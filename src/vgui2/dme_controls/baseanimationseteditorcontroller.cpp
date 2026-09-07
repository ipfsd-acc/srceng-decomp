// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/baseanimationseteditorcontroller.cpp
// Functions: 58
// ============================================================

#include "vgui2\dme_controls\baseanimationseteditorcontroller.h"

//------------------------------------------------------------------------------
// Address: 0x00482EC0
// Name: public: bool Quaternion::operator!=(class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Quaternion::operator!=(Quaternion *this, const Quaternion *src)
{
  return this->x != src->x || this->y != src->y || this->z != src->z || this->w != src->w;
}

//------------------------------------------------------------------------------
// Address: 0x00482F90
// Name: public: class CDmAttribute __near * CDmeChannel::GetFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::GetFromAttribute(CDmeChannel *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
  if ( result == nullptr )
    return CDmeChannel::SetupFromAttribute(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482FC0
// Name: protected: virtual void CBaseAnimationSetControl::GetAnimatedPresetTimeParameters(class DmeTime_t __near &,class DmeTime_t __near &,class DmeTime_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::GetAnimatedPresetTimeParameters(
        CBaseAnimationSetControl *this,
        int tHead,
        DmeTime_t *tStart,
        DmeTime_t *tEnd)
{
  DmeTime_t result; // [esp+4h] [ebp-4h] BYREF

  result.m_tms = (int)this;
  *(_DWORD *)tHead = 0;
  tHead = -2147483647;
  DmeTime_t::operator/=(this: (DmeTime_t *)&tHead, &result, f: 2.0);
  tStart->m_tms = tHead;
  tHead = 0x7FFFFFFF;
  DmeTime_t::operator/=(this: (DmeTime_t *)&tHead, result: (DmeTime_t *)&tStart, f: 2.0);
  tEnd->m_tms = tHead;
}

