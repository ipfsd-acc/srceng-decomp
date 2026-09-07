// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/benchmarkdialog.cpp
// Functions: 17
// ============================================================

#include "game\client\cstrike15\gameui\benchmarkdialog.h"

//------------------------------------------------------------------------------
// Address: 0x101EC8E0
// Name: public: static char const __near * CBenchmarkDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBenchmarkDialog::GetPanelClassName()
{
  return "CBenchmarkDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101EC8F0
// Name: private: virtual void CBenchmarkDialog::RunBenchmark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkDialog::RunBenchmark(CBenchmarkDialog *this)
{
  CCStrike15BasePanel *v2; // eax

  v2 = BasePanel();
  CBaseModPanel::ApplyOptionsDialogSettings(this: v2);
  engine->ClientCmd_Unrestricted(this: engine, a2: "disconnect\n");
  engine->ClientCmd_Unrestricted(this: engine, a2: "wait\n");
  engine->ClientCmd_Unrestricted(this: engine, a2: "wait\n");
  engine->ClientCmd_Unrestricted(this: engine, a2: "maxplayers 1\n");
  engine->ClientCmd_Unrestricted(this: engine, a2: "progress_enable\n");
  engine->ClientCmd_Unrestricted(this: engine, a2: "map test_hardware\n");
  this->Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EC990
// Name: public: static char const __near * CBenchmarkResultsDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBenchmarkResultsDialog::GetPanelClassName()
{
  return "CBenchmarkResultsDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101EC9A0
// Name: public: CBenchmarkResultsDialog::CBenchmarkResultsDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBenchmarkResultsDialog *__thiscall CBenchmarkResultsDialog::CBenchmarkResultsDialog(
        CBenchmarkResultsDialog *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBenchmarkResultsDialog_vtbl *)&CBenchmarkResultsDialog::`vftable';
  if ( `CBenchmarkResultsDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CBenchmarkResultsDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBenchmarkResultsDialog");
    v4->pfnClassName = CBenchmarkResultsDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBenchmarkResultsDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBenchmarkResultsDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBenchmarkResultsDialog");
    v5->pfnClassName = CBenchmarkResultsDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBenchmarkResultsDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBenchmarkResultsDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBenchmarkResultsDialog");
    v6->pfnClassName = CBenchmarkResultsDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetTitle(this, title: "#GameUI_BenchmarkResults_Title", surfaceTitle: true);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  v7 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v7 != nullptr )
    v8 = vgui::CheckButton::CheckButton(
           this: v7,
           parent: this,
           panelName: "UploadCheck",
           text: "#GameUI_BenchmarkResults_UploadNow");
  else
    v8 = nullptr;
  this->m_pUploadCheck = v8;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/BenchmarkResultsDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pUploadCheck->SetSelected(this: this->m_pUploadCheck, a2: true);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101ECAE0
// Name: public: virtual void CBenchmarkResultsDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkResultsDialog::Activate(CBenchmarkResultsDialog *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  double Float; // st7
  char szFrameRate[32]; // [esp+10h] [ebp-20h] BYREF

  vgui::Frame::Activate(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Benchmark");
  else
    v3 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "results/results.txt",
         pathID: "MOD",
         pfnEvaluateSymbolProc: nullptr) )
  {
    Float = KeyValues::GetFloat(this: v3, keyName: "framerate", defaultValue: 0.0);
    V_snprintf(pDest: szFrameRate, maxLen: 0x20u, pFormat: "%.2f", Float);
    this->SetDialogVariable_4(this, a2: "framerate", a3: szFrameRate);
    KeyValues::deleteThis(this: v3);
  }
  else
  {
    this->Close(this);
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECBA0
// Name: private: virtual void CBenchmarkResultsDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkResultsDialog::OnClose(CBenchmarkResultsDialog *this)
{
  if ( this->m_pUploadCheck->IsSelected(this: this->m_pUploadCheck) )
    engine->ClientCmd_Unrestricted(this: engine, a2: "bench_upload\n");
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x101ECBE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBenchmarkResultsDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBenchmarkResultsDialog::GetMessageMap(CBenchmarkResultsDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBenchmarkResultsDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBenchmarkResultsDialog::GetMessageMap'::`2'::s_pMap;
  `CBenchmarkResultsDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBenchmarkResultsDialog");
  `CBenchmarkResultsDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ECC10
// Name: public: virtual struct PanelAnimationMap __near * CBenchmarkResultsDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBenchmarkResultsDialog::GetAnimMap(CBenchmarkResultsDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CBenchmarkResultsDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101ECC20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBenchmarkResultsDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBenchmarkResultsDialog::GetKBMap(CBenchmarkResultsDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBenchmarkResultsDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBenchmarkResultsDialog::GetKBMap'::`2'::s_pMap;
  `CBenchmarkResultsDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBenchmarkResultsDialog");
  `CBenchmarkResultsDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ECC50
// Name: bench_showstatsdialog
// Source: json
//------------------------------------------------------------------------------
void __cdecl bench_showstatsdialog()
{
  CBenchmarkResultsDialog *v0; // esi
  CBaseModPanel *v1; // eax
  CBenchmarkResultsDialog *v2; // eax
  vgui::Panel *v3; // eax

  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    g_BenchmarkResultsDialog.m_iPanelID = -1;
  }
  if ( vgui::PHandle::Get(this: &g_BenchmarkResultsDialog) == nullptr )
  {
    v0 = (CBenchmarkResultsDialog *)MemAlloc_Alloc(nSize: 0x218u);
    if ( v0 != nullptr )
    {
      v1 = BasePanel();
      v2 = CBenchmarkResultsDialog::CBenchmarkResultsDialog(this: v0, parent: v1, name: "BenchmarkResultsDialog");
    }
    else
    {
      v2 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &g_BenchmarkResultsDialog, pPanel: v2);
  }
  v3 = vgui::PHandle::Get(this: &g_BenchmarkResultsDialog);
  v3->__vftable[1].OnTick(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101ECCD0
// Name: public: static void CBenchmarkDialog::PanelMessageFunc_RunBenchmark::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBenchmarkDialog::PanelMessageFunc_RunBenchmark::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBenchmarkDialog::PanelMessageFunc_RunBenchmark::InitVar'::`2'::bAdded )
  {
    `CBenchmarkDialog::PanelMessageFunc_RunBenchmark::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBenchmarkDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RunBenchmark";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECD60
// Name: public: CBenchmarkDialog::CBenchmarkDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBenchmarkDialog *__thiscall CBenchmarkDialog::CBenchmarkDialog(
        CBenchmarkDialog *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBenchmarkDialog_vtbl *)&CBenchmarkDialog::`vftable';
  if ( `CBenchmarkDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CBenchmarkDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBenchmarkDialog");
    v4->pfnClassName = CBenchmarkDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBenchmarkDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBenchmarkDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBenchmarkDialog");
    v5->pfnClassName = CBenchmarkDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBenchmarkDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBenchmarkDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBenchmarkDialog");
    v6->pfnClassName = CBenchmarkDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CBenchmarkDialog::PanelMessageFunc_RunBenchmark::InitVar();
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "RunButton",
           text: "RunButton",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v8 = nullptr;
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "RunBenchmark");
  else
    v10 = nullptr;
  v8->SetCommand(this: v8, a2: v10);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/BenchmarkDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101ECEB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBenchmarkDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBenchmarkDialog::GetMessageMap(CBenchmarkDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBenchmarkDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBenchmarkDialog::GetMessageMap'::`2'::s_pMap;
  `CBenchmarkDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBenchmarkDialog");
  `CBenchmarkDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ECEE0
// Name: public: virtual struct PanelAnimationMap __near * CBenchmarkDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBenchmarkDialog::GetAnimMap(CBenchmarkDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CBenchmarkDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101ECEF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBenchmarkDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBenchmarkDialog::GetKBMap(CBenchmarkDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBenchmarkDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBenchmarkDialog::GetKBMap'::`2'::s_pMap;
  `CBenchmarkDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBenchmarkDialog");
  `CBenchmarkDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423F10
// Name: _dynamic_initializer_for__bench_showstatsdialog_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bench_showstatsdialog_command__()
{
  ConCommand::ConCommand(
    this: &bench_showstatsdialog_command,
    pName: "bench_showstatsdialog",
    callback: bench_showstatsdialog,
    pHelpString: "Shows a dialog displaying the most recent benchmark results.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bench_showstatsdialog_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10435AA0
// Name: _dynamic_atexit_destructor_for__bench_showstatsdialog_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bench_showstatsdialog_command__()
{
  ConCommand::~ConCommand(this: &bench_showstatsdialog_command);
}
