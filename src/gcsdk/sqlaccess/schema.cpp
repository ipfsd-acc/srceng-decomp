// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/sqlaccess/schema.cpp
// Functions: 1
// ============================================================

#include "gcsdk\sqlaccess\schema.h"

//------------------------------------------------------------------------------
// Address: 0x100317F0
// Name: public: GCSDK::CSchema::~CSchema(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CSchema::~CSchema(GCSDK::CSchema *this)
{
  GCSDK::CRecordInfo *m_pRecordInfo; // ecx

  m_pRecordInfo = this->m_pRecordInfo;
  if ( m_pRecordInfo != nullptr )
  {
    if ( _InterlockedDecrement(&m_pRecordInfo->m_cRef) == 0 )
      m_pRecordInfo->DestroyThis(this: m_pRecordInfo);
    this->m_pRecordInfo = nullptr;
  }
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_VecAlterField);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_VecRenameField);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_VecDeleteField);
  CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int>>::~CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int>>(this: &this->m_VecFKData);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_VecFullTextIndexes);
  CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int>>::~CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int>>(this: &this->m_VecIndexes);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_VecField);
}
