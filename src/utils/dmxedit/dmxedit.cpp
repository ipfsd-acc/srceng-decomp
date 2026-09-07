// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/dmxedit/dmxedit.cpp
// Functions: 244
// ============================================================

#include "utils\dmxedit\dmxedit.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: bool StringHasPrefix(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl StringHasPrefix(const char *str, const char *prefix)
{
  return StringAfterPrefix(str, prefix) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401020
// Name: public: Vector::Vector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::Vector(Vector *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401030
// Name: public: void CChangeUndoScopeGuard::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeUndoScopeGuard::Release(CChangeUndoScopeGuard *this)
{
  bool v2; // zf

  if ( !this->m_bReleased )
  {
    ((void (__stdcall *)(bool))g_pDataModel->SetUndoEnabled)(a1: this->m_bOldValue);
    v2 = !this->m_bNotify;
    this->m_bReleased = true;
    if ( !v2 )
    {
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      this->m_bNotify = false;
    }
    if ( this->m_pNotify != nullptr )
    {
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: this->m_pNotify);
      this->m_pNotify = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401090
// Name: bool ShouldTraverse(class CDmAttribute const __near *,enum TraversalDepth_t)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldTraverse(const CDmAttribute *pAttr, TraversalDepth_t depth)
{
  switch ( depth )
  {
    case TD_ALL:
      return 1;
    case TD_DEEP:
      return (pAttr->m_nFlags & 0x1000) == 0;
    case TD_SHALLOW:
      if ( (pAttr->m_nFlags & 0x800) == 0 )
        return 0;
      return (pAttr->m_nFlags & 0x1000) == 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004010E0
// Name: public: enum CDmeMesh::Falloff_t CDmxEdit::CFalloffType::StringToFalloff(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxEdit::CFalloffType::StringToFalloff(CDmxEdit::CFalloffType *this, const char *pFalloffTypeString)
{
  if ( V_strnicmp(s1: pFalloffTypeString, s2: "L", n: 1) != 0 && V_strnicmp(s1: pFalloffTypeString, s2: "ST", n: 2) != 0 )
  {
    if ( V_strnicmp(s1: pFalloffTypeString, s2: "B", n: 1) == 0
      || V_strnicmp(s1: pFalloffTypeString, s2: "SM", n: 2) == 0 )
    {
      return 1;
    }
    if ( V_strnicmp(s1: pFalloffTypeString, s2: "SP", n: 2) == 0 )
      return 2;
    if ( V_strnicmp(s1: pFalloffTypeString, s2: "D", n: 1) == 0 )
      return 3;
    _Msg(
      a1: "// ERROR: Can't Figure Out Which Falloff Type Is Meant By \"%s\", Assuming STRAIGHT\n",
      pFalloffTypeString);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004011A0
// Name: public: enum CDmxEdit::CSelectOp::SelectOp_t CDmxEdit::CSelectOp::StringToSelectOp(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxEdit::CSelectOp::SelectOp_t __thiscall CDmxEdit::CSelectOp::StringToSelectOp(
        CDmxEdit::CSelectOp *this,
        const char *pSelectOpString)
{
  CDmxEdit::CSelectOp::SelectOp_t result; // eax

  result = V_strnicmp(s1: pSelectOpString, s2: "A", n: 1);
  if ( result != 0 )
  {
    if ( V_strnicmp(s1: pSelectOpString, s2: "S", n: 1) != 0 )
    {
      if ( V_strnicmp(s1: pSelectOpString, s2: "T", n: 1) != 0 )
      {
        if ( V_strnicmp(s1: pSelectOpString, s2: "I", n: 1) != 0 )
        {
          if ( V_strnicmp(s1: pSelectOpString, s2: "R", n: 1) != 0 )
            _Msg(
              a1: "// ERROR: Can't Figure Out Which Select Operation Type Is Meant By \"%s\", Assuming REPLACE\n",
              pSelectOpString);
          return 4;
        }
        else
        {
          return kIntersect;
        }
      }
      else
      {
        return kToggle;
      }
    }
    else
    {
      return kSubtract;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401250
// Name: public: void CDmxEdit::LuaWarning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxEdit::LuaWarning(CDmxEdit *this, char *pFormat, ...)
{
  int m_lineNo; // edi
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // [esp-10h] [ebp-1010h]
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+1010h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  if ( _vsnprintf(string, count: 0xFFFu, format: pFormat, ap) < 0 )
    string[4095] = 0;
  m_lineNo = this->m_lineNo;
  if ( m_lineNo < 0 )
  {
    v4 = CUtlString::operator char const *(this: &this->m_funcString);
    _Warning(a1: "// WARNING: %s - %s\n", v4, string);
  }
  else
  {
    v5 = CUtlString::operator char const *(this: &this->m_funcString);
    v3 = CUtlString::operator char const *(this: &this->m_sourceFile);
    _Warning(a1: "// WARNING: %s:%d: %s - %s\n", v3, m_lineNo, v5, string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012F0
// Name: public: bool CDmxEdit::SetErrorString(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
bool CDmxEdit::SetErrorString(CDmxEdit *this, char *pFormat, ...)
{
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+1010h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  if ( _vsnprintf(string, count: 0xFFFu, format: pFormat, ap) < 0 )
    string[4095] = 0;
  CUtlString::operator=(this: &this->m_errorString, src: string);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00401340
// Name: protected: void CDmxEdit::ImportDominationRules(class CDmeCombinationOperator __near *,class CDmeCombinationOperator __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::ImportDominationRules(
        CDmxEdit *this,
        CDmeCombinationOperator *pDestComboOp,
        CDmeCombinationOperator *pSrcComboOp,
        bool bOverwrite)
{
  CDmeVertexDataBase *DominationRule; // esi
  int ClipCount; // ebx
  int v6; // edi
  const char *Dominator; // eax
  int v8; // ebx
  int v9; // edi
  const char *Suppressed; // eax
  int nRuleCount; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]
  bool bMismatch; // [esp+1Bh] [ebp+13h]

  if ( bOverwrite )
    CDmeCombinationOperator::RemoveAllDominationRules(this: pDestComboOp);
  nRuleCount = CDmeCombinationOperator::DominationRuleCount(this: pSrcComboOp);
  for ( i = 0; i < nRuleCount; ++i )
  {
    bMismatch = false;
    DominationRule = (CDmeVertexDataBase *)CDmeCombinationOperator::GetDominationRule(this: pSrcComboOp, i);
    ClipCount = CDmeTrack::GetClipCount(this: DominationRule);
    v6 = 0;
    if ( ClipCount > 0 )
    {
      while ( 1 )
      {
        Dominator = CDmeCombinationDominationRule::GetDominator(
                      this: (CDmeCombinationDominationRule *)DominationRule,
                      i: v6);
        if ( !CDmeCombinationOperator::HasRawControl(this: pDestComboOp, pRawControlName: Dominator) )
          break;
        if ( ++v6 >= ClipCount )
          goto LABEL_9;
      }
      bMismatch = true;
    }
LABEL_9:
    v8 = CDmeCombinationDominationRule::SuppressedCount(this: (CDmeCombinationDominationRule *)DominationRule);
    v9 = 0;
    if ( v8 <= 0 )
    {
LABEL_12:
      if ( !bMismatch )
        CDmeCombinationOperator::AddDominationRule(
          this: pDestComboOp,
          pSrcRule: (CDmeCombinationDominationRule *)DominationRule);
    }
    else
    {
      while ( 1 )
      {
        Suppressed = CDmeCombinationDominationRule::GetSuppressed(
                       this: (CDmeCombinationDominationRule *)DominationRule,
                       i: v9);
        if ( !CDmeCombinationOperator::HasRawControl(this: pDestComboOp, pRawControlName: Suppressed) )
          break;
        if ( ++v9 >= v8 )
          goto LABEL_12;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401410
// Name: int FindControlIndexFromRawControlName(class CDmeCombinationOperator __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindControlIndexFromRawControlName(CDmeCombinationOperator *pCombo, const char *pRawControlName)
{
  int v2; // edi
  int RawControlCount; // ebx
  int v4; // esi
  const char *RawControlName; // eax
  int nControlCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nControlCount = CDmeCombinationOperator::GetControlCount(this: pCombo);
  if ( nControlCount <= 0 )
    return -1;
  while ( 1 )
  {
    RawControlCount = CDmeCombinationOperator::GetRawControlCount(this: pCombo, nControl: v2);
    v4 = 0;
    if ( RawControlCount > 0 )
      break;
LABEL_5:
    if ( ++v2 >= nControlCount )
      return -1;
  }
  while ( 1 )
  {
    RawControlName = CDmeCombinationOperator::GetRawControlName(this: pCombo, nControl: v2, nIndex: v4);
    if ( _V_stricmp(s1: pRawControlName, s2: RawControlName) == 0 )
      return v2;
    if ( ++v4 >= RawControlCount )
      goto LABEL_5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401480
// Name: protected: bool CDmxEdit::Select(class CDmeVertexDeltaData __near *,class CDmeSingleIndexedComponent __near *,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Select(
        CDmxEdit *this,
        CDmeVertexDeltaData *pDelta,
        CDmeSingleIndexedComponent *pPassedSelection,
        CDmeMesh *pPassedMesh)
{
  CDmeMesh *m_pMesh; // ecx
  CDmeSingleIndexedComponent *m_pCurrentSelection; // eax

  if ( pDelta == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "Invalid Delta");
  m_pMesh = pPassedMesh;
  if ( pPassedMesh == nullptr )
  {
    m_pMesh = this->m_pMesh;
    if ( m_pMesh == nullptr )
      return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  }
  m_pCurrentSelection = pPassedSelection;
  if ( pPassedSelection == nullptr )
  {
    m_pCurrentSelection = this->m_pCurrentSelection;
    if ( m_pCurrentSelection == nullptr )
      return CDmxEdit::SetErrorString(this, pFormat: "No Selection To Manipulate");
  }
  CDmeMesh::SelectVerticesFromDelta(this: m_pMesh, pDelta, pSelection: m_pCurrentSelection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004014F0
// Name: public: bool CDmxEdit::Select(class CDmxEdit::CSelectType const __near &,class CDmeSingleIndexedComponent __near *,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Select(
        CDmxEdit *this,
        const CDmxEdit::CSelectType *selectType,
        CDmeSingleIndexedComponent *pPassedSelection,
        CDmeMesh *pPassedMesh)
{
  CDmxEdit::CSelectType::Select_t m_selectType; // eax
  CDmeSingleIndexedComponent *m_pCurrentSelection; // edx
  CDmeMesh *m_pMesh; // eax

  m_selectType = selectType->m_selectType;
  if ( selectType->m_selectType == kDelta )
    return CDmxEdit::SetErrorString(this, pFormat: "Called Via CSelectType... Wacky!");
  m_pCurrentSelection = pPassedSelection;
  if ( pPassedSelection == nullptr )
  {
    m_pCurrentSelection = this->m_pCurrentSelection;
    if ( m_pCurrentSelection == nullptr )
      return CDmxEdit::SetErrorString(this, pFormat: "No Selection To Manipulate");
  }
  if ( m_selectType != kNone )
  {
    if ( m_selectType == kAll )
    {
      m_pMesh = pPassedMesh;
      if ( pPassedMesh != nullptr || (m_pMesh = this->m_pMesh) != nullptr )
      {
        CDmeMesh::SelectAllVertices(this: m_pMesh, pSelection: m_pCurrentSelection, pPassedBase: nullptr);
        return 1;
      }
      else
      {
        return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    this->m_pCurrentSelection->Clear(this: this->m_pCurrentSelection);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401580
// Name: public: bool CDmxEdit::Add(enum CDmxEdit::AddType,class CDmxEditProxy const __near &,float,float,class CDmxEdit::CFalloffType const __near &,class CDmxEdit::CDistanceType const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::Add(
        CDmxEdit *this,
        CDmxEdit::AddType addType,
        const CDmxEditProxy *e,
        float weight,
        float featherDistance,
        const CDmxEdit::CFalloffType *falloffType,
        CDmxEdit::CDistanceType *passedDistanceType)
{
  CDmeSingleIndexedComponent *m_pCurrentSelection; // eax
  CDmeMesh *m_pMesh; // ecx
  CDmxEdit::CDistanceType *p_m_distanceType; // eax
  CExpressionCalculator *v12; // edi
  CDmeSingleIndexedComponent *v13; // eax
  bool v14; // al
  bool v15; // bl
  IDataModel_vtbl *v16; // esi
  int v17; // eax

  if ( this->m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  if ( this->m_pCurrentSelection->Count(this: this->m_pCurrentSelection) == 0 )
  {
    CDmxEdit::LuaWarning(this, pFormat: "No Vertices Selected, Selected ALL");
    if ( CDmxEdit::ALL.m_selectType == kDelta )
    {
      CDmxEdit::SetErrorString(this, pFormat: "Called Via CSelectType... Wacky!");
    }
    else
    {
      m_pCurrentSelection = this->m_pCurrentSelection;
      if ( m_pCurrentSelection != nullptr )
      {
        if ( CDmxEdit::ALL.m_selectType != kNone )
        {
          if ( CDmxEdit::ALL.m_selectType == kAll )
          {
            m_pMesh = this->m_pMesh;
            if ( m_pMesh != nullptr )
              CDmeMesh::SelectAllVertices(this: m_pMesh, pSelection: m_pCurrentSelection, pPassedBase: nullptr);
            else
              CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
          }
        }
        else
        {
          ((void (*)(void))m_pCurrentSelection->Clear)();
        }
      }
      else
      {
        CDmxEdit::SetErrorString(this, pFormat: "No Selection To Manipulate");
      }
    }
  }
  p_m_distanceType = passedDistanceType;
  if ( passedDistanceType->m_distanceType == DIST_DEFAULT )
    p_m_distanceType = &this->m_distanceType;
  if ( featherDistance <= 0.0 )
    v12 = nullptr;
  else
    v12 = (CExpressionCalculator *)CDmeMesh::FeatherSelection(
                                     this: this->m_pMesh,
                                     falloffDistance: featherDistance,
                                     falloffType: falloffType->m_falloffType,
                                     distanceType: p_m_distanceType->m_distanceType,
                                     pSelection: this->m_pCurrentSelection,
                                     pPassedMeshComp: nullptr);
  v13 = (CDmeSingleIndexedComponent *)v12;
  if ( addType != kRaw )
  {
    if ( v12 == nullptr )
      v13 = this->m_pCurrentSelection;
    v14 = CDmeMesh::AddCorrectedMaskedDelta(this: this->m_pMesh, pDelta: nullptr, pDst: nullptr, weight, pMask: v13);
  }
  else
  {
    if ( v12 == nullptr )
      v13 = this->m_pCurrentSelection;
    v14 = CDmeMesh::AddMaskedDelta(this: this->m_pMesh, pDelta: nullptr, pDst: nullptr, weight, pMask: v13);
  }
  v15 = v14;
  if ( v12 != nullptr )
  {
    v16 = g_pDataModel->__vftable;
    v17 = CExpressionCalculator::VariableCount(this: v12);
    v16->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v17);
  }
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x004016D0
// Name: public: bool CDmxEdit::Add(enum CDmxEdit::AddType,char const __near *,float,float,class CDmxEdit::CFalloffType const __near &,class CDmxEdit::CDistanceType const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::Add(
        CDmxEdit *this,
        CDmxEdit::AddType addType,
        const char *pDeltaName,
        float weight,
        float featherDistance,
        const CDmxEdit::CFalloffType *falloffType,
        CDmxEdit::CDistanceType *passedDistanceType)
{
  CDmeSingleIndexedComponent *m_pCurrentSelection; // eax
  CDmeMesh *m_pMesh; // ecx
  CDmxEdit::CDistanceType *p_m_distanceType; // eax
  CDmeSingleIndexedComponent *v12; // edi
  CDmeMesh *v13; // ecx
  CDmeVertexDeltaData *DeltaState; // eax
  CDmeMesh *v15; // ecx
  bool v16; // al
  bool v17; // bl
  IDataModel_vtbl *v18; // esi
  int v19; // eax

  if ( _V_stricmp(s1: "BASE", s2: pDeltaName) == 0 )
    return CDmxEdit::Add(
             this,
             addType,
             e: (const CDmxEditProxy *)&weight,
             weight,
             featherDistance,
             falloffType,
             passedDistanceType: &CDmxEdit::DIST_DEFAULT);
  if ( this->m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  if ( this->m_pCurrentSelection->Count(this: this->m_pCurrentSelection) == 0 )
  {
    CDmxEdit::LuaWarning(this, pFormat: "No Vertices Selected, Selecting ALL");
    if ( CDmxEdit::ALL.m_selectType == kDelta )
    {
      CDmxEdit::SetErrorString(this, pFormat: "Called Via CSelectType... Wacky!");
    }
    else
    {
      m_pCurrentSelection = this->m_pCurrentSelection;
      if ( m_pCurrentSelection != nullptr )
      {
        if ( CDmxEdit::ALL.m_selectType != kNone )
        {
          if ( CDmxEdit::ALL.m_selectType == kAll )
          {
            m_pMesh = this->m_pMesh;
            if ( m_pMesh != nullptr )
              CDmeMesh::SelectAllVertices(this: m_pMesh, pSelection: m_pCurrentSelection, pPassedBase: nullptr);
            else
              CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
          }
        }
        else
        {
          ((void (*)(void))m_pCurrentSelection->Clear)();
        }
      }
      else
      {
        CDmxEdit::SetErrorString(this, pFormat: "No Selection To Manipulate");
      }
    }
  }
  p_m_distanceType = passedDistanceType;
  if ( passedDistanceType->m_distanceType == DIST_DEFAULT )
    p_m_distanceType = &this->m_distanceType;
  if ( featherDistance <= 0.0 )
    v12 = nullptr;
  else
    v12 = CDmeMesh::FeatherSelection(
            this: this->m_pMesh,
            falloffDistance: featherDistance,
            falloffType: falloffType->m_falloffType,
            distanceType: p_m_distanceType->m_distanceType,
            pSelection: this->m_pCurrentSelection,
            pPassedMeshComp: nullptr);
  v13 = this->m_pMesh;
  if ( v13 == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "Invalid Delta \"%s\"", pDeltaName);
  DeltaState = CDmeMesh::FindDeltaState(this: v13, pDeltaName, bSortDeltaName: true);
  if ( DeltaState == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "Invalid Delta \"%s\"", pDeltaName);
  v15 = this->m_pMesh;
  if ( addType != kRaw )
    v16 = CDmeMesh::AddCorrectedMaskedDelta(this: v15, pDelta: DeltaState, pDst: nullptr, weight, pMask: v12);
  else
    v16 = CDmeMesh::AddMaskedDelta(this: v15, pDelta: DeltaState, pDst: nullptr, weight, pMask: v12);
  v17 = v16;
  if ( v12 != nullptr )
  {
    v18 = g_pDataModel->__vftable;
    v19 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v12);
    v18->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v19);
  }
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x00401870
// Name: public: bool CDmxEdit::Interp(class CDmxEditProxy const __near &,float,float,class CDmxEdit::CFalloffType const __near &,class CDmxEdit::CDistanceType const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::Interp(
        CDmxEdit *this,
        const CDmxEditProxy *e,
        float weight,
        float featherDistance,
        const CDmxEdit::CFalloffType *falloffType,
        CDmxEdit::CDistanceType *passedDistanceType)
{
  CDmeSingleIndexedComponent *m_pCurrentSelection; // eax
  CDmeMesh *m_pMesh; // ecx
  CDmxEdit::CDistanceType *p_m_distanceType; // eax
  CDmeSingleIndexedComponent *v11; // eax
  CExpressionCalculator *v12; // edi
  bool v13; // bl
  IDataModel_vtbl *v14; // esi
  int v15; // eax

  if ( this->m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  if ( this->m_pCurrentSelection->Count(this: this->m_pCurrentSelection) == 0 )
  {
    CDmxEdit::LuaWarning(this, pFormat: "No Vertices Selected, Selecting ALL");
    if ( CDmxEdit::ALL.m_selectType == kDelta )
    {
      CDmxEdit::SetErrorString(this, pFormat: "Called Via CSelectType... Wacky!");
    }
    else
    {
      m_pCurrentSelection = this->m_pCurrentSelection;
      if ( m_pCurrentSelection != nullptr )
      {
        if ( CDmxEdit::ALL.m_selectType != kNone )
        {
          if ( CDmxEdit::ALL.m_selectType == kAll )
          {
            m_pMesh = this->m_pMesh;
            if ( m_pMesh != nullptr )
              CDmeMesh::SelectAllVertices(this: m_pMesh, pSelection: m_pCurrentSelection, pPassedBase: nullptr);
            else
              CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
          }
        }
        else
        {
          ((void (*)(void))m_pCurrentSelection->Clear)();
        }
      }
      else
      {
        CDmxEdit::SetErrorString(this, pFormat: "No Selection To Manipulate");
      }
    }
  }
  p_m_distanceType = passedDistanceType;
  if ( passedDistanceType->m_distanceType == DIST_DEFAULT )
    p_m_distanceType = &this->m_distanceType;
  if ( featherDistance <= 0.0 )
  {
    v12 = nullptr;
    goto LABEL_18;
  }
  v11 = CDmeMesh::FeatherSelection(
          this: this->m_pMesh,
          falloffDistance: featherDistance,
          falloffType: falloffType->m_falloffType,
          distanceType: p_m_distanceType->m_distanceType,
          pSelection: this->m_pCurrentSelection,
          pPassedMeshComp: nullptr);
  v12 = (CExpressionCalculator *)v11;
  if ( v11 == nullptr )
LABEL_18:
    v11 = this->m_pCurrentSelection;
  v13 = CDmeMesh::InterpMaskedDelta(this: this->m_pMesh, pDelta: nullptr, pDst: nullptr, weight, pMask: v11);
  if ( v12 != nullptr )
  {
    v14 = g_pDataModel->__vftable;
    v15 = CExpressionCalculator::VariableCount(this: v12);
    v14->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v15);
  }
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x004019A0
// Name: public: bool CDmxEdit::Interp(char const __near *,float,float,class CDmxEdit::CFalloffType const __near &,class CDmxEdit::CDistanceType const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::Interp(
        CDmxEdit *this,
        const char *pDeltaName,
        float weight,
        float featherDistance,
        const CDmxEdit::CFalloffType *falloffType,
        CDmxEdit::CDistanceType *passedDistanceType)
{
  CDmeSingleIndexedComponent *m_pCurrentSelection; // eax
  CDmeMesh *m_pMesh; // ecx
  CDmxEdit::CDistanceType *p_m_distanceType; // eax
  CExpressionCalculator *v11; // edi
  CDmeMesh *v12; // ecx
  CDmeVertexDeltaData *DeltaState; // eax
  CDmeSingleIndexedComponent *v14; // ecx
  bool v15; // bl
  IDataModel_vtbl *v16; // esi
  int v17; // eax

  if ( _V_stricmp(s1: "BASE", s2: pDeltaName) == 0 )
    return CDmxEdit::Interp(
             this,
             e: (const CDmxEditProxy *)&featherDistance,
             weight,
             featherDistance,
             falloffType,
             passedDistanceType: &CDmxEdit::DIST_DEFAULT);
  if ( this->m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  if ( this->m_pCurrentSelection->Count(this: this->m_pCurrentSelection) == 0 )
  {
    CDmxEdit::LuaWarning(this, pFormat: "No Vertices Selected, Selecting ALL");
    if ( CDmxEdit::ALL.m_selectType == kDelta )
    {
      CDmxEdit::SetErrorString(this, pFormat: "Called Via CSelectType... Wacky!");
    }
    else
    {
      m_pCurrentSelection = this->m_pCurrentSelection;
      if ( m_pCurrentSelection != nullptr )
      {
        if ( CDmxEdit::ALL.m_selectType != kNone )
        {
          if ( CDmxEdit::ALL.m_selectType == kAll )
          {
            m_pMesh = this->m_pMesh;
            if ( m_pMesh != nullptr )
              CDmeMesh::SelectAllVertices(this: m_pMesh, pSelection: m_pCurrentSelection, pPassedBase: nullptr);
            else
              CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
          }
        }
        else
        {
          ((void (*)(void))m_pCurrentSelection->Clear)();
        }
      }
      else
      {
        CDmxEdit::SetErrorString(this, pFormat: "No Selection To Manipulate");
      }
    }
  }
  p_m_distanceType = passedDistanceType;
  if ( passedDistanceType->m_distanceType == DIST_DEFAULT )
    p_m_distanceType = &this->m_distanceType;
  if ( featherDistance <= 0.0 )
    v11 = nullptr;
  else
    v11 = (CExpressionCalculator *)CDmeMesh::FeatherSelection(
                                     this: this->m_pMesh,
                                     falloffDistance: featherDistance,
                                     falloffType: falloffType->m_falloffType,
                                     distanceType: p_m_distanceType->m_distanceType,
                                     pSelection: this->m_pCurrentSelection,
                                     pPassedMeshComp: nullptr);
  v12 = this->m_pMesh;
  if ( v12 == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "Invalid Delta \"%s\"", pDeltaName);
  DeltaState = CDmeMesh::FindDeltaState(this: v12, pDeltaName, bSortDeltaName: true);
  if ( DeltaState == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "Invalid Delta \"%s\"", pDeltaName);
  v14 = (CDmeSingleIndexedComponent *)v11;
  if ( v11 == nullptr )
    v14 = this->m_pCurrentSelection;
  v15 = CDmeMesh::InterpMaskedDelta(this: this->m_pMesh, pDelta: DeltaState, pDst: nullptr, weight, pMask: v14);
  if ( v11 != nullptr )
  {
    v16 = g_pDataModel->__vftable;
    v17 = CExpressionCalculator::VariableCount(this: v11);
    v16->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v17);
  }
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x00401B40
// Name: public: bool CDmxEdit::SaveDelta(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::SaveDelta(CDmxEdit *this, const char *pDeltaName)
{
  int v4; // eax
  CDmeMesh *m_pMesh; // ecx
  CDmeVertexData *CurrentBaseState; // edi
  CDmeVertexData *BindBaseState; // eax

  if ( this->m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v4 = _V_stricmp(s1: pDeltaName, s2: "base");
  m_pMesh = this->m_pMesh;
  if ( v4 == 0 )
  {
    CurrentBaseState = CDmeMesh::GetCurrentBaseState(this: m_pMesh);
    if ( CurrentBaseState == nullptr )
      return CDmxEdit::SetErrorString(this, pFormat: "Couldn't Get Current Base State");
    BindBaseState = CDmeMesh::GetBindBaseState(this: this->m_pMesh);
    if ( BindBaseState == nullptr )
      return CDmxEdit::SetErrorString(this, pFormat: "Couldn't Get Bind Base State");
    if ( CurrentBaseState == BindBaseState )
      return CDmxEdit::SetErrorString(this, pFormat: "Current Is Same As Bind State");
    CDmeVertexDataBase::CopyTo(this: CurrentBaseState, pDst: BindBaseState);
  }
  else if ( CDmeMesh::ModifyOrCreateDeltaStateFromBaseState(
              this: m_pMesh,
              pDeltaName,
              pPassedBase: nullptr,
              absolute: false) == nullptr )
  {
    return CDmxEdit::SetErrorString(this, pFormat: "Couldn't Create New Delta State From Base State");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401C10
// Name: public: void CDmxEdit::CleanupWork(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::CleanupWork(CDmxEdit *this)
{
  CDmeMesh *m_pMesh; // ecx
  CExpressionCalculator *m_pCurrentSelection; // ecx
  IDataModel_vtbl *v4; // edi
  int v5; // eax

  m_pMesh = this->m_pMesh;
  if ( m_pMesh != nullptr )
  {
    CDmElement::RemoveAttribute(this: m_pMesh, pAttributeName: "selection");
    m_pCurrentSelection = (CExpressionCalculator *)this->m_pCurrentSelection;
    if ( m_pCurrentSelection != nullptr )
    {
      v4 = g_pDataModel->__vftable;
      v5 = CExpressionCalculator::VariableCount(this: m_pCurrentSelection);
      v4->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
      this->m_pCurrentSelection = nullptr;
    }
    if ( CDmeMesh::FindBaseState(this: this->m_pMesh, pStateName: "bind") != nullptr )
      CDmeMesh::SetCurrentBaseState(this: this->m_pMesh, pStateName: "bind");
    if ( CDmeMesh::FindBaseState(this: this->m_pMesh, pStateName: "__dmxEdit_work") != nullptr )
      CDmeMesh::DeleteBaseState(this: this->m_pMesh, pStateName: "__dmxEdit_work");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C90
// Name: protected: void CDmxEdit::GetFuncArg(struct lua_State __near *,int,class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::GetFuncArg(CDmxEdit *this, lua_State *pLuaState, int nIndex, CUtlString *funcString)
{
  long double rhs; // st7
  bool v5; // zf
  const char *v6; // eax
  const char *v7; // eax
  int v9; // edi
  int v10; // eax
  const char *v11; // eax
  int nCount; // [esp+28h] [ebp+10h]

  switch ( lua_type(L: pLuaState, idx: nIndex) )
  {
    case 0:
    case 2:
    case 6:
    case 7:
    case 8:
      CUtlString::operator+=(this: funcString, rhs: "<");
      v11 = lua_typename(L: pLuaState, t: nIndex);
      CUtlString::operator+=(this: funcString, rhs: v11);
      CUtlString::operator+=(this: funcString, rhs: ">");
      break;
    case 1:
      v5 = lua_toboolean(L: pLuaState, idx: nIndex) == 0;
      v6 = "true";
      if ( v5 )
        v6 = "false";
      CUtlString::operator+=(this: funcString, rhs: v6);
      break;
    case 3:
      rhs = lua_tonumber(L: pLuaState, idx: nIndex);
      CUtlString::operator+=(this: funcString, rhs);
      break;
    case 4:
      CUtlString::operator+=(this: funcString, rhs: "\"");
      v7 = lua_tolstring(L: pLuaState, idx: nIndex, len: nullptr);
      CUtlString::operator+=(this: funcString, rhs: v7);
      CUtlString::operator+=(this: funcString, rhs: "\"");
      break;
    case 5:
      CUtlString::operator+=(this: funcString, rhs: "{ ");
      v9 = 1;
      nCount = lua_objlen(L: pLuaState, idx: nIndex);
      if ( nCount >= 1 )
      {
        do
        {
          lua_rawgeti(L: pLuaState, idx: nIndex, n: v9);
          if ( v9 > 1 )
            CUtlString::operator+=(this: funcString, rhs: ", ");
          v10 = lua_gettop(L: pLuaState);
          CDmxEdit::GetFuncArg(this, pLuaState, nIndex: v10, funcString);
          lua_settop(L: pLuaState, idx: -2);
          ++v9;
        }
        while ( v9 <= nCount );
      }
      CUtlString::operator+=(this: funcString, rhs: " }");
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401E20
// Name: public: class CUtlString const __near & CDmxEdit::SetFuncString(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxEdit::SetFuncString(CDmxEdit *this, lua_State *pLuaState)
{
  CUtlString *p_m_funcString; // edi
  int i; // ebx
  CUtlString *p_m_sourceFile; // esi
  const char *source; // eax
  lua_Debug ar; // [esp+8h] [ebp-68h] BYREF
  CDmxEdit *v8; // [esp+6Ch] [ebp-4h]

  p_m_funcString = &this->m_funcString;
  v8 = this;
  CUtlString::SetLength(this: &this->m_funcString, nLen: 0);
  lua_getstack(L: pLuaState, level: 0, &ar);
  lua_getinfo(L: pLuaState, what: "Sln", &ar);
  if ( ar.name != nullptr )
    CUtlString::operator=(this: p_m_funcString, src: ar.name);
  else
    CUtlString::operator=(this: p_m_funcString, src: "Unknown");
  CUtlString::operator+=(this: p_m_funcString, rhs: "(");
  if ( lua_gettop(L: pLuaState) >= 1 )
    CUtlString::operator+=(this: p_m_funcString, rhs: " ");
  for ( i = 1; i <= lua_gettop(L: pLuaState); ++i )
  {
    if ( i > 1 )
      CUtlString::operator+=(this: p_m_funcString, rhs: ", ");
    CDmxEdit::GetFuncArg(this: v8, pLuaState, nIndex: i, funcString: p_m_funcString);
  }
  if ( lua_gettop(L: pLuaState) >= 1 )
    CUtlString::operator+=(this: p_m_funcString, rhs: " ");
  CUtlString::operator+=(this: p_m_funcString, rhs: ");");
  lua_getstack(L: pLuaState, level: 1, &ar);
  lua_getinfo(L: pLuaState, what: "Sln", &ar);
  p_m_sourceFile = &v8->m_sourceFile;
  v8->m_lineNo = ar.currentline;
  CUtlString::SetLength(this: p_m_sourceFile, nLen: 0);
  source = ar.source;
  if ( ar.source != nullptr )
  {
    if ( *ar.source == 64 )
      source = ar.source + 1;
    CUtlString::operator=(this: p_m_sourceFile, src: source);
  }
  return p_m_funcString;
}

//------------------------------------------------------------------------------
// Address: 0x00401F60
// Name: public: CDmxEditLua::CDmxEditLua(void)
// Source: json
//------------------------------------------------------------------------------
CDmxEditLua *__thiscall CDmxEditLua::CDmxEditLua(CDmxEditLua *this)
{
  lua_State *v2; // eax
  LuaFunc_s *i; // esi
  const char *v4; // eax

  v2 = luaL_newstate();
  this->m_pLuaState = v2;
  luaL_openlibs(L: v2);
  for ( i = LuaFunc_s::s_pFirstFunc; i != nullptr; i = i->m_pNextFunc )
  {
    lua_pushcclosure(L: this->m_pLuaState, fn: i->m_pFunc, n: 0);
    lua_setfield(L: this->m_pLuaState, idx: -10002, k: i->m_pFuncName);
  }
  if ( luaL_loadstring(
         L: this->m_pLuaState,
         s: "vsLuaDir = os.getenv( \"VPROJECT\" );\n"
         "vsLuaDir = string.gsub( vsLuaDir, \"[\\\\/]\", \"/\" );\n"
         "vsLuaDir = string.gsub( vsLuaDir, \"/*$\", \"\" );\n"
         "vsLuaDir = ( string.gsub( vsLuaDir, \"[^/]+$\", \"sdktools/lua\" ) .. \"/?.lua\" );\n"
         "package.path = ( package.path .. \";\" .. vsLuaDir );\n"
         "require( \"vs\" );\n") != 0
    || lua_pcall(L: this->m_pLuaState, nargs: 0, nresults: -1, errfunc: 0) != 0 )
  {
    v4 = lua_tolstring(L: this->m_pLuaState, idx: -1, len: nullptr);
    _Error(a1: "Error: %s\n", v4);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401FF0
// Name: public: class CDmeCombinationOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeCombinationOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeCombinationOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeCombinationOperator *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_0;
      case TD_DEEP:
        goto $LN11;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_0:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeCombinationOperator::m_classType) )
          return nullptr;
        result = (CDmeCombinationOperator *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004020A0
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402130
// Name: public: CDisableUndoScopeGuard::CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
CDisableUndoScopeGuard *__thiscall CDisableUndoScopeGuard::CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  *(_WORD *)&this->m_bReleased = 0;
  this->m_pNotify = nullptr;
  this->m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402170
// Name: public: CDisableUndoScopeGuard::~CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDisableUndoScopeGuard::~CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  CChangeUndoScopeGuard::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x00402180
// Name: public: class CDmAttribute __near * CDmElement::SetValue<char const>(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue,
        char bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( bCreateIfNotFound == 0 && !CDmElement::HasAttribute(this, pAttributeName, type: AT_STRING) )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&bCreateIfNotFound, a3: pValue);
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&bCreateIfNotFound);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x00402200
// Name: public: void CDmElement::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElement::SetName(CDmElement *this, const char *pName)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pName, a3: pName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: this->m_Name.m_pAttribute, value: (const CUtlSymbolLarge *)&pName);
}

//------------------------------------------------------------------------------
// Address: 0x00402230
// Name: DeltaCount_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DeltaCount_luaFunc(lua_State *pLuaState)
{
  int v1; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
    v1 = CDmeMesh::DeltaStateCount(this: LuaFunc_s::m_dmxEdit.m_pMesh);
  else
    v1 = CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Mesh");
  lua_pushnumber(L: pLuaState, n: (double)v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402290
// Name: public: void CDmxEdit::Unload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::Unload(CDmxEdit *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CExpressionCalculator *m_pCurrentSelection; // ecx
  IDataModel_vtbl *v4; // edi
  int v5; // eax
  CDmElement *m_pRoot; // eax
  CDisableUndoScopeGuard sgDisableUndo; // [esp+8h] [ebp-14h] BYREF
  int v8; // [esp+18h] [ebp-4h]

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  sgDisableUndo.m_bNotify = false;
  sgDisableUndo.m_pNotify = nullptr;
  *(_WORD *)&sgDisableUndo.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_pCurrentSelection = (CExpressionCalculator *)this->m_pCurrentSelection;
  v8 = 0;
  if ( m_pCurrentSelection != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: m_pCurrentSelection);
    v4->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
  }
  m_pRoot = this->m_pRoot;
  if ( m_pRoot != nullptr )
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_pRoot->m_fileId);
  CUtlString::operator=(this: &this->m_filename, src: var);
  this->m_pRoot = nullptr;
  this->m_pMesh = nullptr;
  this->m_pCurrentSelection = nullptr;
  v8 = -1;
  CChangeUndoScopeGuard::Release(this: &sgDisableUndo);
}

//------------------------------------------------------------------------------
// Address: 0x00402350
// Name: public: bool CDmxEdit::Select(char const __near *,class CDmeSingleIndexedComponent __near *,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Select(
        CDmxEdit *this,
        const char *pSelectTypeString,
        CDmeSingleIndexedComponent *pPassedSelection,
        CDmeMesh *pPassedMesh)
{
  const char *v4; // esi
  const char *v6; // eax
  CDmeMesh *v7; // ebx
  CDmeMesh *m_pMesh; // ecx
  CDmeVertexDeltaData *DeltaState; // eax

  v4 = pSelectTypeString;
  v6 = (const char *)_V_stricmp(s1: pSelectTypeString, s2: "NONE");
  if ( v6 != nullptr )
    v6 = (const char *)((_V_stricmp(s1: v4, s2: "ALL") != 0) + 1);
  pSelectTypeString = v6;
  if ( v6 != (const char *)2 )
    return CDmxEdit::Select(
             this,
             selectType: (const CDmxEdit::CSelectType *)&pSelectTypeString,
             pPassedSelection,
             pPassedMesh);
  v7 = pPassedMesh;
  m_pMesh = pPassedMesh;
  if ( pPassedMesh == nullptr )
    m_pMesh = this->m_pMesh;
  if ( m_pMesh != nullptr
    && (DeltaState = CDmeMesh::FindDeltaState(this: m_pMesh, pDeltaName: v4, bSortDeltaName: true)) != nullptr )
  {
    return CDmxEdit::Select(this, pDelta: DeltaState, pPassedSelection, pPassedMesh: v7);
  }
  else
  {
    return CDmxEdit::SetErrorString(this, pFormat: "Invalid Delta \"%s\"", v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004023F0
// Name: public: bool CDmxEdit::Merge(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::Merge(CDmxEdit *this, const char *pInFilename, const char *pOutFilename)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  DmFileId_t (__thiscall *RestoreFromFile)(IDataModel *, const char *, const char *, const char *, CDmElement **, DmConflictResolution_t, DmxHeader_t *); // eax
  bool v6; // bl
  CP4File *v8; // eax
  bool (__thiscall *v9)(IDataModel *); // edx
  CP4File *v10; // eax
  CP4File *v11; // eax
  CDisableUndoScopeGuard guard1; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard guard0; // [esp+14h] [ebp-18h] BYREF
  CDmElement *pRoot; // [esp+1Ch] [ebp-10h] BYREF
  int v15; // [esp+28h] [ebp-4h]
  bool retVal_3; // [esp+37h] [ebp+Bh]

  pRoot = nullptr;
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  guard0.m_bNotify = false;
  guard0.m_pNotify = nullptr;
  *(_WORD *)&guard0.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  RestoreFromFile = g_pDataModel->RestoreFromFile;
  v15 = 0;
  RestoreFromFile(
    this: g_pDataModel,
    a2: pInFilename,
    a3: nullptr,
    a4: nullptr,
    a5: &pRoot,
    a6: CR_DELETE_NEW,
    a7: nullptr);
  CChangeUndoScopeGuard::Release(this: &guard0);
  if ( pRoot != nullptr )
  {
    v8 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pInFilename);
    v8->Add(this: v8);
    retVal_3 = CDmMeshUtils::Merge(pSrcMesh: this->m_pMesh, pRoot);
    v9 = g_pDataModel->IsUndoEnabled;
    guard1.m_bNotify = false;
    guard1.m_pNotify = nullptr;
    *(_WORD *)&guard1.m_bOldValue = v9(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    LOBYTE(v15) = 1;
    if ( retVal_3 )
    {
      v10 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pOutFilename);
      if ( !v10->Edit(this: v10) )
      {
        v11 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pOutFilename);
        v11->Add(this: v11);
      }
      if ( !g_pDataModel->SaveToFile(
              this: g_pDataModel,
              a2: pOutFilename,
              a3: nullptr,
              a4: "keyvalues2",
              a5: "model",
              a6: pRoot) )
      {
        retVal_3 = false;
        CDmxEdit::SetErrorString(this, pFormat: "Can't Write File \"%s\"", pOutFilename);
      }
    }
    else
    {
      CDmxEdit::SetErrorString(this, pFormat: "Failed! \"%s\" Unchanged", pOutFilename);
    }
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: pRoot->m_fileId);
    CChangeUndoScopeGuard::Release(this: &guard1);
    LOBYTE(v15) = 0;
    CChangeUndoScopeGuard::Release(this: &guard1);
    v15 = -1;
    CChangeUndoScopeGuard::Release(this: &guard0);
    return retVal_3;
  }
  else
  {
    v6 = CDmxEdit::SetErrorString(this, pFormat: "Can't Load File \"%s\"", pInFilename);
    v15 = -1;
    CChangeUndoScopeGuard::Release(this: &guard0);
    return v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025C0
// Name: public: void CDmxEdit::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxEdit::Error(CDmxEdit *this, char *pMsgFormat, ...)
{
  _iobuf *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  char string[5020]; // [esp+Ch] [ebp-139Ch] BYREF
  va_list ap; // [esp+13B8h] [ebp+10h] BYREF

  va_start(ap, pMsgFormat);
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    outColor = (Color)16843009;
  }
  this->m_errorState = true;
  _vsnprintf(string, count: 0x139Bu, format: pMsgFormat, ap);
  printf(format: string);
  v2 = __iob_func();
  fflush(stream: v2 + 1);
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-coe") == 0 )
  {
    v4 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-continueOnError") == 0 )
    {
      if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
        _Msg(a1: "\nPress q To Quit, d To Debug Or Any Key To Continue After Error...");
      else
        _Msg(a1: "\nPress q To Quit Or Any Key To Continue After Error...");
      v5 = getch();
      v6 = v5;
      if ( v5 == 113 || v5 == 81 )
      {
        CDmxEdit::Unload(this);
        exit(code: 1);
      }
      if ( ((unsigned __int8)_Plat_IsInDebugSession() != 0 && v6 == 100 || v6 == 68)
        && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
      {
        __debugbreak();
      }
      _Msg(a1: "\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004026D0
// Name: public: bool CDmxEditLua::DoIt(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEditLua::DoIt(CDmxEditLua *this, const char *pFilename)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  bool v4; // bl
  const char *v5; // eax
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-18h] BYREF
  bool retVal; // [esp+17h] [ebp-Dh]
  int v9; // [esp+20h] [ebp-4h]

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v4 = false;
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v9 = 0;
  retVal = true;
  CUtlString::operator=(this: &LuaFunc_s::m_dmxEdit.m_scriptFilename, src: pFilename);
  if ( luaL_loadfile(L: this->m_pLuaState, filename: pFilename) != 0
    || lua_pcall(L: this->m_pLuaState, nargs: 0, nresults: -1, errfunc: 0) != 0 )
  {
    v5 = lua_tolstring(L: this->m_pLuaState, idx: -1, len: nullptr);
    _Error(a1: "Error: %s\n", v5);
  }
  else
  {
    v4 = retVal;
  }
  lua_close(L: this->m_pLuaState);
  CDmxEdit::Unload(this: &LuaFunc_s::m_dmxEdit);
  v9 = -1;
  CChangeUndoScopeGuard::Release(this: &guard);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004027B0
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class CDmElement>(char const __near *,class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<CDmElement>(
        CDmElement *this,
        const char *pAttributeName,
        DmElementHandle_t pElement,
        bool bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    if ( !bCreateIfNotFound )
      return nullptr;
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_VALUE_TYPE);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &pElement);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x004028F0
// Name: public: enum DmElementHandle_t const __near & CDmAttribute::GetValue<enum DmElementHandle_t>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CDmAttribute::GetValue<enum DmElementHandle_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  if ( (this->m_nFlags & 0x1F) == 1 )
    return (CDmaVar<enum DmElementHandle_t> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<enum DmElementHandle_t>(this) )
    return &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  CDmAttribute::CopyDataOut<enum DmElementHandle_t>(
    this,
    value: &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`7'::tempVal);
  return (CDmaVar<enum DmElementHandle_t> *)&`CDmAttribute::GetValue<enum DmElementHandle_t>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00402950
// Name: public: char const __near * CDmElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmElement::GetName(CDmElement *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402960
// Name: public: int CDmxEdit::LuaError(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxEdit::LuaError(CDmxEdit *this, lua_State *pLuaState)
{
  int m_lineNo; // edi
  const char *v4; // eax
  const char *v6; // [esp-8h] [ebp-10h]
  const char *v7; // [esp-4h] [ebp-Ch]

  m_lineNo = this->m_lineNo;
  v7 = CUtlString::operator char const *(this: &this->m_errorString);
  v6 = CUtlString::operator char const *(this: &this->m_funcString);
  if ( m_lineNo < 0 )
  {
    CDmxEdit::Error(this, pMsgFormat: "// ERROR: %s - %s\n", v6, v7);
  }
  else
  {
    v4 = CUtlString::operator char const *(this: &this->m_sourceFile);
    CDmxEdit::Error(this, pMsgFormat: "// ERROR: %s:%d: %s - %s\n", v4, m_lineNo, v6, v7);
  }
  lua_pushboolean(L: pLuaState, b: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004029D0
// Name: public: int CDmxEdit::LuaError(struct lua_State __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CDmxEdit::LuaError(CDmxEdit *this, lua_State *pLuaState, char *pFormat, ...)
{
  int m_lineNo; // edi
  const char *v4; // eax
  const char *v5; // eax
  const char *v7; // [esp-10h] [ebp-1010h]
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+1014h] [ebp+14h] BYREF

  va_start(ap, pFormat);
  if ( _vsnprintf(string, count: 0xFFFu, format: pFormat, ap) < 0 )
    string[4095] = 0;
  m_lineNo = this->m_lineNo;
  if ( m_lineNo < 0 )
  {
    v5 = CUtlString::operator char const *(this: &this->m_funcString);
    CDmxEdit::Error(this, pMsgFormat: "// ERROR: %s - %s\n", v5, string);
  }
  else
  {
    v7 = CUtlString::operator char const *(this: &this->m_funcString);
    v4 = CUtlString::operator char const *(this: &this->m_sourceFile);
    CDmxEdit::Error(this, pMsgFormat: "// ERROR: %s:%d: %s - %s\n", v4, m_lineNo, v7, string);
  }
  lua_pushboolean(L: pLuaState, b: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402A80
// Name: public: bool CDmxEdit::ListDeltas(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::ListDeltas(CDmxEdit *this)
{
  CDmeMesh *m_pMesh; // ecx
  int v4; // edi
  const char *v5; // eax
  int v6; // esi
  const char *m_pAsString; // eax

  m_pMesh = this->m_pMesh;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v4 = CDmeMesh::DeltaStateCount(this: m_pMesh);
  if ( v4 > 0 )
  {
    v6 = 0;
    do
    {
      m_pAsString = CDmeMesh::GetDeltaState(this: this->m_pMesh, nDeltaIndex: v6)->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      _Msg(a1: "// Delta %d: %s\n", v6++, m_pAsString);
    }
    while ( v6 < v4 );
    return 1;
  }
  else
  {
    v5 = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = var;
    return CDmxEdit::SetErrorString(this, pFormat: "No Deltas Defined On Mesh: %s", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402B10
// Name: ListDeltas_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListDeltas_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  if ( CDmxEdit::ListDeltas(this: &LuaFunc_s::m_dmxEdit) == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v1);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402B70
// Name: DeltaName_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DeltaName_luaFunc(lua_State *pLuaState)
{
  int v1; // eax
  int v2; // edi
  const char *m_pAsString; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = (int)luaL_checknumber(L: pLuaState, narg: 1);
  v2 = v1;
  if ( LuaFunc_s::m_dmxEdit.m_pMesh == nullptr )
  {
    CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Mesh");
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  }
  if ( v1 >= CDmeMesh::DeltaStateCount(this: LuaFunc_s::m_dmxEdit.m_pMesh) )
  {
    CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "Delta Index Too High");
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  }
  m_pAsString = CDmeMesh::GetDeltaState(this: LuaFunc_s::m_dmxEdit.m_pMesh, nDeltaIndex: v2)->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
  {
    lua_pushstring(L: pLuaState, s: var);
    return 1;
  }
  else
  {
    if ( m_pAsString == nullptr )
      return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
    lua_pushstring(L: pLuaState, s: m_pAsString);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402C20
// Name: SetState_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SetState_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  const char *v2; // esi
  bool v3; // al
  const CDmeVertexDeltaData *DeltaState; // eax
  const char *v5; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  v2 = v1;
  if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
  {
    DeltaState = CDmeMesh::FindDeltaState(this: LuaFunc_s::m_dmxEdit.m_pMesh, pDeltaName: v1, bSortDeltaName: true);
    if ( DeltaState != nullptr )
      v3 = CDmeMesh::SetBaseStateToDelta(this: LuaFunc_s::m_dmxEdit.m_pMesh, pDelta: DeltaState, pPassedBase: nullptr);
    else
      v3 = CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "Invalid Delta \"%s\"", v2);
  }
  else
  {
    v3 = CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Mesh");
  }
  if ( !v3 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v5 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v5);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402CD0
// Name: ResetState_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ResetState_luaFunc(lua_State *pLuaState)
{
  bool v1; // al
  const char *v2; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
    v1 = CDmeMesh::SetBaseStateToDelta(this: LuaFunc_s::m_dmxEdit.m_pMesh, pDelta: nullptr, pPassedBase: nullptr);
  else
    v1 = CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Mesh");
  if ( !v1 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v2 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v2);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402D50
// Name: SelectHalf_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SelectHalf_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  char v2; // al
  BOOL v3; // edx
  bool v4; // al
  const char *v5; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( v1 != nullptr )
  {
    v2 = *v1;
    v3 = v2 != 108 && v2 != 76 && (v2 == 114 || v2 == 82);
    if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
    {
      if ( LuaFunc_s::m_dmxEdit.m_pCurrentSelection != nullptr )
      {
        CDmeMesh::SelectHalfVertices(
          this: LuaFunc_s::m_dmxEdit.m_pMesh,
          selectHalfType: (CDmeMesh::SelectHalfType_t)v3,
          pSelection: LuaFunc_s::m_dmxEdit.m_pCurrentSelection,
          pPassedBase: nullptr);
        goto LABEL_11;
      }
      v4 = CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Selection To Manipulate");
    }
    else
    {
      v4 = CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Mesh");
    }
    if ( v4 )
    {
LABEL_11:
      v5 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
      _Msg(a1: "// %s\n", v5);
      lua_pushboolean(L: pLuaState, b: 1);
      return 1;
    }
  }
  return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
}

//------------------------------------------------------------------------------
// Address: 0x00402E10
// Name: GrowSelection_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl GrowSelection_luaFunc(lua_State *pLuaState)
{
  int v1; // eax
  const char *v2; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  if ( lua_isnumber(L: pLuaState, idx: 1) != 0 )
  {
    v1 = lua_tointeger(L: pLuaState, idx: 1);
    if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
    {
      CDmeMesh::GrowSelection(
        this: LuaFunc_s::m_dmxEdit.m_pMesh,
        nSize: v1,
        pSelection: LuaFunc_s::m_dmxEdit.m_pCurrentSelection,
        pPassedMeshComp: nullptr);
      goto LABEL_4;
    }
  }
  else if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
  {
    CDmeMesh::GrowSelection(
      this: LuaFunc_s::m_dmxEdit.m_pMesh,
      nSize: 1,
      pSelection: LuaFunc_s::m_dmxEdit.m_pCurrentSelection,
      pPassedMeshComp: nullptr);
    goto LABEL_4;
  }
  if ( CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Mesh") )
  {
LABEL_4:
    v2 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
    _Msg(a1: "// %s\n", v2);
    lua_pushboolean(L: pLuaState, b: 1);
    return 1;
  }
  return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
}

//------------------------------------------------------------------------------
// Address: 0x00402EC0
// Name: ShrinkSelection_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ShrinkSelection_luaFunc(lua_State *pLuaState)
{
  int v1; // eax
  const char *v2; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  if ( lua_isnumber(L: pLuaState, idx: 1) != 0 )
  {
    v1 = lua_tointeger(L: pLuaState, idx: 1);
    if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
    {
      CDmeMesh::ShrinkSelection(
        this: LuaFunc_s::m_dmxEdit.m_pMesh,
        nSize: v1,
        pSelection: LuaFunc_s::m_dmxEdit.m_pCurrentSelection,
        pPassedMeshComp: nullptr);
      goto LABEL_4;
    }
  }
  else if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
  {
    CDmeMesh::ShrinkSelection(
      this: LuaFunc_s::m_dmxEdit.m_pMesh,
      nSize: 1,
      pSelection: LuaFunc_s::m_dmxEdit.m_pCurrentSelection,
      pPassedMeshComp: nullptr);
    goto LABEL_4;
  }
  if ( CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Mesh") )
  {
LABEL_4:
    v2 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
    _Msg(a1: "// %s\n", v2);
    lua_pushboolean(L: pLuaState, b: 1);
    return 1;
  }
  return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
}

//------------------------------------------------------------------------------
// Address: 0x00402F70
// Name: Add_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Add_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  double v2; // xmm0_8
  double v3; // xmm0_8
  const char *v4; // eax
  const char *v5; // eax
  float weight; // [esp+1Ch] [ebp-10h]
  float featherDistance; // [esp+24h] [ebp-8h]
  CDmxEdit::CFalloffType falloffType; // [esp+28h] [ebp-4h] BYREF

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_isnumber(L: pLuaState, idx: 2) != 0 )
    v2 = lua_tonumber(L: pLuaState, idx: 2);
  else
    v2 = 1.0;
  weight = v2;
  if ( lua_isnumber(L: pLuaState, idx: 3) != 0 )
    v3 = lua_tonumber(L: pLuaState, idx: 3);
  else
    v3 = 0.0;
  if ( lua_isstring(L: pLuaState, idx: 4) != 0 )
    v4 = lua_tolstring(L: pLuaState, idx: 4, len: nullptr);
  else
    v4 = "straight";
  falloffType.m_falloffType = CDmxEdit::CFalloffType::StringToFalloff(this: &falloffType, pFalloffTypeString: v4);
  featherDistance = v3;
  if ( !CDmxEdit::Add(
          this: &LuaFunc_s::m_dmxEdit,
          addType: kRaw,
          pDeltaName: v1,
          weight,
          featherDistance,
          &falloffType,
          passedDistanceType: &CDmxEdit::DIST_DEFAULT) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v5 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v5);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004030A0
// Name: AddCorrected_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddCorrected_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  double v2; // xmm0_8
  double v3; // xmm0_8
  const char *v4; // eax
  const char *v5; // eax
  float weight; // [esp+1Ch] [ebp-10h]
  float featherDistance; // [esp+24h] [ebp-8h]
  CDmxEdit::CFalloffType falloffType; // [esp+28h] [ebp-4h] BYREF

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_isnumber(L: pLuaState, idx: 2) != 0 )
    v2 = lua_tonumber(L: pLuaState, idx: 2);
  else
    v2 = 1.0;
  weight = v2;
  if ( lua_isnumber(L: pLuaState, idx: 3) != 0 )
    v3 = lua_tonumber(L: pLuaState, idx: 3);
  else
    v3 = 0.0;
  if ( lua_isstring(L: pLuaState, idx: 4) != 0 )
    v4 = lua_tolstring(L: pLuaState, idx: 4, len: nullptr);
  else
    v4 = "straight";
  falloffType.m_falloffType = CDmxEdit::CFalloffType::StringToFalloff(this: &falloffType, pFalloffTypeString: v4);
  featherDistance = v3;
  if ( !CDmxEdit::Add(
          this: &LuaFunc_s::m_dmxEdit,
          addType: kCorrected,
          pDeltaName: v1,
          weight,
          featherDistance,
          &falloffType,
          passedDistanceType: &CDmxEdit::DIST_DEFAULT) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v5 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v5);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004031D0
// Name: Interp_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interp_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  double v2; // xmm0_8
  double v3; // xmm0_8
  const char *v4; // eax
  const char *v5; // eax
  float weight; // [esp+1Ch] [ebp-10h]
  float featherDistance; // [esp+24h] [ebp-8h]
  CDmxEdit::CFalloffType falloffType; // [esp+28h] [ebp-4h] BYREF

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_isnumber(L: pLuaState, idx: 2) != 0 )
    v2 = lua_tonumber(L: pLuaState, idx: 2);
  else
    v2 = 1.0;
  weight = v2;
  if ( lua_isnumber(L: pLuaState, idx: 3) != 0 )
    v3 = lua_tonumber(L: pLuaState, idx: 3);
  else
    v3 = 0.0;
  if ( lua_isstring(L: pLuaState, idx: 4) != 0 )
    v4 = lua_tolstring(L: pLuaState, idx: 4, len: nullptr);
  else
    v4 = "straight";
  falloffType.m_falloffType = CDmxEdit::CFalloffType::StringToFalloff(this: &falloffType, pFalloffTypeString: v4);
  featherDistance = v3;
  if ( !CDmxEdit::Interp(
          this: &LuaFunc_s::m_dmxEdit,
          pDeltaName: v1,
          weight,
          featherDistance,
          &falloffType,
          passedDistanceType: &CDmxEdit::DIST_DEFAULT) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v5 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v5);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403300
// Name: Merge_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Merge_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  const char *v2; // eax
  const char *v3; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  v2 = luaL_checklstring(L: pLuaState, narg: 2, len: nullptr);
  if ( !CDmxEdit::Merge(this: &LuaFunc_s::m_dmxEdit, pInFilename: v1, pOutFilename: v2) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v3 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v3);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403380
// Name: SaveDelta_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SaveDelta_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  const char *v2; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( CDmxEdit::SaveDelta(this: &LuaFunc_s::m_dmxEdit, pDeltaName: v1) == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v2 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v2);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004033F0
// Name: RemoveFacesWithMaterial_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl RemoveFacesWithMaterial_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  const char *v2; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( !CDmMeshUtils::RemoveFacesWithMaterial(pMesh: LuaFunc_s::m_dmxEdit.m_pMesh, pMaterialName: v1) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v2 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v2);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403460
// Name: RemoveFacesWithMoreThanNVerts_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl RemoveFacesWithMoreThanNVerts_luaFunc(lua_State *pLuaState)
{
  int v1; // eax
  const char *v2; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checkinteger(L: pLuaState, narg: 1);
  CDmMeshUtils::RemoveFacesWithMoreThanNVerts(pMesh: LuaFunc_s::m_dmxEdit.m_pMesh, nVertexCount: v1);
  v2 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v2);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004034C0
// Name: Mirror_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mirror_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  char v2; // al
  int v3; // eax
  bool v4; // al
  const char *v5; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  if ( lua_isstring(L: pLuaState, idx: 1) != 0 )
  {
    v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
    if ( v1 != nullptr )
    {
      v2 = *v1;
      if ( v2 == 121 || v2 == 89 )
      {
        v3 = 1;
LABEL_10:
        v4 = CDmMeshUtils::Mirror(pMesh: LuaFunc_s::m_dmxEdit.m_pMesh, axis: v3);
        goto LABEL_11;
      }
      if ( v2 == 122 || v2 == 90 )
      {
        v3 = 2;
        goto LABEL_10;
      }
    }
    v3 = 0;
    goto LABEL_10;
  }
  v4 = CDmMeshUtils::Mirror(pMesh: LuaFunc_s::m_dmxEdit.m_pMesh, axis: CDmxEdit::XAXIS.m_axisType);
LABEL_11:
  if ( !v4 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v5 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v5);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403570
// Name: ComputeNormals_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ComputeNormals_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  CDmeMesh::ComputeDeltaStateNormals(this: LuaFunc_s::m_dmxEdit.m_pMesh);
  v1 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v1);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004035C0
// Name: SetDistanceType_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SetDistanceType_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  char v2; // al
  CDmeMesh::Distance_t v3; // eax
  const char *v4; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( v1 == nullptr )
    goto LABEL_8;
  v2 = *v1;
  if ( v2 != 97 && v2 != 65 )
  {
    if ( v2 == 114 || v2 == 82 )
    {
      v3 = DIST_RELATIVE;
      goto LABEL_9;
    }
LABEL_8:
    v3 = DIST_DEFAULT;
    goto LABEL_9;
  }
  v3 = DIST_ABSOLUTE;
LABEL_9:
  LuaFunc_s::m_dmxEdit.m_distanceType.m_distanceType = v3;
  v4 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v4);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403640
// Name: FileExists_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileExists_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  const char *v2; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v1, a3: nullptr) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState, pFormat: "File \"%s\" Doesn't Exist", v1);
  v2 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v2);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004036C0
// Name: bool HasDuplicateControlName(class CDmeCombinationOperator __near *,char const __near *,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HasDuplicateControlName(
        CDmeCombinationOperator *pDmeCombo,
        const char *pControlName,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *retiredControlNames)
{
  int m_Size; // edi
  int i; // esi

  m_Size = retiredControlNames->m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( _V_stricmp(s1: retiredControlNames->m_Memory.m_pMemory[i], s2: pControlName) == 0 )
      break;
  }
  return i == m_Size && CDmeCombinationOperator::FindControlIndex(this: pDmeCombo, pControlName) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403710
// Name: public: float CDmxEdit::MaxDeltaDistance(char const __near *)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CDmxEdit::MaxDeltaDistance(CDmxEdit *this, const char *pDeltaName)
{
  CDmeMesh *m_pMesh; // ecx
  CDmeVertexDeltaData *DeltaState; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // eax
  int m_Size; // edi
  float v7; // xmm0_4
  int v8; // ebx
  float *p_z; // edx
  float *v10; // esi
  unsigned int v11; // ecx
  float *p_x; // eax
  int v13; // edi
  float fSqMaxDelta; // [esp+8h] [ebp+8h]

  m_pMesh = this->m_pMesh;
  if ( m_pMesh == nullptr )
    return 0.0;
  DeltaState = CDmeMesh::FindDeltaState(this: m_pMesh, pDeltaName, bSortDeltaName: true);
  if ( DeltaState == nullptr )
    return 0.0;
  fSqMaxDelta = 0.0;
  PositionData = CDmeVertexDataBase::GetPositionData(this: DeltaState);
  m_Size = PositionData->m_Size;
  v7 = 0.0;
  v8 = 0;
  if ( m_Size >= 4 )
  {
    p_z = &PositionData->m_Memory.m_pMemory[1].z;
    v10 = &PositionData->m_Memory.m_pMemory->z;
    v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    v8 = 4 * v11;
    do
    {
      if ( v7 <= (float)((float)((float)(*(v10 - 1) * *(v10 - 1)) + (float)(*(v10 - 2) * *(v10 - 2)))
                       + (float)(*v10 * *v10)) )
        v7 = (float)((float)(*(v10 - 1) * *(v10 - 1)) + (float)(*(v10 - 2) * *(v10 - 2))) + (float)(*v10 * *v10);
      if ( v7 <= (float)((float)((float)(v10[1] * v10[1]) + (float)(*(p_z - 1) * *(p_z - 1))) + (float)(*p_z * *p_z)) )
        v7 = (float)((float)(v10[1] * v10[1]) + (float)(*(p_z - 1) * *(p_z - 1))) + (float)(*p_z * *p_z);
      if ( v7 <= (float)((float)((float)(v10[4] * v10[4]) + (float)(p_z[2] * p_z[2])) + (float)(p_z[3] * p_z[3])) )
        v7 = (float)((float)(v10[4] * v10[4]) + (float)(p_z[2] * p_z[2])) + (float)(p_z[3] * p_z[3]);
      if ( v7 <= (float)((float)((float)(p_z[5] * p_z[5]) + (float)(v10[7] * v10[7])) + (float)(p_z[6] * p_z[6])) )
        v7 = (float)((float)(p_z[5] * p_z[5]) + (float)(v10[7] * v10[7])) + (float)(p_z[6] * p_z[6]);
      v10 += 12;
      p_z += 12;
      --v11;
    }
    while ( v11 != 0 );
    fSqMaxDelta = v7;
  }
  if ( v8 < m_Size )
  {
    p_x = &PositionData->m_Memory.m_pMemory[v8].x;
    v13 = m_Size - v8;
    do
    {
      if ( v7 <= (float)((float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])) + (float)(p_x[2] * p_x[2])) )
        v7 = (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])) + (float)(p_x[2] * p_x[2]);
      p_x += 3;
      --v13;
    }
    while ( v13 != 0 );
    fSqMaxDelta = v7;
  }
  return sqrt(fSqMaxDelta);
}

//------------------------------------------------------------------------------
// Address: 0x00403880
// Name: MaxDeltaDistance_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl MaxDeltaDistance_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  long double n; // st7

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  n = CDmxEdit::MaxDeltaDistance(this: &LuaFunc_s::m_dmxEdit, pDeltaName: v1);
  lua_pushnumber(L: pLuaState, n);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004038D0
// Name: void FindBoundingSphere(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &,class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindBoundingSphere(CUtlVector<Vector,CUtlMemory<Vector,int> > *points, Vector *cen, float *fRad)
{
  Vector *v4; // ebx
  int m_Size; // esi
  float v6; // xmm6_4
  float x; // xmm4_4
  int v8; // ecx
  float v9; // xmm3_4
  float v10; // xmm5_4
  float v11; // xmm7_4
  float *p_z; // ecx
  float *v13; // eax
  unsigned int v14; // edx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  Vector *v25; // eax
  int v26; // esi
  float y; // xmm1_4
  float z; // xmm2_4
  double v29; // xmm0_8
  double v30; // xmm1_8
  float v31; // xmm5_4
  double v32; // xmm1_8
  double v33; // xmm2_8
  float v34; // xmm6_4
  float v35; // xmm4_4
  float v36; // xmm3_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  float v39; // xmm6_4
  float v40; // xmm2_4
  int v41; // edx
  double v42; // xmm1_8
  double v43; // xmm0_8
  float v44; // xmm5_4
  int v45; // ecx
  Vector *v46; // eax
  double v47; // xmm2_8
  double v48; // xmm4_8
  double v49; // xmm3_8
  double v50; // xmm2_8
  float v51; // xmm0_4
  float dia1_8; // [esp+8h] [ebp-4Ch]
  float xmax_4; // [esp+10h] [ebp-44h]
  float xmax_8; // [esp+14h] [ebp-40h]
  float xmin_4; // [esp+1Ch] [ebp-38h]
  float xmin_8; // [esp+20h] [ebp-34h]
  float zmax; // [esp+24h] [ebp-30h]
  float zmax_4; // [esp+28h] [ebp-2Ch]
  int zmax_8; // [esp+2Ch] [ebp-28h]
  float ymax; // [esp+30h] [ebp-24h]
  int ymax_4; // [esp+34h] [ebp-20h]
  float ymax_8; // [esp+38h] [ebp-1Ch]
  float zmin; // [esp+3Ch] [ebp-18h]
  float zmin_4; // [esp+40h] [ebp-14h]
  float zmin_8; // [esp+44h] [ebp-10h]
  float v66; // [esp+48h] [ebp-Ch]
  float dz; // [esp+4Ch] [ebp-8h]
  float dz_4; // [esp+50h] [ebp-4h]
  int i; // [esp+5Ch] [ebp+8h]

  if ( points->m_Size > 0 )
  {
    v4 = cen;
    *cen = *points->m_Memory.m_pMemory;
    *fRad = 0.0;
    m_Size = points->m_Size;
    v6 = 3.4028235e38;
    dz = 3.4028235e38;
    x = 3.4028235e38;
    v8 = 0;
    v9 = -3.4028235e38;
    v10 = -3.4028235e38;
    zmin_8 = 3.4028235e38;
    zmax_8 = -8388609;
    ymax_4 = -8388609;
    v11 = -3.4028235e38;
    if ( m_Size >= 4 )
    {
      p_z = &points->m_Memory.m_pMemory->z;
      v13 = &points->m_Memory.m_pMemory[1].z;
      v14 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * v14;
      do
      {
        v15 = *(p_z - 2);
        if ( x > v15 )
        {
          xmin_4 = *(p_z - 1);
          x = *(p_z - 2);
          xmin_8 = *p_z;
        }
        if ( v15 > v11 )
        {
          xmax_4 = *(p_z - 1);
          v11 = *(p_z - 2);
          xmax_8 = *p_z;
        }
        v16 = *(p_z - 1);
        if ( dz > v16 )
        {
          v66 = *(p_z - 2);
          dz = *(p_z - 1);
          dz_4 = *p_z;
        }
        if ( v16 > v10 )
        {
          ymax = *(p_z - 2);
          v10 = *(p_z - 1);
          ymax_8 = *p_z;
        }
        if ( v6 > *p_z )
        {
          zmin = *(p_z - 2);
          zmin_4 = *(p_z - 1);
          v6 = *p_z;
        }
        if ( *p_z > v9 )
        {
          zmax = *(p_z - 2);
          zmax_4 = *(p_z - 1);
          v9 = *p_z;
        }
        v17 = p_z[1];
        if ( x > v17 )
        {
          xmin_4 = *(v13 - 1);
          x = p_z[1];
          xmin_8 = *v13;
        }
        if ( v17 > v11 )
        {
          xmax_4 = *(v13 - 1);
          v11 = p_z[1];
          xmax_8 = *v13;
        }
        v18 = *(v13 - 1);
        if ( dz > v18 )
        {
          v66 = p_z[1];
          dz = *(v13 - 1);
          dz_4 = *v13;
        }
        if ( v18 > v10 )
        {
          ymax = p_z[1];
          v10 = *(v13 - 1);
          ymax_8 = *v13;
        }
        if ( v6 > *v13 )
        {
          zmin = p_z[1];
          zmin_4 = *(v13 - 1);
          v6 = *v13;
        }
        if ( *v13 > v9 )
        {
          zmax = p_z[1];
          zmax_4 = *(v13 - 1);
          v9 = *v13;
        }
        v19 = p_z[4];
        if ( x > v19 )
        {
          xmin_4 = v13[2];
          x = p_z[4];
          xmin_8 = v13[3];
        }
        if ( v19 > v11 )
        {
          xmax_4 = v13[2];
          v11 = p_z[4];
          xmax_8 = v13[3];
        }
        v20 = v13[2];
        if ( dz > v20 )
        {
          v66 = p_z[4];
          dz = v13[2];
          dz_4 = v13[3];
        }
        if ( v20 > v10 )
        {
          ymax = p_z[4];
          v10 = v13[2];
          ymax_8 = v13[3];
        }
        v21 = v13[3];
        if ( v6 > v21 )
        {
          zmin = p_z[4];
          zmin_4 = v13[2];
          v6 = v13[3];
        }
        if ( v21 > v9 )
        {
          zmax = p_z[4];
          zmax_4 = v13[2];
          v9 = v13[3];
        }
        v22 = p_z[7];
        if ( x > v22 )
        {
          xmin_4 = v13[5];
          x = p_z[7];
          xmin_8 = v13[6];
        }
        if ( v22 > v11 )
        {
          xmax_4 = v13[5];
          v11 = p_z[7];
          xmax_8 = v13[6];
        }
        v23 = v13[5];
        if ( dz > v23 )
        {
          v66 = p_z[7];
          dz = v13[5];
          dz_4 = v13[6];
        }
        if ( v23 > v10 )
        {
          ymax = p_z[7];
          v10 = v13[5];
          ymax_8 = v13[6];
        }
        v24 = v13[6];
        if ( v6 > v24 )
        {
          zmin = p_z[7];
          zmin_4 = v13[5];
          v6 = v13[6];
        }
        if ( v24 > v9 )
        {
          zmax = p_z[7];
          zmax_4 = v13[5];
          v9 = v13[6];
        }
        p_z += 12;
        v13 += 12;
        --v14;
      }
      while ( v14 != 0 );
      v4 = cen;
      v8 = i;
      zmax_8 = LODWORD(v9);
      zmin_8 = v6;
      ymax_4 = LODWORD(v10);
    }
    if ( v8 < m_Size )
    {
      v25 = &points->m_Memory.m_pMemory[v8];
      v26 = m_Size - v8;
      do
      {
        if ( x > v25->x )
        {
          xmin_4 = v25->y;
          x = v25->x;
          xmin_8 = v25->z;
        }
        if ( v25->x > v11 )
        {
          xmax_4 = v25->y;
          v11 = v25->x;
          xmax_8 = v25->z;
        }
        y = v25->y;
        if ( dz > y )
        {
          v66 = v25->x;
          dz = v25->y;
          dz_4 = v25->z;
        }
        if ( y > v10 )
        {
          ymax = v25->x;
          v10 = v25->y;
          ymax_8 = v25->z;
        }
        z = v25->z;
        if ( v6 > z )
        {
          zmin = v25->x;
          zmin_4 = v25->y;
          v6 = v25->z;
        }
        if ( z > v9 )
        {
          zmax = v25->x;
          zmax_4 = v25->y;
          v9 = v25->z;
        }
        ++v25;
        --v26;
      }
      while ( v26 != 0 );
      zmax_8 = LODWORD(v9);
      zmin_8 = v6;
      ymax_4 = LODWORD(v10);
    }
    v29 = (float)(xmax_4 - xmin_4) * (float)(xmax_4 - xmin_4)
        + (float)(v11 - x) * (float)(v11 - x)
        + (float)(xmax_8 - xmin_8) * (float)(xmax_8 - xmin_8);
    v30 = (float)(v10 - dz);
    v31 = xmax_8;
    v32 = v30 * v30 + (float)(ymax - v66) * (float)(ymax - v66) + (float)(ymax_8 - dz_4) * (float)(ymax_8 - dz_4);
    v33 = (float)(zmax_4 - zmin_4) * (float)(zmax_4 - zmin_4)
        + (float)(zmax - zmin) * (float)(zmax - zmin)
        + (float)(v9 - zmin_8) * (float)(v9 - zmin_8);
    v34 = x;
    v35 = xmax_4;
    dia1_8 = xmin_8;
    v36 = v11;
    if ( v32 <= v29 )
    {
      v37 = xmin_4;
    }
    else
    {
      v34 = v66;
      v37 = dz;
      v36 = ymax;
      v35 = *(float *)&ymax_4;
      v31 = ymax_8;
      v29 = v32;
      dia1_8 = dz_4;
    }
    if ( v33 > v29 )
    {
      v34 = zmin;
      v37 = zmin_4;
      v36 = zmax;
      v35 = zmax_4;
      v31 = *(float *)&zmax_8;
      dia1_8 = zmin_8;
    }
    v38 = (float)(v36 + v34) * 0.5;
    v4->x = v38;
    v39 = (float)(v31 + dia1_8) * 0.5;
    v40 = (float)(v35 + v37) * 0.5;
    v41 = 0;
    v4->y = v40;
    v4->z = v39;
    v42 = (float)(v35 - v40) * (float)(v35 - v40)
        + (float)(v36 - v38) * (float)(v36 - v38)
        + (float)(v31 - v39) * (float)(v31 - v39);
    v43 = sqrt(v42);
    if ( points->m_Size > 0 )
    {
      v44 = (float)(v35 + v37) * 0.5;
      v45 = 0;
      do
      {
        v46 = &points->m_Memory.m_pMemory[v45];
        v47 = (float)(v46->y - v44) * (float)(v46->y - v44)
            + (float)(v46->x - v4->x) * (float)(v46->x - v4->x)
            + (float)(v46->z - v39) * (float)(v46->z - v39);
        if ( v47 > v42 )
        {
          v48 = sqrt(v47);
          v49 = 1.0 / v48;
          v43 = (v43 + v48) * 0.5;
          v50 = v48 - v43;
          *(float *)&v48 = (v4->x * v43 + points->m_Memory.m_pMemory[v45].x * (v48 - v43)) * (1.0 / v48);
          v4->x = *(float *)&v48;
          v44 = (v44 * v43 + v46->y * v50) * v49;
          v4->y = v44;
          v39 = (v39 * v43 + v46->z * v50) * v49;
          v42 = v43 * v43;
          v4->z = v39;
        }
        ++v41;
        ++v45;
      }
      while ( v41 < points->m_Size );
    }
    v51 = v43;
    *fRad = v51;
  }
  else
  {
    cen->z = 0.0;
    cen->y = 0.0;
    cen->x = 0.0;
    *fRad = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404120
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CDmxEdit::delta *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404160
// Name: protected: bool CDmxEdit::Select(class CDmxEdit::CSelectOp const __near &,class CDmeSingleIndexedComponent __near *,class CDmeSingleIndexedComponent const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::Select(
        CDmxEdit *this,
        const CDmxEdit::CSelectOp *selectOp,
        CDmeSingleIndexedComponent *pOriginal,
        const CDmeSingleIndexedComponent *pNew)
{
  bool result; // al
  CDmeSingleIndexedComponent *v5; // edi
  CDmeSingleIndexedComponent *v6; // ebx
  const char *m_pAsString; // eax
  const char *v8; // eax
  CUtlString originalName; // [esp+8h] [ebp-1Ch] BYREF
  int v10; // [esp+20h] [ebp-4h]

  if ( pOriginal == nullptr || pNew == nullptr )
    return false;
  switch ( selectOp->m_selectOp )
  {
    case 0:
      CDmeSingleIndexedComponent::Add(this: pOriginal, rhs: pNew);
      result = true;
      break;
    case 1:
      CDmeSingleIndexedComponent::Subtract(this: pOriginal, rhs: pNew);
      result = true;
      break;
    case 2:
      v5 = CreateElement<CDmeSingleIndexedComponent>(
             pObjectName: "intersection",
             fileid: pOriginal->m_fileId,
             pObjectID: nullptr);
      if ( v5 != nullptr
        && (v6 = CreateElement<CDmeSingleIndexedComponent>(
                   pObjectName: "newCopy",
                   fileid: pOriginal->m_fileId,
                   pObjectID: nullptr)) != nullptr )
      {
        CDmElement::CopyAttributesTo(this: pOriginal, pCopy: v5, depth: TD_DEEP);
        CDmeSingleIndexedComponent::Intersection(this: v5, rhs: pNew);
        CDmeSingleIndexedComponent::Subtract(this: pOriginal, rhs: v5);
        CDmElement::CopyAttributesTo(this: &pNew->CDmeComponent, pCopy: v6, depth: TD_DEEP);
        CDmeSingleIndexedComponent::Subtract(this: v6, rhs: v5);
        CDmeSingleIndexedComponent::Add(this: pOriginal, rhs: v6);
        result = true;
      }
      else
      {
        result = false;
      }
      break;
    case 3:
      CDmeSingleIndexedComponent::Intersection(this: pOriginal, rhs: pNew);
      result = true;
      break;
    case 4:
      m_pAsString = pOriginal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      CUtlString::CUtlString(this: &originalName, pString: m_pAsString);
      v10 = 0;
      CDmElement::CopyAttributesTo(this: &pNew->CDmeComponent, pCopy: pOriginal, depth: TD_DEEP);
      v8 = CUtlString::operator char const *(this: &originalName);
      CDmElement::SetName(this: pOriginal, pName: v8);
      v10 = -1;
      CUtlString::~CUtlString(this: (CDmxEdit::delta *)&originalName);
      goto LABEL_14;
    default:
LABEL_14:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404320
// Name: protected: void CDmxEdit::AddExportTags(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::AddExportTags(CDmxEdit *this, CDmElement *pRoot, int pFilename)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CUtlSymbolLarge::<unnamed_type_u> v12; // edi
  const char *v13; // eax
  CDmAttribute *v14; // eax
  const char *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // eax
  char szTmpBuf[512]; // [esp+Ch] [ebp-22Ch] BYREF
  CUtlString cmdLine; // [esp+20Ch] [ebp-2Ch] BYREF
  CUtlSymbolLarge v21; // [esp+21Ch] [ebp-1Ch] BYREF
  unsigned int dwSize; // [esp+220h] [ebp-18h] BYREF
  CUtlSymbolLarge v23; // [esp+224h] [ebp-14h] BYREF
  CUtlSymbolLarge value; // [esp+228h] [ebp-10h] BYREF
  int v25; // [esp+234h] [ebp-4h]

  v23.u.m_Id = (int)this;
  if ( pRoot != nullptr )
  {
    v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "dmxedit_exportTags",
           a4: pRoot->m_fileId,
           a5: nullptr);
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v5 = nullptr;
    _strdate(buffer: szTmpBuf);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: szTmpBuf);
    Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "date");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v5, pAttributeName: "date", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    _strtime(buffer: szTmpBuf);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: szTmpBuf);
    v7 = CDmElement::FindAttribute(this: v5, pAttributeName: "time");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "time", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v7, &value);
    }
    dwSize = 512;
    szTmpBuf[0] = 0;
    MyGetUserName(pszBuf: szTmpBuf, pBufSiz: &dwSize);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: szTmpBuf);
    v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "user");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: v5, pAttributeName: "user", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v8, &value);
    }
    szTmpBuf[0] = 0;
    dwSize = 512;
    MyGetComputerName(pszBuf: szTmpBuf, pBufSiz: &dwSize);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: szTmpBuf);
    v9 = CDmElement::FindAttribute(this: v5, pAttributeName: "machine");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "machine", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v9, &value);
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "dmxedit");
    v10 = CDmElement::FindAttribute(this: v5, pAttributeName: "app");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(this: v5, pAttributeName: "app", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v10, &value);
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &v21, a3: pChangeList);
    v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "appVersion");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v5, pAttributeName: "appVersion", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: &v21);
    }
    CUtlString::CUtlString(this: &cmdLine, pString: "dmxedit ");
    v12.m_Id = v23.u.m_Id;
    v25 = 0;
    CUtlString::operator+=(this: &cmdLine, rhs: (const CUtlString *)(v23.u.m_Id + 116));
    CUtlString::operator+=(this: &cmdLine, rhs: var);
    v13 = CUtlString::Get(this: &cmdLine);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &v23, a3: v13);
    v14 = CDmElement::FindAttribute(this: v5, pAttributeName: "cmdLine");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(this: v5, pAttributeName: "cmdLine", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v23);
    }
    v15 = CUtlString::Get(this: (CUtlString *)(v12.m_Id + 4));
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &v23, a3: v15);
    v16 = CDmElement::FindAttribute(this: v5, pAttributeName: "Load");
    if ( v16 != nullptr
      || (v16 = CDmElement::CreateAttribute(this: v5, pAttributeName: "Load", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v16, value: &v23);
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFilename, a3: (const char *)pFilename);
    v17 = CDmElement::FindAttribute(this: v5, pAttributeName: "Save");
    if ( v17 != nullptr
      || (v17 = CDmElement::CreateAttribute(this: v5, pAttributeName: "Save", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v17, value: (const CUtlSymbolLarge *)&pFilename);
    }
    if ( v5 != nullptr )
      pFilename = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v5);
    else
      pFilename = -1;
    v18 = CDmElement::FindAttribute(this: pRoot, pAttributeName: "dmxedit_exportTags");
    if ( v18 != nullptr
      || (v18 = CDmElement::CreateAttribute(
                  this: pRoot,
                  pAttributeName: "dmxedit_exportTags",
                  type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: v18, value: (const DmElementHandle_t *)&pFilename);
    }
    v25 = -1;
    cmdLine.m_Storage.m_nActualLength = 0;
    if ( cmdLine.m_Storage.m_Memory.m_nGrowSize >= 0 && cmdLine.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmdLine.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404730
// Name: public: bool CDmxEdit::RemapMaterial(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::RemapMaterial(CDmxEdit *this, int nMaterialIndex, const char *pNewMaterialName)
{
  bool v4; // bl
  CDmeMesh *m_pMesh; // [esp-Ch] [ebp-30h]
  CUtlString dst; // [esp+8h] [ebp-1Ch] BYREF
  int v8; // [esp+20h] [ebp-4h]

  CUtlString::CUtlString(this: &dst, pString: pNewMaterialName);
  m_pMesh = this->m_pMesh;
  v8 = 0;
  v4 = CDmMeshUtils::RemapMaterial(pMesh: m_pMesh, nMaterialIndex, &dst);
  v8 = -1;
  dst.m_Storage.m_nActualLength = 0;
  if ( dst.m_Storage.m_Memory.m_nGrowSize >= 0 && dst.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dst.m_Storage.m_Memory.m_pMemory);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004047C0
// Name: public: bool CDmxEdit::RemapMaterial(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::RemapMaterial(CDmxEdit *this, const char *pOldMaterialName, const char *pNewMaterialName)
{
  bool result; // al
  CDmeMesh *m_pMesh; // [esp-Ch] [ebp-40h]
  CUtlString dst; // [esp+8h] [ebp-2Ch] BYREF
  CUtlString src; // [esp+18h] [ebp-1Ch] BYREF
  int v8; // [esp+30h] [ebp-4h]
  bool pNewMaterialName_3; // [esp+43h] [ebp+Fh]

  CUtlString::CUtlString(this: &dst, pString: pNewMaterialName);
  v8 = 0;
  CUtlString::CUtlString(this: &src, pString: pOldMaterialName);
  m_pMesh = this->m_pMesh;
  LOBYTE(v8) = 1;
  result = CDmMeshUtils::RemapMaterial(pMesh: m_pMesh, &src, &dst);
  pNewMaterialName_3 = result;
  LOBYTE(v8) = 0;
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
      result = pNewMaterialName_3;
      src.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    src.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v8 = -1;
  dst.m_Storage.m_nActualLength = 0;
  if ( dst.m_Storage.m_Memory.m_nGrowSize >= 0 && dst.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dst.m_Storage.m_Memory.m_pMemory);
    return pNewMaterialName_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404880
// Name: RemapMaterial_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl RemapMaterial_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  int v2; // ebx
  const char *v3; // ebx
  const char *v4; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 2, len: nullptr);
  if ( lua_isnumber(L: pLuaState, idx: 1) != 0 )
  {
    v2 = luaL_checkinteger(L: pLuaState, narg: 1);
    if ( !CDmxEdit::RemapMaterial(this: &LuaFunc_s::m_dmxEdit, nMaterialIndex: v2, pNewMaterialName: v1) )
      CDmxEdit::LuaWarning(
        this: &LuaFunc_s::m_dmxEdit,
        pFormat: "Invalid Material Index To Remap, Couldn't Find Material %d\n",
        v2);
  }
  else
  {
    v3 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
    if ( !CDmxEdit::RemapMaterial(this: &LuaFunc_s::m_dmxEdit, pOldMaterialName: v3, pNewMaterialName: v1) )
      CDmxEdit::LuaWarning(
        this: &LuaFunc_s::m_dmxEdit,
        pFormat: "Invalid Material To Remap, Couldn't Find Material \"%s\"\n",
        v3);
  }
  v4 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v4);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404940
// Name: public: bool CDmxEdit::ComputeWrinkles(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::ComputeWrinkles(CDmxEdit *this, bool bOverwrite)
{
  CDmeMesh *m_pMesh; // esi
  CUtlSymbolLarge *v5; // eax
  CDmeCombinationOperator *Referring; // eax
  const char *m_pAsString; // eax
  _BYTE v8[4]; // [esp+14h] [ebp-4h] BYREF

  m_pMesh = this->m_pMesh;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v8, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: m_pMesh,
                symAttrName: (CUtlSymbolLarge)v5->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    CDmeCombinationOperator::GenerateWrinkleDeltas(this: Referring, bOverwrite, bUseNormalForSign: false, flScale: 1.0);
    return 1;
  }
  else
  {
    m_pAsString = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    return CDmxEdit::SetErrorString(this, pFormat: "No Combination Operator On Mesh \"%s\"", m_pAsString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004049F0
// Name: ComputeWrinkles_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ComputeWrinkles_luaFunc(lua_State *pLuaState)
{
  char v1; // al
  const char *v2; // eax
  bool bOverwrite; // [esp+4h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  if ( lua_type(L: pLuaState, idx: 1) == 1 )
  {
    bOverwrite = lua_toboolean(L: pLuaState, idx: 1) != 0;
    v1 = CDmxEdit::ComputeWrinkles(this: &LuaFunc_s::m_dmxEdit, bOverwrite);
  }
  else
  {
    v1 = CDmxEdit::ComputeWrinkles(this: &LuaFunc_s::m_dmxEdit, bOverwrite: false);
  }
  if ( v1 == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v2 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v2);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404A80
// Name: public: bool CDmxEdit::ComputeWrinkle(char const __near *,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::ComputeWrinkle(CDmxEdit *this, const char *pDeltaName, float flScale, const char *pOperation)
{
  CDmeMesh *m_pMesh; // ecx
  CDmeMesh *v7; // edi
  CUtlSymbolLarge *v8; // eax
  CDmeCombinationOperator *Referring; // edi
  const char *m_pAsString; // eax
  CDmMeshUtils::WrinkleOp v11; // esi
  int v12; // ebx
  int v13; // esi
  const char *RawControlName; // eax
  _BYTE v15[4]; // [esp+2Ch] [ebp-14h] BYREF
  CDmeVertexDeltaData *pDelta; // [esp+30h] [ebp-10h]
  CDmxEdit *v17; // [esp+34h] [ebp-Ch]
  CDmMeshUtils::WrinkleOp wrinkleOp; // [esp+38h] [ebp-8h]
  int nControlCount; // [esp+3Ch] [ebp-4h]
  int nRawControlCount; // [esp+50h] [ebp+10h]

  m_pMesh = this->m_pMesh;
  v17 = this;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  pDelta = CDmeMesh::FindDeltaState(this: m_pMesh, pDeltaName, bSortDeltaName: true);
  if ( pDelta == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "Cannot Find Delta State \"%s\"", pDeltaName);
  v7 = this->m_pMesh;
  v8 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v15, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: v7,
                symAttrName: (CUtlSymbolLarge)v8->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    v11 = StringAfterPrefix(str: pOperation, prefix: "r") == nullptr;
    wrinkleOp = v11;
    v12 = 0;
    nControlCount = CDmeCombinationOperator::GetControlCount(this: Referring);
    if ( nControlCount > 0 )
    {
      do
      {
        v13 = 0;
        nRawControlCount = CDmeCombinationOperator::GetRawControlCount(this: Referring, nControl: v12);
        if ( nRawControlCount > 0 )
        {
          while ( 1 )
          {
            RawControlName = CDmeCombinationOperator::GetRawControlName(this: Referring, nControl: v12, nIndex: v13);
            if ( _V_strcmp(s1: pDeltaName, s2: RawControlName) == 0 )
              break;
            if ( ++v13 >= nRawControlCount )
              goto LABEL_15;
          }
          CDmeCombinationOperator::SetWrinkleScale(
            this: Referring,
            nControl: v12,
            pRawControlName: pDeltaName,
            flWrinkleScale: 1.0);
        }
LABEL_15:
        ++v12;
      }
      while ( v12 < nControlCount );
      v11 = wrinkleOp;
    }
    return CDmMeshUtils::CreateWrinkleDeltaFromBaseState(
             pDelta,
             flScale,
             wrinkleOp: v11,
             pPassedMesh: v17->m_pMesh,
             pPassedBind: nullptr,
             pPassedCurrent: nullptr,
             bUseNormalForSign: false);
  }
  else
  {
    m_pAsString = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    return CDmxEdit::SetErrorString(this, pFormat: "No DmeCombinationOperator On Mesh \"%s\"", m_pAsString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BF0
// Name: ComputeWrinkle_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ComputeWrinkle_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  double v2; // xmm0_8
  const char *v3; // eax
  const char *v4; // eax
  float flScale; // [esp+14h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_isnumber(L: pLuaState, idx: 2) != 0 )
    v2 = lua_tonumber(L: pLuaState, idx: 2);
  else
    v2 = 1.0;
  if ( lua_isstring(L: pLuaState, idx: 3) != 0 )
    v3 = lua_tolstring(L: pLuaState, idx: 3, len: nullptr);
  else
    v3 = "REPLACE";
  flScale = v2;
  if ( !CDmxEdit::ComputeWrinkle(this: &LuaFunc_s::m_dmxEdit, pDeltaName: v1, flScale, pOperation: v3) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v4 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v4);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404CD0
// Name: public: bool CDmxEdit::CreateExpressionFilesFromCachedPresets(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::CreateExpressionFilesFromCachedPresets(CDmxEdit *this)
{
  CDmxEdit *v1; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  const CDmElement *m_pMesh; // esi
  CUtlSymbolLarge *v5; // eax
  int v6; // edi
  const char *v7; // esi
  CP4File *v8; // eax
  CDmePresetGroup *v9; // ebx
  CUtlString *v10; // edi
  const char *v11; // eax
  CP4File *v12; // eax
  CP4File *v13; // eax
  CDmeCombinationOperator *v14; // esi
  CP4File *v15; // eax
  CP4File *v16; // eax
  int m_NumElements; // ecx
  void (__thiscall *SetUndoEnabled)(IDataModel *, bool); // edx
  char buf1[260]; // [esp+Ch] [ebp-234h] BYREF
  char buf[260]; // [esp+110h] [ebp-130h] BYREF
  _BYTE v21[4]; // [esp+214h] [ebp-2Ch] BYREF
  CDmeCombinationOperator *pComboOp; // [esp+218h] [ebp-28h]
  CDisableUndoScopeGuard sgDisableUndo; // [esp+21Ch] [ebp-24h] BYREF
  CDmElement *pRoot; // [esp+224h] [ebp-1Ch] BYREF
  int i; // [esp+228h] [ebp-18h]
  CDmxEdit *v26; // [esp+22Ch] [ebp-14h]
  bool bRetVal; // [esp+233h] [ebp-Dh]
  int v28; // [esp+23Ch] [ebp-4h]

  v1 = this;
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  v26 = this;
  bRetVal = true;
  sgDisableUndo.m_bNotify = false;
  sgDisableUndo.m_pNotify = nullptr;
  *(_WORD *)&sgDisableUndo.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_pMesh = v1->m_pMesh;
  v28 = 0;
  if ( m_pMesh != nullptr
    && (v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v21, a3: "targets"),
        (pComboOp = FindReferringElement<CDmeCombinationOperator>(
                      pElement: m_pMesh,
                      symAttrName: (CUtlSymbolLarge)v5->u.m_Id,
                      bMustBeInSameFile: true,
                      depth: TD_ALL)) != nullptr) )
  {
    i = 0;
    if ( v1->m_presetCache.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      while ( 1 )
      {
        v6 = (unsigned __int16)i;
        v7 = CUtlSymbolTable::String(this: &v1->m_presetCache.m_SymbolTable, id: (CUtlSymbol)i);
        pRoot = nullptr;
        v8 = CP4Factory::AccessFile(this: g_p4factory, szFilename: v7);
        v8->Add(this: v8);
        g_pDataModel->RestoreFromFile(
          this: g_pDataModel,
          a2: v7,
          a3: nullptr,
          a4: nullptr,
          a5: &pRoot,
          a6: CR_DELETE_NEW,
          a7: nullptr);
        if ( pRoot != nullptr )
          break;
        bRetVal = false;
LABEL_17:
        m_NumElements = v1->m_presetCache.m_SymbolTable.m_Lookup.m_NumElements;
        if ( ++i >= m_NumElements )
          goto LABEL_18;
      }
      v9 = (CDmePresetGroup *)pRoot;
      if ( ((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(
             a1: pRoot,
             a2: (CUtlSymbolLarge)CDmePresetGroup::m_classType.u.m_Id) )
      {
        v10 = &v26->m_presetCache.m_Vector.m_Memory.m_pMemory[v6];
        if ( CUtlString::Length(this: v10) == 0 )
        {
          _Warning(a1: "// No expression file specified for preset %s\n", v7);
LABEL_16:
          v1 = v26;
          goto LABEL_17;
        }
        v11 = CUtlString::operator char const *(this: v10);
        V_strncpy(pDest: buf, pSrc: v11, maxLen: 260);
        V_SetExtension(path: buf, extension: ".txt", pathStringLength: 260);
        V_ExtractFilePath(path: buf, dest: buf1, destSize: 260);
        V_FixSlashes(pname: buf1, separator: 92);
        g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: buf1, a3: nullptr);
        v12 = CP4Factory::AccessFile(this: g_p4factory, szFilename: buf);
        if ( !v12->Edit(this: v12) )
        {
          v13 = CP4Factory::AccessFile(this: g_p4factory, szFilename: buf);
          v13->Add(this: v13);
        }
        v14 = pComboOp;
        CDmePresetGroup::ExportToTXT(this: v9, pFileName: buf, pAnimationSet: nullptr, pComboOp);
        V_SetExtension(path: buf, extension: ".vfe", pathStringLength: 260);
        V_ExtractFilePath(path: buf, dest: buf1, destSize: 260);
        V_FixSlashes(pname: buf1, separator: 92);
        g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: buf1, a3: nullptr);
        v15 = CP4Factory::AccessFile(this: g_p4factory, szFilename: buf);
        if ( !v15->Edit(this: v15) )
        {
          v16 = CP4Factory::AccessFile(this: g_p4factory, szFilename: buf);
          v16->Add(this: v16);
        }
        CDmePresetGroup::ExportToVFE(this: v9, pFileName: buf, pAnimationSet: nullptr, pComboOp: v14);
      }
      g_pDataModel->UnloadFile(this: g_pDataModel, a2: pRoot->m_fileId);
      goto LABEL_16;
    }
LABEL_18:
    SetUndoEnabled = g_pDataModel->SetUndoEnabled;
    v28 = -1;
    SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sgDisableUndo.m_bOldValue);
    return bRetVal;
  }
  else
  {
    v28 = -1;
    CChangeUndoScopeGuard::Release(this: &sgDisableUndo);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405000
// Name: CreateExpressionFilesFromCachedPresets_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateExpressionFilesFromCachedPresets_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  if ( !CDmxEdit::CreateExpressionFilesFromCachedPresets(this: &LuaFunc_s::m_dmxEdit) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v1);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405060
// Name: void ScaleDeltaPositions(class CDmrArrayConst<class Vector> const __near &,class CDmeVertexDeltaData __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScaleDeltaPositions(
        const CDmrArrayConst<Vector> *bindPosData,
        CDmeVertexDeltaData *pDelta,
        float sx,
        float sy,
        float sz)
{
  int v5; // eax
  CDmAttribute *m_pVertexData; // esi
  int m_Size; // esi
  void *v8; // esp
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // esi
  float *p_pPosArray; // eax
  char *v13; // edx
  Vector *m_pMemory; // ecx
  Vector *v15; // ecx
  char *v16; // ecx
  char *v17; // ecx
  float *v18; // ecx
  int v19; // edi
  char *v20; // eax
  Vector v21; // [esp+0h] [ebp-20h] BYREF
  CDmrArray<Vector> posData; // [esp+Ch] [ebp-14h] BYREF
  Vector *pPosArray; // [esp+14h] [ebp-Ch] BYREF
  int j; // [esp+18h] [ebp-8h]
  int nPosDataCount; // [esp+1Ch] [ebp-4h]

  v5 = pDelta->m_pStandardFieldIndex[0];
  if ( v5 >= 0 )
  {
    m_pVertexData = pDelta->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&posData);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&posData,
      pAttribute: m_pVertexData);
    m_Size = posData.m_pStorage->m_Size;
    nPosDataCount = m_Size;
    if ( m_Size > 0 )
    {
      v8 = alloca(12 * m_Size);
      v9 = 0;
      if ( m_Size >= 4 )
      {
        v10 = -20 - (_DWORD)&v21;
        v11 = ((unsigned int)(m_Size - 4) >> 2) + 1;
        p_pPosArray = (float *)&pPosArray;
        j = 4 * v11;
        while ( 1 )
        {
          v13 = (char *)p_pPosArray + v10;
          m_pMemory = posData.m_pStorage->m_Memory.m_pMemory;
          *(p_pPosArray - 5) = *(float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory->x + (unsigned int)v13) * sx;
          *(p_pPosArray - 4) = *(float *)&v13[(_DWORD)m_pMemory + 4] * sy;
          *(p_pPosArray - 3) = *(float *)&v13[(_DWORD)m_pMemory + 8] * sz;
          v15 = posData.m_pStorage->m_Memory.m_pMemory;
          *(p_pPosArray - 2) = *(float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory[1].x + (unsigned int)v13) * sx;
          *(p_pPosArray - 1) = *(float *)&v13[(_DWORD)v15 + 16] * sy;
          *p_pPosArray = *(float *)&v13[(_DWORD)v15 + 20] * sz;
          v16 = (char *)posData.m_pStorage->m_Memory.m_pMemory + 4 - (_DWORD)&v21;
          p_pPosArray[1] = *(float *)((char *)p_pPosArray + (_DWORD)v16) * sx;
          p_pPosArray[2] = *(float *)((char *)p_pPosArray + (_DWORD)v16 + 4) * sy;
          p_pPosArray[3] = *(float *)((char *)p_pPosArray + (_DWORD)v16 + 8) * sz;
          v17 = (char *)posData.m_pStorage->m_Memory.m_pMemory + 16 - (_DWORD)&v21;
          p_pPosArray[4] = *(float *)((char *)p_pPosArray + (_DWORD)v17) * sx;
          p_pPosArray[5] = *(float *)((char *)p_pPosArray + (_DWORD)v17 + 4) * sy;
          p_pPosArray[6] = *(float *)((char *)p_pPosArray + (_DWORD)v17 + 8) * sz;
          p_pPosArray += 12;
          if ( --v11 == 0 )
            break;
          v10 = -20 - (_DWORD)&v21;
        }
        m_Size = nPosDataCount;
        v9 = j;
      }
      if ( v9 < m_Size )
      {
        v18 = &v21.z + 3 * v9;
        v19 = m_Size - v9;
        do
        {
          v20 = (char *)posData.m_pStorage->m_Memory.m_pMemory - 8 - (_DWORD)&v21;
          *(v18 - 2) = *(float *)((char *)v18 + (_DWORD)v20) * sx;
          *(v18 - 1) = *(float *)((char *)v18 + (_DWORD)v20 + 4) * sy;
          *v18 = *(float *)((char *)v18 + (_DWORD)v20 + 8) * sz;
          v18 += 3;
          --v19;
        }
        while ( v19 != 0 );
      }
      CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::SetMultiple(
        this: &posData,
        i: 0,
        nCount: m_Size,
        pValue: &v21);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405250
// Name: public: bool CDmxEdit::Scale(float,float,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Scale(CDmxEdit *this, float sx, float sy, float sz)
{
  CDmxEdit *v4; // ebx
  int m_Size; // eax
  Vector *v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  int v9; // eax
  const CDmAttribute *v10; // esi
  int v11; // ebx
  void *v12; // esp
  int v13; // eax
  float *p_z; // eax
  int v15; // edx
  unsigned int v16; // edi
  Vector *m_pMemory; // ecx
  int v18; // esi
  Vector *v19; // ecx
  float *v20; // ecx
  float *v21; // ecx
  int v22; // ecx
  int v23; // esi
  int v24; // edx
  float *v25; // eax
  CDmeVertexData *BindBaseState; // eax
  int v27; // ecx
  const CDmAttribute *m_pVertexData; // esi
  int v29; // ebx
  int k; // esi
  CDmeVertexDeltaData *DeltaState; // eax
  _BYTE v33[12]; // [esp+14h] [ebp-2Ch] BYREF
  CDmrArrayConst<Vector> posData; // [esp+20h] [ebp-20h] BYREF
  int nBaseStateCount; // [esp+28h] [ebp-18h]
  int j; // [esp+2Ch] [ebp-14h]
  int nArraySize; // [esp+30h] [ebp-10h]
  CDmxEdit *v38; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  Vector *pPosArray; // [esp+3Ch] [ebp-4h]

  v4 = this;
  m_Size = this->m_pMesh->m_BaseStates.m_Storage.m_Size;
  v6 = nullptr;
  v38 = this;
  nArraySize = 0;
  pPosArray = nullptr;
  nBaseStateCount = m_Size;
  for ( i = 0; i < nBaseStateCount; ++i )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_pMesh->m_BaseStates.m_Storage.m_Memory.m_pMemory[i]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeVertexData::m_classType) )
      v8 = nullptr;
    v9 = *((_DWORD *)&v8[1] + 15);
    if ( v9 < 0 )
      continue;
    v10 = *(const CDmAttribute **)(v8[1].m_ref.m_attributes.m_hAttribute + 48 * v9 + 16);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&posData);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &posData,
      pAttribute: v10);
    v11 = posData.m_pStorage->m_Size;
    if ( v11 > 0 )
    {
      if ( nArraySize < v11 || v6 == nullptr )
      {
        v12 = alloca(12 * v11);
        pPosArray = (Vector *)v33;
        v6 = (Vector *)v33;
        if ( v33 != nullptr )
        {
          nArraySize = v11;
LABEL_12:
          v13 = 0;
          if ( v11 >= 4 )
          {
            p_z = &v6[1].z;
            v15 = -(int)v6;
            v16 = ((unsigned int)(v11 - 4) >> 2) + 1;
            j = 4 * v16;
            do
            {
              m_pMemory = posData.m_pStorage->m_Memory.m_pMemory;
              v18 = (int)p_z + v15 - 20;
              *(p_z - 5) = *(float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory->x + v18) * sx;
              *(p_z - 4) = *(float *)((char *)&m_pMemory->y + v18) * sy;
              *(p_z - 3) = *(float *)((char *)&m_pMemory->z + v18) * sz;
              v19 = posData.m_pStorage->m_Memory.m_pMemory;
              *(p_z - 2) = *(float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory[1].x + v18) * sx;
              *(p_z - 1) = *(float *)((char *)&v19[1].y + v18) * sy;
              *p_z = *(float *)((char *)&v19->x + (_DWORD)p_z + v15) * sz;
              v20 = (float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory->x + (unsigned int)p_z + v15 + 4);
              p_z[1] = *v20 * sx;
              p_z[2] = v20[1] * sy;
              p_z[3] = v20[2] * sz;
              v21 = (float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory->x + (unsigned int)p_z + v15 + 16);
              p_z += 12;
              --v16;
              *(p_z - 8) = *v21 * sx;
              *(p_z - 7) = v21[1] * sy;
              *(p_z - 6) = v21[2] * sz;
            }
            while ( v16 != 0 );
            v6 = pPosArray;
            v13 = j;
          }
          if ( v13 < v11 )
          {
            v22 = (int)&v6[v13].z;
            v23 = -8 - (_DWORD)pPosArray;
            v24 = v11 - v13;
            do
            {
              v25 = (float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory->x + v22 + v23);
              v22 += 12;
              --v24;
              *(float *)(v22 - 20) = *v25 * sx;
              *(float *)(v22 - 16) = v25[1] * sy;
              *(float *)(v22 - 12) = v25[2] * sz;
            }
            while ( v24 != 0 );
            v6 = pPosArray;
          }
          CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::SetMultiple(
            this: (CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *)&posData,
            i: 0,
            nCount: v11,
            pValue: v6);
          goto LABEL_21;
        }
      }
      if ( nArraySize >= v11 )
        goto LABEL_12;
    }
LABEL_21:
    v4 = v38;
  }
  BindBaseState = CDmeMesh::GetBindBaseState(this: v4->m_pMesh);
  if ( BindBaseState != nullptr )
    v27 = BindBaseState->m_pStandardFieldIndex[0];
  else
    v27 = -1;
  if ( BindBaseState != nullptr && v27 >= 0 )
  {
    m_pVertexData = BindBaseState->m_FieldInfo.m_Memory.m_pMemory[v27].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&posData);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &posData,
      pAttribute: m_pVertexData);
    v29 = CDmeMesh::DeltaStateCount(this: v4->m_pMesh);
    for ( k = 0; k < v29; ++k )
    {
      DeltaState = CDmeMesh::GetDeltaState(this: v38->m_pMesh, nDeltaIndex: k);
      ScaleDeltaPositions(bindPosData: &posData, pDelta: DeltaState, sx, sy, sz);
    }
    return 1;
  }
  else
  {
    _Warning(a1: "// Can't Scale Deltas!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405560
// Name: Scale_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Scale_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  float sx; // [esp+10h] [ebp-Ch]
  float sy; // [esp+14h] [ebp-8h]
  float sz; // [esp+18h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  sx = luaL_checknumber(L: pLuaState, narg: 1);
  sy = sx;
  sz = sx;
  if ( lua_isnumber(L: pLuaState, idx: 2) != 0 && lua_isnumber(L: pLuaState, idx: 3) != 0 )
  {
    sy = lua_tonumber(L: pLuaState, idx: 2);
    sz = lua_tonumber(L: pLuaState, idx: 3);
  }
  if ( CDmxEdit::Scale(this: &LuaFunc_s::m_dmxEdit, sx, sy, sz) == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v1);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405630
// Name: public: bool CDmxEdit::Translate(class Vector,float,class CDmxEdit::CFalloffType const __near &,class CDmxEdit::CDistanceType const __near &,class CDmeMesh __near *,class CDmeVertexData __near *,class CDmeSingleIndexedComponent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::Translate(
        CDmxEdit *this,
        Vector t,
        float featherDistance,
        const CDmxEdit::CFalloffType *falloffType,
        int passedDistanceType,
        CDmeMesh *pPassedMesh,
        CDmeVertexData *pPassedBase,
        int pPassedSelection)
{
  CDmxEdit::CDistanceType *p_m_distanceType; // eax
  CDmeVertexData *CurrentBaseState; // eax
  CDmeSingleIndexedComponent *v12; // ebx
  DmElementHandle_t v13; // eax
  CDmElement *v14; // eax
  CDmxEdit::CDistanceType *v15; // esi
  int v16; // eax
  CDmAttribute *m_pVertexData; // esi
  int m_Size; // edi
  void *v19; // esp
  float x; // xmm0_4
  int v21; // edi
  int v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  int v25; // eax
  int v26; // edx
  unsigned int v27; // edi
  float *p_z; // eax
  char *v29; // edx
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  char *v34; // ecx
  float v35; // xmm1_4
  float v36; // xmm2_4
  char *v37; // ecx
  float v38; // xmm1_4
  float v39; // xmm2_4
  float *v40; // ecx
  int v41; // edx
  char *v42; // eax
  float v43; // xmm1_4
  float v44; // xmm2_4
  Vector v45; // [esp+2Ch] [ebp-28h] BYREF
  Vector vCenter; // [esp+38h] [ebp-1Ch] BYREF
  CDmrArray<Vector> posData; // [esp+44h] [ebp-10h] BYREF
  CDmeVertexData *pBase; // [esp+4Ch] [ebp-8h]
  CDmeMesh::Distance_t *v49; // [esp+50h] [ebp-4h]

  p_m_distanceType = (CDmxEdit::CDistanceType *)passedDistanceType;
  if ( *(_DWORD *)passedDistanceType == 2 )
    p_m_distanceType = &this->m_distanceType;
  v49 = &p_m_distanceType->m_distanceType;
  if ( *(float *)&pPassedMesh == 0.0 )
    pPassedMesh = this->m_pMesh;
  if ( this->m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  CurrentBaseState = pPassedBase;
  if ( pPassedBase == nullptr )
    CurrentBaseState = CDmeMesh::GetCurrentBaseState(this: pPassedMesh);
  v12 = (CDmeSingleIndexedComponent *)pPassedSelection;
  pBase = CurrentBaseState;
  if ( pPassedSelection != 0 )
  {
    passedDistanceType = pPassedSelection;
  }
  else
  {
    passedDistanceType = (int)this->m_pCurrentSelection;
    v12 = (CDmeSingleIndexedComponent *)passedDistanceType;
  }
  if ( v12 == nullptr || v12->Count(this: v12) == 0 )
  {
    v13 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeSingleIndexedComponent::m_classType.u.m_Id,
            a3: "__selectAll",
            a4: DMFILEID_INVALID,
            a5: nullptr);
    v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13);
    v15 = (CDmxEdit::CDistanceType *)v14;
    if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmeSingleIndexedComponent::m_classType) )
      v15 = nullptr;
    passedDistanceType = (int)v15;
    CDmeMesh::SelectAllVertices(this: pPassedMesh, pSelection: (CDmeSingleIndexedComponent *)v15, pPassedBase: nullptr);
    v12 = (CDmeSingleIndexedComponent *)v15;
  }
  if ( v12 != nullptr && featherDistance > 0.0 )
    v12 = CDmeMesh::FeatherSelection(
            this: this->m_pMesh,
            falloffDistance: featherDistance,
            falloffType: falloffType->m_falloffType,
            distanceType: *v49,
            pSelection: v12,
            pPassedMeshComp: nullptr);
  v16 = pBase->m_pStandardFieldIndex[0];
  if ( v16 < 0 )
    return false;
  m_pVertexData = pBase->m_FieldInfo.m_Memory.m_pMemory[v16].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&posData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&posData,
    pAttribute: m_pVertexData);
  m_Size = posData.m_pStorage->m_Size;
  pPassedBase = (CDmeVertexData *)m_Size;
  if ( m_Size <= 0 )
    return false;
  pPassedSelection = 12 * m_Size;
  v19 = alloca(12 * m_Size);
  if ( &v45 == nullptr )
    return false;
  if ( *v49 == DIST_RELATIVE )
  {
    CDmeMesh::GetBoundingSphere(
      this: pPassedMesh,
      c: &vCenter,
      r: (float *)&passedDistanceType,
      pPassedBase: pBase,
      pPassedSelection: (CDmeSingleIndexedComponent *)passedDistanceType);
    t.y = t.y * *(float *)&passedDistanceType;
    x = t.x * *(float *)&passedDistanceType;
    t.x = t.x * *(float *)&passedDistanceType;
    t.z = t.z * *(float *)&passedDistanceType;
  }
  else
  {
    x = t.x;
  }
  if ( v12 != nullptr )
  {
    memcpy(
      dst: (unsigned __int8 *)&v45,
      src: (unsigned __int8 *)posData.m_pStorage->m_Memory.m_pMemory,
      count: pPassedSelection);
    v21 = 0;
    pPassedSelection = v12->Count(this: v12);
    if ( pPassedSelection > 0 )
    {
      do
      {
        CDmeSingleIndexedComponent::GetComponent(
          this: v12,
          index: v21,
          component: &passedDistanceType,
          weight: (float *)&pPassedMesh);
        v22 = 12 * passedDistanceType;
        v23 = posData.m_pStorage->m_Memory.m_pMemory[passedDistanceType].y + (float)(t.y * *(float *)&pPassedMesh);
        ++v21;
        v24 = posData.m_pStorage->m_Memory.m_pMemory[passedDistanceType].z + (float)(t.z * *(float *)&pPassedMesh);
        *(float *)((char *)&v45.x + v22) = posData.m_pStorage->m_Memory.m_pMemory[passedDistanceType].x
                                         + (float)(t.x * *(float *)&pPassedMesh);
        *(float *)((char *)&v45.y + v22) = v23;
        *(float *)((char *)&v45.z + v22) = v24;
      }
      while ( v21 < pPassedSelection );
    }
    m_Size = (int)pPassedBase;
  }
  else
  {
    v25 = 0;
    if ( m_Size >= 4 )
    {
      v26 = -20 - (_DWORD)&v45;
      v27 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      pPassedMesh = (CDmeMesh *)(16 - (_DWORD)&v45);
      p_z = &vCenter.z;
      passedDistanceType = -20 - (_DWORD)&v45;
      pPassedSelection = 4 * v27;
      while ( 1 )
      {
        v29 = (char *)p_z + v26;
        v30 = *(float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory->y + (unsigned int)v29) + t.y;
        v31 = *(float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory->z + (unsigned int)v29) + t.z;
        *(p_z - 5) = x + *(float *)((char *)&posData.m_pStorage->m_Memory.m_pMemory->x + (unsigned int)v29);
        *(p_z - 4) = v30;
        *(p_z - 3) = v31;
        v32 = *(float *)&v29[(unsigned int)posData.m_pStorage->m_Memory.m_pMemory + 16] + t.y;
        v33 = *(float *)&v29[(unsigned int)posData.m_pStorage->m_Memory.m_pMemory + 20] + t.z;
        *(p_z - 2) = t.x + *(float *)&v29[(unsigned int)posData.m_pStorage->m_Memory.m_pMemory + 12];
        *(p_z - 1) = v32;
        *p_z = v33;
        v34 = (char *)posData.m_pStorage->m_Memory.m_pMemory + 4 - (_DWORD)&v45;
        v35 = *(float *)((char *)p_z + (_DWORD)v34 + 4) + t.y;
        v36 = *(float *)((char *)p_z + (_DWORD)v34 + 8) + t.z;
        p_z[1] = t.x + *(float *)((char *)p_z + (_DWORD)v34);
        p_z[2] = v35;
        p_z[3] = v36;
        v37 = (char *)pPassedMesh + (unsigned int)posData.m_pStorage->m_Memory.m_pMemory;
        v38 = *(float *)((char *)p_z + (_DWORD)v37 + 4) + t.y;
        v39 = *(float *)((char *)p_z + (_DWORD)v37 + 8) + t.z;
        p_z[4] = t.x + *(float *)((char *)p_z + (_DWORD)v37);
        p_z[5] = v38;
        p_z[6] = v39;
        x = t.x;
        p_z += 12;
        if ( --v27 == 0 )
          break;
        v26 = passedDistanceType;
      }
      v25 = pPassedSelection;
      m_Size = (int)pPassedBase;
    }
    if ( v25 < m_Size )
    {
      v40 = &v45.z + 3 * v25;
      v41 = m_Size - v25;
      while ( 1 )
      {
        v42 = (char *)posData.m_pStorage->m_Memory.m_pMemory - 8 - (_DWORD)&v45;
        v43 = *(float *)((char *)v40 + (_DWORD)v42 + 4) + t.y;
        v44 = *(float *)((char *)v40 + (_DWORD)v42 + 8) + t.z;
        *(v40 - 2) = x + *(float *)((char *)v40 + (_DWORD)v42);
        *(v40 - 1) = v43;
        *v40 = v44;
        v40 += 3;
        if ( --v41 == 0 )
          break;
        x = t.x;
      }
    }
  }
  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::SetMultiple(
    this: &posData,
    i: 0,
    nCount: m_Size,
    pValue: &v45);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00405A40
// Name: Translate_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Translate_luaFunc(lua_State *pLuaState)
{
  float v1; // ecx
  unsigned __int64 v2; // xmm0_8
  const char *v3; // eax
  const char *v5; // edi
  const char *v6; // eax
  double v7; // xmm0_8
  char v8; // al
  int v9; // eax
  CDmeMesh::Falloff_t v10; // eax
  Vector v11; // [esp-Ch] [ebp-58h]
  float featherDistance; // [esp+0h] [ebp-4Ch]
  CDmxEdit::CFalloffType *v13; // [esp+4h] [ebp-48h]
  CDmxEdit::CDistanceType *v14; // [esp+8h] [ebp-44h]
  unsigned __int64 v15; // [esp+20h] [ebp-2Ch]
  float v16; // [esp+28h] [ebp-24h]
  _BYTE v17[12]; // [esp+2Ch] [ebp-20h] BYREF
  float flFeatherDistance; // [esp+38h] [ebp-14h]
  CDmxEdit::CFalloffType v19; // [esp+3Ch] [ebp-10h] BYREF
  float tz; // [esp+40h] [ebp-Ch]
  float ty; // [esp+44h] [ebp-8h]
  float tx; // [esp+48h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  tx = luaL_checknumber(L: pLuaState, narg: 1);
  ty = luaL_checknumber(L: pLuaState, narg: 2);
  tz = luaL_checknumber(L: pLuaState, narg: 3);
  if ( lua_gettop(L: pLuaState) < 4 )
  {
    *(_QWORD *)v17 = __PAIR64__(LODWORD(ty), LODWORD(tx));
    v14 = &CDmxEdit::DIST_DEFAULT;
    *(float *)&v17[8] = tz;
    v1 = tz;
    v13 = &CDmxEdit::STRAIGHT;
    featherDistance = 0.0;
    v2 = __PAIR64__(LODWORD(ty), LODWORD(tx));
    goto LABEL_3;
  }
  flFeatherDistance = 0.0;
  v5 = "STRAIGHT";
  if ( lua_gettop(L: pLuaState) == 4 && lua_isstring(L: pLuaState, idx: 4) != 0 )
  {
    v6 = lua_tolstring(L: pLuaState, idx: 4, len: nullptr);
  }
  else
  {
    if ( lua_isnumber(L: pLuaState, idx: 4) != 0 )
    {
      *(double *)&v17[4] = lua_tonumber(L: pLuaState, idx: 4);
      v7 = *(double *)&v17[4];
    }
    else
    {
      v7 = 0.0;
    }
    flFeatherDistance = v7;
    if ( lua_isstring(L: pLuaState, idx: 5) != 0 )
      v5 = lua_tolstring(L: pLuaState, idx: 5, len: nullptr);
    if ( lua_isstring(L: pLuaState, idx: 6) == 0 )
      goto LABEL_22;
    v6 = lua_tolstring(L: pLuaState, idx: 6, len: nullptr);
  }
  if ( v6 == nullptr )
  {
LABEL_22:
    v9 = 2;
    goto LABEL_23;
  }
  v8 = *v6;
  if ( v8 != 97 && v8 != 65 )
  {
    if ( v8 == 114 || v8 == 82 )
    {
      v9 = 1;
      goto LABEL_23;
    }
    goto LABEL_22;
  }
  v9 = 0;
LABEL_23:
  *(_DWORD *)&v17[8] = v9;
  v10 = CDmxEdit::CFalloffType::StringToFalloff(this: &v19, pFalloffTypeString: v5);
  v15 = __PAIR64__(LODWORD(ty), LODWORD(tx));
  v19.m_falloffType = v10;
  v14 = (CDmxEdit::CDistanceType *)&v17[8];
  v16 = tz;
  v1 = tz;
  v13 = &v19;
  featherDistance = flFeatherDistance;
  v2 = __PAIR64__(LODWORD(ty), LODWORD(tx));
LABEL_3:
  *(_QWORD *)&v11.x = v2;
  v11.z = v1;
  if ( !CDmxEdit::Translate(
          this: &LuaFunc_s::m_dmxEdit,
          t: v11,
          featherDistance,
          falloffType: v13,
          passedDistanceType: (int)v14,
          pPassedMesh: nullptr,
          pPassedBase: nullptr,
          pPassedSelection: 0) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v3 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v3);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405C40
// Name: public: bool CDmxEdit::Rotate(class Vector,class Vector,float,class CDmxEdit::CFalloffType const __near &,class CDmxEdit::CDistanceType const __near &,class CDmeMesh __near *,class CDmeVertexData __near *,class CDmeSingleIndexedComponent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::Rotate(
        CDmxEdit *this,
        Vector r,
        Vector o,
        float featherDistance,
        const CDmxEdit::CFalloffType *falloffType,
        int passedDistanceType,
        CDmeMesh *pPassedMesh,
        CDmeVertexData *pPassedBase,
        CDmeSingleIndexedComponent *pPassedSelection)
{
  CDmxEdit::CDistanceType *p_m_distanceType; // eax
  CDmeMesh *v11; // ebx
  CDmeVertexData *CurrentBaseState; // eax
  CDmeSingleIndexedComponent *v14; // esi
  DmElementHandle_t v15; // eax
  CDmElement *v16; // eax
  int v17; // eax
  CDmAttribute *m_pVertexData; // edi
  int m_Size; // edi
  void *v20; // esp
  int v21; // edi
  Vector *m_pMemory; // esi
  const float *p_x; // esi
  CDmeMesh *v24; // esi
  int v25; // edi
  Vector v26; // [esp+2Ch] [ebp-C8h] BYREF
  matrix3x4_t rpiMat; // [esp+38h] [ebp-BCh] BYREF
  matrix3x4_t rpMat; // [esp+68h] [ebp-8Ch] BYREF
  matrix3x4_t rMat; // [esp+98h] [ebp-5Ch] BYREF
  float fRadius; // [esp+C8h] [ebp-2Ch] BYREF
  CDmrArray<Vector> posData; // [esp+CCh] [ebp-28h] BYREF
  Vector vCenter; // [esp+D4h] [ebp-20h] BYREF
  CDmeMesh *pMesh; // [esp+E0h] [ebp-14h]
  Vector in; // [esp+E4h] [ebp-10h] BYREF
  CDmeMesh::Distance_t *v35; // [esp+F0h] [ebp-4h]
  Vector *d; // [esp+114h] [ebp+20h]
  int nSelectionCount; // [esp+118h] [ebp+24h]

  p_m_distanceType = (CDmxEdit::CDistanceType *)passedDistanceType;
  if ( *(_DWORD *)passedDistanceType == 2 )
    p_m_distanceType = &this->m_distanceType;
  v35 = &p_m_distanceType->m_distanceType;
  if ( pPassedMesh != nullptr )
  {
    v11 = pPassedMesh;
    pMesh = pPassedMesh;
  }
  else
  {
    pMesh = this->m_pMesh;
    v11 = pMesh;
  }
  if ( this->m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  CurrentBaseState = pPassedBase;
  if ( *(float *)&pPassedBase == 0.0 )
    CurrentBaseState = CDmeMesh::GetCurrentBaseState(this: v11);
  v14 = pPassedSelection;
  pPassedBase = CurrentBaseState;
  if ( pPassedSelection != nullptr )
  {
    passedDistanceType = (int)pPassedSelection;
  }
  else
  {
    passedDistanceType = (int)this->m_pCurrentSelection;
    v14 = (CDmeSingleIndexedComponent *)passedDistanceType;
  }
  if ( v14 == nullptr || v14->Count(this: v14) == 0 )
  {
    v15 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeSingleIndexedComponent::m_classType.u.m_Id,
            a3: "__selectAll",
            a4: DMFILEID_INVALID,
            a5: nullptr);
    v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: v15);
    v14 = (CDmeSingleIndexedComponent *)v16;
    if ( v16 == nullptr || !v16->IsA(this: v16, a2: CDmeSingleIndexedComponent::m_classType) )
      v14 = nullptr;
    passedDistanceType = (int)v14;
    CDmeMesh::SelectAllVertices(this: v11, pSelection: v14, pPassedBase: nullptr);
  }
  if ( v14 != nullptr && featherDistance > 0.0 )
  {
    v14 = CDmeMesh::FeatherSelection(
            this: this->m_pMesh,
            falloffDistance: featherDistance,
            falloffType: falloffType->m_falloffType,
            distanceType: *v35,
            pSelection: v14,
            pPassedMeshComp: nullptr);
    pPassedSelection = v14;
  }
  else
  {
    pPassedSelection = v14;
  }
  v17 = pPassedBase->m_pStandardFieldIndex[0];
  if ( v17 < 0 )
    return false;
  m_pVertexData = pPassedBase->m_FieldInfo.m_Memory.m_pMemory[v17].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&posData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&posData,
    pAttribute: m_pVertexData);
  m_Size = posData.m_pStorage->m_Size;
  pPassedMesh = (CDmeMesh *)m_Size;
  if ( m_Size <= 0 )
    return false;
  v20 = alloca(12 * m_Size);
  if ( &v26 == nullptr )
    return false;
  CDmeMesh::GetBoundingSphere(
    this: pMesh,
    c: &vCenter,
    r: &fRadius,
    pPassedBase,
    pPassedSelection: (CDmeSingleIndexedComponent *)passedDistanceType);
  if ( *v35 == DIST_RELATIVE )
  {
    r.x = r.x * fRadius;
    r.y = r.y * fRadius;
    r.z = r.z * fRadius;
  }
  vCenter.x = o.x + vCenter.x;
  vCenter.y = vCenter.y + o.y;
  vCenter.z = vCenter.z + o.z;
  SetIdentityMatrix(matrix: &rpMat);
  MatrixSetColumn(in: &vCenter, column: 3, out: &rpMat);
  SetIdentityMatrix(matrix: &rpiMat);
  in.x = -vCenter.x;
  in.y = -vCenter.y;
  in.z = -vCenter.z;
  MatrixSetColumn(&in, column: 3, out: &rpiMat);
  SetIdentityMatrix(matrix: &rMat);
  if ( v14 != nullptr )
  {
    memcpy(
      dst: (unsigned __int8 *)&v26,
      src: (unsigned __int8 *)posData.m_pStorage->m_Memory.m_pMemory,
      count: 12 * m_Size);
    v21 = 0;
    nSelectionCount = v14->Count(this: v14);
    if ( nSelectionCount > 0 )
    {
      while ( 1 )
      {
        CDmeSingleIndexedComponent::GetComponent(
          this: v14,
          index: v21,
          component: &passedDistanceType,
          weight: (float *)&pPassedBase);
        m_pMemory = posData.m_pStorage->m_Memory.m_pMemory;
        in.x = (float)(r.x * *(float *)&pPassedBase) * 0.017453292;
        p_x = &m_pMemory[passedDistanceType].x;
        d = &v26 + passedDistanceType;
        in.y = (float)(r.y * *(float *)&pPassedBase) * 0.017453292;
        in.z = (float)(r.z * *(float *)&pPassedBase) * 0.017453292;
        AngleMatrix(angles: (const RadianEuler *)&in, matrix: &rMat);
        ConcatTransforms(in1: &rpMat, in2: &rMat, out: &rMat);
        ConcatTransforms(in1: &rMat, in2: &rpiMat, out: &rMat);
        VectorTransform(in1: p_x, in2: &rMat, out: &d->x);
        if ( ++v21 >= nSelectionCount )
          break;
        v14 = pPassedSelection;
      }
    }
  }
  else
  {
    in.x = r.x * 0.017453292;
    in.y = r.y * 0.017453292;
    in.z = r.z * 0.017453292;
    AngleMatrix(angles: (const RadianEuler *)&in, matrix: &rMat);
    ConcatTransforms(in1: &rpMat, in2: &rMat, out: &rMat);
    ConcatTransforms(in1: &rMat, in2: &rpiMat, out: &rMat);
    v24 = pPassedMesh;
    v25 = 0;
    do
    {
      VectorTransform(
        in1: &posData.m_pStorage->m_Memory.m_pMemory[v25].x,
        in2: &rMat,
        out: (float *)((char *)&v26.x + v25 * 12));
      ++v25;
      v24 = (CDmeMesh *)((char *)v24 - 1);
    }
    while ( v24 != nullptr );
  }
  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::SetMultiple(
    this: &posData,
    i: 0,
    nCount: (int)pPassedMesh,
    pValue: &v26);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00406060
// Name: Rotate_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Rotate_luaFunc(lua_State *pLuaState)
{
  float v1; // ecx
  float v2; // edx
  unsigned __int64 v3; // xmm0_8
  bool v4; // al
  const char *v5; // eax
  const char *v7; // edi
  double v8; // xmm0_8
  const char *v9; // eax
  char v10; // al
  int v11; // eax
  Vector v12; // [esp-18h] [ebp-7Ch]
  Vector v13; // [esp-18h] [ebp-7Ch]
  Vector v14; // [esp-Ch] [ebp-70h]
  Vector v15; // [esp-Ch] [ebp-70h]
  float flFeatherDistance; // [esp+40h] [ebp-24h]
  int v17; // [esp+44h] [ebp-20h] BYREF
  CDmxEdit::CFalloffType v18; // [esp+48h] [ebp-1Ch] BYREF
  float oz; // [esp+4Ch] [ebp-18h]
  float oy; // [esp+50h] [ebp-14h]
  float ox; // [esp+54h] [ebp-10h]
  float rz; // [esp+58h] [ebp-Ch]
  float ry; // [esp+5Ch] [ebp-8h]
  float rx; // [esp+60h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  rx = luaL_checknumber(L: pLuaState, narg: 1);
  ry = luaL_checknumber(L: pLuaState, narg: 2);
  rz = luaL_checknumber(L: pLuaState, narg: 3);
  if ( lua_gettop(L: pLuaState) < 4 )
  {
    v1 = 0.0;
    v2 = rz;
    *(_QWORD *)&v14.x = 0;
    v3 = __PAIR64__(LODWORD(ry), LODWORD(rx));
LABEL_3:
    v14.z = v1;
    *(_QWORD *)&v12.x = v3;
    v12.z = v2;
    v4 = CDmxEdit::Rotate(
           this: &LuaFunc_s::m_dmxEdit,
           r: v12,
           o: v14,
           featherDistance: 0.0,
           falloffType: &CDmxEdit::STRAIGHT,
           passedDistanceType: (int)&CDmxEdit::DIST_DEFAULT,
           pPassedMesh: nullptr,
           pPassedBase: nullptr,
           pPassedSelection: nullptr);
    goto LABEL_4;
  }
  ox = luaL_checknumber(L: pLuaState, narg: 4);
  oy = luaL_checknumber(L: pLuaState, narg: 5);
  oz = luaL_checknumber(L: pLuaState, narg: 6);
  if ( lua_gettop(L: pLuaState) < 7 )
  {
    v1 = oz;
    v2 = rz;
    *(_QWORD *)&v14.x = __PAIR64__(LODWORD(oy), LODWORD(ox));
    v3 = __PAIR64__(LODWORD(ry), LODWORD(rx));
    goto LABEL_3;
  }
  v7 = "STRAIGHT";
  if ( lua_isnumber(L: pLuaState, idx: 7) != 0 )
    v8 = lua_tonumber(L: pLuaState, idx: 7);
  else
    v8 = 0.0;
  if ( lua_isstring(L: pLuaState, idx: 8) != 0 )
    v7 = lua_tolstring(L: pLuaState, idx: 8, len: nullptr);
  if ( lua_isstring(L: pLuaState, idx: 9) == 0 )
    goto LABEL_21;
  v9 = lua_tolstring(L: pLuaState, idx: 9, len: nullptr);
  if ( v9 == nullptr )
    goto LABEL_21;
  v10 = *v9;
  if ( v10 != 97 && v10 != 65 )
  {
    if ( v10 == 114 || v10 == 82 )
    {
      v11 = 1;
      goto LABEL_22;
    }
LABEL_21:
    v11 = 2;
    goto LABEL_22;
  }
  v11 = 0;
LABEL_22:
  v17 = v11;
  v18.m_falloffType = CDmxEdit::CFalloffType::StringToFalloff(this: &v18, pFalloffTypeString: v7);
  *(_QWORD *)&v15.x = __PAIR64__(LODWORD(oy), LODWORD(ox));
  v15.z = oz;
  *(_QWORD *)&v13.x = __PAIR64__(LODWORD(ry), LODWORD(rx));
  v13.z = rz;
  flFeatherDistance = v8;
  v4 = CDmxEdit::Rotate(
         this: &LuaFunc_s::m_dmxEdit,
         r: v13,
         o: v15,
         featherDistance: flFeatherDistance,
         falloffType: &v18,
         passedDistanceType: (int)&v17,
         pPassedMesh: nullptr,
         pPassedBase: nullptr,
         pPassedSelection: nullptr);
LABEL_4:
  if ( !v4 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v5 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v5);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406330
// Name: public: bool CDmxEdit::SetStereoControl(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::SetStereoControl(CDmxEdit *this, const char *pControlName, bool bStereo)
{
  CDmeMesh *m_pMesh; // esi
  CUtlSymbolLarge *v6; // eax
  CDmeCombinationOperator *Referring; // eax
  CDmeCombinationOperator *v8; // esi
  const char *v9; // eax
  int ControlIndex; // eax
  const char *m_pAsString; // eax
  const char *v12; // ecx
  _BYTE v13[4]; // [esp+Ch] [ebp-4h] BYREF

  m_pMesh = this->m_pMesh;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v6 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v13, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: m_pMesh,
                symAttrName: (CUtlSymbolLarge)v6->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  v8 = Referring;
  if ( Referring != nullptr )
  {
    ControlIndex = CDmeCombinationOperator::FindControlIndex(this: Referring, pControlName);
    if ( ControlIndex >= 0 )
    {
      CDmeCombinationOperator::SetStereoControl(this: v8, nControlIndex: ControlIndex, bIsStereo: bStereo);
      return 1;
    }
    else
    {
      m_pAsString = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      v12 = v8->m_Name.m_Storage.u.m_pAsString;
      if ( v12 == (const char *)-1 )
        v12 = var;
      return CDmxEdit::SetErrorString(
               this,
               pFormat: "No Control Named \"%s\" On DmeCombinationOperator \"%s\" On Mesh \"%s\"",
               pControlName,
               v12,
               m_pAsString);
    }
  }
  else
  {
    v9 = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( v9 == (const char *)-1 )
      v9 = var;
    return CDmxEdit::SetErrorString(this, pFormat: "No DmeCombinationOperator On Mesh \"%s\"", v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406410
// Name: SetStereoControl_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SetStereoControl_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  char v2; // al
  const char *v3; // eax
  bool bStereo; // [esp+8h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_type(L: pLuaState, idx: 2) == 1 )
  {
    bStereo = lua_toboolean(L: pLuaState, idx: 2) != 0;
    v2 = CDmxEdit::SetStereoControl(this: &LuaFunc_s::m_dmxEdit, pControlName: v1, bStereo);
  }
  else
  {
    v2 = CDmxEdit::SetStereoControl(this: &LuaFunc_s::m_dmxEdit, pControlName: v1, bStereo: true);
  }
  if ( v2 == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v3 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v3);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004064B0
// Name: public: bool CDmxEdit::SetEyelidControl(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::SetEyelidControl(CDmxEdit *this, const char *pControlName, bool bEyelid)
{
  CDmeMesh *m_pMesh; // esi
  CUtlSymbolLarge *v6; // eax
  CDmeCombinationOperator *Referring; // eax
  CDmeCombinationOperator *v8; // esi
  const char *v9; // eax
  int ControlIndex; // eax
  const char *m_pAsString; // eax
  const char *v12; // ecx
  _BYTE v13[4]; // [esp+Ch] [ebp-4h] BYREF

  m_pMesh = this->m_pMesh;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v6 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v13, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: m_pMesh,
                symAttrName: (CUtlSymbolLarge)v6->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  v8 = Referring;
  if ( Referring != nullptr )
  {
    ControlIndex = CDmeCombinationOperator::FindControlIndex(this: Referring, pControlName);
    if ( ControlIndex >= 0 )
    {
      CDmeCombinationOperator::SetEyelidControl(this: v8, nControlIndex: ControlIndex, bIsEyelid: bEyelid);
      return 1;
    }
    else
    {
      m_pAsString = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      v12 = v8->m_Name.m_Storage.u.m_pAsString;
      if ( v12 == (const char *)-1 )
        v12 = var;
      return CDmxEdit::SetErrorString(
               this,
               pFormat: "No Control Named \"%s\" On DmeCombinationOperator \"%s\" On Mesh \"%s\"",
               pControlName,
               v12,
               m_pAsString);
    }
  }
  else
  {
    v9 = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( v9 == (const char *)-1 )
      v9 = var;
    return CDmxEdit::SetErrorString(this, pFormat: "No DmeCombinationOperator On Mesh \"%s\"", v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406590
// Name: SetEyelidControl_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SetEyelidControl_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  char v2; // al
  const char *v3; // eax
  bool bStereo; // [esp+8h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_type(L: pLuaState, idx: 2) == 1 )
  {
    bStereo = lua_toboolean(L: pLuaState, idx: 2) != 0;
    v2 = CDmxEdit::SetEyelidControl(this: &LuaFunc_s::m_dmxEdit, pControlName: v1, bEyelid: bStereo);
  }
  else
  {
    v2 = CDmxEdit::SetEyelidControl(this: &LuaFunc_s::m_dmxEdit, pControlName: v1, bEyelid: true);
  }
  if ( v2 == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v3 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v3);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406630
// Name: public: bool CDmxEdit::SetWrinkleScale(char const __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::SetWrinkleScale(
        CDmxEdit *this,
        const char *pControlName,
        const char *pRawControlName,
        float flScale)
{
  CDmeMesh *m_pMesh; // esi
  CUtlSymbolLarge *v7; // eax
  CDmeCombinationOperator *Referring; // eax
  CDmeCombinationOperator *v9; // esi
  const char *m_pAsString; // eax
  int ControlIndex; // eax
  int v12; // edi
  int v13; // ebx
  const char *v14; // eax
  int v15; // ebx
  const char *RawControlName; // eax
  bool v17; // bl
  CUtlString rawControls; // [esp+18h] [ebp-24h] BYREF
  _BYTE v19[4]; // [esp+28h] [ebp-14h] BYREF
  CDmxEdit *v20; // [esp+2Ch] [ebp-10h]
  int i; // [esp+38h] [ebp-4h]

  m_pMesh = this->m_pMesh;
  v20 = this;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v7 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v19, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: m_pMesh,
                symAttrName: (CUtlSymbolLarge)v7->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  v9 = Referring;
  if ( Referring != nullptr )
  {
    ControlIndex = CDmeCombinationOperator::FindControlIndex(this: Referring, pControlName);
    v12 = ControlIndex;
    if ( ControlIndex >= 0 )
    {
      v13 = 0;
      if ( CDmeCombinationOperator::GetRawControlCount(this: v9, nControl: ControlIndex) <= 0 )
      {
LABEL_12:
        CUtlString::CUtlString(this: &rawControls);
        v15 = 0;
        for ( i = 0; v15 < CDmeCombinationOperator::GetRawControlCount(this: v9, nControl: v12); ++v15 )
        {
          if ( CUtlString::Length(this: &rawControls) > 0 )
            CUtlString::operator+=(this: &rawControls, rhs: ", ");
          RawControlName = CDmeCombinationOperator::GetRawControlName(this: v9, nControl: v12, nIndex: v15);
          CUtlString::operator+=(this: &rawControls, rhs: RawControlName);
        }
        CUtlString::Get(this: &rawControls);
        v17 = CDmxEdit::SetErrorString(
                this: v20,
                pFormat: "Control \"%s\" Does Not Have Raw Control \"%s\", Raw Controls: ",
                pControlName,
                pRawControlName);
        i = -1;
        rawControls.m_Storage.m_nActualLength = 0;
        if ( rawControls.m_Storage.m_Memory.m_nGrowSize >= 0 && rawControls.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rawControls.m_Storage.m_Memory.m_pMemory);
        return v17;
      }
      else
      {
        while ( 1 )
        {
          v14 = CDmeCombinationOperator::GetRawControlName(this: v9, nControl: v12, nIndex: v13);
          if ( _V_strcmp(s1: pRawControlName, s2: v14) == 0 )
            break;
          if ( ++v13 >= CDmeCombinationOperator::GetRawControlCount(this: v9, nControl: v12) )
            goto LABEL_12;
        }
        CDmeCombinationOperator::SetWrinkleScale(this: v9, nControl: v12, pRawControlName, flWrinkleScale: flScale);
        return 1;
      }
    }
    else
    {
      return CDmxEdit::SetErrorString(this, pFormat: "Cannot Find Control \"%s\"", pControlName);
    }
  }
  else
  {
    m_pAsString = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    return CDmxEdit::SetErrorString(this, pFormat: "No DmeCombinationOperator On Mesh \"%s\"", m_pAsString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406830
// Name: SetWrinkleScale_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SetWrinkleScale_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  const char *v2; // ebx
  const char *v3; // eax
  float fScale; // [esp+10h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  v2 = luaL_checklstring(L: pLuaState, narg: 2, len: nullptr);
  fScale = luaL_checknumber(L: pLuaState, narg: 3);
  if ( CDmxEdit::SetWrinkleScale(this: &LuaFunc_s::m_dmxEdit, pControlName: v1, pRawControlName: v2, flScale: fScale) == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v3 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v3);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004068D0
// Name: public: void CDmxEdit::CreateWork(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::CreateWork(CDmxEdit *this)
{
  CDmeMesh *m_pMesh; // ecx
  CDmeVertexData *BaseState; // esi
  CDmeVertexData *v4; // eax
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmeSingleIndexedComponent *v7; // esi
  CDmeSingleIndexedComponent *v8; // ecx
  CDmeMesh *v9; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  m_pMesh = this->m_pMesh;
  if ( m_pMesh != nullptr )
  {
    BaseState = CDmeMesh::FindBaseState(this: m_pMesh, pStateName: "bind");
    if ( BaseState != nullptr )
    {
      v4 = CDmeMesh::FindOrCreateBaseState(this: this->m_pMesh, pStateName: "__dmxEdit_work");
      if ( v4 != nullptr )
      {
        CDmeVertexDataBase::CopyTo(this: BaseState, pDst: v4);
        CDmeMesh::SetCurrentBaseState(this: this->m_pMesh, pStateName: "__dmxEdit_work");
      }
    }
    v5 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeSingleIndexedComponent::m_classType.u.m_Id,
           a3: "selection",
           a4: this->m_pRoot->m_fileId,
           a5: nullptr);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
    v7 = (CDmeSingleIndexedComponent *)v6;
    if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeSingleIndexedComponent::m_classType) )
      v8 = v7;
    else
      v8 = nullptr;
    this->m_pCurrentSelection = v8;
    v9 = this->m_pMesh;
    if ( v8 != nullptr )
      value = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v8);
    else
      value = DMELEMENT_HANDLE_INVALID;
    Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "selection");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v9, pAttributeName: "selection", type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004069C0
// Name: public: void CDmxEditLua::SetVar(class CUtlString const __near &,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEditLua::SetVar(CDmxEditLua *this, const CUtlString *var, const CUtlString *val)
{
  const char *v4; // eax
  const char *v5; // eax
  CUtlString sLuaCmd; // [esp+4h] [ebp-1Ch] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  CUtlString::CUtlString(this: &sLuaCmd, string: var);
  v7 = 0;
  CUtlString::operator+=(this: &sLuaCmd, rhs: " = ");
  CUtlString::operator+=(this: &sLuaCmd, rhs: val);
  CUtlString::operator+=(this: &sLuaCmd, rhs: ";");
  v4 = CUtlString::Get(this: &sLuaCmd);
  if ( luaL_loadstring(L: this->m_pLuaState, s: v4) != 0
    || lua_pcall(L: this->m_pLuaState, nargs: 0, nresults: -1, errfunc: 0) != 0 )
  {
    v5 = lua_tolstring(L: this->m_pLuaState, idx: -1, len: nullptr);
    _Error(a1: "Error: %s\n", v5);
  }
  v7 = -1;
  sLuaCmd.m_Storage.m_nActualLength = 0;
  if ( sLuaCmd.m_Storage.m_Memory.m_nGrowSize >= 0 && sLuaCmd.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sLuaCmd.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00406AA0
// Name: public: void CDmxEditLua::SetGame(class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEditLua::SetGame(CDmxEditLua *this, const CUtlString *game)
{
  const char *v3; // eax
  const char *v4; // eax
  CUtlString sLuaCmd; // [esp+4h] [ebp-1Ch] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  CUtlString::CUtlString(this: &sLuaCmd, pString: "vs.SetGame( ");
  v6 = 0;
  CUtlString::operator+=(this: &sLuaCmd, rhs: game);
  CUtlString::operator+=(this: &sLuaCmd, rhs: " );");
  v3 = CUtlString::Get(this: &sLuaCmd);
  if ( luaL_loadstring(L: this->m_pLuaState, s: v3) != 0
    || lua_pcall(L: this->m_pLuaState, nargs: 0, nresults: -1, errfunc: 0) != 0 )
  {
    v4 = lua_tolstring(L: this->m_pLuaState, idx: -1, len: nullptr);
    _Error(a1: "Error: %s\n", v4);
  }
  v6 = -1;
  sLuaCmd.m_Storage.m_nActualLength = 0;
  if ( sLuaCmd.m_Storage.m_Memory.m_nGrowSize >= 0 && sLuaCmd.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sLuaCmd.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00406B70
// Name: public: int CUtlStack<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>>::Push(class CDmeDag __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int>>::Push(
        CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > *this,
        CDmeDag **src)
{
  CDmeDag **m_pMemory; // eax
  int m_Size; // ecx
  CDmeDag **v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406D30
// Name: protected: bool CDmxEdit::Select(class CDmxEdit::CSelectOp const __near &,class CDmeVertexDeltaData __near *,class CDmeSingleIndexedComponent __near *,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Select(
        CDmxEdit *this,
        const CDmxEdit::CSelectOp *selectOp,
        CDmeVertexDeltaData *pDelta,
        CDmeSingleIndexedComponent *pPassedSelection,
        CDmeMesh *pPassedMesh)
{
  CDmeSingleIndexedComponent *m_pCurrentSelection; // edi
  CDmeSingleIndexedComponent *v8; // esi
  char v9; // bl
  IDataModel_vtbl *v10; // edi
  int v11; // eax

  if ( pDelta == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "Invalid Delta");
  m_pCurrentSelection = pPassedSelection;
  if ( pPassedSelection == nullptr )
  {
    m_pCurrentSelection = this->m_pCurrentSelection;
    if ( m_pCurrentSelection == nullptr )
      return CDmxEdit::SetErrorString(this, pFormat: "No Selection To Manipulate");
  }
  v8 = CreateElement<CDmeSingleIndexedComponent>(
         pObjectName: "tempSelection",
         fileid: m_pCurrentSelection->m_fileId,
         pObjectID: nullptr);
  if ( v8 == nullptr )
    return 0;
  v9 = CDmxEdit::Select(this, pDelta, pPassedSelection: v8, pPassedMesh);
  if ( v9 != 0 )
    CDmxEdit::Select(this, selectOp, pOriginal: m_pCurrentSelection, pNew: v8);
  v10 = g_pDataModel->__vftable;
  v11 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v8);
  v10->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v11);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00406DF0
// Name: public: bool CDmxEdit::Select(class CDmxEdit::CSelectOp const __near &,class CDmxEdit::CSelectType const __near &,class CDmeSingleIndexedComponent __near *,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Select(
        CDmxEdit *this,
        const CDmxEdit::CSelectOp *selectOp,
        const CDmxEdit::CSelectType *selectType,
        CDmeSingleIndexedComponent *pPassedSelection,
        CDmeMesh *pPassedMesh)
{
  CDmeSingleIndexedComponent *m_pCurrentSelection; // edi
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  CDmeSingleIndexedComponent *v10; // esi
  char v11; // bl
  IDataModel_vtbl *v12; // edi
  int v13; // eax

  m_pCurrentSelection = pPassedSelection;
  if ( pPassedSelection == nullptr )
  {
    m_pCurrentSelection = this->m_pCurrentSelection;
    if ( m_pCurrentSelection == nullptr )
      return CDmxEdit::SetErrorString(this, pFormat: "No Selection To Manipulate");
  }
  v8 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeSingleIndexedComponent::m_classType.u.m_Id,
         a3: "tempSelection",
         a4: m_pCurrentSelection->m_fileId,
         a5: nullptr);
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
  v10 = (CDmeSingleIndexedComponent *)v9;
  if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmeSingleIndexedComponent::m_classType) )
    return 0;
  v11 = CDmxEdit::Select(this, selectType, pPassedSelection: v10, pPassedMesh);
  if ( v11 != 0 )
    CDmxEdit::Select(this, selectOp, pOriginal: m_pCurrentSelection, pNew: v10);
  v12 = g_pDataModel->__vftable;
  v13 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
  v12->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v13);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x00406ED0
// Name: protected: void CDmxEdit::UpdateMakefile(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::UpdateMakefile(CDmxEdit *this, int pRoot)
{
  CDmElement *v2; // edi
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CExpressionCalculator *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // esi
  const char *v8; // eax
  CExpressionCalculator *v9; // eax
  DmFileId_t m_fileId; // [esp-8h] [ebp-1Ch]
  CDmrElementArray<CDmeSourceDCCFile> sources; // [esp+8h] [ebp-Ch] BYREF
  CDmxEdit *v12; // [esp+10h] [ebp-4h]

  v2 = (CDmElement *)pRoot;
  v12 = this;
  if ( pRoot != 0 )
  {
    v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeDCCMakefile::m_classType.u.m_Id,
           a3: "dmxedit",
           a4: *(DmFileId_t *)(pRoot + 56),
           a5: nullptr);
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
    v5 = (CExpressionCalculator *)v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
    {
      pRoot = CExpressionCalculator::VariableCount(this: v5);
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "makefile");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v2, pAttributeName: "makefile", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (const DmElementHandle_t *)&pRoot);
      }
      v7 = CDmElement::FindAttribute(this: (CDmElement *)v5, pAttributeName: "sources");
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sources);
      if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
      {
        sources.m_pAttribute = v7;
        sources.m_pStorage = (DmElementArray_t *)v7->m_pData;
      }
      else
      {
        sources.m_pAttribute = nullptr;
        sources.m_pStorage = nullptr;
      }
      m_fileId = v2->m_fileId;
      v8 = CUtlString::operator char const *(this: &v12->m_filename);
      v9 = (CExpressionCalculator *)CreateElement<CDmeSourceDCCFile>(
                                      pObjectName: v8,
                                      fileid: m_fileId,
                                      pObjectID: nullptr);
      if ( v9 != nullptr )
        pRoot = CExpressionCalculator::VariableCount(this: v9);
      else
        pRoot = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &sources,
        src: (const DmElementHandle_t *)&pRoot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407010
// Name: DeleteDelta_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DeleteDelta_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  bool v2; // bl
  const char *v3; // eax
  const char *v4; // eax
  CUtlString v6; // [esp+Ch] [ebp-1Ch] BYREF
  int v7; // [esp+24h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  CUtlString::CUtlString(this: &v6, pString: v1);
  v7 = 0;
  if ( LuaFunc_s::m_dmxEdit.m_pMesh != nullptr )
  {
    if ( CUtlString::operator char const *(this: &v6) != nullptr )
    {
      v3 = CUtlString::operator char const *(this: &v6);
      CDmeMesh::DeleteDeltaState(this: LuaFunc_s::m_dmxEdit.m_pMesh, pDeltaName: v3);
      v2 = true;
    }
    else
    {
      v2 = CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "Invalid Delta");
    }
  }
  else
  {
    v2 = CDmxEdit::SetErrorString(this: &LuaFunc_s::m_dmxEdit, pFormat: "No Mesh");
  }
  v7 = -1;
  v6.m_Storage.m_nActualLength = 0;
  if ( v6.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6.m_Storage.m_Memory.m_pMemory);
      v6.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v6.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( !v2 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v4 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v4);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407130
// Name: public: class CDmeDag __near * CDmElement::GetValueElement<class CDmeDag>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmElement::GetValueElement<CDmeDag>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_601A7C = -1;
    dword_601A80 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeDag::m_classType) )
    return (CDmeDag *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004071C0
// Name: public: class CDmeModel __near * CDmElement::GetValueElement<class CDmeModel>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmElement::GetValueElement<CDmeModel>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_601A7C = -1;
    dword_601A80 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeModel::m_classType) )
    return (CDmeModel *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00407250
// Name: public: class CDmeCombinationOperator __near * CDmElement::GetValueElement<class CDmeCombinationOperator>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationOperator *__thiscall CDmElement::GetValueElement<CDmeCombinationOperator>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_601A7C = -1;
    dword_601A80 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeCombinationOperator::m_classType) )
    return (CDmeCombinationOperator *)((char *)&v5[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00407370
// Name: public: CUtlVectorFixedGrowable<bool,256>::~CUtlVectorFixedGrowable<bool,256>(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CUtlVectorFixedGrowable<bool,256>::~CUtlVectorFixedGrowable<bool,256>(
        CUtlVectorFixedGrowable<bool,256> *this)
{
  CUtlVector<bool,CUtlMemoryFixedGrowable<bool,256,int>>::~CUtlVector<bool,CUtlMemoryFixedGrowable<bool,256,int>>(this);
}

//------------------------------------------------------------------------------
// Address: 0x00407380
// Name: public: bool CDmxEdit::Select(class CDmxEdit::CSelectOp const __near &,char const __near *,class CDmeSingleIndexedComponent __near *,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Select(
        CDmxEdit *this,
        const CDmxEdit::CSelectOp *selectOp,
        const char *pSelectTypeString,
        CDmeSingleIndexedComponent *pPassedSelection,
        CDmeMesh *pPassedMesh)
{
  const char *v5; // esi
  const char *v7; // eax
  CDmeMesh *v8; // edi
  CDmeMesh *m_pMesh; // ecx
  CDmeVertexDeltaData *DeltaState; // eax

  v5 = pSelectTypeString;
  v7 = (const char *)_V_stricmp(s1: pSelectTypeString, s2: "NONE");
  if ( v7 != nullptr )
    v7 = (const char *)((_V_stricmp(s1: v5, s2: "ALL") != 0) + 1);
  pSelectTypeString = v7;
  if ( v7 != (const char *)2 )
    return CDmxEdit::Select(
             this,
             selectOp,
             selectType: (const CDmxEdit::CSelectType *)&pSelectTypeString,
             pPassedSelection,
             pPassedMesh);
  v8 = pPassedMesh;
  m_pMesh = pPassedMesh;
  if ( pPassedMesh == nullptr )
    m_pMesh = this->m_pMesh;
  if ( m_pMesh != nullptr
    && (DeltaState = CDmeMesh::FindDeltaState(this: m_pMesh, pDeltaName: v5, bSortDeltaName: true)) != nullptr )
  {
    return CDmxEdit::Select(this, selectOp, pDelta: DeltaState, pPassedSelection, pPassedMesh: v8);
  }
  else
  {
    return CDmxEdit::SetErrorString(this, pFormat: "Invalid Delta");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407420
// Name: public: bool CDmxEdit::GroupControls(char const __near *,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::GroupControls(
        CDmxEdit *this,
        const char *pGroupName,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *rawControlNames)
{
  CDmxEdit *v3; // esi
  CDmeMesh *m_pMesh; // edi
  CUtlSymbolLarge *v6; // eax
  CDmeCombinationOperator *Referring; // edi
  const char *m_pAsString; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *v9; // ebx
  bool v10; // cc
  int v11; // esi
  int ControlIndex; // eax
  int m_Size; // eax
  const char **v14; // ebx
  int v15; // esi
  const char **m_pMemory; // ecx
  int v17; // eax
  const char **v18; // ecx
  int v19; // esi
  bool v20; // al
  bool v21; // bl
  int v22; // ebx
  int Control; // ebx
  int j; // esi
  const char **v25; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > validControlNames; // [esp+Ch] [ebp-38h] BYREF
  _BYTE v27[4]; // [esp+20h] [ebp-24h] BYREF
  int nControlIndex; // [esp+24h] [ebp-20h]
  BOOL bEyelid; // [esp+28h] [ebp-1Ch]
  BOOL bStereo; // [esp+2Ch] [ebp-18h]
  CDmxEdit *v31; // [esp+30h] [ebp-14h]
  int i; // [esp+34h] [ebp-10h]
  int v33; // [esp+40h] [ebp-4h]

  v3 = this;
  m_pMesh = this->m_pMesh;
  v31 = this;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v6 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v27, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: m_pMesh,
                symAttrName: (CUtlSymbolLarge)v6->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
  {
    m_pAsString = v3->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    return CDmxEdit::SetErrorString(this: v3, pFormat: "No DmeCombinationOperator On Mesh \"%s\"", m_pAsString);
  }
  memset(&validControlNames, 0, sizeof(validControlNames));
  v33 = 0;
  i = 0;
  v9 = rawControlNames;
  v10 = rawControlNames->m_Size <= 0;
  LOBYTE(bStereo) = 0;
  LOBYTE(bEyelid) = 0;
  if ( !v10 )
  {
    do
    {
      v11 = i;
      ControlIndex = CDmeCombinationOperator::FindControlIndex(this: Referring, pControlName: v9->m_Memory.m_pMemory[i]);
      nControlIndex = ControlIndex;
      if ( ControlIndex >= 0 )
      {
        if ( CDmeCombinationOperator::GetRawControlCount(this: Referring, nControl: ControlIndex) <= 1 )
        {
          m_Size = validControlNames.m_Size;
          v14 = &v9->m_Memory.m_pMemory[v11];
          v15 = validControlNames.m_Size;
          if ( validControlNames.m_Size + 1 > validControlNames.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&validControlNames,
              num: validControlNames.m_Size - validControlNames.m_Memory.m_nAllocationCount + 1);
            m_Size = validControlNames.m_Size;
          }
          m_pMemory = validControlNames.m_Memory.m_pMemory;
          validControlNames.m_Size = m_Size + 1;
          v17 = m_Size - v15;
          validControlNames.m_pElements = validControlNames.m_Memory.m_pMemory;
          if ( v17 > 0 )
          {
            _V_memmove(
              dest: &validControlNames.m_Memory.m_pMemory[v15 + 1],
              src: &validControlNames.m_Memory.m_pMemory[v15],
              count: 4 * v17);
            m_pMemory = validControlNames.m_Memory.m_pMemory;
          }
          v18 = &m_pMemory[v15];
          if ( v18 != nullptr )
            *v18 = *v14;
          v19 = nControlIndex;
          if ( CDmeCombinationOperator::IsStereoControl(this: Referring, nControlIndex) )
            LOBYTE(bStereo) = 1;
          v9 = rawControlNames;
          if ( CDmeCombinationOperator::IsEyelidControl(this: Referring, nControlIndex: v19) )
            LOBYTE(bEyelid) = 1;
        }
        else
        {
          CDmxEdit::LuaWarning(this: v31, pFormat: "Control \"%s\" Isn't A Raw Control, Ignoring", pGroupName);
        }
      }
      else
      {
        CDmxEdit::LuaWarning(this: v31, pFormat: "Control \"%s\" Doesn't Exist, Ignoring", pGroupName);
      }
      ++i;
    }
    while ( i < v9->m_Size );
    v3 = v31;
  }
  if ( HasDuplicateControlName(pDmeCombo: Referring, pControlName: pGroupName, retiredControlNames: &validControlNames) )
  {
    v20 = CDmxEdit::SetErrorString(this: v3, pFormat: "Duplicate Control \"%s\" Found", pGroupName);
LABEL_26:
    v21 = v20;
    v33 = -1;
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: &validControlNames);
    return v21;
  }
  if ( validControlNames.m_Size <= 0 )
  {
    v20 = CDmxEdit::SetErrorString(this: v3, pFormat: "No Valid Controls Specified");
    goto LABEL_26;
  }
  v22 = 0;
  do
    CDmeCombinationOperator::RemoveControl(this: Referring, pControlName: validControlNames.m_Memory.m_pMemory[v22++]);
  while ( v22 < validControlNames.m_Size );
  Control = CDmeCombinationOperator::FindOrCreateControl(
              this: Referring,
              pControlName: pGroupName,
              bStereo,
              bAutoAddRawControl: false);
  CDmeCombinationOperator::SetEyelidControl(this: Referring, nControlIndex: Control, bIsEyelid: bEyelid);
  for ( j = 0; j < validControlNames.m_Size; ++j )
    CDmeCombinationOperator::AddRawControl(
      this: Referring,
      nControl: Control,
      pRawControlName: validControlNames.m_Memory.m_pMemory[j]);
  v25 = validControlNames.m_Memory.m_pMemory;
  v33 = 1;
  validControlNames.m_Size = 0;
  if ( validControlNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( validControlNames.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validControlNames.m_Memory.m_pMemory);
      v25 = nullptr;
      validControlNames.m_Memory.m_pMemory = nullptr;
    }
    validControlNames.m_Memory.m_nAllocationCount = 0;
  }
  validControlNames.m_pElements = v25;
  v33 = -1;
  if ( validControlNames.m_Memory.m_nGrowSize >= 0 && v25 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407720
// Name: GroupControls_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl GroupControls_luaFunc(lua_State *pLuaState)
{
  int m_Size; // esi
  const char **m_pMemory; // edi
  int v3; // ecx
  const char **v4; // ecx
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  const char *v9; // eax
  int m_nGrowSize; // esi
  bool v11; // sf
  IMemAlloc *v12; // ecx
  int m_lineNo; // esi
  const char *v14; // eax
  const char *v15; // [esp-8h] [ebp-44h]
  const char *v16; // [esp-4h] [ebp-40h]
  CUtlVector<char const *,CUtlMemory<char const *,int> > rawControlNames; // [esp+Ch] [ebp-30h] BYREF
  const char *pGroupName; // [esp+20h] [ebp-1Ch]
  const char *v19; // [esp+24h] [ebp-18h]
  int v20; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  int v22; // [esp+38h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  m_Size = 0;
  pGroupName = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  m_pMemory = nullptr;
  memset(&rawControlNames, 0, sizeof(rawControlNames));
  v22 = 0;
  i = 2;
  if ( lua_gettop(L: pLuaState) >= 2 )
  {
    do
    {
      if ( lua_isstring(L: pLuaState, idx: i) == 0 )
        break;
      v19 = lua_tolstring(L: pLuaState, idx: i, len: nullptr);
      v3 = m_Size;
      v20 = m_Size;
      if ( m_Size + 1 > rawControlNames.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&rawControlNames,
          num: m_Size - rawControlNames.m_Memory.m_nAllocationCount + 1);
        m_Size = rawControlNames.m_Size;
        m_pMemory = rawControlNames.m_Memory.m_pMemory;
        v3 = v20;
      }
      rawControlNames.m_Size = ++m_Size;
      rawControlNames.m_pElements = m_pMemory;
      if ( m_Size - v3 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v3 + 1], src: &m_pMemory[v3], count: 4 * (m_Size - v3 - 1));
        v3 = v20;
      }
      v4 = &m_pMemory[v3];
      if ( v4 != nullptr )
        *v4 = v19;
      ++i;
      v5 = lua_gettop(L: pLuaState);
    }
    while ( i <= v5 );
    if ( m_Size > 0 )
    {
      if ( CDmxEdit::GroupControls(this: &LuaFunc_s::m_dmxEdit, pGroupName, &rawControlNames) == 0 )
      {
        m_lineNo = LuaFunc_s::m_dmxEdit.m_lineNo;
        v16 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_errorString);
        v15 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
        if ( m_lineNo < 0 )
        {
          CDmxEdit::Error(this: &LuaFunc_s::m_dmxEdit, pMsgFormat: "// ERROR: %s - %s\n", v15, v16);
        }
        else
        {
          v14 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_sourceFile);
          CDmxEdit::Error(
            this: &LuaFunc_s::m_dmxEdit,
            pMsgFormat: "// ERROR: %s:%d: %s - %s\n",
            v14,
            m_lineNo,
            v15,
            v16);
        }
        lua_pushboolean(L: pLuaState, b: 0);
        m_nGrowSize = rawControlNames.m_Memory.m_nGrowSize;
        v22 = 3;
        rawControlNames.m_Size = 0;
        v11 = rawControlNames.m_Memory.m_nGrowSize < 0;
        if ( rawControlNames.m_Memory.m_nGrowSize < 0 )
          goto LABEL_30;
        if ( m_pMemory == nullptr )
          goto LABEL_29;
        v12 = _g_pMemAlloc;
        goto LABEL_28;
      }
      v9 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
      _Msg(a1: "// %s\n", v9);
      lua_pushboolean(L: pLuaState, b: 1);
      m_nGrowSize = rawControlNames.m_Memory.m_nGrowSize;
      v22 = 2;
      rawControlNames.m_Size = 0;
      v11 = rawControlNames.m_Memory.m_nGrowSize < 0;
      if ( rawControlNames.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          v12 = _g_pMemAlloc;
LABEL_28:
          v12->Free_2(this: v12, a2: m_pMemory);
          m_pMemory = nullptr;
        }
LABEL_29:
        v11 = m_nGrowSize < 0;
      }
LABEL_30:
      v22 = -1;
      if ( !v11 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      return 1;
    }
  }
  v6 = CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState, pFormat: "No Raw Controls Specified");
  v7 = rawControlNames.m_Memory.m_nGrowSize;
  v22 = 1;
  rawControlNames.m_Size = 0;
  if ( rawControlNames.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    m_pMemory = nullptr;
  }
  v22 = -1;
  if ( v7 >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004079C0
// Name: public: bool CDmxEdit::ReorderControls(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::ReorderControls(
        CDmxEdit *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *controlNames)
{
  CDmxEdit *v2; // esi
  CDmeMesh *m_pMesh; // edi
  int v4; // ebx
  CUtlSymbolLarge *v6; // eax
  const char *m_pAsString; // eax
  const char *v9; // eax
  const char **m_pMemory; // edx
  const char *v11; // eax
  int m_Size; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > **v13; // esi
  bool v14; // bl
  int v15; // esi
  CDmeCombinationOperator *v16; // ebx
  const char **v17; // edi
  const char *ControlName; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > validControlNames; // [esp+Ch] [ebp-30h] BYREF
  _BYTE v20[4]; // [esp+20h] [ebp-1Ch] BYREF
  CDmeCombinationOperator *Referring; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  CDmxEdit *v23; // [esp+2Ch] [ebp-10h]
  int v24; // [esp+38h] [ebp-4h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *controlNamesa; // [esp+44h] [ebp+8h]

  v2 = this;
  m_pMesh = this->m_pMesh;
  v4 = 0;
  v23 = this;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v6 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v20, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: m_pMesh,
                symAttrName: (CUtlSymbolLarge)v6->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    memset(&validControlNames, 0, sizeof(validControlNames));
    v24 = 0;
    i = 0;
    if ( controlNames->m_Size <= 0 )
      goto LABEL_19;
    do
    {
      v9 = CUtlString::operator char const *(this: &controlNames->m_Memory.m_pMemory[v4]);
      if ( CDmeCombinationOperator::FindControlIndex(this: Referring, pControlName: v9) >= 0 )
      {
        v11 = CUtlString::operator char const *(this: &controlNames->m_Memory.m_pMemory[v4]);
        m_Size = validControlNames.m_Size;
        controlNamesa = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)v11;
        if ( validControlNames.m_Size + 1 > validControlNames.m_Memory.m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&validControlNames,
            num: validControlNames.m_Size - validControlNames.m_Memory.m_nAllocationCount + 1);
        m_pMemory = validControlNames.m_Memory.m_pMemory;
        ++validControlNames.m_Size;
        validControlNames.m_pElements = validControlNames.m_Memory.m_pMemory;
        if ( validControlNames.m_Size - m_Size - 1 > 0 )
        {
          _V_memmove(
            dest: &validControlNames.m_Memory.m_pMemory[m_Size + 1],
            src: &validControlNames.m_Memory.m_pMemory[m_Size],
            count: 4 * (validControlNames.m_Size - m_Size - 1));
          m_pMemory = validControlNames.m_Memory.m_pMemory;
        }
        v13 = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > **)&m_pMemory[m_Size];
        if ( v13 != nullptr )
        {
          *v13 = controlNamesa;
          m_pMemory = validControlNames.m_Memory.m_pMemory;
        }
        v2 = v23;
      }
      else
      {
        CDmxEdit::LuaWarning(
          this: v2,
          pFormat: "Control \"%s\" doesn't exist, ignoring",
          (const char *)controlNames->m_Memory.m_pMemory[v4].m_Storage.m_Memory.m_pMemory);
        m_pMemory = validControlNames.m_Memory.m_pMemory;
      }
      ++v4;
      ++i;
    }
    while ( i < controlNames->m_Size );
    if ( validControlNames.m_Size > 0 )
    {
      v15 = 0;
      do
      {
        v16 = Referring;
        v17 = &m_pMemory[v15];
        ControlName = CDmeCombinationOperator::GetControlName(this: Referring, i: v15);
        CDmeCombinationOperator::MoveControlBefore(this: v16, pDragControlName: *v17, pDropControlName: ControlName);
        m_pMemory = validControlNames.m_Memory.m_pMemory;
        ++v15;
      }
      while ( v15 < validControlNames.m_Size );
      v24 = 1;
      validControlNames.m_Size = 0;
      if ( validControlNames.m_Memory.m_nGrowSize >= 0 )
      {
        if ( validControlNames.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validControlNames.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          validControlNames.m_Memory.m_pMemory = nullptr;
        }
        validControlNames.m_Memory.m_nAllocationCount = 0;
      }
      validControlNames.m_pElements = m_pMemory;
      v24 = -1;
      if ( validControlNames.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      return 1;
    }
    else
    {
LABEL_19:
      v14 = CDmxEdit::SetErrorString(this: v2, pFormat: "No Valid Controls Specified");
      v24 = -1;
      CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: &validControlNames);
      return v14;
    }
  }
  else
  {
    m_pAsString = v2->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    return CDmxEdit::SetErrorString(this: v2, pFormat: "No DmeCombinationOperator On Mesh \"%s\"", m_pAsString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407C20
// Name: public: bool CDmxEdit::AddDominationRule(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::AddDominationRule(
        CDmxEdit *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dominators,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *supressed)
{
  CDmeMesh *m_pMesh; // esi
  const char **m_nAllocationCount; // edi
  CUtlSymbolLarge *v7; // eax
  const char *m_pAsString; // eax
  int m_Size; // ebx
  int v10; // esi
  const char **m_pMemory; // edi
  char **v12; // esi
  int v13; // esi
  int v14; // ebx
  char **v15; // ebx
  int m_nGrowSize; // esi
  int v17; // esi
  const char **v18; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > tmpSupressed; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<char const *,CUtlMemory<char const *,int> > tmpDominators; // [esp+20h] [ebp-34h] BYREF
  _BYTE v21[4]; // [esp+34h] [ebp-20h] BYREF
  CDmeCombinationOperator *Referring; // [esp+38h] [ebp-1Ch]
  char *v23; // [esp+3Ch] [ebp-18h]
  int i; // [esp+40h] [ebp-14h]
  unsigned int v25; // [esp+44h] [ebp-10h]
  int v26; // [esp+50h] [ebp-4h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dominatorsa; // [esp+5Ch] [ebp+8h]

  m_pMesh = this->m_pMesh;
  m_nAllocationCount = nullptr;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v7 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v21, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: m_pMesh,
                symAttrName: (CUtlSymbolLarge)v7->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_Size = 0;
    memset(&tmpDominators, 0, sizeof(tmpDominators));
    v26 = 0;
    i = 0;
    if ( dominators->m_Size > 0 )
    {
      v25 = 0;
      while ( 1 )
      {
        v23 = CUtlString::Get(this: &dominators->m_Memory.m_pMemory[v25 / 0x10]);
        v10 = m_Size;
        if ( m_Size + 1 > (int)m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&tmpDominators,
            num: m_Size - (_DWORD)m_nAllocationCount + 1);
          m_Size = tmpDominators.m_Size;
        }
        m_pMemory = tmpDominators.m_Memory.m_pMemory;
        tmpDominators.m_Size = ++m_Size;
        tmpDominators.m_pElements = tmpDominators.m_Memory.m_pMemory;
        if ( m_Size - v10 - 1 > 0 )
          _V_memmove(
            dest: &tmpDominators.m_Memory.m_pMemory[v10 + 1],
            src: &tmpDominators.m_Memory.m_pMemory[v10],
            count: 4 * (m_Size - v10 - 1));
        v12 = (char **)&m_pMemory[v10];
        if ( v12 != nullptr )
          *v12 = v23;
        v25 += 16;
        if ( ++i >= dominators->m_Size )
          break;
        m_nAllocationCount = (const char **)tmpDominators.m_Memory.m_nAllocationCount;
      }
      m_nAllocationCount = nullptr;
    }
    v13 = 0;
    memset(&tmpSupressed, 0, sizeof(tmpSupressed));
    LOBYTE(v26) = 1;
    i = 0;
    if ( supressed->m_Size > 0 )
    {
      dominatorsa = nullptr;
      do
      {
        v23 = CUtlString::Get(this: (CUtlString *)((char *)dominatorsa + (unsigned int)supressed->m_Memory.m_pMemory));
        v14 = v13;
        if ( v13 + 1 > tmpSupressed.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&tmpSupressed,
            num: v13 - tmpSupressed.m_Memory.m_nAllocationCount + 1);
          v13 = tmpSupressed.m_Size;
          m_nAllocationCount = tmpSupressed.m_Memory.m_pMemory;
        }
        tmpSupressed.m_Size = ++v13;
        tmpSupressed.m_pElements = m_nAllocationCount;
        if ( v13 - v14 - 1 > 0 )
          _V_memmove(dest: &m_nAllocationCount[v14 + 1], src: &m_nAllocationCount[v14], count: 4 * (v13 - v14 - 1));
        v15 = (char **)&m_nAllocationCount[v14];
        if ( v15 != nullptr )
          *v15 = v23;
        dominatorsa = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)((char *)dominatorsa + 16);
        ++i;
      }
      while ( i < supressed->m_Size );
      m_Size = tmpDominators.m_Size;
    }
    CDmeCombinationOperator::AddDominationRule(
      this: Referring,
      nDominatorCount: m_Size,
      ppDominatorControlNames: tmpDominators.m_Memory.m_pMemory,
      nSuppressedCount: v13,
      ppSuppressedControlNames: m_nAllocationCount);
    m_nGrowSize = tmpSupressed.m_Memory.m_nGrowSize;
    LOBYTE(v26) = 2;
    tmpSupressed.m_Size = 0;
    if ( tmpSupressed.m_Memory.m_nGrowSize >= 0 && m_nAllocationCount != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
      m_nAllocationCount = nullptr;
    }
    LOBYTE(v26) = 0;
    if ( m_nGrowSize >= 0 && m_nAllocationCount != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
    v17 = tmpDominators.m_Memory.m_nGrowSize;
    v18 = tmpDominators.m_Memory.m_pMemory;
    v26 = 3;
    tmpDominators.m_Size = 0;
    if ( tmpDominators.m_Memory.m_nGrowSize >= 0 && tmpDominators.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpDominators.m_Memory.m_pMemory);
      tmpDominators.m_Memory.m_pMemory = nullptr;
      v18 = nullptr;
    }
    v26 = -1;
    if ( v17 >= 0 && v18 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
    return 1;
  }
  else
  {
    m_pAsString = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    return CDmxEdit::SetErrorString(this, pFormat: "No DmeCombinationOperator On Mesh \"%s\"", m_pAsString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407F30
// Name: protected: void CDmxEdit::ImportCombinationControls(class CDmeCombinationOperator __near *,class CDmeCombinationOperator __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::ImportCombinationControls(
        CDmxEdit *this,
        CDmeCombinationOperator *pSrcComboOp,
        CDmeCombinationOperator *pDstComboOp,
        bool bOverwrite)
{
  int v6; // esi
  int v7; // esi
  int v8; // eax
  const char *RawControlName; // esi
  int ControlIndexFromRawControlName; // eax
  int i; // esi
  const char *ControlName; // eax
  int RawControlCount; // ecx
  int m_Size; // eax
  int v15; // esi
  IMemAlloc_vtbl *v16; // eax
  int v17; // eax
  int v18; // esi
  const char *v19; // eax
  bool DoesTargetContainDeltaState; // al
  bool IsEyelidControl; // al
  int v22; // esi
  bool *m_pMemory; // eax
  CUtlVectorFixedGrowable<bool,256> foundMatch; // [esp+10h] [ebp-13Ch] BYREF
  unsigned int count; // [esp+128h] [ebp-24h]
  BOOL bIsStereo; // [esp+12Ch] [ebp-20h]
  unsigned __int8 *v27; // [esp+130h] [ebp-1Ch]
  int num; // [esp+134h] [ebp-18h]
  float flWrinkleScale; // [esp+138h] [ebp-14h]
  const char *pRawControl; // [esp+13Ch] [ebp-10h]
  int v31; // [esp+148h] [ebp-4h]
  int index; // [esp+154h] [ebp+8h]
  int indexa; // [esp+154h] [ebp+8h]
  int indexb; // [esp+154h] [ebp+8h]
  int nRawControls; // [esp+158h] [ebp+Ch]
  int nRawControlsa; // [esp+158h] [ebp+Ch]
  int bOverwritea; // [esp+15Ch] [ebp+10h]
  char bOverwrite_3; // [esp+15Fh] [ebp+13h]

  if ( bOverwrite )
  {
    CDmeCombinationOperator::RemoveAllControls(this: pDstComboOp);
  }
  else
  {
LABEL_5:
    v7 = 0;
    bOverwrite_3 = 0;
    index = 0;
    while ( v7 < CDmeCombinationOperator::GetControlCount(this: pSrcComboOp) )
    {
      pRawControl = (const char *)CDmeCombinationOperator::GetRawControlCount(this: pSrcComboOp, nControl: v7);
      v8 = 0;
      nRawControls = 0;
      while ( v8 < (int)pRawControl )
      {
        RawControlName = CDmeCombinationOperator::GetRawControlName(this: pSrcComboOp, nControl: v7, nIndex: v8);
        ControlIndexFromRawControlName = FindControlIndexFromRawControlName(
                                           pCombo: pDstComboOp,
                                           pRawControlName: RawControlName);
        if ( ControlIndexFromRawControlName >= 0 )
        {
          CDmeCombinationOperator::RemoveRawControl(
            this: pDstComboOp,
            nControl: ControlIndexFromRawControlName,
            pRawControlName: RawControlName);
          v7 = index;
          bOverwrite_3 = 1;
          break;
        }
        ++nRawControls;
        v7 = index;
        v8 = nRawControls;
      }
      index = ++v7;
      if ( bOverwrite_3 != 0 )
        goto LABEL_5;
    }
LABEL_14:
    for ( i = 0; i < CDmeCombinationOperator::GetControlCount(this: pDstComboOp); ++i )
    {
      if ( CDmeCombinationOperator::GetRawControlCount(this: pDstComboOp, nControl: i) == 0 )
      {
        ControlName = CDmeCombinationOperator::GetControlName(this: pDstComboOp, i);
        CDmeCombinationOperator::RemoveControl(this: pDstComboOp, pControlName: ControlName);
        goto LABEL_14;
      }
    }
  }
  v6 = 0;
  foundMatch.m_Memory.m_pMemory = foundMatch.m_Memory.m_pFixedMemory;
  foundMatch.m_Memory.m_nAllocationCount = 256;
  foundMatch.m_Memory.m_nGrowSize = -1;
  foundMatch.m_Memory.m_nMallocGrowSize = 0;
  foundMatch.m_Size = 0;
  foundMatch.m_pElements = foundMatch.m_Memory.m_pFixedMemory;
  v31 = 0;
  bOverwritea = 0;
  if ( CDmeCombinationOperator::GetControlCount(this: pSrcComboOp) > 0 )
  {
    while ( 1 )
    {
      pRawControl = CDmeCombinationOperator::GetControlName(this: pSrcComboOp, i: v6);
      RawControlCount = CDmeCombinationOperator::GetRawControlCount(this: pSrcComboOp, nControl: v6);
      m_Size = foundMatch.m_Size;
      nRawControlsa = RawControlCount;
      indexa = 0;
      if ( foundMatch.m_Size < RawControlCount )
      {
        v15 = RawControlCount - foundMatch.m_Size;
        flWrinkleScale = *(float *)&foundMatch.m_Size;
        if ( RawControlCount != foundMatch.m_Size )
        {
          if ( RawControlCount > foundMatch.m_Memory.m_nAllocationCount )
          {
            num = RawControlCount - foundMatch.m_Memory.m_nAllocationCount;
            if ( foundMatch.m_Memory.m_nGrowSize < 0 )
            {
              foundMatch.m_Memory.m_nGrowSize = foundMatch.m_Memory.m_nMallocGrowSize;
              if ( foundMatch.m_Memory.m_nAllocationCount != 0 )
              {
                v16 = _g_pMemAlloc->__vftable;
                count = foundMatch.m_Memory.m_nAllocationCount;
                v27 = (unsigned __int8 *)v16->Alloc_2(this: _g_pMemAlloc, a2: foundMatch.m_Memory.m_nAllocationCount);
                memcpy(dst: v27, src: (unsigned __int8 *)foundMatch.m_Memory.m_pMemory, count);
                foundMatch.m_Memory.m_pMemory = (bool *)v27;
              }
              else
              {
                foundMatch.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&foundMatch, num);
            m_Size = foundMatch.m_Size;
          }
          foundMatch.m_Size = v15 + m_Size;
          v17 = m_Size - LODWORD(flWrinkleScale);
          foundMatch.m_pElements = foundMatch.m_Memory.m_pMemory;
          if ( v17 > 0 && v15 > 0 )
            _V_memmove(
              dest: &foundMatch.m_Memory.m_pMemory[LODWORD(flWrinkleScale) + v15],
              src: &foundMatch.m_Memory.m_pMemory[LODWORD(flWrinkleScale)],
              count: v17);
          RawControlCount = nRawControlsa;
        }
      }
      v18 = 0;
      if ( RawControlCount > 0 )
      {
        do
        {
          v19 = CDmeCombinationOperator::GetRawControlName(this: pSrcComboOp, nControl: bOverwritea, nIndex: v18);
          LODWORD(flWrinkleScale) = &foundMatch.m_Memory.m_pMemory[v18];
          DoesTargetContainDeltaState = CDmeCombinationOperator::DoesTargetContainDeltaState(
                                          this: pDstComboOp,
                                          pSearchName: v19);
          *(_BYTE *)LODWORD(flWrinkleScale) = DoesTargetContainDeltaState;
          indexa += foundMatch.m_Memory.m_pMemory[v18++];
        }
        while ( v18 < nRawControlsa );
        if ( indexa != 0 )
        {
          CDmeCombinationOperator::RemoveControl(this: pDstComboOp, pControlName: pRawControl);
          LOBYTE(bIsStereo) = CDmeCombinationOperator::IsStereoControl(this: pSrcComboOp, nControlIndex: bOverwritea);
          indexb = CDmeCombinationOperator::FindOrCreateControl(
                     this: pDstComboOp,
                     pControlName: pRawControl,
                     bStereo: bIsStereo,
                     bAutoAddRawControl: false);
          IsEyelidControl = CDmeCombinationOperator::IsEyelidControl(this: pSrcComboOp, nControlIndex: bOverwritea);
          CDmeCombinationOperator::SetEyelidControl(
            this: pDstComboOp,
            nControlIndex: indexb,
            bIsEyelid: IsEyelidControl);
          v22 = 0;
          do
          {
            if ( foundMatch.m_Memory.m_pMemory[v22] )
            {
              pRawControl = CDmeCombinationOperator::GetRawControlName(
                              this: pSrcComboOp,
                              nControl: bOverwritea,
                              nIndex: v22);
              flWrinkleScale = CDmeCombinationOperator::GetRawControlWrinkleScale(
                                 this: pSrcComboOp,
                                 nControl: bOverwritea,
                                 nIndex: v22);
              CDmeCombinationOperator::AddRawControl(this: pDstComboOp, nControl: indexb, pRawControlName: pRawControl);
              CDmeCombinationOperator::SetWrinkleScale(
                this: pDstComboOp,
                nControl: indexb,
                pRawControlName: pRawControl,
                flWrinkleScale);
            }
            ++v22;
          }
          while ( v22 < nRawControlsa );
        }
      }
      if ( ++bOverwritea >= CDmeCombinationOperator::GetControlCount(this: pSrcComboOp) )
        break;
      v6 = bOverwritea;
    }
  }
  m_pMemory = foundMatch.m_Memory.m_pMemory;
  v31 = 1;
  foundMatch.m_Size = 0;
  if ( foundMatch.m_Memory.m_nGrowSize >= 0 )
  {
    if ( foundMatch.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: foundMatch.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      foundMatch.m_Memory.m_pMemory = nullptr;
    }
    foundMatch.m_Memory.m_nAllocationCount = 0;
  }
  foundMatch.m_pElements = m_pMemory;
  v31 = -1;
  if ( foundMatch.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004082D0
// Name: Select_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Select_luaFunc(lua_State *pLuaState)
{
  const char *v1; // ebx
  const char *v2; // edi
  char v3; // al
  const char *v4; // eax
  CDmxEdit::CSelectOp selectOp; // [esp+Ch] [ebp-4h] BYREF

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  v2 = lua_tolstring(L: pLuaState, idx: 2, len: nullptr);
  if ( v2 != nullptr )
  {
    selectOp.m_selectOp = CDmxEdit::CSelectOp::StringToSelectOp(this: &selectOp, pSelectOpString: v1);
    v3 = CDmxEdit::Select(
           this: &LuaFunc_s::m_dmxEdit,
           &selectOp,
           pSelectTypeString: v2,
           pPassedSelection: nullptr,
           pPassedMesh: nullptr);
  }
  else
  {
    v3 = CDmxEdit::Select(
           this: &LuaFunc_s::m_dmxEdit,
           pSelectTypeString: v1,
           pPassedSelection: nullptr,
           pPassedMesh: nullptr);
  }
  if ( v3 == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v4 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v4);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408560
// Name: public: CUtlStringMap<class CUtlString>::~CUtlStringMap<class CUtlString>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlStringMap<CUtlString>::~CUtlStringMap<CUtlString>(CUtlStringMap<CUtlString> *this)
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_SymbolTable);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &this->m_Vector);
}

//------------------------------------------------------------------------------
// Address: 0x004085B0
// Name: public: bool CDmxEdit::ImportComboRules(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::ImportComboRules(CDmxEdit *this, const char *pFilename, bool bOverwrite, bool bPurgeDeltas)
{
  CDmeMesh *m_pMesh; // esi
  CUtlSymbolLarge *v7; // eax
  CDmeCombinationOperator *Referring; // esi
  const char *m_pAsString; // eax
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v11; // al
  IDataModel_vtbl *v12; // edx
  DmFileId_t (__thiscall *RestoreFromFile)(IDataModel *, const char *, const char *, const char *, CDmElement **, DmConflictResolution_t, DmxHeader_t *); // edx
  bool v14; // al
  bool v15; // bl
  CP4File *v16; // eax
  CDmElement *v17; // ecx
  CDmElement *v18; // edi
  CDmeCombinationOperator *Value; // edi
  CDisableUndoScopeGuard sg; // [esp+Ch] [ebp-1Ch] BYREF
  _BYTE v21[4]; // [esp+14h] [ebp-14h] BYREF
  CDmElement *pRoot; // [esp+18h] [ebp-10h] BYREF
  int v23; // [esp+24h] [ebp-4h]

  m_pMesh = this->m_pMesh;
  if ( m_pMesh == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Mesh");
  v7 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v21, a3: "targets");
  Referring = FindReferringElement<CDmeCombinationOperator>(
                pElement: m_pMesh,
                symAttrName: (CUtlSymbolLarge)v7->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
  {
    m_pAsString = this->m_pMesh->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    return CDmxEdit::SetErrorString(this, pFormat: "No DmeCombinationOperator On Mesh \"%s\"", m_pAsString);
  }
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  *(_WORD *)&sg.m_bReleased = 0;
  sg.m_pNotify = nullptr;
  v11 = IsUndoEnabled(this: g_pDataModel);
  v12 = g_pDataModel->__vftable;
  sg.m_bOldValue = v11;
  v12->SetUndoEnabled(this: g_pDataModel, a2: false);
  pRoot = nullptr;
  RestoreFromFile = g_pDataModel->RestoreFromFile;
  v23 = 0;
  RestoreFromFile(
    this: g_pDataModel,
    a2: pFilename,
    a3: nullptr,
    a4: nullptr,
    a5: &pRoot,
    a6: CR_FORCE_COPY,
    a7: nullptr);
  if ( pRoot == nullptr )
  {
    v14 = CDmxEdit::SetErrorString(this, pFormat: "File Cannot Be Read");
LABEL_9:
    v15 = v14;
    v23 = -1;
    CChangeUndoScopeGuard::Release(this: &sg);
    return v15;
  }
  v16 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pFilename);
  v16->Add(this: v16);
  v17 = pRoot;
  v18 = pRoot;
  if ( pRoot != nullptr )
  {
    if ( ((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(
           a1: pRoot,
           a2: (CUtlSymbolLarge)CDmeCombinationOperator::m_classType.u.m_Id) )
    {
      Value = (CDmeCombinationOperator *)((char *)&v18[-1] + 64);
      if ( Value != nullptr )
        goto LABEL_16;
    }
    v17 = pRoot;
  }
  Value = CDmElement::GetValueElement<CDmeCombinationOperator>(this: v17, pAttributeName: "combinationOperator");
  if ( Value == nullptr )
  {
    v14 = CDmxEdit::SetErrorString(this, pFormat: "No DmeCombinationOperator Found In File");
    goto LABEL_9;
  }
LABEL_16:
  CDmxEdit::ImportCombinationControls(this, pSrcComboOp: Value, pDstComboOp: Referring, bOverwrite);
  CDmxEdit::ImportDominationRules(this, pDestComboOp: Referring, pSrcComboOp: Value, bOverwrite);
  CDmeCombinationOperator::SetToDefault(this: Referring);
  g_pDataModel->UnloadFile(this: g_pDataModel, a2: pRoot->m_fileId);
  if ( bPurgeDeltas )
    CDmSerializerBinary::IsBinaryFormat(this: (CP4File_Dummy *)this->m_pMesh);
  v23 = -1;
  CChangeUndoScopeGuard::Release(this: &sg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004087B0
// Name: ImportComboRules_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImportComboRules_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  char v2; // al
  const char *v3; // eax
  bool v5; // [esp-8h] [ebp-10h]
  bool v6; // [esp-8h] [ebp-10h]
  bool v7; // [esp-4h] [ebp-Ch]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_type(L: pLuaState, idx: 2) == 1 )
  {
    if ( lua_type(L: pLuaState, idx: 3) == 1 )
    {
      v7 = lua_toboolean(L: pLuaState, idx: 3) != 0;
      v5 = lua_toboolean(L: pLuaState, idx: 2) != 0;
      v2 = CDmxEdit::ImportComboRules(this: &LuaFunc_s::m_dmxEdit, pFilename: v1, bOverwrite: v5, bPurgeDeltas: v7);
    }
    else
    {
      v6 = lua_toboolean(L: pLuaState, idx: 2) != 0;
      v2 = CDmxEdit::ImportComboRules(this: &LuaFunc_s::m_dmxEdit, pFilename: v1, bOverwrite: v6, bPurgeDeltas: true);
    }
  }
  else
  {
    v2 = CDmxEdit::ImportComboRules(this: &LuaFunc_s::m_dmxEdit, pFilename: v1, bOverwrite: true, bPurgeDeltas: true);
  }
  if ( v2 == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v3 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v3);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408890
// Name: CachePreset_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl CachePreset_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  const char *v2; // ebx
  int m_Id; // edi
  const char *v4; // eax
  CUtlSymbol v6; // [esp+Ch] [ebp-4h] BYREF

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_isstring(L: pLuaState, idx: 2) != 0 )
    v2 = lua_tolstring(L: pLuaState, idx: 2, len: nullptr);
  else
    v2 = nullptr;
  CUtlSymbolTable::AddString(this: &LuaFunc_s::m_dmxEdit.m_presetCache.m_SymbolTable, result: &v6, pString: v1);
  m_Id = v6.m_Id;
  if ( LuaFunc_s::m_dmxEdit.m_presetCache.m_Vector.m_Size <= v6.m_Id
    && LuaFunc_s::m_dmxEdit.m_presetCache.m_Vector.m_Size < v6.m_Id + 1 )
  {
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
      this: &LuaFunc_s::m_dmxEdit.m_presetCache.m_Vector,
      elem: LuaFunc_s::m_dmxEdit.m_presetCache.m_Vector.m_Size,
      num: v6.m_Id + 1 - LuaFunc_s::m_dmxEdit.m_presetCache.m_Vector.m_Size);
  }
  CUtlString::operator=(this: &LuaFunc_s::m_dmxEdit.m_presetCache.m_Vector.m_Memory.m_pMemory[m_Id], src: v2);
  v4 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v4);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408950
// Name: ClearPresetCache_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClearPresetCache_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&LuaFunc_s::m_dmxEdit.m_presetCache);
  CUtlSymbolTable::RemoveAll(this: &LuaFunc_s::m_dmxEdit.m_presetCache.m_SymbolTable);
  v1 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v1);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004089A0
// Name: CreateDeltasFromCachedPresets_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateDeltasFromCachedPresets_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  int m_Size; // eax
  int v3; // esi
  CUtlString *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  bool v7; // zf
  void *(__cdecl **v8)(const char *, int *); // ecx
  bool DeltasFromPresets; // bl
  const char *v10; // eax
  int v12; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > purgeAllBut; // [esp+Ch] [ebp-40h] BYREF
  CUtlString string; // [esp+20h] [ebp-2Ch] BYREF
  void *(__cdecl **pFactoryList)(const char *, int *); // [esp+30h] [ebp-1Ch]
  int nFactoryCount; // [esp+34h] [ebp-18h]
  BOOL bPurge; // [esp+38h] [ebp-14h]
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pPurgeAllBut; // [esp+3Ch] [ebp-10h]
  int v19; // [esp+48h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  LOBYTE(bPurge) = lua_type(L: pLuaState, idx: 1) != 1 || lua_toboolean(L: pLuaState, idx: 1) != 0;
  memset(&purgeAllBut, 0, sizeof(purgeAllBut));
  v19 = 0;
  pPurgeAllBut = nullptr;
  if ( lua_type(L: pLuaState, idx: 2) == 5 )
  {
    pPurgeAllBut = &purgeAllBut;
    lua_pushnil(L: pLuaState);
    while ( lua_next(L: pLuaState, idx: 2) != 0 )
    {
      v1 = lua_tolstring(L: pLuaState, idx: -1, len: nullptr);
      CUtlString::CUtlString(this: &string, pString: v1);
      m_Size = purgeAllBut.m_Size;
      LOBYTE(v19) = 1;
      v3 = purgeAllBut.m_Size;
      if ( purgeAllBut.m_Size + 1 > purgeAllBut.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&purgeAllBut,
          num: purgeAllBut.m_Size - purgeAllBut.m_Memory.m_nAllocationCount + 1);
        m_Size = purgeAllBut.m_Size;
      }
      m_pMemory = purgeAllBut.m_Memory.m_pMemory;
      purgeAllBut.m_Size = m_Size + 1;
      v5 = m_Size - v3;
      purgeAllBut.m_pElements = purgeAllBut.m_Memory.m_pMemory;
      if ( v5 > 0 )
      {
        _V_memmove(
          dest: &purgeAllBut.m_Memory.m_pMemory[v3 + 1],
          src: &purgeAllBut.m_Memory.m_pMemory[v3],
          count: 16 * v5);
        m_pMemory = purgeAllBut.m_Memory.m_pMemory;
      }
      v6 = v3;
      v7 = &m_pMemory[v6] == nullptr;
      v8 = (void *(__cdecl **)(const char *, int *))&m_pMemory[v6];
      nFactoryCount = (int)v8;
      pFactoryList = v8;
      LOBYTE(v19) = 2;
      if ( !v7 )
        CUtlString::CUtlString(this: (CUtlString *)v8, &string);
      LOBYTE(v19) = 0;
      string.m_Storage.m_nActualLength = 0;
      if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
          string.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        string.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      lua_settop(L: pLuaState, idx: -2);
    }
  }
  DeltasFromPresets = CDmMeshUtils::CreateDeltasFromPresets(
                        pMesh: LuaFunc_s::m_dmxEdit.m_pMesh,
                        pPassedDst: nullptr,
                        presetExpressionMap: &LuaFunc_s::m_dmxEdit.m_presetCache,
                        bPurge,
                        pPurgeAllButThese: pPurgeAllBut);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&LuaFunc_s::m_dmxEdit.m_presetCache);
  CUtlSymbolTable::RemoveAll(this: &LuaFunc_s::m_dmxEdit.m_presetCache.m_SymbolTable);
  if ( DeltasFromPresets )
  {
    v10 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
    _Msg(a1: "// %s\n", v10);
    lua_pushboolean(L: pLuaState, b: 1);
    v19 = -1;
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &purgeAllBut);
    return 1;
  }
  else
  {
    v12 = CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
    v19 = -1;
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &purgeAllBut);
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408BB0
// Name: public: bool CDmxEdit::CreateExpressionFileFromPresets(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::CreateExpressionFileFromPresets(
        CDmxEdit *this,
        const char *pPresetFilename,
        const char *pExpressionFilename)
{
  CUtlStringMap<CUtlString> *p_m_presetCache; // esi
  int v4; // ebx
  int m_Size; // ecx
  bool ExpressionFilesFromCachedPresets; // bl

  p_m_presetCache = &this->m_presetCache;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_presetCache);
  CUtlSymbolTable::RemoveAll(this: &p_m_presetCache->m_SymbolTable);
  CUtlSymbolTable::AddString(
    this: &p_m_presetCache->m_SymbolTable,
    result: (CUtlSymbol *)&pPresetFilename,
    pString: pPresetFilename);
  v4 = (unsigned __int16)pPresetFilename;
  m_Size = p_m_presetCache->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pPresetFilename && m_Size < (unsigned __int16)pPresetFilename + 1 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
      this: &p_m_presetCache->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pPresetFilename + 1 - m_Size);
  CUtlString::operator=(this: &p_m_presetCache->m_Vector.m_Memory.m_pMemory[v4], src: pExpressionFilename);
  ExpressionFilesFromCachedPresets = CDmxEdit::CreateExpressionFilesFromCachedPresets(this);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)p_m_presetCache);
  CUtlSymbolTable::RemoveAll(this: &p_m_presetCache->m_SymbolTable);
  return ExpressionFilesFromCachedPresets;
}

