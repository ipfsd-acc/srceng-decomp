// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/messagelist.cpp
// Functions: 5
// ============================================================

#include "gcsdk\messagelist.h"

//------------------------------------------------------------------------------
// Address: 0x10019A30
// Name: public: GCSDK::CMessageListRegistration::CMessageListRegistration(struct GCSDK::MsgInfo_t __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CMessageListRegistration *__thiscall GCSDK::CMessageListRegistration::CMessageListRegistration(
        GCSDK::CMessageListRegistration *this,
        GCSDK::MsgInfo_t *pMsgInfo,
        int cMsgInfo,
        void *pExtra)
{
  this->m_pMsgInfo = pMsgInfo;
  this->m_cMsgInfo = cMsgInfo;
  this->m_pNext = GCSDK::CMessageListRegistration::sm_pFirst;
  GCSDK::CMessageListRegistration::sm_pFirst = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10019A60
// Name: public: bool GCSDK::CMessageList::GetMessage(unsigned int,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CMessageList::GetMessage(
        GCSDK::CMessageList *this,
        unsigned int eMsg,
        const char **ppMsgName,
        int nTypeMask)
{
  unsigned int v5; // eax
  bool v6; // zf
  __int16 **v7; // eax
  __int16 v8; // ax
  char *PchTempTextBuffer; // esi
  int CchTempTextBuffer; // eax
  CVProfile *v11; // ecx
  GCSDK::MsgInfo_t *v13; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "GetMessage",
    a3: 0,
    a4: "Jobs/Coroutines",
    a5: false,
    a6: 4);
  if ( ppMsgName != nullptr )
    *ppMsgName = "Unknown";
  v5 = eMsg >> 4;
  if ( (signed int)(eMsg >> 4) > this->m_vecMessageInfoBuckets.m_Size
    || (v6 = this->m_vecMessageInfoBuckets.m_Memory.m_pMemory[v5] == nullptr,
        v7 = &this->m_vecMessageInfoBuckets.m_Memory.m_pMemory[v5],
        v6)
    || (v8 = (*v7)[eMsg & 0xF]) == -1 )
  {
    PchTempTextBuffer = GCSDK::GetPchTempTextBuffer();
    CchTempTextBuffer = GCSDK::GetCchTempTextBuffer();
    V_snprintf(pDest: PchTempTextBuffer, maxLen: CchTempTextBuffer, pFormat: "Unknown MsgType (%d) - Not Found", eMsg);
    *ppMsgName = PchTempTextBuffer;
    v11 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
LABEL_7:
    CVProfile::ExitScope(this: v11);
    return 0;
  }
  v13 = &this->m_vecMsgInfo.m_Memory.m_pMemory[v8];
  if ( ppMsgName != nullptr )
    *ppMsgName = v13->pchMsgName;
  v11 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  if ( (nTypeMask & v13->nFlags) == 0 )
    goto LABEL_7;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019B20
// Name: char const __near * GCSDK::PchMsgNameFromEMsg(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GCSDK::PchMsgNameFromEMsg(unsigned int eMsg)
{
  const char *pchMsgName; // [esp+0h] [ebp-4h] BYREF

  pchMsgName = "Unknown";
  GCSDK::CMessageList::GetMessage(this: &GCSDK::g_theMessageList, eMsg, ppMsgName: &pchMsgName, nTypeMask: 1);
  return pchMsgName;
}

//------------------------------------------------------------------------------
// Address: 0x10019B50
// Name: public: void GCSDK::CMessageList::TallySendmessage(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CMessageList::TallySendmessage(
        GCSDK::CMessageList *this,
        unsigned int eMsgType,
        unsigned int unMsgSize)
{
  unsigned int v3; // eax
  bool v4; // zf
  __int16 **v5; // eax
  __int16 v6; // ax
  unsigned int v7; // eax
  GCSDK::MsgInfo_t *m_pMemory; // ecx
  bool v9; // cf

  v3 = eMsgType >> 4;
  if ( (signed int)(eMsgType >> 4) <= this->m_vecMessageInfoBuckets.m_Size )
  {
    v4 = this->m_vecMessageInfoBuckets.m_Memory.m_pMemory[v3] == nullptr;
    v5 = &this->m_vecMessageInfoBuckets.m_Memory.m_pMemory[v3];
    if ( !v4 )
    {
      v6 = (*v5)[eMsgType & 0xF];
      if ( v6 != -1 )
      {
        v7 = v6;
        ++this->m_vecMsgInfo.m_Memory.m_pMemory[v7].nTimesSent;
        m_pMemory = this->m_vecMsgInfo.m_Memory.m_pMemory;
        v9 = __CFADD__(unMsgSize, m_pMemory[v7].uBytesSent);
        LODWORD(m_pMemory[v7].uBytesSent) += unMsgSize;
        HIDWORD(m_pMemory[v7].uBytesSent) += v9;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019BB0
// Name: public: GCSDK::CMessageList::~CMessageList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CMessageList::~CMessageList(GCSDK::CMessageList *this)
{
  int i; // edi
  GCSDK::MsgInfo_t *m_pMemory; // eax
  __int16 **v4; // eax

  for ( i = 0; i < this->m_vecMessageInfoBuckets.m_Size; ++i )
  {
    if ( this->m_vecMessageInfoBuckets.m_Memory.m_pMemory[i] != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecMessageInfoBuckets.m_Memory.m_pMemory[i]);
      this->m_vecMessageInfoBuckets.m_Memory.m_pMemory[i] = nullptr;
    }
  }
  this->m_vecMessageInfoBuckets.m_Size = 0;
  this->m_vecMsgInfo.m_Size = 0;
  if ( this->m_vecMsgInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecMsgInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecMsgInfo.m_Memory.m_pMemory);
      this->m_vecMsgInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecMsgInfo.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_vecMsgInfo.m_Memory.m_pMemory;
  this->m_vecMsgInfo.m_pElements = m_pMemory;
  if ( this->m_vecMsgInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_vecMsgInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecMsgInfo.m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecMessageInfoBuckets.m_Size = 0;
  if ( this->m_vecMessageInfoBuckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecMessageInfoBuckets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecMessageInfoBuckets.m_Memory.m_pMemory);
      this->m_vecMessageInfoBuckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecMessageInfoBuckets.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_vecMessageInfoBuckets.m_Memory.m_pMemory;
  this->m_vecMessageInfoBuckets.m_pElements = this->m_vecMessageInfoBuckets.m_Memory.m_pMemory;
  if ( this->m_vecMessageInfoBuckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      this->m_vecMessageInfoBuckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecMessageInfoBuckets.m_Memory.m_nAllocationCount = 0;
  }
}
