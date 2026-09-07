// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/basesavegamedialog.cpp
// Functions: 36
// ============================================================

#include "game\client\cstrike15\gameui\basesavegamedialog.h"

//------------------------------------------------------------------------------
// Address: 0x101D0390
// Name: public: static char const __near * CBaseSaveGameDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseSaveGameDialog::GetPanelClassName()
{
  return "CBaseSaveGameDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101D03A0
// Name: public: virtual void BaseSaveGameDialogPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSaveGameDialogPrecache::CResourcePrecacher::Cache(
        BaseSaveGameDialogPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "vgui/resource/autosave.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D03D0
// Name: public: static char const __near * CSaveGamePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveGamePanel::GetPanelClassName()
{
  return "CSaveGamePanel";
}

//------------------------------------------------------------------------------
// Address: 0x101D03E0
// Name: public: void CSaveGamePanel::SetSaveGameInfo(struct SaveGameDescription_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGamePanel::SetSaveGameInfo(CSaveGamePanel *this, SaveGameDescription_t *save)
{
  char *v3; // eax
  char tga[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: tga, pSrc: save->szFileName, maxLen: 260);
  strstr(str1: (unsigned __int8 *)tga, str2: ".sav");
  if ( v3 != nullptr )
    strcpy(v3, ".tga");
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tga, a3: nullptr) )
  {
    CTGAImagePanel::SetTGAFilename(this: this->m_pSaveGameImage, filename: tga);
  }
  else
  {
    this->m_pSaveGameImage->SetVisible(this: this->m_pSaveGameImage, a2: false);
    this->m_pAutoSaveImage->SetVisible(this: this->m_pAutoSaveImage, a2: true);
    this->m_pAutoSaveImage->SetImage(this: this->m_pAutoSaveImage, a2: "resource\\autosave");
  }
  this->m_pChapterLabel->SetText(this: this->m_pChapterLabel, a2: save->szComment);
  this->SetControlString_2(this, a2: "TypeLabel", a3: save->szType);
  this->SetControlString_2(this, a2: "ElapsedTimeLabel", a3: save->szElapsedTime);
  this->SetControlString_2(this, a2: "FileTimeLabel", a3: save->szFileTime);
}

//------------------------------------------------------------------------------
// Address: 0x101D0500
// Name: public: static int CBaseSaveGameDialog::SaveGameSortFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CBaseSaveGameDialog::SaveGameSortFunc(const void *lhs, const void *rhs)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx

  v2 = *((_DWORD *)lhs + 108);
  v3 = *((_DWORD *)rhs + 108);
  if ( v2 < v3 )
    return 1;
  if ( v2 <= v3 )
    return strcmp((const char *)lhs + 64, (const char *)rhs + 64);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101D0560
