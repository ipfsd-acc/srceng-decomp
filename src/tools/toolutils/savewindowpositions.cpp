// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/savewindowpositions.cpp
// Functions: 7
// ============================================================

#include "tools\toolutils\savewindowpositions.h"

//------------------------------------------------------------------------------
// Address: 0x102BECE0
// Name: BufPrint
// Source: json
//------------------------------------------------------------------------------
void __usercall BufPrint(CUtlBuffer *buf@<edi>, int level@<eax>, const char *fmt, ...)
{
  int v4; // esi
  char string[2048]; // [esp+4h] [ebp-800h] BYREF
  va_list ap; // [esp+810h] [ebp+Ch] BYREF

  va_start(ap, fmt);
  _vsnprintf(string, count: 0x7FFu, format: fmt, ap);
  v4 = level - 1;
  for ( string[2047] = 0; v4 >= 0; --v4 )
    CUtlBuffer::Printf(this: buf, pFmt: "    ");
  CUtlBuffer::Printf(this: buf, pFmt: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x102BED40
// Name: private: struct CWindowPositionMgr::LoadInfo_t __near * CWindowPositionMgr::Find(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CWindowPositionMgr::LoadInfo_t *__thiscall CWindowPositionMgr::Find(CWindowPositionMgr *this, vgui::Panel *panel)
{
  int v3; // ebx
  int i; // edi
  CWindowPositionMgr::LoadInfo_t *v5; // esi
  int c; // [esp+0h] [ebp-8h]
  CWindowPositionMgr *v7; // [esp+4h] [ebp-4h]

  v7 = this;
  if ( panel == nullptr )
    return nullptr;
  v3 = 0;
  c = this->m_Panels.m_Size;
  if ( c <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v5 = &this->m_Panels.m_Memory.m_pMemory[i];
    if ( vgui::PHandle::Get(this: &v5->m_hPanel) == panel )
      break;
    if ( ++v3 >= c )
      return nullptr;
    this = v7;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x102BEDB0
// Name: private: struct CWindowPositionMgr::LoadInfo_t __near * CWindowPositionMgr::Find(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWindowPositionMgr::LoadInfo_t *__thiscall CWindowPositionMgr::Find(CWindowPositionMgr *this, const char *panelName)
{
  int v3; // ebx
  int i; // edi
  CWindowPositionMgr::LoadInfo_t *v5; // esi
  char *v6; // eax
  int c; // [esp+0h] [ebp-8h]
  CWindowPositionMgr *v8; // [esp+4h] [ebp-4h]

  v8 = this;
  if ( panelName == nullptr )
    return nullptr;
  v3 = 0;
  c = this->m_Panels.m_Size;
  if ( c <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v5 = &this->m_Panels.m_Memory.m_pMemory[i];
    v6 = CUtlSymbol::String(this: &v5->m_Name);
    if ( _V_stricmp(s1: v6, s2: panelName) == 0 )
      break;
    if ( ++v3 >= c )
      return nullptr;
    this = v8;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x102BEE20
// Name: public: virtual bool CWindowPositionMgr::LoadPositions(char const __near *,class vgui::Panel __near *,class vgui::IToolWindowFactory __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWindowPositionMgr::LoadPositions(
        CWindowPositionMgr *this,
        char *filename,
        vgui::Panel *parent,
        vgui::IToolWindowFactory *factory,
        KeyValues *key,
        bool force)
{
  void (__thiscall *GetScreenSize)(vgui::ISurface *, int *, int *); // eax
  KeyValues *v7; // eax
  IBaseFileSystem *v8; // eax
  KeyValues *v9; // esi
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  char *String; // eax
  int v13; // edi
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // edx
  KeyValues *v17; // esi
  vgui::ToolWindow *v18; // ebx
  KeyValues *i; // edi
  const char *v20; // eax
  char *v21; // eax
  CWindowPositionMgr::LoadInfo_t *v22; // eax
  vgui::PHandle *v23; // esi
  vgui::Panel *v24; // eax
  char *v26; // [esp-14h] [ebp-40h]
  bool m_bContextMenu; // [esp-10h] [ebp-3Ch]
  int x; // [esp+4h] [ebp-28h]
  int y; // [esp+8h] [ebp-24h]
  float fh; // [esp+Ch] [ebp-20h] BYREF
  float fw; // [esp+10h] [ebp-1Ch] BYREF
  float fy; // [esp+14h] [ebp-18h] BYREF
  int sh; // [esp+18h] [ebp-14h] BYREF
  float fx; // [esp+1Ch] [ebp-10h] BYREF
  int sw; // [esp+20h] [ebp-Ch] BYREF
  KeyValues *kv; // [esp+24h] [ebp-8h]
  bool success; // [esp+2Bh] [ebp-1h]
  const char *filenamea; // [esp+34h] [ebp+8h]
  KeyValues *tw; // [esp+40h] [ebp+14h]

  GetScreenSize = g_pVGuiSurface->GetScreenSize;
  success = false;
  GetScreenSize(this: g_pVGuiSurface, a2: &sw, a3: &sh);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    kv = KeyValues::KeyValues(this: v7, setName: (const char *)key);
  else
    kv = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v8 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v8 = nullptr;
  v9 = kv;
  if ( KeyValues::LoadFromFile(
         this: kv,
         filesystem: v8,
         resourceName: filename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v9);
    tw = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "toolwindow") == 0 )
        {
          String = KeyValues::GetString(this: FirstSubKey, keyName: "bounds", defaultValue: &var);
          if ( String != nullptr
            && *String != 0
            && sscanf(string: String, format: "%f %f %f %f", &fx, &fy, &fw, &fh) == 4 )
          {
            v13 = sh;
            x = (int)(float)((float)((float)sw * fx) + 0.5);
            v14 = (float)((float)sw * fw) + 0.5;
            y = (int)(float)((float)((float)sh * fy) + 0.5);
            v15 = (float)((float)sh * fh) + 0.5;
            v16 = (int)v15;
            if ( (int)v14 >= 0 )
            {
              filenamea = (const char *)sw;
              if ( (int)v14 <= sw )
                filenamea = (const char *)(int)v14;
            }
            else
            {
              filenamea = nullptr;
            }
            if ( v16 >= 0 )
            {
              if ( v16 <= sh )
                v13 = (int)v15;
            }
            else
            {
              v13 = 0;
            }
            v17 = KeyValues::FindKey(this: FirstSubKey, keyName: "windows", bCreate: false);
            if ( v17 != nullptr )
            {
              v18 = (vgui::ToolWindow *)factory->InstanceToolWindow(
                                          this: factory,
                                          a2: parent,
                                          a3: true,
                                          a4: nullptr,
                                          a5: nullptr,
                                          a6: false);
              vgui::Panel::SetBounds(this: v18, x, y, wide: (int)filenamea, tall: v13);
              for ( i = KeyValues::GetFirstSubKey(this: v17); i != nullptr; i = KeyValues::GetNextKey(this: i) )
              {
                v20 = KeyValues::GetName(this: i);
                if ( _V_stricmp(s1: v20, s2: "panel") == 0 )
                {
                  v21 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &var);
                  if ( v21 != nullptr && *v21 != 0 )
                  {
                    v22 = CWindowPositionMgr::Find(this, panelName: v21);
                    v23 = (vgui::PHandle *)v22;
                    if ( v22 != nullptr )
                    {
                      m_bContextMenu = v22->m_bContextMenu;
                      v26 = CUtlSymbol::String(this: &v22->m_Name);
                      v24 = vgui::PHandle::Get(this: v23 + 1);
                      vgui::ToolWindow::AddPage(this: v18, page: v24, title: v26, contextMenu: m_bContextMenu);
                      success = true;
                    }
                  }
                }
              }
              if ( !success && v18 != nullptr )
                ((void (__thiscall *)(vgui::ToolWindow *, int))v18->dtr_Panel)(a1: v18, a2: 1);
              FirstSubKey = tw;
            }
          }
        }
        tw = KeyValues::GetNextKey(this: FirstSubKey);
        if ( tw == nullptr )
          break;
        FirstSubKey = tw;
      }
      v9 = kv;
    }
  }
  KeyValues::deleteThis(this: v9);
  return success;
}

