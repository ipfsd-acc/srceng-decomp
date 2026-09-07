// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/exportfacialanimation.cpp
// Functions: 11
// ============================================================

#include "movieobjects\exportfacialanimation.h"

//------------------------------------------------------------------------------
// Address: 0x005347D0
// Name: ComputeExportChannelScaleBias
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeExportChannelScaleBias(
        ExportInfo_t *info@<esi>,
        long double *pScale,
        DmeTime_t *pBias,
        CDmeChannel *pChannel)
{
  CDmeFilmClip *m_pMovie; // ecx
  int v5; // eax
  DmeTime_t *StartTime; // eax
  int m_tms; // ecx
  CDmeFilmClip *sec; // [esp+0h] [ebp-44h]
  DmeClipStack_t channelToGlobal; // [esp+8h] [ebp-3Ch] BYREF
  DmeTime_t result; // [esp+38h] [ebp-Ch] BYREF
  DmeTime_t tScale; // [esp+3Ch] [ebp-8h] BYREF
  DmeTime_t tOffset; // [esp+40h] [ebp-4h] BYREF

  m_pMovie = info->m_pMovie;
  channelToGlobal.m_tStart.m_tms = 0x80000000;
  channelToGlobal.m_tDuration.m_tms = 0x80000000;
  channelToGlobal.m_tOffset.m_tms = 0x80000000;
  sec = info->m_pShot;
  memset(&channelToGlobal, 0, 20);
  channelToGlobal.m_bOptimized = false;
  if ( CDmeChannel::BuildClipStack(this: pChannel, pClipStack: &channelToGlobal, pRoot: m_pMovie, pShot: sec) != 0 )
  {
    DmeClipStack_t::FromChildMediaTime(this: &channelToGlobal, result: &tOffset, t: 0, bClamp: false);
    v5 = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
    DmeClipStack_t::FromChildMediaTime(this: &channelToGlobal, result: &tScale, t: (DmeTime_t)v5, bClamp: false);
    StartTime = CDmeClip::GetStartTime(this: info->m_pShot, &result);
    m_tms = tOffset.m_tms;
    pBias->m_tms = tOffset.m_tms - StartTime->m_tms;
    *pScale = (float)((float)(tScale.m_tms - m_tms) * 0.000099999997);
  }
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &channelToGlobal.m_clips);
  if ( channelToGlobal.m_clips.m_Memory.m_nGrowSize >= 0 && channelToGlobal.m_clips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelToGlobal.m_clips.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005348B0
// Name: AddLogLayerForExport
// Source: json
//------------------------------------------------------------------------------
void __usercall AddLogLayerForExport(
        ExportInfo_t *info@<ecx>,
        CDmeChannel *pChannel@<eax>,
        CDmElement *pRoot,
        const char *pControlName)
{
  CDmeTransform *Log; // eax
  CDmeLog *v7; // ebx
  CDmAttribute *Attribute; // eax
  CDmeLogLayer *Layer; // eax
  CDmeLogLayer *v10; // edi
  CDmeLogLayer *v11; // eax
  CDmeLogLayer *v12; // eax
  float f; // [esp+10h] [ebp-2Ch]
  CUtlSymbolLarge::<unnamed_type_u> fa; // [esp+10h] [ebp-2Ch]
  int fb; // [esp+10h] [ebp-2Ch]
  CDmrElementArray<CDmElement> animations; // [esp+20h] [ebp-1Ch] BYREF
  long double flScale; // [esp+28h] [ebp-14h] BYREF
  DmElementHandle_t src; // [esp+30h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+34h] [ebp-8h] BYREF
  DmeTime_t tBias; // [esp+38h] [ebp-4h] BYREF

  Log = (CDmeTransform *)CDmeChannel::GetLog(this: pChannel);
  v7 = (CDmeLog *)Log;
  if ( Log != nullptr && CDmeTrack::GetClipCount(this: Log) != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&animations);
    if ( pRoot != nullptr
      && (Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "animations")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      animations.m_pAttribute = Attribute;
      animations.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      animations.m_pAttribute = nullptr;
      animations.m_pStorage = nullptr;
    }
    tBias.m_tms = 0x80000000;
    ComputeExportChannelScaleBias(info, pScale: &flScale, pBias: &tBias, pChannel);
    Layer = CDmeLog::GetLayer(this: v7, index: 0);
    v10 = (CDmeLogLayer *)CDmElement::CopyInternal(this: Layer, depth: TD_DEEP);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: pControlName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v10->m_Name.m_pAttribute, &value);
    CDmeLogLayer::ScaleBiasKeyTimes(this: v10, flScale, nBias: tBias);
    f = flScale;
    value.u.m_Id = info->m_tExportStart.m_tms - tBias.m_tms;
    src = LODWORD(f);
    DmeTime_t::operator/=(this: (DmeTime_t *)&value, result: (DmeTime_t *)&flScale + 1, f);
    tBias.m_tms = info->m_tExportEnd.m_tms - tBias.m_tms;
    DmeTime_t::operator/=(this: &tBias, result: (DmeTime_t *)&flScale + 1, f: *(float *)&src);
    fa.m_Id = value.u.m_Id;
    src = (DmElementHandle_t)v10->__vftable;
    v11 = CDmeLog::GetLayer(this: v7, index: 0);
    (*(void (__thiscall **)(CDmeLogLayer *, int, CDmeLogLayer *, CUtlSymbolLarge::<unnamed_type_u>))(src + 68))(
      a1: v10,
      a2: info->m_tExportStart.m_tms,
      a3: v11,
      a4: fa);
    fb = tBias.m_tms;
    src = (DmElementHandle_t)v10->__vftable;
    v12 = CDmeLog::GetLayer(this: v7, index: 0);
    (*(void (__thiscall **)(CDmeLogLayer *, int, CDmeLogLayer *, int))(src + 68))(
      a1: v10,
      a2: info->m_tExportEnd.m_tms,
      a3: v12,
      a4: fb);
    CDmeLogLayer::RemoveKeysOutsideRange(this: v10, tStart: info->m_tExportStart, tEnd: info->m_tExportEnd);
    src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &animations,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00534A40
// Name: ExportAnimations
// Source: json
//------------------------------------------------------------------------------
void __usercall ExportAnimations(CDmElement *pRoot@<edi>, ExportInfo_t *info)
{
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmeAnimationSet *m_pAnimationSet; // ecx
  const CDmaElementArray<CDmElement> *Bookmarks; // eax
  int m_Size; // ecx
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  const char *m_pAsString; // eax
  CDmeChannel *Value; // eax
  const char *v12; // eax
  CDmeChannel *v13; // eax
  CDmeChannel *v14; // eax
  const char *v15; // esi
  char pControlName[512]; // [esp+8h] [ebp-210h] BYREF
  const CDmaElementArray<CDmElement> *controls; // [esp+208h] [ebp-10h]
  int nControlCount; // [esp+20Ch] [ebp-Ch]
  CDmrElementArray<CDmElement> animations; // [esp+210h] [ebp-8h] BYREF
  int i; // [esp+220h] [ebp+8h]

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&animations);
  if ( pRoot != nullptr
    && ((Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "animations")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: pRoot, pAttributeName: "animations", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    animations.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    m_pData = nullptr;
    animations.m_pAttribute = nullptr;
  }
  m_pAnimationSet = info->m_pAnimationSet;
  animations.m_pStorage = m_pData;
  Bookmarks = (const CDmaElementArray<CDmElement> *)CDmeBookmarkSet::GetBookmarks(this: (CDmeTransform *)m_pAnimationSet);
  m_Size = Bookmarks->m_Storage.m_Size;
  controls = Bookmarks;
  nControlCount = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Bookmarks->m_Storage.m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 != nullptr
        && v8->IsA(this: v8, a2: CDmElement::m_classType)
        && !v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
      {
        if ( CDmElement::HasAttribute(this: v9, pAttributeName: "rightValue", type: AT_UNKNOWN) )
        {
          m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = &pch;
          V_snprintf(pDest: pControlName, maxLen: 512, pFormat: "left_%s", m_pAsString);
          Value = CDmElement::GetValueElement<CDmeChannel>(this: v9, pAttributeName: "leftvaluechannel");
          AddLogLayerForExport(info, pChannel: Value, pRoot, pControlName);
          v12 = v9->m_Name.m_Storage.u.m_pAsString;
          if ( v12 == (const char *)-1 )
            v12 = &pch;
          V_snprintf(pDest: pControlName, maxLen: 512, pFormat: "right_%s", v12);
          v13 = CDmElement::GetValueElement<CDmeChannel>(this: v9, pAttributeName: "leftvaluechannel");
          AddLogLayerForExport(info, pChannel: v13, pRoot, pControlName);
        }
        else
        {
          v14 = CDmElement::GetValueElement<CDmeChannel>(this: v9, pAttributeName: "channel");
          v15 = v9->m_Name.m_Storage.u.m_pAsString;
          if ( v15 == (const char *)-1 )
            v15 = &pch;
          AddLogLayerForExport(info, pChannel: v14, pRoot, pControlName: v15);
        }
      }
      if ( ++i >= nControlCount )
        break;
      Bookmarks = controls;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00534C00
// Name: ExportSounds
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExportSounds(ExportInfo_t *info, CDmElement *pRoot, CDmeClip *pClip, DmeTime_t tOffset)
{
  CDmAttribute *Attribute; // esi
  int v5; // edi
  CDmeTrackGroup *TrackGroup; // eax
  int m_Size; // ecx
  int v8; // esi
  CDmElement *v9; // eax
  CDmeTransform *v10; // edi
  CDmeClip *Clip; // esi
  const char *v12; // edi
  DmeTime_t *Duration; // eax
  const char *m_pAsString; // ecx
  CDmElement *v15; // esi
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // eax
  DmeClipStack_t soundToGlobal; // [esp+Ch] [ebp-6Ch] BYREF
  CDmrElementArray<CDmElement> sounds; // [esp+3Ch] [ebp-3Ch] BYREF
  DmeTime_t result; // [esp+44h] [ebp-34h] BYREF
  int gc; // [esp+48h] [ebp-30h]
  int _tc; // [esp+4Ch] [ebp-2Ch]
  int _cc; // [esp+50h] [ebp-28h]
  CUtlSymbolLarge value; // [esp+54h] [ebp-24h] BYREF
  CDmeTrackGroup *pTrackGroup; // [esp+58h] [ebp-20h]
  int i; // [esp+5Ch] [ebp-1Ch]
  int _i; // [esp+60h] [ebp-18h]
  CDmeTransform *v29; // [esp+64h] [ebp-14h]
  DmElementHandle_t src; // [esp+68h] [ebp-10h] BYREF
  int _j; // [esp+6Ch] [ebp-Ch]
  DmeTime_t tStart; // [esp+70h] [ebp-8h] BYREF
  DmeTime_t tEnd; // [esp+74h] [ebp-4h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sounds);
  if ( pRoot != nullptr
    && ((Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "sounds")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: pRoot, pAttributeName: "sounds", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    sounds.m_pAttribute = Attribute;
    sounds.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    sounds.m_pAttribute = nullptr;
    sounds.m_pStorage = nullptr;
  }
  memset(&soundToGlobal, 0, 20);
  soundToGlobal.m_tStart.m_tms = 0x80000000;
  soundToGlobal.m_tDuration.m_tms = 0x80000000;
  soundToGlobal.m_tOffset.m_tms = 0x80000000;
  soundToGlobal.m_bOptimized = false;
  v5 = 0;
  gc = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)pClip);
  i = 0;
  if ( gc > 0 )
  {
    do
    {
      TrackGroup = CDmeClip::GetTrackGroup(this: pClip, nIndex: v5);
      m_Size = TrackGroup->m_Tracks.m_Storage.m_Size;
      v8 = 0;
      pTrackGroup = TrackGroup;
      _tc = m_Size;
      _i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: TrackGroup->m_Tracks.m_Storage.m_Memory.m_pMemory[v8]);
          v10 = (CDmeTransform *)v9;
          v29 = (CDmeTransform *)v9;
          if ( v9 != nullptr
            && v9->IsA(this: v9, a2: CDmeTrack::m_classType)
            && CDmeTrack::GetClipType(this: (CDmeTrack *)v10) == 1 )
          {
            _cc = (int)CDmeTrack::GetClipCount(this: v10);
            _j = 0;
            if ( _cc > 0 )
            {
              do
              {
                Clip = CDmeTrack::GetClip(this: (CDmeTrack *)v10, i: _j);
                if ( Clip != nullptr )
                {
                  v12 = *(const char **)&g_pDataModel->GetElement(this: g_pDataModel, a2: Clip[1].__vftable)[1].m_Id.m_Value[4];
                  if ( v12 != (const char *)-1
                    && v12 != nullptr
                    && *v12 != 0
                    && !Clip->m_bMute.m_Storage
                    && CDmeClip::BuildClipStack(
                         this: Clip,
                         pStack: &soundToGlobal,
                         pMovie: info->m_pMovie,
                         pShot: pClip) )
                  {
                    DmeClipStack_t::FromChildMediaTime(this: &soundToGlobal, result: &tStart, t: 0, bClamp: false);
                    Duration = CDmeClip::GetDuration(this: Clip, &result);
                    DmeClipStack_t::FromChildMediaTime(
                      this: &soundToGlobal,
                      result: &tEnd,
                      t: (DmeTime_t)Duration->m_tms,
                      bClamp: false);
                    tEnd.m_tms -= tOffset.m_tms;
                    tStart.m_tms -= tOffset.m_tms;
                    if ( tStart.m_tms < info->m_tExportEnd.m_tms && tEnd.m_tms > info->m_tExportStart.m_tms )
                    {
                      m_pAsString = Clip->m_Name.m_Storage.u.m_pAsString;
                      if ( m_pAsString == (const char *)-1 )
                        m_pAsString = &pch;
                      v15 = CreateElement<CDmElement>(
                              pObjectName: m_pAsString,
                              fileid: pRoot->m_fileId,
                              pObjectID: nullptr);
                      v16 = CDmElement::FindAttribute(this: v15, pAttributeName: "start");
                      if ( v16 != nullptr
                        || (v16 = CDmElement::CreateAttribute(this: v15, pAttributeName: "start", type: AT_TIME)) != nullptr )
                      {
                        CDmAttribute::SetValue<DmeTime_t>(this: v16, value: &tStart);
                      }
                      v17 = CDmElement::FindAttribute(this: v15, pAttributeName: "end");
                      if ( v17 != nullptr
                        || (v17 = CDmElement::CreateAttribute(this: v15, pAttributeName: "end", type: AT_TIME)) != nullptr )
                      {
                        CDmAttribute::SetValue<DmeTime_t>(this: v17, value: &tEnd);
                      }
                      g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: v12);
                      v18 = CDmElement::FindAttribute(this: v15, pAttributeName: "gamesound");
                      if ( v18 != nullptr
                        || (v18 = CDmElement::CreateAttribute(this: v15, pAttributeName: "gamesound", type: AT_STRING)) != nullptr )
                      {
                        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v18, &value);
                      }
                      if ( v15 != nullptr )
                        src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v15);
                      else
                        src = DMELEMENT_HANDLE_INVALID;
                      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                        this: &sounds,
                        &src);
                    }
                  }
                  v10 = v29;
                }
                ++_j;
              }
              while ( _j < _cc );
              v8 = _i;
            }
          }
          _i = ++v8;
          if ( v8 >= _tc )
            break;
          TrackGroup = pTrackGroup;
        }
        v5 = i;
      }
      i = ++v5;
    }
    while ( v5 < gc );
  }
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &soundToGlobal.m_clips);
  if ( soundToGlobal.m_clips.m_Memory.m_nGrowSize >= 0 && soundToGlobal.m_clips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: soundToGlobal.m_clips.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00534F30
// Name: ExportSounds_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExportSounds_R(ExportInfo_t *info, CDmElement *pRoot, CDmeClip *pClip, DmeTime_t tOffset)
{
  CDmeClip *v4; // esi
  int v5; // ebx
  CDmeTrackGroup *TrackGroup; // eax
  int m_Size; // ecx
  int v8; // esi
  CDmElement *v9; // eax
  CDmeTransform *v10; // ebx
  CDmeClip *Clip; // esi
  DmeTime_t *Duration; // eax
  DmeClipStack_t childToGlobal; // [esp+Ch] [ebp-58h] BYREF
  DmeTime_t result; // [esp+3Ch] [ebp-28h] BYREF
  int gc; // [esp+40h] [ebp-24h]
  int _tc; // [esp+44h] [ebp-20h]
  int _cc; // [esp+48h] [ebp-1Ch]
  CDmeTrackGroup *pTrackGroup; // [esp+4Ch] [ebp-18h]
  int i; // [esp+50h] [ebp-14h]
  int _i; // [esp+54h] [ebp-10h]
  DmeTime_t tStart; // [esp+58h] [ebp-Ch] BYREF
  int _j; // [esp+5Ch] [ebp-8h]
  DmeTime_t tEnd; // [esp+60h] [ebp-4h] BYREF

  v4 = pClip;
  ExportSounds(info, pRoot, pClip, tOffset);
  v5 = 0;
  memset(&childToGlobal, 0, 20);
  childToGlobal.m_tStart.m_tms = 0x80000000;
  childToGlobal.m_tDuration.m_tms = 0x80000000;
  childToGlobal.m_tOffset.m_tms = 0x80000000;
  childToGlobal.m_bOptimized = false;
  gc = (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)pClip);
  i = 0;
  if ( gc > 0 )
  {
    while ( 1 )
    {
      TrackGroup = CDmeClip::GetTrackGroup(this: v4, nIndex: v5);
      m_Size = TrackGroup->m_Tracks.m_Storage.m_Size;
      v8 = 0;
      pTrackGroup = TrackGroup;
      _tc = m_Size;
      _i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: TrackGroup->m_Tracks.m_Storage.m_Memory.m_pMemory[v8]);
          v10 = (CDmeTransform *)v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTrack::m_classType) )
          {
            _cc = (int)CDmeTrack::GetClipCount(this: v10);
            _j = 0;
            if ( _cc > 0 )
            {
              do
              {
                Clip = CDmeTrack::GetClip(this: (CDmeTrack *)v10, i: _j);
                if ( Clip != nullptr
                  && CDmeClip::BuildClipStack(this: Clip, pStack: &childToGlobal, pMovie: info->m_pMovie, pShot: pClip) )
                {
                  DmeClipStack_t::FromChildMediaTime(this: &childToGlobal, result: &tStart, t: 0, bClamp: false);
                  Duration = CDmeClip::GetDuration(this: Clip, &result);
                  DmeClipStack_t::FromChildMediaTime(
                    this: &childToGlobal,
                    result: &tEnd,
                    t: (DmeTime_t)Duration->m_tms,
                    bClamp: false);
                  tEnd.m_tms -= tOffset.m_tms;
                  tStart.m_tms -= tOffset.m_tms;
                  if ( tStart.m_tms < info->m_tExportEnd.m_tms && tEnd.m_tms > info->m_tExportStart.m_tms )
                    ExportSounds_R(info, pRoot, pClip: Clip, tOffset);
                }
                ++_j;
              }
              while ( _j < _cc );
              v8 = _i;
            }
          }
          _i = ++v8;
          if ( v8 >= _tc )
            break;
          TrackGroup = pTrackGroup;
        }
        v5 = i;
      }
      i = ++v5;
      if ( v5 >= gc )
        break;
      v4 = pClip;
    }
  }
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &childToGlobal.m_clips);
  if ( childToGlobal.m_clips.m_Memory.m_nGrowSize >= 0 && childToGlobal.m_clips.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: childToGlobal.m_clips.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005350F0
// Name: bool ExportFacialAnimation(char const __near *,class CDmeFilmClip __near *,class CDmeFilmClip __near *,class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ExportFacialAnimation(
        const char *pFileName,
        CDmeFilmClip *pMovie,
        CDmeFilmClip *pShot,
        CDmeAnimationSet *pAnimationSet)
{
  CDmeFilmClip *v4; // ebx
  CDmeAnimationSet *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v7; // edi
  CDmeGameModel *Value; // eax
  const char *ModelName; // eax
  bool v10; // bl
  ExportInfo_t info; // [esp+8h] [ebp-14h] BYREF

  if ( pMovie == nullptr )
    return false;
  v4 = pShot;
  if ( pShot == nullptr )
    return false;
  v5 = pAnimationSet;
  if ( pAnimationSet == nullptr )
    return false;
  m_pAsString = pAnimationSet->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pch;
  v7 = CreateElement<CDmElement>(pObjectName: m_pAsString, fileid: DMFILEID_INVALID, pObjectID: nullptr);
  info.m_tExportEnd.m_tms = 0x80000000;
  info.m_pMovie = pMovie;
  info.m_pShot = v4;
  info.m_pAnimationSet = v5;
  info.m_tExportStart.m_tms = 0;
  info.m_tExportEnd = (DmeTime_t)CDmeClip::GetDuration(this: v4, result: (DmeTime_t *)&pMovie)->m_tms;
  Value = CDmElement::GetValueElement<CDmeGameModel>(this: v5, pAttributeName: "gameModel");
  if ( Value != nullptr )
  {
    ModelName = CDmeGameModel::GetModelName(this: Value);
    CDmElement::SetValue<char const>(this: v7, pAttributeName: "gamemodel", pValue: ModelName, bCreateIfNotFound: 1);
  }
  ExportAnimations(pRoot: v7, &info);
  CDmeClip::GetStartTime(this: info.m_pShot, result: (DmeTime_t *)&pMovie);
  ExportSounds(&info, pRoot: v7, pClip: info.m_pMovie, tOffset: (DmeTime_t)pMovie);
  ExportSounds_R(&info, pRoot: v7, pClip: info.m_pShot, tOffset: (DmeTime_t)pMovie);
  CDmElement::SetFileId(this: v7, fileid: DMFILEID_INVALID, depth: TD_DEEP, bOnlyIfMatch: false);
  v10 = g_pDataModel->SaveToFile(
          this: g_pDataModel,
          a2: pFileName,
          a3: nullptr,
          a4: "keyvalues2_flat",
          a5: "facial_animation",
          a6: v7);
  DestroyElement(pElement: (CDmAttribute *)v7, depth: TD_DEEP);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0057FCB0
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x00581760
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x0057FCE0
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0057FD20
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0057FD60
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}
