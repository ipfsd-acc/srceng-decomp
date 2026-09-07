// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_speak.cpp
// Functions: 13
// ============================================================

#include "utils\hlfaceposer\eventproperties_speak.h"

//------------------------------------------------------------------------------
// Address: 0x00444200
// Name: public: virtual void CEventPropertiesSpeakDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::SetTitle(CEventPropertiesSpeakDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(this, params: &g_Params_18, eventname: "Speak", desc: "Speak Sound");
}

//------------------------------------------------------------------------------
// Address: 0x00444220
// Name: public: virtual void CEventPropertiesSpeakDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::InitDialog(CEventPropertiesSpeakDialog *this, HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_18, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_18);
  this->InitControlData(this, a2: &g_Params_18);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_18);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00444290
// Name: private: void CEventPropertiesSpeakDialog::PopulateVolumeLevels(struct HWND__ __near *,class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::PopulateVolumeLevels(
        CEventPropertiesSpeakDialog *this,
        HWND control,
        CEventParams *params)
{
  int v4; // ebx
  CSoundParametersInternal *v5; // eax
  char *v6; // eax
  const char *v7; // esi
  bool enabled_3; // [esp+17h] [ebp+Bh]

  SendMessageA(hWnd: control, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"VOL_NORM");
  SendMessageA(hWnd: control, Msg: 0xCu, wParam: 0, lParam: (LPARAM)"VOL_NORM");
  enabled_3 = false;
  if ( V_stristr(pStr: params->m_szParameters, pSearch: ".wav") == nullptr )
  {
    v4 = soundemitter->GetSoundIndex(this: soundemitter, a2: params->m_szParameters);
    if ( v4 >= 0 )
    {
      v5 = soundemitter->InternalGetParametersForSound(this: soundemitter, a2: v4);
      if ( v5 != nullptr )
      {
        v6 = CSoundParametersInternal::VolumeToString(this: v5);
        SendMessageA(hWnd: control, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v6);
        v7 = soundemitter->GetSourceFileForSound(this: soundemitter, a2: v4);
        if ( v7 != nullptr && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v7, a3: nullptr) )
          enabled_3 = filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v7, a3: nullptr);
      }
    }
  }
  EnableWindow(hWnd: control, bEnable: enabled_3);
}

