// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importcommentary.cpp
// Functions: 7
// ============================================================

#include "dmserializers\importcommentary.h"

//------------------------------------------------------------------------------
// Address: 0x0045C970
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x0045C990
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x0045C9C0
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x0045C9F0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x0045CA00
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x0045CA10
// Name: protected: virtual class CDmElement __near * CImportCommentary::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportCommentary::UnserializeFromKeyValues(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045CA20
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00472350
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x00472370
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x004723A0
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x004723D0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x004723E0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x004723F0
// Name: protected: virtual class CDmElement __near * CImportCommentary::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportCommentary::UnserializeFromKeyValues(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00472400
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004AEE60
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x004AEE80
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x004AEEB0
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x004AEEE0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x004AEEF0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x004AEF00
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104BECB0
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x104BECD0
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x104BED00
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x104BED30
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x104BED40
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x104BED50
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00495120
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x00495140
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
         a1: g_pDataModel.u,
         a2: "keyvalues");
  return v3 != 0
      && (*(bool (__thiscall **)(int, CUtlBuffer *, CDmElement *))(*(_DWORD *)v3 + 20))(a1: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x00495170
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x004951A0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x004951B0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x004951C0
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  int v10; // esi
  char v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
          a1: g_pDataModel.u,
          a2: "keyvalues");
  if ( v10 == 0 )
    return 0;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement ***))(*(_DWORD *)g_pDataModel.u.m_Id + 192))(
    a1: g_pDataModel.u,
    a2: &ppRoot);
  v12 = (*(int (__thiscall **)(int, CUtlBuffer *, const char *, int, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)v10 + 24))(
          a1: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 192))(
    a1: g_pDataModel.u,
    a2: 0);
  return v12;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00518D20
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x00518D40
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x00518D70
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x00518DA0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x00518DB0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x00518DC0
// Name: protected: virtual class CDmElement __near * CImportCommentary::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportCommentary::UnserializeFromKeyValues(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00518DD0
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D9330
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x004D9350
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
         a1: g_pDataModel.u,
         a2: "keyvalues");
  return v3 != 0
      && (*(bool (__thiscall **)(int, CUtlBuffer *, CDmElement *))(*(_DWORD *)v3 + 20))(a1: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x004D9380
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x004D93B0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x004D93C0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x004D93E0
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  int v10; // esi
  char v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
          a1: g_pDataModel.u,
          a2: "keyvalues");
  if ( v10 == 0 )
    return 0;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement ***))(*(_DWORD *)g_pDataModel.u.m_Id + 192))(
    a1: g_pDataModel.u,
    a2: &ppRoot);
  v12 = (*(int (__thiscall **)(int, CUtlBuffer *, const char *, int, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)v10 + 24))(
          a1: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 192))(
    a1: g_pDataModel.u,
    a2: 0);
  return v12;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0045E450
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x0045E470
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x0045E4A0
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x0045E4D0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x0045E4E0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x0045E4F0
// Name: protected: virtual class CDmElement __near * CImportCommentary::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportCommentary::UnserializeFromKeyValues(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045E500
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0045FF40
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x0045FF60
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x0045FF90
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x0045FFC0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x0045FFD0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x0045FFF0
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace particle_import

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0045E3D0
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x0045E3F0
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x0045E420
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x0045E460
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x0045E480
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00463340
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x00463360
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x00463390
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x004633C0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x004633D0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x004633E0
// Name: protected: virtual class CDmElement __near * CImportCommentary::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportCommentary::UnserializeFromKeyValues(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004633F0
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B94C0
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x004B94E0
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
         a1: g_pDataModel.u,
         a2: "keyvalues");
  return v3 != 0
      && (*(bool (__thiscall **)(int, CUtlBuffer *, CDmElement *))(*(_DWORD *)v3 + 20))(a1: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x004B9510
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x004B9540
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x004B9550
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x004B9560
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  int v10; // esi
  char v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
          a1: g_pDataModel.u,
          a2: "keyvalues");
  if ( v10 == 0 )
    return 0;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement ***))(*(_DWORD *)g_pDataModel.u.m_Id + 192))(
    a1: g_pDataModel.u,
    a2: &ppRoot);
  v12 = (*(int (__thiscall **)(int, CUtlBuffer *, const char *, int, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)v10 + 24))(
          a1: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 192))(
    a1: g_pDataModel.u,
    a2: 0);
  return v12;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00463F00
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x00463F20
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x00463F50
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x00463F80
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x00463F90
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x00463FA0
// Name: protected: virtual class CDmElement __near * CImportCommentary::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportCommentary::UnserializeFromKeyValues(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463FB0
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D28C0
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x004D28E0
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
         a1: g_pDataModel.u,
         a2: "keyvalues");
  return v3 != 0
      && (*(bool (__thiscall **)(int, CUtlBuffer *, CDmElement *))(*(_DWORD *)v3 + 20))(a1: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x004D2910
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x004D2940
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x004D2950
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x004D2970
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  int v10; // esi
  char v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
          a1: g_pDataModel.u,
          a2: "keyvalues");
  if ( v10 == 0 )
    return 0;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement ***))(*(_DWORD *)g_pDataModel.u.m_Id + 192))(
    a1: g_pDataModel.u,
    a2: &ppRoot);
  v12 = (*(int (__thiscall **)(int, CUtlBuffer *, const char *, int, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)v10 + 24))(
          a1: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 192))(
    a1: g_pDataModel.u,
    a2: 0);
  return v12;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0046E790
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x0046E7B0
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x0046E7E0
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x0046E810
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x0046E820
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x0046E830
// Name: protected: virtual class CDmElement __near * CImportCommentary::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportCommentary::UnserializeFromKeyValues(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046E840
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00566040
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x00566060
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x00566090
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x005660C0
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x005660D0
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x005660E0
// Name: protected: virtual class CDmElement __near * CImportCommentary::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportCommentary::UnserializeFromKeyValues(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005660F0
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10090E90
// Name: void InstallCommentaryImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallCommentaryImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x10090EB0
// Name: public: virtual bool CImportCommentary::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Serialize(CImportCommentary *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  IDmSerializer *v3; // eax

  v3 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  return v3 != nullptr && v3->Serialize(this: v3, a2: buf, a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x10090EE0
// Name: public: virtual char const __near * CElementForKeyValueCallback::GetElementForKeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CElementForKeyValueCallback::GetElementForKeyValue(
        CElementForKeyValueCallback *this,
        const char *pszKeyName,
        int iNestingLevel)
{
  if ( iNestingLevel != 1 || V_strncmp(s1: pszKeyName, s2: "entity", count: 6) != 0 )
    return nullptr;
  else
    return "DmeCommentaryNodeEntity";
}

