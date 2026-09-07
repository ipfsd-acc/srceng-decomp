// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vtex_gui/vtexdialog.cpp
// Functions: 67
// ============================================================

#include "utils\vtex_gui\vtexdialog.h"

//------------------------------------------------------------------------------
// Address: 0x004039C0
// Name: char __near * CloneString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CloneString(const char *str)
{
  char *result; // eax
  int v2; // eax
  char *v3; // esi

  if ( str != nullptr )
  {
    v2 = _V_strlen(str);
    v3 = (char *)operator new(nSize: v2 + 1);
    _V_strcpy(dest: v3, src: str);
    return v3;
  }
  else
  {
    result = (char *)operator new(nSize: 1u);
    *result = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403A00
// Name: bool FStrEq(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FStrEq(const char *sz1, const char *sz2)
{
  return _V_stricmp(s1: sz1, s2: sz2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403A20
// Name: public: static char const __near * CVtexDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVtexDialog::GetPanelClassName()
{
  return "CVtexDialog";
}

//------------------------------------------------------------------------------
// Address: 0x00403A30
// Name: char __near * VarArgs(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *VarArgs(char *format, ...)
{
  va_list params; // [esp+Ch] [ebp+Ch] BYREF

  va_start(params, format);
  index = (index + 1) % 4;
  V_vsnprintf(pDest: string[index], maxLen: 1024, pFormat: format, params);
  return string[index];
}

//------------------------------------------------------------------------------
// Address: 0x00403A80
// Name: int FileSortFunc(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileSortFunc(vgui::ListPanel *pPanel, const vgui::ListPanelItem *item1, const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00403AC0
// Name: private: void CVtexDialog::ReloadSurfaceProps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::ReloadSurfaceProps(CVtexDialog *this)
{
  CVtexDialog *v1; // ebx
  vgui::ComboBox *m_surfaceProperties; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IBaseFileSystem *v5; // eax
  KeyValues *FirstValue; // edi
  IBaseFileSystem_vtbl *v7; // esi
  const char *String; // eax
  void *v9; // ebx
  unsigned int v10; // edi
  unsigned int v11; // esi
  void *v12; // esp
  int v13; // eax
  int v14; // eax
  KeyValues *v15; // edi
  const char *v16; // eax
  KeyValues *v17; // edi
  const char *v18; // eax
  KeyValues *FirstSubKey; // esi
  CVtexDialog *v20; // ebx
  vgui::ComboBox_vtbl *v21; // edi
  const char *Name; // eax
  int v23; // [esp-4h] [ebp-20h]
  char v24[12]; // [esp+0h] [ebp-1Ch] BYREF
  CVtexDialog *v25; // [esp+Ch] [ebp-10h]
  KeyValues *manifest; // [esp+10h] [ebp-Ch]
  int fullLen; // [esp+14h] [ebp-8h]
  KeyValues *fname; // [esp+18h] [ebp-4h]

  v1 = this;
  m_surfaceProperties = this->m_surfaceProperties;
  v25 = v1;
  vgui::ComboBox::RemoveAll(this: m_surfaceProperties);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "surfaceproperties_manifest");
    manifest = v4;
  }
  else
  {
    manifest = nullptr;
    v4 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: "scripts/surfaceproperties_manifest.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstValue = KeyValues::GetFirstValue(this: v4);
    fname = FirstValue;
    if ( FirstValue != nullptr )
    {
      while ( 1 )
      {
        v7 = g_pFullFileSystem->IBaseFileSystem::__vftable;
        String = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue);
        v9 = v7->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: String, a3: "rb", a4: nullptr);
        if ( v9 != nullptr )
        {
          v10 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v9);
          v11 = v10 + _V_strlen(str: "\n}\n");
          fullLen = _V_strlen(str: "surfaceprops\n{\n") + v11 + 1;
          v12 = alloca(fullLen);
          V_strncpy(pDest: v24, pSrc: "surfaceprops\n{\n", maxLen: fullLen);
          fullLen = (int)g_pFullFileSystem->IBaseFileSystem::__vftable;
          v13 = _V_strlen(str: "surfaceprops\n{\n");
          (*(void (__thiscall **)(IBaseFileSystem *, char *, unsigned int, void *))fullLen)(
            a1: &g_pFullFileSystem->IBaseFileSystem,
            a2: &v24[v13],
            a3: v10,
            a4: v9);
          v23 = _V_strlen(str: "\n}\n") + 1;
          v14 = _V_strlen(str: "surfaceprops\n{\n");
          V_strncpy(pDest: &v24[v14 + v10], pSrc: "\n}\n", maxLen: v23);
          g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v9);
          v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v15 != nullptr )
          {
            v16 = KeyValues::GetString(this: fname, keyName: nullptr, defaultValue: defaultValue);
            v17 = KeyValues::KeyValues(this: v15, setName: v16);
            fullLen = (int)v17;
          }
          else
          {
            fullLen = 0;
            v17 = nullptr;
          }
          v18 = KeyValues::GetString(this: fname, keyName: nullptr, defaultValue: defaultValue);
          if ( KeyValues::LoadFromBuffer(
                 this: v17,
                 resourceName: v18,
                 pBuffer: v24,
                 pFileSystem: nullptr,
                 pPathID: nullptr,
                 pfnEvaluateSymbolProc: nullptr) )
          {
            FirstSubKey = KeyValues::GetFirstSubKey(this: v17);
            if ( FirstSubKey != nullptr )
            {
              do
              {
                v20 = v25;
                v21 = v25->m_surfaceProperties->__vftable;
                Name = KeyValues::GetName(this: FirstSubKey);
                v21->AddItem_2(this: v20->m_surfaceProperties, a2: Name, a3: nullptr);
                FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
              }
              while ( FirstSubKey != nullptr );
              v17 = (KeyValues *)fullLen;
            }
          }
          KeyValues::deleteThis(this: v17);
          FirstValue = fname;
        }
        fname = KeyValues::GetNextValue(this: FirstValue);
        if ( fname == nullptr )
          break;
        FirstValue = fname;
      }
      v4 = manifest;
      v1 = v25;
    }
  }
  KeyValues::deleteThis(this: v4);
  vgui::ComboBox::ActivateItemByRow(this: v1->m_surfaceProperties, row: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00403D30
// Name: protected: virtual void CVtexDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::ApplySchemeSettings(CVtexDialog *this, vgui::IScheme *scheme)
{
  vgui::RichText *m_output; // ecx

  vgui::Frame::ApplySchemeSettings(this, pScheme: scheme);
  m_output = this->m_output;
  if ( m_output != nullptr )
    vgui::RichText::GotoTextEnd(this: m_output);
}

//------------------------------------------------------------------------------
// Address: 0x00403D60
// Name: protected: virtual void CVtexDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::PerformLayout(CVtexDialog *this)
{
  vgui::RichText *m_output; // ecx
  int Wide; // eax

  vgui::Frame::PerformLayout(this);
  m_output = this->m_output;
  if ( m_output != nullptr )
    vgui::RichText::GotoTextEnd(this: m_output);
  Wide = vgui::Panel::GetWide(this: this->m_variables);
  vgui::PanelListPanel::SetFirstColumnWidth(this: this->m_variables, width: (int)((double)Wide * 0.55));
}

//------------------------------------------------------------------------------
// Address: 0x00403DB0
// Name: protected: virtual void CVtexDialog::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::OnTextChanged(CVtexDialog *this)
{
  CVtexDialog *v1; // esi
  KeyValues *ActiveItemUserData; // eax
  KeyValues *FirstSubKey; // edi
  int v4; // ebx
  int v5; // esi
  int v6; // [esp+0h] [ebp-1Ch]
  const char *shaderName; // [esp+Ch] [ebp-10h]
  const char *allowedShaders; // [esp+10h] [ebp-Ch]
  vgui::Panel *panel; // [esp+14h] [ebp-8h]

  v1 = this;
  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_shader);
  shaderName = KeyValues::GetString(this: ActiveItemUserData, keyName: "shader", defaultValue: "None");
  FirstSubKey = KeyValues::GetFirstSubKey(this: v1->m_variableKeys);
  v4 = 0;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      allowedShaders = KeyValues::GetString(this: FirstSubKey, keyName: "shaders", defaultValue: nullptr);
      v5 = (int)v1->m_variables->GetItemLabel(this: v1->m_variables, a2: v4);
      panel = this->m_variables->GetItemPanel(this: this->m_variables, a2: v4);
      if ( allowedShaders == nullptr || _V_strstr(s1: allowedShaders, search: shaderName) != nullptr )
      {
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v5 + 220))(a1: v5, a2: 1, a3: v6);
        v6 = 1;
      }
      else
      {
        (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v5 + 1020))(a1: v5, a2: 0, a3: v6);
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 220))(a1: v5, a2: 0);
        v6 = 0;
      }
      ((void (__thiscall *)(vgui::Panel *))panel->SetEnabled)(a1: panel);
      ++v4;
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403EB0
// Name: public: void CVtexDialog::AddMsg(class Color,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVtexDialog::AddMsg(CVtexDialog *this, Color c, const char *format, ...)
{
  va_list params; // [esp+18h] [ebp+14h] BYREF

  va_start(params, format);
  if ( this->m_output != nullptr )
  {
    V_vsnprintf(pDest: str, maxLen: 1024, pFormat: format, params);
    vgui::RichText::InsertColorChange(this: this->m_output, col: c);
    vgui::RichText::InsertString(this: this->m_output, text: str);
    vgui::RichText::GotoTextEnd(this: this->m_output);
    OutputDebugStringA(lpOutputString: str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403F20
// Name: public: void CVtexDialog::AddMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVtexDialog::AddMsg(CVtexDialog *this, const char *format, ...)
{
  va_list params; // [esp+14h] [ebp+10h] BYREF

  va_start(params, format);
  if ( this->m_output != nullptr )
  {
    V_vsnprintf(pDest: str_0, maxLen: 1024, pFormat: format, params);
    vgui::RichText::InsertColorChange(this: this->m_output, col: (Color)-1);
    vgui::RichText::InsertString(this: this->m_output, text: str_0);
    vgui::RichText::GotoTextEnd(this: this->m_output);
    OutputDebugStringA(lpOutputString: str_0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403F90
// Name: public: void CVtexDialog::AddWarning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVtexDialog::AddWarning(CVtexDialog *this, const char *format, ...)
{
  va_list params; // [esp+14h] [ebp+10h] BYREF

  va_start(params, format);
  if ( this->m_output != nullptr )
  {
    V_vsnprintf(pDest: str_1, maxLen: 1024, pFormat: format, params);
    vgui::RichText::InsertColorChange(this: this->m_output, col: (Color)-12566273);
    vgui::RichText::InsertString(this: this->m_output, text: str_1);
    vgui::RichText::GotoTextEnd(this: this->m_output);
    OutputDebugStringA(lpOutputString: str_1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404000
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<vgui::MessageMapItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::MessageMapItem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404090
// Name: private: void CVtexDialog::ReloadDefaultValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::ReloadDefaultValues(CVtexDialog *this)
{
  int v2; // ebx
  int v3; // edi
  CVtexDialog::MaterialVar *m_pMemory; // eax
  const char *String; // eax
  int v6; // ecx
  __int64 var; // [esp+8h] [ebp-10h]
  __int64 var_8; // [esp+10h] [ebp-8h]

  v2 = 0;
  if ( this->m_materialVars.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_materialVars.m_Memory.m_pMemory;
      var = *(_QWORD *)&m_pMemory[v3].label;
      var_8 = *(_QWORD *)&m_pMemory[v3].combo;
      String = KeyValues::GetString(this: (KeyValues *)HIDWORD(var_8), keyName: "default", defaultValue: defaultValue);
      v6 = var_8;
      if ( (_DWORD)var_8 != 0 || (v6 = HIDWORD(var), HIDWORD(var) != 0) )
        (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 844))(a1: v6, a2: String);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_materialVars.m_Size );
  }
  vgui::ComboBox::ActivateItemByRow(this: this->m_shader, row: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00404120
// Name: protected: virtual void CVtexDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::OnClose(CVtexDialog *this)
{
  vgui::Frame::OnClose(this);
  g_pVGui->Stop(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x00404140
// Name: protected: virtual void CVtexDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVtexDialog::OnCommand(CVtexDialog *this@<ecx>, int a2@<ebx>, const char *command)
{
  char *v4; // edi
  vgui::QueryBox *v5; // eax
  vgui::QueryBox *Box; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  vgui::FileOpenDialog *v11; // eax
  vgui::FileOpenDialog *v12; // eax
  vgui::FileOpenDialog *v13; // eax
  int v14; // eax
  vgui::ListPanel *m_files; // ecx
  vgui::ListPanel_vtbl *v16; // ebx
  int (__thiscall *GetItemIDFromRow)(vgui::ListPanel *, int); // eax
  int v18; // eax
  KeyValues *v19; // eax
  const char *v20; // eax
  vgui::FileOpenDialog *v21; // eax
  vgui::Panel *v22; // eax
  vgui::FileOpenDialog *v23; // eax
  int v24; // eax
  char *m_gameDir; // eax
  vgui::Label_vtbl *v26; // edi
  char *v27; // eax
  int v28; // ebx
  int v29; // eax
  KeyValues *v30; // edi
  const char *String; // eax
  const char *v32; // eax
  KeyValues *ActiveItemUserData; // eax
  const char *v34; // eax
  int v35; // ebx
  vgui::Panel *v36; // edi
  vgui::Panel *v37; // ebx
  const char *v38; // eax
  int v39; // eax
  const char *(__thiscall *GetName)(vgui::IClientPanel *); // edx
  int v41; // eax
  const char *v42; // eax
  const char *v43; // [esp-8h] [ebp-13Ch]
  char *v44; // [esp-4h] [ebp-138h]
  char value[260]; // [esp+8h] [ebp-12Ch] OVERLAPPED BYREF
  CSplitString args; // [esp+10Ch] [ebp-28h] BYREF
  int num; // [esp+124h] [ebp-10h]
  vgui::Panel *panel; // [esp+128h] [ebp-Ch]
  int x; // [esp+12Ch] [ebp-8h] BYREF
  int i; // [esp+130h] [ebp-4h] BYREF

  CSplitString::CSplitString(this: &args, pString: command, pSeparator: " ");
  if ( args.m_Size > 0 )
  {
    v4 = *args.m_Memory.m_pMemory;
    if ( _V_stricmp(s1: *(const char **)args.m_Memory.m_pMemory, s2: "vtex") == 0 )
    {
      CVtexDialog::ProcessTargas(this);
      CSplitString::~CSplitString(this: &args);
      return;
    }
    if ( _V_stricmp(s1: v4, s2: "defaults") == 0 )
    {
      if ( args.m_Size == 2 )
      {
        if ( _V_stricmp(s1: *((const char **)args.m_Memory.m_pMemory + 1), s2: "prompt") != 0 )
        {
          if ( _V_stricmp(s1: *((const char **)args.m_Memory.m_pMemory + 1), s2: "load") == 0 )
            CVtexDialog::ReloadDefaultValues(this);
        }
        else
        {
          v5 = (vgui::QueryBox *)operator new(nSize: 0x244u);
          if ( v5 != nullptr )
            Box = vgui::QueryBox::QueryBox(
                    this: v5,
                    title: "Revert to defaults",
                    queryText: "Do you wish to reload the default values?",
                    parent: this);
          else
            Box = nullptr;
          v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v7 != nullptr )
            v8 = KeyValues::KeyValues(this: v7, setName: "Command", firstKey: "Command", firstValue: "defaults load");
          else
            v8 = nullptr;
          vgui::QueryBox::SetOKCommand(this: Box, keyValues: v8);
          v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v9 != nullptr )
            v10 = KeyValues::KeyValues(this: v9, setName: "Command", firstKey: "Command", firstValue: "defaults cancel");
          else
            v10 = nullptr;
          vgui::QueryBox::SetCancelCommand(this: Box, keyValues: v10);
          Box->AddActionSignalTarget_2(this: Box, a2: this);
          Box->DoModal_2(this: Box, a2: nullptr);
        }
      }
      goto LABEL_62;
    }
    if ( _V_stricmp(s1: v4, s2: "addfiles") != 0 )
    {
      if ( _V_stricmp(s1: v4, s2: "removefiles") != 0 )
      {
        if ( _V_stricmp(s1: v4, s2: "refresh") != 0 )
        {
          if ( _V_stricmp(s1: v4, s2: "dump") == 0 )
          {
            v28 = 0;
            v29 = this->m_files->GetItemIDFromRow(this: this->m_files, a2: 0);
            if ( v29 > -1 )
            {
              i = -4144960;
              do
              {
                ++v28;
                v30 = this->m_files->GetItem(this: this->m_files, a2: v29);
                String = KeyValues::GetString(this: v30, keyName: "filename", defaultValue: defaultValue);
                CVtexDialog::AddMsg(this, format: "%s", String);
                v32 = KeyValues::GetString(this: v30, keyName: "path", defaultValue: defaultValue);
                CVtexDialog::AddMsg(this, c: (Color)i, format: " %s\n", v32);
                v29 = this->m_files->GetItemIDFromRow(this: this->m_files, a2: v28);
              }
              while ( v29 > -1 );
            }
            ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_shader);
            if ( ActiveItemUserData != nullptr )
            {
              v34 = KeyValues::GetString(this: ActiveItemUserData, keyName: "shader", defaultValue: defaultValue);
              CVtexDialog::AddMsg(this, format: "Shader is %s\n", v34);
            }
            v35 = 0;
            num = vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_variables);
            i = 0;
            if ( num > 0 )
            {
              while ( 1 )
              {
                v36 = this->m_variables->GetItemLabel(this: this->m_variables, a2: v35);
                v37 = this->m_variables->GetItemPanel(this: this->m_variables, a2: v35);
                panel = v37;
                if ( v37 != nullptr
                  && v36 != nullptr
                  && ((unsigned __int8 (__thiscall *)(vgui::Panel *))v36->__vftable[1].SetAutoDelete)(a1: v36) != 0
                  && v36->IsEnabled(this: v36) )
                {
                  v38 = v36->GetName(this: v36);
                  v39 = _V_strlen(str: v38);
                  GetName = v37->GetName;
                  x = v39;
                  v41 = (int)GetName(this: v37);
                  memset(&value[4], 0, 256);
                  if ( _V_stricmp(s1: (const char *)(x + v41 + 1), s2: "default") == 0 )
                    panel->__vftable[1].PaintTraverse(this: panel, a2: (bool)&value[4], a3: 256);
                  v42 = (const char *)((int (__thiscall *)(vgui::Panel *, char *))v36->GetName)(a1: v36, a2: &value[4]);
                  CVtexDialog::AddMsg(this, format: "%s\t\t\"%s\"\n", v42, v43);
                }
                if ( ++i >= num )
                  break;
                v35 = i;
              }
            }
          }
        }
        else
        {
          vgui::Panel::GetPos(this, &x, y: &i);
          ((void (__thiscall *)(CVtexDialog *, const char *, _DWORD, _DWORD, _DWORD, int))this->LoadControlSettings)(
            a1: this,
            a2: "VtexDialog.res",
            a3: 0,
            a4: 0,
            a5: 0,
            a6: a2);
          m_gameDir = this->m_gameDir;
          if ( m_gameDir != nullptr && *m_gameDir != 0 )
          {
            v26 = this->m_gameDirLabel->__vftable;
            v27 = VarArgs(format: "Game Dir: %s", this->m_gameDir);
            ((void (__cdecl *)(char *))v26->SetText)(a1: v27);
          }
          else
          {
            ((void (__cdecl *)(const char *))this->m_gameDirLabel->SetText)(a1: "Game Dir: <None>");
          }
          vgui::Panel::SetPos(this, x, y: i);
        }
      }
      else
      {
        while ( this->m_files->GetSelectedItemsCount(this: this->m_files) > 0 )
        {
          v24 = this->m_files->GetSelectedItem(this: this->m_files, a2: 0);
          if ( v24 < 0 )
            break;
          this->m_files->RemoveItem(this: this->m_files, a2: v24);
        }
      }
      goto LABEL_62;
    }
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
    {
      v11 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
      v12 = v11 != nullptr
          ? vgui::FileOpenDialog::FileOpenDialog(
              this: v11,
              parent: this,
              title: "Choose Targas to add",
              bOpenOnly: true,
              pContextKeyValues: nullptr)
          : nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hFileOpenDialog, pPanel: v12);
      if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
      {
        v13 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
        vgui::FileOpenDialog::AddFilter(
          this: v13,
          filter: "*.tga",
          filterName: "Targa Files (*.tga)",
          bActive: true,
          pFilterInfo: nullptr);
      }
    }
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      v14 = ((int (__thiscall *)(vgui::ListPanel *, int))this->m_files->GetSelectedItemsCount)(a1: this->m_files, a2);
      m_files = this->m_files;
      if ( v14 <= 0 )
      {
        if ( m_files->GetItemIDFromRow(this: m_files, a2: 0) < 0 )
        {
          v21 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
          v44 = this->m_gameDir;
          goto LABEL_33;
        }
        v16 = this->m_files->__vftable;
        GetItemIDFromRow = v16->GetItemIDFromRow;
      }
      else
      {
        v16 = m_files->__vftable;
        GetItemIDFromRow = m_files->GetSelectedItem;
      }
      v18 = ((int (__stdcall *)(_DWORD))GetItemIDFromRow)(a1: 0);
      v19 = v16->GetItem(this: this->m_files, a2: v18);
      v20 = KeyValues::GetString(this: v19, keyName: "path", defaultValue: defaultValue);
      V_strncpy(pDest: value, pSrc: v20, maxLen: 260);
      V_StripFilename(path: value);
      v44 = value;
      v21 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
LABEL_33:
      vgui::FileOpenDialog::SetStartDirectory(this: v21, dir: v44);
      v22 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      v22->SetVisible(this: v22, a2: true);
      v23 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::DoModal(this: v23, bUnused: false);
    }
  }
LABEL_62:
  vgui::Frame::OnCommand(this, command);
  CSplitString::~CSplitString(this: &args);
}

//------------------------------------------------------------------------------
// Address: 0x00404750
// Name: private: void CVtexDialog::SetGameDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::SetGameDir(CVtexDialog *this, const char *gameDir)
{
  char *v3; // eax
  int v4; // eax
  char *v5; // edi
  vgui::Label_vtbl *v6; // edi
  char *v7; // eax
  CVtexDialog_vtbl *v8; // edi
  char *v9; // eax

  if ( gameDir == nullptr || this->m_gameDir == nullptr || _V_stricmp(s1: gameDir, s2: this->m_gameDir) != 0 )
  {
    if ( this->m_gameDir != nullptr )
      free(pMem: this->m_gameDir);
    if ( gameDir != nullptr )
    {
      v4 = _V_strlen(str: gameDir);
      v5 = (char *)operator new(nSize: v4 + 1);
      _V_strcpy(dest: v5, src: gameDir);
      v3 = v5;
    }
    else
    {
      v3 = (char *)operator new(nSize: 1u);
      *v3 = 0;
    }
    this->m_gameDir = v3;
    if ( v3 != nullptr && *v3 != 0 )
    {
      v6 = this->m_gameDirLabel->__vftable;
      v7 = VarArgs(format: "Game Dir: %s", v3);
      v6->SetText(this: this->m_gameDirLabel, a2: v7);
      v8 = this->__vftable;
      v9 = VarArgs(format: "%s - VTEX GUI", this->m_gameDir);
      v8->SetTitle_2(this, a2: v9, a3: true);
      CVtexDialog::ReloadSurfaceProps(this);
    }
    else
    {
      this->m_gameDirLabel->SetText(this: this->m_gameDirLabel, a2: "Game Dir: <None>");
      this->SetTitle_2(this, a2: "VTEX GUI", a3: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004048C0
// Name: public: static void CVtexDialog::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVtexDialog::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVtexDialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CVtexDialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVtexDialog");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "FileSelected";
    v4.func = v2;
    v4.firstParamName = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404960
// Name: public: static void CVtexDialog::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVtexDialog::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CVtexDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CVtexDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVtexDialog");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "TextChanged";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004049F0
// Name: public: CVtexDialog::CVtexDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVtexDialog *__thiscall CVtexDialog::CVtexDialog(CVtexDialog *this, KeyValues *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::RichText *v7; // eax
  vgui::RichText *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::ListPanel *v10; // eax
  vgui::Label *v11; // eax
  vgui::Label *v12; // eax
  vgui::ComboBox *v13; // eax
  vgui::ComboBox *v14; // eax
  vgui::PanelListPanel *v15; // eax
  vgui::PanelListPanel *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::ListPanel *m_files; // ecx
  vgui::ListPanel_vtbl *v20; // edi
  int Wide; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  IBaseFileSystem *v24; // eax
  KeyValues *Key; // eax
  KeyValues *i; // edi
  const char *v27; // eax
  vgui::ComboBox_vtbl *v28; // ebx
  const char *String; // eax
  KeyValues *v30; // eax
  KeyValues *Copy; // eax
  KeyValues *FirstSubKey; // edi
  const char *v33; // edi
  vgui::TextEntry *v34; // edi
  const char *v35; // eax
  vgui::TextEntry *v36; // edi
  vgui::TextEntry *v37; // edi
  const char *v38; // eax
  vgui::TextEntry *v39; // edi
  const char *v40; // eax
  vgui::ComboBox *v41; // edi
  const char *v42; // eax
  vgui::ComboBox *v43; // eax
  vgui::CheckButton *v44; // eax
  vgui::CheckButton *v45; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CVtexDialog::MaterialVar *m_pMemory; // ecx
  int v49; // eax
  CVtexDialog::MaterialVar *v50; // edi
  __int64 var; // [esp+Ch] [ebp-20h]
  __int64 var_8; // [esp+14h] [ebp-18h]
  vgui::PanelListPanel *parenta; // [esp+1Ch] [ebp-10h]
  vgui::PanelListPanel *parentb; // [esp+1Ch] [ebp-10h]
  vgui::PanelListPanel *parentc; // [esp+1Ch] [ebp-10h]
  vgui::PanelListPanel *parentd; // [esp+1Ch] [ebp-10h]
  const char *value; // [esp+20h] [ebp-Ch]
  KeyValues *data; // [esp+24h] [ebp-8h]
  KeyValues *parameters; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF
  KeyValues *materialVar; // [esp+34h] [ebp+8h]
  const char *namea; // [esp+38h] [ebp+Ch]

  vgui::Frame::Frame(this, (vgui::Panel *)parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CVtexDialog_vtbl *)&CVtexDialog::`vftable';
  if ( `CVtexDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CVtexDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVtexDialog");
    v4->pfnClassName = CVtexDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CVtexDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVtexDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVtexDialog");
    v5->pfnClassName = CVtexDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CVtexDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVtexDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVtexDialog");
    v6->pfnClassName = CVtexDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CVtexDialog::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CVtexDialog::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_hFileOpenDialog.m_iPanelID = -1;
  this->m_materialVars.m_Memory.m_pMemory = nullptr;
  this->m_materialVars.m_Memory.m_nAllocationCount = 0;
  this->m_materialVars.m_Memory.m_nGrowSize = 0;
  this->m_materialVars.m_Size = 0;
  this->m_materialVars.m_pElements = nullptr;
  this->m_filesToProcess.m_Memory.m_pMemory = nullptr;
  this->m_filesToProcess.m_Memory.m_nAllocationCount = 0;
  this->m_filesToProcess.m_Memory.m_nGrowSize = 0;
  this->m_filesToProcess.m_Size = 0;
  this->m_filesToProcess.m_pElements = nullptr;
  TheVtexDialog = this;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hFileOpenDialog, pPanel: nullptr);
  this->m_vtexModule = nullptr;
  this->m_vtex = nullptr;
  this->m_numVMTArguments = 0;
  vgui::Panel::SetSize(this, wide: 640, tall: 480);
  vgui::Panel::SetMinimumSize(this, wide: 200, tall: 100);
  vgui::Frame::SetMinimizeButtonVisible(this, state: true);
  v7 = (vgui::RichText *)operator new(nSize: 0x220u);
  if ( v7 != nullptr )
    v8 = vgui::RichText::RichText(this: v7, parent: this, panelName: "Output");
  else
    v8 = nullptr;
  this->m_output = v8;
  v9 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v9 != nullptr )
    v10 = vgui::ListPanel::ListPanel(this: v9, parent: this, panelName: "Files");
  else
    v10 = nullptr;
  this->m_files = v10;
  v11 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v11 != nullptr )
    v12 = vgui::Label::Label(this: v11, parent: this, panelName: "GameDir", text: defaultValue);
  else
    v12 = nullptr;
  this->m_gameDirLabel = v12;
  v13 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v13 != nullptr )
    v14 = vgui::ComboBox::ComboBox(this: v13, parent: this, panelName: "Shader", numLines: 5, allowEdit: false);
  else
    v14 = nullptr;
  this->m_shader = v14;
  v15 = (vgui::PanelListPanel *)operator new(nSize: 0x1ACu);
  if ( v15 != nullptr )
    v16 = vgui::PanelListPanel::PanelListPanel(this: v15, parent: this, panelName: "Variables");
  else
    v16 = nullptr;
  this->m_variables = v16;
  vgui::PanelListPanel::SetVerticalBufferPixels(this: v16, buffer: 0);
  v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "ButtonRunVtex",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v18 = nullptr;
  this->m_vtexButton = v18;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "VtexDialog.vdf",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetMoveable(this, state: true);
  this->m_files->AddColumnHeader(this: this->m_files, a2: 0, a3: "path", a4: "Full Path", a5: 0, a6: 9);
  m_files = this->m_files;
  v20 = m_files->__vftable;
  Wide = vgui::Panel::GetWide(this: m_files);
  v20->AddColumnHeader(this: this->m_files, a2: 1, a3: "filename", a4: "Targa", a5: Wide, a6: 2);
  this->m_files->SetSortFunc(this: this->m_files, a2: 0, a3: FileSortFunc);
  this->m_files->SetColumnSortable(this: this->m_files, a2: 0, a3: true);
  this->m_files->SetSortColumn(this: this->m_files, a2: 0);
  v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v22 != nullptr )
    data = KeyValues::KeyValues(this: v22, setName: "data");
  else
    data = nullptr;
  v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v23 != nullptr )
    parameters = KeyValues::KeyValues(this: v23, setName: "Parameters");
  else
    parameters = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v24 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v24 = nullptr;
  KeyValues::LoadFromFile(
    this: parameters,
    filesystem: v24,
    resourceName: "VtexParameters.vdf",
    pathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
  Key = KeyValues::FindKey(this: parameters, keyName: "Shaders", bCreate: false);
  if ( Key != nullptr )
  {
    for ( i = KeyValues::GetFirstSubKey(this: Key); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      v27 = KeyValues::GetName(this: i);
      KeyValues::SetString(this: data, keyName: "shader", value: v27);
      v28 = this->m_shader->__vftable;
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
      v28->AddItem_2(this: this->m_shader, a2: String, a3: data);
    }
  }
  this->m_variableKeys = nullptr;
  this->m_surfaceProperties = nullptr;
  v30 = KeyValues::FindKey(this: parameters, keyName: "Variables", bCreate: false);
  if ( v30 != nullptr )
  {
    Copy = KeyValues::MakeCopy(this: v30);
    this->m_variableKeys = Copy;
    FirstSubKey = KeyValues::GetFirstSubKey(this: Copy);
    materialVar = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        HIDWORD(var) = 0;
        LODWORD(var_8) = 0;
        namea = KeyValues::GetName(this: FirstSubKey);
        value = KeyValues::GetString(this: FirstSubKey, keyName: "default", defaultValue: defaultValue);
        v33 = KeyValues::GetString(this: FirstSubKey, keyName: "type", defaultValue: "default");
        if ( _V_stricmp(s1: v33, s2: "default") == 0 )
          break;
        if ( _V_stricmp(s1: v33, s2: "suffix") == 0 )
        {
          parentb = this->m_variables;
          v37 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
          if ( v37 == nullptr )
            goto LABEL_50;
          v38 = VarArgs(format: "%s_suffix", namea);
          v36 = vgui::TextEntry::TextEntry(this: v37, parent: parentb, panelName: v38);
          goto LABEL_51;
        }
        if ( _V_stricmp(s1: v33, s2: "filename") == 0 )
        {
          parentc = this->m_variables;
          v39 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
          if ( v39 != nullptr )
          {
            v40 = VarArgs(format: "%s_filename", namea);
            v36 = vgui::TextEntry::TextEntry(this: v39, parent: parentc, panelName: v40);
            goto LABEL_51;
          }
LABEL_50:
          v36 = nullptr;
          goto LABEL_51;
        }
        if ( _V_stricmp(s1: v33, s2: "surfaceprop") != 0 )
          goto LABEL_67;
        parentd = this->m_variables;
        v41 = (vgui::ComboBox *)operator new(nSize: 0x458u);
        if ( v41 != nullptr )
        {
          v42 = VarArgs(format: "%s_combo", namea);
          v43 = vgui::ComboBox::ComboBox(this: v41, parent: parentd, panelName: v42, numLines: 20, allowEdit: true);
        }
        else
        {
          v43 = nullptr;
        }
        this->m_surfaceProperties = v43;
        LODWORD(var_8) = v43;
        v36 = v43;
LABEL_57:
        if ( v36 != nullptr )
        {
          v44 = (vgui::CheckButton *)operator new(nSize: 0x218u);
          if ( v44 != nullptr )
            v45 = vgui::CheckButton::CheckButton(this: v44, parent: this->m_variables, panelName: namea, text: namea);
          else
            v45 = nullptr;
          HIDWORD(var_8) = materialVar;
          LODWORD(var) = v45;
          this->m_variables->AddItem(this: this->m_variables, a2: v45, a3: v36);
          m_Size = this->m_materialVars.m_Size;
          m_nAllocationCount = this->m_materialVars.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&this->m_materialVars,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_materialVars.m_Size;
          m_pMemory = this->m_materialVars.m_Memory.m_pMemory;
          v49 = this->m_materialVars.m_Size - m_Size - 1;
          this->m_materialVars.m_pElements = m_pMemory;
          if ( v49 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v49);
          v50 = &this->m_materialVars.m_Memory.m_pMemory[m_Size];
          if ( v50 != nullptr )
          {
            *(_QWORD *)&v50->label = var;
            *(_QWORD *)&v50->combo = var_8;
          }
        }
LABEL_67:
        materialVar = KeyValues::GetNextKey(this: materialVar);
        if ( materialVar == nullptr )
          goto LABEL_68;
        FirstSubKey = materialVar;
      }
      parenta = this->m_variables;
      v34 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
      if ( v34 == nullptr )
        goto LABEL_50;
      v35 = VarArgs(format: "%s_default", namea);
      v36 = vgui::TextEntry::TextEntry(this: v34, parent: parenta, panelName: v35);
LABEL_51:
      v36->SetText(this: v36, a2: value);
      HIDWORD(var) = v36;
      goto LABEL_57;
    }
  }
LABEL_68:
  KeyValues::deleteThis(this: parameters);
  KeyValues::deleteThis(this: data);
  vgui::ComboBox::ActivateItemByRow(this: this->m_shader, row: 0);
  this->m_gameDir = nullptr;
  CVtexDialog::SetGameDir(this, gameDir: nullptr);
  CVtexDialog::LoadVTex(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004050E0
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
// Address: 0x004050F0
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
// Address: 0x00405100
// Name: private: virtual class vgui::Panel __near * vgui::Panel::GetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetPanel(vgui::Panel *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405110
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405120
// Name: public: virtual struct vgui::PanelMessageMap __near * CVtexDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVtexDialog::GetMessageMap(CVtexDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVtexDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVtexDialog::GetMessageMap'::`2'::s_pMap;
  `CVtexDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVtexDialog");
  `CVtexDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405150
// Name: public: virtual struct PanelAnimationMap __near * CVtexDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVtexDialog::GetAnimMap(CVtexDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CVtexDialog");
}

//------------------------------------------------------------------------------
// Address: 0x00405160
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVtexDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVtexDialog::GetKBMap(CVtexDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVtexDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVtexDialog::GetKBMap'::`2'::s_pMap;
  `CVtexDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVtexDialog");
  `CVtexDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405190
// Name: public: virtual CVtexDialog::~CVtexDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::~CVtexDialog(CVtexDialog *this)
{
  KeyValues *m_variableKeys; // ecx
  char *m_gameDir; // eax

  this->__vftable = (CVtexDialog_vtbl *)&CVtexDialog::`vftable';
  CVtexDialog::UnloadVTex(this);
  m_variableKeys = this->m_variableKeys;
  if ( m_variableKeys != nullptr )
    KeyValues::deleteThis(this: m_variableKeys);
  m_gameDir = this->m_gameDir;
  this->m_variableKeys = nullptr;
  if ( m_gameDir != nullptr )
    free(pMem: m_gameDir);
  this->m_gameDir = nullptr;
  TheVtexDialog = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_filesToProcess);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_materialVars);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x00405200
// Name: private: void CVtexDialog::AddTargasInDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::AddTargasInDir(CVtexDialog *this, const char *dir)
{
  const char *v2; // edi
  const char *v4; // eax
  HANDLE FirstFileA; // esi
  const char *v6; // eax
  const char *v7; // eax
  int m_Size; // esi
  char **m_pMemory; // ebx
  const char *v10; // eax
  const char *v11; // edi
  char *v12; // eax
  int v13; // eax
  int v14; // edi
  char **v15; // edi
  int v16; // edi
  _WIN32_FIND_DATAA FindFileData; // [esp+Ch] [ebp-160h] BYREF
  CVtexDialog *v18; // [esp+14Ch] [ebp-20h]
  CUtlVector<char *,CUtlMemory<char *,int> > m_subdirs; // [esp+150h] [ebp-1Ch] BYREF
  void *hFind; // [esp+164h] [ebp-8h]
  char *v21; // [esp+168h] [ebp-4h]

  v2 = dir;
  v18 = this;
  v4 = VarArgs(format: "%s\\*.tga", dir);
  FirstFileA = FindFirstFileA(lpFileName: v4, lpFindFileData: &FindFileData);
  if ( FirstFileA != (HANDLE)-1 )
  {
    do
    {
      v6 = VarArgs(format: "%s\\%s", dir, FindFileData.cFileName);
      CVtexDialog::AddTarga(this, path: v6);
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &FindFileData) );
    FindClose(hFindFile: FirstFileA);
  }
  v7 = VarArgs(format: "%s\\*.*", dir);
  hFind = FindFirstFileA(lpFileName: v7, lpFindFileData: &FindFileData);
  if ( hFind != (void *)-1 )
  {
    m_Size = 0;
    m_pMemory = nullptr;
    memset(&m_subdirs, 0, sizeof(m_subdirs));
    do
    {
      if ( (FindFileData.dwFileAttributes & 0x10) != 0
        && _V_stricmp(s1: ".", s2: FindFileData.cFileName) != 0
        && _V_stricmp(s1: "..", s2: FindFileData.cFileName) != 0 )
      {
        v10 = VarArgs(format: "%s\\%s", v2, FindFileData.cFileName);
        v11 = v10;
        if ( v10 != nullptr )
        {
          v13 = _V_strlen(str: v10);
          v21 = (char *)operator new(nSize: v13 + 1);
          _V_strcpy(dest: v21, src: v11);
        }
        else
        {
          v12 = (char *)operator new(nSize: 1u);
          *v12 = 0;
          v21 = v12;
        }
        v14 = m_Size;
        if ( m_Size + 1 > m_subdirs.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<unsigned long,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&m_subdirs,
            num: m_Size - m_subdirs.m_Memory.m_nAllocationCount + 1);
          m_Size = m_subdirs.m_Size;
          m_pMemory = m_subdirs.m_Memory.m_pMemory;
        }
        m_subdirs.m_Size = ++m_Size;
        m_subdirs.m_pElements = m_pMemory;
        if ( m_Size - v14 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v14 + 1], src: &m_pMemory[v14], count: 4 * (m_Size - v14 - 1));
        v15 = &m_pMemory[v14];
        if ( v15 != nullptr )
          *v15 = v21;
        v2 = dir;
      }
    }
    while ( FindNextFileA(hFindFile: hFind, lpFindFileData: &FindFileData) );
    FindClose(hFindFile: hFind);
    if ( m_Size != 0 )
    {
      v16 = 4 * m_Size - 4;
      do
      {
        CVtexDialog::AddTargasInDir(this: v18, dir: *m_pMemory);
        free(pMem: *m_pMemory);
        if ( --m_Size > 0 )
          _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: v16);
        v16 -= 4;
      }
      while ( m_Size != 0 );
      m_subdirs.m_Size = 0;
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_subdirs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405410
// Name: public: void CVtexDialog::AddTarga(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVtexDialog::AddTarga(CVtexDialog *this@<ecx>, int a2@<ebx>, const char *path)
{
  char *v4; // edi
  const char *v5; // edi
  char *m_gameDir; // eax
  int v7; // ebx
  int v8; // eax
  KeyValues *v9; // edi
  const char *String; // eax
  const char *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  int v15; // [esp-8h] [ebp-21Ch]
  char filename[260]; // [esp+4h] [ebp-210h] BYREF
  char absPath[260]; // [esp+108h] [ebp-10Ch] BYREF
  char ext[8]; // [esp+20Ch] [ebp-8h] BYREF

  V_MakeAbsolutePath(pOut: absPath, outLen: 260, pPath: path, pStartingDir: nullptr);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: absPath, a3: nullptr) )
  {
    if ( (GetFileAttributesA(lpFileName: absPath) & 0x10) != 0 )
    {
      CVtexDialog::AddTargasInDir(this, dir: absPath);
    }
    else
    {
      memset(ext, 0, 6);
      V_ExtractFileExtension(path: absPath, dest: ext, destSize: 6);
      if ( _V_stricmp(s1: ext, s2: "tga") != 0 )
      {
        CVtexDialog::AddWarning(this, format: "%s is not a targa\n", absPath);
      }
      else
      {
        v4 = V_stristr(pStr: absPath, pSearch: "\\materialsrc\\");
        if ( v4 != nullptr && (v5 = &v4[_V_strlen(str: "\\materialsrc\\")]) != nullptr )
        {
          m_gameDir = this->m_gameDir;
          if ( m_gameDir != nullptr && *m_gameDir != 0 && !FStrEq(sz1: m_gameDir, sz2: TheVProjectDir) )
          {
            V_strncpy(pDest: filename, pSrc: v5, maxLen: 260);
            CVtexDialog::AddWarning(
              this,
              format: "%s has a different game dir (%s instead of %s)\n",
              filename,
              TheVProjectDir,
              this->m_gameDir);
          }
          else
          {
            CVtexDialog::SetGameDir(this, gameDir: TheVProjectDir);
            V_strncpy(pDest: filename, pSrc: v5, maxLen: 260);
            v7 = 0;
            v8 = ((int (__thiscall *)(vgui::ListPanel *, _DWORD, int))this->m_files->GetItemIDFromRow)(
                   a1: this->m_files,
                   a2: 0,
                   a3: a2);
            if ( v8 <= -1 )
            {
LABEL_16:
              v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v12 != nullptr )
                v13 = KeyValues::KeyValues(
                        this: v12,
                        setName: "data",
                        firstKey: "path",
                        firstValue: absPath,
                        secondKey: "filename",
                        secondValue: filename);
              else
                v13 = nullptr;
              ((void (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, int))this->m_files->AddItem)(
                a1: this->m_files,
                a2: v13,
                a3: 0,
                a4: 1);
            }
            else
            {
              while ( 1 )
              {
                ++v7;
                v9 = this->m_files->GetItem(this: this->m_files, a2: v8);
                String = KeyValues::GetString(this: v9, keyName: "path", defaultValue: defaultValue);
                if ( _V_stricmp(s1: String, s2: absPath) == 0 )
                {
                  v11 = KeyValues::GetString(this: v9, keyName: "filename", defaultValue: defaultValue);
                  if ( _V_stricmp(s1: v11, s2: filename) == 0 )
                    break;
                }
                v8 = ((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_files->GetItemIDFromRow)(
                       a1: this->m_files,
                       a2: v7,
                       a3: v15);
                if ( v8 <= -1 )
                  goto LABEL_16;
              }
            }
          }
        }
        else
        {
          CVtexDialog::AddWarning(this, format: "%s isn't in MaterialSrc\n", absPath);
        }
      }
    }
  }
  else
  {
    CVtexDialog::AddWarning(this, format: "Cannot find file %s\n", absPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004056A0
// Name: protected: virtual void CVtexDialog::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVtexDialog::OnFileSelected(CVtexDialog *this@<ecx>, int a2@<ebx>, const char *fullpath)
{
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    v4->SetVisible(this: v4, a2: false);
  }
  CVtexDialog::AddTarga(this, a2, path: fullpath);
}

//------------------------------------------------------------------------------
// Address: 0x00411A20
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x00411DB0
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  const char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411FA0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::HasHotkey(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00412220
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x00412800
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  const char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00412AC0
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x00412E90
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x00412EC0
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x00413340
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x00414C30
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x00414CA0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00414CF0
// Name: public: virtual struct vgui::DragDrop_t __near * vgui::Panel::GetDragDropInfo(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall vgui::Panel::GetDragDropInfo(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x004159E0
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00416B30
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)operator new(nSize: 0x24u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417310
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  const char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x004174D0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x004176A0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00417870
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00418120
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00418180
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419580
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004195C0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419600
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419640
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041EAD0
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  const char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
  return (vgui::Panel *)v21;
}

//------------------------------------------------------------------------------
// Address: 0x0041FFE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  CPanelMessageMapDictionary *PanelMessageMapDictionary; // eax
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  PanelMessageMapDictionary = GetPanelMessageMapDictionary();
  result = CPanelMessageMapDictionary::FindOrAddPanelMessageMap(this: PanelMessageMapDictionary, className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420010
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  CPanelKeyBindingMapDictionary *PanelKeyBindingMapDictionary; // eax
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  PanelKeyBindingMapDictionary = vgui::GetPanelKeyBindingMapDictionary();
  result = CPanelKeyBindingMapDictionary::FindOrAddPanelKeyBindingMap(
             this: PanelKeyBindingMapDictionary,
             className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004295E0
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00446300
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00449AA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449AD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x00449AE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004547B0
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x00455250
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00455280
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x00455290
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}