//------------------------------------------------------------------------------
// Address: 0x00483030
// Name: public: bool CBaseAnimationSetControl::IsControlGroupVisible(class CDmeControlGroup const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::IsControlGroupVisible(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pGroup)
{
  return this->m_bShowHiddenControls || CDmeControlGroup::IsVisible(this: pGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00483050
// Name: public: bool CBaseAnimationSetControl::IsPresetFaderBeingDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::IsPresetFaderBeingDragged(CBaseAnimationSetControl *this)
{
  return *((_BYTE *)this + 104) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483060
// Name: public: struct AttributeValue_t __near & AttributeValue_t::operator=(struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
AttributeValue_t *__thiscall AttributeValue_t::operator=(AttributeValue_t *this, const AttributeValue_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00483350
// Name: public: class CDmeFilmClip __near * CBaseAnimationSetControl::GetAnimationSetClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeFilmClip *__thiscall CBaseAnimationSetControl::GetAnimationSetClip(CBaseAnimationSetControl *this)
{
  return (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00483370
// Name: public: void CBaseAnimationSetControl::SetActiveAttributeSlider(class CAttributeSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetActiveAttributeSlider(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_ActiveAttributeSlider, pPanel: pSlider);
}

//------------------------------------------------------------------------------
// Address: 0x00483380
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<float>(class DmeTime_t,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDmeChannel::GetPlaybackValueAtTime<float>@<al>(
        CDmeChannel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        DmeTime_t time,
        float *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<float> *v6; // esi
  int m_tms; // eax
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v6 = (CDmeTypedLog<float> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) || CDmeLog::IsEmpty(this: v6) != 0 )
    return 0;
  CDmeLog::GetBeginTime(this: v6, result: &t0);
  CDmeLog::GetEndTime(this: v6, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  *value = *CDmeTypedLog<float>::GetValue(this: v6, a2, a3, time: (DmeTime_t)m_tms);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483610
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<class Quaternion>(class DmeTime_t,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetPlaybackValueAtTime<Quaternion>(CDmeChannel *this, DmeTime_t time, Quaternion *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v4; // esi
  int m_tms; // eax
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v4 = (CDmeTypedLog<Quaternion> *)Log;
  if ( Log == nullptr
    || !Log->IsA(this: Log, a2: CDmeTypedLog<Quaternion>::m_classType)
    || CDmeLog::IsEmpty(this: v4) != 0 )
  {
    return 0;
  }
  CDmeLog::GetBeginTime(this: v4, result: &t0);
  CDmeLog::GetEndTime(this: v4, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  *value = *CDmeTypedLog<Quaternion>::GetValue(this: v4, time: (DmeTime_t)m_tms);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004836A0
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<class Vector>(class DmeTime_t,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetPlaybackValueAtTime<Vector>(CDmeChannel *this, DmeTime_t time, Vector *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v4; // esi
  int m_tms; // eax
  const Vector *v6; // eax
  double z; // st7
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v4 = (CDmeTypedLog<Vector> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) || CDmeLog::IsEmpty(this: v4) != 0 )
    return 0;
  CDmeLog::GetBeginTime(this: v4, result: &t0);
  CDmeLog::GetEndTime(this: v4, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  v6 = CDmeTypedLog<Vector>::GetValue(this: v4, time: (DmeTime_t)m_tms);
  value->x = v6->x;
  value->y = v6->y;
  z = v6->z;
  value->z = z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483840
// Name: public: class CDmeDag __near * CBaseAnimationSetControl::GetWorkCameraParent(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CBaseAnimationSetControl::GetWorkCameraParent(CBaseAnimationSetControl *this)
{
  return (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hWorkCameraParent.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00483860
// Name: protected: virtual void CBaseAnimationSetControl::FireControlSelectionChangedListeners(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::FireControlSelectionChangedListeners(CBaseAnimationSetControl *this)
{
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v3; // ecx

  for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
  {
    v3 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
    v3->OnControlSelectionChanged(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483890
// Name: protected: virtual void CBaseAnimationSetControl::FireRebuildControlHierarchyListeners(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::FireRebuildControlHierarchyListeners(CBaseAnimationSetControl *this)
{
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v3; // ecx

  for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
  {
    v3 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
    v3->OnRebuildControlHierarchy(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004838C0
// Name: public: void CBaseAnimationSetControl::SetRangeSelectionState(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetRangeSelectionState(
        CBaseAnimationSetControl *this,
        bool bInRangeSelection)
{
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    sg.m_pControl = this;
    sg.m_selectionMode = SELECTION_REMOVE;
    atexit(func: CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__);
  }
  if ( bInRangeSelection )
  {
    ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
    sg.m_selectionMode = SELECTION_SET;
  }
  else if ( --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    sg.m_pControl->FireControlSelectionChangedListeners(this: sg.m_pControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483930
// Name: public: class CDmElement __near * CBaseAnimationSetControl::GetMostRecentlySelectedControl(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAnimationSetControl::GetMostRecentlySelectedControl(CBaseAnimationSetControl *this)
{
  int m_Tail; // eax

  m_Tail = this->m_SelectionHistory.m_Tail;
  if ( m_Tail == 0xFFFF )
    return nullptr;
  else
    return g_pDataModel->GetElement(
             this: g_pDataModel,
             a2: this->m_SelectionHistory.m_Memory.m_pMemory[m_Tail].m_Element->m_hControl.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00483960
// Name: public: void CBaseAnimationSetControl::GetDominantSliderValues(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::GetDominantSliderValues(
        CBaseAnimationSetControl *this,
        float *flDomStart,
        float *flDomValue)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  int m_nDominantSlider; // ecx
  CAttributeSlider *v6; // edi
  char v7; // al
  AnimationControlType_t v8; // esi
  float v9; // xmm0_4
  float flDomStarta; // [esp+8h] [ebp+8h]

  *flDomStart = 0.0;
  *flDomValue = 0.0;
  if ( this->m_nDominantSlider < 0 )
    return;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  if ( AttributeSlider == nullptr )
    return;
  m_nDominantSlider = this->m_nDominantSlider;
  v6 = AttributeSlider->m_SliderList.m_Memory.m_pMemory[m_nDominantSlider];
  if ( v6 == nullptr )
    return;
  v7 = *((_BYTE *)v6 + 656);
  if ( (v7 & 1) != 0 )
    return;
  v8 = (v7 & 4) != 0;
  v9 = this->m_DominantSliderStartValues.m_Memory.m_pMemory[m_nDominantSlider].m_pValue[v8];
  if ( v9 > 1.0 )
    goto LABEL_9;
  if ( v9 >= 0.0 )
  {
    if ( v9 <= 1.0 )
      goto LABEL_10;
LABEL_9:
    v9 = 1.0;
    goto LABEL_10;
  }
  v9 = 0.0;
LABEL_10:
  *flDomStart = v9;
  if ( CAttributeSlider::GetValue(this: v6, type: v8) > 1.0 || CAttributeSlider::GetValue(this: v6, type: v8) >= 0.0 )
  {
    if ( CAttributeSlider::GetValue(this: v6, type: v8) <= 1.0 )
    {
      flDomStarta = CAttributeSlider::GetValue(this: v6, type: v8);
      *flDomValue = flDomStarta;
    }
    else
    {
      *flDomValue = 1.0;
    }
  }
  else
  {
    *flDomValue = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483E00
// Name: protected: bool CDmeChannel::GetValue<class Vector>(class Vector __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<Vector>(CDmeChannel *this, Vector *value, CDmAttribute *pAttr, int nIndex)
{
  CDmaVar<Vector> *v4; // eax
  double z; // st7
  CDmrArrayConst<Vector> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      v4 = CDmAttribute::GetValue<Vector>(this: pAttr);
      goto LABEL_6;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      v4 = (CDmaVar<Vector> *)&array.m_pStorage->m_Memory.m_pMemory[nIndex];
LABEL_6:
      value->x = v4->m_Storage.x;
      value->y = v4->m_Storage.y;
      z = v4->m_Storage.z;
      value->z = z;
      return 1;
    }
  }
  value->x = 0.0;
  value->y = 0.0;
  value->z = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00483E90
// Name: protected: bool CDmeChannel::GetValue<class Quaternion>(class Quaternion __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<Quaternion>(
        CDmeChannel *this,
        Quaternion *value,
        CDmAttribute *pAttr,
        int nIndex)
{
  Quaternion *v4; // eax
  CDmrArrayConst<Quaternion> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      v4 = (Quaternion *)CDmAttribute::GetValue<Quaternion>(this: pAttr);
      goto LABEL_6;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      v4 = &array.m_pStorage->m_Memory.m_pMemory[nIndex];
LABEL_6:
      *value = *v4;
      return 1;
    }
  }
  value->x = 0.0;
  value->y = 0.0;
  value->z = 0.0;
  value->w = 1.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00483F30
// Name: protected: bool CDmeChannel::GetValue<float>(float __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<float>(CDmeChannel *this, float *value, CDmAttribute *pAttr, int nIndex)
{
  CDmrArrayConst<float> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      *value = CDmAttribute::GetValue<float>(this: pAttr)->m_Storage;
      return 1;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      *value = array.m_pStorage->m_Memory.m_pMemory[nIndex];
      return 1;
    }
  }
  *value = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00484190
// Name: public: void CBaseAnimationSetControl::SetWorkCameraParent(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetWorkCameraParent(CBaseAnimationSetControl *this, CDmeDag *pParent)
{
  CDmeHandle<CDmeDag,0> *p_m_hWorkCameraParent; // esi
  DmElementHandle_t BufferType; // eax

  p_m_hWorkCameraParent = &this->m_hWorkCameraParent;
  if ( pParent != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pParent);
    CDmeHandle<CDmeDag,0>::Set(this: p_m_hWorkCameraParent, h: BufferType);
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: p_m_hWorkCameraParent, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004841C0
// Name: public: enum TransformComponent_t CBaseAnimationSetControl::GetSelectionComponentFlags(class CDmElement __near *)const
// Source: json
//------------------------------------------------------------------------------
TransformComponent_t __thiscall CBaseAnimationSetControl::GetSelectionComponentFlags(
        CBaseAnimationSetControl *this,
        CDmElement *pControl)
{
  int m_Head; // eax
  int v5; // esi
  SelectionInfo_t *m_Element; // edi

  if ( pControl == nullptr )
    return TRANSFORM_COMPONENT_NONE;
  m_Head = this->m_SelectionHistory.m_Head;
  if ( m_Head == 0xFFFF )
    return TRANSFORM_COMPONENT_NONE;
  while ( 1 )
  {
    v5 = (unsigned __int16)m_Head;
    m_Element = this->m_SelectionHistory.m_Memory.m_pMemory[v5].m_Element;
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: m_Element->m_hControl.m_handle) == pControl )
      break;
    m_Head = this->m_SelectionHistory.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == 0xFFFF )
      return TRANSFORM_COMPONENT_NONE;
  }
  return m_Element->m_nComponentFlags;
}

//------------------------------------------------------------------------------
// Address: 0x00484750
// Name: public: bool CDmeChannel::GetInputValue<class Vector>(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<Vector>(CDmeChannel *this, Vector *value)
{
  CDmAttribute *v3; // eax

  v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<Vector>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00484790
// Name: public: bool CDmeChannel::GetInputValue<class Quaternion>(class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<Quaternion>(CDmeChannel *this, Quaternion *value)
{
  CDmAttribute *v3; // eax

  v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<Quaternion>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x004847D0
// Name: public: bool CDmeChannel::GetInputValue<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<float>(CDmeChannel *this, float *value)
{
  CDmAttribute *v3; // eax

  v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<float>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x004850A0
// Name: public: void CBaseAnimationSetControl::ClearSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ClearSelection(CBaseAnimationSetControl *this)
{
  int m_Tail; // eax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // ecx
  int v4; // eax

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  m_Tail = this->m_SelectionHistory.m_Tail;
  if ( m_Tail != 0xFFFF )
  {
    m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
    do
    {
      v4 = (unsigned __int16)m_Tail;
      m_pMemory[v4].m_Element->m_nComponentFlags = TRANSFORM_COMPONENT_NONE;
      m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
      m_Tail = m_pMemory[v4].m_Previous;
    }
    while ( m_Tail != 0xFFFF );
  }
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SelectionHistory);
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    this->FireControlSelectionChangedListeners(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485100
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmElement __near *,enum TransformComponent_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(
        CBaseAnimationSetControl *this,
        CDmElement *pControl,
        TransformComponent_t componentFlags)
{
  CDmeControlGroup *GroupContainingControl; // eax
  __int32 v5; // eax

  if ( pControl == nullptr )
    return 0;
  if ( !this->m_bShowHiddenControls )
  {
    GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl);
    if ( GroupContainingControl == nullptr || !CDmeControlGroup::IsVisible(this: GroupContainingControl) )
      return 0;
  }
  v5 = componentFlags & CBaseAnimationSetControl::GetSelectionComponentFlags(this, pControl);
  if ( v5 != 0 )
    return (v5 != componentFlags) + 2;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00485170
// Name: void SetPresetFromControl(class CDmePreset __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPresetFromControl(CDmePreset *pPreset, CDmeTransformControl *pControl)
{
  const char *m_pAsString; // eax
  CDmElement *v3; // esi
  const Vector *Position; // ebx
  CDmAttribute *Attribute; // eax
  const Quaternion *Orientation; // edi
  CDmAttribute *v7; // eax
  const char *v8; // eax
  CDmElement *v9; // esi
  CDmaVar<float> *v10; // ebx
  CDmAttribute *v11; // eax
  CDmaVar<float> *v12; // edi
  CDmAttribute *v13; // eax
  CDmaVar<float> *v14; // edi
  CDmAttribute *v15; // eax

  if ( pControl != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    m_pAsString = pControl->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    v3 = CDmePreset::FindOrAddControlValue(this: pPreset, pControlName: m_pAsString);
    if ( v3 != nullptr )
    {
      if ( CDmeTransformControl::GetPositionChannel(this: pControl) != nullptr )
      {
        Position = CDmeTransformControl::GetPosition(this: pControl);
        Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "valuePosition");
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "valuePosition", type: AT_VECTOR3)) != nullptr )
        {
          CDmAttribute::SetValue<Vector>(this: Attribute, value: Position);
        }
      }
      if ( CDmeTransformControl::GetOrientationChannel(this: pControl) != nullptr )
      {
        Orientation = CDmeTransformControl::GetOrientation(this: pControl);
        v7 = CDmElement::FindAttribute(this: v3, pAttributeName: "valueOrientation");
        if ( v7 != nullptr
          || (v7 = CDmElement::CreateAttribute(this: v3, pAttributeName: "valueOrientation", type: AT_QUATERNION)) != nullptr )
        {
          CDmAttribute::SetValue<Quaternion>(this: v7, value: Orientation);
        }
      }
    }
  }
  else
  {
    v8 = pControl->m_Name.m_Storage.u.m_pAsString;
    if ( v8 == (const char *)-1 )
      v8 = defaultValue;
    v9 = CDmePreset::FindOrAddControlValue(this: pPreset, pControlName: v8);
    if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
    {
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "value");
      v10 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "leftValue");
      v11 = CDmElement::FindAttribute(this: v9, pAttributeName: "leftValue");
      if ( v11 != nullptr
        || (v11 = CDmElement::CreateAttribute(this: v9, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v11, value: &v10->m_Storage);
      }
      v12 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "rightValue");
      v13 = CDmElement::FindAttribute(this: v9, pAttributeName: "rightValue");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v9, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v13, value: &v12->m_Storage);
      }
    }
    else
    {
      v14 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "value");
      v15 = CDmElement::FindAttribute(this: v9, pAttributeName: "value");
      if ( v15 != nullptr
        || (v15 = CDmElement::CreateAttribute(this: v9, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v15, value: &v14->m_Storage);
      }
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "leftValue");
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "rightValue");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485560
// Name: public: CBaseAnimationSetControl::CBaseAnimationSetControl(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetControl *__thiscall CBaseAnimationSetControl::CBaseAnimationSetControl(CBaseAnimationSetControl *this)
{
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // eax

  this->__vftable = (CBaseAnimationSetControl_vtbl *)&CBaseAnimationSetControl::`vftable';
  this->m_hFilmClip.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_pEditor = nullptr;
  this->m_SelectionHistory.m_Memory.m_pMemory = nullptr;
  this->m_SelectionHistory.m_Memory.m_nAllocationCount = 0;
  this->m_SelectionHistory.m_Memory.m_nGrowSize = 0;
  this->m_SelectionHistory.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_SelectionHistory.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_SelectionHistory.m_Head = -1;
  this->m_SelectionHistory.m_pElements = m_pMemory;
  this->m_SelectionHistory.m_NumAlloced = 0;
  this->m_hWorkCameraParent.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_OverrideParentChangedListeners.m_Memory.m_pMemory = nullptr;
  this->m_OverrideParentChangedListeners.m_Memory.m_nAllocationCount = 0;
  this->m_OverrideParentChangedListeners.m_Memory.m_nGrowSize = 0;
  this->m_OverrideParentChangedListeners.m_Size = 0;
  this->m_OverrideParentChangedListeners.m_pElements = nullptr;
  this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory = nullptr;
  this->m_ControlSelectionChangedListeners.m_Memory.m_nAllocationCount = 0;
  this->m_ControlSelectionChangedListeners.m_Memory.m_nGrowSize = 0;
  this->m_ControlSelectionChangedListeners.m_Size = 0;
  this->m_ControlSelectionChangedListeners.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_PreviousPresetSlider, pString: defaultValue);
  *((_BYTE *)this + 104) &= 0xF8u;
  this->m_flPreviousPresetAmount = 0.0;
  this->m_ActiveAttributeSlider.m_iPanelID = -1;
  this->m_DominantSliderStartValues.m_Memory.m_pMemory = nullptr;
  this->m_DominantSliderStartValues.m_Memory.m_nAllocationCount = 0;
  this->m_DominantSliderStartValues.m_Memory.m_nGrowSize = 0;
  this->m_DominantSliderStartValues.m_Size = 0;
  this->m_DominantSliderStartValues.m_pElements = nullptr;
  this->m_nDominantSlider = -1;
  this->m_bShowHiddenControls = false;
  this->m_crossfadePresetControlValues.m_Memory.m_pMemory = nullptr;
  this->m_crossfadePresetControlValues.m_Memory.m_nAllocationCount = 0;
  this->m_crossfadePresetControlValues.m_Memory.m_nGrowSize = 0;
  this->m_crossfadePresetControlValues.m_Size = 0;
  this->m_crossfadePresetControlValues.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00485620
// Name: public: virtual void CBaseAnimationSetControl::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ChangeAnimationSetClip(
        CBaseAnimationSetControl *this,
        CDmeFilmClip *pFilmClip)
{
  DmElementHandle_t BufferType; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax

  if ( pFilmClip != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pFilmClip);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeFilmClip,0>::Set(this: &this->m_hFilmClip, h: BufferType);
  this->m_nDominantSlider = -1;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hWorkCameraParent, h: DMELEMENT_HANDLE_INVALID);
  CBaseAnimationSetControl::ClearSelection(this);
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
  if ( PresetFader != nullptr )
    CBaseAnimSetPresetFaderPanel::PopulatePresetList(this: PresetFader, bChanged: true);
}

//------------------------------------------------------------------------------
// Address: 0x00485680
// Name: public: void CBaseAnimationSetControl::AddControlSelectionChangedListener(class IAnimationSetControlSelectionChangedListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddControlSelectionChangedListener(
        CBaseAnimationSetControl *this,
        IAnimationSetControlSelectionChangedListener *listener)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_ControlSelectionChangedListeners; // esi
  int m_Size; // ecx
  int v4; // eax
  IAnimationSetControlSelectionChangedListener **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_ControlSelectionChangedListeners = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ControlSelectionChangedListeners;
  m_Size = this->m_ControlSelectionChangedListeners.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IAnimationSetControlSelectionChangedListener **)p_m_ControlSelectionChangedListeners->m_pMemory;
  while ( *m_pMemory != listener )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_ControlSelectionChangedListeners->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: p_m_ControlSelectionChangedListeners,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_ControlSelectionChangedListeners[1].m_pMemory;
    v8 = p_m_ControlSelectionChangedListeners->m_pMemory;
    v9 = (int)p_m_ControlSelectionChangedListeners[1].m_pMemory - v7 - 1;
    p_m_ControlSelectionChangedListeners[1].m_nAllocationCount = (int)p_m_ControlSelectionChangedListeners->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_ControlSelectionChangedListeners->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)listener;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485700
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmeControlGroup __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pControlGroup)
{
  CDmeControlGroup *v2; // eax
  int v3; // edi
  int m_Size; // ebx
  CDmElement *v6; // eax
  CDmeControlGroup *v7; // esi
  int v8; // ebx
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  CDmeControlGroup *GroupContainingControl; // eax
  __int32 v12; // eax
  int v13; // eax
  int nControls; // [esp+Ch] [ebp-Ch]
  SelectionState_t selection; // [esp+14h] [ebp-4h]

  v2 = pControlGroup;
  v3 = 0;
  if ( pControlGroup == nullptr )
    return 0;
  m_Size = pControlGroup->m_Children.m_Storage.m_Size;
  selection = SEL_EMPTY;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_Children.m_Storage.m_Memory.m_pMemory[v3]);
      v7 = (CDmeControlGroup *)v6;
      if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeControlGroup::m_classType) )
        v7 = nullptr;
      selection |= CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: v7);
      if ( selection == SEL_SOME )
        return 3;
      v2 = pControlGroup;
    }
    while ( ++v3 < m_Size );
  }
  v8 = 0;
  nControls = v2->m_Controls.m_Storage.m_Size;
  if ( nControls > 0 )
  {
    while ( 1 )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_Controls.m_Storage.m_Memory.m_pMemory[v8]);
      v10 = v9;
      if ( v9 != nullptr
        && v9->IsA(this: v9, a2: CDmElement::m_classType)
        && (this->m_bShowHiddenControls
         || (GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl: v10)) != nullptr
         && CDmeControlGroup::IsVisible(this: GroupContainingControl)) )
      {
        v12 = CBaseAnimationSetControl::GetSelectionComponentFlags(this, pControl: v10) & 0x3F;
        v13 = v12 != 0 ? (v12 != 63) + 2 : 1;
      }
      else
      {
        v13 = 0;
      }
      selection |= v13;
      if ( selection == SEL_SOME )
        break;
      if ( ++v8 >= nControls )
        return selection;
      v2 = pControlGroup;
    }
    return 3;
  }
  return selection;
}

//------------------------------------------------------------------------------
// Address: 0x00485850
// Name: public: void CBaseAnimationSetControl::UpdatePreviewSliderValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdatePreviewSliderValues(CBaseAnimationSetControl *this)
{
  CBaseAnimationSetControl *v1; // edi
  CBaseAnimationSetEditor *m_pEditor; // ecx
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  const char *v5; // eax
  bool v6; // dl
  bool v7; // al
  bool v8; // bl
  char v9; // cl
  bool v10; // al
  char v11; // cl
  bool v12; // al
  int v13; // eax
  CAttributeSlider *v14; // esi
  char v15; // bl
  unsigned __int16 v16; // ax
  AnimationControlAttributes_t *Value; // ebx
  const AttributeValue_t *v18; // eax
  bool v19; // bl
  const AttributeValue_t *v20; // edi
  const AttributeValue_t *v21; // [esp+8h] [ebp-A4h]
  const char *name; // [esp+14h] [ebp-98h]
  AttributeValue_t dest; // [esp+20h] [ebp-8Ch] BYREF
  float flBalanceSliderValue; // [esp+48h] [ebp-64h]
  int c; // [esp+4Ch] [ebp-60h]
  BOOL bTransform; // [esp+50h] [ebp-5Ch]
  AttributeValue_t preview; // [esp+54h] [ebp-58h] BYREF
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+7Ch] [ebp-30h]
  int y; // [esp+80h] [ebp-2Ch] BYREF
  int x; // [esp+84h] [ebp-28h] BYREF
  CBaseAnimationSetControl *v31; // [esp+88h] [ebp-24h]
  CDmElement *pControl; // [esp+8Ch] [ebp-20h] BYREF
  int i; // [esp+90h] [ebp-1Ch]
  FaderPreview_t fader; // [esp+94h] [ebp-18h] BYREF
  bool faderAmountChanged; // [esp+A8h] [ebp-4h]
  bool bFaderChanged; // [esp+A9h] [ebp-3h]
  bool shiftDown; // [esp+AAh] [ebp-2h]
  bool simple; // [esp+ABh] [ebp-1h]

  v1 = this;
  m_pEditor = this->m_pEditor;
  v31 = v1;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: m_pEditor);
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider == nullptr )
    return;
  flBalanceSliderValue = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: AttributeSlider);
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: v1->m_pEditor);
  i = (int)PresetFader;
  if ( PresetFader == nullptr )
    return;
  memset(&fader, 0, 10);
  fader.values = nullptr;
  fader.nProceduralType = 0;
  CBaseAnimSetPresetFaderPanel::GetPreviewFader(this: PresetFader, &fader);
  simple = fader.name != nullptr
        && (CUtlString::Length(this: &v1->m_PreviousPresetSlider) == 0
         || (name = fader.name,
             v5 = CUtlString::Get(this: &v1->m_PreviousPresetSlider),
             _V_stricmp(s1: v5, s2: name) != 0));
  v6 = fader.isbeingdragged != (*((_BYTE *)v1 + 104) & 1);
  v7 = (*((_BYTE *)v1 + 104) & 2) != 0;
  v8 = fader.holdingPreviewKey != v7;
  shiftDown = v6;
  if ( simple || v6 || (bFaderChanged = false, fader.holdingPreviewKey != v7) )
    bFaderChanged = true;
  faderAmountChanged = fader.amount != v1->m_flPreviousPresetAmount;
  if ( fader.holdingPreviewKey || fader.isbeingdragged && v6 || bFaderChanged )
  {
    CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(
      this: (CBaseAnimSetPresetFaderPanel *)i,
      values: fader.values);
    if ( fader.holdingPreviewKey && v8 )
    {
      v6 = shiftDown;
      v9 = 1;
      goto LABEL_21;
    }
    v6 = shiftDown;
  }
  v9 = 0;
LABEL_21:
  v10 = fader.isbeingdragged && v6;
  if ( simple || v9 != 0 || v10 )
    v10 = true;
  *((_BYTE *)v1 + 104) ^= (*((_BYTE *)v1 + 104) ^ (4 * v10)) & 4;
  CUtlString::operator=(this: &v1->m_PreviousPresetSlider, src: fader.name);
  v11 = fader.isbeingdragged | *((_BYTE *)v1 + 104) & 0xFC | (2 * fader.holdingPreviewKey);
  v1->m_flPreviousPresetAmount = fader.amount;
  *((_BYTE *)v1 + 104) = v11;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v12 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v12) )
  {
    shiftDown = true;
  }
  v13 = 0;
  c = pAttributeSlider->m_SliderList.m_Size;
  i = 0;
  if ( c > 0 )
  {
    do
    {
      v14 = pAttributeSlider->m_SliderList.m_Memory.m_pMemory[v13];
      if ( v14->IsVisible(this: v14) )
      {
        pControl = g_pDataModel->GetElement(this: g_pDataModel, a2: v14->m_hControl.m_handle);
        if ( pControl != nullptr )
        {
          v15 = *((_BYTE *)v14 + 656) & 1;
          LOBYTE(bTransform) = v15;
          if ( vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) == v14
            && v14->m_SliderMode != SLIDER_MODE_DRAG_VALUE
            && shiftDown )
          {
            memset(&preview, 0, 24);
            preview.m_Quaternion = quat_identity;
            if ( v15 != 0 )
            {
              CAttributeSlider::GetValue(this: v14, type: ANIM_CONTROL_COUNT, out: &preview.m_Vector);
              CAttributeSlider::GetValue(this: v14, type: ANIM_CONTROL_TXFORM_ORIENTATION, out: &preview.m_Quaternion);
            }
            else
            {
              g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
              vgui::Panel::ScreenToLocal(this: v14, &x, &y);
              preview.m_pValue[0] = CAttributeSlider::EstimateValueAtPos(this: v14, nLocalX: x, nLocalY: y);
              preview.m_pValue[2] = preview.m_pValue[0];
              preview.m_pValue[1] = preview.m_pValue[0];
            }
            CAttributeSlider::SetPreview(this: v14, value: &preview, full: &preview);
          }
          else if ( fader.values != nullptr )
          {
            if ( fader.isbeingdragged || (simple = false, !fader.holdingPreviewKey) )
              simple = true;
            if ( bFaderChanged || fader.isbeingdragged )
            {
              pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pControl);
              v16 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Find(
                      this: fader.values,
                      key: (DmElementHandle_t *)&pControl);
              if ( v16 == 0xFFFF )
                Value = (AnimationControlAttributes_t *)CAttributeSlider::GetValue(this: v14);
              else
                Value = &fader.values->m_Tree.m_Elements.m_pMemory[v16].m_Data.elem;
              v18 = CAttributeSlider::GetValue(this: v14);
              memset(&preview, 0, 24);
              preview.m_Quaternion = quat_identity;
              v21 = Value;
              v19 = bTransform;
              v20 = v18;
              BlendValues(
                bTransform,
                pResult: &preview,
                src: v18,
                dest: v21,
                flBlend: 1.0,
                flBalanceFilter: flBalanceSliderValue);
              if ( simple )
              {
                CAttributeSlider::SetPreview(this: v14, value: &preview, full: &preview);
              }
              else
              {
                memset(&dest, 0, 24);
                dest.m_Quaternion = quat_identity;
                BlendValues(
                  bTransform: v19,
                  pResult: &dest,
                  src: v20,
                  dest: &preview,
                  flBlend: fader.amount,
                  flBalanceFilter: 0.5);
                CAttributeSlider::SetPreview(this: v14, value: &dest, full: &preview);
              }
              v1 = v31;
            }
            if ( faderAmountChanged || fader.isbeingdragged || fader.holdingPreviewKey )
              CAttributeSlider::UpdateFaderAmount(this: v14, flAmount: fader.amount);
          }
        }
      }
      v13 = i + 1;
      i = v13;
    }
    while ( v13 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485CF0
// Name: public: void CBaseAnimationSetControl::ApplyPreset(float,class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyPreset(
        CBaseAnimationSetControl *this,
        float flScale,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *values)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  CBaseAnimSetAttributeSliderPanel *v4; // ebx
  int m_Size; // eax
  int v6; // edi
  CAttributeSlider *v7; // esi
  CExpressionCalculator *v8; // eax
  unsigned __int16 v9; // ax
  AnimationControlAttributes_t *Value; // ebx
  const AttributeValue_t *v11; // eax
  const AttributeValue_t *v12; // edi
  float flBalanceFilter; // [esp+8h] [ebp-50h]
  AttributeValue_t blend; // [esp+18h] [ebp-40h] BYREF
  int c; // [esp+40h] [ebp-18h]
  bool bTransform[4]; // [esp+44h] [ebp-14h]
  DmElementHandle_t key; // [esp+48h] [ebp-10h] BYREF
  int i; // [esp+4Ch] [ebp-Ch]
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+50h] [ebp-8h]
  bool bChanged; // [esp+57h] [ebp-1h]

  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  v4 = AttributeSlider;
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    m_Size = AttributeSlider->m_SliderList.m_Size;
    v6 = 0;
    bChanged = false;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
    {
      do
      {
        v7 = v4->m_SliderList.m_Memory.m_pMemory[v6];
        if ( v7 != nullptr && v7->IsVisible(this: v7) )
        {
          v8 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_hControl.m_handle);
          key = CCodecBuffer_Block::GetBufferType(this: v8);
          v9 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Find(this: values, &key);
          if ( v9 == 0xFFFF )
            Value = (AnimationControlAttributes_t *)CAttributeSlider::GetValue(this: v7);
          else
            Value = &values->m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
          v11 = CAttributeSlider::GetValue(this: v7);
          memset(&blend, 0, 24);
          blend.m_Quaternion = quat_identity;
          v12 = v11;
          bTransform[0] = *((_BYTE *)v7 + 656) & 1;
          flBalanceFilter = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: pAttributeSlider);
          BlendValues(
            bTransform: bTransform[0],
            pResult: &blend,
            src: v12,
            dest: Value,
            flBlend: flScale,
            flBalanceFilter);
          CAttributeSlider::SetValue(this: v7, value: &blend);
          v4 = pAttributeSlider;
          v6 = i;
          bChanged = true;
        }
        i = ++v6;
      }
      while ( v6 < c );
      if ( bChanged )
        v4->UpdatePreview(this: v4, a2: "ApplyPreset\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485E60
// Name: protected: void CBaseAnimationSetControl::ApplySliderValueWithDominance(class CAttributeSlider __near *,int,float,float,class CDmElement __near *,bool,bool,bool __near &,enum AnimationControlType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplySliderValueWithDominance(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        int si,
        float flDomStart,
        float flDomValue,
        CDmElement *pControl,
        float bUsePreviewValue,
        DmeTime_t bForce,
        bool *valuesChanged,
        float type,
        const char *pChannelAttrName,
        char *pValueAttrName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v13; // ebx
  CDmeChannel *Value; // eax
  CDmeChannel *v15; // esi
  ChannelMode_t Mode; // eax
  char v17; // cl
  DmeTime_t *CurrentTime; // eax
  char v19; // bl
  AnimationControlType_t v20; // esi
  double Preview; // st7
  float v23; // xmm1_4
  CDmaVar<float> *v24; // eax
  CDmAttribute *v25; // esi
  float m_Storage; // xmm0_4
  float flScale; // [esp+1Ch] [ebp+8h]

  Attribute = CDmElement::FindAttribute(this: pControl, pAttributeName: pValueAttrName);
  v13 = Attribute;
  pValueAttrName = (char *)Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 3 )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  v15 = Value;
  if ( Value != nullptr )
  {
    Mode = CDmeChannel::GetMode(this: Value);
    if ( Mode != CM_PASS && Mode != CM_RECORD )
    {
      v17 = 0;
      goto LABEL_9;
    }
  }
  else
  {
    Mode = CM_PASS;
  }
  v17 = 1;
LABEL_9:
  if ( Mode == CM_PLAY )
  {
    if ( pSlider->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
    {
      bUsePreviewValue = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue")->m_Storage;
      CurrentTime = CDmeChannel::GetCurrentTime(this: v15, result: &bForce);
      if ( CDmeChannel::GetPlaybackValueAtTime<float>(
             this: v15,
             a2: (int)v13,
             a3: (int)pControl,
             time: (DmeTime_t)CurrentTime->m_tms,
             value: &bUsePreviewValue) != 0 )
        CDmAttribute::SetValue<float>(this: v13, value: &bUsePreviewValue);
      else
        bUsePreviewValue = CDmAttribute::GetValue<float>(this: v13)->m_Storage;
      CAttributeSlider::SetValue(this: pSlider, type: SLODWORD(type), flValue: bUsePreviewValue);
    }
  }
  else if ( v17 != 0 )
  {
    v19 = LOBYTE(bUsePreviewValue);
    v20 = LODWORD(type);
    if ( LOBYTE(bUsePreviewValue) != 0 )
      Preview = CAttributeSlider::GetPreview(this: pSlider, type: SLODWORD(type));
    else
      Preview = CAttributeSlider::GetValue(this: pSlider, type: SLODWORD(type));
    bUsePreviewValue = Preview;
    if ( this->m_nDominantSlider >= 0 && pSlider->IsVisible(this: pSlider) && v19 == 0 && this->m_nDominantSlider != si )
    {
      type = this->m_DominantSliderStartValues.m_Memory.m_pMemory[si].m_pValue[v20];
      if ( (float)(1.0 - flDomStart) <= 0.0 )
      {
        flScale = 0.0;
      }
      else
      {
        v23 = flDomValue - flDomStart;
        if ( (float)(flDomValue - flDomStart) < 0.0 )
          v23 = 0.0;
        flScale = v23 / (float)(1.0 - flDomStart);
      }
      v24 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue");
      bUsePreviewValue = (float)((float)(1.0 - flScale) * type) + (float)(v24->m_Storage * flScale);
      CAttributeSlider::SetValue(this: pSlider, type: v20, flValue: bUsePreviewValue);
    }
    v25 = (CDmAttribute *)pValueAttrName;
    m_Storage = CDmAttribute::GetValue<float>(this: (CDmAttribute *)pValueAttrName)->m_Storage;
    if ( m_Storage != bUsePreviewValue || LOBYTE(bForce.m_tms) != 0 )
    {
      *valuesChanged = true;
      CDmAttribute::SetValue<float>(this: v25, value: &bUsePreviewValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486070
// Name: public: bool CBaseAnimationSetControl::ApplySliderValues(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::ApplySliderValues(CBaseAnimationSetControl *this, BOOL bForce)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // esi
  int m_Size; // ecx
  int v6; // eax
  CAttributeSlider *v7; // esi
  vgui::BuildGroup *v8; // edi
  bool v9; // al
  bool v10; // zf
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  bool v12; // al
  bool guard_4; // [esp+48h] [ebp-20h]
  int nSliders; // [esp+4Ch] [ebp-1Ch]
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+50h] [ebp-18h]
  float flDomStart; // [esp+54h] [ebp-14h] BYREF
  float flDomValue; // [esp+58h] [ebp-10h] BYREF
  int v18; // [esp+5Ch] [ebp-Ch]
  DmeTime_t bUsePreviewValue; // [esp+62h] [ebp-6h]
  bool shiftDown; // [esp+66h] [ebp-2h]
  bool valuesChanged; // [esp+67h] [ebp-1h] BYREF

  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider == nullptr )
    return false;
  if ( !bForce )
    LOBYTE(bForce) = *((_BYTE *)this + 104) & 1;
  guard_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  flDomStart = 0.0;
  flDomValue = 0.0;
  CBaseAnimationSetControl::GetDominantSliderValues(this, &flDomStart, &flDomValue);
  m_Size = AttributeSlider->m_SliderList.m_Size;
  v6 = 0;
  valuesChanged = false;
  nSliders = m_Size;
  v18 = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v7 = AttributeSlider->m_SliderList.m_Memory.m_pMemory[v6];
      if ( v7 != nullptr && v7->IsVisible(this: v7) )
      {
        v8 = (vgui::BuildGroup *)g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_hControl.m_handle);
        if ( v8 != nullptr )
        {
          if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
            || (v9 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v9) )
          {
            shiftDown = true;
          }
          if ( vgui::PHandle::Get(this: &this->m_ActiveAttributeSlider) != v7
            || v7->m_SliderMode == SLIDER_MODE_DRAG_VALUE
            || (v10 = !shiftDown, shiftDown = true, v10) )
          {
            shiftDown = false;
          }
          PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
          v12 = CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(this: PresetFader) != nullptr;
          LOBYTE(bUsePreviewValue.m_tms) = (*((_BYTE *)this + 104) & 2) != 0 || shiftDown || bForce && v12;
          if ( ((unsigned __int8 (__thiscall *)(vgui::BuildGroup *, CUtlSymbolLarge::<unnamed_type_u>))v8->SaveControlSettings)(
                 a1: v8,
                 a2: CDmeTransformControl::m_classType.u) != 0 )
          {
            if ( (*((_BYTE *)v7 + 656) & 2) != 0 )
              CBaseAnimationSetControl::ApplyTransformSliderValue<Quaternion>(
                this,
                pSlider: v7,
                pTranformControl: v8,
                bUsePreviewValue,
                bForce,
                &valuesChanged,
                type: ANIM_CONTROL_TXFORM_ORIENTATION);
            else
              CBaseAnimationSetControl::ApplyTransformSliderValue<Vector>(
                this,
                pSlider: v7,
                pTranformControl: v8,
                bUsePreviewValue,
                bForce,
                &valuesChanged,
                type: ANIM_CONTROL_COUNT);
          }
          else if ( CDmElement::HasAttribute(this: (CDmElement *)v8, pAttributeName: "rightValue", type: AT_UNKNOWN) )
          {
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v18,
              flDomStart,
              flDomValue,
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)&bUsePreviewValue.m_tms,
              (DmeTime_t)bForce,
              &valuesChanged,
              type: COERCE_FLOAT(2),
              pChannelAttrName: "leftvaluechannel",
              pValueAttrName: "leftValue");
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v18,
              flDomStart,
              flDomValue,
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)&bUsePreviewValue.m_tms,
              (DmeTime_t)bForce,
              &valuesChanged,
              type: COERCE_FLOAT(1),
              pChannelAttrName: "rightvaluechannel",
              pValueAttrName: "rightValue");
          }
          else
          {
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v18,
              flDomStart,
              flDomValue,
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)&bUsePreviewValue.m_tms,
              (DmeTime_t)bForce,
              &valuesChanged,
              type: 0.0,
              pChannelAttrName: "channel",
              pValueAttrName: "value");
          }
        }
      }
      v6 = v18 + 1;
      v18 = v6;
      if ( v6 >= nSliders )
        break;
      AttributeSlider = pAttributeSlider;
    }
  }
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: guard_4);
  return valuesChanged;
}

//------------------------------------------------------------------------------
// Address: 0x00486310
// Name: protected: void CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(
        CBaseAnimationSetControl *this,
        int nCount)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_crossfadePresetControlValues; // esi
  int m_Size; // ecx
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  vgui::TreeNode *v7; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax
  int nCounta; // [esp+14h] [ebp+8h]

  p_m_crossfadePresetControlValues = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_crossfadePresetControlValues;
  this->m_crossfadePresetControlValues.m_Size = 0;
  m_Size = this->m_crossfadePresetControlValues.m_Size;
  if ( m_Size < nCount )
  {
    nCounta = nCount - m_Size;
    do
    {
      v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
             a1: g_pDataModel,
             a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
             a3: "procedural preset control value",
             a4: DMFILEID_INVALID,
             a5: nullptr);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
        v7 = (vgui::TreeNode *)v6;
      else
        v7 = nullptr;
      m_pMemory = p_m_crossfadePresetControlValues[1].m_pMemory;
      m_nAllocationCount = p_m_crossfadePresetControlValues->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: p_m_crossfadePresetControlValues,
          num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_crossfadePresetControlValues[1].m_pMemory;
      v10 = p_m_crossfadePresetControlValues->m_pMemory;
      v11 = (char *)p_m_crossfadePresetControlValues[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_crossfadePresetControlValues[1].m_nAllocationCount = (int)p_m_crossfadePresetControlValues->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
      v12 = &p_m_crossfadePresetControlValues->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = v7;
      --nCounta;
    }
    while ( nCounta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004863F0
// Name: void AddKeysToPreset<class Vector>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<Vector>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  const Vector *v18; // eax
  const Vector *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  const Vector *v22; // eax
  Vector v; // [esp+Ch] [ebp-34h] BYREF
  CDmrArray<Vector> values; // [esp+18h] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+20h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+28h] [ebp-18h] BYREF
  int nKeys; // [esp+2Ch] [ebp-14h]
  DmeTime_t src; // [esp+30h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+34h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+38h] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+3Ch] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<Vector> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: "channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    CDmeChannel::GetInputValue<Vector>(this: Value, value: &v);
    CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(this: &values, src: &v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalStart, t: tStart, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalEnd, t: tEnd, bClamp: 0);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  nKeys = (int)CDmeLog::GetKeyCount(this: v14);
  if ( nKeys <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          &src);
        v18 = CDmeTypedLog<Vector>::GetValue(this: v14, time: tLocalStart);
        CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: Referring, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        &src);
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= nKeys )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    v22 = CDmeTypedLog<Vector>::GetValue(this: v14, time: tLocalEnd);
    CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
      this: &values,
      src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486620
// Name: void AddKeysToPreset<class Quaternion>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<Quaternion>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  const Quaternion *v18; // eax
  const Quaternion *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  const Quaternion *v22; // eax
  Quaternion v; // [esp+Ch] [ebp-38h] BYREF
  CDmrArray<Quaternion> values; // [esp+1Ch] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+24h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+2Ch] [ebp-18h] BYREF
  int nKeys; // [esp+30h] [ebp-14h]
  DmeTime_t src; // [esp+34h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+38h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+3Ch] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+40h] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<Quaternion> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Quaternion>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: "channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    CDmeChannel::GetInputValue<Quaternion>(this: Value, value: &v);
    CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
      this: &values,
      src: &v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalStart, t: tStart, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalEnd, t: tEnd, bClamp: 0);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  nKeys = (int)CDmeLog::GetKeyCount(this: v14);
  if ( nKeys <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          &src);
        v18 = CDmeTypedLog<Quaternion>::GetValue(this: v14, time: tLocalStart);
        CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: Referring, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        &src);
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= nKeys )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    v22 = CDmeTypedLog<Quaternion>::GetValue(this: v14, time: tLocalEnd);
    CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
      this: &values,
      src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486850
// Name: void AddKeysToPreset<float>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<float>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<float> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  float *v18; // eax
  float *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  float *v22; // eax
  CDmrArray<float> values; // [esp+Ch] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+14h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-18h] BYREF
  CDmAttribute *v; // [esp+20h] [ebp-14h] BYREF
  DmeTime_t src; // [esp+24h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+28h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+2Ch] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+30h] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<float> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: "channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    CDmeChannel::GetInputValue<float>(this: Value, value: (float *)&v);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
      this: &values,
      src: (const float *)&v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalStart, t: tStart, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalEnd, t: tEnd, bClamp: 0);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  v = CDmeLog::GetKeyCount(this: v14);
  if ( (int)v <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          &src);
        v18 = CDmeTypedLog<float>::GetValue(this: v14, a2: (int)Referring, a3: v16, time: tLocalStart);
        CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: Referring, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        &src);
      KeyValue = CDmeTypedLog<float>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= (int)v )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    v22 = CDmeTypedLog<float>::GetValue(this: v14, a2: (int)Referring, a3: v16, time: tLocalEnd);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(this: &values, src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486A80
// Name: public: virtual void CBaseAnimationSetControl::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::OnControlsAddedOrRemoved(CBaseAnimationSetControl *this)
{
  int m_Head; // edi
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *p_m_SelectionHistory; // esi
  unsigned __int16 v3; // bx
  const CDmElement *v4; // eax
  CDmeControlGroup *GroupContainingControl; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  SelectionInfo_t *psi; // [esp+4h] [ebp-Ch]
  CBaseAnimationSetControl *v8; // [esp+8h] [ebp-8h]
  bool bSelectionChanged; // [esp+Fh] [ebp-1h]

  m_Head = this->m_SelectionHistory.m_Head;
  v8 = this;
  this->m_nDominantSlider = -1;
  bSelectionChanged = false;
  if ( m_Head != 0xFFFF )
  {
    p_m_SelectionHistory = &this->m_SelectionHistory;
    do
    {
      psi = p_m_SelectionHistory->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element;
      v3 = m_Head;
      m_Head = p_m_SelectionHistory->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: psi->m_hControl.m_handle);
      if ( v4 != nullptr )
      {
        if ( v8->m_bShowHiddenControls )
          continue;
        GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl: v4);
        if ( GroupContainingControl != nullptr && CDmeControlGroup::IsVisible(this: GroupContainingControl) )
          continue;
      }
      psi->m_nComponentFlags = TRANSFORM_COMPONENT_NONE;
      CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::Unlink(
        this: p_m_SelectionHistory,
        elem: v3);
      p_m_SelectionHistory->m_Memory.m_pMemory[v3].m_Next = p_m_SelectionHistory->m_FirstFree;
      p_m_SelectionHistory->m_FirstFree = v3;
      bSelectionChanged = true;
    }
    while ( m_Head != 0xFFFF );
    if ( bSelectionChanged
      && ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      v8->FireControlSelectionChangedListeners(this: v8);
    }
    this = v8;
  }
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this: PresetFader, bChanged: false);
}

//------------------------------------------------------------------------------
// Address: 0x00486B70
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmeAnimationSet __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(CBaseAnimationSetControl *this, CDmeAnimationSet *pAnimSet)
{
  CDmeControlGroup *RootControlGroup; // eax

  if ( pAnimSet == nullptr )
    return 0;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  return CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: RootControlGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00486BA0
// Name: void SetPresetFromControlChannels(class CDmePreset __near *,class CDmElement const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPresetFromControlChannels(
        CDmePreset *pPreset,
        CDmElement *pControl,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    AddKeysToPreset<Vector>(
      pPreset,
      pValuesAttrName: "valuePositions",
      pTimesAttrName: "timePositions",
      pControl,
      pChannelAttrName: "positionChannel",
      tHead,
      tStart,
      tEnd);
    AddKeysToPreset<Quaternion>(
      pPreset,
      pValuesAttrName: "valueOrientations",
      pTimesAttrName: "timeOrientations",
      pControl,
      pChannelAttrName: "orientationChannel",
      tHead,
      tStart,
      tEnd);
  }
  if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
  {
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "leftValues",
      pTimesAttrName: "leftTimes",
      pControl,
      pChannelAttrName: "leftvaluechannel",
      tHead,
      tStart,
      tEnd);
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "rightValues",
      pTimesAttrName: "rightTimes",
      pControl,
      pChannelAttrName: "rightvaluechannel",
      tHead,
      tStart,
      tEnd);
  }
  else
  {
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "values",
      pTimesAttrName: "times",
      pControl,
      pChannelAttrName: "channel",
      tHead,
      tStart,
      tEnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486C90
// Name: protected: void CBaseAnimationSetControl::AddPreset(class CDmeAnimationSet __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddPreset(
        CBaseAnimationSetControl *this,
        CDmeAnimationSet *pAnimSet,
        const char *pPresetGroupName,
        const char *pPresetName,
        int bAnimated)
{
  CDmePresetGroup *v6; // eax
  const char *v7; // ebx
  CDmePresetGroup *v8; // esi
  CDmePreset *v9; // esi
  void (__thiscall *GetAnimatedPresetTimeParameters)(CBaseAnimationSetControl *, DmeTime_t *, DmeTime_t *, DmeTime_t *); // edx
  CDmAttribute *Attribute; // eax
  int i; // eax
  int v13; // esi
  SelectionInfo_t *m_Element; // ebx
  int BufferType; // eax
  CDmElement *v16; // eax
  int j; // eax
  int v18; // esi
  SelectionInfo_t *v19; // ebx
  int v20; // eax
  CDmeTransformControl *v21; // eax
  CDmePreset *pPreset; // [esp+Ch] [ebp-8h]
  DmeTime_t tHead; // [esp+10h] [ebp-4h] BYREF

  v6 = CDmeAnimationSet::FindOrAddPresetGroup(this: pAnimSet, pGroupName: pPresetGroupName);
  v7 = pPresetName;
  v8 = v6;
  if ( CDmePresetGroup::FindPreset(this: v6, pPresetName) == nullptr )
  {
    v9 = CDmePresetGroup::FindOrAddPreset(this: v8, pPresetName: v7);
    pPreset = v9;
    if ( (_BYTE)bAnimated != 0 )
    {
      GetAnimatedPresetTimeParameters = this->GetAnimatedPresetTimeParameters;
      tHead.m_tms = 0x80000000;
      pPresetName = (const char *)0x80000000;
      pPresetGroupName = (const char *)0x80000000;
      GetAnimatedPresetTimeParameters(
        this,
        a2: &tHead,
        a3: (DmeTime_t *)&pPresetName,
        a4: (DmeTime_t *)&pPresetGroupName);
      HIBYTE(bAnimated) = 1;
      Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "animated");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v9, pAttributeName: "animated", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&bAnimated + 3);
      }
      for ( i = this->m_SelectionHistory.m_Head; i != 0xFFFF; i = this->m_SelectionHistory.m_Memory.m_pMemory[v13].m_Next )
      {
        v13 = (unsigned __int16)i;
        m_Element = this->m_SelectionHistory.m_Memory.m_pMemory[v13].m_Element;
        if ( pAnimSet != nullptr )
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
        else
          BufferType = -1;
        if ( m_Element->m_hAnimSet.m_handle == BufferType )
        {
          v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Element->m_hControl.m_handle);
          SetPresetFromControlChannels(
            pPreset,
            pControl: v16,
            tHead,
            tStart: (DmeTime_t)pPresetName,
            tEnd: (DmeTime_t)pPresetGroupName);
        }
      }
    }
    else
    {
      for ( j = this->m_SelectionHistory.m_Head; j != 0xFFFF; j = this->m_SelectionHistory.m_Memory.m_pMemory[v18].m_Next )
      {
        v18 = (unsigned __int16)j;
        v19 = this->m_SelectionHistory.m_Memory.m_pMemory[v18].m_Element;
        if ( pAnimSet != nullptr )
          v20 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
        else
          v20 = -1;
        if ( v19->m_hAnimSet.m_handle == v20 )
        {
          v21 = (CDmeTransformControl *)g_pDataModel->GetElement(this: g_pDataModel, a2: v19->m_hControl.m_handle);
          SetPresetFromControl(pPreset, pControl: v21);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486E10
// Name: public: void CBaseAnimationSetControl::UpdateDominantSliderStartValues(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdateDominantSliderStartValues(
        CBaseAnimationSetControl *this,
        bool restoreSliderValues)
{
  CBaseAnimationSetControl *v2; // esi
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  CBaseAnimSetAttributeSliderPanel *v4; // edi
  int m_Size; // ebx
  int v6; // eax
  int v7; // ebx
  CAttributeSlider *v8; // edi
  AttributeValue_t *v9; // esi
  int nSliders; // [esp+8h] [ebp-10h]
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v2 = this;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  v4 = AttributeSlider;
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    m_Size = AttributeSlider->m_SliderList.m_Size;
    nSliders = m_Size;
    if ( v2->m_DominantSliderStartValues.m_Size == m_Size
      || (v2->m_DominantSliderStartValues.m_Size = 0,
          CUtlVector<AttributeValue_t,CUtlMemory<AttributeValue_t,int>>::InsertMultipleBefore(
            this: &v2->m_DominantSliderStartValues,
            elem: 0,
            num: m_Size),
          !restoreSliderValues) )
    {
      v6 = 0;
      i = 0;
      if ( m_Size > 0 )
      {
        v7 = 0;
        while ( 1 )
        {
          v8 = v4->m_SliderList.m_Memory.m_pMemory[v6];
          if ( v8 != nullptr && v8->IsVisible(this: v8) )
          {
            if ( restoreSliderValues )
            {
              if ( v8->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
                CAttributeSlider::SetValue(this: v8, value: &v2->m_DominantSliderStartValues.m_Memory.m_pMemory[v7]);
            }
            else
            {
              v9 = &v2->m_DominantSliderStartValues.m_Memory.m_pMemory[v7];
              *v9 = *CAttributeSlider::GetValue(this: v8);
              v2 = this;
            }
          }
          v6 = i + 1;
          ++v7;
          i = v6;
          if ( v6 >= nSliders )
            break;
          v4 = pAttributeSlider;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487050
// Name: public: bool CBaseAnimationSetControl::SelectControl(class CDmElement const __near *,enum ESelectionMode,enum TransformComponent_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimationSetControl::SelectControl(
        CBaseAnimationSetControl *this,
        const CDmElement *pControl,
        ESelectionMode selectionMode,
        TransformComponent_t nComponentFlags,
        bool bExpandTree)
{
  CDmeControlGroup *GroupContainingControl; // eax
  SelectionInfo_t *v8; // eax
  SelectionInfo_t *v9; // esi
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v11; // ecx
  SelectionInfo_t *psi; // [esp+Ch] [ebp-4h] BYREF

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  if ( pControl != nullptr )
  {
    if ( (this->m_bShowHiddenControls
       || (GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl)) != nullptr
       && CDmeControlGroup::IsVisible(this: GroupContainingControl)
       || selectionMode == SELECTION_REMOVE)
      && (v8 = this->FindSelectionInfoForControl(this, a2: pControl), v9 = v8, psi = v8, v8 != nullptr) )
    {
      if ( selectionMode != SELECTION_SET )
      {
        if ( v8->m_nComponentFlags != TRANSFORM_COMPONENT_NONE )
          CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::FindAndRemove(
            this: &this->m_SelectionHistory,
            src: &psi);
        switch ( selectionMode )
        {
          case SELECTION_ADD:
            v9->m_nComponentFlags |= nComponentFlags;
            break;
          case SELECTION_REMOVE:
            v9->m_nComponentFlags &= ~nComponentFlags;
            break;
          case SELECTION_TOGGLE:
            v9->m_nComponentFlags ^= nComponentFlags;
            break;
          default:
            break;
        }
      }
      else
      {
        CBaseAnimationSetControl::ClearSelection(this);
        v9->m_nComponentFlags = nComponentFlags;
      }
      if ( v9->m_nComponentFlags != TRANSFORM_COMPONENT_NONE )
      {
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AddToTail(
          this: &this->m_SelectionHistory,
          src: &psi);
        if ( bExpandTree )
        {
          for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
          {
            v11 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
            v11->ExpandTreeToControl(this: v11, a2: pControl, a3: nComponentFlags);
          }
        }
      }
      if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
        && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
      {
        this->FireControlSelectionChangedListeners(this);
      }
      return 1;
    }
    else
    {
      if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
        && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
      {
        this->FireControlSelectionChangedListeners(this);
      }
      return 0;
    }
  }
  else
  {
    if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      this->FireControlSelectionChangedListeners(this);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487190
// Name: public: void CBaseAnimationSetControl::SelectControlGroup(class CDmeControlGroup __near *,enum ESelectionMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SelectControlGroup(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pGroup,
        ESelectionMode selectionMode)
{
  CBaseAnimationSetControl *v3; // edi
  int v4; // esi
  CDmElement **m_pMemory; // eax
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > list; // [esp+Ch] [ebp-18h] BYREF
  CBaseAnimationSetControl *v8; // [esp+20h] [ebp-4h]

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  v3 = this;
  v8 = this;
  if ( pGroup != nullptr )
  {
    list.m_Memory.m_pMemory = nullptr;
    list.m_Memory.m_nAllocationCount = 32;
    list.m_Memory.m_nGrowSize = 0;
    list.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
    list.m_Size = 0;
    list.m_pElements = list.m_Memory.m_pMemory;
    CDmeControlGroup::GetControlsInGroup(this: pGroup, controlList: &list, recursive: true);
    v4 = list.m_Size - 1;
    if ( list.m_Size - 1 >= 0 )
    {
      do
      {
        if ( CBaseAnimationSetControl::SelectControl(
               this: v8,
               pControl: list.m_Memory.m_pMemory[v4],
               selectionMode,
               nComponentFlags: TRANSFORM_COMPONENT_ALL,
               bExpandTree: false) != 0
          && selectionMode == SELECTION_SET )
        {
          selectionMode = SELECTION_ADD;
        }
        --v4;
      }
      while ( v4 >= 0 );
      v3 = v8;
    }
    m_pMemory = list.m_Memory.m_pMemory;
    list.m_Size = 0;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( list.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    list.m_pElements = m_pMemory;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      v3->FireControlSelectionChangedListeners(this: v3);
    }
  }
  else if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
         && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    this->FireControlSelectionChangedListeners(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004872C0
// Name: public: void CBaseAnimationSetControl::SelectAnimationSet(class CDmeAnimationSet __near *,enum ESelectionMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SelectAnimationSet(
        CBaseAnimationSetControl *this,
        CDmeAnimationSet *pAnimSet,
        int selectionMode)
{
  CDmeAnimationSet *v3; // ebx
  CBaseAnimationSetControl *v4; // esi
  CDmeControlGroup *RootControlGroup; // eax
  int v6; // ebx
  CDmeDag **m_pMemory; // eax
  CDmeDag *v8; // ecx
  CDmeTransformControl *TransformControl; // eax
  int v10; // eax
  int v11; // edi
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *p_m_SelectionHistory; // esi
  unsigned __int16 v13; // ax
  int v14; // ebx
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *v15; // eax
  ESelectionMode v16; // [esp-4h] [ebp-28h]
  CUtlVector<CDmeDag *,CUtlMemory<CDmeDag *,int> > rootDagNodes; // [esp+Ch] [ebp-18h] BYREF
  CBaseAnimationSetControl *v18; // [esp+20h] [ebp-4h]

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  v3 = pAnimSet;
  v4 = this;
  v16 = selectionMode;
  v18 = this;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  CBaseAnimationSetControl::SelectControlGroup(this: v4, pGroup: RootControlGroup, selectionMode: v16);
  memset(&rootDagNodes, 0, sizeof(rootDagNodes));
  CDmeAnimationSet::FindRootDagNodes(this: v3, rootDagNodeList: &rootDagNodes);
  v6 = 0;
  selectionMode = rootDagNodes.m_Size;
  if ( rootDagNodes.m_Size > 0 )
  {
    m_pMemory = rootDagNodes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = m_pMemory[v6];
      if ( v8 != nullptr )
      {
        TransformControl = CDmeDag::FindTransformControl(this: v8);
        v10 = (int)v4->FindSelectionInfoForControl(this: v4, a2: TransformControl);
        v11 = v10;
        pAnimSet = (CDmeAnimationSet *)v10;
        if ( v10 != 0 && *(_DWORD *)(v10 + 8) != 0 )
        {
          p_m_SelectionHistory = &v4->m_SelectionHistory;
          CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::FindAndRemove(
            this: p_m_SelectionHistory,
            src: (SelectionInfo_t **)&pAnimSet);
          v13 = CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal(
                  this: p_m_SelectionHistory,
                  multilist: false);
          v14 = v13;
          if ( v13 != 0xFFFF )
          {
            CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::LinkBefore(
              this: p_m_SelectionHistory,
              before: 0xFFFFu,
              elem: v13);
            v15 = &p_m_SelectionHistory->m_Memory.m_pMemory[v14];
            if ( v15 != nullptr )
              v15->m_Element = (SelectionInfo_t *)v11;
          }
          v4 = v18;
          break;
        }
        m_pMemory = rootDagNodes.m_Memory.m_pMemory;
      }
      if ( ++v6 >= selectionMode )
        goto LABEL_14;
    }
  }
  m_pMemory = rootDagNodes.m_Memory.m_pMemory;
LABEL_14:
  rootDagNodes.m_Size = 0;
  if ( rootDagNodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      rootDagNodes.m_Memory.m_pMemory = nullptr;
    }
    rootDagNodes.m_Memory.m_nAllocationCount = 0;
  }
  rootDagNodes.m_pElements = m_pMemory;
  if ( rootDagNodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      rootDagNodes.m_Memory.m_pMemory = nullptr;
    }
    rootDagNodes.m_Memory.m_nAllocationCount = 0;
  }
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    v4->FireControlSelectionChangedListeners(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487400
// Name: public: void CBaseAnimationSetControl::AddPreset(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddPreset(
        CBaseAnimationSetControl *this,
        const char *pPresetGroupName,
        const char *pPresetName,
        int bAnimated)
{
  CDmeAnimationSet *i; // esi
  CDmeControlGroup *RootControlGroup; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Add Preset", a3: "Add Preset", a4: 0);
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Add Preset", a3: 0, a4: 256);
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: i);
    if ( (unsigned int)CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: RootControlGroup) >= 2 )
      CBaseAnimationSetControl::AddPreset(this, pAnimSet: i, pPresetGroupName, pPresetName, bAnimated);
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004874E0
// Name: public: void CBaseAnimationSetControl::UpdatePreviewSliderTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdatePreviewSliderTimes(CBaseAnimationSetControl *this)
{
  CBaseAnimationSetControl *v1; // ebx
  CBaseAnimationSetEditor *m_pEditor; // ecx
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // esi
  bool v4; // al
  bool v5; // al
  unsigned int v6; // edi
  vgui::IPanel *v7; // esi
  vgui::IPanel_vtbl *v8; // ebx
  int v9; // eax
  bool v10; // al
  vgui::PHandle *p_m_ActiveAttributeSlider; // esi
  int SliderIndexForControl; // edi
  int m_nDominantSlider; // eax
  CAttributeSlider *v14; // ebx
  bool v15; // zf
  vgui::Panel *v16; // eax
  const CDmElement *v17; // eax
  CAttributeSlider *v18; // eax
  int my; // [esp+8h] [ebp-14h] BYREF
  int mx; // [esp+Ch] [ebp-10h] BYREF
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+10h] [ebp-Ch]
  CBaseAnimationSetControl *v22; // [esp+14h] [ebp-8h]
  bool shiftDown; // [esp+1Ah] [ebp-2h]
  bool ctrlDown; // [esp+1Bh] [ebp-1h]

  v1 = this;
  m_pEditor = this->m_pEditor;
  v22 = v1;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: m_pEditor);
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL), ctrlDown = false, v4) )
    {
      ctrlDown = true;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || (v5 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v5) )
    {
      shiftDown = true;
    }
    if ( ctrlDown )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
      if ( !vgui::Panel::IsWithin(this: AttributeSlider, x: mx, y: my) )
      {
        shiftDown = false;
        ctrlDown = false;
      }
      v6 = g_pVGuiInput->GetMouseOver(this: g_pVGuiInput);
      if ( v6 != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = pAttributeSlider->GetVPanel(this: pAttributeSlider);
        v10 = v8->HasParent(this: v7, a2: v6, a3: v9);
        v1 = v22;
        if ( !v10 )
        {
          shiftDown = false;
          ctrlDown = false;
        }
      }
    }
    LOBYTE(mx) = (*((_BYTE *)v1 + 104) & 2) != 0
              || vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr && shiftDown;
    LOBYTE(my) = (*((_BYTE *)v1 + 104) & 1) != 0
              || vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr
              && vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2;
    p_m_ActiveAttributeSlider = &v1->m_ActiveAttributeSlider;
    SliderIndexForControl = -1;
    if ( vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr
      && vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2 )
    {
      if ( ctrlDown
        || (m_nDominantSlider = v1->m_nDominantSlider) >= 0
        && (v14 = pAttributeSlider->m_SliderList.m_Memory.m_pMemory[m_nDominantSlider],
            v15 = v14 == vgui::PHandle::Get(this: p_m_ActiveAttributeSlider),
            v1 = v22,
            v15) )
      {
        v16 = vgui::PHandle::Get(this: p_m_ActiveAttributeSlider);
        v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: v16[1]._panelName.m_Storage.m_Memory.m_nGrowSize);
        SliderIndexForControl = CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(
                                  this: pAttributeSlider,
                                  control: v17);
      }
    }
    if ( SliderIndexForControl != v1->m_nDominantSlider )
    {
      CBaseAnimationSetControl::UpdateDominantSliderStartValues(
        this: v1,
        restoreSliderValues: SliderIndexForControl < 0);
      v1->m_nDominantSlider = SliderIndexForControl;
    }
    if ( vgui::PHandle::Get(this: p_m_ActiveAttributeSlider) != nullptr
      && vgui::PHandle::Get(this: p_m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2 )
    {
      v18 = (CAttributeSlider *)vgui::PHandle::Get(this: p_m_ActiveAttributeSlider);
    }
    else
    {
      v18 = nullptr;
    }
    pAttributeSlider->UpdateControlSetMode(this: pAttributeSlider, a2: my, a3: mx, a4: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487770
// Name: public: virtual void CBaseAnimationSetControl::ProceduralPreset_UpdateCrossfade(class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ProceduralPreset_UpdateCrossfade(
        CBaseAnimationSetControl *this,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *pPresetValuesLookup,
        int nPresetType)
{
  CBaseAnimationSetControl *v4; // edi
  int m_ElementCount; // eax
  int v6; // xmm0_4
  CDmElement *v7; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // edx
  SelectionInfo_t *m_Element; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v17; // eax
  int v18; // ecx
  CDmElement *v19; // esi
  DmElementHandle_t BufferType; // edi
  unsigned __int16 v21; // ax
  AnimationControlAttributes_t *p_elem; // edi
  CDmElement *v23; // ecx
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // ecx
  const Vector *DefaultPosition; // eax
  CDmAttribute *v27; // eax
  CDmAttribute *v28; // esi
  const Quaternion *DefaultOrientation; // eax
  CDmAttribute *v30; // eax
  CDmAttribute *v31; // eax
  CDmAttribute *v32; // esi
  CDmAttribute *v33; // ecx
  CDmAttribute *v34; // eax
  CDmAttribute *v35; // esi
  CDmaVar<float> *v36; // eax
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t insert; // [esp+Ch] [ebp-CCh] BYREF
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t search; // [esp+60h] [ebp-78h] BYREF
  CDisableUndoScopeGuard guard; // [esp+B4h] [ebp-24h]
  int v40; // [esp+BCh] [ebp-1Ch]
  float flDefaultValue; // [esp+C0h] [ebp-18h] BYREF
  int pcvi; // [esp+C4h] [ebp-14h]
  SelectionInfo_t *psi; // [esp+C8h] [ebp-10h]
  CBaseAnimationSetControl *v44; // [esp+CCh] [ebp-Ch]
  CDmAttribute *pLeftValueAttribute; // [esp+D0h] [ebp-8h]
  CDmElement *pControl; // [esp+D4h] [ebp-4h] BYREF
  bool bSinglePreset_3; // [esp+E7h] [ebp+Fh]

  v4 = this;
  v44 = this;
  if ( nPresetType >= 5 && nPresetType <= 7 )
    return;
  guard.m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  bSinglePreset_3 = nPresetType != 1;
  m_ElementCount = 1;
  if ( nPresetType == 1 )
    m_ElementCount = v4->m_SelectionHistory.m_ElementCount;
  CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(this: v4, nCount: m_ElementCount);
  v6 = 0;
  if ( bSinglePreset_3 )
  {
    pControl = nullptr;
    if ( nPresetType != 2 )
    {
      if ( nPresetType == 3 )
      {
        v6 = 1056964608;
      }
      else
      {
        if ( nPresetType != 4 )
          goto LABEL_12;
        v6 = 1065353216;
      }
    }
    pControl = (CDmElement *)v6;
LABEL_12:
    v7 = *v4->m_crossfadePresetControlValues.m_Memory.m_pMemory;
    Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "valuePosition");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v7, pAttributeName: "valuePosition", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: Attribute, value: &vec3_origin);
    }
    v9 = CDmElement::FindAttribute(this: v7, pAttributeName: "valueOrientation");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: v7, pAttributeName: "valueOrientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v9, value: &quat_identity);
    }
    v10 = CDmElement::FindAttribute(this: v7, pAttributeName: "leftValue");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v10, value: (const float *)&pControl);
    }
    v11 = CDmElement::FindAttribute(this: v7, pAttributeName: "rightValue");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v7, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v11, value: (const float *)&pControl);
    }
    v12 = CDmElement::FindAttribute(this: v7, pAttributeName: "value");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(this: v7, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v12, value: (const float *)&pControl);
    }
  }
  CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &pPresetValuesLookup->m_Tree);
  m_Head = v4->m_SelectionHistory.m_Head;
  pcvi = -1;
  if ( m_Head != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = v4->m_SelectionHistory.m_Memory.m_pMemory;
      v40 = 8 * (unsigned __int16)m_Head;
      m_Element = m_pMemory[v40 / 8u].m_Element;
      GetElement = g_pDataModel->GetElement;
      psi = m_Element;
      v17 = GetElement(this: g_pDataModel, a2: m_Element->m_hControl.m_handle);
      pControl = v17;
      if ( v17 != nullptr )
        break;
LABEL_71:
      m_Head = v4->m_SelectionHistory.m_Memory.m_pMemory[v40 / 8u].m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_72;
    }
    if ( bSinglePreset_3 )
      v18 = 0;
    else
      v18 = ++pcvi;
    v19 = v4->m_crossfadePresetControlValues.m_Memory.m_pMemory[v18];
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
    memset(&search.elem, 0, 24);
    search.elem.m_Quaternion = quat_identity;
    memset(search.elem.m_pValueAttribute, 0, 40);
    search.key = BufferType;
    v21 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &pPresetValuesLookup->m_Tree,
            &search);
    if ( v21 == 0xFFFF )
    {
      memset(&insert.elem, 0, 24);
      insert.elem.m_Quaternion = quat_identity;
      memset(insert.elem.m_pValueAttribute, 0, 40);
      insert.key = BufferType;
      v21 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
              this: &pPresetValuesLookup->m_Tree,
              &insert);
    }
    p_elem = &pPresetValuesLookup->m_Tree.m_Elements.m_pMemory[v21].m_Data.elem;
    _V_memset(dest: p_elem, fill: 0, count: 80);
    v23 = pControl;
    p_elem->m_Quaternion = quat_identity;
    if ( !v23->IsA(this: v23, a2: CDmeTransformControl::m_classType) )
    {
      if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
      {
        v30 = CDmElement::FindAttribute(this: v19, pAttributeName: "leftValue");
        if ( v30 != nullptr )
          pLeftValueAttribute = (v30->m_nFlags & 0x1F) != 3 ? nullptr : v30;
        else
          pLeftValueAttribute = CDmElement::CreateAttribute(this: v19, pAttributeName: "leftValue", type: AT_FLOAT);
        v31 = CDmElement::FindAttribute(this: v19, pAttributeName: "rightValue");
        if ( v31 != nullptr )
          v32 = (v31->m_nFlags & 0x1F) != 3 ? nullptr : v31;
        else
          v32 = CDmElement::CreateAttribute(this: v19, pAttributeName: "rightValue", type: AT_FLOAT);
        v33 = pLeftValueAttribute;
        if ( pLeftValueAttribute != nullptr && v32 != nullptr )
        {
          if ( !bSinglePreset_3 )
          {
            flDefaultValue = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue")->m_Storage;
            CDmAttribute::SetValue<float>(this: pLeftValueAttribute, value: &flDefaultValue);
            CDmAttribute::SetValue<float>(this: v32, value: &flDefaultValue);
            v33 = pLeftValueAttribute;
          }
          p_elem->m_pValueAttribute[2] = v33;
          p_elem->m_pValue[2] = CDmAttribute::GetValue<float>(this: v33)->m_Storage;
          p_elem->m_pValueAttribute[1] = v32;
          p_elem->m_pValue[1] = CDmAttribute::GetValue<float>(this: v32)->m_Storage;
        }
      }
      else
      {
        v34 = CDmElement::FindAttribute(this: v19, pAttributeName: "value");
        if ( v34 != nullptr )
          v35 = (v34->m_nFlags & 0x1F) != 3 ? nullptr : v34;
        else
          v35 = CDmElement::CreateAttribute(this: v19, pAttributeName: "value", type: AT_FLOAT);
        if ( v35 != nullptr )
        {
          if ( !bSinglePreset_3 )
          {
            v36 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue");
            CDmAttribute::SetValue<float>(this: v35, value: &v36->m_Storage);
          }
          p_elem->m_pValueAttribute[0] = v35;
          p_elem->m_pValue[0] = CDmAttribute::GetValue<float>(this: v35)->m_Storage;
        }
      }
      goto LABEL_70;
    }
    if ( (psi->m_nComponentFlags & 7) != 0 )
    {
      v24 = CDmElement::FindAttribute(this: v19, pAttributeName: "valuePosition");
      if ( v24 != nullptr )
      {
        v25 = (v24->m_nFlags & 0x1F) != 10 ? nullptr : v24;
        pLeftValueAttribute = v25;
      }
      else
      {
        pLeftValueAttribute = CDmElement::CreateAttribute(this: v19, pAttributeName: "valuePosition", type: AT_VECTOR3);
        v25 = pLeftValueAttribute;
      }
      if ( v25 == nullptr )
      {
LABEL_70:
        v4 = v44;
        goto LABEL_71;
      }
      if ( !bSinglePreset_3 )
      {
        DefaultPosition = CDmeTransformControl::GetDefaultPosition(this: (CDmeTransformControl *)pControl);
        CDmAttribute::SetValue<Vector>(this: pLeftValueAttribute, value: DefaultPosition);
        v25 = pLeftValueAttribute;
      }
      p_elem->m_pValueAttribute[3] = v25;
      p_elem->m_Vector = CDmAttribute::GetValue<Vector>(this: v25)->m_Storage;
    }
    if ( (psi->m_nComponentFlags & 0x38) != 0 )
    {
      v27 = CDmElement::FindAttribute(this: v19, pAttributeName: "valueOrientation");
      v28 = v27 != nullptr
          ? ((v27->m_nFlags & 0x1F) != 13
           ? nullptr
           : v27)
          : CDmElement::CreateAttribute(this: v19, pAttributeName: "valueOrientation", type: AT_QUATERNION);
      if ( v28 != nullptr )
      {
        if ( !bSinglePreset_3 )
        {
          DefaultOrientation = CDmeTransformControl::GetDefaultOrientation(this: (CDmeTransformControl *)pControl);
          CDmAttribute::SetValue<Quaternion>(this: v28, value: DefaultOrientation);
        }
        p_elem->m_pValueAttribute[4] = v28;
        p_elem->m_Quaternion = *CDmAttribute::GetValue<Quaternion>(this: v28);
      }
    }
    goto LABEL_70;
  }
LABEL_72:
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&guard.m_bOldValue);
}

//------------------------------------------------------------------------------
// Address: 0x0067DDF0
// Name: _dynamic_initializer_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeChannel::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeChannel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006822E0
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00482F20
// Name: class Quaternion MaskValue<class Quaternion>(class Quaternion const __near &,class Quaternion const __near &,enum LogComponents_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Quaternion *__cdecl MaskValue<Quaternion>(
        Quaternion *result,
        const Quaternion *value,
        const Quaternion *curQuat,
        LogComponents_t componentFlags)
{
  QAngle curQA; // [esp+0h] [ebp-18h] BYREF
  QAngle valueQA; // [esp+Ch] [ebp-Ch] BYREF

  QuaternionAngles(q: curQuat, angles: &curQA);
  QuaternionAngles(q: value, angles: &valueQA);
  if ( (componentFlags & 1) == 0 )
    valueQA.x = curQA.x;
  if ( (componentFlags & 2) == 0 )
    valueQA.y = curQA.y;
  if ( (componentFlags & 4) == 0 )
    valueQA.z = curQA.z;
  AngleQuaternion(angles: &valueQA, outQuat: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067DE20
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067DE30
// Name: _dynamic_initializer_for__g_CDmeChannel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeChannel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeChannel_Helper,
           classname: "DmeChannel",
           pFactory: &g_CDmeChannel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006822F0
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x00682300
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10486DB0
// Name: public: bool Quaternion::operator!=(class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Quaternion::operator!=(Quaternion *this, const Quaternion *src)
{
  return this->x != src->x || this->y != src->y || this->z != src->z || this->w != src->w;
}

//------------------------------------------------------------------------------
// Address: 0x10486E80
// Name: public: class CDmAttribute __near * CDmeChannel::GetFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::GetFromAttribute(CDmeChannel *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
  if ( result == nullptr )
    return CDmeChannel::SetupFromAttribute(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10486EB0
// Name: protected: virtual void CBaseAnimationSetControl::GetAnimatedPresetTimeParameters(class DmeTime_t __near &,class DmeTime_t __near &,class DmeTime_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::GetAnimatedPresetTimeParameters(
        CBaseAnimationSetControl *this,
        int tHead,
        DmeTime_t *tStart,
        DmeTime_t *tEnd)
{
  DmeTime_t v4; // [esp+4h] [ebp-4h] BYREF

  v4.m_tms = (int)this;
  *(_DWORD *)tHead = 0;
  tHead = -2147483647;
  DmeTime_t::operator/=(this: (DmeTime_t *)&tHead, result: &v4, f: 2.0);
  tStart->m_tms = tHead;
  tHead = 0x7FFFFFFF;
  DmeTime_t::operator/=(this: (DmeTime_t *)&tHead, result: (DmeTime_t *)&tStart, f: 2.0);
  tEnd->m_tms = tHead;
}

//------------------------------------------------------------------------------
// Address: 0x10486F20
// Name: public: bool CBaseAnimationSetControl::IsControlGroupVisible(class CDmeControlGroup const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::IsControlGroupVisible(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pGroup)
{
  return this->m_bShowHiddenControls || CDmeControlGroup::IsVisible(this: pGroup);
}

//------------------------------------------------------------------------------
// Address: 0x10486F40
// Name: public: bool CBaseAnimationSetControl::IsPresetFaderBeingDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::IsPresetFaderBeingDragged(CBaseAnimationSetControl *this)
{
  return *((_BYTE *)this + 104) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10486F50
// Name: public: struct AttributeValue_t __near & AttributeValue_t::operator=(struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
AttributeValue_t *__thiscall AttributeValue_t::operator=(AttributeValue_t *this, const AttributeValue_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10487240
// Name: public: class CDmeFilmClip __near * CBaseAnimationSetControl::GetAnimationSetClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeFilmClip *__thiscall CBaseAnimationSetControl::GetAnimationSetClip(CBaseAnimationSetControl *this)
{
  return (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x10487260
// Name: public: void CBaseAnimationSetControl::SetActiveAttributeSlider(class CAttributeSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetActiveAttributeSlider(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_ActiveAttributeSlider,
    pPanel: (CDragDropHelperPanel *)pSlider);
}

//------------------------------------------------------------------------------
// Address: 0x10487270
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<float>(class DmeTime_t,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDmeChannel::GetPlaybackValueAtTime<float>@<al>(
        CDmeChannel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        DmeTime_t time,
        float *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<float> *v6; // esi
  int m_tms; // eax
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v6 = (CDmeTypedLog<float> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) || CDmeLog::IsEmpty(this: v6) != 0 )
    return 0;
  CDmeLog::GetBeginTime(this: v6, result: &t0);
  CDmeLog::GetEndTime(this: v6, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  *value = *CDmeTypedLog<float>::GetValue(this: v6, a2, a3, time: (DmeTime_t)m_tms);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10487500
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<class Quaternion>(class DmeTime_t,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetPlaybackValueAtTime<Quaternion>(CDmeChannel *this, DmeTime_t time, Quaternion *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v4; // esi
  int m_tms; // eax
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v4 = (CDmeTypedLog<Quaternion> *)Log;
  if ( Log == nullptr
    || !Log->IsA(this: Log, a2: CDmeTypedLog<Quaternion>::m_classType)
    || CDmeLog::IsEmpty(this: v4) != 0 )
  {
    return 0;
  }
  CDmeLog::GetBeginTime(this: v4, result: &t0);
  CDmeLog::GetEndTime(this: v4, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  *value = *CDmeTypedLog<Quaternion>::GetValue(this: v4, time: (DmeTime_t)m_tms);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10487590
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<class Vector>(class DmeTime_t,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetPlaybackValueAtTime<Vector>(CDmeChannel *this, DmeTime_t time, Vector *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v4; // esi
  int m_tms; // eax
  const Vector *v6; // eax
  double z; // st7
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v4 = (CDmeTypedLog<Vector> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) || CDmeLog::IsEmpty(this: v4) != 0 )
    return 0;
  CDmeLog::GetBeginTime(this: v4, result: &t0);
  CDmeLog::GetEndTime(this: v4, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  v6 = CDmeTypedLog<Vector>::GetValue(this: v4, time: (DmeTime_t)m_tms);
  value->x = v6->x;
  value->y = v6->y;
  z = v6->z;
  value->z = z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10487730
// Name: public: class CDmeDag __near * CBaseAnimationSetControl::GetWorkCameraParent(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CBaseAnimationSetControl::GetWorkCameraParent(CBaseAnimationSetControl *this)
{
  return (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hWorkCameraParent.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x10487750
// Name: protected: virtual void CBaseAnimationSetControl::FireControlSelectionChangedListeners(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::FireControlSelectionChangedListeners(CBaseAnimationSetControl *this)
{
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v3; // ecx

  for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
  {
    v3 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
    v3->OnControlSelectionChanged(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10487780
// Name: protected: virtual void CBaseAnimationSetControl::FireRebuildControlHierarchyListeners(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::FireRebuildControlHierarchyListeners(CBaseAnimationSetControl *this)
{
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v3; // ecx

  for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
  {
    v3 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
    v3->OnRebuildControlHierarchy(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104877B0
// Name: public: void CBaseAnimationSetControl::SetRangeSelectionState(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetRangeSelectionState(
        CBaseAnimationSetControl *this,
        bool bInRangeSelection)
{
  if ( (_S1_48 & 1) == 0 )
  {
    _S1_48 |= 1u;
    sg.m_pControl = this;
    sg.m_selectionMode = SELECTION_REMOVE;
    atexit(func: CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__);
  }
  if ( bInRangeSelection )
  {
    ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
    sg.m_selectionMode = SELECTION_SET;
  }
  else if ( --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    sg.m_pControl->FireControlSelectionChangedListeners(this: sg.m_pControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10487820
// Name: public: class CDmElement __near * CBaseAnimationSetControl::GetMostRecentlySelectedControl(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAnimationSetControl::GetMostRecentlySelectedControl(CBaseAnimationSetControl *this)
{
  int m_Tail; // eax

  m_Tail = this->m_SelectionHistory.m_Tail;
  if ( m_Tail == 0xFFFF )
    return nullptr;
  else
    return g_pDataModel->GetElement(
             this: g_pDataModel,
             a2: this->m_SelectionHistory.m_Memory.m_pMemory[m_Tail].m_Element->m_hControl.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x10487850
// Name: public: void CBaseAnimationSetControl::GetDominantSliderValues(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::GetDominantSliderValues(
        CBaseAnimationSetControl *this,
        float *flDomStart,
        float *flDomValue)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  int m_nDominantSlider; // ecx
  CAttributeSlider *v6; // edi
  char v7; // al
  AnimationControlType_t v8; // esi
  float v9; // xmm0_4
  float flDomStarta; // [esp+8h] [ebp+8h]

  *flDomStart = 0.0;
  *flDomValue = 0.0;
  if ( this->m_nDominantSlider < 0 )
    return;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  if ( AttributeSlider == nullptr )
    return;
  m_nDominantSlider = this->m_nDominantSlider;
  v6 = AttributeSlider->m_SliderList.m_Memory.m_pMemory[m_nDominantSlider];
  if ( v6 == nullptr )
    return;
  v7 = *((_BYTE *)v6 + 656);
  if ( (v7 & 1) != 0 )
    return;
  v8 = (v7 & 4) != 0;
  v9 = this->m_DominantSliderStartValues.m_Memory.m_pMemory[m_nDominantSlider].m_pValue[v8];
  if ( v9 > 1.0 )
    goto LABEL_9;
  if ( v9 >= 0.0 )
  {
    if ( v9 <= 1.0 )
      goto LABEL_10;
LABEL_9:
    v9 = 1.0;
    goto LABEL_10;
  }
  v9 = 0.0;
LABEL_10:
  *flDomStart = v9;
  if ( CAttributeSlider::GetValue(this: v6, type: v8) > 1.0 || CAttributeSlider::GetValue(this: v6, type: v8) >= 0.0 )
  {
    if ( CAttributeSlider::GetValue(this: v6, type: v8) <= 1.0 )
    {
      flDomStarta = CAttributeSlider::GetValue(this: v6, type: v8);
      *flDomValue = flDomStarta;
    }
    else
    {
      *flDomValue = 1.0;
    }
  }
  else
  {
    *flDomValue = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10487CF0
// Name: protected: bool CDmeChannel::GetValue<class Vector>(class Vector __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<Vector>(CDmeChannel *this, Vector *value, CDmAttribute *pAttr, int nIndex)
{
  CDmaVar<Vector> *v4; // eax
  double z; // st7
  CDmrArrayConst<Vector> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      v4 = CDmAttribute::GetValue<Vector>(this: pAttr);
      goto LABEL_6;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      v4 = (CDmaVar<Vector> *)&array.m_pStorage->m_Memory.m_pMemory[nIndex];
LABEL_6:
      value->x = v4->m_Storage.x;
      value->y = v4->m_Storage.y;
      z = v4->m_Storage.z;
      value->z = z;
      return 1;
    }
  }
  value->x = 0.0;
  value->y = 0.0;
  value->z = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10487D80
// Name: protected: bool CDmeChannel::GetValue<class Quaternion>(class Quaternion __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<Quaternion>(
        CDmeChannel *this,
        Quaternion *value,
        CDmAttribute *pAttr,
        int nIndex)
{
  Quaternion *v4; // eax
  CDmrArrayConst<Quaternion> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      v4 = (Quaternion *)CDmAttribute::GetValue<Quaternion>(this: pAttr);
      goto LABEL_6;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      v4 = &array.m_pStorage->m_Memory.m_pMemory[nIndex];
LABEL_6:
      *value = *v4;
      return 1;
    }
  }
  value->x = 0.0;
  value->y = 0.0;
  value->z = 0.0;
  value->w = 1.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10487E20
// Name: protected: bool CDmeChannel::GetValue<float>(float __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<float>(CDmeChannel *this, float *value, CDmAttribute *pAttr, int nIndex)
{
  CDmrArrayConst<float> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      *value = CDmAttribute::GetValue<float>(this: pAttr)->m_Storage;
      return 1;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      *value = array.m_pStorage->m_Memory.m_pMemory[nIndex];
      return 1;
    }
  }
  *value = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10488080
// Name: public: void CBaseAnimationSetControl::SetWorkCameraParent(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetWorkCameraParent(CBaseAnimationSetControl *this, CDmeDag *pParent)
{
  CDmeHandle<CDmeDag,0> *p_m_hWorkCameraParent; // esi
  DmElementHandle_t BufferType; // eax

  p_m_hWorkCameraParent = &this->m_hWorkCameraParent;
  if ( pParent != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pParent);
    CDmeHandle<CDmeDag,0>::Set(this: p_m_hWorkCameraParent, h: BufferType);
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: p_m_hWorkCameraParent, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104880B0
// Name: public: enum TransformComponent_t CBaseAnimationSetControl::GetSelectionComponentFlags(class CDmElement __near *)const
// Source: json
//------------------------------------------------------------------------------
TransformComponent_t __thiscall CBaseAnimationSetControl::GetSelectionComponentFlags(
        CBaseAnimationSetControl *this,
        CDmElement *pControl)
{
  int m_Head; // eax
  int v5; // esi
  SelectionInfo_t *m_Element; // edi

  if ( pControl == nullptr )
    return TRANSFORM_COMPONENT_NONE;
  m_Head = this->m_SelectionHistory.m_Head;
  if ( m_Head == 0xFFFF )
    return TRANSFORM_COMPONENT_NONE;
  while ( 1 )
  {
    v5 = (unsigned __int16)m_Head;
    m_Element = this->m_SelectionHistory.m_Memory.m_pMemory[v5].m_Element;
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: m_Element->m_hControl.m_handle) == pControl )
      break;
    m_Head = this->m_SelectionHistory.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == 0xFFFF )
      return TRANSFORM_COMPONENT_NONE;
  }
  return m_Element->m_nComponentFlags;
}

//------------------------------------------------------------------------------
// Address: 0x10488640
// Name: public: bool CDmeChannel::GetInputValue<class Vector>(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<Vector>(CDmeChannel *this, Vector *value)
{
  CDmAttribute *v3; // eax

  v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<Vector>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x10488680
// Name: public: bool CDmeChannel::GetInputValue<class Quaternion>(class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<Quaternion>(CDmeChannel *this, Quaternion *value)
{
  CDmAttribute *v3; // eax

  v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<Quaternion>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x104886C0
// Name: public: bool CDmeChannel::GetInputValue<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<float>(CDmeChannel *this, float *value)
{
  CDmAttribute *v3; // eax

  v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<float>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x10488F90
// Name: public: void CBaseAnimationSetControl::ClearSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ClearSelection(CBaseAnimationSetControl *this)
{
  int m_Tail; // eax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // ecx
  int v4; // eax

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  m_Tail = this->m_SelectionHistory.m_Tail;
  if ( m_Tail != 0xFFFF )
  {
    m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
    do
    {
      v4 = (unsigned __int16)m_Tail;
      m_pMemory[v4].m_Element->m_nComponentFlags = TRANSFORM_COMPONENT_NONE;
      m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
      m_Tail = m_pMemory[v4].m_Previous;
    }
    while ( m_Tail != 0xFFFF );
  }
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SelectionHistory);
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    this->FireControlSelectionChangedListeners(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10488FF0
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmElement __near *,enum TransformComponent_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(
        CBaseAnimationSetControl *this,
        CDmElement *pControl,
        TransformComponent_t componentFlags)
{
  CDmeControlGroup *GroupContainingControl; // eax
  __int32 v5; // eax

  if ( pControl == nullptr )
    return 0;
  if ( !this->m_bShowHiddenControls )
  {
    GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl);
    if ( GroupContainingControl == nullptr || !CDmeControlGroup::IsVisible(this: GroupContainingControl) )
      return 0;
  }
  v5 = componentFlags & CBaseAnimationSetControl::GetSelectionComponentFlags(this, pControl);
  if ( v5 != 0 )
    return (v5 != componentFlags) + 2;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10489060
// Name: void SetPresetFromControl(class CDmePreset __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPresetFromControl(CDmePreset *pPreset, CDmeTransformControl *pControl)
{
  const char *m_pAsString; // eax
  CDmElement *v3; // esi
  CDmaVar<Vector> *Position; // ebx
  CDmAttribute *Attribute; // eax
  CDmaVar<Quaternion> *Orientation; // edi
  CDmAttribute *v7; // eax
  const char *v8; // eax
  CDmElement *v9; // esi
  CDmaVar<float> *v10; // ebx
  CDmAttribute *v11; // eax
  CDmaVar<float> *v12; // edi
  CDmAttribute *v13; // eax
  CDmaVar<float> *v14; // edi
  CDmAttribute *v15; // eax

  if ( pControl != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    m_pAsString = pControl->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    v3 = CDmePreset::FindOrAddControlValue(this: pPreset, pControlName: m_pAsString);
    if ( v3 != nullptr )
    {
      if ( CDmeTransformControl::GetPositionChannel(this: pControl) != nullptr )
      {
        Position = CDmeTransformControl::GetPosition(this: pControl);
        Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "valuePosition");
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "valuePosition", type: AT_VECTOR3)) != nullptr )
        {
          CDmAttribute::SetValue<Vector>(this: Attribute, value: &Position->m_Storage);
        }
      }
      if ( CDmeTransformControl::GetOrientationChannel(this: pControl) != nullptr )
      {
        Orientation = CDmeTransformControl::GetOrientation(this: pControl);
        v7 = CDmElement::FindAttribute(this: v3, pAttributeName: "valueOrientation");
        if ( v7 != nullptr
          || (v7 = CDmElement::CreateAttribute(this: v3, pAttributeName: "valueOrientation", type: AT_QUATERNION)) != nullptr )
        {
          CDmAttribute::SetValue<Quaternion>(this: v7, value: &Orientation->m_Storage);
        }
      }
    }
  }
  else
  {
    v8 = pControl->m_Name.m_Storage.u.m_pAsString;
    if ( v8 == (const char *)-1 )
      v8 = &var;
    v9 = CDmePreset::FindOrAddControlValue(this: pPreset, pControlName: v8);
    if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
    {
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "value");
      v10 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "leftValue");
      v11 = CDmElement::FindAttribute(this: v9, pAttributeName: "leftValue");
      if ( v11 != nullptr
        || (v11 = CDmElement::CreateAttribute(this: v9, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v11, value: &v10->m_Storage);
      }
      v12 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "rightValue");
      v13 = CDmElement::FindAttribute(this: v9, pAttributeName: "rightValue");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v9, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v13, value: &v12->m_Storage);
      }
    }
    else
    {
      v14 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "value");
      v15 = CDmElement::FindAttribute(this: v9, pAttributeName: "value");
      if ( v15 != nullptr
        || (v15 = CDmElement::CreateAttribute(this: v9, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v15, value: &v14->m_Storage);
      }
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "leftValue");
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "rightValue");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10489450
// Name: public: CBaseAnimationSetControl::CBaseAnimationSetControl(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetControl *__thiscall CBaseAnimationSetControl::CBaseAnimationSetControl(CBaseAnimationSetControl *this)
{
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // eax

  this->__vftable = (CBaseAnimationSetControl_vtbl *)&CBaseAnimationSetControl::`vftable';
  this->m_hFilmClip.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_pEditor = nullptr;
  this->m_SelectionHistory.m_Memory.m_pMemory = nullptr;
  this->m_SelectionHistory.m_Memory.m_nAllocationCount = 0;
  this->m_SelectionHistory.m_Memory.m_nGrowSize = 0;
  this->m_SelectionHistory.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_SelectionHistory.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_SelectionHistory.m_Head = -1;
  this->m_SelectionHistory.m_pElements = m_pMemory;
  this->m_SelectionHistory.m_NumAlloced = 0;
  this->m_hWorkCameraParent.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_OverrideParentChangedListeners.m_Memory.m_pMemory = nullptr;
  this->m_OverrideParentChangedListeners.m_Memory.m_nAllocationCount = 0;
  this->m_OverrideParentChangedListeners.m_Memory.m_nGrowSize = 0;
  this->m_OverrideParentChangedListeners.m_Size = 0;
  this->m_OverrideParentChangedListeners.m_pElements = nullptr;
  this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory = nullptr;
  this->m_ControlSelectionChangedListeners.m_Memory.m_nAllocationCount = 0;
  this->m_ControlSelectionChangedListeners.m_Memory.m_nGrowSize = 0;
  this->m_ControlSelectionChangedListeners.m_Size = 0;
  this->m_ControlSelectionChangedListeners.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_PreviousPresetSlider, pString: (char *)&var);
  *((_BYTE *)this + 104) &= 0xF8u;
  this->m_flPreviousPresetAmount = 0.0;
  this->m_ActiveAttributeSlider.m_iPanelID = -1;
  this->m_DominantSliderStartValues.m_Memory.m_pMemory = nullptr;
  this->m_DominantSliderStartValues.m_Memory.m_nAllocationCount = 0;
  this->m_DominantSliderStartValues.m_Memory.m_nGrowSize = 0;
  this->m_DominantSliderStartValues.m_Size = 0;
  this->m_DominantSliderStartValues.m_pElements = nullptr;
  this->m_nDominantSlider = -1;
  this->m_bShowHiddenControls = false;
  this->m_crossfadePresetControlValues.m_Memory.m_pMemory = nullptr;
  this->m_crossfadePresetControlValues.m_Memory.m_nAllocationCount = 0;
  this->m_crossfadePresetControlValues.m_Memory.m_nGrowSize = 0;
  this->m_crossfadePresetControlValues.m_Size = 0;
  this->m_crossfadePresetControlValues.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10489510
// Name: public: virtual void CBaseAnimationSetControl::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ChangeAnimationSetClip(
        CBaseAnimationSetControl *this,
        CDmeFilmClip *pFilmClip)
{
  DmElementHandle_t BufferType; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax

  if ( pFilmClip != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pFilmClip);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeFilmClip,0>::Set(this: &this->m_hFilmClip, h: BufferType);
  this->m_nDominantSlider = -1;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hWorkCameraParent, h: DMELEMENT_HANDLE_INVALID);
  CBaseAnimationSetControl::ClearSelection(this);
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
  if ( PresetFader != nullptr )
    CBaseAnimSetPresetFaderPanel::PopulatePresetList(this: PresetFader, bChanged: true);
}

//------------------------------------------------------------------------------
// Address: 0x10489570
// Name: public: void CBaseAnimationSetControl::AddControlSelectionChangedListener(class IAnimationSetControlSelectionChangedListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddControlSelectionChangedListener(
        CBaseAnimationSetControl *this,
        IAnimationSetControlSelectionChangedListener *listener)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_ControlSelectionChangedListeners; // esi
  int m_Size; // ecx
  int v4; // eax
  IAnimationSetControlSelectionChangedListener **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_ControlSelectionChangedListeners = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ControlSelectionChangedListeners;
  m_Size = this->m_ControlSelectionChangedListeners.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IAnimationSetControlSelectionChangedListener **)p_m_ControlSelectionChangedListeners->m_pMemory;
  while ( *m_pMemory != listener )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_ControlSelectionChangedListeners->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: p_m_ControlSelectionChangedListeners,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_ControlSelectionChangedListeners[1].m_pMemory;
    v8 = p_m_ControlSelectionChangedListeners->m_pMemory;
    v9 = (int)p_m_ControlSelectionChangedListeners[1].m_pMemory - v7 - 1;
    p_m_ControlSelectionChangedListeners[1].m_nAllocationCount = (int)p_m_ControlSelectionChangedListeners->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v8[v7 + 1], src: (unsigned __int8 *)&v8[v7], count: 4 * v9);
    v10 = &p_m_ControlSelectionChangedListeners->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)listener;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104895F0
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmeControlGroup __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pControlGroup)
{
  CDmeControlGroup *v2; // eax
  int v3; // edi
  int m_Size; // ebx
  CDmElement *v6; // eax
  CDmeControlGroup *v7; // esi
  int v8; // ebx
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  CDmeControlGroup *GroupContainingControl; // eax
  __int32 v12; // eax
  int v13; // eax
  int nControls; // [esp+Ch] [ebp-Ch]
  SelectionState_t selection; // [esp+14h] [ebp-4h]

  v2 = pControlGroup;
  v3 = 0;
  if ( pControlGroup == nullptr )
    return 0;
  m_Size = pControlGroup->m_Children.m_Storage.m_Size;
  selection = SELECT_NONE;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_Children.m_Storage.m_Memory.m_pMemory[v3]);
      v7 = (CDmeControlGroup *)v6;
      if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeControlGroup::m_classType) )
        v7 = nullptr;
      selection |= CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: v7);
      if ( selection == SELECT_MULTI_PARTIAL )
        return 3;
      v2 = pControlGroup;
    }
    while ( ++v3 < m_Size );
  }
  v8 = 0;
  nControls = v2->m_Controls.m_Storage.m_Size;
  if ( nControls > 0 )
  {
    while ( 1 )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_Controls.m_Storage.m_Memory.m_pMemory[v8]);
      v10 = v9;
      if ( v9 != nullptr
        && v9->IsA(this: v9, a2: CDmElement::m_classType)
        && (this->m_bShowHiddenControls
         || (GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl: v10)) != nullptr
         && CDmeControlGroup::IsVisible(this: GroupContainingControl)) )
      {
        v12 = CBaseAnimationSetControl::GetSelectionComponentFlags(this, pControl: v10) & 0x3F;
        v13 = v12 != 0 ? (v12 != 63) + 2 : 1;
      }
      else
      {
        v13 = 0;
      }
      selection |= v13;
      if ( selection == SELECT_MULTI_PARTIAL )
        break;
      if ( ++v8 >= nControls )
        return selection;
      v2 = pControlGroup;
    }
    return 3;
  }
  return selection;
}

