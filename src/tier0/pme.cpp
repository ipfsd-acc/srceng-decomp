// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/pme.cpp
// Functions: 65
// ============================================================

#include "tier0\pme.h"

//------------------------------------------------------------------------------
// Address: 0x10001E50
// Name: protected: int CVProfile::VTuneGroupID(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?GetName@CTestCase@@UAEPBDXZ'
char *__thiscall CVProfile::VTuneGroupID(CCommandLine *this)
{
  return this->m_pszCmdLine;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD70
// Name: public: int CVProfNode::GetBudgetGroupID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetBudgetGroupID(CVProfNode *this)
{
  return this->m_BudgetGroupID;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD80
// Name: public: void CVProfNode::SetBudgetGroupID(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::SetBudgetGroupID(CVProfNode *this, int id)
{
  this->m_BudgetGroupID = id;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD90
// Name: public: void CVProfNode::SetClientData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::SetClientData(CVProfNode *this, int iClientData)
{
  this->m_iClientData = iClientData;
}

//------------------------------------------------------------------------------
// Address: 0x1000ADA0
// Name: public: int CVProfNode::GetClientData(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetClientData(CVProfNode *this)
{
  return this->m_iClientData;
}

//------------------------------------------------------------------------------
// Address: 0x1000ADB0
// Name: private: void CVProfNode::SetUniqueNodeID(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::SetUniqueNodeID(CVProfNode *this, int id)
{
  this->m_iUniqueNodeID = id;
}

//------------------------------------------------------------------------------
// Address: 0x1000ADC0
// Name: private: int CVProfNode::GetUniqueNodeID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetUniqueNodeID(CVProfNode *this)
{
  return this->m_iUniqueNodeID;
}

//------------------------------------------------------------------------------
// Address: 0x1000ADD0
// Name: public: class CVProfNode __near & CVProfNode::operator=(class CVProfNode const __near &)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfNode::operator=(CVProfNode *this, const CVProfNode *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000ADF0
// Name: public: void CVProfile::SetTargetThreadId(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::SetTargetThreadId(CVProfile *this, unsigned int id)
{
  this->m_TargetThreadId = id;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE00
// Name: public: unsigned int CVProfile::GetTargetThreadId(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVProfile::GetTargetThreadId(CVProfile *this)
{
  return this->m_TargetThreadId;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE10
// Name: public: bool CVProfile::InTargetThread(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVProfile::InTargetThread(CVProfile *this)
{
  return this->m_TargetThreadId == GetCurrentThreadId();
}

//------------------------------------------------------------------------------
// Address: 0x1000AE30
// Name: public: void CVProfile::EnableVTuneGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::EnableVTuneGroup(CVProfile *this, const char *pGroupName)
{
  this->m_nVTuneGroupID = CVProfile::BudgetGroupNameToBudgetGroupID(this, pBudgetGroupName: pGroupName);
  this->m_bVTuneGroupEnabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE50
// Name: public: void CVProfile::DisableVTuneGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::DisableVTuneGroup(CVProfile *this)
{
  this->m_bVTuneGroupEnabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE60
// Name: public: int CVProfile::NumFramesSampled(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::NumFramesSampled(CVProfile *this)
{
  return this->m_nFrames;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE70
// Name: public: int CVProfile::BudgetGroupNameToBudgetGroupIDNoCreate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::BudgetGroupNameToBudgetGroupIDNoCreate(CVProfile *this, const char *pBudgetGroupName)
{
  return CVProfile::FindBudgetGroupName(this, pBudgetGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x1000AEB0
// Name: public: void CVProfile::PMEInitialized(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::PMEInitialized(CVProfile *this, bool bInit)
{
  this->m_bPMEInit = bInit;
}

//------------------------------------------------------------------------------
// Address: 0x1000AEC0
// Name: public: void CVProfile::PMEEnable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::PMEEnable(CVProfile *this, bool bEnable)
{
  this->m_bPMEEnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1000AED0
// Name: public: bool CVProfile::UsePME(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVProfile::UsePME(CVProfile *this)
{
  return this->m_bPMEInit && this->m_bPMEEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x1000AEF0
// Name: protected: bool CVProfile::VTuneGroupEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVProfile::VTuneGroupEnabled(CVProfile *this)
{
  return this->m_bVTuneGroupEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x1000AF00
// Name: public: class CVProfile __near & CVProfile::operator=(class CVProfile const __near &)
// Source: json
//------------------------------------------------------------------------------
CVProfile *__thiscall CVProfile::operator=(CVProfile *this, const CVProfile *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000AF20
// Name: public: void CVProfile::PushGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::PushGroup(CVProfile *this, int nGroupID)
{
  this->m_GroupIDStack[this->m_GroupIDStackDepth++] = nGroupID;
  if ( *((_DWORD *)&this->m_bVTuneGroupEnabled + this->m_GroupIDStackDepth) != nGroupID
    && this->m_bVTuneGroupEnabled
    && nGroupID == this->m_nVTuneGroupID )
  {
    vtune(resume: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AF60
// Name: public: void CVProfile::PopGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::PopGroup(CVProfile *this)
{
  int v1; // eax
  int v2; // edx

  v1 = --this->m_GroupIDStackDepth;
  v2 = this->m_GroupIDStack[v1 + 1];
  if ( this->m_GroupIDStack[v1] != v2 && this->m_bVTuneGroupEnabled && v2 == this->m_nVTuneGroupID )
    vtune(resume: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000AF90
// Name: public: class CVProfNode __near * CVProfNode::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?GetCallParam@CWorkerThread@@QBEIXZ'
CVProfNode *__thiscall CVProfNode::GetParent(CVProfNode *this)
{
  return this->m_pParent;
}

//------------------------------------------------------------------------------
// Address: 0x1000AFA0
// Name: public: class CVProfNode __near * CVProfNode::GetSibling(void)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfNode::GetSibling(CVProfNode *this)
{
  return this->m_pSibling;
}

//------------------------------------------------------------------------------
// Address: 0x1000AFB0
// Name: public: class CVProfNode __near * CVProfNode::GetChild(void)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfNode::GetChild(CVProfNode *this)
{
  return this->m_pChild;
}

//------------------------------------------------------------------------------
// Address: 0x1000AFC0
// Name: public: int CVProfNode::GetTotalCalls(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVProfNode::GetTotalCalls(CVProfNode *this)
{
  return this->m_nTotalCalls;
}

//------------------------------------------------------------------------------
// Address: 0x1000AFD0
// Name: public: double CVProfNode::GetTotalTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfNode::GetTotalTime(CVProfNode *this)
{
  return (double)this->m_TotalTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1000B010
// Name: public: int CVProfNode::GetCurCalls(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVProfNode::GetCurCalls(CVProfNode *this)
{
  return this->m_nCurFrameCalls;
}

//------------------------------------------------------------------------------
// Address: 0x1000B020
// Name: public: double CVProfNode::GetCurTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfNode::GetCurTime(CVProfNode *this)
{
  return (double)this->m_CurFrameTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1000B060
// Name: public: int CVProfNode::GetPrevCalls(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVProfNode::GetPrevCalls(CVProfNode *this)
{
  return this->m_nPrevFrameCalls;
}

//------------------------------------------------------------------------------
// Address: 0x1000B070
// Name: public: double CVProfNode::GetPrevTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfNode::GetPrevTime(CVProfNode *this)
{
  return (double)this->m_PrevFrameTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1000B0B0
// Name: public: double CVProfNode::GetPeakTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfNode::GetPeakTime(CVProfNode *this)
{
  return (double)this->m_PeakTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1000B0F0
// Name: public: double CVProfNode::GetTotalTimeLessChildren(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfNode::GetTotalTimeLessChildren(CVProfNode *this)
{
  CVProfNode *m_pChild; // eax
  long double result; // st7
  unsigned int m_Int64; // edx
  unsigned int m_Int64_high; // ecx

  m_pChild = this->m_pChild;
  for ( result = (double)this->m_TotalTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
        m_pChild != nullptr;
        result = result - (double)__PAIR64__(m_Int64_high, m_Int64) * g_ClockSpeedMillisecondsMultiplier )
  {
    m_Int64 = m_pChild->m_TotalTime.m_Int64;
    m_Int64_high = HIDWORD(m_pChild->m_TotalTime.m_Int64);
    m_pChild = m_pChild->m_pSibling;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B180
// Name: public: double CVProfNode::GetCurTimeLessChildren(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfNode::GetCurTimeLessChildren(CVProfNode *this)
{
  CVProfNode *m_pChild; // eax
  long double result; // st7
  unsigned int m_Int64; // edx
  unsigned int m_Int64_high; // ecx

  m_pChild = this->m_pChild;
  for ( result = (double)this->m_CurFrameTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
        m_pChild != nullptr;
        result = result - (double)__PAIR64__(m_Int64_high, m_Int64) * g_ClockSpeedMillisecondsMultiplier )
  {
    m_Int64 = m_pChild->m_CurFrameTime.m_Int64;
    m_Int64_high = HIDWORD(m_pChild->m_CurFrameTime.m_Int64);
    m_pChild = m_pChild->m_pSibling;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B210
// Name: public: double CVProfNode::GetPrevTimeLessChildren(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfNode::GetPrevTimeLessChildren(CVProfNode *this)
{
  CVProfNode *m_pChild; // eax
  long double result; // st7
  unsigned int m_Int64; // edx
  unsigned int m_Int64_high; // ecx

  m_pChild = this->m_pChild;
  for ( result = (double)this->m_PrevFrameTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
        m_pChild != nullptr;
        result = result - (double)__PAIR64__(m_Int64_high, m_Int64) * g_ClockSpeedMillisecondsMultiplier )
  {
    m_Int64 = m_pChild->m_PrevFrameTime.m_Int64;
    m_Int64_high = HIDWORD(m_pChild->m_PrevFrameTime.m_Int64);
    m_pChild = m_pChild->m_pSibling;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B2A0
// Name: public: int CVProfNode::GetPrevL2CacheMissLessChildren(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetPrevL2CacheMissLessChildren(CVProfNode *this)
{
  int result; // eax
  CVProfNode *i; // ecx

  result = this->m_iPrevL2CacheMiss;
  for ( i = this->m_pChild; i != nullptr; i = i->m_pSibling )
    result -= i->m_iPrevL2CacheMiss;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B2C0
// Name: public: int CVProfNode::GetL2CacheMisses(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetL2CacheMisses(CVProfNode *this)
{
  return this->m_L2Cache.m_iL2CacheMissCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000B2D0
// Name: public: bool CVProfile::IsEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVProfile::IsEnabled(CVProfile *this)
{
  return this->m_enabled != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B2E0
// Name: public: int CVProfile::GetDetailLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::GetDetailLevel(CVProfile *this)
{
  return this->m_ProfileDetailLevel;
}

//------------------------------------------------------------------------------
// Address: 0x1000B2F0
// Name: public: bool CVProfile::AtRoot(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVProfile::AtRoot(CVProfile *this)
{
  return this->m_fAtRoot;
}

//------------------------------------------------------------------------------
// Address: 0x1000B300
// Name: public: void CVProfile::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Start(CVProfile *this)
{
  if ( ++this->m_enabled == 1 )
    CVProfNode::EnterScope(this: &this->m_Root);
}

//------------------------------------------------------------------------------
// Address: 0x1000B320
// Name: public: void CVProfile::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Stop(CVProfile *this)
{
  if ( this->m_enabled-- == 1 )
    CVProfNode::ExitScope(this: &this->m_Root);
}

//------------------------------------------------------------------------------
// Address: 0x1000B340
// Name: public: void CVProfile::EnterScope(char const __near *,int,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::EnterScope(
        CVProfile *this,
        const char *pszName,
        int detailLevel,
        const char *pBudgetGroupName,
        bool bAssertAccounted,
        int budgetFlags)
{
  CVProfNode *m_pCurNode; // ecx

  if ( (this->m_enabled != 0 || !this->m_fAtRoot) && this->m_TargetThreadId == GetCurrentThreadId() )
  {
    m_pCurNode = this->m_pCurNode;
    if ( pszName != m_pCurNode->m_pszName )
      this->m_pCurNode = CVProfNode::GetSubNode(this: m_pCurNode, pszName, detailLevel, pBudgetGroupName, budgetFlags);
    this->m_pBudgetGroups[this->m_pCurNode->m_BudgetGroupID].m_BudgetFlags |= budgetFlags;
    CVProfNode::EnterScope(this: this->m_pCurNode);
    this->m_fAtRoot = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B3C0
// Name: public: void CVProfile::EnterScope(char const __near *,int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::EnterScope(
        CVProfile *this,
        const char *pszName,
        int detailLevel,
        const char *pBudgetGroupName,
        bool bAssertAccounted)
{
  CVProfile::EnterScope(this, pszName, detailLevel, pBudgetGroupName, bAssertAccounted, budgetFlags: 4);
}

//------------------------------------------------------------------------------
// Address: 0x1000B3E0
// Name: public: void CVProfile::ExitScope(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::ExitScope(CVProfile *this)
{
  if ( (!this->m_fAtRoot || this->m_enabled != 0) && this->m_TargetThreadId == GetCurrentThreadId() )
  {
    if ( CVProfNode::ExitScope(this: this->m_pCurNode) )
      this->m_pCurNode = this->m_pCurNode->m_pParent;
    this->m_fAtRoot = this->m_pCurNode == &this->m_Root;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B440
// Name: public: void CVProfile::Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Pause(CVProfile *this)
{
  bool v1; // zf

  v1 = !this->m_fAtRoot;
  this->m_pausedEnabledDepth = this->m_enabled;
  this->m_enabled = 0;
  if ( v1 )
    CVProfNode::Pause(this: &this->m_Root);
}

//------------------------------------------------------------------------------
// Address: 0x1000B470
// Name: public: void CVProfile::Resume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Resume(CVProfile *this)
{
  bool v1; // zf

  v1 = !this->m_fAtRoot;
  this->m_enabled = this->m_pausedEnabledDepth;
  if ( v1 )
    CVProfNode::Resume(this: &this->m_Root);
}

//------------------------------------------------------------------------------
// Address: 0x1000B4A0
// Name: public: void CVProfile::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Reset(CVProfile *this)
{
  CVProfNode::Reset(this: &this->m_Root);
  this->m_nFrames = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B4C0
// Name: public: void CVProfile::ResetPeaks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::ResetPeaks(CVProfile *this)
{
  CVProfNode::ResetPeak(this: &this->m_Root);
}

//------------------------------------------------------------------------------
// Address: 0x1000B4D0
// Name: public: void CVProfile::MarkFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::MarkFrame(CVProfile *this)
{
  CVProfNode *p_m_Root; // esi

  if ( this->m_enabled != 0 )
  {
    ++this->m_nFrames;
    p_m_Root = &this->m_Root;
    CVProfNode::ExitScope(this: &this->m_Root);
    CVProfNode::MarkFrame(this: p_m_Root);
    CVProfNode::EnterScope(this: p_m_Root);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B500
// Name: public: double CVProfile::GetTotalTimeSampled(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfile::GetTotalTimeSampled(CVProfile *this)
{
  return (double)this->m_Root.m_TotalTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1000B550
// Name: public: double CVProfile::GetPeakFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfile::GetPeakFrameTime(CVProfile *this)
{
  return (double)this->m_Root.m_PeakTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1000B5A0
// Name: public: double CVProfile::GetTimeLastFrame(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CVProfile::GetTimeLastFrame(CVProfile *this)
{
  return (double)this->m_Root.m_CurFrameTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1000B5F0
// Name: public: class CVProfNode __near * CVProfile::GetRoot(void)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfile::GetRoot(CVProfile *this)
{
  return &this->m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1000B600
// Name: public: char const __near * CVProfile::GetBudgetGroupName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVProfile::GetBudgetGroupName(CVProfile *this, int budgetGroupID)
{
  return this->m_pBudgetGroups[budgetGroupID].m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x1000B620
// Name: public: int CVProfile::GetBudgetGroupFlags(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::GetBudgetGroupFlags(CVProfile *this, int budgetGroupID)
{
  return this->m_pBudgetGroups[budgetGroupID].m_BudgetFlags;
}

//------------------------------------------------------------------------------
// Address: 0x1000B640
// Name: _InitPME
// Source: json
//------------------------------------------------------------------------------
void InitPME()
{
  PME *v0; // eax
  HANDLE CurrentProcess; // eax
  HANDLE CurrentThread; // eax

  v0 = PME::Instance();
  if ( v0 != nullptr )
  {
    if ( v0->vendor == INTEL && (*(_DWORD *)&v0->version & 0xF00) == 0xF00 )
    {
      CurrentProcess = GetCurrentProcess();
      SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x100u);
      CurrentThread = GetCurrentThread();
      SetThreadPriority(hThread: CurrentThread, nPriority: 2);
      DevMsg(level: 1, pMsgFormat: "PME Initialized.\n");
      g_VProfCurrentProfile.m_bPMEInit = true;
    }
  }
  else
  {
    DevMsg(level: 1, pMsgFormat: "PME Uninitialized.\n");
    g_VProfCurrentProfile.m_bPMEInit = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B6C0
// Name: _ShutdownPME
// Source: json
//------------------------------------------------------------------------------
PME *ShutdownPME()
{
  PME *result; // eax
  HANDLE CurrentProcess; // eax
  HANDLE CurrentThread; // eax

  result = PME::Instance();
  if ( result != nullptr )
  {
    CurrentProcess = GetCurrentProcess();
    SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x20u);
    CurrentThread = GetCurrentThread();
    result = (PME *)SetThreadPriority(hThread: CurrentThread, nPriority: 0);
  }
  g_VProfCurrentProfile.m_bPMEInit = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B6F0
// Name: public: CL2Cache::~CL2Cache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL2Cache::~CL2Cache(CL2Cache *this)
{
  if ( this->m_pL2CacheEvent != nullptr )
  {
    operator delete(p: this->m_pL2CacheEvent);
    this->m_pL2CacheEvent = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B710
// Name: public: void CL2Cache::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL2Cache::Start(CL2Cache *this)
{
  P4Event_BSQ_cache_reference *m_pL2CacheEvent; // eax
  P4Event_BSQ_cache_reference *v3; // eax
  int flat_high; // edx
  ESCR *p_escr; // ecx
  int m_eventMask; // eax
  int v7; // edx
  int v8; // eax
  P4Event_BSQ_cache_reference *v9; // ecx
  int v10; // edx
  P4Event_BSQ_cache_reference *v11; // eax
  PME *pme; // ecx
  P4Event_BSQ_cache_reference *v13; // ecx
  int v14; // edx
  P4Event_BSQ_cache_reference *v15; // eax
  PME *v16; // ecx
  unsigned int counterPort; // [esp-10h] [ebp-1Ch]
  unsigned int v18; // [esp-10h] [ebp-1Ch]
  unsigned __int64 i64_value; // [esp+4h] [ebp-8h] BYREF

  m_pL2CacheEvent = this->m_pL2CacheEvent;
  if ( m_pL2CacheEvent != nullptr )
  {
    *(_WORD *)&m_pL2CacheEvent->eventMask->__s0 |= 0x100u;
    v3 = this->m_pL2CacheEvent;
    flat_high = HIDWORD(v3->escr.flat);
    *(_DWORD *)&v3->escr.__s0 |= 4u;
    *(_DWORD *)&v3->escr.__s0 |= 8u;
    p_escr = &v3->escr;
    HIDWORD(i64_value) = v3;
    m_eventMask = v3->m_eventMask;
    HIDWORD(p_escr->flat) = flat_high;
    v7 = HIDWORD(p_escr->flat);
    *(_DWORD *)&p_escr->__s0 = *(_DWORD *)&p_escr->__s0 & 0xFE0001FF | (m_eventMask << 9);
    v8 = HIDWORD(i64_value);
    HIDWORD(p_escr->flat) = v7;
    PME::WriteMSR(this: *(PME **)(v8 + 12), dw_reg: *(_DWORD *)(v8 + 40), i64_value: (const unsigned __int64 *)p_escr);
    v9 = this->m_pL2CacheEvent;
    v10 = HIDWORD(v9->cccr.flat);
    *(_DWORD *)&v9->cccr.__s0 &= ~0x1000u;
    HIDWORD(v9->cccr.flat) = v10;
    PME::WriteMSR(this: v9->pme, dw_reg: v9->cccrPort, i64_value: (const unsigned __int64 *)&v9->cccr);
    v11 = this->m_pL2CacheEvent;
    pme = v11->pme;
    counterPort = v11->counterPort;
    i64_value = 0;
    PME::WriteMSR(this: pme, dw_reg: counterPort, &i64_value);
    v13 = this->m_pL2CacheEvent;
    v14 = HIDWORD(v13->cccr.flat);
    *(_DWORD *)&v13->cccr.__s0 |= 0x1000u;
    HIDWORD(v13->cccr.flat) = v14;
    PME::WriteMSR(this: v13->pme, dw_reg: v13->cccrPort, i64_value: (const unsigned __int64 *)&v13->cccr);
    v15 = this->m_pL2CacheEvent;
    v16 = v15->pme;
    v18 = v15->counterPort;
    i64_value = 0;
    PME::ReadMSR(this: v16, dw_reg: v18, pi64_value: (__int64 *)&i64_value);
    this->m_i64Start = i64_value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B810
// Name: public: void CL2Cache::End(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL2Cache::End(CL2Cache *this)
{
  P4Event_BSQ_cache_reference *m_pL2CacheEvent; // eax
  PME *pme; // ecx
  __int64 v4; // kr00_8
  bool v5; // cf
  int v6; // eax
  int v7; // edi
  P4Event_BSQ_cache_reference *v8; // ecx
  int flat_high; // edx
  unsigned int counterPort; // [esp-Ch] [ebp-18h]
  __int64 i64Delta; // [esp+4h] [ebp-8h] BYREF

  m_pL2CacheEvent = this->m_pL2CacheEvent;
  if ( m_pL2CacheEvent != nullptr )
  {
    pme = m_pL2CacheEvent->pme;
    counterPort = m_pL2CacheEvent->counterPort;
    i64Delta = 0;
    PME::ReadMSR(this: pme, dw_reg: counterPort, pi64_value: &i64Delta);
    v4 = i64Delta;
    LODWORD(this->m_i64End) = i64Delta;
    v5 = (unsigned int)v4 < LODWORD(this->m_i64Start);
    v6 = v4 - LODWORD(this->m_i64Start);
    HIDWORD(this->m_i64End) = HIDWORD(v4);
    v7 = v6;
    HIDWORD(i64Delta) = HIDWORD(v4) - (v5 + HIDWORD(this->m_i64Start));
    v8 = this->m_pL2CacheEvent;
    flat_high = HIDWORD(v8->cccr.flat);
    *(_DWORD *)&v8->cccr.__s0 &= ~0x1000u;
    HIDWORD(v8->cccr.flat) = flat_high;
    PME::WriteMSR(this: v8->pme, dw_reg: v8->cccrPort, i64_value: (const unsigned __int64 *)&v8->cccr);
    this->m_iL2CacheMissCount = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B880
// Name: public: class CVProfNode __near * CVProfNode::GetPrevSibling(void)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfNode::GetPrevSibling(CVProfNode *this)
{
  CVProfNode *result; // eax
  CVProfNode *m_pSibling; // edx

  result = this->m_pParent;
  if ( result != nullptr )
  {
    result = result->m_pChild;
    if ( result != nullptr )
    {
      do
      {
        m_pSibling = result->m_pSibling;
        if ( m_pSibling == this )
          break;
        result = result->m_pSibling;
      }
      while ( m_pSibling != nullptr );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B8B0
// Name: public: void CVProfNode::ClearPrevTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::ClearPrevTime(CVProfNode *this)
{
  this->m_PrevFrameTime.m_Int64 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B8C0
// Name: public: P4Event_BSQ_cache_reference::P4Event_BSQ_cache_reference(void)
// Source: json
//------------------------------------------------------------------------------
P4Event_BSQ_cache_reference *__thiscall P4Event_BSQ_cache_reference::P4Event_BSQ_cache_reference(
        P4Event_BSQ_cache_reference *this)
{
  this->pme = PME::Instance();
  this->escrPort = 0;
  this->eventMask = (EventMaskBSQ_cache_reference *)&this->m_eventMask;
  this->m_eventMask = 0;
  *(_DWORD *)&this->escr.__s0 = 402653184;
  HIDWORD(this->escr.flat) = 0;
  *(_DWORD *)&this->cccr.__s0 = 253952;
  HIDWORD(this->cccr.flat) = 0;
  this->description = "BSQ_cache_reference";
  this->m_counter = 0;
  this->cccrPort = 864;
  this->counterPort = 768;
  this->escrPort = cccr_escr_map[0][7];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000B920
// Name: public: CVProfNode::CVProfNode(char const __near *,int,class CVProfNode __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfNode::CVProfNode(
        CVProfNode *this,
        const char *pszName,
        int detailLevel,
        CVProfNode *pParent,
        const char *pBudgetGroupName,
        int budgetFlags)
{
  int v7; // eax
  P4Event_BSQ_cache_reference *v8; // eax
  P4Event_BSQ_cache_reference *v9; // eax
  CVProfNode *m_pParent; // eax

  this->m_pszName = pszName;
  v7 = s_nCreateCount;
  this->m_Timer.m_Duration.m_Int64 = 0;
  this->m_L2Cache.m_nID = v7;
  s_nCreateCount = v7 + 1;
  v8 = (P4Event_BSQ_cache_reference *)operator new(size: 0x30u);
  if ( v8 != nullptr )
    v9 = P4Event_BSQ_cache_reference::P4Event_BSQ_cache_reference(this: v8);
  else
    v9 = nullptr;
  this->m_L2Cache.m_pL2CacheEvent = v9;
  this->m_L2Cache.m_iL2CacheMissCount = 0;
  LODWORD(this->m_L2Cache.m_i64Start) = 0;
  HIDWORD(this->m_L2Cache.m_i64Start) = 0;
  LODWORD(this->m_L2Cache.m_i64End) = 0;
  HIDWORD(this->m_L2Cache.m_i64End) = 0;
  this->m_nRecursions = 0;
  this->m_nCurFrameCalls = 0;
  LODWORD(this->m_CurFrameTime.m_Int64) = 0;
  HIDWORD(this->m_CurFrameTime.m_Int64) = 0;
  this->m_nPrevFrameCalls = 0;
  LODWORD(this->m_PrevFrameTime.m_Int64) = 0;
  HIDWORD(this->m_PrevFrameTime.m_Int64) = 0;
  LODWORD(this->m_TotalTime.m_Int64) = 0;
  HIDWORD(this->m_TotalTime.m_Int64) = 0;
  LODWORD(this->m_PeakTime.m_Int64) = 0;
  HIDWORD(this->m_PeakTime.m_Int64) = 0;
  this->m_pParent = pParent;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_iClientData = -1;
  this->m_iUniqueNodeID = CVProfNode::s_iCurrentUniqueNodeID++;
  if ( this->m_iUniqueNodeID <= 0 )
    this->m_BudgetGroupID = 0;
  else
    this->m_BudgetGroupID = CVProfile::BudgetGroupNameToBudgetGroupID(
                              this: &g_VProfCurrentProfile,
                              pBudgetGroupName,
                              budgetFlagsToORIn: budgetFlags);
  CVProfNode::Reset(this);
  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr && this->m_BudgetGroupID == 0 )
    this->m_BudgetGroupID = m_pParent->m_BudgetGroupID;
  return this;
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F0056F0
// Name: public: void CVProfile::EnableVTuneGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfile::EnableVTuneGroup(CVProfile *this, const char *pGroupName, int a3, int a4, int a5)
{
  ((void (__thiscall *)(CVProfile *, _DWORD))loc_3F008340)(a1: this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F005750
// Name: public: void CVProfile::DisableVTuneGroup(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0057B0
// Name: public: void CVProfile::SetThreadSafe(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVProfile::SetThreadSafe(CVProfile *this@<ecx>, char a2@<of>, unsigned int a3@<esi>, bool bThreadSafe)
{
  if ( !a2 )
  {
    if ( HIWORD(a3) < 0x4000u )
      JUMPOUT(0x3F0057BD);
    JUMPOUT(0x3F0057CF);
  }
  JUMPOUT(0x3F0057D6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0057C0
// Name: public: bool CVProfile::RequiresThreadSafety(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::RequiresThreadSafety(CVProfile *this)
{
  JUMPOUT(0x3F0057C7);
}

//------------------------------------------------------------------------------
// Address: 0x3F0057D0
// Name: protected: bool CVProfile::VTuneGroupEnabled(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVProfile::VTuneGroupEnabled(CVProfile *this@<ecx>, char a2@<cf>, char a3@<bl>, int a4@<edi>)
{
  *(_BYTE *)(a4 + 94) += a3 + a2;
  JUMPOUT(0x3F0057D4);
}

//------------------------------------------------------------------------------
// Address: 0x3F0057E0
// Name: protected: int CVProfile::VTuneGroupID(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfile::VTuneGroupID(CVProfile *this)
{
  JUMPOUT(0x3F0057E4);
}

//------------------------------------------------------------------------------
// Address: 0x3F005810
// Name: public: void CVProfile::PushGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::PushGroup(CVProfile *this, int nGroupID, int nGroupIDa)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0058F0
// Name: public: void CVProfile::PopGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::PopGroup(CVProfile *this)
{
  (*(void (__thiscall **)(CVProfile *, _DWORD))(*(_DWORD *)&this->m_bVTuneGroupEnabled + 164))(a1: this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F005D60
// Name: public: int CVProfile::GetDetailLevel(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CVProfile::GetDetailLevel(CVProfile *this@<ecx>, _DWORD *a2@<ebx>)
{
  *a2 = __ROL4__(*a2, 51);
  JUMPOUT(0x3F005D69);
}

//------------------------------------------------------------------------------
// Address: 0x3F005F30
// Name: public: void CVProfile::EnterScope(char const __near *,int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVProfile::EnterScope(
        CVProfile *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        const char *pszName,
        int detailLevel,
        const char *pBudgetGroupName,
        bool bAssertAccounted)
{
  *(_DWORD *)(a2 - 4) = -1;
  `eh vector destructor iterator'(a1: (void *)(a3 + 1024), a2: 0x28u, a3: 38, a4: loc_3F0070D0);
  JUMPOUT(0x3F005F4F);
}

//------------------------------------------------------------------------------
// Address: 0x3F0060A0
// Name: public: void CVProfile::MarkFrame(void)
// Source: json
//------------------------------------------------------------------------------
long double __usercall CVProfile::MarkFrame@<st0>(
        CVProfile *this@<ecx>,
        unsigned int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        int a6,
        int a7,
        CVProfile *a8,
        int a9)
{
  int v9; // eax
  int v10; // esi
  long double result; // st7

  dword_3F0A1DE8 = (int)this;
  dword_3F0A1DF0 = (int)this;
  if ( (a2 & 7) != 0 || a2 < 8 )
    __debugbreak();
  *(_DWORD *)(a4 + 8) = a2;
  _InterlockedExchange((volatile __int32 *)a4, 0);
  v9 = *(_DWORD *)(a3 + 8);
  *(_DWORD *)(a4 + 12) = 0;
  *(_DWORD *)(v9 + 4 * a5) = a8;
  v10 = a5 + 1;
  if ( a9 + 1 < 65 )
  {
    CVProfile::Resume(this: a8);
  }
  else
  {
    if ( v10 >= 128 )
      JUMPOUT(0x3F00620B);
    return CVProfile::GetTotalTimeSampled(this: a8);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0061F0
// Name: public: void P4BaseEvent::StartCounter(void)
// Source: json
//------------------------------------------------------------------------------
long double __usercall P4BaseEvent::StartCounter@<st0>(P4BaseEvent *this@<ecx>, int a2@<edx>, int a3@<esi>)
{
  int v3; // esi
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v3 = a3 + 1;
  if ( a2 + 1 >= 129 )
  {
    if ( v3 < 192 )
    {
      if ( v3 + 1 < 257 )
      {
        if ( v3 + 1 < 0 )
          JUMPOUT(0x3F006244);
        if ( ((v3 + 1) & 0x8000000F) == 1 )
        {
          if ( (dword_3F0A3610 & 1) == 0 )
          {
            dword_3F0A3610 |= 1u;
            sub_3F007360(a1: &retaddr);
            atexit_0(a1: sub_3F02EEB0);
          }
          if ( dword_3F0A1DEC == 0 )
          {
            VirtualAlloc(lpAddress: nullptr, dwSize: 0x1000000u, flAllocationType: 0x2000u, flProtect: 1u);
            JUMPOUT(0x3F0062AF);
          }
          JUMPOUT(0x3F0062CF);
        }
        JUMPOUT(0x3F0062FE);
      }
      JUMPOUT(0x3F00642F);
    }
    JUMPOUT(0x3F00631B);
  }
  return CVProfile::GetPeakFrameTime((CVProfile *)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F0062B0
// Name: public: __int64 P4BaseEvent::ReadCounter(void)
// Source: json
//------------------------------------------------------------------------------
void __userpurge P4BaseEvent::ReadCounter(
        P4BaseEvent *this@<ecx>,
        char a2@<cf>,
        int a3@<eax>,
        unsigned __int16 a4@<dx>,
        unsigned int a5@<ebx>,
        int a6@<ebp>,
        int a7@<edi>,
        int a8@<esi>,
        int a9,
        int a10,
        int a11,
        int a12)
{
  int v12; // eax

  LOBYTE(a3) = __inbyte(a4);
  dword_3F0A1DE8 = a3 - (a2 + 225722122);
  dword_3F0A1DF0 = dword_3F0A1DE8 + 0x1000000;
  if ( (a5 & 7) != 0 || a5 < 8 )
    __debugbreak();
  *(_DWORD *)(a7 + 8) = a5;
  _InterlockedExchange((volatile __int32 *)a7, 0);
  v12 = *(_DWORD *)(a6 + 8);
  *(_DWORD *)(a7 + 12) = 0;
  *(_DWORD *)(v12 + 4 * a8) = a12;
  JUMPOUT(0x3F006301);
}

//------------------------------------------------------------------------------
// Address: 0x3F006300
// Name: public: void P4BaseEvent::SetCaptureMode(enum PrivilegeCapture)
// Source: json
//------------------------------------------------------------------------------
void __userpurge P4BaseEvent::SetCaptureMode(
        P4BaseEvent *this@<ecx>,
        int a2@<edx>,
        int a3@<esi>,
        PrivilegeCapture priv)
{
  int v4; // esi

  v4 = a3 + 1;
  if ( a2 + 1 >= 193 )
  {
    if ( v4 < 256 && v4 + 1 < 257 )
    {
      if ( (v4 + 1) % 32 == 1 )
      {
        if ( (dword_3F0A3610 & 1) == 0 )
        {
          dword_3F0A3610 |= 1u;
          JUMPOUT(0x3F00637D);
        }
        JUMPOUT(0x3F00639F);
      }
      JUMPOUT(0x3F006417);
    }
    JUMPOUT(0x3F00642F);
  }
  JUMPOUT(0x3F006230);
}

//------------------------------------------------------------------------------
// Address: 0x3F006380
// Name: _InitPME
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPME(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  JUMPOUT(0x3F006382);
}

//------------------------------------------------------------------------------
// Address: 0x3F0063F0
// Name: _ShutdownPME
// Source: json
//------------------------------------------------------------------------------
void __usercall ShutdownPME(int a1@<ebx>, _DWORD *a2@<edi>, int a3@<esi>, int a4, int a5, int a6, int a7, int a8)
{
  __debugbreak();
  *(_DWORD *)(a3 + 8) = a1;
  _InterlockedExchange((volatile __int32 *)a3, 0);
  *(_DWORD *)(a3 + 12) = 0;
  *a2 = a7;
  JUMPOUT(0x3F00641F);
}

//------------------------------------------------------------------------------
// Address: 0x3F006420
// Name: public: CL2Cache::CL2Cache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL2Cache::CL2Cache(CL2Cache *this@<ecx>, int a2@<eax>)
{
  _disable();
  this->m_nID += a2;
  JUMPOUT(0x3F006423);
}

//------------------------------------------------------------------------------
// Address: 0x3F0064F0
// Name: public: CL2Cache::~CL2Cache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL2Cache::~CL2Cache(CL2Cache *this@<ecx>, char a2@<zf>, int a3@<eax>, int a4@<edx>, int a5@<esi>)
{
  if ( a2 )
  {
    this = *(CL2Cache **)(a4 + 2544);
    a3 = a5;
  }
  if ( (unsigned int)(a3 - *((_DWORD *)this + 9)) >> 16 < 0x100 )
    JUMPOUT(0x3F00650A);
  JUMPOUT(0x3F006510);
}

//------------------------------------------------------------------------------
// Address: 0x3F006510
// Name: public: void CL2Cache::Start(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CL2Cache::Start(CL2Cache *this@<ecx>, int a2@<edx>, int a3@<ebp>, size_t a4@<edi>, int a5)
{
  int v5; // eax
  void *v6; // esi
  size_t v7; // eax

  if ( a4 > 0x400 )
    v5 = 0;
  else
    v5 = *(_DWORD *)(a2 + 4 * ((a4 - 1) >> 2));
  if ( v5 != 0 )
  {
    v6 = (void *)(*(int (__thiscall **)(int, size_t))(*(_DWORD *)g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: a4);
    if ( v6 != nullptr || (v6 = malloc_0(Size: a4)) != nullptr )
    {
      v7 = MEMORY[0x10];
      if ( a4 < MEMORY[0x10] )
        v7 = a4;
      memcpy_1(a1: v6, Src: *(const void **)(a3 + 8), Size: v7);
    }
    ThreadWaitForObjects();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F006590
// Name: public: void CL2Cache::End(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL2Cache::End(CL2Cache *this@<ecx>, int a2@<eax>, int a3@<ebp>, int a4@<edi>)
{
  int v4; // [esp+8h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h] BYREF

  *(int *)((char *)&dword_3F0A362C + (_DWORD)this) += (int)&retaddr;
  if ( ((int (__stdcall *)(int, int))loc_3F007B50)(
         a1: *(_DWORD *)(a3 + 8) + 40 * (((int)&dword_3F0A362C + a2 + a4) % 38) + 1024,
         a2: v4) == 0 )
    JUMPOUT(0x3F0065C5);
  JUMPOUT(0x3F0065CF);
}

//------------------------------------------------------------------------------
// Address: 0x3F0065D0
// Name: public: int CThreadLocal<int>::Get(void)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __userpurge CThreadLocal<int>::Get@<eax>(CThreadLocal<int> *this@<ecx>, int a2@<eax>, int a3, int a4)
{
  return (unsigned int)&dword_3F0A362C ^ a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A640
// Name: public: int CVProfNode::GetBudgetGroupID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetBudgetGroupID(CVProfNode *this)
{
  return this->m_iClientData;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A660
// Name: public: void CVProfNode::SetClientData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::SetClientData(CVProfNode *this, int a2)
{
  this->m_iUniqueNodeID = a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A670
// Name: public: int CVProfNode::GetClientData(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetClientData(CVProfNode *this)
{
  return this->m_iUniqueNodeID;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A690
// Name: private: int CVProfNode::GetUniqueNodeID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetUniqueNodeID(CVProfNode *this)
{
  return *((_DWORD *)this + 34);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A6A0
// Name: public: class CVProfNode __near & CVProfNode::operator=(class CVProfNode const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CVProfNode::operator=(void *this, const void *a2)
{
  qmemcpy(this, a2, 0x90u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A6C0
// Name: public: int CVProfile::NumFramesSampled(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::NumFramesSampled(CVProfile *this)
{
  return this->m_GroupIDStack[2];
}

//------------------------------------------------------------------------------
// Address: 0x3F00A710
// Name: public: void CVProfile::PMEInitialized(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::PMEInitialized(CVProfile *this, bool a2)
{
  LOBYTE(this->m_GroupIDStack[9]) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A720
// Name: public: void CVProfile::PMEEnable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::PMEEnable(CVProfile *this, bool a2)
{
  BYTE1(this->m_GroupIDStack[9]) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A730
// Name: public: bool CVProfile::UsePME(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVProfile::UsePME(CVProfile *this)
{
  return LOBYTE(this->m_GroupIDStack[9]) != 0 && BYTE1(this->m_GroupIDStack[9]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A8D0
// Name: public: class CVProfile __near & CVProfile::operator=(class CVProfile const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::operator=(CValidator *this, int a2)
{
  CValidator::UnlockValidationLocks(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F00B4A0
// Name: public: CVProfNode::CVProfNode(class CVProfile __near *,char const __near *,int,class CVProfNode __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::CVProfNode(
        CVProfNode *this,
        struct CVProfile *a2,
        const char *a3,
        int a4,
        struct CVProfNode *a5,
        const char *a6,
        int a7)
{
  this->m_pszName = nullptr;
  this->m_pvOrigNameAddress = a3;
  this->m_Timer.m_Duration.m_Int64 = 0;
  sub_3F00BEF0();
  this->m_nRecursions = 0;
  this->m_nCurFrameCalls = 0;
  this->m_CurFrameTime.m_Int64 = 0;
  this->m_nPrevFrameCalls = 0;
  this->m_PrevFrameTime.m_Int64 = 0;
  this->m_TotalTime.m_Int64 = 0;
  this->m_PeakTime.m_Int64 = 0;
  this->m_pParent = a5;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_BudgetGroupID = 0;
  this->m_iUniqueNodeID = -1;
  *((_DWORD *)this + 35) = a2;
  strlen(a3);
  VCR_Hook_RecordGameMsg(uMsg: (unsigned int)a2, wParam: (unsigned int)a3, lParam: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F00B600
// Name: public: CVProfNode::~CVProfNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::~CVProfNode(CVProfNode *this)
{
  j_j__free(Block: (void *)this->m_pszName);
  if ( this->m_L2Cache.m_pL2CacheEvent != nullptr )
  {
    j__free(Block: this->m_L2Cache.m_pL2CacheEvent);
    this->m_L2Cache.m_pL2CacheEvent = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00B660
// Name: public: class CVProfNode __near * CVProfNode::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
struct CVProfNode *__thiscall CVProfNode::GetParent(CVProfNode *this)
{
  if ( this->m_pParent == nullptr )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: m_pParent",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
      a4: 983,
      a5: &`CVProfNode::GetParent'::`7'::fDumped,
      a6: 0);
  return this->m_pParent;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B690
// Name: public: class CVProfNode __near * CVProfNode::GetSibling(void)
// Source: json
//------------------------------------------------------------------------------
struct CVProfNode *__thiscall CVProfNode::GetSibling(CVProfNode *this)
{
  return this->m_pSibling;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B6A0
// Name: public: class CVProfNode __near * CVProfNode::GetPrevSibling(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::GetPrevSibling(CVProfNode *this)
{
  CVProfNode *m_pParent; // eax
  CVProfNode *m_pChild; // eax
  CVProfNode *m_pSibling; // ecx

  if ( this->m_pParent == nullptr )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: m_pParent",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
      a4: 983,
      a5: &`CVProfNode::GetParent'::`7'::fDumped,
      a6: 0);
  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr )
  {
    m_pChild = m_pParent->m_pChild;
    if ( m_pChild != nullptr )
    {
      do
      {
        m_pSibling = m_pChild->m_pSibling;
        if ( m_pSibling == this )
          break;
        m_pChild = m_pChild->m_pSibling;
      }
      while ( m_pSibling != nullptr );
    }
  }
  else
  {
    VCR_Hook_RecordEndGameMsg();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00B6F0
// Name: public: class CVProfNode __near * CVProfNode::GetChild(void)
// Source: json
//------------------------------------------------------------------------------
struct CVProfNode *__thiscall CVProfNode::GetChild(CVProfNode *this)
{
  return this->m_pChild;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B700
// Name: public: char const __near * CVProfNode::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVProfNode::GetName(CVProfNode *this)
{
  if ( this->m_pszName == nullptr )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: m_pszName",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
      a4: 1026,
      a5: &`CVProfNode::GetName'::`7'::fDumped,
      a6: 0);
  return this->m_pszName;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B730
// Name: public: void const __near * CVProfNode::GetOrigNameAddress(void)
// Source: json
//------------------------------------------------------------------------------
const void *__thiscall CVProfNode::GetOrigNameAddress(CVProfNode *this)
{
  if ( this->m_pvOrigNameAddress == nullptr )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: m_pvOrigNameAddress",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
      a4: 1034,
      a5: &`CVProfNode::GetOrigNameAddress'::`7'::fDumped,
      a6: 0);
  return this->m_pvOrigNameAddress;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B760
// Name: public: double CVProfNode::GetTotalTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfNode::GetTotalTime(CVProfNode *this)
{
  return (double)this->m_TotalTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B770
// Name: public: int CVProfNode::GetCurCalls(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVProfNode::GetCurCalls(CVProfNode *this)
{
  return this->m_nCurFrameCalls;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B780
// Name: public: double CVProfNode::GetCurTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfNode::GetCurTime(CVProfNode *this)
{
  return (double)this->m_CurFrameTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B790
// Name: public: int CVProfNode::GetPrevCalls(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVProfNode::GetPrevCalls(CVProfNode *this)
{
  return this->m_nPrevFrameCalls;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B7A0
// Name: public: double CVProfNode::GetPrevTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfNode::GetPrevTime(CVProfNode *this)
{
  return (double)this->m_PrevFrameTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B7B0
// Name: public: double CVProfNode::GetPeakTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfNode::GetPeakTime(CVProfNode *this)
{
  return (double)this->m_PeakTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B7C0
// Name: public: double CVProfNode::GetTotalTimeLessChildren(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfNode::GetTotalTimeLessChildren(CVProfNode *this)
{
  CVProfNode *m_pChild; // eax
  double result; // st7
  double m_Int64; // st5

  m_pChild = this->m_pChild;
  for ( result = (double)this->m_TotalTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
        m_pChild != nullptr;
        result = result - m_Int64 * g_ClockSpeedMillisecondsMultiplier )
  {
    m_Int64 = (double)m_pChild->m_TotalTime.m_Int64;
    m_pChild = m_pChild->m_pSibling;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B820
// Name: public: double CVProfNode::GetPrevTimeLessChildren(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfNode::GetPrevTimeLessChildren(CVProfNode *this)
{
  CVProfNode *m_pChild; // eax
  double result; // st7
  double m_Int64; // st5

  m_pChild = this->m_pChild;
  for ( result = (double)this->m_PrevFrameTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier;
        m_pChild != nullptr;
        result = result - m_Int64 * g_ClockSpeedMillisecondsMultiplier )
  {
    m_Int64 = (double)m_pChild->m_PrevFrameTime.m_Int64;
    m_pChild = m_pChild->m_pSibling;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B850
// Name: public: void CVProfNode::ClearPrevTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::ClearPrevTime(CVProfNode *this)
{
  this->m_PrevFrameTime.m_Int64 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B860
// Name: public: bool CVProfile::IsEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVProfile::IsEnabled(CVProfile *this)
{
  return *(_DWORD *)&this->m_bVTuneGroupEnabled != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B870
// Name: public: bool CVProfile::AtRoot(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVProfile::AtRoot(CVProfile *this)
{
  return this->m_nVTuneGroupID;
}

//------------------------------------------------------------------------------
// Address: 0x3F00B880
// Name: public: void CVProfile::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Start(CVProfile *this)
{
  int *v1; // edi
  int v2; // eax
  int v3; // eax

  if ( ++*(_DWORD *)&this->m_bVTuneGroupEnabled == 1 )
  {
    v1 = (int *)this->m_GroupIDStack[1];
    v2 = v1[14];
    ++v1[15];
    v1[14] = v2 + 1;
    if ( v2 == 0 )
    {
      cpuid(a1: v1 + 2);
      v3 = v1[35];
      if ( *(_BYTE *)(v3 + 44) != 0 && *(_BYTE *)(v3 + 45) != 0 )
        sub_3F00BFD0();
      v1[31] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00B8D0
// Name: public: void CVProfile::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Stop(CVProfile *this)
{
  if ( (*(_DWORD *)&this->m_bVTuneGroupEnabled)-- == 1 )
    CVProfNode::ExitScope(this: (CVProfNode *)this->m_GroupIDStack[1]);
}

//------------------------------------------------------------------------------
// Address: 0x3F00B8E0
// Name: public: void CVProfile::EnterScope(char const __near *,int,char const __near *,bool,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::EnterScope(
        CVProfile *this,
        const char *a2,
        int a3,
        const char *a4,
        bool a5,
        int a6,
        void *a7)
{
  int v8; // esi
  int *v9; // edi
  int v10; // eax
  int v11; // eax

  if ( *(_DWORD *)&this->m_bVTuneGroupEnabled != 0 || LOBYTE(this->m_nVTuneGroupID) == 0 )
  {
    v8 = this->m_GroupIDStack[0];
    if ( *(_DWORD *)(v8 + 4) == 0 )
      ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: "Assertion Failed: m_pvOrigNameAddress",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
        a4: 1034,
        a5: &`CVProfNode::GetOrigNameAddress'::`7'::fDumped,
        a6: 0);
    if ( a2 != *(const char **)(v8 + 4) )
      this->m_GroupIDStack[0] = (int)CVProfNode::GetSubNode(
                                       this: (CVProfNode *)this->m_GroupIDStack[0],
                                       a2,
                                       a3,
                                       a4,
                                       a5: a6);
    *(_DWORD *)(this->m_GroupIDStack[5] + 8 * *(_DWORD *)(this->m_GroupIDStack[0] + 128) + 4) |= a6;
    v9 = (int *)this->m_GroupIDStack[0];
    ++v9[15];
    v10 = v9[14];
    v9[14] = v10 + 1;
    if ( v10 == 0 )
    {
      cpuid(a1: v9 + 2);
      v11 = v9[35];
      if ( *(_BYTE *)(v11 + 44) != 0 && *(_BYTE *)(v11 + 45) != 0 )
        sub_3F00BFD0();
      v9[31] = (int)a7;
    }
    LOBYTE(this->m_nVTuneGroupID) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00B9D0
// Name: public: void CVProfile::ExitScope(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::ExitScope(CVProfile *this)
{
  int v2; // edi

  if ( LOBYTE(this->m_nVTuneGroupID) == 0 || *(_DWORD *)&this->m_bVTuneGroupEnabled != 0 )
  {
    if ( CVProfNode::ExitScope(this: (CVProfNode *)this->m_GroupIDStack[0]) )
    {
      v2 = this->m_GroupIDStack[0];
      if ( *(_DWORD *)(v2 + 112) == 0 )
        ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
          a1: "Assertion Failed: m_pParent",
          a2: 0,
          a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
          a4: 983,
          a5: &`CVProfNode::GetParent'::`7'::fDumped,
          a6: 0);
      this->m_GroupIDStack[0] = *(_DWORD *)(v2 + 112);
    }
    LOBYTE(this->m_nVTuneGroupID) = this->m_GroupIDStack[0] == this->m_GroupIDStack[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00BA30
// Name: public: void CVProfile::Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Pause(CVProfile *this)
{
  bool v1; // zf

  v1 = LOBYTE(this->m_nVTuneGroupID) == 0;
  this->m_GroupIDStack[4] = *(_DWORD *)&this->m_bVTuneGroupEnabled;
  *(_DWORD *)&this->m_bVTuneGroupEnabled = 0;
  if ( v1 )
    CVProfNode::Pause(this: (CVProfNode *)this->m_GroupIDStack[1]);
}

//------------------------------------------------------------------------------
// Address: 0x3F00BA50
// Name: public: void CVProfile::Resume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Resume(CVProfile *this)
{
  bool v1; // zf

  v1 = LOBYTE(this->m_nVTuneGroupID) == 0;
  *(_DWORD *)&this->m_bVTuneGroupEnabled = this->m_GroupIDStack[4];
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)this->m_GroupIDStack[1]);
}

//------------------------------------------------------------------------------
// Address: 0x3F00BA70
// Name: public: void CVProfile::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Reset(CVProfile *this)
{
  int v1; // eax

  CVProfNode::Reset(this: (CVProfNode *)this->m_GroupIDStack[1]);
  *(_DWORD *)(v1 + 16) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00BA90
// Name: public: void CVProfile::ResetPeaks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::ResetPeaks(CVProfile *this)
{
  _DWORD *v1; // eax
  int v2; // ecx
  int v3; // eax

  v1 = (_DWORD *)this->m_GroupIDStack[1];
  v2 = v1[29];
  v1[26] = 0;
  v1[27] = 0;
  if ( v2 != 0 )
  {
?ResetPeak@CVProfNode@@QAEXXZ:
    *(_DWORD *)(v2 + 104) = 0;
    *(_DWORD *)(v2 + 108) = 0;
    JUMPOUT(0x3F0169C1);
  }
  v3 = v1[30];
  if ( v3 != 0 )
  {
    v2 = v3;
    goto ?ResetPeak@CVProfNode@@QAEXXZ;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00BC50
// Name: public: double CVProfile::GetTotalTimeSampled(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfile::GetTotalTimeSampled(CVProfile *this)
{
  return (double)*(__int64 *)(this->m_GroupIDStack[1] + 96) * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x3F00BC60
// Name: public: double CVProfile::GetPeakFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfile::GetPeakFrameTime(CVProfile *this)
{
  return (double)*(__int64 *)(this->m_GroupIDStack[1] + 104) * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x3F00BC70
// Name: public: double CVProfile::GetTimeLastFrame(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfile::GetTimeLastFrame(CVProfile *this)
{
  return (double)*(__int64 *)(this->m_GroupIDStack[1] + 64) * g_ClockSpeedMillisecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x3F00BC80
// Name: public: class CVProfNode __near * CVProfile::GetRoot(void)
// Source: json
//------------------------------------------------------------------------------
struct CVProfNode *__thiscall CVProfile::GetRoot(CVProfile *this)
{
  return (struct CVProfNode *)this->m_GroupIDStack[1];
}

//------------------------------------------------------------------------------
// Address: 0x3F00BC90
// Name: public: char const __near * CVProfile::GetBudgetGroupName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__userpurge CVProfile::GetBudgetGroupName@<eax>(
        CVProfile *this@<ecx>,
        int a2,
        char *a3,
        int a4,
        int a5,
        sockaddr *a6,
        int *a7)
{
  if ( a2 >= 0 && a2 < this->m_GroupIDStack[7] )
    return *(const char **)(this->m_GroupIDStack[5] + 8 * a2);
  ((void (__cdecl *)(void *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: &unk_3F031FF0,
    a2: 0,
    a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
    a4: 1341,
    a5: &`CVProfile::GetBudgetGroupName'::`7'::fDumped,
    a6: 0);
  return (const char *)VCR_Hook_recvfrom(s: a2, buf: a3, len: a4, flags: a5, from: a6, fromlen: a7);
}

//------------------------------------------------------------------------------
// Address: 0x3F00BCE0
// Name: public: int CVProfile::GetBudgetGroupFlags(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::GetBudgetGroupFlags(CVProfile *this, int a2)
{
  if ( a2 >= 0 && a2 < this->m_GroupIDStack[7] )
    return *(_DWORD *)(this->m_GroupIDStack[5] + 8 * a2 + 4);
  ((void (__cdecl *)(void *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: &unk_3F031FF0,
    a2: 0,
    a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
    a4: 1347,
    a5: &`CVProfile::GetBudgetGroupFlags'::`7'::fDumped,
    a6: 0);
  return *(_DWORD *)(this->m_GroupIDStack[5] + 8 * a2 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F00BE40
// Name: InitPME
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int InitPME()
{
  char v0; // bl
  int result; // eax
  HANDLE CurrentProcess; // eax
  HANDLE CurrentThread; // eax
  int v4; // [esp-4h] [ebp-8h]

  v0 = 0;
  result = ((int (__stdcall *)(int))loc_3F00EA90)(a1: v4);
  if ( result == 0 )
    goto LABEL_5;
  if ( *(_DWORD *)(result + 28) == 0 )
  {
    result = *(_DWORD *)(result + 60) & 0xF00;
    if ( result == 3840 )
    {
      CurrentProcess = GetCurrentProcess();
      SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x100u);
      CurrentThread = GetCurrentThread();
      SetThreadPriority(hThread: CurrentThread, nPriority: 2);
      v0 = 1;
LABEL_5:
      SetAssertDumpStack(bAssertDumpStack: (bool)"console");
      result = sub_3F00B440();
      *(_BYTE *)(result + 44) = v0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00BEB0
// Name: ShutdownPME
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int ShutdownPME()
{
  HANDLE CurrentProcess; // eax
  HANDLE CurrentThread; // eax
  int result; // eax
  int v3; // [esp-4h] [ebp-4h]

  if ( ((int (__stdcall *)(int))loc_3F00EA90)(a1: v3) != 0 )
  {
    CurrentProcess = GetCurrentProcess();
    SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x20u);
    CurrentThread = GetCurrentThread();
    SetThreadPriority(hThread: CurrentThread, nPriority: 0);
  }
  result = sub_3F00B440();
  *(_BYTE *)(result + 44) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F011390
// Name: public: int CVProfNode::GetTotalCalls(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?GetCallHandle@CWorkerThread@@QAEPAXXZ'
unsigned int __thiscall CVProfNode::GetTotalCalls(CVProfNode *this)
{
  return this->m_nTotalCalls;
}

//------------------------------------------------------------------------------
// Address: 0x3F005770
// Name: ?PMEInitialized@CVProfile@@QAEX_N@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfile::PMEInitialized(
        CVProfile *this@<ecx>,
        char a2@<al>,
        unsigned __int16 a3@<dx>,
        int a4@<ebx>,
        bool bInit)
{
  unsigned __int8 v5; // al

  v5 = a2 & 0xC1;
  __outbyte(a3, v5);
  *((_BYTE *)this + 65790) += v5;
  *(_BYTE *)(a4 + 15) += HIBYTE(a3);
  JUMPOUT(0x3F00577F);
}

//------------------------------------------------------------------------------
// Address: 0x3F005780
// Name: ?PMEEnable@CVProfile@@QAEX_N@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfile::PMEEnable(CVProfile *this@<ecx>, int a2@<ebx>, int a3@<esi>, bool bEnable, int a5)
{
  bool v5; // cf

  v5 = __CFSHL__(*(_DWORD *)(a2 + 4 * (_DWORD)this), 1);
  *(_DWORD *)(a2 + 4 * (_DWORD)this) *= 2;
  *(_BYTE *)(a3 + 93) += a2 + v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F005790
// Name: ?UsePME@CVProfile@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfile::UsePME(CVProfile *this, int a2, int a3)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0057F0
// Name: ??4CVProfile@@QAEAAV0@ABV0@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfile::operator=(int a1, int a2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F005800
// Name: sub_3F005800
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_3F005800(int a1)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F005A30
// Name: sub_3F005A30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __thiscall sub_3F005A30(int this)
{
  DWORD result; // eax
  volatile __int32 *v3; // esi
  bool v4; // zf

  result = GetCurrentThreadId();
  v3 = (volatile __int32 *)(this + 7688);
  if ( result == *(_DWORD *)(this + 7688) || (result = _InterlockedCompareExchange(v3, result, 0)) == 0 )
  {
    ++*(_DWORD *)(this + 7692);
    if ( *(_BYTE *)(this + 7696) != 0 )
    {
      v4 = (*(_DWORD *)(this + 7692))-- == 1;
      if ( v4 )
        return _InterlockedExchange(v3, 0);
    }
    else
    {
      v4 = *(_DWORD *)(this + 7672) == 0;
      *(_BYTE *)(this + 7696) = 1;
      if ( !v4 )
        ((void (__stdcall *)(int))loc_3F006580)(a1: this + 8);
      if ( *(_DWORD *)(this + 7676) != 0 )
        ((void (__cdecl *)(int, int))loc_3F006EC0)(a1: this + 2560, a2: 1);
      *(_BYTE *)(this + 7696) = 0;
      v4 = (*(_DWORD *)(this + 7692))-- == 1;
      result = *(_DWORD *)(this + 7692);
      if ( v4 )
        _InterlockedExchange(v3, 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F005AC0
// Name: sub_3F005AC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F005AC0(_DWORD *this, int a2)
{
  int result; // eax

  result = *(this + 1920);
  *(this + 1920) = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F005AE0
// Name: ??1CVProfNode@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F005B50
// Name: ?GetParent@CVProfNode@@QAEPAV1@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CVProfNode *__usercall CVProfNode::GetParent@<eax>(
        CVProfNode *this@<ecx>,
        char a2@<cf>,
        int _EAX@<eax>,
        _BYTE *a4@<ebx>)
{
  HANDLE CurrentProcess; // eax

  *a4 -= a2 + _EAX;
  __asm { aas }
  ((void (__cdecl *)(int, int))AssertMsgImplementation)(a1: _EAX, a2: 1);
  CurrentProcess = GetCurrentProcess();
  return (CVProfNode *)TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x3F005B80
// Name: ?GetSibling@CVProfNode@@QAEPAV1@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfNode::GetSibling(CVProfNode *this)
{
  JUMPOUT(0x3F005B86);
}

//------------------------------------------------------------------------------
// Address: 0x3F005B90
// Name: ?GetPrevSibling@CVProfNode@@QAEPAV1@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfNode::GetPrevSibling(CVProfNode *this, int a2)
{
  return (*((CVProfNode *(__thiscall **)(CVProfNode *, int, int))this->m_pszName + 36))(a1: this, a2, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F005BE0
// Name: ?GetChild@CVProfNode@@QAEPAV1@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F005BF0
// Name: ?GetName@CVProfNode@@QAEPBDXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__usercall CVProfNode::GetName@<eax>(
        CVProfNode *this@<ecx>,
        char a2@<cf>,
        int a3@<eax>,
        int a4@<ebp>,
        int a5@<esi>)
{
  if ( (*(int (__cdecl **)(char *))(a5 + 7668))(a1: (char *)&GetCurrentProcess + a2 + a3) != 0 )
    return *(const char **)(a4 - 8);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F005C20
// Name: ?GetOrigNameAddress@CVProfNode@@QAEPBXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const void *__thiscall CVProfNode::GetOrigNameAddress(CVProfNode *this, int a2, unsigned int a3)
{
  if ( a3 >= *(_DWORD *)(a2 + 7704) && a3 <= *(_DWORD *)(a2 + 7708) )
    JUMPOUT(0x3F005C4D);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F005C50
// Name: ?GetTotalTime@CVProfNode@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfNode::GetTotalTime(CVProfNode *this@<ecx>, __int32 a2@<eax>)
{
  if ( _InterlockedExchange((volatile __int32 *)this, a2) == 0 )
    JUMPOUT(0x3F005C5C);
}

//------------------------------------------------------------------------------
// Address: 0x3F005C70
// Name: ?GetCurTime@CVProfNode@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfNode::GetCurTime(CVProfNode *this@<ecx>, _BYTE *a2@<eax>, char a3@<dl>, _BYTE *a4@<edi>)
{
  *a2 += a3;
  LOBYTE(a2) = BYTE1(this) + (_BYTE)a2;
  *a4 = (_BYTE)a2;
  *(_DWORD *)a2 += a2;
  JUMPOUT(0x3F005C7B);
}

//------------------------------------------------------------------------------
// Address: 0x3F005C80
// Name: ?GetPrevCalls@CVProfNode@@QAEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F005C90
// Name: ?GetPrevTime@CVProfNode@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfNode::GetPrevTime(CVProfNode *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  if ( *(_DWORD *)(a2 + 7728) == a3 )
    JUMPOUT(0x3F005C9E);
  JUMPOUT(0x3F005CA4);
}

//------------------------------------------------------------------------------
// Address: 0x3F005CA0
// Name: ?GetPeakTime@CVProfNode@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfNode::GetPeakTime(CVProfNode *this@<ecx>, char a2@<bl>, _BYTE *a3@<esi>)
{
  *a3 ^= a2;
  JUMPOUT(0x3F005CA2);
}

//------------------------------------------------------------------------------
// Address: 0x3F005CB0
// Name: ?GetTotalTimeLessChildren@CVProfNode@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfNode::GetTotalTimeLessChildren(CVProfNode *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  *(_DWORD *)(a3 + a2) = 0;
  *(_BYTE *)(a2 + 51130452) += (_BYTE)this;
  JUMPOUT(0x3F005CBA);
}

//------------------------------------------------------------------------------
// Address: 0x3F005D10
// Name: ?GetPrevTimeLessChildren@CVProfNode@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfNode::GetPrevTimeLessChildren(
        CVProfNode *this@<ecx>,
        int a2@<ebx>,
        int _EBP@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  __asm { lock lea this, [ebp-0A4h] }
  *(_DWORD *)(_EBP - 4) = a4;
  ((void (__cdecl *)(int, int))loc_3F003900)(a1: _ECX, a2: 16);
  *(_DWORD *)(a5 + *(_DWORD *)(a2 + 7716) + 12) = a4;
  JUMPOUT(0x3F005D3E);
}

//------------------------------------------------------------------------------
// Address: 0x3F005D40
// Name: ?ClearPrevTime@CVProfNode@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfNode::ClearPrevTime(CVProfNode *this@<ecx>, char a2@<al>, _BYTE *a3@<edi>, const void *a4@<esi>)
{
  BYTE1(this) *= 2;
  *a3 = (a2 - 57) | 0x11;
  qmemcpy(a3 + 1, a4, 4 * (_DWORD)this);
  JUMPOUT(0x3F005D49);
}

//------------------------------------------------------------------------------
// Address: 0x3F005D50
// Name: ?IsEnabled@CVProfile@@QBE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfile::IsEnabled(CVProfile *this)
{
  JUMPOUT(0x3F005D5E);
}

//------------------------------------------------------------------------------
// Address: 0x3F005D70
// Name: ?AtRoot@CVProfile@@QBE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfile::AtRoot(CVProfile *this, int a2, int a3)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F005D80
// Name: ?Start@CVProfile@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfile::Start(CVProfile *this@<ecx>, _DWORD *a2@<eax>, unsigned int a3)
{
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // esi

  if ( a3 != 0 )
  {
    v4 = a2[1928];
    if ( v4 + a3 < a2[1931] )
    {
      v5 = a2[1930];
      if ( a3 >= v5 )
      {
        v6 = a3 - v5;
        if ( ((v4 - 1) & (a3 - v5)) != 0 )
          ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
            a1: "Assertion Failed: (iub & (m_nSizeWithStack-1)) == 0",
            a2: 0,
            a3: ".\\memstd.cpp",
            a4: 2240,
            a5: &unk_3F041A45,
            a6: 0);
        if ( ((a2[1928] - 1) & v6) == 0 )
        {
          if ( *(_DWORD *)(a3 + a2[1929]) != -1441723155 )
            JUMPOUT(0x3F005E09);
          JUMPOUT(0x3F005E22);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F005E10
// Name: ?Stop@CVProfile@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CVProfile::Stop(CVProfile *this@<ecx>, char a2@<cf>, int _EAX@<eax>, _BYTE *a4@<ebx>, _DWORD *a5@<esi>)
{
  *a4 -= a2 + _EAX;
  __asm { aas }
  ((void (__cdecl *)(const char *, _DWORD))AssertMsgImplementation)(
    a1: "Assertion Failed: pAllocTracker->m_uSentinel == 0xaa110ced",
    a2: 0);
  *a5 = 0;
  JUMPOUT(0x3F005E26);
}

//------------------------------------------------------------------------------
// Address: 0x3F005E60
// Name: sub_3F005E60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_3F005E60(int a1)
{
  `eh vector constructor iterator'(a1: (void *)(a1 + 1024), a2: 0x28u, a3: 38, a4: loc_3F0071C0, a5: loc_3F0070D0);
  *(_DWORD *)(a1 + 2544) = sub_3F007150();
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F005ED0
// Name: sub_3F005ED0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F005ED0(CVProfile *this, int a2, int a3, const char *a4, bool a5)
{
  int v5; // eax
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  v5 = *(_DWORD *)(a2 + 2544);
  if ( v5 != 0 && *(_DWORD *)(v5 + 36) != 0 )
  {
    VirtualFree(lpAddress: *(LPVOID *)(v5 + 36), dwSize: 0x1000000u, dwFreeType: 0x10000u);
    this = *(CVProfile **)(a2 + 2544);
    this->m_GroupIDStack[7] = 0;
    *(_DWORD *)(*(_DWORD *)(a2 + 2544) + 40) = 0;
    *(_DWORD *)(*(_DWORD *)(a2 + 2544) + 32) = 0;
  }
  CVProfile::EnterScope(
    this,
    a2: (int)&savedregs,
    a3: a2,
    pszName: (const char *)a2,
    detailLevel: a3,
    pBudgetGroupName: a4,
    bAssertAccounted: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F005F50
// Name: ?ExitScope@CVProfile@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfile::ExitScope(CVProfile *this, int a2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F005FE0
// Name: ?Pause@CVProfile@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfile::Pause(CVProfile *this@<ecx>, int a2@<esi>)
{
  *((_BYTE *)this - 259280372) |= (unsigned __int8)this;
  if ( a2 >= 32 )
  {
    if ( a2 < 64 )
      JUMPOUT(0x3F00600C);
    JUMPOUT(0x3F0060F6);
  }
  JUMPOUT(0x3F005F94);
}

//------------------------------------------------------------------------------
// Address: 0x3F006010
// Name: ?Resume@CVProfile@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall CVProfile::Resume(CVProfile *this, int a2)
{
  if ( a2 < 257 )
  {
    if ( a2 % 4 == 1 )
      JUMPOUT(0x3F006032);
    JUMPOUT(0x3F0060DC);
  }
  JUMPOUT(0x3F0060F6);
}

//------------------------------------------------------------------------------
// Address: 0x3F006040
// Name: ?Reset@CVProfile@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F006060
// Name: ?ResetPeaks@CVProfile@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfile::ResetPeaks(CVProfile *this@<ecx>, char a2@<al>, int a3@<ebx>)
{
  *(_BYTE *)(a3 + 1153893572) += a2;
  JUMPOUT(0x3F006068);
}

//------------------------------------------------------------------------------
// Address: 0x3F006110
// Name: ?GetTotalTimeSampled@CVProfile@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __thiscall CVProfile::GetTotalTimeSampled(CVProfile *this)
{
  return CVProfile::GetPeakFrameTime(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F006120
// Name: ?GetPeakFrameTime@CVProfile@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall CVProfile::GetPeakFrameTime(CVProfile *this, int a2)
{
  if ( a2 < 257 )
    JUMPOUT(0x3F00612C);
  JUMPOUT(0x3F00620B);
}

//------------------------------------------------------------------------------
// Address: 0x3F006130
// Name: ?GetTimeLastFrame@CVProfile@@QAENXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
long double __userpurge CVProfile::GetTimeLastFrame@<st0>(
        CVProfile *this@<ecx>,
        int a2@<eax>,
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
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  *(_BYTE *)(a2 - 2092300935) += a2;
  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F006150
// Name: ?GetBudgetGroupName@CVProfile@@QAEPBDH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfile::GetBudgetGroupName(CVProfile *this@<ecx>, char a2@<al>, int budgetGroupID)
{
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  if ( (a2 & 0x10) == 0 )
  {
    dword_3F0A3610 |= 1u;
    sub_3F007360(a1: &retaddr);
    atexit_0(a1: sub_3F02EEB0);
  }
  if ( dword_3F0A1DEC == 0 )
  {
    VirtualAlloc(lpAddress: nullptr, dwSize: 0x1000000u, flAllocationType: 0x2000u, flProtect: 1u);
    JUMPOUT(0x3F00619F);
  }
  JUMPOUT(0x3F0061BF);
}

//------------------------------------------------------------------------------
// Address: 0x3F0061A0
// Name: ?GetBudgetGroupFlags@CVProfile@@QBEHH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfile::GetBudgetGroupFlags(
        CVProfile *this@<ecx>,
        char a2@<cf>,
        int a3@<eax>,
        unsigned __int16 a4@<dx>,
        unsigned int a5@<ebx>,
        int a6@<ebp>,
        int a7@<edi>,
        int a8@<esi>,
        int budgetGroupID,
        int a10,
        int a11,
        int a12)
{
  int v12; // eax

  LOBYTE(a3) = __inbyte(a4);
  dword_3F0A1DE8 = a3 - (a2 + 225722122);
  dword_3F0A1DF0 = dword_3F0A1DE8 + 0x1000000;
  if ( (a5 & 7) != 0 || a5 < 8 )
    __debugbreak();
  *(_DWORD *)(a7 + 8) = a5;
  _InterlockedExchange((volatile __int32 *)a7, 0);
  v12 = *(_DWORD *)(a6 + 8);
  *(_DWORD *)(a7 + 12) = 0;
  *(_DWORD *)(v12 + 4 * a8) = a12;
  JUMPOUT(0x3F0061F1);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A650
// Name: ?FindObject@CValidator@@QAEPAVCValObject@@PAX@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CThreadMutex *__thiscall CValidator::FindObject(CValidator *this, CThreadMutex *pvObj)
{
  this->m_threadMutexValidationLock[21] = pvObj;
  return pvObj;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A680
// Name: ?DiffAgainst@CValidator@@QAEXPAV1@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CValidator::DiffAgainst(CValidator *this, CThreadMutex *pOtherValidator)
{
  this->m_threadMutexValidationLock[23] = pOtherValidator;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A8E0
// Name: ?UnlockValidationLocks@CValidator@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CValidator::UnlockValidationLocks(CValidator *this@<ecx>, CValObject *a2@<eax>, int a3@<ebx>)
{
  this->m_pValObjectFirst = a2;
  LOBYTE(this->m_pValObjectLast) = *(_BYTE *)(a3 + 4);
  this->m_pValObjectCur = *(CValObject **)(a3 + 8);
  this->m_pValObjects = *(CValObject **)(a3 + 12);
  this->m_cValObjectsAllocated = *(_DWORD *)(a3 + 16);
  this->m_cValObjectsUsed = *(_DWORD *)(a3 + 20);
  this->m_cubThreshold = *(_DWORD *)(a3 + 24);
  this->m_cpvOwned = *(_DWORD *)(a3 + 28);
  this->m_cpubLeaked = *(_DWORD *)(a3 + 32);
  this->m_cubLeaked = *(_DWORD *)(a3 + 36);
  *(_DWORD *)&this->m_bMemLeaks = *(_DWORD *)(a3 + 40);
  LOWORD(this->m_threadMutexValidationLock[0]) = *(_WORD *)(a3 + 44);
  JUMPOUT(0x3F00A92C);
}

//------------------------------------------------------------------------------
// Address: 0x3F00BD30
// Name: sub_3F00BD30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall sub_3F00BD30(_DWORD *this, struct std::exception *a2)
{
  sub_3F00BD80(a1: a2);
  *this = &std::out_of_range::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00BD80
// Name: sub_3F00BD80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F00BD80(int this, struct std::exception *a2)
{
  std::exception::exception((std::exception *)this, a2);
  *(_DWORD *)this = &std::logic_error::`vftable';
  *(_DWORD *)(this + 36) = 15;
  *(_DWORD *)(this + 32) = 0;
  *(_BYTE *)(this + 16) = 0;
  ((void (__stdcall *)(struct std::exception *, _DWORD))loc_3F00E290)(a1: &a2[1], a2: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00BDF0
// Name: sub_3F00BDF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F00BDF0(_DWORD *this)
{
  int v1; // esi
  int v2; // ecx
  int result; // eax
  _DWORD OutBuffer[2]; // [esp+4h] [ebp-10h] BYREF
  unsigned int BytesReturned; // [esp+Ch] [ebp-8h] BYREF
  int InBuffer; // [esp+10h] [ebp-4h] BYREF

  v1 = *(this + 8);
  v2 = *(this + 3);
  result = 0;
  OutBuffer[0] = 0;
  OutBuffer[1] = 0;
  InBuffer = v1;
  if ( *(_BYTE *)(v2 + 80) != 0 )
  {
    DeviceIoControl(
      hDevice: *(HANDLE *)(v2 + 76),
      dwIoControlCode: 0x9C406404,
      lpInBuffer: &InBuffer,
      nInBufferSize: 4u,
      lpOutBuffer: OutBuffer,
      nOutBufferSize: 8u,
      lpBytesReturned: &BytesReturned,
      lpOverlapped: nullptr);
    return OutBuffer[0];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00BEF0
// Name: sub_3F00BEF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F00BEF0@<eax>(_DWORD *a1@<edi>, int a2, char *a3, int a4, int a5)
{
  int v5; // eax
  _DWORD *v6; // esi
  int v8; // [esp+0h] [ebp-18h]

  v5 = dword_3F03D3DC;
  *a1 = dword_3F03D3DC;
  dword_3F03D3DC = v5 + 1;
  v6 = operator new(Size: 0x30u);
  if ( v6 != nullptr )
  {
    v6[3] = ((int (__stdcall *)(int))loc_3F00EA90)(a1: v8);
    *((_WORD *)v6 + 2) = 0;
    v6[11] = v6 + 1;
    v6[4] = 402653184;
    v6[5] = 0;
    v6[6] = 253952;
    v6[7] = 0;
    v6[2] = &__security_cookie_0;
    *v6 = 0;
    v6[9] = 864;
    v6[8] = 768;
    v6[10] = 928;
  }
  return VCR_Hook_recv(s: a2, buf: a3, len: a4, flags: a5);
}

} // namespace tier0_s
