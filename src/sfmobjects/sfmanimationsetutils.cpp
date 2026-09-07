// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: sfmobjects/sfmanimationsetutils.cpp
// Functions: 26
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0053F890
// Name: void RetimeLogData(class CDmeChannelsClip __near *,class CDmeChannelsClip __near *,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RetimeLogData(CDmeChannelsClip *pSrcChannelsClip, CDmeChannelsClip *pDstChannelsClip, CDmeLog *pLog)
{
  int v3; // edx
  int v4; // ecx
  int f; // xmm1_4
  CDmAttribute *KeyCount; // ebx
  int i; // esi
  CDmeLog_vtbl *v8; // edx
  DmeTime_t result; // [esp+18h] [ebp-24h] BYREF
  float scale; // [esp+1Ch] [ebp-20h]
  DmeTime_t dstStart; // [esp+20h] [ebp-1Ch] BYREF
  DmeTime_t srcStart; // [esp+24h] [ebp-18h] BYREF
  DmeTime_t keyTime; // [esp+28h] [ebp-14h] BYREF
  DmeTime_t srcScale; // [esp+2Ch] [ebp-10h] BYREF
  DmeTime_t dstScale; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t dstOffset; // [esp+34h] [ebp-8h] BYREF
  DmeTime_t srcOffset; // [esp+38h] [ebp-4h] BYREF

  *(float *)&srcScale.m_tms = CDmeClip::GetTimeScale(this: &pSrcChannelsClip->CDmeClip);
  *(float *)&dstScale.m_tms = CDmeClip::GetTimeScale(this: &pDstChannelsClip->CDmeClip);
  CDmeClip::GetStartTime(this: &pSrcChannelsClip->CDmeClip, result: &srcStart);
  CDmeClip::GetStartTime(this: &pDstChannelsClip->CDmeClip, result: &dstStart);
  CDmeClip::GetTimeOffset(this: &pSrcChannelsClip->CDmeClip, result: &srcOffset);
  CDmeClip::GetTimeOffset(this: &pDstChannelsClip->CDmeClip, result: &dstOffset);
  v3 = srcOffset.m_tms - srcStart.m_tms;
  v4 = dstOffset.m_tms - dstStart.m_tms;
  srcOffset.m_tms -= srcStart.m_tms;
  dstOffset.m_tms -= dstStart.m_tms;
  if ( *(float *)&srcScale.m_tms != *(float *)&dstScale.m_tms || v3 != v4 )
  {
    f = dstScale.m_tms;
    dstScale.m_tms = v4 - v3;
    scale = *(float *)&f / *(float *)&srcScale.m_tms;
    DmeTime_t::operator*=(this: &dstScale, result: &keyTime, f: *(float *)&f);
    KeyCount = CDmeLog::GetKeyCount(this: pLog);
    for ( i = 0; i < (int)KeyCount; ++i )
    {
      pLog->GetKeyTime(this: pLog, result: &keyTime, a3: i);
      srcScale.m_tms = keyTime.m_tms;
      DmeTime_t::operator*=(this: &srcScale, &result, f: scale);
      v8 = pLog->__vftable;
      keyTime.m_tms = srcScale.m_tms + dstScale.m_tms;
      ((void (__thiscall *)(CDmeLog *, int, int))v8->SetKeyTime)(a1: pLog, a2: i, a3: srcScale.m_tms + dstScale.m_tms);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053FB30
// Name: class CDmeChannelsClip __near * CreateChannelsClip(class CDmeAnimationSet __near *,class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__cdecl CreateChannelsClip(CDmeAnimationSet *pAnimationSet, CDmeFilmClip *pOwnerClip)
{
  CDmeTrackGroup *result; // eax
  CDmeTrack *v3; // ecx
  const char *m_pAsString; // eax
  CDmeClip *NamedClip; // eax
  CDmeChannelsClip *v6; // esi
  const char *v7; // eax
  int v8; // eax
  DmeTime_t *Duration; // eax
  int v10; // edi
  int v11; // eax
  DmeTime_t childMediaDuration; // [esp+14h] [ebp-Ch] BYREF
  DmeTime_t childMediaTime; // [esp+18h] [ebp-8h] BYREF
  CDmeTrack *pAnimSetEditorTrack; // [esp+1Ch] [ebp-4h] BYREF

  result = CDmeClip::FindOrAddTrackGroup(this: pOwnerClip, pTrackGroupName: "channelTrackGroup");
  if ( result != nullptr )
  {
    v3 = CDmeTrackGroup::FindOrAddTrack(this: result, pTrackName: "animSetEditorChannels", trackType: DMECLIP_FIRST);
    m_pAsString = pAnimationSet->m_Name.m_Storage.u.m_pAsString;
    pAnimSetEditorTrack = v3;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    NamedClip = CDmeTrack::FindNamedClip(this: v3, name: m_pAsString);
    v6 = (CDmeChannelsClip *)NamedClip;
    if ( NamedClip == nullptr || !NamedClip->IsA(this: NamedClip, a2: CDmeChannelsClip::m_classType) )
    {
      v7 = pAnimationSet->m_Name.m_Storage.u.m_pAsString;
      if ( v7 == (const char *)-1 )
        v7 = &pParentName;
      v6 = CreateElement<CDmeChannelsClip>(pObjectName: v7, fileid: pAnimationSet->m_fileId, pObjectID: nullptr);
      CDmeTrack::AddClip(this: pAnimSetEditorTrack, clip: &v6->CDmeClip);
    }
    CDmeClip::GetStartInChildMediaTime(this: pOwnerClip, result: &childMediaTime);
    v8 = DmeTime_t::RoundSecondsToTMS(sec: 0x40A00000u);
    CDmeClip::SetStartTime(this: &v6->CDmeClip, t: (DmeTime_t)(childMediaTime.m_tms - v8));
    Duration = CDmeClip::GetDuration(this: pOwnerClip, result: (DmeTime_t *)&pAnimSetEditorTrack);
    CDmeClip::ToChildMediaDuration(this: pOwnerClip, result: &childMediaDuration, dt: (DmeTime_t)Duration->m_tms);
    v10 = DmeTime_t::RoundSecondsToTMS(sec: 0x40A00000u);
    v11 = DmeTime_t::RoundSecondsToTMS(sec: 0x40A00000u);
    CDmeClip::SetDuration(this: &v6->CDmeClip, t: (DmeTime_t)(childMediaDuration.m_tms + v10 + v11));
    return (CDmeTrackGroup *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0053FC50
// Name: class CDmeChannel __near * CreateConstantValuedLog<int>(class CDmeChannelsClip __near *,char const __near *,class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl CreateConstantValuedLog<int>(
        int channelsClip,
        const char *pName,
        CDmElement *pToElement,
        const char *pToAttr,
        const int *value)
{
  CDmeChannelsClip *v5; // edi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  char *v9; // esi
  CDmeTypedLog<int> *Log; // eax
  const int *v12; // [esp-10h] [ebp-18h]

  v5 = (CDmeChannelsClip *)channelsClip;
  v6 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
         a3: pName,
         a4: *(DmFileId_t *)(channelsClip + 56),
         a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeChannel::m_classType) )
    v9 = (char *)&v8[-1] + 64;
  else
    v9 = nullptr;
  CDmeChannel::SetMode(this: (CDmeChannel *)v9, mode: CM_PLAY);
  CDmeChannel::CreateLog(this: (CDmeChannel *)v9, type: AT_INT);
  CDmeChannel::SetOutput(this: (CDmeChannel *)v9, pElement: (int)pToElement, pAttribute: pToAttr, index: 0);
  v12 = value;
  Log = (CDmeTypedLog<int> *)CDmeChannel::GetLog(this: (CDmeChannel *)v9);
  CDmeTypedLog<int>::InsertKey(
    this: Log,
    nTime: 0,
    value: v12,
    interpSetting: SEGMENT_INTERPOLATE,
    curveType: 0,
    bIgnoreTolerance: 0);
  if ( v9 != nullptr )
    channelsClip = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v9 + 4));
  else
    channelsClip = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &v5->m_Channels,
    src: (DmElementHandle_t *)&channelsClip);
  return (CDmeChannel *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x005403C0
// Name: class CDmeChannelsClip __near * FindChannelsClip(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__cdecl FindChannelsClip(CDmeDag *pDag)
{
  CDmeChannel *Referring; // eax
  CExpressionCalculator *Transform; // eax
  int v3; // ebx
  unsigned int v4; // edi
  CExpressionCalculator *Bone; // eax

  if ( pDag == nullptr )
    return nullptr;
  Referring = FindReferringElement<CDmeChannel>(
                pElement: (CExpressionCalculator *)pDag,
                symAttrName: (CUtlSymbolLarge)-1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
  {
    Transform = (CExpressionCalculator *)CDmeDag::GetTransform(this: pDag);
    Referring = FindReferringElement<CDmeChannel>(
                  pElement: Transform,
                  symAttrName: (CUtlSymbolLarge)-1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
    {
      if ( ((int (__thiscall *)(_DWORD, _DWORD))pDag->IsA)(
             a1: pDag,
             a2: (CUtlSymbolLarge)CDmeGameModel::m_classType.u.m_Id) )
      {
        v3 = CDmeGameModel::NumBones(this: (CDmeGameModel *)pDag);
        v4 = 0;
        if ( v3 > 0 )
        {
          while ( 1 )
          {
            Bone = (CExpressionCalculator *)CDmeGameModel::GetBone(this: (CDmeGameModel *)pDag, index: v4);
            Referring = FindReferringElement<CDmeChannel>(
                          pElement: Bone,
                          symAttrName: (CUtlSymbolLarge)-1,
                          bMustBeInSameFile: false,
                          depth: TD_ALL);
            if ( Referring != nullptr )
              break;
            if ( (int)++v4 >= v3 )
              return nullptr;
          }
          return FindReferringElement<CDmeChannelsClip>(
                   pElement: (CExpressionCalculator *)&Referring->CDmElement,
                   symAttrName: (CUtlSymbolLarge)-1,
                   bMustBeInSameFile: false,
                   depth: TD_ALL);
        }
      }
      return nullptr;
    }
  }
  return FindReferringElement<CDmeChannelsClip>(
           pElement: (CExpressionCalculator *)&Referring->CDmElement,
           symAttrName: (CUtlSymbolLarge)-1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x00540480
// Name: void TransferRemainingChannels(class CDmeFilmClip __near *,class CDmeChannelsClip __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransferRemainingChannels(CDmeFilmClip *shot, CDmeChannelsClip *destClip, CDmeChannelsClip *srcClip)
{
  CDmeChannelsClip *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  int v7; // ecx
  char *v8; // esi
  CDmeLog *Log; // eax
  IDataModel_vtbl *v10; // esi
  int v11; // eax
  DmAttributeReferenceIterator_t v12; // edi
  CDmeTrack *m_pOwner; // esi
  IDataModel_vtbl *v14; // esi
  int v15; // eax
  int channelsCount; // [esp+Ch] [ebp-4h]

  v3 = srcClip;
  if ( srcClip != destClip )
  {
    v4 = 0;
    channelsCount = srcClip->m_Channels.m_Storage.m_Size;
    if ( channelsCount > 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Channels.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeChannel::m_classType) )
        {
          v8 = (char *)&v6[-1] + 64;
          if ( v8 != nullptr )
          {
            _Msg(a1: v7, a2: "Transferring '%s'\n");
            srcClip = (CDmeChannelsClip *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v8 + 4));
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &destClip->m_Channels,
              src: (DmElementHandle_t *)&srcClip);
            CDmeChannel::SetMode(this: (CDmeChannel *)v8, mode: CM_PLAY);
            Log = CDmeChannel::GetLog(this: (CDmeChannel *)v8);
            if ( Log != nullptr )
              RetimeLogData(pSrcChannelsClip: v3, pDstChannelsClip: destClip, pLog: Log);
          }
        }
        ++v4;
      }
      while ( v4 < channelsCount );
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &v3->m_Channels);
    v10 = g_pDataModel->__vftable;
    v11 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
    v12 = v10->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v11);
    if ( v12 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    {
      while ( 1 )
      {
        m_pOwner = (CDmeTrack *)g_pDataModel->GetAttribute(this: g_pDataModel, a2: v12)->m_pOwner;
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeTrack::m_classType) )
          break;
        v12 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v12);
        if ( v12 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
          return;
      }
      CDmeTrack::RemoveClip(this: m_pOwner, clip: &v3->CDmeClip);
      v14 = g_pDataModel->__vftable;
      v15 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      v14->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v15);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00540600
// Name: void AttachChannelToTranformControl(char const __near *,enum ControlType_t,class CDmeChannel __near *,class CDmeTransformControl __near *,class CDmeTransform __near *,class CDmeChannelsClip __near *,class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AttachChannelToTranformControl(
        const char *pName,
        ControlType_t controlType,
        int pAttachChannel,
        CDmeTransformControl *pTransformControl,
        CDmeTransform *pTransform,
        CDmeChannelsClip *pSrcChannelsClip,
        CDmeChannelsClip *pDstChannelsClip,
        bool bUseExistingLogData)
{
  CDmeChannel *v8; // edi
  const char *v9; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmAttribute *v13; // eax
  CDmeChannelsClip *v14; // ebx
  int v15; // eax
  CDmaVar<Vector> *Bookmarks; // eax
  CDmeTransformControl *v17; // esi
  CDmAttribute *OrientationAttr; // eax
  CDmaVar<Quaternion> *Orientation; // eax
  CDmeTransformControl *v20; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v22; // esi
  CDmeTimeFrame *TimeFrame; // edi
  CDmeTimeFrame *v24; // eax
  int m_tms; // edx
  float m_Storage; // xmm0_4
  int v27; // ebx
  int v28; // edi
  float v29; // xmm1_4
  int v30; // ecx
  CDmAttribute *KeyCount; // ebx
  int i; // edi
  CDmaVar<Vector> *v33; // eax
  CDmaVar<Quaternion> *v34; // eax
  char szName[512]; // [esp+2Ch] [ebp-21Ch] BYREF
  DmeTime_t v36; // [esp+22Ch] [ebp-1Ch] BYREF
  DmeTime_t result; // [esp+230h] [ebp-18h] BYREF
  float srcScale; // [esp+234h] [ebp-14h]
  DmeTime_t originalTime; // [esp+238h] [ebp-10h] BYREF
  float dstScale; // [esp+23Ch] [ebp-Ch]
  DmeTime_t timeOffset; // [esp+240h] [ebp-8h]
  DmeTime_t v42; // [esp+244h] [ebp-4h] BYREF

  v8 = (CDmeChannel *)pAttachChannel;
  if ( pAttachChannel != 0 )
    goto LABEL_12;
  v9 = "p";
  if ( controlType != CONTROL_TYPE_POSITION )
    v9 = "o";
  V_snprintf(pDest: szName, maxLen: 512, pFormat: "%s_%s", pName, v9);
  v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
          a3: szName,
          a4: pDstChannelsClip->m_fileId,
          a5: nullptr);
  v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
  v12 = v11;
  if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeChannel::m_classType) )
    v8 = (CDmeChannel *)((char *)&v12[-1] + 64);
  else
    v8 = nullptr;
  v13 = controlType != CONTROL_TYPE_POSITION
      ? CDmeGlobalFlexControllerOperator::GetGlobalIndex(this: pTransform)
      : CDmeTrack::GetClipCount(this: pTransform);
  CDmeChannel::SetOutput(this: v8, pAttribute: v13, index: 0);
  if ( v8 != nullptr )
  {
LABEL_12:
    v14 = pSrcChannelsClip;
    if ( pSrcChannelsClip != nullptr && pSrcChannelsClip != pDstChannelsClip )
    {
      pAttachChannel = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v8->CDmElement);
      v15 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
              this: &v14->m_Channels,
              value: (const DmElementHandle_t *)&pAttachChannel);
      if ( v15 != -1 )
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
          this: &v14->m_Channels,
          elem: v15);
    }
    if ( v8 != nullptr )
    {
      pAttachChannel = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v8->CDmElement);
      if ( CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
             this: &pDstChannelsClip->m_Channels,
             value: (const DmElementHandle_t *)&pAttachChannel) != -1 )
        goto LABEL_21;
      pAttachChannel = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v8->CDmElement);
    }
    else
    {
      pAttachChannel = -1;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &pDstChannelsClip->m_Channels,
      src: (DmElementHandle_t *)&pAttachChannel);
LABEL_21:
    if ( controlType != CONTROL_TYPE_POSITION )
    {
      Orientation = CDmeTransform::GetOrientation(this: pTransform);
      v20 = pTransformControl;
      CDmeTransformControl::SetOrientation(this: pTransformControl, orientation: &Orientation->m_Storage);
      CDmeTransformControl::SetOrientationChannel(this: v20, pChannel: (int)v8);
      OrientationAttr = CDmeTransformControl::GetOrientationAttr(this: v20);
    }
    else
    {
      Bookmarks = CDmeBookmarkSet::GetBookmarks(this: pTransform);
      v17 = pTransformControl;
      CDmeTransformControl::SetPosition(this: pTransformControl, position: &Bookmarks->m_Storage);
      CDmeTransformControl::SetPositionChannel(this: v17, pChannel: (int)v8);
      OrientationAttr = CDmeTransformControl::GetPositionAttr(this: v17);
    }
    CDmeChannel::SetInput(this: v8, pAttribute: OrientationAttr, index: 0);
    CDmeChannel::SetMode(this: v8, mode: CM_PLAY);
    Log = CDmeChannel::GetLog(this: v8);
    v22 = (CDmeTypedLog<Quaternion> *)Log;
    if ( bUseExistingLogData )
    {
      if ( Log == nullptr )
        goto LABEL_35;
      if ( v14 != nullptr )
      {
        TimeFrame = CDmeClip::GetTimeFrame(this: &v14->CDmeClip);
        v24 = CDmeClip::GetTimeFrame(this: &pDstChannelsClip->CDmeClip);
        m_tms = TimeFrame->m_Start.m_Storage.m_tms;
        m_Storage = TimeFrame->m_Scale.m_Storage;
        v27 = TimeFrame->m_Offset.m_Storage.m_tms;
        v28 = v24->m_Start.m_Storage.m_tms;
        v29 = v24->m_Scale.m_Storage;
        v30 = v24->m_Offset.m_Storage.m_tms;
        srcScale = m_Storage;
        dstScale = v29;
        if ( m_tms != v28 || v27 != v30 || m_Storage != v29 )
        {
          timeOffset.m_tms = m_tms + v30 - v28 - v27;
          KeyCount = CDmeLog::GetKeyCount(this: v22);
          for ( i = 0; i < (int)KeyCount; ++i )
          {
            v22->GetKeyTime(this: v22, result: &originalTime, a3: i);
            pAttachChannel = originalTime.m_tms;
            DmeTime_t::operator/=(this: (DmeTime_t *)&pAttachChannel, &result, f: srcScale);
            v42.m_tms = timeOffset.m_tms + pAttachChannel;
            DmeTime_t::operator*=(this: &v42, result: &v36, f: dstScale);
            ((void (__thiscall *)(CDmeTypedLog<Quaternion> *, int, int))v22->SetKeyTime)(a1: v22, a2: i, a3: v42.m_tms);
          }
        }
        return;
      }
    }
    if ( Log != nullptr )
    {
      Log->ClearKeys(this: Log);
      goto LABEL_36;
    }
LABEL_35:
    v22 = CDmeChannel::CreateLog(this: v8, type: g_ChannelTypes[controlType]);
LABEL_36:
    if ( controlType != CONTROL_TYPE_POSITION )
    {
      v34 = CDmeTransform::GetOrientation(this: pTransform);
      CDmeTypedLog<Quaternion>::SetKey(
        this: v22,
        time: 0,
        value: &v34->m_Storage,
        interpSetting: SEGMENT_INTERPOLATE,
        curveType: 0);
    }
    else
    {
      v33 = CDmeBookmarkSet::GetBookmarks(this: pTransform);
      CDmeTypedLog<Vector>::SetKey(
        this: (CDmeTypedLog<Vector> *)v22,
        time: 0,
        value: &v33->m_Storage,
        interpSetting: SEGMENT_INTERPOLATE,
        curveType: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00540900
// Name: void LoadPresetGroups(class CDmeAnimationSet __near *,char const __near *,class CDmrElementArray<class CDmePresetGroupInfo> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadPresetGroups(
        CDmeAnimationSet *pAnimationSet,
        const char *pModelName,
        CDmrElementArray<CDmePresetGroupInfo> *presetGroupInfos)
{
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // eax
  CDmePresetGroupInfo *PresetGroupInfo; // eax
  CDmePresetGroupInfo *v5; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  int v8; // esi
  char filenameBase[260]; // [esp+Ch] [ebp-104h] BYREF
  int nPresetGroups; // [esp+120h] [ebp+10h]

  CDmePresetGroupInfo::FilenameBaseForModelName(pModelName, pFileNameBase: filenameBase, nFileNameBaseLen: 260);
  if ( presetGroupInfos->m_pAttribute != nullptr )
  {
    PresetGroupInfo = CDmePresetGroupInfo::FindOrCreatePresetGroupInfo(pFilenameBase: filenameBase, presetGroupInfos);
    v5 = PresetGroupInfo;
    if ( PresetGroupInfo != nullptr )
    {
      v6 = 0;
      nPresetGroups = PresetGroupInfo->m_presetGroups.m_Storage.m_Size;
      if ( nPresetGroups > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_presetGroups.m_Storage.m_Memory.m_pMemory[v6]);
          v8 = (int)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmePresetGroup::m_classType) )
            CDmeAnimationSet::AddPresetGroup(this: pAnimationSet, pPresetGroup: v8);
          ++v6;
        }
        while ( v6 < nPresetGroups );
      }
    }
  }
  else
  {
    PresetGroups = CDmeAnimationSet::GetPresetGroups(this: pAnimationSet);
    CDmePresetGroupInfo::LoadPresetGroups(pFilenameBase: filenameBase, presetGroups: PresetGroups);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005409C0
// Name: class CDmeChannel __near * MoveOrCreateChannel(class CDmeFilmClip __near *,class CDmeChannelsClip __near *,class CDmElement __near *,class CDmAttribute __near *,class CDmAttribute __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl MoveOrCreateChannel(
        CDmeFilmClip *pFilmClip,
        CDmeChannelsClip *pDstChannelsClip,
        CDmElement *pControl,
        CDmAttribute *pInputAttr,
        int pOutputAttr,
        const char *pChannelName)
{
  CDmAttribute *v6; // edi
  CUtlSymbolLarge::<unnamed_type_u> v7; // eax
  const char *m_Id; // ecx
  CDmeChannel *ChannelTargetingElement; // eax
  CDmeChannel *v10; // esi
  int v11; // eax
  CDmeTrack *ParentTrack; // ebx
  CDmeTrackGroup *ParentTrackGroup; // eax
  CDmeTrackGroup *v14; // edi
  CDmeFilmClip *ParentClip; // eax
  CDmeChannelsClip *v16; // ebx
  DmElementHandle_t v17; // eax
  CDmElement *v18; // eax
  CDmElement *v19; // esi
  CDmeTypedLog<Quaternion> *Log; // eax
  DmElementHandle_t value; // [esp+Ch] [ebp-8h] BYREF
  CDmeChannelsClip *pSrcChannelsClip; // [esp+10h] [ebp-4h] BYREF

  v6 = (CDmAttribute *)pOutputAttr;
  v7.m_Id = *(int *)(pOutputAttr + 20);
  pSrcChannelsClip = nullptr;
  m_Id = &pParentName;
  if ( v7.m_Id != -1 )
    m_Id = (const char *)v7.m_Id;
  ChannelTargetingElement = FindChannelTargetingElement(
                              pClip: pFilmClip,
                              pElement: *(CDmElement **)(pOutputAttr + 8),
                              pAttributeName: m_Id,
                              ppChannelsClip: &pSrcChannelsClip,
                              ppTrack: nullptr,
                              ppTrackGroup: nullptr);
  v10 = ChannelTargetingElement;
  if ( ChannelTargetingElement != nullptr )
  {
    value = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&ChannelTargetingElement->CDmElement);
    v11 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
            this: &pSrcChannelsClip->m_Channels,
            &value);
    if ( v11 != -1 )
    {
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
        this: &pSrcChannelsClip->m_Channels,
        elem: v11);
      if ( pSrcChannelsClip->m_Channels.m_Storage.m_Size == 0 )
      {
        ParentTrack = GetParentTrack(pClip: &pSrcChannelsClip->CDmeClip);
        if ( ParentTrack != nullptr )
        {
          CDmeTrack::RemoveClip(this: ParentTrack, clip: &pSrcChannelsClip->CDmeClip);
          if ( CDmeTrack::GetClipCount(this: (CDmeTransform *)ParentTrack) == nullptr )
          {
            ParentTrackGroup = GetParentTrackGroup(pTrack: ParentTrack);
            v14 = ParentTrackGroup;
            if ( ParentTrackGroup != nullptr )
            {
              CDmeTrackGroup::RemoveTrack(this: ParentTrackGroup, pTrack: ParentTrack);
              if ( v14->m_Tracks.m_Storage.m_Size == 0 )
              {
                ParentClip = GetParentClip(pTrackGroup: v14);
                if ( ParentClip != nullptr )
                  CDmeClip::RemoveTrackGroup(this: ParentClip, pTrackGroup: v14);
              }
            }
            v6 = (CDmAttribute *)pOutputAttr;
          }
        }
      }
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pOutputAttr, a3: pChannelName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: v10->m_Name.m_pAttribute,
      value: (const CUtlSymbolLarge *)&pOutputAttr);
    v16 = pDstChannelsClip;
  }
  else
  {
    v16 = pDstChannelsClip;
    v17 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
            a3: pChannelName,
            a4: pDstChannelsClip->m_fileId,
            a5: nullptr);
    v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: v17);
    v19 = v18;
    if ( v18 != nullptr && v18->IsA(this: v18, a2: CDmeChannel::m_classType) )
      v10 = (CDmeChannel *)((char *)&v19[-1] + 64);
    else
      v10 = nullptr;
  }
  if ( v10 != nullptr )
    pOutputAttr = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v10->CDmElement);
  else
    pOutputAttr = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &v16->m_Channels,
    src: (DmElementHandle_t *)&pOutputAttr);
  CDmeChannel::SetInput(this: v10, pAttribute: pInputAttr, index: 0);
  CDmeChannel::SetOutput(this: v10, pAttribute: v6, index: 0);
  Log = (CDmeTypedLog<Quaternion> *)CDmeChannel::GetLog(this: v10);
  if ( Log == nullptr )
    Log = CDmeChannel::CreateLog(this: v10, type: (DmAttributeType_t)(v6->m_nFlags & 0x1F));
  if ( pSrcChannelsClip != nullptr )
    RetimeLogData(pSrcChannelsClip, pDstChannelsClip: v16, pLog: Log);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00540B90
