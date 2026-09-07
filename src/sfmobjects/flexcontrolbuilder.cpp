// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: sfmobjects/flexcontrolbuilder.cpp
// Functions: 25
// ============================================================

#include "sfmobjects\flexcontrolbuilder.h"

//------------------------------------------------------------------------------
// Address: 0x00537510
// Name: void SetupDefaultFlexController(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultFlexController()
{
  g_pGlobalFlexController = &s_GlobalFlexController;
}

//------------------------------------------------------------------------------
// Address: 0x00537520
// Name: public: void CUtlMemory<struct CFlexControlBuilder::FlexControllerInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFlexControlBuilder::FlexControllerInfo_t,int>::Grow(
        CUtlMemory<CFlexControlBuilder::FlexControllerInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CFlexControlBuilder::FlexControllerInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 1;
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
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CFlexControlBuilder::FlexControllerInfo_t *)_g_pMemAlloc->Realloc_2(
                                                                       this: _g_pMemAlloc,
                                                                       a2: m_pMemory,
                                                                       a3: v7);
    else
      this->m_pMemory = (CFlexControlBuilder::FlexControllerInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005375C0
// Name: public: virtual int CDefaultGlobalFlexController::FindGlobalFlexController(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDefaultGlobalFlexController::FindGlobalFlexController(
        CDefaultGlobalFlexController *this,
        const char *name)
{
  return CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&name + 1, pString: name)->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005375E0
// Name: public: virtual char const __near * CDefaultGlobalFlexController::GetGlobalFlexControllerName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDefaultGlobalFlexController::GetGlobalFlexControllerName(
        CDefaultGlobalFlexController *this,
        CUtlSymbol idx)
{
  return CUtlSymbolTable::String(this: &this->m_SymbolTable, id: idx);
}

//------------------------------------------------------------------------------
// Address: 0x00537600
// Name: public: void CUtlMemory<struct CFlexControlBuilder::ControlInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFlexControlBuilder::ControlInfo_t,int>::Grow(
        CUtlMemory<CFlexControlBuilder::ControlInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CFlexControlBuilder::ControlInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 1;
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
    v7 = 344 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CFlexControlBuilder::ControlInfo_t *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (CFlexControlBuilder::ControlInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005376A0
// Name: private: void CFlexControlBuilder::BuildFlexControllerOps(class CDmeGameModel __near *,class CDmeChannelsClip __near *,struct CFlexControlBuilder::ControlInfo_t __near &,enum CFlexControlBuilder::ControlField_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::BuildFlexControllerOps(
        CFlexControlBuilder *this,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip,
        CDmeGlobalFlexControllerOperator *info,
        CFlexControlBuilder::ControlField_t field)
{
  CFlexControlBuilder::ControlField_t v5; // ebx
  CFlexControlBuilder::FlexControllerInfo_t *v7; // esi
  CDmElement *v8; // eax
  CDmeChannel *PassThruConnection; // eax
  const char *v10; // esi
  CDmAttribute *Attribute; // eax
  char pName[256]; // [esp+Ch] [ebp-100h] BYREF
  CDmeGlobalFlexControllerOperator *pFlexControllerOp; // [esp+11Ch] [ebp+10h]
  CDmElement *pFlexControllerOpa; // [esp+11Ch] [ebp+10h]

  v5 = field;
  v7 = &this->m_FlexControllerInfo.m_Memory.m_pMemory[*((_DWORD *)&info[2].m_fileId + field)];
  pFlexControllerOp = CDmeGameModel::AddGlobalFlexController(
                        this: pGameModel,
                        controllerName: v7->m_pFlexControlName,
                        globalIndex: (DmAttributeHandle_t)v7->m_nGlobalIndex);
  V_snprintf(pDest: pName, maxLen: 256, pFormat: "%s_flex_channel", v7->m_pFlexControlName);
  if ( pFlexControllerOp != nullptr )
    v8 = &pFlexControllerOp->CDmElement;
  else
    v8 = nullptr;
  PassThruConnection = CDmeChannelsClip::CreatePassThruConnection(
                         this: pChannelsClip,
                         passThruName: (int)pName,
                         pFrom: (CDmElement *)info[2].m_pAttributes,
                         pFromAttribute: s_pValueControls[v5],
                         pTo: v8,
                         pToAttribute: "flexWeight",
                         index: 0);
  *(&info[2].m_nSortKey + v5) = (int)PassThruConnection;
  v10 = s_pChannelControls[v5];
  pFlexControllerOpa = (CDmElement *)info[2].m_pAttributes;
  if ( PassThruConnection != nullptr )
    field = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&PassThruConnection->CDmElement);
  else
    field = -1;
  Attribute = CDmElement::FindAttribute(this: pFlexControllerOpa, pAttributeName: v10);
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(
                      this: pFlexControllerOpa,
                      pAttributeName: v10,
                      type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&field);
  }
  CDmeChannel::SetMode(this: *((CDmeChannel **)&info[2].m_nSortKey + v5), mode: CM_PLAY);
}

//------------------------------------------------------------------------------
// Address: 0x00537790
// Name: private: void CFlexControlBuilder::AttachControlsToGameModel(class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::AttachControlsToGameModel(
        CFlexControlBuilder *this,
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip)
{
  CFlexControlBuilder *v4; // ebx
  int m_Size; // eax
  CFlexControlBuilder::ControlInfo_t *v6; // edi
  int m_pFlexControlName; // esi
  CDmeGlobalFlexControllerOperator *v8; // ebx
  CDmElement *v9; // ebx
  CDmeChannel *PassThruConnection; // eax
  const char *v11; // esi
  CDmElement *m_pControl; // ebx
  CDmAttribute *Attribute; // eax
  char pDest[256]; // [esp+4h] [ebp-110h] BYREF
  DmElementHandle_t value; // [esp+104h] [ebp-10h] BYREF
  int i; // [esp+108h] [ebp-Ch]
  CFlexControlBuilder *v17; // [esp+10Ch] [ebp-8h]
  unsigned int v18; // [esp+110h] [ebp-4h]

  v4 = this;
  m_Size = this->m_ControlInfo.m_Size;
  v17 = this;
  if ( m_Size > 0 )
  {
    v18 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v6 = &v4->m_ControlInfo.m_Memory.m_pMemory[v18 / 0x158];
      if ( (*((_BYTE *)v6 + 256) & 1) != 0 )
      {
        m_pFlexControlName = (int)v4->m_FlexControllerInfo.m_Memory.m_pMemory[v6->m_pControllerIndex[1]].m_pFlexControlName;
        v8 = CDmeGameModel::AddGlobalFlexController(
               this: pGameModel,
               controllerName: (const char *)m_pFlexControlName,
               globalIndex: *(DmAttributeHandle_t *)(m_pFlexControlName + 260));
        V_snprintf(pDest, maxLen: 256, pFormat: "%s_flex_channel", (const char *)m_pFlexControlName);
        if ( v8 != nullptr )
          v9 = &v8->CDmElement;
        else
          v9 = nullptr;
        PassThruConnection = CDmeChannelsClip::CreatePassThruConnection(
                               this: pChannelsClip,
                               passThruName: (int)pDest,
                               pFrom: v6->m_pControl,
                               pFromAttribute: s_pValueControls[1],
                               pTo: v9,
                               pToAttribute: "flexWeight",
                               index: 0);
        v6->m_ppControlChannel[1] = PassThruConnection;
        v11 = s_pChannelControls[1];
        m_pControl = v6->m_pControl;
        if ( PassThruConnection != nullptr )
          value = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&PassThruConnection->CDmElement);
        else
          value = DMELEMENT_HANDLE_INVALID;
        Attribute = CDmElement::FindAttribute(this: m_pControl, pAttributeName: v11);
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: m_pControl, pAttributeName: v11, type: AT_FIRST_VALUE_TYPE)) != nullptr )
        {
          CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
        }
        CDmeChannel::SetMode(this: v6->m_ppControlChannel[1], mode: CM_PLAY);
        CFlexControlBuilder::BuildFlexControllerOps(
          this: v17,
          pGameModel,
          pChannelsClip,
          info: (CDmeGlobalFlexControllerOperator *)v6,
          field: CONTROL_LEFT);
        v4 = v17;
      }
      else
      {
        CFlexControlBuilder::BuildFlexControllerOps(
          this: v4,
          pGameModel,
          pChannelsClip,
          info: (CDmeGlobalFlexControllerOperator *)v6,
          field: CONTROL_MONO);
      }
      v18 += 344;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005378E0
// Name: private: void CFlexControlBuilder::CreateFlexControls(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::CreateFlexControls(CFlexControlBuilder *this, CDmeAnimationSet *pAnimationSet)
{
  CFlexControlBuilder::ControlInfo_t *v2; // ebx
  CDmElement *v3; // esi
  const char **v4; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CFlexControlBuilder *v9; // [esp+0h] [ebp-Ch]
  int m_Size; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]

  v9 = this;
  if ( this->m_ControlInfo.m_Size > 0 )
  {
    v11 = 0;
    m_Size = this->m_ControlInfo.m_Size;
    while ( 1 )
    {
      v2 = &this->m_ControlInfo.m_Memory.m_pMemory[v11];
      v3 = CDmeAnimationSet::FindOrAddControl(
             this: pAnimationSet,
             pControlName: v2->m_pControlName,
             transformControl: false,
             bMustBeNew: false);
      v2->m_pControl = v3;
      v4 = s_pChannelControls;
      do
        CDmElement::RemoveAttribute(this: v3, pAttributeName: *v4++);
      while ( (int)v4 < (int)s_pValueControls );
      Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "defaultValue");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: Attribute, value: &v2->m_flDefaultValue);
      }
      if ( (*((_BYTE *)v2 + 256) & 1) != 0 )
      {
        CDmElement::RemoveAttribute(this: v3, pAttributeName: "value");
        if ( CDmElement::FindAttribute(this: v3, pAttributeName: "leftValue") == nullptr )
        {
          v6 = CDmElement::FindAttribute(this: v3, pAttributeName: "leftValue");
          if ( v6 != nullptr
            || (v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v6, value: &v2->m_flDefaultValue);
          }
        }
        if ( CDmElement::FindAttribute(this: v3, pAttributeName: "rightValue") == nullptr )
        {
          v7 = CDmElement::FindAttribute(this: v3, pAttributeName: "rightValue");
          if ( v7 != nullptr
            || (v7 = CDmElement::CreateAttribute(this: v3, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v7, value: &v2->m_flDefaultValue);
          }
        }
      }
      else
      {
        if ( CDmElement::FindAttribute(this: v3, pAttributeName: "value") == nullptr )
        {
          v8 = CDmElement::FindAttribute(this: v3, pAttributeName: "value");
          if ( v8 != nullptr
            || (v8 = CDmElement::CreateAttribute(this: v3, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v8, value: &v2->m_flDefaultValue);
          }
        }
        CDmElement::RemoveAttribute(this: v3, pAttributeName: "leftValue");
        CDmElement::RemoveAttribute(this: v3, pAttributeName: "rightValue");
      }
      ++v11;
      if ( --m_Size == 0 )
        break;
      this = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00537A80
// Name: private: class CDmeChannelsClip __near * CFlexControlBuilder::FindChannelsClipContainingChannel(class CDmeFilmClip __near *,class CDmeChannel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CFlexControlBuilder::FindChannelsClipContainingChannel(
        CFlexControlBuilder *this,
        CDmeFilmClip *pClip,
        CDmeChannel *pSearch)
{
  int v3; // esi
  CDmeTrackGroup *TrackGroup; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // eax
  int v9; // ecx
  CDmeClip *Clip; // eax
  CDmeClip *v11; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmeChannel *v15; // eax
  CDmAttribute *gc; // [esp+Ch] [ebp-24h]
  int _tc; // [esp+10h] [ebp-20h]
  CDmeTrackGroup *pTrackGroup; // [esp+14h] [ebp-1Ch]
  int _cc; // [esp+18h] [ebp-18h]
  CDmeTransform *v21; // [esp+1Ch] [ebp-14h]
  int nChannels; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  int _i; // [esp+28h] [ebp-8h]
  int _j; // [esp+2Ch] [ebp-4h]

  v3 = 0;
  gc = CDmeTrack::GetClipCount(this: (CDmeTransform *)pClip);
  i = 0;
  if ( (int)gc <= 0 )
    return nullptr;
  while ( 1 )
  {
    TrackGroup = CDmeClip::GetTrackGroup(this: pClip, nIndex: v3);
    v5 = 0;
    pTrackGroup = TrackGroup;
    _tc = TrackGroup->m_Tracks.m_Storage.m_Size;
    _i = 0;
    if ( _tc > 0 )
      break;
LABEL_20:
    i = ++v3;
    if ( v3 >= (int)gc )
      return nullptr;
  }
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: TrackGroup->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    v21 = (CDmeTransform *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == 0 )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      _cc = (int)ClipCount;
      _j = 0;
      if ( (int)ClipCount > 0 )
        break;
    }
LABEL_18:
    _i = ++v5;
    if ( v5 >= _tc )
    {
      v3 = i;
      goto LABEL_20;
    }
  }
  while ( 1 )
  {
    Clip = CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9);
    v11 = Clip;
    if ( Clip != nullptr )
    {
      v12 = 0;
      nChannels = *(_DWORD *)&Clip[1].m_Id.m_Value[8];
      if ( nChannels > 0 )
        break;
    }
