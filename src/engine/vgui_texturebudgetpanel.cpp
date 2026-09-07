// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_texturebudgetpanel.cpp
// Functions: 113
// ============================================================

#include "engine\vgui_texturebudgetpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10206090
// Name: public: virtual void CConCommandMemberAccessor<class CTextureBudgetPanel>::CommandCallback(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandMemberAccessor<CTextureBudgetPanel>::CommandCallback(
        CConCommandMemberAccessor<CEngineVGui> *this,
        const CCommand *command)
{
  ((void (__thiscall *)(const char *, const CCommand *))this->m_pszName)(
    a1: &this->m_pszHelpString[*(_DWORD *)&this->m_bRegistered],
    a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x102060B0
// Name: public: virtual int CConCommandMemberAccessor<class CTextureBudgetPanel>::CommandCompletionCallback(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConCommandMemberAccessor<CTextureBudgetPanel>::CommandCompletionCallback(
        CConCommandMemberAccessor<CEngineVGui> *this,
        const char *pPartial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  return ((int (__thiscall *)(char *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))this->m_fnCommandCallbackV1)(
           a1: (char *)this->m_pNext + (unsigned int)this->m_fnCompletionCallback,
           a2: pPartial,
           a3: commands);
}

//------------------------------------------------------------------------------
// Address: 0x10206BF0
// Name: public: CConCommandMemberAccessor<class CEngineVGui>::CConCommandMemberAccessor<class CEngineVGui>(class CEngineVGui __near *,char const __near *,void (CEngineVGui::*)(class CCommand const __near &),char const __near *,int,int (CEngineVGui::*)(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &))
// Source: json
//------------------------------------------------------------------------------
CConCommandMemberAccessor<CEngineVGui> *__thiscall CConCommandMemberAccessor<CEngineVGui>::CConCommandMemberAccessor<CEngineVGui>(
        CConCommandMemberAccessor<CEngineVGui> *this,
        CEngineVGui *pOwner,
        const char *pName,
        __int128 callback,
        const char *pHelpString,
        int flags,
        __int128 completionFunc)
{
  ICommandCompletionCallback *v8; // ecx
  ICommandCallback *v9; // eax

  if ( (_DWORD)completionFunc != 0 && this != nullptr )
    v8 = &this->ICommandCompletionCallback;
  else
    v8 = nullptr;
  if ( this != nullptr )
    v9 = &this->ICommandCallback;
  else
    v9 = nullptr;
  ConCommand::ConCommand(this, pName, pCallback: v9, pHelpString, flags, pCompletionCallback: v8);
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  *(_QWORD *)&this->m_Func = callback;
  this->m_pOwner = pOwner;
  LODWORD(this->m_CompletionFunc) = completionFunc;
  *((_QWORD *)&this->m_Func + 1) = *((_QWORD *)&callback + 1);
  *(_QWORD *)((char *)&this->m_CompletionFunc + 4) = *(_QWORD *)((char *)&completionFunc + 4);
  HIDWORD(this->m_CompletionFunc) = HIDWORD(completionFunc);
  this->ConCommand::ConCommandBase::__vftable = (CConCommandMemberAccessor<CEngineVGui>_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ConCommand'};
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ICommandCallback'};
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ICommandCompletionCallback'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020CA40
// Name: void showbudget_texture_on_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl showbudget_texture_on_f()
{
  unsigned int v0; // [esp-10h] [ebp-10h]
  int v1; // [esp-Ch] [ebp-Ch]
  unsigned int v2; // [esp-8h] [ebp-8h]
  int v3; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&texture_budget_panel_global.IConVar, value: 0, a2: v0, a3: v1);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&showbudget_texture.IConVar, value: 1, a2: v2, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1020CA60
// Name: void showbudget_texture_global_on_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl showbudget_texture_global_on_f()
{
  unsigned int v0; // [esp-10h] [ebp-10h]
  int v1; // [esp-Ch] [ebp-Ch]
  unsigned int v2; // [esp-8h] [ebp-8h]
  int v3; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&texture_budget_panel_global.IConVar, value: 1, a2: v0, a3: v1);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&showbudget_texture.IConVar, value: 1, a2: v2, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1020CA80
// Name: void showbudget_texture_off_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl showbudget_texture_off_f()
{
  unsigned int v0; // [esp-8h] [ebp-8h]
  int v1; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&showbudget_texture.IConVar, value: 0, a2: v0, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1020CA90
// Name: public: virtual void CTextureBudgetPanel::ResetAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::ResetAll(CTextureBudgetPanel *this)
{
  CBaseBudgetPanel::ResetAll(this);
  this->m_MaxValue = 0;
  this->m_SumOfValues = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020CAF0
// Name: public: virtual CTextureBudgetPanel::~CTextureBudgetPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::~CTextureBudgetPanel(CTextureBudgetPanel *this)
{
  vgui::Label *m_pModeLabel; // ecx

  m_pModeLabel = this->m_pModeLabel;
  this->__vftable = (CTextureBudgetPanel_vtbl *)&CTextureBudgetPanel::`vftable';
  g_pTextureBudgetPanel = nullptr;
  if ( m_pModeLabel != nullptr )
  {
    ((void (__thiscall *)(vgui::Label *, int))m_pModeLabel->dtr_Panel)(a1: m_pModeLabel, a2: 1);
    this->m_pModeLabel = nullptr;
  }
  this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CTextureBudgetPanel>_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ConCommand'};
  this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ICommandCallback'};
  this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor);
  CBaseBudgetPanel::~CBaseBudgetPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020CB60
// Name: private: enum CounterGroup_t CTextureBudgetPanel::GetCurrentCounterGroup(void)const
// Source: json
//------------------------------------------------------------------------------
CounterGroup_t __thiscall CTextureBudgetPanel::GetCurrentCounterGroup(CTextureBudgetPanel *this)
{
  CounterGroup_t result; // eax

  if ( texture_budget_panel_global.m_pParent == nullptr )
    return COUNTER_GROUP_TEXTURE_PER_FRAME;
  result = COUNTER_GROUP_TEXTURE_GLOBAL;
  if ( texture_budget_panel_global.m_pParent->m_Value.m_nValue == 0 )
    return COUNTER_GROUP_TEXTURE_PER_FRAME;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020CB80
// Name: public: CConCommandMemberAccessor<class CTextureBudgetPanel>::CConCommandMemberAccessor<class CTextureBudgetPanel>(class CTextureBudgetPanel __near *,char const __near *,void (CTextureBudgetPanel::*)(class CCommand const __near &),char const __near *,int,int (CTextureBudgetPanel::*)(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &))
// Source: json
//------------------------------------------------------------------------------
CConCommandMemberAccessor<CTextureBudgetPanel> *__thiscall CConCommandMemberAccessor<CTextureBudgetPanel>::CConCommandMemberAccessor<CTextureBudgetPanel>(
        CConCommandMemberAccessor<CTextureBudgetPanel> *this,
        CTextureBudgetPanel *pOwner,
        const char *pName,
        __int128 callback,
        const char *pHelpString,
        int flags,
        __int128 completionFunc)
{
  ICommandCompletionCallback *v8; // ecx
  ICommandCallback *v9; // eax

  if ( (_DWORD)completionFunc != 0 && this != nullptr )
    v8 = &this->ICommandCompletionCallback;
  else
    v8 = nullptr;
  if ( this != nullptr )
    v9 = &this->ICommandCallback;
  else
    v9 = nullptr;
  ConCommand::ConCommand(this, pName, pCallback: v9, pHelpString, flags, pCompletionCallback: v8);
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  *(_QWORD *)&this->m_Func = callback;
  this->m_pOwner = pOwner;
  LODWORD(this->m_CompletionFunc) = completionFunc;
  *((_QWORD *)&this->m_Func + 1) = *((_QWORD *)&callback + 1);
  *(_QWORD *)((char *)&this->m_CompletionFunc + 4) = *(_QWORD *)((char *)&completionFunc + 4);
  HIDWORD(this->m_CompletionFunc) = HIDWORD(completionFunc);
  this->ConCommand::ConCommandBase::__vftable = (CConCommandMemberAccessor<CTextureBudgetPanel>_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ConCommand'};
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ICommandCallback'};
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ICommandCompletionCallback'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020CC50
// Name: public: virtual void CTextureBudgetPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::OnTick(CTextureBudgetPanel *this)
{
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( showbudget_texture.m_pParent != nullptr && showbudget_texture.m_pParent->m_Value.m_nValue != 0 )
  {
    this->m_pModeLabel->SetVisible(this: this->m_pModeLabel, a2: true);
    this->SetVisible(this, a2: true);
  }
  else
  {
    this->m_pModeLabel->SetVisible(this: this->m_pModeLabel, a2: false);
    this->SetVisible(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CCB0
// Name: public: virtual void CTextureBudgetPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBudgetPanel::PerformLayout(CTextureBudgetPanel *this@<ecx>, int a2@<edi>)
{
  const char *v3; // edi
  IMatSystemSurface_vtbl *v4; // ebx
  int v5; // eax
  int v6; // edi
  int Tall; // eax
  int v8; // eax
  vgui::Label *m_pModeLabel; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  int m_nValue; // eax
  vgui::Label *v12; // ecx
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // eax
  int x; // [esp+8h] [ebp-Ch] BYREF
  int y; // [esp+Ch] [ebp-8h] BYREF
  int v16; // [esp+10h] [ebp-4h]

  CBaseBudgetPanel::PerformLayout(this, a2);
  v3 = "Per-frame texture stats";
  if ( texture_budget_panel_global.m_pParent != nullptr && texture_budget_panel_global.m_pParent->m_Value.m_nValue != 0 )
    v3 = "Global texture stats";
  this->m_pModeLabel->SetText(this: this->m_pModeLabel, a2: v3);
  v4 = g_pMatSystemSurface->__vftable;
  v5 = ((int (__thiscall *)(vgui::Label *, const char *, const char *))this->m_pModeLabel->GetFont)(
         a1: this->m_pModeLabel,
         a2: "%s",
         a3: v3);
  v6 = ((int (__cdecl *)(IMatSystemSurface *, int))v4->DrawTextLen)(a1: g_pMatSystemSurface, a2: v5);
  Tall = vgui::Panel::GetTall(this: this->m_pModeLabel);
  vgui::Panel::SetSize(this: this->m_pModeLabel, wide: v6 + 10, tall: Tall);
  vgui::Panel::GetPos(this, &x, &y);
  v8 = vgui::Panel::GetTall(this: this->m_pModeLabel);
  vgui::Panel::SetPos(this: this->m_pModeLabel, x, y: y - v8);
  m_pModeLabel = this->m_pModeLabel;
  SetFgColor = m_pModeLabel->SetFgColor;
  v16 = -1;
  ((void (__thiscall *)(vgui::Label *, int))SetFgColor)(a1: m_pModeLabel, a2: -1);
  if ( texture_budget_background_alpha.m_pParent != nullptr )
    m_nValue = texture_budget_background_alpha.m_pParent->m_Value.m_nValue;
  else
    LOBYTE(m_nValue) = 0;
  v12 = this->m_pModeLabel;
  HIBYTE(v16) = m_nValue;
  SetBgColor = v12->SetBgColor;
  LOWORD(v16) = 0;
  BYTE2(v16) = 0;
  ((void (__thiscall *)(vgui::Label *, int))SetBgColor)(a1: v12, a2: v16);
}

//------------------------------------------------------------------------------
// Address: 0x1020CDC0
// Name: public: virtual void CTextureBudgetPanel::SetTimeLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::SetTimeLabelText(CTextureBudgetPanel *this)
{
  int v1; // edi
  vgui::Label *v3; // ecx
  char pDest[8]; // [esp+10h] [ebp-204h] BYREF
  char text[512]; // [esp+18h] [ebp-1FCh]

  v1 = 0;
  for ( *(_DWORD *)&text[504] = 0; v1 < this->m_TimeLabels.m_Size; *(_DWORD *)&text[504] = v1 )
  {
    V_snprintf(
      pDest,
      maxLen: 512,
      pFormat: "%.1fM",
      (double)*(int *)&text[504] * this->m_ConfigData.m_flTimeLabelInterval * 0.0009765625);
    v3 = this->m_TimeLabels.m_Memory.m_pMemory[v1];
    v3->SetText(this: v3, a2: pDest);
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CE40
// Name: public: virtual void CTextureBudgetPanel::SetHistoryLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::SetHistoryLabelText(CTextureBudgetPanel *this)
{
  int i; // esi
  vgui::Label *v3; // ecx
  char pDest[8]; // [esp+10h] [ebp-200h] BYREF

  for ( i = 0; i < this->m_HistoryLabels.m_Size; ++i )
  {
    V_snprintf(
      pDest,
      maxLen: 512,
      pFormat: "%.1fM",
      this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory[i] * 0.0009765625);
    v3 = this->m_HistoryLabels.m_Memory.m_pMemory[i];
    v3->SetText(this: v3, a2: pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CEC0
// Name: private: void CTextureBudgetPanel::DumpGlobalTextureStats(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::DumpGlobalTextureStats(CTextureBudgetPanel *this, const CCommand *args)
{
  int i; // esi
  const char *CounterName; // edi
  int CounterValue; // eax

  for ( i = 0; i < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled); ++i )
  {
    if ( CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i) == COUNTER_GROUP_TEXTURE_GLOBAL )
    {
      CounterName = CVProfile::GetCounterName(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i);
      CounterValue = CVProfile::GetCounterValue(
                       this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                       a2: i);
      _Warning(a1: "%s: %d\n", CounterName, CounterValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CF40
// Name: public: CTextureBudgetPanel::CTextureBudgetPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTextureBudgetPanel *__thiscall CTextureBudgetPanel::CTextureBudgetPanel(
        CTextureBudgetPanel *this,
        vgui::Panel *pParent,
        const char *pElementName)
{
  vgui::Label *v4; // eax
  vgui::Label *v5; // eax
  __int128 v7; // [esp-10h] [ebp-1Ch]

  CBaseBudgetPanel::CBaseBudgetPanel(this, pParent, pElementName);
  *(_QWORD *)&v7 = 0;
  *((_QWORD *)&v7 + 1) = 0xFFFFFFFF00000000uLL;
  this->__vftable = (CTextureBudgetPanel_vtbl *)&CTextureBudgetPanel::`vftable';
  CConCommandMemberAccessor<CTextureBudgetPanel>::CConCommandMemberAccessor<CTextureBudgetPanel>(
    this: &this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "showbudget_texture_global_dumpstats",
    callback: (unsigned int)CTextureBudgetPanel::DumpGlobalTextureStats,
    pHelpString: "Dump all items in +showbudget_texture_global in a text form",
    flags: 0,
    completionFunc: v7);
  this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor.m_pOwner = this;
  this->m_LastCounterGroup = -1;
  g_pTextureBudgetPanel = this;
  this->m_MaxValue = 1000;
  this->m_SumOfValues = 0;
  v4 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v4 != nullptr )
    v5 = vgui::Label::Label(this: v4, parent: this, panelName: "mode label", text: defaultValue);
  else
    v5 = nullptr;
  this->m_pModeLabel = v5;
  v5->SetParent_2(this: v5, a2: pParent);
  vgui::Panel::SetVisible(this, state: 0);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020D030
// Name: private: void CTextureBudgetPanel::SendConfigDataToBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::SendConfigDataToBase(CTextureBudgetPanel *this)
{
  CTextureBudgetPanel *v1; // edi
  int v2; // esi
  CounterGroup_t CurrentCounterGroup; // eax
  int v4; // edx
  char *CounterName; // edi
  int v6; // esi
  char *v7; // eax
  int v8; // esi
  int m_Size; // eax
  int v10; // esi
  CBudgetGroupInfo *m_pMemory; // ecx
  int v12; // eax
  int v13; // edx
  CBudgetGroupInfo *v14; // eax
  Color m_Color; // edx
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // ecx
  float *v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  float *v25; // eax
  CBudgetGroupInfo *v26; // eax
  char alternateName[256]; // [esp+Ch] [ebp-17Ch] BYREF
  int g; // [esp+10Ch] [ebp-7Ch] BYREF
  int r; // [esp+110h] [ebp-78h] BYREF
  int a; // [esp+114h] [ebp-74h] BYREF
  const char *pPrefixes[2]; // [esp+118h] [ebp-70h]
  int b; // [esp+120h] [ebp-68h] BYREF
  CTextureBudgetPanel *v33; // [esp+124h] [ebp-64h]
  CBudgetPanelConfigData data; // [esp+128h] [ebp-60h] BYREF
  CBudgetGroupInfo info; // [esp+178h] [ebp-10h]
  CUtlSymbol v36; // [esp+182h] [ebp-6h] BYREF
  int i; // [esp+184h] [ebp-4h]

  v1 = this;
  v2 = 0;
  v33 = this;
  memset(&data, 0, 20);
  memset(&data.m_HistoryLabelValues, 0, sizeof(data.m_HistoryLabelValues));
  i = 0;
  if ( (int)CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) > 0 )
  {
    do
    {
      CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v2);
      CurrentCounterGroup = CTextureBudgetPanel::GetCurrentCounterGroup(this: v1);
      if ( v4 == CurrentCounterGroup )
      {
        CounterName = (char *)CVProfile::GetCounterName(
                                this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                a2: v2);
        pPrefixes[0] = "TexGroup_global_";
        pPrefixes[1] = "TexGroup_frame_";
        v6 = 0;
        while ( 1 )
        {
          strstr(str1: (unsigned __int8 *)CounterName, str2: (unsigned __int8 *)pPrefixes[v6]);
          if ( v7 == CounterName )
            break;
          if ( ++v6 >= 2 )
            goto LABEL_8;
        }
        v8 = strlen(pPrefixes[v6]);
        V_strncpy(pDest: alternateName, pSrc: &CounterName[v8], maxLen: v8);
        alternateName[v8] = 0;
        CounterName = alternateName;
LABEL_8:
        info.m_Color = 0;
        CVProfile::GetBudgetGroupColor(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: data.m_BudgetGroupInfo.m_Size,
          a3: &r,
          a4: &g,
          a5: &b,
          a6: &a);
        info.m_Color._color[0] = r;
        info.m_Color._color[2] = b;
        info.m_Color._color[1] = g;
        info.m_Color._color[3] = a;
        CUtlSymbol::CUtlSymbol(this: &v36, pStr: CounterName);
        m_Size = data.m_BudgetGroupInfo.m_Size;
        v10 = data.m_BudgetGroupInfo.m_Size;
        if ( data.m_BudgetGroupInfo.m_Size + 1 > data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<sentencegroup_t,int>::Grow(
            this: (CUtlMemory<sentencegroup_t,int> *)&data,
            num: data.m_BudgetGroupInfo.m_Size - data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount + 1);
          m_Size = data.m_BudgetGroupInfo.m_Size;
        }
        m_pMemory = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
        data.m_BudgetGroupInfo.m_Size = m_Size + 1;
        v12 = m_Size - v10;
        data.m_BudgetGroupInfo.m_pElements = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
        if ( v12 > 0 )
        {
          _V_memmove(
            dest: &data.m_BudgetGroupInfo.m_Memory.m_pMemory[v10 + 1],
            src: &data.m_BudgetGroupInfo.m_Memory.m_pMemory[v10],
            count: 6 * v12);
          m_pMemory = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
        }
        v1 = v33;
        v13 = v10;
        v2 = i;
        v14 = &m_pMemory[v13];
        if ( v14 != nullptr )
        {
          m_Color = info.m_Color;
          v14->m_Name = v36;
          v14->m_Color = m_Color;
        }
      }
      i = ++v2;
    }
    while ( v2 < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) );
  }
  v16 = 4 * v1->m_MaxValue / 3;
  data.m_flBottomOfHistoryFraction = texture_budget_panel_bottom_of_history_fraction.m_pParent->m_Value.m_fValue;
  v17 = (float)v16;
  v18 = 4 * v1->m_SumOfValues;
  data.m_flBarGraphRange = v17;
  data.m_flTimeLabelInterval = v17 * 0.25;
  data.m_nLinesPerTimeLabel = 4;
  data.m_flHistoryRange = (float)(v18 / 3);
  data.m_HistoryLabelValues.m_Size = 0;
  if ( data.m_HistoryLabelValues.m_Memory.m_nAllocationCount < 3 )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&data.m_HistoryLabelValues,
      num: 3 - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount);
  v19 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  data.m_HistoryLabelValues.m_Size += 3;
  data.m_HistoryLabelValues.m_pElements = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  if ( data.m_HistoryLabelValues.m_Size - 3 > 0 )
  {
    _V_memmove(
      dest: data.m_HistoryLabelValues.m_Memory.m_pMemory + 3,
      src: data.m_HistoryLabelValues.m_Memory.m_pMemory,
      count: 4 * (data.m_HistoryLabelValues.m_Size - 3));
    v19 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v20 = 0;
  if ( data.m_HistoryLabelValues.m_Size > 0 )
  {
    while ( 1 )
    {
      v19[v20] = (float)((float)(v20 + 1) * data.m_flHistoryRange) * 0.25;
      if ( ++v20 >= data.m_HistoryLabelValues.m_Size )
        break;
      v19 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
    }
  }
  data.m_flBackgroundAlpha = texture_budget_background_alpha.m_pParent->m_Value.m_fValue;
  if ( texture_budget_panel_x.m_pParent != nullptr )
    data.m_xCoord = texture_budget_panel_x.m_pParent->m_Value.m_nValue;
  else
    data.m_xCoord = 0;
  if ( texture_budget_panel_y.m_pParent != nullptr )
    data.m_yCoord = texture_budget_panel_y.m_pParent->m_Value.m_nValue;
  else
    data.m_yCoord = 0;
  if ( texture_budget_panel_width.m_pParent != nullptr )
    data.m_Width = texture_budget_panel_width.m_pParent->m_Value.m_nValue;
  else
    data.m_Width = 0;
  if ( texture_budget_panel_height.m_pParent != nullptr )
    data.m_Height = texture_budget_panel_height.m_pParent->m_Value.m_nValue;
  else
    data.m_Height = 0;
  v21 = videomode->GetModeWidth(this: videomode);
  if ( data.m_xCoord + data.m_Width > v21 )
  {
    v22 = videomode->GetModeWidth(this: videomode);
    data.m_xCoord = v22 - data.m_Width;
  }
  v23 = videomode->GetModeHeight(this: videomode);
  if ( data.m_yCoord + data.m_Height > v23 )
  {
    v24 = videomode->GetModeHeight(this: videomode);
    data.m_yCoord = v24 - data.m_Height;
  }
  CBaseBudgetPanel::OnConfigDataChanged(this: v1, &data);
  v25 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  data.m_HistoryLabelValues.m_Size = 0;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_HistoryLabelValues.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_HistoryLabelValues.m_Memory.m_pMemory);
      v25 = nullptr;
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  data.m_HistoryLabelValues.m_pElements = v25;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v25 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  v26 = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
  data.m_BudgetGroupInfo.m_Size = 0;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_BudgetGroupInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_BudgetGroupInfo.m_Memory.m_pMemory);
      v26 = nullptr;
      data.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
    }
    data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  }
  data.m_BudgetGroupInfo.m_pElements = v26;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 && v26 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
}

