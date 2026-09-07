// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmechannel.cpp
// Functions: 38
// ============================================================

#include "movieobjects\dmechannel.h"

//------------------------------------------------------------------------------
// Address: 0x004B7240
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x004B7260
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B7300
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B7370
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B7390
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B73B0
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CExpressionCalculator *Log; // eax
  CExpressionCalculator *v4; // esi

  Log = (CExpressionCalculator *)CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CExpressionCalculator::VariableCount(this: Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B7400
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  CDmElement *v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == nullptr )
      goto LABEL_13;
    v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[2].OnElementSerialized)(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B74C0
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B7530
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7570
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x004B75A0
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
// Address: 0x004B75D0
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004B7740
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = GetAttribute_2(this: g_pDataModel, a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7820
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B7890
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004B78A0
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B78F0
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  IDataModel_vtbl *v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    noundo.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = g_pDataModel->__vftable;
  if ( Ptr == nullptr )
  {
    ((void (__stdcall *)(_DWORD))v9->SetUndoEnabled)(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = ((int (__stdcall *)(_DWORD))v9->GetElement)(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == nullptr
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x004B7A30
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B7AC0
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    GetElement = g_pDataModel->GetElement;
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = (int)GetElement(this: g_pDataModel, a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7C90
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7DA0
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B7E00
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeChannel *v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  CDmElement *v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)v4);
    if ( v5 != nullptr )
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
    else
      v6 = nullptr;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_FromAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_fromIndex.m_Storage, buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_toIndex.m_Storage, buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_fromElement.m_Storage.m_Handle);
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8000
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmElement::m_classType)
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004B80A0
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  CDmElement *(__thiscall *v20)(IDataModel *, DmElementHandle_t); // edx
  CDmeLogLayer *v21; // edi
  int KeyCount; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  CDmElement *v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)GetAttribute_2(this: g_pDataModel, a2: *((DmAttributeHandle_t *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35)) == nullptr && *((_DWORD *)v1 + 38) == -1 )
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    v5 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = g_pDataModel->GetElement;
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)v17(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                                         + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                                         + 4));
            v20 = g_pDataModel->GetElement;
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)v20(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: v21) <= 0 )
              goto LABEL_29;
            KeyCount = CDmeLogLayer::GetKeyCount(this: v21);
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) != KeyCount )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, CDmElement *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = CDmeTrack::GetClipCount(this: (CDmeVertexDataBase *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8610
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8650
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
      m_Size = attrs->m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: m_Size - m_nAllocationCount + 1);
      ++attrs->m_Size;
      m_pMemory = attrs->m_Memory.m_pMemory;
      v8 = attrs->m_Size - m_Size - 1;
      attrs->m_pElements = attrs->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = &attrs->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B86F0
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)((int (__thiscall *)(IDataModel *, DmAttributeHandle_t, int))g_pDataModel->GetAttribute_2)(
                           a1: g_pDataModel,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v11 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
        v12 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8840
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B8940
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8970
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B89C0
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x004B8A20
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005AC6C0
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
// Address: 0x005AFE10
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AC6F0
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC700
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
// Address: 0x005AFE20
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005AFE30
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0050D4B0
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x0050D4D0
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050D570
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050D5E0
// Name: public: class DmeTime_t CDmeChannel::GetCurrentTime(void)const
// Source: json
//------------------------------------------------------------------------------
DmeTime_t *__thiscall CDmeChannel::GetCurrentTime(CDmeChannel *this, DmeTime_t *result)
{
  result->m_tms = (int)this->m_TimeState.m_tCurrentTime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050D600
// Name: public: void CDmeChannel::SetCurrentTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetCurrentTime(CDmeChannel *this, DmeTime_t time)
{
  this->m_TimeState.m_tPreviousTime.m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
  this->m_TimeState.m_tCurrentTime = time;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0050D630
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0050D650
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0050D670
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CExpressionCalculator *Log; // eax
  CExpressionCalculator *v4; // esi

  Log = (CExpressionCalculator *)CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CCodecBuffer_Block::GetBufferType(this: Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0050D6C0
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  CDmElement *v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == nullptr )
      goto LABEL_13;
    v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[2].OnElementSerialized)(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050D780
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050D7F0
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050D830
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x0050D860
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0050D9D0
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = GetAttribute_2(this: g_pDataModel, a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050DAB0
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050DB20
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0050DB30
// Name: public: void CDmeChannel::SetMode(enum ChannelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetMode(CDmeChannel *this, ChannelMode_t mode)
{
  if ( mode != this->m_mode.m_Storage )
  {
    CDmAttribute::SetValue<int>(this: this->m_mode.m_pAttribute, value: (const int *)&mode);
    this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050DB70
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0050DBC0
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  IDataModel_vtbl *v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    noundo.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = g_pDataModel->__vftable;
  if ( Ptr == nullptr )
  {
    ((void (__stdcall *)(_DWORD))v9->SetUndoEnabled)(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = ((int (__stdcall *)(_DWORD))v9->GetElement)(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == nullptr
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x0050DD00
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0050DD90
// Name: void RemapFloatLogValues(class CDmeChannel __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapFloatLogValues(float pChannel, float flBias, float flScale)
{
  CDmeChannel *v3; // esi
  CDmeLog *v4; // eax
  CDmeLog *v5; // esi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // eax
  vgui::Panel *v8; // edi
  vgui::IBorder *KeyCount; // ebx
  int i; // esi
  float *KeyValue; // eax

  v3 = (CDmeChannel *)LODWORD(pChannel);
  if ( pChannel != 0.0 )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(LODWORD(pChannel) + 140)) == nullptr
      && v3->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this: v3);
    }
    v4 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_log.m_Storage.m_Handle);
    v5 = v4;
    if ( v4 != nullptr )
    {
      TopmostLayer = CDmeLog::GetTopmostLayer(this: v4);
      Layer = CDmeLog::GetLayer(this: v5, index: TopmostLayer);
      v8 = (vgui::Panel *)Layer;
      if ( Layer != nullptr && Layer->IsA(this: Layer, a2: CDmeTypedLogLayer<float>::m_classType) )
      {
        KeyCount = CDmeLogLayer::GetKeyCount(this: v8);
        for ( i = 0; i < (int)KeyCount; ++i )
        {
          KeyValue = CDmeTypedLogLayer<float>::GetKeyValue(this: (CDmeTypedLogLayer<float> *)v8, nKeyIndex: i);
          pChannel = (float)(*KeyValue * flScale) + flBias;
          CDmeTypedLogLayer<float>::SetKeyValue(this: (CDmeTypedLogLayer<float> *)v8, nKey: i, value: &pChannel);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050DE60
// Name: class CDmeChannel __near * FindChannelTargetingAttribute(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl FindChannelTargetingAttribute(CDmAttribute *pTargetAttr)
{
  CDmElement *m_pOwner; // ecx
  IDataModel_vtbl *v2; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v4; // edi
  CDmElement *v5; // esi
  CDmeChannel *v6; // esi
  CDmAttribute *v7; // eax

  if ( pTargetAttr == nullptr )
    return nullptr;
  m_pOwner = pTargetAttr->m_pOwner;
  if ( m_pOwner == nullptr )
    return nullptr;
  v2 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  if ( v4 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeChannel::m_classType) )
    {
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
      if ( v6 != nullptr )
      {
        v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
        if ( v7 == nullptr )
          v7 = CDmeChannel::SetupToAttribute(this: v6);
        if ( v7 == pTargetAttr )
          break;
      }
    }
    v4 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v4);
    if ( v4 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0050DF20
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    GetElement = g_pDataModel->GetElement;
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = (int)GetElement(this: g_pDataModel, a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050E0F0
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050E200
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0050E260
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeChannel *v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  CDmElement *v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)v4);
    if ( v5 != nullptr )
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
    else
      v6 = nullptr;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_FromAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_fromIndex.m_Storage, buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_toIndex.m_Storage, buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_fromElement.m_Storage.m_Handle);
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050E460
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmElement::m_classType)
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0050E500
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  CDmElement *(__thiscall *v20)(IDataModel *, DmElementHandle_t); // edx
  CDmeLogLayer *v21; // edi
  vgui::IBorder *KeyCount; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  CDmElement *v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)GetAttribute_2(this: g_pDataModel, a2: *((DmAttributeHandle_t *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35)) == nullptr && *((_DWORD *)v1 + 38) == -1 )
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    v5 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = g_pDataModel->GetElement;
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)v17(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                                         + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                                         + 4));
            v20 = g_pDataModel->GetElement;
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)v20(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( (int)CDmeLogLayer::GetKeyCount(this: (vgui::Panel *)sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( (int)CDmeLogLayer::GetKeyCount(this: (vgui::Panel *)v21) <= 0 )
              goto LABEL_29;
            KeyCount = CDmeLogLayer::GetKeyCount(this: (vgui::Panel *)v21);
            if ( CDmeLogLayer::GetKeyCount(this: (vgui::Panel *)sourceLayer) != KeyCount )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, CDmElement *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050EA70
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050EAB0
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(CDmeChannel *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_nAllocationCount;
      m_pMemory = (int)attrs[1].m_pMemory;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v7 = (CDmAttribute **)attrs->m_pMemory;
      v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
      v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050EB50
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)((int (__thiscall *)(IDataModel *, DmAttributeHandle_t, int))g_pDataModel->GetAttribute_2)(
                           a1: g_pDataModel,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v10 = (CDmAttribute **)attrs->m_pMemory;
        v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
        v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050ECA0
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050EDA0
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050EDD0
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050EE20
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x0050EE80
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104DE1A0
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x104DE1C0
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104DE260
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104DE2D0
// Name: public: class DmeTime_t CDmeChannel::GetCurrentTime(void)const
// Source: json
//------------------------------------------------------------------------------
DmeTime_t *__thiscall CDmeChannel::GetCurrentTime(CDmeChannel *this, DmeTime_t *result)
{
  result->m_tms = (int)this->m_TimeState.m_tCurrentTime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104DE2F0
// Name: public: void CDmeChannel::SetCurrentTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetCurrentTime(CDmeChannel *this, DmeTime_t time)
{
  this->m_TimeState.m_tPreviousTime.m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
  this->m_TimeState.m_tCurrentTime = time;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0;
}

//------------------------------------------------------------------------------
// Address: 0x104DE320
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x104DE340
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x104DE360
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CDmeTypedLog<Quaternion> *Log; // eax
  CDmeTypedLog<Quaternion> *v4; // esi

  Log = CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x104DE3B0
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  CDmElement *v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == nullptr )
      goto LABEL_13;
    v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[2].OnElementSerialized)(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104DE470
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104DE4E0
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DE520
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x104DE550
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x104DE6C0
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = GetAttribute_2(this: g_pDataModel, a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DE7A0
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x104DE810
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x104DE820
// Name: public: void CDmeChannel::SetMode(enum ChannelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetMode(CDmeChannel *this, ChannelMode_t mode)
{
  if ( mode != this->m_mode.m_Storage )
  {
    CDmAttribute::SetValue<int>(this: this->m_mode.m_pAttribute, value: (int *)&mode);
    this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DE860
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x104DE8B0
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  IDataModel_vtbl *v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    noundo.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = g_pDataModel->__vftable;
  if ( Ptr == nullptr )
  {
    ((void (__stdcall *)(_DWORD))v9->SetUndoEnabled)(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = ((int (__stdcall *)(_DWORD))v9->GetElement)(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == nullptr
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x104DE9F0
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x104DEA80
// Name: void RemapFloatLogValues(class CDmeChannel __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapFloatLogValues(float pChannel, float flBias, float flScale)
{
  CDmeChannel *v3; // esi
  CDmeLog *v4; // eax
  CDmeLog *v5; // esi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // eax
  vgui::Panel *v8; // edi
  vgui::IBorder *KeyCount; // ebx
  int i; // esi
  float *KeyValue; // eax

  v3 = (CDmeChannel *)LODWORD(pChannel);
  if ( pChannel != 0.0 )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(LODWORD(pChannel) + 140)) == nullptr
      && v3->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this: v3);
    }
    v4 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_log.m_Storage.m_Handle);
    v5 = v4;
    if ( v4 != nullptr )
    {
      TopmostLayer = CDmeLog::GetTopmostLayer(this: v4);
      Layer = CDmeLog::GetLayer(this: v5, index: TopmostLayer);
      v8 = (vgui::Panel *)Layer;
      if ( Layer != nullptr && Layer->IsA(this: Layer, a2: CDmeTypedLogLayer<float>::m_classType) )
      {
        KeyCount = CDmeLogLayer::GetKeyCount(this: v8);
        for ( i = 0; i < (int)KeyCount; ++i )
        {
          KeyValue = CDmeTypedLogLayer<float>::GetKeyValue(this: (CDmeTypedLogLayer<float> *)v8, nKeyIndex: i);
          pChannel = (float)(*KeyValue * flScale) + flBias;
          CDmeTypedLogLayer<float>::SetKeyValue(this: (CDmeTypedLogLayer<float> *)v8, nKey: i, value: &pChannel);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DEB50
// Name: class CDmeChannel __near * FindChannelTargetingAttribute(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl FindChannelTargetingAttribute(CDmAttribute *pTargetAttr)
{
  CDmElement *m_pOwner; // ecx
  IDataModel_vtbl *v2; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v4; // edi
  CDmElement *v5; // esi
  CDmeChannel *v6; // esi
  CDmAttribute *v7; // eax

  if ( pTargetAttr == nullptr )
    return nullptr;
  m_pOwner = pTargetAttr->m_pOwner;
  if ( m_pOwner == nullptr )
    return nullptr;
  v2 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  if ( v4 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeChannel::m_classType) )
    {
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
      if ( v6 != nullptr )
      {
        v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
        if ( v7 == nullptr )
          v7 = CDmeChannel::SetupToAttribute(this: v6);
        if ( v7 == pTargetAttr )
          break;
      }
    }
    v4 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v4);
    if ( v4 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x104DEC10
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeTime_t **v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    GetElement = g_pDataModel->GetElement;
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = (int)GetElement(this: g_pDataModel, a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = (DmeTime_t **)selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          *v10 = (DmeTime_t *)DmeClipStack_t::ToChildMediaTime(
                                this: &v9->m_ClipStack,
                                result: (DmeTime_t *)&info,
                                t: *v10,
                                bClamp: 0)->m_tms;
          ++v10;
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DEDE0
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DEEF0
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104DEF50
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeChannel *v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  CDmElement *v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)v4);
    if ( v5 != nullptr )
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
    else
      v6 = nullptr;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_FromAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_fromIndex.m_Storage, buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_toIndex.m_Storage, buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_fromElement.m_Storage.m_Handle);
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DF150
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmElement::m_classType)
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x104DF1F0
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  CDmElement *(__thiscall *v20)(IDataModel *, DmElementHandle_t); // edx
  CDmeLogLayer *v21; // edi
  vgui::IBorder *KeyCount; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  CDmElement *v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)GetAttribute_2(this: g_pDataModel, a2: *((DmAttributeHandle_t *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35)) == nullptr && *((_DWORD *)v1 + 38) == -1 )
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    v5 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = g_pDataModel->GetElement;
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)v17(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                                         + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                                         + 4));
            v20 = g_pDataModel->GetElement;
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)v20(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( (int)CDmeLogLayer::GetKeyCount(this: (vgui::Panel *)sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( (int)CDmeLogLayer::GetKeyCount(this: (vgui::Panel *)v21) <= 0 )
              goto LABEL_29;
            KeyCount = CDmeLogLayer::GetKeyCount(this: (vgui::Panel *)v21);
            if ( CDmeLogLayer::GetKeyCount(this: (vgui::Panel *)sourceLayer) != KeyCount )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, CDmElement *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DF760
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DF7A0
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(CDmeChannel *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_nAllocationCount;
      m_pMemory = (int)attrs[1].m_pMemory;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v7 = (CDmAttribute **)attrs->m_pMemory;
      v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v7[m_pMemory + 1], src: (unsigned __int8 *)&v7[m_pMemory], count: 4 * v8);
      v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DF840
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)((int (__thiscall *)(IDataModel *, DmAttributeHandle_t, int))g_pDataModel->GetAttribute_2)(
                           a1: g_pDataModel,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v10 = (CDmAttribute **)attrs->m_pMemory;
        v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v10[m_pMemory + 1],
            src: (unsigned __int8 *)&v10[m_pMemory],
            count: 4 * v11);
        v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DF930
// Name: protected: virtual void CDmeOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::PerformConstruction(CDmeOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeOperator::OnConstruction(this: (CDmeOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x104DF950
// Name: public: virtual char const __near * IDmeOperator::GetOperatorName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IDmeOperator::GetOperatorName(IDmeOperator *this)
{
  return "Unknown";
}

//------------------------------------------------------------------------------
// Address: 0x104DFA10
// Name: public: virtual bool CDmeOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsA(CDmeOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DFA40
// Name: public: virtual int CDmeOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetInheritanceDepth(CDmeOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DFA80
// Name: protected: virtual int CDmeOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::AllocatedSize(CDmeShape *this)
{
  return 76;
}

//------------------------------------------------------------------------------
// Address: 0x104DFA90
// Name: public: virtual char const __near * CDmeOperator::GetOperatorName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeOperator::GetOperatorName(CDmeOperator *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104DFAA0
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104DFBA0
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DFBD0
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DFC20
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x104DFC80
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x104F1070
// Name: protected: virtual void CDmeOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::PerformDestruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x105C9590
// Name: _dynamic_initializer_for__CDmeOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeOperator::s_Allocator,
    blockSize: 0x4Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD9F0
// Name: _dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C95C0
// Name: _dynamic_initializer_for__g_CDmeOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C95D0
// Name: _dynamic_initializer_for__g_CDmeOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeOperator_Helper,
           classname: "DmeOperator",
           pFactory: &g_CDmeOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA00
// Name: _dynamic_atexit_destructor_for__g_CDmeOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeOperator_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004BF910
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x004BF930
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BF9D0
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BFA40
// Name: public: void CDmeChannel::SetCurrentTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetCurrentTime(CDmeChannel *this, DmeTime_t time)
{
  this->m_TimeState.m_tPreviousTime.m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
  this->m_TimeState.m_tCurrentTime = time;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BFA70
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004BFA90
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004BFAB0
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmElementHandle_t type)
{
  CDmeTypedLog<Quaternion> *Log; // eax
  CDmeTypedLog<Quaternion> *v4; // esi

  Log = CDmeLog::CreateLog((DmAttributeType_t)type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CDmElement::GetHandle(this: Log);
  else
    type = DMELEMENT_HANDLE_INVALID;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: &type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004BFB00
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmElementHandle_t v7; // esi
  int v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = WindowName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == 0 )
      goto LABEL_13;
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 140))(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BFBC0
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = WindowName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BFC30
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BFC70
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x004BFCA0
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
// Address: 0x004BFCD0
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004BFE40
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 336);
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v2)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BFF20
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(
        CDmeChannel *this,
        DmElementHandle_t pElement,
        const char *pAttribute,
        int index)
{
  if ( pElement != 0 )
    pElement = CDmElement::GetHandle(this: (CDmElement *)pElement);
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_toElement.m_pAttribute, value: &pElement);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
    a1: g_pDataModel.u,
    a2: &pElement,
    a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x004BFF90
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004BFFA0
// Name: public: void CDmeChannel::SetMode(enum ChannelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetMode(CDmeChannel *this, ChannelMode_t mode)
{
  if ( mode != this->m_mode.m_Storage )
  {
    CDmAttribute::SetValue<int>(this: this->m_mode.m_pAttribute, value: (int *)&mode);
    this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BFFE0
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_log.m_Storage.m_Handle) == 0
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (*(CDmeLog *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004C0030
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  int (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v4; // al
  int v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  int v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = ((int (__thiscall *)(_DWORD))v3)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    noundo.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = *(_DWORD *)g_pDataModel.u.m_Id;
  if ( Ptr == nullptr )
  {
    (*(void (__stdcall **)(_DWORD))(v9 + 232))(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = (*(int (__stdcall **)(_DWORD))(v9 + 72))(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(v11 + 140)) == 0
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
                        a1: g_pDataModel.u,
                        a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x004C0170
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004C0200
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int (__thiscall *v6)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v6 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = ((int (__thiscall *)(_DWORD, _DWORD))v6)(
           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
           a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
               a1: g_pDataModel.u,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                                  a1: g_pDataModel.u,
                                  a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C03D0
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle) == 0
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C04E0
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C0540
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  int v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)v4);
    if ( v5 != 0 )
      v6 = v5 - 4;
    else
      v6 = 0;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 336))(
                             a1: g_pDataModel.u,
                             a2: *(_DWORD *)(v6 + 152));
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 336))(
                             a1: g_pDataModel.u,
                             a2: *(_DWORD *)(v6 + 156));
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: (CDmeChannel *)v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: (CDmeChannel *)v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: *(_DWORD *)(v6 + 96), buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: *(_DWORD *)(v6 + 124), buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(v6 + 76));
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
             a1: v9,
             a2: CDmeTransformControl::m_classType.u) != 0 )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0740
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  int v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = (CDmElement *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmElement::m_classType.u) != 0
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004C07E0
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  int (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  int (__thiscall *v17)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  int (__thiscall *v20)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeLogLayer *v21; // edi
  int ListAttr; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  int v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v2)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_Handle);
  v4 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 336);
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v4)(
                                  a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                  a2: *((_DWORD *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *((_DWORD *)v1 + 35)) == 0
      && *((_DWORD *)v1 + 38) == -1 )
    {
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    }
    v5 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                      a1: g_pDataModel.u,
                      a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v17)(
                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                    a2: *(_DWORD *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                              + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                              + 4));
            v20 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v20)(
                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                    a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeBoneFlexDriverList::GetListAttr(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeBoneFlexDriverList::GetListAttr(this: v21) <= 0 )
              goto LABEL_29;
            ListAttr = CDmeBoneFlexDriverList::GetListAttr(this: v21);
            if ( CDmeBoneFlexDriverList::GetListAttr(this: sourceLayer) != ListAttr )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                      a1: g_pDataModel.u,
                      a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, int, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0D50
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0D90
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_nAllocationCount;
      m_pMemory = (int)attrs[1].m_pMemory;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v7 = (CDmAttribute **)attrs->m_pMemory;
      v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
      v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0E30
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v10 = (CDmAttribute **)attrs->m_pMemory;
        v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
        v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0F80
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1080
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C10B0
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C1100
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeChannel *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x004C1160
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0059B820
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
// Address: 0x0059EFC0
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059B850
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B860
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
// Address: 0x0059EFD0
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x0059EFE0
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004FFD60
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x004FFD80
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004FFE20
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004FFE90
// Name: public: void CDmeChannel::SetCurrentTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetCurrentTime(CDmeChannel *this, DmeTime_t time)
{
  this->m_TimeState.m_tPreviousTime.m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
  this->m_TimeState.m_tCurrentTime = time;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004FFEC0
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004FFEE0
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004FFF00
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CExpressionCalculator *Log; // eax
  CExpressionCalculator *v4; // esi

  Log = (CExpressionCalculator *)CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CExpressionCalculator::VariableCount(this: Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004FFF50
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  int v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == 0 )
      goto LABEL_13;
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 140))(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00500010
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00500080
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005000C0
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x005000F0
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
// Address: 0x00500120
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00500290
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 336);
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v2)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500370
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
    a1: g_pDataModel.u,
    a2: &pElement,
    a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x005003E0
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005003F0
// Name: public: void CDmeChannel::SetMode(enum ChannelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetMode(CDmeChannel *this, ChannelMode_t mode)
{
  if ( mode != this->m_mode.m_Storage )
  {
    CDmAttribute::SetValue<int>(this: this->m_mode.m_pAttribute, value: (int *)&mode);
    this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500430
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_log.m_Storage.m_Handle) == 0
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (*(CDmeLog *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00500480
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  int (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v4; // al
  int v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  int v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = ((int (__thiscall *)(_DWORD))v3)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    noundo.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = *(_DWORD *)g_pDataModel.u.m_Id;
  if ( Ptr == nullptr )
  {
    (*(void (__stdcall **)(_DWORD))(v9 + 232))(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = (*(int (__stdcall **)(_DWORD))(v9 + 72))(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(v11 + 140)) == 0
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
                        a1: g_pDataModel.u,
                        a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x005005C0
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00500650
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int (__thiscall *v6)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v6 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = ((int (__thiscall *)(_DWORD, _DWORD))v6)(
           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
           a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
               a1: g_pDataModel.u,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                                  a1: g_pDataModel.u,
                                  a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500820
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle) == 0
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500930
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00500990
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  int v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)v4);
    if ( v5 != 0 )
      v6 = v5 - 4;
    else
      v6 = 0;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 336))(
                             a1: g_pDataModel.u,
                             a2: *(_DWORD *)(v6 + 152));
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 336))(
                             a1: g_pDataModel.u,
                             a2: *(_DWORD *)(v6 + 156));
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: (CDmeChannel *)v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: (CDmeChannel *)v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: *(_DWORD *)(v6 + 96), buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: *(_DWORD *)(v6 + 124), buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(v6 + 76));
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
             a1: v9,
             a2: CDmeTransformControl::m_classType.u) != 0 )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500B90
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  int v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = (CDmElement *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmElement::m_classType.u) != 0
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00500C30
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  int (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  int (__thiscall *v17)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  int (__thiscall *v20)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeLogLayer *v21; // edi
  int ListAttr; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  int v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v2)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_Handle);
  v4 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 336);
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v4)(
                                  a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                  a2: *((_DWORD *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *((_DWORD *)v1 + 35)) == 0
      && *((_DWORD *)v1 + 38) == -1 )
    {
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    }
    v5 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                      a1: g_pDataModel.u,
                      a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v17)(
                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                    a2: *(_DWORD *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                              + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                              + 4));
            v20 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v20)(
                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                    a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeBoneFlexDriverList::GetListAttr(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeBoneFlexDriverList::GetListAttr(this: v21) <= 0 )
              goto LABEL_29;
            ListAttr = CDmeBoneFlexDriverList::GetListAttr(this: v21);
            if ( CDmeBoneFlexDriverList::GetListAttr(this: sourceLayer) != ListAttr )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                      a1: g_pDataModel.u,
                      a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, int, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005011A0
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005011E0
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_nAllocationCount;
      m_pMemory = (int)attrs[1].m_pMemory;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v7 = (CDmAttribute **)attrs->m_pMemory;
      v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
      v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00501280
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v10 = (CDmAttribute **)attrs->m_pMemory;
        v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
        v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005013D0
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005014D0
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00501500
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00501550
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeChannel *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x005015B0
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005EF8B0
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
// Address: 0x005F3E90
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EF8E0
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF8F0
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
// Address: 0x005F3EA0
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005F3EB0
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004785E0
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x00478600
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004786A0
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00478710
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00478730
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00478750
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CExpressionCalculator *Log; // eax
  CExpressionCalculator *v4; // esi

  Log = (CExpressionCalculator *)CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CExpressionCalculator::VariableCount(this: Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004787A0
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  CDmElement *v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = str;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == nullptr )
      goto LABEL_13;
    v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[2].OnElementSerialized)(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00478860
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = str;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004788D0
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478910
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x00478940
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
// Address: 0x00478970
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00478AE0
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  void *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = GetAttribute_2(this: g_pDataModel, a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = (void *)CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478BC0
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x00478C30
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00478C40
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00478C90
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  IDataModel_vtbl *v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    noundo.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = g_pDataModel->__vftable;
  if ( Ptr == nullptr )
  {
    ((void (__stdcall *)(_DWORD))v9->SetUndoEnabled)(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = ((int (__stdcall *)(_DWORD))v9->GetElement)(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == nullptr
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x00478DD0
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00478E60
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    GetElement = g_pDataModel->GetElement;
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = (int)GetElement(this: g_pDataModel, a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479030
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479140
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004791A0
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeChannel *v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  CDmElement *v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)v4);
    if ( v5 != nullptr )
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
    else
      v6 = nullptr;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_FromAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_fromIndex.m_Storage, buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_toIndex.m_Storage, buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_fromElement.m_Storage.m_Handle);
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004793A0
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmElement::m_classType)
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00479440
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  CDmElement *(__thiscall *v20)(IDataModel *, DmElementHandle_t); // edx
  CDmeLogLayer *v21; // edi
  int KeyCount; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  CDmElement *v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)GetAttribute_2(this: g_pDataModel, a2: *((DmAttributeHandle_t *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35)) == nullptr && *((_DWORD *)v1 + 38) == -1 )
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    v5 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = g_pDataModel->GetElement;
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)v17(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                                         + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                                         + 4));
            v20 = g_pDataModel->GetElement;
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)v20(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: v21) <= 0 )
              goto LABEL_29;
            KeyCount = CDmeLogLayer::GetKeyCount(this: v21);
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) != KeyCount )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, CDmElement *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004799B0
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004799F0
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_nAllocationCount;
      m_pMemory = (int)attrs[1].m_pMemory;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v7 = (CDmAttribute **)attrs->m_pMemory;
      v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
      v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479A90
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)((int (__thiscall *)(IDataModel *, DmAttributeHandle_t, int))g_pDataModel->GetAttribute_2)(
                           a1: g_pDataModel,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v10 = (CDmAttribute **)attrs->m_pMemory;
        v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
        v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479BE0
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00479CE0
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00479D10
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00479D60
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x00479DC0
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0056A9D0
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
// Address: 0x0056E4C0
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056AA00
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056AA10
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
// Address: 0x0056E4D0
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x0056E4E0
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0047D410
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x0047D430
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047D4D0
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047D540
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0047D560
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0047D580
// Name: public: void CDmeChannel::SetLog(class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetLog(CDmeChannel *this, int pLog)
{
  CDmeLog *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pLog != 0 )
  {
    v3 = (CDmeLog *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pLog);
    m_pAttribute = this->m_log.m_pAttribute;
    pLog = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_log.m_pAttribute;
    pLog = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&pLog);
}