//------------------------------------------------------------------------------
// Address: 0x10090F10
// Name: public: virtual char const __near * CImportCommentary::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetName(CImportCommentary *this)
{
  return "commentary";
}

//------------------------------------------------------------------------------
// Address: 0x10090F20
// Name: public: virtual char const __near * CImportCommentary::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportCommentary::GetDescription(CImportCommentary *this)
{
  return "Commentary File";
}

//------------------------------------------------------------------------------
// Address: 0x10090F40
// Name: public: virtual bool CImportCommentary::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportCommentary::Unserialize(
        CImportCommentary *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement **v9; // edi
  IDmSerializer *v10; // esi
  bool v12; // bl

  v9 = ppRoot;
  *ppRoot = nullptr;
  v10 = g_pDataModel->FindSerializer(this: g_pDataModel, a2: "keyvalues");
  if ( v10 == nullptr )
    return false;
  ppRoot = (CDmElement **)&CElementForKeyValueCallback::`vftable';
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: (IElementForKeyValueCallback *)&ppRoot);
  v12 = v10->Unserialize(
          this: v10,
          a2: buf,
          a3: "keyvalues",
          a4: nEncodingVersion,
          a5: pSourceFormatName,
          a6: nSourceFormatVersion,
          a7: fileid,
          a8: idConflictResolution,
          a9: v9);
  g_pDataModel->SetKeyValuesElementCallback(this: g_pDataModel, a2: nullptr);
  return v12;
}

} // namespace vtex_dll
