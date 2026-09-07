// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/p4helpers.cpp
// Functions: 6
// ============================================================

#include "tier2\p4helpers.h"

//------------------------------------------------------------------------------
// Address: 0x1027EE40
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1027EE60
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1027EE80
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1027EEA0
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027EEB0
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x1027EF30
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, const char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x1025DF10
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1025DF30
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1025DF50
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1025DF70
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025DF80
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x1025E000
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace MaterialSystem

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00418010
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00418030
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00418050
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00418070
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418080
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x00418110
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace choreogen

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00576240
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00576260
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00576280
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x005762A0
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005762B0
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x00576330
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace dmxedit

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027EF90
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1027EFB0
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1027EFD0
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1027EFF0
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027F000
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x1027F080
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, const char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CDA60
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004CDA80
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004CDAA0
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004CDAC0
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CDAD0
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x004CDB50
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0057A9A0
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0057A9C0
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0057A9E0
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0057AA00
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA10
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x0057AA90
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C76F0
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x005C7710
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x005C7730
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x005C7750
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C77C0
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0049BBB0
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049BBC0
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

} // namespace mksheet

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00449E10
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00449E30
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00449E50
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00449E70
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449E80
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x00449EF0
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0046A760
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A770
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054EBC0
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0054EBE0
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0054EC00
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0054EC20
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0054EC30
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x0054ECB0
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace phogen

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005505F0
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00550610
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00550630
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00550650
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00550660
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x005506E0
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005C05A0
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x005C05C0
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x005C05E0
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x005C0600
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C0610
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x005C0690
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace studiomdl