//------------------------------------------------------------------------------
// Address: 0x0047D5D0
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CDmeTypedLog<Quaternion> *Log; // eax
  CDmeTypedLog<Quaternion> *v4; // esi

  Log = CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047D620
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  CDmElement *v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pParentName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == nullptr )
      goto LABEL_13;
    v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[2].OnElementSerialized)(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047D6E0
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pParentName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047D750
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D790
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x0047D7C0
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
// Address: 0x0047D7F0
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0047D960
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = GetAttribute_2(this: g_pDataModel, a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DA40
// Name: public: void CDmeChannel::SetInput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetInput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_fromElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_fromAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_fromIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupFromAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047DAB0
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047DB20
// Name: public: void CDmeChannel::SetInput(class CDmAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetInput(CDmeChannel *this, CDmAttribute *pAttribute, int index)
{
  const char *m_pAsString; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pAttribute != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    CDmeChannel::SetInput(this, pElement: (int)pAttribute->m_pOwner, pAttribute: m_pAsString, index);
  }
  else
  {
    pAttribute = (CDmAttribute *)index;
    m_pAttribute = this->m_fromElement.m_pAttribute;
    index = -1;
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&index);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&index, a3: &pParentName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: this->m_fromAttribute.m_pAttribute,
      value: (const CUtlSymbolLarge *)&index);
    CDmAttribute::SetValue<int>(this: this->m_fromIndex.m_pAttribute, value: (int *)&pAttribute);
    CDmeChannel::SetupFromAttribute(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DBB0
// Name: public: void CDmeChannel::SetOutput(class CDmAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, CDmAttribute *pAttribute, int index)
{
  const char *m_pAsString; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pAttribute != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    CDmeChannel::SetOutput(this, pElement: (int)pAttribute->m_pOwner, pAttribute: m_pAsString, index);
  }
  else
  {
    pAttribute = (CDmAttribute *)index;
    m_pAttribute = this->m_toElement.m_pAttribute;
    index = -1;
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&index);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&index, a3: &pParentName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: this->m_toAttribute.m_pAttribute,
      value: (const CUtlSymbolLarge *)&index);
    CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: (int *)&pAttribute);
    CDmeChannel::SetupToAttribute(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DC40
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0047DC50
// Name: public: void CDmeChannel::SetMode(enum ChannelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetMode(CDmeChannel *this, ChannelMode_t mode)
{
  if ( mode != this->m_mode.m_Storage )
  {
    CDmAttribute::SetValue<int>(this: this->m_mode.m_pAttribute, value: (int *)&mode);
    this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DC90
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0047DCE0
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  IDataModel_vtbl *v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    noundo.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = g_pDataModel->__vftable;
  if ( Ptr == nullptr )
  {
    ((void (__stdcall *)(_DWORD))v9->SetUndoEnabled)(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = ((int (__stdcall *)(_DWORD))v9->GetElement)(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == nullptr
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x0047DE20
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047DEB0
// Name: void RemapFloatLogValues(class CDmeChannel __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapFloatLogValues(float pChannel, float flBias, float flScale)
{
  CDmeChannel *v3; // esi
  CDmeLog *v4; // eax
  CDmeLog *v5; // esi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // eax
  CDmeTypedLogLayer<float> *v8; // edi
  int KeyCount; // ebx
  int i; // esi
  float *KeyValue; // eax

  v3 = (CDmeChannel *)LODWORD(pChannel);
  if ( pChannel != 0.0 )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(LODWORD(pChannel) + 140)) == nullptr
      && v3->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this: v3);
    }
    v4 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_log.m_Storage.m_Handle);
    v5 = v4;
    if ( v4 != nullptr )
    {
      TopmostLayer = CDmeLog::GetTopmostLayer(this: v4);
      Layer = CDmeLog::GetLayer(this: v5, index: TopmostLayer);
      v8 = (CDmeTypedLogLayer<float> *)Layer;
      if ( Layer != nullptr && Layer->IsA(this: Layer, a2: CDmeTypedLogLayer<float>::m_classType) )
      {
        KeyCount = CDmeLogLayer::GetKeyCount(this: v8);
        for ( i = 0; i < KeyCount; ++i )
        {
          KeyValue = CDmeTypedLogLayer<float>::GetKeyValue(this: v8, nKeyIndex: i);
          pChannel = (float)(*KeyValue * flScale) + flBias;
          CDmeTypedLogLayer<float>::SetKeyValue(this: v8, nKey: i, value: &pChannel);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DF80
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    GetElement = g_pDataModel->GetElement;
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = (int)GetElement(this: g_pDataModel, a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E150
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E260
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047E2C0
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeChannel *v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  CDmElement *v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)v4);
    if ( v5 != nullptr )
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
    else
      v6 = nullptr;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_FromAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_fromIndex.m_Storage, buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_toIndex.m_Storage, buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_fromElement.m_Storage.m_Handle);
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E4C0
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmElement::m_classType)
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047E560
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  CDmElement *(__thiscall *v20)(IDataModel *, DmElementHandle_t); // edx
  CDmeLogLayer *v21; // edi
  int KeyCount; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  CDmElement *v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)GetAttribute_2(this: g_pDataModel, a2: *((DmAttributeHandle_t *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35)) == nullptr && *((_DWORD *)v1 + 38) == -1 )
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    v5 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = g_pDataModel->GetElement;
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)v17(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                                         + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                                         + 4));
            v20 = g_pDataModel->GetElement;
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)v20(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: v21) <= 0 )
              goto LABEL_29;
            KeyCount = CDmeLogLayer::GetKeyCount(this: v21);
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) != KeyCount )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, CDmElement *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EAD0
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EB10
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
      m_Size = attrs->m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: m_Size - m_nAllocationCount + 1);
      ++attrs->m_Size;
      m_pMemory = attrs->m_Memory.m_pMemory;
      v8 = attrs->m_Size - m_Size - 1;
      attrs->m_pElements = attrs->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = &attrs->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EBB0
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)((int (__thiscall *)(IDataModel *, DmAttributeHandle_t, int))g_pDataModel->GetAttribute_2)(
                           a1: g_pDataModel,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v11 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
        v12 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047ED00
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047EE00
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047EE30
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047EED0
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00522E50
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x0057AAD0
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
// Address: 0x0057E5F0
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057AB00
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057AB10
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
// Address: 0x0057E600
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x0057E610
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00523770
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x00523790
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00523830
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005238A0
// Name: public: class DmeTime_t CDmeChannel::GetCurrentTime(void)const
// Source: json
//------------------------------------------------------------------------------
DmeTime_t *__thiscall CDmeChannel::GetCurrentTime(CDmeChannel *this, DmeTime_t *result)
{
  result->m_tms = (int)this->m_TimeState.m_tCurrentTime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005238C0
// Name: public: void CDmeChannel::SetCurrentTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetCurrentTime(CDmeChannel *this, DmeTime_t time)
{
  this->m_TimeState.m_tPreviousTime.m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
  this->m_TimeState.m_tCurrentTime = time;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005238F0
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00523910
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00523930
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CExpressionCalculator *Log; // eax
  CExpressionCalculator *v4; // esi

  Log = (CExpressionCalculator *)CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CCodecBuffer_Block::GetBufferType(this: Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_log.m_pAttribute,
    value: (const DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00523980
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  int v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == 0 )
      goto LABEL_13;
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 140))(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00523A40
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00523AB0
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523AF0
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x00523B20
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00523C90
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 336);
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v2)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523D70
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (const DmElementHandle_t *)&pElement);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
    a1: g_pDataModel.u,
    a2: &pElement,
    a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x00523DE0
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00523DF0
// Name: public: void CDmeChannel::SetMode(enum ChannelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetMode(CDmeChannel *this, ChannelMode_t mode)
{
  if ( mode != this->m_mode.m_Storage )
  {
    CDmAttribute::SetValue<int>(this: this->m_mode.m_pAttribute, value: (const int *)&mode);
    this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523E30
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_log.m_Storage.m_Handle) == 0
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (*(CDmeLog *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00523E80
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  int (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v4; // al
  int v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  int v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = ((int (__thiscall *)(_DWORD))v3)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    noundo.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = *(_DWORD *)g_pDataModel.u.m_Id;
  if ( Ptr == nullptr )
  {
    (*(void (__stdcall **)(_DWORD))(v9 + 232))(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = (*(int (__stdcall **)(_DWORD))(v9 + 72))(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(v11 + 140)) == 0
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
                        a1: g_pDataModel.u,
                        a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x00523FC0
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00524050
// Name: void RemapFloatLogValues(class CDmeChannel __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapFloatLogValues(float pChannel, float flBias, float flScale)
{
  CDmeChannel *v3; // esi
  CDmeLog *v4; // eax
  CDmeLog *v5; // esi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // eax
  vgui::Panel *v8; // edi
  vgui::IBorder *ListAttr; // ebx
  int i; // esi
  float *KeyValue; // eax

  v3 = (CDmeChannel *)LODWORD(pChannel);
  if ( pChannel != 0.0 )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: *(DmElementHandle_t *)(LODWORD(pChannel) + 140)) == 0
      && v3->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this: v3);
    }
    v4 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: v3->m_log.m_Storage.m_Handle);
    v5 = v4;
    if ( v4 != nullptr )
    {
      TopmostLayer = CDmeLog::GetTopmostLayer(this: v4);
      Layer = CDmeLog::GetLayer(this: v5, index: TopmostLayer);
      v8 = (vgui::Panel *)Layer;
      if ( Layer != nullptr && Layer->IsA(this: Layer, a2: CDmeTypedLogLayer<float>::m_classType) )
      {
        ListAttr = CDmeBoneFlexDriverList::GetListAttr(this: v8);
        for ( i = 0; i < (int)ListAttr; ++i )
        {
          KeyValue = (float *)CDmeTypedLogLayer<float>::GetKeyValue(this: (CDmeTypedLogLayer<float> *)v8, nKeyIndex: i);
          pChannel = (float)(*KeyValue * flScale) + flBias;
          CDmeTypedLogLayer<float>::SetKeyValue(this: (CDmeTypedLogLayer<float> *)v8, nKey: i, value: &pChannel);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524120
// Name: class CDmeChannel __near * FindChannelTargetingAttribute(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl FindChannelTargetingAttribute(CDmAttribute *pTargetAttr)
{
  CDmElement *m_pOwner; // ecx
  int v2; // esi
  int BufferType; // eax
  int v4; // edi
  int v5; // esi
  int v6; // esi
  CDmAttribute *v7; // eax

  if ( pTargetAttr == nullptr )
    return nullptr;
  m_pOwner = pTargetAttr->m_pOwner;
  if ( m_pOwner == nullptr )
    return nullptr;
  v2 = *(_DWORD *)g_pDataModel.u.m_Id;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v2 + 436))(a1: g_pDataModel.u, a2: BufferType);
  if ( v4 == 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                       a1: g_pDataModel.u,
                       a2: v4)
                   + 8);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeChannel::m_classType.u) != 0 )
    {
      v6 = v5 - 4;
      if ( v6 != 0 )
      {
        v7 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 336))(
                               a1: g_pDataModel.u,
                               a2: *(_DWORD *)(v6 + 156));
        if ( v7 == nullptr )
          v7 = CDmeChannel::SetupToAttribute(this: (CDmeChannel *)v6);
        if ( v7 == pTargetAttr )
          break;
      }
    }
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
           a1: g_pDataModel.u,
           a2: v4);
    if ( v4 == 0 )
      return nullptr;
  }
  return (CDmeChannel *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x005241E0
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int (__thiscall *v6)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v6 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = ((int (__thiscall *)(_DWORD, _DWORD))v6)(
           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
           a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
               a1: g_pDataModel.u,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                                  a1: g_pDataModel.u,
                                  a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005243B0
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle) == 0
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005244C0
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00524520
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  int v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)v4);
    if ( v5 != 0 )
      v6 = v5 - 4;
    else
      v6 = 0;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 336))(
                             a1: g_pDataModel.u,
                             a2: *(_DWORD *)(v6 + 152));
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 336))(
                             a1: g_pDataModel.u,
                             a2: *(_DWORD *)(v6 + 156));
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: (CDmeChannel *)v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: (CDmeChannel *)v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: *(_DWORD *)(v6 + 96), buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: *(_DWORD *)(v6 + 124), buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(v6 + 76));
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
             a1: v9,
             a2: CDmeTransformControl::m_classType.u) != 0 )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524720
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  int v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = (CDmElement *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmElement::m_classType.u) != 0
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x005247C0
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  int (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  int (__thiscall *v17)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  int (__thiscall *v20)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeLogLayer *v21; // edi
  vgui::IBorder *ListAttr; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  int v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v2)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_Handle);
  v4 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 336);
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v4)(
                                  a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                  a2: *((_DWORD *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *((_DWORD *)v1 + 35)) == 0
      && *((_DWORD *)v1 + 38) == -1 )
    {
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    }
    v5 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                      a1: g_pDataModel.u,
                      a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v17)(
                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                    a2: *(_DWORD *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                              + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                              + 4));
            v20 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v20)(
                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                    a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( (int)CDmeBoneFlexDriverList::GetListAttr(this: (vgui::Panel *)sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( (int)CDmeBoneFlexDriverList::GetListAttr(this: (vgui::Panel *)v21) <= 0 )
              goto LABEL_29;
            ListAttr = CDmeBoneFlexDriverList::GetListAttr(this: (vgui::Panel *)v21);
            if ( CDmeBoneFlexDriverList::GetListAttr(this: (vgui::Panel *)sourceLayer) != ListAttr )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                      a1: g_pDataModel.u,
                      a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, int, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524D30
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524D70
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(CDmeChannel *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_nAllocationCount;
      m_pMemory = (int)attrs[1].m_pMemory;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v7 = (CDmAttribute **)attrs->m_pMemory;
      v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
      v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524E10
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v10 = (CDmAttribute **)attrs->m_pMemory;
        v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
        v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524F00
// Name: protected: virtual void CDmeOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::PerformConstruction(CDmeOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00524F20
// Name: public: virtual char const __near * IDmeOperator::GetOperatorName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IDmeOperator::GetOperatorName(IDmeOperator *this)
{
  return "Unknown";
}

//------------------------------------------------------------------------------
// Address: 0x00524FE0
// Name: public: virtual bool CDmeOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsA(CDmeOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525010
// Name: public: virtual int CDmeOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetInheritanceDepth(CDmeOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525050
// Name: protected: virtual int CDmeOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::AllocatedSize(CDmeOperator *this)
{
  return 76;
}

//------------------------------------------------------------------------------
// Address: 0x00525060
// Name: public: virtual char const __near * CDmeOperator::GetOperatorName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeOperator::GetOperatorName(CDmeOperator *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00525070
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00525170
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005251A0
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525240
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005DFD60
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x006B28C0
// Name: _dynamic_initializer_for__CDmeOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeOperator::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5CE0
// Name: _dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B28F0
// Name: _dynamic_initializer_for__g_CDmeOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2900
// Name: _dynamic_initializer_for__g_CDmeOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeOperator_Helper,
           classname: "DmeOperator",
           pFactory: &g_CDmeOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5CF0
// Name: _dynamic_atexit_destructor_for__g_CDmeOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeOperator_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0047E230
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x0047E250
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047E2F0
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047E360
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0047E380
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0047E3A0
// Name: public: void CDmeChannel::SetLog(class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetLog(CDmeChannel *this, int pLog)
{
  CDmeLog *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pLog != 0 )
  {
    v3 = (CDmeLog *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pLog);
    m_pAttribute = this->m_log.m_pAttribute;
    pLog = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_log.m_pAttribute;
    pLog = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&pLog);
}

//------------------------------------------------------------------------------
// Address: 0x0047E3F0
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CDmeTypedLog<Quaternion> *Log; // eax
  CDmeTypedLog<Quaternion> *v4; // esi

  Log = CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047E440
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  CDmElement *v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pch;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == nullptr )
      goto LABEL_13;
    v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[2].OnElementSerialized)(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047E500
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pch;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047E570
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E5B0
// Name: public: bool CDmeChannel::BuildClipStack(struct DmeClipStack_t __near *,class CDmeClip __near *,class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::BuildClipStack(
        CDmeChannel *this,
        DmeClipStack_t *pClipStack,
        CDmeClip *pRoot,
        CDmeClip *pShot)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // edi
  CDmeClip *m_pOwner; // esi

  v4 = g_pDataModel->__vftable;
  v5 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&this->CDmElement);
  v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
  if ( v6 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return 0;
  while ( 1 )
  {
    m_pOwner = (CDmeClip *)g_pDataModel->GetAttribute(this: g_pDataModel, a2: v6)->m_pOwner;
    if ( m_pOwner != nullptr
      && m_pOwner->IsA(this: m_pOwner, a2: CDmeChannelsClip::m_classType)
      && CDmeClip::BuildClipStack(this: m_pOwner, pStack: pClipStack, pMovie: pRoot, pShot) )
    {
      break;
    }
    v6 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v6);
    if ( v6 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E650
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x0047E680
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
// Address: 0x0047E6B0
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0047E820
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = GetAttribute_2(this: g_pDataModel, a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E900
// Name: public: void CDmeChannel::SetInput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetInput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_fromElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_fromAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_fromIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupFromAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E970
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E9E0
// Name: public: void CDmeChannel::SetInput(class CDmAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetInput(CDmeChannel *this, CDmAttribute *pAttribute, int index)
{
  const char *m_pAsString; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pAttribute != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    CDmeChannel::SetInput(this, pElement: (int)pAttribute->m_pOwner, pAttribute: m_pAsString, index);
  }
  else
  {
    pAttribute = (CDmAttribute *)index;
    m_pAttribute = this->m_fromElement.m_pAttribute;
    index = -1;
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&index);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&index, a3: &pch);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: this->m_fromAttribute.m_pAttribute,
      value: (const CUtlSymbolLarge *)&index);
    CDmAttribute::SetValue<int>(this: this->m_fromIndex.m_pAttribute, value: (int *)&pAttribute);
    CDmeChannel::SetupFromAttribute(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EA70
// Name: public: void CDmeChannel::SetOutput(class CDmAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, CDmAttribute *pAttribute, int index)
{
  const char *m_pAsString; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pAttribute != nullptr )
  {
    m_pAsString = pAttribute->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    CDmeChannel::SetOutput(this, pElement: (int)pAttribute->m_pOwner, pAttribute: m_pAsString, index);
  }
  else
  {
    pAttribute = (CDmAttribute *)index;
    m_pAttribute = this->m_toElement.m_pAttribute;
    index = -1;
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&index);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&index, a3: &pch);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: this->m_toAttribute.m_pAttribute,
      value: (const CUtlSymbolLarge *)&index);
    CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: (int *)&pAttribute);
    CDmeChannel::SetupToAttribute(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EB00
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0047EB50
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0047EBA0
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  IDataModel_vtbl *v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    noundo.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = g_pDataModel->__vftable;
  if ( Ptr == nullptr )
  {
    ((void (__stdcall *)(_DWORD))v9->SetUndoEnabled)(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = ((int (__stdcall *)(_DWORD))v9->GetElement)(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == nullptr
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x0047ECE0
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047ED70
// Name: void RemapFloatLogValues(class CDmeChannel __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapFloatLogValues(float pChannel, float flBias, float flScale)
{
  CDmeChannel *v3; // esi
  CDmeLog *v4; // eax
  CDmeLog *v5; // esi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // eax
  CDmeTypedLogLayer<float> *v8; // edi
  int KeyCount; // ebx
  int i; // esi
  float *KeyValue; // eax

  v3 = (CDmeChannel *)LODWORD(pChannel);
  if ( pChannel != 0.0 )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(LODWORD(pChannel) + 140)) == nullptr
      && v3->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this: v3);
    }
    v4 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_log.m_Storage.m_Handle);
    v5 = v4;
    if ( v4 != nullptr )
    {
      TopmostLayer = CDmeLog::GetTopmostLayer(this: v4);
      Layer = CDmeLog::GetLayer(this: v5, index: TopmostLayer);
      v8 = (CDmeTypedLogLayer<float> *)Layer;
      if ( Layer != nullptr && Layer->IsA(this: Layer, a2: CDmeTypedLogLayer<float>::m_classType) )
      {
        KeyCount = CDmeLogLayer::GetKeyCount(this: v8);
        for ( i = 0; i < KeyCount; ++i )
        {
          KeyValue = CDmeTypedLogLayer<float>::GetKeyValue(this: v8, nKeyIndex: i);
          pChannel = (float)(*KeyValue * flScale) + flBias;
          CDmeTypedLogLayer<float>::SetKeyValue(this: v8, nKey: i, value: &pChannel);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EE40
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    GetElement = g_pDataModel->GetElement;
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = (int)GetElement(this: g_pDataModel, a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F010
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F120
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047F180
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeChannel *v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  CDmElement *v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)v4);
    if ( v5 != nullptr )
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
    else
      v6 = nullptr;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_FromAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_fromIndex.m_Storage, buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_toIndex.m_Storage, buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_fromElement.m_Storage.m_Handle);
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F380
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmElement::m_classType)
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047F420
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  CDmElement *(__thiscall *v20)(IDataModel *, DmElementHandle_t); // edx
  CDmeLogLayer *v21; // edi
  int KeyCount; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  CDmElement *v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)GetAttribute_2(this: g_pDataModel, a2: *((DmAttributeHandle_t *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35)) == nullptr && *((_DWORD *)v1 + 38) == -1 )
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    v5 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = g_pDataModel->GetElement;
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)v17(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                                         + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                                         + 4));
            v20 = g_pDataModel->GetElement;
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)v20(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: v21) <= 0 )
              goto LABEL_29;
            KeyCount = CDmeLogLayer::GetKeyCount(this: v21);
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) != KeyCount )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, CDmElement *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F990
// Name: public: class CDmeClip __near * CDmeChannel::FindOwnerClipForChannel(class CDmeClip __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeChannel::FindOwnerClipForChannel(CDmeChannel *this, CDmeClip *pRoot)
{
  CDmElement *v2; // esi
  DmeClipStack_t stack; // [esp+4h] [ebp-30h] BYREF

  stack.m_tStart.m_tms = 0x80000000;
  stack.m_tDuration.m_tms = 0x80000000;
  stack.m_tOffset.m_tms = 0x80000000;
  memset(&stack, 0, 20);
  stack.m_bOptimized = false;
  if ( CDmeChannel::BuildClipStack(this, pClipStack: &stack, pRoot, pShot: pRoot) != 0 )
  {
    v2 = g_pDataModel->GetElement(
           this: g_pDataModel,
           a2: stack.m_clips.m_Memory.m_pMemory[stack.m_clips.m_Size - 1].m_handle);
    CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &stack.m_clips);
    if ( stack.m_clips.m_Memory.m_nGrowSize >= 0 && stack.m_clips.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stack.m_clips.m_Memory.m_pMemory);
    return (CDmeClip *)v2;
  }
  else
  {
    CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &stack.m_clips);
    if ( stack.m_clips.m_Memory.m_nGrowSize >= 0 && stack.m_clips.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stack.m_clips.m_Memory.m_pMemory);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FA50
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FA90
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
      m_Size = attrs->m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: m_Size - m_nAllocationCount + 1);
      ++attrs->m_Size;
      m_pMemory = attrs->m_Memory.m_pMemory;
      v8 = attrs->m_Size - m_Size - 1;
      attrs->m_pElements = attrs->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = &attrs->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FB30
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)((int (__thiscall *)(IDataModel *, DmAttributeHandle_t, int))g_pDataModel->GetAttribute_2)(
                           a1: g_pDataModel,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v11 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
        v12 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FC90
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047FD90
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FDC0
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FE10
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x0047FE70
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057CAC0
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
// Address: 0x005805D0
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CAF0
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB00
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
// Address: 0x005805E0
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005805F0
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004F8D80
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x004F8DA0
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004F8E40
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004F8EB0
// Name: public: void CDmeChannel::SetCurrentTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetCurrentTime(CDmeChannel *this, DmeTime_t time)
{
  this->m_TimeState.m_tPreviousTime.m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
  this->m_TimeState.m_tCurrentTime = time;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F8EE0
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004F8F00
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004F8F20
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CExpressionCalculator *Log; // eax
  CExpressionCalculator *v4; // esi

  Log = (CExpressionCalculator *)CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CExpressionCalculator::VariableCount(this: Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004F8F70
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  int v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == 0 )
      goto LABEL_13;
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 140))(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F9030
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F90A0
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F90E0
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x004F9110
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
// Address: 0x004F9140
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004F92B0
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 336);
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v2)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F9390
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
    a1: g_pDataModel.u,
    a2: &pElement,
    a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x004F9400
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004F9410
// Name: public: void CDmeChannel::SetMode(enum ChannelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetMode(CDmeChannel *this, ChannelMode_t mode)
{
  if ( mode != this->m_mode.m_Storage )
  {
    CDmAttribute::SetValue<int>(this: this->m_mode.m_pAttribute, value: (int *)&mode);
    this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F9450
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_log.m_Storage.m_Handle) == 0
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (*(CDmeLog *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004F94A0
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  int (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v4; // al
  int v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  int v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = ((int (__thiscall *)(_DWORD))v3)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    noundo.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = *(_DWORD *)g_pDataModel.u.m_Id;
  if ( Ptr == nullptr )
  {
    (*(void (__stdcall **)(_DWORD))(v9 + 232))(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = (*(int (__stdcall **)(_DWORD))(v9 + 72))(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(v11 + 140)) == 0
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
                        a1: g_pDataModel.u,
                        a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x004F95E0
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004F9670
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int (__thiscall *v6)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v6 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = ((int (__thiscall *)(_DWORD, _DWORD))v6)(
           a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
           a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
               a1: g_pDataModel.u,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                                  a1: g_pDataModel.u,
                                  a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F9840
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_log.m_Storage.m_Handle) == 0
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F9950
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F99B0
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  int v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)v4);
    if ( v5 != 0 )
      v6 = v5 - 4;
    else
      v6 = 0;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 336))(
                             a1: g_pDataModel.u,
                             a2: *(_DWORD *)(v6 + 152));
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 336))(
                             a1: g_pDataModel.u,
                             a2: *(_DWORD *)(v6 + 156));
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: (CDmeChannel *)v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: (CDmeChannel *)v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: *(_DWORD *)(v6 + 96), buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: *(_DWORD *)(v6 + 124), buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(v6 + 76));
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
             a1: v9,
             a2: CDmeTransformControl::m_classType.u) != 0 )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F9BB0
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  int v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = (CDmElement *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmElement::m_classType.u) != 0
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004F9C50
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  int (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  int (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  int (__thiscall *v17)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  int (__thiscall *v20)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD); // edx
  CDmeLogLayer *v21; // edi
  int ListAttr; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  int v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  SegmentInterpolation_t SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  v2 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v2)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_Handle);
  v4 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 336);
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v4)(
                                  a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                  a2: *((_DWORD *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *((_DWORD *)v1 + 35)) == 0
      && *((_DWORD *)v1 + 38) == -1 )
    {
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    }
    v5 = (CDmeLog *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                      a1: g_pDataModel.u,
                      a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v17)(
                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                    a2: *(_DWORD *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                              + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                              + 4));
            v20 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)((int (__thiscall *)(_DWORD, _DWORD))v20)(
                                    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                                    a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeBoneFlexDriverList::GetListAttr(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeBoneFlexDriverList::GetListAttr(this: v21) <= 0 )
              goto LABEL_29;
            ListAttr = CDmeBoneFlexDriverList::GetListAttr(this: v21);
            if ( CDmeBoneFlexDriverList::GetListAttr(this: sourceLayer) != ListAttr )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                      a1: g_pDataModel.u,
                      a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, int, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, SegmentInterpolation_t, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA1C0
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA200
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_nAllocationCount;
      m_pMemory = (int)attrs[1].m_pMemory;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v7 = (CDmAttribute **)attrs->m_pMemory;
      v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
      v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA2A0
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                           a1: g_pDataModel.u,
                           a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v10 = (CDmAttribute **)attrs->m_pMemory;
        v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
        v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA3F0
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004FA4F0
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FA520
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FA570
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeChannel *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x004FA5D0
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005E8750
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
// Address: 0x005ECD30
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E8780
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8790
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
// Address: 0x005ECD40
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005ECD50
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00487190
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x004871B0
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00487250
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004872C0
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004872E0
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00487300
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CExpressionCalculator *Log; // eax
  CExpressionCalculator *v4; // esi

  Log = (CExpressionCalculator *)CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CExpressionCalculator::VariableCount(this: Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_log.m_pAttribute,
    value: (const DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00487350
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  CDmElement *v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = Ptr;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == nullptr )
      goto LABEL_13;
    v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[2].OnElementSerialized)(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00487410
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = Ptr;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00487480
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004874C0
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x004874F0
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
// Address: 0x00487520
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00487690
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  void *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = GetAttribute_2(this: g_pDataModel, a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = (void *)CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487770
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (const DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x004877E0
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004877F0
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00487840
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  IDataModel_vtbl *v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    noundo.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = g_pDataModel->__vftable;
  if ( Ptr == nullptr )
  {
    ((void (__stdcall *)(_DWORD))v9->SetUndoEnabled)(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = ((int (__stdcall *)(_DWORD))v9->GetElement)(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == nullptr
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x00487980
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00487A10
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    GetElement = g_pDataModel->GetElement;
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = (int)GetElement(this: g_pDataModel, a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487BE0
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487CF0
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00487D50
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeChannel *v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  CDmElement *v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)v4);
    if ( v5 != nullptr )
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
    else
      v6 = nullptr;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_FromAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_fromIndex.m_Storage, buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_toIndex.m_Storage, buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_fromElement.m_Storage.m_Handle);
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487F50
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmElement::m_classType)
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00488000
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  CDmElement *(__thiscall *v20)(IDataModel *, DmElementHandle_t); // edx
  CDmeLogLayer *v21; // edi
  int KeyCount; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  CDmElement *v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)GetAttribute_2(this: g_pDataModel, a2: *((DmAttributeHandle_t *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35)) == nullptr && *((_DWORD *)v1 + 38) == -1 )
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    v5 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = g_pDataModel->GetElement;
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)v17(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                                         + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                                         + 4));
            v20 = g_pDataModel->GetElement;
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)v20(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: v21) <= 0 )
              goto LABEL_29;
            KeyCount = CDmeLogLayer::GetKeyCount(this: v21);
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) != KeyCount )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, CDmElement *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != SEGMENT_INTERPOLATE) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488570
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004885B0
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
      m_Size = attrs->m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: m_Size - m_nAllocationCount + 1);
      ++attrs->m_Size;
      m_pMemory = attrs->m_Memory.m_pMemory;
      v8 = attrs->m_Size - m_Size - 1;
      attrs->m_pElements = attrs->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = &attrs->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488650
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)((int (__thiscall *)(IDataModel *, DmAttributeHandle_t, int))g_pDataModel->GetAttribute_2)(
                           a1: g_pDataModel,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v11 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
        v12 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004887A0
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004888A0
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004888D0
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00488920
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x00488980
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057A370
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
// Address: 0x0057DCE0
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057A3A0
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A3B0
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
// Address: 0x0057DCF0
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD00
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00589E40
// Name: bool IsPresetTimeOperation(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPresetTimeOperation(int nPresetType)
{
  return nPresetType >= 16 && nPresetType <= 19;
}

//------------------------------------------------------------------------------
// Address: 0x00589E60
// Name: public: DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLog_TimeSelection_t *__thiscall DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(DmeLog_TimeSelection_t *this)
{
  char v2; // cl

  this->m_nTimes.m_Times[0].m_tms = 0x80000000;
  this->m_nTimes.m_Times[1].m_tms = 0x80000000;
  this->m_nTimes.m_Times[2].m_tms = 0x80000000;
  this->m_nTimes.m_Times[3].m_tms = 0x80000000;
  this->m_nResampleInterval.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3D4CCCCDu);
  this->m_flIntensity = 1.0;
  this->m_pPresetValue = nullptr;
  this->m_pPresetTimes = nullptr;
  this->m_pOldHeadValue = nullptr;
  this->m_flThreshold = 0.000099999997;
  this->m_OldHeadValueIndex = -1;
  this->m_tHeadPosition.m_tms = 0;
  v2 = *((_BYTE *)this + 60);
  *((_BYTE *)this + 70) &= ~1u;
  this->m_RecordingMode = RECORD_PRESET;
  this->m_TransformWriteMode = TRANSFORM_WRITE_MODE_OVERWRITE;
  this->m_nComponentFlags = LOG_COMPONENTS_ALL;
  *((_BYTE *)this + 60) = v2 & 0xFC | 1;
  this->m_nTimes.m_Times[3].m_tms = 0;
  this->m_nTimes.m_Times[2].m_tms = 0;
  this->m_nTimes.m_Times[1].m_tms = 0;
  this->m_nTimes.m_Times[0].m_tms = 0;
  *(_WORD *)this->m_bInfinite = 0;
  this->m_nFalloffInterpolatorTypes[1] = 6;
  this->m_nFalloffInterpolatorTypes[0] = 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00589F00
// Name: public: DmeLogTransformParams_t::DmeLogTransformParams_t(void)
// Source: json
//------------------------------------------------------------------------------
DmeLogTransformParams_t *__thiscall DmeLogTransformParams_t::DmeLogTransformParams_t(DmeLogTransformParams_t *this)
{
  this->m_RotationLocal = quat_identity;
  this->m_RotationParent = quat_identity;
  this->m_Pivot = vec3_origin;
  this->m_nProceduralType = 0;
  this->m_pRotationLog = nullptr;
  SetIdentityMatrix(matrix: &this->m_Transform);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00589F70
// Name: public: class CDmElement __near * CDmeChannel::GetFromElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetFromElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_fromElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00589F90
// Name: public: class CDmElement __near * CDmeChannel::GetToElement(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeChannel::GetToElement(CDmeChannel *this)
{
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_toElement.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00589FB0
// Name: public: class CDmeLog __near * CDmeChannel::CreateLog(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *__thiscall CDmeChannel::CreateLog(CDmeChannel *this, DmAttributeType_t type)
{
  CDmeTypedLog<Quaternion> *Log; // eax
  CDmeTypedLog<Quaternion> *v4; // esi

  Log = CDmeLog::CreateLog(type, fileid: this->m_fileId);
  v4 = Log;
  if ( Log != nullptr )
    type = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)Log);
  else
    type = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_log.m_pAttribute, value: (DmElementHandle_t *)&type);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0058A000
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupFromAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupFromAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // ebx
  DmAttributeType_t v7; // esi
  CDmElement *v8; // eax
  int v9; // eax

  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_fromAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_FromAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    v7 = v6->m_nFlags & 0x1F;
    if ( (unsigned int)(v7 - 15) <= 0xD )
      v7 -= 14;
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    if ( v8 == nullptr )
      goto LABEL_13;
    v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[2].OnElementSerialized)(a1: v8);
    if ( (unsigned int)(v9 - 15) <= 0xD )
      v9 -= 14;
    if ( v9 != v7 )