//------------------------------------------------------------------------------
// Address: 0x10489740
// Name: public: void CBaseAnimationSetControl::UpdatePreviewSliderValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdatePreviewSliderValues(CBaseAnimationSetControl *this)
{
  CBaseAnimationSetControl *v1; // edi
  CBaseAnimationSetEditor *m_pEditor; // ecx
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  const char *v5; // eax
  char v6; // dl
  unsigned __int8 v7; // al
  bool v8; // bl
  char v9; // cl
  bool v10; // al
  char v11; // cl
  bool v12; // al
  CBaseAnimSetPresetFaderPanel *v13; // eax
  CAttributeSlider *v14; // esi
  bool v15; // bl
  unsigned __int16 v16; // ax
  AnimationControlAttributes_t *Value; // ebx
  const AttributeValue_t *v18; // eax
  bool v19; // bl
  const AttributeValue_t *v20; // edi
  const AttributeValue_t *v21; // [esp-4h] [ebp-A4h]
  CBaseAnimSetAttributeSliderPanel *v22; // [esp+8h] [ebp-98h]
  AttributeValue_t pResult; // [esp+14h] [ebp-8Ch] BYREF
  float flBalanceFilter; // [esp+3Ch] [ebp-64h]
  int m_Size; // [esp+40h] [ebp-60h]
  bool v26; // [esp+44h] [ebp-5Ch]
  AttributeValue_t dest; // [esp+48h] [ebp-58h] BYREF
  CBaseAnimSetAttributeSliderPanel *v28; // [esp+70h] [ebp-30h]
  int v29; // [esp+74h] [ebp-2Ch] BYREF
  int v30; // [esp+78h] [ebp-28h] BYREF
  CBaseAnimationSetControl *v31; // [esp+7Ch] [ebp-24h]
  CExpressionCalculator *BufferType; // [esp+80h] [ebp-20h] BYREF
  CBaseAnimSetPresetFaderPanel *v33; // [esp+84h] [ebp-1Ch]
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+88h] [ebp-18h] BYREF
  int y; // [esp+8Ch] [ebp-14h]
  int x; // [esp+90h] [ebp-10h]
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *values; // [esp+94h] [ebp-Ch]
  CDmElement *pControl; // [esp+98h] [ebp-8h]
  int i; // [esp+9Ch] [ebp-4h]

  v1 = this;
  m_pEditor = this->m_pEditor;
  v31 = v1;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: m_pEditor);
  v28 = AttributeSlider;
  if ( AttributeSlider == nullptr )
    return;
  flBalanceFilter = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: AttributeSlider);
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: v1->m_pEditor);
  v33 = PresetFader;
  if ( PresetFader == nullptr )
    return;
  pAttributeSlider = nullptr;
  *(float *)&y = 0.0;
  LOWORD(x) = 0;
  values = nullptr;
  pControl = nullptr;
  CBaseAnimSetPresetFaderPanel::GetPreviewFader(this: PresetFader, fader: (FaderPreview_t *)&pAttributeSlider);
  HIBYTE(i) = pAttributeSlider != nullptr
           && (CUtlString::Length(this: &v1->m_PreviousPresetSlider) == 0
            || (v22 = pAttributeSlider,
                v5 = CUtlString::Get(this: &v1->m_PreviousPresetSlider),
                _V_stricmp(s1: v5, s2: (const char *)v22) != 0));
  v7 = (*((_BYTE *)v1 + 104) & 2) != 0;
  v8 = BYTE1(x) != v7;
  BYTE2(i) = (_BYTE)x != (*((_BYTE *)v1 + 104) & 1);
  v6 = BYTE2(i);
  if ( HIWORD(i) != 0 || (BYTE1(i) = 0, BYTE1(x) != v7) )
    BYTE1(i) = 1;
  LOBYTE(i) = *(float *)&y != v1->m_flPreviousPresetAmount;
  if ( BYTE1(x) != 0 || (_BYTE)x != 0 && BYTE2(i) != 0 || BYTE1(i) != 0 )
  {
    CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(this: v33, values);
    if ( BYTE1(x) != 0 && v8 )
    {
      v6 = BYTE2(i);
      v9 = 1;
      goto LABEL_20;
    }
    v6 = BYTE2(i);
  }
  v9 = 0;
