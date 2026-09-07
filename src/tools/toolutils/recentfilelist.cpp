// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/recentfilelist.cpp
// Functions: 7
// ============================================================

#include "tools\toolutils\recentfilelist.h"

//------------------------------------------------------------------------------
// Address: 0x102BF530
// Name: public: bool CToolsRecentFileList::IsEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CToolsRecentFileList::IsEmpty(CToolsRecentFileList *this)
{
  return this->m_RecentFiles.m_Size == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102BF540
// Name: public: char const __near * CToolsRecentFileList::GetFile(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CToolsRecentFileList::GetFile(CToolsRecentFileList *this, int slot)
{
  if ( slot < 0 || slot >= this->m_RecentFiles.m_Size )
    return nullptr;
  else
    return CUtlString::operator char const *(this: &this->m_RecentFiles.m_Memory.m_pMemory[slot].m_pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x102BF570
// Name: public: void CToolsRecentFileList::SaveToRegistry(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolsRecentFileList::SaveToRegistry(CToolsRecentFileList *this, const char *pToolKeyName)
{
  CToolsRecentFileList *v3; // edi
  int m_Size; // eax
  int v5; // esi
  CUtlString *v6; // ecx
  IRegistry_vtbl *v7; // edi
  const char *v8; // eax
  IRegistry_vtbl *v9; // edi
  const char *v10; // eax
  char sz[128]; // [esp+Ch] [ebp-88h] BYREF
  int c; // [esp+8Ch] [ebp-8h]
  CToolsRecentFileList *v13; // [esp+90h] [ebp-4h]
  const char *pToolKeyNamea; // [esp+9Ch] [ebp+8h]

  v3 = this;
  m_Size = this->m_RecentFiles.m_Size;
  v5 = 0;
  v13 = this;
  c = m_Size;
  if ( m_Size <= 0 )
    goto LABEL_9;
  pToolKeyNamea = nullptr;
  while ( 1 )
  {
    V_snprintf(pDest: sz, maxLen: 0x80u, pFormat: "%s\\history%02i", pToolKeyName, v5);
    v6 = (CUtlString *)&pToolKeyNamea[(unsigned int)v3->m_RecentFiles.m_Memory.m_pMemory];
    v7 = registry->__vftable;
    v8 = CUtlString::operator char const *(this: v6);
    v7->WriteString_2(this: registry, a2: sz, a3: v8);
    V_snprintf(pDest: sz, maxLen: 0x80u, pFormat: "%s\\history_fileformat%02i", pToolKeyName, v5);
    v9 = registry->__vftable;
    v10 = CUtlString::operator char const *(this: (CUtlString *)&pToolKeyNamea[(unsigned int)v13->m_RecentFiles.m_Memory.m_pMemory
                                                                             + 16]);
    v9->WriteString_2(this: registry, a2: sz, a3: v10);
    pToolKeyNamea += 32;
    if ( ++v5 >= c )
      break;
    v3 = v13;
  }
  if ( v5 < 20 )
  {
LABEL_9:
    do
    {
      V_snprintf(pDest: sz, maxLen: 0x80u, pFormat: "%s\\history%02i", pToolKeyName, v5);
      registry->WriteString_2(this: registry, a2: sz, a3: &var);
      V_snprintf(pDest: sz, maxLen: 0x80u, pFormat: "%s\\history_fileformat%02i", pToolKeyName, v5);
      registry->WriteString_2(this: registry, a2: sz, a3: &var);
      ++v5;
    }
    while ( v5 < 20 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF6C0
// Name: public: void CToolsRecentFileList::AddToMenu(class vgui::Menu __near *,class vgui::Panel __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolsRecentFileList::AddToMenu(
        CToolsRecentFileList *this,
        vgui::Menu *menu,
        vgui::Panel *pActionTarget,
        const char *pCommandName)
{
  CToolsRecentFileList *v4; // edi
  int m_Size; // eax
  int v6; // esi
  int v7; // ebx
  const char *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  char sz[32]; // [esp+8h] [ebp-28h] BYREF
  int c; // [esp+28h] [ebp-8h]
  CToolsRecentFileList *v15; // [esp+2Ch] [ebp-4h]

  v4 = this;
  m_Size = this->m_RecentFiles.m_Size;
  v6 = 0;
  v15 = this;
  c = m_Size;
  if ( m_Size > 0 )
  {
    v7 = 0;
    while ( 1 )
    {
      V_snprintf(pDest: sz, maxLen: 0x20u, pFormat: "%s%02i", pCommandName, v6);
      v8 = CUtlString::operator char const *(this: &v4->m_RecentFiles.m_Memory.m_pMemory[v7].m_pFileName);
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v10 = v9 != nullptr
          ? KeyValues::KeyValues(this: v9, setName: "Command", firstKey: "command", firstValue: sz)
          : nullptr;
      menu->AddMenuItem(this: menu, a2: v8, a3: v10, a4: pActionTarget, a5: nullptr);
      ++v6;
      ++v7;
      if ( v6 >= c )
        break;
      v4 = v15;
    }
  }
  menu->AddSeparator(this: menu);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "OnClearRecent");
  else
    v12 = nullptr;
  menu->AddMenuItem(this: menu, a2: "clearrecent", a3: "#ToolFileClearRecent", a4: v12, a5: pActionTarget, a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102BF8C0
// Name: public: void CToolsRecentFileList::Add(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolsRecentFileList::Add(CToolsRecentFileList *this, char *pFileName, char *pFileFormat)
{
  int v4; // edi
  int v5; // ebx
  int i; // eax
  int v7; // edi
  CToolsRecentFileList::RecentFileInfo_t info; // [esp+8h] [ebp-20h] BYREF

  CUtlString::CUtlString(this: &info.m_pFileName);
  CUtlString::CUtlString(this: &info.m_pFileFormat);
  CUtlString::operator=(this: &info.m_pFileName, src: pFileName);
  v4 = 0;
  if ( this->m_RecentFiles.m_Size > 0 )
  {
    v5 = 0;
    while ( !CUtlString::operator==(
               this: &this->m_RecentFiles.m_Memory.m_pMemory[v5].m_pFileName,
               src: &info.m_pFileName) )
    {
      ++v4;
      ++v5;
      if ( v4 >= this->m_RecentFiles.m_Size )
        goto LABEL_8;
    }
    if ( v4 != -1 )
      CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::Remove(
        this: &this->m_RecentFiles,
        elem: v4);
  }
LABEL_8:
  for ( i = this->m_RecentFiles.m_Size; i >= 20; i = this->m_RecentFiles.m_Size )
    CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::Remove(
      this: &this->m_RecentFiles,
      elem: i - 1);
  v7 = CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::InsertBefore(
         this: &this->m_RecentFiles,
         elem: 0);
  CUtlString::operator=(this: &this->m_RecentFiles.m_Memory.m_pMemory[v7].m_pFileName, src: pFileName);
  CUtlString::operator=(this: &this->m_RecentFiles.m_Memory.m_pMemory[v7].m_pFileFormat, src: pFileFormat);
  info.m_pFileFormat.m_Storage.m_nActualLength = 0;
  if ( info.m_pFileFormat.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( info.m_pFileFormat.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: info.m_pFileFormat.m_Storage.m_Memory.m_pMemory);
      info.m_pFileFormat.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    info.m_pFileFormat.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  info.m_pFileName.m_Storage.m_nActualLength = 0;
  if ( info.m_pFileName.m_Storage.m_Memory.m_nGrowSize >= 0 && info.m_pFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: info.m_pFileName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x102BF9B0
// Name: public: void CToolsRecentFileList::Clear(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CToolsRecentFileList::Clear(CToolsRecentFileList *this)
{
  CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::RemoveAll(this: &this->m_RecentFiles);
}

//------------------------------------------------------------------------------
// Address: 0x102BF9C0
// Name: public: void CToolsRecentFileList::LoadFromRegistry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolsRecentFileList::LoadFromRegistry(CToolsRecentFileList *this, const char *pToolKeyName)
{
  int v3; // ebx
  char *v4; // eax
  const char *v5; // eax
  bool v6; // zf
  int v7; // edi
  int v8; // ebx
  int j; // eax
  int v10; // edi
  char pFileName[260]; // [esp+Ch] [ebp-22Ch] BYREF
  char sz[128]; // [esp+110h] [ebp-128h] BYREF
  char szType[128]; // [esp+190h] [ebp-A8h] BYREF
  CUtlString src; // [esp+210h] [ebp-28h] BYREF
  CUtlString v15; // [esp+220h] [ebp-18h] BYREF
  int i; // [esp+230h] [ebp-8h]
  const char *pFormat; // [esp+234h] [ebp-4h]

  CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::RemoveAll(this: &this->m_RecentFiles);
  v3 = 20;
  for ( i = 20; i >= 0; --i )
  {
    V_snprintf(pDest: sz, maxLen: 0x80u, pFormat: "%s\\history%02i", pToolKeyName, v3);
    V_snprintf(pDest: szType, maxLen: 0x80u, pFormat: "%s\\history_fileformat%02i", pToolKeyName, v3);
    v4 = (char *)registry->ReadString_2(this: registry, a2: sz, a3: &var);
    V_strncpy(pDest: pFileName, pSrc: v4, maxLen: 260);
    if ( pFileName[0] != 0 )
    {
      v5 = registry->ReadString_2(this: registry, a2: szType, a3: &var);
      if ( v5 == nullptr || (v6 = *v5 == 0, pFormat = v5, v6) )
        pFormat = "dmx";
      CUtlString::CUtlString(this: &src);
      CUtlString::CUtlString(this: &v15);
      CUtlString::operator=(this: &src, src: pFileName);
      v7 = 0;
      if ( this->m_RecentFiles.m_Size > 0 )
      {
        v8 = 0;
        while ( !CUtlString::operator==(this: &this->m_RecentFiles.m_Memory.m_pMemory[v8].m_pFileName, &src) )
        {
          ++v7;
          ++v8;
          if ( v7 >= this->m_RecentFiles.m_Size )
            goto LABEL_13;
        }
        if ( v7 != -1 )
          CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::Remove(
            this: &this->m_RecentFiles,
            elem: v7);
      }
LABEL_13:
      for ( j = this->m_RecentFiles.m_Size; j >= 20; j = this->m_RecentFiles.m_Size )
        CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::Remove(
          this: &this->m_RecentFiles,
          elem: j - 1);
      v10 = CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::InsertBefore(
              this: &this->m_RecentFiles,
              elem: 0);
      CUtlString::operator=(this: &this->m_RecentFiles.m_Memory.m_pMemory[v10].m_pFileName, src: pFileName);
      CUtlString::operator=(this: &this->m_RecentFiles.m_Memory.m_pMemory[v10].m_pFileFormat, src: (char *)pFormat);
      v15.m_Storage.m_nActualLength = 0;
      if ( v15.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v15.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15.m_Storage.m_Memory.m_pMemory);
          v15.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v15.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
    v3 = i - 1;
  }
}