//------------------------------------------------------------------------------
// Address: 0x1020D410
// Name: private: void CTextureBudgetPanel::SnapshotTextureHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::SnapshotTextureHistory(CTextureBudgetPanel *this)
{
  int v2; // ebx
  CounterGroup_t CurrentCounterGroup; // eax
  int v4; // edx
  int CounterValue; // eax
  int m_MaxValue; // ecx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  CounterGroup_t v11; // eax
  int v12; // edx
  int v13; // ebx
  CounterGroup_t v14; // eax
  int v15; // edx
  int v16; // ecx
  unsigned int v17; // [esp-8h] [ebp-20h]
  int v18; // [esp-4h] [ebp-1Ch]
  int value; // [esp+Ch] [ebp-Ch]
  int nCounters; // [esp+10h] [ebp-8h]
  int nCountersa; // [esp+10h] [ebp-8h]
  bool bForceSendConfigData; // [esp+17h] [ebp-1h]

  v2 = 0;
  for ( this->m_SumOfValues = 0;
        v2 < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        ++v2 )
  {
    CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v2);
    CurrentCounterGroup = CTextureBudgetPanel::GetCurrentCounterGroup(this);
    if ( v4 == CurrentCounterGroup )
    {
      CounterValue = CVProfile::GetCounterValue(
                       this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                       a2: v2);
      m_MaxValue = this->m_MaxValue;
      v7 = CounterValue / 1024;
      this->m_SumOfValues += v7;
      if ( m_MaxValue > v7 )
        v7 = m_MaxValue;
      this->m_MaxValue = v7;
    }
  }
  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&showbudget_texture_global_sum.IConVar,
    value: this->m_SumOfValues,
    a2: v17,
    a3: v18);
  bForceSendConfigData = false;
  if ( (float)this->m_MaxValue > this->m_ConfigData.m_flBarGraphRange
    || (float)this->m_SumOfValues > this->m_ConfigData.m_flHistoryRange )
  {
    bForceSendConfigData = true;
  }
  v8 = 0;
  if ( texture_budget_panel_global.m_pParent == nullptr
    || (v9 = 2, texture_budget_panel_global.m_pParent->m_Value.m_nValue == 0) )
  {
    v9 = 3;
  }
  if ( this->m_LastCounterGroup != v9 )
  {
    this->ResetAll(this);
    if ( texture_budget_panel_global.m_pParent == nullptr
      || (v10 = 2, texture_budget_panel_global.m_pParent->m_Value.m_nValue == 0) )
    {
      v10 = 3;
    }
    this->m_LastCounterGroup = v10;
  }
  nCounters = 0;
  if ( (int)CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) > 0 )
  {
    do
    {
      CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v8);
      v11 = CTextureBudgetPanel::GetCurrentCounterGroup(this);
      if ( v12 == v11 )
        ++nCounters;
      ++v8;
    }
    while ( v8 < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) );
  }
  if ( bForceSendConfigData || nCounters != this->m_ConfigData.m_BudgetGroupInfo.m_Size )
    CTextureBudgetPanel::SendConfigDataToBase(this);
  this->m_BudgetHistoryOffset = (this->m_BudgetHistoryOffset + 1) % 1024;
  v13 = 0;
  if ( (int)CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) > 0 )
  {
    nCountersa = 0;
    do
    {
      CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v13);
      v14 = CTextureBudgetPanel::GetCurrentCounterGroup(this);
      if ( v15 == v14 )
      {
        value = CVProfile::GetCounterValue(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v13)
              / 1024;
        v16 = nCountersa + this->m_BudgetHistoryOffset;
        nCountersa += 1024;
        this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[v16] = (double)value;
      }
      ++v13;
    }
    while ( v13 < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D600
// Name: TextureCVarChangedCallBack
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextureCVarChangedCallBack()
{
  if ( g_pTextureBudgetPanel != nullptr )
    CTextureBudgetPanel::SendConfigDataToBase(this: g_pTextureBudgetPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1020D610
// Name: public: virtual void CTextureBudgetPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::Paint(CTextureBudgetPanel *this)
{
  CTextureBudgetPanel::SnapshotTextureHistory(this);
  CVProfile::ResetCounters(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: COUNTER_GROUP_TEXTURE_PER_FRAME);
  CBaseBudgetPanel::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1031E820
// Name: _dynamic_initializer_for__budget_toggle_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_toggle_group_command__()
{
  ConCommand::ConCommand(
    this: &budget_toggle_group_command,
    pName: "budget_toggle_group",
    callback: (void (__cdecl *)())budget_toggle_group,
    pHelpString: "Turn a budget group on/off",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_toggle_group_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F2E0
// Name: _dynamic_initializer_for__budget_bargraph_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_bargraph_background_alpha__()
{
  ConVar::ConVar(
    this: &budget_bargraph_background_alpha,
    pName: "budget_bargraph_background_alpha",
    pDefaultValue: "128",
    flags: 128,
    pHelpString: "how translucent the budget panel is");
  return atexit(func: dynamic_atexit_destructor_for__budget_bargraph_background_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F310
// Name: _dynamic_initializer_for__budget_peaks_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_peaks_window__()
{
  ConVar::ConVar(
    this: &budget_peaks_window,
    pName: "budget_peaks_window",
    pDefaultValue: "30",
    flags: 128,
    pHelpString: "number of frames to look at when figuring out peak frametimes");
  return atexit(func: dynamic_atexit_destructor_for__budget_peaks_window__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F340
// Name: _dynamic_initializer_for__budget_averages_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_averages_window__()
{
  ConVar::ConVar(
    this: &budget_averages_window,
    pName: "budget_averages_window",
    pDefaultValue: "30",
    flags: 128,
    pHelpString: "number of frames to look at when figuring out average frametimes");
  return atexit(func: dynamic_atexit_destructor_for__budget_averages_window__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F370
// Name: _dynamic_initializer_for__budget_show_peaks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_peaks__()
{
  ConVar::ConVar(
    this: &budget_show_peaks,
    pName: "budget_show_peaks",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "enable/disable peaks in the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_peaks__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F3A0
// Name: _dynamic_initializer_for__budget_show_averages__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_averages__()
{
  ConVar::ConVar(
    this: &budget_show_averages,
    pName: "budget_show_averages",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "enable/disable averages in the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_averages__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F3D0
// Name: _dynamic_initializer_for__budget_show_history__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_history__()
{
  ConVar::ConVar(
    this: &budget_show_history,
    pName: "budget_show_history",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "turn history graph off and on. . good to turn off on low end");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_history__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F400
// Name: _dynamic_initializer_for__budget_history_numsamplesvisible__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_history_numsamplesvisible__()
{
  ConVar::ConVar(
    this: &budget_history_numsamplesvisible,
    pName: "budget_history_numsamplesvisible",
    pDefaultValue: "100",
    flags: 128,
    pHelpString: "number of samples to draw in the budget history window.  The lower the better as far as rendering overhead of the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_history_numsamplesvisible__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F4C0
// Name: _dynamic_initializer_for__budget_history_range_ms__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_history_range_ms__()
{
  ConVar::ConVar(
    this: &budget_history_range_ms,
    pName: "budget_history_range_ms",
    pDefaultValue: "66.666666667",
    flags: 128,
    pHelpString: "budget history range in milliseconds",
    callback: (void (__cdecl *)(IConVar *, const char *, float))PanelGeometryChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__budget_history_range_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F4F0
// Name: _dynamic_initializer_for__budget_panel_bottom_of_history_fraction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_bottom_of_history_fraction__()
{
  ConVar::ConVar(
    this: &budget_panel_bottom_of_history_fraction,
    pName: "budget_panel_bottom_of_history_fraction",
    pDefaultValue: ".25",
    flags: 128,
    pHelpString: "number between 0 and 1",
    callback: (void (__cdecl *)(IConVar *, const char *, float))PanelGeometryChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_bottom_of_history_fraction__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F520
// Name: _dynamic_initializer_for__budget_bargraph_range_ms__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_bargraph_range_ms__()
{
  ConVar::ConVar(
    this: &budget_bargraph_range_ms,
    pName: "budget_bargraph_range_ms",
    pDefaultValue: "16.6666666667",
    flags: 128,
    pHelpString: "budget bargraph range in milliseconds",
    callback: (void (__cdecl *)(IConVar *, const char *, float))PanelGeometryChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__budget_bargraph_range_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F550
// Name: _dynamic_initializer_for__budget_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_background_alpha__()
{
  ConVar::ConVar(
    this: &budget_background_alpha,
    pName: "budget_background_alpha",
    pDefaultValue: "128",
    flags: 128,
    pHelpString: "how translucent the budget panel is");
  return atexit(func: dynamic_atexit_destructor_for__budget_background_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F580
// Name: _dynamic_initializer_for__budget_panel_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_x__()
{
  ConVar::ConVar(
    this: &budget_panel_x,
    pName: "budget_panel_x",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "number of pixels from the left side of the game screen to draw the budget panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))PanelGeometryChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_x__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F5B0
// Name: _dynamic_initializer_for__budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_y__()
{
  ConVar::ConVar(
    this: &budget_panel_y,
    pName: "budget_panel_y",
    pDefaultValue: "50",
    flags: 128,
    pHelpString: "number of pixels from the top side of the game screen to draw the budget panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))PanelGeometryChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_y__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F5E0
// Name: _dynamic_initializer_for__budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_width__()
{
  ConVar::ConVar(
    this: &budget_panel_width,
    pName: "budget_panel_width",
    pDefaultValue: "512",
    flags: 128,
    pHelpString: "width in pixels of the budget panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))PanelGeometryChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_width__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F610
// Name: _dynamic_initializer_for__budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_panel_height__()
{
  ConVar::ConVar(
    this: &budget_panel_height,
    pName: "budget_panel_height",
    pDefaultValue: "384",
    flags: 128,
    pHelpString: "height in pixels of the budget panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))PanelGeometryChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__budget_panel_height__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FB00
// Name: _dynamic_initializer_for__texture_budget_panel_global__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_global__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_global,
    pName: "texture_budget_panel_global",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show global times in the texture budget panel.");
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_global__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FC50
// Name: _dynamic_initializer_for__texture_budget_panel_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_x__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_x,
    pName: "texture_budget_panel_x",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "number of pixels from the left side of the game screen to draw the budget panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_x__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FC80
// Name: _dynamic_initializer_for__texture_budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_y__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_y,
    pName: "texture_budget_panel_y",
    pDefaultValue: "450",
    flags: 128,
    pHelpString: "number of pixels from the top side of the game screen to draw the budget panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_y__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FCB0
// Name: _dynamic_initializer_for__texture_budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_width__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_width,
    pName: "texture_budget_panel_width",
    pDefaultValue: "512",
    flags: 128,
    pHelpString: "width in pixels of the budget panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_width__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FCE0
// Name: _dynamic_initializer_for__texture_budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_height__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_height,
    pName: "texture_budget_panel_height",
    pDefaultValue: "284",
    flags: 128,
    pHelpString: "height in pixels of the budget panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_height__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FD10
// Name: _dynamic_initializer_for__texture_budget_panel_bottom_of_history_fraction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_bottom_of_history_fraction__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_bottom_of_history_fraction,
    pName: "texture_budget_panel_bottom_of_history_fraction",
    pDefaultValue: ".25",
    flags: 128,
    pHelpString: "number between 0 and 1",
    callback: (void (__cdecl *)(IConVar *, const char *, float))TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_bottom_of_history_fraction__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FD40
// Name: _dynamic_initializer_for__texture_budget_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_background_alpha__()
{
  ConVar::ConVar(
    this: &texture_budget_background_alpha,
    pName: "texture_budget_background_alpha",
    pDefaultValue: "128",
    flags: 128,
    pHelpString: "how translucent the budget panel is");
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_background_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x10326E90
// Name: _dynamic_atexit_destructor_for__budget_toggle_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_toggle_group_command__()
{
  ConCommand::~ConCommand(this: &budget_toggle_group_command);
}

//------------------------------------------------------------------------------
// Address: 0x103272E0
// Name: _dynamic_atexit_destructor_for__budget_bargraph_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_bargraph_background_alpha__()
{
  ConVar::~ConVar(this: &budget_bargraph_background_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x103272F0
// Name: _dynamic_atexit_destructor_for__budget_peaks_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_peaks_window__()
{
  ConVar::~ConVar(this: &budget_peaks_window);
}

//------------------------------------------------------------------------------
// Address: 0x10327300
// Name: _dynamic_atexit_destructor_for__budget_averages_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_averages_window__()
{
  ConVar::~ConVar(this: &budget_averages_window);
}

//------------------------------------------------------------------------------
// Address: 0x10327310
// Name: _dynamic_atexit_destructor_for__budget_show_peaks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_show_peaks__()
{
  ConVar::~ConVar(this: &budget_show_peaks);
}

//------------------------------------------------------------------------------
// Address: 0x10327320
// Name: _dynamic_atexit_destructor_for__budget_show_averages__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_show_averages__()
{
  ConVar::~ConVar(this: &budget_show_averages);
}

//------------------------------------------------------------------------------
// Address: 0x10327330
// Name: _dynamic_atexit_destructor_for__budget_show_history__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_show_history__()
{
  ConVar::~ConVar(this: &budget_show_history);
}

//------------------------------------------------------------------------------
// Address: 0x10327340
// Name: _dynamic_atexit_destructor_for__budget_history_numsamplesvisible__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_history_numsamplesvisible__()
{
  ConVar::~ConVar(this: &budget_history_numsamplesvisible);
}

//------------------------------------------------------------------------------
// Address: 0x103273A0
// Name: _dynamic_atexit_destructor_for__budget_history_range_ms__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_history_range_ms__()
{
  ConVar::~ConVar(this: &budget_history_range_ms);
}

//------------------------------------------------------------------------------
// Address: 0x103273B0
// Name: _dynamic_atexit_destructor_for__budget_panel_bottom_of_history_fraction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_bottom_of_history_fraction__()
{
  ConVar::~ConVar(this: &budget_panel_bottom_of_history_fraction);
}

//------------------------------------------------------------------------------
// Address: 0x103273C0
// Name: _dynamic_atexit_destructor_for__budget_bargraph_range_ms__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_bargraph_range_ms__()
{
  ConVar::~ConVar(this: &budget_bargraph_range_ms);
}

//------------------------------------------------------------------------------
// Address: 0x103273D0
// Name: _dynamic_atexit_destructor_for__budget_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_background_alpha__()
{
  ConVar::~ConVar(this: &budget_background_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x103273E0
// Name: _dynamic_atexit_destructor_for__budget_panel_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_x__()
{
  ConVar::~ConVar(this: &budget_panel_x);
}

//------------------------------------------------------------------------------
// Address: 0x103273F0
// Name: _dynamic_atexit_destructor_for__budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_y__()
{
  ConVar::~ConVar(this: &budget_panel_y);
}

//------------------------------------------------------------------------------
// Address: 0x10327400
// Name: _dynamic_atexit_destructor_for__budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_width__()
{
  ConVar::~ConVar(this: &budget_panel_width);
}

//------------------------------------------------------------------------------
// Address: 0x10327410
// Name: _dynamic_atexit_destructor_for__budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_height__()
{
  ConVar::~ConVar(this: &budget_panel_height);
}

//------------------------------------------------------------------------------
// Address: 0x10327510
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_global__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_global__()
{
  ConVar::~ConVar(this: &texture_budget_panel_global);
}

//------------------------------------------------------------------------------
// Address: 0x10327580
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_x__()
{
  ConVar::~ConVar(this: &texture_budget_panel_x);
}

//------------------------------------------------------------------------------
// Address: 0x10327590
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_y__()
{
  ConVar::~ConVar(this: &texture_budget_panel_y);
}

//------------------------------------------------------------------------------
// Address: 0x103275A0
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_width__()
{
  ConVar::~ConVar(this: &texture_budget_panel_width);
}

//------------------------------------------------------------------------------
// Address: 0x103275B0
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_height__()
{
  ConVar::~ConVar(this: &texture_budget_panel_height);
}

//------------------------------------------------------------------------------
// Address: 0x103275C0
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_bottom_of_history_fraction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_bottom_of_history_fraction__()
{
  ConVar::~ConVar(this: &texture_budget_panel_bottom_of_history_fraction);
}

//------------------------------------------------------------------------------
// Address: 0x103275D0
// Name: _dynamic_atexit_destructor_for__texture_budget_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_background_alpha__()
{
  ConVar::~ConVar(this: &texture_budget_background_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x1031F640
// Name: _dynamic_initializer_for__g_TempBudgetGroupSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TempBudgetGroupSpace__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_TempBudgetGroupSpace__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F650
// Name: _dynamic_initializer_for__g_ButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Button *dynamic_initializer_for__g_ButtonPullInModule__()
{
  g_ButtonPullInModule = g_ButtonLinkerHack;
  return g_ButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F660
// Name: _dynamic_initializer_for__g_EditablePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::EditablePanel *dynamic_initializer_for__g_EditablePanelPullInModule__()
{
  g_EditablePanelPullInModule = g_EditablePanelLinkerHack;
  return g_EditablePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F670
// Name: _dynamic_initializer_for__g_ImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ImagePanel *dynamic_initializer_for__g_ImagePanelPullInModule__()
{
  g_ImagePanelPullInModule = g_ImagePanelLinkerHack;
  return g_ImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F680
// Name: _dynamic_initializer_for__g_LabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Label *dynamic_initializer_for__g_LabelPullInModule__()
{
  g_LabelPullInModule = g_LabelLinkerHack;
  return g_LabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F690
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F6A0
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F6B0
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F6C0
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F6D0
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F6E0
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F6F0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F700
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F710
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F720
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F730
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F740
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F750
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F760
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F770
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F780
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F790
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F7A0
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F7B0
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F7C0
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F7D0
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F7E0
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F7F0
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F800
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F810
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F820
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F830
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F840
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F850
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031FB30
// Name: _dynamic_initializer_for__showbudget_texture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture__()
{
  ConVar::ConVar(
    this: &showbudget_texture,
    pName: "showbudget_texture",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Enable the texture budget panel.");
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FB60
// Name: _dynamic_initializer_for__showbudget_texture_global_sum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_global_sum__()
{
  ConVar::ConVar(
    this: &showbudget_texture_global_sum,
    pName: "showbudget_texture_global_sum",
    pDefaultValue: "0.0f",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_global_sum__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FB90
// Name: _dynamic_initializer_for__showbudget_texture_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_on__()
{
  ConCommand::ConCommand(
    this: &showbudget_texture_on,
    pName: "+showbudget_texture",
    callback: showbudget_texture_on_f,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_on__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FBC0
// Name: _dynamic_initializer_for__showbudget_texture_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_off__()
{
  ConCommand::ConCommand(
    this: &showbudget_texture_off,
    pName: "-showbudget_texture",
    callback: showbudget_texture_off_f,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_off__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FBF0
// Name: _dynamic_initializer_for__showbudget_texture_global_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_global_on__()
{
  ConCommand::ConCommand(
    this: &showbudget_texture_global_on,
    pName: "+showbudget_texture_global",
    callback: showbudget_texture_global_on_f,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_global_on__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FC20
// Name: _dynamic_initializer_for__showbudget_texture_global_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_global_off__()
{
  ConCommand::ConCommand(
    this: &showbudget_texture_global_off,
    pName: "-showbudget_texture_global",
    callback: showbudget_texture_off_f,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_global_off__);
}

//------------------------------------------------------------------------------
// Address: 0x10327420
// Name: _dynamic_atexit_destructor_for__g_TempBudgetGroupSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TempBudgetGroupSpace__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_TempBudgetGroupSpace);
}

//------------------------------------------------------------------------------
// Address: 0x10327520
// Name: _dynamic_atexit_destructor_for__showbudget_texture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture__()
{
  ConVar::~ConVar(this: &showbudget_texture);
}

//------------------------------------------------------------------------------
// Address: 0x10327530
// Name: _dynamic_atexit_destructor_for__showbudget_texture_global_sum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_global_sum__()
{
  ConVar::~ConVar(this: &showbudget_texture_global_sum);
}

//------------------------------------------------------------------------------
// Address: 0x10327540
// Name: _dynamic_atexit_destructor_for__showbudget_texture_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_on__()
{
  ConCommand::~ConCommand(this: &showbudget_texture_on);
}

//------------------------------------------------------------------------------
// Address: 0x10327550
// Name: _dynamic_atexit_destructor_for__showbudget_texture_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_off__()
{
  ConCommand::~ConCommand(this: &showbudget_texture_off);
}

//------------------------------------------------------------------------------
// Address: 0x10327560
// Name: _dynamic_atexit_destructor_for__showbudget_texture_global_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_global_on__()
{
  ConCommand::~ConCommand(this: &showbudget_texture_global_on);
}

//------------------------------------------------------------------------------
// Address: 0x10327570
// Name: _dynamic_atexit_destructor_for__showbudget_texture_global_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_global_off__()
{
  ConCommand::~ConCommand(this: &showbudget_texture_global_off);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10206280
// Name: public: virtual int CConCommandMemberAccessor<class CTextureBudgetPanel>::CommandCompletionCallback(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConCommandMemberAccessor<CTextureBudgetPanel>::CommandCompletionCallback(
        CConCommandMemberAccessor<CEngineVGui> *this,
        const char *pPartial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  return ((int (__thiscall *)(char *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))this->m_fnCommandCallbackV1)(
           a1: (char *)this->m_pNext + (unsigned int)this->m_fnCompletionCallback,
           a2: pPartial,
           a3: commands);
}

//------------------------------------------------------------------------------
// Address: 0x10206D90
// Name: public: CConCommandMemberAccessor<class CEngineVGui>::CConCommandMemberAccessor<class CEngineVGui>(class CEngineVGui __near *,char const __near *,void (CEngineVGui::*)(class CCommand const __near &),char const __near *,int,int (CEngineVGui::*)(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &))
// Source: json
//------------------------------------------------------------------------------
CConCommandMemberAccessor<CEngineVGui> *__thiscall CConCommandMemberAccessor<CEngineVGui>::CConCommandMemberAccessor<CEngineVGui>(
        CConCommandMemberAccessor<CEngineVGui> *this,
        CEngineVGui *pOwner,
        const char *pName,
        __int128 callback,
        const char *pHelpString,
        int flags,
        __int128 completionFunc)
{
  ICommandCompletionCallback *v8; // ecx
  ICommandCallback *v9; // eax

  if ( (_DWORD)completionFunc != 0 && this != nullptr )
    v8 = &this->ICommandCompletionCallback;
  else
    v8 = nullptr;
  if ( this != nullptr )
    v9 = &this->ICommandCallback;
  else
    v9 = nullptr;
  ConCommand::ConCommand(this, pName, pCallback: v9, pHelpString, flags, pCompletionCallback: v8);
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  *(_QWORD *)&this->m_Func = callback;
  this->m_pOwner = pOwner;
  LODWORD(this->m_CompletionFunc) = completionFunc;
  *((_QWORD *)&this->m_Func + 1) = *((_QWORD *)&callback + 1);
  *(_QWORD *)((char *)&this->m_CompletionFunc + 4) = *(_QWORD *)((char *)&completionFunc + 4);
  HIDWORD(this->m_CompletionFunc) = HIDWORD(completionFunc);
  this->ConCommand::ConCommandBase::__vftable = (CConCommandMemberAccessor<CEngineVGui>_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ConCommand'};
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ICommandCallback'};
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CEngineVGui>::`vftable'{for `ICommandCompletionCallback'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020CBA0
// Name: void showbudget_texture_global_on_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl showbudget_texture_global_on_f()
{
  unsigned int v0; // [esp-10h] [ebp-10h]
  int v1; // [esp-Ch] [ebp-Ch]
  unsigned int v2; // [esp-8h] [ebp-8h]
  int v3; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&texture_budget_panel_global.IConVar, value: 1, a2: v0, a3: v1);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&showbudget_texture.IConVar, value: 1, a2: v2, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1020CBC0
// Name: void showbudget_texture_off_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl showbudget_texture_off_f()
{
  unsigned int v0; // [esp-8h] [ebp-8h]
  int v1; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&showbudget_texture.IConVar, value: 0, a2: v0, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1020CBD0
// Name: public: virtual void CTextureBudgetPanel::ResetAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::ResetAll(CTextureBudgetPanel *this)
{
  CBaseBudgetPanel::ResetAll(this);
  this->m_MaxValue = 0;
  this->m_SumOfValues = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020CBF0
// Name: public: virtual void CConCommandMemberAccessor<class CTextureBudgetPanel>::CommandCallback(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandMemberAccessor<CTextureBudgetPanel>::CommandCallback(
        CConCommandMemberAccessor<CEngineVGui> *this,
        const CCommand *command)
{
  ((void (__thiscall *)(const char *, const CCommand *))this->m_pszName)(
    a1: &this->m_pszHelpString[*(_DWORD *)&this->m_bRegistered],
    a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x1020CCC0
// Name: private: enum CounterGroup_t CTextureBudgetPanel::GetCurrentCounterGroup(void)const
// Source: json
//------------------------------------------------------------------------------
CounterGroup_t __thiscall CTextureBudgetPanel::GetCurrentCounterGroup(CTextureBudgetPanel *this)
{
  CounterGroup_t result; // eax

  if ( texture_budget_panel_global.m_pParent == nullptr )
    return COUNTER_GROUP_TEXTURE_PER_FRAME;
  result = COUNTER_GROUP_TEXTURE_GLOBAL;
  if ( texture_budget_panel_global.m_pParent->m_Value.m_nValue == 0 )
    return COUNTER_GROUP_TEXTURE_PER_FRAME;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020CCE0
// Name: public: CConCommandMemberAccessor<class CTextureBudgetPanel>::CConCommandMemberAccessor<class CTextureBudgetPanel>(class CTextureBudgetPanel __near *,char const __near *,void (CTextureBudgetPanel::*)(class CCommand const __near &),char const __near *,int,int (CTextureBudgetPanel::*)(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &))
// Source: json
//------------------------------------------------------------------------------
CConCommandMemberAccessor<CTextureBudgetPanel> *__thiscall CConCommandMemberAccessor<CTextureBudgetPanel>::CConCommandMemberAccessor<CTextureBudgetPanel>(
        CConCommandMemberAccessor<CTextureBudgetPanel> *this,
        CTextureBudgetPanel *pOwner,
        const char *pName,
        __int128 callback,
        const char *pHelpString,
        int flags,
        __int128 completionFunc)
{
  ICommandCompletionCallback *v8; // ecx
  ICommandCallback *v9; // eax

  if ( (_DWORD)completionFunc != 0 && this != nullptr )
    v8 = &this->ICommandCompletionCallback;
  else
    v8 = nullptr;
  if ( this != nullptr )
    v9 = &this->ICommandCallback;
  else
    v9 = nullptr;
  ConCommand::ConCommand(this, pName, pCallback: v9, pHelpString, flags, pCompletionCallback: v8);
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  *(_QWORD *)&this->m_Func = callback;
  this->m_pOwner = pOwner;
  LODWORD(this->m_CompletionFunc) = completionFunc;
  *((_QWORD *)&this->m_Func + 1) = *((_QWORD *)&callback + 1);
  *(_QWORD *)((char *)&this->m_CompletionFunc + 4) = *(_QWORD *)((char *)&completionFunc + 4);
  HIDWORD(this->m_CompletionFunc) = HIDWORD(completionFunc);
  this->ConCommand::ConCommandBase::__vftable = (CConCommandMemberAccessor<CTextureBudgetPanel>_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ConCommand'};
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ICommandCallback'};
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CTextureBudgetPanel>::`vftable'{for `ICommandCompletionCallback'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020CDB0
// Name: public: virtual void CTextureBudgetPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::OnTick(CTextureBudgetPanel *this)
{
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( showbudget_texture.m_pParent != nullptr && showbudget_texture.m_pParent->m_Value.m_nValue != 0 )
  {
    this->m_pModeLabel->SetVisible(this: this->m_pModeLabel, a2: true);
    this->SetVisible(this, a2: true);
  }
  else
  {
    this->m_pModeLabel->SetVisible(this: this->m_pModeLabel, a2: false);
    this->SetVisible(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CE10
// Name: public: virtual void CTextureBudgetPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBudgetPanel::PerformLayout(CTextureBudgetPanel *this@<ecx>, int a2@<edi>)
{
  const char *v3; // edi
  IMatSystemSurface_vtbl *v4; // ebx
  int v5; // eax
  int v6; // edi
  int Tall; // eax
  int v8; // eax
  vgui::Label *m_pModeLabel; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  int m_nValue; // eax
  vgui::Label *v12; // ecx
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // eax
  int x; // [esp+8h] [ebp-Ch] BYREF
  int y; // [esp+Ch] [ebp-8h] BYREF
  int v16; // [esp+10h] [ebp-4h]

  CBaseBudgetPanel::PerformLayout(this, a2);
  v3 = "Per-frame texture stats";
  if ( texture_budget_panel_global.m_pParent != nullptr && texture_budget_panel_global.m_pParent->m_Value.m_nValue != 0 )
    v3 = "Global texture stats";
  this->m_pModeLabel->SetText(this: this->m_pModeLabel, a2: v3);
  v4 = g_pMatSystemSurface->__vftable;
  v5 = ((int (__thiscall *)(vgui::Label *, const char *, const char *))this->m_pModeLabel->GetFont)(
         a1: this->m_pModeLabel,
         a2: "%s",
         a3: v3);
  v6 = ((int (__cdecl *)(IMatSystemSurface *, int))v4->DrawTextLen)(a1: g_pMatSystemSurface, a2: v5);
  Tall = vgui::Panel::GetTall(this: this->m_pModeLabel);
  vgui::Panel::SetSize(this: this->m_pModeLabel, wide: v6 + 10, tall: Tall);
  vgui::Panel::GetPos(this, &x, &y);
  v8 = vgui::Panel::GetTall(this: this->m_pModeLabel);
  vgui::Panel::SetPos(this: this->m_pModeLabel, x, y: y - v8);
  m_pModeLabel = this->m_pModeLabel;
  SetFgColor = m_pModeLabel->SetFgColor;
  v16 = -1;
  ((void (__thiscall *)(vgui::Label *, int))SetFgColor)(a1: m_pModeLabel, a2: -1);
  if ( texture_budget_background_alpha.m_pParent != nullptr )
    m_nValue = texture_budget_background_alpha.m_pParent->m_Value.m_nValue;
  else
    LOBYTE(m_nValue) = 0;
  v12 = this->m_pModeLabel;
  HIBYTE(v16) = m_nValue;
  SetBgColor = v12->SetBgColor;
  LOWORD(v16) = 0;
  BYTE2(v16) = 0;
  ((void (__thiscall *)(vgui::Label *, int))SetBgColor)(a1: v12, a2: v16);
}

//------------------------------------------------------------------------------
// Address: 0x1020CF20
// Name: public: virtual void CTextureBudgetPanel::SetTimeLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::SetTimeLabelText(CTextureBudgetPanel *this)
{
  int v1; // edi
  vgui::Label *v3; // ecx
  char pDest[8]; // [esp+10h] [ebp-204h] BYREF
  char text[512]; // [esp+18h] [ebp-1FCh]

  v1 = 0;
  for ( *(_DWORD *)&text[504] = 0; v1 < this->m_TimeLabels.m_Size; *(_DWORD *)&text[504] = v1 )
  {
    V_snprintf(
      pDest,
      maxLen: 512,
      pFormat: "%.1fM",
      (double)*(int *)&text[504] * this->m_ConfigData.m_flTimeLabelInterval * 0.0009765625);
    v3 = this->m_TimeLabels.m_Memory.m_pMemory[v1];
    v3->SetText(this: v3, a2: pDest);
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CFA0
// Name: public: virtual void CTextureBudgetPanel::SetHistoryLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::SetHistoryLabelText(CTextureBudgetPanel *this)
{
  int i; // esi
  vgui::Label *v3; // ecx
  char pDest[8]; // [esp+10h] [ebp-200h] BYREF

  for ( i = 0; i < this->m_HistoryLabels.m_Size; ++i )
  {
    V_snprintf(
      pDest,
      maxLen: 512,
      pFormat: "%.1fM",
      this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory[i] * 0.0009765625);
    v3 = this->m_HistoryLabels.m_Memory.m_pMemory[i];
    v3->SetText(this: v3, a2: pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D020
// Name: private: void CTextureBudgetPanel::DumpGlobalTextureStats(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::DumpGlobalTextureStats(CTextureBudgetPanel *this, const CCommand *args)
{
  int i; // esi
  const char *CounterName; // edi
  int CounterValue; // eax

  for ( i = 0; i < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled); ++i )
  {
    if ( CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i) == COUNTER_GROUP_TEXTURE_GLOBAL )
    {
      CounterName = CVProfile::GetCounterName(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i);
      CounterValue = CVProfile::GetCounterValue(
                       this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                       a2: i);
      _Warning(a1: "%s: %d\n", CounterName, CounterValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D0A0
// Name: public: CTextureBudgetPanel::CTextureBudgetPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTextureBudgetPanel *__thiscall CTextureBudgetPanel::CTextureBudgetPanel(
        CTextureBudgetPanel *this,
        vgui::Panel *pParent,
        const char *pElementName)
{
  vgui::Label *v4; // eax
  vgui::Label *v5; // eax
  __int128 v7; // [esp-10h] [ebp-1Ch]

  CBaseBudgetPanel::CBaseBudgetPanel(this, pParent, pElementName);
  *(_QWORD *)&v7 = 0;
  *((_QWORD *)&v7 + 1) = 0xFFFFFFFF00000000uLL;
  this->__vftable = (CTextureBudgetPanel_vtbl *)&CTextureBudgetPanel::`vftable';
  CConCommandMemberAccessor<CTextureBudgetPanel>::CConCommandMemberAccessor<CTextureBudgetPanel>(
    this: &this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "showbudget_texture_global_dumpstats",
    callback: (unsigned int)CTextureBudgetPanel::DumpGlobalTextureStats,
    pHelpString: "Dump all items in +showbudget_texture_global in a text form",
    flags: 0,
    completionFunc: v7);
  this->m_DumpGlobalTextureStats_register.m_ConCommandAccessor.m_pOwner = this;
  this->m_LastCounterGroup = -1;
  g_pTextureBudgetPanel = this;
  this->m_MaxValue = 1000;
  this->m_SumOfValues = 0;
  v4 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v4 != nullptr )
    v5 = vgui::Label::Label(this: v4, parent: this, panelName: "mode label", text: defaultValue);
  else
    v5 = nullptr;
  this->m_pModeLabel = v5;
  v5->SetParent_2(this: v5, a2: pParent);
  vgui::Panel::SetVisible(this, state: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020D190
// Name: private: void CTextureBudgetPanel::SendConfigDataToBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::SendConfigDataToBase(CTextureBudgetPanel *this)
{
  CTextureBudgetPanel *v1; // edi
  int v2; // esi
  CounterGroup_t CurrentCounterGroup; // eax
  int v4; // edx
  char *CounterName; // edi
  int v6; // esi
  char *v7; // eax
  int v8; // esi
  int m_Size; // eax
  int v10; // esi
  CBudgetGroupInfo *m_pMemory; // ecx
  int v12; // eax
  int v13; // edx
  CBudgetGroupInfo *v14; // eax
  Color m_Color; // edx
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // ecx
  float *v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  float *v25; // eax
  CBudgetGroupInfo *v26; // eax
  int *p_r; // [esp-18h] [ebp-1A0h]
  int *p_g; // [esp-14h] [ebp-19Ch]
  int *p_b; // [esp-10h] [ebp-198h]
  int *p_a; // [esp-Ch] [ebp-194h]
  char alternateName[256]; // [esp+Ch] [ebp-17Ch] BYREF
  int g; // [esp+10Ch] [ebp-7Ch] BYREF
  int r; // [esp+110h] [ebp-78h] BYREF
  int a; // [esp+114h] [ebp-74h] BYREF
  const char *pPrefixes[2]; // [esp+118h] [ebp-70h]
  int b; // [esp+120h] [ebp-68h] BYREF
  CTextureBudgetPanel *v37; // [esp+124h] [ebp-64h]
  CBudgetPanelConfigData data; // [esp+128h] [ebp-60h] BYREF
  CBudgetGroupInfo info; // [esp+178h] [ebp-10h]
  CUtlSymbol v40; // [esp+182h] [ebp-6h] BYREF
  int i; // [esp+184h] [ebp-4h]

  v1 = this;
  v2 = 0;
  v37 = this;
  memset(&data, 0, 20);
  memset(&data.m_HistoryLabelValues, 0, sizeof(data.m_HistoryLabelValues));
  i = 0;
  if ( (int)CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) > 0 )
  {
    do
    {
      CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v2);
      CurrentCounterGroup = CTextureBudgetPanel::GetCurrentCounterGroup(this: v1);
      if ( v4 == CurrentCounterGroup )
      {
        CounterName = (char *)CVProfile::GetCounterName(
                                this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                a2: v2);
        pPrefixes[0] = "TexGroup_global_";
        pPrefixes[1] = "TexGroup_frame_";
        v6 = 0;
        while ( 1 )
        {
          strstr(str1: (unsigned __int8 *)CounterName, str2: (unsigned __int8 *)pPrefixes[v6]);
          if ( v7 == CounterName )
            break;
          if ( ++v6 >= 2 )
            goto LABEL_8;
        }
        v8 = strlen(pPrefixes[v6]);
        V_strncpy(pDest: alternateName, pSrc: &CounterName[v8], maxLen: v8);
        alternateName[v8] = 0;
        CounterName = alternateName;
LABEL_8:
        p_a = &a;
        p_b = &b;
        p_g = &g;
        p_r = &r;
        info.m_Color = 0;
        CVProfile::GetBudgetGroupColor(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: data.m_BudgetGroupInfo.m_Size);
        info.m_Color._color[0] = r;
        info.m_Color._color[2] = b;
        info.m_Color._color[1] = g;
        info.m_Color._color[3] = a;
        CUtlSymbol::CUtlSymbol(this: &v40, pStr: CounterName);
        m_Size = data.m_BudgetGroupInfo.m_Size;
        v10 = data.m_BudgetGroupInfo.m_Size;
        if ( data.m_BudgetGroupInfo.m_Size + 1 > data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<sentencegroup_t,int>::Grow(
            this: (CUtlMemory<sentencegroup_t,int> *)&data,
            num: data.m_BudgetGroupInfo.m_Size - data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount + 1);
          m_Size = data.m_BudgetGroupInfo.m_Size;
        }
        m_pMemory = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
        data.m_BudgetGroupInfo.m_Size = m_Size + 1;
        v12 = m_Size - v10;
        data.m_BudgetGroupInfo.m_pElements = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
        if ( v12 > 0 )
        {
          _V_memmove(
            dest: &data.m_BudgetGroupInfo.m_Memory.m_pMemory[v10 + 1],
            src: &data.m_BudgetGroupInfo.m_Memory.m_pMemory[v10],
            count: 6 * v12);
          m_pMemory = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
        }
        v1 = v37;
        v13 = v10;
        v2 = i;
        v14 = &m_pMemory[v13];
        if ( v14 != nullptr )
        {
          m_Color = info.m_Color;
          v14->m_Name = v40;
          v14->m_Color = m_Color;
        }
      }
      i = ++v2;
    }
    while ( v2 < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) );
  }
  v16 = 4 * v1->m_MaxValue / 3;
  data.m_flBottomOfHistoryFraction = texture_budget_panel_bottom_of_history_fraction.m_pParent->m_Value.m_fValue;
  v17 = (float)v16;
  v18 = 4 * v1->m_SumOfValues;
  data.m_flBarGraphRange = v17;
  data.m_flTimeLabelInterval = v17 * 0.25;
  data.m_nLinesPerTimeLabel = 4;
  data.m_flHistoryRange = (float)(v18 / 3);
  data.m_HistoryLabelValues.m_Size = 0;
  if ( data.m_HistoryLabelValues.m_Memory.m_nAllocationCount < 3 )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&data.m_HistoryLabelValues,
      num: 3 - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount);
  v19 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  data.m_HistoryLabelValues.m_Size += 3;
  data.m_HistoryLabelValues.m_pElements = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  if ( data.m_HistoryLabelValues.m_Size - 3 > 0 )
  {
    _V_memmove(
      dest: data.m_HistoryLabelValues.m_Memory.m_pMemory + 3,
      src: data.m_HistoryLabelValues.m_Memory.m_pMemory,
      count: 4 * (data.m_HistoryLabelValues.m_Size - 3));
    v19 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v20 = 0;
  if ( data.m_HistoryLabelValues.m_Size > 0 )
  {
    while ( 1 )
    {
      v19[v20] = (float)((float)(v20 + 1) * data.m_flHistoryRange) * 0.25;
      if ( ++v20 >= data.m_HistoryLabelValues.m_Size )
        break;
      v19 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
    }
  }
  data.m_flBackgroundAlpha = texture_budget_background_alpha.m_pParent->m_Value.m_fValue;
  if ( texture_budget_panel_x.m_pParent != nullptr )
    data.m_xCoord = texture_budget_panel_x.m_pParent->m_Value.m_nValue;
  else
    data.m_xCoord = 0;
  if ( texture_budget_panel_y.m_pParent != nullptr )
    data.m_yCoord = texture_budget_panel_y.m_pParent->m_Value.m_nValue;
  else
    data.m_yCoord = 0;
  if ( texture_budget_panel_width.m_pParent != nullptr )
    data.m_Width = texture_budget_panel_width.m_pParent->m_Value.m_nValue;
  else
    data.m_Width = 0;
  if ( texture_budget_panel_height.m_pParent != nullptr )
    data.m_Height = texture_budget_panel_height.m_pParent->m_Value.m_nValue;
  else
    data.m_Height = 0;
  v21 = ((int (__thiscall *)(IVideoMode *, int *, int *, int *, int *))videomode->GetModeWidth)(
          a1: videomode,
          a2: p_r,
          a3: p_g,
          a4: p_b,
          a5: p_a);
  if ( data.m_xCoord + data.m_Width > v21 )
  {
    v22 = videomode->GetModeWidth(this: videomode);
    data.m_xCoord = v22 - data.m_Width;
  }
  v23 = videomode->GetModeHeight(this: videomode);
  if ( data.m_yCoord + data.m_Height > v23 )
  {
    v24 = videomode->GetModeHeight(this: videomode);
    data.m_yCoord = v24 - data.m_Height;
  }
  CBaseBudgetPanel::OnConfigDataChanged(this: v1, &data);
  v25 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  data.m_HistoryLabelValues.m_Size = 0;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_HistoryLabelValues.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_HistoryLabelValues.m_Memory.m_pMemory);
      v25 = nullptr;
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  data.m_HistoryLabelValues.m_pElements = v25;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v25 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  v26 = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
  data.m_BudgetGroupInfo.m_Size = 0;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_BudgetGroupInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_BudgetGroupInfo.m_Memory.m_pMemory);
      v26 = nullptr;
      data.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
    }
    data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  }
  data.m_BudgetGroupInfo.m_pElements = v26;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 && v26 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
}

//------------------------------------------------------------------------------
// Address: 0x1020D570
// Name: private: void CTextureBudgetPanel::SnapshotTextureHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::SnapshotTextureHistory(CTextureBudgetPanel *this)
{
  int v2; // ebx
  CounterGroup_t CurrentCounterGroup; // eax
  int v4; // edx
  int CounterValue; // eax
  int m_MaxValue; // ecx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  CounterGroup_t v11; // eax
  int v12; // edx
  int v13; // ebx
  CounterGroup_t v14; // eax
  int v15; // edx
  int v16; // ecx
  unsigned int v17; // [esp-8h] [ebp-20h]
  int v18; // [esp-4h] [ebp-1Ch]
  int value; // [esp+Ch] [ebp-Ch]
  int nCounters; // [esp+10h] [ebp-8h]
  int nCountersa; // [esp+10h] [ebp-8h]
  bool bForceSendConfigData; // [esp+17h] [ebp-1h]

  v2 = 0;
  for ( this->m_SumOfValues = 0;
        v2 < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        ++v2 )
  {
    CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v2);
    CurrentCounterGroup = CTextureBudgetPanel::GetCurrentCounterGroup(this);
    if ( v4 == CurrentCounterGroup )
    {
      CounterValue = CVProfile::GetCounterValue(
                       this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                       a2: v2);
      m_MaxValue = this->m_MaxValue;
      v7 = CounterValue / 1024;
      this->m_SumOfValues += v7;
      if ( m_MaxValue > v7 )
        v7 = m_MaxValue;
      this->m_MaxValue = v7;
    }
  }
  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&showbudget_texture_global_sum.IConVar,
    value: this->m_SumOfValues,
    a2: v17,
    a3: v18);
  bForceSendConfigData = false;
  if ( (float)this->m_MaxValue > this->m_ConfigData.m_flBarGraphRange
    || (float)this->m_SumOfValues > this->m_ConfigData.m_flHistoryRange )
  {
    bForceSendConfigData = true;
  }
  v8 = 0;
  if ( texture_budget_panel_global.m_pParent == nullptr
    || (v9 = 2, texture_budget_panel_global.m_pParent->m_Value.m_nValue == 0) )
  {
    v9 = 3;
  }
  if ( this->m_LastCounterGroup != v9 )
  {
    this->ResetAll(this);
    if ( texture_budget_panel_global.m_pParent == nullptr
      || (v10 = 2, texture_budget_panel_global.m_pParent->m_Value.m_nValue == 0) )
    {
      v10 = 3;
    }
    this->m_LastCounterGroup = v10;
  }
  nCounters = 0;
  if ( (int)CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) > 0 )
  {
    do
    {
      CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v8);
      v11 = CTextureBudgetPanel::GetCurrentCounterGroup(this);
      if ( v12 == v11 )
        ++nCounters;
      ++v8;
    }
    while ( v8 < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) );
  }
  if ( bForceSendConfigData || nCounters != this->m_ConfigData.m_BudgetGroupInfo.m_Size )
    CTextureBudgetPanel::SendConfigDataToBase(this);
  this->m_BudgetHistoryOffset = (this->m_BudgetHistoryOffset + 1) % 1024;
  v13 = 0;
  if ( (int)CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) > 0 )
  {
    nCountersa = 0;
    do
    {
      CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v13);
      v14 = CTextureBudgetPanel::GetCurrentCounterGroup(this);
      if ( v15 == v14 )
      {
        value = CVProfile::GetCounterValue(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: v13)
              / 1024;
        v16 = nCountersa + this->m_BudgetHistoryOffset;
        nCountersa += 1024;
        this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[v16] = (double)value;
      }
      ++v13;
    }
    while ( v13 < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D760
// Name: TextureCVarChangedCallBack
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextureCVarChangedCallBack()
{
  if ( g_pTextureBudgetPanel != nullptr )
    CTextureBudgetPanel::SendConfigDataToBase(this: g_pTextureBudgetPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1020D770
// Name: public: virtual void CTextureBudgetPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBudgetPanel::Paint(CTextureBudgetPanel *this)
{
  CTextureBudgetPanel::SnapshotTextureHistory(this);
  CVProfile::ResetCounters(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: COUNTER_GROUP_TEXTURE_PER_FRAME);
  CBaseBudgetPanel::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA00
// Name: _dynamic_initializer_for__budget_toggle_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_toggle_group_command__()
{
  ConCommand::ConCommand(
    this: &budget_toggle_group_command,
    pName: "budget_toggle_group",
    callback: budget_toggle_group,
    pHelpString: "Turn a budget group on/off",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__budget_toggle_group_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F4B0
// Name: _dynamic_initializer_for__budget_bargraph_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_bargraph_background_alpha__()
{
  ConVar::ConVar(
    this: &budget_bargraph_background_alpha,
    pName: "budget_bargraph_background_alpha",
    pDefaultValue: "128",
    flags: 128,
    pHelpString: "how translucent the budget panel is");
  return atexit(func: dynamic_atexit_destructor_for__budget_bargraph_background_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F4E0
// Name: _dynamic_initializer_for__budget_peaks_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_peaks_window__()
{
  ConVar::ConVar(
    this: &budget_peaks_window,
    pName: "budget_peaks_window",
    pDefaultValue: "30",
    flags: 128,
    pHelpString: "number of frames to look at when figuring out peak frametimes");
  return atexit(func: dynamic_atexit_destructor_for__budget_peaks_window__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F510
// Name: _dynamic_initializer_for__budget_averages_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_averages_window__()
{
  ConVar::ConVar(
    this: &budget_averages_window,
    pName: "budget_averages_window",
    pDefaultValue: "30",
    flags: 128,
    pHelpString: "number of frames to look at when figuring out average frametimes");
  return atexit(func: dynamic_atexit_destructor_for__budget_averages_window__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F540
// Name: _dynamic_initializer_for__budget_show_peaks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_peaks__()
{
  ConVar::ConVar(
    this: &budget_show_peaks,
    pName: "budget_show_peaks",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "enable/disable peaks in the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_peaks__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F570
// Name: _dynamic_initializer_for__budget_show_averages__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_averages__()
{
  ConVar::ConVar(
    this: &budget_show_averages,
    pName: "budget_show_averages",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "enable/disable averages in the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_averages__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F5A0
// Name: _dynamic_initializer_for__budget_show_history__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_show_history__()
{
  ConVar::ConVar(
    this: &budget_show_history,
    pName: "budget_show_history",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "turn history graph off and on. . good to turn off on low end");
  return atexit(func: dynamic_atexit_destructor_for__budget_show_history__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F5D0
// Name: _dynamic_initializer_for__budget_history_numsamplesvisible__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__budget_history_numsamplesvisible__()
{
  ConVar::ConVar(
    this: &budget_history_numsamplesvisible,
    pName: "budget_history_numsamplesvisible",
    pDefaultValue: "100",
    flags: 128,
    pHelpString: "number of samples to draw in the budget history window.  The lower the better as far as rendering overhead of the budget panel");
  return atexit(func: dynamic_atexit_destructor_for__budget_history_numsamplesvisible__);
}

//------------------------------------------------------------------------------
// Address: 0x10327080
// Name: _dynamic_atexit_destructor_for__budget_toggle_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_toggle_group_command__()
{
  ConCommand::~ConCommand(this: &budget_toggle_group_command);
}

//------------------------------------------------------------------------------
// Address: 0x103274D0
// Name: _dynamic_atexit_destructor_for__budget_bargraph_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_bargraph_background_alpha__()
{
  ConVar::~ConVar(this: &budget_bargraph_background_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x103274E0
// Name: _dynamic_atexit_destructor_for__budget_peaks_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_peaks_window__()
{
  ConVar::~ConVar(this: &budget_peaks_window);
}

//------------------------------------------------------------------------------
// Address: 0x103274F0
// Name: _dynamic_atexit_destructor_for__budget_averages_window__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_averages_window__()
{
  ConVar::~ConVar(this: &budget_averages_window);
}

//------------------------------------------------------------------------------
// Address: 0x10327500
// Name: _dynamic_atexit_destructor_for__budget_show_peaks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_show_peaks__()
{
  ConVar::~ConVar(this: &budget_show_peaks);
}

//------------------------------------------------------------------------------
// Address: 0x103275E0
// Name: _dynamic_atexit_destructor_for__budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_y__()
{
  ConVar::~ConVar(this: &budget_panel_y);
}

//------------------------------------------------------------------------------
// Address: 0x103275F0
// Name: _dynamic_atexit_destructor_for__budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_width__()
{
  ConVar::~ConVar(this: &budget_panel_width);
}

//------------------------------------------------------------------------------
// Address: 0x10327600
// Name: _dynamic_atexit_destructor_for__budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__budget_panel_height__()
{
  ConVar::~ConVar(this: &budget_panel_height);
}

//------------------------------------------------------------------------------
// Address: 0x1031F860
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F870
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F880
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F890
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F8A0
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F8B0
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F8C0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F8D0
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F8E0
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F8F0
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F900
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F910
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F920
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F930
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F940
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F950
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F960
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F970
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F980
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F990
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F9A0
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F9B0
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F9C0
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F9D0
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F9E0
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031F9F0
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031FA00
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031FA10
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1031FA20
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x10327610
// Name: _dynamic_atexit_destructor_for__g_TempBudgetGroupSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TempBudgetGroupSpace__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_TempBudgetGroupSpace);
}

} // namespace engine_xlsp
