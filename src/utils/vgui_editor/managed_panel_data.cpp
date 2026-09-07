// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vgui_editor/managed_panel_data.cpp
// Functions: 19
// ============================================================

#include "utils\vgui_editor\managed_panel_data.h"

//------------------------------------------------------------------------------
// Address: 0x00404070
// Name: public: void CManaged_Panel_Data::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_Data::LoadFromKeyValues(CManaged_Panel_Data *this, KeyValues *pKeys)
{
  const char *String; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  KeyValues *m_pResFileKeys; // ecx

  String = KeyValues::GetString(this: pKeys, keyName: "Name", defaultValue: "Unnamed");
  V_snprintf(pDest: this->m_szName, maxLen: 128, pFormat: "%s", String);
  v4 = KeyValues::GetString(this: pKeys, keyName: "ParentClass", defaultValue: "Unnamed");
  V_snprintf(pDest: this->m_szParentClass, maxLen: 128, pFormat: "%s", v4);
  v5 = KeyValues::GetString(this: pKeys, keyName: "SourceFile", defaultValue: "Unnamed");
  V_snprintf(pDest: this->m_szSourceFile, maxLen: 260, pFormat: "%s", v5);
  v6 = KeyValues::GetString(this: pKeys, keyName: "HeaderFile", defaultValue: "Unnamed");
  V_snprintf(pDest: this->m_szHeaderFile, maxLen: 260, pFormat: "%s", v6);
  v7 = KeyValues::GetString(this: pKeys, keyName: "ResFile", defaultValue: "Unnamed");
  V_snprintf(pDest: this->m_szResFile, maxLen: 260, pFormat: "%s", v7);
  m_pResFileKeys = this->m_pResFileKeys;
  if ( m_pResFileKeys != nullptr )
  {
    KeyValues::deleteThis(this: m_pResFileKeys);
    this->m_pResFileKeys = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404170
// Name: public: void CManaged_Panel_Data::SaveToKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_Data::SaveToKeyValues(CManaged_Panel_Data *this, KeyValues *pKeys)
{
  KeyValues::SetString(this: pKeys, keyName: "Name", value: this->m_szName);
  KeyValues::SetString(this: pKeys, keyName: "ParentClass", value: this->m_szParentClass);
  KeyValues::SetString(this: pKeys, keyName: "SourceFile", value: this->m_szSourceFile);
  KeyValues::SetString(this: pKeys, keyName: "HeaderFile", value: this->m_szHeaderFile);
  KeyValues::SetString(this: pKeys, keyName: "ResFile", value: this->m_szResFile);
}

//------------------------------------------------------------------------------
// Address: 0x004041E0
// Name: public: void CManaged_Panel_Data::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_Data::SetName(CManaged_Panel_Data *this, const char *szName)
{
  V_snprintf(pDest: this->m_szName, maxLen: 128, pFormat: "%s", szName);
}

//------------------------------------------------------------------------------
// Address: 0x00404200
// Name: public: void CManaged_Panel_Data::SetParentClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_Data::SetParentClass(CManaged_Panel_Data *this, const char *szParentClass)
{
  V_snprintf(pDest: this->m_szParentClass, maxLen: 128, pFormat: "%s", szParentClass);
}

//------------------------------------------------------------------------------
// Address: 0x00404230
// Name: public: char const __near * CManaged_Panel_Data::GetFullResFilename(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CManaged_Panel_Data::GetFullResFilename(CManaged_Panel_Data *this)
{
  const char *m_pszVMOD; // ebx
  CVGUI_Src_Editor *v3; // eax

  m_pszVMOD = VGUI_Src_Editor()->m_pszVMOD;
  v3 = VGUI_Src_Editor();
  V_snprintf(
    pDest: this->m_szFullResFilename,
    maxLen: 260,
    pFormat: "%s/%s/%s",
    v3->m_pszVGAME,
    m_pszVMOD,
    this->m_szResFile);
  return this->m_szFullResFilename;
}

//------------------------------------------------------------------------------
// Address: 0x00404280
// Name: public: class KeyValues __near * CManaged_Panel_Data::GetResFileKeys(bool)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CManaged_Panel_Data::GetResFileKeys(CManaged_Panel_Data *this, bool bForceReload)
{
  KeyValues *m_pResFileKeys; // ecx
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  const char *m_pszVMOD; // ebx
  CVGUI_Src_Editor *v7; // eax
  char *FullResFilename; // eax
  IBaseFileSystem *bForceReloada; // [esp+Ch] [ebp+8h]

  if ( bForceReload )
  {
    m_pResFileKeys = this->m_pResFileKeys;
    if ( m_pResFileKeys != nullptr )
    {
      KeyValues::deleteThis(this: m_pResFileKeys);
      this->m_pResFileKeys = nullptr;
    }
  }
  if ( this->m_pResFileKeys == nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ResFileKeys");
    else
      v5 = nullptr;
    this->m_pResFileKeys = v5;
    if ( g_pFullFileSystem != nullptr )
      bForceReloada = &g_pFullFileSystem->IBaseFileSystem;
    else
      bForceReloada = nullptr;
    m_pszVMOD = VGUI_Src_Editor()->m_pszVMOD;
    v7 = VGUI_Src_Editor();
    V_snprintf(
      pDest: this->m_szFullResFilename,
      maxLen: 260,
      pFormat: "%s/%s/%s",
      v7->m_pszVGAME,
      m_pszVMOD,
      this->m_szResFile);
    if ( !KeyValues::LoadFromFile(
            this: this->m_pResFileKeys,
            filesystem: bForceReloada,
            resourceName: this->m_szFullResFilename,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      FullResFilename = CManaged_Panel_Data::GetFullResFilename(this);
      _Warning(a1: "Error loading managed panel res file: %s\n", FullResFilename);
      KeyValues::deleteThis(this: this->m_pResFileKeys);
      this->m_pResFileKeys = nullptr;
    }
  }
  return this->m_pResFileKeys;
}

//------------------------------------------------------------------------------
// Address: 0x00404380
// Name: public: bool CManaged_Panel_Data::SaveResFileKeys(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManaged_Panel_Data::SaveResFileKeys(CManaged_Panel_Data *this)
{
  const char *m_pszVMOD; // esi
  CVGUI_Src_Editor *v4; // eax
  IBaseFileSystem *v5; // eax
  char szResFilename[260]; // [esp+4h] [ebp-104h] BYREF

  if ( CManaged_Panel_Data::GetResFileKeys(this, bForceReload: false) != nullptr )
  {
    m_pszVMOD = VGUI_Src_Editor()->m_pszVMOD;
    v4 = VGUI_Src_Editor();
    V_snprintf(pDest: szResFilename, maxLen: 260, pFormat: "%s/%s/%s", v4->m_pszVGAME, m_pszVMOD, this->m_szResFile);
    if ( p4 == nullptr || !p4->OpenFileForEdit(this: p4, a2: szResFilename) )
      _Warning(a1: "Unable to open for edit using p4: %s", szResFilename);
    if ( g_pFullFileSystem != nullptr )
      v5 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v5 = nullptr;
    if ( KeyValues::SaveToFile(this: this->m_pResFileKeys, filesystem: v5, resourceName: szResFilename, pathID: nullptr) )
    {
      return 1;
    }
    else
    {
      _Warning(a1: "Unable to save res file: %s\n", szResFilename);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Unable to save res file keys as GetResFileKeys is NULL\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404470
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004044B0
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004044E0
// Name: protected: bool CManaged_Panel_Data::CreateInitialCppFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManaged_Panel_Data::CreateInitialCppFile(CManaged_Panel_Data *this, const char *szFilename)
{
  char szHeaderBase[260]; // [esp+8h] [ebp-134h] BYREF
  CUtlBuffer output_buffer; // [esp+10Ch] [ebp-30h] BYREF

  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFilename, a3: nullptr) )
  {
    _Warning(a1: "Cpp file already exists: %s\n", szFilename);
    return 0;
  }
  else
  {
    CUtlBuffer::CUtlBuffer(this: &output_buffer, growSize: 0, initSize: 0, nFlags: 1);
    V_FileBase(in: this->m_szHeaderFile, out: szHeaderBase, maxlen: 260);
    V_SetExtension(path: szHeaderBase, extension: ".h", pathStringLength: 260);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "#include \"cbase.h\"\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "#include \"%s\"\n", szHeaderBase);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "// memdbgon must be the last include file in a .cpp file!!!\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "#include \"tier0/memdbgon.h\"\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
    CUtlBuffer::Printf(
      this: &output_buffer,
      pFmt: "C%s::C%s( vgui::Panel *parent, const char *name ) : BaseClass( parent, name )\n",
      this->m_szName,
      this->m_szName);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "{\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t// == MANAGED_MEMBER_CREATION_START: Do not edit by hand ==\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t// == MANAGED_MEMBER_CREATION_END ==\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "}\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "C%s::~C%s()\n", this->m_szName, this->m_szName);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "{\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "}\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
    CUtlBuffer::Printf(
      this: &output_buffer,
      pFmt: "void C%s::ApplySchemeSettings( vgui::IScheme *pScheme )\n",
      this->m_szName);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "{\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tBaseClass::ApplySchemeSettings( pScheme );\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tLoadControlSettings( \"%s\" );\n", this->m_szResFile);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "}\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "void C%s::PerformLayout()\n", this->m_szName);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "{\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tBaseClass::PerformLayout();\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "}\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "void C%s::OnThink()\n", this->m_szName);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "{\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tBaseClass::OnThink();\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "}\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "void C%s::OnCommand( const char *command )\n", this->m_szName);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "{\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tBaseClass::OnCommand( command );\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "}\n");
    if ( g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: szFilename,
           a3: nullptr,
           a4: &output_buffer) )
    {
      if ( p4 == nullptr || !p4->OpenFileForAdd(this: p4, a2: szFilename) )
        _Warning(a1: "Failed to open %s for add with P4\n", szFilename);
      if ( output_buffer.m_Memory.m_nGrowSize >= 0 && output_buffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_buffer.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      _Warning(a1: "Failed to write new cpp file: %s\n", szFilename);
      if ( output_buffer.m_Memory.m_nGrowSize >= 0 && output_buffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_buffer.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404840
// Name: protected: bool CManaged_Panel_Data::CreateInitialHFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManaged_Panel_Data::CreateInitialHFile(CManaged_Panel_Data *this, const char *szFilename)
{
  const char *v4; // [esp-8h] [ebp-140h]
  char szIncludeDefine[256]; // [esp+8h] [ebp-130h] BYREF
  CUtlBuffer output_buffer; // [esp+108h] [ebp-30h] BYREF

  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFilename, a3: nullptr) )
  {
    _Warning(a1: "H file already exists: %s\n", szFilename);
    return 0;
  }
  CUtlBuffer::CUtlBuffer(this: &output_buffer, growSize: 0, initSize: 0, nFlags: 1);
  V_snprintf(pDest: szIncludeDefine, maxLen: 256, pFormat: "_INCLUDED_%s_H", this->m_szName);
  _V_strupr(start: szIncludeDefine);
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "#ifndef %s\n", szIncludeDefine);
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "#define %s\n", szIncludeDefine);
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "#ifdef _WIN32\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "#pragma once\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "#endif\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "#include <vgui/VGUI.h>\n");
  if ( _V_stricmp(s1: this->m_szParentClass, s2: "vgui::EditablePanel") == 0 )
  {
    v4 = "#include <vgui_controls/EditablePanel.h>\n";
LABEL_11:
    CUtlBuffer::Printf(this: &output_buffer, pFmt: v4);
    goto LABEL_12;
  }
  if ( _V_stricmp(s1: this->m_szParentClass, s2: "vgui::Frame") == 0 )
  {
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "#include <vgui_controls/Frame.h>\n");
    goto LABEL_12;
  }
  if ( _V_stricmp(s1: this->m_szParentClass, s2: "vgui::Button") == 0 )
  {
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "#include <vgui_controls/Button.h>\n");
    goto LABEL_12;
  }
  if ( _V_stricmp(s1: this->m_szParentClass, s2: "vgui::Panel") == 0 )
  {
    v4 = "#include <vgui_controls/Panel.h>\n";
    goto LABEL_11;
  }
LABEL_12:
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "// == MANAGED_CLASS_DECLARATIONS_START: Do not edit by hand ==\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "// == MANAGED_CLASS_DECLARATIONS_END ==\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "class C%s : public %s\n", this->m_szName, this->m_szParentClass);
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "{\n");
  CUtlBuffer::Printf(
    this: &output_buffer,
    pFmt: "\tDECLARE_CLASS_SIMPLE( C%s, %s );\n",
    this->m_szName,
    this->m_szParentClass);
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "public:\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tC%s( vgui::Panel *parent, const char *name );\n", this->m_szName);
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tvirtual ~C%s();\n", this->m_szName);
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tvirtual void ApplySchemeSettings( vgui::IScheme *pScheme );\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tvirtual void PerformLayout();\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tvirtual void OnThink();\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\tvirtual void OnCommand( const char *command );\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t// == MANAGED_MEMBER_POINTERS_START: Do not edit by hand ==\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t// == MANAGED_MEMBER_POINTERS_END ==\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "};\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "\n");
  CUtlBuffer::Printf(this: &output_buffer, pFmt: "#endif // %s\n", szIncludeDefine);
  if ( g_pFullFileSystem->WriteFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: szFilename,
         a3: nullptr,
         a4: &output_buffer) )
  {
    if ( p4 == nullptr || !p4->OpenFileForAdd(this: p4, a2: szFilename) )
      _Warning(a1: "Failed to open %s for add with P4\n", szFilename);
    if ( output_buffer.m_Memory.m_nGrowSize >= 0 && output_buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_buffer.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    _Warning(a1: "Failed to write new h file: %s\n", szFilename);
    if ( output_buffer.m_Memory.m_nGrowSize >= 0 && output_buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_buffer.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404B80
// Name: protected: bool CManaged_Panel_Data::AddToVPC(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManaged_Panel_Data::AddToVPC(CManaged_Panel_Data *this)
{
  const char *m_pszVMOD; // esi
  CVGUI_Src_Editor *v3; // eax
  int v4; // edi
  char szFilename[260]; // [esp+Ch] [ebp-164h] BYREF
  CUtlBuffer output_buffer; // [esp+110h] [ebp-60h] BYREF
  CUtlBuffer input_buffer; // [esp+140h] [ebp-30h] BYREF

  m_pszVMOD = VGUI_Src_Editor()->m_pszVMOD;
  v3 = VGUI_Src_Editor();
  V_snprintf(pDest: szFilename, maxLen: 260, pFormat: "%s/game/client/client_%s.vpc", v3->m_pszVSRC, m_pszVMOD);
  v4 = 0;
  CUtlBuffer::CUtlBuffer(this: &input_buffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: szFilename,
          a3: nullptr,
          a4: &input_buffer,
          a5: 0,
          a6: 0,
          a7: nullptr) )
  {
    _Warning(a1: "Failed to open %s\n", szFilename);
    if ( input_buffer.m_Memory.m_nGrowSize >= 0 && input_buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_buffer.m_Memory.m_pMemory);
    return 0;
  }
  if ( p4 == nullptr || !p4->OpenFileForEdit(this: p4, a2: szFilename) )
    _Warning(a1: "Failed to open %s for edit with P4\n", szFilename);
  CUtlBuffer::CUtlBuffer(this: &output_buffer, growSize: 0, initSize: 0, nFlags: 1);
  while ( input_buffer.m_Error == 0 )
  {
    CUtlBuffer::GetLine(this: &input_buffer, pLine: lineBuf, nMaxChars: 10000);
    if ( lineBuf[0] != 10 )
    {
      if ( lineBuf[0] != 0 || input_buffer.m_Get == input_buffer.m_Put )
      {
        if ( lineBuf[_V_strlen(str: lineBuf) - 1] == 13 )
          lineBuf[_V_strlen(str: lineBuf) - 1] = 0;
        if ( v4 == 1 )
        {
          if ( _V_strstr(s1: lineBuf, search: "{") != nullptr )
            v4 = 2;
        }
        else if ( _V_strstr(s1: lineBuf, search: "$Folder") != nullptr
               && _V_strstr(s1: lineBuf, search: "\"ManagedPanels\"") != nullptr )
        {
          v4 = 1;
        }
        CUtlBuffer::Printf(this: &output_buffer, pFmt: "%s\n", lineBuf);
        if ( v4 == 2 )
        {
          CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t\t\t\t\t$file\t\"%s\"\n", this->m_szSourceFile);
          CUtlBuffer::Printf(this: &output_buffer, pFmt: "\t\t\t\t\t$file\t\"%s\"\n", this->m_szHeaderFile);
          v4 = 0;
        }
      }
      else if ( CUtlBuffer::CheckGet(this: &input_buffer, nSize: 1) )
      {
        ++input_buffer.m_Get;
      }
    }
  }
  if ( g_pFullFileSystem->WriteFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: szFilename,
         a3: nullptr,
         a4: &output_buffer) )
  {
    if ( output_buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( output_buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_buffer.m_Memory.m_pMemory);
        output_buffer.m_Memory.m_pMemory = nullptr;
      }
      output_buffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( input_buffer.m_Memory.m_nGrowSize >= 0 && input_buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_buffer.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    _Warning(a1: "Failed to rewrite vpc file: %s\n", szFilename);
    if ( output_buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( output_buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_buffer.m_Memory.m_pMemory);
        output_buffer.m_Memory.m_pMemory = nullptr;
      }
      output_buffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( input_buffer.m_Memory.m_nGrowSize < 0 || input_buffer.m_Memory.m_pMemory == nullptr )
      return 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_buffer.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404EC0
// Name: public: CManaged_Panel_Data::CManaged_Panel_Data(void)
// Source: json
//------------------------------------------------------------------------------
CManaged_Panel_Data *__thiscall CManaged_Panel_Data::CManaged_Panel_Data(CManaged_Panel_Data *this)
{
  this->m_Children.m_Memory.m_pMemory = nullptr;
  this->m_Children.m_Memory.m_nAllocationCount = 0;
  this->m_Children.m_Memory.m_nGrowSize = 0;
  this->m_Children.m_Size = 0;
  this->m_Children.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_szParentClass[0] = 0;
  this->m_szSourceFile[0] = 0;
  this->m_szHeaderFile[0] = 0;
  this->m_szResFile[0] = 0;
  this->m_pResFileKeys = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404F10
// Name: public: CManaged_Panel_Data::~CManaged_Panel_Data(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_Data::~CManaged_Panel_Data(CManaged_Panel_Data *this)
{
  KeyValues *m_pResFileKeys; // ecx

  m_pResFileKeys = this->m_pResFileKeys;
  if ( m_pResFileKeys != nullptr )
  {
    KeyValues::deleteThis(this: m_pResFileKeys);
    this->m_pResFileKeys = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Children);
}

//------------------------------------------------------------------------------
// Address: 0x00404F40
// Name: protected: bool CManaged_Panel_Data::CreateInitialResFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManaged_Panel_Data::CreateInitialResFile(CManaged_Panel_Data *this, const char *szFilename)
{
  CUtlBuffer output_buffer; // [esp+8h] [ebp-30h] BYREF

  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFilename, a3: nullptr) )
  {
    _Warning(a1: "Res file already exists: %s\n", szFilename);
    return 0;
  }
  else
  {
    CUtlBuffer::CUtlBuffer(this: &output_buffer, growSize: 0, initSize: 0, nFlags: 1);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "\"Resource/UI/%s.res\"\n", this->m_szName);
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "{\n");
    CUtlBuffer::Printf(this: &output_buffer, pFmt: "}\n");
    if ( g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: szFilename,
           a3: nullptr,
           a4: &output_buffer) )
    {
      if ( p4 == nullptr || !p4->OpenFileForAdd(this: p4, a2: szFilename) )
        _Warning(a1: "Failed to open %s for add with P4\n", szFilename);
      if ( output_buffer.m_Memory.m_nGrowSize >= 0 && output_buffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_buffer.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      _Warning(a1: "Failed to write new res file: %s\n", szFilename);
      if ( output_buffer.m_Memory.m_nGrowSize >= 0 && output_buffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_buffer.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405060
// Name: public: bool CManaged_Panel_Data::CreateInitialFiles(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManaged_Panel_Data::CreateInitialFiles(CManaged_Panel_Data *this)
{
  char *m_szResFile; // edi
  CVGUI_Src_Editor *v3; // eax
  CVGUI_Src_Editor *v4; // eax
  CVGUI_Src_Editor *v5; // eax
  CVGUI_Src_Editor *v7; // eax
  CVGUI_Src_Editor *v8; // eax
  CVGUI_Src_Editor *v9; // eax
  char pCommand[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char szFilename[260]; // [esp+110h] [ebp-108h] BYREF
  const char *m_pszVMOD; // [esp+214h] [ebp-4h]

  m_szResFile = this->m_szResFile;
  V_snprintf(pDest: this->m_szResFile, maxLen: 260, pFormat: "resource/UI/%s.res", this->m_szName);
  _V_strlower(start: m_szResFile);
  v3 = VGUI_Src_Editor();
  V_snprintf(pDest: this->m_szSourceFile, maxLen: 260, pFormat: "%s/vgui/%s.cpp", v3->m_pszVMOD, this->m_szName);
  _V_strlower(start: this->m_szSourceFile);
  v4 = VGUI_Src_Editor();
  V_snprintf(pDest: this->m_szHeaderFile, maxLen: 260, pFormat: "%s/vgui/%s.h", v4->m_pszVMOD, this->m_szName);
  _V_strlower(start: this->m_szHeaderFile);
  m_pszVMOD = VGUI_Src_Editor()->m_pszVMOD;
  v5 = VGUI_Src_Editor();
  V_snprintf(pDest: szFilename, maxLen: 260, pFormat: "%s/%s/%s", v5->m_pszVGAME, m_pszVMOD, m_szResFile);
  if ( CManaged_Panel_Data::CreateInitialResFile(this, szFilename) != 0 )
  {
    v7 = VGUI_Src_Editor();
    V_snprintf(pDest: szFilename, maxLen: 260, pFormat: "%s/game/client/%s", v7->m_pszVSRC, this->m_szSourceFile);
    _V_strlower(start: szFilename);
    if ( CManaged_Panel_Data::CreateInitialCppFile(this, szFilename) != 0 )
    {
      v8 = VGUI_Src_Editor();
      V_snprintf(pDest: szFilename, maxLen: 260, pFormat: "%s/game/client/%s", v8->m_pszVSRC, this->m_szHeaderFile);
      _V_strlower(start: szFilename);
      if ( CManaged_Panel_Data::CreateInitialHFile(this, szFilename) != 0 )
      {
        if ( CManaged_Panel_Data::AddToVPC(this) != 0 )
        {
          V_snprintf(pDest: pCommand, maxLen: 260, pFormat: "+everything /allgames");
          v9 = VGUI_Src_Editor();
          ShellExecuteA(
            hwnd: nullptr,
            lpOperation: nullptr,
            lpFile: "vpc.exe",
            lpParameters: "+everything /allgames",
            lpDirectory: v9->m_pszVSRC,
            nShowCmd: 1);
        }
        else
        {
          _Warning(a1: "Failed to add to vpc file\n");
        }
        return 1;
      }
      else
      {
        _Warning(a1: "Error creating .h file: %s\n", szFilename);
        return 0;
      }
    }
    else
    {
      _Warning(a1: "Error creating .cpp file: %s\n", szFilename);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Error creating .res file: %s\n", szFilename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405280
// Name: public: bool CManaged_Panel_Data::LoadChildren(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManaged_Panel_Data::LoadChildren(CManaged_Panel_Data *this)
{
  CVGUI_Src_Editor *v2; // eax
  int v3; // edi
  CManaged_Panel_Child *v5; // ebx
  int v6; // eax
  int v7; // esi
  char v8; // dl
  char *v9; // eax
  char *v10; // esi
  int v11; // ebx
  int v12; // eax
  int i; // edi
  char v14; // cl
  CManaged_Panel_Child *v15; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v16; // edi
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v19; // ecx
  int v20; // eax
  CManaged_Panel_Child **v21; // eax
  char **v22; // eax
  char *v23; // [esp-Ch] [ebp-168h]
  char szHFilename[260]; // [esp+8h] [ebp-154h] BYREF
  CUtlBuffer input_h; // [esp+10Ch] [ebp-50h] BYREF
  CUtlMemory<vgui::TreeNode *,int> *p_m_Children; // [esp+13Ch] [ebp-20h]
  CManaged_Panel_Child *pChild; // [esp+140h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > words; // [esp+144h] [ebp-18h] BYREF
  bool bReadingMembers; // [esp+15Bh] [ebp-1h]

  p_m_Children = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Children;
  CUtlVector<visualized_panel_t *,CUtlMemory<visualized_panel_t *,int>>::PurgeAndDeleteElements(this: &this->m_Children);
  v2 = VGUI_Src_Editor();
  V_snprintf(pDest: szHFilename, maxLen: 260, pFormat: "%s/game/client/%s", v2->m_pszVSRC, this->m_szHeaderFile);
  _V_strlower(start: szHFilename);
  v3 = 0;
  CUtlBuffer::CUtlBuffer(this: &input_h, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: szHFilename,
         a3: nullptr,
         a4: &input_h,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    bReadingMembers = false;
    while ( input_h.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &input_h, pLine: lineBuf_0, nMaxChars: 10000);
      if ( lineBuf_0[0] != 10 )
      {
        if ( lineBuf_0[0] != 0 || input_h.m_Get == input_h.m_Put )
        {
          if ( lineBuf_0[_V_strlen(str: lineBuf_0) - 1] == 13 )
            lineBuf_0[_V_strlen(str: lineBuf_0) - 1] = 0;
          if ( bReadingMembers )
          {
            if ( _V_strstr(s1: lineBuf_0, search: "MANAGED_MEMBER_POINTERS_END") != nullptr )
            {
              bReadingMembers = false;
            }
            else
            {
              memset(&words, 0, sizeof(words));
              V_SplitString(pString: lineBuf_0, pSeparator: "*", outStrings: &words);
              if ( words.m_Size == 2 )
              {
                v5 = (CManaged_Panel_Child *)operator new(nSize: 0x100u);
                v23 = *words.m_Memory.m_pMemory;
                pChild = v5;
                v6 = _V_strlen(str: v23);
                v7 = 0;
                if ( v6 > 0 )
                {
                  do
                  {
                    v8 = (*words.m_Memory.m_pMemory)[v3];
                    if ( v8 < 9 || v8 > 13 && v8 != 32 )
                      v5->m_szClassName[v7++] = v8;
                    ++v3;
                  }
                  while ( v3 < v6 );
                }
                v5->m_szClassName[v7] = 0;
                v9 = _V_strstr(s1: *((const char **)words.m_Memory.m_pMemory + 1), search: "m_p");
                if ( v9 != nullptr )
                {
                  v10 = v9 + 3;
                  v11 = _V_strlen(str: v9 + 3);
                  v12 = 0;
                  for ( i = 0; i < v11; ++i )
                  {
                    v14 = v10[i];
                    if ( (v14 < 9 || v14 > 13 && v14 != 32) && v14 != 59 )
                      pChild->m_szName[v12++] = v14;
                  }
                  v15 = pChild;
                  v16 = p_m_Children;
                  pChild->m_szName[v12] = 0;
                  m_pMemory = v16[1].m_pMemory;
                  m_nAllocationCount = v16->m_nAllocationCount;
                  if ( (int)m_pMemory + 1 > m_nAllocationCount )
                    CUtlMemory<unsigned long,int>::Grow(this: v16, num: (int)m_pMemory - m_nAllocationCount + 1);
                  ++v16[1].m_pMemory;
                  v19 = v16->m_pMemory;
                  v20 = (char *)v16[1].m_pMemory - (char *)m_pMemory - 1;
                  v16[1].m_nAllocationCount = (int)v16->m_pMemory;
                  if ( v20 > 0 )
                    _V_memmove(dest: &v19[(_DWORD)m_pMemory + 1], src: &v19[(_DWORD)m_pMemory], count: 4 * v20);
                  v21 = (CManaged_Panel_Child **)&v16->m_pMemory[(_DWORD)m_pMemory];
                  v3 = 0;
                  if ( v21 != nullptr )
                    *v21 = v15;
                }
                else
                {
                  _Warning(a1: "Failed to extra a member pointer to a managed child in header file\n");
                  v3 = 0;
                }
              }
              else
              {
                _Warning(a1: "Bad managed member pointer line:\n%s\n", lineBuf_0);
              }
              CUtlVector<visualized_panel_t *,CUtlMemory<visualized_panel_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<CManaged_Panel_Child *,CUtlMemory<CManaged_Panel_Child *,int> > *)&words);
              v22 = words.m_Memory.m_pMemory;
              words.m_Size = 0;
              if ( words.m_Memory.m_nGrowSize >= 0 )
              {
                if ( words.m_Memory.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: words.m_Memory.m_pMemory);
                  v22 = nullptr;
                  words.m_Memory.m_pMemory = nullptr;
                }
                words.m_Memory.m_nAllocationCount = 0;
              }
              words.m_pElements = v22;
              if ( words.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
            }
          }
          else
          {
            bReadingMembers = _V_strstr(s1: lineBuf_0, search: "MANAGED_MEMBER_POINTERS_START") != nullptr;
          }
        }
        else if ( CUtlBuffer::CheckGet(this: &input_h, nSize: 1) )
        {
          ++input_h.m_Get;
        }
      }
    }
    if ( input_h.m_Memory.m_nGrowSize >= 0 && input_h.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_h.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    _Warning(a1: "Failed to open %s\n", szHFilename);
    if ( input_h.m_Memory.m_nGrowSize >= 0 && input_h.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_h.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004055E0
// Name: public: bool CManaged_Panel_Data::SaveChildren(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManaged_Panel_Data::SaveChildren(CManaged_Panel_Data *this)
{
  CVGUI_Src_Editor *v2; // eax
  CVGUI_Src_Editor *v4; // eax
  char v5; // bl
  int j; // edi
  int k; // ebx
  int v8; // edi
  int m; // ebx
  int v10; // edi
  CManaged_Panel_Child *v11; // edi
  CManaged_Panel_Child *v12; // edi
  int v13; // ebx
  KeyValues *Key; // edi
  KeyValues *v15; // eax
  const char *v16; // [esp-14h] [ebp-304h]
  char *v17; // [esp-10h] [ebp-300h]
  CManaged_Panel_Child *v18; // [esp-Ch] [ebp-2FCh]
  char *m_szName; // [esp-8h] [ebp-2F8h]
  char szCPPFilename[260]; // [esp+8h] [ebp-2E8h] BYREF
  char szHFilename[260]; // [esp+10Ch] [ebp-1E4h] BYREF
  CUtlBuffer input_cpp; // [esp+210h] [ebp-E0h] BYREF
  CUtlBuffer output_cpp; // [esp+240h] [ebp-B0h] BYREF
  CUtlBuffer output_h; // [esp+270h] [ebp-80h] BYREF
  CUtlVector<char const *,CUtlMemory<char const *,int> > aIncludes; // [esp+2A0h] [ebp-50h] BYREF
  CUtlBuffer input_h; // [esp+2B4h] [ebp-3Ch] BYREF
  KeyValues *pResFileKeys; // [esp+2E4h] [ebp-Ch]
  int i; // [esp+2E8h] [ebp-8h]
  bool bReadingMembers; // [esp+2EEh] [ebp-2h]
  bool bReadingDeclarations; // [esp+2EFh] [ebp-1h]

  pResFileKeys = CManaged_Panel_Data::GetResFileKeys(this, bForceReload: true);
  if ( pResFileKeys == nullptr )
    return 0;
  v2 = VGUI_Src_Editor();
  V_snprintf(pDest: szCPPFilename, maxLen: 260, pFormat: "%s/game/client/%s", v2->m_pszVSRC, this->m_szSourceFile);
  _V_strlower(start: szCPPFilename);
  CUtlBuffer::CUtlBuffer(this: &input_cpp, growSize: 0, initSize: 0, nFlags: 0);
  if ( !g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: szCPPFilename,
          a3: nullptr,
          a4: &input_cpp,
          a5: 0,
          a6: 0,
          a7: nullptr) )
  {
    _Warning(a1: "Failed to open %s\n", szCPPFilename);
    if ( input_cpp.m_Memory.m_nGrowSize >= 0 && input_cpp.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_cpp.m_Memory.m_pMemory);
    return 0;
  }
  v4 = VGUI_Src_Editor();
  V_snprintf(pDest: szHFilename, maxLen: 260, pFormat: "%s/game/client/%s", v4->m_pszVSRC, this->m_szHeaderFile);
  _V_strlower(start: szHFilename);
  CUtlBuffer::CUtlBuffer(this: &input_h, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: szHFilename,
         a3: nullptr,
         a4: &input_h,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( p4 == nullptr || !p4->OpenFileForEdit(this: p4, a2: szHFilename) )
      _Warning(a1: "Failed to open %s for edit with P4\n", szHFilename);
    CUtlBuffer::CUtlBuffer(this: &output_h, growSize: 0, initSize: 0, nFlags: 1);
    bReadingMembers = false;
    bReadingDeclarations = false;
    while ( input_h.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &input_h, pLine: lineBuf_2, nMaxChars: 10000);
      if ( lineBuf_2[0] != 10 )
      {
        if ( lineBuf_2[0] != 0 || input_h.m_Get == input_h.m_Put )
        {
          if ( lineBuf_2[_V_strlen(str: lineBuf_2) - 1] == 13 )
            lineBuf_2[_V_strlen(str: lineBuf_2) - 1] = 0;
          v5 = 1;
          if ( bReadingMembers )
          {
            if ( _V_strstr(s1: lineBuf_2, search: "MANAGED_MEMBER_POINTERS_END") != nullptr )
              bReadingMembers = false;
            else
              v5 = 0;
          }
          else if ( _V_strstr(s1: lineBuf_2, search: "MANAGED_MEMBER_POINTERS_START") != nullptr )
          {
            bReadingMembers = true;
            v5 = 0;
            CUtlBuffer::Printf(this: &output_h, pFmt: "%s\n", lineBuf_2);
            for ( j = 0; j < this->m_Children.m_Size; ++j )
              CUtlBuffer::Printf(
                this: &output_h,
                pFmt: "\t%s\t*m_p%s;\n",
                this->m_Children.m_Memory.m_pMemory[j]->m_szClassName,
                this->m_Children.m_Memory.m_pMemory[j]->m_szName);
          }
          if ( !bReadingDeclarations )
          {
            if ( _V_strstr(s1: lineBuf_2, search: "MANAGED_CLASS_DECLARATIONS_START") != nullptr )
            {
              bReadingDeclarations = true;
              CUtlBuffer::Printf(this: &output_h, pFmt: "%s\n", lineBuf_2);
              for ( k = 0; k < this->m_Children.m_Size; ++k )
              {
                v8 = 0;
                if ( k <= 0 )
                {
LABEL_46:
                  CUtlBuffer::Printf(
                    this: &output_h,
                    pFmt: "class %s;\n",
                    this->m_Children.m_Memory.m_pMemory[k]->m_szClassName);
                }
                else
                {
                  while ( _V_stricmp(
                            s1: this->m_Children.m_Memory.m_pMemory[k]->m_szClassName,
                            s2: this->m_Children.m_Memory.m_pMemory[v8]->m_szClassName) != 0 )
                  {
                    if ( ++v8 >= k )
                      goto LABEL_46;
                  }
                }
              }
              continue;
            }
            goto LABEL_36;
          }
          if ( _V_strstr(s1: lineBuf_2, search: "MANAGED_CLASS_DECLARATIONS_END") != nullptr )
          {
            bReadingDeclarations = false;
LABEL_36:
            if ( v5 != 0 )
              CUtlBuffer::Printf(this: &output_h, pFmt: "%s\n", lineBuf_2);
          }
        }
        else if ( CUtlBuffer::CheckGet(this: &input_h, nSize: 1) )
        {
          ++input_h.m_Get;
        }
      }
    }
    if ( !g_pFullFileSystem->WriteFile(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: szHFilename,
            a3: nullptr,
            a4: &output_h) )
    {
      _Warning(a1: "Failed to rewrite h file: %s\n", szHFilename);
      goto LABEL_71;
    }
    if ( p4 == nullptr || !p4->OpenFileForEdit(this: p4, a2: szCPPFilename) )
      _Warning(a1: "Failed to open %s for edit with P4\n", szCPPFilename);
    memset(&aIncludes, 0, sizeof(aIncludes));
    CUtlBuffer::CUtlBuffer(this: &output_cpp, growSize: 0, initSize: 0, nFlags: 1);
    bReadingDeclarations = false;
    if ( input_cpp.m_Error != 0 )
    {
LABEL_65:
      if ( g_pFullFileSystem->WriteFile(
             this: &g_pFullFileSystem->IBaseFileSystem,
             a2: szCPPFilename,
             a3: nullptr,
             a4: &output_cpp) )
      {
        for ( i = 0; i < this->m_Children.m_Size; ++i )
        {
          v13 = i;
          Key = KeyValues::FindKey(
                  this: pResFileKeys,
                  keyName: this->m_Children.m_Memory.m_pMemory[i]->m_szName,
                  bCreate: false);
          if ( Key == nullptr )
          {
            v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            Key = v15 != nullptr
                ? KeyValues::KeyValues(this: v15, setName: this->m_Children.m_Memory.m_pMemory[v13]->m_szName)
                : nullptr;
            KeyValues::AddSubKey(this: pResFileKeys, pSubkey: Key);
            KeyValues::SetString(
              this: Key,
              keyName: "fieldName",
              value: this->m_Children.m_Memory.m_pMemory[v13]->m_szName);
            KeyValues::SetInt(this: Key, keyName: "xpos", value: 0);
            KeyValues::SetInt(this: Key, keyName: "ypos", value: 0);
            KeyValues::SetInt(this: Key, keyName: "wide", value: 100);
            KeyValues::SetInt(this: Key, keyName: "tall", value: 100);
            if ( _V_stricmp(s1: this->m_Children.m_Memory.m_pMemory[v13]->m_szClassName, s2: "vgui::Label") == 0 )
            {
              KeyValues::SetString(this: Key, keyName: "font", value: "Default");
              KeyValues::SetString(
                this: Key,
                keyName: "labelText",
                value: this->m_Children.m_Memory.m_pMemory[v13]->m_szName);
              KeyValues::SetString(this: Key, keyName: "textAlignment", value: "center");
            }
          }
          if ( V_strncmp(s1: this->m_Children.m_Memory.m_pMemory[v13]->m_szClassName, s2: "vgui::", count: 6) != 0 )
            KeyValues::SetString(
              this: Key,
              keyName: "ControlName",
              value: this->m_Children.m_Memory.m_pMemory[v13]->m_szClassName);
          else
            KeyValues::SetString(
              this: Key,
              keyName: "ControlName",
              value: &this->m_Children.m_Memory.m_pMemory[v13]->m_szClassName[6]);
        }
        if ( CManaged_Panel_Data::SaveResFileKeys(this) != 0 )
        {
          if ( output_cpp.m_Memory.m_nGrowSize >= 0 )
          {
            if ( output_cpp.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_cpp.m_Memory.m_pMemory);
              output_cpp.m_Memory.m_pMemory = nullptr;
            }
            output_cpp.m_Memory.m_nAllocationCount = 0;
          }
          if ( aIncludes.m_Memory.m_nGrowSize >= 0 && aIncludes.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: aIncludes.m_Memory.m_pMemory);
          if ( output_h.m_Memory.m_nGrowSize >= 0 )
          {
            if ( output_h.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_h.m_Memory.m_pMemory);
              output_h.m_Memory.m_pMemory = nullptr;
            }
            output_h.m_Memory.m_nAllocationCount = 0;
          }
          if ( input_h.m_Memory.m_nGrowSize >= 0 )
          {
            if ( input_h.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_h.m_Memory.m_pMemory);
              input_h.m_Memory.m_pMemory = nullptr;
            }
            input_h.m_Memory.m_nAllocationCount = 0;
          }
          if ( input_cpp.m_Memory.m_nGrowSize >= 0 && input_cpp.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_cpp.m_Memory.m_pMemory);
          return 1;
        }
        if ( output_cpp.m_Memory.m_nGrowSize >= 0 )
        {
          if ( output_cpp.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_cpp.m_Memory.m_pMemory);
            output_cpp.m_Memory.m_pMemory = nullptr;
          }
          output_cpp.m_Memory.m_nAllocationCount = 0;
        }
        if ( aIncludes.m_Memory.m_nGrowSize >= 0 && aIncludes.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: aIncludes.m_Memory.m_pMemory);
        if ( output_h.m_Memory.m_nGrowSize >= 0 )
        {
          if ( output_h.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_h.m_Memory.m_pMemory);
            output_h.m_Memory.m_pMemory = nullptr;
          }
          output_h.m_Memory.m_nAllocationCount = 0;
        }
        if ( input_h.m_Memory.m_nGrowSize >= 0 )
        {
          if ( input_h.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_h.m_Memory.m_pMemory);
            input_h.m_Memory.m_pMemory = nullptr;
          }
          input_h.m_Memory.m_nAllocationCount = 0;
        }
        if ( input_cpp.m_Memory.m_nGrowSize >= 0 && input_cpp.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_cpp.m_Memory.m_pMemory);
        return 0;
      }
      _Warning(a1: "Failed to rewrite cpp file: %s\n", szCPPFilename);
      if ( output_cpp.m_Memory.m_nGrowSize >= 0 )
      {
        if ( output_cpp.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_cpp.m_Memory.m_pMemory);
          output_cpp.m_Memory.m_pMemory = nullptr;
        }
        output_cpp.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&aIncludes);
LABEL_71:
      if ( output_h.m_Memory.m_nGrowSize >= 0 )
      {
        if ( output_h.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: output_h.m_Memory.m_pMemory);
          output_h.m_Memory.m_pMemory = nullptr;
        }
        output_h.m_Memory.m_nAllocationCount = 0;
      }
      if ( input_h.m_Memory.m_nGrowSize >= 0 )
      {
        if ( input_h.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_h.m_Memory.m_pMemory);
          input_h.m_Memory.m_pMemory = nullptr;
        }
        input_h.m_Memory.m_nAllocationCount = 0;
      }
      if ( input_cpp.m_Memory.m_nGrowSize >= 0 && input_cpp.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_cpp.m_Memory.m_pMemory);
        return 0;
      }
      return 0;
    }
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: &input_cpp, pLine: lineBuf_1, nMaxChars: 10000);
      if ( lineBuf_1[0] != 10 )
      {
        if ( lineBuf_1[0] == 0 && input_h.m_Get != input_h.m_Put )
        {
          if ( CUtlBuffer::CheckGet(this: &input_h, nSize: 1) )
            ++input_h.m_Get;
          goto LABEL_64;
        }
        if ( lineBuf_1[_V_strlen(str: lineBuf_1) - 1] == 13 )
          lineBuf_1[_V_strlen(str: lineBuf_1) - 1] = 0;
        if ( !bReadingDeclarations )
        {
          if ( _V_strstr(s1: lineBuf_1, search: "MANAGED_MEMBER_CREATION_START") != nullptr )
          {
            bReadingDeclarations = true;
            CUtlBuffer::Printf(this: &output_cpp, pFmt: "%s\n", lineBuf_1);
            for ( m = 0; m < this->m_Children.m_Size; ++m )
            {
              v10 = m;
              if ( _V_stricmp(s1: this->m_Children.m_Memory.m_pMemory[m]->m_szClassName, s2: "vgui::Label") != 0
                && _V_stricmp(s1: this->m_Children.m_Memory.m_pMemory[m]->m_szClassName, s2: "vgui::CheckButton") != 0
                && _V_stricmp(s1: this->m_Children.m_Memory.m_pMemory[m]->m_szClassName, s2: "CBitmapButton") != 0 )
              {
                if ( _V_stricmp(s1: this->m_Children.m_Memory.m_pMemory[m]->m_szClassName, s2: "vgui::Button") != 0 )
                {
                  if ( _V_stricmp(s1: this->m_Children.m_Memory.m_pMemory[m]->m_szClassName, s2: "vgui::ComboBox") != 0 )
                  {
                    v12 = this->m_Children.m_Memory.m_pMemory[v10];
                    m_szName = v12->m_szName;
                    v18 = v12;
                    v17 = v12->m_szName;
                    v16 = "\tm_p%s = new %s( this, \"%s\" );\n";
                  }
                  else
                  {
                    v11 = this->m_Children.m_Memory.m_pMemory[v10];
                    m_szName = v11->m_szName;
                    v18 = v11;
                    v17 = v11->m_szName;
                    v16 = "\tm_p%s = new %s( this, \"%s\", 0, true );\n";
                  }
                  CUtlBuffer::Printf(this: &output_cpp, pFmt: v16, v17, v18, m_szName);
                }
                else
                {
                  CUtlBuffer::Printf(
                    this: &output_cpp,
                    pFmt: "\tm_p%s = new %s( this, \"%s\", \"\", this, \"%s\" );\n",
                    this->m_Children.m_Memory.m_pMemory[v10]->m_szName,
                    this->m_Children.m_Memory.m_pMemory[v10]->m_szClassName,
                    this->m_Children.m_Memory.m_pMemory[v10]->m_szName,
                    this->m_Children.m_Memory.m_pMemory[v10]->m_szName);
                }
              }
              else
              {
                CUtlBuffer::Printf(
                  this: &output_cpp,
                  pFmt: "\tm_p%s = new %s( this, \"%s\", \"\" );\n",
                  this->m_Children.m_Memory.m_pMemory[v10]->m_szName,
                  this->m_Children.m_Memory.m_pMemory[v10],
                  this->m_Children.m_Memory.m_pMemory[v10]->m_szName);
              }
            }
            goto LABEL_64;
          }
          goto LABEL_63;
        }
        if ( _V_strstr(s1: lineBuf_1, search: "MANAGED_MEMBER_CREATION_END") != nullptr )
        {
          bReadingDeclarations = false;
LABEL_63:
          CUtlBuffer::Printf(this: &output_cpp, pFmt: "%s\n", lineBuf_1);
        }
      }
