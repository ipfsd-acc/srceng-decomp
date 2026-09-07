// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vprof_engine.cpp
// Functions: 57
// ============================================================

#include "engine\vprof_engine.h"

//------------------------------------------------------------------------------
// Address: 0x101EFE30
// Name: public: ConsoleLogger::ConsoleLogger(void)
// Source: json
//------------------------------------------------------------------------------
ConsoleLogger *__usercall ConsoleLogger::ConsoleLogger@<eax>(ConsoleLogger *this@<ecx>, int a2@<esi>)
{
  bool v2; // al
  const char *v4; // esi

  v2 = con_debuglog;
  this->m_condebugEnabled = con_debuglog;
  if ( !v2 )
  {
    ((void (__thiscall *)(IFileSystem *, const char *))g_pFileSystem->CreateDirHierarchy)(
      a1: g_pFileSystem,
      a2: "vprof");
    do
      v4 = va(format: "vprof/vprof%d.txt", ++ConsoleLogger::m_index);
    while ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v4, a3: nullptr) );
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: v4, a2);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EFEA0
// Name: vprof_dump_counters
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_dump_counters()
{
  g_bDumpCounters = true;
}

//------------------------------------------------------------------------------
// Address: 0x101EFEB0
// Name: void PostUpdateProfile(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PostUpdateProfile()
{
  if ( *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) != 0
    && vprof_dump_spikes.m_pParent->m_Value.m_fValue == 0.0
    && vprof_dump_oninterval.m_pParent->m_Value.m_fValue == 0.0 )
  {
    CVProfile::MarkFrame(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EFEF0
// Name: spike
// Source: json
//------------------------------------------------------------------------------
void __cdecl spike()
{
  Sys_Sleep(msec: 1000);
}

//------------------------------------------------------------------------------
// Address: 0x101EFF00
// Name: vprof_vtune_group
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
void __cdecl vprof_vtune_group(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc == 2 )
  {
    if ( _V_stricmp(s1: args->m_ppArgv[1], s2: "disable") != 0 )
    {
      v1 = defaultValue;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      _g_VProfCurrentProfile.m_nVTuneGroupID = CVProfile::BudgetGroupNameToBudgetGroupID(
                                                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                                 a2: v1);
      _g_VProfCurrentProfile.m_bVTuneGroupEnabled = true;
    }
    else
    {
      _g_VProfCurrentProfile.m_bVTuneGroupEnabled = false;
    }
  }
  else
  {
    _Warning(a1: "vprof_vtune_group groupName (disable to turn off)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EFF70
// Name: vprof_dump_groupnames
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_dump_groupnames()
{
  int NumBudgetGroups; // edi
  int i; // esi

  NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  for ( i = 0; i < NumBudgetGroups; ++i )
    _Msg(
      a1: "group %d: \"%s\"\n",
      i,
      *(const char **)(*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4276) + 8 * i));
}

//------------------------------------------------------------------------------
// Address: 0x101EFFC0
// Name: vprof_cachemiss_Impl
// Source: json
//------------------------------------------------------------------------------
char vprof_cachemiss_Impl()
{
  char result; // al

  if ( g_fVprofCacheMissOnByUI )
  {
    result = _Msg(a1: "VProf cache miss disabled.\n");
    *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4293) = 0;
    g_fVprofCacheMissOnByUI = false;
  }
  else
  {
    _Msg(a1: "VProf cache miss enabled.\n");
    *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4293) = 1;
    g_fVprofCacheMissOnByUI = true;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0010
// Name: vprof_cachemiss_on_Impl
// Source: json
//------------------------------------------------------------------------------
char vprof_cachemiss_on_Impl()
{
  char result; // al

  if ( !g_fVprofCacheMissOnByUI )
  {
    _Msg(a1: "VProf cache miss enabled.\n");
    *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4293) = 1;
    g_fVprofCacheMissOnByUI = true;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0040
// Name: vprof_cachemiss_off_Impl
// Source: json
//------------------------------------------------------------------------------
int vprof_cachemiss_off_Impl()
{
  int result; // eax

  if ( g_fVprofCacheMissOnByUI )
  {
    _Msg(a1: "VProf cache miss disabled.\n");
    *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4293) = 0;
    g_fVprofCacheMissOnByUI = false;
    return *(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0070
// Name: vprof_Impl
// Source: json
//------------------------------------------------------------------------------
void vprof_Impl()
{
  if ( g_fVprofOnByUI )
  {
    _Msg(a1: "VProf disabled.\n");
    if ( (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1 )
      CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_fVprofOnByUI = false;
  }
  else
  {
    _Msg(a1: "VProf enabled.\n");
    if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
      CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_fVprofOnByUI = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F00E0
// Name: budget_toggle_group
// Source: json
//------------------------------------------------------------------------------
void __cdecl budget_toggle_group(const CCommand *args)
{
  int BudgetGroupName; // eax

  if ( args->m_nArgc == 2 )
  {
    BudgetGroupName = CVProfile::FindBudgetGroupName(
                        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                        a2: args->m_ppArgv[1]);
    if ( BudgetGroupName != -1 )
      CVProfile::HideBudgetGroup(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: BudgetGroupName,
        a3: (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4276)
                   + 8 * BudgetGroupName
                   + 4)
       & 0x8000) == 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0130
// Name: vprof_off_Impl
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall vprof_off_Impl(int a1@<ecx>, int a2@<esi>)
{
  int v3; // [esp-2h] [ebp-4h] OVERLAPPED BYREF

  v3 = a1;
  if ( g_fVprofOnByUI )
  {
    _Msg(a1: "VProf disabled.\n");
    if ( (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1 )
      CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_fVprofOnByUI = false;
    if ( g_szDefferedArg1[0] != 0 && _V_stricmp(s1: "infested", s2: g_szDefferedArg1) == 0 )
    {
      ConsoleLogger::ConsoleLogger(this: (ConsoleLogger *)&v3 + 3, a2);
      CVProfile::OutputReport(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: -519,
        a3: nullptr,
        a4: -1);
      if ( HIBYTE(v3) == 0 )
        CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F01C0
// Name: vprof_reset_Impl
// Source: json
//------------------------------------------------------------------------------
void vprof_reset_Impl()
{
  CVProfPanel *VProfPanel; // eax

  _Msg(a1: "VProf reset.\n");
  CVProfNode::Reset(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4264) = 0;
  if ( GetVProfPanel() != nullptr )
  {
    VProfPanel = GetVProfPanel();
    CVProfPanel::Reset(this: VProfPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0210
// Name: vprof_reset_peaks_Impl
// Source: json
//------------------------------------------------------------------------------
void vprof_reset_peaks_Impl()
{
  _Msg(a1: "VProf peaks reset.\n");
  CVProfNode::ResetPeak(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
}

//------------------------------------------------------------------------------
// Address: 0x101F0230
// Name: vprof_generate_report_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall vprof_generate_report_Impl(int a1@<esi>)
{
  bool v1; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF
  int savedregs; // [esp+2h] [ebp+0h]

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog, a2: a1);
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: -519,
    a3: g_szDefferedArg1[0] != 0 ? g_szDefferedArg1 : nullptr,
    a4: -1);
  v1 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x101F02B0
// Name: vprof_generate_report_budget_Impl
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall vprof_generate_report_budget_Impl(int a1@<ecx>, int a2@<esi>)
{
  int v2; // eax
  bool v3; // zf
  int v4; // [esp-2h] [ebp-4h] OVERLAPPED BYREF

  v4 = a1;
  if ( g_szDefferedArg1[0] != 0 )
  {
    CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    ConsoleLogger::ConsoleLogger(this: (ConsoleLogger *)&v4 + 3, a2);
    v2 = CVProfile::BudgetGroupNameToBudgetGroupID(
           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
           a2: g_szDefferedArg1);
    CVProfile::OutputReport(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: -519,
      a3: nullptr,
      a4: v2);
    v3 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
    *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                            + 4272);
    if ( v3 )
      CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    if ( HIBYTE(v4) == 0 )
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0340
// Name: vprof_generate_report_hierarchy_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall vprof_generate_report_hierarchy_Impl(int a1@<esi>)
{
  bool v1; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF
  int savedregs; // [esp+2h] [ebp+0h]

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog, a2: a1);
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: 2,
    a3: g_szDefferedArg1[0] != 0 ? g_szDefferedArg1 : nullptr,
    a4: -1);
  v1 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x101F03C0
// Name: vprof_generate_report_hierarchy_per_frame_and_count_only_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall vprof_generate_report_hierarchy_per_frame_and_count_only_Impl(int a1@<esi>)
{
  bool v1; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF
  int savedregs; // [esp+2h] [ebp+0h]

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog, a2: a1);
  CVProfile::OutputReport(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: 4, a3: nullptr, a4: -1);
  v1 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x101F0430
// Name: vprof_generate_report_AI_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall vprof_generate_report_AI_Impl(int a1@<esi>)
{
  bool v1; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF
  int savedregs; // [esp+2h] [ebp+0h]

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog, a2: a1);
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: -519,
    a3: "NPCs",
    a4: -1);
  v1 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x101F04A0
// Name: vprof_generate_report_AI_only_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall vprof_generate_report_AI_only_Impl(int a1@<esi>)
{
  int v1; // eax
  bool v2; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF
  int savedregs; // [esp+2h] [ebp+0h]

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog, a2: a1);
  v1 = CVProfile::BudgetGroupNameToBudgetGroupID(
         this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
         a2: "NPCs");
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: -519,
    a3: "NPCs",
    a4: v1);
  v2 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v2 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x101F0520
// Name: vprof_generate_report_map_load_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall vprof_generate_report_map_load_Impl(int a1@<esi>)
{
  bool v1; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF
  int savedregs; // [esp+2h] [ebp+0h]

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog, a2: a1);
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: -517,
    a3: "Host_NewGame",
    a4: -1);
  v1 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x101F0590
// Name: public: virtual void CVProfExport::AddListener(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::AddListener(CVProfExport *this)
{
  if ( ++this->m_nListeners == 1 )
    this->m_bStart = true;
}

//------------------------------------------------------------------------------
// Address: 0x101F05B0
// Name: public: virtual void CVProfExport::RemoveListener(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::RemoveListener(CVProfExport *this)
{
  if ( this->m_nListeners-- == 1 )
    this->m_bStop = true;
}

//------------------------------------------------------------------------------
// Address: 0x101F05C0
// Name: void VProfExport_Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VProfExport_Pause(CVProfExport *this)
{
  if ( materials != nullptr )
    materials->Flush(this: materials, a2: false);
  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101F0600
// Name: void VProfExport_StartOrStop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfExport_StartOrStop()
{
  if ( g_VProfExport.m_bStart )
  {
    if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
      CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_VProfExport.m_bStart = false;
  }
  if ( g_VProfExport.m_bStop )
  {
    if ( (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1 )
      CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_VProfExport.m_bStop = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0660
// Name: public: virtual void CVProfExport::ResumeProfile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::ResumeProfile(CVProfExport *this)
{
  bool v1; // zf

  if ( materials != nullptr )
    materials->Flush(this: materials, a2: false);
  v1 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
}

//------------------------------------------------------------------------------
// Address: 0x101F06A0
// Name: void OverrideVProfExport(class IVProfExport __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverrideVProfExport(IVProfExport *pExport)
{
  if ( g_pVProfExport == &g_VProfExport )
    g_pVProfExport = pExport;
}

//------------------------------------------------------------------------------
// Address: 0x101F06C0
// Name: void ResetVProfExport(class IVProfExport __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResetVProfExport(IVProfExport *pExport)
{
  if ( g_pVProfExport == pExport )
    g_pVProfExport = &g_VProfExport;
}

//------------------------------------------------------------------------------
// Address: 0x101F06E0
// Name: vprof_cachemiss
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_cachemiss(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_cachemiss_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0740
// Name: vprof_cachemiss_on
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_cachemiss_on(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_cachemiss_on_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F07A0
// Name: vprof_cachemiss_off
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_cachemiss_off(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_cachemiss_off_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0800
// Name: vprof
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0860
// Name: vprof_on_Impl
// Source: json
//------------------------------------------------------------------------------
void vprof_on_Impl()
{
  if ( !g_fVprofOnByUI )
  {
    _Msg(a1: "VProf enabled.\n");
    if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
      CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_fVprofOnByUI = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F08B0
// Name: vprof_off
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_off(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_off_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0910
// Name: vprof_reset
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_reset(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_reset_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0970
// Name: vprof_reset_peaks
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_reset_peaks(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_reset_peaks_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F09D0
// Name: vprof_generate_report
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0A30
// Name: vprof_generate_report_budget
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_budget(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_budget_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0A90
// Name: vprof_generate_report_hierarchy
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_hierarchy(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_hierarchy_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0AF0
// Name: vprof_generate_report_hierarchy_per_frame_and_count_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_hierarchy_per_frame_and_count_only(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_hierarchy_per_frame_and_count_only_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0B50
// Name: vprof_generate_report_AI
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_AI(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_AI_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0BB0
// Name: vprof_generate_report_AI_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_AI_only(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_AI_only_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0C10
// Name: vprof_generate_report_map_load
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_map_load(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_map_load_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0C70
// Name: vprof_on
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_on(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_on_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0CD0
// Name: public: void CVProfExport::GetAllBudgetGroupTimes(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::GetAllBudgetGroupTimes(CVProfExport *this, float *pTimes)
{
  float *v3; // ebx
  int NumBudgetGroups; // esi
  int v5; // eax
  int v6; // eax
  int *p_m_BudgetFlags; // edx
  unsigned int v8; // esi
  float *v9; // ecx
  int v10; // xmm1_4
  int v11; // xmm1_4
  float v12; // xmm1_4
  int v13; // xmm1_4
  int *v14; // ecx
  float v15; // xmm1_4
  int nTotalGroups; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int v18; // [esp+1Ch] [ebp-4h]

  v3 = pTimes;
  NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  v5 = 0;
  nTotalGroups = NumBudgetGroups;
  if ( NumBudgetGroups >= 4 )
  {
    v6 = -8 - (_DWORD)pTimes;
    p_m_BudgetFlags = &g_pVProfileForDisplay->m_pBudgetGroups[1].m_BudgetFlags;
    v8 = ((unsigned int)(NumBudgetGroups - 4) >> 2) + 1;
    v9 = pTimes + 2;
    v18 = 2;
    i = 4 * v8;
    do
    {
      if ( (*(p_m_BudgetFlags - 2) & this->m_BudgetFlagsFilter) != 0 )
        v10 = *(_DWORD *)((char *)this->m_Times.m_Memory.m_pMemory + v6 + (unsigned int)v9);
      else
        v10 = 0;
      *((_DWORD *)v9 - 2) = v10;
      if ( (*p_m_BudgetFlags & this->m_BudgetFlagsFilter) != 0 )
        v11 = *(_DWORD *)((char *)this->m_Times.m_Memory.m_pMemory + v6 + (unsigned int)v9 + 4);
      else
        v11 = 0;
      *((_DWORD *)v9 - 1) = v11;
      if ( (p_m_BudgetFlags[2] & this->m_BudgetFlagsFilter) != 0 )
      {
        v12 = this->m_Times.m_Memory.m_pMemory[v18];
        v6 = -8 - (_DWORD)pTimes;
      }
      else
      {
        v12 = 0.0;
      }
      *v9 = v12;
      if ( (p_m_BudgetFlags[4] & this->m_BudgetFlagsFilter) != 0 )
      {
        v13 = *(_DWORD *)((char *)this->m_Times.m_Memory.m_pMemory + 4 - (_DWORD)pTimes + (unsigned int)v9);
        v6 = -8 - (_DWORD)pTimes;
      }
      else
      {
        v13 = 0;
      }
      v18 += 4;
      *((_DWORD *)v9 + 1) = v13;
      v9 += 4;
      p_m_BudgetFlags += 8;
      --v8;
    }
    while ( v8 != 0 );
    v5 = i;
    v3 = pTimes;
    NumBudgetGroups = nTotalGroups;
  }
  if ( v5 < NumBudgetGroups )
  {
    v14 = &g_pVProfileForDisplay->m_pBudgetGroups[v5].m_BudgetFlags;
    do
    {
      if ( (*v14 & this->m_BudgetFlagsFilter) != 0 )
        v15 = this->m_Times.m_Memory.m_pMemory[v5];
      else
        v15 = 0.0;
      v3[v5++] = v15;
      v14 += 2;
    }
    while ( v5 < NumBudgetGroups );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0E10
// Name: public: void CVProfExport::CalculateBudgetGroupTimes_Recursive(class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::CalculateBudgetGroupTimes_Recursive(CVProfExport *this, CVProfNode *pNode)
{
  CVProfNode *v2; // edx
  CVProfile *v4; // eax
  int m_BudgetFlags; // ecx
  int v6; // esi
  double PrevTimeLessChildren; // st7
  int m_Size; // eax

  v2 = pNode;
  v4 = (CVProfile *)pNode;
  if ( pNode != &g_pVProfileForDisplay->m_Root )
  {
    do
    {
      m_BudgetFlags = g_pVProfileForDisplay->m_pBudgetGroups[v4->m_GroupIDStack[31]].m_BudgetFlags;
      if ( (this->m_BudgetFlagsFilter & m_BudgetFlags) != 0 && (m_BudgetFlags & 0x8000) == 0 )
        break;
      v4 = (CVProfile *)v4->m_GroupIDStack[28];
    }
    while ( v4 != (CVProfile *)&g_pVProfileForDisplay->m_Root );
    v2 = pNode;
  }
  v6 = v4->m_GroupIDStack[31];
  PrevTimeLessChildren = CVProfNode::GetPrevTimeLessChildren(this: v2);
  if ( v6 >= 0 )
  {
    m_Size = this->m_Times.m_Size;
    if ( m_Size >= 512 )
      m_Size = 512;
    if ( v6 < m_Size )
      this->m_Times.m_Memory.m_pMemory[v6] = PrevTimeLessChildren + this->m_Times.m_Memory.m_pMemory[v6];
  }
  if ( pNode->m_pSibling != nullptr )
    CVProfExport::CalculateBudgetGroupTimes_Recursive(this, pNode: pNode->m_pSibling);
  if ( pNode->m_pChild != nullptr )
    CVProfExport::CalculateBudgetGroupTimes_Recursive(this, pNode: pNode->m_pChild);
  if ( !VProfRecord_IsPlayingBack() )
    CVProfNode::ClearPrevTime(this: pNode);
}

//------------------------------------------------------------------------------
// Address: 0x101F0ED0
// Name: public: virtual int CVProfExport::GetNumBudgetGroups(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfExport::GetNumBudgetGroups(CVProfExport *this)
{
  int m_Size; // edi
  int NumBudgetGroups; // edx
  int result; // eax
  int m_BudgetFlagsFilter; // esi
  int *p_m_BudgetFlags; // ecx

  m_Size = this->m_Times.m_Size;
  if ( m_Size >= CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay) )
    NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  else
    NumBudgetGroups = this->m_Times.m_Size;
  result = 0;
  if ( NumBudgetGroups > 0 )
  {
    m_BudgetFlagsFilter = this->m_BudgetFlagsFilter;
    p_m_BudgetFlags = &g_pVProfileForDisplay->m_pBudgetGroups->m_BudgetFlags;
    do
    {
      if ( (m_BudgetFlagsFilter & *p_m_BudgetFlags) != 0 )
        ++result;
      p_m_BudgetFlags += 2;
      --NumBudgetGroups;
    }
    while ( NumBudgetGroups != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0F20
// Name: public: virtual void CVProfExport::GetBudgetGroupInfos(class IVProfExport::CExportedBudgetGroupInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::GetBudgetGroupInfos(CVProfExport *this, IVProfExport::CExportedBudgetGroupInfo *pInfos)
{
  int m_Size; // esi
  int NumBudgetGroups; // eax
  int v5; // esi
  CVProfile *v6; // eax
  int *p_m_BudgetFlags; // edi
  int alpha; // [esp+Ch] [ebp-18h] BYREF
  int blue; // [esp+10h] [ebp-14h] BYREF
  int green; // [esp+14h] [ebp-10h] BYREF
  int red; // [esp+18h] [ebp-Ch] BYREF
  CVProfExport *v12; // [esp+1Ch] [ebp-8h]
  int v13; // [esp+20h] [ebp-4h]
  IVProfExport::CExportedBudgetGroupInfo *pInfosa; // [esp+2Ch] [ebp+8h]

  m_Size = this->m_Times.m_Size;
  v12 = this;
  if ( m_Size >= CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay) )
    NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  else
    NumBudgetGroups = this->m_Times.m_Size;
  v5 = 0;
  v13 = NumBudgetGroups;
  if ( NumBudgetGroups > 0 )
  {
    v6 = g_pVProfileForDisplay;
    p_m_BudgetFlags = &pInfos->m_BudgetFlags;
    do
    {
      if ( (v6->m_pBudgetGroups[v5].m_BudgetFlags & v12->m_BudgetFlagsFilter) != 0 )
      {
        *(p_m_BudgetFlags - 1) = (int)v6->m_pBudgetGroups[v5].m_pName;
        CVProfile::GetBudgetGroupColor(this: g_pVProfileForDisplay, a2: v5, a3: &red, a4: &green, a5: &blue, a6: &alpha);
        LOBYTE(pInfosa) = red;
        BYTE1(pInfosa) = green;
        BYTE2(pInfosa) = blue;
        HIBYTE(pInfosa) = alpha;
        p_m_BudgetFlags[1] = (int)pInfosa;
        *p_m_BudgetFlags = g_pVProfileForDisplay->m_pBudgetGroups[v5].m_BudgetFlags;
        v6 = g_pVProfileForDisplay;
        p_m_BudgetFlags += 3;
      }
      ++v5;
    }
    while ( v5 < v13 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0FF0
// Name: public: virtual void CVProfExport::GetBudgetGroupTimes(float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::GetBudgetGroupTimes(CVProfExport *this, float *times)
{
  int m_Size; // edi
  int NumBudgetGroups; // ebx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int *i; // edx
  float *v9; // ecx
  int *p_m_BudgetFlags; // edx
  int v11; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Times.m_Size;
  if ( m_Size >= CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay) )
    NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  else
    NumBudgetGroups = this->m_Times.m_Size;
  v11 = NumBudgetGroups;
  v5 = NumBudgetGroups;
  if ( NumBudgetGroups >= 512 )
    v5 = 512;
  memset(dst: (unsigned __int8 *)times, value: 0, count: 4 * v5);
  v6 = 0;
  v7 = 0;
  if ( NumBudgetGroups >= 4 )
  {
    for ( i = &g_pVProfileForDisplay->m_pBudgetGroups[1].m_BudgetFlags; ; i += 8 )
    {
      if ( (*(i - 2) & this->m_BudgetFlagsFilter) != 0 )
        times[v6++] = this->m_Times.m_Memory.m_pMemory[v7];
      if ( (this->m_BudgetFlagsFilter & *i) != 0 )
        times[v6++] = this->m_Times.m_Memory.m_pMemory[v7 + 1];
      if ( (i[2] & this->m_BudgetFlagsFilter) != 0 )
        times[v6++] = this->m_Times.m_Memory.m_pMemory[v7 + 2];
      if ( (i[4] & this->m_BudgetFlagsFilter) != 0 )
        times[v6++] = this->m_Times.m_Memory.m_pMemory[v7 + 3];
      NumBudgetGroups = v11;
      v7 += 4;
      if ( v7 >= v11 - 3 )
        break;
    }
  }
  if ( v7 < NumBudgetGroups )
  {
    v9 = &times[v6];
    p_m_BudgetFlags = &g_pVProfileForDisplay->m_pBudgetGroups[v7].m_BudgetFlags;
    do
    {
      if ( (this->m_BudgetFlagsFilter & *p_m_BudgetFlags) != 0 )
        *v9++ = this->m_Times.m_Memory.m_pMemory[v7];
      ++v7;
      p_m_BudgetFlags += 2;
    }
    while ( v7 < NumBudgetGroups );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1110
// Name: void WriteRemoteVProfGroupData(struct VProfListenInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteRemoteVProfGroupData(VProfListenInfo_t *info)
{
  VProfListenInfo_t *v1; // edi
  int NumBudgetGroups; // esi
  void *v3; // esp
  CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *p_m_SentGroups; // esi
  int m_Size; // eax
  int v6; // edi
  int v7; // ebx
  const char *v8; // eax
  int v9; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  int v15; // eax
  int v16; // edi
  int v17; // esi
  int v18; // edi
  unsigned __int8 v19; // bl
  unsigned __int8 v20; // bl
  unsigned __int8 v21; // bl
  unsigned __int8 v22; // bl
  int v23; // [esp+0h] [ebp-58h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-4Ch] BYREF
  int nGroupCount; // [esp+3Ch] [ebp-1Ch]
  int alpha; // [esp+40h] [ebp-18h]
  int *pIndex; // [esp+44h] [ebp-14h]
  int red; // [esp+48h] [ebp-10h]
  int green; // [esp+4Ch] [ebp-Ch]
  int nSendCount; // [esp+50h] [ebp-8h]
  int blue; // [esp+54h] [ebp-4h]

  v1 = info;
  NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  red = info->m_SentGroups.m_Size;
  nGroupCount = NumBudgetGroups;
  nSendCount = 0;
  v3 = alloca(4 * NumBudgetGroups);
  pIndex = &v23;
  blue = 0;
  if ( NumBudgetGroups > 0 )
  {
    p_m_SentGroups = (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&info->m_SentGroups;
    while ( 1 )
    {
      m_Size = v1->m_SentGroups.m_Size;
      v6 = 0;
      green = (int)g_pVProfileForDisplay->m_pBudgetGroups[blue].m_pName;
      alpha = m_Size;
      if ( m_Size <= 0 )
        goto LABEL_10;
      v7 = 0;
      while ( 1 )
      {
        v8 = CUtlString::Get(this: (CUtlString *)&p_m_SentGroups->m_pMemory[v7]);
        if ( _V_strcmp(s1: (const char *)green, s2: v8) == 0 )
          break;
        ++v6;
        ++v7;
        if ( v6 >= alpha )
          goto LABEL_10;
      }
      if ( v6 < 0 )
      {
LABEL_10:
        v9 = info->m_SentGroups.m_Size;
        m_nAllocationCount = info->m_SentGroups.m_Memory.m_nAllocationCount;
        if ( v9 + 1 > m_nAllocationCount )
          CUtlMemory<CPortalRect,int>::Grow(this: p_m_SentGroups, num: v9 - m_nAllocationCount + 1);
        ++info->m_SentGroups.m_Size;
        m_pMemory = p_m_SentGroups->m_pMemory;
        v12 = info->m_SentGroups.m_Size - v9 - 1;
        info->m_SentGroups.m_pElements = info->m_SentGroups.m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 16 * v12);
        v13 = v9;
        v14 = (CUtlString *)&p_m_SentGroups->m_pMemory[v13];
        if ( v14 != nullptr )
          CUtlString::CUtlString(this: v14);
        CUtlString::operator=(this: (CUtlString *)&p_m_SentGroups->m_pMemory[v13], src: (char *)green);
        v15 = nSendCount;
        pIndex[nSendCount] = blue;
        nSendCount = v15 + 1;
      }
      if ( ++blue >= nGroupCount )
        break;
      v1 = info;
    }
    v16 = nSendCount;
    if ( nSendCount != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 1024, initSize: 1024, nFlags: 0);
      if ( (buf.m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: &buf, pFmt: "%d", red);
      else
        CUtlBuffer::PutTypeBin<int>(this: &buf, src: red);
      if ( (buf.m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: &buf, pFmt: "%d", v16);
      else
        CUtlBuffer::PutTypeBin<int>(this: &buf, src: v16);
      v17 = 0;
      if ( v16 > 0 )
      {
        do
        {
          v18 = pIndex[v17];
          CVProfile::GetBudgetGroupColor(this: g_pVProfileForDisplay, a2: v18);
          if ( (buf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &buf, pFmt: "%hu", (unsigned __int8)red);
          }
          else
          {
            v19 = red;
            if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) != 0 )
            {
              buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v19;
              CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
            }
          }
          if ( (buf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &buf, pFmt: "%hu", (unsigned __int8)green);
          }
          else
          {
            v20 = green;
            if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) != 0 )
            {
              buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v20;
              CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
            }
          }
          if ( (buf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &buf, pFmt: "%hu", (unsigned __int8)blue);
          }
          else
          {
            v21 = blue;
            if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) != 0 )
            {
              buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v21;
              CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
            }
          }
          if ( (buf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &buf, pFmt: "%hu", (unsigned __int8)alpha);
          }
          else
          {
            v22 = alpha;
            if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) != 0 )
            {
              buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v22;
              CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
            }
          }
          CUtlBuffer::PutString(this: &buf, pString: g_pVProfileForDisplay->m_pBudgetGroups[v18].m_pName);
          ++v17;
        }
        while ( v17 < nSendCount );
      }
      CServerRemoteAccess::SendVProfData(
        this: &g_ServerRemoteAccess,
        listenerID: info->m_nListenerId,
        bGroupData: true,
        data: buf.m_Memory.m_pMemory,
        len: buf.m_nMaxPut);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1450
// Name: void WriteRemoteVProfData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WriteRemoteVProfData(CStatTime *this)
{
  int v1; // eax
  int m_Size; // edi
  float *i; // edx
  void *v4; // esp
  int v5; // esi
  int v6; // edi
  void *v7; // esp
  int *p_nSentSize; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  int v12; // esi
  const char *v13; // eax
  double v14; // st7
  float *v15; // ecx
  bool v16; // zf
  int nSentSize; // [esp+0h] [ebp-2Ch] BYREF
  float *pTimes; // [esp+4h] [ebp-28h]
  char *s1; // [esp+8h] [ebp-24h]
  _DWORD *v20; // [esp+Ch] [ebp-20h]
  int v21; // [esp+10h] [ebp-1Ch]
  float *pSentTimes; // [esp+14h] [ebp-18h]
  int nGroupCount; // [esp+18h] [ebp-14h]
  float flMaxDelta; // [esp+1Ch] [ebp-10h]
  int v25; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]
  float flTime; // [esp+28h] [ebp-4h]

  flMaxDelta = rpt_vprof_time.m_pParent->m_Value.m_fValue;
  flTime = _Plat_FloatTime(this);
  v1 = 0;
  m_Size = s_VProfListeners.m_Size;
  if ( s_VProfListeners.m_Size > 0 )
  {
    for ( i = &s_VProfListeners.m_Memory.m_pMemory->m_flLastSentVProfDataTime; (float)(flTime - *i) < flMaxDelta; i += 7 )
    {
      if ( ++v1 >= s_VProfListeners.m_Size )
        return;
    }
    nGroupCount = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
    v4 = alloca(4 * nGroupCount);
    pTimes = (float *)&nSentSize;
    CVProfExport::GetAllBudgetGroupTimes(this: &g_VProfExport, pTimes: (float *)&nSentSize);
    v5 = 0;
    v25 = 0;
    v21 = m_Size;
    do
    {
      if ( flMaxDelta <= (float)(flTime
                               - *(float *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_flLastSentVProfDataTime + v5)) )
      {
        WriteRemoteVProfGroupData(info: (VProfListenInfo_t *)((char *)s_VProfListeners.m_Memory.m_pMemory + v5));
        *(float *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_flLastSentVProfDataTime + v5) = flTime;
        nSentSize = 4 * *(int *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_SentGroups.m_Size + v5);
        v6 = nSentSize;
        v7 = alloca(nSentSize);
        p_nSentSize = &nSentSize;
        pSentTimes = (float *)&nSentSize;
        memset(dst: (unsigned __int8 *)&nSentSize, value: 0, count: nSentSize);
        v9 = 0;
        j = 0;
        if ( nGroupCount > 0 )
        {
          do
          {
            s1 = g_pVProfileForDisplay->m_pBudgetGroups[v9].m_pName;
            v10 = *(int *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_SentGroups.m_Size + v5);
            v11 = 0;
            if ( v10 <= 0 )
            {
LABEL_14:
              v11 = -1;
            }
            else
            {
              v20 = (CUtlString **)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_SentGroups.m_Memory.m_pMemory + v5);
              v12 = 0;
              while ( 1 )
              {
                v13 = CUtlString::Get(this: (CUtlString *)(v12 + *v20));
                if ( _V_strcmp(s1, s2: v13) == 0 )
                  break;
                ++v11;
                v12 += 16;
                if ( v11 >= v10 )
                {
                  v9 = j;
                  v5 = v25;
                  goto LABEL_14;
                }
              }
              v9 = j;
              v5 = v25;
            }
            v14 = pTimes[v9];
            v15 = pSentTimes;
            ++v9;
            pSentTimes[v11] = v14;
            j = v9;
          }
          while ( v9 < nGroupCount );
          v6 = nSentSize;
          p_nSentSize = (int *)v15;
        }
        CServerRemoteAccess::SendVProfData(
          this: &g_ServerRemoteAccess,
          listenerID: *(unsigned int *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_nListenerId + v5),
          bGroupData: false,
          data: p_nSentSize,
          len: v6);
      }
      v5 += 28;
      v16 = v21-- == 1;
      v25 = v5;
    }
    while ( !v16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1610
// Name: public: void CVProfExport::SnapshotVProfHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::SnapshotVProfHistory(CVProfExport *this)
{
  int m_Size; // ebx
  int NumBudgetGroups; // eax
  float *m_pMemory; // ebx
  int v5; // eax
  CVProfNode *m_pChild; // eax

  if ( g_pVProfileForDisplay->m_enabled != 0 )
  {
    m_Size = this->m_Times.m_Size;
    if ( m_Size < CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay) )
    {
      NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
      this->m_Times.m_Size = 0;
      CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_Times,
        elem: 0,
        num: NumBudgetGroups);
    }
    m_pMemory = this->m_Times.m_Memory.m_pMemory;
    v5 = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
    memset(dst: (unsigned __int8 *)m_pMemory, value: 0, count: 4 * v5);
    if ( g_pVProfileForDisplay != (CVProfile *)-4120 )
    {
      m_pChild = g_pVProfileForDisplay->m_Root.m_pChild;
      if ( m_pChild != nullptr )
        CVProfExport::CalculateBudgetGroupTimes_Recursive(this, pNode: m_pChild);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1690
// Name: void PreUpdateProfile(float)
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
void __usercall PreUpdateProfile(int a1@<esi>, float filteredtime)
{
  CVProfile *v2; // ecx
  bool v3; // zf
  CStatTime *v4; // ecx
  double v5; // st7
  char *v6; // ecx
  int v7; // eax
  char *v8; // eax
  char *v9; // ecx
  CStatTime *v10; // ecx
  char *v11; // ecx
  int v12; // edi
  char *v13; // ecx
  int v14; // eax
  char *m_pszString; // eax
  char *v16; // ecx
  char *v17; // ecx
  bool v18; // cc
  int v19; // esi
  int m_nValue; // esi
  int NumCounters; // ebx
  int v22; // edi
  const char *CounterNameAndValue; // eax
  const char *v24; // esi
  int v25; // ecx
  int *p_m_nGrowSize; // eax
  int v27; // eax
  int v28; // edx
  int *p_m_Size; // esi
  int v30; // ebx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  int v34; // eax
  int v35; // edx
  int v36; // eax
  CVProfPanel *VProfPanel; // eax
  int v38; // [esp+Ch] [ebp-50h]
  const char *v39; // [esp+34h] [ebp-28h]
  int v40; // [esp+3Ch] [ebp-20h]
  float v41; // [esp+40h] [ebp-1Ch]
  float v42; // [esp+40h] [ebp-1Ch]
  int v43; // [esp+40h] [ebp-1Ch]
  float m_fValue; // [esp+44h] [ebp-18h]
  int v45; // [esp+44h] [ebp-18h]
  S3RGBA v46; // [esp+48h] [ebp-14h]
  S3RGBA v47; // [esp+4Ch] [ebp-10h]
  unsigned int idx; // [esp+50h] [ebp-Ch]
  S3RGBA v49; // [esp+54h] [ebp-8h] BYREF
  ConsoleLogger v50; // [esp+5Ah] [ebp-2h] BYREF
  char v51; // [esp+5Bh] [ebp-1h]

  if ( g_pfnDeferredOp != nullptr )
  {
    g_pfnDeferredOp();
    g_pfnDeferredOp = nullptr;
  }
  VProfExport_StartOrStop();
  VProfRecord_StartOrStop();
  v2 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  if ( *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 6604) != g_VProfTargetThread )
  {
    *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 6604) = g_VProfTargetThread;
    v2 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  }
  if ( v2->m_enabled != 0 )
  {
    if ( vprof_dump_oninterval.m_pParent->m_Value.m_fValue != 0.0 )
    {
      v41 = eng->GetCurTime(this: eng);
      m_fValue = vprof_dump_oninterval.m_pParent->m_Value.m_fValue;
      CVProfile::MarkFrame(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      v2 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
      if ( v41 > (float)(s_flIntervalStartTime + m_fValue) )
      {
        CVProfile::OutputReport(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: 569,
          a3: nullptr,
          a4: -1);
        v3 = (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1;
        if ( v3 )
          CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
        a1 = *(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
        CVProfNode::Reset(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
        *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4264) = 0;
        if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
          CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
        v2 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
        s_flIntervalStartTime = v41;
      }
    }
    if ( v2->m_enabled != 0 && vprof_dump_spikes.m_pParent->m_Value.m_fValue != 0.0 )
    {
      v42 = vprof_dump_spikes.m_pParent->m_Value.m_fValue;
      CVProfile::MarkFrame(this: v2);
      v51 = 0;
      if ( !_g_VProfSignalSpike )
      {
        if ( ((double (__thiscall *)(IEngine *))eng->GetFrameTime)(a1: eng) <= 1.0 / fabs(v42) )
          goto LABEL_67;
        if ( !_g_VProfSignalSpike
          && (_Plat_FloatTime(this: *(CStatTime **)&_g_VProfSignalSpike) - LastSpikeTime <= 1.0
           || g_ServerGlobalVariables.framecount <= LastSpikeFrame + 10) )
        {
LABEL_66:
          _g_VProfSignalSpike = false;
LABEL_67:
          v2 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
          v19 = 0;
          do
          {
            v3 = v2->m_enabled-- == 1;
            if ( v3 )
              CVProfNode::ExitScope(this: &v2->m_Root);
            v2 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
            ++v19;
          }
          while ( *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) != 0 );
          if ( v51 == 0 )
          {
            CVProfNode::Reset(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
            *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4264) = 0;
            while ( v19 != 0 )
            {
              ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108);
              --v19;
              if ( *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
                CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                          + 4120));
            }
            v2 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
          }
          goto LABEL_77;
        }
      }
      ConsoleLogger::ConsoleLogger(this: &v50, a2: a1);
      v5 = _Plat_FloatTime(this: v4);
      _Msg(a1: "******** Spike on frame %d at time %.3f ", g_ServerGlobalVariables.framecount, v5);
      if ( vprof_dump_spikes_hierarchy.m_pParent == nullptr
        || vprof_dump_spikes_hierarchy.m_pParent->m_Value.m_nValue == 0 )
      {
        if ( vprof_dump_spikes_terse.m_pParent != nullptr && vprof_dump_spikes_terse.m_pParent->m_Value.m_nValue != 0 )
          v12 = 520;
        else
          v12 = 569;
        if ( (vprof_dump_spikes_budget_group.m_nFlags & 0x1000) != 0
          || (v13 = vprof_dump_spikes_budget_group.m_pParent->m_Value.m_pszString) != nullptr && *v13 != 0 )
        {
          if ( (vprof_dump_spikes_budget_group.m_nFlags & 0x1000) != 0 )
          {
            v14 = CVProfile::BudgetGroupNameToBudgetGroupID(
                    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                    a2: "FCVAR_NEVER_AS_STRING");
          }
          else
          {
            m_pszString = vprof_dump_spikes_budget_group.m_pParent->m_Value.m_pszString;
            if ( m_pszString == nullptr )
              m_pszString = (char *)defaultValue;
            v14 = CVProfile::BudgetGroupNameToBudgetGroupID(
                    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                    a2: m_pszString);
          }
        }
        else
        {
          v14 = -1;
        }
        if ( (vprof_dump_spikes_node.m_nFlags & 0x1000) != 0
          || (v16 = vprof_dump_spikes_node.m_pParent->m_Value.m_pszString) != nullptr && *v16 != 0 )
        {
          if ( (vprof_dump_spikes_node.m_nFlags & 0x1000) != 0 )
          {
            v17 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v17 = vprof_dump_spikes_node.m_pParent->m_Value.m_pszString;
            if ( v17 == nullptr )
              v17 = (char *)defaultValue;
          }
        }
        else
        {
          v17 = nullptr;
        }
        CVProfile::OutputReport(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: v12,
          a3: v17,
          a4: v14);
        goto LABEL_62;
      }
      if ( (vprof_dump_spikes_budget_group.m_nFlags & 0x1000) != 0
        || (v6 = vprof_dump_spikes_budget_group.m_pParent->m_Value.m_pszString) != nullptr && *v6 != 0 )
      {
        if ( (vprof_dump_spikes_budget_group.m_nFlags & 0x1000) != 0 )
        {
          v7 = CVProfile::BudgetGroupNameToBudgetGroupID(
                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                 a2: "FCVAR_NEVER_AS_STRING");
        }
        else
        {
          v8 = vprof_dump_spikes_budget_group.m_pParent->m_Value.m_pszString;
          if ( v8 == nullptr )
            v8 = (char *)defaultValue;
          v7 = CVProfile::BudgetGroupNameToBudgetGroupID(
                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                 a2: v8);
        }
      }
      else
      {
        v7 = -1;
      }
      if ( (vprof_dump_spikes_node.m_nFlags & 0x1000) != 0
        || (v9 = vprof_dump_spikes_node.m_pParent->m_Value.m_pszString) != nullptr && *v9 != 0 )
      {
        if ( (vprof_dump_spikes_node.m_nFlags & 0x1000) != 0 )
        {
          CVProfile::OutputReport(
            this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
            a2: 4,
            a3: "FCVAR_NEVER_AS_STRING",
            a4: v7);
LABEL_62:
          LastSpikeTime = _Plat_FloatTime(this: v10);
          v18 = vprof_dump_spikes.m_pParent->m_Value.m_fValue >= 0.0;
          LastSpikeFrame = g_ServerGlobalVariables.framecount;
          if ( !v18 )
          {
            ConVar::SetValue(this: (ConVar *)&vprof_dump_spikes.IConVar, value: 0.0);
            g_fVprofOnByUI = false;
            v51 = 1;
          }
          if ( !v50.m_condebugEnabled )
            CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue, a2: v38);
          goto LABEL_66;
        }
        v11 = vprof_dump_spikes_node.m_pParent->m_Value.m_pszString;
        if ( v11 == nullptr )
        {
          CVProfile::OutputReport(
            this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
            a2: 4,
            a3: defaultValue,
            a4: v7);
          goto LABEL_62;
        }
      }
      else
      {
        v11 = nullptr;
      }
      CVProfile::OutputReport(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: 4, a3: v11, a4: v7);
      goto LABEL_62;
    }
  }
LABEL_77:
  if ( vprof_counters.m_pParent == nullptr )
  {
    m_nValue = 0;
LABEL_79:
    if ( !g_bDumpCounters )
      goto LABEL_112;
    goto LABEL_80;
  }
  m_nValue = vprof_counters.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    goto LABEL_79;
LABEL_80:
  NumCounters = CVProfile::GetNumCounters(this: v2);
  v22 = 0;
  v45 = NumCounters;
  idx = 0;
  v43 = 0;
  if ( NumCounters > 0 )
  {
    v40 = m_nValue - 1;
    do
    {
      if ( CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v22) == v40 )
      {
        CounterNameAndValue = CVProfile::GetCounterNameAndValue(
                                this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                a2: v22,
                                a3: (int *)&v49);
        v24 = CounterNameAndValue;
        v39 = CounterNameAndValue;
        if ( g_bDumpCounters )
          _Msg(a1: "VPROF: %s = %d\n", CounterNameAndValue, v49);
        if ( vprof_counters_show_minmax.m_pParent != nullptr
          && vprof_counters_show_minmax.m_pParent->m_Value.m_nValue != 0 )
        {
          if ( (_S1_21 & 1) == 0 )
          {
            _S1_21 |= 1u;
            v25 = 29;
            p_m_nGrowSize = &history.m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = 0;
              *(p_m_nGrowSize - 1) = 0;
              *p_m_nGrowSize = 0;
              p_m_nGrowSize[1] = 0;
              p_m_nGrowSize[2] = 0;
              p_m_nGrowSize += 5;
              --v25;
            }
            while ( v25 >= 0 );
            atexit(func: PreUpdateProfile_::_62_::_dynamic_atexit_destructor_for__history__);
          }
          v27 = nCycle;
          v28 = *(&history.m_Size + 5 * nCycle);
          if ( v28 < NumCounters )
          {
            CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
              this: &history + nCycle,
              elem: v28,
              num: NumCounters - v28);
            v27 = nCycle;
          }
          (&history.m_Memory.m_pMemory)[5 * v27][v22] = v49;
          v46 = v49;
          v47 = v49;
          p_m_Size = &history.m_Size;
          do
          {
            v30 = *p_m_Size;
            if ( *p_m_Size < v45 )
            {
              v31 = v45 - v30;
              if ( v45 != v30 )
              {
                v32 = *(p_m_Size - 2);
                if ( v45 > v32 )
                  CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)p_m_Size - 1, num: v45 - v32);
                *p_m_Size += v31;
                v33 = *(p_m_Size - 3);
                v34 = *p_m_Size - v45;
                p_m_Size[1] = v33;
                if ( v34 > 0 && v31 > 0 )
                  _V_memmove(dest: (void *)(v33 + 4 * v45), src: (const void *)(v33 + 4 * v30), count: 4 * v34);
              }
            }
            v35 = *(p_m_Size - 3);
            v36 = *(_DWORD *)(v35 + 4 * v43);
            if ( *(_DWORD *)&v46 >= v36 )
              v46 = *(S3RGBA *)(v35 + 4 * v43);
            if ( *(_DWORD *)&v47 <= v36 )
              v47 = *(S3RGBA *)(v35 + 4 * v43);
            p_m_Size += 5;
          }
          while ( (int)p_m_Size < (int)&`CUtlRBTree<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short,CUtlMap<char *,double,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' );
          Con_NPrintf(idx, fmt: "%s = %6d (%6d:%6d)\n", v39, v49, v46, v47);
          v22 = v43;
          NumCounters = v45;
        }
        else
        {
          Con_NPrintf(idx, fmt: "%s = %d\n", v24, v49);
        }
        ++idx;
      }
      v43 = ++v22;
    }
    while ( v22 < NumCounters );
  }
  v2 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  nCycle = (nCycle + 1) % 30;
LABEL_112:
  CVProfile::ResetCounters(this: v2, a2: COUNTER_GROUP_DEFAULT);
  CVProfile::ResetCounters(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: COUNTER_GROUP_TEXTURE_PER_FRAME);
  CVProfile::ResetCounters(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: COUNTER_GROUP_GRAPHICS_PER_FRAME);
  CVProfExport::SnapshotVProfHistory(this: &g_VProfExport);
  VProfRecord_Snapshot();
  if ( GetVProfPanel() != nullptr )
  {
    VProfPanel = GetVProfPanel();
    CVProfPanel::UpdateProfile(this: VProfPanel, filteredtime);
  }
  g_bDumpCounters = false;
}

//------------------------------------------------------------------------------
// Address: 0x101F1EF0
// Name: void RemoveVProfDataListener(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveVProfDataListener(unsigned int listenerID)
{
  VProfListenInfo_t findInfo; // [esp+0h] [ebp-1Ch] BYREF

  findInfo.m_nListenerId = listenerID;
  memset(&findInfo.m_flLastSentVProfDataTime, 0, 24);
  if ( CUtlVector<VProfListenInfo_t,CUtlMemory<VProfListenInfo_t,int>>::FindAndRemove(
         this: &s_VProfListeners,
         src: &findInfo) != 0
    && --g_VProfExport.m_nListeners == 0 )
  {
    g_VProfExport.m_bStop = true;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&findInfo.m_SentGroups);
}

//------------------------------------------------------------------------------
// Address: 0x101F1FB0
// Name: void RegisterVProfDataListener(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RegisterVProfDataListener(unsigned int listenerID)
{
  int v1; // ecx
  VProfListenInfo_t src; // [esp+0h] [ebp-1Ch] BYREF

  src.m_nListenerId = listenerID;
  memset(&src.m_flLastSentVProfDataTime, 0, 24);
  if ( CUtlVector<VProfListenInfo_t,CUtlMemory<VProfListenInfo_t,int>>::FindAndRemove(this: &s_VProfListeners, &src) != 0
    && --g_VProfExport.m_nListeners == 0 )
  {
    g_VProfExport.m_bStop = true;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&src.m_SentGroups);
  v1 = CUtlVector<VProfListenInfo_t,CUtlMemory<VProfListenInfo_t,int>>::InsertBefore(
         this: &s_VProfListeners,
         elem: s_VProfListeners.m_Size);
  s_VProfListeners.m_Memory.m_pMemory[v1].m_nListenerId = listenerID;
  if ( ++g_VProfExport.m_nListeners == 1 )
    g_VProfExport.m_bStart = true;
  WriteRemoteVProfGroupData(info: &s_VProfListeners.m_Memory.m_pMemory[v1]);
}

//------------------------------------------------------------------------------
// Address: 0x102D3D40
// Name: public: virtual void CVProfExport::SetBudgetFlagsFilter(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::SetBudgetFlagsFilter(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x101F05F0
// Name: __CreateCVProfExportIVProfExport_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVProfExport *__cdecl _CreateCVProfExportIVProfExport_interface()
{
  return &g_VProfExport;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101F0150
// Name: vprof_dump_counters
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_dump_counters()
{
  g_bDumpCounters = true;
}

//------------------------------------------------------------------------------
// Address: 0x101F0160
// Name: void PostUpdateProfile(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PostUpdateProfile()
{
  if ( *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) != 0
    && vprof_dump_spikes.m_pParent->m_Value.m_fValue == 0.0
    && vprof_dump_oninterval.m_pParent->m_Value.m_fValue == 0.0 )
  {
    CVProfile::MarkFrame(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F01A0
// Name: spike
// Source: json
//------------------------------------------------------------------------------
void __cdecl spike()
{
  Sys_Sleep();
}

//------------------------------------------------------------------------------
// Address: 0x101F01B0
// Name: vprof_vtune_group
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
void __cdecl vprof_vtune_group(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc == 2 )
  {
    if ( _V_stricmp(s1: args->m_ppArgv[1], s2: "disable") != 0 )
    {
      v1 = defaultValue;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      _g_VProfCurrentProfile.m_nVTuneGroupID = CVProfile::BudgetGroupNameToBudgetGroupID(
                                                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                                 a2: v1);
      _g_VProfCurrentProfile.m_bVTuneGroupEnabled = true;
    }
    else
    {
      _g_VProfCurrentProfile.m_bVTuneGroupEnabled = false;
    }
  }
  else
  {
    _Warning(a1: "vprof_vtune_group groupName (disable to turn off)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0220
// Name: vprof_dump_groupnames
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_dump_groupnames()
{
  int NumBudgetGroups; // edi
  int i; // esi

  NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  for ( i = 0; i < NumBudgetGroups; ++i )
    _Msg(
      a1: "group %d: \"%s\"\n",
      i,
      *(const char **)(*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4276) + 8 * i));
}

//------------------------------------------------------------------------------
// Address: 0x101F0270
// Name: vprof_cachemiss_Impl
// Source: json
//------------------------------------------------------------------------------
char vprof_cachemiss_Impl()
{
  char result; // al

  if ( g_fVprofCacheMissOnByUI )
  {
    result = _Msg(a1: "VProf cache miss disabled.\n");
    *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4293) = 0;
    g_fVprofCacheMissOnByUI = false;
  }
  else
  {
    _Msg(a1: "VProf cache miss enabled.\n");
    *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4293) = 1;
    g_fVprofCacheMissOnByUI = true;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F02C0
// Name: vprof_cachemiss_on_Impl
// Source: json
//------------------------------------------------------------------------------
char vprof_cachemiss_on_Impl()
{
  char result; // al

  if ( !g_fVprofCacheMissOnByUI )
  {
    _Msg(a1: "VProf cache miss enabled.\n");
    *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4293) = 1;
    g_fVprofCacheMissOnByUI = true;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F02F0
// Name: vprof_cachemiss_off_Impl
// Source: json
//------------------------------------------------------------------------------
int vprof_cachemiss_off_Impl()
{
  int result; // eax

  if ( g_fVprofCacheMissOnByUI )
  {
    _Msg(a1: "VProf cache miss disabled.\n");
    *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4293) = 0;
    g_fVprofCacheMissOnByUI = false;
    return *(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0320
// Name: vprof_Impl
// Source: json
//------------------------------------------------------------------------------
void vprof_Impl()
{
  if ( g_fVprofOnByUI )
  {
    _Msg(a1: "VProf disabled.\n");
    if ( (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1 )
      CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_fVprofOnByUI = false;
  }
  else
  {
    _Msg(a1: "VProf enabled.\n");
    if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
      CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_fVprofOnByUI = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0390
// Name: budget_toggle_group
// Source: json
//------------------------------------------------------------------------------
void __cdecl budget_toggle_group(const CCommand *args)
{
  int BudgetGroupName; // eax

  if ( args->m_nArgc == 2 )
  {
    BudgetGroupName = CVProfile::FindBudgetGroupName(
                        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                        a2: args->m_ppArgv[1]);
    if ( BudgetGroupName != -1 )
      CVProfile::HideBudgetGroup(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: BudgetGroupName,
        a3: (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4276)
                   + 8 * BudgetGroupName
                   + 4)
       & 0x8000) == 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F03E0
// Name: vprof_off_Impl
// Source: json
//------------------------------------------------------------------------------
void __fastcall vprof_off_Impl(int a1)
{
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF

  consoleLog.m_condebugEnabled = HIBYTE(a1);
  if ( g_fVprofOnByUI )
  {
    _Msg(a1: "VProf disabled.\n");
    if ( (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1 )
      CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_fVprofOnByUI = false;
    if ( g_szDefferedArg1[0] != 0 && _V_stricmp(s1: "infested", s2: g_szDefferedArg1) == 0 )
    {
      ConsoleLogger::ConsoleLogger(this: &consoleLog);
      CVProfile::OutputReport(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: -519,
        a3: nullptr,
        a4: -1);
      if ( !consoleLog.m_condebugEnabled )
        CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0470
// Name: vprof_reset_Impl
// Source: json
//------------------------------------------------------------------------------
void vprof_reset_Impl()
{
  CVProfPanel *VProfPanel; // eax

  _Msg(a1: "VProf reset.\n");
  CVProfNode::Reset(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4264) = 0;
  if ( GetVProfPanel() != nullptr )
  {
    VProfPanel = GetVProfPanel();
    CVProfPanel::Reset(this: VProfPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F04C0
// Name: vprof_reset_peaks_Impl
// Source: json
//------------------------------------------------------------------------------
void vprof_reset_peaks_Impl()
{
  _Msg(a1: "VProf peaks reset.\n");
  CVProfNode::ResetPeak(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
}

//------------------------------------------------------------------------------
// Address: 0x101F04E0
// Name: vprof_generate_report_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void vprof_generate_report_Impl()
{
  bool v0; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog);
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: -519,
    a3: g_szDefferedArg1[0] != 0 ? g_szDefferedArg1 : nullptr,
    a4: -1);
  v0 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v0 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101F0560
// Name: vprof_generate_report_budget_Impl
// Source: json
//------------------------------------------------------------------------------
void __fastcall vprof_generate_report_budget_Impl(int a1)
{
  int v1; // eax
  bool v2; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF

  consoleLog.m_condebugEnabled = HIBYTE(a1);
  if ( g_szDefferedArg1[0] != 0 )
  {
    CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    ConsoleLogger::ConsoleLogger(this: &consoleLog);
    v1 = CVProfile::BudgetGroupNameToBudgetGroupID(
           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
           a2: g_szDefferedArg1);
    CVProfile::OutputReport(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: -519,
      a3: nullptr,
      a4: v1);
    v2 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
    *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                            + 4272);
    if ( v2 )
      CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    if ( !consoleLog.m_condebugEnabled )
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0670
// Name: vprof_generate_report_hierarchy_per_frame_and_count_only_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void vprof_generate_report_hierarchy_per_frame_and_count_only_Impl()
{
  bool v0; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog);
  CVProfile::OutputReport(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: 4, a3: nullptr, a4: -1);
  v0 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v0 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101F0750
// Name: vprof_generate_report_AI_only_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void vprof_generate_report_AI_only_Impl()
{
  int v0; // eax
  bool v1; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog);
  v0 = CVProfile::BudgetGroupNameToBudgetGroupID(
         this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
         a2: "NPCs");
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: -519,
    a3: "NPCs",
    a4: v0);
  v1 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101F07D0
// Name: vprof_generate_report_map_load_Impl
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void vprof_generate_report_map_load_Impl()
{
  bool v0; // zf
  ConsoleLogger consoleLog; // [esp+1h] [ebp-1h] BYREF

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  ConsoleLogger::ConsoleLogger(this: &consoleLog);
  CVProfile::OutputReport(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: -517,
    a3: "Host_NewGame",
    a4: -1);
  v0 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v0 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  if ( !consoleLog.m_condebugEnabled )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101F0840
// Name: public: virtual void CVProfExport::AddListener(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::AddListener(CVProfExport *this)
{
  if ( ++this->m_nListeners == 1 )
    this->m_bStart = true;
}

//------------------------------------------------------------------------------
// Address: 0x101F0870
// Name: public: virtual void CVProfExport::ResumeProfile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::ResumeProfile(CVProfExport *this)
{
  bool v1; // zf

  if ( materials != nullptr )
    materials->Flush(this: materials, a2: false);
  v1 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v1 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
}

//------------------------------------------------------------------------------
// Address: 0x101F08C0
// Name: void VProfExport_StartOrStop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfExport_StartOrStop()
{
  if ( g_VProfExport.m_bStart )
  {
    if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
      CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_VProfExport.m_bStart = false;
  }
  if ( g_VProfExport.m_bStop )
  {
    if ( (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1 )
      CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_VProfExport.m_bStop = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0920
// Name: void VProfExport_Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VProfExport_Pause(CVProfExport *this)
{
  if ( materials != nullptr )
    materials->Flush(this: materials, a2: false);
  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101F0950
// Name: void OverrideVProfExport(class IVProfExport __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverrideVProfExport(IVProfExport *pExport)
{
  if ( g_pVProfExport == &g_VProfExport )
    g_pVProfExport = pExport;
}

//------------------------------------------------------------------------------
// Address: 0x101F0990
// Name: vprof_cachemiss
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_cachemiss(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_cachemiss_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F09F0
// Name: vprof_cachemiss_on
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_cachemiss_on(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_cachemiss_on_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0A50
// Name: vprof_cachemiss_off
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_cachemiss_off(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_cachemiss_off_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0AB0
// Name: vprof
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0B10
// Name: vprof_on_Impl
// Source: json
//------------------------------------------------------------------------------
void vprof_on_Impl()
{
  if ( !g_fVprofOnByUI )
  {
    _Msg(a1: "VProf enabled.\n");
    if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
      CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
    g_fVprofOnByUI = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0B60
// Name: vprof_off
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_off(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_off_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0BC0
// Name: vprof_reset
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_reset(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_reset_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0C20
// Name: vprof_reset_peaks
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_reset_peaks(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_reset_peaks_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0C80
// Name: vprof_generate_report
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_generate_report_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0CE0
// Name: vprof_generate_report_budget
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_budget(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_budget_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0D40
// Name: vprof_generate_report_hierarchy
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_hierarchy(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_hierarchy_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0DA0
// Name: vprof_generate_report_hierarchy_per_frame_and_count_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_hierarchy_per_frame_and_count_only(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_generate_report_hierarchy_per_frame_and_count_only_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0E00
// Name: vprof_generate_report_AI
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_AI(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = (void (__cdecl *)())vprof_generate_report_AI_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0E60
// Name: vprof_generate_report_AI_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_AI_only(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_generate_report_AI_only_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0EC0
// Name: vprof_generate_report_map_load
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_generate_report_map_load(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // esi

  v1 = args->m_nArgc <= 1;
  g_pfnDeferredOp = vprof_generate_report_map_load_Impl;
  v2 = defaultValue;
  if ( !v1 )
    v2 = args->m_ppArgv[1];
  V_strncpy(pDest: g_szDefferedArg1, pSrc: v2, maxLen: 128);
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  else
    v3 = defaultValue;
  V_strncpy(pDest: g_szDefferedArg2, pSrc: v3, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101F0F80
// Name: public: void CVProfExport::GetAllBudgetGroupTimes(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::GetAllBudgetGroupTimes(CVProfExport *this, float *pTimes)
{
  float *v3; // ebx
  int NumBudgetGroups; // esi
  int v5; // eax
  int v6; // eax
  int *p_m_BudgetFlags; // edx
  unsigned int v8; // esi
  float *v9; // ecx
  int v10; // xmm1_4
  int v11; // xmm1_4
  float v12; // xmm1_4
  int v13; // xmm1_4
  int *v14; // ecx
  float v15; // xmm1_4
  int nTotalGroups; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int v18; // [esp+1Ch] [ebp-4h]

  v3 = pTimes;
  NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  v5 = 0;
  nTotalGroups = NumBudgetGroups;
  if ( NumBudgetGroups >= 4 )
  {
    v6 = -8 - (_DWORD)pTimes;
    p_m_BudgetFlags = &g_pVProfileForDisplay->m_pBudgetGroups[1].m_BudgetFlags;
    v8 = ((unsigned int)(NumBudgetGroups - 4) >> 2) + 1;
    v9 = pTimes + 2;
    v18 = 2;
    i = 4 * v8;
    do
    {
      if ( (*(p_m_BudgetFlags - 2) & this->m_BudgetFlagsFilter) != 0 )
        v10 = *(_DWORD *)((char *)this->m_Times.m_Memory.m_pMemory + v6 + (unsigned int)v9);
      else
        v10 = 0;
      *((_DWORD *)v9 - 2) = v10;
      if ( (*p_m_BudgetFlags & this->m_BudgetFlagsFilter) != 0 )
        v11 = *(_DWORD *)((char *)this->m_Times.m_Memory.m_pMemory + v6 + (unsigned int)v9 + 4);
      else
        v11 = 0;
      *((_DWORD *)v9 - 1) = v11;
      if ( (p_m_BudgetFlags[2] & this->m_BudgetFlagsFilter) != 0 )
      {
        v12 = this->m_Times.m_Memory.m_pMemory[v18];
        v6 = -8 - (_DWORD)pTimes;
      }
      else
      {
        v12 = 0.0;
      }
      *v9 = v12;
      if ( (p_m_BudgetFlags[4] & this->m_BudgetFlagsFilter) != 0 )
      {
        v13 = *(_DWORD *)((char *)this->m_Times.m_Memory.m_pMemory + 4 - (_DWORD)pTimes + (unsigned int)v9);
        v6 = -8 - (_DWORD)pTimes;
      }
      else
      {
        v13 = 0;
      }
      v18 += 4;
      *((_DWORD *)v9 + 1) = v13;
      v9 += 4;
      p_m_BudgetFlags += 8;
      --v8;
    }
    while ( v8 != 0 );
    v5 = i;
    v3 = pTimes;
    NumBudgetGroups = nTotalGroups;
  }
  if ( v5 < NumBudgetGroups )
  {
    v14 = &g_pVProfileForDisplay->m_pBudgetGroups[v5].m_BudgetFlags;
    do
    {
      if ( (*v14 & this->m_BudgetFlagsFilter) != 0 )
        v15 = this->m_Times.m_Memory.m_pMemory[v5];
      else
        v15 = 0.0;
      v3[v5++] = v15;
      v14 += 2;
    }
    while ( v5 < NumBudgetGroups );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F10C0
// Name: public: void CVProfExport::CalculateBudgetGroupTimes_Recursive(class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::CalculateBudgetGroupTimes_Recursive(CVProfExport *this, CVProfNode *pNode)
{
  CVProfNode *v2; // edx
  CVProfile *v4; // eax
  int m_BudgetFlags; // ecx
  int v6; // esi
  double PrevTimeLessChildren; // st7
  int m_Size; // eax

  v2 = pNode;
  v4 = (CVProfile *)pNode;
  if ( pNode != &g_pVProfileForDisplay->m_Root )
  {
    do
    {
      m_BudgetFlags = g_pVProfileForDisplay->m_pBudgetGroups[v4->m_GroupIDStack[31]].m_BudgetFlags;
      if ( (this->m_BudgetFlagsFilter & m_BudgetFlags) != 0 && (m_BudgetFlags & 0x8000) == 0 )
        break;
      v4 = (CVProfile *)v4->m_GroupIDStack[28];
    }
    while ( v4 != (CVProfile *)&g_pVProfileForDisplay->m_Root );
    v2 = pNode;
  }
  v6 = v4->m_GroupIDStack[31];
  PrevTimeLessChildren = CVProfNode::GetPrevTimeLessChildren(this: v2);
  if ( v6 >= 0 )
  {
    m_Size = this->m_Times.m_Size;
    if ( m_Size >= 512 )
      m_Size = 512;
    if ( v6 < m_Size )
      this->m_Times.m_Memory.m_pMemory[v6] = PrevTimeLessChildren + this->m_Times.m_Memory.m_pMemory[v6];
  }
  if ( pNode->m_pSibling != nullptr )
    CVProfExport::CalculateBudgetGroupTimes_Recursive(this, pNode: pNode->m_pSibling);
  if ( pNode->m_pChild != nullptr )
    CVProfExport::CalculateBudgetGroupTimes_Recursive(this, pNode: pNode->m_pChild);
  if ( !VProfRecord_IsPlayingBack() )
    CVProfNode::ClearPrevTime(this: pNode);
}

//------------------------------------------------------------------------------
// Address: 0x101F1180
// Name: public: virtual int CVProfExport::GetNumBudgetGroups(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfExport::GetNumBudgetGroups(CVProfExport *this)
{
  int m_Size; // edi
  int NumBudgetGroups; // edx
  int result; // eax
  int m_BudgetFlagsFilter; // esi
  int *p_m_BudgetFlags; // ecx

  m_Size = this->m_Times.m_Size;
  if ( m_Size >= CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay) )
    NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  else
    NumBudgetGroups = this->m_Times.m_Size;
  result = 0;
  if ( NumBudgetGroups > 0 )
  {
    m_BudgetFlagsFilter = this->m_BudgetFlagsFilter;
    p_m_BudgetFlags = &g_pVProfileForDisplay->m_pBudgetGroups->m_BudgetFlags;
    do
    {
      if ( (m_BudgetFlagsFilter & *p_m_BudgetFlags) != 0 )
        ++result;
      p_m_BudgetFlags += 2;
      --NumBudgetGroups;
    }
    while ( NumBudgetGroups != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F11D0
// Name: public: virtual void CVProfExport::GetBudgetGroupInfos(class IVProfExport::CExportedBudgetGroupInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::GetBudgetGroupInfos(CVProfExport *this, IVProfExport::CExportedBudgetGroupInfo *pInfos)
{
  int m_Size; // esi
  int NumBudgetGroups; // eax
  int v5; // esi
  CVProfile *v6; // eax
  int *p_m_BudgetFlags; // edi
  char alpha; // [esp+Ch] [ebp-18h]
  char blue; // [esp+10h] [ebp-14h]
  char green; // [esp+14h] [ebp-10h]
  char red; // [esp+18h] [ebp-Ch]
  int v13; // [esp+20h] [ebp-4h]
  IVProfExport::CExportedBudgetGroupInfo *pInfosa; // [esp+2Ch] [ebp+8h]

  m_Size = this->m_Times.m_Size;
  if ( m_Size >= CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay) )
    NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  else
    NumBudgetGroups = this->m_Times.m_Size;
  v5 = 0;
  v13 = NumBudgetGroups;
  if ( NumBudgetGroups > 0 )
  {
    v6 = g_pVProfileForDisplay;
    p_m_BudgetFlags = &pInfos->m_BudgetFlags;
    do
    {
      if ( (v6->m_pBudgetGroups[v5].m_BudgetFlags & this->m_BudgetFlagsFilter) != 0 )
      {
        *(p_m_BudgetFlags - 1) = (int)v6->m_pBudgetGroups[v5].m_pName;
        CVProfile::GetBudgetGroupColor(this: g_pVProfileForDisplay, a2: v5);
        LOBYTE(pInfosa) = red;
        BYTE1(pInfosa) = green;
        BYTE2(pInfosa) = blue;
        HIBYTE(pInfosa) = alpha;
        p_m_BudgetFlags[1] = (int)pInfosa;
        *p_m_BudgetFlags = g_pVProfileForDisplay->m_pBudgetGroups[v5].m_BudgetFlags;
        v6 = g_pVProfileForDisplay;
        p_m_BudgetFlags += 3;
      }
      ++v5;
    }
    while ( v5 < v13 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F12A0
// Name: public: virtual void CVProfExport::GetBudgetGroupTimes(float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::GetBudgetGroupTimes(CVProfExport *this, float *times)
{
  int m_Size; // edi
  int NumBudgetGroups; // ebx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int *i; // edx
  float *v9; // ecx
  int *p_m_BudgetFlags; // edx
  int v11; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Times.m_Size;
  if ( m_Size >= CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay) )
    NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  else
    NumBudgetGroups = this->m_Times.m_Size;
  v11 = NumBudgetGroups;
  v5 = NumBudgetGroups;
  if ( NumBudgetGroups >= 512 )
    v5 = 512;
  memset(dst: (unsigned __int8 *)times, value: 0, count: 4 * v5);
  v6 = 0;
  v7 = 0;
  if ( NumBudgetGroups >= 4 )
  {
    for ( i = &g_pVProfileForDisplay->m_pBudgetGroups[1].m_BudgetFlags; ; i += 8 )
    {
      if ( (*(i - 2) & this->m_BudgetFlagsFilter) != 0 )
        times[v6++] = this->m_Times.m_Memory.m_pMemory[v7];
      if ( (this->m_BudgetFlagsFilter & *i) != 0 )
        times[v6++] = this->m_Times.m_Memory.m_pMemory[v7 + 1];
      if ( (i[2] & this->m_BudgetFlagsFilter) != 0 )
        times[v6++] = this->m_Times.m_Memory.m_pMemory[v7 + 2];
      if ( (i[4] & this->m_BudgetFlagsFilter) != 0 )
        times[v6++] = this->m_Times.m_Memory.m_pMemory[v7 + 3];
      NumBudgetGroups = v11;
      v7 += 4;
      if ( v7 >= v11 - 3 )
        break;
    }
  }
  if ( v7 < NumBudgetGroups )
  {
    v9 = &times[v6];
    p_m_BudgetFlags = &g_pVProfileForDisplay->m_pBudgetGroups[v7].m_BudgetFlags;
    do
    {
      if ( (this->m_BudgetFlagsFilter & *p_m_BudgetFlags) != 0 )
        *v9++ = this->m_Times.m_Memory.m_pMemory[v7];
      ++v7;
      p_m_BudgetFlags += 2;
    }
    while ( v7 < NumBudgetGroups );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F13C0
// Name: void WriteRemoteVProfGroupData(struct VProfListenInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteRemoteVProfGroupData(VProfListenInfo_t *info)
{
  VProfListenInfo_t *v1; // edi
  int NumBudgetGroups; // esi
  void *v3; // esp
  CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *p_m_SentGroups; // esi
  int m_Size; // eax
  int v6; // edi
  int v7; // ebx
  const char *v8; // eax
  int v9; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  int v15; // eax
  int v16; // edi
  int v17; // esi
  int v18; // edi
  unsigned __int8 v19; // bl
  unsigned __int8 v20; // bl
  unsigned __int8 v21; // bl
  unsigned __int8 v22; // bl
  int *p_red; // [esp-10h] [ebp-68h]
  int *p_green; // [esp-Ch] [ebp-64h]
  int *p_blue; // [esp-8h] [ebp-60h]
  int *p_alpha; // [esp-4h] [ebp-5Ch]
  int v27; // [esp+0h] [ebp-58h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-4Ch] BYREF
  int nGroupCount; // [esp+3Ch] [ebp-1Ch]
  int alpha; // [esp+40h] [ebp-18h] BYREF
  int *pIndex; // [esp+44h] [ebp-14h]
  int red; // [esp+48h] [ebp-10h] BYREF
  int green; // [esp+4Ch] [ebp-Ch] BYREF
  int nSendCount; // [esp+50h] [ebp-8h]
  int blue; // [esp+54h] [ebp-4h] BYREF

  v1 = info;
  NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
  red = info->m_SentGroups.m_Size;
  nGroupCount = NumBudgetGroups;
  nSendCount = 0;
  v3 = alloca(4 * NumBudgetGroups);
  pIndex = &v27;
  blue = 0;
  if ( NumBudgetGroups > 0 )
  {
    p_m_SentGroups = (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&info->m_SentGroups;
    while ( 1 )
    {
      m_Size = v1->m_SentGroups.m_Size;
      v6 = 0;
      green = (int)g_pVProfileForDisplay->m_pBudgetGroups[blue].m_pName;
      alpha = m_Size;
      if ( m_Size <= 0 )
        goto LABEL_10;
      v7 = 0;
      while ( 1 )
      {
        v8 = CUtlString::Get(this: (CUtlString *)&p_m_SentGroups->m_pMemory[v7]);
        if ( _V_strcmp(s1: (const char *)green, s2: v8) == 0 )
          break;
        ++v6;
        ++v7;
        if ( v6 >= alpha )
          goto LABEL_10;
      }
      if ( v6 < 0 )
      {
LABEL_10:
        v9 = info->m_SentGroups.m_Size;
        m_nAllocationCount = info->m_SentGroups.m_Memory.m_nAllocationCount;
        if ( v9 + 1 > m_nAllocationCount )
          CUtlMemory<CPortalRect,int>::Grow(this: p_m_SentGroups, num: v9 - m_nAllocationCount + 1);
        ++info->m_SentGroups.m_Size;
        m_pMemory = p_m_SentGroups->m_pMemory;
        v12 = info->m_SentGroups.m_Size - v9 - 1;
        info->m_SentGroups.m_pElements = info->m_SentGroups.m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 16 * v12);
        v13 = v9;
        v14 = (CUtlString *)&p_m_SentGroups->m_pMemory[v13];
        if ( v14 != nullptr )
          CUtlString::CUtlString(this: v14);
        CUtlString::operator=(this: (CUtlString *)&p_m_SentGroups->m_pMemory[v13], src: (const char *)green);
        v15 = nSendCount;
        pIndex[nSendCount] = blue;
        nSendCount = v15 + 1;
      }
      if ( ++blue >= nGroupCount )
        break;
      v1 = info;
    }
    v16 = nSendCount;
    if ( nSendCount != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 1024, initSize: 1024, nFlags: 0);
      if ( (buf.m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: &buf, pFmt: "%d", red);
      else
        CUtlBuffer::PutTypeBin<int>(this: &buf, src: red);
      if ( (buf.m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: &buf, pFmt: "%d", v16);
      else
        CUtlBuffer::PutTypeBin<int>(this: &buf, src: v16);
      v17 = 0;
      if ( v16 > 0 )
      {
        do
        {
          v18 = pIndex[v17];
          p_alpha = &alpha;
          p_blue = &blue;
          p_green = &green;
          p_red = &red;
          CVProfile::GetBudgetGroupColor(this: g_pVProfileForDisplay, a2: v18);
          if ( (buf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &buf, pFmt: "%hu", (unsigned __int8)red);
          }
          else
          {
            v19 = red;
            if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
            {
              buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v19;
              CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
            }
          }
          if ( (buf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &buf, pFmt: "%hu", (unsigned __int8)green);
          }
          else
          {
            v20 = green;
            if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
            {
              buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v20;
              CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
            }
          }
          if ( (buf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &buf, pFmt: "%hu", (unsigned __int8)blue);
          }
          else
          {
            v21 = blue;
            if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
            {
              buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v21;
              CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
            }
          }
          if ( (buf.m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: &buf, pFmt: "%hu", (unsigned __int8)alpha);
          }
          else
          {
            v22 = alpha;
            if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
            {
              buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = v22;
              CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
            }
          }
          CUtlBuffer::PutString(this: &buf, pString: g_pVProfileForDisplay->m_pBudgetGroups[v18].m_pName);
          ++v17;
        }
        while ( v17 < nSendCount );
      }
      CServerRemoteAccess::SendVProfData(
        this: &g_ServerRemoteAccess,
        listenerID: info->m_nListenerId,
        bGroupData: true,
        data: buf.m_Memory.m_pMemory,
        len: buf.m_nMaxPut);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        ((void (__thiscall *)(IMemAlloc *, unsigned __int8 *, int *, int *, int *, int *))_g_pMemAlloc->Free_2)(
          a1: _g_pMemAlloc,
          a2: buf.m_Memory.m_pMemory,
          a3: p_red,
          a4: p_green,
          a5: p_blue,
          a6: p_alpha);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1700
// Name: void WriteRemoteVProfData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WriteRemoteVProfData(CStatTime *this)
{
  int v1; // eax
  int m_Size; // edi
  float *i; // edx
  void *v4; // esp
  int v5; // esi
  int v6; // edi
  void *v7; // esp
  int *p_nSentSize; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  int v12; // esi
  const char *v13; // eax
  double v14; // st7
  float *v15; // ecx
  bool v16; // zf
  int nSentSize; // [esp+0h] [ebp-2Ch] BYREF
  float *pTimes; // [esp+4h] [ebp-28h]
  char *s1; // [esp+8h] [ebp-24h]
  _DWORD *v20; // [esp+Ch] [ebp-20h]
  int v21; // [esp+10h] [ebp-1Ch]
  float *pSentTimes; // [esp+14h] [ebp-18h]
  int nGroupCount; // [esp+18h] [ebp-14h]
  float flMaxDelta; // [esp+1Ch] [ebp-10h]
  int v25; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]
  float flTime; // [esp+28h] [ebp-4h]

  flMaxDelta = rpt_vprof_time.m_pParent->m_Value.m_fValue;
  flTime = _Plat_FloatTime(this);
  v1 = 0;
  m_Size = s_VProfListeners.m_Size;
  if ( s_VProfListeners.m_Size > 0 )
  {
    for ( i = &s_VProfListeners.m_Memory.m_pMemory->m_flLastSentVProfDataTime; (float)(flTime - *i) < flMaxDelta; i += 7 )
    {
      if ( ++v1 >= s_VProfListeners.m_Size )
        return;
    }
    nGroupCount = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
    v4 = alloca(4 * nGroupCount);
    pTimes = (float *)&nSentSize;
    CVProfExport::GetAllBudgetGroupTimes(this: &g_VProfExport, pTimes: (float *)&nSentSize);
    v5 = 0;
    v25 = 0;
    v21 = m_Size;
    do
    {
      if ( flMaxDelta <= (float)(flTime
                               - *(float *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_flLastSentVProfDataTime + v5)) )
      {
        WriteRemoteVProfGroupData(info: (VProfListenInfo_t *)((char *)s_VProfListeners.m_Memory.m_pMemory + v5));
        *(float *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_flLastSentVProfDataTime + v5) = flTime;
        nSentSize = 4 * *(int *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_SentGroups.m_Size + v5);
        v6 = nSentSize;
        v7 = alloca(nSentSize);
        p_nSentSize = &nSentSize;
        pSentTimes = (float *)&nSentSize;
        memset(dst: (unsigned __int8 *)&nSentSize, value: 0, count: nSentSize);
        v9 = 0;
        j = 0;
        if ( nGroupCount > 0 )
        {
          do
          {
            s1 = g_pVProfileForDisplay->m_pBudgetGroups[v9].m_pName;
            v10 = *(int *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_SentGroups.m_Size + v5);
            v11 = 0;
            if ( v10 <= 0 )
            {
LABEL_14:
              v11 = -1;
            }
            else
            {
              v20 = (CUtlString **)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_SentGroups.m_Memory.m_pMemory + v5);
              v12 = 0;
              while ( 1 )
              {
                v13 = CUtlString::Get(this: (CUtlString *)(v12 + *v20));
                if ( _V_strcmp(s1, s2: v13) == 0 )
                  break;
                ++v11;
                v12 += 16;
                if ( v11 >= v10 )
                {
                  v9 = j;
                  v5 = v25;
                  goto LABEL_14;
                }
              }
              v9 = j;
              v5 = v25;
            }
            v14 = pTimes[v9];
            v15 = pSentTimes;
            ++v9;
            pSentTimes[v11] = v14;
            j = v9;
          }
          while ( v9 < nGroupCount );
          v6 = nSentSize;
          p_nSentSize = (int *)v15;
        }
        CServerRemoteAccess::SendVProfData(
          this: &g_ServerRemoteAccess,
          listenerID: *(unsigned int *)((char *)&s_VProfListeners.m_Memory.m_pMemory->m_nListenerId + v5),
          bGroupData: false,
          data: p_nSentSize,
          len: v6);
      }
      v5 += 28;
      v16 = v21-- == 1;
      v25 = v5;
    }
    while ( !v16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F18C0
// Name: public: void CVProfExport::SnapshotVProfHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::SnapshotVProfHistory(CVProfExport *this)
{
  int m_Size; // ebx
  int NumBudgetGroups; // eax
  float *m_pMemory; // ebx
  int v5; // eax
  CVProfNode *m_pChild; // eax

  if ( g_pVProfileForDisplay->m_enabled != 0 )
  {
    m_Size = this->m_Times.m_Size;
    if ( m_Size < CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay) )
    {
      NumBudgetGroups = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
      this->m_Times.m_Size = 0;
      CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_Times,
        elem: 0,
        num: NumBudgetGroups);
    }
    m_pMemory = this->m_Times.m_Memory.m_pMemory;
    v5 = CVProfile::GetNumBudgetGroups(this: g_pVProfileForDisplay);
    memset(dst: (unsigned __int8 *)m_pMemory, value: 0, count: 4 * v5);
    if ( g_pVProfileForDisplay != (CVProfile *)-4120 )
    {
      m_pChild = g_pVProfileForDisplay->m_Root.m_pChild;
      if ( m_pChild != nullptr )
        CVProfExport::CalculateBudgetGroupTimes_Recursive(this, pNode: m_pChild);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1940
// Name: void PreUpdateProfile(float)
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
void __cdecl PreUpdateProfile(float filteredtime)
{
  CVProfile *v1; // ecx
  bool v2; // zf
  CStatTime *v3; // ecx
  double v4; // st7
  char *v5; // ecx
  int v6; // eax
  char *v7; // eax
  char *v8; // ecx
  CStatTime *v9; // ecx
  char *v10; // ecx
  int v11; // edi
  char *v12; // ecx
  int v13; // eax
  char *m_pszString; // eax
  char *v15; // ecx
  char *v16; // ecx
  bool v17; // cc
  int v18; // esi
  int m_nValue; // esi
  int NumCounters; // ebx
  int v21; // edi
  const char *CounterNameAndValue; // eax
  const char *v23; // esi
  int v24; // ecx
  int *p_m_nGrowSize; // eax
  int v26; // eax
  int v27; // edx
  int *p_m_Size; // esi
  int v29; // ebx
  int v30; // edi
  int v31; // ecx
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  CVProfPanel *VProfPanel; // eax
  const char *v37; // [esp+34h] [ebp-28h]
  int v38; // [esp+3Ch] [ebp-20h]
  float v39; // [esp+40h] [ebp-1Ch]
  float v40; // [esp+40h] [ebp-1Ch]
  int v41; // [esp+40h] [ebp-1Ch]
  float m_fValue; // [esp+44h] [ebp-18h]
  int v43; // [esp+44h] [ebp-18h]
  S3RGBA v44; // [esp+48h] [ebp-14h]
  S3RGBA v45; // [esp+4Ch] [ebp-10h]
  int idx; // [esp+50h] [ebp-Ch]
  S3RGBA v47; // [esp+54h] [ebp-8h] BYREF
  ConsoleLogger v48; // [esp+5Ah] [ebp-2h] BYREF
  char v49; // [esp+5Bh] [ebp-1h]

  if ( g_pfnDeferredOp != nullptr )
  {
    g_pfnDeferredOp();
    g_pfnDeferredOp = nullptr;
  }
  VProfExport_StartOrStop();
  VProfRecord_StartOrStop();
  v1 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  if ( *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 6604) != g_VProfTargetThread )
  {
    *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 6604) = g_VProfTargetThread;
    v1 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  }
  if ( v1->m_enabled != 0 )
  {
    if ( vprof_dump_oninterval.m_pParent->m_Value.m_fValue != 0.0 )
    {
      v39 = eng->GetCurTime(this: eng);
      m_fValue = vprof_dump_oninterval.m_pParent->m_Value.m_fValue;
      CVProfile::MarkFrame(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      v1 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
      if ( v39 > (float)(s_flIntervalStartTime + m_fValue) )
      {
        CVProfile::OutputReport(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: 569,
          a3: nullptr,
          a4: -1);
        v2 = (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1;
        if ( v2 )
          CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
        CVProfNode::Reset(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
        *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4264) = 0;
        if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
          CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
        v1 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
        s_flIntervalStartTime = v39;
      }
    }
    if ( v1->m_enabled != 0 && vprof_dump_spikes.m_pParent->m_Value.m_fValue != 0.0 )
    {
      v40 = vprof_dump_spikes.m_pParent->m_Value.m_fValue;
      CVProfile::MarkFrame(this: v1);
      v49 = 0;
      if ( !_g_VProfSignalSpike )
      {
        if ( ((double (__thiscall *)(IEngine *))eng->GetFrameTime)(a1: eng) <= 1.0 / fabs(v40) )
          goto LABEL_67;
        if ( !_g_VProfSignalSpike
          && (_Plat_FloatTime(this: *(CStatTime **)&_g_VProfSignalSpike) - LastSpikeTime <= 1.0
           || g_ServerGlobalVariables.framecount <= LastSpikeFrame + 10) )
        {
LABEL_66:
          _g_VProfSignalSpike = false;
LABEL_67:
          v1 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
          v18 = 0;
          do
          {
            v2 = v1->m_enabled-- == 1;
            if ( v2 )
              CVProfNode::ExitScope(this: &v1->m_Root);
            v1 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
            ++v18;
          }
          while ( *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) != 0 );
          if ( v49 == 0 )
          {
            CVProfNode::Reset(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
            *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4264) = 0;
            while ( v18 != 0 )
            {
              ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108);
              --v18;
              if ( *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
                CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                          + 4120));
            }
            v1 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
          }
          goto LABEL_77;
        }
      }
      ConsoleLogger::ConsoleLogger(this: &v48);
      v4 = _Plat_FloatTime(this: v3);
      _Msg(a1: "******** Spike on frame %d at time %.3f ", g_ServerGlobalVariables.framecount, v4);
      if ( vprof_dump_spikes_hierarchy.m_pParent == nullptr
        || vprof_dump_spikes_hierarchy.m_pParent->m_Value.m_nValue == 0 )
      {
        if ( vprof_dump_spikes_terse.m_pParent != nullptr && vprof_dump_spikes_terse.m_pParent->m_Value.m_nValue != 0 )
          v11 = 520;
        else
          v11 = 569;
        if ( (vprof_dump_spikes_budget_group.m_nFlags & 0x1000) != 0
          || (v12 = vprof_dump_spikes_budget_group.m_pParent->m_Value.m_pszString) != nullptr && *v12 != 0 )
        {
          if ( (vprof_dump_spikes_budget_group.m_nFlags & 0x1000) != 0 )
          {
            v13 = CVProfile::BudgetGroupNameToBudgetGroupID(
                    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                    a2: "FCVAR_NEVER_AS_STRING");
          }
          else
          {
            m_pszString = vprof_dump_spikes_budget_group.m_pParent->m_Value.m_pszString;
            if ( m_pszString == nullptr )
              m_pszString = (char *)defaultValue;
            v13 = CVProfile::BudgetGroupNameToBudgetGroupID(
                    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                    a2: m_pszString);
          }
        }
        else
        {
          v13 = -1;
        }
        if ( (vprof_dump_spikes_node.m_nFlags & 0x1000) != 0
          || (v15 = vprof_dump_spikes_node.m_pParent->m_Value.m_pszString) != nullptr && *v15 != 0 )
        {
          if ( (vprof_dump_spikes_node.m_nFlags & 0x1000) != 0 )
          {
            v16 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v16 = vprof_dump_spikes_node.m_pParent->m_Value.m_pszString;
            if ( v16 == nullptr )
              v16 = (char *)defaultValue;
          }
        }
        else
        {
          v16 = nullptr;
        }
        CVProfile::OutputReport(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: v11,
          a3: v16,
          a4: v13);
        goto LABEL_62;
      }
      if ( (vprof_dump_spikes_budget_group.m_nFlags & 0x1000) != 0
        || (v5 = vprof_dump_spikes_budget_group.m_pParent->m_Value.m_pszString) != nullptr && *v5 != 0 )
      {
        if ( (vprof_dump_spikes_budget_group.m_nFlags & 0x1000) != 0 )
        {
          v6 = CVProfile::BudgetGroupNameToBudgetGroupID(
                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                 a2: "FCVAR_NEVER_AS_STRING");
        }
        else
        {
          v7 = vprof_dump_spikes_budget_group.m_pParent->m_Value.m_pszString;
          if ( v7 == nullptr )
            v7 = (char *)defaultValue;
          v6 = CVProfile::BudgetGroupNameToBudgetGroupID(
                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                 a2: v7);
        }
      }
      else
      {
        v6 = -1;
      }
      if ( (vprof_dump_spikes_node.m_nFlags & 0x1000) != 0
        || (v8 = vprof_dump_spikes_node.m_pParent->m_Value.m_pszString) != nullptr && *v8 != 0 )
      {
        if ( (vprof_dump_spikes_node.m_nFlags & 0x1000) != 0 )
        {
          CVProfile::OutputReport(
            this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
            a2: 4,
            a3: "FCVAR_NEVER_AS_STRING",
            a4: v6);
LABEL_62:
          LastSpikeTime = _Plat_FloatTime(this: v9);
          v17 = vprof_dump_spikes.m_pParent->m_Value.m_fValue >= 0.0;
          LastSpikeFrame = g_ServerGlobalVariables.framecount;
          if ( !v17 )
          {
            ConVar::SetValue(this: (ConVar *)&vprof_dump_spikes.IConVar, value: 0.0);
            g_fVprofOnByUI = false;
            v49 = 1;
          }
          if ( !v48.m_condebugEnabled )
            CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&con_logfile.IConVar, value: defaultValue);
          goto LABEL_66;
        }
        v10 = vprof_dump_spikes_node.m_pParent->m_Value.m_pszString;
        if ( v10 == nullptr )
        {
          CVProfile::OutputReport(
            this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
            a2: 4,
            a3: defaultValue,
            a4: v6);
          goto LABEL_62;
        }
      }
      else
      {
        v10 = nullptr;
      }
      CVProfile::OutputReport(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: 4, a3: v10, a4: v6);
      goto LABEL_62;
    }
  }
LABEL_77:
  if ( vprof_counters.m_pParent == nullptr )
  {
    m_nValue = 0;
LABEL_79:
    if ( !g_bDumpCounters )
      goto LABEL_112;
    goto LABEL_80;
  }
  m_nValue = vprof_counters.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    goto LABEL_79;
LABEL_80:
  NumCounters = CVProfile::GetNumCounters(this: v1);
  v21 = 0;
  v43 = NumCounters;
  idx = 0;
  v41 = 0;
  if ( NumCounters > 0 )
  {
    v38 = m_nValue - 1;
    do
    {
      if ( CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v21) == v38 )
      {
        CounterNameAndValue = CVProfile::GetCounterNameAndValue(
                                this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                a2: v21,
                                a3: (int *)&v47);
        v23 = CounterNameAndValue;
        v37 = CounterNameAndValue;
        if ( g_bDumpCounters )
          _Msg(a1: "VPROF: %s = %d\n", CounterNameAndValue, v47);
        if ( vprof_counters_show_minmax.m_pParent != nullptr
          && vprof_counters_show_minmax.m_pParent->m_Value.m_nValue != 0 )
        {
          if ( (_S1_21 & 1) == 0 )
          {
            _S1_21 |= 1u;
            v24 = 29;
            p_m_nGrowSize = &history.m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = 0;
              *(p_m_nGrowSize - 1) = 0;
              *p_m_nGrowSize = 0;
              p_m_nGrowSize[1] = 0;
              p_m_nGrowSize[2] = 0;
              p_m_nGrowSize += 5;
              --v24;
            }
            while ( v24 >= 0 );
            atexit(func: PreUpdateProfile_::_62_::_dynamic_atexit_destructor_for__history__);
          }
          v26 = nCycle;
          v27 = *(&history.m_Size + 5 * nCycle);
          if ( v27 < NumCounters )
          {
            CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
              this: &history + nCycle,
              elem: v27,
              num: NumCounters - v27);
            v26 = nCycle;
          }
          (&history.m_Memory.m_pMemory)[5 * v26][v21] = v47;
          v44 = v47;
          v45 = v47;
          p_m_Size = &history.m_Size;
          do
          {
            v29 = *p_m_Size;
            if ( *p_m_Size < v43 )
            {
              v30 = v43 - v29;
              if ( v43 != v29 )
              {
                v31 = *(p_m_Size - 2);
                if ( v43 > v31 )
                  CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)p_m_Size - 1, num: v43 - v31);
                *p_m_Size += v30;
                v32 = *(p_m_Size - 3);
                v33 = *p_m_Size - v43;
                p_m_Size[1] = v32;
                if ( v33 > 0 && v30 > 0 )
                  _V_memmove(dest: (void *)(v32 + 4 * v43), src: (const void *)(v32 + 4 * v29), count: 4 * v33);
              }
            }
            v34 = *(p_m_Size - 3);
            v35 = *(_DWORD *)(v34 + 4 * v41);
            if ( *(_DWORD *)&v44 >= v35 )
              v44 = *(S3RGBA *)(v34 + 4 * v41);
            if ( *(_DWORD *)&v45 <= v35 )
              v45 = *(S3RGBA *)(v34 + 4 * v41);
            p_m_Size += 5;
          }
          while ( (int)p_m_Size < (int)&`CUtlRBTree<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short,CUtlMap<char *,double,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' );
          Con_NPrintf(idx, fmt: "%s = %6d (%6d:%6d)\n", v37, v47, v44, v45);
          v21 = v41;
          NumCounters = v43;
        }
        else
        {
          Con_NPrintf(idx, fmt: "%s = %d\n", v23, v47);
        }
        ++idx;
      }
      v41 = ++v21;
    }
    while ( v21 < NumCounters );
  }
  v1 = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  nCycle = (nCycle + 1) % 30;
LABEL_112:
  CVProfile::ResetCounters(this: v1, a2: COUNTER_GROUP_DEFAULT);
  CVProfile::ResetCounters(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: COUNTER_GROUP_TEXTURE_PER_FRAME);
  CVProfile::ResetCounters(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: COUNTER_GROUP_GRAPHICS_PER_FRAME);
  CVProfExport::SnapshotVProfHistory(this: &g_VProfExport);
  VProfRecord_Snapshot();
  if ( GetVProfPanel() != nullptr )
  {
    VProfPanel = GetVProfPanel();
    CVProfPanel::UpdateProfile(this: VProfPanel, filteredtime);
  }
  g_bDumpCounters = false;
}

//------------------------------------------------------------------------------
// Address: 0x101F21A0
// Name: void RemoveVProfDataListener(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveVProfDataListener(unsigned int listenerID)
{
  VProfListenInfo_t findInfo; // [esp+0h] [ebp-1Ch] BYREF

  findInfo.m_nListenerId = listenerID;
  memset(&findInfo.m_flLastSentVProfDataTime, 0, 24);
  if ( CUtlVector<VProfListenInfo_t,CUtlMemory<VProfListenInfo_t,int>>::FindAndRemove(
         this: &s_VProfListeners,
         src: &findInfo) != 0
    && --g_VProfExport.m_nListeners == 0 )
  {
    g_VProfExport.m_bStop = true;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&findInfo.m_SentGroups);
}

//------------------------------------------------------------------------------
// Address: 0x101F2260
// Name: void RegisterVProfDataListener(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RegisterVProfDataListener(unsigned int listenerID)
{
  int v1; // ecx
  VProfListenInfo_t src; // [esp+0h] [ebp-1Ch] BYREF

  src.m_nListenerId = listenerID;
  memset(&src.m_flLastSentVProfDataTime, 0, 24);
  if ( CUtlVector<VProfListenInfo_t,CUtlMemory<VProfListenInfo_t,int>>::FindAndRemove(this: &s_VProfListeners, &src) != 0
    && --g_VProfExport.m_nListeners == 0 )
  {
    g_VProfExport.m_bStop = true;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&src.m_SentGroups);
  v1 = CUtlVector<VProfListenInfo_t,CUtlMemory<VProfListenInfo_t,int>>::InsertBefore(
         this: &s_VProfListeners,
         elem: s_VProfListeners.m_Size);
  s_VProfListeners.m_Memory.m_pMemory[v1].m_nListenerId = listenerID;
  if ( ++g_VProfExport.m_nListeners == 1 )
    g_VProfExport.m_bStart = true;
  WriteRemoteVProfGroupData(info: &s_VProfListeners.m_Memory.m_pMemory[v1]);
}

//------------------------------------------------------------------------------
// Address: 0x102D3DD0
// Name: public: virtual void CVProfExport::SetBudgetFlagsFilter(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfExport::SetBudgetFlagsFilter(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

} // namespace engine_xlsp
