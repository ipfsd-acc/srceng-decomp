// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/bugreporter.cpp
// Functions: 106
// ============================================================

#include "engine\bugreporter.h"

//------------------------------------------------------------------------------
// Address: 0x1013C420
// Name: public: class vgui::Panel __near * vgui::PHandle::operator=(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDragDropHelperPanel *__thiscall vgui::PHandle::operator=(vgui::PHandle *this, CDragDropHelperPanel *pPanel)
{
  return vgui::DHANDLE<CDragDropHelperPanel>::operator=((vgui::DHANDLE<CDragDropHelperPanel> *)this, pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1013C430
// Name: unsigned long GetRam(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetRam()
{
  _MEMORYSTATUS stat; // [esp+0h] [ebp-20h] BYREF

  GlobalMemoryStatus(lpBuffer: &stat);
  return stat.dwTotalPhys >> 20;
}

//------------------------------------------------------------------------------
// Address: 0x1013C450
// Name: char const __near * GetInternalBugReporterDLL(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetInternalBugReporterDLL()
{
  int v0; // eax
  const char *result; // eax
  int v2; // eax
  bool v3; // zf
  const char *pBugReportedDLL; // [esp+4h] [ebp-4h] BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-remotebug", a3: 0) != 0 )
    return "bugreporter_remote";
  pBugReportedDLL = nullptr;
  v2 = _CommandLine();
  v3 = (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v2 + 12))(
         a1: v2,
         a2: "-bugreporterdll",
         a3: &pBugReportedDLL) == 0;
  result = pBugReportedDLL;
  if ( v3 )
    return "bugreporter_filequeue";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013C4B0
// Name: void DisplaySystemVersion(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisplaySystemVersion(char *osversion, int maxlen)
{
  bool v2; // zf
  const char *v3; // eax
  char build[256]; // [esp+8h] [ebp-19Ch] BYREF
  _OSVERSIONINFOEXA osvi; // [esp+108h] [ebp-9Ch] BYREF

  *osversion = 0;
  memset(dst: (unsigned __int8 *)&osvi, value: 0, count: sizeof(osvi));
  osvi.dwOSVersionInfoSize = 156;
  if ( !GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi) )
  {
    osvi.dwOSVersionInfoSize = 148;
    if ( !GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi) )
    {
      V_strncpy(pDest: osversion, pSrc: "Unable to get Version", maxLen: maxlen);
      return;
    }
  }
  if ( osvi.dwPlatformId == 0 )
  {
    V_strncat(pDest: osversion, pSrc: "Win32s ", destBufferSize: maxlen, max_chars_to_copy: -1);
    return;
  }
  if ( osvi.dwPlatformId != 1 )
  {
    if ( osvi.dwPlatformId != 2 )
      return;
    if ( osvi.dwMajorVersion <= 4 )
      V_strncat(pDest: osversion, pSrc: "Windows NT ", destBufferSize: maxlen, max_chars_to_copy: -1);
    if ( osvi.dwMajorVersion == 5 )
    {
      if ( osvi.dwMinorVersion != 0
        || (V_strncat(pDest: osversion, pSrc: "Windows 2000 ", destBufferSize: maxlen, max_chars_to_copy: -1),
            osvi.dwMajorVersion == 5) )
      {
        if ( osvi.dwMinorVersion != 1 )
        {
LABEL_18:
          v2 = !IsUserAnAdmin();
          v3 = "no";
          if ( v2 )
            v3 = "yes";
          V_snprintf(
            pDest: build,
            maxLen: 256,
            pFormat: "%s (Build %d) version %d.%d (LimitedUser: %s)",
            osvi.szCSDVersion,
            LOWORD(osvi.dwBuildNumber),
            osvi.dwMajorVersion,
            osvi.dwMinorVersion,
            v3);
          V_strncat(pDest: osversion, pSrc: build, destBufferSize: maxlen, max_chars_to_copy: -1);
          return;
        }
        V_strncat(pDest: osversion, pSrc: "Windows XP ", destBufferSize: maxlen, max_chars_to_copy: -1);
      }
    }
    if ( osvi.dwMajorVersion == 6 )
      V_strncat(pDest: osversion, pSrc: "Windows Vista ", destBufferSize: maxlen, max_chars_to_copy: -1);
    if ( osvi.dwMajorVersion == 7 )
      V_strncat(pDest: osversion, pSrc: "Windows 7 ", destBufferSize: maxlen, max_chars_to_copy: -1);
    goto LABEL_18;
  }
  if ( osvi.dwMajorVersion == 4 )
  {
    if ( osvi.dwMinorVersion != 0 )
      goto LABEL_31;
    V_strncat(pDest: osversion, pSrc: "95 ", destBufferSize: maxlen, max_chars_to_copy: -1);
    if ( osvi.szCSDVersion[1] == 67 || osvi.szCSDVersion[1] == 66 )
      V_strncat(pDest: osversion, pSrc: "OSR2 ", destBufferSize: maxlen, max_chars_to_copy: -1);
    if ( osvi.dwMajorVersion == 4 )
    {
LABEL_31:
      if ( osvi.dwMinorVersion != 10 )
        goto LABEL_32;
      V_strncat(pDest: osversion, pSrc: "98 ", destBufferSize: maxlen, max_chars_to_copy: -1);
      if ( osvi.szCSDVersion[1] == 65 )
        V_strncat(pDest: osversion, pSrc: "SE ", destBufferSize: maxlen, max_chars_to_copy: -1);
      if ( osvi.dwMajorVersion == 4 )
      {
LABEL_32:
        if ( osvi.dwMinorVersion == 90 )
          V_strncat(pDest: osversion, pSrc: "Me ", destBufferSize: maxlen, max_chars_to_copy: -1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C710
// Name: public: CBugReportUploadProgressDialog::CBugReportUploadProgressDialog(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBugReportUploadProgressDialog *__thiscall CBugReportUploadProgressDialog::CBugReportUploadProgressDialog(
        CBugReportUploadProgressDialog *this,
        vgui::Panel *parent,
        const char *name,
        const char *title,
        const char *message)
{
  vgui::ProgressBar *v6; // eax
  vgui::ProgressBar *v7; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBugReportUploadProgressDialog_vtbl *)&CBugReportUploadProgressDialog::`vftable';
  vgui::Panel::SetSize(this, wide: 300, tall: 160);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Panel::MoveToFront(this);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v6 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v6 != nullptr )
    v7 = vgui::ProgressBar::ProgressBar(this: v6, parent: this, panelName: "ProgressBar");
  else
    v7 = nullptr;
  this->m_pProgress = v7;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\BugReporterUploadProgress.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::EditablePanel::SetControlString(this, controlName: "InfoLabel", string: message);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013C7C0
// Name: public: static char const __near * vgui::Frame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Frame::GetPanelClassName()
{
  return "Frame";
}

//------------------------------------------------------------------------------
// Address: 0x1013C7D0
// Name: public: void CBugReportUploadProgressDialog::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReportUploadProgressDialog::SetProgress(CBugReportUploadProgressDialog *this, float progress)
{
  ((void (__stdcall *)(_DWORD))this->m_pProgress->SetProgress)(a1: LODWORD(progress));
}

//------------------------------------------------------------------------------
// Address: 0x1013C7F0
// Name: public: virtual void CBugReportUploadProgressDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReportUploadProgressDialog::PerformLayout(CBugReportUploadProgressDialog *this)
{
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013C820
// Name: public: CBugReportFinishedDialog::CBugReportFinishedDialog(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBugReportFinishedDialog *__thiscall CBugReportFinishedDialog::CBugReportFinishedDialog(
        CBugReportFinishedDialog *this,
        vgui::Panel *parent,
        const char *name,
        const char *title,
        const char *message)
{
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBugReportFinishedDialog_vtbl *)&CBugReportFinishedDialog::`vftable';
  vgui::Panel::SetSize(this, wide: 300, tall: 160);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Panel::MoveToFront(this);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "CloseBtn",
           text: "#OK",
           pActionSignalTarget: this,
           pCmd: "Close");
  else
    v7 = nullptr;
  this->m_pOk = v7;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\BugReporterUploadFinished.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::EditablePanel::SetControlString(this, controlName: "InfoLabel", string: message);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013C8D0
// Name: public: virtual void CBugReportFinishedDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReportFinishedDialog::OnCommand(CBugReportFinishedDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "Close") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    this->MarkForDeletion(this);
    this->OnClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C920
// Name: public: virtual void CBugReportFinishedDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReportFinishedDialog::PerformLayout(CBugReportFinishedDialog *this)
{
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: true);
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013C950
// Name: public: static char const __near * CBugUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBugUIPanel::GetPanelClassName()
{
  return "CBugUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1013C960
// Name: public: virtual void CBugUIPanel::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::SetVisible(CBugUIPanel *this, int state)
{
  bool state_3; // [esp+13h] [ebp+Bh]

  state_3 = (_BYTE)state != this->IsVisible(this);
  vgui::Panel::SetVisible(this, state);
  if ( state_3 && (_BYTE)state != 0 )
    this->m_pTitle->RequestFocus(this: this->m_pTitle, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013C9B0
// Name: protected: void CBugUIPanel::GetDataFileBase(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::GetDataFileBase(CBugUIPanel *this, const char *suffix, char *buf, int bufsize)
{
  char who[128]; // [esp+4h] [ebp-A4h] BYREF
  tm t; // [esp+84h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &t);
  V_strncpy(pDest: who, pSrc: suffix, maxLen: 128);
  _V_strlower(start: who);
  if ( this->m_pBugReporter != nullptr && this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
    V_snprintf(pDest: buf, maxLen: bufsize, pFormat: "%i_%02i_%02i", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
  else
    V_snprintf(pDest: buf, maxLen: bufsize, pFormat: "%i_%02i_%02i_%s", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, who);
}

//------------------------------------------------------------------------------
// Address: 0x1013CA70
// Name: protected: char const __near * CBugUIPanel::GetRepositoryURL(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugUIPanel::GetRepositoryURL(CBugUIPanel *this)
{
  const char *result; // eax

  result = this->m_pBugReporter->GetRepositoryURL(this: this->m_pBugReporter);
  if ( result == nullptr )
    return "\\\\fileserver\\bugs";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013CA90
// Name: protected: char const __near * CBugUIPanel::GetSubmissionURL(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBugUIPanel::GetSubmissionURL(CBugUIPanel *this, int bugid)
{
  char *result; // eax
  const char *v4; // eax

  result = (char *)this->m_pBugReporter->GetSubmissionURL(this: this->m_pBugReporter);
  if ( result == nullptr )
  {
    v4 = this->m_pBugReporter->GetRepositoryURL(this: this->m_pBugReporter);
    if ( v4 == nullptr )
      v4 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: url, maxLen: 512, pFormat: "%s/%i", v4, bugid);
    return url;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013CAF0
// Name: protected: void CBugUIPanel::RepopulateMaps(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::RepopulateMaps(CBugUIPanel *this, int area_index, const char *default_level)
{
  int v4; // ebx
  const char *v5; // edi
  int c; // [esp+Ch] [ebp-Ch]
  int id; // [esp+10h] [ebp-8h]
  int item; // [esp+14h] [ebp-4h]

  c = this->m_pBugReporter->GetLevelCount(this: this->m_pBugReporter, a2: area_index);
  item = -1;
  vgui::ComboBox::RemoveAll(this: this->m_pMapNumber);
  v4 = 0;
  if ( c <= 0 )
    goto LABEL_7;
  do
  {
    v5 = this->m_pBugReporter->GetLevel(this: this->m_pBugReporter, a2: area_index, a3: v4);
    id = this->m_pMapNumber->AddItem_2(this: this->m_pMapNumber, a2: v5, a3: nullptr);
    if ( _V_stricmp(s1: default_level, s2: v5) == 0 )
      item = id;
    ++v4;
  }
  while ( v4 < c );
  if ( item < 0 )
LABEL_7:
    vgui::ComboBox::ActivateItemByRow(this: this->m_pMapNumber, row: 0);
  else
    this->m_pMapNumber->ActivateItem(this: this->m_pMapNumber, a2: item);
}

//------------------------------------------------------------------------------
// Address: 0x1013CBB0
// Name: protected: virtual void CBugUIPanel::OnChooseArea(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnChooseArea(CBugUIPanel *this, vgui::ComboBox *panel)
{
  const char *InternalBugReporterDLL; // eax
  int ActiveItem; // edi
  CClientState *BaseLocalClient; // eax
  const char *v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // ebx
  int v10; // edi
  const char *v11; // eax
  const char *defaultOwner; // [esp+10h] [ebp+8h]

  if ( panel == this->m_pGameArea )
  {
    InternalBugReporterDLL = GetInternalBugReporterDLL();
    if ( _V_strcmp(s1: "bugreporter_filequeue", s2: InternalBugReporterDLL) == 0 )
    {
      ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pGameArea);
      if ( GetBaseLocalClient()->m_nSignonState == 6 )
      {
        BaseLocalClient = GetBaseLocalClient();
        CBugUIPanel::RepopulateMaps(this, area_index: ActiveItem, default_level: BaseLocalClient->m_szLevelNameShort);
      }
      else
      {
        CBugUIPanel::RepopulateMaps(this, area_index: ActiveItem, default_level: "console");
      }
    }
  }
  else if ( panel == this->m_pMapNumber )
  {
    v6 = GetInternalBugReporterDLL();
    if ( _V_strcmp(s1: "bugreporter_filequeue", s2: v6) == 0 )
    {
      v7 = vgui::ComboBox::GetActiveItem(this: this->m_pGameArea);
      v8 = vgui::ComboBox::GetActiveItem(this: this->m_pMapNumber);
      defaultOwner = this->m_pBugReporter->GetLevelOwner(this: this->m_pBugReporter, a2: v7, a3: v8);
      v9 = this->m_pBugReporter->GetDisplayNameCount(this: this->m_pBugReporter);
      v10 = 0;
      if ( v9 > 0 )
      {
        while ( 1 )
        {
          v11 = this->m_pBugReporter->GetUserNameA(this: this->m_pBugReporter, a2: v10);
          if ( _V_stricmp(s1: v11, s2: defaultOwner) == 0 )
            break;
          if ( ++v10 >= v9 )
            return;
        }
        this->m_pAssignTo->ActivateItem(this: this->m_pAssignTo, a2: v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CCE0
// Name: protected: bool CBugUIPanel::IsValidEmailAddress(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBugUIPanel::IsValidEmailAddress(CBugUIPanel *this, char *email)
{
  char v2; // cl
  char *v3; // esi
  char v4; // al
  int v5; // eax
  unsigned __int8 *v6; // esi
  int v7; // eax

  if ( email == nullptr || strlen(email) < 5 )
    return false;
  v3 = email;
  if ( *email != v2 )
  {
    do
    {
      if ( isalnum(c: *v3) == 0 )
      {
        v4 = *v3;
        if ( *v3 != 46 && v4 != 45 && v4 != 64 && v4 != 95 )
          return false;
      }
    }
    while ( *++v3 != 0 );
  }
  if ( isalnum(c: *email) == 0 )
    return false;
  strstr(str1: (unsigned __int8 *)email, str2: "@");
  if ( v5 == 0 )
    return false;
  v6 = (unsigned __int8 *)(v5 + 1);
  if ( isalnum(c: *(char *)(v5 + 1)) == 0 )
    return false;
  strstr(str1: v6, str2: ".");
  if ( v7 == 0 )
    return false;
  return isalnum(c: *(char *)(v7 + 1)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013CDB0
// Name: protected: bool CBugUIPanel::IsValidSubmission(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBugUIPanel::IsValidSubmission(CBugUIPanel *this, bool verbose)
{
  int v4; // eax
  bool v5; // al
  vgui::TextEntry *m_pTitle; // ecx
  bool v7; // bl
  IBugReporter_vtbl *v8; // edi
  int ActiveItem; // eax
  const char *v10; // eax
  _BYTE v11[4096]; // [esp+4h] [ebp-1250h] BYREF
  char pDest[256]; // [esp+1004h] [ebp-250h] BYREF
  char v13[256]; // [esp+1104h] [ebp-150h] BYREF
  char email[80]; // [esp+1204h] [ebp-50h] BYREF

  if ( this->m_pBugReporter == nullptr )
    return false;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-remotebug", a3: 0) != 0 )
    return true;
  v5 = this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter);
  m_pTitle = this->m_pTitle;
  v7 = v5;
  v13[0] = 0;
  v11[0] = 0;
  m_pTitle->GetText_2(this: m_pTitle, a2: v13, a3: 256);
  if ( v13[0] == 0 )
  {
    if ( verbose )
    {
      _Warning(a1: "Bug must have a title\n");
      return false;
    }
    return false;
  }
  if ( v7 )
  {
    this->m_pDescription->GetText_2(this: this->m_pDescription, a2: v11, a3: 4096);
    if ( v11[0] == 0 )
    {
      if ( verbose )
      {
        _Warning(a1: "Bug must have a description\n");
        return false;
      }
      return false;
    }
  }
  else
  {
    if ( vgui::ComboBox::GetActiveItem(this: this->m_pSeverity) < 0 )
    {
      if ( verbose )
      {
        _Warning(a1: "Severity not set!\n");
        return false;
      }
      return false;
    }
    if ( vgui::ComboBox::GetActiveItem(this: this->m_pAssignTo) < 0 )
    {
LABEL_18:
      if ( verbose )
      {
        _Warning(a1: "Owner not set!\n");
        return false;
      }
      return false;
    }
  }
  v8 = this->m_pBugReporter->__vftable;
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pAssignTo);
  v10 = v8->GetDisplayName(this: this->m_pBugReporter, a2: ActiveItem);
  V_strncpy(pDest, pSrc: v10, maxLen: 256);
  if ( v7 )
  {
    if ( vgui::ComboBox::GetActiveItem(this: this->m_pReportType) > 0 )
    {
      this->m_pEmail->GetText_2(this: this->m_pEmail, a2: email, a3: 80);
      return email[0] == 0 || CBugUIPanel::IsValidEmailAddress(this, email);
    }
LABEL_28:
    if ( verbose )
      _Warning(a1: "ReportType not set!\n");
    return false;
  }
  if ( _V_stricmp(s1: pDest, s2: "<<Unassigned>>") == 0 )
    goto LABEL_18;
  if ( vgui::ComboBox::GetActiveItem(this: this->m_pPriority) < 0 )
  {
    if ( verbose )
    {
      _Warning(a1: "Priority not set!\n");
      return false;
    }
    return false;
  }
  if ( vgui::ComboBox::GetActiveItem(this: this->m_pReportType) < 0 )
    goto LABEL_28;
  if ( vgui::ComboBox::GetActiveItem(this: this->m_pGameArea) < 0 )
  {
    if ( verbose )
    {
      _Warning(a1: "Area not set!\n");
      return false;
    }
    return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1013D030
// Name: protected: bool CBugUIPanel::AddFileToZip(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugUIPanel::AddFileToZip(CBugUIPanel *this, const char *relative)
{
  HZIP__ *ZipZ; // eax
  char outname[512]; // [esp+4h] [ebp-520h] BYREF
  char fullpath[512]; // [esp+204h] [ebp-320h] BYREF
  char basename[256]; // [esp+404h] [ebp-120h] BYREF
  char extension[32]; // [esp+504h] [ebp-20h] BYREF

  if ( this->m_hZip == nullptr )
  {
    ZipZ = CreateZipZ(z: nullptr, len: 0x1000000u, flags: 3u);
    this->m_hZip = ZipZ;
    if ( ZipZ == nullptr )
      return 0;
  }
  if ( g_pFileSystem->RelativePathToFullPath(
         this: g_pFileSystem,
         a2: relative,
         a3: "GAME",
         a4: fullpath,
         a5: 512,
         a6: 0,
         a7: 0) == nullptr )
    return 0;
  V_ExtractFileExtension(path: relative, dest: extension, destSize: 32);
  V_FileBase(in: relative, out: basename, maxlen: 256);
  V_snprintf(pDest: outname, maxLen: 512, pFormat: "%s.%s", basename, extension);
  ZipAdd(hz: this->m_hZip, dstzn: outname, src: fullpath, len: 0, flags: 2u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013D110
// Name: void NonFileSystem_CreatePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NonFileSystem_CreatePath(const char *path)
{
  char *i; // esi
  char v2; // bl
  char temppath[512]; // [esp+4h] [ebp-200h] BYREF

  V_strncpy(pDest: temppath, pSrc: path, maxLen: 512);
  for ( i = &temppath[1]; *i != 0; ++i )
  {
    v2 = *i;
    if ( *i == 47 || v2 == 92 )
    {
      *i = 0;
      _mkdir(path: temppath);
      *i = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D170
// Name: protected: bool CBugUIPanel::UploadFile(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBugUIPanel::UploadFile(CBugUIPanel *this, const char *local, const char *remote, bool bDeleteLocal)
{
  const char *v4; // ebx
  void *v5; // edi
  BOOL v7; // eax
  DWORD LastError; // eax
  const char *v9; // eax
  _iobuf *v10; // ebx
  unsigned __int8 *v11; // eax
  int v12; // ebx
  unsigned int v13; // esi
  int nLocalFileSize; // [esp+Ch] [ebp-8h]
  _iobuf *r; // [esp+10h] [ebp-4h]
  unsigned __int8 *pCopyBuf; // [esp+20h] [ebp+Ch]
  bool pCopyBuf_3; // [esp+23h] [ebp+Fh]

  v4 = local;
  _Msg(a1: "Uploading %s to %s\n", local, remote);
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: local, a3: "rb", a4: 0);
  if ( v5 == nullptr )
  {
    _Warning(a1: "CBugUIPanel::UploadFile:  Unable to open local path '%s'\n", local);
    return false;
  }
  nLocalFileSize = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
  if ( nLocalFileSize <= 0 )
  {
    _Warning(a1: "CBugUIPanel::UploadFile:  Local file has 0 size '%s'\n", local);
LABEL_5:
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    return false;
  }
  NonFileSystem_CreatePath(path: remote);
  if ( g_pFileSystem->IsSteam(this: g_pFileSystem) )
  {
    v9 = va(format: "%s", remote);
    v10 = fopen(file: v9, mode: "wb");
    r = v10;
    if ( v10 == nullptr )
    {
      _Warning(a1: "CBugUIPanel::UploadFile:  Unable to open remote path '%s'\n", remote);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
      return false;
    }
    v11 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x200000u);
    pCopyBuf = v11;
    if ( v11 == nullptr )
    {
      _Warning(a1: "CBugUIPanel::UploadFile:  Unable to allocate copy buffer of %d bytes\n", 0x200000);
      fclose(stream: v10);
      goto LABEL_5;
    }
    v12 = nLocalFileSize;
    while ( 1 )
    {
      v13 = v12;
      if ( v12 >= 0x200000 )
        v13 = 0x200000;
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v11, a3: v13, a4: v5);
      fwrite(buffer: pCopyBuf, size: v13, count: 1u, stream: r);
      v12 -= v13;
      if ( v12 <= 0 )
        break;
      v11 = pCopyBuf;
    }
    fclose(stream: r);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    free(pMem: pCopyBuf);
    v4 = local;
    pCopyBuf_3 = true;
  }
  else
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    v7 = CopyFileA(lpExistingFileName: local, lpNewFileName: remote, bFailIfExists: false);
    pCopyBuf_3 = v7;
    if ( !v7 )
    {
      LastError = GetLastError();
      _Warning(a1: "Failed to upload %s, error %d\n", local, LastError);
      return false;
    }
  }
  if ( bDeleteLocal )
    unlink(path: v4);
  return pCopyBuf_3;
}

//------------------------------------------------------------------------------
// Address: 0x1013D3A0
// Name: protected: bool CBugUIPanel::AutoFillToken(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugUIPanel::AutoFillToken(CBugUIPanel *this, const char *token, bool partial)
{
  const char *v5; // eax
  int v6; // ebx
  const char *v7; // edi
  const char *v8; // eax
  int v9; // ebx
  int i; // edi
  const char *v11; // eax
  const char *v12; // eax
  int v13; // ebx
  int j; // edi
  const char *v15; // eax
  const char *v16; // eax
  int v17; // ebx
  int k; // edi
  const char *v19; // eax
  const char *v20; // eax
  int v21; // ebx
  int m; // edi
  const char *v23; // eax
  const char *v24; // eax
  const char *userName; // [esp+4h] [ebp-8h]
  int c; // [esp+8h] [ebp-4h]

  if ( this->m_pBugReporter == nullptr )
    return 1;
  v5 = "PARTIAL";
  if ( !partial )
    v5 = "FULL";
  _Msg(a1: "AUTOFILL: %s (%s)\n", token, v5);
  v6 = 0;
  c = this->m_pBugReporter->GetDisplayNameCount(this: this->m_pBugReporter);
  if ( c > 0 )
  {
    do
    {
      v7 = this->m_pBugReporter->GetDisplayName(this: this->m_pBugReporter, a2: v6);
      v8 = this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: v7);
      userName = v8;
      if ( partial )
      {
        if ( V_stristr(pStr: v8, pSearch: token) != nullptr || V_stristr(pStr: v7, pSearch: token) != nullptr )
        {
LABEL_9:
          _Msg(a1: "  ASSIGNED TO: %s\n", userName);
          this->m_pAssignTo->ActivateItem(this: this->m_pAssignTo, a2: v6);
          return 1;
        }
      }
      else if ( _V_stricmp(s1: v8, s2: token) == 0 || _V_stricmp(s1: v7, s2: token) == 0 )
      {
        goto LABEL_9;
      }
      ++v6;
    }
    while ( v6 < c );
  }
  v9 = this->m_pBugReporter->GetSeverityCount(this: this->m_pBugReporter);
  for ( i = 0; i < v9; ++i )
  {
    v11 = this->m_pBugReporter->GetSeverity(this: this->m_pBugReporter, a2: i);
    if ( partial )
    {
      if ( V_stristr(pStr: v11, pSearch: token) != nullptr )
      {
LABEL_16:
        v12 = this->m_pBugReporter->GetSeverity(this: this->m_pBugReporter, a2: i);
        _Msg(a1: "  SEVERITY: %s\n", v12);
        this->m_pSeverity->ActivateItem(this: this->m_pSeverity, a2: i);
        return 1;
      }
    }
    else if ( _V_stricmp(s1: v11, s2: token) == 0 )
    {
      goto LABEL_16;
    }
  }
  v13 = this->m_pBugReporter->GetReportTypeCount(this: this->m_pBugReporter);
  for ( j = 0; j < v13; ++j )
  {
    v15 = this->m_pBugReporter->GetReportType(this: this->m_pBugReporter, a2: j);
    if ( partial )
    {
      if ( V_stristr(pStr: v15, pSearch: token) != nullptr )
      {
LABEL_22:
        v16 = this->m_pBugReporter->GetReportType(this: this->m_pBugReporter, a2: j);
        _Msg(a1: "  REPORT TYPE: %s\n", v16);
        this->m_pReportType->ActivateItem(this: this->m_pReportType, a2: j);
        return 1;
      }
    }
    else if ( _V_stricmp(s1: v15, s2: token) == 0 )
    {
      goto LABEL_22;
    }
  }
  v17 = this->m_pBugReporter->GetPriorityCount(this: this->m_pBugReporter);
  for ( k = 0; k < v17; ++k )
  {
    v19 = this->m_pBugReporter->GetPriority(this: this->m_pBugReporter, a2: k);
    if ( partial )
    {
      if ( V_stristr(pStr: v19, pSearch: token) != nullptr )
      {
LABEL_28:
        v20 = this->m_pBugReporter->GetPriority(this: this->m_pBugReporter, a2: k);
        _Msg(a1: "  PRIORITY: %s\n", v20);
        this->m_pPriority->ActivateItem(this: this->m_pPriority, a2: k);
        return 1;
      }
    }
    else if ( _V_stricmp(s1: v19, s2: token) == 0 )
    {
      goto LABEL_28;
    }
  }
  v21 = this->m_pBugReporter->GetAreaCount(this: this->m_pBugReporter);
  for ( m = 0; m < v21; ++m )
  {
    v23 = this->m_pBugReporter->GetArea(this: this->m_pBugReporter, a2: m);
    if ( partial )
    {
      if ( V_stristr(pStr: v23, pSearch: token) != nullptr )
      {
LABEL_34:
        v24 = this->m_pBugReporter->GetArea(this: this->m_pBugReporter, a2: m);
        _Msg(a1: "  AREA: %s\n", v24);
        this->m_pGameArea->ActivateItem(this: this->m_pGameArea, a2: m);
        return 1;
      }
    }
    else if ( _V_stricmp(s1: v23, s2: token) == 0 )
    {
      goto LABEL_34;
    }
  }
  if ( _V_stricmp(s1: token, s2: "screenshot") != 0 )
  {
    if ( _V_stricmp(s1: token, s2: "noscreenshot") != 0 )
    {
      return 0;
    }
    else
    {
      this->m_fAutoAddScreenshot = 2;
      return 1;
    }
  }
  else
  {
    this->m_fAutoAddScreenshot = 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D740
// Name: protected: void CBugUIPanel::CheckContinueQueryingSteamForCSERList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::CheckContinueQueryingSteamForCSERList(CBugUIPanel *this)
{
  CSteam3Client *v2; // eax
  unsigned __int16 v3; // bx
  unsigned int unIP; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 usPort; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_bQueryingSteamForCSER && Steam3Client()->m_pSteamUtils != nullptr )
  {
    v2 = Steam3Client();
    v2->m_pSteamUtils->GetCSERIPPort(this: v2->m_pSteamUtils, a2: &unIP, a3: &usPort);
    if ( unIP != 0 )
    {
      v3 = usPort;
      netadr_s::SetIP(this: &this->m_cserIP, unIP);
      netadr_s::SetPort(this: &this->m_cserIP, newport: v3);
      this->m_bQueryingSteamForCSER = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D7B0
// Name: public: virtual int CBugUIPanel::GetBugSubmissionCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugUIPanel::GetBugSubmissionCount(CBugUIPanel *this)
{
  return this->m_BugSub;
}

//------------------------------------------------------------------------------
// Address: 0x1013D7C0
// Name: public: virtual void CBugUIPanel::ClearBugSubmissionCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::ClearBugSubmissionCount(CBugUIPanel *this)
{
  this->m_BugSub = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013D7D0
// Name: public: virtual void CEngineBugReporter::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineBugReporter::Init(CEngineBugReporter *this)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_ParentPanel,
    pPanel: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1013D7E0
// Name: public: virtual void CEngineBugReporter::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineBugReporter::Shutdown(CEngineBugReporter *this)
{
  IBugReporter *m_pBugReporter; // ecx
  IBugReporter **p_m_pBugReporter; // esi
  CBugUIPanel *v3; // edi
  struct CSysModule *m_hBugReporter; // eax

  if ( g_pBugUI != nullptr )
  {
    m_pBugReporter = g_pBugUI->m_pBugReporter;
    p_m_pBugReporter = &g_pBugUI->m_pBugReporter;
    v3 = g_pBugUI;
    if ( m_pBugReporter != nullptr )
      m_pBugReporter->Shutdown(this: m_pBugReporter);
    m_hBugReporter = v3->m_hBugReporter;
    *p_m_pBugReporter = nullptr;
    if ( m_hBugReporter != nullptr )
    {
      Sys_UnloadModule(pModule: m_hBugReporter);
      v3->m_hBugReporter = nullptr;
    }
    g_pBugUI = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D840
// Name: public: virtual bool CEngineBugReporter::ShouldPause(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineBugReporter::ShouldPause(CEngineBugReporter *this)
{
  CClientState *BaseLocalClient; // ecx
  int result; // eax

  if ( g_pBugUI == nullptr || !g_pBugUI->IsVisible(this: g_pBugUI) && !g_pBugUI->m_bTakingSnapshot )
    return 0;
  BaseLocalClient = GetBaseLocalClient();
  result = 1;
  if ( BaseLocalClient->m_nMaxClients != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013D880
// Name: public: virtual bool CEngineBugReporter::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineBugReporter::IsVisible(CEngineBugReporter *this)
{
  return g_pBugUI != nullptr && g_pBugUI->IsVisible(this: g_pBugUI);
}

//------------------------------------------------------------------------------
// Address: 0x1013D8B0
// Name: public: virtual int CEngineBugReporter::GetBugSubmissionCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineBugReporter::GetBugSubmissionCount(CEngineBugReporter *this)
{
  int result; // eax

  result = 0;
  if ( g_pBugUI != nullptr )
    return g_pBugUI->GetBugSubmissionCount(this: g_pBugUI);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013D8D0
// Name: public: virtual void CEngineBugReporter::ClearBugSubmissionCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineBugReporter::ClearBugSubmissionCount(CEngineBugReporter *this)
{
  if ( g_pBugUI != nullptr )
    g_pBugUI->ClearBugSubmissionCount(this: g_pBugUI);
}

//------------------------------------------------------------------------------
// Address: 0x1013D8F0
// Name: protected: int CBugUIPanel::GetArea(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugUIPanel::GetArea(CBugUIPanel *this)
{
  CBugUIPanel *v1; // esi
  unsigned int v2; // edx
  const char *v3; // eax
  char *v4; // eax
  IBugReporter *m_pBugReporter; // ecx
  int (__thiscall *GetAreaMapCount)(IBugReporter *); // edx
  const char *v8; // eax
  char *v9; // esi
  char *v10; // eax
  const char *v11; // ebx
  int v12; // edi
  _BYTE *v13; // esi
  int v14; // eax
  IBugReporter *v15; // ecx
  int (__thiscall *v16)(IBugReporter *); // eax
  int v17; // esi
  char szDirectory[260]; // [esp+Ch] [ebp-314h] BYREF
  char szAreaMap[260]; // [esp+110h] [ebp-210h] BYREF
  char mapname[256]; // [esp+214h] [ebp-10Ch] BYREF
  char *gamedir; // [esp+314h] [ebp-Ch]
  CBugUIPanel *v22; // [esp+318h] [ebp-8h]
  int i; // [esp+31Ch] [ebp-4h]

  v1 = this;
  v22 = this;
  memset(mapname, 0, sizeof(mapname));
  v2 = 80;
  if ( host_state.worldmodel != nullptr )
  {
    v3 = modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
    CL_SetupMapName(pName: v3, pFixedName: mapname, maxlen: 256);
    v2 = 78 - strlen(mapname);
  }
  v1->m_pTitle->SetMaximumCharCount(this: v1->m_pTitle, a2: v2);
  v4 = _V_strrchr(s: com_gamedir, c: 92);
  m_pBugReporter = v1->m_pBugReporter;
  gamedir = v4 + 1;
  GetAreaMapCount = m_pBugReporter->GetAreaMapCount;
  i = 0;
  if ( GetAreaMapCount(this: m_pBugReporter) > 0 )
  {
    while ( 1 )
    {
      v8 = v1->m_pBugReporter->GetAreaMap(this: v1->m_pBugReporter, a2: i);
      _V_strcpy(dest: szAreaMap, src: v8);
      v9 = _V_strrchr(s: szAreaMap, c: 64);
      v10 = _V_strrchr(s: szAreaMap, c: 37);
      v11 = v10;
      if ( v9 == nullptr )
        break;
      if ( v10 != nullptr )
      {
        v12 = v10 - v9 - 1;
        v13 = v9 + 1;
        v11 = v10 + 1;
      }
      else
      {
        v13 = v9 + 1;
        v12 = _V_strlen(str: szAreaMap) + szAreaMap - v13;
      }
      _V_memmove(dest: szDirectory, src: v13, count: v12);
      szDirectory[v12] = 0;
      if ( v13 != nullptr )
      {
        v14 = _V_strcmp(s1: szDirectory, s2: gamedir);
        if ( v11 != nullptr )
        {
          if ( v14 == 0 && _V_strstr(s1: mapname, search: v11) != nullptr )
            return i;
        }
        else if ( v14 == 0 )
        {
          return i;
        }
      }
      v15 = v22->m_pBugReporter;
      v16 = v15->GetAreaMapCount;
      v17 = ++i;
      if ( v17 >= v16(this: v15) )
        return 0;
      v1 = v22;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013DAB0
// Name: public: void CUtlMemory<struct CBugUIPanel::includedfile,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBugUIPanel::includedfile,int>::Grow(
        CUtlMemory<CBugUIPanel::includedfile,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBugUIPanel::includedfile *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 9;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBugUIPanel::includedfile *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBugUIPanel::includedfile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DB50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013DB80
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x1013DB90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013DBF0
// Name: protected: void CBugUIPanel::OnTakeSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnTakeSnapshot(CBugUIPanel *this)
{
  IEngineVGuiInternal *v2; // eax
  IEngineVGuiInternal *v3; // eax
  int v4; // eax

  this->m_nSnapShotFrame = host_framecount;
  this->m_bTakingSnapshot = false;
  v2 = EngineVGui();
  if ( v2->IsGameUIVisible(this: v2) )
  {
    this->m_bHidGameUIForSnapshot = true;
    v3 = EngineVGui();
    v3->HideGameUI(this: v3);
  }
  else
  {
    this->m_bHidGameUIForSnapshot = false;
  }
  this->SetVisible(this, a2: false);
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-remotebug", a3: 0) == 0 )
    Cbuf_AddText(
      eTarget: sv.m_State < ss_active ? CBUF_FIRST_PLAYER : CBUF_SERVER,
      pText: "cmd bugunpause\n",
      nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013DC80
// Name: protected: virtual void CBugUIPanel::OnChooseVMFFolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnChooseVMFFolder(CBugUIPanel *this)
{
  vgui::DHANDLE<vgui::DirectorySelectDialog> *p_m_hDirectorySelectDialog; // edi
  vgui::DirectorySelectDialog *v3; // eax
  CDragDropHelperPanel *v4; // eax
  vgui::DirectorySelectDialog *v5; // eax
  vgui::Panel *v6; // eax

  p_m_hDirectorySelectDialog = &this->m_hDirectorySelectDialog;
  if ( vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog) == nullptr )
  {
    v3 = (vgui::DirectorySelectDialog *)MemAlloc_Alloc(nSize: 0x47Cu);
    if ( v3 != nullptr )
      v4 = (CDragDropHelperPanel *)vgui::DirectorySelectDialog::DirectorySelectDialog(
                                     this: v3,
                                     parent: this,
                                     title: "Choose .vmf folder");
    else
      v4 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)p_m_hDirectorySelectDialog,
      pPanel: v4);
  }
  this->m_bAddVMF = false;
  v5 = (vgui::DirectorySelectDialog *)vgui::PHandle::Get(this: p_m_hDirectorySelectDialog);
  vgui::DirectorySelectDialog::SetStartDirectory(this: v5, path: this->m_szVMFContentDirFullpath);
  v6 = vgui::PHandle::Get(this: p_m_hDirectorySelectDialog);
  v6->__vftable[1].IsEnabled(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1013DCF0
// Name: protected: void CBugUIPanel::OnIncludeFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnIncludeFile(CBugUIPanel *this)
{
  vgui::FileOpenDialog *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // eax
  char startPath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_pBugReporter == nullptr || !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
  {
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
    {
      v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
      if ( v2 != nullptr )
        v3 = (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                       this: v2,
                                       parent: this,
                                       title: "Choose file to include",
                                       bOpenOnly: true,
                                       pContextKeyValues: nullptr);
      else
        v3 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
        pPanel: v3);
      if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
      {
        v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
        ((void (__thiscall *)(vgui::Panel *, _DWORD))v4->__vftable[1].GetUnpackStructure)(a1: v4, a2: 0);
        v5 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
        vgui::FileOpenDialog::AddFilter(
          this: v5,
          filter: "*.*",
          filterName: "All Files (*.*)",
          bActive: true,
          pFilterInfo: nullptr);
      }
    }
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      V_strncpy(pDest: startPath, pSrc: com_gamedir, maxLen: 260);
      V_FixSlashes(pname: startPath, separator: 92);
      v6 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::SetStartDirectory(this: v6, dir: startPath);
      v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DE10
// Name: public: virtual bool CKeyValuesDumpForBugreport::KvWriteText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CKeyValuesDumpForBugreport::KvWriteText(CKeyValuesDumpForBugreport *this, const char *szText)
{
  CUtlBuffer::Printf(this: this->m_buffer, pFmt: "%s", szText);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013DE30
// Name: protected: void CBugUIPanel::DetermineSubmitterName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::DetermineSubmitterName(CBugUIPanel *this)
{
  IBugReporter *m_pBugReporter; // ecx
  const char *v3; // eax
  const char *RepositoryURL; // eax
  _iobuf *v5; // edi
  const char *v6; // eax
  char fn[512]; // [esp+4h] [ebp-304h] BYREF
  char display[256]; // [esp+204h] [ebp-104h] BYREF
  Color clr; // [esp+304h] [ebp-4h] BYREF

  m_pBugReporter = this->m_pBugReporter;
  if ( m_pBugReporter != nullptr )
  {
    if ( m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
    {
      this->m_pSubmitter->SetText(this: this->m_pSubmitter, a2: "PublicUser");
      this->m_bCanSeeRepository = true;
      this->m_bCanSubmit = true;
    }
    else
    {
      clr = (Color)-14236;
      memset(display, 0, sizeof(display));
      this->m_pSubmitter->GetText_2(this: this->m_pSubmitter, a2: display, a3: 256);
      v3 = this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: display);
      if ( v3 != nullptr && *v3 != 0 && display[0] != 0 )
      {
        ConColorMsg(a1: &clr, a2: "Username '%s' -- '%s'\n", v3, display);
        RepositoryURL = CBugUIPanel::GetRepositoryURL(this);
        V_snprintf(pDest: fn, maxLen: 512, pFormat: "%s/%s", RepositoryURL, "info.txt");
        V_FixSlashes(pname: fn, separator: 92);
        v5 = fopen(file: fn, mode: "rb");
        if ( v5 != nullptr )
        {
          v6 = CBugUIPanel::GetRepositoryURL(this);
          ConColorMsg(a1: &clr, a2: "Bug Repository '%s'\n", v6);
          fclose(stream: v5);
          this->m_bCanSeeRepository = true;
        }
        else
        {
          _Warning(a1: "Unable to see '%s', check permissions and network connectivity\n", fn);
          this->m_bCanSubmit = false;
        }
      }
      else
      {
        ConColorMsg(a1: &clr, a2: "Failed to determine bug submission name.\n");
        this->m_bCanSubmit = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DFD0
// Name: protected: void CBugUIPanel::PopulateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::PopulateControls(CBugUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // ebx
  int v5; // edi
  const char *v6; // ebx
  const char *v7; // eax
  vgui::ComboBox_vtbl *v8; // edi
  const char *v9; // eax
  int v10; // edi
  const char *v11; // ebx
  const char *v12; // eax
  int v13; // edi
  const char *v14; // ebx
  int v15; // ebx
  vgui::ComboBox_vtbl *v16; // edi
  int v17; // eax
  int v18; // edi
  const char *v19; // ebx
  int v20; // ebx
  vgui::ComboBox_vtbl *v21; // edi
  int v22; // eax
  int Area; // eax
  const char *submitter; // [esp+4h] [ebp-Ch]
  int defitem; // [esp+8h] [ebp-8h]
  int defitema; // [esp+8h] [ebp-8h]
  int defitemb; // [esp+8h] [ebp-8h]
  int c; // [esp+Ch] [ebp-4h]
  int ca; // [esp+Ch] [ebp-4h]
  int cb; // [esp+Ch] [ebp-4h]
  int cc; // [esp+Ch] [ebp-4h]
  int cd; // [esp+Ch] [ebp-4h]
  int ce; // [esp+Ch] [ebp-4h]

  if ( this->m_pBugReporter != nullptr )
  {
    v4 = -1;
    defitem = -1;
    submitter = (const char *)((int (__thiscall *)(IBugReporter *, int, int))this->m_pBugReporter->GetUserNameA_2)(
                                a1: this->m_pBugReporter,
                                a2: a3,
                                a3: a2);
    vgui::ComboBox::RemoveAll(this: this->m_pSubmitter);
    v5 = 0;
    c = this->m_pBugReporter->GetDisplayNameCount(this: this->m_pBugReporter);
    if ( c > 0 )
    {
      do
      {
        v6 = this->m_pBugReporter->GetDisplayName(this: this->m_pBugReporter, a2: v5);
        v7 = this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: v6);
        if ( V_strcasecmp(s1: v7, s2: submitter) == 0 )
          defitem = v5;
        this->m_pSubmitter->AddItem_2(this: this->m_pSubmitter, a2: v6, a3: nullptr);
        ++v5;
      }
      while ( v5 < c );
      v4 = defitem;
    }
    this->m_pSubmitter->ActivateItem(this: this->m_pSubmitter, a2: v4);
    v8 = this->m_pSubmitter->__vftable;
    v9 = this->m_pBugReporter->GetDisplayName(this: this->m_pBugReporter, a2: v4);
    v8->SetText(this: this->m_pSubmitter, a2: v9);
    ca = this->m_pBugReporter->GetDisplayNameCount(this: this->m_pBugReporter);
    vgui::ComboBox::RemoveAll(this: this->m_pAssignTo);
    v10 = 0;
    for ( defitema = -1; v10 < ca; ++v10 )
    {
      v11 = this->m_pBugReporter->GetDisplayName(this: this->m_pBugReporter, a2: v10);
      v12 = this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: v11);
      if ( V_strcasecmp(s1: v12, s2: submitter) == 0 )
        defitema = v10;
      this->m_pAssignTo->AddItem_2(this: this->m_pAssignTo, a2: v11, a3: nullptr);
    }
    this->m_pAssignTo->ActivateItem(this: this->m_pAssignTo, a2: defitema);
    v13 = 0;
    defitemb = 0;
    vgui::ComboBox::RemoveAll(this: this->m_pSeverity);
    cb = this->m_pBugReporter->GetSeverityCount(this: this->m_pBugReporter);
    if ( cb > 0 )
    {
      do
      {
        v14 = this->m_pBugReporter->GetSeverity(this: this->m_pBugReporter, a2: v13);
        if ( V_strcasecmp(s1: v14, s2: "Zero") == 0 )
          defitemb = v13;
        this->m_pSeverity->AddItem_2(this: this->m_pSeverity, a2: v14, a3: nullptr);
        ++v13;
      }
      while ( v13 < cb );
    }
    this->m_pSeverity->ActivateItem(this: this->m_pSeverity, a2: defitemb);
    vgui::ComboBox::RemoveAll(this: this->m_pReportType);
    v15 = 0;
    cc = this->m_pBugReporter->GetReportTypeCount(this: this->m_pBugReporter);
    if ( cc > 0 )
    {
      do
      {
        v16 = this->m_pReportType->__vftable;
        v17 = ((int (__thiscall *)(IBugReporter *, int, _DWORD))this->m_pBugReporter->GetReportType)(
                a1: this->m_pBugReporter,
                a2: v15,
                a3: 0);
        ((void (__thiscall *)(vgui::ComboBox *, int))v16->AddItem_2)(a1: this->m_pReportType, a2: v17);
        ++v15;
      }
      while ( v15 < cc );
    }
    this->m_pReportType->ActivateItem(this: this->m_pReportType, a2: 0);
    vgui::ComboBox::RemoveAll(this: this->m_pPriority);
    v18 = 0;
    cd = this->m_pBugReporter->GetPriorityCount(this: this->m_pBugReporter);
    if ( cd > 0 )
    {
      do
      {
        v19 = this->m_pBugReporter->GetPriority(this: this->m_pBugReporter, a2: v18);
        if ( V_strcasecmp(s1: v19, s2: "None") == 0 )
          defitemb = v18;
        this->m_pPriority->AddItem_2(this: this->m_pPriority, a2: v19, a3: nullptr);
        ++v18;
      }
      while ( v18 < cd );
    }
    this->m_pPriority->ActivateItem(this: this->m_pPriority, a2: defitemb);
    vgui::ComboBox::RemoveAll(this: this->m_pGameArea);
    v20 = 0;
    ce = this->m_pBugReporter->GetAreaCount(this: this->m_pBugReporter);
    if ( ce > 0 )
    {
      do
      {
        v21 = this->m_pGameArea->__vftable;
        v22 = ((int (__thiscall *)(IBugReporter *, int, _DWORD))this->m_pBugReporter->GetArea)(
                a1: this->m_pBugReporter,
                a2: v20,
                a3: 0);
        ((void (__thiscall *)(vgui::ComboBox *, int))v21->AddItem_2)(a1: this->m_pGameArea, a2: v22);
        ++v20;
      }
      while ( v20 < ce );
    }
    Area = CBugUIPanel::GetArea(this);
    this->m_pGameArea->ActivateItem(this: this->m_pGameArea, a2: Area);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E300
// Name: public: virtual char const __near * CBugReporterDefaultUsername::GetDefaultUsername(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBugReporterDefaultUsername::GetDefaultUsername(CBugReporterDefaultUsername *this)
{
  char *result; // eax

  if ( (bugreporter_username.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = bugreporter_username.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013E330
// Name: protected: char const __near * CBugUIPanel::GetSubmitter(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBugUIPanel::GetSubmitter(CBugUIPanel *this)
{
  char *m_pszString; // esi
  CSteam3Client *v4; // eax
  CSteamID *v5; // eax
  char submitter[256]; // [esp+4h] [ebp-108h] BYREF
  char v7; // [esp+104h] [ebp-8h] BYREF
  Color clr; // [esp+108h] [ebp-4h] BYREF

  if ( !this->m_bCanSubmit )
    return (char *)defaultValue;
  if ( (bugreporter_username.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = bugreporter_username.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  if ( *m_pszString == 0 )
  {
    this->m_pSubmitter->GetText_2(this: this->m_pSubmitter, a2: submitter, a3: 256);
    m_pszString = (char *)this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: submitter);
    if ( *m_pszString == 0 )
    {
      if ( this->m_bIsPublic )
      {
        if ( Steam3Client()->m_pSteamUser != nullptr )
        {
          v4 = Steam3Client();
          v5 = v4->m_pSteamUser->GetSteamID(this: v4->m_pSteamUser, result: (CSteamID *)&v7);
          m_pszString = (char *)CSteamID::Render(this: v5);
        }
        else
        {
          m_pszString = "PublicUser";
        }
      }
      if ( *m_pszString == 0 )
      {
        clr = (Color)-13487361;
        ConColorMsg(
          a1: &clr,
          a2: "Can't determine username. Please set email address with bugreporter_username ConVar and run _bugreporter_restart autoselect\n");
      }
    }
  }
  return m_pszString;
}

//------------------------------------------------------------------------------
// Address: 0x1013E410
// Name: protected: void CBugUIPanel::SuccessSound(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::SuccessSound(CBugUIPanel *this, int bugId)
{
  bool v2; // zf
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v5; // [esp-8h] [ebp-Ch]
  Color clr; // [esp+0h] [ebp-4h] BYREF

  v2 = this->m_pBugReporter == nullptr;
  clr = (Color)-10158286;
  if ( v2
    || ((int (__thiscall *)(_DWORD, _DWORD))this->m_pBugReporter->IsPublicUI)(a1: this->m_pBugReporter, a2: clr) == 0 )
  {
    ConColorMsg(a1: &clr, a2: "Bug submission succeeded for bug (%i)\n", bugId);
  }
  else
  {
    ConColorMsg(a1: &clr, a2: "Bug submission succeeded\n");
  }
  v5 = va(format: "play %s\n", "common/bugreporter_succeeded");
  TraceType = CTraceFilter::GetTraceType(this: v3);
  Cbuf_AddText(eTarget: TraceType, pText: v5, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013E490
// Name: public: void CBugUIPanel::ParseCommands(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBugUIPanel::ParseCommands(CBugUIPanel *this@<ecx>, const char *a2@<edi>, const CCommand *args)
{
  int m_nArgc; // eax
  int v5; // edx
  int v6; // esi
  const char *v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char **v12; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  const char **v14; // [esp+Ch] [ebp-4h]

  if ( this->m_bCanSubmit )
  {
    m_nArgc = args->m_nArgc;
    v5 = 1;
    i = 1;
    if ( args->m_nArgc > 1 )
    {
      v6 = 2;
      v12 = &args->m_ppArgv[1];
      v14 = &args->m_ppArgv[2];
      while ( 1 )
      {
        v7 = v5 < 0 || v5 >= m_nArgc ? defaultValue : *v12;
        if ( _V_stricmp(s1: "-title", s2: v7) != 0 )
        {
          if ( _V_stricmp(s1: "-auto", s2: v7) != 0 )
          {
            if ( _V_stricmp(s1: "-remotebugpath", s2: v7) != 0 )
            {
              if ( CBugUIPanel::AutoFillToken(this, token: v7, partial: false) == 0
                && CBugUIPanel::AutoFillToken(this, token: v7, partial: true) == 0 )
              {
                _Msg(a1: "Unable to determine where to set default bug parameter '%s', ignoring...\n", v7);
              }
            }
            else if ( v6 < args->m_nArgc )
            {
              if ( v6 < 0 )
                v10 = defaultValue;
              else
                v10 = *v14;
              CUtlString::operator=(this: &this->m_strRemoteBugInfoPath, src: v10);
              ++i;
              ++v12;
              ++v14;
              this->m_bIsSubmittingRemoteBug = true;
              ++v6;
            }
          }
          else
          {
            this->m_bAutoSubmit = true;
          }
        }
        else if ( v6 < args->m_nArgc )
        {
          if ( v6 < 0 )
            v8 = defaultValue;
          else
            v8 = *v14;
          ((void (__thiscall *)(vgui::TextEntry *, const char *, const char *))this->m_pTitle->SetText)(
            a1: this->m_pTitle,
            a2: v8,
            a3: a2);
          if ( v6 < 0 || v6 >= args->m_nArgc )
            v9 = defaultValue;
          else
            v9 = *v14;
          a2 = v9;
          ((void (__thiscall *)(vgui::TextEntry *))this->m_pDescription->SetText)(a1: this->m_pDescription);
          ++i;
          ++v12;
          ++v14;
          ++v6;
        }
        ++v12;
        ++v14;
        m_nArgc = args->m_nArgc;
        ++v6;
        if ( ++i >= args->m_nArgc )
          break;
        v5 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E6F0
// Name: public: void CBugUIPanel::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::Init(CBugUIPanel *this@<ecx>, int Tall@<ebx>)
{
  IFileSystem_vtbl *v3; // edi
  const char *v4; // eax
  struct CSysModule *v5; // eax
  bool v6; // zf
  IFileSystem_vtbl *v7; // edi
  const char *v8; // eax
  int Wide; // edi
  int v10; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IBugReporter *v12; // eax
  const char *v13; // eax
  IBugReporter *m_pBugReporter; // ecx
  vgui::Label_vtbl *v15; // edi
  int v16; // eax
  char *v17; // eax
  const char *v18; // [esp-4h] [ebp-14h]
  const char *v19; // [esp-4h] [ebp-14h]
  Color clr; // [esp+Ch] [ebp-4h] BYREF

  clr = (Color)-39886;
  v3 = g_pFileSystem->IAppSystem::__vftable;
  v4 = CUtlString::operator char const *(this: &this->m_sDllName);
  v5 = v3->LoadModule(this: g_pFileSystem, a2: v4, a3: nullptr, a4: true);
  v6 = !this->m_bIsPublic;
  this->m_hBugReporter = v5;
  if ( !v6 )
  {
    v7 = g_pFileSystem->IAppSystem::__vftable;
    v8 = CUtlString::operator char const *(this: &this->m_sDllName);
    this->m_hBugReporter = v7->LoadModule(this: g_pFileSystem, a2: v8, a3: nullptr, a4: true);
    this->LoadControlSettings(this, a2: "Resource\\BugUIPanel_Public.res", a3: nullptr, a4: nullptr, a5: nullptr);
    Wide = vgui::Panel::GetWide(this);
    Tall = vgui::Panel::GetTall(this);
    v3 = (IFileSystem_vtbl *)((videomode->GetModeWidth(this: videomode) - Wide) / 2);
    v10 = videomode->GetModeHeight(this: videomode);
    vgui::Panel::SetPos(this, x: (int)v3, y: (v10 - Tall) / 2);
  }
  if ( this->m_hBugReporter != nullptr )
  {
    Factory = Sys_GetFactory(pModule: this->m_hBugReporter);
    if ( Factory != nullptr )
    {
      v12 = (IBugReporter *)Factory(a1: "BugReporter005", a2: nullptr);
      this->m_pBugReporter = v12;
      if ( v12 != nullptr )
      {
        if ( v12->Init(this: v12, a2: g_AppSystemFactory) )
        {
          *(_WORD *)&this->m_bCanSubmit = 257;
        }
        else
        {
          this->m_pBugReporter = nullptr;
          ConColorMsg(a1: &clr, a2: "m_pBugReporter->Init() failed\n");
        }
      }
      else
      {
        v13 = CUtlString::operator char const *(this: &this->m_sDllName);
        ConColorMsg(a1: &clr, a2: "Couldn't get interface '%s' from '%s'\n", "BugReporter005", v13);
      }
    }
    else
    {
      v18 = CUtlString::operator char const *(this: &this->m_sDllName);
      ConColorMsg(a1: &clr, a2: "Couldn't get factory '%s'\n", v18);
    }
  }
  else
  {
    v19 = CUtlString::operator char const *(this: &this->m_sDllName);
    ConColorMsg(a1: &clr, a2: "Couldn't load '%s'\n", v19);
  }
  if ( this->m_bCanSubmit )
    CBugUIPanel::PopulateControls(this, a2: Tall, a3: (int)v3);
  m_pBugReporter = this->m_pBugReporter;
  if ( m_pBugReporter != nullptr && m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
  {
    this->m_pSaveBSP->SetVisible(this: this->m_pSaveBSP, a2: false);
    this->m_pBSPURL->SetVisible(this: this->m_pBSPURL, a2: false);
    this->m_pChooseVMFFolder->SetVisible(this: this->m_pChooseVMFFolder, a2: false);
    this->m_pSaveVMF->SetVisible(this: this->m_pSaveVMF, a2: false);
    this->m_pVMFURL->SetVisible(this: this->m_pVMFURL, a2: false);
    this->m_pIncludeFile->SetVisible(this: this->m_pIncludeFile, a2: false);
    this->m_pClearIncludes->SetVisible(this: this->m_pClearIncludes, a2: false);
    this->m_pAssignTo->SetVisible(this: this->m_pAssignTo, a2: false);
    this->m_pSeverity->SetVisible(this: this->m_pSeverity, a2: false);
    this->m_pPriority->SetVisible(this: this->m_pPriority, a2: false);
    this->m_pGameArea->SetVisible(this: this->m_pGameArea, a2: false);
    this->m_pMapNumber->SetVisible(this: this->m_pMapNumber, a2: false);
    this->m_pIncludedFiles->SetVisible(this: this->m_pIncludedFiles, a2: false);
    this->m_pSubmitter->SetVisible(this: this->m_pSubmitter, a2: true);
    this->m_pSubmitterLabel->SetVisible(this: this->m_pSubmitterLabel, a2: false);
    this->m_bQueryingSteamForCSER = true;
  }
  else
  {
    this->m_pEmail->SetVisible(this: this->m_pEmail, a2: false);
    this->m_pSubmitterLabel->SetVisible(this: this->m_pSubmitterLabel, a2: true);
    this->m_pSubmitter->SetVisible(this: this->m_pSubmitter, a2: true);
  }
  V_snprintf(pDest: this->m_szVMFContentDirFullpath, maxLen: 260, pFormat: "%s/maps", com_gamedir);
  _V_strlower(start: this->m_szVMFContentDirFullpath);
  V_FixSlashes(pname: this->m_szVMFContentDirFullpath, separator: 92);
  v15 = this->m_pBuildNumber->__vftable;
  v16 = build_number();
  v17 = va(format: "%d", v16);
  v15->SetText(this: this->m_pBuildNumber, a2: v17);
}

//------------------------------------------------------------------------------
// Address: 0x1013EA60
// Name: protected: void CBugUIPanel::TakeSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::TakeSnapshot(CBugUIPanel *this)
{
  char *m_szScreenShotName; // edi
  char *Submitter; // eax
  IBugReporter *m_pBugReporter; // ecx
  int v5; // ebx
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  int v8; // eax
  char *v9; // [esp-8h] [ebp-14h]
  const char *v10; // [esp-8h] [ebp-14h]

  m_szScreenShotName = this->m_szScreenShotName;
  v9 = this->m_szScreenShotName;
  this->m_nSnapShotFrame = host_framecount;
  this->m_bTakingSnapshot = true;
  Submitter = CBugUIPanel::GetSubmitter(this);
  CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: v9, bufsize: 256);
  m_pBugReporter = this->m_pBugReporter;
  v5 = 100;
  if ( m_pBugReporter != nullptr && m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
    v5 = 40;
  v10 = va(format: "jpeg \"%s\" %i\n", m_szScreenShotName, v5);
  TraceType = CTraceFilter::GetTraceType(this: v6);
  Cbuf_AddText(eTarget: TraceType, pText: v10, nTickDelay: 0);
  v8 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-remotebug", a3: 0) == 0 )
    Cbuf_AddText(
      eTarget: sv.m_State < ss_active ? CBUF_FIRST_PLAYER : CBUF_SERVER,
      pText: "cmd bugpause\n",
      nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013EB10
// Name: protected: void CBugUIPanel::OnSaveGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnSaveGame(CBugUIPanel *this)
{
  char *m_szSaveGameName; // edi
  char *Submitter; // eax
  char *v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  char *v7; // [esp-8h] [ebp-10h]
  const char *v8; // [esp-8h] [ebp-10h]

  m_szSaveGameName = this->m_szSaveGameName;
  v7 = this->m_szSaveGameName;
  Submitter = CBugUIPanel::GetSubmitter(this);
  CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: v7, bufsize: 256);
  if ( this->m_pBugReporter != nullptr && this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
    v4 = va(format: "minisave %s\n", m_szSaveGameName);
  else
    v4 = va(format: "save %s.sav notmostrecent copymap\n", m_szSaveGameName);
  v8 = v4;
  TraceType = CTraceFilter::GetTraceType(this: v5);
  Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
  this->m_pSaveGameURL->SetText(this: this->m_pSaveGameURL, a2: m_szSaveGameName);
}

//------------------------------------------------------------------------------
// Address: 0x1013EB90
// Name: protected: void CBugUIPanel::OnSaveBSP(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnSaveBSP(CBugUIPanel *this)
{
  char *m_szBSPName; // edi
  char *Submitter; // eax
  char *v4; // [esp-8h] [ebp-10h]

  m_szBSPName = this->m_szBSPName;
  v4 = this->m_szBSPName;
  Submitter = CBugUIPanel::GetSubmitter(this);
  CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: v4, bufsize: 256);
  this->m_pBSPURL->SetText(this: this->m_pBSPURL, a2: m_szBSPName);
}

//------------------------------------------------------------------------------
// Address: 0x1013EBD0
// Name: protected: void CBugUIPanel::OnSaveVMF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnSaveVMF(CBugUIPanel *this)
{
  IBugReporter *m_pBugReporter; // ecx
  vgui::DirectorySelectDialog *v3; // eax
  CDragDropHelperPanel *v4; // eax
  vgui::DirectorySelectDialog *v5; // eax
  vgui::Panel *v6; // eax
  char *Submitter; // eax
  char localfile[512]; // [esp+4h] [ebp-300h] BYREF
  char level[256]; // [esp+204h] [ebp-100h] BYREF

  m_pBugReporter = this->m_pBugReporter;
  if ( m_pBugReporter == nullptr || !m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
  {
    this->m_pLevelName->GetText(this: this->m_pLevelName, a2: level, a3: 256);
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/%s.vmf", this->m_szVMFContentDirFullpath, level);
    if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: localfile, a3: nullptr) )
    {
      Submitter = CBugUIPanel::GetSubmitter(this);
      CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: this->m_szVMFName, bufsize: 256);
      this->m_pVMFURL->SetText(this: this->m_pVMFURL, a2: this->m_szVMFName);
    }
    else
    {
      if ( vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog) == nullptr )
      {
        v3 = (vgui::DirectorySelectDialog *)MemAlloc_Alloc(nSize: 0x47Cu);
        if ( v3 != nullptr )
          v4 = (CDragDropHelperPanel *)vgui::DirectorySelectDialog::DirectorySelectDialog(
                                         this: v3,
                                         parent: this,
                                         title: "Choose .vmf folder");
        else
          v4 = nullptr;
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(
          this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDirectorySelectDialog,
          pPanel: v4);
      }
      this->m_bAddVMF = true;
      v5 = (vgui::DirectorySelectDialog *)vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog);
      vgui::DirectorySelectDialog::SetStartDirectory(this: v5, path: this->m_szVMFContentDirFullpath);
      v6 = vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog);
      v6->__vftable[1].IsEnabled(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013ED00
// Name: protected: virtual void CBugUIPanel::OnDirectorySelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnDirectorySelected(CBugUIPanel *this, const char *dir)
{
  char *m_szVMFContentDirFullpath; // edi
  vgui::Panel *v4; // eax
  const char *Submitter; // eax

  m_szVMFContentDirFullpath = this->m_szVMFContentDirFullpath;
  V_strncpy(pDest: this->m_szVMFContentDirFullpath, pSrc: dir, maxLen: 260);
  _V_strlower(start: m_szVMFContentDirFullpath);
  V_FixSlashes(pname: m_szVMFContentDirFullpath, separator: 92);
  V_StripTrailingSlash(ppath: m_szVMFContentDirFullpath);
  if ( vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog);
    v4->MarkForDeletion(this: v4);
  }
  if ( this->m_bAddVMF )
  {
    Submitter = CBugUIPanel::GetSubmitter(this);
    CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: this->m_szVMFName, bufsize: 256);
    this->m_pVMFURL->SetText(this: this->m_pVMFURL, a2: this->m_szVMFName);
  }
  this->m_bAddVMF = false;
}

//------------------------------------------------------------------------------
// Address: 0x1013EDA0
// Name: public: virtual void CBugUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::Activate(CBugUIPanel *this@<ecx>, int a2@<edi>)
{
  int Area; // edi
  IClientEntityList_vtbl *v4; // edi
  CClientState *BaseLocalClient; // eax
  int v6; // eax
  vgui::Label_vtbl *v7; // edi
  char *v8; // eax
  vgui::Label_vtbl *v9; // edi
  char *v10; // eax
  vgui::Label_vtbl *v11; // edi
  CClientState *v12; // eax
  vgui::Button_vtbl *v13; // edi
  CClientState *v14; // eax
  vgui::CTreeViewListControl *v15; // ecx
  ECommandTarget_t TraceType; // eax
  QAngle angles; // [esp+24h] [ebp-18h] BYREF
  Vector v18; // [esp+30h] [ebp-Ch]

  if ( !this->m_bValidated )
  {
    this->m_bValidated = true;
    CBugUIPanel::Init(this);
    CBugUIPanel::DetermineSubmitterName(this);
  }
  if ( ((int (__thiscall *)(vgui::ComboBox *, int))this->m_pGameArea->GetItemCount)(a1: this->m_pGameArea, a2) != 0 )
  {
    Area = CBugUIPanel::GetArea(this);
    if ( Area != 0 )
    {
      if ( vgui::ComboBox::GetActiveItem(this: this->m_pGameArea) == Area )
        ((void (__stdcall *)(vgui::ComboBox *))this->OnChooseArea)(a1: this->m_pGameArea);
      else
        ((void (__stdcall *)(int))this->m_pGameArea->ActivateItem)(a1: Area);
    }
  }
  if ( GetBaseLocalClient()->m_nSignonState == 6 )
  {
    v18 = g_MainViewOrigin[0];
    VectorAngles(forward: g_MainViewForward, &angles);
    v4 = entitylist->__vftable;
    BaseLocalClient = GetBaseLocalClient();
    v6 = (int)v4->GetClientEntity(this: entitylist, a2: BaseLocalClient->m_nPlayerSlot + 1);
    if ( v6 != 0 )
      v18 = *(Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 40))(a1: v6);
    v7 = this->m_pPosition->__vftable;
    v8 = va(format: "%f %f %f", v18.x, v18.y, v18.z);
    v7->SetText(this: this->m_pPosition, a2: v8);
    v9 = this->m_pOrientation->__vftable;
    v10 = va(format: "%f %f %f", angles.x, angles.y, angles.z);
    v9->SetText(this: this->m_pOrientation, a2: v10);
    v11 = this->m_pLevelName->__vftable;
    v12 = GetBaseLocalClient();
    v11->SetText(this: this->m_pLevelName, a2: v12->m_szLevelNameShort);
    v13 = this->m_pSaveGame->__vftable;
    v14 = GetBaseLocalClient();
    v13->SetEnabled(this: this->m_pSaveGame, a2: v14->m_nMaxClients == 1);
    this->m_pSaveBSP->SetEnabled(this: this->m_pSaveBSP, a2: true);
    this->m_pSaveVMF->SetEnabled(this: this->m_pSaveVMF, a2: true);
    this->m_pChooseVMFFolder->SetEnabled(this: this->m_pChooseVMFFolder, a2: true);
  }
  else
  {
    this->m_pPosition->SetText(this: this->m_pPosition, a2: "console");
    this->m_pOrientation->SetText(this: this->m_pOrientation, a2: "console");
    this->m_pLevelName->SetText(this: this->m_pLevelName, a2: "console");
    this->m_pSaveGame->SetEnabled(this: this->m_pSaveGame, a2: false);
    this->m_pSaveBSP->SetEnabled(this: this->m_pSaveBSP, a2: false);
    this->m_pSaveVMF->SetEnabled(this: this->m_pSaveVMF, a2: false);
    this->m_pChooseVMFFolder->SetEnabled(this: this->m_pChooseVMFFolder, a2: false);
  }
  vgui::Frame::Activate(this);
  this->m_pTitle->RequestFocus(this: this->m_pTitle, a2: 0);
  vgui::TextEntry::SelectAllText(this: this->m_pTitle, bResetCursorPos: true);
  if ( this->m_szScreenShotName[0] == 0 )
  {
    if ( this->m_bIsPublic )
    {
      if ( this->m_fAutoAddScreenshot == 1 )
        goto LABEL_18;
    }
    else if ( this->m_fAutoAddScreenshot != 2 )
    {
LABEL_18:
      CBugUIPanel::OnTakeSnapshot(this);
    }
  }
  _Msg(a1: "BUG REPORT PORTAL POSITIONS:\n");
  TraceType = CTraceFilter::GetTraceType(this: v15);
  Cbuf_AddText(eTarget: TraceType, pText: "portal_report\n", nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013F170
// Name: public: void CBugUIPanel::ParseDefaultParams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::ParseDefaultParams(CBugUIPanel *this)
{
  const char *i; // esi
  char token[256]; // [esp+4h] [ebp-130h] BYREF
  CUtlBuffer buffer; // [esp+104h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 1);
  if ( g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: "scripts/bugreporter_defaults.txt",
         a3: nullptr,
         a4: &buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    for ( i = COM_ParseFile(data: (const char *)buffer.m_Memory.m_pMemory, token, maxtoken: 256);
          i != nullptr;
          i = COM_ParseFile(data: i, token, maxtoken: 256) )
    {
      if ( CBugUIPanel::AutoFillToken(this, token, partial: false) == 0
        && CBugUIPanel::AutoFillToken(this, token, partial: true) == 0 )
      {
        _Msg(a1: "Unable to determine where to set default bug parameter '%s', ignoring...\n", token);
      }
    }
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1013F250
// Name: protected: bool CBugUIPanel::CopyInfoFromRemoteBug(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CBugUIPanel::CopyInfoFromRemoteBug@<al>(CBugUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  CUtlString *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *String; // ebx
  IBugReporter_vtbl *v11; // ebx
  const char *v12; // eax
  IBugReporter_vtbl *v13; // ebx
  const char *v14; // eax
  IBugReporter_vtbl *v15; // ebx
  const char *v16; // eax
  IBugReporter_vtbl *v17; // ebx
  const char *v18; // eax
  IBugReporter_vtbl *v19; // ebx
  const char *v20; // eax
  IBugReporter_vtbl *v21; // ebx
  const char *v22; // eax
  const char *v23; // eax
  CUtlString *v24; // eax
  const char *v25; // eax
  CUtlString *v26; // eax
  CUtlString *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  CUtlString *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  char localBugConsole[260]; // [esp+4h] [ebp-260h] BYREF
  char buffer[260]; // [esp+108h] [ebp-15Ch] BYREF
  CUtlString strBugConsolePath; // [esp+20Ch] [ebp-58h] BYREF
  CUtlString v39; // [esp+21Ch] [ebp-48h] BYREF
  CUtlString strSSName; // [esp+22Ch] [ebp-38h] BYREF
  CUtlString v41; // [esp+23Ch] [ebp-28h] BYREF
  CUtlString strSSPath; // [esp+24Ch] [ebp-18h] BYREF
  IBaseFileSystem *filesystem; // [esp+25Ch] [ebp-8h]
  bool v44; // [esp+263h] [ebp-1h]

  if ( this->m_pBugReporter == nullptr || !this->m_bIsSubmittingRemoteBug )
    return 0;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "Bug");
  else
    v6 = nullptr;
  if ( g_pFileSystem != nullptr )
    filesystem = &g_pFileSystem->IBaseFileSystem;
  else
    filesystem = nullptr;
  v7 = CUtlString::operator+(this: &this->m_strRemoteBugInfoPath, result: &strSSPath, pOther: "\\bug.txt");
  v8 = CUtlString::operator char const *(this: v7);
  v44 = !KeyValues::LoadFromFile(
           this: v6,
           filesystem,
           resourceName: v8,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr);
  strSSPath.m_Storage.m_nActualLength = 0;
  if ( strSSPath.m_Storage.m_Memory.m_nGrowSize >= 0 && strSSPath.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: strSSPath.m_Storage.m_Memory.m_pMemory);
  if ( v44 )
  {
    v9 = CUtlString::Get(this: &this->m_strRemoteBugInfoPath);
    _Warning(a1: "Failed to parse remote bug KV file at path: '%s'", v9);
    KeyValues::deleteThis(this: v6);
    return 0;
  }
  else
  {
    String = KeyValues::GetString(this: v6, keyName: "level", defaultValue: defaultValue);
    ((void (__thiscall *)(IBugReporter *, const char *, int))this->m_pBugReporter->SetLevel)(
      a1: this->m_pBugReporter,
      a2: String,
      a3: a2);
    V_strncpy(pDest: this->m_szLevel, pSrc: String, maxLen: 256);
    v11 = this->m_pBugReporter->__vftable;
    v12 = KeyValues::GetString(this: v6, keyName: "Build", defaultValue: defaultValue);
    v11->SetBuildNumber(this: this->m_pBugReporter, a2: v12);
    v13 = this->m_pBugReporter->__vftable;
    v14 = KeyValues::GetString(this: v6, keyName: "Position", defaultValue: defaultValue);
    v13->SetPosition(this: this->m_pBugReporter, a2: v14);
    v15 = this->m_pBugReporter->__vftable;
    v16 = KeyValues::GetString(this: v6, keyName: "Orientation", defaultValue: defaultValue);
    v15->SetOrientation(this: this->m_pBugReporter, a2: v16);
    v17 = this->m_pBugReporter->__vftable;
    v18 = KeyValues::GetString(this: v6, keyName: "Misc", defaultValue: defaultValue);
    v17->SetMiscInfo(this: this->m_pBugReporter, a2: v18);
    v19 = this->m_pBugReporter->__vftable;
    v20 = KeyValues::GetString(this: v6, keyName: "Console", defaultValue: defaultValue);
    v19->SetConsoleHistory(this: this->m_pBugReporter, a2: v20);
    v21 = this->m_pBugReporter->__vftable;
    v22 = KeyValues::GetString(this: v6, keyName: "DriverInfo", defaultValue: defaultValue);
    v21->SetDriverInfo(this: this->m_pBugReporter, a2: v22);
    v23 = KeyValues::GetString(this: v6, keyName: "Screenshot", defaultValue: defaultValue);
    CUtlString::CUtlString(this: &strSSName, pString: v23);
    if ( CUtlString::Length(this: &strSSName) != 0 )
    {
      v24 = CUtlString::UnqualifiedFilename(this: &strSSName, result: &v39);
      v25 = CUtlString::operator char const *(this: v24);
      V_StripExtension(in: v25, out: this->m_szScreenShotName, outSize: 256);
      CUtlString::~CUtlString(this: &v39);
      V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s/screenshots/%s.jpg", com_gamedir, this->m_szScreenShotName);
      v26 = CUtlString::operator+(this: &this->m_strRemoteBugInfoPath, result: &v41, pOther: "\\");
      v27 = CUtlString::operator+(this: v26, result: &v39, pOther: this->m_szScreenShotName);
      CUtlString::operator+(this: v27, result: &strSSPath, pOther: ".jpg");
      CUtlString::~CUtlString(this: &v39);
      CUtlString::~CUtlString(this: &v41);
      v28 = CUtlString::operator char const *(this: &strSSPath);
      CBugUIPanel::UploadFile(this, local: v28, remote: buffer, bDeleteLocal: true);
      v29 = (const char *)((int (__thiscall *)(IBugReporter *, int))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: a3);
      if ( v29 == nullptr )
        v29 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s/BugId/%s.jpg", v29, this->m_szScreenShotName);
      V_FixSlashes(pname: buffer, separator: 92);
      this->m_pBugReporter->SetScreenShot(this: this->m_pBugReporter, a2: buffer);
      CUtlString::~CUtlString(this: &strSSPath);
    }
    V_snprintf(pDest: localBugConsole, maxLen: 260, pFormat: "%s/bugconsole.txt", com_gamedir);
    CUtlString::operator+(this: &this->m_strRemoteBugInfoPath, result: &strBugConsolePath, pOther: "\\bugconsole.txt");
    v30 = CUtlString::operator char const *(this: &strBugConsolePath);
    CBugUIPanel::UploadFile(this, local: v30, remote: localBugConsole, bDeleteLocal: true);
    this->OnFileSelected(this, a2: localBugConsole);
    KeyValues::deleteThis(this: v6);
    v31 = CUtlString::operator+(this: &this->m_strRemoteBugInfoPath, result: &v41, pOther: "\\bug.txt");
    v32 = CUtlString::operator char const *(this: v31);
    unlink(path: v32);
    CUtlString::~CUtlString(this: &v41);
    v33 = CUtlString::operator char const *(this: &this->m_strRemoteBugInfoPath);
    _rmdir(path: v33);
    CUtlString::~CUtlString(this: &strBugConsolePath);
    CUtlString::~CUtlString(this: &strSSName);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F650
// Name: bug
// Source: json
//------------------------------------------------------------------------------
void __usercall bug(const char *a1@<edi>, const CCommand *args)
{
  int v2; // eax

  if ( g_pBugUI != nullptr )
  {
    if ( g_pBugUI->IsVisible(this: g_pBugUI) )
      g_pBugUI->Close(this: g_pBugUI);
    g_pBugUI->Activate(this: g_pBugUI);
    CBugUIPanel::ParseDefaultParams(this: g_pBugUI);
    CBugUIPanel::ParseCommands(this: g_pBugUI, a2: a1, args);
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-remotebug", a3: 0) != 0 )
      g_pBugUI->m_bAutoSubmit = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F6D0
// Name: protected: void CBugUIPanel::GetConsoleHistory(class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::GetConsoleHistory(CBugUIPanel *this, CUtlBuffer *buf)
{
  int m_Put; // edi
  int v3; // eax

  if ( g_pCVar->GetConsoleDisplayFuncCount(this: g_pCVar) > 0 )
  {
    m_Put = buf->m_Put;
    CUtlBuffer::EnsureCapacity(this: buf, num: m_Put + 0x100000);
    ((void (__stdcall *)(_DWORD, unsigned __int8 *, int))g_pCVar->GetConsoleText)(
      a1: 0,
      a2: &buf->m_Memory.m_pMemory[m_Put],
      a3: 0x100000);
    v3 = _V_strlen(str: (const char *)&buf->m_Memory.m_pMemory[m_Put]);
    CUtlBuffer::SeekPut(this: buf, type: SEEK_HEAD, offset: m_Put + v3 + 1);
  }
  else
  {
    CUtlBuffer::PutChar(this: buf, c: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F8D0
// Name: protected: void CBugUIPanel::OnClearIncludedFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnClearIncludedFiles(CBugUIPanel *this)
{
  bool v2; // sf

  v2 = this->m_IncludedFiles.m_Memory.m_nGrowSize < 0;
  this->m_IncludedFiles.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_IncludedFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_IncludedFiles.m_Memory.m_pMemory);
      this->m_IncludedFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_IncludedFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_IncludedFiles.m_pElements = this->m_IncludedFiles.m_Memory.m_pMemory;
  this->m_pIncludedFiles->SetText(this: this->m_pIncludedFiles, a2: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x1013F940
// Name: protected: void CBugUIPanel::WipeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::WipeData(CBugUIPanel *this)
{
  vgui::Label *m_pScreenShotURL; // ecx
  vgui::Label *m_pSaveGameURL; // ecx
  vgui::Label *m_pBSPURL; // ecx
  vgui::Label *m_pVMFURL; // ecx

  m_pScreenShotURL = this->m_pScreenShotURL;
  *(_WORD *)&this->m_fAutoAddScreenshot = 0;
  m_pScreenShotURL->SetText(this: m_pScreenShotURL, a2: "Screenshot file");
  m_pSaveGameURL = this->m_pSaveGameURL;
  this->m_szSaveGameName[0] = 0;
  m_pSaveGameURL->SetText(this: m_pSaveGameURL, a2: "Save game file");
  m_pBSPURL = this->m_pBSPURL;
  this->m_szBSPName[0] = 0;
  m_pBSPURL->SetText(this: m_pBSPURL, a2: ".bsp file");
  m_pVMFURL = this->m_pVMFURL;
  this->m_szVMFName[0] = 0;
  m_pVMFURL->SetText(this: m_pVMFURL, a2: ".vmf file");
  this->m_IncludedFiles.m_Size = 0;
  if ( this->m_IncludedFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_IncludedFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_IncludedFiles.m_Memory.m_pMemory);
      this->m_IncludedFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_IncludedFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_IncludedFiles.m_pElements = this->m_IncludedFiles.m_Memory.m_pMemory;
  this->m_pIncludedFiles->SetText(this: this->m_pIncludedFiles, a2: defaultValue);
  this->m_pDescription->SetText(this: this->m_pDescription, a2: defaultValue);
  this->m_pEmail->SetText(this: this->m_pEmail, a2: defaultValue);
  this->m_bIsSubmittingRemoteBug = false;
  CUtlString::Clear(this: &this->m_strRemoteBugInfoPath);
}

//------------------------------------------------------------------------------
// Address: 0x1013FA50
// Name: public: virtual void CBugUIPanel::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::Close(CBugUIPanel *this)
{
  int v2; // eax
  bool (__thiscall *HideGameUI)(IEngineVGuiInternal *); // kr00_4

  CBugUIPanel::WipeData(this);
  vgui::Frame::Close(this);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-remotebug", a3: 0) == 0 )
    Cbuf_AddText(
      eTarget: sv.m_State < ss_active ? CBUF_FIRST_PLAYER : CBUF_SERVER,
      pText: "cmd bugunpause\n",
      nTickDelay: 0);
  HideGameUI = EngineVGui()->HideGameUI;
  __asm { jmp     eax }
}

//------------------------------------------------------------------------------
// Address: 0x1013FAB0
// Name: protected: void CBugUIPanel::OnClearForm(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnClearForm(CBugUIPanel *this)
{
  CBugUIPanel::WipeData(this);
  this->m_pTitle->SetText(this: this->m_pTitle, a2: defaultValue);
  this->m_pDescription->SetText(this: this->m_pDescription, a2: defaultValue);
  this->m_pAssignTo->ActivateItem(this: this->m_pAssignTo, a2: 0);
  this->m_pSeverity->ActivateItem(this: this->m_pSeverity, a2: 0);
  this->m_pReportType->ActivateItem(this: this->m_pReportType, a2: 0);
  this->m_pPriority->ActivateItem(this: this->m_pPriority, a2: 2);
  this->m_pGameArea->ActivateItem(this: this->m_pGameArea, a2: 0);
  this->m_pMapNumber->ActivateItem(this: this->m_pMapNumber, a2: 0);
  this->m_pSubmitter->ActivateItem(this: this->m_pSubmitter, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013FB70
// Name: public: virtual void CBugUIPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnKeyCodeTyped(CBugUIPanel *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
  {
    this->Close(this);
    CBugUIPanel::WipeData(this);
  }
  else
  {
    vgui::Frame::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FC20
// Name: struct ThreadHandle_t__ __near * ThreadExecuteSolo<class CCallQueue __near *,void (CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::*)(void)>(char const __near *,class CCallQueue __near *,void (CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::*)(void))
// Source: json
//------------------------------------------------------------------------------
ThreadHandle_t__ *__cdecl ThreadExecuteSolo<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void)>(
        const char *pszName,
        CCallQueue *a1,
        __int128 a2)
{
  _DWORD *v3; // eax
  int SimpleThread; // esi

  v3 = MemAlloc_Alloc(nSize: 0x28u);
  if ( v3 != nullptr )
  {
    v3[3] = 1;
    *v3 = &CMemberFunctor0<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v3[2] = &CMemberFunctor0<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *((_OWORD *)v3 + 1) = a2;
    v3[8] = a1;
  }
  else
  {
    v3 = nullptr;
  }
  SimpleThread = _CreateSimpleThread(a1: FunctorExecuteThread, a2: v3, a3: 0);
  if ( pszName != nullptr )
    _ThreadSetDebugName(a1: SimpleThread, a2: pszName);
  return (ThreadHandle_t__ *)SimpleThread;
}

//------------------------------------------------------------------------------
// Address: 0x1013FDF0
// Name: public: static void CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FE90
// Name: public: static void CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar'::`2'::bAdded )
  {
    `CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "DirectorySelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "dir";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FF30
// Name: public: static void CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar'::`2'::bAdded )
  {
    `CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "OnChooseVMFFolder";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FFC0
// Name: public: static void CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar'::`2'::bAdded )
  {
    `CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::TextEntry::`vcall'{1136,{flat}};
    memset(&v3.m[1][1], 0, 12);
    *(_QWORD *)&v3.m[2][0] = 0x400000001LL;
    LODWORD(v3.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140060
// Name: public: CBugUIPanel::CBugUIPanel(bool,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBugUIPanel *__thiscall CBugUIPanel::CBugUIPanel(CBugUIPanel *this, bool bIsPublic, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  const char *InternalBugReporterDLL; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::Label *v14; // eax
  vgui::Label *v15; // eax
  vgui::Label *v16; // eax
  vgui::Label *v17; // eax
  vgui::Label *v18; // eax
  vgui::Label *v19; // eax
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label *v22; // eax
  vgui::Label *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::TextEntry *v25; // eax
  vgui::Button *v26; // eax
  vgui::Button *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  vgui::Button *v30; // eax
  vgui::Button *v31; // eax
  vgui::Button *v32; // eax
  vgui::Button *v33; // eax
  vgui::Button *v34; // eax
  vgui::Button *v35; // eax
  vgui::Button *v36; // eax
  vgui::Button *v37; // eax
  vgui::Button *v38; // eax
  vgui::Button *v39; // eax
  vgui::Label *v40; // eax
  vgui::Label *v41; // eax
  vgui::Label *v42; // eax
  vgui::Label *v43; // eax
  vgui::Label *v44; // eax
  vgui::Label *v45; // eax
  vgui::Label *v46; // eax
  vgui::Label *v47; // eax
  vgui::ComboBox *v48; // eax
  vgui::ComboBox *v49; // eax
  vgui::ComboBox *v50; // eax
  vgui::ComboBox *v51; // eax
  vgui::ComboBox *v52; // eax
  vgui::ComboBox *v53; // eax
  vgui::ComboBox *v54; // eax
  vgui::ComboBox *v55; // eax
  vgui::ComboBox *v56; // eax
  vgui::ComboBox *v57; // eax
  vgui::ComboBox *v58; // eax
  vgui::ComboBox *v59; // eax
  vgui::ComboBox *v60; // eax
  vgui::ComboBox *v61; // eax
  vgui::Button *v62; // eax
  vgui::Button *v63; // eax
  vgui::Button *v64; // eax
  vgui::Button *v65; // eax
  vgui::Button *v66; // eax
  vgui::Button *v67; // eax
  KeyValues *v68; // eax
  KeyValues *v69; // eax
  int Wide; // edi
  int v71; // edi
  int h; // [esp+14h] [ebp+8h]
  int ha; // [esp+14h] [ebp+8h]

  vgui::Frame::Frame(this, parent, panelName: "BugUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBugUIPanel_vtbl *)&CBugUIPanel::`vftable';
  if ( `CBugUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBugUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    v4->pfnClassName = CBugUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBugUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBugUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBugUIPanel");
    v5->pfnClassName = CBugUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBugUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBugUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBugUIPanel");
    v6->pfnClassName = CBugUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar();
  CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar();
  CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar();
  CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar();
  this->m_IncludedFiles.m_Memory.m_pMemory = nullptr;
  this->m_IncludedFiles.m_Memory.m_nAllocationCount = 0;
  this->m_IncludedFiles.m_Memory.m_nGrowSize = 0;
  this->m_IncludedFiles.m_Size = 0;
  this->m_IncludedFiles.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_strRemoteBugInfoPath);
  this->m_hFileOpenDialog.m_iPanelID = -1;
  this->m_hDirectorySelectDialog.m_iPanelID = -1;
  this->m_bAddVMF = false;
  this->m_hFinishedDialog.m_iPanelID = -1;
  netadr_s::SetIP(this: &this->m_cserIP, unIP: 0);
  netadr_s::SetPort(this: &this->m_cserIP, newport: 0);
  netadr_s::SetType(this: &this->m_cserIP, newtype: NA_IP);
  this->m_bIsPublic = bIsPublic;
  CUtlString::CUtlString(this: &this->m_sDllName);
  this->m_BugSub = 0;
  if ( this->m_bIsPublic )
    InternalBugReporterDLL = "bugreporter_public";
  else
    InternalBugReporterDLL = GetInternalBugReporterDLL();
  CUtlString::operator=(this: &this->m_sDllName, src: InternalBugReporterDLL);
  this->m_hZip = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDirectorySelectDialog,
    pPanel: nullptr);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
    pPanel: nullptr);
  this->m_pBugReporter = nullptr;
  this->m_hBugReporter = nullptr;
  this->m_bQueryingSteamForCSER = false;
  *(_DWORD *)&this->m_SteamID.m_SteamInstanceID = 0;
  *((_DWORD *)&this->m_SteamID.m_SteamInstanceID + 1) = 0;
  this->m_SteamID.m_SteamLocalUserID.Split.Low32bits = 0;
  this->m_SteamID.m_SteamLocalUserID.Split.High32bits = 0;
  NET_StringToAdr(s: "67.132.200.140:27013", a: &this->m_cserIP);
  this->m_bValidated = false;
  this->m_szScreenShotName[0] = 0;
  this->m_szSaveGameName[0] = 0;
  this->m_szBSPName[0] = 0;
  this->m_szVMFName[0] = 0;
  this->m_szLevel[0] = 0;
  this->m_szVMFContentDirFullpath[0] = 0;
  this->m_IncludedFiles.m_Size = 0;
  if ( this->m_IncludedFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_IncludedFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_IncludedFiles.m_Memory.m_pMemory);
      this->m_IncludedFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_IncludedFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_IncludedFiles.m_pElements = this->m_IncludedFiles.m_Memory.m_pMemory;
  this->m_nSnapShotFrame = -1;
  *(_WORD *)&this->m_bTakingSnapshot = 0;
  *(_WORD *)&this->m_bAutoSubmit = 0;
  this->m_bIsSubmittingRemoteBug = false;
  *(_WORD *)&this->m_bCanSubmit = 0;
  this->m_bCanSeeRepository = false;
  this->m_pProgressDialog = nullptr;
  this->m_flPauseTime = 0.0;
  this->m_bWaitForFinish = false;
  *(_WORD *)&this->m_bUseNameForSubmitter = 0;
  vgui::Frame::SetTitle(this, title: "Bug Reporter", surfaceTitle: true);
  v8 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: "BugTitle");
  else
    v9 = nullptr;
  this->m_pTitle = v9;
  v9->SetMaximumCharCount(this: v9, a2: 60);
  v10 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v10 != nullptr )
    v11 = vgui::TextEntry::TextEntry(this: v10, parent: this, panelName: "BugDescription");
  else
    v11 = nullptr;
  this->m_pDescription = v11;
  v11->SetMultiline(this: v11, a2: true);
  this->m_pDescription->SetCatchEnterKey(this: this->m_pDescription, a2: true);
  this->m_pDescription->SetVerticalScrollbar(this: this->m_pDescription, a2: true);
  v12 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v12 != nullptr )
    v13 = vgui::TextEntry::TextEntry(this: v12, parent: this, panelName: "BugEmail");
  else
    v13 = nullptr;
  this->m_pEmail = v13;
  v13->SetMaximumCharCount(this: v13, a2: 80);
  v14 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v14 != nullptr )
    v15 = vgui::Label::Label(this: v14, parent: this, panelName: "BugSubmitterLabel", text: "Submitter:");
  else
    v15 = nullptr;
  this->m_pSubmitterLabel = v15;
  v16 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v16 != nullptr )
    v17 = vgui::Label::Label(this: v16, parent: this, panelName: "BugScreenShotURL", text: defaultValue);
  else
    v17 = nullptr;
  this->m_pScreenShotURL = v17;
  v18 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v18 != nullptr )
    v19 = vgui::Label::Label(this: v18, parent: this, panelName: "BugSaveGameURL", text: defaultValue);
  else
    v19 = nullptr;
  this->m_pSaveGameURL = v19;
  v20 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v20 != nullptr )
    v21 = vgui::Label::Label(this: v20, parent: this, panelName: "BugBSPURL", text: defaultValue);
  else
    v21 = nullptr;
  this->m_pBSPURL = v21;
  v22 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v22 != nullptr )
    v23 = vgui::Label::Label(this: v22, parent: this, panelName: "BugVMFURL", text: defaultValue);
  else
    v23 = nullptr;
  this->m_pVMFURL = v23;
  v24 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v24 != nullptr )
    v25 = vgui::TextEntry::TextEntry(this: v24, parent: this, panelName: "BugIncludedFiles");
  else
    v25 = nullptr;
  this->m_pIncludedFiles = v25;
  v25->SetMultiline(this: v25, a2: true);
  this->m_pIncludedFiles->SetVerticalScrollbar(this: this->m_pIncludedFiles, a2: true);
  this->m_pIncludedFiles->SetEditable(this: this->m_pIncludedFiles, a2: false);
  v26 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v26 != nullptr )
    v27 = vgui::Button::Button(
            this: v26,
            parent: this,
            panelName: "BugTakeShot",
            text: "Take shot",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v27 = nullptr;
  this->m_pTakeShot = v27;
  v28 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: this,
            panelName: "BugSaveGame",
            text: "Save game",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v29 = nullptr;
  this->m_pSaveGame = v29;
  v30 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v30 != nullptr )
    v31 = vgui::Button::Button(
            this: v30,
            parent: this,
            panelName: "BugSaveBSP",
            text: "Include .bsp",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v31 = nullptr;
  this->m_pSaveBSP = v31;
  v32 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v32 != nullptr )
    v33 = vgui::Button::Button(
            this: v32,
            parent: this,
            panelName: "BugSaveVMF",
            text: "Include .vmf",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v33 = nullptr;
  this->m_pSaveVMF = v33;
  v34 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v34 != nullptr )
    v35 = vgui::Button::Button(
            this: v34,
            parent: this,
            panelName: "BugChooseVMFFolder",
            text: "Choose folder",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v35 = nullptr;
  this->m_pChooseVMFFolder = v35;
  v36 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v36 != nullptr )
    v37 = vgui::Button::Button(
            this: v36,
            parent: this,
            panelName: "BugIncludeFile",
            text: "Include file...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v37 = nullptr;
  this->m_pIncludeFile = v37;
  v38 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v38 != nullptr )
    v39 = vgui::Button::Button(
            this: v38,
            parent: this,
            panelName: "BugClearIncludedFiles",
            text: "Clear files",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v39 = nullptr;
  this->m_pClearIncludes = v39;
  v40 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v40 != nullptr )
    v41 = vgui::Label::Label(this: v40, parent: this, panelName: "BugPosition", text: defaultValue);
  else
    v41 = nullptr;
  this->m_pPosition = v41;
  v42 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v42 != nullptr )
    v43 = vgui::Label::Label(this: v42, parent: this, panelName: "BugOrientation", text: defaultValue);
  else
    v43 = nullptr;
  this->m_pOrientation = v43;
  v44 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v44 != nullptr )
    v45 = vgui::Label::Label(this: v44, parent: this, panelName: "BugLevel", text: defaultValue);
  else
    v45 = nullptr;
  this->m_pLevelName = v45;
  v46 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v46 != nullptr )
    v47 = vgui::Label::Label(this: v46, parent: this, panelName: "BugBuild", text: defaultValue);
  else
    v47 = nullptr;
  this->m_pBuildNumber = v47;
  v48 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v48 != nullptr )
    v49 = vgui::ComboBox::ComboBox(this: v48, parent: this, panelName: "BugSubmitter", numLines: 5, allowEdit: false);
  else
    v49 = nullptr;
  this->m_pSubmitter = v49;
  v50 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v50 != nullptr )
    v51 = vgui::ComboBox::ComboBox(this: v50, parent: this, panelName: "BugOwner", numLines: 10, allowEdit: false);
  else
    v51 = nullptr;
  this->m_pAssignTo = v51;
  v52 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v52 != nullptr )
    v53 = vgui::ComboBox::ComboBox(this: v52, parent: this, panelName: "BugSeverity", numLines: 10, allowEdit: false);
  else
    v53 = nullptr;
  this->m_pSeverity = v53;
  v54 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v54 != nullptr )
    v55 = vgui::ComboBox::ComboBox(this: v54, parent: this, panelName: "BugReportType", numLines: 10, allowEdit: false);
  else
    v55 = nullptr;
  this->m_pReportType = v55;
  v56 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v56 != nullptr )
    v57 = vgui::ComboBox::ComboBox(this: v56, parent: this, panelName: "BugPriority", numLines: 10, allowEdit: false);
  else
    v57 = nullptr;
  this->m_pPriority = v57;
  v58 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v58 != nullptr )
    v59 = vgui::ComboBox::ComboBox(this: v58, parent: this, panelName: "BugArea", numLines: 10, allowEdit: false);
  else
    v59 = nullptr;
  this->m_pGameArea = v59;
  v60 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v60 != nullptr )
    v61 = vgui::ComboBox::ComboBox(this: v60, parent: this, panelName: "BugMapNumber", numLines: 10, allowEdit: false);
  else
    v61 = nullptr;
  this->m_pMapNumber = v61;
  v62 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v62 != nullptr )
    v63 = vgui::Button::Button(
            this: v62,
            parent: this,
            panelName: "BugSubmit",
            text: "Submit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v63 = nullptr;
  this->m_pSubmit = v63;
  v64 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v64 != nullptr )
    v65 = vgui::Button::Button(
            this: v64,
            parent: this,
            panelName: "BugCancel",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v65 = nullptr;
  this->m_pCancel = v65;
  v66 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v66 != nullptr )
    v67 = vgui::Button::Button(
            this: v66,
            parent: this,
            panelName: "BugClearForm",
            text: "Clear Form",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v67 = nullptr;
  this->m_pClearForm = v67;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  if ( this->m_bIsPublic )
    vgui::Frame::LoadControlSettings(
      this,
      dialogResourceName: "Resource\\BugUIPanel_Public.res",
      pathID: nullptr,
      pPreloadedKeyValues: nullptr,
      pConditions: nullptr);
  else
    vgui::Frame::LoadControlSettings(
      this,
      dialogResourceName: "Resource\\BugUIPanel_Filequeue.res",
      pathID: nullptr,
      pPreloadedKeyValues: nullptr,
      pConditions: nullptr);
  v68 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v68 != nullptr )
    v69 = KeyValues::KeyValues(this: v68, setName: "OnChooseVMFFolder");
  else
    v69 = nullptr;
  this->m_pChooseVMFFolder->SetCommand(this: this->m_pChooseVMFFolder, a2: v69);
  this->m_pChooseVMFFolder->AddActionSignalTarget_2(this: this->m_pChooseVMFFolder, a2: this);
  Wide = vgui::Panel::GetWide(this);
  h = vgui::Panel::GetTall(this);
  v71 = (videomode->GetModeWidth(this: videomode) - Wide) / 2;
  ha = (videomode->GetModeHeight(this: videomode) - h) / 2;
  this->IsVisible(this);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  vgui::Panel::SetPos(this, x: v71, y: ha);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10140990
// Name: public: virtual struct vgui::PanelMessageMap __near * CBugUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBugUIPanel::GetMessageMap(CBugUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBugUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBugUIPanel::GetMessageMap'::`2'::s_pMap;
  `CBugUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
  `CBugUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101409C0
// Name: public: virtual struct PanelAnimationMap __near * CBugUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBugUIPanel::GetAnimMap(CBugUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBugUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101409D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBugUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBugUIPanel::GetKBMap(CBugUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBugUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBugUIPanel::GetKBMap'::`2'::s_pMap;
  `CBugUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBugUIPanel");
  `CBugUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10140A00
// Name: public: virtual CBugUIPanel::~CBugUIPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::~CBugUIPanel(CBugUIPanel *this)
{
  this->__vftable = (CBugUIPanel_vtbl *)&CBugUIPanel::`vftable';
  this->m_sDllName.m_Storage.m_nActualLength = 0;
  if ( this->m_sDllName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sDllName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sDllName.m_Storage.m_Memory.m_pMemory);
      this->m_sDllName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sDllName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_strRemoteBugInfoPath.m_Storage.m_nActualLength = 0;
  if ( this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_pMemory);
      this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_IncludedFiles);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10140A90
// Name: protected: virtual void CBugUIPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnFileSelected(CBugUIPanel *this, char *fullpath)
{
  CBugUIPanel *v2; // edi
  char v3; // bl
  bool v4; // zf
  vgui::Panel *v5; // eax
  CUtlVector<CBugUIPanel::includedfile,CUtlMemory<CBugUIPanel::includedfile,int> > *p_m_IncludedFiles; // ebx
  int v7; // esi
  int v8; // edi
  char v9[8192]; // [esp+8h] [ebp-2410h] BYREF
  char pDest[512]; // [esp+2008h] [ebp-410h] BYREF
  CBugUIPanel::includedfile src; // [esp+2208h] [ebp-210h] BYREF
  char dest[12]; // [esp+2408h] [ebp-10h] BYREF
  CBugUIPanel *v13; // [esp+2414h] [ebp-4h]

  v2 = this;
  v3 = 0;
  v4 = this->m_pBugReporter == nullptr;
  v13 = this;
  if ( (v4 || !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter)) && fullpath != nullptr && *fullpath != 0 )
  {
    if ( !g_pFileSystem->FullPathToRelativePath(this: g_pFileSystem, a2: fullpath, a3: pDest, a4: 512) )
    {
      if ( V_stristr(pStr: fullpath, pSearch: com_basedir) == nullptr )
      {
        _Msg(a1: "Only files beneath the base game directory can be included\n");
        return;
      }
      V_snprintf(pDest, maxLen: 512, pFormat: "..%s", &fullpath[strlen(com_basedir)]);
      v3 = 1;
    }
    V_ExtractFileExtension(path: pDest, dest, destSize: 10);
    if ( vgui::PHandle::Get(this: &v2->m_hFileOpenDialog) != nullptr )
    {
      v5 = vgui::PHandle::Get(this: &v2->m_hFileOpenDialog);
      v5->MarkForDeletion(this: v5);
    }
    V_strncpy(pDest: src.name, pSrc: pDest, maxLen: 256);
    if ( v3 != 0 )
      V_snprintf(pDest: src.fixedname, maxLen: 256, pFormat: "%s", &src.name[3]);
    else
      V_snprintf(pDest: src.fixedname, maxLen: 256, pFormat: "%s", &src);
    V_FixSlashes(pname: src.fixedname, separator: 92);
    p_m_IncludedFiles = &v2->m_IncludedFiles;
    CUtlVector<CBugUIPanel::includedfile,CUtlMemory<CBugUIPanel::includedfile,int>>::InsertBefore(
      this: &v2->m_IncludedFiles,
      elem: v2->m_IncludedFiles.m_Size,
      &src);
    v7 = 0;
    v9[0] = 0;
    if ( v2->m_IncludedFiles.m_Size > 0 )
    {
      v8 = 0;
      do
      {
        V_strncat(
          pDest: v9,
          pSrc: p_m_IncludedFiles->m_Memory.m_pMemory[v8].name,
          destBufferSize: 0x2000u,
          max_chars_to_copy: -1);
        V_strncat(pDest: v9, pSrc: "\n", destBufferSize: 0x2000u, max_chars_to_copy: -1);
        ++v7;
        ++v8;
      }
      while ( v7 < v13->m_IncludedFiles.m_Size );
      v2 = v13;
    }
    v2->m_pIncludedFiles->SetText(this: v2->m_pIncludedFiles, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140CA0
// Name: public: virtual void CEngineBugReporter::InstallBugReportingUI(class vgui::Panel __near *,enum IEngineBugReporter::BR_TYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineBugReporter::InstallBugReportingUI(
        CEngineBugReporter *this,
        CDragDropHelperPanel *parent,
        IEngineBugReporter::BR_TYPE type)
{
  const char *InternalBugReporterDLL; // eax
  bool (__thiscall *FileExists)(IBaseFileSystem *, const char *, const char *); // edx
  EUniverse SteamUniverse; // eax
  CBugUIPanel *v7; // eax
  char fn[512]; // [esp+4h] [ebp-204h] BYREF
  BOOL bUsePublic; // [esp+204h] [ebp-4h]

  if ( g_pBugUI != nullptr )
    return;
  InternalBugReporterDLL = GetInternalBugReporterDLL();
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "%s.dll", InternalBugReporterDLL);
  FileExists = g_pFileSystem->FileExists;
  LOBYTE(bUsePublic) = 1;
  if ( FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: fn, a3: "EXECUTABLE_PATH") && type != BR_PUBLIC )
  {
    if ( type == BR_INTERNAL )
    {
      LOBYTE(bUsePublic) = 0;
      goto LABEL_6;
    }
    SteamUniverse = GetSteamUniverse();
    LOBYTE(bUsePublic) = SteamUniverse == k_EUniversePublic;
    if ( SteamUniverse != k_EUniversePublic )
LABEL_6:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&bugreporter_uploadasync.IConVar, value: 1);
  }
  v7 = (CBugUIPanel *)MemAlloc_Alloc(nSize: 0x930u);
  if ( v7 != nullptr )
    g_pBugUI = CBugUIPanel::CBugUIPanel(this: v7, bIsPublic: bUsePublic, parent);
  else
    g_pBugUI = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_ParentPanel,
    pPanel: parent);
}

//------------------------------------------------------------------------------
// Address: 0x10140E20
// Name: protected: bool CBugUIPanel::UploadBugSubmission(char const __near *,int,char const __near *,char const __near *,char const __near *,char const __near *,class CUtlVector<struct CBugUIPanel::includedfile,class CUtlMemory<struct CBugUIPanel::includedfile,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugUIPanel::UploadBugSubmission(
        CBugUIPanel *this,
        const char *levelname,
        int bugId,
        const char *savefile,
        char *screenshot,
        const char *bsp,
        const char *vmf,
        CUtlVector<CBugUIPanel::includedfile,CUtlMemory<CBugUIPanel::includedfile,int> > *files)
{
  int m_nValue; // eax
  const char *v10; // esi
  char *SubmissionURL; // eax
  const char *v12; // esi
  char *v13; // eax
  const char *v14; // edi
  void *v15; // esi
  char *v16; // eax
  const char *v17; // esi
  char *v18; // eax
  CUtlVector<CBugUIPanel::includedfile,CUtlMemory<CBugUIPanel::includedfile,int> > *v19; // esi
  const char *m_Size; // eax
  const char *v21; // edi
  const char *v22; // esi
  const char *v23; // eax
  const char *v24; // eax
  char *v25; // eax
  char *v26; // esi
  bool (__thiscall *v27)(CBugUIPanel *, const char *, const char *, bool); // ecx
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v28; // eax
  bool v29; // zf
  char remotefile[512]; // [esp+Ch] [ebp-434h] BYREF
  char localfile[512]; // [esp+20Ch] [ebp-234h] BYREF
  bool (__thiscall *v33)(CBugUIPanel *, const char *, const char *, bool); // [esp+40Ch] [ebp-34h]
  CUtlString v34; // [esp+41Ch] [ebp-24h] BYREF
  bool bAsync; // [esp+42Fh] [ebp-11h]
  CUtlString src; // [esp+430h] [ebp-10h] BYREF

  if ( bugreporter_uploadasync.m_pParent != nullptr )
    m_nValue = bugreporter_uploadasync.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v10 = savefile;
  bAsync = m_nValue != 0;
  if ( savefile != nullptr && *savefile != 0 )
  {
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/save/%s.sav", com_gamedir, savefile);
    SubmissionURL = CBugUIPanel::GetSubmissionURL(this, bugid: bugId);
    V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s.sav", SubmissionURL, v10);
    V_FixSlashes(pname: localfile, separator: 92);
    V_FixSlashes(pname: remotefile, separator: 92);
    HIBYTE(savefile) = 0;
    CUtlString::CUtlString(this: &v34);
    CUtlString::operator=(this: &v34, src: remotefile);
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: localfile);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
      this: &g_UploadQueue,
      pObject: this,
      pfnProxied: (unsigned int)CBugUIPanel::UploadFile,
      arg1: (const CUtlEnvelope<char const *> *)&src,
      arg2: (const CUtlEnvelope<char const *> *)&v34,
      arg3: (const bool *)&savefile + 3);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
        src.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      src.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v34.m_Storage.m_nActualLength = 0;
    if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
  }
  v12 = screenshot;
  if ( screenshot != nullptr && *screenshot != 0 )
  {
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/screenshots/%s.jpg", com_gamedir, screenshot);
    v13 = CBugUIPanel::GetSubmissionURL(this, bugid: bugId);
    V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s.jpg", v13, v12);
    V_FixSlashes(pname: localfile, separator: 92);
    V_FixSlashes(pname: remotefile, separator: 92);
    HIBYTE(savefile) = 0;
    CUtlString::CUtlString(this: &v34);
    CUtlString::operator=(this: &v34, src: remotefile);
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: localfile);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
      this: &g_UploadQueue,
      pObject: this,
      pfnProxied: (unsigned int)CBugUIPanel::UploadFile,
      arg1: (const CUtlEnvelope<char const *> *)&src,
      arg2: (const CUtlEnvelope<char const *> *)&v34,
      arg3: (const bool *)&savefile + 3);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
        src.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      src.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v34.m_Storage.m_nActualLength = 0;
    if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
  }
  v14 = bsp;
  if ( bsp != nullptr && *bsp != 0 )
  {
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "maps/%s.bsp", levelname);
    v15 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: localfile, a3: "rb", a4: 0, a5: 0, a6: &screenshot);
    if ( v15 != nullptr )
    {
      V_strncpy(pDest: localfile, pSrc: screenshot, maxLen: 512);
      free(pMem: screenshot);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v15);
    }
    else
    {
      V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/maps/%s.bsp", com_gamedir, levelname);
    }
    v16 = CBugUIPanel::GetSubmissionURL(this, bugid: bugId);
    V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s.bsp", v16, v14);
    V_FixSlashes(pname: localfile, separator: 92);
    V_FixSlashes(pname: remotefile, separator: 92);
    HIBYTE(savefile) = 0;
    CUtlString::CUtlString(this: &v34);
    CUtlString::operator=(this: &v34, src: remotefile);
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: localfile);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
      this: &g_UploadQueue,
      pObject: this,
      pfnProxied: (unsigned int)CBugUIPanel::UploadFile,
      arg1: (const CUtlEnvelope<char const *> *)&src,
      arg2: (const CUtlEnvelope<char const *> *)&v34,
      arg3: (const bool *)&savefile + 3);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
        src.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      src.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v34.m_Storage.m_nActualLength = 0;
    if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
  }
  v17 = vmf;
  if ( vmf != nullptr && *vmf != 0 )
  {
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/%s.vmf", this->m_szVMFContentDirFullpath, levelname);
    if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: localfile, a3: nullptr) )
    {
      v18 = CBugUIPanel::GetSubmissionURL(this, bugid: bugId);
      V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s.vmf", v18, v17);
      V_FixSlashes(pname: localfile, separator: 92);
      V_FixSlashes(pname: remotefile, separator: 92);
      HIBYTE(levelname) = 0;
      CUtlString::CUtlString(this: &src);
      CUtlString::operator=(this: &src, src: remotefile);
      CUtlString::CUtlString(this: &v34);
      CUtlString::operator=(this: &v34, src: localfile);
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
        this: &g_UploadQueue,
        pObject: this,
        pfnProxied: (unsigned int)CBugUIPanel::UploadFile,
        arg1: (const CUtlEnvelope<char const *> *)&v34,
        arg2: (const CUtlEnvelope<char const *> *)&src,
        arg3: (const bool *)&levelname + 3);
      CUtlString::~CUtlString(this: &v34);
      CUtlString::~CUtlString(this: &src);
    }
    else
    {
      _Msg(a1: "Unable to locate .vmf file %s\n", localfile);
    }
  }
  v19 = files;
  m_Size = (const char *)files->m_Size;
  if ( (int)m_Size <= 0 )
  {
    if ( bAsync )
      ThreadExecuteSolo<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void)>(
        pszName: "BugUpload",
        a1: &g_UploadQueue,
        a2: (unsigned int)CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued);
    else
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_UploadQueue);
    return 1;
  }
  else
  {
    v21 = nullptr;
    v33 = CBugUIPanel::UploadFile;
    levelname = nullptr;
    savefile = m_Size;
    while ( 1 )
    {
      V_snprintf(
        pDest: localfile,
        maxLen: 512,
        pFormat: "%s/%s",
        com_gamedir,
        &v21[(unsigned int)v19->m_Memory.m_pMemory]);
      v22 = &v21[(unsigned int)v19->m_Memory.m_pMemory];
      v23 = this->m_pBugReporter->GetSubmissionURL(this: this->m_pBugReporter);
      if ( v23 == nullptr )
      {
        v24 = this->m_pBugReporter->GetRepositoryURL(this: this->m_pBugReporter);
        if ( v24 == nullptr )
          v24 = "\\\\fileserver\\bugs";
        V_snprintf(pDest: url, maxLen: 512, pFormat: "%s/%i", v24, bugId);
        v23 = url;
      }
      V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s", v23, v22 + 256);
      V_FixSlashes(pname: localfile, separator: 92);
      V_FixSlashes(pname: remotefile, separator: 92);
      CUtlString::CUtlString(this: &v34);
      CUtlString::operator=(this: &v34, src: remotefile);
      CUtlString::CUtlString(this: &src);
      CUtlString::operator=(this: &src, src: localfile);
      v25 = (char *)MemAlloc_Alloc(nSize: 0x50u);
      v26 = v25;
      if ( v25 != nullptr )
      {
        v27 = v33;
        *((_DWORD *)v25 + 3) = 1;
        *(_DWORD *)v25 = &CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        *((_DWORD *)v25 + 2) = &CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        *((_DWORD *)v25 + 4) = v27;
        *((_DWORD *)v25 + 5) = 0;
        *((_DWORD *)v25 + 6) = 0;
        *((_DWORD *)v25 + 7) = 0;
        *((_DWORD *)v25 + 8) = this;
        CUtlString::CUtlString(this: (CUtlString *)(v25 + 40));
        CUtlString::operator=(this: (CUtlString *)(v26 + 40), &src);
        CUtlString::CUtlString(this: (CUtlString *)(v26 + 56));
        CUtlString::operator=(this: (CUtlString *)(v26 + 56), src: &v34);
        v21 = levelname;
        v26[72] = 0;
      }
      else
      {
        v26 = nullptr;
      }
      if ( g_UploadQueue.m_bNoQueue )
      {
        (*(void (__thiscall **)(char *))(*(_DWORD *)v26 + 12))(a1: v26);
        (*(void (__thiscall **)(char *))(*(_DWORD *)v26 + 4))(a1: v26);
      }
      else
      {
        v28 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)CTSListBase::Pop(this: &g_UploadQueue.m_queue.m_FreeNodes);
        if ( v28 != nullptr || (v28 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
        {
          v28->elem.userdata = (int)v26;
          CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_UploadQueue, pNode: v28);
        }
        else
        {
          CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_UploadQueue, pNode: nullptr);
        }
      }
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
          src.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        src.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v34.m_Storage.m_nActualLength = 0;
      if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v34.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
          v34.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v34.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v21 += 512;
      v29 = savefile-- == (const char *)1;
      levelname = v21;
      if ( v29 )
        break;
      v19 = files;
    }
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_UploadQueue);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101415E0
// Name: protected: void CBugUIPanel::OnFinishBugReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnFinishBugReport(CBugUIPanel *this)
{
  IBugReporter *m_pBugReporter; // ecx
  bool v3; // bl
  int v4; // eax
  const char *v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v8; // [esp-8h] [ebp-14h]
  int bugId; // [esp+8h] [ebp-4h] BYREF

  m_pBugReporter = this->m_pBugReporter;
  bugId = -1;
  v3 = m_pBugReporter->CommitBugReport(this: m_pBugReporter, a2: &bugId);
  if ( !v3 )
  {
    _Warning(a1: "Unable to post bug report to database\n");
LABEL_8:
    v8 = va(format: "play %s\n", "common/bugreporter_failed");
    TraceType = CTraceFilter::GetTraceType(this: v6);
    Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
    this->m_bWaitForFinish = false;
    return;
  }
  if ( !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter)
    && CBugUIPanel::UploadBugSubmission(
         this,
         levelname: this->m_szLevel,
         bugId,
         savefile: this->m_szSaveGameName,
         screenshot: this->m_szScreenShotName,
         bsp: this->m_szBSPName,
         vmf: this->m_szVMFName,
         files: &this->m_IncludedFiles) == 0 )
  {
    _Warning(a1: "Unable to upload saved game and screenshot to bug repository!\n");
    v3 = false;
  }
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-remotebug", a3: 0) != 0 )
  {
    v5 = this->m_pBugReporter->GetSubmissionURL(this: this->m_pBugReporter);
    CServerRemoteAccess::RemoteBug(this: &g_ServerRemoteAccess, pBugPath: v5);
  }
  if ( !v3 )
    goto LABEL_8;
  CBugUIPanel::WipeData(this);
  CBugUIPanel::SuccessSound(this, bugId);
  if ( !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
  {
    this->Close(this);
    ++this->m_BugSub;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141720
// Name: protected: void CBugUIPanel::OnSubmit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::OnSubmit(CBugUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t TraceType; // eax
  bool v6; // al
  IBugReporter *m_pBugReporter; // ecx
  const char *v8; // eax
  bool v9; // al
  IMaterialSystem_vtbl *v10; // edi
  int v11; // eax
  const MaterialSystem_Config_t *v12; // edi
  int v13; // eax
  const char *v14; // ebx
  MaterialThreadMode_t v15; // eax
  __int32 v16; // eax
  int v17; // ecx
  const char *v18; // eax
  const char *v19; // edi
  int v20; // eax
  int v21; // eax
  CClientState *BaseLocalClient; // eax
  int m_nValue; // ebx
  double v24; // st7
  double v25; // st7
  int v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // ebx
  IBaseFileSystem *v29; // eax
  KeyValues *i; // edi
  const char *String; // eax
  const char *Name; // eax
  IBaseFileSystem_vtbl *v33; // edi
  int v34; // eax
  int v35; // eax
  IMatchSession *v36; // eax
  IMatchSession *v37; // edi
  KeyValues *v38; // eax
  KeyValues *v39; // eax
  double v40; // st7
  int v41; // edi
  int v42; // eax
  int j; // edi
  signed int v44; // ebx
  const char *v45; // eax
  const char *v46; // eax
  int v47; // edx
  int m_Put; // ebx
  IBugReporter *v49; // ecx
  IBugReporter_vtbl *v50; // ebx
  int v51; // eax
  IBugReporter *v52; // ecx
  IBugReporter_vtbl *v53; // ebx
  int v54; // eax
  int v55; // ebx
  int CPUInformation; // edi
  IBugReporter *v57; // ebx
  IBugReporter_vtbl *v58; // edx
  int v59; // ecx
  IBugReporter_vtbl *v60; // edx
  int v61; // edi
  char *v62; // eax
  char *v63; // ebx
  char *m_nGrowSize; // ecx
  char *v65; // eax
  int v66; // edi
  unsigned int v67; // edi
  HZIP__ *ZipZ; // eax
  char v69; // bl
  char v70; // al
  HZIP__ *m_hZip; // ecx
  void *v72; // eax
  void *v73; // edi
  ECommandTarget_t v74; // eax
  const char *v75; // eax
  const char *v76; // eax
  const char *v77; // eax
  const char *v78; // eax
  int v79; // ebx
  char *v80; // edi
  const char *v81; // eax
  CBugReportUploadProgressDialog *v82; // eax
  CBugReportUploadProgressDialog *v83; // eax
  vgui::IInput *v84; // ebx
  vgui::IInput_vtbl *v85; // edi
  unsigned int v86; // eax
  int v87; // [esp-8h] [ebp-649Ch]
  int v88; // [esp-4h] [ebp-6498h]
  int v89; // [esp-4h] [ebp-6498h]
  double v90; // [esp+0h] [ebp-6494h]
  int v91; // [esp+0h] [ebp-6494h]
  int v92; // [esp+4h] [ebp-6490h]
  const char *v93; // [esp+8h] [ebp-648Ch]
  int v94; // [esp+8h] [ebp-648Ch]
  int v95; // [esp+8h] [ebp-648Ch]
  const char *v96; // [esp+Ch] [ebp-6488h]
  int v97; // [esp+Ch] [ebp-6488h]
  int v98; // [esp+Ch] [ebp-6488h]
  const char *v99; // [esp+Ch] [ebp-6488h]
  char *v100; // [esp+Ch] [ebp-6488h]
  const char *v101; // [esp+10h] [ebp-6484h]
  int v102; // [esp+10h] [ebp-6484h]
  char *m_pszString; // [esp+10h] [ebp-6484h]
  int v104; // [esp+10h] [ebp-6484h]
  int v105[26]; // [esp+18h] [ebp-647Ch] BYREF
  char v106[8192]; // [esp+2018h] [ebp-447Ch] BYREF
  char v107[104]; // [esp+4018h] [ebp-247Ch] BYREF
  char v108[104]; // [esp+4818h] [ebp-1C7Ch] BYREF
  CFmtStrN<1040> v109; // [esp+4BFCh] [ebp-1898h] BYREF
  char v110[256]; // [esp+5018h] [ebp-147Ch] BYREF
  char v111[512]; // [esp+5118h] [ebp-137Ch] BYREF
  unsigned int v112; // [esp+5318h] [ebp-117Ch]
  unsigned int v113; // [esp+531Ch] [ebp-1178h]
  int v114; // [esp+5320h] [ebp-1174h]
  int v115; // [esp+5324h] [ebp-1170h]
  char v116[256]; // [esp+533Ch] [ebp-1158h] BYREF
  char v117[256]; // [esp+543Ch] [ebp-1058h] BYREF
  char v118[256]; // [esp+553Ch] [ebp-F58h] BYREF
  char v119[256]; // [esp+563Ch] [ebp-E58h] BYREF
  char v120[256]; // [esp+573Ch] [ebp-D58h] BYREF
  char v121[256]; // [esp+583Ch] [ebp-C58h] BYREF
  char v122[256]; // [esp+593Ch] [ebp-B58h] BYREF
  char v123[104]; // [esp+5A3Ch] [ebp-A58h] BYREF
  char v124[256]; // [esp+5B3Ch] [ebp-958h] BYREF
  char v125[256]; // [esp+5C3Ch] [ebp-858h] BYREF
  char v126[104]; // [esp+5D3Ch] [ebp-758h] BYREF
  char v127[104]; // [esp+5E3Ch] [ebp-658h] BYREF
  char v128[104]; // [esp+5EBCh] [ebp-5D8h] BYREF
  char v129[104]; // [esp+5FBCh] [ebp-4D8h] BYREF
  char relative[104]; // [esp+60BCh] [ebp-3D8h] BYREF
  char v131[4]; // [esp+62BCh] [ebp-1D8h] BYREF
  char out[104]; // [esp+62C0h] [ebp-1D4h] BYREF
  _MEMORYSTATUS Buffer; // [esp+63C0h] [ebp-D4h] BYREF
  CUtlBuffer v134; // [esp+63E0h] [ebp-B4h] BYREF
  CUtlBuffer v135; // [esp+6410h] [ebp-84h] BYREF
  char v136[8]; // [esp+6440h] [ebp-54h] BYREF
  CUtlBuffer buf; // [esp+6448h] [ebp-4Ch] BYREF
  char v138; // [esp+6483h] [ebp-11h]
  ConVarRef v139; // [esp+6484h] [ebp-10h] BYREF
  unsigned int v140; // [esp+648Ch] [ebp-8h] BYREF
  char v141; // [esp+6493h] [ebp-1h]

  if ( !this->m_bCanSubmit )
    return;
  if ( !CBugUIPanel::IsValidSubmission(this, verbose: true) )
  {
    v96 = va(format: "play %s\n", "common/bugreporter_failed");
    TraceType = CTraceFilter::GetTraceType(this: v4);
    Cbuf_AddText(eTarget: TraceType, pText: v96, nTickDelay: 0);
    return;
  }
  v6 = this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter);
  m_pBugReporter = this->m_pBugReporter;
  v141 = v6;
  v129[0] = 0;
  v106[0] = 0;
  v117[0] = 0;
  v121[0] = 0;
  v118[0] = 0;
  v116[0] = 0;
  v124[0] = 0;
  v126[0] = 0;
  v125[0] = 0;
  v122[0] = 0;
  v128[0] = 0;
  v120[0] = 0;
  v123[0] = 0;
  m_pBugReporter->StartNewBugReport(this: m_pBugReporter);
  if ( this->m_bIsSubmittingRemoteBug )
    CBugUIPanel::CopyInfoFromRemoteBug(this, a2, a3);
  ((void (__thiscall *)(vgui::TextEntry *, char *, int, int, int))this->m_pTitle->GetText_2)(
    a1: this->m_pTitle,
    a2: v119,
    a3: 256,
    a4: a3,
    a5: a2);
  if ( this->m_bIsSubmittingRemoteBug )
  {
    if ( this->m_szLevel[0] == 0 )
      V_strncpy(pDest: this->m_szLevel, pSrc: "console", maxLen: 256);
    V_strncpy(pDest: out, pSrc: this->m_szLevel, maxLen: 256);
    goto LABEL_13;
  }
  if ( host_state.worldmodel != nullptr )
  {
    v8 = modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
    CL_SetupMapName(pName: v8, pFixedName: out, maxlen: 256);
LABEL_13:
    V_snprintf(pDest: v129, maxLen: 256, pFormat: "%s: %s", out, v119);
    goto LABEL_14;
  }
  V_snprintf(pDest: v129, maxLen: 256, pFormat: "%s", v119);
LABEL_14:
  _Msg(a1: "title:  %s\n", v129);
  this->m_pDescription->GetText_2(this: this->m_pDescription, a2: v106, a3: 0x2000);
  _Msg(a1: "description:  %s\n", v106);
  this->m_pLevelName->GetText(this: this->m_pLevelName, a2: v126, a3: 256);
  this->m_pPosition->GetText(this: this->m_pPosition, a2: v122, a3: 256);
  this->m_pOrientation->GetText(this: this->m_pOrientation, a2: v125, a3: 256);
  this->m_pBuildNumber->GetText(this: this->m_pBuildNumber, a2: v128, a3: 256);
  v9 = g_pFileSystem->IsSteam(this: g_pFileSystem);
  v105[0] = -1;
  if ( v9 )
    V_strncat(pDest: v128, pSrc: " (Steam)", destBufferSize: 0x100u, max_chars_to_copy: v105[0]);
  else
    V_strncat(pDest: v128, pSrc: " (VSS)", destBufferSize: 0x100u, max_chars_to_copy: v105[0]);
  v10 = materials->__vftable;
  v11 = ((int (__thiscall *)(IMaterialSystem *, char *))materials->GetCurrentAdapter)(a1: materials, a2: v111);
  ((void (__thiscall *)(IMaterialSystem *, int))v10->GetDisplayAdapterInfo)(a1: materials, a2: v11);
  v12 = materials->GetCurrentConfigForVideoCard(this: materials);
  v140 = (unsigned int)"Unk";
  if ( g_pMaterialSystemHardwareConfig != nullptr )
  {
    v13 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
    v140 = (unsigned int)COM_DXLevelToString(dxlevel: v13);
  }
  v14 = "???";
  if ( g_pMaterialSystem != nullptr )
  {
    v15 = g_pMaterialSystem->GetThreadMode(this: g_pMaterialSystem);
    if ( v15 != MATERIAL_SINGLE_THREADED )
    {
      v16 = v15 - 1;
      if ( v16 != 0 )
      {
        if ( v16 == 1 )
          v14 = "MATERIAL_QUEUED_THREADED";
        else
          v14 = "unknown";
      }
      else
      {
        v14 = "MATERIAL_QUEUED_SINGLE_THREADED";
      }
    }
    else
    {
      v14 = "MATERIAL_SINGLE_THREADED";
    }
  }
  v17 = *CVProfile::FindOrCreateCounter(
           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
           a2: "reacquire_resources",
           a3: COUNTER_GROUP_NO_RESET);
  if ( (v12->m_Flags & 1) != 0 )
  {
    if ( (v12->m_Flags & 0x20000) != 0 )
      v18 = "Windowed no border";
    else
      v18 = "Windowed";
  }
  else
  {
    v18 = "Fullscreen";
  }
  v19 = (const char *)v140;
  if ( v140 == 0 )
    v19 = "Unk";
  v20 = ((int (__thiscall *)(IVideoMode *, _DWORD, _DWORD, const char *, int, const char *))videomode->GetModeHeight)(
          a1: videomode,
          a2: COERCE_UNSIGNED_INT64(g_fFramesPerSecond),
          a3: HIDWORD(COERCE_UNSIGNED_INT64(g_fFramesPerSecond)),
          a4: v18,
          a5: v17,
          a6: v14);
  v21 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: v20);
  V_snprintf(
    pDest: v107,
    maxLen: 2048,
    pFormat: "Driver Name:  %s\n"
    "VendorId / DeviceId:  0x%x / 0x%x\n"
    "SubSystem / Rev:  0x%x / 0x%x\n"
    "DXLevel:  %s\n"
    "Vid:  %i x %i\n"
    "Framerate:  %.3f\n"
    "Window mode: %s\n"
    "Number of ReaquireResource events (lost device): %d\n"
    "Material system thread mode: %s",
    v111,
    v112,
    v113,
    v114,
    v115,
    v19,
    v21,
    v88,
    v90,
    v93,
    v97,
    v101);
  _Msg(a1: "%s\n", v107);
  v140 = 0;
  if ( GetBaseLocalClient()->m_NetChannel != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    v140 = (int)(((double (__thiscall *)(INetChannel *, _DWORD))BaseLocalClient->m_NetChannel->GetAvgLatency)(
                   a1: BaseLocalClient->m_NetChannel,
                   a2: 0)
               * 1000.0);
  }
  if ( (_S1_15 & 1) == 0 )
  {
    _S1_15 |= 1u;
    ConVarRef::ConVarRef(this: &host_thread_mode, pName: "host_thread_mode");
  }
  if ( (_S1_15 & 2) == 0 )
  {
    _S1_15 |= 2u;
    ConVarRef::ConVarRef(this: &sv_alternateticks, pName: "sv_alternateticks");
  }
  if ( (_S1_15 & 4) == 0 )
  {
    _S1_15 |= 4u;
    ConVarRef::ConVarRef(this: &ai_strong_optimizations, pName: "ai_strong_optimizations");
  }
  if ( (_S1_15 & 8) == 0 )
  {
    _S1_15 |= 8u;
    ConVarRef::ConVarRef(this: &mat_queue_mode, pName: "mat_queue_mode");
  }
  CUtlBuffer::CUtlBuffer(this: &v135, growSize: 0, initSize: 0, nFlags: 1);
  if ( (_S1_15 & 0x10) == 0 )
  {
    _S1_15 |= 0x10u;
    ConVarRef::ConVarRef(this: &skill, pName: "skill");
  }
  m_nValue = skill.m_pConVarState->m_Value.m_nValue;
  v24 = ((double (__thiscall *)(ConVar_ServerBounded *, unsigned int, int, int, int, int))cl_cmdrate->GetFloat)(
          a1: cl_cmdrate,
          a2: v140,
          a3: host_thread_mode.m_pConVarState->m_Value.m_nValue,
          a4: sv_alternateticks.m_pConVarState->m_Value.m_nValue,
          a5: ai_strong_optimizations.m_pConVarState->m_Value.m_nValue,
          a6: mat_queue_mode.m_pConVarState->m_Value.m_nValue);
  v25 = ((double (__thiscall *)(ConVar_ServerBounded *, int))cl_updaterate->GetFloat)(a1: cl_updaterate, a2: (int)v24);
  v26 = ((int (__thiscall *)(ConVar_ServerBounded *, int))cl_rate->GetInt)(a1: cl_rate, a2: (int)v25);
  CUtlBuffer::Printf(
    this: &v135,
    pFmt: "Convars:\n"
    "\tskill:  %i\n"
    "\tnet:  rate %i update %i cmd %i latency %i msec\n"
    "\thost_thread_mode:  %i\n"
    "\tsv_alternateticks:  %i\n"
    "\tai_strong_optimizations:  %i\n"
    "\tmat_queue_mode: %i\n",
    m_nValue,
    v26,
    v87,
    v89,
    v91,
    v92,
    v94,
    v98,
    v102);
  v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v27 != nullptr )
    v28 = KeyValues::KeyValues(this: v27, setName: "bugreport_convars");
  else
    v28 = nullptr;
  if ( g_pFileSystem != nullptr )
    v29 = &g_pFileSystem->IBaseFileSystem;
  else
    v29 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v28,
         filesystem: v29,
         resourceName: "scripts/bugreport_convars.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( i = KeyValues::GetFirstSubKey(this: v28); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
      ConVarRef::ConVarRef(this: &v139, pName: String);
      if ( ConVarRef::IsValid(this: &v139) )
      {
        m_pszString = v139.m_pConVarState->m_Value.m_pszString;
        Name = KeyValues::GetName(this: i);
        CUtlBuffer::Printf(this: &v135, pFmt: "%s:  %s\n", Name, m_pszString);
      }
    }
  }
  KeyValues::deleteThis(this: v28);
  if ( GetBaseLocalClient()->m_nSignonState == 6
    && g_ServerGlobalVariables.mapversion != 0
    && host_state.worldmodel != nullptr )
  {
    v33 = g_pFileSystem->IBaseFileSystem::__vftable;
    v34 = ((int (__thiscall *)(IModelLoader *, model_t *, const char *))modelloader->GetName)(
            a1: modelloader,
            a2: host_state.worldmodel,
            a3: "GAME");
    v35 = ((int (__thiscall *)(IBaseFileSystem *, int))v33->GetFileTime)(a1: &g_pFileSystem->IBaseFileSystem, a2: v34);
    if ( v141 != 0 || v35 == 0 )
    {
      CUtlBuffer::Printf(this: &v135, pFmt: "Map version:  %i\n", g_ServerGlobalVariables.mapversion);
    }
    else
    {
      g_pFileSystem->FileTimeToString(this: g_pFileSystem, a2: v136, a3: 64, a4: v35);
      CUtlBuffer::Printf(
        this: &v135,
        pFmt: "Map version:  %i\nFile timestamp:  %s",
        g_ServerGlobalVariables.mapversion,
        v136);
    }
  }
  if ( GetSteamUniverse() == k_EUniverseBeta )
  {
    if ( sv.m_State >= ss_active && serverGameClients != nullptr )
    {
      _V_memset(dest: v108, fill: 0, count: 2048);
      serverGameClients->GetBugReportInfo(this: serverGameClients, a2: v108, a3: 2048);
      CUtlBuffer::Printf(this: &v135, pFmt: "%s", v108);
    }
    CUtlBuffer::Printf(this: &v135, pFmt: "matchmaking.dll info\n");
    if ( g_pMatchFramework != nullptr )
    {
      v36 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
      v37 = v36;
      if ( v36 != nullptr )
      {
        CUtlBuffer::Printf(this: &v135, pFmt: "match session %p\n", v36);
        v139.m_pConVar = (IConVar *)&CKeyValuesDumpForBugreport::`vftable';
        v139.m_pConVarState = (ConVar *)&v135;
        CUtlBuffer::Printf(this: &v135, pFmt: "session system data:\n");
        v38 = (KeyValues *)v37->GetSessionSystemData(this: v37);
        KeyValues::Dump(this: v38, pDump: (IKeyValuesDumpContext *)&v139, nIndentLevel: 0);
        CUtlBuffer::Printf(this: &v135, pFmt: "session settings:\n");
        v39 = v37->GetSessionSettings(this: v37);
        KeyValues::Dump(this: v39, pDump: (IKeyValuesDumpContext *)&v139, nIndentLevel: 0);
      }
      else
      {
        CUtlBuffer::Printf(this: &v135, pFmt: "[ no match session ]\n");
      }
    }
  }
  CUtlBuffer::Printf(this: &v135, pFmt: "gamedir:  %s\n", com_gamedir);
  v40 = _Plat_FloatTime();
  v41 = (int)(0.0002777777777777778 * v40);
  v42 = (int)(0.01666666666666667 * v40);
  v139.m_pConVarState = (ConVar *)(60 * (v42 % 60 + 60 * v41));
  V_snprintf(
    pDest: (char *)v105,
    maxLen: 0x2000,
    pFormat: "Blackbox dumped at %02d:%02d:%02.3f\n",
    v41,
    v42 % 60,
    v40 - (double)(int)v139.m_pConVarState);
  for ( j = 0; j < gBlackBox->GetTypeCount(this: gBlackBox); ++j )
  {
    v44 = 0;
    if ( gBlackBox->Count(this: gBlackBox, a2: j) > 0 )
    {
      do
      {
        v109.__vftable = (CFmtStrN<1040>_vtbl *)&CFmtStrN<1040>::`vftable';
        *(_WORD *)&v109.m_bQuietTruncation = 1;
        v109.m_nLength = 0;
        v45 = gBlackBox->Get(this: gBlackBox, a2: j, a3: v44);
        v46 = (const char *)((int (__thiscall *)(IBlackBox *, int, const char *))gBlackBox->GetTypeName)(
                              a1: gBlackBox,
                              a2: j,
                              a3: v45);
        CFmtStrN<1040>::sprintf(this: &v109, pszFormat: "%s: %s\n", v46, v99);
        V_strncat(pDest: (char *)v105, pSrc: v109.m_szBuf, destBufferSize: 0x2000u, max_chars_to_copy: -1);
        ++v44;
      }
      while ( v44 < ((int (__thiscall *)(IBlackBox *, int, int))gBlackBox->Count)(a1: gBlackBox, a2: j, a3: v104) );
    }
  }
  CUtlBuffer::Printf(this: &v135, pFmt: "%s", (const char *)v105);
  _Msg(a1: "%s", (const char *)v135.m_Memory.m_pMemory);
  CUtlBuffer::CUtlBuffer(this: &v134, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::Printf(this: &v134, pFmt: "Console:\n\n");
  CBugUIPanel::GetConsoleHistory(this, buf: &v134);
  if ( !this->m_bIsSubmittingRemoteBug )
  {
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: "bugconsole.txt",
      a3: "MOD",
      a4: v131,
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: v131, a3: "MOD", a4: &v134);
    this->OnFileSelected(this, a2: v131);
  }
  if ( bugreporter_console_bytes.m_pParent == nullptr
    || (v47 = bugreporter_console_bytes.m_pParent->m_Value.m_nValue) <= 1 )
  {
    v47 = 1;
  }
  if ( v134.m_Put >= v47 )
  {
    if ( bugreporter_console_bytes.m_pParent == nullptr
      || (m_Put = bugreporter_console_bytes.m_pParent->m_Value.m_nValue) <= 1 )
    {
      m_Put = 1;
    }
  }
  else
  {
    m_Put = v134.m_Put;
  }
  v139.m_pConVarState = (ConVar *)&v134.m_Memory.m_pMemory[v134.m_Put - m_Put];
  CUtlBuffer::Printf(
    this: &v135,
    pFmt: "\n\n-----------------------------------------------------------\nConsole:  (last %d bytes)\n\n",
    m_Put);
  CUtlBuffer::Put(this: &v135, pMem: v139.m_pConVarState, size: m_Put);
  if ( v141 != 0 )
  {
    this->m_pEmail->GetText_2(this: this->m_pEmail, a2: v123, a3: 256);
    if ( _V_strlen(str: v123) <= 0 )
      _Msg(a1: "Not sending email address\n");
    else
      _Msg(a1: "email %s\n", v123);
    this->m_pBugReporter->SetOwner(this: this->m_pBugReporter, a2: v123);
  }
  else
  {
    this->m_pSeverity->GetText_2(this: this->m_pSeverity, a2: v117, a3: 256);
    _Msg(a1: "severity %s\n", v117);
    this->m_pGameArea->GetText_2(this: this->m_pGameArea, a2: v121, a3: 256);
    _Msg(a1: "area %s\n", v121);
    this->m_pMapNumber->GetText_2(this: this->m_pMapNumber, a2: v118, a3: 256);
    _Msg(a1: "map number %s\n", v118);
    this->m_pPriority->GetText_2(this: this->m_pPriority, a2: v116, a3: 256);
    _Msg(a1: "priority %s\n", v116);
    this->m_pAssignTo->GetText_2(this: this->m_pAssignTo, a2: v124, a3: 256);
    _Msg(a1: "owner %s\n", v124);
    v49 = this->m_pBugReporter;
    v50 = v49->__vftable;
    v51 = (int)v49->GetUserNameForDisplayName(this: v49, a2: v124);
    v50->SetOwner(this: this->m_pBugReporter, a2: (const char *)v51);
  }
  this->m_pSubmitter->GetText_2(this: this->m_pSubmitter, a2: v110, a3: 256);
  v52 = this->m_pBugReporter;
  v53 = v52->__vftable;
  v54 = (int)v52->GetUserNameForDisplayName(this: v52, a2: v110);
  v53->SetSubmitter(this: this->m_pBugReporter, a2: (const char *)v54);
  _Msg(a1: "submitter %s\n", v110);
  this->m_pReportType->GetText_2(this: this->m_pReportType, a2: v120, a3: 256);
  _Msg(a1: "report_type %s\n", v120);
  _Msg(a1: "level %s\n", v126);
  _Msg(a1: "position %s\n", v122);
  _Msg(a1: "orientation %s\n", v125);
  _Msg(a1: "build %s\n", v128);
  if ( this->m_szSaveGameName[0] != 0 )
    _Msg(a1: "save file save/%s.sav\n", this->m_szSaveGameName);
  else
    _Msg(a1: "no save game\n");
  if ( this->m_szScreenShotName[0] != 0 )
    _Msg(a1: "screenshot screenshots/%s.jpg\n", this->m_szScreenShotName);
  else
    _Msg(a1: "no screenshot\n");
  if ( v141 == 0 )
  {
    if ( this->m_szBSPName[0] != 0 )
      _Msg(a1: "bsp file maps/%s.bsp\n", this->m_szBSPName);
    if ( this->m_szVMFName[0] != 0 )
      _Msg(a1: "vmf file maps/%s.vmf\n", this->m_szVMFName);
    v55 = 0;
    if ( this->m_IncludedFiles.m_Size > 0 )
    {
      v140 = 0;
      do
      {
        _Msg(a1: "Include:  %s\n", &this->m_IncludedFiles.m_Memory.m_pMemory->name[v140]);
        v140 += 512;
        ++v55;
      }
      while ( v55 < this->m_IncludedFiles.m_Size );
    }
  }
  this->m_pBugReporter->SetTitle(this: this->m_pBugReporter, a2: v129);
  this->m_pBugReporter->SetDescription(this: this->m_pBugReporter, a2: v106);
  if ( !this->m_bIsSubmittingRemoteBug )
  {
    this->m_pBugReporter->SetLevel(this: this->m_pBugReporter, a2: v126);
    this->m_pBugReporter->SetPosition(this: this->m_pBugReporter, a2: v122);
    this->m_pBugReporter->SetOrientation(this: this->m_pBugReporter, a2: v125);
    this->m_pBugReporter->SetBuildNumber(this: this->m_pBugReporter, a2: v128);
  }
  this->m_pBugReporter->SetSeverity(this: this->m_pBugReporter, a2: v117);
  this->m_pBugReporter->SetPriority(this: this->m_pBugReporter, a2: v116);
  this->m_pBugReporter->SetArea(this: this->m_pBugReporter, a2: v121);
  this->m_pBugReporter->SetMapNumber(this: this->m_pBugReporter, a2: v118);
  this->m_pBugReporter->SetReportType(this: this->m_pBugReporter, a2: v120);
  if ( !this->m_bIsSubmittingRemoteBug )
  {
    this->m_pBugReporter->SetDriverInfo(this: this->m_pBugReporter, a2: v107);
    this->m_pBugReporter->SetMiscInfo(this: this->m_pBugReporter, a2: (const char *)v135.m_Memory.m_pMemory);
    this->m_pBugReporter->SetConsoleHistory(this: this->m_pBugReporter, a2: (const char *)v134.m_Memory.m_pMemory);
  }
  ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetCSERAddress)(a1: this->m_pBugReporter);
  v100 = "hl2.exe";
  ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetExeName)(a1: this->m_pBugReporter);
  this->m_pBugReporter->SetGameDirectory(this: this->m_pBugReporter, a2: com_gamedir);
  CPUInformation = _GetCPUInformation();
  GlobalMemoryStatus(lpBuffer: &Buffer);
  this->m_pBugReporter->SetRAM(this: this->m_pBugReporter, a2: Buffer.dwTotalPhys >> 20);
  v57 = this->m_pBugReporter;
  v58 = v57->__vftable;
  v139.m_pConVarState = (ConVar *)(int)((double)*(__int64 *)(CPUInformation + 8) * 0.000001);
  v58->SetCPU(this: v57, a2: (int)v139.m_pConVarState);
  this->m_pBugReporter->SetProcessor(this: this->m_pBugReporter, a2: *(const char **)(CPUInformation + 16));
  v59 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
  v60 = this->m_pBugReporter->__vftable;
  v140 = v59;
  v60->SetDXVersion(this: this->m_pBugReporter, a2: v59 / 10, a3: v59 % 10, a4: v112, a5: v113);
  DisplaySystemVersion(osversion: v127, maxlen: 128);
  this->m_pBugReporter->SetOSVersion(this: this->m_pBugReporter, a2: v127);
  this->m_pBugReporter->ResetIncludedFiles(this: this->m_pBugReporter);
  this->m_pBugReporter->SetZipAttachmentName(this: this->m_pBugReporter, a2: defaultValue);
  if ( this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
  {
    v141 = 0;
    v138 = 0;
    CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, growSize: 0, initSize: 0, nFlags: 1);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "Title:  %s\n", v129);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "Description:  %s\n\n", v106);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "Level:  %s\n", v126);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "Position:  %s\n", v122);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "Orientation:  %s\n", v125);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "BuildNumber:  %s\n", v128);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "DriverInfo:  %s\n", v107);
    CUtlBuffer::Printf(
      this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize,
      pFmt: "Misc:  %s\n",
      (const char *)v135.m_Memory.m_pMemory);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "Exe:  %s\n", "hl2.exe");
    V_FileBase(in: com_gamedir, out, maxlen: 256);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "GameDirectory:  %s\n", out);
    GlobalMemoryStatus(lpBuffer: &Buffer);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "Ram:  %i\n", Buffer.dwTotalPhys >> 20);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "CPU:  %i\n", v139.m_pConVarState);
    CUtlBuffer::Printf(
      this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize,
      pFmt: "Processor:  %s\n",
      *(const char **)(CPUInformation + 16));
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "DXLevel:  %d\n", v140);
    CUtlBuffer::Printf(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, pFmt: "OSVersion:  %s\n", v127);
    if ( (buf.m_nMaxPut & 0x100) != 0
      && buf.m_nTab != 0
      && *(_BYTE *)(buf.m_nTab - (unsigned int)buf.m_PutOverflowFunc + buf.m_Memory.m_nGrowSize - 1) == 10 )
    {
      CUtlBuffer::PutTabs(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize);
    }
    if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, nSize: 1) )
    {
      *(_BYTE *)(buf.m_nTab - (unsigned int)buf.m_PutOverflowFunc + buf.m_Memory.m_nGrowSize) = 0;
      CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&buf.m_Memory.m_nGrowSize, nPut: ++buf.m_nTab);
    }
    v61 = 2 * buf.m_nTab + 1;
    v62 = (char *)MemAlloc_Alloc(nSize: v61);
    v63 = v62;
    if ( v62 != nullptr )
    {
      _V_memset(dest: v62, fill: 0, count: v61);
      m_nGrowSize = (char *)buf.m_Memory.m_nGrowSize;
      v65 = v63;
      if ( *(_BYTE *)buf.m_Memory.m_nGrowSize != 0 )
      {
        v139.m_pConVarState = (ConVar *)(v61 - 1);
        v66 = 0;
        do
        {
          if ( v66 >= (int)v139.m_pConVarState )
            break;
          if ( *m_nGrowSize == 10 )
          {
            *v65++ = 13;
            ++v66;
          }
          *v65++ = *m_nGrowSize++;
          ++v66;
        }
        while ( *m_nGrowSize != 0 );
      }
      *v65 = 0;
      v67 = _V_strlen(str: v63) + 1;
      if ( this->m_hZip != nullptr
        || (ZipZ = CreateZipZ(z: nullptr, len: 0x1000000u, flags: 3u), this->m_hZip = ZipZ, ZipZ != nullptr) )
      {
        ZipAdd(hz: this->m_hZip, dstzn: "info.txt", src: v63, len: v67, flags: 3u);
      }
      free(pMem: v63);
    }
    else
    {
      Sys_Error(error: "Unable to allocate %i bytes for bug description\n", v61);
    }
    if ( GetBaseLocalClient()->m_nMaxClients == 1 && this->m_szSaveGameName[0] != 0 )
    {
      V_snprintf(pDest: relative, maxLen: 512, pFormat: "save/%s.sav", this->m_szSaveGameName);
      V_FixSlashes(pname: relative, separator: 92);
      v69 = CBugUIPanel::AddFileToZip(this, relative);
    }
    else
    {
      v69 = v141;
    }
    if ( this->m_szScreenShotName[0] != 0 )
    {
      V_snprintf(pDest: relative, maxLen: 512, pFormat: "screenshots/%s.jpg", this->m_szScreenShotName);
      V_FixSlashes(pname: relative, separator: 92);
      v70 = CBugUIPanel::AddFileToZip(this, relative);
    }
    else
    {
      v70 = v138;
    }
    m_hZip = this->m_hZip;
    if ( m_hZip != nullptr && (v69 != 0 || v70 != 0) )
    {
      ZipGetMemory(hz: m_hZip, buf: (void **)&v139.m_pConVarState, len: &v140);
      if ( v139.m_pConVarState != nullptr && v140 != 0 )
      {
        v72 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "bug.zip", a3: "wb", a4: 0);
        v73 = v72;
        if ( v72 != nullptr )
        {
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v139.m_pConVarState, a3: v140, a4: v72);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v73);
          this->m_pBugReporter->SetZipAttachmentName(this: this->m_pBugReporter, a2: "bug.zip");
        }
      }
    }
    if ( this->m_hZip != nullptr )
    {
      CloseZipZ(hz: this->m_hZip);
      this->m_hZip = nullptr;
    }
    this->m_pBugReporter->SetSteamUserID(this: this->m_pBugReporter, a2: &this->m_SteamID, a3: 16);
    if ( buf.m_Put >= 0 && buf.m_Memory.m_nGrowSize != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nGrowSize);
  }
  else
  {
    if ( GetBaseLocalClient()->m_nSignonState == 6 && GetBaseLocalClient()->m_nMaxClients > 1 )
    {
      V_snprintf(pDest: out, maxLen: 256, pFormat: "say \"Bug Submitted [%s]: %s\"\n", v124, v129);
      v95 = (int)(float)((float)(1.5 / host_state.interval_per_tick) + 0.5);
      v74 = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)v95);
      Cbuf_AddText(eTarget: v74, pText: out, nTickDelay: v95);
    }
    if ( this->m_szSaveGameName[0] != 0 )
    {
      v75 = (const char *)((int (__thiscall *)(IBugReporter *, const char *))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: "hl2.exe");
      if ( v75 == nullptr )
        v75 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/BugId/%s.sav", v75, this->m_szSaveGameName);
      V_FixSlashes(pname: relative, separator: 92);
      v100 = relative;
      ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetSaveGame)(a1: this->m_pBugReporter);
    }
    if ( this->m_szScreenShotName[0] != 0 )
    {
      v76 = (const char *)((int (__thiscall *)(IBugReporter *, char *))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: v100);
      if ( v76 == nullptr )
        v76 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/BugId/%s.jpg", v76, this->m_szScreenShotName);
      V_FixSlashes(pname: relative, separator: 92);
      v100 = relative;
      ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetScreenShot)(a1: this->m_pBugReporter);
    }
    if ( this->m_szBSPName[0] != 0 )
    {
      v77 = (const char *)((int (__thiscall *)(IBugReporter *, char *))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: v100);
      if ( v77 == nullptr )
        v77 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/BugId/%s.bsp", v77, this->m_szBSPName);
      V_FixSlashes(pname: relative, separator: 92);
      v100 = relative;
      ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetBSPName)(a1: this->m_pBugReporter);
    }
    if ( this->m_szVMFName[0] != 0 )
    {
      v78 = (const char *)((int (__thiscall *)(IBugReporter *, char *))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: v100);
      if ( v78 == nullptr )
        v78 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/BugId/%s.vmf", v78, this->m_szVMFName);
      V_FixSlashes(pname: relative, separator: 92);
      v100 = relative;
      ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetVMFName)(a1: this->m_pBugReporter);
    }
    if ( this->m_IncludedFiles.m_Size > 0 )
    {
      v79 = 0;
      v140 = 0;
      do
      {
        v80 = &this->m_IncludedFiles.m_Memory.m_pMemory->name[v140];
        v81 = (const char *)((int (__thiscall *)(IBugReporter *, char *))this->m_pBugReporter->GetRepositoryURL)(
                              a1: this->m_pBugReporter,
                              a2: v100);
        if ( v81 == nullptr )
          v81 = "\\\\fileserver\\bugs";
        V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/BugId/%s", v81, v80 + 256);
        V_FixSlashes(pname: relative, separator: 92);
        v100 = relative;
        ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->AddIncludedFile)(a1: this->m_pBugReporter);
        v140 += 512;
        ++v79;
      }
      while ( v79 < this->m_IncludedFiles.m_Size );
    }
  }
  if ( !this->m_bIsSubmittingRemoteBug )
    V_strncpy(pDest: this->m_szLevel, pSrc: v126, maxLen: 256);
  if ( this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
  {
    v82 = (CBugReportUploadProgressDialog *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v82 != nullptr )
      v83 = CBugReportUploadProgressDialog::CBugReportUploadProgressDialog(
              this: v82,
              parent: nullptr,
              name: "ProgressDialog",
              title: "#Steam_SubmittingBug_WorkingTitle",
              message: "#Steam_SubmittingBug_WorkingText");
    else
      v83 = nullptr;
    this->m_pProgressDialog = v83;
    v83->Activate(this: v83);
    v84 = g_pVGuiInput;
    v85 = g_pVGuiInput->__vftable;
    v86 = this->m_pProgressDialog->GetVPanel(this: this->m_pProgressDialog);
    v85->SetAppModalSurface(this: v84, a2: v86);
    this->m_flPauseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) + 15.0;
  }
  else
  {
    CBugUIPanel::OnFinishBugReport(this);
  }
  if ( v134.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v134.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v134.m_Memory.m_pMemory);
      v134.m_Memory.m_pMemory = nullptr;
    }
    v134.m_Memory.m_nAllocationCount = 0;
  }
  if ( v135.m_Memory.m_nGrowSize >= 0 && v135.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v135.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10142EB0
// Name: public: virtual void CBugUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnCommand(CBugUIPanel *this, const char *command)
{
  if ( V_strcasecmp(s1: command, s2: "submit") == 0 )
  {
    CBugUIPanel::OnSubmit(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "cancel") == 0 )
  {
    this->Close(this);
    CBugUIPanel::WipeData(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "snapshot") == 0 )
  {
    CBugUIPanel::OnTakeSnapshot(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "savegame") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "savebsp") == 0 )
    {
LABEL_11:
      CBugUIPanel::OnSaveBSP(this);
      return;
    }
    if ( V_strcasecmp(s1: command, s2: "savevmf") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "clearform") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "addfile") != 0 )
        {
          if ( V_strcasecmp(s1: command, s2: "clearfiles") != 0 )
            vgui::Frame::OnCommand(this, command);
          else
            CBugUIPanel::OnClearIncludedFiles(this);
        }
        else
        {
          CBugUIPanel::OnIncludeFile(this);
        }
      }
      else
      {
        CBugUIPanel::OnClearForm(this);
      }
    }
    else
    {
      CBugUIPanel::OnSaveVMF(this);
    }
  }
  else
  {
    CBugUIPanel::OnSaveGame(this);
    if ( bugreporter_includebsp.m_pParent != nullptr
      && bugreporter_includebsp.m_pParent->m_Value.m_nValue != 0
      && !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
    {
      goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10143010
// Name: public: virtual void CBugUIPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CBugUIPanel::OnTick(CBugUIPanel *this)
{
  int m_nSnapShotFrame; // ecx
  int m_nValue; // eax
  vgui::Label *m_pScreenShotURL; // ecx
  IEngineVGuiInternal *v5; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  IBugReporter *m_pBugReporter; // ecx
  vgui::Button_vtbl *v8; // esi
  bool IsValidSubmission; // al
  vgui::ISystem_vtbl *v10; // edx
  CBugReportUploadProgressDialog *m_pProgressDialog; // ecx
  CBugReportFinishedDialog *v12; // eax
  CDragDropHelperPanel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  vgui::IInput *v16; // esi
  vgui::IInput_vtbl *v17; // edi
  int v18; // eax
  long double (__thiscall *GetFrameTime)(vgui::ISystem *); // edx
  float v20; // [esp+0h] [ebp-D0h]
  _BYTE v21[192]; // [esp+10h] [ebp-C0h] OVERLAPPED BYREF

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  CBugUIPanel::CheckContinueQueryingSteamForCSERList(this);
  if ( !this->IsVisible(this) )
  {
    if ( !this->m_bTakingSnapshot )
    {
      m_nSnapShotFrame = this->m_nSnapShotFrame;
      if ( m_nSnapShotFrame > 0 )
      {
        if ( bugreporter_snapshot_delay.m_pParent != nullptr )
          m_nValue = bugreporter_snapshot_delay.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( host_framecount >= m_nValue + m_nSnapShotFrame )
          CBugUIPanel::TakeSnapshot(this);
      }
      return;
    }
    if ( host_framecount < this->m_nSnapShotFrame + 2 )
      return;
    m_pScreenShotURL = this->m_pScreenShotURL;
    this->m_bTakingSnapshot = false;
    this->m_nSnapShotFrame = -1;
    m_pScreenShotURL->SetText(this: m_pScreenShotURL, a2: this->m_szScreenShotName);
    if ( this->m_bHidGameUIForSnapshot || !this->m_bAutoSubmit )
    {
      v5 = EngineVGui();
      v5->ActivateGameUI(this: v5);
    }
    SetVisible = this->SetVisible;
    this->m_bHidGameUIForSnapshot = false;
    SetVisible(this, a2: true);
    this->MoveToFront(this);
  }
  if ( this->m_bCanSubmit )
  {
    v8 = this->m_pSubmit->__vftable;
    IsValidSubmission = CBugUIPanel::IsValidSubmission(this, verbose: false);
    v8->SetEnabled(this: this->m_pSubmit, a2: IsValidSubmission);
    if ( this->m_bAutoSubmit )
    {
      CBugUIPanel::OnSubmit(this);
      this->SetVisible(this, a2: false);
      this->m_bAutoSubmit = false;
    }
    *(float *)&v21[188] = this->m_flPauseTime;
    if ( *(float *)&v21[188] > 0.0 )
    {
      v10 = g_pVGuiSystem->__vftable;
      *(double *)&v21[180] = *(float *)&v21[188];
      if ( v10->GetFrameTime(this: g_pVGuiSystem) < *(float *)&v21[188] )
      {
        if ( this->m_pProgressDialog != nullptr )
        {
          *(double *)&v21[172] = this->m_flPauseTime;
          GetFrameTime = g_pVGuiSystem->GetFrameTime;
          *(_DWORD *)&v21[188] = 1065353216;
          *(_DWORD *)&v21[184] = 0;
          *(double *)&v21[172] = 1.0 - (*(double *)&v21[172] - GetFrameTime(this: g_pVGuiSystem)) * 0.06666666666666667;
          v20 = clamp<double,float,float>(
                  val: (const long double *)&v21[172],
                  minVal: (const float *)&v21[184],
                  maxVal: (const float *)&v21[188]);
          CBugReportUploadProgressDialog::SetProgress(this: this->m_pProgressDialog, progress: v20);
        }
      }
      else
      {
        m_pProgressDialog = this->m_pProgressDialog;
        this->m_flPauseTime = 0.0;
        if ( m_pProgressDialog != nullptr )
          m_pProgressDialog->Close(this: m_pProgressDialog);
        this->m_pProgressDialog = nullptr;
        CBugUIPanel::OnFinishBugReport(this);
        this->m_bWaitForFinish = true;
        if ( vgui::PHandle::Get(this: &this->m_hFinishedDialog) == nullptr )
        {
          v12 = (CBugReportFinishedDialog *)MemAlloc_Alloc(nSize: 0x214u);
          if ( v12 != nullptr )
            v13 = (CDragDropHelperPanel *)CBugReportFinishedDialog::CBugReportFinishedDialog(
                                            this: v12,
                                            parent: nullptr,
                                            name: "FinishDialog",
                                            title: "#Steam_FinishedBug_WorkingTitle",
                                            message: "#Steam_FinishedBug_Text");
          else
            v13 = nullptr;
          vgui::DHANDLE<CDragDropHelperPanel>::operator=(
            this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFinishedDialog,
            pPanel: v13);
          v14 = vgui::PHandle::Get(this: &this->m_hFinishedDialog);
          v14->__vftable[1].OnTick(this: v14);
          v15 = vgui::PHandle::Get(this: &this->m_hFinishedDialog);
          v16 = g_pVGuiInput;
          v17 = g_pVGuiInput->__vftable;
          v18 = v15->GetVPanel(this: v15);
          v17->SetAppModalSurface(this: v16, a2: v18);
        }
      }
    }
    if ( this->m_bWaitForFinish && vgui::PHandle::Get(this: &this->m_hFinishedDialog) == nullptr )
    {
      this->m_bWaitForFinish = false;
      this->Close(this);
    }
  }
  else
  {
    m_pBugReporter = this->m_pBugReporter;
    if ( m_pBugReporter != nullptr && !m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
    {
      if ( this->m_bCanSeeRepository )
      {
        if ( !this->m_bLoggedIn )
          _Warning(a1: "Bug UI disabled:  Couldn't log in to PVCS Tracker\n");
      }
      else
      {
        _Warning(a1: "Bug UI disabled:  Couldn't see repository\n");
      }
      strcpy(
        v21,
        "If you are accessing from VPN at home, try this:\n"
        "Set the ConVar 'bugreporter_username' to your Valve user name.\n"
        "Then call the command '_bugreporter_restart autoselect'.\n");
      _Warning(a1: v21);
    }
    this->SetVisible(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10281E80
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x102866D0
// Name: public: class vgui::Panel __near * vgui::PHandle::Get(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::PHandle::Get(vgui::PHandle *this)
{
  unsigned int v1; // esi
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // ebx
  char *ControlsModuleName; // eax

  if ( this->m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: this->m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x102AABA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::FileOpenDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::FileOpenDialog::GetMessageMap(vgui::FileOpenDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::FileOpenDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::FileOpenDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "FileOpenDialog");
  `vgui::FileOpenDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102AABD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::FileOpenDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::FileOpenDialog::GetAnimMap(vgui::FileOpenDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "FileOpenDialog");
}

//------------------------------------------------------------------------------
// Address: 0x102AABE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::FileOpenDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::FileOpenDialog::GetKBMap(vgui::FileOpenDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::FileOpenDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenDialog::GetKBMap'::`2'::s_pMap;
  `vgui::FileOpenDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenDialog");
  `vgui::FileOpenDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10318D60
// Name: _dynamic_initializer_for__bugreporter_includebsp__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_includebsp__()
{
  ConVar::ConVar(
    this: &bugreporter_includebsp,
    pName: "bugreporter_includebsp",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Include .bsp for internal bug submissions.");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_includebsp__);
}

//------------------------------------------------------------------------------
// Address: 0x10318D90
// Name: _dynamic_initializer_for__bugreporter_uploadasync__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_uploadasync__()
{
  ConVar::ConVar(
    this: &bugreporter_uploadasync,
    pName: "bugreporter_uploadasync",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Upload attachments asynchronously");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_uploadasync__);
}

//------------------------------------------------------------------------------
// Address: 0x10318DC0
// Name: _dynamic_initializer_for__bugreporter_snapshot_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_snapshot_delay__()
{
  ConVar::ConVar(
    this: &bugreporter_snapshot_delay,
    pName: "bugreporter_snapshot_delay",
    pDefaultValue: "15",
    flags: 0,
    pHelpString: "Frames to delay before taking snapshot");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_snapshot_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10318DF0
// Name: _dynamic_initializer_for__bugreporter_username__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_username__()
{
  ConVar::ConVar(
    this: &bugreporter_username,
    pName: "bugreporter_username",
    pDefaultValue: defaultValue,
    flags: 128,
    pHelpString: "Username to use for bugreporter");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_username__);
}

//------------------------------------------------------------------------------
// Address: 0x10318E20
// Name: _dynamic_initializer_for__bugreporter_console_bytes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_console_bytes__()
{
  ConVar::ConVar(
    this: &bugreporter_console_bytes,
    pName: "bugreporter_console_bytes",
    pDefaultValue: "15000",
    flags: 0,
    pHelpString: "Max # of console bytes to put into bug report body (full text still attached).");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_console_bytes__);
}

//------------------------------------------------------------------------------
// Address: 0x10318E90
// Name: _dynamic_initializer_for___bugreporter_restart_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for___bugreporter_restart_command__()
{
  ConCommand::ConCommand(
    this: &bugreporter_restart_command,
    pName: "_bugreporter_restart",
    callback: (void (__cdecl *)())bugreporter_restart,
    pHelpString: "Restarts bug reporter .dll",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___bugreporter_restart_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324A80
// Name: _dynamic_atexit_destructor_for__bugreporter_includebsp__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_includebsp__()
{
  ConVar::~ConVar(this: &bugreporter_includebsp);
}

//------------------------------------------------------------------------------
// Address: 0x10324A90
// Name: _dynamic_atexit_destructor_for__bugreporter_uploadasync__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_uploadasync__()
{
  ConVar::~ConVar(this: &bugreporter_uploadasync);
}

//------------------------------------------------------------------------------
// Address: 0x10324AA0
// Name: _dynamic_atexit_destructor_for__bugreporter_snapshot_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_snapshot_delay__()
{
  ConVar::~ConVar(this: &bugreporter_snapshot_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10324AB0
// Name: _dynamic_atexit_destructor_for__bugreporter_username__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_username__()
{
  ConVar::~ConVar(this: &bugreporter_username);
}

//------------------------------------------------------------------------------
// Address: 0x10324AC0
// Name: _dynamic_atexit_destructor_for__bugreporter_console_bytes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_console_bytes__()
{
  ConVar::~ConVar(this: &bugreporter_console_bytes);
}

//------------------------------------------------------------------------------
// Address: 0x10324AD0
// Name: _dynamic_atexit_destructor_for___bugreporter_restart_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___bugreporter_restart_command__()
{
  ConCommand::~ConCommand(this: &bugreporter_restart_command);
}

//------------------------------------------------------------------------------
// Address: 0x1013D390
// Name: __CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBugReporterDefaultUsername *__cdecl _CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_interface()
{
  return &g_ExposeBugreporterUsername;
}

//------------------------------------------------------------------------------
// Address: 0x1013E620
// Name: _bugreporter_restart
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall bugreporter_restart(int a1@<esi>, const CCommand *args)
{
  int v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  vgui::Panel *v5; // eax

  if ( args->m_nArgc > 1 )
  {
    v2 = 1;
    if ( _V_stricmp(s1: args->m_ppArgv[1], s2: "internal") != 0 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v3, s2: "autoselect") == 0 )
        v2 = 0;
    }
    else
    {
      v2 = 2;
    }
    ((void (__thiscall *)(CEngineBugReporter *, int))g_BugReporter.Shutdown)(a1: &g_BugReporter, a2: a1);
    if ( v2 != 0 )
    {
      v4 = "public";
      if ( v2 != 1 )
        v4 = "valve";
    }
    else
    {
      v4 = "autoselect";
    }
    _Msg(a1: "Changing to bugreporter(%s)\n", v4);
    v5 = vgui::PHandle::Get(this: &g_BugReporter.m_ParentPanel);
    ((void (__thiscall *)(CEngineBugReporter *, vgui::Panel *))g_BugReporter.InstallBugReportingUI)(
      a1: &g_BugReporter,
      a2: v5);
  }
  else
  {
    _Msg(a1: "__bugreporter_restart <internal | external | autoselect>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10318E50
// Name: _dynamic_initializer_for__g_UploadQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UploadQueue__()
{
  CTSQueue<int,0,1>::CTSQueue<int,0,1>(this: (CTSQueue<int,0,1> *)&g_UploadQueue);
  g_UploadQueue.m_bNoQueue = false;
  return atexit(func: dynamic_atexit_destructor_for__g_UploadQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x10318E70
// Name: _dynamic_initializer_for____g_CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_reg,
           fn: (void *(__cdecl *)())_CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_interface,
           pName: "BugReporterUserName001");
}

//------------------------------------------------------------------------------
// Address: 0x10318EC0
// Name: _dynamic_initializer_for__bug_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bug_command__()
{
  ConCommand::ConCommand(
    this: &bug_command,
    pName: "bug",
    callback: (void (__cdecl *)())bug,
    pHelpString: "Show the bug reporting UI.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318EF0
// Name: _dynamic_initializer_for__g_BuildNumber__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_BuildNumber__()
{
  CBuildNumber::ComputeBuildNumber(this: &g_BuildNumber);
}

//------------------------------------------------------------------------------
// Address: 0x10324AE0
// Name: _dynamic_atexit_destructor_for__bug_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bug_command__()
{
  ConCommand::~ConCommand(this: &bug_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324AF0
// Name: _dynamic_atexit_destructor_for__g_UploadQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UploadQueue__()
{
  CTSQueue<int,0,1>::Purge(this: (CTSQueue<int,0,1> *)&g_UploadQueue);
  free(pMem: g_UploadQueue.m_queue.m_Head.value.pNode);
  CTSListBase::Detach(this: &g_UploadQueue.m_queue.m_FreeNodes);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1013C530
// Name: public: class vgui::Panel __near * vgui::PHandle::operator=(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDragDropHelperPanel *__thiscall vgui::PHandle::operator=(vgui::PHandle *this, CDragDropHelperPanel *pPanel)
{
  return vgui::DHANDLE<CDragDropHelperPanel>::operator=((vgui::DHANDLE<CDragDropHelperPanel> *)this, pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1013C540
// Name: unsigned long GetRam(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetRam()
{
  _MEMORYSTATUS stat; // [esp+0h] [ebp-20h] BYREF

  GlobalMemoryStatus(lpBuffer: &stat);
  return stat.dwTotalPhys >> 20;
}

//------------------------------------------------------------------------------
// Address: 0x1013C560
// Name: char const __near * GetInternalBugReporterDLL(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetInternalBugReporterDLL()
{
  int v0; // eax
  const char *result; // eax
  int v2; // eax
  bool v3; // zf
  const char *pBugReportedDLL; // [esp+4h] [ebp-4h] BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-remotebug", a3: 0) != 0 )
    return "bugreporter_remote";
  pBugReportedDLL = nullptr;
  v2 = _CommandLine();
  v3 = (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v2 + 12))(
         a1: v2,
         a2: "-bugreporterdll",
         a3: &pBugReportedDLL) == 0;
  result = pBugReportedDLL;
  if ( v3 )
    return "bugreporter_filequeue";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013C5C0
// Name: void DisplaySystemVersion(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisplaySystemVersion(char *osversion, int maxlen)
{
  bool v2; // zf
  const char *v3; // eax
  char build[256]; // [esp+8h] [ebp-19Ch] BYREF
  _OSVERSIONINFOEXA osvi; // [esp+108h] [ebp-9Ch] BYREF

  *osversion = 0;
  memset(dst: (unsigned __int8 *)&osvi, value: 0, count: sizeof(osvi));
  osvi.dwOSVersionInfoSize = 156;
  if ( !GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi) )
  {
    osvi.dwOSVersionInfoSize = 148;
    if ( !GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi) )
    {
      V_strncpy(pDest: osversion, pSrc: "Unable to get Version", maxLen: maxlen);
      return;
    }
  }
  if ( osvi.dwPlatformId == 0 )
  {
    V_strncat(pDest: osversion, pSrc: "Win32s ", destBufferSize: maxlen, max_chars_to_copy: -1);
    return;
  }
  if ( osvi.dwPlatformId != 1 )
  {
    if ( osvi.dwPlatformId != 2 )
      return;
    if ( osvi.dwMajorVersion <= 4 )
      V_strncat(pDest: osversion, pSrc: "Windows NT ", destBufferSize: maxlen, max_chars_to_copy: -1);
    if ( osvi.dwMajorVersion == 5 )
    {
      if ( osvi.dwMinorVersion != 0
        || (V_strncat(pDest: osversion, pSrc: "Windows 2000 ", destBufferSize: maxlen, max_chars_to_copy: -1),
            osvi.dwMajorVersion == 5) )
      {
        if ( osvi.dwMinorVersion != 1 )
        {
LABEL_18:
          v2 = !IsUserAnAdmin();
          v3 = "no";
          if ( v2 )
            v3 = "yes";
          V_snprintf(
            pDest: build,
            maxLen: 256,
            pFormat: "%s (Build %d) version %d.%d (LimitedUser: %s)",
            osvi.szCSDVersion,
            LOWORD(osvi.dwBuildNumber),
            osvi.dwMajorVersion,
            osvi.dwMinorVersion,
            v3);
          V_strncat(pDest: osversion, pSrc: build, destBufferSize: maxlen, max_chars_to_copy: -1);
          return;
        }
        V_strncat(pDest: osversion, pSrc: "Windows XP ", destBufferSize: maxlen, max_chars_to_copy: -1);
      }
    }
    if ( osvi.dwMajorVersion == 6 )
      V_strncat(pDest: osversion, pSrc: "Windows Vista ", destBufferSize: maxlen, max_chars_to_copy: -1);
    if ( osvi.dwMajorVersion == 7 )
      V_strncat(pDest: osversion, pSrc: "Windows 7 ", destBufferSize: maxlen, max_chars_to_copy: -1);
    goto LABEL_18;
  }
  if ( osvi.dwMajorVersion == 4 )
  {
    if ( osvi.dwMinorVersion != 0 )
      goto LABEL_31;
    V_strncat(pDest: osversion, pSrc: "95 ", destBufferSize: maxlen, max_chars_to_copy: -1);
    if ( osvi.szCSDVersion[1] == 67 || osvi.szCSDVersion[1] == 66 )
      V_strncat(pDest: osversion, pSrc: "OSR2 ", destBufferSize: maxlen, max_chars_to_copy: -1);
    if ( osvi.dwMajorVersion == 4 )
    {
LABEL_31:
      if ( osvi.dwMinorVersion != 10 )
        goto LABEL_32;
      V_strncat(pDest: osversion, pSrc: "98 ", destBufferSize: maxlen, max_chars_to_copy: -1);
      if ( osvi.szCSDVersion[1] == 65 )
        V_strncat(pDest: osversion, pSrc: "SE ", destBufferSize: maxlen, max_chars_to_copy: -1);
      if ( osvi.dwMajorVersion == 4 )
      {
LABEL_32:
        if ( osvi.dwMinorVersion == 90 )
          V_strncat(pDest: osversion, pSrc: "Me ", destBufferSize: maxlen, max_chars_to_copy: -1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C8E0
// Name: public: void CBugReportUploadProgressDialog::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReportUploadProgressDialog::SetProgress(CBugReportUploadProgressDialog *this, float progress)
{
  ((void (__stdcall *)(_DWORD))this->m_pProgress->SetProgress)(a1: LODWORD(progress));
}

//------------------------------------------------------------------------------
// Address: 0x1013C900
// Name: public: virtual void CBugReportUploadProgressDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReportUploadProgressDialog::PerformLayout(CBugReportUploadProgressDialog *this)
{
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013C930
// Name: public: CBugReportFinishedDialog::CBugReportFinishedDialog(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBugReportFinishedDialog *__thiscall CBugReportFinishedDialog::CBugReportFinishedDialog(
        CBugReportFinishedDialog *this,
        vgui::Panel *parent,
        const char *name,
        const char *title,
        const char *message)
{
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBugReportFinishedDialog_vtbl *)&CBugReportFinishedDialog::`vftable';
  vgui::Panel::SetSize(this, wide: 300, tall: 160);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Panel::MoveToFront(this);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "CloseBtn",
           text: "#OK",
           pActionSignalTarget: this,
           pCmd: "Close");
  else
    v7 = nullptr;
  this->m_pOk = v7;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\BugReporterUploadFinished.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::EditablePanel::SetControlString(this, controlName: "InfoLabel", string: message);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013C9E0
// Name: public: virtual void CBugReportFinishedDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReportFinishedDialog::OnCommand(CBugReportFinishedDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "Close") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    this->MarkForDeletion(this);
    this->OnClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CA30
// Name: public: virtual void CBugReportFinishedDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReportFinishedDialog::PerformLayout(CBugReportFinishedDialog *this)
{
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: true);
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013CA60
// Name: public: static char const __near * CBugUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBugUIPanel::GetPanelClassName()
{
  return "CBugUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1013CAC0
// Name: protected: void CBugUIPanel::GetDataFileBase(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::GetDataFileBase(CBugUIPanel *this, const char *suffix, char *buf, int bufsize)
{
  char who[128]; // [esp+4h] [ebp-A4h] BYREF
  tm t; // [esp+84h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &t);
  V_strncpy(pDest: who, pSrc: suffix, maxLen: 128);
  _V_strlower(start: who);
  if ( this->m_pBugReporter != nullptr && this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
    V_snprintf(pDest: buf, maxLen: bufsize, pFormat: "%i_%02i_%02i", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
  else
    V_snprintf(pDest: buf, maxLen: bufsize, pFormat: "%i_%02i_%02i_%s", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, who);
}

//------------------------------------------------------------------------------
// Address: 0x1013CB80
// Name: protected: char const __near * CBugUIPanel::GetRepositoryURL(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBugUIPanel::GetRepositoryURL(CBugUIPanel *this)
{
  const char *result; // eax

  result = this->m_pBugReporter->GetRepositoryURL(this: this->m_pBugReporter);
  if ( result == nullptr )
    return "\\\\fileserver\\bugs";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013CBA0
// Name: protected: char const __near * CBugUIPanel::GetSubmissionURL(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBugUIPanel::GetSubmissionURL(CBugUIPanel *this, int bugid)
{
  char *result; // eax
  const char *v4; // eax

  result = (char *)this->m_pBugReporter->GetSubmissionURL(this: this->m_pBugReporter);
  if ( result == nullptr )
  {
    v4 = this->m_pBugReporter->GetRepositoryURL(this: this->m_pBugReporter);
    if ( v4 == nullptr )
      v4 = "\\\\fileserver\\bugs";
    V_snprintf(pDest: url, maxLen: 512, pFormat: "%s/%i", v4, bugid);
    return url;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013CC00
// Name: protected: void CBugUIPanel::RepopulateMaps(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::RepopulateMaps(CBugUIPanel *this, int area_index, const char *default_level)
{
  int v4; // ebx
  const char *v5; // edi
  int c; // [esp+Ch] [ebp-Ch]
  int id; // [esp+10h] [ebp-8h]
  int item; // [esp+14h] [ebp-4h]

  c = this->m_pBugReporter->GetLevelCount(this: this->m_pBugReporter, a2: area_index);
  item = -1;
  vgui::ComboBox::RemoveAll(this: this->m_pMapNumber);
  v4 = 0;
  if ( c <= 0 )
    goto LABEL_7;
  do
  {
    v5 = this->m_pBugReporter->GetLevel(this: this->m_pBugReporter, a2: area_index, a3: v4);
    id = this->m_pMapNumber->AddItem_2(this: this->m_pMapNumber, a2: v5, a3: nullptr);
    if ( _V_stricmp(s1: default_level, s2: v5) == 0 )
      item = id;
    ++v4;
  }
  while ( v4 < c );
  if ( item < 0 )
LABEL_7:
    vgui::ComboBox::ActivateItemByRow(this: this->m_pMapNumber, row: 0);
  else
    this->m_pMapNumber->ActivateItem(this: this->m_pMapNumber, a2: item);
}

//------------------------------------------------------------------------------
// Address: 0x1013CCC0
// Name: protected: virtual void CBugUIPanel::OnChooseArea(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnChooseArea(CBugUIPanel *this, vgui::ComboBox *panel)
{
  const char *InternalBugReporterDLL; // eax
  int ActiveItem; // edi
  CClientState *BaseLocalClient; // eax
  const char *v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // ebx
  int v10; // edi
  const char *v11; // eax
  const char *defaultOwner; // [esp+10h] [ebp+8h]

  if ( panel == this->m_pGameArea )
  {
    InternalBugReporterDLL = GetInternalBugReporterDLL();
    if ( _V_strcmp(s1: "bugreporter_filequeue", s2: InternalBugReporterDLL) == 0 )
    {
      ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pGameArea);
      if ( GetBaseLocalClient()->m_nSignonState == 6 )
      {
        BaseLocalClient = GetBaseLocalClient();
        CBugUIPanel::RepopulateMaps(this, area_index: ActiveItem, default_level: BaseLocalClient->m_szLevelNameShort);
      }
      else
      {
        CBugUIPanel::RepopulateMaps(this, area_index: ActiveItem, default_level: "console");
      }
    }
  }
  else if ( panel == this->m_pMapNumber )
  {
    v6 = GetInternalBugReporterDLL();
    if ( _V_strcmp(s1: "bugreporter_filequeue", s2: v6) == 0 )
    {
      v7 = vgui::ComboBox::GetActiveItem(this: this->m_pGameArea);
      v8 = vgui::ComboBox::GetActiveItem(this: this->m_pMapNumber);
      defaultOwner = this->m_pBugReporter->GetLevelOwner(this: this->m_pBugReporter, a2: v7, a3: v8);
      v9 = this->m_pBugReporter->GetDisplayNameCount(this: this->m_pBugReporter);
      v10 = 0;
      if ( v9 > 0 )
      {
        while ( 1 )
        {
          v11 = this->m_pBugReporter->GetUserNameA(this: this->m_pBugReporter, a2: v10);
          if ( _V_stricmp(s1: v11, s2: defaultOwner) == 0 )
            break;
          if ( ++v10 >= v9 )
            return;
        }
        this->m_pAssignTo->ActivateItem(this: this->m_pAssignTo, a2: v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CDF0
// Name: protected: bool CBugUIPanel::IsValidEmailAddress(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBugUIPanel::IsValidEmailAddress(CBugUIPanel *this, char *email)
{
  char v2; // cl
  char *v3; // esi
  char v4; // al
  int v5; // eax
  unsigned __int8 *v6; // esi
  int v7; // eax

  if ( email == nullptr || strlen(email) < 5 )
    return false;
  v3 = email;
  if ( *email != v2 )
  {
    do
    {
      if ( isalnum(c: *v3) == 0 )
      {
        v4 = *v3;
        if ( *v3 != 46 && v4 != 45 && v4 != 64 && v4 != 95 )
          return false;
      }
    }
    while ( *++v3 != 0 );
  }
  if ( isalnum(c: *email) == 0 )
    return false;
  strstr(str1: (unsigned __int8 *)email, str2: "@");
  if ( v5 == 0 )
    return false;
  v6 = (unsigned __int8 *)(v5 + 1);
  if ( isalnum(c: *(char *)(v5 + 1)) == 0 )
    return false;
  strstr(str1: v6, str2: ".");
  if ( v7 == 0 )
    return false;
  return isalnum(c: *(char *)(v7 + 1)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013CEC0
// Name: protected: bool CBugUIPanel::IsValidSubmission(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBugUIPanel::IsValidSubmission(CBugUIPanel *this, bool verbose)
{
  int v4; // eax
  bool v5; // al
  vgui::TextEntry *m_pTitle; // ecx
  bool v7; // bl
  IBugReporter_vtbl *v8; // edi
  int ActiveItem; // eax
  const char *v10; // eax
  _BYTE v11[4096]; // [esp+4h] [ebp-1250h] BYREF
  char pDest[256]; // [esp+1004h] [ebp-250h] BYREF
  char v13[256]; // [esp+1104h] [ebp-150h] BYREF
  char email[80]; // [esp+1204h] [ebp-50h] BYREF

  if ( this->m_pBugReporter == nullptr )
    return false;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-remotebug", a3: 0) != 0 )
    return true;
  v5 = this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter);
  m_pTitle = this->m_pTitle;
  v7 = v5;
  v13[0] = 0;
  v11[0] = 0;
  m_pTitle->GetText_2(this: m_pTitle, a2: v13, a3: 256);
  if ( v13[0] == 0 )
  {
    if ( verbose )
    {
      _Warning(a1: "Bug must have a title\n");
      return false;
    }
    return false;
  }
  if ( v7 )
  {
    this->m_pDescription->GetText_2(this: this->m_pDescription, a2: v11, a3: 4096);
    if ( v11[0] == 0 )
    {
      if ( verbose )
      {
        _Warning(a1: "Bug must have a description\n");
        return false;
      }
      return false;
    }
  }
  else
  {
    if ( vgui::ComboBox::GetActiveItem(this: this->m_pSeverity) < 0 )
    {
      if ( verbose )
      {
        _Warning(a1: "Severity not set!\n");
        return false;
      }
      return false;
    }
    if ( vgui::ComboBox::GetActiveItem(this: this->m_pAssignTo) < 0 )
    {
LABEL_18:
      if ( verbose )
      {
        _Warning(a1: "Owner not set!\n");
        return false;
      }
      return false;
    }
  }
  v8 = this->m_pBugReporter->__vftable;
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pAssignTo);
  v10 = v8->GetDisplayName(this: this->m_pBugReporter, a2: ActiveItem);
  V_strncpy(pDest, pSrc: v10, maxLen: 256);
  if ( v7 )
  {
    if ( vgui::ComboBox::GetActiveItem(this: this->m_pReportType) > 0 )
    {
      this->m_pEmail->GetText_2(this: this->m_pEmail, a2: email, a3: 80);
      return email[0] == 0 || CBugUIPanel::IsValidEmailAddress(this, email);
    }
LABEL_28:
    if ( verbose )
      _Warning(a1: "ReportType not set!\n");
    return false;
  }
  if ( _V_stricmp(s1: pDest, s2: "<<Unassigned>>") == 0 )
    goto LABEL_18;
  if ( vgui::ComboBox::GetActiveItem(this: this->m_pPriority) < 0 )
  {
    if ( verbose )
    {
      _Warning(a1: "Priority not set!\n");
      return false;
    }
    return false;
  }
  if ( vgui::ComboBox::GetActiveItem(this: this->m_pReportType) < 0 )
    goto LABEL_28;
  if ( vgui::ComboBox::GetActiveItem(this: this->m_pGameArea) < 0 )
  {
    if ( verbose )
    {
      _Warning(a1: "Area not set!\n");
      return false;
    }
    return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1013D140
// Name: protected: bool CBugUIPanel::AddFileToZip(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugUIPanel::AddFileToZip(CBugUIPanel *this, const char *relative)
{
  HZIP__ *ZipZ; // eax
  char outname[512]; // [esp+4h] [ebp-520h] BYREF
  char fullpath[512]; // [esp+204h] [ebp-320h] BYREF
  char basename[256]; // [esp+404h] [ebp-120h] BYREF
  char extension[32]; // [esp+504h] [ebp-20h] BYREF

  if ( this->m_hZip == nullptr )
  {
    ZipZ = CreateZipZ(z: nullptr, len: 0x1000000u, flags: 3u);
    this->m_hZip = ZipZ;
    if ( ZipZ == nullptr )
      return 0;
  }
  if ( g_pFileSystem->RelativePathToFullPath(
         this: g_pFileSystem,
         a2: relative,
         a3: "GAME",
         a4: fullpath,
         a5: 512,
         a6: 0,
         a7: 0) == nullptr )
    return 0;
  V_ExtractFileExtension(path: relative, dest: extension, destSize: 32);
  V_FileBase(in: relative, out: basename, maxlen: 256);
  V_snprintf(pDest: outname, maxLen: 512, pFormat: "%s.%s", basename, extension);
  ZipAdd(hz: this->m_hZip, dstzn: outname, src: fullpath, len: 0, flags: 2u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013D220
// Name: void NonFileSystem_CreatePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NonFileSystem_CreatePath(const char *path)
{
  char *i; // esi
  char v2; // bl
  char temppath[512]; // [esp+4h] [ebp-200h] BYREF

  V_strncpy(pDest: temppath, pSrc: path, maxLen: 512);
  for ( i = &temppath[1]; *i != 0; ++i )
  {
    v2 = *i;
    if ( *i == 47 || v2 == 92 )
    {
      *i = 0;
      _mkdir(path: temppath);
      *i = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D280
// Name: protected: bool CBugUIPanel::UploadFile(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBugUIPanel::UploadFile(CBugUIPanel *this, const char *local, const char *remote, bool bDeleteLocal)
{
  const char *v4; // ebx
  void *v5; // edi
  BOOL v7; // eax
  DWORD LastError; // eax
  _iobuf *v9; // eax
  _iobuf *v10; // ebx
  unsigned __int8 *v11; // eax
  int v12; // ebx
  unsigned int v13; // esi
  int nLocalFileSize; // [esp+Ch] [ebp-8h]
  _iobuf *r; // [esp+10h] [ebp-4h]
  unsigned __int8 *pCopyBuf; // [esp+20h] [ebp+Ch]
  bool pCopyBuf_3; // [esp+23h] [ebp+Fh]

  v4 = local;
  _Msg(a1: "Uploading %s to %s\n", local, remote);
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: local, a3: "rb", a4: 0);
  if ( v5 == nullptr )
  {
    _Warning(a1: "CBugUIPanel::UploadFile:  Unable to open local path '%s'\n", local);
    return false;
  }
  nLocalFileSize = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
  if ( nLocalFileSize <= 0 )
  {
    _Warning(a1: "CBugUIPanel::UploadFile:  Local file has 0 size '%s'\n", local);
LABEL_5:
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    return false;
  }
  NonFileSystem_CreatePath(path: remote);
  if ( g_pFileSystem->IsSteam(this: g_pFileSystem) )
  {
    v9 = (_iobuf *)va(format: "%s", remote);
    v10 = fopen(file: v9, mode: "wb");
    r = v10;
    if ( v10 == nullptr )
    {
      _Warning(a1: "CBugUIPanel::UploadFile:  Unable to open remote path '%s'\n", remote);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
      return false;
    }
    v11 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x200000u);
    pCopyBuf = v11;
    if ( v11 == nullptr )
    {
      _Warning(a1: "CBugUIPanel::UploadFile:  Unable to allocate copy buffer of %d bytes\n", 0x200000);
      fclose(stream: v10);
      goto LABEL_5;
    }
    v12 = nLocalFileSize;
    while ( 1 )
    {
      v13 = v12;
      if ( v12 >= 0x200000 )
        v13 = 0x200000;
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v11, a3: v13, a4: v5);
      fwrite(buffer: pCopyBuf, size: v13, count: 1u, stream: r);
      v12 -= v13;
      if ( v12 <= 0 )
        break;
      v11 = pCopyBuf;
    }
    fclose(stream: r);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    free(pMem: pCopyBuf);
    v4 = local;
    pCopyBuf_3 = true;
  }
  else
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    v7 = CopyFileA(lpExistingFileName: local, lpNewFileName: remote, bFailIfExists: false);
    pCopyBuf_3 = v7;
    if ( !v7 )
    {
      LastError = GetLastError();
      _Warning(a1: "Failed to upload %s, error %d\n", local, LastError);
      return false;
    }
  }
  if ( bDeleteLocal )
    unlink(path: v4);
  return pCopyBuf_3;
}

//------------------------------------------------------------------------------
// Address: 0x1013D4B0
// Name: protected: bool CBugUIPanel::AutoFillToken(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugUIPanel::AutoFillToken(CBugUIPanel *this, const char *token, bool partial)
{
  const char *v5; // eax
  int v6; // ebx
  const char *v7; // edi
  const char *v8; // eax
  int v9; // ebx
  int i; // edi
  const char *v11; // eax
  const char *v12; // eax
  int v13; // ebx
  int j; // edi
  const char *v15; // eax
  const char *v16; // eax
  int v17; // ebx
  int k; // edi
  const char *v19; // eax
  const char *v20; // eax
  int v21; // ebx
  int m; // edi
  const char *v23; // eax
  const char *v24; // eax
  const char *userName; // [esp+4h] [ebp-8h]
  int c; // [esp+8h] [ebp-4h]

  if ( this->m_pBugReporter == nullptr )
    return 1;
  v5 = "PARTIAL";
  if ( !partial )
    v5 = "FULL";
  _Msg(a1: "AUTOFILL: %s (%s)\n", token, v5);
  v6 = 0;
  c = this->m_pBugReporter->GetDisplayNameCount(this: this->m_pBugReporter);
  if ( c > 0 )
  {
    do
    {
      v7 = this->m_pBugReporter->GetDisplayName(this: this->m_pBugReporter, a2: v6);
      v8 = this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: v7);
      userName = v8;
      if ( partial )
      {
        if ( V_stristr(pStr: v8, pSearch: token) != nullptr || V_stristr(pStr: v7, pSearch: token) != nullptr )
        {
LABEL_9:
          _Msg(a1: "  ASSIGNED TO: %s\n", userName);
          this->m_pAssignTo->ActivateItem(this: this->m_pAssignTo, a2: v6);
          return 1;
        }
      }
      else if ( _V_stricmp(s1: v8, s2: token) == 0 || _V_stricmp(s1: v7, s2: token) == 0 )
      {
        goto LABEL_9;
      }
      ++v6;
    }
    while ( v6 < c );
  }
  v9 = this->m_pBugReporter->GetSeverityCount(this: this->m_pBugReporter);
  for ( i = 0; i < v9; ++i )
  {
    v11 = this->m_pBugReporter->GetSeverity(this: this->m_pBugReporter, a2: i);
    if ( partial )
    {
      if ( V_stristr(pStr: v11, pSearch: token) != nullptr )
      {
LABEL_16:
        v12 = this->m_pBugReporter->GetSeverity(this: this->m_pBugReporter, a2: i);
        _Msg(a1: "  SEVERITY: %s\n", v12);
        this->m_pSeverity->ActivateItem(this: this->m_pSeverity, a2: i);
        return 1;
      }
    }
    else if ( _V_stricmp(s1: v11, s2: token) == 0 )
    {
      goto LABEL_16;
    }
  }
  v13 = this->m_pBugReporter->GetReportTypeCount(this: this->m_pBugReporter);
  for ( j = 0; j < v13; ++j )
  {
    v15 = this->m_pBugReporter->GetReportType(this: this->m_pBugReporter, a2: j);
    if ( partial )
    {
      if ( V_stristr(pStr: v15, pSearch: token) != nullptr )
      {
LABEL_22:
        v16 = this->m_pBugReporter->GetReportType(this: this->m_pBugReporter, a2: j);
        _Msg(a1: "  REPORT TYPE: %s\n", v16);
        this->m_pReportType->ActivateItem(this: this->m_pReportType, a2: j);
        return 1;
      }
    }
    else if ( _V_stricmp(s1: v15, s2: token) == 0 )
    {
      goto LABEL_22;
    }
  }
  v17 = this->m_pBugReporter->GetPriorityCount(this: this->m_pBugReporter);
  for ( k = 0; k < v17; ++k )
  {
    v19 = this->m_pBugReporter->GetPriority(this: this->m_pBugReporter, a2: k);
    if ( partial )
    {
      if ( V_stristr(pStr: v19, pSearch: token) != nullptr )
      {
LABEL_28:
        v20 = this->m_pBugReporter->GetPriority(this: this->m_pBugReporter, a2: k);
        _Msg(a1: "  PRIORITY: %s\n", v20);
        this->m_pPriority->ActivateItem(this: this->m_pPriority, a2: k);
        return 1;
      }
    }
    else if ( _V_stricmp(s1: v19, s2: token) == 0 )
    {
      goto LABEL_28;
    }
  }
  v21 = this->m_pBugReporter->GetAreaCount(this: this->m_pBugReporter);
  for ( m = 0; m < v21; ++m )
  {
    v23 = this->m_pBugReporter->GetArea(this: this->m_pBugReporter, a2: m);
    if ( partial )
    {
      if ( V_stristr(pStr: v23, pSearch: token) != nullptr )
      {
LABEL_34:
        v24 = this->m_pBugReporter->GetArea(this: this->m_pBugReporter, a2: m);
        _Msg(a1: "  AREA: %s\n", v24);
        this->m_pGameArea->ActivateItem(this: this->m_pGameArea, a2: m);
        return 1;
      }
    }
    else if ( _V_stricmp(s1: v23, s2: token) == 0 )
    {
      goto LABEL_34;
    }
  }
  if ( _V_stricmp(s1: token, s2: "screenshot") != 0 )
  {
    if ( _V_stricmp(s1: token, s2: "noscreenshot") != 0 )
    {
      return 0;
    }
    else
    {
      this->m_fAutoAddScreenshot = 2;
      return 1;
    }
  }
  else
  {
    this->m_fAutoAddScreenshot = 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D850
// Name: protected: void CBugUIPanel::CheckContinueQueryingSteamForCSERList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::CheckContinueQueryingSteamForCSERList(CBugUIPanel *this)
{
  CSteam3Client *v2; // eax
  unsigned __int16 v3; // bx
  unsigned int unIP; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 usPort; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_bQueryingSteamForCSER && Steam3Client()->m_pSteamUtils != nullptr )
  {
    v2 = Steam3Client();
    v2->m_pSteamUtils->GetCSERIPPort(this: v2->m_pSteamUtils, a2: &unIP, a3: &usPort);
    if ( unIP != 0 )
    {
      v3 = usPort;
      netadr_s::SetIP(this: &this->m_cserIP, unIP);
      netadr_s::SetPort(this: &this->m_cserIP, newport: v3);
      this->m_bQueryingSteamForCSER = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D8C0
// Name: public: virtual int CBugUIPanel::GetBugSubmissionCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugUIPanel::GetBugSubmissionCount(CBugUIPanel *this)
{
  return this->m_BugSub;
}

//------------------------------------------------------------------------------
// Address: 0x1013D8E0
// Name: public: virtual void CEngineBugReporter::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineBugReporter::Init(CEngineBugReporter *this)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_ParentPanel,
    pPanel: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1013D950
// Name: public: virtual bool CEngineBugReporter::ShouldPause(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineBugReporter::ShouldPause(CEngineBugReporter *this)
{
  CClientState *BaseLocalClient; // ecx
  int result; // eax

  if ( g_pBugUI == nullptr || !g_pBugUI->IsVisible(this: g_pBugUI) && !g_pBugUI->m_bTakingSnapshot )
    return 0;
  BaseLocalClient = GetBaseLocalClient();
  result = 1;
  if ( BaseLocalClient->m_nMaxClients != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013D990
// Name: public: virtual bool CEngineBugReporter::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineBugReporter::IsVisible(CEngineBugReporter *this)
{
  return g_pBugUI != nullptr && g_pBugUI->IsVisible(this: g_pBugUI);
}

//------------------------------------------------------------------------------
// Address: 0x1013D9C0
// Name: public: virtual int CEngineBugReporter::GetBugSubmissionCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineBugReporter::GetBugSubmissionCount(CEngineBugReporter *this)
{
  int result; // eax

  result = 0;
  if ( g_pBugUI != nullptr )
    return g_pBugUI->GetBugSubmissionCount(this: g_pBugUI);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013D9E0
// Name: public: virtual void CEngineBugReporter::ClearBugSubmissionCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineBugReporter::ClearBugSubmissionCount(CEngineBugReporter *this)
{
  if ( g_pBugUI != nullptr )
    g_pBugUI->ClearBugSubmissionCount(this: g_pBugUI);
}

//------------------------------------------------------------------------------
// Address: 0x1013DA00
// Name: protected: int CBugUIPanel::GetArea(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugUIPanel::GetArea(CBugUIPanel *this)
{
  CBugUIPanel *v1; // esi
  unsigned int v2; // edx
  char *v3; // eax
  char *v4; // eax
  IBugReporter *m_pBugReporter; // ecx
  int (__thiscall *GetAreaMapCount)(IBugReporter *); // edx
  const char *v8; // eax
  char *v9; // esi
  char *v10; // eax
  const char *v11; // ebx
  int v12; // edi
  _BYTE *v13; // esi
  int v14; // eax
  IBugReporter *v15; // ecx
  int (__thiscall *v16)(IBugReporter *); // eax
  int v17; // esi
  char szDirectory[260]; // [esp+Ch] [ebp-314h] BYREF
  char szAreaMap[260]; // [esp+110h] [ebp-210h] BYREF
  char mapname[256]; // [esp+214h] [ebp-10Ch] BYREF
  char *gamedir; // [esp+314h] [ebp-Ch]
  CBugUIPanel *v22; // [esp+318h] [ebp-8h]
  int i; // [esp+31Ch] [ebp-4h]

  v1 = this;
  v22 = this;
  memset(mapname, 0, sizeof(mapname));
  v2 = 80;
  if ( host_state.worldmodel != nullptr )
  {
    v3 = (char *)modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
    CL_SetupMapName(pName: v3, pFixedName: mapname, maxlen: 256);
    v2 = 78 - strlen(mapname);
  }
  v1->m_pTitle->SetMaximumCharCount(this: v1->m_pTitle, a2: v2);
  v4 = _V_strrchr(s: com_gamedir, c: 92);
  m_pBugReporter = v1->m_pBugReporter;
  gamedir = v4 + 1;
  GetAreaMapCount = m_pBugReporter->GetAreaMapCount;
  i = 0;
  if ( GetAreaMapCount(this: m_pBugReporter) > 0 )
  {
    while ( 1 )
    {
      v8 = v1->m_pBugReporter->GetAreaMap(this: v1->m_pBugReporter, a2: i);
      _V_strcpy(dest: szAreaMap, src: v8);
      v9 = _V_strrchr(s: szAreaMap, c: 64);
      v10 = _V_strrchr(s: szAreaMap, c: 37);
      v11 = v10;
      if ( v9 == nullptr )
        break;
      if ( v10 != nullptr )
      {
        v12 = v10 - v9 - 1;
        v13 = v9 + 1;
        v11 = v10 + 1;
      }
      else
      {
        v13 = v9 + 1;
        v12 = _V_strlen(str: szAreaMap) + szAreaMap - v13;
      }
      _V_memmove(dest: szDirectory, src: v13, count: v12);
      szDirectory[v12] = 0;
      if ( v13 != nullptr )
      {
        v14 = _V_strcmp(s1: szDirectory, s2: gamedir);
        if ( v11 != nullptr )
        {
          if ( v14 == 0 && _V_strstr(s1: mapname, search: v11) != nullptr )
            return i;
        }
        else if ( v14 == 0 )
        {
          return i;
        }
      }
      v15 = v22->m_pBugReporter;
      v16 = v15->GetAreaMapCount;
      v17 = ++i;
      if ( v17 >= v16(this: v15) )
        return 0;
      v1 = v22;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013DBC0
// Name: public: void CUtlMemory<struct CBugUIPanel::includedfile,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBugUIPanel::includedfile,int>::Grow(
        CUtlMemory<CBugUIPanel::includedfile,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBugUIPanel::includedfile *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 9;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBugUIPanel::includedfile *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBugUIPanel::includedfile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DC50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013DC90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013DD80
// Name: protected: virtual void CBugUIPanel::OnChooseVMFFolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnChooseVMFFolder(CBugUIPanel *this)
{
  vgui::DHANDLE<vgui::DirectorySelectDialog> *p_m_hDirectorySelectDialog; // edi
  vgui::DirectorySelectDialog *v3; // eax
  CDragDropHelperPanel *v4; // eax
  vgui::DirectorySelectDialog *v5; // eax
  vgui::Panel *v6; // eax

  p_m_hDirectorySelectDialog = &this->m_hDirectorySelectDialog;
  if ( vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog) == nullptr )
  {
    v3 = (vgui::DirectorySelectDialog *)MemAlloc_Alloc(nSize: 0x47Cu);
    if ( v3 != nullptr )
      v4 = (CDragDropHelperPanel *)vgui::DirectorySelectDialog::DirectorySelectDialog(
                                     this: v3,
                                     parent: this,
                                     title: "Choose .vmf folder");
    else
      v4 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)p_m_hDirectorySelectDialog,
      pPanel: v4);
  }
  this->m_bAddVMF = false;
  v5 = (vgui::DirectorySelectDialog *)vgui::PHandle::Get(this: p_m_hDirectorySelectDialog);
  vgui::DirectorySelectDialog::SetStartDirectory(this: v5, path: this->m_szVMFContentDirFullpath);
  v6 = vgui::PHandle::Get(this: p_m_hDirectorySelectDialog);
  v6->__vftable[1].IsEnabled(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1013DDF0
// Name: protected: void CBugUIPanel::OnIncludeFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnIncludeFile(CBugUIPanel *this)
{
  vgui::FileOpenDialog *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // eax
  char startPath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_pBugReporter == nullptr || !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
  {
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
    {
      v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
      if ( v2 != nullptr )
        v3 = (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                       this: v2,
                                       parent: this,
                                       title: "Choose file to include",
                                       bOpenOnly: true,
                                       pContextKeyValues: nullptr);
      else
        v3 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
        pPanel: v3);
      if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
      {
        v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
        ((void (__thiscall *)(vgui::Panel *, _DWORD))v4->__vftable[1].GetUnpackStructure)(a1: v4, a2: 0);
        v5 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
        vgui::FileOpenDialog::AddFilter(
          this: v5,
          filter: "*.*",
          filterName: "All Files (*.*)",
          bActive: true,
          pFilterInfo: nullptr);
      }
    }
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      V_strncpy(pDest: startPath, pSrc: com_gamedir, maxLen: 260);
      V_FixSlashes(pname: startPath, separator: 92);
      v6 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::SetStartDirectory(this: v6, dir: startPath);
      v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DF10
// Name: public: virtual bool CKeyValuesDumpForBugreport::KvWriteText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CKeyValuesDumpForBugreport::KvWriteText(CKeyValuesDumpForBugreport *this, const char *szText)
{
  CUtlBuffer::Printf(this: this->m_buffer, pFmt: "%s", szText);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013DF30
// Name: protected: void CBugUIPanel::DetermineSubmitterName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::DetermineSubmitterName(CBugUIPanel *this)
{
  IBugReporter *m_pBugReporter; // ecx
  const char *v3; // eax
  const char *RepositoryURL; // eax
  _iobuf *v5; // edi
  const char *v6; // eax
  char fn[512]; // [esp+4h] [ebp-304h] BYREF
  char display[256]; // [esp+204h] [ebp-104h] BYREF
  Color clr; // [esp+304h] [ebp-4h] BYREF

  m_pBugReporter = this->m_pBugReporter;
  if ( m_pBugReporter != nullptr )
  {
    if ( m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
    {
      this->m_pSubmitter->SetText(this: this->m_pSubmitter, a2: "PublicUser");
      this->m_bCanSeeRepository = true;
      this->m_bCanSubmit = true;
    }
    else
    {
      clr = (Color)-14236;
      memset(display, 0, sizeof(display));
      this->m_pSubmitter->GetText_2(this: this->m_pSubmitter, a2: display, a3: 256);
      v3 = this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: display);
      if ( v3 != nullptr && *v3 != 0 && display[0] != 0 )
      {
        ConColorMsg(a1: &clr, a2: "Username '%s' -- '%s'\n", v3, display);
        RepositoryURL = CBugUIPanel::GetRepositoryURL(this);
        V_snprintf(pDest: fn, maxLen: 512, pFormat: "%s/%s", RepositoryURL, "info.txt");
        V_FixSlashes(pname: fn, separator: 92);
        v5 = fopen(file: (_iobuf *)fn, mode: "rb");
        if ( v5 != nullptr )
        {
          v6 = CBugUIPanel::GetRepositoryURL(this);
          ConColorMsg(a1: &clr, a2: "Bug Repository '%s'\n", v6);
          fclose(stream: v5);
          this->m_bCanSeeRepository = true;
        }
        else
        {
          _Warning(a1: "Unable to see '%s', check permissions and network connectivity\n", fn);
          this->m_bCanSubmit = false;
        }
      }
      else
      {
        ConColorMsg(a1: &clr, a2: "Failed to determine bug submission name.\n");
        this->m_bCanSubmit = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E0D0
// Name: protected: void CBugUIPanel::PopulateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::PopulateControls(CBugUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // ebx
  int v5; // edi
  const char *v6; // ebx
  const char *v7; // eax
  vgui::ComboBox_vtbl *v8; // edi
  const char *v9; // eax
  int v10; // edi
  const char *v11; // ebx
  const char *v12; // eax
  int v13; // edi
  const char *v14; // ebx
  int v15; // ebx
  vgui::ComboBox_vtbl *v16; // edi
  int v17; // eax
  int v18; // edi
  const char *v19; // ebx
  int v20; // ebx
  vgui::ComboBox_vtbl *v21; // edi
  int v22; // eax
  int Area; // eax
  const char *submitter; // [esp+4h] [ebp-Ch]
  int defitem; // [esp+8h] [ebp-8h]
  int defitema; // [esp+8h] [ebp-8h]
  int defitemb; // [esp+8h] [ebp-8h]
  int c; // [esp+Ch] [ebp-4h]
  int ca; // [esp+Ch] [ebp-4h]
  int cb; // [esp+Ch] [ebp-4h]
  int cc; // [esp+Ch] [ebp-4h]
  int cd; // [esp+Ch] [ebp-4h]
  int ce; // [esp+Ch] [ebp-4h]

  if ( this->m_pBugReporter != nullptr )
  {
    v4 = -1;
    defitem = -1;
    submitter = (const char *)((int (__thiscall *)(IBugReporter *, int, int))this->m_pBugReporter->GetUserNameA_2)(
                                a1: this->m_pBugReporter,
                                a2: a3,
                                a3: a2);
    vgui::ComboBox::RemoveAll(this: this->m_pSubmitter);
    v5 = 0;
    c = this->m_pBugReporter->GetDisplayNameCount(this: this->m_pBugReporter);
    if ( c > 0 )
    {
      do
      {
        v6 = this->m_pBugReporter->GetDisplayName(this: this->m_pBugReporter, a2: v5);
        v7 = this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: v6);
        if ( V_strcasecmp(s1: v7, s2: submitter) == 0 )
          defitem = v5;
        this->m_pSubmitter->AddItem_2(this: this->m_pSubmitter, a2: v6, a3: nullptr);
        ++v5;
      }
      while ( v5 < c );
      v4 = defitem;
    }
    this->m_pSubmitter->ActivateItem(this: this->m_pSubmitter, a2: v4);
    v8 = this->m_pSubmitter->__vftable;
    v9 = this->m_pBugReporter->GetDisplayName(this: this->m_pBugReporter, a2: v4);
    v8->SetText(this: this->m_pSubmitter, a2: v9);
    ca = this->m_pBugReporter->GetDisplayNameCount(this: this->m_pBugReporter);
    vgui::ComboBox::RemoveAll(this: this->m_pAssignTo);
    v10 = 0;
    for ( defitema = -1; v10 < ca; ++v10 )
    {
      v11 = this->m_pBugReporter->GetDisplayName(this: this->m_pBugReporter, a2: v10);
      v12 = this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: v11);
      if ( V_strcasecmp(s1: v12, s2: submitter) == 0 )
        defitema = v10;
      this->m_pAssignTo->AddItem_2(this: this->m_pAssignTo, a2: v11, a3: nullptr);
    }
    this->m_pAssignTo->ActivateItem(this: this->m_pAssignTo, a2: defitema);
    v13 = 0;
    defitemb = 0;
    vgui::ComboBox::RemoveAll(this: this->m_pSeverity);
    cb = this->m_pBugReporter->GetSeverityCount(this: this->m_pBugReporter);
    if ( cb > 0 )
    {
      do
      {
        v14 = this->m_pBugReporter->GetSeverity(this: this->m_pBugReporter, a2: v13);
        if ( V_strcasecmp(s1: v14, s2: "Zero") == 0 )
          defitemb = v13;
        this->m_pSeverity->AddItem_2(this: this->m_pSeverity, a2: v14, a3: nullptr);
        ++v13;
      }
      while ( v13 < cb );
    }
    this->m_pSeverity->ActivateItem(this: this->m_pSeverity, a2: defitemb);
    vgui::ComboBox::RemoveAll(this: this->m_pReportType);
    v15 = 0;
    cc = this->m_pBugReporter->GetReportTypeCount(this: this->m_pBugReporter);
    if ( cc > 0 )
    {
      do
      {
        v16 = this->m_pReportType->__vftable;
        v17 = ((int (__thiscall *)(IBugReporter *, int, _DWORD))this->m_pBugReporter->GetReportType)(
                a1: this->m_pBugReporter,
                a2: v15,
                a3: 0);
        ((void (__thiscall *)(vgui::ComboBox *, int))v16->AddItem_2)(a1: this->m_pReportType, a2: v17);
        ++v15;
      }
      while ( v15 < cc );
    }
    this->m_pReportType->ActivateItem(this: this->m_pReportType, a2: 0);
    vgui::ComboBox::RemoveAll(this: this->m_pPriority);
    v18 = 0;
    cd = this->m_pBugReporter->GetPriorityCount(this: this->m_pBugReporter);
    if ( cd > 0 )
    {
      do
      {
        v19 = this->m_pBugReporter->GetPriority(this: this->m_pBugReporter, a2: v18);
        if ( V_strcasecmp(s1: v19, s2: "None") == 0 )
          defitemb = v18;
        this->m_pPriority->AddItem_2(this: this->m_pPriority, a2: v19, a3: nullptr);
        ++v18;
      }
      while ( v18 < cd );
    }
    this->m_pPriority->ActivateItem(this: this->m_pPriority, a2: defitemb);
    vgui::ComboBox::RemoveAll(this: this->m_pGameArea);
    v20 = 0;
    ce = this->m_pBugReporter->GetAreaCount(this: this->m_pBugReporter);
    if ( ce > 0 )
    {
      do
      {
        v21 = this->m_pGameArea->__vftable;
        v22 = ((int (__thiscall *)(IBugReporter *, int, _DWORD))this->m_pBugReporter->GetArea)(
                a1: this->m_pBugReporter,
                a2: v20,
                a3: 0);
        ((void (__thiscall *)(vgui::ComboBox *, int))v21->AddItem_2)(a1: this->m_pGameArea, a2: v22);
        ++v20;
      }
      while ( v20 < ce );
    }
    Area = CBugUIPanel::GetArea(this);
    this->m_pGameArea->ActivateItem(this: this->m_pGameArea, a2: Area);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E400
// Name: public: virtual char const __near * CBugReporterDefaultUsername::GetDefaultUsername(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBugReporterDefaultUsername::GetDefaultUsername(CBugReporterDefaultUsername *this)
{
  char *result; // eax

  if ( (bugreporter_username.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = bugreporter_username.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013E430
// Name: protected: char const __near * CBugUIPanel::GetSubmitter(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBugUIPanel::GetSubmitter(CBugUIPanel *this)
{
  char *m_pszString; // esi
  CSteam3Client *v4; // eax
  CSteamID *v5; // eax
  char submitter[256]; // [esp+4h] [ebp-108h] BYREF
  char v7; // [esp+104h] [ebp-8h] BYREF
  Color clr; // [esp+108h] [ebp-4h] BYREF

  if ( !this->m_bCanSubmit )
    return (char *)defaultValue;
  if ( (bugreporter_username.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = bugreporter_username.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  if ( *m_pszString == 0 )
  {
    this->m_pSubmitter->GetText_2(this: this->m_pSubmitter, a2: submitter, a3: 256);
    m_pszString = (char *)this->m_pBugReporter->GetUserNameForDisplayName(this: this->m_pBugReporter, a2: submitter);
    if ( *m_pszString == 0 )
    {
      if ( this->m_bIsPublic )
      {
        if ( Steam3Client()->m_pSteamUser != nullptr )
        {
          v4 = Steam3Client();
          v5 = v4->m_pSteamUser->GetSteamID(this: v4->m_pSteamUser, result: (CSteamID *)&v7);
          m_pszString = (char *)CSteamID::Render(this: v5);
        }
        else
        {
          m_pszString = "PublicUser";
        }
      }
      if ( *m_pszString == 0 )
      {
        clr = (Color)-13487361;
        ConColorMsg(
          a1: &clr,
          a2: "Can't determine username. Please set email address with bugreporter_username ConVar and run _bugreporter_restart autoselect\n");
      }
    }
  }
  return m_pszString;
}

//------------------------------------------------------------------------------
// Address: 0x1013E510
// Name: protected: void CBugUIPanel::SuccessSound(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::SuccessSound(CBugUIPanel *this, int bugId)
{
  bool v2; // zf
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v5; // [esp-8h] [ebp-Ch]
  Color clr; // [esp+0h] [ebp-4h] BYREF

  v2 = this->m_pBugReporter == nullptr;
  clr = (Color)-10158286;
  if ( v2
    || ((int (__thiscall *)(_DWORD, _DWORD))this->m_pBugReporter->IsPublicUI)(a1: this->m_pBugReporter, a2: clr) == 0 )
  {
    ConColorMsg(a1: &clr, a2: "Bug submission succeeded for bug (%i)\n", bugId);
  }
  else
  {
    ConColorMsg(a1: &clr, a2: "Bug submission succeeded\n");
  }
  v5 = va(format: "play %s\n", "common/bugreporter_succeeded");
  TraceType = CTraceFilter::GetTraceType(this: v3);
  Cbuf_AddText(eTarget: TraceType, pText: v5, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013E590
// Name: public: void CBugUIPanel::ParseCommands(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBugUIPanel::ParseCommands(CBugUIPanel *this@<ecx>, const char *a2@<edi>, const CCommand *args)
{
  int m_nArgc; // eax
  int v5; // edx
  int v6; // esi
  const char *v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char **v12; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  const char **v14; // [esp+Ch] [ebp-4h]

  if ( this->m_bCanSubmit )
  {
    m_nArgc = args->m_nArgc;
    v5 = 1;
    i = 1;
    if ( args->m_nArgc > 1 )
    {
      v6 = 2;
      v12 = &args->m_ppArgv[1];
      v14 = &args->m_ppArgv[2];
      while ( 1 )
      {
        v7 = v5 < 0 || v5 >= m_nArgc ? defaultValue : *v12;
        if ( _V_stricmp(s1: "-title", s2: v7) != 0 )
        {
          if ( _V_stricmp(s1: "-auto", s2: v7) != 0 )
          {
            if ( _V_stricmp(s1: "-remotebugpath", s2: v7) != 0 )
            {
              if ( CBugUIPanel::AutoFillToken(this, token: v7, partial: false) == 0
                && CBugUIPanel::AutoFillToken(this, token: v7, partial: true) == 0 )
              {
                _Msg(a1: "Unable to determine where to set default bug parameter '%s', ignoring...\n", v7);
              }
            }
            else if ( v6 < args->m_nArgc )
            {
              if ( v6 < 0 )
                v10 = defaultValue;
              else
                v10 = *v14;
              CUtlString::operator=(this: &this->m_strRemoteBugInfoPath, src: v10);
              ++i;
              ++v12;
              ++v14;
              this->m_bIsSubmittingRemoteBug = true;
              ++v6;
            }
          }
          else
          {
            this->m_bAutoSubmit = true;
          }
        }
        else if ( v6 < args->m_nArgc )
        {
          if ( v6 < 0 )
            v8 = defaultValue;
          else
            v8 = *v14;
          ((void (__thiscall *)(vgui::TextEntry *, const char *, const char *))this->m_pTitle->SetText)(
            a1: this->m_pTitle,
            a2: v8,
            a3: a2);
          if ( v6 < 0 || v6 >= args->m_nArgc )
            v9 = defaultValue;
          else
            v9 = *v14;
          a2 = v9;
          ((void (__thiscall *)(vgui::TextEntry *))this->m_pDescription->SetText)(a1: this->m_pDescription);
          ++i;
          ++v12;
          ++v14;
          ++v6;
        }
        ++v12;
        ++v14;
        m_nArgc = args->m_nArgc;
        ++v6;
        if ( ++i >= args->m_nArgc )
          break;
        v5 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E880
// Name: public: void CBugUIPanel::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::Init(CBugUIPanel *this@<ecx>, int Tall@<ebx>)
{
  IFileSystem_vtbl *v3; // edi
  const char *v4; // eax
  struct CSysModule *v5; // eax
  bool v6; // zf
  IFileSystem_vtbl *v7; // edi
  const char *v8; // eax
  int Wide; // edi
  int v10; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IBugReporter *v12; // eax
  const char *v13; // eax
  IBugReporter *m_pBugReporter; // ecx
  vgui::Label_vtbl *v15; // edi
  int v16; // eax
  char *v17; // eax
  const char *v18; // [esp-4h] [ebp-14h]
  const char *v19; // [esp-4h] [ebp-14h]
  Color clr; // [esp+Ch] [ebp-4h] BYREF

  clr = (Color)-39886;
  v3 = g_pFileSystem->IAppSystem::__vftable;
  v4 = CUtlString::operator char const *(this: &this->m_sDllName);
  v5 = v3->LoadModule(this: g_pFileSystem, a2: v4, a3: nullptr, a4: true);
  v6 = !this->m_bIsPublic;
  this->m_hBugReporter = v5;
  if ( !v6 )
  {
    v7 = g_pFileSystem->IAppSystem::__vftable;
    v8 = CUtlString::operator char const *(this: &this->m_sDllName);
    this->m_hBugReporter = v7->LoadModule(this: g_pFileSystem, a2: v8, a3: nullptr, a4: true);
    this->LoadControlSettings(this, a2: "Resource\\BugUIPanel_Public.res", a3: nullptr, a4: nullptr, a5: nullptr);
    Wide = vgui::Panel::GetWide(this);
    Tall = vgui::Panel::GetTall(this);
    v3 = (IFileSystem_vtbl *)((videomode->GetModeWidth(this: videomode) - Wide) / 2);
    v10 = videomode->GetModeHeight(this: videomode);
    vgui::Panel::SetPos(this, x: (int)v3, y: (v10 - Tall) / 2);
  }
  if ( this->m_hBugReporter != nullptr )
  {
    Factory = Sys_GetFactory(pModule: this->m_hBugReporter);
    if ( Factory != nullptr )
    {
      v12 = (IBugReporter *)Factory(a1: "BugReporter005", a2: nullptr);
      this->m_pBugReporter = v12;
      if ( v12 != nullptr )
      {
        if ( v12->Init(this: v12, a2: g_AppSystemFactory) )
        {
          *(_WORD *)&this->m_bCanSubmit = 257;
        }
        else
        {
          this->m_pBugReporter = nullptr;
          ConColorMsg(a1: &clr, a2: "m_pBugReporter->Init() failed\n");
        }
      }
      else
      {
        v13 = CUtlString::operator char const *(this: &this->m_sDllName);
        ConColorMsg(a1: &clr, a2: "Couldn't get interface '%s' from '%s'\n", "BugReporter005", v13);
      }
    }
    else
    {
      v18 = CUtlString::operator char const *(this: &this->m_sDllName);
      ConColorMsg(a1: &clr, a2: "Couldn't get factory '%s'\n", v18);
    }
  }
  else
  {
    v19 = CUtlString::operator char const *(this: &this->m_sDllName);
    ConColorMsg(a1: &clr, a2: "Couldn't load '%s'\n", v19);
  }
  if ( this->m_bCanSubmit )
    CBugUIPanel::PopulateControls(this, a2: Tall, a3: (int)v3);
  m_pBugReporter = this->m_pBugReporter;
  if ( m_pBugReporter != nullptr && m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
  {
    this->m_pSaveBSP->SetVisible(this: this->m_pSaveBSP, a2: false);
    this->m_pBSPURL->SetVisible(this: this->m_pBSPURL, a2: false);
    this->m_pChooseVMFFolder->SetVisible(this: this->m_pChooseVMFFolder, a2: false);
    this->m_pSaveVMF->SetVisible(this: this->m_pSaveVMF, a2: false);
    this->m_pVMFURL->SetVisible(this: this->m_pVMFURL, a2: false);
    this->m_pIncludeFile->SetVisible(this: this->m_pIncludeFile, a2: false);
    this->m_pClearIncludes->SetVisible(this: this->m_pClearIncludes, a2: false);
    this->m_pAssignTo->SetVisible(this: this->m_pAssignTo, a2: false);
    this->m_pSeverity->SetVisible(this: this->m_pSeverity, a2: false);
    this->m_pPriority->SetVisible(this: this->m_pPriority, a2: false);
    this->m_pGameArea->SetVisible(this: this->m_pGameArea, a2: false);
    this->m_pMapNumber->SetVisible(this: this->m_pMapNumber, a2: false);
    this->m_pIncludedFiles->SetVisible(this: this->m_pIncludedFiles, a2: false);
    this->m_pSubmitter->SetVisible(this: this->m_pSubmitter, a2: true);
    this->m_pSubmitterLabel->SetVisible(this: this->m_pSubmitterLabel, a2: false);
    this->m_bQueryingSteamForCSER = true;
  }
  else
  {
    this->m_pEmail->SetVisible(this: this->m_pEmail, a2: false);
    this->m_pSubmitterLabel->SetVisible(this: this->m_pSubmitterLabel, a2: true);
    this->m_pSubmitter->SetVisible(this: this->m_pSubmitter, a2: true);
  }
  V_snprintf(pDest: this->m_szVMFContentDirFullpath, maxLen: 260, pFormat: "%s/maps", com_gamedir);
  _V_strlower(start: this->m_szVMFContentDirFullpath);
  V_FixSlashes(pname: this->m_szVMFContentDirFullpath, separator: 92);
  v15 = this->m_pBuildNumber->__vftable;
  v16 = build_number();
  v17 = va(format: "%d", v16);
  v15->SetText(this: this->m_pBuildNumber, a2: v17);
}

//------------------------------------------------------------------------------
// Address: 0x1013EBF0
// Name: protected: void CBugUIPanel::TakeSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::TakeSnapshot(CBugUIPanel *this)
{
  char *m_szScreenShotName; // edi
  char *Submitter; // eax
  IBugReporter *m_pBugReporter; // ecx
  int v5; // ebx
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  int v8; // eax
  char *v9; // [esp-8h] [ebp-14h]
  const char *v10; // [esp-8h] [ebp-14h]

  m_szScreenShotName = this->m_szScreenShotName;
  v9 = this->m_szScreenShotName;
  this->m_nSnapShotFrame = host_framecount;
  this->m_bTakingSnapshot = true;
  Submitter = CBugUIPanel::GetSubmitter(this);
  CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: v9, bufsize: 256);
  m_pBugReporter = this->m_pBugReporter;
  v5 = 100;
  if ( m_pBugReporter != nullptr && m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
    v5 = 40;
  v10 = va(format: "jpeg \"%s\" %i\n", m_szScreenShotName, v5);
  TraceType = CTraceFilter::GetTraceType(this: v6);
  Cbuf_AddText(eTarget: TraceType, pText: v10, nTickDelay: 0);
  v8 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-remotebug", a3: 0) == 0 )
    Cbuf_AddText(
      eTarget: sv.m_State < ss_active ? CBUF_FIRST_PLAYER : CBUF_SERVER,
      pText: "cmd bugpause\n",
      nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013ECA0
// Name: protected: void CBugUIPanel::OnSaveGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnSaveGame(CBugUIPanel *this)
{
  char *m_szSaveGameName; // edi
  char *Submitter; // eax
  char *v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  char *v7; // [esp-8h] [ebp-10h]
  const char *v8; // [esp-8h] [ebp-10h]

  m_szSaveGameName = this->m_szSaveGameName;
  v7 = this->m_szSaveGameName;
  Submitter = CBugUIPanel::GetSubmitter(this);
  CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: v7, bufsize: 256);
  if ( this->m_pBugReporter != nullptr && this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
    v4 = va(format: "minisave %s\n", m_szSaveGameName);
  else
    v4 = va(format: "save %s.sav notmostrecent copymap\n", m_szSaveGameName);
  v8 = v4;
  TraceType = CTraceFilter::GetTraceType(this: v5);
  Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
  this->m_pSaveGameURL->SetText(this: this->m_pSaveGameURL, a2: m_szSaveGameName);
}

//------------------------------------------------------------------------------
// Address: 0x1013ED20
// Name: protected: void CBugUIPanel::OnSaveBSP(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnSaveBSP(CBugUIPanel *this)
{
  char *m_szBSPName; // edi
  char *Submitter; // eax
  char *v4; // [esp-8h] [ebp-10h]

  m_szBSPName = this->m_szBSPName;
  v4 = this->m_szBSPName;
  Submitter = CBugUIPanel::GetSubmitter(this);
  CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: v4, bufsize: 256);
  this->m_pBSPURL->SetText(this: this->m_pBSPURL, a2: m_szBSPName);
}

//------------------------------------------------------------------------------
// Address: 0x1013ED60
// Name: protected: void CBugUIPanel::OnSaveVMF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnSaveVMF(CBugUIPanel *this)
{
  IBugReporter *m_pBugReporter; // ecx
  vgui::DirectorySelectDialog *v3; // eax
  CDragDropHelperPanel *v4; // eax
  vgui::DirectorySelectDialog *v5; // eax
  vgui::Panel *v6; // eax
  char *Submitter; // eax
  char localfile[512]; // [esp+4h] [ebp-300h] BYREF
  char level[256]; // [esp+204h] [ebp-100h] BYREF

  m_pBugReporter = this->m_pBugReporter;
  if ( m_pBugReporter == nullptr || !m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
  {
    this->m_pLevelName->GetText(this: this->m_pLevelName, a2: level, a3: 256);
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/%s.vmf", this->m_szVMFContentDirFullpath, level);
    if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: localfile, a3: nullptr) )
    {
      Submitter = CBugUIPanel::GetSubmitter(this);
      CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: this->m_szVMFName, bufsize: 256);
      this->m_pVMFURL->SetText(this: this->m_pVMFURL, a2: this->m_szVMFName);
    }
    else
    {
      if ( vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog) == nullptr )
      {
        v3 = (vgui::DirectorySelectDialog *)MemAlloc_Alloc(nSize: 0x47Cu);
        if ( v3 != nullptr )
          v4 = (CDragDropHelperPanel *)vgui::DirectorySelectDialog::DirectorySelectDialog(
                                         this: v3,
                                         parent: this,
                                         title: "Choose .vmf folder");
        else
          v4 = nullptr;
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(
          this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDirectorySelectDialog,
          pPanel: v4);
      }
      this->m_bAddVMF = true;
      v5 = (vgui::DirectorySelectDialog *)vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog);
      vgui::DirectorySelectDialog::SetStartDirectory(this: v5, path: this->m_szVMFContentDirFullpath);
      v6 = vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog);
      v6->__vftable[1].IsEnabled(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013EE90
// Name: protected: virtual void CBugUIPanel::OnDirectorySelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnDirectorySelected(CBugUIPanel *this, const char *dir)
{
  char *m_szVMFContentDirFullpath; // edi
  vgui::Panel *v4; // eax
  char *Submitter; // eax

  m_szVMFContentDirFullpath = this->m_szVMFContentDirFullpath;
  V_strncpy(pDest: this->m_szVMFContentDirFullpath, pSrc: dir, maxLen: 260);
  _V_strlower(start: m_szVMFContentDirFullpath);
  V_FixSlashes(pname: m_szVMFContentDirFullpath, separator: 92);
  V_StripTrailingSlash(ppath: m_szVMFContentDirFullpath);
  if ( vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hDirectorySelectDialog);
    v4->MarkForDeletion(this: v4);
  }
  if ( this->m_bAddVMF )
  {
    Submitter = CBugUIPanel::GetSubmitter(this);
    CBugUIPanel::GetDataFileBase(this, suffix: Submitter, buf: this->m_szVMFName, bufsize: 256);
    this->m_pVMFURL->SetText(this: this->m_pVMFURL, a2: this->m_szVMFName);
  }
  this->m_bAddVMF = false;
}

//------------------------------------------------------------------------------
// Address: 0x1013EF30
// Name: public: virtual void CBugUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::Activate(CBugUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int Area; // edi
  IClientEntityList_vtbl *v5; // edi
  CClientState *BaseLocalClient; // eax
  int v7; // eax
  vgui::Label_vtbl *v8; // edi
  char *v9; // eax
  vgui::Label_vtbl *v10; // edi
  char *v11; // eax
  vgui::Label_vtbl *v12; // edi
  CClientState *v13; // eax
  vgui::Button_vtbl *v14; // edi
  CClientState *v15; // eax
  vgui::CTreeViewListControl *v16; // ecx
  ECommandTarget_t TraceType; // eax
  QAngle ang; // [esp+2Ch] [ebp-18h] BYREF
  Vector org; // [esp+38h] [ebp-Ch]

  if ( !this->m_bValidated )
  {
    this->m_bValidated = true;
    CBugUIPanel::Init(this, Tall: a2);
    CBugUIPanel::DetermineSubmitterName(this);
  }
  if ( ((int (__thiscall *)(vgui::ComboBox *, int))this->m_pGameArea->GetItemCount)(a1: this->m_pGameArea, a2: a3) != 0 )
  {
    Area = CBugUIPanel::GetArea(this);
    if ( Area != 0 )
    {
      if ( vgui::ComboBox::GetActiveItem(this: this->m_pGameArea) == Area )
        ((void (__stdcall *)(vgui::ComboBox *))this->OnChooseArea)(a1: this->m_pGameArea);
      else
        ((void (__stdcall *)(int))this->m_pGameArea->ActivateItem)(a1: Area);
    }
  }
  if ( GetBaseLocalClient()->m_nSignonState == 6 )
  {
    org = g_MainViewOrigin[0];
    VectorAngles(forward: g_MainViewForward, angles: &ang);
    v5 = entitylist->__vftable;
    BaseLocalClient = GetBaseLocalClient();
    v7 = (int)v5->GetClientEntity(this: entitylist, a2: BaseLocalClient->m_nPlayerSlot + 1);
    if ( v7 != 0 )
      org = *(Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 40))(a1: v7);
    v8 = this->m_pPosition->__vftable;
    v9 = va(format: "%f %f %f", org.x, org.y, org.z);
    v8->SetText(this: this->m_pPosition, a2: v9);
    v10 = this->m_pOrientation->__vftable;
    v11 = va(format: "%f %f %f", ang.x, ang.y, ang.z);
    v10->SetText(this: this->m_pOrientation, a2: v11);
    v12 = this->m_pLevelName->__vftable;
    v13 = GetBaseLocalClient();
    v12->SetText(this: this->m_pLevelName, a2: v13->m_szLevelNameShort);
    v14 = this->m_pSaveGame->__vftable;
    v15 = GetBaseLocalClient();
    v14->SetEnabled(this: this->m_pSaveGame, a2: v15->m_nMaxClients == 1);
    this->m_pSaveBSP->SetEnabled(this: this->m_pSaveBSP, a2: true);
    this->m_pSaveVMF->SetEnabled(this: this->m_pSaveVMF, a2: true);
    this->m_pChooseVMFFolder->SetEnabled(this: this->m_pChooseVMFFolder, a2: true);
  }
  else
  {
    this->m_pPosition->SetText(this: this->m_pPosition, a2: "console");
    this->m_pOrientation->SetText(this: this->m_pOrientation, a2: "console");
    this->m_pLevelName->SetText(this: this->m_pLevelName, a2: "console");
    this->m_pSaveGame->SetEnabled(this: this->m_pSaveGame, a2: false);
    this->m_pSaveBSP->SetEnabled(this: this->m_pSaveBSP, a2: false);
    this->m_pSaveVMF->SetEnabled(this: this->m_pSaveVMF, a2: false);
    this->m_pChooseVMFFolder->SetEnabled(this: this->m_pChooseVMFFolder, a2: false);
  }
  vgui::Frame::Activate(this);
  this->m_pTitle->RequestFocus(this: this->m_pTitle, a2: 0);
  vgui::TextEntry::SelectAllText(this: this->m_pTitle, bResetCursorPos: true);
  if ( this->m_szScreenShotName[0] == 0 )
  {
    if ( this->m_bIsPublic )
    {
      if ( this->m_fAutoAddScreenshot == 1 )
        goto LABEL_18;
    }
    else if ( this->m_fAutoAddScreenshot != 2 )
    {
LABEL_18:
      CBugUIPanel::OnTakeSnapshot(this);
    }
  }
  _Msg(a1: "BUG REPORT PORTAL POSITIONS:\n");
  TraceType = CTraceFilter::GetTraceType(this: v16);
  Cbuf_AddText(eTarget: TraceType, pText: "portal_report\n", nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013F2D0
// Name: public: void CBugUIPanel::ParseDefaultParams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::ParseDefaultParams(CBugUIPanel *this)
{
  const char *i; // esi
  char token[256]; // [esp+4h] [ebp-130h] BYREF
  CUtlBuffer buffer; // [esp+104h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 1);
  if ( g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: "scripts/bugreporter_defaults.txt",
         a3: nullptr,
         a4: &buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    for ( i = COM_ParseFile(data: (const char *)buffer.m_Memory.m_pMemory, token, maxtoken: 256);
          i != nullptr;
          i = COM_ParseFile(data: i, token, maxtoken: 256) )
    {
      if ( CBugUIPanel::AutoFillToken(this, token, partial: false) == 0
        && CBugUIPanel::AutoFillToken(this, token, partial: true) == 0 )
      {
        _Msg(a1: "Unable to determine where to set default bug parameter '%s', ignoring...\n", token);
      }
    }
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1013F3B0
// Name: protected: bool CBugUIPanel::CopyInfoFromRemoteBug(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CBugUIPanel::CopyInfoFromRemoteBug@<al>(CBugUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  CUtlString *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *String; // ebx
  IBugReporter_vtbl *v11; // ebx
  const char *v12; // eax
  IBugReporter_vtbl *v13; // ebx
  const char *v14; // eax
  IBugReporter_vtbl *v15; // ebx
  const char *v16; // eax
  IBugReporter_vtbl *v17; // ebx
  const char *v18; // eax
  IBugReporter_vtbl *v19; // ebx
  const char *v20; // eax
  IBugReporter_vtbl *v21; // ebx
  const char *v22; // eax
  const char *v23; // eax
  CUtlString *v24; // eax
  const char *v25; // eax
  CUtlString *v26; // eax
  CUtlString *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  CUtlString *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  char localBugConsole[260]; // [esp+4h] [ebp-260h] BYREF
  char buffer[260]; // [esp+108h] [ebp-15Ch] BYREF
  CUtlString strBugConsolePath; // [esp+20Ch] [ebp-58h] BYREF
  CUtlString v39; // [esp+21Ch] [ebp-48h] BYREF
  CUtlString strSSName; // [esp+22Ch] [ebp-38h] BYREF
  CUtlString v41; // [esp+23Ch] [ebp-28h] BYREF
  CUtlString strSSPath; // [esp+24Ch] [ebp-18h] BYREF
  IBaseFileSystem *filesystem; // [esp+25Ch] [ebp-8h]
  bool v44; // [esp+263h] [ebp-1h]

  if ( this->m_pBugReporter == nullptr || !this->m_bIsSubmittingRemoteBug )
    return 0;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "Bug");
  else
    v6 = nullptr;
  if ( g_pFileSystem != nullptr )
    filesystem = &g_pFileSystem->IBaseFileSystem;
  else
    filesystem = nullptr;
  v7 = CUtlString::operator+(this: &this->m_strRemoteBugInfoPath, result: &strSSPath, pOther: "\\bug.txt");
  v8 = CUtlString::operator char const *(this: v7);
  v44 = !KeyValues::LoadFromFile(
           this: v6,
           filesystem,
           resourceName: v8,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr);
  strSSPath.m_Storage.m_nActualLength = 0;
  if ( strSSPath.m_Storage.m_Memory.m_nGrowSize >= 0 && strSSPath.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: strSSPath.m_Storage.m_Memory.m_pMemory);
  if ( v44 )
  {
    v9 = CUtlString::Get(this: &this->m_strRemoteBugInfoPath);
    _Warning(a1: "Failed to parse remote bug KV file at path: '%s'", v9);
    KeyValues::deleteThis(this: v6);
    return 0;
  }
  else
  {
    String = KeyValues::GetString(this: v6, keyName: "level", defaultValue: defaultValue);
    ((void (__thiscall *)(IBugReporter *, const char *, int))this->m_pBugReporter->SetLevel)(
      a1: this->m_pBugReporter,
      a2: String,
      a3: a2);
    V_strncpy(pDest: this->m_szLevel, pSrc: String, maxLen: 256);
    v11 = this->m_pBugReporter->__vftable;
    v12 = KeyValues::GetString(this: v6, keyName: "Build", defaultValue: defaultValue);
    v11->SetBuildNumber(this: this->m_pBugReporter, a2: v12);
    v13 = this->m_pBugReporter->__vftable;
    v14 = KeyValues::GetString(this: v6, keyName: "Position", defaultValue: defaultValue);
    v13->SetPosition(this: this->m_pBugReporter, a2: v14);
    v15 = this->m_pBugReporter->__vftable;
    v16 = KeyValues::GetString(this: v6, keyName: "Orientation", defaultValue: defaultValue);
    v15->SetOrientation(this: this->m_pBugReporter, a2: v16);
    v17 = this->m_pBugReporter->__vftable;
    v18 = KeyValues::GetString(this: v6, keyName: "Misc", defaultValue: defaultValue);
    v17->SetMiscInfo(this: this->m_pBugReporter, a2: v18);
    v19 = this->m_pBugReporter->__vftable;
    v20 = KeyValues::GetString(this: v6, keyName: "Console", defaultValue: defaultValue);
    v19->SetConsoleHistory(this: this->m_pBugReporter, a2: v20);
    v21 = this->m_pBugReporter->__vftable;
    v22 = KeyValues::GetString(this: v6, keyName: "DriverInfo", defaultValue: defaultValue);
    v21->SetDriverInfo(this: this->m_pBugReporter, a2: v22);
    v23 = KeyValues::GetString(this: v6, keyName: "Screenshot", defaultValue: defaultValue);
    CUtlString::CUtlString(this: &strSSName, pString: v23);
    if ( CUtlString::Length(this: &strSSName) != 0 )
    {
      v24 = CUtlString::UnqualifiedFilename(this: &strSSName, result: &v39);
      v25 = CUtlString::operator char const *(this: v24);
      V_StripExtension(in: v25, out: this->m_szScreenShotName, outSize: 256);
      CUtlString::~CUtlString(this: &v39);
      V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s/screenshots/%s.jpg", com_gamedir, this->m_szScreenShotName);
      v26 = CUtlString::operator+(this: &this->m_strRemoteBugInfoPath, result: &v41, pOther: "\\");
      v27 = CUtlString::operator+(this: v26, result: &v39, pOther: this->m_szScreenShotName);
      CUtlString::operator+(this: v27, result: &strSSPath, pOther: ".jpg");
      CUtlString::~CUtlString(this: &v39);
      CUtlString::~CUtlString(this: &v41);
      v28 = CUtlString::operator char const *(this: &strSSPath);
      CBugUIPanel::UploadFile(this, local: v28, remote: buffer, bDeleteLocal: true);
      v29 = (const char *)((int (__thiscall *)(IBugReporter *, int))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: a3);
      if ( v29 == nullptr )
        v29 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s/BugId/%s.jpg", v29, this->m_szScreenShotName);
      V_FixSlashes(pname: buffer, separator: 92);
      this->m_pBugReporter->SetScreenShot(this: this->m_pBugReporter, a2: buffer);
      CUtlString::~CUtlString(this: &strSSPath);
    }
    V_snprintf(pDest: localBugConsole, maxLen: 260, pFormat: "%s/bugconsole.txt", com_gamedir);
    CUtlString::operator+(this: &this->m_strRemoteBugInfoPath, result: &strBugConsolePath, pOther: "\\bugconsole.txt");
    v30 = CUtlString::operator char const *(this: &strBugConsolePath);
    CBugUIPanel::UploadFile(this, local: v30, remote: localBugConsole, bDeleteLocal: true);
    this->OnFileSelected(this, a2: localBugConsole);
    KeyValues::deleteThis(this: v6);
    v31 = CUtlString::operator+(this: &this->m_strRemoteBugInfoPath, result: &v41, pOther: "\\bug.txt");
    v32 = CUtlString::operator char const *(this: v31);
    unlink(path: v32);
    CUtlString::~CUtlString(this: &v41);
    v33 = CUtlString::operator char const *(this: &this->m_strRemoteBugInfoPath);
    _rmdir(path: v33);
    CUtlString::~CUtlString(this: &strBugConsolePath);
    CUtlString::~CUtlString(this: &strSSName);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F7B0
// Name: bug
// Source: json
//------------------------------------------------------------------------------
void __usercall bug(const char *a1@<edi>, const CCommand *args)
{
  int v2; // eax

  if ( g_pBugUI != nullptr )
  {
    if ( g_pBugUI->IsVisible(this: g_pBugUI) )
      g_pBugUI->Close(this: g_pBugUI);
    g_pBugUI->Activate(this: g_pBugUI);
    CBugUIPanel::ParseDefaultParams(this: g_pBugUI);
    CBugUIPanel::ParseCommands(this: g_pBugUI, a2: a1, args);
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-remotebug", a3: 0) != 0 )
      g_pBugUI->m_bAutoSubmit = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F830
// Name: protected: void CBugUIPanel::GetConsoleHistory(class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::GetConsoleHistory(CBugUIPanel *this, CUtlBuffer *buf)
{
  int m_Put; // edi
  int v3; // eax

  if ( g_pCVar->GetConsoleDisplayFuncCount(this: g_pCVar) > 0 )
  {
    m_Put = buf->m_Put;
    CUtlBuffer::EnsureCapacity(this: buf, num: m_Put + 0x100000);
    ((void (__stdcall *)(_DWORD, unsigned __int8 *, int))g_pCVar->GetConsoleText)(
      a1: 0,
      a2: &buf->m_Memory.m_pMemory[m_Put],
      a3: 0x100000);
    v3 = _V_strlen(str: (const char *)&buf->m_Memory.m_pMemory[m_Put]);
    CUtlBuffer::SeekPut(this: buf, type: SEEK_HEAD, offset: m_Put + v3 + 1);
  }
  else
  {
    CUtlBuffer::PutChar(this: buf, c: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FA30
// Name: protected: void CBugUIPanel::OnClearIncludedFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnClearIncludedFiles(CBugUIPanel *this)
{
  bool v2; // sf

  v2 = this->m_IncludedFiles.m_Memory.m_nGrowSize < 0;
  this->m_IncludedFiles.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_IncludedFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_IncludedFiles.m_Memory.m_pMemory);
      this->m_IncludedFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_IncludedFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_IncludedFiles.m_pElements = this->m_IncludedFiles.m_Memory.m_pMemory;
  this->m_pIncludedFiles->SetText(this: this->m_pIncludedFiles, a2: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x1013FAA0
// Name: protected: void CBugUIPanel::WipeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::WipeData(CBugUIPanel *this)
{
  vgui::Label *m_pScreenShotURL; // ecx
  vgui::Label *m_pSaveGameURL; // ecx
  vgui::Label *m_pBSPURL; // ecx
  vgui::Label *m_pVMFURL; // ecx

  m_pScreenShotURL = this->m_pScreenShotURL;
  *(_WORD *)&this->m_fAutoAddScreenshot = 0;
  m_pScreenShotURL->SetText(this: m_pScreenShotURL, a2: "Screenshot file");
  m_pSaveGameURL = this->m_pSaveGameURL;
  this->m_szSaveGameName[0] = 0;
  m_pSaveGameURL->SetText(this: m_pSaveGameURL, a2: "Save game file");
  m_pBSPURL = this->m_pBSPURL;
  this->m_szBSPName[0] = 0;
  m_pBSPURL->SetText(this: m_pBSPURL, a2: ".bsp file");
  m_pVMFURL = this->m_pVMFURL;
  this->m_szVMFName[0] = 0;
  m_pVMFURL->SetText(this: m_pVMFURL, a2: ".vmf file");
  this->m_IncludedFiles.m_Size = 0;
  if ( this->m_IncludedFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_IncludedFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_IncludedFiles.m_Memory.m_pMemory);
      this->m_IncludedFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_IncludedFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_IncludedFiles.m_pElements = this->m_IncludedFiles.m_Memory.m_pMemory;
  this->m_pIncludedFiles->SetText(this: this->m_pIncludedFiles, a2: defaultValue);
  this->m_pDescription->SetText(this: this->m_pDescription, a2: defaultValue);
  this->m_pEmail->SetText(this: this->m_pEmail, a2: defaultValue);
  this->m_bIsSubmittingRemoteBug = false;
  CUtlString::Clear(this: &this->m_strRemoteBugInfoPath);
}

//------------------------------------------------------------------------------
// Address: 0x1013FBB0
// Name: public: virtual void CBugUIPanel::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::Close(CBugUIPanel *this)
{
  int v2; // eax
  bool (__thiscall *HideGameUI)(IEngineVGuiInternal *); // kr00_4

  CBugUIPanel::WipeData(this);
  vgui::Frame::Close(this);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-remotebug", a3: 0) == 0 )
    Cbuf_AddText(
      eTarget: sv.m_State < ss_active ? CBUF_FIRST_PLAYER : CBUF_SERVER,
      pText: "cmd bugunpause\n",
      nTickDelay: 0);
  HideGameUI = EngineVGui()->HideGameUI;
  __asm { jmp     eax }
}

//------------------------------------------------------------------------------
// Address: 0x1013FC10
// Name: protected: void CBugUIPanel::OnClearForm(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnClearForm(CBugUIPanel *this)
{
  CBugUIPanel::WipeData(this);
  this->m_pTitle->SetText(this: this->m_pTitle, a2: defaultValue);
  this->m_pDescription->SetText(this: this->m_pDescription, a2: defaultValue);
  this->m_pAssignTo->ActivateItem(this: this->m_pAssignTo, a2: 0);
  this->m_pSeverity->ActivateItem(this: this->m_pSeverity, a2: 0);
  this->m_pReportType->ActivateItem(this: this->m_pReportType, a2: 0);
  this->m_pPriority->ActivateItem(this: this->m_pPriority, a2: 2);
  this->m_pGameArea->ActivateItem(this: this->m_pGameArea, a2: 0);
  this->m_pMapNumber->ActivateItem(this: this->m_pMapNumber, a2: 0);
  this->m_pSubmitter->ActivateItem(this: this->m_pSubmitter, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013FCD0
// Name: public: virtual void CBugUIPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnKeyCodeTyped(CBugUIPanel *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
  {
    this->Close(this);
    CBugUIPanel::WipeData(this);
  }
  else
  {
    vgui::Frame::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FD80
// Name: struct ThreadHandle_t__ __near * ThreadExecuteSolo<class CCallQueue __near *,void (CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::*)(void)>(char const __near *,class CCallQueue __near *,void (CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::*)(void))
// Source: json
//------------------------------------------------------------------------------
ThreadHandle_t__ *__cdecl ThreadExecuteSolo<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void)>(
        const char *pszName,
        CCallQueue *a1,
        __int128 a2)
{
  _DWORD *v3; // eax
  int SimpleThread; // esi

  v3 = MemAlloc_Alloc(nSize: 0x28u);
  if ( v3 != nullptr )
  {
    v3[3] = 1;
    *v3 = &CMemberFunctor0<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v3[2] = &CMemberFunctor0<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *((_OWORD *)v3 + 1) = a2;
    v3[8] = a1;
  }
  else
  {
    v3 = nullptr;
  }
  SimpleThread = _CreateSimpleThread(a1: FunctorExecuteThread, a2: v3, a3: 0);
  if ( pszName != nullptr )
    _ThreadSetDebugName(a1: SimpleThread, a2: pszName);
  return (ThreadHandle_t__ *)SimpleThread;
}

//------------------------------------------------------------------------------
// Address: 0x1013FF50
// Name: public: static void CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FFF0
// Name: public: static void CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar'::`2'::bAdded )
  {
    `CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "DirectorySelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "dir";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140090
// Name: public: static void CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar'::`2'::bAdded )
  {
    `CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "OnChooseVMFFolder";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140120
// Name: public: static void CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar'::`2'::bAdded )
  {
    `CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::TextEntry::`vcall'{1136,{flat}};
    memset(&v3.m[1][1], 0, 12);
    *(_QWORD *)&v3.m[2][0] = 0x400000001LL;
    LODWORD(v3.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101401C0
// Name: public: CBugUIPanel::CBugUIPanel(bool,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBugUIPanel *__thiscall CBugUIPanel::CBugUIPanel(CBugUIPanel *this, bool bIsPublic, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  const char *InternalBugReporterDLL; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::Label *v14; // eax
  vgui::Label *v15; // eax
  vgui::Label *v16; // eax
  vgui::Label *v17; // eax
  vgui::Label *v18; // eax
  vgui::Label *v19; // eax
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label *v22; // eax
  vgui::Label *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::TextEntry *v25; // eax
  vgui::Button *v26; // eax
  vgui::Button *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  vgui::Button *v30; // eax
  vgui::Button *v31; // eax
  vgui::Button *v32; // eax
  vgui::Button *v33; // eax
  vgui::Button *v34; // eax
  vgui::Button *v35; // eax
  vgui::Button *v36; // eax
  vgui::Button *v37; // eax
  vgui::Button *v38; // eax
  vgui::Button *v39; // eax
  vgui::Label *v40; // eax
  vgui::Label *v41; // eax
  vgui::Label *v42; // eax
  vgui::Label *v43; // eax
  vgui::Label *v44; // eax
  vgui::Label *v45; // eax
  vgui::Label *v46; // eax
  vgui::Label *v47; // eax
  vgui::ComboBox *v48; // eax
  vgui::ComboBox *v49; // eax
  vgui::ComboBox *v50; // eax
  vgui::ComboBox *v51; // eax
  vgui::ComboBox *v52; // eax
  vgui::ComboBox *v53; // eax
  vgui::ComboBox *v54; // eax
  vgui::ComboBox *v55; // eax
  vgui::ComboBox *v56; // eax
  vgui::ComboBox *v57; // eax
  vgui::ComboBox *v58; // eax
  vgui::ComboBox *v59; // eax
  vgui::ComboBox *v60; // eax
  vgui::ComboBox *v61; // eax
  vgui::Button *v62; // eax
  vgui::Button *v63; // eax
  vgui::Button *v64; // eax
  vgui::Button *v65; // eax
  vgui::Button *v66; // eax
  vgui::Button *v67; // eax
  KeyValues *v68; // eax
  KeyValues *v69; // eax
  int Wide; // edi
  int v71; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  int h; // [esp+14h] [ebp+8h]
  int ha; // [esp+14h] [ebp+8h]

  vgui::Frame::Frame(this, parent, panelName: "BugUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBugUIPanel_vtbl *)&CBugUIPanel::`vftable';
  if ( `CBugUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBugUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
    v4->pfnClassName = CBugUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBugUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBugUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBugUIPanel");
    v5->pfnClassName = CBugUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBugUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBugUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBugUIPanel");
    v6->pfnClassName = CBugUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CBugUIPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CBugUIPanel::PanelMessageFunc_OnDirectorySelected::InitVar(a1: (int)&savedregs);
  CBugUIPanel::PanelMessageFunc_OnChooseVMFFolder::InitVar(a1: (int)&savedregs);
  CBugUIPanel::PanelMessageFunc_OnChooseArea::InitVar(a1: (int)&savedregs);
  this->m_IncludedFiles.m_Memory.m_pMemory = nullptr;
  this->m_IncludedFiles.m_Memory.m_nAllocationCount = 0;
  this->m_IncludedFiles.m_Memory.m_nGrowSize = 0;
  this->m_IncludedFiles.m_Size = 0;
  this->m_IncludedFiles.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_strRemoteBugInfoPath);
  this->m_hFileOpenDialog.m_iPanelID = -1;
  this->m_hDirectorySelectDialog.m_iPanelID = -1;
  this->m_bAddVMF = false;
  this->m_hFinishedDialog.m_iPanelID = -1;
  netadr_s::SetIP(this: &this->m_cserIP, unIP: 0);
  netadr_s::SetPort(this: &this->m_cserIP, newport: 0);
  netadr_s::SetType(this: &this->m_cserIP, newtype: NA_IP);
  this->m_bIsPublic = bIsPublic;
  CUtlString::CUtlString(this: &this->m_sDllName);
  this->m_BugSub = 0;
  if ( this->m_bIsPublic )
    InternalBugReporterDLL = "bugreporter_public";
  else
    InternalBugReporterDLL = GetInternalBugReporterDLL();
  CUtlString::operator=(this: &this->m_sDllName, src: InternalBugReporterDLL);
  this->m_hZip = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDirectorySelectDialog,
    pPanel: nullptr);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
    pPanel: nullptr);
  this->m_pBugReporter = nullptr;
  this->m_hBugReporter = nullptr;
  this->m_bQueryingSteamForCSER = false;
  *(_DWORD *)&this->m_SteamID.m_SteamInstanceID = 0;
  *((_DWORD *)&this->m_SteamID.m_SteamInstanceID + 1) = 0;
  this->m_SteamID.m_SteamLocalUserID.Split.Low32bits = 0;
  this->m_SteamID.m_SteamLocalUserID.Split.High32bits = 0;
  NET_StringToAdr(s: "67.132.200.140:27013", a: &this->m_cserIP);
  this->m_bValidated = false;
  this->m_szScreenShotName[0] = 0;
  this->m_szSaveGameName[0] = 0;
  this->m_szBSPName[0] = 0;
  this->m_szVMFName[0] = 0;
  this->m_szLevel[0] = 0;
  this->m_szVMFContentDirFullpath[0] = 0;
  this->m_IncludedFiles.m_Size = 0;
  if ( this->m_IncludedFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_IncludedFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_IncludedFiles.m_Memory.m_pMemory);
      this->m_IncludedFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_IncludedFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_IncludedFiles.m_pElements = this->m_IncludedFiles.m_Memory.m_pMemory;
  this->m_nSnapShotFrame = -1;
  *(_WORD *)&this->m_bTakingSnapshot = 0;
  *(_WORD *)&this->m_bAutoSubmit = 0;
  this->m_bIsSubmittingRemoteBug = false;
  *(_WORD *)&this->m_bCanSubmit = 0;
  this->m_bCanSeeRepository = false;
  this->m_pProgressDialog = nullptr;
  this->m_flPauseTime = 0.0;
  this->m_bWaitForFinish = false;
  *(_WORD *)&this->m_bUseNameForSubmitter = 0;
  vgui::Frame::SetTitle(this, title: "Bug Reporter", surfaceTitle: true);
  v8 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: "BugTitle");
  else
    v9 = nullptr;
  this->m_pTitle = v9;
  v9->SetMaximumCharCount(this: v9, a2: 60);
  v10 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v10 != nullptr )
    v11 = vgui::TextEntry::TextEntry(this: v10, parent: this, panelName: "BugDescription");
  else
    v11 = nullptr;
  this->m_pDescription = v11;
  v11->SetMultiline(this: v11, a2: true);
  this->m_pDescription->SetCatchEnterKey(this: this->m_pDescription, a2: true);
  this->m_pDescription->SetVerticalScrollbar(this: this->m_pDescription, a2: true);
  v12 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v12 != nullptr )
    v13 = vgui::TextEntry::TextEntry(this: v12, parent: this, panelName: "BugEmail");
  else
    v13 = nullptr;
  this->m_pEmail = v13;
  v13->SetMaximumCharCount(this: v13, a2: 80);
  v14 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v14 != nullptr )
    v15 = vgui::Label::Label(this: v14, parent: this, panelName: "BugSubmitterLabel", text: "Submitter:");
  else
    v15 = nullptr;
  this->m_pSubmitterLabel = v15;
  v16 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v16 != nullptr )
    v17 = vgui::Label::Label(this: v16, parent: this, panelName: "BugScreenShotURL", text: defaultValue);
  else
    v17 = nullptr;
  this->m_pScreenShotURL = v17;
  v18 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v18 != nullptr )
    v19 = vgui::Label::Label(this: v18, parent: this, panelName: "BugSaveGameURL", text: defaultValue);
  else
    v19 = nullptr;
  this->m_pSaveGameURL = v19;
  v20 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v20 != nullptr )
    v21 = vgui::Label::Label(this: v20, parent: this, panelName: "BugBSPURL", text: defaultValue);
  else
    v21 = nullptr;
  this->m_pBSPURL = v21;
  v22 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v22 != nullptr )
    v23 = vgui::Label::Label(this: v22, parent: this, panelName: "BugVMFURL", text: defaultValue);
  else
    v23 = nullptr;
  this->m_pVMFURL = v23;
  v24 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v24 != nullptr )
    v25 = vgui::TextEntry::TextEntry(this: v24, parent: this, panelName: "BugIncludedFiles");
  else
    v25 = nullptr;
  this->m_pIncludedFiles = v25;
  v25->SetMultiline(this: v25, a2: true);
  this->m_pIncludedFiles->SetVerticalScrollbar(this: this->m_pIncludedFiles, a2: true);
  this->m_pIncludedFiles->SetEditable(this: this->m_pIncludedFiles, a2: false);
  v26 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v26 != nullptr )
    v27 = vgui::Button::Button(
            this: v26,
            parent: this,
            panelName: "BugTakeShot",
            text: "Take shot",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v27 = nullptr;
  this->m_pTakeShot = v27;
  v28 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: this,
            panelName: "BugSaveGame",
            text: "Save game",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v29 = nullptr;
  this->m_pSaveGame = v29;
  v30 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v30 != nullptr )
    v31 = vgui::Button::Button(
            this: v30,
            parent: this,
            panelName: "BugSaveBSP",
            text: "Include .bsp",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v31 = nullptr;
  this->m_pSaveBSP = v31;
  v32 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v32 != nullptr )
    v33 = vgui::Button::Button(
            this: v32,
            parent: this,
            panelName: "BugSaveVMF",
            text: "Include .vmf",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v33 = nullptr;
  this->m_pSaveVMF = v33;
  v34 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v34 != nullptr )
    v35 = vgui::Button::Button(
            this: v34,
            parent: this,
            panelName: "BugChooseVMFFolder",
            text: "Choose folder",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v35 = nullptr;
  this->m_pChooseVMFFolder = v35;
  v36 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v36 != nullptr )
    v37 = vgui::Button::Button(
            this: v36,
            parent: this,
            panelName: "BugIncludeFile",
            text: "Include file...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v37 = nullptr;
  this->m_pIncludeFile = v37;
  v38 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v38 != nullptr )
    v39 = vgui::Button::Button(
            this: v38,
            parent: this,
            panelName: "BugClearIncludedFiles",
            text: "Clear files",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v39 = nullptr;
  this->m_pClearIncludes = v39;
  v40 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v40 != nullptr )
    v41 = vgui::Label::Label(this: v40, parent: this, panelName: "BugPosition", text: defaultValue);
  else
    v41 = nullptr;
  this->m_pPosition = v41;
  v42 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v42 != nullptr )
    v43 = vgui::Label::Label(this: v42, parent: this, panelName: "BugOrientation", text: defaultValue);
  else
    v43 = nullptr;
  this->m_pOrientation = v43;
  v44 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v44 != nullptr )
    v45 = vgui::Label::Label(this: v44, parent: this, panelName: "BugLevel", text: defaultValue);
  else
    v45 = nullptr;
  this->m_pLevelName = v45;
  v46 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v46 != nullptr )
    v47 = vgui::Label::Label(this: v46, parent: this, panelName: "BugBuild", text: defaultValue);
  else
    v47 = nullptr;
  this->m_pBuildNumber = v47;
  v48 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v48 != nullptr )
    v49 = vgui::ComboBox::ComboBox(this: v48, parent: this, panelName: "BugSubmitter", numLines: 5, allowEdit: false);
  else
    v49 = nullptr;
  this->m_pSubmitter = v49;
  v50 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v50 != nullptr )
    v51 = vgui::ComboBox::ComboBox(this: v50, parent: this, panelName: "BugOwner", numLines: 10, allowEdit: false);
  else
    v51 = nullptr;
  this->m_pAssignTo = v51;
  v52 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v52 != nullptr )
    v53 = vgui::ComboBox::ComboBox(this: v52, parent: this, panelName: "BugSeverity", numLines: 10, allowEdit: false);
  else
    v53 = nullptr;
  this->m_pSeverity = v53;
  v54 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v54 != nullptr )
    v55 = vgui::ComboBox::ComboBox(this: v54, parent: this, panelName: "BugReportType", numLines: 10, allowEdit: false);
  else
    v55 = nullptr;
  this->m_pReportType = v55;
  v56 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v56 != nullptr )
    v57 = vgui::ComboBox::ComboBox(this: v56, parent: this, panelName: "BugPriority", numLines: 10, allowEdit: false);
  else
    v57 = nullptr;
  this->m_pPriority = v57;
  v58 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v58 != nullptr )
    v59 = vgui::ComboBox::ComboBox(this: v58, parent: this, panelName: "BugArea", numLines: 10, allowEdit: false);
  else
    v59 = nullptr;
  this->m_pGameArea = v59;
  v60 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v60 != nullptr )
    v61 = vgui::ComboBox::ComboBox(this: v60, parent: this, panelName: "BugMapNumber", numLines: 10, allowEdit: false);
  else
    v61 = nullptr;
  this->m_pMapNumber = v61;
  v62 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v62 != nullptr )
    v63 = vgui::Button::Button(
            this: v62,
            parent: this,
            panelName: "BugSubmit",
            text: "Submit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v63 = nullptr;
  this->m_pSubmit = v63;
  v64 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v64 != nullptr )
    v65 = vgui::Button::Button(
            this: v64,
            parent: this,
            panelName: "BugCancel",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v65 = nullptr;
  this->m_pCancel = v65;
  v66 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v66 != nullptr )
    v67 = vgui::Button::Button(
            this: v66,
            parent: this,
            panelName: "BugClearForm",
            text: "Clear Form",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v67 = nullptr;
  this->m_pClearForm = v67;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  if ( this->m_bIsPublic )
    vgui::Frame::LoadControlSettings(
      this,
      dialogResourceName: "Resource\\BugUIPanel_Public.res",
      pathID: nullptr,
      pPreloadedKeyValues: nullptr,
      pConditions: nullptr);
  else
    vgui::Frame::LoadControlSettings(
      this,
      dialogResourceName: "Resource\\BugUIPanel_Filequeue.res",
      pathID: nullptr,
      pPreloadedKeyValues: nullptr,
      pConditions: nullptr);
  v68 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v68 != nullptr )
    v69 = KeyValues::KeyValues(this: v68, setName: "OnChooseVMFFolder");
  else
    v69 = nullptr;
  this->m_pChooseVMFFolder->SetCommand(this: this->m_pChooseVMFFolder, a2: v69);
  this->m_pChooseVMFFolder->AddActionSignalTarget_2(this: this->m_pChooseVMFFolder, a2: this);
  Wide = vgui::Panel::GetWide(this);
  h = vgui::Panel::GetTall(this);
  v71 = (videomode->GetModeWidth(this: videomode) - Wide) / 2;
  ha = (videomode->GetModeHeight(this: videomode) - h) / 2;
  this->IsVisible(this);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  vgui::Panel::SetPos(this, x: v71, y: ha);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10140AF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBugUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBugUIPanel::GetMessageMap(CBugUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBugUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBugUIPanel::GetMessageMap'::`2'::s_pMap;
  `CBugUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBugUIPanel");
  `CBugUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10140B20
// Name: public: virtual struct PanelAnimationMap __near * CBugUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBugUIPanel::GetAnimMap(CBugUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBugUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10140B30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBugUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBugUIPanel::GetKBMap(CBugUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBugUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBugUIPanel::GetKBMap'::`2'::s_pMap;
  `CBugUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBugUIPanel");
  `CBugUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10140B60
// Name: public: virtual CBugUIPanel::~CBugUIPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::~CBugUIPanel(CBugUIPanel *this)
{
  this->__vftable = (CBugUIPanel_vtbl *)&CBugUIPanel::`vftable';
  this->m_sDllName.m_Storage.m_nActualLength = 0;
  if ( this->m_sDllName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sDllName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sDllName.m_Storage.m_Memory.m_pMemory);
      this->m_sDllName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sDllName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_strRemoteBugInfoPath.m_Storage.m_nActualLength = 0;
  if ( this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_pMemory);
      this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_strRemoteBugInfoPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_IncludedFiles);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10140BF0
// Name: protected: virtual void CBugUIPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnFileSelected(CBugUIPanel *this, char *fullpath)
{
  CBugUIPanel *v2; // edi
  char v3; // bl
  bool v4; // zf
  vgui::Panel *v5; // eax
  CUtlVector<CBugUIPanel::includedfile,CUtlMemory<CBugUIPanel::includedfile,int> > *p_m_IncludedFiles; // ebx
  int v7; // esi
  int v8; // edi
  char v9[8192]; // [esp+8h] [ebp-2410h] BYREF
  char pDest[512]; // [esp+2008h] [ebp-410h] BYREF
  CBugUIPanel::includedfile src; // [esp+2208h] [ebp-210h] BYREF
  char dest[12]; // [esp+2408h] [ebp-10h] BYREF
  CBugUIPanel *v13; // [esp+2414h] [ebp-4h]

  v2 = this;
  v3 = 0;
  v4 = this->m_pBugReporter == nullptr;
  v13 = this;
  if ( (v4 || !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter)) && fullpath != nullptr && *fullpath != 0 )
  {
    if ( !g_pFileSystem->FullPathToRelativePath(this: g_pFileSystem, a2: fullpath, a3: pDest, a4: 512) )
    {
      if ( V_stristr(pStr: fullpath, pSearch: com_basedir) == nullptr )
      {
        _Msg(a1: "Only files beneath the base game directory can be included\n");
        return;
      }
      V_snprintf(pDest, maxLen: 512, pFormat: "..%s", &fullpath[strlen(com_basedir)]);
      v3 = 1;
    }
    V_ExtractFileExtension(path: pDest, dest, destSize: 10);
    if ( vgui::PHandle::Get(this: &v2->m_hFileOpenDialog) != nullptr )
    {
      v5 = vgui::PHandle::Get(this: &v2->m_hFileOpenDialog);
      v5->MarkForDeletion(this: v5);
    }
    V_strncpy(pDest: src.name, pSrc: pDest, maxLen: 256);
    if ( v3 != 0 )
      V_snprintf(pDest: src.fixedname, maxLen: 256, pFormat: "%s", &src.name[3]);
    else
      V_snprintf(pDest: src.fixedname, maxLen: 256, pFormat: "%s", &src);
    V_FixSlashes(pname: src.fixedname, separator: 92);
    p_m_IncludedFiles = &v2->m_IncludedFiles;
    CUtlVector<CBugUIPanel::includedfile,CUtlMemory<CBugUIPanel::includedfile,int>>::InsertBefore(
      this: &v2->m_IncludedFiles,
      elem: v2->m_IncludedFiles.m_Size,
      &src);
    v7 = 0;
    v9[0] = 0;
    if ( v2->m_IncludedFiles.m_Size > 0 )
    {
      v8 = 0;
      do
      {
        V_strncat(
          pDest: v9,
          pSrc: p_m_IncludedFiles->m_Memory.m_pMemory[v8].name,
          destBufferSize: 0x2000u,
          max_chars_to_copy: -1);
        V_strncat(pDest: v9, pSrc: "\n", destBufferSize: 0x2000u, max_chars_to_copy: -1);
        ++v7;
        ++v8;
      }
      while ( v7 < v13->m_IncludedFiles.m_Size );
      v2 = v13;
    }
    v2->m_pIncludedFiles->SetText(this: v2->m_pIncludedFiles, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140E00
// Name: public: virtual void CEngineBugReporter::InstallBugReportingUI(class vgui::Panel __near *,enum IEngineBugReporter::BR_TYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineBugReporter::InstallBugReportingUI(
        CEngineBugReporter *this,
        CDragDropHelperPanel *parent,
        IEngineBugReporter::BR_TYPE type)
{
  const char *InternalBugReporterDLL; // eax
  bool (__thiscall *FileExists)(IBaseFileSystem *, const char *, const char *); // edx
  EUniverse SteamUniverse; // eax
  CBugUIPanel *v7; // eax
  char fn[512]; // [esp+4h] [ebp-204h] BYREF
  BOOL bUsePublic; // [esp+204h] [ebp-4h]

  if ( g_pBugUI != nullptr )
    return;
  InternalBugReporterDLL = GetInternalBugReporterDLL();
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "%s.dll", InternalBugReporterDLL);
  FileExists = g_pFileSystem->FileExists;
  LOBYTE(bUsePublic) = 1;
  if ( FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: fn, a3: "EXECUTABLE_PATH") && type != BR_PUBLIC )
  {
    if ( type == BR_INTERNAL )
    {
      LOBYTE(bUsePublic) = 0;
      goto LABEL_6;
    }
    SteamUniverse = GetSteamUniverse();
    LOBYTE(bUsePublic) = SteamUniverse == k_EUniversePublic;
    if ( SteamUniverse != k_EUniversePublic )
LABEL_6:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&bugreporter_uploadasync.IConVar, value: 1);
  }
  v7 = (CBugUIPanel *)MemAlloc_Alloc(nSize: 0x930u);
  if ( v7 != nullptr )
    g_pBugUI = CBugUIPanel::CBugUIPanel(this: v7, bIsPublic: bUsePublic, parent);
  else
    g_pBugUI = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_ParentPanel,
    pPanel: parent);
}

//------------------------------------------------------------------------------
// Address: 0x10140F80
// Name: protected: bool CBugUIPanel::UploadBugSubmission(char const __near *,int,char const __near *,char const __near *,char const __near *,char const __near *,class CUtlVector<struct CBugUIPanel::includedfile,class CUtlMemory<struct CBugUIPanel::includedfile,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugUIPanel::UploadBugSubmission(
        CBugUIPanel *this,
        const char *levelname,
        int bugId,
        const char *savefile,
        char *screenshot,
        const char *bsp,
        const char *vmf,
        CUtlVector<CBugUIPanel::includedfile,CUtlMemory<CBugUIPanel::includedfile,int> > *files)
{
  int m_nValue; // eax
  const char *v10; // esi
  char *SubmissionURL; // eax
  const char *v12; // esi
  char *v13; // eax
  const char *v14; // edi
  void *v15; // esi
  char *v16; // eax
  const char *v17; // esi
  char *v18; // eax
  CUtlVector<CBugUIPanel::includedfile,CUtlMemory<CBugUIPanel::includedfile,int> > *v19; // esi
  const char *m_Size; // eax
  const char *v21; // edi
  const char *v22; // esi
  const char *v23; // eax
  const char *v24; // eax
  char *v25; // eax
  loopback_t *v26; // esi
  bool (__thiscall *v27)(CBugUIPanel *, const char *, const char *, bool); // ecx
  CTSQueue<loopback_t *,0,1>::Node_t *v28; // eax
  bool v29; // zf
  char remotefile[512]; // [esp+Ch] [ebp-434h] BYREF
  char localfile[512]; // [esp+20Ch] [ebp-234h] BYREF
  bool (__thiscall *v33)(CBugUIPanel *, const char *, const char *, bool); // [esp+40Ch] [ebp-34h]
  CUtlString v34; // [esp+41Ch] [ebp-24h] BYREF
  bool bAsync; // [esp+42Fh] [ebp-11h]
  CUtlString src; // [esp+430h] [ebp-10h] BYREF

  if ( bugreporter_uploadasync.m_pParent != nullptr )
    m_nValue = bugreporter_uploadasync.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v10 = savefile;
  bAsync = m_nValue != 0;
  if ( savefile != nullptr && *savefile != 0 )
  {
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/save/%s.sav", com_gamedir, savefile);
    SubmissionURL = CBugUIPanel::GetSubmissionURL(this, bugid: bugId);
    V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s.sav", SubmissionURL, v10);
    V_FixSlashes(pname: localfile, separator: 92);
    V_FixSlashes(pname: remotefile, separator: 92);
    HIBYTE(savefile) = 0;
    CUtlString::CUtlString(this: &v34);
    CUtlString::operator=(this: &v34, src: remotefile);
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: localfile);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
      this: &g_UploadQueue,
      pObject: this,
      pfnProxied: (unsigned int)CBugUIPanel::UploadFile,
      arg1: (const CUtlEnvelope<char const *> *)&src,
      arg2: (const CUtlEnvelope<char const *> *)&v34,
      arg3: (bool *)&savefile + 3);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
        src.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      src.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v34.m_Storage.m_nActualLength = 0;
    if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
  }
  v12 = screenshot;
  if ( screenshot != nullptr && *screenshot != 0 )
  {
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/screenshots/%s.jpg", com_gamedir, screenshot);
    v13 = CBugUIPanel::GetSubmissionURL(this, bugid: bugId);
    V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s.jpg", v13, v12);
    V_FixSlashes(pname: localfile, separator: 92);
    V_FixSlashes(pname: remotefile, separator: 92);
    HIBYTE(savefile) = 0;
    CUtlString::CUtlString(this: &v34);
    CUtlString::operator=(this: &v34, src: remotefile);
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: localfile);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
      this: &g_UploadQueue,
      pObject: this,
      pfnProxied: (unsigned int)CBugUIPanel::UploadFile,
      arg1: (const CUtlEnvelope<char const *> *)&src,
      arg2: (const CUtlEnvelope<char const *> *)&v34,
      arg3: (bool *)&savefile + 3);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
        src.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      src.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v34.m_Storage.m_nActualLength = 0;
    if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
  }
  v14 = bsp;
  if ( bsp != nullptr && *bsp != 0 )
  {
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "maps/%s.bsp", levelname);
    v15 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: localfile, a3: "rb", a4: 0, a5: 0, a6: &screenshot);
    if ( v15 != nullptr )
    {
      V_strncpy(pDest: localfile, pSrc: screenshot, maxLen: 512);
      free(pMem: screenshot);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v15);
    }
    else
    {
      V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/maps/%s.bsp", com_gamedir, levelname);
    }
    v16 = CBugUIPanel::GetSubmissionURL(this, bugid: bugId);
    V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s.bsp", v16, v14);
    V_FixSlashes(pname: localfile, separator: 92);
    V_FixSlashes(pname: remotefile, separator: 92);
    HIBYTE(savefile) = 0;
    CUtlString::CUtlString(this: &v34);
    CUtlString::operator=(this: &v34, src: remotefile);
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: localfile);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
      this: &g_UploadQueue,
      pObject: this,
      pfnProxied: (unsigned int)CBugUIPanel::UploadFile,
      arg1: (const CUtlEnvelope<char const *> *)&src,
      arg2: (const CUtlEnvelope<char const *> *)&v34,
      arg3: (bool *)&savefile + 3);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
        src.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      src.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v34.m_Storage.m_nActualLength = 0;
    if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 && v34.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
  }
  v17 = vmf;
  if ( vmf != nullptr && *vmf != 0 )
  {
    V_snprintf(pDest: localfile, maxLen: 512, pFormat: "%s/%s.vmf", this->m_szVMFContentDirFullpath, levelname);
    if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: localfile, a3: nullptr) )
    {
      v18 = CBugUIPanel::GetSubmissionURL(this, bugid: bugId);
      V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s.vmf", v18, v17);
      V_FixSlashes(pname: localfile, separator: 92);
      V_FixSlashes(pname: remotefile, separator: 92);
      HIBYTE(levelname) = 0;
      CUtlString::CUtlString(this: &src);
      CUtlString::operator=(this: &src, src: remotefile);
      CUtlString::CUtlString(this: &v34);
      CUtlString::operator=(this: &v34, src: localfile);
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
        this: &g_UploadQueue,
        pObject: this,
        pfnProxied: (unsigned int)CBugUIPanel::UploadFile,
        arg1: (const CUtlEnvelope<char const *> *)&v34,
        arg2: (const CUtlEnvelope<char const *> *)&src,
        arg3: (bool *)&levelname + 3);
      CUtlString::~CUtlString(this: &v34);
      CUtlString::~CUtlString(this: &src);
    }
    else
    {
      _Msg(a1: "Unable to locate .vmf file %s\n", localfile);
    }
  }
  v19 = files;
  m_Size = (const char *)files->m_Size;
  if ( (int)m_Size <= 0 )
  {
    if ( bAsync )
      ThreadExecuteSolo<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void)>(
        pszName: "BugUpload",
        a1: &g_UploadQueue,
        a2: (unsigned int)CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued);
    else
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_UploadQueue);
    return 1;
  }
  else
  {
    v21 = nullptr;
    v33 = CBugUIPanel::UploadFile;
    levelname = nullptr;
    savefile = m_Size;
    while ( 1 )
    {
      V_snprintf(
        pDest: localfile,
        maxLen: 512,
        pFormat: "%s/%s",
        com_gamedir,
        &v21[(unsigned int)v19->m_Memory.m_pMemory]);
      v22 = &v21[(unsigned int)v19->m_Memory.m_pMemory];
      v23 = this->m_pBugReporter->GetSubmissionURL(this: this->m_pBugReporter);
      if ( v23 == nullptr )
      {
        v24 = this->m_pBugReporter->GetRepositoryURL(this: this->m_pBugReporter);
        if ( v24 == nullptr )
          v24 = "\\\\fileserver\\bugs";
        V_snprintf(pDest: url, maxLen: 512, pFormat: "%s/%i", v24, bugId);
        v23 = url;
      }
      V_snprintf(pDest: remotefile, maxLen: 512, pFormat: "%s/%s", v23, v22 + 256);
      V_FixSlashes(pname: localfile, separator: 92);
      V_FixSlashes(pname: remotefile, separator: 92);
      CUtlString::CUtlString(this: &v34);
      CUtlString::operator=(this: &v34, src: remotefile);
      CUtlString::CUtlString(this: &src);
      CUtlString::operator=(this: &src, src: localfile);
      v25 = (char *)MemAlloc_Alloc(nSize: 0x50u);
      v26 = (loopback_t *)v25;
      if ( v25 != nullptr )
      {
        v27 = v33;
        *((_DWORD *)v25 + 3) = 1;
        *(_DWORD *)v25 = &CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        *((_DWORD *)v25 + 2) = &CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        *((_DWORD *)v25 + 4) = v27;
        *((_DWORD *)v25 + 5) = 0;
        *((_DWORD *)v25 + 6) = 0;
        *((_DWORD *)v25 + 7) = 0;
        *((_DWORD *)v25 + 8) = this;
        CUtlString::CUtlString(this: (CUtlString *)(v25 + 40));
        CUtlString::operator=(this: (CUtlString *)&v26->defbuffer[32], &src);
        CUtlString::CUtlString(this: (CUtlString *)&v26->defbuffer[48]);
        CUtlString::operator=(this: (CUtlString *)&v26->defbuffer[48], src: &v34);
        v21 = levelname;
        v26->defbuffer[64] = 0;
      }
      else
      {
        v26 = nullptr;
      }
      if ( g_UploadQueue.m_bNoQueue )
      {
        (*((void (__thiscall **)(loopback_t *))v26->data + 3))(a1: v26);
        (*((void (__thiscall **)(loopback_t *))v26->data + 1))(a1: v26);
      }
      else
      {
        v28 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &g_UploadQueue.m_queue.m_FreeNodes);
        if ( v28 != nullptr || (v28 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
        {
          v28->elem = v26;
          CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_UploadQueue, pNode: v28);
        }
        else
        {
          CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_UploadQueue, pNode: nullptr);
        }
      }
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
          src.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        src.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v34.m_Storage.m_nActualLength = 0;
      if ( v34.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v34.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Storage.m_Memory.m_pMemory);
          v34.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v34.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v21 += 512;
      v29 = savefile-- == (const char *)1;
      levelname = v21;
      if ( v29 )
        break;
      v19 = files;
    }
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_UploadQueue);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141740
// Name: protected: void CBugUIPanel::OnFinishBugReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugUIPanel::OnFinishBugReport(CBugUIPanel *this)
{
  IBugReporter *m_pBugReporter; // ecx
  bool v3; // bl
  int v4; // eax
  const char *v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v8; // [esp-8h] [ebp-14h]
  int bugId; // [esp+8h] [ebp-4h] BYREF

  m_pBugReporter = this->m_pBugReporter;
  bugId = -1;
  v3 = m_pBugReporter->CommitBugReport(this: m_pBugReporter, a2: &bugId);
  if ( !v3 )
  {
    _Warning(a1: "Unable to post bug report to database\n");
LABEL_8:
    v8 = va(format: "play %s\n", "common/bugreporter_failed");
    TraceType = CTraceFilter::GetTraceType(this: v6);
    Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
    this->m_bWaitForFinish = false;
    return;
  }
  if ( !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter)
    && CBugUIPanel::UploadBugSubmission(
         this,
         levelname: this->m_szLevel,
         bugId,
         savefile: this->m_szSaveGameName,
         screenshot: this->m_szScreenShotName,
         bsp: this->m_szBSPName,
         vmf: this->m_szVMFName,
         files: &this->m_IncludedFiles) == 0 )
  {
    _Warning(a1: "Unable to upload saved game and screenshot to bug repository!\n");
    v3 = false;
  }
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-remotebug", a3: 0) != 0 )
  {
    v5 = this->m_pBugReporter->GetSubmissionURL(this: this->m_pBugReporter);
    CServerRemoteAccess::RemoteBug(this: &g_ServerRemoteAccess, pBugPath: v5);
  }
  if ( !v3 )
    goto LABEL_8;
  CBugUIPanel::WipeData(this);
  CBugUIPanel::SuccessSound(this, bugId);
  if ( !this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
  {
    this->Close(this);
    ++this->m_BugSub;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141880
// Name: protected: void CBugUIPanel::OnSubmit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::OnSubmit(CBugUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t TraceType; // eax
  bool v6; // al
  IBugReporter *m_pBugReporter; // ecx
  char *v8; // eax
  bool v9; // al
  IMaterialSystem_vtbl *v10; // edi
  int v11; // eax
  const MaterialSystem_Config_t *v12; // edi
  int v13; // eax
  const char *v14; // ebx
  MaterialThreadMode_t v15; // eax
  __int32 v16; // eax
  int v17; // ecx
  const char *v18; // eax
  const char *v19; // edi
  int v20; // eax
  int v21; // eax
  CClientState *BaseLocalClient; // eax
  int m_nValue; // ebx
  double v24; // st7
  double v25; // st7
  int v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // ebx
  IBaseFileSystem *v29; // eax
  KeyValues *i; // edi
  const char *String; // eax
  const char *Name; // eax
  IBaseFileSystem_vtbl *v33; // edi
  int v34; // eax
  int v35; // eax
  IMatchSession *v36; // eax
  IMatchSession *v37; // edi
  KeyValues *v38; // eax
  KeyValues *v39; // eax
  int v40; // ecx
  double v41; // st7
  int v42; // edi
  int v43; // eax
  int j; // edi
  signed int v45; // ebx
  const char *v46; // eax
  const char *v47; // eax
  int v48; // edx
  int m_Put; // ebx
  IBugReporter *v50; // ecx
  IBugReporter_vtbl *v51; // ebx
  int v52; // eax
  IBugReporter *v53; // ecx
  IBugReporter_vtbl *v54; // ebx
  int v55; // eax
  int v56; // ebx
  int CPUInformation; // edi
  IBugReporter *v58; // ebx
  IBugReporter_vtbl *v59; // edx
  int v60; // ecx
  IBugReporter_vtbl *v61; // edx
  int v62; // edi
  char *v63; // eax
  char *v64; // ebx
  unsigned __int8 *m_pMemory; // ecx
  char *v66; // eax
  int v67; // edi
  unsigned int v68; // edi
  HZIP__ *ZipZ; // eax
  char v70; // bl
  char v71; // al
  HZIP__ *m_hZip; // ecx
  void *v73; // eax
  void *v74; // edi
  ECommandTarget_t v75; // eax
  const char *v76; // eax
  const char *v77; // eax
  const char *v78; // eax
  const char *v79; // eax
  int v80; // ebx
  char *v81; // edi
  const char *v82; // eax
  CBugReportUploadProgressDialog *v83; // eax
  CBugReportUploadProgressDialog *v84; // eax
  vgui::IInput *v85; // ebx
  vgui::IInput_vtbl *v86; // edi
  unsigned int v87; // eax
  int v88; // [esp+4Ch] [ebp-649Ch]
  int v89; // [esp+50h] [ebp-6498h]
  int v90; // [esp+50h] [ebp-6498h]
  double v91; // [esp+54h] [ebp-6494h]
  int v92; // [esp+54h] [ebp-6494h]
  int v93; // [esp+58h] [ebp-6490h]
  const char *v94; // [esp+5Ch] [ebp-648Ch]
  int v95; // [esp+5Ch] [ebp-648Ch]
  int v96; // [esp+5Ch] [ebp-648Ch]
  const char *v97; // [esp+60h] [ebp-6488h]
  int v98; // [esp+60h] [ebp-6488h]
  int v99; // [esp+60h] [ebp-6488h]
  const char *v100; // [esp+60h] [ebp-6488h]
  char *v101; // [esp+60h] [ebp-6488h]
  const char *v102; // [esp+64h] [ebp-6484h]
  int v103; // [esp+64h] [ebp-6484h]
  const char *v104; // [esp+64h] [ebp-6484h]
  int v105; // [esp+64h] [ebp-6484h]
  int v106[2048]; // [esp+6Ch] [ebp-647Ch] BYREF
  char v107[8192]; // [esp+206Ch] [ebp-447Ch] BYREF
  char v108[2048]; // [esp+406Ch] [ebp-247Ch] BYREF
  char dest[996]; // [esp+486Ch] [ebp-1C7Ch] BYREF
  CFmtStrN<1040> v110; // [esp+4C50h] [ebp-1898h] BYREF
  char v111[256]; // [esp+506Ch] [ebp-147Ch] BYREF
  char v112[512]; // [esp+516Ch] [ebp-137Ch] BYREF
  unsigned int v113; // [esp+536Ch] [ebp-117Ch]
  unsigned int v114; // [esp+5370h] [ebp-1178h]
  int v115; // [esp+5374h] [ebp-1174h]
  int v116; // [esp+5378h] [ebp-1170h]
  char v117[256]; // [esp+5390h] [ebp-1158h] BYREF
  char v118[256]; // [esp+5490h] [ebp-1058h] BYREF
  char v119[256]; // [esp+5590h] [ebp-F58h] BYREF
  char v120[256]; // [esp+5690h] [ebp-E58h] BYREF
  char v121[256]; // [esp+5790h] [ebp-D58h] BYREF
  char v122[256]; // [esp+5890h] [ebp-C58h] BYREF
  char v123[256]; // [esp+5990h] [ebp-B58h] BYREF
  char str[256]; // [esp+5A90h] [ebp-A58h] BYREF
  char v125[256]; // [esp+5B90h] [ebp-958h] BYREF
  char v126[256]; // [esp+5C90h] [ebp-858h] BYREF
  char pSrc[256]; // [esp+5D90h] [ebp-758h] BYREF
  char osversion[128]; // [esp+5E90h] [ebp-658h] BYREF
  char v129[256]; // [esp+5F10h] [ebp-5D8h] BYREF
  char pDest[256]; // [esp+6010h] [ebp-4D8h] BYREF
  char pname[512]; // [esp+6110h] [ebp-3D8h] BYREF
  char v132[4]; // [esp+6310h] [ebp-1D8h] BYREF
  char pFixedName[256]; // [esp+6314h] [ebp-1D4h] BYREF
  _MEMORYSTATUS Buffer; // [esp+6414h] [ebp-D4h] BYREF
  CUtlBuffer buf; // [esp+6434h] [ebp-B4h] BYREF
  CUtlBuffer v136; // [esp+6464h] [ebp-84h] BYREF
  char v137[16]; // [esp+6494h] [ebp-54h] BYREF
  CUtlBuffer v138; // [esp+64A4h] [ebp-44h] BYREF
  char v139; // [esp+64D7h] [ebp-11h]
  _DWORD v140[3]; // [esp+64D8h] [ebp-10h] BYREF
  char v141; // [esp+64E7h] [ebp-1h]

  if ( !this->m_bCanSubmit )
    return;
  if ( !CBugUIPanel::IsValidSubmission(this, verbose: true) )
  {
    v97 = va(format: "play %s\n", "common/bugreporter_failed");
    TraceType = CTraceFilter::GetTraceType(this: v4);
    Cbuf_AddText(eTarget: TraceType, pText: v97, nTickDelay: 0);
    return;
  }
  v6 = this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter);
  m_pBugReporter = this->m_pBugReporter;
  v141 = v6;
  pDest[0] = 0;
  v107[0] = 0;
  v118[0] = 0;
  v122[0] = 0;
  v119[0] = 0;
  v117[0] = 0;
  v125[0] = 0;
  pSrc[0] = 0;
  v126[0] = 0;
  v123[0] = 0;
  v129[0] = 0;
  v121[0] = 0;
  str[0] = 0;
  m_pBugReporter->StartNewBugReport(this: m_pBugReporter);
  if ( this->m_bIsSubmittingRemoteBug )
    CBugUIPanel::CopyInfoFromRemoteBug(this, a2, a3);
  ((void (__thiscall *)(vgui::TextEntry *, char *, int, int, int))this->m_pTitle->GetText_2)(
    a1: this->m_pTitle,
    a2: v120,
    a3: 256,
    a4: a3,
    a5: a2);
  if ( this->m_bIsSubmittingRemoteBug )
  {
    if ( this->m_szLevel[0] == 0 )
      V_strncpy(pDest: this->m_szLevel, pSrc: "console", maxLen: 256);
    V_strncpy(pDest: pFixedName, pSrc: this->m_szLevel, maxLen: 256);
    goto LABEL_13;
  }
  if ( host_state.worldmodel != nullptr )
  {
    v8 = (char *)modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
    CL_SetupMapName(pName: v8, pFixedName, maxlen: 256);
LABEL_13:
    V_snprintf(pDest, maxLen: 256, pFormat: "%s: %s", pFixedName, v120);
    goto LABEL_14;
  }
  V_snprintf(pDest, maxLen: 256, pFormat: "%s", v120);
LABEL_14:
  _Msg(a1: "title:  %s\n", pDest);
  this->m_pDescription->GetText_2(this: this->m_pDescription, a2: v107, a3: 0x2000);
  _Msg(a1: "description:  %s\n", v107);
  this->m_pLevelName->GetText(this: this->m_pLevelName, a2: pSrc, a3: 256);
  this->m_pPosition->GetText(this: this->m_pPosition, a2: v123, a3: 256);
  this->m_pOrientation->GetText(this: this->m_pOrientation, a2: v126, a3: 256);
  this->m_pBuildNumber->GetText(this: this->m_pBuildNumber, a2: v129, a3: 256);
  v9 = g_pFileSystem->IsSteam(this: g_pFileSystem);
  v106[0] = -1;
  if ( v9 )
    V_strncat(pDest: v129, pSrc: " (Steam)", destBufferSize: 0x100u, max_chars_to_copy: v106[0]);
  else
    V_strncat(pDest: v129, pSrc: " (VSS)", destBufferSize: 0x100u, max_chars_to_copy: v106[0]);
  v10 = materials->__vftable;
  v11 = ((int (__thiscall *)(IMaterialSystem *, char *))materials->GetCurrentAdapter)(a1: materials, a2: v112);
  ((void (__thiscall *)(IMaterialSystem *, int))v10->GetDisplayAdapterInfo)(a1: materials, a2: v11);
  v12 = materials->GetCurrentConfigForVideoCard(this: materials);
  v140[2] = "Unk";
  if ( g_pMaterialSystemHardwareConfig != nullptr )
  {
    v13 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
    v140[2] = COM_DXLevelToString(dxlevel: v13);
  }
  v14 = "???";
  if ( g_pMaterialSystem != nullptr )
  {
    v15 = g_pMaterialSystem->GetThreadMode(this: g_pMaterialSystem);
    if ( v15 != MATERIAL_SINGLE_THREADED )
    {
      v16 = v15 - 1;
      if ( v16 != 0 )
      {
        if ( v16 == 1 )
          v14 = "MATERIAL_QUEUED_THREADED";
        else
          v14 = "unknown";
      }
      else
      {
        v14 = "MATERIAL_QUEUED_SINGLE_THREADED";
      }
    }
    else
    {
      v14 = "MATERIAL_SINGLE_THREADED";
    }
  }
  v17 = *CVProfile::FindOrCreateCounter(
           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
           a2: "reacquire_resources",
           a3: COUNTER_GROUP_NO_RESET);
  if ( (v12->m_Flags & 1) != 0 )
  {
    if ( (v12->m_Flags & 0x20000) != 0 )
      v18 = "Windowed no border";
    else
      v18 = "Windowed";
  }
  else
  {
    v18 = "Fullscreen";
  }
  v19 = (const char *)v140[2];
  if ( v140[2] == 0 )
    v19 = "Unk";
  v20 = ((int (__thiscall *)(IVideoMode *, _DWORD, _DWORD, const char *, int, const char *))videomode->GetModeHeight)(
          a1: videomode,
          a2: COERCE_UNSIGNED_INT64(g_fFramesPerSecond),
          a3: HIDWORD(COERCE_UNSIGNED_INT64(g_fFramesPerSecond)),
          a4: v18,
          a5: v17,
          a6: v14);
  v21 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: v20);
  V_snprintf(
    pDest: v108,
    maxLen: 2048,
    pFormat: "Driver Name:  %s\n"
    "VendorId / DeviceId:  0x%x / 0x%x\n"
    "SubSystem / Rev:  0x%x / 0x%x\n"
    "DXLevel:  %s\n"
    "Vid:  %i x %i\n"
    "Framerate:  %.3f\n"
    "Window mode: %s\n"
    "Number of ReaquireResource events (lost device): %d\n"
    "Material system thread mode: %s",
    v112,
    v113,
    v114,
    v115,
    v116,
    v19,
    v21,
    v89,
    v91,
    v94,
    v98,
    v102);
  _Msg(a1: "%s\n", v108);
  v140[2] = 0;
  if ( GetBaseLocalClient()->m_NetChannel != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    v140[2] = (int)(((double (__thiscall *)(INetChannel *, _DWORD))BaseLocalClient->m_NetChannel->GetAvgLatency)(
                      a1: BaseLocalClient->m_NetChannel,
                      a2: 0)
                  * 1000.0);
  }
  if ( (_S1_15 & 1) == 0 )
  {
    _S1_15 |= 1u;
    ConVarRef::ConVarRef(this: &host_thread_mode, pName: "host_thread_mode");
  }
  if ( (_S1_15 & 2) == 0 )
  {
    _S1_15 |= 2u;
    ConVarRef::ConVarRef(this: &sv_alternateticks, pName: "sv_alternateticks");
  }
  if ( (_S1_15 & 4) == 0 )
  {
    _S1_15 |= 4u;
    ConVarRef::ConVarRef(this: &ai_strong_optimizations, pName: "ai_strong_optimizations");
  }
  if ( (_S1_15 & 8) == 0 )
  {
    _S1_15 |= 8u;
    ConVarRef::ConVarRef(this: &mat_queue_mode, pName: "mat_queue_mode");
  }
  CUtlBuffer::CUtlBuffer(this: &v136, growSize: 0, initSize: 0, nFlags: 1);
  if ( (_S1_15 & 0x10) == 0 )
  {
    _S1_15 |= 0x10u;
    ConVarRef::ConVarRef(this: &skill, pName: "skill");
  }
  m_nValue = skill.m_pConVarState->m_Value.m_nValue;
  v24 = ((double (__thiscall *)(ConVar_ServerBounded *, _DWORD, int, int, int, int))cl_cmdrate->GetFloat)(
          a1: cl_cmdrate,
          a2: v140[2],
          a3: host_thread_mode.m_pConVarState->m_Value.m_nValue,
          a4: sv_alternateticks.m_pConVarState->m_Value.m_nValue,
          a5: ai_strong_optimizations.m_pConVarState->m_Value.m_nValue,
          a6: mat_queue_mode.m_pConVarState->m_Value.m_nValue);
  v25 = ((double (__thiscall *)(ConVar_ServerBounded *, int))cl_updaterate->GetFloat)(a1: cl_updaterate, a2: (int)v24);
  v26 = ((int (__thiscall *)(ConVar_ServerBounded *, int))cl_rate->GetInt)(a1: cl_rate, a2: (int)v25);
  CUtlBuffer::Printf(
    this: &v136,
    pFmt: "Convars:\n"
    "\tskill:  %i\n"
    "\tnet:  rate %i update %i cmd %i latency %i msec\n"
    "\thost_thread_mode:  %i\n"
    "\tsv_alternateticks:  %i\n"
    "\tai_strong_optimizations:  %i\n"
    "\tmat_queue_mode: %i\n",
    m_nValue,
    v26,
    v88,
    v90,
    v92,
    v93,
    v95,
    v99,
    v103);
  v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v27 != nullptr )
    v28 = KeyValues::KeyValues(this: v27, setName: "bugreport_convars");
  else
    v28 = nullptr;
  if ( g_pFileSystem != nullptr )
    v29 = &g_pFileSystem->IBaseFileSystem;
  else
    v29 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v28,
         filesystem: v29,
         resourceName: "scripts/bugreport_convars.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( i = KeyValues::GetFirstSubKey(this: v28); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
      ConVarRef::ConVarRef(this: (ConVarRef *)v140, pName: String);
      if ( ConVarRef::IsValid(this: (ConVarRef *)v140) )
      {
        v104 = *(const char **)(v140[1] + 36);
        Name = KeyValues::GetName(this: i);
        CUtlBuffer::Printf(this: &v136, pFmt: "%s:  %s\n", Name, v104);
      }
    }
  }
  KeyValues::deleteThis(this: v28);
  if ( GetBaseLocalClient()->m_nSignonState == 6
    && g_ServerGlobalVariables.mapversion != 0
    && host_state.worldmodel != nullptr )
  {
    v33 = g_pFileSystem->IBaseFileSystem::__vftable;
    v34 = ((int (__thiscall *)(IModelLoader *, model_t *, const char *))modelloader->GetName)(
            a1: modelloader,
            a2: host_state.worldmodel,
            a3: "GAME");
    v35 = ((int (__thiscall *)(IBaseFileSystem *, int))v33->GetFileTime)(a1: &g_pFileSystem->IBaseFileSystem, a2: v34);
    if ( v141 != 0 || v35 == 0 )
    {
      CUtlBuffer::Printf(this: &v136, pFmt: "Map version:  %i\n", g_ServerGlobalVariables.mapversion);
    }
    else
    {
      g_pFileSystem->FileTimeToString(this: g_pFileSystem, a2: v137, a3: 64, a4: v35);
      CUtlBuffer::Printf(
        this: &v136,
        pFmt: "Map version:  %i\nFile timestamp:  %s",
        g_ServerGlobalVariables.mapversion,
        v137);
    }
  }
  if ( GetSteamUniverse() == k_EUniverseBeta )
  {
    if ( sv.m_State >= ss_active && serverGameClients != nullptr )
    {
      _V_memset(dest, fill: 0, count: 2048);
      serverGameClients->GetBugReportInfo(this: serverGameClients, a2: dest, a3: 2048);
      CUtlBuffer::Printf(this: &v136, pFmt: "%s", dest);
    }
    CUtlBuffer::Printf(this: &v136, pFmt: "matchmaking.dll info\n");
    if ( g_pMatchFramework != nullptr )
    {
      v36 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
      v37 = v36;
      if ( v36 != nullptr )
      {
        CUtlBuffer::Printf(this: &v136, pFmt: "match session %p\n", v36);
        v140[0] = &CKeyValuesDumpForBugreport::`vftable';
        v140[1] = &v136;
        CUtlBuffer::Printf(this: &v136, pFmt: "session system data:\n");
        v38 = (KeyValues *)v37->GetSessionSystemData(this: v37);
        KeyValues::Dump(this: v38, pDump: (IKeyValuesDumpContext *)v140, nIndentLevel: 0);
        CUtlBuffer::Printf(this: &v136, pFmt: "session settings:\n");
        v39 = v37->GetSessionSettings(this: v37);
        KeyValues::Dump(this: v39, pDump: (IKeyValuesDumpContext *)v140, nIndentLevel: 0);
      }
      else
      {
        CUtlBuffer::Printf(this: &v136, pFmt: "[ no match session ]\n");
      }
    }
  }
  CUtlBuffer::Printf(this: &v136, pFmt: "gamedir:  %s\n", com_gamedir);
  v41 = _Plat_FloatTime(a1: v40);
  v42 = (int)(0.0002777777777777778 * v41);
  v43 = (int)(0.01666666666666667 * v41);
  v140[1] = 60 * (v43 % 60 + 60 * v42);
  V_snprintf(
    pDest: (char *)v106,
    maxLen: 0x2000,
    pFormat: "Blackbox dumped at %02d:%02d:%02.3f\n",
    v42,
    v43 % 60,
    v41 - (double)v140[1]);
  for ( j = 0; j < gBlackBox->GetTypeCount(this: gBlackBox); ++j )
  {
    v45 = 0;
    if ( gBlackBox->Count(this: gBlackBox, a2: j) > 0 )
    {
      do
      {
        v110.__vftable = (CFmtStrN<1040>_vtbl *)&CFmtStrN<1040>::`vftable';
        *(_WORD *)&v110.m_bQuietTruncation = 1;
        v110.m_nLength = 0;
        v46 = gBlackBox->Get(this: gBlackBox, a2: j, a3: v45);
        v47 = (const char *)((int (__thiscall *)(IBlackBox *, int, const char *))gBlackBox->GetTypeName)(
                              a1: gBlackBox,
                              a2: j,
                              a3: v46);
        CFmtStrN<1040>::sprintf(this: &v110, pszFormat: "%s: %s\n", v47, v100);
        V_strncat(pDest: (char *)v106, pSrc: v110.m_szBuf, destBufferSize: 0x2000u, max_chars_to_copy: -1);
        ++v45;
      }
      while ( v45 < ((int (__thiscall *)(IBlackBox *, int, int))gBlackBox->Count)(a1: gBlackBox, a2: j, a3: v105) );
    }
  }
  CUtlBuffer::Printf(this: &v136, pFmt: "%s", (const char *)v106);
  _Msg(a1: "%s", (const char *)v136.m_Memory.m_pMemory);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::Printf(this: &buf, pFmt: "Console:\n\n");
  CBugUIPanel::GetConsoleHistory(this, &buf);
  if ( !this->m_bIsSubmittingRemoteBug )
  {
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: "bugconsole.txt",
      a3: "MOD",
      a4: v132,
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: v132, a3: "MOD", a4: &buf);
    this->OnFileSelected(this, a2: v132);
  }
  if ( bugreporter_console_bytes.m_pParent == nullptr
    || (v48 = bugreporter_console_bytes.m_pParent->m_Value.m_nValue) <= 1 )
  {
    v48 = 1;
  }
  if ( buf.m_Put >= v48 )
  {
    if ( bugreporter_console_bytes.m_pParent == nullptr
      || (m_Put = bugreporter_console_bytes.m_pParent->m_Value.m_nValue) <= 1 )
    {
      m_Put = 1;
    }
  }
  else
  {
    m_Put = buf.m_Put;
  }
  v140[1] = &buf.m_Memory.m_pMemory[buf.m_Put - m_Put];
  CUtlBuffer::Printf(
    this: &v136,
    pFmt: "\n\n-----------------------------------------------------------\nConsole:  (last %d bytes)\n\n",
    m_Put);
  CUtlBuffer::Put(this: &v136, pMem: (const void *)v140[1], size: m_Put);
  if ( v141 != 0 )
  {
    this->m_pEmail->GetText_2(this: this->m_pEmail, a2: str, a3: 256);
    if ( _V_strlen(str) <= 0 )
      _Msg(a1: "Not sending email address\n");
    else
      _Msg(a1: "email %s\n", str);
    this->m_pBugReporter->SetOwner(this: this->m_pBugReporter, a2: str);
  }
  else
  {
    this->m_pSeverity->GetText_2(this: this->m_pSeverity, a2: v118, a3: 256);
    _Msg(a1: "severity %s\n", v118);
    this->m_pGameArea->GetText_2(this: this->m_pGameArea, a2: v122, a3: 256);
    _Msg(a1: "area %s\n", v122);
    this->m_pMapNumber->GetText_2(this: this->m_pMapNumber, a2: v119, a3: 256);
    _Msg(a1: "map number %s\n", v119);
    this->m_pPriority->GetText_2(this: this->m_pPriority, a2: v117, a3: 256);
    _Msg(a1: "priority %s\n", v117);
    this->m_pAssignTo->GetText_2(this: this->m_pAssignTo, a2: v125, a3: 256);
    _Msg(a1: "owner %s\n", v125);
    v50 = this->m_pBugReporter;
    v51 = v50->__vftable;
    v52 = (int)v50->GetUserNameForDisplayName(this: v50, a2: v125);
    v51->SetOwner(this: this->m_pBugReporter, a2: (const char *)v52);
  }
  this->m_pSubmitter->GetText_2(this: this->m_pSubmitter, a2: v111, a3: 256);
  v53 = this->m_pBugReporter;
  v54 = v53->__vftable;
  v55 = (int)v53->GetUserNameForDisplayName(this: v53, a2: v111);
  v54->SetSubmitter(this: this->m_pBugReporter, a2: (const char *)v55);
  _Msg(a1: "submitter %s\n", v111);
  this->m_pReportType->GetText_2(this: this->m_pReportType, a2: v121, a3: 256);
  _Msg(a1: "report_type %s\n", v121);
  _Msg(a1: "level %s\n", pSrc);
  _Msg(a1: "position %s\n", v123);
  _Msg(a1: "orientation %s\n", v126);
  _Msg(a1: "build %s\n", v129);
  if ( this->m_szSaveGameName[0] != 0 )
    _Msg(a1: "save file save/%s.sav\n", this->m_szSaveGameName);
  else
    _Msg(a1: "no save game\n");
  if ( this->m_szScreenShotName[0] != 0 )
    _Msg(a1: "screenshot screenshots/%s.jpg\n", this->m_szScreenShotName);
  else
    _Msg(a1: "no screenshot\n");
  if ( v141 == 0 )
  {
    if ( this->m_szBSPName[0] != 0 )
      _Msg(a1: "bsp file maps/%s.bsp\n", this->m_szBSPName);
    if ( this->m_szVMFName[0] != 0 )
      _Msg(a1: "vmf file maps/%s.vmf\n", this->m_szVMFName);
    v56 = 0;
    if ( this->m_IncludedFiles.m_Size > 0 )
    {
      v140[2] = 0;
      do
      {
        _Msg(a1: "Include:  %s\n", &this->m_IncludedFiles.m_Memory.m_pMemory->name[v140[2]]);
        v140[2] += 512;
        ++v56;
      }
      while ( v56 < this->m_IncludedFiles.m_Size );
    }
  }
  this->m_pBugReporter->SetTitle(this: this->m_pBugReporter, a2: pDest);
  this->m_pBugReporter->SetDescription(this: this->m_pBugReporter, a2: v107);
  if ( !this->m_bIsSubmittingRemoteBug )
  {
    this->m_pBugReporter->SetLevel(this: this->m_pBugReporter, a2: pSrc);
    this->m_pBugReporter->SetPosition(this: this->m_pBugReporter, a2: v123);
    this->m_pBugReporter->SetOrientation(this: this->m_pBugReporter, a2: v126);
    this->m_pBugReporter->SetBuildNumber(this: this->m_pBugReporter, a2: v129);
  }
  this->m_pBugReporter->SetSeverity(this: this->m_pBugReporter, a2: v118);
  this->m_pBugReporter->SetPriority(this: this->m_pBugReporter, a2: v117);
  this->m_pBugReporter->SetArea(this: this->m_pBugReporter, a2: v122);
  this->m_pBugReporter->SetMapNumber(this: this->m_pBugReporter, a2: v119);
  this->m_pBugReporter->SetReportType(this: this->m_pBugReporter, a2: v121);
  if ( !this->m_bIsSubmittingRemoteBug )
  {
    this->m_pBugReporter->SetDriverInfo(this: this->m_pBugReporter, a2: v108);
    this->m_pBugReporter->SetMiscInfo(this: this->m_pBugReporter, a2: (const char *)v136.m_Memory.m_pMemory);
    this->m_pBugReporter->SetConsoleHistory(this: this->m_pBugReporter, a2: (const char *)buf.m_Memory.m_pMemory);
  }
  ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetCSERAddress)(a1: this->m_pBugReporter);
  v101 = "hl2.exe";
  ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetExeName)(a1: this->m_pBugReporter);
  this->m_pBugReporter->SetGameDirectory(this: this->m_pBugReporter, a2: com_gamedir);
  CPUInformation = _GetCPUInformation();
  GlobalMemoryStatus(lpBuffer: &Buffer);
  this->m_pBugReporter->SetRAM(this: this->m_pBugReporter, a2: Buffer.dwTotalPhys >> 20);
  v58 = this->m_pBugReporter;
  v59 = v58->__vftable;
  v140[1] = (int)((double)*(__int64 *)(CPUInformation + 8) * 0.000001);
  v59->SetCPU(this: v58, a2: v140[1]);
  this->m_pBugReporter->SetProcessor(this: this->m_pBugReporter, a2: *(const char **)(CPUInformation + 16));
  v60 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
  v61 = this->m_pBugReporter->__vftable;
  v140[2] = v60;
  v61->SetDXVersion(this: this->m_pBugReporter, a2: v60 / 10, a3: v60 % 10, a4: v113, a5: v114);
  DisplaySystemVersion(osversion, maxlen: 128);
  this->m_pBugReporter->SetOSVersion(this: this->m_pBugReporter, a2: osversion);
  this->m_pBugReporter->ResetIncludedFiles(this: this->m_pBugReporter);
  this->m_pBugReporter->SetZipAttachmentName(this: this->m_pBugReporter, a2: defaultValue);
  if ( this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
  {
    v141 = 0;
    v139 = 0;
    CUtlBuffer::CUtlBuffer(this: &v138, growSize: 0, initSize: 0, nFlags: 1);
    CUtlBuffer::Printf(this: &v138, pFmt: "Title:  %s\n", pDest);
    CUtlBuffer::Printf(this: &v138, pFmt: "Description:  %s\n\n", v107);
    CUtlBuffer::Printf(this: &v138, pFmt: "Level:  %s\n", pSrc);
    CUtlBuffer::Printf(this: &v138, pFmt: "Position:  %s\n", v123);
    CUtlBuffer::Printf(this: &v138, pFmt: "Orientation:  %s\n", v126);
    CUtlBuffer::Printf(this: &v138, pFmt: "BuildNumber:  %s\n", v129);
    CUtlBuffer::Printf(this: &v138, pFmt: "DriverInfo:  %s\n", v108);
    CUtlBuffer::Printf(this: &v138, pFmt: "Misc:  %s\n", (const char *)v136.m_Memory.m_pMemory);
    CUtlBuffer::Printf(this: &v138, pFmt: "Exe:  %s\n", "hl2.exe");
    V_FileBase(in: com_gamedir, out: pFixedName, maxlen: 256);
    CUtlBuffer::Printf(this: &v138, pFmt: "GameDirectory:  %s\n", pFixedName);
    GlobalMemoryStatus(lpBuffer: &Buffer);
    CUtlBuffer::Printf(this: &v138, pFmt: "Ram:  %i\n", Buffer.dwTotalPhys >> 20);
    CUtlBuffer::Printf(this: &v138, pFmt: "CPU:  %i\n", v140[1]);
    CUtlBuffer::Printf(this: &v138, pFmt: "Processor:  %s\n", *(const char **)(CPUInformation + 16));
    CUtlBuffer::Printf(this: &v138, pFmt: "DXLevel:  %d\n", v140[2]);
    CUtlBuffer::Printf(this: &v138, pFmt: "OSVersion:  %s\n", osversion);
    if ( (v138.m_Flags & 1) != 0 && v138.m_Put != 0 && v138.m_Memory.m_pMemory[v138.m_Put - v138.m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: &v138);
    if ( CUtlBuffer::CheckPut(this: &v138, nSize: 1) )
    {
      v138.m_Memory.m_pMemory[v138.m_Put - v138.m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: &v138, nPut: ++v138.m_Put);
    }
    v62 = 2 * v138.m_Put + 1;
    v63 = (char *)MemAlloc_Alloc(nSize: v62);
    v64 = v63;
    if ( v63 != nullptr )
    {
      _V_memset(dest: v63, fill: 0, count: v62);
      m_pMemory = v138.m_Memory.m_pMemory;
      v66 = v64;
      if ( *v138.m_Memory.m_pMemory != 0 )
      {
        v140[1] = v62 - 1;
        v67 = 0;
        do
        {
          if ( v67 >= v140[1] )
            break;
          if ( *m_pMemory == 10 )
          {
            *v66++ = 13;
            ++v67;
          }
          *v66++ = *m_pMemory++;
          ++v67;
        }
        while ( *m_pMemory != 0 );
      }
      *v66 = 0;
      v68 = _V_strlen(str: v64) + 1;
      if ( this->m_hZip != nullptr
        || (ZipZ = CreateZipZ(z: nullptr, len: 0x1000000u, flags: 3u), this->m_hZip = ZipZ, ZipZ != nullptr) )
      {
        ZipAdd(hz: this->m_hZip, dstzn: "info.txt", src: v64, len: v68, flags: 3u);
      }
      free(pMem: v64);
    }
    else
    {
      Sys_Error(error: "Unable to allocate %i bytes for bug description\n", v62);
    }
    if ( GetBaseLocalClient()->m_nMaxClients == 1 && this->m_szSaveGameName[0] != 0 )
    {
      V_snprintf(pDest: pname, maxLen: 512, pFormat: "save/%s.sav", this->m_szSaveGameName);
      V_FixSlashes(pname, separator: 92);
      v70 = CBugUIPanel::AddFileToZip(this, relative: pname);
    }
    else
    {
      v70 = v141;
    }
    if ( this->m_szScreenShotName[0] != 0 )
    {
      V_snprintf(pDest: pname, maxLen: 512, pFormat: "screenshots/%s.jpg", this->m_szScreenShotName);
      V_FixSlashes(pname, separator: 92);
      v71 = CBugUIPanel::AddFileToZip(this, relative: pname);
    }
    else
    {
      v71 = v139;
    }
    m_hZip = this->m_hZip;
    if ( m_hZip != nullptr && (v70 != 0 || v71 != 0) )
    {
      ZipGetMemory(hz: m_hZip, buf: (void **)&v140[1], len: &v140[2]);
      if ( v140[1] != 0 && v140[2] != 0 )
      {
        v73 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "bug.zip", a3: "wb", a4: 0);
        v74 = v73;
        if ( v73 != nullptr )
        {
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: (const void *)v140[1], a3: v140[2], a4: v73);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v74);
          this->m_pBugReporter->SetZipAttachmentName(this: this->m_pBugReporter, a2: "bug.zip");
        }
      }
    }
    if ( this->m_hZip != nullptr )
    {
      CloseZipZ(hz: this->m_hZip);
      this->m_hZip = nullptr;
    }
    this->m_pBugReporter->SetSteamUserID(this: this->m_pBugReporter, a2: &this->m_SteamID, a3: 16);
    if ( v138.m_Memory.m_nGrowSize >= 0 && v138.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v138.m_Memory.m_pMemory);
  }
  else
  {
    if ( GetBaseLocalClient()->m_nSignonState == 6 && GetBaseLocalClient()->m_nMaxClients > 1 )
    {
      V_snprintf(pDest: pFixedName, maxLen: 256, pFormat: "say \"Bug Submitted [%s]: %s\"\n", v125, pDest);
      v96 = (int)(float)((float)(1.5 / host_state.interval_per_tick) + 0.5);
      v75 = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)v96);
      Cbuf_AddText(eTarget: v75, pText: pFixedName, nTickDelay: v96);
    }
    if ( this->m_szSaveGameName[0] != 0 )
    {
      v76 = (const char *)((int (__thiscall *)(IBugReporter *, const char *))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: "hl2.exe");
      if ( v76 == nullptr )
        v76 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: pname, maxLen: 512, pFormat: "%s/BugId/%s.sav", v76, this->m_szSaveGameName);
      V_FixSlashes(pname, separator: 92);
      v101 = pname;
      ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetSaveGame)(a1: this->m_pBugReporter);
    }
    if ( this->m_szScreenShotName[0] != 0 )
    {
      v77 = (const char *)((int (__thiscall *)(IBugReporter *, char *))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: v101);
      if ( v77 == nullptr )
        v77 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: pname, maxLen: 512, pFormat: "%s/BugId/%s.jpg", v77, this->m_szScreenShotName);
      V_FixSlashes(pname, separator: 92);
      v101 = pname;
      ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetScreenShot)(a1: this->m_pBugReporter);
    }
    if ( this->m_szBSPName[0] != 0 )
    {
      v78 = (const char *)((int (__thiscall *)(IBugReporter *, char *))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: v101);
      if ( v78 == nullptr )
        v78 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: pname, maxLen: 512, pFormat: "%s/BugId/%s.bsp", v78, this->m_szBSPName);
      V_FixSlashes(pname, separator: 92);
      v101 = pname;
      ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetBSPName)(a1: this->m_pBugReporter);
    }
    if ( this->m_szVMFName[0] != 0 )
    {
      v79 = (const char *)((int (__thiscall *)(IBugReporter *, char *))this->m_pBugReporter->GetRepositoryURL)(
                            a1: this->m_pBugReporter,
                            a2: v101);
      if ( v79 == nullptr )
        v79 = "\\\\fileserver\\bugs";
      V_snprintf(pDest: pname, maxLen: 512, pFormat: "%s/BugId/%s.vmf", v79, this->m_szVMFName);
      V_FixSlashes(pname, separator: 92);
      v101 = pname;
      ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->SetVMFName)(a1: this->m_pBugReporter);
    }
    if ( this->m_IncludedFiles.m_Size > 0 )
    {
      v80 = 0;
      v140[2] = 0;
      do
      {
        v81 = &this->m_IncludedFiles.m_Memory.m_pMemory->name[v140[2]];
        v82 = (const char *)((int (__thiscall *)(IBugReporter *, char *))this->m_pBugReporter->GetRepositoryURL)(
                              a1: this->m_pBugReporter,
                              a2: v101);
        if ( v82 == nullptr )
          v82 = "\\\\fileserver\\bugs";
        V_snprintf(pDest: pname, maxLen: 512, pFormat: "%s/BugId/%s", v82, v81 + 256);
        V_FixSlashes(pname, separator: 92);
        v101 = pname;
        ((void (__thiscall *)(IBugReporter *))this->m_pBugReporter->AddIncludedFile)(a1: this->m_pBugReporter);
        v140[2] += 512;
        ++v80;
      }
      while ( v80 < this->m_IncludedFiles.m_Size );
    }
  }
  if ( !this->m_bIsSubmittingRemoteBug )
    V_strncpy(pDest: this->m_szLevel, pSrc, maxLen: 256);
  if ( this->m_pBugReporter->IsPublicUI(this: this->m_pBugReporter) )
  {
    v83 = (CBugReportUploadProgressDialog *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v83 != nullptr )
      v84 = CBugReportUploadProgressDialog::CBugReportUploadProgressDialog(
              this: v83,
              parent: nullptr,
              name: "ProgressDialog",
              title: "#Steam_SubmittingBug_WorkingTitle",
              message: "#Steam_SubmittingBug_WorkingText");
    else
      v84 = nullptr;
    this->m_pProgressDialog = v84;
    v84->Activate(this: v84);
    v85 = g_pVGuiInput;
    v86 = g_pVGuiInput->__vftable;
    v87 = this->m_pProgressDialog->GetVPanel(this: this->m_pProgressDialog);
    v86->SetAppModalSurface(this: v85, a2: v87);
    this->m_flPauseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) + 15.0;
  }
  else
  {
    CBugUIPanel::OnFinishBugReport(this);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( v136.m_Memory.m_nGrowSize >= 0 && v136.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v136.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10143170
// Name: public: virtual void CBugUIPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBugUIPanel::OnTick(CBugUIPanel *this@<ecx>, int a2@<edi>)
{
  int m_nSnapShotFrame; // ecx
  int m_nValue; // eax
  vgui::Label *m_pScreenShotURL; // ecx
  IEngineVGuiInternal *v6; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  IBugReporter *m_pBugReporter; // ecx
  vgui::Button_vtbl *v9; // esi
  bool IsValidSubmission; // al
  vgui::ISystem_vtbl *v11; // edx
  CBugReportUploadProgressDialog *m_pProgressDialog; // ecx
  CBugReportFinishedDialog *v13; // eax
  CDragDropHelperPanel *v14; // eax
  vgui::Panel *v15; // eax
  vgui::Panel *v16; // eax
  vgui::IInput *v17; // esi
  vgui::IInput_vtbl *v18; // edi
  int v19; // eax
  long double (__thiscall *GetFrameTime)(vgui::ISystem *); // edx
  float progress; // [esp+10h] [ebp-D0h]
  char textError[172]; // [esp+20h] [ebp-C0h] BYREF
  long double val; // [esp+CCh] [ebp-14h] BYREF
  double minVal; // [esp+D4h] [ebp-Ch] BYREF
  float maxVal; // [esp+DCh] [ebp-4h] BYREF

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  CBugUIPanel::CheckContinueQueryingSteamForCSERList(this);
  if ( !this->IsVisible(this) )
  {
    if ( !this->m_bTakingSnapshot )
    {
      m_nSnapShotFrame = this->m_nSnapShotFrame;
      if ( m_nSnapShotFrame > 0 )
      {
        if ( bugreporter_snapshot_delay.m_pParent != nullptr )
          m_nValue = bugreporter_snapshot_delay.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( host_framecount >= m_nValue + m_nSnapShotFrame )
          CBugUIPanel::TakeSnapshot(this);
      }
      return;
    }
    if ( host_framecount < this->m_nSnapShotFrame + 2 )
      return;
    m_pScreenShotURL = this->m_pScreenShotURL;
    this->m_bTakingSnapshot = false;
    this->m_nSnapShotFrame = -1;
    m_pScreenShotURL->SetText(this: m_pScreenShotURL, a2: this->m_szScreenShotName);
    if ( this->m_bHidGameUIForSnapshot || !this->m_bAutoSubmit )
    {
      v6 = EngineVGui();
      v6->ActivateGameUI(this: v6);
    }
    SetVisible = this->SetVisible;
    this->m_bHidGameUIForSnapshot = false;
    SetVisible(this, a2: true);
    this->MoveToFront(this);
  }
  if ( this->m_bCanSubmit )
  {
    v9 = this->m_pSubmit->__vftable;
    IsValidSubmission = CBugUIPanel::IsValidSubmission(this, verbose: false);
    v9->SetEnabled(this: this->m_pSubmit, a2: IsValidSubmission);
    if ( this->m_bAutoSubmit )
    {
      CBugUIPanel::OnSubmit(this, a2: (int)this, a3: a2);
      this->SetVisible(this, a2: false);
      this->m_bAutoSubmit = false;
    }
    maxVal = this->m_flPauseTime;
    if ( maxVal > 0.0 )
    {
      v11 = g_pVGuiSystem->__vftable;
      minVal = maxVal;
      if ( v11->GetFrameTime(this: g_pVGuiSystem) < maxVal )
      {
        if ( this->m_pProgressDialog != nullptr )
        {
          val = this->m_flPauseTime;
          GetFrameTime = g_pVGuiSystem->GetFrameTime;
          maxVal = 1.0;
          HIDWORD(minVal) = 0;
          val = 1.0 - (val - GetFrameTime(this: g_pVGuiSystem)) * 0.06666666666666667;
          progress = clamp<double,float,float>(&val, minVal: (const float *)&minVal + 1, &maxVal);
          CBugReportUploadProgressDialog::SetProgress(this: this->m_pProgressDialog, progress);
        }
      }
      else
      {
        m_pProgressDialog = this->m_pProgressDialog;
        this->m_flPauseTime = 0.0;
        if ( m_pProgressDialog != nullptr )
          m_pProgressDialog->Close(this: m_pProgressDialog);
        this->m_pProgressDialog = nullptr;
        CBugUIPanel::OnFinishBugReport(this);
        this->m_bWaitForFinish = true;
        if ( vgui::PHandle::Get(this: &this->m_hFinishedDialog) == nullptr )
        {
          v13 = (CBugReportFinishedDialog *)MemAlloc_Alloc(nSize: 0x214u);
          if ( v13 != nullptr )
            v14 = (CDragDropHelperPanel *)CBugReportFinishedDialog::CBugReportFinishedDialog(
                                            this: v13,
                                            parent: nullptr,
                                            name: "FinishDialog",
                                            title: "#Steam_FinishedBug_WorkingTitle",
                                            message: "#Steam_FinishedBug_Text");
          else
            v14 = nullptr;
          vgui::DHANDLE<CDragDropHelperPanel>::operator=(
            this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFinishedDialog,
            pPanel: v14);
          v15 = vgui::PHandle::Get(this: &this->m_hFinishedDialog);
          v15->__vftable[1].OnTick(this: v15);
          v16 = vgui::PHandle::Get(this: &this->m_hFinishedDialog);
          v17 = g_pVGuiInput;
          v18 = g_pVGuiInput->__vftable;
          v19 = v16->GetVPanel(this: v16);
          v18->SetAppModalSurface(this: v17, a2: v19);
        }
      }
    }
    if ( this->m_bWaitForFinish && vgui::PHandle::Get(this: &this->m_hFinishedDialog) == nullptr )
    {
      this->m_bWaitForFinish = false;
      this->Close(this);
    }
  }
  else
  {
    m_pBugReporter = this->m_pBugReporter;
    if ( m_pBugReporter != nullptr && !m_pBugReporter->IsPublicUI(this: m_pBugReporter) )
    {
      if ( this->m_bCanSeeRepository )
      {
        if ( !this->m_bLoggedIn )
          _Warning(a1: "Bug UI disabled:  Couldn't log in to PVCS Tracker\n");
      }
      else
      {
        _Warning(a1: "Bug UI disabled:  Couldn't see repository\n");
      }
      strcpy(
        textError,
        "If you are accessing from VPN at home, try this:\n"
        "Set the ConVar 'bugreporter_username' to your Valve user name.\n"
        "Then call the command '_bugreporter_restart autoselect'.\n");
      _Warning(a1: textError);
    }
    this->SetVisible(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10281FC0
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x10286830
// Name: public: class vgui::Panel __near * vgui::PHandle::Get(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::PHandle::Get(vgui::PHandle *this)
{
  unsigned int v1; // esi
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // ebx
  const char *ControlsModuleName; // eax

  if ( this->m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: this->m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x102AAD60
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::FileOpenDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::FileOpenDialog::GetMessageMap(vgui::FileOpenDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::FileOpenDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::FileOpenDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "FileOpenDialog");
  `vgui::FileOpenDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102AAD90
// Name: public: virtual struct PanelAnimationMap __near * vgui::FileOpenDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::FileOpenDialog::GetAnimMap(vgui::FileOpenDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "FileOpenDialog");
}

//------------------------------------------------------------------------------
// Address: 0x102AADA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::FileOpenDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::FileOpenDialog::GetKBMap(vgui::FileOpenDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::FileOpenDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenDialog::GetKBMap'::`2'::s_pMap;
  `vgui::FileOpenDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenDialog");
  `vgui::FileOpenDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10318F30
// Name: _dynamic_initializer_for__bugreporter_includebsp__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_includebsp__()
{
  ConVar::ConVar(
    this: &bugreporter_includebsp,
    pName: "bugreporter_includebsp",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Include .bsp for internal bug submissions.");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_includebsp__);
}

//------------------------------------------------------------------------------
// Address: 0x10318F60
// Name: _dynamic_initializer_for__bugreporter_uploadasync__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_uploadasync__()
{
  ConVar::ConVar(
    this: &bugreporter_uploadasync,
    pName: "bugreporter_uploadasync",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Upload attachments asynchronously");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_uploadasync__);
}

//------------------------------------------------------------------------------
// Address: 0x10318F90
// Name: _dynamic_initializer_for__bugreporter_snapshot_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_snapshot_delay__()
{
  ConVar::ConVar(
    this: &bugreporter_snapshot_delay,
    pName: "bugreporter_snapshot_delay",
    pDefaultValue: "15",
    flags: 0,
    pHelpString: "Frames to delay before taking snapshot");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_snapshot_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10318FC0
// Name: _dynamic_initializer_for__bugreporter_username__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_username__()
{
  ConVar::ConVar(
    this: &bugreporter_username,
    pName: "bugreporter_username",
    pDefaultValue: defaultValue,
    flags: 128,
    pHelpString: "Username to use for bugreporter");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_username__);
}

//------------------------------------------------------------------------------
// Address: 0x10319000
// Name: _dynamic_initializer_for__bugreporter_console_bytes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugreporter_console_bytes__()
{
  ConVar::ConVar(
    this: &bugreporter_console_bytes,
    pName: "bugreporter_console_bytes",
    pDefaultValue: "15000",
    flags: 0,
    pHelpString: "Max # of console bytes to put into bug report body (full text still attached).");
  return atexit(func: dynamic_atexit_destructor_for__bugreporter_console_bytes__);
}

//------------------------------------------------------------------------------
// Address: 0x10319070
// Name: _dynamic_initializer_for___bugreporter_restart_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for___bugreporter_restart_command__()
{
  ConCommand::ConCommand(
    this: &bugreporter_restart_command,
    pName: "_bugreporter_restart",
    callback: (void (__cdecl *)())bugreporter_restart,
    pHelpString: "Restarts bug reporter .dll",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___bugreporter_restart_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324C60
// Name: _dynamic_atexit_destructor_for__bugreporter_includebsp__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_includebsp__()
{
  ConVar::~ConVar(this: &bugreporter_includebsp);
}

//------------------------------------------------------------------------------
// Address: 0x10324C70
// Name: _dynamic_atexit_destructor_for__bugreporter_uploadasync__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_uploadasync__()
{
  ConVar::~ConVar(this: &bugreporter_uploadasync);
}

//------------------------------------------------------------------------------
// Address: 0x10324C80
// Name: _dynamic_atexit_destructor_for__bugreporter_snapshot_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_snapshot_delay__()
{
  ConVar::~ConVar(this: &bugreporter_snapshot_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10324C90
// Name: _dynamic_atexit_destructor_for__bugreporter_username__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_username__()
{
  ConVar::~ConVar(this: &bugreporter_username);
}

//------------------------------------------------------------------------------
// Address: 0x10324CA0
// Name: _dynamic_atexit_destructor_for__bugreporter_console_bytes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugreporter_console_bytes__()
{
  ConVar::~ConVar(this: &bugreporter_console_bytes);
}

//------------------------------------------------------------------------------
// Address: 0x10324CB0
// Name: _dynamic_atexit_destructor_for___bugreporter_restart_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___bugreporter_restart_command__()
{
  ConCommand::~ConCommand(this: &bugreporter_restart_command);
}

//------------------------------------------------------------------------------
// Address: 0x1013D4A0
// Name: __CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBugReporterDefaultUsername *__cdecl _CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_interface()
{
  return &g_ExposeBugreporterUsername;
}

//------------------------------------------------------------------------------
// Address: 0x1013E720
// Name: _bugreporter_restart
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall bugreporter_restart(int a1@<esi>, const CCommand *args)
{
  int v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  vgui::Panel *v5; // eax

  if ( args->m_nArgc > 1 )
  {
    v2 = 1;
    if ( _V_stricmp(s1: args->m_ppArgv[1], s2: "internal") != 0 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v3, s2: "autoselect") == 0 )
        v2 = 0;
    }
    else
    {
      v2 = 2;
    }
    ((void (__thiscall *)(CEngineBugReporter *, int))g_BugReporter.Shutdown)(a1: &g_BugReporter, a2: a1);
    if ( v2 != 0 )
    {
      v4 = "public";
      if ( v2 != 1 )
        v4 = "valve";
    }
    else
    {
      v4 = "autoselect";
    }
    _Msg(a1: "Changing to bugreporter(%s)\n", v4);
    v5 = vgui::PHandle::Get(this: &g_BugReporter.m_ParentPanel);
    ((void (__thiscall *)(CEngineBugReporter *, vgui::Panel *))g_BugReporter.InstallBugReportingUI)(
      a1: &g_BugReporter,
      a2: v5);
  }
  else
  {
    _Msg(a1: "__bugreporter_restart <internal | external | autoselect>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319030
// Name: _dynamic_initializer_for__g_UploadQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UploadQueue__()
{
  CTSQueue<int,0,1>::CTSQueue<int,0,1>(this: (CTSQueue<int,0,1> *)&g_UploadQueue);
  g_UploadQueue.m_bNoQueue = false;
  return atexit(func: dynamic_atexit_destructor_for__g_UploadQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x10319050
// Name: _dynamic_initializer_for____g_CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_reg,
           fn: (void *(__cdecl *)())_CreateCBugReporterDefaultUsernameIBugReporterDefaultUsername_interface,
           pName: "BugReporterUserName001");
}

//------------------------------------------------------------------------------
// Address: 0x103190A0
// Name: _dynamic_initializer_for__bug_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bug_command__()
{
  ConCommand::ConCommand(
    this: &bug_command,
    pName: "bug",
    callback: (void (__cdecl *)())bug,
    pHelpString: "Show the bug reporting UI.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103190D0
// Name: _dynamic_initializer_for__g_BuildNumber__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_BuildNumber__()
{
  CBuildNumber::ComputeBuildNumber(this: &g_BuildNumber);
}

//------------------------------------------------------------------------------
// Address: 0x10324CC0
// Name: _dynamic_atexit_destructor_for__bug_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bug_command__()
{
  ConCommand::~ConCommand(this: &bug_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324CD0
// Name: _dynamic_atexit_destructor_for__g_UploadQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UploadQueue__()
{
  CTSQueue<int,0,1>::Purge(this: (CTSQueue<int,0,1> *)&g_UploadQueue);
  free(pMem: g_UploadQueue.m_queue.m_Head.value.pNode);
  CTSListBase::Detach(this: &g_UploadQueue.m_queue.m_FreeNodes);
}

} // namespace engine_xlsp