//------------------------------------------------------------------------------
// Address: 0x00408C30
// Name: CreateExpressionFileFromPresets_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateExpressionFileFromPresets_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  const char *v2; // eax
  const char *v3; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  v2 = luaL_checklstring(L: pLuaState, narg: 2, len: nullptr);
  if ( !CDmxEdit::CreateExpressionFileFromPresets(
          this: &LuaFunc_s::m_dmxEdit,
          pPresetFilename: v1,
          pExpressionFilename: v2) )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v3 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v3);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408CB0
// Name: ReorderControls_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReorderControls_luaFunc(lua_State *pLuaState)
{
  int v1; // esi
  int v2; // ebx
  const char *v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  void *(__cdecl **v10)(const char *, int *); // ecx
  int v11; // esi
  CUtlString *v12; // eax
  const char *v14; // eax
  const char *v15; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > controlNames; // [esp+Ch] [ebp-50h] BYREF
  CUtlString src; // [esp+20h] [ebp-3Ch] BYREF
  CUtlString string; // [esp+30h] [ebp-2Ch] BYREF
  void *(__cdecl **pFactoryList)(const char *, int *); // [esp+40h] [ebp-1Ch]
  int nFactoryCount; // [esp+44h] [ebp-18h]
  int nCount; // [esp+48h] [ebp-14h]
  int i; // [esp+4Ch] [ebp-10h]
  int v23; // [esp+58h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  memset(&controlNames, 0, sizeof(controlNames));
  v1 = 1;
  v23 = 0;
  for ( i = 1; v1 <= lua_gettop(L: pLuaState); i = v1 )
  {
    if ( lua_type(L: pLuaState, idx: v1) == 5 )
    {
      v2 = 1;
      nCount = lua_objlen(L: pLuaState, idx: v1);
      if ( nCount >= 1 )
      {
        do
        {
          lua_rawgeti(L: pLuaState, idx: v1, n: v2);
          if ( lua_isstring(L: pLuaState, idx: -1) != 0 )
          {
            v3 = lua_tolstring(L: pLuaState, idx: -1, len: nullptr);
            CUtlString::CUtlString(this: &string, pString: v3);
            m_Size = controlNames.m_Size;
            LOBYTE(v23) = 1;
            v5 = controlNames.m_Size;
            if ( controlNames.m_Size + 1 > controlNames.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
                this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&controlNames,
                num: controlNames.m_Size - controlNames.m_Memory.m_nAllocationCount + 1);
              m_Size = controlNames.m_Size;
            }
            m_pMemory = controlNames.m_Memory.m_pMemory;
            controlNames.m_Size = m_Size + 1;
            v7 = m_Size - v5;
            controlNames.m_pElements = controlNames.m_Memory.m_pMemory;
            if ( v7 > 0 )
            {
              _V_memmove(
                dest: &controlNames.m_Memory.m_pMemory[v5 + 1],
                src: &controlNames.m_Memory.m_pMemory[v5],
                count: 16 * v7);
              m_pMemory = controlNames.m_Memory.m_pMemory;
            }
            v8 = v5;
            v9 = &m_pMemory[v8] == nullptr;
            v10 = (void *(__cdecl **)(const char *, int *))&m_pMemory[v8];
            nFactoryCount = (int)v10;
            pFactoryList = v10;
            LOBYTE(v23) = 2;
            if ( !v9 )
              CUtlString::CUtlString(this: (CUtlString *)v10, &string);
            LOBYTE(v23) = 0;
            string.m_Storage.m_nActualLength = 0;
            if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
                string.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              string.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            v1 = i;
          }
          lua_settop(L: pLuaState, idx: -2);
          ++v2;
        }
        while ( v2 <= nCount );
      }
    }
    else if ( lua_isstring(L: pLuaState, idx: v1) != 0 )
    {
      v14 = lua_tolstring(L: pLuaState, idx: v1, len: nullptr);
      CUtlString::CUtlString(this: &src, pString: v14);
      LOBYTE(v23) = 3;
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        this: &controlNames,
        elem: controlNames.m_Size,
        &src);
      LOBYTE(v23) = 0;
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
          src.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        src.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
    ++v1;
  }
  if ( controlNames.m_Size > 0 )
  {
    if ( CDmxEdit::ReorderControls(this: &LuaFunc_s::m_dmxEdit, &controlNames) != 0 )
    {
      v15 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
      _Msg(a1: "// %s\n", v15);
      lua_pushboolean(L: pLuaState, b: 1);
      v23 = -1;
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &controlNames);
      return 1;
    }
    v11 = CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
    v23 = -1;
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &controlNames);
  }
  else
  {
    v11 = CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState, pFormat: "No Controls Specified");
    v23 = 4;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&controlNames);
    v12 = controlNames.m_Memory.m_pMemory;
    if ( controlNames.m_Memory.m_nGrowSize >= 0 )
    {
      if ( controlNames.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlNames.m_Memory.m_pMemory);
        v12 = nullptr;
        controlNames.m_Memory.m_pMemory = nullptr;
      }
      controlNames.m_Memory.m_nAllocationCount = 0;
    }
    controlNames.m_pElements = v12;
    v23 = -1;
    if ( controlNames.m_Memory.m_nGrowSize >= 0 && v12 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      return v11;
    }
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x00408FC0
// Name: AddDominationRule_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddDominationRule_luaFunc(lua_State *pLuaState)
{
  int v1; // edi
  const char *v2; // eax
  int v3; // esi
  unsigned int v4; // eax
  int v5; // ecx
  const char *v6; // eax
  int m_Size; // eax
  int v8; // edi
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  int v11; // edi
  bool v12; // zf
  void *(__cdecl **v13)(const char *, int *); // ecx
  CUtlString *v14; // eax
  CUtlString *v15; // eax
  const char *v17; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dominators; // [esp+Ch] [ebp-54h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > supressed; // [esp+20h] [ebp-40h] BYREF
  CUtlString src; // [esp+34h] [ebp-2Ch] BYREF
  void *(__cdecl **pFactoryList)(const char *, int *); // [esp+44h] [ebp-1Ch]
  int nFactoryCount; // [esp+48h] [ebp-18h]
  signed int v23; // [esp+4Ch] [ebp-14h]
  int i; // [esp+50h] [ebp-10h]
  int v25; // [esp+5Ch] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  memset(&dominators, 0, sizeof(dominators));
  v25 = 0;
  if ( lua_type(L: pLuaState, idx: 1) == 5 )
  {
    v1 = 1;
    i = lua_objlen(L: pLuaState, idx: 1);
    if ( i >= 1 )
    {
      do
      {
        lua_rawgeti(L: pLuaState, idx: 1, n: v1);
        if ( lua_isstring(L: pLuaState, idx: -1) != 0 )
        {
          v2 = lua_tolstring(L: pLuaState, idx: -1, len: nullptr);
          CUtlString::CUtlString(this: &src, pString: v2);
          LOBYTE(v25) = 1;
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
            this: &dominators,
            elem: dominators.m_Size,
            &src);
          LOBYTE(v25) = 0;
          src.m_Storage.m_nActualLength = 0;
          if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
              src.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            src.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
        lua_settop(L: pLuaState, idx: -2);
        ++v1;
      }
      while ( v1 <= i );
    }
  }
  if ( dominators.m_Size > 0 )
  {
    memset(&supressed, 0, sizeof(supressed));
    LOBYTE(v25) = 2;
    if ( lua_type(L: pLuaState, idx: 2) == 5 )
    {
      v4 = lua_objlen(L: pLuaState, idx: 2);
      v5 = 1;
      v23 = v4;
      for ( i = 1; v5 <= v23; i = v5 )
      {
        lua_rawgeti(L: pLuaState, idx: 2, n: v5);
        if ( lua_isstring(L: pLuaState, idx: -1) != 0 )
        {
          v6 = lua_tolstring(L: pLuaState, idx: -1, len: nullptr);
          CUtlString::CUtlString(this: &src, pString: v6);
          m_Size = supressed.m_Size;
          LOBYTE(v25) = 3;
          v8 = supressed.m_Size;
          if ( supressed.m_Size + 1 > supressed.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&supressed,
              num: supressed.m_Size - supressed.m_Memory.m_nAllocationCount + 1);
            m_Size = supressed.m_Size;
          }
          m_pMemory = supressed.m_Memory.m_pMemory;
          supressed.m_Size = m_Size + 1;
          v10 = m_Size - v8;
          supressed.m_pElements = supressed.m_Memory.m_pMemory;
          if ( v10 > 0 )
          {
            _V_memmove(
              dest: &supressed.m_Memory.m_pMemory[v8 + 1],
              src: &supressed.m_Memory.m_pMemory[v8],
              count: 16 * v10);
            m_pMemory = supressed.m_Memory.m_pMemory;
          }
          v11 = v8;
          v12 = &m_pMemory[v11] == nullptr;
          v13 = (void *(__cdecl **)(const char *, int *))&m_pMemory[v11];
          nFactoryCount = (int)v13;
          pFactoryList = v13;
          LOBYTE(v25) = 4;
          if ( !v12 )
            CUtlString::CUtlString(this: (CUtlString *)v13, string: &src);
          LOBYTE(v25) = 2;
          src.m_Storage.m_nActualLength = 0;
          if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
              src.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            src.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
        lua_settop(L: pLuaState, idx: -2);
        v5 = i + 1;
      }
    }
    if ( supressed.m_Size <= 0 )
    {
      v3 = CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState, pFormat: "No Supressed Controls Specified");
      LOBYTE(v25) = 5;
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&supressed);
      v14 = supressed.m_Memory.m_pMemory;
      if ( supressed.m_Memory.m_nGrowSize >= 0 )
      {
        if ( supressed.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: supressed.m_Memory.m_pMemory);
          v14 = nullptr;
          supressed.m_Memory.m_pMemory = nullptr;
        }
        supressed.m_Memory.m_nAllocationCount = 0;
      }
      supressed.m_pElements = v14;
      LOBYTE(v25) = 0;
      if ( supressed.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v14 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
          supressed.m_Memory.m_pMemory = nullptr;
        }
        supressed.m_Memory.m_nAllocationCount = 0;
      }
      v25 = 6;
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&dominators);
      v15 = dominators.m_Memory.m_pMemory;
      if ( dominators.m_Memory.m_nGrowSize >= 0 )
      {
        if ( dominators.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dominators.m_Memory.m_pMemory);
          v15 = nullptr;
          dominators.m_Memory.m_pMemory = nullptr;
        }
        dominators.m_Memory.m_nAllocationCount = 0;
      }
      dominators.m_pElements = v15;
      v25 = -1;
      if ( dominators.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
        return v3;
      }
      return v3;
    }
    if ( CDmxEdit::AddDominationRule(this: &LuaFunc_s::m_dmxEdit, &dominators, &supressed) != 0 )
    {
      v17 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
      _Msg(a1: "// %s\n", v17);
      lua_pushboolean(L: pLuaState, b: 1);
      LOBYTE(v25) = 0;
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &supressed);
      v25 = -1;
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &dominators);
      return 1;
    }
    v3 = CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
    LOBYTE(v25) = 0;
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &supressed);
  }
  else
  {
    v3 = CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState, pFormat: "No Dominator Controls Specified");
  }
  v25 = -1;
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &dominators);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00409380
// Name: public: float CDmxEdit::DeltaRadius(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDmxEdit::DeltaRadius(CDmxEdit *this, float pDeltaName)
{
  CDmeMesh *m_pMesh; // ecx
  CDmeVertexData *BaseState; // edi
  CDmeMesh *v6; // ecx
  CDmeVertexDeltaData *DeltaState; // ebx
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // edi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v9; // ebx
  _DWORD *v10; // esi
  float *p_z; // ecx
  unsigned int v12; // edi
  char *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  int m_nGrowSize; // edi
  Vector *v17; // eax
  int m_Size; // [esp-4h] [ebp-44h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > newPos; // [esp+Ch] [ebp-34h] BYREF
  Vector center; // [esp+20h] [ebp-20h] BYREF
  Vector *m_pMemory; // [esp+2Ch] [ebp-14h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *deltaPos; // [esp+30h] [ebp-10h]
  int v23; // [esp+3Ch] [ebp-4h]

  m_pMesh = this->m_pMesh;
  if ( m_pMesh == nullptr )
    return 0.0;
  BaseState = CDmeMesh::FindBaseState(this: m_pMesh, pStateName: "bind");
  if ( BaseState == nullptr )
    return 0.0;
  v6 = this->m_pMesh;
  if ( v6 == nullptr )
    return 0.0;
  DeltaState = CDmeMesh::FindDeltaState(this: v6, pDeltaName: (const char *)LODWORD(pDeltaName), bSortDeltaName: true);
  if ( DeltaState == nullptr )
    return 0.0;
  PositionData = CDmeVertexDataBase::GetPositionData(this: BaseState);
  pDeltaName = COERCE_FLOAT(CDmeVertexDataBase::GetVertexIndexData(this: DeltaState, fieldId: FIELD_POSITION));
  v9 = CDmeVertexDataBase::GetPositionData(this: DeltaState);
  deltaPos = v9;
  memset(&newPos, 0, sizeof(newPos));
  m_Size = v9->m_Size;
  v23 = 0;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
    this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&newPos,
    elem: 0,
    num: m_Size);
  if ( newPos.m_Size > 0 )
  {
    v10 = *(_DWORD **)LODWORD(pDeltaName);
    m_pMemory = PositionData->m_Memory.m_pMemory;
    p_z = &newPos.m_Memory.m_pMemory->z;
    v12 = -8 - (unsigned int)newPos.m_Memory.m_pMemory;
    pDeltaName = *(float *)&newPos.m_Size;
    while ( 1 )
    {
      v13 = (char *)v9->m_Memory.m_pMemory + v12;
      v14 = *(float *)((char *)p_z + (_DWORD)v13 + 4) + m_pMemory[*v10].y;
      v15 = *(float *)((char *)p_z + (_DWORD)v13 + 8) + m_pMemory[*v10].z;
      *(p_z - 2) = *(float *)((char *)p_z + (_DWORD)v13) + m_pMemory[*v10].x;
      *(p_z - 1) = v14;
      *p_z = v15;
      ++v10;
      p_z += 3;
      --LODWORD(pDeltaName);
      if ( pDeltaName == 0.0 )
        break;
      v9 = deltaPos;
    }
  }
  pDeltaName = 0.0;
  FindBoundingSphere(points: &newPos, cen: &center, fRad: &pDeltaName);
  m_nGrowSize = newPos.m_Memory.m_nGrowSize;
  v17 = newPos.m_Memory.m_pMemory;
  v23 = 1;
  newPos.m_Size = 0;
  if ( newPos.m_Memory.m_nGrowSize >= 0 && newPos.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: newPos.m_Memory.m_pMemory);
    newPos.m_Memory.m_pMemory = nullptr;
    v17 = nullptr;
  }
  v23 = -1;
  if ( m_nGrowSize >= 0 && v17 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
  return pDeltaName;
}