LABEL_13:
      CDmeChannel::CreateLog(this, type: v7);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0058A0C0
// Name: protected: class CDmAttribute __near * CDmeChannel::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeChannel::SetupToAttribute(CDmeChannel *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_toElement.m_Storage.m_Handle;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_toAttribute.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0058A130
// Name: public: virtual void CDmeChannel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnAttributeChanged(CDmeChannel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_fromElement.m_Storage.m_ElementType.u.m_Id
    || pAttribute == (CDmAttribute *)this->m_fromAttribute.m_Storage.u.m_Id )
  {
    this->m_log.m_pAttribute = (CDmAttribute *)-1;
  }
  else if ( pAttribute == (CDmAttribute *)this->m_toElement.m_Storage.m_ElementType.u.m_Id
         || pAttribute == (CDmAttribute *)this->m_toAttribute.m_Storage.u.m_Id )
  {
    this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058A170
// Name: public: void CDmeChannel::ScaleSampleTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::ScaleSampleTimes(CDmeChannel *this, float scale)
{
  CDmeLog *v2; // eax

  v2 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
  CDmeLog::ScaleSampleTimes(this: v2, scale);
}

//------------------------------------------------------------------------------
// Address: 0x0058A1A0
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
// Address: 0x0058A1D0
// Name: protected: void CDmeChannel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::OnConstruction(CDmeChannel *this)
{
  CDmaElement<CDmElement> *p_m_fromElement; // ebx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+Ch] [ebp-4h] BYREF

  p_m_fromElement = &this->m_fromElement;
  this->m_nRecordLayerIndex = -1;
  this->m_nNextCurveType = 0;
  this->m_fromElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: &this->CDmElement,
                                       pAttributeName: "fromElement",
                                       type: AT_FIRST_VALUE_TYPE,
                                       pMemory: &this->m_fromElement);
  CDmAttribute::SetElementTypeSymbol(this: p_m_fromElement->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_fromElement->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromAttribute",
         type: AT_STRING,
         pMemory: &this->m_fromAttribute);
  this->m_fromAttribute.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "fromIndex",
         type: AT_INT,
         pMemory: &this->m_fromIndex);
  this->m_fromIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_toElement.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: &this->CDmElement,
                                     pAttributeName: "toElement",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_toElement);
  CDmAttribute::SetElementTypeSymbol(this: this->m_toElement.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_toElement.m_pAttribute->m_nFlags |= 0x1100u;
  v5 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toAttribute",
         type: AT_STRING,
         pMemory: &this->m_toAttribute);
  this->m_toAttribute.m_pAttribute = v5;
  v5->m_nFlags |= 0x500u;
  v6 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "toIndex",
         type: AT_INT,
         pMemory: &this->m_toIndex);
  this->m_toIndex.m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
  value = 1;
  v7 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "mode",
         type: AT_INT,
         pMemory: &this->m_mode);
  this->m_mode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, &value);
  this->m_log.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: &this->CDmElement,
                               pAttributeName: "log",
                               type: AT_FIRST_VALUE_TYPE,
                               pMemory: &this->m_log);
  CDmAttribute::SetElementTypeSymbol(this: this->m_log.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_FromAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0058A340
// Name: protected: void CDmeChannel::Pass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Pass(CDmeChannel *this)
{
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // eax
  CDmAttribute *v3; // edi
  CDmAttribute *v4; // ebx
  DmAttributeType_t v5; // esi
  int *m_pData; // edi
  DmAttributeHandle_t m_FromAttributeHandle; // [esp-4h] [ebp-1Ch]
  CDmrGenericArray v8; // [esp+Ch] [ebp-Ch] BYREF
  CDmrGenericArray array; // [esp+10h] [ebp-8h] BYREF
  CDmeChannel *v10; // [esp+14h] [ebp-4h]

  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  m_FromAttributeHandle = this->m_FromAttributeHandle;
  v10 = this;
  v3 = GetAttribute_2(this: g_pDataModel, a2: m_FromAttributeHandle);
  if ( v3 == nullptr )
    v3 = CDmeChannel::SetupFromAttribute(this);
  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v4 == nullptr )
    v4 = CDmeChannel::SetupToAttribute(this);
  if ( v3 != nullptr && v4 != nullptr && v3 != v4 )
  {
    v5 = v3->m_nFlags & 0x1F;
    if ( (unsigned int)(v5 - 15) > 0xD )
    {
      m_pData = (int *)v3->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v3);
      m_pData = CDmrGenericArrayConst::GetUntyped(this: &array, i: v10->m_fromIndex.m_Storage);
      v5 -= 14;
    }
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: v5, pValue: m_pData);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &v8, pAttribute: v4);
      CDmrGenericArray::Set(this: &v8, i: v10->m_toIndex.m_Storage, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058A420
// Name: public: void CDmeChannel::SetOutput(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::SetOutput(CDmeChannel *this, int pElement, const char *pAttribute, int index)
{
  if ( pElement != 0 )
    pElement = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)pElement);
  else
    pElement = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: this->m_toElement.m_pAttribute,
    value: (DmElementHandle_t *)&pElement);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: pAttribute);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_toAttribute.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pElement);
  CDmAttribute::SetValue<int>(this: this->m_toIndex.m_pAttribute, value: &index);
  CDmeChannel::SetupToAttribute(this);
}