// Name: void AddFloatControlToAnimationSet(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeChannelsClip __near *,class CDmeControlGroup __near *,class CDmAttribute __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddFloatControlToAnimationSet(
        CDmeFilmClip *pFilmClip,
        CDmeAnimationSet *pAnimSet,
        CDmeChannelsClip *pDstChannelsClip,
        CUtlSymbolLarge::<unnamed_type_u> pControlGroup,
        int pSrcAttr,
        float flMin,
        float flMax,
        float flDefault)
{
  CDmeControlGroup *m_Id; // esi
  CDmAttribute *v9; // edi
  const char *v10; // eax
  CDmElement *v11; // eax
  const char *m_pAsString; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v17; // eax
  CDmeChannel *Channel; // ebx
  CDmAttribute *v19; // eax
  CDmaVar<float> *v20; // eax
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  CDmeExpressionOperator *v24; // esi
  CDmElement *v25; // edi
  CDmAttribute *v26; // eax
  CDmAttribute *v27; // eax
  CDmAttribute *v28; // eax
  CDmAttribute *v29; // eax
  const char *v30; // ebx
  CDmAttribute *v31; // eax
  CDmAttribute *v32; // eax
  char channame[256]; // [esp+1Ch] [ebp-20Ch] BYREF
  char exprname[256]; // [esp+11Ch] [ebp-10Ch] BYREF
  CDmElement *pTarget; // [esp+21Ch] [ebp-Ch]
  CDmElement *pControl; // [esp+220h] [ebp-8h]
  float flValue; // [esp+224h] [ebp-4h] BYREF

  m_Id = (CDmeControlGroup *)pControlGroup.m_Id;
  v9 = (CDmAttribute *)pSrcAttr;
  if ( pControlGroup.m_Id != 0 )
  {
    v10 = *(const char **)(pSrcAttr + 20);
    if ( v10 == (const char *)-1 )
      v10 = &pParentName;
    v11 = CDmeAnimationSet::FindOrAddControl(
            this: pAnimSet,
            pControlName: v10,
            transformControl: false,
            bMustBeNew: false);
    CDmeControlGroup::AddControl(this: m_Id, pControl: v11, pInsertBeforeControl: nullptr);
  }
  if ( (v9->m_nFlags & 0x1F) == 3 )
  {
    m_pAsString = v9->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
    {
      v13 = &pParentName;
      pControlGroup.m_Id = (int)&pParentName;
    }
    else
    {
      pControlGroup.m_Id = (int)v9->m_Name.u;
      v13 = m_pAsString;
    }
    v14 = CDmeAnimationSet::FindOrAddControl(
            this: pAnimSet,
            pControlName: v13,
            transformControl: false,
            bMustBeNew: false);
    v15 = v14;
    pControl = v14;
    if ( v14 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v14, pAttributeName: "value");
      v17 = Attribute != nullptr
          ? ((Attribute->m_nFlags & 0x1F) != 3
           ? nullptr
           : Attribute)
          : CDmElement::CreateAttribute(this: v15, pAttributeName: "value", type: AT_FLOAT);
      if ( v17 != nullptr )
      {
        pTarget = v9->m_pOwner;
        Channel = MoveOrCreateChannel(
                    pFilmClip,
                    pDstChannelsClip,
                    pControl: v15,
                    pInputAttr: v17,
                    pOutputAttr: (int)v9,
                    pChannelName: v13);
        CDmeChannel::SetMode(this: Channel, mode: CM_PLAY);
        if ( Channel != nullptr )
          pSrcAttr = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&Channel->CDmElement);
        else
          pSrcAttr = -1;
        v19 = CDmElement::FindAttribute(this: v15, pAttributeName: "channel");
        if ( v19 != nullptr
          || (v19 = CDmElement::CreateAttribute(this: v15, pAttributeName: "channel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
        {
          CDmAttribute::SetValue<enum DmElementHandle_t>(this: v19, value: (DmElementHandle_t *)&pSrcAttr);
        }
        v20 = CDmAttribute::GetValue<float>(this: v9);
        v21 = flMin;
        flValue = v20->m_Storage;
        if ( flMin > flValue )
        {
          v21 = flValue;
          flMin = flValue;
        }
        v22 = flMax;
        if ( flValue > flMax )
        {
          v22 = flValue;
          flMax = flValue;
        }
        if ( v21 != 0.0 || v22 != 1.0 )
        {
          v23 = v22 - v21;
          flValue = (float)(flValue - v21) / v23;
          flDefault = (float)(flDefault - v21) / v23;
          V_snprintf(pDest: exprname, maxLen: 256, pFormat: "%s_rescale", pControlGroup.m_pAsString);
          v24 = CreateElement<CDmeExpressionOperator>(
                  pObjectName: exprname,
                  fileid: pAnimSet->m_fileId,
                  pObjectID: nullptr);
          CDmeAnimationSet::AddOperator(this: pAnimSet, pOperator: (int)v24);
          v25 = &v24->CDmElement;
          g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pSrcAttr, a3: "lerp(value, lo, hi)");
          v26 = CDmElement::FindAttribute(this: &v24->CDmElement, pAttributeName: "expr");
          if ( v26 != nullptr
            || (v26 = CDmElement::CreateAttribute(this: &v24->CDmElement, pAttributeName: "expr", type: AT_STRING)) != nullptr )
          {
            CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: (const CUtlSymbolLarge *)&pSrcAttr);
          }
          pSrcAttr = 0;
          v27 = CDmElement::FindAttribute(this: &v24->CDmElement, pAttributeName: "value");
          if ( v27 != nullptr
            || (v27 = CDmElement::CreateAttribute(this: &v24->CDmElement, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v27, value: (const float *)&pSrcAttr);
          }
          v28 = CDmElement::FindAttribute(this: &v24->CDmElement, pAttributeName: "lo");
          if ( v28 != nullptr
            || (v28 = CDmElement::CreateAttribute(this: &v24->CDmElement, pAttributeName: "lo", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v28, value: &flMin);
          }
          v29 = CDmElement::FindAttribute(this: &v24->CDmElement, pAttributeName: "hi");
          if ( v29 != nullptr
            || (v29 = CDmElement::CreateAttribute(this: &v24->CDmElement, pAttributeName: "hi", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v29, value: &flMax);
          }
          CDmeChannel::SetOutput(
            this: Channel,
            pElement: v24 != nullptr ? (unsigned int)v25 : 0,
            pAttribute: "value",
            index: 0);
          RemapFloatLogValues(
            pChannel: *(float *)&Channel,
            flBias: COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(1.0 / (float)(flMax - flMin)) * flMin) ^ _mask__NegFloat_),
            flScale: 1.0 / (float)(flMax - flMin));
          v30 = (const char *)pControlGroup.m_Id;
          V_snprintf(pDest: channame, maxLen: 256, pFormat: "scaled_%s_channel", pControlGroup.m_pAsString);
          CDmeChannelsClip::CreatePassThruConnection(
            this: pDstChannelsClip,
            passThruName: (int)channame,
            pFrom: v24 != nullptr ? v25 : nullptr,
            pFromAttribute: "result",
            pTo: pTarget,
            pToAttribute: v30,
            index: 0);
          v15 = pControl;
        }
        v31 = CDmElement::FindAttribute(this: v15, pAttributeName: "value");
        if ( v31 != nullptr
          || (v31 = CDmElement::CreateAttribute(this: v15, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v31, value: &flValue);
        }
        if ( flDefault >= 0.0 )
        {
          if ( flDefault <= 1.0 )
            pControlGroup.m_Id = (int)LODWORD(flDefault);
          else
            pControlGroup.m_Id = 1065353216;
        }
        else
        {
          pControlGroup.m_Id = 0;
        }
        v32 = CDmElement::FindAttribute(this: v15, pAttributeName: "defaultValue");
        if ( v32 != nullptr
          || (v32 = CDmElement::CreateAttribute(this: v15, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v32, value: (const float *)&pControlGroup.m_Id);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00540F60
// Name: void AddTransformControlsToAnimationSet(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeChannelsClip __near *,class CDmeControlGroup __near *,class CDmeTransform __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddTransformControlsToAnimationSet(
        CDmeFilmClip *pFilmClip,
        CDmeAnimationSet *pAnimSet,
        CDmeChannelsClip *pDstChannelsClip,
        CDmeControlGroup *pControlGroup,
        CDmeTransform *pTransform,
        const char *pControlName)
{
  CDmElement *v6; // eax
  CDmeTransformControl *v7; // ebx
  int i; // edi
  CDmeChannel *Channel; // esi
  CDmeLog *v10; // eax
  CDmeTypedLog<Vector> *v11; // esi
  CDmaVar<Vector> *Bookmarks; // eax
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v14; // esi
  CDmaVar<Quaternion> *Orientation; // eax
  CDmaVar<Vector> *v16; // eax
  CDmaVar<Quaternion> *v17; // eax
  char channelName[256]; // [esp+Ch] [ebp-110h] BYREF
  CDmAttribute *pOutputAttr[2]; // [esp+10Ch] [ebp-10h]
  CDmAttribute *pInputAttr[2]; // [esp+114h] [ebp-8h]

  v6 = CDmeAnimationSet::FindOrAddControl(this: pAnimSet, pControlName, transformControl: true, bMustBeNew: false);
  v7 = (CDmeTransformControl *)v6;
  if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeTransformControl::m_classType) )
  {
    pInputAttr[0] = CDmeTransformControl::GetPositionAttr(this: v7);
    pInputAttr[1] = CDmeTransformControl::GetOrientationAttr(this: v7);
    pOutputAttr[0] = CDmeTrack::GetClipCount(this: pTransform);
    pOutputAttr[1] = CDmeGlobalFlexControllerOperator::GetGlobalIndex(this: pTransform);
    for ( i = 0; i < 2; ++i )
    {
      V_snprintf(pDest: channelName, maxLen: 256, pFormat: "%s_%s", pControlName, g_pSuffix[i]);
      Channel = MoveOrCreateChannel(
                  pFilmClip,
                  pDstChannelsClip,
                  pControl: v7,
                  pInputAttr: pInputAttr[i],
                  pOutputAttr: (int)pOutputAttr[i],
                  pChannelName: channelName);
      CDmeChannel::SetMode(this: Channel, mode: CM_PLAY);
      if ( i != 0 )
      {
        CDmeTransformControl::SetOrientationChannel(this: v7, pChannel: (int)Channel);
        Log = CDmeChannel::GetLog(this: Channel);
        v14 = (CDmeTypedLog<Quaternion> *)Log;
        if ( Log != nullptr
          && Log->IsA(this: Log, a2: CDmeTypedLog<Quaternion>::m_classType)
          && CDmeLog::GetKeyCount(this: v14) == nullptr )
        {
          Orientation = CDmeTransform::GetOrientation(this: pTransform);
          CDmeTypedLog<Quaternion>::SetDefaultValue(this: v14, value: &Orientation->m_Storage);
        }
      }
      else
      {
        CDmeTransformControl::SetPositionChannel(this: v7, pChannel: (int)Channel);
        v10 = CDmeChannel::GetLog(this: Channel);
        v11 = (CDmeTypedLog<Vector> *)v10;
        if ( v10 != nullptr
          && v10->IsA(this: v10, a2: CDmeTypedLog<Vector>::m_classType)
          && CDmeLog::GetKeyCount(this: v11) == nullptr )
        {
          Bookmarks = CDmeBookmarkSet::GetBookmarks(this: pTransform);
          CDmeTypedLog<Vector>::SetDefaultValue(this: v11, value: &Bookmarks->m_Storage);
        }
      }
    }
    v16 = CDmeBookmarkSet::GetBookmarks(this: pTransform);
    CDmeTransformControl::SetPosition(this: v7, position: &v16->m_Storage);
    v17 = CDmeTransform::GetOrientation(this: pTransform);
    CDmeTransformControl::SetOrientation(this: v7, orientation: &v17->m_Storage);
    if ( pControlGroup != nullptr )
      CDmeControlGroup::AddControl(this: pControlGroup, pControl: v7, pInsertBeforeControl: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00541100
// Name: void AddLocalViewTargetControl(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddLocalViewTargetControl(
        CDmeFilmClip *pFilmClip,
        CDmeAnimationSet *pAnimSet,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip)
{
  CDmeControlGroup *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax

  v4 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimSet, pParentGroup: nullptr, pControlGroupName: "Eyes");
  Attribute = CDmElement::FindAttribute(this: pGameModel, pAttributeName: "localViewTargetFactor");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 3 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: pGameModel, pAttributeName: "localViewTargetFactor", type: AT_FLOAT);
  AddFloatControlToAnimationSet(
    pFilmClip,
    pAnimSet,
    pDstChannelsClip: pChannelsClip,
    pControlGroup: (CUtlSymbolLarge::<unnamed_type_u>)v4,
    pSrcAttr: (int)v6,
    flMin: 0.0,
    flMax: 1.0,
    flDefault: -3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x00541190
// Name: void AddEyeConvergenceControl(class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddEyeConvergenceControl(
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip)
{
  CDmeControlGroup *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // eax
  CDmeExpressionOperator *v9; // edi
  CDmElement *v10; // ebx
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmeChannel *v15; // esi
  CDmElement *v16; // esi
  CDmAttribute *v17; // eax
  float flMaxValue; // [esp+4h] [ebp-14h] BYREF
  float flMinValue; // [esp+8h] [ebp-10h] BYREF
  CDmElement *pControl; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+10h] [ebp-8h] BYREF
  float flDefaultValue; // [esp+14h] [ebp-4h] BYREF

  if ( CDmeAnimationSet::FindControl(this: pAnimationSet, pControlName: "eyes_updown") != nullptr
    || CDmeAnimationSet::FindControl(this: pAnimationSet, pControlName: "eyes_rightleft") != nullptr )
  {
    if ( CDmElement::FindAttribute(this: pGameModel, pAttributeName: "eyes_convergence") == nullptr )
      CDmElement::CreateAttribute(this: pGameModel, pAttributeName: "eyes_convergence", type: AT_FLOAT);
    v3 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimationSet, pParentGroup: nullptr, pControlGroupName: "Eyes");
    if ( v3 != nullptr )
    {
      v4 = CDmeAnimationSet::FindOrAddControl(
             this: pAnimationSet,
             pControlName: "eyes_convergence",
             transformControl: false,
             bMustBeNew: false);
      CDmeControlGroup::AddControl(this: v3, pControl: v4, pInsertBeforeControl: nullptr);
    }
    flMinValue = -45.0;
    flMaxValue = 45.0;
    flDefaultValue = 0.5;
    v5 = CDmeAnimationSet::FindOrAddControl(
           this: pAnimationSet,
           pControlName: "eyes_convergence",
           transformControl: false,
           bMustBeNew: false);
    v6 = v5;
    pControl = v5;
    if ( v5 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "value");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: Attribute, value: &flDefaultValue);
      }
      v8 = CDmElement::FindAttribute(this: v6, pAttributeName: "defaultValue");
      if ( v8 != nullptr
        || (v8 = CDmElement::CreateAttribute(this: v6, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v8, value: &flDefaultValue);
      }
      v9 = CreateElement<CDmeExpressionOperator>(
             pObjectName: "eye_convergence_rescale",
             fileid: pAnimationSet->m_fileId,
             pObjectID: nullptr);
      v10 = &v9->CDmElement;
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "lerp(value, lo, hi)");
      v11 = CDmElement::FindAttribute(this: &v9->CDmElement, pAttributeName: "expr");
      if ( v11 != nullptr
        || (v11 = CDmElement::CreateAttribute(this: &v9->CDmElement, pAttributeName: "expr", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
      }
      value.u.m_Id = 0;
      v12 = CDmElement::FindAttribute(this: &v9->CDmElement, pAttributeName: "value");
      if ( v12 != nullptr
        || (v12 = CDmElement::CreateAttribute(this: &v9->CDmElement, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v12, value: (const float *)&value.u.m_Id);
      }
      v13 = CDmElement::FindAttribute(this: &v9->CDmElement, pAttributeName: "lo");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: &v9->CDmElement, pAttributeName: "lo", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v13, value: &flMinValue);
      }
      v14 = CDmElement::FindAttribute(this: &v9->CDmElement, pAttributeName: "hi");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: &v9->CDmElement, pAttributeName: "hi", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v14, value: &flMaxValue);
      }
      CDmeAnimationSet::AddOperator(this: pAnimationSet, pOperator: (int)v9);
      v15 = CreateElement<CDmeChannel>(
              pObjectName: "eye_convergence_channel",
              fileid: pChannelsClip->m_fileId,
              pObjectID: nullptr);
      CDmeChannel::SetInput(this: v15, pElement: (int)pControl, pAttribute: "value", index: 0);
      CDmeChannel::SetOutput(this: v15, pElement: v9 != nullptr ? (unsigned int)v10 : 0, pAttribute: "value", index: 0);
      CDmeChannel::SetMode(this: v15, mode: CM_PLAY);
      if ( v15 != nullptr )
        value.u.m_Id = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v15->CDmElement);
      else
        value.u.m_Id = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &pChannelsClip->m_Channels,
        src: (DmElementHandle_t *)&value);
      if ( v15 != nullptr )
        value.u.m_Id = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v15->CDmElement);
      else
        value.u.m_Id = -1;
      v16 = pControl;
      v17 = CDmElement::FindAttribute(this: pControl, pAttributeName: "channel");
      if ( v17 != nullptr
        || (v17 = CDmElement::CreateAttribute(this: v16, pAttributeName: "channel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v17, (DmElementHandle_t *)&value);
      }
      CDmeChannelsClip::CreatePassThruConnection(
        this: pChannelsClip,
        passThruName: (int)"scaled_eye_convergence_channel",
        pFrom: v9 != nullptr ? v10 : nullptr,
        pFromAttribute: "result",
        pTo: pGameModel,
        pToAttribute: "eyes_convergence",
        index: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00541490
// Name: void AddViewTargetControl(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddViewTargetControl(
        CDmeFilmClip *pFilmClip,
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmeDag *v8; // edi
  CExpressionCalculator *v9; // eax
  CDmeTransform *Transform; // esi
  CExpressionCalculator *v11; // eax
  CDmAttribute *v12; // eax
  Vector vecPosition; // [esp+Ch] [ebp-18h] BYREF
  CDmeControlGroup *pGroup; // [esp+18h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+1Ch] [ebp-8h] BYREF
  bool bViewTargetInvalid; // [esp+23h] [ebp-1h]

  if ( CDmeAnimationSet::FindControl(this: pAnimationSet, pControlName: "eyes_updown") != nullptr
    || CDmeAnimationSet::FindControl(this: pAnimationSet, pControlName: "eyes_rightleft") != nullptr )
  {
    pGroup = CDmeAnimationSet::FindOrAddControlGroup(
               this: pAnimationSet,
               pParentGroup: nullptr,
               pControlGroupName: "Eyes");
    bViewTargetInvalid = false;
    Attribute = CDmElement::FindAttribute(this: pGameModel, pAttributeName: "viewTargetDag");
    if ( Attribute != nullptr )
      v5 = (unsigned __int8)((Attribute->m_nFlags & 0x1F) - 1) == 0 ? Attribute : nullptr;
    else
      v5 = CDmElement::CreateAttribute(this: pGameModel, pAttributeName: "viewTargetDag", type: AT_FIRST_VALUE_TYPE);
    if ( v5 != nullptr )
      CDmAttribute::SetElementTypeSymbol(this: v5, typeSymbol: CDmeDag::m_classType);
    if ( (v5->m_nFlags & 0x1F) != 1 )
      goto LABEL_13;
    v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v5);
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
    v8 = (CDmeDag *)v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeDag::m_classType) )
      v8 = nullptr;
    if ( v8 == nullptr )
    {
LABEL_13:
      v9 = (CExpressionCalculator *)CreateElement<CDmeDag>(
                                      pObjectName: "viewTarget",
                                      fileid: pGameModel->m_fileId,
                                      pObjectID: nullptr);
      v8 = (CDmeDag *)v9;
      if ( (v5->m_nFlags & 0x1F) == 1 )
      {
        if ( v9 != nullptr )
          value.u.m_Id = CExpressionCalculator::VariableCount(this: v9);
        else
          value.u.m_Id = -1;
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, (DmElementHandle_t *)&value);
      }
      bViewTargetInvalid = true;
    }
    if ( CDmeDag::FindChild(this: pGameModel, pChild: (CExpressionCalculator *)v8) < 0 )
      CDmeDag::AddChild(this: pGameModel, pDag: v8);
    Transform = CDmeDag::GetTransform(this: v8);
    if ( Transform != nullptr )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "viewTarget");
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Transform->m_Name.m_pAttribute, &value);
      if ( !bViewTargetInvalid )
      {
LABEL_30:
        AddTransformControlsToAnimationSet(
          pFilmClip,
          pAnimSet: pAnimationSet,
          pDstChannelsClip: pChannelsClip,
          pControlGroup: pGroup,
          pTransform: Transform,
          pControlName: "viewTarget");
        return;
      }
    }
    else
    {
      v11 = (CExpressionCalculator *)CreateElement<CDmeTransform>(
                                       pObjectName: "viewTarget",
                                       fileid: pGameModel->m_fileId,
                                       pObjectID: nullptr);
      Transform = (CDmeTransform *)v11;
      if ( v11 != nullptr )
        value.u.m_Id = CExpressionCalculator::VariableCount(this: v11);
      else
        value.u.m_Id = -1;
      v12 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
      if ( v12 != nullptr
        || (v12 = CDmElement::CreateAttribute(this: v8, pAttributeName: "transform", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v12, (DmElementHandle_t *)&value);
      }
    }
    vecPosition.x = 32.0;
    vecPosition.y = 0.0;
    vecPosition.z = 64.0;
    CDmeTransform::SetPosition(this: Transform, &vecPosition);
    goto LABEL_30;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00542060
// Name: class CDmeControlGroup __near * FindOrAddGroupForTransformControl(class CDmElement __near *,class CDmeAnimationSet __near *,class Color const __near &,class CUtlDict<class CUtlString,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl FindOrAddGroupForTransformControl(
        CDmElement *pControl,
        CDmeAnimationSet *pAnimationSet,
        const Color *groupColor,
        const CUtlDict<CUtlString,int> *defaultGroupMapping)
{
  const char *m_pAsString; // esi
  const char *v5; // edi
  int v6; // esi
  CDmeControlGroup *result; // eax
  CDmeControlGroup *v8; // esi
  CUtlMap<char const *,CUtlString,int>::Node_t search; // [esp+8h] [ebp-14h] BYREF

  m_pAsString = pControl->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pParentName;
  v5 = "Root";
  if ( m_pAsString != nullptr )
  {
    CUtlString::CUtlString(this: &search.elem);
    search.key = m_pAsString;
    v6 = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::Find(
           this: &defaultGroupMapping->m_Elements.m_Tree,
           &search);
    search.elem.m_Storage.m_nActualLength = 0;
    if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
        search.elem.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      search.elem.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    if ( v6 != -1 )
      v5 = CUtlString::operator char const *(this: &defaultGroupMapping->m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem);
  }
  result = (CDmeControlGroup *)_V_stricmp(s1: v5, s2: "IGNORE");
  if ( result != nullptr )
  {
    v8 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimationSet, pParentGroup: nullptr, pControlGroupName: v5);
    if ( v8 != nullptr )
      CDmeControlGroup::SetGroupColor(this: v8, groupColor, bRecursive: false);
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00542130
// Name: bool AddConstraintControlToGroup(class CDmElement __near *,class CDmeAnimationSet __near *,class Color const __near &,class CUtlDict<class CUtlString,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddConstraintControlToGroup(
        CDmElement *pControl,
        CDmeAnimationSet *pAnimationSet,
        const Color *groupColor,
        const CUtlDict<CUtlString,int> *defaultGroupMapping)
{
  CDmeChannel *Value; // eax
  CDmElement *v5; // eax
  CExpressionCalculator *v6; // esi
  CDmeRigBaseConstraintOperator *Referring; // eax
  CDmeDag *v8; // eax
  CDmeTransformControl *TransformControl; // eax
  CDmeControlGroup *v10; // eax

  if ( !CDmElement::HasAttribute(this: pControl, pAttributeName: "channel", type: AT_UNKNOWN) )
    return 0;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: "channel");
  if ( Value == nullptr )
    return 0;
  v5 = CDmeChannel::GetToElement(this: Value);
  v6 = (CExpressionCalculator *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeConstraintTarget::m_classType) )
    v6 = nullptr;
  Referring = FindReferringElement<CDmeRigBaseConstraintOperator>(
                pElement: v6,
                symAttrName: (CUtlSymbolLarge)-1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  v8 = (CDmeDag *)Referring->GetSlave(this: Referring);
  if ( v8 == nullptr )
    return 0;
  TransformControl = CDmeDag::FindTransformControl(this: v8);
  if ( TransformControl == nullptr )
    return 0;
  v10 = FindOrAddGroupForTransformControl(pControl: TransformControl, pAnimationSet, groupColor, defaultGroupMapping);
  if ( v10 == nullptr )
    return 0;
  CDmeControlGroup::AddControl(this: v10, pControl, pInsertBeforeControl: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00542260
// Name: class CDmeChannel __near * FindChannelTargetingTransform(class CDmeChannelsClip __near *,class CDmeTransform __near *,enum ControlType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl FindChannelTargetingTransform(
        CDmeChannelsClip *pChannelsClip,
        CDmeTransform *pTransform,
        ControlType_t controlType)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int m_Size; // edi
  int v5; // esi
  CDmeChannel *v6; // edi
  int v7; // eax
  CDmeDag *v8; // esi
  CDmElement *v9; // eax
  CDmeTransform *v10; // esi
  CDmeTransform *v11; // ebx
  CDmAttribute *v12; // esi
  CDmeChannel **v13; // eax
  CDmAttribute *v15; // esi
  CDmeDag *v16; // eax
  CDmeTransform *Transform; // eax
  CDmAttribute *v18; // eax
  bool v19; // zf
  CDmAttribute *v20; // eax
  CDmeChannel **m_pMemory; // eax
  CDmeChannel **v22; // eax
  CUtlVector<CDmeDag *,CUtlMemory<CDmeDag *,int> > dagList; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<CDmeChannelsClip *,CUtlMemory<CDmeChannelsClip *,int> > channelClips; // [esp+20h] [ebp-30h] BYREF
  CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > channelsList; // [esp+34h] [ebp-1Ch] BYREF
  int nNumChannels; // [esp+48h] [ebp-8h]
  int iChannel; // [esp+4Ch] [ebp-4h]

  channelsList.m_Memory.m_pMemory = nullptr;
  channelsList.m_Memory.m_nAllocationCount = 8;
  channelsList.m_Memory.m_nGrowSize = 0;
  channelsList.m_Memory.m_pMemory = (CDmeChannel **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  channelsList.m_pElements = channelsList.m_Memory.m_pMemory;
  channelsList.m_Size = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  dagList.m_Memory.m_nAllocationCount = 8;
  dagList.m_Memory.m_nGrowSize = 0;
  dagList.m_Memory.m_pMemory = (CDmeDag **)Alloc_2(this: _g_pMemAlloc, a2: 32u);
  dagList.m_pElements = dagList.m_Memory.m_pMemory;
  dagList.m_Size = 0;
  FindReferringElements<CDmeDag>(
    list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&dagList,
    pElement: (CExpressionCalculator *)pTransform,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  m_Size = dagList.m_Size;
  v5 = 0;
  if ( dagList.m_Size <= 0 )
    goto LABEL_4;
  while ( CDmeDag::GetTransform(this: dagList.m_Memory.m_pMemory[v5]) != pTransform )
  {
    if ( ++v5 >= m_Size )
      goto LABEL_4;
  }
  v8 = dagList.m_Memory.m_pMemory[v5];
  if ( v8 != nullptr )
    CDmeDag::FindTransformChannels(
      this: v8,
      channelList: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelsList);
  else
LABEL_4:
    FindReferringElements<CDmeChannel>(
      list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelsList,
      pElement: (CExpressionCalculator *)pTransform,
      symAttrName: (CUtlSymbolLarge)-1,
      bMustBeInSameFile: false,
      depth: TD_ALL);
  nNumChannels = channelsList.m_Size;
  iChannel = 0;
  if ( channelsList.m_Size <= 0 )
  {
LABEL_61:
    if ( dagList.m_Memory.m_nGrowSize >= 0 && dagList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dagList.m_Memory.m_pMemory);
    m_pMemory = channelsList.m_Memory.m_pMemory;
    channelsList.m_Size = 0;
    if ( channelsList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( channelsList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelsList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        channelsList.m_Memory.m_pMemory = nullptr;
      }
      channelsList.m_Memory.m_nAllocationCount = 0;
    }
    channelsList.m_pElements = m_pMemory;
    if ( channelsList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return nullptr;
  }
  while ( 1 )
  {
    v6 = channelsList.m_Memory.m_pMemory[iChannel];
    if ( v6 != nullptr )
      break;
LABEL_60:
    if ( ++iChannel >= nNumChannels )
      goto LABEL_61;
  }
  memset(&channelClips, 0, sizeof(channelClips));
  FindReferringElements<CDmeChannelsClip>(
    list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelClips,
    pElement: (CExpressionCalculator *)&v6->CDmElement,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  v7 = 0;
  if ( channelClips.m_Size <= 0 )
  {
LABEL_10:
    if ( channelClips.m_Memory.m_nGrowSize < 0 || channelClips.m_Memory.m_pMemory == nullptr )
      goto LABEL_60;
    goto LABEL_59;
  }
  while ( channelClips.m_Memory.m_pMemory[v7] != pChannelsClip )
  {
    if ( ++v7 >= channelClips.m_Size )
      goto LABEL_10;
  }
  v9 = CDmeChannel::GetToElement(this: v6);
  v10 = (CDmeTransform *)v9;
  if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeConstraintSlave::m_classType) )
    v11 = v10;
  else
    v11 = nullptr;
  if ( v10 == pTransform )
  {
    if ( controlType != CONTROL_TYPE_POSITION )
    {
      if ( controlType == CONTROL_TYPE_ORIENTATION )
      {
        v15 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
        if ( v15 == nullptr )
          v15 = CDmeChannel::SetupToAttribute(this: v6);
        if ( v15 == CDmeGlobalFlexControllerOperator::GetGlobalIndex(this: pTransform) )
        {
LABEL_24:
          if ( channelClips.m_Memory.m_nGrowSize >= 0 && channelClips.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelClips.m_Memory.m_pMemory);
          if ( dagList.m_Memory.m_nGrowSize >= 0 && dagList.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dagList.m_Memory.m_pMemory);
          v13 = channelsList.m_Memory.m_pMemory;
          channelsList.m_Size = 0;
          if ( channelsList.m_Memory.m_nGrowSize >= 0 )
          {
            if ( channelsList.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelsList.m_Memory.m_pMemory);
              v13 = nullptr;
              channelsList.m_Memory.m_pMemory = nullptr;
            }
            channelsList.m_Memory.m_nAllocationCount = 0;
          }
          channelsList.m_pElements = v13;
          if ( channelsList.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
          return v6;
        }
      }
    }
    else
    {
      v12 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v12 == nullptr )
        v12 = CDmeChannel::SetupToAttribute(this: v6);
      if ( v12 == CDmeTrack::GetClipCount(this: pTransform) )
        goto LABEL_24;
    }
LABEL_57:
    if ( channelClips.m_Memory.m_nGrowSize < 0 || channelClips.m_Memory.m_pMemory == nullptr )
      goto LABEL_60;
LABEL_59:
    ((void (__stdcall *)(CDmeChannelsClip **))_g_pMemAlloc->Free_2)(a1: channelClips.m_Memory.m_pMemory);
    goto LABEL_60;
  }
  if ( v11 == nullptr )
    goto LABEL_57;
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: LODWORD(v11->m_Position.m_Storage.x)) != nullptr )
  {
    v16 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: LODWORD(v11->m_Position.m_Storage.x));
    Transform = CDmeDag::GetTransform(this: v16);
  }
  else
  {
    Transform = nullptr;
  }
  if ( Transform != pTransform )
    goto LABEL_57;
  if ( controlType != CONTROL_TYPE_POSITION )
  {
    if ( controlType != CONTROL_TYPE_ORIENTATION )
      goto LABEL_57;
    v20 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
    if ( v20 == nullptr )
      v20 = CDmeChannel::SetupToAttribute(this: v6);
    v19 = v20 == *(CDmAttribute **)&v11[1].m_Id.m_Value[4];
  }
  else
  {
    v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
    if ( v18 == nullptr )
      v18 = CDmeChannel::SetupToAttribute(this: v6);
    v19 = v18 == (CDmAttribute *)LODWORD(v11->m_Orientation.m_Storage.z);
  }
  if ( !v19 )
    goto LABEL_57;
  if ( channelClips.m_Memory.m_nGrowSize >= 0 && channelClips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelClips.m_Memory.m_pMemory);
  if ( dagList.m_Memory.m_nGrowSize >= 0 && dagList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dagList.m_Memory.m_pMemory);
  v22 = channelsList.m_Memory.m_pMemory;
  channelsList.m_Size = 0;
  if ( channelsList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( channelsList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelsList.m_Memory.m_pMemory);
      v22 = nullptr;
      channelsList.m_Memory.m_pMemory = nullptr;
    }
    channelsList.m_Memory.m_nAllocationCount = 0;
  }
  channelsList.m_pElements = v22;
  if ( channelsList.m_Memory.m_nGrowSize < 0 || v22 == nullptr )
    return v6;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x005426D0