//------------------------------------------------------------------------------
// Address: 0x00409520
// Name: DeltaRadius_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DeltaRadius_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  double n; // st7

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  n = CDmxEdit::DeltaRadius(this: &LuaFunc_s::m_dmxEdit, pDeltaName: *(float *)&v1);
  lua_pushnumber(L: pLuaState, n);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409570
// Name: public: float CDmxEdit::SelectionRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDmxEdit::SelectionRadius(CDmxEdit *this)
{
  CDmeMesh *m_pMesh; // ecx
  CDmeVertexData *CurrentBaseState; // edi
  CDmeSingleIndexedComponent *m_pCurrentSelection; // ecx
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // esi
  int v7; // edx
  Vector *m_pMemory; // edi
  int v9; // esi
  float *p_x; // eax
  Vector *v11; // ecx
  CUtlVector<int,CUtlMemory<int,int> > selection; // [esp+8h] [ebp-44h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > newPos; // [esp+1Ch] [ebp-30h] BYREF
  Vector center; // [esp+30h] [ebp-1Ch] BYREF
  float radius; // [esp+3Ch] [ebp-10h] BYREF
  int v16; // [esp+48h] [ebp-4h]

  if ( this->m_pCurrentSelection == nullptr )
    return 0.0;
  if ( this->m_pCurrentSelection->Count(this: this->m_pCurrentSelection) == 0 )
    return 0.0;
  m_pMesh = this->m_pMesh;
  if ( m_pMesh == nullptr )
    return 0.0;
  CurrentBaseState = CDmeMesh::GetCurrentBaseState(this: m_pMesh);
  if ( CurrentBaseState == nullptr )
    return 0.0;
  memset(&selection, 0, sizeof(selection));
  m_pCurrentSelection = this->m_pCurrentSelection;
  v16 = 0;
  CDmeSingleIndexedComponent::GetComponents(this: m_pCurrentSelection, components: &selection);
  PositionData = CDmeVertexDataBase::GetPositionData(this: CurrentBaseState);
  memset(&newPos, 0, sizeof(newPos));
  LOBYTE(v16) = 1;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
    this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&newPos,
    elem: 0,
    num: selection.m_Size);
  v7 = 0;
  if ( newPos.m_Size > 0 )
  {
    m_pMemory = PositionData->m_Memory.m_pMemory;
    v9 = 0;
    do
    {
      p_x = &m_pMemory[selection.m_Memory.m_pMemory[v7]].x;
      v11 = newPos.m_Memory.m_pMemory;
      newPos.m_Memory.m_pMemory[v9].x = *p_x;
      ++v7;
      v11[v9++].y = p_x[1];
      v11[v9 - 1].z = p_x[2];
    }
    while ( v7 < newPos.m_Size );
  }
  radius = 0.0;
  FindBoundingSphere(points: &newPos, cen: &center, fRad: &radius);
  LOBYTE(v16) = 0;
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&newPos);
  v16 = -1;
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&selection);
  return radius;
}