//------------------------------------------------------------------------------
// Address: 0x0058A490
// Name: public: enum ChannelMode_t CDmeChannel::GetMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetMode(CDmeChannel *this)
{
  return this->m_mode.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0058A4A0
// Name: public: class CDmeLog __near * CDmeChannel::GetLog(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmeChannel::GetLog(CDmeChannel *this)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
    && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
  {
    CDmeChannel::SetupFromAttribute(this);
  }
  return (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0058A4F0
// Name: class KeyValues __near * FindLayerInPasteData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindLayerInPasteData(const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *list, CDmeLog *log)
{
  int v2; // ebx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  KeyValues *v6; // edi
  const char *Name; // eax
  _DWORD *Ptr; // eax
  IDataModel_vtbl *v9; // edx
  int v10; // eax
  int v11; // esi
  CDisableUndoScopeGuard noundo; // [esp+Ch] [ebp-Ch] BYREF
  int c; // [esp+14h] [ebp-4h]

  v2 = 0;
  c = list->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&noundo.m_bReleased = 0;
    noundo.m_pNotify = nullptr;
    v4 = IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    noundo.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    v6 = list->m_Memory.m_pMemory[v2];
    Name = KeyValues::GetName(this: v6);
    if ( _V_stricmp(s1: Name, s2: "ControlLayers") == 0 )
      break;
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
LABEL_13:
    if ( ++v2 >= c )
      return nullptr;
  }
  Ptr = KeyValues::GetPtr(this: v6, keyName: "LayerData", defaultValue: nullptr);
  v9 = g_pDataModel->__vftable;
  if ( Ptr == nullptr )
  {
    ((void (__stdcall *)(_DWORD))v9->SetUndoEnabled)(a1: *(_DWORD *)&noundo.m_bOldValue);
    noundo.m_bReleased = true;
    goto LABEL_13;
  }
  v10 = ((int (__stdcall *)(_DWORD))v9->GetElement)(a1: *Ptr);
  if ( v10 != 0 )
  {
    v11 = v10 - 4;
    if ( v10 != 4 )
    {
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == nullptr
        && *(_DWORD *)(v11 + 152) == -1 )
      {
        CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v11);
      }
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v11 + 140)) == log )
      {
        CChangeUndoScopeGuard::Release(this: &noundo);
        return v6;
      }
    }
  }
  CChangeUndoScopeGuard::Release(this: &noundo);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x0058A630