// Name: void CreateTransformChannels(class CDmeTransform __near *,char const __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateTransformChannels(CDmeTransform *pTransform, const char *pBaseName, CDmeChannelsClip *pChannelsClip)
{
  CDmeChannel *ChannelTargetingTransform; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  char *v7; // esi
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  char *v11; // esi
  char name[256]; // [esp+Ch] [ebp-108h] BYREF
  CDmeChannel *pOrientationChannel; // [esp+10Ch] [ebp-8h]
  DmElementHandle_t src; // [esp+110h] [ebp-4h] BYREF

  ChannelTargetingTransform = FindChannelTargetingTransform(
                                pChannelsClip,
                                pTransform,
                                controlType: CONTROL_TYPE_POSITION);
  pOrientationChannel = FindChannelTargetingTransform(pChannelsClip, pTransform, controlType: CONTROL_TYPE_ORIENTATION);
  if ( ChannelTargetingTransform == nullptr )
  {
    V_snprintf(pDest: name, maxLen: 256, pFormat: "%s_p", pBaseName);
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
           a3: name,
           a4: pChannelsClip->m_fileId,
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    v6 = v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeChannel::m_classType) )
      v7 = (char *)&v6[-1] + 64;
    else
      v7 = nullptr;
    CDmeChannel::SetMode(this: (CDmeChannel *)v7, mode: CM_PLAY);
    CDmeChannel::CreateLog(this: (CDmeChannel *)v7, type: AT_VECTOR3);
    CDmeChannel::SetOutput(this: (CDmeChannel *)v7, pElement: (int)pTransform, pAttribute: "position", index: 0);
    if ( v7 != nullptr )
      src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v7 + 4));
    else
      src = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &pChannelsClip->m_Channels,
      &src);
  }
  if ( pOrientationChannel == nullptr )
  {
    V_snprintf(pDest: name, maxLen: 256, pFormat: "%s_o", pBaseName);
    v8 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
           a3: name,
           a4: pChannelsClip->m_fileId,
           a5: nullptr);
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
    v10 = v9;
    if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeChannel::m_classType) )
      v11 = (char *)&v10[-1] + 64;
    else
      v11 = nullptr;
    CDmeChannel::SetMode(this: (CDmeChannel *)v11, mode: CM_PLAY);
    CDmeChannel::CreateLog(this: (CDmeChannel *)v11, type: AT_QUATERNION);
    CDmeChannel::SetOutput(this: (CDmeChannel *)v11, pElement: (int)pTransform, pAttribute: "orientation", index: 0);
    if ( v11 != nullptr )
      src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v11 + 4));
    else
      src = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &pChannelsClip->m_Channels,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005428A0
// Name: void CreateAnimationLogs(class CDmeChannelsClip __near *,class CDmeGameModel __near *,class CStudioHdr const __near &,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateAnimationLogs(
        int a1@<ebp>,
        DmElementHandle_t a2@<edi>,
        CDmeChannelsClip *channelsClip,
        CDmeGameModel *pModel,
        CStudioHdr *hdr,
        int sequence,
        float flStartTime,
        float flDuration,
        float flTimeStep)
{
  void *v9; // esp
  const CStudioHdr *v10; // esi
  int NumSeq_Internal; // eax
  int numbones; // edi
  void *v13; // eax
  IMemAlloc_vtbl *v14; // edx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  void *(__thiscall *v16)(IMemAlloc *, unsigned int); // edx
  int v17; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  double v26; // xmm0_8
  CDmeTransform *Bone; // eax
  int v28; // eax
  int v29; // esi
  int v30; // eax
  int v31; // edi
  int v32; // eax
  int v33; // esi
  CUtlSymbolTable::StringPool_t **v34; // edi
  int v35; // eax
  float *v36; // eax
  int v37; // eax
  int v38; // edi
  CUtlSymbolTable::StringPool_t **v39; // esi
  int v40; // eax
  int *v41; // eax
  CDmeChannel **v42; // esi
  const Vector *v43; // edi
  CDmeTypedLog<Vector> *Log; // eax
  int v45; // eax
  CDmeTypedLog<Quaternion> *v46; // eax
  int v47; // [esp+10h] [ebp-1D00h]
  DmeTime_t v48; // [esp+10h] [ebp-1D00h]
  const Quaternion *cycle; // [esp+14h] [ebp-1CFCh]
  Quaternion v51[256]; // [esp+34h] [ebp-1CDCh] BYREF
  Vector v52[256]; // [esp+1034h] [ebp-CDCh] BYREF
  float v53[25]; // [esp+1C34h] [ebp-DCh] BYREF
  void *v54; // [esp+1C98h] [ebp-78h]
  float v55; // [esp+1CACh] [ebp-64h]
  float i; // [esp+1CB0h] [ebp-60h]
  mstudioseqdesc_t *v57; // [esp+1CB4h] [ebp-5Ch]
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v58; // [esp+1CB8h] [ebp-58h] BYREF
  int v59; // [esp+1CC4h] [ebp-4Ch]
  CUtlSymbolTable::StringPool_t **m_pMemory; // [esp+1CC8h] [ebp-48h]
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v61; // [esp+1CCCh] [ebp-44h] BYREF
  int v62; // [esp+1CD8h] [ebp-38h]
  CUtlSymbolTable::StringPool_t **v63; // [esp+1CDCh] [ebp-34h]
  signed int v64; // [esp+1CE0h] [ebp-30h]
  float v65; // [esp+1CE4h] [ebp-2Ch]
  IBoneSetup v66; // [esp+1CE8h] [ebp-28h] BYREF
  float v67; // [esp+1CECh] [ebp-24h]
  float flTime; // [esp+1CF0h] [ebp-20h]
  Quaternion *v69; // [esp+1CF4h] [ebp-1Ch]
  float v70; // [esp+1CF8h] [ebp-18h]
  int m_Size; // [esp+1CFCh] [ebp-14h]
  char v72; // [esp+1D03h] [ebp-Dh]
  int v73; // [esp+1D04h] [ebp-Ch]
  void *v74; // [esp+1D08h] [ebp-8h]
  void *retaddr; // [esp+1D10h] [ebp+0h]

  v73 = a1;
  v74 = retaddr;
  v9 = alloca(7384);
  v10 = hdr;
  if ( hdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: hdr);
  else
    NumSeq_Internal = hdr->m_pStudioHdr->numlocalseq;
  if ( sequence >= NumSeq_Internal )
    sequence = 0;
  numbones = hdr->m_pStudioHdr->numbones;
  v67 = *(float *)&numbones;
  v54 = nullptr;
  memset(&v58, 0, sizeof(v58));
  v59 = 0;
  memset(&v61, 0, sizeof(v61));
  v62 = 0;
  if ( numbones > 0 )
  {
    v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * numbones);
    v14 = _g_pMemAlloc->__vftable;
    v54 = v13;
    Alloc_2 = v14->Alloc_2;
    v58.m_nAllocationCount = numbones;
    v58.m_pMemory = (CUtlSymbolTable::StringPool_t **)Alloc_2(this: _g_pMemAlloc, a2: 4 * numbones);
  }
  m_pMemory = v58.m_pMemory;
  if ( numbones > 0 )
  {
    v16 = _g_pMemAlloc->Alloc_2;
    v61.m_nAllocationCount = numbones;
    v61.m_pMemory = (CUtlSymbolTable::StringPool_t **)v16(this: _g_pMemAlloc, a2: 4 * numbones);
  }
  v63 = v61.m_pMemory;
  Studio_CalcDefaultPoseParameters(pStudioHdr: hdr, flPoseParameter: v53, nCount: 24);
  v70 = Studio_Duration(pStudioHdr: hdr, iSequence: sequence, poseParameter: v53);
  if ( hdr->m_pVModel != nullptr )
  {
    v19 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: sequence);
  }
  else
  {
    v17 = sequence;
    m_pStudioHdr = hdr->m_pStudioHdr;
    if ( sequence < 0 || sequence >= m_pStudioHdr->numlocalseq )
      v17 = 0;
    v19 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v17 + m_pStudioHdr->localseqindex);
  }
  v20 = flStartTime;
  v21 = flStartTime + flDuration;
  v57 = v19;
  v72 = 0;
  flTime = flStartTime;
  v55 = flStartTime + flDuration;
  if ( (float)(flStartTime + flDuration) >= flStartTime )
  {
    v22 = 1.0 / v70;
    for ( i = 1.0 / v70; ; v22 = i )
    {
      if ( v20 > v21 )
      {
        v20 = v21;
        flTime = v21;
      }
      v23 = v22 * v20;
      if ( (v57->flags & 1) == 0 )
        break;
      v24 = v23 - (float)(int)v23;
      v65 = v24;
      if ( v24 < 0.0 )
      {
        v25 = v24 + 1.0;
LABEL_31:
        v65 = v25;
      }
      if ( v72 == 0 )
      {
        v72 = 1;
        v64 = 0;
        if ( numbones > 0 )
        {
          v69 = nullptr;
          do
          {
            m_Size = channelsClip->m_Channels.m_Storage.m_Size;
            Bone = CDmeGameModel::GetBone(this: pModel, index: v64);
            CreateTransformChannels(
              pTransform: Bone,
              pBaseName: (const char *)v10->m_pStudioHdr
            + (unsigned int)v69
            + v10->m_pStudioHdr->boneindex
            + *(int *)((char *)&v10->m_pStudioHdr->id + (unsigned int)v69 + v10->m_pStudioHdr->boneindex),
              pChannelsClip: channelsClip);
            v28 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, DmElementHandle_t))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: channelsClip->m_Channels.m_Storage.m_Memory.m_pMemory[m_Size],
                    a3: a2);
            v29 = v28;
            if ( v28 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v28 + 16))(
                   a1: v28,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              LODWORD(v70) = v29 - 4;
            }
            else
            {
              v70 = 0.0;
            }
            a2 = channelsClip->m_Channels.m_Storage.m_Memory.m_pMemory[m_Size + 1];
            v30 = ((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
            v31 = v30;
            if ( v30 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v30 + 16))(
                   a1: v30,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              m_Size = v31 - 4;
            }
            else
            {
              m_Size = 0;
            }
            v32 = v59;
            v33 = v59;
            if ( v59 + 1 > v58.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &v58, num: v59 - v58.m_nAllocationCount + 1);
              v32 = v59;
            }
            v34 = v58.m_pMemory;
            v59 = v32 + 1;
            v35 = v32 - v33;
            m_pMemory = v58.m_pMemory;
            if ( v35 > 0 )
              _V_memmove(dest: &v58.m_pMemory[v33 + 1], src: &v58.m_pMemory[v33], count: 4 * v35);
            v36 = (float *)&v34[v33];
            if ( v36 != nullptr )
              *v36 = v70;
            v37 = v62;
            v38 = v62;
            if ( v62 + 1 > v61.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &v61, num: v62 - v61.m_nAllocationCount + 1);
              v37 = v62;
            }
            v39 = v61.m_pMemory;
            v62 = v37 + 1;
            v40 = v37 - v38;
            v63 = v61.m_pMemory;
            if ( v40 > 0 )
              _V_memmove(dest: &v61.m_pMemory[v38 + 1], src: &v61.m_pMemory[v38], count: 4 * v40);
            v41 = (int *)&v39[v38];
            if ( v41 != nullptr )
              *v41 = m_Size;
            v69 = (Quaternion *)((char *)v69 + 216);
            v10 = hdr;
            ++v64;
          }
          while ( v64 < SLODWORD(v67) );
          numbones = LODWORD(v67);
        }
      }
      IBoneSetup::IBoneSetup(this: &v66, pStudioHdr: v10, boneMask: 524032, poseParameter: v53, pPoseDebugger: nullptr);
      IBoneSetup::InitPose(this: &v66, pos: v52, q: (QuaternionAligned *)v51);
      IBoneSetup::AccumulatePose(
        this: &v66,
        pos: v52,
        q: v51,
        sequence,
        cycle: v65,
        flWeight: 1.0,
        flTime,
        pIKContext: nullptr);
      if ( numbones > 0 )
      {
        v42 = (CDmeChannel **)v61.m_pMemory;
        m_Size = (char *)v58.m_pMemory - (char *)v61.m_pMemory;
        v69 = v51;
        v43 = v52;
        v70 = v67;
        do
        {
          v47 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(flTime));
          Log = (CDmeTypedLog<Vector> *)CDmeChannel::GetLog(this: *(CDmeChannel **)((char *)v42 + m_Size));
          CDmeTypedLog<Vector>::InsertKey(
            this: Log,
            nTime: (DmeTime_t)v47,
            value: v43,
            interpSetting: SEGMENT_INTERPOLATE,
            curveType: 0,
            bIgnoreTolerance: 0);
          v45 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(flTime));
          cycle = v69;
          v48.m_tms = v45;
          v46 = (CDmeTypedLog<Quaternion> *)CDmeChannel::GetLog(this: *v42);
          CDmeTypedLog<Quaternion>::InsertKey(
            this: v46,
            nTime: v48,
            value: cycle,
            interpSetting: SEGMENT_INTERPOLATE,
            curveType: 0,
            bIgnoreTolerance: 0);
          ++v69;
          ++v43;
          ++v42;
          --LODWORD(v70);
        }
        while ( v70 != 0.0 );
        numbones = LODWORD(v67);
        v10 = hdr;
      }
      IBoneSetup::~IBoneSetup(this: &v66);
      v20 = flTime + flTimeStep;
      v21 = v55;
      flTime = v20;
      if ( v55 < v20 )
        goto LABEL_62;
    }
    if ( v23 >= 0.9999 || v23 >= 0.0 )
    {
      if ( v23 >= 0.9999 )
        v26 = 0.9999;
      else
        v26 = v23;
    }
    else
    {
      v26 = 0.0;
    }
    v25 = v26;
    goto LABEL_31;
  }
LABEL_62:
  if ( v61.m_nGrowSize >= 0 && v61.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v61.m_pMemory);
  if ( v58.m_nGrowSize >= 0 && v58.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v58.m_pMemory);
  if ( v54 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
}

//------------------------------------------------------------------------------
// Address: 0x00542DD0
// Name: class CDmeTransformControl __near * CreateTransformControlAndChannels(char const __near *,class CDmeTransform __near *,class CDmeChannelsClip __near *,class CDmeChannelsClip __near *,class CDmeAnimationSet __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CreateTransformControlAndChannels(
        const char *pName,
        CDmeTransform *pTransform,
        CDmeChannelsClip *pSrcChannelsClip,
        CDmeChannelsClip *pDstChannelsClip,
        CDmeAnimationSet *pAnimationSet,
        bool bUseExistingLogDag)
{
  CDmeTransformControl *v6; // eax
  CDmeChannel *ChannelTargetingTransform; // esi
  CDmElement *v8; // eax
  CDmeTransformControl *v9; // esi
  CDmElement *v10; // eax
  CDmeTransformControl *v11; // esi
  CDmeTransformControl *NewControl; // eax
  CDmeTransformControl *pRotControl; // [esp+4h] [ebp-10h]
  CDmeTransformControl *pPosControl; // [esp+8h] [ebp-Ch]
  CDmeChannel *pRotChannel; // [esp+Ch] [ebp-8h]
  CDmeChannel *pPosChannel; // [esp+10h] [ebp-4h]

  v6 = nullptr;
  if ( pName == nullptr || pTransform == nullptr || pDstChannelsClip == nullptr || pAnimationSet == nullptr )
    return nullptr;
  pPosChannel = nullptr;
  pRotChannel = nullptr;
  if ( pSrcChannelsClip == nullptr )
    goto LABEL_9;
  ChannelTargetingTransform = FindChannelTargetingTransform(
                                pChannelsClip: pSrcChannelsClip,
                                pTransform,
                                controlType: CONTROL_TYPE_POSITION);
  pPosChannel = ChannelTargetingTransform;
  pRotChannel = FindChannelTargetingTransform(
                  pChannelsClip: pSrcChannelsClip,
                  pTransform,
                  controlType: CONTROL_TYPE_ORIENTATION);
  if ( ChannelTargetingTransform == nullptr )
  {
    v6 = nullptr;
LABEL_9:
    pPosControl = nullptr;
    v9 = nullptr;
    goto LABEL_10;
  }
  v8 = CDmeChannel::GetFromElement(this: ChannelTargetingTransform);
  v9 = CastElement<CDmeTransformControl>(pElement: v8);
  pPosControl = v9;
  v6 = nullptr;
LABEL_10:
  if ( pRotChannel != nullptr )
  {
    v10 = CDmeChannel::GetFromElement(this: pRotChannel);
    v6 = CastElement<CDmeTransformControl>(pElement: v10);
  }
  pRotControl = v6;
  v11 = v9 != v6 ? nullptr : v9;
  if ( v11 != nullptr && FindAncestorReferencingElement<CDmeAnimationSet>(target: v11) == pAnimationSet )
  {
    if ( pSrcChannelsClip == pDstChannelsClip )
      return v11;
  }
  else
  {
    NewControl = CDmeAnimationSet::CreateNewControl(this: pAnimationSet, pControlName: pName, bTransformControl: true);
    v11 = CastElement<CDmeTransformControl>(pElement: NewControl);
    if ( v11 == nullptr )
      return v11;
  }
  AttachChannelToTranformControl(
    pName,
    controlType: CONTROL_TYPE_POSITION,
    pAttachChannel: (int)pPosChannel,
    pTransformControl: v11,
    pTransform,
    pSrcChannelsClip,
    pDstChannelsClip,
    bUseExistingLogData: bUseExistingLogDag);
  AttachChannelToTranformControl(
    pName,
    controlType: CONTROL_TYPE_ORIENTATION,
    pAttachChannel: (int)pRotChannel,
    pTransformControl: v11,
    pTransform,
    pSrcChannelsClip,
    pDstChannelsClip,
    bUseExistingLogData: bUseExistingLogDag);
  if ( pPosControl != nullptr && pPosControl != v11 )
    CDmeAnimationSet::RemoveControl(this: pAnimationSet, pControl: pPosControl);
  if ( pRotControl == nullptr || pRotControl == v11 )
    return v11;
  CDmeAnimationSet::RemoveControl(this: pAnimationSet, pControl: pRotControl);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x00542F20
// Name: void SetupBoneTransform(class CDmeChannelsClip __near *,class CDmeChannelsClip __near *,class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CStudioHdr const __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall SetupBoneTransform(
        CBoneSetup *a1@<ebp>,
        CDmeChannelsClip *pSrcChannelsClip,
        CDmeChannelsClip *pDstChannelsClip,
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        const CStudioHdr *hdr,
        unsigned int bonenum,
        bool bUseExistingLogData)
{
  void *v8; // esp
  CDmeTransform *Bone; // edi
  const char *v10; // eax
  Quaternion v11[256]; // [esp+20h] [ebp-1C7Ch] BYREF
  Vector v12[256]; // [esp+1028h] [ebp-C74h] BYREF
  float v13[25]; // [esp+1C28h] [ebp-74h] BYREF
  IBoneSetup v14[4]; // [esp+1C8Ch] [ebp-10h] BYREF
  CBoneSetup *retaddr; // [esp+1C9Ch] [ebp+0h]

  v14[1].m_pBoneSetup = a1;
  v14[2].m_pBoneSetup = retaddr;
  v8 = alloca(7288);
  Bone = CDmeGameModel::GetBone(this: pGameModel, index: bonenum);
  if ( !pGameModel->m_bEvaluateProceduralBones.m_Storage || (hdr->m_boneFlags.m_Memory.m_pMemory[bonenum] & 4) == 0 )
  {
    v10 = (char *)hdr->m_pStudioHdr + 216 * bonenum + hdr->m_pStudioHdr->boneindex;
    CreateTransformControlAndChannels(
      pName: &v10[*(_DWORD *)v10],
      pTransform: Bone,
      pSrcChannelsClip,
      pDstChannelsClip,
      pAnimationSet,
      bUseExistingLogDag: bUseExistingLogData);
    Studio_CalcDefaultPoseParameters(pStudioHdr: hdr, flPoseParameter: v13, nCount: 24);
    IBoneSetup::IBoneSetup(this: v14, pStudioHdr: hdr, boneMask: 524032, poseParameter: v13, pPoseDebugger: nullptr);
    IBoneSetup::InitPose(this: v14, pos: v12, q: (QuaternionAligned *)v11);
    IBoneSetup::AccumulatePose(
      this: v14,
      pos: v12,
      q: v11,
      sequence: 0,
      cycle: 0.0,
      flWeight: 1.0,
      flTime: 0.0,
      pIKContext: nullptr);
    CDmeTransform::SetPosition(this: Bone, vecPosition: &v12[bonenum]);
    CDmeTransform::SetOrientation(this: Bone, orientation: &v11[bonenum]);
    IBoneSetup::~IBoneSetup(this: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005432D0
// Name: void ProcessGroupMapping(class KeyValues __near *,char const __near *,class CUtlDict<class CUtlString,int> __near &,class CUtlVector<struct GroupControlOrdering_t,class CUtlMemory<struct GroupControlOrdering_t,int>> __near &,class Color const __near &,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessGroupMapping(
        KeyValues *pGroupKeyValues,
        const char *pParentName,
        CUtlDict<CUtlString,int> *defaultGroupMapping,
        CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int> > *defaultGroupOrdering,
        const Color *defaultGroupColor,
        const Color *defaultControlColor)
{
  CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int> > *v6; // edi
  int v7; // eax
  CUtlString *v8; // esi
  KeyValues *FirstValue; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v12; // eax
  GroupControlOrdering_t *m_pMemory; // ecx
  int v14; // edi
  int v15; // eax
  CUtlMemory<CUtlString,int> *v16; // esi
  CUtlString *v17; // ecx
  int v18; // eax
  CUtlString *v19; // edi
  KeyValues *i; // esi
  CUtlString element; // [esp+4h] [ebp-2Ch] BYREF
  CUtlString controlName; // [esp+14h] [ebp-1Ch] BYREF
  int v23; // [esp+24h] [ebp-Ch]
  const char *pGroupName; // [esp+28h] [ebp-8h]
  KeyValues *pGroupElement; // [esp+2Ch] [ebp-4h] BYREF

  pGroupName = KeyValues::GetName(this: pGroupKeyValues);
  if ( pGroupName != nullptr )
  {
    v6 = defaultGroupOrdering;
    v7 = CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int>>::InsertBefore(
           this: defaultGroupOrdering,
           elem: defaultGroupOrdering->m_Size) << 6;
    v8 = (CUtlString *)((char *)&defaultGroupOrdering->m_Memory.m_pMemory->groupName + v7);
    v23 = v7;
    CUtlString::operator=(this: v8, src: pGroupName);
    CUtlString::operator=(this: v8 + 1, src: pParentName);
    v8[3].m_Storage.m_Memory.m_nAllocationCount = (int)*KeyValues::GetColor(
                                                          this: pGroupKeyValues,
                                                          result: (Color *)&pGroupElement,
                                                          keyName: "groupColor",
                                                          defaultColor: defaultGroupColor);
    v8[3].m_Storage.m_Memory.m_nGrowSize = (int)*KeyValues::GetColor(
                                                   this: pGroupKeyValues,
                                                   result: (Color *)&pGroupElement,
                                                   keyName: "controlColor",
                                                   defaultColor: defaultControlColor);
    LOBYTE(v8[3].m_Storage.m_nActualLength) = KeyValues::GetInt(
                                                this: pGroupKeyValues,
                                                keyName: "visible",
                                                defaultValue: 1) != 0;
    BYTE1(v8[3].m_Storage.m_nActualLength) = KeyValues::GetInt(
                                               this: pGroupKeyValues,
                                               keyName: "selectable",
                                               defaultValue: 1) != 0;
    BYTE2(v8[3].m_Storage.m_nActualLength) = KeyValues::GetInt(this: pGroupKeyValues, keyName: "snap", defaultValue: 1) != 0;
    FirstValue = KeyValues::GetFirstValue(this: pGroupKeyValues);
    pGroupElement = FirstValue;
    if ( FirstValue != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstValue);
        if ( _V_stricmp(s1: Name, s2: "control") == 0 )
        {
          String = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: &::pParentName);
          CUtlString::CUtlString(this: &controlName, pString: String);
          CUtlString::CUtlString(this: &element, pString: pGroupName);
          v12 = CUtlString::operator char const *(this: &controlName);
          CUtlDict<CUtlString,int>::Insert(this: defaultGroupMapping, pName: v12, &element);
          element.m_Storage.m_nActualLength = 0;
          if ( element.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( element.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: element.m_Storage.m_Memory.m_pMemory);
              element.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            element.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          m_pMemory = v6->m_Memory.m_pMemory;
          v14 = *(int *)((char *)&v6->m_Memory.m_pMemory->controlList.m_Size + v23);
          v15 = *(int *)((char *)&m_pMemory->controlList.m_Memory.m_nAllocationCount + v23);
          v16 = (CUtlMemory<CUtlString,int> *)((char *)&m_pMemory->controlList.m_Memory + v23);
          if ( v14 + 1 > v15 )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(this: v16, num: v14 - v15 + 1);
          ++v16[1].m_pMemory;
          v17 = v16->m_pMemory;
          v18 = (int)v16[1].m_pMemory - v14 - 1;
          v16[1].m_nAllocationCount = (int)v16->m_pMemory;
          if ( v18 > 0 )
            _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 16 * v18);
          v19 = &v16->m_pMemory[v14];
          if ( v19 != nullptr )
            CUtlString::CUtlString(this: v19, string: &controlName);
          controlName.m_Storage.m_nActualLength = 0;
          if ( controlName.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( controlName.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlName.m_Storage.m_Memory.m_pMemory);
              controlName.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            controlName.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          FirstValue = pGroupElement;
          v6 = defaultGroupOrdering;
        }
        pGroupElement = KeyValues::GetNextValue(this: FirstValue);
        if ( pGroupElement == nullptr )
          break;
        FirstValue = pGroupElement;
      }
    }
    for ( i = KeyValues::GetFirstTrueSubKey(this: pGroupKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
      ProcessGroupMapping(
        pGroupKeyValues: i,
        pParentName: pGroupName,
        defaultGroupMapping,
        defaultGroupOrdering: v6,
        defaultGroupColor,
        defaultControlColor);
  }
  else
  {
    _Warning(a1: "%s is malformed\n", "cfg/SFM_DefaultAnimationGroups.txt");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00543520
// Name: LoadDefaultGroupMappings
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadDefaultGroupMappings(
        CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int> > *defaultGroupOrdering@<edi>,
        CUtlDict<CUtlString,int> *defaultGroupMapping,
        const Color *defaultGroupColor,
        const Color *defaultControlColor)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  bool v7; // al
  KeyValues *v8; // ecx
  KeyValues *i; // esi
  KeyValues *pGroupFile; // [esp+4h] [ebp-4h]

  CUtlDict<CUtlString,int>::RemoveAll(this: defaultGroupMapping);
  CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int>>::RemoveAll(this: defaultGroupOrdering);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "groupFile");
    pGroupFile = v5;
    if ( v5 != nullptr )
    {
      if ( g_pFullFileSystem != nullptr )
        v6 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v6 = nullptr;
      v7 = KeyValues::LoadFromFile(
             this: v5,
             filesystem: v6,
             resourceName: "cfg/SFM_DefaultAnimationGroups.txt",
             pathID: "GAME",
             pfnEvaluateSymbolProc: nullptr);
      v8 = v5;
      if ( v7 )
      {
        for ( i = KeyValues::GetFirstTrueSubKey(this: v5); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
          ProcessGroupMapping(
            pGroupKeyValues: i,
            pParentName: &pParentName,
            defaultGroupMapping,
            defaultGroupOrdering,
            defaultGroupColor,
            defaultControlColor);
        v8 = pGroupFile;
      }
      KeyValues::deleteThis(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005435D0
// Name: void BuildGroupMappings(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGroupMappings(CDmeAnimationSet *pAnimationSet)
{
  CDmeControlGroup *v1; // ebx
  char *v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  CDmeControlGroup *v5; // eax
  CDmeControlGroup *v6; // edi
  CDmeAnimationSet *v7; // edi
  CDmeControlGroup *v8; // eax
  CDmaElementArray<CDmElement> *Bookmarks; // eax
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  const char *m_pAsString; // esi
  char *v14; // edi
  int v15; // esi
  CDmeControlGroup *v16; // eax
  char *v17; // ebx
  const char *v18; // eax
  CDmeControlGroup *ControlGroup; // esi
  int v20; // edi
  const char *v21; // eax
  CDmElement *ControlByName; // eax
  int v23; // esi
  CDmeRig *v24; // ecx
  CDmeControlGroup *RootControlGroup; // eax
  CDmeRig **m_pMemory; // eax
  GroupControlOrdering_t *v27; // eax
  int j; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int> *v29; // eax
  CUtlMap<char const *,CUtlString,int>::Node_t search; // [esp+Ch] [ebp-8Ch] BYREF
  char unknownGroupName[8]; // [esp+20h] [ebp-78h] BYREF
  int nCount; // [esp+28h] [ebp-70h]
  char ignoreGroupName[8]; // [esp+2Ch] [ebp-6Ch] BYREF
  CUtlDict<CUtlString,int> defaultGroupMapping; // [esp+34h] [ebp-64h] BYREF
  CUtlVector<CDmeRig *,CUtlMemory<CDmeRig *,int> > rigList; // [esp+58h] [ebp-40h] BYREF
  CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int> > defaultGroupOrdering; // [esp+6Ch] [ebp-2Ch] BYREF
  int nNumGroups; // [esp+80h] [ebp-18h]
  CDmaElementArray<CDmElement> *controls; // [esp+84h] [ebp-14h]
  Color defaultControlColor; // [esp+88h] [ebp-10h] BYREF
  Color defaultGroupColor; // [esp+8Ch] [ebp-Ch] BYREF
  int i; // [esp+90h] [ebp-8h]
  CDmElement *pControl; // [esp+94h] [ebp-4h]

  strcpy(unknownGroupName, "Unknown");
  v1 = nullptr;
  strcpy(ignoreGroupName, "IGNORE");
  defaultGroupMapping.m_Elements.m_Tree.m_Root = -1;
  defaultGroupMapping.m_Elements.m_Tree.m_FirstFree = -1;
  defaultGroupMapping.m_Elements.m_Tree.m_LastAlloc.index = -1;
  defaultGroupColor = (Color)-32768;
  defaultControlColor = (Color)-3618616;
  memset(&defaultGroupMapping.m_Elements.m_Tree.m_Elements, 0, sizeof(defaultGroupMapping.m_Elements.m_Tree.m_Elements));
  defaultGroupMapping.m_Elements.m_Tree.m_NumElements = 0;
  defaultGroupMapping.m_Elements.m_Tree.m_pElements = nullptr;
  defaultGroupMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  memset(&defaultGroupOrdering, 0, sizeof(defaultGroupOrdering));
  LoadDefaultGroupMappings(&defaultGroupOrdering, &defaultGroupMapping, &defaultGroupColor, &defaultControlColor);
  nNumGroups = defaultGroupOrdering.m_Size;
  if ( defaultGroupOrdering.m_Size > 0 )
  {
    pControl = nullptr;
    for ( i = defaultGroupOrdering.m_Size; i != 0; --i )
    {
      v2 = (char *)pControl + (unsigned int)defaultGroupOrdering.m_Memory.m_pMemory;
      if ( CUtlString::Length(this: (CUtlString *)&pControl->m_Id.m_Value[(unsigned int)defaultGroupOrdering.m_Memory.m_pMemory
                                                                        + 12]) != 0 )
      {
        v3 = CUtlString::operator char const *(this: (CUtlString *)v2 + 1);
        v1 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimationSet, pParentGroup: nullptr, pControlGroupName: v3);
      }
      v4 = CUtlString::operator char const *(this: (CUtlString *)v2);
      v5 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimationSet, pParentGroup: v1, pControlGroupName: v4);
      v6 = v5;
      if ( v5 != nullptr )
      {
        CDmeControlGroup::SetVisible(this: v5, bVisible: v2[60]);
        CDmeControlGroup::SetSnappable(this: v6, bSnappable: v2[62]);
        CDmeControlGroup::SetSelectable(this: v6, bSelectable: v2[61]);
        CDmeControlGroup::SetGroupColor(this: v6, groupColor: (const Color *)v2 + 13, bRecursive: false);
        CDmeControlGroup::SetControlColor(this: v6, controlColor: (const Color *)v2 + 14, bRecursive: false);
      }
      pControl = (CDmElement *)((char *)pControl + 64);
      v1 = nullptr;
    }
  }
  v7 = pAnimationSet;
  v8 = CDmeAnimationSet::FindOrAddControlGroup(
         this: pAnimationSet,
         pParentGroup: nullptr,
         pControlGroupName: unknownGroupName);
  if ( v8 != nullptr )
    CDmeControlGroup::SetGroupColor(this: v8, groupColor: &defaultGroupColor, bRecursive: false);
  Bookmarks = (CDmaElementArray<CDmElement> *)CDmeBookmarkSet::GetBookmarks(this: (CDmeTransform *)pAnimationSet);
  m_Size = Bookmarks->m_Storage.m_Size;
  controls = Bookmarks;
  nCount = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: Bookmarks->m_Storage.m_Memory.m_pMemory[i]);
      v12 = v11;
      if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmElement::m_classType) )
      {
        pControl = v12;
      }
      else
      {
        pControl = nullptr;
        v12 = nullptr;
      }
      if ( AddConstraintControlToGroup(
             pControl: v12,
             pAnimationSet: v7,
             groupColor: &defaultGroupColor,
             &defaultGroupMapping) == 0 )
      {
        m_pAsString = v12->m_Name.m_Storage.u.m_pAsString;
        v14 = unknownGroupName;
        if ( m_pAsString == (const char *)-1 )
          break;
        if ( m_pAsString != nullptr )
          goto LABEL_21;
LABEL_27:
        if ( _V_stricmp(s1: v14, s2: ignoreGroupName) != 0 )
        {
          v16 = CDmeAnimationSet::FindOrAddControlGroup(
                  this: pAnimationSet,
                  pParentGroup: nullptr,
                  pControlGroupName: v14);
          if ( v16 != nullptr )
            CDmeControlGroup::AddControl(this: v16, pControl, pInsertBeforeControl: nullptr);
        }
        v7 = pAnimationSet;
      }
      if ( ++i >= nCount )
        goto LABEL_32;
      Bookmarks = controls;
    }
    m_pAsString = &pParentName;
LABEL_21:
    CUtlString::CUtlString(this: &search.elem);
    search.key = m_pAsString;
    v15 = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::Find(
            this: &defaultGroupMapping.m_Elements.m_Tree,
            &search);
    search.elem.m_Storage.m_nActualLength = 0;
    if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
        search.elem.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      search.elem.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    if ( v15 != -1 )
      v14 = (char *)CUtlString::operator char const *(this: &defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory[v15].m_Data.elem);
    goto LABEL_27;
  }