LABEL_16:
    v9 = _j + 1;
    _j = v9;
    if ( v9 >= _cc )
    {
      TrackGroup = pTrackGroup;
      v5 = _i;
      goto LABEL_18;
    }
  }
  while ( 1 )
  {
    v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v11[1].OnAttributeChanged + v12));
    v14 = v13;
    if ( v13 != nullptr && v13->IsA(this: v13, a2: CDmeChannel::m_classType) )
      v15 = (CDmeChannel *)((char *)&v14[-1] + 64);
    else
      v15 = nullptr;
    if ( v15 == pSearch )
      return (CDmeChannelsClip *)v11;
    if ( ++v12 >= nChannels )
    {
      v7 = v21;
      goto LABEL_16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00537BD0
// Name: private: void CFlexControlBuilder::FixupExistingFlexControlLogList(class CDmeFilmClip __near *,class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::FixupExistingFlexControlLogList(
        CFlexControlBuilder *this,
        CDmeFilmClip *pCurrentClip,
        CDmeGameModel *pGameModel)
{
  CDmAttribute *ClipCount; // edi
  int v4; // esi
  CDmeTrackGroup *TrackGroup; // eax
  int v6; // ecx
  CDmElement *v7; // eax
  CDmeTransform *v8; // esi
  CDmAttribute *v9; // ebx
  int v10; // edi
  CDmeClip *Clip; // eax
  int v12; // ecx
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmElement *v15; // eax
  CDmElement *v16; // esi
  CDmeGlobalFlexControllerOperator *v17; // ebx
  CDmAttribute *GlobalIndex; // edi
  CDmeGlobalFlexControllerOperator *GlobalFlexController; // eax
  int v20; // ecx
  CDmeGlobalFlexControllerOperator *v21; // esi
  const char *m_pAsString; // eax
  CDmAttribute *v23; // eax
  const char *v24; // eax
  CDmAttribute *v25; // eax
  const char *v26; // eax
  IDataModel_vtbl *v27; // esi
  int v28; // eax
  int nTrackGroups; // [esp+Ch] [ebp-38h]
  int _tc; // [esp+10h] [ebp-34h]
  CDmeTransform *v31; // [esp+14h] [ebp-30h]
  int _cc; // [esp+18h] [ebp-2Ch]
  int nChannels; // [esp+1Ch] [ebp-28h]
  CDmeChannelsClip *pChannelsClip; // [esp+24h] [ebp-20h]
  CDmeTrackGroup *pTrackGroup; // [esp+28h] [ebp-1Ch]
  int gi; // [esp+2Ch] [ebp-18h]
  int _i; // [esp+30h] [ebp-14h]
  int _j; // [esp+34h] [ebp-10h]
  int ci; // [esp+38h] [ebp-Ch]
  CDmElement *pElement; // [esp+3Ch] [ebp-8h]
  CDmElement *pElementa; // [esp+3Ch] [ebp-8h]
  CDmeChannel *v42; // [esp+40h] [ebp-4h]

  ClipCount = CDmeTrack::GetClipCount(this: (CDmeTransform *)pCurrentClip);
  v4 = 0;
  nTrackGroups = (int)ClipCount;
  for ( gi = 0; v4 < (int)ClipCount; gi = v4 )
  {
    TrackGroup = CDmeClip::GetTrackGroup(this: pCurrentClip, nIndex: v4);
    pTrackGroup = TrackGroup;
    if ( TrackGroup != nullptr )
    {
      v6 = 0;
      _tc = TrackGroup->m_Tracks.m_Storage.m_Size;
      _i = 0;
      if ( _tc > 0 )
      {
        while ( 1 )
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: TrackGroup->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
          v8 = (CDmeTransform *)v7;
          v31 = (CDmeTransform *)v7;
          if ( v7 != nullptr
            && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
            && CDmeTrack::GetClipType(this: (CDmeTrack *)v8) == 0 )
          {
            v9 = CDmeTrack::GetClipCount(this: v8);
            v10 = 0;
            _cc = (int)v9;
            for ( _j = 0; v10 < (int)v9; _j = v10 )
            {
              Clip = CDmeTrack::GetClip(this: (CDmeTrack *)v8, i: v10);
              pChannelsClip = (CDmeChannelsClip *)Clip;
              if ( Clip != nullptr )
              {
                v12 = 0;
                nChannels = *(_DWORD *)&Clip[1].m_Id.m_Value[8];
                ci = 0;
                if ( nChannels > 0 )
                {
                  while ( 1 )
                  {
                    v13 = g_pDataModel->GetElement(
                            this: g_pDataModel,
                            a2: *((_DWORD *)&Clip[1].OnAttributeChanged + v12));
                    v14 = v13;
                    if ( v13 != nullptr && v13->IsA(this: v13, a2: CDmeChannel::m_classType) )
                    {
                      v42 = (CDmeChannel *)((char *)&v14[-1] + 64);
                      if ( v14 != (CDmElement *)4 )
                      {
                        v15 = CDmeChannel::GetToElement(this: (CDmeChannel *)((char *)&v14[-1] + 64));
                        v16 = v15;
                        if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeGlobalFlexControllerOperator::m_classType) )
                        {
                          v17 = (CDmeGlobalFlexControllerOperator *)((char *)&v16[-1] + 64);
                          if ( v16 != (CDmElement *)4
                            && v17->m_gameModel.m_Storage.m_Handle == CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pGameModel) )
                          {
                            GlobalIndex = CDmeGlobalFlexControllerOperator::GetGlobalIndex(this: (CDmeTransform *)v17);
                            GlobalFlexController = CDmeGameModel::FindGlobalFlexController(
                                                     this: pGameModel,
                                                     nGlobalIndex: (int)GlobalIndex);
                            v21 = GlobalFlexController;
                            if ( GlobalFlexController != v17 )
                            {
                              if ( GlobalFlexController != nullptr )
                                goto LABEL_26;
                              _Msg(a1: v20, a2: "adding missing flex controller %d %s\n");
                              m_pAsString = v17->m_Name.m_Storage.u.m_pAsString;
                              if ( m_pAsString == (const char *)-1 )
                                m_pAsString = &pParentName;
                              v21 = CDmeGameModel::AddGlobalFlexController(
                                      this: pGameModel,
                                      controllerName: m_pAsString,
                                      globalIndex: (DmAttributeHandle_t)GlobalIndex);
                              if ( v21 != nullptr )
LABEL_26:
                                pElement = &v21->CDmElement;
                              else
                                pElement = nullptr;
                              v23 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v42->m_ToAttributeHandle);
                              if ( v23 == nullptr )
                                v23 = CDmeChannel::SetupToAttribute(this: v42);
                              v24 = v23->m_Name.u.m_pAsString;
                              if ( v24 == (const char *)-1 )
                                v24 = &pParentName;
                              CDmeChannel::SetOutput(this: v42, (int)pElement, pAttribute: v24, index: 0);
                              if ( CDmeChannel::GetFromElement(this: v42) == &v17->CDmElement )
                              {
                                if ( v21 != nullptr )
                                  pElementa = &v21->CDmElement;
                                else
                                  pElementa = nullptr;
                                v21 = (CDmeGlobalFlexControllerOperator *)v42;
                                v25 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v42->m_FromAttributeHandle);
                                if ( v25 == nullptr )
                                  v25 = CDmeChannel::SetupFromAttribute(this: v42);
                                v26 = v25->m_Name.u.m_pAsString;
                                if ( v26 == (const char *)-1 )
                                  v26 = &pParentName;
                                CDmeChannel::SetInput(this: v42, pElement: (int)pElementa, pAttribute: v26, index: 0);
                              }
                              _Msg(a1: GlobalIndex, a2: "removing duplicate flex controller %d %s\n");
                              RemoveElementFromRefereringAttributes(
                                m_hElement: (DmElementHandle_t)v21,
                                pElement: (int)&v17->CDmElement,
                                bPreserveOrder: true);
                              if ( v17 != (CDmeGlobalFlexControllerOperator *)-4 )
                              {
                                v27 = g_pDataModel->__vftable;
                                v28 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v17->CDmElement);
                                v27->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v28);
                              }
                            }
                          }
                        }
                      }
                    }
                    v12 = ci + 1;
                    ci = v12;
                    if ( v12 >= nChannels )
                      break;
                    Clip = &pChannelsClip->CDmeClip;
                  }
                  v10 = _j;
                  v9 = (CDmAttribute *)_cc;
                  v8 = v31;
                }
              }
              ++v10;
            }
          }
          v6 = _i + 1;
          _i = v6;
          if ( v6 >= _tc )
            break;
          TrackGroup = pTrackGroup;
        }
        ClipCount = (CDmAttribute *)nTrackGroups;
        v4 = gi;
      }
    }
    ++v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538000