//------------------------------------------------------------------------------
// Address: 0x004096B0
// Name: SelectionRadius_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SelectionRadius_luaFunc(lua_State *pLuaState)
{
  double n; // st7

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  n = CDmxEdit::SelectionRadius(this: &LuaFunc_s::m_dmxEdit);
  lua_pushnumber(L: pLuaState, n);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004096F0
// Name: public: virtual CDmxEdit::~CDmxEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxEdit::~CDmxEdit(CDmxEdit *this)
{
  this->__vftable = (CDmxEdit_vtbl *)&CDmxEdit::`vftable';
  this->m_errorString.m_Storage.m_nActualLength = 0;
  if ( this->m_errorString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_errorString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_errorString.m_Storage.m_Memory.m_pMemory);
      this->m_errorString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_errorString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_sourceFile.m_Storage.m_nActualLength = 0;
  if ( this->m_sourceFile.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sourceFile.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sourceFile.m_Storage.m_Memory.m_pMemory);
      this->m_sourceFile.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sourceFile.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_funcString.m_Storage.m_nActualLength = 0;
  if ( this->m_funcString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_funcString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_funcString.m_Storage.m_Memory.m_pMemory);
      this->m_funcString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_funcString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_scriptFilename.m_Storage.m_nActualLength = 0;
  if ( this->m_scriptFilename.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_scriptFilename.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_scriptFilename.m_Storage.m_Memory.m_pMemory);
      this->m_scriptFilename.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_scriptFilename.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_presetCache.m_SymbolTable);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &this->m_presetCache.m_Vector);
  this->m_filename.m_Storage.m_nActualLength = 0;
  if ( this->m_filename.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_filename.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_filename.m_Storage.m_Memory.m_pMemory);
      this->m_filename.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_filename.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409880
// Name: public: CDmxEdit::CDmxEdit(void)
// Source: json
//------------------------------------------------------------------------------
CDmxEdit *__thiscall CDmxEdit::CDmxEdit(CDmxEdit *this)
{
  this->__vftable = (CDmxEdit_vtbl *)&CDmxEdit::`vftable';
  CUtlString::CUtlString(this: &this->m_filename);
  this->m_pRoot = nullptr;
  this->m_pMesh = nullptr;
  this->m_pCurrentSelection = nullptr;
  this->m_distanceType.m_distanceType = DIST_ABSOLUTE;
  this->m_presetCache.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_presetCache.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_presetCache.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_presetCache.m_Vector.m_Size = 0;
  this->m_presetCache.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_presetCache.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  CUtlString::CUtlString(this: &this->m_scriptFilename);
  CUtlString::CUtlString(this: &this->m_funcString);
  CUtlString::CUtlString(this: &this->m_sourceFile);
  CUtlString::CUtlString(this: &this->m_errorString);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409940
// Name: public: bool CDmxEdit::CreateDeltasFromPresets(char const __near *,bool,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxEdit::CreateDeltasFromPresets(
        CDmxEdit *this,
        const char *pPresetFilename,
        bool bPurge,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pPurgeAllButThese,
        const char *pExpressionFilename)
{
  CUtlStringMap<CUtlString> *p_m_presetCache; // esi
  int v6; // ebx
  int m_Size; // ecx
  bool DeltasFromPresets; // bl

  p_m_presetCache = &this->m_presetCache;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_presetCache);
  CUtlSymbolTable::RemoveAll(this: &p_m_presetCache->m_SymbolTable);
  CUtlSymbolTable::AddString(
    this: &p_m_presetCache->m_SymbolTable,
    result: (CUtlSymbol *)&pPresetFilename,
    pString: pPresetFilename);
  v6 = (unsigned __int16)pPresetFilename;
  m_Size = p_m_presetCache->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pPresetFilename && m_Size < (unsigned __int16)pPresetFilename + 1 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
      this: &p_m_presetCache->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pPresetFilename + 1 - m_Size);
  CUtlString::operator=(this: &p_m_presetCache->m_Vector.m_Memory.m_pMemory[v6], src: pExpressionFilename);
  DeltasFromPresets = CDmMeshUtils::CreateDeltasFromPresets(
                        pMesh: this->m_pMesh,
                        pPassedDst: nullptr,
                        presetExpressionMap: p_m_presetCache,
                        bPurge,
                        pPurgeAllButThese);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)p_m_presetCache);
  CUtlSymbolTable::RemoveAll(this: &p_m_presetCache->m_SymbolTable);
  return DeltasFromPresets;
}