//------------------------------------------------------------------------------
// Address: 0x102BF0A0
// Name: public: virtual void CWindowPositionMgr::UnregisterPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWindowPositionMgr::UnregisterPanel(CWindowPositionMgr *this, vgui::Panel *panel)
{
  int v3; // esi
  int i; // edi

  v3 = this->m_Panels.m_Size - 1;
  if ( v3 >= 0 )
  {
    for ( i = v3; vgui::PHandle::Get(this: &this->m_Panels.m_Memory.m_pMemory[i].m_hPanel) != panel; --i )
    {
      if ( --v3 < 0 )
        return;
    }
    if ( this->m_Panels.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&this->m_Panels.m_Memory.m_pMemory[v3],
        src: (unsigned __int8 *)&this->m_Panels.m_Memory.m_pMemory[v3 + 1],
        count: 12 * (this->m_Panels.m_Size - v3 - 1));
    --this->m_Panels.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF190
// Name: public: virtual void CWindowPositionMgr::SavePositions(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CWindowPositionMgr::SavePositions(
        CWindowPositionMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *filename,
        CWindowPositionMgr *key)
{
  float v6; // xmm0_4
  int ToolWindowCount; // edi
  int v8; // ebx
  vgui::ToolWindow *ToolWindow; // esi
  vgui::PropertySheet *PropertySheet; // eax
  vgui::PropertySheet *v11; // esi
  int i; // ebx
  vgui::Panel *v13; // eax
  CWindowPositionMgr::LoadInfo_t *v14; // eax
  char *v15; // eax
  void *v16; // eax
  void *v17; // esi
  int v18; // [esp+20h] [ebp-68h]
  int v19; // [esp+24h] [ebp-64h]
  int v20; // [esp+28h] [ebp-60h]
  CUtlBuffer v21; // [esp+2Ch] [ebp-5Ch] BYREF
  int v22; // [esp+5Ch] [ebp-2Ch]
  _BYTE buf[40]; // [esp+60h] [ebp-28h] OVERLAPPED BYREF

  *(_DWORD *)buf = this;
  CUtlBuffer::CUtlBuffer(this: &v21, growSize: 0, initSize: 0, nFlags: 1u);
  CUtlBuffer::Printf(this: &v21, pFmt: (const char *)&stru_105D97EC, key);
  CUtlBuffer::Printf(this: &v21, pFmt: "{\n");
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: (int *)&buf[24], a3: (int *)&buf[20]);
  v6 = 1.0;
  if ( (float)*(int *)&buf[24] == 0.0 )
    *(_DWORD *)&buf[36] = 1065353216;
  else
    *(float *)&buf[36] = 1.0 / (float)*(int *)&buf[24];
  if ( (float)*(int *)&buf[20] != 0.0 )
    v6 = 1.0 / (float)*(int *)&buf[20];
  v20 = a2;
  v19 = a4;
  v18 = a3;
  ToolWindowCount = vgui::ToolWindow::GetToolWindowCount();
  v8 = 0;
  v22 = ToolWindowCount;
  for ( *(_DWORD *)&buf[28] = 0; v8 < ToolWindowCount; *(_DWORD *)&buf[28] = v8 )
  {
    ToolWindow = vgui::ToolWindow::GetToolWindow(index: v8);
    if ( ToolWindow != nullptr )
    {
      BufPrint(buf: &v21, level: 1, fmt: "toolwindow\n", v18, v19, v20);
      BufPrint(buf: &v21, level: 1, fmt: "{\n");
      vgui::Panel::GetBounds(
        this: ToolWindow,
        x: (int *)&buf[4],
        y: (int *)&buf[8],
        wide: (int *)&buf[12],
        tall: (int *)&buf[16]);
      BufPrint(
        buf: &v21,
        level: 2,
        fmt: "bounds \"%.10f %.10f %.10f %.10f\"\n",
        (float)((float)*(int *)&buf[4] * *(float *)&buf[36]),
        (float)((float)*(int *)&buf[8] * v6),
        (float)((float)*(int *)&buf[12] * *(float *)&buf[36]),
        (float)((float)*(int *)&buf[16] * v6));
      PropertySheet = vgui::ToolWindow::GetPropertySheet(this: ToolWindow);
      v11 = PropertySheet;
      if ( PropertySheet != nullptr )
      {
        *(_DWORD *)&buf[32] = PropertySheet->GetNumPages(this: PropertySheet);
        if ( *(int *)&buf[32] > 0 )
        {
          BufPrint(buf: &v21, level: 2, fmt: "windows\n");
          BufPrint(buf: &v21, level: 2, fmt: "{\n");
          for ( i = 0; i < *(int *)&buf[32]; ++i )
          {
            v13 = v11->GetPage(this: v11, a2: i);
            if ( v13 != nullptr )
            {
              v14 = CWindowPositionMgr::Find(this: *(CWindowPositionMgr **)buf, panel: v13);
              if ( v14 != nullptr )
              {
                v15 = CUtlSymbol::String(this: &v14->m_Name);
                BufPrint(buf: &v21, level: 3, fmt: "panel \"%s\"\n", v15);
              }
            }
          }
          BufPrint(buf: &v21, level: 2, fmt: "}\n");
          v8 = *(_DWORD *)&buf[28];
        }
      }
      BufPrint(buf: &v21, level: 1, fmt: "}\n");
      ToolWindowCount = v22;
    }
    ++v8;
  }
  CUtlBuffer::Printf(this: &v21, pFmt: "}\n");
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, const char *, const char *, int, int, int))g_pFullFileSystem->FileExists)(
         a1: &g_pFullFileSystem->IBaseFileSystem,
         a2: filename,
         a3: "DEFAULT_WRITE_PATH",
         a4: v18,
         a5: v19,
         a6: v20) != 0
    && !g_pFullFileSystem->IsFileWritable(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: filename,
          a3: "DEFAULT_WRITE_PATH") )
  {
    _Warning(a1: "IFM window layout file '%s' is read-only!!!\n", filename);
  }
  v16 = g_pFullFileSystem->Open(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: filename,
          a3: "wb",
          a4: "DEFAULT_WRITE_PATH");
  v17 = v16;
  if ( v16 != nullptr )
  {
    g_pFullFileSystem->Write(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: v21.m_Memory.m_pMemory,
      a3: v21.m_Put,
      a4: v16);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v17);
  }
  if ( v21.m_Memory.m_nGrowSize >= 0 && v21.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x102BF4A0
// Name: public: virtual void CWindowPositionMgr::RegisterPanel(char const __near *,class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWindowPositionMgr::RegisterPanel(
        CWindowPositionMgr *this,
        char *saveName,
        CDragDropHelperPanel *panel,
        bool contextMenu)
{
  CDragDropHelperPanel *v4; // esi
  const char *v6; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CWindowPositionMgr::LoadInfo_t info; // [esp+8h] [ebp-Ch] BYREF

  v4 = panel;
  v6 = panel->GetName(this: panel);
  if ( v6 != nullptr && *v6 != 0 )
  {
    info.m_hPanel.m_iPanelID = -1;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&info.m_hPanel,
      pPanel: v4);
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&panel + 1, pStr: saveName);
    info.m_Name.m_Id = HIWORD(panel);
    info.m_bContextMenu = contextMenu;
    m_Size = this->m_Panels.m_Size;
    info.m_bLoaded = false;
    CUtlVector<CWindowPositionMgr::LoadInfo_t,CUtlMemory<CWindowPositionMgr::LoadInfo_t,int>>::InsertBefore(
      this: &this->m_Panels,
      elem: m_Size,
      src: &info);
  }
  else
  {
    _Warning(a1: "CWindowPositionMgr::RegisterPanel:  Panel has NULL or blank name!!!\n");
  }
}