LABEL_64:
      if ( input_cpp.m_Error != 0 )
        goto LABEL_65;
    }
  }
  _Warning(a1: "Failed to open %s\n", szHFilename);
  if ( input_h.m_Memory.m_nGrowSize >= 0 )
  {
    if ( input_h.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_h.m_Memory.m_pMemory);
      input_h.m_Memory.m_pMemory = nullptr;
    }
    input_h.m_Memory.m_nAllocationCount = 0;
  }
  if ( input_cpp.m_Memory.m_nGrowSize < 0 || input_cpp.m_Memory.m_pMemory == nullptr )
    return 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: input_cpp.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406060
// Name: public: void CManaged_Panel_Data::CreateNewManagedChild(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_Data::CreateNewManagedChild(
        CManaged_Panel_Data *this,
        const char *szName,
        const char *szPanelClass)
{
  char *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CManaged_Panel_Child **m_pMemory; // ecx
  int v8; // eax
  CManaged_Panel_Child **v9; // edi

  v4 = (char *)operator new(nSize: 0x100u);
  V_snprintf(pDest: v4 + 128, maxLen: 128, pFormat: "%s", szName);
  V_snprintf(pDest: v4, maxLen: 128, pFormat: "%s", szPanelClass);
  m_Size = this->m_Children.m_Size;
  m_nAllocationCount = this->m_Children.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Children,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Children.m_Size;
  m_pMemory = this->m_Children.m_Memory.m_pMemory;
  v8 = this->m_Children.m_Size - m_Size - 1;
  this->m_Children.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_Children.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (CManaged_Panel_Child *)v4;
  if ( CManaged_Panel_Data::SaveChildren(this) == 0 )
    _Msg(a1: "Failed to save children after adding a new managed child (%s, %s)\n", szName, szPanelClass);
}