// ============================================================
// Overlay from subdbaker (Missing functions)
// ============================================================
namespace subdbaker {

//------------------------------------------------------------------------------
// Address: 0x0040C6F0
// Name: public: virtual bool CP4File_Dummy::Add(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CP4File_Dummy::Add(CP4File_Dummy *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045BFFF
// Name: public: long D3DXShader::CCommentBlock::Add(void const __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCommentBlock::Add(
        D3DXShader::CCommentBlock *this,
        char *pMem,
        unsigned int nSize,
        unsigned int a4,
        unsigned int *a5)
{
  unsigned int v5; // edi
  D3DXShader::CCommentBlock *v6; // esi
  int i; // eax
  char **v9; // ebx
  char *v10; // eax
  char *v11; // ecx
  char ***v12; // ecx

  v5 = nSize;
  v6 = this;
  if ( nSize != 0 && pMem == nullptr )
    return -2147467259;
  if ( nSize == -1 )
  {
    nSize = strlen(pMem) + 1;
    v5 = nSize;
  }
  if ( (a4 & 1) == 0 )
    a4 |= 2u;
  if ( (a4 & 2) != 0 )
  {
    for ( i = *((_DWORD *)v6 + 2); i != 0; i = *(_DWORD *)(i + 16) )
    {
      if ( (*(_BYTE *)(i + 8) & 2) != 0 && v5 == *(_DWORD *)(i + 4) )
      {
        if ( memcmp(pMem, *(const void **)i, v5) == 0 )
        {
          if ( a5 != nullptr )
            *a5 = *(_DWORD *)(i + 12);
          if ( (a4 & 1) != 0 && (a4 & 8) != 0 )
            free(pMem);
          return 0;
        }
        v5 = nSize;
        v6 = this;
      }
    }
  }
  v9 = (char **)operator new(nSize: 0x14u);
  if ( v9 == nullptr )
    return -2147024882;
  if ( (a4 & 1) != 0 )
  {
    *v9 = pMem;
  }
  else
  {
    v10 = (char *)operator new(nSize: v5);
    *v9 = v10;
    if ( v10 == nullptr )
    {
      free(pMem: v9);
      return -2147024882;
    }
    qmemcpy(v10, pMem, v5);
    v5 = nSize;
    v6 = this;
  }
  if ( (a4 & 4) == 0 )
    *((_DWORD *)v6 + 1) = (*((_DWORD *)v6 + 1) + 3) & 0xFFFFFFFC;
  v11 = *((char **)v6 + 1);
  v9[2] = (char *)a4;
  v9[4] = nullptr;
  v9[3] = v11;
  v9[1] = (char *)v5;
  v12 = *((char ****)v6 + 3);
  *((_DWORD *)v6 + 1) += v5;
  *v12 = v9;
  *((_DWORD *)v6 + 3) = v9 + 4;
  if ( a5 != nullptr )
    *a5 = (unsigned int)v9[3];
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C9990
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::Get(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004C99B0
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::Get(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004C99D0
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::Get(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004C99F0
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C9A00
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x004C9A90
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, const char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045C138
// Name: public: unsigned int D3DXShader::CCommentBlock::SizeInDwords(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CCommentBlock::SizeInDwords(D3DXShader::CCommentBlock *this)
{
  return ((unsigned int)(*((_DWORD *)this + 1) + 3) >> 2) + 2;
}

//------------------------------------------------------------------------------
// Address: 0x0045C144
// Name: public: long D3DXShader::CCommentBlock::WriteComment(unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCommentBlock::WriteComment(
        D3DXShader::CCommentBlock *this,
        unsigned int *a2,
        unsigned int a3)
{
  unsigned int v3; // ebx
  int v6; // edx
  int v7; // eax
  unsigned int *v8; // [esp+10h] [ebp+8h]
  unsigned int *i; // [esp+14h] [ebp+Ch]

  v3 = a3;
  if ( a3 == -1 )
  {
    v3 = ((unsigned int)(*((_DWORD *)this + 1) + 3) >> 2) + 2;
  }
  else if ( a3 < ((unsigned int)(*((_DWORD *)this + 1) + 3) >> 2) + 2 )
  {
    return -2147467259;
  }
  if ( v3 > 0x8000 )
    return -2147467259;
  v8 = nullptr;
  *a2 = ((((_WORD)v3 - 1) & 0x7FFF) << 16) | 0xFFFE;
  a2[1] = *(_DWORD *)this;
  v6 = *((_DWORD *)this + 2);
  for ( i = a2 + 2; v6 != 0; v8 = (unsigned int *)((char *)v8 + v7) )
  {
    if ( (*(_BYTE *)(v6 + 8) & 4) == 0 )
    {
      memset(i, 0xABu, (((unsigned int)v8 + 3) & 0xFFFFFFFC) - (_DWORD)v8);
      i = (unsigned int *)((char *)i + (((unsigned int)v8 + 3) & 0xFFFFFFFC) - (_DWORD)v8);
      v8 = (unsigned int *)(((unsigned int)v8 + 3) & 0xFFFFFFFC);
    }
    qmemcpy(i, *(const void **)v6, *(_DWORD *)(v6 + 4));
    v7 = *(_DWORD *)(v6 + 4);
    v6 = *(_DWORD *)(v6 + 16);
    i = (unsigned int *)((char *)i + v7);
  }
  memset(i, 0xABu, 4 * v3 - 8 - (_DWORD)v8);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045C231
// Name: public: D3DXShader::CFragmentConstants::CFragmentConstants(class D3DXShader::CParse __near *,class D3DXShader::CNodeScope __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CFragmentConstants *__thiscall D3DXShader::CFragmentConstants::CFragmentConstants(
        D3DXShader::CFragmentConstants *this,
        struct D3DXShader::CParse *a2,
        struct D3DXShader::CNodeScope *a3)
{
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045C247
// Name: long D3DXShader::CalcNumRegisters(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CalcNumRegisters(
        D3DXShader *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  D3DXShader **v4; // edi
  D3DXShader *v5; // esi
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // eax
  int result; // eax
  struct D3DXShader::CNode *v10; // ebx
  struct D3DXShader::CNode *v11; // eax
  unsigned int *v12; // [esp-4h] [ebp-10h]
  unsigned int *v13; // [esp+0h] [ebp-Ch]

  v4 = (D3DXShader **)a3;
  if ( a3 == nullptr )
    v4 = &this;
  v5 = this;
  v6 = *((_DWORD *)this + 1);
  if ( v6 == 9 )
  {
    v7 = *((_DWORD *)this + 4);
    v8 = 1;
    if ( v7 < 2 )
    {
      *(_DWORD *)a2 = 1;
      v8 = *((_DWORD *)v5 + 7);
LABEL_9:
      *v4 = (D3DXShader *)v8;
      return 0;
    }
    if ( v7 == 2 )
    {
      *(_DWORD *)a2 = *((_DWORD *)this + 7);
      v8 = *((_DWORD *)v5 + 6);
      goto LABEL_9;
    }
    if ( v7 == 3 )
    {
      *(_DWORD *)a2 = 1;
      goto LABEL_9;
    }
    return -2147467259;
  }
  if ( v6 == 8 )
  {
    v12 = (unsigned int *)v4;
    v4 = (D3DXShader **)a2;
    result = D3DXShader::CalcNumRegisters(this: *((D3DXShader **)this + 4), a2, a3: v12, a4: v13);
    if ( result < 0 )
      return result;
    v8 = (_DWORD)*v4 * *((_DWORD *)v5 + 5);
    goto LABEL_9;
  }
  if ( v6 != 1 )
    return -2147467259;
  v10 = a2;
  *(_DWORD *)a2 = 0;
  *v4 = nullptr;
  while ( 1 )
  {
    result = D3DXShader::CalcNumRegisters(
               this: *(D3DXShader **)(*(_DWORD *)(*((_DWORD *)v5 + 2) + 24) + 32),
               a2: (struct D3DXShader::CNode *)&a3,
               a3: (unsigned int *)&a2,
               a4: v13);
    if ( result < 0 )
      break;
    *(_DWORD *)v10 += a3;
    v11 = *v4;
    if ( a2 > *v4 )
      v11 = a2;
    *v4 = v11;
    v5 = *((D3DXShader **)v5 + 3);
    if ( v5 == nullptr )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C30A
// Name: public: long D3DXShader::CFragmentConstants::GetConstantSize(struct D3DXShader::D3DXTOKEN __near *,char const __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFragmentConstants::GetConstantSize(
        D3DXShader::CFragmentConstants *this,
        struct D3DXShader::D3DXTOKEN *a2,
        const char *a3,
        struct D3DXShader::CNode *a4)
{
  const char *v5; // edi
  D3DXShader::CParse *v6; // ecx
  int result; // eax
  _DWORD *v8; // edx
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  struct D3DXShader::CNodeScope **v11; // [esp-10h] [ebp-3Ch]
  unsigned int *v12; // [esp+0h] [ebp-2Ch]
  const char *v13[8]; // [esp+Ch] [ebp-20h] BYREF

  qmemcpy(v13, a2, sizeof(v13));
  v5 = a3;
  v6 = *(D3DXShader::CParse **)this;
  v13[2] = a3 + 2;
  v11 = *((struct D3DXShader::CNodeScope ***)this + 1);
  v13[0] = (const char *)10;
  if ( D3DXShader::CParse::FindDecl(
         this: v6,
         a2: 1,
         a3: v13,
         a4: nullptr,
         a5: nullptr,
         a6: v11,
         a7: 2u,
         a8: (int *)&a3,
         a9: nullptr) != 0 )
  {
    *(_DWORD *)a4 = 0;
    return 0;
  }
  result = D3DXShader::CalcNumRegisters(this: *((D3DXShader **)a3 + 8), a2: a4, a3: nullptr, a4: v12);
  if ( result >= 0 )
  {
    if ( *(_WORD *)v5 == *(_WORD *)"b_" )
    {
      if ( *v8 == 1 )
      {
        v9 = *((_DWORD **)a3 + 8);
        if ( v9[1] == 9 && v9[4] == 0 && v9[5] == 0 )
          return 0;
      }
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CTErrors *)(*(_DWORD *)(*(_DWORD *)this + 4) + 24),
        (const char **)a2,
        a3: 0xB54u,
        format: "boolean constant register '%s' must be defined as a variable of type bool only",
        v5);
    }
    else
    {
      if ( *(_WORD *)v5 != *(_WORD *)"i_" )
        return 0;
      if ( *v8 == 1 )
      {
        v10 = *((_DWORD **)a3 + 8);
        if ( v10[1] == 9 && v10[4] == 1 && v10[5] == 4 && v10[7] >= 3u )
          return 0;
      }
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CTErrors *)(*(_DWORD *)(*(_DWORD *)this + 4) + 24),
        (const char **)a2,
        a3: 0xB55u,
        format: "integer constant register '%s' must be defined as a variable of type int3 or int4 only",
        v5);
    }
    return -2147467259;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C405
// Name: long D3DXShader::EmitDefaultValue(class D3DXShader::CCommentBlock __near *,unsigned int,unsigned int,class D3DXShader::CNode __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::EmitDefaultValue(
        D3DXShader *this,
        struct D3DXShader::CCommentBlock *a2,
        unsigned int a3,
        unsigned int a4,
        struct D3DXShader::CNode *a5,
        unsigned int *a6)
{
  int v6; // edi
  _DWORD *v7; // esi
  unsigned int v8; // ebx
  char *v9; // edi
  unsigned int v11; // edi
  float *v12; // ecx
  int v13; // eax
  char *pMem; // [esp+4h] [ebp-4h]
  struct D3DXShader::CCommentBlock *v16; // [esp+14h] [ebp+Ch]
  struct D3DXShader::CCommentBlock *v17; // [esp+1Ch] [ebp+14h]

  v6 = 0;
  pMem = nullptr;
  if ( *(_DWORD *)(a4 + 4) != 13 )
    return 0;
  v7 = *(_DWORD **)(a4 + 32);
  if ( v7[1] == 1 )
  {
    v8 = 16 * (_DWORD)a2;
    v9 = (char *)operator new(nSize: 16 * (_DWORD)a2);
    pMem = v9;
    if ( v9 != nullptr )
    {
      memset(v9, 0, v8);
      if ( a2 != nullptr )
      {
        v16 = (struct D3DXShader::CCommentBlock *)v9;
        v17 = a2;
        do
        {
          v11 = a3;
          if ( a3 != 0 )
          {
            v12 = (float *)v16;
            do
            {
              v13 = v7[2];
              if ( *(_DWORD *)(v13 + 16) == 3 )
                *v12 = *(double *)(v13 + 24);
              else
                *v12 = *(float *)(v13 + 24);
              v7 = (_DWORD *)v7[3];
              ++v12;
              --v11;
            }
            while ( v11 != 0 );
          }
          v16 = (struct D3DXShader::CCommentBlock *)((char *)v16 + 16);
          v17 = (struct D3DXShader::CCommentBlock *)((char *)v17 - 1);
        }
        while ( v17 != nullptr );
      }
      v6 = D3DXShader::CCommentBlock::Add(this, pMem, nSize: v8, a4: 6u, (unsigned int *)a5);
    }
    else
    {
      v6 = -2147024882;
    }
  }
  free(pMem);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0045C4C8
// Name: long D3DXShader::EmitZeroDefaultValue(class D3DXShader::CCommentBlock __near *,unsigned int,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::EmitZeroDefaultValue(
        D3DXShader *this,
        struct D3DXShader::CCommentBlock *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  unsigned int v4; // esi
  void *v5; // ebx
  int v6; // esi

  v4 = 16 * (_DWORD)a2;
  v5 = operator new(nSize: 16 * (_DWORD)a2);
  if ( v5 != nullptr )
  {
    memset(v5, 0, v4);
    v6 = D3DXShader::CCommentBlock::Add(this, pMem: (char *)v5, nSize: v4, a4: 6u, a5: a3);
  }
  else
  {
    v6 = -2147024882;
  }
  free(pMem: v5);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0045C51F
// Name: public: long D3DXShader::CFragmentConstants::AddRegister(class D3DXShader::CCommentBlock __near *,struct _D3DXSHADER_CONSTANTINFO __near *,char const __near *,unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFragmentConstants::AddRegister(
        struct D3DXShader::CNodeScope ***this,
        struct D3DXShader::CCommentBlock *a2,
        struct _D3DXSHADER_CONSTANTINFO *a3,
        char *a4,
        __int16 a5,
        unsigned int a6)
{
  struct D3DXShader::CNode *i; // edi
  bool v7; // zf
  struct _D3DXSHADER_CONSTANTINFO *v8; // esi
  int result; // eax
  D3DXShader::CParse *v10; // ecx
  int v11; // eax
  _DWORD *v12; // eax
  int v13; // ecx
  const char *v14; // ecx
  int v15; // eax
  struct _D3DXSHADER_CONSTANTINFO *v16; // edi
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int v19; // eax
  int v20; // eax
  struct D3DXShader::CNodeScope **v21; // [esp-10h] [ebp-78h]
  unsigned int *v22; // [esp+0h] [ebp-68h]
  unsigned int *v23; // [esp+0h] [ebp-68h]
  const char *v24[8]; // [esp+Ch] [ebp-5Ch] BYREF
  _WORD pMem[6]; // [esp+2Ch] [ebp-3Ch] BYREF
  int v26; // [esp+38h] [ebp-30h]
  int v27; // [esp+3Ch] [ebp-2Ch] BYREF
  int v28; // [esp+40h] [ebp-28h]
  unsigned int v29; // [esp+48h] [ebp-20h] BYREF
  D3DXShader::CFragmentConstants *v30; // [esp+4Ch] [ebp-1Ch]
  const char *v31; // [esp+50h] [ebp-18h]
  struct _D3DXSHADER_CONSTANTINFO *v32; // [esp+54h] [ebp-14h]
  struct _D3DXSHADER_CONSTANTINFO *v33; // [esp+58h] [ebp-10h]
  int v34; // [esp+5Ch] [ebp-Ch]
  struct D3DXShader::CCommentBlock *v35; // [esp+60h] [ebp-8h] BYREF
  int v36; // [esp+64h] [ebp-4h] BYREF
  struct _D3DXSHADER_CONSTANTINFO *v37; // [esp+74h] [ebp+Ch]

  HIBYTE(a6) |= 0x80u;
  i = (struct D3DXShader::CNode *)a4;
  v7 = *(_WORD *)"c_" == *(_WORD *)a4;
  v30 = (D3DXShader::CFragmentConstants *)this;
  v36 = 0;
  if ( v7 || *(_WORD *)"b_" == *(_WORD *)a4 || *(_WORD *)"i_" == *(_WORD *)a4 || *(_WORD *)"s_" == *(_WORD *)a4 )
  {
    v31 = a4 + 2;
    v24[2] = a4 + 2;
    v21 = *(this + 1);
    v10 = (D3DXShader::CParse *)*this;
    v24[0] = (const char *)10;
    v24[4] = nullptr;
    v24[5] = nullptr;
    D3DXShader::CParse::FindDecl(
      this: v10,
      a2: 1,
      a3: v24,
      a4: nullptr,
      a5: nullptr,
      a6: v21,
      a7: 2u,
      a8: &v36,
      a9: nullptr);
    result = D3DXShader::CalcNumRegisters(
               this: *(D3DXShader **)(v36 + 32),
               a2: (struct D3DXShader::CNode *)&v35,
               a3: &v29,
               a4: v22);
    if ( result < 0 )
      return result;
    v8 = a3;
    if ( *(_DWORD *)(v36 + 48) != 0 )
    {
      v11 = *(_DWORD *)(v36 + 48);
      v37 = nullptr;
      v33 = nullptr;
      v32 = nullptr;
      v34 = v11;
      if ( v11 != 0 )
      {
        do
        {
          v12 = *(_DWORD **)(v34 + 8);
          if ( v12[1] == 17 )
          {
            v13 = v12[4];
            if ( v13 != 0 )
              v14 = *(const char **)(v13 + 24);
            else
              v14 = nullptr;
            v15 = v12[5];
            if ( v15 != 0 )
              v16 = *(struct _D3DXSHADER_CONSTANTINFO **)(v15 + 24);
            else
              v16 = nullptr;
            if ( v14 != nullptr )
            {
              if ( D3DXGetTargetDescByName(a1: v14, a2: 0, a3: &v27) >= 0
                && v16 != nullptr
                && tolower(c: *(char *)v16) == *a4 )
              {
                if ( a6 == v28 )
                {
                  v37 = v16;
                }
                else if ( ((a6 ^ v28) & 0xFFFF0000) == 0 && (_WORD)v28 == 0 )
                {
                  v33 = v16;
                }
              }
            }
            else if ( v16 != nullptr && tolower(c: *(char *)v16) == *a4 )
            {
              v32 = v16;
            }
          }
          v34 = *(_DWORD *)(v34 + 12);
        }
        while ( v34 != 0 );
        i = (struct D3DXShader::CNode *)a4;
        if ( v37 != nullptr )
          goto LABEL_33;
      }
      v37 = v33;
      if ( v33 != nullptr || (v37 = v32, v32 != nullptr) )
      {
LABEL_33:
        if ( *(char *)i == tolower(c: *(char *)v37) )
        {
          i = v37;
          if ( isdigit(c: *((char *)v37 + 1)) != 0 )
          {
            for ( i = (struct _D3DXSHADER_CONSTANTINFO *)((char *)v37 + 2);
                  isdigit(c: *(char *)i) != 0;
                  i = (struct D3DXShader::CNode *)((char *)i + 1) )
            {
              ;
            }
            if ( *(_BYTE *)i == 0 )
            {
              v17 = atoi(nptr: (const char *)v37 + 1);
              if ( v17 > 0x1FFF )
              {
                D3DXShader::CTErrors::Error(
                  this: (D3DXShader::CTErrors *)(*(_DWORD *)(*(_DWORD *)v30 + 4) + 24),
                  a2: nullptr,
                  a3: 0xB56u,
                  format: "Constant variable '%s' bound to register greater than 8191 (%d requested)",
                  v31,
                  v17);
                return -2147467259;
              }
              *((_WORD *)v8 + 5) |= (unsigned __int16)(4 * v17) | 2;
            }
          }
        }
      }
    }
    v18 = v36;
    if ( (*(_BYTE *)(v36 + 28) & 2) != 0 )
      *((_BYTE *)v8 + 10) |= 1u;
    v19 = *(_DWORD *)(v18 + 40);
    if ( v19 == 0 )
    {
      if ( *(_DWORD *)(v18 + 36) == 0 )
      {
        if ( (*((_BYTE *)v8 + 10) & 1) == 0 )
        {
LABEL_50:
          v20 = *(_DWORD *)(v36 + 32);
          if ( *(_DWORD *)(v20 + 4) != 9 || *(_DWORD *)(v20 + 20) != 20 )
          {
            result = D3DXShader::EmitTypeInfo(
                       a1: i,
                       this: a2,
                       a3: *(struct D3DXShader::CCommentBlock **)(v36 + 32),
                       pMem: (struct D3DXShader::CNode *)1,
                       a5: 0,
                       a6: (unsigned int *)v8 + 3,
                       a7: v23);
            if ( result < 0 )
              return result;
            goto LABEL_56;
          }
          D3DXShader::CTErrors::Error(
            this: (D3DXShader::CTErrors *)(*(_DWORD *)(*(_DWORD *)v30 + 4) + 24),
            a2: nullptr,
            a3: 0xB59u,
            format: "Sampler variable '%s' does not specify the sampler type.  Explicit sampler types required for asm fragments.",
            v31);
          return -2147467259;
        }
        result = D3DXShader::EmitZeroDefaultValue(this: a2, a2: v35, a3: (unsigned int *)v8 + 4, a4: v23);
LABEL_49:
        if ( result < 0 )
          return result;
        goto LABEL_50;
      }
      v19 = *(_DWORD *)(v18 + 36);
    }
    result = D3DXShader::EmitDefaultValue(
               this: a2,
               a2: v35,
               a3: v29,
               a4: v19,
               a5: (struct _D3DXSHADER_CONSTANTINFO *)((char *)v8 + 16),
               a6: v23);
    goto LABEL_49;
  }
  v8 = a3;
  pMem[0] = 1;
  pMem[1] = 3;
  pMem[2] = 1;
  pMem[3] = 4;
  pMem[4] = 1;
  pMem[5] = 0;
  v26 = 0;
  result = D3DXShader::CCommentBlock::Add(this: a2, (char *)pMem, nSize: 0x10u, a4: 6u, a5: (unsigned int *)a3 + 3);
  if ( result < 0 )
    return result;
  v35 = (struct D3DXShader::CCommentBlock *)1;
LABEL_56:
  result = D3DXShader::CCommentBlock::Add(this: a2, pMem: a4, nSize: 0xFFFFFFFF, a4: 7u, a5: (unsigned int *)v8);
  if ( result >= 0 )
  {
    if ( *(_WORD *)"b_" == *(_WORD *)a4 )
      *((_WORD *)v8 + 2) = 0;
    else
      *((_WORD *)v8 + 2) = (*(_WORD *)"i_" != *(_WORD *)a4) + 1;
    *((_WORD *)v8 + 3) = a5;
    *((_WORD *)v8 + 4) = (_WORD)v35;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C86A
// Name: public: D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeAsmInstruction *__thiscall D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(
        D3DXShader::CNodeAsmInstruction *this)
{
  D3DXShader::CNode::CNode(a1: 18);
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *(_DWORD *)this = &D3DXShader::CNodeAsmInstruction::`vftable';
  memset((char *)this + 16, 0, 0x20u);
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045C8A8
// Name: public: D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(struct D3DXShader::D3DXTOKEN const __near *,unsigned long,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeAsmInstruction *__thiscall D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(
        D3DXShader::CNodeAsmInstruction *this,
        const struct D3DXShader::D3DXTOKEN *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  D3DXShader::CNode::CNode(a1: 18);
  *(_DWORD *)this = &D3DXShader::CNodeAsmInstruction::`vftable';
  qmemcpy((char *)this + 16, a2, 0x20u);
  *((_DWORD *)this + 12) = a3;
  *((_DWORD *)this + 13) = a4;
  *((_DWORD *)this + 14) = a5;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045C8FA
// Name: public: D3DXShader::CNodeAsmRegister::CNodeAsmRegister(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeAsmRegister *__thiscall D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
        D3DXShader::CNodeAsmRegister *this)
{
  D3DXShader::CNode::CNode(a1: 19);
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 10) = 0;
  *(_DWORD *)this = &D3DXShader::CNodeAsmRegister::`vftable';
  *((_DWORD *)this + 8) = 983040;
  *((_DWORD *)this + 9) = 14942208;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045C92F
// Name: public: D3DXShader::CNodeAsmRegister::CNodeAsmRegister(unsigned long,unsigned long,unsigned long,int,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeAsmRegister *__thiscall D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
        D3DXShader::CNodeAsmRegister *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        struct D3DXShader::CNode *a6)
{
  D3DXShader::CNode::CNode(a1: 19);
  *((_DWORD *)this + 4) = a2;
  *((_DWORD *)this + 5) = a3;
  *((_DWORD *)this + 6) = a4;
  *((_DWORD *)this + 7) = a5;
  *((_DWORD *)this + 10) = a6;
  *(_DWORD *)this = &D3DXShader::CNodeAsmRegister::`vftable';
  *((_DWORD *)this + 8) = 983040;
  *((_DWORD *)this + 9) = 14942208;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045C978
// Name: public: virtual class D3DXShader::CNodeAsmInstruction __near * D3DXShader::CNodeAsmInstruction::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeAsmInstruction *__thiscall D3DXShader::CNodeAsmInstruction::Copy(
        D3DXShader::CNodeAsmInstruction *this)
{
  unsigned __int8 *v2; // eax
  struct D3DXShader::CNodeAsmInstruction *result; // eax
  int v4; // eax
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // edi
  int v8; // eax
  unsigned int v9; // [esp+4h] [ebp-8h]
  struct D3DXShader::CNodeAsmInstruction *v10; // [esp+8h] [ebp-4h]

  v2 = D3DXShader::CNode::operator new(a1: 0x60u);
  if ( v2 != nullptr )
  {
    result = D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(this: (D3DXShader::CNodeAsmInstruction *)v2);
    v10 = result;
  }
  else
  {
    v10 = nullptr;
    result = nullptr;
  }
  if ( result == nullptr )
    return result;
  qmemcpy((char *)result + 16, (char *)this + 16, 0x2Cu);
  *((_DWORD *)result + 21) = *((_DWORD *)this + 21);
  *((_DWORD *)result + 22) = *((_DWORD *)this + 22);
  if ( *((_DWORD *)this + 15) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 15) + 4))(a1: *((_DWORD *)this + 15));
    *((_DWORD *)v10 + 15) = v4;
    if ( v4 == 0 )
      return nullptr;
    result = v10;
  }
  if ( *((_DWORD *)this + 16) != 0 )
  {
    v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 16) + 4))(a1: *((_DWORD *)this + 16));
    *((_DWORD *)v10 + 16) = v5;
    if ( v5 == 0 )
      return nullptr;
    result = v10;
  }
  v9 = 0;
  v6 = (_DWORD *)((char *)this + 68);
  v7 = result - this;
  do
  {
    if ( *v6 != 0 )
    {
      v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v6 + 4))(a1: *v6);
      *(_DWORD *)((char *)v6 + v7) = v8;
      if ( v8 == 0 )
        return nullptr;
      result = v10;
    }
    ++v9;
    ++v6;
  }
  while ( v9 < 4 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CA3C
// Name: public: virtual class D3DXShader::CNodeAsmRegister __near * D3DXShader::CNodeAsmRegister::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeAsmRegister *__thiscall D3DXShader::CNodeAsmRegister::Copy(D3DXShader::CNodeAsmRegister *this)
{
  unsigned __int8 *v2; // eax
  D3DXShader::CNodeAsmRegister *v3; // esi
  int v4; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x2Cu);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeAsmRegister::CNodeAsmRegister(this: (D3DXShader::CNodeAsmRegister *)v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  *((_DWORD *)v3 + 4) = *((_DWORD *)this + 4);
  *((_DWORD *)v3 + 5) = *((_DWORD *)this + 5);
  *((_DWORD *)v3 + 6) = *((_DWORD *)this + 6);
  *((_DWORD *)v3 + 7) = *((_DWORD *)this + 7);
  *((_DWORD *)v3 + 8) = *((_DWORD *)this + 8);
  *((_DWORD *)v3 + 9) = *((_DWORD *)this + 9);
  if ( *((_DWORD *)this + 10) == 0 )
    return v3;
  v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 4))(a1: *((_DWORD *)this + 10));
  *((_DWORD *)v3 + 10) = v4;
  if ( v4 != 0 )
    return v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045CAA0
