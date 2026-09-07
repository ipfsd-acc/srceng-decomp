// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/toolfilemenubutton.cpp
// Functions: 19
// ============================================================

#include "tools\toolutils\toolfilemenubutton.h"

//------------------------------------------------------------------------------
// Address: 0x102C2020
// Name: public: static char const __near * CToolFileMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToolFileMenuButton::GetPanelClassName()
{
  return "CToolFileMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C2030
// Name: private: virtual void CToolFileMenuButton::OnPerforceAdd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuButton::OnPerforceAdd(CToolFileMenuButton *this)
{
  CPerforceFileListFrame *v2; // esi
  vgui::Panel *v3; // eax
  CPerforceFileListFrame *v4; // esi
  char pPerforceFile[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_pFileMenuCallback->GetPerforceFileName(this: this->m_pFileMenuCallback, a2: pPerforceFile, a3: 260) )
  {
    v2 = (CPerforceFileListFrame *)operator new(nSize: 0x26Cu);
    if ( v2 != nullptr )
    {
      v3 = this->m_pFileMenuCallback->GetRootPanel(this: this->m_pFileMenuCallback);
      v4 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v2,
             pParent: v3,
             pTitle: "Add Movie File to Perforce?",
             pColumnHeader: "Movie File",
             action: PERFORCE_ACTION_FILE_ADD);
    }
    else
    {
      v4 = nullptr;
    }
    CPerforceFileListFrame::AddFile(this: v4, pFullPath: pPerforceFile);
    CPerforceFileListFrame::DoModal(this: v4, pContextKeys: nullptr, pMessage: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C20C0
// Name: private: virtual void CToolFileMenuButton::OnPerforceOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuButton::OnPerforceOpen(CToolFileMenuButton *this)
{
  CPerforceFileListFrame *v2; // esi
  vgui::Panel *v3; // eax
  CPerforceFileListFrame *v4; // esi
  char pPerforceFile[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_pFileMenuCallback->GetPerforceFileName(this: this->m_pFileMenuCallback, a2: pPerforceFile, a3: 260) )
  {
    v2 = (CPerforceFileListFrame *)operator new(nSize: 0x26Cu);
    if ( v2 != nullptr )
    {
      v3 = this->m_pFileMenuCallback->GetRootPanel(this: this->m_pFileMenuCallback);
      v4 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v2,
             pParent: v3,
             pTitle: "Check Out Movie File from Perforce?",
             pColumnHeader: "Movie File",
             action: PERFORCE_ACTION_FILE_EDIT);
    }
    else
    {
      v4 = nullptr;
    }
    CPerforceFileListFrame::AddFile(this: v4, pFullPath: pPerforceFile);
    CPerforceFileListFrame::DoModal(this: v4, pContextKeys: nullptr, pMessage: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C2150
// Name: private: virtual void CToolFileMenuButton::OnPerforceRevert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuButton::OnPerforceRevert(CToolFileMenuButton *this)
{
  CPerforceFileListFrame *v2; // esi
  vgui::Panel *v3; // eax
  CPerforceFileListFrame *v4; // esi
  char pPerforceFile[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_pFileMenuCallback->GetPerforceFileName(this: this->m_pFileMenuCallback, a2: pPerforceFile, a3: 260) )
  {
    v2 = (CPerforceFileListFrame *)operator new(nSize: 0x26Cu);
    if ( v2 != nullptr )
    {
      v3 = this->m_pFileMenuCallback->GetRootPanel(this: this->m_pFileMenuCallback);
      v4 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v2,
             pParent: v3,
             pTitle: "Revert Movie File Changes from Perforce?",
             pColumnHeader: "Movie File",
             action: PERFORCE_ACTION_FILE_REVERT);
    }
    else
    {
      v4 = nullptr;
    }
    CPerforceFileListFrame::AddFile(this: v4, pFullPath: pPerforceFile);
    CPerforceFileListFrame::DoModal(this: v4, pContextKeys: nullptr, pMessage: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C21E0
// Name: private: virtual void CToolFileMenuButton::OnPerforceSubmit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuButton::OnPerforceSubmit(CToolFileMenuButton *this)
{
  CPerforceFileListFrame *v2; // esi
  vgui::Panel *v3; // eax
  CPerforceFileListFrame *v4; // esi
  char pPerforceFile[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_pFileMenuCallback->GetPerforceFileName(this: this->m_pFileMenuCallback, a2: pPerforceFile, a3: 260) )
  {
    v2 = (CPerforceFileListFrame *)operator new(nSize: 0x26Cu);
    if ( v2 != nullptr )
    {
      v3 = this->m_pFileMenuCallback->GetRootPanel(this: this->m_pFileMenuCallback);
      v4 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v2,
             pParent: v3,
             pTitle: "Submit Movie File Changes to Perforce?",
             pColumnHeader: "Movie File",
             action: PERFORCE_ACTION_FILE_SUBMIT);
    }
    else
    {
      v4 = nullptr;
    }
    CPerforceFileListFrame::AddFile(this: v4, pFullPath: pPerforceFile);
    CPerforceFileListFrame::DoModal(this: v4, pContextKeys: nullptr, pMessage: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C2270
// Name: private: virtual void CToolFileMenuButton::OnPerforceP4Win(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuButton::OnPerforceP4Win(CToolFileMenuButton *this)
{
  char pPerforceFile[260]; // [esp+0h] [ebp-104h] BYREF

  if ( this->m_pFileMenuCallback->GetPerforceFileName(this: this->m_pFileMenuCallback, a2: pPerforceFile, a3: 260)
    && p4->IsFileInPerforce(this: p4, a2: pPerforceFile) )
  {
    p4->OpenFileInP4Win(this: p4, a2: pPerforceFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C2320
// Name: private: virtual void CToolFileMenuButton::OnPerforceListOpenFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuButton::OnPerforceListOpenFiles(CToolFileMenuButton *this)
{
  COperationFileListFrame *v1; // ebx
  COperationFileListFrame *v3; // esi
  vgui::Panel *v4; // eax
  P4File_t *m_pMemory; // ecx
  int v6; // edi
  const char *v7; // esi
  const char *v8; // eax
  P4File_t *v9; // eax
  int v10; // [esp-4h] [ebp-28h]
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > openedFiles; // [esp+Ch] [ebp-18h] BYREF
  int i; // [esp+20h] [ebp-4h]

  v1 = nullptr;
  memset(&openedFiles, 0, sizeof(openedFiles));
  p4->GetOpenedFileListInPath(this: p4, a2: "GAME", a3: &openedFiles);
  v3 = (COperationFileListFrame *)operator new(nSize: 0x240u);
  if ( v3 != nullptr )
  {
    v4 = this->m_pFileMenuCallback->GetRootPanel(this: this->m_pFileMenuCallback);
    v1 = COperationFileListFrame::COperationFileListFrame(
           this: v3,
           pParent: v4,
           pTitle: "Opened Files In Perforce",
           pColumnHeader: "File Name",
           bShowDescription: false,
           bShowOkOnly: true,
           nDialogID: 1);
  }
  if ( openedFiles.m_Size > 0 )
  {
    m_pMemory = openedFiles.m_Memory.m_pMemory;
    v6 = 0;
    for ( i = openedFiles.m_Size; i != 0; --i )
    {
      switch ( m_pMemory[v6].m_eOpenState )
      {
        case P4FILE_OPENED_FOR_ADD:
          v7 = "Add";
          goto LABEL_10;
        case P4FILE_OPENED_FOR_EDIT:
          v7 = "Edit";
          goto LABEL_10;
        case P4FILE_OPENED_FOR_DELETE:
          v7 = "Delete";
          goto LABEL_10;
        case P4FILE_OPENED_FOR_INTEGRATE:
          v7 = "Integrate";
LABEL_10:
          HIWORD(v10) = HIWORD(m_pMemory);
          LOWORD(v10) = m_pMemory[v6].m_sLocalFile.m_Id;
          v8 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v10);
          COperationFileListFrame::AddOperation(this: v1, pOperation: v7, pFileName: v8);
          m_pMemory = openedFiles.m_Memory.m_pMemory;
          break;
        default:
          break;
      }
      ++v6;
    }
  }
  COperationFileListFrame::DoModal(this: v1, pContextKeyValues: nullptr, pMessage: nullptr);
  v9 = openedFiles.m_Memory.m_pMemory;
  openedFiles.m_Size = 0;
  if ( openedFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( openedFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: openedFiles.m_Memory.m_pMemory);
      v9 = nullptr;
      openedFiles.m_Memory.m_pMemory = nullptr;
    }
    openedFiles.m_Memory.m_nAllocationCount = 0;
  }
  openedFiles.m_pElements = v9;
  if ( openedFiles.m_Memory.m_nGrowSize >= 0 && v9 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x102C2460
// Name: public: static void CToolFileMenuButton::PanelMessageFunc_OnPerforceAdd::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CToolFileMenuButton::PanelMessageFunc_OnPerforceAdd::InitVar(int a1@<ebp>)
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
  if ( !`CToolFileMenuButton::PanelMessageFunc_OnPerforceAdd::InitVar'::`2'::bAdded )
  {
    `CToolFileMenuButton::PanelMessageFunc_OnPerforceAdd::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPerforceAdd";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C24F0
// Name: public: static void CToolFileMenuButton::PanelMessageFunc_OnPerforceOpen::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CToolFileMenuButton::PanelMessageFunc_OnPerforceOpen::InitVar(int a1@<ebp>)
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
  if ( !`CToolFileMenuButton::PanelMessageFunc_OnPerforceOpen::InitVar'::`2'::bAdded )
  {
    `CToolFileMenuButton::PanelMessageFunc_OnPerforceOpen::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CToolSwitchMenuButton::`vcall'{1228,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPerforceOpen";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C2580
// Name: public: static void CToolFileMenuButton::PanelMessageFunc_OnPerforceRevert::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CToolFileMenuButton::PanelMessageFunc_OnPerforceRevert::InitVar(int a1@<ebp>)
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
  if ( !`CToolFileMenuButton::PanelMessageFunc_OnPerforceRevert::InitVar'::`2'::bAdded )
  {
    `CToolFileMenuButton::PanelMessageFunc_OnPerforceRevert::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CToolFileMenuButton::`vcall'{1232,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPerforceRevert";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C2610
// Name: public: static void CToolFileMenuButton::PanelMessageFunc_OnPerforceSubmit::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CToolFileMenuButton::PanelMessageFunc_OnPerforceSubmit::InitVar(int a1@<ebp>)
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
  if ( !`CToolFileMenuButton::PanelMessageFunc_OnPerforceSubmit::InitVar'::`2'::bAdded )
  {
    `CToolFileMenuButton::PanelMessageFunc_OnPerforceSubmit::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CToolFileMenuButton::`vcall'{1236,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPerforceSubmit";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C26A0
// Name: public: static void CToolFileMenuButton::PanelMessageFunc_OnPerforceP4Win::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CToolFileMenuButton::PanelMessageFunc_OnPerforceP4Win::InitVar(int a1@<ebp>)
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
  if ( !`CToolFileMenuButton::PanelMessageFunc_OnPerforceP4Win::InitVar'::`2'::bAdded )
  {
    `CToolFileMenuButton::PanelMessageFunc_OnPerforceP4Win::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPerforceP4Win";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C2730
// Name: public: static void CToolFileMenuButton::PanelMessageFunc_OnPerforceListOpenFiles::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CToolFileMenuButton::PanelMessageFunc_OnPerforceListOpenFiles::InitVar(int a1@<ebp>)
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
  if ( !`CToolFileMenuButton::PanelMessageFunc_OnPerforceListOpenFiles::InitVar'::`2'::bAdded )
  {
    `CToolFileMenuButton::PanelMessageFunc_OnPerforceListOpenFiles::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CToolFileMenuButton::`vcall'{1244,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPerforceListOpenFiles";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C27C0
// Name: public: virtual void CToolFileMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuButton::OnShowMenu(CToolFileMenuButton *this, vgui::Menu *menu)
{
  char v3; // bl
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // ax
  vgui::Menu *m_pMenu; // ecx
  bool v10; // bl
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char pPerforceFile[260]; // [esp+Ch] [ebp-110h] BYREF
  CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t search; // [esp+110h] [ebp-Ch] BYREF
  bool bFileInPerforce; // [esp+11Bh] [ebp-1h]
  bool bP4Connected_3; // [esp+127h] [ebp+Bh]

  CToolMenuButton::OnShowMenu(this, menu);
  v3 = this->m_pFileMenuCallback->GetFileMenuItemsEnabled(this: this->m_pFileMenuCallback);
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "new";
  v4 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  this->SetItemEnabled(this, a2: v4, a3: v3 & 1);
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "open";
  v5 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  this->SetItemEnabled(this, a2: v5, a3: (v3 & 2) != 0);
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "save";
  v6 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  this->SetItemEnabled(this, a2: v6, a3: (v3 & 4) != 0);
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "saveas";
  v7 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  this->SetItemEnabled(this, a2: v7, a3: (v3 & 8) != 0);
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "close";
  v8 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  this->SetItemEnabled(this, a2: v8, a3: (v3 & 0x10) != 0);
  vgui::Menu::DeleteAllItems(this: this->m_pRecentFiles);
  m_pMenu = this->CToolMenuButton::m_pMenu;
  if ( (v3 & 0x20) != 0 )
  {
    m_pMenu->SetItemEnabled(this: m_pMenu, a2: this->m_nRecentFiles, a3: true);
    this->m_pFileMenuCallback->AddRecentFilesToMenu(this: this->m_pFileMenuCallback, a2: this->m_pRecentFiles);
  }
  else
  {
    m_pMenu->SetItemEnabled(this: m_pMenu, a2: this->m_nRecentFiles, a3: false);
  }
  if ( p4 != nullptr )
  {
    if ( p4->IsConnectedToServer(this: p4, a2: false)
      && this->m_pFileMenuCallback->GetPerforceFileName(this: this->m_pFileMenuCallback, a2: pPerforceFile, a3: 260) )
    {
      v10 = !V_IsAbsolutePath(pStr: pPerforceFile);
      bP4Connected_3 = p4->GetFileState(this: p4, a2: pPerforceFile) != P4FILE_UNOPENED;
      v11 = ((int (__thiscall *)(IP4 *, char *))p4->IsFileInPerforce)(a1: p4, a2: pPerforceFile);
      bFileInPerforce = v11;
      LOBYTE(v11) = !v10 && (_BYTE)v11 == 0 && !bP4Connected_3;
      v12 = ((int (__thiscall *)(vgui::Menu *, int, int))this->m_pPerforce->SetItemEnabled)(
              a1: this->m_pPerforce,
              a2: this->m_nPerforceAdd,
              a3: v11);
      LOBYTE(v12) = !v10 && bFileInPerforce && !bP4Connected_3;
      v13 = ((int (__thiscall *)(vgui::Menu *, int, int))this->m_pPerforce->SetItemEnabled)(
              a1: this->m_pPerforce,
              a2: this->m_nPerforceOpen,
              a3: v12);
      LOBYTE(v13) = !v10 && bP4Connected_3;
      v14 = ((int (__thiscall *)(vgui::Menu *, int, int))this->m_pPerforce->SetItemEnabled)(
              a1: this->m_pPerforce,
              a2: this->m_nPerforceRevert,
              a3: v13);
      LOBYTE(v14) = !v10 && bP4Connected_3;
      v15 = ((int (__thiscall *)(vgui::Menu *, int, int))this->m_pPerforce->SetItemEnabled)(
              a1: this->m_pPerforce,
              a2: this->m_nPerforceSubmit,
              a3: v14);
      if ( !v10 && bFileInPerforce || bP4Connected_3 )
        v15 = 1;
      else
        LOBYTE(v15) = 0;
      this->m_pPerforce->SetItemEnabled(this: this->m_pPerforce, a2: this->m_nPerforceP4Win, a3: v15);
    }
    else
    {
      this->m_pPerforce->SetItemEnabled(this: this->m_pPerforce, a2: this->m_nPerforceAdd, a3: false);
      this->m_pPerforce->SetItemEnabled(this: this->m_pPerforce, a2: this->m_nPerforceOpen, a3: false);
      this->m_pPerforce->SetItemEnabled(this: this->m_pPerforce, a2: this->m_nPerforceRevert, a3: false);
      this->m_pPerforce->SetItemEnabled(this: this->m_pPerforce, a2: this->m_nPerforceSubmit, a3: false);
      this->m_pPerforce->SetItemEnabled(this: this->m_pPerforce, a2: this->m_nPerforceP4Win, a3: false);
    }
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pPerforce->SetItemEnabled)(
      a1: this->m_pPerforce,
      a2: this->m_nPerforceListOpenFiles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C2B60
// Name: public: CToolFileMenuButton::CToolFileMenuButton(class vgui::Panel __near *,char const __near *,char const __near *,class vgui::Panel __near *,class IFileMenuCallbacks __near *)
// Source: json
//------------------------------------------------------------------------------
CToolFileMenuButton *__thiscall CToolFileMenuButton::CToolFileMenuButton(
        CToolFileMenuButton *this,
        vgui::Panel *pParent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionSignalTarget,
        IFileMenuCallbacks *pFileMenuCallback)
{
  vgui::Panel *v6; // edi
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  vgui::Menu *v21; // eax
  vgui::Menu *v22; // eax
  vgui::Menu *m_pMenu; // ecx
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  KeyValues *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  int v32; // eax
  vgui::Menu *m_pPerforce; // ecx
  KeyValues *v34; // eax
  KeyValues *v35; // eax
  KeyValues *v36; // eax
  KeyValues *v37; // eax
  vgui::Menu *v38; // eax
  vgui::Menu *v39; // eax
  vgui::Menu *v40; // ecx
  KeyValues *v41; // eax
  KeyValues *v42; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v6 = pActionSignalTarget;
  CToolMenuButton::CToolMenuButton(this, parent: pParent, panelName, text, actionTarget: pActionSignalTarget);
  this->__vftable = (CToolFileMenuButton_vtbl *)&CToolFileMenuButton::`vftable';
  if ( `CToolFileMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CToolFileMenuButton::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuButton");
    v8->pfnClassName = CToolFileMenuButton::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "CToolMenuButton");
    v6 = pActionSignalTarget;
  }
  if ( `CToolFileMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToolFileMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CToolFileMenuButton");
    v9->pfnClassName = CToolFileMenuButton::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "CToolMenuButton");
    v6 = pActionSignalTarget;
  }
  if ( `CToolFileMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToolFileMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CToolFileMenuButton");
    v10->pfnClassName = CToolFileMenuButton::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuButton");
    v6 = pActionSignalTarget;
  }
  CToolFileMenuButton::PanelMessageFunc_OnPerforceAdd::InitVar(a1: (int)&savedregs);
  CToolFileMenuButton::PanelMessageFunc_OnPerforceOpen::InitVar(a1: (int)&savedregs);
  CToolFileMenuButton::PanelMessageFunc_OnPerforceRevert::InitVar(a1: (int)&savedregs);
  CToolFileMenuButton::PanelMessageFunc_OnPerforceSubmit::InitVar(a1: (int)&savedregs);
  CToolFileMenuButton::PanelMessageFunc_OnPerforceP4Win::InitVar(a1: (int)&savedregs);
  CToolFileMenuButton::PanelMessageFunc_OnPerforceListOpenFiles::InitVar(a1: (int)&savedregs);
  this->m_pFileMenuCallback = pFileMenuCallback;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "OnNew");
  else
    v12 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "new",
    itemText: "#ToolFileNew",
    message: v12,
    target: v6,
    userData: nullptr,
    kbcommandname: "file_new");
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "OnOpen");
  else
    v14 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "open",
    itemText: "#ToolFileOpen",
    message: v14,
    target: v6,
    userData: nullptr,
    kbcommandname: "file_open");
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "OnSave");
  else
    v16 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "save",
    itemText: "#ToolFileSave",
    message: v16,
    target: v6,
    userData: nullptr,
    kbcommandname: "file_save");
  v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v17 != nullptr )
    v18 = KeyValues::KeyValues(this: v17, setName: "OnSaveAs");
  else
    v18 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "saveas",
    itemText: "#ToolFileSaveAs",
    message: v18,
    target: v6,
    userData: nullptr,
    kbcommandname: nullptr);
  v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v19 != nullptr )
    v20 = KeyValues::KeyValues(this: v19, setName: "OnClose");
  else
    v20 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "close",
    itemText: "#ToolFileClose",
    message: v20,
    target: v6,
    userData: nullptr,
    kbcommandname: nullptr);
  CToolMenuButton::AddSeparator(this);
  if ( p4 != nullptr )
  {
    v21 = (vgui::Menu *)operator new(nSize: 0x420u);
    if ( v21 != nullptr )
      v22 = vgui::Menu::Menu(this: v21, parent: this, panelName: "Perforce");
    else
      v22 = nullptr;
    m_pMenu = this->CToolMenuButton::m_pMenu;
    this->m_pPerforce = v22;
    m_pMenu->AddCascadingMenuItem(this: m_pMenu, a2: "#ToolPerforce", a3: this, a4: v22, a5: nullptr);
    v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v24 != nullptr )
      v25 = KeyValues::KeyValues(this: v24, setName: "OnPerforceAdd");
    else
      v25 = nullptr;
    this->m_nPerforceAdd = this->m_pPerforce->AddMenuItem(
                             this: this->m_pPerforce,
                             a2: "perforce_add",
                             a3: "#ToolPerforceAdd",
                             a4: v25,
                             a5: this,
                             a6: nullptr);
    v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v26 != nullptr )
      v27 = KeyValues::KeyValues(this: v26, setName: "OnPerforceOpen");
    else
      v27 = nullptr;
    this->m_nPerforceOpen = this->m_pPerforce->AddMenuItem(
                              this: this->m_pPerforce,
                              a2: "perforce_open",
                              a3: "#ToolPerforceOpen",
                              a4: v27,
                              a5: this,
                              a6: nullptr);
    v28 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v28 != nullptr )
      v29 = KeyValues::KeyValues(this: v28, setName: "OnPerforceRevert");
    else
      v29 = nullptr;
    this->m_nPerforceRevert = this->m_pPerforce->AddMenuItem(
                                this: this->m_pPerforce,
                                a2: "perforce_revert",
                                a3: "#ToolPerforceRevert",
                                a4: v29,
                                a5: this,
                                a6: nullptr);
    v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v30 != nullptr )
      v31 = KeyValues::KeyValues(this: v30, setName: "OnPerforceSubmit");
    else
      v31 = nullptr;
    v32 = this->m_pPerforce->AddMenuItem(
            this: this->m_pPerforce,
            a2: "perforce_submit",
            a3: "#ToolPerforceSubmit",
            a4: v31,
            a5: this,
            a6: nullptr);
    m_pPerforce = this->m_pPerforce;
    this->m_nPerforceSubmit = v32;
    m_pPerforce->AddSeparator(this: m_pPerforce);
    v34 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v34 != nullptr )
      v35 = KeyValues::KeyValues(this: v34, setName: "OnPerforceP4Win");
    else
      v35 = nullptr;
    this->m_nPerforceP4Win = this->m_pPerforce->AddMenuItem(
                               this: this->m_pPerforce,
                               a2: "perforce_p4win",
                               a3: "#ToolPerforceP4Win",
                               a4: v35,
                               a5: this,
                               a6: nullptr);
    v36 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v36 != nullptr )
      v37 = KeyValues::KeyValues(this: v36, setName: "OnPerforceListOpenFiles");
    else
      v37 = nullptr;
    this->m_nPerforceListOpenFiles = this->m_pPerforce->AddMenuItem(
                                       this: this->m_pPerforce,
                                       a2: "perforce_listopenfiles",
                                       a3: "#ToolPerforceListOpenFiles",
                                       a4: v37,
                                       a5: this,
                                       a6: nullptr);
  }
  v38 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v38 != nullptr )
    v39 = vgui::Menu::Menu(this: v38, parent: this, panelName: "RecentFiles");
  else
    v39 = nullptr;
  v40 = this->CToolMenuButton::m_pMenu;
  this->m_pRecentFiles = v39;
  this->m_nRecentFiles = v40->AddCascadingMenuItem(this: v40, a2: "#ToolFileRecent", a3: v6, a4: v39, a5: nullptr);
  CToolMenuButton::AddSeparator(this);
  v41 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v41 != nullptr )
    v42 = KeyValues::KeyValues(this: v41, setName: "OnExit");
  else
    v42 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "exit",
    itemText: "#ToolFileExit",
    message: v42,
    target: v6,
    userData: nullptr,
    kbcommandname: nullptr);
  vgui::MenuButton::SetMenu(this, menu: this->CToolMenuButton::m_pMenu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C3000
// Name: public: virtual struct vgui::PanelMessageMap __near * CToolFileMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToolFileMenuButton::GetMessageMap(CToolFileMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToolFileMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolFileMenuButton::GetMessageMap'::`2'::s_pMap;
  `CToolFileMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuButton");
  `CToolFileMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C3030
// Name: public: virtual struct PanelAnimationMap __near * CToolFileMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToolFileMenuButton::GetAnimMap(CToolFileMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CToolFileMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C3040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToolFileMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToolFileMenuButton::GetKBMap(CToolFileMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToolFileMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolFileMenuButton::GetKBMap'::`2'::s_pMap;
  `CToolFileMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToolFileMenuButton");
  `CToolFileMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C3070
// Name: class CToolMenuButton __near * CreateToolFileMenuButton(class vgui::Panel __near *,char const __near *,char const __near *,class vgui::Panel __near *,class IFileMenuCallbacks __near *)
// Source: json
//------------------------------------------------------------------------------
CToolFileMenuButton *__cdecl CreateToolFileMenuButton(
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionTarget,
        IFileMenuCallbacks *pCallbacks)
{
  CToolFileMenuButton *v5; // eax

  v5 = (CToolFileMenuButton *)operator new(nSize: 0x270u);
  if ( v5 != nullptr )
    return CToolFileMenuButton::CToolFileMenuButton(
             this: v5,
             pParent: parent,
             panelName,
             text,
             pActionSignalTarget: pActionTarget,
             pFileMenuCallback: pCallbacks);
  else
    return nullptr;
}
