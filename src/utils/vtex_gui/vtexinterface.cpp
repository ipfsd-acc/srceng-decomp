// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vtex_gui/vtexinterface.cpp
// Functions: 40
// ============================================================

#include "utils\vtex_gui\vtexinterface.h"

//------------------------------------------------------------------------------
// Address: 0x00404850
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405710
// Name: void __near * filesystemFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl filesystemFactory(const char *interfaceName)
{
  return _V_stricmp(s1: interfaceName, s2: "VFileSystem017") == 0 ? g_pFullFileSystem : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405740
// Name: private: void CVtexDialog::LoadVTex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::LoadVTex(CVtexDialog *this)
{
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IVTex *v4; // eax

  if ( this->m_vtexModule == nullptr && this->m_vtex == nullptr )
  {
    Module = Sys_LoadModule(pModuleName: "vtex_dll");
    this->m_vtexModule = Module;
    if ( Module != nullptr )
    {
      Factory = Sys_GetFactory(pModule: Module);
      if ( Factory != nullptr )
      {
        v4 = (IVTex *)Factory(a1: "VTEX_003", a2: nullptr);
        this->m_vtex = v4;
        if ( v4 == nullptr )
        {
          CVtexDialog::AddWarning(this, format: "Cannot get interface %s from vtex.dll\n", "VTEX_003");
          Sys_UnloadModule(pModule: this->m_vtexModule);
          this->m_vtexModule = nullptr;
        }
      }
      else
      {
        CVtexDialog::AddWarning(this, format: "Cannot get factory from vtex.dll\n");
        Sys_UnloadModule(pModule: this->m_vtexModule);
        this->m_vtexModule = nullptr;
      }
    }
    else
    {
      CVtexDialog::AddWarning(this, format: "Cannot load vtex.dll\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405800
// Name: private: void CVtexDialog::UnloadVTex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::UnloadVTex(CVtexDialog *this)
{
  if ( this->m_vtexModule != nullptr )
    Sys_UnloadModule(pModule: this->m_vtexModule);
  this->m_vtex = nullptr;
  this->m_vtexModule = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405830
// Name: public: void CUtlMemory<struct CVtexDialog::PathElement,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CVtexDialog::PathElement,int>::Grow(
        CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004058D0
// Name: private: bool CVtexDialog::RemoveOutputFile(char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVtexDialog::RemoveOutputFile(CVtexDialog *this, char *path, int bytes, const char *extension)
{
  CP4File *v4; // edi

  V_StripExtension(in: path, out: path, outSize: bytes);
  V_strncat(pDest: path, pSrc: extension, destBufferSize: bytes, max_chars_to_copy: -1);
  V_FixSlashes(pname: path, separator: 92);
  v4 = CP4Factory::AccessFile(this: g_p4factory, szFilename: path);
  v4->Edit(this: v4);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: path, a3: nullptr)
    && (unlink(path), g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: path, a3: nullptr)) )
  {
    v4->Add(this: v4);
    ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
    return 0;
  }
  else
  {
    v4->Add(this: v4);
    ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405990
// Name: private: void CVtexDialog::RemoveTargaFromQueue(struct CVtexDialog::PathElement __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::RemoveTargaFromQueue(CVtexDialog *this, CVtexDialog::PathElement *pathElement)
{
  int v3; // edi
  void **m_VMTArguments; // ebx

  if ( this->m_filesToProcess.m_Size - 1 > 0 )
    _V_memmove(
      dest: this->m_filesToProcess.m_Memory.m_pMemory,
      src: &this->m_filesToProcess.m_Memory.m_pMemory[1],
      count: 8 * (this->m_filesToProcess.m_Size - 1));
  --this->m_filesToProcess.m_Size;
  free(pMem: pathElement->fullPath);
  free(pMem: pathElement->relativePath);
  if ( this->m_filesToProcess.m_Size == 0 )
  {
    v3 = 0;
    if ( this->m_numVMTArguments > 0 )
    {
      m_VMTArguments = (void **)this->m_VMTArguments;
      do
      {
        free(pMem: *m_VMTArguments);
        ++v3;
        ++m_VMTArguments;
      }
      while ( v3 < this->m_numVMTArguments );
    }
    this->m_numVMTArguments = 0;
    CVtexDialog::AddMsg(this, format: "Done!\n");
    this->m_vtexButton->SetText(this: this->m_vtexButton, a2: "Process Files");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A40
// Name: private: void CVtexDialog::ProcessTarga(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::ProcessTarga(CVtexDialog *this)
{
  CVtexDialog::PathElement *m_pMemory; // eax
  char *fullPath; // ebx
  char *relativePath; // edi
  CP4File *m_p; // ebx
  bool (__thiscall *Edit)(CP4File *); // eax
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  _QWORD *v9; // eax
  bool (__thiscall *IsSelected)(vgui::Button *); // edx
  vgui::TextEntry *entry; // edi
  KeyValues *defaults; // ebx
  const char *String; // eax
  int Int; // edi
  int v15; // edi
  char suffix[260]; // [esp+Ch] [ebp-334h] BYREF
  char fileToRemove[260]; // [esp+110h] [ebp-230h] BYREF
  char value[260]; // [esp+214h] [ebp-12Ch] BYREF
  CVtexDialog::MaterialVar var; // [esp+318h] [ebp-28h]
  CP4AutoEditAddFile autop4; // [esp+328h] [ebp-18h]
  int i; // [esp+32Ch] [ebp-14h]
  CVtexDialog::PathElement pathElement; // [esp+330h] [ebp-10h] BYREF
  Color c; // [esp+338h] [ebp-8h]
  bool bSupportsXBox360; // [esp+33Fh] [ebp-1h]

  if ( this->m_vtexModule != nullptr )
    Sys_UnloadModule(pModule: this->m_vtexModule);
  this->m_vtexModule = nullptr;
  this->m_vtex = nullptr;
  CVtexDialog::LoadVTex(this);
  m_pMemory = this->m_filesToProcess.m_Memory.m_pMemory;
  fullPath = m_pMemory->fullPath;
  relativePath = m_pMemory->relativePath;
  c = (Color)-4144960;
  pathElement.relativePath = relativePath;
  pathElement.fullPath = fullPath;
  CVtexDialog::AddMsg(this, c: (Color)-4144960, format: "Processing %s\n", fullPath);
  m_p = CP4Factory::AccessFile(this: g_p4factory, szFilename: fullPath);
  Edit = m_p->Edit;
  autop4.m_spImpl.m_p = m_p;
  Edit(this: m_p);
  V_strncpy(pDest: fileToRemove, pSrc: this->m_gameDir, maxLen: 260);
  V_strncat(pDest: fileToRemove, pSrc: "materials/", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: fileToRemove, pSrc: relativePath, destBufferSize: 0x104u, max_chars_to_copy: -1);
  if ( CVtexDialog::RemoveOutputFile(this, path: fileToRemove, bytes: 260, extension: ".vmt") == 0 )
    CVtexDialog::AddWarning(this, format: "Can't overwrite %s\n", fileToRemove);
  if ( CVtexDialog::RemoveOutputFile(this, path: fileToRemove, bytes: 260, extension: ".vtf") != 0 )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "gameinfo.txt");
    else
      v8 = nullptr;
    bSupportsXBox360 = false;
    if ( v8 == nullptr )
      goto LABEL_17;
    if ( g_pFullFileSystem != nullptr
      && KeyValues::LoadFromFile(
           this: v8,
           filesystem: &g_pFullFileSystem->IBaseFileSystem,
           resourceName: "gameinfo.txt",
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      bSupportsXBox360 = KeyValues::GetInt(this: v8, keyName: "SupportsXBox360", defaultValue: 0) == 1;
    }
    KeyValues::deleteThis(this: v8);
    if ( bSupportsXBox360
      && CVtexDialog::RemoveOutputFile(this, path: fileToRemove, bytes: 260, extension: ".pwl.vtf") == 0 )
    {
      CVtexDialog::AddWarning(this, format: "Skipping %s - pwl.vtf is read-only\n", pathElement.relativePath);
      CVtexDialog::RemoveTargaFromQueue(this, &pathElement);
      m_p->Add(this: m_p);
      ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
    }
    else
    {
LABEL_17:
      i = 0;
      if ( this->m_materialVars.m_Size > 0 )
      {
        c = 0;
        do
        {
          v9 = (_QWORD *)((char *)this->m_materialVars.m_Memory.m_pMemory + *(_DWORD *)&c);
          *(_QWORD *)&var.label = *v9;
          IsSelected = var.label->IsSelected;
          *(_QWORD *)&var.combo = v9[1];
          if ( IsSelected(this: var.label) )
          {
            entry = var.entry;
            if ( var.entry != nullptr )
            {
              defaults = var.defaults;
              String = KeyValues::GetString(this: var.defaults, keyName: "type", defaultValue: "default");
              if ( _V_stricmp(s1: String, s2: "suffix") == 0 )
              {
                memset(suffix, 0, sizeof(suffix));
                entry->GetText_2(this: entry, a2: suffix, a3: 260);
                Int = KeyValues::GetInt(this: defaults, keyName: "argumentIndex", defaultValue: 0);
                if ( (unsigned int)(Int - 1) <= 0x34 )
                {
                  memset(value, 0, sizeof(value));
                  V_strncpy(pDest: value, pSrc: pathElement.relativePath, maxLen: 260);
                  V_StripExtension(in: value, out: value, outSize: 260);
                  V_strncat(pDest: value, pSrc: suffix, destBufferSize: 0x104u, max_chars_to_copy: -1);
                  if ( this->m_VMTArguments[Int] != nullptr )
                    free(pMem: this->m_VMTArguments[Int]);
                  this->m_VMTArguments[Int] = CloneString(str: value);
                }
              }
              m_p = autop4.m_spImpl.m_p;
            }
          }
          *(_DWORD *)&c += 16;
          ++i;
        }
        while ( i < this->m_materialVars.m_Size );
      }
      v15 = s_VTexErrorCount;
      this->m_VMTArguments[this->m_numVMTArguments] = pathElement.fullPath;
      this->m_vtex->VTex(
        this: this->m_vtex,
        a2: (void *(__cdecl *)(const char *, int *))filesystemFactory,
        a3: this->m_gameDir,
        a4: this->m_numVMTArguments + 1,
        a5: this->m_VMTArguments);
      if ( s_VTexErrorCount > v15 )
        CVtexDialog::AddWarning(this, format: "Failed to process %s\n", pathElement.relativePath);
      CVtexDialog::RemoveTargaFromQueue(this, &pathElement);
      m_p->Add(this: m_p);
      ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
    }
  }
  else
  {
    CVtexDialog::AddWarning(this, format: "Skipping %s - vtf is read-only\n", relativePath);
    CVtexDialog::RemoveTargaFromQueue(this, &pathElement);
    m_p->Add(this: m_p);
    ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405E40
// Name: public: int CUtlVector<struct CVtexDialog::PathElement,class CUtlMemory<struct CVtexDialog::PathElement,int>>::InsertBefore(int,struct CVtexDialog::PathElement const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVtexDialog::PathElement,CUtlMemory<CVtexDialog::PathElement,int>>::InsertBefore(
        CUtlVector<CVtexDialog::PathElement,CUtlMemory<CVtexDialog::PathElement,int> > *this,
        int elem,
        const CVtexDialog::PathElement *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVtexDialog::PathElement *m_pMemory; // ecx
  int v7; // eax
  CVtexDialog::PathElement *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVtexDialog::PathElement,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00405EB0
// Name: protected: virtual void CVtexDialog::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVtexDialog::OnThink(CVtexDialog *this)
{
  if ( this->m_filesToProcess.m_Size != 0 )
    CVtexDialog::ProcessTarga(this);
}

//------------------------------------------------------------------------------
// Address: 0x00405EC0
// Name: private: void CVtexDialog::ProcessTargas(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVtexDialog::ProcessTargas(CVtexDialog *this@<ecx>, int a2@<ebx>)
{
  KeyValues *ActiveItemUserData; // eax
  const char *String; // edi
  int v5; // edi
  void **m_VMTArguments; // ebx
  bool v7; // zf
  int v8; // ecx
  CVtexDialog::PathElement *m_pMemory; // eax
  CVtexDialog::PathElement *v10; // eax
  unsigned __int8 (__thiscall *v11)(char *); // edx
  const char *v12; // eax
  char *v13; // eax
  char *fullPath; // edi
  const char *Name; // eax
  vgui::ListPanel *m_files; // ecx
  int (__thiscall *GetItemIDFromRow)(vgui::ListPanel *, int); // eax
  int j; // eax
  vgui::ListPanel *v19; // ecx
  vgui::ListPanel_vtbl *v20; // edx
  KeyValues *v21; // ebx
  const char *v22; // eax
  const char *v23; // edi
  char *v24; // eax
  int v25; // eax
  const char *v26; // eax
  const char *v27; // edi
  char *v28; // eax
  int v29; // eax
  char *v30; // ebx
  int m_Size; // edx
  char value[256]; // [esp+4h] [ebp-118h] BYREF
  CVtexDialog::PathElement file; // [esp+104h] [ebp-18h]
  CVtexDialog::PathElement src; // [esp+10Ch] [ebp-10h] BYREF
  int i; // [esp+114h] [ebp-8h]
  int row; // [esp+118h] [ebp-4h]

  if ( this->m_vtex != nullptr )
  {
    if ( this->m_files->GetItemCount(this: this->m_files) != 0 )
    {
      if ( this->m_gameDir != nullptr )
      {
        ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_shader);
        if ( ActiveItemUserData != nullptr )
        {
          String = KeyValues::GetString(this: ActiveItemUserData, keyName: "shader", defaultValue: nullptr);
          if ( String != nullptr )
          {
            if ( this->m_numVMTArguments <= 0 )
            {
              this->m_VMTArguments[this->m_numVMTArguments++] = CloneString(str: defaultValue);
              this->m_VMTArguments[this->m_numVMTArguments++] = CloneString(str: "-UseStandardError");
              this->m_VMTArguments[this->m_numVMTArguments++] = CloneString(str: "-quiet");
              this->m_VMTArguments[this->m_numVMTArguments++] = CloneString(str: "-mkdir");
              this->m_VMTArguments[this->m_numVMTArguments++] = CloneString(str: "-shader");
              this->m_VMTArguments[this->m_numVMTArguments++] = CloneString(str: String);
              i = 0;
              if ( this->m_materialVars.m_Size > 0 )
              {
                row = 0;
                do
                {
                  v10 = (CVtexDialog::PathElement *)((char *)this->m_materialVars.m_Memory.m_pMemory + row);
                  file = *v10;
                  v11 = *(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)file.relativePath + 1024);
                  src = v10[1];
                  if ( v11(a1: file.relativePath) != 0 )
                  {
                    if ( this->m_numVMTArguments + 3 < 54 )
                    {
                      memset(value, 0, sizeof(value));
                      if ( file.fullPath != nullptr )
                      {
                        (*(void (__thiscall **)(char *, char *, int))(*(_DWORD *)file.fullPath + 856))(
                          a1: file.fullPath,
                          a2: value,
                          a3: 256);
                      }
                      else if ( src.relativePath != nullptr )
                      {
                        (*(void (__thiscall **)(char *, char *, int))(*(_DWORD *)src.relativePath + 856))(
                          a1: src.relativePath,
                          a2: value,
                          a3: 256);
                      }
                      v13 = CloneString(str: "-vmtparam");
                      fullPath = src.fullPath;
                      this->m_VMTArguments[this->m_numVMTArguments++] = v13;
                      Name = KeyValues::GetName(this: (KeyValues *)fullPath);
                      this->m_VMTArguments[this->m_numVMTArguments++] = CloneString(str: Name);
                      this->m_VMTArguments[this->m_numVMTArguments++] = CloneString(str: value);
                      KeyValues::SetInt(
                        this: (KeyValues *)fullPath,
                        keyName: "argumentIndex",
                        value: this->m_numVMTArguments - 1);
                    }
                    else
                    {
                      v12 = KeyValues::GetName(this: (KeyValues *)src.fullPath);
                      CVtexDialog::AddWarning(this, format: "Too many params - ignoring %s\n", v12);
                    }
                  }
                  row += 16;
                  ++i;
                }
                while ( i < this->m_materialVars.m_Size );
              }
              m_files = this->m_files;
              GetItemIDFromRow = m_files->GetItemIDFromRow;
              row = 0;
              for ( j = GetItemIDFromRow(this: m_files, a2: 0);
                    j > -1;
                    j = ((int (__thiscall *)(vgui::ListPanel *))this->m_files->GetItemIDFromRow)(a1: this->m_files) )
              {
                v19 = this->m_files;
                v20 = v19->__vftable;
                ++row;
                v21 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))v20->GetItem)(
                                     a1: v19,
                                     a2: j,
                                     a3: a2);
                v22 = KeyValues::GetString(this: v21, keyName: "filename", defaultValue: defaultValue);
                v23 = v22;
                if ( v22 != nullptr )
                {
                  v25 = _V_strlen(str: v22);
                  i = (int)operator new(nSize: v25 + 1);
                  _V_strcpy(dest: (char *)i, src: v23);
                  v24 = (char *)i;
                }
                else
                {
                  v24 = (char *)operator new(nSize: 1u);
                  *v24 = 0;
                }
                src.relativePath = v24;
                v26 = KeyValues::GetString(this: v21, keyName: "path", defaultValue: defaultValue);
                v27 = v26;
                if ( v26 != nullptr )
                {
                  v29 = _V_strlen(str: v26);
                  v30 = (char *)operator new(nSize: v29 + 1);
                  _V_strcpy(dest: v30, src: v27);
                  v28 = v30;
                }
                else
                {
                  v28 = (char *)operator new(nSize: 1u);
                  *v28 = 0;
                }
                m_Size = this->m_filesToProcess.m_Size;
                src.fullPath = v28;
                CUtlVector<CVtexDialog::PathElement,CUtlMemory<CVtexDialog::PathElement,int>>::InsertBefore(
                  this: &this->m_filesToProcess,
                  elem: m_Size,
                  &src);
                a2 = row;
              }
              this->m_vtexButton->SetText(this: this->m_vtexButton, a2: "Stop Processing");
            }
            else
            {
              v5 = 0;
              m_VMTArguments = (void **)this->m_VMTArguments;
              do
              {
                free(pMem: *m_VMTArguments);
                ++v5;
                ++m_VMTArguments;
              }
              while ( v5 < this->m_numVMTArguments );
              v7 = this->m_filesToProcess.m_Size == 0;
              this->m_numVMTArguments = 0;
              if ( !v7 )
              {
                do
                {
                  free(pMem: this->m_filesToProcess.m_Memory.m_pMemory->fullPath);
                  free(pMem: this->m_filesToProcess.m_Memory.m_pMemory->relativePath);
                  v8 = this->m_filesToProcess.m_Size;
                  if ( v8 > 0 )
                  {
                    if ( v8 != 1 )
                    {
                      m_pMemory = this->m_filesToProcess.m_Memory.m_pMemory;
                      m_pMemory->relativePath = m_pMemory[v8 - 1].relativePath;
                      m_pMemory->fullPath = m_pMemory[v8 - 1].fullPath;
                    }
                    --this->m_filesToProcess.m_Size;
                  }
                }
                while ( this->m_filesToProcess.m_Size != 0 );
              }
              CVtexDialog::AddWarning(this, format: "Aborted processing\n");
              this->m_vtexButton->SetText(this: this->m_vtexButton, a2: "Process Files");
            }
          }
          else
          {
            CVtexDialog::AddWarning(this, format: "No shader selected\n");
          }
        }
        else
        {
          CVtexDialog::AddWarning(this, format: "No shader selected\n");
        }
      }
      else
      {
        CVtexDialog::AddWarning(this, format: "No game directory found\n");
      }
    }
    else
    {
      CVtexDialog::AddWarning(this, format: "No files to process\n");
    }
  }
  else
  {
    CVtexDialog::AddWarning(this, format: "Couldn't find vtex.dll\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406600
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406D30
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406EA0
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00407560
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0041ABC0
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  vgui::BoundKey_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC30
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041ACC0
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042F7E0
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::Find(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::Find(CUtlVector<int,CUtlMemory<int,int> > *this, const int *src)
{
  int m_Size; // edx
  int result; // eax
  int *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432370
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00440490
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x00441000
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004412E0
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004499D0
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0044F4A0
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00451A90
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004585E0
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458650
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004598E0
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459BE0
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CA70
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CAE0
// Name: public: int CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::InsertBefore(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::FileData_t *m_pMemory; // ecx
  int v6; // eax
  vgui::FileData_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::FileData_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 288 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_FileAttributes);
    CUtlString::CUtlString(this: &v7->m_CreationTime);
    CUtlString::CUtlString(this: &v7->m_LastAccessTime);
    CUtlString::CUtlString(this: &v7->m_LastWriteTime);
    CUtlString::CUtlString(this: &v7->m_FileName);
    CUtlString::CUtlString(this: &v7->m_FullPath);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0045DA50
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DAB0
// Name: public: void CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::Purge(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  vgui::FileData_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      vgui::FileData_t::~FileData_t(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F070
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x004606E0
// Name: public: int CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00460CC0
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVtexDialog::PathElement,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00462FF0
// Name: public: void CUtlMemory<struct PanelItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PanelItem_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463080
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463CC0
// Name: public: bool CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::FindAndRemove(class vgui::PHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}