//------------------------------------------------------------------------------
// Address: 0x004099D0
// Name: CreateDeltasFromPresets_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateDeltasFromPresets_luaFunc(lua_State *pLuaState)
{
  const char *v1; // eax
  int m_Size; // eax
  int v3; // esi
  CUtlString *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  bool v7; // zf
  void *(__cdecl **v8)(const char *, int *); // ecx
  const char *v9; // eax
  int v11; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > purgeAllBut; // [esp+Ch] [ebp-48h] BYREF
  CUtlString string; // [esp+20h] [ebp-34h] BYREF
  void *(__cdecl **pFactoryList)(const char *, int *); // [esp+30h] [ebp-24h]
  int nFactoryCount; // [esp+34h] [ebp-20h]
  const char *pPresetFilename; // [esp+38h] [ebp-1Ch]
  BOOL bPurge; // [esp+3Ch] [ebp-18h]
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pPurgeAllBut; // [esp+40h] [ebp-14h]
  const char *pExpressionFilename; // [esp+44h] [ebp-10h]
  int v20; // [esp+50h] [ebp-4h]

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  pPresetFilename = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  LOBYTE(bPurge) = lua_type(L: pLuaState, idx: 2) != 1 || lua_toboolean(L: pLuaState, idx: 2) != 0;
  if ( lua_isstring(L: pLuaState, idx: 4) != 0 )
    pExpressionFilename = lua_tolstring(L: pLuaState, idx: 4, len: nullptr);
  else
    pExpressionFilename = nullptr;
  memset(&purgeAllBut, 0, sizeof(purgeAllBut));
  v20 = 0;
  pPurgeAllBut = nullptr;
  if ( lua_type(L: pLuaState, idx: 3) == 5 )
  {
    pPurgeAllBut = &purgeAllBut;
    lua_pushnil(L: pLuaState);
    while ( lua_next(L: pLuaState, idx: 3) != 0 )
    {
      v1 = lua_tolstring(L: pLuaState, idx: -1, len: nullptr);
      CUtlString::CUtlString(this: &string, pString: v1);
      m_Size = purgeAllBut.m_Size;
      LOBYTE(v20) = 1;
      v3 = purgeAllBut.m_Size;
      if ( purgeAllBut.m_Size + 1 > purgeAllBut.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
          this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&purgeAllBut,
          num: purgeAllBut.m_Size - purgeAllBut.m_Memory.m_nAllocationCount + 1);
        m_Size = purgeAllBut.m_Size;
      }
      m_pMemory = purgeAllBut.m_Memory.m_pMemory;
      purgeAllBut.m_Size = m_Size + 1;
      v5 = m_Size - v3;
      purgeAllBut.m_pElements = purgeAllBut.m_Memory.m_pMemory;
      if ( v5 > 0 )
      {
        _V_memmove(
          dest: &purgeAllBut.m_Memory.m_pMemory[v3 + 1],
          src: &purgeAllBut.m_Memory.m_pMemory[v3],
          count: 16 * v5);
        m_pMemory = purgeAllBut.m_Memory.m_pMemory;
      }
      v6 = v3;
      v7 = &m_pMemory[v6] == nullptr;
      v8 = (void *(__cdecl **)(const char *, int *))&m_pMemory[v6];
      nFactoryCount = (int)v8;
      pFactoryList = v8;
      LOBYTE(v20) = 2;
      if ( !v7 )
        CUtlString::CUtlString(this: (CUtlString *)v8, &string);
      LOBYTE(v20) = 0;
      string.m_Storage.m_nActualLength = 0;
      if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
          string.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        string.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      lua_settop(L: pLuaState, idx: -2);
    }
  }
  if ( CDmxEdit::CreateDeltasFromPresets(
         this: &LuaFunc_s::m_dmxEdit,
         pPresetFilename,
         bPurge,
         pPurgeAllButThese: pPurgeAllBut,
         pExpressionFilename) )
  {
    v9 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
    _Msg(a1: "// %s\n", v9);
    lua_pushboolean(L: pLuaState, b: 1);
    v20 = -1;
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &purgeAllBut);
    return 1;
  }
  else
  {
    v11 = CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
    v20 = -1;
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &purgeAllBut);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409D40
// Name: public: CDmObjSerializer::CDmObjSerializer(void)
// Source: json
//------------------------------------------------------------------------------
CDmObjSerializer *__thiscall CDmObjSerializer::CDmObjSerializer(CDmObjSerializer *this)
{
  this->__vftable = (CDmObjSerializer_vtbl *)&CDmObjSerializer::`vftable';
  this->m_mtlLib.m_Memory.m_pMemory = nullptr;
  this->m_mtlLib.m_Memory.m_nAllocationCount = 0;
  this->m_mtlLib.m_Memory.m_nGrowSize = 0;
  this->m_mtlLib.m_Size = 0;
  this->m_mtlLib.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_objDirectory);
  this->m_deltas.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_deltas.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_deltas.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_deltas.m_Vector.m_Size = 0;
  this->m_deltas.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_deltas.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409DC0
// Name: public: virtual char const __near * CDmObjSerializer::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmObjSerializer::GetName(CDmObjSerializer *this)
{
  return "obj";
}

//------------------------------------------------------------------------------
// Address: 0x00409DD0
// Name: public: virtual char const __near * CDmObjSerializer::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmObjSerializer::GetDescription(CDmObjSerializer *this)
{
  return "Wavefront OBJ";
}

//------------------------------------------------------------------------------
// Address: 0x00409DE0
// Name: public: CDmObjSerializer::~CDmObjSerializer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmObjSerializer::~CDmObjSerializer(CDmObjSerializer *this)
{
  CUtlStringMap<CDmObjSerializer::DeltaInfo_t> *p_m_deltas; // edi

  p_m_deltas = &this->m_deltas;
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_deltas.m_SymbolTable);
  CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>::~CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>(this: &p_m_deltas->m_Vector);
  this->m_objDirectory.m_Storage.m_nActualLength = 0;
  if ( this->m_objDirectory.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_objDirectory.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_objDirectory.m_Storage.m_Memory.m_pMemory);
      this->m_objDirectory.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_objDirectory.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CDmObjSerializer::MtlInfo_t,CUtlMemory<CDmObjSerializer::MtlInfo_t,int>>::~CUtlVector<CDmObjSerializer::MtlInfo_t,CUtlMemory<CDmObjSerializer::MtlInfo_t,int>>(this: &this->m_mtlLib);
}

//------------------------------------------------------------------------------
// Address: 0x00409E70
// Name: public: bool CDmxEdit::Save(char const __near *,class CDmxEdit::CObjType const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDmxEdit::Save@<al>(
        CDmxEdit *this@<ecx>,
        int a2@<ebx>,
        const char *pFilename,
        const CDmxEdit::CObjType *saveType,
        const char *pDeltaName)
{
  CDmElement *m_pRoot; // ecx
  int v9; // eax
  CP4File *v10; // eax
  CP4File *v11; // eax
  char v12; // bl
  CDmObjSerializer *v13; // eax
  bool v14; // al
  CDmObjSerializer *v15; // ecx
  CDmObjSerializer *v16; // eax
  CDmObjSerializer *v17; // eax
  CDmElement *v18; // [esp-14h] [ebp-128h]
  CDmElement *v19; // [esp-14h] [ebp-128h]
  CDmElement *v20; // [esp-14h] [ebp-128h]
  CDmObjSerializer v21; // [esp+8h] [ebp-10Ch] BYREF
  CDmObjSerializer v22; // [esp+88h] [ebp-8Ch] BYREF
  int v23; // [esp+110h] [ebp-4h]
  bool absolute; // [esp+11Ch] [ebp+8h]

  if ( pFilename == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Filename Specified");
  m_pRoot = this->m_pRoot;
  if ( m_pRoot == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "No Dmx Root Object To Save");
  CDmElement::RemoveAttribute(this: m_pRoot, pAttributeName: "vsDmxIO_exportTags");
  CDmxEdit::AddExportTags(this, pRoot: this->m_pRoot, (int)pFilename);
  CDmxEdit::UpdateMakefile(this, pRoot: (int)this->m_pRoot);
  CDmxEdit::CleanupWork(this);
  v9 = _V_strlen(str: pFilename);
  if ( v9 <= 4 || _V_stricmp(s1: &pFilename[v9 - 4], s2: ".dmx") != 0 )
  {
    absolute = saveType->m_objType != kRelative;
    if ( pDeltaName != nullptr )
    {
      if ( _V_stricmp(s1: "base", s2: pDeltaName) != 0 )
      {
        v16 = CDmObjSerializer::CDmObjSerializer(this: &v22);
        v19 = this->m_pRoot;
        v23 = 1;
        v14 = CDmObjSerializer::WriteOBJ(this: v16, pFilename, pRoot: v19, bWriteOBJs: true, pDeltaName, absolute);
      }
      else
      {
        v13 = CDmObjSerializer::CDmObjSerializer(this: &v22);
        v18 = this->m_pRoot;
        v23 = 0;
        v14 = CDmObjSerializer::WriteOBJ(
                this: v13,
                pFilename,
                pRoot: v18,
                bWriteOBJs: false,
                pDeltaName: nullptr,
                absolute);
      }
      v15 = &v22;
    }
    else
    {
      v17 = CDmObjSerializer::CDmObjSerializer(this: &v21);
      v20 = this->m_pRoot;
      v23 = 2;
      v14 = CDmObjSerializer::WriteOBJ(
              this: v17,
              pFilename,
              pRoot: v20,
              bWriteOBJs: true,
              pDeltaName: nullptr,
              absolute);
      v15 = &v21;
    }
    v12 = v14;
    v23 = -1;
    CDmObjSerializer::~CDmObjSerializer(this: v15);
  }
  else
  {
    v10 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pFilename);
    if ( ((unsigned __int8 (__thiscall *)(CP4File *, int))v10->Edit)(a1: v10, a2) == 0 )
    {
      v11 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pFilename);
      v11->Add(this: v11);
    }
    v12 = ((int (__thiscall *)(IDataModel *, const char *, _DWORD, const char *, const char *))g_pDataModel->SaveToFile)(
            a1: g_pDataModel,
            a2: pFilename,
            a3: 0,
            a4: "keyvalues2",
            a5: "model");
    if ( v12 == 0 )
      CDmxEdit::SetErrorString(this, pFormat: "Cannot Write File");
  }
  CDmxEdit::CreateWork(this);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x0040A080
// Name: public: bool CDmxEdit::Load(char const __near *,class CDmxEdit::CObjType const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Load(CDmxEdit *this, int pFilename, CDmeMesh *loadType)
{
  CDmxEdit *v3; // ebx
  const char *v4; // edi
  int v5; // eax
  CDmElement **p_m_pRoot; // esi
  CP4File *v8; // eax
  const CDmxEdit::CObjType *v9; // esi
  int m_Size; // eax
  CDmeDag *v11; // esi
  int v12; // edi
  CDmeDag *Child; // ebx
  CDmeDag **v14; // eax
  CDmeShape *Shape; // eax
  CDmxEdit::CObjType *v16; // esi
  const char *m_objType; // eax
  CDmeMesh *m_pMesh; // ecx
  CDmeVertexData *BaseState; // esi
  CDmeVertexData *v20; // eax
  DmElementHandle_t v21; // eax
  CDmElement *v22; // eax
  CDmElement *v23; // esi
  CExpressionCalculator *v24; // ecx
  const char *m_pAsString; // eax
  CDmElement *v26; // esi
  CDmAttribute *Attribute; // eax
  bool v28; // [esp-4h] [ebp-B8h]
  CDmObjSerializer v29; // [esp+Ch] [ebp-A8h] BYREF
  CDmeDag *pDag; // [esp+8Ch] [ebp-28h] BYREF
  CDmxEdit *p_m_deltas; // [esp+90h] [ebp-24h]
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > traverseStack; // [esp+94h] [ebp-20h] BYREF
  int v33; // [esp+B0h] [ebp-4h]

  v3 = this;
  p_m_deltas = this;
  CDmxEdit::Unload(this);
  v4 = (const char *)pFilename;
  v5 = _V_strlen(str: (const char *)pFilename);
  if ( v5 <= 4 || _V_stricmp(s1: &v4[v5 - 4], s2: ".dmx") != 0 )
  {
    v29.__vftable = (CDmObjSerializer_vtbl *)&CDmObjSerializer::`vftable';
    memset(&v29.m_mtlLib, 0, sizeof(v29.m_mtlLib));
    v33 = 1;
    CUtlString::CUtlString(this: &v29.m_objDirectory);
    p_m_deltas = (CDmxEdit *)&v29.m_deltas;
    v29.m_deltas.m_Vector.m_Memory.m_pMemory = nullptr;
    v29.m_deltas.m_Vector.m_Memory.m_nAllocationCount = 0;
    v29.m_deltas.m_Vector.m_Memory.m_nGrowSize = 32;
    v29.m_deltas.m_Vector.m_Size = 0;
    v29.m_deltas.m_Vector.m_pElements = nullptr;
    LOBYTE(v33) = 3;
    CUtlSymbolTable::CUtlSymbolTable(
      this: &v29.m_deltas.m_SymbolTable,
      growSize: 0,
      initSize: 32,
      caseInsensitive: true);
    v28 = loadType->__vftable == nullptr;
    v33 = 4;
    v3->m_pRoot = CDmObjSerializer::ReadOBJ(
                    this: &v29,
                    pFilename: v4,
                    ppCreatedMesh: &v3->m_pMesh,
                    bLoadAllDeltas: true,
                    bAbsolute: v28);
    v33 = -1;
    CDmObjSerializer::~CDmObjSerializer(this: &v29);
    if ( v3->m_pRoot != nullptr )
      goto LABEL_32;
    return CDmxEdit::SetErrorString(this: v3, pFormat: "OBJ Load Failed");
  }
  p_m_pRoot = &v3->m_pRoot;
  g_pDataModel->RestoreFromFile(
    this: g_pDataModel,
    a2: v4,
    a3: nullptr,
    a4: nullptr,
    a5: &v3->m_pRoot,
    a6: CR_DELETE_NEW,
    a7: nullptr);
  if ( v3->m_pRoot == nullptr )
    return CDmxEdit::SetErrorString(this: v3, pFormat: "DMX Load Failed");
  v8 = CP4Factory::AccessFile(this: g_p4factory, szFilename: v4);
  v8->Add(this: v8);
  pDag = CDmElement::GetValueElement<CDmeDag>(this: *p_m_pRoot, pAttributeName: "model");
  if ( pDag == nullptr )
  {
    m_pAsString = (*p_m_pRoot)->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    CDmxEdit::LuaWarning(
      this: v3,
      pFormat: "Cannot Find A DmeModel As Element Dme Root Object: %s in %s",
      m_pAsString,
      v4);
    goto LABEL_32;
  }
  v9 = nullptr;
  loadType = nullptr;
  memset(&traverseStack, 0, sizeof(traverseStack));
  v33 = 0;
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int>>::Push(this: &traverseStack, src: &pDag);
  m_Size = traverseStack.m_Size;
  if ( traverseStack.m_Size == 0 )
    goto LABEL_25;
  while ( 1 )
  {
    v11 = traverseStack.m_Memory.m_pMemory[--m_Size];
    traverseStack.m_Size = m_Size;
    if ( v11 != nullptr )
      break;
LABEL_21:
    if ( m_Size == 0 )
      goto LABEL_24;
  }
  v12 = CDmElementFramework::GetPhase(this: v11) - 1;
  if ( v12 >= 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this: v11, i: v12);
      if ( traverseStack.m_Size >= traverseStack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&traverseStack,
          num: 1);
      traverseStack.m_pElements = traverseStack.m_Memory.m_pMemory;
      v14 = &traverseStack.m_Memory.m_pMemory[traverseStack.m_Size++];
      if ( v14 != nullptr )
        *v14 = Child;
      --v12;
    }
    while ( v12 >= 0 );
    v3 = p_m_deltas;
  }
  Shape = CDmeDag::GetShape(this: v11);
  v16 = (CDmxEdit::CObjType *)Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
  {
    if ( loadType == nullptr )
      loadType = (CDmeMesh *)v16;
    if ( CDmeMesh::DeltaStateCount(this: (CDmeMesh *)v16) != 0 )
    {
      v4 = (const char *)pFilename;
      v3->m_pMesh = (CDmeMesh *)v16;
LABEL_24:
      v9 = (const CDmxEdit::CObjType *)loadType;
LABEL_25:
      if ( v3->m_pMesh == nullptr )
      {
        if ( v9 != nullptr )
        {
          v3->m_pMesh = (CDmeMesh *)v9;
          m_objType = (const char *)v9[5].m_objType;
          if ( m_objType == (const char *)-1 )
            m_objType = var;
          CDmxEdit::LuaWarning(
            this: v3,
            pFormat: "Cannot Find A DmeMesh With Any Delta States In File, Using First Found Mesh %s",
            m_objType);
        }
        else
        {
          CDmxEdit::LuaWarning(this: v3, pFormat: "Cannot Find A DmeMesh In File");
        }
      }
      v33 = -1;
      CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&traverseStack);
LABEL_32:
      CUtlString::operator=(this: &v3->m_filename, src: v4);
      m_pMesh = v3->m_pMesh;
      if ( m_pMesh != nullptr )
      {
        BaseState = CDmeMesh::FindBaseState(this: m_pMesh, pStateName: "bind");
        if ( BaseState != nullptr )
        {
          v20 = CDmeMesh::FindOrCreateBaseState(this: v3->m_pMesh, pStateName: "__dmxEdit_work");
          if ( v20 != nullptr )
          {
            CDmeVertexDataBase::CopyTo(this: BaseState, pDst: v20);
            CDmeMesh::SetCurrentBaseState(this: v3->m_pMesh, pStateName: "__dmxEdit_work");
          }
        }
        v21 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                a1: g_pDataModel,
                a2: (CUtlSymbolLarge)CDmeSingleIndexedComponent::m_classType.u.m_Id,
                a3: "selection",
                a4: v3->m_pRoot->m_fileId,
                a5: nullptr);
        v22 = g_pDataModel->GetElement(this: g_pDataModel, a2: v21);
        v23 = v22;
        if ( v22 != nullptr && v22->IsA(this: v22, a2: CDmeSingleIndexedComponent::m_classType) )
          v24 = (CExpressionCalculator *)v23;
        else
          v24 = nullptr;
        v26 = v3->m_pMesh;
        v3->m_pCurrentSelection = (CDmeSingleIndexedComponent *)v24;
        if ( v24 != nullptr )
          pFilename = CExpressionCalculator::VariableCount(this: v24);
        else
          pFilename = -1;
        Attribute = CDmElement::FindAttribute(this: v26, pAttributeName: "selection");
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: v26, pAttributeName: "selection", type: AT_FIRST_VALUE_TYPE)) != nullptr )
        {
          CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (const DmElementHandle_t *)&pFilename);
        }
      }
      return 1;
    }
  }
  m_Size = traverseStack.m_Size;
  v4 = (const char *)pFilename;
  goto LABEL_21;
}

