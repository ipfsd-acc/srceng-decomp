// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/bugreporter_public/bugreporter_public.cpp
// Functions: 62
// ============================================================

#include "utils\bugreporter_public\bugreporter_public.h"

//------------------------------------------------------------------------------
// Address: 0x10001290
// Name: public: virtual bool CBugReporter::Init(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::Init(CBugReporter *this, void *(__cdecl *engineFactory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // edi
  IBaseFileSystem *v4; // eax
  int (__thiscall ***v6)(_DWORD); // eax
  const char *v7; // eax
  const char *v8; // eax

  v2 = engineFactory;
  v4 = (IBaseFileSystem *)engineFactory(a1: "VFileSystem017", a2: nullptr);
  if ( v4 != nullptr )
  {
    g_pFileSystem = v4 + 1;
    if ( v4 == (IBaseFileSystem *)-4 )
    {
      return 0;
    }
    else
    {
      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&engineFactory + 1, pStr: "PublicUser");
      this->m_UserName.m_Id = HIWORD(engineFactory);
      v6 = (int (__thiscall ***)(_DWORD))v2(a1: "BugReporterUserName001", a2: nullptr);
      if ( v6 != nullptr )
      {
        v7 = (const char *)(**v6)(a1: v6);
        if ( v7 != nullptr && *v7 != 0 )
        {
          CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&engineFactory + 1, pStr: v7);
          this->m_UserName.m_Id = HIWORD(engineFactory);
          v8 = CUtlSymbol::String(this: &this->m_UserName);
          _Msg(a1: "Default username overridden by bugreporter_username to '%s'\n", v8);
        }
      }
      return 1;
    }
  }
  else
  {
    g_pFileSystem = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001340
// Name: public: virtual char const __near * CBugReporter::GetUserNameA(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetUserNameA(CBugReporter *this)
{
  return CUtlSymbol::String(this: &this->m_UserName);
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: public: virtual char const __near * CBugReporter::GetUserDisplayName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetUserDisplayName(CBugReporter *this)
{
  return this->GetUserNameA_2(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001360
// Name: public: virtual int CBugReporter::GetNameCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetNameCount(CBugReporter *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001370
// Name: public: virtual char const __near * CBugReporter::GetDisplayName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetDisplayName(CBugReporter *this, int index)
{
  if ( index != 0 )
    return "<<Invalid>>";
  else
    return this->GetUserNameA_2(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001390
// Name: public: virtual char const __near * CBugReporter::GetUserNameForDisplayName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetUserNameForDisplayName(CBugReporter *this, const char *display)
{
  return display;
}

//------------------------------------------------------------------------------
// Address: 0x100013A0
// Name: public: virtual char const __near * CBugReporter::GetAreaMap(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetAreaMap(CBugReporter *this, int index)
{
  return "<<Invalid>>";
}

//------------------------------------------------------------------------------
// Address: 0x100013B0
// Name: public: virtual int CBugReporter::GetAreaCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetAreaCount(CBugReporter *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100013C0
// Name: public: virtual void CBugReporter::SetTitle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetTitle(CBugReporter *this, const char *title)
{
  V_strncpy(pDest: this->m_pBug->title, pSrc: title, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: virtual void CBugReporter::SetDescription(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetDescription(CBugReporter *this, const char *description)
{
  V_strncpy(pDest: this->m_pBug->desc, pSrc: description, maxLen: 0x2000);
}

//------------------------------------------------------------------------------
// Address: 0x10001410
// Name: public: virtual void CBugReporter::SetSubmitter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetSubmitter(CBugReporter *this, const char *username)
{
  const char *v2; // esi

  v2 = username;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&username + 1, pStr: username);
  this->m_UserName.m_Id = HIWORD(username);
  if ( v2 == nullptr )
    v2 = (const char *)&unk_10012234;
  V_strncpy(pDest: this->m_pBug->submitter, pSrc: v2, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: virtual void CBugReporter::SetOwner(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetOwner(CBugReporter *this, const char *username)
{
  V_strncpy(pDest: this->m_pBug->owner, pSrc: username, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10001490
// Name: public: virtual void CBugReporter::SetReportType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetReportType(CBugReporter *this, const char *reporttype)
{
  V_strncpy(pDest: this->m_pBug->reporttype, pSrc: reporttype, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100014C0
// Name: public: virtual void CBugReporter::SetLevel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetLevel(CBugReporter *this, const char *levelnamne)
{
  V_strncpy(pDest: this->m_pBug->level, pSrc: levelnamne, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100014F0
// Name: public: virtual void CBugReporter::SetDriverInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetDriverInfo(CBugReporter *this, const char *info)
{
  V_strncpy(pDest: this->m_pBug->driverinfo, pSrc: info, maxLen: 2048);
}

//------------------------------------------------------------------------------
// Address: 0x10001520
// Name: public: virtual void CBugReporter::SetZipAttachmentName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetZipAttachmentName(CBugReporter *this, const char *zipfilename)
{
  V_strncpy(pDest: this->m_pBug->zip, pSrc: zipfilename, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10001550
// Name: public: virtual void CBugReporter::SetMiscInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetMiscInfo(CBugReporter *this, const char *info)
{
  V_strncpy(pDest: this->m_pBug->misc, pSrc: info, maxLen: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: public: virtual void CBugReporter::SetPosition(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetPosition(CBugReporter *this, const char *position)
{
  V_strncpy(pDest: this->m_pBug->position, pSrc: position, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100015B0
// Name: public: virtual void CBugReporter::SetOrientation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetOrientation(CBugReporter *this, const char *pitch_yaw_roll)
{
  V_strncpy(pDest: this->m_pBug->orientation, pSrc: pitch_yaw_roll, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100015E0
// Name: public: virtual void CBugReporter::SetBuildNumber(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetBuildNumber(CBugReporter *this, const char *build_num)
{
  V_strncpy(pDest: this->m_pBug->build, pSrc: build_num, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10001610
// Name: public: virtual void CBugReporter::SetScreenShot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetScreenShot(CBugReporter *this, const char *screenshot_unc_address)
{
  V_strncpy(pDest: this->m_pBug->screenshot_unc, pSrc: screenshot_unc_address, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10001640
// Name: public: virtual void CBugReporter::SetSaveGame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetSaveGame(CBugReporter *this, const char *savegame_unc_address)
{
  V_strncpy(pDest: this->m_pBug->savegame_unc, pSrc: savegame_unc_address, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10001670
// Name: public: virtual void CBugReporter::SetVMFName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetVMFName(CBugReporter *this, const char *pchText)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001680
// Name: public: virtual void CBugReporter::SetExeName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetExeName(CBugReporter *this, const char *exename)
{
  V_strncpy(pDest: this->m_pBug->exename, pSrc: exename, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100016B0
// Name: public: virtual void CBugReporter::SetGameDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetGameDirectory(CBugReporter *this, const char *gamedir)
{
  V_FileBase(in: gamedir, out: this->m_pBug->gamedir, maxlen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100016E0
// Name: public: virtual void CBugReporter::SetRAM(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetRAM(CBugReporter *this, unsigned int ram)
{
  this->m_pBug->ram = ram;
}

//------------------------------------------------------------------------------
// Address: 0x10001700
// Name: public: virtual void CBugReporter::SetCPU(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetCPU(CBugReporter *this, unsigned int cpu)
{
  this->m_pBug->cpu = cpu;
}

//------------------------------------------------------------------------------
// Address: 0x10001720
// Name: public: virtual void CBugReporter::SetProcessor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetProcessor(CBugReporter *this, const char *processor)
{
  V_strncpy(pDest: this->m_pBug->processor, pSrc: processor, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10001750
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
  this->m_pBug->dxversionhigh = high;
  this->m_pBug->dxversionlow = low;
  this->m_pBug->dxvendor = vendor;
  this->m_pBug->dxdevice = device;
}

//------------------------------------------------------------------------------
// Address: 0x100017A0
// Name: public: virtual void CBugReporter::SetOSVersion(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetOSVersion(CBugReporter *this, const char *osversion)
{
  V_strncpy(pDest: this->m_pBug->osversion, pSrc: osversion, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100017D0
// Name: public: virtual void CBugReporter::SetCSERAddress(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetCSERAddress(CBugReporter *this, const netadr_s *adr)
{
  this->m_cserIP = *adr;
}

//------------------------------------------------------------------------------
// Address: 0x100017F0
// Name: public: virtual void CBugReporter::SetSteamUserID(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SetSteamUserID(CBugReporter *this, TSteamGlobalUserID *steamid, int idsize)
{
  this->m_SteamID = *steamid;
}

//------------------------------------------------------------------------------
// Address: 0x100018C0
// Name: public: virtual int CBugReporter::GetSeverityCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetSeverityCount(CBugReporter *this)
{
  return this->m_Severity.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100018D0
// Name: public: virtual int CBugReporter::GetReportTypeCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetReportTypeCount(CBugReporter *this)
{
  return this->m_ReportType.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100018E0
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
// Address: 0x10001920
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
// Address: 0x10001960
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
// Address: 0x100019A0
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
// Address: 0x100019F0
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
// Address: 0x10001B00
// Name: public: CBugReporter::CBugReporter(void)
// Source: json
//------------------------------------------------------------------------------
CBugReporter *__thiscall CBugReporter::CBugReporter(CBugReporter *this)
{
  const CUtlSymbol *v2; // eax
  const CUtlSymbol *v3; // eax
  const CUtlSymbol *v4; // eax
  const CUtlSymbol *v5; // eax
  const CUtlSymbol *v6; // eax
  const CUtlSymbol *v7; // eax
  const CUtlSymbol *v8; // eax
  const CUtlSymbol *v9; // eax
  const CUtlSymbol *v10; // eax
  const CUtlSymbol *v11; // eax
  const CUtlSymbol *v12; // eax
  const CUtlSymbol *v13; // eax
  const CUtlSymbol *v14; // eax
  const CUtlSymbol *v15; // eax
  CUtlSymbol v17; // [esp+Eh] [ebp-2h] BYREF

  this->__vftable = (CBugReporter_vtbl *)&CBugReporter::`vftable';
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_BugStrings, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_Severity.m_Memory.m_pMemory = nullptr;
  this->m_Severity.m_Memory.m_nAllocationCount = 0;
  this->m_Severity.m_Memory.m_nGrowSize = 0;
  this->m_Severity.m_Size = 0;
  this->m_Severity.m_pElements = nullptr;
  this->m_Area.m_Memory.m_pMemory = nullptr;
  this->m_Area.m_Memory.m_nAllocationCount = 0;
  this->m_Area.m_Memory.m_nGrowSize = 0;
  this->m_Area.m_Size = 0;
  this->m_Area.m_pElements = nullptr;
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
  this->m_UserName.m_Id = -1;
  netadr_s::SetIP(this: &this->m_cserIP, unIP: 0);
  netadr_s::SetPort(this: &this->m_cserIP, newport: 0);
  netadr_s::SetType(this: &this->m_cserIP, newtype: NA_IP);
  _V_memset(dest: &this->m_cserIP, fill: 0, count: 12);
  this->m_pBug = nullptr;
  v2 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Zero");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_Severity,
    elem: this->m_Severity.m_Size,
    src: v2);
  v3 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Low");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_Severity,
    elem: this->m_Severity.m_Size,
    src: v3);
  v4 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Medium");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_Severity,
    elem: this->m_Severity.m_Size,
    src: v4);
  v5 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "High");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_Severity,
    elem: this->m_Severity.m_Size,
    src: v5);
  v6 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Showstopper");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_Severity,
    elem: this->m_Severity.m_Size,
    src: v6);
  v7 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "<<Choose Item>>");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v7);
  v8 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Video / Display Problems");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v8);
  v9 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Network / Connectivity Problems");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v9);
  v10 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Download / Installation Problems");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v10);
  v11 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "In-game Crash");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v11);
  v12 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Game play / Strategy Problems");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v12);
  v13 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Steam Problems");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v13);
  v14 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Unlisted Bug");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v14);
  v15 = CUtlSymbolTable::AddString(this: &this->m_BugStrings, result: &v17, pString: "Feature Request / Suggestion");
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &this->m_ReportType,
    elem: this->m_ReportType.m_Size,
    src: v15);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001D80
// Name: public: virtual bool CBugReporter::IsPublicUI(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::IsPublicUI(CBugReporter *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001D90
// Name: public: virtual char const __near * CBugReporter::GetSubmissionURL(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetSubmissionURL(CBugReporter *this)
{
  return (const char *)&unk_10012234;
}

//------------------------------------------------------------------------------
// Address: 0x10001DA0
// Name: public: virtual int CBugReporter::GetLevelCount(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::GetLevelCount(CBugReporter *this, int area)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001DB0
// Name: public: virtual char const __near * CBugReporter::GetLevel(int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugReporter::GetLevel(CBugReporter *this, int area, int index)
{
  return (const char *)&unk_10012234;
}

//------------------------------------------------------------------------------
// Address: 0x10001E30
// Name: public: void CBug::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBug::Clear(CBug *this)
{
  CUtlString *m_pMemory; // ecx

  _V_memset(dest: this, fill: 0, count: 256);
  _V_memset(dest: this->desc, fill: 0, count: 0x2000);
  _V_memset(dest: this->submitter, fill: 0, count: 256);
  _V_memset(dest: this->owner, fill: 0, count: 256);
  _V_memset(dest: this->severity, fill: 0, count: 256);
  _V_memset(dest: this->priority, fill: 0, count: 256);
  _V_memset(dest: this->area, fill: 0, count: 256);
  _V_memset(dest: this->mapnumber, fill: 0, count: 256);
  _V_memset(dest: this->reporttype, fill: 0, count: 256);
  _V_memset(dest: this->level, fill: 0, count: 256);
  _V_memset(dest: this->build, fill: 0, count: 256);
  _V_memset(dest: this->position, fill: 0, count: 256);
  _V_memset(dest: this->orientation, fill: 0, count: 256);
  _V_memset(dest: this->screenshot_unc, fill: 0, count: 256);
  _V_memset(dest: this->savegame_unc, fill: 0, count: 256);
  _V_memset(dest: this->bsp_unc, fill: 0, count: 256);
  _V_memset(dest: this->vmf_unc, fill: 0, count: 256);
  _V_memset(dest: this->driverinfo, fill: 0, count: 2048);
  _V_memset(dest: this->misc, fill: 0, count: 1024);
  _V_memset(dest: this->zip, fill: 0, count: 256);
  _V_memset(dest: this->exename, fill: 0, count: 256);
  _V_memset(dest: this->gamedir, fill: 0, count: 256);
  this->ram = 0;
  this->cpu = 0;
  _V_memset(dest: this->processor, fill: 0, count: 256);
  this->dxversionhigh = 0;
  this->dxversionlow = 0;
  this->dxvendor = 0;
  this->dxdevice = 0;
  _V_memset(dest: this->osversion, fill: 0, count: 256);
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
// Address: 0x10002070
// Name: public: virtual void CBugReporter::CancelNewBugReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::CancelNewBugReport(CBugReporter *this)
{
  CBug *m_pBug; // ecx

  m_pBug = this->m_pBug;
  if ( m_pBug != nullptr )
    CBug::Clear(this: m_pBug);
}

//------------------------------------------------------------------------------
// Address: 0x10002080
// Name: public: virtual bool CBugReporter::CommitBugReport(int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::CommitBugReport(CBugReporter *this, int *bugSubmissionId)
{
  char *zip; // eax
  unsigned int v5; // eax
  CBug *m_pBug; // ecx
  int v7; // eax
  const char *v8; // [esp-48h] [ebp-80h]
  unsigned __int8 *m_pMemory; // [esp-44h] [ebp-7Ch]
  const char *exename; // [esp-40h] [ebp-78h]
  const char *gamedir; // [esp-3Ch] [ebp-74h]
  const char *level; // [esp-38h] [ebp-70h]
  const char *reporttype; // [esp-34h] [ebp-6Ch]
  const char *owner; // [esp-30h] [ebp-68h]
  const char *submitter; // [esp-2Ch] [ebp-64h]
  int ram; // [esp-28h] [ebp-60h]
  int cpu; // [esp-24h] [ebp-5Ch]
  const char *processor; // [esp-20h] [ebp-58h]
  unsigned int dxversionhigh; // [esp-1Ch] [ebp-54h]
  unsigned int dxversionlow; // [esp-18h] [ebp-50h]
  unsigned int dxvendor; // [esp-14h] [ebp-4Ch]
  unsigned int dxdevice; // [esp-10h] [ebp-48h]
  const char *osversion; // [esp-Ch] [ebp-44h]
  const char *v24; // [esp-8h] [ebp-40h]
  unsigned int v25; // [esp-4h] [ebp-3Ch]
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  *bugSubmissionId = -1;
  if ( this->m_pBug == nullptr )
    return 0;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::Printf(this: &buf, pFmt: "%s\n\n", this->m_pBug->desc);
  CUtlBuffer::Printf(
    this: &buf,
    pFmt: "level:  %s\nbuild:  %s\nposition:  setpos %s; setang %s\n",
    this->m_pBug->level,
    this->m_pBug->build,
    this->m_pBug->position,
    this->m_pBug->orientation);
  if ( this->m_pBug->screenshot_unc[0] != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "screenshot:  %s\n", this->m_pBug->screenshot_unc);
  if ( this->m_pBug->savegame_unc[0] != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "savegame:  %s\n", this->m_pBug->savegame_unc);
  if ( this->m_pBug->driverinfo[0] != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%s\n", this->m_pBug->driverinfo);
  if ( this->m_pBug->misc[0] != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%s\n", this->m_pBug->misc);
  if ( (buf.m_Flags & 1) != 0 && buf.m_Put != 0 && buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset - 1] == 10 )
    CUtlBuffer::PutTabs(this: &buf);
  if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
  {
    buf.m_Memory.m_pMemory[buf.m_Put++ - buf.m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
  }
  *bugSubmissionId = 0;
  zip = this->m_pBug->zip;
  if ( *zip != 0 )
    v5 = g_pFileSystem->Size(this: g_pFileSystem, a2: zip, a3: nullptr);
  else
    v5 = 0;
  m_pBug = this->m_pBug;
  v25 = v5;
  v24 = m_pBug->zip;
  osversion = m_pBug->osversion;
  dxdevice = m_pBug->dxdevice;
  dxvendor = m_pBug->dxvendor;
  dxversionlow = m_pBug->dxversionlow;
  dxversionhigh = m_pBug->dxversionhigh;
  processor = m_pBug->processor;
  cpu = m_pBug->cpu;
  ram = m_pBug->ram;
  submitter = m_pBug->submitter;
  owner = m_pBug->owner;
  reporttype = m_pBug->reporttype;
  level = m_pBug->level;
  gamedir = m_pBug->gamedir;
  exename = m_pBug->exename;
  m_pMemory = buf.m_Memory.m_pMemory;
  v8 = (const char *)m_pBug;
  v7 = atoi(nptr: m_pBug->build);
  if ( !UploadBugReport(
          cserIP: &this->m_cserIP,
          userid: &this->m_SteamID,
          build: v7,
          title: v8,
          body: (const char *)m_pMemory,
          exename,
          gamedir,
          mapname: level,
          reporttype,
          email: owner,
          accountname: submitter,
          ram,
          cpu,
          processor,
          high: dxversionhigh,
          low: dxversionlow,
          vendor: dxvendor,
          device: dxdevice,
          osversion,
          attachedfile: v24,
          attachedfilesize: v25) )
    _Msg(a1: "Unable to upload bug...\n");
  CBug::Clear(this: this->m_pBug);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002350
// Name: public: virtual void CBugReporter::StartNewBugReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::StartNewBugReport(CBugReporter *this)
{
  CBug *m_pBug; // ecx
  CBug *v3; // eax
  CBug *v4; // esi

  m_pBug = this->m_pBug;
  if ( m_pBug != nullptr )
  {
    CBug::Clear(this: m_pBug);
  }
  else
  {
    v3 = (CBug *)operator new(nSize: 0x412Cu);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3->includedfiles.m_Memory.m_pMemory = nullptr;
      v3->includedfiles.m_Memory.m_nAllocationCount = 0;
      v3->includedfiles.m_Memory.m_nGrowSize = 0;
      v3->includedfiles.m_Size = 0;
      v3->includedfiles.m_pElements = nullptr;
      CBug::Clear(this: v3);
      this->m_pBug = v4;
    }
    else
    {
      this->m_pBug = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100023C0
// Name: public: virtual CBugReporter::~CBugReporter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::~CBugReporter(CBugReporter *this)
{
  bool v2; // sf
  CBug *m_pBug; // eax
  CBug *pMem; // [esp+Ch] [ebp-8h]

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
  v2 = this->m_ReportType.m_Memory.m_nGrowSize < 0;
  this->m_ReportType.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_ReportType.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ReportType.m_Memory.m_pMemory);
      this->m_ReportType.m_Memory.m_pMemory = nullptr;
    }
    this->m_ReportType.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ReportType.m_pElements = this->m_ReportType.m_Memory.m_pMemory;
  m_pBug = this->m_pBug;
  pMem = m_pBug;
  if ( m_pBug != nullptr )
  {
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &m_pBug->includedfiles);
    free(pMem);
  }
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ReportType);
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_MapNumber);
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Area);
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Severity);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_BugStrings);
  this->__vftable = (CBugReporter_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10003F30
// Name: __heap_term
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall _heap_term(CBugReporter *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001820
// Name: __CreateCBugReporterIBugReporter_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBugReporter *__cdecl _CreateCBugReporterIBugReporter_interface()
{
  return &_g_CBugReporter_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x10003F32
// Name: closesocket(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall closesocket(SOCKET s)
{
  return __imp__closesocket@4(s);
}

//------------------------------------------------------------------------------
// Address: 0x10003F38
// Name: bind(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall bind(SOCKET s, const struct sockaddr *name, int namelen)
{
  return __imp__bind@12(s, name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x10003F3E
// Name: socket(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
SOCKET __stdcall socket(int af, int type, int protocol)
{
  return __imp__socket@12(af, type, protocol);
}

//------------------------------------------------------------------------------
// Address: 0x10003F44
// Name: __WSAFDIsSet(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall __WSAFDIsSet(SOCKET fd, fd_set *a2)
{
  return __imp____WSAFDIsSet@8(fd, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10003F4A
// Name: select(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timeval *timeout)
{
  return __imp__select@20(nfds, readfds, writefds, exceptfds, timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10003F50
// Name: recvfrom(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall recvfrom(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen)
{
  return __imp__recvfrom@24(s, buf, len, flags, from, fromlen);
}

//------------------------------------------------------------------------------
// Address: 0x10003F56
// Name: sendto(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall sendto(SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen)
{
  return __imp__sendto@24(s, buf, len, flags, to, tolen);
}

//------------------------------------------------------------------------------
// Address: 0x10003F5C
// Name: connect(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall connect(SOCKET s, const struct sockaddr *name, int namelen)
{
  return __imp__connect@12(s, name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x10003F62
// Name: send(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall send(SOCKET s, const char *buf, int len, int flags)
{
  return __imp__send@16(s, buf, len, flags);
}

//------------------------------------------------------------------------------
// Address: 0x10003F68
// Name: recv(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall recv(SOCKET s, char *buf, int len, int flags)
{
  return __imp__recv@16(s, buf, len, flags);
}

//------------------------------------------------------------------------------
// Address: 0x10003F6E
// Name: htons(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
u_short __stdcall htons(u_short hostshort)
{
  return __imp__htons@4(hostshort);
}
