// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/choreoactor.cpp
// Functions: 14
// ============================================================

#include "game\shared\choreoactor.h"

//------------------------------------------------------------------------------
// Address: 0x0040F020
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x0040F040
// Name: public: char const __near * CChoreoActor::GetName(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::GetName(CChoreoActor *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F050
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x0040F070
// Name: public: char const __near * CChoreoActor::GetFacePoserModelName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoActor::GetFacePoserModelName(CChoreoActor *this)
{
  return this->m_szFacePoserModelName;
}

//------------------------------------------------------------------------------
// Address: 0x0040F080
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x0040F090
// Name: public: bool CChoreoActor::GetActive(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoActor::GetActive(CChoreoActor *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x0040F0A0
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040F0B0
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x0040F0E0
// Name: public: void CChoreoActor::MarkForSaveAll(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::MarkForSaveAll(CChoreoActor *this, bool mark)
{
  int m_Size; // ebp
  int v4; // esi
  CChoreoChannel *v5; // ecx

  m_Size = this->m_Channels.m_Size;
  v4 = 0;
  for ( this->m_bMarkedForSave = mark; v4 < m_Size; ++v4 )
  {
    if ( v4 < 0 || v4 >= this->m_Channels.m_Size )
      v5 = nullptr;
    else
      v5 = this->m_Channels.m_Memory.m_pMemory[v4];
    CChoreoChannel::MarkForSaveAll(this: v5, mark);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F130
// Name: public: class CChoreoChannel __near * CChoreoActor::FindChannel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::FindChannel(CChoreoActor *this, const char *name)
{
  int m_Size; // ebp
  int v4; // esi
  CChoreoChannel *v5; // edi
  char *v6; // eax

  m_Size = this->m_Channels.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = v4 < 0 || v4 >= this->m_Channels.m_Size ? nullptr : this->m_Channels.m_Memory.m_pMemory[v4];
    v6 = CChoreoChannel::GetName(this: v5);
    if ( _stricmp(dst: v6, src: name) == 0 )
      break;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040F190
// Name: public: void CChoreoActor::RemoveAllChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::RemoveAllChannels(CChoreoActor *this)
{
  this->m_Channels.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040F1A0
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F1E0
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CChoreoChannel *channel)
{
  CUtlVector<CChoreoActor *,CUtlMemory<CChoreoActor *,int>>::InsertBefore(
    this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&this->m_Channels,
    elem: this->m_Channels.m_Size,
    src: (KeyValues **)&channel);
}

//------------------------------------------------------------------------------
// Address: 0x0040F200
// Name: public: class CChoreoActor __near & CChoreoActor::operator=(class CChoreoActor const __near &)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::operator=(CChoreoActor *this, const CChoreoActor *src)
{
  CUtlMemory<KeyValues *,int> *p_m_Channels; // esi
  const CChoreoChannel *v5; // edi
  CChoreoChannel *v6; // eax
  CChoreoChannel *v7; // ebx
  KeyValues **m_pMemory; // edi
  int m_nAllocationCount; // eax
  KeyValues **v10; // ecx
  int v11; // eax
  bool v12; // zf
  CChoreoChannel **v13; // eax
  int i; // [esp+10h] [ebp+4h]

  this->m_bActive = src->m_bActive;
  V_strncpy(pDest: this->m_szName, pSrc: src->m_szName, maxLen: 128);
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: src->m_szFacePoserModelName, maxLen: 128);
  i = 0;
  if ( src->m_Channels.m_Size <= 0 )
    return this;
  p_m_Channels = (CUtlMemory<KeyValues *,int> *)&this->m_Channels;
  do
  {
    v5 = src->m_Channels.m_Memory.m_pMemory[i];
    v6 = (CChoreoChannel *)operator new(nSize: 0x9Cu);
    if ( v6 != nullptr )
      v7 = CChoreoChannel::CChoreoChannel(this: v6);
    else
      v7 = nullptr;
    CChoreoChannel::SetActor(this: v7, actor: this);
    CChoreoChannel::operator=(this: v7, src: v5);
    m_pMemory = p_m_Channels[1].m_pMemory;
    m_nAllocationCount = p_m_Channels->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Channels, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_Channels[1].m_pMemory;
    v10 = p_m_Channels->m_pMemory;
    v11 = (char *)p_m_Channels[1].m_pMemory - (char *)m_pMemory - 1;
    v12 = (char *)p_m_Channels[1].m_pMemory - (char *)m_pMemory == 1;
    p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
    if ( v11 >= 0 && !v12 )
      memmove(
        dst: (unsigned __int8 *)&v10[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v10[(_DWORD)m_pMemory],
        count: 4 * v11);
    v13 = (CChoreoChannel **)&p_m_Channels->m_pMemory[(_DWORD)m_pMemory];
    if ( v13 != nullptr )
      *v13 = v7;
    ++i;
  }
  while ( i < src->m_Channels.m_Size );
  return this;
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x00404AD0
// Name: public: char const __near * CChoreoActor::GetName(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::GetName(CChoreoActor *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004ABB70
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x004ABB90
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x004ABBB0
// Name: public: char const __near * CChoreoActor::GetFacePoserModelName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoActor::GetFacePoserModelName(CChoreoActor *this)
{
  return this->m_szFacePoserModelName;
}

//------------------------------------------------------------------------------
// Address: 0x004ABBC0
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x004ABBD0
// Name: public: bool CChoreoActor::GetActive(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoActor::GetActive(CChoreoActor *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x004ABBE0
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004ABBF0
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x004ABC20
// Name: public: void CChoreoActor::SwapChannels(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SwapChannels(CChoreoActor *this, int c1, int c2)
{
  CChoreoChannel **m_pMemory; // eax
  CChoreoChannel *v4; // esi

  m_pMemory = this->m_Channels.m_Memory.m_pMemory;
  v4 = m_pMemory[c1];
  m_pMemory[c1] = m_pMemory[c2];
  this->m_Channels.m_Memory.m_pMemory[c2] = v4;
}

//------------------------------------------------------------------------------
// Address: 0x004ABC50
// Name: public: int CChoreoActor::FindChannelIndex(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::FindChannelIndex(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_Size; // edx
  int result; // eax
  CChoreoChannel **i; // ecx

  m_Size = this->m_Channels.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Channels.m_Memory.m_pMemory; channel != *i; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004ABC90
// Name: public: void CChoreoActor::MarkForSaveAll(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::MarkForSaveAll(CChoreoActor *this, bool mark)
{
  int m_Size; // ebx
  int v4; // esi
  CChoreoChannel *v5; // ecx

  m_Size = this->m_Channels.m_Size;
  v4 = 0;
  for ( this->m_bMarkedForSave = mark; v4 < m_Size; ++v4 )
  {
    if ( v4 < 0 || v4 >= this->m_Channels.m_Size )
      v5 = nullptr;
    else
      v5 = this->m_Channels.m_Memory.m_pMemory[v4];
    CChoreoChannel::MarkForSaveAll(this: v5, mark);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ABCE0
// Name: public: class CChoreoChannel __near * CChoreoActor::FindChannel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::FindChannel(CChoreoActor *this, const char *name)
{
  int v3; // esi
  CChoreoChannel *v4; // edi
  const char *v5; // eax
  int c; // [esp+Ch] [ebp-4h]

  v3 = 0;
  c = this->m_Channels.m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = v3 < 0 || v3 >= this->m_Channels.m_Size ? nullptr : this->m_Channels.m_Memory.m_pMemory[v3];
    v5 = CChoreoChannel::GetName(this: v4);
    if ( _V_stricmp(s1: v5, s2: name) == 0 )
      break;
    if ( ++v3 >= c )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004ABD50
// Name: public: void CChoreoActor::RemoveChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::RemoveChannel(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_Size; // edx
  int v4; // eax
  CChoreoChannel **i; // ecx

  m_Size = this->m_Channels.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_Channels.m_Memory.m_pMemory; channel != *i; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      if ( m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: &this->m_Channels.m_Memory.m_pMemory[v4],
          src: &this->m_Channels.m_Memory.m_pMemory[v4 + 1],
          count: 4 * (m_Size - v4 - 1));
      --this->m_Channels.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ABDC0
// Name: public: void CChoreoActor::RemoveAllChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::RemoveAllChannels(CChoreoActor *this)
{
  this->m_Channels.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004ABDD0
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004ABE10
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Channels; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)channel;
}

//------------------------------------------------------------------------------
// Address: 0x004ABE80
// Name: public: void CChoreoActor::SaveToBuffer(class CUtlBuffer __near &,class CChoreoScene __near *,class IChoreoStringPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SaveToBuffer(
        CChoreoActor *this,
        CUtlBuffer *buf,
        CChoreoScene *pScene,
        IChoreoStringPool *pStringPool)
{
  __int16 v5; // ax
  int m_Size; // ebx
  int i; // edi
  CChoreoChannel *v8; // ecx
  bool m_bActive; // bl
  int m_Put; // eax
  bool v11; // bl

  v5 = pStringPool->FindOrAddString(this: pStringPool, a2: this->m_szName);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%hd", v5);
  else
    CUtlBuffer::PutTypeBin<short>(this: buf, src: v5);
  m_Size = this->m_Channels.m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "%hu", (unsigned __int8)m_Size);
  }
  else if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = m_Size;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
  for ( i = 0; i < m_Size; ++i )
  {
    if ( i < 0 || i >= this->m_Channels.m_Size )
      v8 = nullptr;
    else
      v8 = this->m_Channels.m_Memory.m_pMemory[i];
    CChoreoChannel::SaveToBuffer(this: v8, buf, pScene, pStringPool);
  }
  m_bActive = this->m_bActive;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  v11 = m_bActive;
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = v11;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ABFA0
// Name: public: class CChoreoActor __near & CChoreoActor::operator=(class CChoreoActor const __near &)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::operator=(CChoreoActor *this, const CChoreoActor *src)
{
  const CChoreoActor *v2; // edi
  const CChoreoChannel *v4; // edi
  CChoreoChannel *v5; // eax
  CChoreoChannel *v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CChoreoChannel **m_pMemory; // ecx
  int v10; // eax
  CChoreoChannel **v11; // eax
  int i; // [esp+Ch] [ebp-4h]

  v2 = src;
  this->m_bActive = src->m_bActive;
  V_strncpy(pDest: this->m_szName, pSrc: src->m_szName, maxLen: 128);
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: src->m_szFacePoserModelName, maxLen: 128);
  i = 0;
  if ( src->m_Channels.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = v2->m_Channels.m_Memory.m_pMemory[i];
      v5 = (CChoreoChannel *)operator new(nSize: 0x9Cu);
      if ( v5 != nullptr )
        v6 = CChoreoChannel::CChoreoChannel(this: v5);
      else
        v6 = nullptr;
      CChoreoChannel::SetActor(this: v6, actor: this);
      CChoreoChannel::operator=(this: v6, src: v4);
      m_Size = this->m_Channels.m_Size;
      m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Channels,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Channels.m_Size;
      m_pMemory = this->m_Channels.m_Memory.m_pMemory;
      v10 = this->m_Channels.m_Size - m_Size - 1;
      this->m_Channels.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &this->m_Channels.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        *v11 = v6;
      if ( ++i >= src->m_Channels.m_Size )
        break;
      v2 = src;
    }
  }
  return this;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x101AA020
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101AA040
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101AA060
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x101AA070
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101AA080
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x101AA0B0
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101AA0F0
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, vgui::TreeNode *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Channels; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = channel;
}

//------------------------------------------------------------------------------
// Address: 0x105C1F40
// Name: _dynamic_initializer_for__choreo_spew_filter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__choreo_spew_filter__()
{
  ConVar::ConVar(
    this: &choreo_spew_filter,
    pName: "choreo_spew_filter",
    pDefaultValue: &var,
    flags: 0x2000,
    pHelpString: "Spew choreo. Use a sub-string or * to display all events.");
  return atexit(func: dynamic_atexit_destructor_for__choreo_spew_filter__);
}

//------------------------------------------------------------------------------
// Address: 0x105CBA50
// Name: _dynamic_atexit_destructor_for__choreo_spew_filter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__choreo_spew_filter__()
{
  ConVar::~ConVar(this: &choreo_spew_filter);
}

//------------------------------------------------------------------------------
// Address: 0x105C1F70
// Name: _dynamic_initializer_for__g_CheckNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckEventNames *dynamic_initializer_for__g_CheckNamesSingleton__()
{
  return CCheckEventNames::CCheckEventNames(this: &g_CheckNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x105C1F80
// Name: _dynamic_initializer_for__g_CheckCCNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckCCNames *dynamic_initializer_for__g_CheckCCNamesSingleton__()
{
  return CCheckCCNames::CCheckCCNames(this: &g_CheckCCNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x105C1F90
// Name: _dynamic_initializer_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataModel__()
{
  CDataModel::CDataModel(this: &g_DataModel);
  return atexit(func: dynamic_atexit_destructor_for__g_DataModel__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1FB0
// Name: _dynamic_initializer_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &DmAttributeList_t::s_Allocator,
    blockSize: 8,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "DmAttributeList_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CBA60
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x105CBA70
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

} // namespace hammer_dll

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x004222E0
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x00422300
// Name: public: char const __near * CChoreoActor::GetName(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::GetName(CChoreoActor *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00422310
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x00422330
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x00422340
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00422350
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x00422380
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004223C0
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CUtlSymbolTable::StringPool_t *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Channels; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = channel;
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x004C1E50
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x004C1E70
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x004C1E90
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x004C1EA0
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004C1EB0
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x004C1EE0
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1F20
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Channels; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<S3RGBA,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)channel;
}

//------------------------------------------------------------------------------
// Address: 0x004C1F90
// Name: public: void CChoreoActor::SaveToBuffer(class CUtlBuffer __near &,class CChoreoScene __near *,class IChoreoStringPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SaveToBuffer(
        CChoreoActor *this,
        CUtlBuffer *buf,
        CChoreoScene *pScene,
        IChoreoStringPool *pStringPool)
{
  signed __int16 v5; // ax
  int m_Size; // ebx
  int i; // edi
  CChoreoChannel *v8; // ecx
  bool m_bActive; // bl
  int m_Put; // eax
  bool v11; // bl

  v5 = pStringPool->FindOrAddString(this: pStringPool, a2: this->m_szName);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%hd", v5);
  else
    CUtlBuffer::PutTypeBin<short>(this: buf, src: v5);
  m_Size = this->m_Channels.m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "%hu", (unsigned __int8)m_Size);
  }
  else if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = m_Size;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
  for ( i = 0; i < m_Size; ++i )
  {
    if ( i < 0 || i >= this->m_Channels.m_Size )
      v8 = nullptr;
    else
      v8 = this->m_Channels.m_Memory.m_pMemory[i];
    CChoreoChannel::SaveToBuffer(this: v8, buf, pScene, pStringPool);
  }
  m_bActive = this->m_bActive;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  v11 = m_bActive;
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = v11;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x004282C0
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x004282E0
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x00428300
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x00428310
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00428320
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x00428350
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428390
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Channels; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)channel;
}

} // namespace scenemanager

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00409AE0
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x00409B00
// Name: public: char const __near * CChoreoActor::GetName(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::GetName(CChoreoActor *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409B10
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x00409B30
// Name: public: char const __near * CChoreoActor::GetFacePoserModelName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoActor::GetFacePoserModelName(CChoreoActor *this)
{
  return this->m_szFacePoserModelName;
}

