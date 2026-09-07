// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/random.cpp
// Functions: 16
// ============================================================

#include "vstdlib\random.h"

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: public: CUniformRandomStream::CUniformRandomStream(class CUniformRandomStream const __near &)
// Source: json
//------------------------------------------------------------------------------
CUniformRandomStream *__thiscall CUniformRandomStream::CUniformRandomStream(
        CUniformRandomStream *this,
        const CUniformRandomStream *__that)
{
  this->__vftable = (CUniformRandomStream_vtbl *)&CUniformRandomStream::`vftable';
  this->m_idum = __that->m_idum;
  this->m_iy = __that->m_iy;
  qmemcpy(this->m_iv, __that->m_iv, 0x88u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000EAE0
// Name: _InstallUniformRandomStream
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallUniformRandomStream(IUniformRandomStream *pStream)
{
  s_pUniformStream = pStream;
  if ( pStream == nullptr )
    s_pUniformStream = &s_UniformStream;
}

//------------------------------------------------------------------------------
// Address: 0x1000EB00
// Name: _RandomSeed
// Source: json
//------------------------------------------------------------------------------
void __cdecl RandomSeed(int iSeed)
{
  s_pUniformStream->SetSeed(this: s_pUniformStream, a2: iSeed);
}

//------------------------------------------------------------------------------
// Address: 0x1000EB20
// Name: _RandomFloat
// Source: json
//------------------------------------------------------------------------------
float __cdecl RandomFloat(float flMinVal, float flMaxVal)
{
  return ((float (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))s_pUniformStream->RandomFloat)(
           a1: s_pUniformStream,
           a2: LODWORD(flMinVal),
           a3: LODWORD(flMaxVal));
}

//------------------------------------------------------------------------------
// Address: 0x1000EB50
// Name: _RandomFloatExp
// Source: json
//------------------------------------------------------------------------------
float __cdecl RandomFloatExp(float flMinVal, float flMaxVal, float flExponent)
{
  return ((float (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD, _DWORD))s_pUniformStream->RandomFloatExp)(
           a1: s_pUniformStream,
           a2: LODWORD(flMinVal),
           a3: LODWORD(flMaxVal),
           a4: LODWORD(flExponent));
}

//------------------------------------------------------------------------------
// Address: 0x1000EB90
// Name: _RandomInt
// Source: json
//------------------------------------------------------------------------------
int __cdecl RandomInt(int iMinVal, int iMaxVal)
{
  return s_pUniformStream->RandomInt(this: s_pUniformStream, a2: iMinVal, a3: iMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x1000EBB0
// Name: public: virtual void CUniformRandomStream::SetSeed(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUniformRandomStream::SetSeed(CUniformRandomStream *this, int iSeed)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  this->m_idum = -abs32(iSeed);
  this->m_iy = 0;
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000EC20
// Name: private: int CUniformRandomStream::GenerateRandomNumber(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUniformRandomStream::GenerateRandomNumber(CUniformRandomStream *this)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  int m_idum; // eax
  int v5; // eax
  int v6; // edi
  int *v7; // ebx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // edi
  int v15; // edx
  int result; // eax
  CThreadFastMutex *generated_id_1; // [esp+Ch] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  generated_id_1 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  m_idum = this->m_idum;
  if ( m_idum <= 0 || this->m_iy == 0 )
  {
    v5 = -m_idum;
    if ( v5 >= 1 )
      this->m_idum = v5;
    else
      this->m_idum = 1;
    v6 = 37;
    v7 = (int *)((char *)this + 164);
    do
    {
      v8 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
      this->m_idum = v8;
      if ( v8 < 0 )
        this->m_idum = v8 + 0x7FFFFFFF;
      if ( v6 + 2 < 32 )
        v7[1] = this->m_idum;
      v9 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
      this->m_idum = v9;
      if ( v9 < 0 )
        this->m_idum = v9 + 0x7FFFFFFF;
      if ( v6 + 1 < 32 )
        *v7 = this->m_idum;
      v10 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
      this->m_idum = v10;
      if ( v10 < 0 )
        this->m_idum = v10 + 0x7FFFFFFF;
      if ( v6 < 32 )
        *(v7 - 1) = this->m_idum;
      v11 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
      this->m_idum = v11;
      if ( v11 < 0 )
        this->m_idum = v11 + 0x7FFFFFFF;
      if ( v6 - 1 < 32 )
        *(v7 - 2) = this->m_idum;
      v12 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
      this->m_idum = v12;
      if ( v12 < 0 )
        this->m_idum = v12 + 0x7FFFFFFF;
      if ( v6 - 2 < 32 )
        *(v7 - 3) = this->m_idum;
      v6 -= 5;
      v7 -= 5;
    }
    while ( v6 + 2 >= 0 );
    p_m_mutex = generated_id_1;
    this->m_iy = this->m_iv[0];
  }
  v13 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
  this->m_idum = v13;
  if ( v13 < 0 )
    this->m_idum = v13 + 0x7FFFFFFF;
  v14 = this->m_iy / 0x4000000;
  if ( (unsigned int)v14 >= 0x20 )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
      __debugbreak();
    _Warning(
      a1: "CUniformRandomStream had an array overrun: tried to write to element %d of 0..31. Contact Tom or Elan.\n",
      v14);
    v14 = (v14 % 32) & 0x7FFFFFFF;
  }
  v15 = this->m_idum;
  this->m_iy = this->m_iv[v14];
  this->m_iv[v14] = v15;
  result = this->m_iy;
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EE90
// Name: public: virtual float CUniformRandomStream::RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CUniformRandomStream::RandomFloat(CUniformRandomStream *this, float flLow, float flHigh)
{
  float fl; // [esp+0h] [ebp-4h]

  fl = (double)CUniformRandomStream::GenerateRandomNumber(this) * 4.656612875245797e-10;
  if ( fl > 0.99999988 )
    fl = 0.99999988;
  return flLow + (flHigh - flLow) * fl;
}

//------------------------------------------------------------------------------
// Address: 0x1000EEF0
// Name: public: virtual float CUniformRandomStream::RandomFloatExp(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CUniformRandomStream::RandomFloatExp(
        CUniformRandomStream *this,
        float flMinVal,
        float flMaxVal,
        float flExponent)
{
  float v4; // xmm0_4
  float fl; // [esp+0h] [ebp-4h]

  v4 = (double)CUniformRandomStream::GenerateRandomNumber(this) * 4.656612875245797e-10;
  fl = v4;
  if ( v4 > 0.99999988 )
  {
    v4 = 0.99999988;
    fl = 0.99999988;
  }
  if ( flExponent != 1.0 )
  {
    __libm_sse2_pow();
    fl = v4;
  }
  return flMinVal + (flMaxVal - flMinVal) * fl;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF70
// Name: public: virtual int CUniformRandomStream::RandomInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUniformRandomStream::RandomInt(CUniformRandomStream *this, int iLow, unsigned int iHigh)
{
  int result; // eax
  unsigned int v4; // ebx
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // eax
  int m_idum; // eax
  int v9; // eax
  int v10; // edi
  int *v11; // ebx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // edi
  int v19; // edx
  unsigned int m_iy; // eax
  bool v21; // zf
  unsigned int maxAcceptable; // [esp+Ch] [ebp-4h]
  unsigned int x; // [esp+1Ch] [ebp+Ch]

  result = iLow;
  v4 = iHigh - iLow + 1;
  x = v4;
  if ( v4 > 1 && v4 - 1 <= 0x7FFFFFFF )
  {
    p_m_mutex = &this->m_mutex;
    maxAcceptable = 0x7FFFFFFF - 0x80000000 % v4;
    while ( 1 )
    {
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId == p_m_mutex->m_ownerID )
        goto LABEL_7;
      if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) == 0 )
        break;
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
      v4 = x;
LABEL_9:
      m_idum = this->m_idum;
      if ( m_idum <= 0 || this->m_iy == 0 )
      {
        v9 = -m_idum;
        if ( v9 >= 1 )
          this->m_idum = v9;
        else
          this->m_idum = 1;
        v10 = 37;
        v11 = (int *)((char *)this + 164);
        do
        {
          v12 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
          this->m_idum = v12;
          if ( v12 < 0 )
            this->m_idum = v12 + 0x7FFFFFFF;
          if ( v10 + 2 < 32 )
            v11[1] = this->m_idum;
          v13 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
          this->m_idum = v13;
          if ( v13 < 0 )
            this->m_idum = v13 + 0x7FFFFFFF;
          if ( v10 + 1 < 32 )
            *v11 = this->m_idum;
          v14 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
          this->m_idum = v14;
          if ( v14 < 0 )
            this->m_idum = v14 + 0x7FFFFFFF;
          if ( v10 < 32 )
            *(v11 - 1) = this->m_idum;
          v15 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
          this->m_idum = v15;
          if ( v15 < 0 )
            this->m_idum = v15 + 0x7FFFFFFF;
          if ( v10 - 1 < 32 )
            *(v11 - 2) = this->m_idum;
          v16 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
          this->m_idum = v16;
          if ( v16 < 0 )
            this->m_idum = v16 + 0x7FFFFFFF;
          if ( v10 - 2 < 32 )
            *(v11 - 3) = this->m_idum;
          v10 -= 5;
          v11 -= 5;
        }
        while ( v10 + 2 >= 0 );
        v4 = x;
        this->m_iy = this->m_iv[0];
      }
      v17 = 16807 * this->m_idum - 0x7FFFFFFF * (this->m_idum / 127773);
      this->m_idum = v17;
      if ( v17 < 0 )
        this->m_idum = v17 + 0x7FFFFFFF;
      v18 = this->m_iy / 0x4000000;
      if ( (unsigned int)v18 >= 0x20 )
      {
        if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
          __debugbreak();
        _Warning(
          a1: "CUniformRandomStream had an array overrun: tried to write to element %d of 0..31. Contact Tom or Elan.\n",
          v18);
        v18 = (v18 % 32) & 0x7FFFFFFF;
      }
      v19 = this->m_idum;
      this->m_iy = this->m_iv[v18];
      this->m_iv[v18] = v19;
      m_iy = this->m_iy;
      v21 = this->m_mutex.m_depth-- == 1;
      p_m_mutex = &this->m_mutex;
      if ( v21 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      if ( m_iy <= maxAcceptable )
        return iLow + m_iy % v4;
    }
    v4 = x;
LABEL_7:
    ++p_m_mutex->m_depth;
    goto LABEL_9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F240
// Name: public: void CGaussianRandomStream::AttachToStream(class IUniformRandomStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGaussianRandomStream::AttachToStream(
        CGaussianRandomStream *this,
        IUniformRandomStream *pUniformStream)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  this->m_pUniformStream = pUniformStream;
  this->m_bHaveValue = false;
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000F2A0
// Name: public: float CGaussianRandomStream::RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGaussianRandomStream::RandomFloat(CGaussianRandomStream *this, float flMean, float flStdDev)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  IUniformRandomStream *m_pUniformStream; // ebx
  double v7; // st7
  double v8; // st7
  float v9; // xmm0_4
  float v10; // xmm0_4
  bool v11; // zf
  float v13; // xmm0_4
  long double v14; // [esp+18h] [ebp-18h]
  float v2; // [esp+28h] [ebp-8h]
  float v1; // [esp+2Ch] [ebp-4h]
  float flStdDeva; // [esp+3Ch] [ebp+Ch]

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  m_pUniformStream = this->m_pUniformStream;
  if ( this->m_pUniformStream == nullptr )
    m_pUniformStream = s_pUniformStream;
  if ( this->m_bHaveValue )
  {
    v13 = (float)(this->m_flRandomValue * flStdDev) + flMean;
    this->m_bHaveValue = false;
    v11 = p_m_mutex->m_depth-- == 1;
    flStdDeva = v13;
    if ( v11 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
  else
  {
    do
    {
      do
      {
        v7 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))m_pUniformStream->RandomFloat)(
               a1: m_pUniformStream,
               a2: 0,
               a3: 1065353216);
        v1 = v7 + v7 - 1.0;
        v8 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))m_pUniformStream->RandomFloat)(
               a1: m_pUniformStream,
               a2: 0,
               a3: 1065353216);
        v2 = v8 + v8 - 1.0;
        v9 = (float)(v2 * v2) + (float)(v1 * v1);
      }
      while ( v9 > 1.0 );
    }
    while ( v9 == 0.0 );
    __libm_sse2_log(x: v14);
    v10 = fsqrt((float)(v9 * -2.0) / v9);
    this->m_flRandomValue = v10 * v1;
    this->m_bHaveValue = true;
    v11 = p_m_mutex->m_depth-- == 1;
    flStdDeva = (float)((float)(v10 * v2) * flStdDev) + flMean;
    if ( v11 )
    {
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return flStdDeva;
    }
  }
  return flStdDeva;
}

//------------------------------------------------------------------------------
// Address: 0x1000F420
// Name: _RandomGaussianFloat
// Source: json
//------------------------------------------------------------------------------
double __cdecl RandomGaussianFloat(float flMean, float flStdDev)
{
  return CGaussianRandomStream::RandomFloat(this: &s_GaussianStream, flMean, flStdDev);
}

//------------------------------------------------------------------------------
// Address: 0x1000F450
// Name: public: CUniformRandomStream::CUniformRandomStream(void)
// Source: json
//------------------------------------------------------------------------------
CUniformRandomStream *__thiscall CUniformRandomStream::CUniformRandomStream(CUniformRandomStream *this)
{
  this->__vftable = (CUniformRandomStream_vtbl *)&CUniformRandomStream::`vftable';
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  CUniformRandomStream::SetSeed(this, iSeed: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F480
// Name: public: CGaussianRandomStream::CGaussianRandomStream(class IUniformRandomStream __near *)
// Source: json
//------------------------------------------------------------------------------
CGaussianRandomStream *__thiscall CGaussianRandomStream::CGaussianRandomStream(
        CGaussianRandomStream *this,
        IUniformRandomStream *pUniformStream)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_mutex = &this->m_mutex;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  this->m_pUniformStream = pUniformStream;
  this->m_bHaveValue = false;
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return this;
}

// ============================================================
// Overlay from vstdlib_s (Missing functions)
// ============================================================
namespace vstdlib_s {

//------------------------------------------------------------------------------
// Address: 0x3F60A520
// Name: InstallUniformRandomStream
// Source: json
//------------------------------------------------------------------------------
void **__cdecl InstallUniformRandomStream(void **a1)
{
  void **result; // eax

  result = a1;
  off_3F662A98 = a1;
  if ( a1 == nullptr )
    off_3F662A98 = (void **)&off_3F662AF0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60A540
// Name: RandomSeed
// Source: json
//------------------------------------------------------------------------------
int __cdecl RandomSeed(int a1)
{
  return (*(int (__thiscall **)(void **, int))*off_3F662A98)(a1: off_3F662A98, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F60A560
// Name: RandomFloat
// Source: json
//------------------------------------------------------------------------------
float __thiscall RandomFloat(IUniformRandomStream *this, float a2, float a3)
{
  return (*((float (__thiscall **)(void **, _DWORD, _DWORD))*off_3F662A98 + 1))(
           a1: off_3F662A98,
           a2: LODWORD(a2),
           a3: LODWORD(a3));
}

//------------------------------------------------------------------------------
// Address: 0x3F60A580
// Name: RandomInt
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F60A5A0
// Name: RandomGaussianFloat
// Source: json
//------------------------------------------------------------------------------
void __cdecl RandomGaussianFloat(float a1, float a2)
{
  CGaussianRandomStream::RandomFloat(this: &stru_3F6643A0, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F60A820
// Name: public: virtual float CUniformRandomStream::RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CUniformRandomStream::RandomFloat(CUniformRandomStream *this, float a2, float a3)
{
  float v4; // [esp+0h] [ebp-4h]

  v4 = (double)(int)CUniformRandomStream::GenerateRandomNumber(this) * 4.656612873077393e-10;
  if ( v4 > 0.9999998807907104 )
    v4 = 0.99999988;
  return (float)((a3 - a2) * v4 + a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F60A870
// Name: public: virtual int CUniformRandomStream::RandomInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUniformRandomStream::RandomInt(CUniformRandomStream *this, int a2, int a3)
{
  unsigned int v3; // esi
  unsigned int RandomNumber; // eax

  v3 = a3 - a2 + 1;
  if ( a3 - a2 == -1 || v3 == 1 || (unsigned int)(a3 - a2) > 0x7FFFFFFF )
    return a2;
  do
    RandomNumber = CUniformRandomStream::GenerateRandomNumber(this);
  while ( RandomNumber > 0x7FFFFFFF - 0x80000000 % v3 );
  return a2 + RandomNumber % v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F60A8D0
// Name: public: void CGaussianRandomStream::AttachToStream(class IUniformRandomStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGaussianRandomStream::AttachToStream(CGaussianRandomStream *this, struct IUniformRandomStream *a2)
{
  this->m_pUniformStream = a2;
  this->m_bHaveValue = false;
}

//------------------------------------------------------------------------------
// Address: 0x3F60A8E0
// Name: public: float CGaussianRandomStream::RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
float __userpurge CGaussianRandomStream::RandomFloat@<st0>(
        CGaussianRandomStream *this@<ecx>,
        KeyValues *a2,
        IBaseFileSystem *a3,
        void *a4)
{
  IUniformRandomStream *m_pUniformStream; // edi
  double v6; // st7

  m_pUniformStream = this->m_pUniformStream;
  if ( this->m_pUniformStream == nullptr )
    m_pUniformStream = (IUniformRandomStream *)off_3F662A98;
  if ( this->m_bHaveValue )
    JUMPOUT(0x3F60A9D4);
  ((void (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))m_pUniformStream->RandomFloat)(
    a1: m_pUniformStream,
    a2: 0.0,
    a3: 1.0);
  v6 = 1.0;
  KeyValues::WriteIndents(
    pBuf: (CUtlBuffer *)m_pUniformStream,
    indentLevel: (int)m_pUniformStream->__vftable,
    a3: (void (__thiscall *)(CUtlBuffer *, _DWORD, _DWORD))m_pUniformStream->RandomFloat,
    a4: (int)this,
    this: a2,
    filesystem: a3,
    f: a4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F612DB0
// Name: _InstallUniformRandomStream
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallUniformRandomStream()
{
  JUMPOUT(0x3F612DCA);
}

//------------------------------------------------------------------------------
// Address: 0x3F612DD0
// Name: _RandomSeed
// Source: json
//------------------------------------------------------------------------------
void __cdecl RandomSeed()
{
  JUMPOUT(0x3F612DE3);
}

//------------------------------------------------------------------------------
// Address: 0x3F612DF0
// Name: _RandomFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall RandomFloat(int a1@<edx>, int a2@<ecx>, int a3@<ebx>, int a4@<edi>, int flMinVal, int flMaxVal)
{
  *(_DWORD *)(a1 - 54) <<= 19;
  if ( *(_DWORD *)(a3 + 856695916) - a2 >= 0 )
    JUMPOUT(0x3F612E35);
  *(_DWORD *)(a2 + 56) = __ROL4__(a4, 1);
  RandomInt(iMinVal: flMinVal, iMaxVal: flMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x3F612E10
// Name: _RandomInt
// Source: json
//------------------------------------------------------------------------------
void __cdecl RandomInt()
{
  JUMPOUT(0x3F612E29);
}

//------------------------------------------------------------------------------
// Address: 0x3F612E30
// Name: _RandomGaussianFloat
// Source: json
//------------------------------------------------------------------------------
void __thiscall RandomGaussianFloat(_DWORD *this)
{
  *(this + 15) = __ROL4__(*(this + 15) ^ *(this + 1) ^ *(this + 7) ^ *(this + 12), 1);
  JUMPOUT(0x3F612E4F);
}

//------------------------------------------------------------------------------
// Address: 0x3F613110
// Name: public: CGaussianRandomStream::CGaussianRandomStream(class IUniformRandomStream __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CGaussianRandomStream::CGaussianRandomStream(
        CGaussianRandomStream *this@<ecx>,
        char a2@<al>,
        unsigned __int16 a3@<dx>,
        _BYTE *a4@<ebx>,
        IUniformRandomStream *pUniformStream)
{
  *a4 -= HIBYTE(a3);
  __outbyte(a3, a2 | 0x33);
  JUMPOUT(0x3F61311D);
}

//------------------------------------------------------------------------------
// Address: 0x3F613250
// Name: _logf
// Source: json
//------------------------------------------------------------------------------
float __cdecl logf(float _X, int a2)
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  return sub_3F613260(a1: LODWORD(_X), a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F613270
// Name: _sqrtf
// Source: json
//------------------------------------------------------------------------------
void __usercall sqrtf(char a1@<al>, unsigned int a2@<ecx>, unsigned int a3@<ebx>, int a4@<esi>)
{
  int v4; // eax

  v4 = a1 & 0x3F;
  *(_DWORD *)(a4 + 24) = a2;
  if ( a2 < 8 * a3 )
    JUMPOUT(0x3F613282);
  *(_DWORD *)(a4 + 28) += a3 >> 29;
  if ( v4 + a3 <= 0x3F )
    JUMPOUT(0x3F6132E5);
  CStringNormalization::Initialize();
}

//------------------------------------------------------------------------------
// Address: 0x3F6404E0
// Name: _log
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F612E90
// Name: ?GenerateRandomNumber@CUniformRandomStream@@AAEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CUniformRandomStream::GenerateRandomNumber(CUniformRandomStream *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 4) = __ROL4__(
                                             *(_DWORD *)(*(_DWORD *)(a2 + 180) + 4)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 12)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 36)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 56),
                                             1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 8) = __ROL4__(
                                             *(_DWORD *)(*(_DWORD *)(a2 + 180) + 8)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 16)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 40)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 60),
                                             1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 12) = __ROL4__(
                                              **(_DWORD **)(a2 + 180)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 12)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 20)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 44),
                                              1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 16) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a2 + 180) + 16)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 4)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 24)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 48),
                                              1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 20) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a2 + 180) + 20)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 8)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 28)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 52),
                                              1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 24) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a2 + 180) + 24)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 12)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 32)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 56),
                                              1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 28) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a2 + 180) + 28)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 16)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 36)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 60),
                                              1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 32) = __ROL4__(
                                              **(_DWORD **)(a2 + 180)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 32)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 20)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 40),
                                              1);
  JUMPOUT(0x3F61306B);
}

//------------------------------------------------------------------------------
// Address: 0x3F613070
// Name: ?RandomFloat@CUniformRandomStream@@UAEMMM@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CUniformRandomStream::RandomFloat(CUniformRandomStream *this@<ecx>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 611595255) += (_BYTE)this;
}

//------------------------------------------------------------------------------
// Address: 0x3F6130C0
// Name: ?RandomInt@CUniformRandomStream@@UAEHHH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __fastcall CUniformRandomStream::RandomInt(CUniformRandomStream *this, int _EDX, int iLow, int iHigh)
{
  char v4; // of
  char v5; // cc
  __int16 v7; // [esp-4h] [ebp-4h]

  v5 = ((*MK_FP(v7, _EDX - 54) & 0x100000) != 0) ^ v4;
  *MK_FP(v7, _EDX - 54) = *MK_FP(v7, _EDX - 54) << 11;
  if ( !v5 )
  {
    *MK_FP(v7, (char *)this - 1961352100) = *MK_FP(v7, (char *)this - 1961352100) - (_BYTE)this;
    __asm { iret }
    JUMPOUT(0x3F6130D5);
  }
  __asm { insb }
  JUMPOUT(0x3F61310D);
}

//------------------------------------------------------------------------------
// Address: 0x3F613120
// Name: ?AttachToStream@CGaussianRandomStream@@QAEXPAVIUniformRandomStream@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CGaussianRandomStream::AttachToStream(CGaussianRandomStream *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F613130
// Name: ?RandomFloat@CGaussianRandomStream@@QAEMMM@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CGaussianRandomStream::RandomFloat(
        CGaussianRandomStream *this@<ecx>,
        int a2@<eax>,
        _DWORD *_EDX@<edx>,
        int a4@<ebx>,
        int a5@<ebp>,
        int a6@<edi>,
        int a7@<esi>,
        float flMean,
        float flStdDev,
        float a10,
        float a11,
        int a12,
        float a13,
        float a14,
        float a15,
        float a16,
        int a17)
{
  int v17; // ebx
  _DWORD *v18; // ecx
  int v19; // esi
  _DWORD *v20; // ecx
  int v21; // edi
  _DWORD *v22; // ebp
  int v23; // ebx
  int v24; // ebp
  int v25; // [esp+24h] [ebp+10h]
  int v26; // [esp+2Ch] [ebp+18h]
  int v27; // [esp+30h] [ebp+1Ch]
  int v28; // [esp+3Ch] [ebp+28h]

  __asm { insb }
  LOBYTE(a2) = (a2 + 117) & 0x10;
  v17 = __ROL4__(a4, 5) + a5 - 899497514;
  v26 = __ROR4__(a7, 2);
  *((_DWORD *)this + 12) = __ROL4__(
                             *((_DWORD *)this + 12)
                           ^ *((_DWORD *)this + 4)
                           ^ *((_DWORD *)this + 9)
                           ^ *((_DWORD *)this + 14),
                             1);
  v18 = *(_DWORD **)(a2 + 180);
  v27 = __ROR4__(a6, 2);
  v19 = __ROL4__(v17, 5) + a17 + v18[12] + (a6 ^ v26 ^ a12) - 899497514;
  v18[13] = __ROL4__(v18[13] ^ v18[5] ^ v18[10] ^ v18[15], 1);
  v20 = *(_DWORD **)(a2 + 180);
  v21 = a12 + v20[13] + (v27 ^ v26 ^ v17) + __ROL4__(v19, 5) - 899497514;
  v25 = __ROR4__(v17, 2);
  v20[14] = __ROL4__(*v20 ^ v20[14] ^ v20[6] ^ v20[11], 1);
  v22 = *(_DWORD **)(a2 + 180);
  v28 = __ROR4__(v19, 2);
  v23 = v26 + v22[14] + (v27 ^ v19 ^ v25) + __ROL4__(v21, 5) - 899497514;
  v22[15] = __ROL4__(v22[15] ^ v22[1] ^ v22[7] ^ v22[12], 1);
  v24 = *(_DWORD *)(*(_DWORD *)(a2 + 180) + 60) + (v21 ^ v28 ^ v25);
  _EDX[1] += v23;
  *_EDX += __ROL4__(v23, 5) + v27 + v24 - 899497514;
  _EDX[3] += v28;
  JUMPOUT(0x3F613245);
}

