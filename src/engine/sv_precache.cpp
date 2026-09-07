// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_precache.cpp
// Functions: 23
// ============================================================

#include "engine\sv_precache.h"

//------------------------------------------------------------------------------
// Address: 0x1012ABF0
// Name: void SV_ForceExactFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_ForceExactFile(int a1@<edi>, int a2@<esi>, char *name)
{
  CDownloadListGenerator *v3; // eax

  v3 = DownloadListGenerator();
  CDownloadListGenerator::ForceExactFile(
    this: v3,
    a2: a1,
    a3: a2,
    relativePathFileName: name,
    consistency: CONSISTENCY_EXACT);
}

//------------------------------------------------------------------------------
// Address: 0x1012AC10
// Name: void SV_ForceSimpleMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_ForceSimpleMaterial(int a1@<edi>, int a2@<esi>, char *name)
{
  CDownloadListGenerator *v3; // eax

  v3 = DownloadListGenerator();
  CDownloadListGenerator::ForceExactFile(
    this: v3,
    a2: a1,
    a3: a2,
    relativePathFileName: name,
    consistency: CONSISTENCY_SIMPLE_MATERIAL);
}

//------------------------------------------------------------------------------
// Address: 0x1012AC30
// Name: void SV_ForceModelBounds(char const __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_ForceModelBounds(int a1@<edi>, const char *name, const Vector *mins, const Vector *maxs)
{
  CDownloadListGenerator *v4; // eax

  v4 = DownloadListGenerator();
  CDownloadListGenerator::ForceModelBounds(this: v4, a2: a1, relativePathFileName: name, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1012AC50
// Name: public: class INetworkStringTable __near * CGameServer::GetModelPrecacheTable(void)const
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CGameServer::GetModelPrecacheTable(CGameServer *this)
{
  return this->m_pModelPrecacheTable;
}

//------------------------------------------------------------------------------
// Address: 0x1012AC60
// Name: public: int CGameServer::LookupModelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameServer::LookupModelIndex(CGameServer *this, const char *name)
{
  int result; // eax

  if ( this->m_pModelPrecacheTable == nullptr )
    return -1;
  result = this->m_pModelPrecacheTable->FindStringIndex(this: this->m_pModelPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012AC90
// Name: public: class INetworkStringTable __near * CGameServer::GetSoundPrecacheTable(void)const
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CGameServer::GetSoundPrecacheTable(CGameServer *this)
{
  return this->m_pSoundPrecacheTable;
}

//------------------------------------------------------------------------------
// Address: 0x1012ACA0
// Name: public: char const __near * CGameServer::GetSound(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameServer::GetSound(CGameServer *this, int index)
{
  if ( index > 0
    && this->m_pSoundPrecacheTable != nullptr
    && index < this->m_pSoundPrecacheTable->GetNumStrings(this: this->m_pSoundPrecacheTable) )
  {
    return CPrecacheItem::GetSound(this: &this->sound_precache[index]);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012ACF0
// Name: public: int CGameServer::LookupSoundIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameServer::LookupSoundIndex(CGameServer *this, const char *name)
{
  int v3; // eax

  if ( this->m_pSoundPrecacheTable == nullptr )
    return 0;
  v3 = this->m_pSoundPrecacheTable->FindStringIndex(this: this->m_pSoundPrecacheTable, a2: name);
  return v3 != 0xFFFF ? v3 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012AD30
// Name: public: int CGameServer::PrecacheGeneric(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CGameServer::PrecacheGeneric@<eax>(
        CGameServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *name,
        int flags)
{
  int v7; // esi
  CMapReslistGenerator *v8; // eax

  if ( this->m_pGenericPrecacheTable == nullptr )
    return -1;
  v7 = this->m_pGenericPrecacheTable->AddString(
         this: this->m_pGenericPrecacheTable,
         a2: true,
         a3: name,
         a4: -1,
         a5: nullptr);
  if ( v7 == 0xFFFF )
    return -1;
  v8 = MapReslistGenerator();
  CMapReslistGenerator::OnResourcePrecached(this: v8, relativePathFileName: name);
  ((void (__thiscall *)(INetworkStringTable *, int, _DWORD, int, int))this->m_pGenericPrecacheTable->GetStringUserData)(
    a1: this->m_pGenericPrecacheTable,
    a2: v7,
    a3: 0,
    a4: a3,
    a5: a2);
  ((void (__thiscall *)(INetworkStringTable *, int))this->m_pGenericPrecacheTable->SetStringUserData)(
    a1: this->m_pGenericPrecacheTable,
    a2: v7);
  CPrecacheItem::SetGeneric(this: &this->generic_precache[v7], pname: name);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1012ADE0
// Name: public: int CGameServer::PrecacheDecal(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CGameServer::PrecacheDecal@<eax>(
        CGameServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *name,
        int flags)
{
  int v7; // esi
  CMapReslistGenerator *v8; // eax

  if ( this->m_pDecalPrecacheTable == nullptr )
    return -1;
  v7 = this->m_pDecalPrecacheTable->AddString(
         this: this->m_pDecalPrecacheTable,
         a2: true,
         a3: name,
         a4: -1,
         a5: nullptr);
  if ( v7 == 0xFFFF )
    return -1;
  v8 = MapReslistGenerator();
  CMapReslistGenerator::OnResourcePrecached(this: v8, relativePathFileName: name);
  ((void (__thiscall *)(INetworkStringTable *, int, _DWORD, int, int))this->m_pDecalPrecacheTable->GetStringUserData)(
    a1: this->m_pDecalPrecacheTable,
    a2: v7,
    a3: 0,
    a4: a3,
    a5: a2);
  ((void (__thiscall *)(INetworkStringTable *, int))this->m_pDecalPrecacheTable->SetStringUserData)(
    a1: this->m_pDecalPrecacheTable,
    a2: v7);
  CPrecacheItem::SetDecal(this: &this->decal_precache[v7], decalname: name);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1012AE90
// Name: public: void CGameServer::DumpPrecacheStats(class INetworkStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::DumpPrecacheStats(CGameServer *this, INetworkStringTable *table)
{
  CPrecacheItem *model_precache; // ecx
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  CAudioDeviceNull *v7; // ebx
  _BYTE *v8; // eax
  const char *FlagString; // eax
  unsigned int ReferenceCount; // eax
  double v11; // [esp+0h] [ebp-28h]
  int v12; // [esp+8h] [ebp-20h]
  double v13; // [esp+8h] [ebp-20h]
  int v14; // [esp+Ch] [ebp-1Ch]
  int v15; // [esp+1Ch] [ebp-Ch]
  _BYTE *v16; // [esp+20h] [ebp-8h]
  int v17; // [esp+24h] [ebp-4h] BYREF
  CPrecacheItem *v18; // [esp+30h] [ebp+8h]
  const char *v19; // [esp+30h] [ebp+8h]

  if ( table == nullptr )
  {
    ConMsg(a1: "Can only dump stats when active in a level\n");
    return;
  }
  if ( table == this->m_pModelPrecacheTable )
  {
    model_precache = this->model_precache;
  }
  else if ( table == this->m_pGenericPrecacheTable )
  {
    model_precache = this->generic_precache;
  }
  else if ( table == this->m_pSoundPrecacheTable )
  {
    model_precache = this->sound_precache;
  }
  else
  {
    if ( table != this->m_pDecalPrecacheTable )
      return;
    model_precache = this->decal_precache;
  }
  v18 = model_precache;
  if ( model_precache != nullptr )
  {
    v15 = table->GetNumStrings(this: table);
    v4 = table->GetMaxStrings(this: table);
    ConMsg(a1: "\n");
    v5 = (const char *)((int (__thiscall *)(INetworkStringTable *, int, int))table->GetTableName)(
                         a1: table,
                         a2: v15,
                         a3: v4);
    ConMsg(a1: "Precache table %s:  %i of %i slots used\n", v5, v12, v14);
    v6 = 0;
    if ( v15 > 0 )
    {
      v7 = (CAudioDeviceNull *)v18;
      do
      {
        v19 = table->GetString(this: table, a2: v6);
        v8 = table->GetStringUserData(this: table, a2: v6, a3: &v17);
        v16 = v8;
        if ( v17 != 1 )
        {
          _Error(a1: "CGameServer::DumpPrecacheStats: invalid CPrecacheUserData length (%d)", v17);
          v8 = v16;
        }
        if ( v19 != nullptr && v7 != nullptr && v8 != nullptr )
        {
          FlagString = GetFlagString(flags: *v8 & 3);
          ConMsg(a1: "%03i:  %s (%s):   ", v6, v19, FlagString);
          if ( CPrecacheItem::GetReferenceCount(this: (CPrecacheItem *)v7) != 0 )
          {
            v13 = CAudioDeviceWave::MixDryVolume(this: v7);
            v11 = CAudioDeviceWave::MixDryVolume(this: v7);
            ReferenceCount = CPrecacheItem::GetReferenceCount(this: (CPrecacheItem *)v7);
            ConMsg(a1: " %i refs, first %.2f mru %.2f\n", ReferenceCount, v11, v13);
          }
          else
          {
            ConMsg(a1: " never used\n");
          }
        }
        ++v6;
        ++v7;
      }
      while ( v6 < v15 );
    }
    ConMsg(a1: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B030
// Name: int SV_ModelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_ModelIndex(const char *name)
{
  int result; // eax

  if ( sv.m_pModelPrecacheTable == nullptr )
    return -1;
  result = sv.m_pModelPrecacheTable->FindStringIndex(this: sv.m_pModelPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012B060
// Name: int SV_SoundIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_SoundIndex(const char *name)
{
  int v2; // eax

  if ( sv.m_pSoundPrecacheTable == nullptr )
    return 0;
  v2 = sv.m_pSoundPrecacheTable->FindStringIndex(this: sv.m_pSoundPrecacheTable, a2: name);
  return v2 != 0xFFFF ? v2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B090
// Name: int SV_GenericIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_GenericIndex(const char *name)
{
  int v2; // eax

  if ( sv.m_pGenericPrecacheTable == nullptr )
    return 0;
  v2 = sv.m_pGenericPrecacheTable->FindStringIndex(this: sv.m_pGenericPrecacheTable, a2: name);
  return v2 != 0xFFFF ? v2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B0C0
// Name: int SV_FindOrAddGeneric(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_FindOrAddGeneric@<eax>(int a1@<ebx>, int a2@<esi>, const char *name, bool preload)
{
  int v4; // eax

  v4 = 1;
  if ( preload )
    v4 = 3;
  return CGameServer::PrecacheGeneric(this: &sv, a2: a1, a3: a2, name, flags: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1012B0F0
// Name: int SV_DecalIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_DecalIndex(const char *name)
{
  int result; // eax

  if ( sv.m_pDecalPrecacheTable == nullptr )
    return -1;
  result = sv.m_pDecalPrecacheTable->FindStringIndex(this: sv.m_pDecalPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012B120
// Name: int SV_FindOrAddDecal(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_FindOrAddDecal@<eax>(int a1@<ebx>, int a2@<esi>, const char *name, bool preload)
{
  int v4; // eax

  v4 = 1;
  if ( preload )
    v4 = 3;
  return CGameServer::PrecacheDecal(this: &sv, a2: a1, a3: a2, name, flags: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1012B150
// Name: public: int CGameServer::PrecacheModel(char const __near *,int,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CGameServer::PrecacheModel@<eax>(
        CGameServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *name,
        char flags,
        model_t *model)
{
  int v8; // edi
  CPrecacheItem *v9; // esi
  bool v10; // bl
  int v11; // eax
  int v12; // eax
  int v13; // eax
  IModelLoader_vtbl *v14; // edx
  const model_t *v15; // eax
  IEngineVGuiInternal *v16; // eax
  CMapReslistGenerator *v17; // eax

  if ( this->m_pModelPrecacheTable == nullptr )
    return -1;
  v8 = this->m_pModelPrecacheTable->AddString(
         this: this->m_pModelPrecacheTable,
         a2: true,
         a3: name,
         a4: -1,
         a5: nullptr);
  if ( v8 == 0xFFFF )
    return -1;
  ((void (__thiscall *)(INetworkStringTable *, int, _DWORD, int, int))this->m_pModelPrecacheTable->GetStringUserData)(
    a1: this->m_pModelPrecacheTable,
    a2: v8,
    a3: 0,
    a4: a2,
    a5: a3);
  ((void (__thiscall *)(INetworkStringTable *, int, int))this->m_pModelPrecacheTable->SetStringUserData)(
    a1: this->m_pModelPrecacheTable,
    a2: v8,
    a3: 1);
  v9 = &this->model_precache[v8];
  if ( model != nullptr )
    CPrecacheItem::SetModel(this: v9, pmodel: model);
  v10 = CPrecacheItem::GetSound(this: v9) == nullptr && (flags & 2) != 0;
  v11 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-nopreload") != 0
    || (v12 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-nopreloadmodels") != 0) )
  {
    v10 = false;
  }
  else if ( sv_forcepreload.m_pParent != nullptr && sv_forcepreload.m_pParent->m_Value.m_nValue != 0
         || (v13 = _CommandLine(),
             (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-preload") != 0) )
  {
    v10 = true;
  }
  if ( v8 != 0 )
  {
    v14 = modelloader->__vftable;
    if ( v10 )
    {
      v15 = (const model_t *)((int (__stdcall *)(const char *, int))v14->GetModelForName)(a1: name, a2: 2);
      CPrecacheItem::SetModel(this: v9, pmodel: v15);
      v16 = EngineVGui();
      v16->UpdateProgressBar(this: v16, a2: PROGRESS_DEFAULT, a3: true);
      v17 = MapReslistGenerator();
      CMapReslistGenerator::OnModelPrecached(this: v17, relativePathFileName: name);
      return v8;
    }
    ((void (__stdcall *)(const char *, int))v14->ReferenceModel)(a1: name, a2: 2);
    CPrecacheItem::SetModel(this: v9, pmodel: nullptr);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1012B2E0
// Name: public: int CGameServer::PrecacheSound(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CGameServer::PrecacheSound@<eax>(
        CGameServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *name,
        int flags)
{
  int v7; // esi
  const char *v8; // eax
  CMapReslistGenerator *v9; // eax
  const char *v10; // [esp-Ch] [ebp-10h]

  if ( this->m_pSoundPrecacheTable == nullptr )
    return -1;
  v7 = this->m_pSoundPrecacheTable->AddString(
         this: this->m_pSoundPrecacheTable,
         a2: true,
         a3: name,
         a4: -1,
         a5: nullptr);
  if ( v7 == 0xFFFF )
    return -1;
  if ( MapReslistGenerator()->m_bLoggingEnabled && *name != 0 )
  {
    v8 = PSkipSoundChars(pch: name);
    v10 = va(format: "sound/%s", v8);
    v9 = MapReslistGenerator();
    CMapReslistGenerator::OnResourcePrecached(this: v9, relativePathFileName: v10);
  }
  ((void (__thiscall *)(INetworkStringTable *, int, _DWORD, int, int))this->m_pSoundPrecacheTable->GetStringUserData)(
    a1: this->m_pSoundPrecacheTable,
    a2: v7,
    a3: 0,
    a4: a3,
    a5: a2);
  ((void (__thiscall *)(INetworkStringTable *, int))this->m_pSoundPrecacheTable->SetStringUserData)(
    a1: this->m_pSoundPrecacheTable,
    a2: v7);
  CPrecacheItem::SetSound(this: &this->sound_precache[v7], name);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1012B3C0
// Name: sv_precacheinfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_precacheinfo(const CCommand *args)
{
  const char *v1; // esi

  if ( args->m_nArgc != 2 )
    goto LABEL_10;
  v1 = args->m_ppArgv[1];
  if ( V_strcasecmp(s1: v1, s2: "generic") == 0 )
  {
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pGenericPrecacheTable);
    return;
  }
  if ( V_strcasecmp(s1: v1, s2: "sound") == 0 )
  {
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pSoundPrecacheTable);
    return;
  }
  if ( V_strcasecmp(s1: v1, s2: "decal") == 0 )
  {
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pDecalPrecacheTable);
    return;
  }
  if ( V_strcasecmp(s1: v1, s2: "model") != 0 )
  {
LABEL_10:
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pGenericPrecacheTable);
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pDecalPrecacheTable);
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pSoundPrecacheTable);
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pModelPrecacheTable);
  }
  else
  {
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pModelPrecacheTable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B4C0
// Name: int SV_FindOrAddModel(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_FindOrAddModel@<eax>(int a1@<ebx>, int a2@<edi>, const char *name, bool preload)
{
  char v4; // al

  v4 = 1;
  if ( preload )
    v4 = 3;
  return CGameServer::PrecacheModel(this: &sv, a2: a1, a3: a2, name, flags: v4, model: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1012B4F0
// Name: int SV_FindOrAddSound(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_FindOrAddSound@<eax>(int a1@<ebx>, int a2@<esi>, const char *name, bool preload)
{
  int v4; // eax

  v4 = 1;
  if ( preload )
    v4 = 3;
  return CGameServer::PrecacheSound(this: &sv, a2: a1, a3: a2, name, flags: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1012B520
// Name: public: struct model_t __near * CGameServer::GetModel(int)
// Source: json
//------------------------------------------------------------------------------
model_t *__userpurge CGameServer::GetModel@<eax>(CGameServer *this@<ecx>, int a2@<ebx>, int index)
{
  model_t *result; // eax
  CPrecacheItem *v5; // ebx
  const char *v6; // esi
  const model_t *v7; // esi

  if ( index <= 0
    || this->m_pModelPrecacheTable == nullptr
    || index >= this->m_pModelPrecacheTable->GetNumStrings(this: this->m_pModelPrecacheTable) )
  {
    return nullptr;
  }
  v5 = &this->model_precache[index];
  result = (model_t *)CPrecacheItem::GetSound(this: v5);
  if ( result == nullptr )
  {
    v6 = (const char *)((int (__thiscall *)(INetworkStringTable *, int, int))this->m_pModelPrecacheTable->GetString)(
                         a1: this->m_pModelPrecacheTable,
                         a2: index,
                         a3: a2);
    if ( host_showcachemiss.m_pParent != nullptr && host_showcachemiss.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "server model cache miss on %s\n", v6);
    v7 = (const model_t *)((int (__thiscall *)(IModelLoader *, const char *))modelloader->GetModelForName)(
                            a1: modelloader,
                            a2: v6);
    CPrecacheItem::SetModel(this: v5, pmodel: v7);
    return (model_t *)v7;
  }
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1012AD50
// Name: void SV_ForceExactFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ForceExactFile(const char *name)
{
  CDownloadListGenerator *v1; // eax

  v1 = DownloadListGenerator();
  CDownloadListGenerator::ForceExactFile(this: v1, relativePathFileName: name, consistency: CONSISTENCY_EXACT);
}

//------------------------------------------------------------------------------
// Address: 0x1012AD70
// Name: void SV_ForceSimpleMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ForceSimpleMaterial(const char *name)
{
  CDownloadListGenerator *v1; // eax

  v1 = DownloadListGenerator();
  CDownloadListGenerator::ForceExactFile(this: v1, relativePathFileName: name, consistency: CONSISTENCY_SIMPLE_MATERIAL);
}

//------------------------------------------------------------------------------
// Address: 0x1012AD90
// Name: void SV_ForceModelBounds(char const __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ForceModelBounds(const char *name, const Vector *mins, const Vector *maxs)
{
  CDownloadListGenerator *v3; // eax

  v3 = DownloadListGenerator();
  CDownloadListGenerator::ForceModelBounds(this: v3, relativePathFileName: name, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1012ADB0
// Name: public: class INetworkStringTable __near * CGameServer::GetModelPrecacheTable(void)const
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CGameServer::GetModelPrecacheTable(CGameServer *this)
{
  return this->m_pModelPrecacheTable;
}

//------------------------------------------------------------------------------
// Address: 0x1012ADC0
// Name: public: int CGameServer::LookupModelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameServer::LookupModelIndex(CGameServer *this, const char *name)
{
  int result; // eax

  if ( this->m_pModelPrecacheTable == nullptr )
    return -1;
  result = this->m_pModelPrecacheTable->FindStringIndex(this: this->m_pModelPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012ADF0
// Name: public: class INetworkStringTable __near * CGameServer::GetSoundPrecacheTable(void)const
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CGameServer::GetSoundPrecacheTable(CGameServer *this)
{
  return this->m_pSoundPrecacheTable;
}

//------------------------------------------------------------------------------
// Address: 0x1012AE00
// Name: public: char const __near * CGameServer::GetSound(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameServer::GetSound(CGameServer *this, int index)
{
  if ( index > 0
    && this->m_pSoundPrecacheTable != nullptr
    && index < this->m_pSoundPrecacheTable->GetNumStrings(this: this->m_pSoundPrecacheTable) )
  {
    return CPrecacheItem::GetSound(this: &this->sound_precache[index]);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AE50
// Name: public: int CGameServer::LookupSoundIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameServer::LookupSoundIndex(CGameServer *this, const char *name)
{
  int v3; // eax

  if ( this->m_pSoundPrecacheTable == nullptr )
    return 0;
  v3 = this->m_pSoundPrecacheTable->FindStringIndex(this: this->m_pSoundPrecacheTable, a2: name);
  return v3 != 0xFFFF ? v3 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012AF40
// Name: public: int CGameServer::PrecacheDecal(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CGameServer::PrecacheDecal@<eax>(
        CGameServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *name,
        int flags)
{
  int v7; // esi
  CMapReslistGenerator *v8; // eax

  if ( this->m_pDecalPrecacheTable == nullptr )
    return -1;
  v7 = this->m_pDecalPrecacheTable->AddString(
         this: this->m_pDecalPrecacheTable,
         a2: true,
         a3: name,
         a4: -1,
         a5: nullptr);
  if ( v7 == 0xFFFF )
    return -1;
  v8 = MapReslistGenerator();
  CMapReslistGenerator::OnResourcePrecached(this: v8, relativePathFileName: name);
  ((void (__thiscall *)(INetworkStringTable *, int, _DWORD, int, int))this->m_pDecalPrecacheTable->GetStringUserData)(
    a1: this->m_pDecalPrecacheTable,
    a2: v7,
    a3: 0,
    a4: a3,
    a5: a2);
  ((void (__thiscall *)(INetworkStringTable *, int))this->m_pDecalPrecacheTable->SetStringUserData)(
    a1: this->m_pDecalPrecacheTable,
    a2: v7);
  CPrecacheItem::SetDecal(this: &this->decal_precache[v7], decalname: name);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1012B000
// Name: public: void CGameServer::DumpPrecacheStats(class INetworkStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::DumpPrecacheStats(CGameServer *this, INetworkStringTable *table)
{
  CPrecacheItem *model_precache; // ecx
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  CAudioDeviceNull *v7; // ebx
  const CPrecacheUserData *v8; // eax
  const char *FlagString; // eax
  unsigned int ReferenceCount; // eax
  double v11; // [esp+Ch] [ebp-28h]
  int v12; // [esp+14h] [ebp-20h]
  double v13; // [esp+14h] [ebp-20h]
  int v14; // [esp+18h] [ebp-1Ch]
  int count; // [esp+28h] [ebp-Ch]
  const CPrecacheUserData *p; // [esp+2Ch] [ebp-8h]
  int testLength; // [esp+30h] [ebp-4h] BYREF
  const char *name; // [esp+3Ch] [ebp+8h]
  const char *namea; // [esp+3Ch] [ebp+8h]

  if ( table == nullptr )
  {
    ConMsg(a1: "Can only dump stats when active in a level\n");
    return;
  }
  if ( table == this->m_pModelPrecacheTable )
  {
    model_precache = this->model_precache;
  }
  else if ( table == this->m_pGenericPrecacheTable )
  {
    model_precache = this->generic_precache;
  }
  else if ( table == this->m_pSoundPrecacheTable )
  {
    model_precache = this->sound_precache;
  }
  else
  {
    if ( table != this->m_pDecalPrecacheTable )
      return;
    model_precache = this->decal_precache;
  }
  name = (const char *)model_precache;
  if ( model_precache != nullptr )
  {
    count = table->GetNumStrings(this: table);
    v4 = table->GetMaxStrings(this: table);
    ConMsg(a1: "\n");
    v5 = (const char *)((int (__thiscall *)(INetworkStringTable *, int, int))table->GetTableName)(
                         a1: table,
                         a2: count,
                         a3: v4);
    ConMsg(a1: "Precache table %s:  %i of %i slots used\n", v5, v12, v14);
    v6 = 0;
    if ( count > 0 )
    {
      v7 = (CAudioDeviceNull *)name;
      do
      {
        namea = table->GetString(this: table, a2: v6);
        v8 = (const CPrecacheUserData *)table->GetStringUserData(this: table, a2: v6, a3: &testLength);
        p = v8;
        if ( testLength != 1 )
        {
          _Error(a1: "CGameServer::DumpPrecacheStats: invalid CPrecacheUserData length (%d)", testLength);
          v8 = p;
        }
        if ( namea != nullptr && v7 != nullptr && v8 != nullptr )
        {
          FlagString = GetFlagString(flags: *(_BYTE *)v8 & 3);
          ConMsg(a1: "%03i:  %s (%s):   ", v6, namea, FlagString);
          if ( CPrecacheItem::GetReferenceCount(this: (CPrecacheItem *)v7) != 0 )
          {
            v13 = CAudioDeviceWave::MixDryVolume(this: v7);
            v11 = CAudioDeviceWave::MixDryVolume(this: v7);
            ReferenceCount = CPrecacheItem::GetReferenceCount(this: (CPrecacheItem *)v7);
            ConMsg(a1: " %i refs, first %.2f mru %.2f\n", ReferenceCount, v11, v13);
          }
          else
          {
            ConMsg(a1: " never used\n");
          }
        }
        ++v6;
        ++v7;
      }
      while ( v6 < count );
    }
    ConMsg(a1: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B1A0
// Name: int SV_ModelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_ModelIndex(const char *name)
{
  int result; // eax

  if ( sv.m_pModelPrecacheTable == nullptr )
    return -1;
  result = sv.m_pModelPrecacheTable->FindStringIndex(this: sv.m_pModelPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012B1D0
// Name: int SV_SoundIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_SoundIndex(const char *name)
{
  int v2; // eax

  if ( sv.m_pSoundPrecacheTable == nullptr )
    return 0;
  v2 = sv.m_pSoundPrecacheTable->FindStringIndex(this: sv.m_pSoundPrecacheTable, a2: name);
  return v2 != 0xFFFF ? v2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B200
// Name: int SV_GenericIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_GenericIndex(const char *name)
{
  int v2; // eax

  if ( sv.m_pGenericPrecacheTable == nullptr )
    return 0;
  v2 = sv.m_pGenericPrecacheTable->FindStringIndex(this: sv.m_pGenericPrecacheTable, a2: name);
  return v2 != 0xFFFF ? v2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B230
// Name: int SV_FindOrAddGeneric(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_FindOrAddGeneric(const char *name, bool preload)
{
  int v2; // eax

  v2 = 1;
  if ( preload )
    v2 = 3;
  return CGameServer::PrecacheGeneric(this: &sv, name, flags: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1012B260
// Name: int SV_DecalIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SV_DecalIndex(const char *name)
{
  int result; // eax

  if ( sv.m_pDecalPrecacheTable == nullptr )
    return -1;
  result = sv.m_pDecalPrecacheTable->FindStringIndex(this: sv.m_pDecalPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012B290
// Name: int SV_FindOrAddDecal(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_FindOrAddDecal@<eax>(int a1@<ebx>, int a2@<esi>, const char *name, bool preload)
{
  int v4; // eax

  v4 = 1;
  if ( preload )
    v4 = 3;
  return CGameServer::PrecacheDecal(this: &sv, a2: a1, a3: a2, name, flags: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1012B2C0
// Name: public: int CGameServer::PrecacheModel(char const __near *,int,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CGameServer::PrecacheModel@<eax>(
        CGameServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *name,
        char flags,
        model_t *model)
{
  int v8; // edi
  CPrecacheItem *v9; // esi
  bool v10; // bl
  int v11; // eax
  int v12; // eax
  int v13; // eax
  IModelLoader_vtbl *v14; // edx
  const model_t *v15; // eax
  IEngineVGuiInternal *v16; // eax
  CMapReslistGenerator *v17; // eax

  if ( this->m_pModelPrecacheTable == nullptr )
    return -1;
  v8 = this->m_pModelPrecacheTable->AddString(
         this: this->m_pModelPrecacheTable,
         a2: true,
         a3: name,
         a4: -1,
         a5: nullptr);
  if ( v8 == 0xFFFF )
    return -1;
  ((void (__thiscall *)(INetworkStringTable *, int, _DWORD, int, int))this->m_pModelPrecacheTable->GetStringUserData)(
    a1: this->m_pModelPrecacheTable,
    a2: v8,
    a3: 0,
    a4: a2,
    a5: a3);
  ((void (__thiscall *)(INetworkStringTable *, int, int))this->m_pModelPrecacheTable->SetStringUserData)(
    a1: this->m_pModelPrecacheTable,
    a2: v8,
    a3: 1);
  v9 = &this->model_precache[v8];
  if ( model != nullptr )
    CPrecacheItem::SetModel(this: v9, pmodel: model);
  v10 = CPrecacheItem::GetSound(this: v9) == nullptr && (flags & 2) != 0;
  v11 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-nopreload") != 0
    || (v12 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-nopreloadmodels") != 0) )
  {
    v10 = false;
  }
  else if ( sv_forcepreload.m_pParent != nullptr && sv_forcepreload.m_pParent->m_Value.m_nValue != 0
         || (v13 = _CommandLine(),
             (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-preload") != 0) )
  {
    v10 = true;
  }
  if ( v8 != 0 )
  {
    v14 = modelloader->__vftable;
    if ( v10 )
    {
      v15 = (const model_t *)((int (__stdcall *)(const char *, int))v14->GetModelForName)(a1: name, a2: 2);
      CPrecacheItem::SetModel(this: v9, pmodel: v15);
      v16 = EngineVGui();
      v16->UpdateProgressBar(this: v16, a2: PROGRESS_DEFAULT, a3: true);
      v17 = MapReslistGenerator();
      CMapReslistGenerator::OnModelPrecached(this: v17, relativePathFileName: name);
      return v8;
    }
    ((void (__stdcall *)(const char *, int))v14->ReferenceModel)(a1: name, a2: 2);
    CPrecacheItem::SetModel(this: v9, pmodel: nullptr);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1012B450
// Name: public: int CGameServer::PrecacheSound(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CGameServer::PrecacheSound@<eax>(
        CGameServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *name,
        int flags)
{
  int v7; // esi
  const char *v8; // eax
  CMapReslistGenerator *v9; // eax
  const char *v10; // [esp-Ch] [ebp-10h]

  if ( this->m_pSoundPrecacheTable == nullptr )
    return -1;
  v7 = this->m_pSoundPrecacheTable->AddString(
         this: this->m_pSoundPrecacheTable,
         a2: true,
         a3: name,
         a4: -1,
         a5: nullptr);
  if ( v7 == 0xFFFF )
    return -1;
  if ( MapReslistGenerator()->m_bLoggingEnabled && *name != 0 )
  {
    v8 = PSkipSoundChars(pch: name);
    v10 = va(format: "sound/%s", v8);
    v9 = MapReslistGenerator();
    CMapReslistGenerator::OnResourcePrecached(this: v9, relativePathFileName: v10);
  }
  ((void (__thiscall *)(INetworkStringTable *, int, _DWORD, int, int))this->m_pSoundPrecacheTable->GetStringUserData)(
    a1: this->m_pSoundPrecacheTable,
    a2: v7,
    a3: 0,
    a4: a3,
    a5: a2);
  ((void (__thiscall *)(INetworkStringTable *, int))this->m_pSoundPrecacheTable->SetStringUserData)(
    a1: this->m_pSoundPrecacheTable,
    a2: v7);
  CPrecacheItem::SetSound(this: &this->sound_precache[v7], name);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1012B530
// Name: sv_precacheinfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_precacheinfo(const CCommand *args)
{
  const char *v1; // esi

  if ( args->m_nArgc != 2 )
    goto LABEL_10;
  v1 = args->m_ppArgv[1];
  if ( V_strcasecmp(s1: v1, s2: "generic") == 0 )
  {
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pGenericPrecacheTable);
    return;
  }
  if ( V_strcasecmp(s1: v1, s2: "sound") == 0 )
  {
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pSoundPrecacheTable);
    return;
  }
  if ( V_strcasecmp(s1: v1, s2: "decal") == 0 )
  {
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pDecalPrecacheTable);
    return;
  }
  if ( V_strcasecmp(s1: v1, s2: "model") != 0 )
  {
LABEL_10:
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pGenericPrecacheTable);
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pDecalPrecacheTable);
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pSoundPrecacheTable);
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pModelPrecacheTable);
  }
  else
  {
    CGameServer::DumpPrecacheStats(this: &sv, table: sv.m_pModelPrecacheTable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B630
// Name: int SV_FindOrAddModel(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_FindOrAddModel@<eax>(int a1@<ebx>, int a2@<edi>, const char *name, bool preload)
{
  char v4; // al

  v4 = 1;
  if ( preload )
    v4 = 3;
  return CGameServer::PrecacheModel(this: &sv, a2: a1, a3: a2, name, flags: v4, model: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1012B660
// Name: int SV_FindOrAddSound(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_FindOrAddSound@<eax>(int a1@<ebx>, int a2@<esi>, const char *name, bool preload)
{
  int v4; // eax

  v4 = 1;
  if ( preload )
    v4 = 3;
  return CGameServer::PrecacheSound(this: &sv, a2: a1, a3: a2, name, flags: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1012B690
// Name: public: struct model_t __near * CGameServer::GetModel(int)
// Source: json
//------------------------------------------------------------------------------
model_t *__userpurge CGameServer::GetModel@<eax>(CGameServer *this@<ecx>, int a2@<ebx>, int index)
{
  model_t *result; // eax
  CPrecacheItem *v5; // ebx
  const char *v6; // esi
  const model_t *v7; // esi

  if ( index <= 0
    || this->m_pModelPrecacheTable == nullptr
    || index >= this->m_pModelPrecacheTable->GetNumStrings(this: this->m_pModelPrecacheTable) )
  {
    return nullptr;
  }
  v5 = &this->model_precache[index];
  result = (model_t *)CPrecacheItem::GetSound(this: v5);
  if ( result == nullptr )
  {
    v6 = (const char *)((int (__thiscall *)(INetworkStringTable *, int, int))this->m_pModelPrecacheTable->GetString)(
                         a1: this->m_pModelPrecacheTable,
                         a2: index,
                         a3: a2);
    if ( host_showcachemiss.m_pParent != nullptr && host_showcachemiss.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "server model cache miss on %s\n", v6);
    v7 = (const model_t *)((int (__thiscall *)(IModelLoader *, const char *))modelloader->GetModelForName)(
                            a1: modelloader,
                            a2: v6);
    CPrecacheItem::SetModel(this: v5, pmodel: v7);
    return (model_t *)v7;
  }
  return result;
}

} // namespace engine_xlsp