LABEL_20:
  v10 = (_BYTE)x != 0 && v6 != 0;
  if ( HIBYTE(i) != 0 || v9 != 0 || v10 )
    v10 = true;
  *((_BYTE *)v1 + 104) ^= (*((_BYTE *)v1 + 104) ^ (4 * v10)) & 4;
  CUtlString::operator=(this: &v1->m_PreviousPresetSlider, src: (char *)pAttributeSlider);
  v11 = x & 1 | *((_BYTE *)v1 + 104) & 0xFC | (2 * (BYTE1(x) & 1));
  v1->m_flPreviousPresetAmount = *(float *)&y;
  *((_BYTE *)v1 + 104) = v11;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v12 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), BYTE2(i) = 0, v12) )
  {
    BYTE2(i) = 1;
  }
  v13 = nullptr;
  m_Size = v28->m_SliderList.m_Size;
  v33 = nullptr;
  if ( m_Size > 0 )
  {
    do
    {
      v14 = v28->m_SliderList.m_Memory.m_pMemory[(_DWORD)v13];
      if ( v14->IsVisible(this: v14) )
      {
        BufferType = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: v14->m_hControl.m_handle);
        if ( BufferType != nullptr )
        {
          v15 = *((_BYTE *)v14 + 656) & 1;
          v26 = v15;
          if ( vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) == v14
            && v14->m_SliderMode != SLIDER_MODE_DRAG_VALUE
            && BYTE2(i) != 0 )
          {
            memset(&dest, 0, 24);
            dest.m_Quaternion = quat_identity;
            if ( v15 )
            {
              CAttributeSlider::GetValue(this: v14, type: ANIM_CONTROL_COUNT, out: &dest.m_Vector);
              CAttributeSlider::GetValue(this: v14, type: ANIM_CONTROL_TXFORM_ORIENTATION, out: &dest.m_Quaternion);
            }
            else
            {
              g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &v30, a3: &v29);
              vgui::Panel::ScreenToLocal(this: v14, x: &v30, y: &v29);
              dest.m_pValue[0] = CAttributeSlider::EstimateValueAtPos(this: v14, nLocalX: v30, nLocalY: v29);
              dest.m_pValue[2] = dest.m_pValue[0];
              dest.m_pValue[1] = dest.m_pValue[0];
            }
            CAttributeSlider::SetPreview(this: v14, value: &dest, full: &dest);
          }
          else if ( values != nullptr )
          {
            if ( (_BYTE)x != 0 || (HIBYTE(i) = 0, BYTE1(x) == 0) )
              HIBYTE(i) = 1;
            if ( BYTE1(i) != 0 || (_BYTE)x != 0 )
            {
              BufferType = (CExpressionCalculator *)CCodecBuffer_Block::GetBufferType(this: BufferType);
              v16 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Find(
                      this: values,
                      key: (DmElementHandle_t *)&BufferType);
              if ( v16 == 0xFFFF )
                Value = (AnimationControlAttributes_t *)CAttributeSlider::GetValue(this: v14);
              else
                Value = &values->m_Tree.m_Elements.m_pMemory[v16].m_Data.elem;
              v18 = CAttributeSlider::GetValue(this: v14);
              memset(&dest, 0, 24);
              dest.m_Quaternion = quat_identity;
              v21 = Value;
              v19 = v26;
              v20 = v18;
              BlendValues(bTransform: v26, pResult: &dest, src: v18, dest: v21, flBlend: 1.0, flBalanceFilter);
              if ( HIBYTE(i) != 0 )
              {
                CAttributeSlider::SetPreview(this: v14, value: &dest, full: &dest);
              }
              else
              {
                memset(&pResult, 0, 24);
                pResult.m_Quaternion = quat_identity;
                BlendValues(bTransform: v19, &pResult, src: v20, &dest, flBlend: *(float *)&y, flBalanceFilter: 0.5);
                CAttributeSlider::SetPreview(this: v14, value: &pResult, full: &dest);
              }
              v1 = v31;
            }
            if ( (_BYTE)i != 0 || (_WORD)x != 0 )
              CAttributeSlider::UpdateFaderAmount(this: v14, flAmount: *(float *)&y);
          }
        }
      }
      v13 = (CBaseAnimSetPresetFaderPanel *)((char *)&v33->__vftable + 1);
      v33 = v13;
    }
    while ( (int)v13 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10489BE0
// Name: public: void CBaseAnimationSetControl::ApplyPreset(float,class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyPreset(
        CBaseAnimationSetControl *this,
        float flScale,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *values)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  float w; // ebx
  float v5; // eax
  float z; // edi
  int v7; // esi
  CExpressionCalculator *v8; // eax
  unsigned __int16 v9; // ax
  AnimationControlAttributes_t *Value; // ebx
  const AttributeValue_t *v11; // eax
  const AttributeValue_t *v12; // edi
  float BalanceSliderValue; // [esp+4h] [ebp-50h]
  float flBlend[5]; // [esp+14h] [ebp-40h] BYREF
  AttributeValue_t blend; // [esp+28h] [ebp-2Ch] BYREF
  int c; // [esp+50h] [ebp-4h]

  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  w = *(float *)&AttributeSlider;
  LODWORD(blend.m_Quaternion.w) = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    v5 = *(float *)&AttributeSlider->m_SliderList.m_Size;
    z = 0.0;
    HIBYTE(c) = 0;
    blend.m_Vector.z = v5;
    blend.m_Quaternion.z = 0.0;
    if ( SLODWORD(v5) > 0 )
    {
      do
      {
        v7 = *(_DWORD *)(*(_DWORD *)(LODWORD(w) + 396) + 4 * LODWORD(z));
        if ( v7 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 136))(a1: v7) != 0 )
        {
          v8 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v7 + 416));
          LODWORD(blend.m_Quaternion.y) = CCodecBuffer_Block::GetBufferType(this: v8);
          v9 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Find(
                 this: values,
                 key: (DmElementHandle_t *)&blend.m_Quaternion.y);
          if ( v9 == 0xFFFF )
            Value = (AnimationControlAttributes_t *)CAttributeSlider::GetValue(this: (CAttributeSlider *)v7);
          else
            Value = &values->m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
          v11 = CAttributeSlider::GetValue(this: (CAttributeSlider *)v7);
          memset(flBlend, 0, sizeof(flBlend));
          blend.m_pValue[0] = 0.0;
          *(Quaternion *)&blend.m_pValue[1] = quat_identity;
          v12 = v11;
          LOBYTE(blend.m_Quaternion.x) = *(_BYTE *)(v7 + 656) & 1;
          BalanceSliderValue = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: (CBaseAnimSetAttributeSliderPanel *)LODWORD(blend.m_Quaternion.w));
          BlendValues(
            bTransform: SLOBYTE(blend.m_Quaternion.x),
            pResult: (AttributeValue_t *)flBlend,
            src: v12,
            dest: Value,
            flBlend: flScale,
            flBalanceFilter: BalanceSliderValue);
          CAttributeSlider::SetValue(this: (CAttributeSlider *)v7, value: (const AttributeValue_t *)flBlend);
          w = blend.m_Quaternion.w;
          z = blend.m_Quaternion.z;
          HIBYTE(c) = 1;
        }
        ++LODWORD(z);
        blend.m_Quaternion.z = z;
      }
      while ( SLODWORD(z) < SLODWORD(blend.m_Vector.z) );
      if ( HIBYTE(c) != 0 )
        (*(void (__cdecl **)(float, const char *))(*(_DWORD *)LODWORD(w) + 972))(
          a1: COERCE_FLOAT(LODWORD(w)),
          a2: "ApplyPreset\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10489D50
// Name: protected: void CBaseAnimationSetControl::ApplySliderValueWithDominance(class CAttributeSlider __near *,int,float,float,class CDmElement __near *,bool,bool,bool __near &,enum AnimationControlType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplySliderValueWithDominance(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        int si,
        float flDomStart,
        float flDomValue,
        CDmElement *pControl,
        float bUsePreviewValue,
        char bForce,
        bool *valuesChanged,
        float type,
        bool *pChannelAttrName,
        char *pValueAttrName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v13; // ebx
  CDmeChannel *Value; // eax
  CDmeChannel *v15; // esi
  ChannelMode_t Mode; // eax
  char v17; // cl
  DmeTime_t *CurrentTime; // eax
  char v19; // bl
  AnimationControlType_t v20; // esi
  double Preview; // st7
  float v23; // xmm1_4
  CDmaVar<float> *v24; // eax
  CDmAttribute *v25; // esi
  float m_Storage; // xmm0_4
  float v28; // [esp+1Ch] [ebp+8h]

  Attribute = CDmElement::FindAttribute(this: pControl, pAttributeName: pValueAttrName);
  v13 = Attribute;
  pValueAttrName = (char *)Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 3 )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: (const char *)pChannelAttrName);
  v15 = Value;
  if ( Value != nullptr )
  {
    Mode = CDmeChannel::GetMode(this: Value);
    if ( Mode != CM_PASS && Mode != CM_RECORD )
    {
      v17 = 0;
      goto LABEL_9;
    }
  }
  else
  {
    Mode = CM_PASS;
  }
  v17 = 1;
LABEL_9:
  if ( Mode == CM_PLAY )
  {
    if ( pSlider->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
    {
      bUsePreviewValue = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue")->m_Storage;
      CurrentTime = CDmeChannel::GetCurrentTime(this: v15, result: (DmeTime_t *)&bForce);
      if ( CDmeChannel::GetPlaybackValueAtTime<float>(
             this: v15,
             a2: (int)v13,
             a3: (int)pControl,
             time: (DmeTime_t)CurrentTime->m_tms,
             value: &bUsePreviewValue) != 0 )
        CDmAttribute::SetValue<float>(this: v13, value: &bUsePreviewValue);
      else
        bUsePreviewValue = CDmAttribute::GetValue<float>(this: v13)->m_Storage;
      CAttributeSlider::SetValue(this: pSlider, type: SLODWORD(type), flValue: bUsePreviewValue);
    }
  }
  else if ( v17 != 0 )
  {
    v19 = LOBYTE(bUsePreviewValue);
    v20 = LODWORD(type);
    if ( LOBYTE(bUsePreviewValue) != 0 )
      Preview = CAttributeSlider::GetPreview(this: pSlider, type: SLODWORD(type));
    else
      Preview = CAttributeSlider::GetValue(this: pSlider, type: SLODWORD(type));
    bUsePreviewValue = Preview;
    if ( this->m_nDominantSlider >= 0 && pSlider->IsVisible(this: pSlider) && v19 == 0 && this->m_nDominantSlider != si )
    {
      type = this->m_DominantSliderStartValues.m_Memory.m_pMemory[si].m_pValue[v20];
      if ( (float)(1.0 - flDomStart) <= 0.0 )
      {
        v28 = 0.0;
      }
      else
      {
        v23 = flDomValue - flDomStart;
        if ( (float)(flDomValue - flDomStart) < 0.0 )
          v23 = 0.0;
        v28 = v23 / (float)(1.0 - flDomStart);
      }
      v24 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue");
      bUsePreviewValue = (float)((float)(1.0 - v28) * type) + (float)(v24->m_Storage * v28);
      CAttributeSlider::SetValue(this: pSlider, type: v20, flValue: bUsePreviewValue);
    }
    v25 = (CDmAttribute *)pValueAttrName;
    m_Storage = CDmAttribute::GetValue<float>(this: (CDmAttribute *)pValueAttrName)->m_Storage;
    if ( m_Storage != bUsePreviewValue || bForce != 0 )
    {
      *valuesChanged = true;
      CDmAttribute::SetValue<float>(this: v25, value: &bUsePreviewValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10489F60
// Name: public: bool CBaseAnimationSetControl::ApplySliderValues(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::ApplySliderValues(CBaseAnimationSetControl *this, bool bForce)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // esi
  int m_Size; // ecx
  int v6; // eax
  CAttributeSlider *v7; // esi
  vgui::BuildGroup *v8; // edi
  bool v9; // al
  bool v10; // zf
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  bool v12; // al
  bool v13; // [esp+34h] [ebp-20h]
  int v14; // [esp+38h] [ebp-1Ch]
  CBaseAnimSetAttributeSliderPanel *v15; // [esp+3Ch] [ebp-18h]
  __int64 v16; // [esp+40h] [ebp-14h] BYREF
  int v17; // [esp+48h] [ebp-Ch]
  bool v18[4]; // [esp+4Eh] [ebp-6h]
  char v19; // [esp+52h] [ebp-2h]
  bool var1[5]; // [esp+53h] [ebp-1h] BYREF

  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  v15 = AttributeSlider;
  if ( AttributeSlider == nullptr )
    return false;
  if ( !bForce )
    bForce = *((_BYTE *)this + 104) & 1;
  v13 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v16 = 0;
  CBaseAnimationSetControl::GetDominantSliderValues(this, flDomStart: (float *)&v16, flDomValue: (float *)&v16 + 1);
  m_Size = AttributeSlider->m_SliderList.m_Size;
  v6 = 0;
  var1[0] = false;
  v14 = m_Size;
  v17 = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v7 = AttributeSlider->m_SliderList.m_Memory.m_pMemory[v6];
      if ( v7 != nullptr && v7->IsVisible(this: v7) )
      {
        v8 = (vgui::BuildGroup *)g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_hControl.m_handle);
        if ( v8 != nullptr )
        {
          if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
            || (v9 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), v19 = 0, v9) )
          {
            v19 = 1;
          }
          if ( vgui::PHandle::Get(this: &this->m_ActiveAttributeSlider) != v7
            || v7->m_SliderMode == SLIDER_MODE_DRAG_VALUE
            || (v10 = v19 == 0, v19 = 1, v10) )
          {
            v19 = 0;
          }
          PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
          v12 = CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(this: PresetFader) != nullptr;
          v18[0] = (*((_BYTE *)this + 104) & 2) != 0 || v19 != 0 || bForce && v12;
          if ( ((unsigned __int8 (__thiscall *)(vgui::BuildGroup *, CUtlSymbolLarge::<unnamed_type_u>))v8->SaveControlSettings)(
                 a1: v8,
                 a2: CDmeTransformControl::m_classType.u) != 0 )
          {
            if ( (*((_BYTE *)v7 + 656) & 2) != 0 )
              CBaseAnimationSetControl::ApplyTransformSliderValue<Quaternion>(
                this,
                pSlider: v7,
                pTranformControl: v8,
                bUsePreviewValue: *(DmeTime_t *)v18,
                bForce,
                valuesChanged: var1,
                type: ANIM_CONTROL_TXFORM_ORIENTATION);
            else
              CBaseAnimationSetControl::ApplyTransformSliderValue<Vector>(
                this,
                pSlider: v7,
                pTranformControl: v8,
                bUsePreviewValue: *(DmeTime_t *)v18,
                bForce,
                valuesChanged: var1,
                type: ANIM_CONTROL_COUNT);
          }
          else if ( CDmElement::HasAttribute(this: (CDmElement *)v8, pAttributeName: "rightValue", type: AT_UNKNOWN) )
          {
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v17,
              flDomStart: *(float *)&v16,
              flDomValue: *((float *)&v16 + 1),
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)v18,
              bForce,
              valuesChanged: var1,
              type: COERCE_FLOAT(2),
              pChannelAttrName: (bool *)"leftvaluechannel",
              pValueAttrName: "leftValue");
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v17,
              flDomStart: *(float *)&v16,
              flDomValue: *((float *)&v16 + 1),
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)v18,
              bForce,
              valuesChanged: var1,
              type: COERCE_FLOAT(1),
              pChannelAttrName: (bool *)"rightvaluechannel",
              pValueAttrName: "rightValue");
          }
          else
          {
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v17,
              flDomStart: *(float *)&v16,
              flDomValue: *((float *)&v16 + 1),
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)v18,
              bForce,
              valuesChanged: var1,
              type: 0.0,
              pChannelAttrName: (bool *)"channel",
              pValueAttrName: "value");
          }
        }
      }
      v6 = v17 + 1;
      v17 = v6;
      if ( v6 >= v14 )
        break;
      AttributeSlider = v15;
    }
  }
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: v13);
  return var1[0];
}