//------------------------------------------------------------------------------
// Address: 0x00444380
// Name: private: void CEventPropertiesSpeakDialog::OnCheckChangedVolumeLevel(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::OnCheckChangedVolumeLevel(
        CEventPropertiesSpeakDialog *this,
        CEventParams *params)
{
  char *m_szParameters; // esi
  int v4; // esi
  CSoundParametersInternal *v5; // ebx
  const char *v6; // esi
  char newvolumelevel[256]; // [esp+0h] [ebp-12Ch] BYREF
  CSoundParametersInternal newparams; // [esp+100h] [ebp-2Ch] BYREF
  HWND__ *control; // [esp+128h] [ebp-4h]
  CEventParams *paramsa; // [esp+134h] [ebp+8h]

  control = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
  if ( IsWindowEnabled(hWnd: control) )
  {
    m_szParameters = params->m_szParameters;
    paramsa = (CEventParams *)params->m_szParameters;
    if ( V_stristr(pStr: paramsa->m_szDialogTitle, pSearch: ".wav") == nullptr )
    {
      v4 = soundemitter->GetSoundIndex(this: soundemitter, a2: m_szParameters);
      if ( v4 >= 0 )
      {
        v5 = soundemitter->InternalGetParametersForSound(this: soundemitter, a2: v4);
        if ( params != nullptr )
        {
          v6 = soundemitter->GetSourceFileForSound(this: soundemitter, a2: v4);
          if ( v6 != nullptr
            && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v6, a3: nullptr)
            && filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v6, a3: nullptr) )
          {
            CSoundParametersInternal::CSoundParametersInternal(this: &newparams);
            CSoundParametersInternal::CopyFrom(this: &newparams, src: v5);
            SendMessageA(hWnd: control, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)newvolumelevel);
            CSoundParametersInternal::VolumeFromString(this: &newparams, sz: newvolumelevel);
            if ( CSoundParametersInternal::operator==(this: &newparams, other: v5) == 0 )
              soundemitter->UpdateSoundParameters(this: soundemitter, a2: (const char *)paramsa, a3: &newparams);
            CSoundParametersInternal::~CSoundParametersInternal(this: &newparams);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004444C0
// Name: private: void CEventPropertiesSpeakDialog::OnSoundSelected(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::OnSoundSelected(CEventPropertiesSpeakDialog *this, HWND__ *params)
{
  HWND DlgItem; // eax
  HWND v4; // eax
  HWND v5; // edi
  int v6; // esi
  const char *v7; // eax
  int v8; // eax
  CUtlSymbol *v9; // eax
  const char *v10; // eax
  int v11; // eax
  LPARAM v12; // [esp-4h] [ebp-18h]
  LPARAM v13; // [esp-4h] [ebp-18h]
  HWND__ *wavename; // [esp+Ch] [ebp-8h]

  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
  CEventPropertiesSpeakDialog::PopulateVolumeLevels(this, control: DlgItem, (CEventParams *)params);
  v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1061);
  SendMessageA(hWnd: v4, Msg: 0xCu, wParam: 0, lParam: (LPARAM)(params + 100));
  v5 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1070);
  wavename = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1069);
  SendMessageA(hWnd: v5, Msg: 0xCu, wParam: 1u, lParam: (LPARAM)defaultValue);
  SendMessageA(hWnd: wavename, Msg: 0xCu, wParam: 1u, lParam: (LPARAM)defaultValue);
  v6 = soundemitter->GetSoundIndex(this: soundemitter, a2: (const char *)(params + 100));
  if ( v6 >= 0 )
  {
    v7 = soundemitter->GetSourceFileForSound(this: soundemitter, a2: v6);
    if ( v7 != nullptr && *v7 != 0 )
    {
      v12 = (LPARAM)v7;
      v8 = _V_strlen(str: v7);
      SendMessageA(hWnd: v5, Msg: 0xCu, wParam: v8 + 1, lParam: v12);
      v9 = (CUtlSymbol *)soundemitter->InternalGetParametersForSound(this: soundemitter, a2: v6);
      if ( v9 != nullptr )
      {
        if ( v9[4].m_Id != 1 )
          v9 = *(CUtlSymbol **)&v9->m_Id;
        v10 = soundemitter->GetWaveName(this: soundemitter, a2: v9);
        if ( v10 != nullptr && *v10 != 0 )
        {
          v13 = (LPARAM)v10;
          v11 = _V_strlen(str: v10);
          SendMessageA(hWnd: wavename, Msg: 0xCu, wParam: v11 + 1, lParam: v13);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004445E0
// Name: private: void CEventPropertiesSpeakDialog::PopulateFilterList(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::PopulateFilterList(CEventPropertiesSpeakDialog *this, bool resetCurrent)
{
  HWND DlgItem; // ebx
  int m_Size; // eax
  int v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // esi
  unsigned __int16 v9; // ax
  unsigned __int16 v10; // ax
  char oldf[256]; // [esp+Ch] [ebp-104h] BYREF
  int c; // [esp+10Ch] [ebp-4h]

  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1068);
  SendMessageA(hWnd: DlgItem, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)oldf);
  SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
  m_Size = this->m_FilterHistory.m_Size;
  c = m_Size;
  if ( m_Size != 0 )
  {
    v5 = 0;
    if ( m_Size > 0 )
    {
      do
      {
        v6 = CUtlSymbolTable::String(this: &this->m_Symbols, id: this->m_FilterHistory.m_Memory.m_pMemory[v5]);
        SendMessageA(hWnd: DlgItem, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v6);
        ++v5;
      }
      while ( v5 < c );
    }
    v7 = CUtlSymbolTable::String(this: &this->m_Symbols, id: (CUtlSymbol)this->m_FilterHistory.m_Memory.m_pMemory->m_Id);
    v8 = v7;
    if ( resetCurrent && v7 != nullptr )
    {
      SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v7);
      v9 = _V_strlen(str: v8);
      SendMessageA(hWnd: DlgItem, Msg: 0x142u, wParam: 0, lParam: v9 | 0xFFFF0000);
    }
    else
    {
      SendMessageA(hWnd: DlgItem, Msg: 0xCu, wParam: 0, lParam: (LPARAM)oldf);
      v10 = _V_strlen(str: oldf);
      SendMessageA(hWnd: DlgItem, Msg: 0x142u, wParam: 0, lParam: v10 | 0xFFFF0000);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444770
// Name: private: void CEventPropertiesSpeakDialog::PopulateSoundList(char const __near *,struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::PopulateSoundList(
        CEventPropertiesSpeakDialog *this,
        const char *current,
        HWND__ *wnd)
{
  int (__thiscall *GetSoundCount)(ISoundEmitterSystemBase *); // edx
  const char *v4; // eax
  int v5; // eax
  UtlRBTreeNode_t<char const *,int> *m_pMemory; // ecx
  int v7; // edx
  unsigned int v8; // esi
  int v9; // edx
  const char **p_m_Data; // esi
  HWND v11; // esi
  int v12; // edi
  const char *m_Data; // esi
  CSoundParameters params; // [esp+Ch] [ebp-F0h] BYREF
  CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > m_SortedNames; // [esp+C0h] [ebp-3Ch] BYREF
  CEventPropertiesSpeakDialog *v16; // [esp+E4h] [ebp-18h]
  int temp; // [esp+E8h] [ebp-14h]
  int i; // [esp+ECh] [ebp-10h]
  const char *name; // [esp+F0h] [ebp-Ch] BYREF
  int selectslot; // [esp+F4h] [ebp-8h] BYREF
  bool add; // [esp+FBh] [ebp-1h] BYREF

  v16 = this;
  GetSoundCount = soundemitter->GetSoundCount;
  m_SortedNames.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))NameLessFunc;
  memset(&m_SortedNames.m_Elements, 0, sizeof(m_SortedNames.m_Elements));
  m_SortedNames.m_Root = -1;
  m_SortedNames.m_NumElements = 0;
  m_SortedNames.m_FirstFree = -1;
  m_SortedNames.m_LastAlloc.index = -1;
  m_SortedNames.m_pElements = nullptr;
  temp = GetSoundCount(this: soundemitter);
  for ( i = 0; i < temp; ++i )
  {
    v4 = soundemitter->GetSoundName(this: soundemitter, a2: i);
    name = v4;
    if ( v4 != nullptr && *v4 != 0 )
    {
      add = true;
      if ( !v16->m_bShowAll )
      {
        params.pitch = 100;
        params.pitchlow = 100;
        params.pitchhigh = 100;
        params.channel = 0;
        params.volume = 1.0;
        params.soundlevel = SNDLVL_NORM;
        params.soundname[0] = 0;
        params.play_to_owner_only = false;
        params.count = 0;
        params.delay_msec = 0;
        params.m_nSoundEntryVersion = 1;
        params.m_hSoundScriptHandle = -1;
        params.m_pOperatorsKV = nullptr;
        params.m_nRandomSeed = -1;
        if ( soundemitter->GetParametersForSound(this: soundemitter, a2: v4, a3: &params, a4: GENDER_NONE, a5: false)
          && params.channel != 2 )
        {
          add = false;
        }
        v4 = name;
      }
      if ( (v16->m_szLastFilter[0] == 0 || V_stristr(pStr: v4, pSearch: v16->m_szLastFilter) != nullptr) && add )
      {
        selectslot = -1;
        add = false;
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
          this: &m_SortedNames,
          insert: &name,
          parent: &selectslot,
          leftchild: &add);
        v5 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
               this: &m_SortedNames,
               a2: (const char *)0x64);
        m_pMemory = m_SortedNames.m_Elements.m_pMemory;
        v7 = selectslot;
        v8 = v5;
        m_SortedNames.m_Elements.m_pMemory[v8].m_Parent = selectslot;
        m_pMemory[v8].m_Right = -1;
        m_pMemory[v8].m_Left = -1;
        m_pMemory[v8].m_Tag = 0;
        if ( v7 == -1 )
        {
          m_SortedNames.m_Root = v5;
        }
        else
        {
          v9 = v7;
          if ( add )
            m_pMemory[v9].m_Left = v5;
          else
            m_pMemory[v9].m_Right = v5;
        }
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
          this: &m_SortedNames,
          elem: v5);
        ++m_SortedNames.m_NumElements;
        p_m_Data = &m_SortedNames.m_Elements.m_pMemory[v8].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = name;
      }
    }
  }
  v11 = wnd;
  SendMessageA(hWnd: wnd, Msg: 0xBu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: wnd, Msg: 0x184u, wParam: 0, lParam: 0);
  selectslot = 0;
  v12 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FirstInorder(this: &m_SortedNames);
  if ( v12 != -1 )
  {
    do
    {
      m_Data = m_SortedNames.m_Elements.m_pMemory[v12].m_Data;
      if ( m_Data != nullptr && *m_Data != 0 )
      {
        temp = SendMessageA(
                 hWnd: wnd,
                 Msg: 0x180u,
                 wParam: 0,
                 lParam: (LPARAM)m_SortedNames.m_Elements.m_pMemory[v12].m_Data);
        if ( _V_stricmp(s1: m_Data, s2: current) == 0 )
          selectslot = temp;
      }
      v12 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
              this: &m_SortedNames,
              i: v12);
    }
    while ( v12 != -1 );
    v11 = wnd;
  }
  SendMessageA(hWnd: v11, Msg: 0x186u, wParam: selectslot, lParam: 0);
  SendMessageA(hWnd: v11, Msg: 0xBu, wParam: 1u, lParam: 0);
  CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RemoveAll(this: &m_SortedNames);
  if ( m_SortedNames.m_Elements.m_nGrowSize >= 0 && m_SortedNames.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_SortedNames.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00444A10
// Name: private: void CEventPropertiesSpeakDialog::AddFilterToHistory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::AddFilterToHistory(CEventPropertiesSpeakDialog *this, const char *filter)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbol *m_pMemory; // eax
  int v6; // ecx
  CUtlSymbol *v7; // esi
  HWND DlgItem; // eax

  CUtlSymbolTable::AddString(this: &this->m_Symbols, result: (CUtlSymbol *)&filter, pString: filter);
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::FindAndRemove(
    this: &this->m_FilterHistory,
    src: (const CUtlSymbol *)&filter);
  m_Size = this->m_FilterHistory.m_Size;
  m_nAllocationCount = this->m_FilterHistory.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlSymbol,int>::Grow(
      this: (CUtlMemory<short,int> *)&this->m_FilterHistory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_FilterHistory.m_Size;
  m_pMemory = this->m_FilterHistory.m_Memory.m_pMemory;
  v6 = this->m_FilterHistory.m_Size - 1;
  this->m_FilterHistory.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[1], src: m_pMemory, count: 2 * v6);
  v7 = this->m_FilterHistory.m_Memory.m_pMemory;
  if ( v7 != nullptr )
    v7->m_Id = (unsigned __int16)filter;
  CEventPropertiesSpeakDialog::PopulateFilterList(this, resetCurrent: false);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1067);
  CEventPropertiesSpeakDialog::PopulateSoundList(this, current: g_Params_18.m_szParameters, wnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x00444AB0
// Name: private: void CEventPropertiesSpeakDialog::OnCheckFilterUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::OnCheckFilterUpdate(CEventPropertiesSpeakDialog *this)
{
  HWND DlgItem; // eax
  char curfilter[256]; // [esp+8h] [ebp-100h] BYREF

  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1068);
  SendMessageA(hWnd: DlgItem, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)curfilter);
  if ( _V_stricmp(s1: curfilter, s2: this->m_szLastFilter) != 0 )
  {
    V_strncpy(pDest: this->m_szLastFilter, pSrc: curfilter, maxLen: 256);
    CEventPropertiesSpeakDialog::AddFilterToHistory(this, filter: this->m_szLastFilter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444B20
// Name: public: virtual void CEventPropertiesSpeakDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesSpeakDialog::InitControlData(CEventPropertiesSpeakDialog *this, HWND__ *params)
{
  signed int TickCount; // eax
  UINT_PTR v5; // eax
  HWND DlgItem; // eax
  HWND__ *m_hDialog; // [esp-10h] [ebp-20h]
  HWND__ *v8; // [esp-8h] [ebp-18h]
  HWND__ *choices1; // [esp+Ch] [ebp-4h]
  HWND__ *choices2; // [esp+18h] [ebp+8h]

  CBaseEventPropertiesDialog::InitControlData(this, (CEventParams *)params);
  TickCount = mx::getTickCount();
  m_hDialog = this->m_hDialog;
  this->m_flLastFilterUpdateTime = (float)TickCount * 0.001;
  v5 = SetTimer(hWnd: m_hDialog, nIDEvent: 0x64u, uElapse: 1u, lpTimerFunc: nullptr);
  v8 = this->m_hDialog;
  this->m_Timer = v5;
  choices1 = GetDlgItem(hDlg: v8, nIDDlgItem: 1067);
  SendMessageA(hWnd: choices1, Msg: 0x184u, wParam: 0, lParam: 0);
  choices2 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1010);
  SendMessageA(hWnd: choices2, Msg: 0x14Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: choices2, Msg: 0xCu, wParam: 0, lParam: (LPARAM)(params + 164));
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1059);
  SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: *((_BYTE *)params + 1721) != 0, lParam: 0);
  CEventPropertiesSpeakDialog::PopulateSoundList(this, current: (const char *)params + 400, wnd: choices1);
  CEventPropertiesSpeakDialog::OnSoundSelected(this, params);
  CEventPropertiesSpeakDialog::PopulateFilterList(this, resetCurrent: true);
}