// Name: FindSpanningLayerAndSetIntensity
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSpanningLayerAndSetIntensity@<eax>(
        DmeLog_TimeSelection_t *ts@<edi>,
        LayerSelectionData_t *data@<edx>)
{
  float m_flIntensity; // xmm0_4
  int v3; // eax
  int v4; // ecx
  LayerSelectionData_t::DataLayer_t *m_pMemory; // edx
  float *i; // esi
  float v8; // xmm1_4

  m_flIntensity = ts->m_flIntensity;
  v3 = data->m_vecData.m_Size - 1;
  v4 = 0;
  if ( v3 <= 0 )
    return v4;
  m_pMemory = data->m_vecData.m_Memory.m_pMemory;
  for ( i = &m_pMemory[1].m_flStartFraction; m_flIntensity < m_pMemory->m_flStartFraction || *i < m_flIntensity; i += 2 )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= v3 )
      return v4;
  }
  v8 = *i;
  if ( m_pMemory->m_flStartFraction != *i )
  {
    ts->m_flIntensity = (float)(m_flIntensity - m_pMemory->m_flStartFraction)
                      / (float)(v8 - m_pMemory->m_flStartFraction);
    return v4;
  }
  if ( (float)(m_flIntensity - v8) < 0.0 )
    ts->m_flIntensity = 0.0;
  else
    ts->m_flIntensity = 1.0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0058A6C0