LABEL_32:
  if ( nNumGroups > 0 )
  {
    i = 0;
    for ( controls = (CDmaElementArray<CDmElement> *)nNumGroups;
          controls != nullptr;
          controls = (CDmaElementArray<CDmElement> *)((char *)controls - 1) )
    {
      v17 = (char *)defaultGroupOrdering.m_Memory.m_pMemory + i;
      v18 = CUtlString::operator char const *(this: (CUtlString *)((char *)&defaultGroupOrdering.m_Memory.m_pMemory->groupName
                                                                 + i));
      ControlGroup = CDmeAnimationSet::FindControlGroup(this: v7, pControlGroupName: v18);
      if ( ControlGroup != nullptr && *((int *)v17 + 11) > 0 )
      {
        v20 = 0;
        pControl = *((CDmElement **)v17 + 11);
        do
        {
          v21 = CUtlString::operator char const *(this: (CUtlString *)(v20 + *((_DWORD *)v17 + 8)));
          ControlByName = CDmeControlGroup::FindControlByName(
                            this: ControlGroup,
                            pchName: v21,
                            recursive: false,
                            pParentGroup: nullptr);
          if ( ControlByName != nullptr )
            CDmeControlGroup::AddControl(this: ControlGroup, pControl: ControlByName, pInsertBeforeControl: nullptr);
          v20 += 16;
          pControl = (CDmElement *)((char *)pControl - 1);
        }
        while ( pControl != nullptr );
        v7 = pAnimationSet;
      }
      i += 64;
    }
  }
  memset(&rigList, 0, sizeof(rigList));
  CollectRigsOnAnimationSet(pAnimSet: v7, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&rigList);
  v23 = 0;
  for ( nNumGroups = rigList.m_Size; v23 < nNumGroups; ++v23 )
  {
    v24 = rigList.m_Memory.m_pMemory[v23];
    if ( v24 != nullptr )
      CDmeRig::HideHiddenControlGroups(this: v24, pAnimationSet: v7);
  }
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: v7);
  CDmeControlGroup::DestroyEmptyChildren(this: RootControlGroup);
  m_pMemory = rigList.m_Memory.m_pMemory;
  rigList.m_Size = 0;
  if ( rigList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( rigList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rigList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      rigList.m_Memory.m_pMemory = nullptr;
    }
    rigList.m_Memory.m_nAllocationCount = 0;
  }
  rigList.m_pElements = m_pMemory;
  if ( rigList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      rigList.m_Memory.m_pMemory = nullptr;
    }
    rigList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int>>::RemoveAll(this: &defaultGroupOrdering);
  v27 = defaultGroupOrdering.m_Memory.m_pMemory;
  if ( defaultGroupOrdering.m_Memory.m_nGrowSize >= 0 )
  {
    if ( defaultGroupOrdering.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultGroupOrdering.m_Memory.m_pMemory);
      v27 = nullptr;
      defaultGroupOrdering.m_Memory.m_pMemory = nullptr;
    }
    defaultGroupOrdering.m_Memory.m_nAllocationCount = 0;
  }
  defaultGroupOrdering.m_pElements = v27;
  if ( defaultGroupOrdering.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v27 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27);
      defaultGroupOrdering.m_Memory.m_pMemory = nullptr;
    }
    defaultGroupOrdering.m_Memory.m_nAllocationCount = 0;
  }
  for ( j = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::FirstInorder(this: &defaultGroupMapping.m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::NextInorder(
              this: &defaultGroupMapping.m_Elements.m_Tree,
              i: j) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::RemoveAll(this: &defaultGroupMapping.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::RemoveAll(this: &defaultGroupMapping.m_Elements.m_Tree);
  v29 = defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory;
  defaultGroupMapping.m_Elements.m_Tree.m_FirstFree = -1;
  if ( defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory);
      v29 = nullptr;
      defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  defaultGroupMapping.m_Elements.m_Tree.m_LastAlloc.index = -1;
  if ( defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 && v29 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
}

//------------------------------------------------------------------------------
// Address: 0x00543A50
// Name: class CDmeAnimationSet __near * CreateAnimationSet(class CDmeFilmClip __near *,class CDmeFilmClip __near *,class CDmeGameModel __near *,char const __near *,bool,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__cdecl CreateAnimationSet(
        CDmeFilmClip *pMovie,
        CDmeFilmClip *pShot,
        int pGameModel,
        CDmeAnimationSet *pAnimationSetName,
        int bAttachToGameRecording,
        CDmElement *pSharedPresetGroupSettings)
{
  signed int v6; // edi
  DmElementHandle_t v7; // eax
  CDmElement *v8; // eax
  const char *v9; // esi
  CDmeAnimationSet *v10; // ebx
  CExpressionCalculator *v11; // esi
  const studiohdr_t *StudioHdr; // eax
  CDmAttribute *Attribute; // eax
  CDmeTrackGroup *ChannelsClip; // ebx
  CDmeChannelsClip *v15; // eax
  CDmeTransform *Transform; // eax
  CDmeGameModel *v17; // eax
  CDmeGameModel *numbones; // ecx
  CDmAttribute *v19; // edi
  const char *ModelName; // eax
  CDmeAnimationSet *v21; // edi
  studiohdr_t *v22; // eax
  int studiohdr2index; // ecx
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // edi
  CExpressionCalculator *Child; // eax
  CDmeAnimationSet *v27; // esi
  CFlexControlBuilder::ControlInfo_t *m_pMemory; // eax
  CFlexControlBuilder::FlexControllerInfo_t *v29; // eax
  int *v30; // eax
  int *v31; // eax
  const studiohdr_t **v32; // eax
  CDmeGameModel *v34; // [esp-4h] [ebp-CCh]
  CDmeChannelsClip *v35; // [esp+10h] [ebp-B8h]
  CDmeAnimationSet *flDuration; // [esp+18h] [ebp-B0h]
  bool flTimeStep; // [esp+1Ch] [ebp-ACh]
  CStudioHdr hdr; // [esp+2Ch] [ebp-9Ch] BYREF
  CFlexControlBuilder builder; // [esp+90h] [ebp-38h] BYREF
  CDmeChannelsClip *srcChannelsClip; // [esp+BCh] [ebp-Ch]
  CDmrElementArray<CDmePresetGroupInfo> presetGroupInfos; // [esp+C0h] [ebp-8h] BYREF
  int savedregs; // [esp+C8h] [ebp+0h] BYREF

  v6 = 0;
  v7 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeAnimationSet::m_classType.u.m_Id,
         a3: (const char *)pAnimationSetName,
         a4: pShot->m_fileId,
         a5: nullptr);
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7);
  v9 = (const char *)v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeAnimationSet::m_classType) )
  {
    v10 = (CDmeAnimationSet *)v9;
    pAnimationSetName = (CDmeAnimationSet *)v9;
  }
  else
  {
    pAnimationSetName = nullptr;
    v10 = nullptr;
  }
  v11 = (CExpressionCalculator *)pGameModel;
  StudioHdr = CDmeGameModel::GetStudioHdr(this: (CDmeGameModel *)pGameModel);
  CStudioHdr::CStudioHdr(this: &hdr, pStudioHdr: StudioHdr, mdlcache: g_pMDLCache);
  if ( v11 != nullptr )
    pGameModel = CExpressionCalculator::VariableCount(this: v11);
  else
    pGameModel = -1;
  Attribute = CDmElement::FindAttribute(this: v10, pAttributeName: "gameModel");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v10, pAttributeName: "gameModel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pGameModel);
  }
  ChannelsClip = CreateChannelsClip(pAnimationSet: v10, pOwnerClip: pShot);
  memset(&builder, 0, 40);
  CFlexControlBuilder::CreateAnimationSetControls(
    this: &builder,
    pMovie,
    pAnimationSet: pAnimationSetName,
    pGameModel: (CDmeGameModel *)v11,
    pSourceClip: pShot,
    pDestClip: (CDmeChannelsClip *)ChannelsClip,
    bUseExistingLogs: bAttachToGameRecording);
  if ( (_BYTE)bAttachToGameRecording == 0 )
  {
    pGameModel = 0;
    CreateConstantValuedLog<int>(
      channelsClip: (int)ChannelsClip,
      pName: "skin",
      pToElement: (CDmElement *)v11,
      pToAttr: "skin",
      value: &pGameModel);
    pGameModel = 0;
    CreateConstantValuedLog<int>(
      channelsClip: (int)ChannelsClip,
      pName: "body",
      pToElement: (CDmElement *)v11,
      pToAttr: "body",
      value: &pGameModel);
    pGameModel = 0;
    CreateConstantValuedLog<int>(
      channelsClip: (int)ChannelsClip,
      pName: "sequence",
      pToElement: (CDmElement *)v11,
      pToAttr: "sequence",
      value: &pGameModel);
    CreateAnimationLogs(
      a1: (int)&savedregs,
      a2: (DmElementHandle_t)0,
      channelsClip: (CDmeChannelsClip *)ChannelsClip,
      pModel: (CDmeGameModel *)v11,
      &hdr,
      sequence: 0,
      flStartTime: 0.0,
      flDuration: 1.0,
      flTimeStep: 0.050000001);
  }
  v15 = FindChannelsClip(pDag: (CDmeDag *)v11);
  flTimeStep = bAttachToGameRecording;
  flDuration = pAnimationSetName;
  v35 = v15;
  srcChannelsClip = v15;
  Transform = CDmeDag::GetTransform(this: (CDmeDag *)v11);
  CreateTransformControlAndChannels(
    pName: "rootTransform",
    pTransform: Transform,
    pSrcChannelsClip: v35,
    pDstChannelsClip: (CDmeChannelsClip *)ChannelsClip,
    pAnimationSet: flDuration,
    bUseExistingLogDag: flTimeStep);
  v17 = (CDmeGameModel *)CDmeGameModel::NumBones(this: (CDmeGameModel *)v11);
  numbones = (CDmeGameModel *)hdr.m_pStudioHdr->numbones;
  pGameModel = (int)numbones;
  if ( v17 != numbones )
  {
    if ( (int)v17 < (int)numbones )
      pGameModel = (int)v17;
    _Warning(a1: "Creating an animationset for a model whose bone count has changed! You should reattach to the model.\n");
    numbones = (CDmeGameModel *)pGameModel;
  }
  if ( (int)numbones > 0 )
  {
    do
      SetupBoneTransform(
        a1: (CBoneSetup *)&savedregs,
        pSrcChannelsClip: srcChannelsClip,
        pDstChannelsClip: (CDmeChannelsClip *)ChannelsClip,
        pAnimationSet: pAnimationSetName,
        pGameModel: (CDmeGameModel *)v11,
        &hdr,
        bonenum: v6++,
        bUseExistingLogData: bAttachToGameRecording);
    while ( v6 < pGameModel );
  }
  if ( srcChannelsClip != nullptr )
    TransferRemainingChannels(shot: pShot, destClip: (CDmeChannelsClip *)ChannelsClip, srcClip: srcChannelsClip);
  if ( pSharedPresetGroupSettings != nullptr )
    v19 = CDmElement::FindAttribute(this: pSharedPresetGroupSettings, pAttributeName: "presetGroupInfos");
  else
    v19 = nullptr;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupInfos);
  if ( v19 != nullptr && (v19->m_nFlags & 0x1F) == 0xF )
  {
    presetGroupInfos.m_pAttribute = v19;
    presetGroupInfos.m_pStorage = (DmElementArray_t *)v19->m_pData;
  }
  else
  {
    presetGroupInfos.m_pAttribute = nullptr;
    presetGroupInfos.m_pStorage = nullptr;
  }
  ModelName = CDmeGameModel::GetModelName(this: (CDmeGameModel *)v11);
  v21 = pAnimationSetName;
  LoadPresetGroups(pAnimationSet: pAnimationSetName, pModelName: ModelName, &presetGroupInfos);
  BuildGroupMappings(pAnimationSet: v21);
  v22 = CDmeGameModel::GetStudioHdr(this: (CDmeGameModel *)v11);
  if ( v22 != nullptr )
  {
    studiohdr2index = v22->studiohdr2index;
    if ( studiohdr2index == 0 || *(int *)((char *)&v22->checksum + studiohdr2index) <= 0 )
    {
      v24 = CDmElement::FindAttribute(this: (CDmElement *)v11, pAttributeName: "illumPositionDag");
      v25 = v24 != nullptr
          ? ((unsigned __int8)((v24->m_nFlags & 0x1F) - 1) == 0
           ? v24
           : nullptr)
          : CDmElement::CreateAttribute(
              this: (CDmElement *)v11,
              pAttributeName: "illumPositionDag",
              type: AT_FIRST_VALUE_TYPE);
      if ( v25 != nullptr )
      {
        CDmAttribute::SetElementTypeSymbol(this: v25, typeSymbol: CDmeDag::m_classType);
        Child = (CExpressionCalculator *)CDmeDag::GetChild(this: (CDmeDag *)v11, i: 0);
        if ( (v25->m_nFlags & 0x1F) == 1 )
        {
          if ( Child != nullptr )
            bAttachToGameRecording = CExpressionCalculator::VariableCount(this: Child);
          else
            bAttachToGameRecording = -1;
          CDmAttribute::SetValue<enum DmElementHandle_t>(this: v25, value: (DmElementHandle_t *)&bAttachToGameRecording);
        }
      }
    }
  }
  if ( CDmeGameModel::FindAttachment(this: (CDmeGameModel *)v11, pchAttachmentName: "eyes") <= 0 )
  {
    v27 = pAnimationSetName;
  }
  else
  {
    AddLocalViewTargetControl(
      pFilmClip: pShot,
      pAnimSet: pAnimationSetName,
      pGameModel: (CDmeGameModel *)v11,
      pChannelsClip: (CDmeChannelsClip *)ChannelsClip);
    AddEyeConvergenceControl(
      pAnimationSet: pAnimationSetName,
      pGameModel: (CDmeGameModel *)v11,
      pChannelsClip: (CDmeChannelsClip *)ChannelsClip);
    v34 = (CDmeGameModel *)v11;
    v27 = pAnimationSetName;
    AddViewTargetControl(
      pFilmClip: pShot,
      pAnimationSet: pAnimationSetName,
      pGameModel: v34,
      pChannelsClip: (CDmeChannelsClip *)ChannelsClip);
  }
  CDmeAnimationSet::UpdateTransformDefaults(this: v27);
  m_pMemory = builder.m_ControlInfo.m_Memory.m_pMemory;
  builder.m_ControlInfo.m_Size = 0;
  if ( builder.m_ControlInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( builder.m_ControlInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: builder.m_ControlInfo.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      builder.m_ControlInfo.m_Memory.m_pMemory = nullptr;
    }
    builder.m_ControlInfo.m_Memory.m_nAllocationCount = 0;
  }
  builder.m_ControlInfo.m_pElements = m_pMemory;
  if ( builder.m_ControlInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      builder.m_ControlInfo.m_Memory.m_pMemory = nullptr;
    }
    builder.m_ControlInfo.m_Memory.m_nAllocationCount = 0;
  }
  v29 = builder.m_FlexControllerInfo.m_Memory.m_pMemory;
  builder.m_FlexControllerInfo.m_Size = 0;
  if ( builder.m_FlexControllerInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( builder.m_FlexControllerInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: builder.m_FlexControllerInfo.m_Memory.m_pMemory);
      v29 = nullptr;
      builder.m_FlexControllerInfo.m_Memory.m_pMemory = nullptr;
    }
    builder.m_FlexControllerInfo.m_Memory.m_nAllocationCount = 0;
  }
  builder.m_FlexControllerInfo.m_pElements = v29;
  if ( builder.m_FlexControllerInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v29 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
      builder.m_FlexControllerInfo.m_Memory.m_pMemory = nullptr;
    }
    builder.m_FlexControllerInfo.m_Memory.m_nAllocationCount = 0;
  }
  CStudioHdr::Term(this: &hdr);
  v30 = hdr.m_boneParent.m_Memory.m_pMemory;
  hdr.m_boneParent.m_Size = 0;
  if ( hdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( hdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hdr.m_boneParent.m_Memory.m_pMemory);
      v30 = nullptr;
      hdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  hdr.m_boneParent.m_pElements = v30;
  if ( hdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v30 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v30);
      hdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v31 = hdr.m_boneFlags.m_Memory.m_pMemory;
  hdr.m_boneFlags.m_Size = 0;
  if ( hdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( hdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hdr.m_boneFlags.m_Memory.m_pMemory);
      v31 = nullptr;
      hdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  hdr.m_boneFlags.m_pElements = v31;
  if ( hdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v31 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v31);
      hdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v32 = hdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  hdr.m_pStudioHdrCache.m_Size = 0;
  if ( hdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( hdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v32 = nullptr;
      hdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  hdr.m_pStudioHdrCache.m_pElements = v32;
  if ( hdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v32 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
  return v27;
}

//------------------------------------------------------------------------------
// Address: 0x0053F9A0
// Name: class CDmeChannelsClip __near * CreateElement<class CDmeChannelsClip>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *__cdecl CreateElement<CDmeChannelsClip>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeChannelsClip::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
    return (CDmeChannelsClip *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0053FD20
// Name: class CDmeExpressionOperator __near * CreateElement<class CDmeExpressionOperator>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeExpressionOperator *__cdecl CreateElement<CDmeExpressionOperator>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeExpressionOperator::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeExpressionOperator::m_classType) )
    return (CDmeExpressionOperator *)((char *)&v5[-1] + 64);
  else
    return nullptr;
}

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005391B0
// Name: void RetimeLogData(class CDmeChannelsClip __near *,class CDmeChannelsClip __near *,class CDmeLog __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RetimeLogData(CDmeChannelsClip *pSrcChannelsClip, CDmeChannelsClip *pDstChannelsClip, CDmeLog *pLog)
{
  int v3; // edx
  int v4; // ecx
  int f; // xmm1_4
  CDmAttribute *KeyCount; // ebx
  int i; // esi
  CDmeLog_vtbl *v8; // edx
  DmeTime_t result; // [esp+18h] [ebp-24h] BYREF
  float scale; // [esp+1Ch] [ebp-20h]
  DmeTime_t dstStart; // [esp+20h] [ebp-1Ch] BYREF
  DmeTime_t srcStart; // [esp+24h] [ebp-18h] BYREF
  DmeTime_t keyTime; // [esp+28h] [ebp-14h] BYREF
  DmeTime_t srcScale; // [esp+2Ch] [ebp-10h] BYREF
  DmeTime_t dstScale; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t dstOffset; // [esp+34h] [ebp-8h] BYREF
  DmeTime_t srcOffset; // [esp+38h] [ebp-4h] BYREF

  *(float *)&srcScale.m_tms = CDmeClip::GetTimeScale(this: &pSrcChannelsClip->CDmeClip);
  *(float *)&dstScale.m_tms = CDmeClip::GetTimeScale(this: &pDstChannelsClip->CDmeClip);
  CDmeClip::GetStartTime(this: &pSrcChannelsClip->CDmeClip, result: &srcStart);
  CDmeClip::GetStartTime(this: &pDstChannelsClip->CDmeClip, result: &dstStart);
  CDmeClip::GetTimeOffset(this: &pSrcChannelsClip->CDmeClip, result: &srcOffset);
  CDmeClip::GetTimeOffset(this: &pDstChannelsClip->CDmeClip, result: &dstOffset);
  v3 = srcOffset.m_tms - srcStart.m_tms;
  v4 = dstOffset.m_tms - dstStart.m_tms;
  srcOffset.m_tms -= srcStart.m_tms;
  dstOffset.m_tms -= dstStart.m_tms;
  if ( *(float *)&srcScale.m_tms != *(float *)&dstScale.m_tms || v3 != v4 )
  {
    f = dstScale.m_tms;
    dstScale.m_tms = v4 - v3;
    scale = *(float *)&f / *(float *)&srcScale.m_tms;
    DmeTime_t::operator*=(this: &dstScale, result: &keyTime, f: *(float *)&f);
    KeyCount = CDmeLog::GetKeyCount(this: pLog);
    for ( i = 0; i < (int)KeyCount; ++i )
    {
      pLog->GetKeyTime(this: pLog, result: &keyTime, a3: i);
      srcScale.m_tms = keyTime.m_tms;
      DmeTime_t::operator*=(this: &srcScale, &result, f: scale);
      v8 = pLog->__vftable;
      keyTime.m_tms = srcScale.m_tms + dstScale.m_tms;
      ((void (__thiscall *)(CDmeLog *, int, int))v8->SetKeyTime)(a1: pLog, a2: i, a3: srcScale.m_tms + dstScale.m_tms);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005393B0
// Name: class CDmeChannelsClip __near * CreateChannelsClip(class CDmeAnimationSet __near *,class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__cdecl CreateChannelsClip(CDmeAnimationSet *pAnimationSet, CDmeFilmClip *pOwnerClip)
{
  CDmeTrackGroup *result; // eax
  CDmeTrack *v3; // ecx
  const char *m_pAsString; // eax
  CDmeClip *NamedClip; // eax
  CDmeChannelsClip *v6; // esi
  const char *v7; // eax
  int v8; // eax
  DmeTime_t *Duration; // eax
  int v10; // edi
  int v11; // eax
  DmeTime_t childMediaDuration; // [esp+14h] [ebp-Ch] BYREF
  DmeTime_t childMediaTime; // [esp+18h] [ebp-8h] BYREF
  CDmeTrack *pAnimSetEditorTrack; // [esp+1Ch] [ebp-4h] BYREF

  result = CDmeClip::FindOrAddTrackGroup(this: pOwnerClip, pTrackGroupName: "channelTrackGroup");
  if ( result != nullptr )
  {
    v3 = CDmeTrackGroup::FindOrAddTrack(this: result, pTrackName: "animSetEditorChannels", trackType: DMECLIP_FIRST);
    m_pAsString = pAnimationSet->m_Name.m_Storage.u.m_pAsString;
    pAnimSetEditorTrack = v3;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    NamedClip = CDmeTrack::FindNamedClip(this: v3, name: m_pAsString);
    v6 = (CDmeChannelsClip *)NamedClip;
    if ( NamedClip == nullptr || !NamedClip->IsA(this: NamedClip, a2: CDmeChannelsClip::m_classType) )
    {
      v7 = pAnimationSet->m_Name.m_Storage.u.m_pAsString;
      if ( v7 == (const char *)-1 )
        v7 = &pch;
      v6 = CreateElement<CDmeChannelsClip>(pObjectName: v7, fileid: pAnimationSet->m_fileId, pObjectID: nullptr);
      CDmeTrack::AddClip(this: pAnimSetEditorTrack, clip: &v6->CDmeClip);
    }
    CDmeClip::GetStartInChildMediaTime(this: pOwnerClip, result: &childMediaTime);
    v8 = DmeTime_t::RoundSecondsToTMS(sec: 0x40A00000u);
    CDmeClip::SetStartTime(this: &v6->CDmeClip, t: (DmeTime_t)(childMediaTime.m_tms - v8));
    Duration = CDmeClip::GetDuration(this: pOwnerClip, result: (DmeTime_t *)&pAnimSetEditorTrack);
    CDmeClip::ToChildMediaDuration(this: pOwnerClip, result: &childMediaDuration, dt: (DmeTime_t)Duration->m_tms);
    v10 = DmeTime_t::RoundSecondsToTMS(sec: 0x40A00000u);
    v11 = DmeTime_t::RoundSecondsToTMS(sec: 0x40A00000u);
    CDmeClip::SetDuration(this: &v6->CDmeClip, t: (DmeTime_t)(childMediaDuration.m_tms + v10 + v11));
    return (CDmeTrackGroup *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005394D0
// Name: class CDmeChannel __near * CreateConstantValuedLog<int>(class CDmeChannelsClip __near *,char const __near *,class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl CreateConstantValuedLog<int>(
        int channelsClip,
        const char *pName,
        CDmElement *pToElement,
        const char *pToAttr,
        int *value)
{
  CDmeChannelsClip *v5; // edi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  char *v9; // esi
  CDmeTypedLog<int> *Log; // eax
  int *v12; // [esp-10h] [ebp-18h]

  v5 = (CDmeChannelsClip *)channelsClip;
  v6 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
         a3: pName,
         a4: *(DmFileId_t *)(channelsClip + 56),
         a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeChannel::m_classType) )
    v9 = (char *)&v8[-1] + 64;
  else
    v9 = nullptr;
  CDmeChannel::SetMode(this: (CDmeChannel *)v9, mode: CM_PLAY);
  CDmeChannel::CreateLog(this: (CDmeChannel *)v9, type: AT_INT);
  CDmeChannel::SetOutput(this: (CDmeChannel *)v9, pElement: (int)pToElement, pAttribute: pToAttr, index: 0);
  v12 = value;
  Log = (CDmeTypedLog<int> *)CDmeChannel::GetLog(this: (CDmeChannel *)v9);
  CDmeTypedLog<int>::InsertKey(
    this: Log,
    nTime: 0,
    value: v12,
    interpSetting: SEGMENT_INTERPOLATE,
    curveType: 0,
    bIgnoreTolerance: 0);
  if ( v9 != nullptr )
    channelsClip = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v9 + 4));
  else
    channelsClip = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &v5->m_Channels,
    src: (const DmElementHandle_t *)&channelsClip);
  return (CDmeChannel *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x00539C30
// Name: class CDmeChannelsClip __near * FindChannelsClip(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__cdecl FindChannelsClip(CDmeDag *pDag)
{
  CDmeChannel *Referring; // eax
  CExpressionCalculator *Transform; // eax
  int v3; // ebx
  unsigned int v4; // edi
  CExpressionCalculator *Bone; // eax

  if ( pDag == nullptr )
    return nullptr;
  Referring = FindReferringElement<CDmeChannel>(
                pElement: (CExpressionCalculator *)pDag,
                symAttrName: (CUtlSymbolLarge)-1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
  {
    Transform = (CExpressionCalculator *)CDmeDag::GetTransform(this: pDag);
    Referring = FindReferringElement<CDmeChannel>(
                  pElement: Transform,
                  symAttrName: (CUtlSymbolLarge)-1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
    {
      if ( ((int (__thiscall *)(_DWORD, _DWORD))pDag->IsA)(
             a1: pDag,
             a2: (CUtlSymbolLarge)CDmeGameModel::m_classType.u.m_Id) )
      {
        v3 = CDmeGameModel::NumBones(this: (CDmeGameModel *)pDag);
        v4 = 0;
        if ( v3 > 0 )
        {
          while ( 1 )
          {
            Bone = (CExpressionCalculator *)CDmeGameModel::GetBone(this: (CDmeGameModel *)pDag, index: v4);
            Referring = FindReferringElement<CDmeChannel>(
                          pElement: Bone,
                          symAttrName: (CUtlSymbolLarge)-1,
                          bMustBeInSameFile: false,
                          depth: TD_ALL);
            if ( Referring != nullptr )
              break;
            if ( (int)++v4 >= v3 )
              return nullptr;
          }
          return FindReferringElement<CDmeChannelsClip>(
                   pElement: (CExpressionCalculator *)&Referring->CDmElement,
                   symAttrName: (CUtlSymbolLarge)-1,
                   bMustBeInSameFile: false,
                   depth: TD_ALL);
        }
      }
      return nullptr;
    }
  }
  return FindReferringElement<CDmeChannelsClip>(
           pElement: (CExpressionCalculator *)&Referring->CDmElement,
           symAttrName: (CUtlSymbolLarge)-1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x00539CF0
// Name: void TransferRemainingChannels(class CDmeFilmClip __near *,class CDmeChannelsClip __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransferRemainingChannels(CDmeFilmClip *shot, CDmeChannelsClip *destClip, CDmeChannelsClip *srcClip)
{
  CDmeChannelsClip *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  int v7; // ecx
  char *v8; // esi
  CDmeLog *Log; // eax
  IDataModel_vtbl *v10; // esi
  int v11; // eax
  DmAttributeReferenceIterator_t v12; // edi
  CDmeTrack *m_pOwner; // esi
  IDataModel_vtbl *v14; // esi
  int v15; // eax
  int channelsCount; // [esp+Ch] [ebp-4h]

  v3 = srcClip;
  if ( srcClip != destClip )
  {
    v4 = 0;
    channelsCount = srcClip->m_Channels.m_Storage.m_Size;
    if ( channelsCount > 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Channels.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeChannel::m_classType) )
        {
          v8 = (char *)&v6[-1] + 64;
          if ( v8 != nullptr )
          {
            _Msg(a1: v7, a2: "Transferring '%s'\n");
            srcClip = (CDmeChannelsClip *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v8 + 4));
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &destClip->m_Channels,
              src: (const DmElementHandle_t *)&srcClip);
            CDmeChannel::SetMode(this: (CDmeChannel *)v8, mode: CM_PLAY);
            Log = CDmeChannel::GetLog(this: (CDmeChannel *)v8);
            if ( Log != nullptr )
              RetimeLogData(pSrcChannelsClip: v3, pDstChannelsClip: destClip, pLog: Log);
          }
        }
        ++v4;
      }
      while ( v4 < channelsCount );
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &v3->m_Channels);
    v10 = g_pDataModel->__vftable;
    v11 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
    v12 = v10->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v11);
    if ( v12 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    {
      while ( 1 )
      {
        m_pOwner = (CDmeTrack *)g_pDataModel->GetAttribute(this: g_pDataModel, a2: v12)->m_pOwner;
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeTrack::m_classType) )
          break;
        v12 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v12);
        if ( v12 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
          return;
      }
      CDmeTrack::RemoveClip(this: m_pOwner, clip: &v3->CDmeClip);
      v14 = g_pDataModel->__vftable;
      v15 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      v14->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v15);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00539E70
// Name: void AttachChannelToTranformControl(char const __near *,enum ControlType_t,class CDmeChannel __near *,class CDmeTransformControl __near *,class CDmeTransform __near *,class CDmeChannelsClip __near *,class CDmeChannelsClip __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AttachChannelToTranformControl(
        const char *pName,
        ControlType_t controlType,
        int pAttachChannel,
        CDmeTransformControl *pTransformControl,
        CDmeTransform *pTransform,
        CDmeChannelsClip *pSrcChannelsClip,
        CDmeChannelsClip *pDstChannelsClip,
        bool bUseExistingLogData)
{
  CDmeChannel *v8; // edi
  const char *v9; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmAttribute *v13; // eax
  CDmeChannelsClip *v14; // ebx
  int v15; // eax
  CDmaVar<Vector> *Bookmarks; // eax
  CDmeTransformControl *v17; // esi
  CDmAttribute *OrientationAttr; // eax
  CDmaVar<Quaternion> *Orientation; // eax
  CDmeTransformControl *v20; // esi
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v22; // esi
  CDmeTimeFrame *TimeFrame; // edi
  CDmeTimeFrame *v24; // eax
  int m_tms; // edx
  float m_Storage; // xmm0_4
  int v27; // ebx
  int v28; // edi
  float v29; // xmm1_4
  int v30; // ecx
  CDmAttribute *KeyCount; // ebx
  int i; // edi
  CDmaVar<Vector> *v33; // eax
  CDmaVar<Quaternion> *v34; // eax
  char szName[512]; // [esp+2Ch] [ebp-21Ch] BYREF
  DmeTime_t v36; // [esp+22Ch] [ebp-1Ch] BYREF
  DmeTime_t result; // [esp+230h] [ebp-18h] BYREF
  float srcScale; // [esp+234h] [ebp-14h]
  DmeTime_t originalTime; // [esp+238h] [ebp-10h] BYREF
  float dstScale; // [esp+23Ch] [ebp-Ch]
  DmeTime_t timeOffset; // [esp+240h] [ebp-8h]
  DmeTime_t v42; // [esp+244h] [ebp-4h] BYREF

  v8 = (CDmeChannel *)pAttachChannel;
  if ( pAttachChannel != 0 )
    goto LABEL_12;
  v9 = "p";
  if ( controlType != CONTROL_TYPE_POSITION )
    v9 = "o";
  V_snprintf(pDest: szName, maxLen: 512, pFormat: "%s_%s", pName, v9);
  v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
          a3: szName,
          a4: pDstChannelsClip->m_fileId,
          a5: nullptr);
  v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
  v12 = v11;
  if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeChannel::m_classType) )
    v8 = (CDmeChannel *)((char *)&v12[-1] + 64);
  else
    v8 = nullptr;
  v13 = controlType != CONTROL_TYPE_POSITION
      ? CDmeGlobalFlexControllerOperator::GetGlobalIndex(this: pTransform)
      : CDmeTrack::GetClipCount(this: pTransform);
  CDmeChannel::SetOutput(this: v8, pAttribute: v13, index: 0);
  if ( v8 != nullptr )
  {
LABEL_12:
    v14 = pSrcChannelsClip;
    if ( pSrcChannelsClip != nullptr && pSrcChannelsClip != pDstChannelsClip )
    {
      pAttachChannel = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v8->CDmElement);
      v15 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
              this: &v14->m_Channels,
              value: (const DmElementHandle_t *)&pAttachChannel);
      if ( v15 != -1 )
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
          this: &v14->m_Channels,
          elem: v15);
    }
    if ( v8 != nullptr )
    {
      pAttachChannel = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v8->CDmElement);
      if ( CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
             this: &pDstChannelsClip->m_Channels,
             value: (const DmElementHandle_t *)&pAttachChannel) != -1 )
        goto LABEL_21;
      pAttachChannel = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v8->CDmElement);
    }
    else
    {
      pAttachChannel = -1;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &pDstChannelsClip->m_Channels,
      src: (const DmElementHandle_t *)&pAttachChannel);