//------------------------------------------------------------------------------
// Address: 0x00409B40
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x00409B50
// Name: public: bool CChoreoActor::GetActive(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoActor::GetActive(CChoreoActor *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x00409B60
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00409B70
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x00409BA0
// Name: public: void CChoreoActor::MarkForSaveAll(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::MarkForSaveAll(CChoreoActor *this, bool mark)
{
  int m_Size; // ebx
  int v4; // esi
  CChoreoChannel *v5; // ecx

  m_Size = this->m_Channels.m_Size;
  v4 = 0;
  for ( this->m_bMarkedForSave = mark; v4 < m_Size; ++v4 )
  {
    if ( v4 < 0 || v4 >= this->m_Channels.m_Size )
      v5 = nullptr;
    else
      v5 = this->m_Channels.m_Memory.m_pMemory[v4];
    CChoreoChannel::MarkForSaveAll(this: v5, mark);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409BF0
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409C30
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Channels; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)channel;
}

} // namespace vcdupdate

// ============================================================
// Overlay from vcd_sound_check (Missing functions)
// ============================================================
namespace vcd_sound_check {

//------------------------------------------------------------------------------
// Address: 0x0040F1C0
// Name: public: char const __near * CChoreoActor::GetName(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::GetName(CChoreoActor *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F1D0
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x0040F1F0
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x0040F210
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x0040F240
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F280
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CUtlSymbolTable::StringPool_t *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Channels; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = channel;
}

} // namespace vcd_sound_check

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102BE7D0
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x102BE7F0
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x102BE810
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x102BE820
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102BE830
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x102BE860
// Name: public: int CChoreoActor::FindChannelIndex(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::FindChannelIndex(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_Size; // edx
  int result; // eax
  CChoreoChannel **i; // ecx

  m_Size = this->m_Channels.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Channels.m_Memory.m_pMemory; channel != *i; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BE8A0
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BE8E0
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Channels; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)channel;
}