// Name: int SaveReadNameAndComment(void __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SaveReadNameAndComment(void *f, char *name, char *comment)
{
  __int16 *v4; // esi
  char **v5; // ebx
  int v6; // eax
  int v7; // edi
  int v8; // eax
  const char *v9; // esi
  const char *v10; // ebx
  int v11; // edi
  const char *v12; // esi
  char *pSaveData; // [esp+4h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-18h]
  int tokenSize; // [esp+Ch] [ebp-14h] BYREF
  int tag; // [esp+10h] [ebp-10h] BYREF
  char **pTokenList; // [esp+14h] [ebp-Ch]
  int tokenCount; // [esp+18h] [ebp-8h] BYREF
  int size; // [esp+1Ch] [ebp-4h] BYREF

  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &tag, a3: 4, a4: f);
  if ( tag != 1447121738 )
    return false;
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &tag, a3: 4, a4: f);
  if ( tag != 116 )
    return false;
  *name = 0;
  *comment = 0;
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &size, a3: 4, a4: f);
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &tokenCount, a3: 4, a4: f);
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &tokenSize, a3: 4, a4: f);
  size += tokenSize;
  if ( (unsigned int)tokenCount > 0x2000000 || (unsigned int)tokenSize > 0x2000000 )
    return false;
  pSaveData = (char *)MemAlloc_Alloc(nSize: size);
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: pSaveData, a3: size, a4: f);
  v4 = (__int16 *)pSaveData;
  if ( tokenSize <= 0 )
  {
    pTokenList = nullptr;
    v5 = nullptr;
  }
  else
  {
    v5 = (char **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)tokenCount >> 30 != 0 ? -1 : 4 * tokenCount);
    v6 = 0;
    for ( pTokenList = v5; v6 < tokenCount; ++v6 )
    {
      v5[v6] = *(_BYTE *)v4 != 0 ? (char *)v4 : nullptr;
      v4 = (__int16 *)((char *)v4 + strlen((const char *)v4) + 1);
    }
  }
  v7 = *v4;
  if ( _V_stricmp(s1: v5[v4[1]], s2: "GameHeader") != 0 )
  {
    C_BaseEntity::operator delete(pMem: pSaveData);
    return false;
  }
  v8 = *((_DWORD *)v4 + 1);
  v9 = (char *)v4 + v7 + 4;
  if ( v8 > 0 )
  {
    for ( i = v8; i != 0; --i )
    {
      v10 = v5[*((__int16 *)v9 + 1)];
      v11 = *(__int16 *)v9;
      v12 = v9 + 4;
      if ( _V_stricmp(s1: v10, s2: "comment") != 0 )
      {
        if ( _V_stricmp(s1: v10, s2: "mapName") == 0 )
          V_strncpy(pDest: name, pSrc: v12, maxLen: v11);
      }
      else
      {
        V_strncpy(pDest: comment, pSrc: v12, maxLen: v11);
      }
      v5 = pTokenList;
      v9 = &v12[v11];
    }
  }
  C_BaseEntity::operator delete(pMem: v5);
  C_BaseEntity::operator delete(pMem: pSaveData);
  return strlen(name) != 0 && strlen(comment) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D0780
