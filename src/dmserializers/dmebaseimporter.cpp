// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/dmebaseimporter.cpp
// Functions: 3
// ============================================================

#include "dmserializers\dmebaseimporter.h"

//------------------------------------------------------------------------------
// Address: 0x0045D060
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045D080
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D0E0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00472A40
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00472A60
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472AC0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004AF550
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AF570
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AF5D0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104BF390
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104BF3B0
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104BF410
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00495800
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 176))(
           a1: g_pDataModel.u,
           a2: this->m_pNextSerializer) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00495820
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  int v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 176))(
                   a1: g_pDataModel.u,
                   a2: this->m_pNextSerializer)) == 0
        || (*(bool (__thiscall **)(int, CDmElement **))(*(_DWORD *)v4 + 8))(a1: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495880
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00519410
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00519430
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00519490
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D9A20
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 176))(
           a1: g_pDataModel.u,
           a2: this->m_pNextSerializer) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D9A40
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  int v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 176))(
                   a1: g_pDataModel.u,
                   a2: this->m_pNextSerializer)) == 0
        || (*(bool (__thiscall **)(int, CDmElement **))(*(_DWORD *)v4 + 8))(a1: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9AA0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0045EB40
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EB60
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045EBC0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00460630
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460650
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004606B0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00469150
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00469170
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004691C0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0045EAC0
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EAE0
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00463A30
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463A50
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463AB0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B9BA0
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 176))(
           a1: g_pDataModel.u,
           a2: this->m_pNextSerializer) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B9BC0
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  int v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 176))(
                   a1: g_pDataModel.u,
                   a2: this->m_pNextSerializer)) == 0
        || (*(bool (__thiscall **)(int, CDmElement **))(*(_DWORD *)v4 + 8))(a1: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B9C20
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00464600
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00464620
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00464680
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D2FB0
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 176))(
           a1: g_pDataModel.u,
           a2: this->m_pNextSerializer) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D2FD0
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  int v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 176))(
                   a1: g_pDataModel.u,
                   a2: this->m_pNextSerializer)) == 0
        || (*(bool (__thiscall **)(int, CDmElement **))(*(_DWORD *)v4 + 8))(a1: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D3030
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0046EE80
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046EEA0
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046EF00
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00566730
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00566750
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005667B0
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10091580
// Name: public: virtual bool CDmeBaseImporter::IsLatestVersion(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeBaseImporter::IsLatestVersion(CDmeBaseImporter *this)
{
  return g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100915A0
// Name: public: virtual bool CDmeBaseImporter::Update(class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBaseImporter::Update(CDmeBaseImporter *this, CDmElement **ppRoot)
{
  bool result; // al
  IDmLegacyUpdater *v4; // eax

  result = this->DoFixup(this, a2: *ppRoot);
  if ( result )
    return this->m_pNextSerializer == nullptr
        || (v4 = g_pDataModel->FindLegacyUpdater(this: g_pDataModel, a2: this->m_pNextSerializer)) == nullptr
        || v4->Update(this: v4, a2: ppRoot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10091600
// Name: public: CSFMBaseImporter::CSFMBaseImporter(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSFMBaseImporter *__thiscall CSFMBaseImporter::CSFMBaseImporter(
        CSFMBaseImporter *this,
        const char *formatName,
        const char *nextFormatName)
{
  this->m_pFormatName = formatName;
  this->m_pNextSerializer = nextFormatName;
  this->__vftable = (CSFMBaseImporter_vtbl *)&CSFMBaseImporter::`vftable';
  return this;
}

} // namespace vtex_dll