// Name: private: void CFlexControlBuilder::BuildDesiredFlexControlList(class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::BuildDesiredFlexControlList(CFlexControlBuilder *this, CDmeGameModel *pGameModel)
{
  const studiohdr_t *StudioHdr; // eax
  int numflexcontrollers; // esi
  CFlexControlBuilder::FlexControllerInfo_t *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  CFlexControlBuilder::FlexControllerInfo_t *v7; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CFlexControlBuilder::FlexControllerInfo_t *v10; // ecx
  int v11; // eax
  CFlexControlBuilder::FlexControllerInfo_t *v12; // ebx
  char *v13; // esi
  float v14; // xmm0_4
  int *v15; // eax
  int *v16; // eax
  const studiohdr_t **v17; // eax
  CStudioHdr cHdr; // [esp+Ch] [ebp-68h] BYREF
  int i; // [esp+70h] [ebp-4h]
  CDmeGameModel *pGameModela; // [esp+7Ch] [ebp+8h]

  StudioHdr = CDmeGameModel::GetStudioHdr(this: pGameModel);
  CStudioHdr::CStudioHdr(this: &cHdr, pStudioHdr: StudioHdr, mdlcache: nullptr);
  numflexcontrollers = cHdr.m_pStudioHdr->numflexcontrollers;
  if ( this->m_FlexControllerInfo.m_Memory.m_nAllocationCount < numflexcontrollers
    && this->m_FlexControllerInfo.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_FlexControllerInfo.m_Memory.m_pMemory;
    this->m_FlexControllerInfo.m_Memory.m_nAllocationCount = numflexcontrollers;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (CFlexControlBuilder::FlexControllerInfo_t *)((int (__stdcall *)(CFlexControlBuilder::FlexControllerInfo_t *, int))v6->Realloc_2)(
                                                          a1: m_pMemory,
                                                          a2: 264 * numflexcontrollers);
    else
      v7 = (CFlexControlBuilder::FlexControllerInfo_t *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 264 * numflexcontrollers);
    this->m_FlexControllerInfo.m_Memory.m_pMemory = v7;
  }
  this->m_FlexControllerInfo.m_pElements = this->m_FlexControllerInfo.m_Memory.m_pMemory;
  if ( numflexcontrollers > 0 )
  {
    pGameModela = nullptr;
    for ( i = numflexcontrollers; i != 0; --i )
    {
      m_Size = this->m_FlexControllerInfo.m_Size;
      m_nAllocationCount = this->m_FlexControllerInfo.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CFlexControlBuilder::FlexControllerInfo_t,int>::Grow(
          this: &this->m_FlexControllerInfo.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_FlexControllerInfo.m_Size;
      v10 = this->m_FlexControllerInfo.m_Memory.m_pMemory;
      v11 = this->m_FlexControllerInfo.m_Size - m_Size - 1;
      this->m_FlexControllerInfo.m_pElements = this->m_FlexControllerInfo.m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 264 * v11);
      v12 = &this->m_FlexControllerInfo.m_Memory.m_pMemory[m_Size];
      v13 = (char *)cHdr.m_pStudioHdr + (unsigned int)pGameModela + cHdr.m_pStudioHdr->flexcontrollerindex;
      V_strncpy(pDest: v12->m_pFlexControlName, pSrc: &v13[*((_DWORD *)v13 + 1)], maxLen: 256);
      v12->m_nGlobalIndex = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v13[*((_DWORD *)v13 + 1)]);
      v12->m_flDefaultValue = 0.0;
      v14 = *((float *)v13 + 4);
      if ( v14 != *((float *)v13 + 3) )
        v12->m_flDefaultValue = COERCE_FLOAT(*((_DWORD *)v13 + 3) ^ _mask__NegFloat_)
                              / (float)(v14 - *((float *)v13 + 3));
      pGameModela = (CDmeGameModel *)((char *)pGameModela + 20);
    }
  }
  CStudioHdr::Term(this: &cHdr);
  v15 = cHdr.m_boneParent.m_Memory.m_pMemory;
  cHdr.m_boneParent.m_Size = 0;
  if ( cHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( cHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cHdr.m_boneParent.m_Memory.m_pMemory);
      v15 = nullptr;
      cHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  cHdr.m_boneParent.m_pElements = v15;
  if ( cHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      cHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v16 = cHdr.m_boneFlags.m_Memory.m_pMemory;
  cHdr.m_boneFlags.m_Size = 0;
  if ( cHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( cHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cHdr.m_boneFlags.m_Memory.m_pMemory);
      v16 = nullptr;
      cHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  cHdr.m_boneFlags.m_pElements = v16;
  if ( cHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      cHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v17 = cHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  cHdr.m_pStudioHdrCache.m_Size = 0;
  if ( cHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( cHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v17 = nullptr;
      cHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  cHdr.m_pStudioHdrCache.m_pElements = v17;
  if ( cHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v17 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
}

//------------------------------------------------------------------------------
// Address: 0x00538240
// Name: private: void CFlexControlBuilder::RemoveUnusedControlsAndChannels(class CDmeAnimationSet __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::RemoveUnusedControlsAndChannels(
        CFlexControlBuilder *this,
        CDmeAnimationSet *pAnimationSet,
        CDmeChannelsClip *pChannelsClip)
{
  CDmaVar<Vector> *Bookmarks; // esi
  float z; // eax
  DmElementArray_t *m_pStorage; // eax
  int m_Size; // ecx
  int v7; // esi
  CDmElement *v8; // eax
  CDmElement *v9; // ebx
  char v10; // al
  const char **v11; // edi
  CDmeChannel *Value; // eax
  CDmeChannel *v13; // esi
  CExpressionCalculator *v14; // ecx
  IDataModel_vtbl *v15; // esi
  int v16; // eax
  CDmrElementArray<CDmElement> controls; // [esp+Ch] [ebp-Ch] BYREF
  int i; // [esp+14h] [ebp-4h]

  Bookmarks = CDmeBookmarkSet::GetBookmarks(this: (CDmeTransform *)pAnimationSet);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controls);
  z = Bookmarks[1].m_Storage.z;
  if ( z == 0.0 || (*(_BYTE *)(LODWORD(z) + 16) & 0x1F) != 0xF )
  {
    m_pStorage = nullptr;
    controls.m_pAttribute = nullptr;
    controls.m_pStorage = nullptr;
    m_Size = 0;
  }
  else
  {
    controls.m_pAttribute = (CDmAttribute *)LODWORD(Bookmarks[1].m_Storage.z);
    m_pStorage = *(DmElementArray_t **)(LODWORD(z) + 4);
    controls.m_pStorage = m_pStorage;
    m_Size = m_pStorage->m_Size;
  }
  v7 = m_Size - 1;
  i = m_Size - 1;
  if ( m_Size - 1 < 0 )
    return;
  while ( 2 )
  {
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v7]);
    v9 = v8;
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
    {
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
        this: &controls,
        elem: v7);
      goto LABEL_21;
    }
    v10 = 0;
    v11 = s_pChannelControls;
    do
    {
      if ( v10 != 0 )
        goto LABEL_16;
      Value = CDmElement::GetValueElement<CDmeChannel>(this: v9, pAttributeName: *v11);
      v13 = Value;
      if ( Value != nullptr && CDmeChannel::GetToElement(this: Value) == nullptr )
      {
        CDmeChannelsClip::RemoveChannel(this: pChannelsClip, pChannel: v13);
        v14 = (CExpressionCalculator *)&v13->CDmElement;
        if ( v13 != (CDmeChannel *)-4 )
        {
          v15 = g_pDataModel->__vftable;
          v16 = CExpressionCalculator::VariableCount(this: v14);
          v15->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v16);
        }
LABEL_16:
        v10 = 1;
        goto LABEL_17;
      }
      v10 = 0;
LABEL_17:
      ++v11;
    }
    while ( (int)v11 < (int)s_pValueControls );
    if ( v10 != 0 )
      CDmeAnimationSet::RemoveControl(this: pAnimationSet, pControl: v9);
    v7 = i;
LABEL_21:
    i = --v7;
    if ( v7 >= 0 )
    {
      m_pStorage = controls.m_pStorage;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538370
// Name: private: void CFlexControlBuilder::ComputeChannelTimeTransform(class DmeTime_t __near *,double __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::ComputeChannelTimeTransform(
        CFlexControlBuilder *this,
        DmeTime_t *pOffset,
        long double *pScale,
        CDmeChannelsClip *pChannelsClip)
{
  float v4; // xmm0_4
  CDmeFilmClip *m_pMovie; // [esp-8h] [ebp-44h]
  DmeClipStack_t srcStack; // [esp+8h] [ebp-34h] BYREF
  DmeTime_t result; // [esp+38h] [ebp-4h] BYREF

  srcStack.m_tStart.m_tms = 0x80000000;
  srcStack.m_tDuration.m_tms = 0x80000000;
  srcStack.m_tOffset.m_tms = 0x80000000;
  m_pMovie = this->m_pMovie;
  memset(&srcStack, 0, 20);
  srcStack.m_bOptimized = false;
  CDmeClip::BuildClipStack(this: &pChannelsClip->CDmeClip, pStack: &srcStack, pMovie: m_pMovie, pShot: nullptr);
  pOffset->m_tms = DmeClipStack_t::FromChildMediaTime(this: &srcStack, &result, t: 0, bClamp: false)->m_tms;
  DmeClipStack_t::FromChildMediaTime(
    this: &srcStack,
    result: (DmeTime_t *)&pChannelsClip,
    t: (DmeTime_t)10000,
    bClamp: false);
  v4 = (float)((int)pChannelsClip - pOffset->m_tms) * 0.000099999997;
  pChannelsClip = (CDmeChannelsClip *)((char *)pChannelsClip - pOffset->m_tms);
  *pScale = v4;
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &srcStack.m_clips);
  if ( srcStack.m_clips.m_Memory.m_nGrowSize >= 0 && srcStack.m_clips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: srcStack.m_clips.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00538430
// Name: private: void CFlexControlBuilder::SetupLogs(class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::SetupLogs(
        CFlexControlBuilder *this,
        CDmeChannelsClip *pChannelsClip,
        bool bUseExistingLogs)
{
  CFlexControlBuilder *v3; // esi
  double v4; // xmm0_8
  int m_Size; // eax
  CFlexControlBuilder::ControlInfo_t *v6; // ebx
  CFlexControlBuilder::ExistingLogInfo_t *m_pExistingLog; // edi
  CDmeChannel **m_ppControlChannel; // ebx
  CDmeLog *Log; // eax
  CExpressionCalculator *m_pLog; // esi
  IDataModel_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  bool v14; // zf
  unsigned int sec; // [esp+10h] [ebp-38h]
  long double flTotalScale; // [esp+20h] [ebp-28h]
  double flOOTargetScale; // [esp+28h] [ebp-20h] BYREF
  CFlexControlBuilder::ControlInfo_t *info; // [esp+30h] [ebp-18h]
  CFlexControlBuilder *v19; // [esp+34h] [ebp-14h]
  int v20; // [esp+38h] [ebp-10h]
  int v21; // [esp+3Ch] [ebp-Ch]
  CDmeChannel **v22; // [esp+40h] [ebp-8h]
  DmeTime_t targetOffset; // [esp+44h] [ebp-4h] BYREF
  CDmeChannelsClip *pChannelsClipa; // [esp+50h] [ebp+8h]

  v3 = this;
  v19 = this;
  targetOffset.m_tms = 0x80000000;
  CFlexControlBuilder::ComputeChannelTimeTransform(
    this,
    pOffset: &targetOffset,
    pScale: &flOOTargetScale,
    pChannelsClip);
  v4 = 1.0;
  if ( flOOTargetScale != 0.0 )
    v4 = 1.0 / flOOTargetScale;
  m_Size = v3->m_ControlInfo.m_Size;
  flOOTargetScale = v4;
  if ( m_Size > 0 )
  {
    pChannelsClipa = nullptr;
    v20 = m_Size;
    while ( 1 )
    {
      v6 = (CFlexControlBuilder::ControlInfo_t *)((char *)pChannelsClipa
                                                + (unsigned int)v3->m_ControlInfo.m_Memory.m_pMemory);
      v21 = 3;
      info = v6;
      m_pExistingLog = v6->m_pExistingLog;
      m_ppControlChannel = v6->m_ppControlChannel;
      v22 = m_ppControlChannel;
      do
      {
        if ( *m_ppControlChannel != nullptr )
        {
          Log = CDmeChannel::GetLog(this: *m_ppControlChannel);
          m_pLog = (CExpressionCalculator *)Log;
          if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
            m_pLog = nullptr;
          if ( bUseExistingLogs && m_pExistingLog->m_pLog != nullptr )
          {
            CDmeChannel::SetLog(this: *m_ppControlChannel, pLog: (int)m_pExistingLog->m_pLog);
            if ( m_pLog != nullptr )
            {
              v11 = g_pDataModel->__vftable;
              v12 = CExpressionCalculator::VariableCount(this: m_pLog);
              v11->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v12);
              m_ppControlChannel = v22;
            }
            m_pLog = (CExpressionCalculator *)m_pExistingLog->m_pLog;
            flTotalScale = m_pExistingLog->m_flGlobalScale * flOOTargetScale;
            *(float *)&sec = (float)((float)(m_pExistingLog->m_GlobalOffset.m_tms - targetOffset.m_tms) * 0.000099999997)
                           * flOOTargetScale;
            v13 = DmeTime_t::RoundSecondsToTMS(sec);
            CDmeLog::ScaleBiasKeyTimes(this: (CDmeLog *)m_pLog, flScale: flTotalScale, nBias: (DmeTime_t)v13);
          }
          CDmeTypedLog<float>::SetDefaultValue(this: (CDmeTypedLog<float> *)m_pLog, value: &info->m_flDefaultValue);
        }
        ++m_ppControlChannel;
        ++m_pExistingLog;
        v14 = v21-- == 1;
        v22 = m_ppControlChannel;
      }
      while ( !v14 );
      pChannelsClipa = (CDmeChannelsClip *)((char *)pChannelsClipa + 344);
      if ( --v20 == 0 )
        break;
      v3 = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005386B0
// Name: private: void CFlexControlBuilder::BuildDesiredControlList(class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::BuildDesiredControlList(CFlexControlBuilder *this, CDmeGameModel *pGameModel)
{
  CFlexControlBuilder *v2; // edi
  int v3; // ebx
  int m_pControlName; // esi
  CFlexControlBuilder::FlexControllerInfo_t *v5; // edi
  CFlexControlBuilder::FlexControllerInfo_t *m_pMemory; // eax
  CFlexControlBuilder::FlexControllerInfo_t *leftInfo; // [esp+8h] [ebp-10h]
  int nCount; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+14h] [ebp-4h]

  v2 = this;
  v3 = 0;
  nCount = this->m_FlexControllerInfo.m_Size;
  if ( nCount > 0 )
  {
    v10 = 0;
    while ( 1 )
    {
      m_pControlName = (int)v2->m_ControlInfo.m_Memory.m_pMemory[CUtlVector<CFlexControlBuilder::ControlInfo_t,CUtlMemory<CFlexControlBuilder::ControlInfo_t,int>>::InsertBefore(
                                                                   this: &v2->m_ControlInfo,
                                                                   elem: v2->m_ControlInfo.m_Size)].m_pControlName;
      memset(dst: (unsigned __int8 *)m_pControlName, value: 0, count: 0x158u);
      v5 = &v2->m_FlexControllerInfo.m_Memory.m_pMemory[v10];
      if ( V_strnicmp(s1: "right_", s2: v5->m_pFlexControlName, n: 6) != 0 || v3 >= nCount - 1 )
      {
        *(_BYTE *)(m_pControlName + 256) &= ~1u;
        *(_DWORD *)(m_pControlName + 268) = v3;
        *(_DWORD *)(m_pControlName + 272) = -1;
        *(_DWORD *)(m_pControlName + 276) = -1;
        V_strncpy(pDest: (char *)m_pControlName, pSrc: v5->m_pFlexControlName, maxLen: 256);
        *(float *)(m_pControlName + 264) = v5->m_flDefaultValue;
      }
      else
      {
        m_pMemory = this->m_FlexControllerInfo.m_Memory.m_pMemory;
        *(_BYTE *)(m_pControlName + 256) |= 1u;
        *(_DWORD *)(m_pControlName + 272) = v3++;
        leftInfo = &m_pMemory[v10 + 1];
        *(_DWORD *)(m_pControlName + 268) = -1;
        *(_DWORD *)(m_pControlName + 276) = v3;
        V_strncpy(pDest: (char *)m_pControlName, pSrc: &v5->m_pFlexControlName[6], maxLen: 256);
        ++v10;
        *(float *)(m_pControlName + 264) = (float)(leftInfo->m_flDefaultValue + v5->m_flDefaultValue) * 0.5;
      }
      ++v10;
      if ( ++v3 >= nCount )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005387E0
// Name: private: void CFlexControlBuilder::GetExistingMonoLog(struct CFlexControlBuilder::ExistingLogInfo_t __near *,class CDmeFilmClip __near *,class CDmeGlobalFlexControllerOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::GetExistingMonoLog(
        CFlexControlBuilder *this,
        CFlexControlBuilder::ExistingLogInfo_t *pExistingLog,
        CDmeFilmClip *pClip,
        CDmeGlobalFlexControllerOperator *pMonoOp)
{
  bool v4; // zf
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmElement *v6; // ecx
  CDmeChannel *Referring; // eax
  CDmeChannel *v8; // edi
  CDmeLog *Log; // eax
  CDmeTypedLog<float> *v10; // esi
  CDmeChannelsClip *ChannelsClipContainingChannel; // eax

  v4 = (_S2_3 & 1) == 0;
  pExistingLog->m_pLog = nullptr;
  if ( v4 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_3 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symToElement, a3: "toElement");
  }
  if ( pMonoOp != nullptr )
    v6 = &pMonoOp->CDmElement;
  else
    v6 = nullptr;
  Referring = FindReferringElement<CDmeChannel>(
                pElement: (CExpressionCalculator *)v6,
                symAttrName: symToElement,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  v8 = Referring;
  if ( Referring != nullptr )
  {
    Log = CDmeChannel::GetLog(this: Referring);
    v10 = (CDmeTypedLog<float> *)Log;
    if ( Log != nullptr && Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
    {
      ChannelsClipContainingChannel = CFlexControlBuilder::FindChannelsClipContainingChannel(this, pClip, pSearch: v8);
      if ( ChannelsClipContainingChannel != nullptr )
      {
        CFlexControlBuilder::ComputeChannelTimeTransform(
          this,
          pOffset: &pExistingLog->m_GlobalOffset,
          pScale: &pExistingLog->m_flGlobalScale,
          pChannelsClip: ChannelsClipContainingChannel);
        pExistingLog->m_pLog = v10;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005388A0
// Name: private: void CFlexControlBuilder::RemoveChannelFromClips(class CDmeChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::RemoveChannelFromClips(CFlexControlBuilder *this, CDmeChannel *pChannel)
{
  CDmeChannel *v2; // ebx
  int v3; // esi
  CDmElement *v4; // ecx
  int m_Size; // edi
  const char **v6; // esi
  CExpressionCalculator *v7; // ecx
  CDmElement *Referring; // eax
  CUtlVector<CDmeChannelsClip *,CUtlMemory<CDmeChannelsClip *,int> > channelsClips; // [esp+Ch] [ebp-14h] BYREF

  v2 = pChannel;
  v3 = 0;
  memset(&channelsClips, 0, sizeof(channelsClips));
  if ( pChannel != nullptr )
    v4 = &pChannel->CDmElement;
  else
    v4 = nullptr;
  FindReferringElements<CDmeChannelsClip>(
    list: &channelsClips,
    pElement: v4,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  m_Size = channelsClips.m_Size;
  if ( channelsClips.m_Size > 0 )
  {
    do
      CDmeChannelsClip::RemoveChannel(this: channelsClips.m_Memory.m_pMemory[v3++], pChannel: v2);
    while ( v3 < m_Size );
  }
  v6 = s_pChannelControls;
  do
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pChannel, a3: *v6);
    if ( v2 != nullptr )
      v7 = (CExpressionCalculator *)&v2->CDmElement;
    else
      v7 = nullptr;
    Referring = FindReferringElement<CDmElement>(
                  pElement: v7,
                  symAttrName: (CUtlSymbolLarge)pChannel,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmElement::RemoveAttribute(this: Referring, pAttributeName: *v6);
    ++v6;
  }
  while ( (int)v6 < (int)s_pValueControls );
  if ( channelsClips.m_Memory.m_nGrowSize >= 0 && channelsClips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelsClips.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00538980
// Name: private: void CFlexControlBuilder::CleanupExistingFlexController(class CDmeGameModel __near *,class CDmeGlobalFlexControllerOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::CleanupExistingFlexController(
        CFlexControlBuilder *this,
        CDmeGameModel *pGameModel,
        CDmeGlobalFlexControllerOperator *pOp)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmElement *v5; // ecx
  CDmeChannel *Referring; // eax
  CDmeChannel *v7; // esi
  CExpressionCalculator *v8; // ecx
  IDataModel_vtbl *v9; // esi
  int v10; // eax
  IDataModel_vtbl *v11; // esi
  int v12; // eax

  if ( (_S1_6 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_6 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symToElement_0, a3: "toElement");
  }
  if ( pOp != nullptr )
    v5 = &pOp->CDmElement;
  else
    v5 = nullptr;
  Referring = FindReferringElement<CDmeChannel>(
                pElement: (CExpressionCalculator *)v5,
                symAttrName: symToElement_0,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  v7 = Referring;
  if ( Referring != nullptr )
  {
    CFlexControlBuilder::RemoveChannelFromClips(this, pChannel: Referring);
    v8 = (CExpressionCalculator *)&v7->CDmElement;
    if ( v7 != (CDmeChannel *)-4 )
    {
      v9 = g_pDataModel->__vftable;
      v10 = CExpressionCalculator::VariableCount(this: v8);
      v9->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v10);
    }
  }
  CDmeGameModel::RemoveGlobalFlexController(this: pGameModel, controller: pOp);
  if ( pOp != nullptr && pOp != (CDmeGlobalFlexControllerOperator *)-4 )
  {
    v11 = g_pDataModel->__vftable;
    v12 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&pOp->CDmElement);
    v11->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538A40
// Name: private: void CFlexControlBuilder::RemoveUnusedExistingFlexControllers(class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::RemoveUnusedExistingFlexControllers(
        CFlexControlBuilder *this,
        CDmeGameModel *pGameModel)
{
  int v2; // eax
  CDmeGlobalFlexControllerOperator *GlobalFlexController; // eax
  CFlexControlBuilder *v4; // ecx
  int m_Size; // ebx
  int v6; // esi
  int v7; // edi
  int i; // [esp+0h] [ebp-10h]
  char *s1; // [esp+4h] [ebp-Ch]
  CDmeGlobalFlexControllerOperator *pOp; // [esp+Ch] [ebp-4h]

  v2 = CDmeGameModel::NumGlobalFlexControllers(this: pGameModel) - 1;
  for ( i = v2; i >= 0; --i )
  {
    GlobalFlexController = CDmeGameModel::GetGlobalFlexController(this: pGameModel, localIndex: v2);
    pOp = GlobalFlexController;
    if ( GlobalFlexController != nullptr )
    {
      s1 = (char *)&pParentName;
      if ( GlobalFlexController->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
        s1 = (char *)GlobalFlexController->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id;
      v4 = this;
      m_Size = this->m_FlexControllerInfo.m_Size;
      v6 = 0;
      if ( m_Size <= 0 )
        goto LABEL_11;
      v7 = 0;
      while ( _V_stricmp(s1, s2: this->m_FlexControllerInfo.m_Memory.m_pMemory[v7].m_pFlexControlName) != 0 )
      {
        ++v6;
        ++v7;
        if ( v6 >= m_Size )
          goto LABEL_11;
      }
      if ( v6 < 0 )
      {
LABEL_11:
        _Msg(a1: v4, a2: "removing flex controller %s\n");
        CFlexControlBuilder::CleanupExistingFlexController(this, pGameModel, pOp);
      }
    }
    v2 = i - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538B00
// Name: private: void CFlexControlBuilder::BuildExistingFlexControlLogList(class CDmeFilmClip __near *,class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::BuildExistingFlexControlLogList(
        CFlexControlBuilder *this,
        CDmeFilmClip *pCurrentClip,
        CDmeGameModel *pGameModel)
{
  CFlexControlBuilder::ControlInfo_t *v4; // edi
  CFlexControlBuilder::FlexControllerInfo_t *v5; // ebx
  CDmeGlobalFlexControllerOperator *GlobalFlexController; // eax
  const char *m_pAsString; // ecx
  CDmeGlobalFlexControllerOperator *v8; // eax
  int v9; // ecx
  CDmeGlobalFlexControllerOperator *v10; // ebx
  CDmeGlobalFlexControllerOperator *pRightOp; // [esp+4h] [ebp-10h]
  int m_Size; // [esp+8h] [ebp-Ch]
  CDmeGlobalFlexControllerOperator *pLeftOp; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]

  if ( this->m_ControlInfo.m_Size > 0 )
  {
    v14 = 0;
    m_Size = this->m_ControlInfo.m_Size;
    do
    {
      v4 = &this->m_ControlInfo.m_Memory.m_pMemory[v14];
      if ( (*((_BYTE *)v4 + 256) & 1) != 0 )
      {
        v5 = &this->m_FlexControllerInfo.m_Memory.m_pMemory[v4->m_pControllerIndex[2]];
        pRightOp = CDmeGameModel::FindGlobalFlexController(
                     this: pGameModel,
                     nGlobalIndex: this->m_FlexControllerInfo.m_Memory.m_pMemory[v4->m_pControllerIndex[1]].m_nGlobalIndex);
        GlobalFlexController = CDmeGameModel::FindGlobalFlexController(
                                 this: pGameModel,
                                 nGlobalIndex: v5->m_nGlobalIndex);
        pLeftOp = GlobalFlexController;
        if ( pRightOp != nullptr && GlobalFlexController != nullptr )
        {
          m_pAsString = &pParentName;
          if ( pRightOp->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
            m_pAsString = pRightOp->m_Name.m_Storage.u.m_pAsString;
          _Msg(a1: m_pAsString, a2: "replacing stereo flex controllers %s and %s\n");
          CFlexControlBuilder::GetExistingMonoLog(
            this,
            pExistingLog: &v4->m_pExistingLog[1],
            pClip: pCurrentClip,
            pMonoOp: pRightOp);
          CFlexControlBuilder::GetExistingMonoLog(
            this,
            pExistingLog: &v4->m_pExistingLog[2],
            pClip: pCurrentClip,
            pMonoOp: pLeftOp);
          CFlexControlBuilder::CleanupExistingFlexController(this, pGameModel, pOp: pRightOp);
          CFlexControlBuilder::CleanupExistingFlexController(this, pGameModel, pOp: pLeftOp);
        }
      }
      else
      {
        v8 = CDmeGameModel::FindGlobalFlexController(
               this: pGameModel,
               nGlobalIndex: this->m_FlexControllerInfo.m_Memory.m_pMemory[v4->m_pControllerIndex[0]].m_nGlobalIndex);
        v10 = v8;
        if ( v8 != nullptr )
        {
          _Msg(a1: v9, a2: "replacing mono flex controller %s\n");
          CFlexControlBuilder::GetExistingMonoLog(
            this,
            pExistingLog: v4->m_pExistingLog,
            pClip: pCurrentClip,
            pMonoOp: v10);
          CFlexControlBuilder::CleanupExistingFlexController(this, pGameModel, pOp: v10);
        }
      }
      ++v14;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538C60
// Name: public: void CFlexControlBuilder::CreateAnimationSetControls(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeFilmClip __near *,class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::CreateAnimationSetControls(
        CFlexControlBuilder *this,
        CDmeFilmClip *pMovie,
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        CDmeFilmClip *pSourceClip,
        CDmeChannelsClip *pDestClip,
        bool bUseExistingLogs)
{
  this->m_pMovie = pMovie;
  CFlexControlBuilder::FixupExistingFlexControlLogList(this, pCurrentClip: pSourceClip, pGameModel);
  CFlexControlBuilder::BuildDesiredFlexControlList(this, pGameModel);
  CFlexControlBuilder::BuildDesiredControlList(this, pGameModel);
  CFlexControlBuilder::RemoveUnusedExistingFlexControllers(this, pGameModel);
  CFlexControlBuilder::RemoveUnusedControlsAndChannels(this, pAnimationSet, pChannelsClip: pDestClip);
  if ( bUseExistingLogs )
    CFlexControlBuilder::BuildExistingFlexControlLogList(this, pCurrentClip: pSourceClip, pGameModel);
  CFlexControlBuilder::CreateFlexControls(this, pAnimationSet);
  CFlexControlBuilder::AttachControlsToGameModel(this, pAnimationSet, pGameModel, pChannelsClip: pDestClip);
  CFlexControlBuilder::SetupLogs(this, pChannelsClip: pDestClip, bUseExistingLogs);
}

//------------------------------------------------------------------------------
// Address: 0x005385C0
// Name: bool FindReferringElements<class CDmeChannelsClip>(class CUtlVector<class CDmeChannelsClip __near *,class CUtlMemory<class CDmeChannelsClip __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeChannelsClip>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeChannelsClip *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeChannelsClip **v11; // ecx
  int v12; // eax
  CDmeChannelsClip **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeChannelsClip>(
           this: &it,
           symAttrName,
           bMustBeInSameFile,
           depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeChannelsClip **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeChannelsClip **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00538CF0
// Name: class CDmeTimeSelection __near * CreateElement<class CDmeTimeSelection>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeSelection *__cdecl CreateElement<CDmeTimeSelection>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTimeSelection::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeTimeSelection::m_classType) )
    return (CDmeTimeSelection *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00538D50
// Name: class CDmeGraphEditorState __near * CreateElement<class CDmeGraphEditorState>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGraphEditorState *__cdecl CreateElement<CDmeGraphEditorState>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeGraphEditorState::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeGraphEditorState::m_classType) )
    return (CDmeGraphEditorState *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00538DB0
// Name: class CDmeProceduralPresetSettings __near * CreateElement<class CDmeProceduralPresetSettings>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeProceduralPresetSettings *__cdecl CreateElement<CDmeProceduralPresetSettings>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeProceduralPresetSettings::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeProceduralPresetSettings::m_classType) )
    return (CDmeProceduralPresetSettings *)v5;
  else
    return nullptr;
}

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0053D8D0
// Name: void SetupDefaultFlexController(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultFlexController()
{
  g_pGlobalFlexController = &s_GlobalFlexController;
}

//------------------------------------------------------------------------------
// Address: 0x0053D8E0
// Name: public: void CUtlMemory<struct CFlexControlBuilder::FlexControllerInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFlexControlBuilder::FlexControllerInfo_t,int>::Grow(
        CUtlMemory<CFlexControlBuilder::FlexControllerInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CFlexControlBuilder::FlexControllerInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 1;
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
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CFlexControlBuilder::FlexControllerInfo_t *)_g_pMemAlloc->Realloc_2(
                                                                       this: _g_pMemAlloc,
                                                                       a2: m_pMemory,
                                                                       a3: v7);
    else
      this->m_pMemory = (CFlexControlBuilder::FlexControllerInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053D980
// Name: public: virtual int CDefaultGlobalFlexController::FindGlobalFlexController(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDefaultGlobalFlexController::FindGlobalFlexController(
        CDefaultGlobalFlexController *this,
        const char *name)
{
  return CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&name + 1, pString: name)->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0053D9A0
// Name: public: virtual char const __near * CDefaultGlobalFlexController::GetGlobalFlexControllerName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDefaultGlobalFlexController::GetGlobalFlexControllerName(
        CDefaultGlobalFlexController *this,
        CUtlSymbol idx)
{
  return CUtlSymbolTable::String(this: &this->m_SymbolTable, id: idx);
}

//------------------------------------------------------------------------------
// Address: 0x0053D9C0
// Name: public: void CUtlMemory<struct CFlexControlBuilder::ControlInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFlexControlBuilder::ControlInfo_t,int>::Grow(
        CUtlMemory<CFlexControlBuilder::ControlInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CFlexControlBuilder::ControlInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 1;
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
    v7 = 344 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CFlexControlBuilder::ControlInfo_t *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (CFlexControlBuilder::ControlInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DA60
// Name: private: void CFlexControlBuilder::BuildFlexControllerOps(class CDmeGameModel __near *,class CDmeChannelsClip __near *,struct CFlexControlBuilder::ControlInfo_t __near &,enum CFlexControlBuilder::ControlField_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::BuildFlexControllerOps(
        CFlexControlBuilder *this,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip,
        CDmeGlobalFlexControllerOperator *info,
        CFlexControlBuilder::ControlField_t field)
{
  CFlexControlBuilder::ControlField_t v5; // ebx
  CFlexControlBuilder::FlexControllerInfo_t *v7; // esi
  CDmElement *v8; // eax
  CDmeChannel *PassThruConnection; // eax
  const char *v10; // esi
  CDmAttribute *Attribute; // eax
  char pName[256]; // [esp+Ch] [ebp-100h] BYREF
  CDmeGlobalFlexControllerOperator *pFlexControllerOp; // [esp+11Ch] [ebp+10h]
  CDmElement *pFlexControllerOpa; // [esp+11Ch] [ebp+10h]

  v5 = field;
  v7 = &this->m_FlexControllerInfo.m_Memory.m_pMemory[*((_DWORD *)&info[2].m_fileId + field)];
  pFlexControllerOp = CDmeGameModel::AddGlobalFlexController(
                        this: pGameModel,
                        controllerName: v7->m_pFlexControlName,
                        globalIndex: (DmAttributeHandle_t)v7->m_nGlobalIndex);
  V_snprintf(pDest: pName, maxLen: 256, pFormat: "%s_flex_channel", v7->m_pFlexControlName);
  if ( pFlexControllerOp != nullptr )
    v8 = &pFlexControllerOp->CDmElement;
  else
    v8 = nullptr;
  PassThruConnection = CDmeChannelsClip::CreatePassThruConnection(
                         this: pChannelsClip,
                         passThruName: pName,
                         pFrom: (CDmElement *)info[2].m_pAttributes,
                         pFromAttribute: s_pValueControls[v5],
                         pTo: v8,
                         pToAttribute: "flexWeight",
                         index: 0);
  *(&info[2].m_nSortKey + v5) = (int)PassThruConnection;
  v10 = s_pChannelControls[v5];
  pFlexControllerOpa = (CDmElement *)info[2].m_pAttributes;
  if ( PassThruConnection != nullptr )
    field = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&PassThruConnection->CDmElement);
  else
    field = -1;
  Attribute = CDmElement::FindAttribute(this: pFlexControllerOpa, pAttributeName: v10);
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(
                      this: pFlexControllerOpa,
                      pAttributeName: v10,
                      type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&field);
  }
  CDmeChannel::SetMode(this: *((CDmeChannel **)&info[2].m_nSortKey + v5), mode: CM_PLAY);
}

//------------------------------------------------------------------------------
// Address: 0x0053DB50
// Name: private: void CFlexControlBuilder::AttachControlsToGameModel(class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::AttachControlsToGameModel(
        CFlexControlBuilder *this,
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip)
{
  CFlexControlBuilder *v4; // ebx
  int m_Size; // eax
  CFlexControlBuilder::ControlInfo_t *v6; // edi
  int m_pFlexControlName; // esi
  CDmeGlobalFlexControllerOperator *v8; // ebx
  CDmElement *v9; // ebx
  CDmeChannel *PassThruConnection; // eax
  const char *v11; // esi
  CDmElement *m_pControl; // ebx
  CDmAttribute *Attribute; // eax
  char pDest[256]; // [esp+4h] [ebp-110h] BYREF
  DmElementHandle_t value; // [esp+104h] [ebp-10h] BYREF
  int i; // [esp+108h] [ebp-Ch]
  CFlexControlBuilder *v17; // [esp+10Ch] [ebp-8h]
  unsigned int v18; // [esp+110h] [ebp-4h]

  v4 = this;
  m_Size = this->m_ControlInfo.m_Size;
  v17 = this;
  if ( m_Size > 0 )
  {
    v18 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v6 = &v4->m_ControlInfo.m_Memory.m_pMemory[v18 / 0x158];
      if ( (*((_BYTE *)v6 + 256) & 1) != 0 )
      {
        m_pFlexControlName = (int)v4->m_FlexControllerInfo.m_Memory.m_pMemory[v6->m_pControllerIndex[1]].m_pFlexControlName;
        v8 = CDmeGameModel::AddGlobalFlexController(
               this: pGameModel,
               controllerName: (const char *)m_pFlexControlName,
               globalIndex: *(DmAttributeHandle_t *)(m_pFlexControlName + 260));
        V_snprintf(pDest, maxLen: 256, pFormat: "%s_flex_channel", (const char *)m_pFlexControlName);
        if ( v8 != nullptr )
          v9 = &v8->CDmElement;
        else
          v9 = nullptr;
        PassThruConnection = CDmeChannelsClip::CreatePassThruConnection(
                               this: pChannelsClip,
                               passThruName: pDest,
                               pFrom: v6->m_pControl,
                               pFromAttribute: s_pValueControls[1],
                               pTo: v9,
                               pToAttribute: "flexWeight",
                               index: 0);
        v6->m_ppControlChannel[1] = PassThruConnection;
        v11 = s_pChannelControls[1];
        m_pControl = v6->m_pControl;
        if ( PassThruConnection != nullptr )
          value = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&PassThruConnection->CDmElement);
        else
          value = DMELEMENT_HANDLE_INVALID;
        Attribute = CDmElement::FindAttribute(this: m_pControl, pAttributeName: v11);
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: m_pControl, pAttributeName: v11, type: AT_FIRST_VALUE_TYPE)) != nullptr )
        {
          CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
        }
        CDmeChannel::SetMode(this: v6->m_ppControlChannel[1], mode: CM_PLAY);
        CFlexControlBuilder::BuildFlexControllerOps(
          this: v17,
          pGameModel,
          pChannelsClip,
          info: (CDmeGlobalFlexControllerOperator *)v6,
          field: CONTROL_LEFT);
        v4 = v17;
      }
      else
      {
        CFlexControlBuilder::BuildFlexControllerOps(
          this: v4,
          pGameModel,
          pChannelsClip,
          info: (CDmeGlobalFlexControllerOperator *)v6,
          field: CONTROL_MONO);
      }
      v18 += 344;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DCA0
// Name: private: void CFlexControlBuilder::CreateFlexControls(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::CreateFlexControls(CFlexControlBuilder *this, CDmeAnimationSet *pAnimationSet)
{
  CFlexControlBuilder::ControlInfo_t *v2; // ebx
  CDmElement *v3; // esi
  const char **v4; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CFlexControlBuilder *v9; // [esp+0h] [ebp-Ch]
  int m_Size; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]

  v9 = this;
  if ( this->m_ControlInfo.m_Size > 0 )
  {
    v11 = 0;
    m_Size = this->m_ControlInfo.m_Size;
    while ( 1 )
    {
      v2 = &this->m_ControlInfo.m_Memory.m_pMemory[v11];
      v3 = CDmeAnimationSet::FindOrAddControl(
             this: pAnimationSet,
             pControlName: v2->m_pControlName,
             transformControl: false,
             bMustBeNew: false);
      v2->m_pControl = v3;
      v4 = s_pChannelControls;
      do
        CDmElement::RemoveAttribute(this: v3, pAttributeName: *v4++);
      while ( (int)v4 < (int)s_pValueControls );
      Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "defaultValue");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: Attribute, value: &v2->m_flDefaultValue);
      }
      if ( (*((_BYTE *)v2 + 256) & 1) != 0 )
      {
        CDmElement::RemoveAttribute(this: v3, pAttributeName: "value");
        if ( CDmElement::FindAttribute(this: v3, pAttributeName: "leftValue") == nullptr )
        {
          v6 = CDmElement::FindAttribute(this: v3, pAttributeName: "leftValue");
          if ( v6 != nullptr
            || (v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v6, value: &v2->m_flDefaultValue);
          }
        }
        if ( CDmElement::FindAttribute(this: v3, pAttributeName: "rightValue") == nullptr )
        {
          v7 = CDmElement::FindAttribute(this: v3, pAttributeName: "rightValue");
          if ( v7 != nullptr
            || (v7 = CDmElement::CreateAttribute(this: v3, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v7, value: &v2->m_flDefaultValue);
          }
        }
      }
      else
      {
        if ( CDmElement::FindAttribute(this: v3, pAttributeName: "value") == nullptr )
        {
          v8 = CDmElement::FindAttribute(this: v3, pAttributeName: "value");
          if ( v8 != nullptr
            || (v8 = CDmElement::CreateAttribute(this: v3, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v8, value: &v2->m_flDefaultValue);
          }
        }
        CDmElement::RemoveAttribute(this: v3, pAttributeName: "leftValue");
        CDmElement::RemoveAttribute(this: v3, pAttributeName: "rightValue");
      }
      ++v11;
      if ( --m_Size == 0 )
        break;
      this = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DE40
// Name: private: class CDmeChannelsClip __near * CFlexControlBuilder::FindChannelsClipContainingChannel(class CDmeFilmClip __near *,class CDmeChannel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CFlexControlBuilder::FindChannelsClipContainingChannel(
        CFlexControlBuilder *this,
        CDmeFilmClip *pClip,
        CDmeChannel *pSearch)
{
  int v3; // esi
  CDmeTrackGroup *TrackGroup; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // eax
  int v9; // ecx
  CDmeClip *Clip; // eax
  CDmeClip *v11; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmeChannel *v15; // eax
  CDmAttribute *gc; // [esp+Ch] [ebp-24h]
  int _tc; // [esp+10h] [ebp-20h]
  CDmeTrackGroup *pTrackGroup; // [esp+14h] [ebp-1Ch]
  int _cc; // [esp+18h] [ebp-18h]
  CDmeTransform *v21; // [esp+1Ch] [ebp-14h]
  int nChannels; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  int _i; // [esp+28h] [ebp-8h]
  int _j; // [esp+2Ch] [ebp-4h]

  v3 = 0;
  gc = CDmeTrack::GetClipCount(this: (CDmeTransform *)pClip);
  i = 0;
  if ( (int)gc <= 0 )
    return nullptr;
  while ( 1 )
  {
    TrackGroup = CDmeClip::GetTrackGroup(this: pClip, nIndex: v3);
    v5 = 0;
    pTrackGroup = TrackGroup;
    _tc = TrackGroup->m_Tracks.m_Storage.m_Size;
    _i = 0;
    if ( _tc > 0 )
      break;
LABEL_20:
    i = ++v3;
    if ( v3 >= (int)gc )
      return nullptr;
  }
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: TrackGroup->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    v21 = (CDmeTransform *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == 0 )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      _cc = (int)ClipCount;
      _j = 0;
      if ( (int)ClipCount > 0 )
        break;
    }
LABEL_18:
    _i = ++v5;
    if ( v5 >= _tc )
    {
      v3 = i;
      goto LABEL_20;
    }
  }
  while ( 1 )
  {
    Clip = CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9);
    v11 = Clip;
    if ( Clip != nullptr )
    {
      v12 = 0;
      nChannels = *(_DWORD *)&Clip[1].m_Id.m_Value[8];
      if ( nChannels > 0 )
        break;
    }
LABEL_16:
    v9 = _j + 1;
    _j = v9;
    if ( v9 >= _cc )
    {
      TrackGroup = pTrackGroup;
      v5 = _i;
      goto LABEL_18;
    }
  }
  while ( 1 )
  {
    v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v11[1].OnAttributeChanged + v12));
    v14 = v13;
    if ( v13 != nullptr && v13->IsA(this: v13, a2: CDmeChannel::m_classType) )
      v15 = (CDmeChannel *)((char *)&v14[-1] + 64);
    else
      v15 = nullptr;
    if ( v15 == pSearch )
      return (CDmeChannelsClip *)v11;
    if ( ++v12 >= nChannels )
    {
      v7 = v21;
      goto LABEL_16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DF90
// Name: private: void CFlexControlBuilder::FixupExistingFlexControlLogList(class CDmeFilmClip __near *,class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::FixupExistingFlexControlLogList(
        CFlexControlBuilder *this,
        CDmeFilmClip *pCurrentClip,
        CDmeGameModel *pGameModel)
{
  CDmAttribute *ClipCount; // edi
  int v4; // esi
  CDmeTrackGroup *TrackGroup; // eax
  int v6; // ecx
  CDmElement *v7; // eax
  CDmeTransform *v8; // esi
  CDmAttribute *v9; // ebx
  int v10; // edi
  CDmeClip *Clip; // eax
  int v12; // ecx
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmElement *v15; // eax
  CDmElement *v16; // esi
  CDmeGlobalFlexControllerOperator *v17; // ebx
  CDmAttribute *GlobalIndex; // edi
  CDmeGlobalFlexControllerOperator *GlobalFlexController; // eax
  int v20; // ecx
  CDmeGlobalFlexControllerOperator *v21; // esi
  const char *m_pAsString; // eax
  CDmAttribute *v23; // eax
  const char *v24; // eax
  CDmAttribute *v25; // eax
  const char *v26; // eax
  IDataModel_vtbl *v27; // esi
  int v28; // eax
  int nTrackGroups; // [esp+Ch] [ebp-38h]
  int _tc; // [esp+10h] [ebp-34h]
  CDmeTransform *v31; // [esp+14h] [ebp-30h]
  int _cc; // [esp+18h] [ebp-2Ch]
  int nChannels; // [esp+1Ch] [ebp-28h]
  CDmeChannelsClip *pChannelsClip; // [esp+24h] [ebp-20h]
  CDmeTrackGroup *pTrackGroup; // [esp+28h] [ebp-1Ch]
  int gi; // [esp+2Ch] [ebp-18h]
  int _i; // [esp+30h] [ebp-14h]
  int _j; // [esp+34h] [ebp-10h]
  int ci; // [esp+38h] [ebp-Ch]
  CDmElement *pElement; // [esp+3Ch] [ebp-8h]
  CDmElement *pElementa; // [esp+3Ch] [ebp-8h]
  CDmeChannel *v42; // [esp+40h] [ebp-4h]

  ClipCount = CDmeTrack::GetClipCount(this: (CDmeTransform *)pCurrentClip);
  v4 = 0;
  nTrackGroups = (int)ClipCount;
  for ( gi = 0; v4 < (int)ClipCount; gi = v4 )
  {
    TrackGroup = CDmeClip::GetTrackGroup(this: pCurrentClip, nIndex: v4);
    pTrackGroup = TrackGroup;
    if ( TrackGroup != nullptr )
    {
      v6 = 0;
      _tc = TrackGroup->m_Tracks.m_Storage.m_Size;
      _i = 0;
      if ( _tc > 0 )
      {
        while ( 1 )
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: TrackGroup->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
          v8 = (CDmeTransform *)v7;
          v31 = (CDmeTransform *)v7;
          if ( v7 != nullptr
            && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
            && CDmeTrack::GetClipType(this: (CDmeTrack *)v8) == 0 )
          {
            v9 = CDmeTrack::GetClipCount(this: v8);
            v10 = 0;
            _cc = (int)v9;
            for ( _j = 0; v10 < (int)v9; _j = v10 )
            {
              Clip = CDmeTrack::GetClip(this: (CDmeTrack *)v8, i: v10);
              pChannelsClip = (CDmeChannelsClip *)Clip;
              if ( Clip != nullptr )
              {
                v12 = 0;
                nChannels = *(_DWORD *)&Clip[1].m_Id.m_Value[8];
                ci = 0;
                if ( nChannels > 0 )
                {
                  while ( 1 )
                  {
                    v13 = g_pDataModel->GetElement(
                            this: g_pDataModel,
                            a2: *((_DWORD *)&Clip[1].OnAttributeChanged + v12));
                    v14 = v13;
                    if ( v13 != nullptr && v13->IsA(this: v13, a2: CDmeChannel::m_classType) )
                    {
                      v42 = (CDmeChannel *)((char *)&v14[-1] + 64);
                      if ( v14 != (CDmElement *)4 )
                      {
                        v15 = CDmeChannel::GetToElement(this: (CDmeChannel *)((char *)&v14[-1] + 64));
                        v16 = v15;
                        if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeGlobalFlexControllerOperator::m_classType) )
                        {
                          v17 = (CDmeGlobalFlexControllerOperator *)((char *)&v16[-1] + 64);
                          if ( v16 != (CDmElement *)4
                            && v17->m_gameModel.m_Storage.m_Handle == CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pGameModel) )
                          {
                            GlobalIndex = CDmeGlobalFlexControllerOperator::GetGlobalIndex(this: (CDmeTransform *)v17);
                            GlobalFlexController = CDmeGameModel::FindGlobalFlexController(
                                                     this: pGameModel,
                                                     nGlobalIndex: (int)GlobalIndex);
                            v21 = GlobalFlexController;
                            if ( GlobalFlexController != v17 )
                            {
                              if ( GlobalFlexController != nullptr )
                                goto LABEL_26;
                              _Msg(a1: v20, a2: "adding missing flex controller %d %s\n");
                              m_pAsString = v17->m_Name.m_Storage.u.m_pAsString;
                              if ( m_pAsString == (const char *)-1 )
                                m_pAsString = &pch;
                              v21 = CDmeGameModel::AddGlobalFlexController(
                                      this: pGameModel,
                                      controllerName: m_pAsString,
                                      globalIndex: (DmAttributeHandle_t)GlobalIndex);
                              if ( v21 != nullptr )
LABEL_26:
                                pElement = &v21->CDmElement;
                              else
                                pElement = nullptr;
                              v23 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v42->m_ToAttributeHandle);
                              if ( v23 == nullptr )
                                v23 = CDmeChannel::SetupToAttribute(this: v42);
                              v24 = v23->m_Name.u.m_pAsString;
                              if ( v24 == (const char *)-1 )
                                v24 = &pch;
                              CDmeChannel::SetOutput(this: v42, (int)pElement, pAttribute: v24, index: 0);
                              if ( CDmeChannel::GetFromElement(this: v42) == &v17->CDmElement )
                              {
                                if ( v21 != nullptr )
                                  pElementa = &v21->CDmElement;
                                else
                                  pElementa = nullptr;
                                v21 = (CDmeGlobalFlexControllerOperator *)v42;
                                v25 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v42->m_FromAttributeHandle);
                                if ( v25 == nullptr )
                                  v25 = CDmeChannel::SetupFromAttribute(this: v42);
                                v26 = v25->m_Name.u.m_pAsString;
                                if ( v26 == (const char *)-1 )
                                  v26 = &pch;
                                CDmeChannel::SetInput(this: v42, pElement: (int)pElementa, pAttribute: v26, index: 0);
                              }
                              _Msg(a1: GlobalIndex, a2: "removing duplicate flex controller %d %s\n");
                              RemoveElementFromRefereringAttributes(
                                m_hElement: (DmElementHandle_t)v21,
                                pElement: (int)&v17->CDmElement,
                                bPreserveOrder: true);
                              if ( v17 != (CDmeGlobalFlexControllerOperator *)-4 )
                              {
                                v27 = g_pDataModel->__vftable;
                                v28 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v17->CDmElement);
                                v27->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v28);
                              }
                            }
                          }
                        }
                      }
                    }
                    v12 = ci + 1;
                    ci = v12;
                    if ( v12 >= nChannels )
                      break;
                    Clip = &pChannelsClip->CDmeClip;
                  }
                  v10 = _j;
                  v9 = (CDmAttribute *)_cc;
                  v8 = v31;
                }
              }
              ++v10;
            }
          }
          v6 = _i + 1;
          _i = v6;
          if ( v6 >= _tc )
            break;
          TrackGroup = pTrackGroup;
        }
        ClipCount = (CDmAttribute *)nTrackGroups;
        v4 = gi;
      }
    }
    ++v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053E330