//------------------------------------------------------------------------------
// Address: 0x00444C10
// Name: public: virtual int CEventPropertiesSpeakDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesSpeakDialog::HandleMessage(
        CEventPropertiesSpeakDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        HWND lParam)
{
  HWND__ *v5; // ebx
  unsigned int v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesSpeakDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // edi
  HWND v11; // eax
  HWND v12; // eax
  float v13; // xmm0_4
  char *v14; // eax
  HWND v15; // eax
  int v16; // esi
  const char *v17; // eax
  HWND v18; // eax
  bool v19; // zf
  HWND__ *m_hDialog; // eax
  HWND v21; // eax
  HWND DlgItem; // eax
  LRESULT v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // ebx
  WPARAM v28; // eax
  IFacePoserSound_vtbl *v29; // esi
  const char *v30; // eax
  char *v31; // eax
  HWND__ *v32; // [esp+10h] [ebp-364h]
  unsigned int v33; // [esp+14h] [ebp-360h]
  unsigned int v34; // [esp+18h] [ebp-35Ch]
  HWND v35; // [esp+1Ch] [ebp-358h]
  char relative_path[260]; // [esp+30h] [ebp-344h] BYREF
  char full_path[512]; // [esp+134h] [ebp-240h] BYREF
  tagRECT rcOut; // [esp+334h] [ebp-40h] BYREF
  char szTime[32]; // [esp+354h] [ebp-20h] BYREF

  v5 = hwndDlg;
  v6 = wParam;
  v35 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v34 = wParam;
  v33 = uMsg;
  v32 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(
             this,
             a2: &g_Params_18,
             a3: v32,
             a4: v33,
             a5: v34,
             a6: (int)v35,
             a7: (bool *)&hwndDlg + 3);
  if ( HIBYTE(hwndDlg) != 0 )
    return result;
  if ( uMsg > 0x110 )
  {
    switch ( uMsg )
    {
      case 0x111u:
        if ( (unsigned __int16)v6 <= 0x3F2u )
        {
          switch ( (unsigned __int16)v6 )
          {
            case 0x3F2u:
              if ( lParam != nullptr )
              {
                SendMessageA(hWnd: lParam, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_18.m_szParameters2);
                return 1;
              }
              break;
            case 1u:
              GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1061, lpString: full_path, cchMax: 512);
              V_FixSlashes(pname: full_path, separator: 92);
              V_strncpy(pDest: g_Params_18.m_szParameters, pSrc: full_path, maxLen: 256);
              v14 = _V_strstr(s1: full_path, search: "\\sound\\");
              if ( v14 != nullptr )
                V_strncpy(pDest: g_Params_18.m_szParameters, pSrc: v14 + 7, maxLen: 256);
              CEventPropertiesSpeakDialog::OnCheckChangedVolumeLevel(this, params: &g_Params_18);
              GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_18.m_szName, cchMax: 256);
              if ( g_Params_18.m_szName[0] == 0 )
                V_strncpy(pDest: g_Params_18.m_szName, pSrc: full_path, maxLen: 256);
              GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
              g_Params_18.m_flStartTime = atof(nptr: szTime);
              GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
              g_Params_18.m_flEndTime = atof(nptr: szTime);
              CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_18);
              KillTimer(hWnd: this->m_hDialog, uIDEvent: this->m_Timer);
              EndDialog(hDlg: v5, nResult: 1);
              return 1;
            case 2u:
              KillTimer(hWnd: this->m_hDialog, uIDEvent: this->m_Timer);
              EndDialog(hDlg: v5, nResult: 0);
              return 1;
            default:
              break;
          }
          return 1;
        }
        switch ( (__int16)v6 )
        {
          case 1017:
            DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
            v23 = SendMessageA(hWnd: DlgItem, Msg: 0xF0u, wParam: 0, lParam: 0);
            g_Params_18.m_bHasEndTime = v23 == 1;
            if ( v23 == 1 )
            {
              v25 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
              ShowWindow(hWnd: v25, nCmdShow: 9);
            }
            else
            {
              v24 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
              ShowWindow(hWnd: v24, nCmdShow: 0);
            }
            return 1;
          case 1018:
            v26 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
            g_Params_18.m_bResumeCondition = SendMessageA(hWnd: v26, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
            return 1;
          case 1025:
            g_Params_18.m_bUsesTag = false;
            goto LABEL_46;
          case 1026:
            g_Params_18.m_bUsesTag = true;
LABEL_46:
            CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_18);
            return 1;
          case 1058:
            v18 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1058);
            v19 = SendMessageA(hWnd: v18, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
            m_hDialog = this->m_hDialog;
            this->m_bShowAll = v19;
            v21 = GetDlgItem(hDlg: m_hDialog, nIDDlgItem: 1007);
            CEventPropertiesSpeakDialog::PopulateSoundList(this, current: g_Params_18.m_szParameters, wnd: v21);
            return 1;
          case 1059:
            v15 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1059);
            g_Params_18.m_bCloseCaptionNoAttenuate = SendMessageA(hWnd: v15, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
            return 1;
          case 1067:
            v27 = lParam;
            if ( lParam == nullptr )
              return 1;
            v28 = SendMessageA(hWnd: lParam, Msg: 0x188u, wParam: 0, lParam: 0);
            if ( v28 == -1 )
              return 1;
            SendMessageA(hWnd: v27, Msg: 0x189u, wParam: v28, lParam: (LPARAM)g_Params_18.m_szParameters);
            CEventPropertiesSpeakDialog::OnSoundSelected(this, params: (HWND__ *)&g_Params_18);
            if ( HIWORD(v6) != 2 )
              return 1;
            goto $LN19_3;
          case 1071:
$LN19_3:
            v29 = sound->__vftable;
            v30 = FacePoser_TranslateSoundName(soundname: g_Params_18.m_szParameters, model: nullptr);
            v31 = va(fmt: "sound/%s", v30);
            ((void (__thiscall *)(IFacePoserSound *, _DWORD, int, char *, _DWORD))v29->PlaySound_2)(
              a1: sound,
              a2: 0,
              a3: 1065353216,
              a4: v31,
              a5: 0);
            result = 1;
            break;
          case 1072:
            v16 = soundemitter->GetSoundIndex(this: soundemitter, a2: g_Params_18.m_szParameters);
            if ( v16 < 0 )
              return 1;
            if ( soundemitter->InternalGetParametersForSound(this: soundemitter, a2: v16) == nullptr )
              return 1;
            v17 = soundemitter->GetSourceFileForSound(this: soundemitter, a2: v16);
            if ( v17 == nullptr )
              return 1;
            V_snprintf(pDest: relative_path, maxLen: 260, pFormat: "%s", v17);
            if ( filesystem->GetLocalPath(this: filesystem, a2: relative_path, a3: &full_path[252], a4: 260) == nullptr )
              return 1;
            ShellExecuteA(
              hwnd: nullptr,
              lpOperation: "open",
              lpFile: &full_path[252],
              lpParameters: nullptr,
              lpDirectory: nullptr,
              nShowCmd: 1);
            result = 1;
            break;
          default:
            return 1;
        }
        break;
      case 0x113u:
        MatSysWindow::Frame(this: g_pMatSysWindow);
        v13 = (float)(int)mx::getTickCount() * 0.001;
        if ( (float)(v13 - this->m_flLastFilterUpdateTime) > 0.5 )
        {
          this->m_flLastFilterUpdateTime = v13;
          CEventPropertiesSpeakDialog::OnCheckFilterUpdate(this);
        }
        return 0;
      case 0x115u:
        v12 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
        CBaseEventPropertiesDialog::GetSplineRect(this, placeholder: v12, rcOut: (tagRECT *)&szTime[16]);
        InvalidateRect(hWnd: v5, lpRect: (const RECT *)&szTime[16], bErase: true);
        UpdateWindow(hWnd: v5);
        return 0;
      default:
        return 0;
    }
  }
  else
  {
    if ( uMsg != 272 )
    {
      if ( uMsg == 15 )
      {
        v10 = BeginPaint(hWnd: v5, lpPaint: (LPPAINTSTRUCT)&rcOut);
        v11 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
        CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_18.m_pEvent);
        EndPaint(hWnd: v5, lpPaint: (const PAINTSTRUCT *)&rcOut);
      }
      return 0;
    }
    this->InitDialog(this, a2: v5);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00445220
// Name: EventPropertiesSpeakDialog
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesSpeakDialog(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, HWND lParam)
{
  return CEventPropertiesSpeakDialog::HandleMessage(this: &g_EventPropertiesSpeakDialog, hwndDlg, uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00445230
// Name: int EventProperties_Speak(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_Speak(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_18 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x7C,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EventPropertiesSpeakDialog,
             dwInitParam: 0);
  *params = g_Params_18;
  return result;
}
