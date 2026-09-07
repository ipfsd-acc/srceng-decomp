// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vcd_sound_check/vcd_sound_check.cpp
// Functions: 127
// ============================================================

#include "utils\vcd_sound_check\vcd_sound_check.h"

//------------------------------------------------------------------------------
// Address: 0x00401520
// Name: public: void CUtlLinkedList<void (*)(void),unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<void (*)(void),unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<void (__cdecl*)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl*)(void),unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<void (__cdecl*)(void),unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004043E0
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
// Address: 0x00404480
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404640
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
// Address: 0x004046B0
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
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x00404BE0
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
    CUtlMemory<fileList_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *)this,
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
// Address: 0x00404C50
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
    CUtlMemory<fileList_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *)this,
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
// Address: 0x00404CF0
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
// Address: 0x00404D60
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
// Address: 0x00405030
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
// Address: 0x004055A0
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x004055D0
// Name: public: virtual char const __near * CSceneTokenProcessor::CurrentToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSceneTokenProcessor::CurrentToken(CSceneTokenProcessor *this)
{
  return token;
}

//------------------------------------------------------------------------------
// Address: 0x004055E0
// Name: public: virtual bool CSceneTokenProcessor::GetToken(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::GetToken(CSceneTokenProcessor *this, bool crossline)
{
  return GetToken(crossline) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405600
// Name: public: virtual bool CSceneTokenProcessor::TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::TokenAvailable(CSceneTokenProcessor *this)
{
  return TokenAvailable() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405610
// Name: public: virtual void CSceneTokenProcessor::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSceneTokenProcessor::Error(CSceneTokenProcessor *this, const char *fmt, ...)
{
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 2048, pFormat: fmt, params);
  _Warning(a1: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x00405650
// Name: void vprint(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void vprint(int depth, char *fmt, ...)
{
  _iobuf *v2; // edi
  int v3; // esi
  char *i; // esi
  char string[8192]; // [esp+Ch] [ebp-2000h] BYREF
  va_list ap; // [esp+201Ch] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  v2 = nullptr;
  if ( uselogfile )
    v2 = fopen(file: "log.txt", mode: "ab");
  v3 = depth;
  while ( v3 > 0 )
  {
    --v3;
    printf(format: "  ");
    OutputDebugStringA(lpOutputString: "  ");
    if ( v2 != nullptr )
      fprintf(str: v2, format: "  ");
  }
  printf(format: string);
  OutputDebugStringA(lpOutputString: string);
  if ( v2 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v2) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v2);
    }
    fclose(stream: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405740
// Name: void logprint(char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void logprint(char *logfile, char *fmt, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // edi
  char *i; // esi
  char string[8192]; // [esp+4h] [ebp-2000h] BYREF
  va_list ap; // [esp+2014h] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  if ( first )
  {
    first = false;
    v2 = fopen(file: logfile, mode: "wb");
  }
  else
  {
    v2 = fopen(file: logfile, mode: "ab");
  }
  v3 = v2;
  if ( v2 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v3) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v3);
    }
    fclose(stream: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004057E0
// Name: void Con_Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_Printf(const char *fmt, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, fmt);
  vprintf(format: fmt, ap);
  vsprintf(string: output, format: fmt, ap);
  vprint(depth: 0, fmt: output);
}

//------------------------------------------------------------------------------
// Address: 0x00405820
// Name: void printusage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn printusage()
{
  vprint(
    depth: 0,
    fmt: "usage:  vcd_sound_check <.wav root directory> <scenes root directory>\n"
    "\t\t\t-v = verbose output\n"
    "\t\t\t-m = spew moveto info\n"
    "\t\t\t-o = spew vcd overlap info only\n"
    "\t\t\t-l = log to file log.txt\n"
    "\t\t\n"
    "e.g.:  vcd_sound_check -l u:/hl2/hl2/sound/vo u:/hl2/hl2/scenes\n");
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00405840
// Name: void SpewMoveto(bool,char const __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpewMoveto(bool first, const char *vcdname, CChoreoEvent *e)
{
  bool v3; // zf
  const char *v4; // eax
  const char *Name; // eax
  double StartTime; // [esp+0h] [ebp-14h]
  const char *Parameters; // [esp+8h] [ebp-Ch]
  const char *v8; // [esp+Ch] [ebp-8h]

  if ( spewmoveto )
  {
    if ( first )
      ecounter = 0;
    v3 = !CChoreoEvent::IsResumeCondition(this: e);
    v4 = "YES";
    if ( v3 )
      v4 = "no";
    ++ecounter;
    v8 = v4;
    Parameters = CChoreoEvent::GetParameters(this: e);
    StartTime = CChoreoEvent::GetStartTime(this: e);
    Name = CChoreoEvent::GetName(this: e);
    logprint(
      logfile: "moveto.txt",
      fmt: "\"%s\",%i,\"%s\",%.3f,\"%s\",%s\n",
      vcdname,
      ecounter,
      Name,
      StartTime,
      Parameters,
      v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004058C0
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > (double)p1a;
}

//------------------------------------------------------------------------------
// Address: 0x00405900
// Name: IsFlexTrackBeingUsed
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsFlexTrackBeingUsed(CChoreoEvent *event, const char *trackName)
{
  int NumFlexAnimationTracks; // edi
  int v3; // ebx
  CFlexAnimationTrack *FlexAnimationTrack; // esi
  int NumSamples; // edi
  const char *FlexControllerName; // eax
  int tc; // [esp+Ch] [ebp-8h]
  int sampleCountNormal; // [esp+10h] [ebp-4h]

  NumFlexAnimationTracks = CChoreoEvent::GetNumFlexAnimationTracks(this: event);
  v3 = 0;
  tc = NumFlexAnimationTracks;
  if ( NumFlexAnimationTracks <= 0 )
    return 0;
  while ( 1 )
  {
    FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: event, index: v3);
    if ( CFlexAnimationTrack::IsTrackActive(this: FlexAnimationTrack) )
      break;
LABEL_9:
    if ( ++v3 >= NumFlexAnimationTracks )
      return 0;
  }
  sampleCountNormal = CFlexAnimationTrack::GetNumSamples(this: FlexAnimationTrack, type: 0);
  NumSamples = 0;
  if ( CFlexAnimationTrack::IsComboType(this: FlexAnimationTrack) )
    NumSamples = CFlexAnimationTrack::GetNumSamples(this: FlexAnimationTrack, type: 1);
  if ( sampleCountNormal == 0 && NumSamples == 0
    || (FlexControllerName = CFlexAnimationTrack::GetFlexControllerName(this: FlexAnimationTrack),
        _V_stricmp(s1: FlexControllerName, s2: trackName) != 0) )
  {
    NumFlexAnimationTracks = tc;
    goto LABEL_9;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004059A0
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
// Address: 0x00405A30
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CChoreoEvent *,int> *m_pMemory; // edx
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CChoreoEvent *,int> *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CChoreoEvent *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405AD0
// Name: public: void CUtlMemory<class CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405B70
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( i == -1 )
    return dword_465EA4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00405BD0
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_465E94 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_465E94;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00405C40
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_465E94 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00405CA0
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_465E94 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00405D10
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::FindInsertionPosition(class CChoreoEvent __near * const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        CChoreoEvent *const *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405E00
// Name: protected: int CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::AllocInternal(
        CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CChoreoEvent *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00405F30
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( i == -1 )
    return dword_465EA0;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00405FB0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct VCDList,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,VCDList,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004060A0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_465EA0 = -1;
      dword_465EA4 = -1;
      dword_465EA8 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_465EA0 = -1;
      dword_465EA4 = -1;
      dword_465EA8 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406140
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00406240
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00406340
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( m_Parent == -1 )
    return dword_465EA0 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x004063F0
// Name: public: void CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::RemoveAll(
        CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CChoreoEvent *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406450
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00406500
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_465EA0 = -1;
      dword_465EA4 = -1;
      dword_465EA8 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004066B0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00406820
// Name: EventCollidesWithRows
// Source: json
//------------------------------------------------------------------------------
char __usercall EventCollidesWithRows@<al>(
        CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *list@<eax>,
        CChoreoEvent *event,
        char *trackName,
        unsigned int trackNameLength)
{
  int m_Head; // eax
  int v6; // esi
  CChoreoEvent *m_Element; // ebx
  int NumFlexAnimationTracks; // ebx
  int v10; // edi
  CFlexAnimationTrack *FlexAnimationTrack; // esi
  int NumSamples; // ebx
  int v13; // edi
  const char *FlexControllerName; // eax
  const char *v15; // eax
  CChoreoEvent *test; // [esp+Ch] [ebp-14h]
  float testend; // [esp+10h] [ebp-10h]
  int testenda; // [esp+10h] [ebp-10h]
  float st; // [esp+14h] [ebp-Ch]
  float ed; // [esp+18h] [ebp-8h]
  float tracka; // [esp+1Ch] [ebp-4h]
  int track; // [esp+1Ch] [ebp-4h]

  st = CChoreoEvent::GetStartTime(this: event);
  ed = CChoreoEvent::GetEndTime(this: event);
  m_Head = list->m_Head;
  if ( m_Head == -1 )
    return 0;
  while ( 1 )
  {
    v6 = m_Head;
    m_Element = list->m_Memory.m_pMemory[m_Head].m_Element;
    test = m_Element;
    tracka = CChoreoEvent::GetStartTime(this: m_Element);
    testend = CChoreoEvent::GetEndTime(this: m_Element);
    if ( tracka < (double)ed && st < testend )
      break;
    m_Head = list->m_Memory.m_pMemory[v6].m_Next;
    if ( m_Head == -1 )
      return 0;
  }
  NumFlexAnimationTracks = CChoreoEvent::GetNumFlexAnimationTracks(this: event);
  v10 = 0;
  testenda = NumFlexAnimationTracks;
  track = 0;
  if ( NumFlexAnimationTracks <= 0 )
    return 0;
  while ( 1 )
  {
    FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: event, index: v10);
    if ( CFlexAnimationTrack::IsTrackActive(this: FlexAnimationTrack) )
      break;
LABEL_14:
    track = ++v10;
    if ( v10 >= NumFlexAnimationTracks )
      return 0;
  }
  NumSamples = CFlexAnimationTrack::GetNumSamples(this: FlexAnimationTrack, type: 0);
  v13 = 0;
  if ( CFlexAnimationTrack::IsComboType(this: FlexAnimationTrack) )
    v13 = CFlexAnimationTrack::GetNumSamples(this: FlexAnimationTrack, type: 1);
  if ( NumSamples == 0 && v13 == 0
    || (FlexControllerName = CFlexAnimationTrack::GetFlexControllerName(this: FlexAnimationTrack),
        IsFlexTrackBeingUsed(event: test, trackName: FlexControllerName) == 0) )
  {
    v10 = track;
    NumFlexAnimationTracks = testenda;
    goto LABEL_14;
  }
  v15 = CFlexAnimationTrack::GetFlexControllerName(this: FlexAnimationTrack);
  V_strncpy(pDest: trackName, pSrc: v15, maxLen: trackNameLength);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406950
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_465E94 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_465E94 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406A20
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // si
  int v4; // edx
  int result; // eax
  int *v6; // ecx
  int v7; // edx
  int *v8; // ecx
  int v9; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406C20
// Name: public: int CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>>::InsertBefore(int,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *this,
        int elem,
        const CUtlSymbol *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlSymbol,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_Id = src->m_Id;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00406C90
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct VCDList,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,VCDList,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00406D80
// Name: public: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406E40
// Name: public: void CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::Unlink(
        CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CChoreoEvent *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406EC0
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_465E94 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_465E94 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_465E94 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_465E94 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_465E94 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_465E94 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_465E94 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_465E94 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_465E94 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_465E94 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_465E94 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407470
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EA0 = -1;
    dword_465EA4 = -1;
    dword_465EA8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EA0 = -1;
          dword_465EA4 = -1;
          dword_465EA8 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004075E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EA0 = -1;
        dword_465EA4 = -1;
        dword_465EA8 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EA0 = -1;
          dword_465EA4 = -1;
          dword_465EA8 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EA0 = -1;
          dword_465EA4 = -1;
          dword_465EA8 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EA0 = -1;
            dword_465EA4 = -1;
            dword_465EA8 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EA0 = -1;
            dword_465EA4 = -1;
            dword_465EA8 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EA0 = -1;
          dword_465EA4 = -1;
          dword_465EA8 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EA0 = -1;
          dword_465EA4 = -1;
          dword_465EA8 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EA0 = -1;
            dword_465EA4 = -1;
            dword_465EA8 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EA0 = -1;
            dword_465EA4 = -1;
            dword_465EA8 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407A40
// Name: public: int CUtlVector<class CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>,class CUtlMemory<class CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,int>>::InsertBefore(
        CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> >,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> >,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *m_pMemory; // ecx
  int v6; // eax
  CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *v7; // eax
  UtlLinkedListElem_t<CChoreoEvent *,int> *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 40 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Memory.m_pMemory = nullptr;
    v7->m_Memory.m_nAllocationCount = 0;
    v7->m_Memory.m_nGrowSize = 0;
    v7->m_LastAlloc.index = -1;
    v7->m_Head = -1;
    v7->m_Tail = -1;
    v7->m_FirstFree = -1;
    v8 = v7->m_Memory.m_pMemory;
    v7->m_ElementCount = 0;
    v7->m_NumAlloced = 0;
    v7->m_pElements = v8;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00407AD0
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407B50
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407BC0
// Name: void BuildFileList_R(class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildFileList_R(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *files,
        const char *dir,
        const char *extension)
{
  signed int v3; // edi
  signed int v4; // kr00_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v8; // eax
  CUtlSymbol *v9; // eax
  int v10; // ecx
  char filename[256]; // [esp+4h] [ebp-450h] BYREF
  char directory[256]; // [esp+104h] [ebp-350h] BYREF
  char pDest[260]; // [esp+204h] [ebp-250h] BYREF
  _WIN32_FIND_DATAA wfd; // [esp+308h] [ebp-14Ch] BYREF
  int extlen; // [esp+448h] [ebp-Ch]
  void *ff; // [esp+44Ch] [ebp-8h]
  CUtlSymbol sym; // [esp+450h] [ebp-4h] BYREF

  sprintf(string: directory, format: "%s\\*.*", dir);
  ff = FindFirstFileA(lpFileName: directory, lpFindFileData: &wfd);
  if ( ff != (void *)-1 )
  {
    v3 = strlen(extension);
    for ( extlen = v3; ; v3 = extlen )
    {
      if ( (wfd.dwFileAttributes & 0x10) != 0 )
      {
        if ( wfd.cFileName[0] != 46 )
        {
          sprintf(string: filename, format: "%s\\%s", dir, wfd.cFileName);
          BuildFileList_R(files, dir: filename, extension);
        }
      }
      else
      {
        v4 = strlen(wfd.cFileName);
        if ( v4 > v3 && _V_stricmp(s1: &wfd.cFileName[v4 - v3], s2: extension) == 0 )
        {
          V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", dir, wfd.cFileName);
          strlwr(string: pDest);
          V_FixSlashes(pname: pDest, separator: 92);
          CUtlSymbolTable::AddString(this: &g_Analysis.symbols, result: &sym, pString: pDest);
          m_Size = files->m_Size;
          m_nAllocationCount = files->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CUtlSymbol,int>::Grow(this: &files->m_Memory, num: m_Size - m_nAllocationCount + 1);
          ++files->m_Size;
          m_pMemory = files->m_Memory.m_pMemory;
          v8 = files->m_Size - m_Size - 1;
          files->m_pElements = files->m_Memory.m_pMemory;
          if ( v8 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v8);
          v9 = &files->m_Memory.m_pMemory[m_Size];
          if ( v9 != nullptr )
            v9->m_Id = sym.m_Id;
          v10 = files->m_Size;
          if ( v10 % 3000 == 0 )
            vprint(depth: 0, fmt: "...found %i .%s files\n", v10, extension);
        }
      }
      if ( !FindNextFileA(hFindFile: ff, lpFindFileData: &wfd) )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407DA0
// Name: public: VCDList::VCDList(struct VCDList const __near &)
// Source: json
//------------------------------------------------------------------------------
VCDList *__thiscall VCDList::VCDList(VCDList *this, const VCDList *src)
{
  int v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  int c; // [esp+8h] [ebp-8h]
  CUtlSymbol *v11; // [esp+Ch] [ebp-4h]

  v2 = 0;
  this->vcds.m_Memory.m_pMemory = nullptr;
  this->vcds.m_Memory.m_nAllocationCount = 0;
  this->vcds.m_Memory.m_nGrowSize = 0;
  this->vcds.m_Size = 0;
  this->vcds.m_pElements = nullptr;
  c = src->vcds.m_Size;
  if ( c > 0 )
  {
    do
    {
      m_Size = this->vcds.m_Size;
      v11 = &src->vcds.m_Memory.m_pMemory[v2];
      m_nAllocationCount = this->vcds.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUtlSymbol,int>::Grow(this: &this->vcds.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++this->vcds.m_Size;
      m_pMemory = this->vcds.m_Memory.m_pMemory;
      v7 = this->vcds.m_Size - m_Size - 1;
      this->vcds.m_pElements = this->vcds.m_Memory.m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v7);
      v8 = &this->vcds.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        v8->m_Id = v11->m_Id;
      ++v2;
    }
    while ( v2 < c );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407E40
// Name: public: struct VCDList __near & VCDList::operator=(struct VCDList const __near &)
// Source: json
//------------------------------------------------------------------------------
VCDList *__thiscall VCDList::operator=(VCDList *this, const VCDList *src)
{
  const VCDList *v2; // eax
  int v4; // ebx
  int m_Size; // edi
  int v6; // ecx
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v9; // eax
  CUtlSymbol *v10; // eax
  int c; // [esp+4h] [ebp-8h]
  unsigned __int16 *v13; // [esp+8h] [ebp-4h]

  v2 = src;
  if ( this != src )
  {
    v4 = 0;
    c = src->vcds.m_Size;
    if ( c > 0 )
    {
      while ( 1 )
      {
        m_Size = this->vcds.m_Size;
        v6 = (int)&v2->vcds.m_Memory.m_pMemory[v4];
        m_nAllocationCount = this->vcds.m_Memory.m_nAllocationCount;
        v13 = (unsigned __int16 *)v6;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CUtlSymbol,int>::Grow(this: &this->vcds.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++this->vcds.m_Size;
        m_pMemory = this->vcds.m_Memory.m_pMemory;
        v9 = this->vcds.m_Size - m_Size - 1;
        this->vcds.m_pElements = this->vcds.m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v9);
        v10 = &this->vcds.m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          v10->m_Id = *v13;
        if ( ++v4 >= c )
          break;
        v2 = src;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407ED0
// Name: public: CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::~CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407F40
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::NewNode@<eax>(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this@<ecx>,
        const char *a2@<edi>)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlMap<char const *,VCDList,int>::Node_t *p_m_Data; // ecx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v6 = index + 1;
      if ( v6 < 0 || v6 >= m_nAllocationCount )
        v6 = -1;
    }
    v7 = v6;
    if ( v6 < 0 || v6 >= m_nAllocationCount )
    {
      CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v8 = this->m_LastAlloc.index;
      if ( v8 < 0 || (v9 = this->m_Elements.m_nAllocationCount, v8 >= v9) )
      {
        v9 = this->m_Elements.m_nAllocationCount;
        v10 = (v9 > 0) - 1;
      }
      else
      {
        v10 = v8 + 1;
        if ( v10 < 0 || v10 >= v9 )
          v10 = -1;
      }
      v7 = v10;
      if ( v10 < 0 || v10 >= v9 )
        _Error(this: (ISceneTokenProcessor *)&stru_42F0F4, a2);
    }
    this->m_LastAlloc.index = v7;
    result = v7;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result].m_Right;
  }
  p_m_Data = &this->m_Elements.m_pMemory[result].m_Data;
  if ( &this->m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)-16 )
  {
    this->m_Elements.m_pMemory[result].m_Data.elem.vcds.m_Memory.m_pMemory = nullptr;
    p_m_Data->elem.vcds.m_Memory.m_nAllocationCount = 0;
    p_m_Data->elem.vcds.m_Memory.m_nGrowSize = 0;
    p_m_Data->elem.vcds.m_Size = 0;
    p_m_Data->elem.vcds.m_pElements = nullptr;
  }
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408020
// Name: public: int CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>::AddToHead(class CChoreoEvent __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::AddToHead(
        CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *this,
        CChoreoEvent **src)
{
  int result; // eax
  int v4; // esi
  UtlLinkedListElem_t<CChoreoEvent *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Next; // eax
  UtlLinkedListElem_t<CChoreoEvent *,int> *v8; // edi

  result = CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    if ( result >= 0
      && result < this->m_Memory.m_nAllocationCount
      && result <= this->m_LastAlloc.index
      && this->m_Memory.m_pMemory[result].m_Previous != result )
    {
      CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::Unlink(
        this,
        elem: result);
    }
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Previous = -1;
    m_pMemory[v6].m_Next = this->m_Head;
    this->m_Head = v4;
    m_Next = m_pMemory[v4].m_Next;
    if ( m_Next == -1 )
      this->m_Tail = v4;
    else
      this->m_Memory.m_pMemory[m_Next].m_Previous = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004080B0
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::Insert(class CChoreoEvent __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        CChoreoEvent *const *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode((CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this);
  v4 = v3;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00408120
// Name: public: void CUtlVector<class CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>,class CUtlMemory<class CUtlLinkedList<class CChoreoEvent __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEvent __near *,int>,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,int>>::RemoveAll(
        CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> >,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> >,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *v3; // esi
  CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> >,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> >,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      this = v4;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408190
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi
  int v5; // edi

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0 && v4 < this->m_Elements.m_nAllocationCount && v4 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EA0 = -1;
            dword_465EA4 = -1;
            dword_465EA8 = 1;
          }
          if ( this->m_Elements.m_pMemory[v4].m_Left != v4 )
          {
            v5 = v4;
            CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Elements.m_pMemory[v4].m_Data.elem);
            this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v5].m_Left = v4;
            this->m_FirstFree = v4;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408270
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int,class CUtlMap<char const __near *,struct VCDList,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct VCDList,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,struct VCDList,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Insert@<eax>(
        CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *this@<ecx>,
        const char *a2@<edi>,
        const CUtlMap<char const *,VCDList,int>::Node_t *insert)
{
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v4 = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::NewNode(
         this,
         a2);
  CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v4,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *)-16 )
  {
    m_pMemory[v4].m_Data.key = insert->key;
    VCDList::VCDList(this: &m_pMemory[v4].m_Data.elem, src: &insert->elem);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004082E0
// Name: void CheckForOverlappingFlexTracks(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckForOverlappingFlexTracks(CChoreoScene *scene)
{
  CChoreoScene *v1; // ebx
  int v2; // esi
  int v3; // edi
  CChoreoActor *v4; // ebx
  CChoreoChannel *v5; // esi
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v11; // esi
  int v12; // edx
  CChoreoEvent **v13; // esi
  CChoreoEvent *v14; // esi
  int m_Size; // ebx
  CChoreoEvent *m_Data; // edi
  int v17; // esi
  CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> > *v18; // ebx
  const char *Filename; // eax
  int v20; // eax
  const char *v21; // [esp-Ch] [ebp-164h]
  const char *Name; // [esp-8h] [ebp-160h]
  char offender[256]; // [esp+Ch] [ebp-14Ch] BYREF
  int a; // [esp+10Ch] [ebp-4Ch]
  CChoreoActor *actor; // [esp+110h] [ebp-48h]
  CChoreoEvent *event; // [esp+114h] [ebp-44h] BYREF
  CChoreoChannel *channel; // [esp+118h] [ebp-40h]
  CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> >,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int> >,int> > rows; // [esp+11Ch] [ebp-3Ch] BYREF
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > actorFlexEvents; // [esp+130h] [ebp-28h] BYREF
  int i; // [esp+14Ch] [ebp-Ch] BYREF
  CChoreoEvent *e; // [esp+150h] [ebp-8h] BYREF
  bool done; // [esp+157h] [ebp-1h] BYREF

  v1 = scene;
  v2 = 0;
  v3 = 0;
  for ( a = 0; v2 < CChoreoScene::GetNumActors(this: scene); v2 = a )
  {
    v4 = CChoreoScene::GetActor(this: v1, actor: v2);
    actor = v4;
    actorFlexEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
    memset(&actorFlexEvents.m_Elements, 0, sizeof(actorFlexEvents.m_Elements));
    *(_DWORD *)&actorFlexEvents.m_Root = 0xFFFF;
    *(_DWORD *)&actorFlexEvents.m_FirstFree = -1;
    actorFlexEvents.m_pElements = nullptr;
    e = nullptr;
    if ( CChoreoActor::GetNumChannels(this: v4) > 0 )
    {
      do
      {
        v5 = CChoreoActor::GetChannel(this: v4, channel: (int)e);
        channel = v5;
        if ( CChoreoChannel::GetNumEvents(this: v5) > 0 )
        {
          do
          {
            event = CChoreoChannel::GetEvent(this: v5, event: v3);
            if ( CChoreoEvent::GetType(this: event) == FLEXANIMATION )
            {
              i = 0xFFFF;
              done = false;
              CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
                this: &actorFlexEvents,
                insert: &event,
                parent: (unsigned __int16 *)&i,
                leftchild: &done);
              v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&actorFlexEvents);
              v7 = i;
              v8 = v6;
              v9 = 3 * v6;
              m_pMemory = actorFlexEvents.m_Elements.m_pMemory;
              v11 = 4 * v9;
              *(unsigned __int16 *)((char *)&actorFlexEvents.m_Elements.m_pMemory->m_Right + v11) = -1;
              *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v11) = -1;
              *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v11) = 0;
              *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v11) = v7;
              if ( v7 == 0xFFFF )
              {
                actorFlexEvents.m_Root = v8;
              }
              else
              {
                v12 = v7;
                if ( done )
                  m_pMemory[v12].m_Left = v8;
                else
                  m_pMemory[v12].m_Right = v8;
              }
              CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
                this: &actorFlexEvents,
                elem: v8);
              ++actorFlexEvents.m_NumElements;
              v13 = (CChoreoEvent **)((char *)&actorFlexEvents.m_Elements.m_pMemory->m_Data + v11);
              if ( v13 != nullptr )
                *v13 = event;
              v5 = channel;
            }
            ++v3;
          }
          while ( v3 < CChoreoChannel::GetNumEvents(this: v5) );
          v4 = actor;
        }
        e = (CChoreoEvent *)((char *)e + 1);
        v14 = e;
        v3 = 0;
      }
      while ( (int)v14 < CChoreoActor::GetNumChannels(this: v4) );
    }
    m_Size = 0;
    memset(&rows, 0, sizeof(rows));
    done = false;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &actorFlexEvents);
    if ( i != 0xFFFF )
    {
      while ( !done )
      {
        m_Data = actorFlexEvents.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        e = m_Data;
        if ( m_Size != 0 )
        {
          v17 = 0;
          if ( m_Size <= 0 )
          {
LABEL_26:
            v20 = CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,int>>::InsertBefore(
                    this: &rows,
                    elem: rows.m_Size);
            CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::AddToHead(
              this: &rows.m_Memory.m_pMemory[v20],
              src: &e);
          }
          else
          {
            v18 = rows.m_Memory.m_pMemory;
            while ( EventCollidesWithRows(list: v18, event: m_Data, trackName: offender, trackNameLength: 0x100u) != 0 )
            {
              Name = CChoreoEvent::GetName(this: m_Data);
              v21 = CChoreoActor::GetName(this: actor);
              Filename = CChoreoScene::GetFilename(this: scene);
              _Msg(a1: "[%s] has overlapping events for actor [%s] [%s] [flex: %s]\n", Filename, v21, Name, offender);
              ++v17;
              ++v18;
              done = true;
              if ( v17 >= rows.m_Size )
                goto LABEL_26;
            }
            CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::AddToHead(
              this: v18,
              src: &e);
          }
        }
        else
        {
          CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,int>>::InsertBefore(
            this: &rows,
            elem: 0);
          CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>::AddToHead(
            this: rows.m_Memory.m_pMemory,
            src: &e);
        }
        v3 = 0;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &actorFlexEvents,
                                i);
        if ( i == 0xFFFF )
          break;
        m_Size = rows.m_Size;
      }
    }
    CUtlVector<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,CUtlMemory<CUtlLinkedList<CChoreoEvent *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEvent *,int>,int>>,int>>::RemoveAll(this: &rows);
    if ( rows.m_Memory.m_nGrowSize >= 0 && rows.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rows.m_Memory.m_pMemory);
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &actorFlexEvents);
    if ( actorFlexEvents.m_Elements.m_nGrowSize >= 0 && actorFlexEvents.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: actorFlexEvents.m_Elements.m_pMemory);
    v1 = scene;
    ++a;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004085E0
// Name: public: int CUtlDict<struct VCDList,int>::Insert(char const __near *,struct VCDList const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<VCDList,int>::Insert(CUtlDict<VCDList,int> *this, const char *pName, const VCDList *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,VCDList,int>::Node_t insert; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int> > *p_m_Tree; // [esp+24h] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  memset(&insert.elem, 0, sizeof(insert.elem));
  insert.key = v3;
  VCDList::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         a2: pName,
         &insert);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&insert.elem);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00408680
// Name: void ProcessVCD(class CUtlDict<struct VCDList,int> __near &,class CUtlSymbol __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessVCD(CUtlDict<VCDList,int> *database, CUtlSymbol *vcdname)
{
  const char *v2; // eax
  CChoreoScene *v3; // eax
  CChoreoScene *v4; // esi
  CChoreoEvent *Event; // edi
  ISoundEmitterSystemBase_vtbl *v6; // esi
  const char *Parameters; // eax
  const char *v8; // eax
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int> *m_pMemory; // ecx
  int m_Size; // edx
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *p_vcds; // ecx
  int v13; // eax
  CUtlSymbol *v14; // esi
  char fullwavename[512]; // [esp+Ch] [ebp-43Ch] BYREF
  char fullname[512]; // [esp+20Ch] [ebp-23Ch] BYREF
  CUtlMap<char const *,VCDList,int>::Node_t search; // [esp+40Ch] [ebp-3Ch] BYREF
  VCDList nullEntry; // [esp+424h] [ebp-24h] BYREF
  int c; // [esp+438h] [ebp-10h]
  CChoreoScene *scene; // [esp+43Ch] [ebp-Ch]
  BOOL first; // [esp+440h] [ebp-8h]
  int i; // [esp+444h] [ebp-4h]

  v2 = CUtlSymbolTable::String(this: &g_Analysis.symbols, id: (CUtlSymbol)vcdname->m_Id);
  V_snprintf(pDest: fullname, maxLen: 512, pFormat: "%s", v2);
  LoadScriptFile(filename: fullname, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
  v3 = ChoreoLoadScene(filename: fullname, callback: nullptr, tokenizer: &g_TokenProcessor, pfn: Con_Printf);
  v4 = v3;
  scene = v3;
  if ( v3 != nullptr )
  {
    LOBYTE(first) = 1;
    c = (int)CChoreoScene::GetNumEvents(this: (ConCommandBase *)v3);
    for ( i = 0; i < c; ++i )
    {
      Event = CChoreoScene::GetEvent(this: v4, event: i);
      if ( CChoreoEvent::GetType(this: Event) == MOVETO )
      {
        SpewMoveto(first, vcdname: fullname, e: Event);
        LOBYTE(first) = 0;
      }
      if ( CChoreoEvent::GetType(this: Event) == SPEAK )
      {
        v6 = soundemitter->__vftable;
        Parameters = CChoreoEvent::GetParameters(this: Event);
        v8 = v6->GetWavFileForSound_2(this: soundemitter, a2: Parameters, a3: nullptr);
        if ( v8 != nullptr && *v8 != 0 )
        {
          V_snprintf(pDest: fullwavename, maxLen: 512, pFormat: "%ssound\\%s", gamedir, v8);
          V_FixSlashes(pname: fullwavename, separator: 92);
          memset(&search.elem, 0, sizeof(search.elem));
          search.key = fullwavename;
          v9 = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Find(
                 this: &database->m_Elements.m_Tree,
                 &search);
          CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&search.elem);
          if ( v9 == -1 )
          {
            memset(&nullEntry, 0, sizeof(nullEntry));
            v9 = CUtlDict<VCDList,int>::Insert(this: database, pName: fullwavename, element: &nullEntry);
            CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&nullEntry);
          }
          m_pMemory = database->m_Elements.m_Tree.m_Elements.m_pMemory;
          m_Size = m_pMemory[v9].m_Data.elem.vcds.m_Size;
          p_vcds = &m_pMemory[v9].m_Data.elem.vcds;
          v13 = 0;
          if ( m_Size <= 0 )
            goto LABEL_16;
          v14 = p_vcds->m_Memory.m_pMemory;
          while ( v14->m_Id != vcdname->m_Id )
          {
            ++v13;
            ++v14;
            if ( v13 >= m_Size )
              goto LABEL_16;
          }
          if ( v13 == -1 )
LABEL_16:
            CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(this: p_vcds, elem: m_Size, src: vcdname);
        }
        v4 = scene;
      }
    }
    if ( vcdonly )
      CheckForOverlappingFlexTracks(scene: v4);
    CChoreoScene::~CChoreoScene(this: v4);
    free(pMem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408880
// Name: void CorrelateWavsAndVCDs(class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CorrelateWavsAndVCDs(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *vcdfiles,
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *wavfiles)
{
  int v2; // esi
  int m_Size; // edi
  int j; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  CUtlSymbol *v8; // esi
  const char *v9; // eax
  int v10; // ebx
  CUtlSymbol *m_pMemory; // eax
  int v12; // edi
  VCDList *p_elem; // ebx
  const char *v14; // eax
  int k; // esi
  const char *v16; // eax
  int v17; // eax
  int m; // esi
  const char *v19; // eax
  CUtlDict<VCDList,int> database; // [esp+1Ch] [ebp-44h] BYREF
  CUtlMap<char const *,VCDList,int>::Node_t search; // [esp+40h] [ebp-20h] BYREF
  int c; // [esp+58h] [ebp-8h]
  int i; // [esp+5Ch] [ebp-4h]
  int ecount; // [esp+68h] [ebp+8h]

  v2 = 0;
  m_Size = vcdfiles->m_Size;
  memset(&database.m_Elements.m_Tree.m_Elements, 0, sizeof(database.m_Elements.m_Tree.m_Elements));
  database.m_Elements.m_Tree.m_Root = -1;
  database.m_Elements.m_Tree.m_NumElements = 0;
  database.m_Elements.m_Tree.m_FirstFree = -1;
  database.m_Elements.m_Tree.m_LastAlloc.index = -1;
  database.m_Elements.m_Tree.m_pElements = nullptr;
  database.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  if ( m_Size > 0 )
  {
    do
      ProcessVCD(&database, vcdname: &vcdfiles->m_Memory.m_pMemory[v2++]);
    while ( v2 < m_Size );
  }
  if ( vcdonly )
  {
    for ( j = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::FirstInorder(this: &database.m_Elements.m_Tree);
          j != -1;
          j = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::NextInorder(
                this: &database.m_Elements.m_Tree,
                i: j) )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)database.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
    }
    CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RemoveAll(this: &database.m_Elements.m_Tree);
    CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RemoveAll(this: &database.m_Elements.m_Tree);
    if ( database.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && database.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
LABEL_8:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: database.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
  else
  {
    vprint(depth: 0, fmt: "Found %i wav files in %i vcds\n", database.m_Elements.m_Tree.m_NumElements, vcdfiles->m_Size);
    v5 = wavfiles->m_Size;
    v6 = 0;
    v7 = 0;
    ecount = 0;
    c = v5;
    i = 0;
    if ( v5 > 0 )
    {
      do
      {
        v8 = &wavfiles->m_Memory.m_pMemory[v7];
        v9 = CUtlSymbolTable::String(this: &g_Analysis.symbols, id: (CUtlSymbol)v8->m_Id);
        if ( v9 == nullptr )
          goto LABEL_33;
        memset(&search.elem, 0, sizeof(search.elem));
        search.key = v9;
        v10 = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::Find(
                this: &database.m_Elements.m_Tree,
                &search);
        m_pMemory = search.elem.vcds.m_Memory.m_pMemory;
        search.elem.vcds.m_Size = 0;
        if ( search.elem.vcds.m_Memory.m_nGrowSize >= 0 )
        {
          if ( search.elem.vcds.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.vcds.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            search.elem.vcds.m_Memory.m_pMemory = nullptr;
          }
          search.elem.vcds.m_Memory.m_nAllocationCount = 0;
        }
        search.elem.vcds.m_pElements = m_pMemory;
        if ( search.elem.vcds.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            search.elem.vcds.m_Memory.m_pMemory = nullptr;
          }
          search.elem.vcds.m_Memory.m_nAllocationCount = 0;
        }
        if ( v10 == -1 )
        {
LABEL_33:
          ++ecount;
          v19 = CUtlSymbolTable::String(this: &g_Analysis.symbols, id: (CUtlSymbol)v8->m_Id);
          vprint(depth: 0, fmt: "%i -- '%s' not referenced by .vcd\n", ecount, v19);
        }
        else
        {
          v12 = database.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem.vcds.m_Size;
          p_elem = &database.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem;
          if ( v12 >= 2 && verbose != 0 )
          {
            v14 = CUtlSymbolTable::String(this: &g_Analysis.symbols, id: (CUtlSymbol)v8->m_Id);
            vprint(depth: 0, fmt: " wave '%s' used by multiple .vcds:\n", v14);
            for ( k = 0; k < v12; vprint(depth: 1, fmt: "%i -- '%s'\n", k, v16) )
              v16 = CUtlSymbolTable::String(this: &g_Analysis.symbols, id: p_elem->vcds.m_Memory.m_pMemory[k++]);
          }
        }
        v5 = c;
        v7 = i + 1;
        i = v7;
      }
      while ( v7 < c );
      v6 = ecount;
    }
    v17 = v5;
    if ( v5 <= 1 )
      v17 = 1;
    vprint(
      depth: 0,
      fmt: "\nSummary:  found %i/%i (%.2f percent) .wav errors\n",
      v6,
      v5,
      (double)v6 * 100.0 / (double)v17);
    for ( m = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::FirstInorder(this: &database.m_Elements.m_Tree);
          m != -1;
          m = CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::NextInorder(
                this: &database.m_Elements.m_Tree,
                i: m) )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)database.m_Elements.m_Tree.m_Elements.m_pMemory[m].m_Data.key);
    }
    CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RemoveAll(this: &database.m_Elements.m_Tree);
    CUtlRBTree<CUtlMap<char const *,VCDList,int>::Node_t,int,CUtlMap<char const *,VCDList,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,VCDList,int>::Node_t,int>,int>>::RemoveAll(this: &database.m_Elements.m_Tree);
    if ( database.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && database.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408BA0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int i; // edi
  const char *v4; // eax
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  char *v8; // eax
  char *v9; // edx
  char v10; // cl
  int v11; // eax
  int v13; // eax
  struct CSysModule *v14; // eax
  struct CSysModule *v15; // edi
  void *(__cdecl *Factory)(const char *, int *); // eax
  void *(__cdecl *FileSystemFactory)(const char *, int *); // eax
  ISoundEmitterSystemBase_vtbl *v18; // esi
  void *(__cdecl *v19)(const char *, int *); // eax
  int v20; // eax
  char workingdir[256]; // [esp+Ch] [ebp-328h] BYREF
  char sounddir[256]; // [esp+10Ch] [ebp-228h] BYREF
  char vcddir[256]; // [esp+20Ch] [ebp-128h] BYREF
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > vcdfiles; // [esp+30Ch] [ebp-28h] BYREF
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > wavfiles; // [esp+320h] [ebp-14h] BYREF

  for ( i = 1; i < argc; ++i )
  {
    v4 = argv[i];
    if ( *v4 == 45 )
    {
      switch ( v4[1] )
      {
        case 'l':
          uselogfile = true;
          continue;
        case 'm':
          spewmoveto = true;
          continue;
        case 'o':
          vcdonly = true;
          continue;
        case 'v':
          verbose = 1;
          continue;
        default:
          goto LABEL_31;
      }
    }
  }
  if ( argc < 3 || i != argc )
  {
    vprint(depth: 0, fmt: "Valve Software - vcd_sound_check.exe (%s)\n", "Dec 28 2010");
    vprint(depth: 0, fmt: "--- Voice Wav File .vcd Checker ---\n");
LABEL_31:
    printusage();
  }
  if ( uselogfile )
  {
    _unlink(path: "log.txt");
    vprint(depth: 0, fmt: "    Outputting to log.txt\n");
  }
  vprint(depth: 0, fmt: "Valve Software - vcd_sound_check.exe (%s)\n", "Dec 28 2010");
  vprint(depth: 0, fmt: "--- Voice Wav File .vcd Checker ---\n");
  vprint(depth: 0, fmt: "    Looking for .wav files not referenced in .vcd files...\n");
  v5 = (char *)argv[i - 2];
  v6 = (char *)(sounddir - v5);
  do
  {
    v7 = *v5;
    v5[(_DWORD)v6] = *v5;
    ++v5;
  }
  while ( v7 != 0 );
  v8 = (char *)argv[i - 1];
  v9 = (char *)(vcddir - v8);
  do
  {
    v10 = *v8;
    v8[(_DWORD)v9] = *v8;
    ++v8;
  }
  while ( v10 != 0 );
  strstr(str1: (unsigned __int8 *)sounddir, str2: "sound");
  if ( v11 != 0 )
  {
    strstr(str1: (unsigned __int8 *)vcddir, str2: "scenes");
    if ( v13 != 0 )
    {
      workingdir[0] = 0;
      Q_getwd(out: workingdir, outSize: 256);
      CmdLib_InitFileSystem(pFilename: workingdir, maxMemoryUsage: 0);
      v14 = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "soundemittersystem.dll", a3: 0, a4: 1);
      v15 = v14;
      if ( v14 != nullptr )
      {
        Factory = Sys_GetFactory(pModule: v14);
        if ( Factory != nullptr )
        {
          soundemitter = (ISoundEmitterSystemBase *)Factory(a1: "VSoundEmitter003", a2: nullptr);
          if ( soundemitter != nullptr )
          {
            FileSystemFactory = CmdLib_GetFileSystemFactory();
            filesystem = (IFileSystem *)FileSystemFactory(a1: "VFileSystem017", a2: nullptr);
            if ( filesystem != nullptr )
            {
              V_FixSlashes(pname: gamedir, separator: 92);
              _V_strlower(start: gamedir);
              vprint(depth: 0, fmt: "game dir %s\nsounds dir %s\nvcd dir %s\n\n", gamedir, sounddir, vcddir);
              V_StripTrailingSlash(ppath: sounddir);
              V_StripTrailingSlash(ppath: vcddir);
              filesystem->RemoveFile(this: filesystem, a2: "moveto.txt", a3: "GAME");
              vprint(depth: 0, fmt: "Initializing sound emitter system\n");
              v18 = soundemitter->__vftable;
              v19 = FileSystem_GetFactory();
              v18->Connect(this: soundemitter, a2: v19);
              soundemitter->Init(this: soundemitter);
              v20 = soundemitter->GetSoundCount(this: soundemitter);
              vprint(depth: 0, fmt: "Loaded %i sounds\n", v20);
              vprint(depth: 0, fmt: "Building list of .vcd files\n");
              memset(&vcdfiles, 0, sizeof(vcdfiles));
              BuildFileList_R(files: &vcdfiles, dir: vcddir, extension: ".vcd");
              vprint(depth: 0, fmt: "found %i .vcd files\n\n", vcdfiles.m_Size);
              vprint(depth: 0, fmt: "Building list of known .wav files\n");
              memset(&wavfiles, 0, sizeof(wavfiles));
              BuildFileList_R(files: &wavfiles, dir: sounddir, extension: ".wav");
              vprint(depth: 0, fmt: "found %i .wav files\n\n", wavfiles.m_Size);
              CorrelateWavsAndVCDs(&vcdfiles, &wavfiles);
              soundemitter->Shutdown(this: soundemitter);
              soundemitter = nullptr;
              g_pFullFileSystem->UnloadModule(this: g_pFullFileSystem, a2: v15);
              FileSystem_Term();
              CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&wavfiles);
              CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&vcdfiles);
              return 0;
            }
            else
            {
              return 1;
            }
          }
          else
          {
            vprint(depth: 0, fmt: "Couldn't get interface %s from soundemittersystem.dll!\n", "VSoundEmitter003");
            return 0;
          }
        }
        else
        {
          vprint(depth: 0, fmt: "Sys_GetFactory on soundemittersystem.dll failed!\n");
          return 0;
        }
      }
      else
      {
        vprint(depth: 0, fmt: "Sys_LoadModule( soundemittersystem.dll ) failed!\n");
        return 0;
      }
    }
    else
    {
      vprint(depth: 0, fmt: ".vcd dir %s looks invalid (format:  u:/tf2/hl2/scenes)\n", vcddir);
      return 0;
    }
  }
  else
  {
    vprint(depth: 0, fmt: "Sound dir %s looks invalid (format:  u:/tf2/hl2/sound/vo)\n", sounddir);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004097D0
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
// Address: 0x00409870
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
// Address: 0x0040A1F0
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
// Address: 0x0040A420
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
// Address: 0x0040A490
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
    CUtlMemory<fileList_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *)this,
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
// Address: 0x0040A520
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
// Address: 0x0040A5C0
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
// Address: 0x0040A940
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
// Address: 0x0040AE30
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
// Address: 0x0040B440
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

