// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/baseviewmodel.cpp
// Functions: 7
// ============================================================

#include "game\server\baseviewmodel.h"

//------------------------------------------------------------------------------
// Address: 0x100DCE70
// Name: public: virtual struct datamap_t __near * CBaseViewModel::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseViewModel::GetDataDescMap(CBaseViewModel *this)
{
  return &CBaseViewModel::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100DCE80
// Name: public: virtual int CBaseViewModel::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseViewModel::UpdateTransmitState(CBaseViewModel *this)
{
  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
  else
    return CBaseEntity::SetTransmitState(this, nFlag: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100DCEA0
// Name: public: virtual void CBaseViewModel::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::SetTransmit(CBaseViewModel *this, CCheckTransmitInfo *pInfo, BOOL bAlways)
{
  edict_t *m_pPev; // eax
  int i; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseAnimating::SetTransmit(this, pInfo, bAlways);
    for ( i = 0; i < this->m_hScreens.m_Size; ++i )
    {
      m_Index = this->m_hScreens.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
          ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))m_pEntity->__vftable[7].SetRefEHandle)(
            a1: m_pEntity,
            a2: pInfo,
            a3: bAlways);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DCF40
// Name: public: virtual int CBaseViewModel::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseViewModel::ShouldTransmit(CBaseViewModel *this, const CCheckTransmitInfo *pInfo)
{
  unsigned int m_Index; // eax
  CEntInfo *v3; // ecx
  CBasePlayer *m_pEntity; // edi
  edict_t *m_pClientEnt; // eax
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // eax
  int v8; // eax
  CBasePlayer *v9; // esi
  CBasePlayer **m_pMemory; // edi
  int m_Size; // ebx
  int v12; // eax
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenPlayers; // edx
  bool v14; // cc
  unsigned int v15; // eax
  int v16; // esi
  IHandleEntity **v17; // eax
  int v18; // eax
  CBasePlayer *v19; // esi
  CBasePlayer *v20; // eax
  CUtlVector<CBasePlayer *,CUtlMemory<CBasePlayer *,int> > checkList; // [esp+Ch] [ebp-20h] BYREF
  CBasePlayer *pOwner; // [esp+20h] [ebp-Ch]
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *vecParasites; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]
  IHandleEntity *pInfoa; // [esp+34h] [ebp+8h]
  const CCheckTransmitInfo *pInfob; // [esp+34h] [ebp+8h]

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && (v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (m_pEntity = (CBasePlayer *)v3->m_pEntity, v3->m_pEntity != nullptr)
    && m_pEntity->IsPlayer(this: (CBaseEntity *)v3->m_pEntity) )
  {
    m_pClientEnt = pInfo->m_pClientEnt;
    pOwner = m_pEntity;
    if ( m_pEntity->m_Network.m_pPev == m_pClientEnt
      || CBasePlayer::IsSplitScreenUserOnEdict(this: m_pEntity, edict: m_pClientEnt) != 0 )
    {
      return 8;
    }
  }
  else
  {
    pOwner = nullptr;
  }
  pEdicts = pInfo->m_pClientEnt;
  if ( pInfo->m_pClientEnt == nullptr )
  {
    if ( gpGlobals->pEdicts == nullptr )
      return 16;
    pEdicts = gpGlobals->pEdicts;
    if ( (pEdicts->m_fStateFlags & 2) != 0 )
      return 16;
  }
  m_pUnk = pEdicts->m_pUnk;
  if ( m_pUnk == nullptr )
    return 16;
  v8 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
  v9 = (CBasePlayer *)v8;
  if ( v8 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 336))(a1: v8) == 0 )
    return 16;
  memset(&checkList, 0, sizeof(checkList));
  CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&checkList, num: 1);
  m_pMemory = checkList.m_Memory.m_pMemory;
  m_Size = checkList.m_Size + 1;
  v12 = checkList.m_Size++;
  checkList.m_pElements = checkList.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: checkList.m_Memory.m_pMemory + 1, src: checkList.m_Memory.m_pMemory, count: 4 * v12);
  if ( m_pMemory != nullptr )
    *m_pMemory = v9;
  SplitScreenPlayers = CBasePlayer::GetSplitScreenPlayers(this: v9);
  v14 = SplitScreenPlayers->m_Size <= 0;
  vecParasites = SplitScreenPlayers;
  i = 0;
  if ( !v14 )
  {
    do
    {
      v15 = SplitScreenPlayers->m_Memory.m_pMemory[i].m_Index;
      if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
        pInfoa = nullptr;
      else
        pInfoa = g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
      v16 = m_Size;
      if ( m_Size + 1 > checkList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&checkList,
          num: m_Size - checkList.m_Memory.m_nAllocationCount + 1);
        m_Size = checkList.m_Size;
        m_pMemory = checkList.m_Memory.m_pMemory;
        SplitScreenPlayers = vecParasites;
      }
      checkList.m_Size = ++m_Size;
      checkList.m_pElements = m_pMemory;
      if ( m_Size - v16 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v16 + 1], src: &m_pMemory[v16], count: 4 * (m_Size - v16 - 1));
        SplitScreenPlayers = vecParasites;
      }
      v17 = &m_pMemory[v16];
      if ( v17 != nullptr )
        *v17 = pInfoa;
      ++i;
    }
    while ( i < SplitScreenPlayers->m_Size );
  }
  v18 = 0;
  pInfob = nullptr;
  if ( m_Size <= 0 )
  {
LABEL_38:
    if ( checkList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return 16;
  }
  while ( 1 )
  {
    v19 = m_pMemory[v18];
    if ( v19 != nullptr )
    {
      if ( v19->pl.hltv || v19->pl.replay )
        break;
      if ( v19->GetObserverMode(this: v19) == 4 )
      {
        v20 = (CBasePlayer *)v19->GetObserverTarget(this: v19);
        if ( v20 == pOwner )
        {
          CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&checkList);
          return 8;
        }
      }
      v18 = (int)pInfob;
    }
    pInfob = (const CCheckTransmitInfo *)++v18;
    if ( v18 >= m_Size )
      goto LABEL_38;
  }
  if ( checkList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x10400730
// Name: CBaseViewModel_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseViewModel_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseViewModel>(__formal: nullptr);
  CBaseViewModel_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DD1E0
// Name: struct datamap_t __near * DataMapInit<class CBaseViewModel>(class CBaseViewModel __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseViewModel>()
{
  if ( (_S2_54 & 1) == 0 )
  {
    _S2_54 |= 1u;
    nameHolder_98.m_pszBase = "CBaseViewModel";
    nameHolder_98.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_98.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_98.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_98.m_Names.m_Size = 0;
    nameHolder_98.m_Names.m_pElements = nullptr;
    nameHolder_98.m_nLenBase = 14;
    atexit(func: DataMapInit_CBaseViewModel__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseViewModel::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2_54 & 2) == 0 )
  {
    _S2_54 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>,13>::`vftable';
    }
    dataDesc_95[7].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>>'::`2'::ops;
    dataDesc_95[7].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_95[7].td = 0;
    *(_QWORD *)&dataDesc_95[7].override_field = 0;
    *(_QWORD *)&dataDesc_95[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_95[7].flatOffset[1] = 0;
  }
  CBaseViewModel::m_DataMap.dataNumFields = 7;
  CBaseViewModel::m_DataMap.dataDesc = &dataDesc_95[1];
  return &CBaseViewModel::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10400740
// Name: _dynamic_initializer_for__g_CBaseViewModel_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseViewModel_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseViewModel_ClassReg,
           pNetworkName: "CBaseViewModel",
           pTable: &DT_BaseViewModel::g_SendTable);
}