// Name: private: void CFlexControlBuilder::BuildDesiredFlexControlList(class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::BuildDesiredFlexControlList(CFlexControlBuilder *this, CDmeGameModel *pGameModel)
{
  const studiohdr_t *StudioHdr; // eax
  int numflexcontrollers; // esi
  CFlexControlBuilder::FlexControllerInfo_t *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  CFlexControlBuilder::FlexControllerInfo_t *v7; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CFlexControlBuilder::FlexControllerInfo_t *v10; // ecx
  int v11; // eax
  CFlexControlBuilder::FlexControllerInfo_t *v12; // ebx
  char *v13; // esi
  float v14; // xmm0_4
  int *v15; // eax
  int *v16; // eax
  const studiohdr_t **v17; // eax
  CStudioHdr cHdr; // [esp+Ch] [ebp-68h] BYREF
  int i; // [esp+70h] [ebp-4h]
  CDmeGameModel *pGameModela; // [esp+7Ch] [ebp+8h]

  StudioHdr = CDmeGameModel::GetStudioHdr(this: pGameModel);
  CStudioHdr::CStudioHdr(this: &cHdr, pStudioHdr: StudioHdr, mdlcache: nullptr);
  numflexcontrollers = cHdr.m_pStudioHdr->numflexcontrollers;
  if ( this->m_FlexControllerInfo.m_Memory.m_nAllocationCount < numflexcontrollers
    && this->m_FlexControllerInfo.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_FlexControllerInfo.m_Memory.m_pMemory;
    this->m_FlexControllerInfo.m_Memory.m_nAllocationCount = numflexcontrollers;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (CFlexControlBuilder::FlexControllerInfo_t *)((int (__stdcall *)(CFlexControlBuilder::FlexControllerInfo_t *, int))v6->Realloc_2)(
                                                          a1: m_pMemory,
                                                          a2: 264 * numflexcontrollers);
    else
      v7 = (CFlexControlBuilder::FlexControllerInfo_t *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 264 * numflexcontrollers);
    this->m_FlexControllerInfo.m_Memory.m_pMemory = v7;
  }
  this->m_FlexControllerInfo.m_pElements = this->m_FlexControllerInfo.m_Memory.m_pMemory;
  if ( numflexcontrollers > 0 )
  {
    pGameModela = nullptr;
    for ( i = numflexcontrollers; i != 0; --i )
    {
      m_Size = this->m_FlexControllerInfo.m_Size;
      m_nAllocationCount = this->m_FlexControllerInfo.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CFlexControlBuilder::FlexControllerInfo_t,int>::Grow(
          this: &this->m_FlexControllerInfo.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_FlexControllerInfo.m_Size;
      v10 = this->m_FlexControllerInfo.m_Memory.m_pMemory;
      v11 = this->m_FlexControllerInfo.m_Size - m_Size - 1;
      this->m_FlexControllerInfo.m_pElements = this->m_FlexControllerInfo.m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 264 * v11);
      v12 = &this->m_FlexControllerInfo.m_Memory.m_pMemory[m_Size];
      v13 = (char *)cHdr.m_pStudioHdr + (unsigned int)pGameModela + cHdr.m_pStudioHdr->flexcontrollerindex;
      V_strncpy(pDest: v12->m_pFlexControlName, pSrc: &v13[*((_DWORD *)v13 + 1)], maxLen: 256);
      v12->m_nGlobalIndex = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v13[*((_DWORD *)v13 + 1)]);
      v12->m_flDefaultValue = 0.0;
      v14 = *((float *)v13 + 4);
      if ( v14 != *((float *)v13 + 3) )
        v12->m_flDefaultValue = COERCE_FLOAT(*((_DWORD *)v13 + 3) ^ _mask__NegFloat_)
                              / (float)(v14 - *((float *)v13 + 3));
      pGameModela = (CDmeGameModel *)((char *)pGameModela + 20);
    }
  }
  CStudioHdr::Term(this: &cHdr);
  v15 = cHdr.m_boneParent.m_Memory.m_pMemory;
  cHdr.m_boneParent.m_Size = 0;
  if ( cHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( cHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cHdr.m_boneParent.m_Memory.m_pMemory);
      v15 = nullptr;
      cHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  cHdr.m_boneParent.m_pElements = v15;
  if ( cHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      cHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v16 = cHdr.m_boneFlags.m_Memory.m_pMemory;
  cHdr.m_boneFlags.m_Size = 0;
  if ( cHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( cHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cHdr.m_boneFlags.m_Memory.m_pMemory);
      v16 = nullptr;
      cHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  cHdr.m_boneFlags.m_pElements = v16;
  if ( cHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      cHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v17 = cHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  cHdr.m_pStudioHdrCache.m_Size = 0;
  if ( cHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( cHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v17 = nullptr;
      cHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    cHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  cHdr.m_pStudioHdrCache.m_pElements = v17;
  if ( cHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v17 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
}

//------------------------------------------------------------------------------
// Address: 0x0053E570
// Name: private: void CFlexControlBuilder::RemoveUnusedControlsAndChannels(class CDmeAnimationSet __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::RemoveUnusedControlsAndChannels(
        CFlexControlBuilder *this,
        CDmeAnimationSet *pAnimationSet,
        CDmeChannelsClip *pChannelsClip)
{
  CDmaVar<Vector> *Bookmarks; // esi
  float z; // eax
  DmElementArray_t *m_pStorage; // eax
  int m_Size; // ecx
  int v7; // esi
  CDmElement *v8; // eax
  CDmElement *v9; // ebx
  char v10; // al
  const char **v11; // edi
  CDmeChannel *Value; // eax
  CDmeChannel *v13; // esi
  CExpressionCalculator *v14; // ecx
  IDataModel_vtbl *v15; // esi
  int v16; // eax
  CDmrElementArray<CDmElement> controls; // [esp+Ch] [ebp-Ch] BYREF
  int i; // [esp+14h] [ebp-4h]

  Bookmarks = CDmeBookmarkSet::GetBookmarks(this: (CDmeTransform *)pAnimationSet);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&controls);
  z = Bookmarks[1].m_Storage.z;
  if ( z == 0.0 || (*(_BYTE *)(LODWORD(z) + 16) & 0x1F) != 0xF )
  {
    m_pStorage = nullptr;
    controls.m_pAttribute = nullptr;
    controls.m_pStorage = nullptr;
    m_Size = 0;
  }
  else
  {
    controls.m_pAttribute = (CDmAttribute *)LODWORD(Bookmarks[1].m_Storage.z);
    m_pStorage = *(DmElementArray_t **)(LODWORD(z) + 4);
    controls.m_pStorage = m_pStorage;
    m_Size = m_pStorage->m_Size;
  }
  v7 = m_Size - 1;
  i = m_Size - 1;
  if ( m_Size - 1 < 0 )
    return;
  while ( 2 )
  {
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v7]);
    v9 = v8;
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
    {
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
        this: &controls,
        elem: v7);
      goto LABEL_21;
    }
    v10 = 0;
    v11 = s_pChannelControls;
    do
    {
      if ( v10 != 0 )
        goto LABEL_16;
      Value = CDmElement::GetValueElement<CDmeChannel>(this: v9, pAttributeName: *v11);
      v13 = Value;
      if ( Value != nullptr && CDmeChannel::GetToElement(this: Value) == nullptr )
      {
        CDmeChannelsClip::RemoveChannel(this: pChannelsClip, pChannel: v13);
        v14 = (CExpressionCalculator *)&v13->CDmElement;
        if ( v13 != (CDmeChannel *)-4 )
        {
          v15 = g_pDataModel->__vftable;
          v16 = CExpressionCalculator::VariableCount(this: v14);
          v15->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v16);
        }
LABEL_16:
        v10 = 1;
        goto LABEL_17;
      }
      v10 = 0;
LABEL_17:
      ++v11;
    }
    while ( (int)v11 < (int)s_pValueControls );
    if ( v10 != 0 )
      CDmeAnimationSet::RemoveControl(this: pAnimationSet, pControl: v9);
    v7 = i;
LABEL_21:
    i = --v7;
    if ( v7 >= 0 )
    {
      m_pStorage = controls.m_pStorage;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053E6A0
// Name: private: void CFlexControlBuilder::ComputeChannelTimeTransform(class DmeTime_t __near *,double __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::ComputeChannelTimeTransform(
        CFlexControlBuilder *this,
        DmeTime_t *pOffset,
        long double *pScale,
        CDmeChannelsClip *pChannelsClip)
{
  float v4; // xmm0_4
  CDmeFilmClip *m_pMovie; // [esp-8h] [ebp-44h]
  DmeClipStack_t srcStack; // [esp+8h] [ebp-34h] BYREF
  DmeTime_t result; // [esp+38h] [ebp-4h] BYREF

  srcStack.m_tStart.m_tms = 0x80000000;
  srcStack.m_tDuration.m_tms = 0x80000000;
  srcStack.m_tOffset.m_tms = 0x80000000;
  m_pMovie = this->m_pMovie;
  memset(&srcStack, 0, 20);
  srcStack.m_bOptimized = false;
  CDmeClip::BuildClipStack(this: &pChannelsClip->CDmeClip, pStack: &srcStack, pMovie: m_pMovie, pShot: nullptr);
  pOffset->m_tms = DmeClipStack_t::FromChildMediaTime(this: &srcStack, &result, t: 0, bClamp: false)->m_tms;
  DmeClipStack_t::FromChildMediaTime(
    this: &srcStack,
    result: (DmeTime_t *)&pChannelsClip,
    t: (DmeTime_t)10000,
    bClamp: false);
  v4 = (float)((int)pChannelsClip - pOffset->m_tms) * 0.000099999997;
  pChannelsClip = (CDmeChannelsClip *)((char *)pChannelsClip - pOffset->m_tms);
  *pScale = v4;
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &srcStack.m_clips);
  if ( srcStack.m_clips.m_Memory.m_nGrowSize >= 0 && srcStack.m_clips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: srcStack.m_clips.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0053E760
// Name: private: void CFlexControlBuilder::SetupLogs(class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::SetupLogs(
        CFlexControlBuilder *this,
        CDmeChannelsClip *pChannelsClip,
        bool bUseExistingLogs)
{
  CFlexControlBuilder *v3; // esi
  double v4; // xmm0_8
  int m_Size; // eax
  CFlexControlBuilder::ControlInfo_t *v6; // ebx
  CFlexControlBuilder::ExistingLogInfo_t *m_pExistingLog; // edi
  CDmeChannel **m_ppControlChannel; // ebx
  CDmeLog *Log; // eax
  CExpressionCalculator *m_pLog; // esi
  IDataModel_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  bool v14; // zf
  unsigned int sec; // [esp+10h] [ebp-38h]
  long double flTotalScale; // [esp+20h] [ebp-28h]
  double flOOTargetScale; // [esp+28h] [ebp-20h] BYREF
  CFlexControlBuilder::ControlInfo_t *info; // [esp+30h] [ebp-18h]
  CFlexControlBuilder *v19; // [esp+34h] [ebp-14h]
  int v20; // [esp+38h] [ebp-10h]
  int v21; // [esp+3Ch] [ebp-Ch]
  CDmeChannel **v22; // [esp+40h] [ebp-8h]
  DmeTime_t targetOffset; // [esp+44h] [ebp-4h] BYREF
  CDmeChannelsClip *pChannelsClipa; // [esp+50h] [ebp+8h]

  v3 = this;
  v19 = this;
  targetOffset.m_tms = 0x80000000;
  CFlexControlBuilder::ComputeChannelTimeTransform(
    this,
    pOffset: &targetOffset,
    pScale: &flOOTargetScale,
    pChannelsClip);
  v4 = 1.0;
  if ( flOOTargetScale != 0.0 )
    v4 = 1.0 / flOOTargetScale;
  m_Size = v3->m_ControlInfo.m_Size;
  flOOTargetScale = v4;
  if ( m_Size > 0 )
  {
    pChannelsClipa = nullptr;
    v20 = m_Size;
    while ( 1 )
    {
      v6 = (CFlexControlBuilder::ControlInfo_t *)((char *)pChannelsClipa
                                                + (unsigned int)v3->m_ControlInfo.m_Memory.m_pMemory);
      v21 = 3;
      info = v6;
      m_pExistingLog = v6->m_pExistingLog;
      m_ppControlChannel = v6->m_ppControlChannel;
      v22 = m_ppControlChannel;
      do
      {
        if ( *m_ppControlChannel != nullptr )
        {
          Log = CDmeChannel::GetLog(this: *m_ppControlChannel);
          m_pLog = (CExpressionCalculator *)Log;
          if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
            m_pLog = nullptr;
          if ( bUseExistingLogs && m_pExistingLog->m_pLog != nullptr )
          {
            CDmeChannel::SetLog(this: *m_ppControlChannel, pLog: (int)m_pExistingLog->m_pLog);
            if ( m_pLog != nullptr )
            {
              v11 = g_pDataModel->__vftable;
              v12 = CExpressionCalculator::VariableCount(this: m_pLog);
              v11->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v12);
              m_ppControlChannel = v22;
            }
            m_pLog = (CExpressionCalculator *)m_pExistingLog->m_pLog;
            flTotalScale = m_pExistingLog->m_flGlobalScale * flOOTargetScale;
            *(float *)&sec = (float)((float)(m_pExistingLog->m_GlobalOffset.m_tms - targetOffset.m_tms) * 0.000099999997)
                           * flOOTargetScale;
            v13 = DmeTime_t::RoundSecondsToTMS(sec);
            CDmeLog::ScaleBiasKeyTimes(this: (CDmeLog *)m_pLog, flScale: flTotalScale, nBias: (DmeTime_t)v13);
          }
          CDmeTypedLog<float>::SetDefaultValue(this: (CDmeTypedLog<float> *)m_pLog, value: &info->m_flDefaultValue);
        }
        ++m_ppControlChannel;
        ++m_pExistingLog;
        v14 = v21-- == 1;
        v22 = m_ppControlChannel;
      }
      while ( !v14 );
      pChannelsClipa = (CDmeChannelsClip *)((char *)pChannelsClipa + 344);
      if ( --v20 == 0 )
        break;
      v3 = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053E8F0
// Name: private: void CFlexControlBuilder::BuildDesiredControlList(class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::BuildDesiredControlList(CFlexControlBuilder *this, CDmeGameModel *pGameModel)
{
  CFlexControlBuilder *v2; // edi
  int v3; // ebx
  int m_pControlName; // esi
  CFlexControlBuilder::FlexControllerInfo_t *v5; // edi
  CFlexControlBuilder::FlexControllerInfo_t *m_pMemory; // eax
  CFlexControlBuilder::FlexControllerInfo_t *leftInfo; // [esp+8h] [ebp-10h]
  int nCount; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+14h] [ebp-4h]

  v2 = this;
  v3 = 0;
  nCount = this->m_FlexControllerInfo.m_Size;
  if ( nCount > 0 )
  {
    v10 = 0;
    while ( 1 )
    {
      m_pControlName = (int)v2->m_ControlInfo.m_Memory.m_pMemory[CUtlVector<CFlexControlBuilder::ControlInfo_t,CUtlMemory<CFlexControlBuilder::ControlInfo_t,int>>::InsertBefore(
                                                                   this: &v2->m_ControlInfo,
                                                                   elem: v2->m_ControlInfo.m_Size)].m_pControlName;
      memset(dst: (unsigned __int8 *)m_pControlName, value: 0, count: 0x158u);
      v5 = &v2->m_FlexControllerInfo.m_Memory.m_pMemory[v10];
      if ( V_strnicmp(s1: "right_", s2: v5->m_pFlexControlName, n: 6) != 0 || v3 >= nCount - 1 )
      {
        *(_BYTE *)(m_pControlName + 256) &= ~1u;
        *(_DWORD *)(m_pControlName + 268) = v3;
        *(_DWORD *)(m_pControlName + 272) = -1;
        *(_DWORD *)(m_pControlName + 276) = -1;
        V_strncpy(pDest: (char *)m_pControlName, pSrc: v5->m_pFlexControlName, maxLen: 256);
        *(float *)(m_pControlName + 264) = v5->m_flDefaultValue;
      }
      else
      {
        m_pMemory = this->m_FlexControllerInfo.m_Memory.m_pMemory;
        *(_BYTE *)(m_pControlName + 256) |= 1u;
        *(_DWORD *)(m_pControlName + 272) = v3++;
        leftInfo = &m_pMemory[v10 + 1];
        *(_DWORD *)(m_pControlName + 268) = -1;
        *(_DWORD *)(m_pControlName + 276) = v3;
        V_strncpy(pDest: (char *)m_pControlName, pSrc: &v5->m_pFlexControlName[6], maxLen: 256);
        ++v10;
        *(float *)(m_pControlName + 264) = (float)(leftInfo->m_flDefaultValue + v5->m_flDefaultValue) * 0.5;
      }
      ++v10;
      if ( ++v3 >= nCount )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053EA20
// Name: private: void CFlexControlBuilder::GetExistingMonoLog(struct CFlexControlBuilder::ExistingLogInfo_t __near *,class CDmeFilmClip __near *,class CDmeGlobalFlexControllerOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::GetExistingMonoLog(
        CFlexControlBuilder *this,
        CFlexControlBuilder::ExistingLogInfo_t *pExistingLog,
        CDmeFilmClip *pClip,
        CDmeGlobalFlexControllerOperator *pMonoOp)
{
  bool v4; // zf
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmElement *v6; // ecx
  CDmeChannel *Referring; // eax
  CDmeChannel *v8; // edi
  CDmeLog *Log; // eax
  CDmeTypedLog<float> *v10; // esi
  CDmeChannelsClip *ChannelsClipContainingChannel; // eax

  v4 = (_S2_3 & 1) == 0;
  pExistingLog->m_pLog = nullptr;
  if ( v4 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_3 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symToElement, a3: "toElement");
  }
  if ( pMonoOp != nullptr )
    v6 = &pMonoOp->CDmElement;
  else
    v6 = nullptr;
  Referring = FindReferringElement<CDmeChannel>(
                pElement: (CExpressionCalculator *)v6,
                symAttrName: symToElement,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  v8 = Referring;
  if ( Referring != nullptr )
  {
    Log = CDmeChannel::GetLog(this: Referring);
    v10 = (CDmeTypedLog<float> *)Log;
    if ( Log != nullptr && Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
    {
      ChannelsClipContainingChannel = CFlexControlBuilder::FindChannelsClipContainingChannel(this, pClip, pSearch: v8);
      if ( ChannelsClipContainingChannel != nullptr )
      {
        CFlexControlBuilder::ComputeChannelTimeTransform(
          this,
          pOffset: &pExistingLog->m_GlobalOffset,
          pScale: &pExistingLog->m_flGlobalScale,
          pChannelsClip: ChannelsClipContainingChannel);
        pExistingLog->m_pLog = v10;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053EAE0
// Name: private: void CFlexControlBuilder::RemoveChannelFromClips(class CDmeChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::RemoveChannelFromClips(CFlexControlBuilder *this, CDmeChannel *pChannel)
{
  CDmeChannel *v2; // ebx
  int v3; // esi
  CDmElement *v4; // ecx
  int m_Size; // edi
  const char **v6; // esi
  CExpressionCalculator *v7; // ecx
  CDmElement *Referring; // eax
  CUtlVector<CDmeChannelsClip *,CUtlMemory<CDmeChannelsClip *,int> > channelsClips; // [esp+Ch] [ebp-14h] BYREF

  v2 = pChannel;
  v3 = 0;
  memset(&channelsClips, 0, sizeof(channelsClips));
  if ( pChannel != nullptr )
    v4 = &pChannel->CDmElement;
  else
    v4 = nullptr;
  FindReferringElements<CDmeChannelsClip>(
    list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelsClips,
    pElement: (CExpressionCalculator *)v4,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  m_Size = channelsClips.m_Size;
  if ( channelsClips.m_Size > 0 )
  {
    do
      CDmeChannelsClip::RemoveChannel(this: channelsClips.m_Memory.m_pMemory[v3++], pChannel: v2);
    while ( v3 < m_Size );
  }
  v6 = s_pChannelControls;
  do
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pChannel, a3: *v6);
    if ( v2 != nullptr )
      v7 = (CExpressionCalculator *)&v2->CDmElement;
    else
      v7 = nullptr;
    Referring = FindReferringElement<CDmElement>(
                  pElement: v7,
                  symAttrName: (CUtlSymbolLarge)pChannel,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmElement::RemoveAttribute(this: Referring, pAttributeName: *v6);
    ++v6;
  }
  while ( (int)v6 < (int)s_pValueControls );
  if ( channelsClips.m_Memory.m_nGrowSize >= 0 && channelsClips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelsClips.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0053EBC0
// Name: private: void CFlexControlBuilder::CleanupExistingFlexController(class CDmeGameModel __near *,class CDmeGlobalFlexControllerOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::CleanupExistingFlexController(
        CFlexControlBuilder *this,
        CDmeGameModel *pGameModel,
        CDmeGlobalFlexControllerOperator *pOp)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmElement *v5; // ecx
  CDmeChannel *Referring; // eax
  CDmeChannel *v7; // esi
  CExpressionCalculator *v8; // ecx
  IDataModel_vtbl *v9; // esi
  int v10; // eax
  IDataModel_vtbl *v11; // esi
  int v12; // eax

  if ( (_S1_6 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_6 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symToElement_0, a3: "toElement");
  }
  if ( pOp != nullptr )
    v5 = &pOp->CDmElement;
  else
    v5 = nullptr;
  Referring = FindReferringElement<CDmeChannel>(
                pElement: (CExpressionCalculator *)v5,
                symAttrName: symToElement_0,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  v7 = Referring;
  if ( Referring != nullptr )
  {
    CFlexControlBuilder::RemoveChannelFromClips(this, pChannel: Referring);
    v8 = (CExpressionCalculator *)&v7->CDmElement;
    if ( v7 != (CDmeChannel *)-4 )
    {
      v9 = g_pDataModel->__vftable;
      v10 = CExpressionCalculator::VariableCount(this: v8);
      v9->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v10);
    }
  }
  CDmeGameModel::RemoveGlobalFlexController(this: pGameModel, controller: pOp);
  if ( pOp != nullptr && pOp != (CDmeGlobalFlexControllerOperator *)-4 )
  {
    v11 = g_pDataModel->__vftable;
    v12 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&pOp->CDmElement);
    v11->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053EC80
// Name: private: void CFlexControlBuilder::RemoveUnusedExistingFlexControllers(class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::RemoveUnusedExistingFlexControllers(
        CFlexControlBuilder *this,
        CDmeGameModel *pGameModel)
{
  int v2; // eax
  CDmeGlobalFlexControllerOperator *GlobalFlexController; // eax
  CFlexControlBuilder *v4; // ecx
  int m_Size; // ebx
  int v6; // esi
  int v7; // edi
  int i; // [esp+0h] [ebp-10h]
  char *s1; // [esp+4h] [ebp-Ch]
  CDmeGlobalFlexControllerOperator *pOp; // [esp+Ch] [ebp-4h]

  v2 = CDmeGameModel::NumGlobalFlexControllers(this: pGameModel) - 1;
  for ( i = v2; i >= 0; --i )
  {
    GlobalFlexController = CDmeGameModel::GetGlobalFlexController(this: pGameModel, localIndex: v2);
    pOp = GlobalFlexController;
    if ( GlobalFlexController != nullptr )
    {
      s1 = (char *)&pch;
      if ( GlobalFlexController->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
        s1 = (char *)GlobalFlexController->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id;
      v4 = this;
      m_Size = this->m_FlexControllerInfo.m_Size;
      v6 = 0;
      if ( m_Size <= 0 )
        goto LABEL_11;
      v7 = 0;
      while ( _V_stricmp(s1, s2: this->m_FlexControllerInfo.m_Memory.m_pMemory[v7].m_pFlexControlName) != 0 )
      {
        ++v6;
        ++v7;
        if ( v6 >= m_Size )
          goto LABEL_11;
      }
      if ( v6 < 0 )
      {
LABEL_11:
        _Msg(a1: v4, a2: "removing flex controller %s\n");
        CFlexControlBuilder::CleanupExistingFlexController(this, pGameModel, pOp);
      }
    }
    v2 = i - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053ED40
// Name: private: void CFlexControlBuilder::BuildExistingFlexControlLogList(class CDmeFilmClip __near *,class CDmeGameModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::BuildExistingFlexControlLogList(
        CFlexControlBuilder *this,
        CDmeFilmClip *pCurrentClip,
        CDmeGameModel *pGameModel)
{
  CFlexControlBuilder::ControlInfo_t *v4; // edi
  CFlexControlBuilder::FlexControllerInfo_t *v5; // ebx
  CDmeGlobalFlexControllerOperator *GlobalFlexController; // eax
  const char *m_pAsString; // ecx
  CDmeGlobalFlexControllerOperator *v8; // eax
  int v9; // ecx
  CDmeGlobalFlexControllerOperator *v10; // ebx
  CDmeGlobalFlexControllerOperator *pRightOp; // [esp+4h] [ebp-10h]
  int m_Size; // [esp+8h] [ebp-Ch]
  CDmeGlobalFlexControllerOperator *pLeftOp; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]

  if ( this->m_ControlInfo.m_Size > 0 )
  {
    v14 = 0;
    m_Size = this->m_ControlInfo.m_Size;
    do
    {
      v4 = &this->m_ControlInfo.m_Memory.m_pMemory[v14];
      if ( (*((_BYTE *)v4 + 256) & 1) != 0 )
      {
        v5 = &this->m_FlexControllerInfo.m_Memory.m_pMemory[v4->m_pControllerIndex[2]];
        pRightOp = CDmeGameModel::FindGlobalFlexController(
                     this: pGameModel,
                     nGlobalIndex: this->m_FlexControllerInfo.m_Memory.m_pMemory[v4->m_pControllerIndex[1]].m_nGlobalIndex);
        GlobalFlexController = CDmeGameModel::FindGlobalFlexController(
                                 this: pGameModel,
                                 nGlobalIndex: v5->m_nGlobalIndex);
        pLeftOp = GlobalFlexController;
        if ( pRightOp != nullptr && GlobalFlexController != nullptr )
        {
          m_pAsString = &pch;
          if ( pRightOp->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
            m_pAsString = pRightOp->m_Name.m_Storage.u.m_pAsString;
          _Msg(a1: m_pAsString, a2: "replacing stereo flex controllers %s and %s\n");
          CFlexControlBuilder::GetExistingMonoLog(
            this,
            pExistingLog: &v4->m_pExistingLog[1],
            pClip: pCurrentClip,
            pMonoOp: pRightOp);
          CFlexControlBuilder::GetExistingMonoLog(
            this,
            pExistingLog: &v4->m_pExistingLog[2],
            pClip: pCurrentClip,
            pMonoOp: pLeftOp);
          CFlexControlBuilder::CleanupExistingFlexController(this, pGameModel, pOp: pRightOp);
          CFlexControlBuilder::CleanupExistingFlexController(this, pGameModel, pOp: pLeftOp);
        }
      }
      else
      {
        v8 = CDmeGameModel::FindGlobalFlexController(
               this: pGameModel,
               nGlobalIndex: this->m_FlexControllerInfo.m_Memory.m_pMemory[v4->m_pControllerIndex[0]].m_nGlobalIndex);
        v10 = v8;
        if ( v8 != nullptr )
        {
          _Msg(a1: v9, a2: "replacing mono flex controller %s\n");
          CFlexControlBuilder::GetExistingMonoLog(
            this,
            pExistingLog: v4->m_pExistingLog,
            pClip: pCurrentClip,
            pMonoOp: v10);
          CFlexControlBuilder::CleanupExistingFlexController(this, pGameModel, pOp: v10);
        }
      }
      ++v14;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053EEA0
// Name: public: void CFlexControlBuilder::CreateAnimationSetControls(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeFilmClip __near *,class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexControlBuilder::CreateAnimationSetControls(
        CFlexControlBuilder *this,
        CDmeFilmClip *pMovie,
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        CDmeFilmClip *pSourceClip,
        CDmeChannelsClip *pDestClip,
        bool bUseExistingLogs)
{
  this->m_pMovie = pMovie;
  CFlexControlBuilder::FixupExistingFlexControlLogList(this, pCurrentClip: pSourceClip, pGameModel);
  CFlexControlBuilder::BuildDesiredFlexControlList(this, pGameModel);
  CFlexControlBuilder::BuildDesiredControlList(this, pGameModel);
  CFlexControlBuilder::RemoveUnusedExistingFlexControllers(this, pGameModel);
  CFlexControlBuilder::RemoveUnusedControlsAndChannels(this, pAnimationSet, pChannelsClip: pDestClip);
  if ( bUseExistingLogs )
    CFlexControlBuilder::BuildExistingFlexControlLogList(this, pCurrentClip: pSourceClip, pGameModel);
  CFlexControlBuilder::CreateFlexControls(this, pAnimationSet);
  CFlexControlBuilder::AttachControlsToGameModel(this, pAnimationSet, pGameModel, pChannelsClip: pDestClip);
  CFlexControlBuilder::SetupLogs(this, pChannelsClip: pDestClip, bUseExistingLogs);
}

//------------------------------------------------------------------------------
// Address: 0x0053EF30
// Name: class CDmeTimeSelection __near * CreateElement<class CDmeTimeSelection>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeSelection *__cdecl CreateElement<CDmeTimeSelection>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTimeSelection::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeTimeSelection::m_classType) )
    return (CDmeTimeSelection *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0053EF90
// Name: class CDmeGraphEditorState __near * CreateElement<class CDmeGraphEditorState>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGraphEditorState *__cdecl CreateElement<CDmeGraphEditorState>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeGraphEditorState::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeGraphEditorState::m_classType) )
    return (CDmeGraphEditorState *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0053EFF0
// Name: class CDmeProceduralPresetSettings __near * CreateElement<class CDmeProceduralPresetSettings>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeProceduralPresetSettings *__cdecl CreateElement<CDmeProceduralPresetSettings>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeProceduralPresetSettings::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeProceduralPresetSettings::m_classType) )
    return (CDmeProceduralPresetSettings *)v5;
  else
    return nullptr;
}

} // namespace sfmgen