//------------------------------------------------------------------------------
// Address: 0x0040A460
// Name: Load_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Load_luaFunc(lua_State *pLuaState)
{
  const char *v1; // edi
  bool v2; // zf
  const char *v3; // eax
  char v4; // al
  CDmxEdit::CObjType::Obj_t v5; // eax
  char v6; // al
  const char *v7; // eax
  CDmxEdit::CObjType loadType; // [esp+8h] [ebp-4h] BYREF

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_type(L: pLuaState, idx: 2) == 1 )
  {
    v2 = lua_toboolean(L: pLuaState, idx: 2) == 0;
    goto LABEL_7;
  }
  if ( lua_isstring(L: pLuaState, idx: 2) != 0 )
  {
    v3 = lua_tolstring(L: pLuaState, idx: 2, len: nullptr);
    if ( v3 != nullptr )
    {
      v4 = *v3;
      if ( v4 != 114 )
      {
        v2 = v4 == 82;
LABEL_7:
        if ( !v2 )
        {
          v5 = kAbsolute;
          goto LABEL_10;
        }
      }
      v5 = kRelative;
LABEL_10:
      loadType.m_objType = v5;
      v6 = CDmxEdit::Load(this: &LuaFunc_s::m_dmxEdit, pFilename: (int)v1, (CDmeMesh *)&loadType);
      goto LABEL_11;
    }
  }
  v6 = CDmxEdit::Load(this: &LuaFunc_s::m_dmxEdit, pFilename: (int)v1, loadType: (CDmeMesh *)&CDmxEdit::ABSOLUTE);
