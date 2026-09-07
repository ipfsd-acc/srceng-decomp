// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_demoactioneditors.cpp
// Functions: 64
// ============================================================

#include "engine\cl_demoactioneditors.h"

//------------------------------------------------------------------------------
// Address: 0x10077C80
// Name: public: static char const __near * CBaseActionEditDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseActionEditDialog::GetPanelClassName()
{
  return "CBaseActionEditDialog";
}

//------------------------------------------------------------------------------
// Address: 0x10077C90
// Name: public: virtual void CBaseActionEditDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionEditDialog::Init(CBaseActionEditDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  const char *ActionName; // eax
  vgui::ComboBox_vtbl *v4; // edi
  DEMOACTIONTIMINGTYPE Socket; // eax
  __int32 v6; // eax
  vgui::TextEntry_vtbl *v7; // edi
  double StartTime; // st7
  char *v9; // eax
  vgui::TextEntry_vtbl *v10; // edi
  int StartTick; // eax
  char *v12; // eax

  v2 = this->m_pActionName->__vftable;
  ActionName = CBaseDemoAction::GetActionName(this: this->m_pAction);
  v2->SetText(this: this->m_pActionName, a2: ActionName);
  v4 = this->m_pStartType->__vftable;
  Socket = CNetChan::GetSocket(this: this->m_pAction);
  v4->ActivateItem(this: this->m_pStartType, a2: Socket);
  v6 = CNetChan::GetSocket(this: this->m_pAction) - 1;
  if ( v6 != 0 )
  {
    if ( v6 == 1 )
    {
      v7 = this->m_pStart->__vftable;
      StartTime = CBaseDemoAction::GetStartTime(this: this->m_pAction);
      v9 = va(format: "%.3f", StartTime);
      v7->SetText(this: this->m_pStart, a2: v9);
    }
    else
    {
      this->m_pStart->SetText(this: this->m_pStart, a2: defaultValue);
    }
  }
  else
  {
    v10 = this->m_pStart->__vftable;
    StartTick = CBaseDemoAction::GetStartTick(this: this->m_pAction);
    v12 = va(format: "%i", StartTick);
    v10->SetText(this: this->m_pStart, a2: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077D70
// Name: public: virtual bool CBaseActionEditDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CBaseActionEditDialog::OnSaveChanges(CBaseActionEditDialog *this)
{
  vgui::TextEntry *m_pActionName; // ecx
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // eax
  char v4; // bl
  const char *ActionName; // eax
  Color v6; // edi
  int v7; // edi
  double StartTime; // st7
  Color v10; // edi
  char name[28]; // [esp+10h] [ebp-604h] BYREF
  char starttype[512]; // [esp+2Ch] [ebp-5E8h] BYREF
  char starttext[512]; // [esp+22Ch] [ebp-3E8h] BYREF
  float actionname_484; // [esp+610h] [ebp-4h] OVERLAPPED

  m_pActionName = this->m_pActionName;
  GetText_2 = m_pActionName->GetText_2;
  v4 = 0;
  g_BaseActionEditSaveChained = true;
  GetText_2(this: m_pActionName, a2: &starttext[484], a3: 512);
  ActionName = CBaseDemoAction::GetActionName(this: this->m_pAction);
  if ( _V_strcmp(s1: ActionName, s2: &starttext[484]) != 0 )
  {
    v4 = 1;
    CBaseDemoAction::SetActionName(this: this->m_pAction, name: &starttext[484]);
  }
  this->m_pStart->GetText_2(this: this->m_pStart, a2: &starttype[484], a3: 512);
  this->m_pStartType->GetText_2(this: this->m_pStartType, a2: name, a3: 512);
  v6 = (Color)CBaseDemoAction::TimingTypeForName(name);
  if ( v6 != CNetChan::GetSocket(this: this->m_pAction) )
  {
    v4 = 1;
    CBaseDemoAction::SetTimingType(this: (vgui::Panel *)this->m_pAction, color: v6);
  }
  v7 = *(_DWORD *)&v6 - 1;
  if ( v7 != 0 )
  {
    if ( v7 == 1 )
    {
      actionname_484 = atof(nptr: &starttype[484]);
      StartTime = CBaseDemoAction::GetStartTime(this: this->m_pAction);
      if ( actionname_484 != StartTime )
      {
        CBaseDemoAction::SetStartTime(this: this->m_pAction, t: actionname_484);
        return 1;
      }
    }
  }
  else
  {
    v10 = (Color)atoi(nptr: &starttype[484]);
    if ( v10 != CBaseDemoAction::GetStartTick(this: this->m_pAction) )
    {
      CBaseDemoAction::SetStartTick(this: (vgui::Panel *)this->m_pAction, color: v10);
      return 1;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10077ED0
// Name: public: virtual void CBaseActionEditDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionEditDialog::OnClose(CBaseActionEditDialog *this)
{
  bool (__thiscall *OnSaveChanges)(CBaseActionEditDialog *); // eax

  if ( this->m_bNewAction )
    demoaction->AddAction(this: demoaction, a2: this->m_pAction);
  OnSaveChanges = this->OnSaveChanges;
  g_BaseActionEditSaveChained = false;
  if ( OnSaveChanges(this) || this->m_bNewAction )
  {
    demoaction->SetDirty(this: demoaction, a2: true);
    CDemoEditorPanel::OnVDMChanged(this: this->m_pEditor);
  }
  this->MarkForDeletion(this);
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x10077F40
// Name: public: virtual void CBaseActionEditDialog::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionEditDialog::OnCancel(CBaseActionEditDialog *this)
{
  CBaseDemoAction *m_pAction; // ecx

  if ( this->m_bNewAction )
  {
    m_pAction = this->m_pAction;
    if ( m_pAction != nullptr )
      ((void (__thiscall *)(CBaseDemoAction *, int))m_pAction->dtr_CBaseDemoAction)(a1: m_pAction, a2: 1);
  }
  this->MarkForDeletion(this);
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x10077F80
// Name: public: virtual void CBaseActionEditDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionEditDialog::OnCommand(CBaseActionEditDialog *this, const char *commands)
{
  if ( V_strcasecmp(s1: commands, s2: "OK") != 0 )
  {
    if ( V_strcasecmp(s1: commands, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: commands);
    else
      this->OnCancel(this);
  }
  else
  {
    this->OnClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077FE0
// Name: public: virtual void CBaseActionSkipAheadDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionSkipAheadDialog::Init(CBaseActionSkipAheadDialog *this)
{
  void (__thiscall *SetText)(vgui::TextEntry *, const char *); // eax
  vgui::TextEntry_vtbl *v3; // edi
  char *v4; // eax

  this->LoadControlSettings(this, a2: "resource\\BaseActionSkipAheadDialog.res", a3: nullptr, a4: nullptr, a5: nullptr);
  CBaseActionEditDialog::Init(this);
  SetText = this->m_pSkipType->SetText;
  if ( LOBYTE(this->m_pAction[1].__vftable) != 0 )
  {
    ((void (__stdcall *)(const char *))SetText)(a1: "TimeUseTick");
    v3 = this->m_pSkip->__vftable;
    v4 = va(format: "%i", this->m_pAction[1].m_Type);
  }
  else
  {
    ((void (__stdcall *)(const char *))SetText)(a1: "TimeUseClock");
    v3 = this->m_pSkip->__vftable;
    v4 = va(format: "%.3f", *(float *)&this->m_pAction[1].m_bActionFired);
  }
  v3->SetText(this: this->m_pSkip, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100780A0
// Name: public: virtual void CBaseActionScreenFadeStartDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionScreenFadeStartDialog::Init(CBaseActionScreenFadeStartDialog *this)
{
  const char *SoundName; // eax
  int v3; // edi
  int v4; // ebx
  __int16 v5; // cx
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  bool v9; // [esp+14h] [ebp-24h]
  bool v10; // [esp+18h] [ebp-20h]
  bool v11; // [esp+1Ch] [ebp-1Ch]
  bool v12; // [esp+20h] [ebp-18h]
  bool v13; // [esp+24h] [ebp-14h]
  int v14; // [esp+28h] [ebp-10h]
  int v15; // [esp+2Ch] [ebp-Ch]
  float fadepurge; // [esp+30h] [ebp-8h]
  vgui::TextEntry_vtbl *fadepurgea; // [esp+30h] [ebp-8h]
  vgui::TextEntry_vtbl *fadestayout; // [esp+34h] [ebp-4h]
  vgui::TextEntry_vtbl *fadestayouta; // [esp+34h] [ebp-4h]

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionScreenFadeStartDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  v3 = *((unsigned __int8 *)SoundName + 6);
  v4 = *((unsigned __int8 *)SoundName + 7);
  v13 = SoundName[4] & 1;
  v5 = *((_WORD *)SoundName + 2);
  fadepurge = 0.001953125 * (double)*((unsigned __int16 *)SoundName + 1);
  v12 = (v5 & 2) != 0;
  v11 = (v5 & 4) != 0;
  v9 = (v5 & 0x10) != 0;
  v10 = (v5 & 8) != 0;
  v14 = *((unsigned __int8 *)SoundName + 8);
  v15 = *((unsigned __int8 *)SoundName + 9);
  fadestayout = this->m_pDuration->__vftable;
  v6 = va(format: "%.3f", (double)*(unsigned __int16 *)SoundName * 0.001953125);
  fadestayout->SetText(this: this->m_pDuration, a2: v6);
  fadestayouta = this->m_pHoldTime->__vftable;
  v7 = va(format: "%.3f", fadepurge);
  fadestayouta->SetText(this: this->m_pHoldTime, a2: v7);
  fadepurgea = this->m_pColor->__vftable;
  v8 = va(format: "%i %i %i %i", v3, v4, v14, v15);
  fadepurgea->SetText(this: this->m_pColor, a2: v8);
  this->m_pFFADE_IN->SetSelected(this: this->m_pFFADE_IN, a2: v13);
  this->m_pFFADE_OUT->SetSelected(this: this->m_pFFADE_OUT, a2: v12);
  this->m_pFFADE_MODULATE->SetSelected(this: this->m_pFFADE_MODULATE, a2: v11);
  this->m_pFFADE_STAYOUT->SetSelected(this: this->m_pFFADE_STAYOUT, a2: v10);
  this->m_pFFADE_PURGE->SetSelected(this: this->m_pFFADE_PURGE, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10078240
// Name: private: void CBaseActionTextMessageStartDialog::FillInFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionTextMessageStartDialog::FillInFonts(CBaseActionTextMessageStartDialog *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  vgui::ComboBox_vtbl *v7; // edi
  const char *Name; // eax
  KeyValues *schemeFile; // [esp+4h] [ebp-4h]

  this->m_pFontName->AddItem_2(this: this->m_pFontName, a2: "TextMessageDefault", a3: nullptr);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "Fonts");
    schemeFile = v3;
    if ( v3 != nullptr )
    {
      if ( g_pFileSystem != nullptr )
        v4 = &g_pFileSystem->IBaseFileSystem;
      else
        v4 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v3,
             filesystem: v4,
             resourceName: "resource/SourceScheme.res",
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        Key = KeyValues::FindKey(this: v3, keyName: "Fonts", bCreate: true);
        FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
        if ( FirstSubKey != nullptr )
        {
          do
          {
            v7 = this->m_pFontName->__vftable;
            Name = KeyValues::GetName(this: FirstSubKey);
            v7->AddItem_2(this: this->m_pFontName, a2: Name, a3: nullptr);
            FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          }
          while ( FirstSubKey != nullptr );
          v3 = schemeFile;
        }
      }
      KeyValues::deleteThis(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078310
// Name: private: bool CBaseActionTextMessageStartDialog::SaveDifferingColor(class vgui::TextEntry __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionTextMessageStartDialog::SaveDifferingColor(
        CBaseActionTextMessageStartDialog *this,
        vgui::TextEntry *control,
        unsigned __int8 *r,
        unsigned __int8 *g,
        unsigned __int8 *b,
        unsigned __int8 *a)
{
  char v6; // bl
  char sz[512]; // [esp+4h] [ebp-20Ch] BYREF
  int gg; // [esp+204h] [ebp-Ch] BYREF
  int aa; // [esp+208h] [ebp-8h] BYREF
  int bb; // [esp+20Ch] [ebp-4h] BYREF

  v6 = 0;
  control->GetText_2(this: control, a2: sz, a3: 512);
  if ( sscanf(string: sz, format: "%i %i %i %i", &control, &gg, &bb, &aa) != 4 )
    return v6;
  if ( (vgui::TextEntry *)*r != control )
  {
    v6 = 1;
    *r = (unsigned __int8)control;
  }
  if ( *g != gg )
  {
    v6 = 1;
    *g = gg;
  }
  if ( *b != bb )
  {
    v6 = 1;
    *b = bb;
  }
  if ( *a == aa )
    return v6;
  *a = aa;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100783C0
// Name: public: virtual bool CBaseActionTextMessageStartDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionTextMessageStartDialog::OnSaveChanges(CBaseActionTextMessageStartDialog *this)
{
  char v2; // bl
  client_textmessage_t *TextMessage; // eax
  vgui::TextEntry *m_pFadeInTime; // ecx
  client_textmessage_t *v5; // esi
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // eax
  long double v7; // st7
  char v8; // al
  vgui::TextEntry *m_pFadeOutTime; // ecx
  void (__thiscall *v10)(vgui::TextEntry *, char *, int); // edx
  char v11; // bl
  long double v12; // st7
  char v13; // al
  vgui::TextEntry *m_pHoldTime; // ecx
  void (__thiscall *v15)(vgui::TextEntry *, char *, int); // edx
  char v16; // bl
  long double v17; // st7
  char v18; // al
  vgui::TextEntry *m_pFXTime; // ecx
  void (__thiscall *v20)(vgui::TextEntry *, char *, int); // edx
  char v21; // bl
  long double v22; // st7
  char v23; // al
  vgui::TextEntry *m_pX; // ecx
  void (__thiscall *v25)(vgui::TextEntry *, char *, int); // edx
  char v26; // bl
  long double v27; // st7
  char v28; // al
  vgui::TextEntry *m_pY; // ecx
  void (__thiscall *v30)(vgui::TextEntry *, char *, int); // edx
  char v31; // bl
  long double v32; // st7
  bool v33; // al
  char v34; // bl
  char v35; // bl
  bool v36; // zf
  float v37; // eax
  const char *SoundName; // eax
  const char *FontName; // eax
  char sz[1024]; // [esp+Ch] [ebp-608h] BYREF
  char nptr[512]; // [esp+40Ch] [ebp-208h] BYREF
  float v43; // [esp+60Ch] [ebp-8h]
  char v44; // [esp+613h] [ebp-1h]

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  TextMessage = CDemoActionTextMessageStart::GetTextMessage(this: (CDemoActionTextMessageStart *)this->m_pAction);
  m_pFadeInTime = this->m_pFadeInTime;
  v5 = TextMessage;
  GetText_2 = m_pFadeInTime->GetText_2;
  v44 = 0;
  GetText_2(this: m_pFadeInTime, a2: nptr, a3: 512);
  v7 = atof(nptr);
  v43 = v7;
  if ( v7 == v5->fadein )
  {
    v8 = v44;
  }
  else
  {
    v5->fadein = v43;
    v8 = 1;
  }
  m_pFadeOutTime = this->m_pFadeOutTime;
  v10 = m_pFadeOutTime->GetText_2;
  v11 = v8 | v2;
  v44 = 0;
  v10(this: m_pFadeOutTime, a2: nptr, a3: 512);
  v12 = atof(nptr);
  v43 = v12;
  if ( v12 == v5->fadeout )
  {
    v13 = v44;
  }
  else
  {
    v5->fadeout = v43;
    v13 = 1;
  }
  m_pHoldTime = this->m_pHoldTime;
  v15 = m_pHoldTime->GetText_2;
  v16 = v13 | v11;
  v44 = 0;
  v15(this: m_pHoldTime, a2: nptr, a3: 512);
  v17 = atof(nptr);
  v43 = v17;
  if ( v17 == v5->holdtime )
  {
    v18 = v44;
  }
  else
  {
    v5->holdtime = v43;
    v18 = 1;
  }
  m_pFXTime = this->m_pFXTime;
  v20 = m_pFXTime->GetText_2;
  v21 = v18 | v16;
  v44 = 0;
  v20(this: m_pFXTime, a2: nptr, a3: 512);
  v22 = atof(nptr);
  v43 = v22;
  if ( v22 == v5->fxtime )
  {
    v23 = v44;
  }
  else
  {
    v5->fxtime = v43;
    v23 = 1;
  }
  m_pX = this->m_pX;
  v25 = m_pX->GetText_2;
  v26 = v23 | v21;
  v44 = 0;
  v25(this: m_pX, a2: nptr, a3: 512);
  v27 = atof(nptr);
  v43 = v27;
  if ( v27 == v5->x )
  {
    v28 = v44;
  }
  else
  {
    v5->x = v43;
    v28 = 1;
  }
  m_pY = this->m_pY;
  v30 = m_pY->GetText_2;
  v31 = v28 | v26;
  v44 = 0;
  v30(this: m_pY, a2: nptr, a3: 512);
  v32 = atof(nptr);
  v43 = v32;
  if ( v32 != v5->y )
  {
    v5->y = v43;
    v44 = 1;
  }
  v33 = CBaseActionTextMessageStartDialog::SaveDifferingColor(
          this,
          control: this->m_pColor1,
          r: &v5->r1,
          g: &v5->g1,
          b: &v5->b1,
          a: &v5->a1);
  v34 = v44 | v33 | v31;
  v35 = CBaseActionTextMessageStartDialog::SaveDifferingColor(
          this,
          control: this->m_pColor2,
          r: &v5->r2,
          g: &v5->g2,
          b: &v5->b2,
          a: &v5->a2)
      | v34;
  this->m_pEffectType->GetText_2(this: this->m_pEffectType, a2: sz, a3: 1024);
  v43 = 0.0;
  while ( 1 )
  {
    v36 = V_strcasecmp(s1: CBaseActionTextMessageStartDialog::s_EffectTypes[LODWORD(v43)].name, s2: sz) == 0;
    v37 = v43;
    if ( v36 )
      break;
    ++LODWORD(v43);
    if ( SLODWORD(v43) >= 3 )
    {
      v37 = 0.0;
      break;
    }
  }
  if ( LODWORD(v37) != v5->effect )
  {
    *(float *)&v5->effect = v37;
    v35 = 1;
  }
  this->m_pMessageText->GetText_2(this: this->m_pMessageText, a2: sz, a3: 1024);
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  if ( V_strcasecmp(s1: sz, s2: SoundName) != 0 )
  {
    CDemoActionTextMessageStart::SetMessageText(this: (CDemoActionTextMessageStart *)this->m_pAction, text: sz);
    v35 = 1;
  }
  this->m_pFontName->GetText_2(this: this->m_pFontName, a2: sz, a3: 1024);
  FontName = CDemoActionTextMessageStart::GetFontName(this: (CDemoActionTextMessageStart *)this->m_pAction);
  if ( V_strcasecmp(s1: sz, s2: FontName) == 0 )
    return v35;
  CDemoActionTextMessageStart::SetFontName(this: (CDemoActionTextMessageStart *)this->m_pAction, font: sz);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10078730
// Name: public: virtual void CBaseActionPlayCommandsDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionPlayCommandsDialog::Init(CBaseActionPlayCommandsDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  const char *SoundName; // eax

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionPlayCommandsDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pCommands->__vftable;
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  v2->SetText(this: this->m_pCommands, a2: SoundName);
}

//------------------------------------------------------------------------------
// Address: 0x10078780
// Name: public: virtual bool CBaseActionPlayCommandsDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionPlayCommandsDialog::OnSaveChanges(CBaseActionPlayCommandsDialog *this)
{
  char v2; // bl
  const char *SoundName; // eax
  char commands[512]; // [esp+8h] [ebp-200h] BYREF

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pCommands->GetText_2(this: this->m_pCommands, a2: commands, a3: 512);
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  if ( V_strcasecmp(s1: commands, s2: SoundName) != 0 )
  {
    v2 = 1;
    CDemoActionPlayCommands::SetCommandStream(this: (CDemoActionPlayCommands *)this->m_pAction, stream: commands);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100787F0
// Name: public: virtual void CBaseActionCDTrackStartDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionCDTrackStartDialog::Init(CBaseActionCDTrackStartDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  int Track; // eax
  char *v4; // eax

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionCDTrackStartDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pTrackNumber->__vftable;
  Track = CDemoActionCDTrackStart::GetTrack(this: (CDemoActionCDTrackStart *)this->m_pAction);
  v4 = va(format: "%i", Track);
  v2->SetText(this: this->m_pTrackNumber, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10078850
// Name: public: virtual bool CBaseActionCDTrackStartDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseActionCDTrackStartDialog::OnSaveChanges(CBaseActionCDTrackStartDialog *this)
{
  bool v2; // bl
  int v3; // edi
  char track[512]; // [esp+Ch] [ebp-200h] BYREF

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pTrackNumber->GetText_2(this: this->m_pTrackNumber, a2: track, a3: 512);
  v3 = atoi(nptr: track);
  if ( v3 != CDemoActionCDTrackStart::GetTrack(this: (CDemoActionCDTrackStart *)this->m_pAction) )
  {
    v2 = true;
    CDemoActionCDTrackStart::SetTrack(this: (CDemoActionCDTrackStart *)this->m_pAction, track: v3);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100788C0
// Name: public: static char const __near * CBaseActionPlaySoundStartDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseActionPlaySoundStartDialog::GetPanelClassName()
{
  return "CBaseActionPlaySoundStartDialog";
}

//------------------------------------------------------------------------------
// Address: 0x100788D0
// Name: public: virtual void CBaseActionPlaySoundStartDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionPlaySoundStartDialog::Init(CBaseActionPlaySoundStartDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  const char *SoundName; // eax

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionPlaySoundStartDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pSoundName->__vftable;
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  v2->SetText(this: this->m_pSoundName, a2: SoundName);
}

//------------------------------------------------------------------------------
// Address: 0x10078920
// Name: public: virtual bool CBaseActionPlaySoundStartDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionPlaySoundStartDialog::OnSaveChanges(CBaseActionPlaySoundStartDialog *this)
{
  char v2; // bl
  const char *v3; // eax
  char soundname[512]; // [esp+8h] [ebp-200h] BYREF

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pSoundName->GetText_2(this: this->m_pSoundName, a2: soundname, a3: 512);
  v3 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  if ( V_strcasecmp(s1: soundname, s2: v3) != 0 )
  {
    v2 = 1;
    CDemoActionPlaySoundStart::SetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction, name: soundname);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10078990
// Name: public: virtual void CBaseActionWithStopTimeDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionWithStopTimeDialog::Init(CBaseActionWithStopTimeDialog *this)
{
  void (__thiscall *SetText)(vgui::TextEntry *, const char *); // eax
  vgui::TextEntry_vtbl *v3; // edi
  char *v4; // eax

  CBaseActionEditDialog::Init(this);
  SetText = this->m_pStopType->SetText;
  if ( LOBYTE(this->m_pAction[1].__vftable) != 0 )
  {
    ((void (__stdcall *)(const char *))SetText)(a1: "TimeUseTick");
    v3 = this->m_pStop->__vftable;
    v4 = va(format: "%i", this->m_pAction[1].m_Type);
  }
  else
  {
    ((void (__stdcall *)(const char *))SetText)(a1: "TimeUseClock");
    v3 = this->m_pStop->__vftable;
    v4 = va(format: "%.3f", *(float *)&this->m_pAction[1].m_bActionFired);
  }
  v3->SetText(this: this->m_pStop, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10078A40
// Name: public: virtual bool CBaseActionWithStopTimeDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CBaseActionWithStopTimeDialog::OnSaveChanges(CBaseActionWithStopTimeDialog *this)
{
  char v2; // bl
  int v3; // edi
  int v4; // eax
  CBaseDemoActionWithStopTime *m_pAction; // ecx
  char s1[4]; // [esp+10h] [ebp-404h] BYREF
  char stoptype[512]; // [esp+24h] [ebp-3F0h] BYREF
  float stop_492; // [esp+410h] [ebp-4h] OVERLAPPED

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pStopType->GetText_2(this: this->m_pStopType, a2: s1, a3: 512);
  this->m_pStop->GetText_2(this: this->m_pStop, a2: &stoptype[492], a3: 512);
  stop_492 = atof(nptr: &stoptype[492]);
  v3 = atoi(nptr: &stoptype[492]);
  v4 = V_strcasecmp(s1, s2: "TimeUseTick");
  m_pAction = (CBaseDemoActionWithStopTime *)this->m_pAction;
  if ( v4 != 0 )
  {
    if ( m_pAction->m_flStopTime != stop_492 )
    {
      v2 = 1;
      CDemoActionSkipAhead::SetSkipToTime(this: m_pAction, t: stop_492);
      CBaseDemoActionWithStopTime::SetStopTick(this: (CBaseDemoActionWithStopTime *)this->m_pAction, tick: -1);
    }
  }
  else if ( m_pAction->m_nStopTick != v3 )
  {
    CBaseDemoActionWithStopTime::SetStopTick(this: m_pAction, tick: v3);
    CDemoActionSkipAhead::SetSkipToTime(this: (CBaseDemoActionWithStopTime *)this->m_pAction, t: -1.0);
    return 1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10078B30
// Name: public: virtual void CBaseActionChangePlaybackRateDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionChangePlaybackRateDialog::Init(CBaseActionChangePlaybackRateDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  double PauseTime; // st7
  char *v4; // eax

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionPlaybackRateDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionWithStopTimeDialog::Init(this);
  v2 = this->m_pRate->__vftable;
  PauseTime = CDemoActionPausePlayback::GetPauseTime(this: (CDemoActionPausePlayback *)this->m_pAction);
  v4 = va(format: "%f", PauseTime);
  v2->SetText(this: this->m_pRate, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10078B90
// Name: public: virtual bool CBaseActionChangePlaybackRateDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CBaseActionChangePlaybackRateDialog::OnSaveChanges(CBaseActionChangePlaybackRateDialog *this)
{
  bool v2; // bl
  double PauseTime; // st7
  char nptr[12]; // [esp+Ch] [ebp-204h] BYREF
  float rate_500; // [esp+20Ch] [ebp-4h] OVERLAPPED

  v2 = CBaseActionWithStopTimeDialog::OnSaveChanges(this);
  this->m_pRate->GetText_2(this: this->m_pRate, a2: nptr, a3: 512);
  rate_500 = atof(nptr);
  PauseTime = CDemoActionPausePlayback::GetPauseTime(this: (CDemoActionPausePlayback *)this->m_pAction);
  if ( PauseTime == rate_500 )
    return v2;
  CDemoActionChangePlaybackRate::SetPlaybackRate(this: (CDemoActionChangePlaybackRate *)this->m_pAction, rate: rate_500);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10078C20
// Name: public: virtual void CBaseActionPauseDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionPauseDialog::Init(CBaseActionPauseDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  double PauseTime; // st7
  char *v4; // eax

  this->LoadControlSettings(this, a2: "resource\\BaseActionPauseDialog.res", a3: nullptr, a4: nullptr, a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pPauseTime->__vftable;
  PauseTime = CDemoActionPausePlayback::GetPauseTime(this: (CDemoActionPausePlayback *)this->m_pAction);
  v4 = va(format: "%f", PauseTime);
  v2->SetText(this: this->m_pPauseTime, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10078C80
// Name: public: virtual bool CBaseActionPauseDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CBaseActionPauseDialog::OnSaveChanges(CBaseActionPauseDialog *this)
{
  char v2; // bl
  double PauseTime; // st7
  char t[12]; // [esp+Ch] [ebp-204h] BYREF
  float pausetime_500; // [esp+20Ch] [ebp-4h] OVERLAPPED

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pPauseTime->GetText_2(this: this->m_pPauseTime, a2: t, a3: 512);
  pausetime_500 = atof(nptr: t);
  PauseTime = CDemoActionPausePlayback::GetPauseTime(this: (CDemoActionPausePlayback *)this->m_pAction);
  if ( PauseTime == pausetime_500 )
    return v2;
  CDemoActionPausePlayback::SetPauseTime(this: (CDemoActionPausePlayback *)this->m_pAction, t: pausetime_500);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10078D10
// Name: public: virtual void CBaseActionZoomDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionZoomDialog::Init(CBaseActionZoomDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  char *v3; // eax
  vgui::TextEntry_vtbl *v4; // edi
  char *v5; // eax
  vgui::TextEntry_vtbl *v6; // edi
  char *v7; // eax
  vgui::TextEntry_vtbl *v8; // edi
  char *v9; // eax

  this->LoadControlSettings(this, a2: "resource\\BaseActionZoomDialog.res", a3: nullptr, a4: nullptr, a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pFinalFOV->__vftable;
  v3 = va(format: "%f", *(float *)&this->m_pAction[1].m_Type);
  v2->SetText(this: this->m_pFinalFOV, a2: v3);
  v4 = this->m_pOutRate->__vftable;
  v5 = va(format: "%f", *(float *)&this->m_pAction[1].m_bActionFired);
  v4->SetText(this: this->m_pOutRate, a2: v5);
  v6 = this->m_pInRate->__vftable;
  v7 = va(format: "%f", *(float *)&this->m_pAction[1].m_szActionName[2]);
  v6->SetText(this: this->m_pInRate, a2: v7);
  v8 = this->m_pHoldTime->__vftable;
  v9 = va(format: "%f", *(float *)&this->m_pAction[1].m_szActionName[6]);
  v8->SetText(this: this->m_pHoldTime, a2: v9);
  this->m_pSpline->SetSelected(this: this->m_pSpline, a2: (bool)this->m_pAction[1].__vftable);
  this->m_pStayout->SetSelected(this: this->m_pStayout, a2: BYTE1(this->m_pAction[1].__vftable));
}

//------------------------------------------------------------------------------
// Address: 0x10078E50
// Name: public: virtual bool CBaseActionZoomDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionZoomDialog::OnSaveChanges(CBaseActionZoomDialog *this)
{
  char v2; // bl
  long double v3; // st7
  CBaseDemoAction *m_pAction; // ecx
  long double v5; // st7
  CBaseDemoAction *v6; // ecx
  long double v7; // st7
  CBaseDemoAction *v8; // ecx
  long double v9; // st7
  CBaseDemoAction *v10; // ecx
  CBaseDemoAction *v11; // edi
  CBaseDemoAction *v12; // edi
  CBaseDemoAction *v13; // edi
  CBaseDemoAction *v14; // edi
  char sz[512]; // [esp+Ch] [ebp-204h] BYREF
  float f; // [esp+20Ch] [ebp-4h]

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pFinalFOV->GetText_2(this: this->m_pFinalFOV, a2: sz, a3: 512);
  v3 = atof(nptr: sz);
  f = v3;
  m_pAction = this->m_pAction;
  if ( *(float *)&m_pAction[1].m_Type != v3 )
  {
    v2 = 1;
    *(float *)&m_pAction[1].m_Type = f;
  }
  this->m_pOutRate->GetText_2(this: this->m_pOutRate, a2: sz, a3: 512);
  v5 = atof(nptr: sz);
  f = v5;
  v6 = this->m_pAction;
  if ( *(float *)&v6[1].m_bActionFired != v5 )
  {
    v2 = 1;
    *(float *)&v6[1].m_bActionFired = f;
  }
  this->m_pInRate->GetText_2(this: this->m_pInRate, a2: sz, a3: 512);
  v7 = atof(nptr: sz);
  f = v7;
  v8 = this->m_pAction;
  if ( *(float *)&v8[1].m_szActionName[2] != v7 )
  {
    v2 = 1;
    *(float *)&v8[1].m_szActionName[2] = f;
  }
  this->m_pHoldTime->GetText_2(this: this->m_pHoldTime, a2: sz, a3: 512);
  v9 = atof(nptr: sz);
  f = v9;
  v10 = this->m_pAction;
  if ( *(float *)&v10[1].m_szActionName[6] != v9 )
  {
    v2 = 1;
    *(float *)&v10[1].m_szActionName[6] = f;
  }
  v11 = this->m_pAction;
  if ( this->m_pSpline->IsSelected(this: this->m_pSpline) != LOBYTE(v11[1].__vftable) )
  {
    v12 = this->m_pAction;
    v2 = 1;
    LOBYTE(v12[1].__vftable) = this->m_pSpline->IsSelected(this: this->m_pSpline);
  }
  v13 = this->m_pAction;
  if ( this->m_pStayout->IsSelected(this: this->m_pStayout) != BYTE1(v13[1].__vftable) )
  {
    v14 = this->m_pAction;
    v2 = 1;
    BYTE1(v14[1].__vftable) = this->m_pStayout->IsSelected(this: this->m_pStayout);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10079040
// Name: public: CBaseActionEditDialog::CBaseActionEditDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__thiscall CBaseActionEditDialog::CBaseActionEditDialog(
        CBaseActionEditDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  const char *v5; // eax
  const char *v6; // eax
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  const char *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::TextEntry *v17; // eax
  vgui::TextEntry *v18; // eax
  vgui::TextEntry *v19; // eax
  vgui::ComboBox *v20; // eax
  vgui::ComboBox *v21; // eax
  DEMOACTIONTIMINGTYPE i; // ebx
  vgui::ComboBox_vtbl *v23; // edi
  const char *v24; // eax
  const char *v26; // [esp-Ch] [ebp-18h]

  v5 = CWaveDataStreamAsync::Source(this: action);
  v6 = CBaseDemoAction::NameForType(actionType: (DEMOACTION)v5);
  vgui::Frame::Frame(this, parent, panelName: v6, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionEditDialog::`vftable';
  if ( `CBaseActionEditDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseActionEditDialog::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CBaseActionEditDialog");
    v7->pfnClassName = CBaseActionEditDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBaseActionEditDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseActionEditDialog::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CBaseActionEditDialog");
    v8->pfnClassName = CBaseActionEditDialog::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBaseActionEditDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseActionEditDialog::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionEditDialog");
    v9->pfnClassName = CBaseActionEditDialog::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pEditor = parent;
  this->m_pAction = (CBaseDemoAction *)action;
  this->m_bNewAction = newaction;
  v10 = CWaveDataStreamAsync::Source(this: action);
  v26 = CBaseDemoAction::NameForType(actionType: (DEMOACTION)v10);
  if ( newaction )
    v11 = va(format: "New %s Action", v26);
  else
    v11 = va(format: "Edit %s Action", v26);
  vgui::Frame::SetTitle(this, title: v11, surfaceTitle: true);
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "OK",
            text: "OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->m_pOK = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->m_pCancel = v15;
  v16 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v16 != nullptr )
    v17 = vgui::TextEntry::TextEntry(this: v16, parent: this, panelName: "ActionName");
  else
    v17 = nullptr;
  this->m_pActionName = v17;
  v18 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v18 != nullptr )
    v19 = vgui::TextEntry::TextEntry(this: v18, parent: this, panelName: "ActionStart");
  else
    v19 = nullptr;
  this->m_pStart = v19;
  v20 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v20 != nullptr )
    v21 = vgui::ComboBox::ComboBox(this: v20, parent: this, panelName: "ActionStartType", numLines: 3, allowEdit: false);
  else
    v21 = nullptr;
  this->m_pStartType = v21;
  for ( i = ACTION_USES_NEITHER; i < NUM_TIMING_TYPES; ++i )
  {
    v23 = this->m_pStartType->__vftable;
    v24 = CBaseDemoAction::NameForTimingType(timingType: i);
    v23->AddItem_2(this: this->m_pStartType, a2: v24, a3: nullptr);
  }
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100792A0
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        vgui::Panel *this,
        const char *elementName,
        const char *x,
        int *y,
        int *wide,
        int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100792B0
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x100792C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseActionEditDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseActionEditDialog::GetMessageMap(CBaseActionEditDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseActionEditDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseActionEditDialog::GetMessageMap'::`2'::s_pMap;
  `CBaseActionEditDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseActionEditDialog");
  `CBaseActionEditDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100792F0
// Name: public: virtual struct PanelAnimationMap __near * CBaseActionEditDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseActionEditDialog::GetAnimMap(CBaseActionEditDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseActionEditDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10079300
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseActionEditDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseActionEditDialog::GetKBMap(CBaseActionEditDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseActionEditDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseActionEditDialog::GetKBMap'::`2'::s_pMap;
  `CBaseActionEditDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionEditDialog");
  `CBaseActionEditDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079330
// Name: public: CBaseActionSkipAheadDialog::CBaseActionSkipAheadDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionSkipAheadDialog *__thiscall CBaseActionSkipAheadDialog::CBaseActionSkipAheadDialog(
        CBaseActionSkipAheadDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  DEMOACTIONTIMINGTYPE i; // ebx
  vgui::ComboBox_vtbl *v10; // esi
  const char *v11; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionSkipAheadDialog_vtbl *)&CBaseActionSkipAheadDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "ActionSkip");
  else
    v6 = nullptr;
  this->m_pSkip = v6;
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "ActionSkipType", numLines: 2, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pSkipType = v8;
  for ( i = ACTION_USES_TICK; i < NUM_TIMING_TYPES; ++i )
  {
    v10 = this->m_pSkipType->__vftable;
    v11 = CBaseDemoAction::NameForTimingType(timingType: i);
    v10->AddItem_2(this: this->m_pSkipType, a2: v11, a3: nullptr);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100793F0
// Name: FnCreateEditorCBaseActionSkipAheadDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionSkipAheadDialog *__cdecl FnCreateEditorCBaseActionSkipAheadDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionSkipAheadDialog *v3; // eax
  CBaseActionSkipAheadDialog *result; // eax
  CBaseActionSkipAheadDialog *v5; // esi

  v3 = (CBaseActionSkipAheadDialog *)MemAlloc_Alloc(nSize: 0x23Cu);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionSkipAheadDialog::CBaseActionSkipAheadDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079440
// Name: public: virtual void CBaseActionStopPlaybackDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionStopPlaybackDialog::Init(CBaseActionStopPlaybackDialog *this)
{
  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionStopPlaybackDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x10079460
// Name: FnCreateEditorCBaseActionStopPlaybackDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl FnCreateEditorCBaseActionStopPlaybackDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionEditDialog *v3; // esi

  v3 = (CBaseActionEditDialog *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v3 == nullptr )
    return nullptr;
  CBaseActionEditDialog::CBaseActionEditDialog(this: v3, parent, action, newaction);
  v3->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionStopPlaybackDialog::`vftable';
  v3->Init(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100794B0
// Name: public: CBaseActionScreenFadeStartDialog::CBaseActionScreenFadeStartDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionScreenFadeStartDialog *__thiscall CBaseActionScreenFadeStartDialog::CBaseActionScreenFadeStartDialog(
        CBaseActionScreenFadeStartDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::CheckButton *v9; // eax
  vgui::CheckButton *v10; // eax
  vgui::CheckButton *v11; // eax
  vgui::CheckButton *v12; // eax
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // eax
  vgui::CheckButton *v15; // eax
  vgui::CheckButton *v16; // eax
  vgui::CheckButton *v17; // eax
  vgui::CheckButton *v18; // eax
  vgui::TextEntry *v19; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionScreenFadeStartDialog_vtbl *)&CBaseActionScreenFadeStartDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "ScreenFadeDuration");
  else
    v6 = nullptr;
  this->m_pDuration = v6;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "ScreenFadeHoldTime");
  else
    v8 = nullptr;
  this->m_pHoldTime = v8;
  v9 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v9 != nullptr )
    v10 = vgui::CheckButton::CheckButton(this: v9, parent: this, panelName: "ScreenFadeFFADE_IN", text: "Fade in");
  else
    v10 = nullptr;
  this->m_pFFADE_IN = v10;
  v11 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v11 != nullptr )
    v12 = vgui::CheckButton::CheckButton(this: v11, parent: this, panelName: "ScreenFadeFFADE_OUT", text: "Fade out");
  else
    v12 = nullptr;
  this->m_pFFADE_OUT = v12;
  v13 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v13 != nullptr )
    v14 = vgui::CheckButton::CheckButton(
            this: v13,
            parent: this,
            panelName: "ScreenFadeFFADE_MODULATE",
            text: "Modulate");
  else
    v14 = nullptr;
  this->m_pFFADE_MODULATE = v14;
  v15 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v15 != nullptr )
    v16 = vgui::CheckButton::CheckButton(
            this: v15,
            parent: this,
            panelName: "ScreenFadeFFADE_STAYOUT",
            text: "Stay out");
  else
    v16 = nullptr;
  this->m_pFFADE_STAYOUT = v16;
  v17 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v17 != nullptr )
    v18 = vgui::CheckButton::CheckButton(this: v17, parent: this, panelName: "ScreenFadeFFADE_Purge", text: "Purge");
  else
    v18 = nullptr;
  this->m_pFFADE_PURGE = v18;
  v19 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v19 != nullptr )
    this->m_pColor = vgui::TextEntry::TextEntry(this: v19, parent: this, panelName: "ScreenFadeColor");
  else
    this->m_pColor = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10079640
// Name: public: virtual bool CBaseActionScreenFadeStartDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseActionScreenFadeStartDialog::OnSaveChanges(CBaseActionScreenFadeStartDialog *this)
{
  char v2; // al
  CDemoActionPlaySoundStart *m_pAction; // ecx
  char *SoundName; // esi
  int v5; // ecx
  __int16 v6; // ax
  char v7; // bl
  char v8; // dl
  int v9; // xmm0_4
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  vgui::TextEntry *m_pDuration; // ecx
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // edx
  char v16; // bl
  long double v17; // st6
  long double v18; // st6
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  vgui::CheckButton *m_pFFADE_IN; // esi
  const char *v24; // ebx
  vgui::CheckButton *m_pFFADE_OUT; // esi
  bool v26; // al
  const char *v27; // ebx
  vgui::CheckButton *m_pFFADE_MODULATE; // esi
  bool v29; // al
  const char *v30; // ebx
  vgui::CheckButton *m_pFFADE_STAYOUT; // esi
  bool v32; // al
  const char *v33; // ebx
  vgui::CheckButton *m_pFFADE_PURGE; // esi
  bool v35; // al
  const char *v36; // edi
  char sz[512]; // [esp+Ch] [ebp-234h] BYREF
  int g; // [esp+20Ch] [ebp-34h]
  int a; // [esp+210h] [ebp-30h]
  int b; // [esp+214h] [ebp-2Ch]
  int r; // [esp+218h] [ebp-28h]
  int rr; // [esp+21Ch] [ebp-24h] BYREF
  int aa; // [esp+220h] [ebp-20h] BYREF
  int gg; // [esp+224h] [ebp-1Ch] BYREF
  int bb; // [esp+228h] [ebp-18h] BYREF
  int holdTime; // [esp+22Ch] [ebp-14h]
  bool fadepurge; // [esp+230h] [ebp-10h]
  bool fademodulate; // [esp+231h] [ebp-Fh]
  bool fadeout; // [esp+232h] [ebp-Eh]
  bool fadestayout; // [esp+233h] [ebp-Dh]
  int v52; // [esp+234h] [ebp-Ch]
  int duration; // [esp+238h] [ebp-8h]
  bool bret; // [esp+23Fh] [ebp-1h]

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  m_pAction = (CDemoActionPlaySoundStart *)this->m_pAction;
  bret = v2;
  SoundName = (char *)CDemoActionPlaySoundStart::GetSoundName(this: m_pAction);
  v5 = *((unsigned __int16 *)SoundName + 1);
  duration = *(unsigned __int16 *)SoundName;
  v6 = *((_WORD *)SoundName + 2);
  v7 = SoundName[4];
  fadeout = (v6 & 2) != 0;
  v8 = v6;
  *(float *)&duration = (double)duration * 0.001953125;
  *(float *)&v9 = (float)v5 * 0.001953125;
  LOBYTE(v5) = v6;
  fadepurge = (v6 & 0x10) != 0;
  v10 = (unsigned __int8)SoundName[6];
  fademodulate = (v5 & 4) != 0;
  v11 = (unsigned __int8)SoundName[7];
  fadestayout = (v8 & 8) != 0;
  v12 = (unsigned __int8)SoundName[8];
  r = v10;
  v13 = (unsigned __int8)SoundName[9];
  g = v11;
  m_pDuration = this->m_pDuration;
  b = v12;
  GetText_2 = m_pDuration->GetText_2;
  a = v13;
  holdTime = v9;
  v16 = v7 & 1;
  GetText_2(this: m_pDuration, a2: sz, a3: 512);
  v17 = atof(nptr: sz);
  if ( v17 != *(float *)&duration )
  {
    bret = true;
    duration = (int)(atof(nptr: sz) * 512.0);
    *(_WORD *)SoundName = duration;
  }
  this->m_pHoldTime->GetText_2(this: this->m_pHoldTime, a2: sz, a3: 512);
  v18 = atof(nptr: sz);
  if ( v18 != *(float *)&holdTime )
  {
    bret = true;
    holdTime = (int)(atof(nptr: sz) * 512.0);
    *((_WORD *)SoundName + 1) = holdTime;
  }
  this->m_pColor->GetText_2(this: this->m_pColor, a2: sz, a3: 512);
  if ( sscanf(string: sz, format: "%i %i %i %i", &rr, &gg, &bb, &aa) == 4 )
  {
    if ( rr >= 0 )
    {
      v19 = 255;
      if ( rr <= 255 )
        v19 = rr;
    }
    else
    {
      v19 = 0;
    }
    v20 = gg;
    duration = v19;
    rr = v19;
    if ( gg >= 0 )
    {
      if ( gg > 255 )
        v20 = 255;
    }
    else
    {
      v20 = 0;
    }
    v52 = v20;
    gg = v20;
    if ( bb >= 0 )
    {
      v21 = 255;
      if ( bb <= 255 )
        v21 = bb;
    }
    else
    {
      v21 = 0;
    }
    v22 = aa;
    bb = v21;
    if ( aa >= 0 )
    {
      if ( aa > 255 )
        v22 = 255;
    }
    else
    {
      v22 = 0;
    }
    aa = v22;
    if ( v19 != r || v52 != g || v21 != b || v22 != a )
    {
      SoundName[6] = duration;
      SoundName[7] = gg;
      SoundName[8] = bb;
      bret = true;
      SoundName[9] = aa;
    }
  }
  m_pFFADE_IN = this->m_pFFADE_IN;
  if ( m_pFFADE_IN->IsSelected(this: m_pFFADE_IN) != v16 )
  {
    v24 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
    if ( m_pFFADE_IN->IsSelected(this: m_pFFADE_IN) )
      *((_WORD *)v24 + 2) |= 1u;
    else
      *((_WORD *)v24 + 2) &= ~1u;
    bret = true;
  }
  m_pFFADE_OUT = this->m_pFFADE_OUT;
  v26 = m_pFFADE_OUT->IsSelected(this: m_pFFADE_OUT);
  if ( v26 != fadeout )
  {
    v27 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
    if ( m_pFFADE_OUT->IsSelected(this: m_pFFADE_OUT) )
      *((_WORD *)v27 + 2) |= 2u;
    else
      *((_WORD *)v27 + 2) &= ~2u;
    bret = true;
  }
  m_pFFADE_MODULATE = this->m_pFFADE_MODULATE;
  v29 = m_pFFADE_MODULATE->IsSelected(this: m_pFFADE_MODULATE);
  if ( v29 != fademodulate )
  {
    v30 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
    if ( m_pFFADE_MODULATE->IsSelected(this: m_pFFADE_MODULATE) )
      *((_WORD *)v30 + 2) |= 4u;
    else
      *((_WORD *)v30 + 2) &= ~4u;
    bret = true;
  }
  m_pFFADE_STAYOUT = this->m_pFFADE_STAYOUT;
  v32 = m_pFFADE_STAYOUT->IsSelected(this: m_pFFADE_STAYOUT);
  if ( v32 != fadestayout )
  {
    v33 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
    if ( m_pFFADE_STAYOUT->IsSelected(this: m_pFFADE_STAYOUT) )
      *((_WORD *)v33 + 2) |= 8u;
    else
      *((_WORD *)v33 + 2) &= ~8u;
    bret = true;
  }
  m_pFFADE_PURGE = this->m_pFFADE_PURGE;
  v35 = m_pFFADE_PURGE->IsSelected(this: m_pFFADE_PURGE);
  if ( v35 == fadepurge )
    return bret;
  v36 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  if ( m_pFFADE_PURGE->IsSelected(this: m_pFFADE_PURGE) )
    *((_WORD *)v36 + 2) |= 0x10u;
  else
    *((_WORD *)v36 + 2) &= ~0x10u;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10079A20
// Name: FnCreateEditorCBaseActionScreenFadeStartDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionScreenFadeStartDialog *__cdecl FnCreateEditorCBaseActionScreenFadeStartDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionScreenFadeStartDialog *v3; // eax
  CBaseActionScreenFadeStartDialog *result; // eax
  CBaseActionScreenFadeStartDialog *v5; // esi

  v3 = (CBaseActionScreenFadeStartDialog *)MemAlloc_Alloc(nSize: 0x254u);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionScreenFadeStartDialog::CBaseActionScreenFadeStartDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079A70
// Name: public: CBaseActionTextMessageStartDialog::CBaseActionTextMessageStartDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionTextMessageStartDialog *__thiscall CBaseActionTextMessageStartDialog::CBaseActionTextMessageStartDialog(
        CBaseActionTextMessageStartDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::ComboBox *v15; // eax
  vgui::ComboBox *v16; // eax
  vgui::TextEntry *v17; // eax
  vgui::TextEntry *v18; // eax
  vgui::TextEntry *v19; // eax
  vgui::TextEntry *v20; // eax
  vgui::TextEntry *v21; // eax
  vgui::TextEntry *v22; // eax
  vgui::TextEntry *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::ComboBox *v25; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionTextMessageStartDialog_vtbl *)&CBaseActionTextMessageStartDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "TextMessageFadeInTime");
  else
    v6 = nullptr;
  this->m_pFadeInTime = v6;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "TextMessageFadeOutTime");
  else
    v8 = nullptr;
  this->m_pFadeOutTime = v8;
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "TextMessageHoldTime");
  else
    v10 = nullptr;
  this->m_pHoldTime = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "TextMessageFXTime");
  else
    v12 = nullptr;
  this->m_pFXTime = v12;
  v13 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v13 != nullptr )
    v14 = vgui::TextEntry::TextEntry(this: v13, parent: this, panelName: "TextMessageText");
  else
    v14 = nullptr;
  this->m_pMessageText = v14;
  v15 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v15 != nullptr )
    v16 = vgui::ComboBox::ComboBox(this: v15, parent: this, panelName: "TextMessageFont", numLines: 6, allowEdit: false);
  else
    v16 = nullptr;
  this->m_pFontName = v16;
  v17 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v17 != nullptr )
    v18 = vgui::TextEntry::TextEntry(this: v17, parent: this, panelName: "TextMessageX");
  else
    v18 = nullptr;
  this->m_pX = v18;
  v19 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v19 != nullptr )
    v20 = vgui::TextEntry::TextEntry(this: v19, parent: this, panelName: "TextMessageY");
  else
    v20 = nullptr;
  this->m_pY = v20;
  v21 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v21 != nullptr )
    v22 = vgui::TextEntry::TextEntry(this: v21, parent: this, panelName: "TextMessageColor1");
  else
    v22 = nullptr;
  this->m_pColor1 = v22;
  v23 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v23 != nullptr )
    v24 = vgui::TextEntry::TextEntry(this: v23, parent: this, panelName: "TextMessageColor2");
  else
    v24 = nullptr;
  this->m_pColor2 = v24;
  v25 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v25 != nullptr )
    this->m_pEffectType = vgui::ComboBox::ComboBox(
                            this: v25,
                            parent: this,
                            panelName: "TextMessageEffect",
                            numLines: 3,
                            allowEdit: false);
  else
    this->m_pEffectType = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10079C70
// Name: public: virtual void CBaseActionTextMessageStartDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionTextMessageStartDialog::Init(CBaseActionTextMessageStartDialog *this)
{
  client_textmessage_t *TextMessage; // edi
  vgui::TextEntry_vtbl *v3; // ebx
  char *v4; // eax
  vgui::TextEntry_vtbl *v5; // ebx
  char *v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  char *v8; // eax
  vgui::TextEntry_vtbl *v9; // ebx
  char *v10; // eax
  vgui::TextEntry_vtbl *v11; // ebx
  char *v12; // eax
  vgui::TextEntry_vtbl *v13; // ebx
  char *v14; // eax
  vgui::TextEntry_vtbl *v15; // ebx
  char *v16; // eax
  vgui::TextEntry_vtbl *v17; // ebx
  char *v18; // eax
  vgui::TextEntry_vtbl *v19; // ebx
  const char *SoundName; // eax
  vgui::ComboBox_vtbl *v21; // ebx
  const char *FontName; // eax
  CBaseActionTextMessageStartDialog::EffectType *v23; // ebx

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionTextMessageStartDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  TextMessage = CDemoActionTextMessageStart::GetTextMessage(this: (CDemoActionTextMessageStart *)this->m_pAction);
  v3 = this->m_pX->__vftable;
  v4 = va(format: "%f", TextMessage->x);
  v3->SetText(this: this->m_pX, a2: v4);
  v5 = this->m_pY->__vftable;
  v6 = va(format: "%f", TextMessage->y);
  v5->SetText(this: this->m_pY, a2: v6);
  v7 = this->m_pFadeInTime->__vftable;
  v8 = va(format: "%.3f", TextMessage->fadein);
  v7->SetText(this: this->m_pFadeInTime, a2: v8);
  v9 = this->m_pFadeOutTime->__vftable;
  v10 = va(format: "%.3f", TextMessage->fadeout);
  v9->SetText(this: this->m_pFadeOutTime, a2: v10);
  v11 = this->m_pHoldTime->__vftable;
  v12 = va(format: "%.3f", TextMessage->holdtime);
  v11->SetText(this: this->m_pHoldTime, a2: v12);
  v13 = this->m_pFXTime->__vftable;
  v14 = va(format: "%.3f", TextMessage->fxtime);
  v13->SetText(this: this->m_pFXTime, a2: v14);
  v15 = this->m_pColor1->__vftable;
  v16 = va(format: "%i %i %i %i", TextMessage->r1, TextMessage->g1, TextMessage->b1, TextMessage->a1);
  v15->SetText(this: this->m_pColor1, a2: v16);
  v17 = this->m_pColor2->__vftable;
  v18 = va(format: "%i %i %i %i", TextMessage->r2, TextMessage->g2, TextMessage->b2, TextMessage->a2);
  v17->SetText(this: this->m_pColor2, a2: v18);
  v19 = this->m_pMessageText->__vftable;
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  v19->SetText(this: this->m_pMessageText, a2: SoundName);
  CBaseActionTextMessageStartDialog::FillInFonts(this);
  v21 = this->m_pFontName->__vftable;
  FontName = CDemoActionTextMessageStart::GetFontName(this: (CDemoActionTextMessageStart *)this->m_pAction);
  v21->SetText(this: this->m_pFontName, a2: FontName);
  v23 = CBaseActionTextMessageStartDialog::s_EffectTypes;
  do
  {
    this->m_pEffectType->AddItem_2(this: this->m_pEffectType, a2: v23->name, a3: nullptr);
    ++v23;
  }
  while ( (int)v23 < (int)&CBaseActionEditDialog `RTTI Type Descriptor' );
  this->m_pEffectType->SetText(
    this: this->m_pEffectType,
    a2: CBaseActionTextMessageStartDialog::s_EffectTypes[TextMessage->effect].name);
}

//------------------------------------------------------------------------------
// Address: 0x10079EB0
// Name: FnCreateEditorCBaseActionTextMessageStartDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionTextMessageStartDialog *__cdecl FnCreateEditorCBaseActionTextMessageStartDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionTextMessageStartDialog *v3; // eax
  CBaseActionTextMessageStartDialog *result; // eax
  CBaseActionTextMessageStartDialog *v5; // esi

  v3 = (CBaseActionTextMessageStartDialog *)MemAlloc_Alloc(nSize: 0x260u);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionTextMessageStartDialog::CBaseActionTextMessageStartDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079F30
// Name: FnCreateEditorCBaseActionPlayCommandsDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl FnCreateEditorCBaseActionPlayCommandsDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionEditDialog *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax

  v3 = (CBaseActionEditDialog *)MemAlloc_Alloc(nSize: 0x238u);
  if ( v3 == nullptr )
    return nullptr;
  CBaseActionEditDialog::CBaseActionEditDialog(this: v3, parent, action, newaction);
  v3->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionPlayCommandsDialog::`vftable';
  v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v4 != nullptr )
    v5 = vgui::TextEntry::TextEntry(this: v4, parent: v3, panelName: "Commands");
  else
    v5 = nullptr;
  v3[1].__vftable = (CBaseActionEditDialog_vtbl *)v5;
  v3->Init(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10079FA0
// Name: FnCreateEditorCBaseActionCDTrackStartDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl FnCreateEditorCBaseActionCDTrackStartDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionEditDialog *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax

  v3 = (CBaseActionEditDialog *)MemAlloc_Alloc(nSize: 0x238u);
  if ( v3 == nullptr )
    return nullptr;
  CBaseActionEditDialog::CBaseActionEditDialog(this: v3, parent, action, newaction);
  v3->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionCDTrackStartDialog::`vftable';
  v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v4 != nullptr )
    v5 = vgui::TextEntry::TextEntry(this: v4, parent: v3, panelName: "TrackNumber");
  else
    v5 = nullptr;
  v3[1].__vftable = (CBaseActionEditDialog_vtbl *)v5;
  v3->Init(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007A010
// Name: private: virtual void CBaseActionPlaySoundStartDialog::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseActionPlaySoundStartDialog::OnFileSelected(
        CBaseActionPlaySoundStartDialog *this@<ecx>,
        int a2@<esi>,
        const char *fullpath)
{
  vgui::Panel *v4; // eax
  char relativepath[512]; // [esp+4h] [ebp-200h] BYREF

  if ( fullpath != nullptr && *fullpath != 0 )
  {
    ((void (__thiscall *)(IFileSystem *, const char *, char *, int, int))g_pFileSystem->FullPathToRelativePath)(
      a1: g_pFileSystem,
      a2: fullpath,
      a3: relativepath,
      a4: 512,
      a5: a2);
    V_FixSlashes(pname: relativepath, separator: 92);
    V_strnicmp(s1: relativepath, s2: "sound\\", n: 6);
    ((void (__thiscall *)(vgui::TextEntry *))this->m_pSoundName->SetText)(a1: this->m_pSoundName);
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      v4->MarkForDeletion(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A0B0
// Name: public: virtual void CBaseActionPlaySoundStartDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionPlaySoundStartDialog::OnCommand(CBaseActionPlaySoundStartDialog *this, const char *command)
{
  vgui::DHANDLE<vgui::FileOpenDialog> *p_m_hFileOpenDialog; // esi
  vgui::FileOpenDialog *v4; // eax
  CDragDropHelperPanel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::FileOpenDialog *v7; // edi
  const char *v8; // eax
  vgui::FileOpenDialog *v9; // eax
  char startPath[260]; // [esp+8h] [ebp-104h] BYREF

  if ( V_strcasecmp(s1: command, s2: "choosesound") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "OK") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "Cancel") != 0 )
        vgui::Frame::OnCommand(this, command);
      else
        this->OnCancel(this);
    }
    else
    {
      this->OnClose(this);
    }
  }
  else
  {
    p_m_hFileOpenDialog = &this->m_hFileOpenDialog;
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
    {
      v4 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
      if ( v4 != nullptr )
        v5 = (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                       this: v4,
                                       parent: this,
                                       title: "Choose .wav file",
                                       bOpenOnly: true,
                                       pContextKeyValues: nullptr);
      else
        v5 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
        pPanel: v5);
      v6 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v6->__vftable[1].GetUnpackStructure)(a1: v6, a2: 0);
    }
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      V_strncpy(pDest: startPath, pSrc: com_gamedir, maxLen: 260);
      V_FixSlashes(pname: startPath, separator: 92);
      v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      v8 = va(format: "%s/sound", startPath);
      vgui::FileOpenDialog::SetStartDirectory(this: v7, dir: v8);
      v9 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: p_m_hFileOpenDialog);
      vgui::FileOpenDialog::DoModal(this: v9, bUnused: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A200
// Name: public: CBaseActionWithStopTimeDialog::CBaseActionWithStopTimeDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionWithStopTimeDialog *__thiscall CBaseActionWithStopTimeDialog::CBaseActionWithStopTimeDialog(
        CBaseActionWithStopTimeDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  DEMOACTIONTIMINGTYPE i; // ebx
  vgui::ComboBox_vtbl *v10; // esi
  const char *v11; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionWithStopTimeDialog_vtbl *)&CBaseActionWithStopTimeDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "ActionStop");
  else
    v6 = nullptr;
  this->m_pStop = v6;
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "ActionStopType", numLines: 2, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pStopType = v8;
  for ( i = ACTION_USES_TICK; i < NUM_TIMING_TYPES; ++i )
  {
    v10 = this->m_pStopType->__vftable;
    v11 = CBaseDemoAction::NameForTimingType(timingType: i);
    v10->AddItem_2(this: this->m_pStopType, a2: v11, a3: nullptr);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A2C0
// Name: FnCreateEditorCBaseActionChangePlaybackRateDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionWithStopTimeDialog *__cdecl FnCreateEditorCBaseActionChangePlaybackRateDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionWithStopTimeDialog *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax

  v3 = (CBaseActionWithStopTimeDialog *)MemAlloc_Alloc(nSize: 0x240u);
  if ( v3 == nullptr )
    return nullptr;
  CBaseActionWithStopTimeDialog::CBaseActionWithStopTimeDialog(this: v3, parent, action, newaction);
  v3->__vftable = (CBaseActionWithStopTimeDialog_vtbl *)&CBaseActionChangePlaybackRateDialog::`vftable';
  v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v4 != nullptr )
    v5 = vgui::TextEntry::TextEntry(this: v4, parent: v3, panelName: "PlaybackRate");
  else
    v5 = nullptr;
  v3[1].__vftable = (CBaseActionWithStopTimeDialog_vtbl *)v5;
  v3->Init(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007A330
// Name: FnCreateEditorCBaseActionPauseDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl FnCreateEditorCBaseActionPauseDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionEditDialog *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax

  v3 = (CBaseActionEditDialog *)MemAlloc_Alloc(nSize: 0x238u);
  if ( v3 == nullptr )
    return nullptr;
  CBaseActionEditDialog::CBaseActionEditDialog(this: v3, parent, action, newaction);
  v3->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionPauseDialog::`vftable';
  v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v4 != nullptr )
    v5 = vgui::TextEntry::TextEntry(this: v4, parent: v3, panelName: "PauseTime");
  else
    v5 = nullptr;
  v3[1].__vftable = (CBaseActionEditDialog_vtbl *)v5;
  v3->Init(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007A3A0
// Name: public: CBaseActionZoomDialog::CBaseActionZoomDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionZoomDialog *__thiscall CBaseActionZoomDialog::CBaseActionZoomDialog(
        CBaseActionZoomDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // eax
  vgui::CheckButton *v15; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionZoomDialog_vtbl *)&CBaseActionZoomDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "ZoomFOV");
  else
    v6 = nullptr;
  this->m_pFinalFOV = v6;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "ZoomOut");
  else
    v8 = nullptr;
  this->m_pOutRate = v8;
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "ZoomIn");
  else
    v10 = nullptr;
  this->m_pInRate = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "ZoomHold");
  else
    v12 = nullptr;
  this->m_pHoldTime = v12;
  v13 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v13 != nullptr )
    v14 = vgui::CheckButton::CheckButton(this: v13, parent: this, panelName: "ZoomSpline", text: "Spline");
  else
    v14 = nullptr;
  this->m_pSpline = v14;
  v15 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v15 != nullptr )
    this->m_pStayout = vgui::CheckButton::CheckButton(
                         this: v15,
                         parent: this,
                         panelName: "ZoomStayout",
                         text: "Stay Out");
  else
    this->m_pStayout = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A4D0
// Name: FnCreateEditorCBaseActionZoomDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionZoomDialog *__cdecl FnCreateEditorCBaseActionZoomDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionZoomDialog *v3; // eax
  CBaseActionZoomDialog *result; // eax
  CBaseActionZoomDialog *v5; // esi

  v3 = (CBaseActionZoomDialog *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionZoomDialog::CBaseActionZoomDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A520
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007A5A0
// Name: public: static void CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseActionPlaySoundStartDialog");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A640
// Name: public: CBaseActionPlaySoundStartDialog::CBaseActionPlaySoundStartDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionPlaySoundStartDialog *__thiscall CBaseActionPlaySoundStartDialog::CBaseActionPlaySoundStartDialog(
        CBaseActionPlaySoundStartDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::Button *v10; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionPlaySoundStartDialog_vtbl *)&CBaseActionPlaySoundStartDialog::`vftable';
  if ( `CBaseActionPlaySoundStartDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseActionPlaySoundStartDialog::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseActionPlaySoundStartDialog");
    v5->pfnClassName = CBaseActionPlaySoundStartDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseActionEditDialog");
  }
  if ( `CBaseActionPlaySoundStartDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseActionPlaySoundStartDialog::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseActionPlaySoundStartDialog");
    v6->pfnClassName = CBaseActionPlaySoundStartDialog::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseActionEditDialog");
  }
  if ( `CBaseActionPlaySoundStartDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseActionPlaySoundStartDialog::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionPlaySoundStartDialog");
    v7->pfnClassName = CBaseActionPlaySoundStartDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionEditDialog");
  }
  CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar();
  this->m_hFileOpenDialog.m_iPanelID = -1;
  v8 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: "SoundName");
  else
    v9 = nullptr;
  this->m_pSoundName = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    this->m_pChooseSound = vgui::Button::Button(
                             this: v10,
                             parent: this,
                             panelName: "ChooseSound",
                             text: "Choose...",
                             pActionSignalTarget: nullptr,
                             pCmd: nullptr);
  else
    this->m_pChooseSound = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A780
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseActionPlaySoundStartDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseActionPlaySoundStartDialog::GetMessageMap(CBaseActionPlaySoundStartDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseActionPlaySoundStartDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseActionPlaySoundStartDialog::GetMessageMap'::`2'::s_pMap;
  `CBaseActionPlaySoundStartDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseActionPlaySoundStartDialog");
  `CBaseActionPlaySoundStartDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A7B0
// Name: public: virtual struct PanelAnimationMap __near * CBaseActionPlaySoundStartDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseActionPlaySoundStartDialog::GetAnimMap(CBaseActionPlaySoundStartDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseActionPlaySoundStartDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1007A7C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseActionPlaySoundStartDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseActionPlaySoundStartDialog::GetKBMap(CBaseActionPlaySoundStartDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseActionPlaySoundStartDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseActionPlaySoundStartDialog::GetKBMap'::`2'::s_pMap;
  `CBaseActionPlaySoundStartDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionPlaySoundStartDialog");
  `CBaseActionPlaySoundStartDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A7F0
// Name: FnCreateEditorCBaseActionPlaySoundStartDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionPlaySoundStartDialog *__cdecl FnCreateEditorCBaseActionPlaySoundStartDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionPlaySoundStartDialog *v3; // eax
  CBaseActionPlaySoundStartDialog *result; // eax
  CBaseActionPlaySoundStartDialog *v5; // esi

  v3 = (CBaseActionPlaySoundStartDialog *)MemAlloc_Alloc(nSize: 0x244u);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionPlaySoundStartDialog::CBaseActionPlaySoundStartDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031DEB0
// Name: _dynamic_initializer_for__editor_toggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__editor_toggle__()
{
  ConCommand::ConCommand(
    this: &editor_toggle,
    pName: "editor_toggle",
    callback: EditorToggle_f,
    pHelpString: "Disables the simulation and returns focus to the editor",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__editor_toggle__);
}

//------------------------------------------------------------------------------
// Address: 0x10326A40
// Name: _dynamic_atexit_destructor_for__editor_toggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__editor_toggle__()
{
  ConCommand::~ConCommand(this: &editor_toggle);
}

//------------------------------------------------------------------------------
// Address: 0x1031DEE0
// Name: _dynamic_initializer_for__g_TextModeLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TextModeLine__()
{
  g_TextModeLine.m_Size = 0;
  g_TextModeLine.m_pElements = g_TextModeLine.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_TextModeLine__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DF30
// Name: _dynamic_initializer_for____g_CreateCEngineAPIIEngineAPI_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineAPIIEngineAPI_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineAPIIEngineAPI_reg,
           fn: (void *(__cdecl *)())_CreateCEngineAPIIEngineAPI_interface,
           pName: "VENGINE_LAUNCHER_API_VERSION004");
}

//------------------------------------------------------------------------------
// Address: 0x1031DF50
// Name: _dynamic_initializer_for__reload_vjobs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reload_vjobs_command__()
{
  ConCommand::ConCommand(
    this: &reload_vjobs_command,
    pName: "reload_vjobs",
    callback: reload_vjobs,
    pHelpString: "reload vjobs module",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__reload_vjobs_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326A50
// Name: _dynamic_atexit_destructor_for__reload_vjobs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reload_vjobs_command__()
{
  ConCommand::~ConCommand(this: &reload_vjobs_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10077940
// Name: public: static char const __near * CBaseActionEditDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseActionEditDialog::GetPanelClassName()
{
  return "CBaseActionEditDialog";
}

//------------------------------------------------------------------------------
// Address: 0x10077950
// Name: public: virtual void CBaseActionEditDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionEditDialog::Init(CBaseActionEditDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  char *ActionName; // eax
  vgui::ComboBox_vtbl *v4; // edi
  DEMOACTIONTIMINGTYPE Socket; // eax
  __int32 v6; // eax
  vgui::TextEntry_vtbl *v7; // edi
  double StartTime; // st7
  char *v9; // eax
  vgui::TextEntry_vtbl *v10; // edi
  int StartTick; // eax
  char *v12; // eax

  v2 = this->m_pActionName->__vftable;
  ActionName = CBaseDemoAction::GetActionName(this: this->m_pAction);
  v2->SetText(this: this->m_pActionName, a2: ActionName);
  v4 = this->m_pStartType->__vftable;
  Socket = CNetChan::GetSocket(this: this->m_pAction);
  v4->ActivateItem(this: this->m_pStartType, a2: Socket);
  v6 = CNetChan::GetSocket(this: this->m_pAction) - 1;
  if ( v6 != 0 )
  {
    if ( v6 == 1 )
    {
      v7 = this->m_pStart->__vftable;
      StartTime = CBaseDemoAction::GetStartTime(this: this->m_pAction);
      v9 = va(format: "%.3f", StartTime);
      v7->SetText(this: this->m_pStart, a2: v9);
    }
    else
    {
      this->m_pStart->SetText(this: this->m_pStart, a2: defaultValue);
    }
  }
  else
  {
    v10 = this->m_pStart->__vftable;
    StartTick = CBaseDemoAction::GetStartTick(this: this->m_pAction);
    v12 = va(format: "%i", StartTick);
    v10->SetText(this: this->m_pStart, a2: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077A30
// Name: public: virtual bool CBaseActionEditDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionEditDialog::OnSaveChanges(CBaseActionEditDialog *this)
{
  vgui::TextEntry *m_pActionName; // ecx
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // eax
  char v4; // bl
  char *v5; // eax
  Color v6; // edi
  int v7; // edi
  double StartTime; // st7
  Color v10; // edi
  char starttype[512]; // [esp+28h] [ebp-604h] BYREF
  char starttext[512]; // [esp+228h] [ebp-404h] BYREF
  char actionname[512]; // [esp+428h] [ebp-204h] BYREF
  float t; // [esp+628h] [ebp-4h]

  m_pActionName = this->m_pActionName;
  GetText_2 = m_pActionName->GetText_2;
  v4 = 0;
  g_BaseActionEditSaveChained = true;
  GetText_2(this: m_pActionName, a2: actionname, a3: 512);
  v5 = CBaseDemoAction::GetActionName(this: this->m_pAction);
  if ( _V_strcmp(s1: v5, s2: actionname) != 0 )
  {
    v4 = 1;
    CBaseDemoAction::SetActionName(this: this->m_pAction, name: actionname);
  }
  this->m_pStart->GetText_2(this: this->m_pStart, a2: starttext, a3: 512);
  this->m_pStartType->GetText_2(this: this->m_pStartType, a2: starttype, a3: 512);
  v6 = (Color)CBaseDemoAction::TimingTypeForName(name: starttype);
  if ( v6 != CNetChan::GetSocket(this: this->m_pAction) )
  {
    v4 = 1;
    CBaseDemoAction::SetTimingType(this: (vgui::Panel *)this->m_pAction, color: v6);
  }
  v7 = *(_DWORD *)&v6 - 1;
  if ( v7 != 0 )
  {
    if ( v7 == 1 )
    {
      t = atof(nptr: starttext);
      StartTime = CBaseDemoAction::GetStartTime(this: this->m_pAction);
      if ( t != StartTime )
      {
        CBaseDemoAction::SetStartTime(this: this->m_pAction, t);
        return 1;
      }
    }
  }
  else
  {
    v10 = (Color)atoi(nptr: starttext);
    if ( v10 != CBaseDemoAction::GetStartTick(this: this->m_pAction) )
    {
      CBaseDemoAction::SetStartTick(this: (vgui::Panel *)this->m_pAction, color: v10);
      return 1;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10077B90
// Name: public: virtual void CBaseActionEditDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionEditDialog::OnClose(CBaseActionEditDialog *this)
{
  bool (__thiscall *OnSaveChanges)(CBaseActionEditDialog *); // eax

  if ( this->m_bNewAction )
    demoaction->AddAction(this: demoaction, a2: this->m_pAction);
  OnSaveChanges = this->OnSaveChanges;
  g_BaseActionEditSaveChained = false;
  if ( OnSaveChanges(this) || this->m_bNewAction )
  {
    demoaction->SetDirty(this: demoaction, a2: true);
    CDemoEditorPanel::OnVDMChanged(this: this->m_pEditor);
  }
  this->MarkForDeletion(this);
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x10077C00
// Name: public: virtual void CBaseActionEditDialog::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionEditDialog::OnCancel(CBaseActionEditDialog *this)
{
  CBaseDemoAction *m_pAction; // ecx

  if ( this->m_bNewAction )
  {
    m_pAction = this->m_pAction;
    if ( m_pAction != nullptr )
      ((void (__thiscall *)(CBaseDemoAction *, int))m_pAction->dtr_CBaseDemoAction)(a1: m_pAction, a2: 1);
  }
  this->MarkForDeletion(this);
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x10077C40
// Name: public: virtual void CBaseActionEditDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionEditDialog::OnCommand(CBaseActionEditDialog *this, const char *commands)
{
  if ( V_strcasecmp(s1: commands, s2: "OK") != 0 )
  {
    if ( V_strcasecmp(s1: commands, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: commands);
    else
      this->OnCancel(this);
  }
  else
  {
    this->OnClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077CA0
// Name: public: virtual void CBaseActionSkipAheadDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionSkipAheadDialog::Init(CBaseActionSkipAheadDialog *this)
{
  void (__thiscall *SetText)(vgui::TextEntry *, const char *); // eax
  vgui::TextEntry_vtbl *v3; // edi
  char *v4; // eax

  this->LoadControlSettings(this, a2: "resource\\BaseActionSkipAheadDialog.res", a3: nullptr, a4: nullptr, a5: nullptr);
  CBaseActionEditDialog::Init(this);
  SetText = this->m_pSkipType->SetText;
  if ( LOBYTE(this->m_pAction[1].__vftable) != 0 )
  {
    ((void (__stdcall *)(const char *))SetText)(a1: "TimeUseTick");
    v3 = this->m_pSkip->__vftable;
    v4 = va(format: "%i", this->m_pAction[1].m_Type);
  }
  else
  {
    ((void (__stdcall *)(const char *))SetText)(a1: "TimeUseClock");
    v3 = this->m_pSkip->__vftable;
    v4 = va(format: "%.3f", *(float *)&this->m_pAction[1].m_bActionFired);
  }
  v3->SetText(this: this->m_pSkip, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10077D60
// Name: public: virtual bool CBaseActionWithStopTimeDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionWithStopTimeDialog::OnSaveChanges(CBaseActionWithStopTimeDialog *this)
{
  char v2; // bl
  int v3; // edi
  int v4; // eax
  CBaseDemoActionWithStopTime *m_pAction; // ecx
  char stoptype[512]; // [esp+20h] [ebp-404h] BYREF
  char stop[512]; // [esp+220h] [ebp-204h] BYREF
  float fstop; // [esp+420h] [ebp-4h]

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pStopType->GetText_2(this: this->m_pStopType, a2: stoptype, a3: 512);
  this->m_pStop->GetText_2(this: this->m_pStop, a2: stop, a3: 512);
  fstop = atof(nptr: stop);
  v3 = atoi(nptr: stop);
  v4 = V_strcasecmp(s1: stoptype, s2: "TimeUseTick");
  m_pAction = (CBaseDemoActionWithStopTime *)this->m_pAction;
  if ( v4 != 0 )
  {
    if ( m_pAction->m_flStopTime != fstop )
    {
      v2 = 1;
      CDemoActionSkipAhead::SetSkipToTime(this: m_pAction, t: fstop);
      CBaseDemoActionWithStopTime::SetStopTick(this: (CBaseDemoActionWithStopTime *)this->m_pAction, tick: -1);
    }
  }
  else if ( m_pAction->m_nStopTick != v3 )
  {
    CBaseDemoActionWithStopTime::SetStopTick(this: m_pAction, tick: v3);
    CDemoActionSkipAhead::SetSkipToTime(this: (CBaseDemoActionWithStopTime *)this->m_pAction, t: -1.0);
    return 1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10077E50
// Name: public: virtual void CBaseActionScreenFadeStartDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionScreenFadeStartDialog::Init(CBaseActionScreenFadeStartDialog *this)
{
  char *SoundName; // eax
  int v3; // edi
  int v4; // ebx
  __int16 v5; // cx
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  bool fadepurge; // [esp+28h] [ebp-24h]
  bool fadestayout; // [esp+2Ch] [ebp-20h]
  bool fademodulate; // [esp+30h] [ebp-1Ch]
  bool fadeout; // [esp+34h] [ebp-18h]
  bool fadein; // [esp+38h] [ebp-14h]
  int b; // [esp+3Ch] [ebp-10h]
  int a; // [esp+40h] [ebp-Ch]
  float holdTime; // [esp+44h] [ebp-8h]
  vgui::TextEntry_vtbl *holdTimea; // [esp+44h] [ebp-8h]
  vgui::TextEntry_vtbl *v18; // [esp+48h] [ebp-4h]
  vgui::TextEntry_vtbl *v19; // [esp+48h] [ebp-4h]

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionScreenFadeStartDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  v3 = (unsigned __int8)SoundName[6];
  v4 = (unsigned __int8)SoundName[7];
  fadein = SoundName[4] & 1;
  v5 = *((_WORD *)SoundName + 2);
  holdTime = 0.001953125 * (double)*((unsigned __int16 *)SoundName + 1);
  fadeout = (v5 & 2) != 0;
  fademodulate = (v5 & 4) != 0;
  fadepurge = (v5 & 0x10) != 0;
  fadestayout = (v5 & 8) != 0;
  b = (unsigned __int8)SoundName[8];
  a = (unsigned __int8)SoundName[9];
  v18 = this->m_pDuration->__vftable;
  v6 = va(format: "%.3f", (double)*(unsigned __int16 *)SoundName * 0.001953125);
  v18->SetText(this: this->m_pDuration, a2: v6);
  v19 = this->m_pHoldTime->__vftable;
  v7 = va(format: "%.3f", holdTime);
  v19->SetText(this: this->m_pHoldTime, a2: v7);
  holdTimea = this->m_pColor->__vftable;
  v8 = va(format: "%i %i %i %i", v3, v4, b, a);
  holdTimea->SetText(this: this->m_pColor, a2: v8);
  this->m_pFFADE_IN->SetSelected(this: this->m_pFFADE_IN, a2: fadein);
  this->m_pFFADE_OUT->SetSelected(this: this->m_pFFADE_OUT, a2: fadeout);
  this->m_pFFADE_MODULATE->SetSelected(this: this->m_pFFADE_MODULATE, a2: fademodulate);
  this->m_pFFADE_STAYOUT->SetSelected(this: this->m_pFFADE_STAYOUT, a2: fadestayout);
  this->m_pFFADE_PURGE->SetSelected(this: this->m_pFFADE_PURGE, a2: fadepurge);
}

//------------------------------------------------------------------------------
// Address: 0x10077FF0
// Name: private: void CBaseActionTextMessageStartDialog::FillInFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionTextMessageStartDialog::FillInFonts(CBaseActionTextMessageStartDialog *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  vgui::ComboBox_vtbl *v7; // edi
  const char *Name; // eax
  KeyValues *schemeFile; // [esp+4h] [ebp-4h]

  this->m_pFontName->AddItem_2(this: this->m_pFontName, a2: "TextMessageDefault", a3: nullptr);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "Fonts");
    schemeFile = v3;
    if ( v3 != nullptr )
    {
      if ( g_pFileSystem != nullptr )
        v4 = &g_pFileSystem->IBaseFileSystem;
      else
        v4 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v3,
             filesystem: v4,
             resourceName: "resource/SourceScheme.res",
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        Key = KeyValues::FindKey(this: v3, keyName: "Fonts", bCreate: true);
        FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
        if ( FirstSubKey != nullptr )
        {
          do
          {
            v7 = this->m_pFontName->__vftable;
            Name = KeyValues::GetName(this: FirstSubKey);
            v7->AddItem_2(this: this->m_pFontName, a2: Name, a3: nullptr);
            FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          }
          while ( FirstSubKey != nullptr );
          v3 = schemeFile;
        }
      }
      KeyValues::deleteThis(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100780C0
// Name: private: bool CBaseActionTextMessageStartDialog::SaveDifferingColor(class vgui::TextEntry __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionTextMessageStartDialog::SaveDifferingColor(
        CBaseActionTextMessageStartDialog *this,
        vgui::TextEntry *control,
        unsigned __int8 *r,
        unsigned __int8 *g,
        unsigned __int8 *b,
        unsigned __int8 *a)
{
  char v6; // bl
  char sz[512]; // [esp+4h] [ebp-20Ch] BYREF
  int gg; // [esp+204h] [ebp-Ch] BYREF
  int aa; // [esp+208h] [ebp-8h] BYREF
  int bb; // [esp+20Ch] [ebp-4h] BYREF

  v6 = 0;
  control->GetText_2(this: control, a2: sz, a3: 512);
  if ( sscanf(string: sz, format: "%i %i %i %i", &control, &gg, &bb, &aa) != 4 )
    return v6;
  if ( (vgui::TextEntry *)*r != control )
  {
    v6 = 1;
    *r = (unsigned __int8)control;
  }
  if ( *g != gg )
  {
    v6 = 1;
    *g = gg;
  }
  if ( *b != bb )
  {
    v6 = 1;
    *b = bb;
  }
  if ( *a == aa )
    return v6;
  *a = aa;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10078170
// Name: public: virtual bool CBaseActionTextMessageStartDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionTextMessageStartDialog::OnSaveChanges(CBaseActionTextMessageStartDialog *this)
{
  char v2; // bl
  client_textmessage_t *TextMessage; // eax
  vgui::TextEntry *m_pFadeInTime; // ecx
  client_textmessage_t *v5; // esi
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // eax
  long double v7; // st7
  char v8; // al
  vgui::TextEntry *m_pFadeOutTime; // ecx
  void (__thiscall *v10)(vgui::TextEntry *, char *, int); // edx
  char v11; // bl
  long double v12; // st7
  char v13; // al
  vgui::TextEntry *m_pHoldTime; // ecx
  void (__thiscall *v15)(vgui::TextEntry *, char *, int); // edx
  char v16; // bl
  long double v17; // st7
  char v18; // al
  vgui::TextEntry *m_pFXTime; // ecx
  void (__thiscall *v20)(vgui::TextEntry *, char *, int); // edx
  char v21; // bl
  long double v22; // st7
  char v23; // al
  vgui::TextEntry *m_pX; // ecx
  void (__thiscall *v25)(vgui::TextEntry *, char *, int); // edx
  char v26; // bl
  long double v27; // st7
  char v28; // al
  vgui::TextEntry *m_pY; // ecx
  void (__thiscall *v30)(vgui::TextEntry *, char *, int); // edx
  char v31; // bl
  long double v32; // st7
  char v33; // al
  char v34; // bl
  char v35; // bl
  bool v36; // zf
  float v37; // eax
  char *SoundName; // eax
  const char *FontName; // eax
  char sz[1024]; // [esp+Ch] [ebp-608h] BYREF
  char nptr[512]; // [esp+40Ch] [ebp-208h] BYREF
  float v43; // [esp+60Ch] [ebp-8h]
  char v44; // [esp+613h] [ebp-1h]

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  TextMessage = CDemoActionTextMessageStart::GetTextMessage(this: (CDemoActionTextMessageStart *)this->m_pAction);
  m_pFadeInTime = this->m_pFadeInTime;
  v5 = TextMessage;
  GetText_2 = m_pFadeInTime->GetText_2;
  v44 = 0;
  GetText_2(this: m_pFadeInTime, a2: nptr, a3: 512);
  v7 = atof(nptr);
  v43 = v7;
  if ( v7 == v5->fadein )
  {
    v8 = v44;
  }
  else
  {
    v5->fadein = v43;
    v8 = 1;
  }
  m_pFadeOutTime = this->m_pFadeOutTime;
  v10 = m_pFadeOutTime->GetText_2;
  v11 = v8 | v2;
  v44 = 0;
  v10(this: m_pFadeOutTime, a2: nptr, a3: 512);
  v12 = atof(nptr);
  v43 = v12;
  if ( v12 == v5->fadeout )
  {
    v13 = v44;
  }
  else
  {
    v5->fadeout = v43;
    v13 = 1;
  }
  m_pHoldTime = this->m_pHoldTime;
  v15 = m_pHoldTime->GetText_2;
  v16 = v13 | v11;
  v44 = 0;
  v15(this: m_pHoldTime, a2: nptr, a3: 512);
  v17 = atof(nptr);
  v43 = v17;
  if ( v17 == v5->holdtime )
  {
    v18 = v44;
  }
  else
  {
    v5->holdtime = v43;
    v18 = 1;
  }
  m_pFXTime = this->m_pFXTime;
  v20 = m_pFXTime->GetText_2;
  v21 = v18 | v16;
  v44 = 0;
  v20(this: m_pFXTime, a2: nptr, a3: 512);
  v22 = atof(nptr);
  v43 = v22;
  if ( v22 == v5->fxtime )
  {
    v23 = v44;
  }
  else
  {
    v5->fxtime = v43;
    v23 = 1;
  }
  m_pX = this->m_pX;
  v25 = m_pX->GetText_2;
  v26 = v23 | v21;
  v44 = 0;
  v25(this: m_pX, a2: nptr, a3: 512);
  v27 = atof(nptr);
  v43 = v27;
  if ( v27 == v5->x )
  {
    v28 = v44;
  }
  else
  {
    v5->x = v43;
    v28 = 1;
  }
  m_pY = this->m_pY;
  v30 = m_pY->GetText_2;
  v31 = v28 | v26;
  v44 = 0;
  v30(this: m_pY, a2: nptr, a3: 512);
  v32 = atof(nptr);
  v43 = v32;
  if ( v32 != v5->y )
  {
    v5->y = v43;
    v44 = 1;
  }
  v33 = CBaseActionTextMessageStartDialog::SaveDifferingColor(
          this,
          control: this->m_pColor1,
          r: &v5->r1,
          g: &v5->g1,
          b: &v5->b1,
          a: &v5->a1);
  v34 = v44 | v33 | v31;
  v35 = CBaseActionTextMessageStartDialog::SaveDifferingColor(
          this,
          control: this->m_pColor2,
          r: &v5->r2,
          g: &v5->g2,
          b: &v5->b2,
          a: &v5->a2)
      | v34;
  this->m_pEffectType->GetText_2(this: this->m_pEffectType, a2: sz, a3: 1024);
  v43 = 0.0;
  while ( 1 )
  {
    v36 = V_strcasecmp(s1: CBaseActionTextMessageStartDialog::s_EffectTypes[LODWORD(v43)].name, s2: sz) == 0;
    v37 = v43;
    if ( v36 )
      break;
    ++LODWORD(v43);
    if ( SLODWORD(v43) >= 3 )
    {
      v37 = 0.0;
      break;
    }
  }
  if ( LODWORD(v37) != v5->effect )
  {
    *(float *)&v5->effect = v37;
    v35 = 1;
  }
  this->m_pMessageText->GetText_2(this: this->m_pMessageText, a2: sz, a3: 1024);
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  if ( V_strcasecmp(s1: sz, s2: SoundName) != 0 )
  {
    CDemoActionTextMessageStart::SetMessageText(this: (CDemoActionTextMessageStart *)this->m_pAction, text: sz);
    v35 = 1;
  }
  this->m_pFontName->GetText_2(this: this->m_pFontName, a2: sz, a3: 1024);
  FontName = CDemoActionTextMessageStart::GetFontName(this: (CDemoActionTextMessageStart *)this->m_pAction);
  if ( V_strcasecmp(s1: sz, s2: FontName) == 0 )
    return v35;
  CDemoActionTextMessageStart::SetFontName(this: (CDemoActionTextMessageStart *)this->m_pAction, font: sz);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100784E0
// Name: public: virtual void CBaseActionPlayCommandsDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionPlayCommandsDialog::Init(CBaseActionPlayCommandsDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  char *SoundName; // eax

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionPlayCommandsDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pCommands->__vftable;
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  v2->SetText(this: this->m_pCommands, a2: SoundName);
}

//------------------------------------------------------------------------------
// Address: 0x10078530
// Name: public: virtual bool CBaseActionPlayCommandsDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionPlayCommandsDialog::OnSaveChanges(CBaseActionPlayCommandsDialog *this)
{
  char v2; // bl
  char *SoundName; // eax
  char commands[512]; // [esp+8h] [ebp-200h] BYREF

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pCommands->GetText_2(this: this->m_pCommands, a2: commands, a3: 512);
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  if ( V_strcasecmp(s1: commands, s2: SoundName) != 0 )
  {
    v2 = 1;
    CDemoActionPlayCommands::SetCommandStream(this: (CDemoActionPlayCommands *)this->m_pAction, stream: commands);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100785A0
// Name: public: virtual void CBaseActionCDTrackStartDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionCDTrackStartDialog::Init(CBaseActionCDTrackStartDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  int Track; // eax
  char *v4; // eax

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionCDTrackStartDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pTrackNumber->__vftable;
  Track = CDemoActionCDTrackStart::GetTrack(this: (CDemoActionCDTrackStart *)this->m_pAction);
  v4 = va(format: "%i", Track);
  v2->SetText(this: this->m_pTrackNumber, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10078600
// Name: public: virtual bool CBaseActionCDTrackStartDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionCDTrackStartDialog::OnSaveChanges(CBaseActionCDTrackStartDialog *this)
{
  char v2; // bl
  int v3; // edi
  char track[512]; // [esp+Ch] [ebp-200h] BYREF

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pTrackNumber->GetText_2(this: this->m_pTrackNumber, a2: track, a3: 512);
  v3 = atoi(nptr: track);
  if ( v3 != CDemoActionCDTrackStart::GetTrack(this: (CDemoActionCDTrackStart *)this->m_pAction) )
  {
    v2 = 1;
    CDemoActionCDTrackStart::SetTrack(this: (CDemoActionCDTrackStart *)this->m_pAction, track: v3);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10078670
// Name: public: static char const __near * CBaseActionPlaySoundStartDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseActionPlaySoundStartDialog::GetPanelClassName()
{
  return "CBaseActionPlaySoundStartDialog";
}

//------------------------------------------------------------------------------
// Address: 0x10078680
// Name: public: virtual void CBaseActionPlaySoundStartDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionPlaySoundStartDialog::Init(CBaseActionPlaySoundStartDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  char *SoundName; // eax

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionPlaySoundStartDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pSoundName->__vftable;
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  v2->SetText(this: this->m_pSoundName, a2: SoundName);
}

//------------------------------------------------------------------------------
// Address: 0x100786D0
// Name: public: virtual bool CBaseActionPlaySoundStartDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionPlaySoundStartDialog::OnSaveChanges(CBaseActionPlaySoundStartDialog *this)
{
  char v2; // bl
  char *v3; // eax
  char soundname[512]; // [esp+8h] [ebp-200h] BYREF

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pSoundName->GetText_2(this: this->m_pSoundName, a2: soundname, a3: 512);
  v3 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  if ( V_strcasecmp(s1: soundname, s2: v3) != 0 )
  {
    v2 = 1;
    CDemoActionPlaySoundStart::SetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction, name: soundname);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10078740
// Name: public: virtual void CBaseActionWithStopTimeDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionWithStopTimeDialog::Init(CBaseActionWithStopTimeDialog *this)
{
  void (__thiscall *SetText)(vgui::TextEntry *, const char *); // eax
  vgui::TextEntry_vtbl *v3; // edi
  char *v4; // eax

  CBaseActionEditDialog::Init(this);
  SetText = this->m_pStopType->SetText;
  if ( LOBYTE(this->m_pAction[1].__vftable) != 0 )
  {
    ((void (__stdcall *)(const char *))SetText)(a1: "TimeUseTick");
    v3 = this->m_pStop->__vftable;
    v4 = va(format: "%i", this->m_pAction[1].m_Type);
  }
  else
  {
    ((void (__stdcall *)(const char *))SetText)(a1: "TimeUseClock");
    v3 = this->m_pStop->__vftable;
    v4 = va(format: "%.3f", *(float *)&this->m_pAction[1].m_bActionFired);
  }
  v3->SetText(this: this->m_pStop, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100788E0
// Name: public: virtual void CBaseActionPauseDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionPauseDialog::Init(CBaseActionPauseDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  double PauseTime; // st7
  char *v4; // eax

  this->LoadControlSettings(this, a2: "resource\\BaseActionPauseDialog.res", a3: nullptr, a4: nullptr, a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pPauseTime->__vftable;
  PauseTime = CDemoActionPausePlayback::GetPauseTime(this: (CDemoActionPausePlayback *)this->m_pAction);
  v4 = va(format: "%f", PauseTime);
  v2->SetText(this: this->m_pPauseTime, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10078940
// Name: public: virtual bool CBaseActionPauseDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionPauseDialog::OnSaveChanges(CBaseActionPauseDialog *this)
{
  char v2; // bl
  double v3; // st7
  char pausetime[512]; // [esp+14h] [ebp-204h] BYREF
  float ftime; // [esp+214h] [ebp-4h]

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pPauseTime->GetText_2(this: this->m_pPauseTime, a2: pausetime, a3: 512);
  ftime = atof(nptr: pausetime);
  v3 = CDemoActionPausePlayback::GetPauseTime(this: (CDemoActionPausePlayback *)this->m_pAction);
  if ( v3 == ftime )
    return v2;
  CDemoActionPausePlayback::SetPauseTime(this: (CDemoActionPausePlayback *)this->m_pAction, t: ftime);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100789D0
// Name: public: virtual void CBaseActionZoomDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionZoomDialog::Init(CBaseActionZoomDialog *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  char *v3; // eax
  vgui::TextEntry_vtbl *v4; // edi
  char *v5; // eax
  vgui::TextEntry_vtbl *v6; // edi
  char *v7; // eax
  vgui::TextEntry_vtbl *v8; // edi
  char *v9; // eax

  this->LoadControlSettings(this, a2: "resource\\BaseActionZoomDialog.res", a3: nullptr, a4: nullptr, a5: nullptr);
  CBaseActionEditDialog::Init(this);
  v2 = this->m_pFinalFOV->__vftable;
  v3 = va(format: "%f", *(float *)&this->m_pAction[1].m_Type);
  v2->SetText(this: this->m_pFinalFOV, a2: v3);
  v4 = this->m_pOutRate->__vftable;
  v5 = va(format: "%f", *(float *)&this->m_pAction[1].m_bActionFired);
  v4->SetText(this: this->m_pOutRate, a2: v5);
  v6 = this->m_pInRate->__vftable;
  v7 = va(format: "%f", *(float *)&this->m_pAction[1].m_szActionName[2]);
  v6->SetText(this: this->m_pInRate, a2: v7);
  v8 = this->m_pHoldTime->__vftable;
  v9 = va(format: "%f", *(float *)&this->m_pAction[1].m_szActionName[6]);
  v8->SetText(this: this->m_pHoldTime, a2: v9);
  this->m_pSpline->SetSelected(this: this->m_pSpline, a2: (bool)this->m_pAction[1].__vftable);
  this->m_pStayout->SetSelected(this: this->m_pStayout, a2: BYTE1(this->m_pAction[1].__vftable));
}

//------------------------------------------------------------------------------
// Address: 0x10078B10
// Name: public: virtual bool CBaseActionZoomDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseActionZoomDialog::OnSaveChanges(CBaseActionZoomDialog *this)
{
  char v2; // bl
  long double v3; // st7
  CBaseDemoAction *m_pAction; // ecx
  long double v5; // st7
  CBaseDemoAction *v6; // ecx
  long double v7; // st7
  CBaseDemoAction *v8; // ecx
  long double v9; // st7
  CBaseDemoAction *v10; // ecx
  CBaseDemoAction *v11; // edi
  CBaseDemoAction *v12; // edi
  CBaseDemoAction *v13; // edi
  CBaseDemoAction *v14; // edi
  char sz[512]; // [esp+Ch] [ebp-204h] BYREF
  float f; // [esp+20Ch] [ebp-4h]

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  this->m_pFinalFOV->GetText_2(this: this->m_pFinalFOV, a2: sz, a3: 512);
  v3 = atof(nptr: sz);
  f = v3;
  m_pAction = this->m_pAction;
  if ( *(float *)&m_pAction[1].m_Type != v3 )
  {
    v2 = 1;
    *(float *)&m_pAction[1].m_Type = f;
  }
  this->m_pOutRate->GetText_2(this: this->m_pOutRate, a2: sz, a3: 512);
  v5 = atof(nptr: sz);
  f = v5;
  v6 = this->m_pAction;
  if ( *(float *)&v6[1].m_bActionFired != v5 )
  {
    v2 = 1;
    *(float *)&v6[1].m_bActionFired = f;
  }
  this->m_pInRate->GetText_2(this: this->m_pInRate, a2: sz, a3: 512);
  v7 = atof(nptr: sz);
  f = v7;
  v8 = this->m_pAction;
  if ( *(float *)&v8[1].m_szActionName[2] != v7 )
  {
    v2 = 1;
    *(float *)&v8[1].m_szActionName[2] = f;
  }
  this->m_pHoldTime->GetText_2(this: this->m_pHoldTime, a2: sz, a3: 512);
  v9 = atof(nptr: sz);
  f = v9;
  v10 = this->m_pAction;
  if ( *(float *)&v10[1].m_szActionName[6] != v9 )
  {
    v2 = 1;
    *(float *)&v10[1].m_szActionName[6] = f;
  }
  v11 = this->m_pAction;
  if ( this->m_pSpline->IsSelected(this: this->m_pSpline) != LOBYTE(v11[1].__vftable) )
  {
    v12 = this->m_pAction;
    v2 = 1;
    LOBYTE(v12[1].__vftable) = this->m_pSpline->IsSelected(this: this->m_pSpline);
  }
  v13 = this->m_pAction;
  if ( this->m_pStayout->IsSelected(this: this->m_pStayout) != BYTE1(v13[1].__vftable) )
  {
    v14 = this->m_pAction;
    v2 = 1;
    BYTE1(v14[1].__vftable) = this->m_pStayout->IsSelected(this: this->m_pStayout);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10078D00
// Name: public: CBaseActionEditDialog::CBaseActionEditDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__thiscall CBaseActionEditDialog::CBaseActionEditDialog(
        CBaseActionEditDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  char *v5; // eax
  const char *v6; // eax
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  char *v10; // eax
  const char *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::TextEntry *v17; // eax
  vgui::TextEntry *v18; // eax
  vgui::TextEntry *v19; // eax
  vgui::ComboBox *v20; // eax
  vgui::ComboBox *v21; // eax
  DEMOACTIONTIMINGTYPE i; // ebx
  vgui::ComboBox_vtbl *v23; // edi
  const char *v24; // eax
  const char *v26; // [esp-Ch] [ebp-18h]

  v5 = CWaveDataStreamAsync::Source(this: action);
  v6 = CBaseDemoAction::NameForType(actionType: (DEMOACTION)v5);
  vgui::Frame::Frame(this, parent, panelName: v6, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionEditDialog::`vftable';
  if ( `CBaseActionEditDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseActionEditDialog::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CBaseActionEditDialog");
    v7->pfnClassName = CBaseActionEditDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBaseActionEditDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseActionEditDialog::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CBaseActionEditDialog");
    v8->pfnClassName = CBaseActionEditDialog::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBaseActionEditDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseActionEditDialog::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionEditDialog");
    v9->pfnClassName = CBaseActionEditDialog::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pEditor = parent;
  this->m_pAction = (CBaseDemoAction *)action;
  this->m_bNewAction = newaction;
  v10 = CWaveDataStreamAsync::Source(this: action);
  v26 = CBaseDemoAction::NameForType(actionType: (DEMOACTION)v10);
  if ( newaction )
    v11 = va(format: "New %s Action", v26);
  else
    v11 = va(format: "Edit %s Action", v26);
  vgui::Frame::SetTitle(this, title: v11, surfaceTitle: true);
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "OK",
            text: "OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->m_pOK = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->m_pCancel = v15;
  v16 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v16 != nullptr )
    v17 = vgui::TextEntry::TextEntry(this: v16, parent: this, panelName: "ActionName");
  else
    v17 = nullptr;
  this->m_pActionName = v17;
  v18 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v18 != nullptr )
    v19 = vgui::TextEntry::TextEntry(this: v18, parent: this, panelName: "ActionStart");
  else
    v19 = nullptr;
  this->m_pStart = v19;
  v20 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v20 != nullptr )
    v21 = vgui::ComboBox::ComboBox(this: v20, parent: this, panelName: "ActionStartType", numLines: 3, allowEdit: false);
  else
    v21 = nullptr;
  this->m_pStartType = v21;
  for ( i = ACTION_USES_NEITHER; i < NUM_TIMING_TYPES; ++i )
  {
    v23 = this->m_pStartType->__vftable;
    v24 = CBaseDemoAction::NameForTimingType(timingType: i);
    v23->AddItem_2(this: this->m_pStartType, a2: v24, a3: nullptr);
  }
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078F70
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        vgui::Panel *this,
        const char *elementName,
        const char *x,
        int *y,
        int *wide,
        int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10078F80
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10078FA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseActionEditDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseActionEditDialog::GetMessageMap(CBaseActionEditDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseActionEditDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseActionEditDialog::GetMessageMap'::`2'::s_pMap;
  `CBaseActionEditDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseActionEditDialog");
  `CBaseActionEditDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10078FD0
// Name: public: virtual struct PanelAnimationMap __near * CBaseActionEditDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseActionEditDialog::GetAnimMap(CBaseActionEditDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseActionEditDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10078FE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseActionEditDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseActionEditDialog::GetKBMap(CBaseActionEditDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseActionEditDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseActionEditDialog::GetKBMap'::`2'::s_pMap;
  `CBaseActionEditDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionEditDialog");
  `CBaseActionEditDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079010
// Name: public: CBaseActionSkipAheadDialog::CBaseActionSkipAheadDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionSkipAheadDialog *__thiscall CBaseActionSkipAheadDialog::CBaseActionSkipAheadDialog(
        CBaseActionSkipAheadDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  DEMOACTIONTIMINGTYPE i; // ebx
  vgui::ComboBox_vtbl *v10; // esi
  const char *v11; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionSkipAheadDialog_vtbl *)&CBaseActionSkipAheadDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "ActionSkip");
  else
    v6 = nullptr;
  this->m_pSkip = v6;
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "ActionSkipType", numLines: 2, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pSkipType = v8;
  for ( i = ACTION_USES_TICK; i < NUM_TIMING_TYPES; ++i )
  {
    v10 = this->m_pSkipType->__vftable;
    v11 = CBaseDemoAction::NameForTimingType(timingType: i);
    v10->AddItem_2(this: this->m_pSkipType, a2: v11, a3: nullptr);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10079100
// Name: FnCreateEditorCBaseActionSkipAheadDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionSkipAheadDialog *__cdecl FnCreateEditorCBaseActionSkipAheadDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionSkipAheadDialog *v3; // eax
  CBaseActionSkipAheadDialog *result; // eax
  CBaseActionSkipAheadDialog *v5; // esi

  v3 = (CBaseActionSkipAheadDialog *)MemAlloc_Alloc(nSize: 0x23Cu);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionSkipAheadDialog::CBaseActionSkipAheadDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079150
// Name: public: virtual void CBaseActionStopPlaybackDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionStopPlaybackDialog::Init(CBaseActionStopPlaybackDialog *this)
{
  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionStopPlaybackDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x10079170
// Name: FnCreateEditorCBaseActionStopPlaybackDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl FnCreateEditorCBaseActionStopPlaybackDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionEditDialog *v3; // esi

  v3 = (CBaseActionEditDialog *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v3 == nullptr )
    return nullptr;
  CBaseActionEditDialog::CBaseActionEditDialog(this: v3, parent, action, newaction);
  v3->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionStopPlaybackDialog::`vftable';
  v3->Init(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100791C0
// Name: public: CBaseActionScreenFadeStartDialog::CBaseActionScreenFadeStartDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionScreenFadeStartDialog *__thiscall CBaseActionScreenFadeStartDialog::CBaseActionScreenFadeStartDialog(
        CBaseActionScreenFadeStartDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::CheckButton *v9; // eax
  vgui::CheckButton *v10; // eax
  vgui::CheckButton *v11; // eax
  vgui::CheckButton *v12; // eax
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // eax
  vgui::CheckButton *v15; // eax
  vgui::CheckButton *v16; // eax
  vgui::CheckButton *v17; // eax
  vgui::CheckButton *v18; // eax
  vgui::TextEntry *v19; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionScreenFadeStartDialog_vtbl *)&CBaseActionScreenFadeStartDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "ScreenFadeDuration");
  else
    v6 = nullptr;
  this->m_pDuration = v6;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "ScreenFadeHoldTime");
  else
    v8 = nullptr;
  this->m_pHoldTime = v8;
  v9 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v9 != nullptr )
    v10 = vgui::CheckButton::CheckButton(this: v9, parent: this, panelName: "ScreenFadeFFADE_IN", text: "Fade in");
  else
    v10 = nullptr;
  this->m_pFFADE_IN = v10;
  v11 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v11 != nullptr )
    v12 = vgui::CheckButton::CheckButton(this: v11, parent: this, panelName: "ScreenFadeFFADE_OUT", text: "Fade out");
  else
    v12 = nullptr;
  this->m_pFFADE_OUT = v12;
  v13 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v13 != nullptr )
    v14 = vgui::CheckButton::CheckButton(
            this: v13,
            parent: this,
            panelName: "ScreenFadeFFADE_MODULATE",
            text: "Modulate");
  else
    v14 = nullptr;
  this->m_pFFADE_MODULATE = v14;
  v15 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v15 != nullptr )
    v16 = vgui::CheckButton::CheckButton(
            this: v15,
            parent: this,
            panelName: "ScreenFadeFFADE_STAYOUT",
            text: "Stay out");
  else
    v16 = nullptr;
  this->m_pFFADE_STAYOUT = v16;
  v17 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v17 != nullptr )
    v18 = vgui::CheckButton::CheckButton(this: v17, parent: this, panelName: "ScreenFadeFFADE_Purge", text: "Purge");
  else
    v18 = nullptr;
  this->m_pFFADE_PURGE = v18;
  v19 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v19 != nullptr )
    this->m_pColor = vgui::TextEntry::TextEntry(this: v19, parent: this, panelName: "ScreenFadeColor");
  else
    this->m_pColor = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10079350
// Name: public: virtual bool CBaseActionScreenFadeStartDialog::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseActionScreenFadeStartDialog::OnSaveChanges(CBaseActionScreenFadeStartDialog *this)
{
  char v2; // al
  CDemoActionPlaySoundStart *m_pAction; // ecx
  char *SoundName; // esi
  int v5; // ecx
  __int16 v6; // ax
  char v7; // bl
  char v8; // dl
  int v9; // xmm0_4
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  vgui::TextEntry *m_pDuration; // ecx
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // edx
  char v16; // bl
  long double v17; // st6
  long double v18; // st6
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  vgui::CheckButton *m_pFFADE_IN; // esi
  char *v24; // ebx
  vgui::CheckButton *m_pFFADE_OUT; // esi
  bool v26; // al
  char *v27; // ebx
  vgui::CheckButton *m_pFFADE_MODULATE; // esi
  bool v29; // al
  char *v30; // ebx
  vgui::CheckButton *m_pFFADE_STAYOUT; // esi
  bool v32; // al
  char *v33; // ebx
  vgui::CheckButton *m_pFFADE_PURGE; // esi
  bool v35; // al
  char *v36; // edi
  char sz[512]; // [esp+Ch] [ebp-234h] BYREF
  int g; // [esp+20Ch] [ebp-34h]
  int a; // [esp+210h] [ebp-30h]
  int b; // [esp+214h] [ebp-2Ch]
  int r; // [esp+218h] [ebp-28h]
  int rr; // [esp+21Ch] [ebp-24h] BYREF
  int aa; // [esp+220h] [ebp-20h] BYREF
  int gg; // [esp+224h] [ebp-1Ch] BYREF
  int bb; // [esp+228h] [ebp-18h] BYREF
  int holdTime; // [esp+22Ch] [ebp-14h]
  bool fadepurge; // [esp+230h] [ebp-10h]
  bool fademodulate; // [esp+231h] [ebp-Fh]
  bool fadeout; // [esp+232h] [ebp-Eh]
  bool fadestayout; // [esp+233h] [ebp-Dh]
  int v52; // [esp+234h] [ebp-Ch]
  int duration; // [esp+238h] [ebp-8h]
  bool bret; // [esp+23Fh] [ebp-1h]

  v2 = CBaseActionEditDialog::OnSaveChanges(this);
  m_pAction = (CDemoActionPlaySoundStart *)this->m_pAction;
  bret = v2;
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: m_pAction);
  v5 = *((unsigned __int16 *)SoundName + 1);
  duration = *(unsigned __int16 *)SoundName;
  v6 = *((_WORD *)SoundName + 2);
  v7 = SoundName[4];
  fadeout = (v6 & 2) != 0;
  v8 = v6;
  *(float *)&duration = (double)duration * 0.001953125;
  *(float *)&v9 = (float)v5 * 0.001953125;
  LOBYTE(v5) = v6;
  fadepurge = (v6 & 0x10) != 0;
  v10 = (unsigned __int8)SoundName[6];
  fademodulate = (v5 & 4) != 0;
  v11 = (unsigned __int8)SoundName[7];
  fadestayout = (v8 & 8) != 0;
  v12 = (unsigned __int8)SoundName[8];
  r = v10;
  v13 = (unsigned __int8)SoundName[9];
  g = v11;
  m_pDuration = this->m_pDuration;
  b = v12;
  GetText_2 = m_pDuration->GetText_2;
  a = v13;
  holdTime = v9;
  v16 = v7 & 1;
  GetText_2(this: m_pDuration, a2: sz, a3: 512);
  v17 = atof(nptr: sz);
  if ( v17 != *(float *)&duration )
  {
    bret = true;
    duration = (int)(atof(nptr: sz) * 512.0);
    *(_WORD *)SoundName = duration;
  }
  this->m_pHoldTime->GetText_2(this: this->m_pHoldTime, a2: sz, a3: 512);
  v18 = atof(nptr: sz);
  if ( v18 != *(float *)&holdTime )
  {
    bret = true;
    holdTime = (int)(atof(nptr: sz) * 512.0);
    *((_WORD *)SoundName + 1) = holdTime;
  }
  this->m_pColor->GetText_2(this: this->m_pColor, a2: sz, a3: 512);
  if ( sscanf(string: sz, format: "%i %i %i %i", &rr, &gg, &bb, &aa) == 4 )
  {
    if ( rr >= 0 )
    {
      v19 = 255;
      if ( rr <= 255 )
        v19 = rr;
    }
    else
    {
      v19 = 0;
    }
    v20 = gg;
    duration = v19;
    rr = v19;
    if ( gg >= 0 )
    {
      if ( gg > 255 )
        v20 = 255;
    }
    else
    {
      v20 = 0;
    }
    v52 = v20;
    gg = v20;
    if ( bb >= 0 )
    {
      v21 = 255;
      if ( bb <= 255 )
        v21 = bb;
    }
    else
    {
      v21 = 0;
    }
    v22 = aa;
    bb = v21;
    if ( aa >= 0 )
    {
      if ( aa > 255 )
        v22 = 255;
    }
    else
    {
      v22 = 0;
    }
    aa = v22;
    if ( v19 != r || v52 != g || v21 != b || v22 != a )
    {
      SoundName[6] = duration;
      SoundName[7] = gg;
      SoundName[8] = bb;
      bret = true;
      SoundName[9] = aa;
    }
  }
  m_pFFADE_IN = this->m_pFFADE_IN;
  if ( m_pFFADE_IN->IsSelected(this: m_pFFADE_IN) != v16 )
  {
    v24 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
    if ( m_pFFADE_IN->IsSelected(this: m_pFFADE_IN) )
      *((_WORD *)v24 + 2) |= 1u;
    else
      *((_WORD *)v24 + 2) &= ~1u;
    bret = true;
  }
  m_pFFADE_OUT = this->m_pFFADE_OUT;
  v26 = m_pFFADE_OUT->IsSelected(this: m_pFFADE_OUT);
  if ( v26 != fadeout )
  {
    v27 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
    if ( m_pFFADE_OUT->IsSelected(this: m_pFFADE_OUT) )
      *((_WORD *)v27 + 2) |= 2u;
    else
      *((_WORD *)v27 + 2) &= ~2u;
    bret = true;
  }
  m_pFFADE_MODULATE = this->m_pFFADE_MODULATE;
  v29 = m_pFFADE_MODULATE->IsSelected(this: m_pFFADE_MODULATE);
  if ( v29 != fademodulate )
  {
    v30 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
    if ( m_pFFADE_MODULATE->IsSelected(this: m_pFFADE_MODULATE) )
      *((_WORD *)v30 + 2) |= 4u;
    else
      *((_WORD *)v30 + 2) &= ~4u;
    bret = true;
  }
  m_pFFADE_STAYOUT = this->m_pFFADE_STAYOUT;
  v32 = m_pFFADE_STAYOUT->IsSelected(this: m_pFFADE_STAYOUT);
  if ( v32 != fadestayout )
  {
    v33 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
    if ( m_pFFADE_STAYOUT->IsSelected(this: m_pFFADE_STAYOUT) )
      *((_WORD *)v33 + 2) |= 8u;
    else
      *((_WORD *)v33 + 2) &= ~8u;
    bret = true;
  }
  m_pFFADE_PURGE = this->m_pFFADE_PURGE;
  v35 = m_pFFADE_PURGE->IsSelected(this: m_pFFADE_PURGE);
  if ( v35 == fadepurge )
    return bret;
  v36 = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  if ( m_pFFADE_PURGE->IsSelected(this: m_pFFADE_PURGE) )
    *((_WORD *)v36 + 2) |= 0x10u;
  else
    *((_WORD *)v36 + 2) &= ~0x10u;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10079730
// Name: FnCreateEditorCBaseActionScreenFadeStartDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionScreenFadeStartDialog *__cdecl FnCreateEditorCBaseActionScreenFadeStartDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionScreenFadeStartDialog *v3; // eax
  CBaseActionScreenFadeStartDialog *result; // eax
  CBaseActionScreenFadeStartDialog *v5; // esi

  v3 = (CBaseActionScreenFadeStartDialog *)MemAlloc_Alloc(nSize: 0x254u);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionScreenFadeStartDialog::CBaseActionScreenFadeStartDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079780
// Name: public: CBaseActionTextMessageStartDialog::CBaseActionTextMessageStartDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionTextMessageStartDialog *__thiscall CBaseActionTextMessageStartDialog::CBaseActionTextMessageStartDialog(
        CBaseActionTextMessageStartDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::ComboBox *v15; // eax
  vgui::ComboBox *v16; // eax
  vgui::TextEntry *v17; // eax
  vgui::TextEntry *v18; // eax
  vgui::TextEntry *v19; // eax
  vgui::TextEntry *v20; // eax
  vgui::TextEntry *v21; // eax
  vgui::TextEntry *v22; // eax
  vgui::TextEntry *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::ComboBox *v25; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionTextMessageStartDialog_vtbl *)&CBaseActionTextMessageStartDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "TextMessageFadeInTime");
  else
    v6 = nullptr;
  this->m_pFadeInTime = v6;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "TextMessageFadeOutTime");
  else
    v8 = nullptr;
  this->m_pFadeOutTime = v8;
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "TextMessageHoldTime");
  else
    v10 = nullptr;
  this->m_pHoldTime = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "TextMessageFXTime");
  else
    v12 = nullptr;
  this->m_pFXTime = v12;
  v13 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v13 != nullptr )
    v14 = vgui::TextEntry::TextEntry(this: v13, parent: this, panelName: "TextMessageText");
  else
    v14 = nullptr;
  this->m_pMessageText = v14;
  v15 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v15 != nullptr )
    v16 = vgui::ComboBox::ComboBox(this: v15, parent: this, panelName: "TextMessageFont", numLines: 6, allowEdit: false);
  else
    v16 = nullptr;
  this->m_pFontName = v16;
  v17 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v17 != nullptr )
    v18 = vgui::TextEntry::TextEntry(this: v17, parent: this, panelName: "TextMessageX");
  else
    v18 = nullptr;
  this->m_pX = v18;
  v19 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v19 != nullptr )
    v20 = vgui::TextEntry::TextEntry(this: v19, parent: this, panelName: "TextMessageY");
  else
    v20 = nullptr;
  this->m_pY = v20;
  v21 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v21 != nullptr )
    v22 = vgui::TextEntry::TextEntry(this: v21, parent: this, panelName: "TextMessageColor1");
  else
    v22 = nullptr;
  this->m_pColor1 = v22;
  v23 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v23 != nullptr )
    v24 = vgui::TextEntry::TextEntry(this: v23, parent: this, panelName: "TextMessageColor2");
  else
    v24 = nullptr;
  this->m_pColor2 = v24;
  v25 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v25 != nullptr )
    this->m_pEffectType = vgui::ComboBox::ComboBox(
                            this: v25,
                            parent: this,
                            panelName: "TextMessageEffect",
                            numLines: 3,
                            allowEdit: false);
  else
    this->m_pEffectType = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10079980
// Name: public: virtual void CBaseActionTextMessageStartDialog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionTextMessageStartDialog::Init(CBaseActionTextMessageStartDialog *this)
{
  client_textmessage_t *TextMessage; // edi
  vgui::TextEntry_vtbl *v3; // ebx
  char *v4; // eax
  vgui::TextEntry_vtbl *v5; // ebx
  char *v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  char *v8; // eax
  vgui::TextEntry_vtbl *v9; // ebx
  char *v10; // eax
  vgui::TextEntry_vtbl *v11; // ebx
  char *v12; // eax
  vgui::TextEntry_vtbl *v13; // ebx
  char *v14; // eax
  vgui::TextEntry_vtbl *v15; // ebx
  char *v16; // eax
  vgui::TextEntry_vtbl *v17; // ebx
  char *v18; // eax
  vgui::TextEntry_vtbl *v19; // ebx
  char *SoundName; // eax
  vgui::ComboBox_vtbl *v21; // ebx
  const char *FontName; // eax
  CBaseActionTextMessageStartDialog::EffectType *v23; // ebx

  this->LoadControlSettings(
    this,
    a2: "resource\\BaseActionTextMessageStartDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  CBaseActionEditDialog::Init(this);
  TextMessage = CDemoActionTextMessageStart::GetTextMessage(this: (CDemoActionTextMessageStart *)this->m_pAction);
  v3 = this->m_pX->__vftable;
  v4 = va(format: "%f", TextMessage->x);
  v3->SetText(this: this->m_pX, a2: v4);
  v5 = this->m_pY->__vftable;
  v6 = va(format: "%f", TextMessage->y);
  v5->SetText(this: this->m_pY, a2: v6);
  v7 = this->m_pFadeInTime->__vftable;
  v8 = va(format: "%.3f", TextMessage->fadein);
  v7->SetText(this: this->m_pFadeInTime, a2: v8);
  v9 = this->m_pFadeOutTime->__vftable;
  v10 = va(format: "%.3f", TextMessage->fadeout);
  v9->SetText(this: this->m_pFadeOutTime, a2: v10);
  v11 = this->m_pHoldTime->__vftable;
  v12 = va(format: "%.3f", TextMessage->holdtime);
  v11->SetText(this: this->m_pHoldTime, a2: v12);
  v13 = this->m_pFXTime->__vftable;
  v14 = va(format: "%.3f", TextMessage->fxtime);
  v13->SetText(this: this->m_pFXTime, a2: v14);
  v15 = this->m_pColor1->__vftable;
  v16 = va(format: "%i %i %i %i", TextMessage->r1, TextMessage->g1, TextMessage->b1, TextMessage->a1);
  v15->SetText(this: this->m_pColor1, a2: v16);
  v17 = this->m_pColor2->__vftable;
  v18 = va(format: "%i %i %i %i", TextMessage->r2, TextMessage->g2, TextMessage->b2, TextMessage->a2);
  v17->SetText(this: this->m_pColor2, a2: v18);
  v19 = this->m_pMessageText->__vftable;
  SoundName = CDemoActionPlaySoundStart::GetSoundName(this: (CDemoActionPlaySoundStart *)this->m_pAction);
  v19->SetText(this: this->m_pMessageText, a2: SoundName);
  CBaseActionTextMessageStartDialog::FillInFonts(this);
  v21 = this->m_pFontName->__vftable;
  FontName = CDemoActionTextMessageStart::GetFontName(this: (CDemoActionTextMessageStart *)this->m_pAction);
  v21->SetText(this: this->m_pFontName, a2: FontName);
  v23 = CBaseActionTextMessageStartDialog::s_EffectTypes;
  do
  {
    this->m_pEffectType->AddItem_2(this: this->m_pEffectType, a2: v23->name, a3: nullptr);
    ++v23;
  }
  while ( (int)v23 < (int)&CBaseActionEditDialog `RTTI Type Descriptor' );
  this->m_pEffectType->SetText(
    this: this->m_pEffectType,
    a2: CBaseActionTextMessageStartDialog::s_EffectTypes[TextMessage->effect].name);
}

//------------------------------------------------------------------------------
// Address: 0x10079BC0
// Name: FnCreateEditorCBaseActionTextMessageStartDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionTextMessageStartDialog *__cdecl FnCreateEditorCBaseActionTextMessageStartDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionTextMessageStartDialog *v3; // eax
  CBaseActionTextMessageStartDialog *result; // eax
  CBaseActionTextMessageStartDialog *v5; // esi

  v3 = (CBaseActionTextMessageStartDialog *)MemAlloc_Alloc(nSize: 0x260u);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionTextMessageStartDialog::CBaseActionTextMessageStartDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079C10
// Name: FnCreateEditorCBaseActionPlayCommandsDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl FnCreateEditorCBaseActionPlayCommandsDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionEditDialog *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax

  v3 = (CBaseActionEditDialog *)MemAlloc_Alloc(nSize: 0x238u);
  if ( v3 == nullptr )
    return nullptr;
  CBaseActionEditDialog::CBaseActionEditDialog(this: v3, parent, action, newaction);
  v3->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionPlayCommandsDialog::`vftable';
  v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v4 != nullptr )
    v5 = vgui::TextEntry::TextEntry(this: v4, parent: v3, panelName: "Commands");
  else
    v5 = nullptr;
  v3[1].__vftable = (CBaseActionEditDialog_vtbl *)v5;
  v3->Init(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10079C80
// Name: FnCreateEditorCBaseActionCDTrackStartDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionEditDialog *__cdecl FnCreateEditorCBaseActionCDTrackStartDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionEditDialog *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax

  v3 = (CBaseActionEditDialog *)MemAlloc_Alloc(nSize: 0x238u);
  if ( v3 == nullptr )
    return nullptr;
  CBaseActionEditDialog::CBaseActionEditDialog(this: v3, parent, action, newaction);
  v3->__vftable = (CBaseActionEditDialog_vtbl *)&CBaseActionCDTrackStartDialog::`vftable';
  v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v4 != nullptr )
    v5 = vgui::TextEntry::TextEntry(this: v4, parent: v3, panelName: "TrackNumber");
  else
    v5 = nullptr;
  v3[1].__vftable = (CBaseActionEditDialog_vtbl *)v5;
  v3->Init(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10079CF0
// Name: private: virtual void CBaseActionPlaySoundStartDialog::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseActionPlaySoundStartDialog::OnFileSelected(
        CBaseActionPlaySoundStartDialog *this@<ecx>,
        int a2@<esi>,
        const char *fullpath)
{
  vgui::Panel *v4; // eax
  char relativepath[512]; // [esp+4h] [ebp-200h] BYREF

  if ( fullpath != nullptr && *fullpath != 0 )
  {
    ((void (__thiscall *)(IFileSystem *, const char *, char *, int, int))g_pFileSystem->FullPathToRelativePath)(
      a1: g_pFileSystem,
      a2: fullpath,
      a3: relativepath,
      a4: 512,
      a5: a2);
    V_FixSlashes(pname: relativepath, separator: 92);
    V_strnicmp(s1: relativepath, s2: "sound\\", n: 6);
    ((void (__thiscall *)(vgui::TextEntry *))this->m_pSoundName->SetText)(a1: this->m_pSoundName);
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      v4->MarkForDeletion(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079D90
// Name: public: virtual void CBaseActionPlaySoundStartDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseActionPlaySoundStartDialog::OnCommand(CBaseActionPlaySoundStartDialog *this, const char *command)
{
  vgui::DHANDLE<vgui::FileOpenDialog> *p_m_hFileOpenDialog; // esi
  vgui::FileOpenDialog *v4; // eax
  CDragDropHelperPanel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::FileOpenDialog *v7; // edi
  const char *v8; // eax
  vgui::FileOpenDialog *v9; // eax
  char startPath[260]; // [esp+8h] [ebp-104h] BYREF

  if ( V_strcasecmp(s1: command, s2: "choosesound") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "OK") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "Cancel") != 0 )
        vgui::Frame::OnCommand(this, command);
      else
        this->OnCancel(this);
    }
    else
    {
      this->OnClose(this);
    }
  }
  else
  {
    p_m_hFileOpenDialog = &this->m_hFileOpenDialog;
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
    {
      v4 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
      if ( v4 != nullptr )
        v5 = (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                       this: v4,
                                       parent: this,
                                       title: "Choose .wav file",
                                       bOpenOnly: true,
                                       pContextKeyValues: nullptr);
      else
        v5 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
        pPanel: v5);
      v6 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v6->__vftable[1].GetUnpackStructure)(a1: v6, a2: 0);
    }
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      V_strncpy(pDest: startPath, pSrc: com_gamedir, maxLen: 260);
      V_FixSlashes(pname: startPath, separator: 92);
      v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      v8 = va(format: "%s/sound", startPath);
      vgui::FileOpenDialog::SetStartDirectory(this: v7, dir: v8);
      v9 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: p_m_hFileOpenDialog);
      vgui::FileOpenDialog::DoModal(this: v9, bUnused: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079EE0
// Name: public: CBaseActionWithStopTimeDialog::CBaseActionWithStopTimeDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionWithStopTimeDialog *__thiscall CBaseActionWithStopTimeDialog::CBaseActionWithStopTimeDialog(
        CBaseActionWithStopTimeDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  DEMOACTIONTIMINGTYPE i; // ebx
  vgui::ComboBox_vtbl *v10; // esi
  const char *v11; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionWithStopTimeDialog_vtbl *)&CBaseActionWithStopTimeDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "ActionStop");
  else
    v6 = nullptr;
  this->m_pStop = v6;
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "ActionStopType", numLines: 2, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pStopType = v8;
  for ( i = ACTION_USES_TICK; i < NUM_TIMING_TYPES; ++i )
  {
    v10 = this->m_pStopType->__vftable;
    v11 = CBaseDemoAction::NameForTimingType(timingType: i);
    v10->AddItem_2(this: this->m_pStopType, a2: v11, a3: nullptr);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A080
// Name: public: CBaseActionZoomDialog::CBaseActionZoomDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionZoomDialog *__thiscall CBaseActionZoomDialog::CBaseActionZoomDialog(
        CBaseActionZoomDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // eax
  vgui::CheckButton *v15; // eax

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionZoomDialog_vtbl *)&CBaseActionZoomDialog::`vftable';
  v5 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: this, panelName: "ZoomFOV");
  else
    v6 = nullptr;
  this->m_pFinalFOV = v6;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "ZoomOut");
  else
    v8 = nullptr;
  this->m_pOutRate = v8;
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "ZoomIn");
  else
    v10 = nullptr;
  this->m_pInRate = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "ZoomHold");
  else
    v12 = nullptr;
  this->m_pHoldTime = v12;
  v13 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v13 != nullptr )
    v14 = vgui::CheckButton::CheckButton(this: v13, parent: this, panelName: "ZoomSpline", text: "Spline");
  else
    v14 = nullptr;
  this->m_pSpline = v14;
  v15 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v15 != nullptr )
    this->m_pStayout = vgui::CheckButton::CheckButton(
                         this: v15,
                         parent: this,
                         panelName: "ZoomStayout",
                         text: "Stay Out");
  else
    this->m_pStayout = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A1B0
// Name: FnCreateEditorCBaseActionZoomDialog
// Source: json
//------------------------------------------------------------------------------
CBaseActionZoomDialog *__cdecl FnCreateEditorCBaseActionZoomDialog(
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  CBaseActionZoomDialog *v3; // eax
  CBaseActionZoomDialog *result; // eax
  CBaseActionZoomDialog *v5; // esi

  v3 = (CBaseActionZoomDialog *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v3 == nullptr )
    return nullptr;
  result = CBaseActionZoomDialog::CBaseActionZoomDialog(this: v3, parent, action, newaction);
  v5 = result;
  if ( result != nullptr )
  {
    result->Init(this: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A280
// Name: public: static void CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseActionPlaySoundStartDialog");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A320
// Name: public: CBaseActionPlaySoundStartDialog::CBaseActionPlaySoundStartDialog(class CDemoEditorPanel __near *,class CBaseDemoAction __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseActionPlaySoundStartDialog *__thiscall CBaseActionPlaySoundStartDialog::CBaseActionPlaySoundStartDialog(
        CBaseActionPlaySoundStartDialog *this,
        CDemoEditorPanel *parent,
        vgui::Tooltip *action,
        bool newaction)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::Button *v10; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseActionEditDialog::CBaseActionEditDialog(this, parent, action, newaction);
  this->__vftable = (CBaseActionPlaySoundStartDialog_vtbl *)&CBaseActionPlaySoundStartDialog::`vftable';
  if ( `CBaseActionPlaySoundStartDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseActionPlaySoundStartDialog::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseActionPlaySoundStartDialog");
    v5->pfnClassName = CBaseActionPlaySoundStartDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseActionEditDialog");
  }
  if ( `CBaseActionPlaySoundStartDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseActionPlaySoundStartDialog::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseActionPlaySoundStartDialog");
    v6->pfnClassName = CBaseActionPlaySoundStartDialog::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseActionEditDialog");
  }
  if ( `CBaseActionPlaySoundStartDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseActionPlaySoundStartDialog::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionPlaySoundStartDialog");
    v7->pfnClassName = CBaseActionPlaySoundStartDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionEditDialog");
  }
  CBaseActionPlaySoundStartDialog::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  this->m_hFileOpenDialog.m_iPanelID = -1;
  v8 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: "SoundName");
  else
    v9 = nullptr;
  this->m_pSoundName = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    this->m_pChooseSound = vgui::Button::Button(
                             this: v10,
                             parent: this,
                             panelName: "ChooseSound",
                             text: "Choose...",
                             pActionSignalTarget: nullptr,
                             pCmd: nullptr);
  else
    this->m_pChooseSound = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A460
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseActionPlaySoundStartDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseActionPlaySoundStartDialog::GetMessageMap(CBaseActionPlaySoundStartDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseActionPlaySoundStartDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseActionPlaySoundStartDialog::GetMessageMap'::`2'::s_pMap;
  `CBaseActionPlaySoundStartDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseActionPlaySoundStartDialog");
  `CBaseActionPlaySoundStartDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A490
// Name: public: virtual struct PanelAnimationMap __near * CBaseActionPlaySoundStartDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseActionPlaySoundStartDialog::GetAnimMap(CBaseActionPlaySoundStartDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseActionPlaySoundStartDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1007A4A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseActionPlaySoundStartDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseActionPlaySoundStartDialog::GetKBMap(CBaseActionPlaySoundStartDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseActionPlaySoundStartDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseActionPlaySoundStartDialog::GetKBMap'::`2'::s_pMap;
  `CBaseActionPlaySoundStartDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseActionPlaySoundStartDialog");
  `CBaseActionPlaySoundStartDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031E0A0
// Name: _dynamic_initializer_for__editor_toggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__editor_toggle__()
{
  ConCommand::ConCommand(
    this: &editor_toggle,
    pName: "editor_toggle",
    callback: EditorToggle_f,
    pHelpString: "Disables the simulation and returns focus to the editor",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__editor_toggle__);
}

//------------------------------------------------------------------------------
// Address: 0x10326C30
// Name: _dynamic_atexit_destructor_for__editor_toggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__editor_toggle__()
{
  ConCommand::~ConCommand(this: &editor_toggle);
}

//------------------------------------------------------------------------------
// Address: 0x1031E0D0
// Name: _dynamic_initializer_for__g_TextModeLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TextModeLine__()
{
  g_TextModeLine.m_Size = 0;
  g_TextModeLine.m_pElements = g_TextModeLine.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_TextModeLine__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E120
// Name: _dynamic_initializer_for____g_CreateCEngineAPIIEngineAPI_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineAPIIEngineAPI_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineAPIIEngineAPI_reg,
           fn: (void *(__cdecl *)())_CreateCEngineAPIIEngineAPI_interface,
           pName: "VENGINE_LAUNCHER_API_VERSION004");
}

//------------------------------------------------------------------------------
// Address: 0x1031E140
// Name: _dynamic_initializer_for__reload_vjobs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reload_vjobs_command__()
{
  ConCommand::ConCommand(
    this: &reload_vjobs_command,
    pName: "reload_vjobs",
    callback: (void (__cdecl *)(const CCommand *))reload_vjobs,
    pHelpString: "reload vjobs module",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__reload_vjobs_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326C40
// Name: _dynamic_atexit_destructor_for__reload_vjobs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reload_vjobs_command__()
{
  ConCommand::~ConCommand(this: &reload_vjobs_command);
}

} // namespace engine_xlsp
