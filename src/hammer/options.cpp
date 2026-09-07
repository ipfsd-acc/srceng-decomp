// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/options.cpp
// Functions: 91
// ============================================================

#include "hammer\options.h"

//------------------------------------------------------------------------------
// Address: 0x1008A3A0
// Name: public: virtual CTypedPtrArray<class CPtrArray,class CGameConfig __near *>::~CTypedPtrArray<class CPtrArray,class CGameConfig __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTypedPtrArray<CPtrArray,CGameConfig *>::~CTypedPtrArray<CPtrArray,CGameConfig *>(
        CTypedPtrArray<CPtrArray,CCommandSequence *> *this)
{
  CPtrArray::~CPtrArray(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008A3E0
// Name: HammerSettingsFound
// Source: json
//------------------------------------------------------------------------------
char __cdecl HammerSettingsFound()
{
  char v0; // bl
  HKEY__ *hkeyConfigured; // [esp+8h] [ebp-10h] BYREF
  HKEY__ *hkeySoftware; // [esp+Ch] [ebp-Ch] BYREF
  HKEY__ *hkeyValve; // [esp+10h] [ebp-8h] BYREF
  HKEY__ *hkeyHammer; // [esp+14h] [ebp-4h] BYREF

  v0 = 0;
  if ( RegOpenKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: "Software",
         ulOptions: 0,
         samDesired: 0x2001Fu,
         phkResult: &hkeySoftware) == 0 )
  {
    if ( RegOpenKeyExA(hKey: hkeySoftware, lpSubKey: "Valve", ulOptions: 0, samDesired: 0x2001Fu, phkResult: &hkeyValve) == 0 )
    {
      if ( RegOpenKeyExA(
             hKey: hkeyValve,
             lpSubKey: "Hammer",
             ulOptions: 0,
             samDesired: 0x2001Fu,
             phkResult: &hkeyHammer) == 0 )
      {
        if ( RegOpenKeyExA(
               hKey: hkeyHammer,
               lpSubKey: "Configured",
               ulOptions: 0,
               samDesired: 0x2001Fu,
               phkResult: &hkeyConfigured) == 0 )
        {
          v0 = 1;
          RegCloseKey(hKey: hkeyConfigured);
        }
        RegCloseKey(hKey: hkeyHammer);
      }
      RegCloseKey(hKey: hkeyValve);
    }
    RegCloseKey(hKey: hkeySoftware);
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A490
// Name: ValveHammerEditorSettingsFound
// Source: json
//------------------------------------------------------------------------------
char __cdecl ValveHammerEditorSettingsFound()
{
  char v0; // bl
  HKEY__ *hkeyConfigured; // [esp+8h] [ebp-10h] BYREF
  HKEY__ *hkeySoftware; // [esp+Ch] [ebp-Ch] BYREF
  HKEY__ *hkeyValve; // [esp+10h] [ebp-8h] BYREF
  HKEY__ *hkeyHammer; // [esp+14h] [ebp-4h] BYREF

  v0 = 0;
  if ( RegOpenKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: "Software",
         ulOptions: 0,
         samDesired: 0x2001Fu,
         phkResult: &hkeySoftware) == 0 )
  {
    if ( RegOpenKeyExA(hKey: hkeySoftware, lpSubKey: "Valve", ulOptions: 0, samDesired: 0x2001Fu, phkResult: &hkeyValve) == 0 )
    {
      if ( RegOpenKeyExA(
             hKey: hkeyValve,
             lpSubKey: "Valve Hammer Editor",
             ulOptions: 0,
             samDesired: 0x2001Fu,
             phkResult: &hkeyHammer) == 0 )
      {
        if ( RegOpenKeyExA(
               hKey: hkeyHammer,
               lpSubKey: "Configured",
               ulOptions: 0,
               samDesired: 0x2001Fu,
               phkResult: &hkeyConfigured) == 0 )
        {
          v0 = 1;
          RegCloseKey(hKey: hkeyConfigured);
        }
        RegCloseKey(hKey: hkeyHammer);
      }
      RegCloseKey(hKey: hkeyValve);
    }
    RegCloseKey(hKey: hkeySoftware);
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A540
// Name: WorldcraftSettingsFound
// Source: json
//------------------------------------------------------------------------------
char __cdecl WorldcraftSettingsFound()
{
  char v0; // bl
  HKEY__ *hkeyWorldcraft; // [esp+8h] [ebp-Ch] BYREF
  HKEY__ *hkeySoftware; // [esp+Ch] [ebp-8h] BYREF
  HKEY__ *hkeyValve; // [esp+10h] [ebp-4h] BYREF

  v0 = 0;
  if ( RegOpenKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: "Software",
         ulOptions: 0,
         samDesired: 0x2001Fu,
         phkResult: &hkeySoftware) == 0 )
  {
    if ( RegOpenKeyExA(hKey: hkeySoftware, lpSubKey: "Valve", ulOptions: 0, samDesired: 0x2001Fu, phkResult: &hkeyValve) == 0 )
    {
      if ( RegOpenKeyExA(
             hKey: hkeyValve,
             lpSubKey: "Worldcraft",
             ulOptions: 0,
             samDesired: 0x2001Fu,
             phkResult: &hkeyWorldcraft) == 0 )
      {
        v0 = 1;
        RegCloseKey(hKey: hkeyWorldcraft);
      }
      RegCloseKey(hKey: hkeyValve);
    }
    RegCloseKey(hKey: hkeySoftware);
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A5E0
// Name: public: int COptions::SetScaleLockingTextures(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptions::SetScaleLockingTextures(COptions *this, int b)
{
  int result; // eax

  result = this->general.bScaleLockingTextures;
  this->general.bScaleLockingTextures = b;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008A5F0
// Name: public: enum TextureAlignment_t COptions::SetTextureAlignment(enum TextureAlignment_t)
// Source: json
//------------------------------------------------------------------------------
TextureAlignment_t __thiscall COptions::SetTextureAlignment(COptions *this, TextureAlignment_t eTextureAlignment)
{
  TextureAlignment_t result; // eax

  result = this->general.eTextureAlignment;
  this->general.eTextureAlignment = eTextureAlignment;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008A600
// Name: public: bool COptions::GetShowHelpers(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall COptions::GetShowHelpers(COptions *this)
{
  return this->general.bShowHelpers == 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008A610
// Name: public: void COptions::SetShowHelpers(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptions::SetShowHelpers(COptions *this, bool bShow)
{
  this->general.bShowHelpers = bShow;
}

//------------------------------------------------------------------------------
// Address: 0x1008A630
// Name: public: class CGameConfig __near * COptionsConfigs::AddConfig(void)
// Source: json
//------------------------------------------------------------------------------
CGameConfig *__thiscall COptionsConfigs::AddConfig(COptionsConfigs *this)
{
  CGameConfig *v2; // eax
  CGameConfig *v3; // esi
  int nConfigs; // eax

  v2 = (CGameConfig *)operator new(nSize: 0xAD4u);
  v3 = nullptr;
  if ( v2 != nullptr )
    v3 = CGameConfig::CGameConfig(this: v2);
  nConfigs = this->nConfigs;
  this->nConfigs = nConfigs + 1;
  CUIntArray::SetAtGrow(this: &this->Configs, nIndex: nConfigs, newElement: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008A6A0
// Name: public: class CGameConfig __near * COptionsConfigs::FindConfig(unsigned long,int __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1008A700
// Name: public: class CGameConfig __near * COptionsConfigs::FindConfigForGame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1008A760
// Name: private: int COptionsConfigs::LoadGameConfigsBlock(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsConfigs::LoadGameConfigsBlock(COptionsConfigs *this, KeyValues *pBlock)
{
  KeyValues *i; // ebx
  CGameConfig *v6; // eax
  CGameConfig *v7; // esi
  int nConfigs; // eax
  int nConfigsRead; // [esp+1Ch] [ebp+8h]

  if ( pBlock == nullptr )
    return 0;
  nConfigsRead = 0;
  for ( i = KeyValues::GetFirstTrueSubKey(this: pBlock); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
  {
    v6 = (CGameConfig *)operator new(nSize: 0xAD4u);
    v7 = nullptr;
    if ( v6 != nullptr )
      v7 = CGameConfig::CGameConfig(this: v6);
    nConfigs = this->nConfigs;
    this->nConfigs = nConfigs + 1;
    CUIntArray::SetAtGrow(this: &this->Configs, nIndex: nConfigs, newElement: v7);
    if ( v7 != nullptr && CGameConfig::Load(this: v7, pkv: i) != 0 )
      ++nConfigsRead;
  }
  return nConfigsRead;
}

//------------------------------------------------------------------------------
// Address: 0x1008A830
// Name: public: void COptionsConfigs::SaveGameConfigs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsConfigs::SaveGameConfigs(COptionsConfigs *this)
{
  int v2; // edi
  KeyValues *GameBlock; // eax
  bool v4; // cc
  KeyValues *v5; // ebx
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // ebx
  int v8; // edi
  const char *Name; // eax
  KeyValues *NextTrueSubKey; // edi
  const char *v11; // [esp-8h] [ebp-130h]
  CGameConfigManager mgr; // [esp+8h] [ebp-120h] BYREF
  KeyValues *pGame; // [esp+118h] [ebp-10h]
  int v14; // [esp+124h] [ebp-4h]

  v2 = 0;
  if ( this->nConfigs != 0 )
  {
    CGameConfigManager::CGameConfigManager(this: &mgr);
    v14 = 0;
    if ( CGameConfigManager::LoadConfigs(this: &mgr, baseDir: this->m_strConfigDir.m_pszData) != 0 )
    {
      GameBlock = CGameConfigManager::GetGameBlock(this: &mgr);
      v4 = this->nConfigs <= 0;
      v5 = GameBlock;
      pGame = GameBlock;
      if ( v4 )
      {
LABEL_11:
        FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v5);
        while ( FirstTrueSubKey != nullptr )
        {
          v8 = 0;
          if ( this->nConfigs <= 0 )
          {
LABEL_17:
            NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
            KeyValues::RemoveSubKey(this: pGame, subKey: FirstTrueSubKey);
            KeyValues::deleteThis(this: FirstTrueSubKey);
            FirstTrueSubKey = NextTrueSubKey;
          }
          else
          {
            while ( 1 )
            {
              if ( v8 < 0 || v8 >= this->Configs.m_nSize )
                goto LABEL_22;
              v11 = (char *)this->Configs.m_pData[v8] + 24;
              Name = KeyValues::GetName(this: FirstTrueSubKey);
              if ( _V_stricmp(s1: Name, s2: v11) == 0 )
                break;
              if ( ++v8 >= this->nConfigs )
                goto LABEL_17;
            }
            FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          }
        }
        CGameConfigManager::SaveConfigs(this: &mgr, baseDir: this->m_strConfigDir.m_pszData);
      }
      else
      {
        while ( 1 )
        {
          if ( v2 < 0 || v2 >= this->Configs.m_nSize )
LABEL_22:
            AfxThrowInvalidArgException();
          Key = KeyValues::FindKey(this: v5, keyName: (const char *)this->Configs.m_pData[v2] + 24, bCreate: false);
          if ( Key == nullptr )
          {
            Key = KeyValues::CreateNewKey(this: v5);
            if ( Key == nullptr )
              break;
          }
          if ( v2 >= this->Configs.m_nSize )
            goto LABEL_22;
          CGameConfig::Save(this: (CGameConfig *)this->Configs.m_pData[v2++], pkv: Key);
          if ( v2 >= this->nConfigs )
            goto LABEL_11;
        }
      }
      v14 = -1;
      CGameConfigManager::~CGameConfigManager(this: &mgr);
    }
    else
    {
      v14 = -1;
      CGameConfigManager::~CGameConfigManager(this: &mgr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A9B0
// Name: private: void COptions::ReadColorSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptions::ReadColorSettings(COptions *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  bool v3; // al
  AFX_MODULE_STATE *v4; // eax
  AFX_MODULE_STATE *v5; // eax
  AFX_MODULE_STATE *v6; // eax
  AFX_MODULE_STATE *v7; // eax
  AFX_MODULE_STATE *v8; // eax
  AFX_MODULE_STATE *v9; // eax
  AFX_MODULE_STATE *v10; // eax
  AFX_MODULE_STATE *v11; // eax
  AFX_MODULE_STATE *v12; // eax
  AFX_MODULE_STATE *v13; // eax
  AFX_MODULE_STATE *v14; // eax
  AFX_MODULE_STATE *v15; // eax
  AFX_MODULE_STATE *v16; // eax
  AFX_MODULE_STATE *v17; // eax
  AFX_MODULE_STATE *v18; // eax
  AFX_MODULE_STATE *v19; // eax
  AFX_MODULE_STATE *v20; // eax
  AFX_MODULE_STATE *v21; // eax
  AFX_MODULE_STATE *v22; // eax
  AFX_MODULE_STATE *v23; // eax
  AFX_MODULE_STATE *v24; // eax
  bool v25; // zf
  unsigned int v26; // eax

  ModuleState = AfxGetModuleState();
  v3 = ModuleState->m_pCurrentWinApp->GetProfileIntA(
         this: ModuleState->m_pCurrentWinApp,
         a2: g_szColors,
         a3: "UseCustom",
         a4: 0) != 0;
  this->colors.bUseCustom = v3;
  if ( v3 )
  {
    v4 = AfxGetModuleState();
    this->colors.clrAxis = CHammer::GetProfileColor(
                             this: (CHammer *)v4->m_pCurrentWinApp,
                             pszSection: g_szColors,
                             pszKey: "Grid0",
                             r: 0,
                             g: 100,
                             b: 100);
    v5 = AfxGetModuleState();
    this->colors.bScaleAxisColor = v5->m_pCurrentWinApp->GetProfileIntA(
                                     this: v5->m_pCurrentWinApp,
                                     a2: g_szColors,
                                     a3: "ScaleGrid0",
                                     a4: 0) != 0;
    v6 = AfxGetModuleState();
    this->colors.clrGrid = CHammer::GetProfileColor(
                             this: (CHammer *)v6->m_pCurrentWinApp,
                             pszSection: g_szColors,
                             pszKey: "Grid",
                             r: 50,
                             g: 50,
                             b: 50);
    v7 = AfxGetModuleState();
    this->colors.bScaleGridColor = v7->m_pCurrentWinApp->GetProfileIntA(
                                     this: v7->m_pCurrentWinApp,
                                     a2: g_szColors,
                                     a3: "ScaleGrid",
                                     a4: 1) != 0;
    v8 = AfxGetModuleState();
    this->colors.clrGrid10 = CHammer::GetProfileColor(
                               this: (CHammer *)v8->m_pCurrentWinApp,
                               pszSection: g_szColors,
                               pszKey: "Grid10",
                               r: 40,
                               g: 40,
                               b: 40);
    v9 = AfxGetModuleState();
    this->colors.bScaleGrid10Color = v9->m_pCurrentWinApp->GetProfileIntA(
                                       this: v9->m_pCurrentWinApp,
                                       a2: g_szColors,
                                       a3: "ScaleGrid10",
                                       a4: 1) != 0;
    v10 = AfxGetModuleState();
    this->colors.clrGrid1024 = CHammer::GetProfileColor(
                                 this: (CHammer *)v10->m_pCurrentWinApp,
                                 pszSection: g_szColors,
                                 pszKey: "Grid1024",
                                 r: 40,
                                 g: 40,
                                 b: 40);
    v11 = AfxGetModuleState();
    this->colors.bScaleGrid1024Color = v11->m_pCurrentWinApp->GetProfileIntA(
                                         this: v11->m_pCurrentWinApp,
                                         a2: g_szColors,
                                         a3: "ScaleGrid1024",
                                         a4: 1) != 0;
    v12 = AfxGetModuleState();
    this->colors.clrGridDot = CHammer::GetProfileColor(
                                this: (CHammer *)v12->m_pCurrentWinApp,
                                pszSection: g_szColors,
                                pszKey: "GridDot",
                                r: 128,
                                g: 128,
                                b: 128);
    v13 = AfxGetModuleState();
    this->colors.bScaleGridDotColor = v13->m_pCurrentWinApp->GetProfileIntA(
                                        this: v13->m_pCurrentWinApp,
                                        a2: g_szColors,
                                        a3: "ScaleGridDot",
                                        a4: 1) != 0;
    v14 = AfxGetModuleState();
    this->colors.clrBrush = CHammer::GetProfileColor(
                              this: (CHammer *)v14->m_pCurrentWinApp,
                              pszSection: g_szColors,
                              pszKey: "LineColor",
                              r: 0,
                              g: 0,
                              b: 0);
    v15 = AfxGetModuleState();
    this->colors.clrEntity = CHammer::GetProfileColor(
                               this: (CHammer *)v15->m_pCurrentWinApp,
                               pszSection: g_szColors,
                               pszKey: "Entity",
                               r: 220,
                               g: 30,
                               b: 220);
    v16 = AfxGetModuleState();
    this->colors.clrVertex = CHammer::GetProfileColor(
                               this: (CHammer *)v16->m_pCurrentWinApp,
                               pszSection: g_szColors,
                               pszKey: "Vertex",
                               r: 0,
                               g: 0,
                               b: 0);
    v17 = AfxGetModuleState();
    this->colors.clrBackground = CHammer::GetProfileColor(
                                   this: (CHammer *)v17->m_pCurrentWinApp,
                                   pszSection: g_szColors,
                                   pszKey: "Background",
                                   r: 0,
                                   g: 0,
                                   b: 0);
    v18 = AfxGetModuleState();
    this->colors.clrToolHandle = CHammer::GetProfileColor(
                                   this: (CHammer *)v18->m_pCurrentWinApp,
                                   pszSection: g_szColors,
                                   pszKey: "HandleColor",
                                   r: 0,
                                   g: 0,
                                   b: 0);
    v19 = AfxGetModuleState();
    this->colors.clrToolBlock = CHammer::GetProfileColor(
                                  this: (CHammer *)v19->m_pCurrentWinApp,
                                  pszSection: g_szColors,
                                  pszKey: "BoxColor",
                                  r: 0,
                                  g: 0,
                                  b: 0);
    v20 = AfxGetModuleState();
    this->colors.clrToolSelection = CHammer::GetProfileColor(
                                      this: (CHammer *)v20->m_pCurrentWinApp,
                                      pszSection: g_szColors,
                                      pszKey: "ToolSelect",
                                      r: 0,
                                      g: 0,
                                      b: 0);
    v21 = AfxGetModuleState();
    this->colors.clrToolMorph = CHammer::GetProfileColor(
                                  this: (CHammer *)v21->m_pCurrentWinApp,
                                  pszSection: g_szColors,
                                  pszKey: "Morph",
                                  r: 255,
                                  g: 0,
                                  b: 0);
    v22 = AfxGetModuleState();
    this->colors.clrToolPath = CHammer::GetProfileColor(
                                 this: (CHammer *)v22->m_pCurrentWinApp,
                                 pszSection: g_szColors,
                                 pszKey: "Path",
                                 r: 255,
                                 g: 0,
                                 b: 0);
    v23 = AfxGetModuleState();
    this->colors.clrSelection = CHammer::GetProfileColor(
                                  this: (CHammer *)v23->m_pCurrentWinApp,
                                  pszSection: g_szColors,
                                  pszKey: "Selection",
                                  r: 220,
                                  g: 0,
                                  b: 0);
    v24 = AfxGetModuleState();
    this->colors.clrToolDrag = CHammer::GetProfileColor(
                                 this: (CHammer *)v24->m_pCurrentWinApp,
                                 pszSection: g_szColors,
                                 pszKey: "ToolDrag",
                                 r: 255,
                                 g: 255,
                                 b: 0);
  }
  else
  {
    v25 = Options.view2d.bWhiteOnBlack == 0;
    this->colors.clrAxis = 6579200;
    if ( v25 )
    {
      this->colors.clrBackground = 0xFFFFFF;
      this->colors.clrGrid = 3289650;
      v26 = 2631720;
      this->colors.clrGrid1024 = 681160;
      this->colors.clrBrush = 0;
      this->colors.clrVertex = 0;
      this->colors.clrToolHandle = 0;
      this->colors.clrToolBlock = 0;
      this->colors.clrToolDrag = 16711680;
    }
    else
    {
      v26 = 0xFFFFFF;
      this->colors.clrBackground = 0;
      this->colors.clrGrid = 0xFFFFFF;
      this->colors.clrGrid1024 = 340580;
      this->colors.clrBrush = 0xFFFFFF;
      this->colors.clrVertex = 0xFFFFFF;
      this->colors.clrToolHandle = 0xFFFFFF;
      this->colors.clrToolBlock = 0xFFFFFF;
      this->colors.clrToolDrag = 0xFFFF;
    }
    this->colors.clrGrid10 = v26;
    this->colors.clrGridDot = v26;
    *(_WORD *)&this->colors.bScaleAxisColor = 256;
    *(_WORD *)&this->colors.bScaleGrid10Color = 1;
    this->colors.bScaleGridDotColor = true;
    this->colors.clrToolSelection = 0xFFFF;
    this->colors.clrSelection = 255;
    this->colors.clrToolMorph = 255;
    this->colors.clrToolPath = 255;
    this->colors.clrEntity = 14425820;
    this->colors.clrModelCollisionWireframe = 0xFFFF;
    this->colors.clrModelCollisionWireframeDisabled = 14425820;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AE20
// Name: public: void COptions::SetClosedCorrectly(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptions::SetClosedCorrectly(COptions *this, int bClosed)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  ModuleState->m_pCurrentWinApp->WriteProfileInt(
    this: ModuleState->m_pCurrentWinApp,
    a2: pszGeneral,
    a3: "Closed Correctly",
    a4: bClosed);
}

//------------------------------------------------------------------------------
// Address: 0x1008AE50
// Name: public: void COptions::PerformChanges(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptions::PerformChanges(COptions *this, char dwOptionsChanged)
{
  CMainFrame *MainWnd; // eax
  CMainFrame *v4; // esi

  MainWnd = GetMainWnd();
  v4 = MainWnd;
  if ( (dwOptionsChanged & 1) != 0 && MainWnd != nullptr )
    CMainFrame::SetBrightness(this: MainWnd, fBrightness: this->textures.fBrightness);
  if ( (dwOptionsChanged & 4) != 0 )
  {
    COptions::ReadColorSettings(this);
    if ( v4 != nullptr )
      CMainFrame::UpdateAllDocViews(this: v4, dwCmd: 0x920u);
  }
  if ( (dwOptionsChanged & 8) != 0 && v4 != nullptr )
    CMainFrame::UpdateAllDocViews(this: v4, dwCmd: 0x940u);
  if ( (dwOptionsChanged & 0x10) != 0 && v4 != nullptr )
    CMainFrame::GlobalNotify(this: v4, a2: (int)this, nCode: 1028);
}

//------------------------------------------------------------------------------
// Address: 0x1008AED0
// Name: public: COptionsConfigs::COptionsConfigs(void)
// Source: json
//------------------------------------------------------------------------------
COptionsConfigs *__thiscall COptionsConfigs::COptionsConfigs(COptionsConfigs *this)
{
  CTypedPtrArray<CPtrArray,CGameConfig *> *p_Configs; // edi
  CAfxStringMgr *StringManager; // eax

  p_Configs = &this->Configs;
  this->__vftable = (COptionsConfigs_vtbl *)&COptionsConfigs::`vftable';
  CPtrArray::CPtrArray(this: &this->Configs);
  p_Configs->__vftable = (CTypedPtrArray<CPtrArray,CGameConfig *>_vtbl *)&CTypedPtrArray<CPtrArray,CGameConfig *>::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strConfigDir.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  this->nConfigs = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008AF70
// Name: public: void COptions::Write(int,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1008B8E0
// Name: public: void COptions::SetDefaults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptions::SetDefaults(COptions *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v3; // eax
  int v4; // eax
  CWinApp *m_pCurrentWinApp; // [esp+14h] [ebp-8h]
  BOOL bWrite; // [esp+18h] [ebp-4h]

  ModuleState = AfxGetModuleState();
  bWrite = ModuleState->m_pCurrentWinApp->GetProfileIntA(
             this: ModuleState->m_pCurrentWinApp,
             a2: "Configured",
             a3: "Configured",
             a4: 0) != 2;
  v3 = AfxGetModuleState();
  if ( v3->m_pCurrentWinApp->GetProfileIntA(this: v3->m_pCurrentWinApp, a2: "Configured", a3: "Installed", a4: 42151) == 42151 )
  {
    m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
    v4 = _time64(timeptr: nullptr);
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: "Configured", a3: "Installed", a4: v4);
  }
  this->uDaysSinceInstalled = 0;
  this->textures.nTextureFiles = 1;
  CStringArray::SetAtGrow(
    this: &this->textures.TextureFiles,
    nIndex: this->textures.TextureFiles.m_nSize,
    newElement: "textures.wad");
  this->textures.fBrightness = 1.0;
  this->general.bIndependentwin = 0;
  this->general.bEnablePerforceIntegration = 1;
  this->general.bLoadwinpos = 1;
  this->general.iUndoLevels = 50;
  this->general.nMaxCameras = 100;
  this->general.bGroupWhileIgnore = 0;
  this->general.bStretchArches = 1;
  this->general.bLockingTextures = 1;
  this->general.bScaleLockingTextures = 0;
  this->general.bShowHelpers = 1;
  this->general.iTimeBetweenSaves = 15;
  this->general.iMaxAutosaveSpace = 100;
  this->general.iMaxAutosavesPerMap = 5;
  this->general.bEnableAutosave = 1;
  this->general.bClosedCorrectly = 1;
  this->general.bShowCollisionModels = 0;
  this->general.bShowDetailObjects = 1;
  this->general.bShowNoDrawBrushes = 1;
  this->view2d.bCrosshairs = 0;
  this->view2d.bGroupCarve = 1;
  this->view2d.bScrollbars = 1;
  this->view2d.bRotateConstrain = 0;
  this->view2d.bDrawVertices = 1;
  this->view2d.bDrawModels = 1;
  this->view2d.iDefaultGrid = 64;
  this->view2d.bWhiteOnBlack = 1;
  this->view2d.bGridHigh1024 = 1;
  this->view2d.bGridHigh10 = 1;
  this->view2d.iGridIntensity = 30;
  this->view2d.bHideSmallGrid = 1;
  this->view2d.bNudge = 0;
  this->view2d.bOrientPrimitives = 0;
  this->view2d.bAutoSelect = 0;
  this->view2d.bSelectbyhandles = 0;
  this->view2d.iGridHighSpec = 8;
  this->view2d.bKeepclonegroup = 1;
  this->view2d.bGridHigh64 = 0;
  this->view2d.bGridDots = 0;
  this->view2d.bCenteroncamera = 0;
  this->view2d.bUsegroupcolors = 1;
  this->view3d.bUseMouseLook = 1;
  this->view3d.bHardware = 0;
  this->view3d.bReverseY = 0;
  this->view3d.iBackPlane = 5000;
  this->view3d.nModelDistance = 400;
  this->view3d.nDetailDistance = 1200;
  this->view3d.bAnimateModels = 0;
  this->view3d.nForwardSpeedMax = 1000;
  this->view3d.nTimeToMaxSpeed = 500;
  this->view3d.bFilterTextures = 1;
  this->view3d.bReverseSelection = 0;
  this->view3d.bPreviewModelFade = false;
  if ( bWrite )
    COptions::Write(this, fOverwrite: 0, fSaveConfigs: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1008BAF0
// Name: public: bool COptions::RunConfigurationDialog(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COptions::RunConfigurationDialog(COptions *this)
{
  COptions *v1; // esi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // ebx
  HINSTANCE__ *StringResourceHandle; // eax
  CMainFrame *MainWnd; // eax
  HWND__ *m_hWnd; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  COptionProperties v9; // [esp+Ch] [ebp-1BF4h] BYREF
  COptions *v10; // [esp+1BECh] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v11; // [esp+1BF0h] [ebp-10h] BYREF
  int v12; // [esp+1BFCh] [ebp-4h]

  v1 = this;
  v10 = this;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v11.m_pszData = m_pszData;
  v12 = 1;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xA02Cu);
  if ( StringResourceHandle != nullptr )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &v11,
      hInstance: StringResourceHandle,
      nID: 0xA02Cu);
    m_pszData = v11.m_pszData;
  }
  if ( MessageBoxA(hWnd: nullptr, lpText: m_pszData, lpCaption: "First Time Setup", uType: 0x24u) == 6 )
  {
    MainWnd = GetMainWnd();
    if ( MainWnd != nullptr )
      m_hWnd = MainWnd->m_hWnd;
    else
      m_hWnd = nullptr;
    ModuleState = AfxGetModuleState();
    CHammer::OpenURL(this: (CHammer *)ModuleState->m_pCurrentWinApp, a2: (int)MessageBoxA, nID: 0x80ABu, hwnd: m_hWnd);
    v1 = v10;
  }
  COptionProperties::COptionProperties(this: &v9, pszCaption: "Configure Hammer", pParentWnd: nullptr, iSelectPage: 0);
  LOBYTE(v12) = 2;
  while ( CPropertySheet::DoModal(this: &v9) == 1 )
  {
    if ( v1->configs.nConfigs == 0 )
    {
      MessageBoxA(
        hWnd: nullptr,
        lpText: "You must create at least one game configuration before using Hammer.",
        lpCaption: "First Time Setup",
        uType: 0x30u);
      if ( v1->configs.nConfigs == 0 )
        continue;
    }
    COptions::Write(this: &Options, fOverwrite: 1, fSaveConfigs: 1);
    LOBYTE(v12) = 1;
    COptionProperties::~COptionProperties(this: &v9);
    v12 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
        a1: *((_DWORD *)m_pszData - 4),
        a2: m_pszData - 16);
    return 1;
  }
  LOBYTE(v12) = 1;
  COptionProperties::~COptionProperties(this: &v9);
  v12 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008BC90
// Name: public: virtual COptionsConfigs::~COptionsConfigs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsConfigs::~COptionsConfigs(COptionsConfigs *this)
{
  int i; // edi
  CGameConfig *v3; // ebx
  volatile signed __int32 *v4; // eax

  this->__vftable = (COptionsConfigs_vtbl *)&COptionsConfigs::`vftable';
  for ( i = 0; i < this->nConfigs; ++i )
  {
    if ( i < 0 || i >= this->Configs.m_nSize )
      AfxThrowInvalidArgException();
    v3 = (CGameConfig *)this->Configs.m_pData[i];
    if ( v3 != nullptr )
    {
      CGameConfig::~CGameConfig(this: v3);
      operator delete(p: v3);
    }
  }
  v4 = (volatile signed __int32 *)(this->m_strConfigDir.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  CPtrArray::~CPtrArray(this: &this->Configs);
}

//------------------------------------------------------------------------------
// Address: 0x1008BD50
// Name: public: COptions::COptions(void)
// Source: json
//------------------------------------------------------------------------------
COptions *__thiscall COptions::COptions(COptions *this)
{
  CStringArray::CStringArray(this: &this->textures.TextureFiles);
  COptionsConfigs::COptionsConfigs(this: &this->configs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008BDE0
// Name: private: int COptionsConfigs::ImportOldGameConfigs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsConfigs::ImportOldGameConfigs(COptionsConfigs *this, float pszFileName)
{
  AFX_MODULE_STATE *ModuleState; // eax
  unsigned int v4; // eax
  int v5; // ecx
  CGameConfig *v6; // eax
  CGameConfig *v7; // esi
  int v8; // ecx
  int v9; // eax
  std::ios_base *v10; // ecx
  char v11; // al
  int nConfigs; // [esp-Ch] [ebp-30Ch]
  char pOut[8]; // [esp+8h] [ebp-2F8h] BYREF
  char szFullPath[260]; // [esp+10h] [ebp-2F0h] BYREF
  char szRootDir[260]; // [esp+114h] [ebp-1ECh] BYREF
  char szSig[28]; // [esp+218h] [ebp-E8h] BYREF
  std::fstream file; // [esp+234h] [ebp-CCh] BYREF
  void *p; // [esp+2ECh] [ebp-14h]
  int nTotalConfigs; // [esp+2F0h] [ebp-10h]
  int v21; // [esp+2FCh] [ebp-4h]

  nTotalConfigs = 0;
  ModuleState = AfxGetModuleState();
  CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: &szFullPath[252]);
  V_MakeAbsolutePath(pOut, outLen: 260, pPath: (const char *)LODWORD(pszFileName), pStartingDir: &szFullPath[252]);
  std::fstream::fstream(this: (std::fstream *)&szSig[20], _Filename: pOut, _Mode: 33, _Prot: 64, a5: 1);
  v21 = 0;
  if ( *(_DWORD *)&file._Filebuffer[4] != 0 )
  {
    std::istream::read(this: (std::istream *)&szSig[20], _Str: &szRootDir[252], _Count: 28);
    v4 = 28;
    v5 = 0;
    while ( *(_DWORD *)&szRootDir[v5 + 252] == *(_DWORD *)&GAMECFG_SIG[v5] )
    {
      v4 -= 4;
      v5 += 4;
      if ( v4 < 4 )
      {
        std::istream::read(this: (std::istream *)&szSig[20], _Str: (char *)&pszFileName, _Count: 4);
        if ( pszFileName >= 1.0 && pszFileName <= 1.4 )
        {
          std::istream::read(this: (std::istream *)&szSig[20], _Str: &file.gap70[68], _Count: 4);
          for ( p = nullptr; (int)p < *(int *)&file.gap70[68]; p = (char *)p + 1 )
          {
            v6 = (CGameConfig *)operator new(nSize: 0xAD4u);
            *(_DWORD *)&file.gap70[64] = v6;
            LOBYTE(v21) = 1;
            if ( v6 != nullptr )
              v7 = CGameConfig::CGameConfig(this: v6);
            else
              v7 = nullptr;
            LOBYTE(v21) = 0;
            nConfigs = this->nConfigs;
            this->nConfigs = nConfigs + 1;
            CUIntArray::SetAtGrow(this: &this->Configs, nIndex: nConfigs, newElement: v7);
            CGameConfig::Import(this: v7, file: (std::fstream *)&szSig[20], fVersion: pszFileName);
            ++nTotalConfigs;
            if ( g_pMapDir == nullptr )
              g_pMapDir = v7->szMapDir;
          }
        }
        break;
      }
    }
    if ( std::filebuf::close(this: (std::filebuf *)file.gap10) == nullptr )
    {
      v8 = *(_DWORD *)(*(_DWORD *)&szSig[20] + 4);
      v9 = *(_DWORD *)&file.gap0[v8 + 4];
      v10 = (std::ios_base *)&szSig[v8 + 20];
      v11 = v9 | 2;
      if ( v10[1].__vftable == nullptr )
        v11 |= 4u;
      std::ios_base::clear(this: v10, _State: v11, _Reraise: false);
    }
  }
  v21 = -1;
  std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)&file._Filebuffer[8]);
  pszFileName = COERCE_FLOAT((std::fstream *)&file._Filebuffer[8]);
  v21 = -1;
  *(_DWORD *)&file._Filebuffer[8] = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)&file._Filebuffer[8]);
  return nTotalConfigs;
}

//------------------------------------------------------------------------------
// Address: 0x1008BFF0
// Name: public: int COptionsConfigs::LoadGameConfigs(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsConfigs::LoadGameConfigs(COptionsConfigs *this)
{
  int v2; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  char *m_pszData; // eax
  char *v5; // edx
  char v6; // cl
  KeyValues *GameBlock; // edi
  int GameConfigsBlock; // esi
  char szFullPath[260]; // [esp+8h] [ebp-428h] BYREF
  char szRootDir[260]; // [esp+10Ch] [ebp-324h] BYREF
  char szSaveName[260]; // [esp+210h] [ebp-220h] BYREF
  CGameConfigManager mgr; // [esp+314h] [ebp-11Ch] BYREF
  int v14; // [esp+42Ch] [ebp-4h]

  v2 = COptionsConfigs::ImportOldGameConfigs(this, pszFileName: COERCE_FLOAT("GameCfg.wc"));
  if ( v2 <= 0 )
  {
    CGameConfigManager::CGameConfigManager(this: &mgr);
    v14 = 0;
    if ( CGameConfigManager::LoadConfigs(this: &mgr, baseDir: this->m_strConfigDir.m_pszData) != 0
      && (GameBlock = CGameConfigManager::GetGameBlock(this: &mgr)) != nullptr )
    {
      GDSetMessageFunc(pFunc: (void (*)(int, const char *, ...))Msg);
      GameConfigsBlock = COptionsConfigs::LoadGameConfigsBlock(this, pBlock: GameBlock);
      v14 = -1;
      CGameConfigManager::~CGameConfigManager(this: &mgr);
      return GameConfigsBlock;
    }
    else
    {
      v14 = -1;
      CGameConfigManager::~CGameConfigManager(this: &mgr);
      return 0;
    }
  }
  else
  {
    ModuleState = AfxGetModuleState();
    CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: szRootDir);
    V_MakeAbsolutePath(pOut: szFullPath, outLen: 260, pPath: "GameCfg.wc", pStartingDir: szRootDir);
    remove(path: szFullPath);
    m_pszData = this->m_strConfigDir.m_pszData;
    v5 = (char *)(szSaveName - m_pszData);
    do
    {
      v6 = *m_pszData;
      m_pszData[(_DWORD)v5] = *m_pszData;
      ++m_pszData;
    }
    while ( v6 != 0 );
    V_AppendSlash(pStr: szSaveName, strSize: 260);
    V_strncat(pDest: szSaveName, pSrc: "GameCfg.ini", destBufferSize: 0x104u, max_chars_to_copy: -1);
    COptionsConfigs::SaveGameConfigs(this);
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C160
// Name: public: bool COptions::Read(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall COptions::Read@<al>(COptions *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  AFX_MODULE_STATE *ModuleState; // eax
  CWinApp *m_pCurrentWinApp; // edi
  __int64 v7; // rax
  int v8; // edi
  CAfxStringMgr *StringManager; // eax
  AFX_MODULE_STATE *v10; // eax
  int i; // edi
  AFX_MODULE_STATE *v12; // eax
  ATL::CStringData *v13; // eax
  unsigned int v14; // eax
  AFX_MODULE_STATE *v15; // eax
  AFX_MODULE_STATE *v16; // eax
  AFX_MODULE_STATE *v17; // eax
  AFX_MODULE_STATE *v18; // eax
  AFX_MODULE_STATE *v19; // eax
  AFX_MODULE_STATE *v20; // eax
  AFX_MODULE_STATE *v21; // eax
  AFX_MODULE_STATE *v22; // eax
  AFX_MODULE_STATE *v23; // eax
  AFX_MODULE_STATE *v24; // eax
  AFX_MODULE_STATE *v25; // eax
  AFX_MODULE_STATE *v26; // eax
  AFX_MODULE_STATE *v27; // eax
  AFX_MODULE_STATE *v28; // eax
  AFX_MODULE_STATE *v29; // eax
  AFX_MODULE_STATE *v30; // eax
  AFX_MODULE_STATE *v31; // eax
  AFX_MODULE_STATE *v32; // eax
  AFX_MODULE_STATE *v33; // eax
  AFX_MODULE_STATE *v34; // eax
  AFX_MODULE_STATE *v35; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v36; // eax
  char *m_pszData; // eax
  char *v38; // ecx
  char v39; // dl
  unsigned int v40; // eax
  char *v41; // eax
  char v42; // cl
  AFX_MODULE_STATE *v43; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v44; // eax
  char *v45; // ecx
  char *szAutosaveDir; // edx
  char v47; // al
  unsigned int v48; // eax
  AFX_MODULE_STATE *v49; // eax
  AFX_MODULE_STATE *v50; // eax
  AFX_MODULE_STATE *v51; // eax
  AFX_MODULE_STATE *v52; // eax
  AFX_MODULE_STATE *v53; // eax
  AFX_MODULE_STATE *v54; // eax
  AFX_MODULE_STATE *v55; // eax
  AFX_MODULE_STATE *v56; // eax
  AFX_MODULE_STATE *v57; // eax
  AFX_MODULE_STATE *v58; // eax
  AFX_MODULE_STATE *v59; // eax
  AFX_MODULE_STATE *v60; // eax
  AFX_MODULE_STATE *v61; // eax
  AFX_MODULE_STATE *v62; // eax
  AFX_MODULE_STATE *v63; // eax
  AFX_MODULE_STATE *v64; // eax
  AFX_MODULE_STATE *v65; // eax
  AFX_MODULE_STATE *v66; // eax
  AFX_MODULE_STATE *v67; // eax
  AFX_MODULE_STATE *v68; // eax
  AFX_MODULE_STATE *v69; // eax
  AFX_MODULE_STATE *v70; // eax
  AFX_MODULE_STATE *v71; // eax
  AFX_MODULE_STATE *v72; // eax
  AFX_MODULE_STATE *v73; // eax
  AFX_MODULE_STATE *v74; // eax
  AFX_MODULE_STATE *v75; // eax
  AFX_MODULE_STATE *v76; // eax
  AFX_MODULE_STATE *v77; // eax
  AFX_MODULE_STATE *v78; // eax
  AFX_MODULE_STATE *v79; // eax
  AFX_MODULE_STATE *v80; // eax
  AFX_MODULE_STATE *v81; // eax
  AFX_MODULE_STATE *v82; // eax
  char *v83; // eax
  char *v84; // eax
  char v86; // [esp+3h] [ebp-121h] BYREF
  char szDefaultAutosavePath[260]; // [esp+4h] [ebp-120h] BYREF
  int iSize; // [esp+108h] [ebp-1Ch]
  unsigned int v89; // [esp+110h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+114h] [ebp-10h] BYREF
  int v91; // [esp+120h] [ebp-4h]

  ModuleState = AfxGetModuleState();
  if ( ModuleState->m_pCurrentWinApp->GetProfileIntA(
         this: ModuleState->m_pCurrentWinApp,
         a2: "Configured",
         a3: "Configured",
         a4: 0) == 0 )
    return 0;
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  v7 = _time64(timeptr: nullptr);
  v89 = HIDWORD(v7);
  v8 = ((int (__thiscall *)(CWinApp *, const char *, const char *, _DWORD, int, int))m_pCurrentWinApp->GetProfileIntA)(
         a1: m_pCurrentWinApp,
         a2: "Configured",
         a3: "Installed",
         a4: v7,
         a5: a3,
         a6: a2);
  this->uDaysSinceInstalled = (_time64(timeptr: nullptr) - (unsigned int)v8) / 86400;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v91 = 1;
  v10 = AfxGetModuleState();
  iSize = v10->m_pCurrentWinApp->GetProfileIntA(
            this: v10->m_pCurrentWinApp,
            a2: pszGeneral,
            a3: "TextureFileCount",
            a4: 0);
  if ( iSize != 0 )
  {
    this->textures.nTextureFiles = 0;
    CStringArray::SetSize(this: &this->textures.TextureFiles, nNewSize: 0, nGrowBy: -1);
    for ( i = 0; i < iSize; ++i )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &str, pszFormat: "TextureFile%d", i);
      v12 = AfxGetModuleState();
      v13 = (ATL::CStringData *)v12->m_pCurrentWinApp->GetProfileStringA(
                                  this: v12->m_pCurrentWinApp,
                                  result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v89,
                                  a3: pszGeneral,
                                  a4: str.m_pszData,
                                  a5: nullptr);
      LOBYTE(v91) = 2;
      ATL::CSimpleStringT<char,0>::operator=(this: &str, strSrc: v13);
      LOBYTE(v91) = 1;
      v14 = v89 - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v89 - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(unsigned int))(**(_DWORD **)v14 + 4))(a1: v14);
      if ( GetFileAttributesA(lpFileName: str.m_pszData) != -1 )
      {
        CStringArray::SetAtGrow(
          this: &this->textures.TextureFiles,
          nIndex: this->textures.TextureFiles.m_nSize,
          newElement: (ATL::CStringData *)&str);
        ++this->textures.nTextureFiles;
      }
    }
  }
  v15 = AfxGetModuleState();
  v89 = v15->m_pCurrentWinApp->GetProfileIntA(this: v15->m_pCurrentWinApp, a2: pszGeneral, a3: "Brightness", a4: 10);
  this->textures.fBrightness = (double)v89 * 0.1;
  v16 = AfxGetModuleState();
  this->general.nMaxCameras = v16->m_pCurrentWinApp->GetProfileIntA(
                                this: v16->m_pCurrentWinApp,
                                a2: pszGeneral,
                                a3: "Max Cameras",
                                a4: 100);
  v17 = AfxGetModuleState();
  this->general.iUndoLevels = v17->m_pCurrentWinApp->GetProfileIntA(
                                this: v17->m_pCurrentWinApp,
                                a2: pszGeneral,
                                a3: "Undo Levels",
                                a4: 50);
  v18 = AfxGetModuleState();
  this->general.bLockingTextures = v18->m_pCurrentWinApp->GetProfileIntA(
                                     this: v18->m_pCurrentWinApp,
                                     a2: pszGeneral,
                                     a3: "Locking Textures",
                                     a4: 1);
  v19 = AfxGetModuleState();
  this->general.bScaleLockingTextures = v19->m_pCurrentWinApp->GetProfileIntA(
                                          this: v19->m_pCurrentWinApp,
                                          a2: pszGeneral,
                                          a3: "Scale Locking Textures",
                                          a4: 0);
  v20 = AfxGetModuleState();
  this->general.eTextureAlignment = v20->m_pCurrentWinApp->GetProfileIntA(
                                      this: v20->m_pCurrentWinApp,
                                      a2: pszGeneral,
                                      a3: "Texture Alignment",
                                      a4: 1);
  v21 = AfxGetModuleState();
  this->general.bLoadwinpos = v21->m_pCurrentWinApp->GetProfileIntA(
                                this: v21->m_pCurrentWinApp,
                                a2: pszGeneral,
                                a3: "Load Default Positions",
                                a4: 1);
  v22 = AfxGetModuleState();
  this->general.bIndependentwin = v22->m_pCurrentWinApp->GetProfileIntA(
                                    this: v22->m_pCurrentWinApp,
                                    a2: pszGeneral,
                                    a3: "Independent Windows",
                                    a4: 0);
  v23 = AfxGetModuleState();
  this->general.bEnablePerforceIntegration = v23->m_pCurrentWinApp->GetProfileIntA(
                                               this: v23->m_pCurrentWinApp,
                                               a2: pszGeneral,
                                               a3: "Perforce Integration",
                                               a4: 1);
  v24 = AfxGetModuleState();
  this->general.bGroupWhileIgnore = v24->m_pCurrentWinApp->GetProfileIntA(
                                      this: v24->m_pCurrentWinApp,
                                      a2: pszGeneral,
                                      a3: "GroupWhileIgnore",
                                      a4: 0);
  v25 = AfxGetModuleState();
  this->general.bStretchArches = v25->m_pCurrentWinApp->GetProfileIntA(
                                   this: v25->m_pCurrentWinApp,
                                   a2: pszGeneral,
                                   a3: "StretchArches",
                                   a4: 1);
  v26 = AfxGetModuleState();
  this->general.bShowHelpers = v26->m_pCurrentWinApp->GetProfileIntA(
                                 this: v26->m_pCurrentWinApp,
                                 a2: pszGeneral,
                                 a3: "Show Helpers",
                                 a4: 1);
  v27 = AfxGetModuleState();
  this->general.bCheckVisibleMapErrors = v27->m_pCurrentWinApp->GetProfileIntA(
                                           this: v27->m_pCurrentWinApp,
                                           a2: pszGeneral,
                                           a3: "Visible Map Errors",
                                           a4: 0);
  v28 = AfxGetModuleState();
  this->general.iTimeBetweenSaves = v28->m_pCurrentWinApp->GetProfileIntA(
                                      this: v28->m_pCurrentWinApp,
                                      a2: pszGeneral,
                                      a3: "Time Between Saves",
                                      a4: 15);
  v29 = AfxGetModuleState();
  this->general.iMaxAutosaveSpace = v29->m_pCurrentWinApp->GetProfileIntA(
                                      this: v29->m_pCurrentWinApp,
                                      a2: pszGeneral,
                                      a3: "Max Autosave Space",
                                      a4: 100);
  v30 = AfxGetModuleState();
  this->general.iMaxAutosavesPerMap = v30->m_pCurrentWinApp->GetProfileIntA(
                                        this: v30->m_pCurrentWinApp,
                                        a2: pszGeneral,
                                        a3: "Max Saves Per Map",
                                        a4: 5);
  v31 = AfxGetModuleState();
  this->general.bEnableAutosave = v31->m_pCurrentWinApp->GetProfileIntA(
                                    this: v31->m_pCurrentWinApp,
                                    a2: pszGeneral,
                                    a3: "Autosaves Enabled",
                                    a4: 1);
  v32 = AfxGetModuleState();
  this->general.bClosedCorrectly = v32->m_pCurrentWinApp->GetProfileIntA(
                                     this: v32->m_pCurrentWinApp,
                                     a2: pszGeneral,
                                     a3: "Closed Correctly",
                                     a4: 1);
  v33 = AfxGetModuleState();
  this->general.bShowHiddenTargetsAsBroken = v33->m_pCurrentWinApp->GetProfileIntA(
                                               this: v33->m_pCurrentWinApp,
                                               a2: pszGeneral,
                                               a3: "Show Hidden Targets As Broken",
                                               a4: 1);
  v34 = AfxGetModuleState();
  this->general.bRadiusCulling = v34->m_pCurrentWinApp->GetProfileIntA(
                                   this: v34->m_pCurrentWinApp,
                                   a2: pszGeneral,
                                   a3: "Use Radius Culling",
                                   a4: 0);
  v35 = AfxGetModuleState();
  v36 = v35->m_pCurrentWinApp->GetProfileStringA(
          this: v35->m_pCurrentWinApp,
          result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v89,
          a3: pszGeneral,
          a4: "Directory",
          a5: "C:");
  LOBYTE(v91) = 4;
  m_pszData = v36->m_pszData;
  v38 = szDefaultAutosavePath;
  do
  {
    v39 = *m_pszData;
    *v38++ = *m_pszData++;
  }
  while ( v39 != 0 );
  LOBYTE(v91) = 1;
  v40 = v89 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v89 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(unsigned int))(**(_DWORD **)v40 + 4))(a1: v40);
  v41 = &v86;
  do
    v42 = *++v41;
  while ( v42 != 0 );
  strcpy(v41, "\\HammerAutosave\\");
  v43 = AfxGetModuleState();
  v44 = v43->m_pCurrentWinApp->GetProfileStringA(
          this: v43->m_pCurrentWinApp,
          result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v89,
          a3: "General",
          a4: "Autosave Dir",
          a5: szDefaultAutosavePath);
  LOBYTE(v91) = 6;
  v45 = v44->m_pszData;
  szAutosaveDir = this->general.szAutosaveDir;
  do
  {
    v47 = *v45;
    *szAutosaveDir++ = *v45++;
  }
  while ( v47 != 0 );
  LOBYTE(v91) = 1;
  v48 = v89 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v89 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(unsigned int))(**(_DWORD **)v48 + 4))(a1: v48);
  if ( std::char_traits<char>::length(str: this->general.szAutosaveDir) == 0 )
    strcpy(this->general.szAutosaveDir, szDefaultAutosavePath);
  v49 = AfxGetModuleState();
  CHammer::SetDirectory(this: (CHammer *)v49->m_pCurrentWinApp, dir: DIR_AUTOSAVE, p: this->general.szAutosaveDir);
  v50 = AfxGetModuleState();
  this->view2d.bCrosshairs = ((int (__thiscall *)(CWinApp *, const char *))v50->m_pCurrentWinApp->GetProfileIntA)(
                               a1: v50->m_pCurrentWinApp,
                               a2: pszView2D);
  v51 = AfxGetModuleState();
  this->view2d.bGroupCarve = v51->m_pCurrentWinApp->GetProfileIntA(
                               this: v51->m_pCurrentWinApp,
                               a2: pszView2D,
                               a3: "GroupCarve",
                               a4: 1);
  v52 = AfxGetModuleState();
  this->view2d.bScrollbars = v52->m_pCurrentWinApp->GetProfileIntA(
                               this: v52->m_pCurrentWinApp,
                               a2: pszView2D,
                               a3: "Scrollbars",
                               a4: 1);
  v53 = AfxGetModuleState();
  this->view2d.bRotateConstrain = v53->m_pCurrentWinApp->GetProfileIntA(
                                    this: v53->m_pCurrentWinApp,
                                    a2: pszView2D,
                                    a3: "RotateConstrain",
                                    a4: 0);
  v54 = AfxGetModuleState();
  this->view2d.bDrawVertices = v54->m_pCurrentWinApp->GetProfileIntA(
                                 this: v54->m_pCurrentWinApp,
                                 a2: pszView2D,
                                 a3: "Draw Vertices",
                                 a4: 1);
  v55 = AfxGetModuleState();
  this->view2d.bDrawModels = v55->m_pCurrentWinApp->GetProfileIntA(
                               this: v55->m_pCurrentWinApp,
                               a2: pszView2D,
                               a3: "Draw Models",
                               a4: 1);
  v56 = AfxGetModuleState();
  this->view2d.bWhiteOnBlack = v56->m_pCurrentWinApp->GetProfileIntA(
                                 this: v56->m_pCurrentWinApp,
                                 a2: pszView2D,
                                 a3: "WhiteOnBlack",
                                 a4: 1);
  v57 = AfxGetModuleState();
  this->view2d.bGridHigh1024 = v57->m_pCurrentWinApp->GetProfileIntA(
                                 this: v57->m_pCurrentWinApp,
                                 a2: pszView2D,
                                 a3: "GridHigh1024",
                                 a4: 1);
  v58 = AfxGetModuleState();
  this->view2d.bGridHigh10 = v58->m_pCurrentWinApp->GetProfileIntA(
                               this: v58->m_pCurrentWinApp,
                               a2: pszView2D,
                               a3: "GridHigh10",
                               a4: 1);
  v59 = AfxGetModuleState();
  this->view2d.bHideSmallGrid = v59->m_pCurrentWinApp->GetProfileIntA(
                                  this: v59->m_pCurrentWinApp,
                                  a2: pszView2D,
                                  a3: "HideSmallGrid",
                                  a4: 1);
  v60 = AfxGetModuleState();
  this->view2d.bNudge = v60->m_pCurrentWinApp->GetProfileIntA(
                          this: v60->m_pCurrentWinApp,
                          a2: pszView2D,
                          a3: "Nudge",
                          a4: 0);
  v61 = AfxGetModuleState();
  this->view2d.bOrientPrimitives = v61->m_pCurrentWinApp->GetProfileIntA(
                                     this: v61->m_pCurrentWinApp,
                                     a2: pszView2D,
                                     a3: "OrientPrimitives",
                                     a4: 0);
  v62 = AfxGetModuleState();
  this->view2d.bAutoSelect = v62->m_pCurrentWinApp->GetProfileIntA(
                               this: v62->m_pCurrentWinApp,
                               a2: pszView2D,
                               a3: "AutoSelect",
                               a4: 0);
  v63 = AfxGetModuleState();
  this->view2d.bSelectbyhandles = v63->m_pCurrentWinApp->GetProfileIntA(
                                    this: v63->m_pCurrentWinApp,
                                    a2: pszView2D,
                                    a3: "SelectByHandles",
                                    a4: 0);
  v64 = AfxGetModuleState();
  this->view2d.iGridIntensity = v64->m_pCurrentWinApp->GetProfileIntA(
                                  this: v64->m_pCurrentWinApp,
                                  a2: pszView2D,
                                  a3: "GridIntensity",
                                  a4: 30);
  v65 = AfxGetModuleState();
  this->view2d.iDefaultGrid = v65->m_pCurrentWinApp->GetProfileIntA(
                                this: v65->m_pCurrentWinApp,
                                a2: pszView2D,
                                a3: "Default Grid",
                                a4: 64);
  v66 = AfxGetModuleState();
  this->view2d.iGridHighSpec = v66->m_pCurrentWinApp->GetProfileIntA(
                                 this: v66->m_pCurrentWinApp,
                                 a2: pszView2D,
                                 a3: "GridHighSpec",
                                 a4: 8);
  v67 = AfxGetModuleState();
  this->view2d.bKeepclonegroup = v67->m_pCurrentWinApp->GetProfileIntA(
                                   this: v67->m_pCurrentWinApp,
                                   a2: pszView2D,
                                   a3: "Keepclonegroup",
                                   a4: 1);
  v68 = AfxGetModuleState();
  this->view2d.bGridHigh64 = v68->m_pCurrentWinApp->GetProfileIntA(
                               this: v68->m_pCurrentWinApp,
                               a2: pszView2D,
                               a3: "Gridhigh64",
                               a4: 1);
  v69 = AfxGetModuleState();
  this->view2d.bGridDots = v69->m_pCurrentWinApp->GetProfileIntA(
                             this: v69->m_pCurrentWinApp,
                             a2: pszView2D,
                             a3: "GridDots",
                             a4: 0);
  v70 = AfxGetModuleState();
  this->view2d.bCenteroncamera = v70->m_pCurrentWinApp->GetProfileIntA(
                                   this: v70->m_pCurrentWinApp,
                                   a2: pszView2D,
                                   a3: "Centeroncamera",
                                   a4: 0);
  v71 = AfxGetModuleState();
  this->view2d.bUsegroupcolors = v71->m_pCurrentWinApp->GetProfileIntA(
                                   this: v71->m_pCurrentWinApp,
                                   a2: pszView2D,
                                   a3: "Usegroupcolors",
                                   a4: 1);
  v72 = AfxGetModuleState();
  this->view3d.bHardware = v72->m_pCurrentWinApp->GetProfileIntA(
                             this: v72->m_pCurrentWinApp,
                             a2: pszView3D,
                             a3: "Hardware",
                             a4: 0);
  v73 = AfxGetModuleState();
  this->view3d.bReverseY = v73->m_pCurrentWinApp->GetProfileIntA(
                             this: v73->m_pCurrentWinApp,
                             a2: pszView3D,
                             a3: "Reverse Y",
                             a4: 1);
  v74 = AfxGetModuleState();
  this->view3d.iBackPlane = v74->m_pCurrentWinApp->GetProfileIntA(
                              this: v74->m_pCurrentWinApp,
                              a2: pszView3D,
                              a3: "BackPlane",
                              a4: 5000);
  v75 = AfxGetModuleState();
  this->view3d.bUseMouseLook = v75->m_pCurrentWinApp->GetProfileIntA(
                                 this: v75->m_pCurrentWinApp,
                                 a2: pszView3D,
                                 a3: "UseMouseLook",
                                 a4: 1);
  v76 = AfxGetModuleState();
  this->view3d.nModelDistance = v76->m_pCurrentWinApp->GetProfileIntA(
                                  this: v76->m_pCurrentWinApp,
                                  a2: pszView3D,
                                  a3: "ModelDistance",
                                  a4: 400);
  v77 = AfxGetModuleState();
  this->view3d.nDetailDistance = v77->m_pCurrentWinApp->GetProfileIntA(
                                   this: v77->m_pCurrentWinApp,
                                   a2: pszView3D,
                                   a3: "DetailDistance",
                                   a4: 1200);
  v78 = AfxGetModuleState();
  this->view3d.bAnimateModels = v78->m_pCurrentWinApp->GetProfileIntA(
                                  this: v78->m_pCurrentWinApp,
                                  a2: pszView3D,
                                  a3: "AnimateModels",
                                  a4: 0);
  v79 = AfxGetModuleState();
  this->view3d.nForwardSpeedMax = v79->m_pCurrentWinApp->GetProfileIntA(
                                    this: v79->m_pCurrentWinApp,
                                    a2: pszView3D,
                                    a3: "ForwardSpeedMax",
                                    a4: 1000);
  v80 = AfxGetModuleState();
  this->view3d.nTimeToMaxSpeed = v80->m_pCurrentWinApp->GetProfileIntA(
                                   this: v80->m_pCurrentWinApp,
                                   a2: pszView3D,
                                   a3: "TimeToMaxSpeed",
                                   a4: 500);
  v81 = AfxGetModuleState();
  this->view3d.bFilterTextures = v81->m_pCurrentWinApp->GetProfileIntA(
                                   this: v81->m_pCurrentWinApp,
                                   a2: pszView3D,
                                   a3: "FilterTextures",
                                   a4: 1);
  v82 = AfxGetModuleState();
  this->view3d.bReverseSelection = v82->m_pCurrentWinApp->GetProfileIntA(
                                     this: v82->m_pCurrentWinApp,
                                     a2: pszView3D,
                                     a3: "ReverseSelection",
                                     a4: 0);
  this->view3d.fFOV = 90.0;
  COptions::ReadColorSettings(this);
  if ( COptionsConfigs::LoadGameConfigs(this: &this->configs) != 0 || COptions::RunConfigurationDialog(this) != 0 )
  {
    if ( this->configs.nConfigs > 0 )
    {
      if ( this->configs.Configs.m_nSize <= 0 )
        AfxThrowInvalidArgException();
      g_pGameConfig = (CGameConfig *)*this->configs.Configs.m_pData;
    }
    v91 = -1;
    v84 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v84 + 4))(a1: v84);
    return 1;
  }
  else
  {
    v91 = -1;
    v83 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v83 + 4))(a1: v83);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CCB0
// Name: public: bool COptionsConfigs::ResetGameConfigs(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COptionsConfigs::ResetGameConfigs(COptionsConfigs *this, bool bOverwrite)
{
  int GameConfigs; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  CGameConfigManager mgr; // [esp+Ch] [ebp-11Ch] BYREF
  int v8; // [esp+124h] [ebp-4h]

  CGameConfigManager::CGameConfigManager(this: &mgr);
  v8 = 0;
  CGameConfigManager::SetBaseDirectory(this: &mgr, pDirectory: this->m_strConfigDir.m_pszData);
  if ( bOverwrite )
  {
    CGameConfigManager::ResetConfigs(this: &mgr, baseDir: nullptr);
    GameConfigs = COptionsConfigs::LoadGameConfigs(this);
  }
  else
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    LOBYTE(v8) = 1;
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Defaults");
    else
      v5 = nullptr;
    LOBYTE(v8) = 0;
    if ( CGameConfigManager::GetDefaultGameBlock(this: &mgr, pIn: v5) == 0 )
    {
      v8 = -1;
      CGameConfigManager::~CGameConfigManager(this: &mgr);
      return false;
    }
    GameConfigs = COptionsConfigs::LoadGameConfigsBlock(this, pBlock: v5);
    KeyValues::deleteThis(this: v5);
  }
  v8 = -1;
  CGameConfigManager::~CGameConfigManager(this: &mgr);
  return GameConfigs > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008CDB0
// Name: public: bool COptions::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COptions::Init(COptions *this)
{
  char v2; // bl
  AFX_MODULE_STATE *v3; // eax
  char result; // al
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v6; // eax
  CMainFrame *MainWnd; // eax
  CMainFrame *v8; // esi
  char v9; // [esp+13h] [ebp-1h]

  v9 = 0;
  v2 = 0;
  if ( HammerSettingsFound() == 0 )
  {
    v2 = ValveHammerEditorSettingsFound();
    if ( v2 != 0 )
    {
      ModuleState = AfxGetModuleState();
      CHammer::BeginImportVHESettings(this: (CHammer *)ModuleState->m_pCurrentWinApp);
    }
    else
    {
      v9 = WorldcraftSettingsFound();
      if ( v9 != 0 )
      {
        v3 = AfxGetModuleState();
        CHammer::BeginImportWCSettings(this: (CHammer *)v3->m_pCurrentWinApp);
      }
    }
  }
  COptions::SetDefaults(this);
  result = COptions::Read(this, a2: v2, a3: (int)this);
  if ( result != 0 )
  {
    if ( v2 != 0 || v9 != 0 )
    {
      v6 = AfxGetModuleState();
      CHammer::EndImportSettings(this: (CHammer *)v6->m_pCurrentWinApp);
    }
    MainWnd = GetMainWnd();
    v8 = MainWnd;
    if ( MainWnd != nullptr )
    {
      CMainFrame::SetBrightness(this: MainWnd, fBrightness: this->textures.fBrightness);
      CMainFrame::UpdateAllDocViews(this: v8, dwCmd: 0x100u);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033FE35
// Name: public: virtual CTypedPtrArray<class CObArray,class CBitmap __near *>::~CTypedPtrArray<class CObArray,class CBitmap __near *>(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTypedPtrArray<CObArray,CBitmap *>::~CTypedPtrArray<CObArray,CBitmap *>(
        CTypedPtrArray<CObArray,CBitmap *> *this)
{
  CObArray::~CObArray(this);
}

//------------------------------------------------------------------------------
// Address: 0x10369A5B
// Name: public: virtual void CFile::Write(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFile::Write(CFile *this, const void *lpBuf, DWORD nCount)
{
  DWORD v3; // edi
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-Ch]

  v3 = nCount;
  if ( nCount != 0 )
  {
    if ( !WriteFile(
            hFile: this->m_hFile,
            lpBuffer: lpBuf,
            nNumberOfBytesToWrite: nCount,
            lpNumberOfBytesWritten: &nCount,
            lpOverlapped: nullptr) )
    {
      m_pszData = this->m_strFileName.m_pszData;
      LastError = GetLastError();
      CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
    }
    if ( nCount != v3 )
      AfxThrowFileException(cause: 13, lOsError: -1, lpszFileName: this->m_strFileName.m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036AF58
// Name: public: virtual void COleStreamFile::Write(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COleStreamFile::Write(COleStreamFile *this, const void *lpBuf, unsigned int nCount)
{
  int v3; // eax

  if ( nCount != 0 )
  {
    if ( lpBuf == nullptr )
      AfxThrowInvalidArgException();
    v3 = this->m_lpStream->Write(this: this->m_lpStream, a2: lpBuf, a3: nCount, a4: &nCount);
    if ( v3 != 0 )
      _AfxThrowOleFileException(sc: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5DF0
// Name: public: virtual int CSettingsStore::Write(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Write(CSettingsStore *this, const char *lpszValueName, unsigned int nValue)
{
  return this->Write_6(this, a2: lpszValueName, a3: nValue);
}

//------------------------------------------------------------------------------
// Address: 0x103F5DFB
// Name: public: virtual int CSettingsStore::Write(char const __near *,class CObject __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Write(CSettingsStore *this, const char *lpszValueName, CObject *obj)
{
  CObject_vtbl *v5; // eax
  unsigned __int8 *v6; // edi
  CArchive ar; // [esp+10h] [ebp-94h] BYREF
  CMemFile file; // [esp+58h] [ebp-4Ch] BYREF
  unsigned __int64 Length; // [esp+88h] [ebp-1Ch]
  int bRes; // [esp+90h] [ebp-14h]
  int v11; // [esp+A0h] [ebp-4h]

  if ( this->m_bReadOnly != 0 )
    return 0;
  bRes = 0;
  v11 = 0;
  CMemFile::CMemFile(this: &file, nGrowBytes: 0x400u);
  LOBYTE(v11) = 1;
  CArchive::CArchive(this: &ar, pFile: &file, nMode: 0, nBufSize: 4096, lpBuf: nullptr);
  v5 = obj->__vftable;
  LOBYTE(v11) = 2;
  ((void (__cdecl *)(CArchive *))v5->Serialize)(a1: &ar);
  CArchive::Flush(this: &ar);
  LOBYTE(v11) = 1;
  CArchive::~CArchive(this: &ar);
  Length = CMemFile::GetLength(this: &file);
  v6 = CMemFile::Detach(this: &file);
  if ( v6 == nullptr )
  {
    LOBYTE(v11) = 0;
    CMemFile::~CMemFile(this: &file);
    return 0;
  }
  bRes = this->Write_3(this, a2: lpszValueName, a3: v6, a4: Length);
  free(pMem: v6);
  LOBYTE(v11) = 0;
  CMemFile::~CMemFile(this: &file);
  return bRes;
}

//------------------------------------------------------------------------------
// Address: 0x103F5EDC
// Name: public: virtual int CSettingsStore::Write(char const __near *,class CObject __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Write(CSettingsStore *this, const char *lpszValueName, CObject *pObj)
{
  return this->Write_2(this, a2: lpszValueName, a3: pObj);
}

//------------------------------------------------------------------------------
// Address: 0x103F6047
// Name: public: virtual int CSettingsStore::Write(char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSettingsStore::Write(CSettingsStore *this, const char *lpszValueName, unsigned int dwValue)
{
  return this->m_bReadOnly == 0
      && RegSetValueExA(
           hKey: this->m_reg.m_hKey,
           lpValueName: lpszValueName,
           Reserved: 0,
           dwType: 4u,
           lpData: (const BYTE *)&dwValue,
           cbData: 4u) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F607B
// Name: public: virtual int CSettingsStore::Write(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSettingsStore::Write(CSettingsStore *this, const char *lpszValueName, const char *lpszData)
{
  return this->m_bReadOnly == 0
      && ATL::CRegKey::SetStringValue(this: &this->m_reg, pszValueName: lpszValueName, pszValue: lpszData, dwType: 1u) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F60A3
// Name: public: virtual int CSettingsStore::Write(char const __near *,class CRect const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Write(CSettingsStore *this, const char *lpszValueName, const CRect *rect)
{
  unsigned __int8 *v4; // edi
  int v6; // esi
  CArchive ar; // [esp+10h] [ebp-90h] BYREF
  CMemFile file; // [esp+58h] [ebp-48h] BYREF
  unsigned __int64 Length; // [esp+84h] [ebp-1Ch]
  int v10; // [esp+9Ch] [ebp-4h]

  if ( this->m_bReadOnly != 0 )
    return 0;
  v10 = 0;
  CMemFile::CMemFile(this: &file, nGrowBytes: 0x400u);
  LOBYTE(v10) = 1;
  CArchive::CArchive(this: &ar, pFile: &file, nMode: 0, nBufSize: 4096, lpBuf: nullptr);
  LOBYTE(v10) = 2;
  CArchive::Write(this: &ar, lpBuf: rect, nMax: 0x10u);
  CArchive::Flush(this: &ar);
  LOBYTE(v10) = 1;
  CArchive::~CArchive(this: &ar);
  Length = CMemFile::GetLength(this: &file);
  v4 = CMemFile::Detach(this: &file);
  if ( v4 == nullptr )
  {
    LOBYTE(v10) = 0;
    CMemFile::~CMemFile(this: &file);
    return 0;
  }
  v6 = this->Write_3(this, a2: lpszValueName, a3: v4, a4: Length);
  free(pMem: v4);
  LOBYTE(v10) = 0;
  CMemFile::~CMemFile(this: &file);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x103F6178
// Name: public: virtual int CSettingsStore::Write(char const __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSettingsStore::Write(
        CSettingsStore *this,
        const char *lpszValueName,
        unsigned __int8 *pData,
        DWORD nBytes)
{
  return this->m_bReadOnly == 0
      && RegSetValueExA(
           hKey: this->m_reg.m_hKey,
           lpValueName: lpszValueName,
           Reserved: 0,
           dwType: 3u,
           lpData: pData,
           cbData: nBytes) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10400F49
// Name: public: virtual void CMemFile::Write(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemFile::Write(CMemFile *this, const unsigned __int8 *lpBuf, unsigned int nCount)
{
  unsigned int m_nPosition; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // eax

  if ( nCount != 0 )
  {
    if ( lpBuf == nullptr )
      goto LABEL_3;
    m_nPosition = this->m_nPosition;
    v5 = m_nPosition + nCount;
    if ( m_nPosition + nCount < m_nPosition )
      goto LABEL_3;
    if ( v5 > this->m_nBufferSize )
      this->GrowFile(this, a2: v5);
    v6 = this->m_nPosition;
    if ( v6 + nCount > this->m_nBufferSize )
LABEL_3:
      AfxThrowInvalidArgException();
    this->Memcpy(this, a2: &this->m_lpBuffer[v6], a3: lpBuf, a4: nCount);
    this->m_nPosition += nCount;
    v7 = this->m_nPosition;
    if ( v7 > this->m_nFileSize )
      this->m_nFileSize = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033FE3A
// Name: protected: void CFrameWnd::BringToTop(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::BringToTop(CFrameWnd *this, int nCmdShow)
{
  HWND LastActivePopup; // eax

  if ( nCmdShow != 0 && nCmdShow != 6 && nCmdShow != 7 && nCmdShow != 8 && nCmdShow != 4 )
  {
    LastActivePopup = GetLastActivePopup(hWnd: this->m_hWnd);
    BringWindowToTop(hWnd: LastActivePopup);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033FE6E
// Name: public: class CFrameWnd __near * CControlBar::GetDockingFrame(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWnd *__thiscall CControlBar::GetDockingFrame(CControlBar *this)
{
  CFrameWnd *result; // eax

  result = CWnd::GetParentFrame(this);
  if ( result == nullptr )
    return this->m_pDockSite;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033FE84
// Name: public: int CControlBar::IsFloating(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlBar::IsFloating(CControlBar *this)
{
  CDockBar *m_pDockBar; // eax

  if ( this->IsDockBar(this) != 0 )
    return *((_DWORD *)this + 46);
  m_pDockBar = this->m_pDockBar;
  return m_pDockBar != nullptr && m_pDockBar->m_bFloating != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033FEB9
// Name: public: virtual struct CRuntimeClass __near * CFrameWnd::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFrameWnd::GetRuntimeClass(CFrameWnd *this)
{
  return &CFrameWnd::classCFrameWnd;
}

//------------------------------------------------------------------------------
// Address: 0x1033FEBF
// Name: public: virtual void CFrameWnd::SetMenuBarVisibility(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::SetMenuBarVisibility(CFrameWnd *this, unsigned int dwStyle)
{
  if ( dwStyle != 1 && dwStyle != 2 && dwStyle != 6 )
    AfxThrowInvalidArgException();
  if ( this->m_dwMenuBarVisibility != dwStyle )
  {
    if ( dwStyle == 1 )
    {
      this->m_dwMenuBarVisibility = 1;
      this->SetMenuBarState(this, a2: 1u);
    }
    else
    {
      this->m_dwMenuBarVisibility = dwStyle;
      this->SetMenuBarState(this, a2: 2u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033FF12
// Name: public: virtual unsigned long CFrameWnd::GetMenuBarVisibility(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::GetMenuBarVisibility(CMFCBaseTabCtrl *this)
{
  return this->m_nTabsHeight;
}

//------------------------------------------------------------------------------
// Address: 0x1033FF19
// Name: public: virtual int CFrameWnd::SetMenuBarState(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::SetMenuBarState(CFrameWnd *this, unsigned int dwState)
{
  if ( dwState != 1 && dwState != 2 )
    AfxThrowInvalidArgException();
  if ( this->m_dwMenuBarState == dwState )
    return 0;
  if ( dwState == 1 )
  {
    this->OnShowMenuBar(this);
    SetMenu(hWnd: this->m_hWnd, hMenu: this->m_hMenu);
  }
  else
  {
    this->m_hMenu = GetMenu(hWnd: this->m_hWnd);
    this->OnHideMenuBar(this);
    SetMenu(hWnd: this->m_hWnd, hMenu: nullptr);
  }
  this->m_dwMenuBarState = dwState;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033FF8B
// Name: public: virtual unsigned long CFrameWnd::GetMenuBarState(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CFrameWnd::GetMenuBarState(CFrameWnd *this)
{
  return this->m_dwMenuBarState;
}

//------------------------------------------------------------------------------
// Address: 0x1033FF92
// Name: public: virtual class CMenu __near * CFrameWnd::GetMenu(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMenu *__thiscall CFrameWnd::GetMenu(CFrameWnd *this)
{
  unsigned int m_dwMenuBarState; // eax
  HMENU Menu; // [esp-4h] [ebp-4h]

  m_dwMenuBarState = this->m_dwMenuBarState;
  if ( m_dwMenuBarState == 1 )
  {
    Menu = GetMenu(hWnd: this->m_hWnd);
    return CMenu::FromHandle(hMenu: Menu);
  }
  else
  {
    if ( m_dwMenuBarState != 2 )
      AfxThrowInvalidArgException();
    return CMenu::FromHandle(hMenu: this->m_hMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033FFBF
// Name: public: static class CNoTrackObject __near * CThreadLocal<class AFX_MODULE_THREAD_STATE>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MODULE_THREAD_STATE *__stdcall CThreadLocal<AFX_MODULE_THREAD_STATE>::CreateObject()
{
  AFX_MODULE_THREAD_STATE *v0; // ecx
  AFX_MODULE_THREAD_STATE *result; // eax

  v0 = (AFX_MODULE_THREAD_STATE *)CNoTrackObject::operator new(nSize: 0x54u);
  result = nullptr;
  if ( v0 != nullptr )
    return AFX_MODULE_THREAD_STATE::AFX_MODULE_THREAD_STATE(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10369AA8
// Name: public: virtual unsigned __int64 CFile::Seek(__int64,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LARGE_INTEGER __thiscall CFile::Seek(CFile *this, __int64 lOff, DWORD nFrom)
{
  DWORD LastError; // eax
  void *m_hFile; // [esp-10h] [ebp-1Ch]
  char *m_pszData; // [esp-8h] [ebp-14h]
  _LARGE_INTEGER liOff; // [esp+4h] [ebp-8h] BYREF

  m_hFile = this->m_hFile;
  liOff.HighPart = HIDWORD(lOff);
  liOff.LowPart = SetFilePointer(
                    hFile: m_hFile,
                    lDistanceToMove: lOff,
                    lpDistanceToMoveHigh: &liOff.HighPart,
                    dwMoveMethod: nFrom);
  if ( liOff.LowPart == -1 && GetLastError() != 0 )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
  return liOff;
}

//------------------------------------------------------------------------------
// Address: 0x10369AFB
// Name: public: virtual unsigned __int64 CFile::GetPosition(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LARGE_INTEGER __thiscall CFile::GetPosition(CFile *this)
{
  DWORD LastError; // eax
  void *m_hFile; // [esp-10h] [ebp-1Ch]
  char *m_pszData; // [esp-8h] [ebp-14h]
  _LARGE_INTEGER liPos; // [esp+4h] [ebp-8h] BYREF

  m_hFile = this->m_hFile;
  liPos.HighPart = 0;
  liPos.LowPart = SetFilePointer(
                    hFile: m_hFile,
                    lDistanceToMove: 0,
                    lpDistanceToMoveHigh: &liPos.HighPart,
                    dwMoveMethod: 1u);
  if ( liPos.LowPart == -1 && GetLastError() != 0 )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
  return liPos;
}

//------------------------------------------------------------------------------
// Address: 0x10369B47
// Name: public: virtual void CFile::Flush(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::Flush(CFile *this)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-8h]

  if ( this->m_hFile != (void *)-1 && !FlushFileBuffers(hFile: this->m_hFile) )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369B70
// Name: public: virtual void CFile::LockRange(unsigned __int64,unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::LockRange(CFile *this, unsigned __int64 dwPos, unsigned __int64 dwCount)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-8h]

  if ( !LockFile(
          hFile: this->m_hFile,
          dwFileOffsetLow: dwPos,
          dwFileOffsetHigh: HIDWORD(dwPos),
          nNumberOfBytesToLockLow: dwCount,
          nNumberOfBytesToLockHigh: HIDWORD(dwCount)) )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369BA5
// Name: public: virtual void CFile::UnlockRange(unsigned __int64,unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::UnlockRange(CFile *this, unsigned __int64 dwPos, unsigned __int64 dwCount)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-8h]

  if ( !UnlockFile(
          hFile: this->m_hFile,
          dwFileOffsetLow: dwPos,
          dwFileOffsetHigh: HIDWORD(dwPos),
          nNumberOfBytesToUnlockLow: dwCount,
          nNumberOfBytesToUnlockHigh: HIDWORD(dwCount)) )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369BDA
// Name: public: virtual void CFile::SetLength(unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::SetLength(CFile *this, unsigned __int64 dwNewLen)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-8h]

  ((void (__thiscall *)(CFile *, _DWORD, _DWORD, _DWORD))this->Seek)(
    a1: this,
    a2: dwNewLen,
    a3: HIDWORD(dwNewLen),
    a4: 0);
  if ( !SetEndOfFile(hFile: this->m_hFile) )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369C10
// Name: public: virtual unsigned __int64 CFile::GetLength(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_ULARGE_INTEGER __thiscall CFile::GetLength(CFile *this)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-8h] [ebp-14h]
  _ULARGE_INTEGER liSize; // [esp+4h] [ebp-8h] BYREF

  liSize.LowPart = GetFileSize(hFile: this->m_hFile, lpFileSizeHigh: &liSize.HighPart);
  if ( liSize.LowPart == -1 && GetLastError() != 0 )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
  return liSize;
}

//------------------------------------------------------------------------------
// Address: 0x10369C51
// Name: public: static void CFile::Rename(char const __near *,char const __near *,class ATL::CAtlTransactionManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CFile::Rename(const char *lpszOldName, const char *lpszNewName, ATL::CAtlTransactionManager *pTM)
{
  BOOL v3; // eax
  DWORD LastError; // eax

  if ( pTM != nullptr )
    v3 = ATL::CAtlTransactionManager::MoveFileA(this: pTM, lpOldFileName: lpszOldName, lpNewFileName: lpszNewName);
  else
    v3 = MoveFileA(lpExistingFileName: lpszOldName, lpNewFileName: lpszNewName);
  if ( !v3 )
  {
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: lpszOldName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369C87
// Name: public: static void CFile::Remove(char const __near *,class ATL::CAtlTransactionManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CFile::Remove(const char *lpszFileName, ATL::CAtlTransactionManager *pTM)
{
  BOOL v2; // eax
  DWORD LastError; // eax

  if ( pTM != nullptr )
    v2 = ATL::CAtlTransactionManager::DeleteFileA(this: pTM, lpFileName: lpszFileName);
  else
    v2 = DeleteFileA(lpFileName: lpszFileName);
  if ( !v2 )
  {
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369CBA
// Name: unsigned int AfxGetFileTitle(char const __near *,char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxGetFileTitle(const char *lpszPathName, char *lpszTitle, unsigned int nMax)
{
  char *v3; // ebx
  char szTemp[260]; // [esp+Ch] [ebp-108h] BYREF

  v3 = lpszTitle;
  if ( lpszTitle == nullptr )
  {
    v3 = szTemp;
    nMax = 260;
  }
  if ( GetFileTitleA(a1: lpszPathName, Buf: v3, cchSize: nMax) != 0 )
    return AfxGetFileName(lpszPathName, lpszTitle, nMax);
  if ( lpszTitle != nullptr )
    return 0;
  return lstrlenA(lpString: v3) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10369D28
// Name: public: virtual void CFile::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::Close(CFile *this)
{
  BOOL v2; // edi
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-Ch]

  v2 = false;
  if ( this->m_hFile != (void *)-1 )
    v2 = !CloseHandle(hObject: this->m_hFile);
  this->m_hFile = (void *)-1;
  this->m_bCloseOnDelete = 0;
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strFileName);
  if ( v2 )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036AF8F
// Name: public: virtual void COleStreamFile::LockRange(unsigned __int64,unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleStreamFile::LockRange(COleStreamFile *this, unsigned __int64 dwPos, unsigned __int64 dwCount)
{
  int v3; // eax

  v3 = ((int (__stdcall *)(IStream *, _DWORD, _DWORD, _DWORD, _DWORD, int))this->m_lpStream->LockRegion)(
         a1: this->m_lpStream,
         a2: dwPos,
         a3: HIDWORD(dwPos),
         a4: dwCount,
         a5: HIDWORD(dwCount),
         a6: 2);
  if ( v3 != 0 )
    _AfxThrowOleFileException(sc: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1036AFB9
// Name: public: virtual void COleStreamFile::UnlockRange(unsigned __int64,unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleStreamFile::UnlockRange(COleStreamFile *this, unsigned __int64 dwPos, unsigned __int64 dwCount)
{
  int v3; // eax

  v3 = ((int (__stdcall *)(IStream *, _DWORD, _DWORD, _DWORD, _DWORD, int))this->m_lpStream->UnlockRegion)(
         a1: this->m_lpStream,
         a2: dwPos,
         a3: HIDWORD(dwPos),
         a4: dwCount,
         a5: HIDWORD(dwCount),
         a6: 2);
  if ( v3 != 0 )
    _AfxThrowOleFileException(sc: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1036AFE3
// Name: public: virtual void COleStreamFile::Flush(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleStreamFile::Flush(COleStreamFile *this)
{
  int v1; // eax

  v1 = this->m_lpStream->Commit(this: this->m_lpStream, a2: 0);
  if ( v1 != 0 )
    _AfxThrowOleFileException(sc: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1036AFF9
// Name: public: int ATL::CAtlTransactionManager::GetFileAttributesExA(char const __near *,enum _GET_FILEEX_INFO_LEVELS,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall ATL::CAtlTransactionManager::GetFileAttributesExA(
        ATL::CAtlTransactionManager *this,
        const char *lpFileName,
        _GET_FILEEX_INFO_LEVELS fInfoLevelId,
        void *lpFileInformation)
{
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *GetFileAttributesTransactedA)(LPCSTR, GET_FILEEX_INFO_LEVELS, LPVOID, HANDLE); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32.dll");
    if ( ModuleHandleA != nullptr )
    {
      GetFileAttributesTransactedA = (BOOL (__stdcall *)(LPCSTR, GET_FILEEX_INFO_LEVELS, LPVOID, HANDLE))GetProcAddress(hModule: ModuleHandleA, lpProcName: "GetFileAttributesTransactedA");
      if ( GetFileAttributesTransactedA != nullptr )
        return GetFileAttributesTransactedA(
                 lpFileName,
                 fInfoLevelId,
                 lpFileInformation,
                 hTransaction: this->m_hTransaction);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return GetFileAttributesExA(lpFileName, fInfoLevelId, lpFileInformation);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1036B049
// Name: public: struct tm __near * ATL::CTime::GetLocalTm(struct tm __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tm *__thiscall ATL::CTime::GetLocalTm(ATL::CTime *this, tm *ptm)
{
  tm ptmTemp; // [esp+4h] [ebp-28h] BYREF

  if ( ptm == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  if ( _localtime64_s(ptm: &ptmTemp, ptime: &this->m_time) != 0 )
    return nullptr;
  *ptm = ptmTemp;
  return ptm;
}

//------------------------------------------------------------------------------
// Address: 0x1036B0A0
// Name: public: int ATL::CTime::GetYear(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ATL::CTime::GetYear(ATL::CTime *this)
{
  tm *LocalTm; // eax
  tm ttm; // [esp+0h] [ebp-28h] BYREF

  LocalTm = ATL::CTime::GetLocalTm(this, ptm: &ttm);
  if ( LocalTm != nullptr )
    return LocalTm->tm_year + 1900;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036B0D7
// Name: public: int ATL::CTime::GetMonth(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ATL::CTime::GetMonth(ATL::CTime *this)
{
  tm *LocalTm; // eax
  tm ttm; // [esp+0h] [ebp-28h] BYREF

  LocalTm = ATL::CTime::GetLocalTm(this, ptm: &ttm);
  if ( LocalTm != nullptr )
    return LocalTm->tm_mon + 1;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036B10A
// Name: public: int ATL::CTime::GetDay(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ATL::CTime::GetDay(ATL::CTime *this)
{
  tm *LocalTm; // eax
  tm ttm; // [esp+0h] [ebp-28h] BYREF

  LocalTm = ATL::CTime::GetLocalTm(this, ptm: &ttm);
  if ( LocalTm != nullptr )
    return LocalTm->tm_mday;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036B13C
// Name: public: int ATL::CTime::GetHour(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ATL::CTime::GetHour(ATL::CTime *this)
{
  tm *LocalTm; // eax
  tm ttm; // [esp+0h] [ebp-28h] BYREF

  LocalTm = ATL::CTime::GetLocalTm(this, ptm: &ttm);
  if ( LocalTm != nullptr )
    return LocalTm->tm_hour;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1036B16F
// Name: public: int ATL::CTime::GetMinute(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ATL::CTime::GetMinute(ATL::CTime *this)
{
  tm *LocalTm; // eax
  tm ttm; // [esp+0h] [ebp-28h] BYREF

  LocalTm = ATL::CTime::GetLocalTm(this, ptm: &ttm);
  if ( LocalTm != nullptr )
    return LocalTm->tm_min;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1036B1A2
// Name: public: int ATL::CTime::GetSecond(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ATL::CTime::GetSecond(ATL::CTime *this)
{
  tm *LocalTm; // eax
  tm ttm; // [esp+0h] [ebp-28h] BYREF

  LocalTm = ATL::CTime::GetLocalTm(this, ptm: &ttm);
  if ( LocalTm != nullptr )
    return LocalTm->tm_sec;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1036B1D4
// Name: public: static int CFile::GetStatus(char const __near *,struct CFileStatus __near &,class ATL::CAtlTransactionManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CFile::GetStatus(char *lpszFileName, CFileStatus *rStatus, ATL::CAtlTransactionManager *pTM)
{
  BOOL FileAttributes; // eax
  unsigned __int64 v5; // rax
  ATL::CTime v6; // [esp+8h] [ebp-30h] BYREF
  _WIN32_FILE_ATTRIBUTE_DATA fileAttributeData; // [esp+10h] [ebp-28h] BYREF

  HIDWORD(v6.m_time) = pTM;
  if ( lpszFileName == nullptr || lstrlenA(lpString: lpszFileName) >= 260 )
    return 0;
  if ( AfxFullPath(lpszPathOut: rStatus->m_szFullName, lpszFileIn: lpszFileName) == 0 )
  {
    rStatus->m_szFullName[0] = 0;
    return 0;
  }
  if ( HIDWORD(v6.m_time) != 0 )
    FileAttributes = ATL::CAtlTransactionManager::GetFileAttributesExA(
                       this: (ATL::CAtlTransactionManager *)HIDWORD(v6.m_time),
                       lpFileName: lpszFileName,
                       fInfoLevelId: GetFileExInfoStandard,
                       lpFileInformation: &fileAttributeData);
  else
    FileAttributes = GetFileAttributesExA(
                       lpFileName: lpszFileName,
                       fInfoLevelId: GetFileExInfoStandard,
                       lpFileInformation: &fileAttributeData);
  if ( !FileAttributes )
    return 0;
  rStatus->m_attribute = fileAttributeData.dwFileAttributes & 0x7F;
  v5 = (unsigned __int64)fileAttributeData.nFileSizeHigh << 32;
  LODWORD(rStatus->m_size) = 0;
  LODWORD(rStatus->m_size) |= fileAttributeData.nFileSizeLow;
  HIDWORD(rStatus->m_size) = HIDWORD(v5);
  HIDWORD(rStatus->m_size) = HIDWORD(rStatus->m_size);
  if ( ATL::CTime::IsValidFILETIME(fileTime: &fileAttributeData.ftCreationTime) )
    rStatus->m_ctime = (ATL::CTime)ATL::CTime::CTime(this: &v6, fileTime: &fileAttributeData.ftCreationTime, nDST: -1)->m_time;
  else
    rStatus->m_ctime.m_time = 0;
  if ( ATL::CTime::IsValidFILETIME(fileTime: &fileAttributeData.ftLastAccessTime) )
    rStatus->m_atime = (ATL::CTime)ATL::CTime::CTime(this: &v6, fileTime: &fileAttributeData.ftLastAccessTime, nDST: -1)->m_time;
  else
    rStatus->m_atime.m_time = 0;
  if ( ATL::CTime::IsValidFILETIME(fileTime: &fileAttributeData.ftLastWriteTime) )
    rStatus->m_mtime = (ATL::CTime)ATL::CTime::CTime(this: &v6, fileTime: &fileAttributeData.ftLastWriteTime, nDST: -1)->m_time;
  else
    rStatus->m_mtime.m_time = 0;
  if ( rStatus->m_ctime.m_time == 0 )
    rStatus->m_ctime.m_time = rStatus->m_mtime.m_time;
  if ( rStatus->m_atime.m_time == 0 )
    rStatus->m_atime.m_time = rStatus->m_mtime.m_time;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1036B334
// Name: void AfxTimeToFileTime(class ATL::CTime const __near &,struct _FILETIME __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl AfxTimeToFileTime(ATL::CTime *time, _FILETIME *pFileTime)
{
  DWORD LastError; // eax
  DWORD v3; // eax
  _FILETIME localTime; // [esp+8h] [ebp-1Ch] BYREF
  _SYSTEMTIME sysTime; // [esp+10h] [ebp-14h] BYREF

  if ( pFileTime == nullptr )
    AfxThrowInvalidArgException();
  sysTime.wYear = ATL::CTime::GetYear(this: time);
  sysTime.wMonth = ATL::CTime::GetMonth(this: time);
  sysTime.wDay = ATL::CTime::GetDay(this: time);
  sysTime.wHour = ATL::CTime::GetHour(this: time);
  sysTime.wMinute = ATL::CTime::GetMinute(this: time);
  sysTime.wSecond = ATL::CTime::GetSecond(this: time);
  sysTime.wMilliseconds = 0;
  if ( !SystemTimeToFileTime(lpSystemTime: &sysTime, lpFileTime: &localTime) )
  {
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: nullptr);
  }
  if ( !LocalFileTimeToFileTime(lpLocalFileTime: &localTime, lpFileTime: pFileTime) )
  {
    v3 = GetLastError();
    CFileException::ThrowOsError(lOsError: v3, lpszFileName: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036B3E7
// Name: public: int CFile::GetStatus(struct CFileStatus __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFile::GetStatus(CFile *this, CFileStatus *rStatus)
{
  int v3; // eax
  void *m_hFile; // eax
  char *m_pszData; // eax
  ATL::CAtlTransactionManager *m_pTM; // ecx
  BOOL FileAttributes; // eax
  DWORD FileAttributesA; // eax
  _FILETIME ftCreate; // [esp+Ch] [ebp-50h] BYREF
  _LARGE_INTEGER li; // [esp+14h] [ebp-48h] BYREF
  ATL::CTime v12; // [esp+1Ch] [ebp-40h] BYREF
  _FILETIME ftModify; // [esp+24h] [ebp-38h] BYREF
  _FILETIME ftAccess; // [esp+2Ch] [ebp-30h] BYREF
  _DWORD FileInformation[9]; // [esp+34h] [ebp-28h] BYREF

  memset(dst: (unsigned __int8 *)rStatus, value: 0, count: sizeof(CFileStatus));
  v3 = _mbsnbcpy_s(
         _Arg1: (unsigned __int8 *)rStatus->m_szFullName,
         _Arg2: 0x104u,
         _Arg3: (const unsigned __int8 *)this->m_strFileName.m_pszData,
         _Arg4: 0xFFFFFFFF);
  AfxCrtErrorCheck(error: v3);
  m_hFile = this->m_hFile;
  if ( m_hFile != (void *)-1 )
  {
    if ( !GetFileTime(
            hFile: m_hFile,
            lpCreationTime: &ftCreate,
            lpLastAccessTime: &ftAccess,
            lpLastWriteTime: &ftModify)
      || !GetFileSizeEx(hFile: this->m_hFile, lpFileSize: &li) )
    {
      return 0;
    }
    rStatus->m_size = li.QuadPart;
    m_pszData = this->m_strFileName.m_pszData;
    if ( *((_DWORD *)m_pszData - 3) != 0 )
    {
      m_pTM = this->m_pTM;
      if ( m_pTM != nullptr )
      {
        FileAttributes = ATL::CAtlTransactionManager::GetFileAttributesExA(
                           this: m_pTM,
                           lpFileName: m_pszData,
                           fInfoLevelId: GetFileExInfoStandard,
                           lpFileInformation: FileInformation);
        FileAttributesA = FileAttributes ? FileInformation[0] : 0;
      }
      else
      {
        FileAttributesA = GetFileAttributesA(lpFileName: this->m_strFileName.m_pszData);
      }
      rStatus->m_attribute = FileAttributesA == -1 ? 0 : FileAttributesA;
    }
    else
    {
      rStatus->m_attribute = 0;
    }
    if ( ATL::CTime::IsValidFILETIME(fileTime: &ftCreate) )
      rStatus->m_ctime = (ATL::CTime)ATL::CTime::CTime(this: &v12, fileTime: &ftCreate, nDST: -1)->m_time;
    else
      rStatus->m_ctime.m_time = 0;
    if ( ATL::CTime::IsValidFILETIME(fileTime: &ftAccess) )
      rStatus->m_atime = (ATL::CTime)ATL::CTime::CTime(this: &v12, fileTime: &ftAccess, nDST: -1)->m_time;
    else
      rStatus->m_atime.m_time = 0;
    if ( ATL::CTime::IsValidFILETIME(fileTime: &ftModify) )
      rStatus->m_mtime = (ATL::CTime)ATL::CTime::CTime(this: &v12, fileTime: &ftModify, nDST: -1)->m_time;
    else
      rStatus->m_mtime.m_time = 0;
    if ( rStatus->m_ctime.m_time == 0 )
      rStatus->m_ctime.m_time = rStatus->m_mtime.m_time;
    if ( rStatus->m_atime.m_time == 0 )
      rStatus->m_atime.m_time = rStatus->m_mtime.m_time;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F5EE7
// Name: public: virtual int CSettingsStore::Read(char const __near *,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Read(CSettingsStore *this, const char *lpszValueName, int *nValue)
{
  return this->Read_6(this, a2: lpszValueName, a3: (unsigned int *)nValue);
}

//------------------------------------------------------------------------------
// Address: 0x103F5EF2
// Name: public: virtual int CSettingsStore::Read(char const __near *,class CObject __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Read(CSettingsStore *this, const char *lpszValueName, CObject *obj)
{
  CSettingsStore_vtbl *v3; // eax
  CObject_vtbl *v5; // eax
  CArchive ar; // [esp+10h] [ebp-94h] BYREF
  CMemFile file; // [esp+58h] [ebp-4Ch] BYREF
  int bSucess; // [esp+8Ch] [ebp-18h]
  unsigned __int8 *pData; // [esp+90h] [ebp-14h] BYREF
  int v10; // [esp+A0h] [ebp-4h]

  v3 = this->__vftable;
  bSucess = 0;
  pData = nullptr;
  if ( v3->Read_3(this, a2: lpszValueName, a3: &pData, a4: (unsigned int *)&lpszValueName) != 0 )
  {
    if ( pData == nullptr )
LABEL_3:
      AfxThrowInvalidArgException();
    v10 = 0;
    CMemFile::CMemFile(this: &file, lpBuffer: pData, nBufferSize: (unsigned int)lpszValueName, nGrowBytes: 0);
    LOBYTE(v10) = 1;
    CArchive::CArchive(this: &ar, pFile: &file, nMode: 1u, nBufSize: 4096, lpBuf: nullptr);
    v5 = obj->__vftable;
    LOBYTE(v10) = 2;
    ((void (__cdecl *)(CArchive *))v5->Serialize)(a1: &ar);
    bSucess = 1;
    LOBYTE(v10) = 1;
    CArchive::~CArchive(this: &ar);
    LOBYTE(v10) = 0;
    CMemFile::~CMemFile(this: &file);
    v10 = -1;
    operator delete(p: pData);
    return bSucess;
  }
  else
  {
    if ( pData != nullptr )
      goto LABEL_3;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5FD4
// Name: public: long ATL::CRegKey::QueryDWORDValue(char const __near *,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CRegKey::QueryDWORDValue(
        ATL::CRegKey *this,
        const char *pszValueName,
        unsigned __int8 *dwValue)
{
  LSTATUS result; // eax
  unsigned int nBytes; // [esp+0h] [ebp-4h] BYREF

  nBytes = 4;
  result = RegQueryValueExA(
             hKey: this->m_hKey,
             lpValueName: pszValueName,
             lpReserved: nullptr,
             lpType: (LPDWORD)&dwValue,
             lpData: dwValue,
             lpcbData: &nBytes);
  if ( result == 0 )
    return dwValue != (unsigned __int8 *)4 ? 0xD : 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F600E
// Name: public: long ATL::CRegKey::QueryBinaryValue(char const __near *,void __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CRegKey::QueryBinaryValue(
        ATL::CRegKey *this,
        const char *pszValueName,
        unsigned __int8 *pValue,
        unsigned int *pnBytes)
{
  LSTATUS result; // eax

  result = RegQueryValueExA(
             hKey: this->m_hKey,
             lpValueName: pszValueName,
             lpReserved: nullptr,
             lpType: (LPDWORD)&pnBytes,
             lpData: pValue,
             lpcbData: pnBytes);
  if ( result == 0 )
    return pnBytes != (unsigned int *)3 ? 0xD : 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F603F
// Name: public: virtual void CSettingsStore::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSettingsStore::Close(CSettingsStore *this)
{
  ATL::CRegKey::Close(this: &this->m_reg);
}

//------------------------------------------------------------------------------
// Address: 0x103F61A6
// Name: public: virtual int CSettingsStore::Read(char const __near *,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CSettingsStore::Read(CSettingsStore *this, const char *lpszValueName, unsigned __int8 *dwValue)
{
  return ATL::CRegKey::QueryDWORDValue(this: &this->m_reg, pszValueName: lpszValueName, dwValue) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F61C2
// Name: public: virtual int CSettingsStore::Read(char const __near *,class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Read(CSettingsStore *this, const char *lpszValueName, CRect *rect)
{
  CSettingsStore_vtbl *v3; // eax
  CArchive ar; // [esp+10h] [ebp-94h] BYREF
  CMemFile file; // [esp+58h] [ebp-4Ch] BYREF
  int bSucess; // [esp+8Ch] [ebp-18h]
  unsigned __int8 *pData; // [esp+90h] [ebp-14h] BYREF
  int v9; // [esp+A0h] [ebp-4h]

  v3 = this->__vftable;
  bSucess = 0;
  pData = nullptr;
  if ( v3->Read_3(this, a2: lpszValueName, a3: &pData, a4: (unsigned int *)&lpszValueName) != 0 )
  {
    if ( pData == nullptr )
LABEL_3:
      AfxThrowInvalidArgException();
    v9 = 0;
    CMemFile::CMemFile(this: &file, lpBuffer: pData, nBufferSize: (unsigned int)lpszValueName, nGrowBytes: 0);
    LOBYTE(v9) = 1;
    CArchive::CArchive(this: &ar, pFile: &file, nMode: 1u, nBufSize: 4096, lpBuf: nullptr);
    LOBYTE(v9) = 2;
    operator>>(&ar, rect);
    bSucess = 1;
    LOBYTE(v9) = 1;
    CArchive::~CArchive(this: &ar);
    LOBYTE(v9) = 0;
    CMemFile::~CMemFile(this: &file);
    v9 = -1;
    operator delete(p: pData);
    return bSucess;
  }
  else
  {
    if ( pData != nullptr )
      goto LABEL_3;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F62A4
// Name: public: virtual int CSettingsStore::Read(char const __near *,unsigned char __near * __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Read(
        CSettingsStore *this,
        const char *lpszValueName,
        unsigned __int8 **ppData,
        unsigned int *pcbData)
{
  ATL::CRegKey *p_m_reg; // ebx
  unsigned __int8 *v5; // eax

  if ( lpszValueName == nullptr || ppData == nullptr || pcbData == nullptr )
    AfxThrowInvalidArgException();
  p_m_reg = &this->m_reg;
  *ppData = nullptr;
  *pcbData = 0;
  if ( ATL::CRegKey::QueryBinaryValue(
         this: &this->m_reg,
         pszValueName: lpszValueName,
         pValue: nullptr,
         pnBytes: pcbData) == 0
    && *pcbData != 0 )
  {
    v5 = (unsigned __int8 *)operator new(nSize: *pcbData);
    *ppData = v5;
    if ( ATL::CRegKey::QueryBinaryValue(this: p_m_reg, pszValueName: lpszValueName, pValue: v5, pnBytes: pcbData) == 0 )
      return 1;
    operator delete(p: *ppData);
    *ppData = nullptr;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F6315
// Name: public: virtual int CSettingsStore::Read(char const __near *,class CObject __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSettingsStore::Read(CSettingsStore *this, const char *lpszValueName, CObject **pObj)
{
  CSettingsStore_vtbl *v3; // eax
  CObject *v5; // eax
  CArchive ar; // [esp+10h] [ebp-94h] BYREF
  CMemFile file; // [esp+58h] [ebp-4Ch] BYREF
  int bSucess; // [esp+8Ch] [ebp-18h]
  unsigned __int8 *pData; // [esp+90h] [ebp-14h] BYREF
  int v10; // [esp+A0h] [ebp-4h]

  v3 = this->__vftable;
  bSucess = 0;
  pData = nullptr;
  if ( v3->Read_3(this, a2: lpszValueName, a3: &pData, a4: (unsigned int *)&lpszValueName) != 0 )
  {
    if ( pData == nullptr )
LABEL_3:
      AfxThrowInvalidArgException();
    v10 = 0;
    CMemFile::CMemFile(this: &file, lpBuffer: pData, nBufferSize: (unsigned int)lpszValueName, nGrowBytes: 0);
    LOBYTE(v10) = 1;
    CArchive::CArchive(this: &ar, pFile: &file, nMode: 1u, nBufSize: 4096, lpBuf: nullptr);
    LOBYTE(v10) = 2;
    v5 = CArchive::ReadObject(this: &ar, pClassRefRequested: nullptr);
    *pObj = v5;
    bSucess = 1;
    LOBYTE(v10) = 1;
    CArchive::~CArchive(this: &ar);
    LOBYTE(v10) = 0;
    CMemFile::~CMemFile(this: &file);
    v10 = -1;
    operator delete(p: pData);
    return bSucess;
  }
  else
  {
    if ( pData != nullptr )
      goto LABEL_3;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F63F9
// Name: public: virtual int CSettingsStore::DeleteValue(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CSettingsStore::DeleteValue(CSettingsStore *this, const char *lpszValue)
{
  return RegDeleteValueA(hKey: this->m_reg.m_hKey, lpValueName: lpszValue) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F6413
// Name: protected: CSettingsStore::CSettingsStore(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSettingsStore *__thiscall CSettingsStore::CSettingsStore(CSettingsStore *this)
{
  CAfxStringMgr *StringManager; // eax

  this->__vftable = (CSettingsStore_vtbl *)&CSettingsStore::`vftable';
  this->m_reg.m_hKey = nullptr;
  this->m_reg.m_samWOW64 = 0;
  this->m_reg.m_pTM = nullptr;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strPath, pStringMgr: StringManager);
  this->m_bReadOnly = 0;
  this->m_bAdmin = 0;
  this->m_dwUserData = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F6446
// Name: public: virtual CSettingsStore::~CSettingsStore(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSettingsStore::~CSettingsStore(CSettingsStore *this)
{
  this->__vftable = (CSettingsStore_vtbl *)&CSettingsStore::`vftable';
  ATL::CRegKey::Close(this: &this->m_reg);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strPath.m_pszData - 1);
  ATL::CRegKey::Close(this: &this->m_reg);
}

//------------------------------------------------------------------------------
// Address: 0x103F646F
// Name: public: class CSettingsStore __near & CSettingsStoreSP::Create(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSettingsStore *__thiscall CSettingsStoreSP::Create(CSettingsStoreSP *this, int bAdmin, int bReadOnly)
{
  CSettingsStore *result; // eax
  CSettingsStore *v5; // ecx
  CSettingsStore *v6; // eax
  CObject *Object; // eax

  result = this->m_pRegistry;
  if ( this->m_pRegistry == nullptr )
  {
    if ( CSettingsStoreSP::m_pRTIDefault != nullptr )
    {
      Object = CRuntimeClass::CreateObject(this: CSettingsStoreSP::m_pRTIDefault);
      v6 = (CSettingsStore *)AfxDynamicDownCast(pClass: &CSettingsStore::classCSettingsStore, pObject: Object);
    }
    else
    {
      v5 = (CSettingsStore *)operator new(nSize: 0x20u);
      if ( v5 != nullptr )
        v6 = CSettingsStore::CSettingsStore(this: v5);
      else
        v6 = nullptr;
    }
    this->m_pRegistry = v6;
    v6->m_bReadOnly = bReadOnly;
    this->m_pRegistry->m_bAdmin = bAdmin;
    this->m_pRegistry->m_reg.m_hKey = (HKEY__ *)((bAdmin != 0) - 0x7FFFFFFF);
    this->m_pRegistry->m_dwUserData = this->m_dwUserData;
    return this->m_pRegistry;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F64F3
// Name: public: static class CObject __near * CSettingsStore::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSettingsStore *__stdcall CSettingsStore::CreateObject()
{
  CSettingsStore *v0; // ecx
  CSettingsStore *result; // eax

  v0 = (CSettingsStore *)operator new(nSize: 0x20u);
  result = nullptr;
  if ( v0 != nullptr )
    return CSettingsStore::CSettingsStore(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F6541
// Name: public: virtual int CSettingsStore::Read(char const __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CSettingsStore::Read(
        CSettingsStore *this,
        const char *lpszValueName,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strValue)
{
  char *v5; // edi
  int v6; // eax
  BOOL v7; // esi
  unsigned int dwCount; // [esp+8h] [ebp-4h] BYREF

  if ( lpszValueName == nullptr )
    AfxThrowInvalidArgException();
  ATL::CSimpleStringT<char,0>::Empty(this: strValue);
  dwCount = 0;
  if ( ATL::CRegKey::QueryStringValue(
         this: &this->m_reg,
         pszValueName: lpszValueName,
         pszValue: nullptr,
         pnChars: &dwCount) != 0 )
    return false;
  if ( dwCount == 0 )
    return true;
  v5 = (char *)operator new(nSize: dwCount + 1);
  v6 = ATL::CRegKey::QueryStringValue(this: &this->m_reg, pszValueName: lpszValueName, pszValue: v5, pnChars: &dwCount);
  v7 = v6 == 0;
  if ( v6 == 0 )
    ATL::CSimpleStringT<char,0>::SetString(this: strValue, pszSrc: v5);
  operator delete(p: v5);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x103F65C1
// Name: PreparePath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *__stdcall PreparePath(
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *result,
        const char *lpszPath)
{
  int v2; // ecx
  int v3; // edx
  ATL::CStringData *v4; // eax

  if ( lpszPath == nullptr )
    AfxThrowInvalidArgException();
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: result,
    pszSrc: lpszPath);
  v2 = *((_DWORD *)result->m_pszData - 3);
  if ( v2 > 0 )
  {
    v3 = v2 - 1;
    if ( v3 > v2 )
      ATL::AtlThrowImpl(hr: -2147024809);
    if ( result->m_pszData[v3] == 92 )
    {
      v4 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                 this: result,
                                 result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszPath,
                                 nCount: v2 - 1);
      ATL::CSimpleStringT<char,0>::operator=(this: result, strSrc: v4);
      ATL::CStringData::Release(this: (ATL::CStringData *)lpszPath - 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400FAB
// Name: public: virtual unsigned __int64 CMemFile::Seek(__int64,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMemFile::Seek(CMemFile *this, __int64 lOff, unsigned int nFrom)
{
  unsigned int m_nPosition; // esi
  int v5; // eax

  m_nPosition = this->m_nPosition;
  if ( nFrom != 0 )
  {
    if ( nFrom != 1 )
    {
      if ( nFrom != 2 )
        return m_nPosition;
      if ( lOff > 0 )
LABEL_6:
        AfxThrowFileException(cause: 9, lOsError: -1, lpszFileName: nullptr);
      m_nPosition = this->m_nFileSize;
    }
    v5 = (lOff + (unsigned __int64)m_nPosition) >> 32;
    m_nPosition += lOff;
  }
  else
  {
    v5 = HIDWORD(lOff);
    m_nPosition = lOff;
  }
  if ( v5 < 0 )
    goto LABEL_6;
  if ( m_nPosition > this->m_nFileSize )
    this->GrowFile(this, a2: m_nPosition);
  this->m_nPosition = m_nPosition;
  return m_nPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10401019
// Name: public: virtual void CMemFile::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMemFile::Close(CMemFile *this)
{
  unsigned __int8 *m_lpBuffer; // eax

  m_lpBuffer = this->m_lpBuffer;
  this->m_nGrowBytes = 0;
  this->m_nPosition = 0;
  this->m_nBufferSize = 0;
  this->m_nFileSize = 0;
  if ( m_lpBuffer != nullptr && this->m_bAutoDelete != 0 )
    this->Free(this, a2: m_lpBuffer);
  this->m_lpBuffer = nullptr;
}