LABEL_11:
  if ( v6 == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v7 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v7);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A530
// Name: public: bool CDmxEdit::Import(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxEdit::Import(CDmxEdit *this, CDmeDag *pFilename, const char *pParentName)
{
  CDmElement *m_pRoot; // ecx
  CDmeModel *Value; // edi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v8; // al
  IDataModel_vtbl *v9; // edx
  DmFileId_t (__thiscall *RestoreFromFile)(IDataModel *, const char *, const char *, const char *, CDmElement **, DmConflictResolution_t, DmxHeader_t *); // edx
  bool v11; // bl
  CP4File *v12; // eax
  bool v13; // bl
  int JointCount; // ebx
  int v15; // esi
  const char *m_pAsString; // eax
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  int v19; // ebx
  CDmeDag *v20; // ebx
  int v21; // eax
  CDmeMesh *Shape; // ebx
  int m_nGrowSize; // esi
  void (__thiscall *SetUndoEnabled)(IDataModel *, bool); // edx
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > traverseStack; // [esp+Ch] [ebp-34h] BYREF
  CDisableUndoScopeGuard sgDisableUndo; // [esp+20h] [ebp-20h] BYREF
  int nSkinningJointIndex; // [esp+28h] [ebp-18h]
  CDmElement *pRoot; // [esp+2Ch] [ebp-14h] BYREF
  CDmxEdit *v29; // [esp+30h] [ebp-10h]
  int v30; // [esp+3Ch] [ebp-4h]
  CDmeDag *pSrcModel; // [esp+48h] [ebp+8h]
  CDmeDag *pSrcModela; // [esp+48h] [ebp+8h]
  CDmeDag *i; // [esp+4Ch] [ebp+Ch]
  int ia; // [esp+4Ch] [ebp+Ch]

  m_pRoot = this->m_pRoot;
  v29 = this;
  if ( m_pRoot == nullptr )
    return CDmxEdit::Load(this, (int)pFilename, loadType: (CDmeMesh *)&CDmxEdit::ABSOLUTE);
  Value = CDmElement::GetValueElement<CDmeModel>(this: m_pRoot, pAttributeName: "model");
  if ( Value == nullptr )
    return CDmxEdit::SetErrorString(this, pFormat: "Can't Find Existing Model Node");
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  *(_WORD *)&sgDisableUndo.m_bReleased = 0;
  sgDisableUndo.m_pNotify = nullptr;
  v8 = IsUndoEnabled(this: g_pDataModel);
  v9 = g_pDataModel->__vftable;
  sgDisableUndo.m_bOldValue = v8;
  v9->SetUndoEnabled(this: g_pDataModel, a2: false);
  pRoot = nullptr;
  RestoreFromFile = g_pDataModel->RestoreFromFile;
  v30 = 0;
  RestoreFromFile(
    this: g_pDataModel,
    a2: (const char *)pFilename,
    a3: nullptr,
    a4: nullptr,
    a5: &pRoot,
    a6: CR_FORCE_COPY,
    a7: nullptr);
  if ( pRoot != nullptr )
  {
    v12 = CP4Factory::AccessFile(this: g_p4factory, szFilename: (const char *)pFilename);
    v12->Add(this: v12);
    pSrcModel = CDmElement::GetValueElement<CDmeDag>(this: pRoot, pAttributeName: "model");
    if ( pSrcModel != nullptr )
    {
      nSkinningJointIndex = -1;
      if ( pParentName != nullptr )
      {
        JointCount = CDmeModel::GetJointCount(this: Value);
        v15 = 0;
        if ( JointCount <= 0 )
          goto LABEL_17;
        while ( 1 )
        {
          m_pAsString = CDmeModel::GetJoint(this: Value, nIndex: v15)->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = var;
          if ( _V_stricmp(s1: m_pAsString, s2: pParentName) == 0 )
            break;
          if ( ++v15 >= JointCount )
            goto LABEL_17;
        }
        nSkinningJointIndex = v15;
        if ( v15 < 0 )
LABEL_17:
          CDmxEdit::LuaWarning(this: v29, pFormat: "Couldn't Find Parent Bone \"%s\"", pParentName);
      }
      CDmxEdit::CleanupWork(this: v29);
      m_pMemory = nullptr;
      m_Size = 0;
      memset(&traverseStack, 0, sizeof(traverseStack));
      LOBYTE(v30) = 1;
      v19 = CDmElementFramework::GetPhase(this: pSrcModel) - 1;
      if ( v19 >= 0 )
      {
        do
        {
          i = CDmeDag::GetChild(this: pSrcModel, i: v19);
          if ( m_Size >= traverseStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&traverseStack,
              num: 1);
            m_Size = traverseStack.m_Size;
            m_pMemory = traverseStack.m_Memory.m_pMemory;
          }
          traverseStack.m_Size = ++m_Size;
          traverseStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = i;
          --v19;
        }
        while ( v19 >= 0 );
        while ( m_Size != 0 )
        {
          v20 = m_pMemory[--m_Size];
          traverseStack.m_Size = m_Size;
          if ( v20 != nullptr )
          {
            v21 = CDmElementFramework::GetPhase(this: v20) - 1;
            ia = v21;
            if ( v21 >= 0 )
            {
              while ( 1 )
              {
                pSrcModela = CDmeDag::GetChild(this: v20, i: v21);
                if ( m_Size >= traverseStack.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<IDmFormatUpdater *,int>::Grow(
                    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&traverseStack,
                    num: 1);
                  m_Size = traverseStack.m_Size;
                  m_pMemory = traverseStack.m_Memory.m_pMemory;
                }
                traverseStack.m_Size = ++m_Size;
                traverseStack.m_pElements = m_pMemory;
                if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
                  m_pMemory[m_Size - 1] = pSrcModela;
                if ( --ia < 0 )
                  break;
                v21 = ia;
              }
            }
            Shape = (CDmeMesh *)CDmeDag::GetShape(this: v20);
            if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
              CDmMeshUtils::Merge(pSrcMesh: Shape, pDstMesh: v29->m_pMesh, nSkinningJointIndex, pJointMap: nullptr);
          }
        }
      }
      g_pDataModel->UnloadFile(this: g_pDataModel, a2: pRoot->m_fileId);
      CDmxEdit::CreateWork(this: v29);
      m_nGrowSize = traverseStack.m_Memory.m_nGrowSize;
      LOBYTE(v30) = 2;
      traverseStack.m_Size = 0;
      if ( traverseStack.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
      }
      LOBYTE(v30) = 0;
      if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      SetUndoEnabled = g_pDataModel->SetUndoEnabled;
      v30 = -1;
      SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sgDisableUndo.m_bOldValue);
      return 1;
    }
    else
    {
      g_pDataModel->UnloadFile(this: g_pDataModel, a2: pRoot->m_fileId);
      v13 = CDmxEdit::SetErrorString(this: v29, pFormat: "Can't Find \"model\" Element On Root Node In DMX File");
      v30 = -1;
      CChangeUndoScopeGuard::Release(this: &sgDisableUndo);
      return v13;
    }
  }
  else
  {
    v11 = CDmxEdit::SetErrorString(this: v29, pFormat: "Can't Load DMX File");
    v30 = -1;
    CChangeUndoScopeGuard::Release(this: &sgDisableUndo);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A8D0
// Name: Import_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Import_luaFunc(lua_State *pLuaState)
{
  CDmeDag *v1; // edi
  const char *v2; // eax
  const char *v3; // eax

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = (CDmeDag *)luaL_checklstring(L: pLuaState, narg: 1, len: nullptr);
  if ( lua_isstring(L: pLuaState, idx: 2) != 0 )
    v2 = lua_tolstring(L: pLuaState, idx: 2, len: nullptr);
  else
    v2 = nullptr;
  if ( CDmxEdit::Import(this: &LuaFunc_s::m_dmxEdit, pFilename: v1, pParentName: v2) == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v3 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v3);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A960
// Name: Save_luaFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Save_luaFunc(lua_State *pLuaState)
{
  const char *v1; // ebx
  const char *v2; // edi
  const char *v3; // eax
  CDmxEdit::CObjType::Obj_t v4; // ecx
  char v5; // al
  const char *v6; // eax
  const char *v8; // [esp-Ch] [ebp-1Ch]
  CDmxEdit::CObjType *p_saveType; // [esp-8h] [ebp-18h]
  const char *v10; // [esp-4h] [ebp-14h]
  CDmxEdit::CObjType saveType; // [esp+Ch] [ebp-4h] BYREF

  CDmxEdit::SetFuncString(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v1 = lua_tolstring(L: pLuaState, idx: 1, len: nullptr);
  v2 = nullptr;
  if ( lua_type(L: pLuaState, idx: 2) == 1 )
  {
    if ( lua_toboolean(L: pLuaState, idx: 2) != 0 )
      v2 = "Absolute";
    else
      v2 = "Relative";
  }
  else if ( lua_isstring(L: pLuaState, idx: 2) != 0 )
  {
    v2 = lua_tolstring(L: pLuaState, idx: 2, len: nullptr);
  }
  if ( v1 != nullptr )
  {
    if ( v2 != nullptr )
    {
      if ( lua_isstring(L: pLuaState, idx: 3) != 0 )
        v3 = lua_tolstring(L: pLuaState, idx: 3, len: nullptr);
      else
        v3 = nullptr;
      v4 = *v2 == 114 || *v2 == 82;
      v10 = v3;
      saveType.m_objType = v4;
      p_saveType = &saveType;
    }
    else
    {
      v10 = nullptr;
      p_saveType = &CDmxEdit::ABSOLUTE;
    }
    v5 = CDmxEdit::Save(this: &LuaFunc_s::m_dmxEdit, a2: (int)v1, pFilename: v1, saveType: p_saveType, pDeltaName: v10);
  }
  else
  {
    v8 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_filename);
    v5 = CDmxEdit::Save(
           this: &LuaFunc_s::m_dmxEdit,
           a2: 0,
           pFilename: v8,
           saveType: &CDmxEdit::ABSOLUTE,
           pDeltaName: nullptr);
  }
  if ( v5 == 0 )
    return CDmxEdit::LuaError(this: &LuaFunc_s::m_dmxEdit, pLuaState);
  v6 = CUtlString::operator char const *(this: &LuaFunc_s::m_dmxEdit.m_funcString);
  _Msg(a1: "// %s\n", v6);
  lua_pushboolean(L: pLuaState, b: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00410670
// Name: public: class CUtlSymbolLarge const __near & CDmAttribute::GetValue<class CUtlSymbolLarge>(void)const
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__thiscall CDmAttribute::GetValue<CUtlSymbolLarge>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  if ( (this->m_nFlags & 0x1F) == 5 )
    return (DmElementHandle_t *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<CUtlSymbolLarge>(this) )
    return (DmElementHandle_t *)&`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal = DMELEMENT_HANDLE_INVALID;
  }
  CDmAttribute::CopyDataOut<enum DmElementHandle_t>(
    this,
    value: &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal);
  return &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x00410F40
// Name: public: class CDmElement __near * CDmAttribute::GetValueElement<class CDmElement>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAttribute::GetValueElement<CDmElement>(CDmAttribute *this)
{
  CDmaVar<enum DmElementHandle_t> *v1; // eax
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( (this->m_nFlags & 0x1F) == 1
    && (v1 = CDmAttribute::GetValue<enum DmElementHandle_t>(this),
        v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_Storage.m_Handle),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmElement::m_classType) )
  {
    return v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D360
// Name: private: void CDmAttribute::CopyDataOut<class DmeTime_t>(class DmeTime_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyDataOut<DmeTime_t>(CDmAttribute *this, DmeTime_t *value)
{
  switch ( this->m_nFlags & 0x1F )
  {
    case 2:
      value->m_tms = *(int *)this->m_pData;
      break;
    case 3:
      value->m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(float *)this->m_pData);
      break;
    case 4:
      if ( *(_BYTE *)this->m_pData != 0 )
        value->m_tms = DmeTime_t::RoundSecondsToTMS(sec: 1.0);
      else
        value->m_tms = 0;
      break;
    case 7:
      value->m_tms = *(int *)this->m_pData;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D420
// Name: private: void CDmAttribute::CopyData<class QAngle>(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyData<QAngle>(CDmAttribute *this, const QAngle *value)
{
  Quaternion qValue; // [esp+4h] [ebp-10h] BYREF

  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    *(QAngle *)this->m_pData = *value;
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    AngleQuaternion(angles: value, outQuat: &qValue);
    *(Quaternion *)this->m_pData = qValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D8F0
// Name: private: bool CDmAttribute::IsTypeConvertable<class CUtlSymbolLarge>(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::IsTypeConvertable<CUtlSymbolLarge>(CDmAttribute *this)
{
  return (this->m_nFlags & 0x1F) == 5;
}

//------------------------------------------------------------------------------
// Address: 0x0041D920
// Name: public: class DmeTime_t const __near & CDmAttribute::GetValue<class DmeTime_t>(class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
const DmeTime_t *__thiscall CDmAttribute::GetValue<DmeTime_t>(CDmAttribute *this, const DmeTime_t *defaultValue)
{
  unsigned __int16 m_nFlags; // ax
  int v4; // eax

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x1F) == 7 )
    return (const DmeTime_t *)this->m_pData;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 7 && v4 != 3 && v4 != 2 && v4 != 4 )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`7'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`7'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal.m_tms = 0x80000000;
  }
  CDmAttribute::CopyDataOut<DmeTime_t>(this, value: &`CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal);
  return &`CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x0041D990
// Name: public: class QAngle const __near & CDmAttribute::GetValue<class QAngle>(class QAngle const __near &)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CDmAttribute::GetValue<QAngle>(CDmAttribute *this, const QAngle *defaultValue)
{
  unsigned __int16 m_nFlags; // ax
  int v4; // eax

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x1F) == 0xC )
    return (const QAngle *)this->m_pData;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 12 && v4 != 13 )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<QAngle>'::`7'::`local static guard' & 1) == 0 )
    `CDmAttribute::GetValue<QAngle>'::`7'::`local static guard' |= 1u;
  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    `CDmAttribute::GetValue<QAngle>'::`7'::tempVal = *(QAngle *)this->m_pData;
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    QuaternionAngles(q: (const Quaternion *)this->m_pData, angles: &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal);
    return &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal;
  }
  return &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x0041DA30
// Name: public: class Quaternion const __near & CDmAttribute::GetValue<class Quaternion>(class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall CDmAttribute::GetValue<Quaternion>(CDmAttribute *this, const Quaternion *defaultValue)
{
  unsigned __int16 m_nFlags; // ax
  int v4; // eax

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x1F) == 0xD )
    return (const Quaternion *)this->m_pData;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 13 && v4 != 12 )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<Quaternion>'::`7'::`local static guard' & 1) == 0 )
    `CDmAttribute::GetValue<Quaternion>'::`7'::`local static guard' |= 1u;
  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    AngleQuaternion(angles: (const QAngle *)this->m_pData, outQuat: &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal);
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    `CDmAttribute::GetValue<Quaternion>'::`7'::tempVal = *(Quaternion *)this->m_pData;
    return &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal;
  }
  return &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x0041F640