// Name: public: void CDmeChannelRecordingMgr::GetLocalTimeSelection(class DmeLog_TimeSelection_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannelRecordingMgr::GetLocalTimeSelection(
        CDmeChannelRecordingMgr *this@<ecx>,
        int a2@<edi>,
        DmeLog_TimeSelection_t *selection,
        CDmeChannel *nIndex)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v7; // eax
  LayerChannelInfo_t *v9; // edi
  DmeLog_TimeSelection_t *v10; // esi
  bool m_bManipulateInFalloff; // dl
  CDmeChannel *v12; // edi
  CDmeLog *v13; // esi
  DmeTime_t *BeginTime; // eax
  int m_tms; // eax
  DmeTime_t *EndTime; // eax
  int v17; // eax
  CDmAttribute *v18; // eax
  DmeTime_t result; // [esp+4h] [ebp-Ch] BYREF
  CDmeChannelRecordingMgr *v21; // [esp+8h] [ebp-8h]
  LayerChannelInfo_t *info; // [esp+Ch] [ebp-4h] BYREF
  int selectiona; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionb; // [esp+18h] [ebp+8h]
  DmeLog_TimeSelection_t *selectionc; // [esp+18h] [ebp+8h]
  CDmeChannel *pChannel; // [esp+1Ch] [ebp+Ch]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  v21 = this;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    GetElement = g_pDataModel->GetElement;
    info = &m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nIndex];
    v7 = (int)GetElement(this: g_pDataModel, a2: info->m_Channel.m_handle);
    if ( v7 != 0 )
    {
      pChannel = (CDmeChannel *)(v7 - 4);
      if ( v7 != 4 )
      {
        *selection = this->m_TimeSelection;
        v9 = info;
        v10 = selection;
        for ( selectiona = 4; selectiona != 0; --selectiona )
        {
          v10->m_nTimes.m_Times[0] = (DmeTime_t)DmeClipStack_t::ToChildMediaTime(
                                                  this: &v9->m_ClipStack,
                                                  result: (DmeTime_t *)&info,
                                                  t: v10->m_nTimes.m_Times[0],
                                                  bClamp: 0)->m_tms;
          v10 = (DmeLog_TimeSelection_t *)((char *)v10 + 4);
        }
        selection->m_pPresetValue = v9->m_pPresetValue;
        selection->m_pPresetTimes = v9->m_pPresetTimes;
        selection->m_tHeadPosition.m_tms = v9->m_HeadPosition.m_tms;
        selection->m_TransformWriteMode = v9->m_TransformWriteMode;
        selection->m_nComponentFlags = v9->m_ComponentFlags;
        m_bManipulateInFalloff = v9->m_bManipulateInFalloff;
        v12 = pChannel;
        *((_BYTE *)selection + 60) ^= (*((_BYTE *)selection + 60) ^ (2 * m_bManipulateInFalloff)) & 2;
        if ( ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: pChannel->m_log.m_Storage.m_Handle,
               a3: a2) == 0
          && pChannel->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
        {
          CDmeChannel::SetupFromAttribute(this: pChannel);
        }
        v13 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: pChannel->m_log.m_Storage.m_Handle);
        if ( v13 != nullptr )
        {
          if ( selection->m_bInfinite[0] )
          {
            selectionb = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[1].m_tms;
            if ( CDmeLog::GetBeginTime(this: v13, result: (DmeTime_t *)&info)->m_tms >= (int)selectionb )
              BeginTime = &selection->m_nTimes.m_Times[1];
            else
              BeginTime = CDmeLog::GetBeginTime(this: v13, &result);
            m_tms = BeginTime->m_tms;
            selection->m_nTimes.m_Times[1].m_tms = m_tms;
            selection->m_nTimes.m_Times[0].m_tms = m_tms;
          }
          if ( selection->m_bInfinite[1] )
          {
            selectionc = (DmeLog_TimeSelection_t *)selection->m_nTimes.m_Times[2].m_tms;
            if ( CDmeLog::GetEndTime(this: v13, &result)->m_tms <= (int)selectionc )
              EndTime = &selection->m_nTimes.m_Times[2];
            else
              EndTime = CDmeLog::GetEndTime(this: v13, result: (DmeTime_t *)&info);
            v17 = EndTime->m_tms;
            v12 = pChannel;
            selection->m_nTimes.m_Times[2].m_tms = v17;
            selection->m_nTimes.m_Times[3].m_tms = v17;
          }
        }
        if ( (*(_BYTE *)v21 & 8) != 0 )
        {
          v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v12->m_ToAttributeHandle);
          if ( v18 != nullptr || (v18 = CDmeChannel::SetupToAttribute(this: v12)) != nullptr )
          {
            selection->m_pOldHeadValue = v18;
            if ( (v18->m_nFlags & 0x1Fu) - 15 <= 0xD )
              selection->m_OldHeadValueIndex = v12->m_toIndex.m_Storage;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058A890
// Name: public: void CDmeChannel::Play(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Play(CDmeChannel *this, bool useEmptyLog)
{
  CDmeLog *v3; // eax
  CDmeLog *v4; // edi
  int m_tms; // ebx
  int v6; // eax
  DmeTime_t tn; // [esp+4h] [ebp-Ch] BYREF
  DmeTime_t t0; // [esp+8h] [ebp-8h] BYREF
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]

  v9 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v9 != nullptr || (v9 = CDmeChannel::SetupToAttribute(this)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle) == nullptr
      && this->m_FromAttributeHandle == DMATTRIBUTE_HANDLE_INVALID )
    {
      CDmeChannel::SetupFromAttribute(this);
    }
    v3 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_log.m_Storage.m_Handle);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_tms = this->m_TimeState.m_tCurrentTime.m_tms;
      CDmeLog::GetBeginTime(this: v3, result: &t0);
      CDmeLog::GetEndTime(this: v4, result: &tn);
      v6 = t0.m_tms;
      if ( m_tms < t0.m_tms || (v6 = tn.m_tms, m_tms > tn.m_tms) )
        m_tms = v6;
      if ( useEmptyLog
        || CDmeLog::IsEmpty(this: v4) == 0
        || v4->HasDefaultValue(this: v4)
        || CDmeChannel::GetFromAttribute(this) == nullptr )
      {
        ((void (__thiscall *)(CDmeLog *, int, CDmAttribute *, int))v4->GetValue)(
          a1: v4,
          a2: m_tms,
          a3: v9,
          a4: this->m_toIndex.m_Storage);
      }
      else
      {
        CDmeChannel::Pass(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058A9A0
// Name: public: virtual bool CDmeChannel::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeChannel::IsDirty(CDmeChannel *this)
{
  CDmAttribute *v3; // eax

  if ( CDmeOperator::IsDirty(this) )
    return 1;
  switch ( this->m_mode.m_Storage )
  {
    case 1:
LABEL_7:
      v3 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
      if ( (v3 != nullptr || (v3 = CDmeChannel::SetupFromAttribute(this)) != nullptr) && (v3->m_nFlags & 0x4000) != 0 )
        return 1;
      return 0;
    case 2:
      if ( this->m_nRecordLayerIndex != -1 )
        return 1;
      goto LABEL_7;
    case 3:
      return 1;
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0058AA00
// Name: public: void CDmeChannelRecordingMgr::StoreChannelAttributeData(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannelRecordingMgr::StoreChannelAttributeData(
        CDmeChannelRecordingMgr *this,
        CDmAttribute *nChannelIndex,
        bool fromAttr)
{
  CRecordingLayer *m_pActiveRecordingLayer; // ecx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeChannel *v6; // ebx
  CUtlBuffer *v7; // esi
  CDmAttribute *v8; // eax
  CDmElement *v9; // eax
  CDmeTransformControl *v10; // esi
  CDmAttribute *pAttr; // [esp+14h] [ebp+8h]

  m_pActiveRecordingLayer = this->m_pActiveRecordingLayer;
  if ( m_pActiveRecordingLayer != nullptr )
  {
    v4 = (int)&m_pActiveRecordingLayer->m_LayerChannels.m_Memory.m_pMemory[(_DWORD)nChannelIndex];
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)v4);
    if ( v5 != nullptr )
      v6 = (CDmeChannel *)((char *)&v5[-1] + 64);
    else
      v6 = nullptr;
    if ( fromAttr )
    {
      v7 = (CUtlBuffer *)(v4 + 104);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_FromAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupFromAttribute(this: v6);
    }
    else
    {
      v7 = (CUtlBuffer *)(v4 + 56);
      v8 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v8 == nullptr )
        v8 = CDmeChannel::SetupToAttribute(this: v6);
    }
    pAttr = v8;
    if ( v8 != nullptr )
    {
      v7->m_Get = 0;
      v7->m_Put = 0;
      v7->m_Error = 0;
      v7->m_nOffset = 0;
      v7->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v7, nPut: 0);
      if ( !fromAttr )
        CDmeChannel::Play(this: v6, useEmptyLog: true);
      if ( (pAttr->m_nFlags & 0x1Fu) - 15 > 0xD )
      {
        CDmAttribute::Serialize(this: pAttr, buf: v7);
      }
      else if ( fromAttr )
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_fromIndex.m_Storage, buf: v7);
      }
      else
      {
        CDmAttribute::SerializeElement(this: pAttr, nElement: v6->m_toIndex.m_Storage, buf: v7);
      }
    }
    if ( fromAttr )
    {
      v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_fromElement.m_Storage.m_Handle);
      v10 = (CDmeTransformControl *)v9;
      if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        CDmeTransformControl::GetManipulationTransform(this: v10, transform: (matrix3x4_t *)(v4 + 172));
        CDmeTransformControl::GetManipulationRotationLocal(this: v10, rotation: (Quaternion *)(v4 + 220));
        CDmeTransformControl::GetManipulationRotationParent(this: v10, rotation: (Quaternion *)(v4 + 236));
        CDmeTransformControl::GetManipulationPivot(this: v10, pivotPosition: (Vector *)(v4 + 252));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058AC00
