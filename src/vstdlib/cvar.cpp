// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/cvar.cpp
// Functions: 78
// ============================================================

#include "vstdlib\cvar.h"

//------------------------------------------------------------------------------
// Address: 0x10001D80
// Name: _VStdLib_GetICVarFactory
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void *(__cdecl *__cdecl VStdLib_GetICVarFactory())(const char *, int *)
{
  return Sys_GetFactoryThis();
}

//------------------------------------------------------------------------------
// Address: 0x10001D90
// Name: public: virtual bool CCvar::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvar::Connect(CCvar *this, void *(__cdecl *factory)(const char *, int *))
{
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  s_pCVarQuery = (ICvarQuery *)factory(a1: "VCvarQuery001", a2: nullptr);
  if ( s_pCVarQuery == nullptr )
    s_pCVarQuery = &s_DefaultCvarQuery;
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001DD0
// Name: public: virtual void CCvar::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::Disconnect(CCvar *this)
{
  ConVar_Unregister();
  s_pCVarQuery = nullptr;
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10001DF0
// Name: public: virtual void __near * CCvar::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCvar *__thiscall CCvar::QueryInterface(CCvar *this, const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VEngineCvar007") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001E20
// Name: public: virtual void CCvar::InstallCVarQuery(class ICvarQuery __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::InstallCVarQuery(CCvar *this, ICvarQuery *pQuery)
{
  s_pCVarQuery = pQuery;
  if ( pQuery == nullptr )
    s_pCVarQuery = &s_DefaultCvarQuery;
}

//------------------------------------------------------------------------------
// Address: 0x10001E40
// Name: public: virtual int CCvar::AllocateDLLIdentifier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvar::AllocateDLLIdentifier(CCvar *this)
{
  int result; // eax

  result = this->m_nNextDLLIdentifier;
  this->m_nNextDLLIdentifier = result + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001E50
// Name: public: virtual class ConVar const __near * CCvar::FindVar(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const ConVar *__thiscall CCvar::FindVar(CCvar *this, const char *var_name)
{
  const ConVar *result; // eax

  result = (const ConVar *)this->FindCommandBase(this, a2: var_name);
  if ( result != nullptr )
    return !result->IsCommand(this: result) ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001E90
// Name: public: virtual class ConVar __near * CCvar::FindVar(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ConVar *__thiscall CCvar::FindVar(CCvar *this, const char *var_name)
{
  ConVar *result; // eax

  result = (ConVar *)this->FindCommandBase_2(this, a2: var_name);
  if ( result != nullptr )
    return !result->IsCommand(this: result) ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001ED0
// Name: public: virtual class ConCommand const __near * CCvar::FindCommand(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const ConCommand *__thiscall CCvar::FindCommand(CCvar *this, const char *pCommandName)
{
  const ConCommandBase *v2; // eax
  const ConCommandBase *v3; // esi

  v2 = this->FindCommandBase(this, a2: pCommandName);
  v3 = v2;
  if ( v2 != nullptr && v2->IsCommand(this: (ConCommandBase *)v2) )
    return (const ConCommand *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001F00
// Name: public: virtual class ConCommand __near * CCvar::FindCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ConCommand *__thiscall CCvar::FindCommand(CCvar *this, const char *pCommandName)
{
  ConCommandBase *v2; // eax
  ConCommandBase *v3; // esi

  v2 = this->FindCommandBase_2(this, a2: pCommandName);
  v3 = v2;
  if ( v2 != nullptr && v2->IsCommand(this: v2) )
    return (ConCommand *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: public: virtual char const __near * CCvar::GetCommandLineValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCvar::GetCommandLineValue(CCvar *this, char *pVariableName)
{
  int v2; // edi
  void *v3; // esp
  int v4; // eax
  char v6; // [esp+0h] [ebp-Ch] BYREF
  unsigned __int8 v7[11]; // [esp+1h] [ebp-Bh] BYREF

  v2 = _V_strlen(str: pVariableName);
  v3 = alloca(v2 + 2);
  v6 = 43;
  memcpy(dst: v7, src: (unsigned __int8 *)pVariableName, count: v2 + 1);
  v4 = _CommandLine();
  return (*(const char *(__thiscall **)(int, char *, _DWORD))(*(_DWORD *)v4 + 32))(a1: v4, a2: &v6, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001F80
// Name: public: virtual bool CCvar::IsMaterialThreadSetAllowed(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCvar::IsMaterialThreadSetAllowed(CCvar *this)
{
  return this->m_bMaterialSystemThreadSetAllowed;
}

//------------------------------------------------------------------------------
// Address: 0x10001F90
// Name: ConVarSortFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConVarSortFunc(ConCommandBase *const *lhs, ConCommandBase *const *rhs)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)rhs + 24))(a1: *rhs);
  v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)lhs + 24))(a1: *lhs);
  if ( v3 == nullptr )
    return false;
  if ( v2 != nullptr )
    return _V_stricmp(s1: v3, s2: v2) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10001FE0
// Name: public: virtual void CCvar::SetMaxSplitScreenSlots(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::SetMaxSplitScreenSlots(CCvar *this, int nSlots)
{
  CCvar_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_nMaxSplitScreenSlots = nSlots;
  ((void (*)(void))v2->AddSplitScreenConVars)();
}

//------------------------------------------------------------------------------
// Address: 0x10002000
// Name: public: virtual int CCvar::GetMaxSplitScreenSlots(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvar::GetMaxSplitScreenSlots(CCvar *this)
{
  return this->m_nMaxSplitScreenSlots;
}

//------------------------------------------------------------------------------
// Address: 0x10002010
// Name: public: virtual void CConCommandMemberAccessor<class CCvar>::CommandCallback(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandMemberAccessor<CCvar>::CommandCallback(
        CConCommandMemberAccessor<CCvar> *this,
        const CCommand *command)
{
  ((void (__thiscall *)(_DWORD, const CCommand *))this->m_pszName)(a1: *(_DWORD *)&this->m_bRegistered, a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x10002020
// Name: public: virtual int CConCommandMemberAccessor<class CCvar>::CommandCompletionCallback(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConCommandMemberAccessor<CCvar>::CommandCompletionCallback(
        CConCommandMemberAccessor<CCvar> *this,
        const char *pPartial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  return ((int (__thiscall *)(ConCommandBase *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))this->m_pszName)(
           a1: this->m_pNext,
           a2: pPartial,
           a3: commands);
}

//------------------------------------------------------------------------------
// Address: 0x10002050
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10002130
// Name: protected: virtual class ICvar::ICVarIteratorInternal __near * CCvar::FactoryInternalIterator(void)
// Source: json
//------------------------------------------------------------------------------
ICvar::ICVarIteratorInternal *__thiscall CCvar::FactoryInternalIterator(CCvar *this)
{
  ICvar::ICVarIteratorInternal *result; // eax

  result = (ICvar::ICVarIteratorInternal *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = (ICvar::ICVarIteratorInternal_vtbl *)this;
  result[2].__vftable = (ICvar::ICVarIteratorInternal_vtbl *)&this->m_CommandHash;
  result->__vftable = (ICvar::ICVarIteratorInternal_vtbl *)&CCvar::CCVarIteratorInternal::`vftable';
  result[3].__vftable = (ICvar::ICVarIteratorInternal_vtbl *)-1;
  result[4].__vftable = (ICvar::ICVarIteratorInternal_vtbl *)-1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002160
// Name: public: virtual bool CCvar::HasQueuedMaterialThreadConVarSets(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCvar::HasQueuedMaterialThreadConVarSets(CCvar *this)
{
  return this->m_QueuedConVarSets.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002170
// Name: public: virtual int CCvar::GetConsoleDisplayFuncCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvar::GetConsoleDisplayFuncCount(CCvar *this)
{
  return this->m_DisplayFuncs.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10002180
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 0xFFu, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10002270
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
// Address: 0x10002410
// Name: public: void CUtlMemory<struct CCvar::QueuedConVarSet_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CCvar::QueuedConVarSet_t,int>::Grow(CUtlMemory<CCvar::QueuedConVarSet_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CCvar::QueuedConVarSet_t *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CCvar::QueuedConVarSet_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CCvar::QueuedConVarSet_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002540
// Name: public: CSplitScreenAddedConVar::CSplitScreenAddedConVar(int,char const __near *,class ConVar const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall CSplitScreenAddedConVar::CSplitScreenAddedConVar(
        CSplitScreenAddedConVar *this,
        int nSplitScreenSlot,
        const char *pName,
        const ConVar *pBaseVar)
{
  const char *Default; // eax
  ConVar *m_pParent; // eax
  int i; // ebx
  unsigned int v10; // [esp-Ch] [ebp-24h]
  const char *v11; // [esp-8h] [ebp-20h]
  bool HasMin; // [esp-4h] [ebp-1Ch]
  float fMin; // [esp+0h] [ebp-18h]
  bool HasMax; // [esp+4h] [ebp-14h]
  float fMax; // [esp+8h] [ebp-10h]

  fMax = ConVar::GetMaxValue(this: pBaseVar);
  HasMax = ConVar::HasMax(this: pBaseVar);
  fMin = ConVar::GetMinValue(this: pBaseVar);
  HasMin = ConVar::HasMin(this: pBaseVar);
  v11 = pBaseVar->GetHelpText(this: pBaseVar);
  v10 = pBaseVar->GetFlags(this: pBaseVar) & 0xFFFB7FFF | 0x40000;
  Default = ConVar::GetDefault(this: pBaseVar);
  ConVar::ConVar(
    this,
    pName,
    pDefaultValue: Default,
    flags: v10,
    pHelpString: v11,
    bMin: HasMin,
    fMin,
    bMax: HasMax,
    fMax);
  this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&CSplitScreenAddedConVar::`vftable'{for `ConCommandBase'};
  this->ConVar::IConVar::__vftable = (IConVar_vtbl *)&CSplitScreenAddedConVar::`vftable'{for `IConVar'};
  this->m_pBaseVar = pBaseVar;
  this->m_nSplitScreenSlot = nSplitScreenSlot;
  m_pParent = pBaseVar->m_pParent;
  for ( i = 0; i < m_pParent->m_fnChangeCallbacks.m_Size; ++i )
  {
    ConVar::InstallChangeCallback(this, callback: m_pParent->m_fnChangeCallbacks.m_Memory.m_pMemory[i], bInvoke: false);
    m_pParent = pBaseVar->m_pParent;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100025F0
// Name: public: virtual char const __near * CSplitScreenAddedConVar::GetBaseName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSplitScreenAddedConVar::GetBaseName(CSplitScreenAddedConVar *this)
{
  return (*(const char *(__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(this->m_fMaxVal) + 24))(a1: LODWORD(this->m_fMaxVal));
}

//------------------------------------------------------------------------------
// Address: 0x10002600
// Name: public: virtual int CSplitScreenAddedConVar::GetSplitScreenPlayerSlot(void)const
// Source: json
//------------------------------------------------------------------------------
void (__cdecl **__thiscall CSplitScreenAddedConVar::GetSplitScreenPlayerSlot(
        CSplitScreenAddedConVar *this))(IConVar *, const char *, float)
{
  return this->m_fnChangeCallbacks.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100026C0
// Name: public: struct CConCommandHash::CCommandHashIterator_t CConCommandHash::Next(struct CConCommandHash::CCommandHashIterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CConCommandHash::CCommandHashIterator_t *__thiscall CConCommandHash::Next(
        CConCommandHash *this,
        CConCommandHash::CCommandHashIterator_t *result,
        const CConCommandHash::CCommandHashIterator_t *iter)
{
  int v3; // edx
  int m_Size; // esi
  int v6; // edx
  int *v7; // eax
  int v8; // ecx

  v3 = *(_DWORD *)(iter->handle + 12);
  if ( v3 != 0 )
  {
    result->bucket = iter->bucket;
    result->handle = v3;
    return result;
  }
  else
  {
    m_Size = this->m_aBuckets.m_Size;
    v6 = iter->bucket + 1;
    if ( v6 >= m_Size )
    {
LABEL_7:
      result->bucket = -1;
      result->handle = 0;
      return result;
    }
    else
    {
      v7 = &this->m_aBuckets.m_Memory.m_pMemory[v6];
      while ( 1 )
      {
        v8 = *v7;
        if ( *v7 != 0 )
          break;
        ++v6;
        ++v7;
        if ( v6 >= m_Size )
          goto LABEL_7;
      }
      result->bucket = v6;
      result->handle = v8;
      return result;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002720
// Name: public: virtual void CCvar::CCVarIteratorInternal::SetFirst(void)restrict
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::CCVarIteratorInternal::SetFirst(CCvar::CCVarIteratorInternal *this)
{
  CConCommandHash *m_pHash; // edx
  int m_Size; // edi
  int v3; // eax
  int *m_pMemory; // edx
  int v5; // esi

  m_pHash = this->m_pHash;
  m_Size = m_pHash->m_aBuckets.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
    v5 = 0;
  }
  else
  {
    m_pMemory = m_pHash->m_aBuckets.m_Memory.m_pMemory;
    while ( 1 )
    {
      v5 = *m_pMemory;
      if ( *m_pMemory != 0 )
        break;
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  this->m_hashIter.handle = v5;
  this->m_hashIter.bucket = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10002750
// Name: public: virtual void CCvar::CCVarIteratorInternal::Next(void)restrict
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::CCVarIteratorInternal::Next(CCvar::CCVarIteratorInternal *this)
{
  CConCommandHash::CCommandHashIterator_t *p_m_hashIter; // esi
  CConCommandHash::CCommandHashIterator_t *v2; // eax
  int handle; // edx
  CConCommandHash::CCommandHashIterator_t result; // [esp+4h] [ebp-8h] BYREF

  p_m_hashIter = &this->m_hashIter;
  v2 = CConCommandHash::Next(this: this->m_pHash, &result, iter: &this->m_hashIter);
  handle = v2->handle;
  p_m_hashIter->bucket = v2->bucket;
  p_m_hashIter->handle = handle;
}

//------------------------------------------------------------------------------
// Address: 0x10002780
// Name: public: virtual bool CCvar::CCVarIteratorInternal::IsValid(void)restrict
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCvar::CCVarIteratorInternal::IsValid(CCvar::CCVarIteratorInternal *this)
{
  int handle; // eax
  BOOL result; // eax

  result = false;
  if ( this->m_hashIter.bucket >= 0 )
  {
    handle = this->m_hashIter.handle;
    if ( handle != 0 && (*(_DWORD *)(handle + 8) != handle || *(_DWORD *)(handle + 12) == handle) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100027A0
// Name: public: virtual void CCvar::CallGlobalChangeCallbacks(class ConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::CallGlobalChangeCallbacks(CCvar *this, ConVar *var, const char *pOldString, float flOldValue)
{
  int m_Size; // ebx
  int i; // esi
  IConVar *v7; // eax

  m_Size = this->m_GlobalChangeCallbacks.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( var != nullptr )
      v7 = &var->IConVar;
    else
      v7 = nullptr;
    ((void (__cdecl *)(IConVar *, const char *, _DWORD))this->m_GlobalChangeCallbacks.m_Memory.m_pMemory[i])(
      a1: v7,
      a2: pOldString,
      a3: LODWORD(flOldValue));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100027F0
// Name: public: virtual void CCvar::GetConsoleText(int,char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::GetConsoleText(CCvar *this, int nDisplayFuncIndex, char *pchText, unsigned int bufSize)
{
  IConsoleDisplayFunc *v4; // ecx

  v4 = this->m_DisplayFuncs.m_Memory.m_pMemory[nDisplayFuncIndex];
  v4->GetConsoleText(this: v4, a2: pchText, a3: bufSize);
}

//------------------------------------------------------------------------------
// Address: 0x10002810
// Name: private: int CConCommandHash::Find(char const __near *,unsigned int)const restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConCommandHash::Find(CConCommandHash *this, const char *name, unsigned int hashkey)
{
  int v3; // esi
  const char *v4; // eax

  v3 = this->m_aBuckets.m_Memory.m_pMemory[(unsigned __int8)hashkey];
  if ( v3 == 0 )
    return -1;
  while ( 1 )
  {
    if ( *(_DWORD *)v3 == hashkey )
    {
      v4 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v3 + 4) + 24))(a1: *(_DWORD *)(v3 + 4));
      if ( _V_stricmp(s1: name, s2: v4) == 0 )
        break;
    }
    v3 = *(_DWORD *)(v3 + 12);
    if ( v3 == 0 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10002870
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
// Address: 0x100028B0
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
// Address: 0x100028F0
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
// Address: 0x100035D0
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
// Address: 0x10003620
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
// Address: 0x10003680
// Name: public: virtual void __near * CDefaultCvarQuery::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDefaultCvarQuery *__thiscall CDefaultCvarQuery::QueryInterface(CDefaultCvarQuery *this, const char *pInterfaceName)
{
  return _V_stricmp(s1: pInterfaceName, s2: "VCvarQuery001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100036B0
// Name: public: virtual bool CDefaultCvarQuery::AreConVarsLinkable(class ConVar const __near *,class ConVar const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDefaultCvarQuery::AreConVarsLinkable(
        CDefaultCvarQuery *this,
        const ConVar *child,
        const ConVar *parent)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100036D0
// Name: public: virtual class ConCommandBase const __near * CCvar::FindCommandBase(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const ConCommandBase *__thiscall CCvar::FindCommandBase(CCvar *this, const char *name)
{
  unsigned int v3; // eax
  int v4; // eax
  int v6; // esi

  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    counter.m_pCounter = CVProfile::FindOrCreateCounter(
                           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                           a2: "CCvar::FindCommandBase",
                           a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CCvar::FindCommandBase_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter.m_pCounter;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCvar::FindCommandBase",
    a3: 0,
    a4: "Cvar_Find",
    a5: false,
    a6: 4);
  v3 = HashStringCaseless(pszKey: name);
  v4 = CConCommandHash::Find(this: &this->m_CommandHash, name, hashkey: v3);
  if ( v4 == -1 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return nullptr;
  }
  else
  {
    v6 = *(_DWORD *)(v4 + 4);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return (const ConCommandBase *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003780
// Name: public: virtual class ConCommandBase __near * CCvar::FindCommandBase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ConCommandBase *__thiscall CCvar::FindCommandBase(CCvar *this, const char *name)
{
  unsigned int v3; // eax
  int v4; // eax
  int v6; // esi

  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    counter_0.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "CCvar::FindCommandBase",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CCvar::FindCommandBase_::_4_::_dynamic_atexit_destructor_for___counter___0);
  }
  ++*counter_0.m_pCounter;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCvar::FindCommandBase",
    a3: 0,
    a4: "Cvar_Find",
    a5: false,
    a6: 4);
  v3 = HashStringCaseless(pszKey: name);
  v4 = CConCommandHash::Find(this: &this->m_CommandHash, name, hashkey: v3);
  if ( v4 == -1 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return nullptr;
  }
  else
  {
    v6 = *(_DWORD *)(v4 + 4);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return (ConCommandBase *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003830
// Name: public: virtual void CCvar::RevertFlaggedConVars(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::RevertFlaggedConVars(CCvar *this, int nFlag)
{
  int m_Size; // ecx
  int v4; // eax
  int *m_pMemory; // edx
  _DWORD *v6; // edi
  int v7; // ebx
  ConVar *v8; // esi
  const char *m_pszString; // eax
  const char *Default; // eax
  int v11; // esi
  int v12; // eax
  int *v13; // ecx
  const char *v14; // [esp-4h] [ebp-14h]
  CCvar *v15; // [esp+Ch] [ebp-4h]

  m_Size = this->m_CommandHash.m_aBuckets.m_Size;
  v4 = 0;
  v15 = this;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v7 = -1;
    v6 = nullptr;
  }
  else
  {
    m_pMemory = this->m_CommandHash.m_aBuckets.m_Memory.m_pMemory;
    while ( 1 )
    {
      v6 = (_DWORD *)*m_pMemory;
      if ( *m_pMemory != 0 )
        break;
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    v7 = v4;
  }
  while ( v7 >= 0 && v6 != nullptr && ((_DWORD *)v6[2] != v6 || (_DWORD *)v6[3] == v6) )
  {
    v8 = (ConVar *)v6[1];
    if ( !v8->IsCommand(this: v8) && v8->IsFlagSet(this: v8, a2: nFlag) )
    {
      if ( (v8->m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = v8->m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = str;
      }
      v14 = m_pszString;
      Default = ConVar::GetDefault(this: v8);
      if ( _V_stricmp(s1: Default, s2: v14) != 0 )
        ConVar::Revert(this: v8);
    }
    if ( v6[3] != 0 )
    {
      v6 = (_DWORD *)v6[3];
    }
    else
    {
      v11 = v15->m_CommandHash.m_aBuckets.m_Size;
      v12 = v7 + 1;
      if ( v7 + 1 >= v11 )
      {
LABEL_25:
        v7 = -1;
        v6 = nullptr;
      }
      else
      {
        v13 = &v15->m_CommandHash.m_aBuckets.m_Memory.m_pMemory[v12];
        while ( *v13 == 0 )
        {
          ++v12;
          ++v13;
          if ( v12 >= v11 )
            goto LABEL_25;
        }
        v7 = v12;
        v6 = (_DWORD *)*v13;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003940
// Name: public: virtual void CCvar::ConsolePrintf(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void CCvar::ConsolePrintf(CCvar *this, char *pFormat, ...)
{
  int m_Size; // edi
  int i; // esi
  IConsoleDisplayFunc *v4; // ecx
  char string[8192]; // [esp+Ch] [ebp-2000h] BYREF
  va_list ap; // [esp+201Ch] [ebp+10h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x1FFFu, format: pFormat, ap);
  m_Size = this->m_DisplayFuncs.m_Size;
  string[0x1FFF] = 0;
  if ( m_Size != 0 )
  {
    for ( i = 0; i < m_Size; ++i )
    {
      v4 = this->m_DisplayFuncs.m_Memory.m_pMemory[i];
      v4->Print(this: v4, a2: string);
    }
  }
  else
  {
    CUtlBuffer::PutChar(this: &this->m_TempConsoleBuffer, c: 1);
    CUtlBuffer::PutString(this: &this->m_TempConsoleBuffer, pString: string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100039C0
// Name: public: virtual void CCvar::ConsoleDPrintf(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void CCvar::ConsoleDPrintf(CCvar *this, char *pFormat, ...)
{
  int m_Size; // edi
  int i; // esi
  IConsoleDisplayFunc *v4; // ecx
  char string[8192]; // [esp+Ch] [ebp-2000h] BYREF
  va_list ap; // [esp+201Ch] [ebp+10h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x1FFFu, format: pFormat, ap);
  m_Size = this->m_DisplayFuncs.m_Size;
  string[0x1FFF] = 0;
  if ( m_Size != 0 )
  {
    for ( i = 0; i < m_Size; ++i )
    {
      v4 = this->m_DisplayFuncs.m_Memory.m_pMemory[i];
      v4->DPrint(this: v4, a2: string);
    }
  }
  else
  {
    CUtlBuffer::PutChar(this: &this->m_TempConsoleBuffer, c: 2);
    CUtlBuffer::PutString(this: &this->m_TempConsoleBuffer, pString: string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005820
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
// Address: 0x100058C0
// Name: public: virtual void CCvar::RemoveGlobalChangeCallback(void (*)(class IConVar __near *,char const __near *,float))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::RemoveGlobalChangeCallback(
        CCvar *this,
        void (__cdecl *callback)(IConVar *, const char *, float))
{
  CUtlVector<IConsoleDisplayFunc *,CUtlMemory<IConsoleDisplayFunc *,int>>::FindAndRemove(
    this: (CUtlVector<IConsoleDisplayFunc *,CUtlMemory<IConsoleDisplayFunc *,int> > *)&this->m_GlobalChangeCallbacks,
    src: (IConsoleDisplayFunc **)&callback);
}

//------------------------------------------------------------------------------
// Address: 0x100058E0
// Name: private: void CCvar::DisplayQueuedMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::DisplayQueuedMessages(CCvar *this)
{
  bool v2; // zf
  signed __int8 v3; // cl
  void *v4; // esp
  char v5[12]; // [esp+0h] [ebp-14h] BYREF
  int nType; // [esp+Ch] [ebp-8h]
  Color clr; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_TempConsoleBuffer.m_Put != 0 )
  {
    v2 = this->m_TempConsoleBuffer.m_Error == 0;
    clr = 0;
    if ( v2 )
    {
      do
      {
        if ( CUtlBuffer::CheckGet(this: &this->m_TempConsoleBuffer, nSize: 1) )
        {
          v3 = this->m_TempConsoleBuffer.m_Memory.m_pMemory[this->m_TempConsoleBuffer.m_Get
                                                          - this->m_TempConsoleBuffer.m_nOffset];
          ++this->m_TempConsoleBuffer.m_Get;
        }
        else
        {
          v3 = 0;
        }
        nType = v3;
        if ( v3 == 0 )
          clr = (Color)CUtlBuffer::GetInt(this: &this->m_TempConsoleBuffer);
        v4 = alloca(CUtlBuffer::PeekStringLength(this: &this->m_TempConsoleBuffer) + 1);
        CUtlBuffer::GetString(this: &this->m_TempConsoleBuffer, pString: v5, nMaxChars: 0);
        if ( nType != 0 )
        {
          if ( nType == 1 )
          {
            this->ConsolePrintf(this, a2: v5);
          }
          else if ( nType == 2 )
          {
            this->ConsoleDPrintf(this, a2: v5);
          }
        }
        else
        {
          this->ConsoleColorPrintf(this, a2: &clr, a3: v5);
        }
      }
      while ( this->m_TempConsoleBuffer.m_Error == 0 );
    }
    this->m_TempConsoleBuffer.m_Get = 0;
    this->m_TempConsoleBuffer.m_Put = 0;
    this->m_TempConsoleBuffer.m_nOffset = 0;
    this->m_TempConsoleBuffer.m_nMaxPut = 0;
    this->m_TempConsoleBuffer.m_Error = 0;
    if ( this->m_TempConsoleBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_TempConsoleBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TempConsoleBuffer.m_Memory.m_pMemory);
        this->m_TempConsoleBuffer.m_Memory.m_pMemory = nullptr;
      }
      this->m_TempConsoleBuffer.m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005A10
// Name: public: virtual void CCvar::RemoveConsoleDisplayFunc(class IConsoleDisplayFunc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::RemoveConsoleDisplayFunc(CCvar *this, IConsoleDisplayFunc *pDisplayFunc)
{
  CUtlVector<IConsoleDisplayFunc *,CUtlMemory<IConsoleDisplayFunc *,int>>::FindAndRemove(
    this: &this->m_DisplayFuncs,
    src: &pDisplayFunc);
}

//------------------------------------------------------------------------------
// Address: 0x10005A30
// Name: public: virtual void CCvar::ConsoleColorPrintf(class Color const __near &,char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void CCvar::ConsoleColorPrintf(CCvar *this, const Color *clr, char *pFormat, ...)
{
  int m_Size; // edi
  int i; // esi
  IConsoleDisplayFunc *v5; // ecx
  int v6; // [esp-4h] [ebp-2010h]
  char string[8192]; // [esp+Ch] [ebp-2000h] BYREF
  va_list ap; // [esp+2020h] [ebp+14h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x1FFFu, format: pFormat, ap);
  m_Size = this->m_DisplayFuncs.m_Size;
  string[0x1FFF] = 0;
  if ( m_Size != 0 )
  {
    for ( i = 0; i < m_Size; ++i )
    {
      v5 = this->m_DisplayFuncs.m_Memory.m_pMemory[i];
      v5->ColorPrint(this: v5, a2: clr, a3: string);
    }
  }
  else
  {
    CUtlBuffer::PutChar(this: &this->m_TempConsoleBuffer, c: 0);
    v6 = (int)*clr;
    if ( (this->m_TempConsoleBuffer.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &this->m_TempConsoleBuffer, pFmt: "%d", v6);
    else
      CUtlBuffer::PutTypeBin<int>(this: &this->m_TempConsoleBuffer, src: v6);
    CUtlBuffer::PutString(this: &this->m_TempConsoleBuffer, pString: string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F10
// Name: public: virtual void CCvar::InstallGlobalChangeCallback(void (*)(class IConVar __near *,char const __near *,float))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::InstallGlobalChangeCallback(
        CCvar *this,
        void (__cdecl *callback)(IConVar *, const char *, float))
{
  int m_nAllocationCount; // eax
  CUtlMemory<CCoroutineMgr *,int> *p_m_GlobalChangeCallbacks; // esi
  int m_Size; // edi
  CCoroutineMgr **m_pMemory; // ecx
  int v6; // eax
  CCoroutineMgr **v7; // eax

  m_nAllocationCount = this->m_GlobalChangeCallbacks.m_Memory.m_nAllocationCount;
  p_m_GlobalChangeCallbacks = (CUtlMemory<CCoroutineMgr *,int> *)&this->m_GlobalChangeCallbacks;
  m_Size = this->m_GlobalChangeCallbacks.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: p_m_GlobalChangeCallbacks, num: m_Size - m_nAllocationCount + 1);
  ++p_m_GlobalChangeCallbacks[1].m_pMemory;
  m_pMemory = p_m_GlobalChangeCallbacks->m_pMemory;
  v6 = (int)p_m_GlobalChangeCallbacks[1].m_pMemory - m_Size - 1;
  p_m_GlobalChangeCallbacks[1].m_nAllocationCount = (int)p_m_GlobalChangeCallbacks->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_GlobalChangeCallbacks->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CCoroutineMgr *)callback;
}

//------------------------------------------------------------------------------
// Address: 0x10005F70
// Name: public: virtual void CCvar::InstallConsoleDisplayFunc(class IConsoleDisplayFunc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::InstallConsoleDisplayFunc(CCvar *this, IConsoleDisplayFunc *pDisplayFunc)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IConsoleDisplayFunc **m_pMemory; // ecx
  int v6; // eax
  IConsoleDisplayFunc **v7; // eax

  m_nAllocationCount = this->m_DisplayFuncs.m_Memory.m_nAllocationCount;
  m_Size = this->m_DisplayFuncs.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CCoroutineMgr *,int> *)&this->m_DisplayFuncs,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_DisplayFuncs.m_Size;
  m_pMemory = this->m_DisplayFuncs.m_Memory.m_pMemory;
  v6 = this->m_DisplayFuncs.m_Size - m_Size - 1;
  this->m_DisplayFuncs.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_DisplayFuncs.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pDisplayFunc;
  CCvar::DisplayQueuedMessages(this);
}

//------------------------------------------------------------------------------
// Address: 0x10005FE0
// Name: public: int CConCommandHash::FastInsert(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *__thiscall CConCommandHash::FastInsert(
        CConCommandHash *this,
        ConCommandBase *cmd)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v3; // esi
  const char *v5; // eax
  unsigned int v6; // eax
  int v7; // edi

  v3 = CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::AllocInternal(
         this: &this->m_aDataPool,
         multilist: true);
  if ( v3 == nullptr )
    return (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)-1;
  v5 = cmd->GetName(this: cmd);
  v6 = HashStringCaseless(pszKey: v5);
  v3->m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)v6;
  v3->m_nBlockSize = (int)cmd;
  v7 = (unsigned __int8)v6;
  CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::LinkBefore(
    this: &this->m_aDataPool,
    before: this->m_aBuckets.m_Memory.m_pMemory[(unsigned __int8)v6],
    elem: (int)v3);
  this->m_aBuckets.m_Memory.m_pMemory[v7] = (int)v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10006040
// Name: public: unsigned short CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Find(class ConVar __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Find(
        CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short> *this,
        ConVar **key)
{
  unsigned __int16 v3; // si
  CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t dummyNode; // [esp+4h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: (CUtlString *)&dummyNode.elem);
  CUtlString::operator=(this: (CUtlString *)&dummyNode.elem, src: str);
  dummyNode.elem.m_Vars[0].m_pVar = nullptr;
  CUtlString::operator=(this: (CUtlString *)&dummyNode.elem, src: str);
  dummyNode.key = *key;
  dummyNode.elem.m_Vars[0].m_pVar = nullptr;
  v3 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  dummyNode.elem.m_Vars[0].m_VarName.m_Storage.m_nActualLength = 0;
  if ( dummyNode.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_nGrowSize >= 0
    && dummyNode.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dummyNode.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_pMemory);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10006270
// Name: public: virtual void CCvar::UnregisterConCommand(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::UnregisterConCommand(CCvar *this, ConCommandBase *pCommandToRemove)
{
  ConCommandBase *m_pConCommandList; // esi
  ConCommandBase *v4; // eax
  const char *(__thiscall *GetName)(ConCommandBase *); // eax
  const char *v6; // eax
  unsigned int v7; // eax
  int *m_pMemory; // edx
  _DWORD *v9; // ecx
  int v10; // esi
  int v11; // eax
  bool v12; // zf
  int *v13; // eax
  int v14; // eax
  int v15; // eax

  if ( pCommandToRemove->IsRegistered(this: pCommandToRemove) )
  {
    pCommandToRemove->m_bRegistered = false;
    m_pConCommandList = this->m_pConCommandList;
    v4 = nullptr;
    if ( m_pConCommandList != nullptr )
    {
      while ( m_pConCommandList != pCommandToRemove )
      {
        v4 = m_pConCommandList;
        m_pConCommandList = m_pConCommandList->m_pNext;
        if ( m_pConCommandList == nullptr )
          return;
      }
      if ( v4 != nullptr )
        v4->m_pNext = m_pConCommandList->m_pNext;
      else
        this->m_pConCommandList = m_pConCommandList->m_pNext;
      GetName = m_pConCommandList->GetName;
      m_pConCommandList->m_pNext = nullptr;
      v6 = GetName(this: m_pConCommandList);
      v7 = HashStringCaseless(pszKey: v6);
      m_pMemory = this->m_CommandHash.m_aBuckets.m_Memory.m_pMemory;
      v9 = (_DWORD *)m_pMemory[(unsigned __int8)v7];
      if ( v9 != nullptr )
      {
        while ( *v9 != v7 || (ConCommandBase *)v9[1] != m_pConCommandList )
        {
          v9 = (_DWORD *)v9[3];
          if ( v9 == nullptr )
            goto LABEL_13;
        }
        v10 = (int)v9;
      }
      else
      {
LABEL_13:
        v10 = -1;
      }
      v11 = *(unsigned __int8 *)v10;
      v12 = m_pMemory[v11] == v10;
      v13 = &m_pMemory[v11];
      if ( v12 )
        *v13 = *(_DWORD *)(v10 + 12);
      else
        CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::Unlink(
          this: &this->m_CommandHash.m_aDataPool,
          elem: v10);
      if ( !CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
              this: &this->m_CommandHash.m_aDataPool.m_Memory,
              i: v10,
              it: &this->m_CommandHash.m_aDataPool.m_LastAlloc) )
      {
        v14 = *(_DWORD *)(v10 + 8);
        if ( v14 != v10 )
        {
          if ( v14 != 0 )
            *(_DWORD *)(v14 + 12) = *(_DWORD *)(v10 + 12);
          else
            this->m_CommandHash.m_aDataPool.m_Head = *(_DWORD *)(v10 + 12);
          v15 = *(_DWORD *)(v10 + 12);
          if ( v15 != 0 )
            *(_DWORD *)(v15 + 8) = *(_DWORD *)(v10 + 8);
          else
            this->m_CommandHash.m_aDataPool.m_Tail = *(_DWORD *)(v10 + 8);
          *(_DWORD *)(v10 + 12) = v10;
          *(_DWORD *)(v10 + 8) = v10;
          --this->m_CommandHash.m_aDataPool.m_ElementCount;
        }
      }
      *(_DWORD *)(v10 + 12) = this->m_CommandHash.m_aDataPool.m_FirstFree;
      this->m_CommandHash.m_aDataPool.m_FirstFree = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006380
// Name: public: int CConCommandHash::Insert(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *__thiscall CConCommandHash::Insert(
        CConCommandHash *this,
        ConCommandBase *cmd)
{
  const char *v3; // eax
  unsigned int v4; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *result; // eax

  v3 = cmd->GetName(this: cmd);
  v4 = HashStringCaseless(pszKey: v3);
  result = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)this->m_aBuckets.m_Memory.m_pMemory[(unsigned __int8)v4];
  if ( result == nullptr )
    return CConCommandHash::FastInsert(this, cmd);
  while ( result->m_pNext != (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)v4
       || (ConCommandBase *)result->m_nBlockSize != cmd )
  {
    result = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)result[1].m_nBlockSize;
    if ( result == nullptr )
      return CConCommandHash::FastInsert(this, cmd);
  }
  if ( result == (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)-1 )
    return CConCommandHash::FastInsert(this, cmd);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100065E0
// Name: public: virtual void CCvar::RegisterConCommand(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::RegisterConCommand(CCvar *this, const ConVar *variable)
{
  const char *(__thiscall *GetName)(ConCommandBase *); // edx
  _BYTE *v4; // eax
  CCvar_vtbl *v5; // edi
  const char *v6; // eax
  const ConVar *v7; // edi
  const char *v8; // eax
  int v9; // edx
  int m_Size; // eax
  int v11; // ebx
  const char *v12; // eax
  unsigned int i; // ebx
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  const char *v17; // ecx
  bool v18; // zf
  const char *v19; // edx
  const char *v20; // eax
  int v21; // eax
  const char *v22; // eax
  const char *v23; // [esp-18h] [ebp-20h]
  const char *v24; // [esp-14h] [ebp-1Ch]
  const char *v25; // [esp-10h] [ebp-18h]
  const char *v26; // [esp-Ch] [ebp-14h]
  const char *v27; // [esp-Ch] [ebp-14h]
  const char *v28; // [esp-Ch] [ebp-14h]
  const char *v29; // [esp-8h] [ebp-10h]
  const char *v30; // [esp-8h] [ebp-10h]
  const char *v31; // [esp-8h] [ebp-10h]
  const char *v32; // [esp-8h] [ebp-10h]

  if ( variable->IsRegistered(this: variable) )
    return;
  GetName = (const char *(__thiscall *)(ConCommandBase *))variable->GetName;
  variable->m_bRegistered = true;
  v4 = (_BYTE *)GetName(this: &variable->ConCommandBase);
  if ( v4 == nullptr || *v4 == 0 )
  {
    variable->m_pNext = nullptr;
    return;
  }
  v5 = this->__vftable;
  v6 = variable->GetName(this: variable);
  v7 = (const ConVar *)v5->FindCommandBase_2(this, a2: v6);
  if ( v7 == nullptr )
  {
    variable->m_pNext = this->m_pConCommandList;
    this->m_pConCommandList = &variable->ConCommandBase;
    CConCommandHash::Insert(this: &this->m_CommandHash, cmd: &variable->ConCommandBase);
    return;
  }
  if ( variable->IsCommand(this: variable) || v7->IsCommand(this: v7) )
  {
    v21 = (int)v7->GetName(this: v7);
    v22 = (const char *)((int (__thiscall *)(const ConVar *, int))variable->GetName)(a1: variable, a2: v21);
    _Warning(a1: "WARNING: unable to link %s and %s because one or more is a ConCommand.\n", v22, v32);
    goto LABEL_35;
  }
  if ( !s_pCVarQuery->AreConVarsLinkable(this: s_pCVarQuery, a2: variable, a3: v7) )
  {
LABEL_35:
    variable->m_pNext = nullptr;
    return;
  }
  if ( variable->m_pszDefaultValue != nullptr
    && v7->m_pszDefaultValue != nullptr
    && variable->IsFlagSet(this: variable, a2: 0x2000)
    && v7->IsFlagSet(this: v7, a2: 0x2000)
    && _V_stricmp(s1: variable->m_pszDefaultValue, s2: v7->m_pszDefaultValue) != 0 )
  {
    v8 = (const char *)((int (__thiscall *)(const ConVar *, const char *, const char *))variable->GetName)(
                         a1: variable,
                         a2: variable->m_pszDefaultValue,
                         a3: v7->m_pszDefaultValue);
    _Warning(
      a1: "Parent and child ConVars with different default values! %s child: %s parent: %s (parent wins)\n",
      v8,
      v26,
      v29);
  }
  v9 = variable->m_nFlags & 0x2B00000;
  variable->m_pParent = v7->m_pParent;
  v7->m_nFlags |= v9;
  m_Size = variable->m_fnChangeCallbacks.m_Size;
  if ( m_Size != 0 )
  {
    v11 = 0;
    if ( m_Size > 0 )
    {
      do
        CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::InsertBefore(
          this: &v7->m_fnChangeCallbacks,
          elem: v7->m_fnChangeCallbacks.m_Size,
          src: &variable->m_fnChangeCallbacks.m_Memory.m_pMemory[v11++]);
      while ( v11 < variable->m_fnChangeCallbacks.m_Size );
    }
    variable->m_fnChangeCallbacks.m_Size = 0;
  }
  if ( variable->m_pszHelpString != nullptr && _V_strlen(str: variable->m_pszHelpString) != 0 )
  {
    if ( v7->m_pszHelpString != nullptr && _V_strlen(str: v7->m_pszHelpString) != 0 )
    {
      if ( _V_stricmp(s1: v7->m_pszHelpString, s2: variable->m_pszHelpString) != 0 )
      {
        v12 = (const char *)((int (__thiscall *)(const ConVar *, const char *, const char *))variable->GetName)(
                              a1: variable,
                              a2: v7->m_pszHelpString,
                              a3: variable->m_pszHelpString);
        _Warning(a1: "Convar %s has multiple help strings:\n\tparent (wins): \"%s\"\n\tchild: \"%s\"\n", v12, v27, v30);
      }
    }
    else
    {
      v7->m_pszHelpString = variable->m_pszHelpString;
    }
  }
  for ( i = 0; i < 5; ++i )
  {
    v14 = nFlags[i];
    v15 = v14 & v7->m_nFlags;
    v16 = v14 & variable->m_nFlags;
    if ( v16 != v15 )
    {
      v17 = "has ";
      if ( v15 == 0 )
        v17 = "no ";
      v18 = v16 == 0;
      v19 = "has ";
      if ( v18 )
        v19 = "no ";
      v20 = (const char *)((int (__thiscall *)(const ConVar *, const char *const, const char *, const char *const, const char *, const char *const))variable->GetName)(
                            a1: variable,
                            a2: szFlags[i],
                            a3: v19,
                            a4: szFlags[i],
                            a5: v17,
                            a6: szFlags[i]);
      _Warning(
        a1: "Convar %s has conflicting %s flags (child: %s%s, parent: %s%s, parent wins)\n",
        v20,
        v23,
        v24,
        v25,
        v28,
        v31);
    }
  }
  variable->m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006840
// Name: public: virtual void CCvar::QueueMaterialThreadSetValue(class ConVar __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::QueueMaterialThreadSetValue(CCvar *this, ConVar *pConVar, const char *pValue)
{
  CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int> > *p_m_QueuedConVarSets; // esi
  int v4; // eax

  p_m_QueuedConVarSets = &this->m_QueuedConVarSets;
  v4 = CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>::InsertBefore(
         this: &this->m_QueuedConVarSets,
         elem: this->m_QueuedConVarSets.m_Size);
  p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_pConVar = pConVar;
  p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_nType = CONVAR_SET_STRING;
  CUtlString::operator=(this: &p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_String, src: pValue);
}

//------------------------------------------------------------------------------
// Address: 0x10006890
// Name: public: virtual void CCvar::QueueMaterialThreadSetValue(class ConVar __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::QueueMaterialThreadSetValue(CCvar *this, ConVar *pConVar, int nValue)
{
  CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int> > *p_m_QueuedConVarSets; // esi
  int v4; // eax

  p_m_QueuedConVarSets = &this->m_QueuedConVarSets;
  v4 = CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>::InsertBefore(
         this: &this->m_QueuedConVarSets,
         elem: this->m_QueuedConVarSets.m_Size);
  p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_pConVar = pConVar;
  p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_nType = CONVAR_SET_INT;
  p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_nInt = nValue;
}

//------------------------------------------------------------------------------
// Address: 0x100068D0
// Name: public: virtual void CCvar::QueueMaterialThreadSetValue(class ConVar __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::QueueMaterialThreadSetValue(CCvar *this, ConVar *pConVar, float flValue)
{
  CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int> > *p_m_QueuedConVarSets; // esi
  int v4; // eax

  p_m_QueuedConVarSets = &this->m_QueuedConVarSets;
  v4 = CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>::InsertBefore(
         this: &this->m_QueuedConVarSets,
         elem: this->m_QueuedConVarSets.m_Size);
  p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_pConVar = pConVar;
  p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_nType = CONVAR_SET_FLOAT;
  p_m_QueuedConVarSets->m_Memory.m_pMemory[v4].m_flFloat = flValue;
}

//------------------------------------------------------------------------------
// Address: 0x10006910
// Name: public: virtual int CCvar::ProcessQueuedMaterialThreadConVarSets(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvar::ProcessQueuedMaterialThreadConVarSets(CCvar *this)
{
  int m_Size; // eax
  int v2; // ebx
  CCvar::QueuedConVarSet_t *m_pMemory; // esi
  CCvar::ConVarSetType_t m_nType; // eax
  CUtlString *v5; // esi
  __int32 v6; // eax
  int v7; // edi
  const char *v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // ebx
  CCvar::QueuedConVarSet_t *v12; // esi
  int i; // [esp+10h] [ebp-Ch]
  int nUpdateFlags; // [esp+14h] [ebp-8h]
  CCvar *v16; // [esp+18h] [ebp-4h]

  m_Size = this->m_QueuedConVarSets.m_Size;
  v2 = 0;
  v16 = this;
  this->m_bMaterialSystemThreadSetAllowed = true;
  nUpdateFlags = 0;
  if ( m_Size > 0 )
  {
    for ( i = m_Size; i != 0; --i )
    {
      m_pMemory = this->m_QueuedConVarSets.m_Memory.m_pMemory;
      m_nType = m_pMemory[v2].m_nType;
      v5 = (CUtlString *)&m_pMemory[v2];
      if ( m_nType != CONVAR_SET_STRING )
      {
        v6 = m_nType - 1;
        if ( v6 != 0 )
        {
          if ( v6 == 1 )
            (*(void (__stdcall **)(int))(*((_DWORD *)v5->m_Storage.m_Memory.m_pMemory + 6) + 8))(a1: v5->m_Storage.m_nActualLength);
        }
        else
        {
          (*(void (__thiscall **)(unsigned __int8 *, int))(*((_DWORD *)v5->m_Storage.m_Memory.m_pMemory + 6) + 4))(
            a1: v5->m_Storage.m_Memory.m_pMemory + 24,
            a2: v5->m_Storage.m_Memory.m_nGrowSize);
        }
      }
      else
      {
        v7 = *((_DWORD *)v5->m_Storage.m_Memory.m_pMemory + 6);
        v8 = CUtlString::operator char const *(this: v5 + 1);
        (*(void (__stdcall **)(const char *))(v7 + 12))(a1: v8);
      }
      v9 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v5->m_Storage.m_Memory.m_pMemory + 20))(a1: v5->m_Storage.m_Memory.m_pMemory);
      this = v16;
      nUpdateFlags |= v9 & 0xB00000;
      ++v2;
    }
  }
  v10 = this->m_QueuedConVarSets.m_Size - 1;
  if ( v10 >= 0 )
  {
    v11 = v10;
    do
    {
      v12 = &this->m_QueuedConVarSets.m_Memory.m_pMemory[v11];
      v12->m_String.m_Storage.m_nActualLength = 0;
      if ( v12->m_String.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v12->m_String.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_String.m_Storage.m_Memory.m_pMemory);
          this = v16;
          v12->m_String.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v12->m_String.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v10;
      --v11;
    }
    while ( v10 >= 0 );
  }
  this->m_QueuedConVarSets.m_Size = 0;
  this->m_bMaterialSystemThreadSetAllowed = false;
  return nUpdateFlags;
}

//------------------------------------------------------------------------------
// Address: 0x10006A30
// Name: private: void CCvar::Find(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::Find(CCvar *this, const CCommand *args)
{
  bool v2; // zf
  int m_Size; // ecx
  int v5; // ebx
  int v6; // eax
  int *m_pMemory; // edx
  int v8; // edi
  char *v9; // esi
  const char *v10; // eax
  const char *v11; // ecx
  const char *v12; // eax
  const char *v13; // ecx
  int v14; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v15; // ecx
  int v16; // edx
  int v17; // esi
  int v18; // edx
  int v19; // esi
  int v20; // eax
  int *v21; // ecx
  int i; // esi
  char *v23; // [esp-10h] [ebp-44h]
  CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > sorted; // [esp+0h] [ebp-34h] BYREF
  char *pSearch; // [esp+24h] [ebp-10h]
  CCvar *v26; // [esp+28h] [ebp-Ch]
  int parent; // [esp+2Ch] [ebp-8h] BYREF
  ConCommandBase *var; // [esp+30h] [ebp-4h] BYREF

  v2 = args->m_nArgc == 2;
  v26 = this;
  if ( v2 )
  {
    m_Size = this->m_CommandHash.m_aBuckets.m_Size;
    v5 = -1;
    pSearch = (char *)args->m_ppArgv[1];
    v6 = 0;
    sorted.m_LessFunc = ConVarSortFunc;
    memset(&sorted.m_Elements, 0, sizeof(sorted.m_Elements));
    sorted.m_Root = -1;
    sorted.m_NumElements = 0;
    sorted.m_FirstFree = -1;
    sorted.m_LastAlloc.index = -1;
    sorted.m_pElements = nullptr;
    if ( m_Size <= 0 )
    {
LABEL_8:
      v8 = 0;
    }
    else
    {
      m_pMemory = this->m_CommandHash.m_aBuckets.m_Memory.m_pMemory;
      while ( *m_pMemory == 0 )
      {
        ++v6;
        ++m_pMemory;
        if ( v6 >= m_Size )
        {
          v5 = -1;
          goto LABEL_8;
        }
      }
      v5 = v6;
      v8 = *m_pMemory;
    }
    while ( v5 >= 0 && v8 != 0 && (*(_DWORD *)(v8 + 8) != v8 || *(_DWORD *)(v8 + 12) == v8) )
    {
      var = *(ConCommandBase **)(v8 + 4);
      if ( !var->IsFlagSet(this: var, a2: 2) && !var->IsFlagSet(this: var, a2: 16) )
      {
        v9 = pSearch;
        v23 = pSearch;
        v10 = var->GetName(this: var);
        if ( V_stristr(a1: v11, a2: (const char *)v5, pStr: v10, pSearch: v23) != nullptr
          || (v12 = var->GetHelpText(this: var),
              V_stristr(a1: v13, a2: (const char *)v5, pStr: v12, pSearch: v9) != nullptr) )
        {
          parent = -1;
          HIBYTE(args) = 0;
          CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::FindInsertionPosition(
            this: &sorted,
            insert: &var,
            &parent,
            leftchild: (bool *)&args + 3);
          v14 = CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::NewNode(this: &sorted);
          v15 = sorted.m_Elements.m_pMemory;
          v16 = parent;
          v17 = v14;
          sorted.m_Elements.m_pMemory[v17].m_Parent = parent;
          v15[v17].m_Right = -1;
          v15[v17].m_Left = -1;
          v15[v17].m_Tag = 0;
          if ( v16 == -1 )
          {
            sorted.m_Root = v14;
          }
          else
          {
            v18 = v16;
            if ( HIBYTE(args) != 0 )
              v15[v18].m_Left = v14;
            else
              v15[v18].m_Right = v14;
          }
          CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::InsertRebalance(
            this: &sorted,
            elem: v14);
          ++sorted.m_NumElements;
          if ( &sorted.m_Elements.m_pMemory[v17] != (UtlRBTreeNode_t<ConCommandBase *,int> *)-16 )
            sorted.m_Elements.m_pMemory[v17].m_Data = var;
        }
      }
      if ( *(_DWORD *)(v8 + 12) != 0 )
      {
        v8 = *(_DWORD *)(v8 + 12);
      }
      else
      {
        v19 = v26->m_CommandHash.m_aBuckets.m_Size;
        v20 = v5 + 1;
        if ( v5 + 1 >= v19 )
        {
LABEL_31:
          v5 = -1;
          v8 = 0;
        }
        else
        {
          v21 = &v26->m_CommandHash.m_aBuckets.m_Memory.m_pMemory[v20];
          while ( *v21 == 0 )
          {
            ++v20;
            ++v21;
            if ( v20 >= v19 )
              goto LABEL_31;
          }
          v5 = v20;
          v8 = *v21;
        }
      }
    }
    for ( i = CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::FirstInorder(this: &sorted);
          i != -1;
          i = CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::NextInorder(
                this: &sorted,
                i) )
    {
      ConVar_PrintDescription(pVar: sorted.m_Elements.m_pMemory[i].m_Data);
    }
    CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RemoveAll(this: &sorted);
    if ( sorted.m_Elements.m_nGrowSize >= 0 && sorted.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Elements.m_pMemory);
  }
  else
  {
    ConMsg(a1: "Usage:  find <string>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006C80
// Name: public: void CConCommandHash::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandHash::Init(CConCommandHash *this)
{
  int m_nAllocationCount; // eax
  int *m_pMemory; // eax
  int v4; // ecx
  int i; // eax
  CUtlFixedLinkedList<CConCommandHash::HashEntry_t> *p_m_aDataPool; // esi
  const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *p_m_LastAlloc; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v8; // edi
  int j; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v10; // edi
  int m_nBlockSize; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v12; // [esp-4h] [ebp-2Ch]
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pBlocks; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+20h] [ebp-8h]
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *p_m_Memory; // [esp+24h] [ebp-4h]

  m_nAllocationCount = this->m_aBuckets.m_Memory.m_nAllocationCount;
  this->m_aBuckets.m_Size = 0;
  if ( m_nAllocationCount < 256 )
    CUtlMemory<int,int>::Grow((CUtlMemory<CCoroutineMgr *,int> *)this, num: 256 - m_nAllocationCount);
  this->m_aBuckets.m_Size += 256;
  m_pMemory = this->m_aBuckets.m_Memory.m_pMemory;
  v4 = this->m_aBuckets.m_Size - 256;
  this->m_aBuckets.m_pElements = this->m_aBuckets.m_Memory.m_pMemory;
  if ( v4 > 0 )
    _V_memmove(dest: m_pMemory + 256, src: m_pMemory, count: 4 * v4);
  for ( i = 0; i < 256; ++i )
    this->m_aBuckets.m_Memory.m_pMemory[i] = 0;
  p_m_aDataPool = &this->m_aDataPool;
  p_m_LastAlloc = &p_m_aDataPool->m_LastAlloc;
  p_m_Memory = &p_m_aDataPool->m_Memory;
  if ( p_m_aDataPool->m_LastAlloc.m_pBlockHeader != nullptr || p_m_aDataPool->m_LastAlloc.m_nIndex != -1 )
  {
    if ( p_m_aDataPool->m_Memory.m_pBlocks != nullptr )
    {
      m_pBlocks = p_m_aDataPool->m_Memory.m_pBlocks;
      v14 = 0;
    }
    else
    {
      m_pBlocks = nullptr;
      v14 = -1;
    }
    v8 = m_pBlocks;
    for ( j = v14; ; j = 0 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          if ( v8 != nullptr )
          {
            if ( j >= 0 && j < v8->m_nBlockSize )
            {
              if ( &v8[2 * j] == (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)-8
                || CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
                     this: p_m_Memory,
                     i: (unsigned int)&v8[2 * j + 1],
                     it: p_m_LastAlloc)
                || v8[2 * j + 2].m_pNext == &v8[2 * j + 1]
                && (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)v8[2 * j + 2].m_nBlockSize != &v8[2 * j + 1] )
              {
                p_m_aDataPool = (CUtlFixedLinkedList<CConCommandHash::HashEntry_t> *)p_m_Memory;
              }
              else
              {
                v8[2 * j + 2].m_pNext = &v8[2 * j + 1];
                v8[2 * j + 2].m_nBlockSize = p_m_Memory[1].m_nGrowSize;
                p_m_Memory[1].m_nGrowSize = (int)&v8[2 * j + 1];
                p_m_aDataPool = (CUtlFixedLinkedList<CConCommandHash::HashEntry_t> *)p_m_Memory;
              }
            }
          }
          else if ( j == -1 )
          {
            goto LABEL_15;
          }
          if ( v8 == p_m_aDataPool->m_LastAlloc.m_pBlockHeader && j == p_m_aDataPool->m_LastAlloc.m_nIndex )
          {
LABEL_15:
            p_m_aDataPool->m_Head = 0;
            p_m_aDataPool->m_Tail = 0;
            p_m_aDataPool->m_ElementCount = 0;
            goto LABEL_16;
          }
          if ( v8 != nullptr && j >= 0 )
          {
            m_nBlockSize = v8->m_nBlockSize;
            if ( j < m_nBlockSize )
              break;
          }
          p_m_LastAlloc = &p_m_aDataPool->m_LastAlloc;
          v8 = nullptr;
          j = -1;
        }
        if ( ++j >= m_nBlockSize )
          break;
LABEL_38:
        p_m_LastAlloc = &p_m_aDataPool->m_LastAlloc;
      }
      v8 = v8->m_pNext;
      if ( v8 == nullptr )
      {
        v8 = nullptr;
        j = -1;
        goto LABEL_38;
      }
      p_m_LastAlloc = &p_m_aDataPool->m_LastAlloc;
    }
  }
LABEL_16:
  v10 = p_m_aDataPool->m_Memory.m_pBlocks;
  if ( p_m_aDataPool->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v12 = v10;
      v10 = v10->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
    }
    while ( v10 != nullptr );
    p_m_aDataPool->m_Memory.m_pBlocks = nullptr;
    p_m_aDataPool->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aDataPool->m_pElements = nullptr;
  p_m_aDataPool->m_Memory.m_nGrowSize = 1024;
}

//------------------------------------------------------------------------------
// Address: 0x10006F10
// Name: public: CCvar::CCommandMemberInitializer_Find::CCommandMemberInitializer_Find(void)
// Source: json
//------------------------------------------------------------------------------
CCvar::CCommandMemberInitializer_Find *__thiscall CCvar::CCommandMemberInitializer_Find::CCommandMemberInitializer_Find(
        CCvar::CCommandMemberInitializer_Find *this)
{
  ICommandCallback *v2; // eax

  if ( this != nullptr )
    v2 = &this->m_ConCommandAccessor.ICommandCallback;
  else
    v2 = nullptr;
  ConCommand::ConCommand(
    this: &this->m_ConCommandAccessor,
    pName: "find",
    pCallback: v2,
    pHelpString: "Find concommands with the specified string in their name/help text.",
    flags: 0,
    pCompletionCallback: nullptr);
  this->m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  this->m_ConCommandAccessor.m_pOwner = (CCvar *)((char *)this - 220);
  this->m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CCvar>_vtbl *)&CConCommandMemberAccessor<CCvar>::`vftable'{for `ConCommand'};
  this->m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CCvar>::`vftable'{for `ICommandCallback'};
  this->m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CCvar>::`vftable'{for `ICommandCompletionCallback'};
  this->m_ConCommandAccessor.m_Func = CCvar::Find;
  this->m_ConCommandAccessor.m_CompletionFunc = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006F70
// Name: public: unsigned short CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Insert(class ConVar __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Insert(
        CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short> *this,
        ConVar **key)
{
  unsigned __int16 v3; // si
  CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t node; // [esp+4h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: (CUtlString *)&node.elem);
  CUtlString::operator=(this: (CUtlString *)&node.elem, src: str);
  node.elem.m_Vars[0].m_pVar = nullptr;
  CUtlString::operator=(this: (CUtlString *)&node.elem, src: str);
  node.key = *key;
  node.elem.m_Vars[0].m_pVar = nullptr;
  v3 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: &node);
  node.elem.m_Vars[0].m_VarName.m_Storage.m_nActualLength = 0;
  if ( node.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_nGrowSize >= 0
    && node.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: node.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_pMemory);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10007060
// Name: public: virtual void CCvar::AddSplitScreenConVars(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCvar::AddSplitScreenConVars(CCvar *this@<ecx>, ConVar_vtbl *a2@<esi>)
{
  CCvar *v2; // edi
  bool v3; // zf
  ConVar *m_pConCommandList; // ebx
  bool (__thiscall *IsFlagSet)(struct ConVar *, int); // edx
  unsigned __int16 v6; // ax
  int v7; // edx
  int v8; // esi
  int p_elem; // eax
  ConVar *p_m_pVar; // edi
  const char *v11; // eax
  CFmtStrN<256> *v12; // eax
  CSplitScreenAddedConVar *v13; // ebx
  const char *v14; // eax
  ConVar_vtbl *v15; // eax
  CCvar *v16; // ecx
  const ConVar *v18; // [esp-8h] [ebp-124h]
  CFmtStrN<256> v19; // [esp+4h] [ebp-118h] BYREF
  CCvar *v20; // [esp+110h] [ebp-Ch]
  ConCommandBase *pCommand; // [esp+114h] [ebp-8h]
  ConVar *pConVar; // [esp+118h] [ebp-4h] BYREF

  v2 = this;
  v3 = this->m_nMaxSplitScreenSlots == 1;
  v20 = this;
  if ( !v3 )
  {
    m_pConCommandList = (ConVar *)this->m_pConCommandList;
    pCommand = &m_pConCommandList->ConCommandBase;
    if ( m_pConCommandList != nullptr )
    {
      while ( 1 )
      {
        if ( !m_pConCommandList->IsCommand(this: m_pConCommandList) )
        {
          IsFlagSet = m_pConCommandList->IsFlagSet;
          pConVar = m_pConCommandList;
          if ( IsFlagSet(this: m_pConCommandList, a2: 0x8000) )
          {
            v6 = CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Find(
                   this: &v2->m_SplitScreenAddedConVarsMap,
                   key: &pConVar);
            if ( v6 == 0xFFFF )
              v6 = CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Insert(
                     this: &v2->m_SplitScreenAddedConVarsMap,
                     key: &pConVar);
            v7 = v6;
            v8 = 1;
            p_elem = (int)&v2->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
            if ( v2->m_nMaxSplitScreenSlots > 1 )
            {
              p_m_pVar = (ConVar *)&v2->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.m_Vars[0].m_pVar;
              pConVar = (ConVar *)(p_elem + 16);
              do
              {
                if ( p_m_pVar->ConCommandBase::__vftable == nullptr )
                {
                  v11 = (const char *)((int (__thiscall *)(ConVar *, int))m_pConCommandList->GetName)(
                                        a1: m_pConCommandList,
                                        a2: v8 + 1);
                  v12 = CFmtStrN<256>::CFmtStrN<256>(this: &v19, pszFormat: "%s%d", v11, a2);
                  CUtlString::operator=(
                    this: (CUtlString *)&p_m_pVar[-1].m_fnChangeCallbacks.m_Memory.m_nAllocationCount,
                    src: v12->m_szBuf);
                  v13 = (CSplitScreenAddedConVar *)operator new(nSize: 0x60u);
                  if ( v13 != nullptr )
                  {
                    v18 = (const ConVar *)pCommand;
                    v14 = CUtlString::Get(this: (CUtlString *)&p_m_pVar[-1].m_fnChangeCallbacks.m_Memory.m_nAllocationCount);
                    v15 = (ConVar_vtbl *)CSplitScreenAddedConVar::CSplitScreenAddedConVar(
                                           this: v13,
                                           nSplitScreenSlot: v8,
                                           pName: v14,
                                           pBaseVar: v18);
                  }
                  else
                  {
                    v15 = nullptr;
                  }
                  pConVar->ConCommandBase::__vftable = v15;
                  v16 = v20;
                  v15[1].RemoveFlags = (void (__thiscall *)(struct ConVar *, int))v8;
                  a2 = v15;
                  ((void (__thiscall *)(CCvar *))v16->RegisterConCommand)(a1: v16);
                  m_pConCommandList = (ConVar *)pCommand;
                  p_m_pVar = pConVar;
                }
                ++v8;
                p_m_pVar = (ConVar *)((char *)p_m_pVar + 20);
                pConVar = p_m_pVar;
              }
              while ( v8 < v20->m_nMaxSplitScreenSlots );
              v2 = v20;
            }
          }
        }
        pCommand = m_pConCommandList->m_pNext;
        if ( pCommand == nullptr )
          break;
        m_pConCommandList = (ConVar *)pCommand;
      }
    }
    ConCommandBase::s_pConCommandBases = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100071C0
// Name: public: virtual void CCvar::UnregisterConCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::UnregisterConCommands(CCvar *this, int id)
{
  CConCommandHash *p_m_CommandHash; // ebx
  ConCommandBase *m_pConCommandList; // esi
  ConCommandBase_vtbl *v5; // edx
  const char *v6; // eax
  unsigned int v7; // eax
  _DWORD *v8; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v9; // edi
  const char *v10; // eax
  unsigned int v11; // eax
  int v12; // esi
  ConCommandBase *pNext; // [esp+10h] [ebp-8h]
  ConCommandBase *pNewList; // [esp+14h] [ebp-4h]

  p_m_CommandHash = &this->m_CommandHash;
  pNewList = nullptr;
  this->m_CommandHash.m_aBuckets.m_Size = 0;
  if ( this->m_CommandHash.m_aBuckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_CommandHash->m_aBuckets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_CommandHash->m_aBuckets.m_Memory.m_pMemory);
      p_m_CommandHash->m_aBuckets.m_Memory.m_pMemory = nullptr;
    }
    p_m_CommandHash->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  }
  p_m_CommandHash->m_aBuckets.m_pElements = p_m_CommandHash->m_aBuckets.m_Memory.m_pMemory;
  CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::Purge(this: &p_m_CommandHash->m_aDataPool);
  CConCommandHash::Init(this: p_m_CommandHash);
  m_pConCommandList = this->m_pConCommandList;
  if ( m_pConCommandList != nullptr )
  {
    do
    {
      pNext = m_pConCommandList->m_pNext;
      if ( m_pConCommandList->GetDLLIdentifier(this: m_pConCommandList) == id )
      {
        m_pConCommandList->m_bRegistered = false;
        m_pConCommandList->m_pNext = nullptr;
      }
      else
      {
        v5 = m_pConCommandList->__vftable;
        m_pConCommandList->m_pNext = pNewList;
        pNewList = m_pConCommandList;
        v6 = v5->GetName(this: m_pConCommandList);
        v7 = HashStringCaseless(pszKey: v6);
        v8 = (_DWORD *)p_m_CommandHash->m_aBuckets.m_Memory.m_pMemory[(unsigned __int8)v7];
        if ( v8 == nullptr )
          goto LABEL_13;
        while ( *v8 != v7 || (ConCommandBase *)v8[1] != m_pConCommandList )
        {
          v8 = (_DWORD *)v8[3];
          if ( v8 == nullptr )
            goto LABEL_13;
        }
        if ( v8 == (_DWORD *)-1 )
        {
LABEL_13:
          v9 = CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::AllocInternal(
                 this: &p_m_CommandHash->m_aDataPool,
                 multilist: true);
          if ( v9 != nullptr )
          {
            v10 = m_pConCommandList->GetName(this: m_pConCommandList);
            v11 = HashStringCaseless(pszKey: v10);
            v9->m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)v11;
            v9->m_nBlockSize = (int)m_pConCommandList;
            v12 = (unsigned __int8)v11;
            CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::LinkBefore(
              this: &p_m_CommandHash->m_aDataPool,
              before: p_m_CommandHash->m_aBuckets.m_Memory.m_pMemory[(unsigned __int8)v11],
              elem: (int)v9);
            p_m_CommandHash->m_aBuckets.m_Memory.m_pMemory[v12] = (int)v9;
          }
        }
      }
      m_pConCommandList = pNext;
    }
    while ( pNext != nullptr );
    this->m_pConCommandList = pNewList;
  }
  else
  {
    this->m_pConCommandList = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100072F0
// Name: public: CConCommandHash::CConCommandHash(void)
// Source: json
//------------------------------------------------------------------------------
CConCommandHash *__thiscall CConCommandHash::CConCommandHash(CConCommandHash *this)
{
  this->m_aBuckets.m_Memory.m_nGrowSize = 0;
  this->m_aBuckets.m_Memory.m_pMemory = nullptr;
  this->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  this->m_aBuckets.m_pElements = nullptr;
  this->m_aDataPool.m_Memory.m_pBlocks = nullptr;
  this->m_aDataPool.m_Memory.m_nAllocationCount = 0;
  this->m_aDataPool.m_Memory.m_nGrowSize = 0;
  this->m_aDataPool.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_aDataPool.m_LastAlloc.m_nIndex = -1;
  this->m_aDataPool.m_Head = 0;
  this->m_aDataPool.m_Tail = 0;
  this->m_aDataPool.m_FirstFree = 0;
  this->m_aDataPool.m_ElementCount = 0;
  this->m_aDataPool.m_NumAlloced = 0;
  this->m_aDataPool.m_pElements = nullptr;
  this->m_aBuckets.m_Size = 0;
  if ( this->m_aBuckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aBuckets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aBuckets.m_Memory.m_pMemory);
      this->m_aBuckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aBuckets.m_pElements = this->m_aBuckets.m_Memory.m_pMemory;
  CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::Purge(this: &this->m_aDataPool);
  CConCommandHash::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007370
// Name: public: CConCommandHash::~CConCommandHash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandHash::~CConCommandHash(CConCommandHash *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  this->m_aBuckets.m_Size = 0;
  if ( this->m_aBuckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aBuckets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aBuckets.m_Memory.m_pMemory);
      this->m_aBuckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aBuckets.m_pElements = this->m_aBuckets.m_Memory.m_pMemory;
  CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::Purge(this: &this->m_aDataPool);
  CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::RemoveAll(this: &this->m_aDataPool);
  if ( this->m_aDataPool.m_Memory.m_pBlocks != nullptr )
  {
    m_pBlocks = this->m_aDataPool.m_Memory.m_pBlocks;
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_aDataPool.m_Memory.m_pBlocks = nullptr;
    this->m_aDataPool.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>((CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100073F0
// Name: public: bool CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Remove(class ConVar __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Remove(
        CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short> *this,
        ConVar **key)
{
  unsigned __int16 v3; // di
  char v4; // bl
  CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t dummyNode; // [esp+Ch] [ebp-18h] BYREF

  CUtlString::CUtlString(this: (CUtlString *)&dummyNode.elem);
  CUtlString::operator=(this: (CUtlString *)&dummyNode.elem, src: str);
  dummyNode.elem.m_Vars[0].m_pVar = nullptr;
  CUtlString::operator=(this: (CUtlString *)&dummyNode.elem, src: str);
  dummyNode.key = *key;
  dummyNode.elem.m_Vars[0].m_pVar = nullptr;
  v3 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  if ( v3 == 0xFFFF )
  {
    v4 = 0;
  }
  else
  {
    CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_Tree,
      elem: v3);
    CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FreeNode(
      this: &this->m_Tree,
      i: v3);
    --this->m_Tree.m_NumElements;
    v4 = 1;
  }
  dummyNode.elem.m_Vars[0].m_VarName.m_Storage.m_nActualLength = 0;
  if ( dummyNode.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_nGrowSize >= 0
    && dummyNode.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dummyNode.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_pMemory);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100074A0
// Name: public: CCvar::~CCvar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::~CCvar(CCvar *this)
{
  CCvar::CCommandMemberInitializer_Find *p_m_Find_register; // ecx

  p_m_Find_register = &this->m_Find_register;
  p_m_Find_register->m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CCvar>_vtbl *)&CConCommandMemberAccessor<CCvar>::`vftable'{for `ConCommand'};
  this->m_Find_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CCvar>::`vftable'{for `ICommandCallback'};
  this->m_Find_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CCvar>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &p_m_Find_register->m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_Find_register.m_ConCommandAccessor);
  CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>::~CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>(this: &this->m_QueuedConVarSets);
  CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_SplitScreenAddedConVarsMap.m_Tree);
  if ( this->m_TempConsoleBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_TempConsoleBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TempConsoleBuffer.m_Memory.m_pMemory);
      this->m_TempConsoleBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_TempConsoleBuffer.m_Memory.m_nAllocationCount = 0;
  }
  CConCommandHash::~CConCommandHash(this: &this->m_CommandHash);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *,int> > *)&this->m_DisplayFuncs);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *,int> > *)&this->m_GlobalChangeCallbacks);
}

//------------------------------------------------------------------------------
// Address: 0x10007530
// Name: public: CCvar::CCvar(void)
// Source: json
//------------------------------------------------------------------------------
CCvar *__thiscall CCvar::CCvar(CCvar *this)
{
  this->__vftable = (CCvar_vtbl *)&CCvar::`vftable';
  this->m_GlobalChangeCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_GlobalChangeCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_GlobalChangeCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_GlobalChangeCallbacks.m_Size = 0;
  this->m_GlobalChangeCallbacks.m_pElements = nullptr;
  this->m_DisplayFuncs.m_Memory.m_pMemory = nullptr;
  this->m_DisplayFuncs.m_Memory.m_nAllocationCount = 0;
  this->m_DisplayFuncs.m_Memory.m_nGrowSize = 0;
  this->m_DisplayFuncs.m_Size = 0;
  this->m_DisplayFuncs.m_pElements = nullptr;
  CConCommandHash::CConCommandHash(this: &this->m_CommandHash);
  CUtlBuffer::CUtlBuffer(this: &this->m_TempConsoleBuffer, growSize: 0, initSize: 1024, nFlags: 0);
  this->m_SplitScreenAddedConVarsMap.m_Tree.m_LessFunc.m_LessFunc = CDefOps<ConVar *>::LessFunc;
  this->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_SplitScreenAddedConVarsMap.m_Tree.m_pElements = this->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_SplitScreenAddedConVarsMap.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_SplitScreenAddedConVarsMap.m_Tree.m_FirstFree = -1;
  this->m_QueuedConVarSets.m_Memory.m_pMemory = nullptr;
  this->m_QueuedConVarSets.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedConVarSets.m_Memory.m_nGrowSize = 0;
  this->m_QueuedConVarSets.m_Size = 0;
  this->m_QueuedConVarSets.m_pElements = nullptr;
  CCvar::CCommandMemberInitializer_Find::CCommandMemberInitializer_Find(this: &this->m_Find_register);
  this->m_nNextDLLIdentifier = 0;
  this->m_pConCommandList = nullptr;
  this->m_nMaxSplitScreenSlots = 1;
  this->m_bMaterialSystemThreadSetAllowed = false;
  CConCommandHash::Init(this: &this->m_CommandHash);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007600
// Name: public: virtual void CCvar::RemoveSplitScreenConVars(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvar::RemoveSplitScreenConVars(CCvar *this, int id)
{
  int v3; // ebx
  CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short> *p_m_SplitScreenAddedConVarsMap; // esi
  int v5; // esi
  int (*GetDLLIdentifier)(void); // eax
  int v7; // ebx
  ConCommandBase **j; // esi
  int m_Size; // eax
  int v10; // esi
  ConVar **m_pMemory; // ebx
  int v12; // eax
  ConVar **v13; // esi
  ConVar **v14; // edi
  CUtlVector<ConVar *,CUtlMemory<ConVar *,int> > deleted; // [esp+4h] [ebp-1Ch] BYREF
  ConVar *key; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  if ( this->m_nMaxSplitScreenSlots != 1 )
  {
    v3 = 0;
    p_m_SplitScreenAddedConVarsMap = &this->m_SplitScreenAddedConVarsMap;
    memset(&deleted, 0, sizeof(deleted));
    i = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_SplitScreenAddedConVarsMap.m_Tree);
    if ( i != 0xFFFF )
    {
      do
      {
        v5 = (unsigned __int16)i;
        GetDLLIdentifier = (int (*)(void))this->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.key->GetDLLIdentifier;
        key = this->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.key;
        if ( GetDLLIdentifier() == id )
        {
          v7 = 1;
          for ( j = &this->m_SplitScreenAddedConVarsMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem.m_Vars[0].m_pVar;
                v7 < this->m_nMaxSplitScreenSlots;
                j += 5 )
          {
            if ( *j != nullptr )
            {
              this->UnregisterConCommand(this, a2: *j);
              if ( *j != nullptr )
                ((void (__thiscall *)(ConCommandBase *, int))(*j)->dtr_ConCommandBase)(a1: *j, a2: 1);
              *j = nullptr;
            }
            ++v7;
          }
          m_Size = deleted.m_Size;
          v10 = deleted.m_Size;
          if ( deleted.m_Size + 1 > deleted.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<CCoroutineMgr *,int> *)&deleted,
              num: deleted.m_Size - deleted.m_Memory.m_nAllocationCount + 1);
            m_Size = deleted.m_Size;
          }
          m_pMemory = deleted.m_Memory.m_pMemory;
          deleted.m_Size = m_Size + 1;
          v12 = m_Size - v10;
          deleted.m_pElements = deleted.m_Memory.m_pMemory;
          if ( v12 > 0 )
            _V_memmove(
              dest: &deleted.m_Memory.m_pMemory[v10 + 1],
              src: &deleted.m_Memory.m_pMemory[v10],
              count: 4 * v12);
          v13 = &m_pMemory[v10];
          if ( v13 != nullptr )
            *v13 = key;
        }
        p_m_SplitScreenAddedConVarsMap = &this->m_SplitScreenAddedConVarsMap;
        i = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_SplitScreenAddedConVarsMap.m_Tree,
              i);
      }
      while ( i != 0xFFFF );
      v3 = deleted.m_Size;
    }
    if ( v3 > 0 )
    {
      v14 = deleted.m_Memory.m_pMemory;
      do
      {
        CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Remove(
          this: p_m_SplitScreenAddedConVarsMap,
          key: v14++);
        --v3;
      }
      while ( v3 != 0 );
    }
    if ( deleted.m_Memory.m_nGrowSize >= 0 && deleted.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: deleted.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022990
// Name: _CCvar::FindCommandBase_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCvar::FindCommandBase_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100229A0
// Name: _CCvar::FindCommandBase_::_4_::_dynamic_atexit_destructor_for___counter___0
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCvar::FindCommandBase_::_4_::_dynamic_atexit_destructor_for___counter___0()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100229B0
// Name: _dynamic_atexit_destructor_for__s_Cvar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_Cvar__()
{
  CCvar::~CCvar(this: &s_Cvar);
}

//------------------------------------------------------------------------------
// Address: 0x100229C0
// Name: _dynamic_atexit_destructor_for__s_EventSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EventSystem__()
{
  s_EventSystem.__vftable = (CEventSystem_vtbl *)&CEventSystem::`vftable';
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::RemoveAll(this: &s_EventSystem.m_EventIds);
  CUtlMemoryPool::~CUtlMemoryPool(this: &s_EventSystem.m_EventIds.m_EntryMemory);
}

// ============================================================
// Overlay from vstdlib_s (Missing functions)
// ============================================================
namespace vstdlib_s {

//------------------------------------------------------------------------------
// Address: 0x3F606410
// Name: VStdLib_GetICVarFactory
// Source: json
//------------------------------------------------------------------------------
void *VStdLib_GetICVarFactory()
{
  return &CreateInterface_0;
}

//------------------------------------------------------------------------------
// Address: 0x3F607E10
// Name: public: CDefaultCvar::CDefaultCvar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultCvar::CDefaultCvar(CDefaultCvar *this)
{
  JUMPOUT(0x3F607E1F);
}

//------------------------------------------------------------------------------
// Address: 0x3F607E20
// Name: public: ICvar::ICvar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICvar::ICvar(ICvar *this)
{
  JUMPOUT(0x3F607E22);
}

//------------------------------------------------------------------------------
// Address: 0x3F607E30
// Name: void SetCVarIF(class ICvar __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall SetCVarIF(
        ICvar *pCVarIF@<eax>,
        char a2@<zf>,
        char a3@<sf>,
        char a4@<of>,
        _DWORD *a5@<ebx>,
        int a6@<edi>)
{
  int v6; // ecx

  if ( a3 ^ a4 | a2 )
  {
    v6 = 3 * (_DWORD)pCVarIF;
    *(_DWORD *)(a6 + 8 * v6 + 16) = *a5;
    *(_DWORD *)(a6 + 8 * v6 + 20) = a5[1];
    JUMPOUT(0x3F607E44);
  }
  JUMPOUT(0x3F607E5E);
}

//------------------------------------------------------------------------------
// Address: 0x3F607E50
// Name: class ICvar __near * GetCVarIF(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F607E70
// Name: public: virtual bool CDefaultCvar::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __fastcall CDefaultCvar::Connect(
        CDefaultCvar *this,
        void (__cdecl *a2)(ConVar *, const char *),
        void *(__cdecl *factory)(const char *, int *))
{
  this->m_fnGlobalChangeCallback = a2;
  JUMPOUT(0x3F607E75);
}

//------------------------------------------------------------------------------
// Address: 0x3F607E80
// Name: public: virtual enum InitReturnVal_t CDefaultCvar::Init(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F607EA0
// Name: public: virtual void __near * CDefaultCvar::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CDefaultCvar::QueryInterface(CDefaultCvar *this@<ecx>, _DWORD *a2@<edi>)
{
  if ( *a2 != -1 )
    CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t>::ValidateGrowSize();
}

//------------------------------------------------------------------------------
// Address: 0x3F607ED0
// Name: public: virtual class ConVar __near * CDefaultCvar::FindVar(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __thiscall CDefaultCvar::FindVar(CDefaultCvar *this)
{
  ((void (__thiscall *)(CDefaultCvar *))sub_3F608350)(a1: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F607F00
// Name: public: virtual void CDefaultCvar::RegisterConCommandBase(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CDefaultCvar::RegisterConCommandBase(CDefaultCvar *this, ConCommandBase *variable)
{
  CValidator::Pop((CValidator *)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F607FB0
// Name: public: virtual char const __near * CDefaultCvar::GetCommandLineValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const char *__usercall CDefaultCvar::GetCommandLineValue@<eax>(
        CDefaultCvar *this@<ecx>,
        const char *result@<eax>,
        int a3@<edi>,
        _DWORD *a4@<esi>)
{
  _DWORD *v4; // ecx

  v4 = (_DWORD *)(*(_DWORD *)(a3 + 44) + 24 * (_DWORD)result + 16);
  if ( *(_DWORD *)(a3 + 44) + 24 * (_DWORD)result != -16 )
  {
    *v4 = *a4;
    v4[1] = a4[1];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F608020
// Name: public: virtual class ConCommandBase __near * CDefaultCvar::GetCommands(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const ConCommandBase *__usercall CDefaultCvar::GetCommands@<eax>(
        char a1@<al>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  int v5; // eax

  if ( a1 != 0 )
    JUMPOUT(0x3F608027);
  if ( (*(unsigned __int8 (__cdecl **)(int, int))(a4 + 36))(a1: *(_DWORD *)(a4 + 44) + a5 + 16, a2: a3) != 0 )
  {
    if ( a2 == -1 )
      v5 = a4;
    else
      v5 = a5 + *(_DWORD *)(a4 + 44);
    a2 = *(_DWORD *)(v5 + 4);
    if ( a2 != -1 )
      JUMPOUT(0x3F608006);
  }
  return (const ConCommandBase *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F608080
// Name: public: virtual void CDefaultCvar::CallGlobalChangeCallback(class ConVar __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F608550
// Name: _VStdLib_GetICVarFactory
// Source: json
//------------------------------------------------------------------------------
void __usercall VStdLib_GetICVarFactory(int a1@<eax>)
{
  if ( a1 != -1 )
    JUMPOUT(0x3F608558);
  JUMPOUT(0x3F608562);
}

//------------------------------------------------------------------------------
// Address: 0x3F610440
// Name: public: virtual void CDefaultCvar::UnlinkVariables(int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F606420
// Name: sub_3F606420
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __stdcall sub_3F606420(int a1)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F606430
// Name: sub_3F606430
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F606430(_DWORD *this)
{
  *(this + 1) = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F606440
// Name: nullsub_31
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_31()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F607E60
// Name: __CreateCDefaultCvarICvar_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CreateCDefaultCvarICvar_interface()
{
  JUMPOUT(0x3F607E67);
}

} // namespace vstdlib_s
