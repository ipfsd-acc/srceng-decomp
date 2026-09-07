// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/traceinit.cpp
// Functions: 5
// ============================================================

#include "engine\traceinit.h"

//------------------------------------------------------------------------------
// Address: 0x101EF070
// Name: public: void CInitTracker::Shutdown(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInitTracker::Shutdown(CInitTracker *this, const char *shutdown, int listnum)
{
  int v5; // edx
  int v6; // eax
  CInitTracker::InitFunc **m_pMemory; // ecx
  CInitTracker::InitFunc *v8; // esi
  int v9; // esi
  CInitTracker::InitFunc *v10; // edi
  CUtlVector<CInitTracker::InitFunc *,CUtlMemory<CInitTracker::InitFunc *,int> > *listnuma; // [esp+18h] [ebp+Ch]

  v5 = this->m_nNumFuncs[listnum];
  if ( v5 != 0 )
  {
    v6 = 0;
    if ( v5 > 0 )
    {
      m_pMemory = this->m_Funcs[listnum].m_Memory.m_pMemory;
      while ( 1 )
      {
        v8 = *m_pMemory;
        if ( (*m_pMemory)->referencecount != 0 )
          break;
        ++v6;
        ++m_pMemory;
        if ( v6 >= v5 )
        {
          if ( v8->referencecount == 0 )
            goto LABEL_11;
          break;
        }
      }
      if ( _V_stricmp(s1: v8->shutdownname, s2: shutdown) != 0 && !v8->warningprinted )
        v8->warningprinted = true;
    }
LABEL_11:
    v9 = 0;
    if ( this->m_nNumFuncs[listnum] <= 0 )
    {
LABEL_15:
      _Msg(a1: "Shutdown function %s not in list!!!\n", shutdown);
    }
    else
    {
      listnuma = &this->m_Funcs[listnum];
      while ( 1 )
      {
        v10 = listnuma->m_Memory.m_pMemory[v9];
        if ( _V_stricmp(s1: v10->shutdownname, s2: shutdown) == 0 )
          break;
        if ( ++v9 >= this->m_nNumFuncs[listnum] )
          goto LABEL_15;
      }
      --v10->referencecount;
    }
  }
  else
  {
    _Msg(a1: "Mismatched shutdown function %s\n", shutdown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF150
// Name: void TraceShutdown(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TraceShutdown(const char *s, int listnum)
{
  CInitTracker::Shutdown(this: &g_InitTracker, shutdown: s, listnum);
}

//------------------------------------------------------------------------------
// Address: 0x101EF170
// Name: public: CInitTracker::~CInitTracker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInitTracker::~CInitTracker(CInitTracker *this)
{
  CInitTracker *v1; // ebx
  int v2; // edi
  CInitTracker::InitFunc *v3; // esi
  bool v4; // zf
  CInitTracker *v5; // esi
  int i; // edi
  void *v7; // eax
  CInitTracker *v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  CUtlVector<CInitTracker::InitFunc *,CUtlMemory<CInitTracker::InitFunc *,int> > *m_Funcs; // [esp+14h] [ebp-4h]

  v8 = this;
  v1 = this;
  m_Funcs = this->m_Funcs;
  v9 = 4;
  do
  {
    v2 = 0;
    if ( v1->m_nNumFuncs[0] > 0 )
    {
      do
      {
        v3 = m_Funcs->m_Memory.m_pMemory[v2];
        if ( v3->referencecount != 0 )
          _Msg(a1: "Missing shutdown function for %s : %s\n", v3->initname, v3->shutdownname);
        free(pMem: v3);
        ++v2;
      }
      while ( v2 < v1->m_nNumFuncs[0] );
      this = v8;
    }
    m_Funcs->m_Size = 0;
    v1->m_nNumFuncs[0] = 0;
    v1 = (CInitTracker *)((char *)v1 + 4);
    v4 = v9-- == 1;
    ++m_Funcs;
  }
  while ( !v4 );
  v5 = this + 1;
  for ( i = 3; i >= 0; --i )
  {
    v5 = (CInitTracker *)((char *)v5 - 20);
    v5->m_nNumFuncs[3] = 0;
    if ( v5->m_nNumFuncs[2] >= 0 )
    {
      if ( v5->m_nNumFuncs[0] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v5->m_nNumFuncs[0]);
        v5->m_nNumFuncs[0] = 0;
      }
      v5->m_nNumFuncs[1] = 0;
    }
    v7 = (void *)v5->m_nNumFuncs[0];
    v5->m_Funcs[0].m_Memory.m_pMemory = (CInitTracker::InitFunc **)v5->m_nNumFuncs[0];
    if ( v5->m_nNumFuncs[2] >= 0 )
    {
      if ( v7 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
        v5->m_nNumFuncs[0] = 0;
      }
      v5->m_nNumFuncs[1] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF250
// Name: public: void CInitTracker::Init(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInitTracker::Init(CInitTracker *this, const char *init, const char *shutdown, int listnum)
{
  _DWORD *v5; // esi
  int v6; // eax
  CUtlMemory<S3RGBA,int> *v7; // edi
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v10; // edx
  S3RGBA *v11; // edi

  v5 = MemAlloc_Alloc(nSize: 0x1Cu);
  *v5 = init;
  v6 = listnum;
  v5[1] = shutdown;
  v7 = (CUtlMemory<S3RGBA,int> *)&this->m_Funcs[listnum];
  v5[3] = this->m_nNumFuncs[listnum];
  v5[2] = 1;
  *((_BYTE *)v5 + 16) = 0;
  v5[5] = 0;
  v5[6] = 0;
  m_nAllocationCount = this->m_Funcs[listnum].m_Memory.m_nAllocationCount;
  if ( this->m_Funcs[listnum].m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(this: v7, num: this->m_Funcs[listnum].m_Size - m_nAllocationCount + 1);
    v6 = listnum;
  }
  ++this->m_Funcs[listnum].m_Size;
  m_pMemory = v7->m_pMemory;
  v10 = this->m_Funcs[listnum].m_Size - 1;
  this->m_Funcs[listnum].m_pElements = this->m_Funcs[listnum].m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(dest: &m_pMemory[1], src: m_pMemory, count: 4 * v10);
    v6 = listnum;
  }
  v11 = v7->m_pMemory;
  if ( v11 != nullptr )
    *v11 = (S3RGBA)v5;
  ++this->m_nNumFuncs[v6];
}

//------------------------------------------------------------------------------
// Address: 0x101EF2F0
// Name: void TraceInit(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TraceInit(const char *i, const char *s, int listnum)
{
  CInitTracker::Init(this: &g_InitTracker, init: i, shutdown: s, listnum);
  _COM_TimestampedLog(a1: "%s", i);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101EF320
// Name: public: void CInitTracker::Shutdown(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInitTracker::Shutdown(CInitTracker *this, const char *shutdown, int listnum)
{
  int v5; // edx
  int v6; // eax
  CInitTracker::InitFunc **m_pMemory; // ecx
  CInitTracker::InitFunc *v8; // esi
  int v9; // esi
  CInitTracker::InitFunc *v10; // edi
  CUtlVector<CInitTracker::InitFunc *,CUtlMemory<CInitTracker::InitFunc *,int> > *listnuma; // [esp+18h] [ebp+Ch]

  v5 = this->m_nNumFuncs[listnum];
  if ( v5 != 0 )
  {
    v6 = 0;
    if ( v5 > 0 )
    {
      m_pMemory = this->m_Funcs[listnum].m_Memory.m_pMemory;
      while ( 1 )
      {
        v8 = *m_pMemory;
        if ( (*m_pMemory)->referencecount != 0 )
          break;
        ++v6;
        ++m_pMemory;
        if ( v6 >= v5 )
        {
          if ( v8->referencecount == 0 )
            goto LABEL_11;
          break;
        }
      }
      if ( _V_stricmp(s1: v8->shutdownname, s2: shutdown) != 0 && !v8->warningprinted )
        v8->warningprinted = true;
    }
LABEL_11:
    v9 = 0;
    if ( this->m_nNumFuncs[listnum] <= 0 )
    {
LABEL_15:
      _Msg(a1: "Shutdown function %s not in list!!!\n", shutdown);
    }
    else
    {
      listnuma = &this->m_Funcs[listnum];
      while ( 1 )
      {
        v10 = listnuma->m_Memory.m_pMemory[v9];
        if ( _V_stricmp(s1: v10->shutdownname, s2: shutdown) == 0 )
          break;
        if ( ++v9 >= this->m_nNumFuncs[listnum] )
          goto LABEL_15;
      }
      --v10->referencecount;
    }
  }
  else
  {
    _Msg(a1: "Mismatched shutdown function %s\n", shutdown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF400
// Name: void TraceShutdown(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TraceShutdown(const char *s, int listnum)
{
  CInitTracker::Shutdown(this: &g_InitTracker, shutdown: s, listnum);
}

//------------------------------------------------------------------------------
// Address: 0x101EF420
// Name: public: CInitTracker::~CInitTracker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInitTracker::~CInitTracker(CInitTracker *this)
{
  CInitTracker *v1; // ebx
  int v2; // edi
  CInitTracker::InitFunc *v3; // esi
  bool v4; // zf
  CInitTracker *v5; // esi
  int i; // edi
  void *v7; // eax
  CInitTracker *v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  CUtlVector<CInitTracker::InitFunc *,CUtlMemory<CInitTracker::InitFunc *,int> > *m_Funcs; // [esp+14h] [ebp-4h]

  v8 = this;
  v1 = this;
  m_Funcs = this->m_Funcs;
  v9 = 4;
  do
  {
    v2 = 0;
    if ( v1->m_nNumFuncs[0] > 0 )
    {
      do
      {
        v3 = m_Funcs->m_Memory.m_pMemory[v2];
        if ( v3->referencecount != 0 )
          _Msg(a1: "Missing shutdown function for %s : %s\n", v3->initname, v3->shutdownname);
        free(pMem: v3);
        ++v2;
      }
      while ( v2 < v1->m_nNumFuncs[0] );
      this = v8;
    }
    m_Funcs->m_Size = 0;
    v1->m_nNumFuncs[0] = 0;
    v1 = (CInitTracker *)((char *)v1 + 4);
    v4 = v9-- == 1;
    ++m_Funcs;
  }
  while ( !v4 );
  v5 = this + 1;
  for ( i = 3; i >= 0; --i )
  {
    v5 = (CInitTracker *)((char *)v5 - 20);
    v5->m_nNumFuncs[3] = 0;
    if ( v5->m_nNumFuncs[2] >= 0 )
    {
      if ( v5->m_nNumFuncs[0] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v5->m_nNumFuncs[0]);
        v5->m_nNumFuncs[0] = 0;
      }
      v5->m_nNumFuncs[1] = 0;
    }
    v7 = (void *)v5->m_nNumFuncs[0];
    v5->m_Funcs[0].m_Memory.m_pMemory = (CInitTracker::InitFunc **)v5->m_nNumFuncs[0];
    if ( v5->m_nNumFuncs[2] >= 0 )
    {
      if ( v7 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
        v5->m_nNumFuncs[0] = 0;
      }
      v5->m_nNumFuncs[1] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF500
// Name: public: void CInitTracker::Init(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInitTracker::Init(CInitTracker *this, const char *init, const char *shutdown, int listnum)
{
  _DWORD *v5; // esi
  int v6; // eax
  CUtlMemory<S3RGBA,int> *v7; // edi
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v10; // edx
  S3RGBA *v11; // edi

  v5 = MemAlloc_Alloc(nSize: 0x1Cu);
  *v5 = init;
  v6 = listnum;
  v5[1] = shutdown;
  v7 = (CUtlMemory<S3RGBA,int> *)&this->m_Funcs[listnum];
  v5[3] = this->m_nNumFuncs[listnum];
  v5[2] = 1;
  *((_BYTE *)v5 + 16) = 0;
  v5[5] = 0;
  v5[6] = 0;
  m_nAllocationCount = this->m_Funcs[listnum].m_Memory.m_nAllocationCount;
  if ( this->m_Funcs[listnum].m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(this: v7, num: this->m_Funcs[listnum].m_Size - m_nAllocationCount + 1);
    v6 = listnum;
  }
  ++this->m_Funcs[listnum].m_Size;
  m_pMemory = v7->m_pMemory;
  v10 = this->m_Funcs[listnum].m_Size - 1;
  this->m_Funcs[listnum].m_pElements = this->m_Funcs[listnum].m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(dest: &m_pMemory[1], src: m_pMemory, count: 4 * v10);
    v6 = listnum;
  }
  v11 = v7->m_pMemory;
  if ( v11 != nullptr )
    *v11 = (S3RGBA)v5;
  ++this->m_nNumFuncs[v6];
}

//------------------------------------------------------------------------------
// Address: 0x101EF5A0
// Name: void TraceInit(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TraceInit(const char *i, const char *s, int listnum)
{
  CInitTracker::Init(this: &g_InitTracker, init: i, shutdown: s, listnum);
  _COM_TimestampedLog(a1: "%s", i);
}

} // namespace engine_xlsp
