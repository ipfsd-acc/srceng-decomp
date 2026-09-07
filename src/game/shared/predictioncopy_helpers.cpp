// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/predictioncopy_helpers.cpp
// Functions: 3
// ============================================================

#include "game\shared\predictioncopy_helpers.h"

//------------------------------------------------------------------------------
// Address: 0x101564D0
// Name: public: void CValueChangeTracker::SetupTracking(class C_BaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValueChangeTracker::SetupTracking(
        CValueChangeTracker *this,
        C_BaseEntity *ent,
        const char *pchFieldName)
{
  datamap_t *v4; // eax
  datamap_t *v5; // ebx
  char *v6; // eax
  const typedescription_t *FlatFieldByName; // eax
  char *Classname; // eax

  *(_BYTE *)this &= 0xFCu;
  this->m_hEntityToTrack.m_Index = -1;
  CUtlString::operator=(this: &this->m_strFieldName, src: prType);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_History);
  this->m_pTrackField = nullptr;
  v4 = ent->GetPredDescMap(this: ent);
  v5 = v4;
  if ( v4 != nullptr )
  {
    CPredictionCopy::PrepareDataMap(dmap: v4);
    FlatFieldByName = CPredictionCopy::FindFlatFieldByName(fieldname: pchFieldName, dmap: v5);
    this->m_pTrackField = FlatFieldByName;
    if ( FlatFieldByName != nullptr )
    {
      this->m_hEntityToTrack.m_Index = ent->GetRefEHandle(this: ent)->m_Index;
      CUtlString::operator=(this: &this->m_strFieldName, src: pchFieldName);
      *(_BYTE *)this |= 1u;
    }
    else
    {
      Classname = C_BaseEntity::GetClassname(this: ent);
      _Msg(a1: "No field '%s' in datamap_t for entity %d/%s\n", pchFieldName, ent->index, Classname);
    }
  }
  else
  {
    v6 = C_BaseEntity::GetClassname(this: ent);
    _Msg(a1: "No prediction datamap_t for entity %d/%s\n", ent->index, v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156590
// Name: cl_pred_track
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_pred_track(const CCommand *args)
{
  CValueChangeTracker *v1; // esi
  int v2; // edi
  C_BaseEntity *BaseEntity; // eax

  v1 = g_pChangeTracker;
  *(_BYTE *)g_pChangeTracker &= 0xFCu;
  v1->m_hEntityToTrack.m_Index = -1;
  CUtlString::operator=(this: &v1->m_strFieldName, src: prType);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&v1->m_History);
  v1->m_pTrackField = nullptr;
  if ( args->m_nArgc == 3 )
  {
    v2 = V_atoi(str: args->m_ppArgv[1]);
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v2);
    if ( BaseEntity != nullptr )
    {
      if ( args->m_nArgc > 2 )
        CValueChangeTracker::SetupTracking(this: g_pChangeTracker, ent: BaseEntity, pchFieldName: args->m_ppArgv[2]);
      else
        CValueChangeTracker::SetupTracking(this: g_pChangeTracker, ent: BaseEntity, pchFieldName: prType);
    }
    else
    {
      _Msg(a1: "cl_pred_track:  Unknown ent index %d\n", v2);
    }
  }
  else
  {
    _Msg(a1: "cl_pred_track <entindex> <fieldname>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156650
// Name: public: CValueChangeTracker::~CValueChangeTracker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValueChangeTracker::~CValueChangeTracker(CValueChangeTracker *this)
{
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_History);
  this->m_strContext.m_Storage.m_nActualLength = 0;
  if ( this->m_strContext.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_strContext.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_strContext.m_Storage.m_Memory.m_pMemory);
      this->m_strContext.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_strContext.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_strFieldName.m_Storage.m_nActualLength = 0;
  if ( this->m_strFieldName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_strFieldName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_strFieldName.m_Storage.m_Memory.m_pMemory);
      this->m_strFieldName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_strFieldName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}