LABEL_21:
    if ( controlType != CONTROL_TYPE_POSITION )
    {
      Orientation = CDmeTransform::GetOrientation(this: pTransform);
      v20 = pTransformControl;
      CDmeTransformControl::SetOrientation(this: pTransformControl, orientation: &Orientation->m_Storage);
      CDmeTransformControl::SetOrientationChannel(this: v20, pChannel: (int)v8);
      OrientationAttr = CDmeTransformControl::GetOrientationAttr(this: v20);
    }
    else
    {
      Bookmarks = CDmeBookmarkSet::GetBookmarks(this: pTransform);
      v17 = pTransformControl;
      CDmeTransformControl::SetPosition(this: pTransformControl, position: &Bookmarks->m_Storage);
      CDmeTransformControl::SetPositionChannel(this: v17, pChannel: (int)v8);
      OrientationAttr = CDmeTransformControl::GetPositionAttr(this: v17);
    }
    CDmeChannel::SetInput(this: v8, pAttribute: OrientationAttr, index: 0);
    CDmeChannel::SetMode(this: v8, mode: CM_PLAY);
    Log = CDmeChannel::GetLog(this: v8);
    v22 = (CDmeTypedLog<Quaternion> *)Log;
    if ( bUseExistingLogData )
    {
      if ( Log == nullptr )
        goto LABEL_35;
      if ( v14 != nullptr )
      {
        TimeFrame = CDmeClip::GetTimeFrame(this: &v14->CDmeClip);
        v24 = CDmeClip::GetTimeFrame(this: &pDstChannelsClip->CDmeClip);
        m_tms = TimeFrame->m_Start.m_Storage.m_tms;
        m_Storage = TimeFrame->m_Scale.m_Storage;
        v27 = TimeFrame->m_Offset.m_Storage.m_tms;
        v28 = v24->m_Start.m_Storage.m_tms;
        v29 = v24->m_Scale.m_Storage;
        v30 = v24->m_Offset.m_Storage.m_tms;
        srcScale = m_Storage;
        dstScale = v29;
        if ( m_tms != v28 || v27 != v30 || m_Storage != v29 )
        {
          timeOffset.m_tms = m_tms + v30 - v28 - v27;
          KeyCount = CDmeLog::GetKeyCount(this: v22);
          for ( i = 0; i < (int)KeyCount; ++i )
          {
            v22->GetKeyTime(this: v22, result: &originalTime, a3: i);
            pAttachChannel = originalTime.m_tms;
            DmeTime_t::operator/=(this: (DmeTime_t *)&pAttachChannel, &result, f: srcScale);
            v42.m_tms = timeOffset.m_tms + pAttachChannel;
            DmeTime_t::operator*=(this: &v42, result: &v36, f: dstScale);
            ((void (__thiscall *)(CDmeTypedLog<Quaternion> *, int, int))v22->SetKeyTime)(a1: v22, a2: i, a3: v42.m_tms);
          }
        }
        return;
      }
    }
    if ( Log != nullptr )
    {
      Log->ClearKeys(this: Log);
      goto LABEL_36;
    }
LABEL_35:
    v22 = CDmeChannel::CreateLog(this: v8, type: g_ChannelTypes[controlType]);
LABEL_36:
    if ( controlType != CONTROL_TYPE_POSITION )
    {
      v34 = CDmeTransform::GetOrientation(this: pTransform);
      CDmeTypedLog<Quaternion>::SetKey(
        this: v22,
        time: 0,
        value: &v34->m_Storage,
        interpSetting: SEGMENT_INTERPOLATE,
        curveType: 0);
    }
    else
    {
      v33 = CDmeBookmarkSet::GetBookmarks(this: pTransform);
      CDmeTypedLog<Vector>::SetKey(
        this: (CDmeTypedLog<Vector> *)v22,
        time: 0,
        value: &v33->m_Storage,
        interpSetting: SEGMENT_INTERPOLATE,
        curveType: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053A170
// Name: void LoadPresetGroups(class CDmeAnimationSet __near *,char const __near *,class CDmrElementArray<class CDmePresetGroupInfo> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadPresetGroups(
        CDmeAnimationSet *pAnimationSet,
        const char *pModelName,
        CDmrElementArray<CDmePresetGroupInfo> *presetGroupInfos)
{
  CDmaElementArray<CDmePresetGroup> *PresetGroups; // eax
  CDmePresetGroupInfo *PresetGroupInfo; // eax
  CDmePresetGroupInfo *v5; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  int v8; // esi
  char filenameBase[260]; // [esp+Ch] [ebp-104h] BYREF
  int nPresetGroups; // [esp+120h] [ebp+10h]

  CDmePresetGroupInfo::FilenameBaseForModelName(pModelName, pFileNameBase: filenameBase, nFileNameBaseLen: 260);
  if ( presetGroupInfos->m_pAttribute != nullptr )
  {
    PresetGroupInfo = CDmePresetGroupInfo::FindOrCreatePresetGroupInfo(pFilenameBase: filenameBase, presetGroupInfos);
    v5 = PresetGroupInfo;
    if ( PresetGroupInfo != nullptr )
    {
      v6 = 0;
      nPresetGroups = PresetGroupInfo->m_presetGroups.m_Storage.m_Size;
      if ( nPresetGroups > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_presetGroups.m_Storage.m_Memory.m_pMemory[v6]);
          v8 = (int)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmePresetGroup::m_classType) )
            CDmeAnimationSet::AddPresetGroup(this: pAnimationSet, pPresetGroup: v8);
          ++v6;
        }
        while ( v6 < nPresetGroups );
      }
    }
  }
  else
  {
    PresetGroups = CDmeAnimationSet::GetPresetGroups(this: pAnimationSet);
    CDmePresetGroupInfo::LoadPresetGroups(pFilenameBase: filenameBase, presetGroups: PresetGroups);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053A230
// Name: class CDmeChannel __near * MoveOrCreateChannel(class CDmeFilmClip __near *,class CDmeChannelsClip __near *,class CDmElement __near *,class CDmAttribute __near *,class CDmAttribute __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl MoveOrCreateChannel(
        CDmeFilmClip *pFilmClip,
        CDmeChannelsClip *pDstChannelsClip,
        CDmElement *pControl,
        CDmAttribute *pInputAttr,
        int pOutputAttr,
        const char *pChannelName)
{
  CDmAttribute *v6; // edi
  CUtlSymbolLarge::<unnamed_type_u> v7; // eax
  const char *m_Id; // ecx
  CDmeChannel *ChannelTargetingElement; // eax
  CDmeChannel *v10; // esi
  int v11; // eax
  CDmeTrack *ParentTrack; // ebx
  CDmeTrackGroup *ParentTrackGroup; // eax
  CDmeTrackGroup *v14; // edi
  CDmeFilmClip *ParentClip; // eax
  CDmeChannelsClip *v16; // ebx
  DmElementHandle_t v17; // eax
  CDmElement *v18; // eax
  CDmElement *v19; // esi
  CDmeTypedLog<Quaternion> *Log; // eax
  DmElementHandle_t value; // [esp+Ch] [ebp-8h] BYREF
  CDmeChannelsClip *pSrcChannelsClip; // [esp+10h] [ebp-4h] BYREF

  v6 = (CDmAttribute *)pOutputAttr;
  v7.m_Id = *(int *)(pOutputAttr + 20);
  pSrcChannelsClip = nullptr;
  m_Id = &pch;
  if ( v7.m_Id != -1 )
    m_Id = (const char *)v7.m_Id;
  ChannelTargetingElement = FindChannelTargetingElement(
                              pClip: pFilmClip,
                              pElement: *(CDmElement **)(pOutputAttr + 8),
                              pAttributeName: m_Id,
                              ppChannelsClip: &pSrcChannelsClip,
                              ppTrack: nullptr,
                              ppTrackGroup: nullptr);
  v10 = ChannelTargetingElement;
  if ( ChannelTargetingElement != nullptr )
  {
    value = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&ChannelTargetingElement->CDmElement);
    v11 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
            this: &pSrcChannelsClip->m_Channels,
            &value);
    if ( v11 != -1 )
    {
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
        this: &pSrcChannelsClip->m_Channels,
        elem: v11);
      if ( pSrcChannelsClip->m_Channels.m_Storage.m_Size == 0 )
      {
        ParentTrack = GetParentTrack(pClip: &pSrcChannelsClip->CDmeClip);
        if ( ParentTrack != nullptr )
        {
          CDmeTrack::RemoveClip(this: ParentTrack, clip: &pSrcChannelsClip->CDmeClip);
          if ( CDmeTrack::GetClipCount(this: (CDmeTransform *)ParentTrack) == nullptr )
          {
            ParentTrackGroup = GetParentTrackGroup(pTrack: ParentTrack);
            v14 = ParentTrackGroup;
            if ( ParentTrackGroup != nullptr )
            {
              CDmeTrackGroup::RemoveTrack(this: ParentTrackGroup, pTrack: ParentTrack);
              if ( v14->m_Tracks.m_Storage.m_Size == 0 )
              {
                ParentClip = GetParentClip(pTrackGroup: v14);
                if ( ParentClip != nullptr )
                  CDmeClip::RemoveTrackGroup(this: ParentClip, pTrackGroup: v14);
              }
            }
            v6 = (CDmAttribute *)pOutputAttr;
          }
        }
      }
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pOutputAttr, a3: pChannelName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: v10->m_Name.m_pAttribute,
      value: (const CUtlSymbolLarge *)&pOutputAttr);
    v16 = pDstChannelsClip;
  }
  else
  {
    v16 = pDstChannelsClip;
    v17 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
            a3: pChannelName,
            a4: pDstChannelsClip->m_fileId,
            a5: nullptr);
    v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: v17);
    v19 = v18;
    if ( v18 != nullptr && v18->IsA(this: v18, a2: CDmeChannel::m_classType) )
      v10 = (CDmeChannel *)((char *)&v19[-1] + 64);
    else
      v10 = nullptr;
  }
  if ( v10 != nullptr )
    pOutputAttr = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v10->CDmElement);
  else
    pOutputAttr = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &v16->m_Channels,
    src: (const DmElementHandle_t *)&pOutputAttr);
  CDmeChannel::SetInput(this: v10, pAttribute: pInputAttr, index: 0);
  CDmeChannel::SetOutput(this: v10, pAttribute: v6, index: 0);
  Log = (CDmeTypedLog<Quaternion> *)CDmeChannel::GetLog(this: v10);
  if ( Log == nullptr )
    Log = CDmeChannel::CreateLog(this: v10, type: (DmAttributeType_t)(v6->m_nFlags & 0x1F));
  if ( pSrcChannelsClip != nullptr )
    RetimeLogData(pSrcChannelsClip, pDstChannelsClip: v16, pLog: Log);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0053A400
