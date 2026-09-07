// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/bugreporter_filequeue/bugreporter.cpp
// Functions: 102
// ============================================================

#include "utils\bugreporter_filequeue\bugreporter.h"

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: GetLocalUserEmailAddress
// Source: json
//------------------------------------------------------------------------------
void __usercall GetLocalUserEmailAddress(CUtlString *email@<edi>, CUtlString *username)
{
  const char *v2; // esi
  char *v3; // eax
  const char *v4; // ebx
  char *v5; // eax
  char *v6; // eax

  v2 = getenv(option: "username");
  v3 = getenv(option: "userdnsdomain");
  v4 = v3;
  if ( v2 != nullptr && v3 != nullptr )
  {
    CUtlString::operator=(this: username, src: v2);
    v5 = CUtlString::Get(this: username);
    _V_strlower(start: v5);
    CUtlString::operator=(this: email, src: v2);
    CUtlString::operator+=(this: email, rhs: "@");
    CUtlString::operator+=(this: email, rhs: v4);
    v6 = CUtlString::Get(this: email);
    _V_strlower(start: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100010B0
// Name: public: virtual char const __near * CBugReporter::GetUserNameA(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetUserNameA(CBugReporter *this)
{
  return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_LocalMachineUserName);
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: public: virtual char const __near * CBugReporter::GetUserDisplayName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetUserDisplayName(CBugReporter *this)
{
  CBugReporter_vtbl *v2; // edi
  const char *v3; // eax

  v2 = this->__vftable;
  v3 = this->GetUserNameA_2(this);
  return v2->GetDisplayNameForUserName(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100010F0
// Name: public: virtual int CBugReporter::GetNameCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetNameCount(CBugReporter *this)
{
  return this->GetDisplayNameCount(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: public: virtual char const __near * CBugReporter::GetName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetName(CBugReporter *this, int index)
{
  return this->GetDisplayName(this, a2: index);
}

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: public: virtual char const __near * CBugReporter::GetRepositoryURL(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBugReporter::GetRepositoryURL(CBugReporter *this)
{
  return this->m_BugRootDirectory;
}

//------------------------------------------------------------------------------
// Address: 0x10001120
// Name: public: virtual char const __near * CBugReporter::GetSubmissionURL(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBugReporter::GetSubmissionURL(CBugReporter *this)
{
  return this->m_CurrentBugDirectory;
}

//------------------------------------------------------------------------------
// Address: 0x10001130
// Name: public: virtual int CBugReporter::GetLevelOwnerCount(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetLevelOwnerCount(CBugReporter *this, int area)
{
  return this->GetLevelCount(this, a2: area);
}

//------------------------------------------------------------------------------
// Address: 0x10001140
// Name: public: virtual void CBugReporter::SetTitle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetTitle(CBugReporter *this, const char *title)
{
  CUtlBuffer::PutString(this: &this->m_pBug->title, pString: title);
}

//------------------------------------------------------------------------------
// Address: 0x10001150
// Name: public: virtual void CBugReporter::SetDescription(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetDescription(CBugReporter *this, const char *description)
{
  CUtlBuffer::PutString(this: &this->m_pBug->desc, pString: description);
}

//------------------------------------------------------------------------------
// Address: 0x10001170
// Name: public: virtual void CBugReporter::SetSubmitter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetSubmitter(CBugReporter *this, const char *username)
{
  const char *v2; // eax

  v2 = username;
  if ( username == nullptr )
    v2 = this->GetUserNameA_2(this);
  CUtlBuffer::PutString(this: &this->m_pBug->submitter, pString: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100011A0
// Name: public: virtual void CBugReporter::SetOwner(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetOwner(CBugReporter *this, const char *username)
{
  CUtlBuffer::PutString(this: &this->m_pBug->owner, pString: username);
}

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: public: virtual void CBugReporter::SetSeverity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetSeverity(CBugReporter *this, const char *severity)
{
  CUtlBuffer::PutString(this: &this->m_pBug->severity, pString: severity);
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: public: virtual void CBugReporter::SetPriority(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetPriority(CBugReporter *this, const char *priority)
{
  CUtlBuffer::PutString(this: &this->m_pBug->priority, pString: priority);
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: public: virtual void CBugReporter::SetMapNumber(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetMapNumber(CBugReporter *this, const char *mapnumber)
{
  CUtlBuffer::PutString(this: &this->m_pBug->mapnumber, pString: mapnumber);
}

//------------------------------------------------------------------------------
// Address: 0x10001220
// Name: public: virtual void CBugReporter::SetReportType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetReportType(CBugReporter *this, const char *report_type)
{
  CUtlBuffer::PutString(this: &this->m_pBug->report_type, pString: report_type);
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: virtual void CBugReporter::SetLevel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetLevel(CBugReporter *this, const char *levelnamne)
{
  CUtlBuffer::PutString(this: &this->m_pBug->level, pString: levelnamne);
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: public: virtual void CBugReporter::SetDriverInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetDriverInfo(CBugReporter *this, const char *info)
{
  CUtlBuffer::PutString(this: &this->m_pBug->driverinfo, pString: info);
}

//------------------------------------------------------------------------------
// Address: 0x10001280
// Name: public: virtual void CBugReporter::SetMiscInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetMiscInfo(CBugReporter *this, const char *info)
{
  CUtlBuffer::PutString(this: &this->m_pBug->misc, pString: info);
}

//------------------------------------------------------------------------------
// Address: 0x100012A0
// Name: public: virtual void CBugReporter::SetPosition(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetPosition(CBugReporter *this, const char *position)
{
  CUtlBuffer::PutString(this: &this->m_pBug->position, pString: position);
}

//------------------------------------------------------------------------------
// Address: 0x100012C0
// Name: public: virtual void CBugReporter::SetOrientation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetOrientation(CBugReporter *this, const char *pitch_yaw_roll)
{
  CUtlBuffer::PutString(this: &this->m_pBug->orientation, pString: pitch_yaw_roll);
}

//------------------------------------------------------------------------------
// Address: 0x100012E0
// Name: public: virtual void CBugReporter::SetBuildNumber(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetBuildNumber(CBugReporter *this, const char *build_num)
{
  CUtlBuffer::PutString(this: &this->m_pBug->build, pString: build_num);
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: public: virtual void CBugReporter::SetScreenShot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetScreenShot(CBugReporter *this, const char *screenshot_unc_address)
{
  CUtlBuffer::PutString(this: &this->m_pBug->screenshot_unc, pString: screenshot_unc_address);
}

//------------------------------------------------------------------------------
// Address: 0x10001320
// Name: public: virtual void CBugReporter::SetSaveGame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetSaveGame(CBugReporter *this, const char *savegame_unc_address)
{
  CUtlBuffer::PutString(this: &this->m_pBug->savegame_unc, pString: savegame_unc_address);
}

//------------------------------------------------------------------------------
// Address: 0x10001340
// Name: public: virtual void CBugReporter::SetBSPName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetBSPName(CBugReporter *this, const char *bsp_unc_address)
{
  CUtlBuffer::PutString(this: &this->m_pBug->bsp_unc, pString: bsp_unc_address);
}

//------------------------------------------------------------------------------
// Address: 0x10001360
// Name: public: virtual void CBugReporter::SetVMFName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetVMFName(CBugReporter *this, const char *vmf_unc_address)
{
  CUtlBuffer::PutString(this: &this->m_pBug->vmf_unc, pString: vmf_unc_address);
}

//------------------------------------------------------------------------------
// Address: 0x10001380
// Name: public: virtual void CBugReporter::SetOSVersion(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetOSVersion(CBugReporter *this, const char *osversion)
{
  CUtlBuffer::PutString(this: &this->m_pBug->osversion, pString: osversion);
}

//------------------------------------------------------------------------------
// Address: 0x100013A0
// Name: public: virtual void CBugReporter::SetConsoleHistory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetConsoleHistory(CBugReporter *this, const char *pchText)
{
  CUtlBuffer::PutString(this: &this->m_pBug->console, pString: pchText);
}

//------------------------------------------------------------------------------
// Address: 0x100013D0
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
// Address: 0x10001460
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
// Address: 0x100014F0
// Name: bool CUtlSymbol_LessThan(class CUtlSymbol const __near &,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CUtlSymbol_LessThan(const CUtlSymbol *sym1, const CUtlSymbol *sym2)
{
  CBugReporter *v2; // esi
  const char *v3; // edi
  const char *v4; // eax

  v2 = g_bugreporter;
  v3 = CUtlSymbolTable::String(this: &g_bugreporter->m_BugStrings, id: (CUtlSymbol)sym1->m_Id);
  v4 = CUtlSymbolTable::String(this: &v2->m_BugStrings, id: (CUtlSymbol)sym2->m_Id);
  return _V_stricmp(s1: v3, s2: v4) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001540
// Name: public: virtual int CBugReporter::GetDisplayNameCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetDisplayNameCount(CBugReporter *this)
{
  return this->m_SortedDisplayNames.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001550
// Name: public: virtual int CBugReporter::GetSeverityCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetSeverityCount(CBugReporter *this)
{
  return this->m_Severity.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001560
// Name: public: virtual int CBugReporter::GetPriorityCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetPriorityCount(CBugReporter *this)
{
  return this->m_Priority.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001570
// Name: public: virtual int CBugReporter::GetAreaCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetAreaCount(CBugReporter *this)
{
  return this->m_Area.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: public: virtual int CBugReporter::GetAreaMapCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetAreaMapCount(CBugReporter *this)
{
  return this->m_AreaMap.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001590
// Name: public: virtual int CBugReporter::GetMapNumberCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetMapNumberCount(CBugReporter *this)
{
  return this->m_MapNumber.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100015A0
// Name: public: virtual int CBugReporter::GetReportTypeCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetReportTypeCount(CBugReporter *this)
{
  return this->m_ReportType.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100015B0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001660
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1002323C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1002323C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100016C0
// Name: public: virtual char const __near * CBugReporter::GetDisplayName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetDisplayName(CBugReporter *this, int index)
{
  if ( index < 0 || index >= this->m_SortedDisplayNames.m_Size )
    return "<<Invalid>>";
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_SortedDisplayNames.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x10001700
// Name: public: virtual char const __near * CBugReporter::GetUserNameA(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetUserNameA(CBugReporter *this, int index)
{
  if ( index < 0 || index >= this->m_SortedUserNames.m_Size )
    return "<<Invalid>>";
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_SortedUserNames.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x10001740
// Name: public: virtual char const __near * CBugReporter::GetDisplayNameForUserName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetDisplayNameForUserName(CBugReporter *this, const char *username)
{
  int m_Size; // edx
  int v4; // eax
  CUtlSymbol *i; // ecx

  CUtlSymbolTable::Find(this: &this->m_BugStrings, result: (CUtlSymbol *)&username, pString: username);
  m_Size = this->m_SortedUserNames.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return str;
  for ( i = this->m_SortedUserNames.m_Memory.m_pMemory; i->m_Id != (_WORD)username; ++i )
  {
    if ( ++v4 >= m_Size )
      return str;
  }
  return this->GetDisplayName(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10001790
// Name: public: virtual char const __near * CBugReporter::GetUserNameForDisplayName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetUserNameForDisplayName(CBugReporter *this, const char *display)
{
  int m_Size; // edx
  int v4; // eax
  CUtlSymbol *i; // ecx

  CUtlSymbolTable::Find(this: &this->m_BugStrings, result: (CUtlSymbol *)&display, pString: display);
  m_Size = this->m_SortedDisplayNames.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return str;
  for ( i = this->m_SortedDisplayNames.m_Memory.m_pMemory; i->m_Id != (_WORD)display; ++i )
  {
    if ( ++v4 >= m_Size )
      return str;
  }
  return this->GetUserNameA(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100017E0
// Name: private: char const __near * CBugReporter::GetAreaMapForArea(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetAreaMapForArea(CBugReporter *this, const char *area)
{
  int m_Size; // ecx
  int v4; // eax
  CUtlSymbol *i; // edx

  CUtlSymbolTable::Find(this: &this->m_BugStrings, result: (CUtlSymbol *)&area, pString: area);
  m_Size = this->m_Area.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return "<<Invalid>>";
  for ( i = this->m_Area.m_Memory.m_pMemory; i->m_Id != (_WORD)area || v4 < 0; ++i )
  {
    if ( ++v4 >= m_Size )
      return "<<Invalid>>";
  }
  return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_AreaMap.m_Memory.m_pMemory[v4]) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: public: virtual char const __near * CBugReporter::GetSeverity(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetSeverity(CBugReporter *this, int index)
{
  if ( index < 0 || index >= this->m_Severity.m_Size )
    return "<<Invalid>>";
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_Severity.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: public: virtual char const __near * CBugReporter::GetPriority(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetPriority(CBugReporter *this, int index)
{
  if ( index < 0 || index >= this->m_Priority.m_Size )
    return "<<Invalid>>";
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_Priority.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x100018D0
// Name: public: virtual char const __near * CBugReporter::GetArea(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetArea(CBugReporter *this, int index)
{
  if ( index < 0 || index >= this->m_Area.m_Size )
    return "<<Invalid>>";
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_Area.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x10001910
// Name: public: virtual char const __near * CBugReporter::GetAreaMap(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetAreaMap(CBugReporter *this, int index)
{
  if ( index < 0 || index >= this->m_AreaMap.m_Size )
    return "<<Invalid>>";
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_AreaMap.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x10001950
// Name: public: virtual char const __near * CBugReporter::GetMapNumber(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetMapNumber(CBugReporter *this, int index)
{
  if ( index < 0 || index >= this->m_MapNumber.m_Size )
    return "<<Invalid>>";
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_MapNumber.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x10001990
// Name: public: virtual char const __near * CBugReporter::GetReportType(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetReportType(CBugReporter *this, int index)
{
  if ( index < 0 || index >= this->m_ReportType.m_Size )
    return "<<Invalid>>";
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: this->m_ReportType.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: public: virtual void CBugReporter::SetArea(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetArea(CBugReporter *this, const char *area)
{
  const char *AreaMapForArea; // eax

  AreaMapForArea = CBugReporter::GetAreaMapForArea(this, area);
  CUtlBuffer::PutString(this: &this->m_pBug->area, pString: AreaMapForArea);
}

//------------------------------------------------------------------------------
// Address: 0x10001A00
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1002323C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10001A60
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1002323C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10001AC0
// Name: protected: void CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t *insert,
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
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001BB0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  int result; // eax

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        v9 = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    this->m_LastAlloc.index = v6;
    result = v6;
  }
  else
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Elements.m_pMemory[m_FirstFree].m_Right;
  }
  if ( &this->m_Elements.m_pMemory[(unsigned __int16)result] != (UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *)-8 )
    this->m_Elements.m_pMemory[(unsigned __int16)result].m_Data.key.m_Id = -1;
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001CD0
// Name: protected: void CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10001DC0
// Name: protected: void CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10001EB0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10001FB0
// Name: public: void CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x10002060
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
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x100020D0
// Name: protected: void CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1002323C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002323C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002323C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002323C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002323C = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002323C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002323C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002323C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002323C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002323C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1002323C = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002323C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1002323C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100026C0
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
// Address: 0x10002730
// Name: public: CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x100027A0
// Name: public: virtual int CBugReporter::GetLevelCount(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetLevelCount(CBugReporter *this, int area)
{
  unsigned __int16 m_Id; // ax
  CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short> *p_m_LevelMap; // edi
  unsigned __int16 v4; // ax
  int v5; // ebx
  CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  CBugReporter *v8; // [esp+14h] [ebp-4h]

  m_Id = this->m_AreaMap.m_Memory.m_pMemory[area].m_Id;
  v8 = this;
  p_m_LevelMap = &this->m_LevelMap;
  search.key.m_Id = m_Id;
  v4 = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_LevelMap.m_Tree,
         &search);
  v5 = v4;
  if ( v4 >= p_m_LevelMap->m_Tree.m_Elements.m_nAllocationCount
    || v4 > p_m_LevelMap->m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &p_m_LevelMap->m_Tree,
         i: v4) == v4 )
  {
    return 0;
  }
  else
  {
    return v8->m_LevelMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002820
// Name: public: virtual char const __near * CBugReporter::GetLevel(int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetLevel(CBugReporter *this, int area, int index)
{
  unsigned __int16 v4; // ax
  int v5; // esi
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *elem; // esi
  CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  search.key.m_Id = this->m_AreaMap.m_Memory.m_pMemory[area].m_Id;
  v4 = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_LevelMap.m_Tree,
         &search);
  v5 = v4;
  if ( v4 >= this->m_LevelMap.m_Tree.m_Elements.m_nAllocationCount )
    return str;
  if ( v4 > this->m_LevelMap.m_Tree.m_LastAlloc.index )
    return str;
  if ( CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &this->m_LevelMap.m_Tree,
         i: v4) == v4 )
    return str;
  elem = this->m_LevelMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
  if ( index < 0 || index >= elem->m_Size )
    return str;
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: elem->m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x100028C0
// Name: public: virtual char const __near * CBugReporter::GetLevelOwner(int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetLevelOwner(CBugReporter *this, int area, int index)
{
  unsigned __int16 v4; // ax
  int v5; // esi
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *elem; // esi
  CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  search.key.m_Id = this->m_AreaMap.m_Memory.m_pMemory[area].m_Id;
  v4 = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_OwnerMap.m_Tree,
         &search);
  v5 = v4;
  if ( v4 >= this->m_OwnerMap.m_Tree.m_Elements.m_nAllocationCount )
    return str;
  if ( v4 > this->m_OwnerMap.m_Tree.m_LastAlloc.index )
    return str;
  if ( CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &this->m_OwnerMap.m_Tree,
         i: v4) == v4 )
    return str;
  elem = this->m_OwnerMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
  if ( index < 0 || index >= elem->m_Size )
    return str;
  else
    return CUtlSymbolTable::String(this: &this->m_BugStrings, id: elem->m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x10002960
// Name: public: virtual void CBugReporter::AddIncludedFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::AddIncludedFile(CBugReporter *this, const char *filename)
{
  const CUtlString *v3; // eax
  CUtlString v4; // [esp+4h] [ebp-10h] BYREF

  v3 = CUtlString::CUtlString(this: &v4, pString: filename);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
    this: &this->m_pBug->includedfiles,
    elem: this->m_pBug->includedfiles.m_Size,
    src: v3);
  v4.m_Storage.m_nActualLength = 0;
  if ( v4.m_Storage.m_Memory.m_nGrowSize >= 0 && v4.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100029C0
// Name: private: bool CBugReporter::PopulateChoiceList(char const __near *,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::PopulateChoiceList(
        CBugReporter *this,
        const char *listname,
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *list)
{
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // ebx
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *v6; // esi
  const char *Name; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v11; // eax
  CUtlSymbol *v12; // eax
  CUtlSymbolTable *p_m_BugStrings; // [esp+8h] [ebp-4h]

  Key = KeyValues::FindKey(this: this->m_OptionsFile, keyName: listname, bCreate: false);
  FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
  if ( FirstSubKey != nullptr )
  {
    p_m_BugStrings = &this->m_BugStrings;
    v6 = list;
    do
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      CUtlSymbolTable::AddString(this: p_m_BugStrings, result: (CUtlSymbol *)&listname, pString: Name);
      m_Size = v6->m_Size;
      m_nAllocationCount = v6->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUtlSymbol,int>::Grow(this: &v6->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++v6->m_Size;
      m_pMemory = v6->m_Memory.m_pMemory;
      v11 = v6->m_Size - m_Size - 1;
      v6->m_pElements = v6->m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v11);
      v12 = &v6->m_Memory.m_pMemory[m_Size];
      if ( v12 != nullptr )
        v12->m_Id = (unsigned __int16)listname;
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    }
    while ( FirstSubKey != nullptr );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002A70
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
// Address: 0x10002AE0
// Name: public: CBugReporter::CBugReporter(void)
// Source: json
//------------------------------------------------------------------------------
CBugReporter *__thiscall CBugReporter::CBugReporter(CBugReporter *this)
{
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  this->__vftable = (CBugReporter_vtbl *)&CBugReporter::`vftable';
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_BugStrings, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_Severity.m_Memory.m_pMemory = nullptr;
  this->m_Severity.m_Memory.m_nAllocationCount = 0;
  this->m_Severity.m_Memory.m_nGrowSize = 0;
  this->m_Severity.m_Size = 0;
  this->m_Severity.m_pElements = nullptr;
  this->m_SortedDisplayNames.m_Memory.m_pMemory = nullptr;
  this->m_SortedDisplayNames.m_Memory.m_nAllocationCount = 0;
  this->m_SortedDisplayNames.m_Memory.m_nGrowSize = 0;
  this->m_SortedDisplayNames.m_Size = 0;
  this->m_SortedDisplayNames.m_pElements = nullptr;
  this->m_SortedUserNames.m_Memory.m_pMemory = nullptr;
  this->m_SortedUserNames.m_Memory.m_nAllocationCount = 0;
  this->m_SortedUserNames.m_Memory.m_nGrowSize = 0;
  this->m_SortedUserNames.m_Size = 0;
  this->m_SortedUserNames.m_pElements = nullptr;
  this->m_Priority.m_Memory.m_pMemory = nullptr;
  this->m_Priority.m_Memory.m_nAllocationCount = 0;
  this->m_Priority.m_Memory.m_nGrowSize = 0;
  this->m_Priority.m_Size = 0;
  this->m_Priority.m_pElements = nullptr;
  this->m_Area.m_Memory.m_pMemory = nullptr;
  this->m_Area.m_Memory.m_nAllocationCount = 0;
  this->m_Area.m_Memory.m_nGrowSize = 0;
  this->m_Area.m_Size = 0;
  this->m_Area.m_pElements = nullptr;
  this->m_AreaMap.m_Memory.m_pMemory = nullptr;
  this->m_AreaMap.m_Memory.m_nAllocationCount = 0;
  this->m_AreaMap.m_Memory.m_nGrowSize = 0;
  this->m_AreaMap.m_Size = 0;
  this->m_AreaMap.m_pElements = nullptr;
  this->m_MapNumber.m_Memory.m_pMemory = nullptr;
  this->m_MapNumber.m_Memory.m_nAllocationCount = 0;
  this->m_MapNumber.m_Memory.m_nGrowSize = 0;
  this->m_MapNumber.m_Size = 0;
  this->m_MapNumber.m_pElements = nullptr;
  this->m_ReportType.m_Memory.m_pMemory = nullptr;
  this->m_ReportType.m_Memory.m_nAllocationCount = 0;
  this->m_ReportType.m_Memory.m_nGrowSize = 0;
  this->m_ReportType.m_Size = 0;
  this->m_ReportType.m_pElements = nullptr;
  this->m_LevelMap.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_LevelMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_LevelMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_LevelMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_LevelMap.m_Tree.m_pElements = this->m_LevelMap.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_LevelMap.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_LevelMap.m_Tree.m_FirstFree = -1;
  this->m_OwnerMap.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_OwnerMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_OwnerMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_OwnerMap.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_OwnerMap.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_OwnerMap.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_OwnerMap.m_Tree.m_FirstFree = -1;
  this->m_OwnerMap.m_Tree.m_pElements = m_pMemory;
  this->m_LocalMachineUserName.m_Id = -1;
  CUtlString::CUtlString(this: &this->m_EngineExportedDefaultUsername);
  this->m_pBug = nullptr;
  this->m_CurrentBugID = 0;
  this->m_bMountedBugSub = false;
  if ( this->m_LevelMap.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_LevelMap.m_Tree.m_LessFunc.m_LessFunc = CUtlSymbol_LessThan;
  if ( this->m_OwnerMap.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_OwnerMap.m_Tree.m_LessFunc.m_LessFunc = CUtlSymbol_LessThan;
  g_bugreporter = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002C80
// Name: public: virtual void CBugReporter::SetDXVersion(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetDXVersion(
        CBugReporter *this,
        unsigned int high,
        unsigned int low,
        unsigned int vendor,
        unsigned int device)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10002C90
// Name: public: virtual void CBugReporter::SetSteamUserID(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetSteamUserID(CBugReporter *this, void *steamid, void *idsize)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10002CA0
// Name: public: void CBug::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBug::Clear(CBug *this)
{
  CUtlString *m_pMemory; // ecx

  this->title.m_Get = 0;
  this->title.m_Put = 0;
  this->title.m_Error = 0;
  this->title.m_nOffset = 0;
  this->title.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->title, nPut: 0);
  this->desc.m_Get = 0;
  this->desc.m_Put = 0;
  this->desc.m_Error = 0;
  this->desc.m_nOffset = 0;
  this->desc.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->desc, nPut: 0);
  this->submitter.m_Get = 0;
  this->submitter.m_Put = 0;
  this->submitter.m_Error = 0;
  this->submitter.m_nOffset = 0;
  this->submitter.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->submitter, nPut: 0);
  this->owner.m_Get = 0;
  this->owner.m_Put = 0;
  this->owner.m_Error = 0;
  this->owner.m_nOffset = 0;
  this->owner.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->owner, nPut: 0);
  this->severity.m_Get = 0;
  this->severity.m_Put = 0;
  this->severity.m_Error = 0;
  this->severity.m_nOffset = 0;
  this->severity.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->severity, nPut: 0);
  this->priority.m_Get = 0;
  this->priority.m_Put = 0;
  this->priority.m_Error = 0;
  this->priority.m_nOffset = 0;
  this->priority.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->priority, nPut: 0);
  this->area.m_Get = 0;
  this->area.m_Put = 0;
  this->area.m_Error = 0;
  this->area.m_nOffset = 0;
  this->area.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->area, nPut: 0);
  this->mapnumber.m_Get = 0;
  this->mapnumber.m_Put = 0;
  this->mapnumber.m_Error = 0;
  this->mapnumber.m_nOffset = 0;
  this->mapnumber.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->mapnumber, nPut: 0);
  this->report_type.m_Get = 0;
  this->report_type.m_Put = 0;
  this->report_type.m_Error = 0;
  this->report_type.m_nOffset = 0;
  this->report_type.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->report_type, nPut: 0);
  this->level.m_Get = 0;
  this->level.m_Put = 0;
  this->level.m_Error = 0;
  this->level.m_nOffset = 0;
  this->level.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->level, nPut: 0);
  this->build.m_Get = 0;
  this->build.m_Put = 0;
  this->build.m_Error = 0;
  this->build.m_nOffset = 0;
  this->build.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->build, nPut: 0);
  this->position.m_Get = 0;
  this->position.m_Put = 0;
  this->position.m_Error = 0;
  this->position.m_nOffset = 0;
  this->position.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->position, nPut: 0);
  this->orientation.m_Get = 0;
  this->orientation.m_Put = 0;
  this->orientation.m_Error = 0;
  this->orientation.m_nOffset = 0;
  this->orientation.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->orientation, nPut: 0);
  this->screenshot_unc.m_Get = 0;
  this->screenshot_unc.m_Put = 0;
  this->screenshot_unc.m_Error = 0;
  this->screenshot_unc.m_nOffset = 0;
  this->screenshot_unc.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->screenshot_unc, nPut: 0);
  this->savegame_unc.m_Get = 0;
  this->savegame_unc.m_Put = 0;
  this->savegame_unc.m_Error = 0;
  this->savegame_unc.m_nOffset = 0;
  this->savegame_unc.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->savegame_unc, nPut: 0);
  this->bsp_unc.m_Get = 0;
  this->bsp_unc.m_Put = 0;
  this->bsp_unc.m_Error = 0;
  this->bsp_unc.m_nOffset = 0;
  this->bsp_unc.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->bsp_unc, nPut: 0);
  this->vmf_unc.m_Get = 0;
  this->vmf_unc.m_Put = 0;
  this->vmf_unc.m_Error = 0;
  this->vmf_unc.m_nOffset = 0;
  this->vmf_unc.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->vmf_unc, nPut: 0);
  this->driverinfo.m_Get = 0;
  this->driverinfo.m_Put = 0;
  this->driverinfo.m_Error = 0;
  this->driverinfo.m_nOffset = 0;
  this->driverinfo.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->driverinfo, nPut: 0);
  this->misc.m_Get = 0;
  this->misc.m_Put = 0;
  this->misc.m_Error = 0;
  this->misc.m_nOffset = 0;
  this->misc.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->misc, nPut: 0);
  this->console.m_Get = 0;
  this->console.m_Put = 0;
  this->console.m_Error = 0;
  this->console.m_nOffset = 0;
  this->console.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->console, nPut: 0);
  this->osversion.m_Get = 0;
  this->osversion.m_Put = 0;
  this->osversion.m_Error = 0;
  this->osversion.m_nOffset = 0;
  this->osversion.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->osversion, nPut: 0);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &this->includedfiles);
  if ( this->includedfiles.m_Memory.m_nGrowSize < 0 )
  {
    this->includedfiles.m_pElements = this->includedfiles.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->includedfiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->includedfiles.m_Memory.m_pMemory);
      this->includedfiles.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->includedfiles.m_Memory.m_pMemory;
    this->includedfiles.m_Memory.m_nAllocationCount = 0;
    this->includedfiles.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F30
// Name: public: virtual void CBugReporter::CancelNewBugReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::CancelNewBugReport(CBugReporter *this)
{
  CBug *m_pBug; // ecx

  m_pBug = this->m_pBug;
  if ( m_pBug != nullptr )
  {
    CBug::Clear(this: m_pBug);
    this->m_CurrentBugID = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F50
// Name: public: virtual bool CBugReporter::CommitBugReport(int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::CommitBugReport(CBugReporter *this, int *bugSubmissionId)
{
  CBug *m_pBug; // edx
  char *v5; // esi
  unsigned __int8 *m_pMemory; // eax
  char *v7; // esi
  CBug *v8; // ecx
  unsigned __int8 *v9; // eax
  char *v10; // esi
  CBug *v11; // edx
  unsigned __int8 *v12; // eax
  char *v13; // esi
  unsigned __int8 *v14; // eax
  char *v15; // esi
  CBug *v16; // ecx
  unsigned __int8 *v17; // eax
  char *v18; // esi
  CBug *v19; // edx
  unsigned __int8 *v20; // eax
  char *v21; // esi
  unsigned __int8 *v22; // eax
  char *v23; // esi
  CBug *v24; // ecx
  unsigned __int8 *v25; // eax
  char *v26; // esi
  CBug *v27; // edx
  unsigned __int8 *v28; // eax
  char *v29; // esi
  unsigned __int8 *v30; // eax
  char *v31; // esi
  CBug *v32; // ecx
  unsigned __int8 *v33; // eax
  char *v34; // esi
  CBug *v35; // edx
  unsigned __int8 *v36; // eax
  char *v37; // esi
  unsigned __int8 *v38; // eax
  char *v39; // esi
  CBug *v40; // ecx
  unsigned __int8 *v41; // eax
  char *v42; // esi
  CBug *v43; // edx
  unsigned __int8 *v44; // eax
  char *v45; // esi
  unsigned __int8 *v46; // eax
  char *v47; // esi
  CBug *v48; // ecx
  unsigned __int8 *v49; // eax
  char *v50; // esi
  CBug *v51; // edx
  unsigned __int8 *v52; // eax
  char *v53; // esi
  unsigned __int8 *v54; // eax
  char *v55; // esi
  CBug *v56; // ecx
  unsigned __int8 *v57; // eax
  char *v58; // esi
  _iobuf *v59; // eax
  _iobuf *v60; // esi
  char szBugFileName[1024]; // [esp+4h] [ebp-430h] BYREF
  CUtlBuffer buf; // [esp+404h] [ebp-30h] BYREF

  *bugSubmissionId = this->m_CurrentBugID;
  if ( this->m_pBug == nullptr )
    return 0;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  m_pBug = this->m_pBug;
  if ( m_pBug->title.m_Memory.m_pMemory != nullptr && *m_pBug->title.m_Memory.m_pMemory != 0 )
  {
    v5 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)m_pBug->title.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Title");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v5);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v5);
  }
  m_pMemory = this->m_pBug->owner.m_Memory.m_pMemory;
  if ( m_pMemory != nullptr && *m_pMemory != 0 )
  {
    v7 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)this->m_pBug->owner.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Owner");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v7);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v7);
  }
  v8 = this->m_pBug;
  v9 = v8->submitter.m_Memory.m_pMemory;
  if ( v9 != nullptr && *v9 != 0 )
  {
    v10 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v8->submitter.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Submitter");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v10);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v10);
  }
  v11 = this->m_pBug;
  v12 = v11->severity.m_Memory.m_pMemory;
  if ( v12 != nullptr && *v12 != 0 )
  {
    v13 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v11->severity.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Severity");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v13);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v13);
  }
  v14 = this->m_pBug->report_type.m_Memory.m_pMemory;
  if ( v14 != nullptr && *v14 != 0 )
  {
    v15 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)this->m_pBug->report_type.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Category");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v15);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v15);
  }
  v16 = this->m_pBug;
  v17 = v16->priority.m_Memory.m_pMemory;
  if ( v17 != nullptr && *v17 != 0 )
  {
    v18 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v16->priority.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Priority");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v18);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v18);
  }
  v19 = this->m_pBug;
  v20 = v19->area.m_Memory.m_pMemory;
  if ( v20 != nullptr && *v20 != 0 )
  {
    v21 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v19->area.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Area");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v21);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v21);
  }
  v22 = this->m_pBug->mapnumber.m_Memory.m_pMemory;
  if ( v22 != nullptr && *v22 != 0 )
  {
    v23 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)this->m_pBug->mapnumber.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Level");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v23);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v23);
  }
  v24 = this->m_pBug;
  v25 = v24->desc.m_Memory.m_pMemory;
  if ( v25 != nullptr && *v25 != 0 )
  {
    v26 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v24->desc.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Description");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v26);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v26);
  }
  v27 = this->m_pBug;
  v28 = v27->build.m_Memory.m_pMemory;
  if ( v28 != nullptr && *v28 != 0 )
  {
    v29 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v27->build.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Build");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v29);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v29);
  }
  v30 = this->m_pBug->position.m_Memory.m_pMemory;
  if ( v30 != nullptr && *v30 != 0 )
  {
    v31 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)this->m_pBug->position.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Position");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v31);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v31);
  }
  v32 = this->m_pBug;
  v33 = v32->orientation.m_Memory.m_pMemory;
  if ( v33 != nullptr && *v33 != 0 )
  {
    v34 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v32->orientation.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Orientation");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v34);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v34);
  }
  v35 = this->m_pBug;
  v36 = v35->screenshot_unc.m_Memory.m_pMemory;
  if ( v36 != nullptr && *v36 != 0 )
  {
    v37 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v35->screenshot_unc.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Screenshot");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v37);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v37);
  }
  v38 = this->m_pBug->savegame_unc.m_Memory.m_pMemory;
  if ( v38 != nullptr && *v38 != 0 )
  {
    v39 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)this->m_pBug->savegame_unc.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Savegame");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v39);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v39);
  }
  v40 = this->m_pBug;
  v41 = v40->bsp_unc.m_Memory.m_pMemory;
  if ( v41 != nullptr && *v41 != 0 )
  {
    v42 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v40->bsp_unc.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Bsp");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v42);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v42);
  }
  v43 = this->m_pBug;
  v44 = v43->vmf_unc.m_Memory.m_pMemory;
  if ( v44 != nullptr && *v44 != 0 )
  {
    v45 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v43->vmf_unc.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "vmf");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v45);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v45);
  }
  v46 = this->m_pBug->driverinfo.m_Memory.m_pMemory;
  if ( v46 != nullptr && *v46 != 0 )
  {
    v47 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)this->m_pBug->driverinfo.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "DriverInfo");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v47);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v47);
  }
  v48 = this->m_pBug;
  v49 = v48->osversion.m_Memory.m_pMemory;
  if ( v49 != nullptr && *v49 != 0 )
  {
    v50 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v48->osversion.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "OSVersion");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v50);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v50);
  }
  v51 = this->m_pBug;
  v52 = v51->misc.m_Memory.m_pMemory;
  if ( v52 != nullptr && *v52 != 0 )
  {
    v53 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v51->misc.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Misc");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v53);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v53);
  }
  v54 = this->m_pBug->console.m_Memory.m_pMemory;
  if ( v54 != nullptr && *v54 != 0 )
  {
    v55 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)this->m_pBug->console.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "Console");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v55);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v55);
  }
  v56 = this->m_pBug;
  v57 = v56->osversion.m_Memory.m_pMemory;
  if ( v57 != nullptr && *v57 != 0 )
  {
    v58 = V_AddBackSlashesToSpecialChars(pSrc: (const char *)v56->osversion.m_Memory.m_pMemory);
    CUtlBuffer::PutString(this: &buf, pString: "OSVersion");
    CUtlBuffer::PutString(this: &buf, pString: "=\"");
    CUtlBuffer::PutString(this: &buf, pString: v58);
    CUtlBuffer::PutString(this: &buf, pString: "\"\n");
    free(pMem: v58);
  }
  V_snprintf(pDest: szBugFileName, maxLen: 1024, pFormat: "%s%cbug.txt", this->m_CurrentBugDirectory, 92);
  v59 = fopen(file: szBugFileName, mode: "wb");
  v60 = v59;
  if ( v59 != nullptr )
  {
    fprintf(str: v59, format: "%s", (const char *)buf.m_Memory.m_pMemory);
    fclose(stream: v60);
    CBug::Clear(this: this->m_pBug);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003780
// Name: public: virtual void CBugReporter::ResetIncludedFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::ResetIncludedFiles(CBugReporter *this)
{
  CBug *m_pBug; // esi
  CUtlString *m_pMemory; // ecx

  m_pBug = this->m_pBug;
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &m_pBug->includedfiles);
  if ( m_pBug->includedfiles.m_Memory.m_nGrowSize < 0 )
  {
    m_pBug->includedfiles.m_pElements = m_pBug->includedfiles.m_Memory.m_pMemory;
  }
  else
  {
    if ( m_pBug->includedfiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pBug->includedfiles.m_Memory.m_pMemory);
      m_pBug->includedfiles.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = m_pBug->includedfiles.m_Memory.m_pMemory;
    m_pBug->includedfiles.m_Memory.m_nAllocationCount = 0;
    m_pBug->includedfiles.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100037F0
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
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
// Address: 0x10003850
// Name: public: CBug::CBug(void)
// Source: json
//------------------------------------------------------------------------------
CBug *__thiscall CBug::CBug(CBug *this)
{
  CUtlBuffer::CUtlBuffer(this: &this->title, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->desc, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->owner, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->submitter, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->severity, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->priority, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->area, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->mapnumber, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->report_type, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->level, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->build, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->position, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->orientation, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->screenshot_unc, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->savegame_unc, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->bsp_unc, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->vmf_unc, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->driverinfo, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->misc, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->console, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::CUtlBuffer(this: &this->osversion, growSize: 0, initSize: 0, nFlags: 1);
  this->includedfiles.m_Memory.m_pMemory = nullptr;
  this->includedfiles.m_Memory.m_nAllocationCount = 0;
  this->includedfiles.m_Memory.m_nGrowSize = 0;
  this->includedfiles.m_Size = 0;
  this->includedfiles.m_pElements = nullptr;
  CBug::Clear(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100039B0
// Name: public: CBug::~CBug(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBug::~CBug(CBug *this)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &this->includedfiles);
  if ( this->osversion.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->osversion.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->osversion.m_Memory.m_pMemory);
      this->osversion.m_Memory.m_pMemory = nullptr;
    }
    this->osversion.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->console.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->console.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->console.m_Memory.m_pMemory);
      this->console.m_Memory.m_pMemory = nullptr;
    }
    this->console.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->misc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->misc.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->misc.m_Memory.m_pMemory);
      this->misc.m_Memory.m_pMemory = nullptr;
    }
    this->misc.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->driverinfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->driverinfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->driverinfo.m_Memory.m_pMemory);
      this->driverinfo.m_Memory.m_pMemory = nullptr;
    }
    this->driverinfo.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->vmf_unc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->vmf_unc.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->vmf_unc.m_Memory.m_pMemory);
      this->vmf_unc.m_Memory.m_pMemory = nullptr;
    }
    this->vmf_unc.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->bsp_unc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->bsp_unc.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->bsp_unc.m_Memory.m_pMemory);
      this->bsp_unc.m_Memory.m_pMemory = nullptr;
    }
    this->bsp_unc.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->savegame_unc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->savegame_unc.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->savegame_unc.m_Memory.m_pMemory);
      this->savegame_unc.m_Memory.m_pMemory = nullptr;
    }
    this->savegame_unc.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->screenshot_unc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->screenshot_unc.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->screenshot_unc.m_Memory.m_pMemory);
      this->screenshot_unc.m_Memory.m_pMemory = nullptr;
    }
    this->screenshot_unc.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->orientation.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->orientation.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->orientation.m_Memory.m_pMemory);
      this->orientation.m_Memory.m_pMemory = nullptr;
    }
    this->orientation.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->position.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->position.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->position.m_Memory.m_pMemory);
      this->position.m_Memory.m_pMemory = nullptr;
    }
    this->position.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->build.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->build.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->build.m_Memory.m_pMemory);
      this->build.m_Memory.m_pMemory = nullptr;
    }
    this->build.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->level.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->level.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->level.m_Memory.m_pMemory);
      this->level.m_Memory.m_pMemory = nullptr;
    }
    this->level.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->report_type.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->report_type.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->report_type.m_Memory.m_pMemory);
      this->report_type.m_Memory.m_pMemory = nullptr;
    }
    this->report_type.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->mapnumber.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->mapnumber.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->mapnumber.m_Memory.m_pMemory);
      this->mapnumber.m_Memory.m_pMemory = nullptr;
    }
    this->mapnumber.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->area.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->area.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->area.m_Memory.m_pMemory);
      this->area.m_Memory.m_pMemory = nullptr;
    }
    this->area.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->priority.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->priority.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->priority.m_Memory.m_pMemory);
      this->priority.m_Memory.m_pMemory = nullptr;
    }
    this->priority.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->severity.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->severity.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->severity.m_Memory.m_pMemory);
      this->severity.m_Memory.m_pMemory = nullptr;
    }
    this->severity.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->submitter.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->submitter.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->submitter.m_Memory.m_pMemory);
      this->submitter.m_Memory.m_pMemory = nullptr;
    }
    this->submitter.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->owner.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->owner.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->owner.m_Memory.m_pMemory);
      this->owner.m_Memory.m_pMemory = nullptr;
    }
    this->owner.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->desc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->desc.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->desc.m_Memory.m_pMemory);
      this->desc.m_Memory.m_pMemory = nullptr;
    }
    this->desc.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->title.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->title.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->title.m_Memory.m_pMemory);
      this->title.m_Memory.m_pMemory = nullptr;
    }
    this->title.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D70
// Name: public: virtual void CBugReporter::StartNewBugReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::StartNewBugReport(CBugReporter *this)
{
  CBug *m_pBug; // ecx
  CBug *v3; // eax
  const char *v4; // eax
  int v5; // eax
  const char *v6; // eax
  tm t; // [esp+Ch] [ebp-24h] BYREF

  m_pBug = this->m_pBug;
  if ( m_pBug != nullptr )
  {
    CBug::Clear(this: m_pBug);
  }
  else
  {
    v3 = (CBug *)operator new(nSize: 0x404u);
    if ( v3 != nullptr )
      this->m_pBug = CBug::CBug(this: v3);
    else
      this->m_pBug = nullptr;
  }
  this->m_CurrentBugID = 0;
  _Plat_GetLocalTime(a1: &t);
  v4 = this->GetUserNameA_2(this);
  V_snprintf(
    pDest: this->m_CurrentBugDirectory,
    maxLen: 512,
    pFormat: "%s%c%04i%02i%02i-%02i%02i%02i-%s",
    this->m_BugRootDirectory,
    92,
    t.tm_year + 1900,
    t.tm_mon + 1,
    t.tm_mday,
    t.tm_hour,
    t.tm_min,
    t.tm_sec,
    v4);
  while ( _access(path: this->m_CurrentBugDirectory, amode: 0) == 0 )
  {
    v5 = _RandomInt(a1: 1000, a2: 2000);
    _ThreadSleep(a1: v5);
    _Plat_GetLocalTime(a1: &t);
    v6 = this->GetUserNameA_2(this);
    V_snprintf(
      pDest: this->m_CurrentBugDirectory,
      maxLen: 512,
      pFormat: "%s%c%04i%02i%02i-%02i%02i%02i-%s",
      this->m_BugRootDirectory,
      92,
      t.tm_year + 1900,
      t.tm_mon + 1,
      t.tm_mday,
      t.tm_hour,
      t.tm_min,
      t.tm_sec,
      v6);
  }
  _mkdir(path: this->m_CurrentBugDirectory);
}

//------------------------------------------------------------------------------
// Address: 0x10003EB0
// Name: private: bool CBugReporter::PopulateLists(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::PopulateLists(CBugReporter *this)
{
  const char *v2; // eax
  const char *v3; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  const char *v6; // edi
  const char *String; // eax
  const char *v8; // eax
  const char *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v13; // eax
  CUtlSymbol *v14; // edi
  int v15; // edi
  int v16; // eax
  CUtlSymbol *v17; // ecx
  int v18; // eax
  CUtlSymbol *v19; // edi
  KeyValues *v20; // eax
  CBugReporter *v21; // edi
  const char *Name; // eax
  const char *v23; // eax
  int v24; // ebx
  int v25; // eax
  CUtlSymbol *v26; // ecx
  int v27; // eax
  CUtlSymbol *v28; // ebx
  int v29; // ebx
  int v30; // eax
  CUtlSymbol *v31; // ecx
  int v32; // eax
  CUtlSymbol *v33; // eax
  KeyValues *v34; // eax
  int v35; // ebx
  const char *v36; // edi
  const char *v37; // eax
  int v38; // edi
  int v39; // eax
  int v40; // ecx
  int v41; // eax
  CUtlSymbol *v42; // edi
  int v43; // edi
  int v44; // eax
  int v45; // ecx
  int v46; // eax
  CUtlSymbol *v47; // eax
  int v48; // esi
  KeyValues *v49; // eax
  KeyValues *v50; // edi
  const char *v51; // esi
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *v52; // eax
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *v53; // ebx
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v54; // edi
  unsigned __int16 v55; // cx
  int v56; // esi
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *v57; // eax
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *v58; // edx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *v59; // eax
  CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t *p_m_Data; // esi
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *v61; // edi
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *v62; // eax
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v63; // esi
  int v64; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *v65; // eax
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *v66; // edx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short> *v67; // eax
  const char *v68; // ecx
  CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t *v69; // eax
  const char *v70; // esi
  const char *v71; // esi
  int v72; // esi
  int v73; // eax
  CUtlSymbol *v74; // ecx
  int v75; // eax
  CUtlSymbol *v76; // esi
  int v77; // esi
  int v78; // eax
  CUtlSymbol *v79; // ecx
  int v80; // eax
  CUtlSymbol *v81; // esi
  char areamap[256]; // [esp+Ch] [ebp-164h] BYREF
  CUtlString username; // [esp+10Ch] [ebp-64h] BYREF
  CUtlSymbol v85; // [esp+11Eh] [ebp-52h] BYREF
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v86; // [esp+120h] [ebp-50h]
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v87; // [esp+124h] [ebp-4Ch]
  CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t v88; // [esp+128h] [ebp-48h] BYREF
  CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t insert; // [esp+130h] [ebp-40h] BYREF
  CUtlString email; // [esp+138h] [ebp-38h] BYREF
  const char *owner; // [esp+148h] [ebp-28h]
  CUtlSymbolTable *v92; // [esp+14Ch] [ebp-24h]
  KeyValues *pLevelKV; // [esp+150h] [ebp-20h]
  CUtlSymbol level_sym; // [esp+154h] [ebp-1Ch] BYREF
  unsigned __int16 parent[2]; // [esp+158h] [ebp-18h] BYREF
  CUtlSymbol v96[2]; // [esp+15Ch] [ebp-14h] BYREF
  KeyValues *pKV; // [esp+160h] [ebp-10h]
  CUtlSymbol areamap_sym; // [esp+164h] [ebp-Ch] BYREF
  CUtlSymbol owner_sym; // [esp+168h] [ebp-8h] BYREF
  bool leftchild; // [esp+16Fh] [ebp-1h] BYREF

  *(_DWORD *)&v96[0].m_Id = this;
  CBugReporter::PopulateChoiceList(this, listname: "Severity", list: &this->m_Severity);
  CBugReporter::PopulateChoiceList(this, listname: "Priority", list: &this->m_Priority);
  CBugReporter::PopulateChoiceList(this, listname: "Category", list: &this->m_ReportType);
  CUtlString::CUtlString(this: &username);
  CUtlString::CUtlString(this: &email);
  GetLocalUserEmailAddress(&email, &username);
  if ( CUtlString::Length(this: &this->m_EngineExportedDefaultUsername) > 0 )
  {
    v2 = CUtlString::Get(this: &this->m_EngineExportedDefaultUsername);
    CUtlString::operator=(this: &username, src: v2);
    v3 = CUtlString::Get(this: &this->m_EngineExportedDefaultUsername);
    CUtlString::operator=(this: &email, src: v3);
  }
  Key = KeyValues::FindKey(this: this->m_OptionsFile, keyName: "Names", bCreate: false);
  FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      v6 = CUtlString::Get(this: &email);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: str);
      if ( _V_stricmp(s1: v6, s2: String) != 0 )
        break;
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    if ( CUtlString::Length(this: &email) > 0 )
    {
      v8 = CUtlString::Get(this: &username);
      CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &areamap_sym, pString: v8);
      v9 = CUtlString::Get(this: &email);
      CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &owner_sym, pString: v9);
      m_Size = this->m_SortedDisplayNames.m_Size;
      m_nAllocationCount = this->m_SortedDisplayNames.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: &this->m_SortedDisplayNames.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_SortedDisplayNames.m_Size;
      m_pMemory = this->m_SortedDisplayNames.m_Memory.m_pMemory;
      v13 = this->m_SortedDisplayNames.m_Size - m_Size - 1;
      this->m_SortedDisplayNames.m_pElements = m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v13);
      v14 = &this->m_SortedDisplayNames.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        v14->m_Id = areamap_sym.m_Id;
      v15 = this->m_SortedUserNames.m_Size;
      v16 = this->m_SortedUserNames.m_Memory.m_nAllocationCount;
      if ( v15 + 1 > v16 )
        CUtlMemory<CUtlSymbol,int>::Grow(this: &this->m_SortedUserNames.m_Memory, num: v15 - v16 + 1);
      ++this->m_SortedUserNames.m_Size;
      v17 = this->m_SortedUserNames.m_Memory.m_pMemory;
      v18 = this->m_SortedUserNames.m_Size - v15 - 1;
      this->m_SortedUserNames.m_pElements = v17;
      if ( v18 > 0 )
        _V_memmove(dest: &v17[v15 + 1], src: &v17[v15], count: 2 * v18);
      v19 = &this->m_SortedUserNames.m_Memory.m_pMemory[v15];
      if ( v19 != nullptr )
        v19->m_Id = owner_sym.m_Id;
    }
  }
  v20 = KeyValues::FindKey(this: this->m_OptionsFile, keyName: "Names", bCreate: false);
  pKV = KeyValues::GetFirstSubKey(this: v20);
  if ( pKV != nullptr )
  {
    v21 = this;
    do
    {
      Name = KeyValues::GetName(this: pKV);
      CUtlSymbolTable::AddString(this: &v21->m_BugStrings, result: &areamap_sym, pString: Name);
      v23 = KeyValues::GetString(this: pKV, keyName: nullptr, defaultValue: str);
      CUtlSymbolTable::AddString(this: &v21->m_BugStrings, result: &owner_sym, pString: v23);
      v24 = v21->m_SortedDisplayNames.m_Size;
      v25 = v21->m_SortedDisplayNames.m_Memory.m_nAllocationCount;
      if ( v24 + 1 > v25 )
        CUtlMemory<CUtlSymbol,int>::Grow(this: &v21->m_SortedDisplayNames.m_Memory, num: v24 - v25 + 1);
      ++v21->m_SortedDisplayNames.m_Size;
      v26 = v21->m_SortedDisplayNames.m_Memory.m_pMemory;
      v27 = v21->m_SortedDisplayNames.m_Size - v24 - 1;
      v21->m_SortedDisplayNames.m_pElements = v26;
      if ( v27 > 0 )
        _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 2 * v27);
      v28 = &v21->m_SortedDisplayNames.m_Memory.m_pMemory[v24];
      if ( v28 != nullptr )
        v28->m_Id = areamap_sym.m_Id;
      v29 = v21->m_SortedUserNames.m_Size;
      v30 = v21->m_SortedUserNames.m_Memory.m_nAllocationCount;
      if ( v29 + 1 > v30 )
        CUtlMemory<CUtlSymbol,int>::Grow(this: &v21->m_SortedUserNames.m_Memory, num: v29 - v30 + 1);
      ++v21->m_SortedUserNames.m_Size;
      v31 = v21->m_SortedUserNames.m_Memory.m_pMemory;
      v32 = v21->m_SortedUserNames.m_Size - v29 - 1;
      v21->m_SortedUserNames.m_pElements = v31;
      if ( v32 > 0 )
        _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: 2 * v32);
      v33 = &v21->m_SortedUserNames.m_Memory.m_pMemory[v29];
      if ( v33 != nullptr )
        v33->m_Id = owner_sym.m_Id;
      pKV = KeyValues::GetNextKey(this: pKV);
    }
    while ( pKV != nullptr );
  }
  v34 = KeyValues::FindKey(this: *(KeyValues **)(*(_DWORD *)&v96[0].m_Id + 812), keyName: "Area", bCreate: false);
  pKV = KeyValues::GetFirstSubKey(this: v34);
  if ( pKV != nullptr )
  {
    v35 = *(_DWORD *)&v96[0].m_Id;
    do
    {
      v36 = KeyValues::GetName(this: pKV);
      v37 = KeyValues::GetString(this: pKV, keyName: nullptr, defaultValue: str);
      V_snprintf(pDest: areamap, maxLen: 256, pFormat: "@%s", v37);
      _V_strlower(start: areamap);
      CUtlSymbolTable::AddString(this: (CUtlSymbolTable *)(v35 + 4), result: &areamap_sym, pString: v36);
      CUtlSymbolTable::AddString(this: (CUtlSymbolTable *)(v35 + 4), result: &owner_sym, pString: areamap);
      v38 = *(_DWORD *)(v35 + 152);
      v39 = *(_DWORD *)(v35 + 144);
      if ( v38 + 1 > v39 )
        CUtlMemory<CUtlSymbol,int>::Grow(this: (CUtlMemory<CUtlSymbol,int> *)(v35 + 140), num: v38 - v39 + 1);
      ++*(_DWORD *)(v35 + 152);
      v40 = *(_DWORD *)(v35 + 140);
      v41 = *(_DWORD *)(v35 + 152) - v38 - 1;
      *(_DWORD *)(v35 + 156) = v40;
      if ( v41 > 0 )
        _V_memmove(dest: (void *)(v40 + 2 * v38 + 2), src: (const void *)(v40 + 2 * v38), count: 2 * v41);
      v42 = (CUtlSymbol *)(*(_DWORD *)(v35 + 140) + 2 * v38);
      if ( v42 != nullptr )
        v42->m_Id = areamap_sym.m_Id;
      v43 = *(_DWORD *)(v35 + 172);
      v44 = *(_DWORD *)(v35 + 164);
      if ( v43 + 1 > v44 )
        CUtlMemory<CUtlSymbol,int>::Grow(this: (CUtlMemory<CUtlSymbol,int> *)(v35 + 160), num: v43 - v44 + 1);
      ++*(_DWORD *)(v35 + 172);
      v45 = *(_DWORD *)(v35 + 160);
      v46 = *(_DWORD *)(v35 + 172) - v43 - 1;
      *(_DWORD *)(v35 + 176) = v45;
      if ( v46 > 0 )
        _V_memmove(dest: (void *)(v45 + 2 * v43 + 2), src: (const void *)(v45 + 2 * v43), count: 2 * v46);
      v47 = (CUtlSymbol *)(*(_DWORD *)(v35 + 160) + 2 * v43);
      if ( v47 != nullptr )
        v47->m_Id = owner_sym.m_Id;
      pKV = KeyValues::GetNextKey(this: pKV);
    }
    while ( pKV != nullptr );
  }
  v48 = *(_DWORD *)&v96[0].m_Id;
  v49 = KeyValues::FindKey(this: *(KeyValues **)(*(_DWORD *)&v96[0].m_Id + 812), keyName: "LevelOwners", bCreate: false);
  pKV = KeyValues::GetFirstSubKey(this: v49);
  if ( pKV != nullptr )
  {
    v86 = (CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v48 + 220);
    v87 = (CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v48 + 248);
    v92 = (CUtlSymbolTable *)(v48 + 4);
    do
    {
      v50 = pKV;
      v51 = KeyValues::GetName(this: pKV);
      pLevelKV = KeyValues::GetFirstSubKey(this: v50);
      V_snprintf(pDest: areamap, maxLen: 256, pFormat: "@%s", v51);
      _V_strlower(start: areamap);
      CUtlSymbolTable::Find(this: v92, result: &areamap_sym, pString: areamap);
      v52 = (CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *)operator new(nSize: 0x14u);
      if ( v52 != nullptr )
      {
        v52->m_Memory.m_pMemory = nullptr;
        v52->m_Memory.m_nAllocationCount = 0;
        v52->m_Memory.m_nGrowSize = 0;
        v52->m_Size = 0;
        v52->m_pElements = nullptr;
        v53 = v52;
      }
      else
      {
        v53 = nullptr;
      }
      v54 = v86;
      insert.key = areamap_sym;
      insert.elem = v53;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: v86,
        &insert,
        parent,
        &leftchild);
      v55 = CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: v54);
      v56 = v55;
      v57 = &v54->m_Elements.m_pMemory[v56];
      v57->m_Parent = parent[0];
      v57->m_Right = -1;
      v57->m_Left = -1;
      v57->m_Tag = 0;
      if ( parent[0] == 0xFFFF )
      {
        v54->m_Root = v55;
      }
      else
      {
        v58 = v54->m_Elements.m_pMemory;
        if ( leftchild )
          v58[parent[0]].m_Left = v55;
        else
          v58[parent[0]].m_Right = v55;
      }
      CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: v54,
        elem: v55);
      v59 = v54->m_Elements.m_pMemory;
      ++v54->m_NumElements;
      p_m_Data = &v59[v56].m_Data;
      v61 = nullptr;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      v62 = (CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *)operator new(nSize: 0x14u);
      if ( v62 != nullptr )
      {
        v62->m_Memory.m_pMemory = nullptr;
        v62->m_Memory.m_nAllocationCount = 0;
        v62->m_Memory.m_nGrowSize = 0;
        v62->m_Size = 0;
        v62->m_pElements = nullptr;
        v61 = v62;
      }
      v63 = v87;
      v88.key = areamap_sym;
      v88.elem = v61;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: v87,
        insert: &v88,
        parent,
        &leftchild);
      v64 = (unsigned __int16)CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: v63);
      v65 = &v63->m_Elements.m_pMemory[v64];
      owner = (const char *)(16 * v64);
      v65->m_Parent = parent[0];
      v65->m_Right = -1;
      v65->m_Left = -1;
      v65->m_Tag = 0;
      if ( parent[0] == 0xFFFF )
      {
        v63->m_Root = v64;
      }
      else
      {
        v66 = v63->m_Elements.m_pMemory;
        if ( leftchild )
          v66[parent[0]].m_Left = v64;
        else
          v66[parent[0]].m_Right = v64;
      }
      CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: v63,
        elem: v64);
      v67 = v63->m_Elements.m_pMemory;
      v68 = owner;
      ++v63->m_NumElements;
      v69 = (CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *,unsigned short>::Node_t *)((char *)&v67->m_Data + (_DWORD)v68);
      if ( v69 != nullptr )
        *v69 = v88;
      for ( ; pLevelKV != nullptr; pLevelKV = KeyValues::GetNextKey(this: pLevelKV) )
      {
        v70 = KeyValues::GetName(this: pLevelKV);
        owner = KeyValues::GetString(this: pLevelKV, keyName: nullptr, defaultValue: str);
        if ( v70 != nullptr )
        {
          CUtlSymbolTable::Find(this: v92, result: &level_sym, pString: v70);
          if ( level_sym.m_Id == 0xFFFF )
            level_sym.m_Id = CUtlSymbolTable::AddString(this: v92, result: &v85, pString: v70)->m_Id;
          v71 = owner;
          CUtlSymbolTable::Find(this: v92, result: &owner_sym, pString: owner);
          if ( owner_sym.m_Id == 0xFFFF )
            owner_sym.m_Id = CUtlSymbolTable::AddString(this: v92, result: &v96[1], pString: v71)->m_Id;
          v72 = v53->m_Size;
          v73 = v53->m_Memory.m_nAllocationCount;
          if ( v72 + 1 > v73 )
            CUtlMemory<CUtlSymbol,int>::Grow(this: &v53->m_Memory, num: v72 - v73 + 1);
          ++v53->m_Size;
          v74 = v53->m_Memory.m_pMemory;
          v75 = v53->m_Size - v72 - 1;
          v53->m_pElements = v53->m_Memory.m_pMemory;
          if ( v75 > 0 )
            _V_memmove(dest: &v74[v72 + 1], src: &v74[v72], count: 2 * v75);
          v76 = &v53->m_Memory.m_pMemory[v72];
          if ( v76 != nullptr )
            v76->m_Id = level_sym.m_Id;
          v77 = v61->m_Size;
          v78 = v61->m_Memory.m_nAllocationCount;
          if ( v77 + 1 > v78 )
            CUtlMemory<CUtlSymbol,int>::Grow(this: &v61->m_Memory, num: v77 - v78 + 1);
          ++v61->m_Size;
          v79 = v61->m_Memory.m_pMemory;
          v80 = v61->m_Size - v77 - 1;
          v61->m_pElements = v61->m_Memory.m_pMemory;
          if ( v80 > 0 )
            _V_memmove(dest: &v79[v77 + 1], src: &v79[v77], count: 2 * v80);
          v81 = &v61->m_Memory.m_pMemory[v77];
          if ( v81 != nullptr )
            v81->m_Id = owner_sym.m_Id;
        }
      }
      pKV = KeyValues::GetNextKey(this: pKV);
    }
    while ( pKV != nullptr );
  }
  email.m_Storage.m_nActualLength = 0;
  if ( email.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( email.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: email.m_Storage.m_Memory.m_pMemory);
      email.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    email.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  username.m_Storage.m_nActualLength = 0;
  if ( username.m_Storage.m_Memory.m_nGrowSize >= 0 && username.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: username.m_Storage.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100046D0
// Name: public: virtual bool CBugReporter::Init(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::Init(CBugReporter *this, void *(__cdecl *engineFactory)(const char *, int *))
{
  IBaseFileSystem *v3; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  const char *String; // eax
  KeyValues *Key; // eax
  KeyValues *v9; // esi
  const char *v10; // eax
  const char *v11; // eax
  struct hostent *v12; // eax
  const char *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  void *v16; // edi
  _iobuf *v17; // esi
  const char *v18; // eax
  int (__thiscall ***v19)(_DWORD); // eax
  const char *v20; // eax
  const char *v21; // eax
  int i; // edi
  const char *v23; // eax
  const char *v24; // eax
  int v25; // kr00_4
  const char *v26; // eax
  const char *v27; // eax
  char szConfigFile[1024]; // [esp+4h] [ebp-578h] BYREF
  char pString[256]; // [esp+404h] [ebp-178h] BYREF
  _stat64i32 cfg_info; // [esp+504h] [ebp-78h] BYREF
  char szNetmask[16]; // [esp+534h] [ebp-48h] BYREF
  char szNetwork[16]; // [esp+544h] [ebp-38h] BYREF
  CUtlString email; // [esp+554h] [ebp-28h] BYREF
  unsigned int netmask; // [esp+564h] [ebp-18h]
  CUtlString username; // [esp+568h] [ebp-14h] BYREF
  unsigned int network; // [esp+578h] [ebp-4h]

  if ( engineFactory != nullptr )
  {
    v3 = (IBaseFileSystem *)engineFactory(a1: "VFileSystem017", a2: nullptr);
    if ( v3 == nullptr )
    {
      g_pFileSystem = nullptr;
      return 0;
    }
    g_pFileSystem = v3 + 1;
    if ( v3 == (IBaseFileSystem *)-4 )
      return 0;
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "bugreporter repository");
  else
    v6 = nullptr;
  memset(szConfigFile, 0, sizeof(szConfigFile));
  if ( v6 != nullptr )
  {
    if ( g_pFileSystem != nullptr )
    {
      if ( !KeyValues::LoadFromFile(
              this: v6,
              filesystem: g_pFileSystem,
              resourceName: "resource/bugreporter.res",
              pathID: nullptr,
              pfnEvaluateSymbolProc: nullptr) )
      {
LABEL_16:
        KeyValues::deleteThis(this: v6);
        goto LABEL_17;
      }
    }
    else
    {
      KeyValues::SetString(this: v6, keyName: "config_file", value: "\\\\bugbait.valvesoftware.com\\bugsub\\config.txt");
    }
    String = KeyValues::GetString(this: v6, keyName: "config_file", defaultValue: str);
    V_strncpy(pDest: szConfigFile, pSrc: String, maxLen: 1024);
    Key = KeyValues::FindKey(this: v6, keyName: "alt_config", bCreate: false);
    v9 = Key;
    if ( Key != nullptr )
    {
      v10 = KeyValues::GetString(this: Key, keyName: "network", defaultValue: str);
      V_strncpy(pDest: szNetwork, pSrc: v10, maxLen: 16);
      v11 = KeyValues::GetString(this: v9, keyName: "netmask", defaultValue: str);
      V_strncpy(pDest: szNetmask, pSrc: v11, maxLen: 16);
      network = inet_addr(cp: szNetwork);
      netmask = inet_addr(cp: szNetmask);
      gethostname(name: pString, namelen: 256);
      v12 = gethostbyname(name: pString);
      if ( v12 != nullptr && (netmask & **(_DWORD **)v12->h_addr_list) == network )
      {
        v13 = KeyValues::GetString(this: v9, keyName: "config_file", defaultValue: str);
        V_strncpy(pDest: szConfigFile, pSrc: v13, maxLen: 1024);
      }
    }
    goto LABEL_16;
  }
LABEL_17:
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "OptionsFile");
  else
    v15 = nullptr;
  this->m_OptionsFile = v15;
  if ( _stat64i32(name: szConfigFile, buf: &cfg_info) != 0 )
    return 0;
  v16 = operator new(nSize: cfg_info.st_size + 1);
  network = (unsigned int)v16;
  v17 = fopen(file: szConfigFile, mode: "rb");
  if ( v17 == nullptr )
    return 0;
  fread(buffer: v16, elementSize: cfg_info.st_size, count: 1u, stream: v17);
  fclose(stream: v17);
  *((_BYTE *)v16 + cfg_info.st_size) = 0;
  if ( !KeyValues::LoadFromBuffer(
          this: this->m_OptionsFile,
          resourceName: szConfigFile,
          pBuffer: (const char *)v16,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    free(pMem: v16);
    return 0;
  }
  v18 = KeyValues::GetString(this: this->m_OptionsFile, keyName: "bug_directory", defaultValue: ".");
  V_strncpy(pDest: this->m_BugRootDirectory, pSrc: v18, maxLen: 512);
  CUtlString::CUtlString(this: &username);
  CUtlString::CUtlString(this: &email);
  GetLocalUserEmailAddress(&email, &username);
  if ( engineFactory != nullptr )
  {
    v19 = (int (__thiscall ***)(_DWORD))engineFactory(a1: "BugReporterUserName001", a2: nullptr);
    if ( v19 != nullptr )
    {
      v20 = (const char *)(**v19)(a1: v19);
      if ( v20 != nullptr && *v20 != 0 )
      {
        CUtlString::operator=(this: &username, src: v20);
        CUtlString::operator=(this: &this->m_EngineExportedDefaultUsername, src: &username);
        v21 = CUtlString::Get(this: &username);
        _Msg(a1: "Default username overridden by bugreporter_username to '%s'\n", v21);
      }
    }
  }
  CBugReporter::PopulateLists(this);
  for ( i = 0; i < this->m_SortedUserNames.m_Size; ++i )
  {
    v23 = this->GetUserNameA(this, a2: i);
    V_strncpy(pDest: pString, pSrc: v23, maxLen: 256);
    strtok(string: pString, control: "@");
    v24 = strtok(string: nullptr, control: str);
    if ( v24 == nullptr || V_strcasecmp(s1: v24, s2: "vmc.com") != 0 )
    {
      v27 = CUtlString::Get(this: &username);
      if ( V_strcasecmp(s1: pString, s2: v27) == 0 )
      {
        this->m_LocalMachineUserName.m_Id = this->m_SortedUserNames.m_Memory.m_pMemory[i].m_Id;
        break;
      }
    }
    else
    {
      v25 = strlen(pString);
      if ( v25 > 0 )
      {
        v26 = CUtlString::Get(this: &username);
        if ( V_strncasecmp(s1: pString, s2: v26, n: v25 - 1) == 0 )
        {
          this->m_LocalMachineUserName.m_Id = this->m_SortedUserNames.m_Memory.m_pMemory[i].m_Id;
          break;
        }
      }
    }
  }
  free(pMem: (void *)network);
  email.m_Storage.m_nActualLength = 0;
  if ( email.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( email.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: email.m_Storage.m_Memory.m_pMemory);
      email.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    email.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  username.m_Storage.m_nActualLength = 0;
  if ( username.m_Storage.m_Memory.m_nGrowSize >= 0 && username.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: username.m_Storage.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004B20
// Name: public: virtual CBugReporter::~CBugReporter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::~CBugReporter(CBugReporter *this)
{
  KeyValues *m_OptionsFile; // ecx
  CBug *m_pBug; // ecx
  CBug *pMem; // [esp+Ch] [ebp-4h]

  this->__vftable = (CBugReporter_vtbl *)&CBugReporter::`vftable';
  CUtlSymbolTable::RemoveAll(this: &this->m_BugStrings);
  this->m_Severity.m_Size = 0;
  if ( this->m_Severity.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Severity.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Severity.m_Memory.m_pMemory);
      this->m_Severity.m_Memory.m_pMemory = nullptr;
    }
    this->m_Severity.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Severity.m_pElements = this->m_Severity.m_Memory.m_pMemory;
  this->m_SortedDisplayNames.m_Size = 0;
  if ( this->m_SortedDisplayNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SortedDisplayNames.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SortedDisplayNames.m_Memory.m_pMemory);
      this->m_SortedDisplayNames.m_Memory.m_pMemory = nullptr;
    }
    this->m_SortedDisplayNames.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SortedDisplayNames.m_pElements = this->m_SortedDisplayNames.m_Memory.m_pMemory;
  this->m_Priority.m_Size = 0;
  if ( this->m_Priority.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Priority.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Priority.m_Memory.m_pMemory);
      this->m_Priority.m_Memory.m_pMemory = nullptr;
    }
    this->m_Priority.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Priority.m_pElements = this->m_Priority.m_Memory.m_pMemory;
  this->m_Area.m_Size = 0;
  if ( this->m_Area.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Area.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Area.m_Memory.m_pMemory);
      this->m_Area.m_Memory.m_pMemory = nullptr;
    }
    this->m_Area.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Area.m_pElements = this->m_Area.m_Memory.m_pMemory;
  this->m_MapNumber.m_Size = 0;
  if ( this->m_MapNumber.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MapNumber.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MapNumber.m_Memory.m_pMemory);
      this->m_MapNumber.m_Memory.m_pMemory = nullptr;
    }
    this->m_MapNumber.m_Memory.m_nAllocationCount = 0;
  }
  this->m_MapNumber.m_pElements = this->m_MapNumber.m_Memory.m_pMemory;
  this->m_ReportType.m_Size = 0;
  if ( this->m_ReportType.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ReportType.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ReportType.m_Memory.m_pMemory);
      this->m_ReportType.m_Memory.m_pMemory = nullptr;
    }
    this->m_ReportType.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ReportType.m_pElements = this->m_ReportType.m_Memory.m_pMemory;
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LevelMap.m_Tree);
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_OwnerMap.m_Tree);
  m_OptionsFile = this->m_OptionsFile;
  if ( m_OptionsFile != nullptr )
    KeyValues::deleteThis(this: m_OptionsFile);
  m_pBug = this->m_pBug;
  pMem = m_pBug;
  if ( m_pBug != nullptr )
  {
    CBug::~CBug(this: m_pBug);
    free(pMem);
  }
  this->m_EngineExportedDefaultUsername.m_Storage.m_nActualLength = 0;
  if ( this->m_EngineExportedDefaultUsername.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_EngineExportedDefaultUsername.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_EngineExportedDefaultUsername.m_Storage.m_Memory.m_pMemory);
      this->m_EngineExportedDefaultUsername.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_EngineExportedDefaultUsername.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_OwnerMap.m_Tree);
  CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>> *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_LevelMap.m_Tree);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ReportType);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_MapNumber);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_AreaMap);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Area);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Priority);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SortedUserNames);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SortedDisplayNames);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Severity);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_BugStrings);
  this->__vftable = (CBugReporter_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10004E90
// Name: __heap_term
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall _heap_term(CBugReporter *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10006660
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006760
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
    dword_100245B8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_100245B8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100068E0
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
    dword_100245B8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10006940
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
    dword_100245B8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100069B0
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
        dword_100245B8 = 0x1FFFF;
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
        dword_100245B8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006AA0
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
// Address: 0x10006BA0
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
// Address: 0x10006CE0
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
        dword_100245B8 = 0x1FFFF;
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
        dword_100245B8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10006DE0
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
// Address: 0x10006EB0
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
      dword_100245B8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100245B8 = 0x1FFFF;
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
      dword_100245B8 = 0x1FFFF;
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
      dword_100245B8 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100245B8 = 0x1FFFF;
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
      dword_100245B8 = 0x1FFFF;
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
        dword_100245B8 = 0x1FFFF;
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
        dword_100245B8 = 0x1FFFF;
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
          dword_100245B8 = 0x1FFFF;
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
          dword_100245B8 = 0x1FFFF;
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
        dword_100245B8 = 0x1FFFF;
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
        dword_100245B8 = 0x1FFFF;
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
          dword_100245B8 = 0x1FFFF;
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
          dword_100245B8 = 0x1FFFF;
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
// Address: 0x100074C0
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
// Address: 0x100075C0
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
// Address: 0x10007650
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
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
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10009C00
// Name: public: virtual bool CBugReporter::IsPublicUI(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBugReporter::IsPublicUI(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000A450
// Name: public: virtual void CBugReporter::SetGameDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetGameDirectory(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100013C0
// Name: __CreateCBugReporterIBugReporter_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBugReporter *__cdecl _CreateCBugReporterIBugReporter_interface()
{
  return &_g_CBugReporter_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x10004DB0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