// Name: class CDmeLogLayer __near * FindLayerInSnapshot(class CDmrElementArray<class CDmElement> const __near &,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLogLayer *__cdecl FindLayerInSnapshot(const CDmrElementArray<CDmElement> *snapshotArray, CDmeLog *origLog)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeLog *Value; // eax
  int c; // [esp+14h] [ebp+8h]

  if ( snapshotArray->m_pAttribute == nullptr )
    return nullptr;
  v3 = 0;
  c = snapshotArray->m_pStorage->m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: snapshotArray->m_pStorage->m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmElement::m_classType)
      && v5->IsA(this: v5, a2: CDmeLogLayer::m_classType) )
    {
      Value = CDmElement::GetValueElement<CDmeLog>(this: v5, pAttributeName: "origLog");
      if ( Value != nullptr && Value == origLog )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeLogLayer *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0058ACA0
// Name: public: void CDmeChannel::Record(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeChannel::Record(CDmeChannel *this)
{
  void *v1; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v3; // eax
  CDmAttribute *(__thiscall *GetAttribute_2)(IDataModel *, DmAttributeHandle_t); // edx
  CDmeLog *v5; // eax
  bool v6; // zf
  CDmeLogLayer *v7; // edi
  CDmeLog *v8; // ebx
  int m_nProceduralType; // edi
  CDmeLogLayer *LayerInSnapshot; // eax
  int ClipCount; // edi
  CDmeLogLayer *v12; // eax
  KeyValues *LayerInPasteData; // eax
  CDmeLogLayer *Ptr; // eax
  CDmAttribute *SpanningLayerAndSetIntensity; // eax
  CDmeLogLayer *v16; // esi
  CDmElement *(__thiscall *v17)(IDataModel *, DmElementHandle_t); // edx
  int v18; // edi
  CDmeLogLayer *v19; // eax
  CDmElement *(__thiscall *v20)(IDataModel *, DmElementHandle_t); // edx
  CDmeLogLayer *v21; // edi
  int KeyCount; // edi
  int TopmostLayer; // eax
  CDmeLogLayer *Layer; // edi
  int v25; // eax
  CDmElement *v26; // eax
  CDmeTransformControl *v27; // eax
  CDmeTransformControl *v28; // edi
  CDmeChannel *OrientationChannel; // eax
  CDmeLog *Log; // edi
  bool v31; // al
  CDmAttribute *v32; // eax
  CDmeLogLayer *v33; // eax
  CDmeLogLayer *v34; // eax
  BOOL SegmentInterpolationSetting; // eax
  DmeTime_t v36; // [esp-14h] [ebp-E0h]
  int v37; // [esp-Ch] [ebp-D8h]
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-D0h]
  DmeLog_TimeSelection_t timeSelection; // [esp+4h] [ebp-C8h] BYREF
  _BYTE blendTimeSelction[100]; // [esp+50h] [ebp-7Ch] OVERLAPPED BYREF
  CDmrElementArray<CDmElement> snapshotArray; // [esp+B4h] [ebp-18h] BYREF
  CDmeLogLayer *pModLayer; // [esp+BCh] [ebp-10h]
  int bFeatherBlendInFalloff; // [esp+C0h] [ebp-Ch]
  CDmeLogLayer *sourceLayer; // [esp+C4h] [ebp-8h]
  CDmeLogLayer *targetLayer; // [esp+C8h] [ebp-4h]

  v1 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_fromElement.m_Storage.m_Handle;
  pModLayer = (CDmeLogLayer *)this;
  v3 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  GetAttribute_2 = g_pDataModel->GetAttribute_2;
  snapshotArray.m_pAttribute = v3;
  sourceLayer = (CDmeLogLayer *)GetAttribute_2(this: g_pDataModel, a2: *((DmAttributeHandle_t *)v1 + 38));
  if ( sourceLayer != nullptr
    || (sourceLayer = (CDmeLogLayer *)CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1)) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35)) == nullptr && *((_DWORD *)v1 + 38) == -1 )
      CDmeChannel::SetupFromAttribute(this: (CDmeChannel *)v1);
    v5 = (CDmeLog *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v1 + 35));
    v6 = *((_DWORD *)v1 + 42) == 0x80000000;
    v7 = *((CDmeLogLayer **)v1 + 41);
    v8 = v5;
    targetLayer = v7;
    if ( v6 )
      *((_DWORD *)v1 + 42) = v7;
    if ( (*(_BYTE *)g_pChannelRecordingMgr & 2) != 0 )
    {
      if ( *((_DWORD *)v1 + 43) != -1 )
      {
        DmeLog_TimeSelection_t::DmeLog_TimeSelection_t(this: &timeSelection);
        CDmeChannelRecordingMgr::GetLocalTimeSelection(
          this: g_pChannelRecordingMgr,
          a2: (int)v7,
          selection: &timeSelection,
          nIndex: *((CDmeChannel **)v1 + 43));
        m_nProceduralType = g_pChannelRecordingMgr->m_nProceduralType;
        bFeatherBlendInFalloff = m_nProceduralType;
        if ( m_nProceduralType == 0 && timeSelection.m_pPresetTimes != nullptr )
        {
          bFeatherBlendInFalloff = 22;
          m_nProceduralType = 22;
        }
        switch ( m_nProceduralType )
        {
          case 8:
          case 10:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
          case 19:
          case 20:
          case 22:
            LayerInPasteData = FindLayerInPasteData(list: &g_pChannelRecordingMgr->m_PasteTarget, log: v8);
            if ( LayerInPasteData == nullptr )
              goto LABEL_30;
            Ptr = (CDmeLogLayer *)KeyValues::GetPtr(this: LayerInPasteData, keyName: "LayerData", defaultValue: nullptr);
            *(DmeLog_TimeSelection_t *)&blendTimeSelction[24] = timeSelection;
            targetLayer = Ptr;
            SpanningLayerAndSetIntensity = (CDmAttribute *)FindSpanningLayerAndSetIntensity(
                                                             ts: (DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                                                             data: (LayerSelectionData_t *)Ptr);
            v16 = targetLayer;
            v17 = g_pDataModel->GetElement;
            v18 = 8 * (_DWORD)SpanningLayerAndSetIntensity;
            snapshotArray.m_pAttribute = SpanningLayerAndSetIntensity;
            v19 = (CDmeLogLayer *)v17(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&targetLayer->m_ref + 2)
                                                         + 8 * (_DWORD)SpanningLayerAndSetIntensity
                                                         + 4));
            v20 = g_pDataModel->GetElement;
            sourceLayer = v19;
            v21 = (CDmeLogLayer *)v20(
                                    this: g_pDataModel,
                                    a2: *(DmElementHandle_t *)(*((_DWORD *)&v16->m_ref + 2) + v18 + 12));
            targetLayer = v21;
            if ( sourceLayer == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) <= 0 )
              goto LABEL_29;
            if ( v21 == nullptr )
              goto LABEL_29;
            if ( CDmeLogLayer::GetKeyCount(this: v21) <= 0 )
              goto LABEL_29;
            KeyCount = CDmeLogLayer::GetKeyCount(this: v21);
            if ( CDmeLogLayer::GetKeyCount(this: sourceLayer) != KeyCount )
              goto LABEL_29;
            TopmostLayer = CDmeLog::GetTopmostLayer(this: v8);
            Layer = CDmeLog::GetLayer(this: v8, index: TopmostLayer);
            if ( IsPresetTimeOperation(nPresetType: bFeatherBlendInFalloff) )
            {
              v25 = bFeatherBlendInFalloff;
              if ( bFeatherBlendInFalloff == 16 || (LOBYTE(bFeatherBlendInFalloff) = 0, v25 == 19) )
                LOBYTE(bFeatherBlendInFalloff) = 1;
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int))v8->BlendTimesUsingTimeSelection)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id,
                a7: bFeatherBlendInFalloff);
