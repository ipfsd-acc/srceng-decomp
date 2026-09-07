// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/soundbrowser.cpp
// Functions: 25
// ============================================================

#include "utils\scenemanager\soundbrowser.h"

//------------------------------------------------------------------------------
// Address: 0x0040CF00
// Name: public: struct SoundFile __near * CSoundParametersInternal::GetSoundNames(void)
// Source: json
//------------------------------------------------------------------------------
SoundFile *__thiscall CSoundParametersInternal::GetSoundNames(CSoundParametersInternal *this)
{
  SoundFile *result; // eax

  result = (SoundFile *)this;
  if ( this->m_nSoundNames != 1 )
    return this->m_pSoundNames;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CF10
// Name: public: CSoundList::CSoundList(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSoundList *__thiscall CSoundList::CSoundList(CSoundList *this, mxWindow *parent, int id)
{
  mxListView::mxListView(this, parent, x: 0, y: 0, w: 0, h: 0, id);
  this->__vftable = (CSoundList_vtbl *)&CSoundList::`vftable';
  mxListView::insertTextColumn(this, column: 0, width: 200, label: "Sound");
  mxListView::insertTextColumn(this, column: 1, width: 20, label: "#");
  mxListView::insertTextColumn(this, column: 2, width: 220, label: "WAV Filename");
  mxListView::insertTextColumn(this, column: 3, width: 300, label: "Sentence Text");
  mxListView::insertTextColumn(this, column: 4, width: 100, label: "Channel");
  mxListView::insertTextColumn(this, column: 5, width: 100, label: "Volume");
  mxListView::insertTextColumn(this, column: 6, width: 120, label: "Soundlevel");
  mxListView::insertTextColumn(this, column: 7, width: 100, label: "Pitch");
  mxListView::insertTextColumn(this, column: 8, width: 150, label: "Script File");
  mxListView::insertTextColumn(this, column: 9, width: 300, label: "CC Text");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040CFF0
// Name: public: virtual void CSoundFilterTab::ShowRightClickMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundFilterTab::ShowRightClickMenu(CSoundFilterTab *this, int mx, int my)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0040D000
// Name: public: void CSoundFilterTab::UpdatePrefixes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundFilterTab::UpdatePrefixes(CSoundFilterTab *this)
{
  int v2; // ebx
  const char *v3; // eax
  ISoundEmitterSystemBase_vtbl *v4; // edi
  char *v5; // eax
  int v6; // eax
  int v7; // eax
  int c; // [esp+8h] [ebp-4h]

  v2 = 2;
  c = this->getItemCount(this);
  if ( c > 2 )
  {
    do
    {
      this->setPrefix(this, a2: v2, a3: &WindowName);
      v3 = this->getLabel(this, a2: v2);
      if ( v3 != nullptr )
      {
        v4 = g_pSoundEmitterSystem->__vftable;
        v5 = va(fmt: "scripts/%s.txt", v3);
        v6 = v4->FindSoundScript(this: g_pSoundEmitterSystem, a2: v5);
        if ( v6 >= 0 && g_pSoundEmitterSystem->IsSoundScriptDirty(this: g_pSoundEmitterSystem, a2: v6) )
          this->setPrefix(this, a2: v2, a3: "* ");
      }
      ++v2;
    }
    while ( v2 < c );
  }
  v7 = mxWidget::w2(this);
  CTabWindow::RecomputeLayout(this, windowWidth: v7, dolayout: true);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040D0C0
// Name: public: COptionsWindow::COptionsWindow(class CSoundBrowser __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsWindow *__thiscall COptionsWindow::COptionsWindow(COptionsWindow *this, CSoundBrowser *browser)
{
  mxCheckBox *v3; // eax
  mxCheckBox *v4; // eax
  mxButton *v5; // eax
  mxButton *v6; // eax
  mxButton *v7; // eax
  mxButton *v8; // eax
  mxButton *v9; // eax
  mxButton *v10; // eax
  mxLabel *v11; // eax

  mxWindow::mxWindow(this, parent: browser, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  this->__vftable = (COptionsWindow_vtbl *)&COptionsWindow::`vftable';
  this->m_pBrowser = browser;
  SceneManager_AddWindowStyle(w: this, addbits: 100663296);
  this->m_szSearchString[0] = 0;
  v3 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxCheckBox::mxCheckBox(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: "CHAN_VOICE only", id: 1000);
  else
    v4 = nullptr;
  this->m_pChanVoiceOnly = v4;
  mxCheckBox::setChecked(this: v4, b: true);
  v5 = (mxButton *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxButton::mxButton(this: v5, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Play", id: 1001);
  else
    v6 = nullptr;
  this->m_pPlay = v6;
  v7 = (mxButton *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v8 = mxButton::mxButton(this: v7, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Stop Sounds", id: 1002);
  else
    v8 = nullptr;
  this->m_pStopSounds = v8;
  v9 = (mxButton *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxButton::mxButton(this: v9, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Search...", id: 1003);
  else
    v10 = nullptr;
  this->m_pSearch = v10;
  v11 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    this->m_pSearchString = mxLabel::mxLabel(this: v11, parent: this, x: 0, y: 0, w: 0, h: 0, label: &WindowName);
  else
    this->m_pSearchString = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040D230
// Name: private: void CSoundBrowser::OnShowInWaveBrowser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnShowInWaveBrowser(CSoundBrowser *this)
{
  int NextSelectedItem; // eax
  CSoundEntry *UserData; // esi
  CWorkspaceManager *WorkspaceManager; // eax
  CWaveBrowser *WaveBrowser; // edi
  CWaveFile *Wave; // eax

  if ( mxListView::getNumSelected(this: this->m_pListView) == 1 )
  {
    NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: -1);
    if ( NextSelectedItem >= 0 )
    {
      UserData = (CSoundEntry *)mxListView::getUserData(this: this->m_pListView, item: NextSelectedItem, column: 0);
      if ( UserData != nullptr )
      {
        WorkspaceManager = GetWorkspaceManager();
        WaveBrowser = CWorkspaceManager::GetWaveBrowser(this: WorkspaceManager);
        if ( WaveBrowser != nullptr && CSoundEntry::GetWaveCount(this: UserData) > 0 )
        {
          Wave = CSoundEntry::GetWave(this: UserData, index: 0);
          if ( Wave != nullptr )
            CWaveBrowser::JumpToItem(this: WaveBrowser, wav: Wave);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D360
// Name: public: void CSoundFilterTab::Init(class CUtlSymbolTable __near &,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundFilterTab::Init(
        CSoundFilterTab *this,
        CUtlSymbolTable *table,
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *scripts)
{
  int m_Size; // ebx
  int i; // edi
  const char *v6; // eax

  this->add(this, a2: "AllSounds");
  this->add(this, a2: "Search results");
  m_Size = scripts->m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v6 = CUtlSymbolTable::String(this: table, id: scripts->m_Memory.m_pMemory[i]);
    this->add(this, a2: v6);
  }
  this->select(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040DAC0
// Name: private: void CSoundBrowser::RemoveAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::RemoveAllSounds(CSoundBrowser *this)
{
  int m_Size; // eax
  int v3; // esi
  CSoundEntry **m_pMemory; // ecx
  CSoundEntry *v5; // edi
  int c; // [esp+8h] [ebp-4h]

  m_Size = this->m_AllSounds.m_Size;
  v3 = 0;
  for ( c = m_Size; v3 < m_Size; ++v3 )
  {
    m_pMemory = this->m_AllSounds.m_Memory.m_pMemory;
    v5 = m_pMemory[v3];
    if ( v5 != nullptr )
    {
      CSoundEntry::~CSoundEntry(this: m_pMemory[v3]);
      free(pMem: v5);
      m_Size = c;
    }
  }
  this->m_AllSounds.m_Size = 0;
  this->m_Scripts.m_Size = 0;
  this->m_CurrentSelection.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E240
// Name: public: virtual void CSoundBrowser::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSoundBrowser::OnDelete(CSoundBrowser *this)
{
  CSoundBrowser::RemoveAllSounds(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040E250
// Name: private: void CSoundBrowser::LoadAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundBrowser::LoadAllSounds(CSoundBrowser *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  int j; // eax
  const char *v5; // edi
  CSoundEntry *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSoundEntry **m_pMemory; // ecx
  int v10; // eax
  CSoundEntry **v11; // edi
  const char *v12; // eax
  int v13; // ecx
  int v14; // eax
  CUtlSymbol *v15; // edx
  int v16; // eax
  int v17; // edi
  CUtlSymbol *v18; // ecx
  int v19; // eax
  CUtlSymbol *v20; // edi
  int v21; // edi
  int (__thiscall *InvalidIndex)(ISoundEmitterSystemBase *); // edx
  int v23; // [esp-4h] [ebp-21Ch]
  char filebase[516]; // [esp+8h] [ebp-210h] BYREF
  CSoundEntry *se; // [esp+20Ch] [ebp-Ch]
  int i; // [esp+210h] [ebp-8h]
  CUtlSymbol script_sym; // [esp+214h] [ebp-4h] BYREF

  CSoundBrowser::RemoveAllSounds(this);
  v3 = g_pSoundEmitterSystem->First(this: g_pSoundEmitterSystem);
  i = v3;
  if ( v3 != g_pSoundEmitterSystem->InvalidIndex(this: g_pSoundEmitterSystem) )
  {
    for ( j = ((int (__thiscall *)(ISoundEmitterSystemBase *, int, int))g_pSoundEmitterSystem->GetSoundName)(
                a1: g_pSoundEmitterSystem,
                a2: v3,
                a3: a2);
          ;
          j = ((int (__thiscall *)(ISoundEmitterSystemBase *, int, int))g_pSoundEmitterSystem->GetSoundName)(
                a1: g_pSoundEmitterSystem,
                a2: i,
                a3: v23) )
    {
      v5 = (const char *)j;
      v6 = (CSoundEntry *)operator new(nSize: 0x21Cu);
      if ( v6 != nullptr )
        se = CSoundEntry::CSoundEntry(this: v6, vcd: nullptr, name: v5);
      else
        se = nullptr;
      m_Size = this->m_AllSounds.m_Size;
      m_nAllocationCount = this->m_AllSounds.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_AllSounds,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_AllSounds.m_Size;
      m_pMemory = this->m_AllSounds.m_Memory.m_pMemory;
      v10 = this->m_AllSounds.m_Size - m_Size - 1;
      this->m_AllSounds.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &this->m_AllSounds.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        *v11 = se;
      v12 = g_pSoundEmitterSystem->GetSourceFileForSound(this: g_pSoundEmitterSystem, a2: i);
      V_FileBase(in: v12, out: filebase, maxlen: 512);
      CUtlSymbolTable::AddString(this: &this->m_ScriptTable, result: &script_sym, pString: filebase);
      v13 = this->m_Scripts.m_Size;
      v14 = 0;
      if ( v13 <= 0 )
        goto LABEL_19;
      v15 = this->m_Scripts.m_Memory.m_pMemory;
      while ( v15->m_Id != script_sym.m_Id )
      {
        ++v14;
        ++v15;
        if ( v14 >= v13 )
          goto LABEL_19;
      }
      if ( v14 == -1 )
      {
LABEL_19:
        v16 = this->m_Scripts.m_Memory.m_nAllocationCount;
        v17 = this->m_Scripts.m_Size;
        if ( v13 + 1 > v16 )
          CUtlMemory<CUtlSymbol,int>::Grow(this: &this->m_Scripts.m_Memory, num: v13 - v16 + 1);
        ++this->m_Scripts.m_Size;
        v18 = this->m_Scripts.m_Memory.m_pMemory;
        v19 = this->m_Scripts.m_Size - v17 - 1;
        this->m_Scripts.m_pElements = v18;
        if ( v19 > 0 )
          _V_memmove(dest: &v18[v17 + 1], src: &v18[v17], count: 2 * v19);
        v20 = &this->m_Scripts.m_Memory.m_pMemory[v17];
        if ( v20 != nullptr )
          v20->m_Id = script_sym.m_Id;
      }
      v23 = i;
      v21 = ((int (__thiscall *)(ISoundEmitterSystemBase *))g_pSoundEmitterSystem->Next)(a1: g_pSoundEmitterSystem);
      InvalidIndex = g_pSoundEmitterSystem->InvalidIndex;
      i = v21;
      if ( v21 == InvalidIndex(this: g_pSoundEmitterSystem) )
        break;
    }
  }
  CSoundFilterTab::Init(this: this->m_pFilter, table: &this->m_ScriptTable, scripts: &this->m_Scripts);
}

//------------------------------------------------------------------------------
// Address: 0x0040E410
// Name: private: void CSoundBrowser::ShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::ShowContextMenu(CSoundBrowser *this)
{
  HWND Handle; // eax
  mxPopupMenu *v3; // eax
  mxPopupMenu *v4; // esi
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF

  CSoundBrowser::BuildSelectionList(this, selected: &this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size > 0 )
  {
    GetCursorPos(lpPoint: &pt);
    Handle = (HWND)mxWidget::getHandle(this);
    ScreenToClient(hWnd: Handle, lpPoint: &pt);
    v3 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v3 != nullptr )
      v4 = mxPopupMenu::mxPopupMenu(this: v3);
    else
      v4 = nullptr;
    if ( this->m_CurrentSelection.m_Size == 1 )
    {
      mxPopupMenu::add(this: v4, item: "&Play", id: 1000);
      mxMenu::addSeparator(this: v4);
    }
    mxPopupMenu::add(this: v4, item: "Refresh sentence data", id: 1005);
    mxPopupMenu::add(this: v4, item: "Add sound entry...", id: 1003);
    if ( this->m_CurrentSelection.m_Size >= 1 )
      mxPopupMenu::add(this: v4, item: "Remove sound(s)", id: 1004);
    mxMenu::addSeparator(this: v4);
    mxPopupMenu::add(this: v4, item: "Show in Wave Browser", id: 1002);
    mxPopupMenu::add(this: v4, item: "&Properties...", id: 1001);
    mxPopupMenu::popup(this: v4, widget: this, x: pt.x, y: pt.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E510
// Name: public: void CSoundBrowser::OnPlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnPlay(CSoundBrowser *this)
{
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *p_m_CurrentSelection; // edi
  CSoundEntry *v3; // ecx

  p_m_CurrentSelection = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(this, selected: &this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size == 1 )
  {
    v3 = *p_m_CurrentSelection->m_Memory.m_pMemory;
    if ( v3 != nullptr )
      CSoundEntry::Play(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E540
// Name: private: void CSoundBrowser::OnSoundProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnSoundProperties(CSoundBrowser *this)
{
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *p_m_CurrentSelection; // edi
  int m_Size; // ecx
  int v4; // ebx
  CSoundEntry *v5; // edi
  int v6; // esi
  CSoundEntry **v7; // eax
  CSoundEntry **m_pMemory; // eax
  CSoundParams params; // [esp+8h] [ebp-ACh] BYREF
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *v10; // [esp+ACh] [ebp-8h]
  int c; // [esp+B0h] [ebp-4h]

  p_m_CurrentSelection = &this->m_CurrentSelection;
  v10 = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(this, selected: &this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size >= 1 )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Sound Properties");
    m_Size = params.items.m_Size;
    v4 = 0;
    c = this->m_CurrentSelection.m_Size;
    if ( c > 0 )
    {
      while ( 1 )
      {
        v5 = p_m_CurrentSelection->m_Memory.m_pMemory[v4];
        if ( v5 != nullptr )
        {
          v6 = m_Size;
          if ( m_Size + 1 > params.items.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&params.items,
              num: m_Size - params.items.m_Memory.m_nAllocationCount + 1);
            m_Size = params.items.m_Size;
          }
          params.items.m_Size = ++m_Size;
          params.items.m_pElements = params.items.m_Memory.m_pMemory;
          if ( m_Size - v6 - 1 > 0 )
          {
            _V_memmove(
              dest: &params.items.m_Memory.m_pMemory[v6 + 1],
              src: &params.items.m_Memory.m_pMemory[v6],
              count: 4 * (m_Size - v6 - 1));
            m_Size = params.items.m_Size;
          }
          v7 = &params.items.m_Memory.m_pMemory[v6];
          if ( v7 != nullptr )
          {
            *v7 = v5;
            m_Size = params.items.m_Size;
          }
        }
        if ( ++v4 >= c )
          break;
        p_m_CurrentSelection = v10;
      }
    }
    if ( m_Size <= 1 )
      SoundProperties(&params);
    else
      SoundProperties_Multiple(&params);
    m_pMemory = params.items.m_Memory.m_pMemory;
    params.items.m_Size = 0;
    if ( params.items.m_Memory.m_nGrowSize >= 0 )
    {
      if ( params.items.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: params.items.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        params.items.m_Memory.m_pMemory = nullptr;
      }
      params.items.m_Memory.m_nAllocationCount = 0;
    }
    params.items.m_pElements = m_pMemory;
    if ( params.items.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    Con_Printf(fmt: "No selection\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E690
// Name: private: void CSoundBrowser::OnAddSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnAddSound(CSoundBrowser *this)
{
  CSoundEntry *v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CSoundEntry **m_pMemory; // ecx
  int v6; // eax
  CSoundEntry **v7; // edi
  ISoundEmitterSystemBase_vtbl *v8; // esi
  int v9; // eax
  int v10; // esi
  CSoundParametersInternal *v11; // ebx
  CWorkspaceManager *WorkspaceManager; // eax
  int v13; // esi
  ISoundEmitterSystemBase *v14; // edi
  SoundFile *SoundNames; // eax
  char *v16; // eax
  CWaveFile *Entry; // eax
  CWorkspaceManager *v18; // eax
  CSoundParams params; // [esp+4h] [ebp-B8h] BYREF
  CSoundParametersInternal *p; // [esp+A8h] [ebp-14h]
  int waveCount; // [esp+ACh] [ebp-10h]
  CSoundEntry *newItem; // [esp+B4h] [ebp-8h]
  CWaveBrowser *wb; // [esp+B8h] [ebp-4h]

  memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
  params.addsound = true;
  V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "New Sound");
  if ( SoundProperties(&params) != 0 )
  {
    if ( params.items.m_Size == 1 )
    {
      v2 = *params.items.m_Memory.m_pMemory;
      m_nAllocationCount = this->m_AllSounds.m_Memory.m_nAllocationCount;
      m_Size = this->m_AllSounds.m_Size;
      newItem = *params.items.m_Memory.m_pMemory;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_AllSounds,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_AllSounds.m_Size;
      m_pMemory = this->m_AllSounds.m_Memory.m_pMemory;
      v6 = this->m_AllSounds.m_Size - m_Size - 1;
      this->m_AllSounds.m_pElements = m_pMemory;
      if ( v6 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
      v7 = &this->m_AllSounds.m_Memory.m_pMemory[m_Size];
      if ( v7 != nullptr )
        *v7 = v2;
      v8 = g_pSoundEmitterSystem->__vftable;
      v9 = v2->GetName(this: v2);
      v10 = v8->GetSoundIndex(this: g_pSoundEmitterSystem, a2: (const char *)v9);
      if ( g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v10) )
      {
        v11 = g_pSoundEmitterSystem->InternalGetParametersForSound(this: g_pSoundEmitterSystem, a2: v10);
        p = v11;
        if ( v11 != nullptr )
        {
          WorkspaceManager = GetWorkspaceManager();
          wb = CWorkspaceManager::GetWaveBrowser(this: WorkspaceManager);
          v13 = 0;
          waveCount = v11->m_nSoundNames;
          if ( waveCount != 0 )
          {
            while ( 1 )
            {
              v14 = g_pSoundEmitterSystem;
              SoundNames = CSoundParametersInternal::GetSoundNames(this: v11);
              v16 = (char *)v14->GetWaveName(this: v14, a2: (CUtlSymbol *)&SoundNames[v13]);
              if ( v16 != nullptr )
              {
                Entry = CWaveBrowser::FindEntry(this: wb, wavname: v16, jump: true);
                if ( Entry != nullptr )
                  CSoundEntry::AddWave(this: newItem, wave: Entry);
              }
              if ( ++v13 >= waveCount )
                break;
              v11 = p;
            }
          }
        }
      }
    }
    v18 = GetWorkspaceManager();
    CWorkspaceManager::RefreshBrowsers(this: v18);
  }
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&params.items);
}

//------------------------------------------------------------------------------
// Address: 0x0040E810
// Name: private: void CSoundBrowser::OnRemoveSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnRemoveSound(CSoundBrowser *this)
{
  int m_Size; // eax
  int v3; // eax
  CSoundEntry *v4; // edi
  ISoundEmitterSystemBase_vtbl *v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  CSoundEntry **m_pMemory; // edx
  int v10; // ecx
  CWorkspaceManager *WorkspaceManager; // eax
  int i; // [esp+4h] [ebp-4h]

  CSoundBrowser::BuildSelectionList(this, selected: &this->m_CurrentSelection);
  m_Size = this->m_CurrentSelection.m_Size;
  if ( m_Size >= 1 )
  {
    v3 = m_Size - 1;
    i = v3;
    if ( v3 >= 0 )
    {
      while ( 1 )
      {
        v4 = this->m_CurrentSelection.m_Memory.m_pMemory[v3];
        v5 = g_pSoundEmitterSystem->__vftable;
        v6 = v4->GetName(this: v4);
        v5->RemoveSound(this: g_pSoundEmitterSystem, a2: (const char *)v6);
        v7 = this->m_AllSounds.m_Size;
        v8 = 0;
        if ( v7 > 0 )
        {
          m_pMemory = this->m_AllSounds.m_Memory.m_pMemory;
          while ( *m_pMemory != v4 )
          {
            ++v8;
            ++m_pMemory;
            if ( v8 >= v7 )
              goto LABEL_15;
          }
          if ( v8 != -1 )
          {
            v10 = v7 - v8 - 1;
            if ( v10 > 0 )
              _V_memmove(
                dest: &this->m_AllSounds.m_Memory.m_pMemory[v8],
                src: &this->m_AllSounds.m_Memory.m_pMemory[v8 + 1],
                count: 4 * v10);
            --this->m_AllSounds.m_Size;
          }
        }
LABEL_15:
        CSoundEntry::~CSoundEntry(this: v4);
        free(pMem: v4);
        if ( --i < 0 )
          break;
        v3 = i;
      }
    }
    WorkspaceManager = GetWorkspaceManager();
    CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
  }
  else
  {
    Con_Printf(fmt: "No selection\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E8E0
// Name: private: void CSoundBrowser::OnGetSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnGetSentence(CSoundBrowser *this)
{
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *p_m_CurrentSelection; // esi
  int m_Size; // edi
  int v4; // edi
  CSoundEntry *v5; // ebx
  int v6; // esi
  CWaveFile *Wave; // edi
  CWorkspaceManager *WorkspaceManager; // eax
  int c; // [esp+8h] [ebp-Ch]
  CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *v10; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  p_m_CurrentSelection = &this->m_CurrentSelection;
  v10 = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(this, selected: &this->m_CurrentSelection);
  m_Size = this->m_CurrentSelection.m_Size;
  if ( m_Size >= 1 )
  {
    v4 = m_Size - 1;
    i = v4;
    if ( v4 >= 0 )
    {
      while ( 1 )
      {
        v5 = p_m_CurrentSelection->m_Memory.m_pMemory[v4];
        v6 = 0;
        c = CSoundEntry::GetWaveCount(this: v5);
        if ( c > 0 )
        {
          do
          {
            Wave = CSoundEntry::GetWave(this: v5, index: v6);
            if ( !CWaveFile::HasLoadedSentenceInfo(this: Wave) )
              CWaveFile::EnsureSentence(this: Wave);
            ++v6;
          }
          while ( v6 < c );
          v4 = i;
        }
        i = --v4;
        if ( v4 < 0 )
          break;
        p_m_CurrentSelection = v10;
      }
    }
    WorkspaceManager = GetWorkspaceManager();
    CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
  }
  else
  {
    Con_Printf(fmt: "No selection\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E980
// Name: private: void CSoundBrowser::PopulateTree(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::PopulateTree(CSoundBrowser *this, bool voiceonly, const char *scriptonly)
{
  COptionsWindow *m_pOptions; // eax
  int v5; // eax
  const char *v6; // esi
  CSoundParametersInternal *SoundParameters; // eax
  const char *ScriptFile; // eax
  int WaveCount; // ebx
  int v10; // esi
  CWaveFile *Wave; // eax
  const char *FileName; // eax
  int v13; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *m_pMemory; // ecx
  int v15; // edx
  unsigned int v16; // esi
  int v17; // edx
  CSoundEntry **p_m_Data; // esi
  int v19; // esi
  CSoundEntry *m_Data; // ebx
  CSoundParametersInternal *v21; // ebx
  int v22; // esi
  int v23; // eax
  const char *v24; // eax
  CUtlSymbol *m_pSoundNames; // eax
  const char *v26; // eax
  const char *SentenceText; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  const char *v31; // eax
  int v32; // eax
  const char *v33; // eax
  char *v34; // [esp-8h] [ebp-A50h]
  int v35; // [esp+0h] [ebp-A48h]
  wchar_t buf[1024]; // [esp+Ch] [ebp-A3Ch] BYREF
  char filebase[512]; // [esp+80Ch] [ebp-23Ch] BYREF
  int c; // [esp+A0Ch] [ebp-3Ch]
  CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > m_Sorted; // [esp+A10h] [ebp-38h] BYREF
  int parent; // [esp+A34h] [ebp-14h] BYREF
  const char *texttofind; // [esp+A38h] [ebp-10h]
  int i; // [esp+A3Ch] [ebp-Ch]
  CSoundEntry *se; // [esp+A40h] [ebp-8h] BYREF
  bool textsearch; // [esp+A46h] [ebp-2h]
  bool leftchild; // [esp+A47h] [ebp-1h] BYREF
  CSoundEntry *voiceonlya; // [esp+A50h] [ebp+8h]
  const char *name; // [esp+A54h] [ebp+Ch]

  m_Sorted.m_LessFunc = NameLessFunc;
  memset(&m_Sorted.m_Elements, 0, sizeof(m_Sorted.m_Elements));
  m_Sorted.m_Root = -1;
  m_Sorted.m_NumElements = 0;
  m_Sorted.m_FirstFree = -1;
  m_Sorted.m_LastAlloc.index = -1;
  m_Sorted.m_pElements = nullptr;
  textsearch = false;
  texttofind = nullptr;
  if ( scriptonly != nullptr )
  {
    if ( _V_stricmp(s1: scriptonly, s2: "AllSounds") != 0 )
    {
      if ( _V_stricmp(s1: scriptonly, s2: "Search results") != 0 )
        goto LABEL_6;
      m_pOptions = this->m_pOptions;
      textsearch = true;
      texttofind = m_pOptions->m_szSearchString;
    }
    scriptonly = nullptr;
  }
LABEL_6:
  v5 = 0;
  c = this->m_AllSounds.m_Size;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      se = this->m_AllSounds.m_Memory.m_pMemory[v5];
      v6 = (const char *)se->GetName(this: se);
      SoundParameters = CSoundEntry::GetSoundParameters(this: se);
      if ( SoundParameters != nullptr && (!voiceonly || SoundParameters->channel == 2) )
      {
        if ( scriptonly == nullptr
          || (ScriptFile = CSoundEntry::GetScriptFile(this: se), _V_stricmp(s1: scriptonly, s2: ScriptFile) == 0) )
        {
          if ( !textsearch || texttofind == nullptr || V_stristr(pStr: v6, pSearch: texttofind) != nullptr )
            goto LABEL_21;
          WaveCount = CSoundEntry::GetWaveCount(this: se);
          v10 = 0;
          if ( WaveCount > 0 )
            break;
        }
      }
LABEL_28:
      v5 = i + 1;
      i = v5;
      if ( v5 >= c )
        goto LABEL_29;
    }
    while ( 1 )
    {
      Wave = CSoundEntry::GetWave(this: se, index: v10);
      if ( Wave != nullptr )
      {
        FileName = CWaveFile::GetFileName(this: Wave);
        if ( FileName != nullptr && V_stristr(pStr: FileName, pSearch: texttofind) != nullptr )
          break;
      }
      if ( ++v10 >= WaveCount )
        goto LABEL_28;
    }
LABEL_21:
    parent = -1;
    leftchild = false;
    CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::FindInsertionPosition(
      this: &m_Sorted,
      insert: &se,
      &parent,
      &leftchild);
    v13 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
            this: &m_Sorted,
            a2: (const char *)this);
    m_pMemory = m_Sorted.m_Elements.m_pMemory;
    v15 = parent;
    v16 = v13;
    m_Sorted.m_Elements.m_pMemory[v16].m_Parent = parent;
    m_pMemory[v16].m_Right = -1;
    m_pMemory[v16].m_Left = -1;
    m_pMemory[v16].m_Tag = 0;
    if ( v15 == -1 )
    {
      m_Sorted.m_Root = v13;
    }
    else
    {
      v17 = v15;
      if ( leftchild )
        m_pMemory[v17].m_Left = v13;
      else
        m_pMemory[v17].m_Right = v13;
    }
    CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::InsertRebalance(
      this: &m_Sorted,
      elem: v13);
    ++m_Sorted.m_NumElements;
    p_m_Data = &m_Sorted.m_Elements.m_pMemory[v16].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = se;
    goto LABEL_28;
  }
LABEL_29:
  mxListView::removeAll(this: this->m_pListView);
  mxListView::setDrawingEnabled(this: this->m_pListView, draw: false);
  v19 = CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::FirstInorder(this: &m_Sorted);
  i = v19;
  if ( v19 != -1 )
  {
    while ( 1 )
    {
      m_Data = m_Sorted.m_Elements.m_pMemory[v19].m_Data;
      voiceonlya = m_Data;
      name = (const char *)m_Data->GetName(this: m_Data);
      v21 = CSoundEntry::GetSoundParameters(this: m_Data);
      if ( v21 != nullptr )
      {
        v22 = mxListView::add(this: this->m_pListView, item: name);
        mxListView::setUserData(this: this->m_pListView, item: v22, column: 0, userData: voiceonlya);
        v23 = voiceonlya->GetIconIndex(this: voiceonlya);
        mxListView::setImage(this: this->m_pListView, item: v22, column: 0, imagenormal: v23);
        if ( v21->m_nSoundNames != 0 )
        {
          if ( v21->m_nSoundNames <= 1u )
            v24 = &WindowName;
          else
            v24 = va(fmt: "%i", v21->m_nSoundNames);
          mxListView::setLabel(this: this->m_pListView, item: v22, column: 1, label: v24);
          m_pSoundNames = (CUtlSymbol *)v21;
          if ( v21->m_nSoundNames != 1 )
            m_pSoundNames = (CUtlSymbol *)v21->m_pSoundNames;
          v26 = g_pSoundEmitterSystem->GetWaveName(this: g_pSoundEmitterSystem, a2: m_pSoundNames);
          mxListView::setLabel(this: this->m_pListView, item: v22, column: 2, label: v26);
        }
        SentenceText = CSoundEntry::GetSentenceText(this: voiceonlya, wavindex: 0);
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 3, label: SentenceText);
        v28 = CSoundParametersInternal::ChannelToString(this: v21);
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 4, label: v28);
        v29 = CSoundParametersInternal::VolumeToString(this: v21);
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 5, label: v29);
        v30 = CSoundParametersInternal::SoundLevelToString(this: v21);
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 6, label: v30);
        v31 = CSoundParametersInternal::PitchToString(this: v21);
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 7, label: v31);
        CSoundEntry::GetCCText(this: voiceonlya, out: buf, maxchars: 1024);
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 9, label: buf);
        v32 = ((int (__thiscall *)(ISoundEmitterSystemBase *, const char *, int))g_pSoundEmitterSystem->GetSoundIndex)(
                a1: g_pSoundEmitterSystem,
                a2: name,
                a3: v35);
        v35 = 512;
        v34 = (char *)v32;
        v33 = (const char *)((int (__thiscall *)(ISoundEmitterSystemBase *))g_pSoundEmitterSystem->GetSourceFileForSound)(a1: g_pSoundEmitterSystem);
        V_FileBase(in: v33, out: v34, maxlen: (int)filebase);
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 8, label: filebase);
        v19 = i;
      }
      i = CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::NextInorder(
            this: &m_Sorted,
            i: v19);
      if ( i == -1 )
        break;
      v19 = i;
    }
  }
  mxListView::setDrawingEnabled(this: this->m_pListView, draw: true);
  CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RemoveAll(this: &m_Sorted);
  if ( m_Sorted.m_Elements.m_nGrowSize >= 0 && m_Sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Sorted.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040ED70
// Name: public: void CSoundBrowser::RepopulateTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::RepopulateTree(CSoundBrowser *this)
{
  int v2; // eax
  const char *v3; // eax
  bool voiceonly; // [esp+4h] [ebp-4h]

  voiceonly = mxCheckBox::isChecked(this: this->m_pOptions->m_pChanVoiceOnly);
  v2 = this->m_pFilter->getSelectedIndex(this: this->m_pFilter);
  if ( v2 > 0 )
  {
    v3 = this->m_pFilter->getLabel(this: this->m_pFilter, a2: v2);
    CSoundBrowser::PopulateTree(this, voiceonly, scriptonly: v3);
  }
  else
  {
    CSoundBrowser::PopulateTree(this, voiceonly, scriptonly: nullptr);
  }
  CSoundFilterTab::UpdatePrefixes(this: this->m_pFilter);
}

//------------------------------------------------------------------------------
// Address: 0x0040EDE0
// Name: public: void CSoundBrowser::JumpToItem(class CSoundEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::JumpToItem(CSoundBrowser *this, CSoundEntry *se)
{
  const char *ScriptFile; // esi
  int v4; // edi
  int (__thiscall ***UserData)(_DWORD); // esi
  const char *v6; // eax
  const char *v7; // [esp-4h] [ebp-14h]
  bool voiceonly; // [esp+Ch] [ebp-4h]
  int voiceonlya; // [esp+Ch] [ebp-4h]

  ScriptFile = CSoundEntry::GetScriptFile(this: se);
  voiceonly = mxCheckBox::isChecked(this: this->m_pOptions->m_pChanVoiceOnly);
  if ( ScriptFile != nullptr && *ScriptFile != 0 )
    CSoundBrowser::PopulateTree(this, voiceonly, scriptonly: ScriptFile);
  else
    CSoundBrowser::PopulateTree(this, voiceonly, scriptonly: nullptr);
  v4 = 0;
  voiceonlya = mxListView::getItemCount(this: this->m_pListView);
  if ( voiceonlya > 0 )
  {
    while ( 1 )
    {
      UserData = (int (__thiscall ***)(_DWORD))mxListView::getUserData(this: this->m_pListView, item: v4, column: 0);
      v7 = (const char *)se->GetName(this: se);
      v6 = (const char *)(**UserData)(a1: UserData);
      if ( _V_stricmp(s1: v6, s2: v7) == 0 )
        break;
      if ( ++v4 >= voiceonlya )
        return;
    }
    if ( v4 < voiceonlya )
      mxListView::scrollToItem(this: this->m_pListView, item: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EE90
// Name: public: void COptionsWindow::OnSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsWindow::OnSearch(COptionsWindow *this)
{
  const char *v2; // eax
  CSoundBrowser *m_pBrowser; // esi
  CInputParams params; // [esp+8h] [ebp-58Ch] BYREF

  memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
  V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Search");
  _V_strcpy(dest: params.m_szPrompt, src: "Find:");
  _V_strcpy(dest: params.m_szInputText, src: this->m_szSearchString);
  if ( InputProperties(&params) != 0 )
  {
    _V_strcpy(dest: this->m_szSearchString, src: params.m_szInputText);
    v2 = va(fmt: "Search:  '%s'", this->m_szSearchString);
    mxWidget::setLabel(this: this->m_pSearchString, format: v2);
    m_pBrowser = this->m_pBrowser;
    m_pBrowser->m_pFilter->select(this: m_pBrowser->m_pFilter, a2: 1);
    CSoundBrowser::RepopulateTree(this: m_pBrowser);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EF50
// Name: public: CSoundBrowser::CSoundBrowser(class mxWindow __near *,class CWorkspaceManager __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSoundBrowser *__thiscall CSoundBrowser::CSoundBrowser(
        CSoundBrowser *this,
        mxWindow *parent,
        CWorkspaceManager *manager,
        int id)
{
  CSoundList *v5; // eax
  CSoundList *v6; // eax
  CTabWindow *v7; // eax
  CSoundFilterTab *v8; // edi
  COptionsWindow *v9; // eax
  COptionsWindow *v10; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  _IMAGELIST *ImageList; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: "Sound Browser", style: id);
  this->__vftable = (CSoundBrowser_vtbl *)&CSoundBrowser::`vftable';
  this->m_AllSounds.m_Memory.m_pMemory = nullptr;
  this->m_AllSounds.m_Memory.m_nAllocationCount = 0;
  this->m_AllSounds.m_Memory.m_nGrowSize = 0;
  this->m_AllSounds.m_Size = 0;
  this->m_AllSounds.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_ScriptTable, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_Scripts.m_Memory.m_pMemory = nullptr;
  this->m_Scripts.m_Memory.m_nAllocationCount = 0;
  this->m_Scripts.m_Memory.m_nGrowSize = 0;
  this->m_Scripts.m_Size = 0;
  this->m_Scripts.m_pElements = nullptr;
  this->m_CurrentSelection.m_Memory.m_pMemory = nullptr;
  this->m_CurrentSelection.m_Memory.m_nAllocationCount = 0;
  this->m_CurrentSelection.m_Memory.m_nGrowSize = 0;
  this->m_CurrentSelection.m_Size = 0;
  this->m_CurrentSelection.m_pElements = nullptr;
  this->m_pManager = manager;
  SceneManager_MakeToolWindow(w: this, smallcaption: false);
  v5 = (CSoundList *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = CSoundList::CSoundList(this: v5, parent: this, id: 101);
  else
    v6 = nullptr;
  this->m_pListView = v6;
  v7 = (CTabWindow *)operator new(nSize: 0x54u);
  v8 = (CSoundFilterTab *)v7;
  if ( v7 != nullptr )
  {
    CTabWindow::CTabWindow(this: v7, parent: this, x: 0, y: 0, w: 0, h: 0, id: 102, style: 0);
    v8->__vftable = (CSoundFilterTab_vtbl *)&CSoundFilterTab::`vftable';
    CTabWindow::SetInverted(this: v8, invert: true);
    CTabWindow::SetRowHeight(this: v8, rowheight: 20);
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pFilter = v8;
  v9 = (COptionsWindow *)operator new(nSize: 0x124u);
  if ( v9 != nullptr )
    v10 = COptionsWindow::COptionsWindow(this: v9, browser: this);
  else
    v10 = nullptr;
  this->m_pOptions = v10;
  WorkspaceManager = GetWorkspaceManager();
  ImageList = CWorkspaceManager::CreateImageList(this: WorkspaceManager);
  mxListView::setImageList(this: this->m_pListView, himagelist: ImageList);
  CSoundBrowser::LoadAllSounds(this, a2: 0);
  this->m_pFilter->select(this: this->m_pFilter, a2: 0);
  CSoundBrowser::RepopulateTree(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F0D0
// Name: public: virtual int CSoundBrowser::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundBrowser::handleEvent(CSoundBrowser *this, mxEvent *event)
{
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  int result; // eax
  int v7; // eax
  int BestHeight; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  int action; // eax
  int v14; // eax
  int flags; // eax
  int NextSelectedItem; // eax
  CSoundEntry *UserData; // eax
  CSoundEntry *v18; // esi
  CWorkspaceManager *v19; // eax
  CWaveBrowser *WaveBrowser; // edi
  CWaveFile *Wave; // eax
  int v22; // [esp-8h] [ebp-14h]
  int v23; // [esp-4h] [ebp-10h]

  v3 = event->event;
  v4 = 0;
  if ( v3 != 0 )
  {
    v5 = v3 - 1;
    if ( v5 == 0 )
    {
      v7 = mxWidget::w2(this);
      BestHeight = CTabWindow::GetBestHeight(this: this->m_pFilter, width: v7);
      v9 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pOptions, x: 0, y: 0, w: v9, h: 20);
      v23 = -20 - BestHeight + mxWidget::h2(this);
      v10 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pListView, x: 0, y: 20, w: v10, h: v23);
      v22 = mxWidget::w2(this);
      v11 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pFilter, x: 0, y: v11 - BestHeight, w: v22, h: BestHeight);
      WorkspaceManager = GetWorkspaceManager();
      CWorkspaceManager::SetWorkspaceDirty(this: WorkspaceManager);
      return 1;
    }
    if ( v5 == 18 )
      return 1;
    return v4;
  }
  action = event->action;
  v4 = 1;
  if ( action <= 1000 )
  {
    if ( action == 1000 )
    {
      CSoundBrowser::OnPlay(this);
      return 1;
    }
    v14 = action - 101;
    if ( v14 != 0 )
    {
      if ( v14 == 1 )
      {
        CSoundBrowser::RepopulateTree(this);
        return 1;
      }
      return 0;
    }
    else
    {
      flags = event->flags;
      if ( flags == 1 )
      {
        CSoundBrowser::ShowContextMenu(this);
        return 1;
      }
      if ( flags == 2 && mxListView::getNumSelected(this: this->m_pListView) == 1 )
      {
        NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: -1);
        if ( NextSelectedItem >= 0 )
        {
          UserData = (CSoundEntry *)mxListView::getUserData(this: this->m_pListView, item: NextSelectedItem, column: 0);
          v18 = UserData;
          if ( UserData != nullptr )
          {
            CSoundEntry::Play(this: UserData);
            v19 = GetWorkspaceManager();
            WaveBrowser = CWorkspaceManager::GetWaveBrowser(this: v19);
            if ( WaveBrowser != nullptr && CSoundEntry::GetWaveCount(this: v18) > 0 )
            {
              Wave = CSoundEntry::GetWave(this: v18, index: 0);
              if ( Wave != nullptr )
              {
                CWaveBrowser::JumpToItem(this: WaveBrowser, wav: Wave);
                return 1;
              }
            }
          }
        }
      }
    }
    return v4;
  }
  switch ( action )
  {
    case 1001:
      CSoundBrowser::OnSoundProperties(this);
      result = 1;
      break;
    case 1002:
      CSoundBrowser::OnShowInWaveBrowser(this);
      result = 1;
      break;
    case 1003:
      CSoundBrowser::OnAddSound(this);
      result = 1;
      break;
    case 1004:
      CSoundBrowser::OnRemoveSound(this);
      result = 1;
      break;
    case 1005:
      CSoundBrowser::OnGetSentence(this);
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F300
// Name: public: virtual int COptionsWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsWindow::handleEvent(COptionsWindow *this, mxEvent *event)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int result; // eax

  v3 = event->event;
  v4 = 0;
  if ( v3 != 0 )
  {
    if ( v3 == 1 )
    {
      v5 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pPlay, x: 1, y: 1, w: 120, h: v5 - 2);
      v6 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pStopSounds, x: 131, y: 1, w: 120, h: v6 - 2);
      v7 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pChanVoiceOnly, x: 261, y: 1, w: 120, h: v7 - 2);
      v8 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pSearch, x: 391, y: 1, w: 120, h: v8 - 2);
      v9 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pSearchString, x: 521, y: 2, w: 240, h: v9 - 4);
      return 1;
    }
    else
    {
      return v4;
    }
  }
  else
  {
    switch ( event->action )
    {
      case 0x3E8:
        CSoundBrowser::RepopulateTree(this: this->m_pBrowser);
        result = 1;
        break;
      case 0x3E9:
        CSoundBrowser::OnPlay(this: this->m_pBrowser);
        result = 1;
        break;
      case 0x3EA:
        sound->StopAll(this: sound);
        result = 1;
        break;
      case 0x3EB:
        v4 = 1;
        COptionsWindow::OnSearch(this);
        return v4;
      default:
        return v4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004175B0
// Name: public: void CSoundBrowser::BuildSelectionList(class CUtlVector<class CSoundEntry __near *,class CUtlMemory<class CSoundEntry __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::BuildSelectionList(CSoundBrowser *this, CSoundEntry *selected)
{
  int v3; // ebx
  int NextSelectedItem; // eax
  int channel; // edi
  int v6; // eax
  CSoundEntry **v7; // ecx
  int v8; // eax
  CSoundEntry **v9; // eax
  CSoundEntry *se; // [esp+18h] [ebp+8h]

  selected->m_Params.channel = 0;
  v3 = -1;
  while ( 1 )
  {
    NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: v3);
    v3 = NextSelectedItem;
    if ( NextSelectedItem == -1 )
      break;
    se = (CSoundEntry *)mxListView::getUserData(this: this->m_pListView, item: NextSelectedItem, column: 0);
    if ( se != nullptr )
    {
      channel = selected->m_Params.channel;
      v6 = *(_DWORD *)&selected->m_bExpanded;
      if ( channel + 1 > v6 )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)selected,
          num: channel - v6 + 1);
      ++selected->m_Params.channel;
      v7 = (CSoundEntry **)selected->__vftable;
      v8 = selected->m_Params.channel - channel - 1;
      LODWORD(selected->m_Params.volume) = selected->__vftable;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[channel + 1], src: &v7[channel], count: 4 * v8);
      v9 = (CSoundEntry **)(&selected->GetName + channel);
      if ( v9 != nullptr )
        *v9 = se;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FFA0
// Name: public: virtual bool mxWindow::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall mxWindow::PaintBackground(ConCommandBase *this)
{
  return 1;
}