//------------------------------------------------------------------------------
// Address: 0x1048A200
// Name: protected: void CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(
        CBaseAnimationSetControl *this,
        int nCount)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_crossfadePresetControlValues; // esi
  int m_Size; // ecx
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  vgui::TreeNode *v7; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax
  int nCounta; // [esp+14h] [ebp+8h]

  p_m_crossfadePresetControlValues = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_crossfadePresetControlValues;
  this->m_crossfadePresetControlValues.m_Size = 0;
  m_Size = this->m_crossfadePresetControlValues.m_Size;
  if ( m_Size < nCount )
  {
    nCounta = nCount - m_Size;
    do
    {
      v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
             a1: g_pDataModel,
             a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
             a3: "procedural preset control value",
             a4: DMFILEID_INVALID,
             a5: nullptr);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
        v7 = (vgui::TreeNode *)v6;
      else
        v7 = nullptr;
      m_pMemory = p_m_crossfadePresetControlValues[1].m_pMemory;
      m_nAllocationCount = p_m_crossfadePresetControlValues->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: p_m_crossfadePresetControlValues,
          num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_crossfadePresetControlValues[1].m_pMemory;
      v10 = p_m_crossfadePresetControlValues->m_pMemory;
      v11 = (char *)p_m_crossfadePresetControlValues[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_crossfadePresetControlValues[1].m_nAllocationCount = (int)p_m_crossfadePresetControlValues->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v10[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v10[(_DWORD)m_pMemory],
          count: 4 * v11);
      v12 = &p_m_crossfadePresetControlValues->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = v7;
      --nCounta;
    }
    while ( nCounta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048A2E0
// Name: void AddKeysToPreset<class Vector>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<Vector>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  const Vector *v18; // eax
  const Vector *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  const Vector *v22; // eax
  Vector v; // [esp+Ch] [ebp-34h] BYREF
  CDmrArray<Vector> values; // [esp+18h] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+20h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+28h] [ebp-18h] BYREF
  int nKeys; // [esp+2Ch] [ebp-14h]
  DmeTime_t src; // [esp+30h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+34h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+38h] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+3Ch] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<Vector> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: "channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (vgui::PageTab *const *)&pPreset);
    CDmeChannel::GetInputValue<Vector>(this: Value, value: &v);
    CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(this: &values, src: &v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: &Referring->CDmeClip, result: &tLocalStart, t: tStart, bClamp: nullptr);
  CDmeClip::ToChildMediaTime(this: &Referring->CDmeClip, result: &tLocalEnd, t: tEnd, bClamp: nullptr);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  nKeys = (int)CDmeLog::GetKeyCount(this: v14);
  if ( nKeys <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          (vgui::PageTab *const *)&src);
        v18 = CDmeTypedLog<Vector>::GetValue(this: v14, time: tLocalStart);
        CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: &Referring->CDmeClip, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        (vgui::PageTab *const *)&src);
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= nKeys )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (vgui::PageTab *const *)&pPreset);
    v22 = CDmeTypedLog<Vector>::GetValue(this: v14, time: tLocalEnd);
    CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
      this: &values,
      src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048A510
// Name: void AddKeysToPreset<class Quaternion>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<Quaternion>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  const Quaternion *v18; // eax
  const Quaternion *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  const Quaternion *v22; // eax
  Quaternion v; // [esp+Ch] [ebp-38h] BYREF
  CDmrArray<Quaternion> values; // [esp+1Ch] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+24h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+2Ch] [ebp-18h] BYREF
  int nKeys; // [esp+30h] [ebp-14h]
  DmeTime_t src; // [esp+34h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+38h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+3Ch] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+40h] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<Quaternion> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Quaternion>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: "channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (vgui::PageTab *const *)&pPreset);
    CDmeChannel::GetInputValue<Quaternion>(this: Value, value: &v);
    CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
      this: &values,
      src: &v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: &Referring->CDmeClip, result: &tLocalStart, t: tStart, bClamp: nullptr);
  CDmeClip::ToChildMediaTime(this: &Referring->CDmeClip, result: &tLocalEnd, t: tEnd, bClamp: nullptr);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  nKeys = (int)CDmeLog::GetKeyCount(this: v14);
  if ( nKeys <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          (vgui::PageTab *const *)&src);
        v18 = CDmeTypedLog<Quaternion>::GetValue(this: v14, time: tLocalStart);
        CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: &Referring->CDmeClip, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        (vgui::PageTab *const *)&src);
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= nKeys )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (vgui::PageTab *const *)&pPreset);
    v22 = CDmeTypedLog<Quaternion>::GetValue(this: v14, time: tLocalEnd);
    CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
      this: &values,
      src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048A740
// Name: void AddKeysToPreset<float>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<float>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<float> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  float *v18; // eax
  float *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  float *v22; // eax
  CDmrArray<float> values; // [esp+Ch] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+14h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-18h] BYREF
  CDmAttribute *v; // [esp+20h] [ebp-14h] BYREF
  DmeTime_t src; // [esp+24h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+28h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+2Ch] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+30h] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<float> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: "channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (vgui::PageTab *const *)&pPreset);
    CDmeChannel::GetInputValue<float>(this: Value, value: (float *)&v);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
      this: &values,
      src: (const float *)&v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: &Referring->CDmeClip, result: &tLocalStart, t: tStart, bClamp: nullptr);
  CDmeClip::ToChildMediaTime(this: &Referring->CDmeClip, result: &tLocalEnd, t: tEnd, bClamp: nullptr);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  v = CDmeLog::GetKeyCount(this: v14);
  if ( (int)v <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          (vgui::PageTab *const *)&src);
        v18 = CDmeTypedLog<float>::GetValue(this: v14, a2: (int)Referring, a3: v16, time: tLocalStart);
        CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: &Referring->CDmeClip, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        (vgui::PageTab *const *)&src);
      KeyValue = CDmeTypedLog<float>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= (int)v )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (vgui::PageTab *const *)&pPreset);
    v22 = CDmeTypedLog<float>::GetValue(this: v14, a2: (int)Referring, a3: v16, time: tLocalEnd);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(this: &values, src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048A970
// Name: public: virtual void CBaseAnimationSetControl::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::OnControlsAddedOrRemoved(CBaseAnimationSetControl *this)
{
  int m_Head; // edi
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *p_m_SelectionHistory; // esi
  unsigned __int16 v3; // bx
  const CDmElement *v4; // eax
  CDmeControlGroup *GroupContainingControl; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  SelectionInfo_t *psi; // [esp+4h] [ebp-Ch]
  CBaseAnimationSetControl *v8; // [esp+8h] [ebp-8h]
  bool bSelectionChanged; // [esp+Fh] [ebp-1h]

  m_Head = this->m_SelectionHistory.m_Head;
  v8 = this;
  this->m_nDominantSlider = -1;
  bSelectionChanged = false;
  if ( m_Head != 0xFFFF )
  {
    p_m_SelectionHistory = &this->m_SelectionHistory;
    do
    {
      psi = p_m_SelectionHistory->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element;
      v3 = m_Head;
      m_Head = p_m_SelectionHistory->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: psi->m_hControl.m_handle);
      if ( v4 != nullptr )
      {
        if ( v8->m_bShowHiddenControls )
          continue;
        GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl: v4);
        if ( GroupContainingControl != nullptr && CDmeControlGroup::IsVisible(this: GroupContainingControl) )
          continue;
      }
      psi->m_nComponentFlags = TRANSFORM_COMPONENT_NONE;
      CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::Unlink(
        this: p_m_SelectionHistory,
        elem: v3);
      p_m_SelectionHistory->m_Memory.m_pMemory[v3].m_Next = p_m_SelectionHistory->m_FirstFree;
      p_m_SelectionHistory->m_FirstFree = v3;
      bSelectionChanged = true;
    }
    while ( m_Head != 0xFFFF );
    if ( bSelectionChanged
      && ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      v8->FireControlSelectionChangedListeners(this: v8);
    }
    this = v8;
  }
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this: PresetFader, bChanged: false);
}

//------------------------------------------------------------------------------
// Address: 0x1048AA60
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmeAnimationSet __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(CBaseAnimationSetControl *this, CDmeAnimationSet *pAnimSet)
{
  CDmeControlGroup *RootControlGroup; // eax

  if ( pAnimSet == nullptr )
    return 0;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  return CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: RootControlGroup);
}

//------------------------------------------------------------------------------
// Address: 0x1048AA90
// Name: void SetPresetFromControlChannels(class CDmePreset __near *,class CDmElement const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPresetFromControlChannels(
        CDmePreset *pPreset,
        CDmElement *pControl,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    AddKeysToPreset<Vector>(
      pPreset,
      pValuesAttrName: "valuePositions",
      pTimesAttrName: "timePositions",
      pControl,
      pChannelAttrName: "positionChannel",
      tHead,
      tStart,
      tEnd);
    AddKeysToPreset<Quaternion>(
      pPreset,
      pValuesAttrName: "valueOrientations",
      pTimesAttrName: "timeOrientations",
      pControl,
      pChannelAttrName: "orientationChannel",
      tHead,
      tStart,
      tEnd);
  }
  if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
  {
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "leftValues",
      pTimesAttrName: "leftTimes",
      pControl,
      pChannelAttrName: "leftvaluechannel",
      tHead,
      tStart,
      tEnd);
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "rightValues",
      pTimesAttrName: "rightTimes",
      pControl,
      pChannelAttrName: "rightvaluechannel",
      tHead,
      tStart,
      tEnd);
  }
  else
  {
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "values",
      pTimesAttrName: "times",
      pControl,
      pChannelAttrName: "channel",
      tHead,
      tStart,
      tEnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048AB80
// Name: protected: void CBaseAnimationSetControl::AddPreset(class CDmeAnimationSet __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddPreset(
        CBaseAnimationSetControl *this,
        CDmeAnimationSet *pAnimSet,
        const char *pPresetGroupName,
        const char *pPresetName,
        int bAnimated)
{
  CDmePresetGroup *v6; // eax
  const char *v7; // ebx
  CDmePresetGroup *v8; // esi
  CDmePreset *v9; // esi
  void (__thiscall *GetAnimatedPresetTimeParameters)(CBaseAnimationSetControl *, DmeTime_t *, DmeTime_t *, DmeTime_t *); // edx
  CDmAttribute *Attribute; // eax
  int i; // eax
  int v13; // esi
  SelectionInfo_t *m_Element; // ebx
  int BufferType; // eax
  CDmElement *v16; // eax
  int j; // eax
  int v18; // esi
  SelectionInfo_t *v19; // ebx
  int v20; // eax
  CDmeTransformControl *v21; // eax
  CDmePreset *pPreset; // [esp+Ch] [ebp-8h]
  DmeTime_t tHead; // [esp+10h] [ebp-4h] BYREF

  v6 = CDmeAnimationSet::FindOrAddPresetGroup(this: pAnimSet, pGroupName: pPresetGroupName);
  v7 = pPresetName;
  v8 = v6;
  if ( CDmePresetGroup::FindPreset(this: v6, pPresetName) == nullptr )
  {
    v9 = CDmePresetGroup::FindOrAddPreset(this: v8, pPresetName: v7);
    pPreset = v9;
    if ( (_BYTE)bAnimated != 0 )
    {
      GetAnimatedPresetTimeParameters = this->GetAnimatedPresetTimeParameters;
      tHead.m_tms = 0x80000000;
      pPresetName = (const char *)0x80000000;
      pPresetGroupName = (const char *)0x80000000;
      GetAnimatedPresetTimeParameters(
        this,
        a2: &tHead,
        a3: (DmeTime_t *)&pPresetName,
        a4: (DmeTime_t *)&pPresetGroupName);
      HIBYTE(bAnimated) = 1;
      Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "animated");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v9, pAttributeName: "animated", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&bAnimated + 3);
      }
      for ( i = this->m_SelectionHistory.m_Head; i != 0xFFFF; i = this->m_SelectionHistory.m_Memory.m_pMemory[v13].m_Next )
      {
        v13 = (unsigned __int16)i;
        m_Element = this->m_SelectionHistory.m_Memory.m_pMemory[v13].m_Element;
        if ( pAnimSet != nullptr )
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
        else
          BufferType = -1;
        if ( m_Element->m_hAnimSet.m_handle == BufferType )
        {
          v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Element->m_hControl.m_handle);
          SetPresetFromControlChannels(
            pPreset,
            pControl: v16,
            tHead,
            tStart: (DmeTime_t)pPresetName,
            tEnd: (DmeTime_t)pPresetGroupName);
        }
      }
    }
    else
    {
      for ( j = this->m_SelectionHistory.m_Head; j != 0xFFFF; j = this->m_SelectionHistory.m_Memory.m_pMemory[v18].m_Next )
      {
        v18 = (unsigned __int16)j;
        v19 = this->m_SelectionHistory.m_Memory.m_pMemory[v18].m_Element;
        if ( pAnimSet != nullptr )
          v20 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
        else
          v20 = -1;
        if ( v19->m_hAnimSet.m_handle == v20 )
        {
          v21 = (CDmeTransformControl *)g_pDataModel->GetElement(this: g_pDataModel, a2: v19->m_hControl.m_handle);
          SetPresetFromControl(pPreset, pControl: v21);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048AD00
// Name: public: void CBaseAnimationSetControl::UpdateDominantSliderStartValues(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdateDominantSliderStartValues(
        CBaseAnimationSetControl *this,
        bool restoreSliderValues)
{
  CBaseAnimationSetControl *v2; // esi
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  CBaseAnimSetAttributeSliderPanel *v4; // edi
  int m_Size; // ebx
  int v6; // eax
  int v7; // ebx
  CAttributeSlider *v8; // edi
  AttributeValue_t *v9; // esi
  int nSliders; // [esp+8h] [ebp-10h]
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v2 = this;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  v4 = AttributeSlider;
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    m_Size = AttributeSlider->m_SliderList.m_Size;
    nSliders = m_Size;
    if ( v2->m_DominantSliderStartValues.m_Size == m_Size
      || (v2->m_DominantSliderStartValues.m_Size = 0,
          CUtlVector<AttributeValue_t,CUtlMemory<AttributeValue_t,int>>::InsertMultipleBefore(
            this: &v2->m_DominantSliderStartValues,
            elem: 0,
            num: m_Size),
          !restoreSliderValues) )
    {
      v6 = 0;
      i = 0;
      if ( m_Size > 0 )
      {
        v7 = 0;
        while ( 1 )
        {
          v8 = v4->m_SliderList.m_Memory.m_pMemory[v6];
          if ( v8 != nullptr && v8->IsVisible(this: v8) )
          {
            if ( restoreSliderValues )
            {
              if ( v8->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
                CAttributeSlider::SetValue(this: v8, value: &v2->m_DominantSliderStartValues.m_Memory.m_pMemory[v7]);
            }
            else
            {
              v9 = &v2->m_DominantSliderStartValues.m_Memory.m_pMemory[v7];
              *v9 = *CAttributeSlider::GetValue(this: v8);
              v2 = this;
            }
          }
          v6 = i + 1;
          ++v7;
          i = v6;
          if ( v6 >= nSliders )
            break;
          v4 = pAttributeSlider;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048AF40
// Name: public: bool CBaseAnimationSetControl::SelectControl(class CDmElement const __near *,enum ESelectionMode,enum TransformComponent_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimationSetControl::SelectControl(
        CBaseAnimationSetControl *this,
        const CDmElement *pControl,
        ESelectionMode selectionMode,
        TransformComponent_t nComponentFlags,
        bool bExpandTree)
{
  CDmeControlGroup *GroupContainingControl; // eax
  SelectionInfo_t *v8; // eax
  SelectionInfo_t *v9; // esi
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v11; // ecx
  SelectionInfo_t *psi; // [esp+Ch] [ebp-4h] BYREF

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  if ( pControl != nullptr )
  {
    if ( (this->m_bShowHiddenControls
       || (GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl)) != nullptr
       && CDmeControlGroup::IsVisible(this: GroupContainingControl)
       || selectionMode == SELECTION_REMOVE)
      && (v8 = this->FindSelectionInfoForControl(this, a2: pControl), v9 = v8, psi = v8, v8 != nullptr) )
    {
      if ( selectionMode != SELECTION_SET )
      {
        if ( v8->m_nComponentFlags != TRANSFORM_COMPONENT_NONE )
          CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::FindAndRemove(
            this: &this->m_SelectionHistory,
            src: &psi);
        switch ( selectionMode )
        {
          case SELECTION_ADD:
            v9->m_nComponentFlags |= nComponentFlags;
            break;
          case SELECTION_REMOVE:
            v9->m_nComponentFlags &= ~nComponentFlags;
            break;
          case SELECTION_TOGGLE:
            v9->m_nComponentFlags ^= nComponentFlags;
            break;
          default:
            break;
        }
      }
      else
      {
        CBaseAnimationSetControl::ClearSelection(this);
        v9->m_nComponentFlags = nComponentFlags;
      }
      if ( v9->m_nComponentFlags != TRANSFORM_COMPONENT_NONE )
      {
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AddToTail(
          this: &this->m_SelectionHistory,
          src: &psi);
        if ( bExpandTree )
        {
          for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
          {
            v11 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
            v11->ExpandTreeToControl(this: v11, a2: pControl, a3: nComponentFlags);
          }
        }
      }
      if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
        && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
      {
        this->FireControlSelectionChangedListeners(this);
      }
      return 1;
    }
    else
    {
      if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
        && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
      {
        this->FireControlSelectionChangedListeners(this);
      }
      return 0;
    }
  }
  else
  {
    if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      this->FireControlSelectionChangedListeners(this);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048B080
// Name: public: void CBaseAnimationSetControl::SelectControlGroup(class CDmeControlGroup __near *,enum ESelectionMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SelectControlGroup(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pGroup,
        ESelectionMode selectionMode)
{
  CBaseAnimationSetControl *v3; // edi
  int v4; // esi
  CDmElement **m_pMemory; // eax
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > list; // [esp+Ch] [ebp-18h] BYREF
  CBaseAnimationSetControl *v8; // [esp+20h] [ebp-4h]

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  v3 = this;
  v8 = this;
  if ( pGroup != nullptr )
  {
    list.m_Memory.m_pMemory = nullptr;
    list.m_Memory.m_nAllocationCount = 32;
    list.m_Memory.m_nGrowSize = 0;
    list.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
    list.m_Size = 0;
    list.m_pElements = list.m_Memory.m_pMemory;
    CDmeControlGroup::GetControlsInGroup(this: pGroup, controlList: &list, recursive: true);
    v4 = list.m_Size - 1;
    if ( list.m_Size - 1 >= 0 )
    {
      do
      {
        if ( CBaseAnimationSetControl::SelectControl(
               this: v8,
               pControl: list.m_Memory.m_pMemory[v4],
               selectionMode,
               nComponentFlags: TRANSFORM_COMPONENT_ALL,
               bExpandTree: false) != 0
          && selectionMode == SELECTION_SET )
        {
          selectionMode = SELECTION_ADD;
        }
        --v4;
      }
      while ( v4 >= 0 );
      v3 = v8;
    }
    m_pMemory = list.m_Memory.m_pMemory;
    list.m_Size = 0;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( list.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    list.m_pElements = m_pMemory;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      v3->FireControlSelectionChangedListeners(this: v3);
    }
  }
  else if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
         && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    this->FireControlSelectionChangedListeners(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048B1B0
// Name: public: void CBaseAnimationSetControl::SelectAnimationSet(class CDmeAnimationSet __near *,enum ESelectionMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SelectAnimationSet(
        CBaseAnimationSetControl *this,
        CDmeAnimationSet *pAnimSet,
        int selectionMode)
{
  CDmeAnimationSet *v3; // ebx
  CBaseAnimationSetControl *v4; // esi
  CDmeControlGroup *RootControlGroup; // eax
  int v6; // ebx
  CDmeDag **m_pMemory; // eax
  CDmeDag *v8; // ecx
  CDmeTransformControl *TransformControl; // eax
  int v10; // eax
  int v11; // edi
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *p_m_SelectionHistory; // esi
  unsigned __int16 v13; // ax
  int v14; // ebx
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *v15; // eax
  ESelectionMode v16; // [esp-4h] [ebp-28h]
  CUtlVector<CDmeDag *,CUtlMemory<CDmeDag *,int> > rootDagNodes; // [esp+Ch] [ebp-18h] BYREF
  CBaseAnimationSetControl *v18; // [esp+20h] [ebp-4h]

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  v3 = pAnimSet;
  v4 = this;
  v16 = selectionMode;
  v18 = this;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  CBaseAnimationSetControl::SelectControlGroup(this: v4, pGroup: RootControlGroup, selectionMode: v16);
  memset(&rootDagNodes, 0, sizeof(rootDagNodes));
  CDmeAnimationSet::FindRootDagNodes(this: v3, rootDagNodeList: &rootDagNodes);
  v6 = 0;
  selectionMode = rootDagNodes.m_Size;
  if ( rootDagNodes.m_Size > 0 )
  {
    m_pMemory = rootDagNodes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = m_pMemory[v6];
      if ( v8 != nullptr )
      {
        TransformControl = CDmeDag::FindTransformControl(this: v8);
        v10 = (int)v4->FindSelectionInfoForControl(this: v4, a2: TransformControl);
        v11 = v10;
        pAnimSet = (CDmeAnimationSet *)v10;
        if ( v10 != 0 && *(_DWORD *)(v10 + 8) != 0 )
        {
          p_m_SelectionHistory = &v4->m_SelectionHistory;
          CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::FindAndRemove(
            this: p_m_SelectionHistory,
            src: (SelectionInfo_t **)&pAnimSet);
          v13 = CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal(
                  this: p_m_SelectionHistory,
                  multilist: false);
          v14 = v13;
          if ( v13 != 0xFFFF )
          {
            CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::LinkBefore(
              this: p_m_SelectionHistory,
              before: 0xFFFFu,
              elem: v13);
            v15 = &p_m_SelectionHistory->m_Memory.m_pMemory[v14];
            if ( v15 != nullptr )
              v15->m_Element = (SelectionInfo_t *)v11;
          }
          v4 = v18;
          break;
        }
        m_pMemory = rootDagNodes.m_Memory.m_pMemory;
      }
      if ( ++v6 >= selectionMode )
        goto LABEL_14;
    }
  }
  m_pMemory = rootDagNodes.m_Memory.m_pMemory;
LABEL_14:
  rootDagNodes.m_Size = 0;
  if ( rootDagNodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      rootDagNodes.m_Memory.m_pMemory = nullptr;
    }
    rootDagNodes.m_Memory.m_nAllocationCount = 0;
  }
  rootDagNodes.m_pElements = m_pMemory;
  if ( rootDagNodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      rootDagNodes.m_Memory.m_pMemory = nullptr;
    }
    rootDagNodes.m_Memory.m_nAllocationCount = 0;
  }
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    v4->FireControlSelectionChangedListeners(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048B2F0
// Name: public: void CBaseAnimationSetControl::AddPreset(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddPreset(
        CBaseAnimationSetControl *this,
        const char *pPresetGroupName,
        const char *pPresetName,
        int bAnimated)
{
  CDmeAnimationSet *i; // esi
  CDmeControlGroup *RootControlGroup; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Add Preset", a3: "Add Preset", a4: 0);
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Add Preset", a3: 0, a4: 256);
  traversal.m_pFilmClip = (CDmeFilmClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: i);
    if ( (unsigned int)CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: RootControlGroup) >= 2 )
      CBaseAnimationSetControl::AddPreset(this, pAnimSet: i, pPresetGroupName, pPresetName, bAnimated);
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1048B3D0
// Name: public: void CBaseAnimationSetControl::UpdatePreviewSliderTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdatePreviewSliderTimes(CBaseAnimationSetControl *this)
{
  CBaseAnimationSetControl *v1; // ebx
  CBaseAnimationSetEditor *m_pEditor; // ecx
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // esi
  bool v4; // al
  bool v5; // al
  unsigned int v6; // edi
  vgui::IPanel *v7; // esi
  vgui::IPanel_vtbl *v8; // ebx
  int v9; // eax
  bool v10; // al
  vgui::PHandle *p_m_ActiveAttributeSlider; // esi
  int SliderIndexForControl; // edi
  int m_nDominantSlider; // eax
  CAttributeSlider *v14; // ebx
  bool v15; // zf
  vgui::Panel *v16; // eax
  const CDmElement *v17; // eax
  CAttributeSlider *v18; // eax
  int my; // [esp+8h] [ebp-14h] BYREF
  int mx; // [esp+Ch] [ebp-10h] BYREF
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+10h] [ebp-Ch]
  CBaseAnimationSetControl *v22; // [esp+14h] [ebp-8h]
  bool shiftDown; // [esp+1Ah] [ebp-2h]
  bool ctrlDown; // [esp+1Bh] [ebp-1h]

  v1 = this;
  m_pEditor = this->m_pEditor;
  v22 = v1;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: m_pEditor);
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL), ctrlDown = false, v4) )
    {
      ctrlDown = true;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || (v5 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v5) )
    {
      shiftDown = true;
    }
    if ( ctrlDown )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
      if ( !vgui::Panel::IsWithin(this: AttributeSlider, x: mx, y: my) )
      {
        shiftDown = false;
        ctrlDown = false;
      }
      v6 = g_pVGuiInput->GetMouseOver(this: g_pVGuiInput);
      if ( v6 != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = pAttributeSlider->GetVPanel(this: pAttributeSlider);
        v10 = v8->HasParent(this: v7, a2: v6, a3: v9);
        v1 = v22;
        if ( !v10 )
        {
          shiftDown = false;
          ctrlDown = false;
        }
      }
    }
    LOBYTE(mx) = (*((_BYTE *)v1 + 104) & 2) != 0
              || vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr && shiftDown;
    LOBYTE(my) = (*((_BYTE *)v1 + 104) & 1) != 0
              || vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr
              && vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2;
    p_m_ActiveAttributeSlider = &v1->m_ActiveAttributeSlider;
    SliderIndexForControl = -1;
    if ( vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr
      && vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2 )
    {
      if ( ctrlDown
        || (m_nDominantSlider = v1->m_nDominantSlider) >= 0
        && (v14 = pAttributeSlider->m_SliderList.m_Memory.m_pMemory[m_nDominantSlider],
            v15 = v14 == vgui::PHandle::Get(this: p_m_ActiveAttributeSlider),
            v1 = v22,
            v15) )
      {
        v16 = vgui::PHandle::Get(this: p_m_ActiveAttributeSlider);
        v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: v16[1]._panelName.m_Storage.m_Memory.m_nGrowSize);
        SliderIndexForControl = CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(
                                  this: pAttributeSlider,
                                  control: v17);
      }
    }
    if ( SliderIndexForControl != v1->m_nDominantSlider )
    {
      CBaseAnimationSetControl::UpdateDominantSliderStartValues(
        this: v1,
        restoreSliderValues: SliderIndexForControl < 0);
      v1->m_nDominantSlider = SliderIndexForControl;
    }
    if ( vgui::PHandle::Get(this: p_m_ActiveAttributeSlider) != nullptr
      && vgui::PHandle::Get(this: p_m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2 )
    {
      v18 = (CAttributeSlider *)vgui::PHandle::Get(this: p_m_ActiveAttributeSlider);
    }
    else
    {
      v18 = nullptr;
    }
    pAttributeSlider->UpdateControlSetMode(this: pAttributeSlider, a2: my, a3: mx, a4: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048B660
// Name: public: virtual void CBaseAnimationSetControl::ProceduralPreset_UpdateCrossfade(class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ProceduralPreset_UpdateCrossfade(
        CBaseAnimationSetControl *this,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *pPresetValuesLookup,
        int nPresetType)
{
  CBaseAnimationSetControl *v4; // edi
  int m_ElementCount; // eax
  int v6; // xmm0_4
  CDmElement *v7; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // edx
  SelectionInfo_t *m_Element; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v17; // eax
  int v18; // ecx
  CDmElement *v19; // esi
  DmElementHandle_t BufferType; // edi
  unsigned __int16 v21; // ax
  AnimationControlAttributes_t *p_elem; // edi
  CDmElement *v23; // ecx
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // ecx
  CDmaVar<Vector> *DefaultPosition; // eax
  CDmAttribute *v27; // eax
  CDmAttribute *v28; // esi
  const Quaternion *DefaultOrientation; // eax
  CDmAttribute *v30; // eax
  CDmAttribute *v31; // eax
  CDmAttribute *v32; // esi
  CDmAttribute *v33; // ecx
  CDmAttribute *v34; // eax
  CDmAttribute *v35; // esi
  CDmaVar<float> *v36; // eax
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t insert; // [esp+Ch] [ebp-CCh] BYREF
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t search; // [esp+60h] [ebp-78h] BYREF
  CDisableUndoScopeGuard guard; // [esp+B4h] [ebp-24h]
  int v40; // [esp+BCh] [ebp-1Ch]
  float flDefaultValue; // [esp+C0h] [ebp-18h] BYREF
  int pcvi; // [esp+C4h] [ebp-14h]
  SelectionInfo_t *psi; // [esp+C8h] [ebp-10h]
  CBaseAnimationSetControl *v44; // [esp+CCh] [ebp-Ch]
  CDmAttribute *pLeftValueAttribute; // [esp+D0h] [ebp-8h]
  CDmElement *pControl; // [esp+D4h] [ebp-4h] BYREF
  bool bSinglePreset_3; // [esp+E7h] [ebp+Fh]

  v4 = this;
  v44 = this;
  if ( nPresetType >= 5 && nPresetType <= 7 )
    return;
  guard.m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  bSinglePreset_3 = nPresetType != 1;
  m_ElementCount = 1;
  if ( nPresetType == 1 )
    m_ElementCount = v4->m_SelectionHistory.m_ElementCount;
  CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(this: v4, nCount: m_ElementCount);
  v6 = 0;
  if ( bSinglePreset_3 )
  {
    pControl = nullptr;
    if ( nPresetType != 2 )
    {
      if ( nPresetType == 3 )
      {
        v6 = 1056964608;
      }
      else
      {
        if ( nPresetType != 4 )
          goto LABEL_12;
        v6 = 1065353216;
      }
    }
    pControl = (CDmElement *)v6;
LABEL_12:
    v7 = *v4->m_crossfadePresetControlValues.m_Memory.m_pMemory;
    Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "valuePosition");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v7, pAttributeName: "valuePosition", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: Attribute, value: &vec3_origin);
    }
    v9 = CDmElement::FindAttribute(this: v7, pAttributeName: "valueOrientation");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: v7, pAttributeName: "valueOrientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v9, value: &quat_identity);
    }
    v10 = CDmElement::FindAttribute(this: v7, pAttributeName: "leftValue");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v10, value: (float *)&pControl);
    }
    v11 = CDmElement::FindAttribute(this: v7, pAttributeName: "rightValue");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v7, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v11, value: (float *)&pControl);
    }
    v12 = CDmElement::FindAttribute(this: v7, pAttributeName: "value");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(this: v7, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v12, value: (float *)&pControl);
    }
  }
  CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &pPresetValuesLookup->m_Tree);
  m_Head = v4->m_SelectionHistory.m_Head;
  pcvi = -1;
  if ( m_Head != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = v4->m_SelectionHistory.m_Memory.m_pMemory;
      v40 = 8 * (unsigned __int16)m_Head;
      m_Element = m_pMemory[v40 / 8u].m_Element;
      GetElement = g_pDataModel->GetElement;
      psi = m_Element;
      v17 = GetElement(this: g_pDataModel, a2: m_Element->m_hControl.m_handle);
      pControl = v17;
      if ( v17 != nullptr )
        break;
LABEL_71:
      m_Head = v4->m_SelectionHistory.m_Memory.m_pMemory[v40 / 8u].m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_72;
    }
    if ( bSinglePreset_3 )
      v18 = 0;
    else
      v18 = ++pcvi;
    v19 = v4->m_crossfadePresetControlValues.m_Memory.m_pMemory[v18];
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
    memset(&search.elem, 0, 24);
    search.elem.m_Quaternion = quat_identity;
    memset(search.elem.m_pValueAttribute, 0, 40);
    search.key = BufferType;
    v21 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &pPresetValuesLookup->m_Tree,
            &search);
    if ( v21 == 0xFFFF )
    {
      memset(&insert.elem, 0, 24);
      insert.elem.m_Quaternion = quat_identity;
      memset(insert.elem.m_pValueAttribute, 0, 40);
      insert.key = BufferType;
      v21 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
              this: &pPresetValuesLookup->m_Tree,
              &insert);
    }
    p_elem = &pPresetValuesLookup->m_Tree.m_Elements.m_pMemory[v21].m_Data.elem;
    _V_memset(dest: (unsigned __int8 *)p_elem, fill: 0, count: 0x50u);
    v23 = pControl;
    p_elem->m_Quaternion = quat_identity;
    if ( !v23->IsA(this: v23, a2: CDmeTransformControl::m_classType) )
    {
      if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
      {
        v30 = CDmElement::FindAttribute(this: v19, pAttributeName: "leftValue");
        if ( v30 != nullptr )
          pLeftValueAttribute = (v30->m_nFlags & 0x1F) != 3 ? nullptr : v30;
        else
          pLeftValueAttribute = CDmElement::CreateAttribute(this: v19, pAttributeName: "leftValue", type: AT_FLOAT);
        v31 = CDmElement::FindAttribute(this: v19, pAttributeName: "rightValue");
        if ( v31 != nullptr )
          v32 = (v31->m_nFlags & 0x1F) != 3 ? nullptr : v31;
        else
          v32 = CDmElement::CreateAttribute(this: v19, pAttributeName: "rightValue", type: AT_FLOAT);
        v33 = pLeftValueAttribute;
        if ( pLeftValueAttribute != nullptr && v32 != nullptr )
        {
          if ( !bSinglePreset_3 )
          {
            flDefaultValue = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue")->m_Storage;
            CDmAttribute::SetValue<float>(this: pLeftValueAttribute, value: &flDefaultValue);
            CDmAttribute::SetValue<float>(this: v32, value: &flDefaultValue);
            v33 = pLeftValueAttribute;
          }
          p_elem->m_pValueAttribute[2] = v33;
          p_elem->m_pValue[2] = CDmAttribute::GetValue<float>(this: v33)->m_Storage;
          p_elem->m_pValueAttribute[1] = v32;
          p_elem->m_pValue[1] = CDmAttribute::GetValue<float>(this: v32)->m_Storage;
        }
      }
      else
      {
        v34 = CDmElement::FindAttribute(this: v19, pAttributeName: "value");
        if ( v34 != nullptr )
          v35 = (v34->m_nFlags & 0x1F) != 3 ? nullptr : v34;
        else
          v35 = CDmElement::CreateAttribute(this: v19, pAttributeName: "value", type: AT_FLOAT);
        if ( v35 != nullptr )
        {
          if ( !bSinglePreset_3 )
          {
            v36 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue");
            CDmAttribute::SetValue<float>(this: v35, value: &v36->m_Storage);
          }
          p_elem->m_pValueAttribute[0] = v35;
          p_elem->m_pValue[0] = CDmAttribute::GetValue<float>(this: v35)->m_Storage;
        }
      }
      goto LABEL_70;
    }
    if ( (psi->m_nComponentFlags & 7) != 0 )
    {
      v24 = CDmElement::FindAttribute(this: v19, pAttributeName: "valuePosition");
      if ( v24 != nullptr )
      {
        v25 = (v24->m_nFlags & 0x1F) != 10 ? nullptr : v24;
        pLeftValueAttribute = v25;
      }
      else
      {
        pLeftValueAttribute = CDmElement::CreateAttribute(this: v19, pAttributeName: "valuePosition", type: AT_VECTOR3);
        v25 = pLeftValueAttribute;
      }
      if ( v25 == nullptr )
      {
LABEL_70:
        v4 = v44;
        goto LABEL_71;
      }
      if ( !bSinglePreset_3 )
      {
        DefaultPosition = CDmeTransformControl::GetDefaultPosition(this: (CDmeTransformControl *)pControl);
        CDmAttribute::SetValue<Vector>(this: pLeftValueAttribute, value: &DefaultPosition->m_Storage);
        v25 = pLeftValueAttribute;
      }
      p_elem->m_pValueAttribute[3] = v25;
      p_elem->m_Vector = CDmAttribute::GetValue<Vector>(this: v25)->m_Storage;
    }
    if ( (psi->m_nComponentFlags & 0x38) != 0 )
    {
      v27 = CDmElement::FindAttribute(this: v19, pAttributeName: "valueOrientation");
      v28 = v27 != nullptr
          ? ((v27->m_nFlags & 0x1F) != 13
           ? nullptr
           : v27)
          : CDmElement::CreateAttribute(this: v19, pAttributeName: "valueOrientation", type: AT_QUATERNION);
      if ( v28 != nullptr )
      {
        if ( !bSinglePreset_3 )
        {
          DefaultOrientation = CDmeTransformControl::GetDefaultOrientation(this: (CDmeTransformControl *)pControl);
          CDmAttribute::SetValue<Quaternion>(this: v28, value: DefaultOrientation);
        }
        p_elem->m_pValueAttribute[4] = v28;
        p_elem->m_Quaternion = *CDmAttribute::GetValue<Quaternion>(this: v28);
      }
    }
    goto LABEL_70;
  }