// Name: void AddFloatControlToAnimationSet(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeChannelsClip __near *,class CDmeControlGroup __near *,class CDmAttribute __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddFloatControlToAnimationSet(
        CDmeFilmClip *pFilmClip,
        CDmeAnimationSet *pAnimSet,
        CDmeChannelsClip *pDstChannelsClip,
        CUtlSymbolLarge::<unnamed_type_u> pControlGroup,
        int pSrcAttr,
        float flMin,
        float flMax,
        float flDefault)
{
  CDmeControlGroup *m_Id; // esi
  CDmAttribute *v9; // edi
  const char *v10; // eax
  CDmElement *v11; // eax
  const char *m_pAsString; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v17; // eax
  CDmeChannel *Channel; // ebx
  CDmAttribute *v19; // eax
  float *v20; // eax
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  CDmeExpressionOperator *v24; // esi
  CDmElement *v25; // edi
  CDmAttribute *v26; // eax
  CDmAttribute *v27; // eax
  CDmAttribute *v28; // eax
  CDmAttribute *v29; // eax
  const char *v30; // ebx
  CDmAttribute *v31; // eax
  CDmAttribute *v32; // eax
  char channame[256]; // [esp+1Ch] [ebp-20Ch] BYREF
  char exprname[256]; // [esp+11Ch] [ebp-10Ch] BYREF
  CDmElement *pTarget; // [esp+21Ch] [ebp-Ch]
  CDmElement *pControl; // [esp+220h] [ebp-8h]
  float flValue; // [esp+224h] [ebp-4h] BYREF

  m_Id = (CDmeControlGroup *)pControlGroup.m_Id;
  v9 = (CDmAttribute *)pSrcAttr;
  if ( pControlGroup.m_Id != 0 )
  {
    v10 = *(const char **)(pSrcAttr + 20);
    if ( v10 == (const char *)-1 )
      v10 = &pch;
    v11 = CDmeAnimationSet::FindOrAddControl(
            this: pAnimSet,
            pControlName: v10,
            transformControl: false,
            bMustBeNew: false);
    CDmeControlGroup::AddControl(this: m_Id, pControl: v11, pInsertBeforeControl: nullptr);
  }
  if ( (v9->m_nFlags & 0x1F) == 3 )
  {
    m_pAsString = v9->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
    {
      v13 = &pch;
      pControlGroup.m_Id = (int)&pch;
    }
    else
    {
      pControlGroup.m_Id = (int)v9->m_Name.u;
      v13 = m_pAsString;
    }
    v14 = CDmeAnimationSet::FindOrAddControl(
            this: pAnimSet,
            pControlName: v13,
            transformControl: false,
            bMustBeNew: false);
    v15 = v14;
    pControl = v14;
    if ( v14 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v14, pAttributeName: "value");
      v17 = Attribute != nullptr
          ? ((Attribute->m_nFlags & 0x1F) != 3
           ? nullptr
           : Attribute)
          : CDmElement::CreateAttribute(this: v15, pAttributeName: "value", type: AT_FLOAT);
      if ( v17 != nullptr )
      {
        pTarget = v9->m_pOwner;
        Channel = MoveOrCreateChannel(
                    pFilmClip,
                    pDstChannelsClip,
                    pControl: v15,
                    pInputAttr: v17,
                    pOutputAttr: (int)v9,
                    pChannelName: v13);
        CDmeChannel::SetMode(this: Channel, mode: CM_PLAY);
        if ( Channel != nullptr )
          pSrcAttr = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&Channel->CDmElement);
        else
          pSrcAttr = -1;
        v19 = CDmElement::FindAttribute(this: v15, pAttributeName: "channel");
        if ( v19 != nullptr
          || (v19 = CDmElement::CreateAttribute(this: v15, pAttributeName: "channel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
        {
          CDmAttribute::SetValue<enum DmElementHandle_t>(this: v19, value: (DmElementHandle_t *)&pSrcAttr);
        }
        v20 = (float *)CDmAttribute::GetValue<float>(this: v9);
        v21 = flMin;
        flValue = *v20;
        if ( flMin > flValue )
        {
          v21 = flValue;
          flMin = flValue;
        }
        v22 = flMax;
        if ( flValue > flMax )
        {
          v22 = flValue;
          flMax = flValue;
        }
        if ( v21 != 0.0 || v22 != 1.0 )
        {
          v23 = v22 - v21;
          flValue = (float)(flValue - v21) / v23;
          flDefault = (float)(flDefault - v21) / v23;
          V_snprintf(pDest: exprname, maxLen: 256, pFormat: "%s_rescale", pControlGroup.m_pAsString);
          v24 = CreateElement<CDmeExpressionOperator>(
                  pObjectName: exprname,
                  fileid: pAnimSet->m_fileId,
                  pObjectID: nullptr);
          CDmeAnimationSet::AddOperator(this: pAnimSet, pOperator: (int)v24);
          v25 = &v24->CDmElement;
          g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pSrcAttr, a3: "lerp(value, lo, hi)");
          v26 = CDmElement::FindAttribute(this: &v24->CDmElement, pAttributeName: "expr");
          if ( v26 != nullptr
            || (v26 = CDmElement::CreateAttribute(this: &v24->CDmElement, pAttributeName: "expr", type: AT_STRING)) != nullptr )
          {
            CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: (const CUtlSymbolLarge *)&pSrcAttr);
          }
          pSrcAttr = 0;
          v27 = CDmElement::FindAttribute(this: &v24->CDmElement, pAttributeName: "value");
          if ( v27 != nullptr
            || (v27 = CDmElement::CreateAttribute(this: &v24->CDmElement, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v27, value: (const float *)&pSrcAttr);
          }
          v28 = CDmElement::FindAttribute(this: &v24->CDmElement, pAttributeName: "lo");
          if ( v28 != nullptr
            || (v28 = CDmElement::CreateAttribute(this: &v24->CDmElement, pAttributeName: "lo", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v28, value: &flMin);
          }
          v29 = CDmElement::FindAttribute(this: &v24->CDmElement, pAttributeName: "hi");
          if ( v29 != nullptr
            || (v29 = CDmElement::CreateAttribute(this: &v24->CDmElement, pAttributeName: "hi", type: AT_FLOAT)) != nullptr )
          {
            CDmAttribute::SetValue<float>(this: v29, value: &flMax);
          }
          CDmeChannel::SetOutput(
            this: Channel,
            pElement: v24 != nullptr ? (unsigned int)v25 : 0,
            pAttribute: "value",
            index: 0);
          RemapFloatLogValues(
            pChannel: *(float *)&Channel,
            flBias: COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(1.0 / (float)(flMax - flMin)) * flMin) ^ _mask__NegFloat_),
            flScale: 1.0 / (float)(flMax - flMin));
          v30 = (const char *)pControlGroup.m_Id;
          V_snprintf(pDest: channame, maxLen: 256, pFormat: "scaled_%s_channel", pControlGroup.m_pAsString);
          CDmeChannelsClip::CreatePassThruConnection(
            this: pDstChannelsClip,
            passThruName: channame,
            pFrom: v24 != nullptr ? v25 : nullptr,
            pFromAttribute: "result",
            pTo: pTarget,
            pToAttribute: v30,
            index: 0);
          v15 = pControl;
        }
        v31 = CDmElement::FindAttribute(this: v15, pAttributeName: "value");
        if ( v31 != nullptr
          || (v31 = CDmElement::CreateAttribute(this: v15, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v31, value: &flValue);
        }
        if ( flDefault >= 0.0 )
        {
          if ( flDefault <= 1.0 )
            pControlGroup.m_Id = (int)LODWORD(flDefault);
          else
            pControlGroup.m_Id = 1065353216;
        }
        else
        {
          pControlGroup.m_Id = 0;
        }
        v32 = CDmElement::FindAttribute(this: v15, pAttributeName: "defaultValue");
        if ( v32 != nullptr
          || (v32 = CDmElement::CreateAttribute(this: v15, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v32, value: (const float *)&pControlGroup.m_Id);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053A7D0
// Name: void AddTransformControlsToAnimationSet(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeChannelsClip __near *,class CDmeControlGroup __near *,class CDmeTransform __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddTransformControlsToAnimationSet(
        CDmeFilmClip *pFilmClip,
        CDmeAnimationSet *pAnimSet,
        CDmeChannelsClip *pDstChannelsClip,
        CDmeControlGroup *pControlGroup,
        CDmeTransform *pTransform,
        const char *pControlName)
{
  CDmElement *v6; // eax
  CDmeTransformControl *v7; // ebx
  int i; // edi
  CDmeChannel *Channel; // esi
  CDmeLog *v10; // eax
  CDmeTypedLog<Vector> *v11; // esi
  CDmaVar<Vector> *Bookmarks; // eax
  CDmeLog *Log; // eax
  CDmeTypedLog<Quaternion> *v14; // esi
  CDmaVar<Quaternion> *Orientation; // eax
  CDmaVar<Vector> *v16; // eax
  CDmaVar<Quaternion> *v17; // eax
  char channelName[256]; // [esp+Ch] [ebp-110h] BYREF
  CDmAttribute *pOutputAttr[2]; // [esp+10Ch] [ebp-10h]
  CDmAttribute *pInputAttr[2]; // [esp+114h] [ebp-8h]

  v6 = CDmeAnimationSet::FindOrAddControl(this: pAnimSet, pControlName, transformControl: true, bMustBeNew: false);
  v7 = (CDmeTransformControl *)v6;
  if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeTransformControl::m_classType) )
  {
    pInputAttr[0] = CDmeTransformControl::GetPositionAttr(this: v7);
    pInputAttr[1] = CDmeTransformControl::GetOrientationAttr(this: v7);
    pOutputAttr[0] = CDmeTrack::GetClipCount(this: pTransform);
    pOutputAttr[1] = CDmeGlobalFlexControllerOperator::GetGlobalIndex(this: pTransform);
    for ( i = 0; i < 2; ++i )
    {
      V_snprintf(pDest: channelName, maxLen: 256, pFormat: "%s_%s", pControlName, g_pSuffix[i]);
      Channel = MoveOrCreateChannel(
                  pFilmClip,
                  pDstChannelsClip,
                  pControl: v7,
                  pInputAttr: pInputAttr[i],
                  pOutputAttr: (int)pOutputAttr[i],
                  pChannelName: channelName);
      CDmeChannel::SetMode(this: Channel, mode: CM_PLAY);
      if ( i != 0 )
      {
        CDmeTransformControl::SetOrientationChannel(this: v7, pChannel: (int)Channel);
        Log = CDmeChannel::GetLog(this: Channel);
        v14 = (CDmeTypedLog<Quaternion> *)Log;
        if ( Log != nullptr
          && Log->IsA(this: Log, a2: CDmeTypedLog<Quaternion>::m_classType)
          && CDmeLog::GetKeyCount(this: v14) == nullptr )
        {
          Orientation = CDmeTransform::GetOrientation(this: pTransform);
          CDmeTypedLog<Quaternion>::SetDefaultValue(this: v14, value: &Orientation->m_Storage);
        }
      }
      else
      {
        CDmeTransformControl::SetPositionChannel(this: v7, pChannel: (int)Channel);
        v10 = CDmeChannel::GetLog(this: Channel);
        v11 = (CDmeTypedLog<Vector> *)v10;
        if ( v10 != nullptr
          && v10->IsA(this: v10, a2: CDmeTypedLog<Vector>::m_classType)
          && CDmeLog::GetKeyCount(this: v11) == nullptr )
        {
          Bookmarks = CDmeBookmarkSet::GetBookmarks(this: pTransform);
          CDmeTypedLog<Vector>::SetDefaultValue(this: v11, value: &Bookmarks->m_Storage);
        }
      }
    }
    v16 = CDmeBookmarkSet::GetBookmarks(this: pTransform);
    CDmeTransformControl::SetPosition(this: v7, position: &v16->m_Storage);
    v17 = CDmeTransform::GetOrientation(this: pTransform);
    CDmeTransformControl::SetOrientation(this: v7, orientation: &v17->m_Storage);
    if ( pControlGroup != nullptr )
      CDmeControlGroup::AddControl(this: pControlGroup, pControl: v7, pInsertBeforeControl: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053A970
// Name: void AddLocalViewTargetControl(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddLocalViewTargetControl(
        CDmeFilmClip *pFilmClip,
        CDmeAnimationSet *pAnimSet,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip)
{
  CDmeControlGroup *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax

  v4 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimSet, pParentGroup: nullptr, pControlGroupName: "Eyes");
  Attribute = CDmElement::FindAttribute(this: pGameModel, pAttributeName: "localViewTargetFactor");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 3 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: pGameModel, pAttributeName: "localViewTargetFactor", type: AT_FLOAT);
  AddFloatControlToAnimationSet(
    pFilmClip,
    pAnimSet,
    pDstChannelsClip: pChannelsClip,
    pControlGroup: (CUtlSymbolLarge::<unnamed_type_u>)v4,
    pSrcAttr: (int)v6,
    flMin: 0.0,
    flMax: 1.0,
    flDefault: -3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0053AA00
// Name: void AddEyeConvergenceControl(class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddEyeConvergenceControl(
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip)
{
  CDmeControlGroup *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // eax
  CDmeExpressionOperator *v9; // edi
  CDmElement *v10; // ebx
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmeChannel *v15; // esi
  CDmElement *v16; // esi
  CDmAttribute *v17; // eax
  float flMaxValue; // [esp+4h] [ebp-14h] BYREF
  float flMinValue; // [esp+8h] [ebp-10h] BYREF
  CDmElement *pControl; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+10h] [ebp-8h] BYREF
  float flDefaultValue; // [esp+14h] [ebp-4h] BYREF

  if ( CDmeAnimationSet::FindControl(this: pAnimationSet, pControlName: "eyes_updown") != nullptr
    || CDmeAnimationSet::FindControl(this: pAnimationSet, pControlName: "eyes_rightleft") != nullptr )
  {
    if ( CDmElement::FindAttribute(this: pGameModel, pAttributeName: "eyes_convergence") == nullptr )
      CDmElement::CreateAttribute(this: pGameModel, pAttributeName: "eyes_convergence", type: AT_FLOAT);
    v3 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimationSet, pParentGroup: nullptr, pControlGroupName: "Eyes");
    if ( v3 != nullptr )
    {
      v4 = CDmeAnimationSet::FindOrAddControl(
             this: pAnimationSet,
             pControlName: "eyes_convergence",
             transformControl: false,
             bMustBeNew: false);
      CDmeControlGroup::AddControl(this: v3, pControl: v4, pInsertBeforeControl: nullptr);
    }
    flMinValue = -45.0;
    flMaxValue = 45.0;
    flDefaultValue = 0.5;
    v5 = CDmeAnimationSet::FindOrAddControl(
           this: pAnimationSet,
           pControlName: "eyes_convergence",
           transformControl: false,
           bMustBeNew: false);
    v6 = v5;
    pControl = v5;
    if ( v5 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "value");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: Attribute, value: &flDefaultValue);
      }
      v8 = CDmElement::FindAttribute(this: v6, pAttributeName: "defaultValue");
      if ( v8 != nullptr
        || (v8 = CDmElement::CreateAttribute(this: v6, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v8, value: &flDefaultValue);
      }
      v9 = CreateElement<CDmeExpressionOperator>(
             pObjectName: "eye_convergence_rescale",
             fileid: pAnimationSet->m_fileId,
             pObjectID: nullptr);
      v10 = &v9->CDmElement;
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "lerp(value, lo, hi)");
      v11 = CDmElement::FindAttribute(this: &v9->CDmElement, pAttributeName: "expr");
      if ( v11 != nullptr
        || (v11 = CDmElement::CreateAttribute(this: &v9->CDmElement, pAttributeName: "expr", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
      }
      value.u.m_Id = 0;
      v12 = CDmElement::FindAttribute(this: &v9->CDmElement, pAttributeName: "value");
      if ( v12 != nullptr
        || (v12 = CDmElement::CreateAttribute(this: &v9->CDmElement, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v12, value: (const float *)&value.u.m_Id);
      }
      v13 = CDmElement::FindAttribute(this: &v9->CDmElement, pAttributeName: "lo");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: &v9->CDmElement, pAttributeName: "lo", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v13, value: &flMinValue);
      }
      v14 = CDmElement::FindAttribute(this: &v9->CDmElement, pAttributeName: "hi");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: &v9->CDmElement, pAttributeName: "hi", type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v14, value: &flMaxValue);
      }
      CDmeAnimationSet::AddOperator(this: pAnimationSet, pOperator: (int)v9);
      v15 = CreateElement<CDmeChannel>(
              pObjectName: "eye_convergence_channel",
              fileid: pChannelsClip->m_fileId,
              pObjectID: nullptr);
      CDmeChannel::SetInput(this: v15, pElement: (int)pControl, pAttribute: "value", index: 0);
      CDmeChannel::SetOutput(this: v15, pElement: v9 != nullptr ? (unsigned int)v10 : 0, pAttribute: "value", index: 0);
      CDmeChannel::SetMode(this: v15, mode: CM_PLAY);
      if ( v15 != nullptr )
        value.u.m_Id = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v15->CDmElement);
      else
        value.u.m_Id = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &pChannelsClip->m_Channels,
        src: (const DmElementHandle_t *)&value);
      if ( v15 != nullptr )
        value.u.m_Id = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)&v15->CDmElement);
      else
        value.u.m_Id = -1;
      v16 = pControl;
      v17 = CDmElement::FindAttribute(this: pControl, pAttributeName: "channel");
      if ( v17 != nullptr
        || (v17 = CDmElement::CreateAttribute(this: v16, pAttributeName: "channel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v17, (DmElementHandle_t *)&value);
      }
      CDmeChannelsClip::CreatePassThruConnection(
        this: pChannelsClip,
        passThruName: "scaled_eye_convergence_channel",
        pFrom: v9 != nullptr ? v10 : nullptr,
        pFromAttribute: "result",
        pTo: pGameModel,
        pToAttribute: "eyes_convergence",
        index: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053AD00
// Name: void AddViewTargetControl(class CDmeFilmClip __near *,class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddViewTargetControl(
        CDmeFilmClip *pFilmClip,
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        CDmeChannelsClip *pChannelsClip)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi
  CDmaVar<enum DmElementHandle_t> *v6; // eax
  CDmElement *v7; // eax
  CDmeDag *v8; // edi
  CExpressionCalculator *v9; // eax
  CDmeTransform *Transform; // esi
  CExpressionCalculator *v11; // eax
  CDmAttribute *v12; // eax
  Vector vecPosition; // [esp+Ch] [ebp-18h] BYREF
  CDmeControlGroup *pGroup; // [esp+18h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+1Ch] [ebp-8h] BYREF
  bool bViewTargetInvalid; // [esp+23h] [ebp-1h]

  if ( CDmeAnimationSet::FindControl(this: pAnimationSet, pControlName: "eyes_updown") != nullptr
    || CDmeAnimationSet::FindControl(this: pAnimationSet, pControlName: "eyes_rightleft") != nullptr )
  {
    pGroup = CDmeAnimationSet::FindOrAddControlGroup(
               this: pAnimationSet,
               pParentGroup: nullptr,
               pControlGroupName: "Eyes");
    bViewTargetInvalid = false;
    Attribute = CDmElement::FindAttribute(this: pGameModel, pAttributeName: "viewTargetDag");
    if ( Attribute != nullptr )
      v5 = (unsigned __int8)((Attribute->m_nFlags & 0x1F) - 1) == 0 ? Attribute : nullptr;
    else
      v5 = CDmElement::CreateAttribute(this: pGameModel, pAttributeName: "viewTargetDag", type: AT_FIRST_VALUE_TYPE);
    if ( v5 != nullptr )
      CDmAttribute::SetElementTypeSymbol(this: v5, typeSymbol: CDmeDag::m_classType);
    if ( (v5->m_nFlags & 0x1F) != 1 )
      goto LABEL_13;
    v6 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v5);
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6->m_Storage.m_Handle);
    v8 = (CDmeDag *)v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeDag::m_classType) )
      v8 = nullptr;
    if ( v8 == nullptr )
    {
LABEL_13:
      v9 = (CExpressionCalculator *)CreateElement<CDmeDag>(
                                      pObjectName: "viewTarget",
                                      fileid: pGameModel->m_fileId,
                                      pObjectID: nullptr);
      v8 = (CDmeDag *)v9;
      if ( (v5->m_nFlags & 0x1F) == 1 )
      {
        if ( v9 != nullptr )
          value.u.m_Id = CExpressionCalculator::VariableCount(this: v9);
        else
          value.u.m_Id = -1;
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, (DmElementHandle_t *)&value);
      }
      bViewTargetInvalid = true;
    }
    if ( CDmeDag::FindChild(this: pGameModel, pChild: (CExpressionCalculator *)v8) < 0 )
      CDmeDag::AddChild(this: pGameModel, pDag: v8);
    Transform = CDmeDag::GetTransform(this: v8);
    if ( Transform != nullptr )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "viewTarget");
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Transform->m_Name.m_pAttribute, &value);
      if ( !bViewTargetInvalid )
      {
LABEL_30:
        AddTransformControlsToAnimationSet(
          pFilmClip,
          pAnimSet: pAnimationSet,
          pDstChannelsClip: pChannelsClip,
          pControlGroup: pGroup,
          pTransform: Transform,
          pControlName: "viewTarget");
        return;
      }
    }
    else
    {
      v11 = (CExpressionCalculator *)CreateElement<CDmeTransform>(
                                       pObjectName: "viewTarget",
                                       fileid: pGameModel->m_fileId,
                                       pObjectID: nullptr);
      Transform = (CDmeTransform *)v11;
      if ( v11 != nullptr )
        value.u.m_Id = CExpressionCalculator::VariableCount(this: v11);
      else
        value.u.m_Id = -1;
      v12 = CDmElement::FindAttribute(this: v8, pAttributeName: "transform");
      if ( v12 != nullptr
        || (v12 = CDmElement::CreateAttribute(this: v8, pAttributeName: "transform", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v12, (DmElementHandle_t *)&value);
      }
    }
    vecPosition.x = 32.0;
    vecPosition.y = 0.0;
    vecPosition.z = 64.0;
    CDmeTransform::SetPosition(this: Transform, &vecPosition);
    goto LABEL_30;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053B9C0
// Name: class CDmeControlGroup __near * FindOrAddGroupForTransformControl(class CDmElement __near *,class CDmeAnimationSet __near *,class Color const __near &,class CUtlDict<class CUtlString,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl FindOrAddGroupForTransformControl(
        CDmElement *pControl,
        CDmeAnimationSet *pAnimationSet,
        const Color *groupColor,
        const CUtlDict<CUtlString,int> *defaultGroupMapping)
{
  const char *m_pAsString; // esi
  const char *v5; // edi
  int v6; // esi
  CDmeControlGroup *result; // eax
  CDmeControlGroup *v8; // esi
  CUtlMap<char const *,CUtlString,int>::Node_t search; // [esp+8h] [ebp-14h] BYREF

  m_pAsString = pControl->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pch;
  v5 = "Root";
  if ( m_pAsString != nullptr )
  {
    CUtlString::CUtlString(this: &search.elem);
    search.key = m_pAsString;
    v6 = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::Find(
           this: &defaultGroupMapping->m_Elements.m_Tree,
           &search);
    search.elem.m_Storage.m_nActualLength = 0;
    if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
        search.elem.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      search.elem.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    if ( v6 != -1 )
      v5 = CUtlString::operator char const *(this: &defaultGroupMapping->m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem);
  }
  result = (CDmeControlGroup *)_V_stricmp(s1: v5, s2: "IGNORE");
  if ( result != nullptr )
  {
    v8 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimationSet, pParentGroup: nullptr, pControlGroupName: v5);
    if ( v8 != nullptr )
      CDmeControlGroup::SetGroupColor(this: v8, groupColor, bRecursive: false);
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0053BA90
// Name: bool AddConstraintControlToGroup(class CDmElement __near *,class CDmeAnimationSet __near *,class Color const __near &,class CUtlDict<class CUtlString,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddConstraintControlToGroup(
        CDmElement *pControl,
        CDmeAnimationSet *pAnimationSet,
        const Color *groupColor,
        const CUtlDict<CUtlString,int> *defaultGroupMapping)
{
  CDmeChannel *Value; // eax
  CDmElement *v5; // eax
  CExpressionCalculator *v6; // esi
  CDmeRigBaseConstraintOperator *Referring; // eax
  CDmeDag *v8; // eax
  CDmeTransformControl *TransformControl; // eax
  CDmeControlGroup *v10; // eax

  if ( !CDmElement::HasAttribute(this: pControl, pAttributeName: "channel", type: AT_UNKNOWN) )
    return 0;
  Value = CDmElement::GetValueElement<CDmeChannel>(this: pControl, pAttributeName: "channel");
  if ( Value == nullptr )
    return 0;
  v5 = CDmeChannel::GetToElement(this: Value);
  v6 = (CExpressionCalculator *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeConstraintTarget::m_classType) )
    v6 = nullptr;
  Referring = FindReferringElement<CDmeRigBaseConstraintOperator>(
                pElement: v6,
                symAttrName: (CUtlSymbolLarge)-1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  v8 = (CDmeDag *)Referring->GetSlave(this: Referring);
  if ( v8 == nullptr )
    return 0;
  TransformControl = CDmeDag::FindTransformControl(this: v8);
  if ( TransformControl == nullptr )
    return 0;
  v10 = FindOrAddGroupForTransformControl(pControl: TransformControl, pAnimationSet, groupColor, defaultGroupMapping);
  if ( v10 == nullptr )
    return 0;
  CDmeControlGroup::AddControl(this: v10, pControl, pInsertBeforeControl: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0053BBC0
// Name: class CDmeChannel __near * FindChannelTargetingTransform(class CDmeChannelsClip __near *,class CDmeTransform __near *,enum ControlType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__cdecl FindChannelTargetingTransform(
        CDmeChannelsClip *pChannelsClip,
        CDmeTransform *pTransform,
        ControlType_t controlType)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int m_Size; // edi
  int v5; // esi
  CDmeChannel *v6; // edi
  int v7; // eax
  CDmeDag *v8; // esi
  CDmElement *v9; // eax
  CDmeTransform *v10; // esi
  CDmeTransform *v11; // ebx
  CDmAttribute *v12; // esi
  CDmeChannel **v13; // eax
  CDmAttribute *v15; // esi
  CDmeDag *v16; // eax
  CDmeTransform *Transform; // eax
  CDmAttribute *v18; // eax
  bool v19; // zf
  CDmAttribute *v20; // eax
  CDmeChannel **m_pMemory; // eax
  CDmeChannel **v22; // eax
  CUtlVector<CDmeDag *,CUtlMemory<CDmeDag *,int> > dagList; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<CDmeChannelsClip *,CUtlMemory<CDmeChannelsClip *,int> > channelClips; // [esp+20h] [ebp-30h] BYREF
  CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > channelsList; // [esp+34h] [ebp-1Ch] BYREF
  int nNumChannels; // [esp+48h] [ebp-8h]
  int iChannel; // [esp+4Ch] [ebp-4h]

  channelsList.m_Memory.m_pMemory = nullptr;
  channelsList.m_Memory.m_nAllocationCount = 8;
  channelsList.m_Memory.m_nGrowSize = 0;
  channelsList.m_Memory.m_pMemory = (CDmeChannel **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  channelsList.m_pElements = channelsList.m_Memory.m_pMemory;
  channelsList.m_Size = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  dagList.m_Memory.m_nAllocationCount = 8;
  dagList.m_Memory.m_nGrowSize = 0;
  dagList.m_Memory.m_pMemory = (CDmeDag **)Alloc_2(this: _g_pMemAlloc, a2: 32u);
  dagList.m_pElements = dagList.m_Memory.m_pMemory;
  dagList.m_Size = 0;
  FindReferringElements<CDmeDag>(
    list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&dagList,
    pElement: (CExpressionCalculator *)pTransform,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  m_Size = dagList.m_Size;
  v5 = 0;
  if ( dagList.m_Size <= 0 )
    goto LABEL_4;
  while ( CDmeDag::GetTransform(this: dagList.m_Memory.m_pMemory[v5]) != pTransform )
  {
    if ( ++v5 >= m_Size )
      goto LABEL_4;
  }
  v8 = dagList.m_Memory.m_pMemory[v5];
  if ( v8 != nullptr )
    CDmeDag::FindTransformChannels(
      this: v8,
      channelList: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelsList);
  else
LABEL_4:
    FindReferringElements<CDmeChannel>(
      list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelsList,
      pElement: (CExpressionCalculator *)pTransform,
      symAttrName: (CUtlSymbolLarge)-1,
      bMustBeInSameFile: false,
      depth: TD_ALL);
  nNumChannels = channelsList.m_Size;
  iChannel = 0;
  if ( channelsList.m_Size <= 0 )
  {
LABEL_61:
    if ( dagList.m_Memory.m_nGrowSize >= 0 && dagList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dagList.m_Memory.m_pMemory);
    m_pMemory = channelsList.m_Memory.m_pMemory;
    channelsList.m_Size = 0;
    if ( channelsList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( channelsList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelsList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        channelsList.m_Memory.m_pMemory = nullptr;
      }
      channelsList.m_Memory.m_nAllocationCount = 0;
    }
    channelsList.m_pElements = m_pMemory;
    if ( channelsList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return nullptr;
  }
  while ( 1 )
  {
    v6 = channelsList.m_Memory.m_pMemory[iChannel];
    if ( v6 != nullptr )
      break;
LABEL_60:
    if ( ++iChannel >= nNumChannels )
      goto LABEL_61;
  }
  memset(&channelClips, 0, sizeof(channelClips));
  FindReferringElements<CDmeChannelsClip>(
    list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelClips,
    pElement: (CExpressionCalculator *)&v6->CDmElement,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  v7 = 0;
  if ( channelClips.m_Size <= 0 )
  {
LABEL_10:
    if ( channelClips.m_Memory.m_nGrowSize < 0 || channelClips.m_Memory.m_pMemory == nullptr )
      goto LABEL_60;
    goto LABEL_59;
  }
  while ( channelClips.m_Memory.m_pMemory[v7] != pChannelsClip )
  {
    if ( ++v7 >= channelClips.m_Size )
      goto LABEL_10;
  }
  v9 = CDmeChannel::GetToElement(this: v6);
  v10 = (CDmeTransform *)v9;
  if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeConstraintSlave::m_classType) )
    v11 = v10;
  else
    v11 = nullptr;
  if ( v10 == pTransform )
  {
    if ( controlType != CONTROL_TYPE_POSITION )
    {
      if ( controlType == CONTROL_TYPE_ORIENTATION )
      {
        v15 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
        if ( v15 == nullptr )
          v15 = CDmeChannel::SetupToAttribute(this: v6);
        if ( v15 == CDmeGlobalFlexControllerOperator::GetGlobalIndex(this: pTransform) )
        {
LABEL_24:
          if ( channelClips.m_Memory.m_nGrowSize >= 0 && channelClips.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelClips.m_Memory.m_pMemory);
          if ( dagList.m_Memory.m_nGrowSize >= 0 && dagList.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dagList.m_Memory.m_pMemory);
          v13 = channelsList.m_Memory.m_pMemory;
          channelsList.m_Size = 0;
          if ( channelsList.m_Memory.m_nGrowSize >= 0 )
          {
            if ( channelsList.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelsList.m_Memory.m_pMemory);
              v13 = nullptr;
              channelsList.m_Memory.m_pMemory = nullptr;
            }
            channelsList.m_Memory.m_nAllocationCount = 0;
          }
          channelsList.m_pElements = v13;
          if ( channelsList.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
          return v6;
        }
      }
    }
    else
    {
      v12 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
      if ( v12 == nullptr )
        v12 = CDmeChannel::SetupToAttribute(this: v6);
      if ( v12 == CDmeTrack::GetClipCount(this: pTransform) )
        goto LABEL_24;
    }
LABEL_57:
    if ( channelClips.m_Memory.m_nGrowSize < 0 || channelClips.m_Memory.m_pMemory == nullptr )
      goto LABEL_60;
LABEL_59:
    ((void (__stdcall *)(CDmeChannelsClip **))_g_pMemAlloc->Free_2)(a1: channelClips.m_Memory.m_pMemory);
    goto LABEL_60;
  }
  if ( v11 == nullptr )
    goto LABEL_57;
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: LODWORD(v11->m_Position.m_Storage.x)) != nullptr )
  {
    v16 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: LODWORD(v11->m_Position.m_Storage.x));
    Transform = CDmeDag::GetTransform(this: v16);
  }
  else
  {
    Transform = nullptr;
  }
  if ( Transform != pTransform )
    goto LABEL_57;
  if ( controlType != CONTROL_TYPE_POSITION )
  {
    if ( controlType != CONTROL_TYPE_ORIENTATION )
      goto LABEL_57;
    v20 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
    if ( v20 == nullptr )
      v20 = CDmeChannel::SetupToAttribute(this: v6);
    v19 = v20 == *(CDmAttribute **)&v11[1].m_Id.m_Value[4];
  }
  else
  {
    v18 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: v6->m_ToAttributeHandle);
    if ( v18 == nullptr )
      v18 = CDmeChannel::SetupToAttribute(this: v6);
    v19 = v18 == (CDmAttribute *)LODWORD(v11->m_Orientation.m_Storage.z);
  }
  if ( !v19 )
    goto LABEL_57;
  if ( channelClips.m_Memory.m_nGrowSize >= 0 && channelClips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelClips.m_Memory.m_pMemory);
  if ( dagList.m_Memory.m_nGrowSize >= 0 && dagList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dagList.m_Memory.m_pMemory);
  v22 = channelsList.m_Memory.m_pMemory;
  channelsList.m_Size = 0;
  if ( channelsList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( channelsList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelsList.m_Memory.m_pMemory);
      v22 = nullptr;
      channelsList.m_Memory.m_pMemory = nullptr;
    }
    channelsList.m_Memory.m_nAllocationCount = 0;
  }
  channelsList.m_pElements = v22;
  if ( channelsList.m_Memory.m_nGrowSize < 0 || v22 == nullptr )
    return v6;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0053C030