// Name: protected: void CBaseSaveGameDialog::DeleteSaveGame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseSaveGameDialog::DeleteSaveGame(CBaseSaveGameDialog *this, char *fileName)
{
  char *v2; // eax
  char tga[260]; // [esp+4h] [ebp-104h] BYREF

  if ( fileName != nullptr && *fileName != 0 )
  {
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: fileName, a3: "MOD");
    V_strncpy(pDest: tga, pSrc: fileName, maxLen: 260);
    strstr(str1: (unsigned __int8 *)tga, str2: ".sav");
    if ( v2 != nullptr )
      strcpy(v2, ".tga");
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: tga, a3: "MOD");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D0810
// Name: private: virtual void CBaseSaveGameDialog::OnPanelSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseSaveGameDialog::OnPanelSelected(CBaseSaveGameDialog *this)
{
  this->SetControlEnabled(this, a2: "loadsave", a3: true);
  this->SetControlEnabled(this, a2: "delete", a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x101D0840
// Name: protected: int CBaseSaveGameDialog::GetSelectedItemSaveIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseSaveGameDialog::GetSelectedItemSaveIndex(CBaseSaveGameDialog *this)
{
  vgui::Panel *SelectedPanel; // eax
  _DWORD *v3; // edx
  int m_Size; // ecx
  int result; // eax
  int v6; // edx

  SelectedPanel = vgui::PanelListPanel::GetSelectedPanel(this: this->m_pGameList);
  v3 = __RTDynamicCast(
         inptr: SelectedPanel,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CSaveGamePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 == nullptr )
    return -1;
  m_Size = this->m_SaveGames.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  v6 = v3[107];
  while ( result != v6 )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D0890
// Name: protected: bool CBaseSaveGameDialog::ParseSaveData(char const __near *,char const __near *,struct SaveGameDescription_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseSaveGameDialog::ParseSaveData(
        CBaseSaveGameDialog *this,
        char *pszFileName,
        char *pszShortName,
        SaveGameDescription_t *save)
{
  void *v4; // eax
  void *v5; // edi
  BOOL NameAndComment; // ebx
  int v8; // kr00_4
  int v9; // edi
  int v10; // eax
  const char *v11; // ecx
  int i; // eax
  char *v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // edi
  _BYTE *v17; // eax
  char szMapName[32]; // [esp+4h] [ebp-B0h] BYREF
  char szComment[80]; // [esp+24h] [ebp-90h] BYREF
  char szFileTime[32]; // [esp+74h] [ebp-40h] BYREF
  char szElapsedTime[32]; // [esp+94h] [ebp-20h] BYREF

  if ( pszFileName == nullptr || pszShortName == nullptr )
    return 0;
  V_strncpy(pDest: save->szShortName, pSrc: pszShortName, maxLen: 64);
  V_strncpy(pDest: save->szFileName, pSrc: pszFileName, maxLen: 128);
  v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pszFileName, a3: "rb", a4: "MOD");
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  NameAndComment = SaveReadNameAndComment(f: v4, name: szMapName, comment: szComment);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  if ( !NameAndComment )
    return 0;
  V_strncpy(pDest: save->szMapName, pSrc: szMapName, maxLen: 32);
  v8 = strlen(szComment);
  V_strncpy(pDest: szElapsedTime, pSrc: "??", maxLen: 32);
  if ( v8 >= 6 )
  {
    V_strncpy(pDest: szElapsedTime, pSrc: &szMapName[v8 + 26], maxLen: 7);
    szElapsedTime[6] = 0;
    v9 = atoi(nptr: szElapsedTime);
    v10 = atoi(nptr: &szElapsedTime[4]);
    if ( v9 != 0 )
    {
      v11 = "minutes";
      if ( v9 <= 1 )
        v11 = "minute";
      V_snprintf(pDest: szElapsedTime, maxLen: 0x20u, pFormat: "%d %s %d seconds", v9, v11, v10);
    }
    else
    {
      V_snprintf(pDest: szElapsedTime, maxLen: 0x20u, pFormat: "%d seconds", v10);
    }
    szComment[v8 - 6] = 0;
    for ( i = v8 - 7; i >= 1; szComment[i--] = 0 )
    {
      if ( szComment[i] != 32 )
        break;
    }
  }
  v13 = (char *)prType;
  strstr(str1: (unsigned __int8 *)pszFileName, str2: "quick");
  if ( v14 != 0 )
  {
    v13 = "#GameUI_QuickSave";
  }
  else
  {
    strstr(str1: (unsigned __int8 *)pszFileName, str2: "autosave");
    if ( v15 != 0 )
      v13 = "#GameUI_AutoSave";
  }
  V_strncpy(pDest: save->szType, pSrc: v13, maxLen: 64);
  V_strncpy(pDest: save->szComment, pSrc: szComment, maxLen: 80);
  V_strncpy(pDest: save->szElapsedTime, pSrc: szElapsedTime, maxLen: 32);
  v16 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pszFileName, a3: nullptr);
  g_pFullFileSystem->FileTimeToString(this: g_pFullFileSystem, a2: szFileTime, a3: 32, a4: v16);
  strstr(str1: (unsigned __int8 *)szFileTime, str2: "\n");
  if ( v17 != nullptr )
    *v17 = 0;
  V_strncpy(pDest: save->szFileTime, pSrc: szFileTime, maxLen: 32);
  save->iTimestamp = v16;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D0C20
// Name: public: static void CBaseSaveGameDialog::PanelMessageFunc_OnPanelSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseSaveGameDialog::PanelMessageFunc_OnPanelSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseSaveGameDialog::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded )
  {
    `CBaseSaveGameDialog::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseSaveGameDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PanelSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D0CB0
// Name: public: static void CSaveGamePanel::PanelMessageFunc_OnPanelSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSaveGamePanel::PanelMessageFunc_OnPanelSelected::InitVar(int a1@<ebp>)
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
  if ( !`CSaveGamePanel::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded )
  {
    `CSaveGamePanel::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSaveGamePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSaveGamePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PanelSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D0D50
// Name: public: CSaveGamePanel::CSaveGamePanel(class vgui::PanelListPanel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSaveGamePanel *__thiscall CSaveGamePanel::CSaveGamePanel(
        CSaveGamePanel *this,
        vgui::PanelListPanel *parent,
        const char *name,
        int saveGameListItemID)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  int v8; // edx
  vgui::PanelListPanel *v9; // eax
  CTGAImagePanel *v10; // eax
  CTGAImagePanel *v11; // eax
  vgui::ImagePanel *v12; // eax
  vgui::ImagePanel *v13; // eax
  vgui::ImagePanel *v14; // eax
  vgui::ImagePanel *v15; // eax
  vgui::Label *v16; // eax
  vgui::Label *v17; // eax
  vgui::Label *v18; // eax
  vgui::Label *v19; // eax
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label *v22; // eax
  vgui::Label *v23; // eax
  CMouseMessageForwardingPanel *v24; // eax
  CMouseMessageForwardingPanel *v25; // eax

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CSaveGamePanel_vtbl *)&CSaveGamePanel::`vftable';
  if ( `CSaveGamePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveGamePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSaveGamePanel");
    v5->pfnClassName = CSaveGamePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CSaveGamePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveGamePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSaveGamePanel");
    v6->pfnClassName = CSaveGamePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CSaveGamePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveGamePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGamePanel");
    v7->pfnClassName = CSaveGamePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CSaveGamePanel::PanelMessageFunc_OnPanelSelected::InitVar();
  v8 = saveGameListItemID;
  v9 = parent;
  this->m_TextColor = 0;
  this->m_FillColor = 0;
  this->m_SelectedColor = 0;
  this->m_iSaveGameListItemID = v8;
  this->m_pParent = v9;
  v10 = (CTGAImagePanel *)MemAlloc_Alloc(nSize: 0x184u);
  if ( v10 != nullptr )
    v11 = CTGAImagePanel::CTGAImagePanel(this: v10, parent: this, name: "SaveGameImage");
  else
    v11 = nullptr;
  this->m_pSaveGameImage = v11;
  v12 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v12 != nullptr )
    v13 = vgui::ImagePanel::ImagePanel(this: v12, parent: this, name: "AutoSaveImage");
  else
    v13 = nullptr;
  this->m_pAutoSaveImage = v13;
  v14 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v14 != nullptr )
    v15 = vgui::ImagePanel::ImagePanel(this: v14, parent: this, name: "SaveGameScreenshotBackground");
  else
    v15 = nullptr;
  this->m_pSaveGameScreenshotBackground = v15;
  v16 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v16 != nullptr )
    v17 = vgui::Label::Label(this: v16, parent: this, panelName: "ChapterLabel", text: prType);
  else
    v17 = nullptr;
  this->m_pChapterLabel = v17;
  v18 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v18 != nullptr )
    v19 = vgui::Label::Label(this: v18, parent: this, panelName: "TypeLabel", text: prType);
  else
    v19 = nullptr;
  this->m_pTypeLabel = v19;
  v20 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v20 != nullptr )
    v21 = vgui::Label::Label(this: v20, parent: this, panelName: "ElapsedTimeLabel", text: prType);
  else
    v21 = nullptr;
  this->m_pElapsedTimeLabel = v21;
  v22 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v22 != nullptr )
    v23 = vgui::Label::Label(this: v22, parent: this, panelName: "FileTimeLabel", text: prType);
  else
    v23 = nullptr;
  this->m_pFileTimeLabel = v23;
  v24 = (CMouseMessageForwardingPanel *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v24 != nullptr )
    v25 = CMouseMessageForwardingPanel::CMouseMessageForwardingPanel(this: v24, parent: this, name: nullptr);
  else
    v25 = nullptr;
  vgui::Panel::SetZPos(this: v25, z: 2);
  vgui::Panel::SetSize(this, wide: 200, tall: 140);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/SaveGamePanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  this->m_FillColor = *vgui::ImagePanel::GetFillColor(
                         this: this->m_pSaveGameScreenshotBackground,
                         result: (Color *)&parent);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D0FD0
// Name: public: virtual void CSaveGamePanel::OnPanelSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGamePanel::OnPanelSelected(CSaveGamePanel *this, int state)
{
  Color m_SelectedColor; // edx
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  CSaveGamePanel_vtbl *v6; // edi
  int v7; // eax

  if ( state != 0 )
  {
    vgui::ProgressBar::SetBarInset(
      this: (vgui::ProgressBar *)this->m_pSaveGameScreenshotBackground,
      pixels: *(_DWORD *)&this->m_SelectedColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterLabel->SetFgColor)(
      a1: this->m_pChapterLabel,
      a2: *(_DWORD *)&this->m_SelectedColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pTypeLabel->SetFgColor)(
      a1: this->m_pTypeLabel,
      a2: *(_DWORD *)&this->m_SelectedColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pElapsedTimeLabel->SetFgColor)(
      a1: this->m_pElapsedTimeLabel,
      a2: *(_DWORD *)&this->m_SelectedColor);
    m_SelectedColor = this->m_SelectedColor;
  }
  else
  {
    vgui::ProgressBar::SetBarInset(
      this: (vgui::ProgressBar *)this->m_pSaveGameScreenshotBackground,
      pixels: *(_DWORD *)&this->m_FillColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterLabel->SetFgColor)(
      a1: this->m_pChapterLabel,
      a2: *(_DWORD *)&this->m_TextColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pTypeLabel->SetFgColor)(
      a1: this->m_pTypeLabel,
      a2: *(_DWORD *)&this->m_TextColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pElapsedTimeLabel->SetFgColor)(
      a1: this->m_pElapsedTimeLabel,
      a2: *(_DWORD *)&this->m_TextColor);
    m_SelectedColor = this->m_TextColor;
  }
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pFileTimeLabel->SetFgColor)(
    a1: this->m_pFileTimeLabel,
    a2: m_SelectedColor);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "PanelSelected");
  else
    v5 = nullptr;
  v6 = this->__vftable;
  v7 = ((int (__thiscall *)(vgui::PanelListPanel *, KeyValues *, _DWORD))this->m_pParent->GetVParent)(
         a1: this->m_pParent,
         a2: v5,
         a3: 0);
  ((void (__thiscall *)(CSaveGamePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101D1110
// Name: public: virtual void CSaveGamePanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGamePanel::OnMouseDoublePressed(CSaveGamePanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  CSaveGamePanel_vtbl *v5; // edi
  int v6; // eax

  this->OnMousePressed(this, a2: code);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "command", firstValue: "loadsave");
  else
    v4 = nullptr;
  v5 = this->__vftable;
  v6 = ((int (__thiscall *)(vgui::PanelListPanel *, KeyValues *, _DWORD))this->m_pParent->GetParent)(
         a1: this->m_pParent,
         a2: v4,
         a3: 0);
  ((void (__thiscall *)(CSaveGamePanel *, int))v5->PostMessage)(a1: this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101D1180
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveGamePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveGamePanel::GetMessageMap(CSaveGamePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveGamePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveGamePanel::GetMessageMap'::`2'::s_pMap;
  `CSaveGamePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSaveGamePanel");
  `CSaveGamePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D11B0
// Name: public: virtual struct PanelAnimationMap __near * CSaveGamePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveGamePanel::GetAnimMap(CSaveGamePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveGamePanel");
}

//------------------------------------------------------------------------------
// Address: 0x101D11C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveGamePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveGamePanel::GetKBMap(CSaveGamePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveGamePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveGamePanel::GetKBMap'::`2'::s_pMap;
  `CSaveGamePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGamePanel");
  `CSaveGamePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D11F0
// Name: public: virtual void CSaveGamePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGamePanel::ApplySchemeSettings(CSaveGamePanel *this, int pScheme)
{
  vgui::IScheme *v2; // esi
  Color v4; // ecx

  v2 = (vgui::IScheme *)pScheme;
  v4 = *(Color *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)pScheme + 20))(
                   a1: pScheme,
                   a2: &pScheme,
                   a3: "NewGame.TextColor",
                   a4: -1);
  pScheme = -1;
  this->m_TextColor = v4;
  this->m_SelectedColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v2->GetColor)(
                                      a1: v2,
                                      a2: &pScheme,
                                      a3: "NewGame.SelectionColor",
                                      a4: -1);
  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)v2);
}