// Name: public: class DmeTime_t const __near & CDmAttribute::GetValue<class DmeTime_t>(void)const
// Source: json
//------------------------------------------------------------------------------
const DmeTime_t *__thiscall CDmAttribute::GetValue<DmeTime_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage.m_tms = 0;
  }
  return CDmAttribute::GetValue<DmeTime_t>(
           this,
           defaultValue: &`CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00420430
// Name: private: bool CDmAttribute::ShouldModify<class CUtlSymbolLarge>(class CUtlSymbolLarge const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<CUtlSymbolLarge>(CDmAttribute *this, const CUtlSymbolLarge *value)
{
  _DWORD *v3; // eax

  if ( (this->m_nFlags & 0x1F) != 5 )
    return false;
  if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  v3 = (this->m_nFlags & 0x1F) == 5 ? this->m_pData : &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
  return *v3 != value->u.m_Id && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x004204F0
// Name: private: bool CDmAttribute::ShouldModify<class DmeTime_t>(class DmeTime_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<DmeTime_t>(CDmAttribute *this, const DmeTime_t *value)
{
  unsigned __int16 m_nFlags; // cx
  int v4; // eax

  m_nFlags = this->m_nFlags;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 7 && v4 != 3 && v4 != 2 && v4 != 4 )
    return false;
  if ( (m_nFlags & 0x1F) != 7 )
    return CDmAttribute::MarkDirty(this);
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage.m_tms = 0;
  }
  return CDmAttribute::GetValue<DmeTime_t>(
           this,
           defaultValue: &`CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage)->m_tms != value->m_tms
      && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x004205E0
// Name: public: class QAngle const __near & CDmAttribute::GetValue<class QAngle>(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CDmAttribute::GetValue<QAngle>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  return CDmAttribute::GetValue<QAngle>(
           this,
           defaultValue: &`CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00420630
// Name: private: bool CDmAttribute::ShouldModify<class QAngle>(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<QAngle>(CDmAttribute *this, const QAngle *value)
{
  unsigned __int16 m_nFlags; // cx
  int v4; // eax
  const QAngle *v6; // eax

  m_nFlags = this->m_nFlags;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 12 && v4 != 13 )
    return false;
  if ( (m_nFlags & 0x1F) != 0xC )
    return CDmAttribute::MarkDirty(this);
  if ( (`CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  v6 = CDmAttribute::GetValue<QAngle>(this, defaultValue: &`CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage);
  return (value->x != v6->x || value->y != v6->y || value->z != v6->z) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x004206E0
// Name: public: class Quaternion const __near & CDmAttribute::GetValue<class Quaternion>(void)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall CDmAttribute::GetValue<Quaternion>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  return CDmAttribute::GetValue<Quaternion>(
           this,
           defaultValue: &`CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00420740
// Name: public: class Color const __near & CDmAttribute::GetValue<class Color>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmAttribute::GetValue<Color>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_Storage = (Color)-16777216;
  }
  if ( (this->m_nFlags & 0x1F) == 8 )
    return (CDmaVar<Color> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00420780
// Name: public: class Vector2D const __near & CDmAttribute::GetValue<class Vector2D>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector2D> *__thiscall CDmAttribute::GetValue<Vector2D>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.y = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 9 )
    return (CDmaVar<Vector2D> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004207D0
// Name: public: class Vector const __near & CDmAttribute::GetValue<class Vector>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmAttribute::GetValue<Vector>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xA )
    return (CDmaVar<Vector> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00420820
// Name: public: class Vector4D const __near & CDmAttribute::GetValue<class Vector4D>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector4D> *__thiscall CDmAttribute::GetValue<Vector4D>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector4D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector4D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.w = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xB )
    return (CDmaVar<Vector4D> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00420880
// Name: public: class VMatrix const __near & CDmAttribute::GetValue<class VMatrix>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<VMatrix> *__thiscall CDmAttribute::GetValue<VMatrix>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_pAttribute = nullptr;
    MatrixSetIdentity(dst: &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_Storage);
  }
  if ( (this->m_nFlags & 0x1F) == 0xE )
    return (CDmaVar<VMatrix> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004278E0
// Name: private: bool CDmAttribute::ShouldModify<class Vector2D>(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<Vector2D>(CDmAttribute *this, const Vector2D *value)
{
  CDmaVar<Vector2D> *m_pData; // edx

  if ( (this->m_nFlags & 0x1F) != 9 )
    return false;
  if ( (`CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.y = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 9 )
    m_pData = (CDmaVar<Vector2D> *)this->m_pData;
  else
    m_pData = &`CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal;
  return (value->x != m_pData->m_Storage.x || value->y != m_pData->m_Storage.y) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00427970
// Name: private: bool CDmAttribute::ShouldModify<class VMatrix>(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<VMatrix>(CDmAttribute *this, const VMatrix *value)
{
  VMatrix *v4; // ecx

  if ( (this->m_nFlags & 0x1F) != 0xE )
    return false;
  if ( (`CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_pAttribute = nullptr;
    MatrixSetIdentity(dst: &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_Storage);
  }
  v4 = (VMatrix *)((this->m_nFlags & 0x1F) == 0xE ? this->m_pData : &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal);
  return !VMatrix::operator==(this: v4, src: value) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00436BF0
// Name: public: class CUtlBinaryBlock const __near & CDmAttribute::GetValue<class CUtlBinaryBlock>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlBinaryBlock> *__thiscall CDmAttribute::GetValue<CUtlBinaryBlock>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`local static guard' |= 1u;
    CUtlBinaryBlock::CUtlBinaryBlock(
      this: &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_Storage,
      growSize: 0,
      initSize: 0);
    `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlBinaryBlock::Set(
      this: &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_Storage,
      pValue: nullptr,
      nLen: 0);
    atexit(func: `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 6 )
    return (CDmaVar<CUtlBinaryBlock> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004573D0
// Name: public: class CDmeDag __near * CAttributeReferenceIterator::FilterReference<class CDmeDag>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CAttributeReferenceIterator::FilterReference<CDmeDag>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeDag *result; // eax
  CDmeDag *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_18;
    case TD_DEEP:
      goto $LN11_13;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_13:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_18:
      m_pOwner = (CDmeDag *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeDag::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457480
// Name: public: class CDmElement __near * CAttributeReferenceIterator::FilterReference<class CDmElement>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CAttributeReferenceIterator::FilterReference<CDmElement>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *result; // eax
  CDmElement *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_19;
    case TD_DEEP:
      goto $LN11_14;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_14:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_19:
      m_pOwner = v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmElement::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457530
// Name: public: class CDmeMesh __near * CAttributeReferenceIterator::FilterReference<class CDmeMesh>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeMesh *__thiscall CAttributeReferenceIterator::FilterReference<CDmeMesh>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeMesh *result; // eax
  CDmeMesh *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_20;
    case TD_DEEP:
      goto $LN11_15;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_15:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_20:
      m_pOwner = (CDmeMesh *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeMesh::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00458030
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class CDmeCombinationOperator>(char const __near *,class CDmeCombinationOperator __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<CDmeCombinationOperator>(
        CDmElement *this,
        const char *pAttributeName,
        DmElementHandle_t pElement,
        bool bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(pElement + 4));
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    if ( !bCreateIfNotFound )
      return nullptr;
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_VALUE_TYPE);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &pElement);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x0045FE80
// Name: public: class CDmAttribute __near * CDmElement::AddAttributeElementArray<class CDmElement>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::AddAttributeElementArray<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v4 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v4 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_ARRAY_TYPE);
  if ( v4 == nullptr )
    return nullptr;
  CDmAttribute::SetElementTypeSymbol(this: v4, typeSymbol: CDmElement::m_classType);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0045FF80
// Name: public: class CDmAttribute __near * CDmElement::InitValue<char const>(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::InitValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue)
{
  CDmAttribute *result; // eax
  CDmAttribute *Attribute; // esi

  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pValue, a3: pValue);
  result = CDmElement::FindAttribute(this, pAttributeName);
  if ( result == nullptr )
  {
    Attribute = CDmElement::FindAttribute(this, pAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pValue);
      return Attribute;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460DC0
// Name: public: class CDmElement __near * CDmElement::GetValueElement<class CDmElement>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmElement::GetValueElement<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_601A7C = -1;
    dword_601A80 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
    return v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460E50
// Name: public: class Vector const __near & CDmElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmElement::GetValue<Vector>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00460EB0
// Name: public: class Quaternion const __near & CDmElement::GetValue<class Quaternion>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmElement::GetValue<Quaternion>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<Quaternion> *)CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    return &`CDmElement::GetValue<Quaternion>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00460F70
// Name: public: class Color const __near & CDmElement::GetValue<class Color>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmElement::GetValue<Color>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_Storage = (Color)-16777216;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Color>(this: Attribute);
  else
    return &`CDmElement::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00490F50
// Name: public: class CDmeChannel __near * CAttributeReferenceIterator::FilterReference<class CDmeChannel>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CAttributeReferenceIterator::FilterReference<CDmeChannel>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeChannel *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_50;
      case TD_DEEP:
        goto $LN11_29;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_29:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_50:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeChannel::m_classType) )
          return nullptr;
        result = (CDmeChannel *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AF3E0
// Name: class CUtlBuffer __near & operator<<(class CUtlBuffer __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlBuffer *__cdecl operator<<(CUtlBuffer *b, const Vector *v)
{
  float src; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4

  src = v->x;
  if ( (b->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: b, pFmt: "%f", src);
  else
    CUtlBuffer::PutTypeBin<float>(this: b, src);
  CUtlBuffer::PutString(this: b, pString: " ");
  y = v->y;
  if ( (b->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: b, pFmt: "%f", y);
  else
    CUtlBuffer::PutTypeBin<float>(this: b, src: y);
  CUtlBuffer::PutString(this: b, pString: " ");
  z = v->z;
  if ( (b->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: b, pFmt: "%f", z);
  else
    CUtlBuffer::PutTypeBin<float>(this: b, src: z);
  return b;
}

//------------------------------------------------------------------------------
// Address: 0x004B7F70
// Name: public: class CDmeLog __near * CDmElement::GetValueElement<class CDmeLog>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmElement::GetValueElement<CDmeLog>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_601A7C = -1;
    dword_601A80 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (CDmaVar<enum DmElementHandle_t> *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeLog::m_classType) )
    return (CDmeLog *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B8CD0
// Name: public: class CDmeClip __near * CAttributeReferenceIterator::FilterReference<class CDmeClip>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CAttributeReferenceIterator::FilterReference<CDmeClip>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmeClip *result; // eax
  CDmeClip *m_pOwner; // esi

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 == nullptr )
    return nullptr;
  switch ( depth )
  {
    case TD_ALL:
      goto $LN4_56;
    case TD_DEEP:
      goto $LN11_30;
    case TD_SHALLOW:
      if ( (v5->m_nFlags & 0x800) == 0 )
        return nullptr;
$LN11_30:
      if ( (v5->m_nFlags & 0x1000) != 0 )
        return nullptr;
$LN4_56:
      m_pOwner = (CDmeClip *)v5->m_pOwner;
      if ( m_pOwner == nullptr
        || !m_pOwner->IsA(this: m_pOwner, a2: CDmeClip::m_classType)
        || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id
        || bMustBeInSameFile && m_pOwner->m_fileId != this->m_fileid )
      {
        return nullptr;
      }
      result = m_pOwner;
      break;
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00560AF0
// Name: public: class CDmeRigBaseConstraintOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeRigBaseConstraintOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeRigBaseConstraintOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeRigBaseConstraintOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeRigBaseConstraintOperator *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_58;
      case TD_DEEP:
        goto $LN11_44;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_44:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_58:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeRigBaseConstraintOperator::m_classType) )
          return nullptr;
        result = (CDmeRigBaseConstraintOperator *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00565750
// Name: public: class CDmeFlexRules __near * CAttributeReferenceIterator::FilterReference<class CDmeFlexRules>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeFlexRules *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_59;
      case TD_DEEP:
        goto $LN11_45;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_45:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_59:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeFlexRules::m_classType) )
          return nullptr;
        result = (CDmeFlexRules *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00568150
// Name: public: class CDmeOperator __near * CAttributeReferenceIterator::FilterReference<class CDmeOperator>(class CUtlSymbolLarge,bool,enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeOperator *__thiscall CAttributeReferenceIterator::FilterReference<CDmeOperator>(
        CAttributeReferenceIterator *this,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CDmAttribute *v5; // edi
  CDmElement *m_pOwner; // esi
  CDmeOperator *result; // eax

  v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: this->m_curr);
  if ( v5 != nullptr )
  {
    switch ( depth )
    {
      case TD_ALL:
        goto $LN4_60;
      case TD_DEEP:
        goto $LN11_46;
      case TD_SHALLOW:
        if ( (v5->m_nFlags & 0x800) == 0 )
          return nullptr;
$LN11_46:
        if ( (v5->m_nFlags & 0x1000) != 0 )
          return nullptr;
$LN4_60:
        m_pOwner = v5->m_pOwner;
        if ( m_pOwner == nullptr )
          return nullptr;
        if ( !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          return nullptr;
        result = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        if ( m_pOwner == (CDmElement *)4 || symAttrName.u.m_Id != -1 && v5->m_Name.u.m_Id != symAttrName.u.m_Id )
          return nullptr;
        if ( bMustBeInSameFile && result->m_fileId != this->m_fileid )
          return nullptr;
        return result;
      default:
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005A6810
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x005AAA40
// Name: _dynamic_initializer_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmElement::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmElement pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmElement::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF4E0
// Name: _dynamic_atexit_destructor_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmElement::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00402820
// Name: class CDmeCombinationOperator __near * FindReferringElement<class CDmeCombinationOperator>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *__cdecl FindReferringElement<CDmeCombinationOperator>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeCombinationOperator *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeCombinationOperator>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004028B0
// Name: class CDmElement __near * GetElement<class CDmElement>(enum DmElementHandle_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl GetElement<CDmElement>(DmElementHandle_t hElement)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: hElement);
  v2 = v1;
  if ( v1 != nullptr && v1->IsA(this: v1, a2: CDmElement::m_classType) )
    return v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403FB0
// Name: class CDmeSingleIndexedComponent __near * CreateElement<class CDmeSingleIndexedComponent>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSingleIndexedComponent *__cdecl CreateElement<CDmeSingleIndexedComponent>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeSingleIndexedComponent::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeSingleIndexedComponent::m_classType) )
    return (CDmeSingleIndexedComponent *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404010
// Name: class CDmeCombinationOperator __near * FindReferringElement<class CDmeCombinationOperator>(class CDmElement const __near *,char const __near *,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *__cdecl FindReferringElement<CDmeCombinationOperator>(
        CExpressionCalculator *pElement,
        const char *pAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CUtlSymbolLarge *p_pAttrName; // eax

  if ( pAttrName != nullptr )
  {
    p_pAttrName = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pAttrName, a3: pAttrName);
  }
  else
  {
    pAttrName = (const char *)-1;
    p_pAttrName = (CUtlSymbolLarge *)&pAttrName;
  }
  return FindReferringElement<CDmeCombinationOperator>(
           pElement,
           symAttrName: (CUtlSymbolLarge)p_pAttrName->u.m_Id,
           bMustBeInSameFile,
           depth);
}

//------------------------------------------------------------------------------
// Address: 0x00404060
// Name: class CDmeSourceDCCFile __near * CreateElement<class CDmeSourceDCCFile>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceDCCFile *__cdecl CreateElement<CDmeSourceDCCFile>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeSourceDCCFile::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeSourceDCCFile::m_classType) )
    return (CDmeSourceDCCFile *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004040C0
// Name: class CDmElement __near * CreateElement<class CDmElement>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl CreateElement<CDmElement>(const char *pObjectName, DmFileId_t fileid, const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
    return v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004580A0
// Name: class CDmePresetGroup __near * CreateElement<class CDmePresetGroup>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePresetGroup *__cdecl CreateElement<CDmePresetGroup>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmePresetGroup::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmePresetGroup::m_classType) )
    return (CDmePresetGroup *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00458100
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00458190
// Name: class CDmElement __near * FindReferringElement<class CDmElement>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl FindReferringElement<CDmElement>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmElement *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmElement>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00458220
// Name: class CDmeMesh __near * FindReferringElement<class CDmeMesh>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *__cdecl FindReferringElement<CDmeMesh>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeMesh *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeMesh>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00568200
// Name: class CDmeOperator __near * FindReferringElement<class CDmeOperator>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeOperator *__cdecl FindReferringElement<CDmeOperator>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeOperator *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeOperator>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAA70
// Name: _dynamic_initializer_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AAA80
// Name: _dynamic_initializer_for__g_CDmElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmElement_Helper,
           classname: "DmElement",
           pFactory: &g_CDmElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AAAA0
// Name: _dynamic_initializer_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AAAB0
// Name: _dynamic_initializer_for__g_CDmeElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElement_Helper,
           classname: "DmeElement",
           pFactory: &g_CDmeElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AAAD0
// Name: _dynamic_initializer_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc4__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_DataAlloc4,
    blockSize: 4,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "4-byte data pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc4__);
}

//------------------------------------------------------------------------------
// Address: 0x005AAB00
// Name: _dynamic_initializer_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc8__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_DataAlloc8,
    blockSize: 8,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "8-byte data pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc8__);
}

//------------------------------------------------------------------------------
// Address: 0x005AAB30
// Name: _dynamic_initializer_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrAlloc__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrAlloc,
    blockSize: 24,
    numElements: 4096,
    growMode: 2,
    pszAllocOwner: "CDmAttribute pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrAlloc__);
}

//------------------------------------------------------------------------------
// Address: 0x005AAB60
// Name: _dynamic_initializer_for____s_AttrDmUnknownAttribute_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmUnknownAttribute_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmUnknownAttribute_t>::`vftable';
    s_pAttrInfo[0] = result;
  }
  else
  {
    s_pAttrInfo[0] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAB90
// Name: _dynamic_initializer_for____s_Attrint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<int>::`vftable';
    s_pAttrInfo[2] = result;
  }
  else
  {
    s_pAttrInfo[2] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AABC0
// Name: _dynamic_initializer_for____s_AttrArrayint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<int>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[16] = result;
  }
  else
  {
    s_pAttrInfo[16] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AABF0
// Name: _dynamic_initializer_for____s_Attrfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<float>::`vftable';
    s_pAttrInfo[3] = result;
  }
  else
  {
    s_pAttrInfo[3] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAC20
// Name: _dynamic_initializer_for____s_AttrArrayfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<float>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[17] = result;
  }
  else
  {
    s_pAttrInfo[17] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAC50
// Name: _dynamic_initializer_for____s_Attrbool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrbool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<bool>::`vftable';
    s_pAttrInfo[4] = result;
  }
  else
  {
    s_pAttrInfo[4] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAC80
// Name: _dynamic_initializer_for____s_AttrArraybool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArraybool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<bool>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[18] = result;
  }
  else
  {
    s_pAttrInfo[18] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AACB0
// Name: _dynamic_initializer_for____s_AttrColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Color>::`vftable';
    s_pAttrInfo[8] = result;
  }
  else
  {
    s_pAttrInfo[8] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AACE0
// Name: _dynamic_initializer_for____s_AttrArrayColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Color>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[22] = result;
  }
  else
  {
    s_pAttrInfo[22] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAD10
// Name: _dynamic_initializer_for____s_AttrVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector2D>::`vftable';
    s_pAttrInfo[9] = result;
  }
  else
  {
    s_pAttrInfo[9] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAD40
// Name: _dynamic_initializer_for____s_AttrArrayVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector2D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[23] = result;
  }
  else
  {
    s_pAttrInfo[23] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAD70
// Name: _dynamic_initializer_for____s_AttrVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector>::`vftable';
    s_pAttrInfo[10] = result;
  }
  else
  {
    s_pAttrInfo[10] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AADA0
// Name: _dynamic_initializer_for____s_AttrArrayVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[24] = result;
  }
  else
  {
    s_pAttrInfo[24] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AADD0
// Name: _dynamic_initializer_for____s_AttrVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector4D>::`vftable';
    s_pAttrInfo[11] = result;
  }
  else
  {
    s_pAttrInfo[11] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAE00
// Name: _dynamic_initializer_for____s_AttrArrayVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector4D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[25] = result;
  }
  else
  {
    s_pAttrInfo[25] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAE30
// Name: _dynamic_initializer_for____s_AttrQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<QAngle>::`vftable';
    s_pAttrInfo[12] = result;
  }
  else
  {
    s_pAttrInfo[12] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAE60
// Name: _dynamic_initializer_for____s_AttrArrayQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<QAngle>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[26] = result;
  }
  else
  {
    s_pAttrInfo[26] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAE90
// Name: _dynamic_initializer_for____s_AttrQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Quaternion>::`vftable';
    s_pAttrInfo[13] = result;
  }
  else
  {
    s_pAttrInfo[13] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAEC0
// Name: _dynamic_initializer_for____s_AttrArrayQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Quaternion>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[27] = result;
  }
  else
  {
    s_pAttrInfo[27] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAEF0
// Name: _dynamic_initializer_for____s_AttrVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<VMatrix>::`vftable';
    s_pAttrInfo[14] = result;
  }
  else
  {
    s_pAttrInfo[14] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAF20
// Name: _dynamic_initializer_for____s_AttrArrayVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<VMatrix>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[28] = result;
  }
  else
  {
    s_pAttrInfo[28] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAF50
// Name: _dynamic_initializer_for____s_AttrCUtlSymbolLarge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlSymbolLarge__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlSymbolLarge>::`vftable';
    s_pAttrInfo[5] = result;
  }
  else
  {
    s_pAttrInfo[5] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAF80
// Name: _dynamic_initializer_for____s_AttrArrayCUtlSymbolLarge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlSymbolLarge__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlSymbolLarge>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[19] = result;
  }
  else
  {
    s_pAttrInfo[19] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAFB0
// Name: _dynamic_initializer_for____s_AttrCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlBinaryBlock>::`vftable';
    s_pAttrInfo[6] = result;
  }
  else
  {
    s_pAttrInfo[6] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AAFF0
// Name: _dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlBinaryBlock>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[20] = result;
  }
  else
  {
    s_pAttrInfo[20] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB020
// Name: _dynamic_initializer_for____s_AttrDmeTime_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmeTime_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmeTime_t>::`vftable';
    s_pAttrInfo[7] = result;
  }
  else
  {
    s_pAttrInfo[7] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB050
// Name: _dynamic_initializer_for____s_AttrArrayDmeTime_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmeTime_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<DmeTime_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[21] = result;
  }
  else
  {
    s_pAttrInfo[21] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB080
// Name: _dynamic_initializer_for____s_AttrDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<enum DmElementHandle_t>::`vftable';
    s_pAttrInfo[1] = result;
  }
  else
  {
    s_pAttrInfo[1] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB0B0
// Name: _dynamic_initializer_for____s_AttrArrayDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<enum DmElementHandle_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[15] = result;
  }
  else
  {
    s_pAttrInfo[15] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB0E0
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005AB120
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2.m_ElementDict);
  s_DMSerializerKeyValues2.m_bFlatMode = false;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB140
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2Flat__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2Flat.m_ElementDict);
  s_DMSerializerKeyValues2Flat.m_bFlatMode = true;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB160
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB170
// Name: _dynamic_initializer_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DmElementFramework__()
{
  CDependencyGraph::CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = nullptr;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nAllocationCount = 256;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nGrowSize = 128;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = (DmElementHandle_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 1024);
  g_DmElementFramework.m_dirtyElements.m_Size = 0;
  g_DmElementFramework.m_dirtyElements.m_pElements = g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory;
  g_DmElementFramework.m_phase = PH_EDIT;
  return atexit(func: dynamic_atexit_destructor_for__g_DmElementFramework__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB1E0
// Name: _dynamic_initializer_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrNodePool,
    blockSize: 28,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB210
// Name: _dynamic_initializer_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_OperatorNodePool,
    blockSize: 32,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_OperatorNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB240
// Name: _dynamic_initializer_for__LOG_MESHUTILS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_MESHUTILS__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "MeshUtils",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_20);
  LOG_MESHUTILS = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB260
// Name: _dynamic_initializer_for__s_ImportSFMV9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV9__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV9, formatName: "sfm_v9", nextFormatName: "sfm_v10");
  s_ImportSFMV9.__vftable = (CImportSFMV9_vtbl *)&CImportSFMV9::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB280
// Name: _dynamic_initializer_for__s_ImportSFMV8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV8__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV8, formatName: "sfm_v8", nextFormatName: "sfm_v9");
  s_ImportSFMV8.__vftable = (CImportSFMV8_vtbl *)&CImportSFMV8::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB2A0
// Name: _dynamic_initializer_for__s_ImportSFMV7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV7__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV7, formatName: "sfm_v7", nextFormatName: "sfm_v8");
  s_ImportSFMV7.__vftable = (CImportSFMV7_vtbl *)&CImportSFMV7::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB2C0
// Name: _dynamic_initializer_for__s_ImportSFMV6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV6__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV6, formatName: "sfm_v6", nextFormatName: "sfm_v7");
  s_ImportSFMV6.__vftable = (CImportSFMV6_vtbl *)&CImportSFMV6::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB2E0
// Name: _dynamic_initializer_for__s_ImportSFMV5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV5__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV5, formatName: "sfm_v5", nextFormatName: "sfm_v6");
  s_ImportSFMV5.__vftable = (CImportSFMV5_vtbl *)&CImportSFMV5::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB300
// Name: _dynamic_initializer_for__s_ImportSFMV4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV4__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV4, formatName: "sfm_v4", nextFormatName: "sfm_v5");
  s_ImportSFMV4.__vftable = (CImportSFMV4_vtbl *)&CImportSFMV4::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB320
// Name: _dynamic_initializer_for__s_ImportSFMV3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV3__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV3, formatName: "sfm_v3", nextFormatName: "sfm_v4");
  s_ImportSFMV3.__vftable = (CImportSFMV3_vtbl *)&CImportSFMV3::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB340
// Name: _dynamic_initializer_for__s_ImportSFMV2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV2__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV2, formatName: "sfm_v2", nextFormatName: "sfm_v3");
  s_ImportSFMV2.__vftable = (CImportSFMV2_vtbl *)&CImportSFMV2::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB360
// Name: _dynamic_initializer_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ImportDmxV1__()
{
  CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportDmxV1, formatName: "sfm_v1", nextFormatName: "sfm_v2");
  s_ImportDmxV1.__vftable = (CImportSFMV1_vtbl *)&CImportSFMV1::`vftable';
  s_ImportDmxV1.m_fixedElements.m_Elements.m_pMemory = nullptr;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nAllocationCount = 0;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nGrowSize = 0;
  s_ImportDmxV1.m_fixedElements.m_Root = -1;
  s_ImportDmxV1.m_fixedElements.m_NumElements = 0;
  s_ImportDmxV1.m_fixedElements.m_FirstFree = -1;
  s_ImportDmxV1.m_fixedElements.m_LastAlloc.index = -1;
  s_ImportDmxV1.m_fixedElements.m_pElements = nullptr;
  s_ImportDmxV1.m_fixedElements.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__s_ImportDmxV1__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF4F0
// Name: _dynamic_atexit_destructor_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElement_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AF500
// Name: _dynamic_atexit_destructor_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmElement_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AF510
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x005AF520
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x005AF530
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}