// Name: void CreateTransformChannels(class CDmeTransform __near *,char const __near *,class CDmeChannelsClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateTransformChannels(CDmeTransform *pTransform, const char *pBaseName, CDmeChannelsClip *pChannelsClip)
{
  CDmeChannel *ChannelTargetingTransform; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  char *v7; // esi
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  char *v11; // esi
  char name[256]; // [esp+Ch] [ebp-108h] BYREF
  CDmeChannel *pOrientationChannel; // [esp+10Ch] [ebp-8h]
  DmElementHandle_t src; // [esp+110h] [ebp-4h] BYREF

  ChannelTargetingTransform = FindChannelTargetingTransform(
                                pChannelsClip,
                                pTransform,
                                controlType: CONTROL_TYPE_POSITION);
  pOrientationChannel = FindChannelTargetingTransform(pChannelsClip, pTransform, controlType: CONTROL_TYPE_ORIENTATION);
  if ( ChannelTargetingTransform == nullptr )
  {
    V_snprintf(pDest: name, maxLen: 256, pFormat: "%s_p", pBaseName);
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
           a3: name,
           a4: pChannelsClip->m_fileId,
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    v6 = v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeChannel::m_classType) )
      v7 = (char *)&v6[-1] + 64;
    else
      v7 = nullptr;
    CDmeChannel::SetMode(this: (CDmeChannel *)v7, mode: CM_PLAY);
    CDmeChannel::CreateLog(this: (CDmeChannel *)v7, type: AT_VECTOR3);
    CDmeChannel::SetOutput(this: (CDmeChannel *)v7, pElement: (int)pTransform, pAttribute: "position", index: 0);
    if ( v7 != nullptr )
      src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v7 + 4));
    else
      src = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &pChannelsClip->m_Channels,
      &src);
  }
  if ( pOrientationChannel == nullptr )
  {
    V_snprintf(pDest: name, maxLen: 256, pFormat: "%s_o", pBaseName);
    v8 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeChannel::m_classType.u.m_Id,
           a3: name,
           a4: pChannelsClip->m_fileId,
           a5: nullptr);
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
    v10 = v9;
    if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeChannel::m_classType) )
      v11 = (char *)&v10[-1] + 64;
    else
      v11 = nullptr;
    CDmeChannel::SetMode(this: (CDmeChannel *)v11, mode: CM_PLAY);
    CDmeChannel::CreateLog(this: (CDmeChannel *)v11, type: AT_QUATERNION);
    CDmeChannel::SetOutput(this: (CDmeChannel *)v11, pElement: (int)pTransform, pAttribute: "orientation", index: 0);
    if ( v11 != nullptr )
      src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v11 + 4));
    else
      src = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &pChannelsClip->m_Channels,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053C200
// Name: void CreateAnimationLogs(class CDmeChannelsClip __near *,class CDmeGameModel __near *,class CStudioHdr const __near &,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateAnimationLogs(
        int a1@<ebp>,
        DmElementHandle_t a2@<edi>,
        CDmeChannelsClip *channelsClip,
        CDmeGameModel *pModel,
        CStudioHdr *hdr,
        int sequence,
        float flStartTime,
        float flDuration,
        float flTimeStep)
{
  void *v9; // esp
  const CStudioHdr *v10; // esi
  int NumSeq_Internal; // eax
  int numbones; // edi
  void *v13; // eax
  IMemAlloc_vtbl *v14; // edx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  void *(__thiscall *v16)(IMemAlloc *, unsigned int); // edx
  int v17; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  double v26; // xmm0_8
  CDmeTransform *Bone; // eax
  int v28; // eax
  int v29; // esi
  int v30; // eax
  int v31; // edi
  int v32; // eax
  int v33; // esi
  CUtlSymbolTable::StringPool_t **v34; // edi
  int v35; // eax
  float *v36; // eax
  int v37; // eax
  int v38; // edi
  CUtlSymbolTable::StringPool_t **v39; // esi
  int v40; // eax
  int *v41; // eax
  CDmeChannel **v42; // esi
  const Vector *v43; // edi
  CDmeTypedLog<Vector> *Log; // eax
  int v45; // eax
  CDmeTypedLog<Quaternion> *v46; // eax
  int v47; // [esp+10h] [ebp-1D00h]
  DmeTime_t v48; // [esp+10h] [ebp-1D00h]
  const Quaternion *cycle; // [esp+14h] [ebp-1CFCh]
  Quaternion v51[256]; // [esp+34h] [ebp-1CDCh] BYREF
  Vector v52[256]; // [esp+1034h] [ebp-CDCh] BYREF
  float v53[25]; // [esp+1C34h] [ebp-DCh] BYREF
  void *v54; // [esp+1C98h] [ebp-78h]
  float v55; // [esp+1CACh] [ebp-64h]
  float i; // [esp+1CB0h] [ebp-60h]
  mstudioseqdesc_t *v57; // [esp+1CB4h] [ebp-5Ch]
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v58; // [esp+1CB8h] [ebp-58h] BYREF
  int v59; // [esp+1CC4h] [ebp-4Ch]
  CUtlSymbolTable::StringPool_t **m_pMemory; // [esp+1CC8h] [ebp-48h]
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v61; // [esp+1CCCh] [ebp-44h] BYREF
  int v62; // [esp+1CD8h] [ebp-38h]
  CUtlSymbolTable::StringPool_t **v63; // [esp+1CDCh] [ebp-34h]
  signed int v64; // [esp+1CE0h] [ebp-30h]
  float v65; // [esp+1CE4h] [ebp-2Ch]
  IBoneSetup v66; // [esp+1CE8h] [ebp-28h] BYREF
  float v67; // [esp+1CECh] [ebp-24h]
  float flTime; // [esp+1CF0h] [ebp-20h]
  Quaternion *v69; // [esp+1CF4h] [ebp-1Ch]
  float v70; // [esp+1CF8h] [ebp-18h]
  int m_Size; // [esp+1CFCh] [ebp-14h]
  char v72; // [esp+1D03h] [ebp-Dh]
  int v73; // [esp+1D04h] [ebp-Ch]
  void *v74; // [esp+1D08h] [ebp-8h]
  void *retaddr; // [esp+1D10h] [ebp+0h]

  v73 = a1;
  v74 = retaddr;
  v9 = alloca(7384);
  v10 = hdr;
  if ( hdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: hdr);
  else
    NumSeq_Internal = hdr->m_pStudioHdr->numlocalseq;
  if ( sequence >= NumSeq_Internal )
    sequence = 0;
  numbones = hdr->m_pStudioHdr->numbones;
  v67 = *(float *)&numbones;
  v54 = nullptr;
  memset(&v58, 0, sizeof(v58));
  v59 = 0;
  memset(&v61, 0, sizeof(v61));
  v62 = 0;
  if ( numbones > 0 )
  {
    v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * numbones);
    v14 = _g_pMemAlloc->__vftable;
    v54 = v13;
    Alloc_2 = v14->Alloc_2;
    v58.m_nAllocationCount = numbones;
    v58.m_pMemory = (CUtlSymbolTable::StringPool_t **)Alloc_2(this: _g_pMemAlloc, a2: 4 * numbones);
  }
  m_pMemory = v58.m_pMemory;
  if ( numbones > 0 )
  {
    v16 = _g_pMemAlloc->Alloc_2;
    v61.m_nAllocationCount = numbones;
    v61.m_pMemory = (CUtlSymbolTable::StringPool_t **)v16(this: _g_pMemAlloc, a2: 4 * numbones);
  }
  v63 = v61.m_pMemory;
  Studio_CalcDefaultPoseParameters(pStudioHdr: hdr, flPoseParameter: v53, nCount: 24);
  v70 = Studio_Duration(pStudioHdr: hdr, iSequence: sequence, poseParameter: v53);
  if ( hdr->m_pVModel != nullptr )
  {
    v19 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: sequence);
  }
  else
  {
    v17 = sequence;
    m_pStudioHdr = hdr->m_pStudioHdr;
    if ( sequence < 0 || sequence >= m_pStudioHdr->numlocalseq )
      v17 = 0;
    v19 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v17 + m_pStudioHdr->localseqindex);
  }
  v20 = flStartTime;
  v21 = flStartTime + flDuration;
  v57 = v19;
  v72 = 0;
  flTime = flStartTime;
  v55 = flStartTime + flDuration;
  if ( (float)(flStartTime + flDuration) >= flStartTime )
  {
    v22 = 1.0 / v70;
    for ( i = 1.0 / v70; ; v22 = i )
    {
      if ( v20 > v21 )
      {
        v20 = v21;
        flTime = v21;
      }
      v23 = v22 * v20;
      if ( (v57->flags & 1) == 0 )
        break;
      v24 = v23 - (float)(int)v23;
      v65 = v24;
      if ( v24 < 0.0 )
      {
        v25 = v24 + 1.0;
LABEL_31:
        v65 = v25;
      }
      if ( v72 == 0 )
      {
        v72 = 1;
        v64 = 0;
        if ( numbones > 0 )
        {
          v69 = nullptr;
          do
          {
            m_Size = channelsClip->m_Channels.m_Storage.m_Size;
            Bone = CDmeGameModel::GetBone(this: pModel, index: v64);
            CreateTransformChannels(
              pTransform: Bone,
              pBaseName: (const char *)v10->m_pStudioHdr
            + (unsigned int)v69
            + v10->m_pStudioHdr->boneindex
            + *(int *)((char *)&v10->m_pStudioHdr->id + (unsigned int)v69 + v10->m_pStudioHdr->boneindex),
              pChannelsClip: channelsClip);
            v28 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, DmElementHandle_t))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: channelsClip->m_Channels.m_Storage.m_Memory.m_pMemory[m_Size],
                    a3: a2);
            v29 = v28;
            if ( v28 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v28 + 16))(
                   a1: v28,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              LODWORD(v70) = v29 - 4;
            }
            else
            {
              v70 = 0.0;
            }
            a2 = channelsClip->m_Channels.m_Storage.m_Memory.m_pMemory[m_Size + 1];
            v30 = ((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
            v31 = v30;
            if ( v30 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v30 + 16))(
                   a1: v30,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              m_Size = v31 - 4;
            }
            else
            {
              m_Size = 0;
            }
            v32 = v59;
            v33 = v59;
            if ( v59 + 1 > v58.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &v58, num: v59 - v58.m_nAllocationCount + 1);
              v32 = v59;
            }
            v34 = v58.m_pMemory;
            v59 = v32 + 1;
            v35 = v32 - v33;
            m_pMemory = v58.m_pMemory;
            if ( v35 > 0 )
              _V_memmove(dest: &v58.m_pMemory[v33 + 1], src: &v58.m_pMemory[v33], count: 4 * v35);
            v36 = (float *)&v34[v33];
            if ( v36 != nullptr )
              *v36 = v70;
            v37 = v62;
            v38 = v62;
            if ( v62 + 1 > v61.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &v61, num: v62 - v61.m_nAllocationCount + 1);
              v37 = v62;
            }
            v39 = v61.m_pMemory;
            v62 = v37 + 1;
            v40 = v37 - v38;
            v63 = v61.m_pMemory;
            if ( v40 > 0 )
              _V_memmove(dest: &v61.m_pMemory[v38 + 1], src: &v61.m_pMemory[v38], count: 4 * v40);
            v41 = (int *)&v39[v38];
            if ( v41 != nullptr )
              *v41 = m_Size;
            v69 = (Quaternion *)((char *)v69 + 216);
            v10 = hdr;
            ++v64;
          }
          while ( v64 < SLODWORD(v67) );
          numbones = LODWORD(v67);
        }
      }
      IBoneSetup::IBoneSetup(this: &v66, pStudioHdr: v10, boneMask: 524032, poseParameter: v53, pPoseDebugger: nullptr);
      IBoneSetup::InitPose(this: &v66, pos: v52, q: (QuaternionAligned *)v51);
      IBoneSetup::AccumulatePose(
        this: &v66,
        pos: v52,
        q: v51,
        sequence,
        cycle: v65,
        flWeight: 1.0,
        flTime,
        pIKContext: nullptr);
      if ( numbones > 0 )
      {
        v42 = (CDmeChannel **)v61.m_pMemory;
        m_Size = (char *)v58.m_pMemory - (char *)v61.m_pMemory;
        v69 = v51;
        v43 = v52;
        v70 = v67;
        do
        {
          v47 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(flTime));
          Log = (CDmeTypedLog<Vector> *)CDmeChannel::GetLog(this: *(CDmeChannel **)((char *)v42 + m_Size));
          CDmeTypedLog<Vector>::InsertKey(
            this: Log,
            nTime: (DmeTime_t)v47,
            value: v43,
            interpSetting: SEGMENT_INTERPOLATE,
            curveType: 0,
            bIgnoreTolerance: false);
          v45 = DmeTime_t::RoundSecondsToTMS(sec: LODWORD(flTime));
          cycle = v69;
          v48.m_tms = v45;
          v46 = (CDmeTypedLog<Quaternion> *)CDmeChannel::GetLog(this: *v42);
          CDmeTypedLog<Quaternion>::InsertKey(
            this: v46,
            nTime: v48,
            value: cycle,
            interpSetting: SEGMENT_INTERPOLATE,
            curveType: 0,
            bIgnoreTolerance: 0);
          ++v69;
          ++v43;
          ++v42;
          --LODWORD(v70);
        }
        while ( v70 != 0.0 );
        numbones = LODWORD(v67);
        v10 = hdr;
      }
      IBoneSetup::~IBoneSetup(this: &v66);
      v20 = flTime + flTimeStep;
      v21 = v55;
      flTime = v20;
      if ( v55 < v20 )
        goto LABEL_62;
    }
    if ( v23 >= 0.9999 || v23 >= 0.0 )
    {
      if ( v23 >= 0.9999 )
        v26 = 0.9999;
      else
        v26 = v23;
    }
    else
    {
      v26 = 0.0;
    }
    v25 = v26;
    goto LABEL_31;
  }
LABEL_62:
  if ( v61.m_nGrowSize >= 0 && v61.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v61.m_pMemory);
  if ( v58.m_nGrowSize >= 0 && v58.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v58.m_pMemory);
  if ( v54 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
}