//------------------------------------------------------------------------------
// Address: 0x101D1260
// Name: protected: void CBaseSaveGameDialog::ScanSavedGames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseSaveGameDialog::ScanSavedGames(CBaseSaveGameDialog *this)
{
  int v2; // ebx
  char *i; // edi
  CSaveGamePanel *v4; // eax
  CSaveGamePanel *v5; // edi
  vgui::Label *v6; // eax
  vgui::Label *v7; // edi
  SaveGameDescription_t save; // [esp+Ch] [ebp-3C8h] BYREF
  char szDirectory[260]; // [esp+1C4h] [ebp-210h] BYREF
  char szFileName[260]; // [esp+2C8h] [ebp-10Ch] BYREF
  int v11; // [esp+3CCh] [ebp-8h]
  int handle; // [esp+3D0h] [ebp-4h] BYREF

  V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "save/*.sav");
  this->m_pGameList->DeleteAllItems(this: this->m_pGameList);
  v2 = 0;
  this->m_SaveGames.m_Size = 0;
  for ( i = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szDirectory, a3: &handle);
        i != nullptr;
        i = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: handle) )
  {
    if ( V_strnicmp(s1: i, s2: "HLSave", n: 6) != 0 )
    {
      V_snprintf(pDest: szFileName, maxLen: 0x104u, pFormat: "save/%s", i);
      if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD")
        && CBaseSaveGameDialog::ParseSaveData(this, pszFileName: szFileName, pszShortName: i, &save) != 0 )
      {
        CUtlVector<SaveGameDescription_t,CUtlMemory<SaveGameDescription_t,int>>::InsertBefore(
          this: &this->m_SaveGames,
          elem: this->m_SaveGames.m_Size,
          src: &save);
      }
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: handle);
  this->OnScanningSaveGames(this);
  qsort(
    base: this->m_SaveGames.m_Memory.m_pMemory,
    num: this->m_SaveGames.m_Size,
    width: 0x1B8u,
    comp: CBaseSaveGameDialog::SaveGameSortFunc);
  if ( this->m_SaveGames.m_Size > 0 )
  {
    v11 = 0;
    do
    {
      if ( v11 >= 56320 )
        break;
      v4 = (CSaveGamePanel *)MemAlloc_Alloc(nSize: 0x1B0u);
      v5 = v4 != nullptr
         ? CSaveGamePanel::CSaveGamePanel(
             this: v4,
             parent: this->m_pGameList,
             name: "SaveGamePanel",
             saveGameListItemID: v2)
         : nullptr;
      CSaveGamePanel::SetSaveGameInfo(this: v5, save: &this->m_SaveGames.m_Memory.m_pMemory[v11 / 0x1B8u]);
      this->m_pGameList->AddItem(this: this->m_pGameList, a2: nullptr, a3: v5);
      v11 += 440;
      ++v2;
    }
    while ( v2 < this->m_SaveGames.m_Size );
  }
  if ( this->m_SaveGames.m_Size == 0 )
  {
    v6 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v6 != nullptr )
      v7 = vgui::Label::Label(
             this: v6,
             parent: this->m_pGameList,
             panelName: "NoSavesLabel",
             text: "#GameUI_NoSaveGamesToDisplay");
    else
      v7 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v7);
    v7->SetTextColorState(this: v7, a2: CS_DULL);
    this->m_pGameList->AddItem(this: this->m_pGameList, a2: nullptr, a3: v7);
  }
  this->SetControlEnabled(this, a2: "loadsave", a3: false);
  this->SetControlEnabled(this, a2: "delete", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101D14B0
// Name: public: CBaseSaveGameDialog::CBaseSaveGameDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseSaveGameDialog *__thiscall CBaseSaveGameDialog::CBaseSaveGameDialog(
        CBaseSaveGameDialog *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PanelListPanel *v7; // eax
  vgui::PanelListPanel *v8; // eax
  vgui::Button *v9; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBaseSaveGameDialog_vtbl *)&CBaseSaveGameDialog::`vftable';
  if ( `CBaseSaveGameDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseSaveGameDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseSaveGameDialog");
    v4->pfnClassName = CBaseSaveGameDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBaseSaveGameDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseSaveGameDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseSaveGameDialog");
    v5->pfnClassName = CBaseSaveGameDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBaseSaveGameDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseSaveGameDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseSaveGameDialog");
    v6->pfnClassName = CBaseSaveGameDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_SaveGames.m_Memory.m_pMemory = nullptr;
  this->m_SaveGames.m_Memory.m_nAllocationCount = 0;
  this->m_SaveGames.m_Memory.m_nGrowSize = 0;
  this->m_SaveGames.m_Size = 0;
  this->m_SaveGames.m_pElements = nullptr;
  CBaseSaveGameDialog::PanelMessageFunc_OnPanelSelected::InitVar();
  v7 = (vgui::PanelListPanel *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v7 != nullptr )
    v8 = vgui::PanelListPanel::PanelListPanel(this: v7, parent: this, panelName: "listpanel_loadgame");
  else
    v8 = nullptr;
  this->m_pGameList = v8;
  vgui::PanelListPanel::SetFirstColumnWidth(this: v8, width: 0);
  CBaseSaveGameDialog::ScanSavedGames(this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    vgui::Button::Button(
      this: v9,
      parent: this,
      panelName: "loadsave",
      text: prType,
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
  vgui::EditablePanel::SetControlEnabled(this, controlName: "loadsave", enabled: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D1600
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseSaveGameDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseSaveGameDialog::GetMessageMap(CBaseSaveGameDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseSaveGameDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseSaveGameDialog::GetMessageMap'::`2'::s_pMap;
  `CBaseSaveGameDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseSaveGameDialog");
  `CBaseSaveGameDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1630
// Name: public: virtual struct PanelAnimationMap __near * CBaseSaveGameDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseSaveGameDialog::GetAnimMap(CBaseSaveGameDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseSaveGameDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101D1640
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseSaveGameDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseSaveGameDialog::GetKBMap(CBaseSaveGameDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseSaveGameDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseSaveGameDialog::GetKBMap'::`2'::s_pMap;
  `CBaseSaveGameDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseSaveGameDialog");
  `CBaseSaveGameDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423B80
// Name: BaseSaveGameDialogPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *BaseSaveGameDialogPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  BaseSaveGameDialogPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &BaseSaveGameDialogPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423BA0
// Name: _dynamic_initializer_for__g_CCvarSlider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CCvarSlider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CCvarSlider_Helper,
           className: "CCvarSlider",
           func: (vgui::Panel *(__cdecl *)())Create_CCvarSlider);
}

//------------------------------------------------------------------------------
// Address: 0x10423BC0
// Name: _dynamic_initializer_for__g_CCvarToggleCheckButton_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CCvarToggleCheckButton_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CCvarToggleCheckButton_Helper,
           className: "CCvarToggleCheckButton",
           func: (vgui::Panel *(__cdecl *)())CvarToggleCheckButton_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10423BE0
// Name: _dynamic_initializer_for__g_GameConsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameConsole__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_GameConsole__);
}

//------------------------------------------------------------------------------
// Address: 0x10423BF0
// Name: _dynamic_initializer_for____g_CreateCGameConsoleIGameConsole_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameConsoleIGameConsole_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameConsoleIGameConsole_reg,
           fn: (void *(__cdecl *)())GameConsole,
           pName: "GameConsole004");
}

