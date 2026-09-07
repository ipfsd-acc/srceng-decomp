// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/soundpicker.cpp
// Functions: 34
// ============================================================

#include "vgui2\dme_controls\soundpicker.h"

//------------------------------------------------------------------------------
// Address: 0x00481270
// Name: public: static char const __near * CSoundPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSoundPicker::GetPanelClassName()
{
  return "CSoundPicker";
}

//------------------------------------------------------------------------------
// Address: 0x00481280
// Name: public: static char const __near * CSoundPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSoundPickerFrame::GetPanelClassName()
{
  return "CSoundPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x00481290
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004812E0
// Name: GameSoundSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl GameSoundSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  bool v3; // bl
  const char *String; // esi
  const char *v6; // eax

  v3 = KeyValues::GetInt(this: item1->kv, keyName: "root", defaultValue: 0) != 0;
  if ( v3 != (KeyValues::GetInt(this: item2->kv, keyName: "root", defaultValue: 0) != 0) )
    return 2 * !v3 - 1;
  String = KeyValues::GetString(this: item1->kv, keyName: "gamesound", defaultValue: defaultValue);
  v6 = KeyValues::GetString(this: item2->kv, keyName: "gamesound", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00481360
// Name: public: void CSoundPicker::SetSelectedSound(enum CSoundPicker::PickType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::SetSelectedSound(
        CSoundPicker *this,
        CSoundPicker::PickType_t type,
        const char *pSoundName)
{
  if ( type != PICK_NONE && pSoundName != nullptr )
  {
    if ( this->m_pGameSoundPage != nullptr && type == PICK_GAMESOUNDS )
    {
      this->m_pViewsSheet->SetActivePage(this: this->m_pViewsSheet, a2: this->m_pGameSoundPage);
      this->m_pGameSoundFilter->SetText(this: this->m_pGameSoundFilter, a2: pSoundName);
    }
    if ( this->m_pWavPage != nullptr && type == PICK_WAVFILES )
    {
      this->m_pViewsSheet->SetActivePage(this: this->m_pViewsSheet, a2: this->m_pWavPage);
      CBaseAssetPicker::SetInitialSelection(this, pAssetName: pSoundName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004813E0
// Name: public: virtual void CSoundPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnKeyCodeTyped(CSoundPicker *this, KeyValues *code)
{
  KeyValues *v3; // eax
  vgui::IPanel *v4; // edi
  vgui::ListPanel *m_pGameSoundList; // ebx
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v8; // [esp+8h] [ebp-4h]
  KeyValues *pMsg; // [esp+14h] [ebp+8h]

  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage
    && (code == (KeyValues *)88 || code == (KeyValues *)90 || code == (KeyValues *)76 || code == (KeyValues *)77) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      pMsg = KeyValues::KeyValues(this: v3, setName: "KeyCodeTyped", firstKey: "code", firstValue: (int)code);
    else
      pMsg = nullptr;
    v4 = g_pVGuiPanel;
    v8 = g_pVGuiPanel->__vftable;
    m_pGameSoundList = this->m_pGameSoundList;
    v6 = this->GetVPanel(this);
    v7 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pGameSoundList->GetVPanel)(
           a1: m_pGameSoundList,
           a2: pMsg,
           a3: v6);
    ((void (__thiscall *)(vgui::IPanel *, int))v8->SendMessage)(a1: v4, a2: v7);
    KeyValues::deleteThis(this: pMsg);
  }
  else
  {
    CBaseAssetPicker::OnKeyCodeTyped(this, (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004814B0
// Name: private: void CSoundPicker::BuildGameSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::BuildGameSoundList(CSoundPicker *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  vgui::ListPanel *m_pGameSoundList; // ecx
  int v5; // edi
  ISoundEmitterSystemBase *v6; // eax
  int v7; // esi
  ISoundEmitterSystemBase *v8; // eax
  ISoundEmitterSystemBase *v9; // eax
  char *v10; // edi
  int v11; // eax
  int v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  ISoundEmitterSystemBase *v15; // eax
  const char *v16; // eax
  int v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // edi
  ISoundEmitterSystemBase *v20; // eax
  ISoundEmitterSystemBase *v21; // eax
  int v22; // eax
  vgui::ListPanel *v23; // ecx
  char pDest[512]; // [esp+4h] [ebp-214h] BYREF
  char *pStr; // [esp+204h] [ebp-14h]
  const char *pSoundName; // [esp+208h] [ebp-10h]
  int nItemID; // [esp+20Ch] [ebp-Ch]
  int nTotalCount; // [esp+210h] [ebp-8h]
  bool bInRoot; // [esp+217h] [ebp-1h]

  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr )
  {
    ((void (__thiscall *)(vgui::ListPanel *, int, int))m_pGameSoundList->RemoveAll)(a1: m_pGameSoundList, a2, a3);
    v5 = 0;
    nTotalCount = 0;
    v6 = vgui::SoundEmitterSystem();
    v7 = v6->First(this: v6);
    v8 = vgui::SoundEmitterSystem();
    if ( v7 != v8->InvalidIndex(this: v8) )
    {
      do
      {
        v9 = vgui::SoundEmitterSystem();
        v10 = (char *)v9->GetSoundName(this: v9, a2: v7);
        pSoundName = v10;
        strchr(string: (unsigned __int8 *)v10, chr: 0x5Cu);
        if ( v11 != 0 || (strchr(string: (unsigned __int8 *)v10, chr: 0x2Fu), bInRoot = true, v12 != 0) )
          bInRoot = false;
        v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v13 != nullptr )
          v14 = KeyValues::KeyValues(this: v13, setName: "node", firstKey: "gamesound", firstValue: v10);
        else
          v14 = nullptr;
        KeyValues::SetInt(this: v14, keyName: "gameSoundHandle", value: v7);
        KeyValues::SetInt(this: v14, keyName: "root", value: bInRoot);
        nItemID = this->m_pGameSoundList->AddItem(this: this->m_pGameSoundList, a2: v14, a3: 0, a4: false, a5: false);
        v15 = vgui::SoundEmitterSystem();
        pStr = (char *)v15->GetSoundName(this: v15, a2: v7);
        if ( CUtlString::Length(this: &this->m_GameSoundFilter) == 0
          || (v16 = CUtlString::Get(this: &this->m_GameSoundFilter), (v17 = (int)V_stristr(pStr, pSearch: v16)) != 0) )
        {
          v17 = 1;
        }
        this->m_pGameSoundList->SetItemVisible(this: this->m_pGameSoundList, a2: nItemID, a3: v17);
        v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v18 != nullptr )
          v19 = KeyValues::KeyValues(this: v18, setName: "drag", firstKey: "text", firstValue: pSoundName);
        else
          v19 = nullptr;
        KeyValues::SetString(this: v19, keyName: "texttype", value: "gamesoundName");
        vgui::ListPanel::SetItemDragData(this: this->m_pGameSoundList, itemID: nItemID, data: v19);
        ++nTotalCount;
        v20 = vgui::SoundEmitterSystem();
        v7 = v20->Next(this: v20, a2: v7);
        v21 = vgui::SoundEmitterSystem();
      }
      while ( v7 != v21->InvalidIndex(this: v21) );
      v5 = nTotalCount;
    }
    this->m_pGameSoundList->SortList(this: this->m_pGameSoundList);
    if ( this->m_pGameSoundList->GetItemCount(this: this->m_pGameSoundList) > 0 )
    {
      v22 = this->m_pGameSoundList->GetItemIDFromRow(this: this->m_pGameSoundList, a2: 0);
      v23 = this->m_pGameSoundList;
      ++this->m_nSoundSuppressionCount;
      v23->SetSelectedCell(this: v23, a2: v22, a3: 0);
    }
    V_snprintf(pDest, maxLen: 512, pFormat: "%s (%d/%d)", "Game Sound", v5, v5);
    this->m_pGameSoundList->SetColumnHeaderText_2(this: this->m_pGameSoundList, a2: 0, a3: pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481700
// Name: private: void CSoundPicker::RefreshGameSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::RefreshGameSoundList(CSoundPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::ListPanel *m_pGameSoundList; // ecx
  int i; // edi
  KeyValues *v6; // ebx
  ISoundEmitterSystemBase *v7; // eax
  int v8; // eax
  int Int; // ebx
  ISoundEmitterSystemBase *v10; // eax
  ISoundEmitterSystemBase *v11; // eax
  const char *v12; // eax
  bool v13; // bl
  vgui::ListPanel *v14; // ecx
  void (__thiscall *SetItemVisible)(vgui::ListPanel *, int, bool); // edx
  int v16; // eax
  char pDest[512]; // [esp+4h] [ebp-210h] BYREF
  char *pStr; // [esp+204h] [ebp-10h]
  BOOL bIsVisible; // [esp+208h] [ebp-Ch]
  int nMatchingGameSounds; // [esp+20Ch] [ebp-8h]
  int nTotalCount; // [esp+210h] [ebp-4h]

  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr )
  {
    nMatchingGameSounds = 0;
    nTotalCount = 0;
    for ( i = ((int (__thiscall *)(vgui::ListPanel *, int))m_pGameSoundList->FirstItem)(a1: m_pGameSoundList, a2: a3);
          i != this->m_pGameSoundList->InvalidItemID(this: this->m_pGameSoundList);
          i = ((int (__thiscall *)(vgui::ListPanel *))this->m_pGameSoundList->NextItem)(a1: this->m_pGameSoundList) )
    {
      v6 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pGameSoundList->GetItem)(
                          a1: this->m_pGameSoundList,
                          a2: i,
                          a3: a2);
      v7 = vgui::SoundEmitterSystem();
      v8 = v7->InvalidIndex(this: v7);
      Int = KeyValues::GetInt(this: v6, keyName: "gameSoundHandle", defaultValue: v8);
      v10 = vgui::SoundEmitterSystem();
      if ( Int != v10->InvalidIndex(this: v10) )
      {
        v11 = vgui::SoundEmitterSystem();
        pStr = (char *)v11->GetSoundName(this: v11, a2: Int);
        v13 = true;
        if ( CUtlString::Length(this: &this->m_GameSoundFilter) != 0 )
        {
          v12 = CUtlString::Get(this: &this->m_GameSoundFilter);
          if ( V_stristr(pStr, pSearch: v12) == nullptr )
            v13 = false;
        }
        v14 = this->m_pGameSoundList;
        SetItemVisible = v14->SetItemVisible;
        LOBYTE(bIsVisible) = v13;
        SetItemVisible(this: v14, a2: i, a3: bIsVisible);
        if ( v13 )
          ++nMatchingGameSounds;
        ++nTotalCount;
      }
      a2 = i;
    }
    V_snprintf(pDest, maxLen: 512, pFormat: "%s (%d/%d)", "Game Sound", nMatchingGameSounds, nTotalCount);
    ((void (__thiscall *)(vgui::ListPanel *, _DWORD))this->m_pGameSoundList->SetColumnHeaderText_2)(
      a1: this->m_pGameSoundList,
      a2: 0);
    if ( this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList) == 0
      && this->m_pGameSoundList->GetItemCount(this: this->m_pGameSoundList) > 0 )
    {
      v16 = this->m_pGameSoundList->GetItemIDFromRow(this: this->m_pGameSoundList, a2: 0);
      ++this->m_nSoundSuppressionCount;
      this->m_pGameSoundList->SetSelectedCell(this: this->m_pGameSoundList, a2: v16, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004818C0
// Name: private: void CSoundPicker::OnGameSoundFilterTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::OnGameSoundFilterTextChanged(CSoundPicker *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  char *v4; // eax
  vgui::TextEntry_vtbl *v5; // [esp+Ch] [ebp-4h]

  v3 = this->m_pGameSoundFilter->GetTextLength(this: this->m_pGameSoundFilter);
  CUtlString::SetLength(this: &this->m_GameSoundFilter, nLen: v3);
  if ( v3 > 0 )
  {
    v5 = this->m_pGameSoundFilter->__vftable;
    ++v3;
    v4 = CUtlString::Get(this: &this->m_GameSoundFilter);
    v5->GetText_2(this: this->m_pGameSoundFilter, a2: v4, a3: v3);
  }
  CSoundPicker::RefreshGameSoundList(this, a2, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00481930
// Name: private: virtual void CSoundPicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSoundPicker::OnTextChanged(CSoundPicker *this@<ecx>, int a2@<ebx>, KeyValues *pKeyValues)
{
  if ( KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr) == this->m_pGameSoundFilter )
    CSoundPicker::OnGameSoundFilterTextChanged(this, a2);
  else
    CBaseAssetPicker::OnTextChanged(this, pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00481970
// Name: private: void CSoundPicker::PlayGameSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::PlayGameSound(CSoundPicker *this, const char *pSoundName)
{
  IEngineTool *v3; // eax
  ISoundEmitterSystemBase *v4; // eax
  IEngineTool *v5; // eax
  CSoundParameters params; // [esp+40h] [ebp-B4h] BYREF

  if ( this->m_nPlayingSound != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
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
  v4 = vgui::SoundEmitterSystem();
  if ( v4->GetParametersForSound(this: v4, a2: pSoundName, a3: &params, a4: GENDER_NONE, a5: false) )
  {
    v5 = vgui::EngineTool();
    this->m_nPlayingSound = ((int (__thiscall *)(IEngineTool *, _DWORD, int, int, int, char *, _DWORD, soundlevel_t, Vector *, Vector *, _DWORD, int, _DWORD, _DWORD, int))v5->StartSound)(
                              a1: v5,
                              a2: 0,
                              a3: 1,
                              a4: -1,
                              a5: 6,
                              a6: params.soundname,
                              a7: LODWORD(params.volume),
                              a8: params.soundlevel,
                              a9: &vec3_origin,
                              a10: &vec3_origin,
                              a11: 0,
                              a12: params.pitch,
                              a13: 0,
                              a14: (float)params.delay_msec * 0.001,
                              a15: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481A90
// Name: private: virtual void CSoundPicker::OnNextSelectionIsDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnNextSelectionIsDefault(CSoundPicker *this)
{
  ++this->m_nSoundSuppressionCount;
}

//------------------------------------------------------------------------------
// Address: 0x00481AA0
// Name: public: enum CSoundPicker::PickType_t CSoundPicker::GetSelectedSoundType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundPicker::GetSelectedSoundType(CSoundPicker *this)
{
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    return 1;
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    return 2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00481B00
// Name: public: int CSoundPicker::GetSelectedSoundCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundPicker::GetSelectedSoundCount(CSoundPicker *this)
{
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    return this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList);
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    return CBaseAssetPicker::GetSelectedAssetCount(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00481B70
// Name: public: char const __near * CSoundPicker::GetSelectedSoundName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundPicker::GetSelectedSoundName(CSoundPicker *this, int nSelectionIndex)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  KeyValues *v6; // eax

  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    v3 = this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList);
    if ( v3 != 0 )
    {
      v4 = nSelectionIndex;
      if ( nSelectionIndex < 0 )
        v4 = v3 - 1;
      v5 = this->m_pGameSoundList->GetSelectedItem(this: this->m_pGameSoundList, a2: v4);
      if ( v5 >= 0 )
      {
        v6 = this->m_pGameSoundList->GetItem(this: this->m_pGameSoundList, a2: v5);
        return KeyValues::GetString(this: v6, keyName: "gamesound", defaultValue: nullptr);
      }
    }
  }
  else if ( this->m_pWavPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
  {
    return CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00481C30
// Name: public: virtual void CSoundPickerFrame::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::OnClose(CSoundPickerFrame *this)
{
  CBaseAssetPicker *m_pPicker; // esi
  IEngineTool *v3; // eax

  m_pPicker = this->m_pPicker;
  if ( *(_DWORD *)&m_pPicker[1].m_clrDragFrame != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: *(_DWORD *)&m_pPicker[1].m_clrDragFrame);
    m_pPicker[1].m_clrDragFrame = 0;
  }
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x00481C70
// Name: public: void CSoundPickerFrame::DoModal(enum CSoundPicker::PickType_t,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::DoModal(
        CSoundPickerFrame *this,
        CSoundPicker::PickType_t initialType,
        const char *pInitialValue,
        KeyValues *pContextKeyValues)
{
  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 4u);
  if ( initialType != PICK_NONE && pInitialValue != nullptr )
    CSoundPicker::SetSelectedSound(this: (CSoundPicker *)this->m_pPicker, type: initialType, pSoundName: pInitialValue);
  CBaseAssetPickerFrame::DoModal(this, pKeyValues: pContextKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00481CC0
// Name: public: virtual void CSoundPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::OnCommand(CSoundPickerFrame *this, KeyValues *pCommand)
{
  CSoundPicker *m_pPicker; // ebx
  int SelectedSoundType; // eax
  const char *SelectedSoundName; // eax
  int v6; // edi
  void *v7; // esp
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  KeyValues *Key; // eax
  int v11; // esi
  const char *v12; // ebx
  void *v13; // esp
  CBaseAssetPickerFrame *v14; // esi
  char v15; // [esp+0h] [ebp-40h] BYREF
  char v16[11]; // [esp+1h] [ebp-3Fh] BYREF
  char pBuf[32]; // [esp+Ch] [ebp-34h] BYREF
  CBaseAssetPickerFrame *v18; // [esp+2Ch] [ebp-14h]
  CSoundPicker *pPicker; // [esp+30h] [ebp-10h]
  int len; // [esp+34h] [ebp-Ch]
  KeyValues *pActionKeys; // [esp+38h] [ebp-8h]
  int nSoundCount; // [esp+3Ch] [ebp-4h]
  KeyValues *pSoundList; // [esp+48h] [ebp+8h]
  KeyValues *pSoundLista; // [esp+48h] [ebp+8h]

  m_pPicker = (CSoundPicker *)this->m_pPicker;
  v18 = this;
  pPicker = m_pPicker;
  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Open") != 0 )
  {
    CBaseAssetPickerFrame::OnCommand(this, (const char *)pCommand);
  }
  else
  {
    SelectedSoundType = CSoundPicker::GetSelectedSoundType(this: m_pPicker);
    len = SelectedSoundType;
    if ( SelectedSoundType == 1 || SelectedSoundType == 2 )
    {
      SelectedSoundName = CSoundPicker::GetSelectedSoundName(this: m_pPicker, nSelectionIndex: -1);
      pSoundList = (KeyValues *)SelectedSoundName;
      if ( SelectedSoundName == nullptr )
      {
        this->CloseModal(this);
        return;
      }
      v6 = _V_strlen(str: SelectedSoundName);
      v7 = alloca(v6 + 2);
      v15 = 35;
      V_strncpy(pDest: v16, pSrc: (const char *)pSoundList, maxLen: v6 + 1);
      nSoundCount = CSoundPicker::GetSelectedSoundCount(this: m_pPicker);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "SoundSelected");
        pActionKeys = v9;
      }
      else
      {
        pActionKeys = nullptr;
        v9 = nullptr;
      }
      KeyValues::SetInt(this: v9, keyName: "count", value: nSoundCount);
      if ( len == 1 )
      {
        KeyValues::SetString(this: v9, keyName: "gamesound", value: &v15);
        if ( CBaseAssetPicker::IsMultiselectEnabled(this: m_pPicker) )
        {
          Key = KeyValues::FindKey(this: v9, keyName: "gamesounds", bCreate: true);
LABEL_14:
          pSoundLista = Key;
          if ( Key != nullptr )
          {
            v11 = 0;
            if ( nSoundCount > 0 )
            {
              while ( 1 )
              {
                V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", v11);
                v12 = CSoundPicker::GetSelectedSoundName(this: m_pPicker, nSelectionIndex: v11);
                len = _V_strlen(str: v12);
                v13 = alloca(len + 2);
                v15 = 35;
                V_strncpy(pDest: v16, pSrc: v12, maxLen: len + 1);
                KeyValues::SetString(this: pSoundLista, keyName: pBuf, value: &v15);
                if ( ++v11 >= nSoundCount )
                  break;
                m_pPicker = pPicker;
              }
              v9 = pActionKeys;
            }
          }
        }
      }
      else
      {
        KeyValues::SetString(this: v9, keyName: "wav", value: &v15);
        if ( CBaseAssetPicker::IsMultiselectEnabled(this: m_pPicker) )
        {
          Key = KeyValues::FindKey(this: v9, keyName: "wavs", bCreate: true);
          goto LABEL_14;
        }
      }
      v14 = v18;
      CBaseAssetPickerFrame::PostMessageAndClose(this: v18, pKeyValues: v9);
      v14->CloseModal(this: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481EA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSoundPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSoundPickerFrame::GetMessageMap(CSoundPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSoundPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CSoundPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSoundPickerFrame");
  `CSoundPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00481ED0
// Name: public: virtual struct PanelAnimationMap __near * CSoundPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSoundPickerFrame::GetAnimMap(CSoundPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CSoundPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00481EE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSoundPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSoundPickerFrame::GetKBMap(CSoundPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSoundPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPickerFrame::GetKBMap'::`2'::s_pMap;
  `CSoundPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPickerFrame");
  `CSoundPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00481F10
// Name: public: virtual void CSoundPicker::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::Activate(CSoundPicker *this@<ecx>, int a2@<edi>)
{
  CBaseAssetPicker::Activate(this);
  if ( this->m_pGameSoundPage != nullptr )
    CSoundPicker::BuildGameSoundList(this, a2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x00481F30
// Name: private: virtual void CSoundPicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnPageChanged(CSoundPicker *this)
{
  IEngineTool *v2; // eax

  if ( this->m_nPlayingSound != 0 )
  {
    v2 = vgui::EngineTool();
    v2->StopSoundByGuid(this: v2, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pGameSoundFilter, status: true);
    this->m_pGameSoundFilter->RequestFocus(this: this->m_pGameSoundFilter, a2: 0);
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    CBaseAssetPicker::RequestFilterFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x00481FD0
// Name: private: virtual void CSoundPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnItemSelected(CSoundPicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pGameSoundList; // ecx
  unsigned __int8 m_nSoundSuppressionCount; // al
  const char *SelectedSoundName; // eax
  const char *v7; // ebx
  void *v8; // esp
  char v9; // [esp+0h] [ebp-Ch] BYREF
  char v10[11]; // [esp+1h] [ebp-Bh] BYREF
  int len; // [esp+14h] [ebp+8h]
  char len_3; // [esp+17h] [ebp+Bh]

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr && Ptr == m_pGameSoundList )
  {
    m_nSoundSuppressionCount = this->m_nSoundSuppressionCount;
    len_3 = 1;
    if ( m_nSoundSuppressionCount != 0 )
    {
      this->m_nSoundSuppressionCount = m_nSoundSuppressionCount - 1;
      len_3 = 0;
    }
    SelectedSoundName = CSoundPicker::GetSelectedSoundName(this, nSelectionIndex: -1);
    v7 = SelectedSoundName;
    if ( SelectedSoundName != nullptr && len_3 != 0 )
    {
      len = _V_strlen(str: SelectedSoundName);
      v8 = alloca(len + 2);
      v9 = 35;
      V_strncpy(pDest: v10, pSrc: v7, maxLen: len + 1);
      CSoundPicker::PlayGameSound(this, pSoundName: &v9);
    }
  }
  else
  {
    CBaseAssetPicker::OnItemSelected(this, kv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004820B0
// Name: private: void CSoundPicker::PlayWavSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::PlayWavSound(CSoundPicker *this, char *pSoundName)
{
  IEngineTool *v3; // eax
  IEngineTool *v4; // esi
  char *v5; // eax
  CFmtStrN<256> *v6; // eax
  IEngineTool *v7; // eax
  CFmtStrN<256> v8; // [esp+38h] [ebp-10Ch] BYREF

  if ( this->m_nPlayingSound != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
  if ( *pSoundName != 0 )
  {
    v4 = vgui::EngineTool();
    v5 = PSkipSoundChars(pch: pSoundName);
    v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "sound\\%s", v5);
    v4->ValidateSoundCache(this: v4, a2: v6->m_szBuf);
    v7 = vgui::EngineTool();
    this->m_nPlayingSound = ((int (__thiscall *)(IEngineTool *, _DWORD, int, int, int, char *, int, _DWORD, Vector *, Vector *, _DWORD, int, _DWORD, _DWORD, int))v7->StartSound)(
                              a1: v7,
                              a2: 0,
                              a3: 1,
                              a4: -1,
                              a5: 6,
                              a6: pSoundName,
                              a7: 1065353216,
                              a8: 0,
                              a9: &vec3_origin,
                              a10: &vec3_origin,
                              a11: 0,
                              a12: 100,
                              a13: 0,
                              a14: 0,
                              a15: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482180
// Name: private: virtual void CSoundPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnSelectedAssetPicked(CSoundPicker *this, char *pAssetName)
{
  unsigned __int8 m_nSoundSuppressionCount; // al
  char v3; // dl

  m_nSoundSuppressionCount = this->m_nSoundSuppressionCount;
  v3 = 1;
  if ( m_nSoundSuppressionCount != 0 )
  {
    this->m_nSoundSuppressionCount = m_nSoundSuppressionCount - 1;
    v3 = 0;
  }
  if ( pAssetName != nullptr && v3 != 0 )
    CSoundPicker::PlayWavSound(this, pSoundName: pAssetName);
}

//------------------------------------------------------------------------------
// Address: 0x004821B0
// Name: public: static void CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482240
// Name: public: static void CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004822D0
// Name: public: static void CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482360
// Name: public: CSoundPicker::CSoundPicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSoundPicker *__thiscall CSoundPicker::CSoundPicker(CSoundPicker *this, vgui::Panel *pParent, int nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::PropertyPage *v9; // eax
  vgui::PropertyPage *v10; // eax
  vgui::ListPanel *v11; // eax
  vgui::ListPanel *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "Sound Files",
    pExt: "wav",
    pSubDir: "sound",
    pTextType: "wavName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CSoundPicker_vtbl *)&CSoundPicker::`vftable';
  if ( `CSoundPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    v4->pfnClassName = CSoundPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CSoundPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSoundPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSoundPicker");
    v5->pfnClassName = CSoundPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CSoundPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPicker");
    v6->pfnClassName = CSoundPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_GameSoundFilter);
  this->m_nSoundSuppressionCount = 0;
  this->m_nPlayingSound = 0;
  v7 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "ViewsSheet", draggableTabs: false);
  else
    v8 = nullptr;
  this->m_pViewsSheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->m_pGameSoundPage = nullptr;
  this->m_pGameSoundList = nullptr;
  if ( (nFlags & 1) != 0 )
  {
    v9 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v9 != nullptr )
      v10 = vgui::PropertyPage::PropertyPage(this: v9, parent: this->m_pViewsSheet, panelName: "GameSoundPage");
    else
      v10 = nullptr;
    this->m_pGameSoundPage = v10;
    v11 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v11 != nullptr )
      v12 = vgui::ListPanel::ListPanel(this: v11, parent: this->m_pGameSoundPage, panelName: "GameSoundsList");
    else
      v12 = nullptr;
    this->m_pGameSoundList = v12;
    v12->AddColumnHeader(this: v12, a2: 0, a3: "GameSound", a4: "Game Sound", a5: 52, a6: 0);
    this->m_pGameSoundList->AddActionSignalTarget_2(this: this->m_pGameSoundList, a2: this);
    this->m_pGameSoundList->SetSelectIndividualCells(this: this->m_pGameSoundList, a2: true);
    this->m_pGameSoundList->SetEmptyListText_2(this: this->m_pGameSoundList, a2: "No game sounds");
    this->m_pGameSoundList->SetDragEnabled(this: this->m_pGameSoundList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pGameSoundList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 0,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    this->m_pGameSoundList->SetSortFunc(this: this->m_pGameSoundList, a2: 0, a3: GameSoundSortFunc);
    this->m_pGameSoundList->SetSortColumn(this: this->m_pGameSoundList, a2: 0);
    vgui::ListPanel::SetMultiselectEnabled(this: this->m_pGameSoundList, bState: nFlags < 0);
    v13 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v13 != nullptr )
      v14 = vgui::TextEntry::TextEntry(this: v13, parent: this->m_pGameSoundPage, panelName: "GameSoundFilter");
    else
      v14 = nullptr;
    this->m_pGameSoundFilter = v14;
    v14->AddActionSignalTarget_2(this: v14, a2: this);
    this->m_pGameSoundPage->LoadControlSettings(
      this: this->m_pGameSoundPage,
      a2: "resource/soundpickergamesoundpage.res",
      a3: nullptr,
      a4: nullptr,
      a5: nullptr);
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: this->m_pGameSoundPage,
      a3: "Game Sounds",
      a4: nullptr,
      a5: false,
      a6: -1);
  }
  this->m_pWavPage = nullptr;
  if ( (nFlags & 2) != 0 )
  {
    v15 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v15 != nullptr )
      v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pViewsSheet, panelName: "WavPage");
    else
      v16 = nullptr;
    this->m_pWavPage = v16;
    CBaseAssetPicker::CreateStandardControls(this, pParent: v16, bAllowMultiselect: nFlags < 0);
    CBaseAssetPicker::AddExtension(this, pExtension: "mp3");
    this->m_pWavPage->LoadControlSettings(
      this: this->m_pWavPage,
      a2: "resource/soundpickerwavpage.res",
      a3: nullptr,
      a4: nullptr,
      a5: nullptr);
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: this->m_pWavPage,
      a3: "WAVs",
      a4: nullptr,
      a5: false,
      a6: -1);
  }
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/soundpicker.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004826D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSoundPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSoundPicker::GetMessageMap(CSoundPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSoundPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPicker::GetMessageMap'::`2'::s_pMap;
  `CSoundPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
  `CSoundPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482700
// Name: public: virtual struct PanelAnimationMap __near * CSoundPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSoundPicker::GetAnimMap(CSoundPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CSoundPicker");
}

//------------------------------------------------------------------------------
// Address: 0x00482710
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSoundPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSoundPicker::GetKBMap(CSoundPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSoundPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPicker::GetKBMap'::`2'::s_pMap;
  `CSoundPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPicker");
  `CSoundPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004827B0
// Name: public: CSoundPickerFrame::CSoundPickerFrame(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSoundPickerFrame *__thiscall CSoundPickerFrame::CSoundPickerFrame(
        CSoundPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        int nFlags)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CSoundPicker *v8; // eax
  CSoundPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CSoundPickerFrame_vtbl *)&CSoundPickerFrame::`vftable';
  if ( `CSoundPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSoundPickerFrame");
    v5->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CSoundPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSoundPickerFrame");
    v6->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CSoundPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPickerFrame");
    v7->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CSoundPicker *)MemAlloc_Alloc(nSize: 0x274u);
  if ( v8 != nullptr )
    v9 = CSoundPicker::CSoundPicker(this: v8, pParent: this, nFlags);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/soundpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104A44A0
// Name: public: static char const __near * CSoundPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSoundPicker::GetPanelClassName()
{
  return "CSoundPicker";
}

//------------------------------------------------------------------------------
// Address: 0x104A44B0
// Name: public: static char const __near * CSoundPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSoundPickerFrame::GetPanelClassName()
{
  return "CSoundPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104A44C0
// Name: GameSoundSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl GameSoundSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  bool v3; // bl
  char *String; // esi
  char *v6; // eax

  v3 = KeyValues::GetInt(this: item1->kv, keyName: "root", defaultValue: 0) != 0;
  if ( v3 != (KeyValues::GetInt(this: item2->kv, keyName: "root", defaultValue: 0) != 0) )
    return 2 * !v3 - 1;
  String = KeyValues::GetString(this: item1->kv, keyName: "gamesound", defaultValue: &var);
  v6 = KeyValues::GetString(this: item2->kv, keyName: "gamesound", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x104A4540
// Name: public: void CSoundPicker::SetSelectedSound(enum CSoundPicker::PickType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::SetSelectedSound(
        CSoundPicker *this,
        CSoundPicker::PickType_t type,
        const char *pSoundName)
{
  if ( type != PICK_NONE && pSoundName != nullptr )
  {
    if ( this->m_pGameSoundPage != nullptr && type == PICK_GAMESOUNDS )
    {
      this->m_pViewsSheet->SetActivePage(this: this->m_pViewsSheet, a2: this->m_pGameSoundPage);
      this->m_pGameSoundFilter->SetText(this: this->m_pGameSoundFilter, a2: pSoundName);
    }
    if ( this->m_pWavPage != nullptr && type == PICK_WAVFILES )
    {
      this->m_pViewsSheet->SetActivePage(this: this->m_pViewsSheet, a2: this->m_pWavPage);
      CBaseAssetPicker::SetInitialSelection(this, pAssetName: pSoundName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A45C0
// Name: public: virtual void CSoundPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnKeyCodeTyped(CSoundPicker *this, KeyValues *code)
{
  KeyValues *v3; // eax
  vgui::IPanel *v4; // edi
  vgui::ListPanel *m_pGameSoundList; // ebx
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v8; // [esp+8h] [ebp-4h]
  KeyValues *pMsg; // [esp+14h] [ebp+8h]

  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage
    && (code == (KeyValues *)88 || code == (KeyValues *)90 || code == (KeyValues *)76 || code == (KeyValues *)77) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      pMsg = KeyValues::KeyValues(this: v3, setName: "KeyCodeTyped", firstKey: "code", firstValue: (int)code);
    else
      pMsg = nullptr;
    v4 = g_pVGuiPanel;
    v8 = g_pVGuiPanel->__vftable;
    m_pGameSoundList = this->m_pGameSoundList;
    v6 = this->GetVPanel(this);
    v7 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pGameSoundList->GetVPanel)(
           a1: m_pGameSoundList,
           a2: pMsg,
           a3: v6);
    ((void (__thiscall *)(vgui::IPanel *, int))v8->SendMessage)(a1: v4, a2: v7);
    KeyValues::deleteThis(this: pMsg);
  }
  else
  {
    CBaseAssetPicker::OnKeyCodeTyped(this, (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A4690
// Name: private: void CSoundPicker::BuildGameSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::BuildGameSoundList(CSoundPicker *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  vgui::ListPanel *m_pGameSoundList; // ecx
  int v5; // edi
  ISoundEmitterSystemBase *v6; // eax
  int v7; // esi
  ISoundEmitterSystemBase *v8; // eax
  ISoundEmitterSystemBase *v9; // eax
  char *v10; // edi
  int v11; // eax
  int v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  ISoundEmitterSystemBase *v15; // eax
  const char *v16; // eax
  int v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // edi
  ISoundEmitterSystemBase *v20; // eax
  ISoundEmitterSystemBase *v21; // eax
  int v22; // eax
  vgui::ListPanel *v23; // ecx
  char pDest[512]; // [esp+4h] [ebp-214h] BYREF
  char *pStr; // [esp+204h] [ebp-14h]
  const char *pSoundName; // [esp+208h] [ebp-10h]
  int nItemID; // [esp+20Ch] [ebp-Ch]
  int nTotalCount; // [esp+210h] [ebp-8h]
  bool bInRoot; // [esp+217h] [ebp-1h]

  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr )
  {
    ((void (__thiscall *)(vgui::ListPanel *, int, int))m_pGameSoundList->RemoveAll)(a1: m_pGameSoundList, a2, a3);
    v5 = 0;
    nTotalCount = 0;
    v6 = vgui::SoundEmitterSystem();
    v7 = v6->First(this: v6);
    v8 = vgui::SoundEmitterSystem();
    if ( v7 != v8->InvalidIndex(this: v8) )
    {
      do
      {
        v9 = vgui::SoundEmitterSystem();
        v10 = (char *)v9->GetSoundName(this: v9, a2: v7);
        pSoundName = v10;
        strchr(string: v10, chr: 0x5Cu);
        if ( v11 != 0 || (strchr(string: v10, chr: 0x2Fu), bInRoot = true, v12 != 0) )
          bInRoot = false;
        v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v13 != nullptr )
          v14 = KeyValues::KeyValues(this: v13, setName: "node", firstKey: "gamesound", firstValue: v10);
        else
          v14 = nullptr;
        KeyValues::SetInt(this: v14, keyName: "gameSoundHandle", value: v7);
        KeyValues::SetInt(this: v14, keyName: "root", value: bInRoot);
        nItemID = this->m_pGameSoundList->AddItem(this: this->m_pGameSoundList, a2: v14, a3: 0, a4: false, a5: false);
        v15 = vgui::SoundEmitterSystem();
        pStr = (char *)v15->GetSoundName(this: v15, a2: v7);
        if ( CUtlString::Length(this: &this->m_GameSoundFilter) == 0
          || (v16 = CUtlString::Get(this: &this->m_GameSoundFilter),
              (v17 = (int)V_stristr(a1: pStr, a2: (const char *)this, pStr, pSearch: v16)) != 0) )
        {
          v17 = 1;
        }
        this->m_pGameSoundList->SetItemVisible(this: this->m_pGameSoundList, a2: nItemID, a3: v17);
        v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v18 != nullptr )
          v19 = KeyValues::KeyValues(this: v18, setName: "drag", firstKey: "text", firstValue: (char *)pSoundName);
        else
          v19 = nullptr;
        KeyValues::SetString(this: v19, keyName: "texttype", value: "gamesoundName");
        vgui::ListPanel::SetItemDragData(this: this->m_pGameSoundList, itemID: nItemID, data: v19);
        ++nTotalCount;
        v20 = vgui::SoundEmitterSystem();
        v7 = v20->Next(this: v20, a2: v7);
        v21 = vgui::SoundEmitterSystem();
      }
      while ( v7 != v21->InvalidIndex(this: v21) );
      v5 = nTotalCount;
    }
    this->m_pGameSoundList->SortList(this: this->m_pGameSoundList);
    if ( this->m_pGameSoundList->GetItemCount(this: this->m_pGameSoundList) > 0 )
    {
      v22 = this->m_pGameSoundList->GetItemIDFromRow(this: this->m_pGameSoundList, a2: 0);
      v23 = this->m_pGameSoundList;
      ++this->m_nSoundSuppressionCount;
      v23->SetSelectedCell(this: v23, a2: v22, a3: 0);
    }
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "%s (%d/%d)", "Game Sound", v5, v5);
    this->m_pGameSoundList->SetColumnHeaderText_2(this: this->m_pGameSoundList, a2: 0, a3: pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A48E0
// Name: private: void CSoundPicker::RefreshGameSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::RefreshGameSoundList(CSoundPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::ListPanel *m_pGameSoundList; // ecx
  int i; // edi
  KeyValues *v6; // ebx
  ISoundEmitterSystemBase *v7; // eax
  int v8; // eax
  int Int; // ebx
  ISoundEmitterSystemBase *v10; // eax
  ISoundEmitterSystemBase *v11; // eax
  const char *v12; // eax
  bool v13; // bl
  vgui::ListPanel *v14; // ecx
  void (__thiscall *SetItemVisible)(vgui::ListPanel *, int, bool); // edx
  int v16; // eax
  char pDest[512]; // [esp+4h] [ebp-210h] BYREF
  char *pStr; // [esp+204h] [ebp-10h]
  BOOL bIsVisible; // [esp+208h] [ebp-Ch]
  int nMatchingGameSounds; // [esp+20Ch] [ebp-8h]
  int nTotalCount; // [esp+210h] [ebp-4h]

  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr )
  {
    nMatchingGameSounds = 0;
    nTotalCount = 0;
    for ( i = ((int (__thiscall *)(vgui::ListPanel *, int))m_pGameSoundList->FirstItem)(a1: m_pGameSoundList, a2: a3);
          i != this->m_pGameSoundList->InvalidItemID(this: this->m_pGameSoundList);
          i = ((int (__thiscall *)(vgui::ListPanel *))this->m_pGameSoundList->NextItem)(a1: this->m_pGameSoundList) )
    {
      v6 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pGameSoundList->GetItem)(
                          a1: this->m_pGameSoundList,
                          a2: i,
                          a3: a2);
      v7 = vgui::SoundEmitterSystem();
      v8 = v7->InvalidIndex(this: v7);
      Int = KeyValues::GetInt(this: v6, keyName: "gameSoundHandle", defaultValue: v8);
      v10 = vgui::SoundEmitterSystem();
      if ( Int != v10->InvalidIndex(this: v10) )
      {
        v11 = vgui::SoundEmitterSystem();
        pStr = (char *)v11->GetSoundName(this: v11, a2: Int);
        v13 = true;
        if ( CUtlString::Length(this: &this->m_GameSoundFilter) != 0 )
        {
          v12 = CUtlString::Get(this: &this->m_GameSoundFilter);
          if ( V_stristr(a1: pStr, a2: (const char *)&this->m_GameSoundFilter, pStr, pSearch: v12) == nullptr )
            v13 = false;
        }
        v14 = this->m_pGameSoundList;
        SetItemVisible = v14->SetItemVisible;
        LOBYTE(bIsVisible) = v13;
        SetItemVisible(this: v14, a2: i, a3: bIsVisible);
        if ( v13 )
          ++nMatchingGameSounds;
        ++nTotalCount;
      }
      a2 = i;
    }
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "%s (%d/%d)", "Game Sound", nMatchingGameSounds, nTotalCount);
    ((void (__thiscall *)(vgui::ListPanel *, _DWORD))this->m_pGameSoundList->SetColumnHeaderText_2)(
      a1: this->m_pGameSoundList,
      a2: 0);
    if ( this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList) == 0
      && this->m_pGameSoundList->GetItemCount(this: this->m_pGameSoundList) > 0 )
    {
      v16 = this->m_pGameSoundList->GetItemIDFromRow(this: this->m_pGameSoundList, a2: 0);
      ++this->m_nSoundSuppressionCount;
      this->m_pGameSoundList->SetSelectedCell(this: this->m_pGameSoundList, a2: v16, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A4AA0
// Name: private: void CSoundPicker::OnGameSoundFilterTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::OnGameSoundFilterTextChanged(CSoundPicker *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  char *v4; // eax
  vgui::TextEntry_vtbl *v5; // [esp+Ch] [ebp-4h]

  v3 = this->m_pGameSoundFilter->GetTextLength(this: this->m_pGameSoundFilter);
  CUtlString::SetLength(this: &this->m_GameSoundFilter, nLen: v3);
  if ( v3 > 0 )
  {
    v5 = this->m_pGameSoundFilter->__vftable;
    ++v3;
    v4 = CUtlString::Get(this: &this->m_GameSoundFilter);
    v5->GetText_2(this: this->m_pGameSoundFilter, a2: v4, a3: v3);
  }
  CSoundPicker::RefreshGameSoundList(this, a2, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x104A4B10
// Name: private: virtual void CSoundPicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSoundPicker::OnTextChanged(CSoundPicker *this@<ecx>, int a2@<ebx>, KeyValues *pKeyValues)
{
  if ( KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr) == this->m_pGameSoundFilter )
    CSoundPicker::OnGameSoundFilterTextChanged(this, a2);
  else
    CBaseAssetPicker::OnTextChanged(this, a2, a3: (int)pKeyValues, pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x104A4B50
// Name: private: void CSoundPicker::PlayGameSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSoundPicker::PlayGameSound(CSoundPicker *this, const char *pSoundName)
{
  IEngineTool *v3; // eax
  ISoundEmitterSystemBase *v4; // eax
  IEngineTool *v5; // eax
  int v6; // [esp+2Ch] [ebp-B4h] BYREF
  int v7; // [esp+30h] [ebp-B0h]
  int v8; // [esp+34h] [ebp-ACh]
  int v9; // [esp+38h] [ebp-A8h]
  int v10; // [esp+3Ch] [ebp-A4h]
  int v11; // [esp+40h] [ebp-A0h]
  char v12; // [esp+44h] [ebp-9Ch]
  int v13; // [esp+48h] [ebp-98h]
  _BYTE v14[24]; // [esp+4Ch] [ebp-94h] BYREF
  _BYTE params_104[20]; // [esp+CCh] [ebp-14h] OVERLAPPED

  if ( this->m_nPlayingSound != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
  v8 = 100;
  v9 = 100;
  v10 = 100;
  v6 = 0;
  v7 = 1065353216;
  v11 = 75;
  v14[0] = 0;
  v12 = 0;
  v13 = 0;
  *(_DWORD *)params_104 = 0;
  *(_DWORD *)&params_104[8] = 1;
  *(_WORD *)&params_104[4] = -1;
  *(_DWORD *)&params_104[12] = 0;
  *(_DWORD *)&params_104[16] = -1;
  v4 = vgui::SoundEmitterSystem();
  if ( v4->GetParametersForSound(this: v4, a2: pSoundName, a3: (CSoundParameters *)&v6, a4: GENDER_NONE, a5: false) )
  {
    v5 = vgui::EngineTool();
    this->m_nPlayingSound = ((int (__thiscall *)(IEngineTool *, _DWORD, int, int, int, _BYTE *, int, int, Vector *, Vector *, _DWORD, int, _DWORD, _DWORD, int))v5->StartSound)(
                              a1: v5,
                              a2: 0,
                              a3: 1,
                              a4: -1,
                              a5: 6,
                              a6: v14,
                              a7: v7,
                              a8: v11,
                              a9: &vec3_origin,
                              a10: &vec3_origin,
                              a11: 0,
                              a12: v8,
                              a13: 0,
                              a14: (float)*(int *)params_104 * 0.001,
                              a15: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A4C70
// Name: private: virtual void CSoundPicker::OnNextSelectionIsDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnNextSelectionIsDefault(CSoundPicker *this)
{
  ++this->m_nSoundSuppressionCount;
}

//------------------------------------------------------------------------------
// Address: 0x104A4C80
// Name: public: enum CSoundPicker::PickType_t CSoundPicker::GetSelectedSoundType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundPicker::GetSelectedSoundType(CSoundPicker *this)
{
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    return 1;
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    return 2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104A4CE0
// Name: public: int CSoundPicker::GetSelectedSoundCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundPicker::GetSelectedSoundCount(CSoundPicker *this)
{
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    return this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList);
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    return CBaseAssetPicker::GetSelectedAssetCount(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104A4D50
// Name: public: char const __near * CSoundPicker::GetSelectedSoundName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundPicker::GetSelectedSoundName(CSoundPicker *this, int nSelectionIndex)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  KeyValues *v6; // eax

  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    v3 = this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList);
    if ( v3 != 0 )
    {
      v4 = nSelectionIndex;
      if ( nSelectionIndex < 0 )
        v4 = v3 - 1;
      v5 = this->m_pGameSoundList->GetSelectedItem(this: this->m_pGameSoundList, a2: v4);
      if ( v5 >= 0 )
      {
        v6 = this->m_pGameSoundList->GetItem(this: this->m_pGameSoundList, a2: v5);
        return KeyValues::GetString(this: v6, keyName: "gamesound", defaultValue: nullptr);
      }
    }
  }
  else if ( this->m_pWavPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
  {
    return (char *)CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104A4E10
// Name: public: virtual void CSoundPickerFrame::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::OnClose(CSoundPickerFrame *this)
{
  CBaseAssetPicker *m_pPicker; // esi
  IEngineTool *v3; // eax

  m_pPicker = this->m_pPicker;
  if ( *(_DWORD *)&m_pPicker[1].m_clrDragFrame != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: *(_DWORD *)&m_pPicker[1].m_clrDragFrame);
    m_pPicker[1].m_clrDragFrame = 0;
  }
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x104A4E50
// Name: public: void CSoundPickerFrame::DoModal(enum CSoundPicker::PickType_t,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::DoModal(
        CSoundPickerFrame *this,
        CSoundPicker::PickType_t initialType,
        const char *pInitialValue,
        KeyValues *pContextKeyValues)
{
  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 4u);
  if ( initialType != PICK_NONE && pInitialValue != nullptr )
    CSoundPicker::SetSelectedSound(this: (CSoundPicker *)this->m_pPicker, type: initialType, pSoundName: pInitialValue);
  CBaseAssetPickerFrame::DoModal(this, pKeyValues: pContextKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x104A4EA0
// Name: public: virtual void CSoundPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::OnCommand(CSoundPickerFrame *this, KeyValues *pCommand)
{
  CSoundPicker *m_pPicker; // ebx
  int SelectedSoundType; // eax
  char *SelectedSoundName; // eax
  unsigned int v6; // edi
  void *v7; // esp
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  KeyValues *Key; // eax
  int v11; // esi
  char *v12; // ebx
  void *v13; // esp
  CBaseAssetPickerFrame *v14; // esi
  char v15; // [esp+0h] [ebp-40h] BYREF
  char v16[11]; // [esp+1h] [ebp-3Fh] BYREF
  char pBuf[32]; // [esp+Ch] [ebp-34h] BYREF
  CBaseAssetPickerFrame *v18; // [esp+2Ch] [ebp-14h]
  CSoundPicker *pPicker; // [esp+30h] [ebp-10h]
  int len; // [esp+34h] [ebp-Ch]
  KeyValues *pActionKeys; // [esp+38h] [ebp-8h]
  int nSoundCount; // [esp+3Ch] [ebp-4h]
  char *pSoundList; // [esp+48h] [ebp+8h]
  KeyValues *pSoundLista; // [esp+48h] [ebp+8h]

  m_pPicker = (CSoundPicker *)this->m_pPicker;
  v18 = this;
  pPicker = m_pPicker;
  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Open") != 0 )
  {
    CBaseAssetPickerFrame::OnCommand(this, a2: (int)m_pPicker, pCommand);
  }
  else
  {
    SelectedSoundType = CSoundPicker::GetSelectedSoundType(this: m_pPicker);
    len = SelectedSoundType;
    if ( SelectedSoundType == 1 || SelectedSoundType == 2 )
    {
      SelectedSoundName = CSoundPicker::GetSelectedSoundName(this: m_pPicker, nSelectionIndex: -1);
      pSoundList = SelectedSoundName;
      if ( SelectedSoundName == nullptr )
      {
        this->CloseModal(this);
        return;
      }
      v6 = std::char_traits<char>::length(str: SelectedSoundName);
      v7 = alloca(v6 + 2);
      v15 = 35;
      V_strncpy(pDest: v16, pSrc: pSoundList, maxLen: v6 + 1);
      nSoundCount = CSoundPicker::GetSelectedSoundCount(this: m_pPicker);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "SoundSelected");
        pActionKeys = v9;
      }
      else
      {
        pActionKeys = nullptr;
        v9 = nullptr;
      }
      KeyValues::SetInt(this: v9, keyName: "count", value: nSoundCount);
      if ( len == 1 )
      {
        KeyValues::SetString(this: v9, keyName: "gamesound", value: &v15);
        if ( CBaseAssetPicker::IsMultiselectEnabled(this: m_pPicker) )
        {
          Key = KeyValues::FindKey(this: v9, keyName: "gamesounds", bCreate: true);
LABEL_14:
          pSoundLista = Key;
          if ( Key != nullptr )
          {
            v11 = 0;
            if ( nSoundCount > 0 )
            {
              while ( 1 )
              {
                V_snprintf(pDest: pBuf, maxLen: 0x20u, pFormat: "%d", v11);
                v12 = CSoundPicker::GetSelectedSoundName(this: m_pPicker, nSelectionIndex: v11);
                len = std::char_traits<char>::length(str: v12);
                v13 = alloca(len + 2);
                v15 = 35;
                V_strncpy(pDest: v16, pSrc: v12, maxLen: len + 1);
                KeyValues::SetString(this: pSoundLista, keyName: pBuf, value: &v15);
                if ( ++v11 >= nSoundCount )
                  break;
                m_pPicker = pPicker;
              }
              v9 = pActionKeys;
            }
          }
        }
      }
      else
      {
        KeyValues::SetString(this: v9, keyName: "wav", value: &v15);
        if ( CBaseAssetPicker::IsMultiselectEnabled(this: m_pPicker) )
        {
          Key = KeyValues::FindKey(this: v9, keyName: "wavs", bCreate: true);
          goto LABEL_14;
        }
      }
      v14 = v18;
      CBaseAssetPickerFrame::PostMessageAndClose(this: v18, pKeyValues: v9);
      v14->CloseModal(this: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A5080
// Name: public: virtual struct vgui::PanelMessageMap __near * CSoundPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSoundPickerFrame::GetMessageMap(CSoundPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSoundPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CSoundPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSoundPickerFrame");
  `CSoundPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A50B0
// Name: public: virtual struct PanelAnimationMap __near * CSoundPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSoundPickerFrame::GetAnimMap(CSoundPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CSoundPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104A50C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSoundPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSoundPickerFrame::GetKBMap(CSoundPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSoundPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPickerFrame::GetKBMap'::`2'::s_pMap;
  `CSoundPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPickerFrame");
  `CSoundPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A50F0
// Name: public: virtual void CSoundPicker::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::Activate(CSoundPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CBaseAssetPicker::Activate(this, a2, a3);
  if ( this->m_pGameSoundPage != nullptr )
    CSoundPicker::BuildGameSoundList(this, a2: a3, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x104A5110
// Name: private: virtual void CSoundPicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnPageChanged(CSoundPicker *this)
{
  IEngineTool *v2; // eax

  if ( this->m_nPlayingSound != 0 )
  {
    v2 = vgui::EngineTool();
    v2->StopSoundByGuid(this: v2, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pGameSoundFilter, status: true);
    this->m_pGameSoundFilter->RequestFocus(this: this->m_pGameSoundFilter, a2: 0);
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    CBaseAssetPicker::RequestFilterFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x104A51B0
// Name: private: virtual void CSoundPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnItemSelected(CSoundPicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pGameSoundList; // ecx
  unsigned __int8 m_nSoundSuppressionCount; // al
  char *SelectedSoundName; // eax
  char *v7; // ebx
  void *v8; // esp
  char v9; // [esp+0h] [ebp-Ch] BYREF
  char v10[11]; // [esp+1h] [ebp-Bh] BYREF
  unsigned int len; // [esp+14h] [ebp+8h]
  char len_3; // [esp+17h] [ebp+Bh]

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr && Ptr == m_pGameSoundList )
  {
    m_nSoundSuppressionCount = this->m_nSoundSuppressionCount;
    len_3 = 1;
    if ( m_nSoundSuppressionCount != 0 )
    {
      this->m_nSoundSuppressionCount = m_nSoundSuppressionCount - 1;
      len_3 = 0;
    }
    SelectedSoundName = CSoundPicker::GetSelectedSoundName(this, nSelectionIndex: -1);
    v7 = SelectedSoundName;
    if ( SelectedSoundName != nullptr && len_3 != 0 )
    {
      len = std::char_traits<char>::length(str: SelectedSoundName);
      v8 = alloca(len + 2);
      v9 = 35;
      V_strncpy(pDest: v10, pSrc: v7, maxLen: len + 1);
      CSoundPicker::PlayGameSound(this, pSoundName: &v9);
    }
  }
  else
  {
    CBaseAssetPicker::OnItemSelected(this, kv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A5290
// Name: private: void CSoundPicker::PlayWavSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::PlayWavSound(CSoundPicker *this, char *pSoundName)
{
  IEngineTool *v3; // eax
  IEngineTool *v4; // esi
  char *v5; // eax
  CFmtStrN<256> *v6; // eax
  IEngineTool *v7; // eax
  CFmtStrN<256> v8; // [esp+30h] [ebp-10Ch] BYREF

  if ( this->m_nPlayingSound != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
  if ( *pSoundName != 0 )
  {
    v4 = vgui::EngineTool();
    v5 = PSkipSoundChars(pch: pSoundName);
    v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "sound\\%s", v5);
    v4->ValidateSoundCache(this: v4, a2: v6->m_szBuf);
    v7 = vgui::EngineTool();
    this->m_nPlayingSound = ((int (__thiscall *)(IEngineTool *, _DWORD, int, int, int, char *, int, _DWORD, Vector *, Vector *, _DWORD, int, _DWORD, _DWORD, int))v7->StartSound)(
                              a1: v7,
                              a2: 0,
                              a3: 1,
                              a4: -1,
                              a5: 6,
                              a6: pSoundName,
                              a7: 1065353216,
                              a8: 0,
                              a9: &vec3_origin,
                              a10: &vec3_origin,
                              a11: 0,
                              a12: 100,
                              a13: 0,
                              a14: 0,
                              a15: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A5360
// Name: private: virtual void CSoundPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnSelectedAssetPicked(CSoundPicker *this, char *pAssetName)
{
  unsigned __int8 m_nSoundSuppressionCount; // al
  char v3; // dl

  m_nSoundSuppressionCount = this->m_nSoundSuppressionCount;
  v3 = 1;
  if ( m_nSoundSuppressionCount != 0 )
  {
    this->m_nSoundSuppressionCount = m_nSoundSuppressionCount - 1;
    v3 = 0;
  }
  if ( pAssetName != nullptr && v3 != 0 )
    CSoundPicker::PlayWavSound(this, pSoundName: pAssetName);
}

//------------------------------------------------------------------------------
// Address: 0x104A5390
// Name: public: static void CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A5420
// Name: public: static void CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A54B0
// Name: public: static void CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104A5540
// Name: public: CSoundPicker::CSoundPicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSoundPicker *__thiscall CSoundPicker::CSoundPicker(CSoundPicker *this, vgui::Panel *pParent, int nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::PropertyPage *v9; // eax
  vgui::PropertyPage *v10; // eax
  vgui::ListPanel *v11; // eax
  vgui::ListPanel *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "Sound Files",
    pExt: "wav",
    pSubDir: "sound",
    pTextType: "wavName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CSoundPicker_vtbl *)&CSoundPicker::`vftable';
  if ( `CSoundPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    v4->pfnClassName = CSoundPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CSoundPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSoundPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSoundPicker");
    v5->pfnClassName = CSoundPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CSoundPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPicker");
    v6->pfnClassName = CSoundPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_GameSoundFilter);
  this->m_nSoundSuppressionCount = 0;
  this->m_nPlayingSound = 0;
  v7 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(
           this: v7,
           parent: this,
           panelName: (vgui::Panel *)"ViewsSheet",
           draggableTabs: false);
  else
    v8 = nullptr;
  this->m_pViewsSheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->m_pGameSoundPage = nullptr;
  this->m_pGameSoundList = nullptr;
  if ( (nFlags & 1) != 0 )
  {
    v9 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v9 != nullptr )
      v10 = vgui::PropertyPage::PropertyPage(this: v9, parent: this->m_pViewsSheet, panelName: "GameSoundPage");
    else
      v10 = nullptr;
    this->m_pGameSoundPage = v10;
    v11 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v11 != nullptr )
      v12 = vgui::ListPanel::ListPanel(this: v11, parent: this->m_pGameSoundPage, panelName: "GameSoundsList");
    else
      v12 = nullptr;
    this->m_pGameSoundList = v12;
    v12->AddColumnHeader(this: v12, a2: 0, a3: "GameSound", a4: "Game Sound", a5: 52, a6: 0);
    this->m_pGameSoundList->AddActionSignalTarget_2(this: this->m_pGameSoundList, a2: this);
    this->m_pGameSoundList->SetSelectIndividualCells(this: this->m_pGameSoundList, a2: true);
    this->m_pGameSoundList->SetEmptyListText_2(this: this->m_pGameSoundList, a2: "No game sounds");
    this->m_pGameSoundList->SetDragEnabled(this: this->m_pGameSoundList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pGameSoundList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 0,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    this->m_pGameSoundList->SetSortFunc(this: this->m_pGameSoundList, a2: 0, a3: GameSoundSortFunc);
    this->m_pGameSoundList->SetSortColumn(this: this->m_pGameSoundList, a2: 0);
    vgui::ListPanel::SetMultiselectEnabled(this: this->m_pGameSoundList, bState: nFlags < 0);
    v13 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v13 != nullptr )
      v14 = vgui::TextEntry::TextEntry(
              this: v13,
              parent: this->m_pGameSoundPage,
              panelName: (vgui::Panel *)"GameSoundFilter");
    else
      v14 = nullptr;
    this->m_pGameSoundFilter = v14;
    v14->AddActionSignalTarget_2(this: v14, a2: this);
    this->m_pGameSoundPage->LoadControlSettings(
      this: this->m_pGameSoundPage,
      a2: "resource/soundpickergamesoundpage.res",
      a3: nullptr,
      a4: nullptr,
      a5: nullptr);
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: this->m_pGameSoundPage,
      a3: "Game Sounds",
      a4: nullptr,
      a5: false,
      a6: -1);
  }
  this->m_pWavPage = nullptr;
  if ( (nFlags & 2) != 0 )
  {
    v15 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v15 != nullptr )
      v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pViewsSheet, panelName: "WavPage");
    else
      v16 = nullptr;
    this->m_pWavPage = v16;
    CBaseAssetPicker::CreateStandardControls(this, pParent: v16, bAllowMultiselect: nFlags < 0);
    CBaseAssetPicker::AddExtension(this, pExtension: (CCullTreeNode *)"mp3");
    this->m_pWavPage->LoadControlSettings(
      this: this->m_pWavPage,
      a2: "resource/soundpickerwavpage.res",
      a3: nullptr,
      a4: nullptr,
      a5: nullptr);
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: this->m_pWavPage,
      a3: "WAVs",
      a4: nullptr,
      a5: false,
      a6: -1);
  }
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/soundpicker.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104A58B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSoundPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSoundPicker::GetMessageMap(CSoundPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSoundPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPicker::GetMessageMap'::`2'::s_pMap;
  `CSoundPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
  `CSoundPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A58E0
// Name: public: virtual struct PanelAnimationMap __near * CSoundPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSoundPicker::GetAnimMap(CSoundPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CSoundPicker");
}

//------------------------------------------------------------------------------
// Address: 0x104A58F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSoundPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSoundPicker::GetKBMap(CSoundPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSoundPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPicker::GetKBMap'::`2'::s_pMap;
  `CSoundPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPicker");
  `CSoundPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104A5990
// Name: public: CSoundPickerFrame::CSoundPickerFrame(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSoundPickerFrame *__thiscall CSoundPickerFrame::CSoundPickerFrame(
        CSoundPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        int nFlags)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CSoundPicker *v8; // eax
  CSoundPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CSoundPickerFrame_vtbl *)&CSoundPickerFrame::`vftable';
  if ( `CSoundPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSoundPickerFrame");
    v5->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CSoundPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSoundPickerFrame");
    v6->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CSoundPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPickerFrame");
    v7->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CSoundPicker *)operator new(nSize: 0x274u);
  if ( v8 != nullptr )
    v9 = CSoundPicker::CSoundPicker(this: v8, pParent: this, nFlags);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/soundpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004A4C90
// Name: public: static char const __near * CSoundPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSoundPicker::GetPanelClassName()
{
  return "CSoundPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004A4CA0
// Name: public: static char const __near * CSoundPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSoundPickerFrame::GetPanelClassName()
{
  return "CSoundPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004A4CB0
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A4D00
// Name: GameSoundSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl GameSoundSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  bool v3; // bl
  const char *String; // esi
  const char *v6; // eax

  v3 = KeyValues::GetInt(this: item1->kv, keyName: "root", defaultValue: 0) != 0;
  if ( v3 != (KeyValues::GetInt(this: item2->kv, keyName: "root", defaultValue: 0) != 0) )
    return 2 * !v3 - 1;
  String = KeyValues::GetString(this: item1->kv, keyName: "gamesound", defaultValue: defaultValue);
  v6 = KeyValues::GetString(this: item2->kv, keyName: "gamesound", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004A4D80
// Name: public: void CSoundPicker::SetSelectedSound(enum CSoundPicker::PickType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::SetSelectedSound(
        CSoundPicker *this,
        CSoundPicker::PickType_t type,
        const char *pSoundName)
{
  if ( type != PICK_NONE && pSoundName != nullptr )
  {
    if ( this->m_pGameSoundPage != nullptr && type == PICK_GAMESOUNDS )
    {
      this->m_pViewsSheet->SetActivePage(this: this->m_pViewsSheet, a2: this->m_pGameSoundPage);
      this->m_pGameSoundFilter->SetText(this: this->m_pGameSoundFilter, a2: pSoundName);
    }
    if ( this->m_pWavPage != nullptr && type == PICK_WAVFILES )
    {
      this->m_pViewsSheet->SetActivePage(this: this->m_pViewsSheet, a2: this->m_pWavPage);
      CBaseAssetPicker::SetInitialSelection(this, pAssetName: pSoundName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A4E00
// Name: public: virtual void CSoundPicker::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnKeyCodeTyped(CSoundPicker *this, KeyValues *code)
{
  KeyValues *v3; // eax
  vgui::IPanel *v4; // edi
  vgui::ListPanel *m_pGameSoundList; // ebx
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v8; // [esp+8h] [ebp-4h]
  KeyValues *pMsg; // [esp+14h] [ebp+8h]

  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage
    && (code == (KeyValues *)88 || code == (KeyValues *)90 || code == (KeyValues *)76 || code == (KeyValues *)77) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      pMsg = KeyValues::KeyValues(this: v3, setName: "KeyCodeTyped", firstKey: "code", firstValue: (int)code);
    else
      pMsg = nullptr;
    v4 = g_pVGuiPanel;
    v8 = g_pVGuiPanel->__vftable;
    m_pGameSoundList = this->m_pGameSoundList;
    v6 = this->GetVPanel(this);
    v7 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, int))m_pGameSoundList->GetVPanel)(
           a1: m_pGameSoundList,
           a2: pMsg,
           a3: v6);
    ((void (__thiscall *)(vgui::IPanel *, int))v8->SendMessage)(a1: v4, a2: v7);
    KeyValues::deleteThis(this: pMsg);
  }
  else
  {
    CBaseAssetPicker::OnKeyCodeTyped(this, (ButtonCode_t)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A4ED0
// Name: private: void CSoundPicker::BuildGameSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::BuildGameSoundList(CSoundPicker *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  vgui::ListPanel *m_pGameSoundList; // ecx
  int v5; // edi
  ISoundEmitterSystemBase *v6; // eax
  int v7; // esi
  ISoundEmitterSystemBase *v8; // eax
  ISoundEmitterSystemBase *v9; // eax
  char *v10; // edi
  int v11; // eax
  int v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // edi
  ISoundEmitterSystemBase *v15; // eax
  const char *v16; // eax
  int v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // edi
  ISoundEmitterSystemBase *v20; // eax
  ISoundEmitterSystemBase *v21; // eax
  int v22; // eax
  vgui::ListPanel *v23; // ecx
  char pDest[512]; // [esp+4h] [ebp-214h] BYREF
  char *pStr; // [esp+204h] [ebp-14h]
  const char *pSoundName; // [esp+208h] [ebp-10h]
  int nItemID; // [esp+20Ch] [ebp-Ch]
  int nTotalCount; // [esp+210h] [ebp-8h]
  bool bInRoot; // [esp+217h] [ebp-1h]

  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr )
  {
    ((void (__thiscall *)(vgui::ListPanel *, int, int))m_pGameSoundList->RemoveAll)(a1: m_pGameSoundList, a2, a3);
    v5 = 0;
    nTotalCount = 0;
    v6 = vgui::SoundEmitterSystem();
    v7 = v6->First(this: v6);
    v8 = vgui::SoundEmitterSystem();
    if ( v7 != v8->InvalidIndex(this: v8) )
    {
      do
      {
        v9 = vgui::SoundEmitterSystem();
        v10 = (char *)v9->GetSoundName(this: v9, a2: v7);
        pSoundName = v10;
        strchr(string: (unsigned __int8 *)v10, chr: 0x5Cu);
        if ( v11 != 0 || (strchr(string: (unsigned __int8 *)v10, chr: 0x2Fu), bInRoot = true, v12 != 0) )
          bInRoot = false;
        v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v13 != nullptr )
          v14 = KeyValues::KeyValues(this: v13, setName: "node", firstKey: "gamesound", firstValue: v10);
        else
          v14 = nullptr;
        KeyValues::SetInt(this: v14, keyName: "gameSoundHandle", value: v7);
        KeyValues::SetInt(this: v14, keyName: "root", value: bInRoot);
        nItemID = this->m_pGameSoundList->AddItem(this: this->m_pGameSoundList, a2: v14, a3: 0, a4: false, a5: false);
        v15 = vgui::SoundEmitterSystem();
        pStr = (char *)v15->GetSoundName(this: v15, a2: v7);
        if ( CUtlString::Length(this: &this->m_GameSoundFilter) == 0
          || (v16 = CUtlString::Get(this: &this->m_GameSoundFilter), (v17 = (int)V_stristr(pStr, pSearch: v16)) != 0) )
        {
          v17 = 1;
        }
        this->m_pGameSoundList->SetItemVisible(this: this->m_pGameSoundList, a2: nItemID, a3: v17);
        v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v18 != nullptr )
          v19 = KeyValues::KeyValues(this: v18, setName: "drag", firstKey: "text", firstValue: pSoundName);
        else
          v19 = nullptr;
        KeyValues::SetString(this: v19, keyName: "texttype", value: "gamesoundName");
        vgui::ListPanel::SetItemDragData(this: this->m_pGameSoundList, itemID: nItemID, data: v19);
        ++nTotalCount;
        v20 = vgui::SoundEmitterSystem();
        v7 = v20->Next(this: v20, a2: v7);
        v21 = vgui::SoundEmitterSystem();
      }
      while ( v7 != v21->InvalidIndex(this: v21) );
      v5 = nTotalCount;
    }
    this->m_pGameSoundList->SortList(this: this->m_pGameSoundList);
    if ( this->m_pGameSoundList->GetItemCount(this: this->m_pGameSoundList) > 0 )
    {
      v22 = this->m_pGameSoundList->GetItemIDFromRow(this: this->m_pGameSoundList, a2: 0);
      v23 = this->m_pGameSoundList;
      ++this->m_nSoundSuppressionCount;
      v23->SetSelectedCell(this: v23, a2: v22, a3: 0);
    }
    V_snprintf(pDest, maxLen: 512, pFormat: "%s (%d/%d)", "Game Sound", v5, v5);
    this->m_pGameSoundList->SetColumnHeaderText_2(this: this->m_pGameSoundList, a2: 0, a3: pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A5120
// Name: private: void CSoundPicker::RefreshGameSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::RefreshGameSoundList(CSoundPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  vgui::ListPanel *m_pGameSoundList; // ecx
  int i; // edi
  KeyValues *v6; // ebx
  ISoundEmitterSystemBase *v7; // eax
  int v8; // eax
  int Int; // ebx
  ISoundEmitterSystemBase *v10; // eax
  ISoundEmitterSystemBase *v11; // eax
  const char *v12; // eax
  bool v13; // bl
  vgui::ListPanel *v14; // ecx
  void (__thiscall *SetItemVisible)(vgui::ListPanel *, int, bool); // edx
  int v16; // eax
  char pDest[512]; // [esp+4h] [ebp-210h] BYREF
  char *pStr; // [esp+204h] [ebp-10h]
  BOOL bIsVisible; // [esp+208h] [ebp-Ch]
  int nMatchingGameSounds; // [esp+20Ch] [ebp-8h]
  int nTotalCount; // [esp+210h] [ebp-4h]

  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr )
  {
    nMatchingGameSounds = 0;
    nTotalCount = 0;
    for ( i = ((int (__thiscall *)(vgui::ListPanel *, int))m_pGameSoundList->FirstItem)(a1: m_pGameSoundList, a2: a3);
          i != this->m_pGameSoundList->InvalidItemID(this: this->m_pGameSoundList);
          i = ((int (__thiscall *)(vgui::ListPanel *))this->m_pGameSoundList->NextItem)(a1: this->m_pGameSoundList) )
    {
      v6 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pGameSoundList->GetItem)(
                          a1: this->m_pGameSoundList,
                          a2: i,
                          a3: a2);
      v7 = vgui::SoundEmitterSystem();
      v8 = v7->InvalidIndex(this: v7);
      Int = KeyValues::GetInt(this: v6, keyName: "gameSoundHandle", defaultValue: v8);
      v10 = vgui::SoundEmitterSystem();
      if ( Int != v10->InvalidIndex(this: v10) )
      {
        v11 = vgui::SoundEmitterSystem();
        pStr = (char *)v11->GetSoundName(this: v11, a2: Int);
        v13 = true;
        if ( CUtlString::Length(this: &this->m_GameSoundFilter) != 0 )
        {
          v12 = CUtlString::Get(this: &this->m_GameSoundFilter);
          if ( V_stristr(pStr, pSearch: v12) == nullptr )
            v13 = false;
        }
        v14 = this->m_pGameSoundList;
        SetItemVisible = v14->SetItemVisible;
        LOBYTE(bIsVisible) = v13;
        SetItemVisible(this: v14, a2: i, a3: bIsVisible);
        if ( v13 )
          ++nMatchingGameSounds;
        ++nTotalCount;
      }
      a2 = i;
    }
    V_snprintf(pDest, maxLen: 512, pFormat: "%s (%d/%d)", "Game Sound", nMatchingGameSounds, nTotalCount);
    ((void (__thiscall *)(vgui::ListPanel *, _DWORD))this->m_pGameSoundList->SetColumnHeaderText_2)(
      a1: this->m_pGameSoundList,
      a2: 0);
    if ( this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList) == 0
      && this->m_pGameSoundList->GetItemCount(this: this->m_pGameSoundList) > 0 )
    {
      v16 = this->m_pGameSoundList->GetItemIDFromRow(this: this->m_pGameSoundList, a2: 0);
      ++this->m_nSoundSuppressionCount;
      this->m_pGameSoundList->SetSelectedCell(this: this->m_pGameSoundList, a2: v16, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A52E0
// Name: private: void CSoundPicker::OnGameSoundFilterTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::OnGameSoundFilterTextChanged(CSoundPicker *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  char *v4; // eax
  vgui::TextEntry_vtbl *v5; // [esp+Ch] [ebp-4h]

  v3 = this->m_pGameSoundFilter->GetTextLength(this: this->m_pGameSoundFilter);
  CUtlString::SetLength(this: &this->m_GameSoundFilter, nLen: v3);
  if ( v3 > 0 )
  {
    v5 = this->m_pGameSoundFilter->__vftable;
    ++v3;
    v4 = CUtlString::Get(this: &this->m_GameSoundFilter);
    v5->GetText_2(this: this->m_pGameSoundFilter, a2: v4, a3: v3);
  }
  CSoundPicker::RefreshGameSoundList(this, a2, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004A5350
// Name: private: virtual void CSoundPicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSoundPicker::OnTextChanged(CSoundPicker *this@<ecx>, int a2@<ebx>, KeyValues *pKeyValues)
{
  if ( KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr) == this->m_pGameSoundFilter )
    CSoundPicker::OnGameSoundFilterTextChanged(this, a2);
  else
    CBaseAssetPicker::OnTextChanged(this, pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004A5390
// Name: private: void CSoundPicker::PlayGameSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::PlayGameSound(CSoundPicker *this, const char *pSoundName)
{
  IEngineTool *v3; // eax
  ISoundEmitterSystemBase *v4; // eax
  IEngineTool *v5; // eax
  CSoundParameters params; // [esp+40h] [ebp-B4h] BYREF

  if ( this->m_nPlayingSound != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
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
  v4 = vgui::SoundEmitterSystem();
  if ( v4->GetParametersForSound(this: v4, a2: pSoundName, a3: &params, a4: GENDER_NONE, a5: false) )
  {
    v5 = vgui::EngineTool();
    this->m_nPlayingSound = ((int (__thiscall *)(IEngineTool *, _DWORD, int, int, int, char *, _DWORD, soundlevel_t, Vector *, Vector *, _DWORD, int, _DWORD, _DWORD, int))v5->StartSound)(
                              a1: v5,
                              a2: 0,
                              a3: 1,
                              a4: -1,
                              a5: 6,
                              a6: params.soundname,
                              a7: LODWORD(params.volume),
                              a8: params.soundlevel,
                              a9: &vec3_origin,
                              a10: &vec3_origin,
                              a11: 0,
                              a12: params.pitch,
                              a13: 0,
                              a14: (float)params.delay_msec * 0.001,
                              a15: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A54B0
// Name: private: virtual void CSoundPicker::OnNextSelectionIsDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnNextSelectionIsDefault(CSoundPicker *this)
{
  ++this->m_nSoundSuppressionCount;
}

//------------------------------------------------------------------------------
// Address: 0x004A54C0
// Name: public: enum CSoundPicker::PickType_t CSoundPicker::GetSelectedSoundType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundPicker::GetSelectedSoundType(CSoundPicker *this)
{
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    return 1;
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    return 2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004A5520
// Name: public: int CSoundPicker::GetSelectedSoundCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundPicker::GetSelectedSoundCount(CSoundPicker *this)
{
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    return this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList);
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    return CBaseAssetPicker::GetSelectedAssetCount(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004A5590
// Name: public: char const __near * CSoundPicker::GetSelectedSoundName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundPicker::GetSelectedSoundName(CSoundPicker *this, int nSelectionIndex)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  KeyValues *v6; // eax

  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    v3 = this->m_pGameSoundList->GetSelectedItemsCount(this: this->m_pGameSoundList);
    if ( v3 != 0 )
    {
      v4 = nSelectionIndex;
      if ( nSelectionIndex < 0 )
        v4 = v3 - 1;
      v5 = this->m_pGameSoundList->GetSelectedItem(this: this->m_pGameSoundList, a2: v4);
      if ( v5 >= 0 )
      {
        v6 = this->m_pGameSoundList->GetItem(this: this->m_pGameSoundList, a2: v5);
        return KeyValues::GetString(this: v6, keyName: "gamesound", defaultValue: nullptr);
      }
    }
  }
  else if ( this->m_pWavPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
  {
    return CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004A5650
// Name: public: virtual void CSoundPickerFrame::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::OnClose(CSoundPickerFrame *this)
{
  CBaseAssetPicker *m_pPicker; // esi
  IEngineTool *v3; // eax

  m_pPicker = this->m_pPicker;
  if ( *(_DWORD *)&m_pPicker[1].m_clrDragFrame != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: *(_DWORD *)&m_pPicker[1].m_clrDragFrame);
    m_pPicker[1].m_clrDragFrame = 0;
  }
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A5690
// Name: public: void CSoundPickerFrame::DoModal(enum CSoundPicker::PickType_t,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::DoModal(
        CSoundPickerFrame *this,
        CSoundPicker::PickType_t initialType,
        const char *pInitialValue,
        KeyValues *pContextKeyValues)
{
  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 4u);
  if ( initialType != PICK_NONE && pInitialValue != nullptr )
    CSoundPicker::SetSelectedSound(this: (CSoundPicker *)this->m_pPicker, type: initialType, pSoundName: pInitialValue);
  CBaseAssetPickerFrame::DoModal(this, pKeyValues: pContextKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004A56E0
// Name: public: virtual void CSoundPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPickerFrame::OnCommand(CSoundPickerFrame *this, KeyValues *pCommand)
{
  CSoundPicker *m_pPicker; // ebx
  int SelectedSoundType; // eax
  const char *SelectedSoundName; // eax
  int v6; // edi
  void *v7; // esp
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  KeyValues *Key; // eax
  int v11; // esi
  const char *v12; // ebx
  void *v13; // esp
  CBaseAssetPickerFrame *v14; // esi
  char v15; // [esp+0h] [ebp-40h] BYREF
  char v16[11]; // [esp+1h] [ebp-3Fh] BYREF
  char pBuf[32]; // [esp+Ch] [ebp-34h] BYREF
  CBaseAssetPickerFrame *v18; // [esp+2Ch] [ebp-14h]
  CSoundPicker *pPicker; // [esp+30h] [ebp-10h]
  int len; // [esp+34h] [ebp-Ch]
  KeyValues *pActionKeys; // [esp+38h] [ebp-8h]
  int nSoundCount; // [esp+3Ch] [ebp-4h]
  KeyValues *pSoundList; // [esp+48h] [ebp+8h]
  KeyValues *pSoundLista; // [esp+48h] [ebp+8h]

  m_pPicker = (CSoundPicker *)this->m_pPicker;
  v18 = this;
  pPicker = m_pPicker;
  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Open") != 0 )
  {
    CBaseAssetPickerFrame::OnCommand(this, (const char *)pCommand);
  }
  else
  {
    SelectedSoundType = CSoundPicker::GetSelectedSoundType(this: m_pPicker);
    len = SelectedSoundType;
    if ( SelectedSoundType == 1 || SelectedSoundType == 2 )
    {
      SelectedSoundName = CSoundPicker::GetSelectedSoundName(this: m_pPicker, nSelectionIndex: -1);
      pSoundList = (KeyValues *)SelectedSoundName;
      if ( SelectedSoundName == nullptr )
      {
        this->CloseModal(this);
        return;
      }
      v6 = _V_strlen(str: SelectedSoundName);
      v7 = alloca(v6 + 2);
      v15 = 35;
      V_strncpy(pDest: v16, pSrc: (const char *)pSoundList, maxLen: v6 + 1);
      nSoundCount = CSoundPicker::GetSelectedSoundCount(this: m_pPicker);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "SoundSelected");
        pActionKeys = v9;
      }
      else
      {
        pActionKeys = nullptr;
        v9 = nullptr;
      }
      KeyValues::SetInt(this: v9, keyName: "count", value: nSoundCount);
      if ( len == 1 )
      {
        KeyValues::SetString(this: v9, keyName: "gamesound", value: &v15);
        if ( CBaseAssetPicker::IsMultiselectEnabled(this: m_pPicker) )
        {
          Key = KeyValues::FindKey(this: v9, keyName: "gamesounds", bCreate: true);
LABEL_14:
          pSoundLista = Key;
          if ( Key != nullptr )
          {
            v11 = 0;
            if ( nSoundCount > 0 )
            {
              while ( 1 )
              {
                V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%d", v11);
                v12 = CSoundPicker::GetSelectedSoundName(this: m_pPicker, nSelectionIndex: v11);
                len = _V_strlen(str: v12);
                v13 = alloca(len + 2);
                v15 = 35;
                V_strncpy(pDest: v16, pSrc: v12, maxLen: len + 1);
                KeyValues::SetString(this: pSoundLista, keyName: pBuf, value: &v15);
                if ( ++v11 >= nSoundCount )
                  break;
                m_pPicker = pPicker;
              }
              v9 = pActionKeys;
            }
          }
        }
      }
      else
      {
        KeyValues::SetString(this: v9, keyName: "wav", value: &v15);
        if ( CBaseAssetPicker::IsMultiselectEnabled(this: m_pPicker) )
        {
          Key = KeyValues::FindKey(this: v9, keyName: "wavs", bCreate: true);
          goto LABEL_14;
        }
      }
      v14 = v18;
      CBaseAssetPickerFrame::PostMessageAndClose(this: v18, pKeyValues: v9);
      v14->CloseModal(this: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A58C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSoundPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSoundPickerFrame::GetMessageMap(CSoundPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSoundPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CSoundPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSoundPickerFrame");
  `CSoundPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A58F0
// Name: public: virtual struct PanelAnimationMap __near * CSoundPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSoundPickerFrame::GetAnimMap(CSoundPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CSoundPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004A5900
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSoundPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSoundPickerFrame::GetKBMap(CSoundPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSoundPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPickerFrame::GetKBMap'::`2'::s_pMap;
  `CSoundPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPickerFrame");
  `CSoundPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A5930
// Name: public: virtual void CSoundPicker::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundPicker::Activate(CSoundPicker *this@<ecx>, int a2@<edi>)
{
  CBaseAssetPicker::Activate(this);
  if ( this->m_pGameSoundPage != nullptr )
    CSoundPicker::BuildGameSoundList(this, a2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x004A5950
// Name: private: virtual void CSoundPicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnPageChanged(CSoundPicker *this)
{
  IEngineTool *v2; // eax

  if ( this->m_nPlayingSound != 0 )
  {
    v2 = vgui::EngineTool();
    v2->StopSoundByGuid(this: v2, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
  if ( this->m_pGameSoundPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pGameSoundPage )
  {
    vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pGameSoundFilter, status: true);
    this->m_pGameSoundFilter->RequestFocus(this: this->m_pGameSoundFilter, a2: 0);
  }
  if ( this->m_pWavPage != nullptr && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pWavPage )
    CBaseAssetPicker::RequestFilterFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A59F0
// Name: private: virtual void CSoundPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnItemSelected(CSoundPicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pGameSoundList; // ecx
  unsigned __int8 m_nSoundSuppressionCount; // al
  const char *SelectedSoundName; // eax
  const char *v7; // ebx
  void *v8; // esp
  char v9; // [esp+0h] [ebp-Ch] BYREF
  char v10[11]; // [esp+1h] [ebp-Bh] BYREF
  int len; // [esp+14h] [ebp+8h]
  char len_3; // [esp+17h] [ebp+Bh]

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pGameSoundList = this->m_pGameSoundList;
  if ( m_pGameSoundList != nullptr && Ptr == m_pGameSoundList )
  {
    m_nSoundSuppressionCount = this->m_nSoundSuppressionCount;
    len_3 = 1;
    if ( m_nSoundSuppressionCount != 0 )
    {
      this->m_nSoundSuppressionCount = m_nSoundSuppressionCount - 1;
      len_3 = 0;
    }
    SelectedSoundName = CSoundPicker::GetSelectedSoundName(this, nSelectionIndex: -1);
    v7 = SelectedSoundName;
    if ( SelectedSoundName != nullptr && len_3 != 0 )
    {
      len = _V_strlen(str: SelectedSoundName);
      v8 = alloca(len + 2);
      v9 = 35;
      V_strncpy(pDest: v10, pSrc: v7, maxLen: len + 1);
      CSoundPicker::PlayGameSound(this, pSoundName: &v9);
    }
  }
  else
  {
    CBaseAssetPicker::OnItemSelected(this, kv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A5AD0
// Name: private: void CSoundPicker::PlayWavSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::PlayWavSound(CSoundPicker *this, char *pSoundName)
{
  IEngineTool *v3; // eax
  IEngineTool *v4; // esi
  char *v5; // eax
  CFmtStrN<256> *v6; // eax
  IEngineTool *v7; // eax
  CFmtStrN<256> v8; // [esp+38h] [ebp-10Ch] BYREF

  if ( this->m_nPlayingSound != 0 )
  {
    v3 = vgui::EngineTool();
    v3->StopSoundByGuid(this: v3, a2: this->m_nPlayingSound);
    this->m_nPlayingSound = 0;
  }
  if ( *pSoundName != 0 )
  {
    v4 = vgui::EngineTool();
    v5 = PSkipSoundChars(pch: pSoundName);
    v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "sound\\%s", v5);
    v4->ValidateSoundCache(this: v4, a2: v6->m_szBuf);
    v7 = vgui::EngineTool();
    this->m_nPlayingSound = ((int (__thiscall *)(IEngineTool *, _DWORD, int, int, int, char *, int, _DWORD, Vector *, Vector *, _DWORD, int, _DWORD, _DWORD, int))v7->StartSound)(
                              a1: v7,
                              a2: 0,
                              a3: 1,
                              a4: -1,
                              a5: 6,
                              a6: pSoundName,
                              a7: 1065353216,
                              a8: 0,
                              a9: &vec3_origin,
                              a10: &vec3_origin,
                              a11: 0,
                              a12: 100,
                              a13: 0,
                              a14: 0,
                              a15: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A5BA0
// Name: private: virtual void CSoundPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPicker::OnSelectedAssetPicked(CSoundPicker *this, char *pAssetName)
{
  unsigned __int8 m_nSoundSuppressionCount; // al
  char v3; // dl

  m_nSoundSuppressionCount = this->m_nSoundSuppressionCount;
  v3 = 1;
  if ( m_nSoundSuppressionCount != 0 )
  {
    this->m_nSoundSuppressionCount = m_nSoundSuppressionCount - 1;
    v3 = 0;
  }
  if ( pAssetName != nullptr && v3 != 0 )
    CSoundPicker::PlayWavSound(this, pSoundName: pAssetName);
}

//------------------------------------------------------------------------------
// Address: 0x004A5BD0
// Name: public: static void CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A5C60
// Name: public: static void CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A5CF0
// Name: public: static void CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A5D80
// Name: public: CSoundPicker::CSoundPicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSoundPicker *__thiscall CSoundPicker::CSoundPicker(CSoundPicker *this, vgui::Panel *pParent, int nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::PropertyPage *v9; // eax
  vgui::PropertyPage *v10; // eax
  vgui::ListPanel *v11; // eax
  vgui::ListPanel *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertyPage *v16; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "Sound Files",
    pExt: "wav",
    pSubDir: "sound",
    pTextType: "wavName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CSoundPicker_vtbl *)&CSoundPicker::`vftable';
  if ( `CSoundPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
    v4->pfnClassName = CSoundPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CSoundPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSoundPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSoundPicker");
    v5->pfnClassName = CSoundPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CSoundPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPicker");
    v6->pfnClassName = CSoundPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CSoundPicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CSoundPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CSoundPicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_GameSoundFilter);
  this->m_nSoundSuppressionCount = 0;
  this->m_nPlayingSound = 0;
  v7 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "ViewsSheet", draggableTabs: false);
  else
    v8 = nullptr;
  this->m_pViewsSheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->m_pGameSoundPage = nullptr;
  this->m_pGameSoundList = nullptr;
  if ( (nFlags & 1) != 0 )
  {
    v9 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v9 != nullptr )
      v10 = vgui::PropertyPage::PropertyPage(this: v9, parent: this->m_pViewsSheet, panelName: "GameSoundPage");
    else
      v10 = nullptr;
    this->m_pGameSoundPage = v10;
    v11 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v11 != nullptr )
      v12 = vgui::ListPanel::ListPanel(this: v11, parent: this->m_pGameSoundPage, panelName: "GameSoundsList");
    else
      v12 = nullptr;
    this->m_pGameSoundList = v12;
    v12->AddColumnHeader(this: v12, a2: 0, a3: "GameSound", a4: "Game Sound", a5: 52, a6: 0);
    this->m_pGameSoundList->AddActionSignalTarget_2(this: this->m_pGameSoundList, a2: this);
    this->m_pGameSoundList->SetSelectIndividualCells(this: this->m_pGameSoundList, a2: true);
    this->m_pGameSoundList->SetEmptyListText_2(this: this->m_pGameSoundList, a2: "No game sounds");
    this->m_pGameSoundList->SetDragEnabled(this: this->m_pGameSoundList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pGameSoundList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 0,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    this->m_pGameSoundList->SetSortFunc(this: this->m_pGameSoundList, a2: 0, a3: GameSoundSortFunc);
    this->m_pGameSoundList->SetSortColumn(this: this->m_pGameSoundList, a2: 0);
    vgui::ListPanel::SetMultiselectEnabled(this: this->m_pGameSoundList, bState: nFlags < 0);
    v13 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v13 != nullptr )
      v14 = vgui::TextEntry::TextEntry(this: v13, parent: this->m_pGameSoundPage, panelName: "GameSoundFilter");
    else
      v14 = nullptr;
    this->m_pGameSoundFilter = v14;
    v14->AddActionSignalTarget_2(this: v14, a2: this);
    this->m_pGameSoundPage->LoadControlSettings(
      this: this->m_pGameSoundPage,
      a2: "resource/soundpickergamesoundpage.res",
      a3: nullptr,
      a4: nullptr,
      a5: nullptr);
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: this->m_pGameSoundPage,
      a3: "Game Sounds",
      a4: nullptr,
      a5: false,
      a6: -1);
  }
  this->m_pWavPage = nullptr;
  if ( (nFlags & 2) != 0 )
  {
    v15 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v15 != nullptr )
      v16 = vgui::PropertyPage::PropertyPage(this: v15, parent: this->m_pViewsSheet, panelName: "WavPage");
    else
      v16 = nullptr;
    this->m_pWavPage = v16;
    CBaseAssetPicker::CreateStandardControls(this, pParent: v16, bAllowMultiselect: nFlags < 0);
    CBaseAssetPicker::AddExtension(this, pExtension: "mp3");
    this->m_pWavPage->LoadControlSettings(
      this: this->m_pWavPage,
      a2: "resource/soundpickerwavpage.res",
      a3: nullptr,
      a4: nullptr,
      a5: nullptr);
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: this->m_pWavPage,
      a3: "WAVs",
      a4: nullptr,
      a5: false,
      a6: -1);
  }
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/soundpicker.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A60F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSoundPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSoundPicker::GetMessageMap(CSoundPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSoundPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPicker::GetMessageMap'::`2'::s_pMap;
  `CSoundPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSoundPicker");
  `CSoundPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A6120
// Name: public: virtual struct PanelAnimationMap __near * CSoundPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSoundPicker::GetAnimMap(CSoundPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CSoundPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004A6130
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSoundPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSoundPicker::GetKBMap(CSoundPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSoundPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSoundPicker::GetKBMap'::`2'::s_pMap;
  `CSoundPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPicker");
  `CSoundPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A61D0
// Name: public: CSoundPickerFrame::CSoundPickerFrame(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSoundPickerFrame *__thiscall CSoundPickerFrame::CSoundPickerFrame(
        CSoundPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        int nFlags)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CSoundPicker *v8; // eax
  CSoundPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CSoundPickerFrame_vtbl *)&CSoundPickerFrame::`vftable';
  if ( `CSoundPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSoundPickerFrame");
    v5->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CSoundPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSoundPickerFrame");
    v6->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CSoundPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSoundPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSoundPickerFrame");
    v7->pfnClassName = CSoundPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CSoundPicker *)MemAlloc_Alloc(nSize: 0x274u);
  if ( v8 != nullptr )
    v9 = CSoundPicker::CSoundPicker(this: v8, pParent: this, nFlags);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/soundpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

} // namespace sceneviewer