LABEL_72:
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&guard.m_bOldValue);
}

//------------------------------------------------------------------------------
// Address: 0x105C7880
// Name: _dynamic_initializer_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeChannel::s_Allocator,
    blockSize: 0xB4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeChannel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD010
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x10486E10
// Name: class Quaternion MaskValue<class Quaternion>(class Quaternion const __near &,class Quaternion const __near &,enum LogComponents_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Quaternion *__cdecl MaskValue<Quaternion>(
        Quaternion *result,
        const Quaternion *value,
        const Quaternion *curQuat,
        LogComponents_t componentFlags)
{
  QAngle curQA; // [esp+0h] [ebp-18h] BYREF
  QAngle valueQA; // [esp+Ch] [ebp-Ch] BYREF

  QuaternionAngles(q: curQuat, angles: &curQA);
  QuaternionAngles(q: value, angles: &valueQA);
  if ( (componentFlags & 1) == 0 )
    valueQA.x = curQA.x;
  if ( (componentFlags & 2) == 0 )
    valueQA.y = curQA.y;
  if ( (componentFlags & 4) == 0 )
    valueQA.z = curQA.z;
  AngleQuaternion(angles: &valueQA, outQuat: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C78B0
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C78C0
// Name: _dynamic_initializer_for__g_CDmeChannel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeChannel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeChannel_Helper,
           classname: "DmeChannel",
           pFactory: &g_CDmeChannel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD020
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x105CD030
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004786A0
// Name: public: bool Quaternion::operator!=(class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Quaternion::operator!=(Quaternion *this, const Quaternion *src)
{
  return this->x != src->x || this->y != src->y || this->z != src->z || this->w != src->w;
}

//------------------------------------------------------------------------------
// Address: 0x00478770
// Name: public: class CDmAttribute __near * CDmeChannel::GetFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::GetFromAttribute(CDmeChannel *this)
{
  CDmAttribute *result; // eax

  result = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_FromAttributeHandle);
  if ( result == nullptr )
    return CDmeChannel::SetupFromAttribute(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004787A0
// Name: protected: virtual void CBaseAnimationSetControl::GetAnimatedPresetTimeParameters(class DmeTime_t __near &,class DmeTime_t __near &,class DmeTime_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::GetAnimatedPresetTimeParameters(
        CBaseAnimationSetControl *this,
        int tHead,
        DmeTime_t *tStart,
        DmeTime_t *tEnd)
{
  DmeTime_t result; // [esp+4h] [ebp-4h] BYREF

  result.m_tms = (int)this;
  *(_DWORD *)tHead = 0;
  tHead = -2147483647;
  DmeTime_t::operator/=(this: (DmeTime_t *)&tHead, &result, f: 2.0);
  tStart->m_tms = tHead;
  tHead = 0x7FFFFFFF;
  DmeTime_t::operator/=(this: (DmeTime_t *)&tHead, result: (DmeTime_t *)&tStart, f: 2.0);
  tEnd->m_tms = tHead;
}

//------------------------------------------------------------------------------
// Address: 0x00478810
// Name: public: bool CBaseAnimationSetControl::IsControlGroupVisible(class CDmeControlGroup const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::IsControlGroupVisible(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pGroup)
{
  return this->m_bShowHiddenControls || CDmeControlGroup::IsVisible(this: pGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00478830
// Name: public: bool CBaseAnimationSetControl::IsPresetFaderBeingDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::IsPresetFaderBeingDragged(CBaseAnimationSetControl *this)
{
  return *((_BYTE *)this + 104) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00478840
// Name: public: struct AttributeValue_t __near & AttributeValue_t::operator=(struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
AttributeValue_t *__thiscall AttributeValue_t::operator=(AttributeValue_t *this, const AttributeValue_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00478BD0
// Name: public: class CDmeFilmClip __near * CBaseAnimationSetControl::GetAnimationSetClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeFilmClip *__thiscall CBaseAnimationSetControl::GetAnimationSetClip(CBaseAnimationSetControl *this)
{
  return (*(CDmeFilmClip *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hFilmClip.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00478BF0
// Name: public: void CBaseAnimationSetControl::SetActiveAttributeSlider(class CAttributeSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetActiveAttributeSlider(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_ActiveAttributeSlider, pPanel: pSlider);
}

//------------------------------------------------------------------------------
// Address: 0x00478C30
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<float>(class DmeTime_t,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDmeChannel::GetPlaybackValueAtTime<float>@<al>(
        CDmeChannel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        DmeTime_t time,
        float *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<float> *v6; // esi
  int m_tms; // eax
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v6 = (CDmeTypedLog<float> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) || CDmeLog::IsEmpty(this: v6) != 0 )
    return 0;
  CDmeLog::GetBeginTime(this: v6, result: &t0);
  CDmeLog::GetEndTime(this: v6, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  *value = *CDmeTypedLog<float>::GetValue(this: v6, a2, a3, time: (DmeTime_t)m_tms);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00478EC0
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<class Quaternion>(class DmeTime_t,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetPlaybackValueAtTime<Quaternion>(CDmeChannel *this, DmeTime_t time, Quaternion *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v4; // esi
  int m_tms; // eax
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v4 = (CDmeTypedLog<Quaternion> *)Log;
  if ( Log == nullptr
    || !Log->IsA(this: Log, a2: CDmeTypedLog<Quaternion>::m_classType)
    || CDmeLog::IsEmpty(this: v4) != 0 )
  {
    return 0;
  }
  CDmeLog::GetBeginTime(this: v4, result: &t0);
  CDmeLog::GetEndTime(this: v4, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  *value = *CDmeTypedLog<Quaternion>::GetValue(this: v4, time: (DmeTime_t)m_tms);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00478F50
// Name: public: bool CDmeChannel::GetPlaybackValueAtTime<class Vector>(class DmeTime_t,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetPlaybackValueAtTime<Vector>(CDmeChannel *this, DmeTime_t time, Vector *value)
{
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v4; // esi
  int m_tms; // eax
  const Vector *v6; // eax
  double z; // st7
  DmeTime_t tn; // [esp+4h] [ebp-8h] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-4h] BYREF

  Log = CDmeChannel::GetLog(this);
  v4 = (CDmeTypedLog<Vector> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) || CDmeLog::IsEmpty(this: v4) != 0 )
    return 0;
  CDmeLog::GetBeginTime(this: v4, result: &t0);
  CDmeLog::GetEndTime(this: v4, result: &tn);
  m_tms = t0.m_tms;
  if ( time.m_tms >= t0.m_tms )
  {
    m_tms = tn.m_tms;
    if ( time.m_tms <= tn.m_tms )
      m_tms = time.m_tms;
  }
  v6 = CDmeTypedLog<Vector>::GetValue(this: v4, time: (DmeTime_t)m_tms);
  value->x = v6->x;
  value->y = v6->y;
  z = v6->z;
  value->z = z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004790F0
// Name: public: class CDmeDag __near * CBaseAnimationSetControl::GetWorkCameraParent(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CBaseAnimationSetControl::GetWorkCameraParent(CBaseAnimationSetControl *this)
{
  return (*(CDmeDag *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hWorkCameraParent.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00479110
// Name: protected: virtual void CBaseAnimationSetControl::FireControlSelectionChangedListeners(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::FireControlSelectionChangedListeners(CBaseAnimationSetControl *this)
{
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v3; // ecx

  for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
  {
    v3 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
    v3->OnControlSelectionChanged(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479140
// Name: protected: virtual void CBaseAnimationSetControl::FireRebuildControlHierarchyListeners(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::FireRebuildControlHierarchyListeners(CBaseAnimationSetControl *this)
{
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v3; // ecx

  for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
  {
    v3 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
    v3->OnRebuildControlHierarchy(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479170
// Name: public: void CBaseAnimationSetControl::SetRangeSelectionState(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetRangeSelectionState(
        CBaseAnimationSetControl *this,
        bool bInRangeSelection)
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    sg.m_pControl = this;
    sg.m_selectionMode = SELECTION_REMOVE;
    atexit(func: CBaseAnimationSetControl::SetRangeSelectionState_::_2_::_dynamic_atexit_destructor_for__sg__);
  }
  if ( bInRangeSelection )
  {
    ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
    sg.m_selectionMode = SELECTION_SET;
  }
  else if ( --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    sg.m_pControl->FireControlSelectionChangedListeners(this: sg.m_pControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004791E0
// Name: public: class CDmElement __near * CBaseAnimationSetControl::GetMostRecentlySelectedControl(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAnimationSetControl::GetMostRecentlySelectedControl(CBaseAnimationSetControl *this)
{
  int m_Tail; // eax

  m_Tail = this->m_SelectionHistory.m_Tail;
  if ( m_Tail == 0xFFFF )
    return nullptr;
  else
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_SelectionHistory.m_Memory.m_pMemory[m_Tail].m_Element->m_hControl.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00479210
// Name: public: void CBaseAnimationSetControl::GetDominantSliderValues(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::GetDominantSliderValues(
        CBaseAnimationSetControl *this,
        float *flDomStart,
        float *flDomValue)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  int m_nDominantSlider; // ecx
  CAttributeSlider *v6; // edi
  char v7; // al
  AnimationControlType_t v8; // esi
  float v9; // xmm0_4
  float flDomStarta; // [esp+8h] [ebp+8h]

  *flDomStart = 0.0;
  *flDomValue = 0.0;
  if ( this->m_nDominantSlider < 0 )
    return;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  if ( AttributeSlider == nullptr )
    return;
  m_nDominantSlider = this->m_nDominantSlider;
  v6 = AttributeSlider->m_SliderList.m_Memory.m_pMemory[m_nDominantSlider];
  if ( v6 == nullptr )
    return;
  v7 = *((_BYTE *)v6 + 656);
  if ( (v7 & 1) != 0 )
    return;
  v8 = (v7 & 4) != 0;
  v9 = this->m_DominantSliderStartValues.m_Memory.m_pMemory[m_nDominantSlider].m_pValue[v8];
  if ( v9 > 1.0 )
    goto LABEL_9;
  if ( v9 >= 0.0 )
  {
    if ( v9 <= 1.0 )
      goto LABEL_10;
LABEL_9:
    v9 = 1.0;
    goto LABEL_10;
  }
  v9 = 0.0;
LABEL_10:
  *flDomStart = v9;
  if ( CAttributeSlider::GetValue(this: v6, type: v8) > 1.0 || CAttributeSlider::GetValue(this: v6, type: v8) >= 0.0 )
  {
    if ( CAttributeSlider::GetValue(this: v6, type: v8) <= 1.0 )
    {
      flDomStarta = CAttributeSlider::GetValue(this: v6, type: v8);
      *flDomValue = flDomStarta;
    }
    else
    {
      *flDomValue = 1.0;
    }
  }
  else
  {
    *flDomValue = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004796F0
// Name: protected: bool CDmeChannel::GetValue<class Vector>(class Vector __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<Vector>(CDmeChannel *this, Vector *value, CDmAttribute *pAttr, int nIndex)
{
  CDmaVar<Vector> *v4; // eax
  double z; // st7
  CDmrArrayConst<Vector> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      v4 = CDmAttribute::GetValue<Vector>(this: pAttr);
      goto LABEL_6;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      v4 = (CDmaVar<Vector> *)&array.m_pStorage->m_Memory.m_pMemory[nIndex];
LABEL_6:
      value->x = v4->m_Storage.x;
      value->y = v4->m_Storage.y;
      z = v4->m_Storage.z;
      value->z = z;
      return 1;
    }
  }
  value->x = 0.0;
  value->y = 0.0;
  value->z = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00479780
// Name: protected: bool CDmeChannel::GetValue<class Quaternion>(class Quaternion __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<Quaternion>(
        CDmeChannel *this,
        Quaternion *value,
        CDmAttribute *pAttr,
        int nIndex)
{
  Quaternion *v4; // eax
  CDmrArrayConst<Quaternion> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      v4 = (Quaternion *)CDmAttribute::GetValue<Quaternion>(this: pAttr);
      goto LABEL_6;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      v4 = &array.m_pStorage->m_Memory.m_pMemory[nIndex];
LABEL_6:
      *value = *v4;
      return 1;
    }
  }
  value->x = 0.0;
  value->y = 0.0;
  value->z = 0.0;
  value->w = 1.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00479820
// Name: protected: bool CDmeChannel::GetValue<float>(float __near &,class CDmAttribute const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetValue<float>(CDmeChannel *this, float *value, CDmAttribute *pAttr, int nIndex)
{
  CDmrArrayConst<float> array; // [esp+4h] [ebp-8h] BYREF

  if ( pAttr != nullptr )
  {
    if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      *value = *CDmAttribute::GetValue<float>(this: pAttr);
      return 1;
    }
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
      this: &array,
      pAttribute: pAttr);
    if ( nIndex >= 0 && nIndex < array.m_pStorage->m_Size )
    {
      *value = array.m_pStorage->m_Memory.m_pMemory[nIndex];
      return 1;
    }
  }
  *value = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00479A80
// Name: public: void CBaseAnimationSetControl::SetWorkCameraParent(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SetWorkCameraParent(CBaseAnimationSetControl *this, CDmeDag *pParent)
{
  CDmeHandle<CDmeDag,0> *p_m_hWorkCameraParent; // esi
  DmElementHandle_t BufferType; // eax

  p_m_hWorkCameraParent = &this->m_hWorkCameraParent;
  if ( pParent != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pParent);
    CDmeHandle<CDmeDag,0>::Set(this: p_m_hWorkCameraParent, h: BufferType);
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: p_m_hWorkCameraParent, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479AB0
// Name: public: enum TransformComponent_t CBaseAnimationSetControl::GetSelectionComponentFlags(class CDmElement __near *)const
// Source: json
//------------------------------------------------------------------------------
TransformComponent_t __thiscall CBaseAnimationSetControl::GetSelectionComponentFlags(
        CBaseAnimationSetControl *this,
        CDmElement *pControl)
{
  int m_Head; // eax
  int v5; // esi
  SelectionInfo_t *m_Element; // edi

  if ( pControl == nullptr )
    return TRANSFORM_COMPONENT_NONE;
  m_Head = this->m_SelectionHistory.m_Head;
  if ( m_Head == 0xFFFF )
    return TRANSFORM_COMPONENT_NONE;
  while ( 1 )
  {
    v5 = (unsigned __int16)m_Head;
    m_Element = this->m_SelectionHistory.m_Memory.m_pMemory[v5].m_Element;
    if ( (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: m_Element->m_hControl.m_handle) == pControl )
      break;
    m_Head = this->m_SelectionHistory.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == 0xFFFF )
      return TRANSFORM_COMPONENT_NONE;
  }
  return m_Element->m_nComponentFlags;
}

//------------------------------------------------------------------------------
// Address: 0x0047A040
// Name: public: bool CDmeChannel::GetInputValue<class Vector>(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<Vector>(CDmeChannel *this, Vector *value)
{
  CDmAttribute *v3; // eax

  v3 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<Vector>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0047A080
// Name: public: bool CDmeChannel::GetInputValue<class Quaternion>(class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<Quaternion>(CDmeChannel *this, Quaternion *value)
{
  CDmAttribute *v3; // eax

  v3 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<Quaternion>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0047A0C0
// Name: public: bool CDmeChannel::GetInputValue<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::GetInputValue<float>(CDmeChannel *this, float *value)
{
  CDmAttribute *v3; // eax

  v3 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  return CDmeChannel::GetValue<float>(this, value, pAttr: v3, nIndex: this->m_fromIndex.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0047A990
// Name: public: void CBaseAnimationSetControl::ClearSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ClearSelection(CBaseAnimationSetControl *this)
{
  int m_Tail; // eax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // ecx
  int v4; // eax

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  m_Tail = this->m_SelectionHistory.m_Tail;
  if ( m_Tail != 0xFFFF )
  {
    m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
    do
    {
      v4 = (unsigned __int16)m_Tail;
      m_pMemory[v4].m_Element->m_nComponentFlags = TRANSFORM_COMPONENT_NONE;
      m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
      m_Tail = m_pMemory[v4].m_Previous;
    }
    while ( m_Tail != 0xFFFF );
  }
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SelectionHistory);
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    this->FireControlSelectionChangedListeners(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A9F0
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmElement __near *,enum TransformComponent_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(
        CBaseAnimationSetControl *this,
        CDmElement *pControl,
        TransformComponent_t componentFlags)
{
  CDmeControlGroup *GroupContainingControl; // eax
  __int32 v5; // eax

  if ( pControl == nullptr )
    return 0;
  if ( !this->m_bShowHiddenControls )
  {
    GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl);
    if ( GroupContainingControl == nullptr || !CDmeControlGroup::IsVisible(this: GroupContainingControl) )
      return 0;
  }
  v5 = componentFlags & CBaseAnimationSetControl::GetSelectionComponentFlags(this, pControl);
  if ( v5 != 0 )
    return (v5 != componentFlags) + 2;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047AA60
// Name: void SetPresetFromControl(class CDmePreset __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPresetFromControl(CDmePreset *pPreset, CDmeTransformControl *pControl)
{
  const char *m_pAsString; // eax
  CDmElement *v3; // esi
  const Vector *Position; // ebx
  CDmAttribute *Attribute; // eax
  const Quaternion *Orientation; // edi
  CDmAttribute *v7; // eax
  const char *v8; // eax
  CDmElement *v9; // esi
  CDmaVar<float> *v10; // ebx
  CDmAttribute *v11; // eax
  CDmaVar<float> *v12; // edi
  CDmAttribute *v13; // eax
  CDmaVar<float> *v14; // edi
  CDmAttribute *v15; // eax

  if ( pControl != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    m_pAsString = pControl->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    v3 = CDmePreset::FindOrAddControlValue(this: pPreset, pControlName: m_pAsString);
    if ( v3 != nullptr )
    {
      if ( CDmeTransformControl::GetPositionChannel(this: pControl) != nullptr )
      {
        Position = CDmeTransformControl::GetPosition(this: pControl);
        Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "valuePosition");
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "valuePosition", type: AT_VECTOR3)) != nullptr )
        {
          CDmAttribute::SetValue<Vector>(this: Attribute, value: Position);
        }
      }
      if ( CDmeTransformControl::GetOrientationChannel(this: pControl) != nullptr )
      {
        Orientation = CDmeTransformControl::GetOrientation(this: pControl);
        v7 = CDmElement::FindAttribute(this: v3, pAttributeName: "valueOrientation");
        if ( v7 != nullptr
          || (v7 = CDmElement::CreateAttribute(this: v3, pAttributeName: "valueOrientation", type: AT_QUATERNION)) != nullptr )
        {
          CDmAttribute::SetValue<Quaternion>(this: v7, value: Orientation);
        }
      }
    }
  }
  else
  {
    v8 = pControl->m_Name.m_Storage.u.m_pAsString;
    if ( v8 == (const char *)-1 )
      v8 = defaultValue;
    v9 = CDmePreset::FindOrAddControlValue(this: pPreset, pControlName: v8);
    if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
    {
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "value");
      v10 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "leftValue");
      v11 = CDmElement::FindAttribute(this: v9, pAttributeName: "leftValue");
      if ( v11 != nullptr
        || (v11 = CDmElement::CreateAttribute(this: v9, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v11, value: &v10->m_Storage);
      }
      v12 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "rightValue");
      v13 = CDmElement::FindAttribute(this: v9, pAttributeName: "rightValue");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v9, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v13, value: &v12->m_Storage);
      }
    }
    else
    {
      v14 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "value");
      v15 = CDmElement::FindAttribute(this: v9, pAttributeName: "value");
      if ( v15 != nullptr
        || (v15 = CDmElement::CreateAttribute(this: v9, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v15, value: &v14->m_Storage);
      }
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "leftValue");
      CDmElement::RemoveAttribute(this: v9, pAttributeName: "rightValue");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047AE50
// Name: public: CBaseAnimationSetControl::CBaseAnimationSetControl(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetControl *__thiscall CBaseAnimationSetControl::CBaseAnimationSetControl(CBaseAnimationSetControl *this)
{
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // eax

  this->__vftable = (CBaseAnimationSetControl_vtbl *)&CBaseAnimationSetControl::`vftable';
  this->m_hFilmClip.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_pEditor = nullptr;
  this->m_SelectionHistory.m_Memory.m_pMemory = nullptr;
  this->m_SelectionHistory.m_Memory.m_nAllocationCount = 0;
  this->m_SelectionHistory.m_Memory.m_nGrowSize = 0;
  this->m_SelectionHistory.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_SelectionHistory.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_SelectionHistory.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_SelectionHistory.m_Head = -1;
  this->m_SelectionHistory.m_pElements = m_pMemory;
  this->m_SelectionHistory.m_NumAlloced = 0;
  this->m_hWorkCameraParent.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_OverrideParentChangedListeners.m_Memory.m_pMemory = nullptr;
  this->m_OverrideParentChangedListeners.m_Memory.m_nAllocationCount = 0;
  this->m_OverrideParentChangedListeners.m_Memory.m_nGrowSize = 0;
  this->m_OverrideParentChangedListeners.m_Size = 0;
  this->m_OverrideParentChangedListeners.m_pElements = nullptr;
  this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory = nullptr;
  this->m_ControlSelectionChangedListeners.m_Memory.m_nAllocationCount = 0;
  this->m_ControlSelectionChangedListeners.m_Memory.m_nGrowSize = 0;
  this->m_ControlSelectionChangedListeners.m_Size = 0;
  this->m_ControlSelectionChangedListeners.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_PreviousPresetSlider, pString: defaultValue);
  *((_BYTE *)this + 104) &= 0xF8u;
  this->m_flPreviousPresetAmount = 0.0;
  this->m_ActiveAttributeSlider.m_iPanelID = -1;
  this->m_DominantSliderStartValues.m_Memory.m_pMemory = nullptr;
  this->m_DominantSliderStartValues.m_Memory.m_nAllocationCount = 0;
  this->m_DominantSliderStartValues.m_Memory.m_nGrowSize = 0;
  this->m_DominantSliderStartValues.m_Size = 0;
  this->m_DominantSliderStartValues.m_pElements = nullptr;
  this->m_nDominantSlider = -1;
  this->m_bShowHiddenControls = false;
  this->m_crossfadePresetControlValues.m_Memory.m_pMemory = nullptr;
  this->m_crossfadePresetControlValues.m_Memory.m_nAllocationCount = 0;
  this->m_crossfadePresetControlValues.m_Memory.m_nGrowSize = 0;
  this->m_crossfadePresetControlValues.m_Size = 0;
  this->m_crossfadePresetControlValues.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047AF10
// Name: public: virtual void CBaseAnimationSetControl::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ChangeAnimationSetClip(
        CBaseAnimationSetControl *this,
        CDmeFilmClip *pFilmClip)
{
  DmElementHandle_t BufferType; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax

  if ( pFilmClip != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pFilmClip);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeFilmClip,0>::Set(this: &this->m_hFilmClip, h: BufferType);
  this->m_nDominantSlider = -1;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hWorkCameraParent, h: DMELEMENT_HANDLE_INVALID);
  CBaseAnimationSetControl::ClearSelection(this);
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
  if ( PresetFader != nullptr )
    CBaseAnimSetPresetFaderPanel::PopulatePresetList(this: PresetFader, bChanged: true);
}

//------------------------------------------------------------------------------
// Address: 0x0047AF70
// Name: public: void CBaseAnimationSetControl::AddControlSelectionChangedListener(class IAnimationSetControlSelectionChangedListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddControlSelectionChangedListener(
        CBaseAnimationSetControl *this,
        IAnimationSetControlSelectionChangedListener *listener)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_ControlSelectionChangedListeners; // esi
  int m_Size; // ecx
  int v4; // eax
  IAnimationSetControlSelectionChangedListener **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_ControlSelectionChangedListeners = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ControlSelectionChangedListeners;
  m_Size = this->m_ControlSelectionChangedListeners.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IAnimationSetControlSelectionChangedListener **)p_m_ControlSelectionChangedListeners->m_pMemory;
  while ( *m_pMemory != listener )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_ControlSelectionChangedListeners->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: p_m_ControlSelectionChangedListeners,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_ControlSelectionChangedListeners[1].m_pMemory;
    v8 = p_m_ControlSelectionChangedListeners->m_pMemory;
    v9 = (int)p_m_ControlSelectionChangedListeners[1].m_pMemory - v7 - 1;
    p_m_ControlSelectionChangedListeners[1].m_nAllocationCount = (int)p_m_ControlSelectionChangedListeners->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_ControlSelectionChangedListeners->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)listener;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047AFF0
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmeControlGroup __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pControlGroup)
{
  CDmeControlGroup *v2; // eax
  int v3; // edi
  int m_Size; // ebx
  int v6; // eax
  CDmeControlGroup *v7; // esi
  int v8; // ebx
  int v9; // eax
  CDmElement *v10; // esi
  CDmeControlGroup *GroupContainingControl; // eax
  __int32 v12; // eax
  int v13; // eax
  int nControls; // [esp+Ch] [ebp-Ch]
  SelectionState_t selection; // [esp+14h] [ebp-4h]

  v2 = pControlGroup;
  v3 = 0;
  if ( pControlGroup == nullptr )
    return 0;
  m_Size = pControlGroup->m_Children.m_Storage.m_Size;
  selection = SEL_EMPTY;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v2->m_Children.m_Storage.m_Memory.m_pMemory[v3]);
      v7 = (CDmeControlGroup *)v6;
      if ( v6 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeControlGroup::m_classType.u) == 0 )
      {
        v7 = nullptr;
      }
      selection |= CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: v7);
      if ( selection == SEL_SOME )
        return 3;
      v2 = pControlGroup;
    }
    while ( ++v3 < m_Size );
  }
  v8 = 0;
  nControls = v2->m_Controls.m_Storage.m_Size;
  if ( nControls > 0 )
  {
    while ( 1 )
    {
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v2->m_Controls.m_Storage.m_Memory.m_pMemory[v8]);
      v10 = (CDmElement *)v9;
      if ( v9 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
             a1: v9,
             a2: CDmElement::m_classType.u) != 0
        && (this->m_bShowHiddenControls
         || (GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl: v10)) != nullptr
         && CDmeControlGroup::IsVisible(this: GroupContainingControl)) )
      {
        v12 = CBaseAnimationSetControl::GetSelectionComponentFlags(this, pControl: v10) & 0x3F;
        v13 = v12 != 0 ? (v12 != 63) + 2 : 1;
      }
      else
      {
        v13 = 0;
      }
      selection |= v13;
      if ( selection == SEL_SOME )
        break;
      if ( ++v8 >= nControls )
        return selection;
      v2 = pControlGroup;
    }
    return 3;
  }
  return selection;
}

//------------------------------------------------------------------------------
// Address: 0x0047B140
// Name: public: void CBaseAnimationSetControl::UpdatePreviewSliderValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdatePreviewSliderValues(CBaseAnimationSetControl *this)
{
  CBaseAnimationSetControl *v1; // edi
  CBaseAnimationSetEditor *m_pEditor; // ecx
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  const char *v5; // eax
  bool v6; // dl
  bool v7; // al
  bool v8; // bl
  char v9; // cl
  bool v10; // al
  char v11; // cl
  bool v12; // al
  int v13; // eax
  CAttributeSlider *v14; // esi
  char v15; // bl
  unsigned __int16 v16; // ax
  AnimationControlAttributes_t *Value; // ebx
  const AttributeValue_t *v18; // eax
  bool v19; // bl
  const AttributeValue_t *v20; // edi
  const AttributeValue_t *v21; // [esp+8h] [ebp-A4h]
  const char *name; // [esp+14h] [ebp-98h]
  AttributeValue_t dest; // [esp+20h] [ebp-8Ch] BYREF
  float flBalanceSliderValue; // [esp+48h] [ebp-64h]
  int c; // [esp+4Ch] [ebp-60h]
  BOOL bTransform; // [esp+50h] [ebp-5Ch]
  AttributeValue_t preview; // [esp+54h] [ebp-58h] BYREF
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+7Ch] [ebp-30h]
  int y; // [esp+80h] [ebp-2Ch] BYREF
  int x; // [esp+84h] [ebp-28h] BYREF
  CBaseAnimationSetControl *v31; // [esp+88h] [ebp-24h]
  CDmElement *pControl; // [esp+8Ch] [ebp-20h] BYREF
  int i; // [esp+90h] [ebp-1Ch]
  FaderPreview_t fader; // [esp+94h] [ebp-18h] BYREF
  bool faderAmountChanged; // [esp+A8h] [ebp-4h]
  bool bFaderChanged; // [esp+A9h] [ebp-3h]
  bool shiftDown; // [esp+AAh] [ebp-2h]
  bool simple; // [esp+ABh] [ebp-1h]

  v1 = this;
  m_pEditor = this->m_pEditor;
  v31 = v1;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: m_pEditor);
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider == nullptr )
    return;
  flBalanceSliderValue = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: AttributeSlider);
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: v1->m_pEditor);
  i = (int)PresetFader;
  if ( PresetFader == nullptr )
    return;
  memset(&fader, 0, 10);
  fader.values = nullptr;
  fader.nProceduralType = 0;
  CBaseAnimSetPresetFaderPanel::GetPreviewFader(this: PresetFader, &fader);
  simple = fader.name != nullptr
        && (CUtlString::Length(this: &v1->m_PreviousPresetSlider) == 0
         || (name = fader.name,
             v5 = CUtlString::Get(this: &v1->m_PreviousPresetSlider),
             _V_stricmp(s1: v5, s2: name) != 0));
  v6 = fader.isbeingdragged != (*((_BYTE *)v1 + 104) & 1);
  v7 = (*((_BYTE *)v1 + 104) & 2) != 0;
  v8 = fader.holdingPreviewKey != v7;
  shiftDown = v6;
  if ( simple || v6 || (bFaderChanged = false, fader.holdingPreviewKey != v7) )
    bFaderChanged = true;
  faderAmountChanged = fader.amount != v1->m_flPreviousPresetAmount;
  if ( fader.holdingPreviewKey || fader.isbeingdragged && v6 || bFaderChanged )
  {
    CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(
      this: (CBaseAnimSetPresetFaderPanel *)i,
      values: fader.values);
    if ( fader.holdingPreviewKey && v8 )
    {
      v6 = shiftDown;
      v9 = 1;
      goto LABEL_21;
    }
    v6 = shiftDown;
  }
  v9 = 0;
LABEL_21:
  v10 = fader.isbeingdragged && v6;
  if ( simple || v9 != 0 || v10 )
    v10 = true;
  *((_BYTE *)v1 + 104) ^= (*((_BYTE *)v1 + 104) ^ (4 * v10)) & 4;
  CUtlString::operator=(this: &v1->m_PreviousPresetSlider, src: fader.name);
  v11 = fader.isbeingdragged | *((_BYTE *)v1 + 104) & 0xFC | (2 * fader.holdingPreviewKey);
  v1->m_flPreviousPresetAmount = fader.amount;
  *((_BYTE *)v1 + 104) = v11;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v12 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v12) )
  {
    shiftDown = true;
  }
  v13 = 0;
  c = pAttributeSlider->m_SliderList.m_Size;
  i = 0;
  if ( c > 0 )
  {
    do
    {
      v14 = pAttributeSlider->m_SliderList.m_Memory.m_pMemory[v13];
      if ( v14->IsVisible(this: v14) )
      {
        pControl = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: v14->m_hControl.m_handle);
        if ( pControl != nullptr )
        {
          v15 = *((_BYTE *)v14 + 656) & 1;
          LOBYTE(bTransform) = v15;
          if ( vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) == v14
            && v14->m_SliderMode != SLIDER_MODE_DRAG_VALUE
            && shiftDown )
          {
            memset(&preview, 0, 24);
            preview.m_Quaternion = quat_identity;
            if ( v15 != 0 )
            {
              CAttributeSlider::GetValue(this: v14, type: ANIM_CONTROL_COUNT, out: &preview.m_Vector);
              CAttributeSlider::GetValue(this: v14, type: ANIM_CONTROL_TXFORM_ORIENTATION, out: &preview.m_Quaternion);
            }
            else
            {
              g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
              vgui::Panel::ScreenToLocal(this: v14, &x, &y);
              preview.m_pValue[0] = CAttributeSlider::EstimateValueAtPos(this: v14, nLocalX: x, nLocalY: y);
              preview.m_pValue[2] = preview.m_pValue[0];
              preview.m_pValue[1] = preview.m_pValue[0];
            }
            CAttributeSlider::SetPreview(this: v14, value: &preview, full: &preview);
          }
          else if ( fader.values != nullptr )
          {
            if ( fader.isbeingdragged || (simple = false, !fader.holdingPreviewKey) )
              simple = true;
            if ( bFaderChanged || fader.isbeingdragged )
            {
              pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pControl);
              v16 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Find(
                      this: fader.values,
                      key: (DmElementHandle_t *)&pControl);
              if ( v16 == 0xFFFF )
                Value = (AnimationControlAttributes_t *)CAttributeSlider::GetValue(this: v14);
              else
                Value = &fader.values->m_Tree.m_Elements.m_pMemory[v16].m_Data.elem;
              v18 = CAttributeSlider::GetValue(this: v14);
              memset(&preview, 0, 24);
              preview.m_Quaternion = quat_identity;
              v21 = Value;
              v19 = bTransform;
              v20 = v18;
              BlendValues(
                bTransform,
                pResult: &preview,
                src: v18,
                dest: v21,
                flBlend: 1.0,
                flBalanceFilter: flBalanceSliderValue);
              if ( simple )
              {
                CAttributeSlider::SetPreview(this: v14, value: &preview, full: &preview);
              }
              else
              {
                memset(&dest, 0, 24);
                dest.m_Quaternion = quat_identity;
                BlendValues(
                  bTransform: v19,
                  pResult: &dest,
                  src: v20,
                  dest: &preview,
                  flBlend: fader.amount,
                  flBalanceFilter: 0.5);
                CAttributeSlider::SetPreview(this: v14, value: &dest, full: &preview);
              }
              v1 = v31;
            }
            if ( faderAmountChanged || fader.isbeingdragged || fader.holdingPreviewKey )
              CAttributeSlider::UpdateFaderAmount(this: v14, flAmount: fader.amount);
          }
        }
      }
      v13 = i + 1;
      i = v13;
    }
    while ( v13 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B5E0
// Name: public: void CBaseAnimationSetControl::ApplyPreset(float,class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplyPreset(
        CBaseAnimationSetControl *this,
        float flScale,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *values)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  CBaseAnimSetAttributeSliderPanel *v4; // ebx
  int m_Size; // eax
  int v6; // edi
  CAttributeSlider *v7; // esi
  CExpressionCalculator *v8; // eax
  unsigned __int16 v9; // ax
  AnimationControlAttributes_t *Value; // ebx
  const AttributeValue_t *v11; // eax
  const AttributeValue_t *v12; // edi
  float flBalanceFilter; // [esp+8h] [ebp-50h]
  AttributeValue_t blend; // [esp+18h] [ebp-40h] BYREF
  int c; // [esp+40h] [ebp-18h]
  bool bTransform[4]; // [esp+44h] [ebp-14h]
  DmElementHandle_t key; // [esp+48h] [ebp-10h] BYREF
  int i; // [esp+4Ch] [ebp-Ch]
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+50h] [ebp-8h]
  bool bChanged; // [esp+57h] [ebp-1h]

  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  v4 = AttributeSlider;
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    m_Size = AttributeSlider->m_SliderList.m_Size;
    v6 = 0;
    bChanged = false;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
    {
      do
      {
        v7 = v4->m_SliderList.m_Memory.m_pMemory[v6];
        if ( v7 != nullptr && v7->IsVisible(this: v7) )
        {
          v8 = (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                          a1: g_pDataModel.u,
                                          a2: v7->m_hControl.m_handle);
          key = CCodecBuffer_Block::GetBufferType(this: v8);
          v9 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Find(this: values, &key);
          if ( v9 == 0xFFFF )
            Value = (AnimationControlAttributes_t *)CAttributeSlider::GetValue(this: v7);
          else
            Value = &values->m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
          v11 = CAttributeSlider::GetValue(this: v7);
          memset(&blend, 0, 24);
          blend.m_Quaternion = quat_identity;
          v12 = v11;
          bTransform[0] = *((_BYTE *)v7 + 656) & 1;
          flBalanceFilter = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: pAttributeSlider);
          BlendValues(
            bTransform: bTransform[0],
            pResult: &blend,
            src: v12,
            dest: Value,
            flBlend: flScale,
            flBalanceFilter);
          CAttributeSlider::SetValue(this: v7, value: &blend);
          v4 = pAttributeSlider;
          v6 = i;
          bChanged = true;
        }
        i = ++v6;
      }
      while ( v6 < c );
      if ( bChanged )
        v4->UpdatePreview(this: v4, a2: "ApplyPreset\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B750
// Name: protected: void CBaseAnimationSetControl::ApplySliderValueWithDominance(class CAttributeSlider __near *,int,float,float,class CDmElement __near *,bool,bool,bool __near &,enum AnimationControlType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ApplySliderValueWithDominance(
        CBaseAnimationSetControl *this,
        CAttributeSlider *pSlider,
        int si,
        float flDomStart,
        float flDomValue,
        CDmElement *pControl,
        float bUsePreviewValue,
        DmeTime_t bForce,
        bool *valuesChanged,
        float type,
        const char *pChannelAttrName,
        char *pValueAttrName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v13; // ebx
  CDmeChannel *Value; // eax
  CDmeChannel *v15; // esi
  ChannelMode_t Mode; // eax
  char v17; // cl
  DmeTime_t *CurrentTime; // eax
  char v19; // bl
  AnimationControlType_t v20; // esi
  double Preview; // st7
  float v23; // xmm1_4
  CDmaVar<float> *v24; // eax
  CDmAttribute *v25; // esi
  float v26; // xmm0_4
  float flScale; // [esp+1Ch] [ebp+8h]

  Attribute = CDmElement::FindAttribute(this: pControl, pAttributeName: pValueAttrName);
  v13 = Attribute;
  pValueAttrName = (char *)Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 3 )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  v15 = Value;
  if ( Value != nullptr )
  {
    Mode = CDmeChannel::GetMode(this: Value);
    if ( Mode != CM_PASS && Mode != CM_RECORD )
    {
      v17 = 0;
      goto LABEL_9;
    }
  }
  else
  {
    Mode = CM_PASS;
  }
  v17 = 1;
LABEL_9:
  if ( Mode == CM_PLAY )
  {
    if ( pSlider->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
    {
      bUsePreviewValue = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue")->m_Storage;
      CurrentTime = CDmeChannel::GetCurrentTime(this: v15, result: &bForce);
      if ( CDmeChannel::GetPlaybackValueAtTime<float>(
             this: v15,
             a2: (int)v13,
             a3: (int)pControl,
             time: (DmeTime_t)CurrentTime->m_tms,
             value: &bUsePreviewValue) != 0 )
        CDmAttribute::SetValue<float>(this: v13, value: &bUsePreviewValue);
      else
        bUsePreviewValue = *CDmAttribute::GetValue<float>(this: v13);
      CAttributeSlider::SetValue(this: pSlider, type: SLODWORD(type), flValue: bUsePreviewValue);
    }
  }
  else if ( v17 != 0 )
  {
    v19 = LOBYTE(bUsePreviewValue);
    v20 = LODWORD(type);
    if ( LOBYTE(bUsePreviewValue) != 0 )
      Preview = CAttributeSlider::GetPreview(this: pSlider, type: SLODWORD(type));
    else
      Preview = CAttributeSlider::GetValue(this: pSlider, type: SLODWORD(type));
    bUsePreviewValue = Preview;
    if ( this->m_nDominantSlider >= 0 && pSlider->IsVisible(this: pSlider) && v19 == 0 && this->m_nDominantSlider != si )
    {
      type = this->m_DominantSliderStartValues.m_Memory.m_pMemory[si].m_pValue[v20];
      if ( (float)(1.0 - flDomStart) <= 0.0 )
      {
        flScale = 0.0;
      }
      else
      {
        v23 = flDomValue - flDomStart;
        if ( (float)(flDomValue - flDomStart) < 0.0 )
          v23 = 0.0;
        flScale = v23 / (float)(1.0 - flDomStart);
      }
      v24 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue");
      bUsePreviewValue = (float)((float)(1.0 - flScale) * type) + (float)(v24->m_Storage * flScale);
      CAttributeSlider::SetValue(this: pSlider, type: v20, flValue: bUsePreviewValue);
    }
    v25 = (CDmAttribute *)pValueAttrName;
    v26 = *CDmAttribute::GetValue<float>(this: (CDmAttribute *)pValueAttrName);
    if ( v26 != bUsePreviewValue || LOBYTE(bForce.m_tms) != 0 )
    {
      *valuesChanged = true;
      CDmAttribute::SetValue<float>(this: v25, value: &bUsePreviewValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B960
// Name: public: bool CBaseAnimationSetControl::ApplySliderValues(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimationSetControl::ApplySliderValues(CBaseAnimationSetControl *this, BOOL bForce)
{
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // esi
  int m_Size; // ecx
  int v6; // eax
  CAttributeSlider *v7; // esi
  vgui::BuildGroup *v8; // edi
  bool v9; // al
  bool v10; // zf
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  bool v12; // al
  char guard_4; // [esp+48h] [ebp-20h]
  int nSliders; // [esp+4Ch] [ebp-1Ch]
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+50h] [ebp-18h]
  float flDomStart; // [esp+54h] [ebp-14h] BYREF
  float flDomValue; // [esp+58h] [ebp-10h] BYREF
  int v18; // [esp+5Ch] [ebp-Ch]
  DmeTime_t bUsePreviewValue; // [esp+62h] [ebp-6h]
  bool shiftDown; // [esp+66h] [ebp-2h]
  bool valuesChanged; // [esp+67h] [ebp-1h] BYREF

  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider == nullptr )
    return false;
  if ( !bForce )
    LOBYTE(bForce) = *((_BYTE *)this + 104) & 1;
  guard_4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  flDomStart = 0.0;
  flDomValue = 0.0;
  CBaseAnimationSetControl::GetDominantSliderValues(this, &flDomStart, &flDomValue);
  m_Size = AttributeSlider->m_SliderList.m_Size;
  v6 = 0;
  valuesChanged = false;
  nSliders = m_Size;
  v18 = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v7 = AttributeSlider->m_SliderList.m_Memory.m_pMemory[v6];
      if ( v7 != nullptr && v7->IsVisible(this: v7) )
      {
        v8 = (vgui::BuildGroup *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: v7->m_hControl.m_handle);
        if ( v8 != nullptr )
        {
          if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
            || (v9 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v9) )
          {
            shiftDown = true;
          }
          if ( vgui::PHandle::Get(this: &this->m_ActiveAttributeSlider) != v7
            || v7->m_SliderMode == SLIDER_MODE_DRAG_VALUE
            || (v10 = !shiftDown, shiftDown = true, v10) )
          {
            shiftDown = false;
          }
          PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
          v12 = CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(this: PresetFader) != nullptr;
          LOBYTE(bUsePreviewValue.m_tms) = (*((_BYTE *)this + 104) & 2) != 0 || shiftDown || bForce && v12;
          if ( ((unsigned __int8 (__thiscall *)(vgui::BuildGroup *, CUtlSymbolLarge::<unnamed_type_u>))v8->SaveControlSettings)(
                 a1: v8,
                 a2: CDmeTransformControl::m_classType.u) != 0 )
          {
            if ( (*((_BYTE *)v7 + 656) & 2) != 0 )
              CBaseAnimationSetControl::ApplyTransformSliderValue<Quaternion>(
                this,
                pSlider: v7,
                pTranformControl: v8,
                bUsePreviewValue,
                bForce,
                &valuesChanged,
                type: ANIM_CONTROL_TXFORM_ORIENTATION);
            else
              CBaseAnimationSetControl::ApplyTransformSliderValue<Vector>(
                this,
                pSlider: v7,
                pTranformControl: v8,
                bUsePreviewValue,
                bForce,
                &valuesChanged,
                type: ANIM_CONTROL_COUNT);
          }
          else if ( CDmElement::HasAttribute(this: (CDmElement *)v8, pAttributeName: "rightValue", type: AT_UNKNOWN) )
          {
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v18,
              flDomStart,
              flDomValue,
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)&bUsePreviewValue.m_tms,
              (DmeTime_t)bForce,
              &valuesChanged,
              type: COERCE_FLOAT(2),
              pChannelAttrName: "leftvaluechannel",
              pValueAttrName: "leftValue");
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v18,
              flDomStart,
              flDomValue,
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)&bUsePreviewValue.m_tms,
              (DmeTime_t)bForce,
              &valuesChanged,
              type: COERCE_FLOAT(1),
              pChannelAttrName: "rightvaluechannel",
              pValueAttrName: "rightValue");
          }
          else
          {
            CBaseAnimationSetControl::ApplySliderValueWithDominance(
              this,
              pSlider: v7,
              si: v18,
              flDomStart,
              flDomValue,
              pControl: (CDmElement *)v8,
              bUsePreviewValue: *(float *)&bUsePreviewValue.m_tms,
              (DmeTime_t)bForce,
              &valuesChanged,
              type: 0.0,
              pChannelAttrName: "channel",
              pValueAttrName: "value");
          }
        }
      }
      v6 = v18 + 1;
      v18 = v6;
      if ( v6 >= nSliders )
        break;
      AttributeSlider = pAttributeSlider;
    }
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: guard_4);
  return valuesChanged;
}

//------------------------------------------------------------------------------
// Address: 0x0047BC00
// Name: protected: void CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(
        CBaseAnimationSetControl *this,
        int nCount)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_crossfadePresetControlValues; // esi
  int m_Size; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // edi
  vgui::TreeNode *v7; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax
  int nCounta; // [esp+14h] [ebp+8h]

  p_m_crossfadePresetControlValues = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_crossfadePresetControlValues;
  this->m_crossfadePresetControlValues.m_Size = 0;
  m_Size = this->m_crossfadePresetControlValues.m_Size;
  if ( m_Size < nCount )
  {
    nCounta = nCount - m_Size;
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
             a1: g_pDataModel.u,
             a2: CDmElement::m_classType.u,
             a3: "procedural preset control value",
             a4: -1,
             a5: 0);
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: v4);
      v6 = v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0 )
      {
        v7 = (vgui::TreeNode *)v6;
      }
      else
      {
        v7 = nullptr;
      }
      m_pMemory = p_m_crossfadePresetControlValues[1].m_pMemory;
      m_nAllocationCount = p_m_crossfadePresetControlValues->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: p_m_crossfadePresetControlValues,
          num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_crossfadePresetControlValues[1].m_pMemory;
      v10 = p_m_crossfadePresetControlValues->m_pMemory;
      v11 = (char *)p_m_crossfadePresetControlValues[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_crossfadePresetControlValues[1].m_nAllocationCount = (int)p_m_crossfadePresetControlValues->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
      v12 = &p_m_crossfadePresetControlValues->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = v7;
      --nCounta;
    }
    while ( nCounta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BCE0
// Name: void AddKeysToPreset<class Vector>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<Vector>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Vector> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  const Vector *v18; // eax
  const Vector *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  const Vector *v22; // eax
  Vector v; // [esp+Ch] [ebp-34h] BYREF
  CDmrArray<Vector> values; // [esp+18h] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+20h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+28h] [ebp-18h] BYREF
  int nKeys; // [esp+2Ch] [ebp-14h]
  DmeTime_t src; // [esp+30h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+34h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+38h] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+3Ch] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<Vector> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Vector>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: (int)"channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    CDmeChannel::GetInputValue<Vector>(this: Value, value: &v);
    CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(this: &values, src: &v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalStart, t: tStart, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalEnd, t: tEnd, bClamp: 0);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  nKeys = CDmeLog::GetKeyCount(this: v14);
  if ( nKeys <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          &src);
        v18 = CDmeTypedLog<Vector>::GetValue(this: v14, time: tLocalStart);
        CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: Referring, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        &src);
      KeyValue = CDmeTypedLog<Vector>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= nKeys )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    v22 = CDmeTypedLog<Vector>::GetValue(this: v14, time: tLocalEnd);
    CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddToTail(
      this: &values,
      src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BF10
// Name: void AddKeysToPreset<class Quaternion>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<Quaternion>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  const Quaternion *v18; // eax
  const Quaternion *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  const Quaternion *v22; // eax
  Quaternion v; // [esp+Ch] [ebp-38h] BYREF
  CDmrArray<Quaternion> values; // [esp+1Ch] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+24h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+2Ch] [ebp-18h] BYREF
  int nKeys; // [esp+30h] [ebp-14h]
  DmeTime_t src; // [esp+34h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+38h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+3Ch] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+40h] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<Quaternion> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<Quaternion>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: (int)"channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    CDmeChannel::GetInputValue<Quaternion>(this: Value, value: &v);
    CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
      this: &values,
      src: &v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalStart, t: tStart, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalEnd, t: tEnd, bClamp: 0);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  nKeys = CDmeLog::GetKeyCount(this: v14);
  if ( nKeys <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          &src);
        v18 = CDmeTypedLog<Quaternion>::GetValue(this: v14, time: tLocalStart);
        CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: Referring, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        &src);
      KeyValue = CDmeTypedLog<Quaternion>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= nKeys )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    v22 = CDmeTypedLog<Quaternion>::GetValue(this: v14, time: tLocalEnd);
    CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddToTail(
      this: &values,
      src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C140
// Name: void AddKeysToPreset<float>(class CDmePreset __near *,char const __near *,char const __near *,class CDmElement const __near *,char const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddKeysToPreset<float>(
        CDmePreset *pPreset,
        const char *pValuesAttrName,
        const char *pTimesAttrName,
        CDmElement *pControl,
        const char *pChannelAttrName,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  CDmePreset *v8; // ebx
  CDmElement *v9; // esi
  CDmeChannel *Value; // edi
  const char *m_pAsString; // eax
  CDmElement *v12; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<float> *v14; // esi
  CDmeChannelsClip *Referring; // ebx
  int v16; // edi
  int m_tms; // eax
  float *v18; // eax
  float *KeyValue; // eax
  int m_Size; // eax
  DmeTime_t *p_tEnd; // eax
  float *v22; // eax
  CDmrArray<float> values; // [esp+Ch] [ebp-28h] BYREF
  CDmrArray<DmeTime_t> times; // [esp+14h] [ebp-20h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-18h] BYREF
  int v; // [esp+20h] [ebp-14h] BYREF
  DmeTime_t src; // [esp+24h] [ebp-10h] BYREF
  DmeTime_t tLocalEnd; // [esp+28h] [ebp-Ch] BYREF
  DmeTime_t t; // [esp+2Ch] [ebp-8h] BYREF
  DmeTime_t tLocalStart; // [esp+30h] [ebp-4h] BYREF

  v8 = pPreset;
  if ( pPreset == nullptr )
    return;
  v9 = pControl;
  if ( pControl == nullptr )
    return;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: pChannelAttrName);
  if ( Value == nullptr )
    return;
  m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v12 = CDmePreset::FindOrAddControlValue(this: v8, pControlName: m_pAsString);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &values,
    pElement: v12,
    pAttributeName: pValuesAttrName,
    bAddAttribute: true);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &times);
  CDmrDecorator<DmeTime_t,CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>>::Init(
    this: &times,
    pElement: v12,
    pAttributeName: pTimesAttrName,
    bAddAttribute: true);
  Log = CDmeChannel::GetLog(this: Value);
  v14 = (CDmeTypedLog<float> *)Log;
  if ( Log == nullptr || !Log->IsA(this: Log, a2: CDmeTypedLog<float>::m_classType) )
    v14 = nullptr;
  Referring = FindReferringElement<CDmeChannelsClip>(
                pElement: (CExpressionCalculator *)&Value->CDmElement,
                pAttrName: (int)"channels",
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( v14 == nullptr || CDmeLog::IsEmpty(this: v14) != 0 || Referring == nullptr )
  {
    pPreset = nullptr;
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    CDmeChannel::GetInputValue<float>(this: Value, value: (float *)&v);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
      this: &values,
      src: (float *)&v);
    return;
  }
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalStart, t: tStart, bClamp: 0);
  CDmeClip::ToChildMediaTime(this: Referring, result: &tLocalEnd, t: tEnd, bClamp: 0);
  HIBYTE(pPreset) = 1;
  v16 = 0;
  v = CDmeLog::GetKeyCount(this: v14);
  if ( v <= 0 )
    return;
  while ( 1 )
  {
    v14->GetKeyTime(this: v14, result: &t, a3: v16);
    m_tms = t.m_tms;
    if ( t.m_tms >= tLocalStart.m_tms )
    {
      if ( HIBYTE(pPreset) != 0 )
      {
        HIBYTE(pPreset) = 0;
        src.m_tms = tStart.m_tms - tHead.m_tms;
        CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
          this: &times,
          &src);
        v18 = CDmeTypedLog<float>::GetValue(this: v14, a2: (int)Referring, a3: v16, time: tLocalStart);
        CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
          this: &values,
          src: v18);
        m_tms = t.m_tms;
        if ( t.m_tms == tLocalStart.m_tms )
          goto LABEL_18;
      }
      if ( m_tms >= tLocalEnd.m_tms )
        break;
      t.m_tms = CDmeClip::FromChildMediaTime(this: Referring, &result, t: (DmeTime_t)m_tms, bClamp: false)->m_tms;
      src.m_tms = t.m_tms - tHead.m_tms;
      CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
        this: &times,
        &src);
      KeyValue = CDmeTypedLog<float>::GetKeyValue(this: v14, nKeyIndex: v16);
      CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &values,
        src: KeyValue);
    }
LABEL_18:
    if ( ++v16 >= v )
      return;
  }
  m_Size = times.m_pStorage->m_Size;
  if ( m_Size <= 0 )
    p_tEnd = &tEnd;
  else
    p_tEnd = &times.m_pStorage->m_Memory.m_pMemory[m_Size - 1];
  if ( p_tEnd->m_tms <= tLocalEnd.m_tms )
  {
    pPreset = (CDmePreset *)(tEnd.m_tms - tHead.m_tms);
    CDmaArrayBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::AddToTail(
      this: &times,
      src: (const DmeTime_t *)&pPreset);
    v22 = CDmeTypedLog<float>::GetValue(this: v14, a2: (int)Referring, a3: v16, time: tLocalEnd);
    CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(this: &values, src: v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C370
// Name: public: virtual void CBaseAnimationSetControl::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::OnControlsAddedOrRemoved(CBaseAnimationSetControl *this)
{
  int m_Head; // edi
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *p_m_SelectionHistory; // esi
  unsigned __int16 v3; // bx
  const CDmElement *v4; // eax
  CDmeControlGroup *GroupContainingControl; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  SelectionInfo_t *psi; // [esp+4h] [ebp-Ch]
  CBaseAnimationSetControl *v8; // [esp+8h] [ebp-8h]
  bool bSelectionChanged; // [esp+Fh] [ebp-1h]

  m_Head = this->m_SelectionHistory.m_Head;
  v8 = this;
  this->m_nDominantSlider = -1;
  bSelectionChanged = false;
  if ( m_Head != 0xFFFF )
  {
    p_m_SelectionHistory = &this->m_SelectionHistory;
    do
    {
      psi = p_m_SelectionHistory->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element;
      v3 = m_Head;
      m_Head = p_m_SelectionHistory->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      v4 = (const CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                 a1: g_pDataModel.u,
                                 a2: psi->m_hControl.m_handle);
      if ( v4 != nullptr )
      {
        if ( v8->m_bShowHiddenControls )
          continue;
        GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl: v4);
        if ( GroupContainingControl != nullptr && CDmeControlGroup::IsVisible(this: GroupContainingControl) )
          continue;
      }
      psi->m_nComponentFlags = TRANSFORM_COMPONENT_NONE;
      CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::Unlink(
        this: p_m_SelectionHistory,
        elem: v3);
      p_m_SelectionHistory->m_Memory.m_pMemory[v3].m_Next = p_m_SelectionHistory->m_FirstFree;
      p_m_SelectionHistory->m_FirstFree = v3;
      bSelectionChanged = true;
    }
    while ( m_Head != 0xFFFF );
    if ( bSelectionChanged
      && ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      v8->FireControlSelectionChangedListeners(this: v8);
    }
    this = v8;
  }
  PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: this->m_pEditor);
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this: PresetFader, bChanged: false);
}

//------------------------------------------------------------------------------
// Address: 0x0047C460
// Name: public: enum SelectionState_t CBaseAnimationSetControl::GetSelectionState(class CDmeAnimationSet __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimationSetControl::GetSelectionState(CBaseAnimationSetControl *this, CDmeAnimationSet *pAnimSet)
{
  CDmeControlGroup *RootControlGroup; // eax

  if ( pAnimSet == nullptr )
    return 0;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  return CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: RootControlGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0047C490
// Name: void SetPresetFromControlChannels(class CDmePreset __near *,class CDmElement const __near *,class DmeTime_t,class DmeTime_t,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPresetFromControlChannels(
        CDmePreset *pPreset,
        CDmElement *pControl,
        DmeTime_t tHead,
        DmeTime_t tStart,
        DmeTime_t tEnd)
{
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    AddKeysToPreset<Vector>(
      pPreset,
      pValuesAttrName: "valuePositions",
      pTimesAttrName: "timePositions",
      pControl,
      pChannelAttrName: "positionChannel",
      tHead,
      tStart,
      tEnd);
    AddKeysToPreset<Quaternion>(
      pPreset,
      pValuesAttrName: "valueOrientations",
      pTimesAttrName: "timeOrientations",
      pControl,
      pChannelAttrName: "orientationChannel",
      tHead,
      tStart,
      tEnd);
  }
  if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
  {
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "leftValues",
      pTimesAttrName: "leftTimes",
      pControl,
      pChannelAttrName: "leftvaluechannel",
      tHead,
      tStart,
      tEnd);
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "rightValues",
      pTimesAttrName: "rightTimes",
      pControl,
      pChannelAttrName: "rightvaluechannel",
      tHead,
      tStart,
      tEnd);
  }
  else
  {
    AddKeysToPreset<float>(
      pPreset,
      pValuesAttrName: "values",
      pTimesAttrName: "times",
      pControl,
      pChannelAttrName: "channel",
      tHead,
      tStart,
      tEnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C580
// Name: protected: void CBaseAnimationSetControl::AddPreset(class CDmeAnimationSet __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddPreset(
        CBaseAnimationSetControl *this,
        CDmeAnimationSet *pAnimSet,
        const char *pPresetGroupName,
        const char *pPresetName,
        int bAnimated)
{
  CDmePresetGroup *v6; // eax
  const char *v7; // ebx
  CDmePresetGroup *v8; // esi
  CDmePreset *v9; // esi
  void (__thiscall *GetAnimatedPresetTimeParameters)(CBaseAnimationSetControl *, DmeTime_t *, DmeTime_t *, DmeTime_t *); // edx
  CDmAttribute *Attribute; // eax
  int i; // eax
  int v13; // esi
  SelectionInfo_t *m_Element; // ebx
  int BufferType; // eax
  CDmElement *v16; // eax
  int j; // eax
  int v18; // esi
  SelectionInfo_t *v19; // ebx
  int v20; // eax
  CDmeTransformControl *v21; // eax
  CDmePreset *pPreset; // [esp+Ch] [ebp-8h]
  DmeTime_t tHead; // [esp+10h] [ebp-4h] BYREF

  v6 = CDmeAnimationSet::FindOrAddPresetGroup(this: pAnimSet, pGroupName: pPresetGroupName);
  v7 = pPresetName;
  v8 = v6;
  if ( CDmePresetGroup::FindPreset(this: v6, pPresetName) == nullptr )
  {
    v9 = CDmePresetGroup::FindOrAddPreset(this: v8, pPresetName: v7);
    pPreset = v9;
    if ( (_BYTE)bAnimated != 0 )
    {
      GetAnimatedPresetTimeParameters = this->GetAnimatedPresetTimeParameters;
      tHead.m_tms = 0x80000000;
      pPresetName = (const char *)0x80000000;
      pPresetGroupName = (const char *)0x80000000;
      GetAnimatedPresetTimeParameters(
        this,
        a2: &tHead,
        a3: (DmeTime_t *)&pPresetName,
        a4: (DmeTime_t *)&pPresetGroupName);
      HIBYTE(bAnimated) = 1;
      Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "animated");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v9, pAttributeName: "animated", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&bAnimated + 3);
      }
      for ( i = this->m_SelectionHistory.m_Head; i != 0xFFFF; i = this->m_SelectionHistory.m_Memory.m_pMemory[v13].m_Next )
      {
        v13 = (unsigned __int16)i;
        m_Element = this->m_SelectionHistory.m_Memory.m_pMemory[v13].m_Element;
        if ( pAnimSet != nullptr )
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
        else
          BufferType = -1;
        if ( m_Element->m_hAnimSet.m_handle == BufferType )
        {
          v16 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                a1: g_pDataModel.u,
                                a2: m_Element->m_hControl.m_handle);
          SetPresetFromControlChannels(
            pPreset,
            pControl: v16,
            tHead,
            tStart: (DmeTime_t)pPresetName,
            tEnd: (DmeTime_t)pPresetGroupName);
        }
      }
    }
    else
    {
      for ( j = this->m_SelectionHistory.m_Head; j != 0xFFFF; j = this->m_SelectionHistory.m_Memory.m_pMemory[v18].m_Next )
      {
        v18 = (unsigned __int16)j;
        v19 = this->m_SelectionHistory.m_Memory.m_pMemory[v18].m_Element;
        if ( pAnimSet != nullptr )
          v20 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimSet);
        else
          v20 = -1;
        if ( v19->m_hAnimSet.m_handle == v20 )
        {
          v21 = (CDmeTransformControl *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                          a1: g_pDataModel.u,
                                          a2: v19->m_hControl.m_handle);
          SetPresetFromControl(pPreset, pControl: v21);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C700
// Name: public: void CBaseAnimationSetControl::UpdateDominantSliderStartValues(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdateDominantSliderStartValues(
        CBaseAnimationSetControl *this,
        bool restoreSliderValues)
{
  CBaseAnimationSetControl *v2; // esi
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // eax
  CBaseAnimSetAttributeSliderPanel *v4; // edi
  int m_Size; // ebx
  int v6; // eax
  int v7; // ebx
  CAttributeSlider *v8; // edi
  AttributeValue_t *v9; // esi
  int nSliders; // [esp+8h] [ebp-10h]
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v2 = this;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: this->m_pEditor);
  v4 = AttributeSlider;
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    m_Size = AttributeSlider->m_SliderList.m_Size;
    nSliders = m_Size;
    if ( v2->m_DominantSliderStartValues.m_Size == m_Size
      || (v2->m_DominantSliderStartValues.m_Size = 0,
          CUtlVector<AttributeValue_t,CUtlMemory<AttributeValue_t,int>>::InsertMultipleBefore(
            this: &v2->m_DominantSliderStartValues,
            elem: 0,
            num: m_Size),
          !restoreSliderValues) )
    {
      v6 = 0;
      i = 0;
      if ( m_Size > 0 )
      {
        v7 = 0;
        while ( 1 )
        {
          v8 = v4->m_SliderList.m_Memory.m_pMemory[v6];
          if ( v8 != nullptr && v8->IsVisible(this: v8) )
          {
            if ( restoreSliderValues )
            {
              if ( v8->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
                CAttributeSlider::SetValue(this: v8, value: &v2->m_DominantSliderStartValues.m_Memory.m_pMemory[v7]);
            }
            else
            {
              v9 = &v2->m_DominantSliderStartValues.m_Memory.m_pMemory[v7];
              *v9 = *CAttributeSlider::GetValue(this: v8);
              v2 = this;
            }
          }
          v6 = i + 1;
          ++v7;
          i = v6;
          if ( v6 >= nSliders )
            break;
          v4 = pAttributeSlider;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C940
// Name: public: bool CBaseAnimationSetControl::SelectControl(class CDmElement const __near *,enum ESelectionMode,enum TransformComponent_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimationSetControl::SelectControl(
        CBaseAnimationSetControl *this,
        const CDmElement *pControl,
        ESelectionMode selectionMode,
        TransformComponent_t nComponentFlags,
        bool bExpandTree)
{
  CDmeControlGroup *GroupContainingControl; // eax
  SelectionInfo_t *v8; // eax
  SelectionInfo_t *v9; // esi
  int i; // esi
  IAnimationSetControlSelectionChangedListener *v11; // ecx
  SelectionInfo_t *psi; // [esp+Ch] [ebp-4h] BYREF

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  if ( pControl != nullptr )
  {
    if ( (this->m_bShowHiddenControls
       || (GroupContainingControl = CDmeControlGroup::FindGroupContainingControl(pControl)) != nullptr
       && CDmeControlGroup::IsVisible(this: GroupContainingControl)
       || selectionMode == SELECTION_REMOVE)
      && (v8 = this->FindSelectionInfoForControl(this, a2: pControl), v9 = v8, psi = v8, v8 != nullptr) )
    {
      if ( selectionMode != SELECTION_SET )
      {
        if ( v8->m_nComponentFlags != TRANSFORM_COMPONENT_NONE )
          CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::FindAndRemove(
            this: &this->m_SelectionHistory,
            src: &psi);
        switch ( selectionMode )
        {
          case SELECTION_ADD:
            v9->m_nComponentFlags |= nComponentFlags;
            break;
          case SELECTION_REMOVE:
            v9->m_nComponentFlags &= ~nComponentFlags;
            break;
          case SELECTION_TOGGLE:
            v9->m_nComponentFlags ^= nComponentFlags;
            break;
          default:
            break;
        }
      }
      else
      {
        CBaseAnimationSetControl::ClearSelection(this);
        v9->m_nComponentFlags = nComponentFlags;
      }
      if ( v9->m_nComponentFlags != TRANSFORM_COMPONENT_NONE )
      {
        CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AddToTail(
          this: &this->m_SelectionHistory,
          src: &psi);
        if ( bExpandTree )
        {
          for ( i = 0; i < this->m_ControlSelectionChangedListeners.m_Size; ++i )
          {
            v11 = this->m_ControlSelectionChangedListeners.m_Memory.m_pMemory[i];
            v11->ExpandTreeToControl(this: v11, a2: pControl, a3: nComponentFlags);
          }
        }
      }
      if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
        && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
      {
        this->FireControlSelectionChangedListeners(this);
      }
      return 1;
    }
    else
    {
      if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
        && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
      {
        this->FireControlSelectionChangedListeners(this);
      }
      return 0;
    }
  }
  else
  {
    if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      this->FireControlSelectionChangedListeners(this);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CA80
// Name: public: void CBaseAnimationSetControl::SelectControlGroup(class CDmeControlGroup __near *,enum ESelectionMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SelectControlGroup(
        CBaseAnimationSetControl *this,
        CDmeControlGroup *pGroup,
        ESelectionMode selectionMode)
{
  CBaseAnimationSetControl *v3; // edi
  int v4; // esi
  CDmElement **m_pMemory; // eax
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > list; // [esp+Ch] [ebp-18h] BYREF
  CBaseAnimationSetControl *v8; // [esp+20h] [ebp-4h]

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  v3 = this;
  v8 = this;
  if ( pGroup != nullptr )
  {
    list.m_Memory.m_pMemory = nullptr;
    list.m_Memory.m_nAllocationCount = 32;
    list.m_Memory.m_nGrowSize = 0;
    list.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
    list.m_Size = 0;
    list.m_pElements = list.m_Memory.m_pMemory;
    CDmeControlGroup::GetControlsInGroup(this: pGroup, controlList: &list, recursive: true);
    v4 = list.m_Size - 1;
    if ( list.m_Size - 1 >= 0 )
    {
      do
      {
        if ( CBaseAnimationSetControl::SelectControl(
               this: v8,
               pControl: list.m_Memory.m_pMemory[v4],
               selectionMode,
               nComponentFlags: TRANSFORM_COMPONENT_ALL,
               bExpandTree: false) != 0
          && selectionMode == SELECTION_SET )
        {
          selectionMode = SELECTION_ADD;
        }
        --v4;
      }
      while ( v4 >= 0 );
      v3 = v8;
    }
    m_pMemory = list.m_Memory.m_pMemory;
    list.m_Size = 0;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( list.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    list.m_pElements = m_pMemory;
    if ( list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        list.m_Memory.m_pMemory = nullptr;
      }
      list.m_Memory.m_nAllocationCount = 0;
    }
    if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
      && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
    {
      v3->FireControlSelectionChangedListeners(this: v3);
    }
  }
  else if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
         && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    this->FireControlSelectionChangedListeners(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CBB0
// Name: public: void CBaseAnimationSetControl::SelectAnimationSet(class CDmeAnimationSet __near *,enum ESelectionMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::SelectAnimationSet(
        CBaseAnimationSetControl *this,
        CDmeAnimationSet *pAnimSet,
        int selectionMode)
{
  CDmeAnimationSet *v3; // ebx
  CBaseAnimationSetControl *v4; // esi
  CDmeControlGroup *RootControlGroup; // eax
  int v6; // ebx
  CDmeDag **m_pMemory; // eax
  CDmeDag *v8; // ecx
  CDmeTransformControl *TransformControl; // eax
  int v10; // eax
  int v11; // edi
  CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> > *p_m_SelectionHistory; // esi
  unsigned __int16 v13; // ax
  int v14; // ebx
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *v15; // eax
  ESelectionMode v16; // [esp-4h] [ebp-28h]
  CUtlVector<CDmeDag *,CUtlMemory<CDmeDag *,int> > rootDagNodes; // [esp+Ch] [ebp-18h] BYREF
  CBaseAnimationSetControl *v18; // [esp+20h] [ebp-4h]

  ++CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth;
  v3 = pAnimSet;
  v4 = this;
  v16 = selectionMode;
  v18 = this;
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: pAnimSet);
  CBaseAnimationSetControl::SelectControlGroup(this: v4, pGroup: RootControlGroup, selectionMode: v16);
  memset(&rootDagNodes, 0, sizeof(rootDagNodes));
  CDmeAnimationSet::FindRootDagNodes(this: v3, rootDagNodeList: &rootDagNodes);
  v6 = 0;
  selectionMode = rootDagNodes.m_Size;
  if ( rootDagNodes.m_Size > 0 )
  {
    m_pMemory = rootDagNodes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = m_pMemory[v6];
      if ( v8 != nullptr )
      {
        TransformControl = CDmeDag::FindTransformControl(this: v8);
        v10 = (int)v4->FindSelectionInfoForControl(this: v4, a2: TransformControl);
        v11 = v10;
        pAnimSet = (CDmeAnimationSet *)v10;
        if ( v10 != 0 && *(_DWORD *)(v10 + 8) != 0 )
        {
          p_m_SelectionHistory = &v4->m_SelectionHistory;
          CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::FindAndRemove(
            this: p_m_SelectionHistory,
            src: (SelectionInfo_t **)&pAnimSet);
          v13 = CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::AllocInternal(
                  this: p_m_SelectionHistory,
                  multilist: false);
          v14 = v13;
          if ( v13 != 0xFFFF )
          {
            CUtlLinkedList<SelectionInfo_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>>::LinkBefore(
              this: p_m_SelectionHistory,
              before: 0xFFFFu,
              elem: v13);
            v15 = &p_m_SelectionHistory->m_Memory.m_pMemory[v14];
            if ( v15 != nullptr )
              v15->m_Element = (SelectionInfo_t *)v11;
          }
          v4 = v18;
          break;
        }
        m_pMemory = rootDagNodes.m_Memory.m_pMemory;
      }
      if ( ++v6 >= selectionMode )
        goto LABEL_14;
    }
  }
  m_pMemory = rootDagNodes.m_Memory.m_pMemory;
LABEL_14:
  rootDagNodes.m_Size = 0;
  if ( rootDagNodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      rootDagNodes.m_Memory.m_pMemory = nullptr;
    }
    rootDagNodes.m_Memory.m_nAllocationCount = 0;
  }
  rootDagNodes.m_pElements = m_pMemory;
  if ( rootDagNodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      rootDagNodes.m_Memory.m_pMemory = nullptr;
    }
    rootDagNodes.m_Memory.m_nAllocationCount = 0;
  }
  if ( CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth > 0
    && --CNotifyAnimationSetControlSelectionChangedScopeGuard::m_nDepth == 0 )
  {
    v4->FireControlSelectionChangedListeners(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CCF0
// Name: public: void CBaseAnimationSetControl::AddPreset(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::AddPreset(
        CBaseAnimationSetControl *this,
        const char *pPresetGroupName,
        const char *pPresetName,
        int bAnimated)
{
  CDmeAnimationSet *i; // esi
  CDmeControlGroup *RootControlGroup; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 256))(
    a1: g_pDataModel.u,
    a2: "Add Preset",
    a3: "Add Preset",
    a4: 0);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 460))(
    a1: g_pDataModel.u,
    a2: "Add Preset",
    a3: 0,
    a4: 256);
  traversal.m_pFilmClip = (CDmeFilmClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                            a1: g_pDataModel.u,
                                            a2: this->m_hFilmClip.m_handle);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: i);
    if ( (unsigned int)CBaseAnimationSetControl::GetSelectionState(this, pControlGroup: RootControlGroup) >= 2 )
      CBaseAnimationSetControl::AddPreset(this, pAnimSet: i, pPresetGroupName, pPresetName, bAnimated);
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0047CDD0
// Name: public: void CBaseAnimationSetControl::UpdatePreviewSliderTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::UpdatePreviewSliderTimes(CBaseAnimationSetControl *this)
{
  CBaseAnimationSetControl *v1; // ebx
  CBaseAnimationSetEditor *m_pEditor; // ecx
  CBaseAnimSetAttributeSliderPanel *AttributeSlider; // esi
  bool v4; // al
  bool v5; // al
  unsigned int v6; // edi
  vgui::IPanel *v7; // esi
  vgui::IPanel_vtbl *v8; // ebx
  int v9; // eax
  bool v10; // al
  vgui::PHandle *p_m_ActiveAttributeSlider; // esi
  int SliderIndexForControl; // edi
  int m_nDominantSlider; // eax
  CAttributeSlider *v14; // ebx
  bool v15; // zf
  vgui::Panel *v16; // eax
  const CDmElement *v17; // eax
  CAttributeSlider *v18; // eax
  int my; // [esp+8h] [ebp-14h] BYREF
  int mx; // [esp+Ch] [ebp-10h] BYREF
  CBaseAnimSetAttributeSliderPanel *pAttributeSlider; // [esp+10h] [ebp-Ch]
  CBaseAnimationSetControl *v22; // [esp+14h] [ebp-8h]
  bool shiftDown; // [esp+1Ah] [ebp-2h]
  bool ctrlDown; // [esp+1Bh] [ebp-1h]

  v1 = this;
  m_pEditor = this->m_pEditor;
  v22 = v1;
  AttributeSlider = CBaseAnimationSetEditor::GetAttributeSlider(this: m_pEditor);
  pAttributeSlider = AttributeSlider;
  if ( AttributeSlider != nullptr )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL), ctrlDown = false, v4) )
    {
      ctrlDown = true;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || (v5 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v5) )
    {
      shiftDown = true;
    }
    if ( ctrlDown )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
      if ( !vgui::Panel::IsWithin(this: AttributeSlider, x: mx, y: my) )
      {
        shiftDown = false;
        ctrlDown = false;
      }
      v6 = g_pVGuiInput->GetMouseOver(this: g_pVGuiInput);
      if ( v6 != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = pAttributeSlider->GetVPanel(this: pAttributeSlider);
        v10 = v8->HasParent(this: v7, a2: v6, a3: v9);
        v1 = v22;
        if ( !v10 )
        {
          shiftDown = false;
          ctrlDown = false;
        }
      }
    }
    LOBYTE(mx) = (*((_BYTE *)v1 + 104) & 2) != 0
              || vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr && shiftDown;
    LOBYTE(my) = (*((_BYTE *)v1 + 104) & 1) != 0
              || vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr
              && vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2;
    p_m_ActiveAttributeSlider = &v1->m_ActiveAttributeSlider;
    SliderIndexForControl = -1;
    if ( vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider) != nullptr
      && vgui::PHandle::Get(this: &v1->m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2 )
    {
      if ( ctrlDown
        || (m_nDominantSlider = v1->m_nDominantSlider) >= 0
        && (v14 = pAttributeSlider->m_SliderList.m_Memory.m_pMemory[m_nDominantSlider],
            v15 = v14 == vgui::PHandle::Get(this: p_m_ActiveAttributeSlider),
            v1 = v22,
            v15) )
      {
        v16 = vgui::PHandle::Get(this: p_m_ActiveAttributeSlider);
        v17 = (const CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                                    a1: g_pDataModel.u,
                                    a2: v16[1]._panelName.m_Storage.m_Memory.m_nGrowSize);
        SliderIndexForControl = CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(
                                  this: pAttributeSlider,
                                  control: v17);
      }
    }
    if ( SliderIndexForControl != v1->m_nDominantSlider )
    {
      CBaseAnimationSetControl::UpdateDominantSliderStartValues(
        this: v1,
        restoreSliderValues: SliderIndexForControl < 0);
      v1->m_nDominantSlider = SliderIndexForControl;
    }
    if ( vgui::PHandle::Get(this: p_m_ActiveAttributeSlider) != nullptr
      && vgui::PHandle::Get(this: p_m_ActiveAttributeSlider)[1]._panelName.m_Storage.m_nActualLength == 2 )
    {
      v18 = (CAttributeSlider *)vgui::PHandle::Get(this: p_m_ActiveAttributeSlider);
    }
    else
    {
      v18 = nullptr;
    }
    pAttributeSlider->UpdateControlSetMode(this: pAttributeSlider, a2: my, a3: mx, a4: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D060
// Name: public: virtual void CBaseAnimationSetControl::ProceduralPreset_UpdateCrossfade(class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetControl::ProceduralPreset_UpdateCrossfade(
        CBaseAnimationSetControl *this,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *pPresetValuesLookup,
        int nPresetType)
{
  CBaseAnimationSetControl *v4; // edi
  int m_ElementCount; // eax
  int v6; // xmm0_4
  CDmElement *v7; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // edx
  SelectionInfo_t *m_Element; // eax
  int (__thiscall *v16)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  CDmElement *v17; // eax
  int v18; // ecx
  CDmElement *v19; // esi
  DmElementHandle_t BufferType; // edi
  unsigned __int16 v21; // ax
  AnimationControlAttributes_t *p_elem; // edi
  CDmElement *v23; // ecx
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // ecx
  const Vector *DefaultPosition; // eax
  CDmAttribute *v27; // eax
  CDmAttribute *v28; // esi
  const Quaternion *DefaultOrientation; // eax
  CDmAttribute *v30; // eax
  CDmAttribute *v31; // eax
  CDmAttribute *v32; // esi
  CDmAttribute *v33; // ecx
  CDmAttribute *v34; // eax
  CDmAttribute *v35; // esi
  CDmaVar<float> *v36; // eax
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t insert; // [esp+Ch] [ebp-CCh] BYREF
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t search; // [esp+60h] [ebp-78h] BYREF
  CDisableUndoScopeGuard guard; // [esp+B4h] [ebp-24h]
  int v40; // [esp+BCh] [ebp-1Ch]
  float flDefaultValue; // [esp+C0h] [ebp-18h] BYREF
  int pcvi; // [esp+C4h] [ebp-14h]
  SelectionInfo_t *psi; // [esp+C8h] [ebp-10h]
  CBaseAnimationSetControl *v44; // [esp+CCh] [ebp-Ch]
  CDmAttribute *pLeftValueAttribute; // [esp+D0h] [ebp-8h]
  CDmElement *pControl; // [esp+D4h] [ebp-4h] BYREF
  bool bSinglePreset_3; // [esp+E7h] [ebp+Fh]

  v4 = this;
  v44 = this;
  if ( nPresetType >= 5 && nPresetType <= 7 )
    return;
  guard.m_bOldValue = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  bSinglePreset_3 = nPresetType != 1;
  m_ElementCount = 1;
  if ( nPresetType == 1 )
    m_ElementCount = v4->m_SelectionHistory.m_ElementCount;
  CBaseAnimationSetControl::EnsureCrossfadePresetControlValues(this: v4, nCount: m_ElementCount);
  v6 = 0;
  if ( bSinglePreset_3 )
  {
    pControl = nullptr;
    if ( nPresetType != 2 )
    {
      if ( nPresetType == 3 )
      {
        v6 = 1056964608;
      }
      else
      {
        if ( nPresetType != 4 )
          goto LABEL_12;
        v6 = 1065353216;
      }
    }
    pControl = (CDmElement *)v6;
LABEL_12:
    v7 = *v4->m_crossfadePresetControlValues.m_Memory.m_pMemory;
    Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "valuePosition");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v7, pAttributeName: "valuePosition", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: Attribute, value: &vec3_origin);
    }
    v9 = CDmElement::FindAttribute(this: v7, pAttributeName: "valueOrientation");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: v7, pAttributeName: "valueOrientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v9, value: &quat_identity);
    }
    v10 = CDmElement::FindAttribute(this: v7, pAttributeName: "leftValue");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v10, value: (const float *)&pControl);
    }
    v11 = CDmElement::FindAttribute(this: v7, pAttributeName: "rightValue");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v7, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v11, value: (const float *)&pControl);
    }
    v12 = CDmElement::FindAttribute(this: v7, pAttributeName: "value");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(this: v7, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v12, value: (const float *)&pControl);
    }
  }
  CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &pPresetValuesLookup->m_Tree);
  m_Head = v4->m_SelectionHistory.m_Head;
  pcvi = -1;
  if ( m_Head != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = v4->m_SelectionHistory.m_Memory.m_pMemory;
      v40 = 8 * (unsigned __int16)m_Head;
      m_Element = m_pMemory[v40 / 8u].m_Element;
      v16 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72);
      psi = m_Element;
      v17 = (CDmElement *)((int (__thiscall *)(_DWORD, _DWORD))v16)(
                            a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                            a2: m_Element->m_hControl.m_handle);
      pControl = v17;
      if ( v17 != nullptr )
        break;
LABEL_71:
      m_Head = v4->m_SelectionHistory.m_Memory.m_pMemory[v40 / 8u].m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_72;
    }
    if ( bSinglePreset_3 )
      v18 = 0;
    else
      v18 = ++pcvi;
    v19 = v4->m_crossfadePresetControlValues.m_Memory.m_pMemory[v18];
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
    memset(&search.elem, 0, 24);
    search.elem.m_Quaternion = quat_identity;
    memset(search.elem.m_pValueAttribute, 0, 40);
    search.key = BufferType;
    v21 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &pPresetValuesLookup->m_Tree,
            &search);
    if ( v21 == 0xFFFF )
    {
      memset(&insert.elem, 0, 24);
      insert.elem.m_Quaternion = quat_identity;
      memset(insert.elem.m_pValueAttribute, 0, 40);
      insert.key = BufferType;
      v21 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
              this: &pPresetValuesLookup->m_Tree,
              &insert);
    }
    p_elem = &pPresetValuesLookup->m_Tree.m_Elements.m_pMemory[v21].m_Data.elem;
    _V_memset(dest: p_elem, fill: 0, count: 80);
    v23 = pControl;
    p_elem->m_Quaternion = quat_identity;
    if ( !v23->IsA(this: v23, a2: CDmeTransformControl::m_classType) )
    {
      if ( CDmElement::HasAttribute(this: pControl, pAttributeName: "rightValue", type: AT_UNKNOWN) )
      {
        v30 = CDmElement::FindAttribute(this: v19, pAttributeName: "leftValue");
        if ( v30 != nullptr )
          pLeftValueAttribute = (v30->m_nFlags & 0x1F) != 3 ? nullptr : v30;
        else
          pLeftValueAttribute = CDmElement::CreateAttribute(this: v19, pAttributeName: "leftValue", type: AT_FLOAT);
        v31 = CDmElement::FindAttribute(this: v19, pAttributeName: "rightValue");
        if ( v31 != nullptr )
          v32 = (v31->m_nFlags & 0x1F) != 3 ? nullptr : v31;
        else
          v32 = CDmElement::CreateAttribute(this: v19, pAttributeName: "rightValue", type: AT_FLOAT);
        v33 = pLeftValueAttribute;
        if ( pLeftValueAttribute != nullptr && v32 != nullptr )
        {
          if ( !bSinglePreset_3 )
          {
            flDefaultValue = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue")->m_Storage;
            CDmAttribute::SetValue<float>(this: pLeftValueAttribute, value: &flDefaultValue);
            CDmAttribute::SetValue<float>(this: v32, value: &flDefaultValue);
            v33 = pLeftValueAttribute;
          }
          p_elem->m_pValueAttribute[2] = v33;
          p_elem->m_pValue[2] = *CDmAttribute::GetValue<float>(this: v33);
          p_elem->m_pValueAttribute[1] = v32;
          p_elem->m_pValue[1] = *CDmAttribute::GetValue<float>(this: v32);
        }
      }
      else
      {
        v34 = CDmElement::FindAttribute(this: v19, pAttributeName: "value");
        if ( v34 != nullptr )
          v35 = (v34->m_nFlags & 0x1F) != 3 ? nullptr : v34;
        else
          v35 = CDmElement::CreateAttribute(this: v19, pAttributeName: "value", type: AT_FLOAT);
        if ( v35 != nullptr )
        {
          if ( !bSinglePreset_3 )
          {
            v36 = CDmElement::GetValue<float>(this: pControl, pAttributeName: "defaultValue");
            CDmAttribute::SetValue<float>(this: v35, value: &v36->m_Storage);
          }
          p_elem->m_pValueAttribute[0] = v35;
          p_elem->m_pValue[0] = *CDmAttribute::GetValue<float>(this: v35);
        }
      }
      goto LABEL_70;
    }
    if ( (psi->m_nComponentFlags & 7) != 0 )
    {
      v24 = CDmElement::FindAttribute(this: v19, pAttributeName: "valuePosition");
      if ( v24 != nullptr )
      {
        v25 = (v24->m_nFlags & 0x1F) != 10 ? nullptr : v24;
        pLeftValueAttribute = v25;
      }
      else
      {
        pLeftValueAttribute = CDmElement::CreateAttribute(this: v19, pAttributeName: "valuePosition", type: AT_VECTOR3);
        v25 = pLeftValueAttribute;
      }
      if ( v25 == nullptr )
      {
LABEL_70:
        v4 = v44;
        goto LABEL_71;
      }
      if ( !bSinglePreset_3 )
      {
        DefaultPosition = CDmeTransformControl::GetDefaultPosition(this: (CDmeTransformControl *)pControl);
        CDmAttribute::SetValue<Vector>(this: pLeftValueAttribute, value: DefaultPosition);
        v25 = pLeftValueAttribute;
      }
      p_elem->m_pValueAttribute[3] = v25;
      p_elem->m_Vector = CDmAttribute::GetValue<Vector>(this: v25)->m_Storage;
    }
    if ( (psi->m_nComponentFlags & 0x38) != 0 )
    {
      v27 = CDmElement::FindAttribute(this: v19, pAttributeName: "valueOrientation");
      v28 = v27 != nullptr
          ? ((v27->m_nFlags & 0x1F) != 13
           ? nullptr
           : v27)
          : CDmElement::CreateAttribute(this: v19, pAttributeName: "valueOrientation", type: AT_QUATERNION);
      if ( v28 != nullptr )
      {
        if ( !bSinglePreset_3 )
        {
          DefaultOrientation = CDmeTransformControl::GetDefaultOrientation(this: (CDmeTransformControl *)pControl);
          CDmAttribute::SetValue<Quaternion>(this: v28, value: DefaultOrientation);
        }
        p_elem->m_pValueAttribute[4] = v28;
        p_elem->m_Quaternion = *CDmAttribute::GetValue<Quaternion>(this: v28);
      }
    }
    goto LABEL_70;
  }
LABEL_72:
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: *(_DWORD *)&guard.m_bOldValue);
}

//------------------------------------------------------------------------------
// Address: 0x006AEF70
// Name: _dynamic_initializer_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeChannel::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeChannel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4940
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00478700
// Name: class Quaternion MaskValue<class Quaternion>(class Quaternion const __near &,class Quaternion const __near &,enum LogComponents_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Quaternion *__cdecl MaskValue<Quaternion>(
        Quaternion *result,
        const Quaternion *value,
        const Quaternion *curQuat,
        LogComponents_t componentFlags)
{
  QAngle curQA; // [esp+0h] [ebp-18h] BYREF
  QAngle valueQA; // [esp+Ch] [ebp-Ch] BYREF

  QuaternionAngles(q: curQuat, angles: &curQA);
  QuaternionAngles(q: value, angles: &valueQA);
  if ( (componentFlags & 1) == 0 )
    valueQA.x = curQA.x;
  if ( (componentFlags & 2) == 0 )
    valueQA.y = curQA.y;
  if ( (componentFlags & 4) == 0 )
    valueQA.z = curQA.z;
  AngleQuaternion(angles: &valueQA, outQuat: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AEFA0
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEFB0
// Name: _dynamic_initializer_for__g_CDmeChannel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeChannel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeChannel_Helper,
           classname: "DmeChannel",
           pFactory: &g_CDmeChannel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4950
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x006B4960
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace sceneviewer