LABEL_29:
              v1 = (void *)pModLayer;
              goto LABEL_30;
            }
            if ( snapshotArray.m_pAttribute != nullptr )
            {
              v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)&v16->m_ref + 2) + 4));
              ((void (__thiscall *)(CDmeLog *, CDmElement *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection)(
                a1: v8,
                a2: (const CDmeLogLayer *)v26,
                a3: sourceLayer,
                a4: targetLayer,
                a5: Layer,
                a6: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a7: false,
                a8: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            else
            {
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, _BYTE *, _DWORD, int, int, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: sourceLayer,
                a3: targetLayer,
                a4: Layer,
                a5: (const DmeLog_TimeSelection_t *)&blendTimeSelction[24],
                a6: false,
                a7: true,
                a8: true,
                a9: (DmeTime_t)v16->m_Name.m_Storage.u.CDmElement::m_Id);
            }
            CDmeChannel::Play(this: (CDmeChannel *)pModLayer, useEmptyLog: false);
            break;
          case 9:
            CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
              this: &snapshotArray,
              pAttribute: (CDmAttribute *)g_pChannelRecordingMgr->m_pRevealTarget);
            LayerInSnapshot = FindLayerInSnapshot(&snapshotArray, origLog: v8);
            if ( LayerInSnapshot == nullptr )
              goto LABEL_30;
            v8->RevealUsingTimeSelection(this: v8, a2: &timeSelection, a3: LayerInSnapshot);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
          case 11:
            ClipCount = CDmeTrack::GetClipCount(this: (CVTFTexture *)v8);
            if ( ClipCount < 3 )
            {
LABEL_30:
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            else
            {
              targetLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 1);
              pModLayer = CDmeLog::GetLayer(this: v8, index: ClipCount - 2);
              v12 = CDmeLog::GetLayer(this: v8, index: ClipCount - 3);
              ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, CDmeLogLayer *, DmeLog_TimeSelection_t *, int, _DWORD, _DWORD, _DWORD))v8->BlendLayersUsingTimeSelection_2)(
                a1: v8,
                a2: v12,
                a3: pModLayer,
                a4: targetLayer,
                a5: &timeSelection,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0);
              CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            }
            break;
          default:
            DmeLogTransformParams_t::DmeLogTransformParams_t(this: (DmeLogTransformParams_t *)blendTimeSelction);
            *(_DWORD *)&blendTimeSelction[92] = m_nProceduralType;
            v27 = CastElement<CDmeTransformControl>(pElement: (CDmElement *)snapshotArray.m_pAttribute);
            v28 = v27;
            if ( v27 != nullptr )
            {
              CDmeTransformControl::GetManipulationTransform(this: v27, transform: (matrix3x4_t *)blendTimeSelction);
              CDmeTransformControl::GetManipulationRotationLocal(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[48]);
              CDmeTransformControl::GetManipulationRotationParent(
                this: v28,
                rotation: (Quaternion *)&blendTimeSelction[64]);
              CDmeTransformControl::GetManipulationPivot(this: v28, pivotPosition: (Vector *)&blendTimeSelction[80]);
              OrientationChannel = CDmeTransformControl::GetOrientationChannel(this: v28);
              if ( OrientationChannel != nullptr )
              {
                Log = CDmeChannel::GetLog(this: OrientationChannel);
                if ( Log != nullptr && Log->GetDataType(this: Log) == AT_QUATERNION )
                  *(_DWORD *)&blendTimeSelction[96] = Log;
              }
            }
            else
            {
              *((_BYTE *)&timeSelection + 60) &= ~2u;
            }
            CDmeChannelRecordingMgr::StoreChannelAttributeData(
              this: g_pChannelRecordingMgr,
              nChannelIndex: *((CDmAttribute **)v1 + 43),
              fromAttr: true);
            v31 = g_pChannelRecordingMgr->m_pModificationLayer != nullptr
               && (*(_BYTE *)g_pChannelRecordingMgr & 0x10) == 0;
            ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, _DWORD, DmeLog_TimeSelection_t *, _BYTE *, CDmeLogLayer *, _DWORD, bool, int))v8->StampKeyAtHead)(
              a1: v8,
              a2: targetLayer,
              a3: *((_DWORD *)v1 + 42),
              a4: &timeSelection,
              a5: blendTimeSelction,
              a6: sourceLayer,
              a7: *((_DWORD *)v1 + 24),
              a8: !v31,
              a9: -1);
            CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
            break;
        }
      }
    }
    else
    {
      v32 = (CDmAttribute *)CDmeLog::GetTopmostLayer(this: v5);
      snapshotArray.m_pAttribute = v32;
      if ( v32 != (CDmAttribute *)-1
        && (v36.m_tms = *((_DWORD *)v1 + 42),
            v33 = CDmeLog::GetLayer(this: v8, index: (int)v32),
            CDmeLogLayer::GetSegmentInterpolationSetting(
              this: v33,
              startTime: v36,
              endTime: (DmeTime_t)0x80000000,
              bExcludeActualEndTimeKey: false) != 0) )
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD, _DWORD))v8->InsertKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42), a3: 0);
        v37 = *((_DWORD *)v1 + 44);
        targetLayer = (CDmeLogLayer *)v8->__vftable;
        v34 = CDmeLog::GetLayer(this: v8, index: (int)snapshotArray.m_pAttribute);
        SegmentInterpolationSetting = CDmeLogLayer::GetSegmentInterpolationSetting(this: v34, time: (DmeTime_t)v7);
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, BOOL, int))targetLayer->m_NonInterpolatedSegments.m_Storage.m_pElements)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: SegmentInterpolationSetting,
          a6: v37);
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
      else
      {
        if ( *((CDmeLogLayer **)v1 + 42) != v7 )
          ((void (__thiscall *)(CDmeLog *, _DWORD))v8->SetDuplicateKeyAtTime)(a1: v8, a2: *((_DWORD *)v1 + 42));
        ((void (__thiscall *)(CDmeLog *, CDmeLogLayer *, CDmeLogLayer *, _DWORD, _DWORD, _DWORD))v8->SetKey)(
          a1: v8,
          a2: v7,
          a3: sourceLayer,
          a4: *((_DWORD *)v1 + 24),
          a5: 0,
          a6: *((_DWORD *)v1 + 44));
        *((_DWORD *)v1 + 44) = 0;
        CDmeChannel::Play(this: (CDmeChannel *)v1, useEmptyLog: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058B210
// Name: public: virtual void CDmeChannel::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::Operate(CDmeChannel *this)
{
  switch ( this->m_mode.m_Storage )
  {
    case 1:
      CDmeChannel::Pass(this);
      break;
    case 2:
      CDmeChannel::Record(this);
      break;
    case 3:
      CDmeChannel::Play(this, useEmptyLog: false);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058B250
// Name: public: virtual void CDmeChannel::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::GetInputAttributes(
        CDmeChannel *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v4; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 && m_Storage != 3 )
  {
    v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_FromAttributeHandle);
    if ( v4 != nullptr || (v4 = CDmeChannel::SetupFromAttribute(this)) != nullptr )
    {
      m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
      m_Size = attrs->m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)attrs,
          num: m_Size - m_nAllocationCount + 1);
      ++attrs->m_Size;
      m_pMemory = attrs->m_Memory.m_pMemory;
      v8 = attrs->m_Size - m_Size - 1;
      attrs->m_pElements = attrs->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = &attrs->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058B2F0
// Name: public: virtual void CDmeChannel::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeChannel::GetOutputAttributes(
        CDmeChannel *this@<ecx>,
        int a2@<edi>,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Storage; // eax
  CDmAttribute *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax

  m_Storage = this->m_mode.m_Storage;
  if ( m_Storage != 0 )
  {
    if ( m_Storage != 2 && m_Storage != 1 )
      goto LABEL_9;
    v5 = (CDmAttribute *)((int (__thiscall *)(IDataModel *, DmAttributeHandle_t, int))g_pDataModel->GetAttribute_2)(
                           a1: g_pDataModel,
                           a2: this->m_FromAttributeHandle,
                           a3: a2);
    if ( v5 == nullptr )
      v5 = CDmeChannel::SetupFromAttribute(this);
    v6 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
    if ( v6 == nullptr )
      v6 = CDmeChannel::SetupToAttribute(this);
    if ( v5 != v6 )
    {
LABEL_9:
      v7 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
      if ( v7 != nullptr || (v7 = CDmeChannel::SetupToAttribute(this)) != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v11 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
        v12 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058B440
// Name: protected: CDmeChannel::CDmeChannel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeChannel::CDmeChannel(
        CDmeChannel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeChannel_vtbl *)&CDmeChannel::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeChannel::`vftable'{for `CDmElement'};
  this->m_fromElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_fromElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_fromElement.m_pAttribute = nullptr;
  this->m_fromAttribute.m_pAttribute = nullptr;
  this->m_fromAttribute.m_Storage.u.m_Id = -1;
  this->m_fromIndex.m_pAttribute = nullptr;
  this->m_fromIndex.m_Storage = 0;
  this->m_toElement.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_toElement.m_pAttribute = nullptr;
  this->m_toElement.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_toAttribute.m_pAttribute = nullptr;
  this->m_toAttribute.m_Storage.u.m_Id = -1;
  this->m_toIndex.m_pAttribute = nullptr;
  this->m_toIndex.m_Storage = 0;
  this->m_mode.m_pAttribute = nullptr;
  this->m_mode.m_Storage = 0;
  this->m_log.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_log.m_pAttribute = nullptr;
  this->m_log.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_TimeState.m_timeOutsideTimeframe.m_tms = 0x80000000;
  this->m_TimeState.m_tCurrentTime.m_tms = 0x80000000;
  this->m_TimeState.m_tPreviousTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0058B540
// Name: public: virtual bool CDmeChannel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeChannel::IsA(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0058B570
// Name: public: virtual int CDmeChannel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::GetInheritanceDepth(CDmeChannel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeChannel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0058B610
// Name: protected: virtual void CDmeChannel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeChannel::PerformConstruction(CDmeChannel *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
  CDmeChannel::OnConstruction(this: (CDmeChannel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0062E570
// Name: protected: virtual int CDmeChannel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeChannel::AllocatedSize(CDmeExpressionOperator *this)
{
  return 180;
}

//------------------------------------------------------------------------------
// Address: 0x006B8280
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
// Address: 0x006BCAE0
// Name: _dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeChannel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeChannel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B82B0
// Name: _dynamic_initializer_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeChannel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeChannel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B82C0
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
// Address: 0x006BCAF0
// Name: _dynamic_atexit_destructor_for__s_ChannelRecordingMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ChannelRecordingMgr__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_ChannelRecordingMgr.m_PasteTarget);
}

//------------------------------------------------------------------------------
// Address: 0x006BCB00
// Name: _dynamic_atexit_destructor_for__g_CDmeChannel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeChannel_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeChannel_Factory.m_CallBackList);
}

} // namespace vmap