//------------------------------------------------------------------------------
// Address: 0x0040B4D0
// Name: public: void CUtlMemory<struct fileList_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<fileList_t,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: m_pMemory,
                                                                                        a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B970
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( i == -1 )
    return dword_465EE0;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0040B9D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( i == -1 )
    return dword_465EDC;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040BA30
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( m_Parent == -1 )
    return dword_465EDC == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0040BAE0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,int,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,int,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BBD0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NewNode@<eax>(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this@<ecx>,
        const char *a2@<edi>)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v12; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v6 = index + 1;
      if ( v6 < 0 || v6 >= m_nAllocationCount )
        v6 = -1;
    }
    v7 = v6;
    if ( v6 < 0 || v6 >= m_nAllocationCount )
    {
      CUtlMemory<fileList_t,int>::Grow(this: &this->m_Elements, num: 1);
      v8 = this->m_LastAlloc.index;
      if ( v8 < 0 || (v9 = this->m_Elements.m_nAllocationCount, v8 >= v9) )
      {
        v9 = this->m_Elements.m_nAllocationCount;
        v10 = (v9 > 0) - 1;
      }
      else
      {
        v10 = v8 + 1;
        if ( v10 < 0 || v10 >= v9 )
          v10 = -1;
      }
      v7 = v10;
      if ( v10 < 0 || v10 >= v9 )
        _Error(this: (ISceneTokenProcessor *)&stru_42F0F4, a2);
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v7;
    this->m_pElements = m_pMemory;
    return v7;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[result].m_Right;
    this->m_pElements = v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BC90
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0040BD40
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_465EDC = -1;
      dword_465EE0 = -1;
      dword_465EE4 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040BEF0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0040C1C0
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
// Address: 0x0040C240
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,int,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,int,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0040C330
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EDC = -1;
            dword_465EE0 = -1;
            dword_465EE4 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C3F0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_465EDC = -1;
      dword_465EE0 = -1;
      dword_465EE4 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_465EDC = -1;
      dword_465EE0 = -1;
      dword_465EE4 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C490
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_465EDC = -1;
    dword_465EE0 = -1;
    dword_465EE4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EDC = -1;
          dword_465EE0 = -1;
          dword_465EE4 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C600
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_465EDC = -1;
        dword_465EE0 = -1;
        dword_465EE4 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EDC = -1;
          dword_465EE0 = -1;
          dword_465EE4 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EDC = -1;
          dword_465EE0 = -1;
          dword_465EE4 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EDC = -1;
            dword_465EE0 = -1;
            dword_465EE4 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EDC = -1;
            dword_465EE0 = -1;
            dword_465EE4 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EDC = -1;
          dword_465EE0 = -1;
          dword_465EE4 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_465EDC = -1;
          dword_465EE0 = -1;
          dword_465EE4 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EDC = -1;
            dword_465EE0 = -1;
            dword_465EE4 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_465EDC = -1;
            dword_465EE0 = -1;
            dword_465EE4 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040F340
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0040F3A0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F470
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *__thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory;
  else
    return (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040F4D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,EventGroup,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F5C0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
bool (__cdecl *__thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this))(const char *const *, const char *const *)
{
  int m_Root; // ebx
  bool (__cdecl *result)(const char *const *, const char *const *); // eax
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v3; // edx

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  result = (bool (__cdecl *)(const char *const *, const char *const *))this->m_Root;
  while ( 1 )
  {
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    v3 = result == (bool (__cdecl *)(const char *const *, const char *const *))-1
       ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
    if ( v3->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
      break;
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( result == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
      result = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc;
    else
      result = (bool (__cdecl *)(const char *const *, const char *const *))this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F660
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory == (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0040F710
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0040F7C0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v4; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v9; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v10; // eax
  int v11; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v8 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
       | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v9 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Right];
  if ( v9->m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v8 | 1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( m_Right == -1 )
      v10 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v10->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v11 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v11].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040F990
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v4; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v7; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[(_DWORD)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RightChild(
                                         this,
                                         i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0040FB10
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,EventGroup,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0040FC00
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *__thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v3; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *result; // eax
  int m_Root; // edx
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v6; // ecx
  int m_Parent; // esi
  int v8; // [esp-4h] [ebp-10h]

  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v8 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
    while ( 1 )
    {
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v6 = result == (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1
         ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
      if ( v6->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( result == (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1 )
        result = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc;
      else
        result = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FD80
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v5; // eax
  int m_Parent; // eax
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v8; // eax
  int v9; // esi
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v10; // eax
  int m_nAllocationCount; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v18; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v20; // eax
  int m_Left; // eax
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v22; // ecx
  int v23; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v24; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v25; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
               | 1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Elements.m_nGrowSize != 0 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v10 = v9 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[v9];
      m_nAllocationCount = v10->m_Elements.m_nAllocationCount;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_nAllocationCount == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_nAllocationCount];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v16 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Elements.m_nGrowSize != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateLeft(
              this,
              elem: v9);
            v17 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
            if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                & 1) == 0 )
            {
              v17 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v18 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v18 = &this->m_Elements.m_pMemory[v9];
            v9 = v18->m_Parent;
            if ( (v17 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v17 | 1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v19 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v19 = &this->m_Elements.m_pMemory[v9];
            m_nAllocationCount = v19->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: m_nAllocationCount);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          elem = m_nAllocationCount;
        }
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_nAllocationCount == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_nAllocationCount];
        m_Left = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v22 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Left];
        if ( v22->m_Elements.m_nGrowSize != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v23 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
            if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                & 1) == 0 )
            {
              v23 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v9 = v24->m_Parent;
            if ( (v23 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v23 | 1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v25 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v25 = &this->m_Elements.m_pMemory[v9];
            m_nAllocationCount = v25->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: m_nAllocationCount);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          elem = m_nAllocationCount;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00410250
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410330
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NewNode@<eax>(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this@<ecx>,
        const char *a2@<edi>)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlMap<char const *,EventGroup,int>::Node_t *p_m_Data; // ecx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v6 = index + 1;
      if ( v6 < 0 || v6 >= m_nAllocationCount )
        v6 = -1;
    }
    v7 = v6;
    if ( v6 < 0 || v6 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v8 = this->m_LastAlloc.index;
      if ( v8 < 0 || (v9 = this->m_Elements.m_nAllocationCount, v8 >= v9) )
      {
        v9 = this->m_Elements.m_nAllocationCount;
        v10 = (v9 > 0) - 1;
      }
      else
      {
        v10 = v8 + 1;
        if ( v10 < 0 || v10 >= v9 )
          v10 = -1;
      }
      v7 = v10;
      if ( v10 < 0 || v10 >= v9 )
        _Error(this: (ISceneTokenProcessor *)&stru_42F0F4, a2);
    }
    this->m_LastAlloc.index = v7;
    result = v7;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result].m_Right;
  }
  p_m_Data = &this->m_Elements.m_pMemory[result].m_Data;
  if ( &this->m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-16 )
  {
    this->m_Elements.m_pMemory[result].m_Data.elem.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
    p_m_Data->elem.timeSortedEvents.m_Elements.m_pMemory = nullptr;
    p_m_Data->elem.timeSortedEvents.m_Elements.m_nAllocationCount = 0;
    p_m_Data->elem.timeSortedEvents.m_Elements.m_nGrowSize = 0;
    p_m_Data->elem.timeSortedEvents.m_Root = -1;
    p_m_Data->elem.timeSortedEvents.m_NumElements = 0;
    p_m_Data->elem.timeSortedEvents.m_FirstFree = -1;
    p_m_Data->elem.timeSortedEvents.m_LastAlloc.index = -1;
    p_m_Data->elem.timeSortedEvents.m_pElements = p_m_Data->elem.timeSortedEvents.m_Elements.m_pMemory;
  }
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410910
// Name: public: int CUtlDict<struct EventGroup,int>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Find(CUtlDict<EventGroup,int> *this, const char *pName)
{
  int v2; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t search; // [esp+0h] [ebp-20h] BYREF

  if ( pName == nullptr )
    return -1;
  search.elem.timeSortedEvents.m_Root = -1;
  memset(&search.elem.timeSortedEvents.m_Elements, 0, sizeof(search.elem.timeSortedEvents.m_Elements));
  search.elem.timeSortedEvents.m_pElements = nullptr;
  search.elem.timeSortedEvents.m_NumElements = 0;
  search.elem.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  search.elem.timeSortedEvents.m_FirstFree = -1;
  search.elem.timeSortedEvents.m_LastAlloc.index = -1;
  search.key = pName;
  v2 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &search.elem.timeSortedEvents);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00410980
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0 && v4 < this->m_Elements.m_nAllocationCount && v4 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( this->m_Elements.m_pMemory[v4].m_Left != v4 )
          {
            CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &this->m_Elements.m_pMemory[v4].m_Data.elem.timeSortedEvents);
            this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v4].m_Left = v4;
            this->m_FirstFree = v4;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410A50
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert@<eax>(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this@<ecx>,
        const char *a2@<edi>,
        const CUtlMap<char const *,EventGroup,int>::Node_t *insert)
{
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v4 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NewNode(
         this,
         a2);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v4,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-16 )
  {
    m_pMemory[v4].m_Data.key = insert->key;
    EventGroup::EventGroup(this: &m_pMemory[v4].m_Data.elem, src: &insert->elem);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00410AC0
// Name: public: void CUtlDict<struct EventGroup,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<EventGroup,int>::RemoveAll(CUtlDict<EventGroup,int> *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi

  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00410B10
// Name: public: int CUtlDict<struct EventGroup,int>::Insert(char const __near *,struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Insert(
        CUtlDict<EventGroup,int> *this,
        const char *pName,
        const EventGroup *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t insert; // [esp+Ch] [ebp-24h] BYREF
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *p_m_Tree; // [esp+2Ch] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  insert.key = v3;
  insert.elem.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&insert.elem.timeSortedEvents.m_Elements, 0, sizeof(insert.elem.timeSortedEvents.m_Elements));
  *(_DWORD *)&insert.elem.timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&insert.elem.timeSortedEvents.m_FirstFree = -1;
  insert.elem.timeSortedEvents.m_pElements = nullptr;
  EventGroup::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         a2: pName,
         &insert);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &insert.elem.timeSortedEvents);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00414A90
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
// Address: 0x00414B40
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode@<eax>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this@<ecx>,
        const char *a2@<edi>)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // di
  int v8; // eax
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v13; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v6 = -1;
      else
        v6 = index + 1;
    }
    v7 = v6;
    if ( v6 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>::Grow(this: &this->m_Elements, num: 1);
      v8 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v8 )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v10 = (v8 > 0) - 1;
      }
      else
      {
        v9 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v9 + 1) >= v8 )
          v10 = -1;
        else
          v10 = v9 + 1;
      }
      v7 = v10;
      if ( v10 >= v8 )
        _Error(this: (ISceneTokenProcessor *)&stru_42F0F4, a2);
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v7;
    this->m_pElements = m_pMemory;
    return v7;
  }
  else
  {
    v13 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v13[m_FirstFree].m_Right;
    this->m_pElements = v13;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414C40
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_476BB0 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_476BB0;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00414DC0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_476BB0 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00414E20
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_476BB0 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00414E90
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_476BB0 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_476BB0 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414F80
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00415080
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x004151C0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_476BB0 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_476BB0 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004152C0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415380
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_476BB0 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_476BB0 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_476BB0 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_476BB0 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_476BB0 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_476BB0 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_476BB0 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_476BB0 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_476BB0 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_476BB0 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_476BB0 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_476BB0 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_476BB0 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_476BB0 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415930
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415A30
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415AC0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert@<ax>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this@<ecx>,
        const char *a2@<edi>,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
         this,
         a2);
  v5 = v4;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v5].m_Data = *insert;
  return v5;
}
