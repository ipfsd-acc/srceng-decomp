// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system/tilegen_ranges.cpp
// Functions: 14
// ============================================================

#include "missionchooser\layout_system\tilegen_ranges.h"

//------------------------------------------------------------------------------
// Address: 0x10016590
// Name: public: virtual class ITilegenRange<class CExit const __near *> __near * CTilegenClassFactory<class ITilegenRange<class CExit const __near *>,class CTilegenRange_ClosedExits>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenRange_ClosedExits *__thiscall CTilegenClassFactory<ITilegenRange<CExit const *>,CTilegenRange_ClosedExits>::CreateInstance(
        CTilegenClassFactory<ITilegenRange<CExit const *>,CTilegenRange_ClosedExits> *this)
{
  CTilegenRange_ClosedExits *v1; // eax

  v1 = (CTilegenRange_ClosedExits *)operator new(nSize: 0x20u);
  if ( v1 != nullptr )
    return CTilegenRange_ClosedExits::CTilegenRange_ClosedExits(this: v1, pRoomCandidateExpression: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016A60
// Name: public: virtual class ITilegenRange<class CExit const __near *> __near * CTilegenClassFactory<class ITilegenRange<class CExit const __near *>,class CTilegenRange_NewOpenExits>::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenRange_NewOpenExits *__thiscall CTilegenClassFactory<ITilegenRange<CExit const *>,CTilegenRange_NewOpenExits>::CreateInstance(
        CTilegenClassFactory<ITilegenRange<CExit const *>,CTilegenRange_NewOpenExits> *this)
{
  CTilegenRange_NewOpenExits *v1; // eax

  v1 = (CTilegenRange_NewOpenExits *)operator new(nSize: 0x20u);
  if ( v1 != nullptr )
    return CTilegenRange_NewOpenExits::CTilegenRange_NewOpenExits(this: v1, pRoomCandidateExpression: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10017D60
// Name: public: static class ITilegenRange<class CExit const __near *> __near * CTilegenClassRegistry<class ITilegenRange<class CExit const __near *>>::CreateInstance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITilegenRange<CExit const *> *__cdecl CTilegenClassRegistry<ITilegenRange<CExit const *>>::CreateInstance(
        const char *pClassName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Size <= 0 )
  {
LABEL_4:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Class %s not found in %s. Check the class name spelling and the context in which it is used.\n");
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v2 = CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->GetName(this: CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( _V_stricmp(s1: v2, s2: pClassName) == 0 )
        return CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v1]->CreateInstance(this: CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Memory.m_pMemory[v1]);
      if ( ++v1 >= CTilegenClassRegistry<ITilegenRange<CExit const *>>::m_FactoryList.m_Size )
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EA20
// Name: public: virtual void CTilegenRange_ClosedExits::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenRange_ClosedExits::Reset(CTilegenRange_ClosedExits *this)
{
  this->m_nCurrentExit = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA60
// Name: public: virtual bool CTilegenRange_NewOpenExits::MoveNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenRange_NewOpenExits::MoveNext(CTilegenRange_ClosedExits *this)
{
  return ++this->m_nCurrentExit < this->m_Exits.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA70
// Name: bool GetExitPosition(class CRoomTemplate const __near *,int,int,int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetExitPosition(const CRoomTemplate *pTemplate, int nX, int nY, int nExitIndex, int *pExitX, int *pExitY)
{
  const CRoomTemplate *v6; // esi
  int v7; // edi
  int *v8; // ecx
  int v9; // eax
  int v10; // ecx

  v6 = pTemplate;
  v7 = nExitIndex;
  CRoomTemplateExit::GetExitOffset(
    Direction: pTemplate->m_Exits.m_Memory.m_pMemory[nExitIndex]->m_ExitDirection,
    pX: &nExitIndex,
    pY: (int *)&pTemplate);
  v8 = pExitX;
  *pExitX = nX + nExitIndex + v6->m_Exits.m_Memory.m_pMemory[v7]->m_iXPos;
  v9 = v6->m_nTilesY - v6->m_Exits.m_Memory.m_pMemory[v7]->m_iYPos - (_DWORD)pTemplate + nY - 1;
  *pExitY = v9;
  v10 = *v8;
  return v10 >= 0 && v9 >= 0 && v10 < 120 && v9 < 120;
}

//------------------------------------------------------------------------------
// Address: 0x1001EAF0
// Name: public: virtual class CExit const __near * CTilegenRange_NewOpenExits::GetCurrent(void)
// Source: json
//------------------------------------------------------------------------------
const CExit *__thiscall CTilegenRange_NewOpenExits::GetCurrent(CTilegenRange_ClosedExits *this)
{
  return &this->m_Exits.m_Memory.m_pMemory[this->m_nCurrentExit];
}

//------------------------------------------------------------------------------
// Address: 0x1001EB00
// Name: public: CTilegenRange_NewOpenExits::CTilegenRange_NewOpenExits(class ITilegenExpression<class CRoomCandidate const __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenRange_NewOpenExits *__thiscall CTilegenRange_NewOpenExits::CTilegenRange_NewOpenExits(
        CTilegenRange_NewOpenExits *this,
        ITilegenExpression<CRoomCandidate const *> *pRoomCandidateExpression)
{
  this->m_pRoomCandidateExpression = pRoomCandidateExpression;
  this->__vftable = (CTilegenRange_NewOpenExits_vtbl *)&CTilegenRange_NewOpenExits::`vftable';
  this->m_Exits.m_Memory.m_pMemory = nullptr;
  this->m_Exits.m_Memory.m_nAllocationCount = 0;
  this->m_Exits.m_Memory.m_nGrowSize = 0;
  this->m_Exits.m_Size = 0;
  this->m_Exits.m_pElements = nullptr;
  this->m_nCurrentExit = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001EB30
// Name: public: CTilegenRange_ClosedExits::CTilegenRange_ClosedExits(class ITilegenExpression<class CRoomCandidate const __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenRange_ClosedExits *__thiscall CTilegenRange_ClosedExits::CTilegenRange_ClosedExits(
        CTilegenRange_ClosedExits *this,
        ITilegenExpression<CRoomCandidate const *> *pRoomCandidateExpression)
{
  this->m_pRoomCandidateExpression = pRoomCandidateExpression;
  this->__vftable = (CTilegenRange_ClosedExits_vtbl *)&CTilegenRange_ClosedExits::`vftable';
  this->m_Exits.m_Memory.m_pMemory = nullptr;
  this->m_Exits.m_Memory.m_nAllocationCount = 0;
  this->m_Exits.m_Memory.m_nGrowSize = 0;
  this->m_Exits.m_Size = 0;
  this->m_Exits.m_pElements = nullptr;
  this->m_nCurrentExit = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001EB60
// Name: void BuildOpenExitList(class CRoomCandidate const __near &,class CMapLayout const __near *,class CUtlVector<class CExit,class CUtlMemory<class CExit,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildOpenExitList(
        const CRoomCandidate *roomCandidate,
        const CMapLayout *pMapLayout,
        CUtlVector<CExit,CUtlMemory<CExit,int> > *pNewExitList)
{
  const CRoomCandidate *v3; // eax
  const CRoomTemplate *m_pRoomTemplate; // esi
  bool v5; // cc
  int m_iXPos; // edi
  CRoomTemplateExit *v7; // ecx
  int v8; // eax
  int v9; // ecx
  CRoomTemplateExit *v10; // edx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CExit *m_pMemory; // ecx
  int v14; // eax
  CExit *v15; // edi
  char v16[84]; // [esp+4h] [ebp-68h] BYREF
  int m_iYPos; // [esp+58h] [ebp-14h]
  int pY; // [esp+5Ch] [ebp-10h] BYREF
  int pX; // [esp+60h] [ebp-Ch] BYREF
  const CRoomTemplate *pTemplate; // [esp+64h] [ebp-8h]
  int i; // [esp+68h] [ebp-4h]

  v3 = roomCandidate;
  m_pRoomTemplate = roomCandidate->m_pRoomTemplate;
  v5 = roomCandidate->m_pRoomTemplate->m_Exits.m_Size <= 0;
  pTemplate = roomCandidate->m_pRoomTemplate;
  i = 0;
  if ( !v5 )
  {
    while ( 1 )
    {
      m_iXPos = v3->m_iXPos;
      m_iYPos = v3->m_iYPos;
      CRoomTemplateExit::GetExitOffset(
        Direction: m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[i]->m_ExitDirection,
        &pX,
        &pY);
      v7 = m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[i];
      v8 = m_iXPos + pX + v7->m_iXPos;
      v9 = m_pRoomTemplate->m_nTilesY - v7->m_iYPos - pY + m_iYPos - 1;
      if ( v8 >= 0 && v9 >= 0 && v8 < 120 && v9 < 120 )
      {
        if ( pMapLayout->m_pRoomGrid[v8][v9] == nullptr )
        {
          v10 = m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[i];
          *(_QWORD *)v16 = __PAIR64__(v9, v8);
          *(_QWORD *)&v16[8] = (unsigned int)v10->m_ExitDirection;
          v16[80] = 0;
          if ( v10 == (CRoomTemplateExit *)-16 )
            v16[16] = 0;
          else
            V_strncpy(pDest: &v16[16], pSrc: v10->m_szExitTag, maxLen: 64);
          m_Size = pNewExitList->m_Size;
          m_nAllocationCount = pNewExitList->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CExit,int>::Grow(
              this: (CUtlMemory<PanelItem_t,int> *)pNewExitList,
              num: m_Size - m_nAllocationCount + 1);
          ++pNewExitList->m_Size;
          m_pMemory = pNewExitList->m_Memory.m_pMemory;
          v14 = pNewExitList->m_Size - m_Size - 1;
          pNewExitList->m_pElements = pNewExitList->m_Memory.m_pMemory;
          if ( v14 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 84 * v14);
          v15 = &pNewExitList->m_Memory.m_pMemory[m_Size];
          if ( v15 != nullptr )
            qmemcpy(v15, v16, sizeof(CExit));
        }
        m_pRoomTemplate = pTemplate;
      }
      if ( ++i >= m_pRoomTemplate->m_Exits.m_Size )
        break;
      v3 = roomCandidate;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ED00
// Name: public: virtual void CTilegenRange_NewOpenExits::Initialize(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenRange_NewOpenExits::Initialize(CTilegenRange_NewOpenExits *this, CFreeVariableMap *pContext)
{
  CUtlVector<CExit,CUtlMemory<CExit,int> > *p_m_Exits; // edi
  const CRoomCandidate *v4; // ebx
  const CMapLayout *FreeVariableDisallowNULL; // eax

  p_m_Exits = &this->m_Exits;
  this->m_Exits.m_Size = 0;
  v4 = this->m_pRoomCandidateExpression->Evaluate(this: this->m_pRoomCandidateExpression, a2: pContext);
  if ( v4 != nullptr )
  {
    FreeVariableDisallowNULL = (const CMapLayout *)CFreeVariableMap::GetFreeVariableDisallowNULL(
                                                     this: pContext,
                                                     pName: "MapLayout");
    BuildOpenExitList(roomCandidate: v4, pMapLayout: FreeVariableDisallowNULL, pNewExitList: p_m_Exits);
  }
  this->m_nCurrentExit = this->m_Exits.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1001EDA0
// Name: public: virtual void CTilegenRange_ClosedExits::Initialize(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenRange_ClosedExits::Initialize(CTilegenRange_ClosedExits *this, CFreeVariableMap *pContext)
{
  CTilegenRange_ClosedExits *v2; // esi
  CUtlMemory<PanelItem_t,int> *p_m_Exits; // ebx
  ITilegenExpression<CRoomCandidate const *> *m_pRoomCandidateExpression; // ecx
  const CRoomCandidate *(__thiscall *Evaluate)(ITilegenExpression<CRoomCandidate const *> *, CFreeVariableMap *); // eax
  const CRoomCandidate *v6; // edi
  const CRoomTemplate *m_pRoomTemplate; // ecx
  CMapLayout *FreeVariableDisallowNULL; // eax
  CRoomTemplateExit *v9; // eax
  int v10; // esi
  PanelItem_t *m_pMemory; // esi
  int m_nAllocationCount; // eax
  PanelItem_t *v13; // ecx
  int v14; // eax
  PanelItem_t *v15; // eax
  CRoomTemplateExit **v16; // eax
  const CRoomTemplate *v17; // [esp-10h] [ebp-90h]
  int m_iXPos; // [esp-Ch] [ebp-8Ch]
  int m_iYPos; // [esp-8h] [ebp-88h]
  char v20[84]; // [esp+Ch] [ebp-74h] BYREF
  CUtlVector<CRoomTemplateExit *,CUtlMemory<CRoomTemplateExit *,int> > matchingExits; // [esp+60h] [ebp-20h] BYREF
  CTilegenRange_ClosedExits *v22; // [esp+74h] [ebp-Ch]
  const CRoomCandidate *pRoomCandidate; // [esp+78h] [ebp-8h]
  ExitDirection_t m_ExitDirection; // [esp+7Ch] [ebp-4h]
  int i; // [esp+88h] [ebp+8h]

  v2 = this;
  p_m_Exits = (CUtlMemory<PanelItem_t,int> *)&this->m_Exits;
  this->m_Exits.m_Size = 0;
  m_pRoomCandidateExpression = this->m_pRoomCandidateExpression;
  Evaluate = m_pRoomCandidateExpression->Evaluate;
  v22 = v2;
  v6 = Evaluate(this: m_pRoomCandidateExpression, a2: pContext);
  pRoomCandidate = v6;
  if ( v6 == nullptr )
    goto LABEL_21;
  m_pRoomTemplate = v6->m_pRoomTemplate;
  m_iYPos = v6->m_iYPos;
  memset(&matchingExits, 0, sizeof(matchingExits));
  m_iXPos = v6->m_iXPos;
  v17 = m_pRoomTemplate;
  FreeVariableDisallowNULL = (CMapLayout *)CFreeVariableMap::GetFreeVariableDisallowNULL(
                                             this: pContext,
                                             pName: "MapLayout");
  CMapLayout::CheckExits(
    this: FreeVariableDisallowNULL,
    pTemplate: v17,
    x: m_iXPos,
    y: m_iYPos,
    pMatchingExits: &matchingExits);
  i = 0;
  if ( matchingExits.m_Size > 0 )
  {
    do
    {
      v9 = matchingExits.m_Memory.m_pMemory[i];
      v10 = v6->m_iYPos;
      m_ExitDirection = v9->m_ExitDirection;
      *(_DWORD *)v20 = v9->m_iXPos + v6->m_iXPos;
      *(_DWORD *)&v20[4] = v6->m_pRoomTemplate->m_nTilesY - v9->m_iYPos + v10 - 1;
      *(_QWORD *)&v20[8] = (unsigned int)m_ExitDirection;
      v20[80] = 0;
      if ( v9 == (CRoomTemplateExit *)-16 )
        v20[16] = 0;
      else
        V_strncpy(pDest: &v20[16], pSrc: v9->m_szExitTag, maxLen: 64);
      m_pMemory = p_m_Exits[1].m_pMemory;
      m_nAllocationCount = p_m_Exits->m_nAllocationCount;
      if ( (int)&m_pMemory->m_EditLabel + 1 > m_nAllocationCount )
        CUtlMemory<CExit,int>::Grow(this: p_m_Exits, num: (int)&m_pMemory->m_EditLabel - m_nAllocationCount + 1);
      ++p_m_Exits[1].m_pMemory;
      v13 = p_m_Exits->m_pMemory;
      v14 = (char *)p_m_Exits[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_Exits[1].m_nAllocationCount = (int)p_m_Exits->m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: &v13[(int)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 84 * v14);
      v15 = &p_m_Exits->m_pMemory[(_DWORD)m_pMemory];
      if ( v15 != nullptr )
      {
        qmemcpy(v15, v20, sizeof(PanelItem_t));
        v6 = pRoomCandidate;
      }
      ++i;
    }
    while ( i < matchingExits.m_Size );
    v2 = v22;
  }
  v16 = matchingExits.m_Memory.m_pMemory;
  matchingExits.m_Size = 0;
  if ( matchingExits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( matchingExits.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: matchingExits.m_Memory.m_pMemory);
      v16 = nullptr;
      matchingExits.m_Memory.m_pMemory = nullptr;
    }
    matchingExits.m_Memory.m_nAllocationCount = 0;
  }
  matchingExits.m_pElements = v16;
  if ( matchingExits.m_Memory.m_nGrowSize < 0 )
  {
    v2->m_nCurrentExit = v2->m_Exits.m_Size;
  }
  else
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
LABEL_21:
      v2->m_nCurrentExit = v2->m_Exits.m_Size;
      return;
    }
    v2->m_nCurrentExit = v2->m_Exits.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EF70
// Name: public: virtual bool CTilegenRange_NewOpenExits::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenRange_NewOpenExits::LoadFromKeyValues(CTilegenRange_NewOpenExits *this, KeyValues *pKeyValues)
{
  return CreateFromKeyValuesBlock<ITilegenExpression<CRoomCandidate const *>>(
           pParentKV: pKeyValues,
           pKeyName: "expression",
           pParentClassName: "CTilegenRange_NewOpenExits",
           ppClass: &this->m_pRoomCandidateExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001EFA0
// Name: public: virtual bool CTilegenRange_ClosedExits::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenRange_ClosedExits::LoadFromKeyValues(CTilegenRange_ClosedExits *this, KeyValues *pKeyValues)
{
  return CreateFromKeyValuesBlock<ITilegenExpression<CRoomCandidate const *>>(
           pParentKV: pKeyValues,
           pKeyName: "expression",
           pParentClassName: "CTilegenRange_ClosedExits",
           ppClass: &this->m_pRoomCandidateExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}