//------------------------------------------------------------------------------
// Address: 0x0053C730
// Name: class CDmeTransformControl __near * CreateTransformControlAndChannels(char const __near *,class CDmeTransform __near *,class CDmeChannelsClip __near *,class CDmeChannelsClip __near *,class CDmeAnimationSet __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CreateTransformControlAndChannels(
        const char *pName,
        CDmeTransform *pTransform,
        CDmeChannelsClip *pSrcChannelsClip,
        CDmeChannelsClip *pDstChannelsClip,
        CDmeAnimationSet *pAnimationSet,
        bool bUseExistingLogDag)
{
  CDmeTransformControl *v6; // eax
  CDmeChannel *ChannelTargetingTransform; // esi
  CDmElement *v8; // eax
  CDmeTransformControl *v9; // esi
  CDmElement *v10; // eax
  CDmeTransformControl *v11; // esi
  CDmeTransformControl *NewControl; // eax
  CDmeTransformControl *pRotControl; // [esp+4h] [ebp-10h]
  CDmeTransformControl *pPosControl; // [esp+8h] [ebp-Ch]
  CDmeChannel *pRotChannel; // [esp+Ch] [ebp-8h]
  CDmeChannel *pPosChannel; // [esp+10h] [ebp-4h]

  v6 = nullptr;
  if ( pName == nullptr || pTransform == nullptr || pDstChannelsClip == nullptr || pAnimationSet == nullptr )
    return nullptr;
  pPosChannel = nullptr;
  pRotChannel = nullptr;
  if ( pSrcChannelsClip == nullptr )
    goto LABEL_9;
  ChannelTargetingTransform = FindChannelTargetingTransform(
                                pChannelsClip: pSrcChannelsClip,
                                pTransform,
                                controlType: CONTROL_TYPE_POSITION);
  pPosChannel = ChannelTargetingTransform;
  pRotChannel = FindChannelTargetingTransform(
                  pChannelsClip: pSrcChannelsClip,
                  pTransform,
                  controlType: CONTROL_TYPE_ORIENTATION);
  if ( ChannelTargetingTransform == nullptr )
  {
    v6 = nullptr;
LABEL_9:
    pPosControl = nullptr;
    v9 = nullptr;
    goto LABEL_10;
  }
  v8 = CDmeChannel::GetFromElement(this: ChannelTargetingTransform);
  v9 = CastElement<CDmeTransformControl>(pElement: v8);
  pPosControl = v9;
  v6 = nullptr;
LABEL_10:
  if ( pRotChannel != nullptr )
  {
    v10 = CDmeChannel::GetFromElement(this: pRotChannel);
    v6 = CastElement<CDmeTransformControl>(pElement: v10);
  }
  pRotControl = v6;
  v11 = v9 != v6 ? nullptr : v9;
  if ( v11 != nullptr && FindAncestorReferencingElement<CDmeAnimationSet>(target: v11) == pAnimationSet )
  {
    if ( pSrcChannelsClip == pDstChannelsClip )
      return v11;
  }
  else
  {
    NewControl = CDmeAnimationSet::CreateNewControl(this: pAnimationSet, pControlName: pName, bTransformControl: true);
    v11 = CastElement<CDmeTransformControl>(pElement: NewControl);
    if ( v11 == nullptr )
      return v11;
  }
  AttachChannelToTranformControl(
    pName,
    controlType: CONTROL_TYPE_POSITION,
    pAttachChannel: (int)pPosChannel,
    pTransformControl: v11,
    pTransform,
    pSrcChannelsClip,
    pDstChannelsClip,
    bUseExistingLogData: bUseExistingLogDag);
  AttachChannelToTranformControl(
    pName,
    controlType: CONTROL_TYPE_ORIENTATION,
    pAttachChannel: (int)pRotChannel,
    pTransformControl: v11,
    pTransform,
    pSrcChannelsClip,
    pDstChannelsClip,
    bUseExistingLogData: bUseExistingLogDag);
  if ( pPosControl != nullptr && pPosControl != v11 )
    CDmeAnimationSet::RemoveControl(this: pAnimationSet, pControl: pPosControl);
  if ( pRotControl == nullptr || pRotControl == v11 )
    return v11;
  CDmeAnimationSet::RemoveControl(this: pAnimationSet, pControl: pRotControl);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x0053C880
// Name: void SetupBoneTransform(class CDmeChannelsClip __near *,class CDmeChannelsClip __near *,class CDmeAnimationSet __near *,class CDmeGameModel __near *,class CStudioHdr const __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall SetupBoneTransform(
        CBoneSetup *a1@<ebp>,
        CDmeChannelsClip *pSrcChannelsClip,
        CDmeChannelsClip *pDstChannelsClip,
        CDmeAnimationSet *pAnimationSet,
        CDmeGameModel *pGameModel,
        const CStudioHdr *hdr,
        unsigned int bonenum,
        bool bUseExistingLogData)
{
  void *v8; // esp
  CDmeTransform *Bone; // edi
  const char *v10; // eax
  Quaternion v11[256]; // [esp+20h] [ebp-1C7Ch] BYREF
  Vector v12[256]; // [esp+1028h] [ebp-C74h] BYREF
  float v13[25]; // [esp+1C28h] [ebp-74h] BYREF
  IBoneSetup v14[4]; // [esp+1C8Ch] [ebp-10h] BYREF
  CBoneSetup *retaddr; // [esp+1C9Ch] [ebp+0h]

  v14[1].m_pBoneSetup = a1;
  v14[2].m_pBoneSetup = retaddr;
  v8 = alloca(7288);
  Bone = CDmeGameModel::GetBone(this: pGameModel, index: bonenum);
  if ( !pGameModel->m_bEvaluateProceduralBones.m_Storage || (hdr->m_boneFlags.m_Memory.m_pMemory[bonenum] & 4) == 0 )
  {
    v10 = (char *)hdr->m_pStudioHdr + 216 * bonenum + hdr->m_pStudioHdr->boneindex;
    CreateTransformControlAndChannels(
      pName: &v10[*(_DWORD *)v10],
      pTransform: Bone,
      pSrcChannelsClip,
      pDstChannelsClip,
      pAnimationSet,
      bUseExistingLogDag: bUseExistingLogData);
    Studio_CalcDefaultPoseParameters(pStudioHdr: hdr, flPoseParameter: v13, nCount: 24);
    IBoneSetup::IBoneSetup(this: v14, pStudioHdr: hdr, boneMask: 524032, poseParameter: v13, pPoseDebugger: nullptr);
    IBoneSetup::InitPose(this: v14, pos: v12, q: (QuaternionAligned *)v11);
    IBoneSetup::AccumulatePose(
      this: v14,
      pos: v12,
      q: v11,
      sequence: 0,
      cycle: 0.0,
      flWeight: 1.0,
      flTime: 0.0,
      pIKContext: nullptr);
    CDmeTransform::SetPosition(this: Bone, vecPosition: &v12[bonenum]);
    CDmeTransform::SetOrientation(this: Bone, orientation: &v11[bonenum]);
    IBoneSetup::~IBoneSetup(this: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053CC30
// Name: void ProcessGroupMapping(class KeyValues __near *,char const __near *,class CUtlDict<class CUtlString,int> __near &,class CUtlVector<struct GroupControlOrdering_t,class CUtlMemory<struct GroupControlOrdering_t,int>> __near &,class Color const __near &,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessGroupMapping(
        KeyValues *pGroupKeyValues,
        const char *pParentName,
        CUtlDict<CUtlString,int> *defaultGroupMapping,
        CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int> > *defaultGroupOrdering,
        const Color *defaultGroupColor,
        const Color *defaultControlColor)
{
  CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int> > *v6; // edi
  int v7; // eax
  CUtlString *v8; // esi
  KeyValues *FirstValue; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v12; // eax
  GroupControlOrdering_t *m_pMemory; // ecx
  int v14; // edi
  int v15; // eax
  CUtlMemory<CUtlString,int> *v16; // esi
  CUtlString *v17; // ecx
  int v18; // eax
  CUtlString *v19; // edi
  KeyValues *i; // esi
  CUtlString element; // [esp+4h] [ebp-2Ch] BYREF
  CUtlString controlName; // [esp+14h] [ebp-1Ch] BYREF
  int v23; // [esp+24h] [ebp-Ch]
  const char *pGroupName; // [esp+28h] [ebp-8h]
  KeyValues *pGroupElement; // [esp+2Ch] [ebp-4h] BYREF

  pGroupName = KeyValues::GetName(this: pGroupKeyValues);
  if ( pGroupName != nullptr )
  {
    v6 = defaultGroupOrdering;
    v7 = CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int>>::InsertBefore(
           this: defaultGroupOrdering,
           elem: defaultGroupOrdering->m_Size) << 6;
    v8 = (CUtlString *)((char *)&defaultGroupOrdering->m_Memory.m_pMemory->groupName + v7);
    v23 = v7;
    CUtlString::operator=(this: v8, src: pGroupName);
    CUtlString::operator=(this: v8 + 1, src: pParentName);
    v8[3].m_Storage.m_Memory.m_nAllocationCount = (int)*KeyValues::GetColor(
                                                          this: pGroupKeyValues,
                                                          result: (Color *)&pGroupElement,
                                                          keyName: "groupColor",
                                                          defaultColor: defaultGroupColor);
    v8[3].m_Storage.m_Memory.m_nGrowSize = (int)*KeyValues::GetColor(
                                                   this: pGroupKeyValues,
                                                   result: (Color *)&pGroupElement,
                                                   keyName: "controlColor",
                                                   defaultColor: defaultControlColor);
    LOBYTE(v8[3].m_Storage.m_nActualLength) = KeyValues::GetInt(
                                                this: pGroupKeyValues,
                                                keyName: "visible",
                                                defaultValue: 1) != 0;
    BYTE1(v8[3].m_Storage.m_nActualLength) = KeyValues::GetInt(
                                               this: pGroupKeyValues,
                                               keyName: "selectable",
                                               defaultValue: 1) != 0;
    BYTE2(v8[3].m_Storage.m_nActualLength) = KeyValues::GetInt(this: pGroupKeyValues, keyName: "snap", defaultValue: 1) != 0;
    FirstValue = KeyValues::GetFirstValue(this: pGroupKeyValues);
    pGroupElement = FirstValue;
    if ( FirstValue != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstValue);
        if ( _V_stricmp(s1: Name, s2: "control") == 0 )
        {
          String = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: &pch);
          CUtlString::CUtlString(this: &controlName, pString: String);
          CUtlString::CUtlString(this: &element, pString: pGroupName);
          v12 = CUtlString::operator char const *(this: &controlName);
          CUtlDict<CUtlString,int>::Insert(this: defaultGroupMapping, pName: v12, &element);
          element.m_Storage.m_nActualLength = 0;
          if ( element.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( element.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: element.m_Storage.m_Memory.m_pMemory);
              element.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            element.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          m_pMemory = v6->m_Memory.m_pMemory;
          v14 = *(int *)((char *)&v6->m_Memory.m_pMemory->controlList.m_Size + v23);
          v15 = *(int *)((char *)&m_pMemory->controlList.m_Memory.m_nAllocationCount + v23);
          v16 = (CUtlMemory<CUtlString,int> *)((char *)&m_pMemory->controlList.m_Memory + v23);
          if ( v14 + 1 > v15 )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(this: v16, num: v14 - v15 + 1);
          ++v16[1].m_pMemory;
          v17 = v16->m_pMemory;
          v18 = (int)v16[1].m_pMemory - v14 - 1;
          v16[1].m_nAllocationCount = (int)v16->m_pMemory;
          if ( v18 > 0 )
            _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 16 * v18);
          v19 = &v16->m_pMemory[v14];
          if ( v19 != nullptr )
            CUtlString::CUtlString(this: v19, string: &controlName);
          controlName.m_Storage.m_nActualLength = 0;
          if ( controlName.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( controlName.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlName.m_Storage.m_Memory.m_pMemory);
              controlName.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            controlName.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          FirstValue = pGroupElement;
          v6 = defaultGroupOrdering;
        }
        pGroupElement = KeyValues::GetNextValue(this: FirstValue);
        if ( pGroupElement == nullptr )
          break;
        FirstValue = pGroupElement;
      }
    }
    for ( i = KeyValues::GetFirstTrueSubKey(this: pGroupKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
      ProcessGroupMapping(
        pGroupKeyValues: i,
        pParentName: pGroupName,
        defaultGroupMapping,
        defaultGroupOrdering: v6,
        defaultGroupColor,
        defaultControlColor);
  }
  else
  {
    _Warning(a1: "%s is malformed\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053CE80
// Name: LoadDefaultGroupMappings
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadDefaultGroupMappings(
        CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int> > *defaultGroupOrdering@<edi>,
        CUtlDict<CUtlString,int> *defaultGroupMapping,
        const Color *defaultGroupColor,
        const Color *defaultControlColor)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  bool v7; // al
  KeyValues *v8; // ecx
  KeyValues *i; // esi
  KeyValues *pGroupFile; // [esp+4h] [ebp-4h]

  CUtlDict<CUtlString,int>::RemoveAll(this: defaultGroupMapping);
  CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int>>::RemoveAll(this: defaultGroupOrdering);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "groupFile");
    pGroupFile = v5;
    if ( v5 != nullptr )
    {
      if ( g_pFullFileSystem != nullptr )
        v6 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v6 = nullptr;
      v7 = KeyValues::LoadFromFile(
             this: v5,
             filesystem: v6,
             resourceName: "cfg/SFM_DefaultAnimationGroups.txt",
             pathID: "GAME",
             pfnEvaluateSymbolProc: nullptr);
      v8 = v5;
      if ( v7 )
      {
        for ( i = KeyValues::GetFirstTrueSubKey(this: v5); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
          ProcessGroupMapping(
            pGroupKeyValues: i,
            pParentName: &pch,
            defaultGroupMapping,
            defaultGroupOrdering,
            defaultGroupColor,
            defaultControlColor);
        v8 = pGroupFile;
      }
      KeyValues::deleteThis(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053CF30
// Name: void BuildGroupMappings(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGroupMappings(CDmeAnimationSet *pAnimationSet)
{
  CDmeControlGroup *v1; // ebx
  char *v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  CDmeControlGroup *v5; // eax
  CDmeControlGroup *v6; // edi
  CDmeAnimationSet *v7; // edi
  CDmeControlGroup *v8; // eax
  CDmaElementArray<CDmElement> *Bookmarks; // eax
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  const char *m_pAsString; // esi
  char *v14; // edi
  int v15; // esi
  CDmeControlGroup *v16; // eax
  char *v17; // ebx
  const char *v18; // eax
  CDmeControlGroup *ControlGroup; // esi
  int v20; // edi
  const char *v21; // eax
  CDmElement *ControlByName; // eax
  int v23; // esi
  CDmeRig *v24; // ecx
  CDmeControlGroup *RootControlGroup; // eax
  CDmeRig **m_pMemory; // eax
  GroupControlOrdering_t *v27; // eax
  int j; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int> *v29; // eax
  CUtlMap<char const *,CUtlString,int>::Node_t search; // [esp+Ch] [ebp-8Ch] BYREF
  char unknownGroupName[8]; // [esp+20h] [ebp-78h] BYREF
  int nCount; // [esp+28h] [ebp-70h]
  char ignoreGroupName[8]; // [esp+2Ch] [ebp-6Ch] BYREF
  CUtlDict<CUtlString,int> defaultGroupMapping; // [esp+34h] [ebp-64h] BYREF
  CUtlVector<CDmeRig *,CUtlMemory<CDmeRig *,int> > rigList; // [esp+58h] [ebp-40h] BYREF
  CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int> > defaultGroupOrdering; // [esp+6Ch] [ebp-2Ch] BYREF
  int nNumGroups; // [esp+80h] [ebp-18h]
  CDmaElementArray<CDmElement> *controls; // [esp+84h] [ebp-14h]
  Color defaultControlColor; // [esp+88h] [ebp-10h] BYREF
  Color defaultGroupColor; // [esp+8Ch] [ebp-Ch] BYREF
  int i; // [esp+90h] [ebp-8h]
  CDmElement *pControl; // [esp+94h] [ebp-4h]

  strcpy(unknownGroupName, "Unknown");
  v1 = nullptr;
  strcpy(ignoreGroupName, "IGNORE");
  defaultGroupMapping.m_Elements.m_Tree.m_Root = -1;
  defaultGroupMapping.m_Elements.m_Tree.m_FirstFree = -1;
  defaultGroupMapping.m_Elements.m_Tree.m_LastAlloc.index = -1;
  defaultGroupColor = (Color)-32768;
  defaultControlColor = (Color)-3618616;
  memset(&defaultGroupMapping.m_Elements.m_Tree.m_Elements, 0, sizeof(defaultGroupMapping.m_Elements.m_Tree.m_Elements));
  defaultGroupMapping.m_Elements.m_Tree.m_NumElements = 0;
  defaultGroupMapping.m_Elements.m_Tree.m_pElements = nullptr;
  defaultGroupMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  memset(&defaultGroupOrdering, 0, sizeof(defaultGroupOrdering));
  LoadDefaultGroupMappings(&defaultGroupOrdering, &defaultGroupMapping, &defaultGroupColor, &defaultControlColor);
  nNumGroups = defaultGroupOrdering.m_Size;
  if ( defaultGroupOrdering.m_Size > 0 )
  {
    pControl = nullptr;
    for ( i = defaultGroupOrdering.m_Size; i != 0; --i )
    {
      v2 = (char *)pControl + (unsigned int)defaultGroupOrdering.m_Memory.m_pMemory;
      if ( CUtlString::Length(this: (CUtlString *)&pControl->m_Id.m_Value[(unsigned int)defaultGroupOrdering.m_Memory.m_pMemory
                                                                        + 12]) != 0 )
      {
        v3 = CUtlString::operator char const *(this: (CUtlString *)v2 + 1);
        v1 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimationSet, pParentGroup: nullptr, pControlGroupName: v3);
      }
      v4 = CUtlString::operator char const *(this: (CUtlString *)v2);
      v5 = CDmeAnimationSet::FindOrAddControlGroup(this: pAnimationSet, pParentGroup: v1, pControlGroupName: v4);
      v6 = v5;
      if ( v5 != nullptr )
      {
        CDmeControlGroup::SetVisible(this: v5, bVisible: v2[60]);
        CDmeControlGroup::SetSnappable(this: v6, bSnappable: v2[62]);
        CDmeControlGroup::SetSelectable(this: v6, bSelectable: v2[61]);
        CDmeControlGroup::SetGroupColor(this: v6, groupColor: (const Color *)v2 + 13, bRecursive: false);
        CDmeControlGroup::SetControlColor(this: v6, controlColor: (const Color *)v2 + 14, bRecursive: false);
      }
      pControl = (CDmElement *)((char *)pControl + 64);
      v1 = nullptr;
    }
  }
  v7 = pAnimationSet;
  v8 = CDmeAnimationSet::FindOrAddControlGroup(
         this: pAnimationSet,
         pParentGroup: nullptr,
         pControlGroupName: unknownGroupName);
  if ( v8 != nullptr )
    CDmeControlGroup::SetGroupColor(this: v8, groupColor: &defaultGroupColor, bRecursive: false);
  Bookmarks = (CDmaElementArray<CDmElement> *)CDmeBookmarkSet::GetBookmarks(this: (CDmeTransform *)pAnimationSet);
  m_Size = Bookmarks->m_Storage.m_Size;
  controls = Bookmarks;
  nCount = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: Bookmarks->m_Storage.m_Memory.m_pMemory[i]);
      v12 = v11;
      if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmElement::m_classType) )
      {
        pControl = v12;
      }
      else
      {
        pControl = nullptr;
        v12 = nullptr;
      }
      if ( AddConstraintControlToGroup(
             pControl: v12,
             pAnimationSet: v7,
             groupColor: &defaultGroupColor,
             &defaultGroupMapping) == 0 )
      {
        m_pAsString = v12->m_Name.m_Storage.u.m_pAsString;
        v14 = unknownGroupName;
        if ( m_pAsString == (const char *)-1 )
          break;
        if ( m_pAsString != nullptr )
          goto LABEL_21;
LABEL_27:
        if ( _V_stricmp(s1: v14, s2: ignoreGroupName) != 0 )
        {
          v16 = CDmeAnimationSet::FindOrAddControlGroup(
                  this: pAnimationSet,
                  pParentGroup: nullptr,
                  pControlGroupName: v14);
          if ( v16 != nullptr )
            CDmeControlGroup::AddControl(this: v16, pControl, pInsertBeforeControl: nullptr);
        }
        v7 = pAnimationSet;
      }
      if ( ++i >= nCount )
        goto LABEL_32;
      Bookmarks = controls;
    }
    m_pAsString = &pch;
LABEL_21:
    CUtlString::CUtlString(this: &search.elem);
    search.key = m_pAsString;
    v15 = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::Find(
            this: &defaultGroupMapping.m_Elements.m_Tree,
            &search);
    search.elem.m_Storage.m_nActualLength = 0;
    if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
        search.elem.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      search.elem.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    if ( v15 != -1 )
      v14 = (char *)CUtlString::operator char const *(this: &defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory[v15].m_Data.elem);
    goto LABEL_27;
  }
LABEL_32:
  if ( nNumGroups > 0 )
  {
    i = 0;
    for ( controls = (CDmaElementArray<CDmElement> *)nNumGroups;
          controls != nullptr;
          controls = (CDmaElementArray<CDmElement> *)((char *)controls - 1) )
    {
      v17 = (char *)defaultGroupOrdering.m_Memory.m_pMemory + i;
      v18 = CUtlString::operator char const *(this: (CUtlString *)((char *)&defaultGroupOrdering.m_Memory.m_pMemory->groupName
                                                                 + i));
      ControlGroup = CDmeAnimationSet::FindControlGroup(this: v7, pControlGroupName: v18);
      if ( ControlGroup != nullptr && *((int *)v17 + 11) > 0 )
      {
        v20 = 0;
        pControl = *((CDmElement **)v17 + 11);
        do
        {
          v21 = CUtlString::operator char const *(this: (CUtlString *)(v20 + *((_DWORD *)v17 + 8)));
          ControlByName = CDmeControlGroup::FindControlByName(
                            this: ControlGroup,
                            pchName: v21,
                            recursive: false,
                            pParentGroup: nullptr);
          if ( ControlByName != nullptr )
            CDmeControlGroup::AddControl(this: ControlGroup, pControl: ControlByName, pInsertBeforeControl: nullptr);
          v20 += 16;
          pControl = (CDmElement *)((char *)pControl - 1);
        }
        while ( pControl != nullptr );
        v7 = pAnimationSet;
      }
      i += 64;
    }
  }
  memset(&rigList, 0, sizeof(rigList));
  CollectRigsOnAnimationSet(pAnimSet: v7, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&rigList);
  v23 = 0;
  for ( nNumGroups = rigList.m_Size; v23 < nNumGroups; ++v23 )
  {
    v24 = rigList.m_Memory.m_pMemory[v23];
    if ( v24 != nullptr )
      CDmeRig::HideHiddenControlGroups(this: v24, pAnimationSet: v7);
  }
  RootControlGroup = CDmeAnimationSet::GetRootControlGroup(this: v7);
  CDmeControlGroup::DestroyEmptyChildren(this: RootControlGroup);
  m_pMemory = rigList.m_Memory.m_pMemory;
  rigList.m_Size = 0;
  if ( rigList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( rigList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rigList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      rigList.m_Memory.m_pMemory = nullptr;
    }
    rigList.m_Memory.m_nAllocationCount = 0;
  }
  rigList.m_pElements = m_pMemory;
  if ( rigList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      rigList.m_Memory.m_pMemory = nullptr;
    }
    rigList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<GroupControlOrdering_t,CUtlMemory<GroupControlOrdering_t,int>>::RemoveAll(this: &defaultGroupOrdering);
  v27 = defaultGroupOrdering.m_Memory.m_pMemory;
  if ( defaultGroupOrdering.m_Memory.m_nGrowSize >= 0 )
  {
    if ( defaultGroupOrdering.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultGroupOrdering.m_Memory.m_pMemory);
      v27 = nullptr;
      defaultGroupOrdering.m_Memory.m_pMemory = nullptr;
    }
    defaultGroupOrdering.m_Memory.m_nAllocationCount = 0;
  }
  defaultGroupOrdering.m_pElements = v27;
  if ( defaultGroupOrdering.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v27 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27);
      defaultGroupOrdering.m_Memory.m_pMemory = nullptr;
    }
    defaultGroupOrdering.m_Memory.m_nAllocationCount = 0;
  }
  for ( j = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::FirstInorder(this: &defaultGroupMapping.m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::NextInorder(
              this: &defaultGroupMapping.m_Elements.m_Tree,
              i: j) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::RemoveAll(this: &defaultGroupMapping.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::RemoveAll(this: &defaultGroupMapping.m_Elements.m_Tree);
  v29 = defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory;
  defaultGroupMapping.m_Elements.m_Tree.m_FirstFree = -1;
  if ( defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory);
      v29 = nullptr;
      defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  defaultGroupMapping.m_Elements.m_Tree.m_LastAlloc.index = -1;
  if ( defaultGroupMapping.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 && v29 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
}

//------------------------------------------------------------------------------
// Address: 0x0053D3B0
// Name: class CDmeAnimationSet __near * CreateAnimationSet(class CDmeFilmClip __near *,class CDmeFilmClip __near *,class CDmeGameModel __near *,char const __near *,bool,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__cdecl CreateAnimationSet(
        CDmeFilmClip *pMovie,
        CDmeFilmClip *pShot,
        int pGameModel,
        CDmeAnimationSet *pAnimationSetName,
        int bAttachToGameRecording,
        CDmElement *pSharedPresetGroupSettings)
{
  signed int v6; // edi
  DmElementHandle_t v7; // eax
  CDmElement *v8; // eax
  const char *v9; // esi
  CDmeAnimationSet *v10; // ebx
  CExpressionCalculator *v11; // esi
  const studiohdr_t *StudioHdr; // eax
  CDmAttribute *Attribute; // eax
  CDmeTrackGroup *ChannelsClip; // ebx
  CDmeChannelsClip *v15; // eax
  CDmeTransform *Transform; // eax
  CDmeGameModel *v17; // eax
  CDmeGameModel *numbones; // ecx
  CDmAttribute *v19; // edi
  const char *ModelName; // eax
  CDmeAnimationSet *v21; // edi
  studiohdr_t *v22; // eax
  int studiohdr2index; // ecx
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // edi
  CExpressionCalculator *Child; // eax
  CDmeAnimationSet *v27; // esi
  CFlexControlBuilder::ControlInfo_t *m_pMemory; // eax
  CFlexControlBuilder::FlexControllerInfo_t *v29; // eax
  int *v30; // eax
  int *v31; // eax
  const studiohdr_t **v32; // eax
  CDmeGameModel *v34; // [esp-4h] [ebp-CCh]
  CDmeChannelsClip *v35; // [esp+10h] [ebp-B8h]
  CDmeAnimationSet *flDuration; // [esp+18h] [ebp-B0h]
  bool flTimeStep; // [esp+1Ch] [ebp-ACh]
  CStudioHdr hdr; // [esp+2Ch] [ebp-9Ch] BYREF
  CFlexControlBuilder builder; // [esp+90h] [ebp-38h] BYREF
  CDmeChannelsClip *srcChannelsClip; // [esp+BCh] [ebp-Ch]
  CDmrElementArray<CDmePresetGroupInfo> presetGroupInfos; // [esp+C0h] [ebp-8h] BYREF
  int savedregs; // [esp+C8h] [ebp+0h] BYREF

  v6 = 0;
  v7 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeAnimationSet::m_classType.u.m_Id,
         a3: (const char *)pAnimationSetName,
         a4: pShot->m_fileId,
         a5: nullptr);
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7);
  v9 = (const char *)v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeAnimationSet::m_classType) )
  {
    v10 = (CDmeAnimationSet *)v9;
    pAnimationSetName = (CDmeAnimationSet *)v9;
  }
  else
  {
    pAnimationSetName = nullptr;
    v10 = nullptr;
  }
  v11 = (CExpressionCalculator *)pGameModel;
  StudioHdr = CDmeGameModel::GetStudioHdr(this: (CDmeGameModel *)pGameModel);
  CStudioHdr::CStudioHdr(this: &hdr, pStudioHdr: StudioHdr, mdlcache: g_pMDLCache);
  if ( v11 != nullptr )
    pGameModel = CExpressionCalculator::VariableCount(this: v11);
  else
    pGameModel = -1;
  Attribute = CDmElement::FindAttribute(this: v10, pAttributeName: "gameModel");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v10, pAttributeName: "gameModel", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pGameModel);
  }
  ChannelsClip = CreateChannelsClip(pAnimationSet: v10, pOwnerClip: pShot);
  memset(&builder, 0, 40);
  CFlexControlBuilder::CreateAnimationSetControls(
    this: &builder,
    pMovie,
    pAnimationSet: pAnimationSetName,
    pGameModel: (CDmeGameModel *)v11,
    pSourceClip: pShot,
    pDestClip: (CDmeChannelsClip *)ChannelsClip,
    bUseExistingLogs: bAttachToGameRecording);
  if ( (_BYTE)bAttachToGameRecording == 0 )
  {
    pGameModel = 0;
    CreateConstantValuedLog<int>(
      channelsClip: (int)ChannelsClip,
      pName: "skin",
      pToElement: (CDmElement *)v11,
      pToAttr: "skin",
      value: &pGameModel);
    pGameModel = 0;
    CreateConstantValuedLog<int>(
      channelsClip: (int)ChannelsClip,
      pName: "body",
      pToElement: (CDmElement *)v11,
      pToAttr: "body",
      value: &pGameModel);
    pGameModel = 0;
    CreateConstantValuedLog<int>(
      channelsClip: (int)ChannelsClip,
      pName: "sequence",
      pToElement: (CDmElement *)v11,
      pToAttr: "sequence",
      value: &pGameModel);
    CreateAnimationLogs(
      a1: (int)&savedregs,
      a2: (DmElementHandle_t)0,
      channelsClip: (CDmeChannelsClip *)ChannelsClip,
      pModel: (CDmeGameModel *)v11,
      &hdr,
      sequence: 0,
      flStartTime: 0.0,
      flDuration: 1.0,
      flTimeStep: 0.050000001);
  }
  v15 = FindChannelsClip(pDag: (CDmeDag *)v11);
  flTimeStep = bAttachToGameRecording;
  flDuration = pAnimationSetName;
  v35 = v15;
  srcChannelsClip = v15;
  Transform = CDmeDag::GetTransform(this: (CDmeDag *)v11);
  CreateTransformControlAndChannels(
    pName: "rootTransform",
    pTransform: Transform,
    pSrcChannelsClip: v35,
    pDstChannelsClip: (CDmeChannelsClip *)ChannelsClip,
    pAnimationSet: flDuration,
    bUseExistingLogDag: flTimeStep);
  v17 = (CDmeGameModel *)CDmeGameModel::NumBones(this: (CDmeGameModel *)v11);
  numbones = (CDmeGameModel *)hdr.m_pStudioHdr->numbones;
  pGameModel = (int)numbones;
  if ( v17 != numbones )
  {
    if ( (int)v17 < (int)numbones )
      pGameModel = (int)v17;
    _Warning(a1: "Creating an animationset for a model whose bone count has changed! You should reattach to the model.\n");
    numbones = (CDmeGameModel *)pGameModel;
  }
  if ( (int)numbones > 0 )
  {
    do
      SetupBoneTransform(
        a1: (CBoneSetup *)&savedregs,
        pSrcChannelsClip: srcChannelsClip,
        pDstChannelsClip: (CDmeChannelsClip *)ChannelsClip,
        pAnimationSet: pAnimationSetName,
        pGameModel: (CDmeGameModel *)v11,
        &hdr,
        bonenum: v6++,
        bUseExistingLogData: bAttachToGameRecording);
    while ( v6 < pGameModel );
  }
  if ( srcChannelsClip != nullptr )
    TransferRemainingChannels(shot: pShot, destClip: (CDmeChannelsClip *)ChannelsClip, srcClip: srcChannelsClip);
  if ( pSharedPresetGroupSettings != nullptr )
    v19 = CDmElement::FindAttribute(this: pSharedPresetGroupSettings, pAttributeName: "presetGroupInfos");
  else
    v19 = nullptr;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroupInfos);
  if ( v19 != nullptr && (v19->m_nFlags & 0x1F) == 0xF )
  {
    presetGroupInfos.m_pAttribute = v19;
    presetGroupInfos.m_pStorage = (DmElementArray_t *)v19->m_pData;
  }
  else
  {
    presetGroupInfos.m_pAttribute = nullptr;
    presetGroupInfos.m_pStorage = nullptr;
  }
  ModelName = CDmeGameModel::GetModelName(this: (CDmeGameModel *)v11);
  v21 = pAnimationSetName;
  LoadPresetGroups(pAnimationSet: pAnimationSetName, pModelName: ModelName, &presetGroupInfos);
  BuildGroupMappings(pAnimationSet: v21);
  v22 = CDmeGameModel::GetStudioHdr(this: (CDmeGameModel *)v11);
  if ( v22 != nullptr )
  {
    studiohdr2index = v22->studiohdr2index;
    if ( studiohdr2index == 0 || *(int *)((char *)&v22->checksum + studiohdr2index) <= 0 )
    {
      v24 = CDmElement::FindAttribute(this: (CDmElement *)v11, pAttributeName: "illumPositionDag");
      v25 = v24 != nullptr
          ? ((unsigned __int8)((v24->m_nFlags & 0x1F) - 1) == 0
           ? v24
           : nullptr)
          : CDmElement::CreateAttribute(
              this: (CDmElement *)v11,
              pAttributeName: "illumPositionDag",
              type: AT_FIRST_VALUE_TYPE);
      if ( v25 != nullptr )
      {
        CDmAttribute::SetElementTypeSymbol(this: v25, typeSymbol: CDmeDag::m_classType);
        Child = (CExpressionCalculator *)CDmeDag::GetChild(this: (CDmeDag *)v11, i: 0);
        if ( (v25->m_nFlags & 0x1F) == 1 )
        {
          if ( Child != nullptr )
            bAttachToGameRecording = CExpressionCalculator::VariableCount(this: Child);
          else
            bAttachToGameRecording = -1;
          CDmAttribute::SetValue<enum DmElementHandle_t>(this: v25, value: (DmElementHandle_t *)&bAttachToGameRecording);
        }
      }
    }
  }
  if ( CDmeGameModel::FindAttachment(this: (CDmeGameModel *)v11, pchAttachmentName: "eyes") <= 0 )
  {
    v27 = pAnimationSetName;
  }
  else
  {
    AddLocalViewTargetControl(
      pFilmClip: pShot,
      pAnimSet: pAnimationSetName,
      pGameModel: (CDmeGameModel *)v11,
      pChannelsClip: (CDmeChannelsClip *)ChannelsClip);
    AddEyeConvergenceControl(
      pAnimationSet: pAnimationSetName,
      pGameModel: (CDmeGameModel *)v11,
      pChannelsClip: (CDmeChannelsClip *)ChannelsClip);
    v34 = (CDmeGameModel *)v11;
    v27 = pAnimationSetName;
    AddViewTargetControl(
      pFilmClip: pShot,
      pAnimationSet: pAnimationSetName,
      pGameModel: v34,
      pChannelsClip: (CDmeChannelsClip *)ChannelsClip);
  }
  CDmeAnimationSet::UpdateTransformDefaults(this: v27);
  m_pMemory = builder.m_ControlInfo.m_Memory.m_pMemory;
  builder.m_ControlInfo.m_Size = 0;
  if ( builder.m_ControlInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( builder.m_ControlInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: builder.m_ControlInfo.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      builder.m_ControlInfo.m_Memory.m_pMemory = nullptr;
    }
    builder.m_ControlInfo.m_Memory.m_nAllocationCount = 0;
  }
  builder.m_ControlInfo.m_pElements = m_pMemory;
  if ( builder.m_ControlInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      builder.m_ControlInfo.m_Memory.m_pMemory = nullptr;
    }
    builder.m_ControlInfo.m_Memory.m_nAllocationCount = 0;
  }
  v29 = builder.m_FlexControllerInfo.m_Memory.m_pMemory;
  builder.m_FlexControllerInfo.m_Size = 0;
  if ( builder.m_FlexControllerInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( builder.m_FlexControllerInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: builder.m_FlexControllerInfo.m_Memory.m_pMemory);
      v29 = nullptr;
      builder.m_FlexControllerInfo.m_Memory.m_pMemory = nullptr;
    }
    builder.m_FlexControllerInfo.m_Memory.m_nAllocationCount = 0;
  }
  builder.m_FlexControllerInfo.m_pElements = v29;
  if ( builder.m_FlexControllerInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v29 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
      builder.m_FlexControllerInfo.m_Memory.m_pMemory = nullptr;
    }
    builder.m_FlexControllerInfo.m_Memory.m_nAllocationCount = 0;
  }
  CStudioHdr::Term(this: &hdr);
  v30 = hdr.m_boneParent.m_Memory.m_pMemory;
  hdr.m_boneParent.m_Size = 0;
  if ( hdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( hdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hdr.m_boneParent.m_Memory.m_pMemory);
      v30 = nullptr;
      hdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  hdr.m_boneParent.m_pElements = v30;
  if ( hdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v30 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v30);
      hdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v31 = hdr.m_boneFlags.m_Memory.m_pMemory;
  hdr.m_boneFlags.m_Size = 0;
  if ( hdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( hdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hdr.m_boneFlags.m_Memory.m_pMemory);
      v31 = nullptr;
      hdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  hdr.m_boneFlags.m_pElements = v31;
  if ( hdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v31 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v31);
      hdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v32 = hdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  hdr.m_pStudioHdrCache.m_Size = 0;
  if ( hdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( hdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: hdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v32 = nullptr;
      hdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    hdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  hdr.m_pStudioHdrCache.m_pElements = v32;
  if ( hdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v32 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
  return v27;
}

//------------------------------------------------------------------------------
// Address: 0x005392C0
// Name: class CDmeChannelsClip __near * CreateElement<class CDmeChannelsClip>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *__cdecl CreateElement<CDmeChannelsClip>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeChannelsClip::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
    return (CDmeChannelsClip *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005395A0
// Name: class CDmeExpressionOperator __near * CreateElement<class CDmeExpressionOperator>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeExpressionOperator *__cdecl CreateElement<CDmeExpressionOperator>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeExpressionOperator::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeExpressionOperator::m_classType) )
    return (CDmeExpressionOperator *)((char *)&v5[-1] + 64);
  else
    return nullptr;
}

} // namespace sfmgen