//------------------------------------------------------------------------------
// Address: 0x3F613260
// Name: sub_3F613260
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F613260(int a1@<esi>, int a2, unsigned int a3)
{
  sqrtf(a1: *(_DWORD *)(a1 + 24) >> 3, a2: *(_DWORD *)(a1 + 24) + 8 * a3, a3, a4: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6132A0
// Name: ?Initialize@CStringNormalization@@SAXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
static void __userpurge CStringNormalization::Initialize(
        int a1@<eax>,
        const void *a2@<ecx>,
        size_t a3@<ebx>,
        int a4@<edi>,
        int a5@<esi>,
        int a6,
        int a7)
{
  size_t v7; // edi
  size_t i; // ebp

  v7 = a4 - a1;
  memcpy_1(a1: (void *)(a1 + a5 + 32), Src: a2, Size: v7);
  ((void (__cdecl *)(int))loc_3F611D70)(a1: a5 + 32);
  for ( i = v7 + 63; i < a3; v7 += 64 )
  {
    ((void (__cdecl *)(size_t))loc_3F611D70)(a1: a7 + i - 63);
    i += 64;
  }
  memcpy_1(a1: (void *)(a5 + 32), Src: (const void *)(a6 + v7), Size: a3 - v7);
}

//------------------------------------------------------------------------------
// Address: 0x3F613360
// Name: ?Normalize@CStringNormalization@@SAH_NPBGPAGH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge CStringNormalization::Normalize@<al>(
        char a1@<dl>,
        int *a2@<ecx>,
        FILE *a3@<edi>,
        int a4@<esi>,
        bool bAggressive,
        const wchar_t *pwchSrc,
        wchar_t *pwchDest,
        wchar_t *cchDest)
{
  unsigned int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // edx
  size_t v11; // ebx
  unsigned int i; // ebp
  _BYTE *v14; // [esp-1F3Ch] [ebp-1F54h]
  int v15; // [esp-1F38h] [ebp-1F50h]
  _BYTE v16[8]; // [esp-1F20h] [ebp-1F38h] BYREF
  _BYTE v17[7960]; // [esp-1F18h] [ebp-1F30h] BYREF

  LOBYTE(a3[-1]._base) += a1;
  v8 = *a2;
  *v14 += BYTE1(a2);
  v9 = v8;
  fseek(Stream: a3, Offset: 0, Origin: v15);
  v10 = v9 / 0x1F40;
  v11 = v9 % 0x1F40;
  if ( v10 != 0 )
  {
    for ( i = v10; i != 0; --i )
    {
      fread(Buffer: v17, ElementSize: 1u, ElementCount: 0x1F40u, Stream: a3);
      sub_3F613260(a1: a4, a2: (int)v17, a3: 0x1F40u);
    }
  }
  if ( v11 != 0 )
  {
    fread(Buffer: v16, ElementSize: 1u, ElementCount: v11, Stream: a3);
    sub_3F613260(a1: a4, a2: (int)v16, a3: v11);
  }
  fclose_0(Stream: a3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6134C0
// Name: ?Normalize@CStringNormalization@@SAH_NPBDPADH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall CStringNormalization::Normalize@<eax>(unsigned int a1@<eax>, char a2@<dl>, _DWORD *a3@<esi>)
{
  *((_BYTE *)a3 + a1 + 95) = a2;
  if ( a1 < 0x14 )
    JUMPOUT(0x3F6134A0);
  memset(a1: a3 + 8, Val: 0, Size: 0x40u);
  a3[1] = 0;
  a3[2] = 0;
  a3[3] = 0;
  a3[4] = 0;
  a3[5] = 0;
  a3[6] = 0;
  a3[7] = 0;
  return ((int (__cdecl *)(_DWORD *))loc_3F611D70)(a1: a3 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F640520
// Name: __CIlog
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __usercall _CIlog@<st0>(char a1@<cl>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v5; // ebp
  char *v7; // [esp-8h] [ebp-8h]
  char *v8; // [esp-4h] [ebp-4h]

  *(_DWORD *)(a2 - 1916832576) = __ROL4__(*(_DWORD *)(a2 - 1916832576), a1);
  v5 = a2 + 1;
  if ( sub_3F64D06E(String1: v7, String2: v8) == 0 )
  {
    *(_DWORD *)(a4 + 8) |= 0x304u;
    *(_DWORD *)(a4 + 24) = a3;
    JUMPOUT(0x3F640594);
  }
  if ( (*(_BYTE *)(a4 + 8) & 2) != 0 )
    JUMPOUT(0x3F640597);
  if ( *(_DWORD *)(a4 + 12) == 0 )
    JUMPOUT(0x3F64057B);
  sub_3F64D351(String1: *(char **)a4, String2: (char *)(v5 - 124), MaxCount: *(_DWORD *)(a4 + 12));
  return ((double (*)(void))_CIlog_default)();
}

//------------------------------------------------------------------------------
// Address: 0x3F64055B
// Name: __CIlog_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _CIlog_default(
        int a1@<eax>,
        int (__cdecl *a2)(int, int, int, int)@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        double a6@<st0>)
{
  int v6; // edx
  const char *v7; // [esp-4h] [ebp-4h]

  if ( a1 != 0 )
  {
    if ( (*(_DWORD *)(a5 + 8) & 1) == 0 && ((int (__cdecl *)(int))TestDefaultCountry)(a1: a4) != 0 )
    {
      *(_DWORD *)(a5 + 8) = v6 | 1;
      *(_DWORD *)(a5 + 28) = a4;
    }
  }
  else
  {
    v7 = *(const char **)a5;
    *(_DWORD *)(a5 + 8) |= 2u;
    *(_DWORD *)(a5 + 28) = a4;
    if ( strlen_0(Str: v7) == *(_DWORD *)(a5 + 12) )
      *(_DWORD *)(a5 + 24) = a4;
  }
  if ( (*(_DWORD *)(a5 + 8) & 0x300) != 0x300 )
  {
    if ( a2(a1: a4, a2: *(_DWORD *)(a5 + 16) != 0 ? 3 : 4097, a3: a3 - 124, a4: 120) == 0 )
      JUMPOUT(0x3F6404E4);
    if ( sub_3F64D06E(String1: *(char **)a5, String2: (char *)(a3 - 124)) == 0 )
    {
      *(_DWORD *)(a5 + 8) |= 0x200u;
      if ( *(_DWORD *)(a5 + 16) != 0 )
      {
        *(_DWORD *)(a5 + 8) |= 0x100u;
        JUMPOUT(0x3F64063F);
      }
      if ( *(_DWORD *)(a5 + 12) == 0 || strlen_0(Str: *(const char **)a5) != *(_DWORD *)(a5 + 12) )
        JUMPOUT(0x3F640638);
LABEL_18:
      ((void (__usercall *)(double@<st0>))((char *)&_CIsqrt + 1))(x: a6);
      JUMPOUT(0x3F640632);
    }
    if ( *(_DWORD *)(a5 + 16) == 0
      && *(_DWORD *)(a5 + 12) != 0
      && sub_3F64D06E(String1: *(char **)a5, String2: (char *)(a3 - 124)) == 0 )
    {
      goto LABEL_18;
    }
  }
  JUMPOUT(0x3F640647);
}

//------------------------------------------------------------------------------
// Address: 0x3F640639
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _ftol2_pentium4(
        _BYTE *a1@<eax>,
        char a2@<dh>,
        _BYTE *a3@<ecx>,
        char a4@<bh>,
        int a5@<ebp>,
        int a6@<edi>)
{
  bool v6; // cf
  int v7; // [esp-4h] [ebp-4h]

  *a1 |= (unsigned __int8)a1;
  *(_DWORD *)a1 += a1;
  v6 = __CFADD__(a4, *a3);
  *a3 += a4;
  *(_BYTE *)(a5 + 3) -= v6 + a2;
  *(_DWORD *)(v7 + 24) = a6;
  JUMPOUT(0x3F64064A);
}

//------------------------------------------------------------------------------
// Address: 0x3F64064C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge _ftol2_sse_excpt(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4)
{
  *(_BYTE *)(a2 + 1300955616) = __ROL1__(*(_BYTE *)(a2 + 1300955616), 1);
  __security_check_cookie`...'(StackCookie: a3 ^ a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F640666
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge _ftol2(int a1@<ebp>, int a2)
{
  int v2; // esi
  LCID v3; // eax

  *(_DWORD *)(a1 - 4) = a1 ^ __security_cookie;
  v2 = _getptd_0() + 156;
  v3 = ((int (*)(void))LcidFromHexString)();
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: *(_DWORD *)(v2 + 16) != 0 ? 3 : 4097,
         lpLCData: (LPSTR)(a1 - 124),
         cchData: 120) == 0 )
  {
    *(_DWORD *)(v2 + 8) = 0;
    JUMPOUT(0x3F640712);
  }
  if ( sub_3F64D06E(String1: *(char **)v2, String2: (char *)(a1 - 124)) == 0 )
  {
    if ( *(_DWORD *)(v2 + 16) == 0 )
      JUMPOUT(0x3F6406EF);
    JUMPOUT(0x3F6406FD);
  }
  if ( *(_DWORD *)(v2 + 16) == 0 )
    JUMPOUT(0x3F6406DB);
  JUMPOUT(0x3F640707);
}

//------------------------------------------------------------------------------
// Address: 0x3F6406E0
// Name: __aullrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge _aullrem(char *a1@<eax>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, double a5@<st0>, int a6)
{
  int v6; // eax

  if ( sub_3F64D06E(String1: *(char **)a4, String2: a1) == 0 )
  {
    ((void (__usercall *)(double@<st0>))((char *)&_CIsqrt + 1))(x: a5);
    if ( v6 != 0 )
    {
      *(_DWORD *)(a4 + 8) |= 4u;
      *(_DWORD *)(a4 + 24) = a3;
      *(_DWORD *)(a4 + 28) = a3;
    }
  }
  __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 - 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F640760
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F6407C8
// Name: __setjmp3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall _setjmp3@<eax>(int a1@<esi>)
{
  BOOL result; // eax

  *(_DWORD *)(a1 + 12) = 2;
  result = EnumSystemLocalesA(lpLocaleEnumProc: loc_3F640663, dwFlags: 1u);
  if ( (*(_BYTE *)(a1 + 8) & 4) == 0 )
    *(_DWORD *)(a1 + 8) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F640850
// Name: __trandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _trandisp1()
{
  _disable();
  JUMPOUT(0x3F640851);
}

//------------------------------------------------------------------------------
// Address: 0x3F6408B7
// Name: __trandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _trandisp2@<eax>(char a1@<al>, int a2@<ebx>, int a3@<ebp>, int a4@<esi>, int a5, int a6, int a7)
{
  int v7; // eax

  *(_BYTE *)(2 * a4 + 0x85E8918) |= a1;
  if ( *(_DWORD *)(a4 + 8) == a2 )
    return 0;
  v7 = ((int (__thiscall *)(int))ProcessCodePage)(a1: a3 != 0 ? a3 + 128 : 0);
  if ( v7 == 0
    || v7 == 65000
    || v7 == 65001
    || !IsValidCodePage(CodePage: (unsigned __int16)v7)
    || !IsValidLocale(Locale: *(_DWORD *)(a4 + 24), dwFlags: 1u) )
  {
    return 0;
  }
  if ( a6 != 0 )
    JUMPOUT(0x3F640944);
  if ( a7 != 0 )
    return _rtonepop();
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F64095B
// Name: __rtonepop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtonepop()
{
  JUMPOUT(0x3F640960);
}

//------------------------------------------------------------------------------
// Address: 0x3F64098D
// Name: __nosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F64098F
// Name: __tosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _tosnan2(
        int (__stdcall *a1)(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData)@<ebp>,
        int a2@<edi>,
        int a3@<esi>)
{
  char *v3; // [esp-4h] [ebp-8h]
  int v4; // [esp+0h] [ebp-4h]

  if ( a1(Locale: *(_DWORD *)(a3 + 24), LCType: 0x1001u, lpLCData: v3, cchData: v4) != 0
    && a1(Locale: *(_DWORD *)(a3 + 28), LCType: 0x1002u, lpLCData: (LPSTR)(a2 + 64), cchData: 64) != 0 )
  {
    JUMPOUT(0x3F6409BC);
  }
  JUMPOUT(0x3F6409CB);
}

//------------------------------------------------------------------------------
// Address: 0x3F640A13
// Name: __rtchsifneg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __userpurge _rtchsifneg@<edx:eax>(
        char a1@<efl>,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  __int64 result; // rax

  BYTE1(result) = a1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F640A20
// Name: __startTwoArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _startTwoArgErrorHandling(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        _DWORD *a4@<ebx>,
        int a5@<ebp>,
        _DWORD *a6@<edi>)
{
  *a6 += a3;
  BYTE1(a2) = 73;
  *a4 += a5;
  *(_DWORD *)(a1 + a2 + 51) <<= 9;
  JUMPOUT(0x3F640A36);
}

//------------------------------------------------------------------------------
// Address: 0x3F640A37
// Name: __startOneArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _startOneArgErrorHandling(int a1@<eax>, unsigned __int8 *a2@<ecx>, int a3@<esi>)
{
  int v3; // eax

  if ( a1 != *(_DWORD *)a2 )
  {
    v3 = (unsigned __int8)a1 - *a2;
    if ( v3 == 0 || 2 * (v3 > 0) == 1 )
    {
      if ( *(unsigned __int8 *)(a3 + 1) != a2[1] )
        JUMPOUT(0x3F640A74);
      JUMPOUT(0x3F640A7E);
    }
    JUMPOUT(0x3F640AB3);
  }
  JUMPOUT(0x3F640AB1);
}

//------------------------------------------------------------------------------
// Address: 0x3F640A80
// Name: __twoToTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge _twoToTOS(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F640A95
// Name: __load_CW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _load_CW(char a1@<zf>, int a2@<ecx>, int a3@<esi>)
{
  if ( a1 )
  {
    if ( *(unsigned __int8 *)(a3 + 3) != *(unsigned __int8 *)(a2 + 3) )
      JUMPOUT(0x3F640AAA);
  }
  JUMPOUT(0x3F640AB3);
}

//------------------------------------------------------------------------------
// Address: 0x3F640AAC
// Name: __convertTOStoQNaN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__thiscall _convertTOStoQNaN(void *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F640AC5
// Name: __fload_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fload_withFB(int _EDX@<edx>, int a2@<ecx>, int a3@<esi>)
{
  int v4; // esi

  __asm { lock movzx eax, byte ptr [edx] }
  v4 = a3 - _EAX;
  if ( (v4 == 0 || 2 * (v4 > 0) == 1)
    && (*(unsigned __int8 *)(a2 + 1) == *(unsigned __int8 *)(_EDX + 1)
     || 2 * (*(unsigned __int8 *)(a2 + 1) > (unsigned int)*(unsigned __int8 *)(_EDX + 1)) == 1) )
  {
    JUMPOUT(0x3F640B07);
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F640B08
// Name: __checkTOS_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F640B1E
// Name: __fast_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _fast_exit(int a1, int a2)
{
  if ( *(unsigned __int8 *)(a1 + 3) != *(unsigned __int8 *)(a2 + 3) )
    JUMPOUT(0x3F640B2A);
  JUMPOUT(0x3F640B37);
}

//------------------------------------------------------------------------------
// Address: 0x3F640B2B
// Name: __math_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _math_exit(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<ebp>)
{
  int v4; // eax

  *(_BYTE *)(a4 - 1063317514) = __ROL1__(*(_BYTE *)(a4 - 1063317514), 141);
  if ( a1 == 0 )
  {
    if ( *(_DWORD *)(a3 + 4) != *(_DWORD *)(a2 + 4) )
      JUMPOUT(0x3F640B54);
    v4 = *(_DWORD *)(a3 + 8);
    if ( v4 == *(_DWORD *)(a2 + 8) )
      JUMPOUT(0x3F640C51);
    if ( (unsigned __int8)v4 == *(unsigned __int8 *)(a2 + 8)
      || 2 * ((unsigned __int8)v4 > (unsigned int)*(unsigned __int8 *)(a2 + 8)) == 1 )
    {
      if ( *(unsigned __int8 *)(a3 + 9) != *(unsigned __int8 *)(a2 + 9) )
        JUMPOUT(0x3F640C0F);
      JUMPOUT(0x3F640C15);
    }
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F640B55
// Name: __check_overflow_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F640C10
// Name: __CIlog_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F640EFA
// Name: __rtinfnpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _rtinfnpopse(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  *(_BYTE *)(a1 - 1946222524) = __ROR1__(*(_BYTE *)(a1 - 1946222524), 240);
  if ( a3 == 0 )
  {
    if ( (unsigned int)(a2 - 32) < 0x20 )
      JUMPOUT(0x3F640F31);
    JUMPOUT(0x3F640ABD);
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F640FBF
// Name: __rtinfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtinfpop()
{
  JUMPOUT(0x3F640FC1);
}

//------------------------------------------------------------------------------
// Address: 0x3F641087
// Name: __87except
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _87except(char a1@<zf>, int a2@<edx>, int a3@<ecx>, int a4@<ebp>, int (__cdecl *opcode)(_exception *))
{
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax

  *(_BYTE *)(a4 - 2046885820) = __ROR1__(*(_BYTE *)(a4 - 2046885820), 192);
  if ( !a1
    || *(unsigned __int8 *)(a3 - 18) != *(unsigned __int8 *)(a2 - 18)
    && 2 * (*(unsigned __int8 *)(a3 - 18) > (unsigned int)*(unsigned __int8 *)(a2 - 18)) != 1 )
  {
    goto LABEL_31;
  }
  v5 = *(unsigned __int8 *)(a3 - 17) - *(unsigned __int8 *)(a2 - 17);
  if ( v5 != 0 )
    v5 = 2 * (*(unsigned __int8 *)(a3 - 17) > (unsigned int)*(unsigned __int8 *)(a2 - 17)) - 1;
  if ( v5 != 0 )
    goto LABEL_31;
  v6 = *(_DWORD *)(a3 - 16);
  if ( v6 == *(_DWORD *)(a2 - 16) )
  {
    v8 = 0;
    goto LABEL_18;
  }
  if ( (unsigned __int8)v6 != *(unsigned __int8 *)(a2 - 16)
    && 2 * ((unsigned __int8)v6 > (unsigned int)*(unsigned __int8 *)(a2 - 16)) != 1
    || *(unsigned __int8 *)(a3 - 15) != *(unsigned __int8 *)(a2 - 15)
    && 2 * (*(unsigned __int8 *)(a3 - 15) > (unsigned int)*(unsigned __int8 *)(a2 - 15)) != 1
    || *(unsigned __int8 *)(a3 - 14) != *(unsigned __int8 *)(a2 - 14)
    && 2 * (*(unsigned __int8 *)(a3 - 14) > (unsigned int)*(unsigned __int8 *)(a2 - 14)) != 1 )
  {
LABEL_31:
    JUMPOUT(0x3F6412F2);
  }
  v7 = *(unsigned __int8 *)(a3 - 13) - *(unsigned __int8 *)(a2 - 13);
  if ( v7 != 0 )
    v7 = 2 * (*(unsigned __int8 *)(a3 - 13) > (unsigned int)*(unsigned __int8 *)(a2 - 13)) - 1;
  v8 = v7;
LABEL_18:
  if ( v8 != 0 )
    goto LABEL_31;
  v9 = *(_DWORD *)(a3 - 12);
  if ( v9 == *(_DWORD *)(a2 - 12) )
    JUMPOUT(0x3F6411E6);
  if ( (unsigned __int8)v9 == *(unsigned __int8 *)(a2 - 12) )
    JUMPOUT(0x3F64118B);
  __libm_setusermatherr(user_merr: opcode);
}

//------------------------------------------------------------------------------
// Address: 0x3F641183
// Name: ___libm_setusermatherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __libm_setusermatherr(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  if ( a1 == 0
    && (*(unsigned __int8 *)(a3 - 11) == *(unsigned __int8 *)(a2 - 11)
     || 2 * (*(unsigned __int8 *)(a3 - 11) > (unsigned int)*(unsigned __int8 *)(a2 - 11)) == 1) )
  {
    JUMPOUT(0x3F6411AA);
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F6411AC
// Name: ___libm_error_support
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __libm_error_support(char a1@<of>)
{
  if ( !a1 )
    JUMPOUT(0x3F6411A4);
}

//------------------------------------------------------------------------------
// Address: 0x3F64145C
// Name: __d_inttype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _d_inttype()
{
  JUMPOUT(0x3F64145D);
}

//------------------------------------------------------------------------------
// Address: 0x3F6414C0
// Name: __powhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _powhlp(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax

  if ( 2 * a1 == 1
    && (*(unsigned __int8 *)(a3 - 15) == *(unsigned __int8 *)(a2 - 15)
     || 2 * (*(unsigned __int8 *)(a3 - 15) > (unsigned int)*(unsigned __int8 *)(a2 - 15)) == 1) )
  {
    v3 = *(unsigned __int8 *)(a3 - 14) - *(unsigned __int8 *)(a2 - 14);
    if ( v3 != 0 )
      v3 = 2 * (*(unsigned __int8 *)(a3 - 14) > (unsigned int)*(unsigned __int8 *)(a2 - 14)) - 1;
    if ( v3 == 0 )
    {
      v4 = *(_DWORD *)(a3 - 13);
      if ( v4 == *(_DWORD *)(a2 - 13) )
      {
        v6 = 0;
      }
      else
      {
        if ( (unsigned __int8)v4 != *(unsigned __int8 *)(a2 - 13)
          && 2 * ((unsigned __int8)v4 > (unsigned int)*(unsigned __int8 *)(a2 - 13)) != 1
          || *(unsigned __int8 *)(a3 - 12) != *(unsigned __int8 *)(a2 - 12)
          && 2 * (*(unsigned __int8 *)(a3 - 12) > (unsigned int)*(unsigned __int8 *)(a2 - 12)) != 1
          || *(unsigned __int8 *)(a3 - 11) != *(unsigned __int8 *)(a2 - 11)
          && 2 * (*(unsigned __int8 *)(a3 - 11) > (unsigned int)*(unsigned __int8 *)(a2 - 11)) != 1 )
        {
          goto LABEL_37;
        }
        v5 = *(unsigned __int8 *)(a3 - 10) - *(unsigned __int8 *)(a2 - 10);
        if ( v5 != 0 )
          v5 = 2 * (*(unsigned __int8 *)(a3 - 10) > (unsigned int)*(unsigned __int8 *)(a2 - 10)) - 1;
        v6 = v5;
      }
      if ( v6 == 0 )
      {
        v7 = *(_DWORD *)(a3 - 9);
        if ( v7 == *(_DWORD *)(a2 - 9) )
          JUMPOUT(0x3F64161E);
        if ( ((unsigned __int8)v7 == *(unsigned __int8 *)(a2 - 9)
           || 2 * ((unsigned __int8)v7 > (unsigned int)*(unsigned __int8 *)(a2 - 9)) == 1)
          && (*(unsigned __int8 *)(a3 - 8) == *(unsigned __int8 *)(a2 - 8)
           || 2 * (*(unsigned __int8 *)(a3 - 8) > (unsigned int)*(unsigned __int8 *)(a2 - 8)) == 1) )
        {
          if ( *(unsigned __int8 *)(a3 - 7) != *(unsigned __int8 *)(a2 - 7) )
            JUMPOUT(0x3F6415FB);
          JUMPOUT(0x3F641601);
        }
      }
    }
  }
LABEL_37:
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F641600
// Name: _fdiv_main_routine
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall fdiv_main_routine(_DWORD *a1@<edi>)
{
  --*a1;
  _disable();
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F641717
// Name: __adj_fdiv_r
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _adj_fdiv_r()
{
  _enable();
  JUMPOUT(0x3F641718);
}

//------------------------------------------------------------------------------
// Address: 0x3F641BB6
// Name: __fdivp_sti_st
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _fdivp_sti_st()
{
  JUMPOUT(0x3F641BC7);
}

//------------------------------------------------------------------------------
// Address: 0x3F641BC9
// Name: __fdivrp_sti_st
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn _fdivrp_sti_st()
{
  JUMPOUT(0xB44D5E0F);
}

//------------------------------------------------------------------------------
// Address: 0x3F641BDC
// Name: __adj_fdiv_m32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _adj_fdiv_m32(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
  int v4; // esi

  v4 = a4 - a1;
  if ( (v4 == 0 || 2 * (v4 > 0) == 1)
    && (*(unsigned __int8 *)(a3 - 22) == *(unsigned __int8 *)(a2 - 22)
     || 2 * (*(unsigned __int8 *)(a3 - 22) > (unsigned int)*(unsigned __int8 *)(a2 - 22)) == 1) )
  {
    if ( *(unsigned __int8 *)(a3 - 21) != *(unsigned __int8 *)(a2 - 21) )
      JUMPOUT(0x3F641C25);
    JUMPOUT(0x3F641C31);
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F641C28
// Name: __adj_fdiv_m64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _adj_fdiv_m64(int a1@<edx>, int a2@<ecx>, int a3@<ebp>, _DWORD *a4@<edi>, int a5@<esi>)
{
  int v5; // esi
  int v6; // eax

  ++*(_DWORD *)(a3 - 1048244288);
  --*a4;
  BYTE1(a1) = 113;
  __inbyte(a1);
  v5 = a5 - *(unsigned __int8 *)(a1 - 20);
  if ( v5 != 0 )
    v5 = 2 * (v5 > 0) - 1;
  if ( v5 == 0 )
  {
    v6 = *(_DWORD *)(a2 - 19);
    if ( v6 != *(_DWORD *)(a1 - 19) )
    {
      if ( (unsigned __int8)v6 != *(unsigned __int8 *)(a1 - 19) )
        JUMPOUT(0x3F641C72);
      JUMPOUT(0x3F641C7E);
    }
    JUMPOUT(0x3F641CD9);
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F641C74
// Name: __adj_fdiv_m16i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _adj_fdiv_m16i(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  if ( a1 == 0
    && (*(unsigned __int8 *)(a3 - 18) == *(unsigned __int8 *)(a2 - 18)
     || 2 * (*(unsigned __int8 *)(a3 - 18) > (unsigned int)*(unsigned __int8 *)(a2 - 18)) == 1) )
  {
    JUMPOUT(0x3F641CA7);
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F641CA8
// Name: __adj_fdiv_m32i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _adj_fdiv_m32i(int a1@<eax>, int a2@<ebp>)
{
  *(_BYTE *)(a2 - 1063317514) = __ROL1__(*(_BYTE *)(a2 - 1063317514), 141);
  if ( a1 == 0 )
    JUMPOUT(0x3F641CDB);
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F641CDC
// Name: __adj_fdivr_m32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _adj_fdivr_m32@<eax>(unsigned __int8 a1@<al>, int a2@<edx>, int a3@<ecx>, int a4@<ebx>, _BYTE *a5@<edi>)
{
  bool v5; // zf

  *a5 = __ROR1__(*a5, 133);
  v5 = (*(_DWORD *)(a4 + 1111224641))-- == 1;
  __asm { icebp }
  if ( v5 )
    JUMPOUT(0x3F641D64);
  if ( a1 != *(unsigned __int8 *)(a2 - 15) && 2 * (a1 > (unsigned int)*(unsigned __int8 *)(a2 - 15)) != 1
    || *(unsigned __int8 *)(a3 - 14) != *(unsigned __int8 *)(a2 - 14)
    && 2 * (*(unsigned __int8 *)(a3 - 14) > (unsigned int)*(unsigned __int8 *)(a2 - 14)) != 1 )
  {
    JUMPOUT(0x3F6412F2);
  }
  return _adj_fdivr_m64();
}

//------------------------------------------------------------------------------
// Address: 0x3F641D28
// Name: __adj_fdivr_m64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _adj_fdivr_m64(int a1, int a2)
{
  int v2; // esi

  if ( *(unsigned __int8 *)(a1 - 13) == *(unsigned __int8 *)(a2 - 13)
    || 2 * (*(unsigned __int8 *)(a1 - 13) > (unsigned int)*(unsigned __int8 *)(a2 - 13)) == 1 )
  {
    v2 = *(unsigned __int8 *)(a1 - 12) - *(unsigned __int8 *)(a2 - 12);
    if ( v2 != 0 )
      v2 = 2 * (*(unsigned __int8 *)(a1 - 12) > (unsigned int)*(unsigned __int8 *)(a2 - 12)) - 1;
    if ( v2 == 0 )
      return _adj_fdivr_m16i();
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F641D74
// Name: __adj_fdivr_m16i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _adj_fdivr_m16i(char a1@<zf>, unsigned __int8 a2@<al>, int a3@<edx>, int a4@<ecx>)
{
  if ( !a1 )
  {
    if ( a2 == *(unsigned __int8 *)(a3 - 11) || 2 * (a2 > (unsigned int)*(unsigned __int8 *)(a3 - 11)) == 1 )
    {
      if ( *(unsigned __int8 *)(a4 - 10) != *(unsigned __int8 *)(a3 - 10) )
        JUMPOUT(0x3F641DA7);
      JUMPOUT(0x3F641DB3);
    }
    JUMPOUT(0x3F6412F2);
  }
  JUMPOUT(0x3F641DEF);
}

//------------------------------------------------------------------------------
// Address: 0x3F641DA8
// Name: __adj_fdivr_m32i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _adj_fdivr_m32i@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  if ( a1 != 0
    || *(unsigned __int8 *)(a3 - 9) != *(unsigned __int8 *)(a2 - 9)
    && 2 * (*(unsigned __int8 *)(a3 - 9) > (unsigned int)*(unsigned __int8 *)(a2 - 9)) != 1 )
  {
    JUMPOUT(0x3F6412F2);
  }
  return _safe_fdiv();
}

//------------------------------------------------------------------------------
// Address: 0x3F641DDC
// Name: __safe_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _safe_fdiv()
{
  return _safe_fdivr();
}

//------------------------------------------------------------------------------
// Address: 0x3F641DF1
// Name: __safe_fdivr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _safe_fdivr(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  if ( a1 == 0 )
  {
    if ( *(_DWORD *)(a3 - 7) != *(_DWORD *)(a2 - 7) )
      JUMPOUT(0x3F641E04);
    JUMPOUT(0x3F641E7A);
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F641E06
// Name: __fprem_common
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fprem_common(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
  int v4; // edx
  int v5; // esi
  int v6; // esi

  v4 = a2 + 1;
  v5 = a4 - a1;
  if ( (v5 == 0 || 2 * (v5 > 0) == 1)
    && (*(unsigned __int8 *)(a3 - 6) == *(unsigned __int8 *)(v4 - 6)
     || 2 * (*(unsigned __int8 *)(a3 - 6) > (unsigned int)*(unsigned __int8 *)(v4 - 6)) == 1)
    && (*(unsigned __int8 *)(a3 - 5) == *(unsigned __int8 *)(v4 - 5)
     || 2 * (*(unsigned __int8 *)(a3 - 5) > (unsigned int)*(unsigned __int8 *)(v4 - 5)) == 1) )
  {
    v6 = *(unsigned __int8 *)(a3 - 4) - *(unsigned __int8 *)(v4 - 4);
    if ( v6 != 0 )
      v6 = 2 * (*(unsigned __int8 *)(a3 - 4) > (unsigned int)*(unsigned __int8 *)(v4 - 4)) - 1;
    if ( v6 == 0
      && (*(unsigned __int8 *)(a3 - 3) == *(unsigned __int8 *)(v4 - 3)
       || 2 * (*(unsigned __int8 *)(a3 - 3) > (unsigned int)*(unsigned __int8 *)(v4 - 3)) == 1) )
    {
      if ( *(unsigned __int8 *)(a3 - 2) != *(unsigned __int8 *)(v4 - 2) )
        JUMPOUT(0x3F6416AB);
      JUMPOUT(0x3F6416B3);
    }
  }
  JUMPOUT(0x3F6412F2);
}

//------------------------------------------------------------------------------
// Address: 0x3F6420BE
// Name: __fprem1_common
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fprem1_common(char a1@<zf>, int a2@<eax>, int a3@<ecx>, int _ESI@<esi>)
{
  int v4; // esi
  int v5; // esi
  int v6; // esi

  __asm { rep test esi, esi }
  if ( a1
    && (*(unsigned __int8 *)(a2 + 9) == *(unsigned __int8 *)(a3 + 9)
     || 2 * (*(unsigned __int8 *)(a2 + 9) > (unsigned int)*(unsigned __int8 *)(a3 + 9)) == 1)
    && (*(unsigned __int8 *)(a2 + 10) == *(unsigned __int8 *)(a3 + 10)
     || 2 * (*(unsigned __int8 *)(a2 + 10) > (unsigned int)*(unsigned __int8 *)(a3 + 10)) == 1) )
  {
    v4 = *(unsigned __int8 *)(a2 + 11) - *(unsigned __int8 *)(a3 + 11);
    if ( v4 != 0 )
      v4 = 2 * (*(unsigned __int8 *)(a2 + 11) > (unsigned int)*(unsigned __int8 *)(a3 + 11)) - 1;
    if ( v4 == 0 )
    {
      if ( *(_DWORD *)(a2 + 12) == *(_DWORD *)(a3 + 12) )
      {
        v5 = 0;
      }
      else
      {
        if ( *(unsigned __int8 *)(a2 + 12) != *(unsigned __int8 *)(a3 + 12)
          && 2 * (*(unsigned __int8 *)(a2 + 12) > (unsigned int)*(unsigned __int8 *)(a3 + 12)) != 1
          || *(unsigned __int8 *)(a2 + 13) != *(unsigned __int8 *)(a3 + 13)
          && 2 * (*(unsigned __int8 *)(a2 + 13) > (unsigned int)*(unsigned __int8 *)(a3 + 13)) != 1
          || *(unsigned __int8 *)(a2 + 14) != *(unsigned __int8 *)(a3 + 14)
          && 2 * (*(unsigned __int8 *)(a2 + 14) > (unsigned int)*(unsigned __int8 *)(a3 + 14)) != 1 )
        {
          goto LABEL_52;
        }
        v5 = *(unsigned __int8 *)(a2 + 15) - *(unsigned __int8 *)(a3 + 15);
        if ( v5 != 0 )
          v5 = 2 * (*(unsigned __int8 *)(a2 + 15) > (unsigned int)*(unsigned __int8 *)(a3 + 15)) - 1;
      }
      if ( v5 != 0 )
        goto LABEL_52;
      if ( *(_DWORD *)(a2 + 16) == *(_DWORD *)(a3 + 16) )
      {
        v6 = 0;
      }
      else
      {
        if ( *(unsigned __int8 *)(a2 + 16) != *(unsigned __int8 *)(a3 + 16)
          && 2 * (*(unsigned __int8 *)(a2 + 16) > (unsigned int)*(unsigned __int8 *)(a3 + 16)) != 1
          || *(unsigned __int8 *)(a2 + 17) != *(unsigned __int8 *)(a3 + 17)
          && 2 * (*(unsigned __int8 *)(a2 + 17) > (unsigned int)*(unsigned __int8 *)(a3 + 17)) != 1
          || *(unsigned __int8 *)(a2 + 18) != *(unsigned __int8 *)(a3 + 18)
          && 2 * (*(unsigned __int8 *)(a2 + 18) > (unsigned int)*(unsigned __int8 *)(a3 + 18)) != 1 )
        {
          goto LABEL_52;
        }
        v6 = *(unsigned __int8 *)(a2 + 19) - *(unsigned __int8 *)(a3 + 19);
        if ( v6 != 0 )
          v6 = 2 * (*(unsigned __int8 *)(a2 + 19) > (unsigned int)*(unsigned __int8 *)(a3 + 19)) - 1;
      }
      if ( v6 == 0 )
      {
        if ( *(_DWORD *)(a2 + 20) == *(_DWORD *)(a3 + 20) )
          JUMPOUT(0x3F6422D4);
        if ( (*(unsigned __int8 *)(a2 + 20) == *(unsigned __int8 *)(a3 + 20)
           || 2 * (*(unsigned __int8 *)(a2 + 20) > (unsigned int)*(unsigned __int8 *)(a3 + 20)) == 1)
          && (*(unsigned __int8 *)(a2 + 21) == *(unsigned __int8 *)(a3 + 21)
           || 2 * (*(unsigned __int8 *)(a2 + 21) > (unsigned int)*(unsigned __int8 *)(a3 + 21)) == 1)
          && (*(unsigned __int8 *)(a2 + 22) == *(unsigned __int8 *)(a3 + 22)
           || 2 * (*(unsigned __int8 *)(a2 + 22) > (unsigned int)*(unsigned __int8 *)(a3 + 22)) == 1) )
        {
          JUMPOUT(0x3F6422C3);
        }
      }
    }
  }
LABEL_52:
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F6422C4
// Name: __adj_fprem1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _adj_fprem1(char a1@<cf>, int a2@<eax>, int a3@<ecx>, _DWORD *a4@<ebx>, int a5@<esi>)
{
  int v5; // esi

  *a4 += a5 + a1;
  if ( 2 * (_DWORD)a4 != 1 )
    goto LABEL_21;
  if ( *(_DWORD *)(a2 + 24) == *(_DWORD *)(a3 + 24) )
  {
    v5 = 0;
  }
  else
  {
    if ( *(unsigned __int8 *)(a2 + 24) != *(unsigned __int8 *)(a3 + 24)
      && 2 * (*(unsigned __int8 *)(a2 + 24) > (unsigned int)*(unsigned __int8 *)(a3 + 24)) != 1
      || *(unsigned __int8 *)(a2 + 25) != *(unsigned __int8 *)(a3 + 25)
      && 2 * (*(unsigned __int8 *)(a2 + 25) > (unsigned int)*(unsigned __int8 *)(a3 + 25)) != 1
      || *(unsigned __int8 *)(a2 + 26) != *(unsigned __int8 *)(a3 + 26)
      && 2 * (*(unsigned __int8 *)(a2 + 26) > (unsigned int)*(unsigned __int8 *)(a3 + 26)) != 1 )
    {
      goto LABEL_21;
    }
    v5 = *(unsigned __int8 *)(a2 + 27) - *(unsigned __int8 *)(a3 + 27);
    if ( v5 != 0 )
      v5 = 2 * (*(unsigned __int8 *)(a2 + 27) > (unsigned int)*(unsigned __int8 *)(a3 + 27)) - 1;
  }
  if ( v5 == 0 )
  {
    if ( *(_DWORD *)(a2 + 28) != *(_DWORD *)(a3 + 28) )
      JUMPOUT(0x3F642376);
    JUMPOUT(0x3F6423E8);
  }
LABEL_21:
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F642379
// Name: __safe_fprem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _safe_fprem(int a1, __int16 a2)
{
  HIBYTE(a2) = 89;
  return _safe_fprem1(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F64237F
// Name: __safe_fprem1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F642385
// Name: __adj_fpatan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _adj_fpatan()
{
  JUMPOUT(0x3F642388);
}

//------------------------------------------------------------------------------
// Address: 0x3F64238B
// Name: __raise_exc_ex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _raise_exc_ex(
        char a1@<cf>,
        unsigned __int8 *a2@<eax>,
        unsigned int a3@<edx>,
        unsigned __int8 *a4@<ecx>,
        int a5@<ebx>)
{
  int v5; // esi
  unsigned int v6; // edi

  if ( a5 == 0
    && (a2[29] == a4[29] || 2 * (a2[29] > (unsigned int)a4[29]) == 1)
    && (a2[30] == a4[30] || 2 * (a2[30] > (unsigned int)a4[30]) == 1) )
  {
    v5 = a2[31] - a4[31];
    if ( v5 != 0 )
      v5 = 2 * (a2[31] > (unsigned int)a4[31]) - 1;
    if ( v5 == 0 )
    {
      v6 = -a1 - a3;
      if ( v6 < a3 )
      {
        switch ( v6 )
        {
          case 1u:
            JUMPOUT(0x3F642BDF);
          case 2u:
            JUMPOUT(0x3F642FE1);
          default:
            JUMPOUT(0x3F6427E3);
        }
      }
      JUMPOUT(0x3F641F82);
    }
  }
  JUMPOUT(0x3F6427E5);
}

//------------------------------------------------------------------------------
// Address: 0x3F642665
// Name: __raise_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _raise_exc(int a1@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  --*(_DWORD *)(a2 + 267814386);
  if ( a3 != *(unsigned __int8 *)(a1 - 11) )
    JUMPOUT(0x3F642683);
  JUMPOUT(0x3F642691);
}

//------------------------------------------------------------------------------
// Address: 0x3F642686
// Name: __raise_excf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _raise_excf(int a1@<ebx>)
{
  --*(_DWORD *)(a1 + 267814386);
  JUMPOUT(0x3F64268F);
}

//------------------------------------------------------------------------------
// Address: 0x3F6426A7
// Name: __handle_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _handle_exc(int a1@<ebx>)
{
  --*(_DWORD *)(a1 + 267814386);
  JUMPOUT(0x3F6426B0);
}

//------------------------------------------------------------------------------
// Address: 0x3F642888
// Name: __set_errno_from_matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _set_errno_from_matherr(
        char a1@<zf>,
        unsigned int a2@<eax>,
        int a3@<ecx>,
        int a4@<esi>,
        unsigned int matherrtype)
{
  __outdword(0x2Bu, a2);
  if ( !a1 && 2 * (a4 > 0) != 1 )
    JUMPOUT(0x3F642410);
  if ( *(unsigned __int8 *)(a2 - 24) == *(unsigned __int8 *)(a3 - 24) )
    JUMPOUT(0x3F6428C3);
  get_fname(opcode: matherrtype);
}

//------------------------------------------------------------------------------
// Address: 0x3F6428B0
// Name: _get_fname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall get_fname(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
  LOBYTE(a2) = a4 > 0;
  if ( 2 * a2 == 1 )
  {
    if ( *(unsigned __int8 *)(a1 - 23) != *(unsigned __int8 *)(a3 - 23) )
      JUMPOUT(0x3F6428CF);
    JUMPOUT(0x3F6428E4);
  }
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F6428D0
// Name: __errcode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _errcode@<st0>(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        int a4@<ebp>,
        unsigned int flags,
        unsigned int a6,
        long double a7,
        long double a8,
        long double a9,
        unsigned int a10)
{
  *(_BYTE *)(a4 - 1029763082) = __ROL1__(*(_BYTE *)(a4 - 1029763082), a3);
  if ( 2 * a2 != 1 )
    JUMPOUT(0x3F642410);
  if ( *(unsigned __int8 *)(a1 - 22) == *(unsigned __int8 *)(a3 - 22) )
    JUMPOUT(0x3F642901);
  return _umatherr(type: flags, opcode: a6, arg1: a7, arg2: a8, retval: a9, cw: a10);
}

//------------------------------------------------------------------------------
// Address: 0x3F6428FD
// Name: __umatherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _umatherr@<st0>(
        int a1@<eax>,
        int a2@<ecx>,
        int a3@<esi>,
        unsigned int type,
        long double opcode,
        unsigned int arg1)
{
  int v6; // edx
  int v7; // esi

  if ( a3 != 0 )
    goto LABEL_14;
  v6 = *(_DWORD *)(a1 - 21);
  if ( v6 == *(_DWORD *)(a2 - 21) )
  {
    v7 = 0;
    goto LABEL_12;
  }
  if ( (unsigned __int8)v6 != *(unsigned __int8 *)(a2 - 21)
    && 2 * ((unsigned __int8)v6 > (unsigned int)*(unsigned __int8 *)(a2 - 21)) != 1
    || *(unsigned __int8 *)(a1 - 20) != *(unsigned __int8 *)(a2 - 20)
    && 2 * (*(unsigned __int8 *)(a1 - 20) > (unsigned int)*(unsigned __int8 *)(a2 - 20)) != 1
    || *(unsigned __int8 *)(a1 - 19) != *(unsigned __int8 *)(a2 - 19)
    && 2 * (*(unsigned __int8 *)(a1 - 19) > (unsigned int)*(unsigned __int8 *)(a2 - 19)) != 1 )
  {
LABEL_14:
    JUMPOUT(0x3F642410);
  }
  v7 = *(unsigned __int8 *)(a1 - 18) - *(unsigned __int8 *)(a2 - 18);
  if ( v7 != 0 )
    v7 = 2 * (*(unsigned __int8 *)(a1 - 18) > (unsigned int)*(unsigned __int8 *)(a2 - 18)) - 1;
LABEL_12:
  if ( v7 != 0 )
    goto LABEL_14;
  return _handle_qnan1(opcode: type, x: opcode, savedcw: arg1);
}

//------------------------------------------------------------------------------
// Address: 0x3F64299B
// Name: __handle_qnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _handle_qnan1(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  if ( a2 != *(_DWORD *)(a3 - 17) )
  {
    if ( ((unsigned __int8)a2 == *(unsigned __int8 *)(a3 - 17)
       || 2 * ((unsigned __int8)a2 > (unsigned int)*(unsigned __int8 *)(a3 - 17)) == 1)
      && (*(unsigned __int8 *)(a1 - 16) == *(unsigned __int8 *)(a3 - 16)
       || 2 * (*(unsigned __int8 *)(a1 - 16) > (unsigned int)*(unsigned __int8 *)(a3 - 16)) == 1) )
    {
      if ( *(unsigned __int8 *)(a1 - 15) != *(unsigned __int8 *)(a3 - 15) )
        JUMPOUT(0x3F6429ED);
      JUMPOUT(0x3F642A02);
    }
    JUMPOUT(0x3F642410);
  }
  JUMPOUT(0x3F642A1D);
}

//------------------------------------------------------------------------------
// Address: 0x3F6429EE
// Name: __handle_qnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _handle_qnan2(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<ebp>)
{
  int v4; // esi
  int v5; // edx
  int v6; // esi

  *(_BYTE *)(a4 - 1029763082) = __ROL1__(*(_BYTE *)(a4 - 1029763082), a3);
  if ( 2 * a2 == 1 )
  {
    v4 = *(unsigned __int8 *)(a1 - 14) - *(unsigned __int8 *)(a3 - 14);
    if ( v4 != 0 )
      v4 = 2 * (*(unsigned __int8 *)(a1 - 14) > (unsigned int)*(unsigned __int8 *)(a3 - 14)) - 1;
    if ( v4 == 0 )
    {
      v5 = *(_DWORD *)(a1 - 13);
      if ( v5 == *(_DWORD *)(a3 - 13) )
      {
        v6 = 0;
      }
      else
      {
        if ( (unsigned __int8)v5 != *(unsigned __int8 *)(a3 - 13)
          && 2 * ((unsigned __int8)v5 > (unsigned int)*(unsigned __int8 *)(a3 - 13)) != 1
          || *(unsigned __int8 *)(a1 - 12) != *(unsigned __int8 *)(a3 - 12)
          && 2 * (*(unsigned __int8 *)(a1 - 12) > (unsigned int)*(unsigned __int8 *)(a3 - 12)) != 1
          || *(unsigned __int8 *)(a1 - 11) != *(unsigned __int8 *)(a3 - 11)
          && 2 * (*(unsigned __int8 *)(a1 - 11) > (unsigned int)*(unsigned __int8 *)(a3 - 11)) != 1 )
        {
          goto LABEL_29;
        }
        v6 = *(unsigned __int8 *)(a1 - 10) - *(unsigned __int8 *)(a3 - 10);
        if ( v6 != 0 )
          v6 = 2 * (*(unsigned __int8 *)(a1 - 10) > (unsigned int)*(unsigned __int8 *)(a3 - 10)) - 1;
      }
      if ( v6 == 0 )
      {
        if ( *(_DWORD *)(a1 - 9) == *(_DWORD *)(a3 - 9) )
          JUMPOUT(0x3F642B3C);
        if ( (*(unsigned __int8 *)(a1 - 9) == *(unsigned __int8 *)(a3 - 9)
           || 2 * (*(unsigned __int8 *)(a1 - 9) > (unsigned int)*(unsigned __int8 *)(a3 - 9)) == 1)
          && (*(unsigned __int8 *)(a1 - 8) == *(unsigned __int8 *)(a3 - 8)
           || 2 * (*(unsigned __int8 *)(a1 - 8) > (unsigned int)*(unsigned __int8 *)(a3 - 8)) == 1) )
        {
          JUMPOUT(0x3F642B04);
        }
      }
    }
  }
LABEL_29:
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F642B07
// Name: __except2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _except2(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
  int v4; // esi
  int v5; // esi
  int v6; // edx
  int v7; // esi

  v4 = a4 - a2;
  if ( v4 == 0 || 2 * (v4 > 0) == 1 )
  {
    v5 = *(unsigned __int8 *)(a1 - 6) - *(unsigned __int8 *)(a3 - 6);
    if ( v5 != 0 )
      v5 = 2 * (*(unsigned __int8 *)(a1 - 6) > (unsigned int)*(unsigned __int8 *)(a3 - 6)) - 1;
    if ( v5 == 0 )
    {
      v6 = *(_DWORD *)(a1 - 5);
      if ( v6 == *(_DWORD *)(a3 - 5) )
      {
        v7 = 0;
LABEL_16:
        if ( v7 == 0 )
          JUMPOUT(0x3F642BD5);
        goto LABEL_18;
      }
      if ( ((unsigned __int8)v6 == *(unsigned __int8 *)(a3 - 5)
         || 2 * ((unsigned __int8)v6 > (unsigned int)*(unsigned __int8 *)(a3 - 5)) == 1)
        && (*(unsigned __int8 *)(a1 - 4) == *(unsigned __int8 *)(a3 - 4)
         || 2 * (*(unsigned __int8 *)(a1 - 4) > (unsigned int)*(unsigned __int8 *)(a3 - 4)) == 1)
        && (*(unsigned __int8 *)(a1 - 3) == *(unsigned __int8 *)(a3 - 3)
         || 2 * (*(unsigned __int8 *)(a1 - 3) > (unsigned int)*(unsigned __int8 *)(a3 - 3)) == 1) )
      {
        v7 = *(unsigned __int8 *)(a1 - 2) - *(unsigned __int8 *)(a3 - 2);
        if ( v7 != 0 )
          v7 = 2 * (*(unsigned __int8 *)(a1 - 2) > (unsigned int)*(unsigned __int8 *)(a3 - 2)) - 1;
        goto LABEL_16;
      }
    }
  }
LABEL_18:
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F642BE4
// Name: __copysign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _copysign()
{
  JUMPOUT(0x3F6427E5);
}

//------------------------------------------------------------------------------
// Address: 0x3F642C0A
// Name: __chgsign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _chgsign(int a1@<eax>, int a2@<ecx>, int a3@<esi>)
{
  if ( 2 * (a3 > 0) == 1 )
  {
    if ( *(unsigned __int8 *)(a1 - 29) != *(unsigned __int8 *)(a2 - 29) )
      JUMPOUT(0x3F642C32);
    JUMPOUT(0x3F642C40);
  }
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F642C35
// Name: __scalb
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _scalb(int a1@<ebx>, _DWORD *a2@<edi>)
{
  --*(_DWORD *)(a1 + 267814386);
  --*a2;
  __inbyte(0xFu);
  __inbyte(0x2Bu);
  JUMPOUT(0x3F642C49);
}

//------------------------------------------------------------------------------
// Address: 0x3F642C4B
// Name: __logb
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _logb(char a1@<cf>, int a2@<eax>, int a3@<edx>, int a4@<ecx>)
{
  bool v4; // of
  int v5; // eax
  int v6; // esi
  int v7; // edx
  int v8; // esi
  int v9; // edx

  v4 = __OFADD__(a1, a2);
  v5 = a1 + a2;
  v4 |= __OFADD__(-159002061, v5);
  v5 -= 159002061;
  LOBYTE(a3) = !((v5 < 0) ^ v4 | (v5 == 0));
  if ( 2 * a3 == 1 )
  {
    v6 = *(unsigned __int8 *)(v5 - 27) - *(unsigned __int8 *)(a4 - 27);
    if ( v6 != 0 )
      v6 = 2 * (*(unsigned __int8 *)(v5 - 27) > (unsigned int)*(unsigned __int8 *)(a4 - 27)) - 1;
    if ( v6 == 0 )
    {
      v7 = *(_DWORD *)(v5 - 26);
      if ( v7 == *(_DWORD *)(a4 - 26) )
      {
        v8 = 0;
      }
      else
      {
        if ( (unsigned __int8)v7 != *(unsigned __int8 *)(a4 - 26)
          && 2 * ((unsigned __int8)v7 > (unsigned int)*(unsigned __int8 *)(a4 - 26)) != 1
          || *(unsigned __int8 *)(v5 - 25) != *(unsigned __int8 *)(a4 - 25)
          && 2 * (*(unsigned __int8 *)(v5 - 25) > (unsigned int)*(unsigned __int8 *)(a4 - 25)) != 1
          || *(unsigned __int8 *)(v5 - 24) != *(unsigned __int8 *)(a4 - 24)
          && 2 * (*(unsigned __int8 *)(v5 - 24) > (unsigned int)*(unsigned __int8 *)(a4 - 24)) != 1 )
        {
          goto LABEL_27;
        }
        v8 = *(unsigned __int8 *)(v5 - 23) - *(unsigned __int8 *)(a4 - 23);
        if ( v8 != 0 )
          v8 = 2 * (*(unsigned __int8 *)(v5 - 23) > (unsigned int)*(unsigned __int8 *)(a4 - 23)) - 1;
      }
      if ( v8 == 0 )
      {
        v9 = *(_DWORD *)(v5 - 22);
        if ( v9 != *(_DWORD *)(a4 - 22) )
        {
          if ( (unsigned __int8)v9 != *(unsigned __int8 *)(a4 - 22) )
            JUMPOUT(0x3F642D2C);
          JUMPOUT(0x3F642D3D);
        }
        JUMPOUT(0x3F642D9A);
      }
    }
  }
LABEL_27:
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F642D2E
// Name: __nextafter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge _nextafter(
        long double x,
        long double y,
        float y_4,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40,
        float a41,
        float a42,
        float a43,
        float a44,
        float a45,
        float a46,
        float a47,
        float a48,
        float a49,
        float a50,
        float a51,
        float a52,
        float a53,
        float a54,
        float a55,
        float a56,
        float a57,
        float a58,
        float a59,
        float a60,
        float a61,
        float a62,
        float a63,
        float a64)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F642FC3
// Name: __finite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _finite()
{
  JUMPOUT(0x3F642FD9);
}

//------------------------------------------------------------------------------
// Address: 0x3F642FD8
// Name: __isnan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _isnan()
{
  JUMPOUT(0x3F642FDF);
}

//------------------------------------------------------------------------------
// Address: 0x3F643006
// Name: __fpclass
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _fpclass(int a1, int a2)
{
  if ( 2 * a2 == 1 )
    JUMPOUT(0x3F642BDF);
  JUMPOUT(0x3F643425);
}

//------------------------------------------------------------------------------
// Address: 0x3F64309A
// Name: __set_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _set_exp(int a1@<eax>, int a2@<ecx>, int a3@<esi>)
{
  int v3; // edx

  if ( a3 == 0 )
  {
    v3 = *(_DWORD *)(a1 - 27);
    if ( v3 != *(_DWORD *)(a2 - 27) )
    {
      if ( (unsigned __int8)v3 != *(unsigned __int8 *)(a2 - 27) )
        JUMPOUT(0x3F6430C1);
      JUMPOUT(0x3F6430CF);
    }
    JUMPOUT(0x3F64312C);
  }
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F6430C4
// Name: __get_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _get_exp(int a1@<ebx>)
{
  --*(_DWORD *)(a1 + 267814386);
  JUMPOUT(0x3F6430CD);
}

//------------------------------------------------------------------------------
// Address: 0x3F6430D9
// Name: __add_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _add_exp@<st0>(char a1@<zf>, int a2@<eax>, int a3@<ecx>, int a4@<esi>, long double x, int exp)
{
  if ( !a1 && 2 * (a4 > 0) != 1 )
    JUMPOUT(0x3F642410);
  if ( *(unsigned __int8 *)(a2 - 25) == *(unsigned __int8 *)(a3 - 25) )
    JUMPOUT(0x3F643111);
  return _set_bexp(x, bexp: exp);
}

//------------------------------------------------------------------------------
// Address: 0x3F643103
// Name: __set_bexp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _set_bexp(int a1@<eax>, int a2@<edx>, int a3@<ecx>, long double x)
{
  if ( 2 * a2 != 1 )
    JUMPOUT(0x3F642410);
  if ( *(unsigned __int8 *)(a1 - 24) == *(unsigned __int8 *)(a3 - 24) )
    JUMPOUT(0x3F64312E);
  _sptype(x);
}

//------------------------------------------------------------------------------
// Address: 0x3F643128
// Name: __sptype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _sptype@<st0>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, long double x, int *x_4)
{
  int v5; // edx

  if ( a2 == 0 )
  {
    v5 = *(_DWORD *)(a1 - 23);
    if ( v5 == *(_DWORD *)(a3 - 23) )
      JUMPOUT(0x3F6431BB);
    if ( ((unsigned __int8)v5 == *(unsigned __int8 *)(a3 - 23)
       || 2 * ((unsigned __int8)v5 > (unsigned int)*(unsigned __int8 *)(a3 - 23)) == 1)
      && (*(unsigned __int8 *)(a1 - 22) == *(unsigned __int8 *)(a3 - 22)
       || 2 * (*(unsigned __int8 *)(a1 - 22) > (unsigned int)*(unsigned __int8 *)(a3 - 22)) == 1) )
    {
      return _decomp(x, pexp: x_4);
    }
  }
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F643183
// Name: __decomp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _decomp(int a1@<eax>, int a2@<ecx>, int a3@<esi>)
{
  int v3; // esi
  int v4; // esi
  int v5; // edx

  v3 = a3 - *(unsigned __int8 *)(a2 - 21);
  if ( v3 == 0 || 2 * (v3 > 0) == 1 )
  {
    v4 = *(unsigned __int8 *)(a1 - 20) - *(unsigned __int8 *)(a2 - 20);
    if ( v4 != 0 )
      v4 = 2 * (*(unsigned __int8 *)(a1 - 20) > (unsigned int)*(unsigned __int8 *)(a2 - 20)) - 1;
    if ( v4 == 0 )
    {
      v5 = *(_DWORD *)(a1 - 19);
      if ( v5 == *(_DWORD *)(a2 - 19) )
        JUMPOUT(0x3F64324A);
      if ( ((unsigned __int8)v5 == *(unsigned __int8 *)(a2 - 19)
         || 2 * ((unsigned __int8)v5 > (unsigned int)*(unsigned __int8 *)(a2 - 19)) == 1)
        && (*(unsigned __int8 *)(a1 - 18) == *(unsigned __int8 *)(a2 - 18)
         || 2 * (*(unsigned __int8 *)(a1 - 18) > (unsigned int)*(unsigned __int8 *)(a2 - 18)) == 1)
        && (*(unsigned __int8 *)(a1 - 17) == *(unsigned __int8 *)(a2 - 17)
         || 2 * (*(unsigned __int8 *)(a1 - 17) > (unsigned int)*(unsigned __int8 *)(a2 - 17)) == 1) )
      {
        JUMPOUT(0x3F64322F);
      }
    }
  }
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F643232
// Name: _ldexp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall ldexp(int a1@<eax>, int _ECX@<ecx>, int a3@<esi>)
{
  int v4; // esi
  int v5; // esi
  int v6; // edx
  int v7; // esi
  int v8; // edx

  __asm { lock movzx edx, byte ptr [ecx-10h] }
  v4 = a3 - _EDX;
  if ( v4 != 0 )
    v4 = 2 * (v4 > 0) - 1;
  if ( v4 == 0 )
  {
    if ( *(_DWORD *)(a1 - 15) == *(_DWORD *)(_ECX - 15) )
    {
      v5 = 0;
    }
    else
    {
      if ( *(unsigned __int8 *)(a1 - 15) != *(unsigned __int8 *)(_ECX - 15)
        && 2 * (*(unsigned __int8 *)(a1 - 15) > (unsigned int)*(unsigned __int8 *)(_ECX - 15)) != 1
        || *(unsigned __int8 *)(a1 - 14) != *(unsigned __int8 *)(_ECX - 14)
        && 2 * (*(unsigned __int8 *)(a1 - 14) > (unsigned int)*(unsigned __int8 *)(_ECX - 14)) != 1
        || *(unsigned __int8 *)(a1 - 13) != *(unsigned __int8 *)(_ECX - 13)
        && 2 * (*(unsigned __int8 *)(a1 - 13) > (unsigned int)*(unsigned __int8 *)(_ECX - 13)) != 1 )
      {
        goto LABEL_44;
      }
      v5 = *(unsigned __int8 *)(a1 - 12) - *(unsigned __int8 *)(_ECX - 12);
      if ( v5 != 0 )
        v5 = 2 * (*(unsigned __int8 *)(a1 - 12) > (unsigned int)*(unsigned __int8 *)(_ECX - 12)) - 1;
    }
    if ( v5 != 0 )
      goto LABEL_44;
    v6 = *(_DWORD *)(a1 - 11);
    if ( v6 == *(_DWORD *)(_ECX - 11) )
    {
      v7 = 0;
    }
    else
    {
      if ( (unsigned __int8)v6 != *(unsigned __int8 *)(_ECX - 11)
        && 2 * ((unsigned __int8)v6 > (unsigned int)*(unsigned __int8 *)(_ECX - 11)) != 1
        || *(unsigned __int8 *)(a1 - 10) != *(unsigned __int8 *)(_ECX - 10)
        && 2 * (*(unsigned __int8 *)(a1 - 10) > (unsigned int)*(unsigned __int8 *)(_ECX - 10)) != 1
        || *(unsigned __int8 *)(a1 - 9) != *(unsigned __int8 *)(_ECX - 9)
        && 2 * (*(unsigned __int8 *)(a1 - 9) > (unsigned int)*(unsigned __int8 *)(_ECX - 9)) != 1 )
      {
        goto LABEL_44;
      }
      v7 = *(unsigned __int8 *)(a1 - 8) - *(unsigned __int8 *)(_ECX - 8);
      if ( v7 != 0 )
        v7 = 2 * (*(unsigned __int8 *)(a1 - 8) > (unsigned int)*(unsigned __int8 *)(_ECX - 8)) - 1;
    }
    if ( v7 == 0 )
    {
      v8 = *(_DWORD *)(a1 - 7);
      if ( v8 == *(_DWORD *)(_ECX - 7) )
        JUMPOUT(0x3F6433F8);
      if ( ((unsigned __int8)v8 == *(unsigned __int8 *)(_ECX - 7)
         || 2 * ((unsigned __int8)v8 > (unsigned int)*(unsigned __int8 *)(_ECX - 7)) == 1)
        && (*(unsigned __int8 *)(a1 - 6) == *(unsigned __int8 *)(_ECX - 6)
         || 2 * (*(unsigned __int8 *)(a1 - 6) > (unsigned int)*(unsigned __int8 *)(_ECX - 6)) == 1)
        && (*(unsigned __int8 *)(a1 - 5) == *(unsigned __int8 *)(_ECX - 5)
         || 2 * (*(unsigned __int8 *)(a1 - 5) > (unsigned int)*(unsigned __int8 *)(_ECX - 5)) == 1) )
      {
        JUMPOUT(0x3F6433E1);
      }
    }
  }
LABEL_44:
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F6433F0
// Name: _dynamic_initializer_for__g_ThreadLocalCoroutineMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall dynamic_initializer_for__g_ThreadLocalCoroutineMgr__(int a1, int a2)
{
  if ( 2 * a2 == 1 )
    JUMPOUT(0x3F64340A);
  JUMPOUT(0x3F642410);
}

//------------------------------------------------------------------------------
// Address: 0x3F643420
// Name: _dynamic_initializer_for__g_ThreadMutexCoroutineMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_ThreadMutexCoroutineMgr__()
{
  _enable();
  JUMPOUT(0x3F643423);
}

//------------------------------------------------------------------------------
// Address: 0x3F643440
// Name: _dynamic_initializer_for____g_CreateCDefaultCvarICvar_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for____g_CreateCDefaultCvarICvar_reg__(
        char a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        int a4@<edx>)
{
  LOBYTE(a4) = !(a2 ^ a3 | a1);
  if ( 2 * a4 == 1 )
    JUMPOUT(0x3F643455);
  JUMPOUT(0x3F64353E);
}

//------------------------------------------------------------------------------
// Address: 0x3F643460
// Name: _dynamic_initializer_for__vec2_origin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge dynamic_initializer_for__vec2_origin__(
        _BYTE *a1@<edi>,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  *a1 = __ROR1__(*a1, 159);
}

//------------------------------------------------------------------------------
// Address: 0x3F6434B0
// Name: _dynamic_initializer_for__vec2_invalid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge dynamic_initializer_for__vec2_invalid__(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  JUMPOUT(0x3F64353E);
}

//------------------------------------------------------------------------------
// Address: 0x3F643510
// Name: _dynamic_initializer_for__g_VecLoadedModules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge dynamic_initializer_for__g_VecLoadedModules__(
        _BYTE *a1@<edi>,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  *a1 = __ROR1__(*a1, 159);
}

//------------------------------------------------------------------------------
// Address: 0x3F643520
// Name: _dynamic_initializer_for__g_mutexKeyValuesErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__g_mutexKeyValuesErrorStack__(int a1@<ecx>, int a2@<ebp>, _DWORD *a3@<edi>)
{
  int v3; // ecx

  v3 = a1 + 1;
  *a3 += v3;
  if ( !__OFADD__(a2, v3) )
    JUMPOUT(0x3F643529);
  JUMPOUT(0x3F643528);
}

//------------------------------------------------------------------------------
// Address: 0x3F643530
// Name: _dynamic_initializer_for__g_KeyValuesSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge dynamic_initializer_for__g_KeyValuesSystem__(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  JUMPOUT(0x3F64349B);
}

//------------------------------------------------------------------------------
// Address: 0x3F643550
// Name: _dynamic_initializer_for__vec2_origin___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge dynamic_initializer_for__vec2_origin___0@<eax>(
        int _EAX@<eax>,
        int _EBX@<ebx>,
        int a3@<edi>,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  int result; // eax
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  __asm
  {
    aas
    daa
    aas
  }
  __asm
  {
    das
    aas
  }
  if ( (unsigned int)&retaddr >= *(_DWORD *)((char *)CRC32_Init + 2 * a3 - 1063260078) )
  {
    _EAX = _EAX & 0x29093F64;
    __asm { aas }
    JUMPOUT(0x3F64359C);
  }
  __asm
  {
    aas
    xlat; CRC32_Init(ulong *)
    aas
  }
  __asm { aas }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6435A0
// Name: _dynamic_initializer_for__vec2_invalid___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall dynamic_initializer_for__vec2_invalid___0@<eax>(
        int _EAX@<eax>,
        char a2@<ch>,
        unsigned int a3@<ebx>,
        int a4@<ebp>,
        int a5@<edi>)
{
  bool v5; // zf
  bool v6; // pf
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  *(_DWORD *)&byte_3F653FFF[2 * a5 - 1063600229] ^= (unsigned int)&retaddr;
  LOBYTE(_EAX) = _EAX & 0x64;
  v5 = (_BYTE)_EAX == 0;
  v6 = __SETP__(_EAX, 0);
  __asm { aas }
  if ( !v6 )
  {
    __asm { aas }
    LOBYTE(retaddr) = a2;
    __asm { aas }
    *((_BYTE *)CRC32_Init + 2 * a5 - 1063260129) ^= BYTE1(_EAX);
    LOBYTE(_EAX) = _EAX & 0x64;
    __asm { aas }
LABEL_5:
    if ( a3 != 4 )
      JUMPOUT(0x3F6435F3);
    return dynamic_atexit_destructor_for__g_ThreadLocalCoroutineMgr__(a1: *(_DWORD *)(a4 + 12));
  }
  if ( v5 )
    JUMPOUT(0x3F643675);
  if ( a3 >= 4 )
    goto LABEL_5;
  return dynamic_atexit_destructor_for__g_ThreadLocalCoroutineMgr__(a1: *(_DWORD *)(a4 + 12));
}

//------------------------------------------------------------------------------
// Address: 0x3F643600
// Name: _dynamic_initializer_for__g_mapPairs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall dynamic_initializer_for__g_mapPairs__(int a1, char a2)
{
  if ( a2 != 0 && a2 == *(_BYTE *)(a1 - 3) )
    JUMPOUT(0x3F64360E);
  JUMPOUT(0x3F643642);
}

//------------------------------------------------------------------------------
// Address: 0x3F643610
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__s_StringCharConversion__(char a1@<zf>)
{
  if ( !a1 )
    JUMPOUT(0x3F643615);
  JUMPOUT(0x3F643638);
}

//------------------------------------------------------------------------------
// Address: 0x3F643620
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall dynamic_initializer_for__s_NoEscConversion__@<eax>(int a1@<ecx>, int a2@<ebp>, unsigned int a3@<edi>)
{
  *(_DWORD *)(a2 - 4) += 4;
  if ( *(_DWORD *)(a2 - 4) < a3 )
    JUMPOUT(0x3F6435EE);
  return dynamic_atexit_destructor_for__g_ThreadLocalCoroutineMgr__(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F643640
// Name: _dynamic_initializer_for____g_CreateCDLLValidateIValidate_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CreateCDLLValidateIValidate_reg__()
{
  return dynamic_atexit_destructor_for__g_VecPCoroutineMgr__();
}

//------------------------------------------------------------------------------
// Address: 0x3F643660
// Name: _CommandLine_::_2_::_dynamic_atexit_destructor_for__g_CmdLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall CommandLine_::_2_::_dynamic_atexit_destructor_for__g_CmdLine__(_BYTE *a1, char a2)
{
  if ( a2 != 0 && a2 == *a1 )
    JUMPOUT(0x3F64366A);
  JUMPOUT(0x3F643678);
}

//------------------------------------------------------------------------------
// Address: 0x3F643670
// Name: _dynamic_atexit_destructor_for__g_ThreadLocalCoroutineMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dynamic_atexit_destructor_for__g_ThreadLocalCoroutineMgr__(
        char a1@<cf>,
        char *a2@<eax>,
        _BYTE *a3@<ecx>)
{
  if ( a1 )
    CommandLine_::_2_::_dynamic_atexit_destructor_for__g_CmdLine__(a1: a3, a2: *a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F643680
// Name: _dynamic_atexit_destructor_for__g_VecPCoroutineMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void dynamic_atexit_destructor_for__g_VecPCoroutineMgr__(void)
{
  JUMPOUT(0x3F643674);
}

//------------------------------------------------------------------------------
// Address: 0x3F6436C0
// Name: _dynamic_atexit_destructor_for__g_ThreadMutexCoroutineMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_atexit_destructor_for__g_ThreadMutexCoroutineMgr__(int a1@<eax>)
{
  *(_BYTE *)(a1 - 61) = __ROL1__(*(_BYTE *)(a1 - 61), 139);
  JUMPOUT(0x3F6436CB);
}

//------------------------------------------------------------------------------
// Address: 0x3F6436D0
// Name: _dynamic_atexit_destructor_for__g_VecLoadedModules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dynamic_atexit_destructor_for__g_VecLoadedModules__(
        int a1@<eax>,
        int a2@<edx>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  __int16 v7; // [esp-8h] [ebp-8h]
  int v8; // [esp-4h] [ebp-4h]

  *MK_FP(v7, a6 + 4 * (((v8 & a2) + a1) >> 5)) = *MK_FP(v7, a6 + 4 * (((v8 & a2) + a1) >> 5)) + (1 << (v8 - a7 % 32));
  JUMPOUT(0x3F643728);
}

//------------------------------------------------------------------------------
// Address: 0x3F643710
// Name: _dynamic_atexit_destructor_for__g_KeyValuesSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__g_KeyValuesSystem__()
{
  JUMPOUT(0x3F643716);
}

//------------------------------------------------------------------------------
// Address: 0x3F643720
// Name: _dynamic_atexit_destructor_for__g_mapPairs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall dynamic_atexit_destructor_for__g_mapPairs__@<eax>(
        char a1@<cf>,
        int a2@<eax>,
        int a3@<edx>,
        int a4@<ebx>,
        int a5@<edi>)
{
  if ( a1 )
    a4 = 1;
  *(_DWORD *)(a5 + 4 * a2) = a3;
  if ( a2 - 1 >= 0 )
    JUMPOUT(0x3F64370D);
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x3F64385F
// Name: __ShrMan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ShrMan(int a1, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // ecx
  _DWORD *v5; // edx
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int i; // [esp+20h] [ebp+Ch]

  result = a2 / 32;
  v3 = a2 % 32;
  v7 = 0;
  for ( i = 0; i < 3; ++i )
  {
    v6 = ~(-1 << v3) & *(_DWORD *)(a1 + 4 * i);
    *(_DWORD *)(a1 + 4 * i) = v7 | (*(_DWORD *)(a1 + 4 * i) >> v3);
    v7 = v6 << (32 - v3);
  }
  v4 = 2;
  v5 = (_DWORD *)(a1 + 4 * (2 - result));
  do
  {
    if ( v4 < result )
      *(_DWORD *)(a1 + 4 * v4) = 0;
    else
      *(_DWORD *)(a1 + 4 * v4) = *v5;
    --v4;
    --v5;
  }
  while ( v4 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6438F7
// Name: __ld12cvt_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ld12cvt_0(unsigned __int16 *a1, unsigned int *a2, int *a3)
{
  unsigned __int16 v3; // bx
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // kr00_4
  unsigned int *v10; // edi
  int v11; // eax
  bool i; // zf
  int v13; // eax
  unsigned int v14; // edx
  unsigned int *v15; // ecx
  bool v16; // cf
  unsigned int v17; // esi
  int v18; // eax
  int v19; // kr04_4
  int v20; // eax
  int v21; // edx
  int *v22; // ebx
  unsigned int v23; // esi
  char v24; // cl
  int v25; // edx
  unsigned int *v26; // ecx
  int v27; // esi
  int v28; // eax
  bool v29; // sf
  unsigned int v30; // edx
  unsigned int *v31; // ebx
  bool j; // zf
  int v33; // eax
  unsigned int v34; // edx
  unsigned int *v35; // ecx
  unsigned int v36; // edi
  int k; // ecx
  unsigned int *v38; // ecx
  unsigned int v39; // esi
  int v40; // edi
  int v41; // eax
  int v42; // edx
  int *v43; // ebx
  unsigned int v44; // esi
  char v45; // cl
  int v46; // edx
  unsigned int *v47; // ecx
  int result; // eax
  int v49; // kr10_4
  int v50; // eax
  int v51; // edx
  int *v52; // ebx
  unsigned int v53; // edi
  char v54; // cl
  int v55; // edx
  unsigned int *v56; // ecx
  int v57; // ecx
  int v58; // ebx
  int v59; // edx
  unsigned int v60; // eax
  int v61; // ecx
  unsigned int *v62; // eax
  int v63; // ecx
  unsigned int v64; // esi
  unsigned int v65; // edx
  unsigned int v66; // [esp+Ch] [ebp-2Ch]
  unsigned int v67; // [esp+10h] [ebp-28h]
  int v68; // [esp+14h] [ebp-24h]
  unsigned int v69; // [esp+18h] [ebp-20h] BYREF
  unsigned int v70; // [esp+1Ch] [ebp-1Ch]
  int v71; // [esp+20h] [ebp-18h] BYREF
  int v72; // [esp+24h] [ebp-14h]
  int v73; // [esp+28h] [ebp-10h]
  int v74; // [esp+2Ch] [ebp-Ch]
  int v75; // [esp+30h] [ebp-8h]
  int v76; // [esp+34h] [ebp-4h]
  int v77; // [esp+40h] [ebp+8h]
  unsigned int v78; // [esp+40h] [ebp+8h]
  int v79; // [esp+40h] [ebp+8h]
  int v80; // [esp+40h] [ebp+8h]
  int v81; // [esp+40h] [ebp+8h]
  int v82; // [esp+40h] [ebp+8h]
  int v83; // [esp+40h] [ebp+8h]

  v3 = a1[5];
  v72 = v3 & 0x8000;
  v69 = *(_DWORD *)(a1 + 3);
  v4 = (v3 & 0x7FFF) - 0x3FFF;
  v5 = *a1 << 16;
  v70 = *(_DWORD *)(a1 + 1);
  v71 = v5;
  if ( v4 == -16383 )
  {
    v6 = 0;
    v7 = 0;
    while ( *(&v69 + v7) == 0 )
    {
      if ( ++v7 >= 3 )
        goto LABEL_80;
    }
LABEL_26:
    v69 = 0;
    v70 = 0;
    v71 = 0;
LABEL_63:
    result = 2;
    goto LABEL_81;
  }
  v77 = 0;
  v66 = v69;
  v67 = v70;
  v68 = v71;
  v8 = a3[2] - 1;
  v9 = a3[2];
  v73 = v4;
  v74 = v9 / 32;
  v10 = &v69 + v9 / 32;
  v75 = 31 - v9 % 32;
  if ( ((1 << (31 - v9 % 32)) & *v10) != 0 )
  {
    v11 = v74;
    for ( i = (~(-1 << (31 - v9 % 32)) & *(&v69 + v74)) == 0; i; i = *(&v69 + v11) == 0 )
    {
      if ( ++v11 >= 3 )
        goto LABEL_21;
    }
    v13 = v8 / 32;
    v76 = 0;
    v14 = 1 << (31 - v8 % 32);
    v15 = &v69 + v8 / 32;
    v78 = v14 + *v15;
    if ( v78 >= *v15 )
    {
      v16 = v78 < v14;
      goto LABEL_17;
    }
LABEL_18:
    v76 = 1;
    while ( 1 )
    {
      --v13;
      *v15 = v78;
      if ( v13 < 0 || v76 == 0 )
        break;
      v76 = 0;
      v15 = &v69 + v13;
      v17 = *v15 + 1;
      v78 = v17;
      if ( v17 >= *v15 )
      {
        v16 = v17 == 0;
LABEL_17:
        if ( !v16 )
          continue;
      }
      goto LABEL_18;
    }
    v77 = v76;
  }
LABEL_21:
  *v10 &= -1 << v75;
  if ( v74 + 1 < 3 )
    memset(&v69 + v74 + 1, 0, 4 * (3 - (v74 + 1)));
  v6 = 0;
  if ( v77 != 0 )
    ++v4;
  v18 = a3[1];
  if ( v4 < v18 - a3[2] )
    goto LABEL_26;
  if ( v4 <= v18 )
  {
    v69 = v66;
    v19 = v18 - v73;
    v70 = v67;
    v20 = (v18 - v73) / 32;
    v71 = v68;
    v21 = v19 % 32;
    v74 = 0;
    v79 = 0;
    v76 = 32 - v19 % 32;
    do
    {
      v22 = (int *)(&v69 + v79);
      v23 = *v22;
      v73 = ~(-1 << v21) & *v22;
      v24 = v76;
      *v22 = v74 | (v23 >> v21);
      ++v79;
      v74 = v73 << v24;
    }
    while ( v79 < 3 );
    v25 = 2;
    v26 = (unsigned int *)(&v71 - v20);
    do
    {
      if ( v25 < v20 )
        *(&v69 + v25) = 0;
      else
        *(&v69 + v25) = *v26;
      --v25;
      --v26;
    }
    while ( v25 >= 0 );
    v27 = a3[2] - 1;
    v28 = a3[2] / 32;
    v30 = a3[2] & 0x8000001F;
    v29 = a3[2] < 0;
    v74 = v28;
    if ( v29 )
      v30 = (((_BYTE)v30 - 1) | 0xFFFFFFE0) + 1;
    v31 = &v69 + v28;
    v73 = 31 - v30;
    if ( ((1 << (31 - v30)) & *v31) != 0 )
    {
      for ( j = (~(-1 << (31 - v30)) & *(&v69 + v28)) == 0; j; j = *(&v69 + v28) == 0 )
      {
        if ( ++v28 >= 3 )
          goto LABEL_53;
      }
      v33 = v27 / 32;
      v80 = 0;
      v34 = 1 << (31 - v27 % 32);
      v35 = &v69 + v27 / 32;
      v36 = *v35 + v34;
      if ( v36 < *v35 || v36 < v34 )
        v80 = 1;
      *v35 = v36;
      for ( k = v80; --v33 >= 0 && k != 0; k = v40 )
      {
        v38 = &v69 + v33;
        v39 = *v38 + 1;
        v40 = 0;
        if ( v39 < *v38 || *v38 == -1 )
          v40 = 1;
        *v38 = v39;
      }
    }
LABEL_53:
    *v31 &= -1 << v73;
    if ( v74 + 1 < 3 )
      memset(&v69 + v74 + 1, 0, 4 * (3 - (v74 + 1)));
    v41 = (a3[3] + 1) / 32;
    v42 = (a3[3] + 1) % 32;
    v74 = 0;
    v81 = 0;
    v76 = 32 - v42;
    do
    {
      v43 = (int *)(&v69 + v81);
      v44 = *v43;
      v73 = ~(-1 << v42) & *v43;
      v45 = v76;
      *v43 = v74 | (v44 >> v42);
      ++v81;
      v74 = v73 << v45;
    }
    while ( v81 < 3 );
    v46 = 2;
    v47 = (unsigned int *)(&v71 - v41);
    do
    {
      if ( v46 < v41 )
        *(&v69 + v46) = 0;
      else
        *(&v69 + v46) = *v47;
      --v46;
      --v47;
    }
    while ( v46 >= 0 );
    v6 = 0;
    goto LABEL_63;
  }
  if ( v4 < *a3 )
  {
    v69 &= ~0x80000000;
    v57 = a3[3];
    v6 = v4 + a3[5];
    v58 = v57 / 32;
    v59 = v57 % 32;
    v74 = 0;
    v83 = 0;
    v76 = 32 - v57 % 32;
    do
    {
      v60 = *(&v69 + v83);
      v73 = ~(-1 << v59) & v60;
      *(&v69 + v83++) = v74 | (v60 >> v59);
      v74 = v73 << v76;
    }
    while ( v83 < 3 );
    v61 = 2;
    v62 = (unsigned int *)(&v71 - v58);
    do
    {
      if ( v61 < v58 )
        *(&v69 + v61) = 0;
      else
        *(&v69 + v61) = *v62;
      --v61;
      --v62;
    }
    while ( v61 >= 0 );
LABEL_80:
    result = 0;
  }
  else
  {
    v70 = 0;
    v71 = 0;
    v69 = 0x80000000;
    v49 = a3[3];
    v50 = v49 / 32;
    v51 = v49 % 32;
    v74 = 0;
    v82 = 0;
    v76 = 32 - v49 % 32;
    do
    {
      v52 = (int *)(&v69 + v82);
      v53 = *v52;
      v73 = ~(-1 << v51) & *v52;
      v54 = v76;
      *v52 = v74 | (v53 >> v51);
      ++v82;
      v74 = v73 << v54;
    }
    while ( v82 < 3 );
    v55 = 2;
    v56 = (unsigned int *)(&v71 - v50);
    do
    {
      if ( v55 < v50 )
        *(&v69 + v55) = 0;
      else
        *(&v69 + v55) = *v56;
      --v55;
      --v56;
    }
    while ( v55 >= 0 );
    v6 = *a3 + a3[5];
    result = 1;
  }
LABEL_81:
  v63 = a3[4];
  v64 = v69 | (v72 != 0 ? 0x80000000 : 0) | (v6 << (31 - *((_BYTE *)a3 + 12)));
  if ( v63 == 64 )
  {
    v65 = v70;
    a2[1] = v64;
    *a2 = v65;
  }
  else if ( v63 == 32 )
  {
    *a2 = v64;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6448A4
// Name: __ld12told_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ld12told_0(unsigned __int16 *a1, int a2)
{
  unsigned __int16 v2; // dx
  unsigned int v3; // ebx
  unsigned int v4; // esi
  int v5; // ecx
  __int16 v6; // di
  bool v7; // zf
  int v8; // ebx
  int v9; // ecx
  unsigned int *v10; // ecx
  unsigned int v11; // ebx
  bool v12; // sf
  unsigned int v14; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]
  int v19; // [esp+28h] [ebp+8h]

  v2 = a1[5];
  v17 = 0;
  v3 = *(_DWORD *)(a1 + 3);
  v4 = *(_DWORD *)(a1 + 1);
  v5 = *a1 << 16;
  v6 = v2 & 0x7FFF;
  v7 = (*a1 & 0x8000) == 0;
  v14 = v3;
  v16 = v5;
  if ( !v7 && (v5 & 0x7FFFFFFF) != 0 )
  {
    v8 = 0;
    if ( v4 + 1 < v4 || v4 == -1 )
      v8 = 1;
    v19 = 0;
    v15 = v4 + 1;
    v9 = v8;
    while ( v9 != 0 )
    {
      v18 = 0;
      v10 = &v14 + v19;
      v11 = *v10 + 1;
      if ( v11 < *v10 || *v10 == -1 )
        v18 = 1;
      v12 = --v19 < 0;
      *v10 = v11;
      v9 = v18;
      if ( v12 )
      {
        if ( v18 != 0 )
        {
          v3 = 0x80000000;
          ++v6;
          goto LABEL_15;
        }
        break;
      }
    }
    v3 = v14;
LABEL_15:
    v4 = v15;
  }
  if ( v6 == 0x7FFF )
    v17 = 1;
  *(_DWORD *)a2 = v4;
  *(_DWORD *)(a2 + 4) = v3;
  *(_WORD *)(a2 + 8) = v6 | v2 & 0x8000;
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x3F644966
// Name: __forcdecpt_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl _forcdecpt_l_0(char *a1, struct localeinfo_struct *a2)
{
  char *v2; // esi
  bool i; // zf
  char result; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate v8; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v8, a2);
  v2 = a1;
  for ( i = tolower_0(C: *a1) == 101; !i; i = isdigit_0(C: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower_0(C: *v2) == 120 )
    v2 += 2;
  result = *v2;
  *v2 = *v8.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = result;
    result = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( v8.updated )
  {
    result = (char)v8.ptd;
    v8.ptd->_ownlocale &= ~2u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6449D7
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _cropzeros_l(_BYTE *a1, struct localeinfo_struct *a2)
{
  _BYTE *v2; // eax
  char i; // cl
  char v4; // cl
  _tiddata *result; // eax
  char tid; // cl
  _tiddata *v7; // edx
  char v8; // cl
  _LocaleUpdate v9; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v9, a2);
  v2 = a1;
  for ( i = *a1; *v2 != 0; i = *++v2 )
  {
    if ( i == *v9.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  result = (_tiddata *)(v2 + 1);
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      tid = result->_tid;
      if ( LOBYTE(result->_tid) == 0 || tid == 101 || tid == 69 )
        break;
      result = (_tiddata *)((char *)result + 1);
    }
    v7 = result;
    do
      result = (_tiddata *)((char *)result - 1);
    while ( LOBYTE(result->_tid) == 48 );
    if ( LOBYTE(result->_tid) == *v9.localeinfo.locinfo->lconv->decimal_point )
      result = (_tiddata *)((char *)result - 1);
    do
    {
      v8 = v7->_tid;
      result = (_tiddata *)((char *)result + 1);
      v7 = (_tiddata *)((char *)v7 + 1);
      LOBYTE(result->_tid) = v8;
    }
    while ( v8 != 0 );
  }
  if ( v9.updated )
  {
    result = v9.ptd;
    v9.ptd->_ownlocale &= ~2u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F644A69
// Name: nullsub_40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_40()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F644A6A
// Name: sub_3F644A6A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F644A6A()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F644A6D
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_QWORD *__cdecl _fassign_l(int a1, _QWORD *a2, int a3, int a4)
{
  _QWORD *result; // eax
  __int64 v5; // [esp+0h] [ebp-8h] BYREF

  if ( a1 != 0 )
  {
    sub_3F64D633(a1: &v5, a2: a3, a3: a4);
    result = a2;
    *a2 = v5;
  }
  else
  {
    sub_3F64D7A6(&a1, a2: a3, a3: a4);
    result = a2;
    *(_DWORD *)a2 = a1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F644AAD
// Name: __fassign_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_QWORD *__cdecl _fassign_0(int a1, _QWORD *a2, int a3)
{
  return _fassign_l(a1, a2, a3, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F645305
// Name: nullsub_41
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int nullsub_41()
{
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}

//------------------------------------------------------------------------------
// Address: 0x3F64544A
// Name: sub_3F64544A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64544A(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return _cfltcvt_l_0(a1, a2, a3, a4, a5, a6, a7: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F645494
// Name: __ms_p5_test_fdiv_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _ms_p5_test_fdiv_0()
{
  return 4195835.0 - 4195835.0 / 3145727.0 * 3145727.0 > 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645566
// Name: ___mtold12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __mtold12_0(char *a1, int a2, unsigned int *a3)
{
  unsigned int *result; // eax
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned int v6; // edx
  unsigned int v7; // edi
  int v8; // ebx
  unsigned int v9; // ecx
  unsigned int v10; // ebx
  int v11; // esi
  unsigned int v12; // ecx
  unsigned int v13; // edi
  int v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // esi
  int v17; // edx
  unsigned int v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // edi
  int v21; // ecx
  __int16 v22; // [esp+Ch] [ebp-18h]
  int v23; // [esp+10h] [ebp-14h]
  int v24; // [esp+10h] [ebp-14h]
  unsigned int v25; // [esp+18h] [ebp-Ch]
  unsigned int v26; // [esp+1Ch] [ebp-8h]

  result = a3;
  v22 = 16462;
  *a3 = 0;
  a3[1] = 0;
  for ( a3[2] = 0; a2 != 0; ++a1 )
  {
    v25 = a3[1];
    v26 = a3[2];
    v23 = 0;
    v4 = __SPAIR64__(*(_QWORD *)(a3 + 1) >> 31, *(__int64 *)a3 >> 31) >> 31;
    v5 = *a3;
    v6 = (2LL * *(_QWORD *)a3) >> 31;
    v7 = 5 * *a3;
    *a3 *= 4;
    a3[1] = v6;
    a3[2] = v4;
    if ( 5 * v5 < 4 * v5 || v7 < v5 )
      v23 = 1;
    v8 = 0;
    *a3 = v7;
    if ( v23 != 0 )
    {
      if ( v6 + 1 < v6 || v6 == -1 )
        v8 = 1;
      a3[1] = v6 + 1;
      if ( v8 != 0 )
        a3[2] = v4 + 1;
    }
    v9 = a3[1];
    v10 = v9 + v25;
    v11 = 0;
    if ( v9 + v25 < v9 || v10 < v25 )
      v11 = 1;
    a3[1] = v10;
    if ( v11 != 0 )
      ++a3[2];
    a3[2] += v26;
    v24 = 0;
    v12 = 2 * v7;
    v13 = (v7 >> 31) | (2 * v10);
    v14 = (v10 >> 31) | (2 * a3[2]);
    *a3 = v12;
    a3[1] = v13;
    a3[2] = v14;
    v15 = *a1;
    v16 = v12 + v15;
    if ( v12 + v15 < v12 || v16 < v15 )
      v24 = 1;
    *a3 = v16;
    if ( v24 != 0 )
    {
      v17 = 0;
      if ( v13 + 1 < v13 || v13 == -1 )
        v17 = 1;
      a3[1] = v13 + 1;
      if ( v17 != 0 )
        a3[2] = v14 + 1;
    }
    --a2;
  }
  while ( a3[2] == 0 )
  {
    v18 = a3[1];
    a3[2] = HIWORD(v18);
    v22 -= 16;
    *(_QWORD *)a3 = __PAIR64__(v18, *a3) << 16;
  }
  if ( (a3[2] & 0x8000) == 0 )
  {
    do
    {
      v19 = *a3;
      v20 = a3[1];
      --v22;
      *a3 *= 2;
      v21 = (v20 >> 31) | (2 * a3[2]);
      a3[1] = (v19 >> 31) | (2 * v20);
      a3[2] = v21;
    }
    while ( (v21 & 0x8000) == 0 );
  }
  *((_WORD *)a3 + 5) = v22;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F645732
// Name: __lseeki64_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl _lseeki64_nolock_0(int a1, LONG a2, int a3, DWORD dwMoveMethod)
{
  void *v4; // eax
  DWORD LastError; // eax
  _BYTE *v7; // eax
  __int64 lDistanceToMove; // [esp+8h] [ebp-8h] BYREF

  HIDWORD(lDistanceToMove) = a3;
  v4 = (void *)((int (__cdecl *)(int))loc_3F63B222)(a1);
  if ( v4 == (void *)-1 )
  {
    *_errno_0() = 9;
    return -1;
  }
  LODWORD(lDistanceToMove) = SetFilePointer(
                               hFile: v4,
                               lDistanceToMove: a2,
                               lpDistanceToMoveHigh: (PLONG)&lDistanceToMove + 1,
                               dwMoveMethod);
  if ( (_DWORD)lDistanceToMove == -1 )
  {
    LastError = GetLastError();
    if ( LastError != 0 )
    {
      _dosmaperr_0(a1: LastError);
      return -1;
    }
  }
  v7 = (_BYTE *)(dword_3F665FE0[a1 >> 5] + 56 * (a1 & 0x1F) + 4);
  *v7 &= ~2u;
  return lDistanceToMove;
}

//------------------------------------------------------------------------------
// Address: 0x3F6457B5
// Name: __lseeki64_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl _lseeki64_0(int FileHandle, __int64 Offset, int Origin)
{
  int *v4; // ebx
  int v5; // esi
  int v6; // [esp+0h] [ebp-34h]
  int v7; // [esp+4h] [ebp-30h]
  int v8; // [esp+8h] [ebp-2Ch]
  int v9; // [esp+Ch] [ebp-28h]
  __int64 v10; // [esp+10h] [ebp-24h]
  __int64 v11; // [esp+10h] [ebp-24h]
  int v12; // [esp+18h] [ebp-1Ch]
  int ms_exc; // [esp+1Ch] [ebp-18h]
  int ms_exc_4; // [esp+20h] [ebp-14h]
  int ms_exc_8; // [esp+24h] [ebp-10h]
  int ms_exc_12; // [esp+28h] [ebp-Ch]
  int ms_exc_16; // [esp+2Ch] [ebp-8h]

  if ( FileHandle == -2 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    return -1;
  }
  if ( FileHandle < 0 || FileHandle >= uNumber )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  v4 = &dword_3F665FE0[FileHandle >> 5];
  v5 = 56 * (FileHandle & 0x1F);
  if ( (*(_BYTE *)(*v4 + v5 + 4) & 1) != 0 )
  {
    ((void (__cdecl *)(int))loc_3F63B293)(a1: FileHandle);
    if ( (*(_BYTE *)(*v4 + v5 + 4) & 1) != 0 )
    {
      v10 = _lseeki64_nolock_0(a1: FileHandle, a2: Offset, a3: SHIDWORD(Offset), dwMoveMethod: Origin);
    }
    else
    {
      *_errno_0() = 9;
      *__doserrno_0() = 0;
      v10 = -1;
    }
    ((void (__stdcall *)(int, int, int, int, int, int, _DWORD, _DWORD, int, int, int, int, int, int))_LN9_16)(
      a1: FileHandle,
      a2: 1063540920,
      a3: v6,
      a4: v7,
      a5: v8,
      a6: v9,
      a7: v10,
      a8: HIDWORD(v10),
      a9: v12,
      a10: ms_exc,
      a11: ms_exc_4,
      a12: ms_exc_8,
      a13: ms_exc_12,
      a14: ms_exc_16);
    return v11;
  }
  else
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F6458CE
// Name: sub_3F6458CE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall sub_3F6458CE(_DWORD *this)
{
  *this = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F6458D4
// Name: ?Constructor@HeapManager@@QAEXP6APAXI@ZP6AXPAX@Z@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall HeapManager::Constructor(
        HeapManager *this,
        void *(__cdecl *a2)(unsigned int),
        void (__cdecl *a3)(void *))
{
  this->pOpNew = a2;
  this->pOpDelete = a3;
  this->blockLeft = 0;
  this->head = nullptr;
  this->tail = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F6458EF
// Name: public: void HeapManager::Destructor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall HeapManager::Destructor(HeapManager *this)
{
  HeapManager::Block *head; // eax
  HeapManager::Block *tail; // [esp-4h] [ebp-8h]

  if ( this->pOpDelete != nullptr )
  {
    while ( 1 )
    {
      head = this->head;
      this->tail = head;
      if ( head == nullptr )
        break;
      tail = this->tail;
      this->head = tail->next;
      this->pOpDelete(a1: tail);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F645DF7
// Name: ?doMSKeywords@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doMSKeywords()
{
  return (dword_3F663DD4 & 2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E04
// Name: ?doPtr64@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doPtr64()
{
  return (dword_3F663DD4 & 0x20000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E12
// Name: ?doFunctionReturns@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doFunctionReturns()
{
  return (dword_3F663DD4 & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E20
// Name: ?doAllocationModel@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doAllocationModel()
{
  return (dword_3F663DD4 & 8) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E2E
// Name: public: static int UnDecorator::doAllocationLanguage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doAllocationLanguage()
{
  return (dword_3F663DD4 & 0x10) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E4E
// Name: ?doAccessSpecifiers@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doAccessSpecifiers()
{
  return (dword_3F663DD4 & 0x80) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E5C
// Name: ?doThrowTypes@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doThrowTypes()
{
  return (dword_3F663DD4 & 0x100) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E6A
// Name: ?doMemberTypes@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doMemberTypes()
{
  return (dword_3F663DD4 & 0x200) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E78
// Name: sub_3F645E78
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F645E78()
{
  return dword_3F663DD4 & 0x1000;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E83
// Name: sub_3F645E83
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F645E83()
{
  return dword_3F663DD4 & 0x2000;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E8E
// Name: sub_3F645E8E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F645E8E()
{
  return dword_3F663DD4 & 0x4000;
}

//------------------------------------------------------------------------------
// Address: 0x3F645E99
// Name: ?doEcsu@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doEcsu()
{
  return (dword_3F663DD4 & 0x8000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645EA7
// Name: sub_3F645EA7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F645EA7()
{
  return dword_3F663DD4 & 0x10000;
}

//------------------------------------------------------------------------------
// Address: 0x3F645EB2
// Name: ?doEllipsis@UnDecorator@@SAHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static BOOL __cdecl UnDecorator::doEllipsis()
{
  return (dword_3F663DD4 & 0x40000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F645EC0
// Name: ?UScore@UnDecorator@@SAPBDW4Tokens@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static char *__cdecl UnDecorator::UScore(enum Tokens a1)
{
  char *result; // eax

  result = off_3F656400[a1];
  if ( (dword_3F663DD4 & 1) != 0 )
    result += 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F645ED9
// Name: ?getMemory@HeapManager@@QAEPAXIH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall HeapManager::getMemory(HeapManager *this, unsigned int a2, int a3)
{
  unsigned int v3; // edi
  unsigned int blockLeft; // eax
  HeapManager::Block *Memory; // eax
  HeapManager::Block *tail; // ecx

  v3 = (a2 + 7) & 0xFFFFFFF8;
  if ( a3 != 0 )
    return (char *)this->pOpNew(a1: (a2 + 7) & 0xFFFFFFF8);
  if ( v3 == 0 )
    v3 = 8;
  blockLeft = this->blockLeft;
  if ( blockLeft >= v3 )
  {
    this->blockLeft = blockLeft - v3;
  }
  else
  {
    if ( v3 > 0x1000 )
      return nullptr;
    Memory = (HeapManager::Block *)HeapManager::getMemory(this: &stru_3F663DA4, a2: 0x1004u, a3: 1);
    if ( Memory != nullptr )
      Memory->next = nullptr;
    else
      Memory = nullptr;
    if ( Memory == nullptr )
      return nullptr;
    tail = this->tail;
    if ( tail != nullptr )
      tail->next = Memory;
    else
      this->head = Memory;
    this->tail = Memory;
    this->blockLeft = 4096 - v3;
  }
  return &this->tail->memBlock[this->blockLeft];
}

//------------------------------------------------------------------------------
// Address: 0x3F645F5D
// Name: ??0DName@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this)
{
  this->node = nullptr;
  *((_DWORD *)this + 1) &= 0xFFFFF000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F645F6A
// Name: ??0DName@@QAE@PAVDNameNode@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, struct DNameNode *a2)
{
  *((_DWORD *)this + 1) &= 0xFFFFF000;
  this->node = a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F645F7C
// Name: ??0DName@@QAE@ABV0@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, const struct DName *a2)
{
  DName *result; // eax
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // esi

  result = this;
  *((_DWORD *)this + 1) ^= (*((_DWORD *)this + 1) ^ ((int)(*((_DWORD *)a2 + 1) << 28) >> 28)) & 0xF;
  v3 = *((_DWORD *)result + 1)
     ^ ((unsigned __int8)*((_DWORD *)result + 1)
      ^ (unsigned __int8)*((_DWORD *)a2 + 1))
     & 0x10;
  *((_DWORD *)this + 1) = v3;
  v4 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)*((_DWORD *)a2 + 1)) & 0x20;
  *((_DWORD *)this + 1) = v4;
  v5 = v4 ^ ((unsigned __int8)v4 ^ (unsigned __int8)*((_DWORD *)a2 + 1)) & 0x40;
  *((_DWORD *)this + 1) = v5;
  v6 = v5 ^ ((unsigned __int8)v5 ^ (unsigned __int8)*((_DWORD *)a2 + 1)) & 0x80;
  *((_DWORD *)this + 1) = v6;
  this->node = a2->node;
  *((_DWORD *)this + 1) ^= (*((_DWORD *)a2 + 1) ^ v6) & 0x100;
  v7 = *((_DWORD *)result + 1)
     ^ ((unsigned __int16)*((_DWORD *)result + 1)
      ^ (unsigned __int16)*((_DWORD *)a2 + 1))
     & 0x200;
  *((_DWORD *)this + 1) = v7;
  v8 = v7 ^ ((unsigned __int16)v7 ^ (unsigned __int16)*((_DWORD *)a2 + 1)) & 0x400;
  *((_DWORD *)this + 1) = v8;
  *((_DWORD *)this + 1) = v8 ^ ((unsigned __int16)v8 ^ (unsigned __int16)*((_DWORD *)a2 + 1)) & 0x800;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F646018
// Name: ?status@DName@@QBE?AW4DNameStatus@@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall DName::status(DName *this)
{
  return (int)(*((_DWORD *)this + 1) << 28) >> 28;
}

//------------------------------------------------------------------------------
// Address: 0x3F646022
// Name: ?clearStatus@DName@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::clearStatus(DName *this)
{
  *((_DWORD *)this + 1) &= 0xFFFFFFF0;
}

//------------------------------------------------------------------------------
// Address: 0x3F646027
// Name: ?setPtrRef@DName@@QAEAAV1@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct DName *__thiscall DName::setPtrRef(DName *this)
{
  *((_DWORD *)this + 1) |= 0x10u;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F64602E
// Name: ?isPtrRef@DName@@QBEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall DName::isPtrRef(DName *this)
{
  return (*((_DWORD *)this + 1) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F646038
// Name: ?setIsArray@DName@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::setIsArray(DName *this)
{
  *((_DWORD *)this + 1) |= 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x3F646040
// Name: unknown_libname_3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
BOOL __thiscall unknown_libname_3(_DWORD *this)
{
  return (*(this + 1) & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64604A
// Name: unknown_libname_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
BOOL __thiscall unknown_libname_4(_DWORD *this)
{
  return (*(this + 1) & 0x100) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F646054
// Name: ?setIsNoTE@DName@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::setIsNoTE(DName *this)
{
  *((_DWORD *)this + 1) |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x3F64605C
// Name: ?isPinPtr@DName@@QBEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall DName::isPinPtr(DName *this)
{
  return (*((_DWORD *)this + 1) & 0x200) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F646066
// Name: ?setIsPinPtr@DName@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::setIsPinPtr(DName *this)
{
  *((_DWORD *)this + 1) |= 0x200u;
}

//------------------------------------------------------------------------------
// Address: 0x3F64606E
// Name: public: int DName::isComArray(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall DName::isComArray(DName *this)
{
  return (*((_DWORD *)this + 1) & 0x400) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F646078
// Name: ?setIsComArray@DName@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::setIsComArray(DName *this)
{
  *((_DWORD *)this + 1) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x3F646080
// Name: unknown_libname_5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
BOOL __thiscall unknown_libname_5(_DWORD *this)
{
  return (*(this + 1) & 0x800) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64608A
// Name: unknown_libname_6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void __thiscall unknown_libname_6(_DWORD *this)
{
  *(this + 1) |= 0x800u;
}

//------------------------------------------------------------------------------
// Address: 0x3F646092
// Name: ??4DName@@QAEAAV0@ABV0@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall DName::operator=(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // esi
  int v4; // ecx
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // esi
  int v9; // edx

  result = this;
  v3 = *(this + 1);
  v4 = v3 << 28 >> 28;
  if ( v4 == 0 || v4 == 2 )
  {
    v5 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)((int)(a2[1] << 28) >> 28)) & 0xF;
    result[1] = v5;
    v6 = v5 ^ ((unsigned __int8)v5 ^ (unsigned __int8)a2[1]) & 0x10;
    result[1] = v6;
    v7 = v6 ^ ((unsigned __int8)v6 ^ (unsigned __int8)a2[1]) & 0x20;
    result[1] = v7;
    v8 = v7 ^ ((unsigned __int8)v7 ^ (unsigned __int8)a2[1]) & 0x40;
    result[1] = v8;
    v9 = v8 ^ ((unsigned __int8)v8 ^ (unsigned __int8)a2[1]) & 0x80;
    result[1] = v9;
    result[1] = v9 ^ ((unsigned __int16)v9 ^ (unsigned __int16)a2[1]) & 0x800;
    *result = *a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64610D
// Name: ?isFull@Replicator@@QBEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall Replicator::isFull(Replicator *this)
{
  return this->index == 9;
}

//------------------------------------------------------------------------------
// Address: 0x3F646116
// Name: ??AReplicator@@QBEABVDName@@H@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall Replicator::operator[](_DWORD *this, unsigned int a2)
{
  if ( a2 > 9 )
    return this + 11;
  if ( *this == -1 || (signed int)a2 > *this )
    return this + 13;
  return (_DWORD *)*(this + a2 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F64613B
// Name: sub_3F64613B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall sub_3F64613B(_DWORD *this)
{
  *(this + 1) = 0;
  *this = &DNameNode::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F646148
// Name: sub_3F646148
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F646148(_DWORD *this)
{
  return *(this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F64614C
// Name: ??YDNameNode@@QAEAAV0@PAV0@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall DNameNode::operator+=(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  int v3; // edx

  result = this;
  if ( a2 != 0 )
  {
    v3 = *(this + 1);
    if ( v3 != 0 )
    {
      while ( *(_DWORD *)(v3 + 4) != 0 )
        v3 = *(_DWORD *)(v3 + 4);
      *(_DWORD *)(v3 + 4) = a2;
    }
    else
    {
      *(this + 1) = a2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F646175
// Name: ??0charNode@@QAE@D@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
charNode *__thiscall charNode::charNode(charNode *this, char a2)
{
  this->next = nullptr;
  this->__vftable = (charNode_vtbl *)&charNode::`vftable';
  this->me = a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F64618B
// Name: sub_3F64618B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F64618B()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F64618F
// Name: sub_3F64618F
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall sub_3F64618F(_BYTE *this)
{
  return *(this + 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F646193
// Name: public: virtual char __near * charNode::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall charNode::getString(charNode *this, char *a2, int a3)
{
  char *result; // eax

  result = a2;
  if ( a2 == nullptr || a3 == 0 )
    return nullptr;
  *a2 = this->me;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6461AE
// Name: sub_3F6461AE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F6461AE(_DWORD *this)
{
  return *(this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x3F6461B2
// Name: ??0pDNameNode@@QAE@PAVDName@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
pDNameNode *__thiscall pDNameNode::pDNameNode(pDNameNode *this, struct DName *a2)
{
  DName *v2; // edx
  pDNameNode *result; // eax
  int v4; // ecx

  v2 = a2;
  result = this;
  this->next = nullptr;
  this->__vftable = (pDNameNode_vtbl *)&pDNameNode::`vftable';
  if ( a2 != nullptr )
  {
    v4 = (int)(*((_DWORD *)a2 + 1) << 28) >> 28;
    if ( v4 == 1 || v4 == 3 )
      v2 = nullptr;
  }
  result->me = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6461E1
// Name: ??0DNameStatusNode@@QAE@W4DNameStatus@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DNameStatusNode *__thiscall DNameStatusNode::DNameStatusNode(DNameStatusNode *this, enum DNameStatus a2)
{
  DNameStatusNode *result; // eax
  int v3; // ecx

  result = this;
  this->next = nullptr;
  this->__vftable = (DNameStatusNode_vtbl *)&DNameStatusNode::`vftable';
  this->me = a2;
  if ( a2 == DN_truncated )
    v3 = 4;
  else
    v3 = 0;
  result->myLen = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F646206
// Name: public: virtual char DNameStatusNode::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall DNameStatusNode::getLastChar(DNameStatusNode *this)
{
  return this->me != DN_truncated ? 0 : 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x3F646213
// Name: unsigned int und_strlen(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall und_strlen(_BYTE *this)
{
  unsigned int result; // eax

  for ( result = 0; *this != 0; ++this )
    ++result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F646221
// Name: char __near * und_strncpy(char __near *,char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall und_strncpy@<eax>(char *a1@<edx>, char *a2, const char *a3)
{
  char *i; // ecx
  bool v4; // zf

  for ( i = a2; a3 != nullptr; --a3 )
  {
    v4 = *a1 == 0;
    *i = *a1;
    if ( v4 )
      break;
    ++i;
    ++a1;
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F6464E7
// Name: ??_5DName@@QAEAAV0@ABV0@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall DName::operator|=(_DWORD *this, int a2)
{
  _DWORD *v2; // edx
  int v3; // esi
  int v4; // ecx

  v2 = this;
  v3 = *(this + 1);
  if ( (*(_BYTE *)(this + 1) & 0xF) != 3 && ((int (__thiscall *)(int))((char *)&nameTable[47] + 3))(a1: a2) == 0 )
    v2[1] = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)((int)(*(_DWORD *)(v4 + 4) << 28) >> 28)) & 0xF;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F64651C
// Name: ??4DName@@QAEAAV0@W4DNameStatus@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DNameStatusNode **__thiscall DName::operator=(DNameStatusNode **this, enum DNameStatus a2)
{
  int v3; // eax
  int v4; // ecx
  char *Memory; // eax
  DNameStatusNode *v6; // eax
  int v7; // eax

  if ( a2 == DN_invalid || a2 == DN_error )
  {
    v7 = (int)*(this + 1);
    *this = nullptr;
    if ( (v7 & 0xF) != 3 )
      *(this + 1) = (DNameStatusNode *)(v7 ^ ((unsigned __int8)a2 ^ (unsigned __int8)v7) & 0xF);
  }
  else
  {
    v3 = (int)*(this + 1);
    v4 = v3 << 28 >> 28;
    if ( v4 == 0 || v4 == 2 )
    {
      *(this + 1) = (DNameStatusNode *)(v3 & 0xFFFFF70F);
      Memory = HeapManager::getMemory(this: &stru_3F663DA4, a2: 0x10u, a3: 0);
      if ( Memory != nullptr )
        v6 = DNameStatusNode::DNameStatusNode(this: (DNameStatusNode *)Memory, a2);
      else
        v6 = nullptr;
      *this = v6;
      if ( v6 == nullptr )
        *(this + 1) = (DNameStatusNode *)((unsigned int)*(this + 1) & 0xFFFFFFF0 | 3);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F64659D
// Name: ??0Replicator@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Replicator *__thiscall Replicator::Replicator(Replicator *this)
{
  ((void (__thiscall *)(const DName *, int))((char *)&nameTable[23] + 2))(a1: &this->ErrorDName, a2: 3);
  ((void (__thiscall *)(const DName *, int))((char *)&nameTable[23] + 2))(a1: &this->InvalidDName, a2: 1);
  this->index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F6465BB
// Name: ??YReplicator@@QAEAAV0@ABVDName@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall Replicator::operator+=(_DWORD *this, struct DName *a2)
{
  char *Memory; // eax
  DName *v4; // eax

  if ( *this != 9 && ((int (__thiscall *)(struct DName *))((char *)&nameTable[53] + 2))(a1: a2) == 0 )
  {
    Memory = HeapManager::getMemory(this: &stru_3F663DA4, a2: 8u, a3: 0);
    if ( Memory != nullptr )
      v4 = DName::DName(this: (DName *)Memory, a2);
    else
      v4 = nullptr;
    if ( v4 != nullptr )
      *(this + ++*this + 1) = v4;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F646602
// Name: ?clone@DNameNode@@QAEPAV1@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
pDNameNode *__thiscall DNameNode::clone(DNameNode *this)
{
  char *Memory; // ebx
  char *v3; // eax

  Memory = HeapManager::getMemory(this: &stru_3F663DA4, a2: 0xCu, a3: 0);
  if ( Memory == nullptr )
    return nullptr;
  v3 = HeapManager::getMemory(this: &stru_3F663DA4, a2: 8u, a3: 0);
  if ( v3 != nullptr )
  {
    *((_DWORD *)v3 + 1) &= 0xFFFFF000;
    *(_DWORD *)v3 = this;
  }
  else
  {
    v3 = nullptr;
  }
  return pDNameNode::pDNameNode(this: (pDNameNode *)Memory, a2: (struct DName *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x3F6466AE
// Name: public: virtual char pcharNode::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall pcharNode::getLastChar(pcharNode *this)
{
  int myLen; // eax

  myLen = this->myLen;
  if ( myLen != 0 )
    return this->me[myLen - 1];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F6466C0
// Name: ?getString@pcharNode@@UBEPADPADH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall pcharNode::getString(pcharNode *this, char *a2, char *a3)
{
  const char *myLen; // edx
  char *me; // ecx
  char *result; // eax

  myLen = a3;
  if ( (int)a3 > this->myLen )
    myLen = (const char *)this->myLen;
  me = this->me;
  result = nullptr;
  if ( me != nullptr && a2 != nullptr && myLen != nullptr )
    return und_strncpy(a1: me, a2, a3: myLen);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6466F1
// Name: ?length@pDNameNode@@UBEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall pDNameNode::length(pDNameNode *this)
{
  if ( this->me != nullptr )
    JUMPOUT(0x3F6463F9);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F646700
// Name: ?getLastChar@pDNameNode@@UBEDXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall pDNameNode::getLastChar(pDNameNode *this)
{
  if ( this->me == nullptr )
    return 0;
  if ( ((int (*)(void))((char *)&nameTable[53] + 2))() == 0 )
    JUMPOUT(0x3F64642B);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64670F
// Name: ?getString@pDNameNode@@UBEPADPADH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall pDNameNode::getString(pDNameNode *this, char *a2, int a3)
{
  char *result; // eax

  result = nullptr;
  if ( this->me != nullptr && a2 != nullptr && a3 != 0 )
    JUMPOUT(0x3F646456);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64672C
// Name: ?getString@DNameStatusNode@@UBEPADPADH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall DNameStatusNode::getString(DNameStatusNode *this, char *a2, char *a3)
{
  const char *myLen; // edx
  char *result; // eax

  myLen = a3;
  if ( (int)a3 > this->myLen )
    myLen = (const char *)this->myLen;
  result = nullptr;
  if ( this->me == DN_truncated && a2 != nullptr && myLen != nullptr )
    return und_strncpy(a1: " ?? ", a2, a3: myLen);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64675F
// Name: ??0UnDecorator@@QAE@PADPBDHP6APADJ@ZK@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UnDecorator *__thiscall UnDecorator::UnDecorator(
        UnDecorator *this,
        char *a2,
        const char *a3,
        int a4,
        char *(__cdecl *a5)(int),
        unsigned int a6)
{
  Replicator::Replicator(this: &this->ArgList);
  Replicator::Replicator(this: &this->ZNameList);
  dword_3F663DC8 = (int)a3;
  dword_3F663DC4 = (int)a3;
  if ( a2 != nullptr )
  {
    dword_3F663DD0 = a4 - 1;
    dword_3F663DCC = (int)a2;
  }
  else
  {
    dword_3F663DCC = 0;
    dword_3F663DD0 = 0;
  }
  dword_3F663DD4 = a6;
  dword_3F663DBC = (int)&this->ZNameList;
  dword_3F663DD8 = (int)a5;
  dword_3F663DB8 = (int)this;
  byte_3F663DDC = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F6467D2
// Name: private: static class DName UnDecorator::getReturnType(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static struct DName *__cdecl UnDecorator::getReturnType(struct DName *a1, int a2)
{
  if ( *(_BYTE *)dword_3F663DC4 == 64 )
  {
    ++dword_3F663DC4;
    ((void (__thiscall *)(struct DName *, int))&nameTable[2])(a1, a2);
  }
  else
  {
    UnDecorator::getDataType(a1);
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6485D3
// Name: ?getZName@UnDecorator@@CA?AVDName@@_N@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static DName *__usercall UnDecorator::getZName@<eax>(int a1@<edi>, DName *a2, char a3)
{
  char v3; // dl
  unsigned int v4; // ecx
  const struct DName *v5; // eax
  _DWORD *v7; // eax
  int v8; // eax
  const char *v10; // ecx
  const char *v11; // edi
  _BYTE *v12; // esi
  int i; // ebx
  int v14; // eax
  const char *v15; // edi
  _BYTE *v16; // esi
  int j; // ebx
  const char *v18; // esi
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  _DWORD *v23; // eax
  int v25; // [esp-4h] [ebp-40h]
  _BYTE v26[8]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v27[8]; // [esp+Ch] [ebp-30h] BYREF
  DName *v28; // [esp+14h] [ebp-28h]
  DName v29; // [esp+18h] [ebp-24h] BYREF
  struct DName v30; // [esp+20h] [ebp-1Ch] BYREF
  char String[16]; // [esp+28h] [ebp-14h] BYREF

  v3 = *(_BYTE *)dword_3F663DC4;
  v4 = *(char *)dword_3F663DC4 - 48;
  v28 = a2;
  if ( v4 <= 9 )
  {
    ++dword_3F663DC4;
    v5 = (const struct DName *)Replicator::operator[](this: (_DWORD *)dword_3F663DBC, a2: v4);
    DName::DName(this: a2, a2: v5);
    return a2;
  }
  v30.node = nullptr;
  *((_DWORD *)&v30 + 1) &= 0xFFFFF000;
  if ( v3 == 63 )
  {
    v7 = (_DWORD *)((int (__cdecl *)(DName *, _DWORD))&pulCRCTable[228])(a1: &v29, a2: 0);
    DName::operator=(this: &v30, a2: v7);
    v8 = dword_3F663DC4 + 1;
    if ( *(_BYTE *)dword_3F663DC4++ != 64 )
    {
      dword_3F663DC4 = v8 - 1;
      DName::operator=(this: (DNameStatusNode **)&v30, a2: (enum DNameStatus)((*(_BYTE *)(v8 - 1) == 0) + 1));
    }
    goto LABEL_25;
  }
  v10 = "template-parameter-";
  v11 = "template-parameter-";
  v12 = (_BYTE *)dword_3F663DC4;
  for ( i = 18; i != 0; --i )
  {
    if ( *v12 == 0 )
      break;
    if ( *v12 != *v11 )
      break;
    ++v12;
    ++v11;
  }
  if ( *v12 == *v11 )
  {
    v14 = dword_3F663DC4 + 19;
  }
  else
  {
    v10 = "generic-type-";
    v15 = "generic-type-";
    v16 = (_BYTE *)dword_3F663DC4;
    for ( j = 12; j != 0; --j )
    {
      if ( *v16 == 0 )
        break;
      if ( *v16 != *v15 )
        break;
      ++v16;
      ++v15;
    }
    if ( *v16 != *v15 )
    {
      v23 = (_DWORD *)((int (__thiscall *)(_BYTE *, int *, int))&rgentry[47].m_wch)(
                        a1: v27,
                        a2: &dword_3F663DC4,
                        a3: 64);
      DName::operator=(this: &v30, a2: v23);
      goto LABEL_25;
    }
    v14 = dword_3F663DC4 + 13;
  }
  dword_3F663DC4 = v14;
  v18 = v10;
  ((void (__stdcall *)(DName *, int))((char *)&rgentry[706].m_wch + 1))(a1: &v29, a2: a1);
  if ( (dword_3F663DD4 & 0x4000) == 0 )
  {
    ((void (__thiscall *)(struct DName *, const char *))&rgentry[176].m_wch)(a1: &v30, a2: "`");
    v21 = ((int (__cdecl *)(_BYTE *, const char *, DName *))((char *)rgentry[339].m_pwchNormal + 1))(
            a1: v26,
            a2: v18,
            a3: &v29);
    goto LABEL_23;
  }
  DName::getString(this: &v29, a2: String, a3: 16);
  v19 = sub_3F628F99(String);
  v20 = dword_3F663DD8(a1: v19);
  if ( v20 == 0 )
  {
    ((void (__thiscall *)(struct DName *, const char *, int))&rgentry[176].m_wch)(a1: &v30, a2: "`", a3: v25);
    v21 = ((int (__cdecl *)(_BYTE *, const char *, DName *))((char *)rgentry[339].m_pwchNormal + 1))(
            a1: v27,
            a2: v18,
            a3: &v29);
LABEL_23:
    v22 = ((int (__thiscall *)(int))((char *)&rgentry[352].m_pwchNormal[1] + 1))(a1: v21);
    ((void (__thiscall *)(struct DName *, int))((char *)&rgentry[132].m_pwchNormal[1] + 1))(a1: &v30, a2: v22);
    goto LABEL_25;
  }
  ((void (__thiscall *)(struct DName *, int))&rgentry[176].m_wch)(a1: &v30, a2: v20);
LABEL_25:
  if ( a3 != 0 && *(_DWORD *)dword_3F663DBC != 9 )
    Replicator::operator+=(this: (_DWORD *)dword_3F663DBC, a2: &v30);
  DName::DName(this: v28, a2: &v30);
  return v28;
}

//------------------------------------------------------------------------------
// Address: 0x3F6488B0
// Name: ?getECSUDataType@UnDecorator@@CA?AVDName@@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static DName *__cdecl UnDecorator::getECSUDataType(DName *a1)
{
  BOOL v1; // ebx
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  _BYTE v11[8]; // [esp+8h] [ebp-18h] BYREF
  struct DName v12; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+18h] [ebp-8h] BYREF
  int v14; // [esp+1Ch] [ebp-4h]

  v1 = true;
  if ( (dword_3F663DD4 & 0x8000) != 0 || (dword_3F663DD4 & 0x1000) != 0 )
    v1 = false;
  v2 = *(char *)dword_3F663DC4;
  v13 = 0;
  v14 &= 0xFFFFF000;
  ++dword_3F663DC4;
  if ( v2 != 0 )
  {
    v3 = v2 - 84;
    if ( v3 != 0 )
    {
      v4 = v3 - 1;
      if ( v4 != 0 )
      {
        v5 = v4 - 1;
        if ( v5 != 0 )
        {
          v6 = v5 - 1;
          if ( v6 != 0 )
          {
            v7 = v6 - 1;
            if ( v7 != 0 )
            {
              if ( v7 == 1 )
                ((void (__thiscall *)(int *, const char *))&rgentry[176].m_wch)(a1: &v13, a2: "cointerface ");
            }
            else
            {
              ((void (__thiscall *)(int *, const char *))&rgentry[176].m_wch)(a1: &v13, a2: "coclass ");
            }
          }
          else
          {
            v1 = (dword_3F663DD4 & 0x8000) == 0;
            v8 = ((int (__cdecl *)(struct DName *))&rgentry[413].m_wch)(a1: &v12);
            v9 = (_DWORD *)((int (__cdecl *)(_BYTE *, const char *, int))((char *)rgentry[339].m_pwchNormal + 1))(
                             a1: v11,
                             a2: "enum ",
                             a3: v8);
            DName::operator=(this: &v13, a2: v9);
          }
        }
        else
        {
          ((void (__thiscall *)(int *, const char *))&rgentry[176].m_wch)(a1: &v13, a2: "class ");
        }
      }
      else
      {
        ((void (__thiscall *)(int *, const char *))&rgentry[176].m_wch)(a1: &v13, a2: "struct ");
      }
    }
    else
    {
      ((void (__thiscall *)(int *, const char *))&rgentry[176].m_wch)(a1: &v13, a2: "union ");
    }
    v12.node = nullptr;
    *((_DWORD *)&v12 + 1) &= 0xFFFFF000;
    if ( v1 )
      DName::operator=(this: &v12, a2: &v13);
    ((void (__cdecl *)(int *))UnDecorator::getScopedName)(a1: &v13);
    ((void (__thiscall *)(struct DName *, int *))((char *)&rgentry[132].m_pwchNormal[1] + 1))(a1: &v12, a2: &v13);
    DName::DName(this: a1, a2: &v12);
  }
  else
  {
    --dword_3F663DC4;
    ((void (__thiscall *)(DName *, char *))((char *)&rgentry[39].m_pwchNormal[1] + 1))(a1, a2: "nknown ecsu'");
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6489B0
// Name: ?getSymbolName@UnDecorator@@CA?AVDName@@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static DName *__usercall UnDecorator::getSymbolName@<eax>(int a1@<edi>, DName *a2)
{
  if ( *(_BYTE *)dword_3F663DC4 == 63 )
  {
    if ( *(_BYTE *)(dword_3F663DC4 + 1) == 36 )
    {
      ((void (__cdecl *)(DName *, int))&pulCRCTable[228])(a1: a2, a2: 1);
    }
    else
    {
      ++dword_3F663DC4;
      ((void (__cdecl *)(DName *, _DWORD, _DWORD))((char *)&rgentry[949].m_pwchNormal[1] + 1))(a1: a2, a2: 0, a3: 0);
    }
  }
  else
  {
    UnDecorator::getZName(a1, a2, a3: 1);
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F6489F6
// Name: ?getBasedType@UnDecorator@@CA?AVDName@@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static DName *__cdecl UnDecorator::getBasedType(DName *a1)
{
  char *v1; // eax
  int v2; // ecx
  int v3; // ecx
  int v4; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-10h] BYREF
  struct DName v7; // [esp+8h] [ebp-8h] BYREF

  v1 = UnDecorator::UScore(a1: TOK_basedLp);
  ((void (__thiscall *)(struct DName *, char *))((char *)&rgentry[39].m_pwchNormal[1] + 1))(a1: &v7, a2: v1);
  if ( *(_BYTE *)dword_3F663DC4 == 0 )
  {
    (*(void (__thiscall **)(struct DName *, int))__dnames)(a1: &v7, a2: 2);
    goto LABEL_9;
  }
  v2 = *(char *)dword_3F663DC4++ - 48;
  if ( v2 == 0 )
  {
    ((void (__thiscall *)(struct DName *, const char *))&rgentry[259].m_pwchNormal[1])(a1: &v7, a2: "void");
    goto LABEL_9;
  }
  v3 = v2 - 2;
  if ( v3 == 0 )
  {
    v4 = ((int (__cdecl *)(_BYTE *))UnDecorator::getScopedName)(a1: v6);
    ((void (__thiscall *)(struct DName *, int))((char *)&rgentry[132].m_pwchNormal[1] + 1))(a1: &v7, a2: v4);
    goto LABEL_9;
  }
  if ( v3 != 3 )
  {
LABEL_9:
    ((void (__thiscall *)(struct DName *, const char *))&rgentry[259].m_pwchNormal[1])(a1: &v7, a2: ") ");
    DName::DName(this: a1, a2: &v7);
    return a1;
  }
  ((void (__thiscall *)(DName *, int))((char *)&nameTable[23] + 2))(a1, a2: 1);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6495CA
// Name: ?getDecoratedName@UnDecorator@@CA?AVDName@@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static DName *__usercall UnDecorator::getDecoratedName@<eax>(int a1@<edi>, DName *a2)
{
  struct DName *v2; // eax
  _BYTE *v3; // eax
  _BYTE *i; // eax
  BOOL v5; // edi
  BOOL v6; // esi
  int v7; // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  int v10; // eax
  _DWORD *v11; // eax
  int v12; // edx
  struct DName v14; // [esp+8h] [ebp-20h] BYREF
  _BYTE v15[8]; // [esp+10h] [ebp-18h] BYREF
  struct DName v16; // [esp+18h] [ebp-10h] BYREF
  DName v17; // [esp+20h] [ebp-8h] BYREF

  if ( (dword_3F663DD4 & 0x2000) == 0 )
  {
    if ( *(_BYTE *)dword_3F663DC4 != 63 )
    {
      if ( *(_BYTE *)dword_3F663DC4 == 0 )
      {
        ((void (__thiscall *)(DName *, int))((char *)&nameTable[23] + 2))(a1: a2, a2: 2);
        return a2;
      }
      goto LABEL_35;
    }
    v3 = (_BYTE *)(dword_3F663DC4 + 1);
    dword_3F663DC4 = (int)v3;
    if ( *v3 == 63 && v3[1] == 63 )
    {
      UnDecorator::getDecoratedName();
      for ( i = (_BYTE *)dword_3F663DC4; *i != 0; dword_3F663DC4 = (int)i )
        ++i;
      goto LABEL_3;
    }
    UnDecorator::getSymbolName(a1, a2: &v17);
    v5 = ((int (__thiscall *)(DName *))((char *)&nameTable[53] + 2))(a1: &v17) == 0
      && (*((_BYTE *)&v17 + 4) & 0x20) != 0;
    v6 = (*((_WORD *)&v17 + 2) & 0x800) != 0;
    if ( ((int (__thiscall *)(DName *))((char *)&nameTable[47] + 3))(a1: &v17) == 0 )
    {
LABEL_17:
      v2 = &v17;
      goto LABEL_4;
    }
    if ( *(_BYTE *)dword_3F663DC4 != 0 && *(_BYTE *)dword_3F663DC4 != 64 )
    {
      ((void (__cdecl *)(struct DName *))UnDecorator::getScope)(a1: &v16);
      if ( ((int (__thiscall *)(struct DName *))((char *)&nameTable[53] + 2))(a1: &v16) == 0 )
      {
        if ( byte_3F663DDC == 0 )
        {
          v10 = ((int (__thiscall *)(struct DName *, _BYTE *, const char *, struct DName *, DName *))((char *)&rgentry[352].m_pwchNormal[1] + 1))(
                  a1: &v16,
                  a2: v15,
                  a3: "::",
                  a4: &v14,
                  a5: &v17);
          goto LABEL_25;
        }
        byte_3F663DDC = 0;
        v8 = (_DWORD *)((int (__thiscall *)(DName *, _BYTE *, int))((char *)&rgentry[220].m_pwchNormal[1] + 1))(
                         a1: &v17,
                         a2: v15,
                         a3: v7);
        DName::operator=(this: &v17, a2: v8);
        if ( *(_BYTE *)dword_3F663DC4 != 64 )
        {
          v9 = (_DWORD *)((int (__cdecl *)(_BYTE *))UnDecorator::getScope)(a1: v15);
          DName::operator=(this: &v16, a2: v9);
          v10 = ((int (__thiscall *)(struct DName *, struct DName *, const char *, _BYTE *, DName *))((char *)&rgentry[352].m_pwchNormal[1] + 1))(
                  a1: &v16,
                  a2: &v14,
                  a3: "::",
                  a4: v15,
                  a5: &v17);
LABEL_25:
          v11 = (_DWORD *)((int (__thiscall *)(int))((char *)&rgentry[220].m_pwchNormal[1] + 1))(a1: v10);
          DName::operator=(this: &v17, a2: v11);
        }
      }
    }
    if ( v5 && ((int (__thiscall *)(DName *))((char *)&nameTable[53] + 2))(a1: &v17) == 0 )
      *((_DWORD *)&v17 + 1) |= 0x20u;
    if ( v6 )
      *((_DWORD *)&v17 + 1) |= 0x800u;
    if ( ((int (__thiscall *)(DName *))((char *)&nameTable[53] + 2))(a1: &v17) != 0
      || (*((_WORD *)&v17 + 2) & 0x100) != 0 )
    {
      goto LABEL_17;
    }
    if ( *(_BYTE *)dword_3F663DC4 != 0 )
    {
      if ( *(_BYTE *)dword_3F663DC4 != 64 )
      {
LABEL_35:
        ((void (__thiscall *)(DName *, int))((char *)&nameTable[23] + 2))(a1: a2, a2: 1);
        return a2;
      }
      ++dword_3F663DC4;
    }
    if ( (dword_3F663DD4 & 0x1000) == 0 || v5 || (v12 & *((_DWORD *)&v17 + 1)) != 0 )
    {
      UnDecorator::composeDeclaration(a1: a2);
      return a2;
    }
    v16.node = nullptr;
    *((_DWORD *)&v16 + 1) &= 0xFFFFF000;
    UnDecorator::composeDeclaration(a1: &v14);
    goto LABEL_17;
  }
  dword_3F663DD4 &= ~0x2000u;
  UnDecorator::getDataType(a1: &v16);
  dword_3F663DD4 |= 0x2000u;
LABEL_3:
  v2 = &v16;
LABEL_4:
  DName::DName(this: a2, a2: v2);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F649A66
// Name: ?getFunctionIndirectType@UnDecorator@@CA?AVDName@@ABV2@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static DName *__usercall UnDecorator::getFunctionIndirectType@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        DName *a4,
        struct DName *a5)
{
  char v5; // cl
  int v6; // ebx
  _BYTE *v7; // eax
  bool v8; // cc
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  DName *BasedType; // eax
  int v15; // eax
  _DWORD *v16; // eax
  int v17; // eax
  DName *v18; // eax
  int v19; // eax
  _DWORD *v20; // eax
  int v21; // eax
  int v22; // eax
  _DWORD *v23; // eax
  char *Memory; // eax
  char *v25; // esi
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v32; // [esp-14h] [ebp-44h]
  int v33; // [esp-10h] [ebp-40h]
  DName v35; // [esp+0h] [ebp-30h] BYREF
  DName v36; // [esp+8h] [ebp-28h] BYREF
  _BYTE v37[8]; // [esp+10h] [ebp-20h] BYREF
  struct DName v38; // [esp+18h] [ebp-18h] BYREF
  int v39; // [esp+20h] [ebp-10h] BYREF
  int v40; // [esp+24h] [ebp-Ch]
  DName v41; // [esp+28h] [ebp-8h] BYREF

  v5 = *(_BYTE *)dword_3F663DC4;
  if ( *(_BYTE *)dword_3F663DC4 == 0 )
  {
    ((void (__cdecl *)(DName *, int, struct DName *))((char *)&rgentry[333].m_pwchNormal[1] + 1))(a1: a4, a2: 2, a3: a5);
    return a4;
  }
  if ( (v5 < 54 || v5 > 57) && v5 != 95 )
  {
    ((void (__thiscall *)(DName *, int))((char *)&nameTable[23] + 2))(a1: a4, a2: 1);
    return a4;
  }
  v6 = v5 - 54;
  v7 = (_BYTE *)++dword_3F663DC4;
  if ( v5 == 95 )
  {
    if ( *v7 == 0 )
    {
      ((void (__cdecl *)(DName *, int, struct DName *))((char *)&rgentry[333].m_pwchNormal[1] + 1))(
        a1: a4,
        a2: 2,
        a3: a5);
      return a4;
    }
    v6 = (char)*v7 - 61;
    dword_3F663DC4 = (int)(v7 + 1);
    if ( v6 >= 4 )
    {
      v8 = v6 <= 7;
      goto LABEL_14;
    }
  }
  else if ( v6 >= 0 )
  {
    v8 = v6 <= 3;
LABEL_14:
    if ( v8 )
      goto LABEL_16;
  }
  v6 = -1;
LABEL_16:
  if ( v6 == -1 )
  {
    ((void (__thiscall *)(DName *, int))((char *)&nameTable[23] + 2))(a1: a4, a2: 1);
  }
  else
  {
    v39 = 0;
    v40 &= 0xFFFFF000;
    DName::DName(this: &v41, a2: a5);
    if ( (v6 & 2) != 0 )
    {
      v9 = (_DWORD *)((int (__cdecl *)(_BYTE *, const char *, DName *))((char *)rgentry[339].m_pwchNormal + 1))(
                       a1: v37,
                       a2: "::",
                       a3: &v41);
      DName::operator=(this: &v41, a2: v9);
      if ( *(_BYTE *)dword_3F663DC4 != 0 )
      {
        v10 = ((int (__cdecl *)(DName *, _BYTE *, DName *))UnDecorator::getScope)(a1: &v36, a2: v37, a3: &v41);
        v11 = ((int (__cdecl *)(DName *, int, int))((char *)&rgentry[327].m_wch + 1))(a1: &v35, a2: 32, a3: v10);
        v12 = (_DWORD *)((int (__thiscall *)(int, int, int))((char *)&rgentry[220].m_pwchNormal[1] + 1))(
                          a1: v11,
                          a2: v32,
                          a3: v33);
      }
      else
      {
        v12 = (_DWORD *)((int (__cdecl *)(DName *, int, DName *))((char *)&rgentry[333].m_pwchNormal[1] + 1))(
                          a1: &v35,
                          a2: 2,
                          a3: &v41);
      }
      DName::operator=(this: &v41, a2: v12);
      if ( *(_BYTE *)dword_3F663DC4 == 0 )
      {
        ((void (__cdecl *)(DName *, int, DName *))((char *)&rgentry[333].m_pwchNormal[1] + 1))(a1: a4, a2: 2, a3: &v41);
        return a4;
      }
      if ( *(_BYTE *)dword_3F663DC4 != 64 )
      {
        ((void (__thiscall *)(DName *, int))((char *)&nameTable[23] + 2))(a1: a4, a2: 1);
        return a4;
      }
      ++dword_3F663DC4;
      if ( (dword_3F663DD4 & 0x60) == 0x60 )
      {
        v17 = ((int (__cdecl *)(DName *))((char *)tokenTable + 1))(a1: &v35);
        DName::operator|=(this: &v39, a2: v17);
      }
      else
      {
        v13 = (_DWORD *)((int (__cdecl *)(DName *))((char *)tokenTable + 1))(a1: &v35);
        DName::operator=(this: &v39, a2: v13);
      }
    }
    if ( (v6 & 4) != 0 )
    {
      if ( (~((unsigned int)dword_3F663DD4 >> 1) & 1) != 0 )
      {
        BasedType = UnDecorator::getBasedType(a1: &v36);
        v15 = ((int (__cdecl *)(_BYTE *, int, DName *))((char *)&rgentry[327].m_wch + 1))(
                a1: v37,
                a2: 32,
                a3: BasedType);
        v16 = (_DWORD *)((int (__thiscall *)(int, DName *, DName *))((char *)&rgentry[220].m_pwchNormal[1] + 1))(
                          a1: v15,
                          a2: &v35,
                          a3: &v41);
        DName::operator=(this: &v41, a2: v16);
      }
      else
      {
        v18 = UnDecorator::getBasedType(a1: &v35);
        DName::operator|=(this: &v41, a2: (int)v18);
      }
    }
    if ( (~((unsigned int)dword_3F663DD4 >> 1) & 1) != 0 )
    {
      v19 = ((int (__cdecl *)(DName *))&rgentry[183].m_wch)(a1: &v36);
      v20 = (_DWORD *)((int (__thiscall *)(int, DName *, DName *, int, int, int))((char *)&rgentry[220].m_pwchNormal[1]
                                                                                + 1))(
                        a1: v19,
                        a2: &v35,
                        a3: &v41,
                        a4: a2,
                        a5: a3,
                        a6: a1);
      DName::operator=(this: &v41, a2: v20);
    }
    else
    {
      v21 = ((int (__stdcall *)(DName *, int, int))&rgentry[183].m_wch)(a1: &v35, a2, a3);
      DName::operator|=(this: &v41, a2: v21);
    }
    if ( ((int (__thiscall *)(struct DName *))((char *)&nameTable[53] + 2))(a1: a5) == 0 )
    {
      v22 = ((int (__cdecl *)(DName *, int, DName *))((char *)&rgentry[327].m_wch + 1))(a1: &v36, a2: 40, a3: &v41);
      v23 = (_DWORD *)((int (__thiscall *)(int, DName *, int))((char *)&rgentry[344].m_wch + 1))(
                        a1: v22,
                        a2: &v35,
                        a3: 41);
      DName::operator=(this: &v41, a2: v23);
    }
    Memory = HeapManager::getMemory(this: &stru_3F663DA4, a2: 8u, a3: 0);
    if ( Memory != nullptr )
    {
      *(_DWORD *)Memory = 0;
      *((_DWORD *)Memory + 1) &= 0xFFFFF000;
      v25 = Memory;
    }
    else
    {
      v25 = nullptr;
    }
    UnDecorator::getReturnType(a1: &v38, a2: (int)v25);
    v26 = ((int (__cdecl *)(DName *, DName *, int))&rgentry[449])(a1: &v36, a2: &v35, a3: 41);
    v27 = ((int (__cdecl *)(_BYTE *, int, int))((char *)&rgentry[327].m_wch + 1))(a1: v37, a2: 40, a3: v26);
    v28 = ((int (__thiscall *)(int))((char *)&rgentry[344].m_wch + 1))(a1: v27);
    ((void (__thiscall *)(DName *, int))((char *)&rgentry[132].m_pwchNormal[1] + 1))(a1: &v41, a2: v28);
    if ( (dword_3F663DD4 & 0x60) != 0x60 && (v6 & 2) != 0 )
      ((void (__thiscall *)(DName *, int *))((char *)&rgentry[132].m_pwchNormal[1] + 1))(a1: &v41, a2: &v39);
    if ( (dword_3F663DD4 & 0x100) != 0 )
    {
      v30 = ((int (__cdecl *)(DName *))&rgentry[481].m_wch)(a1: &v35);
      DName::operator|=(this: &v41, a2: v30);
    }
    else
    {
      v29 = ((int (__cdecl *)(DName *))&rgentry[481].m_wch)(a1: &v35);
      ((void (__thiscall *)(DName *, int))((char *)&rgentry[132].m_pwchNormal[1] + 1))(a1: &v41, a2: v29);
    }
    if ( v25 != nullptr )
    {
      DName::operator=(this: v25, a2: &v41);
      DName::DName(this: a4, a2: &v38);
    }
    else
    {
      ((void (__thiscall *)(DName *, int))((char *)&nameTable[23] + 2))(a1: a4, a2: 3);
    }
  }
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x3F64A28B
// Name: ??BUnDecorator@@QAEPADXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall UnDecorator::operator char *@<eax>(int a1@<edi>)
{
  char v1; // al
  DName *DecoratedName; // eax
  DName *v3; // eax
  _DWORD *v4; // eax
  int v5; // eax
  char *result; // eax
  int v7; // eax
  char *v8; // eax
  _BYTE *v9; // edx
  char v10; // cl
  DName v11; // [esp+0h] [ebp-20h] BYREF
  DName v12; // [esp+8h] [ebp-18h] BYREF
  DName v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+18h] [ebp-8h] BYREF
  int v15; // [esp+1Ch] [ebp-4h]

  v14 = 0;
  v13.node = nullptr;
  v15 &= 0xFFFFF000;
  *((_DWORD *)&v13 + 1) &= 0xFFFFF000;
  if ( dword_3F663DC8 != 0 )
  {
    if ( *(_BYTE *)dword_3F663DC8 == 63 )
    {
      v1 = *(_BYTE *)(dword_3F663DC8 + 1);
      if ( v1 == 64 )
      {
        dword_3F663DC4 += 2;
        DecoratedName = UnDecorator::getDecoratedName(a1, a2: &v12);
        v3 = (DName *)((int (__cdecl *)(DName *, const char *, DName *))((char *)rgentry[339].m_pwchNormal + 1))(
                        a1: &v11,
                        a2: "CV: ",
                        a3: DecoratedName);
LABEL_9:
        DName::operator=(this: &v14, a2: v3);
        goto LABEL_10;
      }
      if ( v1 == 36 )
      {
        v4 = (_DWORD *)((int (__cdecl *)(DName *, _DWORD))&pulCRCTable[228])(a1: &v11, a2: 0);
        DName::operator=(this: &v14, a2: v4);
        if ( (v15 & 0xF) != 1 )
          goto LABEL_10;
        v15 &= 0xFFFFFFF0;
        dword_3F663DC4 = dword_3F663DC8;
      }
    }
    v3 = UnDecorator::getDecoratedName(a1, a2: &v11);
    goto LABEL_9;
  }
LABEL_10:
  v5 = v15 << 28 >> 28;
  if ( v5 == 3 )
    return nullptr;
  if ( v5 == 1 || (dword_3F663DD4 & 0x1000) == 0 && *(_BYTE *)dword_3F663DC4 != 0 )
    ((void (__thiscall *)(DName *, int))&rgentry[176].m_wch)(a1: &v13, a2: dword_3F663DC8);
  else
    DName::operator=(this: &v13, a2: &v14);
  result = (char *)dword_3F663DCC;
  if ( dword_3F663DCC != 0
    || (v7 = ((int (__thiscall *)(DName *))((char *)&nameTable[72] + 1))(a1: &v13),
        dword_3F663DD0 = v7 + 1,
        result = (char *)stru_3F663DA4.pOpNew(a1: (v7 + 8) & 0xFFFFFFF8),
        dword_3F663DCC = (int)result,
        result != nullptr) )
  {
    DName::getString(this: &v13, a2: result, a3: dword_3F663DD0);
    v8 = (char *)dword_3F663DCC;
    v9 = (_BYTE *)dword_3F663DCC;
    while ( 1 )
    {
      v10 = *v8;
      if ( *v8 == 0 )
        break;
      if ( v10 == 32 )
      {
        ++v8;
        *v9++ = 32;
        while ( *v8 == 32 )
          ++v8;
      }
      else
      {
        *v9++ = v10;
        ++v8;
      }
    }
    *v9 = 0;
    return (char *)dword_3F663DCC;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64AB49
// Name: ?getDataType@UnDecorator@@CA?AVDName@@PAV2@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static struct DName *__cdecl UnDecorator::getDataType(struct DName *a1, int a2)
{
  char v2; // al
  DNameNode *node; // eax
  struct DName v5; // [esp+0h] [ebp-18h] BYREF
  int v6; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+Ch] [ebp-Ch]
  _DWORD v8[2]; // [esp+10h] [ebp-8h] BYREF

  ((void (__thiscall *)(_DWORD *, int))&nameTable[2])(a1: v8, a2);
  v2 = *(_BYTE *)dword_3F663DC4;
  if ( *(_BYTE *)dword_3F663DC4 == 0 )
  {
    ((void (__cdecl *)(struct DName *, int, _DWORD *))((char *)&rgentry[333].m_pwchNormal[1] + 1))(a1, a2: 2, a3: v8);
    return a1;
  }
  if ( v2 == 63 )
  {
    ++dword_3F663DC4;
    v7 &= 0xFFFFF000;
    v6 = 0;
    node = UnDecorator::getDataIndirectType(a1: &v5, a2: (char)v8, a3: nullptr, a4: &v6).node;
    DName::operator=(this: v8, a2: node);
  }
  else if ( v2 == 88 )
  {
    ++dword_3F663DC4;
    if ( ((int (__thiscall *)(_DWORD *))((char *)&nameTable[53] + 2))(a1: v8) != 0 )
      ((void (__thiscall *)(struct DName *, const char *))((char *)&rgentry[39].m_pwchNormal[1] + 1))(a1, a2: "void");
    else
      ((void (__cdecl *)(struct DName *, const char *, _DWORD *))((char *)rgentry[339].m_pwchNormal + 1))(
        a1,
        a2: "void ",
        a3: v8);
    return a1;
  }
  UnDecorator::getPrimaryDataType(a1);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F64ABFA
// Name: ?getExternalDataType@UnDecorator@@CA?AVDName@@ABV2@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static struct DName *__cdecl UnDecorator::getExternalDataType(struct DName *a1, int a2)
{
  char *v2; // esi
  char *Memory; // eax
  int v4; // eax
  _DWORD *v5; // eax
  _BYTE v7[8]; // [esp+4h] [ebp-18h] BYREF
  _BYTE v8[8]; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v9[8]; // [esp+14h] [ebp-8h] BYREF

  v2 = nullptr;
  Memory = HeapManager::getMemory(this: &stru_3F663DA4, a2: 8u, a3: 0);
  if ( Memory != nullptr )
  {
    *((_DWORD *)Memory + 1) &= 0xFFFFF000;
    *(_DWORD *)Memory = 0;
    v2 = Memory;
  }
  UnDecorator::getDataType(a1, a2: (int)v2);
  ((void (__cdecl *)(_BYTE *))UnDecorator::getDataIndirectType)(a1: v9);
  v4 = ((int (__thiscall *)(_BYTE *, _BYTE *, int, _BYTE *, int))((char *)&rgentry[344].m_wch + 1))(
         a1: v9,
         a2: v7,
         a3: 32,
         a4: v8,
         a5: a2);
  v5 = (_DWORD *)((int (__thiscall *)(int))((char *)&rgentry[220].m_pwchNormal[1] + 1))(a1: v4);
  DName::operator=(this: v2, a2: v5);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F64AC5E
// Name: sub_3F64AC5E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64AC5E(int a1, int a2, int a3)
{
  HMODULE LibraryA; // eax
  HMODULE v4; // edi
  int (__stdcall *MessageBoxA)(HWND, LPCSTR, LPCSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  BOOL (__stdcall *GetUserObjectInformationA)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v10)(void); // esi
  int (__stdcall *v11)(int, int, _BYTE *, int, _BYTE *); // eax
  int (__stdcall *v12)(int, int, _BYTE *, int, _BYTE *); // edi
  int v13; // eax
  int (*v14)(void); // eax
  int (__stdcall *v15)(int); // eax
  int (__stdcall *v16)(int, int, int, int); // eax
  _BYTE v18[12]; // [esp+10h] [ebp-20h] BYREF
  _BYTE v19[4]; // [esp+1Ch] [ebp-14h] BYREF
  unsigned int v20; // [esp+20h] [ebp-10h] BYREF
  int v21; // [esp+24h] [ebp-Ch] BYREF
  int v22; // [esp+28h] [ebp-8h]
  int v23; // [esp+2Ch] [ebp-4h]

  v22 = sub_3F62D76A();
  v23 = 0;
  v21 = 0;
  v20 = 0;
  if ( dword_3F663DE0 == 0 )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "USER32.DLL");
    v4 = LibraryA;
    if ( LibraryA == nullptr )
      return 0;
    MessageBoxA = (int (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))GetProcAddress(
                                                                   hModule: LibraryA,
                                                                   lpProcName: "MessageBoxA");
    if ( MessageBoxA == nullptr )
      return 0;
    dword_3F663DE0 = ((int (__cdecl *)(int (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT)))_encode_pointer_0)(a1: MessageBoxA);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: v4, lpProcName: "GetActiveWindow");
    dword_3F663DE4 = ((int (__cdecl *)(HWND (__stdcall *)()))_encode_pointer_0)(a1: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: v4, lpProcName: "GetLastActivePopup");
    dword_3F663DE8 = ((int (__cdecl *)(HWND (__stdcall *)(HWND)))_encode_pointer_0)(a1: GetLastActivePopup);
    if ( ((int (__cdecl *)(int *))loc_3F62DD9E)(a1: &v21) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    if ( v21 == 2 )
    {
      GetUserObjectInformationA = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                            hModule: v4,
                                                                                            lpProcName: "GetUserObjectInformationA");
      dword_3F663DF0 = ((int (__cdecl *)(BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD)))_encode_pointer_0)(a1: GetUserObjectInformationA);
      if ( dword_3F663DF0 != 0 )
      {
        GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                             hModule: v4,
                                                             lpProcName: "GetProcessWindowStation");
        dword_3F663DEC = ((int (__cdecl *)(HWINSTA (__stdcall *)()))_encode_pointer_0)(a1: GetProcessWindowStation);
      }
    }
  }
  if ( dword_3F663DEC == v22
    || dword_3F663DF0 == v22
    || (v10 = (int (*)(void))_decode_pointer_0(a1: dword_3F663DEC),
        v11 = (int (__stdcall *)(int, int, _BYTE *, int, _BYTE *))_decode_pointer_0(a1: dword_3F663DF0),
        v12 = v11,
        v10 == nullptr)
    || v11 == nullptr
    || (v13 = v10()) != 0 && v12(a1: v13, a2: 1, a3: v18, a4: 12, a5: v19) != 0 && (v18[8] & 1) != 0 )
  {
    if ( dword_3F663DE4 != v22 )
    {
      v14 = (int (*)(void))_decode_pointer_0(a1: dword_3F663DE4);
      if ( v14 != nullptr )
      {
        v23 = v14();
        if ( v23 != 0 && dword_3F663DE8 != v22 )
        {
          v15 = (int (__stdcall *)(int))_decode_pointer_0(a1: dword_3F663DE8);
          if ( v15 != nullptr )
            v23 = v15(a1: v23);
        }
      }
    }
  }
  else
  {
    if ( sub_3F62DE4D(a1: &v20) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    if ( v20 < 4 )
      a3 |= 0x40000u;
    else
      a3 |= 0x200000u;
  }
  v16 = (int (__stdcall *)(int, int, int, int))_decode_pointer_0(a1: dword_3F663DE0);
  if ( v16 != nullptr )
    return v16(a1: v23, a2: a1, a3: a2, a4: a3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64AE1B
// Name: __set_error_mode_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_error_mode_0(int Mode)
{
  int result; // eax

  if ( Mode >= 0 )
  {
    if ( Mode <= 2 )
    {
      result = dword_3F663730;
      dword_3F663730 = Mode;
      return result;
    }
    if ( Mode == 3 )
      return dword_3F663730;
  }
  *_errno_0() = 22;
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F64AE61
// Name: sub_3F64AE61
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64AE61(int a1)
{
  dword_3F663734 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F64AE6B
// Name: sub_3F64AE6B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F64AE6B()
{
  return dword_3F663734;
}

//------------------------------------------------------------------------------
// Address: 0x3F64AFAC
// Name: ___crtGetLocaleInfoW_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetLocaleInfoW_0(
        struct localeinfo_struct *a1,
        unsigned int a2,
        unsigned int a3,
        wchar_t *a4,
        int a5,
        int a6)
{
  int result; // eax
  _LocaleUpdate v7; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v7, a2: a1);
  result = __crtGetLocaleInfoW_stat(a1: &v7.localeinfo, a2, a3, a4, a5, a6);
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64B219
// Name: sub_3F64B219
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F64B219()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64B414
// Name: nullsub_43
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_43()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F64B76F
// Name: ___crtGetStringTypeW_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeW_0(
        struct localeinfo_struct *a1,
        unsigned int a2,
        const wchar_t *a3,
        int a4,
        unsigned __int16 *a5,
        int a6,
        int a7)
{
  int result; // eax
  _LocaleUpdate v8; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v8, a2: a1);
  result = __crtGetStringTypeW_stat(a1: &v8.localeinfo, a2, a3, a4, a5, a6, a7);
  if ( v8.updated )
    v8.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64B7AD
// Name: __toupper_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _toupper_0(int C)
{
  return C - 32;
}

//------------------------------------------------------------------------------
// Address: 0x3F64B7B5
// Name: __toupper_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _toupper_l_0(int C, _locale_t Locale)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate v9; // [esp+4h] [ebp-18h] BYREF
  _BYTE v10[4]; // [esp+14h] [ebp-8h] BYREF
  char v11; // [esp+18h] [ebp-4h] BYREF
  char v12; // [esp+19h] [ebp-3h]
  char v13; // [esp+1Ah] [ebp-2h]
  int Ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &v9, a2: Locale);
  if ( (unsigned int)C >= 0x100 )
  {
    if ( v9.localeinfo.locinfo->mb_cur_max > 1
      && (Ca = C >> 8, ((int (__cdecl *)(_DWORD, _LocaleUpdate *))loc_3F62AC25)(a1: BYTE1(C), a2: &v9) != 0) )
    {
      v11 = Ca;
      v12 = C;
      v13 = 0;
      v6 = 2;
    }
    else
    {
      *_errno_0() = 42;
      v11 = C;
      v12 = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA_0(
           a1: &v9,
           a2: v9.localeinfo.locinfo->lc_handle[2],
           a3: 512,
           a4: &v11,
           a5: v6,
           a6: v10,
           a7: 3,
           a8: v9.localeinfo.locinfo->lc_codepage,
           a9: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = v10[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = v10[0];
        result = v10[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = v9.localeinfo.locinfo;
    if ( v9.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = v9.localeinfo.locinfo->pctype[C] & 2;
    }
    else
    {
      v4 = _isctype_l_0(C, Type: 2, Locale: &v9.localeinfo);
      locinfo = v9.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[C];
LABEL_18:
      if ( v9.updated )
        v9.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( v9.updated )
    v9.ptd->_ownlocale &= ~2u;
  return C;
}

//------------------------------------------------------------------------------
// Address: 0x3F64B8CD
// Name: _toupper_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl toupper_0(int C)
{
  int result; // eax

  if ( dword_3F6637BC != 0 )
    return _toupper_l_0(C, Locale: nullptr);
  result = C;
  if ( (unsigned int)(C - 97) <= 0x19 )
    return C - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64B8F4
// Name: _fastzero_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastzero_I(_OWORD *a1, unsigned int a2)
{
  unsigned int v3; // ecx

  v3 = a2 >> 7;
  do
  {
    *a1 = 0;
    a1[1] = 0;
    a1[2] = 0;
    a1[3] = 0;
    a1[4] = 0;
    a1[5] = 0;
    a1[6] = 0;
    a1[7] = 0;
    a1 += 8;
    --v3;
  }
  while ( v3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x3F64B94B
// Name: __VEC_memzero_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _VEC_memzero_0(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // [esp+4h] [ebp-Ch]

  result = a1;
  v4 = a1 % 16;
  if ( a1 % 16 != 0 )
  {
    memset((void *)a1, 0, 16 - v4);
    _VEC_memzero_0(a1: 16 - v4 + a1, a2: 0, a3: a3 - (16 - v4));
    return a1;
  }
  else
  {
    v5 = a3 & 0x7F;
    v6 = v5;
    if ( a3 != v5 )
    {
      fastzero_I((_OWORD *)a1, a2: a3 - v5);
      result = a1;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      memset((void *)(a3 + result - v5), 0, v6);
      return a1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64B9FE
// Name: __tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *_tzset_nolock()
{
  char *v0; // eax
  const char *v1; // esi
  size_t v2; // eax
  size_t v3; // eax
  int v4; // edi
  int v5; // edi
  int v6; // edi
  LPSTR *v7; // edi
  char *v8; // esi
  char v9; // al
  int *result; // eax
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int v15; // [esp+14h] [ebp-38h]
  int CodePage; // [esp+18h] [ebp-34h]
  int UsedDefaultChar; // [esp+1Ch] [ebp-30h] BYREF
  int v18; // [esp+20h] [ebp-2Ch]
  int v19; // [esp+24h] [ebp-28h] BYREF
  int v20; // [esp+28h] [ebp-24h] BYREF
  LPSTR *v21; // [esp+2Ch] [ebp-20h]
  int v22; // [esp+30h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  v15 = 0;
  v18 = 0;
  v22 = 0;
  v20 = 0;
  v19 = 0;
  _lock_0(a1: 7);
  ms_exc.registration.TryLevel = 0;
  v21 = (LPSTR *)sub_3F64C302();
  if ( sub_3F64C21A(a1: &v22) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  if ( sub_3F64C1B2(a1: &v20) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  if ( sub_3F64C1E6(a1: &v19) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  CodePage = ((int (*)(void))loc_3F63EC84)();
  dword_3F6641D4 = 0;
  *(_DWORD *)&output[420] = -1;
  *(_DWORD *)&output[408] = -1;
  v0 = getenv_0(VarName: "TZ");
  v1 = v0;
  if ( v0 == nullptr || *v0 == 0 )
  {
    if ( Str2 != nullptr )
    {
      ((void (__cdecl *)(char *))loc_3F609ED0)(a1: Str2);
      Str2 = nullptr;
    }
    if ( GetTimeZoneInformation(lpTimeZoneInformation: &TimeZoneInformation) != -1 )
    {
      dword_3F6641D4 = 1;
      v22 = 60 * TimeZoneInformation.Bias;
      if ( TimeZoneInformation.StandardDate.wMonth != 0 )
        v22 = 60 * TimeZoneInformation.StandardBias + 60 * TimeZoneInformation.Bias;
      if ( TimeZoneInformation.DaylightDate.wMonth != 0 && TimeZoneInformation.DaylightBias != 0 )
      {
        v20 = 1;
        v19 = 60 * (TimeZoneInformation.DaylightBias - TimeZoneInformation.StandardBias);
      }
      else
      {
        v20 = 0;
        v19 = 0;
      }
      if ( WideCharToMultiByte(
             CodePage,
             dwFlags: 0,
             lpWideCharStr: TimeZoneInformation.StandardName,
             cchWideChar: -1,
             lpMultiByteStr: *v21,
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &UsedDefaultChar) == 0
        || UsedDefaultChar != 0 )
      {
        **v21 = 0;
      }
      else
      {
        (*v21)[63] = 0;
      }
      if ( WideCharToMultiByte(
             CodePage,
             dwFlags: 0,
             lpWideCharStr: TimeZoneInformation.DaylightName,
             cchWideChar: -1,
             lpMultiByteStr: v21[1],
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &UsedDefaultChar) == 0
        || UsedDefaultChar != 0 )
      {
        *v21[1] = 0;
      }
      else
      {
        v21[1][63] = 0;
      }
    }
    goto LABEL_33;
  }
  if ( Str2 != nullptr )
  {
    if ( strcmp_0(Str1: v0, Str2: Str2) == 0 )
    {
LABEL_33:
      v18 = 1;
      goto LABEL_34;
    }
    if ( Str2 != nullptr )
      ((void (__cdecl *)(char *))loc_3F609ED0)(a1: Str2);
  }
  v2 = strlen_0(Str: v1);
  Str2 = (char *)((int (__cdecl *)(size_t))loc_3F609A30)(a1: v2 + 1);
  if ( Str2 == nullptr )
    goto LABEL_33;
  v3 = strlen_0(Str: v1);
  if ( strcpy_s_0(Destination: Str2, SizeInBytes: v3 + 1, Source: v1) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
LABEL_34:
  v4 = v22;
  *(_DWORD *)sub_3F64C2FC() = v4;
  v5 = v20;
  *(_DWORD *)sub_3F64C2F0() = v5;
  v6 = v19;
  *(_DWORD *)sub_3F64C2F6() = v6;
  ms_exc.registration.TryLevel = -2;
  result = (int *)_unlock_0(a1: 7);
  if ( v18 == 0 )
  {
    v7 = v21;
    if ( ((int (__cdecl *)(LPSTR, int, const char *, int))loc_3F63FE13)(a1: *v21, a2: 64, a3: v1, a4: 3) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    v8 = (char *)(v1 + 3);
    if ( *v8 == 45 )
    {
      v15 = 1;
      ++v8;
    }
    v22 = 3600 * sub_3F628F99(String: v8);
    while ( 1 )
    {
      v9 = *v8;
      if ( *v8 != 43 && (v9 < 48 || v9 > 57) )
        break;
      ++v8;
    }
    if ( *v8 == 58 )
    {
      v11 = sub_3F628F99(String: ++v8);
      v22 += 60 * v11;
      while ( *v8 >= 48 && *v8 <= 57 )
        ++v8;
      if ( *v8 == 58 )
      {
        v12 = sub_3F628F99(String: ++v8);
        v22 += v12;
        while ( *v8 >= 48 && *v8 <= 57 )
          ++v8;
      }
    }
    if ( v15 != 0 )
      v22 = -v22;
    v20 = *v8;
    if ( v20 != 0 )
    {
      if ( ((int (__cdecl *)(LPSTR, int, char *, int))loc_3F63FE13)(a1: v7[1], a2: 64, a3: v8, a4: 3) != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    }
    else
    {
      *v7[1] = 0;
    }
    v13 = v22;
    *(_DWORD *)sub_3F64C2FC() = v13;
    v14 = v20;
    result = (int *)sub_3F64C2F0();
    *result = v14;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64C0EA
// Name: ___tzset_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __tzset_0()
{
  int result; // eax

  if ( dword_3F6641DC == 0 )
  {
    _lock_0(a1: 6);
    if ( dword_3F6641DC == 0 )
    {
      _tzset_nolock();
      ++dword_3F6641DC;
    }
    return _unlock_0(a1: 6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64C139
// Name: __tzset_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _tzset_0()
{
  _lock_0(a1: 6);
  _tzset_nolock();
  _unlock_0(a1: 6);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C171
// Name: __isindst_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _isindst_0()
{
  int v1; // [esp+0h] [ebp-2Ch]
  int v2; // [esp+10h] [ebp-1Ch]

  _lock_0(a1: 6);
  v2 = ((int (__stdcall *)(int))_isindst_nolock)(a1: v1);
  _unlock_0(a1: 6);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F64C1B2
// Name: sub_3F64C1B2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64C1B2(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    *a1 = *(_DWORD *)&output[436];
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64C1E6
// Name: sub_3F64C1E6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64C1E6(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    *a1 = *(_DWORD *)&output[440];
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64C21A
// Name: sub_3F64C21A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64C21A(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    *a1 = *(_DWORD *)&output[432];
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64C24E
// Name: __get_tzname_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _get_tzname_0(size_t *ReturnValue, char *Buffer, size_t SizeInBytes, int Index)
{
  const char **v5; // esi
  size_t v6; // eax

  if ( Buffer == nullptr )
  {
    if ( SizeInBytes == 0 )
      goto LABEL_3;
LABEL_9:
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
  if ( SizeInBytes == 0 )
    goto LABEL_9;
LABEL_3:
  if ( Buffer != nullptr )
    *Buffer = 0;
  if ( ReturnValue != nullptr && (unsigned int)Index < 2 )
  {
    v5 = (const char **)&output[4 * Index + 576];
    v6 = strlen_0(Str: *v5) + 1;
    *ReturnValue = v6;
    if ( Buffer != nullptr )
    {
      if ( v6 <= SizeInBytes )
        return strcpy_s_0(Destination: Buffer, SizeInBytes, Source: *v5);
      else
        return 34;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64C2F0
// Name: sub_3F64C2F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *sub_3F64C2F0()
{
  return &output[436];
}

//------------------------------------------------------------------------------
// Address: 0x3F64C2F6
// Name: sub_3F64C2F6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *sub_3F64C2F6()
{
  return &output[440];
}

//------------------------------------------------------------------------------
// Address: 0x3F64C2FC
// Name: sub_3F64C2FC
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *sub_3F64C2FC()
{
  return &output[432];
}

//------------------------------------------------------------------------------
// Address: 0x3F64C302
// Name: sub_3F64C302
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *sub_3F64C302()
{
  return &output[576];
}

//------------------------------------------------------------------------------
// Address: 0x3F64C308
// Name: __ungetc_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock_0(int Character, FILE *Stream)
{
  int *v2; // edi
  _BYTE *v3; // eax
  int *v4; // edi
  char *v5; // eax
  int flag; // eax
  char *v8; // eax
  int v9; // eax

  if ( (Stream->_flag & 0x40) == 0 )
  {
    if ( _fileno_0(Stream) == -1 || _fileno_0(Stream) == -2 )
    {
      v3 = &unk_3F661428;
    }
    else
    {
      v2 = &dword_3F665FE0[_fileno_0(Stream) >> 5];
      v3 = (_BYTE *)(*v2 + 56 * (_fileno_0(Stream) & 0x1F));
    }
    if ( (v3[36] & 0x7F) != 0
      || (_fileno_0(Stream) == -1 || _fileno_0(Stream) == -2
        ? (v5 = (char *)&unk_3F661428)
        : (v4 = &dword_3F665FE0[_fileno_0(Stream) >> 5], v5 = (char *)(*v4 + 56 * (_fileno_0(Stream) & 0x1F))),
          v5[36] < 0) )
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      return -1;
    }
  }
  if ( Character == -1 )
    return -1;
  flag = Stream->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( Stream->_base == nullptr )
    ((void (__cdecl *)(FILE *))_getbuf_0)(a1: Stream);
  if ( Stream->_ptr == Stream->_base )
  {
    if ( Stream->_cnt != 0 )
      return -1;
    ++Stream->_ptr;
  }
  v8 = --Stream->_ptr;
  if ( (Stream->_flag & 0x40) != 0 )
  {
    if ( *v8 != (_BYTE)Character )
    {
      Stream->_ptr = v8 + 1;
      return -1;
    }
  }
  else
  {
    *v8 = Character;
  }
  v9 = Stream->_flag;
  ++Stream->_cnt;
  Stream->_flag = v9 & 0xFFFFFFEE | 1;
  return (unsigned __int8)Character;
}

//------------------------------------------------------------------------------
// Address: 0x3F64C426
// Name: _ungetc_1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ungetc_1(int Character, FILE *Stream)
{
  int v3; // [esp+10h] [ebp-1Ch]

  if ( Stream != nullptr )
  {
    _lock_file_0(Stream);
    v3 = _ungetc_nolock_0(Character, Stream);
    _unlock_file_0(Stream);
    return v3;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64C498
// Name: __mbtowc_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l_0(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes, _locale_t Locale)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate v8; // [esp+8h] [ebp-10h] BYREF

  if ( SrcCh == nullptr || SrcSizeInBytes == 0 )
    return 0;
  if ( *SrcCh == 0 )
  {
    if ( DstCh != nullptr )
      *DstCh = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(this: &v8, a2: Locale);
  if ( v8.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( DstCh != nullptr )
      *DstCh = *(unsigned __int8 *)SrcCh;
    goto LABEL_11;
  }
  if ( ((int (__cdecl *)(_DWORD, _LocaleUpdate *))loc_3F62AC25)(a1: *(unsigned __int8 *)SrcCh, a2: &v8) != 0 )
  {
    locinfo = v8.localeinfo.locinfo;
    mb_cur_max = v8.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && (int)SrcSizeInBytes >= mb_cur_max
      && (v7 = MultiByteToWideChar(
                 CodePage: v8.localeinfo.locinfo->lc_codepage,
                 dwFlags: 9u,
                 lpMultiByteStr: SrcCh,
                 cbMultiByte: mb_cur_max,
                 lpWideCharStr: DstCh,
                 cchWideChar: DstCh != nullptr) == 0,
          locinfo = v8.localeinfo.locinfo,
          !v7)
      || SrcSizeInBytes >= locinfo->mb_cur_max && SrcCh[1] != 0 )
    {
      result = locinfo->mb_cur_max;
      if ( v8.updated )
        v8.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(
              CodePage: v8.localeinfo.locinfo->lc_codepage,
              dwFlags: 9u,
              lpMultiByteStr: SrcCh,
              cbMultiByte: 1,
              lpWideCharStr: DstCh,
              cchWideChar: DstCh != nullptr) != 0 )
  {
LABEL_11:
    if ( v8.updated )
      v8.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno_0() = 42;
  if ( v8.updated )
    v8.ptd->_ownlocale &= ~2u;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F64C5AB
// Name: sub_3F64C5AB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64C5AB(wchar_t *DstCh, char *SrcCh, size_t SrcSizeInBytes)
{
  return _mbtowc_l_0(DstCh, SrcCh, SrcSizeInBytes, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C5C2
// Name: __fputwc_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wint_t __cdecl _fputwc_nolock_0(wchar_t Character, FILE *Stream)
{
  int *v2; // ebx
  _BYTE *v3; // eax
  int *v4; // ebx
  _BYTE *v5; // eax
  bool v6; // sf
  int v7; // eax
  int v9; // eax
  int *v10; // ebx
  char *v11; // eax
  int v12; // ebx
  int v13; // eax
  int SizeConverted; // [esp+Ch] [ebp-10h] BYREF
  char MbCh[8]; // [esp+10h] [ebp-Ch] BYREF

  if ( (Stream->_flag & 0x40) != 0 )
    goto LABEL_35;
  if ( _fileno_0(Stream) == -1 || _fileno_0(Stream) == -2 )
  {
    v3 = &unk_3F661428;
  }
  else
  {
    v2 = &dword_3F665FE0[_fileno_0(Stream) >> 5];
    v3 = (_BYTE *)(*v2 + 56 * (_fileno_0(Stream) & 0x1F));
  }
  if ( (v3[36] & 0x7F) == 2 )
    goto LABEL_35;
  if ( _fileno_0(Stream) == -1 || _fileno_0(Stream) == -2 )
  {
    v5 = &unk_3F661428;
  }
  else
  {
    v4 = &dword_3F665FE0[_fileno_0(Stream) >> 5];
    v5 = (_BYTE *)(*v4 + 56 * (_fileno_0(Stream) & 0x1F));
  }
  if ( (v5[36] & 0x7F) == 1 )
  {
    v6 = --Stream->_cnt < 0;
    if ( v6 )
    {
      v7 = _flsbuf_0(Ch: (char)Character, File: Stream);
    }
    else
    {
      *Stream->_ptr = Character;
      v7 = *(unsigned __int8 *)Stream->_ptr++;
    }
    if ( v7 != -1 )
    {
      v6 = --Stream->_cnt < 0;
      if ( v6 )
      {
        v9 = _flsbuf_0(Ch: SHIBYTE(Character), File: Stream);
      }
      else
      {
        *Stream->_ptr = HIBYTE(Character);
        v9 = *(unsigned __int8 *)Stream->_ptr++;
      }
      if ( v9 != -1 )
        return Character;
    }
    return -1;
  }
  if ( _fileno_0(Stream) == -1 || _fileno_0(Stream) == -2 )
  {
    v11 = (char *)&unk_3F661428;
  }
  else
  {
    v10 = &dword_3F665FE0[_fileno_0(Stream) >> 5];
    v11 = (char *)(*v10 + 56 * (_fileno_0(Stream) & 0x1F));
  }
  if ( v11[4] >= 0 )
  {
LABEL_35:
    v6 = Stream->_cnt - 2 < 0;
    Stream->_cnt -= 2;
    if ( v6 )
    {
      return ((int (__cdecl *)(_DWORD, FILE *))_flswbuf_0)(a1: Character, a2: Stream);
    }
    else
    {
      *(_WORD *)Stream->_ptr = Character;
      Stream->_ptr += 2;
      return Character;
    }
  }
  else
  {
    if ( sub_3F63BF49(&SizeConverted, MbCh, SizeInBytes: 5u, WCh: Character) != 0 )
      return -1;
    v12 = 0;
    if ( SizeConverted > 0 )
    {
      while ( 1 )
      {
        v6 = --Stream->_cnt < 0;
        if ( v6 )
        {
          v13 = _flsbuf_0(Ch: MbCh[v12], File: Stream);
        }
        else
        {
          *Stream->_ptr = MbCh[v12];
          v13 = *(unsigned __int8 *)Stream->_ptr++;
        }
        if ( v13 == -1 )
          break;
        if ( ++v12 >= SizeConverted )
          return Character;
      }
      return -1;
    }
    return Character;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64C7A0
// Name: _fputwc_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wint_t __cdecl fputwc_0(wchar_t Character, FILE *Stream)
{
  wint_t v3; // [esp+10h] [ebp-1Ch]

  if ( Stream != nullptr )
  {
    _lock_file_0(Stream);
    v3 = _fputwc_nolock_0(Character, Stream);
    _unlock_file_0(Stream);
    return v3;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64C81D
// Name: int x_ismbbtype_l(struct localeinfo_struct __near *,unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl x_ismbbtype_l(struct localeinfo_struct *a1, unsigned __int8 a2, int a3, unsigned __int8 a4)
{
  int result; // eax
  _LocaleUpdate v5; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v5, a2: a1);
  if ( (a4 & v5.localeinfo.mbcinfo->mbctype[a2 + 1]) != 0
    || (a3 == 0 ? (result = 0) : (result = (unsigned __int16)(a3 & v5.localeinfo.locinfo->pctype[a2])), result != 0) )
  {
    result = 1;
  }
  if ( v5.updated )
    v5.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64C86E
// Name: __ismbbkalnum_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbkalnum_l_0(unsigned int C, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: C, a3: 0, a4: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C883
// Name: __ismbbkalnum_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbkalnum_0(unsigned int C)
{
  return x_ismbbtype_l(a1: nullptr, a2: C, a3: 0, a4: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C896
// Name: __ismbbkprint_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbkprint_l_0(unsigned int C, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: C, a3: 0, a4: 3u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C8AB
// Name: __ismbbkprint_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbkprint_0(unsigned int C)
{
  return x_ismbbtype_l(a1: nullptr, a2: C, a3: 0, a4: 3u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C8BE
// Name: __ismbbkpunct_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbkpunct_l_0(unsigned int C, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: C, a3: 0, a4: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C8D3
// Name: __ismbbkpunct_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbkpunct_0(unsigned int C)
{
  return x_ismbbtype_l(a1: nullptr, a2: C, a3: 0, a4: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C8E6
// Name: __ismbbalnum_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbalnum_l_0(unsigned int C, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: C, a3: 263, a4: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C8FE
// Name: __ismbbalnum_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbalnum_0(unsigned int C)
{
  return x_ismbbtype_l(a1: nullptr, a2: C, a3: 263, a4: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C914
// Name: __ismbbalpha_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbalpha_l_0(unsigned int C, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: C, a3: 259, a4: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C92C
// Name: __ismbbalpha_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbalpha_0(unsigned int C)
{
  return x_ismbbtype_l(a1: nullptr, a2: C, a3: 259, a4: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C942
// Name: __ismbbgraph_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbgraph_l_0(unsigned int C, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: C, a3: 279, a4: 3u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C95A
// Name: __ismbbgraph_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbgraph_0(unsigned int C)
{
  return x_ismbbtype_l(a1: nullptr, a2: C, a3: 279, a4: 3u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C970
// Name: __ismbbprint_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbprint_l_0(unsigned int C, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: C, a3: 343, a4: 3u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C988
// Name: __ismbbprint_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbprint_0(unsigned int C)
{
  return x_ismbbtype_l(a1: nullptr, a2: C, a3: 343, a4: 3u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C99E
// Name: __ismbbpunct_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbpunct_l_0(unsigned int C, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: C, a3: 16, a4: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C9B3
// Name: __ismbbpunct_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbpunct_0(unsigned int C)
{
  return x_ismbbtype_l(a1: nullptr, a2: C, a3: 16, a4: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C9C6
// Name: __ismbblead_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead_l_0(unsigned int Ch, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: Ch, a3: 0, a4: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C9DB
// Name: __ismbblead_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead_0(unsigned int Ch)
{
  return x_ismbbtype_l(a1: nullptr, a2: Ch, a3: 0, a4: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64C9EE
// Name: __ismbbtrail_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbtrail_l_0(unsigned int Ch, _locale_t Locale)
{
  return x_ismbbtype_l(a1: Locale, a2: Ch, a3: 0, a4: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64CA03
// Name: __ismbbtrail_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbtrail_0(unsigned int Ch)
{
  return x_ismbbtype_l(a1: nullptr, a2: Ch, a3: 0, a4: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x3F64CA16
// Name: __ismbbkana_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbbkana_l_0(unsigned int C, _locale_t Locale)
{
  int result; // eax
  _LocaleUpdate v3; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v3, a2: Locale);
  if ( v3.localeinfo.mbcinfo != nullptr && v3.localeinfo.mbcinfo->mbcodepage == 932 )
  {
    result = x_ismbbtype_l(a1: Locale, a2: C, a3: 0, a4: 3u);
    if ( v3.updated )
      v3.ptd->_ownlocale &= ~2u;
  }
  else
  {
    if ( v3.updated )
      v3.ptd->_ownlocale &= ~2u;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64CA80
// Name: __chsize_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chsize_nolock_0(int a1, __int64 a2)
{
  __int64 v2; // rax
  int v3; // edi
  unsigned int v4; // esi
  HANDLE ProcessHeap; // eax
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // of
  int v10; // kr08_4
  int v11; // esi
  HANDLE v12; // eax
  __int64 v13; // rax
  void *v14; // eax
  unsigned int *v15; // esi
  __int64 v16; // rax
  __int64 v17; // [esp+Ch] [ebp-18h]
  __int64 v18; // [esp+14h] [ebp-10h]
  int v19; // [esp+1Ch] [ebp-8h]
  void *lpMem; // [esp+20h] [ebp-4h]

  HIDWORD(v18) = 0;
  v17 = _lseeki64_nolock_0(a1, a2: 0, a3: 0, dwMoveMethod: 1u);
  if ( (HIDWORD(v17) & (unsigned int)v17) == 0xFFFFFFFF )
    return *_errno_0();
  v2 = _lseeki64_nolock_0(a1, a2: 0, a3: 0, dwMoveMethod: 2u);
  if ( (HIDWORD(v2) & (unsigned int)v2) == 0xFFFFFFFF )
    return *_errno_0();
  v3 = (unsigned __int64)(a2 - v2) >> 32;
  v4 = a2 - v2;
  if ( v3 >= 0 && (a2 >= v2 && (unsigned __int64)(a2 - v2) >> 32 != 0 || v4 != 0) )
  {
    ProcessHeap = GetProcessHeap();
    lpMem = HeapAlloc(hHeap: ProcessHeap, dwFlags: 8u, dwBytes: 0x1000u);
    if ( lpMem == nullptr )
    {
      *_errno_0() = 12;
      return *_errno_0();
    }
    v19 = _setmode_nolock_0(a1, a2: 0x8000);
    while ( 1 )
    {
      v7 = v3 < 0 || v3 <= 0 && v4 < 0x1000 ? v4 : 4096;
      v8 = _write_nolock_0(a1, a2: lpMem, a3: v7);
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
    if ( *__doserrno_0() == 5 )
      *_errno_0() = 13;
    v11 = -1;
    HIDWORD(v18) = -1;
LABEL_20:
    _setmode_nolock_0(a1, a2: v19);
    v12 = GetProcessHeap();
    HeapFree(hHeap: v12, dwFlags: 0, lpMem);
    goto LABEL_28;
  }
  if ( v3 < 0 )
  {
    v13 = _lseeki64_nolock_0(a1, a2, a3: SHIDWORD(a2), dwMoveMethod: 0);
    if ( (HIDWORD(v13) & (unsigned int)v13) == 0xFFFFFFFF )
      return *_errno_0();
    v14 = (void *)((int (__cdecl *)(int))loc_3F63B222)(a1);
    v18 = SetEndOfFile(hFile: v14) - 1;
    if ( (HIDWORD(v18) & (unsigned int)v18) == 0xFFFFFFFF )
    {
      *_errno_0() = 13;
      v15 = __doserrno_0();
      *v15 = GetLastError();
      v11 = v18;
LABEL_28:
      if ( (HIDWORD(v18) & v11) == 0xFFFFFFFF )
        return *_errno_0();
    }
  }
  v16 = _lseeki64_nolock_0(a1, a2: v17, a3: SHIDWORD(v17), dwMoveMethod: 0);
  if ( (HIDWORD(v16) & (unsigned int)v16) == 0xFFFFFFFF )
    return *_errno_0();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64CC34
// Name: __chsize_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _chsize_s_0(int FileHandle, __int64 Size)
{
  errno_t v3; // esi
  int *v4; // ebx
  int v5; // esi
  int v6; // [esp+0h] [ebp-30h]
  int v7; // [esp+4h] [ebp-2Ch]
  int v8; // [esp+8h] [ebp-28h]
  int v9; // [esp+Ch] [ebp-24h]
  int v10; // [esp+10h] [ebp-20h]
  int v11; // [esp+14h] [ebp-1Ch]
  errno_t v12; // [esp+14h] [ebp-1Ch]
  int ms_exc; // [esp+18h] [ebp-18h]
  int ms_exc_4; // [esp+1Ch] [ebp-14h]
  int ms_exc_8; // [esp+20h] [ebp-10h]
  int ms_exc_12; // [esp+24h] [ebp-Ch]
  int ms_exc_16; // [esp+28h] [ebp-8h]

  if ( FileHandle == -2 )
  {
    *__doserrno_0() = 0;
    return 9;
  }
  if ( FileHandle < 0
    || FileHandle >= uNumber
    || (v4 = &dword_3F665FE0[FileHandle >> 5], v5 = 56 * (FileHandle & 0x1F), (*(_BYTE *)(*v4 + v5 + 4) & 1) == 0) )
  {
    *__doserrno_0() = 0;
    v3 = 9;
    *_errno_0() = 9;
LABEL_6:
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return v3;
  }
  if ( Size < 0 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 22;
    v3 = 22;
    goto LABEL_6;
  }
  ((void (__cdecl *)(int))loc_3F63B293)(a1: FileHandle);
  if ( (*(_BYTE *)(*v4 + v5 + 4) & 1) != 0 )
  {
    v11 = _chsize_nolock_0(a1: FileHandle, a2: Size);
  }
  else
  {
    *_errno_0() = 9;
    v11 = 9;
  }
  ((void (__stdcall *)(int, int, int, int, int, int, int, int, int, int, int, int, int))_LN9_16)(
    a1: FileHandle,
    a2: 1063570702,
    a3: v6,
    a4: v7,
    a5: v8,
    a6: v9,
    a7: v10,
    a8: v11,
    a9: ms_exc,
    a10: ms_exc_4,
    a11: ms_exc_8,
    a12: ms_exc_12,
    a13: ms_exc_16);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x3F64CD21
// Name: __chsize_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chsize_0(int FileHandle, int Size)
{
  return -(_chsize_s_0(FileHandle, Size) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F64CD39
// Name: __setmode_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmode_nolock_0(int a1, int a2)
{
  int v2; // edx
  int *v3; // esi
  int v4; // ecx
  int v5; // eax
  _BYTE *v6; // ecx
  char v7; // dl
  int v9; // [esp+14h] [ebp+8h]

  v2 = 56 * (a1 & 0x1F);
  v3 = &dword_3F665FE0[a1 >> 5];
  v4 = *v3 + v2;
  v9 = *(_BYTE *)(v4 + 4) & 0x80;
  v5 = (char)(2 * *(_BYTE *)(v4 + 36)) >> 1;
  if ( a2 == 0x4000 )
  {
    *(_BYTE *)(v4 + 4) |= 0x80u;
    *(_BYTE *)(*v3 + v2 + 36) &= 0x80u;
  }
  else if ( a2 == 0x8000 )
  {
    *(_BYTE *)(v4 + 4) &= ~0x80u;
  }
  else
  {
    if ( a2 == 0x10000 || a2 == 0x20000 )
    {
      *(_BYTE *)(v4 + 4) |= 0x80u;
      v6 = (_BYTE *)(*v3 + v2 + 36);
      v7 = *v6 & 0x80 | 2;
    }
    else
    {
      if ( a2 != 0x40000 )
        goto LABEL_11;
      *(_BYTE *)(v4 + 4) |= 0x80u;
      v6 = (_BYTE *)(*v3 + v2 + 36);
      v7 = *v6 & 0x80 | 1;
    }
    *v6 = v7;
  }
LABEL_11:
  if ( v9 != 0 )
    return v5 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x3F64CDF5
// Name: __set_fmode_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _set_fmode_0(int Mode)
{
  if ( Mode == 0x4000 || Mode == 0x8000 || Mode == 0x10000 )
  {
    InterlockedExchange(Target: &dword_3F6641E4, Value: Mode);
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64CE3B
// Name: sub_3F64CE3B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64CE3B(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    *a1 = dword_3F6641E4;
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64CE6F
// Name: __setmode_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmode_0(int FileHandle, int Mode)
{
  int *v3; // edi
  int v4; // esi
  int v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+4h] [ebp-2Ch]
  int v7; // [esp+8h] [ebp-28h]
  int v8; // [esp+Ch] [ebp-24h]
  int v9; // [esp+10h] [ebp-20h]
  int v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+14h] [ebp-1Ch]
  int ms_exc; // [esp+18h] [ebp-18h]
  int ms_exc_4; // [esp+1Ch] [ebp-14h]
  int ms_exc_8; // [esp+20h] [ebp-10h]
  int ms_exc_12; // [esp+24h] [ebp-Ch]
  int ms_exc_16; // [esp+28h] [ebp-8h]

  if ( Mode != 0x4000 && Mode != 0x8000 && Mode != 0x10000 && Mode != 0x40000 && Mode != 0x20000 )
  {
    *_errno_0() = 22;
LABEL_7:
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  if ( FileHandle == -2 )
  {
    *_errno_0() = 9;
    return -1;
  }
  if ( FileHandle < 0
    || FileHandle >= uNumber
    || (v3 = &dword_3F665FE0[FileHandle >> 5], v4 = 56 * (FileHandle & 0x1F), (*(_BYTE *)(*v3 + v4 + 4) & 1) == 0) )
  {
    *_errno_0() = 9;
    goto LABEL_7;
  }
  ((void (__cdecl *)(int))loc_3F63B293)(a1: FileHandle);
  if ( (*(_BYTE *)(*v3 + v4 + 4) & 1) != 0 )
  {
    v10 = _setmode_nolock_0(a1: FileHandle, a2: Mode);
  }
  else
  {
    *_errno_0() = 9;
    v10 = -1;
  }
  ((void (__stdcall *)(int, int, int, int, int, int, int, int, int, int, int, int, int))_LN9_16)(
    a1: FileHandle,
    a2: 1063571283,
    a3: v5,
    a4: v6,
    a5: v7,
    a6: v8,
    a7: v9,
    a8: v10,
    a9: ms_exc,
    a10: ms_exc_4,
    a11: ms_exc_8,
    a12: ms_exc_12,
    a13: ms_exc_16);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x3F64CF66
// Name: ___ascii_stricmp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ascii_stricmp_0(unsigned __int8 *a1, unsigned __int8 *a2)
{
  int v4; // eax
  int v5; // ecx

  do
  {
    v4 = *a1++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *a2++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( v4 != 0 && v4 == v5 );
  return v4 - v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F64CF9B
// Name: __stricmp_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stricmp_l_0(const char *String1, const char *String2, _locale_t Locale)
{
  int result; // eax
  const char *v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  _LocaleUpdate Localea; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &Localea, a2: Locale);
  if ( String1 != nullptr )
  {
    v4 = String2;
    if ( String2 != nullptr )
    {
      if ( Localea.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v5 = _tolower_l_0(C: *(unsigned __int8 *)String1++, Locale: &Localea.localeinfo);
          v6 = v5;
          v7 = _tolower_l_0(C: *(unsigned __int8 *)v4++, Locale: &Localea.localeinfo);
        }
        while ( v6 != 0 && v6 == v7 );
        result = v6 - v7;
      }
      else
      {
        result = __ascii_stricmp_0(a1: (unsigned __int8 *)String1, a2: (unsigned __int8 *)String2);
      }
      if ( Localea.updated )
        Localea.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      if ( Localea.updated )
        Localea.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    if ( Localea.updated )
      Localea.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D06E
// Name: sub_3F64D06E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64D06E(unsigned __int8 *String1, unsigned __int8 *String2)
{
  if ( dword_3F6637BC != 0 )
    return _stricmp_l_0((const char *)String1, (const char *)String2, Locale: nullptr);
  if ( String1 != nullptr && String2 != nullptr )
    return __ascii_stricmp_0(a1: String1, a2: String2);
  *_errno_0() = 22;
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D0BE
// Name: __putwch_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wint_t __cdecl _putwch_nolock_0(wchar_t Character)
{
  UINT ConsoleOutputCP; // eax
  DWORD v3; // eax
  unsigned int NumberOfCharsWritten; // [esp+4h] [ebp-10h] BYREF
  char MultiByteStr[8]; // [esp+8h] [ebp-Ch] BYREF

  if ( *(_DWORD *)&output[688] == 0 )
    goto LABEL_10;
  if ( *(_DWORD *)&output[700] == -2 )
    ((void (*)(void))&__initialmbcinfo.mbcasemap[82])();
  if ( *(_DWORD *)&output[700] == -1 )
    return -1;
  if ( !WriteConsoleW(
          hConsoleOutput: *(HANDLE *)&output[700],
          lpBuffer: &Character,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: &NumberOfCharsWritten,
          lpReserved: nullptr) )
  {
    if ( *(_DWORD *)&output[688] != 2 || GetLastError() != 120 )
      return -1;
    *(_DWORD *)&output[688] = 0;
LABEL_10:
    ConsoleOutputCP = GetConsoleOutputCP();
    v3 = WideCharToMultiByte(
           CodePage: ConsoleOutputCP,
           dwFlags: 0,
           lpWideCharStr: &Character,
           cchWideChar: 1,
           lpMultiByteStr: MultiByteStr,
           cbMultiByte: 5,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    if ( *(_DWORD *)&output[700] != -1
      && WriteConsoleA(
           hConsoleOutput: *(HANDLE *)&output[700],
           lpBuffer: MultiByteStr,
           nNumberOfCharsToWrite: v3,
           lpNumberOfCharsWritten: &NumberOfCharsWritten,
           lpReserved: nullptr) )
    {
      return Character;
    }
    return -1;
  }
  *(_DWORD *)&output[688] = 1;
  return Character;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D180
// Name: __cputws_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cputws_0(const wchar_t *Buffer)
{
  int v2; // eax
  wint_t v3; // ax
  int v4; // [esp+10h] [ebp-20h]
  int v5; // [esp+14h] [ebp-1Ch]

  v4 = 0;
  if ( Buffer != nullptr )
  {
    v5 = ((int (__cdecl *)(const wchar_t *))&__initialmbcinfo.mbcasemap[158])(a1: Buffer);
    _lock_0(a1: 3);
    while ( 1 )
    {
      v2 = v5--;
      if ( v2 == 0 )
        break;
      v3 = _putwch_nolock_0(Character: *Buffer++);
      if ( v3 == 0xFFFF )
      {
        v4 = -1;
        break;
      }
    }
    _unlock_0(a1: 3);
    return v4;
  }
  else
  {
    *__doserrno_0() = 0;
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64D258
// Name: sub_3F64D258
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F64D258()
{
  return _unlock_0(a1: 3);
}

//------------------------------------------------------------------------------
// Address: 0x3F64D261
// Name: __strnicmp_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strnicmp_l_0(const char *String1, const char *String2, size_t MaxCount, _locale_t Locale)
{
  int result; // eax
  const char *v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  _LocaleUpdate Localea; // [esp+Ch] [ebp-10h] BYREF

  if ( MaxCount == 0 )
    return 0;
  _LocaleUpdate::_LocaleUpdate(this: &Localea, a2: Locale);
  if ( String1 != nullptr && (v5 = String2, String2 != nullptr) )
  {
    if ( MaxCount <= 0x7FFFFFFF )
    {
      if ( Localea.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v6 = _tolower_l_0(C: *(unsigned __int8 *)String1++, Locale: &Localea.localeinfo);
          v7 = v6;
          v8 = _tolower_l_0(C: *(unsigned __int8 *)v5++, Locale: &Localea.localeinfo);
          --MaxCount;
        }
        while ( MaxCount != 0 && v7 != 0 && v7 == v8 );
        result = v7 - v8;
      }
      else
      {
        result = ((int (__cdecl *)(const char *, const char *, size_t))&__initialmbcinfo.mbcasemap[195])(
                   a1: String1,
                   a2: String2,
                   a3: MaxCount);
      }
      if ( Localea.updated )
        Localea.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      if ( Localea.updated )
        Localea.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    if ( Localea.updated )
      Localea.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D351
// Name: sub_3F64D351
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64D351(char *String1, char *String2, size_t MaxCount)
{
  if ( dword_3F6637BC != 0 )
    return _strnicmp_l_0(String1, String2, MaxCount, Locale: nullptr);
  if ( String1 != nullptr && String2 != nullptr && MaxCount <= 0x7FFFFFFF )
    JUMPOUT(0x3F64E210);
  *_errno_0() = 22;
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D3AD
// Name: xtoa_s(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge xtoa_s@<eax>(unsigned int a1@<eax>, _BYTE *a2@<ecx>, unsigned int a3, unsigned int a4, int a5)
{
  _BYTE *v5; // esi
  int *v7; // eax
  int v8; // esi
  char *v9; // edi
  char v10; // dl
  unsigned int v11; // et2
  char v12; // dl
  char *v13; // ecx
  char v14; // al
  int v15; // [esp-8h] [ebp-14h]
  unsigned int v16; // [esp+8h] [ebp-4h]

  v5 = a2;
  if ( a2 == nullptr )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
  if ( a3 == 0 )
    goto LABEL_4;
  *a2 = 0;
  if ( a3 <= (unsigned int)(a5 != 0) + 1 )
  {
LABEL_7:
    v7 = _errno_0();
    v15 = 34;
    goto LABEL_5;
  }
  if ( a4 - 2 > 0x22 )
  {
LABEL_4:
    v7 = _errno_0();
    v15 = 22;
LABEL_5:
    v8 = v15;
    *v7 = v15;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return v8;
  }
  v16 = 0;
  if ( a5 != 0 )
  {
    *a2++ = 45;
    v16 = 1;
    a1 = -a1;
  }
  v9 = a2;
  do
  {
    v11 = a1 % a4;
    a1 /= a4;
    v10 = v11;
    if ( v11 <= 9 )
      v12 = v10 + 48;
    else
      v12 = v10 + 87;
    *a2++ = v12;
    ++v16;
  }
  while ( a1 != 0 && v16 < a3 );
  if ( v16 >= a3 )
  {
    *v5 = 0;
    goto LABEL_7;
  }
  *a2 = 0;
  v13 = a2 - 1;
  do
  {
    v14 = *v13;
    *v13-- = *v9;
    *v9++ = v14;
  }
  while ( v9 < v13 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D488
// Name: __itoa_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _itoa_s_0(int Value, char *Buffer, size_t BufferCount, int Radix)
{
  if ( Radix == 10 && Value < 0 )
    return xtoa_s(a1: Value, a2: Buffer, a3: BufferCount, a4: 0xAu, a5: 1);
  else
    return xtoa_s(a1: Value, a2: Buffer, a3: BufferCount, a4: Radix, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F64D4B0
// Name: __ltoa_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _ltoa_s_0(int Value, char *Buffer, size_t BufferCount, int Radix)
{
  BOOL v4; // eax

  v4 = false;
  if ( Radix == 10 )
    v4 = Value < 0;
  return xtoa_s(a1: Value, a2: Buffer, a3: BufferCount, a4: Radix, a5: v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F64D4D5
// Name: __ultoa_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _ultoa_s_0(unsigned int Value, char *Buffer, size_t BufferCount, int Radix)
{
  return xtoa_s(a1: Value, a2: Buffer, a3: BufferCount, a4: Radix, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F64D4ED
// Name: x64toa_s(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge x64toa_s@<eax>(char *a1@<edi>, __int64 a2, unsigned int a3, unsigned int a4, int a5)
{
  int *v5; // eax
  int v6; // esi
  unsigned int v8; // eax
  int v9; // edx
  char *v10; // esi
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rcx
  unsigned int v13; // ecx
  char *v14; // esi
  char v15; // cl
  int v16; // [esp-4h] [ebp-18h]
  int v17; // [esp+10h] [ebp-4h]
  char *v18; // [esp+2Ch] [ebp+18h]

  if ( a1 != nullptr && a3 != 0 )
  {
    *a1 = 0;
    if ( a3 <= (unsigned int)(a5 != 0) + 1 )
    {
      v5 = _errno_0();
      v16 = 34;
      goto LABEL_3;
    }
    if ( a4 - 2 <= 0x22 )
    {
      v8 = HIDWORD(a2);
      v9 = a2;
      v17 = 0;
      v10 = a1;
      if ( a5 != 0 )
      {
        v9 = -(int)a2;
        *a1 = 45;
        v10 = a1 + 1;
        v17 = 1;
        v8 = (unsigned __int64)-a2 >> 32;
      }
      v18 = v10;
      while ( 1 )
      {
        v12 = __PAIR64__(v8, v9) % a4;
        v11 = __PAIR64__(v8, v9) / a4;
        HIDWORD(v12) = HIDWORD(v11);
        v9 = v11;
        v8 = HIDWORD(v12);
        LOBYTE(v12) = (unsigned int)v12 <= 9 ? v12 + 48 : (unsigned __int8)v12 + 87;
        *v10++ = v12;
        v13 = ++v17;
        if ( HIDWORD(v12) == 0 && v9 == 0 )
          break;
        if ( v13 >= a3 )
        {
          v13 = v17;
          break;
        }
      }
      if ( v13 >= a3 )
      {
        *a1 = 0;
        *_errno_0() = 34;
        v6 = 34;
        goto LABEL_4;
      }
      *v10 = 0;
      v14 = v10 - 1;
      do
      {
        v15 = *v14;
        *v14-- = *v18;
        *v18++ = v15;
      }
      while ( v18 < v14 );
      return 0;
    }
  }
  v5 = _errno_0();
  v16 = 22;
LABEL_3:
  v6 = v16;
  *v5 = v16;
LABEL_4:
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D5E3
// Name: __i64toa_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _i64toa_s_0(__int64 Value, char *Buffer, size_t BufferCount, int Radix)
{
  BOOL v4; // eax

  v4 = false;
  if ( Radix == 10 && SHIDWORD(Value) <= 0 )
    v4 = Value < 0;
  return x64toa_s(a1: Buffer, a2: Value, a3: BufferCount, a4: Radix, a5: v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F64D616
// Name: __ui64toa_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _ui64toa_s_0(unsigned __int64 Value, char *Buffer, size_t BufferCount, int Radix)
{
  return x64toa_s(a1: Buffer, a2: Value, a3: BufferCount, a4: Radix, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F64D633
// Name: sub_3F64D633
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64D633(int a1, int a2, struct localeinfo_struct *a3)
{
  int v3; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate v7; // [esp+10h] [ebp-24h] BYREF
  int v8; // [esp+20h] [ebp-14h]
  _BYTE v9[12]; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v7, a2: a3);
  v8 = ((int (__cdecl *)(_BYTE *, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _LocaleUpdate *))__strgtold12_l_0)(
         a1: v9,
         a2: v6,
         a3: a2,
         a4: 0,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: &v7);
  v3 = ((int (__cdecl *)(_BYTE *, int))loc_3F643E20)(a1: v9, a2: a1);
  if ( (v8 & 3) != 0 )
  {
    if ( (v8 & 1) != 0 )
      goto LABEL_8;
    if ( (v8 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == 1 )
    {
LABEL_3:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == 2 )
    {
LABEL_8:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D6EC
// Name: __atoldbl_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atoldbl_l_0(_LDOUBLE *Result, char *String, _locale_t Locale)
{
  int v3; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate v7; // [esp+10h] [ebp-24h] BYREF
  int v8; // [esp+20h] [ebp-14h]
  unsigned __int16 v9[6]; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v7, a2: Locale);
  v8 = ((int (__cdecl *)(unsigned __int16 *, _BYTE *, char *, int, _DWORD, _DWORD, _DWORD, _LocaleUpdate *))__strgtold12_l_0)(
         a1: v9,
         a2: v6,
         a3: String,
         a4: 1,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: &v7);
  v3 = _ld12told_0(a1: v9, a2: (int)Result);
  if ( (v8 & 3) != 0 )
  {
    if ( (v8 & 1) != 0 )
      goto LABEL_8;
    if ( (v8 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == 1 )
    {
LABEL_3:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == 2 )
    {
LABEL_8:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D7A6
// Name: sub_3F64D7A6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64D7A6(int a1, int a2, struct localeinfo_struct *a3)
{
  int v3; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate v7; // [esp+10h] [ebp-24h] BYREF
  int v8; // [esp+20h] [ebp-14h]
  _BYTE v9[12]; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v7, a2: a3);
  v8 = ((int (__cdecl *)(_BYTE *, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _LocaleUpdate *))__strgtold12_l_0)(
         a1: v9,
         a2: v6,
         a3: a2,
         a4: 0,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: &v7);
  v3 = ((int (__cdecl *)(_BYTE *, int))&first_127char[18])(a1: v9, a2: a1);
  if ( (v8 & 3) != 0 )
  {
    if ( (v8 & 1) != 0 )
      goto LABEL_8;
    if ( (v8 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == 1 )
    {
LABEL_3:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == 2 )
    {
LABEL_8:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D896
// Name: sub_3F64D896
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F64D896()
{
  return dword_3F6641E0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D89C
// Name: __fptostr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fptostr_0(char *a1, unsigned int a2, int a3, int a4)
{
  int v4; // ecx
  char *v5; // edi
  int v6; // esi
  int v8; // edx
  int v9; // eax
  char *v10; // eax
  char v11; // cl
  size_t v12; // eax

  v4 = a4;
  v5 = *(char **)(a4 + 12);
  if ( a1 == nullptr || a2 == 0 )
  {
    v6 = 22;
    *_errno_0() = 22;
LABEL_3:
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return v6;
  }
  v8 = a3;
  *a1 = 0;
  if ( a3 <= 0 )
    v9 = 0;
  else
    v9 = a3;
  if ( a2 <= v9 + 1 )
  {
    *_errno_0() = 34;
    v6 = 34;
    goto LABEL_3;
  }
  *a1 = 48;
  v10 = a1 + 1;
  if ( a3 > 0 )
  {
    do
    {
      v11 = *v5;
      if ( *v5 != 0 )
        ++v5;
      else
        v11 = 48;
      *v10++ = v11;
      --v8;
    }
    while ( v8 > 0 );
    v4 = a4;
  }
  *v10 = 0;
  if ( v8 >= 0 && *v5 >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *a1 == 49 )
  {
    ++*(_DWORD *)(v4 + 4);
  }
  else
  {
    v12 = strlen_0(Str: a1 + 1);
    memcpy_0(a1, Src: a1 + 1, Size: v12 + 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64D959
// Name: ___dtold_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __dtold_0(int *a1, int *a2)
{
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax
  __int16 v7; // cx
  __int16 v8; // di
  int *result; // eax
  __int16 v10; // cx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-4h]
  __int16 v15; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)a2 + 3) >> 4) & 0x7FF;
  v15 = *((_WORD *)a2 + 3) & 0x8000;
  v4 = a2[1];
  v5 = *a2;
  v6 = v4 & 0xFFFFF;
  v14 = 0x80000000;
  if ( (_WORD)v3 == 0 )
  {
    if ( v6 == 0 && v5 == 0 )
    {
      result = a1;
      v10 = v15;
      a1[1] = 0;
      *a1 = 0;
      goto LABEL_13;
    }
    v7 = 15361;
    v14 = 0;
    goto LABEL_9;
  }
  if ( (unsigned __int16)v3 != 2047 )
  {
    v7 = v3 + 15360;
LABEL_9:
    v8 = v7;
    goto LABEL_10;
  }
  v8 = 0x7FFF;
LABEL_10:
  v11 = v14 | (v6 << 11) | (v5 >> 21);
  result = a1;
  a1[1] = v11;
  *a1 = v5 << 11;
  if ( (v11 & 0x80000000) == 0 )
  {
    do
    {
      v12 = *(__int64 *)a1 >> 31;
      v13 = 2 * *a1;
      --v8;
      a1[1] = v12;
      *a1 = v13;
    }
    while ( (v12 & 0x80000000) == 0 );
  }
  v10 = v8 | v15;
LABEL_13:
  *((_WORD *)result + 4) = v10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64DA14
// Name: __fltout2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl _fltout2_0(int a1, int a2, _DWORD *a3, char *a4, rsize_t SizeInBytes)
{
  _DWORD *v5; // ebx
  __int16 v7; // [esp-10h] [ebp-4Ch]
  char *Destination; // [esp+Ch] [ebp-30h]
  __int16 v9; // [esp+10h] [ebp-2Ch] BYREF
  char v10; // [esp+12h] [ebp-2Ah]
  char Source[24]; // [esp+14h] [ebp-28h] BYREF
  int v12[3]; // [esp+2Ch] [ebp-10h] BYREF

  v5 = a3;
  Destination = a4;
  __dtold_0(a1: v12, a2: &a1);
  v7 = v12[2];
  v5[2] = ((int (__cdecl *)(int, int, __int16, int, _DWORD, __int16 *))&_mbctype[33])(
            a1: v12[0],
            a2: v12[1],
            a3: v7,
            a4: 17,
            a5: 0,
            a6: &v9);
  *v5 = v10;
  v5[1] = v9;
  if ( strcpy_s_0(Destination, SizeInBytes, Source) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  v5[3] = Destination;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F64DAB0
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
// Address: 0x3F64DB90
// Name: __aullshr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __usercall _aullshr_0@<edx:eax>(unsigned __int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
    return 0;
  else
    return a1 >> a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F64DBAF
// Name: __controlfp_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _controlfp_s_0(unsigned int *CurrentState, unsigned int NewValue, unsigned int Mask)
{
  unsigned int v4; // [esp-4h] [ebp-8h]

  if ( (Mask & 0xFFF7FFFF & NewValue & 0xFCF0FCE0) != 0 )
  {
    if ( CurrentState != nullptr )
      *CurrentState = _control87_0(NewValue: 0, Mask: 0);
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
  else
  {
    v4 = Mask & 0xFFF7FFFF;
    if ( CurrentState != nullptr )
      *CurrentState = _control87_0(NewValue, Mask: v4);
    else
      _control87_0(NewValue, Mask: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F64DC19
// Name: _getenv_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv_0(const char *VarName)
{
  const char **v1; // esi
  size_t v3; // edi

  v1 = (const char **)dword_3F66376C;
  if ( dword_3F667108 == 0 )
    return nullptr;
  if ( dword_3F66376C != 0
    || dword_3F663774 != 0
    && ((int (*)(void))__wtomb_environ_0)() == 0
    && (v1 = (const char **)dword_3F66376C, dword_3F66376C != 0) )
  {
    if ( VarName != nullptr )
    {
      v3 = strlen_0(Str: VarName);
      while ( *v1 != nullptr )
      {
        if ( strlen_0(Str: *v1) > v3
          && (*v1)[v3] == 61
          && sub_3F64FC40(Str1: (unsigned __int8 *)*v1, Str2: (unsigned __int8 *)VarName, MaxCount: v3) == 0 )
        {
          return (char *)&(*v1)[v3 + 1];
        }
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F64DC9A
// Name: __getenv_s_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _getenv_s_helper@<eax>(size_t *a1@<eax>, char *Destination, rsize_t SizeInBytes, char *VarName)
{
  char *v6; // eax
  const char *v7; // edi
  size_t v8; // eax

  if ( a1 == nullptr )
    goto LABEL_2;
  *a1 = 0;
  if ( Destination != nullptr )
  {
    if ( SizeInBytes == 0 )
      goto LABEL_2;
  }
  else if ( SizeInBytes != 0 )
  {
LABEL_2:
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
  if ( Destination != nullptr )
    *Destination = 0;
  v6 = getenv_0(VarName);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v8 = strlen_0(Str: v6) + 1;
    *a1 = v8;
    if ( SizeInBytes != 0 )
    {
      if ( v8 > SizeInBytes )
        return 34;
      if ( strcpy_s_0(Destination, SizeInBytes, Source: v7) != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F64DD2D
// Name: __dupenv_s_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _dupenv_s_helper@<eax>(char **a1@<ebx>, rsize_t *a2, char *VarName)
{
  char *v4; // eax
  rsize_t v5; // esi
  char *v6; // eax
  char *Source; // [esp+8h] [ebp-4h]

  if ( a1 != nullptr )
  {
    *a1 = nullptr;
    if ( a2 != nullptr )
      *a2 = 0;
    if ( VarName != nullptr )
    {
      v4 = getenv_0(VarName);
      Source = v4;
      if ( v4 != nullptr )
      {
        v5 = strlen_0(Str: v4) + 1;
        v6 = (char *)((int (__cdecl *)(rsize_t, int))loc_3F609A90)(a1: v5, a2: 1);
        *a1 = v6;
        if ( v6 == nullptr )
        {
          *_errno_0() = 12;
          return *_errno_0();
        }
        if ( strcpy_s_0(Destination: v6, SizeInBytes: v5, Source) != 0 )
          _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
        if ( a2 != nullptr )
          *a2 = v5;
      }
      return 0;
    }
  }
  *_errno_0() = 22;
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  return 22;
}

//------------------------------------------------------------------------------
// Address: 0x3F64DE49
// Name: sub_3F64DE49
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F64DE49()
{
  return _unlock_0(a1: 7);
}

//------------------------------------------------------------------------------
// Address: 0x3F64DE52
// Name: _getenv_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl getenv_s_0(size_t *RequiredCount, char *Buffer, rsize_t BufferCount, const char *VarName)
{
  char *v5; // eax
  const char *v6; // esi
  rsize_t v7; // eax
  errno_t v9; // [esp+10h] [ebp-1Ch]

  _lock_0(a1: 7);
  if ( RequiredCount != nullptr )
  {
    *RequiredCount = 0;
    if ( Buffer != nullptr ? BufferCount != 0 : BufferCount == 0 )
    {
      if ( Buffer != nullptr )
        *Buffer = 0;
      v5 = getenv_0(VarName);
      v6 = v5;
      if ( v5 != nullptr )
      {
        v7 = strlen_0(Str: v5) + 1;
        *RequiredCount = v7;
        if ( BufferCount != 0 )
        {
          if ( v7 > BufferCount )
          {
            v9 = 34;
            goto LABEL_16;
          }
          if ( strcpy_s_0(Destination: Buffer, SizeInBytes: BufferCount, Source: v6) != 0 )
            _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
        }
      }
      v9 = 0;
      goto LABEL_16;
    }
  }
  *_errno_0() = 22;
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  v9 = 22;
LABEL_16:
  _unlock_0(a1: 7);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x3F64E007
// Name: sub_3F64E007
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F64E007()
{
  return _unlock_0(a1: 7);
}

//------------------------------------------------------------------------------
// Address: 0x3F64FC40
// Name: sub_3F64FC40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F64FC40(unsigned __int8 *Str1, unsigned __int8 *Str2, size_t MaxCount)
{
  return _mbsnbicoll_l_0(Str1, Str2, MaxCount, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F64FCEC
// Name: __statfp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _statfp_0@<eax>(__int16 a1@<fpstat>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F64FD00
// Name: sub_3F64FD00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_3F64FD00@<al>(char a1@<al>)
{
  return a1 & 0x59;
}

//------------------------------------------------------------------------------
// Address: 0x3F64FE38
// Name: nullsub_44
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_44()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F64FE50
// Name: nullsub_45
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_45()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F64FE9B
// Name: int strncnt(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__usercall strncnt@<eax>(_BYTE *a1@<eax>, const char *a2)
{
  int v2; // ecx

  v2 = (int)a2;
  while ( v2 != 0 )
  {
    --v2;
    if ( *a1 == 0 )
      return &a2[-v2 - 1];
    ++a1;
  }
  v2 = -1;
  return &a2[-v2 - 1];
}

//------------------------------------------------------------------------------
// Address: 0x3F65079C
// Name: nullsub_46
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_46()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F650C30
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  int result; // eax
  int v2; // edx
  float v3; // [esp+0h] [ebp-24h]
  int v4; // [esp+18h] [ebp-Ch]

  if ( dword_3F665FB8 != 0 )
    return (int)a1;
  *(float *)&v4 = a1;
  v2 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v2 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v2 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F650CE0
// Name: __aullrem_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _aullrem_0(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  bool v7; // cf
  int v8; // ecx
  unsigned __int64 v9; // rax

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
    v8 = HIDWORD(a2) * (v6 / v5);
    v9 = (unsigned int)a2 * (unsigned __int64)(unsigned int)(v6 / v5);
    v7 = __CFADD__(v8, HIDWORD(v9));
    HIDWORD(v9) += v8;
    if ( v7 || v9 > a1 )
      v9 -= a2;
    return a1 - v9;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 % (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F650D58
// Name: __setjmp3_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _setjmp3_0@<eax>(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        _DWORD *a5,
        int a6,
        struct _EXCEPTION_REGISTRATION_RECORD *a7,
        int a8,
        ...)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  unsigned int v9; // ecx
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, a8);
  *a5 = a2;
  a5[1] = a1;
  a5[2] = a3;
  a5[3] = a4;
  a5[4] = &retaddr;
  a5[5] = retaddr;
  a5[8] = 1447244336;
  a5[9] = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  a5[6] = ExceptionList;
  if ( ExceptionList == (struct _EXCEPTION_REGISTRATION_RECORD *)-1 )
  {
    a5[7] = -1;
  }
  else if ( a6 != 0 && (ExceptionList = a7, a5[9] = a7, a6 != 1) )
  {
    a5[7] = a8;
    v9 = a6 - 2;
    if ( a6 != 2 )
    {
      if ( v9 > 6 )
        v9 = 6;
      qmemcpy(a5 + 10, va, 4 * v9);
    }
  }
  else
  {
    a5[7] = ExceptionList[1].Handler;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F650DE0
// Name: __trandisp1_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp1_0@<eax>(int a1@<edx>, __int16 a2@<cx>, int a3@<ebp>, __int16 a4@<fpstat>, double _ST7@<st0>)
{
  __int16 v5; // bx

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a3 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a3 - 162) = v5;
  _EBX = &unk_3F66342C;
  __asm { fxam }
  *(_DWORD *)(a3 - 148) = a1;
  *(_WORD *)(a3 - 160) = a4;
  *(_BYTE *)(a3 - 144) = 0;
  LOBYTE(a2) = __ROL1__((char)(2 * *(_BYTE *)(a3 - 159)) >> 1, 1);
  _AL = a2 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))(_AL + a1 + 16))(a1: a2 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x3F650EED
// Name: __rtonenpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtonenpop()
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x3F650EF2
// Name: __tosnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan1@<st0>(int a1@<ebp>, double a2@<st0>)
{
  double result; // st7

  *(double *)(a1 - 158) = a2;
  result = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
    return result + dbl_3F663424;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F650F99
// Name: __rttosnpopde_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _rttosnpopde_0(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 144) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F650FA9
// Name: chsifnegret_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void chsifnegret_0()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F650FB0
// Name: __startTwoArgErrorHandling_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _startTwoArgErrorHandling_0@<st0>(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        double a4@<st0>,
        __int16 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  _DWORD v11[6]; // [esp+0h] [ebp-20h] BYREF
  double v12; // [esp+18h] [ebp-8h]

  v11[0] = a1;
  v11[4] = a9;
  v11[5] = a10;
  v12 = a4;
  v11[1] = a3;
  v11[2] = a7;
  v11[3] = a8;
  _87except_0(a1: a2, a2: v11, a3: &a5);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x3F651010
// Name: __twoToTOS_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _twoToTOS_0@<st0>(long double a1@<st0>)
{
  long double v1; // rt0

  v1 = rint(a1);
  return __FSCALE__(__F2XM1__(-(v1 - a1)) + 1.0, v1);
}

//------------------------------------------------------------------------------
// Address: 0x3F65103C
// Name: __convertTOStoQNaN_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _convertTOStoQNaN_0@<st0>(int a1@<eax>, double result@<st0>)
{
  if ( (a1 & 0x80000) == 0 )
    return result + 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F651067
// Name: fpload_special
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __fastcall fpload_special(int a1, _QWORD *a2)
{
  double result; // st7

  *(_QWORD *)&result = *a2 << 11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6510A9
// Name: special_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl special_exp(int a1, int a2)
{
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F6510E5
// Name: __check_overflow_exit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F6511A0
// Name: __CIlog_pentium4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _CIlog_pentium4_0@<eax>(__int64 a1@<st0>)
{
  return start_0(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6511BE
// Name: start_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall start_0@<st0>(__m128d a1@<xmm0>, __m128i a2@<xmm2>, double a3)
{
  int i; // edx
  __m128i v4; // xmm5
  __m128d v5; // xmm0
  int v6; // eax
  __m128d v7; // xmm4
  __m128d v8; // xmm6
  __m128d v9; // xmm0
  __m128d v10; // xmm6
  __m128d v11; // xmm7
  __m128d v12; // xmm4
  unsigned int v13; // ecx
  int v14; // ecx
  __m128d v15; // xmm6
  int v16; // edx
  __m128d v17; // xmm3
  __m128d v18; // xmm7
  __m128d v19; // xmm0
  __m128d v21; // xmm0
  __m128i v22; // xmm1
  int v23; // edx
  double v24; // [esp+10h] [ebp-Ch] BYREF

  for ( i = 0; ; i = -52 )
  {
    v4 = (__m128i)a1;
    v5 = _mm_or_pd(_mm_and_pd(_mm_unpacklo_pd(a1, a1), (__m128d)xmmword_3F65C860), (__m128d)xmmword_3F65C8C0);
    v6 = _mm_extract_epi16((__m128i)_mm_add_pd((__m128d)xmmword_3F65C870, v5), 0) & 0x7F0;
    v7 = *(__m128d *)((char *)&xmmword_3F65C940 + v6);
    v11 = *(__m128d *)((char *)&xmmword_3F65CD50 + v6);
    v8 = _mm_and_pd((__m128d)xmmword_3F65C880, v5);
    v9 = _mm_sub_pd(v5, v8);
    v10 = _mm_sub_pd(_mm_mul_pd(v8, v7), (__m128d)xmmword_3F65C8C0);
    v11.m128d_f64[0] = v11.m128d_f64[0] + v10.m128d_f64[0];
    v12 = _mm_mul_pd(v9, v7);
    a1 = _mm_add_pd(v12, v10);
    v13 = (_mm_extract_epi16(_mm_srli_epi64(v4, 0x34u), 0) & 0xFFF) - 1;
    if ( v13 <= 0x7FD )
      break;
    v21.m128d_f64[0] = a3;
    v22 = (__m128i)_mm_cmpeq_sd((__m128d)xmmword_3F65C8D0, v21);
    if ( _mm_extract_epi16(v22, 0) != 0 )
    {
      *(double *)v22.m128i_i64 = -INFINITY;
      v23 = 2;
CALL_LIBM_ERROR_0:
      v24 = *(double *)v22.m128i_i64;
      __libm_error_support_0(a1: &a3, a2: &a3, a3: &v24, a4: v23);
      return v24;
    }
    if ( v13 != -1 )
    {
      if ( v13 > 0x7FE )
      {
        if ( (((_WORD)v13 + 1) & 0x7FF) == 0x7FF
          && (*(double *)a2.m128i_i64 = a3,
              (_mm_cvtsi128_si32(_mm_srli_epi64(a2, 0x20u)) & 0xFFFFF | _mm_cvtsi128_si32(a2)) != 0) )
        {
          v23 = 1000;
        }
        else
        {
          *(double *)v22.m128i_i64 = 0.0 / 0.0;
          v23 = 3;
        }
      }
      else
      {
        a1.m128d_f64[0] = a3;
        v22.m128i_i64[0] = 0xFFFFFFFFFFFFFLL;
        if ( _mm_extract_epi16(
               (__m128i)_mm_cmpeq_sd(
                          (__m128d)xmmword_3F65C8C0,
                          _mm_or_pd(_mm_and_pd(a1, (__m128d)xmmword_3F65C860), (__m128d)xmmword_3F65C8C0)),
               0) != 0 )
          return INFINITY;
        v23 = 1000;
      }
      goto CALL_LIBM_ERROR_0;
    }
    a1.m128d_f64[0] = a3 * 4.503599627370496e15;
  }
  v14 = i + v13 - 1022;
  v10.m128d_f64[0] = (double)v14;
  v15 = _mm_unpacklo_pd(v10, v10);
  v16 = 0;
  if ( (v14 << 10) + v6 == 0 )
    v16 = 1;
  v17 = _mm_mul_pd(a1, a1);
  v18 = _mm_add_pd(
          _mm_add_pd(v11, _mm_mul_pd(v15, (__m128d)xmmword_3F65C890)),
          _mm_and_pd(v12, (__m128d)xmmword_3F65C8A0[v16]));
  v17.m128d_f64[0] = v17.m128d_f64[0] * v17.m128d_f64[0] * a1.m128d_f64[0];
  v19 = _mm_mul_pd(
          _mm_add_pd(
            _mm_mul_pd(_mm_add_pd(_mm_mul_pd((__m128d)xmmword_3F65C910, a1), (__m128d)xmmword_3F65C920), a1),
            (__m128d)xmmword_3F65C930),
          v17);
  return v19.m128d_f64[0]
       + _mm_unpackhi_pd(v19, v19).m128d_f64[0]
       + _mm_unpackhi_pd(v18, v18).m128d_f64[0]
       + v18.m128d_f64[0];
}

//------------------------------------------------------------------------------
// Address: 0x3F651421
// Name: __fFEXP_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _fFEXP_0@<st0>(__int16 a1@<cx>, int a2@<ebp>, double a3@<st0>)
{
  double v4; // st7
  char v5; // dl
  char v6; // ch
  long double v7; // st6

  *(_BYTE *)(a2 - 144) = -2;
  HIBYTE(a1) = 0;
  v4 = a3 * 1.442695040888963407;
  _ffexpm1_0(a1);
  v7 = 1.442695040888963407 + 1.0;
  if ( (*(_BYTE *)(a2 - 159) & 1) != 0 )
  {
    if ( dword_3F6637E4 == 1 )
      unknown_libname_20(a1: v4);
    else
      v7 = 1.0 / v7;
  }
  if ( (v5 & 0x40) == 0 )
    v7 = __FSCALE__(v7, v4);
  if ( v6 != 0 )
    return -v7;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x3F6514F7
// Name: zerotoxdone_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void zerotoxdone_0()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F651542
// Name: _expbigret_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void expbigret_0()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F651561
// Name: _rtforexpinf_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __fastcall rtforexpinf_0(char a1)
{
  if ( a1 != 0 )
    return 0.0;
  else
    return *(double *)&tbyte_3F663440;
}

//------------------------------------------------------------------------------
// Address: 0x3F65156E
// Name: __ffexpm1_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _ffexpm1_0(char a1@<ch>, int _EBP@<ebp>)
{
  __asm
  {
    fld     st
    fabs
    fld     tbyte_3F66345E
    fcompp
    fstsw   word ptr [ebp-0A0h]
  }
  if ( (*(_BYTE *)(_EBP - 159) & 0x41) != 0 )
  {
    __asm
    {
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    if ( (*(_BYTE *)(_EBP - 159) & 1) != 0 )
    {
      *(_BYTE *)(_EBP - 144) = 4;
      __asm
      {
        fstp    st
        fldz
      }
    }
    else
    {
      __asm
      {
        fstp    st
        fld     tbyte_3F663440
      }
      if ( a1 != 0 )
        __asm { fchs }
      expbigret_0();
    }
  }
  else
  {
    __asm
    {
      fld     st
      frndint
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    __asm
    {
      fxch    st(1)
      fsub    st, st(1)
      ftst
      fstsw   word ptr [ebp-0A0h]
      fabs
      f2xm1
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F6515B1
// Name: _isintTOS_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isintTOS_0@<eax>(long double a1@<st0>)
{
  if ( rint(a1) != a1 )
    return notanint_0();
  if ( rint(a1 * dbl_3F663472) == a1 * dbl_3F663472 )
    return evenint_0();
  return isintTOSret_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F6515D6
// Name: _isintTOSret_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void isintTOSret_0()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F6515D7
// Name: notanint_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void notanint_0()
{
  isintTOSret_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F6515DE
// Name: evenint_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void evenint_0()
{
  isintTOSret_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F6515E5
// Name: _usepowhlp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall usepowhlp_0@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  int v4; // eax
  double result; // st7
  double *v6; // [esp+10h] [ebp-7Ch]
  double v7[15]; // [esp+14h] [ebp-78h] BYREF

  _ESI = v7;
  v6 = v7;
  __asm { fsave   byte ptr [esi+8] }
  v4 = _powhlp_0(a1: a3, a2, a3: (int)v7);
  __asm { frstor  byte ptr [esi+8] }
  result = v7[0];
  if ( v4 != 0 )
    _rttosnpopde_0(a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F651617
// Name: __87except_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _87except_0(int a1, int a2, unsigned __int16 *a3)
{
  int v3; // ecx
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  DWORD v11; // ebx
  int result; // eax
  int v13; // [esp-4h] [ebp-94h]
  int v14; // [esp+Ch] [ebp-84h] BYREF
  ULONG_PTR Arguments[12]; // [esp+10h] [ebp-80h] BYREF
  double v16; // [esp+40h] [ebp-50h]
  unsigned int v17; // [esp+50h] [ebp-40h]

  v3 = *a3;
  v5 = *(_DWORD *)a2 - 1;
  v4 = *(_DWORD *)a2 == 1;
  v14 = v3;
  if ( !v4 )
  {
    v6 = v5 - 1;
    if ( v6 == 0 )
    {
      v13 = 4;
      goto LABEL_14;
    }
    v7 = v6 - 1;
    if ( v7 == 0 )
    {
      v13 = 17;
      goto LABEL_14;
    }
    v8 = v7 - 1;
    if ( v8 == 0 )
    {
      v13 = 18;
      goto LABEL_14;
    }
    v9 = v8 - 1;
    if ( v9 != 0 )
    {
      v10 = v9 - 2;
      if ( v10 == 0 )
      {
        *(_DWORD *)a2 = 1;
        goto LABEL_21;
      }
      if ( v10 == 1 )
      {
        v13 = 16;
        goto LABEL_14;
      }
LABEL_21:
      ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: v14, a2: 0xFFFF);
      if ( *(_DWORD *)a2 == 8 )
        return _set_errno_0(Value: *(_DWORD *)a2);
      if ( dword_3F6636E8 != 0 )
        return _set_errno_0(Value: *(_DWORD *)a2);
      result = sub_3F653163(a1: a2);
      if ( result == 0 )
        return _set_errno_0(Value: *(_DWORD *)a2);
      return result;
    }
  }
  v13 = 8;
LABEL_14:
  v11 = v13;
  if ( _handle_exc_0(a1: v13, a2: a2 + 24, a3: v3) == 0 )
  {
    if ( a1 == 16 || a1 == 22 || a1 == 29 )
    {
      v16 = *(double *)(a2 + 16);
      v17 = v17 & 0xFFFFFFE0 | 3;
    }
    else
    {
      v17 &= ~1u;
    }
    sub_3F652BF5((ULONG_PTR)Arguments, a2: (int)&v14, dwExceptionCode: v11, a4: a1, a5: a2 + 8, a6: a2 + 24);
  }
  goto LABEL_21;
}

//------------------------------------------------------------------------------
// Address: 0x3F65173C
// Name: ___libm_error_support_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __libm_error_support_0(double *a1, double *a2, double *a3, int a4)
{
  int *result; // eax
  double v5; // st7
  double v6; // st7
  double v7; // st7
  int v8; // [esp+Ch] [ebp-28h] BYREF
  const char *v9; // [esp+10h] [ebp-24h]
  double v10; // [esp+14h] [ebp-20h]
  double v11; // [esp+1Ch] [ebp-18h]
  double v12; // [esp+24h] [ebp-10h]
  double v13; // [esp+2Ch] [ebp-8h]

  v13 = 0.0;
  if ( dword_3F665FA8 != 0 )
    result = (int *)_decode_pointer_0(a1: dword_3F665FAC);
  else
    result = (int *)sub_3F653163;
  if ( a4 > 166 )
  {
    switch ( a4 )
    {
      case 1000:
        v9 = "log";
        goto LABEL_37;
      case 1001:
        v9 = "log10";
        goto LABEL_37;
      case 1002:
        v9 = "exp";
        goto LABEL_37;
      case 1003:
        v9 = "atan";
        goto LABEL_37;
      case 1004:
        v9 = "ceil";
        goto LABEL_37;
      case 1005:
        v9 = "floor";
        goto LABEL_37;
      case 1006:
        goto LABEL_38;
      case 1007:
        v9 = "modf";
        goto LABEL_37;
      case 1008:
        goto LABEL_35;
      case 1009:
        goto LABEL_34;
      case 1010:
        v9 = (const char *)&unk_3F65D1D0;
        goto LABEL_53;
      case 1011:
        v9 = (const char *)&unk_3F65D1CC;
        goto LABEL_53;
      case 1012:
        v9 = (const char *)&unk_3F65D1C8;
LABEL_53:
        v6 = *a1 * v13;
        *a3 = v6;
        v10 = *a1;
        v11 = *a2;
        goto LABEL_54;
      default:
        return result;
    }
  }
  if ( a4 == 166 )
  {
    v8 = 3;
    v9 = "exp10";
    goto LABEL_17;
  }
  if ( a4 <= 25 )
  {
    switch ( a4 )
    {
      case 25:
        v9 = "pow";
        goto LABEL_20;
      case 2:
        v8 = 2;
        v9 = "log";
        goto LABEL_17;
      case 3:
        v9 = "log";
        break;
      case 8:
        v8 = 2;
        v9 = "log10";
        goto LABEL_17;
      case 9:
        v9 = "log10";
        break;
      case 14:
        v8 = 3;
        v9 = "exp";
LABEL_17:
        v10 = *a1;
        v11 = *a2;
        v12 = *a3;
        result = (int *)((int (__cdecl *)(int *))result)(a1: &v8);
        if ( result == nullptr )
        {
          result = _errno_0();
          *result = 34;
        }
        goto LABEL_56;
      case 15:
        v9 = "exp";
LABEL_20:
        v10 = *a1;
        v5 = *a2;
        v8 = 4;
        v11 = v5;
        v12 = *a3;
        result = (int *)((int (__cdecl *)(int *))result)(a1: &v8);
LABEL_56:
        v7 = v12;
        goto LABEL_57;
      case 24:
        v8 = 3;
        goto LABEL_16;
      default:
        return result;
    }
LABEL_23:
    v10 = *a1;
    v11 = *a2;
    v6 = *a3;
LABEL_54:
    v12 = v6;
    v8 = 1;
    result = (int *)((int (__cdecl *)(int *))result)(a1: &v8);
    if ( result == nullptr )
    {
      result = _errno_0();
      *result = 33;
    }
    goto LABEL_56;
  }
  if ( a4 != 26 )
  {
    switch ( a4 )
    {
      case 27:
        v8 = 2;
LABEL_16:
        v9 = "pow";
        goto LABEL_17;
      case 28:
LABEL_38:
        v9 = "pow";
        break;
      case 29:
        v9 = "pow";
LABEL_37:
        *a3 = *a1;
        break;
      case 58:
LABEL_35:
        v9 = "acos";
        break;
      case 61:
LABEL_34:
        v9 = "asin";
        break;
      default:
        return result;
    }
    goto LABEL_23;
  }
  v7 = 1.0;
LABEL_57:
  *a3 = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6519EC
// Name: __d_inttype_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _d_inttype_0(double X)
{
  if ( (_fpclass_0(X) & 0x90) != 0 )
    return 0;
  _frnd(a1: X);
  _frnd(a1: X * 0.5);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x3F651A50
// Name: __powhlp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _powhlp_0(double a1, double a2, double *a3)
{
  double v3; // st7
  int v4; // esi
  double v5; // st6
  double *v6; // eax
  int v7; // eax

  v3 = 0.0;
  v4 = 0;
  v5 = a1;
  if ( a1 < 0.0 )
    v5 = -a1;
  if ( HIDWORD(a2) == 2146435072 )
  {
    if ( LODWORD(a2) == 0 )
    {
      if ( v5 <= 1.0 )
      {
        v6 = a3;
        if ( v5 >= 1.0 )
          v3 = 1.0;
        goto LABEL_28;
      }
      goto LABEL_6;
    }
  }
  else if ( a2 == -INFINITY )
  {
    if ( v5 > 1.0 )
      goto LABEL_27;
    v6 = a3;
    if ( v5 < 1.0 )
    {
      v3 = dbl_3F6636F0;
LABEL_28:
      *v6 = v3;
      return v4;
    }
    *a3 = dbl_3F6636F8;
    return 1;
  }
  if ( HIDWORD(a1) == 2146435072 )
  {
    if ( LODWORD(a1) == 0 )
    {
      if ( a2 <= 0.0 )
      {
        v6 = a3;
        if ( a2 >= 0.0 )
          v3 = 1.0;
        goto LABEL_28;
      }
LABEL_6:
      v3 = dbl_3F6636F0;
LABEL_27:
      v6 = a3;
      goto LABEL_28;
    }
  }
  else if ( a1 == -INFINITY )
  {
    v7 = _d_inttype_0(X: a2);
    v3 = 0.0;
    if ( a2 <= 0.0 )
    {
      if ( a2 >= 0.0 )
      {
        v3 = 1.0;
      }
      else if ( v7 == 1 )
      {
        v3 = dbl_3F663710;
      }
    }
    else
    {
      v3 = dbl_3F6636F0;
      if ( v7 == 1 )
        v3 = -dbl_3F6636F0;
    }
    goto LABEL_27;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x3F651B90
// Name: unknown_libname_7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
double __cdecl unknown_libname_7(_TBYTE a1, _TBYTE a2)
{
  double v2; // st7
  double v3; // st6
  unsigned int v4; // eax

  v2 = *(double *)&a2;
  v3 = *(double *)&a1;
  while ( !__CFADD__(DWORD1(a1), DWORD1(a1)) )
  {
    if ( *(_QWORD *)&a1 == 0 || (HIWORD(a1) & 0x7FFF) != 0 )
      return v2 / v3;
    if ( (HIWORD(a2) & 0x7FFF) != 0 )
    {
      if ( (HIWORD(a2) & 0x7FFF) == 0x7FFF || !__CFADD__(DWORD1(a2), DWORD1(a2)) )
        return v2 / v3;
    }
    else if ( __CFADD__(DWORD1(a2), DWORD1(a2)) )
    {
      return v2 / v3;
    }
    *(double *)&a1 = v3 * flt_3F6634B8;
    v2 = *(double *)&a2;
  }
  v4 = (2 * DWORD1(a1)) ^ 0xE000000;
  if ( (v4 & 0xE000000) != 0 )
    return v2 / v3;
  if ( byte_3F6634A0[v4 >> 28] == 0 )
    return v2 / v3;
  if ( (HIWORD(a1) & 0x7FFF) == 0 || (HIWORD(a1) & 0x7FFF) == 0x7FFF )
    return v2 / v3;
  if ( (HIWORD(a2) & 0x7FFF) == 1 )
    return v2 * flt_3F6634B4 / (v3 * flt_3F6634B4);
  else
    return v2 * flt_3F6634B0 / (v3 * flt_3F6634B0);
}

//------------------------------------------------------------------------------
// Address: 0x3F651CA7
// Name: unknown_libname_8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
// positive sp value has been detected, the output may be wrong!
void __usercall unknown_libname_8(char a1@<al>)
{
  _TBYTE v1; // [esp-2Ch] [ebp-58h]
  _TBYTE v2; // [esp-20h] [ebp-4Ch]
  _TBYTE v17; // [esp+0h] [ebp-2Ch]
  _TBYTE v18; // [esp+Ch] [ebp-20h]

  switch ( a1 & 0x3F )
  {
    case 0:
      __asm { fdiv    st, st; jumptable 3F651CAD case 0 }
      return;
    case 1:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_4;
    case 2:
LABEL_4:
      __asm { fdivr   st, st; jumptable 3F651CAD case 2 }
      return;
    case 3:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_6;
    case 4:
LABEL_6:
      __asm { fdiv    st, st; jumptable 3F651CAD case 4 }
      return;
    case 5:
      __asm { fdivp   st, st; jumptable 3F651CAD case 5 }
      return;
    case 6:
      __asm { fdivr   st, st; jumptable 3F651CAD case 6 }
      return;
    case 7:
      __asm { fdivrp  st, st; jumptable 3F651CAD case 7 }
      return;
    case 8:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 8
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fld     [esp+2Ch+var_C]
        fxch    st(1)
      }
      return;
    case 9:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_12;
    case 0xA:
LABEL_12:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 3F651CAD case 10
        fstp    [esp+arg_8]; _TBYTE
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fld     [esp+arg_8]
        fxch    st(1)
      }
      return;
    case 0xB:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_14;
    case 0xC:
LABEL_14:
      __asm
      {
        fxch    st(1); jumptable 3F651CAD case 12
        fstp    [esp+arg_8]; _TBYTE
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm { fld     [esp+arg_1C] }
      return;
    case 0xD:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 3F651CAD case 13
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      return;
    case 0xE:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 14
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fld     [esp+2Ch+var_20] }
      return;
    case 0xF:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 15
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      return;
    case 0x10:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 16
        fxch    st(1)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_C]
        fxch    st(2)
      }
      return;
    case 0x11:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_20;
    case 0x12:
LABEL_20:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 3F651CAD case 18
        fxch    st(1)
        fstp    [esp+arg_8]; _TBYTE
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_8]
        fxch    st(2)
      }
      return;
    case 0x13:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_22;
    case 0x14:
LABEL_22:
      __asm
      {
        fxch    st(2); jumptable 3F651CAD case 20
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(1)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_1C]
      }
      return;
    case 0x15:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 3F651CAD case 21
        fxch    st(1)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(1) }
      return;
    case 0x16:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 22
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x17:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 23
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(1) }
      return;
    case 0x18:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 24
        fxch    st(2)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_C]
        fxch    st(3)
      }
      return;
    case 0x19:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_28;
    case 0x1A:
LABEL_28:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 3F651CAD case 26
        fxch    st(2)
        fstp    [esp+arg_8]; _TBYTE
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_8]
        fxch    st(3)
      }
      return;
    case 0x1B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_30;
    case 0x1C:
LABEL_30:
      __asm
      {
        fxch    st(3); jumptable 3F651CAD case 28
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(2)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_1C]
      }
      return;
    case 0x1D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 3F651CAD case 29
        fxch    st(2)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(2) }
      return;
    case 0x1E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 30
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x1F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 31
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(2) }
      return;
    case 0x20:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 32
        fxch    st(3)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_C]
        fxch    st(4)
      }
      return;
    case 0x21:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_36;
    case 0x22:
LABEL_36:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 3F651CAD case 34
        fxch    st(3)
        fstp    [esp+arg_8]; _TBYTE
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_8]
        fxch    st(4)
      }
      return;
    case 0x23:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_38;
    case 0x24:
LABEL_38:
      __asm
      {
        fxch    st(4); jumptable 3F651CAD case 36
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(3)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_1C]
      }
      return;
    case 0x25:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 3F651CAD case 37
        fxch    st(3)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(3) }
      return;
    case 0x26:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 38
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x27:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 39
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(3) }
      return;
    case 0x28:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 40
        fxch    st(4)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_C]
        fxch    st(5)
      }
      return;
    case 0x29:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_44;
    case 0x2A:
LABEL_44:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 3F651CAD case 42
        fxch    st(4)
        fstp    [esp+arg_8]; _TBYTE
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_8]
        fxch    st(5)
      }
      return;
    case 0x2B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_46;
    case 0x2C:
LABEL_46:
      __asm
      {
        fxch    st(5); jumptable 3F651CAD case 44
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(4)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_1C]
      }
      return;
    case 0x2D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 3F651CAD case 45
        fxch    st(4)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(4) }
      return;
    case 0x2E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 46
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x2F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 47
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(4) }
      return;
    case 0x30:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 48
        fxch    st(5)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_C]
        fxch    st(6)
      }
      return;
    case 0x31:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_52;
    case 0x32:
LABEL_52:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 3F651CAD case 50
        fxch    st(5)
        fstp    [esp+arg_8]; _TBYTE
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_8]
        fxch    st(6)
      }
      return;
    case 0x33:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_54;
    case 0x34:
LABEL_54:
      __asm
      {
        fxch    st(6); jumptable 3F651CAD case 52
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(5)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_1C]
      }
      return;
    case 0x35:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 3F651CAD case 53
        fxch    st(5)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(5) }
      return;
    case 0x36:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 54
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x37:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 55
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(5) }
      return;
    case 0x38:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 56
        fxch    st(6)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_C]
        fxch    st(7)
      }
      return;
    case 0x39:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_60;
    case 0x3A:
LABEL_60:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 3F651CAD case 58
        fxch    st(6)
        fstp    [esp+arg_8]; _TBYTE
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_8]
        fxch    st(7)
      }
      return;
    case 0x3B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto LABEL_62;
    case 0x3C:
LABEL_62:
      __asm
      {
        fxch    st(7); jumptable 3F651CAD case 60
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(6)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      unknown_libname_7(a1: v17, a2: v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_1C]
      }
      break;
    case 0x3D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 3F651CAD case 61
        fxch    st(6)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(6) }
      break;
    case 0x3E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 62
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_20]
      }
      break;
    case 0x3F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 3F651CAD case 63
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      unknown_libname_7(a1: v1, a2: v2);
      __asm { fxch    st(6) }
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F652146
// Name: unknown_libname_9
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void __usercall unknown_libname_9(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-2Ch]
  _TBYTE v3; // [esp+Ch] [ebp-20h]

  *(double *)&v2 = a1;
  *(double *)&v3 = a2;
  unknown_libname_7(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x3F652159
// Name: unknown_libname_10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void __usercall unknown_libname_10(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-2Ch]
  _TBYTE v3; // [esp+Ch] [ebp-20h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  unknown_libname_7(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x3F65236C
// Name: unknown_libname_19
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void __usercall __spoils<edx,ecx,st0> unknown_libname_19(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v2 = a1;
  *(double *)&v3 = a2;
  unknown_libname_7(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x3F652381
// Name: unknown_libname_20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void __usercall __spoils<edx,ecx,st0> unknown_libname_20(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  unknown_libname_7(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x3F652396
// Name: unknown_libname_21
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
unsigned int __usercall unknown_libname_21@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  int v6; // ecx
  double v7; // st7
  __int16 v8; // fps
  double v9; // st6
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( byte_3F6634BC[result] != 0 )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( 2 * DWORD1(a5) == 0 )
          {
            result = 2 * DWORD1(a2);
            if ( 2 * DWORD1(a2) == 0 )
            {
              if ( (WORD4(a5) & 0x7FFFu) > (WORD4(a2) & 0x7FFFu) + 63 )
              {
                v6 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v7 = fabs(*(long double *)&a2);
                v9 = fabs(*(long double *)&a5);
                do
                {
                  v10 = v9 < v7;
                  v11 = 0;
                  v12 = v9 == v7;
                  result = v8 & 0x100;
                  if ( (v8 & 0x100) == 0 )
                    v9 = v9 - v7;
                  v7 = v7 * dbl_3F6634EC;
                  --v6;
                }
                while ( v6 != 0 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
    return v13 & 0x4300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F65259C
// Name: unknown_libname_22
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
int __usercall __spoils<ecx,st0> unknown_libname_22@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return unknown_libname_21(a1: 0, a2: *(__int128 *)v4, a3: *(int *)&v4[16], a4: v5, a5: v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * dbl_3F6634D4;
    }
    *(double *)v4 = a2 * dbl_3F6634D4;
    return unknown_libname_21(a1: v3, a2: *(__int128 *)v4, a3: HIDWORD(*(unsigned __int64 *)&a2), a4: v5, a5: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F65264E
// Name: unknown_libname_23
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
unsigned int __usercall unknown_libname_23@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  int v6; // ecx
  double v7; // st7
  __int16 v8; // fps
  double v9; // st6
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( byte_3F6634BC[result] != 0 )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( 2 * DWORD1(a5) == 0 )
          {
            result = 2 * DWORD1(a2);
            if ( 2 * DWORD1(a2) == 0 )
            {
              if ( (WORD4(a5) & 0x7FFFu) > (WORD4(a2) & 0x7FFFu) + 63 )
              {
                v6 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v7 = fabs(*(long double *)&a2);
                v9 = fabs(*(long double *)&a5);
                do
                {
                  v10 = v9 < v7;
                  v11 = 0;
                  v12 = v9 == v7;
                  result = v8 & 0x100;
                  if ( (v8 & 0x100) == 0 )
                    v9 = v9 - v7;
                  v7 = v7 * dbl_3F6634EC;
                  --v6;
                }
                while ( v6 != 0 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
    return v13 & 0x4300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F652854
// Name: unknown_libname_24
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
int __usercall __spoils<ecx,st0> unknown_libname_24@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return unknown_libname_23(a1: 0, a2: *(__int128 *)v4, a3: *(int *)&v4[16], a4: v5, a5: v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * dbl_3F6634D4;
    }
    *(double *)v4 = a2 * dbl_3F6634D4;
    return unknown_libname_23(a1: v3, a2: *(__int128 *)v4, a3: HIDWORD(*(unsigned __int64 *)&a2), a4: v5, a5: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F65291B
// Name: __raise_exc_ex_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _raise_exc_ex_0@<eax>(
        __int16 a1@<fpstat>,
        ULONG_PTR Arguments,
        unsigned int *a3,
        DWORD dwExceptionCode,
        int a5,
        float *a6,
        float *a7,
        int a8)
{
  char v8; // cl
  unsigned int *v9; // esi
  char v10; // al
  int v11; // eax
  unsigned int *v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  unsigned int *v15; // eax
  unsigned int v16; // ecx
  float *v17; // edi
  ULONG_PTR v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  unsigned int v22; // eax
  int v23; // eax
  int v24; // eax
  unsigned int result; // eax

  v8 = dwExceptionCode;
  *(_DWORD *)(Arguments + 4) = 0;
  *(_DWORD *)(Arguments + 8) = 0;
  *(_DWORD *)(Arguments + 12) = 0;
  if ( (v8 & 0x10) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 1u;
    dwExceptionCode = -1073741681;
  }
  if ( (v8 & 2) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 2u;
    dwExceptionCode = -1073741677;
  }
  if ( (v8 & 1) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 4u;
    dwExceptionCode = -1073741679;
  }
  if ( (v8 & 4) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 8u;
    dwExceptionCode = -1073741682;
  }
  if ( (v8 & 8) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 0x10u;
    dwExceptionCode = -1073741680;
  }
  v9 = a3;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(16 * *a3)) & 0x10;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(2 * *v9)) & 8;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v9 >> 1)) & 4;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v9 >> 3)) & 2;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v9 >> 5)) & 1;
  v10 = _statfp_0(a1);
  if ( (v10 & 1) != 0 )
    *(_DWORD *)(Arguments + 12) |= 0x10u;
  if ( (v10 & 4) != 0 )
    *(_DWORD *)(Arguments + 12) |= 8u;
  if ( (v10 & 8) != 0 )
    *(_DWORD *)(Arguments + 12) |= 4u;
  if ( (v10 & 0x10) != 0 )
    *(_DWORD *)(Arguments + 12) |= 2u;
  if ( (v10 & 0x20) != 0 )
    *(_DWORD *)(Arguments + 12) |= 1u;
  v11 = *v9 & 0xC00;
  switch ( v11 )
  {
    case 0:
      *(_DWORD *)Arguments &= 0xFFFFFFFC;
      break;
    case 1024:
      v12 = (unsigned int *)Arguments;
      v13 = *(_DWORD *)Arguments & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v12 = (unsigned int *)Arguments;
      v13 = *(_DWORD *)Arguments & 0xFFFFFFFC | 2;
LABEL_27:
      *v12 = v13;
      break;
    case 3072:
      *(_DWORD *)Arguments |= 3u;
      break;
    default:
      break;
  }
  v14 = *v9 & 0x300;
  switch ( v14 )
  {
    case 0:
      v15 = (unsigned int *)Arguments;
      v16 = *(_DWORD *)Arguments & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v15 = (unsigned int *)Arguments;
      v16 = *(_DWORD *)Arguments & 0xFFFFFFE3 | 4;
LABEL_36:
      *v15 = v16;
      break;
    case 768:
      *(_DWORD *)Arguments &= 0xFFFFFFE3;
      break;
    default:
      break;
  }
  *(_DWORD *)Arguments ^= (*(_DWORD *)Arguments ^ (32 * a5)) & 0x1FFE0;
  *(_DWORD *)(Arguments + 32) |= 1u;
  v17 = a7;
  if ( a8 != 0 )
  {
    *(_DWORD *)(Arguments + 32) &= 0xFFFFFFE1;
    *(float *)(Arguments + 16) = *a6;
    *(_DWORD *)(Arguments + 96) |= 1u;
    *(_DWORD *)(Arguments + 96) &= 0xFFFFFFE1;
    *(float *)(Arguments + 80) = *v17;
  }
  else
  {
    *(_DWORD *)(Arguments + 32) = *(_DWORD *)(Arguments + 32) & 0xFFFFFFE1 | 2;
    *(double *)(Arguments + 16) = *(double *)a6;
    *(_DWORD *)(Arguments + 96) |= 1u;
    *(_DWORD *)(Arguments + 96) = *(_DWORD *)(Arguments + 96) & 0xFFFFFFE1 | 2;
    *(double *)(Arguments + 80) = *(double *)v17;
  }
  ((void (*)(void))_clrfp_0)();
  RaiseException(dwExceptionCode, dwExceptionFlags: 0, nNumberOfArguments: 1u, lpArguments: &Arguments);
  v18 = Arguments;
  if ( (*(_BYTE *)(Arguments + 8) & 0x10) != 0 )
    *v9 &= ~1u;
  if ( (*(_BYTE *)(v18 + 8) & 8) != 0 )
    *v9 &= ~4u;
  if ( (*(_BYTE *)(v18 + 8) & 4) != 0 )
    *v9 &= ~8u;
  if ( (*(_BYTE *)(v18 + 8) & 2) != 0 )
    *v9 &= ~0x10u;
  if ( (*(_BYTE *)(v18 + 8) & 1) != 0 )
    *v9 &= ~0x20u;
  v19 = *(_DWORD *)v18 & 3;
  if ( v19 == 0 )
  {
    *v9 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v20 = v19 - 1;
  if ( v20 == 0 )
  {
    v22 = *v9 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v21 = v20 - 1;
  if ( v21 == 0 )
  {
    v22 = *v9 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v9 = v22;
    goto LABEL_59;
  }
  if ( v21 == 1 )
    *v9 |= 0xC00u;
LABEL_59:
  v23 = (*(_DWORD *)v18 >> 2) & 7;
  if ( v23 == 0 )
  {
    result = *v9 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v24 = v23 - 1;
  if ( v24 == 0 )
  {
    result = *v9 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v9 = result;
    goto LABEL_66;
  }
  result = v24 - 1;
  if ( result == 0 )
    *v9 &= 0xFFFFF3FF;
LABEL_66:
  if ( a8 != 0 )
    *v17 = *(float *)(v18 + 80);
  else
    *(double *)v17 = *(double *)(v18 + 80);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F652BF5
// Name: sub_3F652BF5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall sub_3F652BF5@<eax>(
        __int16 a1@<fpstat>,
        ULONG_PTR Arguments,
        unsigned int *a3,
        DWORD dwExceptionCode,
        int a5,
        float *a6,
        float *a7)
{
  return _raise_exc_ex_0(a1, Arguments, a3, dwExceptionCode, a5, a6, a7, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F652C16
// Name: __raise_excf_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _raise_excf_0@<eax>(
        __int16 a1@<fpstat>,
        ULONG_PTR Arguments,
        unsigned int *a3,
        DWORD dwExceptionCode,
        int a5,
        float *a6,
        float *a7)
{
  return _raise_exc_ex_0(a1, Arguments, a3, dwExceptionCode, a5, a6, a7, a8: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F652C37
// Name: __handle_exc_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _handle_exc_0(char a1, double *a2, __int16 a3)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  double v6; // st7
  BOOL v7; // esi
  double v8; // st7
  int v9; // ecx
  double v10; // st7
  int v11; // eax
  double v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+20h] [ebp-8h] BYREF
  int v15; // [esp+24h] [ebp-4h]

  v3 = a1 & 0x1F;
  v15 = v3;
  if ( (a1 & 8) != 0 && (a3 & 1) != 0 )
  {
    ((void (__cdecl *)(int))_set_statfp_0)(a1: 1);
    v3 = a1 & 0x17;
    goto LABEL_46;
  }
  if ( (a1 & 4) != 0 && (a3 & 4) != 0 )
  {
    ((void (__cdecl *)(int))_set_statfp_0)(a1: 4);
    v3 = a1 & 0x1B;
    goto LABEL_46;
  }
  if ( (a1 & 1) != 0 && (a3 & 8) != 0 )
  {
    ((void (__cdecl *)(int))_set_statfp_0)(a1: 8);
    v4 = a3 & 0xC00;
    if ( (a3 & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = a1 & 0x1E;
            goto LABEL_46;
          }
          v5 = a2;
          v6 = dbl_3F663700;
          if ( *a2 <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = v6;
          goto LABEL_24;
        }
        v5 = a2;
        if ( *a2 <= 0.0 )
        {
          v6 = dbl_3F663700;
LABEL_22:
          v6 = -v6;
          goto LABEL_23;
        }
LABEL_20:
        v6 = dbl_3F6636F0;
        goto LABEL_23;
      }
      v5 = a2;
      if ( *a2 > 0.0 )
      {
        v6 = dbl_3F663700;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = a2;
      if ( *a2 > 0.0 )
        goto LABEL_20;
    }
    v6 = dbl_3F6636F0;
    goto LABEL_22;
  }
  if ( (a1 & 2) != 0 && (a3 & 0x10) != 0 )
  {
    v7 = (a1 & 0x10) != 0;
    if ( 0.0 == *a2 )
    {
      v7 = true;
      goto LABEL_43;
    }
    v8 = *a2;
    _decomp_0(a1: v8, a2: (int)&v14);
    v13 = v8;
    v9 = v14 - 1536;
    if ( v14 - 1536 >= -1074 )
    {
      HIWORD(v13) = BYTE6(v13) & 0xF | 0x10;
      if ( v9 < -1021 )
      {
        v11 = -1021 - v9;
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
      if ( v8 >= 0.0 )
        goto LABEL_41;
      v10 = -v13;
    }
    else
    {
      v7 = true;
      v10 = v8 * 0.0;
    }
    v13 = v10;
LABEL_41:
    *a2 = v13;
LABEL_43:
    if ( v7 )
      ((void (__cdecl *)(int))_set_statfp_0)(a1: 16);
    v15 &= ~2u;
    v3 = v15;
  }
LABEL_46:
  if ( (a1 & 0x10) != 0 && (a3 & 0x20) != 0 )
  {
    ((void (__cdecl *)(int))_set_statfp_0)(a1: 32);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F652E18
// Name: __set_errno_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _set_errno_0(int Value)
{
  errno_t result; // eax

  result = Value;
  if ( Value == 1 )
  {
    result = (errno_t)_errno_0();
    *(_DWORD *)result = 33;
  }
  else if ( Value > 1 && Value <= 3 )
  {
    result = (errno_t)_errno_0();
    *(_DWORD *)result = 34;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F652E60
// Name: __errcode_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _errcode_0(char a1)
{
  if ( (a1 & 0x20) != 0 )
    return 5;
  if ( (a1 & 8) != 0 )
    return 1;
  if ( (a1 & 4) != 0 )
    return 2;
  if ( (a1 & 1) != 0 )
    return 3;
  return 2 * (a1 & 2);
}

//------------------------------------------------------------------------------
// Address: 0x3F652E8D
// Name: __umatherr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _umatherr_0@<st0>(int a1@<esi>, int Value, int a3, int a4, int a5, int a6, int a7, double a8, int a9)
{
  int v9; // eax
  char *v10; // eax
  int v12; // [esp+0h] [ebp-20h] BYREF
  char *v13; // [esp+4h] [ebp-1Ch]
  double v14; // [esp+18h] [ebp-8h]

  v9 = 0;
  while ( dword_3F663600[2 * v9] != a3 )
  {
    if ( ++v9 >= 29 )
    {
      v10 = nullptr;
      goto LABEL_5;
    }
  }
  v10 = (&off_3F663604)[2 * v9];
LABEL_5:
  v13 = v10;
  if ( v10 != nullptr )
  {
    v14 = a8;
    ((void (__cdecl *)(int, int, int, int, char *, int, int, int, int))_ctrlfp_0)(
      a1: a9,
      a2: 0xFFFF,
      a3: a1,
      a4: Value,
      a5: v13,
      a6: a4,
      a7: a5,
      a8: a6,
      a9: a7);
    if ( sub_3F653163(a1: &v12) == 0 )
      _set_errno_0(Value);
    return v14;
  }
  else
  {
    ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: a9, a2: 0xFFFF);
    _set_errno_0(Value);
    return a8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F652F2B
// Name: __handle_qnan1_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _handle_qnan1_0@<st0>(int a1@<esi>, int a2, double a3, int a4)
{
  if ( dword_3F6636E8 == 0 )
    return _umatherr_0(
             a1,
             Value: 1,
             a3: a2,
             a4: SLODWORD(a3),
             a5: SHIDWORD(a3),
             a6: COERCE_UNSIGNED_INT64(0.0),
             a7: HIDWORD(COERCE_UNSIGNED_INT64(0.0)),
             a8: a3,
             a9: a4);
  *_errno_0() = 33;
  ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: a4, a2: 0xFFFF);
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x3F652F7E
// Name: __handle_qnan2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _handle_qnan2_0@<st0>(int a1@<esi>, int a2, double a3, double a4, int a5)
{
  double v6; // [esp+1Ch] [ebp-8h]

  v6 = a3 + a4;
  if ( dword_3F6636E8 == 0 )
    return _umatherr_0(
             a1,
             Value: 1,
             a3: a2,
             a4: SLODWORD(a3),
             a5: SHIDWORD(a3),
             a6: SLODWORD(a4),
             a7: SHIDWORD(a4),
             a8: v6,
             a9: a5);
  *_errno_0() = 33;
  ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: a5, a2: 0xFFFF);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F652FDD
// Name: __except1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _except1@<st0>(int a1@<esi>, DWORD dwExceptionCode, int a3, int a4, int a5, double a6, int a7)
{
  __int16 v7; // fps
  int v8; // eax
  ULONG_PTR Arguments[16]; // [esp+1Ch] [ebp-80h] BYREF
  int v11; // [esp+5Ch] [ebp-40h]

  if ( !_handle_exc_0(a1: dwExceptionCode, a2: &a6, a3: a7) )
  {
    v11 &= ~1u;
    _raise_exc_ex_0(
      a1: v7,
      (ULONG_PTR)Arguments,
      a3: (unsigned int *)&a7,
      dwExceptionCode,
      a5: a3,
      a6: (float *)&a4,
      a7: (float *)&a6,
      a8: 0);
  }
  v8 = _errcode_0(a1: dwExceptionCode);
  if ( dword_3F6636E8 == 0 && v8 != 0 )
    return _umatherr_0(
             a1,
             Value: v8,
             a3,
             a4,
             a5,
             a6: COERCE_UNSIGNED_INT64(0.0),
             a7: HIDWORD(COERCE_UNSIGNED_INT64(0.0)),
             a8: a6,
             a9: a7);
  _set_errno_0(Value: v8);
  ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: a7, a2: 0xFFFF);
  return a6;
}

//------------------------------------------------------------------------------
// Address: 0x3F653097
// Name: __except2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _except2_0@<st0>(
        int a1@<esi>,
        DWORD dwExceptionCode,
        int a3,
        int a4,
        int a5,
        double a6,
        double a7,
        int a8)
{
  __int16 v8; // fps
  int v9; // eax
  ULONG_PTR Arguments[12]; // [esp+1Ch] [ebp-80h] BYREF
  double v12; // [esp+4Ch] [ebp-50h]
  unsigned int v13; // [esp+5Ch] [ebp-40h]

  if ( !_handle_exc_0(a1: dwExceptionCode, a2: &a7, a3: a8) )
  {
    v12 = a6;
    v13 = v13 & 0xFFFFFFE0 | 3;
    _raise_exc_ex_0(
      a1: v8,
      (ULONG_PTR)Arguments,
      a3: (unsigned int *)&a8,
      dwExceptionCode,
      a5: a3,
      a6: (float *)&a4,
      (float *)&a7,
      a8: 0);
  }
  v9 = _errcode_0(a1: dwExceptionCode);
  if ( dword_3F6636E8 == 0 && v9 != 0 )
    return _umatherr_0(a1, Value: v9, a3, a4, a5, a6: SLODWORD(a6), a7: SHIDWORD(a6), a8: a7, a9: a8);
  _set_errno_0(Value: v9);
  ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: a8, a2: 0xFFFF);
  return a7;
}

//------------------------------------------------------------------------------
// Address: 0x3F653163
// Name: sub_3F653163
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F653163()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F653166
// Name: __frnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _frnd(long double a1)
{
  return rint(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F653177
// Name: __copysign_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _copysign_0(double Number, double Sign)
{
  double v3; // [esp+0h] [ebp-8h]

  LODWORD(v3) = LODWORD(Number);
  HIDWORD(v3) = HIDWORD(Sign) ^ (HIDWORD(Number) ^ HIDWORD(Sign)) & 0x7FFFFFFF;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F65319D
// Name: __chgsign_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _chgsign_0(double X)
{
  double v2; // [esp+0h] [ebp-8h]

  LODWORD(v2) = LODWORD(X);
  HIDWORD(v2) = ~HIDWORD(X) ^ (HIDWORD(X) ^ ~HIDWORD(X)) & 0x7FFFFFFF;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F6531C8
// Name: __scalb_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _scalb_0(double X, int Y)
{
  return ldexp_0(X, Y);
}

//------------------------------------------------------------------------------
// Address: 0x3F6531DE
// Name: __logb_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _logb_0(double X)
{
  int v1; // edi
  int v2; // eax
  int v4; // [esp+1Ch] [ebp-4h] BYREF

  v1 = ((int (__cdecl *)(int, int))_ctrlfp_0)(a1: 4927, a2: 0xFFFF);
  if ( (HIWORD(X) & 0x7FF0) != 0x7FF0 )
  {
    if ( X == 0.0 )
      return _except1(
               a1: 0xFFFF,
               dwExceptionCode: 4u,
               a3: 37,
               a4: SLODWORD(X),
               a5: SHIDWORD(X),
               a6: -dbl_3F6636F0,
               a7: v1);
    _decomp_0(a1: X, a2: (int)&v4);
    X = (double)(v4 - 1);
    ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: v1, a2: 0xFFFF);
    return X;
  }
  v2 = _sptype_0(a1: LODWORD(X), a2: HIDWORD(X));
  if ( v2 > 0 )
  {
    if ( v2 > 2 )
    {
      if ( v2 == 3 )
        return _handle_qnan1_0(a1: 0xFFFF, a2: 37, a3: X, a4: v1);
      return _except1(a1: 0xFFFF, dwExceptionCode: 8u, a3: 37, a4: SLODWORD(X), a5: SHIDWORD(X), a6: X + 1.0, a7: v1);
    }
    ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: v1, a2: 0xFFFF);
    return X;
  }
  return _except1(a1: 0xFFFF, dwExceptionCode: 8u, a3: 37, a4: SLODWORD(X), a5: SHIDWORD(X), a6: X + 1.0, a7: v1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6532C1
// Name: __nextafter_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _nextafter_0(double X, double Y)
{
  int v2; // esi
  double v4; // st6
  double v5; // st5
  double v6; // rt2
  double v7; // st5
  double v8; // st6
  double v9; // rtt
  double v10; // rt0
  double v11; // st5
  double v12; // st6
  int v13; // edi
  int v14; // eax
  double v15; // rt1
  double v16; // rt2
  double v17; // st5
  double v18; // st6
  double v19; // rtt
  double v20; // st7
  double v21; // st7
  int v22[2]; // [esp+28h] [ebp-Ch] BYREF
  int v23; // [esp+30h] [ebp-4h]

  *(double *)v22 = 0.0;
  v2 = 0xFFFF;
  v23 = ((int (__cdecl *)(int))_ctrlfp_0)(a1: 4927);
  if ( (HIWORD(X) & 0x7FF0) == 0x7FF0 || (HIWORD(Y) & 0x7FF0) == 0x7FF0 )
  {
    if ( (HIWORD(X) & 0x7FF8) == 0x7FF0 && ((HIDWORD(X) & 0x7FFFF) != 0 || LODWORD(X) != 0) )
      return _except2_0(
               a1: v2,
               dwExceptionCode: 8u,
               a3: 38,
               a4: SLODWORD(X),
               a5: SHIDWORD(X),
               a6: Y,
               a7: X + Y,
               a8: v23);
    v2 = HIWORD(Y) & 0x7FF8;
    if ( (HIWORD(Y) & 0x7FF8) == 0x7FF0 && ((HIDWORD(Y) & 0x7FFFF) != 0 || LODWORD(Y) != 0) )
      return _except2_0(
               a1: v2,
               dwExceptionCode: 8u,
               a3: 38,
               a4: SLODWORD(X),
               a5: SHIDWORD(X),
               a6: Y,
               a7: X + Y,
               a8: v23);
    if ( (HIWORD(X) & 0x7FF8) == 0x7FF8 || (_WORD)v2 == 32760 )
      return _handle_qnan2_0(a1: v2, a2: 38, a3: X, a4: Y, a5: v23);
  }
  v4 = Y;
  if ( Y == X )
  {
    ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: v23, a2: 0xFFFF);
    return X;
  }
  v5 = 0.0;
  if ( 0.0 == X )
  {
    v22[0] = 1;
    if ( Y <= X )
      v22[1] = 0x80000000;
    else
      v22[1] = 0;
    v5 = 0.0;
    v4 = Y;
  }
  if ( v5 < X )
  {
    v6 = v5;
    v7 = v4;
    v8 = v6;
    if ( v7 < X )
      goto LABEL_24;
    v9 = v7;
    v5 = v8;
    v4 = v9;
  }
  if ( v5 <= X )
  {
LABEL_28:
    if ( v5 < X )
    {
      v16 = v5;
      v17 = v4;
      v18 = v16;
      if ( v17 > X )
      {
LABEL_33:
        v13 = LODWORD(X) + 1;
        v22[0] = LODWORD(X) + 1;
        v22[1] = HIDWORD(X);
        if ( LODWORD(X) != -1 )
          goto LABEL_36;
        v14 = HIDWORD(X) + 1;
        goto LABEL_26;
      }
      v19 = v17;
      v5 = v18;
      v4 = v19;
    }
    if ( v5 <= X || v4 >= X )
    {
      v13 = v22[0];
      goto LABEL_36;
    }
    goto LABEL_33;
  }
  v10 = v5;
  v11 = v4;
  v12 = v10;
  if ( v11 <= X )
  {
    v15 = v11;
    v5 = v12;
    v4 = v15;
    goto LABEL_28;
  }
LABEL_24:
  v13 = LODWORD(X) - 1;
  v22[0] = LODWORD(X) - 1;
  v22[1] = HIDWORD(X);
  if ( LODWORD(X) == 0 )
  {
    v14 = HIDWORD(X) - 1;
LABEL_26:
    v22[1] = v14;
  }
LABEL_36:
  if ( (v22[1] & 0x7FF00000) == 0 && ((v22[1] & 0xFFFFF) != 0 || v13 != 0) )
  {
    v20 = *(double *)v22;
    _decomp_0(a1: *(double *)v22, a2: (int)&v22[1]);
    _set_exp_0(a1: v20, a2: v22[1] + 1536);
    return _except2_0(
             a1: 0xFFFF,
             dwExceptionCode: 0x12u,
             a3: 38,
             a4: SLODWORD(X),
             a5: SHIDWORD(X),
             a6: Y,
             a7: v20,
             a8: v23);
  }
  else if ( (v22[1] != 2146435072 || v13 != 0) && (v22[1] != -1048576 || v13 != 0) )
  {
    ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: v23, a2: 0xFFFF);
    return *(double *)v22;
  }
  else
  {
    v21 = *(double *)v22;
    _decomp_0(a1: *(double *)v22, a2: (int)&v22[1]);
    _set_exp_0(a1: v21, a2: v22[1] - 1536);
    return _except2_0(
             a1: 0xFFFF,
             dwExceptionCode: 0x11u,
             a3: 38,
             a4: SLODWORD(X),
             a5: SHIDWORD(X),
             a6: Y,
             a7: v21,
             a8: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F653556
// Name: __finite_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _finite_0(double X)
{
  return (HIWORD(X) & 0x7FF0) != 32752;
}

//------------------------------------------------------------------------------
// Address: 0x3F65356B
// Name: __isnan_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isnan_0(double X)
{
  return (HIWORD(X) & 0x7FF8) == 0x7FF0 && ((HIDWORD(X) & 0x7FFFF) != 0 || LODWORD(X) != 0)
      || (HIWORD(X) & 0x7FF8) == 0x7FF8;
}

//------------------------------------------------------------------------------
// Address: 0x3F653599
// Name: __fpclass_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fpclass_0(double X)
{
  int v1; // eax
  int v2; // eax
  int v4; // ecx

  if ( (HIWORD(X) & 0x7FF0) == 0x7FF0 )
  {
    v1 = _sptype_0(a1: LODWORD(X), a2: HIDWORD(X)) - 1;
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
    v4 = HIWORD(X) & 0x8000;
    if ( (HIWORD(X) & 0x7FF0) == 0 && ((HIDWORD(X) & 0xFFFFF) != 0 || LODWORD(X) != 0) )
    {
      return (HIWORD(X) & 0x8000) != 0 ? 16 : 128;
    }
    else if ( 0.0 == X )
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
// Address: 0x3F65362D
// Name: __set_exp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _set_exp_0(double a1, __int16 a2)
{
  double v3; // [esp+0h] [ebp-8h]

  v3 = a1;
  HIWORD(v3) = HIWORD(a1) & 0x800F | (16 * (a2 + 1022));
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F653696
// Name: __set_bexp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _set_bexp_0(double a1, __int16 a2)
{
  double v3; // [esp+0h] [ebp-8h]

  v3 = a1;
  HIWORD(v3) = HIWORD(a1) & 0x800F | (16 * a2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F6536BB
// Name: __sptype_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sptype_0(int a1, int a2)
{
  if ( a2 == 2146435072 )
  {
    if ( a1 == 0 )
      return 1;
  }
  else if ( a2 == -1048576 && a1 == 0 )
  {
    return 2;
  }
  if ( (HIWORD(a2) & 0x7FF8) == 0x7FF8 )
    return 3;
  if ( (HIWORD(a2) & 0x7FF8) == 0x7FF0 && ((a2 & 0x7FFFF) != 0 || a1 != 0) )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F653716
// Name: __decomp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __cdecl _decomp_0(double a1, int *a2)
{
  double result; // st7
  int v3; // edx
  int v4; // edx
  BOOL v5; // eax

  result = 0.0;
  if ( 0.0 == a1 )
  {
    v3 = 0;
  }
  else if ( (HIWORD(a1) & 0x7FF0) == 0 && ((HIDWORD(a1) & 0xFFFFF) != 0 || LODWORD(a1) != 0) )
  {
    v4 = -1021;
    v5 = a1 < 0.0;
    while ( (BYTE6(a1) & 0x10) == 0 )
    {
      HIDWORD(a1) *= 2;
      if ( SLODWORD(a1) < 0 )
        HIDWORD(a1) |= 1u;
      LODWORD(a1) *= 2;
      --v4;
    }
    HIWORD(a1) &= ~0x10u;
    if ( v5 )
      HIWORD(a1) |= 0x8000u;
    result = _set_exp_0(a1, a2: 0);
  }
  else
  {
    result = _set_exp_0(a1, a2: 0);
    v3 = ((*(_DWORD *)((char *)&a1 + 6) >> 4) & 0x7FF) - 1022;
  }
  *a2 = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6537C5
// Name: _ldexp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ldexp_0(double X, int Y)
{
  int v2; // edi
  int v3; // eax
  double v5; // st7
  int v6; // eax
  double v7; // st7
  double v8; // st7
  double Number; // [esp+8h] [ebp-20h]
  double v10; // [esp+10h] [ebp-18h]
  int v11; // [esp+18h] [ebp-10h]
  int v12; // [esp+24h] [ebp-4h] BYREF

  v2 = ((int (__cdecl *)(int, int))_ctrlfp_0)(a1: 4927, a2: 0xFFFF);
  if ( (HIWORD(X) & 0x7FF0) != 0x7FF0 )
  {
    if ( 0.0 == X )
    {
LABEL_6:
      ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: v2, a2: 0xFFFF);
      return X;
    }
    v5 = _decomp_0(a1: X, a2: &v12);
    if ( Y >= 0 )
    {
      if ( v12 > 0x7FFFFFFF - Y )
      {
LABEL_15:
        v11 = v2;
        v10 = _copysign_0(Number: dbl_3F6636F0, Sign: v5);
        Number = (double)Y;
        return _except2_0(
                 a1: 0xFFFF,
                 dwExceptionCode: 0x11u,
                 a3: 25,
                 a4: SLODWORD(X),
                 a5: SHIDWORD(X),
                 a6: Number,
                 a7: v10,
                 a8: v11);
      }
    }
    else if ( v12 < (int)(0x80000000 - Y) )
    {
      goto LABEL_20;
    }
    v6 = v12 + Y;
    if ( v12 + Y > 2560 )
      goto LABEL_15;
    if ( v6 > 1024 )
    {
      v7 = _set_exp_0(a1: v5, a2: (unsigned __int16)v6 - 1536);
      v11 = v2;
      v10 = v7;
      Number = (double)Y;
      return _except2_0(
               a1: 0xFFFF,
               dwExceptionCode: 0x11u,
               a3: 25,
               a4: SLODWORD(X),
               a5: SHIDWORD(X),
               a6: Number,
               a7: v10,
               a8: v11);
    }
    if ( v6 >= -2557 )
    {
      if ( v6 >= -1021 )
      {
        X = _set_exp_0(a1: v5, a2: v6);
        ((void (__cdecl *)(int, int))_ctrlfp_0)(a1: v2, a2: 0xFFFF);
        return X;
      }
      v8 = _set_exp_0(a1: v5, a2: (unsigned __int16)v6 + 1536);
      return _except2_0(
               a1: 0xFFFF,
               dwExceptionCode: 0x12u,
               a3: 25,
               a4: SLODWORD(X),
               a5: SHIDWORD(X),
               a6: (double)Y,
               a7: v8,
               a8: v2);
    }
LABEL_20:
    v8 = v5 * 0.0;
    return _except2_0(
             a1: 0xFFFF,
             dwExceptionCode: 0x12u,
             a3: 25,
             a4: SLODWORD(X),
             a5: SHIDWORD(X),
             a6: (double)Y,
             a7: v8,
             a8: v2);
  }
  v3 = _sptype_0(a1: SLODWORD(X), a2: SHIDWORD(X));
  if ( v3 > 0 )
  {
    if ( v3 > 2 )
    {
      if ( v3 == 3 )
        return _handle_qnan2_0(a1: 0xFFFF, a2: 25, a3: X, a4: (double)Y, a5: v2);
      return _except2_0(
               a1: 0xFFFF,
               dwExceptionCode: 8u,
               a3: 25,
               a4: SLODWORD(X),
               a5: SHIDWORD(X),
               a6: (double)Y,
               a7: X + 1.0,
               a8: v2);
    }
    goto LABEL_6;
  }
  return _except2_0(
           a1: 0xFFFF,
           dwExceptionCode: 8u,
           a3: 25,
           a4: SLODWORD(X),
           a5: SHIDWORD(X),
           a6: (double)Y,
           a7: X + 1.0,
           a8: v2);
}

//------------------------------------------------------------------------------
// Address: 0x3F653974
// Name: RaiseException
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RaiseException(
        DWORD dwExceptionCode,
        DWORD dwExceptionFlags,
        DWORD nNumberOfArguments,
        const ULONG_PTR *lpArguments)
{
  __imp_RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments);
}

//------------------------------------------------------------------------------
// Address: 0x3F653980
// Name: sub_3F653980
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F653980()
{
  CThreadLocalBase::CThreadLocalBase(this: &stru_3F6642B8);
  return atexit_0(a1: sub_3F653B30);
}

//------------------------------------------------------------------------------
// Address: 0x3F6539A0
// Name: sub_3F6539A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F6539A0()
{
  return atexit_0(a1: sub_3F653B40);
}

//------------------------------------------------------------------------------
// Address: 0x3F6539B0
// Name: sub_3F6539B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F6539B0()
{
  CThreadMutex::CThreadMutex(this: &stru_3F6642BC);
  return atexit_0(a1: sub_3F653B50);
}

//------------------------------------------------------------------------------
// Address: 0x3F6539D0
// Name: sub_3F6539D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F6539D0()
{
  int result; // eax

  result = dword_3F6642A8;
  dword_3F662AEC = dword_3F6642A8;
  dword_3F6642A8 = (int)&off_3F662AE4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6539F0
// Name: sub_3F6539F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F6539F0()
{
  ((void (*)(void))loc_3F606B60)();
  return atexit_0(a1: sub_3F653B70);
}

//------------------------------------------------------------------------------
// Address: 0x3F653A10
// Name: sub_3F653A10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F653A10(KeyValues *this)
{
  char *v1; // esi
  int v2; // ecx
  int result; // eax
  char *pszString; // [esp+8h] [ebp-10h] BYREF
  int v5; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+14h] [ebp-4h]

  pszString = nullptr;
  v5 = 0;
  KeyValues::WriteConvertedString(this, a2: (int)&pszString);
  v1 = pszString;
  v6 = v5;
  result = (unsigned int)v1 ^ ThreadGetCurrentProcessId(a1: v2);
  *(_DWORD *)&output_1[0][0] = 0;
  if ( result >= 0 )
    result = -result;
  dword_3F662AF4 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F653A60
// Name: sub_3F653A60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F653A60()
{
  int v1; // [esp+0h] [ebp-4h] BYREF

  v1 = 0;
  ((void (__stdcall *)(int *))loc_3F60B660)(a1: &v1);
  return atexit_0(a1: sub_3F653B80);
}

//------------------------------------------------------------------------------
// Address: 0x3F653A80
// Name: sub_3F653A80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F653A80()
{
  int result; // eax

  result = dword_3F6642A8;
  dword_3F662B88 = dword_3F6642A8;
  dword_3F6642A8 = (int)&off_3F662B80;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F653AA0
// Name: sub_3F653AA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F653AA0()
{
  return atexit_0(a1: sub_3F653BC0);
}

//------------------------------------------------------------------------------
// Address: 0x3F653AB0
// Name: sub_3F653AB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *sub_3F653AB0()
{
  dword_3F6643F0 = 0;
  dword_3F6643E4 = (int)&loc_3F61AB50;
  dword_3F6643E8 = 0;
  dword_3F6643EC = 0;
  return &loc_3F61AB50;
}

//------------------------------------------------------------------------------
// Address: 0x3F653AE0
// Name: sub_3F653AE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall sub_3F653AE0(int a1, _LDBL12 *pld12, const char **p_end_ptr, const char *str, int mult12)
{
  JUMPOUT(0x3F623300);
}

//------------------------------------------------------------------------------
// Address: 0x3F653AF0
// Name: sub_3F653AF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int sub_3F653AF0()
{
  int result; // eax
  int v1; // [esp-Ch] [ebp-10h]
  int v2; // [esp-8h] [ebp-Ch]
  int v3; // [esp-4h] [ebp-8h]

  result = ((int (__stdcall *)(int, char **, int, int, int))loc_3F623380)(
             a1: 1,
             a2: &g_CmdLine.m_ppParms[39],
             a3: v1,
             a4: v2,
             a5: v3);
  dword_3F664E08 = (int)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F653B10
// Name: sub_3F653B10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F653B10()
{
  return atexit_0(a1: sub_3F653BD0);
}

//------------------------------------------------------------------------------
// Address: 0x3F653B20
// Name: sub_3F653B20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F653B20(int a1@<esi>)
{
  dword_3F665888 = (int)&CCommandLine::`vftable';
  ((void (__cdecl *)(int))loc_3F601CC0)(a1);
  (*(void (__thiscall **)(_DWORD, int, _DWORD))(*g_pMemAllocSteam + 24))(
    a1: g_pMemAllocSteam,
    a2: dword_3F66588C,
    a3: 0);
  JUMPOUT(0x3F60126C);
}

//------------------------------------------------------------------------------
// Address: 0x3F653B30
// Name: sub_3F653B30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F653B30()
{
  CThreadLocalBase::~CThreadLocalBase(this: &stru_3F6642B8);
}

//------------------------------------------------------------------------------
// Address: 0x3F653B40
// Name: sub_3F653B40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl sub_3F653B40()
{
  JUMPOUT(0x3F605340);
}

//------------------------------------------------------------------------------
// Address: 0x3F653B50
// Name: sub_3F653B50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F653B50()
{
  CThreadMutex::~CThreadMutex(this: &stru_3F6642BC);
}

//------------------------------------------------------------------------------
// Address: 0x3F653B60
// Name: sub_3F653B60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F653B60()
{
  JUMPOUT(0x3F60690B);
}

//------------------------------------------------------------------------------
// Address: 0x3F653B70
// Name: sub_3F653B70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F653B70()
{
  JUMPOUT(0x3F606DE0);
}

//------------------------------------------------------------------------------
// Address: 0x3F653B80
// Name: sub_3F653B80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F653B80()
{
  ((void (*)(void))loc_3F60B9B0)();
  if ( dword_3F6643E0 >= 0 )
  {
    if ( dword_3F6643D8 != nullptr )
    {
      (*(void (__thiscall **)(_DWORD, CUtlMemory<ModuleCount_t> *, _DWORD))(*g_pMemAllocSteam + 24))(
        a1: g_pMemAllocSteam,
        a2: dword_3F6643D8,
        a3: 0);
      dword_3F6643D8 = nullptr;
    }
    dword_3F6643DC = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F653BC0
// Name: sub_3F653BC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl sub_3F653BC0()
{
  sub_3F61A4A0();
}

//------------------------------------------------------------------------------
// Address: 0x3F653BD0
// Name: sub_3F653BD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F653BD0()
{
  int v0; // esi

  v0 = dword_3F6642B4;
  if ( dword_3F6642B4 != 0 )
  {
    CThreadMutex::~CThreadMutex(this: (CThreadMutex *)(dword_3F6642B4 + 68));
    ((void (*)(void))loc_3F626880)();
    (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v0, a3: 1);
  }
  dword_3F6642B4 = 0;
}

} // namespace vstdlib_s
