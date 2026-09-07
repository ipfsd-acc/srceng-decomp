// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/sentence.cpp
// Functions: 24
// ============================================================

#include "public\sentence.h"

//------------------------------------------------------------------------------
// Address: 0x101D2AC0
// Name: public: CPhonemeTag::CPhonemeTag(class CPhonemeTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhonemeTag *__thiscall CPhonemeTag::CPhonemeTag(CPhonemeTag *this, const CPhonemeTag *from)
{
  unsigned int m_uiEndByte; // ecx
  char *m_szPhoneme; // ebx
  int v5; // edi
  char *v6; // eax

  this->CBasePhonemeTag = from->CBasePhonemeTag;
  m_uiEndByte = from->m_uiEndByte;
  this->m_uiStartByte = from->m_uiStartByte;
  this->m_uiEndByte = m_uiEndByte;
  this->m_bSelected = from->m_bSelected;
  this->m_szPhoneme = nullptr;
  m_szPhoneme = from->m_szPhoneme;
  if ( m_szPhoneme == nullptr )
    m_szPhoneme = (char *)defaultValue;
  free(pMem: nullptr);
  this->m_szPhoneme = nullptr;
  if ( m_szPhoneme != nullptr && *m_szPhoneme != 0 )
  {
    v5 = _V_strlen(str: m_szPhoneme) + 1;
    v6 = (char *)MemAlloc_Alloc(nSize: v5);
    this->m_szPhoneme = v6;
    V_strncpy(pDest: v6, pSrc: m_szPhoneme, maxLen: v5);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D2B40
// Name: private: void CSentence::ParsePlaintext(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParsePlaintext(CSentence *this, CUtlBuffer *buf)
{
  bool v3; // zf
  int v4; // esi
  char *v5; // eax
  char pString[4096]; // [esp+8h] [ebp-2000h] BYREF
  char pDest[4096]; // [esp+1008h] [ebp-1000h] BYREF

  pDest[0] = 0;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncat(pDest, pSrc: pString, destBufferSize: 0x1000u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: " ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
  free(pMem: this->m_szText);
  v3 = pDest[0] == 0;
  this->m_szText = nullptr;
  if ( !v3 )
  {
    v4 = _V_strlen(str: pDest) + 1;
    v5 = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_szText = v5;
    V_strncpy(pDest: v5, pSrc: pDest, maxLen: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2C30
// Name: private: void CSentence::ParseOptions(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseOptions(CSentence *this, CUtlBuffer *buf)
{
  unsigned int v3; // eax
  char pString[4096]; // [esp+8h] [ebp-1200h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-200h] BYREF
  char nptr[256]; // [esp+1108h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_strlen(str: pString) == 0 )
      break;
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    if ( _V_stricmp(s1: pDest, s2: "voice_duck") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "checksum") == 0 )
      {
        v3 = atoi(nptr);
        *((_BYTE *)this + 73) = 1;
        this->m_uCheckSum = v3;
      }
    }
    else
    {
      *((_BYTE *)this + 74) = atoi(nptr) != 0;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2D60
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D2DD0
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2EE0
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2F90
// Name: public: void CUtlBuffer::PutFloat(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutFloat(CUtlBuffer *this, float f)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%f", f);
  else
    CUtlBuffer::PutTypeBin<float>(this, src: f);
}

//------------------------------------------------------------------------------
// Address: 0x101D2FD0
// Name: private: void CSentence::ParseCloseCaption(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseCloseCaption(CSentence *this, CUtlBuffer *buf)
{
  int v2; // edi
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-2020h] BYREF
  char pString[4096]; // [esp+1008h] [ebp-1020h] BYREF
  char pDest[32]; // [esp+2008h] [ebp-20h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    while ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      if ( _V_stricmp(s1: pString, s2: "PHRASE") != 0 )
        break;
      memset(dst, value: 0, count: sizeof(dst));
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      V_strncpy(pDest, pSrc: pString, maxLen: 32);
      if ( _V_stricmp(s1: pDest, s2: "unicode") != 0 )
        _V_stricmp(s1: pDest, s2: "char");
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      v2 = atoi(nptr: pString);
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::Get(this: buf, pMem: dst, size: v2);
      dst[v2] = 0;
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D31C0
// Name: public: void CSentence::ClearRuntimePhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ClearRuntimePhonemes(CSentence *this)
{
  for ( ; this->m_RunTimePhonemes.m_Size > 0; --this->m_RunTimePhonemes.m_Size )
  {
    free(pMem: *(void **)this->m_RunTimePhonemes.m_Memory.m_pMemory);
    if ( this->m_RunTimePhonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_RunTimePhonemes.m_Memory.m_pMemory,
        src: this->m_RunTimePhonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_RunTimePhonemes.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3210
// Name: public: CWordTag::~CWordTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::~CWordTag(CWordTag *this)
{
  CPhonemeTag *v2; // edi

  free(pMem: this->m_pszWord);
  for ( ; this->m_Phonemes.m_Size > 0; --this->m_Phonemes.m_Size )
  {
    v2 = *this->m_Phonemes.m_Memory.m_pMemory;
    if ( v2 != nullptr )
    {
      free(pMem: v2->m_szPhoneme);
      free(pMem: v2);
    }
    if ( this->m_Phonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Phonemes.m_Memory.m_pMemory,
        src: this->m_Phonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Phonemes.m_Size - 1));
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Phonemes);
}

//------------------------------------------------------------------------------
// Address: 0x101D3280
// Name: public: CSentence::CSentence(void)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::CSentence(CSentence *this)
{
  this->m_Words.m_Memory.m_pMemory = nullptr;
  this->m_Words.m_Memory.m_nAllocationCount = 0;
  this->m_Words.m_Memory.m_nGrowSize = 0;
  this->m_Words.m_Size = 0;
  this->m_Words.m_pElements = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_pMemory = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_nAllocationCount = 0;
  this->m_RunTimePhonemes.m_Memory.m_nGrowSize = 0;
  this->m_RunTimePhonemes.m_Size = 0;
  this->m_RunTimePhonemes.m_pElements = nullptr;
  this->m_EmphasisSamples.m_Memory.m_pMemory = nullptr;
  this->m_EmphasisSamples.m_Memory.m_nAllocationCount = 0;
  this->m_EmphasisSamples.m_Memory.m_nGrowSize = 0;
  this->m_EmphasisSamples.m_Size = 0;
  this->m_EmphasisSamples.m_pElements = nullptr;
  this->m_nResetWordBase = 0;
  this->m_szText = nullptr;
  this->m_uCheckSum = 0;
  *(_WORD *)((char *)this + 73) = 0;
  *((_BYTE *)this + 72) = 0;
  *((_BYTE *)this + 75) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D32D0
// Name: public: void CSentence::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Reset(CSentence *this)
{
  bool v2; // cc
  CWordTag **m_pMemory; // eax
  CWordTag *v4; // edi

  v2 = this->m_Words.m_Size <= 0;
  this->m_nResetWordBase = 0;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_Words.m_Memory.m_pMemory;
      v4 = *m_pMemory;
      if ( *m_pMemory != nullptr )
      {
        CWordTag::~CWordTag(this: *m_pMemory);
        free(pMem: v4);
      }
      if ( this->m_Words.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Words.m_Memory.m_pMemory,
          src: this->m_Words.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Words.m_Size - 1));
      --this->m_Words.m_Size;
    }
    while ( this->m_Words.m_Size > 0 );
  }
  this->m_EmphasisSamples.m_Size = 0;
  CSentence::ClearRuntimePhonemes(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D3340
// Name: public: CWordTag::CWordTag(class CWordTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this, const CWordTag *from)
{
  CWordTag *v2; // edi
  CUtlMemory<S3RGBA,int> *p_m_Phonemes; // esi
  char *m_pszWord; // ebx
  unsigned int v5; // kr00_4
  char *v6; // eax
  const CWordTag *v7; // ebx
  unsigned int m_uiEndByte; // eax
  CPhonemeTag *v10; // eax
  CPhonemeTag *v11; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v14; // ecx
  int v15; // eax
  CPhonemeTag **v16; // eax
  int p; // [esp+10h] [ebp-4h]

  v2 = this;
  p_m_Phonemes = (CUtlMemory<S3RGBA,int> *)&this->m_Phonemes;
  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_pszWord = nullptr;
  m_pszWord = from->m_pszWord;
  free(pMem: nullptr);
  v2->m_pszWord = nullptr;
  if ( m_pszWord != nullptr && *m_pszWord != 0 )
  {
    v5 = strlen(m_pszWord);
    v6 = (char *)MemAlloc_Alloc(nSize: v5 + 1);
    this->m_pszWord = v6;
    V_strncpy(pDest: v6, pSrc: m_pszWord, maxLen: v5 + 1);
    v2 = this;
  }
  v7 = from;
  m_uiEndByte = from->m_uiEndByte;
  v2->m_uiStartByte = from->m_uiStartByte;
  v2->m_uiEndByte = m_uiEndByte;
  v2->m_flStartTime = from->m_flStartTime;
  p = 0;
  v2->m_flEndTime = from->m_flEndTime;
  v2->m_bSelected = from->m_bSelected;
  if ( from->m_Phonemes.m_Size <= 0 )
    return v2;
  while ( 1 )
  {
    v10 = (CPhonemeTag *)MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v10 != nullptr )
      v11 = CPhonemeTag::CPhonemeTag(this: v10, from: v7->m_Phonemes.m_Memory.m_pMemory[p]);
    else
      v11 = nullptr;
    m_pMemory = p_m_Phonemes[1].m_pMemory;
    m_nAllocationCount = p_m_Phonemes->m_nAllocationCount;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: p_m_Phonemes, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++p_m_Phonemes[1].m_pMemory;
    v14 = p_m_Phonemes->m_pMemory;
    v15 = (char *)p_m_Phonemes[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Phonemes[1].m_nAllocationCount = (int)p_m_Phonemes->m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
    v16 = (CPhonemeTag **)&p_m_Phonemes->m_pMemory[(_DWORD)m_pMemory];
    if ( v16 != nullptr )
      *v16 = v11;
    if ( ++p >= from->m_Phonemes.m_Size )
      break;
    v7 = from;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D3480
// Name: public: CSentence::~CSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::~CSentence(CSentence *this)
{
  CSentence::Reset(this);
  free(pMem: this->m_szText);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EmphasisSamples);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RunTimePhonemes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Words);
}

//------------------------------------------------------------------------------
// Address: 0x101D34B0
// Name: private: void CSentence::ParseEmphasis(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseEmphasis(CSentence *this, CUtlBuffer *buf)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v6; // eax
  CEmphasisSample *v7; // eax
  float v8; // edx
  int v9; // ecx
  char pString[4096]; // [esp+8h] [ebp-120Ch] BYREF
  char nptr[256]; // [esp+1008h] [ebp-20Ch] BYREF
  char pDest[256]; // [esp+1108h] [ebp-10Ch] BYREF
  float v13; // [esp+1208h] [ebp-Ch]
  float v14; // [esp+120Ch] [ebp-8h]
  int v15; // [esp+1210h] [ebp-4h]

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    LOBYTE(v15) = 0;
    v13 = atof(nptr: pDest);
    v14 = atof(nptr);
    m_Size = this->m_EmphasisSamples.m_Size;
    m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
        this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EmphasisSamples.m_Size;
    m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
    v6 = this->m_EmphasisSamples.m_Size - m_Size - 1;
    this->m_EmphasisSamples.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v6);
    v7 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
    {
      v8 = v14;
      v7->time = v13;
      v9 = v15;
      v7->value = v8;
      *(_DWORD *)&v7->selected = v9;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3600
// Name: public: void CSentence::CacheSaveToBuffer(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::CacheSaveToBuffer(CSentence *this, float buf, float version)
{
  float v3; // ebx
  CUtlBuffer *v4; // esi
  int m_Size_low; // edi
  bool v6; // zf
  int v7; // ebx
  int v8; // edi
  int v9; // edi
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl
  float v12; // xmm0_4
  int v13; // xmm1_4
  __int16 v14; // bx
  float v15; // xmm0_4
  int v16; // xmm1_4
  __int16 v17; // bx
  int v18; // ebx
  int v19; // edi
  int v20; // edi
  float *v21; // edi
  int v22; // xmm1_4
  float v23; // xmm0_4
  __int16 v24; // bx
  int v25; // eax
  float *v26; // eax
  float v27; // xmm0_4
  __int16 v28; // bx
  float *v29; // eax
  bool v30; // bl
  int m_Put; // eax
  int v32; // ebx
  int v33; // edi
  CUtlBuffer *v34; // xmm0_4
  float v35; // xmm0_4
  BOOL v36; // edi
  int v37; // ebx
  int v38; // edi
  CUtlBuffer *v39; // xmm0_4
  float v40; // xmm0_4
  __int16 v41; // di
  bool v42; // bl
  int v43; // eax
  int v44; // [esp+4h] [ebp-20h]
  int v45; // [esp+4h] [ebp-20h]
  float v46; // [esp+14h] [ebp-10h] BYREF
  float v47; // [esp+18h] [ebp-Ch] BYREF
  float v48; // [esp+1Ch] [ebp-8h] BYREF
  __int16 inputBuffer[2]; // [esp+20h] [ebp-4h]

  v3 = version;
  v4 = (CUtlBuffer *)LODWORD(buf);
  m_Size_low = LOWORD(this->m_RunTimePhonemes.m_Size);
  *(_DWORD *)inputBuffer = this;
  if ( LODWORD(version) == 4 )
  {
    CUtlBuffer::PutChar(this: (CUtlBuffer *)LODWORD(buf), c: 4);
    CUtlBuffer::PutChar(this: v4, c: 0);
    CUtlBuffer::PutChar(this: v4, c: 0);
    CUtlBuffer::PutChar(this: v4, c: 0);
    v6 = (v4->m_Flags & 1) == 0;
    buf = *(float *)&m_Size_low;
    if ( v6 )
      CUtlBuffer::PutTypeBin<int>(this: v4, src: m_Size_low);
    else
      CUtlBuffer::Printf(this: v4, pFmt: "%d", m_Size_low);
    v7 = 0;
    if ( m_Size_low > 0 )
    {
      do
      {
        v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)inputBuffer + 24) + 4 * v7);
        v44 = *(unsigned __int16 *)(v8 + 8);
        if ( (v4->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v4, pFmt: "%d", v44);
        else
          CUtlBuffer::PutTypeBin<int>(this: v4, src: v44);
        v6 = (v4->m_Flags & 1) == 0;
        v48 = *(float *)v8;
        if ( v6 )
          CUtlBuffer::PutTypeBin<float>(this: v4, src: v48);
        else
          CUtlBuffer::Printf(this: v4, pFmt: "%f", v48);
        v6 = (v4->m_Flags & 1) == 0;
        v47 = *(float *)(v8 + 4);
        if ( v6 )
          CUtlBuffer::PutTypeBin<float>(this: v4, src: v47);
        else
          CUtlBuffer::Printf(this: v4, pFmt: "%f", v47);
        ++v7;
      }
      while ( v7 < SLODWORD(buf) );
    }
  }
  else
  {
    CUtlBuffer::PutChar(this: (CUtlBuffer *)LODWORD(buf), c: SLOBYTE(version));
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", (__int16)m_Size_low);
    else
      CUtlBuffer::PutTypeBin<short>(this: v4, src: m_Size_low);
    buf = *(float *)&m_Size_low;
    if ( LODWORD(v3) == 5 )
    {
      v48 = 0.0;
      if ( m_Size_low > 0 )
      {
        do
        {
          v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)inputBuffer + 24) + 4 * LODWORD(v48));
          v10 = CodeToByteCode(code: *(unsigned __int16 *)(v9 + 8));
          v11 = v10;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hu", v10);
          }
          else if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
          {
            v4->m_Memory.m_pMemory[v4->m_Put++ - v4->m_nOffset] = v11;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
          v12 = (float)(*(float *)v9 * 1000.0) * 0.2;
          *(float *)&v13 = -32768.0;
          if ( v12 < -32768.0 || (*(float *)&v13 = 32767.0, v12 > 32767.0) )
            v12 = *(float *)&v13;
          v14 = (int)v12;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", v14);
          }
          else
          {
            LODWORD(v47) = (unsigned __int16)(int)v12;
            if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned short>(
                  this: &v4->m_Byteswap,
                  outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                  inputBuffer: (__int16 *)&v47,
                  count: 1);
              else
                *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v14;
              v4->m_Put += 2;
              CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            }
          }
          v15 = (float)(*(float *)(v9 + 4) * 1000.0) * 0.2;
          *(float *)&v16 = -32768.0;
          if ( v15 < -32768.0 || (*(float *)&v16 = 32767.0, v15 > 32767.0) )
            v15 = *(float *)&v16;
          v17 = (int)v15;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", v17);
          }
          else
          {
            LODWORD(v47) = (unsigned __int16)(int)v15;
            if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned short>(
                  this: &v4->m_Byteswap,
                  outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                  inputBuffer: (__int16 *)&v47,
                  count: 1);
              else
                *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v17;
              v4->m_Put += 2;
              CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            }
          }
          ++LODWORD(v48);
        }
        while ( SLODWORD(v48) < SLODWORD(buf) );
      }
    }
    else
    {
      v18 = 0;
      if ( m_Size_low > 0 )
      {
        do
        {
          v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)inputBuffer + 24) + 4 * v18);
          if ( (v4->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", *(__int16 *)(v19 + 8));
          else
            CUtlBuffer::PutTypeBin<short>(this: v4, src: *(_WORD *)(v19 + 8));
          v6 = (v4->m_Flags & 1) == 0;
          v47 = *(float *)v19;
          if ( v6 )
            CUtlBuffer::PutTypeBin<float>(this: v4, src: v47);
          else
            CUtlBuffer::Printf(this: v4, pFmt: "%f", v47);
          v6 = (v4->m_Flags & 1) == 0;
          v48 = *(float *)(v19 + 4);
          if ( v6 )
            CUtlBuffer::PutTypeBin<float>(this: v4, src: v48);
          else
            CUtlBuffer::Printf(this: v4, pFmt: "%f", v48);
          ++v18;
        }
        while ( v18 < SLODWORD(buf) );
      }
    }
  }
  v20 = *(int *)(*(_DWORD *)inputBuffer + 60);
  if ( LODWORD(version) == 5 )
  {
    if ( (v4->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", (__int16)v20);
    }
    else
    {
      LODWORD(buf) = (unsigned __int16)v20;
      if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
      {
        if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &v4->m_Byteswap,
            outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
            inputBuffer: (__int16 *)&buf,
            count: 1);
        else
          *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v20;
        v4->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
      }
    }
    if ( v20 > 0 )
    {
      version = 0.0;
      v47 = *(float *)&v20;
      do
      {
        v21 = (float *)(LODWORD(version) + *(_DWORD *)(*(_DWORD *)inputBuffer + 48));
        *(float *)&v22 = -32768.0;
        v23 = (float)(*v21 * 1000.0) * 0.2;
        if ( v23 < -32768.0 || (*(float *)&v22 = 32767.0, v23 > 32767.0) )
          v23 = *(float *)&v22;
        v24 = (int)v23;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v24);
        }
        else
        {
          LODWORD(buf) = (unsigned __int16)(int)v23;
          if ( !CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            goto LABEL_83;
          v25 = (int)&v4->m_Memory.m_pMemory[-v4->m_nOffset];
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          {
            v26 = (float *)(v4->m_Put + v25);
            if ( v26 != nullptr )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              {
                HIWORD(buf) = 0;
                LOBYTE(buf) = (unsigned __int16)(int)v23 >> 8;
                BYTE1(buf) = (int)v23;
                _V_memcpy(dest: v26, src: &buf, count: 2);
                v4->m_Put += 2;
                CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
                goto LABEL_83;
              }
              if ( v26 != &buf )
              {
                *(_WORD *)v26 = LOWORD(buf);
                v4->m_Put += 2;
                CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
                goto LABEL_83;
              }
            }
          }
          else
          {
            *(_WORD *)(v25 + v4->m_Put) = v24;
          }
          v4->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
        }
LABEL_83:
        v27 = v21[1] * 32767.0;
        if ( v27 >= 0.0 )
        {
          if ( v27 > 32767.0 )
            v27 = 32767.0;
        }
        else
        {
          v27 = 0.0;
        }
        v28 = (int)v27;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v28);
          goto LABEL_98;
        }
        LODWORD(buf) = (unsigned __int16)(int)v27;
        if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
        {
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) == 0 )
          {
            *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v28;
LABEL_96:
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            goto LABEL_98;
          }
          v29 = (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset];
          if ( v29 == nullptr )
            goto LABEL_96;
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          {
            HIWORD(buf) = 0;
            LOBYTE(buf) = (unsigned __int16)(int)v27 >> 8;
            BYTE1(buf) = (int)v27;
            _V_memcpy(dest: v29, src: &buf, count: 2);
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
          else
          {
            if ( v29 == &buf )
              goto LABEL_96;
            *(_WORD *)v29 = LOWORD(buf);
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
LABEL_98:
        LODWORD(version) += 12;
        --LODWORD(v47);
      }
      while ( v47 != 0.0 );
    }
    v30 = *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      m_Put = v4->m_Put;
      if ( m_Put != 0 && v4->m_Memory.m_pMemory[m_Put - v4->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: v4);
    }
    if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
    {
      v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v30;
LABEL_163:
      CUtlBuffer::AddNullTermination(this: v4, nPut: ++v4->m_Put);
    }
  }
  else if ( LODWORD(version) == 4 )
  {
    v45 = *(_DWORD *)(*(_DWORD *)inputBuffer + 60);
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%d", v45);
    else
      CUtlBuffer::PutTypeBin<int>(this: v4, src: v45);
    if ( v20 > 0 )
    {
      v32 = 0;
      v47 = *(float *)&v20;
      do
      {
        v6 = (v4->m_Flags & 1) == 0;
        v33 = *(_DWORD *)(*(_DWORD *)inputBuffer + 48);
        v34 = *(CUtlBuffer **)(v33 + v32);
        buf = *(float *)&v34;
        if ( v6 )
        {
          v48 = *(float *)&v34;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: &v48,
                count: 1);
            else
              *(float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = buf;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", buf);
        }
        v6 = (v4->m_Flags & 1) == 0;
        v35 = *(float *)(v33 + v32 + 4);
        version = v35;
        if ( v6 )
        {
          v46 = v35;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: &v46,
                count: 1);
            else
              *(float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = version;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", version);
        }
        v32 += 12;
        --LODWORD(v47);
      }
      while ( v47 != 0.0 );
    }
    v36 = *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v4, pFmt: "%d", *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0);
    }
    else
    {
      LODWORD(buf) = *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0;
      if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
      {
        if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v4->m_Byteswap,
            outputBuffer: (int *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
            inputBuffer: (int *)&buf,
            count: 1);
        else
          *(_DWORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v36;
        v4->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
      }
    }
  }
  else
  {
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", (__int16)v20);
    else
      CUtlBuffer::PutTypeBin<short>(this: v4, src: *(_DWORD *)(*(_DWORD *)inputBuffer + 60));
    if ( v20 > 0 )
    {
      v37 = 0;
      version = *(float *)&v20;
      do
      {
        v6 = (v4->m_Flags & 1) == 0;
        v38 = *(_DWORD *)(*(_DWORD *)inputBuffer + 48);
        v39 = *(CUtlBuffer **)(v38 + v37);
        buf = *(float *)&v39;
        if ( v6 )
        {
          LODWORD(v46) = v39;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: &v46,
                count: 1);
            else
              *(float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = buf;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", buf);
        }
        v40 = *(float *)(v38 + v37 + 4) * 32767.0;
        if ( v40 >= 0.0 )
        {
          if ( v40 > 32767.0 )
            v40 = 32767.0;
        }
        else
        {
          v40 = 0.0;
        }
        v41 = (int)v40;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v41);
        }
        else
        {
          LODWORD(v47) = (unsigned __int16)(int)v40;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned short>(
                this: &v4->m_Byteswap,
                outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: (__int16 *)&v47,
                count: 1);
            else
              *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v41;
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        v37 += 12;
        --LODWORD(version);
      }
      while ( version != 0.0 );
    }
    v42 = *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      v43 = v4->m_Put;
      if ( v43 != 0 && v4->m_Memory.m_pMemory[v43 - v4->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: v4);
    }
    if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
    {
      v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v42;
      goto LABEL_163;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4070
// Name: public: void CSentence::AddRuntimePhoneme(class CPhonemeTag const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::AddRuntimePhoneme(CSentence *this, const CPhonemeTag *src)
{
  _DWORD *v3; // eax
  CBasePhonemeTag *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBasePhonemeTag **m_pMemory; // ecx
  int v8; // eax
  CBasePhonemeTag **v9; // edi

  v3 = MemAlloc_Alloc(nSize: 0xCu);
  if ( v3 != nullptr )
  {
    *v3 = 0;
    v3[1] = 0;
    *((_WORD *)v3 + 4) = 0;
    v4 = (CBasePhonemeTag *)v3;
  }
  else
  {
    v4 = nullptr;
  }
  *v4 = src->CBasePhonemeTag;
  m_Size = this->m_RunTimePhonemes.m_Size;
  m_nAllocationCount = this->m_RunTimePhonemes.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_RunTimePhonemes,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_RunTimePhonemes.m_Size;
  m_pMemory = this->m_RunTimePhonemes.m_Memory.m_pMemory;
  v8 = this->m_RunTimePhonemes.m_Size - m_Size - 1;
  this->m_RunTimePhonemes.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_RunTimePhonemes.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v4;
}

//------------------------------------------------------------------------------
// Address: 0x101D4110
// Name: public: void CSentence::MakeRuntimeOnly(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::MakeRuntimeOnly(CSentence *this)
{
  int m_Size; // edx
  int v3; // eax
  CWordTag *v4; // ebx
  int v5; // edi
  CWordTag **m_pMemory; // ecx
  CWordTag *v7; // edi
  char *m_szText; // [esp-4h] [ebp-1Ch]
  int c; // [esp+Ch] [ebp-Ch]
  int pcount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  m_szText = this->m_szText;
  *((_BYTE *)this + 75) = 1;
  free(pMem: m_szText);
  m_Size = this->m_Words.m_Size;
  v3 = 0;
  this->m_szText = nullptr;
  c = m_Size;
  for ( i = 0; v3 < m_Size; i = v3 )
  {
    v4 = this->m_Words.m_Memory.m_pMemory[v3];
    v5 = 0;
    pcount = v4->m_Phonemes.m_Size;
    if ( pcount > 0 )
    {
      do
        CSentence::AddRuntimePhoneme(this, src: v4->m_Phonemes.m_Memory.m_pMemory[v5++]);
      while ( v5 < pcount );
      v3 = i;
      m_Size = c;
    }
    ++v3;
  }
  for ( ; this->m_Words.m_Size > 0; --this->m_Words.m_Size )
  {
    m_pMemory = this->m_Words.m_Memory.m_pMemory;
    v7 = *m_pMemory;
    if ( *m_pMemory != nullptr )
    {
      CWordTag::~CWordTag(this: *m_pMemory);
      free(pMem: v7);
    }
    if ( this->m_Words.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Words.m_Memory.m_pMemory,
        src: this->m_Words.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Words.m_Size - 1));
  }
  *((_BYTE *)this + 72) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D41D0
// Name: public: class CSentence __near & CSentence::operator=(class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::operator=(CSentence *this, CWordTag *src)
{
  CSentence *v2; // esi
  bool v4; // cc
  const CWordTag *v5; // edi
  CWordTag *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v10; // eax
  CWordTag **v11; // eax
  char *m_flStartTime_low; // edi
  int v13; // esi
  char *v14; // eax
  CEmphasisSample *v15; // eax
  int v16; // edi
  float time; // ecx
  float value; // edx
  int v19; // eax
  int v20; // eax
  CEmphasisSample *v21; // ecx
  int v22; // eax
  int v23; // eax
  float v24; // edx
  int v25; // ecx
  int m_uiEndByte; // edi
  int j; // esi
  CBasePhonemeTag *v28; // eax
  float m_flEndTime; // edx
  float m_flStartTime; // ecx
  int v31; // eax
  CSentence *result; // eax
  CPhonemeTag full; // [esp+Ch] [ebp-30h] BYREF
  CEmphasisSample s; // [esp+28h] [ebp-14h]
  int i; // [esp+34h] [ebp-8h]
  CSentence *v36; // [esp+38h] [ebp-4h]
  CWordTag *newWord; // [esp+44h] [ebp+8h]
  CWordTag *newWorda; // [esp+44h] [ebp+8h]

  v2 = this;
  v36 = this;
  CSentence::Reset(this);
  v4 = src->m_Phonemes.m_Memory.m_nGrowSize <= 0;
  i = 0;
  if ( !v4 )
  {
    do
    {
      v5 = *(const CWordTag **)(LODWORD(src->m_flEndTime) + 4 * i);
      v6 = (CWordTag *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v6 != nullptr )
        newWord = CWordTag::CWordTag(this: v6, from: v5);
      else
        newWord = nullptr;
      m_Size = v2->m_Words.m_Size;
      m_nAllocationCount = v2->m_Words.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v2->m_Words,
          num: m_Size - m_nAllocationCount + 1);
      ++v2->m_Words.m_Size;
      m_pMemory = v2->m_Words.m_Memory.m_pMemory;
      v10 = v2->m_Words.m_Size - m_Size - 1;
      v2->m_Words.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &v2->m_Words.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        *v11 = newWord;
      ++i;
    }
    while ( i < src->m_Phonemes.m_Memory.m_nGrowSize );
  }
  m_flStartTime_low = (char *)LODWORD(src->m_flStartTime);
  if ( LODWORD(src->m_flStartTime) == 0 )
    m_flStartTime_low = (char *)defaultValue;
  free(pMem: v2->m_szText);
  v2->m_szText = nullptr;
  if ( m_flStartTime_low != nullptr && *m_flStartTime_low != 0 )
  {
    v13 = _V_strlen(str: m_flStartTime_low) + 1;
    v14 = (char *)MemAlloc_Alloc(nSize: v13);
    v36->m_szText = v14;
    V_strncpy(pDest: v14, pSrc: m_flStartTime_low, maxLen: v13);
    v2 = v36;
  }
  v2->m_nResetWordBase = LODWORD(src[1].m_flStartTime);
  if ( src[1].m_Phonemes.m_Memory.m_nGrowSize > 0 )
  {
    newWorda = nullptr;
    i = src[1].m_Phonemes.m_Memory.m_nGrowSize;
    do
    {
      v15 = (CEmphasisSample *)((char *)newWorda + LODWORD(src[1].m_flEndTime));
      v16 = v2->m_EmphasisSamples.m_Size;
      time = v15->time;
      value = v15->value;
      v19 = *(_DWORD *)&v15->selected;
      s.time = time;
      *(_DWORD *)&s.selected = v19;
      v20 = v2->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      s.value = value;
      if ( v16 + 1 > v20 )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v2->m_EmphasisSamples,
          num: v16 - v20 + 1);
      ++v2->m_EmphasisSamples.m_Size;
      v21 = v2->m_EmphasisSamples.m_Memory.m_pMemory;
      v22 = v2->m_EmphasisSamples.m_Size - v16 - 1;
      v2->m_EmphasisSamples.m_pElements = v21;
      if ( v22 > 0 )
        _V_memmove(dest: &v21[v16 + 1], src: &v21[v16], count: 12 * v22);
      v23 = (int)&v2->m_EmphasisSamples.m_Memory.m_pMemory[v16];
      if ( v23 != 0 )
      {
        v24 = s.value;
        *(float *)v23 = s.time;
        v25 = *(_DWORD *)&s.selected;
        *(float *)(v23 + 4) = v24;
        *(_DWORD *)(v23 + 8) = v25;
      }
      newWorda = (CWordTag *)((char *)newWorda + 12);
      --i;
    }
    while ( i != 0 );
    v2 = v36;
  }
  *((_BYTE *)v2 + 75) = *(&src[1].m_bSelected + 3);
  m_uiEndByte = src->m_uiEndByte;
  for ( j = 0; j < m_uiEndByte; ++j )
  {
    v28 = src->m_Phonemes.m_pElements[j];
    m_flEndTime = v28->m_flEndTime;
    memset(&full.m_uiStartByte, 0, 12);
    full.m_bSelected = false;
    m_flStartTime = v28->m_flStartTime;
    v31 = *(_DWORD *)&v28->m_nPhonemeCode;
    full.m_flStartTime = m_flStartTime;
    full.m_flEndTime = m_flEndTime;
    *(_DWORD *)&full.m_nPhonemeCode = v31;
    CSentence::AddRuntimePhoneme(this: v36, src: &full);
    free(pMem: nullptr);
  }
  result = v36;
  *((_BYTE *)v36 + 74) = *(&src[1].m_bSelected + 2);
  *((_BYTE *)result + 73) = *(&src[1].m_bSelected + 1);
  result->m_uCheckSum = (unsigned int)src[1].m_Phonemes.m_pElements;
  *((_BYTE *)result + 72) = src[1].m_bSelected;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D4400
// Name: private: void CSentence::ParseWords(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseWords(CSentence *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // ebx
  float *v3; // eax
  float *v4; // esi
  unsigned int v5; // kr00_4
  char *v6; // eax
  float *v7; // eax
  CSentence *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v12; // eax
  float **v13; // edi
  float *v14; // esi
  __int16 v15; // di
  _DWORD *v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  char *v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  void *v25; // [esp-8h] [ebp-1220h]
  char pString[4096]; // [esp+8h] [ebp-1210h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-210h] BYREF
  char str[256]; // [esp+1108h] [ebp-110h] BYREF
  CSentence *v29; // [esp+1208h] [ebp-10h]
  float v30; // [esp+120Ch] [ebp-Ch]
  float v31; // [esp+1210h] [ebp-8h]
  float *v32; // [esp+1214h] [ebp-4h]

  v2 = buf;
  v29 = this;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_stricmp(s1: pString, s2: "WORD") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v31 = atof(nptr: pString);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v30 = atof(nptr: pString);
    v3 = (float *)MemAlloc_Alloc(nSize: 0x2Cu);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3[2] = 0.0;
      v3[3] = 0.0;
      v3[4] = 0.0;
      v3[5] = 0.0;
      v3[6] = 0.0;
      v3[8] = 0.0;
      v3[9] = 0.0;
      *v3 = 0.0;
      v3[1] = 0.0;
      v3[10] = 0.0;
      *((_BYTE *)v3 + 28) = 0;
      free(pMem: nullptr);
      v4[10] = 0.0;
      if ( pDest[0] != 0 )
      {
        v5 = strlen(pDest);
        v6 = (char *)MemAlloc_Alloc(nSize: v5 + 1);
        *((_DWORD *)v4 + 10) = v6;
        V_strncpy(pDest: v6, pSrc: pDest, maxLen: v5 + 1);
      }
      v32 = v4;
    }
    else
    {
      v32 = nullptr;
    }
    v7 = v32;
    v8 = v29;
    *v32 = v31;
    v7[1] = v30;
    m_Size = v8->m_Words.m_Size;
    m_nAllocationCount = v8->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v8->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v8->m_Words.m_Size;
    m_pMemory = v8->m_Words.m_Memory.m_pMemory;
    v12 = v8->m_Words.m_Size - m_Size - 1;
    v8->m_Words.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = (float **)&v8->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v32;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      v14 = v32;
      do
      {
        v15 = atoi(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        V_strncpy(pDest: str, pSrc: pString, maxLen: 256);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v30 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v31 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        atof(nptr: pString);
        v16 = MemAlloc_Alloc(nSize: 0x1Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[6] = 0;
          v16[4] = 0;
          v16[5] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_WORD *)v16 + 4) = 0;
          *((_BYTE *)v16 + 12) = 0;
          v17 = v16;
        }
        v25 = (void *)v17[6];
        *((_WORD *)v17 + 4) = v15;
        free(pMem: v25);
        v17[6] = 0;
        if ( str[0] != 0 )
        {
          v18 = _V_strlen(str) + 1;
          v19 = (char *)MemAlloc_Alloc(nSize: v18);
          v17[6] = v19;
          V_strncpy(pDest: v19, pSrc: str, maxLen: v18);
        }
        *(float *)v17 = v30;
        *((float *)v17 + 1) = v31;
        v20 = *((_DWORD *)v14 + 5);
        v21 = *((_DWORD *)v14 + 3);
        if ( v20 + 1 > v21 )
          CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(v14 + 2), num: v20 - v21 + 1);
        ++*((_DWORD *)v14 + 5);
        v22 = *((_DWORD *)v14 + 2);
        v23 = *((_DWORD *)v14 + 5) - v20 - 1;
        *((_DWORD *)v14 + 6) = v22;
        if ( v23 > 0 )
          _V_memmove(dest: (void *)(v22 + 4 * v20 + 4), src: (const void *)(v22 + 4 * v20), count: 4 * v23);
        v24 = (_DWORD *)(*((_DWORD *)v14 + 2) + 4 * v20);
        if ( v24 != nullptr )
          *v24 = v17;
        CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
        v2 = buf;
      }
      while ( _V_stricmp(s1: pString, s2: "}") != 0 );
    }
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4820
// Name: private: void CSentence::ParseDataVersionOnePointZero(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseDataVersionOnePointZero(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1100h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( strlen(pString) != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    if ( _V_stricmp(s1: pDest, s2: "PLAINTEXT") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "WORDS") != 0 )
      {
        if ( _V_stricmp(s1: pDest, s2: "EMPHASIS") != 0 )
        {
          if ( _V_stricmp(s1: pDest, s2: "CLOSECAPTION") != 0 )
          {
            if ( _V_stricmp(s1: pDest, s2: "OPTIONS") == 0 )
              CSentence::ParseOptions(this, buf);
          }
          else
          {
            CSentence::ParseCloseCaption(this, buf);
          }
        }
        else
        {
          CSentence::ParseEmphasis(this, buf);
        }
      }
      else
      {
        CSentence::ParseWords(this, buf);
      }
    }
    else
    {
      CSentence::ParsePlaintext(this, buf);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4990
// Name: public: void CSentence::CacheRestoreFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::CacheRestoreFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  signed __int8 v4; // al
  int v5; // ebx
  unsigned __int16 Short; // ax
  int i; // ebx
  __int16 v8; // ax
  __int16 v9; // ax
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  CEmphasisSample *v13; // ecx
  int v14; // eax
  CEmphasisSample *v15; // eax
  float v16; // edx
  int v17; // ecx
  unsigned __int8 v18; // cl
  unsigned __int16 Int; // bx
  int v20; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v24; // eax
  CEmphasisSample *v25; // eax
  float value; // edx
  int v27; // ecx
  bool v28; // zf
  unsigned __int16 v29; // bx
  __int16 v30; // ax
  __int16 v31; // ax
  int v32; // ebx
  int v33; // ecx
  int v34; // eax
  CEmphasisSample *v35; // ecx
  int v36; // eax
  CEmphasisSample *v37; // eax
  float v38; // edx
  int v39; // ecx
  CPhonemeTag pt; // [esp+Ch] [ebp-34h] BYREF
  CEmphasisSample sample; // [esp+28h] [ebp-18h]
  float et; // [esp+34h] [ebp-Ch] BYREF
  float st[2]; // [esp+38h] [ebp-8h] BYREF
  unsigned __int8 bufa; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufb; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufc; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufd; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufe; // [esp+48h] [ebp+8h]
  CUtlBuffer *buff; // [esp+48h] [ebp+8h]

  CSentence::Reset(this);
  *((_BYTE *)this + 75) = 1;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    v4 = 0;
  }
  v5 = v4;
  if ( v4 != 1 )
  {
    if ( v4 == 4 )
      goto LABEL_9;
    if ( v4 != 5 )
    {
      *((_BYTE *)this + 72) = 0;
      return;
    }
  }
  if ( v4 != 4 )
  {
    Short = CUtlBuffer::GetShort(this: buf);
    goto LABEL_17;
  }
LABEL_9:
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  Short = CUtlBuffer::GetInt(this: buf);
LABEL_17:
  memset(&pt, 0, 10);
  memset(&pt.m_uiStartByte, 0, 12);
  pt.m_bSelected = false;
  if ( v5 != 5 )
  {
    if ( v5 == 4 )
    {
      if ( Short != 0 )
      {
        for ( bufc = (CUtlBuffer *)Short; bufc != nullptr; bufc = (CUtlBuffer *)((char *)bufc - 1) )
        {
          Int = CUtlBuffer::GetInt(this: buf);
          CUtlBuffer::GetType<float>(this: buf, dest: &et);
          CUtlBuffer::GetType<float>(this: buf, dest: st);
          pt.m_flStartTime = et;
          pt.m_nPhonemeCode = Int;
          pt.m_flEndTime = st[0];
          CSentence::AddRuntimePhoneme(this, src: &pt);
        }
      }
      v20 = CUtlBuffer::GetInt(this: buf);
      if ( v20 > 0 )
      {
        for ( bufd = (CUtlBuffer *)v20; bufd != nullptr; bufd = (CUtlBuffer *)((char *)bufd - 1) )
        {
          sample.selected = false;
          CUtlBuffer::GetType<float>(this: buf, dest: &et);
          sample.time = et;
          CUtlBuffer::GetType<float>(this: buf, dest: st);
          m_Size = this->m_EmphasisSamples.m_Size;
          m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
          sample.value = st[0];
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
              this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_EmphasisSamples.m_Size;
          m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
          v24 = this->m_EmphasisSamples.m_Size - m_Size - 1;
          this->m_EmphasisSamples.m_pElements = m_pMemory;
          if ( v24 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v24);
          v25 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
          if ( v25 != nullptr )
          {
            value = sample.value;
            v25->time = sample.time;
            v27 = *(_DWORD *)&sample.selected;
            v25->value = value;
            *(_DWORD *)&v25->selected = v27;
          }
        }
      }
      v28 = CUtlBuffer::GetInt(this: buf) == 0;
      goto LABEL_67;
    }
    if ( Short != 0 )
    {
      for ( bufe = (CUtlBuffer *)Short; bufe != nullptr; bufe = (CUtlBuffer *)((char *)bufe - 1) )
      {
        v29 = CUtlBuffer::GetShort(this: buf);
        CUtlBuffer::GetType<float>(this: buf, dest: &et);
        CUtlBuffer::GetType<float>(this: buf, dest: st);
        pt.m_flStartTime = et;
        pt.m_nPhonemeCode = v29;
        pt.m_flEndTime = st[0];
        CSentence::AddRuntimePhoneme(this, src: &pt);
      }
    }
    v30 = CUtlBuffer::GetShort(this: buf);
    if ( v30 > 0 )
    {
      for ( buff = (CUtlBuffer *)v30; buff != nullptr; buff = (CUtlBuffer *)((char *)buff - 1) )
      {
        sample.selected = false;
        CUtlBuffer::GetType<float>(this: buf, dest: &et);
        sample.time = et;
        v31 = CUtlBuffer::GetShort(this: buf);
        v32 = this->m_EmphasisSamples.m_Size;
        v33 = v31;
        v34 = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
        sample.value = (float)v33 * 0.000030518509;
        if ( v32 + 1 > v34 )
          CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
            this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
            num: v32 - v34 + 1);
        ++this->m_EmphasisSamples.m_Size;
        v35 = this->m_EmphasisSamples.m_Memory.m_pMemory;
        v36 = this->m_EmphasisSamples.m_Size - v32 - 1;
        this->m_EmphasisSamples.m_pElements = v35;
        if ( v36 > 0 )
          _V_memmove(dest: &v35[v32 + 1], src: &v35[v32], count: 12 * v36);
        v37 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v32];
        if ( v37 != nullptr )
        {
          v38 = sample.value;
          v37->time = sample.time;
          v39 = *(_DWORD *)&sample.selected;
          v37->value = v38;
          *(_DWORD *)&v37->selected = v39;
        }
      }
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v18 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
      goto LABEL_66;
    }
LABEL_65:
    v18 = 0;
    goto LABEL_66;
  }
  if ( Short != 0 )
  {
    for ( i = Short; i != 0; --i )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        bufa = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        bufa = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        bufa = 0;
      }
      st[0] = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      et = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      pt.m_nPhonemeCode = ByteCodeToCode(byteCode: bufa);
      pt.m_flStartTime = st[0];
      pt.m_flEndTime = et;
      CSentence::AddRuntimePhoneme(this, src: &pt);
    }
  }
  v8 = CUtlBuffer::GetShort(this: buf);
  if ( v8 > 0 )
  {
    for ( bufb = (CUtlBuffer *)v8; bufb != nullptr; bufb = (CUtlBuffer *)((char *)bufb - 1) )
    {
      sample.selected = false;
      sample.time = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      v9 = CUtlBuffer::GetShort(this: buf);
      v10 = this->m_EmphasisSamples.m_Size;
      v11 = v9;
      v12 = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      sample.value = (float)v11 * 0.000030518509;
      if ( v10 + 1 > v12 )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
          num: v10 - v12 + 1);
      ++this->m_EmphasisSamples.m_Size;
      v13 = this->m_EmphasisSamples.m_Memory.m_pMemory;
      v14 = this->m_EmphasisSamples.m_Size - v10 - 1;
      this->m_EmphasisSamples.m_pElements = v13;
      if ( v14 > 0 )
        _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 12 * v14);
      v15 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v10];
      if ( v15 != nullptr )
      {
        v16 = sample.value;
        v15->time = sample.time;
        v17 = *(_DWORD *)&sample.selected;
        v15->value = v16;
        *(_DWORD *)&v15->selected = v17;
      }
    }
  }
  if ( !CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    goto LABEL_65;
  v18 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
  ++buf->m_Get;
LABEL_66:
  v28 = v18 == 0;
LABEL_67:
  *((_BYTE *)this + 74) = !v28;
  *((_BYTE *)this + 72) = 1;
  free(pMem: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D4E80
// Name: public: void CSentence::InitFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1000h] BYREF

  CSentence::Reset(this);
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  if ( _V_stricmp(s1: pString, s2: "VERSION") == 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( atof(nptr: pString) == 1.0 )
    {
      CSentence::ParseDataVersionOnePointZero(this, buf);
      *((_BYTE *)this + 72) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4F10
// Name: public: void CSentence::InitFromDataChunk(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromDataChunk(CSentence *this, void *data, int size)
{
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::EnsureCapacity(this: &buf, num: size);
  CUtlBuffer::Put(this: &buf, pMem: data, size);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: size);
  CSentence::InitFromBuffer(this, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00403C00
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    ++this->m_Put;
    CUtlBuffer::AddNullTermination(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403C30
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // edi

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this);
    }
  }
}

} // namespace choreogen

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101D2F60
// Name: private: void CSentence::ParsePlaintext(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParsePlaintext(CSentence *this, CUtlBuffer *buf)
{
  bool v3; // zf
  int v4; // esi
  char *v5; // eax
  char pString[4096]; // [esp+8h] [ebp-2000h] BYREF
  char pDest[4096]; // [esp+1008h] [ebp-1000h] BYREF

  pDest[0] = 0;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncat(pDest, pSrc: pString, destBufferSize: 0x1000u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: " ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
  free(pMem: this->m_szText);
  v3 = pDest[0] == 0;
  this->m_szText = nullptr;
  if ( !v3 )
  {
    v4 = _V_strlen(str: pDest) + 1;
    v5 = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_szText = v5;
    V_strncpy(pDest: v5, pSrc: pDest, maxLen: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3050
// Name: private: void CSentence::ParseOptions(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseOptions(CSentence *this, CUtlBuffer *buf)
{
  unsigned int v3; // eax
  char pString[4096]; // [esp+8h] [ebp-1200h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-200h] BYREF
  char nptr[256]; // [esp+1108h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_strlen(str: pString) == 0 )
      break;
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    if ( _V_stricmp(s1: pDest, s2: "voice_duck") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "checksum") == 0 )
      {
        v3 = atoi(nptr);
        *((_BYTE *)this + 73) = 1;
        this->m_uCheckSum = v3;
      }
    }
    else
    {
      *((_BYTE *)this + 74) = atoi(nptr) != 0;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3180
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D31F0
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3260
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3310
// Name: public: void CUtlBuffer::PutFloat(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutFloat(CUtlBuffer *this, float f)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%f", f);
  else
    CUtlBuffer::PutTypeBin<float>(this, src: f);
}

//------------------------------------------------------------------------------
// Address: 0x101D3350
// Name: private: void CSentence::ParseCloseCaption(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseCloseCaption(CSentence *this, CUtlBuffer *buf)
{
  int v2; // edi
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-2020h] BYREF
  char pString[4096]; // [esp+1008h] [ebp-1020h] BYREF
  char pDest[32]; // [esp+2008h] [ebp-20h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    while ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      if ( _V_stricmp(s1: pString, s2: "PHRASE") != 0 )
        break;
      memset(dst, value: 0, count: sizeof(dst));
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      V_strncpy(pDest, pSrc: pString, maxLen: 32);
      if ( _V_stricmp(s1: pDest, s2: "unicode") != 0 )
        _V_stricmp(s1: pDest, s2: "char");
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      v2 = atoi(nptr: pString);
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::Get(this: buf, pMem: dst, size: v2);
      dst[v2] = 0;
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3540
// Name: public: void CSentence::ClearRuntimePhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ClearRuntimePhonemes(CSentence *this)
{
  for ( ; this->m_RunTimePhonemes.m_Size > 0; --this->m_RunTimePhonemes.m_Size )
  {
    free(pMem: *(void **)this->m_RunTimePhonemes.m_Memory.m_pMemory);
    if ( this->m_RunTimePhonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_RunTimePhonemes.m_Memory.m_pMemory,
        src: this->m_RunTimePhonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_RunTimePhonemes.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3590
// Name: public: CWordTag::~CWordTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::~CWordTag(CWordTag *this)
{
  CPhonemeTag *v2; // edi

  free(pMem: this->m_pszWord);
  for ( ; this->m_Phonemes.m_Size > 0; --this->m_Phonemes.m_Size )
  {
    v2 = *this->m_Phonemes.m_Memory.m_pMemory;
    if ( v2 != nullptr )
    {
      free(pMem: v2->m_szPhoneme);
      free(pMem: v2);
    }
    if ( this->m_Phonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Phonemes.m_Memory.m_pMemory,
        src: this->m_Phonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Phonemes.m_Size - 1));
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Phonemes);
}

//------------------------------------------------------------------------------
// Address: 0x101D3650
// Name: public: void CSentence::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Reset(CSentence *this)
{
  bool v2; // cc
  CWordTag **m_pMemory; // eax
  CWordTag *v4; // edi

  v2 = this->m_Words.m_Size <= 0;
  this->m_nResetWordBase = 0;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_Words.m_Memory.m_pMemory;
      v4 = *m_pMemory;
      if ( *m_pMemory != nullptr )
      {
        CWordTag::~CWordTag(this: *m_pMemory);
        free(pMem: v4);
      }
      if ( this->m_Words.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Words.m_Memory.m_pMemory,
          src: this->m_Words.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Words.m_Size - 1));
      --this->m_Words.m_Size;
    }
    while ( this->m_Words.m_Size > 0 );
  }
  this->m_EmphasisSamples.m_Size = 0;
  CSentence::ClearRuntimePhonemes(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D36C0
// Name: public: CWordTag::CWordTag(class CWordTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this, const CWordTag *from)
{
  CWordTag *v2; // edi
  CUtlMemory<S3RGBA,int> *p_m_Phonemes; // esi
  char *m_pszWord; // ebx
  unsigned int v5; // kr00_4
  char *v6; // eax
  const CWordTag *v7; // ebx
  unsigned int m_uiEndByte; // eax
  CPhonemeTag *v10; // eax
  CPhonemeTag *v11; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v14; // ecx
  int v15; // eax
  CPhonemeTag **v16; // eax
  int p; // [esp+10h] [ebp-4h]

  v2 = this;
  p_m_Phonemes = (CUtlMemory<S3RGBA,int> *)&this->m_Phonemes;
  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_pszWord = nullptr;
  m_pszWord = from->m_pszWord;
  free(pMem: nullptr);
  v2->m_pszWord = nullptr;
  if ( m_pszWord != nullptr && *m_pszWord != 0 )
  {
    v5 = strlen(m_pszWord);
    v6 = (char *)MemAlloc_Alloc(nSize: v5 + 1);
    this->m_pszWord = v6;
    V_strncpy(pDest: v6, pSrc: m_pszWord, maxLen: v5 + 1);
    v2 = this;
  }
  v7 = from;
  m_uiEndByte = from->m_uiEndByte;
  v2->m_uiStartByte = from->m_uiStartByte;
  v2->m_uiEndByte = m_uiEndByte;
  v2->m_flStartTime = from->m_flStartTime;
  p = 0;
  v2->m_flEndTime = from->m_flEndTime;
  v2->m_bSelected = from->m_bSelected;
  if ( from->m_Phonemes.m_Size <= 0 )
    return v2;
  while ( 1 )
  {
    v10 = (CPhonemeTag *)MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v10 != nullptr )
      v11 = CPhonemeTag::CPhonemeTag(this: v10, from: v7->m_Phonemes.m_Memory.m_pMemory[p]);
    else
      v11 = nullptr;
    m_pMemory = p_m_Phonemes[1].m_pMemory;
    m_nAllocationCount = p_m_Phonemes->m_nAllocationCount;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: p_m_Phonemes, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++p_m_Phonemes[1].m_pMemory;
    v14 = p_m_Phonemes->m_pMemory;
    v15 = (char *)p_m_Phonemes[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Phonemes[1].m_nAllocationCount = (int)p_m_Phonemes->m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
    v16 = (CPhonemeTag **)&p_m_Phonemes->m_pMemory[(_DWORD)m_pMemory];
    if ( v16 != nullptr )
      *v16 = v11;
    if ( ++p >= from->m_Phonemes.m_Size )
      break;
    v7 = from;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D3800
// Name: public: CSentence::~CSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::~CSentence(CSentence *this)
{
  CSentence::Reset(this);
  free(pMem: this->m_szText);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EmphasisSamples);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RunTimePhonemes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Words);
}

//------------------------------------------------------------------------------
// Address: 0x101D3830
// Name: private: void CSentence::ParseEmphasis(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseEmphasis(CSentence *this, CUtlBuffer *buf)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v6; // eax
  CEmphasisSample *v7; // eax
  float v8; // edx
  int v9; // ecx
  char pString[4096]; // [esp+8h] [ebp-120Ch] BYREF
  char nptr[256]; // [esp+1008h] [ebp-20Ch] BYREF
  char pDest[256]; // [esp+1108h] [ebp-10Ch] BYREF
  float v13; // [esp+1208h] [ebp-Ch]
  float v14; // [esp+120Ch] [ebp-8h]
  int v15; // [esp+1210h] [ebp-4h]

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    LOBYTE(v15) = 0;
    v13 = atof(nptr: pDest);
    v14 = atof(nptr);
    m_Size = this->m_EmphasisSamples.m_Size;
    m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
        this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EmphasisSamples.m_Size;
    m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
    v6 = this->m_EmphasisSamples.m_Size - m_Size - 1;
    this->m_EmphasisSamples.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v6);
    v7 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
    {
      v8 = v14;
      v7->time = v13;
      v9 = v15;
      v7->value = v8;
      *(_DWORD *)&v7->selected = v9;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3980
// Name: public: void CSentence::CacheSaveToBuffer(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::CacheSaveToBuffer(CSentence *this, float buf, float version)
{
  float v3; // ebx
  CUtlBuffer *v4; // esi
  int m_Size_low; // edi
  bool v6; // zf
  int v7; // ebx
  int v8; // edi
  int v9; // edi
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl
  float v12; // xmm0_4
  int v13; // xmm1_4
  __int16 v14; // bx
  float v15; // xmm0_4
  int v16; // xmm1_4
  __int16 v17; // bx
  int v18; // ebx
  int v19; // edi
  float v20; // edi
  float *v21; // edi
  int v22; // xmm1_4
  float v23; // xmm0_4
  __int16 v24; // bx
  int v25; // eax
  float *v26; // eax
  float v27; // xmm0_4
  __int16 v28; // bx
  float *v29; // eax
  bool v30; // bl
  int m_Put; // eax
  int v32; // ebx
  int v33; // edi
  CUtlBuffer *v34; // xmm0_4
  float v35; // xmm0_4
  BOOL v36; // edi
  int v37; // ebx
  int v38; // edi
  CUtlBuffer *v39; // xmm0_4
  float v40; // xmm0_4
  __int16 v41; // di
  bool v42; // bl
  int v43; // eax
  int v44; // [esp+4h] [ebp-20h]
  int v45; // [esp+4h] [ebp-20h]
  float v46; // [esp+14h] [ebp-10h] BYREF
  float v47; // [esp+18h] [ebp-Ch] BYREF
  float v48; // [esp+1Ch] [ebp-8h] BYREF
  __int16 inputBuffer[2]; // [esp+20h] [ebp-4h]

  v3 = version;
  v4 = (CUtlBuffer *)LODWORD(buf);
  m_Size_low = LOWORD(this->m_RunTimePhonemes.m_Size);
  *(_DWORD *)inputBuffer = this;
  if ( LODWORD(version) == 4 )
  {
    CUtlBuffer::PutChar(this: (CUtlBuffer *)LODWORD(buf), c: 4);
    CUtlBuffer::PutChar(this: v4, c: 0);
    CUtlBuffer::PutChar(this: v4, c: 0);
    CUtlBuffer::PutChar(this: v4, c: 0);
    v6 = (v4->m_Flags & 1) == 0;
    buf = *(float *)&m_Size_low;
    if ( v6 )
      CUtlBuffer::PutTypeBin<int>(this: v4, src: m_Size_low);
    else
      CUtlBuffer::Printf(this: v4, pFmt: "%d", m_Size_low);
    v7 = 0;
    if ( m_Size_low > 0 )
    {
      do
      {
        v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)inputBuffer + 24) + 4 * v7);
        v44 = *(unsigned __int16 *)(v8 + 8);
        if ( (v4->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v4, pFmt: "%d", v44);
        else
          CUtlBuffer::PutTypeBin<int>(this: v4, src: v44);
        v6 = (v4->m_Flags & 1) == 0;
        v48 = *(float *)v8;
        if ( v6 )
          CUtlBuffer::PutTypeBin<float>(this: v4, src: v48);
        else
          CUtlBuffer::Printf(this: v4, pFmt: "%f", v48);
        v6 = (v4->m_Flags & 1) == 0;
        v47 = *(float *)(v8 + 4);
        if ( v6 )
          CUtlBuffer::PutTypeBin<float>(this: v4, src: v47);
        else
          CUtlBuffer::Printf(this: v4, pFmt: "%f", v47);
        ++v7;
      }
      while ( v7 < SLODWORD(buf) );
    }
  }
  else
  {
    CUtlBuffer::PutChar(this: (CUtlBuffer *)LODWORD(buf), c: SLOBYTE(version));
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", (__int16)m_Size_low);
    else
      CUtlBuffer::PutTypeBin<short>(this: v4, src: m_Size_low);
    buf = *(float *)&m_Size_low;
    if ( LODWORD(v3) == 5 )
    {
      v48 = 0.0;
      if ( m_Size_low > 0 )
      {
        do
        {
          v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)inputBuffer + 24) + 4 * LODWORD(v48));
          v10 = CodeToByteCode(code: *(unsigned __int16 *)(v9 + 8));
          v11 = v10;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hu", v10);
          }
          else if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
          {
            v4->m_Memory.m_pMemory[v4->m_Put++ - v4->m_nOffset] = v11;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
          v12 = (float)(*(float *)v9 * 1000.0) * 0.2;
          *(float *)&v13 = -32768.0;
          if ( v12 < -32768.0 || (*(float *)&v13 = 32767.0, v12 > 32767.0) )
            v12 = *(float *)&v13;
          v14 = (int)v12;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", v14);
          }
          else
          {
            LODWORD(v47) = (unsigned __int16)(int)v12;
            if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned short>(
                  this: &v4->m_Byteswap,
                  outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                  inputBuffer: (__int16 *)&v47,
                  count: 1);
              else
                *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v14;
              v4->m_Put += 2;
              CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            }
          }
          v15 = (float)(*(float *)(v9 + 4) * 1000.0) * 0.2;
          *(float *)&v16 = -32768.0;
          if ( v15 < -32768.0 || (*(float *)&v16 = 32767.0, v15 > 32767.0) )
            v15 = *(float *)&v16;
          v17 = (int)v15;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", v17);
          }
          else
          {
            LODWORD(v47) = (unsigned __int16)(int)v15;
            if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned short>(
                  this: &v4->m_Byteswap,
                  outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                  inputBuffer: (__int16 *)&v47,
                  count: 1);
              else
                *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v17;
              v4->m_Put += 2;
              CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            }
          }
          ++LODWORD(v48);
        }
        while ( SLODWORD(v48) < SLODWORD(buf) );
      }
    }
    else
    {
      v18 = 0;
      if ( m_Size_low > 0 )
      {
        do
        {
          v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)inputBuffer + 24) + 4 * v18);
          if ( (v4->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", *(__int16 *)(v19 + 8));
          else
            CUtlBuffer::PutTypeBin<short>(this: v4, src: *(_WORD *)(v19 + 8));
          v6 = (v4->m_Flags & 1) == 0;
          v47 = *(float *)v19;
          if ( v6 )
            CUtlBuffer::PutTypeBin<float>(this: v4, src: v47);
          else
            CUtlBuffer::Printf(this: v4, pFmt: "%f", v47);
          v6 = (v4->m_Flags & 1) == 0;
          v48 = *(float *)(v19 + 4);
          if ( v6 )
            CUtlBuffer::PutTypeBin<float>(this: v4, src: v48);
          else
            CUtlBuffer::Printf(this: v4, pFmt: "%f", v48);
          ++v18;
        }
        while ( v18 < SLODWORD(buf) );
      }
    }
  }
  v20 = *(float *)(*(_DWORD *)inputBuffer + 60);
  if ( LODWORD(version) == 5 )
  {
    if ( (v4->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", SLOWORD(v20));
    }
    else
    {
      LODWORD(buf) = LOWORD(v20);
      if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
      {
        if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &v4->m_Byteswap,
            outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
            inputBuffer: (__int16 *)&buf,
            count: 1);
        else
          *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = LOWORD(v20);
        v4->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
      }
    }
    if ( SLODWORD(v20) > 0 )
    {
      version = 0.0;
      v47 = v20;
      do
      {
        v21 = (float *)(LODWORD(version) + *(_DWORD *)(*(_DWORD *)inputBuffer + 48));
        *(float *)&v22 = -32768.0;
        v23 = (float)(*v21 * 1000.0) * 0.2;
        if ( v23 < -32768.0 || (*(float *)&v22 = 32767.0, v23 > 32767.0) )
          v23 = *(float *)&v22;
        v24 = (int)v23;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v24);
        }
        else
        {
          LODWORD(buf) = (unsigned __int16)(int)v23;
          if ( !CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            goto LABEL_83;
          v25 = (int)&v4->m_Memory.m_pMemory[-v4->m_nOffset];
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          {
            v26 = (float *)(v4->m_Put + v25);
            if ( v26 != nullptr )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              {
                HIWORD(buf) = 0;
                LOBYTE(buf) = (unsigned __int16)(int)v23 >> 8;
                BYTE1(buf) = (int)v23;
                _V_memcpy(dest: v26, src: &buf, count: 2);
                v4->m_Put += 2;
                CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
                goto LABEL_83;
              }
              if ( v26 != &buf )
              {
                *(_WORD *)v26 = LOWORD(buf);
                v4->m_Put += 2;
                CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
                goto LABEL_83;
              }
            }
          }
          else
          {
            *(_WORD *)(v25 + v4->m_Put) = v24;
          }
          v4->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
        }
LABEL_83:
        v27 = v21[1] * 32767.0;
        if ( v27 >= 0.0 )
        {
          if ( v27 > 32767.0 )
            v27 = 32767.0;
        }
        else
        {
          v27 = 0.0;
        }
        v28 = (int)v27;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v28);
          goto LABEL_98;
        }
        LODWORD(buf) = (unsigned __int16)(int)v27;
        if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
        {
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) == 0 )
          {
            *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v28;
LABEL_96:
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            goto LABEL_98;
          }
          v29 = (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset];
          if ( v29 == nullptr )
            goto LABEL_96;
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          {
            HIWORD(buf) = 0;
            LOBYTE(buf) = (unsigned __int16)(int)v27 >> 8;
            BYTE1(buf) = (int)v27;
            _V_memcpy(dest: v29, src: &buf, count: 2);
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
          else
          {
            if ( v29 == &buf )
              goto LABEL_96;
            *(_WORD *)v29 = LOWORD(buf);
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
LABEL_98:
        LODWORD(version) += 12;
        --LODWORD(v47);
      }
      while ( v47 != 0.0 );
    }
    v30 = *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      m_Put = v4->m_Put;
      if ( m_Put != 0 && v4->m_Memory.m_pMemory[m_Put - v4->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: v4);
    }
    if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
    {
      v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v30;
LABEL_163:
      CUtlBuffer::AddNullTermination(this: v4, nPut: ++v4->m_Put);
    }
  }
  else if ( LODWORD(version) == 4 )
  {
    v45 = *(_DWORD *)(*(_DWORD *)inputBuffer + 60);
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%d", v45);
    else
      CUtlBuffer::PutTypeBin<int>(this: v4, src: v45);
    if ( SLODWORD(v20) > 0 )
    {
      v32 = 0;
      v47 = v20;
      do
      {
        v6 = (v4->m_Flags & 1) == 0;
        v33 = *(_DWORD *)(*(_DWORD *)inputBuffer + 48);
        v34 = *(CUtlBuffer **)(v33 + v32);
        buf = *(float *)&v34;
        if ( v6 )
        {
          v48 = *(float *)&v34;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: &v48,
                count: 1);
            else
              *(float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = buf;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", buf);
        }
        v6 = (v4->m_Flags & 1) == 0;
        v35 = *(float *)(v33 + v32 + 4);
        version = v35;
        if ( v6 )
        {
          v46 = v35;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: &v46,
                count: 1);
            else
              *(float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = version;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", version);
        }
        v32 += 12;
        --LODWORD(v47);
      }
      while ( v47 != 0.0 );
    }
    v36 = *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v4, pFmt: "%d", *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0);
    }
    else
    {
      LODWORD(buf) = *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0;
      if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
      {
        if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v4->m_Byteswap,
            outputBuffer: (int *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
            inputBuffer: (int *)&buf,
            count: 1);
        else
          *(_DWORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v36;
        v4->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
      }
    }
  }
  else
  {
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", SLOWORD(v20));
    else
      CUtlBuffer::PutTypeBin<short>(this: v4, src: *(_DWORD *)(*(_DWORD *)inputBuffer + 60));
    if ( SLODWORD(v20) > 0 )
    {
      v37 = 0;
      version = v20;
      do
      {
        v6 = (v4->m_Flags & 1) == 0;
        v38 = *(_DWORD *)(*(_DWORD *)inputBuffer + 48);
        v39 = *(CUtlBuffer **)(v38 + v37);
        buf = *(float *)&v39;
        if ( v6 )
        {
          LODWORD(v46) = v39;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: &v46,
                count: 1);
            else
              *(float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = buf;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", buf);
        }
        v40 = *(float *)(v38 + v37 + 4) * 32767.0;
        if ( v40 >= 0.0 )
        {
          if ( v40 > 32767.0 )
            v40 = 32767.0;
        }
        else
        {
          v40 = 0.0;
        }
        v41 = (int)v40;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v41);
        }
        else
        {
          LODWORD(v47) = (unsigned __int16)(int)v40;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned short>(
                this: &v4->m_Byteswap,
                outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: (__int16 *)&v47,
                count: 1);
            else
              *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v41;
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        v37 += 12;
        --LODWORD(version);
      }
      while ( version != 0.0 );
    }
    v42 = *(_BYTE *)(*(_DWORD *)inputBuffer + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      v43 = v4->m_Put;
      if ( v43 != 0 && v4->m_Memory.m_pMemory[v43 - v4->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: v4);
    }
    if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
    {
      v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v42;
      goto LABEL_163;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D43F0
// Name: public: void CSentence::AddRuntimePhoneme(class CPhonemeTag const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::AddRuntimePhoneme(CSentence *this, const CPhonemeTag *src)
{
  _DWORD *v3; // eax
  CBasePhonemeTag *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBasePhonemeTag **m_pMemory; // ecx
  int v8; // eax
  CBasePhonemeTag **v9; // edi

  v3 = MemAlloc_Alloc(nSize: 0xCu);
  if ( v3 != nullptr )
  {
    *v3 = 0;
    v3[1] = 0;
    *((_WORD *)v3 + 4) = 0;
    v4 = (CBasePhonemeTag *)v3;
  }
  else
  {
    v4 = nullptr;
  }
  *v4 = src->CBasePhonemeTag;
  m_Size = this->m_RunTimePhonemes.m_Size;
  m_nAllocationCount = this->m_RunTimePhonemes.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_RunTimePhonemes,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_RunTimePhonemes.m_Size;
  m_pMemory = this->m_RunTimePhonemes.m_Memory.m_pMemory;
  v8 = this->m_RunTimePhonemes.m_Size - m_Size - 1;
  this->m_RunTimePhonemes.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_RunTimePhonemes.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v4;
}

//------------------------------------------------------------------------------
// Address: 0x101D4490
// Name: public: void CSentence::MakeRuntimeOnly(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::MakeRuntimeOnly(CSentence *this)
{
  int m_Size; // edx
  int v3; // eax
  CWordTag *v4; // ebx
  int v5; // edi
  CWordTag **m_pMemory; // ecx
  CWordTag *v7; // edi
  char *m_szText; // [esp-4h] [ebp-1Ch]
  int c; // [esp+Ch] [ebp-Ch]
  int pcount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  m_szText = this->m_szText;
  *((_BYTE *)this + 75) = 1;
  free(pMem: m_szText);
  m_Size = this->m_Words.m_Size;
  v3 = 0;
  this->m_szText = nullptr;
  c = m_Size;
  for ( i = 0; v3 < m_Size; i = v3 )
  {
    v4 = this->m_Words.m_Memory.m_pMemory[v3];
    v5 = 0;
    pcount = v4->m_Phonemes.m_Size;
    if ( pcount > 0 )
    {
      do
        CSentence::AddRuntimePhoneme(this, src: v4->m_Phonemes.m_Memory.m_pMemory[v5++]);
      while ( v5 < pcount );
      v3 = i;
      m_Size = c;
    }
    ++v3;
  }
  for ( ; this->m_Words.m_Size > 0; --this->m_Words.m_Size )
  {
    m_pMemory = this->m_Words.m_Memory.m_pMemory;
    v7 = *m_pMemory;
    if ( *m_pMemory != nullptr )
    {
      CWordTag::~CWordTag(this: *m_pMemory);
      free(pMem: v7);
    }
    if ( this->m_Words.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Words.m_Memory.m_pMemory,
        src: this->m_Words.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Words.m_Size - 1));
  }
  *((_BYTE *)this + 72) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D4550
// Name: public: class CSentence __near & CSentence::operator=(class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::operator=(CSentence *this, CWordTag *src)
{
  CSentence *v2; // esi
  bool v4; // cc
  const CWordTag *v5; // edi
  CWordTag *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v10; // eax
  CWordTag **v11; // eax
  char *m_flStartTime_low; // edi
  int v13; // esi
  char *v14; // eax
  CEmphasisSample *v15; // eax
  int v16; // edi
  float time; // ecx
  float value; // edx
  int v19; // eax
  int v20; // eax
  CEmphasisSample *v21; // ecx
  int v22; // eax
  int v23; // eax
  float v24; // edx
  int v25; // ecx
  int m_uiEndByte; // edi
  int j; // esi
  CBasePhonemeTag *v28; // eax
  float m_flEndTime; // edx
  float m_flStartTime; // ecx
  int v31; // eax
  CSentence *result; // eax
  CPhonemeTag full; // [esp+Ch] [ebp-30h] BYREF
  CEmphasisSample s; // [esp+28h] [ebp-14h]
  int i; // [esp+34h] [ebp-8h]
  CSentence *v36; // [esp+38h] [ebp-4h]
  CWordTag *newWord; // [esp+44h] [ebp+8h]
  CWordTag *newWorda; // [esp+44h] [ebp+8h]

  v2 = this;
  v36 = this;
  CSentence::Reset(this);
  v4 = src->m_Phonemes.m_Memory.m_nGrowSize <= 0;
  i = 0;
  if ( !v4 )
  {
    do
    {
      v5 = *(const CWordTag **)(LODWORD(src->m_flEndTime) + 4 * i);
      v6 = (CWordTag *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v6 != nullptr )
        newWord = CWordTag::CWordTag(this: v6, from: v5);
      else
        newWord = nullptr;
      m_Size = v2->m_Words.m_Size;
      m_nAllocationCount = v2->m_Words.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v2->m_Words,
          num: m_Size - m_nAllocationCount + 1);
      ++v2->m_Words.m_Size;
      m_pMemory = v2->m_Words.m_Memory.m_pMemory;
      v10 = v2->m_Words.m_Size - m_Size - 1;
      v2->m_Words.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &v2->m_Words.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        *v11 = newWord;
      ++i;
    }
    while ( i < src->m_Phonemes.m_Memory.m_nGrowSize );
  }
  m_flStartTime_low = (char *)LODWORD(src->m_flStartTime);
  if ( LODWORD(src->m_flStartTime) == 0 )
    m_flStartTime_low = (char *)defaultValue;
  free(pMem: v2->m_szText);
  v2->m_szText = nullptr;
  if ( m_flStartTime_low != nullptr && *m_flStartTime_low != 0 )
  {
    v13 = _V_strlen(str: m_flStartTime_low) + 1;
    v14 = (char *)MemAlloc_Alloc(nSize: v13);
    v36->m_szText = v14;
    V_strncpy(pDest: v14, pSrc: m_flStartTime_low, maxLen: v13);
    v2 = v36;
  }
  v2->m_nResetWordBase = LODWORD(src[1].m_flStartTime);
  if ( src[1].m_Phonemes.m_Memory.m_nGrowSize > 0 )
  {
    newWorda = nullptr;
    i = src[1].m_Phonemes.m_Memory.m_nGrowSize;
    do
    {
      v15 = (CEmphasisSample *)((char *)newWorda + LODWORD(src[1].m_flEndTime));
      v16 = v2->m_EmphasisSamples.m_Size;
      time = v15->time;
      value = v15->value;
      v19 = *(_DWORD *)&v15->selected;
      s.time = time;
      *(_DWORD *)&s.selected = v19;
      v20 = v2->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      s.value = value;
      if ( v16 + 1 > v20 )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v2->m_EmphasisSamples,
          num: v16 - v20 + 1);
      ++v2->m_EmphasisSamples.m_Size;
      v21 = v2->m_EmphasisSamples.m_Memory.m_pMemory;
      v22 = v2->m_EmphasisSamples.m_Size - v16 - 1;
      v2->m_EmphasisSamples.m_pElements = v21;
      if ( v22 > 0 )
        _V_memmove(dest: &v21[v16 + 1], src: &v21[v16], count: 12 * v22);
      v23 = (int)&v2->m_EmphasisSamples.m_Memory.m_pMemory[v16];
      if ( v23 != 0 )
      {
        v24 = s.value;
        *(float *)v23 = s.time;
        v25 = *(_DWORD *)&s.selected;
        *(float *)(v23 + 4) = v24;
        *(_DWORD *)(v23 + 8) = v25;
      }
      newWorda = (CWordTag *)((char *)newWorda + 12);
      --i;
    }
    while ( i != 0 );
    v2 = v36;
  }
  *((_BYTE *)v2 + 75) = *(&src[1].m_bSelected + 3);
  m_uiEndByte = src->m_uiEndByte;
  for ( j = 0; j < m_uiEndByte; ++j )
  {
    v28 = src->m_Phonemes.m_pElements[j];
    m_flEndTime = v28->m_flEndTime;
    memset(&full.m_uiStartByte, 0, 12);
    full.m_bSelected = false;
    m_flStartTime = v28->m_flStartTime;
    v31 = *(_DWORD *)&v28->m_nPhonemeCode;
    full.m_flStartTime = m_flStartTime;
    full.m_flEndTime = m_flEndTime;
    *(_DWORD *)&full.m_nPhonemeCode = v31;
    CSentence::AddRuntimePhoneme(this: v36, src: &full);
    free(pMem: nullptr);
  }
  result = v36;
  *((_BYTE *)v36 + 74) = *(&src[1].m_bSelected + 2);
  *((_BYTE *)result + 73) = *(&src[1].m_bSelected + 1);
  result->m_uCheckSum = (unsigned int)src[1].m_Phonemes.m_pElements;
  *((_BYTE *)result + 72) = src[1].m_bSelected;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D4780
// Name: private: void CSentence::ParseWords(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseWords(CSentence *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // ebx
  float *v3; // eax
  float *v4; // esi
  unsigned int v5; // kr00_4
  char *v6; // eax
  float *v7; // eax
  CSentence *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v12; // eax
  float **v13; // edi
  float *v14; // esi
  __int16 v15; // di
  _DWORD *v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  char *v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  void *v25; // [esp-8h] [ebp-1220h]
  char pString[4096]; // [esp+8h] [ebp-1210h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-210h] BYREF
  char str[256]; // [esp+1108h] [ebp-110h] BYREF
  CSentence *v29; // [esp+1208h] [ebp-10h]
  float v30; // [esp+120Ch] [ebp-Ch]
  float v31; // [esp+1210h] [ebp-8h]
  float *v32; // [esp+1214h] [ebp-4h]

  v2 = buf;
  v29 = this;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_stricmp(s1: pString, s2: "WORD") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v31 = atof(nptr: pString);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v30 = atof(nptr: pString);
    v3 = (float *)MemAlloc_Alloc(nSize: 0x2Cu);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3[2] = 0.0;
      v3[3] = 0.0;
      v3[4] = 0.0;
      v3[5] = 0.0;
      v3[6] = 0.0;
      v3[8] = 0.0;
      v3[9] = 0.0;
      *v3 = 0.0;
      v3[1] = 0.0;
      v3[10] = 0.0;
      *((_BYTE *)v3 + 28) = 0;
      free(pMem: nullptr);
      v4[10] = 0.0;
      if ( pDest[0] != 0 )
      {
        v5 = strlen(pDest);
        v6 = (char *)MemAlloc_Alloc(nSize: v5 + 1);
        *((_DWORD *)v4 + 10) = v6;
        V_strncpy(pDest: v6, pSrc: pDest, maxLen: v5 + 1);
      }
      v32 = v4;
    }
    else
    {
      v32 = nullptr;
    }
    v7 = v32;
    v8 = v29;
    *v32 = v31;
    v7[1] = v30;
    m_Size = v8->m_Words.m_Size;
    m_nAllocationCount = v8->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v8->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v8->m_Words.m_Size;
    m_pMemory = v8->m_Words.m_Memory.m_pMemory;
    v12 = v8->m_Words.m_Size - m_Size - 1;
    v8->m_Words.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = (float **)&v8->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v32;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      v14 = v32;
      do
      {
        v15 = atoi(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        V_strncpy(pDest: str, pSrc: pString, maxLen: 256);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v30 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v31 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        atof(nptr: pString);
        v16 = MemAlloc_Alloc(nSize: 0x1Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[6] = 0;
          v16[4] = 0;
          v16[5] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_WORD *)v16 + 4) = 0;
          *((_BYTE *)v16 + 12) = 0;
          v17 = v16;
        }
        v25 = (void *)v17[6];
        *((_WORD *)v17 + 4) = v15;
        free(pMem: v25);
        v17[6] = 0;
        if ( str[0] != 0 )
        {
          v18 = _V_strlen(str) + 1;
          v19 = (char *)MemAlloc_Alloc(nSize: v18);
          v17[6] = v19;
          V_strncpy(pDest: v19, pSrc: str, maxLen: v18);
        }
        *(float *)v17 = v30;
        *((float *)v17 + 1) = v31;
        v20 = *((_DWORD *)v14 + 5);
        v21 = *((_DWORD *)v14 + 3);
        if ( v20 + 1 > v21 )
          CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(v14 + 2), num: v20 - v21 + 1);
        ++*((_DWORD *)v14 + 5);
        v22 = *((_DWORD *)v14 + 2);
        v23 = *((_DWORD *)v14 + 5) - v20 - 1;
        *((_DWORD *)v14 + 6) = v22;
        if ( v23 > 0 )
          _V_memmove(dest: (void *)(v22 + 4 * v20 + 4), src: (const void *)(v22 + 4 * v20), count: 4 * v23);
        v24 = (_DWORD *)(*((_DWORD *)v14 + 2) + 4 * v20);
        if ( v24 != nullptr )
          *v24 = v17;
        CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
        v2 = buf;
      }
      while ( _V_stricmp(s1: pString, s2: "}") != 0 );
    }
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4BA0
// Name: private: void CSentence::ParseDataVersionOnePointZero(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseDataVersionOnePointZero(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1100h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( strlen(pString) != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    if ( _V_stricmp(s1: pDest, s2: "PLAINTEXT") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "WORDS") != 0 )
      {
        if ( _V_stricmp(s1: pDest, s2: "EMPHASIS") != 0 )
        {
          if ( _V_stricmp(s1: pDest, s2: "CLOSECAPTION") != 0 )
          {
            if ( _V_stricmp(s1: pDest, s2: "OPTIONS") == 0 )
              CSentence::ParseOptions(this, buf);
          }
          else
          {
            CSentence::ParseCloseCaption(this, buf);
          }
        }
        else
        {
          CSentence::ParseEmphasis(this, buf);
        }
      }
      else
      {
        CSentence::ParseWords(this, buf);
      }
    }
    else
    {
      CSentence::ParsePlaintext(this, buf);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4D10
// Name: public: void CSentence::CacheRestoreFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::CacheRestoreFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  signed __int8 v4; // al
  int v5; // ebx
  unsigned __int16 Short; // ax
  int i; // ebx
  __int16 v8; // ax
  __int16 v9; // ax
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  CEmphasisSample *v13; // ecx
  int v14; // eax
  CEmphasisSample *v15; // eax
  float v16; // edx
  int v17; // ecx
  unsigned __int8 v18; // cl
  unsigned __int16 Int; // bx
  int v20; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v24; // eax
  CEmphasisSample *v25; // eax
  float value; // edx
  int v27; // ecx
  bool v28; // zf
  unsigned __int16 v29; // bx
  __int16 v30; // ax
  __int16 v31; // ax
  int v32; // ebx
  int v33; // ecx
  int v34; // eax
  CEmphasisSample *v35; // ecx
  int v36; // eax
  CEmphasisSample *v37; // eax
  float v38; // edx
  int v39; // ecx
  CPhonemeTag pt; // [esp+Ch] [ebp-34h] BYREF
  CEmphasisSample sample; // [esp+28h] [ebp-18h]
  float et; // [esp+34h] [ebp-Ch] BYREF
  float st[2]; // [esp+38h] [ebp-8h] BYREF
  unsigned __int8 bufa; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufb; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufc; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufd; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufe; // [esp+48h] [ebp+8h]
  CUtlBuffer *buff; // [esp+48h] [ebp+8h]

  CSentence::Reset(this);
  *((_BYTE *)this + 75) = 1;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    v4 = 0;
  }
  v5 = v4;
  if ( v4 != 1 )
  {
    if ( v4 == 4 )
      goto LABEL_9;
    if ( v4 != 5 )
    {
      *((_BYTE *)this + 72) = 0;
      return;
    }
  }
  if ( v4 != 4 )
  {
    Short = CUtlBuffer::GetShort(this: buf);
    goto LABEL_17;
  }
LABEL_9:
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  Short = CUtlBuffer::GetInt(this: buf);
LABEL_17:
  memset(&pt, 0, 10);
  memset(&pt.m_uiStartByte, 0, 12);
  pt.m_bSelected = false;
  if ( v5 != 5 )
  {
    if ( v5 == 4 )
    {
      if ( Short != 0 )
      {
        for ( bufc = (CUtlBuffer *)Short; bufc != nullptr; bufc = (CUtlBuffer *)((char *)bufc - 1) )
        {
          Int = CUtlBuffer::GetInt(this: buf);
          CUtlBuffer::GetType<float>(this: buf, dest: &et);
          CUtlBuffer::GetType<float>(this: buf, dest: st);
          pt.m_flStartTime = et;
          pt.m_nPhonemeCode = Int;
          pt.m_flEndTime = st[0];
          CSentence::AddRuntimePhoneme(this, src: &pt);
        }
      }
      v20 = CUtlBuffer::GetInt(this: buf);
      if ( v20 > 0 )
      {
        for ( bufd = (CUtlBuffer *)v20; bufd != nullptr; bufd = (CUtlBuffer *)((char *)bufd - 1) )
        {
          sample.selected = false;
          CUtlBuffer::GetType<float>(this: buf, dest: &et);
          sample.time = et;
          CUtlBuffer::GetType<float>(this: buf, dest: st);
          m_Size = this->m_EmphasisSamples.m_Size;
          m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
          sample.value = st[0];
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
              this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_EmphasisSamples.m_Size;
          m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
          v24 = this->m_EmphasisSamples.m_Size - m_Size - 1;
          this->m_EmphasisSamples.m_pElements = m_pMemory;
          if ( v24 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v24);
          v25 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
          if ( v25 != nullptr )
          {
            value = sample.value;
            v25->time = sample.time;
            v27 = *(_DWORD *)&sample.selected;
            v25->value = value;
            *(_DWORD *)&v25->selected = v27;
          }
        }
      }
      v28 = CUtlBuffer::GetInt(this: buf) == 0;
      goto LABEL_67;
    }
    if ( Short != 0 )
    {
      for ( bufe = (CUtlBuffer *)Short; bufe != nullptr; bufe = (CUtlBuffer *)((char *)bufe - 1) )
      {
        v29 = CUtlBuffer::GetShort(this: buf);
        CUtlBuffer::GetType<float>(this: buf, dest: &et);
        CUtlBuffer::GetType<float>(this: buf, dest: st);
        pt.m_flStartTime = et;
        pt.m_nPhonemeCode = v29;
        pt.m_flEndTime = st[0];
        CSentence::AddRuntimePhoneme(this, src: &pt);
      }
    }
    v30 = CUtlBuffer::GetShort(this: buf);
    if ( v30 > 0 )
    {
      for ( buff = (CUtlBuffer *)v30; buff != nullptr; buff = (CUtlBuffer *)((char *)buff - 1) )
      {
        sample.selected = false;
        CUtlBuffer::GetType<float>(this: buf, dest: &et);
        sample.time = et;
        v31 = CUtlBuffer::GetShort(this: buf);
        v32 = this->m_EmphasisSamples.m_Size;
        v33 = v31;
        v34 = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
        sample.value = (float)v33 * 0.000030518509;
        if ( v32 + 1 > v34 )
          CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
            this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
            num: v32 - v34 + 1);
        ++this->m_EmphasisSamples.m_Size;
        v35 = this->m_EmphasisSamples.m_Memory.m_pMemory;
        v36 = this->m_EmphasisSamples.m_Size - v32 - 1;
        this->m_EmphasisSamples.m_pElements = v35;
        if ( v36 > 0 )
          _V_memmove(dest: &v35[v32 + 1], src: &v35[v32], count: 12 * v36);
        v37 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v32];
        if ( v37 != nullptr )
        {
          v38 = sample.value;
          v37->time = sample.time;
          v39 = *(_DWORD *)&sample.selected;
          v37->value = v38;
          *(_DWORD *)&v37->selected = v39;
        }
      }
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v18 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
      goto LABEL_66;
    }
LABEL_65:
    v18 = 0;
    goto LABEL_66;
  }
  if ( Short != 0 )
  {
    for ( i = Short; i != 0; --i )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        bufa = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        bufa = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        bufa = 0;
      }
      st[0] = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      et = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      pt.m_nPhonemeCode = ByteCodeToCode(byteCode: bufa);
      pt.m_flStartTime = st[0];
      pt.m_flEndTime = et;
      CSentence::AddRuntimePhoneme(this, src: &pt);
    }
  }
  v8 = CUtlBuffer::GetShort(this: buf);
  if ( v8 > 0 )
  {
    for ( bufb = (CUtlBuffer *)v8; bufb != nullptr; bufb = (CUtlBuffer *)((char *)bufb - 1) )
    {
      sample.selected = false;
      sample.time = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      v9 = CUtlBuffer::GetShort(this: buf);
      v10 = this->m_EmphasisSamples.m_Size;
      v11 = v9;
      v12 = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      sample.value = (float)v11 * 0.000030518509;
      if ( v10 + 1 > v12 )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
          num: v10 - v12 + 1);
      ++this->m_EmphasisSamples.m_Size;
      v13 = this->m_EmphasisSamples.m_Memory.m_pMemory;
      v14 = this->m_EmphasisSamples.m_Size - v10 - 1;
      this->m_EmphasisSamples.m_pElements = v13;
      if ( v14 > 0 )
        _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 12 * v14);
      v15 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v10];
      if ( v15 != nullptr )
      {
        v16 = sample.value;
        v15->time = sample.time;
        v17 = *(_DWORD *)&sample.selected;
        v15->value = v16;
        *(_DWORD *)&v15->selected = v17;
      }
    }
  }
  if ( !CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    goto LABEL_65;
  v18 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
  ++buf->m_Get;
LABEL_66:
  v28 = v18 == 0;
LABEL_67:
  *((_BYTE *)this + 74) = !v28;
  *((_BYTE *)this + 72) = 1;
  free(pMem: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D5200
// Name: public: void CSentence::InitFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1000h] BYREF

  CSentence::Reset(this);
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  if ( _V_stricmp(s1: pString, s2: "VERSION") == 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( atof(nptr: pString) == 1.0 )
    {
      CSentence::ParseDataVersionOnePointZero(this, buf);
      *((_BYTE *)this + 72) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5290
// Name: public: void CSentence::InitFromDataChunk(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromDataChunk(CSentence *this, void *data, int size)
{
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::EnsureCapacity(this: &buf, num: size);
  CUtlBuffer::Put(this: &buf, pMem: data, size);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: size);
  CSentence::InitFromBuffer(this, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x0040F500
// Name: public: void CWordTag::SetWord(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::SetWord(CWordTag *this, const char *word)
{
  unsigned int v3; // kr00_4
  char *v4; // eax

  free(pMem: this->m_pszWord);
  this->m_pszWord = nullptr;
  if ( word != nullptr && *word != 0 )
  {
    v3 = strlen(word);
    v4 = (char *)operator new(nSize: v3 + 1);
    this->m_pszWord = v4;
    V_strncpy(pDest: v4, pSrc: word, maxLen: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F560
// Name: public: char const __near * CWordTag::GetWord(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWordTag::GetWord(CWordTag *this)
{
  char *result; // eax

  result = this->m_pszWord;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F570
// Name: public: CPhonemeTag::CPhonemeTag(void)
// Source: json
//------------------------------------------------------------------------------
CPhonemeTag *__thiscall CPhonemeTag::CPhonemeTag(CPhonemeTag *this)
{
  this->m_flStartTime = 0.0;
  this->m_flEndTime = 0.0;
  this->m_nPhonemeCode = 0;
  this->m_szPhoneme = nullptr;
  this->m_uiStartByte = 0;
  this->m_uiEndByte = 0;
  this->m_bSelected = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F5A0
// Name: public: CPhonemeTag::~CPhonemeTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhonemeTag::~CPhonemeTag(CPhonemeTag *this)
{
  free(pMem: this->m_szPhoneme);
}

//------------------------------------------------------------------------------
// Address: 0x0040F5B0
// Name: public: void CPhonemeTag::SetTag(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhonemeTag::SetTag(CPhonemeTag *this, const char *phoneme)
{
  int v3; // esi
  char *v4; // eax

  free(pMem: this->m_szPhoneme);
  this->m_szPhoneme = nullptr;
  if ( phoneme != nullptr && *phoneme != 0 )
  {
    v3 = _V_strlen(str: phoneme) + 1;
    v4 = (char *)operator new(nSize: v3);
    this->m_szPhoneme = v4;
    V_strncpy(pDest: v4, pSrc: phoneme, maxLen: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F600
// Name: public: static char const __near * CSentence::NameForLanguage(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSentence::NameForLanguage(unsigned int language)
{
  if ( language > 0xB )
    return "unknown_language";
  else
    return g_CCLanguageLookup[language].name;
}

//------------------------------------------------------------------------------
// Address: 0x0040F620
// Name: public: void CSentence::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SetText(CSentence *this, const char *text)
{
  int v3; // esi
  char *v4; // eax

  free(pMem: this->m_szText);
  this->m_szText = nullptr;
  if ( text != nullptr && *text != 0 )
  {
    v3 = _V_strlen(str: text) + 1;
    v4 = (char *)operator new(nSize: v3);
    this->m_szText = v4;
    V_strncpy(pDest: v4, pSrc: text, maxLen: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F670
// Name: public: char const __near * CSentence::GetText(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSentence::GetText(CSentence *this)
{
  char *result; // eax

  result = this->m_szText;
  if ( this->m_szText == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F680
// Name: public: void CSentence::SetDataCheckSum(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SetDataCheckSum(CSentence *this, unsigned int chk)
{
  *((_BYTE *)this + 73) = 1;
  this->m_uCheckSum = chk;
}

//------------------------------------------------------------------------------
// Address: 0x0040F6A0
// Name: public: unsigned int CSentence::GetDataCheckSum(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSentence::GetDataCheckSum(CSentence *this)
{
  return this->m_uCheckSum;
}

//------------------------------------------------------------------------------
// Address: 0x0040F6B0
// Name: public: static int CSentence::CountWords(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSentence::CountWords(const char *str)
{
  const char *v1; // edx
  char v2; // cl
  int result; // eax

  v1 = str;
  if ( str == nullptr )
    return 0;
  v2 = *str;
  if ( *str == 0 )
    return 0;
  result = 1;
  do
  {
    if ( (unsigned __int8)v2 <= 0x20u )
    {
      ++result;
      if ( v2 == 0 )
        return result;
      while ( (unsigned __int8)v2 <= 0x20u )
      {
        v2 = *++v1;
        if ( v2 == 0 )
          return result;
      }
    }
    v2 = *++v1;
  }
  while ( v2 != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F700
// Name: public: CPhonemeTag::CPhonemeTag(class CPhonemeTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhonemeTag *__thiscall CPhonemeTag::CPhonemeTag(CPhonemeTag *this, const CPhonemeTag *from)
{
  unsigned int m_uiEndByte; // ecx
  char *m_szPhoneme; // ebx
  int v5; // edi
  char *v6; // eax

  this->CBasePhonemeTag = from->CBasePhonemeTag;
  m_uiEndByte = from->m_uiEndByte;
  this->m_uiStartByte = from->m_uiStartByte;
  this->m_uiEndByte = m_uiEndByte;
  this->m_bSelected = from->m_bSelected;
  this->m_szPhoneme = nullptr;
  m_szPhoneme = from->m_szPhoneme;
  if ( m_szPhoneme == nullptr )
    m_szPhoneme = (char *)defaultValue;
  free(pMem: nullptr);
  this->m_szPhoneme = nullptr;
  if ( m_szPhoneme != nullptr && *m_szPhoneme != 0 )
  {
    v5 = _V_strlen(str: m_szPhoneme) + 1;
    v6 = (char *)operator new(nSize: v5);
    this->m_szPhoneme = v6;
    V_strncpy(pDest: v6, pSrc: m_szPhoneme, maxLen: v5);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F780
// Name: private: void CSentence::ParsePlaintext(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParsePlaintext(CSentence *this, CUtlBuffer *buf)
{
  bool v3; // zf
  int v4; // esi
  char *v5; // eax
  char pString[4096]; // [esp+8h] [ebp-2000h] BYREF
  char pDest[4096]; // [esp+1008h] [ebp-1000h] BYREF

  pDest[0] = 0;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncat(pDest, pSrc: pString, destBufferSize: 0x1000u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: " ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
  free(pMem: this->m_szText);
  v3 = pDest[0] == 0;
  this->m_szText = nullptr;
  if ( !v3 )
  {
    v4 = _V_strlen(str: pDest) + 1;
    v5 = (char *)operator new(nSize: v4);
    this->m_szText = v5;
    V_strncpy(pDest: v5, pSrc: pDest, maxLen: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F870
// Name: private: void CSentence::ParseOptions(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseOptions(CSentence *this, CUtlBuffer *buf)
{
  unsigned int v3; // eax
  char pString[4096]; // [esp+8h] [ebp-1200h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-200h] BYREF
  char nptr[256]; // [esp+1108h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_strlen(str: pString) == 0 )
      break;
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    if ( _V_stricmp(s1: pDest, s2: "voice_duck") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "checksum") == 0 )
      {
        v3 = atoi(nptr);
        *((_BYTE *)this + 73) = 1;
        this->m_uCheckSum = v3;
      }
    }
    else
    {
      *((_BYTE *)this + 74) = atoi(nptr) != 0;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F9A0
// Name: public: int CSentence::GetNumSamples(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSentence::GetNumSamples(CSentence *this)
{
  return this->m_EmphasisSamples.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040F9B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FA50
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FAC0
// Name: public: void CByteswap::SwapBufferToTargetEndian<short>(short __near *,short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        __int16 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = (unsigned __int8 *)inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FB40
// Name: public: void CByteswap::SwapBufferToTargetEndian<int>(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FBD0
// Name: public: int CWordTag::IndexOfPhoneme(class CPhonemeTag __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWordTag::IndexOfPhoneme(CWordTag *this, CPhonemeTag *tag)
{
  int m_Size; // edx
  int result; // eax
  CPhonemeTag **i; // ecx

  m_Size = this->m_Phonemes.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Phonemes.m_Memory.m_pMemory; *i != tag; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FC00
// Name: public: unsigned int CWordTag::ComputeDataCheckSum(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWordTag::ComputeDataCheckSum(CWordTag *this)
{
  int v2; // eax
  int v3; // edi
  CPhonemeTag *v4; // esi
  int v5; // eax
  int c; // [esp+8h] [ebp-1Ch]
  unsigned int phonemeCheckSum; // [esp+Ch] [ebp-18h] BYREF
  float m_flEndTime; // [esp+10h] [ebp-14h] BYREF
  float m_flStartTime; // [esp+14h] [ebp-10h] BYREF
  int pBuffer; // [esp+18h] [ebp-Ch] BYREF
  unsigned int crc; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int pulCRC; // [esp+20h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  if ( this->m_pszWord != nullptr )
  {
    v2 = _V_strlen(str: this->m_pszWord);
    CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: this->m_pszWord, nBuffer: v2);
  }
  v3 = 0;
  c = this->m_Phonemes.m_Size;
  if ( c > 0 )
  {
    do
    {
      v4 = this->m_Phonemes.m_Memory.m_pMemory[v3];
      CRC32_Init(&pulCRC);
      v5 = _V_strlen(str: v4->m_szPhoneme);
      CRC32_ProcessBuffer(&pulCRC, pBuffer: v4->m_szPhoneme, nBuffer: v5);
      pBuffer = v4->m_nPhonemeCode;
      CRC32_ProcessBuffer(&pulCRC, &pBuffer, nBuffer: 4);
      m_flStartTime = v4->m_flStartTime;
      m_flEndTime = v4->m_flEndTime;
      CRC32_ProcessBuffer(&pulCRC, pBuffer: &m_flStartTime, nBuffer: 4);
      CRC32_ProcessBuffer(&pulCRC, pBuffer: &m_flEndTime, nBuffer: 4);
      CRC32_Final(&pulCRC);
      phonemeCheckSum = pulCRC;
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &phonemeCheckSum, nBuffer: 4);
      ++v3;
    }
    while ( v3 < c );
  }
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: this, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->m_flEndTime, nBuffer: 4);
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x0040FD10
// Name: public: void CSentence::SaveToBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SaveToBuffer(CSentence *this, CUtlBuffer *buf)
{
  CSentence *v3; // edi
  const char *m_szText; // eax
  CWordTag *v5; // edi
  const char *m_pszWord; // eax
  int j; // ebx
  CPhonemeTag *v8; // eax
  const char *m_szPhoneme; // ecx
  int v10; // ebx
  int i; // [esp+28h] [ebp+8h]
  int ia; // [esp+28h] [ebp+8h]

  v3 = this;
  CUtlBuffer::Printf(this: buf, pFmt: "VERSION 1.0\n");
  CUtlBuffer::Printf(this: buf, pFmt: "PLAINTEXT\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_szText = v3->m_szText;
  if ( v3->m_szText == nullptr )
    m_szText = defaultValue;
  CUtlBuffer::Printf(this: buf, pFmt: (const char *)&stru_4EDE64, m_szText);
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "WORDS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  i = 0;
  if ( v3->m_Words.m_Size > 0 )
  {
    do
    {
      v5 = v3->m_Words.m_Memory.m_pMemory[i];
      m_pszWord = v5->m_pszWord;
      if ( m_pszWord == nullptr )
        m_pszWord = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "WORD %s %.3f %.3f\n", m_pszWord, v5->m_flStartTime, v5->m_flEndTime);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      for ( j = 0; j < v5->m_Phonemes.m_Size; ++j )
      {
        v8 = v5->m_Phonemes.m_Memory.m_pMemory[j];
        m_szPhoneme = v8->m_szPhoneme;
        if ( m_szPhoneme == nullptr )
          m_szPhoneme = defaultValue;
        CUtlBuffer::Printf(
          this: buf,
          pFmt: "%i %s %.3f %.3f 1\n",
          v8->m_nPhonemeCode,
          m_szPhoneme,
          v8->m_flStartTime,
          v8->m_flEndTime);
      }
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      ++i;
      v3 = this;
    }
    while ( i < this->m_Words.m_Size );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "EMPHASIS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  if ( v3->m_EmphasisSamples.m_Size > 0 )
  {
    v10 = 0;
    ia = v3->m_EmphasisSamples.m_Size;
    do
    {
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "%f %f\n",
        v3->m_EmphasisSamples.m_Memory.m_pMemory[v10].time,
        v3->m_EmphasisSamples.m_Memory.m_pMemory[v10].value);
      ++v10;
      --ia;
    }
    while ( ia != 0 );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "OPTIONS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  CUtlBuffer::Printf(this: buf, pFmt: "voice_duck %d\n", *((_BYTE *)v3 + 74) != 0);
  if ( *((_BYTE *)v3 + 73) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "checksum %d\n", v3->m_uCheckSum);
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x0040FF30
// Name: public: int CSentence::CountPhonemes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSentence::CountPhonemes(CSentence *this)
{
  int m_Size; // edx
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  CWordTag **m_pMemory; // eax
  unsigned int v7; // edx
  int i; // [esp+Ch] [ebp-8h]

  m_Size = this->m_Words.m_Size;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( m_Size >= 2 )
  {
    m_pMemory = this->m_Words.m_Memory.m_pMemory;
    v7 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    i = 2 * v7;
    do
    {
      v3 += (*m_pMemory)->m_Phonemes.m_Size;
      v4 += m_pMemory[1]->m_Phonemes.m_Size;
      m_pMemory += 2;
      --v7;
    }
    while ( v7 != 0 );
    v2 = 0;
    v5 = i;
  }
  if ( v5 < this->m_Words.m_Size )
    v2 = this->m_Words.m_Memory.m_pMemory[v5]->m_Phonemes.m_Size;
  return v2 + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040FFA0
// Name: public: class CWordTag __near * CSentence::GetWordForPhoneme(class CPhonemeTag __near *)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CSentence::GetWordForPhoneme(CSentence *this, CPhonemeTag *phoneme)
{
  int m_Size; // edx
  int v3; // edi
  CWordTag **m_pMemory; // ecx
  CWordTag *result; // eax
  int v6; // esi
  int v7; // ecx
  CPhonemeTag **v8; // edx
  int v9; // [esp+Ch] [ebp-8h]
  CWordTag **i; // [esp+10h] [ebp-4h]

  m_Size = this->m_Words.m_Size;
  v3 = 0;
  v9 = m_Size;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Words.m_Memory.m_pMemory;
  for ( i = m_pMemory; ; ++i )
  {
    result = *m_pMemory;
    if ( *m_pMemory != nullptr )
    {
      v6 = result->m_Phonemes.m_Size;
      v7 = 0;
      if ( v6 > 0 )
        break;
    }
LABEL_9:
    ++v3;
    m_pMemory = i + 1;
    if ( v3 >= m_Size )
      return nullptr;
  }
  v8 = result->m_Phonemes.m_Memory.m_pMemory;
  while ( *v8 != phoneme )
  {
    ++v7;
    ++v8;
    if ( v7 >= v6 )
    {
      m_Size = v9;
      goto LABEL_9;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410000
// Name: public: void CSentence::Resort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Resort(CSentence *this)
{
  int m_Size; // edx
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  CEmphasisSample *m_pMemory; // edx
  __int64 v7; // xmm0_8
  __int64 v8; // xmm1_8
  int v9; // edi
  int v10; // ebx
  CEmphasisSample *v11; // edx
  CEmphasisSample *v12; // edx
  __int64 v13; // xmm0_8
  __int64 v14; // xmm1_8
  int v15; // edi
  int v16; // ebx
  char *v17; // edx
  CEmphasisSample *v18; // edx
  __int64 v19; // xmm0_8
  __int64 v20; // xmm1_8
  int v21; // ebx
  int v22; // edi
  char *v23; // edx
  CEmphasisSample *v24; // edx
  __int64 v25; // xmm0_8
  __int64 v26; // xmm1_8
  int v27; // ebx
  char *v28; // edx
  int v29; // esi
  CEmphasisSample *v30; // edx
  __int64 v31; // xmm0_8
  __int64 v32; // xmm1_8
  int v33; // edi
  int v34; // ebx
  CEmphasisSample *v35; // edx
  bool v36; // zf
  int src_8; // [esp+14h] [ebp-1Ch]
  int src_8a; // [esp+14h] [ebp-1Ch]
  int j; // [esp+18h] [ebp-18h]
  int v40; // [esp+1Ch] [ebp-14h]
  int c; // [esp+20h] [ebp-10h]
  unsigned int v42; // [esp+24h] [ebp-Ch]
  int v43; // [esp+24h] [ebp-Ch]
  int v44; // [esp+28h] [ebp-8h]
  int v45; // [esp+2Ch] [ebp-4h]

  m_Size = this->m_EmphasisSamples.m_Size;
  c = m_Size;
  if ( m_Size > 0 )
  {
    v2 = 1;
    v3 = 0;
    v44 = 1;
    v45 = m_Size - 1;
    v40 = this->m_EmphasisSamples.m_Size;
    do
    {
      v4 = v2;
      if ( v2 < m_Size )
      {
        if ( v45 >= 4 )
        {
          v42 = ((unsigned int)(m_Size - v2 - 4) >> 2) + 1;
          v5 = v3 * 12 + 12;
          j = v2 + 4 * v42;
          do
          {
            m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
            v7 = *(_QWORD *)&m_pMemory[v3].time;
            v8 = *(_QWORD *)((char *)&m_pMemory->time + v5);
            v9 = *(_DWORD *)&m_pMemory[v3].selected;
            v10 = *(_DWORD *)(&m_pMemory->selected + v5);
            if ( *(float *)&v7 > *(float *)&v8 )
            {
              *(_QWORD *)&m_pMemory[v3].time = v8;
              *(_DWORD *)&m_pMemory[v3].selected = v10;
              v11 = this->m_EmphasisSamples.m_Memory.m_pMemory;
              *(_QWORD *)((char *)&v11->time + v5) = v7;
              *(_DWORD *)(&v11->selected + v5) = v9;
            }
            v12 = this->m_EmphasisSamples.m_Memory.m_pMemory;
            v13 = *(_QWORD *)&v12[v3].time;
            v14 = *(_QWORD *)((char *)&v12[1].time + v5);
            v15 = *(_DWORD *)&v12[v3].selected;
            v16 = *(_DWORD *)(&v12[1].selected + v5);
            if ( *(float *)&v13 > *(float *)&v14 )
            {
              *(_QWORD *)&v12[v3].time = v14;
              *(_DWORD *)&v12[v3].selected = v16;
              v17 = (char *)&this->m_EmphasisSamples.m_Memory.m_pMemory[1] + v5;
              *(_QWORD *)v17 = v13;
              *((_DWORD *)v17 + 2) = v15;
            }
            v18 = this->m_EmphasisSamples.m_Memory.m_pMemory;
            v19 = *(_QWORD *)&v18[v3].time;
            v20 = *(_QWORD *)((char *)&v18[2].time + v5);
            v21 = *(_DWORD *)(&v18[2].selected + v5);
            src_8 = *(_DWORD *)&v18[v3].selected;
            v22 = v5 + 36;
            if ( *(float *)&v19 > *(float *)&v20 )
            {
              *(_QWORD *)&v18[v3].time = v20;
              *(_DWORD *)&v18[v3].selected = v21;
              v23 = (char *)&this->m_EmphasisSamples.m_Memory.m_pMemory[2] + v5;
              *(_QWORD *)v23 = v19;
              *((_DWORD *)v23 + 2) = src_8;
            }
            v24 = this->m_EmphasisSamples.m_Memory.m_pMemory;
            v25 = *(_QWORD *)&v24[v3].time;
            v26 = *(_QWORD *)((char *)&v24->time + v22);
            src_8a = *(_DWORD *)&v24[v3].selected;
            v27 = *(_DWORD *)(&v24->selected + v22);
            if ( *(float *)&v25 > *(float *)&v26 )
            {
              *(_QWORD *)&v24[v3].time = v26;
              *(_DWORD *)&v24[v3].selected = v27;
              v28 = (char *)this->m_EmphasisSamples.m_Memory.m_pMemory + v22;
              *(_QWORD *)v28 = v25;
              *((_DWORD *)v28 + 2) = src_8a;
            }
            v5 += 48;
            --v42;
          }
          while ( v42 != 0 );
          v2 = v44;
          v4 = j;
          m_Size = c;
        }
        if ( v4 < m_Size )
        {
          v29 = v4;
          v43 = m_Size - v4;
          do
          {
            v30 = this->m_EmphasisSamples.m_Memory.m_pMemory;
            v31 = *(_QWORD *)&v30[v3].time;
            v32 = *(_QWORD *)&v30[v29].time;
            v33 = *(_DWORD *)&v30[v3].selected;
            v34 = *(_DWORD *)&v30[v29].selected;
            if ( *(float *)&v31 > *(float *)&v32 )
            {
              *(_QWORD *)&v30[v3].time = v32;
              *(_DWORD *)&v30[v3].selected = v34;
              v35 = this->m_EmphasisSamples.m_Memory.m_pMemory;
              *(_QWORD *)&v35[v29].time = v31;
              *(_DWORD *)&v35[v29].selected = v33;
            }
            ++v29;
            --v43;
          }
          while ( v43 != 0 );
          m_Size = c;
          v2 = v44;
        }
      }
      --v45;
      ++v2;
      ++v3;
      v36 = v40-- == 1;
      v44 = v2;
    }
    while ( !v36 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410210
// Name: public: struct CEmphasisSample __near * CSentence::GetSample(int)
// Source: json
//------------------------------------------------------------------------------
CEmphasisSample *__thiscall CSentence::GetSample(CSentence *this, int index)
{
  if ( index < 0 || index >= this->m_EmphasisSamples.m_Size )
    return nullptr;
  else
    return &this->m_EmphasisSamples.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x00410240
// Name: public: unsigned int CSentence::ComputeDataCheckSum(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSentence::ComputeDataCheckSum(CSentence *this)
{
  char *m_szText; // ecx
  char *v3; // edi
  int v4; // eax
  int m_Size; // ebx
  int i; // edi
  int v7; // ebx
  int v8; // edi
  unsigned int wordCheckSum; // [esp+Ch] [ebp-8h] BYREF
  unsigned int crc; // [esp+10h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  m_szText = this->m_szText;
  if ( this->m_szText != nullptr )
  {
    v3 = this->m_szText;
  }
  else
  {
    m_szText = (char *)defaultValue;
    v3 = (char *)defaultValue;
  }
  v4 = _V_strlen(str: m_szText);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: v3, nBuffer: v4);
  m_Size = this->m_Words.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    wordCheckSum = CWordTag::ComputeDataCheckSum(this: this->m_Words.m_Memory.m_pMemory[i]);
    CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &wordCheckSum, nBuffer: 4);
  }
  v7 = this->m_EmphasisSamples.m_Size;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->m_EmphasisSamples.m_Memory.m_pMemory[v8], nBuffer: 4);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->m_EmphasisSamples.m_Memory.m_pMemory[v8++].value, nBuffer: 4);
      --v7;
    }
    while ( v7 != 0 );
  }
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x00410350
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410390
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004103D0
// Name: protected: void CUtlBuffer::PutTypeBin<short>(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<short>(CUtlBuffer *this, __int16 src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 2) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<short>(
        this: &this->m_Byteswap,
        outputBuffer: &this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_WORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 2;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410440
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004104B0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410500
// Name: private: void CSentence::ParseCloseCaption(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseCloseCaption(CSentence *this, CUtlBuffer *buf)
{
  int v2; // edi
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-2020h] BYREF
  char pString[4096]; // [esp+1008h] [ebp-1020h] BYREF
  char pDest[32]; // [esp+2008h] [ebp-20h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    while ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      if ( _V_stricmp(s1: pString, s2: "PHRASE") != 0 )
        break;
      memset(dst, value: 0, count: sizeof(dst));
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      V_strncpy(pDest, pSrc: pString, maxLen: 32);
      if ( _V_stricmp(s1: pDest, s2: "unicode") != 0 )
        _V_stricmp(s1: pDest, s2: "char");
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      v2 = atoi(nptr: pString);
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::Get(this: buf, pMem: dst, size: v2);
      dst[v2] = 0;
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004106F0
// Name: public: void CSentence::ClearRuntimePhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ClearRuntimePhonemes(CSentence *this)
{
  for ( ; this->m_RunTimePhonemes.m_Size > 0; --this->m_RunTimePhonemes.m_Size )
  {
    free(pMem: *(void **)this->m_RunTimePhonemes.m_Memory.m_pMemory);
    if ( this->m_RunTimePhonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_RunTimePhonemes.m_Memory.m_pMemory,
        src: this->m_RunTimePhonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_RunTimePhonemes.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410740
// Name: public: float CSentence::GetIntensity(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSentence::GetIntensity(CSentence *this, float time, int endtime)
{
  float t; // xmm0_4
  int v6; // eax
  int v7; // ebx
  int *v8; // edx
  int v9; // edi
  int *v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // edi
  int v14; // ebx
  int m_Size; // eax
  CEmphasisSample *v16; // esi
  CEmphasisSample *v17; // edx
  int *v18; // eax
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm5_4
  float v22; // xmm5_4
  float v23; // xmm5_4
  float v24; // xmm5_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  Vector vOut; // [esp+8h] [ebp-40h] BYREF
  Vector vPre; // [esp+14h] [ebp-34h] BYREF
  Vector vStart; // [esp+20h] [ebp-28h] BYREF
  Vector vEnd; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector vNext; // [esp+38h] [ebp-10h] BYREF
  int c; // [esp+44h] [ebp-4h]
  int *retval; // [esp+54h] [ebp+Ch]

  c = this->m_EmphasisSamples.m_Size;
  if ( c <= 0 )
    return 0.5;
  t = 0.0;
  v6 = -1;
  v7 = -12;
  do
  {
    dword_5436F8 = 0;
    dword_5436FC = 1056964608;
    dword_5436EC = endtime;
    dword_5436F0 = 1056964608;
    if ( v6 >= 0 )
    {
      if ( v6 < this->m_EmphasisSamples.m_Size )
        v8 = (int *)((char *)this->m_EmphasisSamples.m_Memory.m_pMemory + v7);
      else
        v8 = &dword_5436EC;
    }
    else
    {
      v8 = &dword_5436F8;
    }
    v9 = v6 + 1;
    dword_5436F8 = 0;
    dword_5436FC = 1056964608;
    dword_5436EC = endtime;
    dword_5436F0 = 1056964608;
    if ( v6 + 1 >= 0 )
    {
      if ( v9 < this->m_EmphasisSamples.m_Size )
        v10 = (int *)((char *)&this->m_EmphasisSamples.m_Memory.m_pMemory[1] + v7);
      else
        v10 = &dword_5436EC;
    }
    else
    {
      v10 = &dword_5436F8;
    }
    if ( v8 != nullptr && v10 != nullptr && time >= *(float *)v8 && *(float *)v10 >= time )
      break;
    ++v6;
    v7 += 12;
  }
  while ( v9 < c );
  v11 = v6 - 1;
  v12 = v6;
  v13 = v6 + 1;
  v14 = v6 + 2;
  if ( v6 - 1 < -1 )
    v11 = -1;
  if ( v6 < -1 )
    v12 = -1;
  m_Size = this->m_EmphasisSamples.m_Size;
  if ( v13 >= m_Size )
    v13 = this->m_EmphasisSamples.m_Size;
  if ( v14 >= m_Size )
    v14 = this->m_EmphasisSamples.m_Size;
  dword_5436F8 = 0;
  dword_5436FC = 1056964608;
  dword_5436EC = endtime;
  dword_5436F0 = 1056964608;
  if ( v11 >= 0 )
  {
    if ( v11 < this->m_EmphasisSamples.m_Size )
      retval = (int *)&this->m_EmphasisSamples.m_Memory.m_pMemory[v11];
    else
      retval = &dword_5436EC;
  }
  else
  {
    retval = &dword_5436F8;
  }
  dword_5436F8 = 0;
  dword_5436FC = 1056964608;
  dword_5436EC = endtime;
  dword_5436F0 = 1056964608;
  if ( v12 >= 0 )
  {
    if ( v12 < this->m_EmphasisSamples.m_Size )
      v16 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v12];
    else
      v16 = (CEmphasisSample *)&dword_5436EC;
  }
  else
  {
    v16 = (CEmphasisSample *)&dword_5436F8;
  }
  dword_5436F8 = 0;
  dword_5436FC = 1056964608;
  dword_5436EC = endtime;
  dword_5436F0 = 1056964608;
  if ( v13 >= 0 )
  {
    if ( v13 < this->m_EmphasisSamples.m_Size )
      v17 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v13];
    else
      v17 = (CEmphasisSample *)&dword_5436EC;
  }
  else
  {
    v17 = (CEmphasisSample *)&dword_5436F8;
  }
  dword_5436F8 = 0;
  dword_5436FC = 1056964608;
  dword_5436EC = endtime;
  dword_5436F0 = 1056964608;
  if ( v14 >= 0 )
  {
    if ( v14 < this->m_EmphasisSamples.m_Size )
      v18 = (int *)&this->m_EmphasisSamples.m_Memory.m_pMemory[v14];
    else
      v18 = &dword_5436EC;
  }
  else
  {
    v18 = &dword_5436F8;
  }
  v19 = v17->time - v16->time;
  v20 = 0.0099999998;
  if ( v19 >= 0.0099999998 )
  {
    if ( v19 <= 1.0 )
      v20 = v17->time - v16->time;
    else
      v20 = 1.0;
  }
  v21 = *(float *)retval;
  LODWORD(vPre.y) = retval[1];
  vPre.x = v21;
  vPre.z = 0.0;
  v22 = v16->time;
  vStart.y = v16->value;
  vStart.x = v22;
  vStart.z = 0.0;
  v23 = v17->time;
  vEnd.y = v17->value;
  vEnd.x = v23;
  vEnd.z = 0.0;
  v24 = *(float *)v18;
  LODWORD(vNext.y) = v18[1];
  vNext.x = v24;
  vNext.z = 0.0;
  v25 = (float)(time - v16->time) / v20;
  if ( v25 >= 0.0 )
  {
    if ( v25 <= 1.0 )
      t = (float)(time - v16->time) / v20;
    else
      t = 1.0;
  }
  Catmull_Rom_Spline(p1: &vPre, p2: &vStart, p3: &vEnd, p4: &vNext, t, output: &vOut);
  v26 = 0.0;
  if ( vOut.y < 0.0 )
    return v26;
  v26 = 1.0;
  if ( vOut.y > 1.0 )
    return v26;
  else
    return vOut.y;
}

//------------------------------------------------------------------------------
// Address: 0x00410B60
// Name: public: CWordTag::CWordTag(void)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this)
{
  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_pszWord = nullptr;
  this->m_uiStartByte = 0;
  this->m_uiEndByte = 0;
  this->m_flStartTime = 0.0;
  this->m_flEndTime = 0.0;
  this->m_bSelected = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410B90
// Name: public: CWordTag::CWordTag(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this, const char *word)
{
  unsigned int v3; // kr00_4
  char *v4; // eax

  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_uiStartByte = 0;
  this->m_uiEndByte = 0;
  this->m_flStartTime = 0.0;
  this->m_flEndTime = 0.0;
  this->m_pszWord = nullptr;
  this->m_bSelected = false;
  free(pMem: nullptr);
  this->m_pszWord = nullptr;
  if ( word != nullptr && *word != 0 )
  {
    v3 = strlen(word);
    v4 = (char *)operator new(nSize: v3 + 1);
    this->m_pszWord = v4;
    V_strncpy(pDest: v4, pSrc: word, maxLen: v3 + 1);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410C10
// Name: public: CWordTag::~CWordTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::~CWordTag(CWordTag *this)
{
  CPhonemeTag *v2; // edi

  free(pMem: this->m_pszWord);
  for ( ; this->m_Phonemes.m_Size > 0; --this->m_Phonemes.m_Size )
  {
    v2 = *this->m_Phonemes.m_Memory.m_pMemory;
    if ( v2 != nullptr )
    {
      free(pMem: v2->m_szPhoneme);
      free(pMem: v2);
    }
    if ( this->m_Phonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Phonemes.m_Memory.m_pMemory,
        src: this->m_Phonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Phonemes.m_Size - 1));
  }
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Phonemes);
}

//------------------------------------------------------------------------------
// Address: 0x00410C80
// Name: public: CSentence::CSentence(void)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::CSentence(CSentence *this)
{
  this->m_Words.m_Memory.m_pMemory = nullptr;
  this->m_Words.m_Memory.m_nAllocationCount = 0;
  this->m_Words.m_Memory.m_nGrowSize = 0;
  this->m_Words.m_Size = 0;
  this->m_Words.m_pElements = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_pMemory = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_nAllocationCount = 0;
  this->m_RunTimePhonemes.m_Memory.m_nGrowSize = 0;
  this->m_RunTimePhonemes.m_Size = 0;
  this->m_RunTimePhonemes.m_pElements = nullptr;
  this->m_EmphasisSamples.m_Memory.m_pMemory = nullptr;
  this->m_EmphasisSamples.m_Memory.m_nAllocationCount = 0;
  this->m_EmphasisSamples.m_Memory.m_nGrowSize = 0;
  this->m_EmphasisSamples.m_Size = 0;
  this->m_EmphasisSamples.m_pElements = nullptr;
  this->m_nResetWordBase = 0;
  this->m_szText = nullptr;
  this->m_uCheckSum = 0;
  *(_WORD *)((char *)this + 73) = 0;
  *((_BYTE *)this + 72) = 0;
  *((_BYTE *)this + 75) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410CD0
// Name: public: void CSentence::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Reset(CSentence *this)
{
  bool v2; // cc
  CWordTag **m_pMemory; // eax
  CWordTag *v4; // edi

  v2 = this->m_Words.m_Size <= 0;
  this->m_nResetWordBase = 0;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_Words.m_Memory.m_pMemory;
      v4 = *m_pMemory;
      if ( *m_pMemory != nullptr )
      {
        CWordTag::~CWordTag(this: *m_pMemory);
        free(pMem: v4);
      }
      if ( this->m_Words.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Words.m_Memory.m_pMemory,
          src: this->m_Words.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Words.m_Size - 1));
      --this->m_Words.m_Size;
    }
    while ( this->m_Words.m_Size > 0 );
  }
  this->m_EmphasisSamples.m_Size = 0;
  CSentence::ClearRuntimePhonemes(this);
}

//------------------------------------------------------------------------------
// Address: 0x00410D40
// Name: public: CWordTag::CWordTag(class CWordTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this, const CWordTag *from)
{
  CWordTag *v2; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Phonemes; // edi
  char *m_pszWord; // ebx
  unsigned int v5; // kr00_4
  char *v6; // eax
  unsigned int m_uiEndByte; // ecx
  int v8; // ebx
  CPhonemeTag *v9; // eax
  CPhonemeTag *v10; // esi
  CPhonemeTag *v11; // eoff
  unsigned int v12; // ecx
  char *m_szPhoneme; // eax
  const char *v14; // ebx
  int v15; // ebx
  char *v16; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v19; // ecx
  int v20; // eax
  CPhonemeTag **v21; // esi
  int p; // [esp+Ch] [ebp-Ch]
  const char *newPhoneme; // [esp+14h] [ebp-4h]
  CPhonemeTag *newPhonemea; // [esp+14h] [ebp-4h]

  v2 = this;
  p_m_Phonemes = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Phonemes;
  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_pszWord = nullptr;
  m_pszWord = from->m_pszWord;
  free(pMem: nullptr);
  v2->m_pszWord = nullptr;
  if ( m_pszWord != nullptr && *m_pszWord != 0 )
  {
    v5 = strlen(m_pszWord);
    v6 = (char *)operator new(nSize: v5 + 1);
    this->m_pszWord = v6;
    V_strncpy(pDest: v6, pSrc: m_pszWord, maxLen: v5 + 1);
    v2 = this;
  }
  m_uiEndByte = from->m_uiEndByte;
  v2->m_uiStartByte = from->m_uiStartByte;
  v2->m_uiEndByte = m_uiEndByte;
  v2->m_flStartTime = from->m_flStartTime;
  v8 = 0;
  p = 0;
  v2->m_flEndTime = from->m_flEndTime;
  v2->m_bSelected = from->m_bSelected;
  if ( from->m_Phonemes.m_Size <= 0 )
    return v2;
  do
  {
    v9 = (CPhonemeTag *)operator new(nSize: 0x1Cu);
    v10 = v9;
    if ( v9 != nullptr )
    {
      v11 = from->m_Phonemes.m_Memory.m_pMemory[v8];
      *(_QWORD *)&v9->m_flStartTime = *(_QWORD *)&v11->m_flStartTime;
      *(_DWORD *)&v9->m_nPhonemeCode = *(_DWORD *)&v11->m_nPhonemeCode;
      v12 = v11->m_uiEndByte;
      v9->m_uiStartByte = v11->m_uiStartByte;
      v9->m_uiEndByte = v12;
      v9->m_bSelected = v11->m_bSelected;
      v9->m_szPhoneme = nullptr;
      m_szPhoneme = v11->m_szPhoneme;
      if ( m_szPhoneme != nullptr )
      {
        v14 = m_szPhoneme;
        newPhoneme = m_szPhoneme;
      }
      else
      {
        newPhoneme = defaultValue;
        v14 = defaultValue;
      }
      free(pMem: nullptr);
      v10->m_szPhoneme = nullptr;
      if ( v14 != nullptr && *v14 != 0 )
      {
        v15 = _V_strlen(str: v14) + 1;
        v16 = (char *)operator new(nSize: v15);
        v10->m_szPhoneme = v16;
        V_strncpy(pDest: v16, pSrc: newPhoneme, maxLen: v15);
      }
      v8 = p;
      newPhonemea = v10;
    }
    else
    {
      newPhonemea = nullptr;
    }
    m_pMemory = p_m_Phonemes[1].m_pMemory;
    m_nAllocationCount = p_m_Phonemes->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_m_Phonemes, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_Phonemes[1].m_pMemory;
    v19 = p_m_Phonemes->m_pMemory;
    v20 = (char *)p_m_Phonemes[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Phonemes[1].m_nAllocationCount = (int)p_m_Phonemes->m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[(_DWORD)m_pMemory + 1], src: &v19[(_DWORD)m_pMemory], count: 4 * v20);
    v21 = (CPhonemeTag **)&p_m_Phonemes->m_pMemory[(_DWORD)m_pMemory];
    if ( v21 != nullptr )
      *v21 = newPhonemea;
    p = ++v8;
  }
  while ( v8 < from->m_Phonemes.m_Size );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410F00
// Name: public: CSentence::~CSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::~CSentence(CSentence *this)
{
  CSentence::Reset(this);
  free(pMem: this->m_szText);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_EmphasisSamples);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_RunTimePhonemes);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Words);
}

//------------------------------------------------------------------------------
// Address: 0x00410F30
// Name: private: void CSentence::ParseEmphasis(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseEmphasis(CSentence *this, CUtlBuffer *buf)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v6; // eax
  CEmphasisSample *v7; // eax
  int v8; // ecx
  char pString[4096]; // [esp+8h] [ebp-120Ch] BYREF
  char nptr[256]; // [esp+1008h] [ebp-20Ch] BYREF
  char pDest[256]; // [esp+1108h] [ebp-10Ch] BYREF
  __int64 v12; // [esp+1208h] [ebp-Ch]
  int v13; // [esp+1210h] [ebp-4h]

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    LOBYTE(v13) = 0;
    *(float *)&v12 = atof(nptr: pDest);
    *((float *)&v12 + 1) = atof(nptr);
    m_Size = this->m_EmphasisSamples.m_Size;
    m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
        this: (CUtlMemory<CAppSystemGroup::Module_t,int> *)&this->m_EmphasisSamples,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EmphasisSamples.m_Size;
    m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
    v6 = this->m_EmphasisSamples.m_Size - m_Size - 1;
    this->m_EmphasisSamples.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v6);
    v7 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
    {
      v8 = v13;
      *(_QWORD *)&v7->time = v12;
      *(_DWORD *)&v7->selected = v8;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411080
// Name: public: void CSentence::AddWordTag(class CWordTag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::AddWordTag(CSentence *this, CWordTag *tag)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Words; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Words.m_Memory.m_nAllocationCount;
  p_m_Words = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Words;
  m_Size = this->m_Words.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_m_Words, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Words[1].m_pMemory;
  m_pMemory = p_m_Words->m_pMemory;
  v6 = (int)p_m_Words[1].m_pMemory - m_Size - 1;
  p_m_Words[1].m_nAllocationCount = (int)p_m_Words->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Words->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)tag;
}

//------------------------------------------------------------------------------
// Address: 0x004110E0
// Name: public: class CSentence __near & CSentence::operator=(class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::operator=(CSentence *this, const CSentence *src)
{
  CSentence *v2; // esi
  const CSentence *v3; // ebx
  const CWordTag *v4; // edi
  CWordTag *v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v9; // eax
  CWordTag **v10; // eax
  char *m_szText; // edi
  int v12; // esi
  char *v13; // eax
  int v14; // edi
  int v15; // eax
  CEmphasisSample *v16; // ecx
  int v17; // eax
  CEmphasisSample *v18; // eax
  CBasePhonemeTag *v19; // eax
  int v20; // edi
  _DWORD *v21; // eax
  CBasePhonemeTag *v22; // ebx
  int v23; // edi
  int v24; // eax
  CBasePhonemeTag **v25; // ecx
  int v26; // eax
  CBasePhonemeTag **v27; // eax
  __int64 full; // [esp+Ch] [ebp-34h]
  CWordTag *newWord; // [esp+34h] [ebp-Ch]
  CWordTag *newWorda; // [esp+34h] [ebp-Ch]
  CWordTag *newWordb; // [esp+34h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-4h]
  int ia; // [esp+3Ch] [ebp-4h]
  int ib; // [esp+3Ch] [ebp-4h]
  CEmphasisSample s; // 0:^3C.12

  v2 = this;
  CSentence::Reset(this);
  v3 = src;
  for ( i = 0; i < src->m_Words.m_Size; ++i )
  {
    v4 = src->m_Words.m_Memory.m_pMemory[i];
    v5 = (CWordTag *)operator new(nSize: 0x2Cu);
    if ( v5 != nullptr )
      newWord = CWordTag::CWordTag(this: v5, from: v4);
    else
      newWord = nullptr;
    m_Size = v2->m_Words.m_Size;
    m_nAllocationCount = v2->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_Words.m_Size;
    m_pMemory = v2->m_Words.m_Memory.m_pMemory;
    v9 = v2->m_Words.m_Size - m_Size - 1;
    v2->m_Words.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &v2->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = newWord;
  }
  m_szText = src->m_szText;
  if ( src->m_szText == nullptr )
    m_szText = (char *)defaultValue;
  free(pMem: v2->m_szText);
  v2->m_szText = nullptr;
  if ( m_szText != nullptr && *m_szText != 0 )
  {
    v12 = _V_strlen(str: m_szText) + 1;
    v13 = (char *)operator new(nSize: v12);
    this->m_szText = v13;
    V_strncpy(pDest: v13, pSrc: m_szText, maxLen: v12);
    v2 = this;
  }
  v2->m_nResetWordBase = src->m_nResetWordBase;
  if ( src->m_EmphasisSamples.m_Size > 0 )
  {
    ia = 0;
    newWorda = (CWordTag *)src->m_EmphasisSamples.m_Size;
    do
    {
      v14 = v2->m_EmphasisSamples.m_Size;
      s = src->m_EmphasisSamples.m_Memory.m_pMemory[ia];
      v15 = v2->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      if ( v14 + 1 > v15 )
        CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
          this: (CUtlMemory<CAppSystemGroup::Module_t,int> *)&v2->m_EmphasisSamples,
          num: v14 - v15 + 1);
      ++v2->m_EmphasisSamples.m_Size;
      v16 = v2->m_EmphasisSamples.m_Memory.m_pMemory;
      v17 = v2->m_EmphasisSamples.m_Size - v14 - 1;
      v2->m_EmphasisSamples.m_pElements = v16;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 12 * v17);
      v18 = &v2->m_EmphasisSamples.m_Memory.m_pMemory[v14];
      if ( v18 != nullptr )
        *v18 = s;
      ++ia;
      newWorda = (CWordTag *)((char *)newWorda - 1);
    }
    while ( newWorda != nullptr );
    v2 = this;
  }
  *((_BYTE *)v2 + 75) = *((_BYTE *)src + 75);
  newWordb = (CWordTag *)src->m_RunTimePhonemes.m_Size;
  ib = 0;
  if ( (int)newWordb > 0 )
  {
    do
    {
      v19 = v3->m_RunTimePhonemes.m_Memory.m_pMemory[ib];
      v20 = *(_DWORD *)&v19->m_nPhonemeCode;
      full = *(_QWORD *)&v19->m_flStartTime;
      v21 = operator new(nSize: 0xCu);
      if ( v21 != nullptr )
      {
        *v21 = 0;
        v21[1] = 0;
        *((_WORD *)v21 + 4) = 0;
        v22 = (CBasePhonemeTag *)v21;
      }
      else
      {
        v22 = nullptr;
      }
      *(_QWORD *)&v22->m_flStartTime = full;
      *(_DWORD *)&v22->m_nPhonemeCode = v20;
      v23 = v2->m_RunTimePhonemes.m_Size;
      v24 = v2->m_RunTimePhonemes.m_Memory.m_nAllocationCount;
      if ( v23 + 1 > v24 )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_RunTimePhonemes,
          num: v23 - v24 + 1);
      ++v2->m_RunTimePhonemes.m_Size;
      v25 = v2->m_RunTimePhonemes.m_Memory.m_pMemory;
      v26 = v2->m_RunTimePhonemes.m_Size - v23 - 1;
      v2->m_RunTimePhonemes.m_pElements = v25;
      if ( v26 > 0 )
        _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 4 * v26);
      v27 = &v2->m_RunTimePhonemes.m_Memory.m_pMemory[v23];
      if ( v27 != nullptr )
        *v27 = v22;
      free(pMem: nullptr);
      v3 = src;
      ++ib;
    }
    while ( ib < (int)newWordb );
    v2 = this;
  }
  *((_BYTE *)v2 + 74) = *((_BYTE *)v3 + 74);
  *((_BYTE *)v2 + 73) = *((_BYTE *)v3 + 73);
  v2->m_uCheckSum = v3->m_uCheckSum;
  *((_BYTE *)v2 + 72) = *((_BYTE *)v3 + 72);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00411380
// Name: public: void CSentence::Append(float,class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Append(CSentence *this, float starttime, const CSentence *src)
{
  float v3; // xmm0_4
  const CSentence *v4; // edi
  bool v5; // cc
  CSentence *v6; // ebx
  const CWordTag *v7; // esi
  CWordTag *v8; // eax
  CWordTag *v9; // esi
  int m_Size; // edi
  int v11; // eax
  float *p_m_flStartTime; // ecx
  float *v13; // ecx
  float *v14; // ecx
  float *v15; // ecx
  float *v16; // ecx
  int v17; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v20; // eax
  CWordTag **v21; // edi
  const char *m_szText; // ecx
  const char *v23; // eax
  bool v24; // zf
  int v25; // esi
  char *v26; // eax
  CUtlMemory<CAppSystemGroup::Module_t,int> *p_m_EmphasisSamples; // esi
  int v28; // ebx
  CEmphasisSample *v29; // eax
  __int64 v30; // xmm1_8
  int v31; // edx
  CAppSystemGroup::Module_t *v32; // edi
  int v33; // eax
  CAppSystemGroup::Module_t *v34; // ecx
  int v35; // eax
  int v36; // eax
  int v37; // ecx
  char pDest[4096]; // [esp+0h] [ebp-1014h] BYREF
  __int64 v39; // [esp+1000h] [ebp-14h]
  int v40; // [esp+1008h] [ebp-Ch]
  CSentence *v41; // [esp+100Ch] [ebp-8h]
  int v42; // [esp+1010h] [ebp-4h]

  v3 = starttime;
  v4 = src;
  v5 = src->m_Words.m_Size <= 0;
  v6 = this;
  v41 = this;
  v42 = 0;
  if ( !v5 )
  {
    do
    {
      v7 = v4->m_Words.m_Memory.m_pMemory[v42];
      v8 = (CWordTag *)operator new(nSize: 0x2Cu);
      if ( v8 != nullptr )
        v9 = CWordTag::CWordTag(this: v8, from: v7);
      else
        v9 = nullptr;
      v3 = starttime;
      m_Size = v9->m_Phonemes.m_Size;
      v9->m_flStartTime = v9->m_flStartTime + starttime;
      v11 = 0;
      v9->m_flEndTime = v9->m_flEndTime + starttime;
      if ( m_Size >= 4 )
      {
        do
        {
          p_m_flStartTime = &v9->m_Phonemes.m_Memory.m_pMemory[v11]->m_flStartTime;
          *p_m_flStartTime = *p_m_flStartTime + starttime;
          p_m_flStartTime[1] = p_m_flStartTime[1] + starttime;
          v13 = &v9->m_Phonemes.m_Memory.m_pMemory[v11 + 1]->m_flStartTime;
          *v13 = *v13 + starttime;
          v13[1] = v13[1] + starttime;
          v14 = &v9->m_Phonemes.m_Memory.m_pMemory[v11 + 2]->m_flStartTime;
          *v14 = *v14 + starttime;
          v14[1] = v14[1] + starttime;
          v15 = &v9->m_Phonemes.m_Memory.m_pMemory[v11 + 3]->m_flStartTime;
          *v15 = *v15 + starttime;
          v11 += 4;
          v15[1] = v15[1] + starttime;
        }
        while ( v11 < m_Size - 3 );
      }
      for ( ; v11 < m_Size; v16[1] = v16[1] + starttime )
      {
        v16 = &v9->m_Phonemes.m_Memory.m_pMemory[v11]->m_flStartTime;
        *v16 = *v16 + starttime;
        ++v11;
      }
      v17 = v6->m_Words.m_Size;
      m_nAllocationCount = v6->m_Words.m_Memory.m_nAllocationCount;
      if ( v17 + 1 > m_nAllocationCount )
      {
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v6->m_Words,
          num: v17 - m_nAllocationCount + 1);
        v3 = starttime;
      }
      ++v6->m_Words.m_Size;
      m_pMemory = v6->m_Words.m_Memory.m_pMemory;
      v20 = v6->m_Words.m_Size - v17 - 1;
      v6->m_Words.m_pElements = m_pMemory;
      if ( v20 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 4 * v20);
        v3 = starttime;
      }
      v21 = &v6->m_Words.m_Memory.m_pMemory[v17];
      if ( v21 != nullptr )
        *v21 = v9;
      ++v42;
      v4 = src;
    }
    while ( v42 < src->m_Words.m_Size );
  }
  m_szText = v4->m_szText;
  if ( v4->m_szText != nullptr && *m_szText != 0 )
  {
    v23 = v6->m_szText;
    if ( v6->m_szText != nullptr && *v23 != 0 )
      V_snprintf(pDest, maxLen: 4096, pFormat: "%s %s", v23, v4->m_szText);
    else
      V_strncpy(pDest, pSrc: m_szText, maxLen: 4096);
    free(pMem: v6->m_szText);
    v24 = pDest[0] == 0;
    v6->m_szText = nullptr;
    if ( !v24 )
    {
      v25 = _V_strlen(str: pDest) + 1;
      v26 = (char *)operator new(nSize: v25);
      v6->m_szText = v26;
      V_strncpy(pDest: v26, pSrc: pDest, maxLen: v25);
    }
    v3 = starttime;
  }
  if ( v4->m_EmphasisSamples.m_Size > 0 )
  {
    p_m_EmphasisSamples = (CUtlMemory<CAppSystemGroup::Module_t,int> *)&v6->m_EmphasisSamples;
    v28 = 0;
    v42 = v4->m_EmphasisSamples.m_Size;
    do
    {
      v29 = v4->m_EmphasisSamples.m_Memory.m_pMemory;
      v30 = *(_QWORD *)&v29[v28].time;
      v31 = *(_DWORD *)&v29[v28].selected;
      v32 = p_m_EmphasisSamples[1].m_pMemory;
      v33 = p_m_EmphasisSamples->m_nAllocationCount;
      HIDWORD(v39) = HIDWORD(v30);
      v40 = v31;
      *(float *)&v39 = *(float *)&v30 + v3;
      if ( (int)&v32->m_pModule + 1 > v33 )
      {
        CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(this: p_m_EmphasisSamples, num: (int)&v32->m_pModule - v33 + 1);
        v3 = starttime;
      }
      ++p_m_EmphasisSamples[1].m_pMemory;
      v34 = p_m_EmphasisSamples->m_pMemory;
      v35 = (char *)p_m_EmphasisSamples[1].m_pMemory - (char *)v32 - 1;
      p_m_EmphasisSamples[1].m_nAllocationCount = (int)p_m_EmphasisSamples->m_pMemory;
      if ( v35 > 0 )
      {
        _V_memmove(dest: &v34[(int)v32 + 1], src: &v34[(_DWORD)v32], count: 12 * v35);
        v3 = starttime;
      }
      v36 = (int)&p_m_EmphasisSamples->m_pMemory[(_DWORD)v32];
      if ( v36 != 0 )
      {
        v37 = v40;
        *(_QWORD *)v36 = v39;
        *(_DWORD *)(v36 + 8) = v37;
      }
      v4 = src;
      ++v28;
      --v42;
    }
    while ( v42 != 0 );
    v6 = v41;
  }
  *((_BYTE *)v6 + 74) |= *((_BYTE *)v4 + 74);
}

//------------------------------------------------------------------------------
// Address: 0x00411690
// Name: public: void CSentence::CreateEventWordDistribution(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::CreateEventWordDistribution(CSentence *this, const char *pszText, float flSentenceDuration)
{
  int v5; // eax
  float v6; // xmm0_4
  const char *v7; // edi
  char *v8; // esi
  char v9; // bl
  char v10; // bl
  _DWORD *v11; // eax
  CWordTag *v12; // ebx
  unsigned int v13; // kr04_4
  char *v14; // eax
  CSentence *v15; // ecx
  _DWORD *v16; // eax
  CWordTag *v17; // esi
  CSentence *v18; // ecx
  char word[260]; // [esp+8h] [ebp-10Ch] BYREF
  float v20; // [esp+10Ch] [ebp-8h]
  CSentence *v21; // [esp+110h] [ebp-4h]
  float wordStart; // [esp+11Ch] [ebp+8h]

  v21 = this;
  if ( pszText != nullptr )
  {
    v5 = CSentence::CountWords(str: pszText);
    if ( v5 > 0 )
    {
      v6 = (flSentenceDuration - 0.2) / (float)v5;
      wordStart = 0.1;
      CSentence::Reset(this);
      v7 = pszText;
      v8 = word;
      while ( *v7 != 0 )
      {
        v9 = *v7;
        if ( *v7 <= 32 || ispunct(c: v9) != 0 && v9 != 39 )
        {
          v10 = *v7;
          for ( *v8 = 0; v10 != 0; v10 = *++v7 )
          {
            if ( v10 > 32 && (ispunct(c: v10) == 0 || v10 == 39) )
              break;
          }
          if ( strlen(word) != 0 )
          {
            v11 = operator new(nSize: 0x2Cu);
            if ( v11 != nullptr )
            {
              v11[2] = 0;
              v11[3] = 0;
              v11[4] = 0;
              v11[5] = 0;
              v11[6] = 0;
              v11[10] = 0;
              v11[8] = 0;
              v11[9] = 0;
              *v11 = 0;
              v11[1] = 0;
              *((_BYTE *)v11 + 28) = 0;
              v12 = (CWordTag *)v11;
            }
            else
            {
              v12 = nullptr;
            }
            free(pMem: v12->m_pszWord);
            v12->m_pszWord = nullptr;
            if ( word[0] != 0 )
            {
              v13 = strlen(word);
              v14 = (char *)operator new(nSize: v13 + 1);
              v12->m_pszWord = v14;
              V_strncpy(pDest: v14, pSrc: word, maxLen: v13 + 1);
            }
            v15 = v21;
            v12->m_flStartTime = wordStart;
            v20 = wordStart + v6;
            v12->m_flEndTime = wordStart + v6;
            CSentence::AddWordTag(this: v15, tag: v12);
            wordStart = v20;
          }
          v8 = word;
        }
        else
        {
          *v8++ = *v7++;
        }
      }
      *v8 = 0;
      if ( strlen(word) != 0 )
      {
        v16 = operator new(nSize: 0x2Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[2] = 0;
          v16[3] = 0;
          v16[4] = 0;
          v16[5] = 0;
          v16[6] = 0;
          v16[10] = 0;
          v16[8] = 0;
          v16[9] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_BYTE *)v16 + 28) = 0;
          v17 = (CWordTag *)v16;
        }
        CWordTag::SetWord(this: v17, word);
        v18 = v21;
        v17->m_flStartTime = wordStart;
        v17->m_flEndTime = wordStart + v6;
        CSentence::AddWordTag(this: v18, tag: v17);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004118D0
// Name: private: void CSentence::ParseWords(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseWords(CSentence *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // ebx
  float *v3; // eax
  float *v4; // esi
  unsigned int v5; // kr00_4
  char *v6; // eax
  float *v7; // eax
  CSentence *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v12; // eax
  float **v13; // edi
  float *v14; // esi
  __int16 v15; // di
  _DWORD *v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  char *v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  void *v25; // [esp-8h] [ebp-1220h]
  char pString[4096]; // [esp+8h] [ebp-1210h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-210h] BYREF
  char str[256]; // [esp+1108h] [ebp-110h] BYREF
  CSentence *v29; // [esp+1208h] [ebp-10h]
  float v30; // [esp+120Ch] [ebp-Ch]
  float v31; // [esp+1210h] [ebp-8h]
  float *v32; // [esp+1214h] [ebp-4h]

  v2 = buf;
  v29 = this;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_stricmp(s1: pString, s2: "WORD") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v31 = atof(nptr: pString);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v30 = atof(nptr: pString);
    v3 = (float *)operator new(nSize: 0x2Cu);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3[2] = 0.0;
      v3[3] = 0.0;
      v3[4] = 0.0;
      v3[5] = 0.0;
      v3[6] = 0.0;
      v3[8] = 0.0;
      v3[9] = 0.0;
      *v3 = 0.0;
      v3[1] = 0.0;
      v3[10] = 0.0;
      *((_BYTE *)v3 + 28) = 0;
      free(pMem: nullptr);
      v4[10] = 0.0;
      if ( pDest[0] != 0 )
      {
        v5 = strlen(pDest);
        v6 = (char *)operator new(nSize: v5 + 1);
        *((_DWORD *)v4 + 10) = v6;
        V_strncpy(pDest: v6, pSrc: pDest, maxLen: v5 + 1);
      }
      v32 = v4;
    }
    else
    {
      v32 = nullptr;
    }
    v7 = v32;
    v8 = v29;
    *v32 = v31;
    v7[1] = v30;
    m_Size = v8->m_Words.m_Size;
    m_nAllocationCount = v8->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v8->m_Words.m_Size;
    m_pMemory = v8->m_Words.m_Memory.m_pMemory;
    v12 = v8->m_Words.m_Size - m_Size - 1;
    v8->m_Words.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = (float **)&v8->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v32;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      v14 = v32;
      do
      {
        v15 = atoi(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        V_strncpy(pDest: str, pSrc: pString, maxLen: 256);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v30 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v31 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        atof(nptr: pString);
        v16 = operator new(nSize: 0x1Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[6] = 0;
          v16[4] = 0;
          v16[5] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_WORD *)v16 + 4) = 0;
          *((_BYTE *)v16 + 12) = 0;
          v17 = v16;
        }
        v25 = (void *)v17[6];
        *((_WORD *)v17 + 4) = v15;
        free(pMem: v25);
        v17[6] = 0;
        if ( str[0] != 0 )
        {
          v18 = _V_strlen(str) + 1;
          v19 = (char *)operator new(nSize: v18);
          v17[6] = v19;
          V_strncpy(pDest: v19, pSrc: str, maxLen: v18);
        }
        *(float *)v17 = v30;
        *((float *)v17 + 1) = v31;
        v20 = *((_DWORD *)v14 + 5);
        v21 = *((_DWORD *)v14 + 3);
        if ( v20 + 1 > v21 )
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(v14 + 2),
            num: v20 - v21 + 1);
        ++*((_DWORD *)v14 + 5);
        v22 = *((_DWORD *)v14 + 2);
        v23 = *((_DWORD *)v14 + 5) - v20 - 1;
        *((_DWORD *)v14 + 6) = v22;
        if ( v23 > 0 )
          _V_memmove(dest: (void *)(v22 + 4 * v20 + 4), src: (const void *)(v22 + 4 * v20), count: 4 * v23);
        v24 = (_DWORD *)(*((_DWORD *)v14 + 2) + 4 * v20);
        if ( v24 != nullptr )
          *v24 = v17;
        CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
        v2 = buf;
      }
      while ( _V_stricmp(s1: pString, s2: "}") != 0 );
    }
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411CF0
// Name: private: void CSentence::ParseDataVersionOnePointZero(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseDataVersionOnePointZero(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1100h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( strlen(pString) != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    if ( _V_stricmp(s1: pDest, s2: "PLAINTEXT") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "WORDS") != 0 )
      {
        if ( _V_stricmp(s1: pDest, s2: "EMPHASIS") != 0 )
        {
          if ( _V_stricmp(s1: pDest, s2: "CLOSECAPTION") != 0 )
          {
            if ( _V_stricmp(s1: pDest, s2: "OPTIONS") == 0 )
              CSentence::ParseOptions(this, buf);
          }
          else
          {
            CSentence::ParseCloseCaption(this, buf);
          }
        }
        else
        {
          CSentence::ParseEmphasis(this, buf);
        }
      }
      else
      {
        CSentence::ParseWords(this, buf);
      }
    }
    else
    {
      CSentence::ParsePlaintext(this, buf);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411E60
// Name: public: void CSentence::InitFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1000h] BYREF

  CSentence::Reset(this);
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  if ( _V_stricmp(s1: pString, s2: "VERSION") == 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( atof(nptr: pString) == 1.0 )
    {
      CSentence::ParseDataVersionOnePointZero(this, buf);
      *((_BYTE *)this + 72) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411EF0
// Name: public: void CSentence::InitFromDataChunk(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromDataChunk(CSentence *this, void *data, int size)
{
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::EnsureCapacity(this: &buf, num: size);
  CUtlBuffer::Put(this: &buf, pMem: data, size);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: size);
  CSentence::InitFromBuffer(this, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

} // namespace hlfaceposer

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x00417CF0
// Name: public: static char const __near * CSentence::NameForLanguage(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSentence::NameForLanguage(unsigned int language)
{
  if ( language > 0xB )
    return "unknown_language";
  else
    return g_CCLanguageLookup[language].name;
}

//------------------------------------------------------------------------------
// Address: 0x00417D10
// Name: public: static int CSentence::LanguageForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSentence::LanguageForName(const char *name)
{
  int v1; // edi
  const char **p_name; // esi

  v1 = 0;
  p_name = &g_CCLanguageLookup[0].name;
  while ( _V_stricmp(s1: *p_name, s2: name) != 0 )
  {
    p_name = (const char **)((char *)p_name + 11);
    ++v1;
    if ( (int)p_name >= (int)&vec2_invalid_11.y )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00417D50
// Name: public: void CSentence::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SetText(CSentence *this, const char *text)
{
  int v3; // esi
  char *v4; // eax

  free(pMem: this->m_szText);
  this->m_szText = nullptr;
  if ( text != nullptr && *text != 0 )
  {
    v3 = _V_strlen(str: text) + 1;
    v4 = (char *)operator new(nSize: v3);
    this->m_szText = v4;
    V_strncpy(pDest: v4, pSrc: text, maxLen: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417DA0
// Name: public: char const __near * CSentence::GetText(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSentence::GetText(CSentence *this)
{
  char *result; // eax

  result = this->m_szText;
  if ( this->m_szText == nullptr )
    return (char *)setName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417DB0
// Name: public: void CSentence::SetDataCheckSum(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SetDataCheckSum(CSentence *this, unsigned int chk)
{
  *((_BYTE *)this + 73) = 1;
  this->m_uCheckSum = chk;
}

//------------------------------------------------------------------------------
// Address: 0x00417DD0
// Name: public: unsigned int CSentence::GetDataCheckSum(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSentence::GetDataCheckSum(CSentence *this)
{
  return this->m_uCheckSum;
}

//------------------------------------------------------------------------------
// Address: 0x00417DE0
// Name: private: void CSentence::ParsePlaintext(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParsePlaintext(CSentence *this, CUtlBuffer *buf)
{
  bool v3; // zf
  int v4; // esi
  char *v5; // eax
  char pString[4096]; // [esp+8h] [ebp-2000h] BYREF
  char pDest[4096]; // [esp+1008h] [ebp-1000h] BYREF

  pDest[0] = 0;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncat(pDest, pSrc: pString, destBufferSize: 0x1000u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: " ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
  free(pMem: this->m_szText);
  v3 = pDest[0] == 0;
  this->m_szText = nullptr;
  if ( !v3 )
  {
    v4 = _V_strlen(str: pDest) + 1;
    v5 = (char *)operator new(nSize: v4);
    this->m_szText = v5;
    V_strncpy(pDest: v5, pSrc: pDest, maxLen: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417ED0
// Name: private: void CSentence::ParseOptions(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseOptions(CSentence *this, CUtlBuffer *buf)
{
  unsigned int v3; // eax
  char pString[4096]; // [esp+8h] [ebp-1200h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-200h] BYREF
  char nptr[256]; // [esp+1108h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_strlen(str: pString) == 0 )
      break;
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    if ( _V_stricmp(s1: pDest, s2: "voice_duck") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "checksum") == 0 )
      {
        v3 = atoi(nptr);
        *((_BYTE *)this + 73) = 1;
        this->m_uCheckSum = v3;
      }
    }
    else
    {
      *((_BYTE *)this + 74) = atoi(nptr) != 0;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418000
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418080
// Name: public: unsigned int CWordTag::ComputeDataCheckSum(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWordTag::ComputeDataCheckSum(CWordTag *this)
{
  int v2; // eax
  int v3; // edi
  CPhonemeTag *v4; // esi
  int v5; // eax
  int c; // [esp+8h] [ebp-1Ch]
  unsigned int phonemeCheckSum; // [esp+Ch] [ebp-18h] BYREF
  float m_flEndTime; // [esp+10h] [ebp-14h] BYREF
  float m_flStartTime; // [esp+14h] [ebp-10h] BYREF
  int pBuffer; // [esp+18h] [ebp-Ch] BYREF
  unsigned int crc; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int pulCRC; // [esp+20h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  if ( this->m_pszWord != nullptr )
  {
    v2 = _V_strlen(str: this->m_pszWord);
    CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: this->m_pszWord, nBuffer: v2);
  }
  v3 = 0;
  c = this->m_Phonemes.m_Size;
  if ( c > 0 )
  {
    do
    {
      v4 = this->m_Phonemes.m_Memory.m_pMemory[v3];
      CRC32_Init(&pulCRC);
      v5 = _V_strlen(str: v4->m_szPhoneme);
      CRC32_ProcessBuffer(&pulCRC, pBuffer: v4->m_szPhoneme, nBuffer: v5);
      pBuffer = v4->m_nPhonemeCode;
      CRC32_ProcessBuffer(&pulCRC, &pBuffer, nBuffer: 4);
      m_flStartTime = v4->m_flStartTime;
      m_flEndTime = v4->m_flEndTime;
      CRC32_ProcessBuffer(&pulCRC, pBuffer: &m_flStartTime, nBuffer: 4);
      CRC32_ProcessBuffer(&pulCRC, pBuffer: &m_flEndTime, nBuffer: 4);
      CRC32_Final(&pulCRC);
      phonemeCheckSum = pulCRC;
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &phonemeCheckSum, nBuffer: 4);
      ++v3;
    }
    while ( v3 < c );
  }
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: this, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->m_flEndTime, nBuffer: 4);
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x00418190
// Name: public: void CSentence::SaveToBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SaveToBuffer(CSentence *this, CUtlBuffer *buf)
{
  CSentence *v3; // edi
  const char *m_szText; // eax
  CWordTag *v5; // edi
  const char *m_pszWord; // eax
  int j; // ebx
  CPhonemeTag *v8; // eax
  const char *m_szPhoneme; // ecx
  int v10; // ebx
  int i; // [esp+28h] [ebp+8h]
  int ia; // [esp+28h] [ebp+8h]

  v3 = this;
  CUtlBuffer::Printf(this: buf, pFmt: "VERSION 1.0\n");
  CUtlBuffer::Printf(this: buf, pFmt: "PLAINTEXT\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_szText = v3->m_szText;
  if ( v3->m_szText == nullptr )
    m_szText = setName;
  CUtlBuffer::Printf(this: buf, pFmt: (const char *)&stru_444A30, m_szText);
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "WORDS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  i = 0;
  if ( v3->m_Words.m_Size > 0 )
  {
    do
    {
      v5 = v3->m_Words.m_Memory.m_pMemory[i];
      m_pszWord = v5->m_pszWord;
      if ( m_pszWord == nullptr )
        m_pszWord = setName;
      CUtlBuffer::Printf(this: buf, pFmt: "WORD %s %.3f %.3f\n", m_pszWord, v5->m_flStartTime, v5->m_flEndTime);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      for ( j = 0; j < v5->m_Phonemes.m_Size; ++j )
      {
        v8 = v5->m_Phonemes.m_Memory.m_pMemory[j];
        m_szPhoneme = v8->m_szPhoneme;
        if ( m_szPhoneme == nullptr )
          m_szPhoneme = setName;
        CUtlBuffer::Printf(
          this: buf,
          pFmt: "%i %s %.3f %.3f 1\n",
          v8->m_nPhonemeCode,
          m_szPhoneme,
          v8->m_flStartTime,
          v8->m_flEndTime);
      }
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      ++i;
      v3 = this;
    }
    while ( i < this->m_Words.m_Size );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "EMPHASIS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  if ( v3->m_EmphasisSamples.m_Size > 0 )
  {
    v10 = 0;
    ia = v3->m_EmphasisSamples.m_Size;
    do
    {
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "%f %f\n",
        v3->m_EmphasisSamples.m_Memory.m_pMemory[v10].time,
        v3->m_EmphasisSamples.m_Memory.m_pMemory[v10].value);
      ++v10;
      --ia;
    }
    while ( ia != 0 );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "OPTIONS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  CUtlBuffer::Printf(this: buf, pFmt: "voice_duck %d\n", *((_BYTE *)v3 + 74) != 0);
  if ( *((_BYTE *)v3 + 73) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "checksum %d\n", v3->m_uCheckSum);
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x004183B0
// Name: public: unsigned int CSentence::ComputeDataCheckSum(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSentence::ComputeDataCheckSum(CSentence *this)
{
  char *m_szText; // ecx
  char *v3; // edi
  int v4; // eax
  int m_Size; // ebx
  int i; // edi
  int v7; // ebx
  int v8; // edi
  unsigned int wordCheckSum; // [esp+Ch] [ebp-8h] BYREF
  unsigned int crc; // [esp+10h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  m_szText = this->m_szText;
  if ( this->m_szText != nullptr )
  {
    v3 = this->m_szText;
  }
  else
  {
    m_szText = (char *)setName;
    v3 = (char *)setName;
  }
  v4 = _V_strlen(str: m_szText);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: v3, nBuffer: v4);
  m_Size = this->m_Words.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    wordCheckSum = CWordTag::ComputeDataCheckSum(this: this->m_Words.m_Memory.m_pMemory[i]);
    CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &wordCheckSum, nBuffer: 4);
  }
  v7 = this->m_EmphasisSamples.m_Size;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->m_EmphasisSamples.m_Memory.m_pMemory[v8], nBuffer: 4);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &this->m_EmphasisSamples.m_Memory.m_pMemory[v8++].value, nBuffer: 4);
      --v7;
    }
    while ( v7 != 0 );
  }
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x00418480
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004184C0
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418500
// Name: protected: void CUtlBuffer::PutTypeBin<unsigned short>(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<unsigned short>(CUtlBuffer *this, unsigned __int16 src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 2) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned short>(
        this: &this->m_Byteswap,
        outputBuffer: &this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: (unsigned __int8 *)&src,
        count: 1);
    else
      *(_WORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 2;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418570
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004185C0
// Name: private: void CSentence::ParseCloseCaption(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseCloseCaption(CSentence *this, CUtlBuffer *buf)
{
  int v2; // edi
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-2020h] BYREF
  char pString[4096]; // [esp+1008h] [ebp-1020h] BYREF
  char pDest[32]; // [esp+2008h] [ebp-20h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    while ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      if ( _V_stricmp(s1: pString, s2: "PHRASE") != 0 )
        break;
      memset(dst, value: 0, count: sizeof(dst));
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      V_strncpy(pDest, pSrc: pString, maxLen: 32);
      if ( _V_stricmp(s1: pDest, s2: "unicode") != 0 )
        _V_stricmp(s1: pDest, s2: "char");
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      v2 = atoi(nptr: pString);
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::Get(this: buf, pMem: dst, size: v2);
      dst[v2] = 0;
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004187B0
// Name: public: void CSentence::ClearRuntimePhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ClearRuntimePhonemes(CSentence *this)
{
  for ( ; this->m_RunTimePhonemes.m_Size > 0; --this->m_RunTimePhonemes.m_Size )
  {
    free(pMem: *(void **)this->m_RunTimePhonemes.m_Memory.m_pMemory);
    if ( this->m_RunTimePhonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_RunTimePhonemes.m_Memory.m_pMemory,
        src: this->m_RunTimePhonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_RunTimePhonemes.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418800
// Name: public: CWordTag::~CWordTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::~CWordTag(CWordTag *this)
{
  CPhonemeTag *v2; // edi

  free(pMem: this->m_pszWord);
  for ( ; this->m_Phonemes.m_Size > 0; --this->m_Phonemes.m_Size )
  {
    v2 = *this->m_Phonemes.m_Memory.m_pMemory;
    if ( v2 != nullptr )
    {
      free(pMem: v2->m_szPhoneme);
      free(pMem: v2);
    }
    if ( this->m_Phonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Phonemes.m_Memory.m_pMemory,
        src: this->m_Phonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Phonemes.m_Size - 1));
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Phonemes);
}

//------------------------------------------------------------------------------
// Address: 0x00418870
// Name: public: CSentence::CSentence(void)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::CSentence(CSentence *this)
{
  this->m_Words.m_Memory.m_pMemory = nullptr;
  this->m_Words.m_Memory.m_nAllocationCount = 0;
  this->m_Words.m_Memory.m_nGrowSize = 0;
  this->m_Words.m_Size = 0;
  this->m_Words.m_pElements = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_pMemory = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_nAllocationCount = 0;
  this->m_RunTimePhonemes.m_Memory.m_nGrowSize = 0;
  this->m_RunTimePhonemes.m_Size = 0;
  this->m_RunTimePhonemes.m_pElements = nullptr;
  this->m_EmphasisSamples.m_Memory.m_pMemory = nullptr;
  this->m_EmphasisSamples.m_Memory.m_nAllocationCount = 0;
  this->m_EmphasisSamples.m_Memory.m_nGrowSize = 0;
  this->m_EmphasisSamples.m_Size = 0;
  this->m_EmphasisSamples.m_pElements = nullptr;
  this->m_nResetWordBase = 0;
  this->m_szText = nullptr;
  this->m_uCheckSum = 0;
  *(_WORD *)((char *)this + 73) = 0;
  *((_BYTE *)this + 72) = 0;
  *((_BYTE *)this + 75) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004188C0
// Name: public: void CSentence::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Reset(CSentence *this)
{
  bool v2; // cc
  CWordTag **m_pMemory; // eax
  CWordTag *v4; // edi

  v2 = this->m_Words.m_Size <= 0;
  this->m_nResetWordBase = 0;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_Words.m_Memory.m_pMemory;
      v4 = *m_pMemory;
      if ( *m_pMemory != nullptr )
      {
        CWordTag::~CWordTag(this: *m_pMemory);
        free(pMem: v4);
      }
      if ( this->m_Words.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Words.m_Memory.m_pMemory,
          src: this->m_Words.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Words.m_Size - 1));
      --this->m_Words.m_Size;
    }
    while ( this->m_Words.m_Size > 0 );
  }
  this->m_EmphasisSamples.m_Size = 0;
  CSentence::ClearRuntimePhonemes(this);
}

//------------------------------------------------------------------------------
// Address: 0x00418930
// Name: public: CWordTag::CWordTag(class CWordTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this, const CWordTag *from)
{
  CWordTag *v2; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Phonemes; // edi
  char *m_pszWord; // ebx
  unsigned int v5; // kr00_4
  char *v6; // eax
  unsigned int m_uiEndByte; // ecx
  int v8; // ebx
  CPhonemeTag *v9; // eax
  CPhonemeTag *v10; // esi
  CPhonemeTag *v11; // eoff
  unsigned int v12; // ecx
  char *m_szPhoneme; // eax
  const char *v14; // ebx
  int v15; // ebx
  char *v16; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v19; // ecx
  int v20; // eax
  CPhonemeTag **v21; // esi
  int p; // [esp+Ch] [ebp-Ch]
  const char *newPhoneme; // [esp+14h] [ebp-4h]
  CPhonemeTag *newPhonemea; // [esp+14h] [ebp-4h]

  v2 = this;
  p_m_Phonemes = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Phonemes;
  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_pszWord = nullptr;
  m_pszWord = from->m_pszWord;
  free(pMem: nullptr);
  v2->m_pszWord = nullptr;
  if ( m_pszWord != nullptr && *m_pszWord != 0 )
  {
    v5 = strlen(m_pszWord);
    v6 = (char *)operator new(nSize: v5 + 1);
    this->m_pszWord = v6;
    V_strncpy(pDest: v6, pSrc: m_pszWord, maxLen: v5 + 1);
    v2 = this;
  }
  m_uiEndByte = from->m_uiEndByte;
  v2->m_uiStartByte = from->m_uiStartByte;
  v2->m_uiEndByte = m_uiEndByte;
  v2->m_flStartTime = from->m_flStartTime;
  v8 = 0;
  p = 0;
  v2->m_flEndTime = from->m_flEndTime;
  v2->m_bSelected = from->m_bSelected;
  if ( from->m_Phonemes.m_Size <= 0 )
    return v2;
  do
  {
    v9 = (CPhonemeTag *)operator new(nSize: 0x1Cu);
    v10 = v9;
    if ( v9 != nullptr )
    {
      v11 = from->m_Phonemes.m_Memory.m_pMemory[v8];
      *(_QWORD *)&v9->m_flStartTime = *(_QWORD *)&v11->m_flStartTime;
      *(_DWORD *)&v9->m_nPhonemeCode = *(_DWORD *)&v11->m_nPhonemeCode;
      v12 = v11->m_uiEndByte;
      v9->m_uiStartByte = v11->m_uiStartByte;
      v9->m_uiEndByte = v12;
      v9->m_bSelected = v11->m_bSelected;
      v9->m_szPhoneme = nullptr;
      m_szPhoneme = v11->m_szPhoneme;
      if ( m_szPhoneme != nullptr )
      {
        v14 = m_szPhoneme;
        newPhoneme = m_szPhoneme;
      }
      else
      {
        newPhoneme = setName;
        v14 = setName;
      }
      free(pMem: nullptr);
      v10->m_szPhoneme = nullptr;
      if ( v14 != nullptr && *v14 != 0 )
      {
        v15 = _V_strlen(str: v14) + 1;
        v16 = (char *)operator new(nSize: v15);
        v10->m_szPhoneme = v16;
        V_strncpy(pDest: v16, pSrc: newPhoneme, maxLen: v15);
      }
      v8 = p;
      newPhonemea = v10;
    }
    else
    {
      newPhonemea = nullptr;
    }
    m_pMemory = p_m_Phonemes[1].m_pMemory;
    m_nAllocationCount = p_m_Phonemes->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Phonemes, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_Phonemes[1].m_pMemory;
    v19 = p_m_Phonemes->m_pMemory;
    v20 = (char *)p_m_Phonemes[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Phonemes[1].m_nAllocationCount = (int)p_m_Phonemes->m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[(_DWORD)m_pMemory + 1], src: &v19[(_DWORD)m_pMemory], count: 4 * v20);
    v21 = (CPhonemeTag **)&p_m_Phonemes->m_pMemory[(_DWORD)m_pMemory];
    if ( v21 != nullptr )
      *v21 = newPhonemea;
    p = ++v8;
  }
  while ( v8 < from->m_Phonemes.m_Size );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00418AF0
// Name: public: CSentence::~CSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::~CSentence(CSentence *this)
{
  CSentence::Reset(this);
  free(pMem: this->m_szText);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_EmphasisSamples);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_RunTimePhonemes);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Words);
}

//------------------------------------------------------------------------------
// Address: 0x00418B20
// Name: private: void CSentence::ParseEmphasis(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseEmphasis(CSentence *this, CUtlBuffer *buf)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v6; // eax
  CEmphasisSample *v7; // eax
  int v8; // ecx
  char pString[4096]; // [esp+8h] [ebp-120Ch] BYREF
  char nptr[256]; // [esp+1008h] [ebp-20Ch] BYREF
  char pDest[256]; // [esp+1108h] [ebp-10Ch] BYREF
  __int64 v12; // [esp+1208h] [ebp-Ch]
  int v13; // [esp+1210h] [ebp-4h]

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    LOBYTE(v13) = 0;
    *(float *)&v12 = atof(nptr: pDest);
    *((float *)&v12 + 1) = atof(nptr);
    m_Size = this->m_EmphasisSamples.m_Size;
    m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
        this: (CUtlMemory<CAppSystemGroup::Module_t,int> *)&this->m_EmphasisSamples,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EmphasisSamples.m_Size;
    m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
    v6 = this->m_EmphasisSamples.m_Size - m_Size - 1;
    this->m_EmphasisSamples.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v6);
    v7 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
    {
      v8 = v13;
      *(_QWORD *)&v7->time = v12;
      *(_DWORD *)&v7->selected = v8;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418C70
// Name: public: class CSentence __near & CSentence::operator=(class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::operator=(CSentence *this, const CSentence *src)
{
  CSentence *v2; // esi
  const CSentence *v3; // ebx
  const CWordTag *v4; // edi
  CWordTag *v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v9; // eax
  CWordTag **v10; // eax
  char *m_szText; // edi
  int v12; // esi
  char *v13; // eax
  int v14; // edi
  int v15; // eax
  CEmphasisSample *v16; // ecx
  int v17; // eax
  CEmphasisSample *v18; // eax
  CBasePhonemeTag *v19; // eax
  int v20; // edi
  _DWORD *v21; // eax
  CBasePhonemeTag *v22; // ebx
  int v23; // edi
  int v24; // eax
  CBasePhonemeTag **v25; // ecx
  int v26; // eax
  CBasePhonemeTag **v27; // eax
  __int64 full; // [esp+Ch] [ebp-34h]
  CWordTag *newWord; // [esp+34h] [ebp-Ch]
  CWordTag *newWorda; // [esp+34h] [ebp-Ch]
  CWordTag *newWordb; // [esp+34h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-4h]
  int ia; // [esp+3Ch] [ebp-4h]
  int ib; // [esp+3Ch] [ebp-4h]
  CEmphasisSample s; // 0:^3C.12

  v2 = this;
  CSentence::Reset(this);
  v3 = src;
  for ( i = 0; i < src->m_Words.m_Size; ++i )
  {
    v4 = src->m_Words.m_Memory.m_pMemory[i];
    v5 = (CWordTag *)operator new(nSize: 0x2Cu);
    if ( v5 != nullptr )
      newWord = CWordTag::CWordTag(this: v5, from: v4);
    else
      newWord = nullptr;
    m_Size = v2->m_Words.m_Size;
    m_nAllocationCount = v2->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_Words.m_Size;
    m_pMemory = v2->m_Words.m_Memory.m_pMemory;
    v9 = v2->m_Words.m_Size - m_Size - 1;
    v2->m_Words.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &v2->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = newWord;
  }
  m_szText = src->m_szText;
  if ( src->m_szText == nullptr )
    m_szText = (char *)setName;
  free(pMem: v2->m_szText);
  v2->m_szText = nullptr;
  if ( m_szText != nullptr && *m_szText != 0 )
  {
    v12 = _V_strlen(str: m_szText) + 1;
    v13 = (char *)operator new(nSize: v12);
    this->m_szText = v13;
    V_strncpy(pDest: v13, pSrc: m_szText, maxLen: v12);
    v2 = this;
  }
  v2->m_nResetWordBase = src->m_nResetWordBase;
  if ( src->m_EmphasisSamples.m_Size > 0 )
  {
    ia = 0;
    newWorda = (CWordTag *)src->m_EmphasisSamples.m_Size;
    do
    {
      v14 = v2->m_EmphasisSamples.m_Size;
      s = src->m_EmphasisSamples.m_Memory.m_pMemory[ia];
      v15 = v2->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      if ( v14 + 1 > v15 )
        CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
          this: (CUtlMemory<CAppSystemGroup::Module_t,int> *)&v2->m_EmphasisSamples,
          num: v14 - v15 + 1);
      ++v2->m_EmphasisSamples.m_Size;
      v16 = v2->m_EmphasisSamples.m_Memory.m_pMemory;
      v17 = v2->m_EmphasisSamples.m_Size - v14 - 1;
      v2->m_EmphasisSamples.m_pElements = v16;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 12 * v17);
      v18 = &v2->m_EmphasisSamples.m_Memory.m_pMemory[v14];
      if ( v18 != nullptr )
        *v18 = s;
      ++ia;
      newWorda = (CWordTag *)((char *)newWorda - 1);
    }
    while ( newWorda != nullptr );
    v2 = this;
  }
  *((_BYTE *)v2 + 75) = *((_BYTE *)src + 75);
  newWordb = (CWordTag *)src->m_RunTimePhonemes.m_Size;
  ib = 0;
  if ( (int)newWordb > 0 )
  {
    do
    {
      v19 = v3->m_RunTimePhonemes.m_Memory.m_pMemory[ib];
      v20 = *(_DWORD *)&v19->m_nPhonemeCode;
      full = *(_QWORD *)&v19->m_flStartTime;
      v21 = operator new(nSize: 0xCu);
      if ( v21 != nullptr )
      {
        *v21 = 0;
        v21[1] = 0;
        *((_WORD *)v21 + 4) = 0;
        v22 = (CBasePhonemeTag *)v21;
      }
      else
      {
        v22 = nullptr;
      }
      *(_QWORD *)&v22->m_flStartTime = full;
      *(_DWORD *)&v22->m_nPhonemeCode = v20;
      v23 = v2->m_RunTimePhonemes.m_Size;
      v24 = v2->m_RunTimePhonemes.m_Memory.m_nAllocationCount;
      if ( v23 + 1 > v24 )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_RunTimePhonemes,
          num: v23 - v24 + 1);
      ++v2->m_RunTimePhonemes.m_Size;
      v25 = v2->m_RunTimePhonemes.m_Memory.m_pMemory;
      v26 = v2->m_RunTimePhonemes.m_Size - v23 - 1;
      v2->m_RunTimePhonemes.m_pElements = v25;
      if ( v26 > 0 )
        _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 4 * v26);
      v27 = &v2->m_RunTimePhonemes.m_Memory.m_pMemory[v23];
      if ( v27 != nullptr )
        *v27 = v22;
      free(pMem: nullptr);
      v3 = src;
      ++ib;
    }
    while ( ib < (int)newWordb );
    v2 = this;
  }
  *((_BYTE *)v2 + 74) = *((_BYTE *)v3 + 74);
  *((_BYTE *)v2 + 73) = *((_BYTE *)v3 + 73);
  v2->m_uCheckSum = v3->m_uCheckSum;
  *((_BYTE *)v2 + 72) = *((_BYTE *)v3 + 72);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00418F10
// Name: public: void CSentence::Append(float,class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Append(CSentence *this, float starttime, const CSentence *src)
{
  float v3; // xmm0_4
  const CSentence *v4; // edi
  bool v5; // cc
  CSentence *v6; // ebx
  const CWordTag *v7; // esi
  CWordTag *v8; // eax
  CWordTag *v9; // esi
  int m_Size; // edi
  int v11; // eax
  float *p_m_flStartTime; // ecx
  float *v13; // ecx
  float *v14; // ecx
  float *v15; // ecx
  float *v16; // ecx
  int v17; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v20; // eax
  CWordTag **v21; // edi
  const char *m_szText; // ecx
  const char *v23; // eax
  bool v24; // zf
  int v25; // esi
  char *v26; // eax
  CUtlMemory<CAppSystemGroup::Module_t,int> *p_m_EmphasisSamples; // esi
  int v28; // ebx
  CEmphasisSample *v29; // eax
  __int64 v30; // xmm1_8
  int v31; // edx
  CAppSystemGroup::Module_t *v32; // edi
  int v33; // eax
  CAppSystemGroup::Module_t *v34; // ecx
  int v35; // eax
  int v36; // eax
  int v37; // ecx
  char pDest[4096]; // [esp+0h] [ebp-1014h] BYREF
  __int64 v39; // [esp+1000h] [ebp-14h]
  int v40; // [esp+1008h] [ebp-Ch]
  CSentence *v41; // [esp+100Ch] [ebp-8h]
  int v42; // [esp+1010h] [ebp-4h]

  v3 = starttime;
  v4 = src;
  v5 = src->m_Words.m_Size <= 0;
  v6 = this;
  v41 = this;
  v42 = 0;
  if ( !v5 )
  {
    do
    {
      v7 = v4->m_Words.m_Memory.m_pMemory[v42];
      v8 = (CWordTag *)operator new(nSize: 0x2Cu);
      if ( v8 != nullptr )
        v9 = CWordTag::CWordTag(this: v8, from: v7);
      else
        v9 = nullptr;
      v3 = starttime;
      m_Size = v9->m_Phonemes.m_Size;
      v9->m_flStartTime = v9->m_flStartTime + starttime;
      v11 = 0;
      v9->m_flEndTime = v9->m_flEndTime + starttime;
      if ( m_Size >= 4 )
      {
        do
        {
          p_m_flStartTime = &v9->m_Phonemes.m_Memory.m_pMemory[v11]->m_flStartTime;
          *p_m_flStartTime = *p_m_flStartTime + starttime;
          p_m_flStartTime[1] = p_m_flStartTime[1] + starttime;
          v13 = &v9->m_Phonemes.m_Memory.m_pMemory[v11 + 1]->m_flStartTime;
          *v13 = *v13 + starttime;
          v13[1] = v13[1] + starttime;
          v14 = &v9->m_Phonemes.m_Memory.m_pMemory[v11 + 2]->m_flStartTime;
          *v14 = *v14 + starttime;
          v14[1] = v14[1] + starttime;
          v15 = &v9->m_Phonemes.m_Memory.m_pMemory[v11 + 3]->m_flStartTime;
          *v15 = *v15 + starttime;
          v11 += 4;
          v15[1] = v15[1] + starttime;
        }
        while ( v11 < m_Size - 3 );
      }
      for ( ; v11 < m_Size; v16[1] = v16[1] + starttime )
      {
        v16 = &v9->m_Phonemes.m_Memory.m_pMemory[v11]->m_flStartTime;
        *v16 = *v16 + starttime;
        ++v11;
      }
      v17 = v6->m_Words.m_Size;
      m_nAllocationCount = v6->m_Words.m_Memory.m_nAllocationCount;
      if ( v17 + 1 > m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v6->m_Words,
          num: v17 - m_nAllocationCount + 1);
        v3 = starttime;
      }
      ++v6->m_Words.m_Size;
      m_pMemory = v6->m_Words.m_Memory.m_pMemory;
      v20 = v6->m_Words.m_Size - v17 - 1;
      v6->m_Words.m_pElements = m_pMemory;
      if ( v20 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 4 * v20);
        v3 = starttime;
      }
      v21 = &v6->m_Words.m_Memory.m_pMemory[v17];
      if ( v21 != nullptr )
        *v21 = v9;
      ++v42;
      v4 = src;
    }
    while ( v42 < src->m_Words.m_Size );
  }
  m_szText = v4->m_szText;
  if ( v4->m_szText != nullptr && *m_szText != 0 )
  {
    v23 = v6->m_szText;
    if ( v6->m_szText != nullptr && *v23 != 0 )
      V_snprintf(pDest, maxLen: 4096, pFormat: "%s %s", v23, v4->m_szText);
    else
      V_strncpy(pDest, pSrc: m_szText, maxLen: 4096);
    free(pMem: v6->m_szText);
    v24 = pDest[0] == 0;
    v6->m_szText = nullptr;
    if ( !v24 )
    {
      v25 = _V_strlen(str: pDest) + 1;
      v26 = (char *)operator new(nSize: v25);
      v6->m_szText = v26;
      V_strncpy(pDest: v26, pSrc: pDest, maxLen: v25);
    }
    v3 = starttime;
  }
  if ( v4->m_EmphasisSamples.m_Size > 0 )
  {
    p_m_EmphasisSamples = (CUtlMemory<CAppSystemGroup::Module_t,int> *)&v6->m_EmphasisSamples;
    v28 = 0;
    v42 = v4->m_EmphasisSamples.m_Size;
    do
    {
      v29 = v4->m_EmphasisSamples.m_Memory.m_pMemory;
      v30 = *(_QWORD *)&v29[v28].time;
      v31 = *(_DWORD *)&v29[v28].selected;
      v32 = p_m_EmphasisSamples[1].m_pMemory;
      v33 = p_m_EmphasisSamples->m_nAllocationCount;
      HIDWORD(v39) = HIDWORD(v30);
      v40 = v31;
      *(float *)&v39 = *(float *)&v30 + v3;
      if ( (int)&v32->m_pModule + 1 > v33 )
      {
        CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(this: p_m_EmphasisSamples, num: (int)&v32->m_pModule - v33 + 1);
        v3 = starttime;
      }
      ++p_m_EmphasisSamples[1].m_pMemory;
      v34 = p_m_EmphasisSamples->m_pMemory;
      v35 = (char *)p_m_EmphasisSamples[1].m_pMemory - (char *)v32 - 1;
      p_m_EmphasisSamples[1].m_nAllocationCount = (int)p_m_EmphasisSamples->m_pMemory;
      if ( v35 > 0 )
      {
        _V_memmove(dest: &v34[(int)v32 + 1], src: &v34[(_DWORD)v32], count: 12 * v35);
        v3 = starttime;
      }
      v36 = (int)&p_m_EmphasisSamples->m_pMemory[(_DWORD)v32];
      if ( v36 != 0 )
      {
        v37 = v40;
        *(_QWORD *)v36 = v39;
        *(_DWORD *)(v36 + 8) = v37;
      }
      v4 = src;
      ++v28;
      --v42;
    }
    while ( v42 != 0 );
    v6 = v41;
  }
  *((_BYTE *)v6 + 74) |= *((_BYTE *)v4 + 74);
}

//------------------------------------------------------------------------------
// Address: 0x00419220
// Name: private: void CSentence::ParseWords(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseWords(CSentence *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // ebx
  float *v3; // eax
  float *v4; // esi
  unsigned int v5; // kr00_4
  char *v6; // eax
  float *v7; // eax
  CSentence *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v12; // eax
  float **v13; // edi
  float *v14; // esi
  __int16 v15; // di
  _DWORD *v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  char *v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  void *v25; // [esp-8h] [ebp-1220h]
  char pString[4096]; // [esp+8h] [ebp-1210h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-210h] BYREF
  char str[256]; // [esp+1108h] [ebp-110h] BYREF
  CSentence *v29; // [esp+1208h] [ebp-10h]
  float v30; // [esp+120Ch] [ebp-Ch]
  float v31; // [esp+1210h] [ebp-8h]
  float *v32; // [esp+1214h] [ebp-4h]

  v2 = buf;
  v29 = this;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_stricmp(s1: pString, s2: "WORD") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v31 = atof(nptr: pString);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v30 = atof(nptr: pString);
    v3 = (float *)operator new(nSize: 0x2Cu);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3[2] = 0.0;
      v3[3] = 0.0;
      v3[4] = 0.0;
      v3[5] = 0.0;
      v3[6] = 0.0;
      v3[8] = 0.0;
      v3[9] = 0.0;
      *v3 = 0.0;
      v3[1] = 0.0;
      v3[10] = 0.0;
      *((_BYTE *)v3 + 28) = 0;
      free(pMem: nullptr);
      v4[10] = 0.0;
      if ( pDest[0] != 0 )
      {
        v5 = strlen(pDest);
        v6 = (char *)operator new(nSize: v5 + 1);
        *((_DWORD *)v4 + 10) = v6;
        V_strncpy(pDest: v6, pSrc: pDest, maxLen: v5 + 1);
      }
      v32 = v4;
    }
    else
    {
      v32 = nullptr;
    }
    v7 = v32;
    v8 = v29;
    *v32 = v31;
    v7[1] = v30;
    m_Size = v8->m_Words.m_Size;
    m_nAllocationCount = v8->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v8->m_Words.m_Size;
    m_pMemory = v8->m_Words.m_Memory.m_pMemory;
    v12 = v8->m_Words.m_Size - m_Size - 1;
    v8->m_Words.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = (float **)&v8->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v32;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      v14 = v32;
      do
      {
        v15 = atoi(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        V_strncpy(pDest: str, pSrc: pString, maxLen: 256);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v30 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v31 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        atof(nptr: pString);
        v16 = operator new(nSize: 0x1Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[6] = 0;
          v16[4] = 0;
          v16[5] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_WORD *)v16 + 4) = 0;
          *((_BYTE *)v16 + 12) = 0;
          v17 = v16;
        }
        v25 = (void *)v17[6];
        *((_WORD *)v17 + 4) = v15;
        free(pMem: v25);
        v17[6] = 0;
        if ( str[0] != 0 )
        {
          v18 = _V_strlen(str) + 1;
          v19 = (char *)operator new(nSize: v18);
          v17[6] = v19;
          V_strncpy(pDest: v19, pSrc: str, maxLen: v18);
        }
        *(float *)v17 = v30;
        *((float *)v17 + 1) = v31;
        v20 = *((_DWORD *)v14 + 5);
        v21 = *((_DWORD *)v14 + 3);
        if ( v20 + 1 > v21 )
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(v14 + 2),
            num: v20 - v21 + 1);
        ++*((_DWORD *)v14 + 5);
        v22 = *((_DWORD *)v14 + 2);
        v23 = *((_DWORD *)v14 + 5) - v20 - 1;
        *((_DWORD *)v14 + 6) = v22;
        if ( v23 > 0 )
          _V_memmove(dest: (void *)(v22 + 4 * v20 + 4), src: (const void *)(v22 + 4 * v20), count: 4 * v23);
        v24 = (_DWORD *)(*((_DWORD *)v14 + 2) + 4 * v20);
        if ( v24 != nullptr )
          *v24 = v17;
        CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
        v2 = buf;
      }
      while ( _V_stricmp(s1: pString, s2: "}") != 0 );
    }
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419640
// Name: private: void CSentence::ParseDataVersionOnePointZero(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseDataVersionOnePointZero(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1100h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( strlen(pString) != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    if ( _V_stricmp(s1: pDest, s2: "PLAINTEXT") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "WORDS") != 0 )
      {
        if ( _V_stricmp(s1: pDest, s2: "EMPHASIS") != 0 )
        {
          if ( _V_stricmp(s1: pDest, s2: "CLOSECAPTION") != 0 )
          {
            if ( _V_stricmp(s1: pDest, s2: "OPTIONS") == 0 )
              CSentence::ParseOptions(this, buf);
          }
          else
          {
            CSentence::ParseCloseCaption(this, buf);
          }
        }
        else
        {
          CSentence::ParseEmphasis(this, buf);
        }
      }
      else
      {
        CSentence::ParseWords(this, buf);
      }
    }
    else
    {
      CSentence::ParsePlaintext(this, buf);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004197B0
// Name: public: void CSentence::InitFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1000h] BYREF

  CSentence::Reset(this);
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  if ( _V_stricmp(s1: pString, s2: "VERSION") == 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( atof(nptr: pString) == 1.0 )
    {
      CSentence::ParseDataVersionOnePointZero(this, buf);
      *((_BYTE *)this + 72) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419840
// Name: public: void CSentence::InitFromDataChunk(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromDataChunk(CSentence *this, void *data, int size)
{
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::EnsureCapacity(this: &buf, num: size);
  CUtlBuffer::Put(this: &buf, pMem: data, size);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: size);
  CSentence::InitFromBuffer(this, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00402B00
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ResourceCopy_t,int>::Grow((CUtlMemory<ResourceCopy_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00402B70
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
    CUtlMemory<ResourceCopy_t,int>::Grow((CUtlMemory<ResourceCopy_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x00403430
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
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int> *)this,
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
// Address: 0x004034A0
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
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int> *)this,
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
// Address: 0x00403610
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
// Address: 0x00404500
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  bool v2; // sf
  CUtlBinaryBlock *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
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
// Address: 0x004047C0
// Name: public: CUtlVector<struct errorList_t,class CUtlMemory<struct errorList_t,int>>::~CUtlVector<struct errorList_t,class CUtlMemory<struct errorList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<errorList_t,CUtlMemory<errorList_t,int>>::~CUtlVector<errorList_t,CUtlMemory<errorList_t,int>>(
        CUtlVector<errorList_t,CUtlMemory<errorList_t,int> > *this)
{
  bool v2; // sf
  errorList_t *m_pMemory; // eax

  CUtlVector<errorList_t,CUtlMemory<errorList_t,int>>::RemoveAll(this);
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
// Address: 0x00407950
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbol,int>::Grow((CUtlMemory<CUtlSymbol,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417420
// Name: public: int CUtlVector<struct AudioConversion_t,class CUtlMemory<struct AudioConversion_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>::InsertBefore(
        CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AudioConversion_t *m_pMemory; // ecx
  int v6; // eax
  AudioConversion_t *v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<AudioConversion_t,int>::Grow(
      (CUtlMemory<CUtlSymbolTable,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 56 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &v7->audioPath);
    CUtlString::CUtlString(this: &v7->mp3Encoder);
    v7->iXmaQuality = 60;
    *(_WORD *)&v7->bForceTo22K = 0;
    v7->bConvertToMp3 = false;
    v7->nSkipMp3ConversionIfSizeIsLessThan = 0;
    *(_WORD *)&v7->bSkipMp3ConversionIfLoopedSound = 0;
    v7->nMp3BitRate = 160;
    v7->bFakeMp3 = false;
    CUtlString::operator=(this: &v7->mp3Encoder, src: "../../tools/bin/MSEnc.exe");
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004181A0
// Name: public: void CUtlVector<struct AudioConversion_t,class CUtlMemory<struct AudioConversion_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>::RemoveAll(
        CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int> > *v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 56 * v1;
    v5 = 56 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 13) = 0;
      if ( *((int *)v3 + 12) >= 0 )
      {
        if ( *((_DWORD *)v3 + 10) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 10));
          v2 = v5;
          this = v4;
          *((_DWORD *)v3 + 10) = 0;
        }
        *((_DWORD *)v3 + 11) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          v2 = v5;
          this = v4;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 -= 56;
      v5 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418250
// Name: public: CUtlVector<struct AudioConversion_t,class CUtlMemory<struct AudioConversion_t,int>>::~CUtlVector<struct AudioConversion_t,class CUtlMemory<struct AudioConversion_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>::~CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>(
        CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int> > *this)
{
  bool v2; // sf
  AudioConversion_t *m_pMemory; // eax

  CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>::RemoveAll(this);
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
// Address: 0x00419880
// Name: public: int CUtlVector<struct variable_t,class CUtlMemory<struct variable_t,int>>::InsertBefore(int,struct variable_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
        CUtlVector<ZIP_PreloadDirectoryEntry,CUtlMemory<ZIP_PreloadDirectoryEntry,int> > *this,
        int elem,
        const ZIP_PreloadDirectoryEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ZIP_PreloadDirectoryEntry *m_pMemory; // ecx
  int v7; // eax
  ZIP_PreloadDirectoryEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x0041A410
// Name: public: void CUtlVector<struct errorList_t,class CUtlMemory<struct errorList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<errorList_t,CUtlMemory<errorList_t,int>>::RemoveAll(
        CUtlVector<errorList_t,CUtlMemory<errorList_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  errorList_t *v3; // esi
  CUtlVector<errorList_t,CUtlMemory<errorList_t,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->fileName.m_Storage.m_nActualLength = 0;
      if ( v3->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->fileName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A480
// Name: public: int CUtlVector<struct preloadRemap_t,class CUtlMemory<struct preloadRemap_t,int>>::InsertBefore(int,struct preloadRemap_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>::InsertBefore(
        CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int> > *this,
        int elem,
        const preloadRemap_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  preloadRemap_t *m_pMemory; // ecx
  int v7; // eax
  preloadRemap_t *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->filename, string: &src->filename);
    v8->preloadDirIndex = src->preloadDirIndex;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041A500
// Name: public: void CUtlVector<struct preloadRemap_t,class CUtlMemory<struct preloadRemap_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>::RemoveAll(
        CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  preloadRemap_t *v3; // esi
  CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->filename.m_Storage.m_nActualLength = 0;
      if ( v3->filename.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->filename.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->filename.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->filename.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->filename.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A570
// Name: public: void CUtlVector<struct AlternateFile_t,class CUtlMemory<struct AlternateFile_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int>>::RemoveAll(
        CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 32 * v1;
    v4 = 32 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 7) = 0;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 4));
          this = v5;
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v5;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v4 - 32;
      v4 -= 32;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B010
// Name: public: CUtlVector<struct preloadRemap_t,class CUtlMemory<struct preloadRemap_t,int>>::~CUtlVector<struct preloadRemap_t,class CUtlMemory<struct preloadRemap_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>::~CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>(
        CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int> > *this)
{
  bool v2; // sf
  preloadRemap_t *m_pMemory; // eax

  CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>::RemoveAll(this);
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
// Address: 0x0041B370
// Name: public: CUtlVector<struct AlternateFile_t,class CUtlMemory<struct AlternateFile_t,int>>::~CUtlVector<struct AlternateFile_t,class CUtlMemory<struct AlternateFile_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int>>::~CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int>>(
        CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int> > *this)
{
  bool v2; // sf
  AlternateFile_t *m_pMemory; // eax

  CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int>>::RemoveAll(this);
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
// Address: 0x0041FEB0
// Name: private: void CSentence::ParsePlaintext(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParsePlaintext(CSentence *this, CUtlBuffer *buf)
{
  bool v3; // zf
  int v4; // esi
  char *v5; // eax
  char pString[4096]; // [esp+8h] [ebp-2000h] BYREF
  char pDest[4096]; // [esp+1008h] [ebp-1000h] BYREF

  pDest[0] = 0;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncat(pDest, pSrc: pString, destBufferSize: 0x1000u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: " ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
  free(pMem: this->m_szText);
  v3 = pDest[0] == 0;
  this->m_szText = nullptr;
  if ( !v3 )
  {
    v4 = _V_strlen(str: pDest) + 1;
    v5 = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_szText = v5;
    V_strncpy(pDest: v5, pSrc: pDest, maxLen: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FFA0
// Name: private: void CSentence::ParseOptions(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseOptions(CSentence *this, CUtlBuffer *buf)
{
  unsigned int v3; // eax
  char pString[4096]; // [esp+8h] [ebp-1200h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-200h] BYREF
  char nptr[256]; // [esp+1108h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_strlen(str: pString) == 0 )
      break;
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    if ( _V_stricmp(s1: pDest, s2: "voice_duck") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "checksum") == 0 )
      {
        v3 = atoi(nptr);
        *((_BYTE *)this + 73) = 1;
        this->m_uCheckSum = v3;
      }
    }
    else
    {
      *((_BYTE *)this + 74) = atoi(nptr) != 0;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004200D0
// Name: private: void CSentence::ParseCloseCaption(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseCloseCaption(CSentence *this, CUtlBuffer *buf)
{
  int v2; // edi
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-2020h] BYREF
  char pString[4096]; // [esp+1008h] [ebp-1020h] BYREF
  char pDest[32]; // [esp+2008h] [ebp-20h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    while ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      if ( _V_stricmp(s1: pString, s2: "PHRASE") != 0 )
        break;
      memset(dst, value: 0, count: sizeof(dst));
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      V_strncpy(pDest, pSrc: pString, maxLen: 32);
      if ( _V_stricmp(s1: pDest, s2: "unicode") != 0 )
        _V_stricmp(s1: pDest, s2: "char");
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      v2 = atoi(nptr: pString);
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::Get(this: buf, pMem: dst, size: v2);
      dst[v2] = 0;
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004202C0
// Name: public: void CSentence::ClearRuntimePhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ClearRuntimePhonemes(CSentence *this)
{
  for ( ; this->m_RunTimePhonemes.m_Size > 0; --this->m_RunTimePhonemes.m_Size )
  {
    free(pMem: *(void **)this->m_RunTimePhonemes.m_Memory.m_pMemory);
    if ( this->m_RunTimePhonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_RunTimePhonemes.m_Memory.m_pMemory,
        src: this->m_RunTimePhonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_RunTimePhonemes.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420310
// Name: public: CWordTag::~CWordTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::~CWordTag(CWordTag *this)
{
  CPhonemeTag *v2; // edi

  free(pMem: this->m_pszWord);
  for ( ; this->m_Phonemes.m_Size > 0; --this->m_Phonemes.m_Size )
  {
    v2 = *this->m_Phonemes.m_Memory.m_pMemory;
    if ( v2 != nullptr )
    {
      free(pMem: v2->m_szPhoneme);
      free(pMem: v2);
    }
    if ( this->m_Phonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Phonemes.m_Memory.m_pMemory,
        src: this->m_Phonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Phonemes.m_Size - 1));
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Phonemes);
}

//------------------------------------------------------------------------------
// Address: 0x00420380
// Name: public: CSentence::CSentence(void)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::CSentence(CSentence *this)
{
  this->m_Words.m_Memory.m_pMemory = nullptr;
  this->m_Words.m_Memory.m_nAllocationCount = 0;
  this->m_Words.m_Memory.m_nGrowSize = 0;
  this->m_Words.m_Size = 0;
  this->m_Words.m_pElements = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_pMemory = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_nAllocationCount = 0;
  this->m_RunTimePhonemes.m_Memory.m_nGrowSize = 0;
  this->m_RunTimePhonemes.m_Size = 0;
  this->m_RunTimePhonemes.m_pElements = nullptr;
  this->m_EmphasisSamples.m_Memory.m_pMemory = nullptr;
  this->m_EmphasisSamples.m_Memory.m_nAllocationCount = 0;
  this->m_EmphasisSamples.m_Memory.m_nGrowSize = 0;
  this->m_EmphasisSamples.m_Size = 0;
  this->m_EmphasisSamples.m_pElements = nullptr;
  this->m_nResetWordBase = 0;
  this->m_szText = nullptr;
  this->m_uCheckSum = 0;
  *(_WORD *)((char *)this + 73) = 0;
  *((_BYTE *)this + 72) = 0;
  *((_BYTE *)this + 75) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004203D0
// Name: public: void CSentence::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Reset(CSentence *this)
{
  bool v2; // cc
  CWordTag **m_pMemory; // eax
  CWordTag *v4; // edi

  v2 = this->m_Words.m_Size <= 0;
  this->m_nResetWordBase = 0;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_Words.m_Memory.m_pMemory;
      v4 = *m_pMemory;
      if ( *m_pMemory != nullptr )
      {
        CWordTag::~CWordTag(this: *m_pMemory);
        free(pMem: v4);
      }
      if ( this->m_Words.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Words.m_Memory.m_pMemory,
          src: this->m_Words.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Words.m_Size - 1));
      --this->m_Words.m_Size;
    }
    while ( this->m_Words.m_Size > 0 );
  }
  this->m_EmphasisSamples.m_Size = 0;
  CSentence::ClearRuntimePhonemes(this);
}

//------------------------------------------------------------------------------
// Address: 0x00420440
// Name: public: CWordTag::CWordTag(class CWordTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this, const CWordTag *from)
{
  CWordTag *v2; // esi
  CUtlMemory<S3RGBA,int> *p_m_Phonemes; // edi
  char *m_pszWord; // ebx
  unsigned int v5; // kr00_4
  char *v6; // eax
  unsigned int m_uiEndByte; // ecx
  int v8; // ebx
  CPhonemeTag *v9; // eax
  CPhonemeTag *v10; // esi
  CPhonemeTag *v11; // eoff
  unsigned int v12; // ecx
  char *m_szPhoneme; // eax
  const char *v14; // ebx
  int v15; // ebx
  char *v16; // eax
  S3RGBA *m_pMemory; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v19; // ecx
  int v20; // eax
  CPhonemeTag **v21; // esi
  int p; // [esp+Ch] [ebp-Ch]
  const char *newPhoneme; // [esp+14h] [ebp-4h]
  CPhonemeTag *newPhonemea; // [esp+14h] [ebp-4h]

  v2 = this;
  p_m_Phonemes = (CUtlMemory<S3RGBA,int> *)&this->m_Phonemes;
  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_pszWord = nullptr;
  m_pszWord = from->m_pszWord;
  free(pMem: nullptr);
  v2->m_pszWord = nullptr;
  if ( m_pszWord != nullptr && *m_pszWord != 0 )
  {
    v5 = strlen(m_pszWord);
    v6 = (char *)MemAlloc_Alloc(nSize: v5 + 1);
    this->m_pszWord = v6;
    V_strncpy(pDest: v6, pSrc: m_pszWord, maxLen: v5 + 1);
    v2 = this;
  }
  m_uiEndByte = from->m_uiEndByte;
  v2->m_uiStartByte = from->m_uiStartByte;
  v2->m_uiEndByte = m_uiEndByte;
  v2->m_flStartTime = from->m_flStartTime;
  v8 = 0;
  p = 0;
  v2->m_flEndTime = from->m_flEndTime;
  v2->m_bSelected = from->m_bSelected;
  if ( from->m_Phonemes.m_Size <= 0 )
    return v2;
  do
  {
    v9 = (CPhonemeTag *)MemAlloc_Alloc(nSize: 0x1Cu);
    v10 = v9;
    if ( v9 != nullptr )
    {
      v11 = from->m_Phonemes.m_Memory.m_pMemory[v8];
      *(_QWORD *)&v9->m_flStartTime = *(_QWORD *)&v11->m_flStartTime;
      *(_DWORD *)&v9->m_nPhonemeCode = *(_DWORD *)&v11->m_nPhonemeCode;
      v12 = v11->m_uiEndByte;
      v9->m_uiStartByte = v11->m_uiStartByte;
      v9->m_uiEndByte = v12;
      v9->m_bSelected = v11->m_bSelected;
      v9->m_szPhoneme = nullptr;
      m_szPhoneme = v11->m_szPhoneme;
      if ( m_szPhoneme != nullptr )
      {
        v14 = m_szPhoneme;
        newPhoneme = m_szPhoneme;
      }
      else
      {
        newPhoneme = pDefaultValue;
        v14 = pDefaultValue;
      }
      free(pMem: nullptr);
      v10->m_szPhoneme = nullptr;
      if ( v14 != nullptr && *v14 != 0 )
      {
        v15 = _V_strlen(str: v14) + 1;
        v16 = (char *)MemAlloc_Alloc(nSize: v15);
        v10->m_szPhoneme = v16;
        V_strncpy(pDest: v16, pSrc: newPhoneme, maxLen: v15);
      }
      v8 = p;
      newPhonemea = v10;
    }
    else
    {
      newPhonemea = nullptr;
    }
    m_pMemory = p_m_Phonemes[1].m_pMemory;
    m_nAllocationCount = p_m_Phonemes->m_nAllocationCount;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Phonemes, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++p_m_Phonemes[1].m_pMemory;
    v19 = p_m_Phonemes->m_pMemory;
    v20 = (char *)p_m_Phonemes[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Phonemes[1].m_nAllocationCount = (int)p_m_Phonemes->m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[(_DWORD)m_pMemory + 1], src: &v19[(_DWORD)m_pMemory], count: 4 * v20);
    v21 = (CPhonemeTag **)&p_m_Phonemes->m_pMemory[(_DWORD)m_pMemory];
    if ( v21 != nullptr )
      *v21 = newPhonemea;
    p = ++v8;
  }
  while ( v8 < from->m_Phonemes.m_Size );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00420600
// Name: public: CSentence::~CSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::~CSentence(CSentence *this)
{
  CSentence::Reset(this);
  free(pMem: this->m_szText);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EmphasisSamples);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RunTimePhonemes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Words);
}

//------------------------------------------------------------------------------
// Address: 0x00420630
// Name: private: void CSentence::ParseEmphasis(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseEmphasis(CSentence *this, CUtlBuffer *buf)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v6; // eax
  CEmphasisSample *v7; // eax
  int v8; // ecx
  char pString[4096]; // [esp+8h] [ebp-120Ch] BYREF
  char nptr[256]; // [esp+1008h] [ebp-20Ch] BYREF
  char pDest[256]; // [esp+1108h] [ebp-10Ch] BYREF
  __int64 v12; // [esp+1208h] [ebp-Ch]
  int v13; // [esp+1210h] [ebp-4h]

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    LOBYTE(v13) = 0;
    *(float *)&v12 = atof(nptr: pDest);
    *((float *)&v12 + 1) = atof(nptr);
    m_Size = this->m_EmphasisSamples.m_Size;
    m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
        this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EmphasisSamples.m_Size;
    m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
    v6 = this->m_EmphasisSamples.m_Size - m_Size - 1;
    this->m_EmphasisSamples.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v6);
    v7 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
    {
      v8 = v13;
      *(_QWORD *)&v7->time = v12;
      *(_DWORD *)&v7->selected = v8;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420780
// Name: public: void CSentence::CacheSaveToBuffer(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::CacheSaveToBuffer(CSentence *this, CUtlBuffer *buf, int version)
{
  int v3; // ebx
  CUtlBuffer *v4; // esi
  int m_Size_low; // edi
  bool v6; // zf
  int v7; // ebx
  CBasePhonemeTag *v8; // edi
  CBasePhonemeTag *v9; // edi
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl
  float v12; // xmm0_4
  int v13; // xmm1_4
  __int16 v14; // bx
  float v15; // xmm0_4
  int v16; // xmm1_4
  __int16 v17; // bx
  float m_flStartTime; // xmm0_4
  float m_flEndTime; // xmm0_4
  int v20; // ebx
  CBasePhonemeTag *v21; // edi
  float v22; // xmm0_4
  float v23; // xmm0_4
  CUtlBuffer *m_Size; // edi
  float *v25; // edi
  int v26; // xmm1_4
  float v27; // xmm0_4
  __int16 v28; // bx
  int v29; // eax
  _WORD *v30; // eax
  float v31; // xmm0_4
  __int16 v32; // bx
  unsigned __int8 *v33; // eax
  bool v34; // bl
  int m_Put; // eax
  int v36; // ebx
  CEmphasisSample *m_pMemory; // edi
  float time; // xmm0_4
  BOOL v39; // edi
  int v40; // ebx
  CEmphasisSample *v41; // edi
  float v42; // xmm0_4
  __int16 v43; // di
  bool v44; // bl
  int v45; // eax
  int src; // [esp+4h] [ebp-20h]
  int srca; // [esp+4h] [ebp-20h]
  float value; // [esp+14h] [ebp-10h]
  float v49; // [esp+14h] [ebp-10h]
  unsigned __int16 inputBuffer[2]; // [esp+18h] [ebp-Ch] BYREF
  int i; // [esp+1Ch] [ebp-8h] BYREF
  CSentence *v52; // [esp+20h] [ebp-4h]

  v3 = version;
  v4 = buf;
  m_Size_low = LOWORD(this->m_RunTimePhonemes.m_Size);
  v52 = this;
  if ( version == 4 )
  {
    CUtlBuffer::PutChar(this: buf, c: 4);
    CUtlBuffer::PutChar(this: v4, c: 0);
    CUtlBuffer::PutChar(this: v4, c: 0);
    CUtlBuffer::PutChar(this: v4, c: 0);
    v6 = (v4->m_Flags & 1) == 0;
    buf = (CUtlBuffer *)m_Size_low;
    if ( v6 )
      CUtlBuffer::PutTypeBin<int>(this: v4, src: m_Size_low);
    else
      CUtlBuffer::Printf(this: v4, pFmt: "%d", m_Size_low);
    v7 = 0;
    if ( m_Size_low > 0 )
    {
      do
      {
        v8 = v52->m_RunTimePhonemes.m_Memory.m_pMemory[v7];
        src = v8->m_nPhonemeCode;
        if ( (v4->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v4, pFmt: "%d", src);
        else
          CUtlBuffer::PutTypeBin<int>(this: v4, src);
        m_flStartTime = v8->m_flStartTime;
        if ( (v4->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v4, pFmt: "%f", m_flStartTime);
        else
          CUtlBuffer::PutTypeBin<float>(this: v4, src: m_flStartTime);
        m_flEndTime = v8->m_flEndTime;
        if ( (v4->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v4, pFmt: "%f", m_flEndTime);
        else
          CUtlBuffer::PutTypeBin<float>(this: v4, src: m_flEndTime);
        ++v7;
      }
      while ( v7 < (int)buf );
    }
  }
  else
  {
    CUtlBuffer::PutChar(this: buf, c: version);
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", (__int16)m_Size_low);
    else
      CUtlBuffer::PutTypeBin<short>(this: v4, src: m_Size_low);
    buf = (CUtlBuffer *)m_Size_low;
    if ( v3 == 5 )
    {
      i = 0;
      if ( m_Size_low > 0 )
      {
        do
        {
          v9 = v52->m_RunTimePhonemes.m_Memory.m_pMemory[i];
          v10 = CodeToByteCode(code: v9->m_nPhonemeCode);
          v11 = v10;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hu", v10);
          }
          else if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
          {
            v4->m_Memory.m_pMemory[v4->m_Put++ - v4->m_nOffset] = v11;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
          v12 = (float)(v9->m_flStartTime * 1000.0) * 0.2;
          *(float *)&v13 = -32768.0;
          if ( v12 < -32768.0 || (*(float *)&v13 = 32767.0, v12 > 32767.0) )
            v12 = *(float *)&v13;
          v14 = (int)v12;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", v14);
          }
          else
          {
            *(_DWORD *)inputBuffer = (unsigned __int16)(int)v12;
            if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned short>(
                  this: &v4->m_Byteswap,
                  outputBuffer: (unsigned __int16 *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                  inputBuffer,
                  count: 1);
              else
                *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v14;
              v4->m_Put += 2;
              CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            }
          }
          v15 = (float)(v9->m_flEndTime * 1000.0) * 0.2;
          *(float *)&v16 = -32768.0;
          if ( v15 < -32768.0 || (*(float *)&v16 = 32767.0, v15 > 32767.0) )
            v15 = *(float *)&v16;
          v17 = (int)v15;
          if ( (v4->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", v17);
          }
          else
          {
            *(_DWORD *)inputBuffer = (unsigned __int16)(int)v15;
            if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned short>(
                  this: &v4->m_Byteswap,
                  outputBuffer: (unsigned __int16 *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                  inputBuffer,
                  count: 1);
              else
                *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v17;
              v4->m_Put += 2;
              CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            }
          }
          ++i;
        }
        while ( i < (int)buf );
      }
    }
    else
    {
      v20 = 0;
      if ( m_Size_low > 0 )
      {
        do
        {
          v21 = v52->m_RunTimePhonemes.m_Memory.m_pMemory[v20];
          if ( (v4->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: v4, pFmt: "%hd", (__int16)v21->m_nPhonemeCode);
          else
            CUtlBuffer::PutTypeBin<short>(this: v4, src: v21->m_nPhonemeCode);
          v22 = v21->m_flStartTime;
          if ( (v4->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: v4, pFmt: "%f", v22);
          else
            CUtlBuffer::PutTypeBin<float>(this: v4, src: v22);
          v23 = v21->m_flEndTime;
          if ( (v4->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: v4, pFmt: "%f", v23);
          else
            CUtlBuffer::PutTypeBin<float>(this: v4, src: v23);
          ++v20;
        }
        while ( v20 < (int)buf );
      }
    }
  }
  m_Size = (CUtlBuffer *)v52->m_EmphasisSamples.m_Size;
  if ( version == 5 )
  {
    if ( (v4->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", (__int16)m_Size);
    }
    else
    {
      buf = (CUtlBuffer *)(unsigned __int16)m_Size;
      if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
      {
        if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &v4->m_Byteswap,
            outputBuffer: (unsigned __int16 *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
            inputBuffer: (unsigned __int16 *)&buf,
            count: 1);
        else
          *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = (_WORD)m_Size;
        v4->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
      }
    }
    if ( (int)m_Size > 0 )
    {
      version = 0;
      for ( i = (int)m_Size; i != 0; --i )
      {
        v25 = (float *)((char *)&v52->m_EmphasisSamples.m_Memory.m_pMemory->time + version);
        *(float *)&v26 = -32768.0;
        v27 = (float)(*v25 * 1000.0) * 0.2;
        if ( v27 < -32768.0 || (*(float *)&v26 = 32767.0, v27 > 32767.0) )
          v27 = *(float *)&v26;
        v28 = (int)v27;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v28);
        }
        else
        {
          buf = (CUtlBuffer *)(unsigned __int16)(int)v27;
          if ( !CUtlBuffer::CheckPut(this: v4, nSize: 2) )
            goto LABEL_83;
          v29 = (int)&v4->m_Memory.m_pMemory[-v4->m_nOffset];
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          {
            v30 = (_WORD *)(v4->m_Put + v29);
            if ( v30 != nullptr )
            {
              if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              {
                HIWORD(buf) = 0;
                LOBYTE(buf) = (unsigned __int16)(int)v27 >> 8;
                BYTE1(buf) = (int)v27;
                _V_memcpy(dest: v30, src: &buf, count: 2);
                v4->m_Put += 2;
                CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
                goto LABEL_83;
              }
              if ( v30 != (_WORD *)&buf )
              {
                *v30 = (_WORD)buf;
                v4->m_Put += 2;
                CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
                goto LABEL_83;
              }
            }
          }
          else
          {
            *(_WORD *)(v29 + v4->m_Put) = v28;
          }
          v4->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
        }
LABEL_83:
        v31 = v25[1] * 32767.0;
        if ( v31 >= 0.0 )
        {
          if ( v31 > 32767.0 )
            v31 = 32767.0;
        }
        else
        {
          v31 = 0.0;
        }
        v32 = (int)v31;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v32);
          goto LABEL_98;
        }
        buf = (CUtlBuffer *)(unsigned __int16)(int)v31;
        if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
        {
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) == 0 )
          {
            *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v32;
LABEL_96:
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
            goto LABEL_98;
          }
          v33 = &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset];
          if ( v33 == nullptr )
            goto LABEL_96;
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          {
            HIWORD(buf) = 0;
            LOBYTE(buf) = (unsigned __int16)(int)v31 >> 8;
            BYTE1(buf) = (int)v31;
            _V_memcpy(dest: v33, src: &buf, count: 2);
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
          else
          {
            if ( v33 == (unsigned __int8 *)&buf )
              goto LABEL_96;
            *(_WORD *)v33 = (_WORD)buf;
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
LABEL_98:
        version += 12;
      }
    }
    v34 = *((_BYTE *)v52 + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      m_Put = v4->m_Put;
      if ( m_Put != 0 && v4->m_Memory.m_pMemory[m_Put - v4->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: v4);
    }
    if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
    {
      v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v34;
LABEL_163:
      CUtlBuffer::AddNullTermination(this: v4, nPut: ++v4->m_Put);
    }
  }
  else if ( version == 4 )
  {
    srca = v52->m_EmphasisSamples.m_Size;
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%d", srca);
    else
      CUtlBuffer::PutTypeBin<int>(this: v4, src: srca);
    if ( (int)m_Size > 0 )
    {
      v36 = 0;
      for ( buf = m_Size; buf != nullptr; buf = (CUtlBuffer *)((char *)buf - 1) )
      {
        v6 = (v4->m_Flags & 1) == 0;
        m_pMemory = v52->m_EmphasisSamples.m_Memory.m_pMemory;
        time = m_pMemory[v36].time;
        *(float *)inputBuffer = time;
        if ( v6 )
        {
          version = LODWORD(time);
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: (float *)&version,
                count: 1);
            else
              *(_DWORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = *(_DWORD *)inputBuffer;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        else
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", time);
        }
        value = m_pMemory[v36].value;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", m_pMemory[v36].value);
        }
        else
        {
          i = LODWORD(m_pMemory[v36].value);
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: (float *)&i,
                count: 1);
            else
              *(float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = value;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        ++v36;
      }
    }
    v39 = *((_BYTE *)v52 + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v4, pFmt: "%d", *((_BYTE *)v52 + 74) != 0);
    }
    else
    {
      buf = (CUtlBuffer *)(*((_BYTE *)v52 + 74) != 0);
      if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
      {
        if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v4->m_Byteswap,
            outputBuffer: (int *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
            inputBuffer: (int *)&buf,
            count: 1);
        else
          *(_DWORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v39;
        v4->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
      }
    }
  }
  else
  {
    if ( (v4->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v4, pFmt: "%hd", (__int16)m_Size);
    else
      CUtlBuffer::PutTypeBin<short>(this: v4, src: v52->m_EmphasisSamples.m_Size);
    if ( (int)m_Size > 0 )
    {
      v40 = 0;
      for ( buf = m_Size; buf != nullptr; buf = (CUtlBuffer *)((char *)buf - 1) )
      {
        v41 = v52->m_EmphasisSamples.m_Memory.m_pMemory;
        v49 = v41[v40].time;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%f", v41[v40].time);
        }
        else
        {
          version = LODWORD(v41[v40].time);
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 4) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &v4->m_Byteswap,
                outputBuffer: (float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer: (float *)&version,
                count: 1);
            else
              *(float *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v49;
            v4->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        v42 = v41[v40].value * 32767.0;
        if ( v42 >= 0.0 )
        {
          if ( v42 > 32767.0 )
            v42 = 32767.0;
        }
        else
        {
          v42 = 0.0;
        }
        v43 = (int)v42;
        if ( (v4->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v4, pFmt: "%hd", v43);
        }
        else
        {
          *(_DWORD *)inputBuffer = (unsigned __int16)(int)v42;
          if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
          {
            if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned short>(
                this: &v4->m_Byteswap,
                outputBuffer: (unsigned __int16 *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
                inputBuffer,
                count: 1);
            else
              *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v43;
            v4->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
          }
        }
        ++v40;
      }
    }
    v44 = *((_BYTE *)v52 + 74) != 0;
    if ( (v4->m_Flags & 1) != 0 )
    {
      v45 = v4->m_Put;
      if ( v45 != 0 && v4->m_Memory.m_pMemory[v45 - v4->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: v4);
    }
    if ( CUtlBuffer::CheckPut(this: v4, nSize: 1) )
    {
      v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v44;
      goto LABEL_163;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004211F0
// Name: public: void CSentence::AddRuntimePhoneme(class CPhonemeTag const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::AddRuntimePhoneme(CSentence *this, const CPhonemeTag *src)
{
  _DWORD *v3; // eax
  CBasePhonemeTag *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBasePhonemeTag **m_pMemory; // ecx
  int v8; // eax
  CBasePhonemeTag **v9; // edi

  v3 = MemAlloc_Alloc(nSize: 0xCu);
  if ( v3 != nullptr )
  {
    *v3 = 0;
    v3[1] = 0;
    *((_WORD *)v3 + 4) = 0;
    v4 = (CBasePhonemeTag *)v3;
  }
  else
  {
    v4 = nullptr;
  }
  *v4 = src->CBasePhonemeTag;
  m_Size = this->m_RunTimePhonemes.m_Size;
  m_nAllocationCount = this->m_RunTimePhonemes.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_RunTimePhonemes,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_RunTimePhonemes.m_Size;
  m_pMemory = this->m_RunTimePhonemes.m_Memory.m_pMemory;
  v8 = this->m_RunTimePhonemes.m_Size - m_Size - 1;
  this->m_RunTimePhonemes.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_RunTimePhonemes.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v4;
}

//------------------------------------------------------------------------------
// Address: 0x00421290
// Name: public: void CSentence::MakeRuntimeOnly(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::MakeRuntimeOnly(CSentence *this)
{
  int m_Size; // edx
  int v3; // eax
  CWordTag *v4; // ebx
  int v5; // edi
  CWordTag **m_pMemory; // ecx
  CWordTag *v7; // edi
  char *m_szText; // [esp-4h] [ebp-1Ch]
  int c; // [esp+Ch] [ebp-Ch]
  int pcount; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  m_szText = this->m_szText;
  *((_BYTE *)this + 75) = 1;
  free(pMem: m_szText);
  m_Size = this->m_Words.m_Size;
  v3 = 0;
  this->m_szText = nullptr;
  c = m_Size;
  for ( i = 0; v3 < m_Size; i = v3 )
  {
    v4 = this->m_Words.m_Memory.m_pMemory[v3];
    v5 = 0;
    pcount = v4->m_Phonemes.m_Size;
    if ( pcount > 0 )
    {
      do
        CSentence::AddRuntimePhoneme(this, src: v4->m_Phonemes.m_Memory.m_pMemory[v5++]);
      while ( v5 < pcount );
      v3 = i;
      m_Size = c;
    }
    ++v3;
  }
  for ( ; this->m_Words.m_Size > 0; --this->m_Words.m_Size )
  {
    m_pMemory = this->m_Words.m_Memory.m_pMemory;
    v7 = *m_pMemory;
    if ( *m_pMemory != nullptr )
    {
      CWordTag::~CWordTag(this: *m_pMemory);
      free(pMem: v7);
    }
    if ( this->m_Words.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Words.m_Memory.m_pMemory,
        src: this->m_Words.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Words.m_Size - 1));
  }
  *((_BYTE *)this + 72) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00421350
// Name: public: class CSentence __near & CSentence::operator=(class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::operator=(CSentence *this, const CSentence *src)
{
  CSentence *v2; // esi
  const CSentence *v3; // ebx
  const CWordTag *v4; // edi
  CWordTag *v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v9; // eax
  CWordTag **v10; // eax
  char *m_szText; // edi
  int v12; // esi
  char *v13; // eax
  int v14; // edi
  int v15; // eax
  CEmphasisSample *v16; // ecx
  int v17; // eax
  CEmphasisSample *v18; // eax
  CBasePhonemeTag *v19; // eax
  int v20; // edi
  _DWORD *v21; // eax
  CBasePhonemeTag *v22; // ebx
  int v23; // edi
  int v24; // eax
  CBasePhonemeTag **v25; // ecx
  int v26; // eax
  CBasePhonemeTag **v27; // eax
  __int64 full; // [esp+Ch] [ebp-34h]
  CWordTag *newWord; // [esp+34h] [ebp-Ch]
  CWordTag *newWorda; // [esp+34h] [ebp-Ch]
  CWordTag *newWordb; // [esp+34h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-4h]
  int ia; // [esp+3Ch] [ebp-4h]
  int ib; // [esp+3Ch] [ebp-4h]
  CEmphasisSample s; // 0:^3C.12

  v2 = this;
  CSentence::Reset(this);
  v3 = src;
  for ( i = 0; i < src->m_Words.m_Size; ++i )
  {
    v4 = src->m_Words.m_Memory.m_pMemory[i];
    v5 = (CWordTag *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v5 != nullptr )
      newWord = CWordTag::CWordTag(this: v5, from: v4);
    else
      newWord = nullptr;
    m_Size = v2->m_Words.m_Size;
    m_nAllocationCount = v2->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v2->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_Words.m_Size;
    m_pMemory = v2->m_Words.m_Memory.m_pMemory;
    v9 = v2->m_Words.m_Size - m_Size - 1;
    v2->m_Words.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &v2->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = newWord;
  }
  m_szText = src->m_szText;
  if ( src->m_szText == nullptr )
    m_szText = (char *)pDefaultValue;
  free(pMem: v2->m_szText);
  v2->m_szText = nullptr;
  if ( m_szText != nullptr && *m_szText != 0 )
  {
    v12 = _V_strlen(str: m_szText) + 1;
    v13 = (char *)MemAlloc_Alloc(nSize: v12);
    this->m_szText = v13;
    V_strncpy(pDest: v13, pSrc: m_szText, maxLen: v12);
    v2 = this;
  }
  v2->m_nResetWordBase = src->m_nResetWordBase;
  if ( src->m_EmphasisSamples.m_Size > 0 )
  {
    ia = 0;
    newWorda = (CWordTag *)src->m_EmphasisSamples.m_Size;
    do
    {
      v14 = v2->m_EmphasisSamples.m_Size;
      s = src->m_EmphasisSamples.m_Memory.m_pMemory[ia];
      v15 = v2->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      if ( v14 + 1 > v15 )
        CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v2->m_EmphasisSamples,
          num: v14 - v15 + 1);
      ++v2->m_EmphasisSamples.m_Size;
      v16 = v2->m_EmphasisSamples.m_Memory.m_pMemory;
      v17 = v2->m_EmphasisSamples.m_Size - v14 - 1;
      v2->m_EmphasisSamples.m_pElements = v16;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 12 * v17);
      v18 = &v2->m_EmphasisSamples.m_Memory.m_pMemory[v14];
      if ( v18 != nullptr )
        *v18 = s;
      ++ia;
      newWorda = (CWordTag *)((char *)newWorda - 1);
    }
    while ( newWorda != nullptr );
    v2 = this;
  }
  *((_BYTE *)v2 + 75) = *((_BYTE *)src + 75);
  newWordb = (CWordTag *)src->m_RunTimePhonemes.m_Size;
  ib = 0;
  if ( (int)newWordb > 0 )
  {
    do
    {
      v19 = v3->m_RunTimePhonemes.m_Memory.m_pMemory[ib];
      v20 = *(_DWORD *)&v19->m_nPhonemeCode;
      full = *(_QWORD *)&v19->m_flStartTime;
      v21 = MemAlloc_Alloc(nSize: 0xCu);
      if ( v21 != nullptr )
      {
        *v21 = 0;
        v21[1] = 0;
        *((_WORD *)v21 + 4) = 0;
        v22 = (CBasePhonemeTag *)v21;
      }
      else
      {
        v22 = nullptr;
      }
      *(_QWORD *)&v22->m_flStartTime = full;
      *(_DWORD *)&v22->m_nPhonemeCode = v20;
      v23 = v2->m_RunTimePhonemes.m_Size;
      v24 = v2->m_RunTimePhonemes.m_Memory.m_nAllocationCount;
      if ( v23 + 1 > v24 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v2->m_RunTimePhonemes,
          num: v23 - v24 + 1);
      ++v2->m_RunTimePhonemes.m_Size;
      v25 = v2->m_RunTimePhonemes.m_Memory.m_pMemory;
      v26 = v2->m_RunTimePhonemes.m_Size - v23 - 1;
      v2->m_RunTimePhonemes.m_pElements = v25;
      if ( v26 > 0 )
        _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 4 * v26);
      v27 = &v2->m_RunTimePhonemes.m_Memory.m_pMemory[v23];
      if ( v27 != nullptr )
        *v27 = v22;
      free(pMem: nullptr);
      v3 = src;
      ++ib;
    }
    while ( ib < (int)newWordb );
    v2 = this;
  }
  *((_BYTE *)v2 + 74) = *((_BYTE *)v3 + 74);
  *((_BYTE *)v2 + 73) = *((_BYTE *)v3 + 73);
  v2->m_uCheckSum = v3->m_uCheckSum;
  *((_BYTE *)v2 + 72) = *((_BYTE *)v3 + 72);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004215F0
// Name: private: void CSentence::ParseWords(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseWords(CSentence *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // ebx
  float *v3; // eax
  float *v4; // esi
  unsigned int v5; // kr00_4
  char *v6; // eax
  float *v7; // eax
  CSentence *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v12; // eax
  float **v13; // edi
  float *v14; // esi
  __int16 v15; // di
  _DWORD *v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  char *v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  void *v25; // [esp-8h] [ebp-1220h]
  char pString[4096]; // [esp+8h] [ebp-1210h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-210h] BYREF
  char str[256]; // [esp+1108h] [ebp-110h] BYREF
  CSentence *v29; // [esp+1208h] [ebp-10h]
  float v30; // [esp+120Ch] [ebp-Ch]
  float v31; // [esp+1210h] [ebp-8h]
  float *v32; // [esp+1214h] [ebp-4h]

  v2 = buf;
  v29 = this;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_stricmp(s1: pString, s2: "WORD") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v31 = atof(nptr: pString);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v30 = atof(nptr: pString);
    v3 = (float *)MemAlloc_Alloc(nSize: 0x2Cu);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3[2] = 0.0;
      v3[3] = 0.0;
      v3[4] = 0.0;
      v3[5] = 0.0;
      v3[6] = 0.0;
      v3[8] = 0.0;
      v3[9] = 0.0;
      *v3 = 0.0;
      v3[1] = 0.0;
      v3[10] = 0.0;
      *((_BYTE *)v3 + 28) = 0;
      free(pMem: nullptr);
      v4[10] = 0.0;
      if ( pDest[0] != 0 )
      {
        v5 = strlen(pDest);
        v6 = (char *)MemAlloc_Alloc(nSize: v5 + 1);
        *((_DWORD *)v4 + 10) = v6;
        V_strncpy(pDest: v6, pSrc: pDest, maxLen: v5 + 1);
      }
      v32 = v4;
    }
    else
    {
      v32 = nullptr;
    }
    v7 = v32;
    v8 = v29;
    *v32 = v31;
    v7[1] = v30;
    m_Size = v8->m_Words.m_Size;
    m_nAllocationCount = v8->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v8->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v8->m_Words.m_Size;
    m_pMemory = v8->m_Words.m_Memory.m_pMemory;
    v12 = v8->m_Words.m_Size - m_Size - 1;
    v8->m_Words.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = (float **)&v8->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v32;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      v14 = v32;
      do
      {
        v15 = atoi(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        V_strncpy(pDest: str, pSrc: pString, maxLen: 256);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v30 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v31 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        atof(nptr: pString);
        v16 = MemAlloc_Alloc(nSize: 0x1Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[6] = 0;
          v16[4] = 0;
          v16[5] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_WORD *)v16 + 4) = 0;
          *((_BYTE *)v16 + 12) = 0;
          v17 = v16;
        }
        v25 = (void *)v17[6];
        *((_WORD *)v17 + 4) = v15;
        free(pMem: v25);
        v17[6] = 0;
        if ( str[0] != 0 )
        {
          v18 = _V_strlen(str) + 1;
          v19 = (char *)MemAlloc_Alloc(nSize: v18);
          v17[6] = v19;
          V_strncpy(pDest: v19, pSrc: str, maxLen: v18);
        }
        *(float *)v17 = v30;
        *((float *)v17 + 1) = v31;
        v20 = *((_DWORD *)v14 + 5);
        v21 = *((_DWORD *)v14 + 3);
        if ( v20 + 1 > v21 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(v14 + 2), num: v20 - v21 + 1);
        ++*((_DWORD *)v14 + 5);
        v22 = *((_DWORD *)v14 + 2);
        v23 = *((_DWORD *)v14 + 5) - v20 - 1;
        *((_DWORD *)v14 + 6) = v22;
        if ( v23 > 0 )
          _V_memmove(dest: (void *)(v22 + 4 * v20 + 4), src: (const void *)(v22 + 4 * v20), count: 4 * v23);
        v24 = (_DWORD *)(*((_DWORD *)v14 + 2) + 4 * v20);
        if ( v24 != nullptr )
          *v24 = v17;
        CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
        v2 = buf;
      }
      while ( _V_stricmp(s1: pString, s2: "}") != 0 );
    }
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421A10
// Name: private: void CSentence::ParseDataVersionOnePointZero(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseDataVersionOnePointZero(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1100h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( strlen(pString) != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    if ( _V_stricmp(s1: pDest, s2: "PLAINTEXT") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "WORDS") != 0 )
      {
        if ( _V_stricmp(s1: pDest, s2: "EMPHASIS") != 0 )
        {
          if ( _V_stricmp(s1: pDest, s2: "CLOSECAPTION") != 0 )
          {
            if ( _V_stricmp(s1: pDest, s2: "OPTIONS") == 0 )
              CSentence::ParseOptions(this, buf);
          }
          else
          {
            CSentence::ParseCloseCaption(this, buf);
          }
        }
        else
        {
          CSentence::ParseEmphasis(this, buf);
        }
      }
      else
      {
        CSentence::ParseWords(this, buf);
      }
    }
    else
    {
      CSentence::ParsePlaintext(this, buf);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421B80
// Name: public: void CSentence::CacheRestoreFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::CacheRestoreFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  signed __int8 v4; // al
  int v5; // ebx
  unsigned __int16 Short; // ax
  int i; // ebx
  __int16 v8; // ax
  __int16 v9; // ax
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  CEmphasisSample *v13; // ecx
  int v14; // eax
  CEmphasisSample *v15; // eax
  unsigned __int8 v16; // cl
  unsigned __int16 Int; // bx
  int v18; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v22; // eax
  CEmphasisSample *v23; // eax
  bool v24; // zf
  unsigned __int16 v25; // bx
  __int16 v26; // ax
  __int16 v27; // ax
  int v28; // ebx
  int v29; // ecx
  int v30; // eax
  CEmphasisSample *v31; // ecx
  int v32; // eax
  CEmphasisSample *v33; // eax
  CPhonemeTag pt; // [esp+Ch] [ebp-34h] BYREF
  CEmphasisSample sample; // [esp+28h] [ebp-18h]
  float et; // [esp+34h] [ebp-Ch] BYREF
  float st[2]; // [esp+38h] [ebp-8h] BYREF
  unsigned __int8 bufa; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufb; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufc; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufd; // [esp+48h] [ebp+8h]
  CUtlBuffer *bufe; // [esp+48h] [ebp+8h]
  CUtlBuffer *buff; // [esp+48h] [ebp+8h]

  CSentence::Reset(this);
  *((_BYTE *)this + 75) = 1;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    v4 = 0;
  }
  v5 = v4;
  if ( v4 != 1 )
  {
    if ( v4 == 4 )
      goto LABEL_9;
    if ( v4 != 5 )
    {
      *((_BYTE *)this + 72) = 0;
      return;
    }
  }
  if ( v4 != 4 )
  {
    Short = CUtlBuffer::GetShort(this: buf);
    goto LABEL_17;
  }
LABEL_9:
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    ++buf->m_Get;
  Short = CUtlBuffer::GetInt(this: buf);
LABEL_17:
  memset(&pt, 0, 10);
  memset(&pt.m_uiStartByte, 0, 12);
  pt.m_bSelected = false;
  if ( v5 != 5 )
  {
    if ( v5 == 4 )
    {
      if ( Short != 0 )
      {
        for ( bufc = (CUtlBuffer *)Short; bufc != nullptr; bufc = (CUtlBuffer *)((char *)bufc - 1) )
        {
          Int = CUtlBuffer::GetInt(this: buf);
          CUtlBuffer::GetType<float>(this: buf, dest: &et);
          CUtlBuffer::GetType<float>(this: buf, dest: st);
          pt.m_flStartTime = et;
          pt.m_nPhonemeCode = Int;
          pt.m_flEndTime = st[0];
          CSentence::AddRuntimePhoneme(this, src: &pt);
        }
      }
      v18 = CUtlBuffer::GetInt(this: buf);
      if ( v18 > 0 )
      {
        for ( bufd = (CUtlBuffer *)v18; bufd != nullptr; bufd = (CUtlBuffer *)((char *)bufd - 1) )
        {
          sample.selected = false;
          CUtlBuffer::GetType<float>(this: buf, dest: &et);
          sample.time = et;
          CUtlBuffer::GetType<float>(this: buf, dest: st);
          m_Size = this->m_EmphasisSamples.m_Size;
          m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
          sample.value = st[0];
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
              this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_EmphasisSamples.m_Size;
          m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
          v22 = this->m_EmphasisSamples.m_Size - m_Size - 1;
          this->m_EmphasisSamples.m_pElements = m_pMemory;
          if ( v22 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v22);
          v23 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
          if ( v23 != nullptr )
            *v23 = sample;
        }
      }
      v24 = CUtlBuffer::GetInt(this: buf) == 0;
      goto LABEL_67;
    }
    if ( Short != 0 )
    {
      for ( bufe = (CUtlBuffer *)Short; bufe != nullptr; bufe = (CUtlBuffer *)((char *)bufe - 1) )
      {
        v25 = CUtlBuffer::GetShort(this: buf);
        CUtlBuffer::GetType<float>(this: buf, dest: &et);
        CUtlBuffer::GetType<float>(this: buf, dest: st);
        pt.m_flStartTime = et;
        pt.m_nPhonemeCode = v25;
        pt.m_flEndTime = st[0];
        CSentence::AddRuntimePhoneme(this, src: &pt);
      }
    }
    v26 = CUtlBuffer::GetShort(this: buf);
    if ( v26 > 0 )
    {
      for ( buff = (CUtlBuffer *)v26; buff != nullptr; buff = (CUtlBuffer *)((char *)buff - 1) )
      {
        sample.selected = false;
        CUtlBuffer::GetType<float>(this: buf, dest: &et);
        sample.time = et;
        v27 = CUtlBuffer::GetShort(this: buf);
        v28 = this->m_EmphasisSamples.m_Size;
        v29 = v27;
        v30 = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
        sample.value = (float)v29 * 0.000030518509;
        if ( v28 + 1 > v30 )
          CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
            this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
            num: v28 - v30 + 1);
        ++this->m_EmphasisSamples.m_Size;
        v31 = this->m_EmphasisSamples.m_Memory.m_pMemory;
        v32 = this->m_EmphasisSamples.m_Size - v28 - 1;
        this->m_EmphasisSamples.m_pElements = v31;
        if ( v32 > 0 )
          _V_memmove(dest: &v31[v28 + 1], src: &v31[v28], count: 12 * v32);
        v33 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v28];
        if ( v33 != nullptr )
          *v33 = sample;
      }
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v16 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
      goto LABEL_66;
    }
LABEL_65:
    v16 = 0;
    goto LABEL_66;
  }
  if ( Short != 0 )
  {
    for ( i = Short; i != 0; --i )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        bufa = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        bufa = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        bufa = 0;
      }
      st[0] = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      et = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      pt.m_nPhonemeCode = ByteCodeToCode(byteCode: bufa);
      pt.m_flStartTime = st[0];
      pt.m_flEndTime = et;
      CSentence::AddRuntimePhoneme(this, src: &pt);
    }
  }
  v8 = CUtlBuffer::GetShort(this: buf);
  if ( v8 > 0 )
  {
    for ( bufb = (CUtlBuffer *)v8; bufb != nullptr; bufb = (CUtlBuffer *)((char *)bufb - 1) )
    {
      sample.selected = false;
      sample.time = (float)((float)CUtlBuffer::GetShort(this: buf) * 5.0) * 0.001;
      v9 = CUtlBuffer::GetShort(this: buf);
      v10 = this->m_EmphasisSamples.m_Size;
      v11 = v9;
      v12 = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      sample.value = (float)v11 * 0.000030518509;
      if ( v10 + 1 > v12 )
        CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_EmphasisSamples,
          num: v10 - v12 + 1);
      ++this->m_EmphasisSamples.m_Size;
      v13 = this->m_EmphasisSamples.m_Memory.m_pMemory;
      v14 = this->m_EmphasisSamples.m_Size - v10 - 1;
      this->m_EmphasisSamples.m_pElements = v13;
      if ( v14 > 0 )
        _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 12 * v14);
      v15 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v10];
      if ( v15 != nullptr )
        *v15 = sample;
    }
  }
  if ( !CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    goto LABEL_65;
  v16 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
  ++buf->m_Get;
LABEL_66:
  v24 = v16 == 0;
LABEL_67:
  *((_BYTE *)this + 74) = !v24;
  *((_BYTE *)this + 72) = 1;
  free(pMem: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00422070
// Name: public: void CSentence::InitFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1000h] BYREF

  CSentence::Reset(this);
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  if ( _V_stricmp(s1: pString, s2: "VERSION") == 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( atof(nptr: pString) == 1.0 )
    {
      CSentence::ParseDataVersionOnePointZero(this, buf);
      *((_BYTE *)this + 72) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422100
// Name: public: void CSentence::InitFromDataChunk(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromDataChunk(CSentence *this, void *data, int size)
{
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::EnsureCapacity(this: &buf, num: size);
  CUtlBuffer::Put(this: &buf, pMem: data, size);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: size);
  CSentence::InitFromBuffer(this, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004B3FD0
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
// Address: 0x004B4140
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
    CUtlMemory<AudioConversion_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x004B47F0
// Name: public: int CUtlVector<struct CDmElementDictionary::DeletionInfo_t,class CUtlMemory<struct CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::DeletionInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B5890
// Name: public: int CUtlVector<short,class CUtlMemory<short,int>>::Find(short const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<short,CUtlMemory<short,int>>::Find(
        CUtlVector<short,CUtlMemory<short,int> > *this,
        const __int16 *src)
{
  int m_Size; // edx
  int result; // eax
  __int16 *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B5A00
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this)
{
  bool v2; // sf
  CVTFTexture::ResourceMemorySection *m_pMemory; // eax

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
// Address: 0x004B5DF0
// Name: public: int CUtlVector<struct SceneFile_t,class CUtlMemory<struct SceneFile_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::InsertBefore(
        CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SceneFile_t *m_pMemory; // ecx
  int v6; // eax
  SceneFile_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SceneFile_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 96 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &v7->fileName);
    CUtlBuffer::CUtlBuffer(this: &v7->compiledBuffer, growSize: 0, initSize: 0, nFlags: 0);
    v7->soundList.m_Memory.m_pMemory = nullptr;
    v7->soundList.m_Memory.m_nAllocationCount = 0;
    v7->soundList.m_Memory.m_nGrowSize = 0;
    v7->soundList.m_Size = 0;
    v7->soundList.m_pElements = nullptr;
    v7->msecs = 0;
    v7->lastspeak_msecs = 0;
    v7->crcFileName = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004B5EE0
// Name: public: void CUtlVector<struct SceneFile_t,class CUtlMemory<struct SceneFile_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::RemoveAll(
        CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 96 * v1;
    v6 = 96 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 22) = 0;
      if ( *((int *)v3 + 21) >= 0 )
      {
        if ( *((_DWORD *)v3 + 19) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 19));
          *((_DWORD *)v3 + 19) = 0;
        }
        *((_DWORD *)v3 + 20) = 0;
      }
      v4 = *((void **)v3 + 19);
      *((_DWORD *)v3 + 23) = v4;
      if ( *((int *)v3 + 21) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 19) = 0;
        }
        *((_DWORD *)v3 + 20) = 0;
      }
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      this = v5;
      --v1;
      v2 = v6 - 96;
      v6 -= 96;
    }
    while ( v1 >= 0 );
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7400
// Name: public: CUtlVector<struct SceneFile_t,class CUtlMemory<struct SceneFile_t,int>>::~CUtlVector<struct SceneFile_t,class CUtlMemory<struct SceneFile_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::~CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>(
        CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int> > *this)
{
  bool v2; // sf
  SceneFile_t *m_pMemory; // eax

  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::RemoveAll(this);
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
// Address: 0x004B8700
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
// Address: 0x004BCB70
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
// Address: 0x004BCBF0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004BCE10
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
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int> *)this,
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
// Address: 0x004BCEA0
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
// Address: 0x004BCF40
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
// Address: 0x004BDC10
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
// Address: 0x004BEDE0
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
// Address: 0x004BEE40
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
// Address: 0x004C3010
// Name: public: void CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::Sort(int (*)(class CUtlSymbolLarge const __near *,class CUtlSymbolLarge const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::Sort(
        CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  CUtlSymbolLarge::<unnamed_type_u> v6; // ecx
  CUtlSymbolLarge *v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6.m_Id = (int)this->m_Memory.m_pMemory[j - 1].u;
            v7 = &this->m_Memory.m_pMemory[j];
            v7[-1].u.m_Id = v7->u.m_Id;
            v7->u.m_Id = v6.m_Id;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C3C80
// Name: public: void CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::FastRemove(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  CDataModel::ElementIdHandlePair_t *m_pMemory; // edx
  int v4; // eax
  __int64 v5; // xmm0_8
  CDataModel::ElementIdHandlePair_t *v6; // eax
  CDataModel::ElementIdHandlePair_t *v7; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v4 = m_Size;
      v5 = *(_QWORD *)this->m_Memory.m_pMemory[v4 - 1].m_id.m_Value;
      v6 = &this->m_Memory.m_pMemory[v4 - 1];
      *(_QWORD *)m_pMemory[elem].m_id.m_Value = v5;
      v7 = &m_pMemory[elem];
      *(_QWORD *)&v7->m_id.m_Value[8] = *(_QWORD *)&v6->m_id.m_Value[8];
      v7->m_ref = v6->m_ref;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4040
// Name: public: int CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolLarge *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlSymbolLarge *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->u.m_Id = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C65D0
// Name: public: int CUtlVector<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<CDmAttribute,21>::EntryType_t,CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,CUtlMemory<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C6640
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(int,struct CDataModel::ElementIdHandlePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        const CDataModel::ElementIdHandlePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v7; // eax
  CDataModel::ElementIdHandlePair_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDataModel::ElementIdHandlePair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CDataModel::ElementIdHandlePair_t::ElementIdHandlePair_t(this: v8, that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004CB200
// Name: public: class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> __near & CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *__thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(
        CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *this,
        const CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *other)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v2; // esi
  int m_Size; // edi
  int v4; // eax
  int v5; // edi
  _DWORD *v6; // ebx
  CUtlMemory<S3RGBA,int> *v7; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v10; // eax
  int i; // eax
  bool v12; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v2 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this;
  m_Size = other->m_Size;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll((CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
    this: v2,
    elem: v2->m_Size,
    num: m_Size);
  if ( m_Size <= 0 )
    return (CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *)v2;
  v4 = 0;
  v16 = 0;
  v15 = m_Size;
  while ( 1 )
  {
    v5 = *(int *)((char *)&other->m_Memory.m_pMemory->m_Size + v4);
    v6 = (DmElementHandle_t **)((char *)&other->m_Memory.m_pMemory->m_Memory.m_pMemory + v4);
    v7 = (CUtlMemory<S3RGBA,int> *)((char *)v2->m_Memory.m_pMemory + v4);
    v7[1].m_pMemory = nullptr;
    if ( v5 != 0 )
    {
      m_nAllocationCount = v7->m_nAllocationCount;
      if ( v5 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: v5 - m_nAllocationCount);
      v7[1].m_pMemory = (S3RGBA *)((char *)v7[1].m_pMemory + v5);
      m_pMemory = v7->m_pMemory;
      v10 = (int)v7[1].m_pMemory - v5;
      v7[1].m_nAllocationCount = (int)v7->m_pMemory;
      if ( v10 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: 4 * v10);
    }
    for ( i = 0; i < v5; ++i )
      v7->m_pMemory[i] = *(S3RGBA *)(*v6 + 4 * i);
    v4 = v16 + 20;
    v12 = v15-- == 1;
    v16 += 20;
    if ( v12 )
      break;
    v2 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CB330
// Name: public: CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this);
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
// Address: 0x004CE6D0
// Name: public: int CUtlVector<struct ElementPathItem_t,class CUtlMemory<struct ElementPathItem_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int>>::InsertBefore(
        CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ElementPathItem_t *m_pMemory; // ecx
  int v6; // eax
  ElementPathItem_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->hElement = DMELEMENT_HANDLE_INVALID;
    v7->hAttribute = DMATTRIBUTE_HANDLE_INVALID;
    v7->nIndex = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004CFE00
// Name: public: bool CUtlVector<class IDmNotify __near *,class CUtlMemory<class IDmNotify __near *,int>>::FindAndRemove(class IDmNotify __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
        CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *this,
        IDmNotify **src)
{
  int m_Size; // edx
  int v4; // eax
  IDmNotify **m_pMemory; // ebx
  IDmNotify **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D2FA0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::Find(enum DmElementHandle_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::Find(
        CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *this,
        const DmElementHandle_t *src)
{
  int m_Size; // edx
  int result; // eax
  DmElementHandle_t *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D3C20
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int num)
{
  DmeTime_t *m_pMemory; // edx
  unsigned int v4; // eax
  DmeTime_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (DmeTime_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (DmeTime_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3C80
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool *v4; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3CE0
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int num)
{
  Vector2D *m_pMemory; // edx
  unsigned int v4; // eax
  Vector2D *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 8 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3D40
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int num)
{
  CUtlBinaryBlock *m_pMemory; // edx
  unsigned int v4; // eax
  CUtlBinaryBlock *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CUtlBinaryBlock *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (CUtlBinaryBlock *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3DA0
// Name: public: void CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::EnsureCapacity(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int num)
{
  VMatrix *m_pMemory; // edx
  unsigned int v4; // eax
  VMatrix *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = num << 6;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3E00
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        const DmeTime_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v7; // eax
  DmeTime_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_tms = src->m_tms;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004D42C0
// Name: public: void CUtlVector<class CDmeHandle<class CDmElement,2>,class CUtlMemory<class CDmeHandle<class CDmElement,2>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int>>::Purge(
        CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CDmeHandle<CDmElement,2> *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel != nullptr )
      CDmeElementRefHelper::Unref(
        this: &this->m_Memory.m_pMemory[i],
        hElement: this->m_Memory.m_pMemory[i].m_handle,
        handleType: HT_UNDO);
  }
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
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
// Address: 0x004D4330
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  CUtlBinaryBlock *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ResourceCopy_t,int>::Grow((CUtlMemory<ResourceCopy_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v7, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DA710
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertBefore(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        float *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v7; // eax
  float *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DA780
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertBefore(int,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        bool *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v7; // eax
  bool *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DA7E0
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertMultipleBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DA850
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  Color *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = 0;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DA8E0
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  Vector2D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x004DA950
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResourceEntryInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DA9C0
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        const CVTFTexture::ResourceMemorySection *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v7; // eax
  CVTFTexture::ResourceMemorySection *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: &this->m_Memory,
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
// Address: 0x004DAA40
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  Vector4D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ResourceCopy_t,int>::Grow((CUtlMemory<ResourceCopy_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DAAC0
// Name: public: int CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DAB40
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ResourceCopy_t,int>::Grow((CUtlMemory<ResourceCopy_t,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DABB0
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertBefore(int,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        const VMatrix *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy((void *)&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DAC20
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: v9 << 6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DAC90
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ResourceCopy_t,int>::Grow((CUtlMemory<ResourceCopy_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004DAD00
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlBinaryBlock *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ResourceCopy_t,int>::Grow((CUtlMemory<ResourceCopy_t,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 16 * v10);
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
          CUtlBinaryBlock::CUtlBinaryBlock(this: v12, growSize: 0, initSize: 0);
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
// Address: 0x004DADA0
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  DmeTime_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_tms = 0x80000000;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004E8450
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlBinaryBlock *v3; // esi
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->m_nActualLength = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EFFA0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::FastRemove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf
  int m_Size; // eax
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  __int64 v8; // xmm0_8
  CUtlBinaryBlock *v9; // eax

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v7 = m_Size;
      v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v7 - 1].m_Memory.m_pMemory;
      v9 = &this->m_Memory.m_pMemory[v7 - 1];
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_pMemory = v8;
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_nGrowSize = *(_QWORD *)&v9->m_Memory.m_nGrowSize;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F0020
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::Remove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 16 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004F0090
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultiple(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int *v9; // esi
  bool v10; // sf
  bool v11; // zf
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]
  int elema; // [esp+18h] [ebp+8h]

  v5 = num;
  v6 = elem + num;
  v7 = elem + num - 1;
  v12 = elem + num;
  if ( v7 >= elem )
  {
    v8 = 16 * v7;
    elema = 16 * v7;
    v13 = num;
    do
    {
      v9 = (int *)((char *)this->m_Memory.m_pMemory + v8);
      v10 = v9[2] < 0;
      v9[3] = 0;
      if ( !v10 )
      {
        if ( *v9 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v9);
          v6 = v12;
          v8 = elema;
          *v9 = 0;
        }
        v9[1] = 0;
      }
      v8 -= 16;
      v11 = v13-- == 1;
      elema = v8;
    }
    while ( !v11 );
    v5 = num;
  }
  if ( this->m_Size - elem - v5 > 0 && v5 > 0 )
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[v6],
      count: 16 * (this->m_Size - elem - v5));
    v5 = num;
  }
  this->m_Size -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x004F4E80
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::CopyArray(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::CopyArray(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        const float *pArray,
        int size)
{
  int v3; // ebx
  int v4; // edi
  const float *v6; // ecx
  const float *v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  char *v10; // edx
  int v11; // ebx
  double v12; // st7
  char *v13; // edx
  int v14; // [esp+14h] [ebp-4h]

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: size);
  v6 = pArray;
  if ( size >= 4 )
  {
    v7 = pArray + 2;
    v8 = -8 - (_DWORD)pArray;
    v9 = ((unsigned int)(size - 4) >> 2) + 1;
    v14 = 8;
    v4 = 4 * v9;
    while ( 1 )
    {
      v10 = (char *)v7 + v8;
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory] = *(v7 - 2);
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 4] = *(v7 - 1);
      v11 = v14;
      v14 += 16;
      *(float *)((char *)this->m_Memory.m_pMemory + v11) = *v7;
      v12 = v7[1];
      v13 = (char *)v7 + 4 - (_DWORD)pArray;
      v7 += 4;
      *(float *)&v13[(unsigned int)this->m_Memory.m_pMemory] = v12;
      if ( --v9 == 0 )
        break;
      v8 = -8 - (_DWORD)pArray;
    }
    v3 = size;
    v6 = pArray;
  }
  for ( ; v4 < v3; ++v4 )
    this->m_Memory.m_pMemory[v4] = v6[v4];
}

//------------------------------------------------------------------------------
// Address: 0x004F4F30
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::CopyArray(bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::CopyArray(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        const bool *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x004F4FA0
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CopyArray(class Vector2D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CopyArray(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        const Vector2D *pArray,
        int size)
{
  int v3; // edi
  signed int v6; // edx
  int v7; // edx
  unsigned int v8; // edi
  float *p_y; // eax
  Vector2D *m_pMemory; // ecx
  char *v11; // edx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  Vector2D *v16; // eax
  unsigned int v17; // ecx
  double x; // st7
  int i; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]
  const Vector2D *pArraya; // [esp+20h] [ebp+8h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)this,
    elem: 0,
    num: size);
  v6 = 0;
  if ( size >= 4 )
  {
    v21 = -4 - (_DWORD)pArray;
    v7 = -20 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    v20 = 4 - (_DWORD)pArray;
    p_y = &pArray[2].y;
    pArraya = (const Vector2D *)(-20 - (_DWORD)pArray);
    i = 4 * v8;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v11 = (char *)p_y + v7;
      *(float *)&v11[(_DWORD)m_pMemory] = *(p_y - 5);
      *(float *)&v11[(_DWORD)m_pMemory + 4] = *(p_y - 4);
      v12 = (float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 8];
      *v12 = *(p_y - 3);
      v12[1] = *(p_y - 2);
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v21);
      *v13 = *(p_y - 1);
      v13[1] = *p_y;
      v14 = p_y[1];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v20);
      p_y += 8;
      --v8;
      *v15 = v14;
      v15[1] = *(p_y - 6);
      if ( v8 == 0 )
        break;
      v7 = (int)pArraya;
    }
    v3 = size;
    v6 = i;
  }
  for ( ; v6 < v3; v16[v17].y = pArray[v17].y )
  {
    v16 = this->m_Memory.m_pMemory;
    v17 = v6;
    x = pArray[v6++].x;
    v16[v17].x = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F5090
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CopyArray(class Vector4D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CopyArray(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        const Vector4D *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector4D *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  float *v16; // ecx
  int v17; // edi
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
    (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this,
    elem: 0,
    num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -24 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 6);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 5);
      v11[2] = *(p_z - 4);
      v11[3] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 16];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v12[3] = p_z[1];
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 8 - (_DWORD)pArray);
      *v13 = p_z[2];
      v13[1] = p_z[3];
      v13[2] = p_z[4];
      v13[3] = p_z[5];
      v14 = p_z[6];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      p_z += 16;
      --v7;
      *v15 = v14;
      v15[1] = *(p_z - 9);
      v15[2] = *(p_z - 8);
      v15[3] = *(p_z - 7);
      if ( v7 == 0 )
        break;
      v6 = -24 - (_DWORD)pArray;
    }
    v3 = size;
    v5 = i;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = (float *)((char *)v16 + (unsigned int)this->m_Memory.m_pMemory - 8 - (_DWORD)pArray);
      *v18 = *(v16 - 2);
      v16 += 4;
      --v17;
      v18[1] = *(v16 - 5);
      v18[2] = *(v16 - 4);
      v18[3] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F51C0
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        const QAngle *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  QAngle *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  double v13; // st7
  float *v14; // ecx
  float *v15; // ecx
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      *(float *)&v10[(_DWORD)m_pMemory + 4] = *(p_z - 4);
      *(float *)&v10[(_DWORD)m_pMemory + 8] = *(p_z - 3);
      v11 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v11 = *(p_z - 2);
      v11[1] = *(p_z - 1);
      v11[2] = *p_z;
      v12 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v12 = p_z[1];
      v12[1] = p_z[2];
      v12[2] = p_z[3];
      v13 = p_z[4];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      p_z += 12;
      --v7;
      *v14 = v13;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = i;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v15 = &pArray[v5].z;
    v16 = v3 - v5;
    do
    {
      v17 = *(v15 - 2);
      v18 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v15 - 8 - (_DWORD)pArray);
      v15 += 3;
      --v16;
      *v18 = v17;
      v18[1] = *(v15 - 4);
      v18[2] = *(v15 - 3);
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F6C80
// Name: public: class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x13 )
    return (CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F6CE0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x004F6D00
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x004F82D0
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0xF )
    return (CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F8340
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmAttribute::GetValue<class CUtlVector<int,class CUtlMemory<int,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x10 )
    return (CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F83A0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F8400
// Name: public: class CUtlVector<bool,class CUtlMemory<bool,int>> const __near & CDmAttribute::GetValue<class CUtlVector<bool,class CUtlMemory<bool,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x12 )
    return (CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F8460
// Name: public: class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Color,class CUtlMemory<class Color,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x16 )
    return (CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F84C0
// Name: public: class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x17 )
    return (CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F8520
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x18 )
    return (CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F8580
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x19 )
    return (CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F85E0
// Name: public: class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1A )
    return (CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F8640
// Name: public: class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1B )
    return (CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F86A0
// Name: public: class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1C )
    return (CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F8700
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004F8810
// Name: public: class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage);
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x14 )
    return (CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004FB700
// Name: public: CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>>::CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *__thiscall CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int>>::CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int>>(
        CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *this,
        int growSize,
        int initSize)
{
  CDmElement **m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004FF7B0
// Name: public: void CUtlVector<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,class CUtlMemory<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005006B0
// Name: public: virtual class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near & CDmElementFramework::GetSortedOperators(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *__thiscall CDmElementFramework::GetSortedOperators(
        CDmElementFramework *this)
{
  return &this->m_dependencyGraph.m_operators;
}

//------------------------------------------------------------------------------
// Address: 0x00501700
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(int,struct CDmElementDictionary::DmIdPair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(
        CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *this,
        int elem,
        const CDmElementDictionary::DmIdPair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::DmIdPair_t *m_pMemory; // ecx
  int v7; // eax
  CDmElementDictionary::DmIdPair_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00502430
// Name: public: int CUtlVector<struct CDmElementDictionary::AttributeInfo_t,class CUtlMemory<struct CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::AttributeInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00504820
// Name: public: int CUtlVector<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,class CUtlMemory<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0050E200
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmElement::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(this: Attribute);
  else
    return &`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0050E300
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *,class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0050E370
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *,class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0050ED70
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0050EDD0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00515150
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
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
// Address: 0x00534970
// Name: public: int CUtlVector<struct ResourceCopy_t,class CUtlMemory<struct ResourceCopy_t,int>>::InsertBefore(int,struct ResourceCopy_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int>>::InsertBefore(
        CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int> > *this,
        int elem,
        const ResourceCopy_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResourceCopy_t *m_pMemory; // ecx
  int v7; // eax
  ResourceCopy_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ResourceCopy_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00539070
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int num)
{
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
  unsigned int v4; // eax
  CVTFTexture::ResourceMemorySection *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005390E0
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CVTFTexture::ResourceMemorySection *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        *(_QWORD *)&v11->m_nDataAllocSize = 0;
        v11->m_pData = nullptr;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

} // namespace makegamedata

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004019B0
// Name: public: Vector::Vector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::Vector(Vector *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004019C0
// Name: public: void CWordTag::SetWord(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::SetWord(CWordTag *this, const char *word)
{
  unsigned int v3; // kr00_4
  char *v4; // eax

  free(pMem: this->m_pszWord);
  this->m_pszWord = nullptr;
  if ( word != nullptr && *word != 0 )
  {
    v3 = strlen(word);
    v4 = (char *)operator new(nSize: v3 + 1);
    this->m_pszWord = v4;
    V_strncpy(pDest: v4, pSrc: word, maxLen: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A20
// Name: public: CBasePhonemeTag::CBasePhonemeTag(class CBasePhonemeTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CBasePhonemeTag *__thiscall CBasePhonemeTag::CBasePhonemeTag(CBasePhonemeTag *this, const CBasePhonemeTag *from)
{
  *this = *from;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401A40
// Name: public: void CSentence::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SetText(CSentence *this, const char *text)
{
  int v3; // esi
  char *v4; // eax

  free(pMem: this->m_szText);
  this->m_szText = nullptr;
  if ( text != nullptr && *text != 0 )
  {
    v3 = _V_strlen(str: text) + 1;
    v4 = (char *)operator new(nSize: v3);
    this->m_szText = v4;
    V_strncpy(pDest: v4, pSrc: text, maxLen: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A90
// Name: public: static int CSentence::CountWords(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSentence::CountWords(const char *str)
{
  const char *v1; // edx
  char v2; // cl
  int result; // eax

  v1 = str;
  if ( str == nullptr )
    return 0;
  v2 = *str;
  if ( *str == 0 )
    return 0;
  result = 1;
  do
  {
    if ( (unsigned __int8)v2 <= 0x20u )
    {
      ++result;
      if ( v2 == 0 )
        return result;
      while ( (unsigned __int8)v2 <= 0x20u )
      {
        v2 = *++v1;
        if ( v2 == 0 )
          return result;
      }
    }
    v2 = *++v1;
  }
  while ( v2 != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401AE0
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x00401B30
// Name: private: void CSentence::ParsePlaintext(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParsePlaintext(CSentence *this, CUtlBuffer *buf)
{
  bool v3; // zf
  int v4; // esi
  char *v5; // eax
  char pString[4096]; // [esp+8h] [ebp-2000h] BYREF
  char pDest[4096]; // [esp+1008h] [ebp-1000h] BYREF

  pDest[0] = 0;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncat(pDest, pSrc: pString, destBufferSize: 0x1000u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: " ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
  free(pMem: this->m_szText);
  v3 = pDest[0] == 0;
  this->m_szText = nullptr;
  if ( !v3 )
  {
    v4 = _V_strlen(str: pDest) + 1;
    v5 = (char *)operator new(nSize: v4);
    this->m_szText = v5;
    V_strncpy(pDest: v5, pSrc: pDest, maxLen: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C20
// Name: private: void CSentence::ParseOptions(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseOptions(CSentence *this, CUtlBuffer *buf)
{
  unsigned int v3; // eax
  char pString[4096]; // [esp+8h] [ebp-1200h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-200h] BYREF
  char nptr[256]; // [esp+1108h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_strlen(str: pString) == 0 )
      break;
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    if ( _V_stricmp(s1: pDest, s2: "voice_duck") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "checksum") == 0 )
      {
        v3 = atoi(nptr);
        *((_BYTE *)this + 73) = 1;
        this->m_uCheckSum = v3;
      }
    }
    else
    {
      *((_BYTE *)this + 74) = atoi(nptr) != 0;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401D50
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401DF0
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401E60
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401ED0
// Name: protected: bool CUtlBuffer::GetTypeText<int>(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<int>(CUtlBuffer *this, int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401F40
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401FB0
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402020
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004020A0
// Name: public: void CByteswap::SwapBufferToTargetEndian<int>(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402130
// Name: public: void CSentence::SaveToBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SaveToBuffer(CSentence *this, CUtlBuffer *buf)
{
  CSentence *v3; // edi
  const char *m_szText; // eax
  CWordTag *v5; // edi
  const char *m_pszWord; // eax
  int j; // ebx
  CPhonemeTag *v8; // eax
  const char *m_szPhoneme; // ecx
  int v10; // ebx
  int i; // [esp+28h] [ebp+8h]
  int ia; // [esp+28h] [ebp+8h]

  v3 = this;
  CUtlBuffer::Printf(this: buf, pFmt: "VERSION 1.0\n");
  CUtlBuffer::Printf(this: buf, pFmt: "PLAINTEXT\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_szText = v3->m_szText;
  if ( v3->m_szText == nullptr )
    m_szText = &pParentName;
  CUtlBuffer::Printf(this: buf, pFmt: "%s\n", m_szText);
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "WORDS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  i = 0;
  if ( v3->m_Words.m_Size > 0 )
  {
    do
    {
      v5 = v3->m_Words.m_Memory.m_pMemory[i];
      m_pszWord = v5->m_pszWord;
      if ( m_pszWord == nullptr )
        m_pszWord = &pParentName;
      CUtlBuffer::Printf(this: buf, pFmt: "WORD %s %.3f %.3f\n", m_pszWord, v5->m_flStartTime, v5->m_flEndTime);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      for ( j = 0; j < v5->m_Phonemes.m_Size; ++j )
      {
        v8 = v5->m_Phonemes.m_Memory.m_pMemory[j];
        m_szPhoneme = v8->m_szPhoneme;
        if ( m_szPhoneme == nullptr )
          m_szPhoneme = &pParentName;
        CUtlBuffer::Printf(
          this: buf,
          pFmt: "%i %s %.3f %.3f 1\n",
          v8->m_nPhonemeCode,
          m_szPhoneme,
          v8->m_flStartTime,
          v8->m_flEndTime);
      }
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      ++i;
      v3 = this;
    }
    while ( i < this->m_Words.m_Size );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "EMPHASIS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  if ( v3->m_EmphasisSamples.m_Size > 0 )
  {
    v10 = 0;
    ia = v3->m_EmphasisSamples.m_Size;
    do
    {
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "%f %f\n",
        v3->m_EmphasisSamples.m_Memory.m_pMemory[v10].time,
        v3->m_EmphasisSamples.m_Memory.m_pMemory[v10].value);
      ++v10;
      --ia;
    }
    while ( ia != 0 );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "OPTIONS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  CUtlBuffer::Printf(this: buf, pFmt: "voice_duck %d\n", *((_BYTE *)v3 + 74) != 0);
  if ( *((_BYTE *)v3 + 73) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "checksum %d\n", v3->m_uCheckSum);
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x00402350
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402390
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402440
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402480
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004024F0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402540
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025A0
// Name: private: void CSentence::ParseCloseCaption(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseCloseCaption(CSentence *this, CUtlBuffer *buf)
{
  int v2; // edi
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-2020h] BYREF
  char pString[4096]; // [esp+1008h] [ebp-1020h] BYREF
  char pDest[32]; // [esp+2008h] [ebp-20h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    while ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      if ( _V_stricmp(s1: pString, s2: "PHRASE") != 0 )
        break;
      memset(dst, value: 0, count: sizeof(dst));
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      V_strncpy(pDest, pSrc: pString, maxLen: 32);
      if ( _V_stricmp(s1: pDest, s2: "unicode") != 0 )
        _V_stricmp(s1: pDest, s2: "char");
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      v2 = atoi(nptr: pString);
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::Get(this: buf, pMem: dst, size: v2);
      dst[v2] = 0;
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402790
// Name: public: void CSentence::ClearRuntimePhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ClearRuntimePhonemes(CSentence *this)
{
  for ( ; this->m_RunTimePhonemes.m_Size > 0; --this->m_RunTimePhonemes.m_Size )
  {
    free(pMem: *(void **)this->m_RunTimePhonemes.m_Memory.m_pMemory);
    if ( this->m_RunTimePhonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_RunTimePhonemes.m_Memory.m_pMemory,
        src: this->m_RunTimePhonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_RunTimePhonemes.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x004027E0
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
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
// Address: 0x00402810
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004028B0
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402950
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004029F0
// Name: public: CWordTag::~CWordTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::~CWordTag(CWordTag *this)
{
  CPhonemeTag *v2; // edi

  free(pMem: this->m_pszWord);
  for ( ; this->m_Phonemes.m_Size > 0; --this->m_Phonemes.m_Size )
  {
    v2 = *this->m_Phonemes.m_Memory.m_pMemory;
    if ( v2 != nullptr )
    {
      free(pMem: v2->m_szPhoneme);
      free(pMem: v2);
    }
    if ( this->m_Phonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Phonemes.m_Memory.m_pMemory,
        src: this->m_Phonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Phonemes.m_Size - 1));
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Phonemes);
}

//------------------------------------------------------------------------------
// Address: 0x00402A60
// Name: public: CSentence::CSentence(void)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::CSentence(CSentence *this)
{
  this->m_Words.m_Memory.m_pMemory = nullptr;
  this->m_Words.m_Memory.m_nAllocationCount = 0;
  this->m_Words.m_Memory.m_nGrowSize = 0;
  this->m_Words.m_Size = 0;
  this->m_Words.m_pElements = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_pMemory = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_nAllocationCount = 0;
  this->m_RunTimePhonemes.m_Memory.m_nGrowSize = 0;
  this->m_RunTimePhonemes.m_Size = 0;
  this->m_RunTimePhonemes.m_pElements = nullptr;
  this->m_EmphasisSamples.m_Memory.m_pMemory = nullptr;
  this->m_EmphasisSamples.m_Memory.m_nAllocationCount = 0;
  this->m_EmphasisSamples.m_Memory.m_nGrowSize = 0;
  this->m_EmphasisSamples.m_Size = 0;
  this->m_EmphasisSamples.m_pElements = nullptr;
  this->m_nResetWordBase = 0;
  this->m_szText = nullptr;
  this->m_uCheckSum = 0;
  *(_WORD *)((char *)this + 73) = 0;
  *((_BYTE *)this + 72) = 0;
  *((_BYTE *)this + 75) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402AB0
// Name: public: void CSentence::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Reset(CSentence *this)
{
  bool v2; // cc
  CWordTag **m_pMemory; // eax
  CWordTag *v4; // edi

  v2 = this->m_Words.m_Size <= 0;
  this->m_nResetWordBase = 0;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_Words.m_Memory.m_pMemory;
      v4 = *m_pMemory;
      if ( *m_pMemory != nullptr )
      {
        CWordTag::~CWordTag(this: *m_pMemory);
        free(pMem: v4);
      }
      if ( this->m_Words.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Words.m_Memory.m_pMemory,
          src: this->m_Words.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Words.m_Size - 1));
      --this->m_Words.m_Size;
    }
    while ( this->m_Words.m_Size > 0 );
  }
  this->m_EmphasisSamples.m_Size = 0;
  CSentence::ClearRuntimePhonemes(this);
}

//------------------------------------------------------------------------------
// Address: 0x00402B20
// Name: public: CWordTag::CWordTag(class CWordTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this, const CWordTag *from)
{
  CWordTag *v2; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Phonemes; // edi
  char *m_pszWord; // ebx
  unsigned int v5; // kr00_4
  char *v6; // eax
  unsigned int m_uiEndByte; // ecx
  int v8; // ebx
  CPhonemeTag *v9; // eax
  CPhonemeTag *v10; // esi
  CPhonemeTag *v11; // eoff
  unsigned int v12; // ecx
  char *m_szPhoneme; // eax
  const char *v14; // ebx
  int v15; // ebx
  char *v16; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v19; // ecx
  int v20; // eax
  CPhonemeTag **v21; // esi
  int p; // [esp+Ch] [ebp-Ch]
  const char *newPhoneme; // [esp+14h] [ebp-4h]
  CPhonemeTag *newPhonemea; // [esp+14h] [ebp-4h]

  v2 = this;
  p_m_Phonemes = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Phonemes;
  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_pszWord = nullptr;
  m_pszWord = from->m_pszWord;
  free(pMem: nullptr);
  v2->m_pszWord = nullptr;
  if ( m_pszWord != nullptr && *m_pszWord != 0 )
  {
    v5 = strlen(m_pszWord);
    v6 = (char *)operator new(nSize: v5 + 1);
    this->m_pszWord = v6;
    V_strncpy(pDest: v6, pSrc: m_pszWord, maxLen: v5 + 1);
    v2 = this;
  }
  m_uiEndByte = from->m_uiEndByte;
  v2->m_uiStartByte = from->m_uiStartByte;
  v2->m_uiEndByte = m_uiEndByte;
  v2->m_flStartTime = from->m_flStartTime;
  v8 = 0;
  p = 0;
  v2->m_flEndTime = from->m_flEndTime;
  v2->m_bSelected = from->m_bSelected;
  if ( from->m_Phonemes.m_Size <= 0 )
    return v2;
  do
  {
    v9 = (CPhonemeTag *)operator new(nSize: 0x1Cu);
    v10 = v9;
    if ( v9 != nullptr )
    {
      v11 = from->m_Phonemes.m_Memory.m_pMemory[v8];
      *(_QWORD *)&v9->m_flStartTime = *(_QWORD *)&v11->m_flStartTime;
      *(_DWORD *)&v9->m_nPhonemeCode = *(_DWORD *)&v11->m_nPhonemeCode;
      v12 = v11->m_uiEndByte;
      v9->m_uiStartByte = v11->m_uiStartByte;
      v9->m_uiEndByte = v12;
      v9->m_bSelected = v11->m_bSelected;
      v9->m_szPhoneme = nullptr;
      m_szPhoneme = v11->m_szPhoneme;
      if ( m_szPhoneme != nullptr )
      {
        v14 = m_szPhoneme;
        newPhoneme = m_szPhoneme;
      }
      else
      {
        newPhoneme = &pParentName;
        v14 = &pParentName;
      }
      free(pMem: nullptr);
      v10->m_szPhoneme = nullptr;
      if ( v14 != nullptr && *v14 != 0 )
      {
        v15 = _V_strlen(str: v14) + 1;
        v16 = (char *)operator new(nSize: v15);
        v10->m_szPhoneme = v16;
        V_strncpy(pDest: v16, pSrc: newPhoneme, maxLen: v15);
      }
      v8 = p;
      newPhonemea = v10;
    }
    else
    {
      newPhonemea = nullptr;
    }
    m_pMemory = p_m_Phonemes[1].m_pMemory;
    m_nAllocationCount = p_m_Phonemes->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Phonemes, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_Phonemes[1].m_pMemory;
    v19 = p_m_Phonemes->m_pMemory;
    v20 = (char *)p_m_Phonemes[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Phonemes[1].m_nAllocationCount = (int)p_m_Phonemes->m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[(_DWORD)m_pMemory + 1], src: &v19[(_DWORD)m_pMemory], count: 4 * v20);
    v21 = (CPhonemeTag **)&p_m_Phonemes->m_pMemory[(_DWORD)m_pMemory];
    if ( v21 != nullptr )
      *v21 = newPhonemea;
    p = ++v8;
  }
  while ( v8 < from->m_Phonemes.m_Size );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402CE0
// Name: public: CSentence::~CSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::~CSentence(CSentence *this)
{
  CSentence::Reset(this);
  free(pMem: this->m_szText);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_EmphasisSamples);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RunTimePhonemes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Words);
}

//------------------------------------------------------------------------------
// Address: 0x00402D10
// Name: private: void CSentence::ParseEmphasis(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseEmphasis(CSentence *this, CUtlBuffer *buf)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v6; // eax
  CEmphasisSample *v7; // eax
  int v8; // ecx
  char pString[4096]; // [esp+8h] [ebp-120Ch] BYREF
  char nptr[256]; // [esp+1008h] [ebp-20Ch] BYREF
  char pDest[256]; // [esp+1108h] [ebp-10Ch] BYREF
  __int64 v12; // [esp+1208h] [ebp-Ch]
  int v13; // [esp+1210h] [ebp-4h]

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    LOBYTE(v13) = 0;
    *(float *)&v12 = atof(nptr: pDest);
    *((float *)&v12 + 1) = atof(nptr);
    m_Size = this->m_EmphasisSamples.m_Size;
    m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
        this: (CUtlMemory<Extractor,int> *)&this->m_EmphasisSamples,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EmphasisSamples.m_Size;
    m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
    v6 = this->m_EmphasisSamples.m_Size - m_Size - 1;
    this->m_EmphasisSamples.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v6);
    v7 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
    {
      v8 = v13;
      *(_QWORD *)&v7->time = v12;
      *(_DWORD *)&v7->selected = v8;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402E60
// Name: public: void CSentence::AddWordTag(class CWordTag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::AddWordTag(CSentence *this, CWordTag *tag)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Words; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Words.m_Memory.m_nAllocationCount;
  p_m_Words = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Words;
  m_Size = this->m_Words.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Words, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Words[1].m_pMemory;
  m_pMemory = p_m_Words->m_pMemory;
  v6 = (int)p_m_Words[1].m_pMemory - m_Size - 1;
  p_m_Words[1].m_nAllocationCount = (int)p_m_Words->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Words->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)tag;
}

//------------------------------------------------------------------------------
// Address: 0x00402EC0
// Name: public: class CSentence __near & CSentence::operator=(class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::operator=(CSentence *this, const CSentence *src)
{
  CSentence *v2; // esi
  const CSentence *v3; // ebx
  const CWordTag *v4; // edi
  CWordTag *v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v9; // eax
  CWordTag **v10; // eax
  char *m_szText; // edi
  int v12; // esi
  char *v13; // eax
  int v14; // edi
  int v15; // eax
  CEmphasisSample *v16; // ecx
  int v17; // eax
  CEmphasisSample *v18; // eax
  CBasePhonemeTag *v19; // eax
  int v20; // edi
  _DWORD *v21; // eax
  CBasePhonemeTag *v22; // ebx
  int v23; // edi
  int v24; // eax
  CBasePhonemeTag **v25; // ecx
  int v26; // eax
  CBasePhonemeTag **v27; // eax
  __int64 full; // [esp+Ch] [ebp-34h]
  CWordTag *newWord; // [esp+34h] [ebp-Ch]
  CWordTag *newWorda; // [esp+34h] [ebp-Ch]
  CWordTag *newWordb; // [esp+34h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-4h]
  int ia; // [esp+3Ch] [ebp-4h]
  int ib; // [esp+3Ch] [ebp-4h]
  CEmphasisSample s; // 0:^3C.12

  v2 = this;
  CSentence::Reset(this);
  v3 = src;
  for ( i = 0; i < src->m_Words.m_Size; ++i )
  {
    v4 = src->m_Words.m_Memory.m_pMemory[i];
    v5 = (CWordTag *)operator new(nSize: 0x2Cu);
    if ( v5 != nullptr )
      newWord = CWordTag::CWordTag(this: v5, from: v4);
    else
      newWord = nullptr;
    m_Size = v2->m_Words.m_Size;
    m_nAllocationCount = v2->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_Words.m_Size;
    m_pMemory = v2->m_Words.m_Memory.m_pMemory;
    v9 = v2->m_Words.m_Size - m_Size - 1;
    v2->m_Words.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &v2->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = newWord;
  }
  m_szText = src->m_szText;
  if ( src->m_szText == nullptr )
    m_szText = (char *)&pParentName;
  free(pMem: v2->m_szText);
  v2->m_szText = nullptr;
  if ( m_szText != nullptr && *m_szText != 0 )
  {
    v12 = _V_strlen(str: m_szText) + 1;
    v13 = (char *)operator new(nSize: v12);
    this->m_szText = v13;
    V_strncpy(pDest: v13, pSrc: m_szText, maxLen: v12);
    v2 = this;
  }
  v2->m_nResetWordBase = src->m_nResetWordBase;
  if ( src->m_EmphasisSamples.m_Size > 0 )
  {
    ia = 0;
    newWorda = (CWordTag *)src->m_EmphasisSamples.m_Size;
    do
    {
      v14 = v2->m_EmphasisSamples.m_Size;
      s = src->m_EmphasisSamples.m_Memory.m_pMemory[ia];
      v15 = v2->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      if ( v14 + 1 > v15 )
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<Extractor,int> *)&v2->m_EmphasisSamples,
          num: v14 - v15 + 1);
      ++v2->m_EmphasisSamples.m_Size;
      v16 = v2->m_EmphasisSamples.m_Memory.m_pMemory;
      v17 = v2->m_EmphasisSamples.m_Size - v14 - 1;
      v2->m_EmphasisSamples.m_pElements = v16;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 12 * v17);
      v18 = &v2->m_EmphasisSamples.m_Memory.m_pMemory[v14];
      if ( v18 != nullptr )
        *v18 = s;
      ++ia;
      newWorda = (CWordTag *)((char *)newWorda - 1);
    }
    while ( newWorda != nullptr );
    v2 = this;
  }
  *((_BYTE *)v2 + 75) = *((_BYTE *)src + 75);
  newWordb = (CWordTag *)src->m_RunTimePhonemes.m_Size;
  ib = 0;
  if ( (int)newWordb > 0 )
  {
    do
    {
      v19 = v3->m_RunTimePhonemes.m_Memory.m_pMemory[ib];
      v20 = *(_DWORD *)&v19->m_nPhonemeCode;
      full = *(_QWORD *)&v19->m_flStartTime;
      v21 = operator new(nSize: 0xCu);
      if ( v21 != nullptr )
      {
        *v21 = 0;
        v21[1] = 0;
        *((_WORD *)v21 + 4) = 0;
        v22 = (CBasePhonemeTag *)v21;
      }
      else
      {
        v22 = nullptr;
      }
      *(_QWORD *)&v22->m_flStartTime = full;
      *(_DWORD *)&v22->m_nPhonemeCode = v20;
      v23 = v2->m_RunTimePhonemes.m_Size;
      v24 = v2->m_RunTimePhonemes.m_Memory.m_nAllocationCount;
      if ( v23 + 1 > v24 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_RunTimePhonemes,
          num: v23 - v24 + 1);
      ++v2->m_RunTimePhonemes.m_Size;
      v25 = v2->m_RunTimePhonemes.m_Memory.m_pMemory;
      v26 = v2->m_RunTimePhonemes.m_Size - v23 - 1;
      v2->m_RunTimePhonemes.m_pElements = v25;
      if ( v26 > 0 )
        _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 4 * v26);
      v27 = &v2->m_RunTimePhonemes.m_Memory.m_pMemory[v23];
      if ( v27 != nullptr )
        *v27 = v22;
      free(pMem: nullptr);
      v3 = src;
      ++ib;
    }
    while ( ib < (int)newWordb );
    v2 = this;
  }
  *((_BYTE *)v2 + 74) = *((_BYTE *)v3 + 74);
  *((_BYTE *)v2 + 73) = *((_BYTE *)v3 + 73);
  v2->m_uCheckSum = v3->m_uCheckSum;
  *((_BYTE *)v2 + 72) = *((_BYTE *)v3 + 72);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00403160
// Name: public: void CSentence::CreateEventWordDistribution(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::CreateEventWordDistribution(CSentence *this, const char *pszText, float flSentenceDuration)
{
  int v5; // eax
  float v6; // xmm0_4
  const char *v7; // edi
  char *v8; // esi
  char v9; // bl
  char v10; // bl
  _DWORD *v11; // eax
  CWordTag *v12; // ebx
  unsigned int v13; // kr04_4
  char *v14; // eax
  CSentence *v15; // ecx
  _DWORD *v16; // eax
  CWordTag *v17; // esi
  CSentence *v18; // ecx
  char word[260]; // [esp+8h] [ebp-10Ch] BYREF
  float v20; // [esp+10Ch] [ebp-8h]
  CSentence *v21; // [esp+110h] [ebp-4h]
  float wordStart; // [esp+11Ch] [ebp+8h]

  v21 = this;
  if ( pszText != nullptr )
  {
    v5 = CSentence::CountWords(str: pszText);
    if ( v5 > 0 )
    {
      v6 = (flSentenceDuration - 0.2) / (float)v5;
      wordStart = 0.1;
      CSentence::Reset(this);
      v7 = pszText;
      v8 = word;
      while ( *v7 != 0 )
      {
        v9 = *v7;
        if ( *v7 <= 32 || ispunct(c: v9) != 0 && v9 != 39 )
        {
          v10 = *v7;
          for ( *v8 = 0; v10 != 0; v10 = *++v7 )
          {
            if ( v10 > 32 && (ispunct(c: v10) == 0 || v10 == 39) )
              break;
          }
          if ( strlen(word) != 0 )
          {
            v11 = operator new(nSize: 0x2Cu);
            if ( v11 != nullptr )
            {
              v11[2] = 0;
              v11[3] = 0;
              v11[4] = 0;
              v11[5] = 0;
              v11[6] = 0;
              v11[10] = 0;
              v11[8] = 0;
              v11[9] = 0;
              *v11 = 0;
              v11[1] = 0;
              *((_BYTE *)v11 + 28) = 0;
              v12 = (CWordTag *)v11;
            }
            else
            {
              v12 = nullptr;
            }
            free(pMem: v12->m_pszWord);
            v12->m_pszWord = nullptr;
            if ( word[0] != 0 )
            {
              v13 = strlen(word);
              v14 = (char *)operator new(nSize: v13 + 1);
              v12->m_pszWord = v14;
              V_strncpy(pDest: v14, pSrc: word, maxLen: v13 + 1);
            }
            v15 = v21;
            v12->m_flStartTime = wordStart;
            v20 = wordStart + v6;
            v12->m_flEndTime = wordStart + v6;
            CSentence::AddWordTag(this: v15, tag: v12);
            wordStart = v20;
          }
          v8 = word;
        }
        else
        {
          *v8++ = *v7++;
        }
      }
      *v8 = 0;
      if ( strlen(word) != 0 )
      {
        v16 = operator new(nSize: 0x2Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[2] = 0;
          v16[3] = 0;
          v16[4] = 0;
          v16[5] = 0;
          v16[6] = 0;
          v16[10] = 0;
          v16[8] = 0;
          v16[9] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_BYTE *)v16 + 28) = 0;
          v17 = (CWordTag *)v16;
        }
        CWordTag::SetWord(this: v17, word);
        v18 = v21;
        v17->m_flStartTime = wordStart;
        v17->m_flEndTime = wordStart + v6;
        CSentence::AddWordTag(this: v18, tag: v17);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004033A0
// Name: private: void CSentence::ParseWords(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseWords(CSentence *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // ebx
  float *v3; // eax
  float *v4; // esi
  unsigned int v5; // kr00_4
  char *v6; // eax
  float *v7; // eax
  CSentence *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v12; // eax
  float **v13; // edi
  float *v14; // esi
  __int16 v15; // di
  _DWORD *v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  char *v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  void *v25; // [esp-8h] [ebp-1220h]
  char pString[4096]; // [esp+8h] [ebp-1210h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-210h] BYREF
  char str[256]; // [esp+1108h] [ebp-110h] BYREF
  CSentence *v29; // [esp+1208h] [ebp-10h]
  float v30; // [esp+120Ch] [ebp-Ch]
  float v31; // [esp+1210h] [ebp-8h]
  float *v32; // [esp+1214h] [ebp-4h]

  v2 = buf;
  v29 = this;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_stricmp(s1: pString, s2: "WORD") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v31 = atof(nptr: pString);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v30 = atof(nptr: pString);
    v3 = (float *)operator new(nSize: 0x2Cu);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3[2] = 0.0;
      v3[3] = 0.0;
      v3[4] = 0.0;
      v3[5] = 0.0;
      v3[6] = 0.0;
      v3[8] = 0.0;
      v3[9] = 0.0;
      *v3 = 0.0;
      v3[1] = 0.0;
      v3[10] = 0.0;
      *((_BYTE *)v3 + 28) = 0;
      free(pMem: nullptr);
      v4[10] = 0.0;
      if ( pDest[0] != 0 )
      {
        v5 = strlen(pDest);
        v6 = (char *)operator new(nSize: v5 + 1);
        *((_DWORD *)v4 + 10) = v6;
        V_strncpy(pDest: v6, pSrc: pDest, maxLen: v5 + 1);
      }
      v32 = v4;
    }
    else
    {
      v32 = nullptr;
    }
    v7 = v32;
    v8 = v29;
    *v32 = v31;
    v7[1] = v30;
    m_Size = v8->m_Words.m_Size;
    m_nAllocationCount = v8->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v8->m_Words.m_Size;
    m_pMemory = v8->m_Words.m_Memory.m_pMemory;
    v12 = v8->m_Words.m_Size - m_Size - 1;
    v8->m_Words.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = (float **)&v8->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v32;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      v14 = v32;
      do
      {
        v15 = atoi(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        V_strncpy(pDest: str, pSrc: pString, maxLen: 256);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v30 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v31 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        atof(nptr: pString);
        v16 = operator new(nSize: 0x1Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[6] = 0;
          v16[4] = 0;
          v16[5] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_WORD *)v16 + 4) = 0;
          *((_BYTE *)v16 + 12) = 0;
          v17 = v16;
        }
        v25 = (void *)v17[6];
        *((_WORD *)v17 + 4) = v15;
        free(pMem: v25);
        v17[6] = 0;
        if ( str[0] != 0 )
        {
          v18 = _V_strlen(str) + 1;
          v19 = (char *)operator new(nSize: v18);
          v17[6] = v19;
          V_strncpy(pDest: v19, pSrc: str, maxLen: v18);
        }
        *(float *)v17 = v30;
        *((float *)v17 + 1) = v31;
        v20 = *((_DWORD *)v14 + 5);
        v21 = *((_DWORD *)v14 + 3);
        if ( v20 + 1 > v21 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(v14 + 2),
            num: v20 - v21 + 1);
        ++*((_DWORD *)v14 + 5);
        v22 = *((_DWORD *)v14 + 2);
        v23 = *((_DWORD *)v14 + 5) - v20 - 1;
        *((_DWORD *)v14 + 6) = v22;
        if ( v23 > 0 )
          _V_memmove(dest: (void *)(v22 + 4 * v20 + 4), src: (const void *)(v22 + 4 * v20), count: 4 * v23);
        v24 = (_DWORD *)(*((_DWORD *)v14 + 2) + 4 * v20);
        if ( v24 != nullptr )
          *v24 = v17;
        CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
        v2 = buf;
      }
      while ( _V_stricmp(s1: pString, s2: "}") != 0 );
    }
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004037C0
// Name: private: void CSentence::ParseDataVersionOnePointZero(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseDataVersionOnePointZero(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1100h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( strlen(pString) != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    if ( _V_stricmp(s1: pDest, s2: "PLAINTEXT") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "WORDS") != 0 )
      {
        if ( _V_stricmp(s1: pDest, s2: "EMPHASIS") != 0 )
        {
          if ( _V_stricmp(s1: pDest, s2: "CLOSECAPTION") != 0 )
          {
            if ( _V_stricmp(s1: pDest, s2: "OPTIONS") == 0 )
              CSentence::ParseOptions(this, buf);
          }
          else
          {
            CSentence::ParseCloseCaption(this, buf);
          }
        }
        else
        {
          CSentence::ParseEmphasis(this, buf);
        }
      }
      else
      {
        CSentence::ParseWords(this, buf);
      }
    }
    else
    {
      CSentence::ParsePlaintext(this, buf);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403930
// Name: public: void CSentence::InitFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1000h] BYREF

  CSentence::Reset(this);
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  if ( _V_stricmp(s1: pString, s2: "VERSION") == 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( atof(nptr: pString) == 1.0 )
    {
      CSentence::ParseDataVersionOnePointZero(this, buf);
      *((_BYTE *)this + 72) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004039C0
// Name: public: void CSentence::InitFromDataChunk(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromDataChunk(CSentence *this, void *data, int size)
{
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::EnsureCapacity(this: &buf, num: size);
  CUtlBuffer::Put(this: &buf, pMem: data, size);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: size);
  CSentence::InitFromBuffer(this, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00403A30
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

} // namespace phogen

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: static char const __near * CSentence::NameForLanguage(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSentence::NameForLanguage(unsigned int language)
{
  if ( language > 0xB )
    return "unknown_language";
  else
    return g_CCLanguageLookup[language].name;
}

//------------------------------------------------------------------------------
// Address: 0x00401020
// Name: public: void CSentence::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SetText(CSentence *this, const char *text)
{
  int v3; // esi
  char *v4; // eax

  free(pMem: this->m_szText);
  this->m_szText = nullptr;
  if ( text != nullptr && *text != 0 )
  {
    v3 = _V_strlen(str: text) + 1;
    v4 = (char *)operator new(nSize: v3);
    this->m_szText = v4;
    V_strncpy(pDest: v4, pSrc: text, maxLen: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401070
// Name: public: char const __near * CSentence::GetText(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSentence::GetText(CSentence *this)
{
  char *result; // eax

  result = this->m_szText;
  if ( this->m_szText == nullptr )
    return (char *)&WindowName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401080
// Name: private: void CSentence::ParsePlaintext(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParsePlaintext(CSentence *this, CUtlBuffer *buf)
{
  bool v3; // zf
  int v4; // esi
  char *v5; // eax
  char pString[4096]; // [esp+8h] [ebp-2000h] BYREF
  char pDest[4096]; // [esp+1008h] [ebp-1000h] BYREF

  pDest[0] = 0;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncat(pDest, pSrc: pString, destBufferSize: 0x1000u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: " ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
  free(pMem: this->m_szText);
  v3 = pDest[0] == 0;
  this->m_szText = nullptr;
  if ( !v3 )
  {
    v4 = _V_strlen(str: pDest) + 1;
    v5 = (char *)operator new(nSize: v4);
    this->m_szText = v5;
    V_strncpy(pDest: v5, pSrc: pDest, maxLen: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401170
// Name: private: void CSentence::ParseOptions(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseOptions(CSentence *this, CUtlBuffer *buf)
{
  unsigned int v3; // eax
  char pString[4096]; // [esp+8h] [ebp-1200h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-200h] BYREF
  char nptr[256]; // [esp+1108h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_strlen(str: pString) == 0 )
      break;
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    if ( _V_stricmp(s1: pDest, s2: "voice_duck") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "checksum") == 0 )
      {
        v3 = atoi(nptr);
        *((_BYTE *)this + 73) = 1;
        this->m_uCheckSum = v3;
      }
    }
    else
    {
      *((_BYTE *)this + 74) = atoi(nptr) != 0;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012A0
// Name: public: void CSentence::SaveToBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::SaveToBuffer(CSentence *this, CUtlBuffer *buf)
{
  CSentence *v3; // edi
  const char *m_szText; // eax
  CWordTag *v5; // edi
  const char *m_pszWord; // eax
  int j; // ebx
  CPhonemeTag *v8; // eax
  const char *m_szPhoneme; // ecx
  int v10; // ebx
  int i; // [esp+28h] [ebp+8h]
  int ia; // [esp+28h] [ebp+8h]

  v3 = this;
  CUtlBuffer::Printf(this: buf, pFmt: "VERSION 1.0\n");
  CUtlBuffer::Printf(this: buf, pFmt: "PLAINTEXT\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_szText = v3->m_szText;
  if ( v3->m_szText == nullptr )
    m_szText = &WindowName;
  CUtlBuffer::Printf(this: buf, pFmt: (const char *)&stru_44CCF8, m_szText);
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "WORDS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  i = 0;
  if ( v3->m_Words.m_Size > 0 )
  {
    do
    {
      v5 = v3->m_Words.m_Memory.m_pMemory[i];
      m_pszWord = v5->m_pszWord;
      if ( m_pszWord == nullptr )
        m_pszWord = &WindowName;
      CUtlBuffer::Printf(this: buf, pFmt: "WORD %s %.3f %.3f\n", m_pszWord, v5->m_flStartTime, v5->m_flEndTime);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      for ( j = 0; j < v5->m_Phonemes.m_Size; ++j )
      {
        v8 = v5->m_Phonemes.m_Memory.m_pMemory[j];
        m_szPhoneme = v8->m_szPhoneme;
        if ( m_szPhoneme == nullptr )
          m_szPhoneme = &WindowName;
        CUtlBuffer::Printf(
          this: buf,
          pFmt: "%i %s %.3f %.3f 1\n",
          v8->m_nPhonemeCode,
          m_szPhoneme,
          v8->m_flStartTime,
          v8->m_flEndTime);
      }
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      ++i;
      v3 = this;
    }
    while ( i < this->m_Words.m_Size );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "EMPHASIS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  if ( v3->m_EmphasisSamples.m_Size > 0 )
  {
    v10 = 0;
    ia = v3->m_EmphasisSamples.m_Size;
    do
    {
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "%f %f\n",
        v3->m_EmphasisSamples.m_Memory.m_pMemory[v10].time,
        v3->m_EmphasisSamples.m_Memory.m_pMemory[v10].value);
      ++v10;
      --ia;
    }
    while ( ia != 0 );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  CUtlBuffer::Printf(this: buf, pFmt: "OPTIONS\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  CUtlBuffer::Printf(this: buf, pFmt: "voice_duck %d\n", *((_BYTE *)v3 + 74) != 0);
  if ( *((_BYTE *)v3 + 73) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "checksum %d\n", v3->m_uCheckSum);
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x004014C0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401500
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401540
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401590
// Name: private: void CSentence::ParseCloseCaption(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseCloseCaption(CSentence *this, CUtlBuffer *buf)
{
  int v2; // edi
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-2020h] BYREF
  char pString[4096]; // [esp+1008h] [ebp-1020h] BYREF
  char pDest[32]; // [esp+2008h] [ebp-20h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    while ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      if ( _V_stricmp(s1: pString, s2: "PHRASE") != 0 )
        break;
      memset(dst, value: 0, count: sizeof(dst));
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      V_strncpy(pDest, pSrc: pString, maxLen: 32);
      if ( _V_stricmp(s1: pDest, s2: "unicode") != 0 )
        _V_stricmp(s1: pDest, s2: "char");
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      v2 = atoi(nptr: pString);
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::Get(this: buf, pMem: dst, size: v2);
      dst[v2] = 0;
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
        ++buf->m_Get;
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
      CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401780
// Name: public: void CSentence::ClearRuntimePhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ClearRuntimePhonemes(CSentence *this)
{
  for ( ; this->m_RunTimePhonemes.m_Size > 0; --this->m_RunTimePhonemes.m_Size )
  {
    free(pMem: *(void **)this->m_RunTimePhonemes.m_Memory.m_pMemory);
    if ( this->m_RunTimePhonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_RunTimePhonemes.m_Memory.m_pMemory,
        src: this->m_RunTimePhonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_RunTimePhonemes.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x004017D0
// Name: public: CWordTag::~CWordTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWordTag::~CWordTag(CWordTag *this)
{
  CPhonemeTag *v2; // edi

  free(pMem: this->m_pszWord);
  for ( ; this->m_Phonemes.m_Size > 0; --this->m_Phonemes.m_Size )
  {
    v2 = *this->m_Phonemes.m_Memory.m_pMemory;
    if ( v2 != nullptr )
    {
      free(pMem: v2->m_szPhoneme);
      free(pMem: v2);
    }
    if ( this->m_Phonemes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Phonemes.m_Memory.m_pMemory,
        src: this->m_Phonemes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Phonemes.m_Size - 1));
  }
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Phonemes);
}

//------------------------------------------------------------------------------
// Address: 0x00401840
// Name: public: CSentence::CSentence(void)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::CSentence(CSentence *this)
{
  this->m_Words.m_Memory.m_pMemory = nullptr;
  this->m_Words.m_Memory.m_nAllocationCount = 0;
  this->m_Words.m_Memory.m_nGrowSize = 0;
  this->m_Words.m_Size = 0;
  this->m_Words.m_pElements = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_pMemory = nullptr;
  this->m_RunTimePhonemes.m_Memory.m_nAllocationCount = 0;
  this->m_RunTimePhonemes.m_Memory.m_nGrowSize = 0;
  this->m_RunTimePhonemes.m_Size = 0;
  this->m_RunTimePhonemes.m_pElements = nullptr;
  this->m_EmphasisSamples.m_Memory.m_pMemory = nullptr;
  this->m_EmphasisSamples.m_Memory.m_nAllocationCount = 0;
  this->m_EmphasisSamples.m_Memory.m_nGrowSize = 0;
  this->m_EmphasisSamples.m_Size = 0;
  this->m_EmphasisSamples.m_pElements = nullptr;
  this->m_nResetWordBase = 0;
  this->m_szText = nullptr;
  this->m_uCheckSum = 0;
  *(_WORD *)((char *)this + 73) = 0;
  *((_BYTE *)this + 72) = 0;
  *((_BYTE *)this + 75) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401890
// Name: public: void CSentence::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::Reset(CSentence *this)
{
  bool v2; // cc
  CWordTag **m_pMemory; // eax
  CWordTag *v4; // edi

  v2 = this->m_Words.m_Size <= 0;
  this->m_nResetWordBase = 0;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_Words.m_Memory.m_pMemory;
      v4 = *m_pMemory;
      if ( *m_pMemory != nullptr )
      {
        CWordTag::~CWordTag(this: *m_pMemory);
        free(pMem: v4);
      }
      if ( this->m_Words.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Words.m_Memory.m_pMemory,
          src: this->m_Words.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Words.m_Size - 1));
      --this->m_Words.m_Size;
    }
    while ( this->m_Words.m_Size > 0 );
  }
  this->m_EmphasisSamples.m_Size = 0;
  CSentence::ClearRuntimePhonemes(this);
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: CWordTag::CWordTag(class CWordTag const __near &)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall CWordTag::CWordTag(CWordTag *this, const CWordTag *from)
{
  CWordTag *v2; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Phonemes; // edi
  char *m_pszWord; // ebx
  unsigned int v5; // kr00_4
  char *v6; // eax
  unsigned int m_uiEndByte; // ecx
  int v8; // ebx
  CPhonemeTag *v9; // eax
  CPhonemeTag *v10; // esi
  CPhonemeTag *v11; // eoff
  unsigned int v12; // ecx
  char *m_szPhoneme; // eax
  const char *v14; // ebx
  int v15; // ebx
  char *v16; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v19; // ecx
  int v20; // eax
  CPhonemeTag **v21; // esi
  int p; // [esp+Ch] [ebp-Ch]
  const char *newPhoneme; // [esp+14h] [ebp-4h]
  CPhonemeTag *newPhonemea; // [esp+14h] [ebp-4h]

  v2 = this;
  p_m_Phonemes = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Phonemes;
  this->m_Phonemes.m_Memory.m_pMemory = nullptr;
  this->m_Phonemes.m_Memory.m_nAllocationCount = 0;
  this->m_Phonemes.m_Memory.m_nGrowSize = 0;
  this->m_Phonemes.m_Size = 0;
  this->m_Phonemes.m_pElements = nullptr;
  this->m_pszWord = nullptr;
  m_pszWord = from->m_pszWord;
  free(pMem: nullptr);
  v2->m_pszWord = nullptr;
  if ( m_pszWord != nullptr && *m_pszWord != 0 )
  {
    v5 = strlen(m_pszWord);
    v6 = (char *)operator new(nSize: v5 + 1);
    this->m_pszWord = v6;
    V_strncpy(pDest: v6, pSrc: m_pszWord, maxLen: v5 + 1);
    v2 = this;
  }
  m_uiEndByte = from->m_uiEndByte;
  v2->m_uiStartByte = from->m_uiStartByte;
  v2->m_uiEndByte = m_uiEndByte;
  v2->m_flStartTime = from->m_flStartTime;
  v8 = 0;
  p = 0;
  v2->m_flEndTime = from->m_flEndTime;
  v2->m_bSelected = from->m_bSelected;
  if ( from->m_Phonemes.m_Size <= 0 )
    return v2;
  do
  {
    v9 = (CPhonemeTag *)operator new(nSize: 0x1Cu);
    v10 = v9;
    if ( v9 != nullptr )
    {
      v11 = from->m_Phonemes.m_Memory.m_pMemory[v8];
      *(_QWORD *)&v9->m_flStartTime = *(_QWORD *)&v11->m_flStartTime;
      *(_DWORD *)&v9->m_nPhonemeCode = *(_DWORD *)&v11->m_nPhonemeCode;
      v12 = v11->m_uiEndByte;
      v9->m_uiStartByte = v11->m_uiStartByte;
      v9->m_uiEndByte = v12;
      v9->m_bSelected = v11->m_bSelected;
      v9->m_szPhoneme = nullptr;
      m_szPhoneme = v11->m_szPhoneme;
      if ( m_szPhoneme != nullptr )
      {
        v14 = m_szPhoneme;
        newPhoneme = m_szPhoneme;
      }
      else
      {
        newPhoneme = &WindowName;
        v14 = &WindowName;
      }
      free(pMem: nullptr);
      v10->m_szPhoneme = nullptr;
      if ( v14 != nullptr && *v14 != 0 )
      {
        v15 = _V_strlen(str: v14) + 1;
        v16 = (char *)operator new(nSize: v15);
        v10->m_szPhoneme = v16;
        V_strncpy(pDest: v16, pSrc: newPhoneme, maxLen: v15);
      }
      v8 = p;
      newPhonemea = v10;
    }
    else
    {
      newPhonemea = nullptr;
    }
    m_pMemory = p_m_Phonemes[1].m_pMemory;
    m_nAllocationCount = p_m_Phonemes->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Phonemes, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_Phonemes[1].m_pMemory;
    v19 = p_m_Phonemes->m_pMemory;
    v20 = (char *)p_m_Phonemes[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Phonemes[1].m_nAllocationCount = (int)p_m_Phonemes->m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[(_DWORD)m_pMemory + 1], src: &v19[(_DWORD)m_pMemory], count: 4 * v20);
    v21 = (CPhonemeTag **)&p_m_Phonemes->m_pMemory[(_DWORD)m_pMemory];
    if ( v21 != nullptr )
      *v21 = newPhonemea;
    p = ++v8;
  }
  while ( v8 < from->m_Phonemes.m_Size );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401AC0
// Name: public: CSentence::~CSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::~CSentence(CSentence *this)
{
  CSentence::Reset(this);
  free(pMem: this->m_szText);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_EmphasisSamples);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_RunTimePhonemes);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Words);
}

//------------------------------------------------------------------------------
// Address: 0x00401AF0
// Name: private: void CSentence::ParseEmphasis(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseEmphasis(CSentence *this, CUtlBuffer *buf)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CEmphasisSample *m_pMemory; // ecx
  int v6; // eax
  CEmphasisSample *v7; // eax
  int v8; // ecx
  char pString[4096]; // [esp+8h] [ebp-120Ch] BYREF
  char nptr[256]; // [esp+1008h] [ebp-20Ch] BYREF
  char pDest[256]; // [esp+1108h] [ebp-10Ch] BYREF
  __int64 v12; // [esp+1208h] [ebp-Ch]
  int v13; // [esp+1210h] [ebp-4h]

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    V_strncpy(pDest: nptr, pSrc: pString, maxLen: 256);
    LOBYTE(v13) = 0;
    *(float *)&v12 = atof(nptr: pDest);
    *((float *)&v12 + 1) = atof(nptr);
    m_Size = this->m_EmphasisSamples.m_Size;
    m_nAllocationCount = this->m_EmphasisSamples.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
        this: (CUtlMemory<CAppSystemGroup::Module_t,int> *)&this->m_EmphasisSamples,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EmphasisSamples.m_Size;
    m_pMemory = this->m_EmphasisSamples.m_Memory.m_pMemory;
    v6 = this->m_EmphasisSamples.m_Size - m_Size - 1;
    this->m_EmphasisSamples.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v6);
    v7 = &this->m_EmphasisSamples.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
    {
      v8 = v13;
      *(_QWORD *)&v7->time = v12;
      *(_DWORD *)&v7->selected = v8;
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C40
// Name: public: class CSentence __near & CSentence::operator=(class CSentence const __near &)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CSentence::operator=(CSentence *this, const CSentence *src)
{
  CSentence *v2; // esi
  const CSentence *v3; // ebx
  const CWordTag *v4; // edi
  CWordTag *v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v9; // eax
  CWordTag **v10; // eax
  char *m_szText; // edi
  int v12; // esi
  char *v13; // eax
  int v14; // edi
  int v15; // eax
  CEmphasisSample *v16; // ecx
  int v17; // eax
  CEmphasisSample *v18; // eax
  CBasePhonemeTag *v19; // eax
  int v20; // edi
  _DWORD *v21; // eax
  CBasePhonemeTag *v22; // ebx
  int v23; // edi
  int v24; // eax
  CBasePhonemeTag **v25; // ecx
  int v26; // eax
  CBasePhonemeTag **v27; // eax
  __int64 full; // [esp+Ch] [ebp-34h]
  CWordTag *newWord; // [esp+34h] [ebp-Ch]
  CWordTag *newWorda; // [esp+34h] [ebp-Ch]
  CWordTag *newWordb; // [esp+34h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-4h]
  int ia; // [esp+3Ch] [ebp-4h]
  int ib; // [esp+3Ch] [ebp-4h]
  CEmphasisSample s; // 0:^3C.12

  v2 = this;
  CSentence::Reset(this);
  v3 = src;
  for ( i = 0; i < src->m_Words.m_Size; ++i )
  {
    v4 = src->m_Words.m_Memory.m_pMemory[i];
    v5 = (CWordTag *)operator new(nSize: 0x2Cu);
    if ( v5 != nullptr )
      newWord = CWordTag::CWordTag(this: v5, from: v4);
    else
      newWord = nullptr;
    m_Size = v2->m_Words.m_Size;
    m_nAllocationCount = v2->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_Words.m_Size;
    m_pMemory = v2->m_Words.m_Memory.m_pMemory;
    v9 = v2->m_Words.m_Size - m_Size - 1;
    v2->m_Words.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &v2->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = newWord;
  }
  m_szText = src->m_szText;
  if ( src->m_szText == nullptr )
    m_szText = (char *)&WindowName;
  free(pMem: v2->m_szText);
  v2->m_szText = nullptr;
  if ( m_szText != nullptr && *m_szText != 0 )
  {
    v12 = _V_strlen(str: m_szText) + 1;
    v13 = (char *)operator new(nSize: v12);
    this->m_szText = v13;
    V_strncpy(pDest: v13, pSrc: m_szText, maxLen: v12);
    v2 = this;
  }
  v2->m_nResetWordBase = src->m_nResetWordBase;
  if ( src->m_EmphasisSamples.m_Size > 0 )
  {
    ia = 0;
    newWorda = (CWordTag *)src->m_EmphasisSamples.m_Size;
    do
    {
      v14 = v2->m_EmphasisSamples.m_Size;
      s = src->m_EmphasisSamples.m_Memory.m_pMemory[ia];
      v15 = v2->m_EmphasisSamples.m_Memory.m_nAllocationCount;
      if ( v14 + 1 > v15 )
        CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
          this: (CUtlMemory<CAppSystemGroup::Module_t,int> *)&v2->m_EmphasisSamples,
          num: v14 - v15 + 1);
      ++v2->m_EmphasisSamples.m_Size;
      v16 = v2->m_EmphasisSamples.m_Memory.m_pMemory;
      v17 = v2->m_EmphasisSamples.m_Size - v14 - 1;
      v2->m_EmphasisSamples.m_pElements = v16;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 12 * v17);
      v18 = &v2->m_EmphasisSamples.m_Memory.m_pMemory[v14];
      if ( v18 != nullptr )
        *v18 = s;
      ++ia;
      newWorda = (CWordTag *)((char *)newWorda - 1);
    }
    while ( newWorda != nullptr );
    v2 = this;
  }
  *((_BYTE *)v2 + 75) = *((_BYTE *)src + 75);
  newWordb = (CWordTag *)src->m_RunTimePhonemes.m_Size;
  ib = 0;
  if ( (int)newWordb > 0 )
  {
    do
    {
      v19 = v3->m_RunTimePhonemes.m_Memory.m_pMemory[ib];
      v20 = *(_DWORD *)&v19->m_nPhonemeCode;
      full = *(_QWORD *)&v19->m_flStartTime;
      v21 = operator new(nSize: 0xCu);
      if ( v21 != nullptr )
      {
        *v21 = 0;
        v21[1] = 0;
        *((_WORD *)v21 + 4) = 0;
        v22 = (CBasePhonemeTag *)v21;
      }
      else
      {
        v22 = nullptr;
      }
      *(_QWORD *)&v22->m_flStartTime = full;
      *(_DWORD *)&v22->m_nPhonemeCode = v20;
      v23 = v2->m_RunTimePhonemes.m_Size;
      v24 = v2->m_RunTimePhonemes.m_Memory.m_nAllocationCount;
      if ( v23 + 1 > v24 )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_RunTimePhonemes,
          num: v23 - v24 + 1);
      ++v2->m_RunTimePhonemes.m_Size;
      v25 = v2->m_RunTimePhonemes.m_Memory.m_pMemory;
      v26 = v2->m_RunTimePhonemes.m_Size - v23 - 1;
      v2->m_RunTimePhonemes.m_pElements = v25;
      if ( v26 > 0 )
        _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 4 * v26);
      v27 = &v2->m_RunTimePhonemes.m_Memory.m_pMemory[v23];
      if ( v27 != nullptr )
        *v27 = v22;
      free(pMem: nullptr);
      v3 = src;
      ++ib;
    }
    while ( ib < (int)newWordb );
    v2 = this;
  }
  *((_BYTE *)v2 + 74) = *((_BYTE *)v3 + 74);
  *((_BYTE *)v2 + 73) = *((_BYTE *)v3 + 73);
  v2->m_uCheckSum = v3->m_uCheckSum;
  *((_BYTE *)v2 + 72) = *((_BYTE *)v3 + 72);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00401EE0
// Name: private: void CSentence::ParseWords(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseWords(CSentence *this, CUtlBuffer *buf)
{
  CUtlBuffer *v2; // ebx
  float *v3; // eax
  float *v4; // esi
  unsigned int v5; // kr00_4
  char *v6; // eax
  float *v7; // eax
  CSentence *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v12; // eax
  float **v13; // edi
  float *v14; // esi
  __int16 v15; // di
  _DWORD *v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  char *v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  void *v25; // [esp-8h] [ebp-1220h]
  char pString[4096]; // [esp+8h] [ebp-1210h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-210h] BYREF
  char str[256]; // [esp+1108h] [ebp-110h] BYREF
  CSentence *v29; // [esp+1208h] [ebp-10h]
  float v30; // [esp+120Ch] [ebp-Ch]
  float v31; // [esp+1210h] [ebp-8h]
  float *v32; // [esp+1214h] [ebp-4h]

  v2 = buf;
  v29 = this;
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( _V_stricmp(s1: pString, s2: "}") != 0 )
  {
    if ( _V_stricmp(s1: pString, s2: "WORD") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v31 = atof(nptr: pString);
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    v30 = atof(nptr: pString);
    v3 = (float *)operator new(nSize: 0x2Cu);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3[2] = 0.0;
      v3[3] = 0.0;
      v3[4] = 0.0;
      v3[5] = 0.0;
      v3[6] = 0.0;
      v3[8] = 0.0;
      v3[9] = 0.0;
      *v3 = 0.0;
      v3[1] = 0.0;
      v3[10] = 0.0;
      *((_BYTE *)v3 + 28) = 0;
      free(pMem: nullptr);
      v4[10] = 0.0;
      if ( pDest[0] != 0 )
      {
        v5 = strlen(pDest);
        v6 = (char *)operator new(nSize: v5 + 1);
        *((_DWORD *)v4 + 10) = v6;
        V_strncpy(pDest: v6, pSrc: pDest, maxLen: v5 + 1);
      }
      v32 = v4;
    }
    else
    {
      v32 = nullptr;
    }
    v7 = v32;
    v8 = v29;
    *v32 = v31;
    v7[1] = v30;
    m_Size = v8->m_Words.m_Size;
    m_nAllocationCount = v8->m_Words.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_Words,
        num: m_Size - m_nAllocationCount + 1);
    ++v8->m_Words.m_Size;
    m_pMemory = v8->m_Words.m_Memory.m_pMemory;
    v12 = v8->m_Words.m_Size - m_Size - 1;
    v8->m_Words.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = (float **)&v8->m_Words.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v32;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "}") != 0 )
    {
      v14 = v32;
      do
      {
        v15 = atoi(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        V_strncpy(pDest: str, pSrc: pString, maxLen: 256);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v30 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        v31 = atof(nptr: pString);
        CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
        atof(nptr: pString);
        v16 = operator new(nSize: 0x1Cu);
        v17 = nullptr;
        if ( v16 != nullptr )
        {
          v16[6] = 0;
          v16[4] = 0;
          v16[5] = 0;
          *v16 = 0;
          v16[1] = 0;
          *((_WORD *)v16 + 4) = 0;
          *((_BYTE *)v16 + 12) = 0;
          v17 = v16;
        }
        v25 = (void *)v17[6];
        *((_WORD *)v17 + 4) = v15;
        free(pMem: v25);
        v17[6] = 0;
        if ( str[0] != 0 )
        {
          v18 = _V_strlen(str) + 1;
          v19 = (char *)operator new(nSize: v18);
          v17[6] = v19;
          V_strncpy(pDest: v19, pSrc: str, maxLen: v18);
        }
        *(float *)v17 = v30;
        *((float *)v17 + 1) = v31;
        v20 = *((_DWORD *)v14 + 5);
        v21 = *((_DWORD *)v14 + 3);
        if ( v20 + 1 > v21 )
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(v14 + 2),
            num: v20 - v21 + 1);
        ++*((_DWORD *)v14 + 5);
        v22 = *((_DWORD *)v14 + 2);
        v23 = *((_DWORD *)v14 + 5) - v20 - 1;
        *((_DWORD *)v14 + 6) = v22;
        if ( v23 > 0 )
          _V_memmove(dest: (void *)(v22 + 4 * v20 + 4), src: (const void *)(v22 + 4 * v20), count: 4 * v23);
        v24 = (_DWORD *)(*((_DWORD *)v14 + 2) + 4 * v20);
        if ( v24 != nullptr )
          *v24 = v17;
        CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
        v2 = buf;
      }
      while ( _V_stricmp(s1: pString, s2: "}") != 0 );
    }
    CUtlBuffer::GetString(this: v2, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402300
// Name: private: void CSentence::ParseDataVersionOnePointZero(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::ParseDataVersionOnePointZero(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1100h] BYREF
  char pDest[256]; // [esp+1008h] [ebp-100h] BYREF

  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  while ( strlen(pString) != 0 )
  {
    V_strncpy(pDest, pSrc: pString, maxLen: 256);
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( _V_stricmp(s1: pString, s2: "{") != 0 )
      break;
    if ( _V_stricmp(s1: pDest, s2: "PLAINTEXT") != 0 )
    {
      if ( _V_stricmp(s1: pDest, s2: "WORDS") != 0 )
      {
        if ( _V_stricmp(s1: pDest, s2: "EMPHASIS") != 0 )
        {
          if ( _V_stricmp(s1: pDest, s2: "CLOSECAPTION") != 0 )
          {
            if ( _V_stricmp(s1: pDest, s2: "OPTIONS") == 0 )
              CSentence::ParseOptions(this, buf);
          }
          else
          {
            CSentence::ParseCloseCaption(this, buf);
          }
        }
        else
        {
          CSentence::ParseEmphasis(this, buf);
        }
      }
      else
      {
        CSentence::ParseWords(this, buf);
      }
    }
    else
    {
      CSentence::ParsePlaintext(this, buf);
    }
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402470
// Name: public: void CSentence::InitFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromBuffer(CSentence *this, CUtlBuffer *buf)
{
  char pString[4096]; // [esp+8h] [ebp-1000h] BYREF

  CSentence::Reset(this);
  CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
  if ( _V_stricmp(s1: pString, s2: "VERSION") == 0 )
  {
    CUtlBuffer::GetString(this: buf, pString, nMaxChars: 0);
    if ( atof(nptr: pString) == 1.0 )
    {
      CSentence::ParseDataVersionOnePointZero(this, buf);
      *((_BYTE *)this + 72) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402500
// Name: public: void CSentence::InitFromDataChunk(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentence::InitFromDataChunk(CSentence *this, void *data, int size)
{
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::EnsureCapacity(this: &buf, num: size);
  CUtlBuffer::Put(this: &buf, pMem: data, size);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: size);
  CSentence::InitFromBuffer(this, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

} // namespace scenemanager

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x004011B0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004011F0
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401230
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

} // namespace vcdupdate

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x100C51B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        wchar_t *outputBuffer,
        wchar_t *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = (unsigned __int8 *)inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = (unsigned __int8 *)outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = (char *)outputBuffer - (char *)v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != (wchar_t *)v5 )
    {
      memcpy(dst: (unsigned __int8 *)outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169C90
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169D30
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, unsigned int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10169DA0
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, unsigned int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10169E10
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10169E80
// Name: public: class CBasePhonemeTag const __near * CSentence::GetRuntimePhoneme(int)const
// Source: json
//------------------------------------------------------------------------------
const CBasePhonemeTag *__thiscall CSentence::GetRuntimePhoneme(CSentence *this, int i)
{
  return this->m_RunTimePhonemes.m_Memory.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10169E90
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169ED0
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169F80
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169FD0
// Name: public: float CSentence::GetIntensity(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSentence::GetIntensity(CSentence *this, float time, int endtime)
{
  float t; // xmm0_4
  int v6; // eax
  int v7; // ebx
  int *v8; // edx
  int v9; // edi
  int *v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // edi
  int v14; // ebx
  int m_Size; // eax
  CEmphasisSample *v16; // esi
  CEmphasisSample *v17; // edx
  int *v18; // eax
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm5_4
  float v22; // xmm5_4
  float v23; // xmm5_4
  float v24; // xmm5_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  Vector vOut; // [esp+8h] [ebp-40h] BYREF
  Vector vPre; // [esp+14h] [ebp-34h] BYREF
  Vector vStart; // [esp+20h] [ebp-28h] BYREF
  Vector vEnd; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector vNext; // [esp+38h] [ebp-10h] BYREF
  int c; // [esp+44h] [ebp-4h]
  int *retval; // [esp+54h] [ebp+Ch]

  c = this->m_EmphasisSamples.m_Size;
  if ( c <= 0 )
    return 0.5;
  t = 0.0;
  v6 = -1;
  v7 = -12;
  do
  {
    dword_1064F848 = 0;
    dword_1064F84C = 1056964608;
    dword_1064F83C = endtime;
    dword_1064F840 = 1056964608;
    if ( v6 >= 0 )
    {
      if ( v6 < this->m_EmphasisSamples.m_Size )
        v8 = (int *)((char *)this->m_EmphasisSamples.m_Memory.m_pMemory + v7);
      else
        v8 = &dword_1064F83C;
    }
    else
    {
      v8 = &dword_1064F848;
    }
    v9 = v6 + 1;
    dword_1064F848 = 0;
    dword_1064F84C = 1056964608;
    dword_1064F83C = endtime;
    dword_1064F840 = 1056964608;
    if ( v6 + 1 >= 0 )
    {
      if ( v9 < this->m_EmphasisSamples.m_Size )
        v10 = (int *)((char *)&this->m_EmphasisSamples.m_Memory.m_pMemory[1] + v7);
      else
        v10 = &dword_1064F83C;
    }
    else
    {
      v10 = &dword_1064F848;
    }
    if ( v8 != nullptr && v10 != nullptr && time >= *(float *)v8 && *(float *)v10 >= time )
      break;
    ++v6;
    v7 += 12;
  }
  while ( v9 < c );
  v11 = v6 - 1;
  v12 = v6;
  v13 = v6 + 1;
  v14 = v6 + 2;
  if ( v6 - 1 < -1 )
    v11 = -1;
  if ( v6 < -1 )
    v12 = -1;
  m_Size = this->m_EmphasisSamples.m_Size;
  if ( v13 >= m_Size )
    v13 = this->m_EmphasisSamples.m_Size;
  if ( v14 >= m_Size )
    v14 = this->m_EmphasisSamples.m_Size;
  dword_1064F848 = 0;
  dword_1064F84C = 1056964608;
  dword_1064F83C = endtime;
  dword_1064F840 = 1056964608;
  if ( v11 >= 0 )
  {
    if ( v11 < this->m_EmphasisSamples.m_Size )
      retval = (int *)&this->m_EmphasisSamples.m_Memory.m_pMemory[v11];
    else
      retval = &dword_1064F83C;
  }
  else
  {
    retval = &dword_1064F848;
  }
  dword_1064F848 = 0;
  dword_1064F84C = 1056964608;
  dword_1064F83C = endtime;
  dword_1064F840 = 1056964608;
  if ( v12 >= 0 )
  {
    if ( v12 < this->m_EmphasisSamples.m_Size )
      v16 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v12];
    else
      v16 = (CEmphasisSample *)&dword_1064F83C;
  }
  else
  {
    v16 = (CEmphasisSample *)&dword_1064F848;
  }
  dword_1064F848 = 0;
  dword_1064F84C = 1056964608;
  dword_1064F83C = endtime;
  dword_1064F840 = 1056964608;
  if ( v13 >= 0 )
  {
    if ( v13 < this->m_EmphasisSamples.m_Size )
      v17 = &this->m_EmphasisSamples.m_Memory.m_pMemory[v13];
    else
      v17 = (CEmphasisSample *)&dword_1064F83C;
  }
  else
  {
    v17 = (CEmphasisSample *)&dword_1064F848;
  }
  dword_1064F848 = 0;
  dword_1064F84C = 1056964608;
  dword_1064F83C = endtime;
  dword_1064F840 = 1056964608;
  if ( v14 >= 0 )
  {
    if ( v14 < this->m_EmphasisSamples.m_Size )
      v18 = (int *)&this->m_EmphasisSamples.m_Memory.m_pMemory[v14];
    else
      v18 = &dword_1064F83C;
  }
  else
  {
    v18 = &dword_1064F848;
  }
  v19 = v17->time - v16->time;
  v20 = 0.0099999998;
  if ( v19 >= 0.0099999998 )
  {
    if ( v19 <= 1.0 )
      v20 = v17->time - v16->time;
    else
      v20 = 1.0;
  }
  v21 = *(float *)retval;
  LODWORD(vPre.y) = retval[1];
  vPre.x = v21;
  vPre.z = 0.0;
  v22 = v16->time;
  vStart.y = v16->value;
  vStart.x = v22;
  vStart.z = 0.0;
  v23 = v17->time;
  vEnd.y = v17->value;
  vEnd.x = v23;
  vEnd.z = 0.0;
  v24 = *(float *)v18;
  LODWORD(vNext.y) = v18[1];
  vNext.x = v24;
  vNext.z = 0.0;
  v25 = (float)(time - v16->time) / v20;
  if ( v25 >= 0.0 )
  {
    if ( v25 <= 1.0 )
      t = (float)(time - v16->time) / v20;
    else
      t = 1.0;
  }
  Catmull_Rom_Spline(p1: &vPre, p2: &vStart, p3: &vEnd, p4: &vNext, t, output: &vOut);
  v26 = 0.0;
  if ( vOut.y < 0.0 )
    return v26;
  v26 = 1.0;
  if ( vOut.y > 1.0 )
    return v26;
  else
    return vOut.y;
}

//------------------------------------------------------------------------------
// Address: 0x1016A300
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (wchar_t *)&s,
          inputBuffer: (wchar_t *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 0xAu);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016A3A0
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (wchar_t *)&s,
          inputBuffer: (wchar_t *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 0xAu);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

} // namespace client
