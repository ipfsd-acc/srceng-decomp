// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/achievement_saverestore.cpp
// Functions: 5
// ============================================================

#include "game\shared\achievement_saverestore.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: virtual char const __near * CAchievementSaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAchievementSaveRestoreBlockHandler::GetBlockName(CAchievementSaveRestoreBlockHandler *this)
{
  return "Achievement";
}

//------------------------------------------------------------------------------
// Address: 0x10001010
// Name: public: virtual void CAchievementSaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAchievementSaveRestoreBlockHandler::Save(
        CAchievementSaveRestoreBlockHandler *this@<ecx>,
        int a2@<edi>,
        ISave *pSave)
{
  CAchievementMgr *Instance; // eax
  CAchievementMgr *v4; // ebx
  int v5; // esi
  IAchievement *AchievementByIndex; // eax
  int v8; // ebx
  IAchievement *v9; // esi
  int (__thiscall ***v10)(int); // eax
  int (__thiscall ***v11)(int); // esi
  unsigned __int16 v12; // ax
  void (__thiscall *WriteShort_2)(ISave *, const __int16 *, int); // edx
  ISave_vtbl *v14; // ebx
  int v15; // eax
  int iAchievementID; // [esp+8h] [ebp-10h] BYREF
  CAchievementMgr *pAchievementMgr; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int nSaveCount; // [esp+14h] [ebp-4h] BYREF
  int iTotalAchievements; // [esp+20h] [ebp+8h]

  Instance = CAchievementMgr::GetInstance();
  v4 = Instance;
  v5 = 0;
  pAchievementMgr = Instance;
  if ( Instance != nullptr )
  {
    CAchievementMgr::SaveGlobalStateIfDirty(this: Instance);
    ((void (__thiscall *)(ISave *, const char *, int))pSave->StartBlock_2)(a1: pSave, a2: "Achievements", a3: a2);
    iTotalAchievements = CAchievementMgr::GetAchievementCount(this: v4, bAssets: false);
    nSaveCount = 0;
    if ( iTotalAchievements > 0 )
    {
      do
      {
        AchievementByIndex = CAchievementMgr::GetAchievementByIndex(this: v4, index: v5, nUserSlot: 0);
        if ( AchievementByIndex->ShouldSaveWithGame(this: AchievementByIndex) )
          ++nSaveCount;
        ++v5;
      }
      while ( v5 < iTotalAchievements );
    }
    ((void (__thiscall *)(ISave *, int *))pSave->WriteShort_2)(a1: pSave, a2: &nSaveCount);
    v8 = 0;
    for ( i = 0; v8 < iTotalAchievements; i = v8 )
    {
      v9 = CAchievementMgr::GetAchievementByIndex(this: pAchievementMgr, index: v8, nUserSlot: 0);
      if ( v9->ShouldSaveWithGame(this: v9) )
      {
        v10 = (int (__thiscall ***)(int))__RTDynamicCast(
                                           inptr: v9,
                                           VfDelta: 0,
                                           SrcType: &IAchievement `RTTI Type Descriptor',
                                           TargetType: &CBaseAchievement `RTTI Type Descriptor',
                                           isReference: 0);
        v11 = v10;
        if ( v10 != nullptr )
        {
          v12 = (*v10[3])(a1: (int)(v10 + 3));
          WriteShort_2 = pSave->WriteShort_2;
          iAchievementID = v12;
          WriteShort_2(this: pSave, a2: (const __int16 *)&iAchievementID, a3: 1);
          v14 = pSave->__vftable;
          v15 = (*v11)[29](a1: (int)v11);
          v14->WriteAll(this: pSave, a2: v11, a3: (datamap_t *)v15);
          v8 = i;
        }
      }
      ++v8;
    }
    pSave->EndBlock(this: pSave);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001120
// Name: public: virtual void CAchievementSaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementSaveRestoreBlockHandler::WriteSaveHeaders(
        CAchievementSaveRestoreBlockHandler *this,
        ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &ACHIEVEMENT_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10001140
// Name: public: virtual void CAchievementSaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementSaveRestoreBlockHandler::ReadRestoreHeaders(
        CAchievementSaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  pRestore->ReadShort(this: pRestore, a2: (__int16 *)&pRestore, a3: 1, a4: 0);
  this->m_fDoLoad = (_WORD)pRestore == ACHIEVEMENT_SAVE_RESTORE_VERSION
                 && gpGlobals->eLoadType <= (unsigned int)MapLoad_LoadGame;
}

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: public: virtual void CAchievementSaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAchievementSaveRestoreBlockHandler::Restore(
        CAchievementSaveRestoreBlockHandler *this@<ecx>,
        datamap_t *DataDescMap@<ebx>,
        IRestore *pRestore,
        bool createPlayers)
{
  CAchievementMgr *Instance; // eax
  CAchievementMgr *v6; // edi
  __int16 v8; // ax
  int i; // ebx
  __int16 v10; // ax
  CBaseAchievement *AchievementByID; // edi
  IRestore_vtbl *v12; // ebx
  IRestore_vtbl *v13; // edi
  int v15; // [esp+0h] [ebp-9Ch]
  CBaseAchievement ignored; // [esp+8h] [ebp-94h] BYREF
  CAchievementMgr *pAchievementMgr; // [esp+98h] [ebp-4h]
  int nSavedAchievements; // [esp+A4h] [ebp+8h]

  Instance = CAchievementMgr::GetInstance();
  v6 = Instance;
  pAchievementMgr = Instance;
  if ( Instance != nullptr && this->m_fDoLoad )
  {
    CAchievementMgr::PreRestoreSavedGame(this: Instance);
    pRestore->StartBlock(this: pRestore);
    v8 = pRestore->ReadShort_2(this: pRestore);
    for ( i = v8; i != 0; v6 = pAchievementMgr )
    {
      nSavedAchievements = --i;
      v10 = ((int (__thiscall *)(IRestore *, datamap_t *))pRestore->ReadShort_2)(a1: pRestore, a2: DataDescMap);
      AchievementByID = CAchievementMgr::GetAchievementByID(this: v6, iAchievementID: v10, nUserSlot: 0);
      if ( AchievementByID != nullptr )
      {
        v12 = pRestore->__vftable;
        v15 = ((int (__thiscall *)(CBaseAchievement *, int))AchievementByID->GetDataDescMap)(
                a1: AchievementByID,
                a2: v15);
        DataDescMap = (datamap_t *)AchievementByID;
        ((void (__thiscall *)(IRestore *))v12->ReadAll)(a1: pRestore);
        i = nSavedAchievements;
      }
      else
      {
        CBaseAchievement::CBaseAchievement(this: &ignored);
        v13 = pRestore->__vftable;
        DataDescMap = CBaseAchievement::GetDataDescMap(this: &ignored);
        ((void (__thiscall *)(IRestore *, CBaseAchievement *))v13->ReadAll)(a1: pRestore, a2: &ignored);
        ignored.CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CGameEventListener::`vftable';
        ignored.m_nDebugID = 13;
        if ( ignored.m_bRegisteredForEvents && gameeventmanager != nullptr )
          gameeventmanager->RemoveListener(this: gameeventmanager, a2: &ignored);
      }
    }
    pRestore->EndBlock(this: pRestore);
    CAchievementMgr::PostRestoreSavedGame(this: v6);
  }
}