//------------------------------------------------------------------------------
// Address: 0x102BE950
// Name: public: bool CChoreoActor::RestoreFromBuffer(class CUtlBuffer __near &,class CChoreoScene __near *,class IChoreoStringPool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoActor::RestoreFromBuffer(
        CChoreoActor *this,
        CUtlBuffer *buf,
        CChoreoScene *pScene,
        IChoreoStringPool *pStringPool)
{
  IChoreoStringPool_vtbl *v5; // esi
  CChoreoActor *v6; // edi
  __int16 Short; // ax
  unsigned __int8 UnsignedShort; // al
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Channels; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v13; // eax
  CChoreoChannel **v14; // eax
  unsigned __int8 v15; // cl
  char sz[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int c; // [esp+10Ch] [ebp-Ch]
  int i; // [esp+110h] [ebp-8h]
  CChoreoActor *actor; // [esp+114h] [ebp-4h]
  CChoreoChannel *channel; // [esp+120h] [ebp+8h]

  v5 = pStringPool->__vftable;
  v6 = this;
  actor = this;
  Short = CUtlBuffer::GetShort(this: buf);
  v5->GetString(this: pStringPool, a2: Short, a3: sz, a4: 256);
  V_strncpy(pDest: v6->m_szName, pSrc: sz, maxLen: 128);
  if ( (buf->m_Flags & 1) != 0 )
  {
    UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
  }
  else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
  }
  else
  {
    UnsignedShort = 0;
  }
  c = UnsignedShort;
  i = 0;
  if ( UnsignedShort != 0 )
  {
    while ( 1 )
    {
      channel = CChoreoScene::AllocChannel(this: pScene);
      if ( !CChoreoChannel::RestoreFromBuffer(this: channel, buf, pScene, pActor: v6, pStringPool) )
        return 0;
      m_nAllocationCount = v6->m_Channels.m_Memory.m_nAllocationCount;
      p_m_Channels = (CUtlMemory<vgui::TreeNode *,int> *)&v6->m_Channels;
      m_Size = v6->m_Channels.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
      ++p_m_Channels[1].m_pMemory;
      m_pMemory = p_m_Channels->m_pMemory;
      v13 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
      p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v13);
      v14 = (CChoreoChannel **)&p_m_Channels->m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = channel;
      CChoreoChannel::SetActor(this: channel, actor);
      v6 = actor;
      if ( ++i >= c )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      v15 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
    else
      v15 = 0;
    v6->m_bActive = v15 == 1;
    return 1;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1034FF30
// Name: public: void CChoreoActor::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x1034FF50
// Name: public: void CChoreoActor::SetFacePoserModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetFacePoserModelName(CChoreoActor *this, const char *name)
{
  V_strncpy(pDest: this->m_szFacePoserModelName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x1034FF70
// Name: public: void CChoreoActor::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::SetActive(CChoreoActor *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x1034FF80
// Name: public: int CChoreoActor::GetNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::GetNumChannels(CChoreoActor *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1034FF90
// Name: public: class CChoreoChannel __near * CChoreoActor::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoActor::GetChannel(CChoreoActor *this, int channel)
{
  if ( channel < 0 || channel >= this->m_Channels.m_Size )
    return nullptr;
  else
    return this->m_Channels.m_Memory.m_pMemory[channel];
}

//------------------------------------------------------------------------------
// Address: 0x1034FFC0
// Name: public: int CChoreoActor::FindChannelIndex(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActor::FindChannelIndex(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_Size; // edx
  int result; // eax
  CChoreoChannel **i; // ecx

  m_Size = this->m_Channels.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Channels.m_Memory.m_pMemory; channel != *i; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10350000
// Name: public: CChoreoActor::CChoreoActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoActor::CChoreoActor(CChoreoActor *this)
{
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szFacePoserModelName[0] = 0;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10350040
// Name: public: void CChoreoActor::AddChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActor::AddChannel(CChoreoActor *this, CChoreoChannel *channel)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Channels; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Channels.m_Memory.m_nAllocationCount;
  p_m_Channels = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Channels;
  m_Size = this->m_Channels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Channels[1].m_pMemory;
  m_pMemory = p_m_Channels->m_pMemory;
  v6 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
  p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Channels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)channel;
}

//------------------------------------------------------------------------------
// Address: 0x103500B0
// Name: public: bool CChoreoActor::RestoreFromBuffer(class CUtlBuffer __near &,class CChoreoScene __near *,class IChoreoStringPool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoActor::RestoreFromBuffer(
        CChoreoActor *this,
        CChoreoChannel *buf,
        CChoreoScene *pScene,
        IChoreoStringPool *pStringPool)
{
  IChoreoStringPool_vtbl *v5; // esi
  CChoreoActor *v6; // edi
  __int16 Short; // ax
  unsigned __int8 UnsignedShort; // al
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Channels; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v13; // eax
  CChoreoChannel **v14; // eax
  unsigned __int8 v15; // cl
  char sz[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int c; // [esp+10Ch] [ebp-Ch]
  int i; // [esp+110h] [ebp-8h]
  CChoreoActor *actor; // [esp+114h] [ebp-4h]
  CChoreoChannel *channel; // [esp+120h] [ebp+8h]

  v5 = pStringPool->__vftable;
  v6 = this;
  actor = this;
  Short = CUtlBuffer::GetShort(this: (CUtlBuffer *)buf);
  v5->GetString(this: pStringPool, a2: Short, a3: sz, a4: 256);
  V_strncpy(pDest: v6->m_szName, pSrc: sz, maxLen: 128);
  if ( (buf->m_szName[17] & 1) != 0 )
  {
    UnsignedShort = CUtlBuffer::GetUnsignedShort(this: (CUtlBuffer *)buf);
  }
  else if ( CUtlBuffer::CheckGet(this: (CUtlBuffer *)buf, nSize: 1) )
  {
    UnsignedShort = buf->m_pActor->m_szName[(*(_DWORD *)&buf->m_szName[8])++ - *(_DWORD *)&buf->m_szName[28]];
  }
  else
  {
    UnsignedShort = 0;
  }
  c = UnsignedShort;
  i = 0;
  if ( UnsignedShort != 0 )
  {
    while ( 1 )
    {
      channel = CChoreoScene::AllocChannel(this: pScene);
      if ( !CChoreoChannel::RestoreFromBuffer(this: channel, (CUtlBuffer *)buf, pScene, pActor: v6, pStringPool) )
        return 0;
      m_nAllocationCount = v6->m_Channels.m_Memory.m_nAllocationCount;
      p_m_Channels = (CUtlMemory<vgui::TreeNode *,int> *)&v6->m_Channels;
      m_Size = v6->m_Channels.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Channels, num: m_Size - m_nAllocationCount + 1);
      ++p_m_Channels[1].m_pMemory;
      m_pMemory = p_m_Channels->m_pMemory;
      v13 = (int)p_m_Channels[1].m_pMemory - m_Size - 1;
      p_m_Channels[1].m_nAllocationCount = (int)p_m_Channels->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
      v14 = (CChoreoChannel **)&p_m_Channels->m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = channel;
      CAI_WaypointList::Set(this: channel, actor);
      v6 = actor;
      if ( ++i >= c )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    if ( CUtlBuffer::CheckGet(this: (CUtlBuffer *)buf, nSize: 1) )
      v15 = buf->m_pActor->m_szName[(*(_DWORD *)&buf->m_szName[8])++ - *(_DWORD *)&buf->m_szName[28]];
    else
      v15 = 0;
    v6->m_bActive = v15 == 1;
    return 1;
  }
}

} // namespace server