// Name: public: D3DXShader::CInstruction::CInstruction(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CInstruction *__thiscall D3DXShader::CInstruction::CInstruction(D3DXShader::CInstruction *this)
{
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 13) = -1;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045CAD6
// Name: public: long D3DXShader::CInstruction::Instance(class D3DXShader::CInstruction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CInstruction::Instance(D3DXShader::CInstruction *this, struct D3DXShader::CInstruction *a2)
{
  if ( a2 == nullptr )
    return -2147467259;
  *((_DWORD *)this + 15) = *((_DWORD *)a2 + 15);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045CAF5
// Name: public: unsigned int D3DXShader::CInstruction::GetInputs(unsigned int,unsigned int __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CInstruction::GetInputs(D3DXShader::CInstruction *this, unsigned int a2, unsigned int **a3)
{
  int result; // eax

  result = *(_DWORD *)this & 0xFFFFF;
  if ( a2 * result + result <= *((_DWORD *)this + 1) )
  {
    if ( a3 != nullptr )
      *a3 = (unsigned int *)(*((_DWORD *)this + 2) + 4 * a2 * result);
  }
  else
  {
    if ( a3 != nullptr )
      *a3 = nullptr;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CB32
// Name: public: int D3DXShader::CInstruction::IsSpecial(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsSpecial(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax
  BOOL result; // eax

  result = true;
  if ( (*(_DWORD *)this & 0xF0000000) != 0x60000000 )
  {
    v1 = *(_DWORD *)this & 0xFFF00000;
    if ( v1 != 1343225856 && v1 != 1344274432 && v1 != 1345323008 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CB65
// Name: public: int D3DXShader::CInstruction::IsScalar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsScalar(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  return v1 == 271581184 || v1 == 273678336 || v1 == 274726912 || v1 == 275775488;
}

//------------------------------------------------------------------------------
// Address: 0x0045CB8F
// Name: public: int D3DXShader::CInstruction::IsSymetric(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsSymetric(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  return v1 == 0x20000000 || v1 == 537919488 || v1 == 541065216 || v1 == 542113792 || v1 == 1342177280;
}

//------------------------------------------------------------------------------
// Address: 0x0045CBC0
// Name: public: int D3DXShader::CInstruction::IsCopy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsCopy(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  return v1 == 0x10000000 || v1 == 269484032 || v1 == 287309824 || v1 == 544210944 || v1 == 545259520 || v1 == 546308096;
}

//------------------------------------------------------------------------------
// Address: 0x0045CBF8
// Name: public: int D3DXShader::CInstruction::IsMacro(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsMacro(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  if ( v1 > 0x70700000 )
  {
    if ( v1 == 1890582528 || v1 == 1891631104 || v1 == 1892679680 )
      return true;
    return v1 == 1895825408;
  }
  else
  {
    if ( v1 == 1886388224 || v1 == 1345323008 || v1 == 1880096768 || v1 == 1881145344 || v1 == 1884291072 )
      return true;
    return v1 == 1885339648;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CC50
// Name: public: int D3DXShader::CInstruction::IsLoop(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsLoop(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  if ( v1 > 0x74200000 )
  {
    if ( v1 == 1949302784
      || v1 == 1950351360
      || v1 == 1951399936
      || v1 == 1952448512
      || v1 == 1953497088
      || v1 == 1956642816 )
    {
      return true;
    }
    return v1 == 1957691392;
  }
  else
  {
    if ( v1 == 1948254208 )
      return true;
    if ( v1 > 0x11500000 )
    {
      if ( v1 == 545259520 || v1 == 546308096 )
        return true;
      return v1 == 1947205632;
    }
    else
    {
      if ( v1 == 290455552 || v1 == 286261248 || v1 == 287309824 || v1 == 288358400 )
        return true;
      return v1 == 289406976;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CCD6
// Name: public: int D3DXShader::CInstruction::IsElse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsElse(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  return v1 == 1930428416
      || v1 == 1932525568
      || v1 == 1943011328
      || v1 == 1944059904
      || v1 == 1945108480
      || v1 == 1946157056;
}

//------------------------------------------------------------------------------
// Address: 0x0045CD0E
// Name: public: int D3DXShader::CInstruction::IsEndIf(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsEndIf(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  return v1 == 544210944 || v1 == 1933574144;
}

//------------------------------------------------------------------------------
// Address: 0x0045CD2A
// Name: public: int D3DXShader::CInstruction::IsFlowControl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsFlowControl(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  if ( v1 > 0x73800000 )
  {
    if ( v1 > 0x74100000 )
    {
      if ( v1 > 0x74600000 )
      {
        if ( v1 == 1953497088 || v1 == 1956642816 )
          return true;
        return v1 == 1957691392;
      }
      else
      {
        if ( v1 == 1952448512 || v1 == 1948254208 || v1 == 1949302784 || v1 == 1950351360 )
          return true;
        return v1 == 1951399936;
      }
    }
    else
    {
      if ( v1 == 1947205632 )
        return true;
      if ( v1 > 0x73D00000 )
      {
        if ( v1 == 1944059904 || v1 == 1945108480 )
          return true;
        return v1 == 1946157056;
      }
      else
      {
        if ( v1 == 1943011328 || v1 == 1938817024 || v1 == 1939865600 || v1 == 1940914176 )
          return true;
        return v1 == 1941962752;
      }
    }
  }
  else
  {
    if ( v1 == 1937768448 )
      return true;
    if ( v1 > 0x20900000 )
    {
      if ( v1 > 0x73400000 )
      {
        if ( v1 == 1934622720 || v1 == 1935671296 )
          return true;
        return v1 == 1936719872;
      }
      else
      {
        if ( v1 == 1933574144 || v1 == 1929379840 || v1 == 1930428416 || v1 == 1931476992 )
          return true;
        return v1 == 1932525568;
      }
    }
    else
    {
      if ( v1 == 546308096 )
        return true;
      if ( v1 > 0x11400000 )
      {
        if ( v1 == 290455552 || v1 == 544210944 )
          return true;
        return v1 == 545259520;
      }
      else
      {
        if ( v1 == 289406976 || v1 == 284164096 || v1 == 286261248 || v1 == 287309824 )
          return true;
        return v1 == 288358400;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CE91
// Name: public: int D3DXShader::CInstruction::IsGradient(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsGradient(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  if ( v1 > 0x60800000 )
  {
    if ( v1 == 1621098496 || v1 == 1623195648 || v1 == 1624244224 || v1 == 1626341376 || v1 == 1628438528 )
      return true;
    return v1 == 1629487104;
  }
  else
  {
    if ( v1 == 1619001344
      || v1 == 282066944
      || v1 == 283115520
      || v1 == 1610612736
      || v1 == 1612709888
      || v1 == 1613758464
      || v1 == 1615855616 )
    {
      return true;
    }
    return v1 == 1617952768;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CF05
// Name: public: static void D3DXShader::CInstruction::SetAlloc(class D3DXCore::CAlloc __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __stdcall D3DXShader::CInstruction::SetAlloc(struct D3DXCore::CAlloc *a1)
{
  D3DXShader::CInstruction::s_pFree = nullptr;
  D3DXShader::CInstruction::s_pAlloc = a1;
}

//------------------------------------------------------------------------------
// Address: 0x0045CF1D
// Name: public: static unsigned int __near * D3DXShader::CInstruction::Alloc(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static unsigned __int8 *__stdcall D3DXShader::CInstruction::Alloc(unsigned int a1)
{
  return D3DXCore::CAlloc::Alloc(this: D3DXShader::CInstruction::s_pAlloc, a2: 4 * a1, a3: 0x10u);
}

//------------------------------------------------------------------------------
// Address: 0x004C9AF6
// Name: __Tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _Tolower(int c, const _Ctypevec *ploc)
{
  const _Ctypevec *v2; // esi
  unsigned int Page; // eax
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  bool v8; // zf
  UINT codepage; // [esp+4h] [ebp-10h]
  LCID handle; // [esp+8h] [ebp-Ch]
  int v11; // [esp+Ch] [ebp-8h]
  char outbuffer[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = ploc;
  if ( ploc != nullptr )
  {
    handle = ploc->_Hand;
    Page = ploc->_Page;
  }
  else
  {
    handle = ___lc_handle_func()[2];
    Page = ___lc_codepage_func();
  }
  codepage = Page;
  if ( handle == 0 )
  {
    result = c;
    if ( (unsigned int)(c - 65) <= 0x19 )
      return c + 32;
    return result;
  }
  if ( (unsigned int)c < 0x100 )
  {
    if ( v2 == nullptr )
    {
      if ( isupper(c) == 0 )
        return c;
      goto LABEL_13;
    }
    if ( (v2->_Table[c] & 1) == 0 )
      return c;
  }
  if ( v2 == nullptr )
  {
LABEL_13:
    v11 = c >> 8;
    v5 = __pctype_func()[BYTE1(c)] & 0x8000;
    goto LABEL_15;
  }
  v11 = c >> 8;
  v5 = v2->_Table[BYTE1(c)] < 0;
LABEL_15:
  if ( v5 != 0 )
  {
    LOBYTE(ploc) = v11;
    *(_WORD *)((char *)&ploc + 1) = (unsigned __int8)c;
    v6 = 2;
  }
  else
  {
    LOWORD(ploc) = (unsigned __int8)c;
    v6 = 1;
  }
  v7 = __crtLCMapStringA(
         plocinfo: nullptr,
         Locale: handle,
         dwMapFlags: 0x100u,
         lpSrcStr: (const char *)&ploc,
         cchSrc: v6,
         lpDestStr: outbuffer,
         cchDest: 3,
         code_page: codepage,
         bError: 1);
  if ( v7 == 0 )
    return c;
  v8 = v7 == 1;
  result = (unsigned __int8)outbuffer[0];
  if ( !v8 )
    return (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C9C03
// Name: __Getctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_Ctypevec *_Getctype(_Ctypevec *result, ...)
{
  unsigned __int8 *v1; // eax
  unsigned __int8 *v2; // eax
  const __int16 *v3; // eax

  result->_Hand = ___lc_handle_func()[1];
  result->_Page = ___lc_codepage_func();
  v1 = calloc(count: 0x100u, size: 2u);
  result->_Table = (const __int16 *)v1;
  if ( v1 != nullptr )
  {
    v2 = (unsigned __int8 *)__pctype_func();
    memcpy(dst: (unsigned __int8 *)result->_Table, src: v2, count: 0x200u);
    result->_Delfl = 1;
  }
  else
  {
    v3 = (const __int16 *)__pctype_func();
    result->_Delfl = 0;
    result->_Table = v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C9C63
// Name: __Getcvt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int _Getcvt()
{
  unsigned int v0; // esi

  v0 = ___lc_handle_func()[2];
  ___lc_codepage_func();
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x004C9C79
// Name: public: std::_Init_locks::_Init_locks(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Init_locks *__thiscall std::_Init_locks::_Init_locks(std::_Init_locks *this)
{
  _RTL_CRITICAL_SECTION *v2; // esi

  if ( InterlockedIncrement(lpAddend: &init) == 0 )
  {
    v2 = mtx;
    do
      _Mtxinit(_Mtx: v2++);
    while ( (int)v2 < (int)&initlocks );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C9CAA
// Name: public: std::_Init_locks::~_Init_locks(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::_Init_locks::~_Init_locks(std::_Init_locks *this)
{
  _RTL_CRITICAL_SECTION *v1; // esi

  if ( InterlockedDecrement(lpAddend: &init) < 0 )
  {
    v1 = mtx;
    do
      _Mtxdst(_Mtx: v1++);
    while ( (int)v1 < (int)&initlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C9CD3
// Name: public: std::_Lockit::_Lockit(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Lockit *__thiscall std::_Lockit::_Lockit(std::_Lockit *this, int kind)
{
  this->_Locktype = kind;
  if ( kind < 4 )
    _Mtxlock(_Mtx: &mtx[kind]);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C9CFB
// Name: public: std::_Lockit::~_Lockit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::_Lockit::~_Lockit(std::_Lockit *this)
{
  if ( this->_Locktype < 4 )
    _Mtxunlock(_Mtx: &mtx[this->_Locktype]);
}

//------------------------------------------------------------------------------
// Address: 0x004C9D12
// Name: public: std::_Fac_node::~_Fac_node(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::_Fac_node::~_Fac_node(std::_Fac_node *this)
{
  std::locale::facet *v1; // eax

  v1 = std::locale::facet::_Decref(this: this->_Facptr);
  if ( v1 != nullptr )
    ((void (__thiscall *)(std::locale::facet *, int))v1->dtr_facet)(a1: v1, a2: 1);
}

} // namespace subdbaker

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00418240
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00418260
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00418280
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004182A0
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004182B0
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x00418330
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace vcdupdate

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x100A1E60
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100A1E80
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100A1EA0
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100A1EC0
// Name: public: bool CP4Factory::SetDummyMode(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4Factory::SetDummyMode(CP4Factory *this, bool bDummyMode)
{
  bool result; // al

  result = this->m_bDummyMode;
  this->m_bDummyMode = bDummyMode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1ED0
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x100A1F50
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace vtex_dll

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00410CC0
// Name: public: virtual bool CP4File::Edit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Edit(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForEdit(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00410CE0
// Name: public: virtual bool CP4File::Add(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::Add(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->OpenFileForAdd(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00410D00
// Name: public: virtual bool CP4File::IsFileInPerforce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4File::IsFileInPerforce(CP4File *this)
{
  const char *v1; // eax

  v1 = CUtlString::operator char const *(this: &this->m_sFilename);
  return p4->IsFileInPerforce(this: p4, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00410D20
// Name: public: void CP4Factory::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Factory::SetOpenFileChangeList(CP4Factory *this, const char *szChangeListName)
{
  if ( !this->m_bDummyMode )
    p4->SetOpenFileChangeList(this: p4, a2: szChangeListName);
}

//------------------------------------------------------------------------------
// Address: 0x00410DA0
// Name: public: class CP4File __near * CP4Factory::AccessFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CP4File *__thiscall CP4Factory::AccessFile(CP4Factory *this, char *szFilename)
{
  char *v2; // esi
  char *v4; // eax
  _DWORD *v5; // esi

  if ( this->m_bDummyMode )
  {
    v4 = (char *)operator new(nSize: 0x14u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *(_DWORD *)v4 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v4 + 4), pString: szFilename);
      *v5 = &CP4File_Dummy::`vftable';
      return (CP4File *)v5;
    }
  }
  else
  {
    v2 = (char *)operator new(nSize: 0x14u);
    if ( v2 != nullptr )
    {
      *(_DWORD *)v2 = &CP4File::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)(v2 + 4), pString: szFilename);
      return (CP4File *)v2;
    }
  }
  return nullptr;
}

} // namespace vtex_gui
