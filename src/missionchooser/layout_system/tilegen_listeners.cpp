// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system/tilegen_listeners.cpp
// Functions: 3
// ============================================================

#include "missionchooser\layout_system\tilegen_listeners.h"

//------------------------------------------------------------------------------
// Address: 0x1001E230
// Name: public: virtual void CTilegenListener_NumTilesPlaced::OnBeginGeneration(class CLayoutSystem const __near *,class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenListener_NumTilesPlaced::OnBeginGeneration(
        CTilegenListener_NumTilesPlaced *this,
        const CLayoutSystem *pLayoutSystem,
        CFreeVariableMap *pFreeVariables)
{
  this->m_nTotalArea = 0;
  this->m_nTotalAreaThisState = 0;
  CFreeVariableMap::SetOrCreateFreeVariable(this: pFreeVariables, pName: "NumTilesPlaced", pValue: nullptr);
  CFreeVariableMap::SetOrCreateFreeVariable(
    this: pFreeVariables,
    pName: "NumTilesPlacedThisState",
    pValue: (void *)this->m_nTotalAreaThisState);
}

//------------------------------------------------------------------------------
// Address: 0x1001E270
// Name: public: virtual void CTilegenListener_NumTilesPlaced::OnStateChanged(class CLayoutSystem const __near *,class CTilegenState const __near *,class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenListener_NumTilesPlaced::OnStateChanged(
        CTilegenListener_NumTilesPlaced *this,
        const CLayoutSystem *pLayoutSystem,
        const CTilegenState *pOldState,
        CFreeVariableMap *pFreeVariables)
{
  this->m_nTotalAreaThisState = 0;
  CFreeVariableMap::SetOrCreateFreeVariable(this: pFreeVariables, pName: "NumTilesPlacedThisState", pValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1001E290
// Name: public: virtual void CTilegenListener_NumTilesPlaced::OnRoomPlaced(class CLayoutSystem const __near *,class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenListener_NumTilesPlaced::OnRoomPlaced(
        CTilegenListener_NumTilesPlaced *this,
        const CLayoutSystem *pLayoutSystem,
        CFreeVariableMap *pFreeVariables)
{
  const CRoomTemplate *m_pRoomTemplate; // ecx
  int v5; // eax
  void *m_nTotalArea; // ecx

  m_pRoomTemplate = pLayoutSystem->m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[pLayoutSystem->m_pMapLayout->m_PlacedRooms.m_Size
                                                                                - 1]->m_pRoomTemplate;
  v5 = m_pRoomTemplate->m_nTilesX * m_pRoomTemplate->m_nTilesY;
  this->m_nTotalArea += v5;
  m_nTotalArea = (void *)this->m_nTotalArea;
  this->m_nTotalAreaThisState += v5;
  CFreeVariableMap::SetOrCreateFreeVariable(this: pFreeVariables, pName: "NumTilesPlaced", pValue: m_nTotalArea);
  CFreeVariableMap::SetOrCreateFreeVariable(
    this: pFreeVariables,
    pName: "NumTilesPlacedThisState",
    pValue: (void *)this->m_nTotalAreaThisState);
}
