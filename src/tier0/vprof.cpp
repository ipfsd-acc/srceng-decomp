// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/vprof.cpp
// Functions: 124
// ============================================================

#include "tier0\vprof.h"

//------------------------------------------------------------------------------
// Address: 0x1000AE80
// Name: public: void CVProfile::HideBudgetGroup(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::HideBudgetGroup(CVProfile *this, const char *pszName, bool bHide)
{
  int v4; // eax

  v4 = CVProfile::BudgetGroupNameToBudgetGroupID(this, pBudgetGroupName: pszName);
  CVProfile::HideBudgetGroup(this, budgetGroupID: v4, bHide);
}

//------------------------------------------------------------------------------
// Address: 0x100119E0
// Name: public: CVProfNode::~CVProfNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::~CVProfNode(CVProfNode *this)
{
  CL2Cache::~CL2Cache(this: &this->m_L2Cache);
}

//------------------------------------------------------------------------------
// Address: 0x100119F0
// Name: public: void CVProfNode::EnterScope(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::EnterScope(CVProfNode *this)
{
  int m_nRecursions; // eax
  int m_BudgetGroupID; // esi

  m_nRecursions = this->m_nRecursions;
  ++this->m_nCurFrameCalls;
  this->m_nRecursions = m_nRecursions + 1;
  if ( m_nRecursions == 0 )
  {
    this->m_Timer.m_Duration.m_Int64 = __rdtsc();
    if ( g_VProfCurrentProfile.m_bPMEInit && g_VProfCurrentProfile.m_bPMEEnabled )
      CL2Cache::Start(this: &this->m_L2Cache);
    m_BudgetGroupID = this->m_BudgetGroupID;
    g_VProfCurrentProfile.m_GroupIDStack[g_VProfCurrentProfile.m_GroupIDStackDepth++] = m_BudgetGroupID;
    if ( *((_DWORD *)&g_VProfCurrentProfile.m_bVTuneGroupEnabled + g_VProfCurrentProfile.m_GroupIDStackDepth) != m_BudgetGroupID
      && g_VProfCurrentProfile.m_bVTuneGroupEnabled
      && m_BudgetGroupID == g_VProfCurrentProfile.m_nVTuneGroupID )
    {
      vtune(resume: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011A80
// Name: public: void CVProfNode::Resume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::Resume(CVProfNode *this)
{
  CVProfNode *m_pChild; // ecx

  do
  {
    if ( this->m_nRecursions > 0 )
    {
      this->m_Timer.m_Duration.m_Int64 = __rdtsc();
      if ( g_VProfCurrentProfile.m_bPMEInit && g_VProfCurrentProfile.m_bPMEEnabled )
        CL2Cache::Start(this: &this->m_L2Cache);
    }
    m_pChild = this->m_pChild;
    if ( m_pChild != nullptr )
      CVProfNode::Resume(this: m_pChild);
    this = this->m_pSibling;
  }
  while ( this != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x10011AE0
// Name: TimeCompare
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl TimeCompare(const TimeSums_t *lhs, const TimeSums_t *rhs)
{
  return lhs->time > rhs->time;
}

//------------------------------------------------------------------------------
// Address: 0x10011B00
// Name: TimeLessChildrenCompare
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl TimeLessChildrenCompare(const TimeSums_t *lhs, const TimeSums_t *rhs)
{
  return lhs->timeLessChildren > rhs->timeLessChildren;
}

//------------------------------------------------------------------------------
// Address: 0x10011B20
// Name: PeakCompare
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PeakCompare(const TimeSums_t *lhs, const TimeSums_t *rhs)
{
  return lhs->peak > rhs->peak;
}

//------------------------------------------------------------------------------
// Address: 0x10011B40
// Name: AverageTimeCompare
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl AverageTimeCompare(const TimeSums_t *lhs, const TimeSums_t *rhs)
{
  unsigned int calls; // eax
  double v3; // xmm0_8
  double v4; // xmm1_8
  unsigned int v5; // eax

  calls = lhs->calls;
  v3 = 0.0;
  if ( calls != 0 )
    v4 = lhs->time / (double)calls;
  else
    v4 = 0.0;
  v5 = rhs->calls;
  if ( v5 != 0 )
    v3 = rhs->time / (double)v5;
  return v4 > v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011BB0
// Name: AverageTimeLessChildrenCompare
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl AverageTimeLessChildrenCompare(const TimeSums_t *lhs, const TimeSums_t *rhs)
{
  unsigned int calls; // eax
  double v3; // xmm0_8
  double v4; // xmm1_8
  unsigned int v5; // eax

  calls = lhs->calls;
  v3 = 0.0;
  if ( calls != 0 )
    v4 = lhs->timeLessChildren / (double)calls;
  else
    v4 = 0.0;
  v5 = rhs->calls;
  if ( v5 != 0 )
    v3 = rhs->timeLessChildren / (double)v5;
  return v4 > v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011C20
// Name: PeakOverAverageCompare
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PeakOverAverageCompare(const TimeSums_t *lhs, const TimeSums_t *rhs)
{
  unsigned int calls; // eax
  double v3; // xmm0_8
  double v4; // xmm2_8
  unsigned int v5; // eax
  double v6; // xmm3_8
  double v7; // xmm1_8

  calls = lhs->calls;
  v3 = 0.0;
  if ( calls != 0 )
    v4 = lhs->time / (double)calls;
  else
    v4 = 0.0;
  v5 = rhs->calls;
  if ( v5 != 0 )
    v6 = rhs->time / (double)v5;
  else
    v6 = 0.0;
  if ( v4 == 0.0 )
    v7 = 0.0;
  else
    v7 = lhs->peak / v4;
  if ( v6 != 0.0 )
    v3 = rhs->peak / v6;
  return v7 > v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011CC0
// Name: public: class CVProfNode __near * CVProfile::FindNode(class CVProfNode __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfile::FindNode(CVProfile *this, CVProfNode *pStartNode, const char *pszNode)
{
  CVProfNode *m_pSibling; // ecx
  CVProfNode *result; // eax
  CVProfNode *m_pChild; // ecx

  if ( strcmp(pStartNode->m_pszName, pszNode) == 0 )
    return pStartNode;
  m_pSibling = pStartNode->m_pSibling;
  result = nullptr;
  if ( m_pSibling == nullptr || (result = CVProfile::FindNode(this, pStartNode: m_pSibling, pszNode)) == nullptr )
  {
    m_pChild = pStartNode->m_pChild;
    if ( m_pChild != nullptr )
      return CVProfile::FindNode(this, pStartNode: m_pChild, pszNode);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011D40
// Name: public: void CVProfile::GetBudgetGroupColor(int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::GetBudgetGroupColor(CVProfile *this, int budgetGroupID, int *r, int *g, int *b, int *a)
{
  *r = g_ColorLookup[(budgetGroupID % 64) & 1 | ((budgetGroupID % 64) >> 4) & 2];
  *g = g_ColorLookup[((budgetGroupID % 64) & 2 | ((budgetGroupID % 64) >> 2) & 4) >> 1];
  *b = g_ColorLookup[((budgetGroupID % 64) >> 2) & 3];
  *a = 255;
}

//------------------------------------------------------------------------------
// Address: 0x10011DB0
// Name: protected: int CVProfile::FindBudgetGroupName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::FindBudgetGroupName(CVProfile *this, const char *pBudgetGroupName)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_nBudgetGroupNames <= 0 )
    return -1;
  while ( _stricmp(dst: pBudgetGroupName, src: this->m_pBudgetGroups[v3].m_pName) != 0 )
  {
    if ( ++v3 >= this->m_nBudgetGroupNames )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011E00
// Name: protected: int CVProfile::AddBudgetGroupName(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::AddBudgetGroupName(CVProfile *this, const char *pBudgetGroupName, int budgetFlags)
{
  char *v4; // ebx
  int m_nBudgetGroupNames; // ecx
  int m_nBudgetGroupNamesAllocated; // eax
  int v7; // eax
  int v8; // ecx
  CVProfile::CBudgetGroup *v9; // edi
  int i; // eax
  CVProfile::CBudgetGroup *m_pBudgetGroups; // ecx
  void (*m_pNumBudgetGroupsChangedCallBack)(void); // eax

  v4 = (char *)operator new[](cb: strlen(pBudgetGroupName) + 1);
  strcpy(v4, pBudgetGroupName);
  m_nBudgetGroupNames = this->m_nBudgetGroupNames;
  m_nBudgetGroupNamesAllocated = this->m_nBudgetGroupNamesAllocated;
  if ( m_nBudgetGroupNames + 1 > m_nBudgetGroupNamesAllocated )
  {
    v7 = 2 * m_nBudgetGroupNamesAllocated;
    v8 = m_nBudgetGroupNames + 6;
    this->m_nBudgetGroupNamesAllocated = v7;
    if ( v8 > v7 )
      v7 = v8;
    this->m_nBudgetGroupNamesAllocated = v7;
    v9 = (CVProfile::CBudgetGroup *)operator new[](cb: 8 * v7);
    for ( i = 0; i < this->m_nBudgetGroupNames; ++i )
    {
      m_pBudgetGroups = this->m_pBudgetGroups;
      v9[i].m_pName = m_pBudgetGroups[i].m_pName;
      v9[i].m_BudgetFlags = m_pBudgetGroups[i].m_BudgetFlags;
    }
    operator delete[](p: this->m_pBudgetGroups);
    this->m_pBudgetGroups = v9;
  }
  this->m_pBudgetGroups[this->m_nBudgetGroupNames].m_pName = v4;
  this->m_pBudgetGroups[this->m_nBudgetGroupNames].m_BudgetFlags = budgetFlags;
  m_pNumBudgetGroupsChangedCallBack = this->m_pNumBudgetGroupsChangedCallBack;
  ++this->m_nBudgetGroupNames;
  if ( m_pNumBudgetGroupsChangedCallBack != nullptr )
    m_pNumBudgetGroupsChangedCallBack();
  return this->m_nBudgetGroupNames - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011F10
// Name: public: int CVProfile::BudgetGroupNameToBudgetGroupID(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::BudgetGroupNameToBudgetGroupID(
        CVProfile *this,
        const char *pBudgetGroupName,
        int budgetFlagsToORIn)
{
  int result; // eax

  result = CVProfile::FindBudgetGroupName(this, pBudgetGroupName);
  if ( result == -1 )
    return CVProfile::AddBudgetGroupName(this, pBudgetGroupName, budgetFlags: budgetFlagsToORIn);
  this->m_pBudgetGroups[result].m_BudgetFlags |= budgetFlagsToORIn;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011F50
// Name: public: int CVProfile::BudgetGroupNameToBudgetGroupID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::BudgetGroupNameToBudgetGroupID(CVProfile *this, const char *pBudgetGroupName)
{
  int result; // eax

  result = CVProfile::FindBudgetGroupName(this, pBudgetGroupName);
  if ( result == -1 )
    return CVProfile::AddBudgetGroupName(this, pBudgetGroupName, budgetFlags: 4);
  this->m_pBudgetGroups[result].m_BudgetFlags |= 4u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011F90
// Name: public: int CVProfile::GetNumBudgetGroups(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::GetNumBudgetGroups(CVProfile *this)
{
  return this->m_nBudgetGroupNames;
}

//------------------------------------------------------------------------------
// Address: 0x10011FA0
// Name: public: void CVProfile::RegisterNumBudgetGroupsChangedCallBack(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::RegisterNumBudgetGroupsChangedCallBack(CVProfile *this, void (__cdecl *pCallBack)())
{
  this->m_pNumBudgetGroupsChangedCallBack = pCallBack;
}

//------------------------------------------------------------------------------
// Address: 0x10011FB0
// Name: public: void CVProfile::HideBudgetGroup(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::HideBudgetGroup(CVProfile *this, int budgetGroupID, bool bHide)
{
  if ( budgetGroupID != -1 )
  {
    if ( bHide )
      this->m_pBudgetGroups[budgetGroupID].m_BudgetFlags |= 0x8000u;
    else
      this->m_pBudgetGroups[budgetGroupID].m_BudgetFlags &= ~0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011FF0
// Name: public: int __near * CVProfile::FindOrCreateCounter(char const __near *,enum CounterGroup_t)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CVProfile::FindOrCreateCounter(CVProfile *this, const char *pName, CounterGroup_t eCounterGroup)
{
  int v4; // edi
  char **m_CounterNames; // ebx
  char *v6; // eax

  if ( this->m_NumCounters + 1 >= 256 || this->m_TargetThreadId != GetCurrentThreadId() )
    return &dummy;
  v4 = 0;
  if ( this->m_NumCounters <= 0 )
  {
LABEL_7:
    v6 = (char *)operator new[](cb: strlen(pName) + 1);
    strcpy(v6, pName);
    this->m_Counters[this->m_NumCounters] = 0;
    this->m_CounterGroups[this->m_NumCounters] = eCounterGroup;
    this->m_CounterNames[this->m_NumCounters++] = v6;
    return (int *)(&this->m_bPMEInit + 4 * this->m_NumCounters);
  }
  else
  {
    m_CounterNames = this->m_CounterNames;
    while ( _stricmp(dst: *m_CounterNames, src: pName) != 0 )
    {
      ++v4;
      ++m_CounterNames;
      if ( v4 >= this->m_NumCounters )
        goto LABEL_7;
    }
    return &this->m_Counters[v4];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100120F0
// Name: public: void CVProfile::ResetCounters(enum CounterGroup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::ResetCounters(CVProfile *this, CounterGroup_t eCounterGroup)
{
  int v2; // eax
  int *m_Counters; // edx

  v2 = 0;
  if ( this->m_NumCounters > 0 )
  {
    m_Counters = this->m_Counters;
    do
    {
      if ( this->m_CounterGroups[v2] == eCounterGroup )
        *m_Counters = 0;
      ++v2;
      ++m_Counters;
    }
    while ( v2 < this->m_NumCounters );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012140
// Name: public: int CVProfile::GetNumCounters(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::GetNumCounters(CVProfile *this)
{
  return this->m_NumCounters;
}

//------------------------------------------------------------------------------
// Address: 0x10012150
// Name: public: char const __near * CVProfile::GetCounterName(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVProfile::GetCounterName(CVProfile *this, int index)
{
  return this->m_CounterNames[index];
}

//------------------------------------------------------------------------------
// Address: 0x10012170
// Name: public: int CVProfile::GetCounterValue(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::GetCounterValue(CVProfile *this, int index)
{
  return this->m_Counters[index];
}

//------------------------------------------------------------------------------
// Address: 0x10012190
// Name: public: char const __near * CVProfile::GetCounterNameAndValue(int,int __near &)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVProfile::GetCounterNameAndValue(CVProfile *this, int index, int *val)
{
  *val = this->m_Counters[index];
  return this->m_CounterNames[index];
}

//------------------------------------------------------------------------------
// Address: 0x100121B0
// Name: public: enum CounterGroup_t CVProfile::GetCounterGroup(int)const
// Source: json
//------------------------------------------------------------------------------
CounterGroup_t __thiscall CVProfile::GetCounterGroup(CVProfile *this, int index)
{
  return this->m_CounterGroups[index];
}

//------------------------------------------------------------------------------
// Address: 0x100121D0
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Max(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Max(
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100121F0
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Min(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Min(
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012210
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Max(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Max(
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012230
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Min(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Min(
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012250
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *i; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( this->_Ptr->_Isnil == 0 )
  {
    Right = Ptr->_Right;
    if ( Right->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Right )
          break;
        result->_Ptr = i;
      }
      result->_Ptr = i;
    }
    else
    {
      for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
        Right = j;
      result->_Ptr = Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100122A0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *i; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( this->_Ptr->_Isnil == 0 )
  {
    Right = Ptr->_Right;
    if ( Right->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Right )
          break;
        result->_Ptr = i;
      }
      result->_Ptr = i;
    }
    else
    {
      for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
        Right = j;
      result->_Ptr = Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100122F0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v5; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( Ptr->_Isnil != 0 )
  {
    result->_Ptr = Ptr->_Right;
    return result;
  }
  Left = Ptr->_Left;
  if ( Ptr->_Left->_Isnil == 0 )
  {
    Right = Left->_Right;
    if ( Right->_Isnil == 0 )
    {
      do
      {
        v5 = Right;
        Right = Right->_Right;
      }
      while ( Right->_Isnil == 0 );
      result->_Ptr = v5;
      return result;
    }
LABEL_11:
    result->_Ptr = Left;
    return result;
  }
  for ( Left = Ptr->_Parent; Left->_Isnil == 0; Left = Left->_Parent )
  {
    if ( result->_Ptr != Left->_Left )
      break;
    result->_Ptr = Left;
  }
  if ( result->_Ptr->_Isnil == 0 )
    goto LABEL_11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012350
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v5; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( Ptr->_Isnil != 0 )
  {
    result->_Ptr = Ptr->_Right;
    return result;
  }
  Left = Ptr->_Left;
  if ( Ptr->_Left->_Isnil == 0 )
  {
    Right = Left->_Right;
    if ( Right->_Isnil == 0 )
    {
      do
      {
        v5 = Right;
        Right = Right->_Right;
      }
      while ( Right->_Isnil == 0 );
      result->_Ptr = v5;
      return result;
    }
LABEL_11:
    result->_Ptr = Left;
    return result;
  }
  for ( Left = Ptr->_Parent; Left->_Isnil == 0; Left = Left->_Parent )
  {
    if ( result->_Ptr != Left->_Left )
      break;
    result->_Ptr = Left;
  }
  if ( result->_Ptr->_Isnil == 0 )
    goto LABEL_11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100123B0
// Name: void std::_Push_heap<struct TimeSums_t __near *,int,struct TimeSums_t,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,int,int,struct TimeSums_t __near &&,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        TimeSums_t *_First,
        int _Hole,
        int _Top,
        TimeSums_t *_Val,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  int v5; // ebx
  int i; // edi
  TimeSums_t *v7; // esi
  TimeSums_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    *(_QWORD *)&v8->pszProfileScope = *(_QWORD *)&v7->pszProfileScope;
    v8->time = v7->time;
    v8->timeLessChildren = v7->timeLessChildren;
    v8->peak = v7->peak;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10012460
// Name: struct TimeSums_t __near * std::_Move_backward<struct TimeSums_t __near *,struct TimeSums_t __near *>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
TimeSums_t *__cdecl std::_Move_backward<TimeSums_t *,TimeSums_t *>(
        TimeSums_t *_First,
        TimeSums_t *_Last,
        TimeSums_t *_Dest)
{
  TimeSums_t *v3; // ecx
  TimeSums_t *result; // eax
  __int64 v5; // xmm0_8

  v3 = _Last;
  for ( result = _Dest; v3 != _First; result->peak = v3->peak )
  {
    v5 = *(_QWORD *)&v3[-1].pszProfileScope;
    --v3;
    --result;
    *(_QWORD *)&result->pszProfileScope = v5;
    result->time = v3->time;
    result->timeLessChildren = v3->timeLessChildren;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100124B0
// Name: public: bool CVProfNode::ExitScope(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVProfNode::ExitScope(CVProfNode *this)
{
  bool v2; // zf
  unsigned __int64 v3; // kr00_8
  bool v4; // cf
  int v5; // ecx
  unsigned __int64 v7; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v8; // [esp+Ch] [ebp-4h]

  v2 = this->m_nRecursions-- == 1;
  if ( v2 && this->m_nCurFrameCalls != 0 )
  {
    v8 = &v7;
    v7 = __rdtsc();
    v3 = v7 - this->m_Timer.m_Duration.m_Int64;
    this->m_Timer.m_Duration.m_Int64 = v3;
    v4 = __CFADD__((_DWORD)v3, this->m_CurFrameTime.m_Int64);
    LODWORD(this->m_CurFrameTime.m_Int64) += v3;
    HIDWORD(this->m_CurFrameTime.m_Int64) += HIDWORD(this->m_Timer.m_Duration.m_Int64) + v4;
    if ( g_VProfCurrentProfile.m_bPMEInit && g_VProfCurrentProfile.m_bPMEEnabled )
    {
      CL2Cache::End(this: &this->m_L2Cache);
      this->m_iCurL2CacheMiss += this->m_L2Cache.m_iL2CacheMissCount;
    }
    v5 = g_VProfCurrentProfile.m_GroupIDStack[g_VProfCurrentProfile.m_GroupIDStackDepth--];
    if ( g_VProfCurrentProfile.m_GroupIDStack[g_VProfCurrentProfile.m_GroupIDStackDepth] != v5
      && g_VProfCurrentProfile.m_bVTuneGroupEnabled
      && v5 == g_VProfCurrentProfile.m_nVTuneGroupID )
    {
      vtune(resume: false);
    }
  }
  return this->m_nRecursions == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012570
// Name: public: void CVProfNode::Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::Pause(CVProfNode *this)
{
  unsigned __int64 v2; // kr00_8
  bool v3; // cf
  CVProfNode *m_pChild; // ecx
  unsigned __int64 v5; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v6; // [esp+Ch] [ebp-4h]

  do
  {
    if ( this->m_nRecursions > 0 )
    {
      v6 = &v5;
      v5 = __rdtsc();
      v2 = v5 - this->m_Timer.m_Duration.m_Int64;
      this->m_Timer.m_Duration.m_Int64 = v2;
      v3 = __CFADD__((_DWORD)v2, this->m_CurFrameTime.m_Int64);
      LODWORD(this->m_CurFrameTime.m_Int64) += v2;
      HIDWORD(this->m_CurFrameTime.m_Int64) += HIDWORD(this->m_Timer.m_Duration.m_Int64) + v3;
      if ( g_VProfCurrentProfile.m_bPMEInit && g_VProfCurrentProfile.m_bPMEEnabled )
      {
        CL2Cache::End(this: &this->m_L2Cache);
        this->m_iCurL2CacheMiss += this->m_L2Cache.m_iL2CacheMissCount;
      }
    }
    m_pChild = this->m_pChild;
    if ( m_pChild != nullptr )
      CVProfNode::Pause(this: m_pChild);
    this = this->m_pSibling;
  }
  while ( this != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x10012600
// Name: public: void CVProfNode::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::Reset(CVProfNode *this)
{
  CVProfNode *m_pChild; // ecx

  do
  {
    m_pChild = this->m_pChild;
    this->m_nPrevFrameCalls = 0;
    LODWORD(this->m_PrevFrameTime.m_Int64) = 0;
    HIDWORD(this->m_PrevFrameTime.m_Int64) = 0;
    this->m_nCurFrameCalls = 0;
    LODWORD(this->m_CurFrameTime.m_Int64) = 0;
    HIDWORD(this->m_CurFrameTime.m_Int64) = 0;
    this->m_nTotalCalls = 0;
    LODWORD(this->m_TotalTime.m_Int64) = 0;
    HIDWORD(this->m_TotalTime.m_Int64) = 0;
    LODWORD(this->m_PeakTime.m_Int64) = 0;
    HIDWORD(this->m_PeakTime.m_Int64) = 0;
    this->m_iPrevL2CacheMiss = 0;
    this->m_iCurL2CacheMiss = 0;
    this->m_iTotalL2CacheMiss = 0;
    if ( m_pChild != nullptr )
      CVProfNode::Reset(this: m_pChild);
    this = this->m_pSibling;
  }
  while ( this != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x10012650
// Name: public: void CVProfNode::MarkFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::MarkFrame(CVProfNode *this)
{
  int m_Int64; // ecx
  int m_Int64_high; // edx
  unsigned int m_nCurFrameCalls; // eax
  int m_iCurL2CacheMiss; // ecx
  int v6; // edx
  bool v7; // cf
  int v8; // ecx
  CVProfNode *m_pChild; // ecx

  do
  {
    m_Int64 = this->m_CurFrameTime.m_Int64;
    m_Int64_high = HIDWORD(this->m_CurFrameTime.m_Int64);
    m_nCurFrameCalls = this->m_nCurFrameCalls;
    this->m_nTotalCalls += m_nCurFrameCalls;
    LODWORD(this->m_PrevFrameTime.m_Int64) = m_Int64;
    m_iCurL2CacheMiss = this->m_iCurL2CacheMiss;
    HIDWORD(this->m_PrevFrameTime.m_Int64) = m_Int64_high;
    v6 = this->m_CurFrameTime.m_Int64;
    this->m_nPrevFrameCalls = m_nCurFrameCalls;
    this->m_iPrevL2CacheMiss = m_iCurL2CacheMiss;
    v7 = __CFADD__(v6, this->m_TotalTime.m_Int64);
    LODWORD(this->m_TotalTime.m_Int64) += v6;
    HIDWORD(this->m_TotalTime.m_Int64) += HIDWORD(this->m_CurFrameTime.m_Int64) + v7;
    if ( this->m_PeakTime.m_Int64 < this->m_CurFrameTime.m_Int64 )
    {
      v8 = HIDWORD(this->m_CurFrameTime.m_Int64);
      LODWORD(this->m_PeakTime.m_Int64) = this->m_CurFrameTime.m_Int64;
      HIDWORD(this->m_PeakTime.m_Int64) = v8;
    }
    m_pChild = this->m_pChild;
    this->m_iTotalL2CacheMiss += this->m_iCurL2CacheMiss;
    LODWORD(this->m_CurFrameTime.m_Int64) = 0;
    HIDWORD(this->m_CurFrameTime.m_Int64) = 0;
    this->m_nCurFrameCalls = 0;
    this->m_iCurL2CacheMiss = 0;
    if ( m_pChild != nullptr )
      CVProfNode::MarkFrame(this: m_pChild);
    this = this->m_pSibling;
  }
  while ( this != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x100126D0
// Name: public: void CVProfNode::ResetPeak(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::ResetPeak(CVProfNode *this)
{
  CVProfNode *m_pChild; // ecx

  do
  {
    m_pChild = this->m_pChild;
    LODWORD(this->m_PeakTime.m_Int64) = 0;
    HIDWORD(this->m_PeakTime.m_Int64) = 0;
    if ( m_pChild != nullptr )
      CVProfNode::ResetPeak(this: m_pChild);
    this = this->m_pSibling;
  }
  while ( this != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x10012700
// Name: public: void CVProfNode::SetCurFrameTime(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::SetCurFrameTime(CVProfNode *this, unsigned int milliseconds)
{
  if ( g_ClockSpeedMillisecondsMultiplier <= 0.0 )
    this->m_CurFrameTime.m_Int64 = 0;
  else
    this->m_CurFrameTime.m_Int64 = (unsigned __int64)((double)milliseconds / g_ClockSpeedMillisecondsMultiplier);
}

//------------------------------------------------------------------------------
// Address: 0x10012750
// Name: protected: void CVProfile::FreeNodes_R(class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::FreeNodes_R(CVProfile *this, CVProfNode *pNode)
{
  CVProfNode *m_pChild; // eax
  CVProfNode *m_pSibling; // esi

  m_pChild = pNode->m_pChild;
  if ( m_pChild != nullptr )
  {
    do
    {
      m_pSibling = m_pChild->m_pSibling;
      CVProfile::FreeNodes_R(this, pNode: m_pChild);
      m_pChild = m_pSibling;
    }
    while ( m_pSibling != nullptr );
  }
  if ( pNode == &this->m_Root )
  {
    pNode->m_pChild = nullptr;
  }
  else
  {
    CL2Cache::~CL2Cache(this: &pNode->m_L2Cache);
    operator delete(p: pNode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100127B0
// Name: public: void CVProfile::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Term(CVProfile *this)
{
  int v2; // ebx
  int i; // edi
  void **m_CounterNames; // edi
  CVProfNode *m_pChild; // eax
  CVProfNode *m_pSibling; // edi

  v2 = 0;
  for ( i = 0; i < this->m_nBudgetGroupNames; ++i )
    operator delete[](p: this->m_pBudgetGroups[i].m_pName);
  operator delete(p: this->m_pBudgetGroups);
  this->m_nBudgetGroupNamesAllocated = 0;
  this->m_nBudgetGroupNames = 0;
  this->m_pBudgetGroups = nullptr;
  if ( this->m_NumCounters > 0 )
  {
    m_CounterNames = (void **)this->m_CounterNames;
    do
    {
      operator delete[](p: *m_CounterNames);
      *m_CounterNames = nullptr;
      ++v2;
      ++m_CounterNames;
    }
    while ( v2 < this->m_NumCounters );
  }
  this->m_NumCounters = 0;
  if ( this != (CVProfile *)-4120 )
  {
    m_pChild = this->m_Root.m_pChild;
    if ( m_pChild != nullptr )
    {
      do
      {
        m_pSibling = m_pChild->m_pSibling;
        CVProfile::FreeNodes_R(this, pNode: m_pChild);
        m_pChild = m_pSibling;
      }
      while ( m_pSibling != nullptr );
    }
    this->m_Root.m_pChild = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012870
// Name: public: struct TimeSums_t __near * std::allocator<struct TimeSums_t>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
TimeSums_t *__thiscall std::allocator<TimeSums_t>::allocate(std::allocator<TimeSums_t> *this, unsigned int _Count)
{
  TimeSums_t *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x7FFFFFF || (result = (TimeSums_t *)operator new(size: 32 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100128D0
// Name: protected: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Lrotate(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Parent; // ecx

  Right = _Wherenode->_Right;
  _Wherenode->_Right = Right->_Left;
  if ( Right->_Left->_Isnil == 0 )
    Right->_Left->_Parent = _Wherenode;
  Right->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Left )
      Parent->_Left = Right;
    else
      Parent->_Right = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012930
// Name: protected: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Rrotate(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Parent; // ecx

  Left = _Wherenode->_Left;
  _Wherenode->_Left = _Wherenode->_Left->_Right;
  Right = Left->_Right;
  if ( Right->_Isnil == 0 )
    Right->_Parent = _Wherenode;
  Left->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Right )
      Parent->_Right = Left;
    else
      Parent->_Left = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012990
// Name: protected: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Lrotate(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Parent; // ecx

  Right = _Wherenode->_Right;
  _Wherenode->_Right = Right->_Left;
  if ( Right->_Left->_Isnil == 0 )
    Right->_Left->_Parent = _Wherenode;
  Right->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Left )
      Parent->_Left = Right;
    else
      Parent->_Right = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100129F0
// Name: protected: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Rrotate(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Parent; // ecx

  Left = _Wherenode->_Left;
  _Wherenode->_Left = _Wherenode->_Left->_Right;
  Right = Left->_Right;
  if ( Right->_Isnil == 0 )
    Right->_Parent = _Wherenode;
  Left->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Right )
      Parent->_Right = Left;
    else
      Parent->_Left = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012A50
// Name: void std::_Cons_val<class std::allocator<struct TimeSums_t>,struct TimeSums_t,struct TimeSums_t>(class std::allocator<struct TimeSums_t> __near &,struct TimeSums_t __near *,struct TimeSums_t __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<TimeSums_t>,TimeSums_t,TimeSums_t>(
        std::allocator<TimeSums_t> *_Alval,
        TimeSums_t *_Pdest,
        TimeSums_t *_Src)
{
  if ( _Pdest != nullptr )
    *_Pdest = *_Src;
}

//------------------------------------------------------------------------------
// Address: 0x10012A90
// Name: struct TimeSums_t __near * std::_Copy_impl<struct TimeSums_t __near *,struct TimeSums_t __near *>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
TimeSums_t *__cdecl std::_Copy_impl<TimeSums_t *,TimeSums_t *>(
        TimeSums_t *_First,
        TimeSums_t *_Last,
        TimeSums_t *_Dest)
{
  TimeSums_t *v3; // ecx
  TimeSums_t *result; // eax

  v3 = _First;
  for ( result = _Dest; v3 != _Last; ++result )
  {
    *(_QWORD *)&result->pszProfileScope = *(_QWORD *)&v3->pszProfileScope;
    result->time = v3->time;
    result->timeLessChildren = v3->timeLessChildren;
    result->peak = v3->peak;
    ++v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012AE0
// Name: void std::_Adjust_heap<struct TimeSums_t __near *,int,struct TimeSums_t,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,int,int,struct TimeSums_t __near &&,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        TimeSums_t *_First,
        int _Hole,
        int _Bottom,
        TimeSums_t *_Val,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  int v5; // edx
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  TimeSums_t *v9; // eax
  TimeSums_t *v10; // ecx
  TimeSums_t *v11; // ecx
  int v12; // ecx
  int v13; // ebx
  TimeSums_t *v14; // esi
  TimeSums_t *v15; // eax
  int _Top; // [esp+Ch] [ebp-4h]
  int _Bottoma; // [esp+20h] [ebp+10h]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  _Top = _Hole;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = &_First[v7];
      v10 = &_First[v6];
      *(_QWORD *)&v10->pszProfileScope = *(_QWORD *)&v9->pszProfileScope;
      v10->time = v9->time;
      _Hole = v7;
      v6 = v7;
      v10->timeLessChildren = v9->timeLessChildren;
      v7 = 2 * v7 + 2;
      v10->peak = v9->peak;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    v11 = &_First[v5 - 1];
    _First[v6] = *v11;
    _Hole = v5 - 1;
    v6 = v5 - 1;
  }
  v12 = v6;
  _Bottoma = v6;
  v13 = (v6 - 1) / 2;
  if ( _Top < _Hole )
  {
    do
    {
      v14 = &_First[v13];
      if ( !_Pred(a1: v14, a2: _Val) )
        break;
      v15 = &_First[_Bottoma];
      *(_QWORD *)&v15->pszProfileScope = *(_QWORD *)&v14->pszProfileScope;
      v15->time = v14->time;
      v15->timeLessChildren = v14->timeLessChildren;
      v15->peak = v14->peak;
      _Bottoma = v13;
      v13 = (v13 - 1) / 2;
    }
    while ( _Top < _Bottoma );
    v12 = _Bottoma;
  }
  _First[v12] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10012C50
// Name: public: class CVProfNode __near * CVProfNode::GetSubNode(char const __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfNode::GetSubNode(
        CVProfNode *this,
        const char *pszName,
        int detailLevel,
        const char *pBudgetGroupName,
        int budgetFlags)
{
  CVProfNode *result; // eax
  CVProfNode *v7; // eax

  result = this->m_pChild;
  if ( result != nullptr )
  {
    while ( result->m_pszName != pszName )
    {
      result = result->m_pSibling;
      if ( result == nullptr )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v7 = (CVProfNode *)operator new(size: 0x90u);
    if ( v7 != nullptr )
    {
      result = CVProfNode::CVProfNode(this: v7, pszName, detailLevel, pParent: this, pBudgetGroupName, budgetFlags);
      result->m_pSibling = this->m_pChild;
      this->m_pChild = result;
    }
    else
    {
      MEMORY[0x80] = this->m_pChild;
      this->m_pChild = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012CC0
// Name: public: class CVProfNode __near * CVProfNode::GetSubNode(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfNode::GetSubNode(
        CVProfNode *this,
        const char *pszName,
        int detailLevel,
        const char *pBudgetGroupName)
{
  return CVProfNode::GetSubNode(this, pszName, detailLevel, pBudgetGroupName, budgetFlags: 4);
}

//------------------------------------------------------------------------------
// Address: 0x10012CE0
// Name: public: CVProfile::CVProfile(void)
// Source: json
//------------------------------------------------------------------------------
CVProfile *__thiscall CVProfile::CVProfile(CVProfile *this)
{
  CVProfNode *p_m_Root; // ecx
  int BudgetGroupName; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax

  p_m_Root = &this->m_Root;
  this->m_enabled = 0;
  this->m_fAtRoot = true;
  this->m_pCurNode = p_m_Root;
  CVProfNode::CVProfNode(
    this: p_m_Root,
    pszName: "Root",
    detailLevel: 0,
    pParent: nullptr,
    pBudgetGroupName: "Unaccounted",
    budgetFlags: 0);
  this->m_nFrames = 0;
  this->m_pausedEnabledDepth = 0;
  this->m_GroupIDStackDepth = 1;
  this->m_GroupIDStack[0] = 0;
  this->m_TargetThreadId = GetCurrentThreadId();
  this->m_pBudgetGroups = (CVProfile::CBudgetGroup *)operator new[](cb: 0x100u);
  this->m_nBudgetGroupNames = 0;
  this->m_nBudgetGroupNamesAllocated = 32;
  BudgetGroupName = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Unaccounted");
  if ( BudgetGroupName == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Unaccounted", budgetFlags: 6);
  else
    this->m_pBudgetGroups[BudgetGroupName].m_BudgetFlags |= 6u;
  v4 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "World Rendering");
  if ( v4 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "World Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v4].m_BudgetFlags |= 1u;
  v5 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Displacement_Rendering");
  if ( v5 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Displacement_Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v5].m_BudgetFlags |= 1u;
  v6 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Game");
  if ( v6 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Game", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v6].m_BudgetFlags |= 6u;
  v7 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Player");
  if ( v7 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Player", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v7].m_BudgetFlags |= 6u;
  v8 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "NPCs");
  if ( v8 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "NPCs", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v8].m_BudgetFlags |= 6u;
  v9 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Server Animation");
  if ( v9 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Server Animation", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v9].m_BudgetFlags |= 6u;
  v10 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Client_Animation");
  if ( v10 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Client_Animation", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v10].m_BudgetFlags |= 1u;
  v11 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Physics");
  if ( v11 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Physics", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v11].m_BudgetFlags |= 6u;
  v12 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Static_Prop_Rendering");
  if ( v12 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Static_Prop_Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v12].m_BudgetFlags |= 1u;
  v13 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Other_Model_Rendering");
  if ( v13 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Other_Model_Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v13].m_BudgetFlags |= 1u;
  v14 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Fast Path Model Rendering");
  if ( v14 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Fast Path Model Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v14].m_BudgetFlags |= 1u;
  v15 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Light_Cache");
  if ( v15 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Light_Cache", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v15].m_BudgetFlags |= 1u;
  v16 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Brush_Model_Rendering");
  if ( v16 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Brush_Model_Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v16].m_BudgetFlags |= 1u;
  v17 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Shadow_Rendering");
  if ( v17 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Shadow_Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v17].m_BudgetFlags |= 1u;
  v18 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Detail_Prop_Rendering");
  if ( v18 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Detail_Prop_Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v18].m_BudgetFlags |= 1u;
  v19 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Particle/Effect_Rendering");
  if ( v19 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Particle/Effect_Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v19].m_BudgetFlags |= 1u;
  v20 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Ropes");
  if ( v20 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Ropes", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v20].m_BudgetFlags |= 1u;
  v21 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Dynamic_Light_Rendering");
  if ( v21 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Dynamic_Light_Rendering", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v21].m_BudgetFlags |= 1u;
  v22 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Networking");
  if ( v22 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Networking", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v22].m_BudgetFlags |= 6u;
  v23 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Sound");
  if ( v23 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Sound", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v23].m_BudgetFlags |= 6u;
  v24 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "VGUI");
  if ( v24 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "VGUI", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v24].m_BudgetFlags |= 6u;
  v25 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "FileSystem");
  if ( v25 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "FileSystem", budgetFlags: 6);
  else
    this->m_pBudgetGroups[v25].m_BudgetFlags |= 6u;
  v26 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Prediction");
  if ( v26 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Prediction", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v26].m_BudgetFlags |= 1u;
  v27 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Interpolation");
  if ( v27 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Interpolation", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v27].m_BudgetFlags |= 1u;
  v28 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Swap_Buffers");
  if ( v28 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Swap_Buffers", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v28].m_BudgetFlags |= 1u;
  v29 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Occlusion");
  if ( v29 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Occlusion", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v29].m_BudgetFlags |= 1u;
  v30 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Overlays");
  if ( v30 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Overlays", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v30].m_BudgetFlags |= 1u;
  v31 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Tools");
  if ( v31 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Tools", budgetFlags: 5);
  else
    this->m_pBudgetGroups[v31].m_BudgetFlags |= 5u;
  v32 = CVProfile::FindBudgetGroupName(this, pBudgetGroupName: "Texture_Cache");
  if ( v32 == -1 )
    CVProfile::AddBudgetGroupName(this, pBudgetGroupName: "Texture_Cache", budgetFlags: 1);
  else
    this->m_pBudgetGroups[v32].m_BudgetFlags |= 1u;
  *(_WORD *)&this->m_bPMEInit = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013310
// Name: public: CVProfile::~CVProfile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::~CVProfile(CVProfile *this)
{
  CVProfile::Term(this);
  CL2Cache::~CL2Cache(this: &this->m_Root.m_L2Cache);
}

//------------------------------------------------------------------------------
// Address: 0x10013330
// Name: protected: bool std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::_Buy(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::vector<TimeSums_t>::_Buy(std::vector<TimeSums_t> *this, unsigned int _Capacity)
{
  TimeSums_t *v4; // eax

  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
  if ( _Capacity == 0 )
    return 0;
  if ( _Capacity > 0x7FFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  v4 = std::allocator<TimeSums_t>::allocate(this: &this->_Alval, _Count: _Capacity);
  this->_Myend = &v4[_Capacity];
  this->_Myfirst = v4;
  this->_Mylast = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013380
// Name: protected: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>> std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Insert(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0xFFFFFFE )
  {
    operator delete(p: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  this->_Mysize = Mysize + 1;
  v6 = _Newnode;
  _Newnode->_Parent = _Wherenode;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead )
  {
    Myhead->_Parent = _Newnode;
    this->_Myhead->_Left = _Newnode;
    this->_Myhead->_Right = _Newnode;
  }
  else if ( _Addleft )
  {
    _Wherenode->_Left = _Newnode;
    v8 = this->_Myhead;
    if ( _Wherenode == v8->_Left )
      v8->_Left = _Newnode;
  }
  else
  {
    _Wherenode->_Right = _Newnode;
    v9 = this->_Myhead;
    if ( _Wherenode == v9->_Right )
      v9->_Right = _Newnode;
  }
  v10 = _Newnode;
  while ( v10->_Parent->_Color == 0 )
  {
    Parent = v10->_Parent;
    v12 = Parent->_Parent;
    if ( Parent == v12->_Left )
    {
      Right = v12->_Right;
      if ( Right->_Color != 0 )
      {
        if ( v10 == Parent->_Right )
        {
          v10 = v10->_Parent;
          v14 = Parent->_Right;
          v10->_Right = v14->_Left;
          if ( v14->_Left->_Isnil == 0 )
            v14->_Left->_Parent = v10;
          v14->_Parent = v10->_Parent;
          v15 = this->_Myhead;
          if ( v10 == v15->_Parent )
          {
            v15->_Parent = v14;
          }
          else
          {
            v16 = v10->_Parent;
            if ( v10 == v16->_Left )
              v16->_Left = v14;
            else
              v16->_Right = v14;
          }
          v14->_Left = v10;
          v10->_Parent = v14;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Left;
        v17->_Left = v17->_Left->_Right;
        v19 = Left->_Right;
        if ( v19->_Isnil == 0 )
          v19->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v20 = this->_Myhead;
        if ( v17 == v20->_Parent )
        {
          v20->_Parent = Left;
          Left->_Right = v17;
        }
        else
        {
          v21 = v17->_Parent;
          if ( v17 == v21->_Right )
            v21->_Right = Left;
          else
            v21->_Left = Left;
          Left->_Right = v17;
        }
LABEL_50:
        v6 = _Newnode;
        v17->_Parent = Left;
        continue;
      }
      Parent->_Color = 1;
      Right->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    else
    {
      v22 = v12->_Left;
      if ( v22->_Color != 0 )
      {
        if ( v10 == Parent->_Left )
        {
          v10 = v10->_Parent;
          v23 = Parent->_Left;
          v10->_Left = v23->_Right;
          v24 = v23->_Right;
          if ( v24->_Isnil == 0 )
            v24->_Parent = v10;
          v23->_Parent = v10->_Parent;
          v25 = this->_Myhead;
          if ( v10 == v25->_Parent )
          {
            v25->_Parent = v23;
          }
          else
          {
            v26 = v10->_Parent;
            if ( v10 == v26->_Right )
              v26->_Right = v23;
            else
              v26->_Left = v23;
          }
          v23->_Right = v10;
          v10->_Parent = v23;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Right;
        v17->_Right = Left->_Left;
        if ( Left->_Left->_Isnil == 0 )
          Left->_Left->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v27 = this->_Myhead;
        if ( v17 == v27->_Parent )
        {
          v27->_Parent = Left;
        }
        else
        {
          v28 = v17->_Parent;
          if ( v17 == v28->_Left )
            v28->_Left = Left;
          else
            v28->_Right = Left;
        }
        Left->_Left = v17;
        goto LABEL_50;
      }
      Parent->_Color = 1;
      v22->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
  }
  v29 = this->_Myhead->_Parent;
  result->_Ptr = v6;
  v29->_Color = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100135B0
// Name: protected: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>> std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Insert(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x1FFFFFFE )
  {
    operator delete(p: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  this->_Mysize = Mysize + 1;
  v6 = _Newnode;
  _Newnode->_Parent = _Wherenode;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead )
  {
    Myhead->_Parent = _Newnode;
    this->_Myhead->_Left = _Newnode;
    this->_Myhead->_Right = _Newnode;
  }
  else if ( _Addleft )
  {
    _Wherenode->_Left = _Newnode;
    v8 = this->_Myhead;
    if ( _Wherenode == v8->_Left )
      v8->_Left = _Newnode;
  }
  else
  {
    _Wherenode->_Right = _Newnode;
    v9 = this->_Myhead;
    if ( _Wherenode == v9->_Right )
      v9->_Right = _Newnode;
  }
  v10 = _Newnode;
  while ( v10->_Parent->_Color == 0 )
  {
    Parent = v10->_Parent;
    v12 = Parent->_Parent;
    if ( Parent == v12->_Left )
    {
      Right = v12->_Right;
      if ( Right->_Color != 0 )
      {
        if ( v10 == Parent->_Right )
        {
          v10 = v10->_Parent;
          v14 = Parent->_Right;
          v10->_Right = v14->_Left;
          if ( v14->_Left->_Isnil == 0 )
            v14->_Left->_Parent = v10;
          v14->_Parent = v10->_Parent;
          v15 = this->_Myhead;
          if ( v10 == v15->_Parent )
          {
            v15->_Parent = v14;
          }
          else
          {
            v16 = v10->_Parent;
            if ( v10 == v16->_Left )
              v16->_Left = v14;
            else
              v16->_Right = v14;
          }
          v14->_Left = v10;
          v10->_Parent = v14;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Left;
        v17->_Left = v17->_Left->_Right;
        v19 = Left->_Right;
        if ( v19->_Isnil == 0 )
          v19->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v20 = this->_Myhead;
        if ( v17 == v20->_Parent )
        {
          v20->_Parent = Left;
          Left->_Right = v17;
        }
        else
        {
          v21 = v17->_Parent;
          if ( v17 == v21->_Right )
            v21->_Right = Left;
          else
            v21->_Left = Left;
          Left->_Right = v17;
        }
LABEL_50:
        v6 = _Newnode;
        v17->_Parent = Left;
        continue;
      }
      Parent->_Color = 1;
      Right->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    else
    {
      v22 = v12->_Left;
      if ( v22->_Color != 0 )
      {
        if ( v10 == Parent->_Left )
        {
          v10 = v10->_Parent;
          v23 = Parent->_Left;
          v10->_Left = v23->_Right;
          v24 = v23->_Right;
          if ( v24->_Isnil == 0 )
            v24->_Parent = v10;
          v23->_Parent = v10->_Parent;
          v25 = this->_Myhead;
          if ( v10 == v25->_Parent )
          {
            v25->_Parent = v23;
          }
          else
          {
            v26 = v10->_Parent;
            if ( v10 == v26->_Right )
              v26->_Right = v23;
            else
              v26->_Left = v23;
          }
          v23->_Right = v10;
          v10->_Parent = v23;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Right;
        v17->_Right = Left->_Left;
        if ( Left->_Left->_Isnil == 0 )
          Left->_Left->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v27 = this->_Myhead;
        if ( v17 == v27->_Parent )
        {
          v27->_Parent = Left;
        }
        else
        {
          v28 = v17->_Parent;
          if ( v17 == v28->_Left )
            v28->_Left = Left;
          else
            v28->_Right = Left;
        }
        Left->_Left = v17;
        goto LABEL_50;
      }
      Parent->_Color = 1;
      v22->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
  }
  v29 = this->_Myhead->_Parent;
  result->_Ptr = v6;
  v29->_Color = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100137E0
// Name: void std::_Make_heap<struct TimeSums_t __near *,int,struct TimeSums_t,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &),int __near *,struct TimeSums_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        TimeSums_t *_First,
        TimeSums_t *_Last,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  TimeSums_t *i; // edx
  __int64 v8; // xmm0_8
  TimeSums_t *v9; // edx
  int v10; // eax
  int v11; // esi
  long double peak; // xmm0_8
  int v13; // ebx
  bool v14; // zf
  TimeSums_t *v15; // eax
  TimeSums_t *v16; // ecx
  TimeSums_t *v17; // edx
  TimeSums_t *v18; // ebx
  TimeSums_t _Val; // [esp+4h] [ebp-28h] BYREF
  int v20; // [esp+24h] [ebp-8h]
  TimeSums_t *v21; // [esp+28h] [ebp-4h]
  int _Hole; // [esp+34h] [ebp+8h]
  int _Bottom; // [esp+38h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v21 )
    {
      v8 = *(_QWORD *)&i[-1].pszProfileScope;
      v9 = i - 1;
      *(_QWORD *)&_Val.pszProfileScope = v8;
      _Val.time = v9->time;
      v10 = v5 - 1;
      v11 = v6 - 2;
      _Val.timeLessChildren = v9->timeLessChildren;
      peak = v9->peak;
      _Hole = v10;
      v21 = v9;
      v20 = v11;
      _Val.peak = peak;
      v13 = v10;
      v14 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v11], a2: &_First[v11 - 1]) )
            --v11;
          v15 = &_First[v11];
          v16 = &_First[v13];
          *(_QWORD *)&v16->pszProfileScope = *(_QWORD *)&v15->pszProfileScope;
          v16->time = v15->time;
          v13 = v11;
          v16->timeLessChildren = v15->timeLessChildren;
          v11 = 2 * v11 + 2;
          v16->peak = v15->peak;
        }
        while ( v11 < _Bottom );
        v4 = _Bottom;
        v10 = _Hole;
        v14 = v11 == _Bottom;
      }
      if ( v14 )
      {
        v17 = &_First[v4 - 1];
        v18 = &_First[v13];
        *(_QWORD *)&v18->pszProfileScope = *(_QWORD *)&v17->pszProfileScope;
        v18->time = v17->time;
        v18->timeLessChildren = v17->timeLessChildren;
        v18->peak = v17->peak;
        v13 = v4 - 1;
      }
      std::_Push_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        _First,
        _Hole: v13,
        _Top: v10,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013920
// Name: void std::_Insertion_sort1<struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &),struct TimeSums_t>(struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &),struct TimeSums_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Insertion_sort1<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &),TimeSums_t>(
        TimeSums_t *_First,
        TimeSums_t *_Last,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  TimeSums_t *v3; // esi
  TimeSums_t *v4; // ebx
  TimeSums_t *v5; // edi
  TimeSums_t *i; // esi
  TimeSums_t _Val; // [esp+4h] [ebp-24h] BYREF
  TimeSums_t *v8; // [esp+24h] [ebp-4h]

  v3 = _First;
  if ( _First != _Last )
  {
    v4 = _First + 1;
    if ( &_First[1] != _Last )
    {
      v8 = _First;
      do
      {
        _Val = *v4;
        v5 = v4;
        if ( _Pred(a1: &_Val, a2: v3) )
        {
          std::_Move_backward<TimeSums_t *,TimeSums_t *>(_First: v3, _Last: v4, _Dest: v8 + 2);
          *v3 = _Val;
        }
        else
        {
          for ( i = v8; _Pred(a1: &_Val, a2: i); --i )
          {
            *(_QWORD *)&v5->pszProfileScope = *(_QWORD *)&i->pszProfileScope;
            v5->time = i->time;
            v5->timeLessChildren = i->timeLessChildren;
            v5->peak = i->peak;
            v5 = i;
          }
          v3 = _First;
          *v5 = _Val;
        }
        ++v8;
        ++v4;
      }
      while ( v4 != _Last );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013A60
// Name: void std::_Med3<struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Med3<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        TimeSums_t *_First,
        TimeSums_t *_Mid,
        TimeSums_t *_Last,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  __int64 v4; // xmm0_8
  long double time; // xmm1_8
  long double timeLessChildren; // xmm2_8
  long double peak; // xmm3_8
  __int64 v8; // xmm0_8
  long double v9; // xmm1_8
  long double v10; // xmm2_8
  long double v11; // xmm3_8
  __int64 v12; // xmm0_8
  long double v13; // xmm1_8
  long double v14; // xmm2_8
  long double v15; // xmm3_8

  if ( _Pred(a1: _Mid, a2: _First) )
  {
    v4 = *(_QWORD *)&_Mid->pszProfileScope;
    time = _Mid->time;
    timeLessChildren = _Mid->timeLessChildren;
    peak = _Mid->peak;
    *_Mid = *_First;
    *(_QWORD *)&_First->pszProfileScope = v4;
    _First->time = time;
    _First->timeLessChildren = timeLessChildren;
    _First->peak = peak;
  }
  if ( _Pred(a1: _Last, a2: _Mid) )
  {
    v8 = *(_QWORD *)&_Last->pszProfileScope;
    v9 = _Last->time;
    v10 = _Last->timeLessChildren;
    v11 = _Last->peak;
    *_Last = *_Mid;
    *(_QWORD *)&_Mid->pszProfileScope = v8;
    _Mid->time = v9;
    _Mid->timeLessChildren = v10;
    _Mid->peak = v11;
  }
  if ( _Pred(a1: _Mid, a2: _First) )
  {
    v12 = *(_QWORD *)&_Mid->pszProfileScope;
    v13 = _Mid->time;
    v14 = _Mid->timeLessChildren;
    v15 = _Mid->peak;
    *_Mid = *_First;
    *(_QWORD *)&_First->pszProfileScope = v12;
    _First->time = v13;
    _First->timeLessChildren = v14;
    _First->peak = v15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013B80
// Name: protected: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Erase(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v2; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *i; // esi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    operator delete(p: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013BC0
// Name: protected: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Erase(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v2; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *i; // esi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    operator delete(p: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100140A0
// Name: public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>>,bool> std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > >,bool> *__thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Linsert(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > >,bool> *result,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Node,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > _Leftish)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v4; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v8; // esi
  bool v9; // cl
  CVProfNode *first; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Ptr; // edi
  bool _Addleft; // [esp+Ch] [ebp-4h]

  v4 = _Node;
  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v8 = Myhead;
  v9 = true;
  _Addleft = true;
  if ( Parent->_Isnil == 0 )
  {
    first = _Node->_Myval.first;
    do
    {
      v8 = Parent;
      if ( LOBYTE(_Leftish._Ptr) != 0 )
        v9 = Parent->_Myval.first >= first;
      else
        v9 = first < Parent->_Myval.first;
      _Addleft = v9;
      if ( v9 )
        Parent = Parent->_Left;
      else
        Parent = Parent->_Right;
    }
    while ( Parent->_Isnil == 0 );
  }
  Ptr = v8;
  _Leftish._Ptr = v8;
  if ( v9 )
  {
    if ( v8 == this->_Myhead->_Left )
    {
      result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > >)std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Insert(this, result: &_Leftish, _Addleft: true, _Wherenode: v8, _Newnode: _Node)->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    Ptr = _Leftish._Ptr;
    v4 = _Node;
  }
  if ( Ptr->_Myval.first >= v4->_Myval.first )
  {
    operator delete(p: v4);
    result->first._Ptr = Ptr;
    result->second = false;
  }
  else
  {
    result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > >)std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Insert(this, result: &_Leftish, _Addleft, _Wherenode: v8, _Newnode: v4)->_Ptr;
    result->second = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014180
// Name: public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>>,bool> std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > >,bool> *__thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Linsert(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > >,bool> *result,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Node,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > _Leftish)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v4; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v8; // esi
  bool v9; // cl
  const char *first; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Ptr; // edi
  bool _Addleft; // [esp+Ch] [ebp-4h]

  v4 = _Node;
  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v8 = Myhead;
  v9 = true;
  _Addleft = true;
  if ( Parent->_Isnil == 0 )
  {
    first = _Node->_Myval.first;
    do
    {
      v8 = Parent;
      if ( LOBYTE(_Leftish._Ptr) != 0 )
        v9 = Parent->_Myval.first >= first;
      else
        v9 = first < Parent->_Myval.first;
      _Addleft = v9;
      if ( v9 )
        Parent = Parent->_Left;
      else
        Parent = Parent->_Right;
    }
    while ( Parent->_Isnil == 0 );
  }
  Ptr = v8;
  _Leftish._Ptr = v8;
  if ( v9 )
  {
    if ( v8 == this->_Myhead->_Left )
    {
      result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > >)std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Insert(this, result: &_Leftish, _Addleft: true, _Wherenode: v8, _Newnode: _Node)->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    Ptr = _Leftish._Ptr;
    v4 = _Node;
  }
  if ( Ptr->_Myval.first >= v4->_Myval.first )
  {
    operator delete(p: v4);
    result->first._Ptr = Ptr;
    result->second = false;
  }
  else
  {
    result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > >)std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Insert(this, result: &_Leftish, _Addleft, _Wherenode: v8, _Newnode: v4)->_Ptr;
    result->second = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014260
// Name: void std::_Cons_val<class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,struct std::pair<class CVProfNode __near * const,double>,struct std::pair<class CVProfNode __near *,double>>(class std::allocator<struct std::pair<class CVProfNode __near * const,double>> __near &,struct std::pair<class CVProfNode __near * const,double> __near *,struct std::pair<class CVProfNode __near *,double> __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::pair<CVProfNode * const,double>>,std::pair<CVProfNode * const,double>,std::pair<CVProfNode *,double>>(
        std::allocator<std::pair<CVProfNode * const,double> > *_Alval,
        std::pair<CVProfNode * const,double> *_Pdest,
        std::pair<CVProfNode *,double> *_Src)
{
  if ( _Pdest != nullptr )
    *_Pdest = *(std::pair<CVProfNode * const,double> *)_Src;
}

//------------------------------------------------------------------------------
// Address: 0x10014280
// Name: void std::_Cons_val<class std::allocator<struct std::pair<char const __near * const,unsigned int>>,struct std::pair<char const __near * const,unsigned int>,struct std::pair<char const __near *,unsigned int>>(class std::allocator<struct std::pair<char const __near * const,unsigned int>> __near &,struct std::pair<char const __near * const,unsigned int> __near *,struct std::pair<char const __near *,unsigned int> __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::pair<char const * const,unsigned int>>,std::pair<char const * const,unsigned int>,std::pair<char const *,unsigned int>>(
        std::allocator<std::pair<char const * const,unsigned int> > *_Alval,
        std::pair<char const * const,unsigned int> *_Pdest,
        std::pair<char const *,unsigned int> *_Src)
{
  if ( _Pdest != nullptr )
    *_Pdest = *(std::pair<char const * const,unsigned int> *)_Src;
}

//------------------------------------------------------------------------------
// Address: 0x100142A0
// Name: struct TimeSums_t __near * std::_Uninit_copy<struct TimeSums_t __near *,struct TimeSums_t __near *,class std::allocator<struct TimeSums_t>>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *,class std::allocator<struct TimeSums_t> __near &,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
TimeSums_t *__cdecl std::_Uninit_copy<TimeSums_t *,TimeSums_t *,std::allocator<TimeSums_t>>(
        TimeSums_t *_First,
        TimeSums_t *_Last,
        TimeSums_t *_Dest,
        std::allocator<TimeSums_t> *_Al)
{
  _DWORD v7[7]; // [esp+0h] [ebp-1Ch] BYREF

  v7[3] = v7;
  v7[6] = 0;
  while ( _First != _Last )
    std::_Cons_val<std::allocator<TimeSums_t>,TimeSums_t,TimeSums_t>(_Alval: _Al, _Pdest: _Dest++, _Src: _First++);
  return _Dest;
}

//------------------------------------------------------------------------------
// Address: 0x10014320
// Name: void std::_Median<struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Median<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        TimeSums_t *_First,
        TimeSums_t *_Mid,
        TimeSums_t *_Last,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  TimeSums_t *v9; // [esp-10h] [ebp-14h]
  TimeSums_t *_Firsta; // [esp+Ch] [ebp+8h]

  v4 = _Last - _First;
  if ( v4 <= 40 )
  {
    std::_Med3<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(_First, _Mid, _Last, _Pred);
  }
  else
  {
    v5 = (v4 + 1) / 8;
    v6 = v5;
    v5 <<= 6;
    v7 = v6 * 32;
    v9 = (TimeSums_t *)((char *)_First + v5);
    _Firsta = &_First[v6];
    std::_Med3<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
      _First,
      _Mid: _Firsta,
      _Last: v9,
      _Pred);
    std::_Med3<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
      _First: (TimeSums_t *)((char *)_Mid - v7),
      _Mid,
      _Last: (TimeSums_t *)((char *)_Mid + v7),
      _Pred);
    std::_Med3<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
      _First: (TimeSums_t *)((char *)_Last - v5),
      _Mid: (TimeSums_t *)((char *)_Last - v7),
      _Last,
      _Pred);
    std::_Med3<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
      _First: _Firsta,
      _Mid,
      _Last: (TimeSums_t *)((char *)_Last - v7),
      _Pred);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100143C0
// Name: public: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::clear(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Parent; // ebx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *i; // esi

  Parent = this->_Myhead->_Parent;
  for ( i = Parent; i->_Isnil == 0; Parent = i )
  {
    std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    operator delete(p: Parent);
  }
  this->_Myhead->_Parent = this->_Myhead;
  this->_Myhead->_Left = this->_Myhead;
  this->_Myhead->_Right = this->_Myhead;
  this->_Mysize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014410
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>> std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::find(class CVProfNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::find(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > *result,
        CVProfNode *const *_Keyval)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Parent; // eax

  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  while ( Parent->_Isnil == 0 )
  {
    if ( Parent->_Myval.first >= *_Keyval )
    {
      Myhead = Parent;
      Parent = Parent->_Left;
    }
    else
    {
      Parent = Parent->_Right;
    }
  }
  if ( Myhead == this->_Myhead || *_Keyval < Myhead->_Myval.first )
  {
    result->_Ptr = this->_Myhead;
    return result;
  }
  else
  {
    result->_Ptr = Myhead;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014480
// Name: public: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::clear(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Parent; // ebx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *i; // esi

  Parent = this->_Myhead->_Parent;
  for ( i = Parent; i->_Isnil == 0; Parent = i )
  {
    std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    operator delete(p: Parent);
  }
  this->_Myhead->_Parent = this->_Myhead;
  this->_Myhead->_Left = this->_Myhead;
  this->_Myhead->_Right = this->_Myhead;
  this->_Mysize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100144D0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>> std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::find(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::find(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *result,
        const char *const *_Keyval)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Parent; // eax

  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  while ( Parent->_Isnil == 0 )
  {
    if ( Parent->_Myval.first >= *_Keyval )
    {
      Myhead = Parent;
      Parent = Parent->_Left;
    }
    else
    {
      Parent = Parent->_Right;
    }
  }
  if ( Myhead == this->_Myhead || *_Keyval < Myhead->_Myval.first )
  {
    result->_Ptr = this->_Myhead;
    return result;
  }
  else
  {
    result->_Ptr = Myhead;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014680
// Name: public: struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Buynode<struct std::pair<class CVProfNode __near *,double>>(struct std::pair<class CVProfNode __near *,double> __near &&)
// Source: json
//------------------------------------------------------------------------------
std::pair<CVProfNode * const,double> *__thiscall std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode<std::pair<CVProfNode *,double>>(
        std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::pair<CVProfNode *,double> *_Val)
{
  std::pair<CVProfNode * const,double> *v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *p; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::pair<CVProfNode * const,double> *)operator new(size: 0x28u);
  p = v3;
  if ( v3 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  v3->first = (CVProfNode *const)this->_Myhead;
  *((_DWORD *)&v3->first + 1) = this->_Myhead;
  LODWORD(v3->second) = this->_Myhead;
  LOWORD(v3[2].first) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<std::pair<CVProfNode * const,double>>,std::pair<CVProfNode * const,double>,std::pair<CVProfNode *,double>>(
    _Alval: &this->_Alval,
    _Pdest: v3 + 1,
    _Src: _Val);
  v9 = -1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10014740
// Name: public: struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Buynode<struct std::pair<char const __near *,unsigned int>>(struct std::pair<char const __near *,unsigned int> __near &&)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *__thiscall std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Buynode<std::pair<char const *,unsigned int>>(
        std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::pair<char const *,unsigned int> *_Val)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *p; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node **)operator new(size: 0x18u);
  p = v3;
  if ( v3 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *v3 = this->_Myhead;
  v3[1] = this->_Myhead;
  v3[2] = this->_Myhead;
  *((_WORD *)v3 + 10) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<std::pair<char const * const,unsigned int>>,std::pair<char const * const,unsigned int>,std::pair<char const *,unsigned int>>(
    _Alval: &this->_Alval,
    _Pdest: (std::pair<char const * const,unsigned int> *)(v3 + 3),
    _Src: _Val);
  v9 = -1;
  return (std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10014800
// Name: struct std::pair<struct TimeSums_t __near *,struct TimeSums_t __near *> std::_Unguarded_partition<struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
std::pair<TimeSums_t *,TimeSums_t *> *__cdecl std::_Unguarded_partition<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        std::pair<TimeSums_t *,TimeSums_t *> *result,
        TimeSums_t *_First,
        TimeSums_t *_Last,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  TimeSums_t *v4; // esi
  unsigned int v5; // ebx
  unsigned int v6; // edi
  TimeSums_t *v7; // edx
  unsigned int v8; // edi
  __int64 v9; // xmm0_8
  __int64 v10; // xmm1_8
  __int64 v11; // xmm2_8
  __int64 v12; // xmm3_8
  bool v13; // zf
  TimeSums_t *v14; // ebx
  __int64 v15; // xmm0_8
  long double time; // xmm1_8
  long double timeLessChildren; // xmm2_8
  long double peak; // xmm3_8
  __int64 v19; // xmm0_8
  long double v20; // xmm1_8
  long double v21; // xmm2_8
  long double v22; // xmm3_8
  unsigned int v23; // eax
  __int64 v24; // xmm0_8
  long double v25; // xmm1_8
  long double v26; // xmm2_8
  long double v27; // xmm3_8
  __int64 v28; // xmm0_8
  long double v29; // xmm1_8
  long double v30; // xmm2_8
  long double v31; // xmm3_8
  __int64 v32; // xmm4_8
  __int64 v33; // xmm0_8
  long double v34; // xmm1_8
  long double v35; // xmm2_8
  long double v36; // xmm3_8
  __int64 v37; // xmm0_8
  long double v38; // xmm1_8
  long double v39; // xmm2_8
  long double v40; // xmm3_8
  TimeSums_t *_Glast; // [esp+Ch] [ebp-8h]
  TimeSums_t *_Plast; // [esp+10h] [ebp-4h]

  v4 = &_First[(_Last - _First) / 2];
  std::_Median<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
    _First,
    _Mid: v4,
    _Last: _Last - 1,
    _Pred);
  v5 = (unsigned int)&v4[1];
  _Plast = v4 + 1;
  if ( _First < v4 )
  {
    do
    {
      v6 = (unsigned int)&v4[-1];
      if ( _Pred(a1: v4 - 1, a2: v4) )
        break;
      if ( _Pred(a1: v4, a2: v4 - 1) )
        break;
      --v4;
    }
    while ( (unsigned int)_First < v6 );
  }
  if ( v5 < (unsigned int)_Last )
  {
    do
    {
      if ( _Pred(a1: (const TimeSums_t *)v5, a2: v4) )
        break;
      if ( _Pred(a1: v4, a2: (const TimeSums_t *)v5) )
        break;
      v5 += 32;
    }
    while ( v5 < (unsigned int)_Last );
    _Plast = (TimeSums_t *)v5;
  }
  v7 = v4;
  v8 = v5;
  _Glast = v4;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v8 < (unsigned int)_Last )
      {
        do
        {
          if ( !_Pred(a1: v4, a2: (const TimeSums_t *)v8) )
          {
            if ( _Pred(a1: (const TimeSums_t *)v8, a2: v4) )
              break;
            v9 = *(_QWORD *)v5;
            v10 = *(_QWORD *)(v5 + 8);
            v11 = *(_QWORD *)(v5 + 16);
            v12 = *(_QWORD *)(v5 + 24);
            *(_QWORD *)v5 = *(_QWORD *)v8;
            *(_QWORD *)(v5 + 8) = *(_QWORD *)(v8 + 8);
            *(_QWORD *)(v5 + 16) = *(_QWORD *)(v8 + 16);
            *(_QWORD *)(v5 + 24) = *(_QWORD *)(v8 + 24);
            *(_QWORD *)v8 = v9;
            *(_QWORD *)(v8 + 8) = v10;
            *(_QWORD *)(v8 + 16) = v11;
            v5 += 32;
            *(_QWORD *)(v8 + 24) = v12;
          }
          v8 += 32;
        }
        while ( v8 < (unsigned int)_Last );
        v7 = _Glast;
        _Plast = (TimeSums_t *)v5;
      }
      v13 = v7 == _First;
      if ( v7 > _First )
      {
        v14 = v7 - 1;
        do
        {
          if ( !_Pred(a1: v14, a2: v4) )
          {
            if ( _Pred(a1: v4, a2: v14) )
              break;
            v15 = *(_QWORD *)&v4[-1].pszProfileScope;
            time = v4[-1].time;
            timeLessChildren = v4[-1].timeLessChildren;
            peak = v4[-1].peak;
            --v4;
            *(_QWORD *)&v4->pszProfileScope = *(_QWORD *)&v14->pszProfileScope;
            v4->time = v14->time;
            v4->timeLessChildren = v14->timeLessChildren;
            v4->peak = v14->peak;
            *(_QWORD *)&v14->pszProfileScope = v15;
            v14->time = time;
            v14->timeLessChildren = timeLessChildren;
            v14->peak = peak;
          }
          --v14;
          --_Glast;
        }
        while ( _First < _Glast );
        v7 = _Glast;
        v5 = (unsigned int)_Plast;
        v13 = _Glast == _First;
      }
      if ( v13 )
        break;
      _Glast = --v7;
      if ( (TimeSums_t *)v8 == _Last )
      {
        if ( v7 != --v4 )
        {
          v28 = *(_QWORD *)&v7->pszProfileScope;
          v29 = v7->time;
          v30 = v7->timeLessChildren;
          v31 = v7->peak;
          *(_QWORD *)&v7->pszProfileScope = *(_QWORD *)&v4->pszProfileScope;
          v7->time = v4->time;
          v7->timeLessChildren = v4->timeLessChildren;
          v7->peak = v4->peak;
          *(_QWORD *)&v4->pszProfileScope = v28;
          v4->time = v29;
          v4->timeLessChildren = v30;
          v4->peak = v31;
        }
        v32 = *(_QWORD *)(v5 - 32);
        v33 = *(_QWORD *)&v4->pszProfileScope;
        v34 = v4->time;
        v35 = v4->timeLessChildren;
        v36 = v4->peak;
        v5 -= 32;
        *(_QWORD *)&v4->pszProfileScope = v32;
        v4->time = *(long double *)(v5 + 8);
        v4->timeLessChildren = *(long double *)(v5 + 16);
        v4->peak = *(long double *)(v5 + 24);
        *(_QWORD *)v5 = v33;
        *(long double *)(v5 + 8) = v34;
        *(long double *)(v5 + 16) = v35;
        _Plast = (TimeSums_t *)v5;
        *(long double *)(v5 + 24) = v36;
      }
      else
      {
        v37 = *(_QWORD *)v8;
        v38 = *(double *)(v8 + 8);
        v39 = *(double *)(v8 + 16);
        v40 = *(double *)(v8 + 24);
        *(_QWORD *)v8 = *(_QWORD *)&v7->pszProfileScope;
        *(long double *)(v8 + 8) = v7->time;
        *(long double *)(v8 + 16) = v7->timeLessChildren;
        *(long double *)(v8 + 24) = v7->peak;
        *(_QWORD *)&v7->pszProfileScope = v37;
        v7->time = v38;
        v7->timeLessChildren = v39;
        v7->peak = v40;
        v8 += 32;
      }
    }
    if ( (TimeSums_t *)v8 == _Last )
      break;
    if ( v5 != v8 )
    {
      v19 = *(_QWORD *)&v4->pszProfileScope;
      v20 = v4->time;
      v21 = v4->timeLessChildren;
      v22 = v4->peak;
      *(_QWORD *)&v4->pszProfileScope = *(_QWORD *)v5;
      v4->time = *(long double *)(v5 + 8);
      v4->timeLessChildren = *(long double *)(v5 + 16);
      v4->peak = *(long double *)(v5 + 24);
      *(_QWORD *)v5 = v19;
      *(long double *)(v5 + 8) = v20;
      *(long double *)(v5 + 16) = v21;
      *(long double *)(v5 + 24) = v22;
    }
    v23 = v8;
    v24 = *(_QWORD *)&v4->pszProfileScope;
    v25 = v4->time;
    v26 = v4->timeLessChildren;
    v27 = v4->peak;
    *(_QWORD *)&v4->pszProfileScope = *(_QWORD *)v8;
    v4->time = *(long double *)(v8 + 8);
    v4->timeLessChildren = *(long double *)(v8 + 16);
    v4->peak = *(long double *)(v8 + 24);
    *(_QWORD *)v8 = v24;
    v5 += 32;
    *(long double *)(v8 + 8) = v25;
    ++v4;
    *(long double *)(v8 + 16) = v26;
    _Plast = (TimeSums_t *)v5;
    v8 += 32;
    *(long double *)(v23 + 24) = v27;
  }
  result->first = v4;
  result->second = (TimeSums_t *)v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014B80
// Name: void std::_Sort_heap<struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        TimeSums_t *_First,
        TimeSums_t *_Last,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  int v3; // eax
  TimeSums_t *v4; // esi
  TimeSums_t _Val; // [esp+4h] [ebp-20h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFE0) > 32 )
  {
    v4 = _Last - 1;
    do
    {
      _Val = *v4;
      *v4 = *_First;
      std::_Adjust_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 32) >> 5,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 32;
    }
    while ( (int)(v3 & 0xFFFFFFE0) > 32 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014C30
// Name: protected: void CVProfile::DumpNodes(class CVProfNode __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::DumpNodes(CVProfile *this, CVProfNode *pNode, int indent, bool bAverageAndCountOnly)
{
  CVProfNode *v4; // esi
  CVProfile *v5; // edi
  CVProfNode *v6; // eax
  double v7; // xmm2_8
  double second; // xmm0_8
  int m_nTotalCalls; // edi
  long double TotalTime; // st7
  double v11; // xmm3_8
  long double v12; // st7
  double v13; // xmm1_8
  long double v14; // st7
  int v15; // edi
  CVProfNode *m_pChild; // eax
  double v17; // [esp+60h] [ebp-44h]
  double v18; // [esp+80h] [ebp-24h]
  double dNodeTime; // [esp+90h] [ebp-14h]
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > iterTimeLessChildren; // [esp+98h] [ebp-Ch] BYREF
  CVProfile *v21; // [esp+9Ch] [ebp-8h]
  bool fIsRoot; // [esp+A3h] [ebp-1h]

  v4 = pNode;
  v5 = this;
  v21 = this;
  if ( pNode != nullptr )
  {
    v6 = g_pStartNode;
    while ( 1 )
    {
      fIsRoot = v4 == &v5->m_Root;
      if ( v4 != &v5->m_Root && v4 != v6 )
        goto LABEL_9;
      if ( bAverageAndCountOnly )
      {
        Msg(pMsgFormat: " Avg Time/Frame (ms)\n");
        Msg(pMsgFormat: "[ func+child      func ]       Count\n");
        Msg(pMsgFormat: "  ---------- ---------      --------\n");
      }
      else
      {
        Msg(pMsgFormat: "       Sum (ms)            Avg Time/Frame (ms)     Avg Time/Call (ms)\n");
        Msg(pMsgFormat: "[ func+child      func ]  [ func+child   func ]  [ func+child   func ]    Count   Peak\n");
        Msg(pMsgFormat: "  ---------- ---------      ---------- ------      ---------- ------   -------- ------\n");
      }
      if ( !fIsRoot )
      {
LABEL_9:
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::find(
          this: &g_TimesLessChildren,
          result: &iterTimeLessChildren,
          _Keyval: &pNode);
        v7 = 0.0;
        second = 0.0;
        dNodeTime = 0.0;
        if ( iterTimeLessChildren._Ptr != g_TimesLessChildren._Myhead )
        {
          second = iterTimeLessChildren._Ptr->_Myval.second;
          dNodeTime = second;
        }
        m_nTotalCalls = v4->m_nTotalCalls;
        if ( bAverageAndCountOnly )
        {
          if ( m_nTotalCalls <= 0 )
            v18 = 0.0;
          else
            v18 = second / (double)v21->m_nFrames;
          if ( m_nTotalCalls > 0 )
          {
            TotalTime = CVProfNode::GetTotalTime(this: v4);
            v7 = TotalTime / (double)v21->m_nFrames;
          }
          Msg(pMsgFormat: "  %10.3f %9.2f      %8d", v7, v18, m_nTotalCalls);
        }
        else
        {
          pNode = (CVProfNode *)v4->m_nTotalCalls;
          if ( m_nTotalCalls <= 0 )
            v11 = 0.0;
          else
            v11 = second / (double)m_nTotalCalls;
          if ( m_nTotalCalls <= 0 )
          {
            v17 = 0.0;
          }
          else
          {
            v12 = CVProfNode::GetTotalTime(this: v4);
            second = dNodeTime;
            v7 = 0.0;
            v17 = v12 / (double)(int)pNode;
          }
          if ( m_nTotalCalls <= 0 )
            v13 = 0.0;
          else
            v13 = second / (double)v21->m_nFrames;
          if ( m_nTotalCalls > 0 )
          {
            v14 = CVProfNode::GetTotalTime(this: v4);
            second = dNodeTime;
            v7 = v14 / (double)v21->m_nFrames;
          }
          Msg(
            pMsgFormat: "  %10.3f %9.2f      %10.3f %6.2f      %10.3f %6.2f   %8d %6.2f",
            (double)(g_ClockSpeedMillisecondsMultiplier * (double)v4->m_TotalTime.m_Int64),
            second,
            v7,
            v13,
            v17,
            v11,
            m_nTotalCalls,
            (double)((double)v4->m_PeakTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier));
        }
        Msg(pMsgFormat: "  ");
        if ( indent > 1 )
        {
          v15 = indent - 1;
          do
          {
            Msg(pMsgFormat: "|  ");
            --v15;
          }
          while ( v15 != 0 );
        }
        Msg(pMsgFormat: "%s\n", v4->m_pszName);
        v5 = v21;
      }
      m_pChild = v4->m_pChild;
      if ( m_pChild != nullptr )
        CVProfile::DumpNodes(this: v5, pNode: m_pChild, indent: indent + 1, bAverageAndCountOnly);
      if ( fIsRoot )
        break;
      v6 = g_pStartNode;
      if ( v4 == g_pStartNode )
        break;
      v4 = v4->m_pSibling;
      if ( v4 == nullptr )
        break;
      pNode = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014F10
// Name: protected: struct TimeSums_t __near * std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::_Ucopy<struct TimeSums_t __near *>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *)
// Source: json
//------------------------------------------------------------------------------
TimeSums_t *__thiscall std::vector<TimeSums_t>::_Ucopy<TimeSums_t *>(
        std::vector<TimeSums_t> *this,
        TimeSums_t *_First,
        TimeSums_t *_Last,
        TimeSums_t *_Ptr)
{
  return std::_Uninit_copy<TimeSums_t *,TimeSums_t *,std::allocator<TimeSums_t>>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: &this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x10014F40
// Name: protected: struct TimeSums_t __near * std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::_Umove<struct TimeSums_t __near *>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *)
// Source: json
//------------------------------------------------------------------------------
TimeSums_t *__thiscall std::vector<TimeSums_t>::_Umove<TimeSums_t *>(
        std::vector<TimeSums_t> *this,
        TimeSums_t *_First,
        TimeSums_t *_Last,
        TimeSums_t *_Ptr)
{
  return std::_Uninit_copy<TimeSums_t *,TimeSums_t *,std::allocator<TimeSums_t>>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: &this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x10014F70
// Name: public: void std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<TimeSums_t>::reserve(std::vector<TimeSums_t> *this, unsigned int _Count)
{
  int v4; // edi
  _DWORD v5[4]; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+18h] [ebp-4h]
  TimeSums_t *_Ptr; // [esp+24h] [ebp+8h]

  v5[3] = v5;
  if ( _Count > 0x7FFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    _Ptr = std::allocator<TimeSums_t>::allocate(this: &this->_Alval, _Count);
    v6 = 0;
    std::vector<TimeSums_t>::_Umove<TimeSums_t *>(this, _First: this->_Myfirst, _Last: this->_Mylast, _Ptr);
    v6 = -1;
    v4 = (char *)this->_Mylast - (char *)this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      operator delete(p: this->_Myfirst);
    this->_Myend = &_Ptr[_Count];
    this->_Mylast = (TimeSums_t *)((char *)_Ptr + (v4 & 0xFFFFFFE0));
    this->_Myfirst = _Ptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015030
// Name: void std::_Sort<struct TimeSums_t __near *,int,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,int,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort<TimeSums_t *,int,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        TimeSums_t *_First,
        TimeSums_t *_Last,
        int _Ideal,
        bool (__cdecl *_Pred)(const TimeSums_t *, const TimeSums_t *))
{
  TimeSums_t *second; // ebx
  TimeSums_t *first; // edi
  int v6; // eax
  std::pair<TimeSums_t *,TimeSums_t *> _Mid; // [esp+Ch] [ebp-8h] BYREF

  second = _First;
  first = _Last;
  v6 = _Last - _First;
  if ( v6 <= 32 )
  {
LABEL_7:
    if ( v6 > 1 )
      std::_Insertion_sort1<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &),TimeSums_t>(
        _First: second,
        _Last: first,
        _Pred);
  }
  else
  {
    while ( _Ideal > 0 )
    {
      std::_Unguarded_partition<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        result: &_Mid,
        _First: second,
        _Last: first,
        _Pred);
      _Ideal = _Ideal / 2 / 2 + _Ideal / 2;
      if ( (int)(((char *)_Mid.first - (char *)second) & 0xFFFFFFE0) >= (int)(((char *)first - (char *)_Mid.second)
                                                                            & 0xFFFFFFE0) )
      {
        std::_Sort<TimeSums_t *,int,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
          _First: _Mid.second,
          _Last: first,
          _Ideal,
          _Pred);
        first = _Mid.first;
      }
      else
      {
        std::_Sort<TimeSums_t *,int,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
          _First: second,
          _Last: _Mid.first,
          _Ideal,
          _Pred);
        second = _Mid.second;
      }
      v6 = first - second;
      if ( v6 <= 32 )
        goto LABEL_7;
    }
    if ( (int)(((char *)first - (char *)second) & 0xFFFFFFE0) > 32 )
      std::_Make_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        _First: second,
        _Last: first,
        _Pred);
    std::_Sort_heap<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
      _First: second,
      _Last: first,
      _Pred);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015120
// Name: protected: void std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<TimeSums_t>::_Reserve(std::vector<TimeSums_t> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x7FFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x7FFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<TimeSums_t>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015190
// Name: public: class std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>> __near & std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::operator=(class std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::vector<TimeSums_t> *__thiscall std::vector<TimeSums_t>::operator=(
        std::vector<TimeSums_t> *this,
        const std::vector<TimeSums_t> *_Right)
{
  TimeSums_t *Mylast; // eax
  unsigned int v4; // ecx
  TimeSums_t *Myfirst; // edx
  unsigned int v7; // eax
  TimeSums_t *v8; // ebx

  if ( this != _Right )
  {
    Mylast = this->_Mylast;
    v4 = _Right->_Mylast - _Right->_Myfirst;
    if ( v4 != 0 )
    {
      Myfirst = this->_Myfirst;
      v7 = Mylast - this->_Myfirst;
      if ( v4 <= v7 )
      {
        std::_Copy_impl<TimeSums_t *,TimeSums_t *>(_First: _Right->_Myfirst, _Last: _Right->_Mylast, _Dest: Myfirst);
        this->_Mylast = (TimeSums_t *)((char *)this->_Myfirst
                                     + (((char *)_Right->_Mylast - (char *)_Right->_Myfirst) & 0xFFFFFFE0));
        return this;
      }
      if ( v4 <= this->_Myend - Myfirst )
      {
        v8 = &_Right->_Myfirst[v7];
        std::_Copy_impl<TimeSums_t *,TimeSums_t *>(_First: _Right->_Myfirst, _Last: v8, _Dest: Myfirst);
        this->_Mylast = std::_Uninit_copy<TimeSums_t *,TimeSums_t *,std::allocator<TimeSums_t>>(
                          _First: v8,
                          _Last: _Right->_Mylast,
                          _Dest: this->_Mylast,
                          _Al: &this->_Alval);
        return this;
      }
      if ( Myfirst != nullptr )
        operator delete(p: this->_Myfirst);
      if ( std::vector<TimeSums_t>::_Buy(this, _Capacity: _Right->_Mylast - _Right->_Myfirst) != 0 )
        this->_Mylast = std::vector<TimeSums_t>::_Ucopy<TimeSums_t *>(
                          this,
                          _First: _Right->_Myfirst,
                          _Last: _Right->_Mylast,
                          _Ptr: this->_Myfirst);
    }
    else if ( this->_Myfirst != Mylast )
    {
      this->_Mylast = std::_Copy_impl<TimeSums_t *,TimeSums_t *>(_First: Mylast, _Last: Mylast, _Dest: this->_Myfirst);
      return this;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10015290
// Name: public: void std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::push_back(struct TimeSums_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<TimeSums_t>::push_back(std::vector<TimeSums_t> *this, const TimeSums_t *_Val)
{
  const TimeSums_t *v2; // esi
  TimeSums_t *Mylast; // eax
  int v5; // esi
  TimeSums_t *v6; // eax

  v2 = _Val;
  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<TimeSums_t>::_Reserve(this, _Count: 1u);
  }
  else
  {
    v5 = (char *)_Val - (char *)this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<TimeSums_t>::_Reserve(this, _Count: 1u);
    v2 = (TimeSums_t *)((char *)this->_Myfirst + (v5 & 0xFFFFFFE0));
  }
  v6 = this->_Mylast;
  if ( v6 != nullptr )
  {
    *(_QWORD *)&v6->pszProfileScope = *(_QWORD *)&v2->pszProfileScope;
    v6->time = v2->time;
    v6->timeLessChildren = v2->timeLessChildren;
    v6->peak = v2->peak;
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x10015310
// Name: protected: void CVProfile::SumTimes(class CVProfNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::SumTimes(CVProfile *this, CVProfNode *pNode, const char *budgetGroupID)
{
  CVProfNode *v4; // edi
  int v5; // ebx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v6; // eax
  const char *m_pszName; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Ptr; // eax
  unsigned int m_nTotalCalls; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v10; // eax
  TimeSums_t *v11; // edi
  long double TotalTime; // st7
  long double v13; // xmm0_8
  CVProfNode *m_pSibling; // eax
  CVProfNode *m_pChild; // esi
  TimeSums_t timeSums; // [esp+4h] [ebp-3Ch] BYREF
  double timeLessChildren; // [esp+24h] [ebp-1Ch] BYREF
  std::pair<CVProfNode *,double> _Val; // [esp+2Ch] [ebp-14h] BYREF
  CVProfile *v19; // [esp+3Ch] [ebp-4h]
  char bSetStartNode_3; // [esp+4Bh] [ebp+Bh]

  v19 = this;
  if ( pNode != nullptr )
  {
    v4 = g_pStartNode;
    if ( g_pStartNode != nullptr || strcmp(pNode->m_pszName, g_pszSumNode) != 0 )
    {
      bSetStartNode_3 = 0;
    }
    else
    {
      v4 = pNode;
      g_pStartNode = pNode;
      bSetStartNode_3 = 1;
    }
    v5 = (int)budgetGroupID;
    if ( &v19->m_Root != pNode )
    {
      if ( v4 == nullptr )
        goto LABEL_17;
      if ( (int)pNode->m_nTotalCalls > 0
        && (budgetGroupID == (const char *)-1 || (const char *)pNode->m_BudgetGroupID == budgetGroupID) )
      {
        timeLessChildren = CVProfNode::GetTotalTimeLessChildren(this: pNode);
        _Val.second = timeLessChildren;
        _Val.first = pNode;
        v6 = std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode<std::pair<CVProfNode *,double>>(
               this: &g_TimesLessChildren,
               &_Val);
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Linsert(
          this: &g_TimesLessChildren,
          result: (std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > >,bool> *)&_Val.second,
          _Node: v6,
          _Leftish: false);
        m_pszName = pNode->m_pszName;
        budgetGroupID = pNode->m_pszName;
        Ptr = std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::find(
                this: &g_TimeSumsMap,
                result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *)&_Val.second
              + 1,
                _Keyval: &budgetGroupID)->_Ptr;
        if ( Ptr == g_TimeSumsMap._Myhead )
        {
          m_nTotalCalls = pNode->m_nTotalCalls;
          timeSums.pszProfileScope = m_pszName;
          timeSums.calls = m_nTotalCalls;
          timeSums.time = CVProfNode::GetTotalTime(this: pNode);
          timeSums.timeLessChildren = timeLessChildren;
          timeSums.peak = CVProfNode::GetPeakTime(this: pNode);
          LODWORD(_Val.second) = m_pszName;
          HIDWORD(_Val.second) = g_TimeSums._Mylast - g_TimeSums._Myfirst;
          v10 = std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Buynode<std::pair<char const *,unsigned int>>(
                  this: &g_TimeSumsMap,
                  _Val: (std::pair<char const *,unsigned int> *)&_Val.second);
          std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Linsert(
            this: &g_TimeSumsMap,
            result: (std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > >,bool> *)&timeLessChildren,
            _Node: v10,
            _Leftish: false);
          std::vector<TimeSums_t>::push_back(this: &g_TimeSums, _Val: &timeSums);
        }
        else
        {
          v11 = &g_TimeSums._Myfirst[Ptr->_Myval.second];
          v11->calls += pNode->m_nTotalCalls;
          TotalTime = CVProfNode::GetTotalTime(this: pNode);
          v13 = v11->timeLessChildren + timeLessChildren;
          v11->time = TotalTime + v11->time;
          v11->timeLessChildren = v13;
          if ( CVProfNode::GetPeakTime(this: pNode) > v11->peak )
            v11->peak = CVProfNode::GetPeakTime(this: pNode);
        }
      }
      if ( g_pStartNode == nullptr || pNode != g_pStartNode )
      {
LABEL_17:
        m_pSibling = pNode->m_pSibling;
        if ( m_pSibling != nullptr )
          CVProfile::SumTimes(this: v19, pNode: m_pSibling, budgetGroupID: v5);
      }
    }
    m_pChild = pNode->m_pChild;
    if ( m_pChild != nullptr )
      CVProfile::SumTimes(this: v19, pNode: m_pChild, budgetGroupID: v5);
    if ( bSetStartNode_3 != 0 )
      g_pStartNode = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015500
// Name: protected: void CVProfile::SumTimes(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::SumTimes(CVProfile *this, const char *pszStartNode, const char *budgetGroupID)
{
  if ( this->m_Root.m_pChild != nullptr )
  {
    if ( pszStartNode != nullptr )
      g_pStartNode = nullptr;
    else
      g_pStartNode = &this->m_Root;
    g_pszSumNode = pszStartNode;
    CVProfile::SumTimes(this, pNode: &this->m_Root, budgetGroupID);
    g_pStartNode = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015550
// Name: DumpSorted
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpSorted(
        const char *pszHeading,
        long double totalTime,
        bool (__cdecl *pfnSort)(const TimeSums_t *, const TimeSums_t *),
        unsigned int maxLen)
{
  unsigned int v4; // ebx
  TimeSums_t *Myfirst; // esi
  unsigned int v6; // edi
  long double *p_time; // esi
  double v8; // xmm2_8
  unsigned int v9; // eax
  double v10; // xmm6_8
  double v11; // xmm5_8
  double v12; // xmm4_8
  double v13; // xmm1_8
  double v14; // xmm0_8
  double v15; // [esp+40h] [ebp-30h]
  std::vector<TimeSums_t> sortedSums; // [esp+54h] [ebp-1Ch] BYREF
  double avgLessChildren; // [esp+64h] [ebp-Ch]
  float v18; // [esp+6Ch] [ebp-4h]

  v4 = 0;
  memset(&sortedSums, 0, 12);
  std::vector<TimeSums_t>::operator=(this: &sortedSums, _Right: &g_TimeSums);
  Myfirst = sortedSums._Myfirst;
  v6 = sortedSums._Mylast - sortedSums._Myfirst;
  std::_Sort<TimeSums_t *,int,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
    _First: sortedSums._Myfirst,
    _Last: sortedSums._Mylast,
    _Ideal: v6,
    _Pred: pfnSort);
  Msg(pMsgFormat: "%s\n", pszHeading);
  Msg(
    pMsgFormat: "  Scope                                                      Calls Calls/Frame  Time+Child    Pct        Time    Pct"
    "   Avg/Frame    Avg/Call Avg-NoChild        Peak\n");
  Msg(
    pMsgFormat: "  ---------------------------------------------------- ----------- ----------- ----------- ------ ----------- ------"
    " ----------- ----------- ----------- -----------\n");
  if ( v6 != 0 )
  {
    p_time = &Myfirst->time;
    do
    {
      v8 = 100.0;
      if ( v4 >= maxLen )
        break;
      v9 = *((_DWORD *)p_time - 1);
      if ( v9 != 0 )
      {
        HIDWORD(avgLessChildren) = *((_DWORD *)p_time - 1);
        avgLessChildren = *p_time / (double)v9;
        v10 = avgLessChildren;
      }
      else
      {
        v10 = 0.0;
      }
      if ( v9 != 0 )
      {
        HIDWORD(avgLessChildren) = v9;
        avgLessChildren = p_time[1] / (double)v9;
        v11 = avgLessChildren;
      }
      else
      {
        v11 = 0.0;
      }
      v12 = p_time[1];
      v13 = v12 * (1.0 / totalTime) * 100.0;
      if ( v13 >= 100.0 )
        v13 = 100.0;
      if ( 1.0 / totalTime * *p_time * 100.0 < 100.0 )
        v8 = 1.0 / totalTime * *p_time * 100.0;
      v14 = *p_time;
      v15 = p_time[2];
      v18 = (float)g_TotalFrames;
      HIDWORD(avgLessChildren) = v9;
      Msg(
        pMsgFormat: "  %52.52s%12d%12.3f%12.3f%7.2f%12.3f%7.2f%12.3f%12.3f%12.3f%12.3f\n",
        *((const char **)p_time - 2),
        v9,
        (double)v9 / (float)g_TotalFrames,
        v14,
        v8,
        v12,
        v13,
        v14 / (float)g_TotalFrames,
        v10,
        v11,
        v15);
      ++v4;
      p_time += 4;
    }
    while ( v4 < v6 );
    Myfirst = sortedSums._Myfirst;
  }
  if ( Myfirst != nullptr )
    operator delete(p: Myfirst);
}

//------------------------------------------------------------------------------
// Address: 0x10015710
// Name: public: void CVProfile::OutputReport(int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::OutputReport(
        CVProfile *this,
        __int16 type,
        const char *pszStartNode,
        const char *budgetGroupID)
{
  long double TotalTimeSampled; // st7
  long double v6; // st7
  long double PeakFrameTime; // st7
  long double v8; // st6
  double v9; // xmm0_8
  const char *m_pszName; // edi
  __int16 v11; // ax
  CVProfNode *Node; // eax
  CVProfNode *p_m_Root; // eax
  unsigned int v14; // edi
  long double v15; // st7
  long double v16; // st7
  long double v17; // st7
  long double v18; // st7
  long double v19; // st7
  long double v20; // st7
  long double v21; // [esp+Ch] [ebp-18h]
  unsigned int v22; // [esp+Ch] [ebp-18h]
  double timeAccountedFor; // [esp+1Ch] [ebp-8h]

  Msg(pMsgFormat: "******** BEGIN VPROF REPORT ********\n");
  g_TotalFrames = this->m_nFrames - 1;
  if ( g_TotalFrames <= 1 )
    g_TotalFrames = 1;
  if ( this->m_nFrames == 0 || (double)this->m_Root.m_TotalTime.m_Int64 * g_ClockSpeedMillisecondsMultiplier == 0.0 )
  {
    Msg(pMsgFormat: "No samples\n");
    goto LABEL_39;
  }
  if ( (type & 1) != 0 )
  {
    Msg(pMsgFormat: "-- Summary --\n");
    TotalTimeSampled = CVProfile::GetTotalTimeSampled(this);
    Msg(pMsgFormat: "%d frames sampled for %.2f seconds\n", g_TotalFrames, (double)(TotalTimeSampled * 0.001));
    timeAccountedFor = (double)g_TotalFrames;
    v21 = CVProfile::GetTotalTimeSampled(this) / timeAccountedFor;
    v6 = CVProfile::GetTotalTimeSampled(this);
    Msg(pMsgFormat: "Average %.2f fps, %.2f ms per frame\n", (double)(1000.0 / (v6 / timeAccountedFor)), (double)v21);
    PeakFrameTime = CVProfile::GetPeakFrameTime(this);
    Msg(pMsgFormat: "Peak %.2f ms frame\n", (double)PeakFrameTime);
    v8 = 100.0
       - CVProfNode::GetTotalTimeLessChildren(this: &this->m_Root)
       / ((double)this->m_Root.m_TotalTime.m_Int64
        * g_ClockSpeedMillisecondsMultiplier);
    if ( v8 <= 100.0 )
      v9 = v8;
    else
      v9 = 100.0;
    Msg(pMsgFormat: "%.0f pct of time accounted for\n", v9);
    Msg(pMsgFormat: "\n");
  }
  m_pszName = pszStartNode;
  if ( pszStartNode == nullptr )
    m_pszName = this->m_Root.m_pszName;
  CVProfile::SumTimes(this, pszStartNode: m_pszName, budgetGroupID);
  v11 = type;
  if ( (type & 2) != 0 )
  {
    Msg(pMsgFormat: "-- Hierarchical Call Graph --\n");
    if ( m_pszName != nullptr )
    {
      Node = CVProfile::FindNode(this, pStartNode: &this->m_Root, pszNode: m_pszName);
      g_pStartNode = Node;
      if ( Node != nullptr )
      {
LABEL_17:
        CVProfile::DumpNodes(this, pNode: Node, indent: 0, bAverageAndCountOnly: false);
        Msg(pMsgFormat: "\n");
        v11 = type;
        goto LABEL_18;
      }
    }
    else
    {
      g_pStartNode = nullptr;
    }
    Node = &this->m_Root;
    goto LABEL_17;
  }
LABEL_18:
  if ( (v11 & 4) != 0 )
  {
    Msg(pMsgFormat: "-- Hierarchical Call Graph --\n");
    if ( m_pszName != nullptr )
    {
      p_m_Root = CVProfile::FindNode(this, pStartNode: &this->m_Root, pszNode: m_pszName);
      g_pStartNode = p_m_Root;
      if ( p_m_Root != nullptr )
      {
LABEL_23:
        CVProfile::DumpNodes(this, pNode: p_m_Root, indent: 0, bAverageAndCountOnly: true);
        Msg(pMsgFormat: "\n");
        v11 = type;
        goto LABEL_24;
      }
    }
    else
    {
      g_pStartNode = nullptr;
    }
    p_m_Root = &this->m_Root;
    goto LABEL_23;
  }
LABEL_24:
  v14 = (v11 & 0x200) != 0 ? 25 : 999999;
  if ( (v11 & 8) != 0 )
  {
    v22 = (v11 & 0x200) != 0 ? 25 : 999999;
    v15 = CVProfile::GetTotalTimeSampled(this);
    DumpSorted(
      pszHeading: "-- Profile scopes sorted by time (including children) --",
      totalTime: v15,
      pfnSort: (bool (__cdecl *)(const TimeSums_t *, const TimeSums_t *))TimeCompare,
      maxLen: v22);
    Msg(pMsgFormat: "\n");
    v11 = type;
  }
  if ( (v11 & 0x10) != 0 )
  {
    v16 = CVProfile::GetTotalTimeSampled(this);
    DumpSorted(
      pszHeading: "-- Profile scopes sorted by time (without children) --",
      totalTime: v16,
      pfnSort: (bool (__cdecl *)(const TimeSums_t *, const TimeSums_t *))TimeLessChildrenCompare,
      maxLen: v14);
    Msg(pMsgFormat: "\n");
    v11 = type;
  }
  if ( (v11 & 0x20) != 0 )
  {
    v17 = CVProfile::GetTotalTimeSampled(this);
    DumpSorted(
      pszHeading: "-- Profile scopes sorted by average time (including children) --",
      totalTime: v17,
      pfnSort: (bool (__cdecl *)(const TimeSums_t *, const TimeSums_t *))AverageTimeCompare,
      maxLen: v14);
    Msg(pMsgFormat: "\n");
    v11 = type;
  }
  if ( (v11 & 0x40) != 0 )
  {
    v18 = CVProfile::GetTotalTimeSampled(this);
    DumpSorted(
      pszHeading: "-- Profile scopes sorted by average time (without children) --",
      totalTime: v18,
      pfnSort: (bool (__cdecl *)(const TimeSums_t *, const TimeSums_t *))AverageTimeLessChildrenCompare,
      maxLen: v14);
    Msg(pMsgFormat: "\n");
    v11 = type;
  }
  if ( (v11 & 0x80u) != 0 )
  {
    v19 = CVProfile::GetTotalTimeSampled(this);
    DumpSorted(
      pszHeading: "-- Profile scopes sorted by peak --",
      totalTime: v19,
      pfnSort: (bool (__cdecl *)(const TimeSums_t *, const TimeSums_t *))PeakCompare,
      maxLen: v14);
    Msg(pMsgFormat: "\n");
    v11 = type;
  }
  if ( (v11 & 0x100) != 0 )
  {
    v20 = CVProfile::GetTotalTimeSampled(this);
    DumpSorted(
      pszHeading: "-- Profile scopes sorted by peak over average (including children) --",
      totalTime: v20,
      pfnSort: (bool (__cdecl *)(const TimeSums_t *, const TimeSums_t *))PeakOverAverageCompare,
      maxLen: v14);
    Msg(pMsgFormat: "\n");
  }
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::clear(this: &g_TimesLessChildren);
  std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::clear(this: &g_TimeSumsMap);
  if ( g_TimeSums._Myfirst != g_TimeSums._Mylast )
    g_TimeSums._Mylast = std::_Copy_impl<TimeSums_t *,TimeSums_t *>(
                           _First: g_TimeSums._Mylast,
                           _Last: g_TimeSums._Mylast,
                           _Dest: g_TimeSums._Myfirst);
LABEL_39:
  Msg(pMsgFormat: "******** END VPROF REPORT ********\n");
}

//------------------------------------------------------------------------------
// Address: 0x1002AAFC
// Name: void std::_Xlength_error(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn std::_Xlength_error(const char *_Message)
{
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  std::exception::exception(this: &pExceptionObject, _What: &_Message);
  pExceptionObject.__vftable = (std::exception_vtbl *)&std::length_error::`vftable';
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI3_AVlength_error_std__);
}

//------------------------------------------------------------------------------
// Address: 0x1002AB49
// Name: void std::_Xout_of_range(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn std::_Xout_of_range(const char *_Message)
{
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  std::exception::exception(this: &pExceptionObject, _What: &_Message);
  pExceptionObject.__vftable = (std::exception_vtbl *)&std::out_of_range::`vftable';
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI3_AVout_of_range_std__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B54D
// Name: std::_dynamic_initializer_for__initlocks__
// Source: json
//------------------------------------------------------------------------------
int std::_dynamic_initializer_for__initlocks__()
{
  std::_Init_locks::_Init_locks(this: &initlocks);
  return atexit(func: std::_dynamic_atexit_destructor_for__initlocks__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B832
// Name: std::_dynamic_atexit_destructor_for__initlocks__
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_dynamic_atexit_destructor_for__initlocks__()
{
  std::_Init_locks::~_Init_locks(this: &initlocks);
}

//------------------------------------------------------------------------------
// Address: 0x10013C00
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>> std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>>)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > _Where)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *v7; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *i; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
  if ( Ptr->_Left->_Isnil != 0 )
  {
    Right = Ptr->_Right;
LABEL_8:
    Parent = Ptr->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    v7 = this;
    Myhead = this->_Myhead;
    if ( Myhead->_Parent == Ptr )
    {
      Myhead->_Parent = Right;
    }
    else if ( Parent->_Left == Ptr )
    {
      Parent->_Left = Right;
    }
    else
    {
      Parent->_Right = Right;
    }
    if ( this->_Myhead->_Left == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v9 = Parent;
      }
      else
      {
        v9 = std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Min(_Pnode: Right);
        v7 = this;
      }
      v7->_Myhead->_Left = v9;
    }
    v10 = v7->_Myhead;
    if ( v10->_Right == Ptr )
    {
      if ( Right->_Isnil != 0 )
        v10->_Right = Parent;
      else
        v10->_Right = std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Max(_Pnode: Right);
    }
    goto LABEL_35;
  }
  if ( Ptr->_Right->_Isnil != 0 )
  {
    Right = Ptr->_Left;
    goto LABEL_8;
  }
  v5 = _Where._Ptr;
  Right = _Where._Ptr->_Right;
  if ( _Where._Ptr == Ptr )
    goto LABEL_8;
  Ptr->_Left->_Parent = _Where._Ptr;
  v5->_Left = Ptr->_Left;
  if ( v5 == Ptr->_Right )
  {
    Parent = v5;
  }
  else
  {
    Parent = v5->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    Parent->_Left = Right;
    v5->_Right = Ptr->_Right;
    Ptr->_Right->_Parent = v5;
  }
  v11 = this->_Myhead;
  if ( v11->_Parent == Ptr )
  {
    v11->_Parent = v5;
  }
  else
  {
    v12 = Ptr->_Parent;
    if ( v12->_Left == Ptr )
      v12->_Left = v5;
    else
      v12->_Right = v5;
  }
  v5->_Parent = Ptr->_Parent;
  Color = v5->_Color;
  v5->_Color = Ptr->_Color;
  Ptr->_Color = Color;
LABEL_35:
  if ( _Erasednode->_Color == 1 )
  {
    for ( i = this; Right != i->_Myhead->_Parent; Parent = Parent->_Parent )
    {
      if ( Right->_Color != 1 )
        break;
      Left = Parent->_Left;
      if ( Right == Parent->_Left )
      {
        Left = Parent->_Right;
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Right;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Left->_Color != 1 || Left->_Right->_Color != 1 )
        {
          if ( Left->_Right->_Color == 1 )
          {
            Left->_Left->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      else
      {
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Left;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Right->_Color != 1 || Left->_Left->_Color != 1 )
        {
          if ( Left->_Left->_Color == 1 )
          {
            Left->_Right->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      Left->_Color = 0;
LABEL_53:
      Right = Parent;
    }
    Right->_Color = 1;
  }
  operator delete(p: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013E50
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>> std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>>)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > _Where)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *v7; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *i; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
  if ( Ptr->_Left->_Isnil != 0 )
  {
    Right = Ptr->_Right;
LABEL_8:
    Parent = Ptr->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    v7 = this;
    Myhead = this->_Myhead;
    if ( Myhead->_Parent == Ptr )
    {
      Myhead->_Parent = Right;
    }
    else if ( Parent->_Left == Ptr )
    {
      Parent->_Left = Right;
    }
    else
    {
      Parent->_Right = Right;
    }
    if ( this->_Myhead->_Left == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v9 = Parent;
      }
      else
      {
        v9 = std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Min(_Pnode: Right);
        v7 = this;
      }
      v7->_Myhead->_Left = v9;
    }
    v10 = v7->_Myhead;
    if ( v10->_Right == Ptr )
    {
      if ( Right->_Isnil != 0 )
        v10->_Right = Parent;
      else
        v10->_Right = std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Max(_Pnode: Right);
    }
    goto LABEL_35;
  }
  if ( Ptr->_Right->_Isnil != 0 )
  {
    Right = Ptr->_Left;
    goto LABEL_8;
  }
  v5 = _Where._Ptr;
  Right = _Where._Ptr->_Right;
  if ( _Where._Ptr == Ptr )
    goto LABEL_8;
  Ptr->_Left->_Parent = _Where._Ptr;
  v5->_Left = Ptr->_Left;
  if ( v5 == Ptr->_Right )
  {
    Parent = v5;
  }
  else
  {
    Parent = v5->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    Parent->_Left = Right;
    v5->_Right = Ptr->_Right;
    Ptr->_Right->_Parent = v5;
  }
  v11 = this->_Myhead;
  if ( v11->_Parent == Ptr )
  {
    v11->_Parent = v5;
  }
  else
  {
    v12 = Ptr->_Parent;
    if ( v12->_Left == Ptr )
      v12->_Left = v5;
    else
      v12->_Right = v5;
  }
  v5->_Parent = Ptr->_Parent;
  Color = v5->_Color;
  v5->_Color = Ptr->_Color;
  Ptr->_Color = Color;
LABEL_35:
  if ( _Erasednode->_Color == 1 )
  {
    for ( i = this; Right != i->_Myhead->_Parent; Parent = Parent->_Parent )
    {
      if ( Right->_Color != 1 )
        break;
      Left = Parent->_Left;
      if ( Right == Parent->_Left )
      {
        Left = Parent->_Right;
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Right;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Left->_Color != 1 || Left->_Right->_Color != 1 )
        {
          if ( Left->_Right->_Color == 1 )
          {
            Left->_Left->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      else
      {
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Left;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Right->_Color != 1 || Left->_Left->_Color != 1 )
        {
          if ( Left->_Left->_Color == 1 )
          {
            Left->_Right->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      Left->_Color = 0;
LABEL_53:
      Right = Parent;
    }
    Right->_Color = 1;
  }
  operator delete(p: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014540
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>> std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>>)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > _Last)
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Ptr; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > v8; // edx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *i; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > v13; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::clear(this);
    result->_Ptr = this->_Myhead->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v8._Ptr = Ptr;
      if ( Ptr->_Isnil == 0 )
      {
        Right = Ptr->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( Ptr != i->_Right )
              break;
            Ptr = i;
          }
          _First._Ptr = i;
        }
        else
        {
          v10 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v10 = j;
          _First._Ptr = v10;
        }
      }
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::erase(
        this,
        result: &v13,
        _Where: v8);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100145E0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>> std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>>)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > _Last)
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Ptr; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > v8; // edx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *i; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > v13; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::clear(this);
    result->_Ptr = this->_Myhead->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v8._Ptr = Ptr;
      if ( Ptr->_Isnil == 0 )
      {
        Right = Ptr->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( Ptr != i->_Right )
              break;
            Ptr = i;
          }
          _First._Ptr = i;
        }
        else
        {
          v10 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v10 = j;
          _First._Ptr = v10;
        }
      }
      std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::erase(
        this,
        result: &v13,
        _Where: v8);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AB2C
// Name: public: std::length_error::length_error(class std::length_error const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::length_error *__thiscall std::length_error::length_error(std::length_error *this, const std::length_error *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::length_error_vtbl *)&std::length_error::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002AB79
// Name: public: std::out_of_range::out_of_range(class std::out_of_range const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::out_of_range *__thiscall std::out_of_range::out_of_range(std::out_of_range *this, const std::out_of_range *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::out_of_range_vtbl *)&std::out_of_range::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002ABB7
// Name: public: std::_Init_locks::_Init_locks(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Init_locks *__thiscall std::_Init_locks::_Init_locks(std::_Init_locks *this)
{
  _RTL_CRITICAL_SECTION *v2; // esi

  if ( InterlockedIncrement(lpAddend: &init) == 0 )
  {
    v2 = mtx;
    do
      _Mtxinit(_Mtx: v2++);
    while ( (int)v2 < (int)&initlocks );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002ABE8
// Name: public: std::_Init_locks::~_Init_locks(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::_Init_locks::~_Init_locks(std::_Init_locks *this)
{
  _RTL_CRITICAL_SECTION *v1; // esi

  if ( InterlockedDecrement(lpAddend: &init) < 0 )
  {
    v1 = mtx;
    do
      _Mtxdst(_Mtx: v1++);
    while ( (int)v1 < (int)&initlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AC11
// Name: public: std::_Lockit::_Lockit(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Lockit *__thiscall std::_Lockit::_Lockit(std::_Lockit *this, int kind)
{
  this->_Locktype = kind;
  if ( kind < 4 )
    _Mtxlock(_Mtx: &mtx[kind]);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002AC39
// Name: public: std::_Lockit::~_Lockit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::_Lockit::~_Lockit(std::_Lockit *this)
{
  if ( this->_Locktype < 4 )
    _Mtxunlock(_Mtx: &mtx[this->_Locktype]);
}

//------------------------------------------------------------------------------
// Address: 0x1002AC50
// Name: __Mtxinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Mtxinit(_RTL_CRITICAL_SECTION *_Mtx)
{
  InitializeCriticalSection(lpCriticalSection: _Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x1002AC60
// Name: __Mtxdst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Mtxdst(_RTL_CRITICAL_SECTION *_Mtx)
{
  DeleteCriticalSection(lpCriticalSection: _Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x1002AC70
// Name: __Mtxlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Mtxlock(_RTL_CRITICAL_SECTION *_Mtx)
{
  EnterCriticalSection(lpCriticalSection: _Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x1002AC80
// Name: __Mtxunlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Mtxunlock(_RTL_CRITICAL_SECTION *_Mtx)
{
  LeaveCriticalSection(lpCriticalSection: _Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x1002AC90
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x1002AC96
// Name: _remove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl remove(const char *path)
{
  DWORD LastError; // eax

  if ( DeleteFileA(lpFileName: path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002ACC6
// Name: _unlink
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unlink(const char *path)
{
  return remove(path);
}

//------------------------------------------------------------------------------
// Address: 0x1002AD70
// Name: _dynamic_initializer_for__g_CmdLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CmdLine__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CmdLine__);
}

//------------------------------------------------------------------------------
// Address: 0x1002AD80
// Name: _dynamic_initializer_for__LOG_LOADING__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_LOADING__()
{
  int result; // eax

  result = LoggingSystem_RegisterLoggingChannel(
             pName: "LOADING",
             registerTagsFunc: nullptr,
             flags: (LoggingChannelFlags_t)0,
             severity: LS_MESSAGE,
             color: UNSPECIFIED_LOGGING_COLOR_3);
  LOG_LOADING = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002ADB0
// Name: _dynamic_initializer_for__g_ClockSpeedInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
static void __cdecl dynamic_initializer_for__g_ClockSpeedInit__()
{
  CClockSpeedInit::Init();
}

//------------------------------------------------------------------------------
// Address: 0x1002ADC0
// Name: _dynamic_initializer_for__LOG_GENERAL__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_GENERAL__()
{
  CLoggingSystem *v0; // ecx
  Color v1; // esi
  int result; // eax

  v0 = g_pGlobalLoggingSystem;
  v1 = UNSPECIFIED_LOGGING_COLOR_5;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  result = CLoggingSystem::RegisterLoggingChannel(
             this: v0,
             pChannelName: "General",
             registerTagsFunc: nullptr,
             flags: (LoggingChannelFlags_t)0,
             severity: 0,
             spewColor: v1);
  LOG_GENERAL = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AE30
// Name: _dynamic_initializer_for__LOG_ASSERT__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_ASSERT__()
{
  CLoggingSystem *v0; // ecx
  Color v1; // esi
  int result; // eax

  v0 = g_pGlobalLoggingSystem;
  v1 = UNSPECIFIED_LOGGING_COLOR_5;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  result = CLoggingSystem::RegisterLoggingChannel(
             this: v0,
             pChannelName: "Assert",
             registerTagsFunc: nullptr,
             flags: (LoggingChannelFlags_t)0,
             severity: 0,
             spewColor: v1);
  LOG_ASSERT = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AEA0
// Name: _dynamic_initializer_for__LOG_CONSOLE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_CONSOLE__()
{
  CLoggingSystem *v0; // ecx
  Color v1; // esi
  int result; // eax

  v0 = g_pGlobalLoggingSystem;
  v1 = UNSPECIFIED_LOGGING_COLOR_5;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  result = CLoggingSystem::RegisterLoggingChannel(
             this: v0,
             pChannelName: "Console",
             registerTagsFunc: Register_LOG_CONSOLE_Tags,
             flags: LCF_CONSOLE_ONLY,
             severity: (Color)3,
             spewColor: v1);
  LOG_CONSOLE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AF10
// Name: _dynamic_initializer_for__LOG_DEVELOPER__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DEVELOPER__()
{
  CLoggingSystem *v0; // ecx
  Color v1; // esi
  int result; // eax

  v0 = g_pGlobalLoggingSystem;
  v1 = UNSPECIFIED_LOGGING_COLOR_5;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  result = CLoggingSystem::RegisterLoggingChannel(
             this: v0,
             pChannelName: "Developer",
             registerTagsFunc: Register_LOG_DEVELOPER_Tags,
             flags: LCF_CONSOLE_ONLY,
             severity: (Color)3,
             spewColor: v1);
  LOG_DEVELOPER = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AF80
// Name: _dynamic_initializer_for__LOG_DEVELOPER_CONSOLE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DEVELOPER_CONSOLE__()
{
  CLoggingSystem *v0; // ecx
  Color v1; // esi
  int result; // eax

  v0 = g_pGlobalLoggingSystem;
  v1 = UNSPECIFIED_LOGGING_COLOR_5;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  result = CLoggingSystem::RegisterLoggingChannel(
             this: v0,
             pChannelName: "DeveloperConsole",
             registerTagsFunc: Register_LOG_DEVELOPER_CONSOLE_Tags,
             flags: LCF_CONSOLE_ONLY,
             severity: (Color)3,
             spewColor: v1);
  LOG_DEVELOPER_CONSOLE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AFF0
// Name: _dynamic_initializer_for__LOG_DEVELOPER_VERBOSE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DEVELOPER_VERBOSE__()
{
  CLoggingSystem *v0; // ecx
  int result; // eax

  v0 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  result = CLoggingSystem::RegisterLoggingChannel(
             this: v0,
             pChannelName: "DeveloperVerbose",
             registerTagsFunc: Register_LOG_DEVELOPER_VERBOSE_Tags,
             flags: LCF_CONSOLE_ONLY,
             severity: (Color)3,
             spewColor: (Color)-4161344);
  LOG_DEVELOPER_VERBOSE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B060
// Name: _dynamic_initializer_for__g_nThreadLocalStateIndex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_nThreadLocalStateIndex__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &g_nThreadLocalStateIndex);
  return atexit(func: dynamic_atexit_destructor_for__g_nThreadLocalStateIndex__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B570
// Name: _dynamic_atexit_destructor_for__g_CmdLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CmdLine__()
{
  CCommandLine::~CCommandLine(this: &g_CmdLine);
}

//------------------------------------------------------------------------------
// Address: 0x1002B580
// Name: _GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__()
{
  g_bEnforceLoggingSystemSingleton = false;
  operator delete(p: stru_1003A860.m_pStateMutex);
}

//------------------------------------------------------------------------------
// Address: 0x1002B5A0
// Name: _dynamic_atexit_destructor_for__g_nThreadLocalStateIndex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_nThreadLocalStateIndex__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_nThreadLocalStateIndex);
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F00A620
// Name: public: class CVProfile __near * CVProfNode::GetProfile(void)
// Source: json
//------------------------------------------------------------------------------
struct CVProfile *__thiscall CVProfNode::GetProfile(CVProfNode *this)
{
  return *((struct CVProfile **)this + 35);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A630
// Name: public: void __near * CVProfNode::GetCurrentScope(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfNode::GetCurrentScope(CVProfNode *this)
{
  return this->m_BudgetGroupID;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A6D0
// Name: public: class CVProfNode __near * CVProfile::GetCurrentNode(void)
// Source: json
//------------------------------------------------------------------------------
struct CVProfNode *__thiscall CVProfile::GetCurrentNode(CVProfile *this)
{
  return (struct CVProfNode *)this->m_GroupIDStack[0];
}

//------------------------------------------------------------------------------
// Address: 0x3F00A6E0
// Name: public: void __near * CVProfile::GetCurrentScope(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CVProfile::GetCurrentScope(CVProfile *this)
{
  return *(void **)(this->m_GroupIDStack[0] + 124);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A6F0
// Name: public: void CVProfile::SetThreadEntry(class CVProfileThreadEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::SetThreadEntry(CVProfile *this, struct CVProfileThreadEntry *a2)
{
  this->m_GroupIDStack[651] = (int)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A700
// Name: public: char const __near * CVProfile::GetThreadName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVProfile::GetThreadName(CVProfile *this)
{
  return (const char *)&this->m_GroupIDStack[587];
}

//------------------------------------------------------------------------------
// Address: 0x3F00A750
// Name: public: CVProfile::CVProfile(class CVProfile const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::CVProfile(CVProfile *this, CValidator *a2, char *a3)
{
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  *(_DWORD *)&this->m_bVTuneGroupEnabled = a2->m_pValObjectFirst;
  LOBYTE(this->m_nVTuneGroupID) = a2->m_pValObjectLast;
  qmemcpy(this->m_GroupIDStack, &a2->m_pValObjectCur, 38);
  qmemcpy(&this->m_GroupIDStack[10], &a2->m_threadMutexValidationLock[1], 0x400u);
  qmemcpy(&this->m_GroupIDStack[266], &a2->m_threadMutexValidationLock[257], 0x100u);
  CValidator::Validate(
    this: nullptr,
    (int)a2,
    a3: this,
    a4: (int)&savedregs,
    a5: &this->m_GroupIDStack[330],
    a6: &a2->m_threadMutexValidationLock[321],
    validator: a2,
    pchName: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F00ECF0
// Name: public: void CVProfNode::EnterScope(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfNode::EnterScope(CVProfNode *this)
{
  DWORD v1; // [esp-Ch] [ebp-Ch]
  unsigned int *v2; // [esp-8h] [ebp-8h]

  hObject = CreateThread(
              lpThreadAttributes: nullptr,
              dwStackSize: 0,
              lpStartAddress: StartAddress,
              lpParameter: &hObject,
              dwCreationFlags: v1,
              lpThreadId: v2);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F020
// Name: public: void CVProfNode::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CVProfNode::Validate(CVProfNode *this@<ecx>, char _BH@<bh>, int a3@<ebp>, int _EDI@<edi>)
{
  __asm { lock add bh, [edi] }
  *(_DWORD *)(a3 - 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F170
// Name: TimeCompare
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeCompare(const TimeSums_t *lhs)
{
  if ( lhs != nullptr )
    Sleep(dwMilliseconds: (DWORD)lhs);
  else
    Sleep(dwMilliseconds: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F190
// Name: TimeLessChildrenCompare
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall TimeLessChildrenCompare()
{
  return GetCurrentProcessId();
}

//------------------------------------------------------------------------------
// Address: 0x3F00F1B0
// Name: PeakCompare
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __cdecl PeakCompare(const TimeSums_t *lhs, const TimeSums_t *rhs)
{
  HANDLE v2; // eax
  DWORD v4; // [esp-Ch] [ebp-Ch]
  BOOL v5; // [esp-8h] [ebp-8h]
  DWORD v6; // [esp-4h] [ebp-4h]

  v2 = OpenProcess(dwDesiredAccess: v4, bInheritHandle: v5, dwProcessId: v6);
  if ( v2 == nullptr )
    JUMPOUT(0x3F00F1D6);
  WaitForSingleObject(hHandle: v2, dwMilliseconds: 0);
  return AverageTimeCompare(lhs, rhs);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F1D0
// Name: AverageTimeCompare
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall AverageTimeCompare@<al>(char a1@<bl>)
{
  void *v2; // [esp-10h] [ebp-10h]

  CloseHandle(hObject: v2);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F230
// Name: AverageTimeLessChildrenCompare
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall AverageTimeLessChildrenCompare@<eax>(
        __int16 a1@<bx>,
        int a2@<ebp>,
        int (__cdecl *a3)(const char *)@<edi>)
{
  HMODULE v3; // eax
  FARPROC ProcAddress; // eax
  HMODULE v6; // eax

  HIBYTE(a1) += *(_BYTE *)a3;
  v3 = (HMODULE)a3(a1: "kernel32.dll");
  if ( v3 == nullptr
    || (ProcAddress = GetProcAddress(hModule: v3, lpProcName: (LPCSTR)&__initialmbcinfo.mbcasemap[39])) == nullptr )
  {
    v6 = (HMODULE)a3(a1: (const char *)&__initialmbcinfo.mbcasemap[55]);
    if ( v6 != nullptr && GetProcAddress(hModule: v6, lpProcName: (LPCSTR)&__initialmbcinfo.mbcasemap[67]) != nullptr )
    {
      *(_DWORD *)(a2 - 24) = 0;
      *(_DWORD *)(a2 - 20) = 0;
      *(_DWORD *)(a2 - 16) = 0;
      *(_DWORD *)(a2 - 12) = 0;
      *(_DWORD *)(a2 - 8) = 0;
      *(_DWORD *)(a2 - 4) = 0;
      JUMPOUT(0x3F00F28A);
    }
    JUMPOUT(0x3F00F29E);
  }
  return ((int (__cdecl *)(__int16))ProcAddress)(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F290
// Name: PeakOverAverageCompare
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall PeakOverAverageCompare@<eax>(int a1@<eax>, int a2@<ebp>)
{
  if ( a1 != 0 )
    return -1;
  else
    return *(_DWORD *)(a2 - 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F970
// Name: DumpSorted
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall DumpSorted(_DWORD *a1@<eax>, char a2@<ch>, _DWORD *a3@<ebx>, CThreadSyncObject *a4@<edi>)
{
  _EAX = (unsigned int)a1 + *a1;
  *((_BYTE *)&unk_3F03AFFF + _EAX - 1057206319) += a2;
  *a3 &= _EAX;
  __asm { aas }
  ((void (__cdecl *)(int, _DWORD, _DWORD))AssertMsgImplementation)(a1: _EAX, a2: 0, a3: (unsigned __int16)__SS__);
  CThreadSyncObject::Wait(this: a4, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F010210
// Name: public: CThreadLocal<int>::~CThreadLocal<int>(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CThreadLocal<int>::~CThreadLocal<int>(CThreadLocal<int> *this@<ecx>, int a2@<edi>)
{
  --*(_DWORD *)(a2 + 32);
}

//------------------------------------------------------------------------------
// Address: 0x3F010870
// Name: public: int CVProfile::GetNumBudgetGroups(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfile::GetNumBudgetGroups(CVProfile *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F010B10
// Name: public: void CVProfile::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVProfile::Validate(CVProfile *this@<ecx>, int a2@<ebx>, CValidator *validator, char *pchName)
{
  *(_BYTE *)(a2 + 79846885) += (_BYTE)this;
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  JUMPOUT(0x3F010B20);
}

//------------------------------------------------------------------------------
// Address: 0x3F010C30
// Name: public: std::map<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>>::map<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::map<CVProfNode *,double>::map<CVProfNode *,double>(
        std::map<CVProfNode *,double> *this@<ecx>,
        int a2@<ebx>,
        int a3,
        int a4,
        int a5,
        CThreadSemaphore a6,
        int a7,
        int a8,
        char a9)
{
  DWORD LastError; // eax
  char *v10; // eax
  char *v11; // eax

  LastError = GetLastError();
  v10 = sub_3F008FA0(a1: &a9, Format: (char *)&_rgcode_page_info[2].mbulinfo[4], LastError);
  v11 = sub_3F008FA0(a1: (char *)&STACK[0x122], Format: "Assertion Failed: %s", v10);
  ((void (__cdecl *)(char *, int, unsigned __int8 *, int, void *, int))AssertMsgImplementation)(
    a1: v11,
    a2,
    a3: &__initialmbcinfo.mbcasemap[107],
    a4: 2636,
    a5: &unk_3F041A7E,
    a6: a2);
  LOBYTE(STACK[0x22E]) = a2;
  CThreadSemaphore::~CThreadSemaphore(this: &a6);
  JUMPOUT(0x3F010BAB);
}

//------------------------------------------------------------------------------
// Address: 0x3F010CA0
// Name: public: std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::~_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::~_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this)
{
  JUMPOUT(0x3F010CA6);
}

//------------------------------------------------------------------------------
// Address: 0x3F010CB0
// Name: public: struct std::pair<class std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::iterator,bool> std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::insert(struct std::pair<class CVProfNode __near * const,double> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::insert(
        const std::pair<CVProfNode * const,double> *_Val@<ebx>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        int a3,
        int a4,
        CThreadSemaphore a5)
{
  LOBYTE(STACK[0x240]) = (_BYTE)_Val;
  CThreadSemaphore::~CThreadSemaphore(this: &a5);
  JUMPOUT(0x3F010BAB);
}

//------------------------------------------------------------------------------
// Address: 0x3F010D60
// Name: public: class std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::iterator std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::find(class CVProfNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::find@<eax>(
        char a1@<dh>,
        int a2@<ebp>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this)
{
  *(_BYTE *)(a2 + 9) += a1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F010DE0
// Name: public: std::map<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>>::map<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::map<char const *,unsigned int>::map<char const *,unsigned int>(
        std::map<char const *,unsigned int> *this)
{
  char *v2; // eax
  char v3[256]; // [esp+8h] [ebp-100h] BYREF

  if ( *((_DWORD *)this + 9) != 0 )
  {
    if ( CThreadLocalBase::Get(this: (CThreadLocalBase *)dwTlsIndex) == this )
    {
      v2 = sub_3F008FA0(a1: v3, Format: "Assertion Failed: %s", (const char *)_rgcode_page_info[4].rgrange);
      ((void (__cdecl *)(char *, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: v2,
        a2: 0,
        a3: &__initialmbcinfo.mbcasemap[107],
        a4: 2775,
        a5: &unk_3F041A7F,
        a6: 0);
    }
    if ( *((_DWORD *)this + 9) != 0 )
      JUMPOUT(0x3F010E4F);
    JUMPOUT(0x3F010E8E);
  }
  JUMPOUT(0x3F010E98);
}

//------------------------------------------------------------------------------
// Address: 0x3F010E50
// Name: public: std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::~_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::~_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this@<ecx>,
        int a2@<ebx>)
{
  *(_BYTE *)(a2 + 37554372) = __ROL1__(*(_BYTE *)(a2 + 37554372), 1);
  JUMPOUT(0x3F010E56);
}

//------------------------------------------------------------------------------
// Address: 0x3F010E60
// Name: public: struct std::pair<class std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::iterator,bool> std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::insert(struct std::pair<char const __near * const,unsigned int> const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::insert@<al>(
        int a1@<eax>,
        int a2@<esi>,
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this)
{
  std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator _Where; // [esp+4h] [ebp-10h]

  _Where._Ptr = *(std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node **)((char *)&_Where._Ptr + a2 + 3);
  if ( (DWORD (__stdcall **)())((char *)&GetLastError + a1) == nullptr )
    return 1;
  ((void (__cdecl *)(unsigned __int8 *, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: &__initialmbcinfo.mbcasemap[127],
    a2: 0,
    a3: &__initialmbcinfo.mbcasemap[107],
    a4: 2787,
    a5: &unk_3F041A80,
    a6: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F010F10
// Name: public: std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::~vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::vector<TimeSums_t>::~vector<TimeSums_t>(
        std::vector<TimeSums_t> *this@<ecx>,
        char a2@<sf>,
        char a3@<of>,
        _DWORD *_EAX@<eax>,
        int a5@<ebp>,
        _BYTE *a6@<edi>,
        int a7@<esi>)
{
  bool v8; // zf

  if ( a2 == a3 )
  {
    LOBYTE(_EAX) = (unsigned __int8)_EAX | 3;
    *_EAX += _EAX;
    *a6 += (_BYTE)this;
    __asm { aam     15h }
    if ( CThreadLocalBase::Get((CThreadLocalBase *)this) == (LPVOID)a7 )
    {
      v8 = (*(_BYTE *)(a7 + 84) & 1) == 0;
      *(_DWORD *)(a7 + 44) = *(_DWORD *)(a5 + 8);
      if ( v8 )
        JUMPOUT(0x3F010F37);
      JUMPOUT(0x3F010F5D);
    }
    JUMPOUT(0x3F010F70);
  }
  JUMPOUT(0x3F010F36);
}

//------------------------------------------------------------------------------
// Address: 0x3F010F40
// Name: public: class std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>> __near & std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::operator=(class std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge __noreturn std::vector<TimeSums_t>::operator=(
        std::vector<TimeSums_t> *this@<ecx>,
        int a2@<esi>,
        const std::vector<TimeSums_t> *_Right,
        int a4,
        int pExceptionObject)
{
  CThreadLocalBase::Set(this: (CThreadLocalBase *)dwTlsIndex, lpTlsValue: nullptr);
  CloseHandle(hObject: *(HANDLE *)(a2 + 36));
  *(_DWORD *)(a2 + 36) = 0;
  _CxxThrowException(&pExceptionObject, pThrowInfo: (_ThrowInfo *)&stru_3F0348D4);
}

//------------------------------------------------------------------------------
// Address: 0x3F0110C0
// Name: public: unsigned int std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::size(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0110E0
// Name: public: struct TimeSums_t __near & std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::operator[](unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge std::vector<TimeSums_t>::operator[]@<al>(std::vector<TimeSums_t> *this@<esi>, int a2@<eax>, int a3)
{
  ((void (__cdecl *)(int, _DWORD))AssertMsgImplementation)(a1: a2, a2: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F011110
// Name: public: void std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::push_back(struct TimeSums_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall std::vector<TimeSums_t>::push_back(std::vector<TimeSums_t> *this)
{
  char *v2; // ecx
  _DWORD v3[5]; // [esp+0h] [ebp-2Ch] BYREF
  const char *v4; // [esp+14h] [ebp-18h]
  _DWORD *v5; // [esp+1Ch] [ebp-10h]
  int v6; // [esp+28h] [ebp-4h]

  v5 = v3;
  v3[4] = this;
  v6 = 0;
  v4 = *(const char **)&this->_Alval.std::_Allocator_base<TimeSums_t>;
  v2 = (char *)v4;
  if ( strlen(v4 + 48) != 0 )
  {
    ThreadSetDebugName(a1: 0xFFFFFFFF, a2: (ULONG_PTR)(v4 + 48));
    v2 = (char *)v4;
  }
  CThreadLocalBase::Set(this: (CThreadLocalBase *)dwTlsIndex, lpTlsValue: v2);
  CThreadLocalBase::Get(this: (CThreadLocalBase *)dwTlsIndex);
  JUMPOUT(0x3F01118C);
}

//------------------------------------------------------------------------------
// Address: 0x3F011190
// Name: public: struct std::pair<char const __near * const,unsigned int> __near * std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::iterator::operator->(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::iterator::operator->(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator *this@<ecx>,
        int a2@<eax>,
        int a3@<ebp>,
        _DWORD *a4@<esi>)
{
  _BYTE *v4; // eax

  *(_DWORD *)(a2 + 44) = -1;
  v4 = (_BYTE *)a4[2];
  if ( v4 != nullptr )
    *v4 = 0;
  *(_BYTE *)(a3 - 4) = 1;
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*a4 + 4))(a1: *a4, a2: (unsigned __int16)__ES__);
  JUMPOUT(0x3F0111AF);
}

//------------------------------------------------------------------------------
// Address: 0x3F0111B0
// Name: protected: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Erase(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this@<ecx>,
        int _EAX@<eax>,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Rootnode)
{
  __asm { fmul    dword ptr [eax+45C7EF5Dh] }
  JUMPOUT(0x3F0111B7);
}

//------------------------------------------------------------------------------
// Address: 0x3F0111F0
// Name: protected: class std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::iterator std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *,struct std::pair<class CVProfNode __near * const,double> const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Insert(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        bool _Addleft,
        const std::pair<CVProfNode * const,double> *_Val)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0114E0
// Name: protected: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Erase(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this@<ecx>,
        int _EAX@<eax>,
        CThreadSyncObject *a3@<ebx>,
        int a4@<ebp>,
        CWorkerThread *a5@<edi>,
        _RTL_CRITICAL_SECTION *a6@<esi>,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Rootnode)
{
  void *m_hThread; // eax
  HANDLE CurrentThread; // eax
  void *retaddr; // [esp+0h] [ebp+0h] BYREF

  __asm { aas }
  STACK[0x214] = 0;
  m_hThread = a5->m_hThread;
  if ( m_hThread == nullptr
    || !GetExitCodeThread(hThread: m_hThread, lpExitCode: (LPDWORD)&retaddr)
    || retaddr != (void *)259 )
  {
    STACK[0x214] = -1;
    JUMPOUT(0x3F011518);
  }
  retaddr = nullptr;
  if ( *(_BYTE *)(a4 + 16) != 0 )
    retaddr = (void *)CWorkerThread::BoostPriority(this: a5);
  a5->m_Param = *(_DWORD *)(a4 + 8);
  CThreadEvent::Reset(this: &a5->m_EventComplete);
  CThreadSyncObject::AssertUseable(this: a3);
  SetEvent(hEvent: a3->m_hSyncObject);
  CWorkerThread::WaitForReply(
    this: a5,
    a2: *(_DWORD *)(a4 + 12),
    a3: *(unsigned int (__stdcall **)(unsigned int, void *const *, int, unsigned int))(a4 + 20));
  if ( *(_BYTE *)(a4 + 16) != 0 )
  {
    CurrentThread = a5->m_hThread;
    if ( CurrentThread == nullptr )
      CurrentThread = GetCurrentThread();
    SetThreadPriority(hThread: CurrentThread, nPriority: (int)retaddr);
  }
  STACK[0x214] = -1;
  LeaveCriticalSection(lpCriticalSection: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0117C0
// Name: protected: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Tidy(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Tidy(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this@<ecx>,
        HANDLE *a2@<esi>,
        int a3)
{
  CThreadSyncObject::AssertUseable((CThreadSyncObject *)this);
  SetEvent(hEvent: *a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F011810
// Name: public: class std::_Vector_iterator<struct TimeSums_t,class std::allocator<struct TimeSums_t>> std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::insert(class std::_Vector_iterator<struct TimeSums_t,class std::allocator<struct TimeSums_t>>,struct TimeSums_t const __near &)
// Source: json
//------------------------------------------------------------------------------
std::vector<TimeSums_t> *__userpurge std::vector<TimeSums_t>::insert@<eax>(
        std::vector<TimeSums_t> *this@<ecx>,
        const TimeSums_t *result,
        std::_Vector_iterator<TimeSums_t> _Where,
        const TimeSums_t *_Val)
{
  if ( ((unsigned __int8)result & 2) != 0 )
  {
    `eh vector destructor iterator'(
      a1: this,
      a2: 0x70u,
      a3: *((_DWORD *)this - 1),
      a4: (void (__thiscall *)(void *))CWorkerThread::~CWorkerThread);
    if ( ((unsigned __int8)result & 1) != 0 )
      j_j__free(Block: (char *)this - 4);
    return (std::vector<TimeSums_t> *)((char *)this - 4);
  }
  else
  {
    CWorkerThread::~CWorkerThread((CWorkerThread *)this);
    if ( ((unsigned __int8)result & 1) != 0 )
      j__free(Block: this);
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F011940
// Name: protected: bool std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::_Buy(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::vector<TimeSums_t>::_Buy(
        std::vector<TimeSums_t> *this@<edi>,
        unsigned int _Capacity@<eax>,
        int a3@<ecx>,
        void *a4@<ebx>,
        int a5@<esi>)
{
  bool v5; // zf
  void *v6; // eax

  *(_BYTE *)_Capacity |= _Capacity;
  v5 = (_BYTE)a3 + *(_BYTE *)(a3 + 73304350) == 0;
  *(_BYTE *)(a3 + 73304350) += a3;
  *(_DWORD *)(a5 + 8) = a4;
  *(_DWORD *)(a5 + 32) = a4;
  *(_BYTE *)(a5 + 48) = (_BYTE)a4;
  *(_BYTE *)(a5 + 49) = (_BYTE)a4;
  *(_DWORD *)(a5 + 24) = a3;
  *(_DWORD *)(a5 + 28) = a4;
  *(_DWORD *)(a5 + 2100) = a4;
  *(_DWORD *)(a5 + 16) = a4;
  *(_DWORD *)(a5 + 12) = a4;
  *(_DWORD *)(a5 + 20) = a4;
  if ( v5 )
  {
    *(_DWORD *)(a5 + 16) = 50000;
    v6 = malloc_0(Size: 0x2191C0u);
    *(_DWORD *)(a5 + 12) = v6;
    if ( v6 == a4 )
      ((void (__cdecl *)(errentry *, void *, errentry *, int, void *, void *))AssertMsgImplementation)(
        a1: &errtable[11],
        a2: a4,
        a3: &errtable[9],
        a4: 47,
        a5: &unk_3F041A85,
        a6: a4);
  }
  JUMPOUT(0x3F0119A3);
}

//------------------------------------------------------------------------------
// Address: 0x3F0119B0
// Name: protected: struct TimeSums_t __near * std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::_Ufill(struct TimeSums_t __near *,unsigned int,struct TimeSums_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0119E0
// Name: public: std::length_error::length_error(class std::length_error const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::length_error::length_error(std::length_error *this@<ecx>, int _EAX@<eax>, int a3@<esi>)
{
  void *v4; // esi

  __asm { aas }
  ((void (__thiscall *)(std::length_error *))AssertMsgImplementation)(a1: this);
  v4 = *(void **)(a3 + 12);
  if ( v4 != nullptr )
    free(Block: v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F011B00
// Name: public: class std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::iterator std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::erase(class std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::iterator,class std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::iterator)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::iterator *__userpurge std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::erase@<eax>(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this@<ecx>,
        int a2@<edx>,
        int a3@<ebp>,
        int *a4@<edi>,
        int a5@<esi>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::iterator *result,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::iterator _First,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::iterator _Last)
{
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::iterator *v8; // eax
  bool v9; // zf

  a4[5] = a2 + 1;
  STACK[0x10C] = -1;
  v8 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::iterator *)sub_3F012460(result: a4[2], a2: (int)this, a3: a5, a4: *(_DWORD *)(a3 + 12), a5: *(_DWORD *)(a3 + 16), a6: a4[1]);
  v9 = *a4 == 0;
  a4[1] = a5;
  if ( v9 )
    *a4 = a5;
  a4[2] = a5;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x3F011C50
// Name: protected: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Lrotate(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this@<ecx>,
        int a2@<ebx>,
        _DWORD *a3@<esi>,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Wherenode)
{
  if ( a3[2] == 0 )
    ((void (__cdecl *)(errentry *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &errtable[34],
      a2: 0,
      a3: &errtable[9],
      a4: 246,
      a5: &unk_3F041A89,
      a6: 0);
  if ( sub_3F0124D0(a1: (_DWORD *)a3[2], a2, a3: a3[7]) != 0 )
    ++a3[8];
}

//------------------------------------------------------------------------------
// Address: 0x3F011CA0
// Name: protected: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Rrotate(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Wherenode)
{
  CValidator::ClaimMemory(
    (CValidator *)this,
    a2: *(std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node **)(((unsigned int)_Wherenode & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F011CF0
// Name: protected: struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near * std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Buynode(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *,struct std::pair<class CVProfNode __near * const,double> const __near &,char)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        int a1@<ebx>,
        int a2@<esi>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Larg,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Parg,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *_Rarg,
        char _Carg)
{
  *(_DWORD *)(a2 + 93) += a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F011DA0
// Name: public: class std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::iterator std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::erase(class std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::iterator,class std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::iterator)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator *__usercall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::erase@<eax>(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this@<ecx>,
        int _EBP@<ebp>,
        _BYTE *a3@<esi>,
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator *result,
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator _First,
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator _Last,
        int a7,
        int a8,
        _BYTE *a9,
        int a10,
        int a11,
        int a12,
        char a13,
        int a14,
        int a15,
        int a16,
        int Str,
        int a18,
        int a19,
        int a20,
        int a21)
{
  char *v22; // edi
  char *v23; // eax
  char v24; // bl
  int v25; // ecx
  double v27; // [esp-10h] [ebp-18h]

  __asm
  {
    fisub   [esp+arg_30]
    fstp    [esp+arg_30]
    fld     [esp+arg_30]
    fabs
    fstp    [esp+arg_30]
    fld     [esp+arg_30]
    fcomp   qword ptr ds:GS_ExceptionRecord.ExceptionInformation+14h
    fnstsw  ax
  }
  if ( __SETP__(HIBYTE(_AX) & 5, 0) )
  {
    ((void (__cdecl *)(int *, int, int *, int, int *))_LN10_6)(
      a1: &a21,
      a2: 32,
      a3: &errtable[42].errnocode,
      a4: 2,
      a5: &a11);
    __asm { fld     dword ptr [ebp+8] }
    __asm { fstp    [esp+8+var_8] }
    ((void (__cdecl *)(char *, int, int *, _DWORD, _DWORD))_LN10_6)(
      a1: &a13,
      a2: 32,
      a3: &a21,
      a4: LODWORD(v27),
      a5: HIDWORD(v27));
  }
  else
  {
    ((void (__cdecl *)(char *, int, int *, std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *, int *))_LN10_6)(
      a1: &a13,
      a2: 32,
      a3: &errtable[41].errnocode,
      a4: this,
      a5: &a11);
  }
  v22 = &a13;
  v23 = strstr(Str: &a13, SubStr: (const char *)&errtable[44]);
  if ( v23 == nullptr )
    v23 = strstr(Str: &a13, SubStr: (const char *)&errtable[44].errnocode);
  v24 = a13;
  v25 = v23 - &a13 - 3;
  if ( a13 != 0 )
  {
    do
    {
      if ( v25 >= 0 && v25 % 3 == 0 && a3 != a9 )
        *a3++ = 44;
      ++v22;
      *a3 = v24;
      v24 = *v22;
      --v25;
      ++a3;
    }
    while ( *v22 != 0 );
    *a3 = 0;
    return (std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator *)a9;
  }
  else
  {
    *a3 = 0;
    return (std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator *)a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F011EF0
// Name: protected: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Lrotate(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Wherenode)
{
  int v4; // edi
  const char *v5; // ebx
  const char *v6; // eax
  float v7; // [esp+0h] [ebp-4h]
  int v8; // [esp+20h] [ebp+1Ch]

  if ( *(_DWORD *)(a3 + 32) >= *(_DWORD *)(a2 + 8) )
  {
    v4 = *(_DWORD *)(a3 + 28);
    v5 = *(const char **)(a3 + 4);
    v8 = *(unsigned __int16 *)(a3 + 40);
    v7 = (float)*(int *)(a3 + 32);
    v6 = (const char *)((int (__cdecl *)(_DWORD))loc_3F011D00)(a1: LODWORD(v7));
    Msg(a1: (int)"%*s%s --> %d blocks = %s\n", v8, (const char *)&bad_alloc_Message_3, v5, v4, v6);
  }
  JUMPOUT(0x3F011F3C);
}

//------------------------------------------------------------------------------
// Address: 0x3F011F40
// Name: protected: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Rrotate(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this@<ecx>,
        int a2@<eax>,
        char a3@<dh>,
        int a4@<ebp>,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Wherenode)
{
  float v5; // [esp+0h] [ebp-4h]

  *(_DWORD *)(a4 - 2085915146) += a2;
  *(_BYTE *)(a4 + 32) += a3;
  ((void (__cdecl *)(const char *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: "Assertion Failed: g_pMemAllocSteam",
    a2: 0,
    a3: &errtable[9],
    a4: 494,
    a5: &unk_3F041A8A,
    a6: 0);
  v5 = (float)*(int *)(a4 + 8);
  ((void (__cdecl *)(_DWORD))loc_3F011D00)(a1: LODWORD(v5));
  JUMPOUT(0x3F011F8D);
}

//------------------------------------------------------------------------------
// Address: 0x3F012030
// Name: protected: void std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::_Insert_n(class std::_Vector_iterator<struct TimeSums_t,class std::allocator<struct TimeSums_t>>,unsigned int,struct TimeSums_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge std::vector<TimeSums_t>::_Insert_n(
        int a1@<eax>,
        int a2@<ebx>,
        _DWORD *a3@<edi>,
        std::vector<TimeSums_t> *this,
        std::_Vector_iterator<TimeSums_t> _Where,
        const TimeSums_t *_Tmp,
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
        const char *a20,
        int a21,
        const char *a22,
        int a23,
        const char *a24,
        int a25,
        const char *a26,
        int a27,
        const char *a28,
        int a29,
        const char *a30,
        int a31,
        const char *a32,
        int a33,
        const char *a34,
        int a35,
        const char *a36,
        int a37,
        const char *a38,
        int a39,
        const char *a40,
        int a41,
        const char *a42,
        int a43)
{
  std::vector<TimeSums_t> *v44; // edi
  unsigned int i; // esi
  _UNKNOWN *retaddr; // [esp+38h] [ebp+0h]

  v44 = (std::vector<TimeSums_t> *)((char *)a3 + *a3);
  a19 = a1;
  a20 = "p2pcore.dll";
  a21 = a1;
  a22 = "p2pvoice.dll";
  a23 = a1;
  a24 = "vaudio_speex.dll";
  a25 = a1;
  a26 = "steamservice.dll";
  a27 = a1;
  a28 = "xmemory";
  a29 = 146;
  a30 = "xlocale";
  a31 = 1760;
  a32 = "misc.h";
  a33 = 67;
  a34 = "secblock.h";
  a35 = 87;
  a36 = "vgui2.dll";
  a37 = a1;
  a38 = "steamui.dll";
  a39 = a1;
  a40 = "friendsui.dll";
  a41 = a1;
  a42 = "serverbrowser.dll";
  a43 = a1;
  for ( i = 0; i < 0x15; ++i )
  {
    if ( sub_3F01A783(a1: a2, a2: *(&retaddr + 2 * i)) == 0 && v44 == *(&this + 2 * i) )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F012350
// Name: public: class std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::iterator std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::erase(class std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::iterator)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::iterator *result,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::iterator _Where)
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
  __debugbreak();
  __debugbreak();
  __debugbreak();
  JUMPOUT(0x3F012360);
}

//------------------------------------------------------------------------------
// Address: 0x3F012620
// Name: protected: struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near * std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Buynode(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *__thiscall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *this,
        int a2,
        char a3)
{
  _BYTE v4[232]; // [esp+0h] [ebp-100h] BYREF

  ((void (__cdecl *)(_BYTE *, int, int, char *))_LN10_6)(a1: v4, a2: 256, a3: a2, a4: &a3);
  (**(void (__thiscall ***)(int, _BYTE *))dword_3F03D3E8)(a1: dword_3F03D3E8, a2: v4);
  return (*((std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *(**)(void))g_pVCR
          + 1))();
}

//------------------------------------------------------------------------------
// Address: 0x3F0126D0
// Name: public: class std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::iterator std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::erase(class std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::iterator)
// Source: json
//------------------------------------------------------------------------------
std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator *__fastcall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this,
        const void *a2)
{
  fwrite_0(Buffer: a2, ElementSize: 1u, ElementCount: (size_t)this, Stream: Stream);
  return (std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::iterator *)fflush(Stream: Stream);
}

//------------------------------------------------------------------------------
// Address: 0x3F0129A0
// Name: protected: struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near * std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Buynode(void)
// Source: json
//------------------------------------------------------------------------------
FILE *__thiscall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Buynode(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *this)
{
  FILE *result; // eax
  HANDLE CurrentProcess; // eax

  result = Stream;
  if ( Stream != nullptr )
  {
    result = (FILE *)fclose_0(Stream: Stream);
    Stream = nullptr;
  }
  if ( ElementSize == 2 )
  {
    CurrentProcess = GetCurrentProcess();
    result = (FILE *)TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
  }
  ElementSize = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F012A50
// Name: public: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::const_iterator::_Dec(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::const_iterator::_Dec(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::const_iterator *this@<ecx>,
        int _EAX@<eax>,
        int _EBX@<ebx>,
        _BYTE *a4@<edi>)
{
  __asm
  {
    lock rol dword ptr [ebx+0], cl; "bad allocation"
    aas
  }
  *a4 += (_BYTE)this;
  JUMPOUT(0x3F012A59);
}

//------------------------------------------------------------------------------
// Address: 0x3F012AD0
// Name: public: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::const_iterator::_Dec(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::const_iterator::_Dec(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::const_iterator *this@<ecx>,
        int a2@<eax>,
        int a3@<ebp>)
{
  FILE *v3; // [esp-8h] [ebp-8h]

  if ( a2 != 0 )
  {
    ++dword_3F03D3F4;
    if ( a2 == 1 )
    {
      sub_3F012770(a1: 2);
    }
    else if ( dword_3F03C0C4 != 2 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)this,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
  }
  if ( ElementSize == 1 )
  {
    v3 = Stream;
    *(_BYTE *)(a3 - 13) = strlen(*(const char **)(a3 + 8));
    fwrite_0(Buffer: (const void *)(a3 - 13), ElementSize: 1u, ElementCount: 1u, Stream: v3);
    JUMPOUT(0x3F012B48);
  }
  JUMPOUT(0x3F012B75);
}

//------------------------------------------------------------------------------
// Address: 0x3F012B50
// Name: public: void std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::const_iterator::_Inc(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::const_iterator::_Inc(
        std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::const_iterator *this@<ecx>,
        size_t a2@<eax>,
        const void *a3@<esi>)
{
  __asm { rep mov edx, Stream }
  fwrite_0(Buffer: a3, ElementSize: 1u, ElementCount: a2, Stream: _EDX);
  fflush(Stream: Stream);
  JUMPOUT(0x3F012C6E);
}

//------------------------------------------------------------------------------
// Address: 0x3F012BC0
// Name: public: std::out_of_range::out_of_range(class std::out_of_range const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge std::out_of_range::out_of_range(
        std::out_of_range *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<ebx>,
        int a4@<ebp>,
        _DWORD *a5@<esi>,
        const std::out_of_range *__that)
{
  unsigned int v8; // eax
  _DWORD *v9; // ecx
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // edx
  int v13; // [esp-8h] [ebp-8h]
  char v14; // [esp-4h] [ebp-4h]

  _EAX = a2 - *a3;
  __asm { aas }
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
    (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)this,
    a2: v13,
    a3: v14);
  v8 = *(unsigned __int8 *)(a4 - 13);
  v9 = (_DWORD *)(a4 - 272);
  if ( v8 < 4 )
  {
LABEL_4:
    if ( v8 == 0 )
      goto LABEL_13;
  }
  else
  {
    while ( *a5 == *v9 )
    {
      v8 -= 4;
      ++v9;
      ++a5;
      if ( v8 < 4 )
        goto LABEL_4;
    }
  }
  if ( *(unsigned __int8 *)a5 != *(unsigned __int8 *)v9 )
    goto LABEL_14;
  v11 = (unsigned __int8 *)v9 + 1;
  v12 = (unsigned __int8 *)a5 + 1;
  if ( v8 != 1 )
  {
    if ( *v12 == *v11 )
      JUMPOUT(0x3F012C1F);
LABEL_14:
    JUMPOUT(0x3F012C47);
  }
LABEL_13:
  JUMPOUT(0x3F012C55);
}

//------------------------------------------------------------------------------
// Address: 0x3F012C20
// Name: protected: static struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near * std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Max(struct std::_Tree_nod<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Max(
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
        int a63)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F012C40
// Name: protected: static struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near * std::_Tree<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Max(struct std::_Tree_nod<class std::_Tmap_traits<char const __near *,unsigned int,struct std::less<char const __near *>,class std::allocator<struct std::pair<char const __near * const,unsigned int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Max(
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *_Pnode@<eax>,
        unsigned __int8 *a2@<edx>)
{
  int v2; // esi
  int v3; // eax

  v2 = *a2 - (_DWORD)_Pnode;
  if ( v2 != 0 )
  {
    v3 = 1;
    if ( v2 <= 0 )
      v3 = -1;
  }
  else
  {
    v3 = 0;
  }
  if ( v3 != 0 )
    JUMPOUT(0x3F012C5C);
  JUMPOUT(0x3F012C6E);
}

//------------------------------------------------------------------------------
// Address: 0x3F012C60
// Name: public: void std::_Tree<class std::_Tmap_traits<class CVProfNode __near *,double,struct std::less<class CVProfNode __near *>,class std::allocator<struct std::pair<class CVProfNode __near * const,double>>,0>>::const_iterator::_Inc(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::const_iterator::_Inc(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::const_iterator *this@<ecx>,
        int _EAX@<eax>,
        int a3@<ebp>)
{
  char v4; // [esp-Ch] [ebp-Ch]

  __asm { aas }
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
    (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)this,
    a2: (int)&rterrs[11].rterrtxt,
    a3: v4);
  *(_DWORD *)(a3 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( ElementSize == 2 )
  {
    ((void (*)(void))loc_3F0126F0)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F012CD0
// Name: struct TimeSums_t __near * stdext::unchecked_copy<struct TimeSums_t __near *,struct TimeSums_t __near *>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall stdext::unchecked_copy<TimeSums_t *,TimeSums_t *>(int a1@<ebp>)
{
  size_t v3; // eax
  bool v4; // zf

  if ( ElementSize == 0
    || byte_3F03D3C7 == 0
    || *(_BYTE *)(dword_3F03D400 + 12 * (unsigned __int16)sub_3F012550() + 8) == 0 )
  {
    JUMPOUT(0x3F012D08);
  }
  v3 = ElementSize;
  v4 = ElementSize == 1;
  *(_BYTE *)(a1 - 13) = 0;
  if ( v4 )
  {
    EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
    JUMPOUT(0x3F012D56);
  }
  if ( v3 == 2 )
  {
    sub_3F012550();
    JUMPOUT(0x3F012D3E);
  }
  JUMPOUT(0x3F012D5B);
}

//------------------------------------------------------------------------------
// Address: 0x3F012D40
// Name: struct TimeSums_t __near * stdext::_Unchecked_move_backward<struct TimeSums_t __near *,struct TimeSums_t __near *>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __usercall stdext::_Unchecked_move_backward<TimeSums_t *,TimeSums_t *>@<st0>(
        TimeSums_t *_Last@<edx>,
        int a2@<ebp>)
{
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *v3; // ecx
  size_t v4; // eax

  WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 4 * (_DWORD)_Last + 4), dwMilliseconds: 0xFFFFFFFF);
  v4 = ElementSize;
  *(_DWORD *)(a2 - 4) = 0;
  if ( v4 != 0 )
  {
    ++dword_3F03D3F4;
    if ( v4 == 1 )
    {
      sub_3F012770(a1: 0);
      JUMPOUT(0x3F012D79);
    }
    if ( dword_3F03C0C4 != 0 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: v3,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
      v4 = ElementSize;
    }
  }
  if ( v4 == 1 )
  {
    fwrite_0(Buffer: (const void *)(a2 + 8), ElementSize: 1u, ElementCount: 8u, Stream: Stream);
    fflush(Stream: Stream);
  }
  else
  {
    if ( v4 != 2 )
      goto LABEL_12;
    ((void (__thiscall *)(int))loc_3F012670)(a1: a2 + 8);
    dbl_3F03D358 = *(double *)(a2 + 8);
  }
  v4 = ElementSize;
LABEL_12:
  *(double *)(a2 - 24) = *(double *)(a2 + 8);
  *(_DWORD *)(a2 - 4) = -1;
  if ( v4 == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
    return *(double *)(a2 - 24);
  }
  else
  {
    if ( v4 == 2 )
      ((void (*)(void))loc_3F0126F0)();
    return *(double *)(a2 - 24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F012E70
// Name: void std::_Uninit_fill_n<struct TimeSums_t __near *,unsigned int,struct TimeSums_t,class std::allocator<struct TimeSums_t>>(struct TimeSums_t __near *,unsigned int,struct TimeSums_t const __near &,class std::allocator<struct TimeSums_t> __near &,struct std::_Nonscalar_ptr_iterator_tag,struct std::_Range_checked_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::_Uninit_fill_n<TimeSums_t *,unsigned int,TimeSums_t,std::allocator<TimeSums_t>>(
        const TimeSums_t *_Val@<ecx>,
        _DWORD *a2@<eax>,
        HWND a3@<edx>,
        int a4@<ebx>,
        UINT a5@<ebp>)
{
  bool v5; // cf
  UINT v6; // [esp-4h] [ebp-8h]

  *a2 |= 0x8B287500;
  v5 = *(_BYTE *)(a4 + 1300960325) < (unsigned __int8)_Val;
  *(_BYTE *)(a4 + 1300960325) -= (_BYTE)_Val;
  *((_BYTE *)a3 - 117) += (_BYTE)a3 + v5;
  PeekMessageA(lpMsg: *(LPMSG *)(a5 + 8), hWnd: a3, wMsgFilterMin: (UINT)_Val, wMsgFilterMax: a5, wRemoveMsg: v6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0131F0
// Name: void std::_Insertion_sort<struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Insertion_sort<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>()
{
  unsigned __int16 v0; // ax

  if ( ElementSize != 0
    && byte_3F03D3C7 != 0
    && *(_BYTE *)(dword_3F03D400 + 12 * (unsigned __int16)sub_3F012550() + 8) != 0 )
  {
    if ( ElementSize == 1 )
    {
      EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
    }
    else
    {
      if ( ElementSize != 2 )
        JUMPOUT(0x3F013284);
      v0 = sub_3F012550();
      WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v0 + 4), dwMilliseconds: 0xFFFFFFFF);
    }
    JUMPOUT(0x3F01327F);
  }
  JUMPOUT(0x3F0132F8);
}

//------------------------------------------------------------------------------
// Address: 0x3F013280
// Name: struct TimeSums_t __near * std::_Uninit_copy<struct TimeSums_t __near *,struct TimeSums_t __near *,class std::allocator<struct TimeSums_t>>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *,class std::allocator<struct TimeSums_t> __near &,struct std::_Nonscalar_ptr_iterator_tag,struct std::_Range_checked_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::_Uninit_copy<TimeSums_t *,TimeSums_t *,std::allocator<TimeSums_t>>(
        TimeSums_t *_Last@<ecx>,
        int _EAX@<eax>,
        int _EBX@<ebx>,
        int a4@<ebp>)
{
  FILE *v5; // [esp-Ch] [ebp-Ch]

  __asm
  {
    lock rol dword ptr [ebx+0], cl; "bad allocation"
    aas
  }
  *(_DWORD *)(a4 - 4) = 0;
  if ( _EAX == 1 )
  {
    ++dword_3F03D3F4;
    sub_3F012770(a1: 14);
    v5 = Stream;
    *(_BYTE *)(a4 - 13) = 0;
    fwrite_0(Buffer: (const void *)(a4 - 13), ElementSize: 1u, ElementCount: 1u, Stream: v5);
    fflush(Stream: Stream);
    _EAX = ElementSize;
  }
  *(_DWORD *)(a4 - 4) = -1;
  if ( _EAX != 1 )
  {
    if ( _EAX == 2 )
      ((void (*)(void))loc_3F0126F0)();
    JUMPOUT(0x3F013302);
  }
  LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
}

//------------------------------------------------------------------------------
// Address: 0x3F0133A0
// Name: void std::_Make_heap<struct TimeSums_t __near *,int,struct TimeSums_t,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &),int __near *,struct TimeSums_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::_Make_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3@<esi>)
{
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *v4; // ecx
  size_t v5; // eax

  (*(void (**)(void))(a1 - 1))();
  v5 = ElementSize;
  *(_DWORD *)(a2 - 4) = 0;
  if ( v5 == 2 )
  {
    dword_3F03D3F4 += a3;
    if ( dword_3F03C0C4 != 14 )
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: v4,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    ((void (__thiscall *)(int))loc_3F012670)(a1: a2 - 13);
    if ( *(_BYTE *)(a2 - 13) != 0 )
    {
      ((void (__thiscall *)(_DWORD))loc_3F012670)(a1: *(_DWORD *)(a2 + 8));
      ((void (__thiscall *)(_DWORD))loc_3F012670)(a1: *(_DWORD *)(a2 + 12));
      JUMPOUT(0x3F0133FD);
    }
    JUMPOUT(0x3F013426);
  }
  JUMPOUT(0x3F01342B);
}

//------------------------------------------------------------------------------
// Address: 0x3F013400
// Name: void std::_Sort_heap<struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::_Sort_heap<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(int a1@<ebp>)
{
  ((void (*)(void))loc_3F012670)();
  *(_DWORD *)(a1 - 4) = -1;
  sub_3F0125E0(a1: (_BYTE *)(a1 - 14));
}

//------------------------------------------------------------------------------
// Address: 0x3F013480
// Name: void std::_Med3<struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __usercall std::_Med3<TimeSums_t *,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(int a1@<ebp>)
{
  size_t v2; // eax
  bool v3; // zf
  unsigned __int16 v4; // ax

  if ( ElementSize != 0
    && byte_3F03D3C7 != 0
    && *(_BYTE *)(dword_3F03D400 + 12 * (unsigned __int16)sub_3F012550() + 8) != 0 )
  {
    v2 = ElementSize;
    v3 = ElementSize == 1;
    *(_BYTE *)(a1 - 13) = 0;
    if ( v3 )
    {
      EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
    }
    else if ( v2 == 2 )
    {
      v4 = sub_3F012550();
      WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v4 + 4), dwMilliseconds: 0xFFFFFFFF);
    }
    *(_DWORD *)(a1 - 4) = 0;
    if ( ElementSize != 0 )
    {
      ++dword_3F03D3F4;
      if ( ElementSize == 1 )
      {
        sub_3F012770(a1: 3);
        JUMPOUT(0x3F01352F);
      }
      JUMPOUT(0x3F013534);
    }
    JUMPOUT(0x3F01354F);
  }
  GetCursorPos(lpPoint: *(LPPOINT *)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F013530
// Name: void std::_Adjust_heap<struct TimeSums_t __near *,int,struct TimeSums_t,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,int,int,struct TimeSums_t,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::_Adjust_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        char a1@<cf>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a2@<ecx>,
        int a3@<ebx>,
        int a4@<ebp>)
{
  tagPOINT *v6; // esi
  char v7; // [esp-8h] [ebp-8h]

  _EAX = *(_DWORD *)(a3 + 8 * a4) - (a1 + *(_DWORD *)(a3 + 62964797));
  __asm { aas }
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
    this: a2,
    a2: 1748960043,
    a3: v7);
  if ( ElementSize == 2 )
  {
    ((void (__thiscall *)(_DWORD))loc_3F012670)(a1: *(_DWORD *)(a4 + 8));
  }
  else
  {
    v6 = *(tagPOINT **)(a4 + 8);
    GetCursorPos(lpPoint: v6);
    if ( ElementSize == 1 )
    {
      fwrite_0(Buffer: v6, ElementSize: 1u, ElementCount: 8u, Stream: Stream);
      fflush(Stream: Stream);
    }
  }
  *(_DWORD *)(a4 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( ElementSize == 2 )
  {
    ((void (*)(void))loc_3F0126F0)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0135F0
// Name: void std::_Push_heap<struct TimeSums_t __near *,int,struct TimeSums_t,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &)>(struct TimeSums_t __near *,int,int,struct TimeSums_t,bool (*)(struct TimeSums_t const __near &,struct TimeSums_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __usercall std::_Push_heap<TimeSums_t *,int,TimeSums_t,bool (__cdecl *)(TimeSums_t const &,TimeSums_t const &)>(
        int a1@<ebp>)
{
  bool v2; // zf

  if ( ElementSize != 0
    && byte_3F03D3C7 != 0
    && *(_BYTE *)(dword_3F03D400 + 12 * (unsigned __int16)sub_3F012550() + 8) != 0 )
  {
    v2 = ElementSize == 1;
    *(_BYTE *)(a1 - 13) = 0;
    if ( v2 )
    {
      EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
      JUMPOUT(0x3F01367F);
    }
    JUMPOUT(0x3F01365D);
  }
  ScreenToClient(hWnd: *(HWND *)(a1 + 8), lpPoint: *(LPPOINT *)(a1 + 12));
}

//------------------------------------------------------------------------------
// Address: 0x3F013660
// Name: void std::_Rotate<struct TimeSums_t __near *,int,struct TimeSums_t>(struct TimeSums_t __near *,struct TimeSums_t __near *,struct TimeSums_t __near *,int __near *,struct TimeSums_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __fastcall std::_Rotate<TimeSums_t *,int,TimeSums_t>(int a1, unsigned __int16 a2)
{
  unsigned __int8 v2; // al

  v2 = __inbyte(a2);
  __outbyte(a2, v2);
  JUMPOUT(0x3F013662);
}

//------------------------------------------------------------------------------
// Address: 0x3F0137A0
// Name: public: virtual char const __near * std::logic_error::what(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall std::logic_error::what(std::logic_error *this@<ecx>, _DWORD *a2@<eax>, int a3@<ebx>)
{
  *a2 |= 0x8B2C7500;
  *(_BYTE *)(a3 - 1957555123) -= ((unsigned __int8)a2 < 0x8Bu) + (_BYTE)this;
  std::out_of_range::~out_of_range((std::out_of_range *)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F0137B0
// Name: public: virtual std::out_of_range::~out_of_range(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::out_of_range::~out_of_range(
        std::out_of_range *this@<ecx>,
        char a2@<cf>,
        char *a3@<eax>,
        int a4@<edx>,
        int a5@<ebp>)
{
  int v5; // [esp-Ch] [ebp-10h]
  struct sockaddr *v6; // [esp-8h] [ebp-Ch]
  int *v7; // [esp-4h] [ebp-8h]

  *(a3 - 117) += a4 + a2;
  LOBYTE(a3) = (unsigned __int8)a3 | 0x51;
  recvfrom(s: *(_DWORD *)(a5 + 9), buf: a3, len: a4, flags: v5, from: v6, fromlen: v7);
}

//------------------------------------------------------------------------------
// Address: 0x3F013800
// Name: public: std::out_of_range::out_of_range(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::out_of_range::out_of_range(
        std::out_of_range *this@<ecx>,
        int a2@<edx>,
        int a3@<ebp>,
        int a4@<edi>,
        const std::string *_Message)
{
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *v5; // ecx

  WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 4 * a2 + 4), dwMilliseconds: 0xFFFFFFFF);
  *(_DWORD *)(a3 - 4) = 0;
  if ( ElementSize != 0 )
  {
    dword_3F03D3F4 += a4;
    if ( ElementSize == a4 )
    {
      sub_3F012770(a1: a4);
    }
    else if ( dword_3F03C0C4 != a4 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: v5,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
  }
  JUMPOUT(0x3F01385D);
}

//------------------------------------------------------------------------------
// Address: 0x3F013860
// Name: public: std::logic_error::logic_error(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::logic_error::logic_error(std::logic_error *this, const std::string *_Message)
{
  JUMPOUT(0x3F013862);
}

//------------------------------------------------------------------------------
// Address: 0x3F013960
// Name: public: virtual std::logic_error::~logic_error(void)
// Source: json
//------------------------------------------------------------------------------
void __fastcall std::logic_error::~logic_error(std::logic_error *this, __int16 _DX)
{
  __asm { insb }
  __indword(_DX);
  JUMPOUT(0x3F013962);
}

//------------------------------------------------------------------------------
// Address: 0x3F0139E0
// Name: public: virtual std::length_error::~length_error(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall std::length_error::~length_error(
        std::length_error *this@<ecx>,
        int _EAX@<eax>,
        char a3@<dh>,
        int a4@<ebx>)
{
  __asm { aas }
  *((_BYTE *)this - 128) += a3;
  *(_BYTE *)(_EAX + a4 - 24) += a3;
  JUMPOUT(0x3F0139F0);
}

//------------------------------------------------------------------------------
// Address: 0x3F013A30
// Name: public: std::length_error::length_error(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::length_error::length_error(
        std::length_error *this@<ecx>,
        char _DH@<dh>,
        int a3@<ebp>,
        const std::string *_Message)
{
  _EBP = a3 + 1;
  __asm { rep add [ebp+0Dh], dh }
  EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
  *(_DWORD *)(_EBP - 4) = 0;
  if ( ElementSize != 0 )
  {
    ++dword_3F03D3F4;
    if ( ElementSize == 1 )
    {
      sub_3F012770(a1: 18);
      JUMPOUT(0x3F013A8D);
    }
    JUMPOUT(0x3F013A92);
  }
  JUMPOUT(0x3F013AAD);
}

//------------------------------------------------------------------------------
// Address: 0x3F013AB1
// Name: public: static void std::_String_base::_Xlen(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall std::_String_base::_Xlen(int a1@<edx>, int a2@<ebp>, int a3@<esi>)
{
  LOBYTE(a1) = *(_BYTE *)(a3 + 117) + a1;
  ((void (__fastcall *)(int, int))loc_3F012670)(a1: a2 - 20, a2: a1);
  if ( *(_DWORD *)(a2 - 20) == -1 )
  {
    ((void (__thiscall *)(int))loc_3F012670)(a1: a2 - 24);
    WSASetLastError(iError: *(_DWORD *)(a2 - 24));
    JUMPOUT(0x3F013B70);
  }
  ((void (__thiscall *)(_DWORD))loc_3F012670)(a1: *(_DWORD *)(a2 + 12));
  std::_String_base::_Xran();
}

//------------------------------------------------------------------------------
// Address: 0x3F016720
// Name: public: class CVProfNode __near * CVProfNode::GetSubNode(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
struct CVProfNode *__thiscall CVProfNode::GetSubNode(CVProfNode *this, const char *a2, int a3, const char *a4)
{
  return CVProfNode::GetSubNode(this, a2, a3, a4, a5: 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F016740
// Name: public: void CVProfNode::EnterScope(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVProfNode::EnterScope(CVProfNode *this@<ecx>, _iobuf *a2, int a3, int a4)
{
  fseek(stream: a2, offset: a3, whence: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F016810
// Name: public: void CVProfNode::Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::Pause(CVProfNode *this)
{
  __int64 v2; // kr00_8
  bool v3; // cf
  int v4; // eax
  CVProfNode *m_pChild; // ecx
  __int64 out_edx; // [esp+10h] [ebp-8h] BYREF

  do
  {
    if ( this->m_nRecursions > 0 )
    {
      out_edx = 0;
      cpuid(a1: (int *)&out_edx);
      v2 = out_edx - this->m_Timer.m_Duration.m_Int64;
      this->m_Timer.m_Duration.m_Int64 = v2;
      v3 = __CFADD__((_DWORD)v2, this->m_CurFrameTime.m_Int64);
      LODWORD(this->m_CurFrameTime.m_Int64) += v2;
      HIDWORD(this->m_CurFrameTime.m_Int64) += HIDWORD(this->m_Timer.m_Duration.m_Int64) + v3;
      v4 = *((_DWORD *)this + 35);
      if ( *(_BYTE *)(v4 + 44) != 0 && *(_BYTE *)(v4 + 45) != 0 )
      {
        sub_3F00C0A0();
        this->m_iCurL2CacheMiss += this->m_L2Cache.m_iL2CacheMissCount;
      }
    }
    m_pChild = this->m_pChild;
    if ( m_pChild != nullptr )
      CVProfNode::Pause(this: m_pChild);
    this = this->m_pSibling;
  }
  while ( this != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x3F016890
// Name: public: void CVProfNode::Resume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::Resume(CVProfNode *this)
{
  int v2; // eax
  CVProfNode *m_pChild; // ecx

  do
  {
    if ( this->m_nRecursions > 0 )
    {
      cpuid(a1: (int *)&this->m_Timer);
      v2 = *((_DWORD *)this + 35);
      if ( *(_BYTE *)(v2 + 44) != 0 && *(_BYTE *)(v2 + 45) != 0 )
        sub_3F00BFD0();
    }
    m_pChild = this->m_pChild;
    if ( m_pChild != nullptr )
      CVProfNode::Resume(this: m_pChild);
    this = this->m_pSibling;
  }
  while ( this != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x3F0168F0
// Name: public: void CVProfNode::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::Reset(CVProfNode *this)
{
  CVProfNode *m_pChild; // ecx

  do
  {
    m_pChild = this->m_pChild;
    this->m_nPrevFrameCalls = 0;
    LODWORD(this->m_PrevFrameTime.m_Int64) = 0;
    HIDWORD(this->m_PrevFrameTime.m_Int64) = 0;
    this->m_nCurFrameCalls = 0;
    LODWORD(this->m_CurFrameTime.m_Int64) = 0;
    HIDWORD(this->m_CurFrameTime.m_Int64) = 0;
    this->m_nTotalCalls = 0;
    LODWORD(this->m_TotalTime.m_Int64) = 0;
    HIDWORD(this->m_TotalTime.m_Int64) = 0;
    LODWORD(this->m_PeakTime.m_Int64) = 0;
    HIDWORD(this->m_PeakTime.m_Int64) = 0;
    this->m_iCurL2CacheMiss = 0;
    this->m_iTotalL2CacheMiss = 0;
    if ( m_pChild != nullptr )
      CVProfNode::Reset(this: m_pChild);
    this = this->m_pSibling;
  }
  while ( this != nullptr );
}

//------------------------------------------------------------------------------
// Address: 0x3F016940
// Name: public: void CVProfNode::MarkFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfNode::MarkFrame(CVProfNode *this)
{
  JUMPOUT(0x3F016946);
}

//------------------------------------------------------------------------------
// Address: 0x3F016D00
// Name: public: void CVProfile::RegisterCallbackHandler(class IVProfileCallbackHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::RegisterCallbackHandler(CVProfile *this, struct IVProfileCallbackHandler *a2)
{
  int *v3; // ebx
  CVProfile *CurrentThreadId; // ecx
  struct IVProfileCallbackHandler **v5; // edi
  int *v6; // esi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  _DWORD *v9; // eax
  unsigned int v10; // edi
  int *v12; // [esp+14h] [ebp-24h]
  struct IVProfileCallbackHandler **v13; // [esp+18h] [ebp-20h]
  _BYTE v14[12]; // [esp+20h] [ebp-18h] BYREF
  int v15; // [esp+34h] [ebp-4h]

  v3 = &this->m_GroupIDStack[664];
  v12 = &this->m_GroupIDStack[664];
  CurrentThreadId = (CVProfile *)GetCurrentThreadId();
  if ( CurrentThreadId != (CVProfile *)*v3 && _InterlockedCompareExchange(v3, (signed __int32)CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: (int)v3, a2: CurrentThreadId, dwMilliseconds: 0);
  }
  else
  {
    ++v3[1];
  }
  v15 = 0;
  v5 = (struct IVProfileCallbackHandler **)this->m_GroupIDStack[667];
  v6 = &this->m_GroupIDStack[666];
  if ( (unsigned int)v5 > v6[2] )
    _invalid_parameter_noinfo_0();
  while ( 1 )
  {
    v13 = (struct IVProfileCallbackHandler **)v6[2];
    if ( v6[1] > (unsigned int)v13 )
    {
      _invalid_parameter_noinfo_0();
      v3 = v12;
    }
    if ( v6 == nullptr )
    {
      _invalid_parameter_noinfo_0();
      v3 = v12;
    }
    if ( v5 == v13 )
      break;
    if ( v6 == nullptr )
    {
      _invalid_parameter_noinfo_0();
      v3 = v12;
    }
    if ( (unsigned int)v5 >= v6[2] )
    {
      _invalid_parameter_noinfo_0();
      v3 = v12;
    }
    if ( *v5 == a2 )
      goto LABEL_29;
    if ( (unsigned int)v5 >= v6[2] )
    {
      _invalid_parameter_noinfo_0();
      v3 = v12;
    }
    ++v5;
  }
  v7 = v6[1];
  if ( v7 != 0 )
    v8 = (int)(v6[2] - v7) >> 2;
  else
    v8 = 0;
  if ( v7 != 0 && v8 < (int)(v6[3] - v7) >> 2 )
  {
    v9 = (_DWORD *)v6[2];
    *v9 = a2;
    v6[2] = (int)(v9 + 1);
  }
  else
  {
    v10 = v6[2];
    if ( v7 > v10 )
      _invalid_parameter_noinfo_0();
    ((void (__stdcall *)(_BYTE *, struct IVProfileCallbackHandler **, int *, unsigned int))loc_3F0190F0)(
      a1: v14,
      &a2,
      a3: v6,
      a4: v10);
  }
LABEL_29:
  v15 = -1;
  if ( v3[1]-- == 1 )
    _InterlockedExchange(v3, 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F0171D0
// Name: public: class CVProfNode __near * CVProfile::FindNode(class CVProfNode __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn CVProfile::FindNode(CVProfile *this, struct CVProfNode *a2, char *Str2)
{
  if ( a2->m_pszName == nullptr )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: m_pszName",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
      a4: 1026,
      a5: &`CVProfNode::GetName'::`7'::fDumped,
      a6: 0);
  sub_3F01D502(Str1: (unsigned __int8 *)a2->m_pszName, (unsigned __int8 *)Str2);
}

//------------------------------------------------------------------------------
// Address: 0x3F017250
// Name: protected: void CVProfile::SumTimes(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::SumTimes(CVProfile *this, const char *a2, int a3)
{
  struct CVProfNode *v4; // eax

  v4 = (struct CVProfNode *)this->m_GroupIDStack[1];
  if ( v4->m_pChild != nullptr )
  {
    if ( a2 != nullptr )
      this->m_GroupIDStack[662] = 0;
    else
      this->m_GroupIDStack[662] = (int)v4;
    this->m_GroupIDStack[663] = (int)a2;
    CVProfile::SumTimes(this, a2: v4, a3);
    this->m_GroupIDStack[662] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0172A0
// Name: protected: void CVProfile::DumpNodes(class CVProfNode __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn CVProfile::DumpNodes(CVProfile *this, struct CVProfNode *a2, int a3, bool a4)
{
  if ( a2 == nullptr )
    JUMPOUT(0x3F0172B5);
  JUMPOUT(0x3F0172C2);
}

//------------------------------------------------------------------------------
// Address: 0x3F017900
// Name: public: double CVProfile::GetFrameTimeOutsideBudgetGroup_Recursive(class CVProfNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVProfile::GetFrameTimeOutsideBudgetGroup_Recursive(CVProfile *this, struct CVProfNode *a2, int a3)
{
  double result; // st7
  struct CVProfNode *m_pSibling; // eax
  struct CVProfNode *m_pChild; // esi
  double v7; // [esp+Ch] [ebp-8h]

  result = 0.0;
  v7 = 0.0;
  if ( a2 != nullptr )
  {
    result = 0.0;
    if ( (int)a2->m_nCurFrameCalls > 0 && a2->m_iClientData != a3 )
    {
      result = CVProfNode::GetCurTimeLessChildren(this: a2) + *(double *)&GS_ExceptionRecord.NumberParameters;
      v7 = result;
    }
    m_pSibling = a2->m_pSibling;
    if ( m_pSibling != nullptr )
    {
      result = CVProfile::GetFrameTimeOutsideBudgetGroup_Recursive(this, a2: m_pSibling, a3) + v7;
      v7 = result;
    }
    m_pChild = a2->m_pChild;
    if ( m_pChild != nullptr )
      return CVProfile::GetFrameTimeOutsideBudgetGroup_Recursive(this, a2: m_pChild, a3) + v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F017980
// Name: public: void CVProfile::OutputReport(int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVProfile::OutputReport(int a1)
{
  CVProfile *this; // ecx
  CVProfile *v2; // esi
  CVProfile *CurrentThreadId; // ecx
  int *v4; // eax
  int v5; // eax
  int v6; // ecx
  struct CVProfNode *v7; // edi
  int v8; // eax

  v2 = this;
  CurrentThreadId = (CVProfile *)GetCurrentThreadId();
  if ( CurrentThreadId != (CVProfile *)dword_3F041A0C
    && _InterlockedCompareExchange(&dword_3F041A0C, (signed __int32)CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: (int)&dword_3F041A0C, a2: CurrentThreadId, dwMilliseconds: 0);
  }
  else
  {
    ++dword_3F041A10;
  }
  v4 = (int *)v2->m_GroupIDStack[651];
  if ( v4 != nullptr )
    v5 = *v4;
  else
    v5 = 0;
  Msg(a1: (int)&IVCRTrace `RTTI Type Descriptor', v5, &v2->m_GroupIDStack[587]);
  if ( v2->m_GroupIDStack[2] == 0
    || (double)*(__int64 *)((v6 = v2->m_GroupIDStack[1]) + 96) * g_ClockSpeedMillisecondsMultiplier == *(double *)&GS_ExceptionRecord.NumberParameters )
  {
    JUMPOUT(0x3F017D99);
  }
  if ( v6 != 0 )
    v7 = *(struct CVProfNode **)(v6 + 116);
  else
    v7 = nullptr;
  if ( v7 == nullptr
    || (v8 = CVProfile::BudgetGroupNameToBudgetGroupID(this: v2, a2: "Sleeping"),
        !CVProfile::BProfileHasNodesOutsideBudgetGroup_Recursive(this: v2, a2: v7, a3: v8)) )
  {
    JUMPOUT(0x3F017D92);
  }
  if ( (a1 & 1) == 0 )
    JUMPOUT(0x3F017B48);
  Msg(a1: (int)&DoubleFormat);
  Msg(
    a1: (int)&DoubleFormat.format_width,
    v2->m_GroupIDStack[2],
    (double)*(__int64 *)(v2->m_GroupIDStack[1] + 96) * g_ClockSpeedMillisecondsMultiplier / 1000.0);
  _setmbcp(codepage: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F0181A0
// Name: public: void CVProfile::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::Term(CVProfile *this)
{
  int i; // edi
  bool v3; // zf
  bool v4; // sf

  if ( this->m_GroupIDStack[5] != 0 )
  {
    for ( i = 0; i < this->m_GroupIDStack[7]; ++i )
      j_j__free(Block: *(void **)(this->m_GroupIDStack[5] + 8 * i));
    j__free(Block: (void *)this->m_GroupIDStack[5]);
  }
  v3 = this->m_GroupIDStack[586] == 0;
  v4 = this->m_GroupIDStack[586] < 0;
  this->m_GroupIDStack[6] = 0;
  this->m_GroupIDStack[7] = 0;
  this->m_GroupIDStack[5] = 0;
  if ( !v4 && !v3 )
    JUMPOUT(0x3F01820C);
  JUMPOUT(0x3F018253);
}

//------------------------------------------------------------------------------
// Address: 0x3F0182F0
// Name: public: unsigned int CVProfile::GetThreadID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVProfile::GetThreadID(CVProfile *this)
{
  int v1; // eax

  v1 = this->m_GroupIDStack[651];
  if ( v1 != 0 )
    return *(_DWORD *)v1;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F018300
// Name: public: void CVProfile::GetBudgetGroupColor(int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::GetBudgetGroupColor(CVProfile *this, int a2, int *a3, int *a4, int *a5, int *a6)
{
  *a3 = dword_3F03C0B0[(a2 % 64) & 1 | ((a2 % 64) >> 4) & 2];
  *a4 = dword_3F03C0B0[((a2 % 64) & 2 | ((a2 % 64) >> 2) & 4) >> 1];
  *a5 = dword_3F03C0B0[((a2 % 64) >> 2) & 3];
  *a6 = 255;
}

//------------------------------------------------------------------------------
// Address: 0x3F018370
// Name: protected: int CVProfile::FindBudgetGroupName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::FindBudgetGroupName(CVProfile *this, const char *fh)
{
  if ( this->m_GroupIDStack[5] == 0 )
    CVProfile::CreateBudgetGroups(this);
  if ( this->m_GroupIDStack[7] > 0 )
    _close((int)fh);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F0184B0
// Name: public: int CVProfile::BudgetGroupNameToBudgetGroupID(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::BudgetGroupNameToBudgetGroupID(CVProfile *this, char *a2, int a3)
{
  int result; // eax

  if ( this->m_GroupIDStack[5] == 0 )
    CVProfile::CreateBudgetGroups(this);
  result = CVProfile::FindBudgetGroupName(this, fh: a2);
  if ( result == -1 )
    return ((int (__thiscall *)(CVProfile *, char *, int))_LN17_1)(a1: this, a2, a3);
  *(_DWORD *)(this->m_GroupIDStack[5] + 8 * result + 4) |= a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F018500
// Name: public: int CVProfile::BudgetGroupNameToBudgetGroupID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::BudgetGroupNameToBudgetGroupID(CVProfile *this, char *a2)
{
  int result; // eax

  if ( this->m_GroupIDStack[5] == 0 )
    CVProfile::CreateBudgetGroups(this);
  result = CVProfile::FindBudgetGroupName(this, fh: a2);
  if ( result == -1 )
    return ((int (__thiscall *)(CVProfile *, char *, int))_LN17_1)(a1: this, a2, a3: 4);
  *(_DWORD *)(this->m_GroupIDStack[5] + 8 * result + 4) |= 4u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F018550
// Name: public: void CVProfile::RegisterNumBudgetGroupsChangedCallBack(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::RegisterNumBudgetGroupsChangedCallBack(CVProfile *this, void (__cdecl *a2)())
{
  this->m_GroupIDStack[8] = (int)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F018560
// Name: public: int __near * CVProfile::FindOrCreateCounter(char const __near *,enum CounterGroup_t)
// Source: json
//------------------------------------------------------------------------------
int *__userpurge CVProfile::FindOrCreateCounter@<eax>(
        CVProfile *this@<ecx>,
        const char *a2,
        unsigned int a3,
        const char *a4,
        int a5,
        char *a6,
        int a7,
        int a8,
        int a9)
{
  int v10; // eax

  if ( this->m_GroupIDStack[586] + 1 >= 256 )
    ((void (__cdecl *)(unsigned int *, _DWORD, unsigned int *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &_S1,
      a2: 0,
      a3: &under[1],
      a4: 1210,
      a5: &unk_3F041A9B,
      a6: 0);
  v10 = this->m_GroupIDStack[586];
  if ( v10 + 1 < 256 )
  {
    if ( v10 > 0 )
      _crtLCMapStringA_stat(
        plocinfo: (localeinfo_struct *)(v10 + 1),
        Locale: (unsigned int)a2,
        dwMapFlags: a3,
        lpSrcStr: a4,
        cchSrc: a5,
        lpDestStr: a6,
        cchDest: a7,
        code_page: a8,
        bError: a9);
    JUMPOUT(0x3F0185E5);
  }
  return (int *)&unk_3F0A3614;
}

//------------------------------------------------------------------------------
// Address: 0x3F018670
// Name: public: void CVProfile::ResetCounters(enum CounterGroup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfile::ResetCounters(CVProfile *this, enum CounterGroup_t a2)
{
  int v2; // eax
  int *v3; // edx

  v2 = 0;
  if ( this->m_GroupIDStack[586] > 0 )
  {
    v3 = &this->m_GroupIDStack[10];
    do
    {
      if ( *((char *)&this->m_GroupIDStack[266] + v2) == a2 )
        *v3 = 0;
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_GroupIDStack[586] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0186C0
// Name: public: int CVProfile::GetNumCounters(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::GetNumCounters(CVProfile *this)
{
  return this->m_GroupIDStack[586];
}

//------------------------------------------------------------------------------
// Address: 0x3F0186D0
// Name: public: char const __near * CVProfile::GetCounterName(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVProfile::GetCounterName(CVProfile *this, int a2)
{
  if ( a2 < 0 || a2 >= this->m_GroupIDStack[586] )
    ((void (__cdecl *)(char ***, _DWORD, unsigned int *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &__initenv,
      a2: 0,
      a3: &under[1],
      a4: 1252,
      a5: &unk_3F041A9C,
      a6: 0);
  return (const char *)this->m_GroupIDStack[a2 + 330];
}

//------------------------------------------------------------------------------
// Address: 0x3F018720
// Name: public: int CVProfile::GetCounterValue(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfile::GetCounterValue(CVProfile *this, int a2)
{
  if ( a2 < 0 || a2 >= this->m_GroupIDStack[586] )
    ((void (__cdecl *)(char ***, _DWORD, unsigned int *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &__initenv,
      a2: 0,
      a3: &under[1],
      a4: 1258,
      a5: &unk_3F041A9D,
      a6: 0);
  return this->m_GroupIDStack[a2 + 10];
}

//------------------------------------------------------------------------------
// Address: 0x3F018760
// Name: public: char const __near * CVProfile::GetCounterNameAndValue(int,int __near &)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVProfile::GetCounterNameAndValue(CVProfile *this, int a2, int *a3)
{
  if ( a2 < 0 || a2 >= this->m_GroupIDStack[586] )
    ((void (__cdecl *)(char ***, _DWORD, unsigned int *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &__initenv,
      a2: 0,
      a3: &under[1],
      a4: 1264,
      a5: &unk_3F041A9E,
      a6: 0);
  *a3 = this->m_GroupIDStack[a2 + 10];
  return (const char *)this->m_GroupIDStack[a2 + 330];
}

//------------------------------------------------------------------------------
// Address: 0x3F01D1AD
// Name: public: virtual char const __near * exception::what(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall exception::what(exception *this)
{
  const char *result; // eax

  result = *((const char **)this + 1);
  if ( result == nullptr )
    return "Unknown exception";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00ED40
// Name: ?ExitScope@CVProfNode@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge CVProfNode::ExitScope@<eax>(CVProfNode *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4, int a5)
{
  bool v5; // zf
  int result; // eax
  int v7; // ecx

  v5 = (*(_DWORD *)(a2 + 1031805124))++ == -1;
  result = *(_DWORD *)(a3 + 12);
  v7 = *(_DWORD *)(a3 + 8);
  dword_3F0415C4 = result;
  dword_3F0415C8 = v7;
  if ( v5 )
    return ((int (*)(void))loc_3F00ECB0)();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EDD0
// Name: ?Pause@CVProfNode@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfNode::Pause(CVProfNode *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EE80
// Name: ?Resume@CVProfNode@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfNode::Resume(CVProfNode *this)
{
  hObject = nullptr;
  byte_3F0415B8 = 0;
  byte_3F0415B9 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00EEA0
// Name: StartAddress
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall StartAddress(void (__stdcall **a1)(_DWORD))
{
  void (__stdcall *v2)(_DWORD); // [esp-4h] [ebp-8h]

  ((void (*)(void))loc_3F00EDE0)();
  a1[7](a1: a1[6]);
  v2 = a1[2];
  *a1 = nullptr;
  *((_BYTE *)a1 + 12) = 0;
  *((_BYTE *)a1 + 13) = 0;
  SetEvent(hEvent: v2);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F1E0
// Name: ThreadTerminateProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl ThreadTerminateProcess(DWORD dwProcessId)
{
  bool v1; // bl
  HANDLE v2; // eax
  void *v3; // esi

  v1 = false;
  v2 = OpenProcess(dwDesiredAccess: 1u, bInheritHandle: false, dwProcessId);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v1 = TerminateProcess(hProcess: v2, uExitCode: 0);
    CloseHandle(hObject: v3);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F2B0
// Name: ThreadShellExecute
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ThreadShellExecute(const char *a1, const char *a2, const char *a3)
{
  int v3; // esi
  SHELLEXECUTEINFOA pExecInfo; // [esp+4h] [ebp-3Ch] BYREF

  v3 = 0;
  memset_0(a1: &pExecInfo.fMask, Val: 0, Size: 0x38u);
  pExecInfo.lpFile = a1;
  pExecInfo.cbSize = 60;
  pExecInfo.fMask = 64;
  pExecInfo.hwnd = nullptr;
  pExecInfo.lpVerb = nullptr;
  pExecInfo.lpParameters = a2;
  pExecInfo.lpDirectory = a3;
  pExecInfo.nShow = 10;
  pExecInfo.hInstApp = nullptr;
  pExecInfo.hProcess = nullptr;
  if ( ShellExecuteExA(&pExecInfo) && pExecInfo.hProcess != nullptr )
  {
    v3 = ((int (__cdecl *)(HANDLE))loc_3F00F220)(a1: pExecInfo.hProcess);
    CloseHandle(hObject: pExecInfo.hProcess);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F330
// Name: ?SumTimes@CVProfile@@IAEXPAVCVProfNode@@H@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HANDLE __stdcall CVProfile::SumTimes()
{
  return GetCurrentThread();
}

//------------------------------------------------------------------------------
// Address: 0x3F00F340
// Name: ThreadIsThreadIdRunning
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ThreadIsThreadIdRunning(DWORD dwThreadId)
{
  char v1; // bl
  HANDLE v2; // eax
  void *v3; // esi
  unsigned int ExitCode; // [esp+8h] [ebp-4h] BYREF

  v1 = 1;
  v2 = OpenThread(dwDesiredAccess: 0x40u, bInheritHandle: false, dwThreadId);
  v3 = v2;
  if ( v2 == nullptr )
    return 0;
  if ( !GetExitCodeThread(hThread: v2, lpExitCode: &ExitCode) || ExitCode != 259 )
    v1 = 0;
  CloseHandle(hObject: v3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F010270
// Name: ?CreateBudgetGroups@CVProfile@@IAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfile::CreateBudgetGroups(CVProfile *this@<ecx>, __int16 _DX@<dx>, int a3@<ebx>, int a4@<esi>)
{
  int v5; // esi

  __asm { insb }
  ++*(_DWORD *)(a3 - 1946221498);
  v5 = a4 + 1;
  _InterlockedExchange((volatile __int32 *)v5, 0);
  if ( (_BYTE)a3 != 0 )
    CThreadSyncObject::Wait(this: (CThreadSyncObject *)(v5 + 8), a2: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x3F010880
// Name: ?RegisterNumBudgetGroupsChangedCallBack@CVProfile@@QAEXP6AXXZ@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfile::RegisterNumBudgetGroupsChangedCallBack(
        CVProfile *this@<ecx>,
        void (__cdecl *pCallBack)(),
        CounterGroup_t a3)
{
  CVProfile::FindOrCreateCounter(this, pName: (const char *)pCallBack, eCounterGroup: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F010890
// Name: ?FindOrCreateCounter@CVProfile@@QAEPAHPBDW4CounterGroup_t@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__usercall CVProfile::FindOrCreateCounter@<eax>(CVProfile *this@<ecx>, int a2@<ebp>)
{
  int *result; // eax

  *(_DWORD *)(a2 - 16) = dwTlsIndex;
  *(_DWORD *)(a2 - 4) = -1;
  result = (int *)dwTlsIndex[0];
  if ( dwTlsIndex[0] != -1 )
    result = (int *)TlsFree(dwTlsIndex: dwTlsIndex[0]);
  dwTlsIndex[0] = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01122F
// Name: nullsub_9
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_9()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0112AF
// Name: sub_3F0112AF
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn sub_3F0112AF(int a1@<ebp>)
{
  CThreadEvent::Set(this: *(CThreadEvent **)(*(_DWORD *)(a1 + 8) + 4));
  _CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F0118C0
// Name: public: class std::_Vector_iterator<struct TimeSums_t,class std::allocator<struct TimeSums_t>> std::vector<struct TimeSums_t,class std::allocator<struct TimeSums_t>>::erase(class std::_Vector_iterator<struct TimeSums_t,class std::allocator<struct TimeSums_t>>,class std::_Vector_iterator<struct TimeSums_t,class std::allocator<struct TimeSums_t>>)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge std::vector<TimeSums_t>::erase(
        std::vector<TimeSums_t> *this@<ecx>,
        std::vector<TimeSums_t> *result,
        std::_Vector_iterator<TimeSums_t> _First,
        std::_Vector_iterator<TimeSums_t> _Last)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F012770
// Name: sub_3F012770
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F012770(int a1)
{
  unsigned __int16 v1; // ax
  int v3; // [esp+0h] [ebp-4h] BYREF

  HIBYTE(a1) = a1;
  v1 = sub_3F012550();
  v3 = v1;
  if ( v1 != 0 )
  {
    HIBYTE(a1) |= 0x80u;
    fwrite_0(Buffer: (char *)&a1 + 3, ElementSize: 1u, ElementCount: 1u, Stream: Stream);
    fflush(Stream: Stream);
    fwrite_0(Buffer: &v3, ElementSize: 1u, ElementCount: 2u, Stream: Stream);
    return fflush(Stream: Stream);
  }
  else
  {
    fwrite_0(Buffer: (char *)&a1 + 3, ElementSize: 1u, ElementCount: 1u, Stream: Stream);
    return fflush(Stream: Stream);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0127F0
// Name: sub_3F0127F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F0127F0()
{
  return dword_3F03C0C4;
}

//------------------------------------------------------------------------------
// Address: 0x3F012800
// Name: sub_3F012800
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_3F012800(int a1, int a2)
{
  return ((int (__thiscall *)(int))loc_3F012670)(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F012820
// Name: sub_3F012820
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F012820(int a1, char a2, int a3)
{
  HANDLE EventA; // eax
  int v4; // ecx
  void (*v5)(void); // ecx
  const char *CommandLineA; // eax
  FILE *v7; // eax
  FILE *v9; // eax
  int Buffer; // [esp+8h] [ebp-4h] BYREF

  dword_3F03D408 = GetCurrentThreadId();
  byte_3F03D3C7 = 1;
  dword_3F03D400 = ((int (__cdecl *)(int))byte_3F01A077)(a1: 6144);
  *(_DWORD *)dword_3F03D400 = GetCurrentThreadId();
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset: false, bInitialState: false, lpName: nullptr);
  v4 = dword_3F03D400;
  *(_DWORD *)(dword_3F03D400 + 4) = EventA;
  *(_BYTE *)(v4 + 8) = 1;
  v5 = *((void (**)(void))g_pVCR + 1);
  dword_3F03D404 = 1;
  dword_3F03D3E8 = a3;
  v5();
  dword_3F03C0C0 = -1;
  if ( a2 != 0 )
  {
    CommandLineA = GetCommandLineA();
    if ( strstr(Str: CommandLineA, SubStr: (const char *)&locktable[4]) == nullptr )
      Error(a1: (int)&locktable[5].kind);
    v7 = (FILE *)((int (__cdecl *)(int, $D283E5A92EBEB600100C8EBC9C67A011 *))loc_3F01D719)(a1, a2: &locktable[9].kind);
    Stream = v7;
    if ( v7 != nullptr )
    {
      Buffer = 2;
      fwrite_0(&Buffer, ElementSize: 1u, ElementCount: 4u, Stream: v7);
      fflush(Stream: Stream);
      ElementSize = 1;
      return 1;
    }
    return 0;
  }
  v9 = (FILE *)((int (__cdecl *)(int, $BCB77B5D4E58F0838C6B555B44D1750B *))loc_3F01D719)(a1, a2: &locktable[10]);
  Stream = v9;
  if ( v9 == nullptr )
    return 0;
  ((void (__cdecl *)(FILE *, _DWORD, int))loc_3F01DE25)(a1: v9, a2: 0, a3: 2);
  dword_3F03D3FC = ftell_0(Stream: Stream);
  ((void (__cdecl *)(FILE *, _DWORD, _DWORD))loc_3F01DE25)(a1: Stream, a2: 0, a3: 0);
  dword_3F03D3F8 = 0;
  ((void (__thiscall *)(int *))loc_3F012670)(a1: &Buffer);
  if ( Buffer != 2 )
  {
    (*((void (**)(void))g_pVCR + 1))();
    return 0;
  }
  ElementSize = 2;
  ((void (*)(void))loc_3F0126F0)();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F013070
// Name: sub_3F013070
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F013070(char a1, char a2, char a3)
{
  int v3; // ecx
  size_t v4; // eax
  unsigned __int16 v5; // ax
  int v6; // [esp-2h] [ebp-10h] BYREF
  int v7; // [esp+Ah] [ebp-4h]

  v6 = v3;
  if ( ElementSize == 0
    || byte_3F03D3C7 == 0
    || *(_BYTE *)(dword_3F03D400 + 12 * (unsigned __int16)sub_3F012550() + 8) == 0 )
  {
    return;
  }
  v4 = ElementSize;
  BYTE2(v6) = 0;
  if ( ElementSize == 1 )
  {
    EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
LABEL_8:
    v4 = ElementSize;
    goto LABEL_9;
  }
  if ( ElementSize == 2 )
  {
    v5 = sub_3F012550();
    WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v5 + 4), dwMilliseconds: 0xFFFFFFFF);
    goto LABEL_8;
  }
LABEL_9:
  v7 = 0;
  if ( v4 == 1 )
  {
    ++dword_3F03D3F4;
    sub_3F012770(a1: 14);
    HIBYTE(v6) = 1;
    fwrite_0(Buffer: (char *)&v6 + 3, ElementSize: 1u, ElementCount: 1u, Stream: Stream);
    fflush(Stream: Stream);
    fwrite_0(Buffer: &a1, ElementSize: 1u, ElementCount: 4u, Stream: Stream);
    fflush(Stream: Stream);
    fwrite_0(Buffer: &a2, ElementSize: 1u, ElementCount: 4u, Stream: Stream);
    fflush(Stream: Stream);
    fwrite_0(Buffer: &a3, ElementSize: 1u, ElementCount: 4u, Stream: Stream);
    fflush(Stream: Stream);
    v4 = ElementSize;
  }
  v7 = -1;
  if ( v4 == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( v4 == 2 )
  {
    ((void (__cdecl *)(int))loc_3F0126F0)(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F013A9A
// Name: WSAGetLastError()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall WSAGetLastError()
{
  int v0; // eax
  _DWORD *v1; // ebx

  _EAX = v0 - *v1;
  __asm { aas }
  JUMPOUT(0x3F013AA0);
}

//------------------------------------------------------------------------------
// Address: 0x3F013AF0
// Name: public: static void std::_String_base::_Xran(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __cdecl std::_String_base::_Xran()
{
  JUMPOUT(0x3F013B70);
}

//------------------------------------------------------------------------------
// Address: 0x3F013B2F
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __security_check_cookie(char a1@<cf>, char a2@<zf>)
{
  if ( a1 | a2 )
    JUMPOUT(0x3F013B31);
  JUMPOUT(0x3F013ACE);
}

//------------------------------------------------------------------------------
// Address: 0x3F013B3E
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_LocaleUpdate *__usercall _LocaleUpdate::_LocaleUpdate@<eax>(_LocaleUpdate *this@<ecx>, int a2@<ebp>)
{
  _LocaleUpdate *v2; // esi

  *(_DWORD *)(a2 - 24) = WSAGetLastError();
  sub_3F016480(Buffer: (void *)(a2 - 24));
  v2 = *(_LocaleUpdate **)(a2 - 20);
  *(_DWORD *)(a2 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
    return v2;
  }
  else
  {
    if ( ElementSize == 2 )
      ((void (*)(void))loc_3F0126F0)();
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F013BC0
// Name: __mbsicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl _mbsicmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        localeinfo_struct *plocinfo,
        int flags)
{
  unsigned __int16 v4; // ax
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *v5; // ecx
  unsigned __int16 v7; // ax
  threadlocaleinfostruct *locinfo; // esi
  int iError; // [esp+0h] [ebp-18h] BYREF
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-14h] BYREF
  unsigned __int8 szResult[4]; // [esp+14h] [ebp-4h]

  if ( ElementSize == 0 )
    return (threadlocaleinfostruct *)send(s: (SOCKET)s1, buf: (const char *)s2, len: (int)plocinfo, flags);
  if ( byte_3F03D3C7 == 0 )
    return (threadlocaleinfostruct *)send(s: (SOCKET)s1, buf: (const char *)s2, len: (int)plocinfo, flags);
  v4 = sub_3F012550();
  v5 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)dword_3F03D400;
  if ( *(_BYTE *)(dword_3F03D400 + 12 * v4 + 8) == 0 )
    return (threadlocaleinfostruct *)send(s: (SOCKET)s1, buf: (const char *)s2, len: (int)plocinfo, flags);
  HIBYTE(_loc_update.localeinfo.mbcinfo) = 0;
  if ( ElementSize == 1 )
  {
    EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( ElementSize == 2 )
  {
    v7 = sub_3F012550();
    WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v7 + 4), dwMilliseconds: 0xFFFFFFFF);
  }
  *(_DWORD *)szResult = 0;
  if ( ElementSize != 0 )
  {
    ++dword_3F03D3F4;
    if ( ElementSize == 1 )
    {
      sub_3F012770(a1: 19);
    }
    else if ( dword_3F03C0C4 != 19 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: v5,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
  }
  if ( ElementSize == 2 )
  {
    ((void (__thiscall *)(_LocaleUpdate *))loc_3F012670)(a1: &_loc_update);
    if ( _loc_update.localeinfo.locinfo == (threadlocaleinfostruct *)-1 )
    {
      ((void (__thiscall *)(int *))loc_3F012670)(a1: &iError);
      WSASetLastError(iError);
    }
  }
  else
  {
    _loc_update.localeinfo.locinfo = (threadlocaleinfostruct *)send(
                                                                 s: (SOCKET)s1,
                                                                 buf: (const char *)s2,
                                                                 len: (int)plocinfo,
                                                                 flags);
    if ( ElementSize == 1 )
    {
      fwrite_0(Buffer: &_loc_update, ElementSize: 1u, ElementCount: 4u, Stream: Stream);
      fflush(Stream: Stream);
      if ( _loc_update.localeinfo.locinfo == (threadlocaleinfostruct *)-1 )
      {
        iError = WSAGetLastError();
        sub_3F016480(Buffer: &iError);
      }
    }
  }
  locinfo = _loc_update.localeinfo.locinfo;
  *(_DWORD *)szResult = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
    return locinfo;
  }
  else
  {
    if ( ElementSize == 2 )
      ((void (*)(void))loc_3F0126F0)();
    return locinfo;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F013DDA
// Name: __mbsicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__usercall _mbsicmp@<eax>(
        int _EAX@<eax>,
        char _CL@<cl>,
        int _EBX@<ebx>,
        int a4@<ebp>,
        _BYTE *a5@<edi>,
        unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int a8,
        localeinfo_struct *a9)
{
  *a5 += _CL;
  __asm
  {
    lock rol dword ptr [ebx+0], cl; "bad allocation"
    aas
  }
  *(_BYTE *)(a4 - 13) = 0;
  return _mbsnbcpy_l(dst: s1, src: s2, cnt: a8, plocinfo: a9);
}

//------------------------------------------------------------------------------
// Address: 0x3F013DED
// Name: __mbsnbcpy_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__usercall _mbsnbcpy_l@<eax>(
        char a1@<zf>,
        int a2@<eax>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a3@<ecx>,
        int a4@<ebp>,
        int a5@<esi>,
        unsigned __int8 *dst,
        unsigned __int8 *src,
        const unsigned __int8 *cnt)
{
  unsigned __int16 v8; // ax
  int v9; // eax
  int v10; // eax

  if ( a1 )
  {
    EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( a2 == 2 )
  {
    v8 = sub_3F012550();
    WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v8 + 4), dwMilliseconds: 0xFFFFFFFF);
  }
  *(_DWORD *)(a4 - 4) = 0;
  if ( ElementSize != 0 )
  {
    ++dword_3F03D3F4;
    if ( ElementSize == 1 )
    {
      sub_3F012770(a1: 6);
    }
    else if ( dword_3F03C0C4 != 6 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: a3,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
  }
  if ( ElementSize == 2 )
  {
    ((void (__thiscall *)(int, int))loc_3F012670)(a1: a4 - 20, a2: a5);
    v9 = *(_DWORD *)(a4 - 20);
    if ( v9 == -1 )
    {
      **(_DWORD **)(a4 + 8) = 0;
    }
    else
    {
      v10 = (*(int (__thiscall **)(int, int, $D283E5A92EBEB600100C8EBC9C67A011 *, int, _DWORD, _DWORD))(*(_DWORD *)g_pMemAllocSteam + 4))(
              a1: g_pMemAllocSteam,
              a2: v9,
              a3: &locktable[19].kind,
              a4: 954,
              a5: 0,
              a6: 0);
      **(_DWORD **)(a4 + 8) = v10;
      ((void (__thiscall *)(int))loc_3F012670)(a1: v10);
    }
LABEL_16:
    JUMPOUT(0x3F013F53);
  }
  if ( ElementSize != 1 )
    goto LABEL_16;
  return _mbsnbcpy(dst, src, (unsigned int)cnt);
}

//------------------------------------------------------------------------------
// Address: 0x3F013ECE
// Name: __mbsnbcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__usercall _mbsnbcpy@<eax>(
        const char *a1@<esi>,
        unsigned __int8 *dst,
        const unsigned __int8 *src,
        localeinfo_struct *cnt)
{
  if ( a1 == nullptr )
    JUMPOUT(0x3F013F2A);
  strlen(a1);
  return (unsigned __int8 *)_mbsstr_l(str1: dst, str2: src, plocinfo: cnt);
}

//------------------------------------------------------------------------------
// Address: 0x3F013EE5
// Name: __mbsstr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _mbsstr_l(int a1@<eax>, int a2@<ebp>, const void *a3@<esi>)
{
  *(_DWORD *)(a2 - 20) = a1;
  fwrite_0(Buffer: (const void *)(a2 - 20), ElementSize: 1u, ElementCount: 4u, Stream: Stream);
  fflush(Stream: Stream);
  fwrite_0(Buffer: a3, ElementSize: 1u, ElementCount: *(_DWORD *)(a2 - 20), Stream: Stream);
  fflush(Stream: Stream);
  *(_DWORD *)(a2 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( ElementSize == 2 )
  {
    ((void (*)(void))loc_3F0126F0)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F014024
// Name: __mbsstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsstr(int a1@<ebp>, int a2@<esi>)
{
  *(_DWORD *)(a1 + 12) += a2;
  sub_3F012770(a1: 7);
  JUMPOUT(0x3F01404F);
}

//------------------------------------------------------------------------------
// Address: 0x3F014037
// Name: void operator delete(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall operator delete(_BYTE *a1@<ebx>)
{
  *a1 = __ROL1__(*a1, 63);
  JUMPOUT(0x3F01403B);
}

//------------------------------------------------------------------------------
// Address: 0x3F014055
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall operator new(int a1@<edx>, int a2@<ebp>)
{
  int v2; // eax

  BYTE1(a1) += *(_BYTE *)(a2 + 39);
  ((void (__fastcall *)(int, int))loc_3F012670)(a1: a2 - 20, a2: a1);
  v2 = ((int (__cdecl *)(_DWORD))byte_3F01A077)(a1: *(_DWORD *)(a2 - 20));
  ((void (__thiscall *)(int))loc_3F012670)(a1: v2);
  JUMPOUT(0x3F0140CD);
}

//------------------------------------------------------------------------------
// Address: 0x3F0140BF
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall sprintf@<eax>(FILE *a1@<edx>, int a2@<ebp>, int a3@<edi>, char *string, char *format, ...)
{
  fflush(Stream: a1);
  *(_DWORD *)(a2 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
    return a3;
  }
  else
  {
    if ( ElementSize == 2 && *(_BYTE *)(a2 - 13) == 0 )
      ((void (*)(void))loc_3F0126F0)();
    return a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F014140
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall memmove(int _EAX@<eax>, char a2@<dh>, int a3@<ecx>, int a4@<ebx>)
{
  __asm { aas }
  *(_BYTE *)(a3 - 128) += a2;
  *(_BYTE *)(_EAX + a4 - 24) += a2;
  JUMPOUT(0x3F01414E);
}

//------------------------------------------------------------------------------
// Address: 0x3F0144A5
// Name: __snprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
LSTATUS __usercall _snprintf@<eax>(
        int a1@<eax>,
        int a2@<ecx>,
        int a3@<ebp>,
        int a4@<edi>,
        char *string,
        char *count,
        const char *format,
        ...)
{
  size_t v8; // eax
  bool v9; // zf
  unsigned __int16 v10; // ax

  if ( *(_BYTE *)(a2 + 12 * (unsigned __int16)((unsigned int)&dword_3F03D400 | a1) + 8) != 0 )
  {
    v8 = ElementSize;
    v9 = ElementSize == 1;
    *(_BYTE *)(a3 - 13) = 0;
    if ( v9 )
    {
      EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
    }
    else if ( v8 == 2 )
    {
      v10 = sub_3F012550();
      WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v10 + 4), dwMilliseconds: 0xFFFFFFFF);
    }
    *(_DWORD *)(a3 - 4) = a4;
    if ( ElementSize != a4 )
    {
      ++dword_3F03D3F4;
      if ( ElementSize == 1 )
      {
        sub_3F012770(a1: 10);
      }
      else if ( dword_3F03C0C4 != 10 )
      {
        JUMPOUT(0x3F014551);
      }
    }
    JUMPOUT(0x3F014563);
  }
  return RegQueryValueExA(
           hKey: *(HKEY *)(a3 + 8),
           lpValueName: *(LPCSTR *)(a3 + 12),
           lpReserved: *(LPDWORD *)(a3 + 16),
           lpType: *(LPDWORD *)(a3 + 20),
           lpData: *(LPBYTE *)(a3 + 24),
           lpcbData: *(LPDWORD *)(a3 + 28));
}

//------------------------------------------------------------------------------
// Address: 0x3F014552
// Name: __mbsrchr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _mbsrchr_l(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a1@<ecx>,
        int a2@<ebp>,
        _DWORD *a3@<edi>,
        int a4@<esi>)
{
  char *v4; // edi
  bool v5; // zf
  char *v6; // ecx
  unsigned int *v7; // edi
  LSTATUS Value; // eax
  char r; // [esp+10h] [ebp-4h]

  v4 = (char *)a3 + *a3;
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
    this: a1,
    a2: 1748960043,
    a3: r);
  v5 = ElementSize == 2;
  *(_DWORD *)(a2 - 24) = v4;
  if ( v5 )
  {
    ((void (__thiscall *)(int, int))loc_3F012670)(a1: a2 - 20, a2: a4);
    v6 = *(char **)(a2 + 20);
    if ( v6 == v4 )
      v6 = (char *)(a2 - 24);
    ((void (__fastcall *)(char *))loc_3F012670)(a1: v6);
    ((void (__thiscall *)(_DWORD))loc_3F012670)(a1: *(_DWORD *)(a2 + 28));
    ((void (__thiscall *)(_DWORD))loc_3F012670)(a1: *(_DWORD *)(a2 + 24));
    JUMPOUT(0x3F014658);
  }
  v7 = *(unsigned int **)(a2 + 20);
  Value = RegQueryValueExA(
            hKey: *(HKEY *)(a2 + 8),
            lpValueName: *(LPCSTR *)(a2 + 12),
            lpReserved: *(LPDWORD *)(a2 + 16),
            lpType: v7,
            lpData: *(LPBYTE *)(a2 + 24),
            lpcbData: *(LPDWORD *)(a2 + 28));
  v5 = ElementSize == 1;
  *(_DWORD *)(a2 - 20) = Value;
  if ( v5 )
  {
    fwrite_0(Buffer: (const void *)(a2 - 20), ElementSize: 1u, ElementCount: 4u, Stream: Stream);
    fflush(Stream: Stream);
    if ( v7 == nullptr )
      v7 = (unsigned int *)(a2 - 24);
    fwrite_0(Buffer: v7, ElementSize: 1u, ElementCount: 4u, Stream: Stream);
    JUMPOUT(0x3F01460F);
  }
  JUMPOUT(0x3F014657);
}

//------------------------------------------------------------------------------
// Address: 0x3F014612
// Name: __mbsrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F014625
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall printf@<eax>(const void *a1@<ebx>, int a2@<ebp>, size_t *a3@<esi>, const char *format, ...)
{
  int v4; // esi
  const void *v6; // [esp-18h] [ebp-34h]
  size_t v7; // [esp-14h] [ebp-30h]
  size_t v8; // [esp-10h] [ebp-2Ch]
  FILE *v9; // [esp-Ch] [ebp-28h]

  fwrite_0(Buffer: v6, ElementSize: v7, ElementCount: v8, Stream: v9);
  fflush(Stream: Stream);
  fwrite_0(Buffer: a1, ElementSize: 1u, ElementCount: *a3, Stream: Stream);
  fflush(Stream: Stream);
  v4 = *(_DWORD *)(a2 - 20);
  *(_DWORD *)(a2 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
    return v4;
  }
  else
  {
    if ( ElementSize == 2 )
      ((void (*)(void))loc_3F0126F0)();
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0146D4
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _get_printf_count_output()
{
  if ( byte_3F03D3C7 != 0 )
  {
    sub_3F012550();
    JUMPOUT(0x3F0146E8);
  }
  JUMPOUT(0x3F0146F5);
}

//------------------------------------------------------------------------------
// Address: 0x3F0146EA
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_iobuf *__usercall _fsopen@<eax>(
        _BYTE *a1@<eax>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a2@<ecx>,
        int a3@<ebp>)
{
  bool v3; // zf
  size_t v5; // eax
  unsigned __int16 v6; // ax

  *(_BYTE *)(a3 + 2088779780) = __ROR1__(*(_BYTE *)(a3 + 2088779780), 129);
  v3 = ((unsigned __int8)a1 | *a1) == 0;
  *a1 |= (unsigned __int8)a1;
  if ( !v3 )
  {
    v5 = ElementSize;
    v3 = ElementSize == 1;
    *(_BYTE *)(a3 - 13) = 0;
    if ( v3 )
    {
      EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
    }
    else if ( v5 == 2 )
    {
      v6 = sub_3F012550();
      WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v6 + 4), dwMilliseconds: 0xFFFFFFFF);
    }
    *(_DWORD *)(a3 - 4) = 0;
    if ( ElementSize != 0 )
    {
      ++dword_3F03D3F4;
      if ( ElementSize == 1 )
      {
        sub_3F012770(a1: 11);
      }
      else if ( dword_3F03C0C4 != 11 )
      {
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
          this: a2,
          a2: (int)&rterrs[11].rterrtxt,
          a3: (char)&locktable[1]);
        JUMPOUT(0x3F0147AD);
      }
    }
    JUMPOUT(0x3F0147B0);
  }
  return (_iobuf *)RegCreateKeyExA(
                     hKey: *(HKEY *)(a3 + 8),
                     lpSubKey: *(LPCSTR *)(a3 + 12),
                     Reserved: *(_DWORD *)(a3 + 16),
                     lpClass: *(LPSTR *)(a3 + 20),
                     dwOptions: *(_DWORD *)(a3 + 24),
                     samDesired: *(_DWORD *)(a3 + 28),
                     lpSecurityAttributes: *(const LPSECURITY_ATTRIBUTES *)(a3 + 32),
                     phkResult: *(PHKEY *)(a3 + 36),
                     lpdwDisposition: *(LPDWORD *)(a3 + 40));
}

//------------------------------------------------------------------------------
// Address: 0x3F0147AE
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fopen()
{
  if ( ElementSize == 2 )
    JUMPOUT(0x3F0147BF);
  JUMPOUT(0x3F0147C9);
}

//------------------------------------------------------------------------------
// Address: 0x3F0147C1
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall fprintf@<eax>(unsigned __int16 a1@<dx>, int a2@<ebp>, _iobuf *str, _iobuf *format, ...)
{
  int v4; // esi

  __inbyte(a1);
  ((void (*)(void))loc_3F012670)();
  v4 = *(_DWORD *)(a2 - 20);
  *(_DWORD *)(a2 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
    return v4;
  }
  else
  {
    if ( ElementSize == 2 )
      ((void (*)(void))loc_3F0126F0)();
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F014910
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _vsnprintf_l(
        int _EAX@<eax>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a2@<ecx>,
        int a3@<ebp>)
{
  __asm { aas }
  *(_DWORD *)(a3 - 4) = 0;
  if ( _EAX != 0 )
  {
    ++dword_3F03D3F4;
    if ( _EAX == 1 )
    {
      sub_3F012770(a1: 12);
    }
    else
    {
      if ( dword_3F03C0C4 == 12 )
        goto LABEL_7;
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: a2,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
    _EAX = ElementSize;
  }
LABEL_7:
  if ( _EAX != 2 )
  {
    RegCloseKey(hKey: *(HKEY *)(a3 + 8));
    _EAX = ElementSize;
  }
  *(_DWORD *)(a3 - 4) = -1;
  if ( _EAX == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( _EAX == 2 )
  {
    ((void (*)(void))loc_3F0126F0)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0149C1
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _vsnprintf()
{
  if ( ElementSize != 0 && byte_3F03D3C7 != 0 )
    JUMPOUT(0x3F0149DB);
  JUMPOUT(0x3F0149F3);
}

//------------------------------------------------------------------------------
// Address: 0x3F0149DC
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fclose_nolock(char a1@<of>)
{
  if ( !a1 )
    JUMPOUT(0x3F0149DE);
  JUMPOUT(0x3F0149B9);
}

//------------------------------------------------------------------------------
// Address: 0x3F014A4E
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall fclose(
        int _EAX@<eax>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a2@<ecx>,
        int a3@<ebp>,
        int a4@<esi>)
{
  __asm { aas }
  *(_DWORD *)(a3 - 4) = 0;
  if ( ElementSize != 0 )
  {
    ++dword_3F03D3F4;
    if ( ElementSize == 1 )
    {
      sub_3F012770(a1: 15);
    }
    else if ( dword_3F03C0C4 != 15 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: a2,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
  }
  if ( ElementSize == 2 )
  {
    ((void (__thiscall *)(int, int))loc_3F012670)(a1: a3 - 13, a2: a4);
    ((void (__thiscall *)(_DWORD))loc_3F012670)(a1: *(_DWORD *)(a3 + 12));
    JUMPOUT(0x3F014B11);
  }
  GetNumberOfConsoleInputEvents(hConsoleInput: *(HANDLE *)(a3 + 8), lpNumberOfEvents: *(LPDWORD *)(a3 + 12));
  JUMPOUT(0x3F014AC6);
}

//------------------------------------------------------------------------------
// Address: 0x3F014ACA
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F014AEE
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __crtCorExitProcess(FILE *a1@<edx>, const void *a2@<esi>)
{
  fwrite_0(Buffer: a2, ElementSize: 1u, ElementCount: 4u, Stream: a1);
  fflush(Stream: Stream);
  JUMPOUT(0x3F014B11);
}

//------------------------------------------------------------------------------
// Address: 0x3F014B14
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __crtExitProcess(int a1@<ebp>)
{
  *(_DWORD *)(a1 - 4) = -1;
  if ( ElementSize == 1 )
    JUMPOUT(0x3F014B26);
  if ( ElementSize == 2 )
    ((void (*)(void))loc_3F0126F0)();
  JUMPOUT(0x3F014B52);
}

//------------------------------------------------------------------------------
// Address: 0x3F014B29
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _lockexit()
{
  _RTL_CRITICAL_SECTION *v0; // [esp-4h] [ebp-4h]

  LeaveCriticalSection(lpCriticalSection: v0);
  JUMPOUT(0x3F014B33);
}

//------------------------------------------------------------------------------
// Address: 0x3F014B53
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall _initterm_e(void *this)
{
  MEMORY[0] = this;
}

//------------------------------------------------------------------------------
// Address: 0x3F014B73
// Name: __get_osplatform
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _get_osplatform()
{
  if ( ElementSize != 0
    && byte_3F03D3C7 != 0
    && *(_BYTE *)(dword_3F03D400 + 12 * (unsigned __int16)sub_3F012550() + 8) != 0 )
  {
    JUMPOUT(0x3F014BC7);
  }
  JUMPOUT(0x3F014BA9);
}

//------------------------------------------------------------------------------
// Address: 0x3F014BAA
// Name: __get_winmajor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
BOOL __usercall _get_winmajor@<eax>(DWORD a1@<eax>, _INPUT_RECORD *a2@<ecx>, int a3@<ebp>)
{
  unsigned int *v4; // [esp-8h] [ebp-8h]

  LOBYTE(a1) = a1 | 0x52;
  return ReadConsoleInputA(hConsoleInput: *(HANDLE *)(a3 - 1 + 8), lpBuffer: a2, nLength: a1, lpNumberOfEventsRead: v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F014BE6
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _cinit(
        int a1@<eax>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a2@<ecx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  unsigned __int16 v5; // ax

  if ( a1 == 2 )
  {
    v5 = sub_3F012550();
    WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v5 + 4), dwMilliseconds: 0xFFFFFFFF);
  }
  *(_DWORD *)(a3 - 4) = 0;
  if ( ElementSize != 0 )
  {
    dword_3F03D3F4 += a5;
    if ( ElementSize == a5 )
    {
      sub_3F012770(a1: 16);
    }
    else if ( dword_3F03C0C4 != 16 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: a2,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
  }
  if ( ElementSize == 2 )
  {
    ((void (__thiscall *)(int, int))loc_3F012670)(a1: a3 - 13, a2: a4);
    if ( *(_BYTE *)(a3 - 13) != 0 )
      JUMPOUT(0x3F014C74);
    JUMPOUT(0x3F014D05);
  }
  JUMPOUT(0x3F014C8C);
}

//------------------------------------------------------------------------------
// Address: 0x3F014C78
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall doexit(int a1@<ebx>, int a2@<ebp>)
{
  --*(_DWORD *)(a1 + 206408455);
  ((void (*)(void))loc_3F012670)();
  *(_DWORD *)(a2 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( ElementSize == 2 )
  {
    ((void (*)(void))loc_3F0126F0)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F014D5A
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F014D6B
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F014D7C
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F014D8B
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _init_pointers(_DWORD *a1@<eax>, char *a2@<edi>)
{
  bool v2; // zf
  char v3; // [esp+0h] [ebp-38h] BYREF

  *a1 += 142445312;
  v2 = ElementSize == 0;
  qmemcpy(a2, a1 != (_DWORD *)22 ? &v3 : nullptr, 0x24u);
  if ( !v2 && byte_3F03D3C7 != 0 )
  {
    sub_3F012550();
    JUMPOUT(0x3F014DD8);
  }
  JUMPOUT(0x3F014ED9);
}

//------------------------------------------------------------------------------
// Address: 0x3F014E66
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _freea(int a1@<ebp>)
{
  if ( ElementSize == 2 )
  {
    ((void (__thiscall *)(_DWORD))loc_3F012670)(a1: *(_DWORD *)(a1 + 8));
    JUMPOUT(0x3F014EA3);
  }
  JUMPOUT(0x3F014E80);
}

//------------------------------------------------------------------------------
// Address: 0x3F014E81
// Name: _strupr_s_l_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall strupr_s_l_stat(size_t a1@<eax>, int a2@<ebp>)
{
  size_t v3; // eax

  fwrite_0(Buffer: *(const void **)(a2 + 8), ElementSize: a1, ElementCount: 0x24u, Stream: Stream);
  fflush(Stream: Stream);
  v3 = ElementSize;
  *(_DWORD *)(a2 - 4) = -1;
  if ( v3 == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( v3 == 2 )
  {
    ((void (*)(void))loc_3F0126F0)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F014FFD
// Name: __strupr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _strupr_s_l(int _EAX@<eax>, unsigned __int16 a2@<dx>, char a3@<cl>, _DWORD *a4@<ebx>, int a5@<ebp>)
{
  size_t v6; // eax

  LOBYTE(_EAX) = __inbyte(a2);
  *a4 = __ROL4__(*a4, a3);
  __asm { aas }
  fflush(Stream: _EAX);
  v6 = ElementSize;
  *(_DWORD *)(a5 - 4) = -1;
  if ( v6 == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
    JUMPOUT(0x3F01502A);
  }
  JUMPOUT(0x3F015035);
}

//------------------------------------------------------------------------------
// Address: 0x3F015030
// Name: __strupr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall _strupr@<eax>(char a1@<cl>, int a2@<ebx>)
{
  *(_BYTE *)(a2 - 2084348443) += a1;
  return (char *)((int (*)(void))loc_3F0126F0)();
}

//------------------------------------------------------------------------------
// Address: 0x3F0150A0
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn strncpy()
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F0151C4
// Name: ___ascii_stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall __ascii_stricmp@<eax>(int a1@<esi>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F0151F9
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _stricmp_l(int a1@<ebp>)
{
  unsigned __int16 v1; // ax
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *v2; // ecx
  size_t v3; // eax
  bool v4; // zf
  unsigned __int16 v5; // ax

  if ( ElementSize != 0 && byte_3F03D3C7 != 0 )
  {
    v1 = sub_3F012550();
    v2 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)dword_3F03D400;
    if ( *(_BYTE *)(dword_3F03D400 + 12 * v1 + 8) != 0 )
    {
      v3 = ElementSize;
      v4 = ElementSize == 1;
      *(_BYTE *)(a1 - 14) = 0;
      if ( v4 )
      {
        EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
      }
      else if ( v3 == 2 )
      {
        v5 = sub_3F012550();
        WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v5 + 4), dwMilliseconds: 0xFFFFFFFF);
      }
      *(_DWORD *)(a1 - 4) = 0;
      if ( ElementSize != 0 )
      {
        ++dword_3F03D3F4;
        if ( ElementSize == 1 )
        {
          sub_3F012770(a1: 20);
        }
        else if ( dword_3F03C0C4 != 20 )
        {
          std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
            this: v2,
            a2: (int)&rterrs[11].rterrtxt,
            a3: (char)&locktable[1]);
        }
      }
      if ( ElementSize != 1 )
      {
        Error(a1: (int)&locktable[27], *(_DWORD *)(a1 + 8));
        JUMPOUT(0x3F0152CB);
      }
      JUMPOUT(0x3F0152CE);
    }
  }
  JUMPOUT(0x3F0153E0);
}

//------------------------------------------------------------------------------
// Address: 0x3F0152CC
// Name: __strcmpi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _strcmpi(signed int a1@<eax>, int a2@<ebp>, const char *a3@<esi>)
{
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *v3; // ecx

  v3 = *(std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > **)a1;
  LOBYTE(a1) = -1;
  if ( a3 != nullptr )
  {
    a1 = strlen(a3) + 1;
    if ( a1 >= 255 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: v3,
        a2: (int)&locktable[33].kind,
        (char)a3);
      *(_DWORD *)(a2 - 4) = -1;
      sub_3F0125E0(a1: (_BYTE *)(a2 - 14));
      JUMPOUT(0x3F01531F);
    }
  }
  *(_BYTE *)(a2 - 13) = a1;
  fwrite_0(Buffer: (const void *)(a2 - 13), ElementSize: 1u, ElementCount: 1u, Stream: Stream);
  fflush(Stream: Stream);
  fwrite_0(Buffer: a3, ElementSize: 1u, ElementCount: *(unsigned __int8 *)(a2 - 13), Stream: Stream);
  fflush(Stream: Stream);
  JUMPOUT(0x3F015365);
}

//------------------------------------------------------------------------------
// Address: 0x3F0153AA
// Name: _V6_HeapAlloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall V6_HeapAlloc(int a1@<ebp>)
{
  *(_DWORD *)(a1 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( ElementSize == 2 )
  {
    ((void (*)(void))loc_3F0126F0)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0154BC
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _msize(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        _BYTE *a4@<edi>)
{
  int v4; // ecx
  _BYTE *v5; // eax
  bool v6; // cf
  unsigned __int8 v7; // dl
  int v8; // eax

  ++*(_DWORD *)(a2 + 468387012);
  if ( dword_3F03C0C4 != 20 )
    std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
      this: a1,
      a2: (int)&rterrs[11].rterrtxt,
      a3: (char)&locktable[1]);
  ((void (__thiscall *)(int))loc_3F012670)(a1: a3 - 18);
  if ( *(_BYTE *)(a3 - 18) != 0xFF )
  {
    ((void (__thiscall *)(int))loc_3F012670)(a1: a3 - 532);
    v4 = a3 - 532;
    v5 = a4;
    do
    {
      v6 = *v5 < *(_BYTE *)v4;
      if ( *v5 != *(_BYTE *)v4 )
        goto LABEL_10;
      if ( *v5 == 0 )
        break;
      v7 = v5[1];
      v6 = v7 < *(_BYTE *)(v4 + 1);
      if ( v7 != *(_BYTE *)(v4 + 1) )
      {
LABEL_10:
        v8 = -v6 - (v6 - 1);
        goto LABEL_11;
      }
      v5 += 2;
      v4 += 2;
    }
    while ( v7 != 0 );
    v8 = 0;
LABEL_11:
    if ( v8 != 0 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)v4,
        a2: (int)&_XcptActTab[3],
        a3: (char)a4);
      *(_DWORD *)(a3 - 4) = -1;
      if ( ElementSize == 1 )
        JUMPOUT(0x3F01555A);
      JUMPOUT(0x3F015573);
    }
  }
  JUMPOUT(0x3F015590);
}

//------------------------------------------------------------------------------
// Address: 0x3F015683
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall atexit@<eax>(char a1@<dh>, int a2@<ecx>, int a3@<ebx>, int a4@<ebp>, _BYTE *a5@<esi>)
{
  bool v5; // cf

  v5 = __CFADD__(*(_BYTE *)(a3 + 361361493), (_BYTE)a2);
  LOBYTE(a2) = *(_BYTE *)(a3 + 361361493) + a2;
  *a5 -= v5 + a1;
  *(_BYTE *)(a4 - 4) = 0;
  return _purecall(a1: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F0156BF
// Name: _realloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall realloc@<eax>(int a1@<ebp>)
{
  unsigned int v1; // eax
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *v2; // ecx
  _DWORD *v3; // edx
  int v4; // esi
  unsigned int v5; // eax
  unsigned __int8 *v6; // edx
  unsigned int v7; // eax
  unsigned __int8 *v8; // edx
  unsigned __int8 *v9; // edx
  int v10; // eax
  int v11; // esi
  char v13; // [esp+10h] [ebp-10h]

  ((void (*)(void))loc_3F012670)();
  v1 = *(_DWORD *)(a1 - 16);
  v2 = *(std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > **)(a1 + 8);
  v3 = (_DWORD *)dword_3F0A361C;
  if ( v1 < 4 )
  {
LABEL_4:
    if ( v1 == 0 )
    {
LABEL_14:
      v10 = 0;
      goto LABEL_15;
    }
  }
  else
  {
    while ( *v3 == *(_DWORD *)&v2->std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > )
    {
      v1 -= 4;
      v2 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)((char *)v2 + 4);
      ++v3;
      if ( v1 < 4 )
        goto LABEL_4;
    }
  }
  v4 = *(unsigned __int8 *)v3 - *(_BYTE *)&v2->comp.std::binary_function<CVProfNode *,CVProfNode *,bool>;
  if ( v4 == 0 )
  {
    v5 = v1 - 1;
    v2 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)((char *)v2 + 1);
    v6 = (unsigned __int8 *)v3 + 1;
    if ( v5 == 0 )
      goto LABEL_14;
    v4 = *v6 - *(_BYTE *)&v2->comp.std::binary_function<CVProfNode *,CVProfNode *,bool>;
    if ( v4 == 0 )
    {
      v7 = v5 - 1;
      v2 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)((char *)v2 + 1);
      v8 = v6 + 1;
      if ( v7 == 0 )
        goto LABEL_14;
      v4 = *v8 - *(_BYTE *)&v2->comp.std::binary_function<CVProfNode *,CVProfNode *,bool>;
      if ( v4 == 0 )
      {
        v2 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)((char *)v2 + 1);
        v9 = v8 + 1;
        if ( v7 == 1 )
          goto LABEL_14;
        v2 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)(unsigned __int8)v2->comp.std::binary_function<CVProfNode *,CVProfNode *,bool>;
        v4 = *v9 - (_DWORD)v2;
        if ( v4 == 0 )
          goto LABEL_14;
      }
    }
  }
  v10 = 1;
  if ( v4 <= 0 )
    v10 = -1;
LABEL_15:
  if ( v10 != 0 )
    std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
      this: v2,
      a2: (int)&tzdst[20],
      a3: v13);
  v11 = *(_DWORD *)(a1 - 16);
  *(_DWORD *)(a1 - 4) = -1;
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
    return v11;
  }
  else
  {
    if ( ElementSize == 2 )
      ((void (*)(void))loc_3F0126F0)();
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0158DA
// Name: __recalloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F015960
// Name: sub_3F015960
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__thiscall sub_3F015960(type_info *this, unsigned int a2)
{
  return type_info::`scalar deleting destructor'(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F015998
// Name: _rename
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall rename(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a1@<ecx>,
        _DWORD *a2@<edi>)
{
  int v2; // edi
  int v3; // [esp-8h] [ebp-8h]
  char v4; // [esp-4h] [ebp-4h]

  v2 = (int)a2 + *a2;
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
    this: a1,
    a2: v3,
    a3: v4);
  if ( dword_3F041A94 < v2 )
  {
    j_j__free(Block: Block);
    Block = (void *)((int (__cdecl *)(int))byte_3F01A077)(a1: v2);
    JUMPOUT(0x3F0159C5);
  }
  JUMPOUT(0x3F0159CB);
}

//------------------------------------------------------------------------------
// Address: 0x3F0159C6
// Name: __time32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__usercall _time32@<eax>(
        _DWORD *a1@<ebx>,
        unsigned int a2@<edi>,
        void (__cdecl *timeptr)(unsigned int, _EXCEPTION_POINTERS *)))(unsigned int, _EXCEPTION_POINTERS *)
{
  ((void (__thiscall *)(void *))loc_3F012670)(a1: Block);
  if ( a2 < 4 )
    JUMPOUT(0x3F015A04);
  if ( *(_DWORD *)Block != *a1 )
    JUMPOUT(0x3F015A08);
  return _set_se_translator(pNew: timeptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F0159FF
// Name: void (*_set_se_translator(void (*)(unsigned int,struct _EXCEPTION_POINTERS __near *)))(unsigned int,struct _EXCEPTION_POINTERS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _set_se_translator(unsigned int a1@<eax>, unsigned __int8 *a2@<edx>, unsigned __int8 *a3@<ecx>)
{
  if ( a1 < 4 )
  {
    if ( a1 != 0 )
    {
      if ( *a2 == *a3 )
        JUMPOUT(0x3F015A1D);
      JUMPOUT(0x3F015A57);
    }
    JUMPOUT(0x3F015A65);
  }
  JUMPOUT(0x3F0159F0);
}

//------------------------------------------------------------------------------
// Address: 0x3F015A1E
// Name: __localtime32_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _localtime32_s@<eax>(
        int a1@<eax>,
        unsigned __int8 *a2@<edx>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a3@<ecx>,
        int a4@<ebp>)
{
  int v4; // esi
  int v5; // eax
  unsigned __int8 *v6; // edx
  unsigned __int8 *v7; // edx
  int result; // eax

  v4 = *a2 - *(_BYTE *)&a3->comp.std::binary_function<CVProfNode *,CVProfNode *,bool>;
  if ( v4 != 0
    || (v5 = a1 - 1,
        a3 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)((char *)a3 + 1),
        v6 = a2 + 1,
        v5 != 0)
    && ((v4 = *v6 - *(_BYTE *)&a3->comp.std::binary_function<CVProfNode *,CVProfNode *,bool>) != 0
     || (a3 = (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)((char *)a3 + 1),
         v7 = v6 + 1,
         v5 != 1)
     && (v4 = *v7 - *(_BYTE *)&a3->comp.std::binary_function<CVProfNode *,CVProfNode *,bool>) != 0) )
  {
    result = 1;
    if ( v4 <= 0 )
      result = -1;
  }
  else
  {
    result = 0;
  }
  if ( result != 0 )
    return (int)std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
                  this: a3,
                  a2: (int)"ReadAndVerifyShortString: strings different ('%s' vs '%s').",
                  a3: *(_DWORD *)(a4 + 8));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F015C4B
// Name: __localtime32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _localtime32()
{
  unsigned __int16 v0; // ax

  v0 = sub_3F012550();
  WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v0 + 4), dwMilliseconds: 0xFFFFFFFF);
  JUMPOUT(0x3F015C6B);
}

//------------------------------------------------------------------------------
// Address: 0x3F015C6F
// Name: _memmove_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall memmove_s(
        int _EAX@<eax>,
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a2@<ecx>,
        int a3@<ebp>,
        unsigned int a4@<esi>)
{
  type_info *v5; // ecx

  __asm { aas }
  *(_DWORD *)(a3 - 4) = 0;
  if ( _EAX != 0 )
  {
    ++dword_3F03D3F4;
    if ( _EAX == 1 )
    {
      sub_3F012770(a1: 26);
    }
    else if ( dword_3F03C0C4 != 26 )
    {
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: a2,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
  }
  sub_3F015960(this: (type_info *)a2, a2: a4);
  sub_3F015960(this: v5, a2: *(_DWORD *)(a3 + 8));
  *(_DWORD *)(a3 - 4) = -1;
  JUMPOUT(0x3F015CC7);
}

//------------------------------------------------------------------------------
// Address: 0x3F015DD8
// Name: void operator delete[](void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator delete[](void *p, unsigned int a2, const void *a3, unsigned int a4)
{
  memcpy_s(dst: p, sizeInBytes: a2, src: a3, count: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F015DDD
// Name: _memcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
uintptr_t __usercall memcpy_s@<eax>(unsigned __int16 a1@<ax>, int a2@<ecx>, int a3@<ebp>, _DWORD *a4@<esi>)
{
  uintptr_t result; // eax
  _DWORD *v5; // ecx

  if ( *(_BYTE *)(a2 + 12 * a1 + 8) != 0 )
  {
LABEL_6:
    if ( GetCurrentThreadId() != dword_3F03D408 )
    {
      Error(a1: (int)&__lc_time_c.wday[2]);
      JUMPOUT(0x3F015E56);
    }
    JUMPOUT(0x3F015E59);
  }
  if ( (_DWORD *)ElementSize != a4 )
  {
    Error(a1: (int)aVcrCreatethrea);
    goto LABEL_6;
  }
  result = _beginthreadex_0(
             Security: *(void **)(a3 + 8),
             StackSize: *(_DWORD *)(a3 + 12),
             StartAddress: *(_beginthreadex_proc_type *)(a3 + 16),
             ArgList: *(void **)(a3 + 20),
             InitFlag: *(_DWORD *)(a3 + 24),
             ThrdAddr: (unsigned int *)(a3 - 20));
  v5 = *(_DWORD **)(a3 + 28);
  if ( v5 == a4 )
    JUMPOUT(0x3F016015);
  *v5 = *(_DWORD *)(a3 - 20);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F015E58
// Name: __mbscmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbscmp_l(char a1@<al>, _BYTE *a2@<edx>)
{
  *a2 += a1 - 127;
  JUMPOUT(0x3F015E61);
}

//------------------------------------------------------------------------------
// Address: 0x3F015F74
// Name: __mbscmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl _mbscmp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F015F87
// Name: void __ArrayUnwind(void __near *,unsigned int,int,void (*)(void __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn __ArrayUnwind(void *ptr, void *size, unsigned int count, void (__thiscall *pDtor)(void *))
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F016048
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __usercall _flush@<eax>(int a1@<ebp>, _iobuf *str)
{
  if ( ElementSize == 0
    || byte_3F03D3C7 == 0
    || *(_BYTE *)(dword_3F03D400 + 12 * (unsigned __int16)sub_3F012550() + 8) == 0 )
  {
    return WaitForSingleObject(hHandle: *(HANDLE *)(a1 + 8), dwMilliseconds: *(_DWORD *)(a1 + 12));
  }
  if ( ElementSize != 1 )
    JUMPOUT(0x3F0160B5);
  return _fflush_nolock(str);
}

//------------------------------------------------------------------------------
// Address: 0x3F0160AA
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fflush_nolock@<eax>(
        int a1@<ebp>,
        void (__stdcall *a2)(HANDLE hHandle, DWORD dwMilliseconds)@<edi>,
        _iobuf *str)
{
  size_t v3; // eax
  unsigned __int16 v5; // ax
  void *v6; // [esp+0h] [ebp-8h]
  DWORD v7; // [esp+4h] [ebp-4h]

  a2(hHandle: v6, dwMilliseconds: v7);
  v3 = ElementSize;
  *(_BYTE *)(a1 - 14) = 0;
  if ( v3 == 1 )
  {
    EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else
  {
    if ( v3 != 2 )
      JUMPOUT(0x3F0160F1);
    v5 = sub_3F012550();
    a2(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v5 + 4), dwMilliseconds: 0xFFFFFFFF);
  }
  return flsall(flushflag: (int)str);
}

//------------------------------------------------------------------------------
// Address: 0x3F0160EC
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall flsall@<eax>(
        std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *a1@<ecx>,
        int a2@<ebp>,
        int a3@<esi>)
{
  size_t v3; // eax

  v3 = ElementSize;
  *(_DWORD *)(a2 - 4) = 0;
  if ( v3 != 0 )
  {
    ++dword_3F03D3F4;
    if ( v3 == 1 )
    {
      sub_3F012770(a1: 22);
    }
    else
    {
      if ( dword_3F03C0C4 == 22 )
        goto LABEL_7;
      std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Buynode(
        this: a1,
        a2: (int)&rterrs[11].rterrtxt,
        a3: (char)&locktable[1]);
    }
    v3 = ElementSize;
  }
LABEL_7:
  *(_BYTE *)(a2 - 13) = 1;
  if ( v3 != 1 )
  {
    if ( v3 != 2 )
      ((void (__cdecl *)($D283E5A92EBEB600100C8EBC9C67A011 *, _DWORD, $D283E5A92EBEB600100C8EBC9C67A011 *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: &locktable[21].kind,
        a2: 0,
        a3: &locktable[19].kind,
        a4: 1661,
        a5: &unk_3F041A98,
        a6: 0);
    ((void (__thiscall *)(int))loc_3F012670)(a1: a2 - 13);
    JUMPOUT(0x3F016205);
  }
  if ( a3 == 128 )
  {
    *(_BYTE *)(a2 - 13) = 2;
  }
  else if ( a3 == 258 )
  {
    *(_BYTE *)(a2 - 13) = 3;
  }
  fwrite_0(Buffer: (const void *)(a2 - 13), ElementSize: 1u, ElementCount: 1u, Stream: Stream);
  fflush(Stream: Stream);
  *(_DWORD *)(a2 - 4) = -1;
  if ( ElementSize != 1 )
  {
    if ( ElementSize == 2 )
    {
      ((void (*)(void))loc_3F0126F0)();
      JUMPOUT(0x3F0161CA);
    }
    JUMPOUT(0x3F016263);
  }
  LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x3F016219
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _flushall@<eax>(
        _BYTE *a1@<eax>,
        _BYTE *a2@<edx>,
        int a3@<ecx>,
        void *a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        _iobuf *a8)
{
  *a1 = *a1;
  a1[a3 - 127] += BYTE1(a2);
  ++*a2;
  return _fread_nolock_s(buffer: a4, bufferSize: a5, elementSize: a6, num: a7, stream: a8);
}

//------------------------------------------------------------------------------
// Address: 0x3F016222
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _fread_nolock_s@<eax>(_DWORD *a1@<eax>, char a2@<dh>, int a3@<ebp>, int a4@<esi>)
{
  *a1 += a1;
  *(_BYTE *)(a3 + 13) += a2;
  Error(a1: (int)&__lc_time_c.refcount);
  *(_DWORD *)(a3 - 4) = -1;
  sub_3F0125E0(a1: (_BYTE *)(a3 - 14));
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x3F016428
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __usercall fread_s@<eax>(char a1@<cf>, int a2@<eax>)
{
  return (unsigned int)&LeaveCriticalSection + a1 + a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F016460
// Name: sub_3F016460
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F016460(void *Buffer)
{
  fwrite_0(Buffer, ElementSize: 1u, ElementCount: 1u, Stream: Stream);
  return fflush(Stream: Stream);
}

//------------------------------------------------------------------------------
// Address: 0x3F016480
// Name: sub_3F016480
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F016480(void *Buffer)
{
  fwrite_0(Buffer, ElementSize: 1u, ElementCount: 4u, Stream: Stream);
  return fflush(Stream: Stream);
}

//------------------------------------------------------------------------------
// Address: 0x3F0164BE
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall fread(int a1@<ebp>)
{
  *(_DWORD *)(a1 - 4) = -1;
  if ( g_VProfile != -1 )
    TlsFree(dwTlsIndex: g_VProfile);
  JUMPOUT(0x3F0164D8);
}

//------------------------------------------------------------------------------
// Address: 0x3F0164D9
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _fwrite_nolock()
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F0164F0
// Name: CreateVProfile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVProfile *CreateVProfile()
{
  CVProfile *v0; // eax

  v0 = (CVProfile *)operator new(Size: 0xA80u);
  if ( v0 != nullptr )
    return CVProfile::CVProfile(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F016550
// Name: public: CVProfileArray::~CVProfileArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfileArray::~CVProfileArray(CVProfileArray *this)
{
  void *v1; // ecx

  *((_DWORD *)this + 1) = 0;
  v1 = *(void **)this;
  if ( v1 != nullptr )
    j_j__free(Block: v1);
}

//------------------------------------------------------------------------------
// Address: 0x3F016570
// Name: public: void CVProfManager::GetAllThreadProfiles(class CVProfileArray __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfManager::GetAllThreadProfiles(
        LPCRITICAL_SECTION lpCriticalSection@<ecx>,
        struct CVProfileArray *a2,
        unsigned int a3,
        unsigned int a4,
        _iobuf *a5)
{
  unsigned int v7; // eax
  void **p_OwningThread; // ecx
  int i; // edx
  int v10; // eax
  void **v11; // edx
  int RecursionCount; // ecx

  if ( a2 == nullptr )
    JUMPOUT(0x3F016676);
  EnterCriticalSection(lpCriticalSection);
  v7 = 0;
  p_OwningThread = &lpCriticalSection[1].OwningThread;
  for ( i = 64; i != 0; --i )
  {
    if ( *(p_OwningThread - 1) != nullptr )
      ++v7;
    if ( *p_OwningThread != nullptr )
      ++v7;
    if ( p_OwningThread[1] != nullptr )
      ++v7;
    if ( p_OwningThread[2] != nullptr )
      ++v7;
    p_OwningThread += 4;
  }
  *((_DWORD *)a2 + 1) = v7;
  if ( v7 == 0 )
    JUMPOUT(0x3F01666F);
  *(_DWORD *)a2 = ((int (__cdecl *)(unsigned int))byte_3F01A077)(a1: (unsigned __int64)v7 >> 30 != 0 ? -1 : 4 * v7);
  v10 = 0;
  v11 = &lpCriticalSection[1].OwningThread;
  RecursionCount = lpCriticalSection[1].RecursionCount;
  if ( RecursionCount != 0 )
  {
    **(_DWORD **)a2 = *(_DWORD *)(RecursionCount + 4);
    v10 = 4;
  }
  if ( *v11 != nullptr )
    *(_DWORD *)(v10 + *(_DWORD *)a2) = *((_DWORD *)*v11 + 1);
  fwrite(buffer: lpCriticalSection, size: a3, count: a4, stream: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F016638
// Name: _fwrite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge fwrite(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ebp>,
        int a4@<edi>,
        _DWORD *a5@<esi>,
        const void *buffer,
        const void *size,
        unsigned int count,
        _iobuf *stream)
{
  int v9; // ecx
  int v10; // ecx

  v9 = *(_DWORD *)(a2 + 4);
  if ( v9 != 0 )
  {
    *(_DWORD *)(a1 + *a5) = *(_DWORD *)(v9 + 4);
    a1 += 4;
  }
  v10 = *(_DWORD *)(a2 + 8);
  if ( v10 != 0 )
    *(_DWORD *)(a1 + *a5) = *(_DWORD *)(v10 + 4);
  if ( a4 != 1 )
    JUMPOUT(0x3F016615);
  *(_DWORD *)(a3 - 4) = -1;
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a3 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F0166BA
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge _fseek_nolock(
        char a1@<zf>,
        int a2@<eax>,
        const char *a3@<ebx>,
        _DWORD *a4@<ebp>,
        struct CVProfNode *a5@<esi>,
        _iobuf *str,
        _iobuf *offset,
        int whence,
        int whencea)
{
  CVProfNode *v9; // edi
  CVProfNode *v10; // eax
  struct CVProfile *v11; // eax
  int v12; // [esp-20h] [ebp-20h]
  const char *v13; // [esp-18h] [ebp-18h]
  int v14; // [esp-14h] [ebp-14h]

  if ( !a1 )
  {
    if ( *(_DWORD *)(a2 + 120) != 0 )
      JUMPOUT(0x3F0166B7);
    v9 = (CVProfNode *)operator new(Size: 0x90u);
    a4[2] = v9;
    v10 = nullptr;
    *(a4 - 1) = 0;
    if ( v9 != nullptr )
    {
      v14 = a4[5];
      v13 = (const char *)a4[4];
      v12 = a4[3];
      v11 = (struct CVProfile *)sub_3F00B440();
      CVProfNode::CVProfNode(this: v9, a2: v11, a3, a4: v12, a5, a6: v13, a7: v14);
    }
    *(a4 - 1) = -1;
    v10->m_pSibling = a5->m_pChild;
    a5->m_pChild = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F016741
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge fseek@<eax>(int *a1@<ecx>, _iobuf *stream, _iobuf *offset, int whence)
{
  int result; // eax

  result = a1[14];
  ++a1[15];
  a1[14] = result + 1;
  if ( result == 0 )
  {
    cpuid(a1: a1 + 2);
    result = a1[35];
    if ( *(_BYTE *)(result + 44) != 0 && *(_BYTE *)(result + 45) != 0 )
      result = sub_3F00BFD0();
    a1[31] = (int)offset;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0167C6
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
BOOL __usercall _ftell_nolock@<eax>(int a1@<edx>, int a2@<ecx>, _DWORD *a3@<edi>)
{
  bool v3; // cf
  int v4; // eax

  *(_BYTE *)(a2 - 796193713) |= a2;
  v3 = __CFADD__(a1, a3[16]);
  a3[16] += a1;
  a3[17] += a3[3] + v3;
  v4 = a3[35];
  if ( *(_BYTE *)(v4 + 44) != 0 && *(_BYTE *)(v4 + 45) != 0 )
  {
    sub_3F00C0A0();
    a3[12] += a3[10];
  }
  a3[31] = 0;
  return a3[14] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01695E
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall ftell(char a1@<cf>, CVProfNode *a2@<edi>, int a3@<esi>)
{
  unsigned int m_nCurFrameCalls; // eax
  int m_Int64; // ecx
  int m_Int64_high; // edx
  _DWORD *v6; // esi
  int v7; // edx
  CVProfNode *v8; // ecx
  CVProfNode *v9; // esi

  v6 = (_DWORD *)(a3 + 1);
  v6[25] += v6[17] + a1;
  if ( *((_QWORD *)v6 + 13) < *((_QWORD *)v6 + 8) )
  {
    v7 = v6[17];
    v6[26] = v6[16];
    v6[27] = v7;
  }
  v8 = (CVProfNode *)v6[29];
  v6[13] += v6[12];
  v6[16] = a2;
  v6[17] = a2;
  v6[15] = a2;
  v6[12] = a2;
  if ( v8 != a2 )
    CVProfNode::MarkFrame(this: v8);
  v9 = (CVProfNode *)v6[30];
  if ( v9 != a2 )
  {
    m_nCurFrameCalls = v9->m_nCurFrameCalls;
    m_Int64 = v9->m_CurFrameTime.m_Int64;
    m_Int64_high = HIDWORD(v9->m_CurFrameTime.m_Int64);
    v9->m_nTotalCalls += m_nCurFrameCalls;
    v9->m_nPrevFrameCalls = m_nCurFrameCalls;
    LODWORD(v9->m_PrevFrameTime.m_Int64) = m_Int64;
    HIDWORD(v9->m_PrevFrameTime.m_Int64) = m_Int64_high;
    JUMPOUT(0x3F01695D);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0169CC
// Name: __endthreadex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl _endthreadex()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F016A05
// Name: _callthreadstartex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned __int64 __userpurge callthreadstartex@<edx:eax>(
        char _AL@<al>,
        int a2@<esi>,
        double a3@<st1>,
        double a4@<st0>,
        int a5)
{
  unsigned __int64 result; // rax

  __asm { aaa }
  result = (unsigned __int64)(a3 / a4);
  *(_QWORD *)(a2 + 64) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F016A46
// Name: _threadstartex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F016AC6
// Name: __beginthreadex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __userpurge _beginthreadex@<eax>(
        int a1@<esi>,
        void *security,
        void *stacksize,
        unsigned int (__stdcall *initialcode)(void *),
        unsigned int argument,
        void *createflag,
        unsigned int *thrdaddr)
{
  unsigned int result; // eax

  if ( *(_BYTE *)(a1 + 49) == 0 )
  {
    if ( *(_DWORD *)(a1 + 8) == 0 )
      ((void (__cdecl *)(errentry *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: &errtable[34],
        a2: 0,
        a3: &errtable[9],
        a4: 158,
        a5: &unk_3F041A88,
        a6: 0);
    result = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(result + 12);
    if ( *(int *)(result + 32) <= 0 )
      --*(_DWORD *)(a1 + 20);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F016B74
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _initp_misc_invarg(char a1@<cl>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 1507592269) -= a1;
  JUMPOUT(0x3F016B7E);
}

//------------------------------------------------------------------------------
// Address: 0x3F016BA0
// Name: sub_3F016BA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl sub_3F016BA0(int a1, int a2)
{
  int v2; // eax
  double v3; // st6
  double v4; // st6
  int v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st6
  double v9; // rt0

  v2 = *(_DWORD *)(a1 + 4);
  if ( v2 != 0 )
  {
    v3 = (double)v2;
    if ( v2 < 0 )
      v3 = v3 + *(double *)&GS_ExceptionRecord.ExceptionInformation[1];
    v4 = *(double *)(a1 + 8) / v3;
  }
  else
  {
    v4 = 0.0;
  }
  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 != 0 )
  {
    v6 = v4;
    v7 = (double)v5;
    if ( v5 < 0 )
      v7 = v7 + *(double *)&GS_ExceptionRecord.ExceptionInformation[1];
    v8 = *(double *)(a2 + 8) / v7;
  }
  else
  {
    v9 = v4;
    v8 = 0.0;
    v6 = v9;
  }
  return v8 < v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F016C00
// Name: sub_3F016C00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl sub_3F016C00(int a1, int a2)
{
  int v2; // eax
  double v3; // st6
  double v4; // st6
  int v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st6
  double v9; // rt0

  v2 = *(_DWORD *)(a1 + 4);
  if ( v2 != 0 )
  {
    v3 = (double)v2;
    if ( v2 < 0 )
      v3 = v3 + *(double *)&GS_ExceptionRecord.ExceptionInformation[1];
    v4 = *(double *)(a1 + 16) / v3;
  }
  else
  {
    v4 = 0.0;
  }
  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 != 0 )
  {
    v6 = v4;
    v7 = (double)v5;
    if ( v5 < 0 )
      v7 = v7 + *(double *)&GS_ExceptionRecord.ExceptionInformation[1];
    v8 = *(double *)(a2 + 16) / v7;
  }
  else
  {
    v9 = v4;
    v8 = 0.0;
    v6 = v9;
  }
  return v8 < v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F016C7A
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(int _EDX@<edx>, int a2@<ebp>)
{
  int v2; // ecx
  int v4; // [esp+4h] [ebp+4h]

  __asm { fdivr   qword ptr [edx+10h] }
  v2 = *(_DWORD *)(a2 + 12);
  if ( *(_DWORD *)(v2 + 4) == 0 )
    JUMPOUT(0x3F016CAB);
  v4 = *(_DWORD *)(v2 + 4);
  __asm { fild    [esp+arg_0] }
  _invalid_parameter_noinfo();
}

//------------------------------------------------------------------------------
// Address: 0x3F016C9E
// Name: __invalid_parameter_noinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo()
{
  char v0; // sf
  char v1; // of

  if ( v0 != v1 )
    __asm { fadd    qword ptr ds:GS_ExceptionRecord.ExceptionInformation+4 }
  __asm { fdivr   qword ptr [ecx+10h] }
  JUMPOUT(0x3F016CAD);
}

//------------------------------------------------------------------------------
// Address: 0x3F016CAE
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _CRT_INIT(
        void *hDllHandle,
        void *dwReason,
        unsigned int lpreserved,
        unsigned int winmajor,
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
// Address: 0x3F016F7D
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge _DllMainCRTStartup(
        int a1@<eax>,
        int a2@<ebx>,
        int a3@<edi>,
        void *hDllHandle,
        unsigned int dwReason,
        void *lpreserved)
{
  if ( a1 == 0 )
    *(_DWORD *)(a3 + 2656) = a2;
  if ( *(_DWORD *)(a3 + 12) != a2 )
    JUMPOUT(0x3F016FA3);
  JUMPOUT(0x3F017195);
}

//------------------------------------------------------------------------------
// Address: 0x3F017239
// Name: TranslatorGuardHandler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge TranslatorGuardHandler@<eax>(
        int a1@<edi>,
        EHExceptionRecord *pExcept,
        EHExceptionRecord *pRN,
        TranslatorGuardRN *pContext,
        void *__formal)
{
  return MK_FP(*(_WORD *)(a1 + 98), *(_DWORD *)(a1 + 94))();
}

//------------------------------------------------------------------------------
// Address: 0x3F017349
// Name: __CreateFrameInfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _CreateFrameInfo(char a1@<zf>, char a2@<sf>, char a3@<of>, int a4@<ebp>, int a5@<edi>)
{
  int v5; // [esp-Ch] [ebp-Ch]
  int v6; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  if ( !(a2 ^ a3 | a1) )
  {
    *(_DWORD *)(a4 + 8) = *(_DWORD *)(*(_DWORD *)(a4 - 12) + 16);
    ((void (__stdcall *)(int, int, int))loc_3F018BB0)(a1: v5, a2: v6, a3: v7);
  }
  if ( *(int *)(a5 + 88) > 0 )
    JUMPOUT(0x3F017370);
  JUMPOUT(0x3F01737E);
}

//------------------------------------------------------------------------------
// Address: 0x3F017371
// Name: __IsExceptionObjectToBeDestroyed_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _IsExceptionObjectToBeDestroyed_0()
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F017392
// Name: __FindAndUnlinkFrame
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0173DE
// Name: void __near * _CallCatchBlock2(struct EHRegistrationNode __near *,struct _s_FuncInfo const __near *,void __near *,int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _CallCatchBlock2(int a1@<eax>, int _EBP@<ebp>, int _EDI@<edi>)
{
  bool v8; // zf
  int CGRN_12; // [esp+Ch] [ebp-Ch]
  int CGRN_16; // [esp+10h] [ebp-8h]
  int CGRN_20; // [esp+14h] [ebp-4h]

  __asm { fst     qword ptr [ebp-24h] }
  *(double *)(_EBP - 36) = _RT1;
  if ( a1 <= 0 )
  {
    __asm { fst     qword ptr [ebp-2Ch] }
    *(double *)(_EBP - 44) = _RT1;
  }
  else
  {
    __asm { fstp    st }
    *(_DWORD *)(_EBP + 8) = *(_DWORD *)(*(_DWORD *)(_EBP - 12) + 16);
    _EAX = ((int (__stdcall *)(int, int, int))loc_3F018BB0)(a1: CGRN_12, a2: CGRN_16, a3: CGRN_20);
    __asm
    {
      fild    dword ptr [ebp+8]
      fdivr   qword ptr [eax+8]
      fstp    qword ptr [ebp-2Ch]
    }
    *(double *)(_EBP - 44) = _RT1;
    __asm { fldz }
  }
  if ( *(int *)(_EDI + 88) > 0 )
  {
    _ECX = *(_DWORD *)(_EBP - 12);
    __asm
    {
      fstp    st
      fild    qword ptr [edi+60h]
      fmul    g_ClockSpeedMillisecondsMultiplier
      fidiv   dword ptr [ecx+10h]
    }
  }
  v8 = *(_DWORD *)(_EBP - 20) == 0;
  __asm { fstp    qword ptr [ebp-34h] }
  *(double *)(_EBP - 52) = _RT1;
  __asm
  {
    fild    qword ptr [edi+68h]
    fmul    g_ClockSpeedMillisecondsMultiplier
    fstp    qword ptr [ebp-3Ch]
  }
  *(double *)(_EBP - 60) = _RT1;
  if ( v8 )
    _invalid_parameter_noinfo_0();
  JUMPOUT(0x3F01743A);
}

//------------------------------------------------------------------------------
// Address: 0x3F0174A5
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl __noreturn __report_gsfailure()
{
  bool v0; // zf
  int v1; // ebx
  int v2; // ebp
  int v3; // edi
  int v4; // esi
  int v5; // esi
  struct CVProfNode *v6; // eax
  int v7; // edx
  int v8; // edi

  *(_DWORD *)(v4 + 26) += v3;
  v5 = v1 - 1;
  do
  {
    Msg(a1: (int)"|  ");
    --v5;
  }
  while ( v5 != 0 );
  if ( *(_DWORD *)v3 == 0 )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: m_pszName",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier0/vprof.h",
      a4: 1026,
      a5: &`CVProfNode::GetName'::`7'::fDumped,
      a6: 0);
  Msg(a1: (int)"%s\n", *(const char **)v3);
  v6 = *(struct CVProfNode **)(v3 + 116);
  if ( v6 != nullptr )
    CVProfile::DumpNodes(this: *(CVProfile **)(v2 - 12), a2: v6, a3: v1 + 1, a4: *(_DWORD *)(v2 + 16));
  if ( *(_BYTE *)(v2 - 5) == 0 )
  {
    v7 = *(_DWORD *)(v2 - 12);
    if ( v3 != *(_DWORD *)(v7 + 2656) )
    {
      v8 = *(_DWORD *)(v3 + 120);
      if ( v8 != 0 )
      {
        *(_DWORD *)(v2 + 8) = v8;
        v0 = v8 != *(_DWORD *)(v7 + 12);
        *(_BYTE *)(v2 - 5) = v8 == *(_DWORD *)(v7 + 12);
        if ( v0 )
          JUMPOUT(0x3F0172D5);
        JUMPOUT(0x3F0172D7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0175A9
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void CPtoLCID()
{
  __asm { iret }
  JUMPOUT(0x3F0175AC);
}

//------------------------------------------------------------------------------
// Address: 0x3F0175D8
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01762D
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBUpLow(
        unsigned int ptmbci@<esi>,
        int a2@<eax>,
        int a3@<edx>,
        int a4@<ecx>,
        int a5@<ebx>,
        int a6@<edi>,
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
        int a20)
{
  *(_BYTE *)(3 * a3 - 123) += BYTE1(a3);
  *(_BYTE *)(a5 + a4 - 117) = 0;
  if ( ptmbci >= (a3 - a2) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    a4 = a20;
    a2 = a19;
  }
  if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    a4 = a20;
    a2 = a19;
  }
  if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    a4 = a20;
    a2 = a19;
  }
  if ( *(_DWORD *)(a6 + a2 + 4) != 0 )
  {
    if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
    {
      _invalid_parameter_noinfo_0();
      a4 = a20;
      a2 = a19;
    }
    if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
    {
      _invalid_parameter_noinfo_0();
      a4 = a20;
      a2 = a19;
    }
  }
  if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    a4 = a20;
    a2 = a19;
  }
  if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    a4 = a20;
    a2 = a19;
  }
  if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    a4 = a20;
    a2 = a19;
  }
  if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    a4 = a20;
    a2 = a19;
  }
  if ( a2 == 0 || ptmbci >= (a4 - a2) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    a2 = a19;
  }
  if ( a2 != 0 )
    JUMPOUT(0x3F0177B6);
  JUMPOUT(0x3F0177C1);
}

//------------------------------------------------------------------------------
// Address: 0x3F0177B7
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __updatetmbcinfo(
        _DWORD *a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        unsigned int a4@<esi>,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        double a12,
        double a13,
        int a14,
        int a15,
        int a16)
{
  int v16; // eax

  *a1 >>= 1;
  _disable();
  _invalid_parameter_noinfo_0();
  v16 = a15;
  if ( a15 == 0 || a4 >= (a16 - a15) >> 5 )
  {
    _invalid_parameter_noinfo_0();
    v16 = a15;
  }
  Msg(
    a1: (int)"  %52s%12d%12.3f%6.2f%%%12.3f%6.2f%%%12.3f%12.3f%12.3f\n",
    *(const char **)(a3 + v16),
    *(_DWORD *)(a3 + a15 + 4),
    *(double *)(a11 + 8),
    100.0 * (*(double *)(a10 + 8) / *(double *)(a2 + 12)),
    *(double *)(a9 + 16),
    *(double *)(a8 + 16) / *(double *)(a2 + 12) * 100.0,
    a13,
    a12,
    *(double *)(a7 + 24));
  JUMPOUT(0x3F017859);
}

//------------------------------------------------------------------------------
// Address: 0x3F017AAE
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _setmbcp@<eax>(
        char a1@<bl>,
        int a2@<ebp>,
        int a3@<esi>,
        int codepage,
        int codepagea,
        int codepage_4,
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
        int a17)
{
  double v17; // st7
  CVProfNode *v18; // edi
  double v19; // st7
  char *Name; // edi
  struct CVProfNode *v21; // eax
  struct CVProfNode *v22; // eax

  v17 = (double)*(__int64 *)(*(_DWORD *)(a3 + 12) + 96) * g_ClockSpeedMillisecondsMultiplier;
  Msg(a1: (int)&_pow10pos[0].ld12[4], 1000.0 / (v17 / (double)a17), v17 / (double)a16);
  Msg(
    a1: (int)&_pow10pos[3].ld12[8],
    (double)*(__int64 *)(*(_DWORD *)(a3 + 12) + 104) * g_ClockSpeedMillisecondsMultiplier);
  v18 = *(CVProfNode **)(a3 + 12);
  v19 = 100.0
      - CVProfNode::GetTotalTimeLessChildren(this: v18)
      / ((double)v18->m_TotalTime.m_Int64
       * g_ClockSpeedMillisecondsMultiplier);
  if ( v19 > 100.0 )
    v19 = 100.0;
  Msg(a1: (int)&_pow10pos[5].ld12[4], v19);
  Msg(a1: (int)"\n");
  Name = *(char **)(a2 + 12);
  if ( Name == nullptr )
    Name = (char *)CVProfNode::GetName(this: *(CVProfNode **)(a3 + 12));
  CVProfile::SumTimes(this: (CVProfile *)a3, a2: Name, a3: *(_DWORD *)(a2 + 16));
  if ( (a1 & 2) != 0 )
  {
    Msg(a1: (int)&_pow10pos[8]);
    if ( Name == nullptr )
    {
      *(_DWORD *)(a3 + 2656) = 0;
      v21 = *(struct CVProfNode **)(a3 + 2656);
      if ( v21 == nullptr )
        v21 = *(struct CVProfNode **)(a3 + 12);
      CVProfile::DumpNodes(this: (CVProfile *)a3, a2: v21, a3: 0, a4: false);
    }
    CVProfile::FindNode(this: (CVProfile *)a3, a2: *(struct CVProfNode **)(a3 + 12), Str2: Name);
  }
  if ( (a1 & 4) != 0 )
  {
    Msg(a1: (int)&_pow10pos[8]);
    if ( Name == nullptr )
    {
      *(_DWORD *)(a3 + 2656) = 0;
      v22 = *(struct CVProfNode **)(a3 + 2656);
      if ( v22 == nullptr )
        v22 = *(struct CVProfNode **)(a3 + 12);
      CVProfile::DumpNodes(this: (CVProfile *)a3, a2: v22, a3: 0, a4: true);
    }
    CVProfile::FindNode(this: (CVProfile *)a3, a2: *(struct CVProfNode **)(a3 + 12), Str2: Name);
  }
  if ( (a1 & 8) == 0 )
    JUMPOUT(0x3F017C5F);
  return __initmbctable();
}

//------------------------------------------------------------------------------
// Address: 0x3F017C48
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F017C66
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F017DA6
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall __addlocaleref(threadlocaleinfostruct *ptloci, int a2, int a3)
{
  Msg(a1: (int)&::ptloci.lc_category[2].wlocale);
  if ( --dword_3F041A10 == 0 )
    _InterlockedExchange(&dword_3F041A0C, 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F017E2C
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __fastcall __removelocaleref(_BYTE *a1)
{
  int v1; // ebp
  void *v2; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  a1[1586046046] &= (unsigned __int8)a1;
  a1[602270] -= (_BYTE)a1;
  a1[668830] += (_BYTE)a1;
  v1 = v4;
  ((void (__cdecl *)(int))loc_3F0189C0)(a1: v3 + 2628);
  *(_BYTE *)(v1 - 4) = 1;
  *(_DWORD *)(v3 + 2644) = -1996488695;
  *(_DWORD *)(v3 + 2648) = -1996488695;
  *(_DWORD *)(v3 + 2652) = -1996488695;
  *(_BYTE *)(v1 - 4) = 2;
  *(_DWORD *)(v3 + 2664) = -1996488695;
  *(_DWORD *)(v3 + 2668) = -1996488695;
  *(_DWORD *)(v3 + 2676) = -1996488695;
  *(_DWORD *)(v3 + 2680) = -1996488695;
  *(_DWORD *)(v3 + 2684) = -1996488695;
  *(_BYTE *)(v1 - 4) = 3;
  *(_BYTE *)(v3 + 2356) = 9;
  *(_BYTE *)(v3 + 44) = 9;
  *(_BYTE *)(v3 + 45) = 9;
  v2 = operator new(Size: 0x90u);
  *(_DWORD *)(v1 - 20) = v2;
  *(_BYTE *)(v1 - 4) = 4;
  if ( v2 != (void *)-1996488695 )
    JUMPOUT(0x3F017EB5);
  JUMPOUT(0x3F017ECB);
}

//------------------------------------------------------------------------------
// Address: 0x3F017EB8
// Name: _updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall updatetlocinfoEx_nolock(
        threadlocaleinfostruct **pptlocid@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        struct CVProfile *a4@<esi>)
{
  int v5; // eax
  struct CVProfNode *v6; // [esp-10h] [ebp-14h]
  const char *v7; // [esp-Ch] [ebp-10h]
  int v8; // [esp-8h] [ebp-Ch]

  CVProfNode::CVProfNode(
    this: (CVProfNode *)pptlocid,
    a2: a4,
    a3: (const char *)&ptloci.lc_category[3].wlocale,
    a4: a2,
    a5: v6,
    a6: v7,
    a7: v8);
  *(_BYTE *)(a3 - 4) = 3;
  a4->m_GroupIDStack[1] = v5;
  a4->m_GroupIDStack[0] = v5;
  memset(&a4->m_GroupIDStack[330], 0, 0x400u);
  *(_DWORD *)(a3 - 4) = -1;
  JUMPOUT(0x3F017EF5);
}

//------------------------------------------------------------------------------
// Address: 0x3F017EF6
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall __updatetlocinfo(void *this)
{
  MEMORY[0] = this;
}

//------------------------------------------------------------------------------
// Address: 0x3F017F6C
// Name: _use_encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall use_encode_pointer(int a1@<eax>, char a2@<ch>, CVProfile *a3@<esi>)
{
  _DWORD *v3; // eax
  char *bEncode; // [esp+0h] [ebp-8h]
  int winmajor; // [esp+4h] [ebp-4h]

  v3 = (_DWORD *)(a1 - 9961472);
  ++*v3;
  *((_BYTE *)v3 + (_DWORD)&unk_3F03AFFF - 1057206395) += a2;
  CVProfile::BudgetGroupNameToBudgetGroupID(this: a3, a2: bEncode, a3: winmajor);
  CVProfile::BudgetGroupNameToBudgetGroupID(this: a3, a2: (char *)&ptloci.lc_category[5].wrefcount, a3: 0xFFFF);
  CVProfile::BudgetGroupNameToBudgetGroupID(this: a3, a2: (char *)&ptloci.mb_cur_max, a3: 0xFFFF);
  CVProfile::BudgetGroupNameToBudgetGroupID(this: a3, a2: (char *)&ptloci.lconv_num_refcount, a3: 0xFFFF);
  CVProfile::BudgetGroupNameToBudgetGroupID(this: a3, a2: (char *)&ptloci.ctype1_refcount, a3: 0xFFFF);
  CVProfile::BudgetGroupNameToBudgetGroupID(this: a3, a2: (char *)&ptloci.lc_time_curr, a3: 0xFFFF);
  JUMPOUT(0x3F017FDA);
}

//------------------------------------------------------------------------------
// Address: 0x3F018046
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall _encoded_null(CVProfile *this)
{
  char *v1; // [esp-8h] [ebp-8h]
  int v2; // [esp-4h] [ebp-4h]

  __asm { into }
  CVProfile::BudgetGroupNameToBudgetGroupID(this, a2: v1, a3: v2);
  JUMPOUT(0x3F018051);
}

//------------------------------------------------------------------------------
// Address: 0x3F0180BD
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __crtTlsAlloc(_BYTE *a1@<ebx>, void (__stdcall *lpCallBack)(void *))
{
  *a1 += BYTE1(a1);
  JUMPOUT(0x3F0180C6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0180DB
// Name: ___get_flsindex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __get_flsindex()
{
  JUMPOUT(0x3F0180DD);
}

//------------------------------------------------------------------------------
// Address: 0x3F0180E1
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall __set_flsgetvalue@<al>(_BYTE *a1@<eax>, int a2@<ecx>, int a3@<ebx>)
{
  char result; // al

  result = *a1 | (unsigned __int8)a1;
  *(_DWORD *)(a3 + 676998) += a2;
  *(_BYTE *)a3 += BYTE1(a3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F018113
// Name: __fls_setvalue(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __fls_setvalue(int a1@<ecx>, int a2@<ebp>, unsigned int dwFlsIndex, void *lpFlsData)
{
  *(_BYTE *)(a1 + 1569254469) += a1;
  sub_3F00CB00();
  *(_DWORD *)(a2 - 4) = -1;
  JUMPOUT(0x3F018127);
}

//------------------------------------------------------------------------------
// Address: 0x3F01812C
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F018228
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _getptd_noexit(int a1@<ebx>, void **a2@<edi>, CVProfile *a3@<esi>)
{
  void *v3; // eax
  int v4; // edi
  struct CVProfNode *v5; // eax
  struct CVProfNode *m_pSibling; // ebx

  ((void (*)(void))AssertMsgImplementation)();
  v3 = *a2;
  if ( *a2 == nullptr )
    goto LABEL_3;
  while ( 1 )
  {
    j_j__free(Block: v3);
    *a2 = nullptr;
LABEL_3:
    ++a1;
    ++a2;
    if ( a1 >= a3->m_GroupIDStack[586] )
      break;
    v3 = *a2;
    if ( *a2 == nullptr )
      JUMPOUT(0x3F018218);
  }
  v4 = a3->m_GroupIDStack[1];
  a3->m_GroupIDStack[586] = 0;
  if ( v4 != 0 )
  {
    v5 = *(struct CVProfNode **)(v4 + 116);
    if ( v5 != nullptr )
    {
      do
      {
        m_pSibling = v5->m_pSibling;
        CVProfile::FreeNodes_R(this: a3, a2: v5);
        v5 = m_pSibling;
      }
      while ( m_pSibling != nullptr );
    }
    if ( v4 == a3->m_GroupIDStack[1] )
      *(_DWORD *)(v4 + 116) = 0;
    else
      _getptd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01829F
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _getptd(void **a1@<edi>)
{
  j_j__free(Block: *a1);
  JUMPOUT(0x3F0182B6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0183D8
// Name: __freeptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _freeptd(const char *a1@<eax>, char *a2@<edi>, int a3@<esi>)
{
  int v3; // edx
  char *v4; // eax
  int v5; // edx
  char v6; // cl
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // ecx

  v3 = ((int (__cdecl *)(unsigned int))byte_3F01A077)(a1: strlen(a1) + 1);
  v4 = a2;
  v5 = v3 - (_DWORD)a2;
  do
  {
    v6 = *v4;
    v4[v5] = *v4;
    ++v4;
  }
  while ( v6 != 0 );
  v7 = *(_DWORD *)(a3 + 36);
  v8 = *(_DWORD *)(a3 + 32);
  if ( v7 + 1 > v8 )
  {
    v9 = 2 * v8;
    v10 = v7 + 6;
    *(_DWORD *)(a3 + 32) = v9;
    if ( v10 > v9 )
      v9 = v10;
    *(_DWORD *)(a3 + 32) = v9;
    ((void (__cdecl *)(int))byte_3F01A077)(a1: (unsigned __int64)(unsigned int)v9 >> 29 != 0 ? -1 : 8 * v9);
    JUMPOUT(0x3F018440);
  }
  JUMPOUT(0x3F018478);
}

//------------------------------------------------------------------------------
// Address: 0x3F018441
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge _mtinit@<eax>(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int a5, int a6)
{
  int i; // eax
  int v7; // ecx
  void (*v8)(void); // eax

  for ( i = 0; i < *(_DWORD *)(a4 + 36); ++i )
  {
    v7 = *(_DWORD *)(a4 + 28);
    *(_DWORD *)(a3 + 8 * i) = *(_DWORD *)(v7 + 8 * i);
    *(_DWORD *)(a3 + 8 * i + 4) = *(_DWORD *)(v7 + 8 * i + 4);
  }
  j_j__free(Block: *(void **)(a4 + 28));
  *(_DWORD *)(a4 + 28) = a3;
  *(_DWORD *)(*(_DWORD *)(a4 + 28) + 8 * *(_DWORD *)(a4 + 36)) = a1;
  *(_DWORD *)(*(_DWORD *)(a4 + 28) + 8 * *(_DWORD *)(a4 + 36) + 4) = *(_DWORD *)(a2 + 12);
  v8 = *(void (**)(void))(a4 + 40);
  ++*(_DWORD *)(a4 + 36);
  if ( v8 != nullptr )
    v8();
  return *(_DWORD *)(a4 + 36) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F0185C5
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __noreturn _crtLCMapStringA_stat(
        int a1@<eax>,
        unsigned int Locale,
        unsigned int dwMapFlags,
        const char *lpSrcStr,
        const char *cchSrc,
        char *lpDestStr,
        char *cchDest,
        int code_page,
        int bError)
{
  _close(fh: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F018860
// Name: sub_3F018860
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_3F018860(int a1, int a2, unsigned int *a3)
{
  int v3; // ebx
  int *v4; // edi
  int *v5; // eax
  bool v6; // cl
  unsigned int v7; // esi
  int *v8; // eax
  int *v9; // eax
  int v10; // ecx
  int *v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+4h] [ebp-18h]
  int v17; // [esp+8h] [ebp-14h]
  int v18; // [esp+10h] [ebp-Ch] BYREF
  int *v19; // [esp+14h] [ebp-8h]

  v3 = a2;
  v4 = *(int **)(a1 + 4);
  v5 = (int *)v4[1];
  v6 = true;
  LOBYTE(a2) = 1;
  if ( *((_BYTE *)v5 + 33) == 0 )
  {
    v7 = *a3;
    do
    {
      v4 = v5;
      v6 = v7 < v5[4];
      LOBYTE(a2) = v6;
      if ( v7 >= v5[4] )
        v5 = (int *)v5[2];
      else
        v5 = (int *)*v5;
    }
    while ( *((_BYTE *)v5 + 33) == 0 );
  }
  v8 = v4;
  v19 = v4;
  v18 = a1;
  if ( v6 )
  {
    if ( v4 == **(int ***)(a1 + 4) )
    {
      v9 = (int *)((int (__thiscall *)(int *, int *, int, unsigned int *))loc_3F018BF0)(a1: v4, a2: &v18, a3: 1, a4: a3);
      v10 = *v9;
      *(_DWORD *)(v3 + 4) = v9[1];
      *(_BYTE *)(v3 + 8) = 1;
      *(_DWORD *)v3 = v10;
      return v3;
    }
    ((void (__stdcall *)(int, int, int))loc_3F019600)(a1: v15, a2: v16, a3: v17);
    v8 = v19;
  }
  if ( v8[4] >= *a3 )
  {
    v14 = v18;
    *(_DWORD *)(v3 + 4) = v8;
    *(_BYTE *)(v3 + 8) = 0;
    *(_DWORD *)v3 = v14;
  }
  else
  {
    v12 = (int *)((int (__thiscall *)(int *, int *, int, unsigned int *))loc_3F018BF0)(a1: v4, a2: &v18, a3: a2, a4: a3);
    v13 = *v12;
    *(_DWORD *)(v3 + 4) = v12[1];
    *(_DWORD *)v3 = v13;
    *(_BYTE *)(v3 + 8) = 1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F018967
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn __crtLCMapStringA(char a1@<dh>, int a2@<ecx>, int a3@<ebx>, int a4@<ebp>)
{
  _BYTE v4[101]; // [esp+1h] [ebp-75h]

  LOBYTE(a3) = BYTE1(a2) | a3;
  *(_DWORD *)(a3 + 561610761) = __ROR4__(*(_DWORD *)(a3 + 561610761), 1);
  v4[8 * a4] += a1;
  *(_DWORD *)(a2 + 1971976277) = __ROR4__(*(_DWORD *)(a2 + 1971976277), 1);
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F0189AA
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge _get_errno_from_oserr@<al>(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ecx>, unsigned int oserrno)
{
  LOBYTE(a1) = (_BYTE)a1 + 95;
  *a1 = a2;
  a1[1] = a3;
  return (char)a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F0189E5
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _errno(char a1@<cf>, int a2@<eax>, int a3@<esi>)
{
  *(_DWORD *)(a1 + a2 + 1 + 71731973) = a1 + a2 + 1 + 71731969;
  **(_DWORD **)(a3 + 4) = *(_DWORD *)(a3 + 4);
  JUMPOUT(0x3F0189F6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0189F8
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __doserrno(_BYTE *a1@<eax>)
{
  *a1 |= (unsigned __int8)a1;
  JUMPOUT(0x3F0189FD);
}

//------------------------------------------------------------------------------
// Address: 0x3F018A30
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall memset(char a1@<pf>, int a2@<edx>, int a3@<ebx>, int a4@<ebp>, int a5@<edi>)
{
  int v5; // eax
  bool v6; // zf

  if ( !a1 )
  {
    v5 = *(_DWORD *)(a5 + 4);
    v6 = *(_BYTE *)(v5 + 21) == 0;
    *(_BYTE *)(a4 + 12) = 1;
    if ( v6 )
    {
      *(_BYTE *)(a4 + 12) = **(_DWORD **)(a4 + 16) < *(_DWORD *)(v5 + 12);
      JUMPOUT(0x3F018A5B);
    }
    *(_DWORD *)(a4 - 8) = a5;
    *(_DWORD *)(a4 - 12) = a2;
    if ( a5 == **(_DWORD **)(a2 + 4) )
    {
      *(_DWORD *)(a3 + 4) = *(_DWORD *)(((int (__thiscall *)(int, int, int, _DWORD))loc_3F018E10)(
                                          a1: a5,
                                          a2: a4 - 12,
                                          a3: 1,
                                          a4: *(_DWORD *)(a4 + 16))
                                      + 4);
      JUMPOUT(0x3F018A8F);
    }
    JUMPOUT(0x3F018AA3);
  }
  JUMPOUT(0x3F018A36);
}

//------------------------------------------------------------------------------
// Address: 0x3F018AAA
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(void *enull)
{
  _callnewh(size: (unsigned int)enull);
}

//------------------------------------------------------------------------------
// Address: 0x3F018AB4
// Name: __callnewh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _callnewh(unsigned int *a1@<ecx>, _DWORD *a2@<ebx>, int a3@<ebp>, int a4@<edi>, unsigned int a5@<esi>)
{
  int *v5; // eax
  int v6; // edx

  if ( a5 < *a1 )
  {
    v5 = (int *)((int (__thiscall *)(int, int, _DWORD, unsigned int *))loc_3F018E10)(
                  a1: a4,
                  a2: a3 - 12,
                  a3: *(_DWORD *)(a3 + 12),
                  a4: a1);
    v6 = *v5;
    a2[1] = v5[1];
    *a2 = v6;
    JUMPOUT(0x3F018AD4);
  }
  JUMPOUT(0x3F018AE3);
}

//------------------------------------------------------------------------------
// Address: 0x3F018AD6
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge _flsbuf@<eax>(char a1@<al>, _BYTE *a2@<ecx>, int a3@<ebx>, int ch, _iobuf *str, int fh)
{
  *a2 |= a1;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x3F018C36
// Name: write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>, int a4@<ebp>)
{
  --*(int *)((char *)&f[36466659]._charbuf + 1);
  __asm { aam     50h ; 'P' }
  ((void (__thiscall *)(int))loc_3F00E080)(a1: a4 - 84);
  *(_BYTE *)(a4 - 4) = 1;
  *(_DWORD *)(a4 - 84) = &std::length_error::`vftable';
  *(_BYTE *)(a4 - 4) = 0;
  _CxxThrowException(pExceptionObject: (void *)(a4 - 84), pThrowInfo: (_ThrowInfo *)&stru_3F034868);
}

//------------------------------------------------------------------------------
// Address: 0x3F018C69
// Name: write_multi_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_multi_char(int *pnumwritten@<eax>, int a2@<ebp>, _iobuf *a3@<edi>, int *a4@<esi>, int ch)
{
  char *v5; // ecx
  int *cnt; // eax

  v5 = (char *)((int (__stdcall *)(int *))loc_3F00D810)(a1: pnumwritten);
  cnt = (int *)a3->_cnt;
  ++a3->_base;
  *(_DWORD *)(a2 + 16) = v5;
  if ( a4 != cnt )
    JUMPOUT(0x3F018C94);
  cnt[1] = (int)v5;
  write_string(string: v5, len: ch, f: a3, pnumwritten: cnt);
}

//------------------------------------------------------------------------------
// Address: 0x3F018C8D
// Name: write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(char *string@<ecx>, _iobuf *f@<edi>, _DWORD *a3@<edx>)
{
  *a3 = string;
  *(_DWORD *)(f->_cnt + 8) = string;
  if ( *(_BYTE *)(*((_DWORD *)string + 1) + 32) == 0 )
  {
    if ( *((_DWORD *)string + 1) == **(_DWORD **)(*((_DWORD *)string + 1) + 4) )
      JUMPOUT(0x3F018CD7);
    JUMPOUT(0x3F018D5C);
  }
  JUMPOUT(0x3F018DE8);
}

//------------------------------------------------------------------------------
// Address: 0x3F018CD7
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge _output_l@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        char a4@<bl>,
        int a5@<ebp>,
        int a6@<edi>,
        int a7@<esi>,
        _iobuf *stream,
        const char *format,
        localeinfo_struct *plocinfo,
        char *argptr)
{
  _DWORD *v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // edx
  _DWORD *v15; // edx
  int v16; // ecx
  _DWORD *result; // eax
  int v18; // [esp+6Ch] [ebp-14h]
  int v19; // [esp+70h] [ebp-10h]
  int v20; // [esp+74h] [ebp-Ch]
  int v21; // [esp+78h] [ebp-8h]
  int v22; // [esp+7Ch] [ebp-4h]

  if ( *(_BYTE *)(a2 + 32) != 0 )
  {
    if ( a7 == *(_DWORD *)(a3 + 8) )
    {
      a7 = a3;
      ((void (__stdcall *)(int, int, int, int, int, int))loc_3F00D750)(
        a1: a6,
        a2: v18,
        a3: v19,
        a4: v20,
        a5: v21,
        a6: v22);
    }
    *(_BYTE *)(*(_DWORD *)(a7 + 4) + 32) = a4;
    *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a7 + 4) + 4) + 32) = 0;
    v11 = *(_DWORD **)(*(_DWORD *)(a7 + 4) + 4);
    v12 = *v11;
    *v11 = *(_DWORD *)(*v11 + 8);
    v13 = *(_DWORD *)(v12 + 8);
    if ( *(_BYTE *)(v13 + 33) == 0 )
      *(_DWORD *)(v13 + 4) = v11;
    *(_DWORD *)(v12 + 4) = v11[1];
    v14 = *(_DWORD *)(a6 + 4);
    if ( v11 == *(_DWORD **)(v14 + 4) )
    {
      *(_DWORD *)(v14 + 4) = v12;
      *(_DWORD *)(v12 + 8) = v11;
    }
    else
    {
      v15 = (_DWORD *)v11[1];
      if ( v11 == (_DWORD *)v15[2] )
        v15[2] = v12;
      else
        *v15 = v12;
      *(_DWORD *)(v12 + 8) = v11;
    }
    v11[1] = v12;
  }
  else
  {
    *(_BYTE *)(a3 + 32) = a4;
    *(_BYTE *)(a2 + 32) = a4;
    *(_BYTE *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + 32) = 0;
    a7 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  }
  if ( *(_BYTE *)(*(_DWORD *)(a7 + 4) + 32) == 0 )
    JUMPOUT(0x3F018CC7);
  v16 = *(_DWORD *)(a5 + 16);
  *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a6 + 4) + 4) + 32) = a4;
  result = *(_DWORD **)(a5 + 8);
  result[1] = v16;
  *result = a6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01966B
// Name: fastcopy_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall fastcopy_I(int a1@<eax>, char a2@<dh>, char a3@<bh>, int a4@<ebp>, _DWORD *a5@<esi>)
{
  int *v5; // eax
  int v6; // eax
  int v7; // ecx
  int j; // eax
  int i; // eax

  *(_BYTE *)(a4 + a1 - 23) += a2;
  MEMORY[0x46890000] |= a3;
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  if ( *a5 == 0 )
    _invalid_parameter_noinfo_0();
  v5 = (int *)a5[1];
  if ( *((_BYTE *)v5 + 21) != 0 )
  {
    v6 = v5[2];
    a5[1] = v6;
    if ( *(_BYTE *)(v6 + 21) == 0 )
      JUMPOUT(0x3F0196F6);
    _invalid_parameter_noinfo_0();
  }
  else
  {
    v7 = *v5;
    if ( *(_BYTE *)(*v5 + 21) != 0 )
    {
      for ( i = v5[1]; *(_BYTE *)(i + 21) == 0; i = *(_DWORD *)(i + 4) )
      {
        if ( a5[1] != *(_DWORD *)i )
          break;
        a5[1] = i;
      }
      if ( *(_BYTE *)(a5[1] + 21) != 0 )
        JUMPOUT(0x3F0196EE);
      JUMPOUT(0x3F0196F3);
    }
    for ( j = *(_DWORD *)(v7 + 8); *(_BYTE *)(j + 21) == 0; j = *(_DWORD *)(j + 8) )
      v7 = j;
    a5[1] = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0196F2
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall _VEC_memcpy@<eax>(char *result@<eax>, char *a2@<edx>, int a3@<ecx>, void *dst)
{
  void *v4; // edi

  *(_BYTE *)(a3 - 859634618) += a3;
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  while ( result != a2 )
  {
    v4 = result;
    result += 32;
    qmemcpy(v4, dst, 0x20u);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F019730
// Name: sub_3F019730
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall sub_3F019730(int a1, char *a2, char *a3)
{
  int result; // eax
  bool v5; // zf
  int v6; // eax
  int v7; // [esp+10h] [ebp+8h]

  result = a1 - 32 * ((a2 - a3) >> 5);
  v5 = a3 == a2;
  v7 = result;
  if ( !v5 )
  {
    v6 = a1 - (_DWORD)a2;
    do
    {
      a2 -= 32;
      qmemcpy(&a2[v6], a2, 0x20u);
    }
    while ( a2 != a3 );
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0197D5
// Name: __sse2_mathfcns_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _sse2_mathfcns_init()
{
  JUMPOUT(0x3F0197EA);
}

//------------------------------------------------------------------------------
// Address: 0x3F0197F0
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strrchr(char a1@<cf>, int a2@<eax>, int a3@<edx>, int a4@<ebx>, int a5@<esi>)
{
  LOBYTE(a2) = a1 + a2 - 117;
  ((void (__cdecl *)(int, int, int, int))loc_3F019790)(a1: a4, a2, a3: a5, a4: a3);
  JUMPOUT(0x3F01981B);
}

//------------------------------------------------------------------------------
// Address: 0x3F01981D
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__usercall __iob_func@<eax>(char a1@<bh>, int a2@<edi>)
{
  *(_BYTE *)(a2 - 114) &= a1;
  return (_iobuf *)__initstdio();
}

//------------------------------------------------------------------------------
// Address: 0x3F019823
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall __initstdio@<eax>(char a1@<zf>, char a2@<sf>, char a3@<of>, int a4@<ebx>, int a5@<ebp>, int a6@<edi>)
{
  int result; // eax

  if ( !(a2 ^ a3 | a1) )
    return sub_3F019BB0(a1: a4, a2: a6, a3: *(_DWORD *)(a5 + 20));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0198D4
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __endstdio()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0198F4
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _lock_file(
        volatile signed __int8 *a1@<eax>,
        unsigned __int16 a2@<dx>,
        int a3@<ecx>,
        int a4@<ebx>,
        int a5@<ebp>)
{
  int v5; // ebx

  LOBYTE(a1) = __inbyte(a2);
  _InterlockedAdd8(a1, (unsigned __int8)a1);
  *(_BYTE *)(a4 + 1448284237) += a3;
  v5 = *(_DWORD *)(a5 + 12) + 32 * (((a3 - *(_DWORD *)(a5 + 12)) >> 5) / 2);
  sub_3F019C50(a1: v5, a2: *(_DWORD *)(a5 + 20));
  *(_DWORD *)(a5 - 4) = v5 + 32;
  JUMPOUT(0x3F01992F);
}

//------------------------------------------------------------------------------
// Address: 0x3F019930
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _lock_file2(
        char a1@<cl>,
        unsigned int a2@<ebx>,
        int a3@<ebp>,
        unsigned __int8 (*a4)(void)@<edi>,
        unsigned int a5@<esi>)
{
  *(_BYTE *)(a3 + 1448337523) &= a1;
  if ( a4() != 0
    || ((unsigned __int8 (__cdecl *)(unsigned int, unsigned int))a4)(a1: a2, a2: a5) != 0
    || (a2 = a5, *(_DWORD *)(a3 + 12) >= a5) )
  {
    if ( *(_DWORD *)(a3 - 4) < *(_DWORD *)(a3 + 16) )
      JUMPOUT(0x3F019960);
    *(_DWORD *)(a3 - 8) = *(_DWORD *)(a3 - 4);
    *(_DWORD *)(a3 - 12) = a2;
    JUMPOUT(0x3F019992);
  }
  JUMPOUT(0x3F019931);
}

//------------------------------------------------------------------------------
// Address: 0x3F019994
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _unlock_file2(
        bool a1@<cf>,
        char a2@<dh>,
        int a3@<ebx>,
        int a4@<ebp>,
        unsigned __int8 (*a5)(void)@<edi>,
        unsigned int a6@<esi>,
        int i,
        _iobuf *s)
{
  unsigned int v8; // eax
  void *v9; // eax
  void *v10; // ebx

  *(_BYTE *)(a3 + 93) += a2 + a1;
  while ( a5() != 0 )
  {
    a6 += 32;
    a1 = a6 < *(_DWORD *)(a4 + 16);
    *(_DWORD *)(a4 - 8) = a6;
    if ( !a1 )
      goto LABEL_7;
  }
  if ( ((unsigned __int8 (__cdecl *)(unsigned int, int))a5)(a1: a6, a2: a3) == 0 )
  {
    *(_DWORD *)(a4 - 4) += 32;
    JUMPOUT(0x3F0199C0);
  }
LABEL_7:
  v8 = *(_DWORD *)(a4 - 12);
  if ( *(_DWORD *)(a4 + 12) >= v8 )
    goto LABEL_12;
  *(_DWORD *)(a4 - 16) = v8 - 32;
  if ( ((unsigned __int8 (__cdecl *)(_DWORD, int))a5)(a1: *(_DWORD *)(a4 - 16), a2: a3) == 0 )
  {
    if ( ((unsigned __int8 (__cdecl *)(int, _DWORD))a5)(a1: a3, a2: *(_DWORD *)(a4 - 16)) == 0 )
    {
      v9 = *(void **)(a4 - 16);
      v10 = (void *)(a3 - 32);
      qmemcpy((void *)(a4 - 48), v10, 0x20u);
      qmemcpy(v10, v9, 0x20u);
      qmemcpy(v9, (const void *)(a4 - 48), 0x20u);
      goto LABEL_11;
    }
LABEL_12:
    JUMPOUT(0x3F019A5F);
  }
LABEL_11:
  *(_DWORD *)(a4 - 16) -= 32;
  _ftbuf(flag: i, str: s);
}

//------------------------------------------------------------------------------
// Address: 0x3F019A54
// Name: __ftbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _ftbuf(int a1@<eax>, int a2@<ebx>, _DWORD *a3@<ebp>, const void *a4@<esi>)
{
  unsigned int v4; // eax
  bool v5; // cf
  int v6; // eax
  void *v7; // eax
  bool v8; // zf
  void *v9; // ebx
  void *v10; // eax
  char *v11; // edx
  void *v12; // eax
  _DWORD *v13; // eax
  int v14; // edx

  v4 = a1 - 32;
  v5 = a3[3] < v4;
  *(a3 - 3) = v4;
  if ( v5 )
    JUMPOUT(0x3F019A02);
  v6 = *(a3 - 3);
  if ( v6 != a3[3] )
  {
    v7 = (void *)(v6 - 32);
    v8 = a4 == (const void *)a3[4];
    *(a3 - 3) = v7;
    if ( v8 )
    {
      v9 = (void *)(a2 - 32);
      if ( v7 != v9 )
      {
        qmemcpy(a3 - 28, v7, 0x20u);
        qmemcpy(v7, v9, 0x20u);
        qmemcpy(v9, a3 - 28, 0x20u);
      }
      *(a3 - 1) -= 32;
      v10 = (void *)*(a3 - 1);
      qmemcpy(a3 - 44, v9, 0x20u);
      qmemcpy(v9, v10, 0x20u);
      qmemcpy(v10, a3 - 44, 0x20u);
    }
    else
    {
      v11 = (char *)*(a3 - 2);
      v12 = (void *)*(a3 - 3);
      qmemcpy(a3 - 60, a4, 0x20u);
      qmemcpy(v11, v12, 0x20u);
      qmemcpy(v12, a3 - 60, 0x20u);
      *(a3 - 2) = v11 + 32;
    }
    JUMPOUT(0x3F019992);
  }
  if ( a4 != (const void *)a3[4] )
  {
    if ( (const void *)*(a3 - 1) != a4 )
      JUMPOUT(0x3F019A7F);
    JUMPOUT(0x3F019AA4);
  }
  v13 = (_DWORD *)a3[2];
  v14 = *(a3 - 1);
  *v13 = a2;
  v13[1] = v14;
}

//------------------------------------------------------------------------------
// Address: 0x3F019AC9
// Name: __SEH_epilog4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _SEH_epilog4_0(void *a1@<eax>, int a2@<ecx>, int a3@<ebp>, void *a4@<edi>, const void *a5@<esi>)
{
  _disable();
  qmemcpy(a4, a5, 4 * a2);
  qmemcpy(a1, (const void *)(a3 - 80), 0x20u);
  JUMPOUT(0x3F019ADE);
}

//------------------------------------------------------------------------------
// Address: 0x3F019BB0
// Name: sub_3F019BB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F019BB0(int a1, int a2, int (__cdecl *a3)(int, int))
{
  int result; // eax
  int v4; // edi
  int v5; // esi
  int v6; // ebx
  int v7; // edi
  int v8; // ebx
  int v9; // [esp+4h] [ebp-4h]

  result = a2;
  v4 = a1;
  if ( a1 != a2 )
  {
    v5 = a1 + 32;
    if ( a1 + 32 != a2 )
    {
      v6 = a1 + 64;
      v9 = a1 + 64;
      do
      {
        result = a3(a1: v5, a2: v4);
        if ( (_BYTE)result != 0 )
        {
          if ( v4 != v5 && v5 != v6 )
            result = ((int (__cdecl *)(int, int))loc_3F019FB0)(a1: v4, a2: v6);
        }
        else
        {
          v7 = v6 - 64;
          result = a3(a1: v5, a2: v6 - 64);
          if ( (_BYTE)result != 0 )
          {
            do
            {
              v8 = v7;
              v7 -= 32;
              result = a3(a1: v5, a2: v7);
            }
            while ( (_BYTE)result != 0 );
            if ( v8 != v5 && v5 != v9 )
              result = ((int (__cdecl *)(int, int))loc_3F019FB0)(a1: v8, a2: v9);
            v6 = v9;
          }
          v4 = a1;
        }
        v5 += 32;
        v6 += 32;
        v9 = v6;
      }
      while ( v5 != a2 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F019C50
// Name: sub_3F019C50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__usercall sub_3F019C50@<eax>(int a1@<eax>, int a2@<ecx>, const char *a3, const char *a4, int a5, _iobuf *a6)
{
  if ( (a1 - a2) >> 5 <= 40 )
    JUMPOUT(0x3F019CD5);
  return _openfile(filename: a3, mode: a4, shflag: a5, str: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F019C76
// Name: __openfile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F019F16
// Name: __getstream
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01A048
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _local_unwind4@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, void *a4@<ebx>, int a5@<ebp>)
{
  int v5; // ecx
  int result; // eax
  bool v7; // zf

  if ( *(_DWORD *)(a5 + 8) + 32 * (a2 - a3) != a1 )
    JUMPOUT(0x3F01A025);
  qmemcpy(a4, (const void *)(a5 - 44), 0x20u);
  v5 = *(_DWORD *)(a5 - 4) - 1;
  result = a1 - 32;
  v7 = *(_DWORD *)(a5 - 4) == 1;
  *(_DWORD *)(a5 - 4) = v5;
  if ( v5 >= 0 && !v7 )
    JUMPOUT(0x3F01A006);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01A07C
// Name: sub_3F01A07C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn sub_3F01A07C()
{
  _DWORD pExceptionObject[10]; // [esp+10h] [ebp-50h] BYREF
  _BYTE v1[36]; // [esp+38h] [ebp-28h] BYREF
  int v2; // [esp+5Ch] [ebp-4h]

  sub_3F00C150(a1: "string too long");
  v2 = 0;
  ((void (__thiscall *)(_DWORD *, _BYTE *))loc_3F00E080)(a1: pExceptionObject, a2: v1);
  pExceptionObject[0] = &std::length_error::`vftable';
  _CxxThrowException(pExceptionObject, pThrowInfo: (_ThrowInfo *)&stru_3F034868);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A0D8
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn unwind_handler4(int a1@<ebp>, int a2)
{
  ((void (__thiscall *)(int, int))loc_3F00E080)(a1: a1 - 80, a2: a1 - 40);
  *(_DWORD *)(a1 - 80) = &std::out_of_range::`vftable';
  _CxxThrowException(pExceptionObject: (void *)(a1 - 80), pThrowInfo: (_ThrowInfo *)&pThrowInfo);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A11E
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge _seh_longjmp_unwind4(int a1@<eax>, void *a2@<ecx>, _DWORD *a3@<esi>, unsigned int Dummy)
{
  if ( a2 != off_3F03B8D8 && (dword_3F03B7F4 & *(_DWORD *)(a1 + 112)) == 0 )
    *a3 = __updatetlocinfo_0();
  JUMPOUT(0x3F01A138);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A13A
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _EH4_CallFilterFunc(int a1@<eax>, int a2@<esi>)
{
  LOBYTE(a1) = a1 + 59;
  if ( (volatile LONG **)((char *)&lpAddend + a1) != nullptr
    && (dword_3F03B7F4 & *(_DWORD *)(*(_DWORD *)(a2 + 8) + 112)) == 0 )
  {
    JUMPOUT(0x3F01A151);
  }
  JUMPOUT(0x3F01A159);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A151
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge _EH4_TransferToHandler@<eax>(int a1@<esi>, int a2)
{
  int v2; // eax

  *(_DWORD *)(a1 + 4) = ((int (*)(void))__updatetmbcinfo_0)();
  v2 = *(_DWORD *)(a1 + 8);
  if ( (*(_BYTE *)(v2 + 112) & 2) != 0 )
    JUMPOUT(0x3F01A176);
  *(_DWORD *)(v2 + 112) |= 2u;
  *(_BYTE *)(a1 + 12) = 1;
  return _EH4_GlobalUnwind(a1: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A16A
// Name: _EH4_GlobalUnwind(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge _EH4_GlobalUnwind@<eax>(int a1@<esi>, int a2)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01A184
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01A19B
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall _ioinit@<eax>(char a1@<bl>, int a2@<ebp>)
{
  char *result; // eax
  const char *v3; // [esp+58h] [ebp-Ch]

  result = strstr(Str: *(const char **)(a2 + 8), SubStr: v3);
  if ( *(_BYTE *)(a2 - 12) != a1 )
    *(_DWORD *)(*(_DWORD *)(a2 - 16) + 112) &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01A2BB
// Name: sub_3F01A2BB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int sub_3F01A2BB()
{
  void *retaddr; // [esp+0h] [ebp+0h]

  return ((int (__stdcall *)(void *))loc_3F01A17C)(a1: retaddr);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A2CE
// Name: __mbsicmp_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __noreturn _mbsicmp_l_0(const unsigned __int8 *Str1, const unsigned __int8 *Str2, _locale_t Locale)
{
  _BYTE v3[20]; // [esp+4h] [ebp-14h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v3, a2: Locale);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A3DB
// Name: __ioterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ioterm(unsigned __int8 *a1@<ebx>, int a2@<ebp>)
{
  int v2; // ebp
  int v3; // edx
  _BYTE *v4; // ebx

  v2 = a2 - 1;
  ++*(_DWORD *)(v2 + 8);
  v3 = *a1;
  v4 = a1 + 1;
  if ( (*(_BYTE *)(v3 + *(_DWORD *)(v2 - 16) + 29) & 4) != 0 )
  {
    if ( *v4 == 0 )
      JUMPOUT(0x3F01A48E);
    JUMPOUT(0x3F01A426);
  }
  JUMPOUT(0x3F01A472);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A427
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fileno(int a1@<ebp>, int a2@<edi>)
{
  if ( !__OFADD__(a2, a2) )
    __crtLCMapStringA_0(a1: a1 - 20);
  JUMPOUT(0x3F01A42F);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A454
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _close_nolock@<eax>(int a1@<ebp>, unsigned __int16 a2@<si>)
{
  int v2; // esi
  _BYTE *v3; // edx
  bool v4; // zf
  unsigned __int16 v5; // cx
  unsigned __int8 *v6; // edx
  int result; // eax

  v5 = *(unsigned __int8 *)(a1 - 3) + (*(unsigned __int8 *)(a1 - 4) << 8);
  if ( v5 == a2 )
  {
    if ( a2 != 0 )
    {
      v6 = *(unsigned __int8 **)(a1 + 8);
      v2 = *v6;
      v3 = v6 + 1;
      v4 = (*(_BYTE *)(v2 + *(_DWORD *)(a1 - 16) + 29) & 4) == 0;
      *(_DWORD *)(a1 + 8) = v3;
      if ( !v4 )
      {
        if ( *v3 != 0 )
          __crtLCMapStringA_0(a1: a1 - 20);
        JUMPOUT(0x3F01A40B);
      }
      JUMPOUT(0x3F01A3EF);
    }
    if ( *(_BYTE *)(a1 - 8) != 0 )
      *(_DWORD *)(*(_DWORD *)(a1 - 12) + 112) &= ~2u;
    return 0;
  }
  else
  {
    result = v5 < a2 ? 1 : -1;
    if ( *(_BYTE *)(a1 - 8) != 0 )
      *(_DWORD *)(*(_DWORD *)(a1 - 12) + 112) &= ~2u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01A4E8
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _close(unsigned __int8 *fh, const unsigned __int8 *fha)
{
  _mbsicmp_l_0(Str1: fh, Str2: fha, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A4FB
// Name: j__free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl j__free(void *Block)
{
  JUMPOUT(0x3F01A8E5);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A500
// Name: ??0bad_alloc@std@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::bad_alloc *__thiscall std::bad_alloc::bad_alloc(std::bad_alloc *this)
{
  std::exception::exception(this, a2: (const char *const *)&off_3F03B008, a3: 1);
  this->__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F01A519
// Name: ??2@YAPAXI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(size_t Size)
{
  void *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  while ( 1 )
  {
    result = malloc_0(Size);
    if ( result != nullptr )
      break;
    if ( _callnewh_0(Size) == 0 )
    {
      if ( (dword_3F03C7AC & 1) == 0 )
      {
        dword_3F03C7AC |= 1u;
        std::bad_alloc::bad_alloc(this: &stru_3F03C7A0);
        atexit_0(a1: sub_3F02EFE5);
      }
      std::exception::exception(this: &pExceptionObject, a2: &stru_3F03C7A0);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: (_ThrowInfo *)&stru_3F0348A0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01A583
// Name: __mbsnbcpy_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __noreturn _mbsnbcpy_l_0(
        unsigned __int8 *Dest,
        const unsigned __int8 *Source,
        size_t Count,
        _locale_t Locale)
{
  _BYTE v4[16]; // [esp+8h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v4, a2: Locale);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A5E1
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _NMSG_WRITE(
        bool a1@<zf>,
        int a2@<edx>,
        unsigned __int8 *a3@<ecx>,
        int a4@<ebx>,
        int a5@<ebp>,
        unsigned __int8 *a6@<esi>)
{
  unsigned __int8 v6; // al
  _BYTE *v7; // esi
  char *v8; // ecx
  char v9; // al

  if ( a1 )
  {
    ((void (__cdecl *)(unsigned __int8 *, unsigned __int8 *, _DWORD))loc_3F01B3F0)(
      a1: a6,
      a2: a3,
      a3: *(_DWORD *)(a5 + 16));
    if ( *(_BYTE *)(a5 - 4) != (_BYTE)a4 )
      *(_DWORD *)(*(_DWORD *)(a5 - 8) + 112) &= ~2u;
    return;
  }
  if ( *(_DWORD *)(a5 + 16) == a4 )
    goto LABEL_11;
  while ( 1 )
  {
    v6 = *a3;
    --*(_DWORD *)(a5 + 16);
    a1 = (*(_BYTE *)(v6 + a2 + 29) & 4) == 0;
    *a6 = v6;
    if ( !a1 )
      break;
    ++a6;
    ++a3;
    if ( v6 == (_BYTE)a4 )
      goto LABEL_9;
LABEL_15:
    if ( *(_DWORD *)(a5 + 16) == a4 )
      goto LABEL_11;
  }
  v7 = a6 + 1;
  v8 = (char *)(a3 + 1);
  if ( *(_DWORD *)(a5 + 16) == a4 )
  {
    *(v7 - 1) = a4;
    goto LABEL_11;
  }
  v9 = *v8;
  --*(_DWORD *)(a5 + 16);
  *v7 = v9;
  a6 = v7 + 1;
  a3 = (unsigned __int8 *)(v8 + 1);
  if ( v9 != (_BYTE)a4 )
    goto LABEL_15;
  *(a6 - 2) = a4;
LABEL_9:
  if ( *(_DWORD *)(a5 + 16) != a4 )
    memset_0(a1: a6, Val: a4, Size: *(_DWORD *)(a5 + 16));
LABEL_11:
  if ( *(_BYTE *)(a5 - 4) != (_BYTE)a4 )
    *(_DWORD *)(*(_DWORD *)(a5 - 8) + 112) &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x3F01A664
// Name: sub_3F01A664
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F01A664(unsigned __int8 *Dest, unsigned __int8 *Source, size_t Count)
{
  _mbsnbcpy_l_0(Dest, Source, Count, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A67B
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
// Address: 0x3F01A6B0
// Name: __stricmp_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __noreturn _stricmp_l_0(const char *String1, const char *String2, _locale_t Locale)
{
  _BYTE v3[16]; // [esp+4h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v3, a2: Locale);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A783
// Name: sub_3F01A783
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F01A783(int a1, int a2)
{
  if ( dword_3F03C854 != 0 )
    JUMPOUT(0x3F01A7C1);
  if ( a1 == 0 || a2 == 0 )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    JUMPOUT(0x3F01A7D0);
  }
  return _mtinitlocks();
}

//------------------------------------------------------------------------------
// Address: 0x3F01A7BA
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __cdecl _mtinitlocks(unsigned __int8 *a1, unsigned __int8 *a2)
{
  return __ascii_stricmp_0(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A822
// Name: _malloc_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01A858
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _unlock(int a1@<ebp>, int a2@<esi>, int locknum)
{
  if ( dword_3F0A48C4 != 1 )
    JUMPOUT(0x3F01A875);
  if ( a1 == a2 )
    JUMPOUT(0x3F01A86F);
  _mtinitlocknum(locknum);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A86D
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _mtinitlocknum@<eax>(int (__cdecl *a1)(HANDLE, int)@<ebx>, size_t a2@<ebp>, int a3@<esi>)
{
  int v3; // esi

  v3 = a1(a1: hHeap, a2: a3);
  if ( v3 == 0 )
  {
    if ( dword_3F03CCFC != 0 )
    {
      if ( _callnewh_0(Size: a2) != 0 )
      {
        if ( hHeap == nullptr )
        {
          ((void (*)(void))_FF_MSGBANNER_0)();
          ((void (__cdecl *)(int))_NMSG_WRITE_0)(a1: 30);
          JUMPOUT(0x3F01A856);
        }
        JUMPOUT(0x3F01A85D);
      }
    }
    else
    {
      *_errno_0() = 12;
    }
    *_errno_0() = 12;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F01A930
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _lock(int a1@<ebp>)
{
  if ( *(_DWORD *)(a1 - 28) == 0 && !HeapFree(hHeap: hHeap, dwFlags: 0, lpMem: *(LPVOID *)(a1 + 8)) )
  {
    _errno_0();
    JUMPOUT(0x3F01A95E);
  }
  JUMPOUT(0x3F01A96D);
}

//------------------------------------------------------------------------------
// Address: 0x3F01A961
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  _DWORD *v2; // esi

  __asm { lock add bh, [edi] }
  *v2 = ((int (__cdecl *)())loc_3F01FB70)();
}

//------------------------------------------------------------------------------
// Address: 0x3F01A985
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _RTC_Terminate()
{
  ((void (__cdecl *)(int))_NMSG_WRITE_0)(a1: 25);
  _set_abort_behavior_0(Flags: 0, Mask: 1u);
  abort_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F01A9D0
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
BOOL __thiscall _ValidateImageBase(_BYTE *this, unsigned __int8 *pImageBase)
{
  const char *v3; // [esp-8h] [ebp-8h]
  const char *v4; // [esp-4h] [ebp-4h]

  *this = __ROR1__(*this, 80);
  return strcmp_0(Str1: v3, Str2: v4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01AA00
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _FindPESection(int a1@<esi>)
{
  *_errno_0() = 22;
  _invalid_parameter_0(a1, a2: a1, a3: a1, a4: a1, a5: a1);
  JUMPOUT(0x3F01AA7C);
}

//------------------------------------------------------------------------------
// Address: 0x3F01AA50
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall _IsNonwritableInCurrentImage@<al>(char result@<al>, _BYTE *a2@<ebx>)
{
  *a2 += result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01AB0B
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn terminate(char a1@<zf>, int a2@<ebp>)
{
  if ( !a1 )
    *(_DWORD *)(*(_DWORD *)(a2 - 12) + 112) &= ~2u;
  JUMPOUT(0x3F01AB67);
}

//------------------------------------------------------------------------------
// Address: 0x3F01AB44
// Name: void unexpected(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn unexpected(int a1@<ecx>, int a2@<ebp>)
{
  *(_DWORD *)(a2 - 60) <<= *(_BYTE *)(a1 + 977402957) + a1;
  _inconsistency();
}

//------------------------------------------------------------------------------
// Address: 0x3F01AB57
// Name: void _inconsistency(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _inconsistency(char a1@<bl>, int a2@<ebp>)
{
  if ( *(_BYTE *)(a2 - 8) != a1 )
    *(_DWORD *)(*(_DWORD *)(a2 - 12) + 112) &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x3F01AB8E
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01AC2B
// Name: __vsnprintf_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l_0(
        char *const Buffer,
        const size_t BufferCount,
        const char *const Format,
        const _locale_t Locale,
        va_list ArgList)
{
  char *v6; // [esp+4h] [ebp-20h] BYREF
  size_t v7; // [esp+8h] [ebp-1Ch]
  char *v8; // [esp+Ch] [ebp-18h]
  int v9; // [esp+10h] [ebp-14h]

  if ( Format != nullptr )
  {
    if ( BufferCount == 0 || Buffer != nullptr )
    {
      v7 = 0x7FFFFFFF;
      if ( BufferCount <= 0x7FFFFFFF )
        v7 = BufferCount;
      v9 = 66;
      v8 = Buffer;
      v6 = Buffer;
      _output_l_0(a1: &v6, a2: Format, a3: Locale, a4: ArgList);
    }
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01ACDC
// Name: sub_3F01ACDC
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F01ACDC(char *Buffer, size_t BufferCount, char *Format, va_list ArgList)
{
  return _vsnprintf_l_0(Buffer, BufferCount, Format, Locale: nullptr, ArgList);
}

//------------------------------------------------------------------------------
// Address: 0x3F01ACF7
// Name: _sprintf_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf_0(char *const Buffer, const char *const Format, ...)
{
  return __CppXcptFilter(xcptnum: (unsigned int)Buffer, pxcptinfoptrs: (_EXCEPTION_POINTERS *)Format);
}

//------------------------------------------------------------------------------
// Address: 0x3F01ACFD
// Name: ___CppXcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __CppXcptFilter(int a1@<ebp>)
{
  int v1; // eax

  if ( *(_DWORD *)(a1 + 12) != 0 )
  {
    v1 = *(_DWORD *)(a1 + 8);
    if ( v1 != 0 )
    {
      *(_DWORD *)(a1 - 24) = v1;
      *(_DWORD *)(a1 - 32) = v1;
      JUMPOUT(0x3F01AD30);
    }
  }
  *_errno_0() = 22;
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  JUMPOUT(0x3F01AD1A);
}

//------------------------------------------------------------------------------
// Address: 0x3F01AD31
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01AD65
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void (__cdecl *__usercall __get_sigabrt@<eax>(int a1@<esi>))(int)
{
  int *v2; // [esp-14h] [ebp-14h]

  _get_fmode(pMode: v2);
  return (void (__cdecl *)(int))a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01AD72
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl raise(UINT signum)
{
  int (__cdecl *v1)(int); // eax

  ((void (*)(void))_FF_MSGBANNER_0)();
  ((void (__cdecl *)(UINT))_NMSG_WRITE_0)(a1: signum);
  v1 = (int (__cdecl *)(int))((int (__cdecl *)(void *))_decode_pointer)(a1: off_3F03B028);
  return v1(a1: 255);
}

//------------------------------------------------------------------------------
// Address: 0x3F01AF22
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(void *enull)
{
  _initp_misc_purevirt(enull);
}

//------------------------------------------------------------------------------
// Address: 0x3F01AF2C
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void *enull)
{
  ((void (__cdecl *)(int))_lock_0)(a1: 8);
  _initp_misc_initcrit(enull);
}

//------------------------------------------------------------------------------
// Address: 0x3F01AF36
// Name: __initp_misc_initcrit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _initp_misc_initcrit(int a1@<ebp>, int a2@<edi>)
{
  *(_DWORD *)(a1 - 4) = a2;
  JUMPOUT(0x3F01AF3C);
}

//------------------------------------------------------------------------------
// Address: 0x3F01AF40
// Name: __crtInitCritSecNoSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge _crtInitCritSecNoSpinCount(
        int a1@<ebx>,
        _DWORD *a2@<edi>,
        _RTL_CRITICAL_SECTION *lpCriticalSection,
        unsigned int dwSpinCount)
{
  if ( (_DWORD *)((char *)a2 + *a2) != nullptr )
  {
    dword_3F03C7F4 = a1;
    JUMPOUT(0x3F01AF4D);
  }
  JUMPOUT(0x3F01AFC2);
}

//------------------------------------------------------------------------------
// Address: 0x3F01AF50
// Name: ___crtInitCritSecAndSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtInitCritSecAndSpinCount@<eax>(int a1@<ebp>, _DWORD *a2@<edi>)
{
  char *v2; // edi
  int *v3; // esi
  int v4; // edi
  void (*v5)(void); // eax
  int result; // eax

  v2 = (char *)a2 + *a2;
  if ( *(char **)(a1 + 12) == v2 )
  {
    *(_DWORD *)(a1 - 28) = ((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F0A48D0);
    v3 = (int *)((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F0A48CC);
    *(_DWORD *)(a1 - 32) = v3;
    if ( *(char **)(a1 - 28) != v2 )
    {
      while ( 1 )
      {
        *(_DWORD *)(a1 - 32) = --v3;
        if ( (unsigned int)v3 < *(_DWORD *)(a1 - 28) )
          break;
        if ( *v3 != 0 )
        {
          v4 = *v3;
          if ( v4 != _encoded_null_0() )
          {
            v5 = (void (*)(void))((int (__cdecl *)(int))_decode_pointer)(a1: v4);
            v5();
          }
        }
      }
    }
    ((void (__cdecl *)(void *))loc_3F01ADE3)(a1: &unk_3F02F308);
  }
  result = ((int (__cdecl *)(void *))loc_3F01ADE3)(a1: &unk_3F02F310);
  *(_DWORD *)(a1 - 4) = -2;
  if ( *(_DWORD *)(a1 + 16) != 0 )
    return ((int (__cdecl *)(int))loc_3F020118)(a1: 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01B030
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strchr(int a1@<eax>, int a2@<ebx>)
{
  int v2; // esi

  v2 = _encoded_null_0(a1: *(_DWORD *)(a2 + 8 * a1));
  (*(void (__cdecl **)(int))byte_3F01FFD4)(a1: v2);
  sub_3F02252C(a1: v2);
  sub_3F01D251(a1: v2);
  sub_3F021200(a1: v2);
  sub_3F022522(a1: v2);
  _initp_misc_winsig(a1: v2);
  nullsub_8(a1: v2);
  sub_3F02218E(a1: v2);
  off_3F03B028 = (_UNKNOWN *)((int (__cdecl *)(void *))_encode_pointer)(a1: &loc_3F01B013);
}

//------------------------------------------------------------------------------
// Address: 0x3F01B0B0
// Name: sub_3F01B0B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned __int8 *__usercall sub_3F01B0B0@<eax>(
        char a1@<dl>,
        unsigned int a2@<ecx>,
        int a3@<ebp>,
        _BYTE *a4@<edi>,
        _BYTE *a5@<esi>,
        const unsigned __int8 *a6,
        unsigned int a7)
{
  unsigned __int8 *result; // eax
  unsigned int v8; // ecx
  int v9; // edx
  bool v10; // cf
  unsigned int v11; // ecx

  if ( ((unsigned __int8)a4 & 0xF) == ((unsigned __int8)a5 & 0xF) )
    return _mbschr_0(Str: a6, C: a7);
  if ( ((unsigned __int8)a4 & 3) != 0 )
  {
    v10 = a2 < 4;
    v11 = a2 - 4;
    if ( !v10 )
      __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
    __asm { jmp     dword ptr ds:TrailUp0_1[ecx*4]; jumptable 3F01B0DC case 0 }
  }
  v8 = a2 >> 2;
  v9 = a1 & 3;
  switch ( v8 )
  {
    case 0u:
      goto UnwindUp0_1;
    case 1u:
      goto UnwindUp1_1;
    case 2u:
      goto UnwindUp2_1;
    case 3u:
      goto UnwindUp3_0;
    case 4u:
      goto UnwindUp4_0;
    case 5u:
      goto UnwindUp5_0;
    case 6u:
      goto UnwindUp6_1;
    case 7u:
      *(_DWORD *)&a4[4 * v8 - 28] = *(_DWORD *)&a5[4 * v8 - 28];
UnwindUp6_1:
      *(_DWORD *)&a4[4 * v8 - 24] = *(_DWORD *)&a5[4 * v8 - 24];
UnwindUp5_0:
      *(_DWORD *)&a4[4 * v8 - 20] = *(_DWORD *)&a5[4 * v8 - 20];
UnwindUp4_0:
      *(_DWORD *)&a4[4 * v8 - 16] = *(_DWORD *)&a5[4 * v8 - 16];
UnwindUp3_0:
      *(_DWORD *)&a4[4 * v8 - 12] = *(_DWORD *)&a5[4 * v8 - 12];
UnwindUp2_1:
      *(_DWORD *)&a4[4 * v8 - 8] = *(_DWORD *)&a5[4 * v8 - 8];
UnwindUp1_1:
      *(_DWORD *)&a4[4 * v8 - 4] = *(_DWORD *)&a5[4 * v8 - 4];
      a5 += 4 * v8;
      a4 += 4 * v8;
UnwindUp0_1:
      switch ( v9 )
      {
        case 0:
          goto TrailUp0_1;
        case 1:
          goto TrailUp1_1;
        case 2:
          goto _strcpy_s;
        case 3:
          goto TrailUp3_1;
      }
    default:
      qmemcpy(a4, a5, 4 * v8);
      a5 += 4 * v8;
      a4 += 4 * v8;
      switch ( v9 )
      {
        case 0:
TrailUp0_1:
          result = *(unsigned __int8 **)(a3 + 8);
          break;
        case 1:
TrailUp1_1:
          *a4 = *a5;
          result = *(unsigned __int8 **)(a3 + 8);
          break;
        case 2:
_strcpy_s:
          JUMPOUT(0x3F01B218);
        case 3:
TrailUp3_1:
          JUMPOUT(0x3F01B22C);
      }
      return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01B149
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _heap_init@<eax>(int a1@<edx>, unsigned int a2@<ecx>, int a3@<ebp>, int a4@<edi>, int a5@<esi>)
{
  unsigned int v5; // ecx
  char *v6; // esi
  char *v7; // edi
  char *v8; // edi
  char *v9; // esi
  int result; // eax

  v5 = a2 >> 2;
  *(_BYTE *)(a4 + 1) = *(_BYTE *)(a5 + 1);
  v6 = (char *)(a5 + 2);
  v7 = (char *)(a4 + 2);
  if ( v5 < 8 )
    JUMPOUT(0x3F01B104);
  qmemcpy(v7, v6, 4 * v5);
  v9 = &v6[4 * v5];
  v8 = &v7[4 * v5];
  switch ( a1 )
  {
    case 0:
      result = *(_DWORD *)(a3 + 8);
      break;
    case 1:
      *v8 = *v9;
      result = *(_DWORD *)(a3 + 8);
      break;
    case 2:
      *v8 = *v9;
      v8[1] = v9[1];
      result = *(_DWORD *)(a3 + 8);
      break;
    case 3:
      *v8 = *v9;
      v8[1] = v9[1];
      v8[2] = v9[2];
      result = *(_DWORD *)(a3 + 8);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01B2A0
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _alloca_probe_16(int _EAX@<eax>, int _EDX@<edx>, unsigned int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
  int v6; // edx
  _DWORD *v7; // esi
  unsigned int v8; // ecx
  _DWORD *v9; // edi

  __asm
  {
    lock mov dl, 1
    aas
  }
  v6 = a3 & _EDX;
  *(_BYTE *)(a4 + 3) = *(_BYTE *)(a5 + 3);
  v7 = (_DWORD *)(a5 - 1);
  v8 = a3 >> 2;
  v9 = (_DWORD *)(a4 - 1);
  if ( v8 >= 8 )
  {
    while ( v8 != 0 )
    {
      *v9-- = *v7--;
      --v8;
    }
    switch ( v6 )
    {
      case 0:
        JUMPOUT(0x3F01B3A0);
      case 1:
        JUMPOUT(0x3F01B3A8);
      case 2:
        JUMPOUT(0x3F01B3B8);
      case 3:
        JUMPOUT(0x3F01B3CC);
    }
  }
  JUMPOUT(0x3F01B26C);
}

//------------------------------------------------------------------------------
// Address: 0x3F01B2CC
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _tolower_l(int a1@<eax>)
{
  *(_DWORD *)(a1 + 1183449927) = __ROR4__(*(_DWORD *)(a1 + 1183449927), 1);
  JUMPOUT(0x41493ADB);
}

//------------------------------------------------------------------------------
// Address: 0x3F01B40A
// Name: ___sbh_heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn __sbh_heap_init(char a1@<cl>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 1963992188) += a1;
  JUMPOUT(0xC486C319);
}

//------------------------------------------------------------------------------
// Address: 0x3F01B452
// Name: ___sbh_find_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
tagHeader *__usercall __sbh_find_block@<eax>(unsigned __int16 a1@<dx>, void *pvAlloc)
{
  __indword(a1);
  return (tagHeader *)pvAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x3F01B47D
// Name: ___sbh_free_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __sbh_free_block()
{
  __asm { fld     st(1) }
  JUMPOUT(0xC7762986);
}

//------------------------------------------------------------------------------
// Address: 0x3F01B514
// Name: __freea_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea_0(void *Memory)
{
  if ( Memory != nullptr && *((_DWORD *)Memory - 2) == 56797 )
    free(Block: (char *)Memory - 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F01B530
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strstr(const char *Str, const char *SubStr)
{
  char v2; // dl
  const char *v3; // edi
  char v4; // dh
  const char *v5; // ecx
  char *v6; // esi
  char v7; // al
  char v9; // ah
  char v10; // al
  char v11; // al

  v2 = *SubStr;
  v3 = Str;
  if ( *SubStr == 0 )
    return (char *)Str;
  v4 = SubStr[1];
  if ( v4 == 0 )
    JUMPOUT(0x3F01C430);
findnext_0:
  v5 = SubStr;
  v6 = (char *)(v3 + 1);
  if ( *v3 == v2 )
    goto first_char_found_0;
  if ( *v3 != 0 )
  {
    while ( 2 )
    {
      v7 = *v6++;
      while ( v7 == v2 )
      {
first_char_found_0:
        v7 = *v6++;
        if ( v7 == v4 )
        {
          v3 = v6 - 1;
          while ( 1 )
          {
            v9 = v5[2];
            if ( v9 == 0 )
              break;
            v10 = *v6;
            v6 += 2;
            if ( v10 != v9 )
              goto findnext_0;
            v11 = v5[3];
            if ( v11 == 0 )
              break;
            v5 += 2;
            if ( v11 != *(v6 - 1) )
              goto findnext_0;
          }
          return (char *)(v3 - 1);
        }
      }
      if ( v7 != 0 )
        continue;
      break;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F01B5B6
// Name: __heapwalk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _heapwalk(_HEAPINFO *EntryInfo)
{
  int *pentry; // eax
  DWORD LastError; // eax
  _PROCESS_HEAP_ENTRY Entry; // [esp+10h] [ebp-3Ch] BYREF
  int v6; // [esp+2Ch] [ebp-20h]
  BOOL v7; // [esp+30h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  v6 = -2;
  if ( EntryInfo != nullptr )
  {
    Entry.wFlags = 0;
    Entry.iRegionIndex = 0;
    pentry = EntryInfo->_pentry;
    Entry.lpData = pentry;
    if ( pentry != nullptr )
    {
      if ( EntryInfo->_useflag != 1 )
        goto $nextBlock$24730;
      if ( HeapValidate(hHeap: hHeap, dwFlags: 0, lpMem: pentry) )
      {
        Entry.wFlags = 4;
        goto $nextBlock$24730;
      }
    }
    else
    {
      if ( !HeapWalk(hHeap: hHeap, lpEntry: &Entry) )
      {
        if ( GetLastError() != 120 )
          return -3;
LABEL_7:
        *__doserrno_0() = 120;
        *_errno_0() = 40;
        return -5;
      }
      do
      {
        if ( (Entry.wFlags & 3) == 0 )
        {
          EntryInfo->_pentry = (int *)Entry.lpData;
          EntryInfo->_size = Entry.cbData;
          EntryInfo->_useflag = (Entry.wFlags & 4) != 0;
          return v6;
        }
$nextBlock$24730:
        ms_exc.registration.TryLevel = 0;
        v7 = !HeapWalk(hHeap: hHeap, lpEntry: &Entry);
        ms_exc.registration.TryLevel = -2;
      }
      while ( !v7 );
      LastError = GetLastError();
      if ( LastError == 259 )
        return -5;
      if ( LastError == 120 )
        goto LABEL_7;
    }
    return -4;
  }
  *_errno_0() = 22;
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  return -6;
}

//------------------------------------------------------------------------------
// Address: 0x3F01B834
// Name: _atexit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit_0(void (__cdecl *Func)())
{
  _onexit_0((_onexit_t)Func);
  return __sbh_alloc_new_group(pHeader: (tagHeader *)Func);
}

//------------------------------------------------------------------------------
// Address: 0x3F01B841
// Name: ___sbh_alloc_new_group
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall __sbh_alloc_new_group@<eax>(int a1@<eax>)
{
  return -a1 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01B98A
// Name: sub_3F01B98A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F01B98A()
{
  return ((int (__cdecl *)(int))loc_3F020118)(a1: 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F01BA61
// Name: __recalloc_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _recalloc_0(void *Block, size_t Count, size_t Size)
{
  size_t v3; // ebx
  size_t v5; // esi
  int v6; // eax
  void *v7; // edi

  v3 = 0;
  if ( Count != 0 && 0xFFFFFFE0 / Count < Size )
  {
    *_errno_0() = 12;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return nullptr;
  }
  else
  {
    v5 = Size * Count;
    if ( Block != nullptr )
      v3 = _msize_0(Block);
    v6 = ((int (__cdecl *)(void *, size_t))loc_3F01B846)(a1: Block, a2: v5);
    v7 = (void *)v6;
    if ( v6 != 0 && v3 < v5 )
      memset_0(a1: (void *)(v6 + v3), Val: 0, Size: v5 - v3);
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01BADA
// Name: ___heap_select_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __heap_select_0()
{
  unsigned int v1; // [esp+4h] [ebp-8h] BYREF
  int v2; // [esp+8h] [ebp-4h] BYREF

  v2 = 0;
  v1 = 0;
  if ( ((int (__cdecl *)(int *))loc_3F01AE1B)(a1: &v2) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  if ( ((int (__cdecl *)(unsigned int *))loc_3F01AE52)(a1: &v1) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  if ( v2 == 2 && v1 >= 5 )
    return 1;
  else
    return 3;
}

//------------------------------------------------------------------------------
// Address: 0x3F01BB35
// Name: __heap_init_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _heap_init_0(int a1)
{
  hHeap = HeapCreate(flOptions: a1 == 0, dwInitialSize: 0x1000u, dwMaximumSize: 0);
  if ( hHeap == nullptr )
    return 0;
  dword_3F0A48C4 = __heap_select_0();
  if ( dword_3F0A48C4 == 3 && __sbh_heap_init_0(a1: 1016) == 0 )
  {
    HeapDestroy(hHeap: hHeap);
    hHeap = nullptr;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01BB8F
// Name: __heap_term
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _heap_term()
{
  int v0; // edi
  LPVOID *v1; // esi
  BOOL result; // eax

  if ( dword_3F0A48C4 == 3 )
  {
    v0 = 0;
    if ( dword_3F0A3888 > 0 )
    {
      v1 = (LPVOID *)((char *)lpMem + 16);
      do
      {
        VirtualFree(lpAddress: *(v1 - 1), dwSize: 0, dwFreeType: 0x8000u);
        HeapFree(hHeap: hHeap, dwFlags: 0, lpMem: *v1);
        v1 += 5;
        ++v0;
      }
      while ( v0 < dword_3F0A3888 );
    }
    HeapFree(hHeap: hHeap, dwFlags: 0, lpMem: lpMem);
  }
  result = HeapDestroy(hHeap: hHeap);
  hHeap = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01BC03
// Name: sub_3F01BC03
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE sub_3F01BC03()
{
  return hHeap;
}

//------------------------------------------------------------------------------
// Address: 0x3F01BC9B
// Name: sub_3F01BC9B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F01BC9B()
{
  return sub_3F01BCA3();
}

//------------------------------------------------------------------------------
// Address: 0x3F01BCA3
// Name: sub_3F01BCA3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F01BCA3()
{
  return ((int (__cdecl *)(int))loc_3F020118)(a1: 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F01BD11
// Name: ?__ArrayUnwind@@YGXPAXIHP6EX0@Z@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __ArrayUnwind(char *a1, unsigned int a2, int a3, void (*a4)(void))
{
  while ( --a3 >= 0 )
  {
    a1 -= a2;
    a4();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01BD6F
// Name: ??_M@YGXPAXIHP6EX0@Z@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall `eh vector destructor iterator'(char *a1, unsigned int a2, int a3, void (__thiscall *a4)(void *))
{
  char *i; // [esp+34h] [ebp+8h]

  for ( i = &a1[a3 * a2]; --a3 >= 0; a4(a1: i) )
    i -= a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F01BDD2
// Name: _fprintf_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf_0(FILE *const Stream, const char *const Format, ...)
{
  int *v2; // edi
  _BYTE *v3; // eax
  int *v4; // edi
  char *v5; // eax
  int v7; // [esp+10h] [ebp-1Ch]
  va_list va; // [esp+3Ch] [ebp+10h] BYREF

  va_start(va, Format);
  v7 = 0;
  if ( Stream != nullptr && Format != nullptr )
  {
    _lock_file_0(Stream);
    if ( (Stream->_flag & 0x40) == 0 )
    {
      if ( ((int (__cdecl *)(FILE *const))loc_3F022F31)(a1: Stream) == -1
        || ((int (__cdecl *)(FILE *const))loc_3F022F31)(a1: Stream) == -2 )
      {
        v3 = &unk_3F03BD00;
      }
      else
      {
        v2 = &dword_3F0A3780[((int (__cdecl *)(FILE *const))loc_3F022F31)(a1: Stream) >> 5];
        v3 = (_BYTE *)(*v2 + 56 * (((int (__cdecl *)(FILE *const))loc_3F022F31)(a1: Stream) & 0x1F));
      }
      if ( (v3[36] & 0x7F) != 0
        || (((int (__cdecl *)(FILE *const))loc_3F022F31)(a1: Stream) == -1
         || ((int (__cdecl *)(FILE *const))loc_3F022F31)(a1: Stream) == -2
          ? (v5 = (char *)&unk_3F03BD00)
          : (v4 = &dword_3F0A3780[((int (__cdecl *)(FILE *const))loc_3F022F31)(a1: Stream) >> 5],
             v5 = (char *)(*v4 + 56 * (((int (__cdecl *)(FILE *const))loc_3F022F31)(a1: Stream) & 0x1F))),
            v5[36] < 0) )
      {
        *_errno_0() = 22;
        _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
        v7 = -1;
      }
    }
    if ( v7 == 0 )
    {
      ((void (__cdecl *)(FILE *const))_stbuf)(a1: Stream);
      _output_l_0(a1: Stream, a2: Format, a3: 0, a4: va);
    }
    JUMPOUT(0x3F01BF09);
  }
  *_errno_0() = 22;
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  JUMPOUT(0x3F01BF11);
}

//------------------------------------------------------------------------------
// Address: 0x3F01BF30
// Name: _swap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall swap@<eax>(_BYTE *a1@<eax>, int a2@<edx>, _BYTE *a3@<ecx>, unsigned int a4, unsigned int a5)
{
  if ( a1 == a3 || a2 == 0 )
    JUMPOUT(0x3F01BF56);
  *a1 = *a3;
  return _calloc_crt(count: a4, size: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F01BF49
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__usercall _calloc_crt@<eax>(int a1@<eax>, char a2@<dl>, _BYTE *a3@<ecx>, int a4@<esi>)
{
  void *result; // eax

  *a3 = a2;
  result = (void *)(a1 + 1);
  if ( a4 != 0 )
    JUMPOUT(0x3F01BF40);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01BF91
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__usercall _realloc_crt@<eax>(
        int a1@<ebx>,
        unsigned int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        void *ptr,
        unsigned int size,
        unsigned int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int (*a12)(void))
{
  int v12; // esi
  _BYTE *v13; // eax
  int v14; // ecx
  char v15; // dl

  if ( a12() > 0 )
    a3 = a4;
  if ( a1 + a4 <= a2 )
    JUMPOUT(0x3F01BF90);
  v12 = a1;
  v13 = (_BYTE *)a2;
  if ( a3 != a2 && a1 != 0 )
  {
    v14 = a3 - a2;
    do
    {
      v15 = v13[v14];
      v13[v14] = *v13;
      --v12;
      *v13++ = v15;
    }
    while ( v12 != 0 );
  }
  return _recalloc_crt(ptr, count: size, size: a7);
}

//------------------------------------------------------------------------------
// Address: 0x3F01BFDC
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _recalloc_crt(unsigned int a1@<ecx>, int a2@<ebx>, int a3@<ebp>)
{
  if ( a3 - a2 > a1 )
    JUMPOUT(0x3F01BF80);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C02C
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl __noreturn abort()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F01C11F
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01C140
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall memcpy(
        _BYTE *a1@<ebx>,
        unsigned int a2@<ebp>,
        _BYTE *a3@<edi>,
        _BYTE *a4@<esi>,
        unsigned __int8 *dst,
        unsigned __int8 *src,
        unsigned __int8 *count,
        unsigned int counta,
        unsigned int a9,
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
        int a42)
{
  unsigned int v42; // ecx
  _BYTE *v43; // eax
  int v44; // ebp
  unsigned int v45; // esi
  unsigned int v46; // eax
  char v47; // [esp+1Bh] [ebp+1Bh]

  while ( 1 )
  {
    if ( a3 <= a1 )
      goto LABEL_6;
    do
    {
      a1 += a2;
      if ( a1 >= a3 )
        goto CopyUp_0;
    }
    while ( ((int (__cdecl *)(_BYTE *, _BYTE *))STACK[0x120])(a1, a2: a3) <= 0 );
    if ( a3 <= a1 )
    {
LABEL_6:
      do
CopyUp_0:
        a1 += a2;
      while ( (unsigned int)a1 <= a9 && ((int (__cdecl *)(_BYTE *, _BYTE *))STACK[0x120])(a1, a2: a3) <= 0 );
    }
    do
      a4 -= a2;
    while ( a4 > a3 && ((int (__cdecl *)(_BYTE *, _BYTE *))STACK[0x120])(a1: a4, a2: a3) > 0 );
    if ( a1 > a4 )
    {
      v45 = (unsigned int)&a4[a2];
      if ( (unsigned int)a3 >= v45 )
        goto LABEL_20;
      do
      {
        v45 -= a2;
        if ( v45 <= (unsigned int)a3 )
          goto LABEL_20;
      }
      while ( ((int (__cdecl *)(unsigned int, _BYTE *))STACK[0x120])(a1: v45, a2: a3) == 0 );
      if ( (unsigned int)a3 < v45 )
      {
LABEL_22:
        v46 = counta;
      }
      else
      {
LABEL_20:
        while ( 1 )
        {
          v46 = counta;
          v45 -= a2;
          if ( v45 <= counta )
            break;
          if ( ((int (__cdecl *)(unsigned int, _BYTE *))STACK[0x120])(a1: v45, a2: a3) != 0 )
            goto LABEL_22;
        }
      }
      if ( (int)(v45 - v46) >= (int)(a9 - (_DWORD)a1) )
      {
        if ( v46 < v45 )
        {
          *(&a12 + a11) = v46;
          *(&a42 + a11) = v45;
        }
        JUMPOUT(0x3F01C248);
      }
      if ( (unsigned int)a1 < a9 )
      {
        *(&a12 + a11) = (int)a1;
        *(&a42 + a11) = a9;
      }
      if ( v46 < v45 )
        JUMPOUT(0x3F01C093);
      JUMPOUT(0x3F01C0B6);
    }
    v42 = a2;
    v43 = a4;
    if ( a1 != a4 )
    {
      v44 = a1 - a4;
      do
      {
        v47 = v43[v44];
        v43[v44] = *v43;
        --v42;
        *v43++ = v47;
      }
      while ( v42 != 0 );
      a2 = STACK[0x11C];
    }
    if ( a3 == a4 )
      a3 = a1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01C297
// Name: __tolower_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __noreturn _tolower_l_0(int C, _locale_t Locale)
{
  _BYTE v2[24]; // [esp+8h] [ebp-18h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v2, a2: Locale);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C304
// Name: CopyDown_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void CopyDown_0()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F01C3D4
// Name: nullsub_10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_10()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F01C3D5
// Name: j_j__free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl j_j__free(void *Block)
{
  j__free(Block);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C4DE
// Name: __strnicmp_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strnicmp_l_0(const char *String1, const char *String2, size_t MaxCount, _locale_t Locale)
{
  _BYTE v5[16]; // [esp+Ch] [ebp-10h] BYREF

  if ( MaxCount != 0 )
    ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v5, a2: Locale);
  JUMPOUT(0x3F01C5C7);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C520
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strcmp(int a1@<eax>)
{
  *(_DWORD *)(a1 + 112) &= ~2u;
  JUMPOUT(0x3F01C5C9);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C5B0
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _aulldiv(int a1@<eax>, int a2@<ebx>, int a3@<ebp>, int a4@<esi>)
{
  bool v4; // zf

  v4 = (*(_DWORD *)(a3 + 16))-- == 1;
  if ( !v4 && a4 != a2 && a4 == a1 )
    JUMPOUT(0x3F01C58E);
  JUMPOUT(0x3F01C580);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C618
// Name: _tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall tzset_nolock@<eax>(char a1@<cf>, char a2@<bh>, int a3@<ebp>)
{
  int result; // eax
  const char *v4; // [esp+28h] [ebp-14h]
  size_t v5; // [esp+2Ch] [ebp-10h]
  localeinfo_struct *v6; // [esp+30h] [ebp-Ch]

  if ( a2 + a1 + a2 == 0 )
    return _strnicmp_l_0(String1: *(const char **)(a3 + 8), String2: v4, MaxCount: v5, Locale: v6);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01C62A
// Name: sub_3F01C62A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F01C62A(int a1)
{
  return ((int (__cdecl *)(int, _DWORD, int))loc_3F0232EC)(a1, a2: 0, a3: 10);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C63B
// Name: sub_3F01C63B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl sub_3F01C63B(int a1)
{
  return sub_3F01C62A(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C640
// Name: _vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(int a1@<esi>, int (__cdecl *a2)(int *, int, int, int), int a3, int a4, int a5)
{
  unsigned int v5; // eax
  int v7; // [esp+8h] [ebp-20h] BYREF
  int v8; // [esp+Ch] [ebp-1Ch]
  int v9; // [esp+10h] [ebp-18h]
  int v10; // [esp+14h] [ebp-14h]

  v5 = ((int (*)(void))loc_3F01E640)();
  if ( a1 != 0 && a3 != 0 )
  {
    v10 = 73;
    v9 = a1;
    v7 = a1;
    v8 = 0x7FFFFFFF;
    if ( v5 <= 0x7FFFFFFF )
      v8 = v5;
    return a2(a1: &v7, a2: a3, a3: a4, a4: a5);
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01C6C7
// Name: sub_3F01C6C7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_UNKNOWN **sub_3F01C6C7(const char *a1, ...)
{
  return &off_3F03B040;
}

//------------------------------------------------------------------------------
// Address: 0x3F01C6CD
// Name: ___initstdio_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __initstdio_0()
{
  size_t v0; // eax
  char *v1; // eax
  int v3; // edx
  _UNKNOWN **v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int v7; // eax

  v0 = Size;
  if ( Size == 0 )
  {
    v0 = 512;
LABEL_5:
    Size = v0;
    goto LABEL_6;
  }
  if ( (int)Size < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (char *)_calloc_crt_0(Size: v0, a2: 4);
  dword_3F0A38A4 = v1;
  if ( v1 == nullptr )
  {
    Size = 20;
    v1 = (char *)_calloc_crt_0(Size: 0x14u, a2: 4);
    dword_3F0A38A4 = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = &off_3F03B040;
  while ( 1 )
  {
    *(_DWORD *)&v1[v3] = v4;
    v4 += 8;
    v3 += 4;
    if ( (int)v4 >= (int)&off_3F03B2C0 )
      break;
    v1 = (char *)dword_3F0A38A4;
  }
  v5 = 0;
  v6 = &unk_3F03B050;
  do
  {
    v7 = *(_DWORD *)(56 * (v5 & 0x1F) + dword_3F0A3780[v5 >> 5]);
    if ( v7 == -1 || v7 == -2 || v7 == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_3F03B0B0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01C77E
// Name: ___endstdio_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio_0()
{
  sub_3F01D8FD();
  if ( byte_3F03C7F0 != 0 )
    ((void (*)(void))loc_3F023FF1)();
  free(Block: dword_3F0A38A4);
}

//------------------------------------------------------------------------------
// Address: 0x3F01C79E
// Name: __lock_file_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file_0(FILE *Stream)
{
  if ( Stream < (FILE *)&off_3F03B040 || Stream > &stru_3F03B2A0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&Stream[1]);
  }
  else
  {
    ((void (__cdecl *)(int))_lock_0)(a1: (((char *)Stream - (char *)&off_3F03B040) >> 5) + 16);
    Stream->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01C7DA
// Name: __lock_file2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2_0(int a1, int a2)
{
  if ( a1 >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(a2 + 32));
  }
  else
  {
    ((void (__cdecl *)(int))_lock_0)(a1: a1 + 16);
    *(_DWORD *)(a2 + 12) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01C808
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(FILE *Stream)
{
  if ( Stream < (FILE *)&off_3F03B040 || Stream > &stru_3F03B2A0 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&Stream[1]);
  }
  else
  {
    Stream->_flag &= ~0x8000u;
    ((void (__cdecl *)(int))loc_3F020118)(a1: (((char *)Stream - (char *)&off_3F03B040) >> 5) + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01C868
// Name: _time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__time32_t __cdecl time(__time32_t *const Time)
{
  __time32_t result; // eax
  _FILETIME SystemTimeAsFileTime; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: &SystemTimeAsFileTime);
  result = ((int (__cdecl *)(unsigned int, _DWORD, int, _DWORD))loc_3F024090)(
             a1: SystemTimeAsFileTime.dwLowDateTime + 717324288,
             a2: (unsigned __int64)(*(_QWORD *)&SystemTimeAsFileTime - 116444736000000000LL) >> 32,
             a3: 10000000,
             a4: 0);
  if ( Time != nullptr )
    *Time = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01C8A1
// Name: ?_set_se_translator@@YAP6AXIPAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl _set_se_translator(
        void (__cdecl *a1)(unsigned int, struct _EXCEPTION_POINTERS *)))(unsigned int, struct _EXCEPTION_POINTERS *)
{
  int v1; // esi

  v1 = *(_DWORD *)(_getptd_0() + 128);
  *(_DWORD *)(_getptd_0() + 128) = a1;
  return (void (__cdecl *)(unsigned int, struct _EXCEPTION_POINTERS *))v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01CB56
// Name: _isindst_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall isindst_nolock@<al>(char a1@<al>, char a2@<cl>, int a3@<ebx>)
{
  *(_BYTE *)(a3 - 998044603) += a2;
  return a1 | 0x3B;
}

//------------------------------------------------------------------------------
// Address: 0x3F01CD53
// Name: __isindst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01CD94
// Name: __gmtime32_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01CEC1
// Name: ___getgmtimebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __getgmtimebuf(_DWORD *a1@<eax>, int a2@<esi>)
{
  *a1 = a2;
  ((void (__cdecl *)())_invalid_parameter_0)();
  JUMPOUT(0x3F01D08D);
}

//------------------------------------------------------------------------------
// Address: 0x3F01CF09
// Name: __get_daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _get_daylight(_DWORD *a1@<eax>, int a2@<edx>, char a3@<ch>)
{
  int v3; // [esp-4h] [ebp-4h]

  *(_BYTE *)(a2 + 22) += a3;
  *a1 = v3;
  JUMPOUT(0x3F01D08C);
}

//------------------------------------------------------------------------------
// Address: 0x3F01CF3D
// Name: __get_dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _get_dstbias@<eax>(int a1@<ebp>, const wchar_t *a2@<edi>, int *_Daylight_savings_bias)
{
  if ( ((_DWORD (__cdecl *)())sub_3F02412C)() != 0 )
    _invoke_watson_0(Expression: a2, FunctionName: a2, FileName: a2, LineNo: (unsigned int)a2, Reserved: (uintptr_t)a2);
  if ( sub_3F024160(a1: a1 - 4) != 0 )
    _invoke_watson_0(Expression: a2, FunctionName: a2, FileName: a2, LineNo: (unsigned int)a2, Reserved: (uintptr_t)a2);
  return _get_timezone(_Timezone: _Daylight_savings_bias);
}

//------------------------------------------------------------------------------
// Address: 0x3F01CF71
// Name: __get_timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _get_timezone@<eax>(int a1@<eax>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int *a5@<esi>)
{
  int result; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // edx
  int v13; // eax

  if ( a1 > 259200 && a1 < 2147224447 )
  {
    *(_DWORD *)(a3 + 8) = a1 - *(_DWORD *)(a3 - 4);
    result = ((int (__cdecl *)(int *, int))loc_3F01CB1C)(a1: a5, a2: a3 + 8);
    if ( result != a4 )
      return result;
    if ( *(_DWORD *)(a3 - 8) != a4 )
      JUMPOUT(0x3F01CFA3);
    return 0;
  }
  result = ((int (__cdecl *)(int *, int))loc_3F01CB1C)(a1: a5, a2);
  if ( result != a4 )
    return result;
  if ( *(_DWORD *)(a3 - 8) == a4 || ((int (__cdecl *)(int *))byte_3F0248E7)(a1: a5) == 0 )
  {
    v7 = *a5 - *(_DWORD *)(a3 - 4);
  }
  else
  {
    v6 = *a5 - *(_DWORD *)(a3 - 4);
    a5[8] = 1;
    v7 = v6 - *(_DWORD *)(a3 - 12);
  }
  *a5 = v7 % 60;
  if ( v7 % 60 < a4 )
  {
    *a5 = v7 % 60 + 60;
    v7 -= 60;
  }
  v8 = a5[1] + v7 / 60;
  a5[1] = v8 % 60;
  if ( v8 % 60 < a4 )
  {
    a5[1] = v8 % 60 + 60;
    v8 -= 60;
  }
  v9 = a5[2] + v8 / 60;
  a5[2] = v9 % 24;
  if ( v9 % 24 < a4 )
  {
    a5[2] = v9 % 24 + 24;
    v9 -= 24;
  }
  v10 = v9 / 24;
  if ( v10 <= a4 )
  {
    if ( v10 >= a4 )
      return 0;
    v12 = (a5[6] + v10 + 7) % 7;
    a5[3] += v10;
    v13 = a5[3];
    a5[6] = v12;
    if ( v13 <= a4 )
    {
      a5[7] += v10 + 365;
      --a5[5];
      a5[3] = v13 + 31;
      a5[4] = 11;
      return 0;
    }
  }
  else
  {
    v11 = (v10 + a5[6]) % 7;
    a5[3] += v10;
    a5[6] = v11;
  }
  a5[7] += v10;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01CFA5
// Name: ___daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __daylight()
{
  JUMPOUT(0x3F01CFA7);
}

//------------------------------------------------------------------------------
// Address: 0x3F01CFAB
// Name: ___dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int *__usercall __dstbias@<eax>(char a1@<zf>)
{
  if ( a1 )
    JUMPOUT(0x3F01D08A);
  return __timezone();
}

//------------------------------------------------------------------------------
// Address: 0x3F01CFB1
// Name: ___timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall __timezone@<eax>(int a1@<ebp>)
{
  *(_DWORD *)(a1 + 8) -= *(_DWORD *)(a1 - 12);
  return __tzname();
}

//------------------------------------------------------------------------------
// Address: 0x3F01CFB7
// Name: ___tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01D0C8
// Name: sub_3F01D0C8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall sub_3F01D0C8(_DWORD *this)
{
  *(this + 1) = 0;
  *(this + 2) = 0;
  *this = &std::exception::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D0D9
// Name: ??0exception@std@@QAE@ABQBD@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::exception *__thiscall std::exception::exception(std::exception *this, const char **a2)
{
  size_t v3; // esi
  char *v4; // eax

  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
  if ( *a2 != nullptr )
  {
    v3 = ((int (__cdecl *)(const char *))loc_3F01E640)(a1: *a2) + 1;
    v4 = (char *)malloc_0(Size: v3);
    this->_m_what = v4;
    if ( v4 != nullptr )
      strcpy_s_0(Destination: v4, SizeInBytes: v3, Source: *a2);
  }
  else
  {
    this->_m_what = nullptr;
  }
  this->_m_doFree = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D127
// Name: ??0exception@std@@QAE@ABQBDH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::exception *__thiscall std::exception::exception(std::exception *this, const char **a2, int a3)
{
  std::exception *result; // eax
  const char *v4; // ecx

  result = this;
  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
  v4 = *a2;
  result->_m_doFree = 0;
  result->_m_what = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D13F
// Name: ??0exception@std@@QAE@ABV01@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::exception *__thiscall std::exception::exception(std::exception *this, const struct std::exception *a2)
{
  int m_doFree; // eax
  bool v4; // zf
  const char *m_what; // eax
  size_t v6; // edi
  char *v7; // eax

  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
  m_doFree = a2->_m_doFree;
  this->_m_doFree = m_doFree;
  v4 = m_doFree == 0;
  m_what = a2->_m_what;
  if ( v4 )
  {
    this->_m_what = m_what;
  }
  else if ( m_what != nullptr )
  {
    v6 = ((int (__cdecl *)(const char *))loc_3F01E640)(a1: a2->_m_what) + 1;
    v7 = (char *)malloc_0(Size: v6);
    this->_m_what = v7;
    if ( v7 != nullptr )
      strcpy_s_0(Destination: v7, SizeInBytes: v6, Source: a2->_m_what);
  }
  else
  {
    this->_m_what = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D197
// Name: sub_3F01D197
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F01D197(void *this)
{
  bool v1; // zf

  v1 = *((_DWORD *)this + 2) == 0;
  *(_DWORD *)this = &std::exception::`vftable';
  if ( !v1 )
    free(Block: *((void **)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x3F01D1BA
// Name: sub_3F01D1BA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__thiscall sub_3F01D1BA(void *Block, char a2)
{
  sub_3F01D197(this: Block);
  if ( (a2 & 1) != 0 )
    j__free(Block);
  return Block;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D1D6
// Name: _memcpy_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static errno_t __cdecl memcpy_s_0(
        void *const Destination,
        const rsize_t DestinationSize,
        const void *const Source,
        const rsize_t SourceSize)
{
  errno_t v5; // esi

  if ( SourceSize == 0 )
    return 0;
  if ( Destination != nullptr )
  {
    if ( Source != nullptr && DestinationSize >= SourceSize )
    {
      memcpy_1(a1: Destination, Src: Source, Size: SourceSize);
      return 0;
    }
    memset_0(a1: Destination, Val: 0, Size: DestinationSize);
    if ( Source != nullptr )
    {
      if ( DestinationSize < SourceSize )
      {
        *_errno_0() = 34;
        v5 = 34;
        goto LABEL_5;
      }
      return 22;
    }
  }
  v5 = 22;
  *_errno_0() = 22;
LABEL_5:
  _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D251
// Name: sub_3F01D251
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F01D251(int a1)
{
  dword_3F03C820 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D25B
// Name: __invoke_watson_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _invoke_watson_0(
        const wchar_t *Expression,
        const wchar_t *FunctionName,
        const wchar_t *FileName,
        unsigned int LineNo,
        uintptr_t Reserved)
{
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // edi
  int v10; // esi
  unsigned int v11; // kr00_4
  BOOL v12; // esi
  HANDLE CurrentProcess; // eax
  _DWORD v14[20]; // [esp+4h] [ebp-80h] BYREF
  struct _EXCEPTION_POINTERS ExceptionInfo; // [esp+54h] [ebp-30h] BYREF
  int v16; // [esp+5Ch] [ebp-28h] BYREF
  __int16 v17; // [esp+E8h] [ebp+64h]
  __int16 v18; // [esp+ECh] [ebp+68h]
  __int16 v19; // [esp+F0h] [ebp+6Ch]
  __int16 v20; // [esp+F4h] [ebp+70h]
  int v21; // [esp+F8h] [ebp+74h]
  int v22; // [esp+FCh] [ebp+78h]
  int v23; // [esp+100h] [ebp+7Ch]
  int v24; // [esp+104h] [ebp+80h]
  int v25; // [esp+108h] [ebp+84h]
  int v26; // [esp+10Ch] [ebp+88h]
  int v27; // [esp+110h] [ebp+8Ch]
  void *v28; // [esp+114h] [ebp+90h]
  __int16 v29; // [esp+118h] [ebp+94h]
  unsigned int v30; // [esp+11Ch] [ebp+98h]
  void **v31; // [esp+120h] [ebp+9Ch]
  __int16 v32; // [esp+124h] [ebp+A0h]
  int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  v26 = v5;
  v25 = v7;
  v24 = v6;
  v23 = v8;
  v22 = v10;
  v21 = v9;
  v32 = __SS__;
  v29 = __CS__;
  v20 = __DS__;
  v19 = __ES__;
  v18 = __FS__;
  v17 = __GS__;
  v11 = __readeflags();
  v30 = v11;
  v31 = &retaddr;
  v16 = 65537;
  v28 = retaddr;
  v27 = savedregs;
  memset_0(a1: v14, Val: 0, Size: sizeof(v14));
  ExceptionInfo.ExceptionRecord = (_EXCEPTION_RECORD *)v14;
  v14[0] = -1073741811;
  v14[3] = retaddr;
  ExceptionInfo.ContextRecord = (_CONTEXT *)&v16;
  v12 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(&ExceptionInfo) == 0 && !v12 )
    ((void (__cdecl *)(int))loc_3F024928)(a1: 2);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC000000D);
}

//------------------------------------------------------------------------------
// Address: 0x3F01D357
// Name: __invalid_parameter_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _invalid_parameter_0(
        const wchar_t *Expression,
        const wchar_t *FunctionName,
        const wchar_t *FileName,
        unsigned int LineNo,
        uintptr_t Reserved)
{
  int (*v5)(void); // eax

  v5 = (int (*)(void))((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F03C820);
  if ( v5 == nullptr )
  {
    ((void (__cdecl *)(int))loc_3F024928)(a1: 2);
    _invoke_watson_0(Expression, FunctionName, FileName, LineNo, Reserved);
  }
  return v5();
}

//------------------------------------------------------------------------------
// Address: 0x3F01D37B
// Name: __invalid_parameter_noinfo_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo_0()
{
  _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F01D38B
// Name: _memmove_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static errno_t __cdecl memmove_s_0(
        void *const Destination,
        const rsize_t DestinationSize,
        const void *const Source,
        const rsize_t SourceSize)
{
  errno_t v4; // esi

  if ( SourceSize != 0 )
  {
    if ( Destination == nullptr || Source == nullptr )
    {
      v4 = 22;
      *_errno_0() = 22;
LABEL_4:
      _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      return v4;
    }
    if ( DestinationSize < SourceSize )
    {
      *_errno_0() = 34;
      v4 = 34;
      goto LABEL_4;
    }
    memcpy_0(a1: Destination, Src: Source, Size: SourceSize);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D3E6
// Name: __mbscmp_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __noreturn _mbscmp_l_0(const unsigned __int8 *Str1, const unsigned __int8 *Str2, _locale_t Locale)
{
  _BYTE v3[20]; // [esp+4h] [ebp-14h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v3, a2: Locale);
}

//------------------------------------------------------------------------------
// Address: 0x3F01D502
// Name: sub_3F01D502
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F01D502(unsigned __int8 *Str1, unsigned __int8 *Str2)
{
  _mbscmp_l_0(Str1, Str2, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F01D583
// Name: __write
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _write@<eax>(
        unsigned int a1@<eax>,
        unsigned __int16 a2@<dx>,
        unsigned int a3@<ecx>,
        int a4@<ebx>,
        int a5@<edi>,
        int fh,
        int buf)
{
  _BYTE *v7; // edi
  char *v8; // esi
  char v9; // bl
  unsigned int v10; // ecx
  int v11; // edx
  char v12; // dl
  int v14; // eax

  __outdword(a2, a1);
  BYTE1(a3) += a4;
  *(_BYTE *)(a4 + 65733615) |= a1;
  v7 = (_BYTE *)(a5 - 4);
  v8 = (char *)buf;
  if ( (buf & 3) == 0 )
  {
    v9 = a3;
    v10 = a3 >> 2;
    if ( v10 != 0 )
      goto LABEL_15;
    goto LABEL_8;
  }
  do
  {
    LOBYTE(v11) = *v8++;
    if ( (_BYTE)v11 == 0 )
    {
LABEL_13:
      *v7 = v11;
      return fh;
    }
    *v7++ = v11;
    if ( --a3 == 0 )
      goto LABEL_11;
  }
  while ( ((unsigned __int8)v8 & 3) != 0 );
  v9 = a3;
  v10 = a3 >> 2;
  if ( v10 == 0 )
  {
LABEL_8:
    a3 = v9 & 3;
    if ( (v9 & 3) != 0 )
    {
      while ( 1 )
      {
        v12 = *v8++;
        *v7++ = v12;
        if ( v12 == 0 )
          break;
        if ( --a3 == 0 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      *v7 = a3;
    }
    return fh;
  }
  while ( 1 )
  {
LABEL_15:
    v14 = (*(_DWORD *)v8 + 2130640639) ^ ~*(_DWORD *)v8;
    v11 = *(_DWORD *)v8;
    v8 += 4;
    if ( (v14 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        goto LABEL_13;
      if ( BYTE1(v11) == 0 )
        break;
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_WORD *)v7 = v11;
        v7[2] = 0;
        return fh;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v7 = v11;
        return fh;
      }
    }
    *(_DWORD *)v7 = v11;
    v7 += 4;
    if ( --v10 == 0 )
      goto LABEL_8;
  }
  *(_WORD *)v7 = (unsigned __int8)v11;
  return fh;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D70F
// Name: sub_3F01D70F
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F01D70F(int a1@<ebp>)
{
  _unlock_file(Stream: *(FILE **)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F01D740
// Name: __filbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _filbuf@<eax>(int _EAX@<eax>, int a2@<ebx>, _DWORD *a3@<esi>)
{
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v10; // [esp-14h] [ebp-14h]
  DWORD v11; // [esp-10h] [ebp-10h]

  __asm { aas }
  if ( (_EAX & 0x108) != 0 )
  {
    v4 = a3[2];
    v5 = *a3 - v4;
    if ( v5 > 0 )
    {
      v11 = *a3 - v4;
      v10 = a3[2];
      v6 = ((int (__cdecl *)(_DWORD *))loc_3F022F31)(a1: a3);
      if ( sub_3F025419(a1: v6, a2: v10, nNumberOfBytesToWrite: v11) == v5 )
      {
        v7 = a3[3];
        if ( (v7 & 0x80u) != 0 )
          a3[3] = v7 & 0xFFFFFFFD;
      }
      else
      {
        a3[3] |= 0x20u;
        a2 = -1;
      }
    }
  }
  v8 = a3[2];
  a3[1] = 0;
  *a3 = v8;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D8AA
// Name: _fflush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush(FILE *Stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  if ( Stream == nullptr )
    return ((int (__cdecl *)(_DWORD))loc_3F01D7D0)(a1: 0);
  _lock_file_0(Stream);
  v2 = ((int (__cdecl *)(FILE *))loc_3F01D78E)(a1: Stream);
  _unlock_file(Stream);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F01D8FD
// Name: sub_3F01D8FD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F01D8FD()
{
  return ((int (__cdecl *)(int))loc_3F01D7D0)(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F01D906
// Name: __fread_nolock_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl _fread_nolock_s_0(
        void *Buffer,
        size_t BufferSize,
        size_t ElementSize,
        size_t ElementCount,
        FILE *Stream)
{
  size_t v6; // edi
  size_t v7; // ebx
  int cnt; // eax
  rsize_t v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int bufsiz; // [esp+10h] [ebp-Ch]
  char *Destination; // [esp+14h] [ebp-8h]
  rsize_t DestinationSize; // [esp+18h] [ebp-4h]

  Destination = (char *)Buffer;
  DestinationSize = BufferSize;
  if ( ElementSize == 0 || ElementCount == 0 )
    return 0;
  if ( Buffer != nullptr )
  {
    if ( Stream != nullptr && ElementCount <= 0xFFFFFFFF / ElementSize )
      goto LABEL_12;
    if ( BufferSize != -1 )
      memset_0(a1: Buffer, Val: 0, Size: BufferSize);
    if ( Stream != nullptr && ElementCount <= 0xFFFFFFFF / ElementSize )
    {
LABEL_12:
      v6 = ElementCount * ElementSize;
      v7 = ElementCount * ElementSize;
      if ( (Stream->_flag & 0x10C) != 0 )
        bufsiz = Stream->_bufsiz;
      else
        bufsiz = 4096;
      if ( v6 == 0 )
        return ElementCount;
      while ( 1 )
      {
        if ( (Stream->_flag & 0x10C) != 0 )
        {
          cnt = Stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_46;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = Stream->_cnt;
            if ( v9 <= DestinationSize )
            {
              memcpy_s_0(Destination, DestinationSize, Source: Stream->_ptr, SourceSize: v9);
              Stream->_cnt -= v9;
              Stream->_ptr += v9;
              Destination += v9;
              v7 -= v9;
              DestinationSize -= v9;
              v6 = ElementCount * ElementSize;
              goto LABEL_38;
            }
            if ( BufferSize != -1 )
              memset_0(a1: Buffer, Val: 0, Size: BufferSize);
LABEL_42:
            *_errno_0() = 34;
            _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
            return 0;
          }
        }
        if ( v7 < bufsiz )
        {
          v15 = _filbuf_0(File: Stream);
          if ( v15 == -1 )
            return (v6 - v7) / ElementSize;
          if ( DestinationSize != 0 )
          {
            v16 = Destination++;
            *v16 = v15;
            --v7;
            --DestinationSize;
            bufsiz = Stream->_bufsiz;
            goto LABEL_38;
          }
LABEL_43:
          if ( BufferSize != -1 )
            memset_0(a1: Buffer, Val: 0, Size: BufferSize);
          goto LABEL_42;
        }
        if ( bufsiz != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % bufsiz;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % bufsiz;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > DestinationSize )
          goto LABEL_43;
        v17 = v12;
        v13 = ((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream);
        v14 = _read_0(FileHandle: v13, DstBuf: Destination, MaxCharCount: v17);
        if ( v14 == 0 )
          break;
        if ( v14 == -1 )
        {
LABEL_46:
          Stream->_flag |= 0x20u;
          return (v6 - v7) / ElementSize;
        }
        Destination += v14;
        v7 -= v14;
        DestinationSize -= v14;
LABEL_38:
        if ( v7 == 0 )
          return ElementCount;
      }
      Stream->_flag |= 0x10u;
      return (v6 - v7) / ElementSize;
    }
  }
  *_errno_0() = 22;
  _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01DB0C
// Name: _fread_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl fread_s_0(void *Buffer, size_t BufferSize, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  size_t v6; // [esp+10h] [ebp-1Ch]

  if ( ElementSize == 0 || ElementCount == 0 )
    return 0;
  if ( Stream == nullptr )
  {
    if ( BufferSize != -1 )
      memset_0(a1: Buffer, Val: 0, Size: BufferSize);
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 0;
  }
  _lock_file_0(Stream);
  v6 = _fread_nolock_s_0(Buffer, BufferSize, ElementSize, ElementCount, Stream);
  _unlock_file(Stream);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F01DBA2
// Name: sub_3F01DBA2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl sub_3F01DBA2(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  return fread_s_0(Buffer, BufferSize: 0xFFFFFFFF, ElementSize, ElementCount, Stream);
}

//------------------------------------------------------------------------------
// Address: 0x3F01DD1C
// Name: _fwrite_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl fwrite_0(const void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  size_t v5; // [esp+10h] [ebp-1Ch]

  if ( ElementSize == 0 || ElementCount == 0 )
    return 0;
  if ( Stream == nullptr )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 0;
  }
  _lock_file_0(Stream);
  v5 = _fwrite_nolock_0(Buffer, ElementSize, ElementCount, Stream);
  _unlock_file(Stream);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F01DE21
// Name: __read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _read@<eax>(int a1@<ebp>, int _ESI@<esi>)
{
  unsigned int v3; // edi

  __asm { rcr     dword ptr [esi+5Dh], 0C3h }
  if ( *(_DWORD *)(a1 + 8) != 0 )
  {
    v3 = *(_DWORD *)(a1 + 16);
    if ( v3 <= 2 )
    {
      _lock_file_0(Stream: *(FILE **)(a1 + 8));
      *(_DWORD *)(a1 - 4) = 0;
      *(_DWORD *)(a1 - 28) = _fseek_nolock_0(Stream: *(FILE **)(a1 + 8), Offset: *(_DWORD *)(a1 + 12), Origin: v3);
      *(_DWORD *)(a1 - 4) = -2;
      JUMPOUT(0x3F01DEA0);
    }
  }
  *_errno_0() = 22;
  _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01DF1E
// Name: __lseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _lseek_nolock@<eax>(unsigned int a1@<eax>, int a2@<ecx>, int a3@<ebx>, int a4@<ebp>, int a5@<edi>)
{
  _BYTE *v5; // ecx
  _BYTE *i; // edx
  int v8; // edx
  int v9; // esi
  int *v10; // ebx
  _BYTE *v11; // eax
  _BYTE *v12; // ecx
  bool v13; // zf
  int v14; // eax
  int v15; // ecx

  v5 = (_BYTE *)(*(_DWORD *)(a2 + 1098183797) + a2);
  if ( *(char *)(dword_3F0A3780[*(int *)(a4 - 4) >> 5] + 56 * (*(_DWORD *)(a4 - 4) & 0x1F) + 4) < 0 )
  {
    for ( i = v5; (unsigned int)i < a1; ++i )
    {
      if ( *i == 10 )
      {
        ++*(_DWORD *)(a4 - 12);
        a3 = 0;
      }
    }
  }
  if ( *(_DWORD *)(a4 - 8) == a3 )
    return *(_DWORD *)(a4 - 12);
  if ( (*(_BYTE *)(a5 + 12) & 1) != 0 )
  {
    v8 = *(_DWORD *)(a5 + 4);
    if ( v8 == a3 )
    {
      *(_DWORD *)(a4 - 12) = a3;
    }
    else
    {
      v9 = 56 * (*(_DWORD *)(a4 - 4) & 0x1F);
      v10 = &dword_3F0A3780[*(int *)(a4 - 4) >> 5];
      *(_DWORD *)(a4 + 8) = v8 + a1 - (_DWORD)v5;
      if ( *(char *)(*v10 + v9 + 4) < 0 )
      {
        if ( ((int (__cdecl *)(_DWORD, _DWORD, int))loc_3F025E26)(a1: *(_DWORD *)(a4 - 4), a2: 0, a3: 2) == *(_DWORD *)(a4 - 8) )
        {
          v11 = *(_BYTE **)(a5 + 8);
          v12 = &v11[*(_DWORD *)(a4 + 8)];
          while ( v11 < v12 )
          {
            if ( *v11 == 10 )
              ++*(_DWORD *)(a4 + 8);
            ++v11;
          }
          v13 = (*(_WORD *)(a5 + 12) & 0x2000) == 0;
        }
        else
        {
          if ( ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))loc_3F025E26)(
                 a1: *(_DWORD *)(a4 - 4),
                 a2: *(_DWORD *)(a4 - 8),
                 a3: 0) < 0 )
            return -1;
          v14 = 512;
          if ( *(_DWORD *)(a4 + 8) > 0x200u || ((v15 = *(_DWORD *)(a5 + 12)) & 8) == 0 || (v15 & 0x400) != 0 )
            v14 = *(_DWORD *)(a5 + 24);
          *(_DWORD *)(a4 + 8) = v14;
          v13 = (*(_BYTE *)(*v10 + v9 + 4) & 4) == 0;
        }
        if ( !v13 )
          ++*(_DWORD *)(a4 + 8);
      }
      *(_DWORD *)(a4 - 8) -= *(_DWORD *)(a4 + 8);
    }
  }
  return *(_DWORD *)(a4 - 8) + *(_DWORD *)(a4 - 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F01E074
// Name: __setenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setenvp()
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01E0A6
// Name: sub_3F01E0A6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F01E0A6(int a1@<ebp>)
{
  _unlock_file(Stream: *(FILE **)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F01E0B0
// Name: __fclose_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock_0(FILE *Stream)
{
  int v1; // ebx
  int v3; // eax

  v1 = -1;
  if ( Stream != nullptr )
  {
    if ( (Stream->_flag & 0x83) != 0 )
    {
      v1 = ((int (__cdecl *)(FILE *))_flush_0)(a1: Stream);
      ((void (__cdecl *)(FILE *))_freebuf_0)(a1: Stream);
      v3 = ((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream);
      if ( _close_0(FileHandle: v3) >= 0 )
      {
        if ( Stream->_tmpfname != nullptr )
        {
          free(Block: Stream->_tmpfname);
          Stream->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    Stream->_flag = 0;
    return v1;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01E122
// Name: _fclose_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01E14F
// Name: parse_cmdline
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall parse_cmdline(const wchar_t *numchars@<edi>)
{
  const wchar_t *v2; // [esp-Ch] [ebp-10h]
  unsigned int v3; // [esp-8h] [ebp-Ch]
  uintptr_t v4; // [esp-4h] [ebp-8h]

  _invalid_parameter_0(Expression: numchars, FunctionName: numchars, FileName: v2, LineNo: v3, Reserved: v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F01E19E
// Name: __endthreadex_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01E1D7
// Name: __callthreadstartex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn _callthreadstartex()
{
  int v0; // eax
  unsigned int v1; // eax
  int v2; // [esp+0h] [ebp-2Ch]

  v0 = _getptd_0();
  v1 = (*(int (__stdcall **)(_DWORD, int))(v0 + 84))(a1: *(_DWORD *)(v0 + 88), a2: v2);
  _endthreadex_0(ReturnCode: v1);
}

//------------------------------------------------------------------------------
// Address: 0x3F01E218
// Name: _threadstartex(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __stdcall __noreturn _threadstartex(void *a1)
{
  int v1; // eax
  _DWORD *v2; // eax
  DWORD LastError; // eax
  int v4; // [esp-Ch] [ebp-10h]
  DWORD *retaddr; // [esp+4h] [ebp+0h]

  ((void (*)(void))loc_3F01F68C)();
  v1 = ((int (*)(void))loc_3F01F686)();
  v2 = (_DWORD *)((int (__cdecl *)(int))loc_3F01F671)(a1: v1);
  if ( v2 != nullptr )
  {
    v2[21] = retaddr[21];
    v2[22] = retaddr[22];
    v2[1] = retaddr[1];
    ((void (__cdecl *)(DWORD *))_freefls)(a1: retaddr);
  }
  else
  {
    v4 = ((int (__cdecl *)(DWORD *))loc_3F01F686)(a1: retaddr);
    if ( ((int (*)(void))loc_3F01F6BE)() == 0 )
    {
      LastError = GetLastError();
      ExitThread(dwExitCode: LastError);
    }
    *retaddr = GetCurrentThreadId();
  }
  if ( nullsub_8 != nullptr && ((int (__cdecl *)(int (**)()))_IsNonwritableInCurrentImage_0)(a1: off_3F03384C) != 0 )
    nullsub_8(a1: v4);
  _callthreadstartex();
}

//------------------------------------------------------------------------------
// Address: 0x3F01E2E7
// Name: __setargv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int *__usercall _setargv@<eax>(
        int _EDX@<edx>,
        int a2@<ecx>,
        unsigned int *a3@<ebx>,
        int a4@<ebp>,
        int a5@<edi>,
        _DWORD *a6@<esi>)
{
  int v6; // eax
  unsigned int *v7; // eax
  unsigned int *result; // eax

  __asm { insb }
  ((void (__fastcall *)(int, int, _DWORD *))loc_3F01F714)(a1: a2, a2: _EDX, a3: a6);
  v6 = *(_DWORD *)(a4 + 20);
  a6[1] = -1;
  a6[22] = v6;
  v7 = *(unsigned int **)(a4 + 28);
  a6[21] = a5;
  if ( v7 == a3 )
    v7 = (unsigned int *)(a4 + 16);
  result = (unsigned int *)CreateThread(
                             lpThreadAttributes: *(LPSECURITY_ATTRIBUTES *)(a4 + 8),
                             dwStackSize: *(_DWORD *)(a4 + 12),
                             lpStartAddress: (LPTHREAD_START_ROUTINE)_threadstartex,
                             lpParameter: a6,
                             dwCreationFlags: *(_DWORD *)(a4 + 24),
                             lpThreadId: v7);
  if ( result == a3 )
  {
    *(_DWORD *)(a4 - 4) = GetLastError();
    free(Block: a6);
    if ( *(unsigned int **)(a4 - 4) != a3 )
      ((void (__cdecl *)(_DWORD))_dosmaperr_0)(a1: *(_DWORD *)(a4 - 4));
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01E3A0
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge __crtGetEnvironmentStringsA(
        char a1@<al>,
        char a2@<cl>,
        int a3@<ebx>,
        int a4@<ebp>,
        __int16 a5@<di>,
        int a6,
        int a7,
        int a8)
{
  int v8; // ebp
  int v9; // edi
  void *v10; // eax
  int v11; // ecx
  int v12; // eax
  DWORD v13; // [esp-4h] [ebp-10h]
  char *aEnv; // [esp+0h] [ebp-Ch]

  v8 = a4 + 1;
  *(_BYTE *)(a3 + 1166608454) += a2 + __CFADD__(a1 | 0x8B, -119);
  v9 = a5 & 0x7FFF;
  v10 = (void *)((int (*)(void))a3)();
  HeapFree(hHeap: v10, dwFlags: v13, lpMem: aEnv);
  if ( *(_DWORD *)(v8 + 12) != 2 )
    v9 |= 0x8000u;
  v11 = *(_DWORD *)(v8 - 4);
  dword_3F03C7B8 = *(_DWORD *)(v8 + 12);
  v12 = *(_DWORD *)(v8 + 16);
  dword_3F03C7C0 = v11 + (v12 << 8);
  dword_3F03C7C4 = v12;
  dword_3F03C7C8 = v11;
  dword_3F03C7BC = v9;
  if ( _heap_init_0(a1: 1) != 0 )
  {
    if ( ((int (*)(void))loc_3F01F9EC)() != 0 )
    {
      sub_3F021F62();
      dword_3F0A38A0 = (int)GetCommandLineA();
      dword_3F03C828 = ((int (*)(void))__crtGetEnvironmentStringsA_0)();
      if ( ((int (*)(void))loc_3F022CA5)() >= 0 )
      {
        if ( ((int (*)(void))_setargv_0)() >= 0
          && ((int (*)(void))_setenvp_0)() >= 0
          && ((int (__cdecl *)(_DWORD))loc_3F01AE8E)(a1: 0) == 0 )
        {
          ++dword_3F03C824;
          JUMPOUT(0x3F01E515);
        }
        ((void (*)(void))loc_3F022EE5)();
      }
      ((void (*)(void))loc_3F01F6D7)();
    }
    _heap_term();
  }
  JUMPOUT(0x3F01E376);
}

//------------------------------------------------------------------------------
// Address: 0x3F01E4D5
// Name: ___security_init_cookie
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl __security_init_cookie()
{
  int v0; // edi
  DWORD *v1; // esi
  int (*v2)(void); // eax
  DWORD CurrentThreadId; // eax

  v2 = (int (*)(void))((int (*)(void))_decode_pointer)();
  if ( v2() == 0 )
  {
    free(Block: v1);
    JUMPOUT(0x3F01E376);
  }
  ((void (__stdcall *)(DWORD *, int))loc_3F01F714)(a1: v1, a2: v0);
  CurrentThreadId = GetCurrentThreadId();
  v1[1] = -1;
  *v1 = CurrentThreadId;
}

//------------------------------------------------------------------------------
// Address: 0x3F01E596
// Name: ___TypeMatch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01E636
// Name: ___FrameUnwindToState
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __FrameUnwindToState(EHRegistrationNode *pRN)
{
  EHRegistrationNode *v1; // ecx
  char pNext; // al
  int v3; // eax
  int state; // eax

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
  v1 = pRN;
  if ( ((unsigned __int8)pRN & 3) != 0 )
  {
    while ( 1 )
    {
      pNext = (char)v1->pNext;
      v1 = (EHRegistrationNode *)((char *)v1 + 1);
      if ( pNext == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto LABEL_4;
    }
  }
  else
  {
    do
    {
      do
      {
LABEL_4:
        v3 = ((int)&v1->pNext[177553386].frameHandler + 3) ^ ~(int)v1->pNext;
        v1 = (EHRegistrationNode *)((char *)v1 + 4);
      }
      while ( (v3 & 0x81010100) == 0 );
      state = v1[-1].state;
    }
    while ( (_BYTE)state != 0 && BYTE1(state) != 0 && (state & 0xFF0000) != 0 && (state & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01E717
// Name: ExFilterRethrow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ExFilterRethrow@<eax>(unsigned __int16 a1@<dx>, int a2@<ebp>)
{
  __inbyte(a1);
  *(_DWORD *)(a2 - 4) = *(_DWORD *)(a2 + 12) + 12;
  return (*(int (**)(void))(a2 + 8))();
}

//------------------------------------------------------------------------------
// Address: 0x3F01E745
// Name: sub_3F01E745
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// ?_CallMemberFunction0@@YGXPAX0@Z
// doubtful name
// positive sp value has been detected, the output may be wrong!
int __cdecl sub_3F01E745(int a1, int a2)
{
  __int32 v3; // [esp-8h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  return ((int (*)(void))_InterlockedExchange((volatile __int32 *)&retaddr, v3))();
}

//------------------------------------------------------------------------------
// Address: 0x3F01E75C
// Name: ___DestructExceptionObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge __DestructExceptionObject(
        char a1@<zf>,
        int a2@<ebp>,
        EHExceptionRecord *pExcept,
        unsigned __int8 fThrowNotAllowed)
{
  if ( !a1 )
    JUMPOUT(0x3F01E75A);
  *(_DWORD *)(a2 - 8) = &_ReturnPoint_17705;
  RtlUnwind(
    TargetFrame: *(PVOID *)(a2 + 8),
    TargetIp: *(PVOID *)(a2 - 8),
    ExceptionRecord: *(PEXCEPTION_RECORD *)(a2 + 12),
    ReturnValue: nullptr);
  *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4) &= ~2u;
  **(_DWORD **)(a2 - 4) = NtCurrentTeb()->NtTib.ExceptionList;
}

//------------------------------------------------------------------------------
// Address: 0x3F01E7B0
// Name: ___AdjustPointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__usercall __AdjustPointer@<eax>(int a1@<ebp>)
{
  *(_DWORD *)(a1 - 8) = ((BOOL (__stdcall *)(LCID, DWORD, LPCSTR, int, LPWORD))((char *)&GetStringTypeA + 2))(
                          Locale: *(_DWORD *)(a1 + 8),
                          dwInfoType: *(_DWORD *)(a1 + 12),
                          lpSrcStr: *(LPCSTR *)(a1 + 16),
                          cchSrc: *(_DWORD *)(a1 + 20),
                          lpCharType: *(LPWORD *)(a1 - 4));
  return *(void **)(a1 - 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F01E7D5
// Name: IsInExceptionSpec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
BOOL __cdecl IsInExceptionSpec(EHExceptionRecord *pExcept, EHExceptionRecord *pExcepta, const char *a3)
{
  __security_check_cookie`...'(StackCookie: (unsigned int)pExcepta ^ (unsigned int)pExcepta->ExceptionRecord);
  return ((BOOL (__stdcall *)(LCID, DWORD, LPCSTR, int, LPWORD))((char *)&GetStringTypeA + 2))(
           Locale: (LCID)pExcept,
           dwInfoType: pExcepta->NumberParameters,
           lpSrcStr: a3,
           cchSrc: 0,
           lpCharType: (LPWORD)pExcepta->ExceptionAddress);
}

//------------------------------------------------------------------------------
// Address: 0x3F01E897
// Name: CallCatchBlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__usercall CallCatchBlock@<eax>(_BYTE *handlerAddress@<ecx>, int a2@<eax>, int a3@<ebp>)
{
  handlerAddress[1166922821] += (_BYTE)handlerAddress;
  __debugbreak();
  (*(void (__cdecl **)(_DWORD, int))(a3 - 44))(a1: **(_DWORD **)(a3 + 8), a2);
  *(_DWORD *)(a3 - 56) = 0;
  if ( *(_DWORD *)(a3 - 4) != 0 )
    **(_DWORD **)(a3 - 40) = NtCurrentTeb()->NtTib.ExceptionList->Next;
  return *(void **)(a3 - 56);
}

//------------------------------------------------------------------------------
// Address: 0x3F01EA11
// Name: __IsExceptionObjectToBeDestroyed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _IsExceptionObjectToBeDestroyed(int a1)
{
  _DWORD *i; // eax

  for ( i = *(_DWORD **)(_getptd_0() + 152); ; i = (_DWORD *)i[1] )
  {
    if ( i == nullptr )
      return 1;
    if ( *i == a1 )
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01EA32
// Name: $LN15_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _LN15_4(int a1)
{
  int result; // eax

  if ( a1 == *(_DWORD *)(_getptd_0() + 152) )
  {
    result = _getptd_0();
    *(_DWORD *)(result + 152) = *(_DWORD *)(a1 + 4);
  }
  else
  {
    for ( result = *(_DWORD *)(_getptd_0() + 152); ; result = *(_DWORD *)(result + 4) )
    {
      if ( *(_DWORD *)(result + 4) == 0 )
        _inconsistency();
      if ( a1 == *(_DWORD *)(result + 4) )
        break;
    }
    *(_DWORD *)(result + 4) = *(_DWORD *)(a1 + 4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01EA7E
// Name: ?_CallCatchBlock2@@YAPAXPAUEHRegistrationNode@@PBU_s_FuncInfo@@PAXHK@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _CallCatchBlock2(LPARAM lParam, const struct _s_FuncInfo *a2, WNDENUMPROC lpEnumFunc)
{
  return EnumWindows(lpEnumFunc, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x3F01EB54
// Name: _CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CPtoLCID@<eax>(int a1@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  v1 = a1 - 932;
  if ( v1 == 0 )
    return 1041;
  v2 = v1 - 4;
  if ( v2 == 0 )
    return 2052;
  v3 = v2 - 13;
  if ( v3 == 0 )
    return 1042;
  if ( v3 == 1 )
    return 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01EBB2
// Name: ___BuildCatchObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __BuildCatchObject()
{
  JUMPOUT(0x3F01EBB5);
}

//------------------------------------------------------------------------------
// Address: 0x3F01EC43
// Name: CatchIt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CatchIt(
        EHRegistrationNode *pRN@<esi>,
        const _s_HandlerType *pCatch@<ebx>,
        const _s_TryBlockMapEntry *pEntry@<edi>,
        void *a4@<edx>,
        int a5@<ebp>)
{
  size_t v5; // [esp-4h] [ebp-4h]

  memset_0(a1: a4, Val: 32, Size: v5);
  if ( BYTE1(pCatch->adjectives) == 0 )
  {
    ((void (__cdecl *)(_DWORD, int, int, const _s_TryBlockMapEntry *, int, void *, EHRegistrationNode *, _DWORD))&__lookuptable[56])(
      a1: 0,
      a2: 1,
      a3: a5 + 920,
      a4: pEntry,
      a5: a5 - 104,
      a6: pRN->frameHandler,
      a7: pRN[1].pNext,
      a8: 0);
    __crtLCMapStringA_0(a1: 0);
  }
  JUMPOUT(0x3F01EC2E);
}

//------------------------------------------------------------------------------
// Address: 0x3F01ECAF
// Name: FindHandlerForForeignException
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn FindHandlerForForeignException(int a1@<ebx>)
{
  __crtLCMapStringA_0(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F01EDFD
// Name: sub_3F01EDFD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F01EDFD()
{
  return ((int (__cdecl *)(int))loc_3F020118)(a1: 13);
}

//------------------------------------------------------------------------------
// Address: 0x3F01EE06
// Name: int getSystemCP(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn getSystemCP()
{
  _BYTE v0[16]; // [esp+4h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _DWORD))loc_3F01A0FA)(a1: v0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F01EE80
// Name: __setmbcp_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn _setmbcp_nolock_0()
{
  getSystemCP();
}

//------------------------------------------------------------------------------
// Address: 0x3F01F059
// Name: __setmbcp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __noreturn _setmbcp_0(int CodePage)
{
  _getptd_0();
  ((void (*)(void))__updatetmbcinfo_0)();
  getSystemCP();
}

//------------------------------------------------------------------------------
// Address: 0x3F01F351
// Name: ___addlocaleref_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __cdecl __addlocaleref_0(volatile LONG *lpAddend)
{
  volatile LONG **v1; // ebx
  int i; // ebp

  InterlockedIncrement(lpAddend);
  if ( *((_DWORD *)lpAddend + 44) != 0 )
    InterlockedIncrement(lpAddend: *((volatile LONG **)lpAddend + 44));
  if ( *((_DWORD *)lpAddend + 46) != 0 )
    InterlockedIncrement(lpAddend: *((volatile LONG **)lpAddend + 46));
  if ( *((_DWORD *)lpAddend + 45) != 0 )
    InterlockedIncrement(lpAddend: *((volatile LONG **)lpAddend + 45));
  if ( *((_DWORD *)lpAddend + 48) != 0 )
    InterlockedIncrement(lpAddend: *((volatile LONG **)lpAddend + 48));
  v1 = (volatile LONG **)(lpAddend + 20);
  for ( i = 6; i != 0; --i )
  {
    if ( *(v1 - 2) != (volatile LONG *)&unk_3F03B7F8 && *v1 != nullptr )
      InterlockedIncrement(lpAddend: *v1);
    if ( *(v1 - 1) != nullptr && v1[1] != nullptr )
      InterlockedIncrement(lpAddend: v1[1]);
    v1 += 4;
  }
  return InterlockedIncrement(lpAddend: (volatile LONG *)(*((_DWORD *)lpAddend + 53) + 180));
}

//------------------------------------------------------------------------------
// Address: 0x3F01F3D7
// Name: ___removelocaleref_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __removelocaleref_0(
        volatile LONG *lpAddend,
        unsigned int a2,
        const char *a3,
        int a4,
        unsigned __int16 *a5,
        int a6,
        int a7,
        int a8)
{
  if ( lpAddend == nullptr )
    JUMPOUT(0x3F01F45F);
  InterlockedDecrement(lpAddend);
  if ( *((_DWORD *)lpAddend + 44) != 0 )
    InterlockedDecrement(lpAddend: *((volatile LONG **)lpAddend + 44));
  if ( *((_DWORD *)lpAddend + 46) == 0 )
    JUMPOUT(0x3F01F406);
  return __crtGetStringTypeA(
           plocinfo: (localeinfo_struct *)lpAddend,
           dwInfoType: a2,
           lpSrcStr: a3,
           cchSrc: a4,
           lpCharType: a5,
           code_page: a6,
           lcid: a7,
           bError: a8);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F404
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __crtGetStringTypeA(void (*a1)(void)@<edi>, int a2@<esi>)
{
  _DWORD *v2; // ebx

  a1();
  if ( *(_DWORD *)(a2 + 180) != 0 )
    ((void (__stdcall *)(_DWORD))a1)(a1: *(_DWORD *)(a2 + 180));
  if ( *(_DWORD *)(a2 + 192) != 0 )
    ((void (__stdcall *)(_DWORD))a1)(a1: *(_DWORD *)(a2 + 192));
  v2 = (_DWORD *)(a2 + 80);
  if ( *(_UNKNOWN **)(a2 + 72) != &unk_3F03B7F8 && *v2 != 0 )
    ((void (__stdcall *)(_DWORD))a1)(a1: *v2);
  if ( *(_DWORD *)(a2 + 76) != 0 )
    JUMPOUT(0x3F01F443);
  JUMPOUT(0x3F01F448);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F444
// Name: ___free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __free_lc_time(
        char _AL@<al>,
        int _EBX@<ebx>,
        int a3@<ebp>,
        void (__cdecl *a4)(int)@<edi>,
        int a5@<esi>)
{
  __asm { xlat }
  if ( a3 != 1 )
    JUMPOUT(0x3F01F426);
  a4(a1: *(_DWORD *)(a5 + 212) + 180);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F463
// Name: __updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01F4A1
// Name: ___updatetlocinfo_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __updatetlocinfo_0()
{
  int v0; // esi
  int v1; // esi
  int v3; // [esp+10h] [ebp-1Ch]

  v0 = _getptd_0();
  if ( (dword_3F03B7F4 & *(_DWORD *)(v0 + 112)) != 0 && *(_DWORD *)(v0 + 108) != 0 )
  {
    v1 = *(_DWORD *)(_getptd_0() + 108);
  }
  else
  {
    ((void (__stdcall *)(int))_lock_0)(a1: 12);
    v3 = _updatetlocinfoEx_nolock();
    ((void (__cdecl *)(int))loc_3F020118)(a1: 12);
    v1 = v3;
  }
  if ( v1 == 0 )
    raise(signum: 0x20u);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F01F517
// Name: __use_encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _use_encode_pointer()
{
  unsigned int v0; // ebx
  HMODULE ModuleHandleA; // eax
  char *v3; // esi
  const char *v4; // edi
  int v5; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v0 = 0;
  v5 = 1;
  v6 = 0;
  ((void (__cdecl *)(int *))loc_3F01AE52)(a1: &v6);
  if ( v6 > 5 )
    return 1;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v3 = (char *)ModuleHandleA + *((_DWORD *)ModuleHandleA + 15);
  v4 = &v3[*((unsigned __int16 *)v3 + 10) + 24];
  if ( *((_WORD *)v3 + 3) != 0 )
  {
    while ( strcmp_0(Str1: ".mixcrt", Str2: v4) != 0 )
    {
      ++v0;
      v4 += 40;
      if ( v0 >= *((unsigned __int16 *)v3 + 3) )
        return v5;
    }
    return 0;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F01F5D4
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl __free_lconv_num(lconv *l, int a2)
{
  FARPROC ProcAddress; // eax
  HMODULE v3; // [esp-4h] [ebp-8h]
  const char *v4; // [esp+0h] [ebp-4h]

  ProcAddress = GetProcAddress(hModule: v3, lpProcName: v4);
  if ( ProcAddress != nullptr )
    ((void (__cdecl *)(int))ProcAddress)(a1: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F5F1
// Name: __encoded_null_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _encoded_null_0()
{
  return ((int (__cdecl *)(_DWORD))_encode_pointer)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F614
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __free_lconv_mon(int (__stdcall *a1)(DWORD)@<esi>, lconv *l)
{
  int (*v2)(void); // eax
  int v3; // eax
  PVOID (__stdcall *DecodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi

  v2 = (int (*)(void))a1(a1: dword_3F03B8EC);
  v3 = v2();
  if ( v3 != 0 )
  {
    DecodePointer = *(PVOID (__stdcall **)(PVOID))(v3 + 508);
    goto LABEL_6;
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  if ( ModuleHandleA != nullptr && _use_encode_pointer() != 0 )
  {
    DecodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "DecodePointer");
LABEL_6:
    if ( DecodePointer != nullptr )
      DecodePointer(Ptr: l);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01F69D
// Name: ____lc_codepage_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__usercall ___lc_codepage_func@<eax>(char a1@<zf>, void *a2@<esi>)
{
  if ( a1 )
  {
    a2 = (void *)((int (__cdecl *)(LPVOID))_decode_pointer)(a1: lpTlsValue);
    TlsSetValue(dwTlsIndex: dword_3F03B8EC, lpTlsValue: a2);
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F01F6C3
// Name: _strcat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge strcat_s@<eax>(char a1@<zf>, int a2@<eax>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  int (*v5)(void); // eax

  if ( a1 )
  {
    ((void (*)(void))(a2 | 0x59FFFFFF))();
    dword_3F03B8E8 = -1;
    if ( dword_3F03B8EC != -1 )
    {
      TlsFree(dwTlsIndex: dword_3F03B8EC);
      dword_3F03B8EC = -1;
    }
    JUMPOUT(0x3F0200C3);
  }
  v5 = (int (*)(void))((int (*)(void))_decode_pointer)();
  return v5();
}

//------------------------------------------------------------------------------
// Address: 0x3F01F740
// Name: _strcspn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strcspn(char a1@<zf>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  if ( !a1 && _use_encode_pointer() != 0 )
  {
    *(_DWORD *)(a4 + 504) = GetProcAddress(hModule: *(HMODULE *)(a2 - 28), lpProcName: "EncodePointer");
    *(_DWORD *)(a4 + 508) = GetProcAddress(hModule: *(HMODULE *)(a2 - 28), lpProcName: "DecodePointer");
  }
  *(_DWORD *)(a4 + 112) = a3;
  *(_BYTE *)(a4 + 200) = 67;
  *(_BYTE *)(a4 + 331) = 67;
  JUMPOUT(0x3F01F782);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F786
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strncpy_s(int _EAX@<eax>, int a2@<ebp>, int a3@<esi>)
{
  int v4; // eax

  __asm { aas }
  *(_DWORD *)(a3 + 104) = _EAX;
  InterlockedIncrement(lpAddend: _EAX);
  ((void (__cdecl *)(int))_lock_0)(a1: 12);
  *(_DWORD *)(a2 - 4) = 0;
  v4 = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(a3 + 108) = v4;
  if ( v4 == 0 )
    *(_DWORD *)(a3 + 108) = off_3F03B8D8;
  __addlocaleref_0(lpAddend: *(volatile LONG **)(a3 + 108));
  *(_DWORD *)(a2 - 4) = -2;
  JUMPOUT(0x3F01F7CA);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F84A
// Name: __getptd_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _getptd_0()
{
  int v0; // esi

  v0 = ((int (*)(void))loc_3F01F7D3)();
  if ( v0 == 0 )
    raise(signum: 0x10u);
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x3F01F900
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F01F940
// Name: ___ansicp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __ansicp(int a1@<ebp>, _DWORD *a2@<edi>, void *a3@<esi>, int lcid)
{
  _DWORD *v4; // edi

  v4 = (_DWORD *)((char *)a2 + *a2);
  if ( v4 != nullptr && *v4 == 0 )
    ((void (__cdecl *)(_DWORD *))__freetlocinfo_0)(a1: v4);
  *(_DWORD *)(a1 - 4) = -2;
  sub_3F01F97A();
  free(Block: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F96E
// Name: sub_3F01F96E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F01F96E()
{
  return ((int (__cdecl *)(int))loc_3F020118)(a1: 13);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F977
// Name: sub_3F01F977
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F01F977()
{
  return sub_3F01F97A();
}

//------------------------------------------------------------------------------
// Address: 0x3F01F97A
// Name: sub_3F01F97A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F01F97A()
{
  return ((int (__cdecl *)(int))loc_3F020118)(a1: 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F01F987
// Name: ___convertcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __convertcp(int fromCP)
{
  int v1; // edi
  int (__stdcall *Value)(int); // eax
  void (__stdcall *v3)(int, _DWORD); // eax
  char *result; // eax
  int cpi_12; // [esp+20h] [ebp-Ch]
  int cpi_12a; // [esp+20h] [ebp-Ch]

  v1 = fromCP;
  if ( fromCP == 0 && TlsGetValue(dwTlsIndex: dword_3F03B8EC) != nullptr )
  {
    cpi_12 = dword_3F03B8E8;
    Value = (int (__stdcall *)(int))TlsGetValue(dwTlsIndex: dword_3F03B8EC);
    v1 = Value(a1: cpi_12);
  }
  cpi_12a = dword_3F03B8E8;
  v3 = (void (__stdcall *)(int, _DWORD))((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F03C880);
  v3(a1: cpi_12a, a2: 0);
  ((void (__stdcall *)(int))_freefls)(a1: v1);
  result = (char *)dword_3F03B8EC;
  if ( dword_3F03B8EC != -1 )
    return (char *)TlsSetValue(dwTlsIndex: dword_3F03B8EC, lpTlsValue: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01FB39
// Name: fastzero_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall fastzero_I(DWORD *a1@<esi>)
{
  int (*v1)(void); // eax
  DWORD CurrentThreadId; // eax
  int v3; // [esp-10h] [ebp-10h]
  int v4; // [esp-Ch] [ebp-Ch]

  v1 = (int (*)(void))((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F03C880);
  if ( v1() != 0 )
  {
    ((void (__stdcall *)(DWORD *, _DWORD))loc_3F01F714)(a1, a2: 0);
    CurrentThreadId = GetCurrentThreadId();
    a1[1] = -1;
    *a1 = CurrentThreadId;
  }
  else
  {
    ((void (__stdcall *)(int, int))loc_3F01F6D7)(a1: v3, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F01FBAB
// Name: __errno_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno_0()
{
  int v0; // eax

  v0 = ((int (*)(void))loc_3F01F7D3)();
  if ( v0 != 0 )
    return (int *)(v0 + 8);
  else
    return (int *)&unk_3F03BA58;
}

//------------------------------------------------------------------------------
// Address: 0x3F01FC1F
// Name: __lseeki64_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
__int64 __usercall _lseeki64_nolock@<edx:eax>(
        int a1@<ebx>,
        _DWORD *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int fh,
        __int64 pos,
        int mthd)
{
  int v7; // ecx
  _BYTE *v8; // eax
  int v9; // eax
  bool v10; // zf
  LCID v12; // [esp-10h] [ebp-18h]
  DWORD v13; // [esp-Ch] [ebp-14h]
  const wchar_t *v14; // [esp-8h] [ebp-10h]
  int v15; // [esp-4h] [ebp-Ch]
  wchar_t *newpos; // [esp+0h] [ebp-8h]
  int newpos_4; // [esp+4h] [ebp-4h]

  if ( LCMapStringW(Locale: v12, dwMapFlags: v13, lpSrcStr: v14, cchSrc: v15, lpDestStr: newpos, cchDest: newpos_4) != 0 )
  {
    dword_3F03C888 = a3;
  }
  else if ( GetLastError() == 120 )
  {
    dword_3F03C888 = 2;
  }
  if ( a2[5] > a1 )
  {
    v7 = a2[5];
    v8 = (_BYTE *)a2[4];
    while ( 1 )
    {
      --v7;
      if ( *v8 == (_BYTE)a1 )
        break;
      ++v8;
      if ( v7 == a1 )
      {
        v7 = -1;
        break;
      }
    }
    v9 = a2[5] - v7 - 1;
    if ( v9 < a2[5] )
      v9 = a2[5] - v7;
    a2[5] = v9;
  }
  if ( dword_3F03C888 == 2 || dword_3F03C888 == a1 )
    JUMPOUT(0x3F01FE26);
  if ( dword_3F03C888 != 1 )
    JUMPOUT(0x3F01FE57);
  v10 = a2[8] == a1;
  *(a2 - 2) = a1;
  if ( v10 )
    a2[8] = *(_DWORD *)(*(_DWORD *)a4 + 4);
  return _lseeki64(fh, pos, mthd);
}

//------------------------------------------------------------------------------
// Address: 0x3F01FCA2
// Name: __lseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _lseeki64(
        wchar_t *a1@<ebx>,
        int a2@<ebp>,
        int (__stdcall *a3)(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar)@<esi>,
        int fh,
        __int64 pos)
{
  int v5; // eax
  int v6; // edi
  unsigned int v7; // eax
  void *v8; // esp
  int *v9; // eax
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // eax
  void *v13; // esp
  wchar_t *p_pos; // esi
  int v15; // [esp+0h] [ebp-4h]
  int retaddr; // [esp+4h] [ebp+0h] BYREF

  v5 = a3(
         CodePage: *(_DWORD *)(a2 + 32),
         dwFlags: 8 * (*(_DWORD *)(a2 + 36) != (_DWORD)a1) + 1,
         lpMultiByteStr: *(LPCCH *)(a2 + 16),
         cbMultiByte: *(_DWORD *)(a2 + 20),
         lpWideCharStr: a1,
         cchWideChar: v15);
  v6 = v5;
  if ( (wchar_t *)v5 == a1 )
    goto LABEL_34;
  if ( v5 <= (int)a1 || 0xFFFFFFE0 / v5 < 2 )
  {
    *(_DWORD *)(a2 - 12) = a1;
LABEL_12:
    if ( *(wchar_t **)(a2 - 12) != a1 )
    {
      if ( a3(
             CodePage: *(_DWORD *)(a2 + 32),
             dwFlags: 1u,
             lpMultiByteStr: *(LPCCH *)(a2 + 16),
             cbMultiByte: *(_DWORD *)(a2 + 20),
             lpWideCharStr: *(LPWSTR *)(a2 - 12),
             cchWideChar: v6) == 0 )
        goto LABEL_32;
      v10 = LCMapStringW(
              Locale: *(_DWORD *)(a2 + 8),
              dwMapFlags: *(_DWORD *)(a2 + 12),
              lpSrcStr: *(LPCWSTR *)(a2 - 12),
              cchSrc: v6,
              lpDestStr: a1,
              cchDest: (int)a1);
      v11 = v10;
      *(_DWORD *)(a2 - 8) = v10;
      if ( (wchar_t *)v10 == a1 )
        goto LABEL_32;
      if ( (*(_WORD *)(a2 + 12) & 0x400) != 0 )
      {
        if ( *(wchar_t **)(a2 + 28) != a1 && v10 <= *(_DWORD *)(a2 + 28) )
          LCMapStringW(
            Locale: *(_DWORD *)(a2 + 8),
            dwMapFlags: *(_DWORD *)(a2 + 12),
            lpSrcStr: *(LPCWSTR *)(a2 - 12),
            cchSrc: v6,
            lpDestStr: *(LPWSTR *)(a2 + 24),
            cchDest: *(_DWORD *)(a2 + 28));
        goto LABEL_32;
      }
      if ( v10 <= (int)a1 || 0xFFFFFFE0 / v10 < 2 )
      {
        p_pos = nullptr;
      }
      else
      {
        v12 = 2 * v10 + 8;
        if ( v12 > 0x400 )
        {
          malloc_0(Size: 2 * v11 + 8);
          JUMPOUT(0x3F01FDBC);
        }
        v13 = alloca(v12);
        if ( &retaddr == (int *)a1 )
LABEL_32:
          JUMPOUT(0x3F01FE15);
        retaddr = 52428;
        p_pos = (wchar_t *)&pos;
      }
      if ( p_pos != a1 )
      {
        if ( LCMapStringW(
               Locale: *(_DWORD *)(a2 + 8),
               dwMapFlags: *(_DWORD *)(a2 + 12),
               lpSrcStr: *(LPCWSTR *)(a2 - 12),
               cchSrc: v6,
               lpDestStr: p_pos,
               cchDest: *(_DWORD *)(a2 - 8)) != 0 )
          JUMPOUT(0x3F01FDFD);
        JUMPOUT(0x3F01FE0E);
      }
      goto LABEL_32;
    }
LABEL_34:
    JUMPOUT(0x3F01FE57);
  }
  v7 = 2 * v5 + 8;
  if ( v7 > 0x400 )
  {
    v9 = (int *)malloc_0(Size: 2 * v6 + 8);
    if ( v9 != (int *)a1 )
    {
      *v9 = 56797;
      goto LABEL_9;
    }
  }
  else
  {
    v8 = alloca(v7);
    v9 = &retaddr;
    if ( &retaddr != (int *)a1 )
    {
      retaddr = 52428;
LABEL_9:
      v9 += 2;
    }
  }
  *(_DWORD *)(a2 - 12) = v9;
  goto LABEL_12;
}

//------------------------------------------------------------------------------
// Address: 0x3F01FDFF
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _isatty@<eax>(int a1@<ebp>, void *a2@<esi>)
{
  DWORD v3; // [esp-14h] [ebp-1Ch]
  const wchar_t *v4; // [esp-10h] [ebp-18h]
  int v5; // [esp-Ch] [ebp-14h]
  char *v6; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]
  const char *v8; // [esp+0h] [ebp-8h]
  int *v9; // [esp+4h] [ebp-4h]

  *(_DWORD *)(a1 - 8) = WideCharToMultiByte(
                          CodePage: *(_DWORD *)(a1 + 32),
                          dwFlags: v3,
                          lpWideCharStr: v4,
                          cchWideChar: v5,
                          lpMultiByteStr: v6,
                          cbMultiByte: v7,
                          lpDefaultChar: v8,
                          lpUsedDefaultChar: v9);
  _freea_0(Memory: a2);
  _freea_0(Memory: *(void **)(a1 - 12));
  return *(_DWORD *)(a1 - 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F01FF91
// Name: ___crtLCMapStringA_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtLCMapStringA_0(int a1)
{
  _BYTE v1[16]; // [esp+0h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v1, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F01FFBC
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall wctomb_s@<eax>(int a1@<eax>, int a2@<ebp>)
{
  int result; // eax

  LOBYTE(a1) = a1 | 0xE8;
  result = a1 + 2080374788;
  if ( *(_BYTE *)(a2 - 4) != 0 )
    *(_DWORD *)(*(_DWORD *)(a2 - 8) + 112) &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F01FFD7
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l()
{
  return __CS__;
}

//------------------------------------------------------------------------------
// Address: 0x3F01FFDE
// Name: __callnewh_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _callnewh_0(size_t Size)
{
  int (__cdecl *v1)(size_t); // eax

  v1 = (int (__cdecl *)(size_t))((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F03C88C);
  return v1 != nullptr && v1(a1: Size) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F02000D
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall isleadbyte(char a1@<zf>, int a2@<edx>)
{
  *(_BYTE *)(a2 - 2079841212) = __ROR1__(*(_BYTE *)(a2 - 2079841212), 192);
  if ( a1 )
    JUMPOUT(0x3F02001C);
  JUMPOUT(0x3F02002C);
}

//------------------------------------------------------------------------------
// Address: 0x3F020020
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _aulldvrm@<eax>(
        int a1@<eax>,
        char a2@<dh>,
        int _ECX@<ecx>,
        int a4@<ebp>,
        _RTL_CRITICAL_SECTION *a5@<edi>,
        int a6@<esi>)
{
  bool v6; // zf

  v6 = a2 + *(_BYTE *)(a4 + a1 - 23) == 0;
  *(_BYTE *)(a4 + a1 - 23) += a2;
  if ( !v6 )
    JUMPOUT(0x3F02002A);
  __asm { rcr     byte ptr [ecx+59h], 74h }
  if ( a6 < 36 )
  {
    if ( *(&dbl_3F03BA60 + 2 * a6 + 1) == (LPCRITICAL_SECTION)1 )
    {
      *(&dbl_3F03BA60 + 2 * a6) = a5;
      JUMPOUT(0x3F020096);
    }
    JUMPOUT(0x3F0200AB);
  }
  return has_osfxsr_set();
}

//------------------------------------------------------------------------------
// Address: 0x3F0200B5
// Name: has_osfxsr_set
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl has_osfxsr_set()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F020105
// Name: __get_sse2_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _get_sse2_info@<eax>(char a1@<zf>, int result@<eax>, int (__cdecl *a3)(int)@<ebx>, int a4@<esi>)
{
  if ( a1 )
    result = a3(a1: result);
  if ( a4 + 8 < (int)&dword_3F03BB80 )
    JUMPOUT(0x3F0200FB);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F020165
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __sse2_available_init(unsigned __int8 a1@<al>)
{
  if ( a1 != 0xF5 )
    JUMPOUT(0x3F020171);
  JUMPOUT(0x3F020173);
}

//------------------------------------------------------------------------------
// Address: 0x3F020172
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fcloseall@<eax>(void *a1@<ebx>, int a2@<ebp>, void **_ESI@<esi>)
{
  void *v3; // edi

  __asm { outsb }
  v3 = (void *)_malloc_crt_0(Size: 0x18u);
  if ( v3 == a1 )
  {
    *_errno_0() = 12;
    return 0;
  }
  else
  {
    ((void (__cdecl *)(int))_lock_0)(a1: 10);
    *(_DWORD *)(a2 - 4) = a1;
    if ( *_ESI == a1 )
    {
      if ( __crtInitCritSecAndSpinCount_0(a1: v3, a2: 4000) != 0 )
      {
        *_ESI = v3;
      }
      else
      {
        free(Block: v3);
        *_errno_0() = 12;
        *(_DWORD *)(a2 - 28) = a1;
      }
    }
    else
    {
      free(Block: v3);
    }
    *(_DWORD *)(a2 - 4) = -2;
    sub_3F0201E7();
    return *(_DWORD *)(a2 - 28);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0201E7
// Name: sub_3F0201E7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F0201E7()
{
  return ((int (__cdecl *)(int))loc_3F020118)(a1: 10);
}

//------------------------------------------------------------------------------
// Address: 0x3F020221
// Name: ___sbh_heap_init_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __sbh_heap_init_0(int a1)
{
  int result; // eax

  result = (int)HeapAlloc(hHeap: hHeap, dwFlags: 0, dwBytes: 0x140u);
  lpMem = (LPVOID)result;
  if ( result != 0 )
  {
    dword_3F03C9E0 = nullptr;
    dword_3F0A3888 = 0;
    dword_3F0A3894 = result;
    dword_3F0A3890 = a1;
    dword_3F0A3898 = 16;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F020269
// Name: ___sbh_find_block_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __sbh_find_block_0(int a1)
{
  char *result; // eax

  for ( result = (char *)lpMem; result < (char *)lpMem + 20 * dword_3F0A3888; result += 20 )
  {
    if ( (unsigned int)(a1 - *((_DWORD *)result + 3)) < 0x100000 )
      return result;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F020294
// Name: ___sbh_free_block_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl __sbh_free_block_0(_DWORD *a1, int a2)
{
  _DWORD *result; // eax
  int *v3; // esi
  unsigned int v4; // edi
  int v5; // ecx
  char *v6; // ebx
  unsigned int v7; // edx
  _BYTE *v8; // ecx
  unsigned int v9; // ebx
  bool v10; // zf
  _BYTE *v11; // ecx
  unsigned int v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // esi
  unsigned int v17; // esi
  _DWORD *v18; // ecx
  int v19; // ebx
  LPVOID *v20; // eax
  _DWORD *v21; // [esp+8h] [ebp-10h]
  int v22; // [esp+Ch] [ebp-Ch]
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  char *v25; // [esp+24h] [ebp+Ch]
  int *v26; // [esp+24h] [ebp+Ch]
  char v27; // [esp+27h] [ebp+Fh]

  result = (_DWORD *)a1[4];
  v3 = (int *)(a2 - 4);
  v4 = (unsigned int)(a2 - a1[3]) >> 15;
  v21 = &result[129 * v4 + 81];
  v5 = *(_DWORD *)(a2 - 4) - 1;
  v24 = v5;
  if ( (v5 & 1) == 0 )
  {
    v6 = (char *)v3 + v5;
    v22 = *(int *)((char *)v3 + v5);
    v23 = *(_DWORD *)(a2 - 8);
    v25 = (char *)v3 + v5;
    if ( (v22 & 1) == 0 )
    {
      v7 = (v22 >> 4) - 1;
      if ( v7 > 0x3F )
        v7 = 63;
      if ( *((_DWORD *)v6 + 1) == *((_DWORD *)v6 + 2) )
      {
        if ( v7 >= 0x20 )
        {
          v11 = (char *)result + v7 + 4;
          v12 = ~(0x80000000 >> (v7 - 32));
          result[v4 + 49] &= v12;
          v10 = (*v11)-- == 1;
          if ( v10 )
            a1[1] &= v12;
        }
        else
        {
          v8 = (char *)result + v7 + 4;
          v9 = ~(0x80000000 >> v7);
          result[v4 + 17] &= v9;
          v10 = (*v8)-- == 1;
          if ( v10 )
            *a1 &= v9;
        }
        v6 = v25;
      }
      v5 = v22 + v24;
      *(_DWORD *)(*((_DWORD *)v6 + 2) + 4) = *((_DWORD *)v6 + 1);
      *(_DWORD *)(*((_DWORD *)v25 + 1) + 8) = *((_DWORD *)v25 + 2);
      v24 += v22;
    }
    v13 = (v5 >> 4) - 1;
    if ( v13 > 0x3F )
      v13 = 63;
    if ( (v23 & 1) != 0 )
    {
      v14 = (unsigned int)a1;
    }
    else
    {
      v26 = (int *)((char *)v3 - v23);
      v14 = (v23 >> 4) - 1;
      if ( v14 > 0x3F )
        v14 = 63;
      v15 = v23 + v5;
      v13 = (v15 >> 4) - 1;
      v24 = v15;
      if ( v13 > 0x3F )
        v13 = 63;
      if ( v14 != v13 )
      {
        if ( v26[1] == v26[2] )
        {
          if ( v14 >= 0x20 )
          {
            v17 = ~(0x80000000 >> (v14 - 32));
            result[v4 + 49] &= v17;
            v10 = (*((_BYTE *)result + v14 + 4))-- == 1;
            if ( v10 )
              a1[1] &= v17;
          }
          else
          {
            v16 = ~(0x80000000 >> v14);
            result[v4 + 17] &= v16;
            v10 = (*((_BYTE *)result + v14 + 4))-- == 1;
            if ( v10 )
              *a1 &= v16;
          }
        }
        *(_DWORD *)(v26[2] + 4) = v26[1];
        *(_DWORD *)(v26[1] + 8) = v26[2];
      }
      v3 = v26;
    }
    if ( (v23 & 1) != 0 || v14 != v13 )
    {
      v18 = &v21[2 * v13];
      v19 = v18[1];
      v3[2] = (int)v18;
      v3[1] = v19;
      v18[1] = v3;
      *(_DWORD *)(v3[1] + 8) = v3;
      if ( v3[1] == v3[2] )
      {
        v27 = *((_BYTE *)result + v13 + 4);
        *((_BYTE *)result + v13 + 4) = v27 + 1;
        if ( v13 >= 0x20 )
        {
          if ( v27 == 0 )
            a1[1] |= 0x80000000 >> (v13 - 32);
          result[v4 + 49] |= 0x80000000 >> (v13 - 32);
        }
        else
        {
          if ( v27 == 0 )
            *a1 |= 0x80000000 >> v13;
          result[v4 + 17] |= 0x80000000 >> v13;
        }
      }
    }
    *v3 = v24;
    *(int *)((char *)v3 + v24 - 4) = v24;
    result += 129 * v4 + 81;
    v10 = (*v21)-- == 1;
    if ( v10 )
    {
      if ( dword_3F03C9E0 != nullptr )
      {
        VirtualFree(
          lpAddress: (LPVOID)(*((_DWORD *)dword_3F03C9E0 + 3) + (dword_3F0A389C << 15)),
          dwSize: 0x8000u,
          dwFreeType: 0x4000u);
        *((_DWORD *)dword_3F03C9E0 + 2) |= 0x80000000 >> dword_3F0A389C;
        *(_DWORD *)(*((_DWORD *)dword_3F03C9E0 + 4) + 4 * dword_3F0A389C + 196) = 0;
        --*(_BYTE *)(*((_DWORD *)dword_3F03C9E0 + 4) + 67);
        v20 = (LPVOID *)dword_3F03C9E0;
        if ( *(_BYTE *)(*((_DWORD *)dword_3F03C9E0 + 4) + 67) == 0 )
        {
          *((_DWORD *)dword_3F03C9E0 + 1) &= ~1u;
          v20 = (LPVOID *)dword_3F03C9E0;
        }
        if ( v20[2] == (LPVOID)-1 )
        {
          VirtualFree(lpAddress: v20[3], dwSize: 0, dwFreeType: 0x8000u);
          HeapFree(hHeap: hHeap, dwFlags: 0, lpMem: *((LPVOID *)dword_3F03C9E0 + 4));
          memcpy_0(
            a1: dword_3F03C9E0,
            Src: (char *)dword_3F03C9E0 + 20,
            Size: (size_t)lpMem + 20 * dword_3F0A3888 - (_DWORD)dword_3F03C9E0 - 20);
          --dword_3F0A3888;
          if ( a1 > dword_3F03C9E0 )
            a1 -= 5;
          dword_3F0A3894 = (int)lpMem;
        }
      }
      dword_3F03C9E0 = a1;
      dword_3F0A389C = v4;
      return a1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0205A8
// Name: ___sbh_alloc_new_region
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__sbh_alloc_new_region()
{
  int v0; // esi
  void *v1; // eax
  char *v3; // esi
  LPVOID v4; // eax
  LPVOID v5; // eax

  v0 = dword_3F0A3888;
  if ( dword_3F0A3888 == dword_3F0A3898 )
  {
    v1 = HeapReAlloc(hHeap: hHeap, dwFlags: 0, lpMem: lpMem, dwBytes: 20 * (dword_3F0A3898 + 16));
    if ( v1 == nullptr )
      return nullptr;
    dword_3F0A3898 += 16;
    v0 = dword_3F0A3888;
    lpMem = v1;
  }
  v3 = (char *)lpMem + 20 * v0;
  v4 = HeapAlloc(hHeap: hHeap, dwFlags: 8u, dwBytes: 0x41C4u);
  *((_DWORD *)v3 + 4) = v4;
  if ( v4 == nullptr )
    return nullptr;
  v5 = VirtualAlloc(lpAddress: nullptr, dwSize: 0x100000u, flAllocationType: 0x2000u, flProtect: 4u);
  *((_DWORD *)v3 + 3) = v5;
  if ( v5 == nullptr )
  {
    HeapFree(hHeap: hHeap, dwFlags: 0, lpMem: *((LPVOID *)v3 + 4));
    return nullptr;
  }
  *((_DWORD *)v3 + 2) = -1;
  *(_DWORD *)v3 = 0;
  *((_DWORD *)v3 + 1) = 0;
  ++dword_3F0A3888;
  **((_DWORD **)v3 + 4) = -1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F020658
// Name: ___sbh_alloc_new_group_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __sbh_alloc_new_group_0(_DWORD *a1)
{
  int v1; // eax
  int v2; // esi
  int v3; // ebx
  int v4; // eax
  int i; // edx
  _DWORD *v6; // edi
  _DWORD *v8; // edx
  _DWORD *v9; // eax
  int j; // ecx

  v1 = a1[2];
  v2 = a1[4];
  v3 = 0;
  while ( v1 >= 0 )
  {
    v1 *= 2;
    ++v3;
  }
  v4 = 516 * v3 + v2 + 324;
  for ( i = 63; i != 0; --i )
  {
    *(_DWORD *)(v4 + 8) = v4;
    *(_DWORD *)(v4 + 4) = v4;
    v4 += 8;
  }
  v6 = (_DWORD *)(a1[3] + (v3 << 15));
  if ( VirtualAlloc(lpAddress: v6, dwSize: 0x8000u, flAllocationType: 0x1000u, flProtect: 4u) == nullptr )
    return -1;
  v8 = v6 + 7168;
  if ( v6 < v6 + 7168 )
  {
    v9 = v6 + 4;
    for ( j = 8; j != 0; --j )
    {
      *(v9 - 2) = -1;
      v9[1019] = -1;
      *v9 = v9 + 1023;
      *(v9 - 1) = 4080;
      v9[1] = v9 - 1025;
      v9[1018] = 4080;
      v9 += 1024;
    }
    v8 = v6 + 7168;
  }
  *(_DWORD *)(516 * v3 + v2 + 832) = v6 + 3;
  v6[5] = 516 * v3 + v2 + 828;
  *(_DWORD *)(516 * v3 + v2 + 836) = v8 + 3;
  v8[4] = 516 * v3 + v2 + 828;
  *(_DWORD *)(v2 + 4 * v3 + 68) = 0;
  *(_DWORD *)(v2 + 4 * v3 + 196) = 1;
  if ( (*(_BYTE *)(v2 + 67))++ == 0 )
    a1[1] |= 1u;
  a1[2] &= ~(0x80000000 >> v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F02096A
// Name: __sopen_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _sopen_helper(char a1@<ah>, _BYTE *a2@<ecx>, int a3@<esi>)
{
  _BYTE *v3; // ecx

  *a2 |= a1;
  v3 = a2 - 1;
  if ( a3 != 1 && v3 != nullptr )
    JUMPOUT(0x3F020946);
  JUMPOUT(0x3F020902);
}

//------------------------------------------------------------------------------
// Address: 0x3F020A36
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _sopen_s@<eax>(int result@<eax>)
{
  *(_BYTE *)(result + 95) = __ROL1__(*(_BYTE *)(result + 95), 94);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F020A54
// Name: __mbsnbcmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbcmp_l@<eax>(
        char *a1@<eax>,
        int a2@<ecx>,
        int a3@<ebp>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        const unsigned __int8 *n)
{
  signed int v6; // ecx
  int v7; // ecx
  unsigned int v8; // esi
  unsigned int v9; // ecx
  char *i; // ebx
  int *v11; // eax
  int v12; // edx
  bool v13; // zf
  int v14; // edx
  _DWORD *j; // ecx
  int v16; // edi
  int v17; // ecx

  v6 = (a2 + 23) & 0xFFFFFFF0;
  *(_DWORD *)(a3 - 16) = v6;
  v7 = (v6 >> 4) - 1;
  if ( v7 >= 32 )
  {
    v8 = 0;
    *(_DWORD *)(a3 - 8) = 0xFFFFFFFF >> (v7 - 32);
  }
  else
  {
    v8 = 0xFFFFFFFF >> v7;
    *(_DWORD *)(a3 - 8) = -1;
  }
  v9 = dword_3F0A3894;
  for ( i = (char *)dword_3F0A3894; ; i += 20 )
  {
    *(_DWORD *)(a3 + 8) = i;
    if ( i >= a1 || (v8 & *(_DWORD *)i | *(_DWORD *)(a3 - 8) & *((_DWORD *)i + 1)) != 0 )
      break;
  }
  if ( i == a1 )
  {
    for ( i = (char *)lpMem; ; i += 20 )
    {
      *(_DWORD *)(a3 + 8) = i;
      if ( (unsigned int)i >= v9 || (v8 & *(_DWORD *)i | *(_DWORD *)(a3 - 8) & *((_DWORD *)i + 1)) != 0 )
        break;
    }
    if ( i == (char *)v9 )
    {
      while ( i < a1 && *((_DWORD *)i + 2) == 0 )
      {
        i += 20;
        *(_DWORD *)(a3 + 8) = i;
      }
      if ( i == a1 )
      {
        for ( i = (char *)lpMem; ; i += 20 )
        {
          *(_DWORD *)(a3 + 8) = i;
          if ( (unsigned int)i >= v9 || *((_DWORD *)i + 2) != 0 )
            break;
        }
        if ( i == (char *)v9 )
        {
          i = __sbh_alloc_new_region();
          *(_DWORD *)(a3 + 8) = i;
          if ( i == nullptr )
            goto LABEL_38;
        }
      }
      **((_DWORD **)i + 4) = __sbh_alloc_new_group_0(a1: i);
      if ( **((_DWORD **)i + 4) == -1 )
LABEL_38:
        JUMPOUT(0x3F020D1B);
    }
  }
  dword_3F0A3894 = (int)i;
  v11 = *((int **)i + 4);
  v12 = *v11;
  v13 = *v11 == -1;
  *(_DWORD *)(a3 - 4) = *v11;
  if ( v13 || (v8 & v11[v12 + 17] | *(_DWORD *)(a3 - 8) & v11[v12 + 49]) == 0 )
  {
    *(_DWORD *)(a3 - 4) = 0;
    v14 = v11[49];
    for ( j = v11 + 17; (v8 & *j | *(_DWORD *)(a3 - 8) & v14) == 0; ++j )
    {
      ++*(_DWORD *)(a3 - 4);
      v14 = j[33];
    }
    v12 = *(_DWORD *)(a3 - 4);
  }
  *(_DWORD *)(a3 - 12) = &v11[129 * v12 + 81];
  v16 = 0;
  v17 = v8 & v11[v12 + 17];
  if ( v17 == 0 )
  {
    v17 = *(_DWORD *)(a3 - 8) & v11[v12 + 49];
    v16 = 32;
  }
  while ( v17 >= 0 )
  {
    v17 *= 2;
    ++v16;
  }
  return _mbsnbcmp(s1, s2, (unsigned int)n);
}

//------------------------------------------------------------------------------
// Address: 0x3F020BBD
// Name: __mbsnbcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsnbcmp(
        char a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        int a4@<ecx>,
        int a5@<ebp>,
        int a6@<edi>,
        int a7@<esi>)
{
  *(_DWORD *)(a5 - 8) = a4;
  if ( !(a2 ^ a3 | a1) )
    a7 = 63;
  if ( a7 != a6 )
    JUMPOUT(0x3F020BD3);
  JUMPOUT(0x3F020CCE);
}

//------------------------------------------------------------------------------
// Address: 0x3F020BD4
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _global_unwind2(int a1@<ebp>, int a2@<edi>)
{
  if ( a2 < 32 )
  {
    *(_DWORD *)(a1 - 20) = ~(0x80000000 >> a2);
    JUMPOUT(0x3F020BF3);
  }
  JUMPOUT(0x3F020C05);
}

//------------------------------------------------------------------------------
// Address: 0x3F020BF4
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _unwind_handler(char a1@<zf>, char a2@<al>, int a3@<ebp>, int a4@<edi>, int a5@<esi>)
{
  *(_BYTE *)(a5 + 8 * a4 + 15) = a2;
  if ( a1 )
    **(_DWORD **)(a3 + 8) &= *(_DWORD *)(a3 - 20);
  JUMPOUT(0x3F020C38);
}

//------------------------------------------------------------------------------
// Address: 0x3F020C39
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _local_unwind2(
        char a1@<zf>,
        char a2@<pf>,
        int a3@<eax>,
        _DWORD *a4@<edx>,
        int a5@<ecx>,
        _DWORD *a6@<ebx>,
        int a7@<ebp>,
        int a8@<edi>,
        int a9@<esi>)
{
  int v9; // ecx
  int v10; // edi
  char v11; // cl
  int v12; // ecx

  if ( !a2 )
  {
    *(_DWORD *)(a5 + 4) = a8;
    *(_DWORD *)(a4[1] + 8) = a4[2];
    if ( !a1 )
    {
      v9 = *(_DWORD *)(a7 - 12) + 8 * a9;
      v10 = *(_DWORD *)(v9 + 4);
      a4[2] = v9;
      a4[1] = v10;
      *(_DWORD *)(v9 + 4) = a4;
      *(_DWORD *)(a4[1] + 8) = a4;
      if ( a4[1] == a4[2] )
      {
        v11 = *(_BYTE *)(a9 + a3 + 4);
        *(_BYTE *)(a7 + 11) = v11;
        *(_BYTE *)(a9 + a3 + 4) = v11 + 1;
        if ( a9 >= 32 )
        {
          if ( *(_BYTE *)(a7 + 11) == 0 )
            JUMPOUT(0x3F020CA8);
          JUMPOUT(0x3F020CB8);
        }
        if ( *(_BYTE *)(a7 + 11) == 0 )
          *a6 |= 0x80000000 >> a9;
        *(_DWORD *)(a3 + 4 * *(_DWORD *)(a7 - 4) + 68) |= 0x80000000 >> a9;
      }
      v12 = *(_DWORD *)(a7 - 8);
      if ( v12 != 0 )
      {
        *a4 = v12;
        *(_DWORD *)((char *)a4 + v12 - 4) = v12;
      }
    }
    JUMPOUT(0x3F020CDD);
  }
  JUMPOUT(0x3F020C3F);
}

//------------------------------------------------------------------------------
// Address: 0x3F020CE0
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _NLG_Notify1(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
  *(_DWORD *)(a2 + a1) = a3 + 1;
  JUMPOUT(0x3F020CE7);
}

//------------------------------------------------------------------------------
// Address: 0x3F020CE9
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _NLG_Notify(char a1@<ah>, void *a2@<ebx>, int a3@<ebp>)
{
  _DWORD *v3; // esi

  BYTE1(a2) ^= a1;
  v3 = *(_DWORD **)(a3 - 12);
  if ( (*v3)++ == 0 && a2 == dword_3F03C9E0 )
    JUMPOUT(0x3F020D04);
  JUMPOUT(0x3F020D13);
}

//------------------------------------------------------------------------------
// Address: 0x3F020D08
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _NLG_Call()
{
  JUMPOUT(0x3F020D0A);
}

//------------------------------------------------------------------------------
// Address: 0x3F020D0B
// Name: __set_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _set_osfhnd@<eax>(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ebp>)
{
  dword_3F03C9E0 = nullptr;
  *a1 = *(_DWORD *)(a3 - 4);
  return a2 + 4;
}

//------------------------------------------------------------------------------
// Address: 0x3F020D65
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x3F020D88
// Name: __free_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _free_osfhnd@<eax>(
        int a1@<ebx>,
        int fh,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  _DWORD *v10; // esi
  int v11; // ebp

  v10 = (_DWORD *)(__security_cookie ^ *(_DWORD *)(a1 + 8));
  HIBYTE(fh) = 0;
  if ( *v10 != -2 )
    __security_check_cookie`...'(StackCookie: *(_DWORD *)(*v10 + a1 + 16) ^ (a1
                                                                           + 16
                                                                           + *(_DWORD *)((__security_cookie
                                                                                        ^ *(_DWORD *)(a1 + 8))
                                                                                       + 4)));
  if ( (*(_BYTE *)(a8 + 4) & 0x66) != 0 )
  {
    if ( *(_DWORD *)(a1 + 12) != -2 )
    {
      _EH4_LocalUnwind::6_0(a1: a1 + 16, a2: &__security_cookie);
      JUMPOUT(0x3F020E2B);
    }
LABEL_13:
    JUMPOUT(0x3F020E4F);
  }
  v11 = *(_DWORD *)(a1 + 12);
  a5 = a8;
  a6 = a10;
  *(_DWORD *)(a1 - 4) = &a5;
  if ( v11 == -2 )
    goto LABEL_13;
  if ( v10[3 * v11 + 5] == 0 )
    JUMPOUT(0x3F020E1D);
  return _get_osfhandle(fh);
}

//------------------------------------------------------------------------------
// Address: 0x3F020E09
// Name: __get_osfhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _get_osfhandle@<eax>(int a1@<edi>, _DWORD *a2@<esi>, _DWORD *fh)
{
  int v3; // eax
  int v5; // [esp-10h] [ebp-10h]
  int v6; // [esp-Ch] [ebp-Ch]

  v3 = _EH4_CallFilterFunc`...'();
  if ( v3 < 0 )
  {
    v6 = 0;
LABEL_4:
    if ( *a2 != -2 )
      __security_check_cookie`...'(StackCookie: *(_DWORD *)(*a2 + a1) ^ (a1 + a2[1]));
    __security_check_cookie`...'(StackCookie: *(_DWORD *)(a2[2] + a1) ^ (a1 + a2[3]));
    return v6;
  }
  if ( v3 <= 0 )
  {
    if ( v5 != -2 )
      JUMPOUT(0x3F020DF1);
    goto LABEL_4;
  }
  if ( *fh != -529697949 || &__DestructExceptionObject_0 == nullptr )
    JUMPOUT(0x3F020E9B);
  return __lock_fhandle((int)fh);
}

//------------------------------------------------------------------------------
// Address: 0x3F020E7A
// Name: ___lock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __lock_fhandle@<eax>(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        _DWORD *a4@<esi>,
        int fh,
        int fha,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        _DWORD *TargetFrame)
{
  _DWORD *v15; // eax
  int (__fastcall *v16)(_DWORD, _DWORD); // esi

  if ( ((int (__cdecl *)(_UNKNOWN **))_IsNonwritableInCurrentImage_0)(a1: &off_3F02FC14) != 0 )
    ((void (__cdecl *)(int, int))__DestructExceptionObject_0)(a1: a14, a2: 1);
  _EH4_GlobalUnwind`...'(TargetFrame);
  v15 = TargetFrame;
  if ( TargetFrame[3] != a2 )
  {
    _EH4_LocalUnwind::6_0(a1: a3, a2: &__security_cookie);
    v15 = TargetFrame;
  }
  v15[3] = a9;
  if ( *a4 != -2 )
    __security_check_cookie`...'(StackCookie: *(_DWORD *)(*a4 + a3) ^ (a3 + a4[1]));
  __security_check_cookie`...'(StackCookie: *(_DWORD *)(a4[2] + a3) ^ (a3 + a4[3]));
  v16 = *(int (__fastcall **)(_DWORD, _DWORD))(a1 + 8);
  _NLG_Notify_0(a1: 1);
  return v16(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F0210EF
// Name: _abort_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort_0()
{
  int v0; // esi
  int v1; // eax
  int v2; // edx
  int v3; // ecx
  unsigned int v4; // kr00_4
  int v5; // [esp-4h] [ebp-88h]
  _DWORD v6[20]; // [esp+4h] [ebp-80h] BYREF
  struct _EXCEPTION_POINTERS ExceptionInfo; // [esp+54h] [ebp-30h] BYREF
  int v8; // [esp+5Ch] [ebp-28h] BYREF
  __int16 v9; // [esp+E8h] [ebp+64h]
  __int16 v10; // [esp+ECh] [ebp+68h]
  __int16 v11; // [esp+F0h] [ebp+6Ch]
  __int16 v12; // [esp+F4h] [ebp+70h]
  int v13; // [esp+FCh] [ebp+78h]
  int v14; // [esp+104h] [ebp+80h]
  int v15; // [esp+108h] [ebp+84h]
  int v16; // [esp+10Ch] [ebp+88h]
  int v17; // [esp+110h] [ebp+8Ch]
  void *v18; // [esp+114h] [ebp+90h]
  __int16 v19; // [esp+118h] [ebp+94h]
  unsigned int v20; // [esp+11Ch] [ebp+98h]
  void **v21; // [esp+120h] [ebp+9Ch]
  __int16 v22; // [esp+124h] [ebp+A0h]
  int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  if ( (dword_3F03BC38 & 1) != 0 )
    ((void (__cdecl *)(int))_NMSG_WRITE_0)(a1: 10);
  v1 = sub_3F022365();
  if ( v1 != 0 )
  {
    v1 = ((int (__cdecl *)(int))error_cleanup_0)(a1: 22);
    v3 = v5;
  }
  if ( (dword_3F03BC38 & 2) != 0 )
  {
    v16 = v1;
    v15 = v3;
    v14 = v2;
    v13 = v0;
    v22 = __SS__;
    v19 = __CS__;
    v12 = __DS__;
    v11 = __ES__;
    v10 = __FS__;
    v9 = __GS__;
    v4 = __readeflags();
    v20 = v4;
    v21 = &retaddr;
    v8 = 65537;
    v18 = retaddr;
    v17 = savedregs;
    memset_0(a1: v6, Val: 0, Size: sizeof(v6));
    ExceptionInfo.ExceptionRecord = (_EXCEPTION_RECORD *)v6;
    v6[0] = 1073741845;
    v6[3] = retaddr;
    ExceptionInfo.ContextRecord = (_CONTEXT *)&v8;
    SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
    UnhandledExceptionFilter(&ExceptionInfo);
  }
  ((void (__cdecl *)(int))loc_3F01B013)(a1: 3);
  __debugbreak();
}

//------------------------------------------------------------------------------
// Address: 0x3F0211E2
// Name: __set_abort_behavior_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior_0(unsigned int Flags, unsigned int Mask)
{
  unsigned int result; // eax

  result = dword_3F03BC38;
  dword_3F03BC38 = Mask & Flags | dword_3F03BC38 & ~Mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F021200
// Name: sub_3F021200
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F021200(int a1)
{
  dword_3F03CD08 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F021280
// Name: _strcmp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcmp_0(const char *Str1, const char *Str2)
{
  if ( ((unsigned __int8)Str1 & 3) != 0 )
    JUMPOUT(0x3F0212CC);
  if ( (unsigned __int8)*(_DWORD *)Str1 != *Str2 )
    JUMPOUT(0x3F0212C4);
  return _set_error_mode(em: (int)Str1);
}

//------------------------------------------------------------------------------
// Address: 0x3F021298
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _set_error_mode@<eax>(char a1@<zf>, unsigned int a2@<eax>, _BYTE *a3@<ecx>)
{
  bool v3; // cf
  unsigned int v4; // eax

  if ( a1 )
    return 0;
  v3 = BYTE1(a2) < a3[1];
  if ( BYTE1(a2) == a3[1] )
  {
    if ( BYTE1(a2) == 0 )
      return 0;
    v4 = HIWORD(a2);
    v3 = (unsigned __int8)v4 < a3[2];
    if ( (_BYTE)v4 != a3[2] )
      return -2 * v3 + 1;
    if ( (_BYTE)v4 == 0 )
      return 0;
    v3 = BYTE1(v4) < a3[3];
    if ( BYTE1(v4) == a3[3] )
    {
      if ( BYTE1(v4) != 0 )
        JUMPOUT(0x3F021290);
      return 0;
    }
  }
  return -2 * v3 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F0212DE
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fptrap(_DWORD *a1@<ecx>, int a2@<ebx>)
{
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h]

  *a1 = __ROL4__(*a1, 10);
  *((_BYTE *)&_loc_update.localeinfo.mbcinfo + 8 * a2 + 3) *= 4;
  JUMPOUT(0x3F0212E8);
}

//------------------------------------------------------------------------------
// Address: 0x3F021336
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall isdigit@<eax>(int a1@<eax>, int a2@<esi>)
{
  if ( a2 == a1 + 1 )
  {
    ++dword_3F03C800;
    if ( (*(_WORD *)(a2 + 12) & 0x10C) == 0 )
    {
      if ( unk_3F03CD18 == 0 )
        JUMPOUT(0x3F02135F);
      JUMPOUT(0x3F02137F);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F021360
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _chkstk(int a1@<ebx>, int *a2@<edi>, int *a3@<esi>)
{
  int v3; // eax
  int v4; // edi
  size_t v5; // [esp-4h] [ebp-4h]

  v3 = _malloc_crt_0(Size: v5);
  *a2 = v3;
  if ( v3 == 0 )
  {
    a3[2] = (int)(a3 + 5);
    *a3 = (int)(a3 + 5);
    a3[6] = 2;
    a3[1] = 2;
    JUMPOUT(0x3F02138C);
  }
  v4 = *a2;
  a3[2] = v4;
  *a3 = v4;
  a3[6] = a1;
  JUMPOUT(0x3F021389);
}

//------------------------------------------------------------------------------
// Address: 0x3F02138B
// Name: __isctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall _isctype_l@<al>(_DWORD *a1@<eax>, int _EBX@<ebx>, int a3@<edi>)
{
  LOBYTE(a1) = ((_BYTE)a1 - 127) | 2;
  *a1 += a1;
  *(_BYTE *)(a3 + 51) += _EBX;
  __asm { rcr     byte ptr [ebx+40h], 5Eh }
  return (char)a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F02139E
// Name: __ftbuf_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftbuf_0(int a1, _DWORD *a2)
{
  int result; // eax

  if ( a1 != 0 && (a2[3] & 0x1000) != 0 )
  {
    result = ((int (__cdecl *)(_DWORD *))_flush_0)(a1: a2);
    a2[3] &= 0xFFFFEEFF;
    a2[6] = 0;
    *a2 = 0;
    a2[2] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0213CD
// Name: _write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall write_char@<eax>(int result@<eax>, int a2@<ecx>, _DWORD *a3@<esi>)
{
  bool v3; // sf

  if ( ((*(_BYTE *)(a2 + 12) & 0x40) == 0 || *(_DWORD *)(a2 + 8) != 0)
    && ((v3 = *(_DWORD *)(a2 + 4) - 1 < 0, --*(_DWORD *)(a2 + 4), v3)
      ? (result = _get_fmode(pMode: (int *)(char)result))
      : (**(_BYTE **)a2 = result, ++*(_DWORD *)a2, result = (unsigned __int8)result),
        result == -1) )
  {
    *a3 = -1;
  }
  else
  {
    ++*a3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F021400
// Name: _write_multi_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall write_multi_char@<eax>(int result@<eax>, char a2, int a3, int a4)
{
  _DWORD *v4; // esi

  v4 = (_DWORD *)result;
  do
  {
    if ( a3 <= 0 )
      break;
    LOBYTE(result) = a2;
    --a3;
    result = write_char(result, a2: a4, a3: v4);
  }
  while ( *v4 != -1 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F021424
// Name: _write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(_DWORD *a1@<eax>, int a2@<edi>, int a3)
{
  if ( (*(_BYTE *)(a2 + 12) & 0x40) != 0 && *(_DWORD *)(a2 + 8) == 0 )
  {
    *a1 += a3;
    JUMPOUT(0x3F02146B);
  }
  JUMPOUT(0x3F021464);
}

//------------------------------------------------------------------------------
// Address: 0x3F021441
// Name: __calloc_impl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int *__usercall _calloc_impl@<eax>(int a1@<eax>, int a2@<edi>, _DWORD *a3@<esi>, signed int num)
{
  int *result; // eax

  LOBYTE(a1) = a1 & 0xC;
  result = (int *)write_char(result: a1, a2, a3);
  if ( *a3 == -1 )
  {
    result = _errno_0();
    if ( *result != 42 )
      return result;
    LOBYTE(result) = 63;
    result = (int *)write_char((int)result, a2, a3);
  }
  if ( num > 0 )
    JUMPOUT(0x3F021440);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02146E
// Name: __output_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _output_l_0(int a1, int a2, int a3, int a4)
{
  _BYTE v4[20]; // [esp+28h] [ebp-64h] BYREF
  int v5; // [esp+3Ch] [ebp-50h]
  int v6; // [esp+40h] [ebp-4Ch]
  int v7; // [esp+48h] [ebp-44h]
  int v8; // [esp+4Ch] [ebp-40h]
  int v9; // [esp+50h] [ebp-3Ch]
  int v10; // [esp+5Ch] [ebp-30h]
  int v11; // [esp+60h] [ebp-2Ch]
  int v12; // [esp+6Ch] [ebp-20h]
  int v13; // [esp+74h] [ebp-18h]

  v10 = a1;
  v11 = a4;
  v6 = 0;
  v13 = 0;
  v8 = 0;
  v12 = 0;
  v9 = 0;
  v5 = 0;
  v7 = 0;
  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v4, a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F021570
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getenv_helper_nolock()
{
  JUMPOUT(0x3F021571);
}

//------------------------------------------------------------------------------
// Address: 0x3F0215F1
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall strtoxl@<eax>(
        int a1@<eax>,
        unsigned __int8 a2@<dl>,
        int a3@<ecx>,
        char *a4@<ebx>,
        int a5@<ebp>,
        int a6@<edi>,
        int a7@<esi>,
        localeinfo_struct *plocinfo,
        char **nptr,
        const char **endptr)
{
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  char v15; // al
  bool v16; // zf
  int v17; // eax

  v10 = byte_3F02FAC8[8 * a1 + a3] >> 4;
  *(_DWORD *)(a5 - 116) = v10;
  switch ( v10 )
  {
    case 0:
      goto $NORMAL_STATE$25388;
    case 1:
      *(_DWORD *)(a5 - 32) = -1;
      *(_DWORD *)(a5 - 120) = a7;
      *(_DWORD *)(a5 - 80) = a7;
      *(_DWORD *)(a5 - 64) = a7;
      *(_DWORD *)(a5 - 60) = a7;
      *(_DWORD *)(a5 - 24) = a7;
      *(_DWORD *)(a5 - 68) = a7;
      goto LABEL_55;
    case 2:
      switch ( a2 )
      {
        case ' ':
          *(_DWORD *)(a5 - 24) |= 2u;
          break;
        case '#':
          *(_DWORD *)(a5 - 24) |= 0x80u;
          break;
        case '+':
          *(_DWORD *)(a5 - 24) |= 1u;
          break;
        case '-':
          *(_DWORD *)(a5 - 24) |= 4u;
          break;
        case '0':
          *(_DWORD *)(a5 - 24) |= 8u;
          break;
        default:
          break;
      }
      goto LABEL_55;
    case 3:
      if ( a2 == 42 )
      {
        v11 = a6 + 4;
        *(_DWORD *)(a5 - 44) = v11;
        v12 = *(_DWORD *)(v11 - 4);
        *(_DWORD *)(a5 - 64) = v12;
        if ( v12 < a7 )
        {
          *(_DWORD *)(a5 - 24) |= 4u;
          *(_DWORD *)(a5 - 64) = -*(_DWORD *)(a5 - 64);
        }
      }
      else
      {
        *(_DWORD *)(a5 - 64) = 10 * *(_DWORD *)(a5 - 64) + (char)a2 - 48;
      }
      goto LABEL_55;
    case 4:
      *(_DWORD *)(a5 - 32) = a7;
      goto LABEL_55;
    case 5:
      if ( a2 == 42 )
      {
        v13 = a6 + 4;
        *(_DWORD *)(a5 - 44) = v13;
        v14 = *(_DWORD *)(v13 - 4);
        *(_DWORD *)(a5 - 32) = v14;
        if ( v14 < a7 )
          *(_DWORD *)(a5 - 32) = -1;
      }
      else
      {
        *(_DWORD *)(a5 - 32) = 10 * *(_DWORD *)(a5 - 32) + (char)a2 - 48;
      }
      goto LABEL_55;
    case 6:
      switch ( a2 )
      {
        case 'I':
          v15 = *a4;
          if ( *a4 == 54 && a4[1] == 52 )
          {
            *(_DWORD *)(a5 - 24) |= 0x8000u;
            *(_DWORD *)(a5 - 72) = a4 + 2;
          }
          else if ( v15 == 51 && a4[1] == 50 )
          {
            *(_DWORD *)(a5 - 24) &= ~0x8000u;
            *(_DWORD *)(a5 - 72) = a4 + 2;
          }
          else if ( v15 != 100 && v15 != 105 && v15 != 111 && v15 != 117 && v15 != 120 && v15 != 88 )
          {
            *(_DWORD *)(a5 - 116) = a7;
$NORMAL_STATE$25388:
            *(_DWORD *)(a5 - 68) = a7;
            v17 = ((int (__cdecl *)(_DWORD))loc_3F022F5E)(a1: a2);
            v16 = v17 == 0;
            LOBYTE(v17) = *(_BYTE *)(a5 - 25);
            if ( !v16 )
            {
              v17 = write_char(result: v17, a2: *(_DWORD *)(a5 - 48), a3: (_DWORD *)(a5 - 52));
              LOBYTE(v17) = *a4;
              *(_DWORD *)(a5 - 72) = a4 + 1;
              if ( (_BYTE)v17 == 0 )
                JUMPOUT(0x3F021DA3);
            }
            write_char(result: v17, a2: *(_DWORD *)(a5 - 48), a3: (_DWORD *)(a5 - 52));
          }
          break;
        case 'h':
          *(_DWORD *)(a5 - 24) |= 0x20u;
          break;
        case 'l':
          if ( *a4 == 108 )
          {
            *(_DWORD *)(a5 - 24) |= 0x1000u;
            *(_DWORD *)(a5 - 72) = a4 + 1;
          }
          else
          {
            *(_DWORD *)(a5 - 24) |= 0x10u;
          }
          break;
        case 'w':
          *(_DWORD *)(a5 - 24) |= 0x800u;
          break;
        default:
          break;
      }
LABEL_55:
      JUMPOUT(0x3F021D8A);
    case 7:
      if ( (char)a2 > 100 )
        JUMPOUT(0x3F021970);
      if ( a2 == 100 )
        JUMPOUT(0x3F0219EF);
      if ( (char)a2 > 83 )
        JUMPOUT(0x3F0218B8);
      if ( a2 == 83 )
        JUMPOUT(0x3F021869);
      if ( a2 != 65 )
      {
        if ( a2 == 67 )
          JUMPOUT(0x3F021858);
        if ( a2 != 69 )
          return strtol(nptr: (const char *)plocinfo, endptr: nptr, ibase: (int)endptr);
      }
      JUMPOUT(0x3F021824);
    default:
      goto LABEL_55;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F02181C
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strtol(int a1@<eax>, char a2@<dl>, int a3@<ebp>)
{
  if ( a1 == 2 )
  {
    *(_DWORD *)(a3 - 120) = 1;
    *(_BYTE *)(a3 - 25) = a2 + 32;
    *(_DWORD *)(a3 - 24) |= 0x40u;
    *(_DWORD *)(a3 - 36) = a3 - 20;
    JUMPOUT(0x3F021843);
  }
  JUMPOUT(0x3F021C72);
}

//------------------------------------------------------------------------------
// Address: 0x3F021845
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _putwch_nolock(char a1@<sf>, char a2@<of>, int a3@<ebp>)
{
  if ( a1 != a2 )
  {
    *(_DWORD *)(a3 - 32) = 6;
    JUMPOUT(0x3F021A61);
  }
  JUMPOUT(0x3F021A13);
}

//------------------------------------------------------------------------------
// Address: 0x3F021907
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbtowc_l(unsigned __int16 a1@<dx>, int a2@<ebp>)
{
  int v2; // ebp

  v2 = a2 + 1;
  __inbyte(a1);
  *(_DWORD *)(v2 - 40) = 1;
  *(_DWORD *)(v2 - 36) = v2 - 20;
  JUMPOUT(0x3F021C72);
}

//------------------------------------------------------------------------------
// Address: 0x3F021A1A
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall mbtowc(int a1@<ebp>)
{
  *(_DWORD *)(a1 - 32) = 1;
  JUMPOUT(0x3F021A61);
}

//------------------------------------------------------------------------------
// Address: 0x3F021A31
// Name: x_ismbbtype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall x_ismbbtype_l(char a1@<bh>, int a2@<ebp>, int *a3@<edi>, int a4@<esi>)
{
  size_t v4; // esi
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // edi

  *(_BYTE *)(a4 + 45) += a1;
  v4 = *(_DWORD *)(a2 - 32) + 349;
  v5 = _malloc_crt_0(Size: v4);
  *(_DWORD *)(a2 - 84) = v5;
  if ( v5 != 0 )
  {
    *(_DWORD *)(a2 - 36) = v5;
    *(_DWORD *)(a2 - 104) = v4;
  }
  else
  {
    *(_DWORD *)(a2 - 32) = 163;
  }
  v6 = *a3;
  v7 = a3 + 2;
  *(_DWORD *)(a2 - 128) = v6;
  *(_DWORD *)(a2 - 124) = *(v7 - 1);
  *(_DWORD *)(a2 - 44) = v7;
  JUMPOUT(0x3F021A80);
}

//------------------------------------------------------------------------------
// Address: 0x3F021A82
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ismbblead()
{
  ((void (__cdecl *)(int (*)()))_decode_pointer)(a1: off_3F03BC68[0]);
  JUMPOUT(0x3F021A94);
}

//------------------------------------------------------------------------------
// Address: 0x3F021A95
// Name: int _ValidateRead(void const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ValidateRead(unsigned int a1@<eax>, int a2@<ebx>)
{
  char v2; // cf

  v2 = *(_BYTE *)(a2 - 997988227) & 1;
  *(_BYTE *)(a2 - 997988227) = __ROR1__(*(_BYTE *)(a2 - 997988227), 1);
  LOBYTE(a1) = a1 - (v2 - 127);
  __outdword(0x80u, a1);
  JUMPOUT(0x3F021A9F);
}

//------------------------------------------------------------------------------
// Address: 0x3F021AA2
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _strnicmp_l(char a1@<zf>, _BYTE *a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5@<esi>)
{
  void (*v5)(void); // eax
  void (*v6)(void); // eax

  if ( !a1 && *(_DWORD *)(a3 - 32) == a5 )
  {
    v5 = (void (*)(void))((int (__cdecl *)(int (*)()))_decode_pointer)(a1: off_3F03BC74);
    v5();
  }
  if ( *(_BYTE *)(a3 - 25) == 103 && a4 == a5 )
  {
    v6 = (void (*)(void))((int (__cdecl *)(int (*)()))_decode_pointer)(a1: off_3F03BC70[0]);
    v6();
  }
  if ( *a2 == 45 )
  {
    *(_DWORD *)(a3 - 24) |= 0x100u;
    *(_DWORD *)(a3 - 36) = a2 + 1;
  }
  JUMPOUT(0x3F021965);
}

//------------------------------------------------------------------------------
// Address: 0x3F021B92
// Name: __chsize_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _chsize_nolock(char a1@<cf>, int a2@<eax>, int a3@<edx>, int a4@<ebp>)
{
  int v4; // ebx
  int v5; // edi
  _BYTE *i; // esi
  int v7; // eax
  __int64 v8; // rax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  _BYTE *v12; // esi
  bool v13; // zf
  int v14; // eax
  int v15; // ebx
  int v16; // edi
  int v17; // eax
  unsigned __int16 *v18; // esi
  int v19; // eax

  *(_DWORD *)(a4 - 24) |= 0x100u;
  v4 = -(a1 + a3);
  v5 = a2;
  if ( (*(_WORD *)(a4 - 24) & 0x9000) == 0 )
    v4 = 0;
  if ( *(int *)(a4 - 32) >= 0 )
  {
    *(_DWORD *)(a4 - 24) &= ~8u;
    if ( *(int *)(a4 - 32) > 512 )
      *(_DWORD *)(a4 - 32) = 512;
  }
  else
  {
    *(_DWORD *)(a4 - 32) = 1;
  }
  if ( (v4 | a2) == 0 )
    *(_DWORD *)(a4 - 60) = 0;
  for ( i = (_BYTE *)(a4 + 491); ; --i )
  {
    v7 = *(_DWORD *)(a4 - 32);
    *(_DWORD *)(a4 - 32) = v7 - 1;
    if ( v7 <= 0 && (v4 | v5) == 0 )
      break;
    v8 = ((__int64 (__stdcall *)(int, int, _DWORD, int))&__newclmap[344])(
           a1: v5,
           a2: v4,
           a3: *(_DWORD *)(a4 - 40),
           a4: *(int *)(a4 - 40) >> 31);
    v10 = v9 + 48;
    *(_DWORD *)(a4 - 104) = v4;
    v4 = HIDWORD(v8);
    v5 = v8;
    if ( v10 > 57 )
      v10 += *(_DWORD *)(a4 - 76);
    *i = v10;
  }
  v11 = a4 + 491 - (_DWORD)i;
  v12 = i + 1;
  v13 = (*(_WORD *)(a4 - 24) & 0x200) == 0;
  *(_DWORD *)(a4 - 40) = v11;
  *(_DWORD *)(a4 - 36) = v12;
  if ( !v13 && (v11 == 0 || *v12 != 48) )
  {
    *(_BYTE *)--*(_DWORD *)(a4 - 36) = 48;
    *(_DWORD *)(a4 - 40) = v11 + 1;
  }
  if ( *(_DWORD *)(a4 - 80) != 0 )
    JUMPOUT(0x3F021D77);
  v14 = *(_DWORD *)(a4 - 24);
  if ( (v14 & 0x40) != 0 )
  {
    if ( (v14 & 0x100) != 0 )
    {
      *(_BYTE *)(a4 - 56) = 45;
    }
    else if ( (v14 & 1) != 0 )
    {
      *(_BYTE *)(a4 - 56) = 43;
    }
    else
    {
      if ( (v14 & 2) == 0 )
        goto LABEL_28;
      *(_BYTE *)(a4 - 56) = 32;
    }
    *(_DWORD *)(a4 - 60) = 1;
  }
LABEL_28:
  v15 = *(_DWORD *)(a4 - 64) - *(_DWORD *)(a4 - 40) - *(_DWORD *)(a4 - 60);
  if ( (*(_BYTE *)(a4 - 24) & 0xC) == 0 )
    write_multi_char(result: a4 - 52, a2: 32, a3: v15, a4: *(_DWORD *)(a4 - 48));
  v16 = *(_DWORD *)(a4 - 48);
  write_string(a1: (_DWORD *)(a4 - 52), a2: v16, a3: *(_DWORD *)(a4 - 60));
  if ( (*(_BYTE *)(a4 - 24) & 8) != 0 && (*(_BYTE *)(a4 - 24) & 4) == 0 )
    write_multi_char(result: a4 - 52, a2: 48, a3: v15, a4: v16);
  v17 = *(_DWORD *)(a4 - 40);
  if ( *(_DWORD *)(a4 - 68) != 0 && v17 > 0 )
  {
    v18 = *(unsigned __int16 **)(a4 - 36);
    *(_DWORD *)(a4 - 104) = v17;
    v19 = *v18;
    --*(_DWORD *)(a4 - 104);
    if ( ((int (__cdecl *)(int, int, int, int))&__newclmap[310])(a1: a4 - 112, a2: a4 + 492, a3: 6, a4: v19) == 0
      && *(_DWORD *)(a4 - 112) != 0 )
    {
      write_string(a1: (_DWORD *)(a4 - 52), a2: v16, a3: *(_DWORD *)(a4 - 112));
      JUMPOUT(0x3F021D45);
    }
    JUMPOUT(0x3F021D49);
  }
  JUMPOUT(0x3F021D4F);
}

//------------------------------------------------------------------------------
// Address: 0x3F021D46
// Name: __setmode_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _setmode_nolock(unsigned int a1@<ebx>, int a2@<ebp>, int a3@<edi>)
{
  int v3; // ebx
  char v4; // al

  v3 = a1 >> 19;
  *(_DWORD *)(a2 - 52) = -1;
  if ( *(int *)(a2 - 52) >= 0 && (*(_BYTE *)(a2 - 24) & 4) != 0 )
    write_multi_char(result: a2 - 52, a2: 32, a3: v3, a4: a3);
  if ( *(_DWORD *)(a2 - 84) != 0 )
  {
    free(Block: *(void **)(a2 - 84));
    *(_DWORD *)(a2 - 84) = 0;
  }
  v4 = **(_BYTE **)(a2 - 72);
  *(_BYTE *)(a2 - 25) = v4;
  if ( v4 != 0 )
    JUMPOUT(0x3F0215CC);
  if ( *(_BYTE *)(a2 - 88) != 0 )
    *(_DWORD *)(*(_DWORD *)(a2 - 92) + 112) &= ~2u;
  __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 + 500));
}

//------------------------------------------------------------------------------
// Address: 0x3F021E02
// Name: __get_fmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _get_fmode(int *pMode, int a2)
{
  int v2; // eax

  ((void (__cdecl *)(int))loc_3F022F31)(a1: a2);
  v2 = *(_DWORD *)(a2 + 12);
  if ( (v2 & 0x82) == 0 )
  {
    *_errno_0() = 9;
    *(_DWORD *)(a2 + 12) |= 0x20u;
    JUMPOUT(0x3F021F5F);
  }
  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x3F021E36);
  JUMPOUT(0x3F021E43);
}

//------------------------------------------------------------------------------
// Address: 0x3F021E40
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _allmul(int a1@<eax>, int a2@<ecx>, _DWORD *a3@<esi>)
{
  if ( a2 != 0 )
  {
    if ( (a1 & 1) != 0 )
    {
      a3[1] = 0;
      if ( (a1 & 0x10) == 0 )
        JUMPOUT(0x3F021EDA);
      *a3 = a3[2];
      a3[3] = a1 & 0xFFFFFFFE;
    }
    a3[3] = a3[3] & 0xFFFFFFED | 2;
    a3[1] = 0;
    JUMPOUT(0x3F021E73);
  }
  JUMPOUT(0x3F021E97);
}

//------------------------------------------------------------------------------
// Address: 0x3F021E74
// Name: __mbsnbicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F021F62
// Name: sub_3F021F62
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F021F62()
{
  JUMPOUT(0x3F021F83);
}

//------------------------------------------------------------------------------
// Address: 0x3F021F77
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall __wtomb_environ@<eax>(int result@<eax>, int a2@<edx>, unsigned int a3@<edi>, int a4@<esi>)
{
  *(_BYTE *)(a2 + result - 1) = 0;
  if ( a4 + 4 < a3 )
    JUMPOUT(0x3F021F76);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F021FD0
// Name: __ValidateImageBase_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase_0(int a1)
{
  int v2; // eax

  return *(_WORD *)a1 == 23117 && *(_DWORD *)(v2 = a1 + *(_DWORD *)(a1 + 60)) == 17744 && *(_WORD *)(v2 + 24) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x3F02200C
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __initconout(char a1@<cf>, int a2@<eax>, int a3@<ecx>, int a4, int a5, unsigned int a6)
{
  int v6; // eax

  LOBYTE(a2) = a1 + a2 + 83;
  v6 = a2 + a3 + 24;
  if ( *(_WORD *)(a3 + 6) != 0 )
  {
    if ( a6 >= *(_DWORD *)(v6 + 12) )
      JUMPOUT(0x3F022029);
    JUMPOUT(0x3F022032);
  }
  JUMPOUT(0x3F02203C);
}

//------------------------------------------------------------------------------
// Address: 0x3F02202B
// Name: ___termcon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall __termcon@<eax>(char a1@<al>, int a2@<edx>, _BYTE *a3@<ebx>, unsigned int a4@<esi>)
{
  *a3 |= a1;
  _enable();
  if ( a2 + 1 < a4 )
    JUMPOUT(0x3F022022);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F022060
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __ascii_strnicmp(int a1@<ebp>)
{
  uintptr_t v1; // eax
  _DWORD v2[7]; // [esp-1Ch] [ebp-1Ch] BYREF

  v2[6] = MEMORY[0];
  v1 = __security_cookie;
  *(_DWORD *)(a1 - 8) ^= __security_cookie;
  v2[0] = a1 ^ v1;
  *(_DWORD *)(a1 - 24) = v2;
  *(_DWORD *)(a1 - 4) = 0;
  if ( _ValidateImageBase_0(a1: 1056964608)
    && ((int (__cdecl *)(int, int))_FindPESection_0)(a1: 1056964608, a2: *(_DWORD *)(a1 + 8) - 1056964608) != 0 )
  {
    JUMPOUT(0x3F0220C0);
  }
  *(_DWORD *)(a1 - 4) = -2;
}

//------------------------------------------------------------------------------
// Address: 0x3F0220D8
// Name: nullsub_11
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_11()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0220ED
// Name: sub_3F0220ED
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F0220ED()
{
  JUMPOUT(0x3F0220F0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02210B
// Name: _dynamic_initializer_for__g_VCRThreadSafeInitter___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn dynamic_initializer_for__g_VCRThreadSafeInitter___0()
{
  void (*v0)(void); // eax

  v0 = *(void (**)(void))(_getptd_0() + 120);
  if ( v0 != nullptr )
    v0();
  abort_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F022144
// Name: ?unexpected@@YAXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn unexpected()
{
  void (*v0)(void); // eax

  v0 = *(void (**)(void))(_getptd_0() + 124);
  if ( v0 != nullptr )
    v0();
  dynamic_initializer_for__g_VCRThreadSafeInitter___0();
}

//------------------------------------------------------------------------------
// Address: 0x3F022157
// Name: ?_inconsistency@@YAXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _inconsistency()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F03CD1C);
  if ( v0 != nullptr )
    v0();
  dynamic_initializer_for__g_VCRThreadSafeInitter___0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02218E
// Name: sub_3F02218E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02218E()
{
  int result; // eax

  result = ((int (__cdecl *)(void (__noreturn *)(void)))_encode_pointer)(a1: dynamic_initializer_for__g_VCRThreadSafeInitter___0);
  dword_3F03CD1C = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02219F
// Name: __XcptFilter_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _XcptFilter_0(int a1, int a2)
{
  int result; // eax
  _DWORD *v3; // esi
  int *v4; // edx
  int *v5; // ecx
  int *v6; // eax
  void (__cdecl *v7)(int); // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // [esp+4h] [ebp-8h]

  result = ((int (*)(void))loc_3F01F7D3)();
  v3 = (_DWORD *)result;
  if ( result != 0 )
  {
    v4 = *(int **)(result + 92);
    v5 = v4;
    do
    {
      if ( *v5 == a1 )
        break;
      v5 += 3;
    }
    while ( v5 < &v4[3 * dword_3F03BCFC] );
    if ( v5 < &v4[3 * dword_3F03BCFC] && *v5 == a1 )
      v6 = v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr && (v7 = (void (__cdecl *)(int))v6[2]) != nullptr )
    {
      if ( v7 == (void (__cdecl *)(int))5 )
      {
        v6[2] = 0;
        return 1;
      }
      else
      {
        if ( v7 != (void (__cdecl *)(int))1 )
        {
          v13 = v3[24];
          v3[24] = a2;
          v8 = v6[1];
          if ( v8 == 8 )
          {
            v9 = dword_3F03BCF0;
            if ( dword_3F03BCF0 < dword_3F03BCF0 + dword_3F03BCF4 )
            {
              v10 = 12 * dword_3F03BCF0;
              do
              {
                *(_DWORD *)(v10 + v3[23] + 8) = 0;
                ++v9;
                v10 += 12;
              }
              while ( v9 < dword_3F03BCF0 + dword_3F03BCF4 );
            }
            v11 = *v6;
            v12 = v3[25];
            switch ( v11 )
            {
              case -1073741682:
                v3[25] = 131;
                break;
              case -1073741680:
                v3[25] = 129;
                break;
              case -1073741679:
                v3[25] = 132;
                break;
              case -1073741677:
                v3[25] = 133;
                break;
              case -1073741683:
                v3[25] = 130;
                break;
              case -1073741681:
                v3[25] = 134;
                break;
              case -1073741678:
                v3[25] = 138;
                break;
              default:
                break;
            }
            v7(a1: 8);
            v3[25] = v12;
          }
          else
          {
            v6[2] = 0;
            v7(a1: v8);
          }
          v3[24] = v13;
        }
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0222FD
// Name: ___CppXcptFilter_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __CppXcptFilter_0(int a1, int a2)
{
  if ( a1 == -529697949 )
    return _XcptFilter_0(a1: -529697949, a2);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F022318
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initp_misc_winsig(int a1)
{
  dword_3F03CD20 = a1;
  dword_3F03CD24 = a1;
  dword_3F03CD28 = a1;
  dword_3F03CD2C = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F022331
// Name: _siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall siglookup@<eax>(int a1@<edx>, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  do
  {
    if ( *(_DWORD *)(result + 4) == a1 )
      break;
    result += 12;
  }
  while ( result < a2 + 12 * dword_3F03BCFC );
  if ( result >= a2 + 12 * dword_3F03BCFC || *(_DWORD *)(result + 4) != a1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F022365
// Name: sub_3F022365
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F022365()
{
  return ((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F03CD28);
}

//------------------------------------------------------------------------------
// Address: 0x3F02244A
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCompareStringA()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F02248A
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _strnicoll_l@<eax>(int a1@<eax>, int a2@<ebx>, int a3@<ebp>, _DWORD *a4@<edi>)
{
  *(_BYTE *)(a2 + 779421947) += a1;
  for ( *(_DWORD *)(a3 - 36) = dword_3F03BCF0;
        *(_DWORD *)(a3 - 36) < dword_3F03BCF0 + dword_3F03BCF4;
        ++*(_DWORD *)(a3 - 36) )
  {
    *(_DWORD *)(12 * *(_DWORD *)(a3 - 36) + a4[23] + 8) = a1;
  }
  *(_DWORD *)(a3 - 4) = -2;
  sub_3F0224E6();
  if ( a2 == 8 )
    (*(void (__cdecl **)(int, _DWORD))(a3 - 32))(a1: 8, a2: a4[25]);
  else
    (*(void (__cdecl **)(int))(a3 - 32))(a1: a2);
  if ( a2 == 8 || a2 == 11 || a2 == 4 )
  {
    a4[24] = *(_DWORD *)(a3 - 44);
    if ( a2 == 8 )
      a4[25] = *(_DWORD *)(a3 - 48);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0224E0
// Name: sub_3F0224E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F0224E0()
{
  return sub_3F0224E6();
}

//------------------------------------------------------------------------------
// Address: 0x3F0224E6
// Name: sub_3F0224E6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F0224E6@<eax>(int a1@<ebp>)
{
  int result; // eax

  if ( *(_DWORD *)(a1 - 28) != 0 )
    return ((int (__cdecl *)(_DWORD))loc_3F020118)(a1: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F022522
// Name: sub_3F022522
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F022522(int a1)
{
  dword_3F03CD34 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F02252C
// Name: sub_3F02252C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F02252C(int a1)
{
  dword_3F03CD38 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F022536
// Name: __crtInitCritSecNoSpinCount(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall __crtInitCritSecNoSpinCount(LPCRITICAL_SECTION lpCriticalSection, int a2)
{
  InitializeCriticalSection(lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F022546
// Name: ___crtInitCritSecAndSpinCount_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __crtInitCritSecAndSpinCount_0()
{
  int v0; // [esp+18h] [ebp-1Ch] BYREF

  v0 = 0;
  if ( ((int (__cdecl *)(int))_decode_pointer)(a1: dword_3F03CD38) == 0 )
  {
    if ( ((int (__cdecl *)(int *))loc_3F01AE1B)(a1: &v0) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    JUMPOUT(0x3F022584);
  }
  JUMPOUT(0x3F0225BC);
}

//------------------------------------------------------------------------------
// Address: 0x3F022582
// Name: findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall findenv(_DWORD *len@<edi>, char a2@<sf>, char a3@<of>, int a4@<ecx>, int a5@<ebp>, int a6@<esi>)
{
  BOOL (__stdcall *v6)(LPCRITICAL_SECTION, DWORD); // edi
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION, DWORD); // esi

  if ( a2 != a3 )
  {
    *(_DWORD *)(a4 + 104) += a6;
    v6 = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))((char *)len + *len);
    ModuleHandleA = GetModuleHandleA(lpModuleName: (LPCSTR)(unsigned __int16)__SS__);
    if ( ModuleHandleA == (HMODULE)v6
      || (InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))GetProcAddress(
                                                                                                   hModule: ModuleHandleA,
                                                                                                   lpProcName: "InitializeCriticalSec"
                                                                                                   "tionAndSpinCount")) == v6 )
    {
      InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))__crtInitCritSecNoSpinCount;
    }
    dword_3F03CD38 = ((int (__cdecl *)(BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD)))_encode_pointer)(a1: InitializeCriticalSectionAndSpinCount);
    *(_DWORD *)(a5 - 4) = v6;
    *(_DWORD *)(a5 - 32) = InitializeCriticalSectionAndSpinCount(
                             lpCriticalSection: *(LPCRITICAL_SECTION *)(a5 + 8),
                             dwSpinCount: *(_DWORD *)(a5 + 12));
    JUMPOUT(0x3F0225FB);
  }
  JUMPOUT(0x3F02256B);
}

//------------------------------------------------------------------------------
// Address: 0x3F0225CF
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall copy_environ@<eax>(int **a1@<eax>, int a2@<ebp>)
{
  int v3; // eax

  v3 = **a1;
  *(_DWORD *)(a2 - 36) = v3;
  return (char **)(v3 == -1073741801);
}

//------------------------------------------------------------------------------
// Address: 0x3F02262C
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __crtsetenv(int a1@<ecx>, int a2@<edi>, const __m128i *a3@<esi>, __int128 a4@<xmm0>)
{
  __m128i si128; // xmm1
  __m128i v5; // xmm2
  __m128i v6; // xmm3
  __m128i v7; // xmm5
  __m128i v8; // xmm6
  __m128i v9; // xmm7

  si128 = _mm_load_si128(a3 + 1);
  v5 = _mm_load_si128(a3 + 2);
  v6 = _mm_load_si128(a3 + 3);
  *(_OWORD *)a2 = a4;
  *(__m128i *)(a2 + 16) = si128;
  *(__m128i *)(a2 + 32) = v5;
  *(__m128i *)(a2 + 48) = v6;
  v7 = _mm_load_si128(a3 + 5);
  v8 = _mm_load_si128(a3 + 6);
  v9 = _mm_load_si128(a3 + 7);
  *(__m128i *)(a2 + 64) = _mm_load_si128(a3 + 4);
  *(__m128i *)(a2 + 80) = v7;
  *(__m128i *)(a2 + 96) = v8;
  *(__m128i *)(a2 + 112) = v9;
  if ( a1 != 1 )
    JUMPOUT(0x3F02262B);
}

//------------------------------------------------------------------------------
// Address: 0x3F022692
// Name: __mbschr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _mbschr_0(const unsigned __int8 *Str, unsigned int C)
{
  int v2; // ecx
  unsigned __int8 *result; // eax
  int v4; // ecx
  unsigned int v5; // [esp+4h] [ebp-18h]
  unsigned int v6; // [esp+2Ch] [ebp+10h]

  v2 = (int)C % 16;
  result = (unsigned __int8 *)Str;
  if ( (((int)Str % 16) | ((int)C % 16)) != 0 )
  {
    if ( v2 == (int)Str % 16 )
    {
      qmemcpy((void *)Str, (const void *)C, 16 - v2);
      _mbschr_0(Str: &Str[16 - v2], C: 16 - v2 + C);
    }
    else
    {
      qmemcpy((void *)Str, (const void *)C, v6);
    }
    return (unsigned __int8 *)Str;
  }
  else
  {
    v4 = v6 & 0x7F;
    v5 = v4;
    if ( v6 != v4 )
    {
      ((void (__cdecl *)(const unsigned __int8 *, unsigned int, unsigned int))fastcopy_I)(a1: Str, a2: C, a3: v6 - v4);
      result = (unsigned __int8 *)Str;
      v4 = v5;
    }
    if ( v4 != 0 )
    {
      qmemcpy(&result[v6 - v4], (const void *)(v6 + C - v4), v5);
      return (unsigned __int8 *)Str;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F022775
// Name: __sse2_mathfcns_init_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _sse2_mathfcns_init_0()
{
  dword_3F0A3880 = 0;
  dword_3F0A3880 = _get_sse2_info_0();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F022789
// Name: _strcpy_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl strcpy_s_0(char *Destination, rsize_t SizeInBytes, const char *Source)
{
  rsize_t v3; // edi
  errno_t v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // al

  if ( Destination == nullptr )
    goto LABEL_3;
  v3 = SizeInBytes;
  if ( SizeInBytes == 0 )
    goto LABEL_3;
  v6 = Source;
  if ( Source == nullptr )
  {
    *Destination = 0;
LABEL_3:
    v4 = 22;
    *_errno_0() = 22;
LABEL_4:
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return v4;
  }
  v7 = Destination;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  if ( v3 == 0 )
  {
    *Destination = 0;
    *_errno_0() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0227F0
// Name: ___alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __alloca_probe_16()
{
  return _alloca_probe();
}

//------------------------------------------------------------------------------
// Address: 0x3F022806
// Name: __alloca_probe_8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _alloca_probe_8()
{
  return _alloca_probe();
}

//------------------------------------------------------------------------------
// Address: 0x3F02281C
// Name: __malloc_crt_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _malloc_crt_0(size_t Size)
{
  DWORD v1; // esi
  void *v2; // edi
  int v3; // eax

  v1 = 0;
  do
  {
    v2 = malloc_0(Size);
    if ( v2 != nullptr || dword_3F03CD3C == 0 )
      break;
    Sleep(dwMilliseconds: v1);
    v3 = v1 + 1000;
    if ( v1 + 1000 > dword_3F03CD3C )
      v3 = -1;
    v1 = v3;
  }
  while ( v3 != -1 );
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F02285C
// Name: __calloc_crt_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _calloc_crt_0(const char *Size, int a2)
{
  if ( _calloc_impl_0((size_t)Size, a2, a3: 0) != 0 )
    JUMPOUT(0x3F02289F);
  return _strdup(string: Size);
}

//------------------------------------------------------------------------------
// Address: 0x3F022878
// Name: __strdup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall _strdup@<eax>(unsigned int a1@<eax>, int a2@<edi>, DWORD a3@<esi>)
{
  int v3; // eax

  if ( dword_3F03CD3C > a1 )
  {
    Sleep(dwMilliseconds: a3);
    v3 = a3 + 1000;
    if ( a3 + 1000 > dword_3F03CD3C )
      v3 = -1;
    if ( v3 != -1 )
      JUMPOUT(0x3F022860);
  }
  return (char *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F0228C8
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const unsigned __int8 *__usercall _mbschr_l@<eax>(
        char a1@<cf>,
        char a2@<zf>,
        int _EAX@<eax>,
        int a4@<edi>,
        DWORD a5@<esi>)
{
  int v6; // eax

  __asm { aas }
  if ( !(a1 | a2) )
  {
    Sleep(dwMilliseconds: a5);
    v6 = a5 + 1000;
    if ( a5 + 1000 > dword_3F03CD3C )
      v6 = -1;
    if ( v6 != -1 )
      JUMPOUT(0x3F0228A8);
  }
  return (const unsigned __int8 *)a4;
}

//------------------------------------------------------------------------------
// Address: 0x3F0228EF
// Name: __recalloc_crt_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _recalloc_crt_0(void *Block, size_t Count, size_t Size)
{
  DWORD v3; // esi
  void *v4; // edi
  int v5; // eax

  v3 = 0;
  do
  {
    v4 = _recalloc_0(Block, Count, Size);
    if ( v4 != nullptr || Size == 0 || dword_3F03CD3C == 0 )
      break;
    Sleep(dwMilliseconds: v3);
    v5 = v3 + 1000;
    if ( v3 + 1000 > dword_3F03CD3C )
      v5 = -1;
    v3 = v5;
  }
  while ( v5 != -1 );
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x3F022940
// Name: _memcpy_1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl memcpy_1(void *a1, const void *Src, size_t Size)
{
  if ( a1 > Src && a1 < (char *)Src + Size )
    JUMPOUT(0x3F022B04);
  if ( Size < 0x100 || dword_3F0A3884 == 0 || ((unsigned __int8)a1 & 0xF) != ((unsigned __int8)Src & 0xF) )
    JUMPOUT(0x3F022987);
  return (void *)_mbschr(string: (const unsigned __int8 *)a1, c: (unsigned int)Src);
}

//------------------------------------------------------------------------------
// Address: 0x3F022982
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
unsigned __int8 *__cdecl _mbschr(const unsigned __int8 *string, unsigned int c)
{
  return _mbschr_0(Str: string, C: c);
}

//------------------------------------------------------------------------------
// Address: 0x3F022996
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  int v4; // edx
  int v5; // ecx
  void *v6; // edi
  const void *v7; // esi

  *(_BYTE *)(v4 + 42) |= BYTE1(v4);
  qmemcpy(v6, v7, 4 * v5);
  _initp_misc_winxfltr(enull: TargetFrame);
}

//------------------------------------------------------------------------------
// Address: 0x3F02299C
// Name: __initp_misc_winxfltr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall _initp_misc_winxfltr(int a1@<edx>, _BYTE *a2@<edi>, _BYTE *a3@<esi>)
{
  switch ( a1 )
  {
    case 0:
      JUMPOUT(0x3F022AC4);
    case 1:
      *a2 = *a3;
      _alldiv();
      return;
    case 2:
      JUMPOUT(0x3F022AD8);
    case 3:
      JUMPOUT(0x3F022AEC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0229A4
// Name: CopyLeadUp_2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CopyLeadUp_2@<eax>(unsigned int a1@<ecx>, char a2@<dil>)
{
  bool v2; // cf
  unsigned int v3; // ecx

  v2 = a1 < 4;
  v3 = a1 - 4;
  if ( v2 )
    return (*((int (**)(void))_initp_misc_winxfltr_0 + v3))();
  else
    return (*((int (__fastcall **)(unsigned int, int))CopyUnwindUp_1 + (a2 & 3) + 1))(a1: (a2 & 3) + v3, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x3F0229C4
// Name: CopyUnwindUp_1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __usercall CopyUnwindUp_1@<eax>(int a1@<edx>, int a2@<ecx>, _BYTE *a3@<edi>, _BYTE *a4@<esi>)
{
  switch ( a2 )
  {
    case 0:
      goto UnwindUp0_2;
    case 1:
      goto UnwindUp1_2;
    case 2:
      goto UnwindUp2_2;
    case 3:
      goto UnwindUp3_1;
    case 4:
      goto UnwindUp4_1;
    case 5:
      goto UnwindUp5_1;
    case 6:
      *(_DWORD *)&a3[4 * a2 - 24] = *(_DWORD *)&a4[4 * a2 - 24];
UnwindUp5_1:
      *(_DWORD *)&a3[4 * a2 - 20] = *(_DWORD *)&a4[4 * a2 - 20];
UnwindUp4_1:
      *(_DWORD *)&a3[4 * a2 - 16] = *(_DWORD *)&a4[4 * a2 - 16];
UnwindUp3_1:
      *(_DWORD *)&a3[4 * a2 - 12] = *(_DWORD *)&a4[4 * a2 - 12];
UnwindUp2_2:
      *(_DWORD *)&a3[4 * a2 - 8] = *(_DWORD *)&a4[4 * a2 - 8];
UnwindUp1_2:
      *(_DWORD *)&a3[4 * a2 - 4] = *(_DWORD *)&a4[4 * a2 - 4];
      a4 += 4 * a2;
      a3 += 4 * a2;
UnwindUp0_2:
      switch ( a1 )
      {
        case 0:
          JUMPOUT(0x3F022AC4);
        case 1:
          *a3 = *a4;
          return _alldiv();
        case 2:
          JUMPOUT(0x3F022AD8);
        case 3:
          JUMPOUT(0x3F022AEC);
      }
    case 7:
      JUMPOUT(0x3F022A68);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F022A20
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(int a1@<edx>, _BYTE *a2@<edi>, _BYTE *a3@<esi>)
{
  switch ( a1 )
  {
    case 0:
      JUMPOUT(0x3F022AC4);
    case 1:
      *a2 = *a3;
      return _alldiv();
    case 2:
      JUMPOUT(0x3F022AD8);
    case 3:
      JUMPOUT(0x3F022AEC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F022A29
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __noreturn _ftol2_pentium4(_BYTE *a1, int a2)
{
  *(_DWORD *)(a2 - 2096658426) = __ROR4__(*(_DWORD *)(a2 - 2096658426), 1);
  *a1 = -63;
  JUMPOUT(0x40C9AD39);
}

//------------------------------------------------------------------------------
// Address: 0x3F022AC4
// Name: __initp_misc_winxfltr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// jumptable 3F02299C case 0
// jumptable 3F022A20 case 0
// jumptable 3F022A3E case 0
// jumptable 3F022AAB case 0
// positive sp value has been detected, the output may be wrong!
int __usercall _initp_misc_winxfltr_0@<eax>(int a1@<ebp>)
{
  return *(_DWORD *)(a1 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F022AD0
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _alldiv@<eax>(int a1@<ebp>)
{
  return *(_DWORD *)(a1 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F022B80
// Name: __allshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _allshr(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  _EAX = a1;
  LOBYTE(_EAX) = a1 - 2;
  __asm { aas }
  *(_BYTE *)(a2 + 3) = *(_BYTE *)(a3 + 3);
  *(_BYTE *)(a2 + 2) = *(_BYTE *)(a3 + 2);
  JUMPOUT(0x3F022B9F);
}

//------------------------------------------------------------------------------
// Address: 0x3F022BA1
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _forcdecpt_l(int a1@<edx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>, long double *buffer)
{
  *(_BYTE *)(a1 - 120) |= BYTE1(a1);
  while ( a2 != 0 )
  {
    *(_DWORD *)a3 = *(_DWORD *)a4;
    a4 -= 4;
    a3 -= 4;
    --a2;
  }
  switch ( a1 )
  {
    case 0:
      return;
    case 1:
      *(_BYTE *)(a3 + 3) = *(_BYTE *)(a4 + 3);
      break;
    case 2:
      *(_BYTE *)(a3 + 3) = *(_BYTE *)(a4 + 3);
      *(_BYTE *)(a3 + 2) = *(_BYTE *)(a4 + 2);
      break;
    case 3:
      *(_BYTE *)(a3 + 3) = *(_BYTE *)(a4 + 3);
      _positive(arg: buffer);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F022C92
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _positive@<eax>(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  *(_BYTE *)(a2 + 2) = *(_BYTE *)(a3 + 2);
  *(_BYTE *)(a2 + 1) = *(_BYTE *)(a3 + 1);
  return *(_DWORD *)(a1 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F022CA8
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fassign_l(int a1@<ebp>)
{
  char *v1; // eax

  *(_DWORD *)(a1 - 4) = 0;
  GetStartupInfoA(lpStartupInfo: (LPSTARTUPINFOA)(a1 - 100));
  *(_DWORD *)(a1 - 4) = -2;
  v1 = _calloc_crt_0(Size: (const char *)0x20, a2: 56);
  if ( v1 != nullptr )
  {
    dword_3F0A3780[0] = (int)v1;
    uNumber = 32;
    JUMPOUT(0x3F022CE7);
  }
  JUMPOUT(0x3F022EDC);
}

//------------------------------------------------------------------------------
// Address: 0x3F022CE8
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fassign(_BYTE *a1@<eax>)
{
  *a1 = (_BYTE)a1;
  JUMPOUT(0x3F022CEB);
}

//------------------------------------------------------------------------------
// Address: 0x3F022CFF
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, char *a2)
{
  LOBYTE(s) = 0;
  s[37] = 10;
  s[38] = 10;
  if ( (unsigned int)(s + 56) < dword_3F0A3780[0] + 1792 )
    JUMPOUT(0x3F022CEF);
  _forcdecpt(buffer: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F022D1C
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _forcdecpt(int a1@<ebp>, __int16 a2@<di>)
{
  if ( *(_WORD *)(a1 - 50) != a2 )
    JUMPOUT(0x3F022D2B);
  JUMPOUT(0x3F022E23);
}

//------------------------------------------------------------------------------
// Address: 0x3F022D38
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        _BYTE *a2@<ebx>,
        int a3@<ebp>,
        char *a4@<edi>,
        long double *sizeInBytes,
        char *ndec,
        unsigned int caps,
        _strflt *pflt,
        _strflt *g_fmt,
        localeinfo_struct *plocinfo)
{
  char v10; // cc
  int v11; // esi
  char *v12; // eax
  int *v13; // ecx
  unsigned int i; // edx
  void *v15; // ecx
  int v16; // esi
  int v17; // eax
  int v18; // esi
  HANDLE StdHandle; // eax
  HANDLE v20; // edi
  DWORD FileType; // eax
  int v22; // eax

  *buf |= (unsigned __int8)buf;
  v10 = ((char)(BYTE1(a2) + *a2) < 0) ^ __OFADD__(BYTE1(a2), *a2);
  *a2 += BYTE1(a2);
  if ( !v10 )
    a4 = buf;
  v11 = 1;
  while ( (int)uNumber < (int)a4 )
  {
    v12 = _calloc_crt_0(Size: (const char *)0x20, a2: 56);
    if ( v12 == nullptr )
    {
      a4 = (char *)uNumber;
      break;
    }
    v13 = &dword_3F0A3780[v11];
    *v13 = (int)v12;
    uNumber += 32;
    for ( i = (unsigned int)(v12 + 1792); (unsigned int)v12 < i; i = *v13 + 1792 )
    {
      v12[4] = 0;
      *(_DWORD *)v12 = -1;
      v12[5] = 10;
      *((_DWORD *)v12 + 2) = 0;
      v12[36] &= 0x80u;
      v12[37] = 10;
      v12[38] = 10;
      v12 += 56;
    }
    ++v11;
  }
  for ( *(_DWORD *)(a3 - 32) = 0; *(_DWORD *)(a3 - 32) < (int)a4; *(_DWORD *)(a3 - 28) += 4 )
  {
    v15 = **(void ***)(a3 - 28);
    if ( v15 != (void *)-1 && v15 != (void *)-2 && (*a2 & 1) != 0 && ((*a2 & 8) != 0 || GetFileType(hFile: v15) != 0) )
    {
      v16 = dword_3F0A3780[*(int *)(a3 - 32) >> 5] + 56 * (*(_DWORD *)(a3 - 32) & 0x1F);
      *(_DWORD *)v16 = **(_DWORD **)(a3 - 28);
      *(_BYTE *)(v16 + 4) = *a2;
      __crtInitCritSecAndSpinCount_0();
      if ( v17 == 0 )
        goto LABEL_38;
      ++*(_DWORD *)(v16 + 8);
    }
    ++*(_DWORD *)(a3 - 32);
    ++a2;
  }
  v18 = dword_3F0A3780[0];
  if ( *(_DWORD *)dword_3F0A3780[0] != -1 && *(_DWORD *)dword_3F0A3780[0] != -2 )
  {
    *(_BYTE *)(dword_3F0A3780[0] + 4) |= 0x80u;
    JUMPOUT(0x3F022EB4);
  }
  *(_BYTE *)(dword_3F0A3780[0] + 4) = -127;
  StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF6);
  v20 = StdHandle;
  if ( StdHandle == (HANDLE)-1 || StdHandle == nullptr || (FileType = GetFileType(hFile: StdHandle)) == 0 )
    JUMPOUT(0x3F022EAA);
  *(_DWORD *)v18 = v20;
  if ( (unsigned __int8)FileType == 2 )
  {
    *(_BYTE *)(v18 + 4) |= 0x40u;
  }
  else if ( (unsigned __int8)FileType == 3 )
  {
    *(_BYTE *)(v18 + 4) |= 8u;
  }
  __crtInitCritSecAndSpinCount_0();
  if ( v22 == 0 )
LABEL_38:
    JUMPOUT(0x3F022EDC);
  return _cftoe_l(pvalue: sizeInBytes, buf: ndec, sizeInBytes: caps, ndec: (int)pflt, caps: (int)g_fmt, plocinfo);
}

//------------------------------------------------------------------------------
// Address: 0x3F022EA5
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cftoe_l@<eax>(int a1@<ebx>, int a2@<esi>)
{
  ++*(_DWORD *)(a2 + 8);
  if ( a1 + 1 < 3 )
    JUMPOUT(0x3F022E25);
  SetHandleCount(uNumber: uNumber);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F022F73
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _cftoe(int a1@<ebp>)
{
  if ( *(_BYTE *)(a1 - 4) != 0 )
    JUMPOUT(0x3F022F8E);
  JUMPOUT(0x3F022F92);
}

//------------------------------------------------------------------------------
// Address: 0x3F022F91
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl _cftoa_l()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F023302
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int cftof2_l()
{
  return ((int (__cdecl *)(_UNKNOWN **))loc_3F0230C1)(a1: &off_3F03B8E0);
}

//------------------------------------------------------------------------------
// Address: 0x3F0233F7
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _cftof_l(char a1@<zf>, const wchar_t *a2@<ebx>, int a3@<esi>)
{
  int *v3; // edi
  _BYTE *v4; // eax

  if ( !a1 && (const wchar_t *)a3 != a2 )
  {
    if ( (*(_BYTE *)(a3 + 12) & 0x40) != 0 )
      JUMPOUT(0x3F0234B8);
    if ( ((int (__cdecl *)(int))loc_3F022F31)(a1: a3) == -1 || ((int (__cdecl *)(int))loc_3F022F31)(a1: a3) == -2 )
    {
      v4 = &unk_3F03BD00;
    }
    else
    {
      v3 = &dword_3F0A3780[((int (__cdecl *)(int))loc_3F022F31)(a1: a3) >> 5];
      v4 = (_BYTE *)(*v3 + 56 * (((int (__cdecl *)(int))loc_3F022F31)(a1: a3) & 0x1F));
    }
    if ( (v4[36] & 0x7F) == 0 )
    {
      if ( ((int (__cdecl *)(int))loc_3F022F31)(a1: a3) != -1 && ((int (__cdecl *)(int))loc_3F022F31)(a1: a3) != -2 )
      {
        ((void (__cdecl *)(int))loc_3F022F31)(a1: a3);
        ((void (__cdecl *)(int))loc_3F022F31)(a1: a3);
      }
      JUMPOUT(0x3F0234AF);
    }
  }
  *_errno_0() = 22;
  _invalid_parameter_0(
    Expression: a2,
    FunctionName: a2,
    FileName: a2,
    LineNo: (unsigned int)a2,
    Reserved: (uintptr_t)a2);
  JUMPOUT(0x3F023FD9);
}

//------------------------------------------------------------------------------
// Address: 0x3F0234B0
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _cftog_l(_DWORD *a1@<eax>, __int16 _DX@<dx>, char a3@<cl>, int a4@<ebx>, int a5@<ebp>)
{
  --*(_DWORD *)(a4 - 1241524099);
  __readeflags();
  *a1 += a1;
  *(_BYTE *)(a5 + 887657549) += a3;
  __asm { insb }
  JUMPOUT(0x3F0234C4);
}

//------------------------------------------------------------------------------
// Address: 0x3F02364F
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _setdefaultprecision(char a1@<zf>, int a2@<ebp>, unsigned __int8 *a3@<edi>)
{
  int v3; // ebx

  *(_BYTE *)(a2 - 5) = -1;
  if ( a1 )
    *(_BYTE *)(a2 - 5) = 1;
  v3 = *a3 | 0x20;
  *(_DWORD *)(a2 - 32) = v3;
  if ( v3 != 110 )
  {
    if ( v3 != 99 && v3 != 123 )
      JUMPOUT(0x3F023677);
    JUMPOUT(0x3F02367F);
  }
  JUMPOUT(0x3F02369C);
}

//------------------------------------------------------------------------------
// Address: 0x3F023678
// Name: __ms_p5_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ms_p5_test_fdiv()
{
  JUMPOUT(0x3F02367A);
}

//------------------------------------------------------------------------------
// Address: 0x3F0236DD
// Name: __atodbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _atodbl_l(_DWORD *a1@<eax>)
{
  char *v1; // eax
  bool v2; // zf
  char v3; // cc

  _disable();
  v1 = (char *)a1 + *a1;
  v2 = (_BYTE)v1 + *(v1 - 1962871939) == 0;
  v3 = ((char)((_BYTE)v1 + *(v1 - 1962871939)) < 0) ^ __OFADD__((_BYTE)v1, *(v1 - 1962871939));
  *(v1 - 1962871939) += (char)v1;
  if ( v3 )
  {
    if ( !v2 )
      JUMPOUT(0x3F023EFE);
    JUMPOUT(0x3F023EDE);
  }
  JUMPOUT(0x3F0236F4);
}

//------------------------------------------------------------------------------
// Address: 0x3F023783
// Name: __atoflt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _atoflt_l(unsigned __int16 a1@<dx>, int a2@<ebx>, int a3@<ebp>)
{
  int v3; // eax
  char v4; // al
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  int v8; // ecx

  __inbyte(a1);
  ++*(_DWORD *)(a3 + 4);
  v3 = ((int (*)(void))loc_3F023369)();
  *(_DWORD *)(a3 - 4) = v3;
  if ( ((int (__cdecl *)(_DWORD))((char *)&_wctype[48] + 1))(a1: (unsigned __int8)v3) == 0 )
  {
    v4 = ***(_BYTE ***)(*(_DWORD *)(a3 - 108) + 188);
    v5 = v4 == *(_BYTE *)(a3 - 4);
    *(_BYTE *)(a3 - 24) = v4;
    if ( v5 )
    {
      v6 = *(_DWORD *)(a3 - 12);
      *(_DWORD *)(a3 - 12) = v6 - 1;
      if ( v6 != 0 )
      {
        ++*(_DWORD *)(a3 + 4);
        v7 = ((int (*)(void))loc_3F023369)();
        v8 = *(_DWORD *)(a3 - 36);
        *(_DWORD *)(a3 - 4) = v7;
        *(_BYTE *)(a2 + v8) = *(_BYTE *)(a3 - 24);
        if ( ((int (__cdecl *)(int, int, int))loc_3F023315)(a1: a2 + 1, a2: a3 + 8, a3: a3 - 68) != 0 )
          JUMPOUT(0x3F023848);
        JUMPOUT(0x3F023F96);
      }
    }
    JUMPOUT(0x3F023853);
  }
  JUMPOUT(0x3F02374B);
}

//------------------------------------------------------------------------------
// Address: 0x3F023829
// Name: __fptostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fptostr()
{
  _disable();
  JUMPOUT(0x3F02382A);
}

//------------------------------------------------------------------------------
// Address: 0x3F0238E6
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __dtold(
        char a1@<zf>,
        int a2@<eax>,
        int a3@<ecx>,
        int a4@<ebx>,
        int a5@<ebp>,
        _CRT_DOUBLE pld,
        _strflt *sign,
        char *a8,
        unsigned int a9)
{
  int v9; // edx
  int i; // eax
  int v11; // eax
  int v12; // eax
  char v13; // cl
  int v14; // eax

  if ( a1 )
  {
    *(_DWORD *)(a5 - 12) &= a2;
  }
  else
  {
    v9 = *(_DWORD *)(a5 - 20);
    ++*(_DWORD *)(a5 + 4);
    *(_DWORD *)(a5 - 4) = ((int (__fastcall *)(int, int))loc_3F023369)(a1: a3, a2: v9);
  }
  for ( i = *(unsigned __int8 *)(a5 - 4);
        ((int (__cdecl *)(int))((char *)&_wctype[48] + 1))(a1: i) != 0;
        i = (unsigned __int8)i )
  {
    v11 = *(_DWORD *)(a5 - 12);
    *(_DWORD *)(a5 - 12) = v11 - 1;
    if ( v11 == 0 )
      break;
    v12 = *(_DWORD *)(a5 - 36);
    v13 = *(_BYTE *)(a5 - 4);
    ++*(_DWORD *)(a5 - 28);
    *(_BYTE *)(a4 + v12) = v13;
    if ( ((int (__cdecl *)(int, int, int))loc_3F023315)(a1: ++a4, a2: a5 + 8, a3: a5 - 68) == 0 )
      goto LABEL_17;
    ++*(_DWORD *)(a5 + 4);
    i = ((int (*)(void))loc_3F023369)();
    *(_DWORD *)(a5 - 4) = i;
  }
  --*(_DWORD *)(a5 + 4);
  if ( *(_DWORD *)(a5 - 4) != -1 )
    _ungetc_nolock(Character: *(_DWORD *)(a5 - 4), Stream: *(FILE **)(a5 - 20));
  if ( *(_DWORD *)(a5 - 28) == 0 )
LABEL_17:
    JUMPOUT(0x3F023F96);
  if ( *(_BYTE *)(a5 - 13) != 0 )
    JUMPOUT(0x3F023EFE);
  v14 = *(_DWORD *)(a5 - 36);
  ++*(_DWORD *)(a5 - 60);
  *(_BYTE *)(a4 + v14) = 0;
  ((void (__cdecl *)(int (*)()))_decode_pointer)(a1: off_3F03BC6C[0]);
  _fltout2(x: pld, flt: sign, resultstr: a8, resultsize: a9);
}

//------------------------------------------------------------------------------
// Address: 0x3F0239A1
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _fltout2(void (*a1)(void)@<eax>)
{
  a1();
  JUMPOUT(0x3F023EFE);
}

//------------------------------------------------------------------------------
// Address: 0x3F023A30
// Name: __alldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _alldvrm(int a1@<eax>, int a2@<ebx>, int a3@<ebp>, _WORD *a4@<esi>)
{
  int v4; // eax

  if ( ((1 << (a1 & 7)) & (a2 ^ *(char *)(a3 + (a1 >> 3) + 360))) != 0 )
  {
    if ( *(_BYTE *)(a3 - 13) == 0 )
    {
      if ( *(_BYTE *)(a3 - 22) != 0 )
      {
        *(_BYTE *)(a3 - 80) = a1;
        if ( ((int (__cdecl *)(_DWORD))loc_3F022F94)((unsigned __int8)a1) != 0 )
        {
          ++*(_DWORD *)(a3 + 4);
          *(_BYTE *)(a3 - 79) = ((int (*)(void))loc_3F023369)();
        }
        v4 = *(_DWORD *)(a3 - 108);
        *(_DWORD *)(a3 - 92) = 63;
        _mbtowc_l_0(
          DstCh: (wchar_t *)(a3 - 92),
          SrcCh: (const char *)(a3 - 80),
          SrcSizeInBytes: *(_DWORD *)(v4 + 172),
          Locale: (_locale_t)(a3 - 108));
        *a4 = *(_WORD *)(a3 - 92);
        JUMPOUT(0x3F023C87);
      }
      JUMPOUT(0x3F023C84);
    }
    JUMPOUT(0x3F023C8F);
  }
  JUMPOUT(0x3F023C95);
}

//------------------------------------------------------------------------------
// Address: 0x3F023B10
// Name: __aullshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F023B2F
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _controlfp_s(int a1@<ebx>)
{
  int v2; // [esp-4h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 1048579268))++ == -1 )
    *(_BYTE *)(v2 + 371) = 32;
  JUMPOUT(0x3F023BB3);
}

//------------------------------------------------------------------------------
// Address: 0x3F023B99
// Name: __ld12tod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _ld12tod(unsigned int a1@<ecx>, int a2@<ebp>, _BYTE *a3@<esi>)
{
  *(_BYTE *)(a2 + (a1 >> 3) + 360) |= 1 << (a1 & 7);
  if ( *a3 == 93 )
  {
    *(_DWORD *)(a2 - 40) = a3;
    JUMPOUT(0x3F0239C3);
  }
  JUMPOUT(0x3F023B49);
}

//------------------------------------------------------------------------------
// Address: 0x3F0240DB
// Name: __ld12tof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
__int64 __userpurge _ld12tof@<edx:eax>(
        unsigned __int64 a1@<edx:eax>,
        unsigned int a2@<esi>,
        unsigned __int64 pld12,
        _CRT_FLOAT *f,
        int a5)
{
  __outbyte(3u, a1);
  *(_DWORD *)(HIDWORD(a1) + 14) *= 2;
  if ( a1 > pld12 )
    --a2;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F0240F8
// Name: sub_3F0240F8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F0240F8(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    *a1 = dword_3F03BD44;
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F02412C
// Name: sub_3F02412C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F02412C(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    *a1 = dword_3F03BD48;
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F024160
// Name: sub_3F024160
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F024160(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    *a1 = dword_3F03BD40;
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F024194
// Name: sub_3F024194
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *sub_3F024194()
{
  return &dword_3F03BD44;
}

//------------------------------------------------------------------------------
// Address: 0x3F02419A
// Name: sub_3F02419A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *sub_3F02419A()
{
  return &dword_3F03BD48;
}

//------------------------------------------------------------------------------
// Address: 0x3F0241A0
// Name: sub_3F0241A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *sub_3F0241A0()
{
  return &dword_3F03BD40;
}

//------------------------------------------------------------------------------
// Address: 0x3F0241A6
// Name: sub_3F0241A6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_UNKNOWN **sub_3F0241A6()
{
  return &off_3F03BDD0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0241AC
// Name: __tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *_tzset_nolock()
{
  char *v0; // eax
  const char *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // edi
  int v5; // edi
  int v6; // edi
  LPSTR *v7; // edi
  const char *v8; // esi
  char v9; // al
  int *result; // eax
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int v15; // [esp+14h] [ebp-38h]
  unsigned int CodePage; // [esp+18h] [ebp-34h]
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
  ((void (__cdecl *)(int))_lock_0)(a1: 7);
  ms_exc.registration.TryLevel = 0;
  v21 = (LPSTR *)sub_3F0241A6();
  if ( sub_3F024160(a1: &v22) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  if ( sub_3F0240F8(a1: &v20) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  if ( sub_3F02412C(a1: &v19) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  CodePage = ___lc_codepage_func_0();
  dword_3F03CDEC = 0;
  dword_3F03BE4C = -1;
  dword_3F03BE40 = -1;
  v0 = getenv(VarName: "TZ");
  v1 = v0;
  if ( v0 == nullptr || *v0 == 0 )
  {
    if ( Destination != nullptr )
    {
      free(Block: Destination);
      Destination = nullptr;
    }
    if ( GetTimeZoneInformation(lpTimeZoneInformation: &TimeZoneInformation) != -1 )
    {
      dword_3F03CDEC = 1;
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
  if ( Destination != nullptr )
  {
    if ( strcmp_0(Str1: v0, Str2: Destination) == 0 )
    {
LABEL_33:
      v18 = 1;
      goto LABEL_34;
    }
    if ( Destination != nullptr )
      free(Block: Destination);
  }
  v2 = ((int (__cdecl *)(const char *))loc_3F01E640)(a1: v1);
  Destination = (char *)_malloc_crt_0(Size: v2 + 1);
  if ( Destination == nullptr )
    goto LABEL_33;
  v3 = ((int (__cdecl *)(const char *))loc_3F01E640)(a1: v1);
  if ( strcpy_s_0(Destination: Destination, SizeInBytes: v3 + 1, Source: v1) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
LABEL_34:
  v4 = v22;
  *sub_3F0241A0() = v4;
  v5 = v20;
  *sub_3F024194() = v5;
  v6 = v19;
  *sub_3F02419A() = v6;
  ms_exc.registration.TryLevel = -2;
  result = (int *)((int (__cdecl *)(int))loc_3F020118)(a1: 7);
  if ( v18 == 0 )
  {
    v7 = v21;
    if ( strncpy_s_0(Destination: *v21, SizeInBytes: 0x40u, Source: v1, MaxCount: 3u) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    v8 = v1 + 3;
    if ( *v8 == 45 )
    {
      v15 = 1;
      ++v8;
    }
    v22 = 3600 * sub_3F01C62A(a1: (int)v8);
    while ( 1 )
    {
      v9 = *v8;
      if ( *v8 != 43 && (v9 < 48 || v9 > 57) )
        break;
      ++v8;
    }
    if ( *v8 == 58 )
    {
      v11 = sub_3F01C62A(a1: (int)++v8);
      v22 += 60 * v11;
      while ( *v8 >= 48 && *v8 <= 57 )
        ++v8;
      if ( *v8 == 58 )
      {
        v12 = sub_3F01C62A(a1: (int)++v8);
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
      if ( strncpy_s_0(Destination: v7[1], SizeInBytes: 0x40u, Source: v8, MaxCount: 3u) != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    }
    else
    {
      *v7[1] = 0;
    }
    v13 = v22;
    *sub_3F0241A0() = v13;
    v14 = v20;
    result = sub_3F024194();
    *result = v14;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02461D
// Name: ___strgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall __strgtold12_l@<eax>(int a1@<eax>, int a2@<ecx>, _DWORD *a3@<ebp>, int a4@<edi>, int a5@<esi>)
{
  int result; // eax
  int v6; // et2
  int v7; // esi
  int v8; // esi
  int v9; // ecx
  int ms_exc_4; // [esp+60h] [ebp-14h]

  v6 = a1 % ms_exc_4;
  result = a1 / ms_exc_4;
  if ( v6 != 0 || (result = (a4 + 1900) / 400, (a4 + 1900) % 400 == 0) )
    v7 = (int)*(&off_3F03BDD4 + a5);
  else
    v7 = dword_3F03BE08[a5];
  v8 = a3[7] + v7;
  v9 = a3[10] + 1000 * (a3[9] + 60 * (a3[8] + 60 * a2));
  if ( a3[2] == 1 )
  {
    dword_3F03BE44 = v8;
    dword_3F03BE48 = v9;
    dword_3F03BE40 = a4;
  }
  else
  {
    dword_3F03BE50 = v8;
    dword_3F03BE54 = v9;
    if ( sub_3F02412C(a1: a3 - 1) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    result = 1000 * *(a3 - 1);
    dword_3F03BE54 += result;
    if ( dword_3F03BE54 >= 0 )
    {
      result = 86400000;
      if ( dword_3F03BE54 >= 86400000 )
      {
        dword_3F03BE54 -= 86400000;
        ++dword_3F03BE50;
      }
    }
    else
    {
      dword_3F03BE54 += 86400000;
      --dword_3F03BE50;
    }
    dword_3F03BE4C = a4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F024CDD
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _I10_OUTPUT@<eax>(int a1@<ebp>, int a2@<edi>)
{
  *(_DWORD *)(a1 - 4) = -2;
  sub_3F024CF7();
  return a2 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F024CF4
// Name: sub_3F024CF4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F024CF4()
{
  return sub_3F024CF7();
}

//------------------------------------------------------------------------------
// Address: 0x3F024CF7
// Name: sub_3F024CF7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F024CF7()
{
  return ((int (__cdecl *)(int))loc_3F020118)(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F024D00
// Name: __local_unwind4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4_0(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-8h] [ebp-28h]
  int (__cdecl *v8)(int, int, int, int); // [esp-4h] [ebp-24h]

  v8 = _unwind_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 == -2 || a3 != -2 && v4 <= a3 )
      break;
    v5 = 3 * v4;
    v6 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 0x10);
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      _NLG_Notify_0(a1: 257);
      _NLG_Call_0(a1: 1, a2: ExceptionList, a3: v8);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F024D90
// Name: __unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax
  int v5; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 + 8));
    _local_unwind4_0(a1: *(_DWORD **)(v5 + 20), a2: *(_DWORD *)(v5 + 16), a3: *(_DWORD *)(v5 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F024DD6
// Name: __seh_longjmp_unwind4@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _seh_longjmp_unwind4(int a1)
{
  return _local_unwind4_0(a1: *(_DWORD **)(a1 + 40), a2: *(_DWORD *)(a1 + 24), a3: *(_DWORD *)(a1 + 28));
}

//------------------------------------------------------------------------------
// Address: 0x3F024E3C
// Name: _EH4_LocalUnwind::6_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind::6_0(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4_0(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F024E53
// Name: __write_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _write_nolock_0(int a1, const void *a2, DWORD nNumberOfBytesToWrite)
{
  int v4; // ebx
  int *v5; // edi
  int v6; // eax
  char v7; // cl
  BOOL v8; // esi
  UINT ConsoleCP; // eax
  char *v10; // esi
  DWORD v11; // eax
  signed int v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  char *v17; // eax
  char *v18; // edx
  char v19; // dl
  signed int v20; // esi
  unsigned int v21; // esi
  unsigned int v22; // ecx
  char *v23; // eax
  __int16 *v24; // edx
  __int16 v25; // dx
  signed int v26; // esi
  DWORD v27; // ecx
  wchar_t *v28; // eax
  wchar_t v29; // dx
  int v30; // esi
  int v31; // edi
  unsigned int v32; // esi
  int v33; // [esp-Ch] [ebp-8Ch]
  unsigned int Mode; // [esp+4h] [ebp-7Ch] BYREF
  BOOL v35; // [esp+8h] [ebp-78h]
  char *v36; // [esp+Ch] [ebp-74h]
  int *v37; // [esp+10h] [ebp-70h]
  unsigned int v38; // [esp+14h] [ebp-6Ch] BYREF
  int v39; // [esp+18h] [ebp-68h]
  LPCVOID lpBuffer; // [esp+1Ch] [ebp-64h]
  unsigned int v41; // [esp+20h] [ebp-60h]
  wchar_t *v42; // [esp+24h] [ebp-5Ch]
  char v43; // [esp+2Bh] [ebp-55h]
  wchar_t WideCharStr[2]; // [esp+2Ch] [ebp-54h] BYREF
  unsigned int NumberOfBytesWritten; // [esp+30h] [ebp-50h] BYREF
  char Buffer[340]; // [esp+34h] [ebp-4Ch] BYREF
  char v47[688]; // [esp+188h] [ebp+108h] BYREF
  wchar_t v48[170]; // [esp+438h] [ebp+3B8h] BYREF
  char MultiByteStr[8]; // [esp+58Ch] [ebp+50Ch] BYREF

  lpBuffer = a2;
  v41 = 0;
  v39 = 0;
  if ( nNumberOfBytesToWrite == 0 )
    return 0;
  if ( a2 == nullptr )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return -1;
  }
  v4 = 56 * (a1 & 0x1F);
  v5 = &dword_3F0A3780[a1 >> 5];
  v6 = v4 + *v5;
  v7 = (char)(2 * *(_BYTE *)(v6 + 36)) >> 1;
  v37 = v5;
  v43 = v7;
  if ( (v7 == 2 || v7 == 1) && (nNumberOfBytesToWrite & 1) != 0 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return -1;
  }
  if ( (*(_BYTE *)(v6 + 4) & 0x20) != 0 )
    ((void (__cdecl *)(int, _DWORD, _DWORD, int))&__newcumap[109])(a1, a2: 0, a3: 0, a4: 2);
  if ( ((int (__cdecl *)(int))((char *)&_wctype[192] + 1))(a1) != 0 && *(char *)(v4 + *v5 + 4) < 0 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(_getptd_0() + 108) + 20) == 0;
    if ( GetConsoleMode(hConsoleHandle: *(HANDLE *)(v4 + *v5), lpMode: &Mode) && (!v8 || v43 != 0) )
    {
      ConsoleCP = GetConsoleCP();
      NumberOfBytesWritten = 0;
      v10 = (char *)lpBuffer;
      Mode = ConsoleCP;
      v36 = (char *)lpBuffer;
      v42 = nullptr;
      while ( 1 )
      {
        if ( v43 != 0 )
        {
          if ( v43 == 1 || v43 == 2 )
          {
            v14 = *(unsigned __int16 *)v10;
            ++v42;
            *(_DWORD *)WideCharStr = v14;
            v36 = v10 + 2;
            v35 = (_WORD)v14 == 10;
          }
          if ( v43 == 1 || v43 == 2 )
          {
            if ( _putwch_nolock_0(Character: WideCharStr[0]) != WideCharStr[0] )
              goto LABEL_82;
            ++v41;
            if ( v35 )
            {
              wcscpy(WideCharStr, L"\r");
              if ( _putwch_nolock_0(Character: 0xDu) != WideCharStr[0] )
                goto LABEL_82;
              ++v41;
              ++v39;
            }
          }
        }
        else
        {
          v33 = *v10;
          v35 = *v10 == 10;
          if ( ((int (__cdecl *)(int))loc_3F022F94)(a1: v33) != 0 )
          {
            if ( nNumberOfBytesToWrite + (_BYTE *)lpBuffer - v10 <= 1
              || sub_3F028975(DstCh: WideCharStr, SrcCh: v10, SrcSizeInBytes: 2u) == -1 )
            {
              goto LABEL_83;
            }
            ++v10;
            v42 = (wchar_t *)((char *)v42 + 1);
          }
          else if ( sub_3F028975(DstCh: WideCharStr, SrcCh: v10, SrcSizeInBytes: 1u) == -1 )
          {
            goto LABEL_83;
          }
          v42 = (wchar_t *)((char *)v42 + 1);
          v36 = v10 + 1;
          v11 = WideCharToMultiByte(
                  CodePage: Mode,
                  dwFlags: 0,
                  lpWideCharStr: WideCharStr,
                  cchWideChar: 1,
                  lpMultiByteStr: MultiByteStr,
                  cbMultiByte: 5,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          v12 = v11;
          if ( v11 == 0 )
            goto LABEL_83;
          if ( !WriteFile(
                  hFile: *(HANDLE *)(v4 + *v5),
                  lpBuffer: MultiByteStr,
                  nNumberOfBytesToWrite: v11,
                  lpNumberOfBytesWritten: &NumberOfBytesWritten,
                  lpOverlapped: nullptr) )
            goto LABEL_82;
          v41 += NumberOfBytesWritten;
          if ( (int)NumberOfBytesWritten < v12 )
            goto LABEL_83;
          if ( v35 )
          {
            v13 = *v5;
            MultiByteStr[0] = 13;
            if ( !WriteFile(
                    hFile: *(HANDLE *)(v4 + v13),
                    lpBuffer: MultiByteStr,
                    nNumberOfBytesToWrite: 1u,
                    lpNumberOfBytesWritten: &NumberOfBytesWritten,
                    lpOverlapped: nullptr) )
              goto LABEL_82;
            if ( (int)NumberOfBytesWritten < 1 )
              goto LABEL_83;
            ++v39;
            ++v41;
          }
        }
        if ( (unsigned int)v42 >= nNumberOfBytesToWrite )
          goto LABEL_83;
        v10 = v36;
      }
    }
  }
  v15 = v4 + *v5;
  if ( *(char *)(v15 + 4) >= 0 )
  {
    if ( WriteFile(
           hFile: *(HANDLE *)v15,
           lpBuffer,
           nNumberOfBytesToWrite,
           lpNumberOfBytesWritten: &v38,
           lpOverlapped: nullptr) )
    {
      *(_DWORD *)WideCharStr = 0;
      v41 = v38;
      goto LABEL_83;
    }
  }
  else
  {
    *(_DWORD *)WideCharStr = 0;
    if ( v43 != 0 )
    {
      if ( v43 == 2 )
      {
        NumberOfBytesWritten = (unsigned int)lpBuffer;
        while ( 1 )
        {
          v21 = 0;
          v22 = NumberOfBytesWritten - (_DWORD)lpBuffer;
          v23 = Buffer;
          do
          {
            if ( v22 >= nNumberOfBytesToWrite )
              break;
            v24 = (__int16 *)NumberOfBytesWritten;
            NumberOfBytesWritten += 2;
            v25 = *v24;
            v22 += 2;
            if ( v25 == 10 )
            {
              v39 += 2;
              *(_WORD *)v23 = 13;
              v23 += 2;
              v21 += 2;
            }
            v5 = v37;
            *(_WORD *)v23 = v25;
            v23 += 2;
            v21 += 2;
          }
          while ( v21 < 0x3FF );
          v26 = v23 - Buffer;
          if ( !WriteFile(
                  hFile: *(HANDLE *)(v4 + *v5),
                  lpBuffer: Buffer,
                  nNumberOfBytesToWrite: v23 - Buffer,
                  lpNumberOfBytesWritten: &v38,
                  lpOverlapped: nullptr) )
            break;
          v41 += v38;
          if ( (int)v38 < v26 || NumberOfBytesWritten - (unsigned int)lpBuffer >= nNumberOfBytesToWrite )
            goto LABEL_83;
        }
      }
      else
      {
        v42 = (wchar_t *)lpBuffer;
        while ( 1 )
        {
          NumberOfBytesWritten = 0;
          v27 = (char *)v42 - (_BYTE *)lpBuffer;
          v28 = v48;
          do
          {
            if ( v27 >= nNumberOfBytesToWrite )
              break;
            v29 = *v42++;
            v27 += 2;
            if ( v29 == 10 )
            {
              *v28++ = 13;
              NumberOfBytesWritten += 2;
            }
            NumberOfBytesWritten += 2;
            *v28++ = v29;
          }
          while ( NumberOfBytesWritten < 0x152 );
          v30 = 0;
          v31 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: v48,
                  cchWideChar: v28 - v48,
                  lpMultiByteStr: v47,
                  cbMultiByte: 683,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v31 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)(v4 + *v37),
                    lpBuffer: &v47[v30],
                    nNumberOfBytesToWrite: v31 - v30,
                    lpNumberOfBytesWritten: &v38,
                    lpOverlapped: nullptr) )
          {
            v30 += v38;
            if ( v31 <= v30 )
              goto LABEL_77;
          }
          *(_DWORD *)WideCharStr = GetLastError();
LABEL_77:
          if ( v31 <= v30 )
          {
            v41 = (char *)v42 - (_BYTE *)lpBuffer;
            if ( (char *)v42 - (_BYTE *)lpBuffer < nNumberOfBytesToWrite )
              continue;
          }
          goto LABEL_83;
        }
      }
    }
    else
    {
      NumberOfBytesWritten = (unsigned int)lpBuffer;
      while ( 1 )
      {
        v42 = nullptr;
        v16 = NumberOfBytesWritten - (_DWORD)lpBuffer;
        v17 = Buffer;
        do
        {
          if ( v16 >= nNumberOfBytesToWrite )
            break;
          v18 = (char *)NumberOfBytesWritten++;
          v19 = *v18;
          ++v16;
          if ( v19 == 10 )
          {
            ++v39;
            *v17++ = 13;
            v42 = (wchar_t *)((char *)v42 + 1);
          }
          *v17++ = v19;
          v42 = (wchar_t *)((char *)v42 + 1);
        }
        while ( (unsigned int)v42 < 0x400 );
        v20 = v17 - Buffer;
        if ( !WriteFile(
                hFile: *(HANDLE *)(v4 + *v5),
                lpBuffer: Buffer,
                nNumberOfBytesToWrite: v17 - Buffer,
                lpNumberOfBytesWritten: &v38,
                lpOverlapped: nullptr) )
          break;
        v41 += v38;
        if ( (int)v38 < v20 || NumberOfBytesWritten - (unsigned int)lpBuffer >= nNumberOfBytesToWrite )
          goto LABEL_83;
      }
    }
  }
LABEL_82:
  *(_DWORD *)WideCharStr = GetLastError();
LABEL_83:
  if ( v41 == 0 )
  {
    v32 = 0;
    if ( *(_DWORD *)WideCharStr != 0 )
    {
      v32 = 5;
      if ( *(_DWORD *)WideCharStr != 5 )
      {
        ((void (__cdecl *)(_DWORD))_dosmaperr_0)(a1: *(_DWORD *)WideCharStr);
        return -1;
      }
      *_errno_0() = 9;
    }
    else
    {
      if ( (*(_BYTE *)(v4 + *v37 + 4) & 0x40) != 0 && *(_BYTE *)lpBuffer == 26 )
        return 0;
      *_errno_0() = 28;
    }
    *__doserrno_0() = v32;
    return -1;
  }
  return v41 - v39;
}

//------------------------------------------------------------------------------
// Address: 0x3F025419
// Name: sub_3F025419
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F025419(int a1, const void *a2, DWORD nNumberOfBytesToWrite)
{
  int *v4; // ebx
  int v5; // esi
  int v6; // [esp+14h] [ebp-1Ch]

  if ( a1 == -2 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    return -1;
  }
  if ( a1 < 0
    || a1 >= uNumber
    || (v4 = &dword_3F0A3780[a1 >> 5], v5 = 56 * (a1 & 0x1F), (*(_BYTE *)(*v4 + v5 + 4) & 1) == 0) )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return -1;
  }
  __lock_fhandle_0(a1);
  if ( (*(_BYTE *)(*v4 + v5 + 4) & 1) != 0 )
  {
    v6 = _write_nolock_0(a1, a2, nNumberOfBytesToWrite);
  }
  else
  {
    *_errno_0() = 9;
    *__doserrno_0() = 0;
    v6 = -1;
  }
  _unlock_fhandle_0(a1);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F0254F5
// Name: __commit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _commit_0(int FileHandle)
{
  int *v1; // edi
  int v2; // esi
  void *osfhandle_0; // eax
  int result; // eax
  DWORD LastError; // [esp+14h] [ebp-1Ch]

  if ( FileHandle == -2 )
  {
    *_errno_0() = 9;
    goto LABEL_13;
  }
  if ( FileHandle < 0
    || FileHandle >= uNumber
    || (v1 = &dword_3F0A3780[FileHandle >> 5], (*(_BYTE *)((v2 = 56 * (FileHandle & 0x1F)) + *v1 + 4) & 1) == 0) )
  {
    *_errno_0() = 9;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
LABEL_13:
    JUMPOUT(0x3F0255C6);
  }
  __lock_fhandle_0(a1: FileHandle);
  if ( (*(_BYTE *)(v2 + *v1 + 4) & 1) == 0 )
    JUMPOUT(0x3F0255A8);
  osfhandle_0 = (void *)_get_osfhandle_0(FileHandle);
  if ( FlushFileBuffers(hFile: osfhandle_0) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    JUMPOUT(0x3F0255B7);
  __doserrno_0();
  LOWORD(result) = hw_cw(abstr: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0255A3
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0256F6
// Name: __read_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __cdecl _read_nolock_0(int a1, _BYTE *lpBuffer, DWORD nNumberOfBytesToRead)
{
  DWORD v3; // edx
  int v5; // esi
  int *v6; // edi
  int v7; // eax
  char v8; // cl
  _BYTE *v9; // eax
  __int64 v10; // rax
  int v11; // ecx
  int v12; // ecx
  char v13; // cl
  int v14; // ecx
  bool v15; // zf
  char v16; // cl
  int v17; // ecx
  char v18; // cl
  int v19; // ecx
  int v20; // eax
  char *v21; // eax
  bool v22; // cf
  DWORD LastError; // eax
  unsigned int NumberOfBytesRead; // [esp+8h] [ebp-18h] BYREF
  int v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch]
  char v28; // [esp+1Eh] [ebp-2h]

  v3 = nNumberOfBytesToRead;
  v25 = -2;
  if ( a1 == -2 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    return -1;
  }
  if ( a1 < 0 || a1 >= uNumber )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return -1;
  }
  v5 = 56 * (a1 & 0x1F);
  v6 = &dword_3F0A3780[a1 >> 5];
  v7 = v5 + *v6;
  v8 = *(_BYTE *)(v7 + 4);
  if ( (v8 & 1) == 0 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
LABEL_19:
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return -1;
  }
  if ( nNumberOfBytesToRead > 0x7FFFFFFF )
    goto LABEL_18;
  v26 = 0;
  if ( nNumberOfBytesToRead != 0 && (v8 & 2) == 0 )
  {
    if ( lpBuffer != nullptr )
    {
      v28 = (char)(2 * *(_BYTE *)(v7 + 36)) >> 1;
      if ( v28 == 1 )
      {
        if ( (nNumberOfBytesToRead & 1) == 0 )
        {
          nNumberOfBytesToRead = 4;
          if ( v3 >> 1 >= 4 )
            nNumberOfBytesToRead = v3 >> 1;
          v27 = (unsigned int)_malloc_crt_0(Size: nNumberOfBytesToRead);
          if ( v27 == 0 )
          {
            *_errno_0() = 12;
            *__doserrno_0() = 8;
            return -1;
          }
          v10 = ((__int64 (__cdecl *)(int, _DWORD, _DWORD, int))&__newcumap[109])(a1, a2: 0, a3: 0, a4: 1);
          v11 = *v6;
          *(_DWORD *)(v5 + v11 + 40) = v10;
          v9 = (_BYTE *)v27;
          *(_DWORD *)(v5 + v11 + 44) = HIDWORD(v10);
LABEL_26:
          v12 = v5 + *v6;
          if ( (*(_BYTE *)(v12 + 4) & 0x48) != 0 )
          {
            v13 = *(_BYTE *)(v12 + 5);
            if ( v13 != 10 && nNumberOfBytesToRead != 0 )
            {
              *v9 = v13;
              v14 = *v6;
              ++v9;
              --nNumberOfBytesToRead;
              v15 = v28 == 0;
              v26 = 1;
              *(_BYTE *)(v5 + v14 + 5) = 10;
              if ( !v15 )
              {
                v16 = *(_BYTE *)(v5 + *v6 + 37);
                if ( v16 != 10 && nNumberOfBytesToRead != 0 )
                {
                  *v9 = v16;
                  v17 = *v6;
                  ++v9;
                  --nNumberOfBytesToRead;
                  v15 = v28 == 1;
                  v26 = 2;
                  *(_BYTE *)(v5 + v17 + 37) = 10;
                  if ( v15 )
                  {
                    v18 = *(_BYTE *)(v5 + *v6 + 38);
                    if ( v18 != 10 && nNumberOfBytesToRead != 0 )
                    {
                      *v9 = v18;
                      v19 = *v6;
                      ++v9;
                      --nNumberOfBytesToRead;
                      v26 = 3;
                      *(_BYTE *)(v5 + v19 + 38) = 10;
                    }
                  }
                }
              }
            }
          }
          if ( ReadFile(
                 hFile: *(HANDLE *)(v5 + *v6),
                 lpBuffer: v9,
                 nNumberOfBytesToRead,
                 lpNumberOfBytesRead: &NumberOfBytesRead,
                 lpOverlapped: nullptr)
            && (NumberOfBytesRead & 0x80000000) == 0
            && NumberOfBytesRead <= nNumberOfBytesToRead )
          {
            v20 = *v6;
            v26 += NumberOfBytesRead;
            v21 = (char *)(v5 + v20 + 4);
            if ( *v21 < 0 )
            {
              if ( v28 != 2 )
              {
                if ( NumberOfBytesRead != 0 && *(_BYTE *)v27 == 10 )
                  *v21 |= 4u;
                else
                  *v21 &= ~4u;
                v22 = v27 < v27 + v26;
                v26 += v27;
                if ( v22 )
                  JUMPOUT(0x3F025959);
                JUMPOUT(0x3F025A29);
              }
              JUMPOUT(0x3F025B45);
            }
          }
          else
          {
            LastError = GetLastError();
            if ( LastError == 5 )
            {
              _errno_0();
              JUMPOUT(0x3F025C8D);
            }
            if ( LastError != 109 )
              JUMPOUT(0x3F025B00);
            v25 = 0;
          }
          JUMPOUT(0x3F025B0B);
        }
      }
      else
      {
        if ( v28 != 2 )
        {
LABEL_16:
          v9 = lpBuffer;
          v27 = (unsigned int)lpBuffer;
          goto LABEL_26;
        }
        if ( (nNumberOfBytesToRead & 1) == 0 )
        {
          nNumberOfBytesToRead &= ~1u;
          goto LABEL_16;
        }
      }
    }
LABEL_18:
    *__doserrno_0() = 0;
    *_errno_0() = 22;
    goto LABEL_19;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0259D4
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __mtold12(int a1@<eax>, char *a2@<ebx>, int a3@<ebp>, int *a4@<edi>, int a5@<esi>)
{
  char *v5; // ecx
  char v6; // al
  _BYTE *v7; // eax
  char *v8; // eax
  bool v9; // zf
  char *v10; // ebx
  int v11; // ecx
  int v12; // eax
  char v13; // dl
  int v14; // ecx
  _BYTE *v15; // ebx
  int v16; // ebx
  int v17; // eax
  DWORD LastError; // eax
  int v19; // eax
  int v20; // edx

  --*(_DWORD *)((a1 | 0x4D8A078B) - 351992244);
  if ( *(_BYTE *)(a3 - 1) == 10 )
  {
LABEL_43:
    *a2 = 10;
  }
  else
  {
    ((void (__cdecl *)(_DWORD, int, int, int))&__newcumap[109])(a1: *(_DWORD *)(a3 + 8), a2: -1, a3: -1, a4: 1);
    if ( *(_BYTE *)(a3 - 1) == 10 )
      goto LABEL_5;
LABEL_3:
    *a2 = 13;
  }
  ++a2;
LABEL_5:
  while ( *(_DWORD *)(a3 + 16) < *(_DWORD *)(a3 - 16) )
  {
    v5 = *(char **)(a3 + 16);
    v6 = *v5;
    if ( *v5 == 26 )
    {
      v7 = (_BYTE *)(a5 + *a4 + 4);
      if ( (*v7 & 0x40) != 0 )
        *a2++ = *v5;
      else
        *v7 |= 2u;
      break;
    }
    if ( v6 == 13 )
    {
      if ( (unsigned int)v5 < *(_DWORD *)(a3 - 16) - 1 )
      {
        if ( v5[1] == 10 )
        {
          *(_DWORD *)(a3 + 16) = v5 + 2;
          goto LABEL_43;
        }
        *(_DWORD *)(a3 + 16) = v5 + 1;
        goto LABEL_3;
      }
      ++*(_DWORD *)(a3 + 16);
      if ( !ReadFile(
              hFile: *(HANDLE *)(a5 + *a4),
              lpBuffer: (LPVOID)(a3 - 1),
              nNumberOfBytesToRead: 1u,
              lpNumberOfBytesRead: (LPDWORD)(a3 - 24),
              lpOverlapped: nullptr)
        && GetLastError() != 0
        || *(_DWORD *)(a3 - 24) == 0 )
      {
        goto LABEL_3;
      }
      if ( (*(_BYTE *)(a5 + *a4 + 4) & 0x48) == 0 )
        JUMPOUT(0x3F0259E0);
      if ( *(_BYTE *)(a3 - 1) != 10 )
        JUMPOUT(0x3F0259D2);
      goto LABEL_43;
    }
    *a2++ = v6;
    *(_DWORD *)(a3 + 16) = v5 + 1;
  }
  v8 = &a2[-*(_DWORD *)(a3 - 12)];
  v9 = *(_BYTE *)(a3 - 2) == 1;
  *(_DWORD *)(a3 - 16) = v8;
  if ( v9 && v8 != nullptr )
  {
    v10 = a2 - 1;
    LOBYTE(v11) = *v10;
    if ( *v10 < 0 )
    {
      v12 = 1;
      v11 = (unsigned __int8)v11;
      while ( byte_3F03BE58[v11] == 0 && v12 <= 4 && (unsigned int)v10 >= *(_DWORD *)(a3 - 12) )
      {
        v11 = (unsigned __int8)*--v10;
        ++v12;
      }
      v13 = *v10;
      if ( byte_3F03BE58[(unsigned __int8)*v10] == 0 )
      {
        *_errno_0() = 42;
LABEL_32:
        *(_DWORD *)(a3 - 20) = -1;
        goto $error_return$25367;
      }
      if ( byte_3F03BE58[(unsigned __int8)*v10] + 1 == v12 )
      {
        v10 += v12;
      }
      else
      {
        v14 = a5 + *a4;
        if ( (*(_BYTE *)(v14 + 4) & 0x48) != 0 )
        {
          v15 = v10 + 1;
          *(_BYTE *)(v14 + 5) = v13;
          if ( v12 >= 2 )
            *(_BYTE *)(a5 + *a4 + 37) = *v15++;
          if ( v12 == 3 )
            *(_BYTE *)(a5 + *a4 + 38) = *v15++;
          v10 = &v15[-v12];
        }
        else
        {
          ((void (__cdecl *)(_DWORD, int, int, int))&__newcumap[109])(
            a1: *(_DWORD *)(a3 + 8),
            a2: -v12,
            a3: -v12 >> 31,
            a4: 1);
        }
      }
    }
    else
    {
      ++v10;
    }
    v16 = (int)&v10[-*(_DWORD *)(a3 - 12)];
    v17 = MultiByteToWideChar(
            CodePage: 0xFDE9u,
            dwFlags: 0,
            lpMultiByteStr: *(LPCCH *)(a3 - 12),
            cbMultiByte: v16,
            lpWideCharStr: *(LPWSTR *)(a3 + 12),
            cchWideChar: *(_DWORD *)(a3 - 28) >> 1);
    *(_DWORD *)(a3 - 16) = v17;
    if ( v17 == 0 )
    {
      LastError = GetLastError();
      ((void (__cdecl *)(DWORD))_dosmaperr_0)(a1: LastError);
      goto LABEL_32;
    }
    v19 = *(_DWORD *)(a3 - 16);
    v20 = *a4;
    *(_DWORD *)(a3 - 16) = 2 * v19;
    *(_DWORD *)(a5 + v20 + 48) = v19 != v16;
  }
$error_return$25367:
  if ( *(_DWORD *)(a3 - 12) != *(_DWORD *)(a3 + 12) )
    free(Block: *(void **)(a3 - 12));
}

//------------------------------------------------------------------------------
// Address: 0x3F025BA0
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __set_fpsr_sse2(
        int a1@<eax>,
        _DWORD *a2@<edx>,
        int a3@<ecx>,
        _WORD *a4@<ebx>,
        int a5@<ebp>,
        int a6@<esi>)
{
  int v6; // eax
  _WORD *v7; // ebx

  v6 = a1 - 1;
  BYTE1(v6) += *(_BYTE *)(a6 - 125);
  if ( *a2 == a3 )
  {
    *(_DWORD *)(a5 + 16) = v6 + 4;
    *a4 = 10;
  }
  else
  {
    *(_DWORD *)(a5 + 16) = a3;
    *a4 = 13;
  }
  v7 = a4 + 1;
  if ( *(_DWORD *)(a5 + 16) >= *(_DWORD *)(a5 - 16) )
  {
    *(_DWORD *)(a5 - 16) = (char *)v7 - *(_DWORD *)(a5 - 12);
    JUMPOUT(0x3F025B0B);
  }
  JUMPOUT(0x3F025B70);
}

//------------------------------------------------------------------------------
// Address: 0x3F026058
// Name: nullsub_12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_12()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F026059
// Name: sub_3F026059
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F026059@<eax>(int a1@<ebp>)
{
  return _unlock_fhandle_0(a1: *(_DWORD *)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F0260C8
// Name: __ehhandler$??0out_of_range@std@@QAE@ABV01@@Z
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _ehhandler___0out_of_range_std__QAE_ABV01__Z()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F026103
// Name: __ehhandler$??0logic_error@std@@QAE@ABV01@@Z
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _ehhandler___0logic_error_std__QAE_ABV01__Z()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F026338
// Name: nullsub_13
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_13()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F026584
// Name: sub_3F026584
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F026584(void *this)
{
  *(_DWORD *)this = &std::bad_exception::`vftable';
  sub_3F01D197(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F02664C
// Name: sub_3F02664C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02664C@<eax>(_DWORD *a1@<eax>)
{
  --*a1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F026710
// Name: __unwindfunclet$?VCR_Hook_RecordGameMsg@@YAXIIJ@Z$0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unwindfunclet__VCR_Hook_RecordGameMsg__YAXIIJ_Z_0()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0267BA
// Name: sub_3F0267BA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall sub_3F0267BA@<eax>(int a1@<ebp>)
{
  return *(_BYTE *)(a1 + 12) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0267C3
// Name: sub_3F0267C3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn sub_3F0267C3()
{
  dynamic_initializer_for__g_VCRThreadSafeInitter___0();
}

//------------------------------------------------------------------------------
// Address: 0x3F026868
// Name: nullsub_14
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_14()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F02689A
// Name: __ehhandler$?VCR_Hook_Sys_FloatTime@@YANN@Z
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _ehhandler__VCR_Hook_Sys_FloatTime__YANN_Z(int a1@<ebp>)
{
  *(_DWORD *)(_getptd_0() + 148) = *(_DWORD *)(a1 + 8);
  _CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F026A20
// Name: _dynamic_initializer_for__g_ClockSpeedInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall dynamic_initializer_for__g_ClockSpeedInit__@<eax>(
        char a1@<zf>,
        int result@<eax>,
        int a3@<ebp>,
        int a4@<esi>)
{
  if ( (a1 || result == 429065506) && *(_DWORD *)(a3 - 52) == 0 && *(_DWORD *)(a3 - 28) != 0 )
  {
    result = _IsExceptionObjectToBeDestroyed(a1: *(_DWORD *)(a4 + 24));
    if ( result != 0 )
      return ((int (__cdecl *)(int, _DWORD))__DestructExceptionObject_0)(a1: a4, a2: *(_DWORD *)(a3 + 16));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F026A4E
// Name: ___BuildCatchObjectHelper_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __BuildCatchObjectHelper_0(int a1, int a2, int a3)
{
  if ( *(_DWORD *)(a3 + 4) == 0 )
    JUMPOUT(0x3F026BC5);
  return dynamic_initializer_for__s_MutexAllocScratch__();
}

//------------------------------------------------------------------------------
// Address: 0x3F026A70
// Name: _dynamic_initializer_for__s_MutexAllocScratch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__s_MutexAllocScratch__(char a1@<zf>, int a2@<eax>, int a3@<edx>, int a4@<ebp>)
{
  if ( !a1 )
  {
    if ( *(_DWORD *)(a2 + 8) == a3 )
      JUMPOUT(0x3F026A7D);
    *(_DWORD *)(a4 - 4) = a3;
    JUMPOUT(0x3F026A9F);
  }
  JUMPOUT(0x3F026BC5);
}

//------------------------------------------------------------------------------
// Address: 0x3F026AA0
// Name: _dynamic_initializer_for__g_ThreadFastMutexMiniDump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__g_ThreadFastMutexMiniDump__(int a1@<ebp>)
{
  unknown_libname_1(a1: *(_DWORD *)(*(_DWORD *)(a1 + 8) + 24));
  JUMPOUT(0x3F026AAD);
}

//------------------------------------------------------------------------------
// Address: 0x3F026AB0
// Name: _dynamic_initializer_for__g_AllocCSInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__g_AllocCSInit__(char a1@<zf>, int a2@<esi>)
{
  if ( !a1 && unknown_libname_1(a1: a2) != 0 )
    JUMPOUT(0x3F026AC7);
  JUMPOUT(0x3F026BA8);
}

//------------------------------------------------------------------------------
// Address: 0x3F026AD0
// Name: _dynamic_initializer_for__g_TestHarness__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dynamic_initializer_for__g_TestHarness__(_DWORD *a1@<eax>, _DWORD *a2@<esi>)
{
  *a1 = __ROR4__(*a1, 81);
  *a2 = ((int (__cdecl *)(_DWORD *))__AdjustPointer_0)(a1);
  JUMPOUT(0x3F026BAD);
}

//------------------------------------------------------------------------------
// Address: 0x3F026B00
// Name: _dynamic_initializer_for__g_ThreadMainThreadID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dynamic_initializer_for__g_ThreadMainThreadID__(int a1@<ebp>, int a2@<edi>, void *a3@<esi>)
{
  if ( ((_DWORD (__cdecl *)())unknown_libname_1)() != 0 )
  {
    memcpy_0(a1: a3, Src: *(const void **)(*(_DWORD *)(a1 + 8) + 24), Size: *(_DWORD *)(a2 + 20));
    JUMPOUT(0x3F026B1E);
  }
  JUMPOUT(0x3F026BA8);
}

//------------------------------------------------------------------------------
// Address: 0x3F026B20
// Name: _dynamic_initializer_for__DynTryEnterCriticalSection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__DynTryEnterCriticalSection__(int a1@<eax>)
{
  LOBYTE(a1) = (a1 | 0x83) + 15;
  if ( a1 != 0 )
    JUMPOUT(0x3F026AD3);
  JUMPOUT(0x3F026BAD);
}

//------------------------------------------------------------------------------
// Address: 0x3F026B50
// Name: _dynamic_initializer_for__g_pCurThread__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__g_pCurThread__(int a1@<eax>, int a2@<ebp>, int a3@<edi>, void *a4@<esi>)
{
  const void *v4; // eax
  size_t v5; // [esp-4h] [ebp-4h]

  if ( a1 != 0 )
  {
    v5 = *(_DWORD *)(a3 + 20);
    v4 = (const void *)((int (__cdecl *)(_DWORD, int))__AdjustPointer_0)(
                         a1: *(_DWORD *)(*(_DWORD *)(a2 + 8) + 24),
                         a2: a3 + 8);
    memcpy_0(a1: a4, Src: v4, Size: v5);
    JUMPOUT(0x3F026BAD);
  }
  JUMPOUT(0x3F026BA8);
}

//------------------------------------------------------------------------------
// Address: 0x3F026BA0
// Name: _dynamic_initializer_for__g_DebugFileCS222__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__g_DebugFileCS222__(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 119) = __ROL1__(*(_BYTE *)(a1 - 119), 69);
  __inbyte(0xEBu);
  JUMPOUT(0x3F026BB0);
}

//------------------------------------------------------------------------------
// Address: 0x3F026BC0
// Name: _dynamic_initializer_for__g_VCRThreadSafeInitter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __noreturn dynamic_initializer_for__g_VCRThreadSafeInitter__()
{
  dynamic_initializer_for__g_VCRThreadSafeInitter___0();
}

//------------------------------------------------------------------------------
// Address: 0x3F026BE0
// Name: _dynamic_initializer_for__g_VProfCurrentProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dynamic_initializer_for__g_VProfCurrentProfile__(int a1@<eax>, int a2@<ecx>, int a3@<ebx>)
{
  *(_BYTE *)(a1 + 1569391988) += a1;
  LOBYTE(a2) = *(_BYTE *)(a3 + 1435174984) | a2;
  LOBYTE(a1) = a1 | 0xEF;
  *(_DWORD *)(a3 + 4 * a1) += a2;
  JUMPOUT(0x3F026BF6);
}

//------------------------------------------------------------------------------
// Address: 0x3F026C00
// Name: _dynamic_initializer_for__g_TimesLessChildren__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dynamic_initializer_for__g_TimesLessChildren__(char a1@<sf>, char a2@<of>, int a3@<edi>)
{
  int v3; // eax
  int v4; // [esp-Ch] [ebp-Ch]
  int v5; // [esp-8h] [ebp-8h]

  if ( a1 != a2 )
  {
    v3 = __BuildCatchObjectHelper_0(a1: a3, a2: v4, a3: v5) - 1;
    if ( v3 != 0 )
    {
      if ( v3 == 1 )
        JUMPOUT(0x3F026C11);
      JUMPOUT(0x3F026C45);
    }
    JUMPOUT(0x3F026C2D);
  }
  JUMPOUT(0x3F026C0A);
}

//------------------------------------------------------------------------------
// Address: 0x3F026C20
// Name: _dynamic_initializer_for__g_TimeSumsMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dynamic_initializer_for__g_TimeSumsMap__(int a1@<ebx>, int a2@<esi>)
{
  sub_3F01E745(a1, a2: *(_DWORD *)(a2 + 24));
  JUMPOUT(0x3F026C45);
}

//------------------------------------------------------------------------------
// Address: 0x3F026C40
// Name: _dynamic_initializer_for__g_TimeSums__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F026C50
// Name: _dynamic_atexit_destructor_for__s_StdMemAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__s_StdMemAlloc__()
{
  JUMPOUT(0x3F026C55);
}

//------------------------------------------------------------------------------
// Address: 0x3F026C56
// Name: sub_3F026C56
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn sub_3F026C56()
{
  dynamic_initializer_for__g_VCRThreadSafeInitter___0();
}

//------------------------------------------------------------------------------
// Address: 0x3F026C60
// Name: _dynamic_atexit_destructor_for__g_AllocCSInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F026C70
// Name: _dynamic_atexit_destructor_for__g_TestHarness__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__g_TestHarness__()
{
  JUMPOUT(0x3F026C71);
}

//------------------------------------------------------------------------------
// Address: 0x3F026CC0
// Name: _dynamic_atexit_destructor_for__g_pCurThread__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dynamic_atexit_destructor_for__g_pCurThread__(void *a1@<eax>, struct EHRegistrationNode *a2@<esi>)
{
  _JumpToContinuation(a1, a2);
  JUMPOUT(0x3F026CC8);
}

//------------------------------------------------------------------------------
// Address: 0x3F026CCA
// Name: void FindHandlerForForeignException(struct EHExceptionRecord __near *,struct EHRegistrationNode __near *,struct _CONTEXT __near *,void __near *,struct _s_FuncInfo const __near *,int,int,struct EHRegistrationNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl FindHandlerForForeignException()
{
  JUMPOUT(0x3F026CD0);
}

//------------------------------------------------------------------------------
// Address: 0x3F026CE0
// Name: _dynamic_atexit_destructor_for__g_VCRThreadSafeInitter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__g_VCRThreadSafeInitter__()
{
  _getptd_0();
  JUMPOUT(0x3F026CEC);
}

//------------------------------------------------------------------------------
// Address: 0x3F026CF0
// Name: _dynamic_atexit_destructor_for__g_VProfCurrentProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_atexit_destructor_for__g_VProfCurrentProfile__(int a1@<ebp>)
{
  --*(_DWORD *)(a1 + 32952);
  JUMPOUT(0x3F026CFA);
}

//------------------------------------------------------------------------------
// Address: 0x3F026D00
// Name: _dynamic_atexit_destructor_for__g_TimesLessChildren__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_atexit_destructor_for__g_TimesLessChildren__(
        char a1@<zf>,
        int a2@<ebp>,
        struct EHExceptionRecord *a3@<esi>)
{
  if ( a1
    || a3->ExceptionCode == -532459699
    || _CallSETranslator(
         a1: a3,
         a2: *(struct EHRegistrationNode **)(a2 + 12),
         a3: *(void **)(a2 + 16),
         a4: *(void **)(a2 + 20),
         a5: *(const struct _s_FuncInfo **)(a2 + 24),
         a6: *(_DWORD *)(a2 + 32),
         a7: *(struct EHRegistrationNode **)(a2 + 36)) == 0 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(a2 + 24) + 12) == 0 )
      _inconsistency();
    JUMPOUT(0x3F026D3E);
  }
  JUMPOUT(0x3F026DB8);
}

//------------------------------------------------------------------------------
// Address: 0x3F026D40
// Name: _dynamic_atexit_destructor_for__g_TimeSumsMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_atexit_destructor_for__g_TimeSumsMap__(
        unsigned int *a1@<eax>,
        int a2@<ebp>,
        const struct _s_FuncInfo *a3@<edi>,
        int a4@<esi>)
{
  const struct _s_TryBlockMapEntry *v4; // edi

  v4 = _GetRangeOfTrysToCheck(a1: a3, a2: *(_DWORD *)(a2 + 32), a3: a4, a4: (unsigned int *)(a2 - 4), a5: a1);
  if ( *(_DWORD *)(a2 - 4) < *(_DWORD *)(a2 - 8) )
  {
    if ( a4 >= v4->tryLow && a4 <= v4->tryHigh )
    {
      if ( v4->pHandlerArray[v4->nCatches - 1].pType != nullptr )
        JUMPOUT(0x3F026D7D);
      JUMPOUT(0x3F026D7F);
    }
    JUMPOUT(0x3F026DA9);
  }
  JUMPOUT(0x3F026DB8);
}

//------------------------------------------------------------------------------
// Address: 0x3F026D80
// Name: _dynamic_atexit_destructor_for__g_TimeSums__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F026DB1
// Name: _operator_new_::_6_::_dynamic_atexit_destructor_for__nomem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall operator_new_::_6_::_dynamic_atexit_destructor_for__nomem__@<al>(char a1@<cf>, char a2@<al>)
{
  return a1 + a2 + 59;
}

//------------------------------------------------------------------------------
// Address: 0x3F0277B1
// Name: ____lc_codepage_func_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl ___lc_codepage_func_0()
{
  int v0; // ecx
  int v1; // eax

  v0 = _getptd_0();
  v1 = *(_DWORD *)(v0 + 108);
  if ( (_UNKNOWN *)v1 != off_3F03B8D8 && (dword_3F03B7F4 & *(_DWORD *)(v0 + 112)) == 0 )
    v1 = __updatetlocinfo_0();
  return *(_DWORD *)(v1 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F0277D7
// Name: _strcat_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl strcat_s_0(char *Destination, rsize_t SizeInBytes, const char *Source)
{
  rsize_t v3; // edi
  errno_t v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // cl

  if ( Destination == nullptr )
    goto LABEL_3;
  v3 = SizeInBytes;
  if ( SizeInBytes == 0 )
    goto LABEL_3;
  v6 = Source;
  if ( Source != nullptr )
  {
    v7 = Destination;
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
      do
      {
        v8 = *v6;
        *v7++ = *v6++;
        if ( v8 == 0 )
          break;
        --v3;
      }
      while ( v3 != 0 );
      if ( v3 == 0 )
      {
        *Destination = 0;
        *_errno_0() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return 0;
    }
  }
  *Destination = 0;
LABEL_3:
  v4 = 22;
  *_errno_0() = 22;
LABEL_4:
  _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x3F027850
// Name: _strcspn_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl strcspn_0(const char *Str, const char *Control)
{
  unsigned int v2; // eax
  size_t v5; // ecx
  signed __int32 v7[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v7, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *Control;
    if ( *Control == 0 )
      break;
    ++Control;
    _bittestandset(v7, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *Str;
    if ( *Str == 0 )
      break;
    ++Str;
  }
  while ( !_bittest(v7, v2) );
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F027896
// Name: _strncpy_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl strncpy_s_0(char *Destination, rsize_t SizeInBytes, const char *Source, rsize_t MaxCount)
{
  rsize_t v5; // edi
  errno_t v6; // esi
  const char *v7; // edx
  char *v8; // eax
  char v9; // cl
  char v10; // cl

  if ( MaxCount != 0 )
  {
    if ( Destination == nullptr )
    {
LABEL_7:
      v6 = 22;
      *_errno_0() = 22;
LABEL_8:
      _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      return v6;
    }
  }
  else if ( Destination == nullptr )
  {
    if ( SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  v5 = SizeInBytes;
  if ( SizeInBytes == 0 )
    goto LABEL_7;
  if ( MaxCount == 0 )
  {
    *Destination = 0;
    return 0;
  }
  v7 = Source;
  if ( Source == nullptr )
  {
    *Destination = 0;
    goto LABEL_7;
  }
  v8 = Destination;
  if ( MaxCount == -1 )
  {
    do
    {
      v9 = *v7;
      *v8++ = *v7++;
      if ( v9 == 0 )
        break;
      --v5;
    }
    while ( v5 != 0 );
  }
  else
  {
    do
    {
      v10 = *v7;
      *v8++ = *v7++;
      if ( v10 == 0 )
        break;
      if ( --v5 == 0 )
        break;
      --MaxCount;
    }
    while ( MaxCount != 0 );
    if ( MaxCount == 0 )
      *v8 = 0;
  }
  if ( v5 != 0 )
    return 0;
  if ( MaxCount != -1 )
  {
    *Destination = 0;
    *_errno_0() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  Destination[SizeInBytes - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x3F027949
// Name: _strncmp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp_0(const char *Str1, const char *Str2, size_t MaxCount)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  size_t v12; // [esp+4h] [ebp-4h]

  v12 = 0;
  if ( MaxCount == 0 )
    return 0;
  if ( MaxCount <= 4 )
  {
    v4 = Str2;
    v5 = Str1;
    goto LABEL_23;
  }
  v4 = Str2;
  v5 = Str1;
  do
  {
    v6 = *v5;
    v5 += 4;
    v4 += 4;
    if ( v6 == 0 || v6 != *(v4 - 4) )
    {
      v10 = *((unsigned __int8 *)v5 - 4);
      v11 = *((unsigned __int8 *)v4 - 4);
      return v10 - v11;
    }
    v7 = *(v5 - 3);
    if ( v7 == 0 || v7 != *(v4 - 3) )
    {
      v10 = *((unsigned __int8 *)v5 - 3);
      v11 = *((unsigned __int8 *)v4 - 3);
      return v10 - v11;
    }
    v8 = *(v5 - 2);
    if ( v8 == 0 || v8 != *(v4 - 2) )
    {
      v10 = *((unsigned __int8 *)v5 - 2);
      v11 = *((unsigned __int8 *)v4 - 2);
      return v10 - v11;
    }
    v9 = *(v5 - 1);
    if ( v9 == 0 || v9 != *(v4 - 1) )
    {
      v10 = *((unsigned __int8 *)v5 - 1);
      v11 = *((unsigned __int8 *)v4 - 1);
      return v10 - v11;
    }
    v12 += 4;
  }
  while ( v12 < MaxCount - 4 );
  while ( 1 )
  {
LABEL_23:
    if ( v12 >= MaxCount )
      return 0;
    if ( *v5 == 0 || *v5 != *v4 )
      break;
    ++v5;
    ++v4;
    ++v12;
  }
  v10 = *(unsigned __int8 *)v5;
  v11 = *(unsigned __int8 *)v4;
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x3F027A10
// Name: _strpbrk_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strpbrk_0(const char *Str, const char *Control)
{
  char *result; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  result = nullptr;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(result) = *Control;
    if ( *Control == 0 )
      break;
    ++Control;
    _bittestandset(v5, (unsigned int)result);
  }
  while ( 1 )
  {
    LOBYTE(result) = *Str;
    if ( *Str == 0 )
      break;
    ++Str;
    if ( _bittest(v5, (unsigned int)result) )
      return (char *)(Str - 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F027A50
// Name: ___ansicp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ansicp_0(LCID Locale)
{
  char LCData[8]; // [esp+0h] [ebp-Ch] BYREF

  LCData[6] = 0;
  if ( GetLocaleInfoA(Locale, LCType: 0x1004u, lpLCData: LCData, cchData: 6) != 0 )
    return sub_3F01C62A(a1: (int)LCData);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F0284A7
// Name: sub_3F0284A7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F0284A7@<eax>(int a1@<ebp>)
{
  return _unlock_fhandle_0(a1: *(_DWORD *)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F0284B1
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getbuf(_DWORD *a1)
{
  void *v1; // eax
  int result; // eax

  ++dword_3F03C800;
  v1 = _malloc_crt_0(Size: 0x1000u);
  a1[2] = v1;
  if ( v1 != nullptr )
  {
    a1[3] |= 8u;
    a1[6] = 4096;
  }
  else
  {
    a1[3] |= 4u;
    a1[2] = a1 + 5;
    a1[6] = 2;
  }
  result = a1[2];
  a1[1] = 0;
  *a1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0284F5
// Name: sub_3F0284F5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F0284F5()
{
  return raise(signum: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x3F0284FE
// Name: _has_osfxsr_set
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int has_osfxsr_set()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F02854E
// Name: __get_sse2_info_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_sse2_info_0()
{
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4
  int v13; // [esp+18h] [ebp-4h]

  v13 = 0;
  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
  if ( v1 != v0 )
  {
    __writeeflags(v0);
    _EAX = 0;
    __asm { cpuid }
    _EAX = 1;
    __asm { cpuid }
    v13 = _EDX;
  }
  return (v13 & 0x4000000) != 0 && has_osfxsr_set() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0285C0
// Name: __alloca_probe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _alloca_probe@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x3F0285EB
// Name: __calloc_impl_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl _calloc_impl_0(size_t Size, unsigned int a2, _DWORD *a3)
{
  size_t v4; // esi
  LPVOID v5; // ebx
  void *v6; // [esp+10h] [ebp-1Ch]
  size_t Sizea; // [esp+34h] [ebp+8h]

  if ( Size == 0 || 0xFFFFFFE0 / Size >= a2 )
  {
    Sizea = a2 * Size;
    v4 = Sizea;
    if ( Sizea == 0 )
      v4 = 1;
    while ( 1 )
    {
      v5 = nullptr;
      if ( v4 <= 0xFFFFFFE0 )
        break;
LABEL_14:
      if ( v5 != nullptr )
        return v5;
      if ( dword_3F03CCFC == 0 )
      {
        if ( a3 != nullptr )
          *a3 = 12;
        return v5;
      }
      if ( _callnewh_0(Size: v4) == 0 )
      {
        if ( a3 != nullptr )
          *a3 = 12;
        return nullptr;
      }
    }
    if ( dword_3F0A48C4 == 3 )
    {
      v4 = (v4 + 15) & 0xFFFFFFF0;
      if ( Sizea <= dword_3F0A3890 )
      {
        ((void (__stdcall *)(int))_lock_0)(a1: 4);
        v6 = (void *)((int (__cdecl *)(size_t))loc_3F020A3D)(a1: Sizea);
        ((void (__cdecl *)(int))loc_3F020118)(a1: 4);
        v5 = v6;
        if ( v6 == nullptr )
        {
LABEL_13:
          v5 = HeapAlloc(hHeap: hHeap, dwFlags: 8u, dwBytes: v4);
          goto LABEL_14;
        }
        memset_0(a1: v6, Val: 0, Size: Sizea);
      }
    }
    if ( v5 != nullptr )
      return v5;
    goto LABEL_13;
  }
  *_errno_0() = 12;
  _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F028710
// Name: __allmul_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul_0(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F028744
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock(int Character, FILE *Stream)
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
    if ( ((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream) == -1
      || ((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream) == -2 )
    {
      v3 = &unk_3F03BD00;
    }
    else
    {
      v2 = &dword_3F0A3780[((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream) >> 5];
      v3 = (_BYTE *)(*v2 + 56 * (((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream) & 0x1F));
    }
    if ( (v3[36] & 0x7F) != 0
      || (((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream) == -1
       || ((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream) == -2
        ? (v5 = (char *)&unk_3F03BD00)
        : (v4 = &dword_3F0A3780[((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream) >> 5],
           v5 = (char *)(*v4 + 56 * (((int (__cdecl *)(FILE *))loc_3F022F31)(a1: Stream) & 0x1F))),
          v5[36] < 0) )
    {
      *_errno_0() = 22;
      _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      return -1;
    }
  }
  if ( Character == -1 )
    return -1;
  flag = Stream->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( Stream->_base == nullptr )
    _getbuf(a1: Stream);
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
// Address: 0x3F028862
// Name: __mbtowc_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l_0(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes, _locale_t Locale)
{
  _BYTE v5[16]; // [esp+8h] [ebp-10h] BYREF

  if ( SrcCh != nullptr && SrcSizeInBytes != 0 )
  {
    if ( *SrcCh != 0 )
      ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v5, a2: Locale);
    if ( DstCh != nullptr )
      *DstCh = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F028975
// Name: sub_3F028975
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F028975(wchar_t *DstCh, char *SrcCh, size_t SrcSizeInBytes)
{
  return _mbtowc_l_0(DstCh, SrcCh, SrcSizeInBytes, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F02898C
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(const char *VarName)
{
  unsigned __int8 **v1; // esi
  size_t v3; // edi

  v1 = (unsigned __int8 **)dword_3F03C7D8;
  if ( dword_3F0A48C8 == 0 )
    return nullptr;
  if ( dword_3F03C7D8 != nullptr
    || dword_3F03C7E0 != 0
    && __wtomb_environ_0() == 0
    && (v1 = (unsigned __int8 **)dword_3F03C7D8, dword_3F03C7D8 != nullptr) )
  {
    if ( VarName != nullptr )
    {
      v3 = ((int (__cdecl *)(const char *))loc_3F01E640)(a1: VarName);
      while ( *v1 != nullptr )
      {
        if ( ((int (__cdecl *)(unsigned __int8 *))loc_3F01E640)(a1: *v1) > v3 && (*v1)[v3] == 61 )
          sub_3F029AF6(Str1: *v1, Str2: (unsigned __int8 *)VarName, MaxCount: v3);
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F029161
// Name: $exit$28194
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _exit_28194()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F029166
// Name: __sopen_helper_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_helper_0(int a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int result; // eax
  _BYTE *v7; // eax
  int v8; // [esp+14h] [ebp-20h]
  int v9; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  v9 = 0;
  if ( a5 == nullptr || (*a5 = -1, a1 == 0) || a6 != 0 && (a4 & 0xFFFFFE7F) != 0 )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 22;
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    v8 = ((int (__stdcall *)(int *))_tsopen_nolock)(a1: &v9);
    ms_exc.registration.TryLevel = -2;
    if ( v9 != 0 )
    {
      if ( v8 != 0 )
      {
        v7 = (_BYTE *)(dword_3F0A3780[(int)*a5 >> 5] + 56 * (*a5 & 0x1F) + 4);
        *v7 &= ~1u;
      }
      _unlock_fhandle_0(a1: *a5);
    }
    result = v8;
    if ( v8 != 0 )
      *a5 = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F029232
// Name: sub_3F029232
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F029232(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  return _sopen_helper_0(a1: a2, a2: a3, a3: a4, a4: a5, a5: a1, a6: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F029250
// Name: __mbsnbcmp_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp_l_0(const unsigned __int8 *Str1, const unsigned __int8 *Str2, size_t MaxCount, _locale_t Locale)
{
  _BYTE v5[4]; // [esp+4h] [ebp-10h] BYREF

  if ( MaxCount != 0 )
    ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v5, a2: Locale);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0293B9
// Name: sub_3F0293B9
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F0293B9(unsigned __int8 *Str1, unsigned __int8 *Str2, size_t MaxCount)
{
  return _mbsnbcmp_l_0(Str1, Str2, MaxCount, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F0293D0
// Name: __global_unwind2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2_0(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return_0, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F0293F0
// Name: __unwind_handler_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler_0(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax
  int v6; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    __security_check_cookie`...'(StackCookie: a5 ^ *(_DWORD *)(a5 - 4));
    _local_unwind2_0(a1: *(_DWORD *)(v6 + 36), a2: *(_DWORD *)(v6 + 40));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F029435
// Name: __local_unwind2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2_0(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ecx
  int v7; // [esp-4h] [ebp-24h]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-20h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
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
      _NLG_Notify_0(a1: 257);
      _NLG_Call_0(a1: v6, a2: v7, a3: ExceptionList);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0294B9
// Name: __abnormal_termination_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination_0()
{
  int result; // eax
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler_0 )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0294DC
// Name: __NLG_Notify1_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1_0(int a1)
{
  JUMPOUT(0x3F0294F0);
}

//------------------------------------------------------------------------------
// Address: 0x3F0294E5
// Name: __NLG_Notify_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge _NLG_Notify_0@<eax>(int result@<eax>, int a2@<ebp>, int a3)
{
  unk_3F03C098 = a3;
  unk_3F03C094 = result;
  unk_3F03C09C = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F029504
// Name: __NLG_Call_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call_0@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x3F029507
// Name: __putwch_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wint_t __cdecl _putwch_nolock_0(wchar_t Character)
{
  UINT ConsoleOutputCP; // eax
  DWORD v3; // eax
  unsigned int NumberOfCharsWritten; // [esp+4h] [ebp-10h] BYREF
  char MultiByteStr[8]; // [esp+8h] [ebp-Ch] BYREF

  if ( dword_3F03C0A0 == 0 )
    goto LABEL_10;
  if ( hConsoleOutput == (HANDLE)-2 )
    __initconout_0();
  if ( hConsoleOutput == (HANDLE)-1 )
    return -1;
  if ( !WriteConsoleW(
          hConsoleOutput: hConsoleOutput,
          lpBuffer: &Character,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: &NumberOfCharsWritten,
          lpReserved: nullptr) )
  {
    if ( dword_3F03C0A0 != 2 || GetLastError() != 120 )
      return -1;
    dword_3F03C0A0 = 0;
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
    if ( hConsoleOutput != (HANDLE)-1
      && WriteConsoleA(
           hConsoleOutput: hConsoleOutput,
           lpBuffer: MultiByteStr,
           nNumberOfCharsToWrite: v3,
           lpNumberOfCharsWritten: &NumberOfCharsWritten,
           lpReserved: nullptr) )
    {
      return Character;
    }
    return -1;
  }
  dword_3F03C0A0 = 1;
  return Character;
}

//------------------------------------------------------------------------------
// Address: 0x3F029646
// Name: __free_osfhnd_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _free_osfhnd_0(int a1)
{
  int v1; // esi
  int *v2; // edi
  _DWORD *v3; // eax

  if ( a1 < 0
    || a1 >= uNumber
    || (v1 = 56 * (a1 & 0x1F), v2 = &dword_3F0A3780[a1 >> 5], ((v3 = (_DWORD *)(v1 + *v2))[1] & 1) == 0)
    || *v3 == -1 )
  {
    *_errno_0() = 9;
    *__doserrno_0() = 0;
    return -1;
  }
  else
  {
    if ( dword_3F03C834 == 1 )
    {
      if ( a1 != 0 )
      {
        if ( a1 == 1 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF5, hHandle: nullptr);
        }
        else if ( a1 == 2 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF4, hHandle: nullptr);
        }
      }
      else
      {
        SetStdHandle(nStdHandle: 0xFFFFFFF6, hHandle: nullptr);
      }
    }
    *(_DWORD *)(v1 + *v2) = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0296C7
// Name: __get_osfhandle_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
intptr_t __cdecl _get_osfhandle_0(int FileHandle)
{
  intptr_t *v2; // eax

  if ( FileHandle == -2 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    return -1;
  }
  else if ( FileHandle >= 0
         && FileHandle < uNumber
         && ((v2 = (intptr_t *)(dword_3F0A3780[FileHandle >> 5] + 56 * (FileHandle & 0x1F)))[1] & 1) != 0 )
  {
    return *v2;
  }
  else
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F029738
// Name: ___lock_fhandle_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl __lock_fhandle_0(int a1)
{
  int v1; // esi
  int v2; // eax
  BOOL v4; // [esp+10h] [ebp-1Ch]

  v1 = dword_3F0A3780[a1 >> 5] + 56 * (a1 & 0x1F);
  v4 = true;
  if ( *(_DWORD *)(v1 + 8) == 0 )
  {
    ((void (__cdecl *)(int))_lock_0)(a1: 10);
    if ( *(_DWORD *)(v1 + 8) == 0 )
    {
      __crtInitCritSecAndSpinCount_0();
      v4 = v2 != 0;
      ++*(_DWORD *)(v1 + 8);
    }
    ((void (__cdecl *)(int))loc_3F020118)(a1: 10);
  }
  if ( v4 )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(dword_3F0A3780[a1 >> 5] + 56 * (a1 & 0x1F) + 12));
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x3F0297D8
// Name: __unlock_fhandle_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_fhandle_0(int a1)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(dword_3F0A3780[a1 >> 5] + 56 * (a1 & 0x1F) + 12));
}

//------------------------------------------------------------------------------
// Address: 0x3F0299EA
// Name: __ismbblead_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead_0(unsigned int Ch)
{
  return ((int (__cdecl *)(_DWORD, unsigned int, _DWORD, int))((char *)&cccr_escr_map[14][0] + 1))(
           a1: 0,
           a2: Ch,
           a3: 0,
           a4: 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F0299FD
// Name: unknown_libname_1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
BOOL __cdecl unknown_libname_1(int a1)
{
  return a1 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F029A0A
// Name: __mbsnbicoll_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __noreturn _mbsnbicoll_l_0(
        const unsigned __int8 *Str1,
        const unsigned __int8 *Str2,
        size_t MaxCount,
        _locale_t Locale)
{
  _BYTE v4[16]; // [esp+4h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v4, a2: Locale);
}

//------------------------------------------------------------------------------
// Address: 0x3F029AF6
// Name: sub_3F029AF6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F029AF6(unsigned __int8 *Str1, unsigned __int8 *Str2, size_t MaxCount)
{
  _mbsnbicoll_l_0(Str1, Str2, MaxCount, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F029B0D
// Name: ___wtomb_environ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __wtomb_environ_0()
{
  LPCWCH *v0; // edi
  const wchar_t *v1; // eax
  const char *v2; // eax
  char *v3; // eax
  int cbMultiByte; // [esp+Ch] [ebp-8h]
  void *Block; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCWCH *)dword_3F03C7E0;
  Block = nullptr;
  v1 = *(const wchar_t **)dword_3F03C7E0;
  if ( *(_DWORD *)dword_3F03C7E0 == 0 )
    return 0;
  while ( 1 )
  {
    v2 = (const char *)WideCharToMultiByte(
                         CodePage: 0,
                         dwFlags: 0,
                         lpWideCharStr: v1,
                         cchWideChar: -1,
                         lpMultiByteStr: nullptr,
                         cbMultiByte: 0,
                         lpDefaultChar: nullptr,
                         lpUsedDefaultChar: nullptr);
    cbMultiByte = (int)v2;
    if ( v2 == nullptr )
      break;
    v3 = _calloc_crt_0(Size: v2, a2: 1);
    Block = v3;
    if ( v3 == nullptr )
      break;
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: *v0,
           cchWideChar: -1,
           lpMultiByteStr: v3,
           cbMultiByte,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(Block);
      return -1;
    }
    if ( (int)__crtsetenv_0(a1: &Block, a2: 0) < 0 && Block != nullptr )
    {
      free(Block);
      Block = nullptr;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F029E11
// Name: nullsub_15
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_15()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F029E12
// Name: sub_3F029E12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F029E12(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    *a1 = dword_3F03D28C;
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F029E46
// Name: ___initconout_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout_0()
{
  HANDLE result; // eax

  result = CreateFileA(
             lpFileName: "CONOUT$",
             dwDesiredAccess: 0x40000000u,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  hConsoleOutput = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F029E65
// Name: ___termcon_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termcon_0()
{
  HANDLE result; // eax

  if ( hConsoleOutput != (HANDLE)-1 && hConsoleOutput != (HANDLE)-2 )
    CloseHandle(hObject: hConsoleOutput);
  result = dword_3F03C0A4;
  if ( dword_3F03C0A4 != (HANDLE)-1 && dword_3F03C0A4 != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: dword_3F03C0A4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02A21B
// Name: ___crtCompareStringA_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtCompareStringA_0(int a1)
{
  _BYTE v1[16]; // [esp+0h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v1, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F02A25B
// Name: __strnicoll_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __noreturn _strnicoll_l_0(const char *String1, const char *String2, size_t MaxCount, _locale_t Locale)
{
  _BYTE v4[16]; // [esp+4h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v4, a2: Locale);
}

//------------------------------------------------------------------------------
// Address: 0x3F02A353
// Name: _findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall findenv@<eax>(size_t a1@<edi>, unsigned __int8 *Str1)
{
  if ( *(_DWORD *)dword_3F03C7D8 != 0 )
    sub_3F029AF6(Str1, Str2: *(unsigned __int8 **)dword_3F03C7D8, MaxCount: a1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F02A3A0
// Name: _copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall copy_environ@<eax>(_DWORD *a1@<edi>)
{
  char *result; // eax
  _DWORD *v2; // ecx
  char *v3; // esi
  const char *v4; // eax
  const char **v5; // ebx
  char *v6; // [esp+0h] [ebp-4h]

  result = nullptr;
  v2 = a1;
  if ( a1 != nullptr )
  {
    if ( *a1 != 0 )
    {
      do
      {
        ++v2;
        ++result;
      }
      while ( *v2 != 0 );
    }
    v3 = _calloc_crt_0(Size: result + 1, a2: 4);
    v6 = v3;
    if ( v3 == nullptr )
      raise(signum: 9u);
    v4 = (const char *)*a1;
    v5 = (const char **)a1;
    while ( v4 != nullptr )
    {
      *(_DWORD *)v3 = _strdup_0(Source: v4);
      v3 += 4;
      v4 = *++v5;
    }
    *(_DWORD *)v3 = 0;
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02A3FD
// Name: ___crtsetenv_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtsetenv_0(unsigned __int8 **a1)
{
  if ( a1 != nullptr )
  {
    if ( *a1 != nullptr )
      sub_3F02A753(Str: *a1, C: 0x3Du);
    *_errno_0() = 22;
    return -1;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F02A649
// Name: __strdup_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _strdup_0(const char *Source)
{
  size_t v2; // esi
  char *v3; // eax
  char *v4; // edi

  if ( Source == nullptr )
    return nullptr;
  v2 = ((int (__cdecl *)(const char *))loc_3F01E640)(a1: Source) + 1;
  v3 = (char *)malloc_0(Size: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  if ( strcpy_s_0(Destination: v3, SizeInBytes: v2, Source) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x3F02A699
// Name: __mbschr_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __noreturn _mbschr_l_0(const unsigned __int8 *Str, unsigned int C, _locale_t Locale)
{
  _BYTE v3[16]; // [esp+4h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, _locale_t))loc_3F01A0FA)(a1: v3, a2: Locale);
}

//------------------------------------------------------------------------------
// Address: 0x3F02A753
// Name: sub_3F02A753
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F02A753(unsigned __int8 *Str, unsigned int C)
{
  _mbschr_l_0(Str, C, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F02A766
// Name: RtlUnwind
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp_RtlUnwind(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x3F02A76C
// Name: nullsub_8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_8()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F02A7F0
// Name: __ftol2_sse_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_0@<eax>(double a1@<st0>)
{
  if ( dword_3F0A3884 != 0 )
    return (int)a1;
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F02A826
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
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
// Address: 0x3F02A966
// Name: _lh_continue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall lh_continue(int a1@<ebx>, int a2@<esi>)
{
  int v2; // edi

  while ( 1 )
  {
    v2 = *(_DWORD *)(a1 + 8);
    a2 = *(_DWORD *)(v2 + 12 * a2);
    if ( a2 == -1 )
      break;
    if ( *(_DWORD *)(v2 + 12 * a2 + 4) != 0 )
      JUMPOUT(0x3F02A90F);
  }
  JUMPOUT(0x3F02A982);
}

//------------------------------------------------------------------------------
// Address: 0x3F02A97B
// Name: _lh_abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall lh_abort@<eax>(int a1@<ebp>)
{
  *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4) |= 8u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F02A9A6
// Name: _seh_longjmp_unwind(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _seh_longjmp_unwind(int a1)
{
  return _local_unwind2_0(a1: *(_DWORD *)(a1 + 24), a2: *(_DWORD *)(a1 + 28));
}

//------------------------------------------------------------------------------
// Address: 0x3F02A9D0
// Name: __alldiv_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv_0(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

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
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F02AA80
// Name: __allshr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _allshr_0@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> 31;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> (a2 & 0x1F);
  }
  else
  {
    a1 >>= a2 & 0x1F;
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F02AAA1
// Name: __forcdecpt_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _forcdecpt_l_0(int a1, int a2)
{
  _BYTE v2[16]; // [esp+4h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v2, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F02AB12
// Name: __cropzeros_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _cropzeros_l_0(int a1, int a2)
{
  _BYTE v2[16]; // [esp+4h] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v2, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F02ABA8
// Name: __fassign_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _fassign_l_0(int a1, int a2, int a3, int a4)
{
  int v4; // [esp+0h] [ebp-8h] BYREF

  if ( a1 != 0 )
    sub_3F02BA82(a1: &v4, a2: a3, a3: a4);
  sub_3F02BB28(&a1, a2: a3, a3: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F02ABE8
// Name: sub_3F02ABE8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F02ABE8(int a1, int a2, int a3)
{
  _fassign_l_0(a1, a2, a3, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02ABFF
// Name: __shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall _shift@<eax>(char *result@<eax>, int a2@<edi>)
{
  char *v2; // esi
  int v3; // eax

  v2 = result;
  if ( a2 != 0 )
  {
    v3 = ((int (__cdecl *)(char *))loc_3F01E640)(a1: result);
    return (char *)memcpy_0(a1: &v2[a2], Src: v2, Size: v3 + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02AC1C
// Name: sub_3F02AC1C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F02AC1C(int a1)
{
  _forcdecpt_l_0(a1, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02AC2A
// Name: sub_3F02AC2A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F02AC2A(int a1)
{
  _cropzeros_l_0(a1, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02AC38
// Name: __cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _cftoe2_l(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _BYTE v6[16]; // [esp+Ch] [ebp-10h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v6, a2: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F02ADA5
// Name: __cftoe_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe_l_0(_DWORD *a1, _BYTE *a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  int v7; // eax
  int v8[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int v9[6]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2_0(a1: *a1, a2: a1[1], a3: (int)v8, a4: (int)v9, SizeInBytes: 0x16u);
  if ( a2 != nullptr && a3 != 0 )
  {
    if ( a3 == -1 )
      v7 = -1;
    else
      v7 = a3 - (v8[0] == 45) - (a4 > 0);
    result = _fptostr_0(a1: &a2[(v8[0] == 45) + (a4 > 0)], a2: v7, a3: a4 + 1, a4: (int)v8);
    if ( result == 0 )
      _cftoe2_l(a1: a3, a2: a4, a3: a5, a4: (int)v8, a5: 0, a6);
    *a2 = 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02AE73
// Name: sub_3F02AE73
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F02AE73(_DWORD *a1, _BYTE *a2, int a3, int a4, int a5)
{
  return _cftoe_l_0(a1, a2, a3, a4, a5, a6: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02AE91
// Name: __cftoa_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _cftoa_l_0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _BYTE v6[16]; // [esp+8h] [ebp-24h] BYREF
  int v7; // [esp+18h] [ebp-14h]
  int v8; // [esp+28h] [ebp-4h]

  v7 = 1023;
  v8 = 48;
  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v6, a2: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F02B8E0
// Name: sub_3F02B8E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02B8E0@<eax>(int a1@<ebp>)
{
  int v1; // eax
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // ecx
  int *v8; // edx
  int v9; // edx
  int *v10; // eax
  int v11; // ebx
  int v12; // esi
  int v13; // edi

  *(_DWORD *)(a1 - 4) = -2;
  if ( VirtualQuery(lpAddress: *(LPCVOID *)(a1 - 28), lpBuffer: (PMEMORY_BASIC_INFORMATION)(a1 - 64), dwLength: 0x1Cu) == 0 )
    return 1;
  v1 = *(_DWORD *)(a1 - 40);
  if ( v1 != 0x1000000 )
  {
    if ( v1 != 0x20000 )
      return -1;
    if ( dword_3F0A3644[0] == 0 )
    {
      VersionInformation.dwOSVersionInfoSize = 148;
      if ( GetVersionExA(lpVersionInformation: &VersionInformation) )
      {
        dword_3F0A3644[0] = 1;
      }
      else if ( dword_3F0A3644[0] == 0 )
      {
        goto LABEL_10;
      }
    }
    if ( VersionInformation.dwPlatformId != 1 )
      return -1;
  }
LABEL_10:
  v3 = *(_DWORD *)(a1 - 60);
  if ( !_ValidateImageBase_0(a1: v3) )
    return -1;
  if ( ((*(_BYTE *)(a1 - 44) & 0xCC) == 0
     || (v4 = ((int (__cdecl *)(int, int))_FindPESection_0)(a1: v3, a2: *(_DWORD *)(a1 - 28) - v3)) != 0
     && *(int *)(v4 + 36) >= 0)
    && ((int (__cdecl *)(_DWORD))ValidateScopeTableHandlers)(a1: *(_DWORD *)(a1 - 28)) != 0
    && ((int (__cdecl *)(int, int))_FindPESection_0)(a1: v3, a2: *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4) - v3) != 0 )
  {
    if ( _InterlockedExchange((volatile __int32 *)&unk_3F0A36C8, 1) == 0 )
    {
      v5 = dword_3F0A3640[0];
      v6 = dword_3F0A3640[0];
      v7 = *(_DWORD *)(a1 - 32);
      if ( dword_3F0A3640[0] > 0 )
      {
        v8 = &dword_3F0A3640[2 * dword_3F0A3640[0]];
        do
        {
          if ( *v8 == v7 )
            break;
          --v6;
          v8 -= 2;
        }
        while ( v6 > 0 );
      }
      if ( v6 != 0 )
      {
        dword_3F0A3644[2 * v6] = *(_DWORD *)(a1 - 60);
      }
      else
      {
        if ( dword_3F0A3640[0] > 15 )
          v5 = 15;
        v9 = *(_DWORD *)(a1 - 60);
        if ( v5 >= 0 )
        {
          v10 = &dword_3F0A3648;
          v11 = v5 + 1;
          do
          {
            v12 = *v10;
            v13 = v10[1];
            *v10 = v7;
            v10[1] = v9;
            v7 = v12;
            v9 = v13;
            v10 += 2;
            --v11;
          }
          while ( v11 != 0 );
        }
        if ( dword_3F0A3640[0] < 16 )
          ++dword_3F0A3640[0];
      }
      _InterlockedExchange((volatile __int32 *)&unk_3F0A36C8, 0);
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F02BA82
// Name: sub_3F02BA82
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F02BA82(int a1, int a2, int a3)
{
  _BYTE v3[32]; // [esp+10h] [ebp-24h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v3, a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F02BB28
// Name: sub_3F02BB28
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_3F02BB28(int a1, int a2, int a3)
{
  _BYTE v3[32]; // [esp+10h] [ebp-24h] BYREF

  ((void (__thiscall __noreturn *)(_BYTE *, int))loc_3F01A0FA)(a1: v3, a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F02BBCE
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
  int v12; // eax

  v4 = a4;
  v5 = *(char **)(a4 + 12);
  if ( a1 == nullptr || a2 == 0 )
  {
    v6 = 22;
    *_errno_0() = 22;
LABEL_3:
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
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
    v12 = ((int (__cdecl *)(char *))loc_3F01E640)(a1: a1 + 1);
    memcpy_0(a1, Src: a1 + 1, Size: v12 + 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F02BC8B
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
// Address: 0x3F02BD46
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
  v5[2] = ((int (__cdecl *)(int, int, __int16, int, _DWORD, __int16 *))_I10_OUTPUT_0)(
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
// Address: 0x3F02BED0
// Name: __CT??_R0?AVbad_exception@std@@@8??0bad_exception@std@@QAE@ABV01@@Z12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _CT___R0_AVbad_exception_std___8__0bad_exception_std__QAE_ABV01__Z12(char a1, unsigned int a2)
{
  return a2 >> (a1 & 0x1F);
}

//------------------------------------------------------------------------------
// Address: 0x3F02BEDA
// Name: RETZERO_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 RETZERO_0()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F02BEDF
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
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
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
// Address: 0x3F02C48B
// Name: sub_3F02C48B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F02C48B(unsigned __int16 *a1, unsigned int *a2)
{
  unsigned __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  unsigned int v55; // ebx
  unsigned int v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  unsigned int v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  unsigned int v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  int v68; // [esp+3Ch] [ebp+8h]
  unsigned int v69; // [esp+3Ch] [ebp+8h]
  int v70; // [esp+3Ch] [ebp+8h]
  int v71; // [esp+3Ch] [ebp+8h]
  int v72; // [esp+3Ch] [ebp+8h]
  int v73; // [esp+3Ch] [ebp+8h]
  int v74; // [esp+3Ch] [ebp+8h]

  v2 = a1[5];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)(a1 + 3);
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *a1 << 16;
  v61 = *(_DWORD *)(a1 + 1);
  v62 = v4;
  if ( v3 != -16383 )
  {
    v68 = 0;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = dword_3F03C4A0 - 1;
    v64 = v3;
    v65 = dword_3F03C4A0 / 32;
    v9 = &v60 + dword_3F03C4A0 / 32;
    v66 = 31 - dword_3F03C4A0 % 32;
    if ( ((1 << (31 - dword_3F03C4A0 % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - dword_3F03C4A0 % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      v69 = v13 + *v14;
      if ( v69 >= *v14 )
      {
        v15 = v69 < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = v69;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        v69 = v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      v68 = v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( v68 != 0 )
      ++v3;
    if ( v3 >= dword_3F03C49C - dword_3F03C4A0 )
    {
      if ( v3 > dword_3F03C49C )
      {
        if ( v3 < dword_3F03C498 )
        {
          v60 &= ~0x80000000;
          v5 = dword_3F03C4AC + v3;
          v50 = dword_3F03C4A4 / 32;
          v51 = dword_3F03C4A4 % 32;
          v65 = 0;
          v74 = 0;
          v67 = 32 - dword_3F03C4A4 % 32;
          do
          {
            v52 = *(&v60 + v74);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + v74++) = v65 | (v52 >> v51);
            v65 = v64 << v67;
          }
          while ( v74 < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = 0;
        }
        else
        {
          v61 = 0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = dword_3F03C4A4 / 32;
          v44 = dword_3F03C4A4 % 32;
          v65 = 0;
          v73 = 0;
          v67 = 32 - dword_3F03C4A4 % 32;
          do
          {
            v45 = (int *)(&v60 + v73);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            ++v73;
            v65 = v64 << v47;
          }
          while ( v73 < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = dword_3F03C4AC + dword_3F03C498;
          result = 1;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (dword_3F03C49C - v64) / 32;
      v62 = v59;
      v18 = (dword_3F03C49C - v64) % 32;
      v65 = 0;
      v70 = 0;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + v70);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        ++v70;
        v65 = v64 << v21;
      }
      while ( v70 < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = dword_3F03C4A0 - 1;
      v25 = dword_3F03C4A0 / 32;
      v65 = dword_3F03C4A0 / 32;
      v26 = &v60 + dword_3F03C4A0 / 32;
      v64 = 31 - dword_3F03C4A0 % 32;
      if ( ((1 << (31 - dword_3F03C4A0 % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - dword_3F03C4A0 % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        v71 = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          v71 = 1;
        *v30 = v31;
        for ( k = v71; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (dword_3F03C4A4 + 1) / 32;
      v37 = (dword_3F03C4A4 + 1) % 32;
      v65 = 0;
      v72 = 0;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + v72);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        ++v72;
        v65 = v64 << v40;
      }
      while ( v72 < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0;
      v62 = 0;
    }
    v5 = 0;
    result = 2;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = 0;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0;
  v62 = 0;
  result = 2;
LABEL_79:
  v55 = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - dword_3F03C4A4));
  if ( dword_3F03C4A8 == 64 )
  {
    v56 = v61;
    a2[1] = v55;
    *a2 = v56;
  }
  else if ( dword_3F03C4A8 == 32 )
  {
    *a2 = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02C9CD
// Name: ___strgtold12_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __strgtold12_l_0(int a1, char **a2, char *a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // ecx
  _BYTE *v9; // edi
  char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  char *v16; // edx
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  char *v24; // esi
  char v25; // al
  int v26; // eax
  char *v27; // eax
  char *v28; // ebx
  __int16 v29; // dx
  __int16 v30; // ax
  unsigned __int16 v31; // dx
  __int16 v32; // ax
  unsigned __int16 v33; // di
  int v34; // eax
  _WORD *v35; // esi
  unsigned int v36; // ecx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  __int16 v39; // di
  unsigned int v40; // ecx
  int v41; // esi
  int v42; // ecx
  int v43; // esi
  unsigned int v44; // ecx
  int v45; // ebx
  int v46; // ecx
  __int16 v47; // cx
  unsigned __int64 v48; // kr00_8
  __int16 v49; // ax
  int v50; // [esp-4h] [ebp-8Ch]
  int v51; // [esp-4h] [ebp-8Ch]
  int v52; // [esp+10h] [ebp-78h]
  __int16 v53; // [esp+14h] [ebp-74h]
  char *v54; // [esp+18h] [ebp-70h]
  int v55; // [esp+1Ch] [ebp-6Ch]
  int v56; // [esp+20h] [ebp-68h]
  int v57; // [esp+20h] [ebp-68h]
  int v58; // [esp+24h] [ebp-64h]
  int v59; // [esp+24h] [ebp-64h]
  int v60; // [esp+28h] [ebp-60h]
  unsigned __int16 *v61; // [esp+28h] [ebp-60h]
  int v62; // [esp+2Ch] [ebp-5Ch]
  unsigned __int16 *v63; // [esp+2Ch] [ebp-5Ch]
  int v64; // [esp+30h] [ebp-58h]
  int i; // [esp+30h] [ebp-58h]
  char *v66; // [esp+34h] [ebp-54h]
  int v67; // [esp+34h] [ebp-54h]
  int v68; // [esp+38h] [ebp-50h]
  int v69; // [esp+38h] [ebp-50h]
  unsigned int v70; // [esp+3Ch] [ebp-4Ch]
  char *v71; // [esp+3Ch] [ebp-4Ch]
  __int64 v72; // [esp+40h] [ebp-48h] BYREF
  int v73; // [esp+48h] [ebp-40h]
  _DWORD v74[7]; // [esp+4Ch] [ebp-3Ch] BYREF
  _BYTE v75[23]; // [esp+68h] [ebp-20h] BYREF
  char v76; // [esp+7Fh] [ebp-9h]

  v8 = 0;
  v9 = v75;
  v53 = 0;
  v56 = 1;
  v70 = 0;
  v64 = 0;
  v62 = 0;
  v60 = 0;
  v58 = 0;
  v68 = 0;
  v55 = 0;
  if ( a8 == 0 )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    return 0;
  }
  v11 = a3;
  v66 = a3;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == ***(_BYTE ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( v14 == 0 )
        {
          v53 = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( v15 == 0 )
        {
          v8 = 2;
          v53 = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_75;
        goto LABEL_19;
      case 1:
        v64 = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == ***(_BYTE ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_33;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (v13 <= 99 || v13 > 101) )
          goto LABEL_75;
        v51 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v50 = 3;
LABEL_12:
          v8 = v50;
          --v11;
        }
        else
        {
          if ( v13 == ***(_BYTE ***)(*(_DWORD *)a8 + 188) )
          {
LABEL_14:
            v51 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_37:
            v16 = v66;
            goto LABEL_82;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        v64 = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( v70 >= 0x19 )
          {
            ++v68;
          }
          else
          {
            ++v70;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != ***(_BYTE ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_46;
LABEL_24:
        v51 = 4;
        goto LABEL_15;
      case 4:
        v64 = 1;
        v62 = 1;
        if ( v70 == 0 )
        {
          while ( v13 == 48 )
          {
            --v68;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( v70 < 0x19 )
          {
            ++v70;
            *v9++ = v13 - 48;
            --v68;
          }
          v13 = *v11++;
        }
LABEL_46:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_33:
        --v11;
        v51 = 11;
        goto LABEL_15;
      case 5:
        v62 = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_37;
        v50 = 4;
        goto LABEL_12;
      case 6:
        v66 = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v17 = v13 - 43;
        if ( v17 == 0 )
          goto LABEL_70;
        v18 = v17 - 2;
        if ( v18 == 0 )
          goto LABEL_69;
        v19 = v18 == 3;
LABEL_67:
        if ( !v19 )
          goto LABEL_37;
        v51 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v19 = v13 == 48;
        goto LABEL_67;
      case 8:
        v60 = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_75;
LABEL_63:
        v50 = 9;
        goto LABEL_12;
      case 9:
        v60 = 1;
        v21 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v21 = 10 * v21 + v13 - 48;
            if ( v21 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v21 = 5201;
          }
          break;
        }
        v58 = v21;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_75:
        v16 = v11 - 1;
        goto LABEL_82;
      case 11:
        if ( a7 != 0 )
        {
          v20 = v13 - 43;
          v66 = v11 - 1;
          if ( v20 != 0 )
          {
            if ( v20 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_82;
            }
LABEL_69:
            v56 = -1;
            v8 = 7;
          }
          else
          {
LABEL_70:
            v51 = 7;
LABEL_15:
            v8 = v51;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_82:
        *a2 = v16;
        if ( v64 == 0 )
        {
          v55 = 4;
LABEL_174:
          v47 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_175;
        }
        if ( v70 > 0x18 )
        {
          if ( v76 >= 5 )
            ++v76;
          --v9;
          ++v68;
          v70 = 24;
        }
        if ( v70 == 0 )
          goto LABEL_174;
        while ( *--v9 == 0 )
        {
          --v70;
          ++v68;
        }
        __mtold12_0(a1: v75, a2: v70, a3: v74);
        v22 = v58;
        if ( v56 < 0 )
          v22 = -v58;
        v23 = v68 + v22;
        if ( v60 == 0 )
          v23 += a5;
        if ( v62 == 0 )
          v23 -= a6;
        if ( v23 > 5200 )
        {
          v49 = 0x7FFF;
          v47 = 0;
          v55 = 2;
          v48 = 0x8000000000000000uLL;
          goto LABEL_175;
        }
        if ( v23 < -5200 )
        {
          v55 = 1;
          goto LABEL_174;
        }
        v24 = (char *)&unk_3F03C4B0 - 96;
        v67 = v23;
        if ( v23 != 0 )
        {
          if ( v23 < 0 )
          {
            v67 = -v23;
            v24 = (char *)&unk_3F03C610 - 96;
          }
          if ( a4 == 0 )
            LOWORD(v74[0]) = 0;
          while ( v67 != 0 )
          {
            v25 = v67;
            v67 >>= 3;
            v24 += 84;
            v26 = v25 & 7;
            v71 = v24;
            if ( v26 != 0 )
            {
              v27 = &v24[12 * v26];
              v28 = v27;
              v54 = v27;
              if ( *(_WORD *)v27 >= 0x8000u )
              {
                v72 = *(_QWORD *)v27;
                v73 = *((_DWORD *)v27 + 2);
                --*(_DWORD *)((char *)&v72 + 2);
                v28 = (char *)&v72;
                v54 = (char *)&v72;
              }
              v29 = *((_WORD *)v28 + 5);
              v69 = 0;
              memset(&v74[4], 0, 12);
              v30 = HIWORD(v74[2]) ^ v29;
              v31 = v29 & 0x7FFF;
              v32 = v30 & 0x8000;
              v33 = v31 + (HIWORD(v74[2]) & 0x7FFF);
              if ( (HIWORD(v74[2]) & 0x7FFF) == 0x7FFF || v31 >= 0x7FFFu || v33 > 0xBFFDu )
              {
LABEL_167:
                v74[1] = 0;
                v34 = v32 != 0 ? -32768 : 2147450880;
                v74[0] = 0;
                goto LABEL_168;
              }
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                v74[1] = 0;
                v74[0] = 0;
LABEL_168:
                v74[2] = v34;
                continue;
              }
              if ( (v74[2] & 0x7FFF0000) != 0 || (++v33, (v74[2] & 0x7FFFFFFF) != 0) || v74[1] != 0 || v74[0] != 0 )
              {
                if ( v31 != 0
                  || (++v33, (*((_DWORD *)v28 + 2) & 0x7FFFFFFF) != 0)
                  || *((_DWORD *)v28 + 1) != 0
                  || *(_DWORD *)v28 != 0 )
                {
                  v57 = 0;
                  v35 = &v74[5];
                  for ( i = 5; i > 0; --i )
                  {
                    v59 = i;
                    v63 = (unsigned __int16 *)v74 + v57;
                    v61 = (unsigned __int16 *)(v28 + 8);
                    do
                    {
                      v52 = 0;
                      v36 = *v63 * *v61;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        v52 = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( v52 != 0 )
                        ++*v35;
                      ++v63;
                      --v61;
                      --v59;
                    }
                    while ( v59 > 0 );
                    v28 = v54;
                    ++v35;
                    ++v57;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_178;
                  do
                  {
                    if ( v74[6] < 0 )
                      break;
                    v40 = v74[4];
                    v74[4] *= 2;
                    v41 = (v40 >> 31) | (2 * v74[5]);
                    v42 = *(__int64 *)&v74[5] >> 31;
                    --v39;
                    v74[5] = v41;
                    v74[6] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_178:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v74[4] & 1) != 0 )
                          ++v69;
                        v44 = v74[6];
                        v74[6] >>= 1;
                        v45 = __SPAIR64__(v44, v74[5]) >> 1;
                        v46 = *(__int64 *)&v74[4] >> 1;
                        --v43;
                        v74[5] = v45;
                        v74[4] = v46;
                      }
                      while ( v43 != 0 );
                      if ( v69 != 0 )
                        LOWORD(v74[4]) |= 1u;
                    }
                  }
                  if ( LOWORD(v74[4]) > 0x8000u || (v74[4] & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)((char *)&v74[4] + 2) == -1 )
                    {
                      *(_DWORD *)((char *)&v74[4] + 2) = 0;
                      if ( *(_DWORD *)((char *)&v74[5] + 2) == -1 )
                      {
                        *(_DWORD *)((char *)&v74[5] + 2) = 0;
                        if ( HIWORD(v74[6]) == 0xFFFF )
                        {
                          HIWORD(v74[6]) = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++HIWORD(v74[6]);
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)((char *)&v74[5] + 2);
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)((char *)&v74[4] + 2);
                    }
                  }
                  v24 = v71;
                  if ( (unsigned __int16)v39 >= 0x7FFFu )
                    goto LABEL_167;
                  LOWORD(v74[0]) = HIWORD(v74[4]);
                  *(_QWORD *)((char *)v74 + 2) = *(_QWORD *)&v74[5];
                  HIWORD(v74[2]) = v32 | v39;
                }
                else
                {
                  memset(v74, 0, 12);
                }
              }
              else
              {
                HIWORD(v74[2]) = 0;
              }
            }
          }
        }
        v47 = v74[0];
        v48 = *(_QWORD *)((char *)v74 + 2);
        v49 = HIWORD(v74[2]);
LABEL_175:
        *(_WORD *)a1 = v47;
        *(_WORD *)(a1 + 10) = v53 | v49;
        *(_QWORD *)(a1 + 2) = v48;
        return v55;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F02D953
// Name: __hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _hw_cw@<eax>(int a1@<ebx>)
{
  int result; // eax
  int v2; // ecx

  result = (a1 & 0x10) != 0;
  if ( (a1 & 8) != 0 )
    result |= 4u;
  if ( (a1 & 4) != 0 )
    result |= 8u;
  if ( (a1 & 2) != 0 )
    result |= 0x10u;
  if ( (a1 & 1) != 0 )
    result |= 0x20u;
  if ( (a1 & 0x80000) != 0 )
    result |= 2u;
  v2 = a1 & 0x300;
  if ( (a1 & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 256:
        result |= 0x400u;
        break;
      case 512:
        result |= 0x800u;
        break;
      case 768:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (a1 & 0x30000) != 0 )
  {
    if ( (a1 & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (a1 & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02D9E1
// Name: ___hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall __hw_cw_sse2(int a1, int a2)
{
  int result; // eax
  int v3; // ecx
  int v4; // edx

  result = 0;
  if ( (a2 & 0x10) != 0 )
    result = 128;
  if ( (a2 & 8) != 0 )
    result |= 0x200u;
  if ( (a2 & 4) != 0 )
    result |= 0x400u;
  if ( (a2 & 2) != 0 )
    result |= 0x800u;
  if ( (a2 & 1) != 0 )
    result |= 0x1000u;
  if ( (a2 & 0x80000) != 0 )
    result |= 0x100u;
  v3 = a2 & 0x300;
  if ( (a2 & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 256:
        result |= 0x2000u;
        break;
      case 512:
        result |= 0x4000u;
        break;
      case 768:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = a2 & 0x3000000;
  switch ( v4 )
  {
    case 16777216:
      return result | 0x8040;
    case 33554432:
      return result | 0x40;
    case 50331648:
      return result | 0x8000;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02DA81
// Name: __control87_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87_0(unsigned int NewValue, unsigned int Mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v5; // ax
  __int16 v6; // bx
  unsigned int v7; // edx
  int v8; // eax
  __int16 v9; // ax
  int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  __int16 v16; // ax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  __int16 v22; // [esp+14h] [ebp-Ch]
  unsigned int v23; // [esp+1Ch] [ebp-4h]
  unsigned int Maska; // [esp+28h] [ebp+8h]

  v2 = 0;
  if ( (v22 & 1) != 0 )
    v2 = 16;
  if ( (v22 & 4) != 0 )
    v2 |= 8u;
  if ( (v22 & 8) != 0 )
    v2 |= 4u;
  if ( (v22 & 0x10) != 0 )
    v2 |= 2u;
  if ( (v22 & 0x20) != 0 )
    v2 |= 1u;
  if ( (v22 & 2) != 0 )
    v2 |= 0x80000u;
  v3 = v22 & 0xC00;
  if ( v3 != 0 )
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
  if ( (v22 & 0x300) != 0 )
  {
    if ( (v22 & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (v22 & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = Mask & NewValue | v2 & ~Mask;
  v23 = result;
  if ( result != v2 )
  {
    v5 = _hw_cw(a1: Mask & NewValue | v2 & ~Mask);
    v6 = v5;
    v7 = 0;
    if ( (v5 & 1) != 0 )
      v7 = 16;
    if ( (v5 & 4) != 0 )
      v7 |= 8u;
    if ( (v5 & 8) != 0 )
      v7 |= 4u;
    if ( (v5 & 0x10) != 0 )
      v7 |= 2u;
    if ( (v5 & 0x20) != 0 )
      v7 |= 1u;
    if ( (v5 & 2) != 0 )
      v7 |= 0x80000u;
    v8 = v5 & 0xC00;
    if ( (v6 & 0xC00) != 0 )
    {
      switch ( v8 )
      {
        case 1024:
          v7 |= 0x100u;
          break;
        case 2048:
          v7 |= 0x200u;
          break;
        case 3072:
          v7 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v6 & 0x300) != 0 )
    {
      if ( (v6 & 0x300) == 0x200 )
        v7 |= 0x10000u;
    }
    else
    {
      v7 |= 0x20000u;
    }
    if ( (v6 & 0x1000) != 0 )
      v7 |= 0x40000u;
    result = v7;
    v23 = v7;
  }
  if ( dword_3F0A3884 != 0 )
  {
    v9 = _mm_getcsr();
    v10 = 0;
    if ( (v9 & 0x80u) != 0 )
      v10 = 16;
    if ( (v9 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v9 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v9 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v9 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v9 & 0x100) != 0 )
      v10 |= 0x80000u;
    v11 = v9 & 0x6000;
    if ( (v9 & 0x6000) != 0 )
    {
      switch ( v11 )
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
    v12 = (v9 & 0x8040) - 64;
    if ( v12 != 0 )
    {
      v13 = v12 - 32704;
      if ( v13 != 0 )
      {
        if ( v13 == 64 )
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
    v14 = NewValue & Mask & 0x308031F | v10 & ~(Mask & 0x308031F);
    if ( v14 == v10 )
    {
      v15 = v10;
    }
    else
    {
      Maska = __hw_cw_sse2(a1: v11, a2: v14);
      __set_fpsr_sse2_0(a1: Maska);
      v16 = _mm_getcsr();
      v17 = 0;
      if ( (v16 & 0x80u) != 0 )
        v17 = 16;
      if ( (v16 & 0x200) != 0 )
        v17 |= 8u;
      if ( (v16 & 0x400) != 0 )
        v17 |= 4u;
      if ( (v16 & 0x800) != 0 )
        v17 |= 2u;
      if ( (v16 & 0x1000) != 0 )
        v17 |= 1u;
      if ( (v16 & 0x100) != 0 )
        v17 |= 0x80000u;
      v18 = v16 & 0x6000;
      if ( (v16 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v17 |= 0x100u;
            break;
          case 16384:
            v17 |= 0x200u;
            break;
          case 24576:
            v17 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v16 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v17 |= 0x1000000u;
        }
        else
        {
          v17 |= 0x3000000u;
        }
      }
      else
      {
        v17 |= 0x2000000u;
      }
      v15 = v17;
    }
    v21 = v23 ^ v15;
    result = v23 | v15;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02DD84
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
// Address: 0x3F02DF50
// Name: ___set_fpsr_sse2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __set_fpsr_sse2_0(unsigned int a1)
{
  int result; // eax

  result = 0;
  if ( dword_3F0A3884 != 0 )
  {
    if ( (a1 & 0x40) != 0 && dword_3F03C784 != 0 )
      _mm_setcsr(a1);
    else
      _mm_setcsr(a1 & 0xFFFFFFBF);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02DFD0
// Name: sub_3F02DFD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02DFD0()
{
  JUMPOUT(0x3F00E550);
}

//------------------------------------------------------------------------------
// Address: 0x3F02DFD8
// Name: sub_3F02DFD8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02DFD8(int a1, int a2)
{
  __security_check_cookie`...'(StackCookie: (a2 + 12) ^ *(_DWORD *)(a2 - 84));
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02DFF3
// Name: sub_3F02DFF3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02DFF3(int a1, int a2)
{
  __security_check_cookie`...'(StackCookie: (a2 + 12) ^ *(_DWORD *)(a2 - 20));
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E010
// Name: sub_3F02E010
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E010(int a1@<ebp>)
{
  sub_3F01D197(this: (void *)(a1 - 28));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E018
// Name: sub_3F02E018
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E018(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E030
// Name: sub_3F02E030
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E030(int a1@<ebp>)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 - 16) + 16;
  if ( *(_DWORD *)(*(_DWORD *)(a1 - 16) + 20) != 0 )
  {
    j__free(Block: *(void **)(*(_DWORD *)(a1 - 16) + 20));
    *(_DWORD *)(v1 + 4) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F02E03B
// Name: ??1CVProfNode@@QAE@XZ_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfNode::~CVProfNode(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E050
// Name: sub_3F02E050
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E050(int a1@<ebp>)
{
  CThreadMutex::~CThreadMutex(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E058
// Name: ??1CVProfManager@@QAE@XZ_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfManager::~CVProfManager(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E070
// Name: sub_3F02E070
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E070()
{
  unsigned int result; // eax

  result = dword_3F041AA4 & 0xFFFFFFFE;
  dword_3F041AA4 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E07E
// Name: sub_3F02E07E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E07E(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E090
// Name: sub_3F02E090
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E090(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E0A0
// Name: sub_3F02E0A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E0A0(int a1@<ebp>)
{
  CThreadMutex::~CThreadMutex(lpCriticalSection: (LPCRITICAL_SECTION)(*(_DWORD *)(a1 - 16) + 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E0AB
// Name: ??0CThread@@QAE@XZ_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CThread::CThread(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E0C0
// Name: sub_3F02E0C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E0C0(int a1@<ebp>)
{
  CThreadLocalBase::~CThreadLocalBase(this: *(CThreadLocalBase **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E0C8
// Name: sub_3F02E0C8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E0C8(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E0E0
// Name: sub_3F02E0E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E0E0(int a1@<ebp>)
{
  sub_3F01D197(this: *(void **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E0E8
// Name: sub_3F02E0E8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E0E8(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E100
// Name: sub_3F02E100
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E100(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E110
// Name: j__Warning
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void j__Warning(const char *pMsgFormat, ...)
{
  Warning();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E115
// Name: sub_3F02E115
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E115(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E120
// Name: j__Warning_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void j__Warning_0(const char *pMsgFormat, ...)
{
  Warning();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E125
// Name: sub_3F02E125
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E125(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E130
// Name: sub_3F02E130
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E130(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E140
// Name: SEH_3F00D470
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F00D470(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E150
// Name: sub_3F02E150
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E150(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E160
// Name: sub_3F02E160
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E160(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E170
// Name: sub_3F02E170
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E170(int a1@<ebp>)
{
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E178
// Name: ?SetName@CThread@@QAEXPBD@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CThread::SetName(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E190
// Name: sub_3F02E190
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E190()
{
  JUMPOUT(0x3F001E60);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E198
// Name: sub_3F02E198
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E198(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E1B0
// Name: sub_3F02E1B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E1B0()
{
  unsigned int result; // eax

  result = dword_3F041BB4 & 0xFFFFFFFE;
  dword_3F041BB4 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E1BE
// Name: sub_3F02E1BE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E1BE()
{
  unsigned int result; // eax

  result = dword_3F041BB4 & 0xFFFFFFFD;
  dword_3F041BB4 &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E1CC
// Name: SEH_3F002350
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F002350(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E1E0
// Name: sub_3F02E1E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E1E0()
{
  unsigned int result; // eax

  result = dword_3F041BC8 & 0xFFFFFFFE;
  dword_3F041BC8 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E1EE
// Name: SEH_3F0022C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F0022C0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E200
// Name: sub_3F02E200
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E200()
{
  unsigned int result; // eax

  result = dword_3F041BD0 & 0xFFFFFFFE;
  dword_3F041BD0 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E20E
// Name: sub_3F02E20E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E20E(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E220
// Name: sub_3F02E220
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E220()
{
  JUMPOUT(0x3F001E60);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E228
// Name: SEH_3F002AB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F002AB0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E240
// Name: sub_3F02E240
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E240(int a1@<ebp>)
{
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E248
// Name: ?GetAllThreadProfiles@CVProfManager@@QAEXPAVCVProfileArray@@@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfManager::GetAllThreadProfiles(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E260
// Name: sub_3F02E260
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E260(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E270
// Name: sub_3F02E270
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E270@<eax>(int a1@<ebp>)
{
  int result; // eax
  int v2; // ecx
  _DWORD *v3; // esi

  v3 = (_DWORD *)(a1 - 20);
  result = *(_DWORD *)(a1 - 20);
  if ( result != 0 )
  {
    v2 = v3[1];
    if ( v2 != 0 )
    {
      result = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 8))(a1: v2, a2: *v3);
      v3[1] = 0;
      *v3 = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E278
// Name: SEH_3F009A40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F009A40(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E290
// Name: sub_3F02E290
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E290()
{
  return sub_3F0042E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E29B
// Name: sub_3F02E29B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E29B(int a1@<ebp>)
{
  `eh vector destructor iterator'(
    a1: (char *)(*(_DWORD *)(a1 - 16) + 48),
    a2: 0x18u,
    a3: 16,
    a4: (void (__thiscall *)(void *))Plat_RegisterThread);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E2B1
// Name: sub_3F02E2B1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E2B1(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E2C0
// Name: sub_3F02E2C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E2C0()
{
  return sub_3F0042E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E2CB
// Name: sub_3F02E2CB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E2CB(int a1@<ebp>)
{
  `eh vector destructor iterator'(
    a1: (char *)(*(_DWORD *)(a1 - 16) + 48),
    a2: 0x18u,
    a3: 256,
    a4: (void (__thiscall *)(void *))Plat_RegisterThread);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E2E4
// Name: SEH_3F007360
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F007360(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E2F0
// Name: sub_3F02E2F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E2F0()
{
  return sub_3F0042E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E2F8
// Name: SEH_3F007110
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F007110(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E310
// Name: sub_3F02E310
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E310(int a1@<ebp>)
{
  sub_3F007110(a1: *(CSmallBlockHeap **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E31A
// Name: sub_3F02E31A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E31A()
{
  return sub_3F0042E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E322
// Name: sub_3F02E322
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E322(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E330
// Name: sub_3F02E330
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E330(int a1@<ebp>)
{
  `eh vector destructor iterator'(a1: (char *)(*(_DWORD *)(a1 + 8) + 1024), a2: 0x28u, a3: 38, a4: loc_3F0070D0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E348
// Name: SEH_3F005E60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F005E60(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E360
// Name: sub_3F02E360
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall sub_3F02E360(CVProfile *a1@<ecx>, int a2@<ebp>)
{
  int v2; // [esp-Ch] [ebp-Ch]
  const char *v3; // [esp-8h] [ebp-8h]
  bool v4; // [esp-4h] [ebp-4h]

  sub_3F005ED0(this: a1, a2: *(_DWORD *)(a2 - 16) + 8, a3: v2, a4: v3, a5: v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E36D
// Name: sub_3F02E36D
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E36D@<eax>(int a1@<ebp>)
{
  return ((int (__stdcall *)(int))loc_3F0066C0)(a1: *(_DWORD *)(a1 - 16) + 2560);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E37C
// Name: sub_3F02E37C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E37C@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(int))loc_3F007000)(a1: *(_DWORD *)(a1 - 16) + 5112);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E38B
// Name: sub_3F02E38B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E38B(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E3A0
// Name: sub_3F02E3A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E3A0()
{
  unsigned int result; // eax

  result = dword_3F0A3600 & 0xFFFFFFFE;
  dword_3F0A3600 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E3AE
// Name: sub_3F02E3AE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E3AE@<eax>(int a1@<ebp>)
{
  int result; // eax

  result = *(_DWORD *)(a1 - 16);
  if ( (*(_DWORD *)(result + 4))-- == 1 )
    _InterlockedExchange((volatile __int32 *)result, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E3B6
// Name: sub_3F02E3B6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E3B6(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E3C0
// Name: sub_3F02E3C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E3C0(int a1@<ebp>)
{
  sub_3F01D197(this: *(void **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E3C8
// Name: sub_3F02E3C8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E3C8()
{
  JUMPOUT(0x3F00E550);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E3D3
// Name: SEH_3F00E4A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F00E4A0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E3E0
// Name: sub_3F02E3E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E3E0@<eax>(int a1@<ebp>)
{
  return sub_3F00E4A0(a1: *(_DWORD *)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E3E8
// Name: SEH_3F00BD30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F00BD30(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E400
// Name: sub_3F02E400
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E400(int a1@<ebp>)
{
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 - 24));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E408
// Name: ?EnableDumpSpikes@CVProfManager@@QAEXH@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfManager::EnableDumpSpikes(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E420
// Name: sub_3F02E420
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E420(int a1@<ebp>)
{
  j__free(Block: *(void **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E42B
// Name: unknown_libname_2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void __usercall unknown_libname_2(int a1@<ebp>)
{
  j__free(Block: *(void **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E436
// Name: sub_3F02E436
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E436(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E440
// Name: sub_3F02E440
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E440()
{
  JUMPOUT(0x3F00E550);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E448
// Name: sub_3F02E448
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E448()
{
  JUMPOUT(0x3F00E550);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E453
// Name: sub_3F02E453
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E453(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E460
// Name: sub_3F02E460
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E460()
{
  JUMPOUT(0x3F00E550);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E468
// Name: sub_3F02E468
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E468@<eax>(int a1@<ebp>)
{
  return sub_3F00E4A0(a1: a1 - 56);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E470
// Name: sub_3F02E470
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E470(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E480
// Name: sub_3F02E480
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E480(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E490
// Name: SEH_3F00C2D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F00C2D0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E4A0
// Name: sub_3F02E4A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E4A0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E4B0
// Name: sub_3F02E4B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E4B0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E4C0
// Name: sub_3F02E4C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E4C0()
{
  JUMPOUT(0x3F00E550);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E4C8
// Name: sub_3F02E4C8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E4C8@<eax>(int a1@<ebp>)
{
  return sub_3F00E4A0(a1: a1 - 84);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E4D0
// Name: sub_3F02E4D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E4D0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E4E0
// Name: sub_3F02E4E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E4E0()
{
  return sub_3F00C3E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E4E8
// Name: sub_3F02E4E8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E4E8(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E500
// Name: sub_3F02E500
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E500@<eax>(int a1@<ebp>)
{
  int result; // eax

  result = *(_DWORD *)(a1 - 28);
  if ( (*(_DWORD *)(result + 4))-- == 1 )
    _InterlockedExchange((volatile __int32 *)result, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E508
// Name: ?RegisterCallbackHandler@CVProfile@@QAEXPAVIVProfileCallbackHandler@@@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfile::RegisterCallbackHandler(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E520
// Name: sub_3F02E520
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E520@<eax>(int a1@<ebp>)
{
  return sub_3F00EA10(a1: *(_DWORD *)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E52A
// Name: SEH_3F00E9B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F00E9B0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E550
// Name: sub_3F02E550
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E550(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E568
// Name: sub_3F02E568
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E568(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E580
// Name: sub_3F02E580
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E580()
{
  return sub_3F0042E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E58B
// Name: SEH_3F007660
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F007660(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E5A0
// Name: sub_3F02E5A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E5A0()
{
  return sub_3F0042E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E5AB
// Name: sub_3F02E5AB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E5AB(int a1@<ebp>)
{
  `eh vector destructor iterator'(
    a1: (char *)(*(_DWORD *)(a1 - 16) + 48),
    a2: 0x18u,
    a3: 0x4000,
    a4: (void (__thiscall *)(void *))Plat_RegisterThread);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E5C4
// Name: sub_3F02E5C4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E5C4(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E5D0
// Name: sub_3F02E5D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E5D0()
{
  unsigned int result; // eax

  result = dword_3F0A3608 & 0xFFFFFFFE;
  dword_3F0A3608 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E5DE
// Name: sub_3F02E5DE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E5DE(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E5F0
// Name: sub_3F02E5F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E5F0()
{
  unsigned int result; // eax

  result = dword_3F0A360C & 0xFFFFFFFE;
  dword_3F0A360C &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E5FE
// Name: sub_3F02E5FE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E5FE(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E610
// Name: sub_3F02E610
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E610(int a1@<ebp>)
{
  sub_3F007110(a1: *(CSmallBlockHeap **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E61A
// Name: sub_3F02E61A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E61A(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E630
// Name: sub_3F02E630
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E630()
{
  unsigned int result; // eax

  result = dword_3F0A3610 & 0xFFFFFFFE;
  dword_3F0A3610 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E63E
// Name: SEH_3F007150
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F007150(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E650
// Name: sub_3F02E650
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E650()
{
  JUMPOUT(0x3F0029A0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E658
// Name: sub_3F02E658
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E658(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E670
// Name: SEH_3F00C230
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F00C230(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E680
// Name: sub_3F02E680
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E680(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E690
// Name: sub_3F02E690
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E690()
{
  return sub_3F00C2C0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E698
// Name: sub_3F02E698
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E698(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E6B0
// Name: sub_3F02E6B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F02E6B0(
        void *a1,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        const unsigned __int8 *a5,
        unsigned int a6)
{
  return j_VCR_Hook_RegSetValueEx(hKey: a1, lpValueName: a2, Reserved: a3, dwType: a4, lpData: a5, cbData: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E6B8
// Name: sub_3F02E6B8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E6B8@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(int))loc_3F00AA70)(a1: *(_DWORD *)(a1 - 16) + 2616);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E6C7
// Name: sub_3F02E6C7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E6C7()
{
  return sub_3F00C2C0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E6CF
// Name: sub_3F02E6CF
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E6CF@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(int))loc_3F00AAB0)(a1: *(_DWORD *)(a1 - 16) + 2628);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E6DE
// Name: sub_3F02E6DE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E6DE()
{
  return sub_3F00C3E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E6EC
// Name: sub_3F02E6EC
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E6EC()
{
  return sub_3F00C3E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E6FA
// Name: ??0CVProfile@@QAE@ABV0@@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfile::CVProfile(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E710
// Name: SEH_3F009E40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F009E40(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E720
// Name: sub_3F02E720
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F02E720(
        void *a1,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        const unsigned __int8 *a5,
        unsigned int a6)
{
  return j_VCR_Hook_RegSetValueEx(hKey: a1, lpValueName: a2, Reserved: a3, dwType: a4, lpData: a5, cbData: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E728
// Name: sub_3F02E728
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E728(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E740
// Name: sub_3F02E740
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E740(int a1@<ebp>)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 - 20) + 16;
  if ( *(_DWORD *)(*(_DWORD *)(a1 - 20) + 20) != 0 )
  {
    j__free(Block: *(void **)(*(_DWORD *)(a1 - 20) + 20));
    *(_DWORD *)(v1 + 4) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F02E74B
// Name: ?Term@CVProfile@@QAEXXZ_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfile::Term(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E760
// Name: sub_3F02E760
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E760@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(int))loc_3F00AA70)(a1: *(_DWORD *)(a1 - 16) + 2616);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E76F
// Name: sub_3F02E76F
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02E76F@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(int))loc_3F00AAB0)(a1: *(_DWORD *)(a1 - 16) + 2628);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E77E
// Name: sub_3F02E77E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E77E()
{
  return sub_3F00C3E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E78C
// Name: sub_3F02E78C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E78C()
{
  return sub_3F00C3E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E79A
// Name: sub_3F02E79A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02E79A()
{
  return sub_3F00C2C0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E7A2
// Name: sub_3F02E7A2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F02E7A2(
        void *a1,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        const unsigned __int8 *a5,
        unsigned int a6)
{
  return j_VCR_Hook_RegSetValueEx(hKey: a1, lpValueName: a2, Reserved: a3, dwType: a4, lpData: a5, cbData: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E7AA
// Name: sub_3F02E7AA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E7AA(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E7C0
// Name: sub_3F02E7C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E7C0(int a1@<ebp>)
{
  sub_3F0125E0(a1: (_BYTE *)(a1 + 11));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E7CA
// Name: sub_3F02E7CA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E7CA(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E7E0
// Name: sub_3F02E7E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E7E0(int a1@<ebp>)
{
  sub_3F0125E0(a1: (_BYTE *)(a1 - 14));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E7EA
// Name: SEH_3F0131F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F0131F0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E800
// Name: sub_3F02E800
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E800(int a1@<ebp>)
{
  sub_3F0125E0(a1: (_BYTE *)(a1 - 13));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E80A
// Name: SEH_3F013BC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F013BC0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E820
// Name: sub_3F02E820
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E820(int a1@<ebp>)
{
  sub_3F0125E0(a1: (_BYTE *)(a1 - 17));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E82A
// Name: sub_3F02E82A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E82A()
{
  unsigned int result; // eax

  result = dword_3F0A3620 & 0xFFFFFFFE;
  dword_3F0A3620 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E838
// Name: sub_3F02E838
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E838()
{
  unsigned int result; // eax

  result = dword_3F0A3620 & 0xFFFFFFFD;
  dword_3F0A3620 &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E846
// Name: sub_3F02E846
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E846(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E850
// Name: j__Warning_1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void j__Warning_1(const char *pMsgFormat, ...)
{
  Warning();
}

//------------------------------------------------------------------------------
// Address: 0x3F02E855
// Name: sub_3F02E855
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E855(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E860
// Name: sub_3F02E860
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E860()
{
  JUMPOUT(0x3F00E580);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E868
// Name: ?Validate@CVProfManager@@QAEXAAVCValidator@@PBD@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfManager::Validate(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E880
// Name: sub_3F02E880
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E880()
{
  unsigned int result; // eax

  result = dword_3F0A360C & 0xFFFFFFFE;
  dword_3F0A360C &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E88E
// Name: sub_3F02E88E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E88E()
{
  unsigned int result; // eax

  result = dword_3F0A360C & 0xFFFFFFFE;
  dword_3F0A360C &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E89C
// Name: sub_3F02E89C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E89C()
{
  unsigned int result; // eax

  result = dword_3F0A360C & 0xFFFFFFFE;
  dword_3F0A360C &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E8AA
// Name: sub_3F02E8AA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E8AA()
{
  unsigned int result; // eax

  result = dword_3F0A360C & 0xFFFFFFFE;
  dword_3F0A360C &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E8B8
// Name: sub_3F02E8B8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E8B8(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E8D0
// Name: sub_3F02E8D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E8D0()
{
  unsigned int result; // eax

  result = dword_3F0A3610 & 0xFFFFFFFE;
  dword_3F0A3610 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E8DE
// Name: sub_3F02E8DE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E8DE()
{
  unsigned int result; // eax

  result = dword_3F0A3610 & 0xFFFFFFFE;
  dword_3F0A3610 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E8EC
// Name: sub_3F02E8EC
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E8EC()
{
  unsigned int result; // eax

  result = dword_3F0A3610 & 0xFFFFFFFE;
  dword_3F0A3610 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E8FA
// Name: sub_3F02E8FA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F02E8FA()
{
  unsigned int result; // eax

  result = dword_3F0A3610 & 0xFFFFFFFE;
  dword_3F0A3610 &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02E908
// Name: sub_3F02E908
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E908(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E920
// Name: sub_3F02E920
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E920(int a1@<ebp>)
{
  CThreadMutex::~CThreadMutex(lpCriticalSection: (LPCRITICAL_SECTION)(*(_DWORD *)(a1 - 20) + 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E92B
// Name: sub_3F02E92B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E92B(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E940
// Name: sub_3F02E940
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E940(int a1@<ebp>)
{
  CThreadSyncObject::~CThreadSyncObject(this: *(CThreadSyncObject **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E948
// Name: ??0CThreadFullMutex@@QAE@_NPBD@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CThreadFullMutex::CThreadFullMutex(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E960
// Name: sub_3F02E960
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E960(int a1@<ebp>)
{
  CThreadSyncObject::~CThreadSyncObject(this: *(CThreadSyncObject **)(a1 - 28));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E968
// Name: ??0CThreadEvent@@QAE@PBD_N1@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CThreadEvent::CThreadEvent(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E980
// Name: sub_3F02E980
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E980(int a1@<ebp>)
{
  CThreadSyncObject::~CThreadSyncObject(this: *(CThreadSyncObject **)(a1 - 20));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E988
// Name: sub_3F02E988
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E988(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E9A0
// Name: sub_3F02E9A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E9A0(int a1@<ebp>)
{
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 - 276));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E9AB
// Name: sub_3F02E9AB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E9AB(int a1@<ebp>)
{
  j__free(Block: *(void **)(a1 - 280));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E9B9
// Name: ?AddProfileForThread@CVProfManager@@QAEPAVCVProfileThreadEntry@@PAVCVProfile@@K@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfManager::AddProfileForThread(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E9D0
// Name: sub_3F02E9D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E9D0(int a1@<ebp>)
{
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 - 20));
}

//------------------------------------------------------------------------------
// Address: 0x3F02E9D8
// Name: sub_3F02E9D8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02E9D8(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E9F0
// Name: sub_3F02E9F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02E9F0()
{
  JUMPOUT(0x3F010940);
}

//------------------------------------------------------------------------------
// Address: 0x3F02E9F8
// Name: sub_3F02E9F8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02E9F8(int a1@<ebp>)
{
  CThreadSemaphore::~CThreadSemaphore(this: (CThreadSemaphore *)(*(_DWORD *)(a1 - 16) + 88));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA03
// Name: sub_3F02EA03
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02EA03(int a1@<ebp>)
{
  CThreadSemaphore::~CThreadSemaphore(this: (CThreadSemaphore *)(*(_DWORD *)(a1 - 16) + 96));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA0E
// Name: ??0CWorkerThread@@QAE@XZ_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CWorkerThread::CWorkerThread(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA20
// Name: sub_3F02EA20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02EA20(int a1@<ebp>)
{
  CThreadSemaphore::~CThreadSemaphore(this: (CThreadSemaphore *)(*(_DWORD *)(a1 - 16) + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA2B
// Name: sub_3F02EA2B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02EA2B(int a1@<ebp>)
{
  CThreadSemaphore::~CThreadSemaphore(this: (CThreadSemaphore *)(*(_DWORD *)(a1 - 16) + 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA36
// Name: ??0CThreadRWLock@@QAE@XZ_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CThreadRWLock::CThreadRWLock(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA40
// Name: sub_3F02EA40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02EA40@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(int))loc_3F00AA70)(a1: *(_DWORD *)(a1 - 16) + 2616);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA4F
// Name: sub_3F02EA4F
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02EA4F@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(int))loc_3F00AAB0)(a1: *(_DWORD *)(a1 - 16) + 2628);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA5E
// Name: sub_3F02EA5E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EA5E()
{
  return sub_3F00C3E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA6C
// Name: sub_3F02EA6C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EA6C()
{
  return sub_3F00C3E0();
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA7A
// Name: unknown_libname_3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void __usercall unknown_libname_3(int a1@<ebp>)
{
  j__free(Block: *(void **)(a1 - 20));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA85
// Name: sub_3F02EA85
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02EA85(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA90
// Name: unknown_libname_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void __usercall unknown_libname_4(int a1@<ebp>)
{
  j__free(Block: *(void **)(a1 - 16));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EA9B
// Name: CreateVProfile_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CreateVProfile_SEH(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EAB0
// Name: sub_3F02EAB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02EAB0(int a1)
{
  JUMPOUT(0x3F011800);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EAB8
// Name: sub_3F02EAB8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02EAB8(int a1@<ebp>)
{
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EAC0
// Name: ?ThreadProc@CThread@@CGIPAX@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CThread::ThreadProc(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EAD0
// Name: sub_3F02EAD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02EAD0(int a1@<ebp>)
{
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 - 532));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EADB
// Name: sub_3F02EADB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02EADB(int a1@<ebp>)
{
  CThreadSemaphore::~CThreadSemaphore(this: (CThreadSemaphore *)(a1 - 544));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EAE6
// Name: ?Start@CThread@@QAE_NI@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CThread::Start(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EAF0
// Name: sub_3F02EAF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F02EAF0@<eax>(int a1@<ebp>)
{
  int result; // eax

  result = *(_DWORD *)(a1 - 68);
  if ( (*(_DWORD *)(result + 4))-- == 1 )
    _InterlockedExchange((volatile __int32 *)result, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02EAF8
// Name: ?OutputReport@CVProfile@@QAEXHPBDH@Z_SEH
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CVProfile::OutputReport(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB10
// Name: sub_3F02EB10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02EB10(int a1@<ebp>)
{
  j__free(Block: *(void **)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB1B
// Name: sub_3F02EB1B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02EB1B(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB30
// Name: sub_3F02EB30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F02EB30(int a1@<ebp>)
{
  LeaveCriticalSection(lpCriticalSection: *(LPCRITICAL_SECTION *)(a1 - 532));
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB3B
// Name: sub_3F02EB3B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F02EB3B(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB50
// Name: sub_3F02EB50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02EB50()
{
  CThreadLocalBase::~CThreadLocalBase(this: (CThreadLocalBase *)dwTlsIndex);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB5A
// Name: SEH_3F02ED00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F02ED00(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB70
// Name: sub_3F02EB70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02EB70()
{
  CThreadLocalBase::~CThreadLocalBase(this: (CThreadLocalBase *)&g_VProfile);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB7A
// Name: SEH_3F02EE20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F02EE20(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB90
// Name: sub_3F02EB90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02EB90()
{
  CThreadMutex::~CThreadMutex(lpCriticalSection: &g_VProfManager);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EB9A
// Name: SEH_3F02EFA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SEH_3F02EFA0(int a1, int a2)
{
  JUMPOUT(0x3F01E79E);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EBB0
// Name: sub_3F02EBB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EBB0()
{
  int v0; // eax
  int result; // eax
  double v2; // st7

  v0 = ((int (*)(void))GetCPUInformation)();
  LODWORD(g_ClockSpeed) = *(_DWORD *)(v0 + 8);
  result = *(_DWORD *)(v0 + 12);
  HIDWORD(g_ClockSpeed) = result;
  v2 = (double)g_ClockSpeed;
  g_dwClockSpeed = g_ClockSpeed;
  g_ClockSpeedMicrosecondsMultiplier = 1000000.0 / v2;
  g_ClockSpeedMillisecondsMultiplier = 1000.0 / v2;
  g_ClockSpeedSecondsMultiplier = 1.0 / v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02EC00
// Name: sub_3F02EC00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int sub_3F02EC00()
{
  int v1; // [esp-4h] [ebp-4h]

  ((void (__stdcall *)(int))loc_3F0044C0)(a1: v1);
  return atexit_0(a1: sub_3F02EE80);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EC20
// Name: sub_3F02EC20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EC20()
{
  InitializeCriticalSectionAndSpinCount(lpCriticalSection: &CriticalSection, dwSpinCount: 0xFA0u);
  word_3F03F27C = 0;
  dword_3F03F278 = 0;
  byte_3F03F27E = 0;
  return atexit_0(a1: sub_3F02EEC0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EC50
// Name: sub_3F02EC50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EC50()
{
  return atexit_0(a1: sub_3F02EED0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EC60
// Name: sub_3F02EC60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EC60()
{
  InitializeCriticalSection(lpCriticalSection: &stru_3F03D2EC);
  return atexit_0(a1: sub_3F02EF10);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EC80
// Name: sub_3F02EC80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EC80()
{
  dword_3F0415C0 = GetCurrentThreadId();
  dword_3F0415BC = 0;
  hEvent = nullptr;
  dword_3F0415B4 = nullptr;
  hObject = nullptr;
  return atexit_0(a1: sub_3F02EF20);
}

//------------------------------------------------------------------------------
// Address: 0x3F02ECB0
// Name: sub_3F02ECB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD sub_3F02ECB0()
{
  DWORD result; // eax

  ThreadSetDebugName(a1: 0xFFFFFFFF, a2: (ULONG_PTR)&__initialmbcinfo.mbcasemap[95]);
  result = GetCurrentThreadId();
  dword_3F0415CC = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02ECD0
// Name: sub_3F02ECD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE sub_3F02ECD0()
{
  HMODULE result; // eax

  result = LoadLibraryA(lpLibFileName: "Kernel32.dll");
  if ( result != nullptr )
  {
    result = (HMODULE)GetProcAddress(hModule: result, lpProcName: "TryEnterCriticalSection");
    dword_3F0415D0 = (int (__stdcall *)(_DWORD))result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F02ED00
// Name: sub_3F02ED00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02ED00()
{
  int v1; // [esp+0h] [ebp-Ch]
  const char *v2; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  CThreadLocalBase::CThreadLocalBase(this: (CThreadLocalBase *)dwTlsIndex, a2: v1, a3: v2, a4: v3);
  return atexit_0(a1: (void (__cdecl *)())CVProfile::RegisterNumBudgetGroupsChangedCallBack);
}

//------------------------------------------------------------------------------
// Address: 0x3F02ED50
// Name: sub_3F02ED50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02ED50()
{
  InitializeCriticalSection(lpCriticalSection: &stru_3F03D340);
  return atexit_0(a1: sub_3F02EF80);
}

//------------------------------------------------------------------------------
// Address: 0x3F02ED70
// Name: sub_3F02ED70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02ED70()
{
  InitializeCriticalSection(lpCriticalSection: &stru_3F03D328);
  return atexit_0(a1: sub_3F02EF90);
}

//------------------------------------------------------------------------------
// Address: 0x3F02ED90
// Name: sub_3F02ED90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F02ED90()
{
  g_VProfProfilesRunningCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F02EDA0
// Name: sub_3F02EDA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EDA0()
{
  InitializeCriticalSectionAndSpinCount(lpCriticalSection: &g_VProfManager, dwSpinCount: 0xFA0u);
  word_3F0415FC = 0;
  dword_3F0415F8 = 0;
  byte_3F0415FE = 0;
  memset(&unk_3F041600, 0, 0x400u);
  dbl_3F041A00 = 0.0;
  return atexit_0(a1: sub_3F02EFA0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EE20
// Name: sub_3F02EE20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EE20()
{
  int v1; // [esp+0h] [ebp-Ch]
  const char *v2; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  CThreadLocalBase::CThreadLocalBase(this: (CThreadLocalBase *)&g_VProfile, a2: v1, a3: v2, a4: v3);
  return atexit_0(a1: sub_3F02EFE0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EE70
// Name: sub_3F02EE70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F02EE70()
{
  dword_3F041A0C = 0;
  dword_3F041A10 = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F02EE80
// Name: sub_3F02EE80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl sub_3F02EE80()
{
  JUMPOUT(0x3F0045D0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EE90
// Name: sub_3F02EE90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F02EE90(void *this)
{
  ((void (__cdecl *)(void *))loc_3F007600)(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EEA0
// Name: sub_3F02EEA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F02EEA0(void *this)
{
  Test_RunFrame(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EEB0
// Name: sub_3F02EEB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F02EEB0(void *this)
{
  ((void (__cdecl *)(void *))loc_3F007400)(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EEC0
// Name: sub_3F02EEC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F02EEC0()
{
  DeleteCriticalSection(lpCriticalSection: &CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EED0
// Name: sub_3F02EED0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F02EED0()
{
  if ( byte_3F03F280 != 0 )
  {
    byte_3F03F280 = 0;
    dword_3F03F284 = 0;
    dword_3F03F288 = 0;
    if ( dword_3F03F28C != nullptr )
      FreeLibrary(hLibModule: dword_3F03F28C);
    dword_3F03F28C = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F02EF10
// Name: sub_3F02EF10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F02EF10()
{
  DeleteCriticalSection(lpCriticalSection: &stru_3F03D2EC);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EF20
// Name: sub_3F02EF20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F02EF20()
{
  if ( byte_3F0415B8 != 0 )
  {
    byte_3F0415B9 = 1;
    SetEvent(hEvent: hEvent);
    WaitForSingleObject(hHandle: hObject, dwMilliseconds: 0x64u);
    CloseHandle(hObject: hObject);
    CloseHandle(hObject: hEvent);
    CloseHandle(hObject: dword_3F0415B4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F02EF70
// Name: j_?RegisterNumBudgetGroupsChangedCallBack@CVProfile@@QAEXP6AXXZ@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge CVProfile::RegisterNumBudgetGroupsChangedCallBack(
        CVProfile *this@<ecx>,
        void (__cdecl *pCallBack)(),
        CounterGroup_t a3)
{
  ?RegisterNumBudgetGroupsChangedCallBack@CVProfile@@QAEXP6AXXZ@Z_0(this, pCallBack, a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EF80
// Name: sub_3F02EF80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F02EF80()
{
  DeleteCriticalSection(lpCriticalSection: &stru_3F03D340);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EF90
// Name: sub_3F02EF90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F02EF90()
{
  DeleteCriticalSection(lpCriticalSection: &stru_3F03D328);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EFA0
// Name: sub_3F02EFA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F02EFA0()
{
  DeleteCriticalSection(lpCriticalSection: &g_VProfManager);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EFE0
// Name: sub_3F02EFE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl sub_3F02EFE0()
{
  JUMPOUT(0x3F0164A0);
}

//------------------------------------------------------------------------------
// Address: 0x3F02EFE5
// Name: sub_3F02EFE5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F02EFE5()
{
  stru_3F03C7A0.__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
  sub_3F01D197(this: &stru_3F03C7A0);
}

} // namespace tier0_s
