// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_saverestore.cpp
// Functions: 6
// ============================================================

#include "game\server\ai_saverestore.h"

//------------------------------------------------------------------------------
// Address: 0x100816A0
// Name: class ISaveRestoreBlockHandler __near * GetAISaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CAI_SaveRestoreBlockHandler *__cdecl GetAISaveRestoreBlockHandler()
{
  return &g_AI_SaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x100816B0
// Name: public: virtual char const __near * CAI_SaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_SaveRestoreBlockHandler::GetBlockName(CAI_SaveRestoreBlockHandler *this)
{
  return "AI";
}

//------------------------------------------------------------------------------
// Address: 0x100816C0
// Name: public: virtual void CAI_SaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SaveRestoreBlockHandler::WriteSaveHeaders(CAI_SaveRestoreBlockHandler *this, ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &AI_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100816E0
// Name: public: virtual void CAI_SaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SaveRestoreBlockHandler::ReadRestoreHeaders(CAI_SaveRestoreBlockHandler *this, IRestore *pRestore)
{
  pRestore->ReadShort(this: pRestore, a2: (__int16 *)&pRestore, a3: 1, a4: 0);
  this->m_fDoLoad = (_WORD)pRestore == (unsigned __int16)AI_SAVE_RESTORE_VERSION;
}

//------------------------------------------------------------------------------
// Address: 0x10081710
// Name: public: virtual void CAI_SaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SaveRestoreBlockHandler::Save(CAI_SaveRestoreBlockHandler *this, ISave *pSave)
{
  ISave *v2; // esi
  unsigned __int16 v3; // ax
  void (__thiscall *WriteShort_2)(ISave *, const __int16 *, int); // edx
  CAI_Squad *m_pSquads; // edi
  CAI_Squad *v6; // ebx
  const char *pszValue; // eax
  CAI_Squad *m_pNextSquad; // eax
  int v9; // edi
  CAI_BaseNPC **i; // ebx
  int j; // edi
  void (__thiscall *WriteEntityPtr)(ISave *, CBaseEntity **, int); // edx
  int v13; // eax
  CBaseEntity *p; // [esp+Ch] [ebp-Ch] BYREF
  string_t squadName; // [esp+10h] [ebp-8h] BYREF
  int nSquads; // [esp+14h] [ebp-4h] BYREF

  v2 = pSave;
  pSave->StartBlock_2(this: pSave, a2: "Squads");
  v3 = CAI_SquadManager::NumSquads(this: &g_AI_SquadManager);
  WriteShort_2 = v2->WriteShort_2;
  nSquads = v3;
  WriteShort_2(this: v2, a2: (const __int16 *)&nSquads, a3: 1);
  m_pSquads = g_AI_SquadManager.m_pSquads;
  v6 = g_AI_SquadManager.m_pSquads;
  if ( g_AI_SquadManager.m_pSquads != nullptr )
  {
    do
    {
      pszValue = v6->m_Name.pszValue;
      if ( pszValue == nullptr || *pszValue == 0 )
        pszValue = nullptr;
      squadName.pszValue = pszValue;
      v2->WriteString(this: v2, a2: locale, a3: &squadName, a4: 1);
      v2->WriteAll(this: v2, a2: v6, a3: &CAI_Squad::m_DataMap);
      m_pNextSquad = m_pSquads;
      if ( m_pSquads != nullptr )
        m_pNextSquad = m_pSquads->m_pNextSquad;
      m_pSquads = m_pNextSquad;
      v6 = m_pNextSquad;
    }
    while ( m_pNextSquad != nullptr );
  }
  v2->EndBlock(this: v2);
  v2->StartBlock_2(this: v2, a2: "Enemies");
  v9 = 0;
  pSave = nullptr;
  for ( i = CAI_Manager::AccessAIs(this: &g_AI_Manager); v9 < vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager); ++v9 )
  {
    if ( i[v9]->GetEnemies(this: i[v9]) != nullptr )
      pSave = (ISave *)((char *)pSave + 1);
  }
  v2->WriteShort_2(this: v2, a2: (const __int16 *)&pSave, a3: 1);
  for ( j = 0; j < vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager); ++j )
  {
    if ( i[j]->GetEnemies(this: i[j]) != nullptr )
    {
      WriteEntityPtr = v2->WriteEntityPtr;
      p = i[j];
      WriteEntityPtr(this: v2, a2: &p, a3: 1);
      v13 = (int)i[j]->GetEnemies(this: i[j]);
      v2->WriteAll(this: v2, a2: (const void *)v13, a3: &CAI_Enemies::m_DataMap);
    }
  }
  v2->EndBlock(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10081880
// Name: public: virtual void CAI_SaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SaveRestoreBlockHandler::Restore(
        CAI_SaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool createPlayers)
{
  CAI_BaseNPC **v4; // edi
  int i; // esi
  IRestore *v6; // esi
  __int16 v7; // ax
  int v8; // edi
  int v9; // eax
  CAI_Squad *Squad; // eax
  __int16 j; // di
  int v12; // eax
  CAI_Squad ignored; // [esp+Ch] [ebp-C8h] BYREF
  CAI_Enemies ignoredMem; // [esp+94h] [ebp-40h] BYREF
  CBaseEntity *pAI; // [esp+D0h] [ebp-4h] BYREF

  v4 = CAI_Manager::AccessAIs(this: &g_AI_Manager);
  for ( i = 0; i < vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager); ++i )
    v4[i]->InitSquad(this: v4[i]);
  if ( this->m_fDoLoad )
  {
    v6 = pRestore;
    pRestore->StartBlock(this: pRestore);
    CAI_Squad::CAI_Squad(this: &ignored);
    v7 = v6->ReadShort_2(this: v6);
    v8 = v7;
    while ( v8 != 0 )
    {
      --v8;
      v9 = v6->SkipHeader(this: v6);
      v6->ReadString(this: v6, a2: (string_t *)&pRestore, a3: 1, a4: v9);
      Squad = CAI_SquadManager::FindSquad(this: &g_AI_SquadManager, squadName: (string_t)pRestore);
      if ( Squad == nullptr )
        Squad = &ignored;
      v6->ReadAll(this: v6, a2: Squad, a3: &CAI_Squad::m_DataMap);
    }
    v6->EndBlock(this: v6);
    v6->StartBlock(this: v6);
    CAI_Enemies::CAI_Enemies(this: &ignoredMem);
    for ( j = v6->ReadShort_2(this: v6); j != 0; --j )
    {
      v6->ReadEntityPtr(this: v6, a2: &pAI, a3: 1, a4: 0);
      if ( pAI != nullptr )
      {
        v12 = ((int (__thiscall *)(CBaseEntity *))pAI->__vftable[2].GetAttackDamageScale)(a1: pAI);
        v6->ReadAll(this: v6, a2: (void *)v12, a3: &CAI_Enemies::m_DataMap);
      }
      else
      {
        v6->ReadAll(this: v6, a2: &ignoredMem, a3: &CAI_Enemies::m_DataMap);
      }
    }
    v6->EndBlock(this: v6);
    CAI_Enemies::~CAI_Enemies(this: &ignoredMem);
    CAI_Squad::~CAI_Squad(this: &ignored);
  }
  if ( vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager) != 0
    && g_pBigAINet->m_iNumNodes == 0
    && !CAI_NetworkManager::gm_fNetworksLoaded )
  {
    _Msg(a1: "***\n");
    _Msg(a1: "ERROR: Loaded save game with no node graph. Load map and build node graph first!\n");
    _Msg(a1: "***\n");
    CAI_BaseNPC::m_nDebugBits |= 1u;
    CAI_NetworkManager::MarkDontSaveGraph(this: g_pAINetworkManager);
  }
}