//------------------------------------------------------------------------------
// Address: 0x10423C10
// Name: _dynamic_initializer_for__condump_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__condump_command__()
{
  ConCommand::ConCommand(
    this: &condump_command,
    pName: "condump",
    callback: condump,
    pHelpString: "dump the text currently in the console to condumpXX.log",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__condump_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10423C40
// Name: _dynamic_initializer_for__g_GameUI___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameUI___0()
{
  g_pGameUI = &g_GameUI;
  *((_BYTE *)&g_GameUI + 8) &= 0xE0u;
  return atexit(func: dynamic_atexit_destructor_for__g_GameUI___0);
}

//------------------------------------------------------------------------------
// Address: 0x10423C70
// Name: _dynamic_initializer_for____g_CreateCGameUIIGameUI_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameUIIGameUI_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameUIIGameUI_reg,
           fn: (void *(__cdecl *)())GameUI,
           pName: "GameUI011");
}

//------------------------------------------------------------------------------
// Address: 0x10423C90
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  ConVar::ConVar(this: &s_EmptyConVar, pName: prType, pDefaultValue: "0", flags: 0);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyGameUIConVar_vtbl *)&CEmptyGameUIConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&CEmptyGameUIConVar::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x10423CD0
// Name: _dynamic_initializer_for__ui_loading_tip_refresh__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ui_loading_tip_refresh__()
{
  ConVar::ConVar(this: &ui_loading_tip_refresh, pName: "ui_loading_tip_refresh", pDefaultValue: "5", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__ui_loading_tip_refresh__);
}

//------------------------------------------------------------------------------
// Address: 0x10423D00
// Name: _dynamic_initializer_for__ui_loading_tip_f1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ui_loading_tip_f1__()
{
  ConVar::ConVar(this: &ui_loading_tip_f1, pName: "ui_loading_tip_f1", pDefaultValue: "0.05", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__ui_loading_tip_f1__);
}

//------------------------------------------------------------------------------
// Address: 0x10423D30
// Name: _dynamic_initializer_for__ui_loading_tip_f2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ui_loading_tip_f2__()
{
  ConVar::ConVar(this: &ui_loading_tip_f2, pName: "ui_loading_tip_f2", pDefaultValue: "0.40", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__ui_loading_tip_f2__);
}
