// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/choreoview.cpp
// Functions: 215
// ============================================================

#include "utils\hlfaceposer\choreoview.h"

//------------------------------------------------------------------------------
// Address: 0x00423370
// Name: public: CSoundParameters::CSoundParameters(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParameters *__thiscall CSoundParameters::CSoundParameters(CSoundParameters *this)
{
  this->pitch = 100;
  this->pitchlow = 100;
  this->pitchhigh = 100;
  this->channel = 0;
  this->volume = 1.0;
  this->soundlevel = SNDLVL_NORM;
  this->soundname[0] = 0;
  this->play_to_owner_only = false;
  this->count = 0;
  this->delay_msec = 0;
  this->m_nSoundEntryVersion = 1;
  this->m_hSoundScriptHandle = -1;
  this->m_pOperatorsKV = nullptr;
  this->m_nRandomSeed = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004233D0
// Name: RescaleExpressionTimes
// Source: json
//------------------------------------------------------------------------------
void __cdecl RescaleExpressionTimes(CChoreoEvent *event, float newstart, float newend)
{
  CChoreoEvent *v3; // edi
  int v4; // esi
  CFlexAnimationTrack *FlexAnimationTrack; // ebx
  int j; // edi
  int k; // esi
  CExpressionSample *Sample; // eax
  float v9; // xmm0_4
  int count; // [esp+4h] [ebp-10h]
  int i; // [esp+Ch] [ebp-8h]
  float dt; // [esp+10h] [ebp-4h]

  v3 = event;
  if ( event != nullptr
    && CChoreoEvent::GetType(this: event) == FLEXANIMATION
    && (newstart != CChoreoEvent::GetStartTime(this: event) || newend != CChoreoEvent::GetEndTime(this: event)) )
  {
    dt = 0.0;
    if ( newstart != CChoreoEvent::GetStartTime(this: event) )
      dt = -(newstart - CChoreoEvent::GetStartTime(this: event));
    v4 = 0;
    count = CChoreoEvent::GetNumFlexAnimationTracks(this: event);
    i = 0;
    if ( count > 0 )
    {
      do
      {
        FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: v3, index: v4);
        if ( FlexAnimationTrack != nullptr )
        {
          for ( j = 0; j < 2; ++j )
          {
            for ( k = CFlexAnimationTrack::GetNumSamples(this: FlexAnimationTrack, type: j) - 1; k >= 0; --k )
            {
              Sample = CFlexAnimationTrack::GetSample(this: FlexAnimationTrack, index: k, type: j);
              if ( Sample != nullptr )
              {
                v9 = Sample->time + dt;
                Sample->time = v9;
                if ( v9 > (float)(newend - newstart) || v9 < 0.0 )
                  CFlexAnimationTrack::RemoveSample(this: FlexAnimationTrack, index: k, type: j);
              }
            }
          }
          v4 = i;
          v3 = event;
        }
        i = ++v4;
      }
      while ( v4 < count );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004234F0
// Name: RescaleRamp
// Source: json
//------------------------------------------------------------------------------
void __usercall RescaleRamp(CChoreoEvent *event@<eax>, float newduration)
{
  double v3; // st7
  signed int NumChannels; // ebx
  int i; // esi
  CExpressionSample *v6; // eax
  float time; // xmm0_4
  float v8; // xmm0_4
  float midpointtime; // [esp+8h] [ebp-8h]
  float oldduration; // [esp+Ch] [ebp-4h]

  v3 = ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event);
  oldduration = v3;
  if ( fabs(v3 - newduration) >= 0.000001 && newduration > 0.0 )
  {
    midpointtime = oldduration * 0.5;
    NumChannels = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&event->m_Ramp);
    for ( i = 0; i < NumChannels; ++i )
    {
      v6 = CCurveData::Get(this: &event->m_Ramp, index: i);
      if ( v6 != nullptr )
      {
        time = v6->time;
        if ( midpointtime <= time )
        {
          if ( (float)(newduration * 0.5) < (float)(oldduration - time) )
            v8 = (float)((float)((float)(time - midpointtime) / midpointtime) + 1.0) * (float)(newduration * 0.5);
          else
            v8 = newduration - (float)(oldduration - time);
          v6->time = v8;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004235C0
// Name: bool DoesAnyActorHaveAssociatedModelLoaded(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoesAnyActorHaveAssociatedModelLoaded(CChoreoScene *scene)
{
  int NumActors; // ebx
  int v3; // esi
  CChoreoActor *Actor; // eax
  char *FacePoserModelName; // eax
  char mdlname[256]; // [esp+4h] [ebp-100h] BYREF

  if ( scene == nullptr )
    return 0;
  NumActors = CChoreoScene::GetNumActors(this: scene);
  v3 = 0;
  if ( NumActors <= 0 )
    return 0;
  while ( 1 )
  {
    Actor = CChoreoScene::GetActor(this: scene, actor: v3);
    if ( Actor != nullptr )
    {
      FacePoserModelName = CChoreoActor::GetFacePoserModelName(this: Actor);
      if ( FacePoserModelName != nullptr && *FacePoserModelName != 0 )
      {
        V_strncpy(pDest: mdlname, pSrc: FacePoserModelName, maxLen: 256);
        V_FixSlashes(pname: mdlname, separator: 92);
        if ( models->FindModelByFilename(this: models, a2: mdlname) >= 0 )
          break;
      }
    }
    if ( ++v3 >= NumActors )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423660
// Name: class StudioModel __near * FindAssociatedModel(class CChoreoScene __near *,class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
StudioModel *__cdecl FindAssociatedModel(CChoreoScene *scene, CChoreoActor *a)
{
  IFaceposerModels_vtbl *v3; // esi
  char *FacePoserModelName; // eax
  int v5; // eax
  int v7; // esi
  const char *v8; // edi
  CChoreoActor *Name; // eax
  int c; // [esp+10h] [ebp+Ch]

  if ( a == nullptr || scene == nullptr )
    return nullptr;
  if ( *CChoreoActor::GetFacePoserModelName(this: a) != 0 )
  {
    v3 = models->__vftable;
    FacePoserModelName = CChoreoActor::GetFacePoserModelName(this: a);
    v5 = v3->FindModelByFilename(this: models, a2: FacePoserModelName);
    if ( v5 >= 0 )
      return models->GetStudioModel(this: models, a2: v5);
  }
  v7 = 0;
  c = models->Count(this: models);
  if ( c <= 0 )
  {
LABEL_9:
    if ( DoesAnyActorHaveAssociatedModelLoaded(scene) != 0 )
      return nullptr;
    else
      return ((StudioModel *(__thiscall *)(IFaceposerModels *, CChoreoScene *, int))models->GetActiveStudioModel)(
               a1: models,
               a2: scene,
               a3: c);
  }
  else
  {
    while ( 1 )
    {
      v8 = models->GetModelName(this: models, a2: v7);
      Name = CChoreoActor::GetName(this: a);
      if ( _V_stricmp(s1: v8, s2: Name->m_szName) == 0 )
        return models->GetStudioModel(this: models, a2: v7);
      if ( ++v7 >= c )
        goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423740
// Name: public: void CChoreoView::ReportSceneClearToTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ReportSceneClearToTools(CChoreoView *this)
{
  CChoreoScene *m_pScene; // ecx

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
    CChoreoScene::ResetSimulation(this: m_pScene, forward: true, starttime: 0.0, endtime: 0.0);
  PhonemeEditor::ClearEvent(this: g_pPhonemeEditor);
  ExpressionTool::LayoutItems(this: g_pExpressionTool, force: true);
  g_pExpressionTool->redraw(this: g_pExpressionTool);
  g_pGestureTool->redraw(this: g_pGestureTool);
  g_pRampTool->redraw(this: g_pRampTool);
  g_pSceneRampTool->redraw(this: g_pSceneRampTool);
}

//------------------------------------------------------------------------------
// Address: 0x004237B0
// Name: float SnapTime(float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SnapTime(float input, float granularity)
{
  return (double)(int)(float)((float)(int)(float)(1.0 / granularity) * (float)(input - (float)(int)input)) * granularity
       + (float)(int)input;
}

//------------------------------------------------------------------------------
// Address: 0x00423800
// Name: private: void CChoreoView::ClearABPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ClearABPoints(CChoreoView *this)
{
  this->m_rgABPoints[0] = 0;
  this->m_rgABPoints[1] = 0;
  this->m_nCurrentABPoint = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423820
// Name: public: bool CChoreoView::IsMouseOverTimeline(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsMouseOverTimeline(CChoreoView *this, unsigned int mx, unsigned int my)
{
  __int64 v3; // xmm0_8
  tagRECT rcCheck; // [esp+0h] [ebp-10h] BYREF

  *(_QWORD *)&rcCheck.left = *(_QWORD *)&this->m_rcTimeLine.left;
  v3 = *(_QWORD *)&this->m_rcTimeLine.right;
  rcCheck.right = this->m_rcTimeLine.right;
  rcCheck.bottom = HIDWORD(v3) - 11;
  return PtInRect(lprc: &rcCheck, pt: (POINT)__PAIR64__(my, mx));
}

//------------------------------------------------------------------------------
// Address: 0x00423870
// Name: public: void CChoreoView::AssociateBSP(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::AssociateBSP(CChoreoView *this)
{
  char mapname[512]; // [esp+4h] [ebp-200h] BYREF

  if ( this->m_pScene != nullptr
    && FacePoser_ShowOpenFileNameDialog(relative: mapname, bufsize: 0x200u, subdir: "maps", wildcard: "*.bsp") )
  {
    CChoreoScene::SetMapname(this: this->m_pScene, name: mapname);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004238D0
// Name: private: bool CChoreoView::IsMouseOverEvent(class CChoreoEventWidget __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsMouseOverEvent(CChoreoView *this, CChoreoEventWidget *ew, int mx, int my)
{
  int v4; // edi
  bool result; // al
  char *Header; // eax
  bool v7; // zf
  CChoreoEventWidget_vtbl *v8; // eax
  int v9; // eax

  v4 = mx - ew->getBounds(this: ew)->left;
  result = false;
  if ( v4 > -5 )
  {
    Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)ew);
    if ( Header == nullptr || !CChoreoEvent::CurveHasEndTime(this: (CChoreoEvent *)Header) )
      return true;
    v7 = ew->GetDurationRightEdge(this: ew) == 0;
    v8 = ew->__vftable;
    v9 = v7
       ? ((int (__fastcall *)(CChoreoEventWidget *))v8->w)(a1: ew)
       : ((int (__fastcall *)(CChoreoEventWidget *))v8->GetDurationRightEdge)(a1: ew);
    if ( v4 <= v9 + 5 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423950
// Name: private: bool CChoreoView::IsMouseOverEventEdge(class CChoreoEventWidget __near *,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsMouseOverEventEdge(
        CChoreoView *this,
        CChoreoEventWidget *ew,
        bool bLeftEdge,
        int mx,
        int my)
{
  int v5; // edi
  char *Header; // eax
  bool v8; // zf
  CChoreoEventWidget_vtbl *v9; // eax
  int v10; // eax

  v5 = mx - ew->getBounds(this: ew)->left;
  Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)ew);
  if ( Header == nullptr || !CChoreoEvent::CurveHasEndTime(this: (CChoreoEvent *)Header) )
    return false;
  if ( v5 > -5 && v5 <= 5 )
    return bLeftEdge;
  v8 = ew->GetDurationRightEdge(this: ew) == 0;
  v9 = ew->__vftable;
  v10 = v8
      ? ((int (__fastcall *)(CChoreoEventWidget *))v9->w)(a1: ew)
      : ((int (__fastcall *)(CChoreoEventWidget *))v9->GetDurationRightEdge)(a1: ew);
  return v5 >= v10 - 5 && v5 <= v10 + 5 && !bLeftEdge;
}

//------------------------------------------------------------------------------
// Address: 0x004239F0
// Name: private: bool CChoreoView::CheckGestureLength(class CChoreoEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::CheckGestureLength(CChoreoView *this, CChoreoEvent *e, bool bCheckOnly)
{
  const char *Name; // eax
  CChoreoScene *SceneFPS; // eax
  StudioModel *AssociatedModel; // eax
  StudioModel *v7; // esi
  CStudioHdr *StudioHdr; // ebx
  float *PoseParameters; // eax
  CChoreoActor *Actor; // [esp-8h] [ebp-Ch]

  if ( e == nullptr )
    return false;
  if ( CChoreoEvent::GetType(this: e) != GESTURE )
  {
    Name = CChoreoEvent::GetName(this: e);
    Con_Printf(fmt: "CheckGestureLength:  called on non-GESTURE event %s\n", Name);
    return false;
  }
  Actor = CChoreoEvent::GetActor(this: e);
  SceneFPS = (CChoreoScene *)CChoreoScene::GetSceneFPS(this: (CChoreoScene *)e);
  AssociatedModel = FindAssociatedModel(scene: SceneFPS, a: Actor);
  v7 = AssociatedModel;
  if ( AssociatedModel == nullptr )
    return false;
  StudioHdr = StudioModel::GetStudioHdr(this: AssociatedModel);
  if ( StudioHdr == nullptr )
    return false;
  PoseParameters = StudioModel::GetPoseParameters(this: v7);
  return UpdateGestureLength(e, pStudioHdr: StudioHdr, pPoseParameters: PoseParameters, bCheckOnly);
}

//------------------------------------------------------------------------------
// Address: 0x00423A80
// Name: private: bool CChoreoView::DefaultGestureLength(class CChoreoEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoView::DefaultGestureLength(CChoreoView *this, CChoreoEvent *e, bool bCheckOnly)
{
  const char *Name; // eax
  CChoreoScene *SceneFPS; // eax
  StudioModel *AssociatedModel; // eax
  StudioModel *v8; // esi
  const char *Parameters; // eax
  int v10; // eax
  char v11; // bl
  double Duration; // st7
  float endtime; // [esp+0h] [ebp-10h]
  CChoreoActor *Actor; // [esp+4h] [ebp-Ch]
  float seqduration; // [esp+18h] [ebp+8h]

  if ( e == nullptr )
    return 0;
  if ( CChoreoEvent::GetType(this: e) != GESTURE )
  {
    Name = CChoreoEvent::GetName(this: e);
    Con_Printf(fmt: "DefaultGestureLength:  called on non-GESTURE event %s\n", Name);
    return 0;
  }
  Actor = CChoreoEvent::GetActor(this: e);
  SceneFPS = (CChoreoScene *)CChoreoScene::GetSceneFPS(this: (CChoreoScene *)e);
  AssociatedModel = FindAssociatedModel(scene: SceneFPS, a: Actor);
  v8 = AssociatedModel;
  if ( AssociatedModel == nullptr )
    return 0;
  if ( StudioModel::GetStudioHdr(this: AssociatedModel) == nullptr )
    return 0;
  Parameters = CChoreoEvent::GetParameters(this: e);
  v10 = StudioModel::LookupSequence(this: v8, szSequence: Parameters);
  if ( v10 < 0 )
    return 0;
  v11 = 0;
  Duration = StudioModel::GetDuration(this: v8, iSequence: v10);
  if ( Duration != 0.0 )
  {
    v11 = 1;
    if ( !bCheckOnly )
    {
      seqduration = Duration;
      endtime = CChoreoEvent::GetStartTime(this: e) + seqduration;
      CChoreoEvent::SetEndTime(this: e, endtime);
    }
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x00423B40
// Name: private: bool CChoreoView::AutoaddGestureKeys(class CChoreoEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::AutoaddGestureKeys(CChoreoView *this, CChoreoEvent *e, bool bCheckOnly)
{
  CChoreoScene *SceneFPS; // eax
  StudioModel *AssociatedModel; // eax
  StudioModel *v6; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v8; // eax
  CStudioHdr *v9; // edi
  float *PoseParameters; // eax
  CChoreoActor *Actor; // [esp-8h] [ebp-Ch]

  if ( e == nullptr )
    return false;
  Actor = CChoreoEvent::GetActor(this: e);
  SceneFPS = (CChoreoScene *)CChoreoScene::GetSceneFPS(this: (CChoreoScene *)e);
  AssociatedModel = FindAssociatedModel(scene: SceneFPS, a: Actor);
  v6 = AssociatedModel;
  if ( AssociatedModel == nullptr )
    return false;
  m_pStudioHdr = AssociatedModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v8 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v6->m_MDLHandle);
    CStudioHdr::Init(this: v6->m_pStudioHdr, pStudioHdr: v8, mdlcache: nullptr);
    m_pStudioHdr = v6->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return false;
  }
  v9 = m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return false;
  PoseParameters = StudioModel::GetPoseParameters(this: v6);
  return AutoAddGestureKeys(e, pStudioHdr: v9, pPoseParameters: PoseParameters, bCheckOnly);
}

//------------------------------------------------------------------------------
// Address: 0x00423BE0
// Name: private: bool CChoreoView::CheckSequenceLength(class CChoreoEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::CheckSequenceLength(CChoreoView *this, CChoreoEvent *e, bool bCheckOnly)
{
  const char *Name; // eax
  CChoreoScene *SceneFPS; // eax
  StudioModel *AssociatedModel; // eax
  StudioModel *v7; // esi
  CStudioHdr *StudioHdr; // ebx
  float *PoseParameters; // eax
  CChoreoActor *Actor; // [esp-8h] [ebp-Ch]

  if ( e == nullptr )
    return false;
  if ( CChoreoEvent::GetType(this: e) != SEQUENCE )
  {
    Name = CChoreoEvent::GetName(this: e);
    Con_Printf(fmt: "CheckSequenceLength:  called on non-SEQUENCE event %s\n", Name);
    return false;
  }
  Actor = CChoreoEvent::GetActor(this: e);
  SceneFPS = (CChoreoScene *)CChoreoScene::GetSceneFPS(this: (CChoreoScene *)e);
  AssociatedModel = FindAssociatedModel(scene: SceneFPS, a: Actor);
  v7 = AssociatedModel;
  if ( AssociatedModel == nullptr )
    return false;
  StudioHdr = StudioModel::GetStudioHdr(this: AssociatedModel);
  if ( StudioHdr == nullptr )
    return false;
  PoseParameters = StudioModel::GetPoseParameters(this: v7);
  return UpdateSequenceLength(e, pStudioHdr: StudioHdr, pPoseParameters: PoseParameters, bCheckOnly, bVerbose: true);
}

//------------------------------------------------------------------------------
// Address: 0x00423C70
// Name: public: void CChoreoView::PauseScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::PauseScene(CChoreoView *this)
{
  if ( this->m_bSimulating )
  {
    this->m_bPaused = true;
    sound->StopAll(this: sound);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423C90
// Name: public: bool CChoreoView::GetTarget(class CChoreoScene __near *,class CChoreoEvent __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoView::GetTarget(
        CChoreoView *this,
        CChoreoScene *scene,
        CChoreoEvent *event,
        Vector *vecTarget,
        QAngle *vecAngle)
{
  CChoreoActor *Actor; // ebx
  StudioModel *AssociatedModel; // esi
  const char *Parameters; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *Mapname; // eax
  IMapEntities_vtbl *v13; // esi
  CChoreoActor *v14; // eax
  IMapEntities_vtbl *v15; // esi
  const char *v16; // eax
  double y; // st7
  CChoreoActor *Name; // [esp-Ch] [ebp-B8h]
  Vector eyeTarget; // [esp+4h] [ebp-A8h] BYREF
  QAngle anglesDummy; // [esp+10h] [ebp-9Ch] BYREF
  matrix3x4_t matrix; // [esp+1Ch] [ebp-90h] BYREF
  QAngle anglesActor; // [esp+4Ch] [ebp-60h] BYREF
  Vector vecForward2; // [esp+58h] [ebp-54h] BYREF
  Vector vecForward; // [esp+64h] [ebp-48h] BYREF
  Vector headTarget; // [esp+70h] [ebp-3Ch] BYREF
  Vector orgActor; // [esp+7Ch] [ebp-30h] BYREF
  Vector orgTarget; // [esp+88h] [ebp-24h] BYREF
  QAngle angles; // [esp+94h] [ebp-18h] BYREF
  Vector delta; // [esp+A0h] [ebp-Ch] BYREF
  CChoreoScene *scenea; // [esp+B4h] [ebp+8h]
  CChoreoEvent *eventa; // [esp+B8h] [ebp+Ch]

  if ( CChoreoEvent::GetActor(this: event) == nullptr )
    return 0;
  Actor = CChoreoEvent::GetActor(this: event);
  AssociatedModel = FindAssociatedModel(scene, a: Actor);
  if ( AssociatedModel == nullptr )
    return 0;
  Name = CChoreoActor::GetName(this: Actor);
  Parameters = CChoreoEvent::GetParameters(this: event);
  if ( _V_stricmp(s1: Parameters, s2: Name->m_szName) == 0 )
  {
    *vecTarget = vec3_origin;
    return 1;
  }
  v10 = CChoreoEvent::GetParameters(this: event);
  if ( _V_stricmp(s1: v10, s2: "player") != 0
    && (v11 = CChoreoEvent::GetParameters(this: event), _V_stricmp(s1: v11, s2: "!player") != 0) )
  {
    eventa = (CChoreoEvent *)mapentities->__vftable;
    Mapname = CChoreoScene::GetMapname(this: scene);
    ((void (__thiscall *)(IMapEntities *, const char *))eventa->__vftable)(a1: mapentities, a2: Mapname);
    if ( CChoreoEvent::GetPitch(this: event) == 0 && CChoreoEvent::GetYaw(this: event) == 0 )
    {
      v13 = mapentities->__vftable;
      v14 = CChoreoActor::GetName(this: Actor);
      if ( v13->LookupOrigin(this: mapentities, a2: v14->m_szName, a3: &orgActor, a4: &anglesActor) )
      {
        v15 = mapentities->__vftable;
        v16 = CChoreoEvent::GetParameters(this: event);
        if ( v15->LookupOrigin(this: mapentities, a2: v16, a3: &orgTarget, a4: &anglesDummy) )
        {
          delta.x = orgTarget.x - orgActor.x;
          delta.y = orgTarget.y - orgActor.y;
          delta.z = orgTarget.z - orgActor.z;
          AngleMatrix(angles: &anglesActor, &matrix);
          VectorIRotate(in1: &delta.x, in2: &matrix, out: &vecTarget->x);
          return 1;
        }
      }
      return 0;
    }
    scenea = (CChoreoScene *)(COERCE_UNSIGNED_INT((float)CChoreoEvent::GetPitch(this: event)) ^ _mask__NegFloat_);
    angles.y = (float)CChoreoEvent::GetYaw(this: event);
    LODWORD(angles.x) = scenea;
    angles.z = 0.0;
    AngleMatrix(angles: &AssociatedModel->m_angles, &matrix);
    delta.x = angles.x * 0.60000002;
    delta.z = angles.z;
    delta.y = angles.y * 0.80000001;
    AngleVectors(&angles, forward: &vecForward);
    AngleVectors(angles: (const QAngle *)&delta, forward: &vecForward2);
    VectorNormalize(vec: &vecForward);
    VectorNormalize(vec: &vecForward2);
    VectorRotate(in1: &vecForward.x, in2: &matrix, out: &eyeTarget.x);
    VectorRotate(in1: &vecForward2.x, in2: &matrix, out: &headTarget.x);
    vecTarget->x = headTarget.x * 150.0;
    vecTarget->y = headTarget.y * 150.0;
    vecTarget->z = headTarget.z * 150.0;
    return 1;
  }
  else
  {
    vecTarget->x = AssociatedModel->m_origin.x;
    y = AssociatedModel->m_origin.y;
    vecTarget->z = 0.0;
    vecTarget->y = y;
    *vecAngle = AssociatedModel->m_angles;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423FB0
// Name: public: void CChoreoView::ProcessFace(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessFace(CChoreoView *this, CChoreoScene *scene, CChoreoEvent *event)
{
  CChoreoActor *Actor; // eax
  Vector vecTarget; // [esp+8h] [ebp-18h] BYREF
  QAngle vecAngle; // [esp+14h] [ebp-Ch] BYREF

  if ( CChoreoEvent::GetActor(this: event) != nullptr )
  {
    Actor = CChoreoEvent::GetActor(this: event);
    if ( FindAssociatedModel(scene, a: Actor) != nullptr )
      CChoreoView::GetTarget(this, scene, event, &vecTarget, &vecAngle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424000
// Name: public: void CChoreoView::ProcessGesture(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessGesture(CChoreoView *this, CChoreoScene *scene, CChoreoEvent *event)
{
  const char *Name; // eax
  CChoreoActor *Actor; // eax
  StudioModel *AssociatedModel; // edi
  CChoreoActor *v7; // ebx
  const char *Parameters; // eax
  CChoreoChannel *Channel; // eax
  int ChannelIndex; // eax
  unsigned int NewAnimationLayer; // ebx
  float t; // [esp+4h] [ebp-14h]
  float ta; // [esp+4h] [ebp-14h]
  float tb; // [esp+4h] [ebp-14h]
  int iSequence; // [esp+14h] [ebp-4h]
  float eventlocaltime; // [esp+24h] [ebp+Ch]
  float eventlocaltimea; // [esp+24h] [ebp+Ch]
  float eventlocaltimeb; // [esp+24h] [ebp+Ch]
  float eventlocaltimec; // [esp+24h] [ebp+Ch]
  float eventlocaltimed; // [esp+24h] [ebp+Ch]
  float eventlocaltimee; // [esp+24h] [ebp+Ch]

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
  {
    Actor = CChoreoEvent::GetActor(this: event);
    AssociatedModel = FindAssociatedModel(scene, a: Actor);
    if ( AssociatedModel != nullptr && CChoreoEvent::GetActor(this: event) != nullptr )
    {
      v7 = CChoreoEvent::GetActor(this: event);
      Parameters = CChoreoEvent::GetParameters(this: event);
      iSequence = StudioModel::LookupSequence(this: AssociatedModel, szSequence: Parameters);
      if ( iSequence >= 0 )
      {
        eventlocaltime = CChoreoScene::GetTime(this: scene);
        eventlocaltimea = eventlocaltime - CChoreoEvent::GetStartTime(this: event);
        t = eventlocaltimea / ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event);
        eventlocaltimeb = CChoreoEvent::GetOriginalPercentageFromPlaybackPercentage(this: event, t);
        eventlocaltimec = ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event) * eventlocaltimeb;
        eventlocaltimed = CChoreoEvent::GetStartTime(this: event) + eventlocaltimec;
        eventlocaltimee = CChoreoEvent::GetCompletion(this: event, time: eventlocaltimed);
        Channel = CChoreoEvent::GetChannel(this: event);
        ChannelIndex = CChoreoActor::FindChannelIndex(this: v7, channel: Channel);
        NewAnimationLayer = StudioModel::GetNewAnimationLayer(this: AssociatedModel, iPriority: ChannelIndex);
        ta = CChoreoScene::GetTime(this: scene);
        tb = CChoreoEvent::GetIntensity(this: event, scenetime: ta);
        StudioModel::SetOverlaySequence(this: AssociatedModel, iLayer: NewAnimationLayer, iSequence, flWeight: tb);
        StudioModel::SetOverlayRate(
          this: AssociatedModel,
          iLayer: NewAnimationLayer,
          flCycle: eventlocaltimee,
          flPlaybackRate: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424140
// Name: public: int CChoreoView::GetMovetoSequence(class CChoreoScene __near *,class CChoreoEvent __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetMovetoSequence(
        CChoreoView *this,
        CChoreoScene *scene,
        CChoreoEvent *event,
        StudioModel *model)
{
  const char *Parameters2; // eax
  char *v5; // esi
  const char *v6; // eax
  char *v7; // esi
  int result; // eax
  char szActName[256]; // [esp+4h] [ebp-100h] BYREF

  if ( CChoreoEvent::GetParameters2(this: event) == nullptr || *CChoreoEvent::GetParameters2(this: event) == 0 )
    return StudioModel::LookupSequence(this: model, szSequence: "walk_all");
  Parameters2 = CChoreoEvent::GetParameters2(this: event);
  v5 = _V_strstr(s1: Parameters2, search: " ");
  if ( v5 != nullptr )
  {
    v6 = CChoreoEvent::GetParameters2(this: event);
    V_strncpy(pDest: szActName, pSrc: v6, maxLen: 256);
    szActName[v5 - CChoreoEvent::GetParameters2(this: event)] = 0;
    v7 = szActName;
  }
  else
  {
    v7 = (char *)CChoreoEvent::GetParameters2(this: event);
  }
  if ( _V_strcmp(s1: v7, s2: "Walk") != 0 )
  {
    if ( _V_strcmp(s1: v7, s2: "Run") != 0 )
    {
      if ( _V_strcmp(s1: v7, s2: "CrouchWalk") == 0 )
        v7 = "ACT_WALK_CROUCH";
    }
    else
    {
      v7 = "ACT_RUN";
    }
  }
  else
  {
    v7 = "ACT_WALK";
  }
  result = StudioModel::LookupActivity(this: model, szActivity: v7);
  if ( result == -1 )
    return StudioModel::LookupSequence(this: model, szSequence: "walk_all");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424250
// Name: public: void CChoreoView::ProcessPause(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessPause(CChoreoView *this, CChoreoScene *scene, CChoreoEvent *event)
{
  char *Parameters; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  long double v9; // st7
  int v10; // [esp-8h] [ebp-Ch]

  if ( this->m_nDragType != 8 )
  {
    if ( this->m_bSimulating )
    {
      this->m_bPaused = true;
      sound->StopAll(this: sound);
    }
    this->m_bAutomated = false;
    this->m_nAutomatedAction = 0;
    this->m_flAutomationDelay = 0.0;
    this->m_flAutomationTime = 0.0;
    v10 = strlen(CChoreoEvent::GetParameters(this: event));
    Parameters = (char *)CChoreoEvent::GetParameters(this: event);
    ParseFromMemory(buffer: Parameters, size: v10);
    if ( tokenprocessor->TokenAvailable(this: tokenprocessor) )
    {
      tokenprocessor->GetToken(this: tokenprocessor, a2: false);
      v5 = (const char *)tokenprocessor->CurrentToken(this: tokenprocessor);
      if ( _V_stricmp(s1: v5, s2: "automate") == 0 && tokenprocessor->TokenAvailable(this: tokenprocessor) )
      {
        tokenprocessor->GetToken(this: tokenprocessor, a2: false);
        v6 = (const char *)tokenprocessor->CurrentToken(this: tokenprocessor);
        if ( _V_stricmp(s1: v6, s2: "Cancel") != 0 )
        {
          v7 = (const char *)tokenprocessor->CurrentToken(this: tokenprocessor);
          if ( _V_stricmp(s1: v7, s2: "Resume") == 0 )
            this->m_nAutomatedAction = 2;
        }
        else
        {
          this->m_nAutomatedAction = 1;
        }
        if ( tokenprocessor->TokenAvailable(this: tokenprocessor) && this->m_nAutomatedAction != 0 )
        {
          tokenprocessor->GetToken(this: tokenprocessor, a2: false);
          v8 = (const char *)tokenprocessor->CurrentToken(this: tokenprocessor);
          v9 = atof(nptr: v8);
          this->m_flAutomationDelay = v9;
          if ( v9 > 0.0 )
          {
            this->m_bAutomated = true;
            this->m_flAutomationTime = 0.0;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004243F0
// Name: public: virtual bool CChoreoView::CheckEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoView::CheckEvent(CChoreoView *this, float currenttime, CChoreoScene *scene, CChoreoEvent *event)
{
  CChoreoActor *Actor; // eax
  CChoreoChannel *Channel; // eax

  if ( event != nullptr && CChoreoEvent::GetActive(this: event) )
  {
    Actor = CChoreoEvent::GetActor(this: event);
    if ( Actor == nullptr || CChoreoActor::GetActive(this: Actor) )
    {
      Channel = CChoreoEvent::GetChannel(this: event);
      if ( Channel == nullptr || CChoreoChannel::GetActive(this: Channel) )
        CChoreoEvent::GetType(this: event);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00424440
// Name: public: void CChoreoView::FinishSimulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::FinishSimulation(CChoreoView *this)
{
  float m_flLastSpeedScale; // xmm0_4

  if ( this->m_bSimulating )
  {
    *(_WORD *)&this->m_bSimulating = 0;
    sound->StopAll(this: sound);
    if ( this->m_bResetSpeedScale )
    {
      m_flLastSpeedScale = this->m_flLastSpeedScale;
      this->m_bResetSpeedScale = false;
      g_viewerSettings.speedScale = m_flLastSpeedScale;
      this->m_flLastSpeedScale = 0.0;
      Con_Printf(fmt: "Resetting speed scale to %f\n", 0.0);
    }
    models->ClearOverlaysSequences(this: models);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004244C0
// Name: public: int CChoreoView::GetLabelWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetLabelWidth(CChoreoView *this)
{
  return this->m_nLabelWidth;
}

//------------------------------------------------------------------------------
// Address: 0x004244D0
// Name: public: int CChoreoView::GetStartRow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetStartRow(CChoreoView *this)
{
  return this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
}

//------------------------------------------------------------------------------
// Address: 0x004244F0
// Name: public: int CChoreoView::GetRowHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetRowHeight(CChoreoView *this)
{
  return this->m_nRowHeight;
}

//------------------------------------------------------------------------------
// Address: 0x00424500
// Name: public: int CChoreoView::GetFontSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetFontSize(CChoreoView *this)
{
  return this->m_nFontSize;
}

//------------------------------------------------------------------------------
// Address: 0x00424510
// Name: public: class CChoreoScene __near * CChoreoView::LoadScene(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoScene *__thiscall CChoreoView::LoadScene(CChoreoView *this, char *filename)
{
  char *v2; // esi
  IChoreoEventCallback *v5; // eax
  char pFullPathBuf[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = filename;
  if ( !V_IsAbsolutePath(pStr: filename) )
  {
    filesystem->RelativePathToFullPath(
      this: filesystem,
      a2: filename,
      a3: "GAME",
      a4: pFullPathBuf,
      a5: 260,
      a6: (PathTypeFilter_t)0,
      a7: nullptr);
    v2 = pFullPathBuf;
  }
  if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v2, a3: nullptr) )
    return nullptr;
  LoadScriptFile(filename: v2, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
  if ( this != nullptr )
    v5 = &this->IChoreoEventCallback;
  else
    v5 = nullptr;
  return ChoreoLoadScene(filename: v2, callback: v5, tokenizer: tokenprocessor, pfn: Con_Printf);
}

//------------------------------------------------------------------------------
// Address: 0x004245B0
// Name: private: bool CChoreoView::FixupSequenceDurations(class CChoreoScene __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CChoreoView::FixupSequenceDurations@<al>(
        CChoreoView *this@<ecx>,
        int a2@<edi>,
        CChoreoScene *scene,
        bool checkonly)
{
  CChoreoScene *v4; // esi
  char v5; // bl
  int NumEvents; // eax
  int v8; // ecx
  CChoreoEvent *Event; // eax
  CChoreoEvent *v10; // esi
  __int32 v11; // eax
  __int32 v12; // eax
  IFacePoserSound_vtbl *v13; // edi
  const char *v14; // eax
  char *v15; // eax
  int v16; // edi
  float v18; // [esp+8h] [ebp-1Ch]
  int c; // [esp+14h] [ebp-10h]
  float endtime; // [esp+18h] [ebp-Ch]
  float endtimea; // [esp+18h] [ebp-Ch]
  float endtimeb; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]

  v4 = scene;
  v5 = 0;
  if ( scene == nullptr )
    return 0;
  NumEvents = CChoreoScene::GetNumEvents(this: (IterateRIFF *)scene);
  v8 = 0;
  c = NumEvents;
  i = 0;
  if ( NumEvents > 0 )
  {
    while ( 1 )
    {
      Event = CChoreoScene::GetEvent(this: v4, event: v8);
      v10 = Event;
      if ( Event != nullptr )
      {
        v11 = CChoreoEvent::GetType(this: Event) - 5;
        if ( v11 != 0 )
        {
          v12 = v11 - 1;
          if ( v12 != 0 )
          {
            if ( v12 == 1 && CChoreoView::CheckSequenceLength(this, e: v10, bCheckOnly: checkonly) )
              v5 = 1;
          }
          else
          {
            if ( CChoreoView::CheckGestureLength(this, e: v10, bCheckOnly: checkonly) )
              v5 = 1;
            if ( CChoreoView::AutoaddGestureKeys(this, e: v10, bCheckOnly: checkonly) )
              v5 = 1;
          }
        }
        else
        {
          v13 = sound->__vftable;
          v14 = FacePoser_TranslateSoundName(event: v10);
          v15 = va(fmt: "sound/%s", v14);
          v16 = (int)v13->LoadSound(this: sound, a2: v15);
          if ( v16 != 0 )
          {
            endtime = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v16 + 36))(a1: v16, a2);
            endtimea = CChoreoEvent::GetStartTime(this: v10) + endtime;
            if ( CChoreoEvent::GetEndTime(this: v10) != endtimea )
            {
              endtimeb = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v16 + 36))(a1: v16);
              v18 = CChoreoEvent::GetStartTime(this: v10) + endtimeb;
              CChoreoEvent::SetEndTime(this: v10, endtime: v18);
              v5 = 1;
            }
            a2 = 1;
            (**(void (__thiscall ***)(int))v16)(a1: v16);
          }
        }
      }
      v8 = i + 1;
      i = v8;
      if ( v8 >= c )
        break;
      v4 = scene;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00424700
// Name: public: virtual void CChoreoView::EndEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::EndEvent(CChoreoView *this, float currenttime, CChoreoScene *scene, CChoreoEvent *event)
{
  CChoreoActor *Actor; // eax
  CChoreoChannel *Channel; // eax
  CChoreoEvent::EVENTTYPE Type; // eax
  CChoreoScene *SubScene; // eax
  CAudioMixer *Mixer; // edi

  if ( event != nullptr && CChoreoEvent::GetActive(this: event) )
  {
    Actor = CChoreoEvent::GetActor(this: event);
    if ( Actor == nullptr || CChoreoActor::GetActive(this: Actor) )
    {
      Channel = CChoreoEvent::GetChannel(this: event);
      if ( Channel == nullptr || CChoreoChannel::GetActive(this: Channel) )
      {
        Type = CChoreoEvent::GetType(this: event);
        if ( Type == SPEAK )
        {
          Mixer = CChoreoEvent::GetMixer(this: event);
          if ( Mixer != nullptr && sound->IsSoundPlaying(this: sound, a2: Mixer) )
            sound->StopSound(this: sound, a2: Mixer);
          CChoreoEvent::SetMixer(this: event, mixer: nullptr);
        }
        else if ( Type == SUBSCENE )
        {
          SubScene = CChoreoEvent::GetSubScene(this: event);
          if ( SubScene != nullptr )
            CChoreoScene::ResetSimulation(this: SubScene, forward: true, starttime: 0.0, endtime: 0.0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004247D0
// Name: public: int CChoreoView::GetTagUnderCursorPos(class CChoreoEventWidget __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetTagUnderCursorPos(CChoreoView *this, CChoreoEventWidget *event, int mx, int my)
{
  int v5; // ebx
  char *Header; // eax
  char *v7; // eax
  CEventAbsoluteTag *RelativeTag; // edi
  tagRECT *v9; // eax
  char *v10; // eax
  __int64 bounds; // [esp+4h] [ebp-10h]

  if ( event == nullptr )
    return -1;
  v5 = 0;
  Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)event);
  if ( CChoreoEvent::GetNumRelativeTags(this: (CChoreoEvent *)Header) <= 0 )
    return -1;
  while ( 1 )
  {
    v7 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)event);
    RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: (CChoreoEvent *)v7, tagnum: v5);
    if ( RelativeTag != nullptr )
    {
      v9 = event->getBounds(this: event);
      bounds = *(_QWORD *)&v9->left;
      if ( (int)abs32(
                  mx
                - (int)(CEventAbsoluteTag::GetPercentage(this: RelativeTag) * (double)(v9->right - (int)bounds) + 0.5)
                - bounds) < 3
        && (int)abs32(my - HIDWORD(bounds)) < 3 )
      {
        break;
      }
    }
    ++v5;
    v10 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)event);
    if ( v5 >= CChoreoEvent::GetNumRelativeTags(this: (CChoreoEvent *)v10) )
      return -1;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004248B0
// Name: public: class CEventAbsoluteTag __near * CChoreoView::GetAbsoluteTagUnderCursorPos(class CChoreoEventWidget __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CEventAbsoluteTag *__thiscall CChoreoView::GetAbsoluteTagUnderCursorPos(
        CChoreoView *this,
        CAudioSourceWave *event,
        int mx,
        int my)
{
  int v6; // ebx
  char *Header; // eax
  char *v9; // eax
  CEventAbsoluteTag *AbsoluteTag; // edi
  tagRECT *v11; // eax
  char *v12; // eax
  __int64 bounds; // [esp+4h] [ebp-14h]
  int i; // [esp+20h] [ebp+8h]

  if ( event == nullptr )
    return nullptr;
  v6 = 0;
  i = 0;
  Header = CAudioSourceWave::GetHeader(this: event);
  if ( CChoreoEvent::GetNumAbsoluteTags(this: (CChoreoEvent *)Header, type: PLAYBACK) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v9 = CAudioSourceWave::GetHeader(this: event);
    AbsoluteTag = CChoreoEvent::GetAbsoluteTag(this: (CChoreoEvent *)v9, type: PLAYBACK, tagnum: v6);
    if ( AbsoluteTag != nullptr )
      break;
LABEL_8:
    i = ++v6;
    v12 = CAudioSourceWave::GetHeader(this: event);
    if ( v6 >= CChoreoEvent::GetNumAbsoluteTags(this: (CChoreoEvent *)v12, type: PLAYBACK) )
      return nullptr;
  }
  v11 = (tagRECT *)((int (__thiscall *)(CAudioSourceWave *))event->__vftable[1].GetOutputData)(a1: event);
  bounds = *(_QWORD *)&v11->left;
  if ( (int)abs32(
              mx
            - (int)(CEventAbsoluteTag::GetPercentage(this: AbsoluteTag) * (double)(v11->right - (int)bounds) + 0.5)
            - bounds) >= 3
    || (int)abs32(my - HIDWORD(bounds)) >= 3 )
  {
    v6 = i;
    goto LABEL_8;
  }
  return AbsoluteTag;
}

//------------------------------------------------------------------------------
// Address: 0x00424990
// Name: public: void CChoreoView::Deselect(class CChoreoWidget __near *,class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::Deselect(CChoreoView *this, CChoreoWidget *widget, CChoreoWidget *param1)
{
  if ( widget->IsSelected(this: widget) )
    widget->SetSelected(this: widget, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004249C0
// Name: public: void CChoreoView::Select(class CChoreoWidget __near *,class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::Select(CChoreoView *this, CChoreoWidget *widget, CChoreoWidget *param1)
{
  if ( widget == param1 && !widget->IsSelected(this: widget) )
    widget->SetSelected(this: widget, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x004249F0
// Name: public: void CChoreoView::SelectAllEvents(class CChoreoWidget __near *,class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SelectAllEvents(CChoreoView *this, CChoreoWidget *widget, CChoreoWidget *param1)
{
  void *v3; // edi
  void *v4; // eax

  v3 = __RTDynamicCast(
         inptr: widget,
         VfDelta: 0,
         SrcType: &CChoreoWidget `RTTI Type Descriptor',
         TargetType: &CChoreoEventWidget `RTTI Type Descriptor',
         isReference: 0);
  v4 = __RTDynamicCast(
         inptr: widget,
         VfDelta: 0,
         SrcType: &CChoreoWidget `RTTI Type Descriptor',
         TargetType: &CChoreoGlobalEventWidget `RTTI Type Descriptor',
         isReference: 0);
  if ( (v3 != nullptr || v4 != nullptr) && !widget->IsSelected(this: widget) )
    widget->SetSelected(this: widget, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00424A50
// Name: public: bool CChoreoView::IsPlayingScene(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsPlayingScene(CChoreoView *this)
{
  return this->m_bSimulating;
}

//------------------------------------------------------------------------------
// Address: 0x00424A60
// Name: public: int CChoreoView::GetEndRow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetEndRow(CChoreoView *this)
{
  HWND Handle; // eax
  tagRECT rcClient; // [esp+4h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rcClient);
  return rcClient.bottom - this->m_nInfoHeight - this->m_nScrollbarHeight;
}

//------------------------------------------------------------------------------
// Address: 0x00424A90
// Name: public: void CChoreoView::OnGestureTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnGestureTool(CChoreoView *this)
{
  char *Header; // eax
  char *v3; // eax

  Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedEvent);
  if ( CChoreoEvent::GetType(this: (CChoreoEvent *)Header) == GESTURE )
  {
    v3 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedEvent);
    GestureTool::SetEvent(this: g_pGestureTool, event: (CChoreoEvent *)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424AD0
// Name: public: void CChoreoView::OnExpressionTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnExpressionTool(CChoreoView *this)
{
  char *Header; // eax
  char *v3; // eax

  Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedEvent);
  if ( CChoreoEvent::GetType(this: (CChoreoEvent *)Header) == FLEXANIMATION )
  {
    v3 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedEvent);
    ExpressionTool::SetEvent(this: g_pExpressionTool, event: (CChoreoEvent *)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424B10
// Name: public: class CChoreoScene __near * CChoreoView::GetScene(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoScene *__thiscall CChoreoView::GetScene(CChoreoView *this)
{
  return this->m_pScene;
}

//------------------------------------------------------------------------------
// Address: 0x00424B20
// Name: public: virtual bool CChoreoView::IsProcessing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsProcessing(CChoreoView *this)
{
  return LODWORD(this->m_rgABPoints[1].time) != 0
      && *(float *)&this->m_nClickedX != *(float *)&this->m_nClickedChannelCloseCaptionButton;
}

//------------------------------------------------------------------------------
// Address: 0x00424B50
// Name: public: bool CChoreoView::ShouldProcessSpeak(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::ShouldProcessSpeak(CChoreoView *this)
{
  bool result; // al

  if ( ControlPanel::AllToolsDriveSpeech(this: g_pControlPanel) )
    return IFacePoserToolWindow::IsAnyToolScrubbing() || IFacePoserToolWindow::IsAnyToolProcessing();
  result = IFacePoserToolWindow::IsActiveTool(this: &this->IFacePoserToolWindow);
  if ( result )
    return IFacePoserToolWindow::IsAnyToolScrubbing() || IFacePoserToolWindow::IsAnyToolProcessing();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424B90
// Name: public: void CChoreoView::ProcessSubscene(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessSubscene(CChoreoView *this, CChoreoScene *scene, CChoreoEvent *event)
{
  CChoreoScene *SubScene; // eax
  CChoreoScene *v5; // esi

  SubScene = CChoreoEvent::GetSubScene(this: event);
  v5 = SubScene;
  if ( SubScene != nullptr && !CChoreoScene::SimulationFinished(this: SubScene) )
    CChoreoScene::Think(this: v5, curtime: this->m_flScrub);
}

//------------------------------------------------------------------------------
// Address: 0x00424BD0
// Name: private: void CChoreoView::PositionControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::PositionControls(CChoreoView *this)
{
  int v2; // edi

  v2 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 29;
  mxWidget::setBounds(this: this->m_btnPlay, x: 2, y: v2, w: 16, h: 16);
  mxWidget::setBounds(this: this->m_btnPause, x: 20, y: v2, w: 16, h: 16);
  mxWidget::setBounds(this: this->m_btnStop, x: 38, y: v2, w: 16, h: 16);
  mxWidget::setBounds(this: this->m_pPlaybackRate, x: 56, y: v2, w: 100, h: 16);
}

//------------------------------------------------------------------------------
// Address: 0x00424C30
// Name: public: void CChoreoView::SetChoreoFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetChoreoFile(CChoreoView *this, const char *filename)
{
  const char *v2; // eax
  char *m_szChoreoFile; // esi
  int v5; // edx
  char v6; // cl
  char sz[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = filename;
  m_szChoreoFile = this->m_szChoreoFile;
  v5 = this->m_szChoreoFile - filename;
  do
  {
    v6 = *v2;
    v2[v5] = *v2;
    ++v2;
  }
  while ( v6 != 0 );
  if ( *m_szChoreoFile != 0 )
  {
    if ( IsFileWriteable(filename: m_szChoreoFile) )
      V_snprintf(pDest: sz, maxLen: 256, pFormat: " - %s", m_szChoreoFile);
    else
      V_snprintf(pDest: sz, maxLen: 256, pFormat: " - %s [Read-Only]", m_szChoreoFile);
    IFacePoserToolWindow::SetSuffix(this: &this->IFacePoserToolWindow, suffix: sz);
  }
  else
  {
    IFacePoserToolWindow::SetSuffix(this: &this->IFacePoserToolWindow, suffix: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424CF0
// Name: public: char const __near * CChoreoView::GetChoreoFile(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoView::GetChoreoFile(CChoreoView *this)
{
  return this->m_szChoreoFile;
}

//------------------------------------------------------------------------------
// Address: 0x00424D00
// Name: public: bool CChoreoView::IsMouseOverScrubArea(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsMouseOverScrubArea(CChoreoView *this, mxEvent *event)
{
  int v3; // eax
  POINT v5; // [esp-8h] [ebp-1Ch]
  tagRECT rcArea; // [esp+4h] [ebp-10h] BYREF

  rcArea.left = 0;
  rcArea.right = mxWidget::w2(this);
  v3 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  rcArea.top = v3 + 2;
  rcArea.bottom = v3 + 13;
  InflateRect(lprc: &rcArea, dx: 2, dy: 2);
  v5.y = SLOWORD(event->y);
  v5.x = SLOWORD(event->x);
  return PtInRect(lprc: &rcArea, pt: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00424D60
// Name: public: virtual bool CChoreoView::IsScrubbing(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsScrubbing(CChoreoView *this)
{
  return this->m_FocusRects.m_Memory.m_nGrowSize == 8;
}

//------------------------------------------------------------------------------
// Address: 0x00424D70
// Name: public: void CChoreoView::SetScrubTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetScrubTime(CChoreoView *this, float t)
{
  this->m_flScrub = t;
  this->m_bPaused = false;
}

//------------------------------------------------------------------------------
// Address: 0x00424D90
// Name: public: void CChoreoView::SetScrubTargetTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetScrubTargetTime(CChoreoView *this, float t)
{
  this->m_flScrubTarget = t;
  this->m_bPaused = false;
}

//------------------------------------------------------------------------------
// Address: 0x00424DB0
// Name: private: void CChoreoView::InvalidateTrackLookup_R(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::InvalidateTrackLookup_R(CChoreoView *this, CChoreoScene *scene)
{
  signed int NumEvents; // ebx
  int i; // edi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v5; // esi
  __int32 v6; // eax
  CChoreoScene *SubScene; // eax

  NumEvents = CChoreoScene::GetNumEvents(this: (IterateRIFF *)scene);
  for ( i = 0; i < NumEvents; ++i )
  {
    Event = CChoreoScene::GetEvent(this: scene, event: i);
    v5 = Event;
    if ( Event != nullptr )
    {
      v6 = CChoreoEvent::GetType(this: Event) - 10;
      if ( v6 != 0 )
      {
        if ( v6 == 1 )
        {
          SubScene = CChoreoEvent::GetSubScene(this: v5);
          if ( SubScene != nullptr )
            CChoreoView::InvalidateTrackLookup_R(this, scene: SubScene);
        }
      }
      else
      {
        CChoreoEvent::SetTrackLookupSet(this: v5, set: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424E20
// Name: public: bool CChoreoView::IsRampOnly(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsRampOnly(CChoreoView *this)
{
  return this->m_bRampOnly;
}

//------------------------------------------------------------------------------
// Address: 0x00424E30
// Name: public: int CChoreoView::GetTimeZoom(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetTimeZoom(CChoreoView *this, const char *tool)
{
  CChoreoScene *m_pScene; // ecx

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
    return CChoreoScene::GetTimeZoom(this: m_pScene, tool);
  else
    return 100;
}

//------------------------------------------------------------------------------
// Address: 0x00424E50
// Name: private: void CChoreoView::CheckInsertTime(class CChoreoEvent __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::CheckInsertTime(
        CChoreoView *this,
        CChoreoEvent *e,
        float dt,
        float starttime,
        float endtime)
{
  double v7; // st7
  CChoreoEvent::EVENTTYPE Type; // eax
  __int32 v9; // eax
  __int32 v10; // eax
  IFacePoserSound_vtbl *v11; // edi
  const char *v12; // eax
  char *v13; // eax
  int v14; // edi
  float v15; // [esp+0h] [ebp-14h]
  float newstart; // [esp+4h] [ebp-10h]
  float newstarta; // [esp+4h] [ebp-10h]
  float newend; // [esp+8h] [ebp-Ch]
  float newenda; // [esp+8h] [ebp-Ch]
  float eventend; // [esp+1Ch] [ebp+8h]
  float dta; // [esp+20h] [ebp+Ch]
  float newduration; // [esp+24h] [ebp+10h]

  if ( CChoreoEvent::CurveHasEndTime(this: e) )
    v7 = CChoreoEvent::GetEndTime(this: e);
  else
    v7 = CChoreoEvent::GetStartTime(this: e);
  eventend = v7;
  if ( starttime <= eventend )
  {
    if ( CChoreoEvent::GetStartTime(this: e) <= (double)starttime )
    {
      if ( !CChoreoEvent::IsFixedLength(this: e) && CChoreoEvent::CurveHasEndTime(this: e) )
      {
        newduration = ((double (__thiscall *)(CChoreoEvent *))e->GetDuration)(a1: e) + dt;
        RescaleRamp(event: e, newduration);
        Type = CChoreoEvent::GetType(this: e);
        if ( Type == GESTURE )
        {
          newstarta = CChoreoEvent::GetEndTime(this: e) + dt;
          v15 = CChoreoEvent::GetStartTime(this: e);
          CChoreoEvent::RescaleGestureTimes(
            this: e,
            newstart: v15,
            newend: newstarta,
            bMaintainAbsoluteTagPositions: true);
        }
        else if ( Type == FLEXANIMATION )
        {
          newend = CChoreoEvent::GetEndTime(this: e) + dt;
          newstart = CChoreoEvent::GetStartTime(this: e);
          RescaleExpressionTimes(event: e, newstart, newend);
        }
        CChoreoEvent::OffsetEndTime(this: e, dt);
        CChoreoEvent::SnapTimes(this: e);
        CCurveData::Resort(this: &e->m_Ramp, data: e);
      }
    }
    else
    {
      CChoreoEvent::OffsetTime(this: e, dt);
      CChoreoEvent::SnapTimes(this: e);
    }
    v9 = CChoreoEvent::GetType(this: e) - 5;
    if ( v9 != 0 )
    {
      v10 = v9 - 1;
      if ( v10 != 0 )
      {
        if ( v10 == 1 )
          CChoreoView::CheckSequenceLength(this, e, bCheckOnly: false);
      }
      else
      {
        CChoreoView::CheckGestureLength(this, e, bCheckOnly: false);
      }
    }
    else
    {
      v11 = sound->__vftable;
      v12 = FacePoser_TranslateSoundName(event: e);
      v13 = va(fmt: "sound/%s", v12);
      v14 = (int)v11->LoadSound(this: sound, a2: v13);
      if ( v14 != 0 )
      {
        dta = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v14 + 36))(a1: v14);
        newenda = CChoreoEvent::GetStartTime(this: e) + dta;
        CChoreoEvent::SetEndTime(this: e, endtime: newenda);
        (**(void (__thiscall ***)(int, int))v14)(a1: v14, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425000
// Name: private: void CChoreoView::CheckDeleteTime(class CChoreoEvent __near *,float,float,float,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::CheckDeleteTime(
        CChoreoView *this,
        CChoreoEvent *e,
        float dt,
        float starttime,
        float endtime,
        bool *deleteEvent)
{
  double v8; // st7
  double v9; // st7
  float v10; // xmm0_4
  double v11; // st7
  float v12; // xmm0_4
  double v13; // st7
  CChoreoEvent::EVENTTYPE Type; // eax
  __int32 v15; // eax
  __int32 v16; // eax
  IFacePoserSound_vtbl *v17; // edi
  const char *v18; // eax
  char *v19; // eax
  int v20; // edi
  float v21; // [esp+0h] [ebp-18h]
  float newstart; // [esp+4h] [ebp-14h]
  float newstarta; // [esp+4h] [ebp-14h]
  float dta; // [esp+8h] [ebp-10h]
  float dtb; // [esp+8h] [ebp-10h]
  float newduration; // [esp+24h] [ebp+Ch]
  float maxoffset; // [esp+28h] [ebp+10h]
  float maxoffseta; // [esp+28h] [ebp+10h]
  float maxoffsetb; // [esp+28h] [ebp+10h]
  float eventend; // [esp+30h] [ebp+18h]

  *deleteEvent = false;
  if ( CChoreoEvent::CurveHasEndTime(this: e) )
    v8 = CChoreoEvent::GetEndTime(this: e);
  else
    v8 = CChoreoEvent::GetStartTime(this: e);
  eventend = v8;
  if ( starttime <= eventend )
  {
    if ( CChoreoEvent::GetStartTime(this: e) <= (double)starttime )
    {
      if ( !CChoreoEvent::IsFixedLength(this: e) && CChoreoEvent::CurveHasEndTime(this: e) )
      {
        v11 = CChoreoEvent::GetEndTime(this: e) - starttime;
        if ( v11 <= dt )
        {
          maxoffseta = v11;
          v12 = maxoffseta;
        }
        else
        {
          v12 = dt;
        }
        v13 = ((double (__thiscall *)(CChoreoEvent *))e->GetDuration)(a1: e) - v12;
        if ( v13 <= 0.0 )
          goto LABEL_8;
        newduration = v13;
        RescaleRamp(event: e, newduration);
        Type = CChoreoEvent::GetType(this: e);
        if ( Type == GESTURE )
        {
          newstarta = CChoreoEvent::GetEndTime(this: e) - v12;
          v21 = CChoreoEvent::GetStartTime(this: e);
          CChoreoEvent::RescaleGestureTimes(
            this: e,
            newstart: v21,
            newend: newstarta,
            bMaintainAbsoluteTagPositions: true);
        }
        else if ( Type == FLEXANIMATION )
        {
          dta = CChoreoEvent::GetEndTime(this: e) - v12;
          newstart = CChoreoEvent::GetStartTime(this: e);
          RescaleExpressionTimes(event: e, newstart, newend: dta);
        }
        CChoreoEvent::OffsetEndTime(this: e, dt: COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_));
        CChoreoEvent::SnapTimes(this: e);
        CCurveData::Resort(this: &e->m_Ramp, data: e);
      }
    }
    else
    {
      if ( !CChoreoEvent::CurveHasEndTime(this: e) && (double)endtime > CChoreoEvent::GetStartTime(this: e) )
      {
LABEL_8:
        *deleteEvent = true;
        return;
      }
      v9 = CChoreoEvent::GetStartTime(this: e) - starttime;
      if ( v9 <= dt )
      {
        maxoffset = v9;
        v10 = maxoffset;
      }
      else
      {
        v10 = dt;
      }
      CChoreoEvent::OffsetTime(this: e, dt: COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_));
      CChoreoEvent::SnapTimes(this: e);
    }
    v15 = CChoreoEvent::GetType(this: e) - 5;
    if ( v15 != 0 )
    {
      v16 = v15 - 1;
      if ( v16 != 0 )
      {
        if ( v16 == 1 )
          CChoreoView::CheckSequenceLength(this, e, bCheckOnly: false);
      }
      else
      {
        CChoreoView::CheckGestureLength(this, e, bCheckOnly: false);
      }
    }
    else
    {
      v17 = sound->__vftable;
      v18 = FacePoser_TranslateSoundName(event: e);
      v19 = va(fmt: "sound/%s", v18);
      v20 = (int)v17->LoadSound(this: sound, a2: v19);
      if ( v20 != 0 )
      {
        maxoffsetb = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v20 + 36))(a1: v20);
        dtb = CChoreoEvent::GetStartTime(this: e) + maxoffsetb;
        CChoreoEvent::SetEndTime(this: e, endtime: dtb);
        (**(void (__thiscall ***)(int, int))v20)(a1: v20, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425240
// Name: public: virtual void CChoreoView::OnModelChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnModelChanged(CChoreoView *this)
{
  float time; // eax
  CChoreoView *v2; // ecx

  time = this->m_rgABPoints[1].time;
  v2 = (CChoreoView *)((char *)this - 12);
  if ( time != 0.0 )
    CChoreoView::InvalidateTrackLookup_R(this: v2, scene: (CChoreoScene *)LODWORD(time));
}

//------------------------------------------------------------------------------
// Address: 0x00425260
// Name: public: bool CChoreoView::GetShowCloseCaptionData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::GetShowCloseCaptionData(CChoreoView *this)
{
  return this->m_bShowCloseCaptionData;
}

//------------------------------------------------------------------------------
// Address: 0x004252B0
// Name: public: void CChoreoView::StopScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::StopScene(CChoreoView *this)
{
  double m_flScrub; // st7

  m_flScrub = this->m_flScrub;
  this->m_bPaused = false;
  this->m_flScrubTarget = m_flScrub;
  CChoreoView::FinishSimulation(this);
  sound->Flush(this: sound);
}

//------------------------------------------------------------------------------
// Address: 0x004252E0
// Name: public: void CChoreoView::SelectInActor(class CChoreoWidget __near *,class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SelectInActor(CChoreoView *this, CChoreoWidget *widget, CChoreoWidget *param1)
{
  CAudioSourceWave *v3; // esi
  char *Header; // eax
  CChoreoChannel *Channel; // eax
  CChoreoActor *Actor; // esi
  TimelineItem *v7; // eax

  v3 = (CAudioSourceWave *)__RTDynamicCast(
                             inptr: widget,
                             VfDelta: 0,
                             SrcType: &CChoreoWidget `RTTI Type Descriptor',
                             TargetType: &CChoreoEventWidget `RTTI Type Descriptor',
                             isReference: 0);
  if ( v3 != nullptr && !v3->IsLooped(this: v3) )
  {
    Header = CAudioSourceWave::GetHeader(this: v3);
    Channel = CChoreoEvent::GetChannel(this: (CChoreoEvent *)Header);
    if ( Channel != nullptr )
    {
      Actor = CChoreoChannel::GetActor(this: Channel);
      if ( Actor != nullptr )
      {
        v7 = (TimelineItem *)__RTDynamicCast(
                               inptr: param1,
                               VfDelta: 0,
                               SrcType: &CChoreoWidget `RTTI Type Descriptor',
                               TargetType: &CChoreoActorWidget `RTTI Type Descriptor',
                               isReference: 0);
        if ( v7 != nullptr && (CChoreoActor *)CActorBitmapButton::GetActor(this: v7) == Actor )
          widget->SetSelected(this: widget, a2: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425370
// Name: public: void CChoreoView::SelectInChannel(class CChoreoWidget __near *,class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SelectInChannel(CChoreoView *this, CChoreoWidget *widget, CChoreoWidget *param1)
{
  CAudioSourceWave *v3; // esi
  char *Header; // eax
  char *Channel; // esi
  CAudioSourceWave *v6; // eax

  v3 = (CAudioSourceWave *)__RTDynamicCast(
                             inptr: widget,
                             VfDelta: 0,
                             SrcType: &CChoreoWidget `RTTI Type Descriptor',
                             TargetType: &CChoreoEventWidget `RTTI Type Descriptor',
                             isReference: 0);
  if ( v3 != nullptr && !v3->IsLooped(this: v3) )
  {
    Header = CAudioSourceWave::GetHeader(this: v3);
    Channel = (char *)CChoreoEvent::GetChannel(this: (CChoreoEvent *)Header);
    if ( Channel != nullptr )
    {
      v6 = (CAudioSourceWave *)__RTDynamicCast(
                                 inptr: param1,
                                 VfDelta: 0,
                                 SrcType: &CChoreoWidget `RTTI Type Descriptor',
                                 TargetType: &CChoreoChannelWidget `RTTI Type Descriptor',
                                 isReference: 0);
      if ( v6 != nullptr && CAudioSourceWave::GetHeader(this: v6) == Channel )
        widget->SetSelected(this: widget, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004253F0
// Name: public: void CChoreoView::SetScrubUnitSeconds(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetScrubUnitSeconds(CChoreoView *this, bool bUseSeconds)
{
  CChoreoView_vtbl *v2; // edx

  v2 = this->mxWindow::mxWidget::__vftable;
  this->m_bScrubSeconds = bUseSeconds;
  ((void (*)(void))v2->redraw)();
}

//------------------------------------------------------------------------------
// Address: 0x00425410
// Name: float clamp<float,double,double>(float const __near &,double const __near &,double const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,double,double>(float *val, const long double *minVal, const long double *maxVal)
{
  float vala; // [esp+10h] [ebp+8h]

  vala = *val;
  if ( *(double *)minVal > vala )
    return *(double *)minVal;
  if ( vala <= *(double *)maxVal )
    return vala;
  return *(double *)maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x00425470
// Name: public: void CChoreoView::DrawTimeLine(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DrawTimeLine(CChoreoView *this, int drawHelper, tagRECT *rc, float left, float right)
{
  CChoreoWidgetDrawHelper *v5; // ebx
  __int64 v7; // xmm0_8
  const char *Name; // eax
  CChoreoScene *m_pScene; // ecx
  int TimeZoom; // eax
  float v11; // xmm1_4
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // eax
  float v13; // edx
  IFacePoserToolWindow_vtbl *v14; // eax
  int v15; // eax
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  IFacePoserToolWindow_vtbl *v22; // eax
  int v23; // eax
  int m_nStartRow; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // [esp-8h] [ebp-70h]
  int v28; // [esp-4h] [ebp-6Ch]
  int v29; // [esp+0h] [ebp-68h]
  char sz[32]; // [esp+14h] [ebp-54h] BYREF
  tagRECT rcFill; // [esp+34h] [ebp-34h] BYREF
  tagRECT rcLabel; // [esp+44h] [ebp-24h] BYREF
  float v33; // [esp+54h] [ebp-14h]
  int y1; // [esp+58h] [ebp-10h]
  float granularity; // [esp+5Ch] [ebp-Ch]
  float f; // [esp+60h] [ebp-8h]
  Color clr; // [esp+64h] [ebp-4h] BYREF

  v5 = (CChoreoWidgetDrawHelper *)drawHelper;
  *(_QWORD *)&rcFill.left = *(_QWORD *)&this->m_rcTimeLine.left;
  v7 = *(_QWORD *)&this->m_rcTimeLine.right;
  rcFill.right = this->m_rcTimeLine.right;
  rcFill.bottom = HIDWORD(v7) - 11;
  clr = (Color)13166310;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: (CChoreoWidgetDrawHelper *)drawHelper, &clr, rc: &rcFill);
  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
    TimeZoom = CChoreoScene::GetTimeZoom(this: m_pScene, tool: Name);
  else
    TimeZoom = 100;
  v11 = (float)TimeZoom * 0.0099999998;
  GetCaptionHeight = this->GetCaptionHeight;
  granularity = 0.25 / v11;
  LODWORD(v13) = GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
  v14 = this->IFacePoserToolWindow::__vftable;
  f = v13;
  v15 = v14->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  v29 = rc->right;
  v28 = v15 + this->m_nStartRow + 14;
  v27 = rc->left;
  drawHelper = 8331039;
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: v5,
    clr: (HPEN__ *)&drawHelper,
    style: 0,
    width: 1,
    x1: v27,
    y1: v28,
    x2: v29,
    y2: LODWORD(f) - 1);
  v16 = granularity;
  v17 = left;
  v18 = right;
  v19 = (float)((float)(int)(float)((float)(int)(float)(1.0 / granularity) * (float)(left - (float)(int)left))
              * granularity)
      + (float)(int)left;
  f = v19;
  if ( right > v19 )
  {
    v20 = right - left;
    v33 = right - left;
    do
    {
      v21 = (float)(v19 - v17) / v20;
      if ( v21 >= 0.0 && v21 <= 1.0 )
      {
        v22 = this->IFacePoserToolWindow::__vftable;
        rcLabel.left = this->m_nLabelWidth + (int)(float)((float)(rc->right - this->m_nLabelWidth) * v21);
        v23 = v22->GetCaptionHeight(this: &this->IFacePoserToolWindow);
        m_nStartRow = this->m_nStartRow;
        rcLabel.bottom = v23 + m_nStartRow + 14;
        rcLabel.top = v23 + m_nStartRow + 4;
        if ( f != left )
        {
          y1 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
          drawHelper = 15785180;
          v25 = mxWidget::h2(this);
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: v5,
            clr: (HPEN__ *)&drawHelper,
            style: 2,
            width: 1,
            x1: rcLabel.left,
            y1,
            x2: rcLabel.left,
            y2: v25);
        }
        sprintf(string: sz, format: "%.2f", f);
        v26 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
        rcLabel.right = v26 + rcLabel.left;
        OffsetRect(lprc: &rcLabel, dx: v26 / -2, dy: 0);
        clr = 0;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: v5,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          &clr,
          rcText: &rcLabel,
          fmt: sz);
        v16 = granularity;
        v17 = left;
        v19 = f;
        v18 = right;
        v20 = v33;
      }
      v19 = v19 + v16;
      f = v19;
    }
    while ( v18 > v19 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425720
// Name: public: void CChoreoView::GetUndoLevels(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::GetUndoLevels(CChoreoView *this, int *current, int *number)
{
  *current = this->m_nUndoLevel;
  *number = this->m_UndoStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00425740
// Name: public: int CChoreoView::GetPixelForTimeValue(float,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetPixelForTimeValue(CChoreoView *this, float time, bool *clipped)
{
  float v3; // xmm0_4
  int m_nLabelWidth; // esi

  if ( clipped != nullptr )
    *clipped = false;
  v3 = (float)(time - this->m_flStartTime) / (float)(this->m_flEndTime - this->m_flStartTime);
  if ( (v3 < 0.0 || v3 > 1.0) && clipped != nullptr )
    *clipped = true;
  m_nLabelWidth = this->m_nLabelWidth;
  return m_nLabelWidth + (int)(float)((float)(mxWidget::w2(this) - m_nLabelWidth) * v3);
}

//------------------------------------------------------------------------------
// Address: 0x004257B0
// Name: public: float CChoreoView::GetTimeValueForMouse(int,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CChoreoView::GetTimeValueForMouse(CChoreoView *this, int mx, bool clip)
{
  int m_nLabelWidth; // edx
  signed int v4; // xmm0_4

  m_nLabelWidth = this->m_nLabelWidth;
  v4 = _mm_loadl_epi64((const __m128i *)&this->m_rcTimeLine.right).m128i_u32[0];
  if ( !clip )
    return this->m_flStartTime
         + (double)(mx - m_nLabelWidth) / (double)(v4 - m_nLabelWidth) * (this->m_flEndTime - this->m_flStartTime);
  if ( mx < m_nLabelWidth )
    return this->m_flStartTime;
  if ( mx > v4 )
    return this->m_flEndTime;
  else
    return this->m_flStartTime
         + (double)(mx - m_nLabelWidth) / (double)(v4 - m_nLabelWidth) * (this->m_flEndTime - this->m_flStartTime);
}

//------------------------------------------------------------------------------
// Address: 0x00425830
// Name: public: float CChoreoView::GetPixelsPerSecond(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CChoreoView::GetPixelsPerSecond(CChoreoView *this)
{
  const char *Name; // eax
  CChoreoScene *m_pScene; // ecx
  double v4; // st7

  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
    v4 = (double)CChoreoScene::GetTimeZoom(this: m_pScene, tool: Name) * this->m_flPixelsPerSecond;
  else
    v4 = (double)100 * this->m_flPixelsPerSecond;
  return v4 * 0.0099999998;
}

//------------------------------------------------------------------------------
// Address: 0x00425890
// Name: public: float CChoreoView::GetTimeDeltaForMouseDelta(int,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CChoreoView::GetTimeDeltaForMouseDelta(CChoreoView *this, int mx, int origmx)
{
  int m_nLabelWidth; // eax

  m_nLabelWidth = this->m_nLabelWidth;
  return (float)((float)((float)((float)(mx - m_nLabelWidth) / (float)(this->m_rcTimeLine.right - m_nLabelWidth))
                       * (float)(this->m_flEndTime - this->m_flStartTime))
               + this->m_flStartTime)
       - (float)((float)((float)((float)(origmx - m_nLabelWidth) / (float)(this->m_rcTimeLine.right - m_nLabelWidth))
                       * (float)(this->m_flEndTime - this->m_flStartTime))
               + this->m_flStartTime);
}

//------------------------------------------------------------------------------
// Address: 0x00425960
// Name: private: void CChoreoView::PlaceABPoint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::PlaceABPoint(CChoreoView *this, int mx)
{
  float time; // xmm0_4
  float v3; // xmm1_4

  this->m_rgABPoints[this->m_nCurrentABPoint & 1].time = (float)((float)((float)(mx - this->m_nLabelWidth)
                                                                       / (float)(this->m_rcTimeLine.right
                                                                               - this->m_nLabelWidth))
                                                               * (float)(this->m_flEndTime - this->m_flStartTime))
                                                       + this->m_flStartTime;
  this->m_rgABPoints[this->m_nCurrentABPoint++ & 1].active = true;
  if ( this->m_rgABPoints[0].active && this->m_rgABPoints[1].active )
  {
    time = this->m_rgABPoints[0].time;
    v3 = this->m_rgABPoints[1].time;
    if ( time > v3 )
    {
      this->m_rgABPoints[0].time = v3;
      this->m_rgABPoints[1].time = time;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425A30
// Name: private: bool CChoreoView::IsMouseOverSceneEndTime(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::IsMouseOverSceneEndTime(CChoreoView *this, int mx)
{
  CChoreoScene *m_pScene; // ecx
  float v4; // xmm0_4
  char v5; // bl
  int m_nLabelWidth; // edi
  int v7; // ecx
  float endtime; // [esp+4h] [ebp-4h]

  m_pScene = this->m_pScene;
  if ( m_pScene == nullptr )
    return false;
  endtime = CChoreoScene::FindStopTime(this: m_pScene);
  v4 = (float)(endtime - this->m_flStartTime) / (float)(this->m_flEndTime - this->m_flStartTime);
  v5 = 0;
  if ( v4 < 0.0 || v4 > 1.0 )
    v5 = 1;
  m_nLabelWidth = this->m_nLabelWidth;
  v7 = m_nLabelWidth + (int)(float)((float)(mxWidget::w2(this) - m_nLabelWidth) * v4);
  return v5 == 0 && (int)abs32(mx - v7) < 5;
}

//------------------------------------------------------------------------------
// Address: 0x00425AE0
// Name: public: void CChoreoView::PlayScene(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::PlayScene(CChoreoView *this, bool forward)
{
  CChoreoScene *m_pScene; // ecx
  bool v4; // al
  float v5; // xmm0_4
  float v6; // xmm1_4
  bool m_bForward; // al
  float v8; // xmm0_4
  float starttime; // xmm0_4
  bool v10; // al
  float v11; // xmm1_4
  float st; // [esp+10h] [ebp-4h]
  float sta; // [esp+10h] [ebp-4h]
  float startonly; // [esp+1Ch] [ebp+8h]

  this->m_bForward = forward;
  if ( this->m_pScene != nullptr )
  {
    sound->Flush(this: sound);
    FacePoser_EnsurePhonemesLoaded();
    if ( this->m_bSimulating && this->m_bPaused )
    {
      this->m_bPaused = false;
      return;
    }
    m_pScene = this->m_pScene;
    *(_WORD *)&this->m_bSimulating = 1;
    st = CChoreoScene::FindStopTime(this: m_pScene);
    CChoreoScene::SetSoundFileStartupLatency(this: this->m_pScene, time: 0.0);
    if ( this->m_rgABPoints[0].active )
    {
      if ( this->m_rgABPoints[1].active )
      {
        sta = this->m_rgABPoints[0].time;
        startonly = this->m_rgABPoints[1].time;
        CChoreoScene::ResetSimulation(
          this: this->m_pScene,
          forward: this->m_bForward,
          starttime: sta,
          endtime: startonly);
        m_bForward = this->m_bForward;
        if ( m_bForward )
          v8 = sta;
        else
          v8 = startonly;
        this->m_flScrub = v8;
        this->m_bPaused = false;
        if ( !m_bForward )
        {
          v5 = sta;
          goto LABEL_25;
        }
LABEL_24:
        v5 = startonly;
LABEL_25:
        this->m_flScrubTarget = v5;
        this->m_bPaused = false;
        if ( g_viewerSettings.speedScale == 0.0 )
        {
          this->m_flLastSpeedScale = g_viewerSettings.speedScale;
          this->m_bResetSpeedScale = true;
          g_viewerSettings.speedScale = 1.0;
          Con_Printf(fmt: "Resetting speed scale to 1.0\n");
        }
        return;
      }
      starttime = this->m_rgABPoints[0].time;
    }
    else
    {
      if ( !this->m_rgABPoints[1].active )
      {
        CChoreoScene::ResetSimulation(this: this->m_pScene, forward: this->m_bForward, starttime: 0.0, endtime: 0.0);
        v4 = this->m_bForward;
        v5 = st;
        if ( v4 )
          v6 = 0.0;
        else
          v6 = st;
        this->m_flScrub = v6;
        this->m_bPaused = false;
        if ( !v4 )
          v5 = 0.0;
        goto LABEL_25;
      }
      starttime = this->m_rgABPoints[1].time;
    }
    startonly = starttime;
    CChoreoScene::ResetSimulation(this: this->m_pScene, forward: this->m_bForward, starttime, endtime: 0.0);
    v10 = this->m_bForward;
    v5 = st;
    if ( v10 )
      v11 = startonly;
    else
      v11 = st;
    this->m_flScrub = v11;
    this->m_bPaused = false;
    if ( v10 )
      goto LABEL_25;
    goto LABEL_24;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425D10
// Name: void SetupFlexControllerTracks(class CStudioHdr __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupFlexControllerTracks(CStudioHdr *hdr, CChoreoEvent *event)
{
  CChoreoEvent *v2; // ebx
  int NumFlexAnimationTracks; // esi
  int j; // edi
  CFlexAnimationTrack *FlexAnimationTrack; // ebx
  const studiohdr_t *m_pStudioHdr; // eax
  int v7; // edi
  int v8; // ecx
  int v9; // ebx
  char *v10; // ecx
  bool v11; // zf
  const char *v12; // ebx
  CFlexAnimationTrack *Track; // esi
  float value; // xmm0_4
  int v15; // ebx
  double v16; // st7
  float v17; // xmm0_4
  CExpressionSample *sample; // [esp+10h] [ebp-20h]
  float v19; // [esp+14h] [ebp-1Ch]
  float rangedValue; // [esp+18h] [ebp-18h]
  float orig_max; // [esp+1Ch] [ebp-14h]
  float orig_min; // [esp+20h] [ebp-10h]
  int range; // [esp+24h] [ebp-Ch]
  float rangeb; // [esp+24h] [ebp-Ch]
  float rangea; // [esp+24h] [ebp-Ch]
  float rangec; // [esp+24h] [ebp-Ch]
  LocalFlexController_t i; // [esp+28h] [ebp-8h]
  bool combo; // [esp+2Fh] [ebp-1h]

  if ( hdr != nullptr )
  {
    v2 = event;
    if ( event != nullptr && !CChoreoEvent::GetTrackLookupSet(this: event) )
    {
      NumFlexAnimationTracks = CChoreoEvent::GetNumFlexAnimationTracks(this: event);
      for ( j = 0; j < NumFlexAnimationTracks; ++j )
      {
        FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: v2, index: j);
        CFlexAnimationTrack::SetFlexControllerIndex(
          this: FlexAnimationTrack,
          raw: DUMMY_INVALID_FLEX_CONTROLLER,
          index: -1,
          side: 0);
        CFlexAnimationTrack::SetFlexControllerIndex(
          this: FlexAnimationTrack,
          raw: DUMMY_INVALID_FLEX_CONTROLLER,
          index: -1,
          side: 1);
        v2 = event;
      }
      m_pStudioHdr = hdr->m_pStudioHdr;
      v7 = 0;
      i = DUMMY_NULL_FLEX_CONTROLLER;
      if ( hdr->m_pStudioHdr->numflexcontrollers > 0 )
      {
        do
        {
          v8 = v7 + m_pStudioHdr->flexcontrollerindex;
          v9 = *(int *)((char *)&m_pStudioHdr->version + v8);
          v10 = (char *)m_pStudioHdr + v8;
          v11 = &v10[v9] == nullptr;
          v12 = &v10[v9];
          range = *(int *)((char *)&m_pStudioHdr->checksum + v7 + m_pStudioHdr->flexcontrollerindex);
          if ( !v11 )
          {
            combo = false;
            if ( strncmp(first: "right_", last: v12, count: 6u) == 0 )
            {
              combo = true;
              v12 += 6;
            }
            Track = CChoreoEvent::FindTrack(this: event, controllername: v12);
            if ( Track == nullptr )
              Track = CChoreoEvent::AddTrack(this: event, controllername: v12);
            CFlexAnimationTrack::SetFlexControllerIndex(this: Track, raw: i, index: range, side: 0);
            if ( combo )
            {
              CFlexAnimationTrack::SetFlexControllerIndex(
                this: Track,
                raw: (LocalFlexController_t)(i + 1),
                index: *(_DWORD *)&hdr->m_pStudioHdr->name[v7 + 16 + hdr->m_pStudioHdr->flexcontrollerindex],
                side: 1);
              CFlexAnimationTrack::SetComboType(this: Track, combo: true);
            }
            orig_min = CFlexAnimationTrack::GetMin(this: Track, type: 0);
            orig_max = CFlexAnimationTrack::GetMax(this: Track, type: 0);
            if ( *(float *)&hdr->m_pStudioHdr->name[v7 + hdr->m_pStudioHdr->flexcontrollerindex] == 0.0
              || *(float *)&hdr->m_pStudioHdr->name[v7 + 4 + hdr->m_pStudioHdr->flexcontrollerindex] == 1.0 )
            {
              CFlexAnimationTrack::SetInverted(this: Track, isInverted: false);
              CFlexAnimationTrack::SetMin(
                this: Track,
                value: *(float *)&hdr->m_pStudioHdr->name[v7 + hdr->m_pStudioHdr->flexcontrollerindex]);
              value = *(float *)&hdr->m_pStudioHdr->name[v7 + 4 + hdr->m_pStudioHdr->flexcontrollerindex];
            }
            else
            {
              CFlexAnimationTrack::SetInverted(this: Track, isInverted: true);
              CFlexAnimationTrack::SetMin(
                this: Track,
                value: *(float *)&hdr->m_pStudioHdr->name[v7 + 4 + hdr->m_pStudioHdr->flexcontrollerindex]);
              value = *(float *)&hdr->m_pStudioHdr->name[v7 + hdr->m_pStudioHdr->flexcontrollerindex];
            }
            CFlexAnimationTrack::SetMax(this: Track, value);
            if ( CFlexAnimationTrack::GetNumSamples(this: Track, type: 0) > 0 )
            {
              rangeb = CFlexAnimationTrack::GetMax(this: Track, type: 0);
              v15 = 0;
              rangea = rangeb - CFlexAnimationTrack::GetMin(this: Track, type: 0);
              if ( CFlexAnimationTrack::GetNumSamples(this: Track, type: 0) > 0 )
              {
                v19 = 1.0 / rangea;
                do
                {
                  sample = CFlexAnimationTrack::GetSample(this: Track, index: v15, type: 0);
                  rangedValue = (float)((float)(1.0 - sample->value) * orig_min) + (float)(sample->value * orig_max);
                  v16 = (rangedValue - CFlexAnimationTrack::GetMin(this: Track, type: 0)) * v19;
                  if ( v16 >= 0.0 )
                  {
                    v17 = v16;
                    rangec = v16;
                    if ( rangec > 1.0 )
                      v17 = 1.0;
                  }
                  else
                  {
                    v17 = 0.0;
                  }
                  sample->value = v17;
                  ++v15;
                }
                while ( v15 < CFlexAnimationTrack::GetNumSamples(this: Track, type: 0) );
              }
            }
            if ( combo )
            {
              ++i;
              v7 += 20;
            }
          }
          m_pStudioHdr = hdr->m_pStudioHdr;
          v7 += 20;
          ++i;
        }
        while ( i < hdr->m_pStudioHdr->numflexcontrollers );
        v2 = event;
      }
      CChoreoEvent::SetTrackLookupSet(this: v2, set: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426010
// Name: public: void CChoreoView::ProcessLookat(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::ProcessLookat(
        CChoreoView *this@<ecx>,
        int a2@<edi>,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  double v6; // st7
  double v7; // st7
  float v8; // xmm2_4
  float v9; // xmm1_4
  const char *Parameters; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *Mapname; // eax
  IMapEntities_vtbl *v15; // edi
  CChoreoActor *Name; // eax
  IMapEntities_vtbl *v17; // edi
  const char *v18; // eax
  const char *v19; // eax
  char v20; // cl
  float i; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float scenetime; // [esp+1Ch] [ebp-9Ch]
  CChoreoActor *scenetimea; // [esp+1Ch] [ebp-9Ch]
  long double v26; // [esp+20h] [ebp-98h]
  long double v27; // [esp+20h] [ebp-98h]
  QAngle anglesDummy; // [esp+28h] [ebp-90h] BYREF
  matrix3x4_t matrix; // [esp+34h] [ebp-84h] BYREF
  QAngle anglesActor; // [esp+64h] [ebp-54h] BYREF
  Vector orgTarget; // [esp+70h] [ebp-48h] BYREF
  Vector vecForward; // [esp+7Ch] [ebp-3Ch] BYREF
  Vector orgActor; // [esp+88h] [ebp-30h] BYREF
  float flMaxIntensity; // [esp+94h] [ebp-24h]
  CChoreoActor *a; // [esp+98h] [ebp-20h]
  QAngle angles; // [esp+9Ch] [ebp-1Ch] BYREF
  float flIntensity; // [esp+A8h] [ebp-10h]
  Vector eyeTarget; // [esp+ACh] [ebp-Ch] BYREF
  StudioModel *model; // [esp+C0h] [ebp+8h]
  float flDurationb; // [esp+C4h] [ebp+Ch]
  float flDurationc; // [esp+C4h] [ebp+Ch]
  float flDurationd; // [esp+C4h] [ebp+Ch]
  float flDuration; // [esp+C4h] [ebp+Ch]
  float flDurationa; // [esp+C4h] [ebp+Ch]

  if ( CChoreoEvent::GetActor(this: event) != nullptr )
  {
    LODWORD(v26) = a2;
    a = CChoreoEvent::GetActor(this: event);
    model = FindAssociatedModel(scene, a);
    if ( model != nullptr )
    {
      scenetime = CChoreoScene::GetTime(this: scene);
      flIntensity = CChoreoEvent::GetIntensity(this: event, scenetime);
      flDurationb = CChoreoScene::GetTime(this: scene);
      v6 = flDurationb - CChoreoEvent::GetStartTime(this: event);
      if ( v6 >= 0.30000001 )
      {
        flMaxIntensity = 1.0;
      }
      else
      {
        flDurationc = v6;
        flMaxIntensity = (float)((float)((float)(flDurationc * 3.3333333) * (float)(flDurationc * 3.3333333)) * 3.0)
                       - (float)((float)((float)((float)(flDurationc * 3.3333333) * (float)(flDurationc * 3.3333333))
                                       * 2.0)
                               * (float)(flDurationc * 3.3333333));
      }
      flDurationd = CChoreoEvent::GetEndTime(this: event);
      v7 = flDurationd - CChoreoScene::GetTime(this: scene);
      flDuration = v7;
      if ( v7 >= 0.30000001 )
        v8 = 1.0;
      else
        v8 = (float)((float)((float)(flDuration * 3.3333333) * (float)(flDuration * 3.3333333)) * 3.0)
           - (float)((float)((float)((float)(flDuration * 3.3333333) * (float)(flDuration * 3.3333333)) * 2.0)
                   * (float)(flDuration * 3.3333333));
      v9 = flMaxIntensity;
      if ( v8 <= flMaxIntensity )
      {
        if ( flDuration >= 0.30000001 )
          v9 = 1.0;
        else
          v9 = (float)((float)((float)(flDuration * 3.3333333) * (float)(flDuration * 3.3333333)) * 3.0)
             - (float)((float)((float)((float)(flDuration * 3.3333333) * (float)(flDuration * 3.3333333)) * 2.0)
                     * (float)(flDuration * 3.3333333));
      }
      if ( flIntensity >= 0.0 )
      {
        if ( flIntensity <= v9 )
          flDurationa = flIntensity;
        else
          flDurationa = v9;
      }
      else
      {
        flDurationa = 0.0;
      }
      scenetimea = CChoreoActor::GetName(this: a);
      Parameters = CChoreoEvent::GetParameters(this: event);
      if ( _V_stricmp(s1: Parameters, s2: scenetimea->m_szName) != 0
        && (v11 = CChoreoEvent::GetParameters(this: event), _V_stricmp(s1: v11, s2: "!self") != 0) )
      {
        v12 = CChoreoEvent::GetParameters(this: event);
        if ( _V_stricmp(s1: v12, s2: "player") != 0
          && (v13 = CChoreoEvent::GetParameters(this: event), _V_stricmp(s1: v13, s2: "!player") != 0) )
        {
          flIntensity = *(float *)&mapentities->__vftable;
          Mapname = CChoreoScene::GetMapname(this: scene);
          (*(void (__thiscall **)(IMapEntities *, const char *))LODWORD(flIntensity))(a1: mapentities, a2: Mapname);
          if ( CChoreoEvent::GetPitch(this: event) != 0 || CChoreoEvent::GetYaw(this: event) != 0 )
          {
            LODWORD(flIntensity) = COERCE_UNSIGNED_INT((float)CChoreoEvent::GetPitch(this: event)) ^ _mask__NegFloat_;
            angles.y = (float)CChoreoEvent::GetYaw(this: event);
            angles.x = flIntensity;
            angles.z = 0.0;
            AngleMatrix(angles: &model->m_angles, &matrix);
            AngleVectors(&angles, forward: &vecForward);
            VectorRotate(in1: &vecForward.x, in2: &matrix, out: &eyeTarget.x);
            eyeTarget.x = eyeTarget.x * 75.0;
            eyeTarget.y = eyeTarget.y * 75.0;
            eyeTarget.z = eyeTarget.z * 75.0;
            StudioModel::AddLookTarget(this: model, vecPosition: &eyeTarget, flWeight: flDurationa);
          }
          else
          {
            v15 = mapentities->__vftable;
            Name = CChoreoActor::GetName(this: a);
            if ( v15->LookupOrigin(this: mapentities, a2: Name->m_szName, a3: &orgActor, a4: &anglesActor)
              && (v17 = mapentities->__vftable,
                  v18 = CChoreoEvent::GetParameters(this: event),
                  v17->LookupOrigin(this: mapentities, a2: v18, a3: &orgTarget, a4: &anglesDummy)) )
            {
              eyeTarget.x = orgTarget.x - orgActor.x;
              eyeTarget.y = orgTarget.y - orgActor.y;
              eyeTarget.z = orgTarget.z - orgActor.z;
              AngleMatrix(angles: &anglesActor, &matrix);
              VectorIRotate(in1: &eyeTarget.x, in2: &matrix, out: &angles.x);
              StudioModel::AddLookTarget(this: model, vecPosition: (const Vector *)&angles, flWeight: flDurationa);
            }
            else
            {
              v19 = CChoreoEvent::GetParameters(this: event);
              v20 = *v19;
              for ( i = 0.0; *v19 != 0; i = i + v22 )
              {
                ++v19;
                v22 = (float)v20;
                v20 = *v19;
              }
              angles.x = 0.0;
              __libm_sse2_cos(x: v26);
              __libm_sse2_acos(x: v27);
              v23 = (float)(i * 45.0) * 0.3183098861837907;
              angles.y = v23;
              angles.z = 0.0;
              AngleMatrix(angles: &model->m_angles, &matrix);
              AngleVectors(&angles, forward: &vecForward);
              VectorRotate(in1: &vecForward.x, in2: &matrix, out: &eyeTarget.x);
              eyeTarget.x = eyeTarget.x * 75.0;
              eyeTarget.y = eyeTarget.y * 75.0;
              eyeTarget.z = eyeTarget.z * 75.0;
              StudioModel::AddLookTarget(this: model, vecPosition: &eyeTarget, flWeight: flDurationa);
            }
          }
        }
        else
        {
          *(_QWORD *)&angles.x = *(_QWORD *)&model->m_origin.x;
          angles.z = 0.0;
          StudioModel::AddLookTarget(this: model, vecPosition: (const Vector *)&angles, flWeight: flDurationa);
        }
      }
      else
      {
        StudioModel::AddLookTargetSelf(this: model, flWeight: flDurationa);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426530
// Name: public: void CChoreoView::ProcessLoop(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessLoop(CChoreoView *this, CChoreoScene *scene, CChoreoEvent *event)
{
  const char *Parameters; // eax
  int NumLoopsRemaining; // eax
  float backtime; // [esp+18h] [ebp+Ch]

  if ( !this->IsScrubbing(this: &this->IFacePoserToolWindow) )
  {
    Parameters = CChoreoEvent::GetParameters(this: event);
    backtime = atof(nptr: Parameters);
    if ( CChoreoEvent::GetLoopCount(this: event) != -1 )
    {
      NumLoopsRemaining = CChoreoEvent::GetNumLoopsRemaining(this: event);
      if ( NumLoopsRemaining <= 0 )
        return;
      CChoreoEvent::SetNumLoopsRemaining(this: event, loops: NumLoopsRemaining - 1);
    }
    CChoreoScene::LoopToTime(this: scene, t: backtime);
    this->m_flScrub = backtime;
    this->m_bPaused = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004265B0
// Name: public: void CChoreoView::ProcessSequence(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessSequence(CChoreoView *this, CChoreoScene *scene, float event)
{
  CChoreoEvent *v3; // esi
  CChoreoActor *Actor; // eax
  StudioModel *AssociatedModel; // edi
  const char *Parameters; // eax
  int v7; // eax
  int v8; // ebx
  float v9; // xmm0_4
  double StartTime; // st7
  CChoreoChannel *Channel; // eax
  int ChannelIndex; // eax
  unsigned int NewAnimationLayer; // ebx
  float scenetime; // [esp+4h] [ebp-30h]
  float scenetimea; // [esp+4h] [ebp-30h]
  double minVal; // [esp+14h] [ebp-20h] BYREF
  double maxVal; // [esp+1Ch] [ebp-18h] BYREF
  float flGroundSpeed; // [esp+24h] [ebp-10h] BYREF
  int iSequence; // [esp+28h] [ebp-Ch]
  CChoreoActor *a; // [esp+2Ch] [ebp-8h]
  float flFrameRate; // [esp+30h] [ebp-4h] BYREF

  if ( this->m_bProcessSequences )
  {
    v3 = (CChoreoEvent *)LODWORD(event);
    Actor = CChoreoEvent::GetActor(this: (CChoreoEvent *)LODWORD(event));
    AssociatedModel = FindAssociatedModel(scene, a: Actor);
    if ( AssociatedModel != nullptr && CChoreoEvent::GetActor(this: v3) != nullptr )
    {
      a = CChoreoEvent::GetActor(this: v3);
      Parameters = CChoreoEvent::GetParameters(this: v3);
      v7 = StudioModel::LookupSequence(this: AssociatedModel, szSequence: Parameters);
      v8 = v7;
      iSequence = v7;
      if ( v7 >= 0 )
      {
        StudioModel::GetSequenceInfo(
          this: AssociatedModel,
          iSequence: v7,
          pflFrameRate: &flFrameRate,
          pflGroundSpeed: &flGroundSpeed);
        if ( StudioModel::GetSequenceLoops(this: AssociatedModel, iSequence: v8) )
        {
          event = CChoreoScene::GetTime(this: scene) - v3->m_flPrevTime;
          v3->m_flPrevTime = CChoreoScene::GetTime(this: scene);
          maxVal = 0.1;
          minVal = 0.0;
          event = clamp<float,double,double>(val: &event, &minVal, &maxVal);
          v9 = (float)((float)(event * flFrameRate) + v3->m_flPrevCycle)
             - (float)(int)(float)((float)(event * flFrameRate) + v3->m_flPrevCycle);
          v3->m_flPrevCycle = v9;
        }
        else
        {
          event = CChoreoScene::GetTime(this: scene);
          StartTime = CChoreoEvent::GetStartTime(this: v3);
          event = event - StartTime;
          v9 = (float)(event * flFrameRate) - (float)(int)(float)(event * flFrameRate);
        }
        event = v9;
        Channel = CChoreoEvent::GetChannel(this: v3);
        ChannelIndex = CChoreoActor::FindChannelIndex(this: a, channel: Channel);
        NewAnimationLayer = StudioModel::GetNewAnimationLayer(this: AssociatedModel, iPriority: ChannelIndex);
        scenetime = CChoreoScene::GetTime(this: scene);
        scenetimea = CChoreoEvent::GetIntensity(this: v3, scenetime);
        StudioModel::SetOverlaySequence(
          this: AssociatedModel,
          iLayer: NewAnimationLayer,
          iSequence,
          flWeight: scenetimea);
        StudioModel::SetOverlayRate(
          this: AssociatedModel,
          iLayer: NewAnimationLayer,
          flCycle: event,
          flPlaybackRate: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426750
// Name: public: void CChoreoView::ProcessMoveto(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessMoveto(CChoreoView *this, CChoreoScene *scene, CChoreoEvent *event)
{
  bool v3; // zf
  CChoreoActor *Actor; // eax
  StudioModel *AssociatedModel; // esi
  int MovetoSequence; // edi
  double v8; // st7
  double v9; // st7
  unsigned int NewAnimationLayer; // ebx
  float cycle; // [esp+14h] [ebp-10h]
  float flGroundSpeed; // [esp+18h] [ebp-Ch] BYREF
  float flFrameRate; // [esp+1Ch] [ebp-8h] BYREF
  CChoreoView *t1; // [esp+20h] [ebp-4h]
  float dta; // [esp+2Ch] [ebp+8h]
  float dt; // [esp+2Ch] [ebp+8h]
  float intensity; // [esp+30h] [ebp+Ch]

  v3 = !this->m_bProcessSequences;
  t1 = this;
  if ( !v3 )
  {
    Actor = CChoreoEvent::GetActor(this: event);
    AssociatedModel = FindAssociatedModel(scene, a: Actor);
    if ( AssociatedModel != nullptr && CChoreoEvent::GetActor(this: event) != nullptr )
    {
      MovetoSequence = CChoreoView::GetMovetoSequence(this: t1, scene, event, model: AssociatedModel);
      if ( MovetoSequence >= 0 )
      {
        StudioModel::GetSequenceInfo(
          this: AssociatedModel,
          iSequence: MovetoSequence,
          pflFrameRate: &flFrameRate,
          pflGroundSpeed: &flGroundSpeed);
        dta = CChoreoScene::GetTime(this: scene);
        dt = dta - CChoreoEvent::GetStartTime(this: event);
        cycle = (float)(dt * flFrameRate) - (float)(int)(float)(dt * flFrameRate);
        *(float *)&t1 = flGroundSpeed * 0.0099999998;
        intensity = 1.0;
        if ( (float)(flGroundSpeed * 0.0099999998) <= dt )
        {
          v8 = ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event);
          if ( *(float *)&t1 > v8 - dt )
          {
            v9 = ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event);
            intensity = (v9 - dt) / *(float *)&t1;
          }
        }
        else
        {
          intensity = dt / (float)(flGroundSpeed * 0.0099999998);
        }
        NewAnimationLayer = StudioModel::GetNewAnimationLayer(this: AssociatedModel, iPriority: 0);
        StudioModel::SetOverlaySequence(
          this: AssociatedModel,
          iLayer: NewAnimationLayer,
          iSequence: MovetoSequence,
          flWeight: intensity);
        StudioModel::SetOverlayRate(
          this: AssociatedModel,
          iLayer: NewAnimationLayer,
          flCycle: cycle,
          flPlaybackRate: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004268A0
// Name: private: int CChoreoView::ComputeHPixelsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::ComputeHPixelsNeeded(CChoreoView *this)
{
  CChoreoScene *m_pScene; // ecx
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v6; // ecx
  int TimeZoom; // eax
  float maxtime; // [esp+4h] [ebp-4h]

  m_pScene = this->m_pScene;
  if ( m_pScene == nullptr )
    return 0;
  StopTime = CChoreoScene::FindStopTime(this: m_pScene);
  maxtime = StopTime;
  if ( StopTime < 5.0 )
    maxtime = 5.0;
  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  v6 = this->m_pScene;
  if ( v6 != nullptr )
    TimeZoom = CChoreoScene::GetTimeZoom(this: v6, tool: Name);
  else
    TimeZoom = 100;
  return (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                    * (float)(maxtime + 5.0));
}

//------------------------------------------------------------------------------
// Address: 0x00426930
// Name: public: void CChoreoView::RepositionHSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::RepositionHSlider(CChoreoView *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  float m_flLeftOffset; // xmm0_4
  mxScrollbar *m_pHorzScrollBar; // ecx
  int m_nScrollbarHeight; // [esp-4h] [ebp-14h]
  int size; // [esp+Ch] [ebp-4h]

  v2 = CChoreoView::ComputeHPixelsNeeded(this);
  v3 = mxWidget::w2(this);
  size = v3 - this->m_nLabelWidth;
  mxWidget::setVisible(this: this->m_pHorzScrollBar, b: v2 > size);
  m_nScrollbarHeight = this->m_nScrollbarHeight;
  v4 = mxWidget::h2(this);
  mxWidget::setBounds(
    this: this->m_pHorzScrollBar,
    x: 0,
    y: v4 - this->m_nScrollbarHeight,
    w: v3 - m_nScrollbarHeight,
    h: m_nScrollbarHeight);
  m_flLeftOffset = this->m_flLeftOffset;
  if ( m_flLeftOffset < 0.0 )
    m_flLeftOffset = 0.0;
  this->m_flLeftOffset = m_flLeftOffset;
  if ( m_flLeftOffset > (float)v2 )
    m_flLeftOffset = (float)v2;
  m_pHorzScrollBar = this->m_pHorzScrollBar;
  this->m_flLeftOffset = m_flLeftOffset;
  mxScrollbar::setRange(this: m_pHorzScrollBar, min: 0, max: v2);
  mxScrollbar::setValue(this: this->m_pHorzScrollBar, ivalue: (int)this->m_flLeftOffset);
  mxScrollbar::setPagesize(this: this->m_pHorzScrollBar, size);
  this->m_nLastHPixelsNeeded = v2;
}

//------------------------------------------------------------------------------
// Address: 0x00426A00
// Name: public: virtual void CChoreoView::StartEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::StartEvent(
        CChoreoView *this@<ecx>,
        int a2@<edi>,
        float currenttime,
        float scene,
        CAudioMixer *event)
{
  CChoreoEvent *v5; // esi
  CChoreoView *v6; // ebx
  CChoreoActor *Actor; // eax
  CChoreoChannel *Channel; // eax
  CChoreoScene *SubScene; // edi
  char *v10; // eax
  const char *Parameters; // eax
  double StartTime; // st7
  double v13; // st7
  double v14; // st7
  ICloseCaptionManager_vtbl *v15; // edi
  double v16; // st7
  CChoreoActor *v17; // eax
  StudioModel *AssociatedModel; // edi
  CChoreoEvent *Mixer; // eax
  int v20; // eax
  gender_t v21; // ebx
  IFacePoserSound_vtbl *v22; // ebx
  const char *v23; // eax
  char *v24; // eax
  int v25; // eax
  int v26; // eax
  float v27; // xmm0_4
  int v28; // eax
  int CloseCaptionLanguageId; // [esp+30h] [ebp-310h]
  char soundname[512]; // [esp+3Ch] [ebp-304h] BYREF
  CSoundParameters params; // [esp+23Ch] [ebp-104h] BYREF
  char tok[64]; // [esp+2F0h] [ebp-50h] BYREF
  float actualEndTime; // [esp+330h] [ebp-10h]
  float LastSlaveEndTime; // [esp+334h] [ebp-Ch]
  CChoreoView *minVal; // [esp+338h] [ebp-8h] BYREF
  float duration; // [esp+33Ch] [ebp-4h]

  v5 = (CChoreoEvent *)event;
  v6 = this;
  minVal = this;
  if ( event != nullptr && CChoreoEvent::GetActive(this: (CChoreoEvent *)event) )
  {
    Actor = CChoreoEvent::GetActor(this: v5);
    if ( Actor == nullptr || CChoreoActor::GetActive(this: Actor) )
    {
      Channel = CChoreoEvent::GetChannel(this: v5);
      if ( Channel == nullptr || CChoreoChannel::GetActive(this: Channel) )
      {
        CloseCaptionLanguageId = a2;
        switch ( CChoreoEvent::GetType(this: v5) )
        {
          case SECTION:
            CChoreoView::ProcessPause(
              this: (CChoreoView *)((char *)v6 - 632),
              scene: (CChoreoScene *)LODWORD(scene),
              event: v5);
            break;
          case SPEAK:
            if ( CChoreoView::ShouldProcessSpeak(this: (CChoreoView *)((char *)v6 - 632)) )
            {
              Parameters = CChoreoEvent::GetParameters(this: v5);
              V_strncpy(pDest: soundname, pSrc: Parameters, maxLen: 512);
              actualEndTime = CChoreoEvent::GetEndTime(this: v5);
              if ( CChoreoEvent::GetCloseCaptionType(this: v5) == CC_MASTER
                && CChoreoEvent::GetPlaybackCloseCaptionToken(this: v5, dest: tok, destlen: 64) )
              {
                LastSlaveEndTime = ((double (__thiscall *)(CChoreoEvent *, int))v5->GetDuration)(a1: v5, a2);
                duration = CChoreoEvent::GetLastSlaveEndTime(this: v5);
                StartTime = CChoreoEvent::GetStartTime(this: v5);
                v13 = duration - StartTime;
                if ( LastSlaveEndTime <= v13 )
                {
                  LastSlaveEndTime = CChoreoEvent::GetLastSlaveEndTime(this: v5);
                  v14 = CChoreoEvent::GetStartTime(this: v5);
                  v13 = LastSlaveEndTime - v14;
                }
                else
                {
                  v5->GetDuration(this: v5);
                }
                duration = v13;
                v15 = closecaptionmanager->__vftable;
                CloseCaptionLanguageId = GetCloseCaptionLanguageId();
                ((void (__thiscall *)(ICloseCaptionManager *, char *, float))v15->Process)(
                  a1: closecaptionmanager,
                  a2: tok,
                  a3: COERCE_FLOAT(LODWORD(duration)));
                if ( CChoreoEvent::IsUsingCombinedFile(this: v5) && CChoreoEvent::GetNumSlaves(this: v5) > 0 )
                {
                  V_strncpy(pDest: soundname, pSrc: tok, maxLen: 512);
                  v16 = CChoreoEvent::GetLastSlaveEndTime(this: v5);
                  if ( actualEndTime <= v16 )
                    actualEndTime = CChoreoEvent::GetLastSlaveEndTime(this: v5);
                }
              }
              v17 = CChoreoEvent::GetActor(this: v5);
              AssociatedModel = FindAssociatedModel(scene: (CChoreoScene *)LODWORD(scene), a: v17);
              Mixer = (CChoreoEvent *)CChoreoEvent::GetMixer(this: v5);
              event = (CAudioMixer *)Mixer;
              if ( Mixer == nullptr
                || (_BYTE)(v20 = ((int (__thiscall *)(IFacePoserSound *, CChoreoEvent *))sound->IsSoundPlaying)(
                                   a1: sound,
                                   a2: Mixer)) == 0 )
              {
                CSoundParameters::CSoundParameters(this: &params);
                v21 = GENDER_NONE;
                scene = 1.0;
                if ( AssociatedModel != nullptr )
                  v21 = soundemitter->GetActorGender(this: soundemitter, a2: AssociatedModel->m_pModelName);
                if ( V_stristr(pStr: soundname, pSearch: ".wav") == nullptr
                  && soundemitter->GetParametersForSound(
                       this: soundemitter,
                       a2: soundname,
                       a3: &params,
                       a4: v21,
                       a5: false) )
                {
                  scene = params.volume;
                }
                v22 = sound->__vftable;
                v23 = FacePoser_TranslateSoundName(soundname, model: AssociatedModel);
                v24 = va(fmt: "sound/%s", v23);
                v22->PlaySound_2(
                  this: sound,
                  a2: AssociatedModel,
                  a3: COERCE_FLOAT(LODWORD(scene)),
                  a4: v24,
                  a5: &event);
                CChoreoEvent::SetMixer(this: v5, mixer: event);
                v6 = minVal;
              }
              if ( event != nullptr )
              {
                LOBYTE(v20) = *(float *)v6->m_szDisplayRoot >= 0.0;
                ((void (__stdcall *)(int))event->SetDirection)(a1: v20);
                scene = CChoreoEvent::GetStartTime(this: v5);
                if ( (float)(actualEndTime - scene) > 0.0 )
                {
                  scene = (float)(currenttime - scene) / (float)(actualEndTime - scene);
                  currenttime = 1.0;
                  minVal = nullptr;
                  scene = clamp<float,float,float>(val: &scene, (const float *)&minVal, maxVal: &currenttime);
                  v25 = ((int (__thiscall *)(CAudioMixer *, int))event->GetSource)(
                          a1: event,
                          a2: CloseCaptionLanguageId);
                  v26 = (*(int (__thiscall **)(int))(*(_DWORD *)v25 + 20))(a1: v25);
                  v27 = (float)v26 - 1.0;
                  v28 = (int)(float)((float)v26 * scene);
                  if ( v28 >= 0 )
                  {
                    if ( (float)v28 > v27 )
                      v28 = (int)v27;
                  }
                  else
                  {
                    v28 = 0;
                  }
                  ((void (__thiscall *)(CAudioMixer *, int))event->SetSamplePosition)(a1: event, a2: v28);
                  event->SetActive(this: event, a2: true);
                }
              }
            }
            break;
          case SEQUENCE:
            CChoreoView::ProcessSequence(
              this: (CChoreoView *)((char *)v6 - 632),
              scene: (CChoreoScene *)LODWORD(scene),
              event: *(float *)&v5);
            break;
          case SUBSCENE:
            if ( !CChoreoScene::IsSubScene(this: (CChoreoScene *)LODWORD(scene)) )
            {
              SubScene = CChoreoEvent::GetSubScene(this: v5);
              if ( SubScene != nullptr
                || (v10 = (char *)CChoreoEvent::GetParameters(this: v5),
                    SubScene = CChoreoView::LoadScene(this: (CChoreoView *)((char *)v6 - 632), filename: v10),
                    CChoreoScene::SetSubScene(this: SubScene, sub: true),
                    CChoreoEvent::SetSubScene(this: v5, scene: SubScene),
                    SubScene != nullptr) )
              {
                CChoreoScene::ResetSimulation(
                  this: SubScene,
                  forward: v6->m_szToolName[8],
                  starttime: 0.0,
                  endtime: 0.0);
              }
            }
            break;
          case LOOP:
            CChoreoView::ProcessLoop(
              this: (CChoreoView *)((char *)v6 - 632),
              scene: (CChoreoScene *)LODWORD(scene),
              event: v5);
            break;
          default:
            return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426E70
// Name: public: void CChoreoView::RedrawStatusArea(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::RedrawStatusArea(CChoreoView *this, CChoreoWidgetDrawHelper *drawHelper, int rcStatus)
{
  int *v3; // esi
  bool v5; // zf
  CChoreoScene *m_pScene; // ecx
  const char *Mapname; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp-10h] [ebp-240h]
  int v11; // [esp-Ch] [ebp-23Ch]
  int v12; // [esp-8h] [ebp-238h]
  char sz[512]; // [esp+Ch] [ebp-224h] BYREF
  tagRECT rcInfo; // [esp+20Ch] [ebp-24h] BYREF
  tagRECT rcText; // [esp+21Ch] [ebp-14h] BYREF
  Color clr; // [esp+22Ch] [ebp-4h] BYREF

  v3 = (int *)rcStatus;
  clr = (Color)14479600;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, &clr, rc: (tagRECT *)rcStatus);
  v12 = v3[2];
  v11 = v3[1];
  v10 = *v3;
  rcStatus = 16409700;
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: drawHelper,
    clr: (HPEN__ *)&rcStatus,
    style: 0,
    width: 1,
    x1: v10,
    y1: v11,
    x2: v12,
    y2: v11);
  *(_QWORD *)&rcInfo.left = *(_QWORD *)v3;
  rcInfo.top += 2;
  v5 = this->m_Flyover.e == nullptr;
  *(_QWORD *)&rcInfo.right = *((_QWORD *)v3 + 1);
  if ( !v5 )
    this->m_Flyover.e->redrawStatus(this: this->m_Flyover.e, a2: drawHelper, a3: &rcInfo);
  if ( this->m_Flyover.c != nullptr && this->m_Flyover.ccbutton != -1 )
    this->m_Flyover.c->redrawStatus(this: this->m_Flyover.c, a2: drawHelper, a3: &rcInfo, a4: this->m_Flyover.ccbutton);
  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
  {
    *(_QWORD *)&rcText.left = *(_QWORD *)&rcInfo.left;
    rcText.right = _mm_loadl_epi64((const __m128i *)&rcInfo.right).m128i_u32[0];
    rcText.bottom = rcInfo.top + 11;
    Mapname = CChoreoScene::GetMapname(this: m_pScene);
    if ( Mapname != nullptr )
    {
      if ( *Mapname == 0 )
        Mapname = "none";
      sprintf(string: sz, format: "Associated .bsp:  %s", Mapname);
      v8 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
      rcText.left = rcText.right - v8 - 10;
      rcStatus = 7999;
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: (const Color *)&rcStatus,
        &rcText,
        fmt: sz);
      OffsetRect(lprc: &rcText, dx: 0, dy: 11);
    }
    sprintf(string: sz, format: "Scene:  %s", this->m_szChoreoFile);
    v9 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
    rcText.left = rcText.right - v9 - 10;
    rcStatus = 7999;
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: drawHelper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: (const Color *)&rcStatus,
      &rcText,
      fmt: sz);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427030
// Name: public: void CChoreoView::ProcessSpeak(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::ProcessSpeak(
        CChoreoView *this@<ecx>,
        int a2@<edi>,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  CChoreoActor *Actor; // eax
  StudioModel *AssociatedModel; // ebx
  const char *Parameters; // eax
  CAudioMixer *v9; // eax
  gender_t v10; // edi
  IFacePoserSound_vtbl *v11; // edi
  const char *v12; // eax
  char *v13; // eax
  CAudioMixer *v14; // eax
  BOOL v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int v18; // eax
  float v19; // xmm0_4
  int v20; // ebx
  int v21; // edi
  CAudioSource *v22; // eax
  int v23; // eax
  CChoreoView *v24; // esi
  CAudioSource *v25; // eax
  int v26; // ecx
  CAudioMixer_vtbl *v27; // edi
  bool v28; // al
  char soundname[512]; // [esp+30h] [ebp-300h] BYREF
  char tok[64]; // [esp+230h] [ebp-100h] BYREF
  CSoundParameters params; // [esp+270h] [ebp-C0h] BYREF
  float t; // [esp+324h] [ebp-Ch]
  CChoreoView *v34; // [esp+328h] [ebp-8h]
  CAudioMixer *mixer; // [esp+32Ch] [ebp-4h] BYREF
  float actualEndTime; // [esp+338h] [ebp+8h]
  float actualEndTimea; // [esp+338h] [ebp+8h]
  int actualEndTimeb; // [esp+338h] [ebp+8h]
  float volume; // [esp+33Ch] [ebp+Ch]
  float volumea; // [esp+33Ch] [ebp+Ch]

  v34 = this;
  if ( (ControlPanel::AllToolsDriveSpeech(this: g_pControlPanel)
     || IFacePoserToolWindow::IsActiveTool(this: &this->IFacePoserToolWindow))
    && (IFacePoserToolWindow::IsAnyToolScrubbing() || IFacePoserToolWindow::IsAnyToolProcessing()) )
  {
    t = CChoreoScene::GetTime(this: scene);
    Actor = CChoreoEvent::GetActor(this: event);
    AssociatedModel = FindAssociatedModel(scene, a: Actor);
    Parameters = CChoreoEvent::GetParameters(this: event);
    V_strncpy(pDest: soundname, pSrc: Parameters, maxLen: 512);
    actualEndTime = CChoreoEvent::GetEndTime(this: event);
    if ( CChoreoEvent::GetCloseCaptionType(this: event) == CC_MASTER
      && CChoreoEvent::GetPlaybackCloseCaptionToken(this: event, dest: tok, destlen: 64)
      && CChoreoEvent::IsUsingCombinedFile(this: event)
      && CChoreoEvent::GetNumSlaves(this: event) > 0 )
    {
      V_strncpy(pDest: soundname, pSrc: tok, maxLen: 512);
      if ( (double)actualEndTime <= CChoreoEvent::GetLastSlaveEndTime(this: event) )
        actualEndTime = CChoreoEvent::GetLastSlaveEndTime(this: event);
    }
    v9 = CChoreoEvent::GetMixer(this: event);
    v10 = GENDER_NONE;
    mixer = v9;
    if ( v9 == nullptr || !sound->IsSoundPlaying(this: sound, a2: v9) )
    {
      params.channel = 0;
      params.volume = 1.0;
      params.pitch = 100;
      params.pitchlow = 100;
      params.pitchhigh = 100;
      params.soundlevel = SNDLVL_NORM;
      params.soundname[0] = 0;
      params.play_to_owner_only = false;
      params.count = 0;
      params.delay_msec = 0;
      params.m_nSoundEntryVersion = 1;
      params.m_hSoundScriptHandle = -1;
      params.m_pOperatorsKV = nullptr;
      params.m_nRandomSeed = -1;
      volume = 1.0;
      if ( AssociatedModel != nullptr )
        v10 = soundemitter->GetActorGender(this: soundemitter, a2: AssociatedModel->m_pModelName);
      if ( V_stristr(pStr: soundname, pSearch: ".wav") == nullptr
        && soundemitter->GetParametersForSound(this: soundemitter, a2: soundname, a3: &params, a4: v10, a5: false) )
      {
        volume = params.volume;
      }
      v11 = sound->__vftable;
      v12 = FacePoser_TranslateSoundName(soundname, model: AssociatedModel);
      v13 = va(fmt: "sound/%s", v12);
      v11->PlaySound_2(this: sound, a2: AssociatedModel, a3: COERCE_FLOAT(LODWORD(volume)), a4: v13, a5: &mixer);
      CChoreoEvent::SetMixer(this: event, mixer);
    }
    v14 = CChoreoEvent::GetMixer(this: event);
    mixer = v14;
    if ( v14 != nullptr )
    {
      LOBYTE(v15) = v34->m_flFrameTime >= 0.0;
      v14->SetDirection(this: v14, a2: v15);
      volumea = CChoreoEvent::GetStartTime(this: event);
      if ( (float)(actualEndTime - volumea) > 0.0 )
      {
        v16 = (float)(t - volumea) / (float)(actualEndTime - volumea);
        if ( v16 >= 0.0 )
        {
          if ( v16 <= 1.0 )
            actualEndTimea = (float)(t - volumea) / (float)(actualEndTime - volumea);
          else
            actualEndTimea = 1.0;
        }
        else
        {
          actualEndTimea = 0.0;
        }
        v17 = ((int (__thiscall *)(CAudioMixer *, int))mixer->GetSource)(a1: mixer, a2);
        v18 = (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 20))(a1: v17);
        v19 = (float)v18 - 1.0;
        v20 = (int)(float)(actualEndTimea * (float)v18);
        if ( v20 >= 0 )
        {
          if ( (float)v20 > v19 )
            v20 = (int)v19;
        }
        else
        {
          v20 = 0;
        }
        v21 = v20 - mixer->GetSamplePosition(this: mixer);
        v22 = mixer->GetSource(this: mixer);
        v23 = v22->SampleRate(this: v22);
        v24 = v34;
        actualEndTimeb = (int)(float)((float)v23 * 0.02);
        if ( v34->IsScrubbing(this: &v34->IFacePoserToolWindow) )
        {
          v25 = mixer->GetSource(this: mixer);
          v26 = (int)(float)((float)v25->SampleRate(this: v25) * 0.0099999998);
        }
        else
        {
          v26 = actualEndTimeb;
        }
        if ( (int)abs32(v21) > v26 )
        {
          v27 = mixer->__vftable;
          v28 = v24->IsScrubbing(this: &v24->IFacePoserToolWindow);
          v27->SetSamplePosition(this: mixer, a2: v20, a3: v28);
        }
        mixer->SetActive(this: mixer, a2: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004273F0
// Name: public: void CChoreoView::GetScrubHandleRect(struct tagRECT __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::GetScrubHandleRect(
        CChoreoView *this@<ecx>,
        int a2@<edi>,
        tagRECT *rcHandle,
        bool clipped)
{
  float v4; // xmm0_4
  int m_nLabelWidth; // edi
  int v7; // eax
  int v8; // eax
  float screenfrac; // [esp+0h] [ebp-4h]

  v4 = 0.0;
  if ( this->m_pScene != nullptr )
  {
    m_nLabelWidth = this->m_nLabelWidth;
    screenfrac = (float)(this->m_flScrub - this->m_flStartTime) / (float)(this->m_flEndTime - this->m_flStartTime);
    v4 = (float)((float)(mxWidget::w2(this) - m_nLabelWidth) * screenfrac) + (float)m_nLabelWidth;
    if ( clipped )
    {
      v7 = mxWidget::w2(this) - 20;
      if ( v4 >= 20.0 )
      {
        if ( v4 > (float)v7 )
          v4 = (float)v7;
      }
      else
      {
        v4 = 20.0;
      }
    }
  }
  rcHandle->right = (int)(float)(v4 + 20.0);
  rcHandle->left = (int)(float)(v4 - 20.0);
  v8 = ((int (__thiscall *)(IFacePoserToolWindow *, int))this->GetCaptionHeight)(a1: &this->IFacePoserToolWindow, a2)
     + 2;
  rcHandle->top = v8;
  rcHandle->bottom = v8 + 10;
}

//------------------------------------------------------------------------------
// Address: 0x004274E0
// Name: public: void CChoreoView::DrawScrubHandle(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::DrawScrubHandle(
        CChoreoView *this@<ecx>,
        int a2@<edi>,
        CChoreoWidgetDrawHelper *drawHelper)
{
  HBRUSH SolidBrush; // eax
  CChoreoWidgetDrawHelper *v5; // ebx
  HBRUSH v6; // edi
  int SceneFPS; // eax
  int v8; // eax
  char sz[48]; // [esp+14h] [ebp-50h] BYREF
  tagRECT rcText; // [esp+44h] [ebp-20h] BYREF
  tagRECT rcHandle; // [esp+54h] [ebp-10h] BYREF

  CChoreoView::GetScrubHandleRect(this, a2, &rcHandle, clipped: true);
  SolidBrush = CreateSolidBrush(color: (COLORREF)&g_flexedverts[1250].z);
  v5 = drawHelper;
  v6 = SolidBrush;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, br: SolidBrush, rc: &rcHandle);
  if ( this->m_bScrubSeconds != 0 )
  {
    sprintf(string: sz, format: "%.3f", this->m_flScrub);
  }
  else
  {
    SceneFPS = CChoreoScene::GetSceneFPS(this: this->m_pScene);
    sprintf(string: sz, format: "%i", (int)(float)((float)SceneFPS * this->m_flScrub));
  }
  v8 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
  rcText.top = rcHandle.top;
  rcText.left = rcHandle.left + (rcHandle.right - rcHandle.left - v8) / 2;
  *(_QWORD *)&rcText.right = *(_QWORD *)&rcHandle.right;
  drawHelper = (CChoreoWidgetDrawHelper *)0xFFFFFF;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: v5,
    font: "Arial",
    pointsize: 9,
    weight: 500,
    clr: (const Color *)&drawHelper,
    &rcText,
    fmt: sz);
  DeleteObject(ho: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004275F0
// Name: public: bool CChoreoView::IsMouseOverScrubHandle(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CChoreoView::IsMouseOverScrubHandle@<al>(CChoreoView *this@<ecx>, int a2@<edi>, mxEvent *event)
{
  POINT v4; // [esp-8h] [ebp-18h]
  tagRECT rcHandle; // [esp+0h] [ebp-10h] BYREF

  CChoreoView::GetScrubHandleRect(this, a2, &rcHandle, clipped: true);
  InflateRect(lprc: &rcHandle, dx: 2, dy: 2);
  v4.y = SLOWORD(event->y);
  v4.x = SLOWORD(event->x);
  return PtInRect(lprc: &rcHandle, pt: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00427640
// Name: public: void CChoreoView::DrawScrubHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChoreoView::DrawScrubHandle(CChoreoView *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-6Ch] BYREF
  tagRECT rcArea; // [esp+5Ch] [ebp-14h] BYREF
  Color bgColor; // [esp+6Ch] [ebp-4h] BYREF

  if ( this->m_bCanDraw )
  {
    rcArea.left = 0;
    rcArea.right = mxWidget::w2(this);
    v3 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
    rcArea.top = v3 + 2;
    rcArea.bottom = v3 + 13;
    bgColor = (Color)14479600;
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcArea, &bgColor);
    CChoreoView::DrawScrubHandle(this, a2, &drawHelper);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004276B0
// Name: public: void CChoreoView::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::CalcBounds(CChoreoView *this, int movetype)
{
  int m_nLabelWidth; // edi
  int v4; // eax
  CChoreoScene *m_pScene; // ecx
  int v6; // edi
  float movetypea; // [esp+10h] [ebp+8h]
  float movetypeb; // [esp+10h] [ebp+8h]
  float movetypec; // [esp+10h] [ebp+8h]

  this->m_bUseBounds = false;
  this->m_nMinX = 0;
  this->m_nMaxX = 0;
  if ( this->m_pClickedEvent != nullptr && movetype > 0 && movetype <= 5 )
  {
    m_nLabelWidth = this->m_nLabelWidth;
    movetypea = COERCE_FLOAT(LODWORD(this->m_flStartTime) ^ _mask__NegFloat_)
              / (float)(this->m_flEndTime - this->m_flStartTime);
    v4 = mxWidget::w2(this);
    m_pScene = this->m_pScene;
    this->m_nMinX = m_nLabelWidth + (int)(float)((float)(v4 - m_nLabelWidth) * movetypea);
    movetypeb = CChoreoScene::FindStopTime(this: m_pScene);
    v6 = this->m_nLabelWidth;
    movetypec = (float)(movetypeb - this->m_flStartTime) / (float)(this->m_flEndTime - this->m_flStartTime);
    this->m_nMaxX = v6 + (int)(float)((float)(mxWidget::w2(this) - v6) * movetypec);
    CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedEvent);
    this->m_bUseBounds = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004278B0
// Name: public: void CChoreoView::DrawSceneABTicks(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DrawSceneABTicks(CChoreoView *this, int drawHelper)
{
  float time; // xmm0_4
  bool v4; // zf
  float v5; // xmm2_4
  CChoreoWidgetDrawHelper *v6; // ebx
  int m_nLabelWidth; // edi
  int v8; // eax
  IFacePoserToolWindow_vtbl *v9; // edx
  int v10; // edi
  int v11; // eax
  int SceneFPS; // eax
  int v13; // edi
  int v14; // eax
  IFacePoserToolWindow_vtbl *v15; // edx
  int v16; // edi
  int v17; // eax
  int v18; // eax
  char sz[48]; // [esp+0h] [ebp-4Ch] BYREF
  tagRECT rcThumb; // [esp+30h] [ebp-1Ch] BYREF
  int v21; // [esp+40h] [ebp-Ch]
  float scenestart; // [esp+44h] [ebp-8h]
  float sceneend; // [esp+48h] [ebp-4h]

  if ( this->m_rgABPoints[0].active )
    time = this->m_rgABPoints[0].time;
  else
    time = 0.0;
  v4 = !this->m_rgABPoints[1].active;
  scenestart = time;
  if ( v4 )
    v5 = 0.0;
  else
    v5 = this->m_rgABPoints[1].time;
  v6 = (CChoreoWidgetDrawHelper *)drawHelper;
  sceneend = v5;
  if ( time != 0.0 )
  {
    m_nLabelWidth = this->m_nLabelWidth;
    *(float *)&drawHelper = (float)(time - this->m_flStartTime) / (float)(this->m_flEndTime - this->m_flStartTime);
    v21 = m_nLabelWidth;
    v8 = mxWidget::w2(this);
    v9 = this->IFacePoserToolWindow::__vftable;
    v10 = m_nLabelWidth + (int)(float)((float)(v8 - m_nLabelWidth) * *(float *)&drawHelper);
    rcThumb.right = v10 + 4;
    rcThumb.left = v10 - 4;
    v11 = v9->GetCaptionHeight(this: &this->IFacePoserToolWindow);
    rcThumb.top = v11 + 17;
    rcThumb.bottom = v11 + 25;
    drawHelper = 2062367;
    CChoreoWidgetDrawHelper::DrawTriangleMarker(
      this: v6,
      rc: &rcThumb,
      fill: (const Color *)&drawHelper,
      inverted: false);
    SceneFPS = CChoreoScene::GetSceneFPS(this: this->m_pScene);
    sprintf(string: sz, format: "Frame: %i", (int)(float)((float)SceneFPS * scenestart));
    rcThumb.left = v10
                 - CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz)
                 - 10;
    drawHelper = 3289650;
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: v6,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: (const Color *)&drawHelper,
      rcText: &rcThumb,
      fmt: sz);
    v5 = sceneend;
  }
  if ( v5 != 0.0 )
  {
    v13 = this->m_nLabelWidth;
    *(float *)&drawHelper = (float)(v5 - this->m_flStartTime) / (float)(this->m_flEndTime - this->m_flStartTime);
    v21 = v13;
    v14 = mxWidget::w2(this);
    v15 = this->IFacePoserToolWindow::__vftable;
    v16 = v21 + (int)(float)((float)(v14 - v13) * *(float *)&drawHelper);
    rcThumb.right = v16 + 4;
    rcThumb.left = v16 - 4;
    v17 = v15->GetCaptionHeight(this: &this->IFacePoserToolWindow);
    rcThumb.top = v17 + 17;
    rcThumb.bottom = v17 + 25;
    drawHelper = 2062367;
    CChoreoWidgetDrawHelper::DrawTriangleMarker(
      this: v6,
      rc: &rcThumb,
      fill: (const Color *)&drawHelper,
      inverted: false);
    v18 = CChoreoScene::GetSceneFPS(this: this->m_pScene);
    sprintf(string: sz, format: "Frame: %i", (int)(float)((float)v18 * sceneend));
    v16 += 10;
    rcThumb.right = v16
                  + CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
    rcThumb.left = v16;
    drawHelper = 3289650;
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: v6,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: (const Color *)&drawHelper,
      rcText: &rcThumb,
      fmt: sz);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427B10
// Name: public: void CChoreoView::DrawRelativeTagLines(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DrawRelativeTagLines(CChoreoView *this, CChoreoWidgetDrawHelper *drawHelper, tagRECT *rc)
{
  HWND Handle; // eax
  int v5; // edx
  int m_nScrollbarHeight; // eax
  int m_nInfoHeight; // ecx
  int v8; // ebx
  CChoreoActorWidget *v9; // edi
  CChoreoChannelWidget *Channel; // eax
  CChoreoChannelWidget *v11; // ebx
  int v12; // edi
  CAudioSourceWave *Event; // eax
  char *Header; // eax
  CChoreoEvent *v15; // edi
  const char *RelativeWavName; // eax
  CEventRelativeTag *TagByName; // eax
  float v18; // xmm0_4
  char v19; // bl
  int m_nLabelWidth; // edi
  int v21; // eax
  int v22; // ebx
  const char *RelativeTagName; // [esp-Ch] [ebp-40h]
  tagRECT rcClip; // [esp+4h] [ebp-30h] BYREF
  float v25; // [esp+14h] [ebp-20h]
  float tagtime; // [esp+18h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-18h]
  CChoreoActorWidget *a; // [esp+20h] [ebp-14h]
  int k; // [esp+24h] [ebp-10h]
  CChoreoChannelWidget *c; // [esp+28h] [ebp-Ch]
  int j; // [esp+2Ch] [ebp-8h]
  Color clr; // [esp+30h] [ebp-4h] BYREF

  if ( this->m_pScene != nullptr )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &rcClip);
    v5 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
    m_nScrollbarHeight = this->m_nScrollbarHeight;
    m_nInfoHeight = this->m_nInfoHeight;
    rcClip.right -= m_nScrollbarHeight;
    rcClip.bottom -= m_nScrollbarHeight + m_nInfoHeight;
    rcClip.top = v5;
    CChoreoWidgetDrawHelper::StartClipping(this: drawHelper, clipRect: &rcClip);
    v8 = 0;
    for ( i = 0; v8 < this->m_SceneActors.m_Size; i = v8 )
    {
      v9 = this->m_SceneActors.m_Memory.m_pMemory[v8];
      a = v9;
      if ( v9 != nullptr )
      {
        j = 0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: v9) > 0 )
        {
          do
          {
            Channel = CChoreoActorWidget::GetChannel(this: v9, num: j);
            v11 = Channel;
            c = Channel;
            if ( Channel != nullptr )
            {
              v12 = 0;
              k = 0;
              if ( (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)Channel) > 0 )
              {
                do
                {
                  Event = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v11, num: v12);
                  if ( Event != nullptr )
                  {
                    Header = CAudioSourceWave::GetHeader(this: Event);
                    v15 = (CChoreoEvent *)Header;
                    if ( Header != nullptr && CChoreoEvent::IsUsingRelativeTag(this: (CChoreoEvent *)Header) )
                    {
                      RelativeTagName = CChoreoEvent::GetRelativeTagName(this: v15);
                      RelativeWavName = CChoreoEvent::GetRelativeWavName(this: v15);
                      TagByName = CChoreoScene::FindTagByName(
                                    this: this->m_pScene,
                                    wavname: RelativeWavName,
                                    name: RelativeTagName);
                      if ( TagByName != nullptr )
                      {
                        tagtime = CEventRelativeTag::GetStartTime(this: TagByName);
                        v18 = (float)(tagtime - this->m_flStartTime) / (float)(this->m_flEndTime - this->m_flStartTime);
                        v19 = 0;
                        v25 = v18;
                        if ( v18 < 0.0 || v18 > 1.0 )
                          v19 = 1;
                        m_nLabelWidth = this->m_nLabelWidth;
                        v21 = mxWidget::w2(this);
                        if ( v19 == 0 )
                        {
                          clr = (Color)14464180;
                          CChoreoWidgetDrawHelper::DrawColoredLine(
                            this: drawHelper,
                            (HPEN__ *)&clr,
                            style: 0,
                            width: 1,
                            x1: m_nLabelWidth + (int)(float)((float)(v21 - m_nLabelWidth) * v25),
                            y1: rcClip.top,
                            x2: m_nLabelWidth + (int)(float)((float)(v21 - m_nLabelWidth) * v25),
                            y2: rcClip.bottom);
                        }
                        v11 = c;
                      }
                    }
                  }
                  v12 = ++k;
                }
                while ( v12 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v11) );
              }
              v9 = a;
            }
            v22 = ++j;
          }
          while ( v22 < CChoreoWidgetDrawHelper::GetHeight(this: v9) );
          v8 = i;
        }
      }
      ++v8;
    }
    CChoreoWidgetDrawHelper::StopClipping(this: drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427D20
// Name: public: void CChoreoView::DrawBackground(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DrawBackground(CChoreoView *this, CChoreoWidgetDrawHelper *drawHelper, tagRECT *rc)
{
  HWND Handle; // eax
  int v5; // edx
  int m_nScrollbarHeight; // eax
  int m_nInfoHeight; // ecx
  int v8; // edi
  CChoreoGlobalEventWidget *v9; // ecx
  int i; // edi
  CChoreoActorWidget *v11; // ecx
  tagRECT rcClip; // [esp+Ch] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rcClip);
  v5 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
  m_nScrollbarHeight = this->m_nScrollbarHeight;
  m_nInfoHeight = this->m_nInfoHeight;
  rcClip.right -= m_nScrollbarHeight;
  rcClip.bottom -= m_nScrollbarHeight + m_nInfoHeight;
  v8 = 0;
  for ( rcClip.top = v5; v8 < this->m_SceneGlobalEvents.m_Size; ++v8 )
  {
    v9 = this->m_SceneGlobalEvents.m_Memory.m_pMemory[v8];
    if ( v9 != nullptr )
      v9->redraw(this: v9, a2: drawHelper);
  }
  CChoreoWidgetDrawHelper::StartClipping(this: drawHelper, clipRect: &rcClip);
  for ( i = 0; i < this->m_SceneActors.m_Size; ++i )
  {
    v11 = this->m_SceneActors.m_Memory.m_pMemory[i];
    if ( v11 != nullptr )
      v11->redraw(this: v11, a2: drawHelper);
  }
  CChoreoWidgetDrawHelper::StopClipping(this: drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x00427DE0
// Name: public: void CChoreoView::DrawFocusRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DrawFocusRect(CChoreoView *this)
{
  int v2; // edi
  int v3; // ebx
  tagRECT rc; // [esp+8h] [ebp-14h] BYREF
  HDC__ *dc; // [esp+18h] [ebp-4h]

  v2 = 0;
  dc = GetDC(hWnd: nullptr);
  if ( this->m_FocusRects.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      rc = this->m_FocusRects.m_Memory.m_pMemory[v3].m_rcFocus;
      DrawFocusRect(hDC: dc, lprc: &rc);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_FocusRects.m_Size );
  }
  ReleaseDC(hWnd: nullptr, hDC: dc);
}

//------------------------------------------------------------------------------
// Address: 0x00427E60
// Name: public: int CChoreoView::CountSelectedGlobalEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::CountSelectedGlobalEvents(CChoreoView *this)
{
  int v2; // ebx
  int i; // esi
  CChoreoGlobalEventWidget *v4; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_SceneGlobalEvents.m_Size; ++i )
  {
    v4 = this->m_SceneGlobalEvents.m_Memory.m_pMemory[i];
    if ( v4 != nullptr && v4->IsSelected(this: v4) )
      ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00427EA0
// Name: public: int CChoreoView::CountSelectedEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::CountSelectedEvents(CChoreoView *this)
{
  int result; // eax
  int v2; // edi
  CChoreoActorWidget **m_pMemory; // eax
  CChoreoActorWidget *v4; // ebx
  int v5; // esi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v7; // esi
  int v8; // edi
  CChoreoEventWidget *Event; // eax
  int i; // [esp+4h] [ebp-10h]
  CChoreoView *v11; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  int c; // [esp+10h] [ebp-4h]

  result = 0;
  v2 = 0;
  v11 = this;
  c = 0;
  i = 0;
  if ( this->m_SceneActors.m_Size > 0 )
  {
    do
    {
      m_pMemory = this->m_SceneActors.m_Memory.m_pMemory;
      v4 = m_pMemory[v2];
      if ( v4 != nullptr )
      {
        v5 = 0;
        j = 0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: m_pMemory[v2]) > 0 )
        {
          do
          {
            Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v4, num: v5);
            v7 = (CChoreoChannelWidget *)Channel;
            if ( Channel != nullptr )
            {
              v8 = 0;
              if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
              {
                do
                {
                  Event = CChoreoChannelWidget::GetEvent(this: v7, num: v8);
                  if ( Event != nullptr && Event->IsSelected(this: Event) )
                    ++c;
                  ++v8;
                }
                while ( v8 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v7) );
              }
            }
            v5 = ++j;
          }
          while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v4) );
          v2 = i;
        }
        this = v11;
      }
      i = ++v2;
    }
    while ( v2 < this->m_SceneActors.m_Size );
    return c;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427F60
// Name: public: int CChoreoView::GetEarliestEventIndex(class CUtlVector<class CChoreoEventWidget __near *,class CUtlMemory<class CChoreoEventWidget __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetEarliestEventIndex(
        CChoreoView *this,
        CUtlVector<CChoreoEventWidget *,CUtlMemory<CChoreoEventWidget *,int> > *events)
{
  int m_Size; // edi
  int result; // eax
  int v4; // esi
  char *Header; // eax
  double StartTime; // st7
  int best; // [esp+0h] [ebp-8h]
  float minTime; // [esp+4h] [ebp-4h]

  m_Size = events->m_Size;
  result = -1;
  v4 = 0;
  best = -1;
  minTime = 3.4028235e38;
  if ( m_Size > 0 )
  {
    do
    {
      Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)events->m_Memory.m_pMemory[v4]);
      StartTime = CChoreoEvent::GetStartTime(this: (CChoreoEvent *)Header);
      if ( minTime > StartTime )
      {
        minTime = StartTime;
        best = v4;
      }
      ++v4;
    }
    while ( v4 < m_Size );
    return best;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427FD0
// Name: public: int CChoreoView::GetLatestEventIndex(class CUtlVector<class CChoreoEventWidget __near *,class CUtlMemory<class CChoreoEventWidget __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetLatestEventIndex(
        CChoreoView *this,
        CUtlVector<CChoreoEventWidget *,CUtlMemory<CChoreoEventWidget *,int> > *events)
{
  int m_Size; // edi
  int result; // eax
  int v5; // esi
  char *Header; // eax
  double EndTime; // st7
  int best; // [esp+0h] [ebp-8h]
  float maxTime; // [esp+4h] [ebp-4h]
  float t; // [esp+10h] [ebp+8h]

  m_Size = events->m_Size;
  result = -1;
  v5 = 0;
  best = -1;
  maxTime = 1.1754944e-38;
  if ( m_Size > 0 )
  {
    do
    {
      Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)events->m_Memory.m_pMemory[v5]);
      EndTime = CChoreoEvent::GetEndTime(this: (CChoreoEvent *)Header);
      if ( EndTime > maxTime )
      {
        t = EndTime;
        maxTime = t;
        best = v5;
      }
      ++v5;
    }
    while ( v5 < m_Size );
    return best;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428040
// Name: public: void CChoreoView::RecomputeWaves(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::RecomputeWaves(CChoreoView *this)
{
  int v1; // edi
  CChoreoActorWidget **m_pMemory; // eax
  CChoreoActorWidget *v3; // ebx
  int v4; // esi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v6; // esi
  int v7; // edi
  CChoreoEventWidget *Event; // eax
  int i; // [esp+4h] [ebp-Ch]
  CChoreoView *v10; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v10 = this;
  for ( i = 0; v1 < this->m_SceneActors.m_Size; i = v1 )
  {
    m_pMemory = this->m_SceneActors.m_Memory.m_pMemory;
    v3 = m_pMemory[v1];
    if ( v3 != nullptr )
    {
      v4 = 0;
      j = 0;
      if ( CChoreoWidgetDrawHelper::GetHeight(this: m_pMemory[v1]) > 0 )
      {
        do
        {
          Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v3, num: v4);
          v6 = (CChoreoChannelWidget *)Channel;
          if ( Channel != nullptr )
          {
            v7 = 0;
            if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
            {
              do
              {
                Event = CChoreoChannelWidget::GetEvent(this: v6, num: v7);
                if ( Event != nullptr )
                  CChoreoEventWidget::RecomputeWave(this: Event);
                ++v7;
              }
              while ( v7 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v6) );
            }
          }
          v4 = ++j;
        }
        while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v3) );
        v1 = i;
      }
      this = v10;
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004280F0
// Name: public: void CChoreoView::ProcessExpression(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessExpression(CChoreoView *this, CChoreoScene *scene, CChoreoEvent *event)
{
  CChoreoActor *Actor; // eax
  StudioModel *AssociatedModel; // eax
  StudioModel *v5; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v7; // eax
  CStudioHdr *v8; // esi
  IExpressionManager_vtbl *v9; // esi
  const char *Parameters; // eax
  CExpClass *v11; // esi
  const char *Parameters2; // eax
  CExpression *Expression; // ebx
  CChoreoView *v14; // eax
  int v15; // edi
  CChoreoActorWidget **m_pMemory; // ecx
  CChoreoActorWidget *v17; // esi
  bool v18; // zf
  float *v19; // ebx
  const studiohdr_t *v20; // eax
  int v21; // edx
  int v22; // esi
  int v23; // ecx
  float v24; // xmm0_4
  float scenetime; // [esp+8h] [ebp-1Ch]
  CChoreoActor *a; // [esp+18h] [ebp-Ch]
  CChoreoActor *aa; // [esp+18h] [ebp-Ch]
  CStudioHdr *hdr; // [esp+1Ch] [ebp-8h]
  float *settingsa; // [esp+20h] [ebp-4h]
  float flIntensity; // [esp+2Ch] [ebp+8h]

  Actor = CChoreoEvent::GetActor(this: event);
  AssociatedModel = FindAssociatedModel(scene, a: Actor);
  v5 = AssociatedModel;
  if ( AssociatedModel != nullptr )
  {
    m_pStudioHdr = AssociatedModel->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      hdr = v5->m_pStudioHdr;
    }
    else
    {
      v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v5->m_MDLHandle);
      CStudioHdr::Init(this: v5->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
      v8 = v5->m_pStudioHdr;
      if ( v8->m_pStudioHdr == nullptr )
        return;
      hdr = v8;
    }
    if ( hdr != nullptr )
    {
      v9 = expressions->__vftable;
      Parameters = CChoreoEvent::GetParameters(this: event);
      v11 = v9->FindClass(this: expressions, a2: Parameters, a3: true);
      if ( v11 != nullptr )
      {
        Parameters2 = CChoreoEvent::GetParameters2(this: event);
        Expression = CExpClass::FindExpression(this: v11, name: Parameters2);
        if ( Expression != nullptr )
        {
          a = CChoreoEvent::GetActor(this: event);
          if ( a != nullptr )
          {
            v14 = this;
            v15 = 0;
            if ( this->m_SceneActors.m_Size > 0 )
            {
              do
              {
                m_pMemory = v14->m_SceneActors.m_Memory.m_pMemory;
                v17 = m_pMemory[v15];
                if ( v17 != nullptr )
                {
                  v18 = CActorBitmapButton::GetActor(this: (TimelineItem *)m_pMemory[v15]) == (_DWORD)a;
                  v14 = this;
                  if ( v18 )
                    break;
                }
                ++v15;
              }
              while ( v15 < v14->m_SceneActors.m_Size );
              if ( v17 != nullptr && v15 < v14->m_SceneActors.m_Size )
              {
                settingsa = CExpression::GetSettings(this: Expression);
                aa = (CChoreoActor *)CExpression::GetWeights(this: Expression);
                v19 = CChoreoActorWidget::GetSettings(this: v17);
                scenetime = CChoreoScene::GetTime(this: scene);
                flIntensity = CChoreoEvent::GetIntensity(this: event, scenetime);
                v20 = hdr->m_pStudioHdr;
                v21 = 0;
                if ( hdr->m_pStudioHdr->numflexcontrollers > 0 )
                {
                  v22 = 0;
                  do
                  {
                    v23 = *(int *)((char *)&v20->checksum + v22 + v20->flexcontrollerindex);
                    if ( v23 >= 0 )
                    {
                      v24 = *(float *)&aa->m_szName[4 * v23] * flIntensity;
                      if ( v24 >= 0.0 )
                      {
                        if ( v24 > 1.0 )
                          v24 = 1.0;
                      }
                      else
                      {
                        v24 = 0.0;
                      }
                      v19[v23] = (float)((float)(1.0 - v24) * v19[v23]) + (float)(settingsa[v23] * v24);
                    }
                    ++v21;
                    v22 += 20;
                  }
                  while ( v21 < v20->numflexcontrollers );
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004282D0
// Name: public: void CChoreoView::PauseThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::PauseThink(CChoreoView *this)
{
  int v2; // eax
  float m_flAutomationDelay; // xmm0_4
  float m_flAutomationTime; // xmm1_4
  int v5; // edi
  int v6; // eax
  char sz[256]; // [esp+1Ch] [ebp-17Ch] BYREF
  CChoreoWidgetDrawHelper drawHelper; // [esp+11Ch] [ebp-7Ch] BYREF
  tagRECT rcPauseRect; // [esp+174h] [ebp-24h] BYREF
  tagRECT rcText; // [esp+184h] [ebp-14h] BYREF
  Color bgColor; // [esp+194h] [ebp-4h] BYREF

  if ( this->m_bAutomated )
  {
    this->m_flAutomationTime = fabs(this->m_flFrameTime) + this->m_flAutomationTime;
    rcPauseRect.left = 0;
    rcPauseRect.right = mxWidget::w2(this);
    v2 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
    rcPauseRect.top = v2 + 15;
    rcPauseRect.bottom = v2 + 25;
    bgColor = (Color)14479600;
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcPauseRect, &bgColor);
    CChoreoView::DrawSceneABTicks(this, (int)&drawHelper);
    m_flAutomationDelay = this->m_flAutomationDelay;
    if ( m_flAutomationDelay <= 0.0
      || (m_flAutomationTime = this->m_flAutomationTime, m_flAutomationDelay <= m_flAutomationTime) )
    {
      v6 = this->m_nAutomatedAction - 1;
      this->m_bAutomated = false;
      if ( v6 != 0 )
      {
        if ( v6 == 1 )
        {
          this->m_bPaused = false;
          sound->StopAll(this: sound);
        }
      }
      else
      {
        CChoreoView::FinishSimulation(this);
      }
      this->m_nAutomatedAction = 0;
      *(_QWORD *)&this->m_flAutomationDelay = 0;
      CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
    }
    else
    {
      sprintf(string: sz, format: "Pause %.2f/%.2f", m_flAutomationTime, m_flAutomationDelay);
      v5 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
      CChoreoView::GetScrubHandleRect(this, a2: v5, rcHandle: &rcText, clipped: true);
      rcText.left = (int)(float)((float)((rcText.right + rcText.left) / 2) - (float)((float)v5 * 0.5));
      rcText.right = rcText.left + v5 + 1;
      rcText.top = rcPauseRect.top;
      rcText.bottom = rcPauseRect.bottom;
      bgColor = (Color)127;
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: &bgColor,
        &rcText,
        fmt: sz);
      CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004284A0
// Name: public: void CChoreoView::LayoutScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::LayoutScene(CChoreoView *this)
{
  CChoreoScene *m_pScene; // ecx
  HWND Handle; // eax
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // eax
  int v5; // eax
  int m_nTopOffset; // edx
  double v7; // st7
  double PixelsPerSecond; // st7
  double v9; // st7
  int (__thiscall *v10)(IFacePoserToolWindow *); // eax
  int v11; // eax
  int top; // ebx
  float v13; // eax
  int v14; // ebx
  CChoreoActorWidget *v15; // edi
  int v16; // eax
  int v17; // xmm0_4
  int i; // ebx
  TimelineItem *v19; // edi
  double m_flStartTime; // st7
  CChoreoEvent *Actor; // eax
  double StartTime; // st7
  int m_nLabelWidth; // eax
  float v24; // xmm0_4
  int v25; // ecx
  void (__thiscall *Draw)(TimelineItem *, CChoreoWidgetDrawHelper *); // edx
  tagRECT rc; // [esp+4h] [ebp-34h] BYREF
  tagRECT rcEvent; // [esp+14h] [ebp-24h] BYREF
  tagRECT rcClient; // [esp+24h] [ebp-14h] BYREF
  int frac; // [esp+34h] [ebp-4h]

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr && !this->m_bLayoutIsValid )
  {
    CChoreoScene::ReconcileTags(this: m_pScene);
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &rc);
    GetCaptionHeight = this->GetCaptionHeight;
    rcClient = rc;
    v5 = GetCaptionHeight(this: &this->IFacePoserToolWindow);
    m_nTopOffset = this->m_nTopOffset;
    rcClient.top += v5 + this->m_nStartRow + 15;
    OffsetRect(lprc: &rcClient, dx: 0, dy: -m_nTopOffset);
    v7 = this->m_flLeftOffset / CChoreoView::GetPixelsPerSecond(this);
    frac = rcClient.right - this->m_nLabelWidth;
    this->m_flStartTime = v7;
    *(float *)&frac = (float)frac;
    PixelsPerSecond = CChoreoView::GetPixelsPerSecond(this);
    v9 = *(float *)&frac / PixelsPerSecond;
    v10 = this->GetCaptionHeight;
    this->m_rcTimeLine = rcClient;
    this->m_flEndTime = v9 + this->m_flStartTime;
    v11 = v10(this: &this->IFacePoserToolWindow);
    top = rcClient.top;
    v11 += 15;
    this->m_rcTimeLine.top = v11;
    this->m_rcTimeLine.bottom = v11 + 44;
    v13 = 0.0;
    v14 = top + 2;
    *(float *)&frac = 0.0;
    if ( this->m_SceneActors.m_Size > 0 )
    {
      do
      {
        v15 = this->m_SceneActors.m_Memory.m_pMemory[LODWORD(v13)];
        if ( v15 != nullptr )
        {
          v16 = v15->GetItemHeight(this: v15);
          *(_QWORD *)&rcEvent.left = *(_QWORD *)&rcClient.left;
          v17 = _mm_loadl_epi64((const __m128i *)&rcClient.right).m128i_u32[0];
          rcEvent.top = v14;
          v14 += v16;
          rcEvent.right = v17;
          rcEvent.bottom = v14;
          v15->Layout(this: v15, a2: &rcEvent);
          v13 = *(float *)&frac;
        }
        ++LODWORD(v13);
        *(float *)&frac = v13;
      }
      while ( SLODWORD(v13) < this->m_SceneActors.m_Size );
    }
    for ( i = 0; i < this->m_SceneGlobalEvents.m_Size; ++i )
    {
      v19 = (TimelineItem *)this->m_SceneGlobalEvents.m_Memory.m_pMemory[i];
      if ( v19 != nullptr )
      {
        m_flStartTime = this->m_flStartTime;
        *(_QWORD *)&rcEvent.left = *(_QWORD *)&this->m_rcTimeLine.left;
        *(float *)&frac = m_flStartTime;
        *(_QWORD *)&rcEvent.right = *(_QWORD *)&this->m_rcTimeLine.right;
        Actor = (CChoreoEvent *)CActorBitmapButton::GetActor(this: v19);
        StartTime = CChoreoEvent::GetStartTime(this: Actor);
        m_nLabelWidth = this->m_nLabelWidth;
        v24 = (float)(this->m_rcTimeLine.right - m_nLabelWidth - this->m_rcTimeLine.left);
        *(float *)&frac = (StartTime - *(float *)&frac) / (this->m_flEndTime - *(float *)&frac);
        v25 = rcEvent.left + m_nLabelWidth + (int)(float)(v24 * *(float *)&frac) - 4;
        rcEvent.right = v25 + 8;
        rcEvent.left = v25;
        rcEvent.top = rcEvent.bottom - 8;
        Draw = v19->__vftable[7].Draw;
        if ( v25 + 10 >= m_nLabelWidth )
          ((void (__stdcall *)(int))Draw)(a1: 1);
        else
          ((void (__stdcall *)(_DWORD))Draw)(a1: 0);
        v19->__vftable[1].handleEvent(this: v19, a2: (mxEvent *)&rcEvent);
      }
    }
    this->m_bLayoutIsValid = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004286D0
// Name: private: int CChoreoView::ComputeVPixelsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::ComputeVPixelsNeeded(CChoreoView *this)
{
  int v2; // ebx
  int i; // edi
  CChoreoActorWidget *v4; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_SceneActors.m_Size; ++i )
  {
    v4 = this->m_SceneActors.m_Memory.m_pMemory[i];
    if ( v4 != nullptr )
      v2 += v4->GetItemHeight(this: v4) + 2;
  }
  return this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + v2 + 30;
}

//------------------------------------------------------------------------------
// Address: 0x00428720
// Name: public: void CChoreoView::RepositionVSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::RepositionVSlider(CChoreoView *this)
{
  int v2; // ebx
  int v3; // eax
  mxScrollbar *m_pVertScrollBar; // ecx
  int v5; // eax
  int v6; // eax
  mxScrollbar *v7; // ecx
  int v8; // edi
  int v9; // eax
  int v10; // [esp-4h] [ebp-1Ch]
  int y; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  int w; // [esp+14h] [ebp-4h]
  int wa; // [esp+14h] [ebp-4h]

  v2 = CChoreoView::ComputeVPixelsNeeded(this);
  w = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
  v3 = mxWidget::h2(this);
  m_pVertScrollBar = this->m_pVertScrollBar;
  if ( v2 > v3 - w )
  {
    mxWidget::setVisible(this: m_pVertScrollBar, b: true);
  }
  else
  {
    mxWidget::setVisible(this: m_pVertScrollBar, b: false);
    this->m_nTopOffset = 0;
  }
  v12 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
  y = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
  wa = this->m_nScrollbarHeight;
  v10 = mxWidget::h2(this) - wa - v12;
  v5 = mxWidget::w2(this);
  mxWidget::setBounds(this: this->m_pVertScrollBar, x: v5 - this->m_nScrollbarHeight, y, w: wa, h: v10);
  v6 = this->m_nTopOffset < 0 ? 0 : this->m_nTopOffset;
  this->m_nTopOffset = v6;
  if ( v2 < v6 )
    v6 = v2;
  v7 = this->m_pVertScrollBar;
  this->m_nTopOffset = v6;
  mxScrollbar::setRange(this: v7, min: 0, max: v2);
  mxScrollbar::setValue(this: this->m_pVertScrollBar, ivalue: this->m_nTopOffset);
  v8 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15;
  v9 = mxWidget::h2(this);
  mxScrollbar::setPagesize(this: this->m_pVertScrollBar, size: v9 - v8);
  this->m_nLastVPixelsNeeded = v2;
}

//------------------------------------------------------------------------------
// Address: 0x00428860
// Name: public: class CChoreoGlobalEventWidget __near * CChoreoView::GetGlobalEventUnderCursorPos(int,int)
// Source: json
//------------------------------------------------------------------------------
CChoreoGlobalEventWidget *__thiscall CChoreoView::GetGlobalEventUnderCursorPos(
        CChoreoView *this,
        unsigned int mx,
        unsigned int my)
{
  int v4; // edi
  CChoreoGlobalEventWidget *v5; // esi
  tagRECT bounds; // [esp+Ch] [ebp-10h] BYREF

  v4 = 0;
  if ( this->m_SceneGlobalEvents.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->m_SceneGlobalEvents.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->getBounds_2(this: v5, a2: &bounds);
      if ( PtInRect(lprc: &bounds, pt: (POINT)__PAIR64__(my, mx)) )
        break;
    }
    if ( ++v4 >= this->m_SceneGlobalEvents.m_Size )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004288D0
// Name: public: class CChoreoActorWidget __near * CChoreoView::GetActorUnderCursorPos(int,int)
// Source: json
//------------------------------------------------------------------------------
CChoreoActorWidget *__thiscall CChoreoView::GetActorUnderCursorPos(CChoreoView *this, unsigned int mx, unsigned int my)
{
  int v4; // edi
  CChoreoActorWidget *v5; // esi
  tagRECT bounds; // [esp+Ch] [ebp-10h] BYREF

  v4 = 0;
  if ( this->m_SceneActors.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->m_SceneActors.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->getBounds_2(this: v5, a2: &bounds);
      if ( PtInRect(lprc: &bounds, pt: (POINT)__PAIR64__(my, mx)) )
        break;
    }
    if ( ++v4 >= this->m_SceneActors.m_Size )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00428940
// Name: public: class CChoreoChannelWidget __near * CChoreoView::GetChannelUnderCursorPos(int,int)
// Source: json
//------------------------------------------------------------------------------
CChoreoActorWidget *__thiscall CChoreoView::GetChannelUnderCursorPos(
        CChoreoView *this,
        unsigned int mx,
        unsigned int my)
{
  CChoreoActorWidget *result; // eax
  CChoreoActorWidget *v4; // edi
  int v5; // ebx
  CChoreoChannelWidget *Channel; // esi
  tagRECT bounds; // [esp+4h] [ebp-10h] BYREF

  result = CChoreoView::GetActorUnderCursorPos(this, mx, my);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = 0;
    if ( CChoreoWidgetDrawHelper::GetHeight(this: result) <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        Channel = CChoreoActorWidget::GetChannel(this: v4, num: v5);
        if ( Channel != nullptr )
        {
          Channel->getBounds_2(this: Channel, a2: &bounds);
          if ( PtInRect(lprc: &bounds, pt: (POINT)__PAIR64__(my, mx)) )
            break;
        }
        if ( ++v5 >= CChoreoWidgetDrawHelper::GetHeight(this: v4) )
          return nullptr;
      }
      return (CChoreoActorWidget *)Channel;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004289D0
// Name: public: class CChoreoEventWidget __near * CChoreoView::GetEventUnderCursorPos(int,int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEventWidget *__thiscall CChoreoView::GetEventUnderCursorPos(CChoreoView *this, int mx, int my)
{
  CChoreoActorWidget *ChannelUnderCursorPos; // edi
  int v5; // ebx
  CChoreoEventWidget *Event; // esi
  tagRECT bounds; // [esp+Ch] [ebp-10h] BYREF

  ChannelUnderCursorPos = CChoreoView::GetChannelUnderCursorPos(this, mx, my);
  if ( ChannelUnderCursorPos == nullptr )
    return nullptr;
  if ( mx < this->m_nLabelWidth )
    return nullptr;
  if ( my < this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + this->m_nStartRow + 15 )
    return nullptr;
  if ( my >= mxWidget::h2(this) - this->m_nInfoHeight - this->m_nScrollbarHeight )
    return nullptr;
  v5 = 0;
  if ( (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)ChannelUnderCursorPos) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Event = CChoreoChannelWidget::GetEvent(this: (CChoreoChannelWidget *)ChannelUnderCursorPos, num: v5);
    if ( Event != nullptr )
    {
      Event->getBounds_2(this: Event, a2: &bounds);
      InflateRect(lprc: &bounds, dx: 8, dy: 4);
      if ( PtInRect(lprc: &bounds, pt: (POINT)__PAIR64__(my, mx)) )
        break;
    }
    if ( ++v5 >= (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)ChannelUnderCursorPos) )
      return nullptr;
  }
  return Event;
}

//------------------------------------------------------------------------------
// Address: 0x00428AB0
// Name: public: void CChoreoView::TraverseWidgets(void (CChoreoView::*)(class CChoreoWidget __near *,class CChoreoWidget __near *),class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::TraverseWidgets(
        CChoreoView *this,
        void (__thiscall *pfn)(CChoreoView *this, CChoreoWidget *, CChoreoWidget *),
        CChoreoWidget *param1,
        CChoreoWidget *param1a)
{
  int v4; // esi
  CChoreoActorWidget *v6; // edi
  CChoreoChannelWidget *Channel; // eax
  CChoreoChannelWidget *v8; // esi
  int k; // edi
  CChoreoEventWidget *Event; // eax
  int m; // esi
  CChoreoGlobalEventWidget *v12; // eax
  int i; // [esp+8h] [ebp-Ch]
  CChoreoActorWidget *actor; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]

  v4 = 0;
  for ( i = 0; v4 < this->m_SceneActors.m_Size; i = v4 )
  {
    v6 = this->m_SceneActors.m_Memory.m_pMemory[v4];
    actor = v6;
    if ( v6 != nullptr )
    {
      pfn(this: (CChoreoView *)((char *)this + (_DWORD)param1), a2: v6, a3: param1a);
      j = 0;
      if ( CChoreoWidgetDrawHelper::GetHeight(this: v6) > 0 )
      {
        do
        {
          Channel = CChoreoActorWidget::GetChannel(this: v6, num: j);
          v8 = Channel;
          if ( Channel != nullptr )
          {
            pfn(this: (CChoreoView *)((char *)this + (_DWORD)param1), a2: Channel, a3: param1a);
            for ( k = 0; k < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v8); ++k )
            {
              Event = CChoreoChannelWidget::GetEvent(this: v8, num: k);
              if ( Event != nullptr )
                pfn(this: (CChoreoView *)((char *)this + (_DWORD)param1), a2: Event, a3: param1a);
            }
            v6 = actor;
          }
          ++j;
        }
        while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v6) );
        v4 = i;
      }
    }
    ++v4;
  }
  for ( m = 0; m < this->m_SceneGlobalEvents.m_Size; ++m )
  {
    v12 = this->m_SceneGlobalEvents.m_Memory.m_pMemory[m];
    if ( v12 != nullptr )
      pfn(this: (CChoreoView *)((char *)this + (_DWORD)param1), a2: v12, a3: param1a);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428BC0
// Name: public: void CChoreoView::ResetTargetSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ResetTargetSettings(CChoreoView *this)
{
  int i; // esi
  CChoreoActorWidget *v3; // ecx

  for ( i = 0; i < this->m_SceneActors.m_Size; ++i )
  {
    v3 = this->m_SceneActors.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      CChoreoActorWidget::ResetSettings(this: v3);
  }
  models->ClearModelTargets(this: models, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00428C00
// Name: public: void CChoreoView::UpdateCurrentSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::UpdateCurrentSettings(CChoreoView *this)
{
  CChoreoView *v1; // edi
  int v2; // eax
  CChoreoActorWidget **m_pMemory; // ecx
  TimelineItem *v4; // esi
  CChoreoActor *Actor; // eax
  CChoreoActor *v6; // eax
  StudioModel *AssociatedModel; // eax
  StudioModel *v8; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v10; // eax
  CStudioHdr *v11; // edi
  const studiohdr_t *v12; // eax
  LocalFlexController_t v13; // esi
  int v14; // edi
  float flValue; // [esp+0h] [ebp-28h]
  float *current; // [esp+10h] [ebp-18h]
  StudioModel *defaultModel; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  CStudioHdr *hdr; // [esp+20h] [ebp-8h]
  int v21; // [esp+24h] [ebp-4h]

  v1 = this;
  defaultModel = models->GetActiveStudioModel(this: models);
  v2 = 0;
  i = 0;
  while ( v2 < v1->m_SceneActors.m_Size )
  {
    m_pMemory = v1->m_SceneActors.m_Memory.m_pMemory;
    v4 = (TimelineItem *)m_pMemory[v2];
    if ( v4 != nullptr )
    {
      Actor = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)m_pMemory[v2]);
      if ( CChoreoActor::GetActive(this: Actor) )
      {
        v6 = (CChoreoActor *)CActorBitmapButton::GetActor(this: v4);
        AssociatedModel = FindAssociatedModel(scene: v1->m_pScene, a: v6);
        v8 = AssociatedModel;
        if ( AssociatedModel != nullptr )
        {
          m_pStudioHdr = AssociatedModel->m_pStudioHdr;
          if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
          {
            hdr = v8->m_pStudioHdr;
            v11 = m_pStudioHdr;
LABEL_10:
            if ( v11 != nullptr )
            {
              current = CChoreoActorWidget::GetSettings(this: (CChoreoActorWidget *)v4);
              v12 = v11->m_pStudioHdr;
              v13 = DUMMY_NULL_FLEX_CONTROLLER;
              if ( v11->m_pStudioHdr->numflexcontrollers > 0 )
              {
                v21 = 0;
                do
                {
                  v14 = *(int *)((char *)&v12->checksum + v21 + v12->flexcontrollerindex);
                  if ( v14 != -1 )
                  {
                    if ( defaultModel == v8 && FlexPanel::IsEdited(this: g_pFlexPanel, iFlexController: v14) )
                    {
                      flValue = FlexPanel::GetSlider(this: g_pFlexPanel, iFlexController: v14);
                      StudioModel::SetFlexController(this: v8, iFlex: v13, flValue);
                    }
                    else
                    {
                      StudioModel::SetFlexController(this: v8, iFlex: v13, flValue: current[v14]);
                    }
                  }
                  v12 = hdr->m_pStudioHdr;
                  v21 += 20;
                  ++v13;
                }
                while ( v13 < hdr->m_pStudioHdr->numflexcontrollers );
              }
            }
            v1 = this;
            goto LABEL_20;
          }
          v10 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v8->m_MDLHandle);
          CStudioHdr::Init(this: v8->m_pStudioHdr, pStudioHdr: v10, mdlcache: nullptr);
          if ( v8->m_pStudioHdr->m_pStudioHdr != nullptr )
          {
            v11 = v8->m_pStudioHdr;
            hdr = v11;
            goto LABEL_10;
          }
        }
      }
    }
LABEL_20:
    v2 = i + 1;
    i = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428D60
// Name: public: class CChoreoChannelWidget __near * CChoreoView::FindChannelForEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannelWidget *__thiscall CChoreoView::FindChannelForEvent(CChoreoView *this, CChoreoEvent *event)
{
  int v2; // esi
  CChoreoActorWidget **m_pMemory; // eax
  CChoreoActorWidget *v4; // ebx
  int v5; // edi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v7; // esi
  int v8; // edi
  CAudioSourceWave *v9; // eax
  int i; // [esp+Ch] [ebp-Ch]
  CChoreoView *v12; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]

  v2 = 0;
  v12 = this;
  i = 0;
  if ( this->m_SceneActors.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    m_pMemory = this->m_SceneActors.m_Memory.m_pMemory;
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
      break;
LABEL_13:
    i = ++v2;
    if ( v2 >= this->m_SceneActors.m_Size )
      return nullptr;
  }
  v5 = 0;
  j = 0;
  if ( CChoreoWidgetDrawHelper::GetHeight(this: m_pMemory[v2]) <= 0 )
  {
LABEL_12:
    this = v12;
    goto LABEL_13;
  }
  while ( 1 )
  {
    Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v4, num: v5);
    v7 = (CChoreoChannelWidget *)Channel;
    if ( Channel != nullptr )
      break;
LABEL_10:
    j = ++v5;
    if ( v5 >= CChoreoWidgetDrawHelper::GetHeight(this: v4) )
    {
      v2 = i;
      goto LABEL_12;
    }
  }
  v8 = 0;
  if ( (int)CAudioMixerWave::GetChannel(this: Channel) <= 0 )
  {
LABEL_9:
    v5 = j;
    goto LABEL_10;
  }
  while ( 1 )
  {
    v9 = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v7, num: v8);
    if ( v9 != nullptr && CAudioSourceWave::GetHeader(this: v9) == (char *)event )
      return v7;
    if ( ++v8 >= (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v7) )
      goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428E30
// Name: public: class CChoreoEventWidget __near * CChoreoView::FindWidgetForEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceWave *__thiscall CChoreoView::FindWidgetForEvent(CChoreoView *this, CChoreoEvent *event)
{
  int v2; // edi
  CChoreoActorWidget *v3; // ebx
  int v4; // esi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v6; // esi
  int v7; // edi
  CAudioSourceWave *v8; // eax
  CAudioSourceWave *v9; // ebx
  CChoreoActorWidget *a; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  CChoreoView *v13; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  v2 = 0;
  v13 = this;
  i = 0;
  if ( this->m_SceneActors.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = this->m_SceneActors.m_Memory.m_pMemory[v2];
    a = v3;
    if ( v3 != nullptr )
      break;
LABEL_13:
    i = ++v2;
    if ( v2 >= this->m_SceneActors.m_Size )
      return nullptr;
  }
  v4 = 0;
  j = 0;
  if ( CChoreoWidgetDrawHelper::GetHeight(this: v3) <= 0 )
  {
LABEL_12:
    this = v13;
    goto LABEL_13;
  }
  while ( 1 )
  {
    Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v3, num: v4);
    v6 = (CChoreoChannelWidget *)Channel;
    if ( Channel != nullptr )
    {
      v7 = 0;
      if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
        break;
    }
LABEL_10:
    v4 = ++j;
    if ( j >= CChoreoWidgetDrawHelper::GetHeight(this: v3) )
    {
      v2 = i;
      goto LABEL_12;
    }
  }
  while ( 1 )
  {
    v8 = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v6, num: v7);
    v9 = v8;
    if ( v8 != nullptr && CAudioSourceWave::GetHeader(this: v8) == (char *)event )
      return v9;
    if ( ++v7 >= (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v6) )
    {
      v3 = a;
      goto LABEL_10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428F00
// Name: public: void CChoreoView::SelectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SelectAll(CChoreoView *this)
{
  CChoreoView::TraverseWidgets(this, pfn: CChoreoView::SelectAllEvents, param1: nullptr, param1a: nullptr);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428F20
// Name: public: void CChoreoView::DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DeselectAll(CChoreoView *this)
{
  CChoreoView::TraverseWidgets(this, pfn: CChoreoView::Deselect, param1: nullptr, param1a: nullptr);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428F40
// Name: public: void CChoreoView::PushRedo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::PushRedo(CChoreoView *this, const char *description)
{
  CChoreoScene *v3; // eax
  CChoreoScene *v4; // esi
  char *v5; // eax
  CChoreoView::CVUndo *undo; // [esp+8h] [ebp-4h]

  this->m_bRedoPending = false;
  v3 = (CChoreoScene *)operator new(nSize: 0x218u);
  if ( v3 != nullptr )
    v4 = CChoreoScene::CChoreoScene(this: v3, callback: &this->IChoreoEventCallback);
  else
    v4 = nullptr;
  CChoreoScene::operator=(this: v4, src: this->m_pScene);
  undo = this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1];
  undo->redo = v4;
  v5 = (char *)operator new(nSize: strlen(description) + 1);
  strcpy(v5, description);
  undo->rdescription = v5;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428FF0
// Name: public: char const __near * CChoreoView::GetUndoDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoView::GetUndoDescription(CChoreoView *this)
{
  int m_nUndoLevel; // eax

  m_nUndoLevel = this->m_nUndoLevel;
  if ( m_nUndoLevel != 0 )
    return this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel - 1]->udescription;
  else
    return "???undo";
}

//------------------------------------------------------------------------------
// Address: 0x00429010
// Name: public: char const __near * CChoreoView::GetRedoDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoView::GetRedoDescription(CChoreoView *this)
{
  int m_nUndoLevel; // eax

  m_nUndoLevel = this->m_nUndoLevel;
  if ( m_nUndoLevel == this->m_UndoStack.m_Size )
    return "???redo";
  else
    return this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel]->rdescription;
}

//------------------------------------------------------------------------------
// Address: 0x00429040
// Name: public: void CChoreoView::ExportVCDFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ExportVCDFile(CChoreoView *this, const char *filename)
{
  CChoreoView *v2; // ebx
  int v3; // eax
  CChoreoActorWidget *v4; // esi
  int v5; // edi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v7; // edi
  int v8; // ebx
  CChoreoEventWidget *Event; // eax
  CAudioSourceWave *v10; // esi
  char *Header; // eax
  CChoreoEvent *v12; // esi
  CChoreoActorWidget *a; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]

  v2 = this;
  Con_Printf(fmt: "Exporting to %s\n", filename);
  CChoreoScene::MarkForSaveAll(this: v2->m_pScene, mark: false);
  v3 = 0;
  for ( i = 0; v3 < v2->m_SceneActors.m_Size; i = v3 )
  {
    v4 = v2->m_SceneActors.m_Memory.m_pMemory[v3];
    a = v4;
    if ( v4 != nullptr )
    {
      v5 = 0;
      j = 0;
      if ( CChoreoWidgetDrawHelper::GetHeight(this: v4) > 0 )
      {
        do
        {
          Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v4, num: v5);
          v7 = (CChoreoChannelWidget *)Channel;
          if ( Channel != nullptr )
          {
            v8 = 0;
            if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
            {
              do
              {
                Event = CChoreoChannelWidget::GetEvent(this: v7, num: v8);
                v10 = (CAudioSourceWave *)Event;
                if ( Event != nullptr && Event->IsSelected(this: Event) )
                {
                  Header = CAudioSourceWave::GetHeader(this: v10);
                  v12 = (CChoreoEvent *)Header;
                  if ( Header != nullptr )
                  {
                    Header[376] |= 0x40u;
                    if ( CChoreoEvent::GetChannel(this: (CChoreoEvent *)Header) != nullptr )
                      CChoreoEvent::GetChannel(this: v12)->m_bMarkedForSave = true;
                    if ( CChoreoEvent::GetActor(this: v12) != nullptr )
                      CChoreoEvent::GetActor(this: v12)->m_bMarkedForSave = true;
                  }
                }
                ++v8;
              }
              while ( v8 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v7) );
              v4 = a;
            }
          }
          v5 = ++j;
        }
        while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v4) );
        v2 = this;
      }
    }
    v3 = i + 1;
  }
  CChoreoScene::ExportMarkedToFile(this: v2->m_pScene, filename);
}

//------------------------------------------------------------------------------
// Address: 0x00429180
// Name: public: void CChoreoView::ExportVCD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ExportVCD(CChoreoView *this)
{
  char scenefile[512]; // [esp+4h] [ebp-200h] BYREF

  if ( FacePoser_ShowSaveFileNameDialog(relative: scenefile, bufsize: 0x200u, subdir: "scenes", wildcard: "*.vcd") )
  {
    V_DefaultExtension(path: scenefile, extension: ".vcd", pathStringLength: 512);
    CChoreoView::ExportVCDFile(this, filename: scenefile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004291E0
// Name: public: void CChoreoView::SelectEvents(struct CChoreoView::SelectionParams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SelectEvents(CChoreoView *this, CChoreoView::SelectionParams_t *params)
{
  CChoreoView *v2; // ebx
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  int v4; // eax
  CChoreoActorWidget *v5; // edi
  int v6; // esi
  CAudioSourceWave *v7; // eax
  CChoreoChannelWidget *v8; // ebx
  char *v9; // eax
  int v10; // esi
  CAudioSourceWave *Event; // eax
  CAudioSourceWave *v12; // esi
  char *Header; // eax
  CChoreoEvent *v14; // edi
  double EndTime; // st7
  int v16; // eax
  CChoreoGlobalEventWidget **m_pMemory; // ecx
  CChoreoGlobalEventWidget *v18; // esi
  CChoreoEvent *Actor; // eax
  CChoreoEvent *v20; // edi
  double StartTime; // st7
  CChoreoActorWidget *a; // [esp+8h] [ebp-18h]
  int i; // [esp+Ch] [ebp-14h]
  float ia; // [esp+Ch] [ebp-14h]
  int j; // [esp+10h] [ebp-10h]
  int ja; // [esp+10h] [ebp-10h]
  int k; // [esp+14h] [ebp-Ch]
  float v29; // [esp+18h] [ebp-8h]
  char *channel; // [esp+1Ch] [ebp-4h]

  v2 = this;
  if ( this->m_pScene != nullptr
    && this->m_pClickedActor != nullptr
    && (params->type != 0 || this->m_pClickedChannel != nullptr) )
  {
    m_pClickedChannel = this->m_pClickedChannel;
    if ( m_pClickedChannel != nullptr )
      channel = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)m_pClickedChannel);
    else
      channel = nullptr;
    v4 = 0;
    for ( i = 0; v4 < v2->m_SceneActors.m_Size; i = v4 )
    {
      v5 = v2->m_SceneActors.m_Memory.m_pMemory[v4];
      a = v5;
      if ( v5 != nullptr )
      {
        v6 = 0;
        j = 0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: v5) > 0 )
        {
          do
          {
            v7 = (CAudioSourceWave *)CChoreoActorWidget::GetChannel(this: v5, num: v6);
            v8 = (CChoreoChannelWidget *)v7;
            if ( v7 != nullptr && (params->type != 0 || CAudioSourceWave::GetHeader(this: v7) == channel) )
            {
              if ( params->type != 1
                || (v9 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v8),
                    CChoreoChannel::GetActive(this: (CChoreoChannel *)v9)) )
              {
                v10 = 0;
                k = 0;
                if ( (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v8) > 0 )
                {
                  while ( 1 )
                  {
                    Event = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v8, num: v10);
                    v12 = Event;
                    if ( Event == nullptr )
                      goto LABEL_27;
                    Header = CAudioSourceWave::GetHeader(this: Event);
                    v14 = (CChoreoEvent *)Header;
                    if ( Header != nullptr )
                    {
                      if ( params->forward )
                      {
                        if ( CChoreoEvent::GetStartTime(this: (CChoreoEvent *)Header) < (double)params->time )
                          goto LABEL_27;
                      }
                      else
                      {
                        if ( CChoreoEvent::CurveHasEndTime(this: (CChoreoEvent *)Header) )
                          EndTime = CChoreoEvent::GetEndTime(this: v14);
                        else
                          EndTime = CChoreoEvent::GetStartTime(this: v14);
                        v29 = EndTime;
                        if ( params->time < v29 )
                          goto LABEL_27;
                      }
                      ((void (__thiscall *)(CAudioSourceWave *, int))v12->IsStreaming)(a1: v12, a2: 1);
                    }
LABEL_27:
                    v10 = ++k;
                    if ( k >= (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v8) )
                    {
                      v5 = a;
                      break;
                    }
                  }
                }
              }
            }
            v6 = ++j;
          }
          while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v5) );
          v2 = this;
        }
      }
      v4 = i + 1;
    }
    v16 = 0;
    for ( ja = 0; v16 < v2->m_SceneGlobalEvents.m_Size; ja = v16 )
    {
      m_pMemory = v2->m_SceneGlobalEvents.m_Memory.m_pMemory;
      v18 = m_pMemory[v16];
      if ( v18 == nullptr )
        goto LABEL_43;
      Actor = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)m_pMemory[v16]);
      v20 = Actor;
      if ( Actor != nullptr )
      {
        if ( params->forward )
        {
          if ( CChoreoEvent::GetStartTime(this: Actor) < (double)params->time )
            goto LABEL_43;
        }
        else
        {
          if ( CChoreoEvent::CurveHasEndTime(this: Actor) )
            StartTime = CChoreoEvent::GetEndTime(this: v20);
          else
            StartTime = CChoreoEvent::GetStartTime(this: v20);
          ia = StartTime;
          if ( params->time < ia )
            goto LABEL_43;
        }
        v18->SetSelected(this: v18, a2: true);
      }
LABEL_43:
      v16 = ja + 1;
    }
    v2->redraw(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429420
// Name: void SuggestCaption(char __near *,int,class CUtlVector<class CChoreoEvent __near *,class CUtlMemory<class CChoreoEvent __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SuggestCaption(
        char *dest,
        unsigned int destlen,
        CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > *events)
{
  int v4; // esi
  CChoreoEvent *v5; // edi
  const wchar_t *v6; // eax
  IFacePoserSound_vtbl *v7; // esi
  const char *v8; // eax
  char *v9; // eax
  int v10; // eax
  CSentence *v11; // eax
  char *Text; // eax
  char ansi[1024]; // [esp+8h] [ebp-444h] BYREF
  char tok[64]; // [esp+408h] [ebp-44h] BYREF
  int c; // [esp+448h] [ebp-4h]
  int i; // [esp+454h] [ebp+8h]

  *dest = 0;
  v4 = 0;
  c = events->m_Size;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v5 = events->m_Memory.m_pMemory[v4];
      if ( CChoreoEvent::GetPlaybackCloseCaptionToken(this: v5, dest: tok, destlen: 64) )
      {
        v6 = g_pLocalize->Find(this: g_pLocalize, a2: tok);
        if ( v6 != nullptr )
          break;
      }
      v7 = sound->__vftable;
      v8 = FacePoser_TranslateSoundName(event: v5);
      v9 = va(fmt: "sound/%s", v8);
      v10 = (int)v7->LoadSound(this: sound, a2: v9);
      if ( v10 != 0 )
      {
        v11 = (CSentence *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 48))(a1: v10);
        if ( v11 != nullptr )
        {
          Text = CSentence::GetText(this: v11);
          V_strncat(pDest: dest, pSrc: Text, destBufferSize: destlen, max_chars_to_copy: -1);
          v4 = i;
LABEL_8:
          if ( _V_strlen(str: dest) > 0 && v4 != c - 1 )
            V_strncat(pDest: dest, pSrc: " ", destBufferSize: destlen, max_chars_to_copy: -1);
          goto LABEL_12;
        }
      }
      v4 = i;
LABEL_12:
      i = ++v4;
      if ( v4 >= c )
        return;
    }
    g_pLocalize->ConvertUnicodeToANSI(this: g_pLocalize, a2: v6, a3: ansi, a4: 1024);
    V_strncat(pDest: dest, pSrc: ansi, destBufferSize: destlen, max_chars_to_copy: -1);
    goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429540
// Name: FindMetric
// Source: json
//------------------------------------------------------------------------------
int __usercall FindMetric@<eax>(
        double EndTime@<st0>,
        int type,
        CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > *list,
        float *value)
{
  int v5; // esi
  CChoreoEvent *v6; // edi
  bool v7; // cf
  int c; // [esp+0h] [ebp-10h]
  int bestIndex; // [esp+4h] [ebp-Ch]
  float val; // [esp+8h] [ebp-8h]
  float bestVal; // [esp+Ch] [ebp-4h]
  char greater_3; // [esp+1Bh] [ebp+Bh]

  bestVal = 999999.0;
  bestIndex = -1;
  if ( type == 1 || type == 3 )
  {
    bestVal = -999999.0;
    greater_3 = 1;
  }
  else
  {
    greater_3 = 0;
  }
  v5 = 0;
  c = list->m_Size;
  if ( c > 0 )
  {
    do
    {
      v6 = list->m_Memory.m_pMemory[v5];
      if ( type == 0 || CChoreoEvent::CurveHasEndTime(this: list->m_Memory.m_pMemory[v5]) )
      {
        if ( type == 1 )
        {
          EndTime = CChoreoEvent::GetEndTime(this: v6);
        }
        else if ( (unsigned int)(type - 2) > 1 )
        {
          EndTime = CChoreoEvent::GetStartTime(this: v6);
        }
        else
        {
          ((void (__fastcall *)(CChoreoEvent *))v6->GetDuration)(a1: v6);
        }
        val = EndTime;
        if ( greater_3 != 0 )
          v7 = bestVal < val;
        else
          v7 = val < bestVal;
        if ( v7 )
        {
          bestVal = EndTime;
          bestIndex = v5;
        }
      }
      ++v5;
    }
    while ( v5 < c );
  }
  *value = bestVal;
  return bestIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00429610
// Name: public: void CChoreoView::SelectAllEventsInActor(class CChoreoActorWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SelectAllEventsInActor(CChoreoView *this, CChoreoActorWidget *actor)
{
  CChoreoView::TraverseWidgets(this, pfn: CChoreoView::SelectInActor, param1: nullptr, param1a: actor);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00429640
// Name: public: void CChoreoView::SelectAllEventsInChannel(class CChoreoChannelWidget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SelectAllEventsInChannel(CChoreoView *this, CChoreoChannelWidget *channel)
{
  CChoreoView::TraverseWidgets(this, pfn: CChoreoView::SelectInChannel, param1: nullptr, param1a: channel);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A800
// Name: public: virtual void CChoreoView::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::redraw(CChoreoView *this)
{
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // edx
  int v3; // edi
  int Height; // eax
  int m_nScrollbarHeight; // ecx
  int v6; // eax
  int v7; // eax
  CChoreoScene *m_pScene; // ecx
  int PixelForTimeValue; // eax
  int StartRow; // eax
  int v11; // eax
  int m_Size; // edx
  int v13; // xmm0_4
  int v14; // eax
  int v15; // xmm0_4
  const char *Name; // eax
  CChoreoScene *v17; // esi
  int TimeZoom; // eax
  int m_nUndoLevel; // [esp-14h] [ebp-210h]
  float left_4; // [esp+4h] [ebp-1F8h]
  int left_4a; // [esp+4h] [ebp-1F8h]
  int right; // [esp+8h] [ebp-1F4h]
  char string[256]; // [esp+18h] [ebp-1E4h] BYREF
  char sz[48]; // [esp+118h] [ebp-E4h] BYREF
  tagRECT rcClip; // [esp+148h] [ebp-B4h] BYREF
  CChoreoWidgetDrawHelper drawHelper; // [esp+158h] [ebp-A4h] BYREF
  tagRECT rcInfo; // [esp+1B0h] [ebp-4Ch] BYREF
  int finishx; // [esp+1C0h] [ebp-3Ch]
  tagRECT v29; // [esp+1C4h] [ebp-38h] BYREF
  tagRECT rcText; // [esp+1D4h] [ebp-28h] BYREF
  tagRECT rc; // [esp+1E4h] [ebp-18h] BYREF
  bool clipped; // [esp+1F7h] [ebp-5h] BYREF
  Color bgColor; // [esp+1F8h] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) && !this->m_bSuppressLayout )
  {
    CChoreoView::LayoutScene(this);
    bgColor = (Color)14479600;
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, &bgColor);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &drawHelper);
    if ( this->m_bCanDraw )
    {
      GetCaptionHeight = this->GetCaptionHeight;
      rc.left = 0;
      v3 = GetCaptionHeight(this: &this->IFacePoserToolWindow);
      rc.top = v3;
      rc.right = CAudioMixerWave::GetModelIndex(this: (CAudioMixerWave *)&drawHelper);
      Height = CChoreoWidgetDrawHelper::GetHeight(this: (CChoreoActorWidget *)&drawHelper);
      m_nScrollbarHeight = this->m_nScrollbarHeight;
      rc.bottom = Height;
      rcInfo.bottom = Height - m_nScrollbarHeight;
      rcInfo.top = Height - m_nScrollbarHeight - this->m_nInfoHeight;
      rcInfo.left = 0;
      rcInfo.right = rc.right - m_nScrollbarHeight;
      CChoreoWidgetDrawHelper::StartClipping(this: &drawHelper, clipRect: &rcInfo);
      CChoreoView::RedrawStatusArea(this, &drawHelper, rcStatus: (int)&rcInfo);
      CChoreoWidgetDrawHelper::StopClipping(this: &drawHelper);
      v6 = rc.bottom - this->m_nInfoHeight - this->m_nScrollbarHeight;
      *(_QWORD *)&rcClip.left = *(_QWORD *)&rc.left;
      rcClip.right = _mm_loadl_epi64((const __m128i *)&rc.right).m128i_u32[0];
      rcClip.bottom = v6;
      CChoreoWidgetDrawHelper::StartClipping(this: &drawHelper, clipRect: &rcClip);
      if ( this->m_pScene == nullptr )
      {
        sprintf(string, format: "No choreography scene file (.vcd) loaded");
        v7 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)0x12, weight: 400, fmt: string);
        v29.top = (rc.bottom - v3) / 2 - 9;
        v29.bottom = v29.top + 28;
        v29.left = rc.right / 2 - v7 / 2;
        v29.right = v7 + v29.left;
        bgColor = (Color)7910580;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: &drawHelper,
          font: "Arial",
          pointsize: 18,
          weight: 400,
          clr: &bgColor,
          rcText: &v29,
          fmt: string);
        CChoreoWidgetDrawHelper::StopClipping(this: &drawHelper);
        CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
        return;
      }
      CChoreoView::DrawTimeLine(this, (int)&drawHelper, &rc, left: this->m_flStartTime, right: this->m_flEndTime);
      m_pScene = this->m_pScene;
      clipped = false;
      left_4 = CChoreoScene::FindStopTime(this: m_pScene);
      PixelForTimeValue = CChoreoView::GetPixelForTimeValue(this, time: left_4, &clipped);
      finishx = PixelForTimeValue;
      if ( !clipped )
      {
        right = rc.bottom;
        left_4a = PixelForTimeValue;
        bgColor = (Color)16711680;
        StartRow = CChoreoView::GetStartRow(this);
        CChoreoWidgetDrawHelper::DrawColoredLine(
          this: &drawHelper,
          clr: (HPEN__ *)&bgColor,
          style: 2,
          width: 1,
          x1: finishx,
          y1: v3 + StartRow,
          x2: left_4a,
          y2: right);
      }
      CChoreoView::DrawRelativeTagLines(this, &drawHelper, &rc);
      CChoreoView::DrawBackground(this, &drawHelper, &rc);
      CChoreoView::DrawSceneABTicks(this, (int)&drawHelper);
      CChoreoWidgetDrawHelper::StopClipping(this: &drawHelper);
      if ( this->m_UndoStack.m_Size > 0 )
      {
        v11 = CChoreoWidgetDrawHelper::CalcTextWidth(
                font: "Arial",
                pointsize: (HFONT__ *)9,
                weight: 400,
                fmt: "undo %i/%i",
                this->m_nUndoLevel,
                this->m_UndoStack.m_Size);
        m_Size = this->m_UndoStack.m_Size;
        *(_QWORD *)&v29.left = *(_QWORD *)&rc.left;
        v13 = _mm_loadl_epi64((const __m128i *)&rc.right).m128i_u32[0];
        v29.top = v3 + 48;
        v29.right = v13;
        v29.bottom = v3 + 58;
        v29.left = this->m_nLabelWidth - v11 - 20;
        m_nUndoLevel = this->m_nUndoLevel;
        v29.right = v11 + v29.left;
        bgColor = (Color)&g_flexedverts[1899];
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: &drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          clr: &bgColor,
          rcText: &v29,
          fmt: "undo %i/%i",
          m_nUndoLevel,
          m_Size);
      }
      CChoreoView::DrawScrubHandle(this, a2: v3, &drawHelper);
      sprintf(string: sz, format: "Speed: %.2fx", this->m_flPlaybackRate);
      v14 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
      *(_QWORD *)&rcText.left = *(_QWORD *)&rc.left;
      v15 = _mm_loadl_epi64((const __m128i *)&rc.right).m128i_u32[0];
      rcText.top = v3 + 35;
      rcText.right = v15;
      rcText.bottom = v3 + 45;
      rcText.left = this->m_nLabelWidth + 20;
      rcText.right = v14 + rcText.left;
      strcpy((char *)&bgColor, "222");
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: &bgColor,
        &rcText,
        fmt: sz);
      Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v17 = this->m_pScene;
      if ( v17 != nullptr )
        TimeZoom = CChoreoScene::GetTimeZoom(this: v17, tool: Name);
      else
        TimeZoom = 100;
      sprintf(string: sz, format: "Zoom: %.2fx", (float)((float)TimeZoom * 0.0099999998));
      rcText.right = CChoreoWidgetDrawHelper::CalcTextWidth(
                       font: "Arial",
                       pointsize: (HFONT__ *)9,
                       weight: 400,
                       fmt: sz)
                   + 5;
      rcText.top = v3 + 48;
      rcText.left = 5;
      rcText.bottom = v3 + 58;
      strcpy((char *)&bgColor, "222");
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: &bgColor,
        &rcText,
        fmt: sz);
    }
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042ACC0
// Name: public: void CChoreoView::ProcessFlexAnimation(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessFlexAnimation(CChoreoView *this, CChoreoScene *scene, CChoreoEvent *event)
{
  CChoreoActor *Actor; // eax
  StudioModel *AssociatedModel; // eax
  StudioModel *v6; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v8; // eax
  CStudioHdr *v9; // esi
  int v10; // esi
  TimelineItem *v11; // edi
  CChoreoActor *v12; // eax
  CChoreoActor *Name; // eax
  CChoreoEvent *v14; // esi
  CAudioSourceWave *WidgetForEvent; // eax
  int v16; // edi
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v18; // esi
  int v19; // edi
  int v20; // eax
  int v21; // ebx
  int i; // edi
  int FlexControllerIndex; // ebx
  int v24; // edi
  float time; // [esp+0h] [ebp-2Ch]
  float timea; // [esp+0h] [ebp-2Ch]
  CChoreoActor *scenetime; // [esp+4h] [ebp-28h]
  float scenetimea; // [esp+4h] [ebp-28h]
  StudioModel *model; // [esp+14h] [ebp-18h]
  CChoreoActor *a; // [esp+18h] [ebp-14h]
  CChoreoActor *aa; // [esp+18h] [ebp-14h]
  float *current; // [esp+1Ch] [ebp-10h]
  float weight; // [esp+20h] [ebp-Ch]
  CStudioHdr *flIntensity; // [esp+24h] [ebp-8h]
  float flIntensitya; // [esp+24h] [ebp-8h]
  float flIntensityb; // [esp+24h] [ebp-8h]
  bool bUpdateSliders; // [esp+2Bh] [ebp-1h]

  Actor = CChoreoEvent::GetActor(this: event);
  AssociatedModel = FindAssociatedModel(scene, a: Actor);
  v6 = AssociatedModel;
  model = AssociatedModel;
  if ( AssociatedModel != nullptr )
  {
    m_pStudioHdr = AssociatedModel->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      flIntensity = v6->m_pStudioHdr;
    }
    else
    {
      v8 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v6->m_MDLHandle);
      CStudioHdr::Init(this: v6->m_pStudioHdr, pStudioHdr: v8, mdlcache: nullptr);
      v9 = v6->m_pStudioHdr;
      if ( v9->m_pStudioHdr == nullptr )
        return;
      flIntensity = v9;
    }
    if ( flIntensity != nullptr )
    {
      v10 = 0;
      a = CChoreoEvent::GetActor(this: event);
      if ( this->m_SceneActors.m_Size > 0 )
      {
        do
        {
          v11 = (TimelineItem *)this->m_SceneActors.m_Memory.m_pMemory[v10];
          if ( v11 != nullptr )
          {
            scenetime = CChoreoActor::GetName(this: a);
            v12 = (CChoreoActor *)CActorBitmapButton::GetActor(this: v11);
            Name = CChoreoActor::GetName(this: v12);
            if ( _V_stricmp(s1: Name->m_szName, s2: scenetime->m_szName) == 0 )
              break;
          }
          ++v10;
        }
        while ( v10 < this->m_SceneActors.m_Size );
        if ( v11 != nullptr && v10 < this->m_SceneActors.m_Size )
        {
          v14 = event;
          current = CChoreoActorWidget::GetSettings(this: (CChoreoActorWidget *)v11);
          if ( !CChoreoEvent::GetTrackLookupSet(this: event) )
            SetupFlexControllerTracks(hdr: flIntensity, event);
          scenetimea = CChoreoScene::GetTime(this: scene);
          weight = CChoreoEvent::GetIntensity(this: event, scenetime: scenetimea);
          WidgetForEvent = CChoreoView::FindWidgetForEvent(this, event);
          if ( WidgetForEvent == nullptr
            || !WidgetForEvent->IsLooped(this: WidgetForEvent)
            || (bUpdateSliders = true, model != models->GetActiveStudioModel(this: models)) )
          {
            bUpdateSliders = false;
          }
          v16 = 0;
          for ( aa = nullptr; (int)aa < CChoreoEvent::GetNumFlexAnimationTracks(this: event); v16 = (int)aa )
          {
            FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: v14, index: v16);
            v18 = FlexAnimationTrack;
            if ( FlexAnimationTrack != nullptr )
            {
              if ( CFlexAnimationTrack::IsTrackActive(this: FlexAnimationTrack) )
              {
                if ( CFlexAnimationTrack::IsComboType(this: v18) )
                {
                  for ( i = 0; i < 2; ++i )
                  {
                    FlexControllerIndex = CFlexAnimationTrack::GetFlexControllerIndex(this: v18, side: i);
                    if ( FlexControllerIndex != -1 )
                    {
                      time = CChoreoScene::GetTime(this: scene);
                      flIntensitya = CFlexAnimationTrack::GetIntensity(this: v18, time, side: i);
                      if ( bUpdateSliders
                        && !FlexPanel::IsEdited(this: g_pFlexPanel, iFlexController: FlexControllerIndex) )
                      {
                        FlexPanel::SetSlider(
                          this: g_pFlexPanel,
                          iFlexController: FlexControllerIndex,
                          value: flIntensitya);
                        FlexPanel::SetInfluence(this: g_pFlexPanel, iFlexController: FlexControllerIndex, value: 1.0);
                      }
                      current[FlexControllerIndex] = (float)((float)(1.0 - weight) * current[FlexControllerIndex])
                                                   + (float)(flIntensitya * weight);
                    }
                  }
                }
                else
                {
                  v24 = CFlexAnimationTrack::GetFlexControllerIndex(this: v18, side: 0);
                  if ( v24 != -1 )
                  {
                    timea = CChoreoScene::GetTime(this: scene);
                    flIntensityb = CFlexAnimationTrack::GetIntensity(this: v18, time: timea, side: 0);
                    if ( bUpdateSliders && !FlexPanel::IsEdited(this: g_pFlexPanel, iFlexController: v24) )
                    {
                      FlexPanel::SetSlider(this: g_pFlexPanel, iFlexController: v24, value: flIntensityb);
                      FlexPanel::SetInfluence(this: g_pFlexPanel, iFlexController: v24, value: 1.0);
                    }
                    current[v24] = (float)((float)(1.0 - weight) * current[v24]) + (float)(flIntensityb * weight);
                  }
                }
              }
              else if ( bUpdateSliders )
              {
                v19 = 0;
                if ( CFlexAnimationTrack::IsComboType(this: v18) != -1 )
                {
                  do
                  {
                    v20 = CFlexAnimationTrack::GetFlexControllerIndex(this: v18, side: v19);
                    v21 = v20;
                    if ( v20 != -1 && !FlexPanel::IsEdited(this: g_pFlexPanel, iFlexController: v20) )
                    {
                      FlexPanel::SetSlider(this: g_pFlexPanel, iFlexController: v21, value: 0.0);
                      FlexPanel::SetInfluence(this: g_pFlexPanel, iFlexController: v21, value: 0.0);
                    }
                    ++v19;
                  }
                  while ( v19 < CFlexAnimationTrack::IsComboType(this: v18) + 1 );
                }
              }
            }
            v14 = event;
            aa = (CChoreoActor *)((char *)aa + 1);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B040
// Name: public: virtual void CChoreoView::ProcessEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ProcessEvent(
        CChoreoView *this,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  CChoreoActor *Actor; // eax
  CChoreoChannel *Channel; // eax

  if ( event != nullptr && CChoreoEvent::GetActive(this: event) )
  {
    Actor = CChoreoEvent::GetActor(this: event);
    if ( Actor == nullptr || CChoreoActor::GetActive(this: Actor) )
    {
      Channel = CChoreoEvent::GetChannel(this: event);
      if ( Channel == nullptr || CChoreoChannel::GetActive(this: Channel) )
      {
        switch ( CChoreoEvent::GetType(this: event) )
        {
          case 2:
            CChoreoView::ProcessExpression(this: (CChoreoView *)((char *)this - 632), scene, event);
            break;
          case 3:
            CChoreoView::ProcessLookat(this: (CChoreoView *)((char *)this - 632), a2: (int)this, scene, event);
            break;
          case 4:
            CChoreoView::ProcessMoveto(this: (CChoreoView *)((char *)this - 632), scene, event);
            break;
          case 5:
            CChoreoView::ProcessSpeak(this: (CChoreoView *)((char *)this - 632), a2: (int)this, scene, event);
            break;
          case 6:
            CChoreoView::ProcessGesture(this: (CChoreoView *)((char *)this - 632), scene, event);
            break;
          case 7:
            CChoreoView::ProcessSequence(this: (CChoreoView *)((char *)this - 632), scene, event: *(float *)&event);
            break;
          case 8:
            CChoreoView::ProcessFace(this: (CChoreoView *)((char *)this - 632), scene, event);
            break;
          case 10:
            CChoreoView::ProcessFlexAnimation(this: (CChoreoView *)((char *)this - 632), scene, event);
            break;
          case 11:
            CChoreoView::ProcessSubscene(this: (CChoreoView *)((char *)this - 632), scene, event);
            break;
          default:
            return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B1B0
// Name: public: void CChoreoView::SceneThink(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SceneThink(CChoreoView *this, float time)
{
  CChoreoScene *m_pScene; // ecx
  bool IsAnyToolScrubbing; // bl
  bool IsAnyToolProcessing; // al
  bool autoprocess_3; // [esp+13h] [ebp+Bh]

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
  {
    if ( this->m_bSimulating )
    {
      if ( this->m_bPaused )
      {
        CChoreoView::PauseThink(this);
      }
      else
      {
        CChoreoScene::SetSoundFileStartupLatency(this: m_pScene, time: 0.0);
        models->CheckResetFlexes(this: models);
        CChoreoView::ResetTargetSettings(this);
        models->ClearOverlaysSequences(this: models);
        CChoreoScene::Think(this: this->m_pScene, curtime: time);
        CChoreoView::UpdateCurrentSettings(this);
      }
    }
    else
    {
      CChoreoView::FinishSimulation(this);
    }
    if ( !ControlPanel::AllToolsDriveSpeech(this: g_pControlPanel)
      && !IFacePoserToolWindow::IsActiveTool(this: &this->IFacePoserToolWindow)
      || !IFacePoserToolWindow::IsAnyToolScrubbing() && !IFacePoserToolWindow::IsAnyToolProcessing() )
    {
      autoprocess_3 = IFacePoserToolWindow::ShouldAutoProcess();
      IsAnyToolScrubbing = IFacePoserToolWindow::IsAnyToolScrubbing();
      IsAnyToolProcessing = IFacePoserToolWindow::IsAnyToolProcessing();
      if ( !IsAnyToolScrubbing && !IsAnyToolProcessing && autoprocess_3 && !this->m_bForceProcess )
        sound->StopAll(this: sound);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B2A0
// Name: public: void CChoreoView::DeleteSceneWidgets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DeleteSceneWidgets(CChoreoView *this)
{
  bool m_bCanDraw; // al
  int v3; // ebx
  CChoreoActorWidget *v4; // edi
  int i; // edi
  CChoreoGlobalEventWidget *v6; // ecx
  bool oldcandraw; // [esp+Bh] [ebp-1h]

  m_bCanDraw = this->m_bCanDraw;
  this->m_bCanDraw = false;
  *(_QWORD *)&this->m_Flyover.a = 0;
  *(_QWORD *)&this->m_Flyover.e = 0;
  v3 = 0;
  *(_QWORD *)&this->m_Flyover.tag = 0;
  this->m_Flyover.ccbutton = 0;
  for ( oldcandraw = m_bCanDraw; v3 < this->m_SceneActors.m_Size; ++v3 )
  {
    v4 = this->m_SceneActors.m_Memory.m_pMemory[v3];
    this->m_ActorExpanded[v3].expanded = CChoreoActorWidget::GetShowChannels(this: v4);
    if ( v4 != nullptr )
      ((void (__thiscall *)(CChoreoActorWidget *, int))v4->dtr_CChoreoWidget)(a1: v4, a2: 1);
  }
  this->m_SceneActors.m_Size = 0;
  for ( i = 0; i < this->m_SceneGlobalEvents.m_Size; ++i )
  {
    v6 = this->m_SceneGlobalEvents.m_Memory.m_pMemory[i];
    if ( v6 != nullptr )
      ((void (__thiscall *)(CChoreoGlobalEventWidget *, int))v6->dtr_CChoreoWidget)(a1: v6, a2: 1);
  }
  this->m_SceneGlobalEvents.m_Size = 0;
  this->m_pClickedActor = nullptr;
  this->m_pClickedChannel = nullptr;
  this->m_pClickedEvent = nullptr;
  this->m_pClickedGlobalEvent = nullptr;
  this->m_bCanDraw = oldcandraw;
}

//------------------------------------------------------------------------------
// Address: 0x0042B380
// Name: public: void CChoreoView::InvalidateLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::InvalidateLayout(CChoreoView *this)
{
  CChoreoScene *m_pScene; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // edx

  if ( !this->m_bSuppressLayout )
  {
    if ( CChoreoView::ComputeHPixelsNeeded(this) != this->m_nLastHPixelsNeeded )
      CChoreoView::RepositionHSlider(this);
    if ( CChoreoView::ComputeVPixelsNeeded(this) != this->m_nLastVPixelsNeeded )
      CChoreoView::RepositionVSlider(this);
    m_pScene = this->m_pScene;
    if ( m_pScene != nullptr )
    {
      CChoreoScene::ReconcileGestureTimes(this: m_pScene);
      CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
    }
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B3F0
// Name: public: void CChoreoView::GetObjectsUnderMouse(int,int,class CChoreoActorWidget __near * __near *,class CChoreoChannelWidget __near * __near *,class CChoreoEventWidget __near * __near *,class CChoreoGlobalEventWidget __near * __near *,int __near *,class CEventAbsoluteTag __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::GetObjectsUnderMouse(
        CChoreoView *this,
        int mx,
        int my,
        CChoreoActorWidget **actor,
        CChoreoChannelWidget **channel,
        CChoreoEventWidget **event,
        CChoreoGlobalEventWidget **globalevent,
        int *clickedTag,
        CEventAbsoluteTag **absolutetag,
        int *clickedCCArea)
{
  CChoreoChannelWidget *ChannelUnderCursorPos; // eax
  CChoreoEventWidget **v12; // ecx
  int TagUnderCursorPos; // eax

  if ( actor != nullptr )
    *actor = CChoreoView::GetActorUnderCursorPos(this, mx, my);
  if ( channel != nullptr )
  {
    ChannelUnderCursorPos = (CChoreoChannelWidget *)CChoreoView::GetChannelUnderCursorPos(this, mx, my);
    *channel = ChannelUnderCursorPos;
    if ( ChannelUnderCursorPos != nullptr && clickedCCArea != nullptr )
      *clickedCCArea = CChoreoChannelWidget::GetChannelItemUnderMouse(this: ChannelUnderCursorPos, mx, my);
  }
  v12 = event;
  if ( event != nullptr )
  {
    *event = CChoreoView::GetEventUnderCursorPos(this, mx, my);
    v12 = event;
  }
  if ( globalevent != nullptr )
  {
    *globalevent = CChoreoView::GetGlobalEventUnderCursorPos(this, mx, my);
    v12 = event;
  }
  if ( clickedTag != nullptr )
  {
    if ( v12 != nullptr && *v12 != nullptr )
    {
      TagUnderCursorPos = CChoreoView::GetTagUnderCursorPos(this, event: *v12, mx, my);
      v12 = event;
      *clickedTag = TagUnderCursorPos;
    }
    else
    {
      *clickedTag = -1;
    }
  }
  if ( absolutetag != nullptr )
  {
    if ( v12 != nullptr && *v12 != nullptr )
    {
      *absolutetag = CChoreoView::GetAbsoluteTagUnderCursorPos(this, event: (CAudioSourceWave *)*v12, mx, my);
      this->m_nSelectedEvents = CChoreoView::CountSelectedEvents(this);
      return;
    }
    *absolutetag = nullptr;
  }
  this->m_nSelectedEvents = CChoreoView::CountSelectedEvents(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042B4F0
// Name: public: void CChoreoView::UpdateStatusArea(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::UpdateStatusArea(CChoreoView *this, int mx, int my)
{
  HWND Handle; // eax
  int m_nScrollbarHeight; // ecx
  HWND v6; // eax
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-84h] BYREF
  CChoreoView::FLYOVER fo; // [esp+5Ch] [ebp-2Ch] BYREF
  tagRECT rcClip; // [esp+78h] [ebp-10h] BYREF

  CChoreoView::GetObjectsUnderMouse(
    this,
    mx,
    my,
    actor: &fo.a,
    channel: &fo.c,
    event: &fo.e,
    globalevent: &fo.ge,
    clickedTag: &fo.tag,
    absolutetag: &fo.at,
    clickedCCArea: &fo.ccbutton);
  if ( fo.a != nullptr )
    this->m_Flyover.a = fo.a;
  if ( fo.e != nullptr )
    this->m_Flyover.e = fo.e;
  if ( fo.c != nullptr )
    this->m_Flyover.c = fo.c;
  if ( fo.ge != nullptr )
    this->m_Flyover.ge = fo.ge;
  if ( fo.tag != -1 )
    this->m_Flyover.tag = fo.tag;
  if ( fo.ccbutton != -1 )
    this->m_Flyover.ccbutton = fo.ccbutton;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rcClip);
  m_nScrollbarHeight = this->m_nScrollbarHeight;
  rcClip.right -= m_nScrollbarHeight;
  rcClip.bottom -= m_nScrollbarHeight;
  rcClip.top = rcClip.bottom - this->m_nInfoHeight;
  my = 14479600;
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
    this: &drawHelper,
    widget: this,
    bounds: &rcClip,
    bgColor: (const Color *)&my);
  CChoreoWidgetDrawHelper::StartClipping(this: &drawHelper, clipRect: &rcClip);
  CChoreoView::RedrawStatusArea(this, &drawHelper, rcStatus: (int)&rcClip);
  CChoreoWidgetDrawHelper::StopClipping(this: &drawHelper);
  v6 = (HWND)mxWidget::getHandle(this);
  ValidateRect(hWnd: v6, lpRect: &rcClip);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x0042B610
// Name: public: void CChoreoView::MoveEventToBack(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MoveEventToBack(CChoreoView *this, CChoreoEvent *event)
{
  int v2; // edi
  CChoreoActorWidget *v3; // ebx
  int v4; // esi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v6; // esi
  int v7; // edi
  CAudioSourceWave *v8; // eax
  CChoreoEventWidget *v9; // ebx
  CChoreoScene *m_pScene; // ecx
  int v11; // eax
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v14; // ecx
  int TimeZoom; // eax
  int v16; // ebx
  int k; // edi
  CChoreoActorWidget *v18; // ecx
  CChoreoScene *v19; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  CChoreoActorWidget *a; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  CChoreoView *v24; // [esp+10h] [ebp-4h]
  float eventa; // [esp+1Ch] [ebp+8h]

  v2 = 0;
  v24 = this;
  i = 0;
  if ( this->m_SceneActors.m_Size <= 0 )
    return;
  while ( 1 )
  {
    v3 = this->m_SceneActors.m_Memory.m_pMemory[v2];
    a = v3;
    if ( v3 != nullptr )
      break;
LABEL_13:
    i = ++v2;
    if ( v2 >= this->m_SceneActors.m_Size )
      return;
  }
  v4 = 0;
  j = 0;
  if ( CChoreoWidgetDrawHelper::GetHeight(this: v3) <= 0 )
  {
LABEL_12:
    this = v24;
    goto LABEL_13;
  }
  while ( 1 )
  {
    Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v3, num: v4);
    v6 = (CChoreoChannelWidget *)Channel;
    if ( Channel != nullptr )
    {
      v7 = 0;
      if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
        break;
    }
LABEL_10:
    v4 = ++j;
    if ( j >= CChoreoWidgetDrawHelper::GetHeight(this: v3) )
    {
      v2 = i;
      goto LABEL_12;
    }
  }
  while ( 1 )
  {
    v8 = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v6, num: v7);
    v9 = (CChoreoEventWidget *)v8;
    if ( v8 != nullptr && event == (CChoreoEvent *)CAudioSourceWave::GetHeader(this: v8) )
      break;
    if ( ++v7 >= (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v6) )
    {
      v3 = a;
      goto LABEL_10;
    }
  }
  CChoreoChannelWidget::MoveEventToTail(this: v6, event: v9);
  if ( !v24->m_bSuppressLayout )
  {
    m_pScene = v24->m_pScene;
    if ( m_pScene != nullptr )
    {
      StopTime = CChoreoScene::FindStopTime(this: m_pScene);
      eventa = StopTime;
      if ( StopTime < 5.0 )
        eventa = 5.0;
      Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&v24->IFacePoserToolWindow);
      v14 = v24->m_pScene;
      if ( v14 != nullptr )
        TimeZoom = CChoreoScene::GetTimeZoom(this: v14, tool: Name);
      else
        TimeZoom = 100;
      v11 = (int)(float)((float)((float)((float)TimeZoom * v24->m_flPixelsPerSecond) * 0.0099999998)
                       * (float)(eventa + 5.0));
    }
    else
    {
      v11 = 0;
    }
    if ( v11 != v24->m_nLastHPixelsNeeded )
      CChoreoView::RepositionHSlider(this: v24);
    v16 = 0;
    for ( k = 0; k < v24->m_SceneActors.m_Size; ++k )
    {
      v18 = v24->m_SceneActors.m_Memory.m_pMemory[k];
      if ( v18 != nullptr )
        v16 += v18->GetItemHeight(this: v18) + 2;
    }
    if ( v16 + v24->m_nStartRow + v24->GetCaptionHeight(this: &v24->IFacePoserToolWindow) + 30 != v24->m_nLastVPixelsNeeded )
      CChoreoView::RepositionVSlider(this: v24);
    v19 = v24->m_pScene;
    if ( v19 != nullptr )
    {
      CChoreoScene::ReconcileGestureTimes(this: v19);
      CChoreoScene::ReconcileCloseCaption(this: v24->m_pScene);
    }
    redraw = v24->redraw;
    v24->m_bLayoutIsValid = false;
    redraw(this: v24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B7F0
// Name: public: void CChoreoView::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::WipeUndo(CChoreoView *this)
{
  void ***m_pMemory; // eax
  void **v3; // esi
  void *v4; // ebx
  void *v5; // ebx

  for ( ; this->m_UndoStack.m_Size > 0; --this->m_UndoStack.m_Size )
  {
    m_pMemory = (void ***)this->m_UndoStack.m_Memory.m_pMemory;
    v3 = *m_pMemory;
    v4 = **m_pMemory;
    if ( v4 != nullptr )
    {
      CChoreoScene::~CChoreoScene(this: (CChoreoScene *)**m_pMemory);
      free(pMem: v4);
    }
    v5 = v3[1];
    if ( v5 != nullptr )
    {
      CChoreoScene::~CChoreoScene(this: (CChoreoScene *)v3[1]);
      free(pMem: v5);
    }
    free(pMem: v3[2]);
    free(pMem: v3[3]);
    free(pMem: v3);
    if ( this->m_UndoStack.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_UndoStack.m_Memory.m_pMemory,
        src: this->m_UndoStack.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_UndoStack.m_Size - 1));
  }
  this->m_nUndoLevel = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B8A0
// Name: public: void CChoreoView::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::WipeRedo(CChoreoView *this)
{
  int i; // eax
  CChoreoView::CVUndo *v3; // edi
  CChoreoScene *undo; // ebx
  CChoreoScene *redo; // ebx
  int m_nUndoLevel; // ecx

  for ( i = this->m_nUndoLevel; this->m_UndoStack.m_Size > i; i = this->m_nUndoLevel )
  {
    v3 = this->m_UndoStack.m_Memory.m_pMemory[i];
    undo = v3->undo;
    if ( v3->undo != nullptr )
    {
      CChoreoScene::~CChoreoScene(this: v3->undo);
      free(pMem: undo);
    }
    redo = v3->redo;
    if ( redo != nullptr )
    {
      CChoreoScene::~CChoreoScene(this: v3->redo);
      free(pMem: redo);
    }
    free(pMem: v3->udescription);
    free(pMem: v3->rdescription);
    free(pMem: v3);
    m_nUndoLevel = this->m_nUndoLevel;
    if ( this->m_UndoStack.m_Size - m_nUndoLevel - 1 > 0 )
      _V_memmove(
        dest: &this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel],
        src: &this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel + 1],
        count: 4 * (this->m_UndoStack.m_Size - m_nUndoLevel - 1));
    --this->m_UndoStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B960
// Name: public: void CChoreoView::CopyEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::CopyEvents(CChoreoView *this)
{
  if ( this->m_pScene != nullptr )
  {
    MakeFileWriteable(filename: "scenes/copydatavcd.txt");
    CChoreoView::ExportVCDFile(this, filename: "scenes/copydatavcd.txt");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B990
// Name: public: void CChoreoView::ScrubThink(float,bool,class IFacePoserToolWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::ScrubThink(
        CChoreoView *this@<ecx>,
        int a2@<edi>,
        float dt,
        bool scrubbing,
        IFacePoserToolWindow *invoker)
{
  int CurrentFrame; // eax
  bool v7; // zf
  float m_flScrubTarget; // xmm3_4
  float m_flScrub; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  float v12; // xmm2_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float time; // xmm0_4
  IFacePoserToolWindow *v16; // eax
  IFacePoserToolWindow *v17; // eax
  IFacePoserToolWindow *v18; // eax
  IFacePoserToolWindow *v19; // eax

  CurrentFrame = MDLViewer::GetCurrentFrame(this: g_MDLViewer);
  if ( CurrentFrame == lastthinkframe )
    return;
  v7 = this->m_pScene == nullptr;
  lastthinkframe = CurrentFrame;
  if ( v7 )
    return;
  if ( this->m_flScrubTarget == this->m_flScrub && !scrubbing )
  {
    if ( !IFacePoserToolWindow::ShouldAutoProcess() )
      return;
    this->m_bSimulating = true;
    goto LABEL_7;
  }
  models->SetSolveHeadTurn(this: models, a2: 1);
  if ( this->m_bPaused )
  {
LABEL_7:
    CChoreoView::SceneThink(this, time: this->m_flScrub);
    return;
  }
  FacePoser_EnsurePhonemesLoaded();
  if ( !this->m_bSimulating )
    this->m_bSimulating = true;
  m_flScrubTarget = this->m_flScrubTarget;
  m_flScrub = this->m_flScrub;
  v10 = m_flScrubTarget - m_flScrub;
  if ( (float)(m_flScrubTarget - m_flScrub) <= 0.0 )
    v11 = -1;
  else
    v11 = 1;
  v12 = this->m_flPlaybackRate * dt;
  v13 = this->m_flScrub;
  if ( v11 <= 0 )
  {
    if ( v12 > COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_) )
    {
      this->m_flScrub = m_flScrubTarget;
      goto LABEL_22;
    }
    v14 = m_flScrub - v12;
LABEL_21:
    this->m_flScrub = v14;
    goto LABEL_22;
  }
  if ( v12 <= v10 )
  {
    v14 = m_flScrub + v12;
    goto LABEL_21;
  }
  this->m_flScrub = m_flScrubTarget;
LABEL_22:
  time = this->m_flScrub;
  this->m_flFrameTime = time - v13;
  CChoreoView::SceneThink(this, time);
  CChoreoView::DrawScrubHandle(this, a2);
  if ( scrubbing )
    MatSysWindow::Frame(this: g_pMatSysWindow);
  if ( g_pExpressionTool != nullptr )
    v16 = &g_pExpressionTool->IFacePoserToolWindow;
  else
    v16 = nullptr;
  if ( invoker != v16 )
    ExpressionTool::ForceScrubPositionFromSceneTime(this: g_pExpressionTool, scenetime: this->m_flScrub);
  if ( g_pGestureTool != nullptr )
    v17 = &g_pGestureTool->IFacePoserToolWindow;
  else
    v17 = nullptr;
  if ( invoker != v17 )
    GestureTool::ForceScrubPositionFromSceneTime(this: g_pGestureTool, scenetime: this->m_flScrub);
  if ( g_pRampTool != nullptr )
    v18 = &g_pRampTool->IFacePoserToolWindow;
  else
    v18 = nullptr;
  if ( invoker != v18 )
    RampTool::ForceScrubPositionFromSceneTime(this: g_pRampTool, scenetime: this->m_flScrub);
  if ( g_pSceneRampTool != nullptr )
    v19 = &g_pSceneRampTool->IFacePoserToolWindow;
  else
    v19 = nullptr;
  if ( invoker != v19 )
    SceneRampTool::ForceScrubPositionFromSceneTime(this: g_pSceneRampTool, scenetime: this->m_flScrub);
}

//------------------------------------------------------------------------------
// Address: 0x0042BBA0
// Name: private: void CChoreoView::ReselectEvents(class CUtlVector<class CChoreoEvent __near *,class CUtlMemory<class CChoreoEvent __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ReselectEvents(
        CChoreoView *this,
        CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > *list)
{
  int v2; // ebx
  CChoreoActorWidget *v3; // edi
  int v4; // esi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v6; // ebx
  int v7; // esi
  CAudioSourceWave *Event; // eax
  CAudioSourceWave *v9; // edi
  char *Header; // eax
  int m_Size; // edx
  int v12; // ecx
  CChoreoEvent **m_pMemory; // esi
  CChoreoActorWidget *actor; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  CChoreoView *v16; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  int k; // [esp+14h] [ebp-4h]

  v2 = 0;
  v16 = this;
  for ( i = 0; v2 < this->m_SceneActors.m_Size; i = v2 )
  {
    v3 = this->m_SceneActors.m_Memory.m_pMemory[v2];
    actor = v3;
    if ( v3 != nullptr )
    {
      v4 = 0;
      j = 0;
      if ( CChoreoWidgetDrawHelper::GetHeight(this: v3) > 0 )
      {
        do
        {
          Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v3, num: v4);
          v6 = (CChoreoChannelWidget *)Channel;
          if ( Channel != nullptr )
          {
            v7 = 0;
            k = 0;
            if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
            {
              do
              {
                Event = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v6, num: v7);
                v9 = Event;
                if ( Event != nullptr )
                {
                  Header = CAudioSourceWave::GetHeader(this: Event);
                  m_Size = list->m_Size;
                  v12 = 0;
                  if ( m_Size > 0 )
                  {
                    m_pMemory = list->m_Memory.m_pMemory;
                    while ( *m_pMemory != (CChoreoEvent *)Header )
                    {
                      ++v12;
                      ++m_pMemory;
                      if ( v12 >= m_Size )
                        goto LABEL_14;
                    }
                    if ( v12 != -1 )
                      ((void (__thiscall *)(CAudioSourceWave *, int))v9->IsStreaming)(a1: v9, a2: 1);
                  }
                }
LABEL_14:
                v7 = ++k;
              }
              while ( k < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v6) );
              v3 = actor;
            }
          }
          v4 = ++j;
        }
        while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v3) );
        v2 = i;
      }
      this = v16;
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BCA0
// Name: private: void CChoreoView::OnToggleCloseCaptionTags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnToggleCloseCaptionTags(CChoreoView *this)
{
  this->m_bShowCloseCaptionData = !this->m_bShowCloseCaptionData;
  CChoreoView::InvalidateLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042D4C0
// Name: public: void CChoreoView::MouseContinueDrag(class mxEvent __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MouseContinueDrag(CChoreoView *this, mxEvent *event, int mx, int my)
{
  int v5; // edi
  int m_nMinX; // eax
  CChoreoView::CFocusRect *v7; // eax
  tagRECT *p_m_rcFocus; // ebx
  CChoreoEventWidget *m_pClickedEvent; // ecx
  int v10; // eax
  int v11; // edi
  int m_nDragType; // eax
  char *Header; // eax
  float dt; // xmm0_4
  CChoreoView *v15; // ecx
  int v16; // eax
  int v17; // eax
  int m_Size; // edx
  signed int v19; // ebx
  int *p_right; // eax
  int v21; // edi
  int v22; // eax
  float v23; // xmm0_4
  float v24; // xmm0_4
  int v25; // ebx
  CChoreoView::CFocusRect *m_pMemory; // eax
  int right; // edi
  int left; // edx
  CChoreoView::CFocusRect *v29; // eax
  int v30; // ecx
  int v31; // edx
  int v32; // edx
  bool v33; // zf
  int i; // [esp+18h] [ebp-Ch]
  int v35; // [esp+1Ch] [ebp-8h]
  int t; // [esp+20h] [ebp-4h]
  float ta; // [esp+20h] [ebp-4h]
  mxEvent *eventa; // [esp+2Ch] [ebp+8h]
  int m_nStart; // [esp+30h] [ebp+Ch]
  int m_nEnd; // [esp+34h] [ebp+10h]

  if ( this->m_bDragging )
  {
    CChoreoView::DrawFocusRect(this);
    v5 = mx;
    if ( this->m_bUseBounds )
    {
      m_nMinX = this->m_nMinX;
      if ( mx < m_nMinX || (m_nMinX = this->m_nMaxX, mx > m_nMinX) )
        v5 = m_nMinX;
      mx = v5;
    }
    i = 0;
    if ( this->m_FocusRects.m_Size > 0 )
    {
      v35 = 0;
      do
      {
        v7 = &this->m_FocusRects.m_Memory.m_pMemory[v35];
        p_m_rcFocus = &v7->m_rcFocus;
        *(_QWORD *)&v7->m_rcFocus.left = *(_QWORD *)&v7->m_rcOrig.left;
        *(_QWORD *)&v7->m_rcFocus.right = *(_QWORD *)&v7->m_rcOrig.right;
        switch ( this->m_nDragType )
        {
          case 1:
          case 6:
          case 7:
            m_pClickedEvent = this->m_pClickedEvent;
            v10 = v5 - this->m_xStart;
            v11 = my - this->m_yStart;
            t = v10;
            if ( m_pClickedEvent != nullptr )
            {
              if ( (event->modifiers & 2) == 0 )
                v11 = 0;
              if ( (int)abs32(v11) < m_pClickedEvent->GetItemHeight(this: m_pClickedEvent) )
                v11 = 0;
              if ( this->m_nSelectedEvents > 1 )
                v11 = 0;
              m_nDragType = this->m_nDragType;
              if ( m_nDragType == 6 || m_nDragType == 7 )
                v11 = 0;
              Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedEvent);
              if ( CChoreoEvent::IsUsingRelativeTag(this: (CChoreoEvent *)Header) )
                t = 0;
              OffsetRect(lprc: p_m_rcFocus, dx: t, dy: v11);
              v5 = mx;
            }
            else
            {
              OffsetRect(lprc: p_m_rcFocus, dx: v10, dy: 0);
              v5 = mx;
            }
            break;
          case 2:
          case 3:
            p_m_rcFocus->left += v5 - this->m_xStart;
            break;
          case 4:
          case 5:
            v7->m_rcFocus.right += v5 - this->m_xStart;
            break;
          case 9:
            OffsetRect(lprc: p_m_rcFocus, dx: v5 - this->m_xStart, dy: 0);
            break;
          case 0xA:
          case 0xB:
            break;
          default:
            ta = CChoreoView::GetTimeValueForMouse(this, mx: v5, clip: false) + this->m_flScrubberTimeOffset;
            this->m_flScrubTarget = ta;
            dt = ta - this->m_flScrub;
            *(_WORD *)&this->m_bSimulating = 1;
            CChoreoView::ScrubThink(this: v15, a2: v5, dt, scrubbing: true, invoker: &this->IFacePoserToolWindow);
            this->m_flScrub = ta;
            v16 = v5 - this->m_xStart;
            this->m_bPaused = false;
            OffsetRect(lprc: p_m_rcFocus, dx: v16, dy: 0);
            break;
        }
        ++v35;
        ++i;
      }
      while ( i < this->m_FocusRects.m_Size );
    }
    v17 = this->m_nDragType;
    if ( v17 == 10 || v17 == 11 )
    {
      m_Size = this->m_FocusRects.m_Size;
      v19 = 0x80000000;
      m_nStart = 0x7FFFFFFF;
      m_nEnd = 0x80000000;
      if ( m_Size > 0 )
      {
        p_right = &this->m_FocusRects.m_Memory.m_pMemory->m_rcFocus.right;
        do
        {
          if ( *(p_right - 2) < m_nStart )
            m_nStart = *(p_right - 2);
          if ( *p_right > v19 )
          {
            m_nEnd = *p_right;
            v19 = *p_right;
          }
          p_right += 8;
          --m_Size;
        }
        while ( m_Size != 0 );
      }
      v21 = v5 - this->m_xStart;
      v22 = v19 - m_nStart;
      if ( v19 - m_nStart > 0 )
      {
        v23 = this->m_nDragType == 11 ? (float)(v22 + v21) : (float)(v22 - v21);
        v24 = v23 / (float)v22;
        if ( this->m_FocusRects.m_Size > 0 )
        {
          v25 = 0;
          eventa = (mxEvent *)this->m_FocusRects.m_Size;
          do
          {
            m_pMemory = this->m_FocusRects.m_Memory.m_pMemory;
            right = m_pMemory[v25].m_rcFocus.right;
            left = m_pMemory[v25].m_rcFocus.left;
            v29 = &m_pMemory[v25];
            v30 = right - left;
            if ( this->m_nDragType == 11 )
            {
              v31 = m_nStart + (int)(float)((float)((float)(left - m_nStart) * v24) + 0.5);
              v29->m_rcFocus.right = v31 + (int)(float)((float)((float)v30 * v24) + 0.5);
            }
            else
            {
              v32 = m_nEnd - (int)(float)((float)((float)(m_nEnd - right) * v24) + 0.5);
              v29->m_rcFocus.right = v32;
              v31 = v32 - (int)(float)((float)((float)v30 * v24) + 0.5);
            }
            ++v25;
            v33 = eventa == (mxEvent *)1;
            eventa = (mxEvent *)((char *)eventa - 1);
            v29->m_rcFocus.left = v31;
          }
          while ( !v33 );
        }
      }
    }
    CChoreoView::DrawFocusRect(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D820
// Name: public: void CChoreoView::MoveTimeSliderToPos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MoveTimeSliderToPos(CChoreoView *this, int x)
{
  mxScrollbar *m_pHorzScrollBar; // ecx
  HWND Handle; // eax

  m_pHorzScrollBar = this->m_pHorzScrollBar;
  this->m_flLeftOffset = (float)x;
  mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: (int)(float)x);
  Handle = (HWND)mxWidget::getHandle(this: this->m_pHorzScrollBar);
  InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
  CChoreoView::InvalidateLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042D870
// Name: public: void CChoreoView::SetDirty(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetDirty(CChoreoView *this, bool dirty, bool clearundo)
{
  bool v4; // zf
  bool v5; // bl
  const char *v6; // eax

  v4 = dirty == this->m_bDirty;
  this->m_bDirty = dirty;
  v5 = !v4;
  if ( !dirty && clearundo )
  {
    CChoreoView::WipeUndo(this);
    this->redraw(this);
  }
  if ( v5 )
  {
    v6 = "* ";
    if ( !this->m_bDirty )
      v6 = defaultValue;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D8D0
// Name: public: void CChoreoView::Save(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChoreoView::Save(CChoreoView *this@<ecx>, int a2@<ebx>)
{
  CP4File *v3; // ebx
  const char *v4; // eax
  bool v5; // zf

  if ( this->m_pScene != nullptr )
  {
    if ( MakeFileWriteablePrompt(filename: this->m_szChoreoFile, promptTitle: "VCD File") )
    {
      Con_Printf(fmt: "Saving changes to %s\n", this->m_szChoreoFile);
      v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename: this->m_szChoreoFile);
      ((void (__thiscall *)(CP4File *, int))v3->Edit)(a1: v3, a2);
      if ( !CChoreoScene::SaveToFile(this: this->m_pScene, filename: this->m_szChoreoFile) )
      {
        v4 = va(fmt: "Unable to write \"%s\"", this->m_szChoreoFile);
        mxMessageBox(parent: this, msg: v4, title: "SaveToFile", style: 8);
      }
      MDLViewer::OnVCDSaved(this: g_MDLViewer, pFullpath: this->m_szChoreoFile);
      CChoreoView::SetChoreoFile(this, filename: this->m_szChoreoFile);
      v5 = !this->m_bDirty;
      this->m_bDirty = false;
      if ( !v5 )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: defaultValue);
      this->redraw(this);
      v3->Add(this: v3);
      ((void (__thiscall *)(CP4File *, int))v3->dtr_CP4File)(a1: v3, a2: 1);
    }
    else
    {
      Con_Printf(fmt: "Not saving changes to %s\n", this->m_szChoreoFile);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D9C0
// Name: public: void CChoreoView::SaveAs(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChoreoView::SaveAs(CChoreoView *this@<ecx>, int a2@<edi>)
{
  CP4File *v3; // edi
  const char *v4; // eax
  bool v5; // zf
  char scenefile[512]; // [esp+4h] [ebp-200h] BYREF

  if ( this->m_pScene != nullptr
    && FacePoser_ShowSaveFileNameDialog(relative: scenefile, bufsize: 0x200u, subdir: "scenes", wildcard: "*.vcd") )
  {
    V_DefaultExtension(path: scenefile, extension: ".vcd", pathStringLength: 512);
    Con_Printf(fmt: "Saving %s\n", scenefile);
    MakeFileWriteable(filename: scenefile);
    CChoreoView::SetChoreoFile(this, filename: scenefile);
    v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename: scenefile);
    ((void (__thiscall *)(CP4File *, int))v3->Edit)(a1: v3, a2);
    if ( !CChoreoScene::SaveToFile(this: this->m_pScene, filename: scenefile) )
    {
      v4 = va(fmt: "Unable to write \"%s\"", scenefile);
      mxMessageBox(parent: this, msg: v4, title: "SaveToFile", style: 8);
    }
    MDLViewer::OnVCDSaved(this: g_MDLViewer, pFullpath: scenefile);
    v5 = !this->m_bDirty;
    this->m_bDirty = false;
    if ( !v5 )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: defaultValue);
    v3->Add(this: v3);
    ((void (__thiscall *)(CP4File *, int))v3->dtr_CP4File)(a1: v3, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DAF0
// Name: public: void CChoreoView::UnloadScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::UnloadScene(CChoreoView *this)
{
  CChoreoScene *m_pScene; // ebx
  bool v3; // zf
  bool v4; // bl
  const char *v5; // eax

  CChoreoView::InvalidateLayout(this);
  CChoreoView::ReportSceneClearToTools(this);
  *(_QWORD *)&this->m_Flyover.a = 0;
  *(_QWORD *)&this->m_Flyover.e = 0;
  *(_QWORD *)&this->m_Flyover.tag = 0;
  this->m_Flyover.ccbutton = 0;
  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
  {
    CChoreoScene::~CChoreoScene(this: this->m_pScene);
    free(pMem: m_pScene);
  }
  v3 = !this->m_bDirty;
  this->m_pScene = nullptr;
  v4 = !v3;
  this->m_bDirty = false;
  CChoreoView::WipeUndo(this);
  this->redraw(this);
  if ( v4 )
  {
    v5 = "* ";
    if ( !this->m_bDirty )
      v5 = defaultValue;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: v5);
  }
  CChoreoView::SetChoreoFile(this, filename: defaultValue);
  MDLViewer::InitGridSettings(this: g_MDLViewer);
  CChoreoWidget::m_pScene = nullptr;
  CChoreoView::DeleteSceneWidgets(this);
  mxWidget::setVisible(this: this->m_pVertScrollBar, b: false);
  mxWidget::setVisible(this: this->m_pHorzScrollBar, b: false);
  mxWidget::setVisible(this: this->m_btnPlay, b: false);
  mxWidget::setVisible(this: this->m_btnPause, b: false);
  mxWidget::setVisible(this: this->m_btnStop, b: false);
  mxWidget::setVisible(this: this->m_pPlaybackRate, b: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042DC10
// Name: public: virtual void CChoreoView::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::Think(CChoreoView *this@<ecx>, int a2@<edi>, float dt)
{
  bool IsAnyToolScrubbing; // al

  IsAnyToolScrubbing = IFacePoserToolWindow::IsAnyToolScrubbing();
  CChoreoView::ScrubThink(
    this: (CChoreoView *)((char *)this - 12),
    a2,
    dt,
    scrubbing: IsAnyToolScrubbing,
    invoker: this != (CChoreoView *)12 ? (IFacePoserToolWindow *)this : nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042DC50
// Name: public: void CChoreoView::SetTimeZoom(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetTimeZoom(CChoreoView *this, const char *tool, int tz, bool preserveFocus)
{
  CChoreoScene *m_pScene; // ecx
  bool m_bDirty; // zf
  HWND Handle; // eax
  int m_nLabelWidth; // edx
  float m_flEndTime; // xmm0_4
  HWND v11; // eax
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // edx
  int v13; // eax
  int m_nTopOffset; // edx
  double PixelsPerSecond; // st7
  double v16; // st7
  int v17; // eax
  int x; // ecx
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  __int64 v26; // [esp+Ch] [ebp-30h]
  tagRECT rc; // [esp+14h] [ebp-28h] BYREF
  tagRECT rcClient; // [esp+24h] [ebp-18h] BYREF
  tagPOINT pt; // [esp+34h] [ebp-8h] BYREF
  float t; // [esp+44h] [ebp+8h]
  float ppsb; // [esp+48h] [ebp+Ch]
  float pps; // [esp+48h] [ebp+Ch]
  float ppsa; // [esp+48h] [ebp+Ch]
  int newTa; // [esp+4Ch] [ebp+10h]
  float newT; // [esp+4Ch] [ebp+10h]
  float newTb; // [esp+4Ch] [ebp+10h]

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr && tz != CChoreoScene::GetTimeZoom(this: m_pScene, tool) )
  {
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    GetCursorPos(lpPoint: &pt);
    Handle = (HWND)mxWidget::getHandle(this);
    ScreenToClient(hWnd: Handle, lpPoint: &pt);
    m_nLabelWidth = this->m_nLabelWidth;
    rcClient = this->m_rcTimeLine;
    if ( pt.x >= m_nLabelWidth )
    {
      if ( pt.x <= rcClient.right )
        m_flEndTime = (float)((float)((float)(pt.x - m_nLabelWidth) / (float)(rcClient.right - m_nLabelWidth))
                            * (float)(this->m_flEndTime - this->m_flStartTime))
                    + this->m_flStartTime;
      else
        m_flEndTime = this->m_flEndTime;
    }
    else
    {
      m_flEndTime = this->m_flStartTime;
    }
    t = m_flEndTime;
    CChoreoScene::SetTimeZoom(this: this->m_pScene, tool, tz);
    if ( preserveFocus )
    {
      v11 = (HWND)mxWidget::getHandle(this);
      GetClientRect(hWnd: v11, lpRect: &rc);
      GetCaptionHeight = this->GetCaptionHeight;
      rcClient = rc;
      v13 = GetCaptionHeight(this: &this->IFacePoserToolWindow);
      m_nTopOffset = this->m_nTopOffset;
      rcClient.top += v13 + this->m_nStartRow + 15;
      OffsetRect(lprc: &rcClient, dx: 0, dy: -m_nTopOffset);
      PixelsPerSecond = CChoreoView::GetPixelsPerSecond(this);
      newTa = rcClient.right - this->m_nLabelWidth;
      this->m_flStartTime = this->m_flLeftOffset / PixelsPerSecond;
      ppsb = (float)newTa;
      newT = this->m_flStartTime;
      v16 = CChoreoView::GetPixelsPerSecond(this);
      v17 = this->m_nLabelWidth;
      x = pt.x;
      v26 = *(_QWORD *)&this->m_rcTimeLine.right;
      pps = ppsb / v16 + newT;
      this->m_flEndTime = pps;
      if ( x >= v17 )
        v19 = x <= (int)v26 ? (float)((float)((float)(x - v17) / (float)(v26 - v17)) * (float)(pps - newT)) + newT : pps;
      else
        v19 = newT;
      if ( v19 != t )
      {
        ppsa = CChoreoView::GetPixelsPerSecond(this);
        v20 = this->m_flLeftOffset - (float)((float)(v19 - t) * ppsa);
        this->m_flLeftOffset = v20;
        if ( v20 < 0.0 )
          this->m_flLeftOffset = 0.0;
        if ( CChoreoScene::FindStopTime(this: this->m_pScene) <= 5.0 )
        {
          v21 = 5.0;
        }
        else
        {
          newTb = CChoreoScene::FindStopTime(this: this->m_pScene);
          v21 = newTb;
        }
        v22 = v21 + 5.0;
        v23 = this->m_flEndTime;
        if ( v23 > v22 )
        {
          v24 = this->m_flLeftOffset - (float)((float)(v23 - v22) * ppsa);
          v25 = 0.0;
          if ( v24 >= 0.0 )
            v25 = v24;
          this->m_flLeftOffset = v25;
        }
      }
    }
    CChoreoView::RepositionHSlider(this);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E020
// Name: public: bool CChoreoView::Close(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CChoreoView::Close@<al>(CChoreoView *this@<ecx>, int a2@<ebx>)
{
  const char *v3; // eax
  int v4; // eax

  if ( this->m_pScene != nullptr )
  {
    if ( this->m_bDirty )
    {
      v3 = va(fmt: "Save changes to scene '%s'?", this->m_szChoreoFile);
      v4 = mxMessageBox(parent: nullptr, msg: v3, title: g_appTitle, style: 2);
      if ( v4 == 2 )
        return 0;
      if ( v4 == 0 )
        CChoreoView::Save(this, a2);
    }
    if ( this->m_pScene != nullptr )
      CChoreoView::UnloadScene(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E090
// Name: public: virtual bool CChoreoView::CanClose(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CChoreoView::CanClose@<al>(CChoreoView *this@<ecx>, int a2@<ebx>)
{
  char result; // al

  if ( this->m_pScene == nullptr )
    return 1;
  workspacefiles->StartStoringFiles(this: workspacefiles, a2: 1);
  workspacefiles->StoreFile(this: workspacefiles, a2: 1, a3: this->m_szChoreoFile);
  workspacefiles->FinishStoringFiles(this: workspacefiles, a2: 1);
  if ( this->m_pScene == nullptr )
    return 1;
  if ( !this->m_bDirty )
    return 1;
  result = CChoreoView::Close(this, a2);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E100
// Name: public: virtual void CChoreoView::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnDelete(CChoreoView *this)
{
  if ( this->m_pScene != nullptr )
    CChoreoView::UnloadScene(this);
  CChoreoWidget::m_pView = nullptr;
  CChoreoEventWidget::DestroyImages();
}

//------------------------------------------------------------------------------
// Address: 0x0042E120
// Name: public: int CChoreoView::GetSelectedEventWidgets(class CUtlVector<class CChoreoEventWidget __near *,class CUtlMemory<class CChoreoEventWidget __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetSelectedEventWidgets(
        CChoreoView *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *events)
{
  int v4; // ecx
  int result; // eax
  CChoreoActorWidget *v6; // ebx
  CAudioMixerWave *v7; // eax
  CChoreoChannelWidget *v8; // edi
  CChoreoEventWidget *Event; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CChoreoEventWidget **v12; // ecx
  int v13; // eax
  CChoreoEventWidget **v14; // eax
  CChoreoView *v15; // [esp+8h] [ebp-18h]
  CChoreoActorWidget *actor; // [esp+Ch] [ebp-14h]
  CChoreoChannelWidget *channel; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  int c; // [esp+18h] [ebp-8h]
  int j; // [esp+1Ch] [ebp-4h]
  int k; // [esp+28h] [ebp+8h]

  v4 = 0;
  result = 0;
  events[1].m_pMemory = nullptr;
  v15 = this;
  c = 0;
  i = 0;
  if ( this->m_SceneActors.m_Size > 0 )
  {
    do
    {
      v6 = this->m_SceneActors.m_Memory.m_pMemory[v4];
      actor = v6;
      if ( v6 != nullptr )
      {
        j = 0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: v6) > 0 )
        {
          do
          {
            v7 = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v6, num: j);
            v8 = (CChoreoChannelWidget *)v7;
            channel = (CChoreoChannelWidget *)v7;
            if ( v7 != nullptr )
            {
              k = 0;
              if ( (int)CAudioMixerWave::GetChannel(this: v7) > 0 )
              {
                do
                {
                  Event = CChoreoChannelWidget::GetEvent(this: v8, num: k);
                  if ( Event != nullptr && Event->IsSelected(this: Event) )
                  {
                    m_pMemory = (int)events[1].m_pMemory;
                    m_nAllocationCount = events->m_nAllocationCount;
                    if ( m_pMemory + 1 > m_nAllocationCount )
                      CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                        this: events,
                        num: m_pMemory - m_nAllocationCount + 1);
                    ++events[1].m_pMemory;
                    v12 = (CChoreoEventWidget **)events->m_pMemory;
                    v13 = (int)events[1].m_pMemory - m_pMemory - 1;
                    events[1].m_nAllocationCount = (int)events->m_pMemory;
                    if ( v13 > 0 )
                      _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
                    v14 = (CChoreoEventWidget **)&events->m_pMemory[m_pMemory];
                    if ( v14 != nullptr )
                      *v14 = Event;
                    ++c;
                    v8 = channel;
                  }
                  ++k;
                }
                while ( k < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v8) );
                v6 = actor;
              }
            }
            ++j;
          }
          while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v6) );
          this = v15;
        }
      }
      v4 = i + 1;
      i = v4;
    }
    while ( v4 < this->m_SceneActors.m_Size );
    return c;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E280
// Name: public: int CChoreoView::GetSelectedEvents(class CUtlVector<class CChoreoEvent __near *,class CUtlMemory<class CChoreoEvent __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::GetSelectedEvents(
        CChoreoView *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *events)
{
  int v3; // ecx
  int result; // eax
  CChoreoActorWidget *v6; // edi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v8; // ebx
  CAudioSourceWave *Event; // edi
  char *Header; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CChoreoEvent **v13; // ecx
  int v14; // eax
  CChoreoEvent **v15; // eax
  CChoreoView *v16; // [esp+8h] [ebp-18h]
  CChoreoActorWidget *actor; // [esp+Ch] [ebp-14h]
  char *v18; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  int c; // [esp+18h] [ebp-8h]
  int j; // [esp+1Ch] [ebp-4h]
  int k; // [esp+28h] [ebp+8h]

  v3 = 0;
  result = 0;
  events[1].m_pMemory = nullptr;
  v16 = this;
  c = 0;
  i = 0;
  if ( this->m_SceneActors.m_Size > 0 )
  {
    do
    {
      v6 = this->m_SceneActors.m_Memory.m_pMemory[v3];
      actor = v6;
      if ( v6 != nullptr )
      {
        j = 0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: v6) > 0 )
        {
          do
          {
            Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v6, num: j);
            v8 = (CChoreoChannelWidget *)Channel;
            if ( Channel != nullptr )
            {
              k = 0;
              if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
              {
                do
                {
                  Event = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v8, num: k);
                  if ( Event != nullptr && Event->IsLooped(this: Event) )
                  {
                    Header = CAudioSourceWave::GetHeader(this: Event);
                    m_pMemory = (int)events[1].m_pMemory;
                    v18 = Header;
                    m_nAllocationCount = events->m_nAllocationCount;
                    if ( m_pMemory + 1 > m_nAllocationCount )
                      CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                        this: events,
                        num: m_pMemory - m_nAllocationCount + 1);
                    ++events[1].m_pMemory;
                    v13 = (CChoreoEvent **)events->m_pMemory;
                    v14 = (int)events[1].m_pMemory - m_pMemory - 1;
                    events[1].m_nAllocationCount = (int)events->m_pMemory;
                    if ( v14 > 0 )
                      _V_memmove(dest: &v13[m_pMemory + 1], src: &v13[m_pMemory], count: 4 * v14);
                    v15 = (CChoreoEvent **)&events->m_pMemory[m_pMemory];
                    if ( v15 != nullptr )
                      *v15 = (CChoreoEvent *)v18;
                    ++c;
                  }
                  ++k;
                }
                while ( k < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v8) );
                v6 = actor;
              }
            }
            ++j;
          }
          while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v6) );
          this = v16;
        }
      }
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < this->m_SceneActors.m_Size );
    return c;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E3E0
// Name: public: int CChoreoView::ComputeEventDragType(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::ComputeEventDragType(CChoreoView *this, int mx, int my)
{
  int result; // eax
  CChoreoEventWidget *v6; // edi
  int EarliestEventIndex; // edi
  int LatestEventIndex; // eax
  char *Header; // eax
  CUtlVector<CChoreoEventWidget *,CUtlMemory<CChoreoEventWidget *,int> > events; // [esp+Ch] [ebp-14h] BYREF
  int iEnd; // [esp+2Ch] [ebp+Ch]
  CChoreoEvent *iEnda; // [esp+2Ch] [ebp+Ch]

  result = (int)CChoreoView::GetEventUnderCursorPos(this, mx, my);
  v6 = (CChoreoEventWidget *)result;
  if ( result != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)result + 48))(a1: result);
    if ( CChoreoView::GetTagUnderCursorPos(this, event: v6, mx, my) != -1 && CChoreoView::CountSelectedEvents(this) <= 1 )
      return 6;
    if ( CChoreoView::GetAbsoluteTagUnderCursorPos(this, event: (CAudioSourceWave *)v6, mx, my) != nullptr
      && CChoreoView::CountSelectedEvents(this) <= 1 )
    {
      return 7;
    }
    if ( CChoreoView::CountSelectedEvents(this) > 1 )
    {
      memset(&events, 0, sizeof(events));
      CChoreoView::GetSelectedEventWidgets(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&events);
      EarliestEventIndex = CChoreoView::GetEarliestEventIndex(this, &events);
      LatestEventIndex = CChoreoView::GetLatestEventIndex(this, &events);
      iEnd = LatestEventIndex;
      if ( EarliestEventIndex >= 0 && EarliestEventIndex < events.m_Size )
      {
        if ( CChoreoView::IsMouseOverEventEdge(
               this,
               ew: events.m_Memory.m_pMemory[EarliestEventIndex],
               bLeftEdge: true,
               mx,
               my) )
        {
          CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
          return 10;
        }
        LatestEventIndex = iEnd;
      }
      if ( LatestEventIndex >= 0
        && LatestEventIndex < events.m_Size
        && CChoreoView::IsMouseOverEventEdge(
             this,
             ew: events.m_Memory.m_pMemory[LatestEventIndex],
             bLeftEdge: false,
             mx,
             my) )
      {
        CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
        return 11;
      }
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
      return 1;
    }
    Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v6);
    iEnda = (CChoreoEvent *)Header;
    if ( Header != nullptr
      && (CChoreoEvent::IsFixedLength(this: (CChoreoEvent *)Header) || !CChoreoEvent::CurveHasEndTime(this: iEnda)) )
    {
      return 1;
    }
    if ( CChoreoView::IsMouseOverEventEdge(this, ew: v6, bLeftEdge: true, mx, my) )
    {
      return (GetAsyncKeyState(vKey: 16) != 0) + 2;
    }
    else if ( CChoreoView::IsMouseOverEventEdge(this, ew: v6, bLeftEdge: false, mx, my) )
    {
      return (GetAsyncKeyState(vKey: 16) != 0) + 4;
    }
    else
    {
      return CChoreoView::IsMouseOverEvent(this, ew: v6, mx, my);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E5E0
// Name: private: void CChoreoView::StartDraggingSceneEndTime(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::StartDraggingSceneEndTime(CChoreoView *this, int mx, int my)
{
  CChoreoView::CFocusRect *m_pMemory; // edx
  HWND Handle; // eax
  HCURSOR CursorA; // eax
  int m_Size; // [esp-8h] [ebp-4Ch]
  CChoreoView::CFocusRect fr; // [esp+Ch] [ebp-38h] BYREF
  tagRECT rcFocus; // [esp+2Ch] [ebp-18h] BYREF
  tagPOINT offset; // [esp+3Ch] [ebp-8h] BYREF

  this->m_nDragType = 9;
  this->m_FocusRects.m_Size = 0;
  if ( this->m_FocusRects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
      this->m_FocusRects.m_Memory.m_pMemory = nullptr;
    }
    this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_FocusRects.m_Memory.m_pMemory;
  rcFocus.top = 0;
  this->m_FocusRects.m_pElements = m_pMemory;
  rcFocus.left = mx;
  rcFocus.bottom = mxWidget::h2(this);
  rcFocus.right = mx + 2;
  offset.x = 0;
  offset.y = 0;
  Handle = (HWND)mxWidget::getHandle(this);
  ClientToScreen(hWnd: Handle, lpPoint: &offset);
  OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
  m_Size = this->m_FocusRects.m_Size;
  fr.m_rcFocus = rcFocus;
  fr.m_rcOrig = rcFocus;
  CUtlVector<PhonemeEditor::CFocusRect,CUtlMemory<PhonemeEditor::CFocusRect,int>>::InsertBefore(
    this: &this->m_FocusRects,
    elem: m_Size,
    src: &fr);
  this->m_xStart = mx;
  this->m_yStart = my;
  CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
  this->m_hPrevCursor = SetCursor(hCursor: CursorA);
  CChoreoView::DrawFocusRect(this);
  this->m_bDragging = true;
}

//------------------------------------------------------------------------------
// Address: 0x0042E700
// Name: public: void CChoreoView::StartDraggingEvent(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::StartDraggingEvent(CChoreoView *this, int mx, int my)
{
  int v4; // eax
  int v5; // ebx
  CChoreoActorWidget *v6; // esi
  CChoreoChannelWidget *v7; // eax
  CChoreoChannelWidget *v8; // ebx
  CChoreoEventWidget *Event; // eax
  CChoreoEventWidget *v10; // esi
  int m_nClickedTag; // eax
  bool v12; // zf
  char *Header; // eax
  CEventAbsoluteTag *RelativeTag; // ebx
  double v15; // st7
  double v16; // st7
  tagRECT *v17; // eax
  double Percentage; // st7
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  CChoreoEventWidget_vtbl *v22; // edx
  int v23; // ebx
  int v24; // eax
  int v25; // eax
  HWND Handle; // eax
  int v27; // esi
  int v28; // ebx
  CChoreoGlobalEventWidget **m_pMemory; // ecx
  CChoreoGlobalEventWidget *v30; // esi
  int v31; // ebx
  HWND v32; // eax
  int v33; // eax
  HCURSOR CursorA; // eax
  int m_Size; // [esp-Ch] [ebp-88h]
  int v36; // [esp-Ch] [ebp-88h]
  int v37; // [esp-8h] [ebp-84h]
  CChoreoView::CFocusRect fr; // [esp+8h] [ebp-74h] BYREF
  __int64 v39; // [esp+28h] [ebp-54h]
  __int64 v40; // [esp+30h] [ebp-4Ch]
  tagRECT bounds; // [esp+38h] [ebp-44h]
  tagRECT rcFocus; // [esp+48h] [ebp-34h] BYREF
  tagPOINT offset; // [esp+58h] [ebp-24h] BYREF
  CChoreoActorWidget *actor; // [esp+60h] [ebp-1Ch]
  CChoreoChannelWidget *channel; // [esp+64h] [ebp-18h]
  int v46; // [esp+68h] [ebp-14h]
  int i; // [esp+6Ch] [ebp-10h]
  int j; // [esp+70h] [ebp-Ch]
  int k; // [esp+74h] [ebp-8h]
  int leftEdge; // [esp+78h] [ebp-4h]

  v4 = CChoreoView::ComputeEventDragType(this, mx, my);
  v5 = 0;
  this->m_nDragType = v4;
  if ( v4 == 0 )
  {
    if ( this->m_pClickedGlobalEvent == nullptr )
      return;
    this->m_nDragType = 1;
  }
  this->m_FocusRects.m_Size = 0;
  if ( this->m_FocusRects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
      this->m_FocusRects.m_Memory.m_pMemory = nullptr;
    }
    this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
  i = 0;
  if ( this->m_SceneActors.m_Size > 0 )
  {
    do
    {
      v6 = this->m_SceneActors.m_Memory.m_pMemory[v5];
      actor = v6;
      if ( v6 != nullptr )
      {
        j = 0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: v6) > 0 )
        {
          do
          {
            v7 = CChoreoActorWidget::GetChannel(this: v6, num: j);
            v8 = v7;
            channel = v7;
            if ( v7 != nullptr )
            {
              k = 0;
              if ( (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v7) > 0 )
              {
                while ( 1 )
                {
                  Event = CChoreoChannelWidget::GetEvent(this: v8, num: k);
                  v10 = Event;
                  if ( Event == nullptr || !Event->IsSelected(this: Event) )
                    goto LABEL_31;
                  if ( v10 != this->m_pClickedEvent
                    || (m_nClickedTag = this->m_nClickedTag) == -1 && this->m_pClickedAbsoluteTag == nullptr )
                  {
                    rcFocus.left = v10->x(this: v10);
                    rcFocus.top = v10->y(this: v10);
                    v21 = v10->GetDurationRightEdge(this: v10);
                    v22 = v10->__vftable;
                    if ( v21 != 0 )
                    {
                      v23 = v22->GetDurationRightEdge(this: v10);
                      rcFocus.right = v10->x(this: v10) + v23;
                    }
                    else
                    {
                      v24 = v22->w(this: v10);
                      rcFocus.right = rcFocus.left + v24;
                    }
                    v25 = v10->h(this: v10);
                    rcFocus.bottom = rcFocus.top + v25;
                    goto LABEL_30;
                  }
                  v12 = this->m_pClickedAbsoluteTag == nullptr;
                  leftEdge = 0;
                  if ( v12 )
                    break;
                  v17 = v10->getBounds(this: v10);
                  v39 = *(_QWORD *)&v17->left;
                  v40 = *(_QWORD *)&v17->right;
                  v46 = v40 - v39;
                  if ( (int)v40 - (int)v39 > 0 )
                  {
                    Percentage = CEventAbsoluteTag::GetPercentage(this: this->m_pClickedAbsoluteTag);
                    v16 = Percentage * (double)v46;
LABEL_24:
                    leftEdge = (int)(v16 + 0.5);
                  }
LABEL_25:
                  v19 = v10->x(this: v10);
                  rcFocus.left = v19 + leftEdge - 1;
                  rcFocus.top = v10->y(this: v10) - 1;
                  rcFocus.right = rcFocus.left + 2;
                  v20 = v10->h(this: v10);
                  rcFocus.bottom = v10->y(this: v10) + v20;
LABEL_30:
                  offset.x = 0;
                  offset.y = 0;
                  Handle = (HWND)mxWidget::getHandle(this);
                  ClientToScreen(hWnd: Handle, lpPoint: &offset);
                  OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
                  m_Size = this->m_FocusRects.m_Size;
                  fr.m_rcFocus = rcFocus;
                  fr.m_rcOrig = rcFocus;
                  CUtlVector<PhonemeEditor::CFocusRect,CUtlMemory<PhonemeEditor::CFocusRect,int>>::InsertBefore(
                    this: &this->m_FocusRects,
                    elem: m_Size,
                    src: &fr);
                  v8 = channel;
LABEL_31:
                  v27 = ++k;
                  if ( v27 >= (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v8) )
                  {
                    v6 = actor;
                    goto LABEL_33;
                  }
                }
                v37 = m_nClickedTag;
                Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v10);
                RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(
                                                     this: (CChoreoEvent *)Header,
                                                     tagnum: v37);
                if ( RelativeTag == nullptr )
                  goto LABEL_25;
                bounds = *v10->getBounds(this: v10);
                v46 = bounds.right - bounds.left;
                if ( bounds.right - bounds.left <= 0 )
                  goto LABEL_25;
                v15 = CEventAbsoluteTag::GetPercentage(this: RelativeTag);
                v16 = v15 * (double)v46;
                goto LABEL_24;
              }
            }
LABEL_33:
            v28 = ++j;
          }
          while ( v28 < CChoreoWidgetDrawHelper::GetHeight(this: v6) );
          v5 = i;
        }
      }
      i = ++v5;
    }
    while ( v5 < this->m_SceneActors.m_Size );
    v5 = 0;
  }
  i = 0;
  if ( this->m_SceneGlobalEvents.m_Size > 0 )
  {
    do
    {
      m_pMemory = this->m_SceneGlobalEvents.m_Memory.m_pMemory;
      v30 = m_pMemory[v5];
      if ( v30 != nullptr && v30->IsSelected(this: m_pMemory[v5]) )
      {
        v31 = v30->w(this: v30) / 2;
        *(_QWORD *)&rcFocus.left = (unsigned int)(v31 + v30->x(this: v30));
        rcFocus.right = rcFocus.left + 2;
        rcFocus.bottom = mxWidget::h2(this);
        offset.x = 0;
        offset.y = 0;
        v32 = (HWND)mxWidget::getHandle(this);
        ClientToScreen(hWnd: v32, lpPoint: &offset);
        OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
        v36 = this->m_FocusRects.m_Size;
        fr.m_rcFocus = rcFocus;
        fr.m_rcOrig = rcFocus;
        CUtlVector<PhonemeEditor::CFocusRect,CUtlMemory<PhonemeEditor::CFocusRect,int>>::InsertBefore(
          this: &this->m_FocusRects,
          elem: v36,
          src: &fr);
        v5 = i;
      }
      i = ++v5;
    }
    while ( v5 < this->m_SceneGlobalEvents.m_Size );
  }
  v33 = this->m_nDragType - 1;
  this->m_xStart = mx;
  this->m_yStart = my;
  this->m_hPrevCursor = nullptr;
  switch ( v33 )
  {
    case 0:
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
      goto LABEL_46;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 9:
    case 10:
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
      goto LABEL_46;
    case 6:
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F01);
LABEL_46:
      this->m_hPrevCursor = SetCursor(hCursor: CursorA);
      break;
    default:
      break;
  }
  CChoreoView::DrawFocusRect(this);
  this->m_bDragging = true;
}

//------------------------------------------------------------------------------
// Address: 0x0042EB90
// Name: public: void CChoreoView::MouseMove(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MouseMove(CChoreoView *this, int mx, int my)
{
  CChoreoGlobalEventWidget *GlobalEventUnderCursorPos; // ebx
  HCURSOR CursorA; // eax
  int dragtype; // [esp+10h] [ebp+Ch]

  if ( !this->m_bDragging )
  {
    dragtype = CChoreoView::ComputeEventDragType(this, mx, my);
    if ( dragtype == 0 )
    {
      GlobalEventUnderCursorPos = CChoreoView::GetGlobalEventUnderCursorPos(this, mx, my);
      this->m_nSelectedEvents = CChoreoView::CountSelectedEvents(this);
      if ( GlobalEventUnderCursorPos != nullptr )
      {
        dragtype = 1;
      }
      else if ( CChoreoView::IsMouseOverSceneEndTime(this, mx) )
      {
        dragtype = 9;
      }
    }
    if ( this->m_hPrevCursor != nullptr )
    {
      SetCursor(hCursor: this->m_hPrevCursor);
      this->m_hPrevCursor = nullptr;
    }
    switch ( dragtype )
    {
      case 1:
        CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
        goto LABEL_13;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 9:
      case 10:
      case 11:
        CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
        goto LABEL_13;
      case 7:
        CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F01);
LABEL_13:
        this->m_hPrevCursor = SetCursor(hCursor: CursorA);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EC70
// Name: public: void CChoreoView::CreateSceneWidgets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::CreateSceneWidgets(CChoreoView *this)
{
  CChoreoView *v1; // esi
  CChoreoScene *m_pScene; // ecx
  int v3; // ebx
  CChoreoActor *Actor; // edi
  CChoreoActorWidget *v5; // eax
  IFaceposerModels *v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CChoreoActorWidget **m_pMemory; // ecx
  int v10; // eax
  IFaceposerModels **v11; // edi
  int v12; // edi
  CChoreoEvent *Event; // eax
  int v14; // edi
  CChoreoGlobalEventWidget *v15; // eax
  IFaceposerModels *v16; // ebx
  int v17; // edi
  int v18; // eax
  CChoreoGlobalEventWidget **v19; // ecx
  int v20; // eax
  CChoreoGlobalEventWidget **v21; // ecx
  IFaceposerModels **v22; // edi
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]

  v1 = this;
  CChoreoView::DeleteSceneWidgets(this);
  m_pScene = v1->m_pScene;
  v3 = 0;
  v1->m_bSuppressLayout = true;
  i = 0;
  if ( CChoreoScene::GetNumActors(this: m_pScene) > 0 )
  {
    do
    {
      Actor = CChoreoScene::GetActor(this: v1->m_pScene, actor: v3);
      if ( Actor != nullptr )
      {
        v5 = (CChoreoActorWidget *)CChoreoWidget::operator new(stAllocateBlock: 0x644u);
        if ( v5 != nullptr )
          v6 = (IFaceposerModels *)CChoreoActorWidget::CChoreoActorWidget(this: v5, parent: nullptr);
        else
          v6 = nullptr;
        IFaceposerModels::ForceActiveModelIndex(this: v6, index: (int)Actor);
        v6->Count(this: v6);
        m_Size = v1->m_SceneActors.m_Size;
        m_nAllocationCount = v1->m_SceneActors.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_SceneActors,
            num: m_Size - m_nAllocationCount + 1);
        ++v1->m_SceneActors.m_Size;
        m_pMemory = v1->m_SceneActors.m_Memory.m_pMemory;
        v10 = v1->m_SceneActors.m_Size - m_Size - 1;
        v1->m_SceneActors.m_pElements = m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
        v11 = (IFaceposerModels **)&v1->m_SceneActors.m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
          *v11 = v6;
        CChoreoActorWidget::ShowChannels(this: (CChoreoActorWidget *)v6, show: this->m_ActorExpanded[i].expanded);
        v3 = i;
        v1 = this;
      }
      i = ++v3;
    }
    while ( v3 < CChoreoScene::GetNumActors(this: v1->m_pScene) );
  }
  v12 = 0;
  for ( ia = 0; ia < (int)CChoreoScene::GetNumEvents(this: (IterateRIFF *)v1->m_pScene); v12 = ia )
  {
    Event = CChoreoScene::GetEvent(this: v1->m_pScene, event: v12);
    v14 = (int)Event;
    if ( Event != nullptr && CChoreoEvent::GetActor(this: Event) == nullptr )
    {
      v15 = (CChoreoGlobalEventWidget *)CChoreoWidget::operator new(stAllocateBlock: 0x4Cu);
      if ( v15 != nullptr )
        v16 = (IFaceposerModels *)CChoreoGlobalEventWidget::CChoreoGlobalEventWidget(this: v15, parent: nullptr);
      else
        v16 = nullptr;
      IFaceposerModels::ForceActiveModelIndex(this: v16, index: v14);
      v16->Count(this: v16);
      v17 = v1->m_SceneGlobalEvents.m_Size;
      v18 = v1->m_SceneGlobalEvents.m_Memory.m_nAllocationCount;
      if ( v17 + 1 > v18 )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_SceneGlobalEvents,
          num: v17 - v18 + 1);
      ++v1->m_SceneGlobalEvents.m_Size;
      v19 = v1->m_SceneGlobalEvents.m_Memory.m_pMemory;
      v20 = v1->m_SceneGlobalEvents.m_Size - v17 - 1;
      v1->m_SceneGlobalEvents.m_pElements = v19;
      if ( v20 > 0 )
        _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
      v21 = v1->m_SceneGlobalEvents.m_Memory.m_pMemory;
      v1 = this;
      v22 = (IFaceposerModels **)&v21[v17];
      if ( v22 != nullptr )
        *v22 = v16;
    }
    ++ia;
  }
  v1->m_bSuppressLayout = false;
}

//------------------------------------------------------------------------------
// Address: 0x0042EE90
// Name: public: void CChoreoView::LoadSceneFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::LoadSceneFromFile(
        CChoreoView *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *filename)
{
  const char *v5; // ecx
  char v6; // al
  bool v7; // zf
  bool v8; // bl
  const char *v9; // eax
  char fn[512]; // [esp+4h] [ebp-200h] BYREF

  v5 = filename;
  if ( *filename == 47 || *filename == 92 )
    v5 = filename + 1;
  V_strncpy(pDest: fn, pSrc: v5, maxLen: 512);
  if ( this->m_pScene == nullptr || (CChoreoView::Close(this, a2), this->m_pScene == nullptr) )
  {
    this->m_pScene = CChoreoView::LoadScene(this, filename: fn);
    MDLViewer::InitGridSettings(this: g_MDLViewer);
    if ( this->m_pScene != nullptr )
    {
      MDLViewer::OnFileLoaded(this: g_MDLViewer, pszFile: fn);
      mxWidget::setVisible(this: this->m_btnPlay, b: true);
      mxWidget::setVisible(this: this->m_btnPause, b: true);
      mxWidget::setVisible(this: this->m_btnStop, b: true);
      mxWidget::setVisible(this: this->m_pPlaybackRate, b: true);
      CChoreoWidget::m_pScene = this->m_pScene;
      CChoreoView::SetChoreoFile(this, filename: fn);
      v6 = CChoreoView::FixupSequenceDurations(this, a2: a3, scene: this->m_pScene, checkonly: false);
      v7 = v6 == this->m_bDirty;
      this->m_bDirty = v6;
      v8 = !v7;
      if ( v6 == 0 )
      {
        CChoreoView::WipeUndo(this);
        this->redraw(this);
      }
      if ( v8 )
      {
        v9 = "* ";
        if ( !this->m_bDirty )
          v9 = defaultValue;
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: v9);
      }
      CChoreoView::DeleteSceneWidgets(this);
      CChoreoView::CreateSceneWidgets(this);
      this->m_nLastHPixelsNeeded = -1;
      this->m_nLastVPixelsNeeded = -1;
      CChoreoView::InvalidateLayout(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EFF0
// Name: public: void CChoreoView::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::Undo(CChoreoView *this)
{
  int m_nUndoLevel; // eax
  CChoreoView::CVUndo **m_pMemory; // ecx
  int v4; // eax
  const CChoreoScene **p_undo; // ebx

  if ( this->m_UndoStack.m_Size > 0 )
  {
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel > 0 )
    {
      m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
      v4 = m_nUndoLevel - 1;
      this->m_nUndoLevel = v4;
      p_undo = (const CChoreoScene **)&m_pMemory[v4]->undo;
      CChoreoView::DeleteSceneWidgets(this);
      CChoreoScene::operator=(this: this->m_pScene, src: *p_undo);
      MDLViewer::InitGridSettings(this: g_MDLViewer);
      CChoreoView::CreateSceneWidgets(this);
      CChoreoView::ReportSceneClearToTools(this);
      *(_QWORD *)&this->m_Flyover.a = 0;
      *(_QWORD *)&this->m_Flyover.e = 0;
      *(_QWORD *)&this->m_Flyover.tag = 0;
      this->m_Flyover.ccbutton = 0;
      this->m_pClickedActor = nullptr;
      this->m_pClickedChannel = nullptr;
      this->m_pClickedEvent = nullptr;
      this->m_pClickedGlobalEvent = nullptr;
    }
  }
  CChoreoView::InvalidateLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042F090
// Name: public: void CChoreoView::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::Redo(CChoreoView *this)
{
  int m_Size; // ecx
  int m_nUndoLevel; // eax
  CChoreoView::CVUndo *v4; // ebx

  m_Size = this->m_UndoStack.m_Size;
  if ( m_Size > 0 )
  {
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel <= m_Size - 1 )
    {
      v4 = this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel];
      CChoreoView::DeleteSceneWidgets(this);
      CChoreoScene::operator=(this: this->m_pScene, src: v4->redo);
      MDLViewer::InitGridSettings(this: g_MDLViewer);
      CChoreoView::CreateSceneWidgets(this);
      CChoreoView::ReportSceneClearToTools(this);
      *(_QWORD *)&this->m_Flyover.a = 0;
      *(_QWORD *)&this->m_Flyover.e = 0;
      *(_QWORD *)&this->m_Flyover.tag = 0;
      this->m_Flyover.ccbutton = 0;
      ++this->m_nUndoLevel;
      this->m_pClickedActor = nullptr;
      this->m_pClickedChannel = nullptr;
      this->m_pClickedEvent = nullptr;
      this->m_pClickedGlobalEvent = nullptr;
    }
  }
  CChoreoView::InvalidateLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042F140
// Name: public: void CChoreoView::PushUndo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::PushUndo(CChoreoView *this, const char *description)
{
  CChoreoScene *v3; // eax
  CChoreoScene *v4; // esi
  CChoreoView::CVUndo *v5; // edi
  char *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CChoreoView::CVUndo **m_pMemory; // ecx
  int v10; // eax
  CChoreoView::CVUndo **v11; // edi
  CChoreoView::CVUndo *undo; // [esp+Ch] [ebp-4h]

  this->m_bRedoPending = true;
  CChoreoView::WipeRedo(this);
  v3 = (CChoreoScene *)operator new(nSize: 0x218u);
  if ( v3 != nullptr )
    v4 = CChoreoScene::CChoreoScene(this: v3, callback: &this->IChoreoEventCallback);
  else
    v4 = nullptr;
  CChoreoScene::operator=(this: v4, src: this->m_pScene);
  v5 = (CChoreoView::CVUndo *)operator new(nSize: 0x10u);
  v5->undo = v4;
  undo = v5;
  v5->redo = nullptr;
  v6 = (char *)operator new(nSize: strlen(description) + 1);
  strcpy(v6, description);
  v5->udescription = v6;
  v5->rdescription = nullptr;
  m_Size = this->m_UndoStack.m_Size;
  m_nAllocationCount = this->m_UndoStack.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_UndoStack,
      num: m_Size - m_nAllocationCount + 1);
  m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
  v10 = ++this->m_UndoStack.m_Size - m_Size - 1;
  this->m_UndoStack.m_pElements = m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
  v11 = &this->m_UndoStack.m_Memory.m_pMemory[m_Size];
  if ( v11 != nullptr )
    *v11 = undo;
  ++this->m_nUndoLevel;
}

//------------------------------------------------------------------------------
// Address: 0x0042F260
// Name: public: void CChoreoView::ImportEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ImportEvents(CChoreoView *this)
{
  char *v2; // edi
  bool m_bDirty; // zf
  CChoreoActor *Actor; // eax
  char *Header; // [esp-8h] [ebp-40Ch]
  char fullpathbuf[512]; // [esp+4h] [ebp-400h] BYREF
  char eventfile[512]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pScene != nullptr
    && this->m_pClickedActor != nullptr
    && this->m_pClickedChannel != nullptr
    && FacePoser_ShowOpenFileNameDialog(relative: eventfile, bufsize: 0x200u, subdir: "scenes", wildcard: "*.vce") )
  {
    v2 = eventfile;
    if ( !V_IsAbsolutePath(pStr: eventfile) )
    {
      filesystem->RelativePathToFullPath(
        this: filesystem,
        a2: eventfile,
        a3: "GAME",
        a4: fullpathbuf,
        a5: 512,
        a6: (PathTypeFilter_t)0,
        a7: nullptr);
      v2 = fullpathbuf;
    }
    if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v2, a3: nullptr) )
    {
      LoadScriptFile(filename: v2, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      CChoreoView::DeselectAll(this);
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Import Events");
      Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedChannel);
      Actor = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)this->m_pClickedActor);
      CChoreoScene::ImportEvents(
        this: this->m_pScene,
        tokenizer: tokenprocessor,
        actor: Actor,
        channel: (CChoreoChannel *)Header);
      CChoreoView::PushRedo(this, description: "Import Events");
      CChoreoView::CreateSceneWidgets(this);
      CChoreoView::InvalidateLayout(this);
      Con_Printf(fmt: "Imported events from %s\n", v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F3B0
// Name: public: void CChoreoView::ExportEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ExportEvents(CChoreoView *this)
{
  CChoreoView *v1; // edi
  int v2; // ebx
  CChoreoActorWidget *v3; // esi
  int v4; // edi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v6; // edi
  int v7; // ebx
  CChoreoEventWidget *v8; // eax
  CAudioSourceWave *v9; // esi
  int m_Size; // eax
  int v11; // esi
  CChoreoEvent **m_pMemory; // ecx
  int v13; // eax
  CChoreoEvent **v14; // eax
  CChoreoEvent **v15; // eax
  char eventfilename[512]; // [esp+4h] [ebp-228h] BYREF
  CChoreoActorWidget *a; // [esp+204h] [ebp-28h]
  CChoreoEvent *event; // [esp+208h] [ebp-24h]
  int j; // [esp+20Ch] [ebp-20h]
  int i; // [esp+210h] [ebp-1Ch]
  CChoreoView *v21; // [esp+214h] [ebp-18h]
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > events; // [esp+218h] [ebp-14h] BYREF

  v1 = this;
  v21 = this;
  if ( FacePoser_ShowSaveFileNameDialog(relative: eventfilename, bufsize: 0x200u, subdir: "scenes", wildcard: "*.vce") )
  {
    V_DefaultExtension(path: eventfilename, extension: ".vce", pathStringLength: 512);
    Con_Printf(fmt: "Exporting events to %s\n", eventfilename);
    v2 = 0;
    memset(&events, 0, sizeof(events));
    i = 0;
    if ( v1->m_SceneActors.m_Size <= 0 )
      goto LABEL_24;
    do
    {
      v3 = v1->m_SceneActors.m_Memory.m_pMemory[v2];
      a = v3;
      if ( v3 != nullptr )
      {
        v4 = 0;
        j = 0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: v3) > 0 )
        {
          do
          {
            Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v3, num: v4);
            v6 = (CChoreoChannelWidget *)Channel;
            if ( Channel != nullptr )
            {
              v7 = 0;
              if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
              {
                do
                {
                  v8 = CChoreoChannelWidget::GetEvent(this: v6, num: v7);
                  v9 = (CAudioSourceWave *)v8;
                  if ( v8 != nullptr && v8->IsSelected(this: v8) )
                  {
                    event = (CChoreoEvent *)CAudioSourceWave::GetHeader(this: v9);
                    if ( event != nullptr )
                    {
                      m_Size = events.m_Size;
                      v11 = events.m_Size;
                      if ( events.m_Size + 1 > events.m_Memory.m_nAllocationCount )
                      {
                        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&events,
                          num: events.m_Size - events.m_Memory.m_nAllocationCount + 1);
                        m_Size = events.m_Size;
                      }
                      m_pMemory = events.m_Memory.m_pMemory;
                      events.m_Size = m_Size + 1;
                      v13 = m_Size - v11;
                      events.m_pElements = events.m_Memory.m_pMemory;
                      if ( v13 > 0 )
                      {
                        _V_memmove(
                          dest: &events.m_Memory.m_pMemory[v11 + 1],
                          src: &events.m_Memory.m_pMemory[v11],
                          count: 4 * v13);
                        m_pMemory = events.m_Memory.m_pMemory;
                      }
                      v14 = &m_pMemory[v11];
                      if ( v14 != nullptr )
                        *v14 = event;
                    }
                  }
                  ++v7;
                }
                while ( v7 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v6) );
                v3 = a;
              }
            }
            v4 = ++j;
          }
          while ( v4 < CChoreoWidgetDrawHelper::GetHeight(this: v3) );
          v2 = i;
        }
        v1 = v21;
      }
      i = ++v2;
    }
    while ( v2 < v1->m_SceneActors.m_Size );
    if ( events.m_Size <= 0 )
LABEL_24:
      Con_Printf(fmt: "No events selected\n");
    else
      CChoreoScene::ExportEvents(this: v1->m_pScene, filename: eventfilename, &events);
    v15 = events.m_Memory.m_pMemory;
    events.m_Size = 0;
    if ( events.m_Memory.m_nGrowSize >= 0 )
    {
      if ( events.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: events.m_Memory.m_pMemory);
        v15 = nullptr;
        events.m_Memory.m_pMemory = nullptr;
      }
      events.m_Memory.m_nAllocationCount = 0;
    }
    events.m_pElements = v15;
    if ( events.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F5C0
// Name: private: void CChoreoView::OnChangeScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnChangeScale(CChoreoView *this)
{
  const char *Name; // eax
  CChoreoScene *m_pScene; // ecx
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  CChoreoScene *v8; // ecx
  int TimeZoom; // eax
  int v10; // [esp+0h] [ebp-5B4h]
  CInputParams params; // [esp+14h] [ebp-5A0h] BYREF
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > selected; // [esp+5A0h] [ebp-14h] BYREF

  if ( this->m_pScene != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    *(_QWORD *)params.m_szDialogTitle = *(_QWORD *)aChangeZ;
    strcpy(params.m_szPrompt, "New scale (e.g., 2.5x):");
    *(_DWORD *)&params.m_szDialogTitle[8] = (char *)&g_flexedverts[49579].z + 3;
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    m_pScene = this->m_pScene;
    v4 = m_pScene != nullptr ? CChoreoScene::GetTimeZoom(this: m_pScene, tool: Name) : 100;
    V_snprintf(pDest: params.m_szInputText, maxLen: 1024, pFormat: "%.2f", (float)((float)v4 * 0.0099999998));
    if ( InputProperties(&params) != 0 )
    {
      v5 = (int)(atof(nptr: params.m_szInputText) * 100.0);
      if ( v5 >= 1 )
      {
        if ( v5 > 1000 )
          v5 = 1000;
      }
      else
      {
        v5 = 1;
      }
      v10 = v5;
      v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      CChoreoView::SetTimeZoom(this, tool: v6, tz: v10, preserveFocus: false);
      this->m_nLastHPixelsNeeded = -1;
      this->m_nLastVPixelsNeeded = -1;
      memset(&selected, 0, sizeof(selected));
      CChoreoView::GetSelectedEvents(this, events: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&selected);
      CChoreoView::DeleteSceneWidgets(this);
      CChoreoView::CreateSceneWidgets(this);
      CChoreoView::ReselectEvents(this, list: &selected);
      CChoreoView::InvalidateLayout(this);
      v7 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v8 = this->m_pScene;
      if ( v8 != nullptr )
        TimeZoom = CChoreoScene::GetTimeZoom(this: v8, tool: v7);
      else
        TimeZoom = 100;
      Con_Printf(fmt: "Zoom factor %i %%\n", TimeZoom);
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&selected);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F770
// Name: public: void CChoreoView::OnCheckSequenceLengths(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChoreoView::OnCheckSequenceLengths(CChoreoView *this@<ecx>, int a2@<edi>)
{
  bool m_bDirty; // zf

  if ( this->m_pScene != nullptr )
  {
    Con_Printf(fmt: "Checking sequence durations...\n");
    if ( CChoreoView::FixupSequenceDurations(this, a2, scene: this->m_pScene, checkonly: true) != 0 )
    {
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Check sequence lengths");
      CChoreoView::FixupSequenceDurations(this, a2, scene: this->m_pScene, checkonly: false);
      CChoreoView::PushRedo(this, description: "Check sequence lengths");
      CChoreoView::InvalidateLayout(this);
    }
    else
    {
      Con_Printf(fmt: "   no changes...\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F800
// Name: public: void CChoreoView::OnInsertTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnInsertTime(CChoreoView *this)
{
  float time; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  bool m_bDirty; // zf
  int v6; // esi
  CChoreoActorWidget *v7; // edi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v9; // esi
  int v10; // edi
  CAudioSourceWave *Event; // eax
  char *Header; // eax
  int k; // esi
  TimelineItem *v14; // ecx
  CChoreoEvent *v15; // eax
  CChoreoScene *m_pScene; // ecx
  int v17; // eax
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v20; // ecx
  int TimeZoom; // eax
  int v22; // esi
  int m; // edi
  CChoreoActorWidget *v24; // ecx
  CChoreoScene *v25; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  float dt; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  CChoreoActorWidget *actor; // [esp+20h] [ebp-10h]
  float starttime; // [esp+24h] [ebp-Ch]
  float endtime; // [esp+28h] [ebp-8h]
  int j; // [esp+2Ch] [ebp-4h]

  if ( this->m_rgABPoints[0].active || this->m_rgABPoints[1].active )
  {
    Con_Printf(fmt: "OnInsertTime()\n");
    time = this->m_rgABPoints[0].time;
    v3 = this->m_rgABPoints[1].time;
    starttime = time;
    endtime = v3;
    if ( time > v3 )
    {
      time = this->m_rgABPoints[1].time;
      v3 = this->m_rgABPoints[0].time;
      starttime = time;
      endtime = v3;
    }
    v4 = v3 - time;
    if ( v4 != 0.0 )
    {
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Insert Time");
      v6 = 0;
      for ( i = 0; v6 < this->m_SceneActors.m_Size; i = v6 )
      {
        v7 = this->m_SceneActors.m_Memory.m_pMemory[v6];
        actor = v7;
        if ( v7 != nullptr )
        {
          j = 0;
          if ( CChoreoWidgetDrawHelper::GetHeight(this: v7) > 0 )
          {
            do
            {
              Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v7, num: j);
              v9 = (CChoreoChannelWidget *)Channel;
              if ( Channel != nullptr )
              {
                v10 = 0;
                if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
                {
                  do
                  {
                    Event = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v9, num: v10);
                    if ( Event != nullptr )
                    {
                      Header = CAudioSourceWave::GetHeader(this: Event);
                      if ( Header != nullptr )
                        CChoreoView::CheckInsertTime(this, e: (CChoreoEvent *)Header, dt: v4, starttime, endtime);
                    }
                    ++v10;
                  }
                  while ( v10 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v9) );
                }
                v7 = actor;
              }
              ++j;
            }
            while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v7) );
            v6 = i;
          }
        }
        ++v6;
      }
      for ( k = 0; k < this->m_SceneGlobalEvents.m_Size; ++k )
      {
        v14 = (TimelineItem *)this->m_SceneGlobalEvents.m_Memory.m_pMemory[k];
        if ( v14 != nullptr )
        {
          v15 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: v14);
          if ( v15 != nullptr )
            CChoreoView::CheckInsertTime(this, e: v15, dt: v4, starttime, endtime);
        }
      }
      CChoreoView::PushRedo(this, description: "Insert Time");
      if ( !this->m_bSuppressLayout )
      {
        m_pScene = this->m_pScene;
        if ( m_pScene != nullptr )
        {
          StopTime = CChoreoScene::FindStopTime(this: m_pScene);
          dt = StopTime;
          if ( StopTime < 5.0 )
            dt = 5.0;
          Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
          v20 = this->m_pScene;
          if ( v20 != nullptr )
            TimeZoom = CChoreoScene::GetTimeZoom(this: v20, tool: Name);
          else
            TimeZoom = 100;
          v17 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                           * (float)(dt + 5.0));
        }
        else
        {
          v17 = 0;
        }
        if ( v17 != this->m_nLastHPixelsNeeded )
          CChoreoView::RepositionHSlider(this);
        v22 = 0;
        for ( m = 0; v22 < this->m_SceneActors.m_Size; ++v22 )
        {
          v24 = this->m_SceneActors.m_Memory.m_pMemory[v22];
          if ( v24 != nullptr )
            m += v24->GetItemHeight(this: v24) + 2;
        }
        if ( m + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
          CChoreoView::RepositionVSlider(this);
        v25 = this->m_pScene;
        if ( v25 != nullptr )
        {
          CChoreoScene::ReconcileGestureTimes(this: v25);
          CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
        }
        redraw = this->redraw;
        this->m_bLayoutIsValid = false;
        redraw(this);
      }
      ExpressionTool::LayoutItems(this: g_pExpressionTool, force: true);
      g_pExpressionTool->redraw(this: g_pExpressionTool);
      g_pGestureTool->redraw(this: g_pGestureTool);
      g_pRampTool->redraw(this: g_pRampTool);
      g_pSceneRampTool->redraw(this: g_pSceneRampTool);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FB50
// Name: public: void CChoreoView::OnDeleteTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnDeleteTime(CChoreoView *this)
{
  CChoreoView *v1; // edi
  bool m_bDirty; // zf
  float v3; // xmm0_4
  float time; // xmm1_4
  int m_Size; // ebx
  int v6; // eax
  CChoreoActorWidget *v7; // esi
  CChoreoChannelWidget *v8; // eax
  CChoreoChannelWidget *v9; // esi
  CChoreoGlobalEventWidget *v10; // eax
  char *Header; // eax
  int v12; // esi
  CChoreoEventWidget **m_pMemory; // edi
  CChoreoGlobalEventWidget **v14; // eax
  channel_s *v15; // eax
  int v16; // esi
  int v17; // eax
  CChoreoGlobalEventWidget *v18; // ecx
  CChoreoEvent *v19; // eax
  int v20; // eax
  int v21; // esi
  CChoreoGlobalEventWidget **v22; // edi
  int v23; // eax
  CChoreoGlobalEventWidget **v24; // esi
  int m; // edi
  char *v26; // esi
  CChoreoChannel *v27; // eax
  int n; // esi
  CChoreoEvent *v29; // eax
  CChoreoView *v30; // esi
  CChoreoScene *m_pScene; // ecx
  int v32; // eax
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v35; // ecx
  int TimeZoom; // eax
  int v37; // ebx
  int ii; // edi
  CChoreoActorWidget *v39; // ecx
  CChoreoScene *v40; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  CUtlVector<CChoreoEventWidget *,CUtlMemory<CChoreoEventWidget *,int> > deletions; // [esp+1Ch] [ebp-54h] BYREF
  CUtlVector<CChoreoGlobalEventWidget *,CUtlMemory<CChoreoGlobalEventWidget *,int> > global_deletions; // [esp+30h] [ebp-40h] BYREF
  CChoreoGlobalEventWidget *event; // [esp+44h] [ebp-2Ch]
  float dt; // [esp+48h] [ebp-28h]
  int i; // [esp+4Ch] [ebp-24h]
  CChoreoActorWidget *actor; // [esp+50h] [ebp-20h]
  CChoreoChannelWidget *channel; // [esp+54h] [ebp-1Ch]
  float starttime; // [esp+58h] [ebp-18h]
  float endtime; // [esp+5Ch] [ebp-14h]
  int j; // [esp+60h] [ebp-10h]
  int k; // [esp+64h] [ebp-Ch]
  CChoreoView *v53; // [esp+68h] [ebp-8h]
  bool deleteEvent; // [esp+6Fh] [ebp-1h] BYREF

  v1 = this;
  m_bDirty = !this->m_rgABPoints[0].active;
  v53 = this;
  if ( !m_bDirty || this->m_rgABPoints[1].active )
  {
    Con_Printf(fmt: "OnDeleteTime()\n");
    time = v1->m_rgABPoints[1].time;
    starttime = v1->m_rgABPoints[0].time;
    v3 = starttime;
    endtime = time;
    if ( starttime > time )
    {
      v3 = time;
      time = starttime;
      starttime = v3;
      endtime = time;
    }
    dt = time - v3;
    if ( (float)(time - v3) != 0.0 )
    {
      m_bDirty = v1->m_bDirty;
      v1->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &v1->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this: v1, description: "Delete Time");
      m_Size = 0;
      v6 = 0;
      memset(&deletions, 0, sizeof(deletions));
      memset(&global_deletions, 0, sizeof(global_deletions));
      i = 0;
      if ( v1->m_SceneActors.m_Size > 0 )
      {
        do
        {
          v7 = v1->m_SceneActors.m_Memory.m_pMemory[v6];
          actor = v7;
          if ( v7 != nullptr )
          {
            j = 0;
            if ( CChoreoWidgetDrawHelper::GetHeight(this: v7) > 0 )
            {
              while ( 1 )
              {
                v8 = CChoreoActorWidget::GetChannel(this: v7, num: j);
                v9 = v8;
                channel = v8;
                if ( v8 != nullptr )
                {
                  k = 0;
                  if ( (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v8) > 0 )
                  {
                    do
                    {
                      v10 = (CChoreoGlobalEventWidget *)CChoreoChannelWidget::GetEvent(this: v9, num: k);
                      event = v10;
                      if ( v10 != nullptr )
                      {
                        Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v10);
                        if ( Header != nullptr )
                        {
                          deleteEvent = false;
                          CChoreoView::CheckDeleteTime(
                            this: v1,
                            e: (CChoreoEvent *)Header,
                            dt,
                            starttime,
                            endtime,
                            &deleteEvent);
                          if ( deleteEvent )
                          {
                            v12 = m_Size;
                            if ( m_Size + 1 > deletions.m_Memory.m_nAllocationCount )
                            {
                              CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&deletions,
                                num: m_Size - deletions.m_Memory.m_nAllocationCount + 1);
                              m_Size = deletions.m_Size;
                            }
                            m_pMemory = deletions.m_Memory.m_pMemory;
                            deletions.m_Size = ++m_Size;
                            deletions.m_pElements = deletions.m_Memory.m_pMemory;
                            if ( m_Size - v12 - 1 > 0 )
                              _V_memmove(
                                dest: &deletions.m_Memory.m_pMemory[v12 + 1],
                                src: &deletions.m_Memory.m_pMemory[v12],
                                count: 4 * (m_Size - v12 - 1));
                            v14 = (CChoreoGlobalEventWidget **)&m_pMemory[v12];
                            v1 = v53;
                            v9 = channel;
                            if ( v14 != nullptr )
                              *v14 = event;
                          }
                        }
                      }
                      ++k;
                      v15 = CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v9);
                    }
                    while ( k < (int)v15 );
                  }
                }
                v16 = ++j;
                if ( v16 >= CChoreoWidgetDrawHelper::GetHeight(this: actor) )
                  break;
                v7 = actor;
              }
            }
          }
          v6 = i + 1;
          i = v6;
        }
        while ( v6 < v1->m_SceneActors.m_Size );
      }
      v17 = 0;
      for ( i = 0; v17 < v1->m_SceneGlobalEvents.m_Size; i = v17 )
      {
        v18 = v1->m_SceneGlobalEvents.m_Memory.m_pMemory[v17];
        event = v18;
        if ( v18 != nullptr )
        {
          v19 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)v18);
          if ( v19 != nullptr )
          {
            deleteEvent = false;
            CChoreoView::CheckDeleteTime(this: v1, e: v19, dt, starttime, endtime, &deleteEvent);
            if ( deleteEvent )
            {
              v20 = global_deletions.m_Size;
              v21 = global_deletions.m_Size;
              if ( global_deletions.m_Size + 1 > global_deletions.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&global_deletions,
                  num: global_deletions.m_Size - global_deletions.m_Memory.m_nAllocationCount + 1);
                v20 = global_deletions.m_Size;
              }
              v22 = global_deletions.m_Memory.m_pMemory;
              global_deletions.m_Size = v20 + 1;
              v23 = v20 - v21;
              global_deletions.m_pElements = global_deletions.m_Memory.m_pMemory;
              if ( v23 > 0 )
                _V_memmove(
                  dest: &global_deletions.m_Memory.m_pMemory[v21 + 1],
                  src: &global_deletions.m_Memory.m_pMemory[v21],
                  count: 4 * v23);
              v24 = &v22[v21];
              v1 = v53;
              if ( v24 != nullptr )
                *v24 = event;
            }
          }
        }
        v17 = i + 1;
      }
      for ( m = 0; m < m_Size; ++m )
      {
        v26 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)deletions.m_Memory.m_pMemory[m]);
        v27 = CChoreoEvent::GetChannel(this: (CChoreoEvent *)v26);
        if ( v27 != nullptr )
          CChoreoChannel::RemoveEvent(this: v27, event: (CChoreoEvent *)v26);
        CChoreoScene::DeleteReferencedObjects(this: v53->m_pScene, event: (CChoreoEvent *)v26);
      }
      for ( n = 0; n < global_deletions.m_Size; ++n )
      {
        v29 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)global_deletions.m_Memory.m_pMemory[n]);
        CChoreoScene::DeleteReferencedObjects(this: v53->m_pScene, event: v29);
      }
      v30 = v53;
      v53->m_nLastHPixelsNeeded = -1;
      v30->m_nLastVPixelsNeeded = -1;
      if ( m_Size > 0 || global_deletions.m_Size > 0 )
      {
        CChoreoView::DeleteSceneWidgets(this: v30);
        CChoreoView::CreateSceneWidgets(this: v30);
      }
      CChoreoView::PushRedo(this: v30, description: "Delete Time");
      if ( !v30->m_bSuppressLayout )
      {
        m_pScene = v30->m_pScene;
        if ( m_pScene != nullptr )
        {
          StopTime = CChoreoScene::FindStopTime(this: m_pScene);
          dt = StopTime;
          if ( StopTime < 5.0 )
            dt = 5.0;
          Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&v30->IFacePoserToolWindow);
          v35 = v30->m_pScene;
          if ( v35 != nullptr )
            TimeZoom = CChoreoScene::GetTimeZoom(this: v35, tool: Name);
          else
            TimeZoom = 100;
          v32 = (int)(float)((float)((float)((float)TimeZoom * v30->m_flPixelsPerSecond) * 0.0099999998)
                           * (float)(dt + 5.0));
        }
        else
        {
          v32 = 0;
        }
        if ( v32 != v30->m_nLastHPixelsNeeded )
          CChoreoView::RepositionHSlider(this: v30);
        v37 = 0;
        for ( ii = 0; ii < v30->m_SceneActors.m_Size; ++ii )
        {
          v39 = v30->m_SceneActors.m_Memory.m_pMemory[ii];
          if ( v39 != nullptr )
            v37 += v39->GetItemHeight(this: v39) + 2;
        }
        if ( v37 + v30->m_nStartRow + v30->GetCaptionHeight(this: &v30->IFacePoserToolWindow) + 30 != v30->m_nLastVPixelsNeeded )
          CChoreoView::RepositionVSlider(this: v30);
        v40 = v30->m_pScene;
        if ( v40 != nullptr )
        {
          CChoreoScene::ReconcileGestureTimes(this: v40);
          CChoreoScene::ReconcileCloseCaption(this: v30->m_pScene);
        }
        redraw = v30->redraw;
        v30->m_bLayoutIsValid = false;
        redraw(this: v30);
      }
      ExpressionTool::LayoutItems(this: g_pExpressionTool, force: true);
      g_pExpressionTool->redraw(this: g_pExpressionTool);
      g_pGestureTool->redraw(this: g_pGestureTool);
      g_pRampTool->redraw(this: g_pRampTool);
      g_pSceneRampTool->redraw(this: g_pSceneRampTool);
      if ( global_deletions.m_Memory.m_nGrowSize >= 0 && global_deletions.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: global_deletions.m_Memory.m_pMemory);
      if ( deletions.m_Memory.m_nGrowSize >= 0 && deletions.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: deletions.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004300A0
// Name: private: bool CChoreoView::GenerateCombinedFile(char const __near *,char const __near *,enum gender_t,class CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoView::GenerateCombinedFile(
        CChoreoView *this,
        const char *outfilename,
        const char *cctoken,
        gender_t gender,
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *sorted)
{
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *v5; // edi
  int Inorder; // ebx
  CChoreoEvent *m_Data; // esi
  const char *Parameters; // eax
  const char *v9; // eax
  int m_Size; // eax
  int v11; // esi
  CombinerEntry *m_pMemory; // ecx
  int v13; // eax
  CombinerEntry *v14; // eax
  char actualfile[512]; // [esp+0h] [ebp-320h] BYREF
  CombinerEntry ce; // [esp+200h] [ebp-120h] BYREF
  float startoffset; // [esp+308h] [ebp-18h]
  CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > work; // [esp+30Ch] [ebp-14h] BYREF
  float curoffset; // [esp+328h] [ebp+8h]

  memset(&work, 0, sizeof(work));
  soundemitter->GenderExpandString(this: soundemitter, a2: gender, a3: outfilename, a4: actualfile, a5: 512);
  if ( _V_strlen(str: actualfile) <= 0 )
    goto LABEL_13;
  v5 = sorted;
  Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: sorted);
  if ( Inorder != 0xFFFF )
  {
    startoffset = CChoreoEvent::GetStartTime(this: sorted->m_Elements.m_pMemory[Inorder].m_Data);
    do
    {
      m_Data = v5->m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data;
      curoffset = CChoreoEvent::GetStartTime(this: m_Data);
      ce.wavefile[0] = 0;
      ce.startoffset = 0.0;
      Parameters = CChoreoEvent::GetParameters(this: m_Data);
      v9 = FacePoser_TranslateSoundNameGender(soundname: Parameters, gender);
      V_snprintf(pDest: ce.wavefile, maxLen: 260, pFormat: "sound/%s", v9);
      m_Size = work.m_Size;
      ce.startoffset = curoffset - startoffset;
      v11 = work.m_Size;
      if ( work.m_Size + 1 > work.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CombinerEntry,int>::Grow(
          this: &work.m_Memory,
          num: work.m_Size - work.m_Memory.m_nAllocationCount + 1);
        m_Size = work.m_Size;
      }
      m_pMemory = work.m_Memory.m_pMemory;
      work.m_Size = m_Size + 1;
      v13 = m_Size - v11;
      work.m_pElements = work.m_Memory.m_pMemory;
      if ( v13 > 0 )
      {
        _V_memmove(dest: &work.m_Memory.m_pMemory[v11 + 1], src: &work.m_Memory.m_pMemory[v11], count: 264 * v13);
        m_pMemory = work.m_Memory.m_pMemory;
      }
      v14 = &m_pMemory[v11];
      if ( v14 != nullptr )
      {
        *v14 = ce;
        v5 = sorted;
      }
      Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                    this: v5,
                                    i: Inorder);
    }
    while ( Inorder != 0xFFFF );
  }
  if ( !soundcombiner->CombineSoundFiles(this: soundcombiner, a2: filesystem, a3: actualfile, a4: &work) )
  {
    Con_ErrorPrintf(fmt: "Failed to create combined sound '%s':'%s'\n", cctoken, actualfile);
LABEL_13:
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&work);
    return 0;
  }
  Con_Printf(fmt: "Created combined sound '%s':'%s'\n", cctoken, actualfile);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&work);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00430280
// Name: private: bool CChoreoView::ValidateCombinedFileCheckSum(char const __near *,char const __near *,enum gender_t,class CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::ValidateCombinedFileCheckSum(
        CChoreoView *this,
        const char *outfilename,
        const char *cctoken,
        gender_t gender,
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *sorted)
{
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *v6; // edi
  int Inorder; // ebx
  CChoreoEvent *m_Data; // esi
  const char *Parameters; // eax
  const char *v10; // eax
  int m_Size; // eax
  int v12; // esi
  CombinerEntry *m_pMemory; // ecx
  int v14; // eax
  CombinerEntry *v15; // eax
  bool v16; // bl
  char actualfile[512]; // [esp+0h] [ebp-320h] BYREF
  CombinerEntry ce; // [esp+200h] [ebp-120h] BYREF
  float startoffset; // [esp+308h] [ebp-18h]
  CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > work; // [esp+30Ch] [ebp-14h] BYREF
  float curoffset; // [esp+328h] [ebp+8h]

  memset(&work, 0, sizeof(work));
  soundemitter->GenderExpandString(this: soundemitter, a2: gender, a3: outfilename, a4: actualfile, a5: 512);
  if ( _V_strlen(str: actualfile) > 0 )
  {
    v6 = sorted;
    Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: sorted);
    if ( Inorder != 0xFFFF )
    {
      startoffset = CChoreoEvent::GetStartTime(this: sorted->m_Elements.m_pMemory[Inorder].m_Data);
      do
      {
        m_Data = v6->m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data;
        curoffset = CChoreoEvent::GetStartTime(this: m_Data);
        ce.wavefile[0] = 0;
        ce.startoffset = 0.0;
        Parameters = CChoreoEvent::GetParameters(this: m_Data);
        v10 = FacePoser_TranslateSoundNameGender(soundname: Parameters, gender);
        V_snprintf(pDest: ce.wavefile, maxLen: 260, pFormat: "sound/%s", v10);
        m_Size = work.m_Size;
        ce.startoffset = curoffset - startoffset;
        v12 = work.m_Size;
        if ( work.m_Size + 1 > work.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CombinerEntry,int>::Grow(
            this: &work.m_Memory,
            num: work.m_Size - work.m_Memory.m_nAllocationCount + 1);
          m_Size = work.m_Size;
        }
        m_pMemory = work.m_Memory.m_pMemory;
        work.m_Size = m_Size + 1;
        v14 = m_Size - v12;
        work.m_pElements = work.m_Memory.m_pMemory;
        if ( v14 > 0 )
        {
          _V_memmove(dest: &work.m_Memory.m_pMemory[v12 + 1], src: &work.m_Memory.m_pMemory[v12], count: 264 * v14);
          m_pMemory = work.m_Memory.m_pMemory;
        }
        v15 = &m_pMemory[v12];
        if ( v15 != nullptr )
        {
          *v15 = ce;
          v6 = sorted;
        }
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                      this: v6,
                                      i: Inorder);
      }
      while ( Inorder != 0xFFFF );
    }
    v16 = soundcombiner->IsCombinedFileChecksumValid(this: soundcombiner, a2: filesystem, a3: actualfile, a4: &work);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&work);
    return v16;
  }
  else
  {
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&work);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430430
// Name: private: void CChoreoView::OnRemoveSpeakEventFromGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnRemoveSpeakEventFromGroup(CChoreoView *this)
{
  int v2; // esi
  CChoreoEvent *v3; // ebx
  CChoreoEvent *CaptionClickedEvent; // eax
  bool m_bDirty; // zf
  int v6; // esi
  int i; // ebx
  CChoreoScene *m_pScene; // ecx
  int v9; // eax
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v12; // ecx
  int TimeZoom; // eax
  CChoreoScene *v14; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  CChoreoEvent **m_pMemory; // eax
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > selected; // [esp+10h] [ebp-2Ch] BYREF
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > processlist; // [esp+24h] [ebp-18h] BYREF
  void *dest; // [esp+38h] [ebp-4h]

  if ( this->m_pScene != nullptr )
  {
    memset(&selected, 0, sizeof(selected));
    memset(&processlist, 0, sizeof(processlist));
    if ( CChoreoView::GetSelectedEvents(this, events: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&selected) <= 0 )
    {
      CaptionClickedEvent = CChoreoChannelWidget::GetCaptionClickedEvent(this: this->m_pClickedChannel);
      CChoreoChannelWidget::GetMasterAndSlaves(
        this: this->m_pClickedChannel,
        master: CaptionClickedEvent,
        fulllist: &processlist);
    }
    else
    {
      v2 = selected.m_Size - 1;
      if ( selected.m_Size - 1 >= 0 )
      {
        dest = &selected.m_Memory.m_pMemory[v2];
        do
        {
          v3 = *(CChoreoEvent **)dest;
          if ( CChoreoEvent::GetType(this: *(CChoreoEvent **)dest) == SPEAK )
          {
            if ( CChoreoEvent::GetCloseCaptionType(this: v3) != CC_DISABLED )
            {
              CChoreoChannelWidget::GetMasterAndSlaves(
                this: this->m_pClickedChannel,
                master: v3,
                fulllist: &processlist);
              goto LABEL_13;
            }
            if ( selected.m_Size - v2 - 1 > 0 )
            {
              _V_memmove(dest, src: (char *)dest + 4, count: 4 * (selected.m_Size - v2 - 1));
              --selected.m_Size;
              goto LABEL_13;
            }
          }
          else if ( selected.m_Size - v2 - 1 > 0 )
          {
            _V_memmove(dest, src: (char *)dest + 4, count: 4 * (selected.m_Size - v2 - 1));
          }
          --selected.m_Size;
LABEL_13:
          dest = (char *)dest - 4;
          --v2;
        }
        while ( v2 >= 0 );
      }
    }
    if ( selected.m_Size >= 1 )
    {
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Remove speak event(s)");
      v6 = 0;
      for ( i = processlist.m_Size; v6 < i; ++v6 )
      {
        CChoreoEvent::SetCloseCaptionToken(this: processlist.m_Memory.m_pMemory[v6], token: defaultValue);
        CChoreoWidget::setVisible(this: processlist.m_Memory.m_pMemory[v6], type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: processlist.m_Memory.m_pMemory[v6], isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: processlist.m_Memory.m_pMemory[v6], checksum: 0);
        CChoreoEvent::SetNumSlaves(this: processlist.m_Memory.m_pMemory[v6], num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: processlist.m_Memory.m_pMemory[v6], t: 0.0);
      }
      CChoreoView::PushRedo(this, description: "Remove speak event(s)");
      if ( !this->m_bSuppressLayout )
      {
        m_pScene = this->m_pScene;
        if ( m_pScene != nullptr )
        {
          StopTime = CChoreoScene::FindStopTime(this: m_pScene);
          *(float *)&dest = StopTime;
          if ( StopTime < 5.0 )
            *(float *)&dest = 5.0;
          Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
          v12 = this->m_pScene;
          if ( v12 != nullptr )
            TimeZoom = CChoreoScene::GetTimeZoom(this: v12, tool: Name);
          else
            TimeZoom = 100;
          v9 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                          * (float)(*(float *)&dest + 5.0));
        }
        else
        {
          v9 = 0;
        }
        if ( v9 != this->m_nLastHPixelsNeeded )
          CChoreoView::RepositionHSlider(this);
        if ( CChoreoView::ComputeVPixelsNeeded(this) != this->m_nLastVPixelsNeeded )
          CChoreoView::RepositionVSlider(this);
        v14 = this->m_pScene;
        if ( v14 != nullptr )
        {
          CChoreoScene::ReconcileGestureTimes(this: v14);
          CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
        }
        redraw = this->redraw;
        this->m_bLayoutIsValid = false;
        redraw(this);
      }
      Con_Printf(fmt: "Reverted %i events to use default close caption token\n", i);
      m_pMemory = processlist.m_Memory.m_pMemory;
      processlist.m_Size = 0;
      if ( processlist.m_Memory.m_nGrowSize >= 0 )
      {
        if ( processlist.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: processlist.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          processlist.m_Memory.m_pMemory = nullptr;
        }
        processlist.m_Memory.m_nAllocationCount = 0;
      }
      processlist.m_pElements = m_pMemory;
      if ( processlist.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          processlist.m_Memory.m_pMemory = nullptr;
        }
        processlist.m_Memory.m_nAllocationCount = 0;
      }
      if ( selected.m_Memory.m_nGrowSize >= 0 && selected.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: selected.m_Memory.m_pMemory);
    }
    else
    {
      Con_ErrorPrintf(fmt: "No eligible SPEAK event selected.\n");
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&processlist);
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&selected);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430750
// Name: private: bool CChoreoView::AreSelectedEventsCombinable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::AreSelectedEventsCombinable(CChoreoView *this)
{
  CChoreoChannel *v3; // ebx
  int v4; // edi
  CChoreoEvent *v5; // esi
  CChoreoChannel *Channel; // eax
  bool v7; // bl
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > events; // [esp+8h] [ebp-28h] BYREF
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > selected; // [esp+1Ch] [ebp-14h] BYREF

  memset(&events, 0, sizeof(events));
  if ( CChoreoView::GetSelectedEvents(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&events) > 0 )
  {
    v3 = nullptr;
    memset(&selected, 0, sizeof(selected));
    CChoreoView::GetSelectedEvents(this, events: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&selected);
    v4 = selected.m_Size - 1;
    if ( selected.m_Size - 1 < 0 )
    {
LABEL_9:
      v7 = selected.m_Size >= 2;
      if ( selected.m_Memory.m_nGrowSize >= 0 && selected.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: selected.m_Memory.m_pMemory);
      if ( events.m_Memory.m_nGrowSize >= 0 && events.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: events.m_Memory.m_pMemory);
      return v7;
    }
    else
    {
      while ( 1 )
      {
        v5 = selected.m_Memory.m_pMemory[v4];
        if ( CChoreoEvent::GetType(this: v5) != SPEAK )
          break;
        Channel = CChoreoEvent::GetChannel(this: v5);
        if ( v3 != nullptr )
        {
          if ( Channel != v3 )
            break;
        }
        else
        {
          v3 = Channel;
        }
        if ( --v4 < 0 )
          goto LABEL_9;
      }
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&selected);
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
      return false;
    }
  }
  else
  {
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430840
// Name: private: bool CChoreoView::AreSelectedEventsInSpeakGroup(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoView::AreSelectedEventsInSpeakGroup(CChoreoView *this)
{
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  CChoreoEvent *CaptionClickedEvent; // eax
  CChoreoEvent *v4; // esi
  int m_Size; // edi
  int v7; // esi
  CChoreoEvent **v8; // ebx
  int v9; // eax
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > selected; // [esp+8h] [ebp-1Ch] BYREF
  CChoreoEvent *e; // [esp+1Ch] [ebp-8h]
  bool v12; // [esp+23h] [ebp-1h]

  memset(&selected, 0, sizeof(selected));
  if ( CChoreoView::GetSelectedEvents(this, events: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&selected) <= 0 )
  {
    m_pClickedChannel = this->m_pClickedChannel;
    if ( m_pClickedChannel != nullptr
      && (CaptionClickedEvent = CChoreoChannelWidget::GetCaptionClickedEvent(this: m_pClickedChannel),
          v4 = CaptionClickedEvent,
          CaptionClickedEvent != nullptr)
      && CChoreoEvent::GetCloseCaptionType(this: CaptionClickedEvent) == CC_MASTER
      && CChoreoEvent::GetNumSlaves(this: v4) >= 1 )
    {
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&selected);
      return 1;
    }
    else
    {
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&selected);
      return 0;
    }
  }
  m_Size = selected.m_Size;
  v7 = selected.m_Size - 1;
  if ( selected.m_Size - 1 >= 0 )
  {
    v8 = &selected.m_Memory.m_pMemory[v7];
    while ( 1 )
    {
      e = *v8;
      if ( CChoreoEvent::GetType(this: e) != SPEAK )
        break;
      if ( CChoreoEvent::GetCloseCaptionType(this: e) == CC_DISABLED )
      {
        v9 = m_Size - v7 - 1;
        if ( v9 > 0 )
          goto LABEL_15;
        goto LABEL_16;
      }
LABEL_17:
      --v8;
      if ( --v7 < 0 )
        goto LABEL_18;
    }
    v9 = m_Size - v7 - 1;
    if ( v9 > 0 )
LABEL_15:
      _V_memmove(dest: v8, src: v8 + 1, count: 4 * v9);
LABEL_16:
    --m_Size;
    goto LABEL_17;
  }
LABEL_18:
  v12 = m_Size >= 1;
  if ( selected.m_Memory.m_nGrowSize >= 0 && selected.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: selected.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x00430950
// Name: private: void CChoreoView::OnChangeCloseCaptionToken(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnChangeCloseCaptionToken(CChoreoView *this, CChoreoEvent *e)
{
  int v3; // esi
  const char *CloseCaptionToken; // eax
  const char *v5; // eax
  const char *v6; // eax
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  bool m_bDirty; // zf
  int m_Size; // ebx
  const char *Name; // eax
  CCloseCaptionLookupParams params; // [esp+Ch] [ebp-4E0h] BYREF
  char oldToken[64]; // [esp+498h] [ebp-54h] BYREF
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > events; // [esp+4D8h] [ebp-14h] BYREF

  V_strncpy(pDest: params.m_szDialogTitle, pSrc: "Close Caption Token Lookup", maxLen: 128);
  v3 = 0;
  params.m_bPositionDialog = false;
  params.m_nLeft = 0;
  params.m_nTop = 0;
  CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
  V_strncpy(pDest: params.m_szCCToken, pSrc: CloseCaptionToken, maxLen: 1024);
  if ( CloseCaptionLookup(&params) != 0 )
  {
    v5 = CChoreoEvent::GetCloseCaptionToken(this: e);
    if ( _V_stricmp(s1: v5, s2: params.m_szCCToken) != 0 )
    {
      v6 = CChoreoEvent::GetCloseCaptionToken(this: e);
      V_strncpy(pDest: oldToken, pSrc: v6, maxLen: 64);
      m_pClickedChannel = this->m_pClickedChannel;
      memset(&events, 0, sizeof(events));
      CChoreoChannelWidget::GetMasterAndSlaves(this: m_pClickedChannel, master: e, fulllist: &events);
      if ( events.m_Size < 2 )
        Con_ErrorPrintf(fmt: "Can't combine events, must have at least two events selected.\n");
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Change closecaption token");
      m_Size = events.m_Size;
      if ( events.m_Size > 0 )
      {
        do
          CChoreoEvent::SetCloseCaptionToken(this: events.m_Memory.m_pMemory[v3++], token: params.m_szCCToken);
        while ( v3 < m_Size );
      }
      CChoreoView::PushRedo(this, description: "Change closecaption token");
      CChoreoView::InvalidateLayout(this);
      Name = CChoreoEvent::GetName(this: e);
      Con_Printf(fmt: "Close Caption token for '%s' changed to '%s'\n", Name, params.m_szCCToken);
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430AC0
// Name: private: void CChoreoView::OnToggleCloseCaptionsForEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnToggleCloseCaptionsForEvent(CChoreoView *this)
{
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  CChoreoEvent *CaptionClickedEvent; // eax
  CChoreoEvent *v4; // edi
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // eax
  CChoreoEvent::CLOSECAPTION v6; // ebx
  bool m_bDirty; // zf
  const char *Name; // eax
  const char *v9; // [esp-Ch] [ebp-10h]

  m_pClickedChannel = this->m_pClickedChannel;
  if ( m_pClickedChannel != nullptr )
  {
    CaptionClickedEvent = CChoreoChannelWidget::GetCaptionClickedEvent(this: m_pClickedChannel);
    v4 = CaptionClickedEvent;
    if ( CaptionClickedEvent != nullptr )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: CaptionClickedEvent);
      if ( CloseCaptionType != CC_MASTER )
      {
        if ( CloseCaptionType != CC_DISABLED )
          return;
        v6 = CC_MASTER;
      }
      else
      {
        v6 = CC_DISABLED;
      }
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Enable/disable captions");
      CChoreoWidget::setVisible(this: v4, type: v6);
      CChoreoView::PushRedo(this, description: "Enable/disable captions");
      CChoreoView::InvalidateLayout(this);
      v9 = CChoreoEvent::NameForCCType(type: v6);
      Name = CChoreoEvent::GetName(this: v4);
      Con_Printf(fmt: "Close Caption type for '%s' changed to '%s'\n", Name, v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430B70
// Name: private: void CChoreoView::OnAlign(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::OnAlign(CChoreoView *this@<ecx>, double a2@<st0>, bool left)
{
  int v3; // esi
  int v5; // eax
  int m_Size; // edi
  TimelineItem *v7; // esi
  int v8; // esi
  CChoreoEvent **m_pMemory; // ecx
  CChoreoEvent **v10; // esi
  CChoreoEvent **v11; // eax
  bool m_bDirty; // zf
  const char *v13; // eax
  CChoreoEvent *v14; // ecx
  double v15; // st7
  double StartTime; // st7
  CChoreoScene *m_pScene; // ecx
  int v18; // eax
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v21; // ecx
  int TimeZoom; // eax
  CChoreoScene *v23; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  char undotext[128]; // [esp+10h] [ebp-A8h] BYREF
  float offset; // [esp+90h] [ebp-28h]
  int idx; // [esp+94h] [ebp-24h]
  int newStartTime; // [esp+98h] [ebp-20h]
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > list; // [esp+9Ch] [ebp-1Ch] BYREF
  CChoreoEvent *e; // [esp+B0h] [ebp-8h]
  int i; // [esp+B4h] [ebp-4h] BYREF
  float lefta; // [esp+C0h] [ebp+8h]

  v3 = 0;
  memset(&list, 0, sizeof(list));
  CChoreoView::GetSelectedEvents(this, events: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&list);
  if ( left && (v5 = 0, *(float *)&i = 0.0, this->m_SceneGlobalEvents.m_Size > 0) )
  {
    m_Size = list.m_Size;
    do
    {
      v7 = (TimelineItem *)this->m_SceneGlobalEvents.m_Memory.m_pMemory[v5];
      if ( v7 != nullptr && ((unsigned __int8 (__thiscall *)(TimelineItem *))v7->__vftable[3].Draw)(a1: v7) != 0 )
      {
        e = (CChoreoEvent *)CActorBitmapButton::GetActor(this: v7);
        v8 = m_Size;
        if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&list,
            num: m_Size - list.m_Memory.m_nAllocationCount + 1);
          m_Size = list.m_Size;
        }
        m_pMemory = list.m_Memory.m_pMemory;
        list.m_Size = ++m_Size;
        list.m_pElements = list.m_Memory.m_pMemory;
        if ( m_Size - v8 - 1 > 0 )
        {
          _V_memmove(
            dest: &list.m_Memory.m_pMemory[v8 + 1],
            src: &list.m_Memory.m_pMemory[v8],
            count: 4 * (m_Size - v8 - 1));
          m_pMemory = list.m_Memory.m_pMemory;
        }
        v10 = &m_pMemory[v8];
        if ( v10 != nullptr )
          *v10 = e;
      }
      v5 = i + 1;
      i = v5;
    }
    while ( v5 < this->m_SceneGlobalEvents.m_Size );
    v3 = 0;
  }
  else
  {
    m_Size = list.m_Size;
  }
  if ( m_Size < 2 )
  {
    _Warning(a1: "Can't align, must have at least two events selected\n");
    if ( list.m_Memory.m_nGrowSize < 0 )
      return;
    v11 = list.m_Memory.m_pMemory;
    m_bDirty = list.m_Memory.m_pMemory == nullptr;
    goto LABEL_49;
  }
  idx = FindMetric(EndTime: a2, type: !left, &list, value: (float *)&i);
  if ( idx == -1 )
  {
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&list);
    return;
  }
  m_bDirty = this->m_bDirty;
  this->m_bDirty = true;
  if ( !m_bDirty )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  v13 = "Left";
  if ( !left )
    v13 = "Right";
  V_snprintf(pDest: undotext, maxLen: 128, pFormat: "Align %s", v13);
  CChoreoView::PushUndo(this, description: undotext);
  do
  {
    if ( v3 != idx )
    {
      v14 = list.m_Memory.m_pMemory[v3];
      e = v14;
      if ( left )
      {
        newStartTime = i;
      }
      else
      {
        v15 = ((double (__thiscall *)(CChoreoEvent *))v14->GetDuration)(a1: v14);
        v14 = e;
        *(float *)&newStartTime = *(float *)&i - v15;
      }
      StartTime = CChoreoEvent::GetStartTime(this: v14);
      offset = *(float *)&newStartTime - StartTime;
      CChoreoEvent::OffsetTime(this: e, dt: offset);
    }
    ++v3;
  }
  while ( v3 < m_Size );
  CChoreoView::PushRedo(this, description: undotext);
  if ( !this->m_bSuppressLayout )
  {
    m_pScene = this->m_pScene;
    if ( m_pScene != nullptr )
    {
      StopTime = CChoreoScene::FindStopTime(this: m_pScene);
      lefta = StopTime;
      if ( StopTime < 5.0 )
        lefta = 5.0;
      Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v21 = this->m_pScene;
      if ( v21 != nullptr )
        TimeZoom = CChoreoScene::GetTimeZoom(this: v21, tool: Name);
      else
        TimeZoom = 100;
      v18 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                       * (float)(lefta + 5.0));
    }
    else
    {
      v18 = 0;
    }
    if ( v18 != this->m_nLastHPixelsNeeded )
      CChoreoView::RepositionHSlider(this);
    if ( CChoreoView::ComputeVPixelsNeeded(this) != this->m_nLastVPixelsNeeded )
      CChoreoView::RepositionVSlider(this);
    v23 = this->m_pScene;
    if ( v23 != nullptr )
    {
      CChoreoScene::ReconcileGestureTimes(this: v23);
      CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
    }
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    v11 = list.m_Memory.m_pMemory;
    m_bDirty = list.m_Memory.m_pMemory == nullptr;
LABEL_49:
    if ( !m_bDirty )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430E70
// Name: private: void CChoreoView::OnMakeSameSize(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoView::OnMakeSameSize(CChoreoView *this@<ecx>, double a2@<st0>, bool smallest)
{
  bool m_bDirty; // zf
  const char *v5; // eax
  int v6; // esi
  CChoreoEvent **m_pMemory; // ebx
  double StartTime; // st7
  float endtime; // [esp+0h] [ebp-B0h]
  char undotext[128]; // [esp+10h] [ebp-A0h] BYREF
  int idx; // [esp+90h] [ebp-20h]
  float value; // [esp+94h] [ebp-1Ch] BYREF
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > list; // [esp+98h] [ebp-18h] BYREF
  int numSel; // [esp+ACh] [ebp-4h]

  memset(&list, 0, sizeof(list));
  numSel = CChoreoView::GetSelectedEvents(this, events: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&list);
  if ( numSel < 2 )
  {
    _Warning(a1: "Can't align, must have at least two events selected\n");
LABEL_3:
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&list);
    return;
  }
  idx = FindMetric(EndTime: a2, type: !smallest + 2, &list, &value);
  if ( idx == -1 )
    goto LABEL_3;
  m_bDirty = this->m_bDirty;
  this->m_bDirty = true;
  if ( !m_bDirty )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  v5 = "Smallest";
  if ( !smallest )
    v5 = "Largest";
  V_snprintf(pDest: undotext, maxLen: 128, pFormat: "Size to %s", v5);
  CChoreoView::PushUndo(this, description: undotext);
  v6 = 0;
  if ( numSel > 0 )
  {
    m_pMemory = list.m_Memory.m_pMemory;
    do
    {
      if ( v6 != idx )
      {
        StartTime = CChoreoEvent::GetStartTime(this: m_pMemory[v6]);
        endtime = StartTime + value;
        CChoreoEvent::SetEndTime(this: m_pMemory[v6], endtime);
      }
      ++v6;
    }
    while ( v6 < numSel );
  }
  CChoreoView::PushRedo(this, description: undotext);
  CChoreoView::InvalidateLayout(this);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&list);
}

//------------------------------------------------------------------------------
// Address: 0x004310E0
// Name: public: void CChoreoView::ShowContextMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ShowContextMenu(CChoreoView *this, int mx, int my)
{
  CChoreoChannelWidget *v4; // eax
  CChoreoEventWidget *v5; // ecx
  CChoreoGlobalEventWidget *v6; // edx
  int v7; // ecx
  CEventAbsoluteTag *v8; // edx
  int v9; // eax
  mxPopupMenu *v10; // eax
  mxPopupMenu *v11; // edi
  char *Header; // eax
  const char *Name; // eax
  const char *v14; // eax
  char *v15; // eax
  CChoreoEvent::EVENTTYPE Type; // eax
  char *v17; // eax
  const char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  mxPopupMenu *v21; // eax
  mxPopupMenu *v22; // ebx
  mxPopupMenu *v23; // eax
  mxPopupMenu *v24; // ebx
  CChoreoActor *Actor; // eax
  CChoreoActor *v26; // eax
  const char *v27; // eax
  char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  CChoreoEvent *v31; // eax
  __int32 v32; // eax
  __int32 v33; // eax
  CChoreoEvent *v34; // eax
  const char *v35; // eax
  CChoreoEvent *v36; // eax
  CChoreoEvent *v37; // eax
  mxPopupMenu *v38; // eax
  mxPopupMenu *v39; // eax
  mxPopupMenu *v40; // ebx
  CChoreoActor *v41; // eax
  CChoreoActor *v42; // eax
  const char *v43; // eax
  CChoreoActor *v44; // eax
  CChoreoActor *v45; // eax
  const char *v46; // eax
  char *v47; // eax
  const char *v48; // eax
  const char *v49; // eax
  char *v50; // eax
  const char *v51; // eax
  const char *v52; // eax
  mxPopupMenu *v53; // eax
  mxPopupMenu *v54; // ebx
  CChoreoActor *v55; // eax
  CChoreoActor *v56; // eax
  const char *v57; // eax
  char *v58; // eax
  const char *v59; // eax
  const char *v60; // eax
  char *v61; // eax
  const char *v62; // eax
  const char *v63; // eax
  CChoreoEvent *v64; // eax
  __int32 v65; // eax
  __int32 v66; // eax
  CChoreoEvent *v67; // eax
  const char *v68; // eax
  CChoreoEvent *v69; // eax
  CChoreoEvent *v70; // eax
  char *v71; // eax
  CEventAbsoluteTag *RelativeTag; // eax
  const char *v73; // eax
  const char *v74; // eax
  mxPopupMenu *v75; // eax
  mxPopupMenu *v76; // ebx
  CChoreoActor *v77; // eax
  CChoreoActor *v78; // eax
  const char *v79; // eax
  char *v80; // eax
  const char *v81; // eax
  const char *v82; // eax
  CChoreoEventWidget *v83; // ebx
  char *v84; // eax
  CChoreoEvent::EVENTTYPE v85; // eax
  char *v86; // eax
  const char *v87; // eax
  char *v88; // eax
  char *v89; // eax
  const char *v90; // eax
  const char *v91; // eax
  const char *v92; // eax
  char *v93; // eax
  const char *v94; // eax
  const char *v95; // eax
  char *v96; // eax
  char *v97; // eax
  const char *v98; // eax
  char *v99; // eax
  mxPopupMenu *v100; // eax
  const char *v101; // eax
  char *v102; // eax
  const char *v103; // eax
  const char *v104; // eax
  const char *v105; // eax
  mxPopupMenu *v106; // eax
  const char *v107; // eax
  mxPopupMenu *v108; // ebx
  char *v109; // eax
  const char *v110; // eax
  const char *v111; // eax
  const char *v112; // eax
  mxPopupMenu *v113; // eax
  mxPopupMenu *v114; // ebx
  const char *v115; // eax
  const char *v116; // eax
  int v117; // ebx
  bool v118; // bl
  mxPopupMenu *v119; // eax
  mxPopupMenu *v120; // ebx
  const char *v121; // eax
  const char *v122; // eax
  const char *v123; // eax
  const char *v124; // eax
  const char *v125; // eax
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  CChoreoEvent *CaptionClickedEvent; // eax
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // eax
  CChoreoChannelWidget *v129; // ecx
  CChoreoEvent *v130; // eax
  bool v131; // bl
  CChoreoEvent *v132; // eax
  int m_nUndoLevel; // eax
  const char *v134; // eax
  int v135; // eax
  const char *v136; // eax
  const char *Mapname; // eax
  const char *v138; // eax
  CChoreoActorWidget *v139; // ebx
  CChoreoActor *v140; // eax
  CChoreoActor *v141; // eax
  const char *v142; // eax
  CChoreoActor *v143; // eax
  const char *v144; // [esp-8h] [ebp-34h]
  const char *v145; // [esp-8h] [ebp-34h]
  const char *v146; // [esp-8h] [ebp-34h]
  const char *v147; // [esp-8h] [ebp-34h]
  const char *v148; // [esp-8h] [ebp-34h]
  const char *v149; // [esp-8h] [ebp-34h]
  const char *v150; // [esp-8h] [ebp-34h]
  const char *v151; // [esp-8h] [ebp-34h]
  const char *v152; // [esp-8h] [ebp-34h]
  const char *v153; // [esp-8h] [ebp-34h]
  const char *v154; // [esp-8h] [ebp-34h]
  const char *v155; // [esp-8h] [ebp-34h]
  CChoreoActor *v156; // [esp-8h] [ebp-34h]
  CChoreoActor *v157; // [esp-8h] [ebp-34h]
  int v158; // [esp-4h] [ebp-30h]
  int v159; // [esp-4h] [ebp-30h]
  int v160; // [esp-4h] [ebp-30h]
  int v161; // [esp-4h] [ebp-30h]
  int clickedCloseCaptionButton; // [esp+Ch] [ebp-20h] BYREF
  mxPopupMenu *exportMenu; // [esp+10h] [ebp-1Ch] BYREF
  int ct; // [esp+14h] [ebp-18h] BYREF
  CChoreoGlobalEventWidget *ge; // [esp+18h] [ebp-14h] BYREF
  CChoreoChannelWidget *c; // [esp+1Ch] [ebp-10h] BYREF
  CChoreoActorWidget *a; // [esp+20h] [ebp-Ch] BYREF
  CChoreoEventWidget *e; // [esp+24h] [ebp-8h] BYREF
  bool onmaster; // [esp+2Bh] [ebp-1h]

  a = nullptr;
  c = nullptr;
  e = nullptr;
  ge = nullptr;
  ct = -1;
  exportMenu = nullptr;
  clickedCloseCaptionButton = 0;
  CChoreoView::GetObjectsUnderMouse(
    this,
    mx,
    my,
    actor: &a,
    channel: &c,
    event: &e,
    globalevent: &ge,
    clickedTag: &ct,
    absolutetag: (CEventAbsoluteTag **)&exportMenu,
    clickedCCArea: &clickedCloseCaptionButton);
  v4 = c;
  v5 = e;
  this->m_pClickedActor = a;
  v6 = ge;
  this->m_pClickedChannel = v4;
  this->m_pClickedEvent = v5;
  v7 = ct;
  this->m_pClickedGlobalEvent = v6;
  v8 = (CEventAbsoluteTag *)exportMenu;
  this->m_nClickedX = mx;
  v9 = clickedCloseCaptionButton;
  this->m_nClickedY = my;
  this->m_nClickedTag = v7;
  this->m_pClickedAbsoluteTag = v8;
  this->m_nClickedChannelCloseCaptionButton = v9;
  v10 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v11 = mxPopupMenu::mxPopupMenu(this: v10);
  else
    v11 = nullptr;
  if ( a == nullptr || c == nullptr )
    goto LABEL_16;
  if ( e != nullptr )
  {
    Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)e);
    Name = CChoreoEvent::GetName(this: (CChoreoEvent *)Header);
    v14 = va(fmt: "Edit Event '%s'...", Name);
    mxPopupMenu::add(this: v11, item: v14, id: 5010);
    v15 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)e);
    Type = CChoreoEvent::GetType(this: (CChoreoEvent *)v15);
    if ( Type == GESTURE )
    {
      v158 = 5053;
      v19 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)e);
      v145 = CChoreoEvent::GetName(this: (CChoreoEvent *)v19);
      v18 = va(fmt: "Edit Event '%s' in gesture tool", v145);
    }
    else
    {
      if ( Type != FLEXANIMATION )
        goto LABEL_13;
      v158 = 5040;
      v17 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)e);
      v144 = CChoreoEvent::GetName(this: (CChoreoEvent *)v17);
      v18 = va(fmt: "Edit Event '%s' in expression tool", v144);
    }
    mxPopupMenu::add(this: v11, item: v18, id: v158);
LABEL_13:
    v20 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)e);
    if ( CChoreoEvent::CurveHasEndTime(this: (CChoreoEvent *)v20) )
      mxPopupMenu::add(this: v11, item: "Timing Tag...", id: 5034);
    goto LABEL_15;
  }
  mxPopupMenu::add(this: v11, item: "Expression...", id: 5012);
  mxPopupMenu::add(this: v11, item: "WAV File...", id: 5016);
  mxPopupMenu::add(this: v11, item: "Gesture...", id: 5013);
  mxPopupMenu::add(this: v11, item: "NULL Gesture...", id: 5068);
  mxPopupMenu::add(this: v11, item: "Look at actor...", id: 5014);
  mxPopupMenu::add(this: v11, item: "Move to actor...", id: 5015);
  mxPopupMenu::add(this: v11, item: "Face actor...", id: 5017);
  mxPopupMenu::add(this: v11, item: "Fire Trigger...", id: 5018);
  mxPopupMenu::add(this: v11, item: "Generic(AI)...", id: 5020);
  mxPopupMenu::add(this: v11, item: "Sequence...", id: 5019);
  mxPopupMenu::add(this: v11, item: "Flex animation...", id: 5042);
  mxPopupMenu::add(this: v11, item: "Sub-scene...", id: 5047);
  mxPopupMenu::add(this: v11, item: "Interrupt...", id: 5056);
  mxPopupMenu::add(this: v11, item: "Permit Responses...", id: 5079);
  mxPopupMenu::add(this: v11, item: "Camera...", id: 5093);
LABEL_15:
  mxMenu::addSeparator(this: v11);
LABEL_16:
  v21 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v21 != nullptr )
    v22 = mxPopupMenu::mxPopupMenu(this: v21);
  else
    v22 = nullptr;
  mxPopupMenu::add(this: v22, item: "Actor...", id: 5005);
  if ( a != nullptr )
    mxPopupMenu::add(this: v22, item: "Channel...", id: 5025);
  mxPopupMenu::add(this: v22, item: "Section Pause...", id: 5024);
  mxPopupMenu::add(this: v22, item: "Loop...", id: 5054);
  mxPopupMenu::add(this: v22, item: "Fire Completion...", id: 5067);
  mxMenu::addMenu(this: v11, item: "New", menu: v22);
  if ( a != nullptr || c != nullptr || e != nullptr || ge != nullptr )
  {
    v23 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v23 != nullptr )
      v24 = mxPopupMenu::mxPopupMenu(this: v23);
    else
      v24 = nullptr;
    if ( a != nullptr )
    {
      Actor = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)a);
      v26 = CChoreoActor::GetName(this: Actor);
      v27 = va(fmt: "Actor '%s'...", v26->m_szName);
      mxPopupMenu::add(this: v24, item: v27, id: 5009);
    }
    if ( c != nullptr )
    {
      v28 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)c);
      v29 = CChoreoChannel::GetName(this: (CChoreoChannel *)v28);
      v30 = va(fmt: "Channel '%s'...", v29);
      mxPopupMenu::add(this: v24, item: v30, id: 5026);
    }
    if ( ge != nullptr )
    {
      v31 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)ge);
      v32 = CChoreoEvent::GetType(this: v31) - 1;
      if ( v32 == 0 )
      {
        v37 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)ge);
        v148 = CChoreoEvent::GetName(this: v37);
        v35 = va(fmt: "Section Pause '%s'...", v148);
        goto LABEL_39;
      }
      v33 = v32 - 11;
      if ( v33 == 0 )
      {
        v36 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)ge);
        v147 = CChoreoEvent::GetName(this: v36);
        v35 = va(fmt: "Loop Point '%s'...", v147);
        goto LABEL_39;
      }
      if ( v33 == 2 )
      {
        v34 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)ge);
        v146 = CChoreoEvent::GetName(this: v34);
        v35 = va(fmt: "Fire Completion '%s'...", v146);
LABEL_39:
        mxPopupMenu::add(this: v24, item: v35, id: 5022);
      }
    }
    mxMenu::addMenu(this: v11, item: "Edit", menu: v24);
    if ( a != nullptr || c != nullptr )
    {
      v38 = (mxPopupMenu *)operator new(nSize: 0xCu);
      if ( v38 != nullptr )
        exportMenu = mxPopupMenu::mxPopupMenu(this: v38);
      else
        exportMenu = nullptr;
      v39 = (mxPopupMenu *)operator new(nSize: 0xCu);
      if ( v39 != nullptr )
        v40 = mxPopupMenu::mxPopupMenu(this: v39);
      else
        v40 = nullptr;
      if ( a != nullptr )
      {
        v41 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)a);
        v42 = CChoreoActor::GetName(this: v41);
        v43 = va(fmt: "Move '%s' up", v42->m_szName);
        mxPopupMenu::add(this: exportMenu, item: v43, id: 5007);
        v44 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)a);
        v45 = CChoreoActor::GetName(this: v44);
        v46 = va(fmt: "Move '%s' down", v45->m_szName);
        mxPopupMenu::add(this: v40, item: v46, id: 5008);
      }
      if ( c != nullptr )
      {
        v47 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)c);
        v48 = CChoreoChannel::GetName(this: (CChoreoChannel *)v47);
        v49 = va(fmt: "Move '%s' up", v48);
        mxPopupMenu::add(this: exportMenu, item: v49, id: 5028);
        v50 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)c);
        v51 = CChoreoChannel::GetName(this: (CChoreoChannel *)v50);
        v52 = va(fmt: "Move '%s' down", v51);
        mxPopupMenu::add(this: v40, item: v52, id: 5029);
      }
      mxMenu::addMenu(this: v11, item: "Move Up", menu: exportMenu);
      mxMenu::addMenu(this: v11, item: "Move Down", menu: v40);
      if ( a != nullptr || c != nullptr )
        goto LABEL_57;
    }
    if ( e != nullptr || ge != nullptr )
      goto LABEL_57;
  }
  if ( ct == -1 )
    goto LABEL_79;
LABEL_57:
  v53 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v53 != nullptr )
    v54 = mxPopupMenu::mxPopupMenu(this: v53);
  else
    v54 = nullptr;
  if ( a != nullptr )
  {
    v55 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)a);
    v56 = CChoreoActor::GetName(this: v55);
    v57 = va(fmt: "Actor '%s'", v56->m_szName);
    mxPopupMenu::add(this: v54, item: v57, id: 5006);
  }
  if ( c != nullptr )
  {
    v58 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)c);
    v59 = CChoreoChannel::GetName(this: (CChoreoChannel *)v58);
    v60 = va(fmt: "Channel '%s'", v59);
    mxPopupMenu::add(this: v54, item: v60, id: 5027);
  }
  if ( e != nullptr )
  {
    v61 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)e);
    v62 = CChoreoEvent::GetName(this: (CChoreoEvent *)v61);
    v63 = va(fmt: "Event '%s'", v62);
    mxPopupMenu::add(this: v54, item: v63, id: 5011);
  }
  if ( ge == nullptr )
    goto LABEL_74;
  v64 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)ge);
  v65 = CChoreoEvent::GetType(this: v64) - 1;
  if ( v65 != 0 )
  {
    v66 = v65 - 11;
    if ( v66 != 0 )
    {
      if ( v66 != 2 )
        goto LABEL_74;
      v67 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)ge);
      v149 = CChoreoEvent::GetName(this: v67);
      v68 = va(fmt: "Fire Completion '%s'...", v149);
    }
    else
    {
      v69 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)ge);
      v150 = CChoreoEvent::GetName(this: v69);
      v68 = va(fmt: "Loop Point '%s'...", v150);
    }
  }
  else
  {
    v70 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)ge);
    v151 = CChoreoEvent::GetName(this: v70);
    v68 = va(fmt: "Section Pause '%s'...", v151);
  }
  mxPopupMenu::add(this: v54, item: v68, id: 5023);
LABEL_74:
  if ( e != nullptr && ct != -1 )
  {
    v159 = ct;
    v71 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)e);
    RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: (CChoreoEvent *)v71, tagnum: v159);
    if ( RelativeTag != nullptr )
    {
      v73 = CEventAbsoluteTag::GetName(this: RelativeTag);
      v74 = va(fmt: "Relative Tag '%s'...", v73);
      mxPopupMenu::add(this: v54, item: v74, id: 5033);
    }
  }
  mxMenu::addMenu(this: v11, item: "Delete", menu: v54);
LABEL_79:
  v75 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v75 != nullptr )
    v76 = mxPopupMenu::mxPopupMenu(this: v75);
  else
    v76 = nullptr;
  mxPopupMenu::add(this: v76, item: "Select All", id: 5035);
  mxPopupMenu::add(this: v76, item: "Deselect All", id: 5036);
  mxMenu::addSeparator(this: v76);
  mxPopupMenu::add(this: v76, item: "All events before", id: 5069);
  mxPopupMenu::add(this: v76, item: "All events after", id: 5070);
  mxPopupMenu::add(this: v76, item: "Active events before", id: 5071);
  mxPopupMenu::add(this: v76, item: "Active events after", id: 5072);
  mxPopupMenu::add(this: v76, item: "Channel events before", id: 5073);
  mxPopupMenu::add(this: v76, item: "Channel events after", id: 5074);
  if ( a != nullptr || c != nullptr )
  {
    mxMenu::addSeparator(this: v76);
    if ( a != nullptr )
    {
      v77 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)a);
      v78 = CChoreoActor::GetName(this: v77);
      v79 = va(fmt: "All events in actor '%s'", v78->m_szName);
      mxPopupMenu::add(this: v76, item: v79, id: 5090);
    }
    if ( c != nullptr )
    {
      v80 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)c);
      v81 = CChoreoChannel::GetName(this: (CChoreoChannel *)v80);
      v82 = va(fmt: "All events in channel '%s'", v81);
      mxPopupMenu::add(this: v76, item: v82, id: 5089);
    }
  }
  mxMenu::addMenu(this: v11, item: "Select/Deselect", menu: v76);
  if ( e == nullptr )
  {
    v83 = nullptr;
    goto LABEL_101;
  }
  mxMenu::addSeparator(this: v11);
  v83 = e;
  v84 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)e);
  v85 = CChoreoEvent::GetType(this: (CChoreoEvent *)v84);
  if ( v85 == GESTURE )
  {
    v160 = 5053;
    v88 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
    v153 = CChoreoEvent::GetName(this: (CChoreoEvent *)v88);
    v87 = va(fmt: "Edit event '%s' in gesture tool", v153);
  }
  else
  {
    if ( v85 != FLEXANIMATION )
      goto LABEL_94;
    v160 = 5040;
    v86 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
    v152 = CChoreoEvent::GetName(this: (CChoreoEvent *)v86);
    v87 = va(fmt: "Edit event '%s' in expression tool", v152);
  }
  mxPopupMenu::add(this: v11, item: v87, id: v160);
LABEL_94:
  v89 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
  v90 = CChoreoEvent::GetName(this: (CChoreoEvent *)v89);
  v91 = va(fmt: "Move event '%s' to back", v90);
  mxPopupMenu::add(this: v11, item: v91, id: 5037);
  if ( CChoreoView::CountSelectedEvents(this) <= 1 )
  {
    v93 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
    v94 = CChoreoEvent::GetName(this: (CChoreoEvent *)v93);
    v95 = va(fmt: "Delete event '%s'", v94);
    mxPopupMenu::add(this: v11, item: v95, id: 5011);
    mxMenu::addSeparator(this: v11);
    v96 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
    if ( CChoreoEvent::GetActive(this: (CChoreoEvent *)v96) )
    {
      v161 = 5092;
      v97 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
      v154 = CChoreoEvent::GetName(this: (CChoreoEvent *)v97);
      v98 = va(fmt: "Disable event '%s'", v154);
    }
    else
    {
      v161 = 5091;
      v99 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
      v155 = CChoreoEvent::GetName(this: (CChoreoEvent *)v99);
      v98 = va(fmt: "Enable event '%s'", v155);
    }
    mxPopupMenu::add(this: v11, item: v98, id: v161);
  }
  else
  {
    v92 = va(fmt: "Delete events");
    mxPopupMenu::add(this: v11, item: v92, id: 5011);
    mxMenu::addSeparator(this: v11);
    mxPopupMenu::add(this: v11, item: "Enable events", id: 5091);
    mxPopupMenu::add(this: v11, item: "Disable events", id: 5092);
  }
LABEL_101:
  if ( this->m_rgABPoints[0].active && this->m_rgABPoints[1].active )
  {
    mxMenu::addSeparator(this: v11);
    v100 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v100 != nullptr )
      exportMenu = mxPopupMenu::mxPopupMenu(this: v100);
    else
      exportMenu = nullptr;
    mxPopupMenu::add(this: exportMenu, item: "Insert empty space between marks (shifts events right)", id: 5075);
    mxPopupMenu::add(this: exportMenu, item: "Delete events between marks (shifts remaining events left)", id: 5076);
    mxMenu::addMenu(this: v11, item: "Time Marks", menu: exportMenu);
  }
  if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: "scenes/copydatavcd.txt", a3: nullptr)
    || v83 != nullptr )
  {
    mxMenu::addSeparator(this: v11);
    if ( CChoreoView::CountSelectedEvents(this) <= 1 )
    {
      if ( v83 != nullptr )
      {
        v102 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
        v103 = CChoreoEvent::GetName(this: (CChoreoEvent *)v102);
        v104 = va(fmt: "Copy event '%s' to clipboard", v103);
        mxPopupMenu::add(this: v11, item: v104, id: 5043);
      }
    }
    else
    {
      v101 = va(fmt: "Copy events to clipboard");
      mxPopupMenu::add(this: v11, item: v101, id: 5043);
    }
    if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: "scenes/copydatavcd.txt", a3: nullptr) )
    {
      v105 = va(fmt: "Paste events");
      mxPopupMenu::add(this: v11, item: v105, id: 5044);
    }
  }
  mxMenu::addSeparator(this: v11);
  if ( v83 != nullptr )
  {
    v106 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v106 != nullptr )
      exportMenu = mxPopupMenu::mxPopupMenu(this: v106);
    else
      exportMenu = nullptr;
    if ( CChoreoView::CountSelectedEvents(this) <= 1 )
    {
      v109 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v83);
      v110 = CChoreoEvent::GetName(this: (CChoreoEvent *)v109);
      v111 = va(fmt: "Export event '%s' to .vce...", v110);
      mxPopupMenu::add(this: exportMenu, item: v111, id: 5046);
      v108 = exportMenu;
    }
    else
    {
      v107 = va(fmt: "Export events to .vce...");
      v108 = exportMenu;
      mxPopupMenu::add(this: exportMenu, item: v107, id: 5046);
    }
    v112 = va(fmt: "Export as .vcd...");
    mxPopupMenu::add(this: v108, item: v112, id: 5077);
    mxMenu::addMenu(this: v11, item: "Export", menu: v108);
  }
  v113 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v113 != nullptr )
    v114 = mxPopupMenu::mxPopupMenu(this: v113);
  else
    v114 = nullptr;
  v115 = va(fmt: "Import events from .vce...");
  mxPopupMenu::add(this: v114, item: v115, id: 5045);
  v116 = va(fmt: "Merge from .vcd...");
  mxPopupMenu::add(this: v114, item: v116, id: 5078);
  mxMenu::addMenu(this: v11, item: "Import", menu: v114);
  v117 = CChoreoView::CountSelectedEvents(this);
  v118 = CChoreoView::CountSelectedGlobalEvents(this) + v117 > 1;
  if ( e != nullptr && (CChoreoView::CountSelectedEvents(this) > 1 || v118) )
  {
    mxMenu::addSeparator(this: v11);
    v119 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v119 != nullptr )
      v120 = mxPopupMenu::mxPopupMenu(this: v119);
    else
      v120 = nullptr;
    mxPopupMenu::add(this: v120, item: "Align Left", id: 5085);
    if ( CChoreoView::CountSelectedEvents(this) > 1 )
    {
      mxPopupMenu::add(this: v120, item: "Align Right", id: 5086);
      mxPopupMenu::add(this: v120, item: "Size to Smallest", id: 5087);
      mxPopupMenu::add(this: v120, item: "Size to Largest", id: 5088);
    }
    mxMenu::addMenu(this: v11, item: "Align", menu: v120);
  }
  mxMenu::addSeparator(this: v11);
  v121 = va(fmt: "Change scale...");
  mxPopupMenu::add(this: v11, item: v121, id: 5021);
  v122 = va(fmt: "Check sequences");
  mxPopupMenu::add(this: v11, item: v122, id: 5051);
  v123 = va(fmt: "Process sequences");
  mxPopupMenu::add(this: v11, item: v123, id: 5052);
  v124 = "Ramp normal";
  if ( !this->m_bRampOnly )
    v124 = "Ramp only";
  v125 = va(fmt: v124);
  mxPopupMenu::add(this: v11, item: v125, id: 5055);
  mxMenu::setChecked(this: v11, id: 5052, b: this->m_bProcessSequences);
  m_pClickedChannel = this->m_pClickedChannel;
  if ( m_pClickedChannel == nullptr
    || CChoreoChannelWidget::GetCaptionClickedEvent(this: m_pClickedChannel) == nullptr
    || (CaptionClickedEvent = CChoreoChannelWidget::GetCaptionClickedEvent(this: this->m_pClickedChannel),
        CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: CaptionClickedEvent),
        onmaster = true,
        CloseCaptionType != CC_MASTER) )
  {
    onmaster = false;
  }
  v129 = this->m_pClickedChannel;
  v131 = false;
  if ( v129 != nullptr && CChoreoChannelWidget::GetCaptionClickedEvent(this: v129) != nullptr )
  {
    v130 = CChoreoChannelWidget::GetCaptionClickedEvent(this: this->m_pClickedChannel);
    if ( CChoreoEvent::GetCloseCaptionType(this: v130) == CC_DISABLED )
      v131 = true;
  }
  if ( this->m_bShowCloseCaptionData
    && (CChoreoView::AreSelectedEventsCombinable(this)
     || CChoreoView::AreSelectedEventsInSpeakGroup(this) != 0
     || onmaster
     || v131) )
  {
    mxMenu::addSeparator(this: v11);
    if ( CChoreoView::AreSelectedEventsCombinable(this) )
      mxPopupMenu::add(this: v11, item: "Combine Speak Events", id: 5081);
    if ( CChoreoView::AreSelectedEventsInSpeakGroup(this) != 0 )
      mxPopupMenu::add(this: v11, item: "Uncombine Speak Events", id: 5082);
    if ( onmaster )
    {
      v132 = CChoreoChannelWidget::GetCaptionClickedEvent(this: this->m_pClickedChannel);
      if ( CChoreoEvent::GetNumSlaves(this: v132) >= 1 )
        mxPopupMenu::add(this: v11, item: "Change Token", id: 5083);
      mxPopupMenu::add(this: v11, item: "Disable captions", id: 5084);
    }
    if ( v131 )
      mxPopupMenu::add(this: v11, item: "Enable captions", id: 5084);
  }
  if ( this->m_nUndoLevel != 0 || this->m_UndoStack.m_Size != 0 )
  {
    mxMenu::addSeparator(this: v11);
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel != 0 )
    {
      v134 = va(fmt: "Undo %s", this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel - 1]->udescription);
      mxPopupMenu::add(this: v11, item: v134, id: 1025);
    }
    v135 = this->m_nUndoLevel;
    if ( v135 != this->m_UndoStack.m_Size )
    {
      v136 = va(fmt: "Redo %s", this->m_UndoStack.m_Memory.m_pMemory[v135]->rdescription);
      mxPopupMenu::add(this: v11, item: v136, id: 1026);
    }
  }
  if ( this->m_pScene != nullptr )
  {
    mxMenu::addSeparator(this: v11);
    Mapname = CChoreoScene::GetMapname(this: this->m_pScene);
    v138 = va(fmt: "Associate .bsp (%s)", Mapname);
    mxPopupMenu::add(this: v11, item: v138, id: 5041);
    v139 = a;
    if ( a != nullptr )
    {
      if ( CActorBitmapButton::GetActor(this: (TimelineItem *)a) != 0
        && (v140 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)v139),
            *CChoreoActor::GetFacePoserModelName(this: v140) != 0) )
      {
        v141 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)v139);
        v156 = CChoreoActor::GetName(this: v141);
        v142 = va(fmt: "Change .mdl for %s", v156);
      }
      else
      {
        v143 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)v139);
        v157 = CChoreoActor::GetName(this: v143);
        v142 = va(fmt: "Associate .mdl with %s", v157);
      }
      mxPopupMenu::add(this: v11, item: v142, id: 5049);
    }
  }
  mxPopupMenu::popup(this: v11, widget: this, x: mx, y: my);
}

//------------------------------------------------------------------------------
// Address: 0x00432030
// Name: public: void CChoreoView::AssociateModelToActor(class CChoreoActor __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::AssociateModelToActor(CChoreoView *this, CChoreoActor *actor, int modelindex)
{
  bool v4; // al
  const char *v5; // [esp-4h] [ebp-Ch]

  v4 = !this->m_bDirty;
  this->m_bDirty = true;
  if ( v4 )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  CChoreoView::PushUndo(this, description: "Associate model");
  if ( modelindex < 0 || modelindex >= models->Count(this: models) )
  {
    CChoreoActor::SetFacePoserModelName(this: actor, name: defaultValue);
  }
  else
  {
    v5 = models->GetModelFileName(this: models, a2: modelindex);
    CChoreoActor::SetFacePoserModelName(this: actor, name: v5);
  }
  CChoreoView::RecomputeWaves(this);
  CChoreoView::PushRedo(this, description: "Associate model");
}

//------------------------------------------------------------------------------
// Address: 0x004320C0
// Name: public: void CChoreoView::OnDoubleClicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnDoubleClicked(CChoreoView *this)
{
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  int m_nClickedChannelCloseCaptionButton; // eax
  CChoreoEvent *CaptionClickedEvent; // eax
  CChoreoEvent *v5; // edi
  bool m_bDirty; // zf
  char *Header; // eax
  char *v8; // eax
  CChoreoActor *Actor; // eax
  CChoreoActor *v10; // eax
  bool v11; // [esp-4h] [ebp-8h]
  bool v12; // [esp-4h] [ebp-8h]

  m_pClickedChannel = this->m_pClickedChannel;
  if ( m_pClickedChannel != nullptr )
  {
    m_nClickedChannelCloseCaptionButton = this->m_nClickedChannelCloseCaptionButton;
    if ( m_nClickedChannelCloseCaptionButton != 0 )
    {
      if ( m_nClickedChannelCloseCaptionButton == 5 )
      {
        CaptionClickedEvent = CChoreoChannelWidget::GetCaptionClickedEvent(this: m_pClickedChannel);
        v5 = CaptionClickedEvent;
        if ( CaptionClickedEvent != nullptr && CChoreoEvent::GetNumSlaves(this: CaptionClickedEvent) >= 1 )
          CChoreoView::OnChangeCloseCaptionToken(this, e: v5);
      }
    }
    else
    {
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Enable/disable Channel");
      Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedChannel);
      v11 = !CChoreoChannel::GetActive(this: (CChoreoChannel *)Header);
      v8 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedChannel);
      CChoreoChannel::SetActive(this: (CChoreoChannel *)v8, active: v11);
      CChoreoView::PushRedo(this, description: "Enable/disable Channel");
    }
  }
  else if ( this->m_pClickedActor != nullptr )
  {
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    CChoreoView::PushUndo(this, description: "Enable/disable Actor");
    Actor = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)this->m_pClickedActor);
    v12 = !CChoreoActor::GetActive(this: Actor);
    v10 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)this->m_pClickedActor);
    CChoreoActor::SetActive(this: v10, active: v12);
    CChoreoView::PushRedo(this, description: "Enable/disable Actor");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004321E0
// Name: private: void CChoreoView::FinishDraggingSceneEndTime(class mxEvent __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::FinishDraggingSceneEndTime(CChoreoView *this, mxEvent *event, CChoreoEvent *mx, int my)
{
  CChoreoView *v4; // esi
  int v5; // ebx
  bool m_bDirty; // zf
  CChoreoActorWidget *v7; // edi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v9; // ebx
  char *v10; // edi
  CAudioSourceWave *v11; // eax
  char *Header; // esi
  char *v13; // edi
  CAudioSourceWave *v14; // eax
  CChoreoEvent *v15; // esi
  char *v16; // eax
  CChoreoEvent::EVENTTYPE Type; // eax
  HCURSOR m_hPrevCursor; // eax
  CChoreoScene *m_pScene; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  float StartTime; // [esp+4h] [ebp-48h]
  float newstart; // [esp+8h] [ebp-44h]
  float newstarta; // [esp+8h] [ebp-44h]
  int newend; // [esp+Ch] [ebp-40h]
  float newenda; // [esp+Ch] [ebp-40h]
  float scene_dt; // [esp+2Ch] [ebp-20h]
  float newduration; // [esp+30h] [ebp-1Ch]
  float newdurationa; // [esp+30h] [ebp-1Ch]
  int i; // [esp+34h] [ebp-18h]
  CChoreoActorWidget *a; // [esp+38h] [ebp-14h]
  int j; // [esp+3Ch] [ebp-10h]
  float dt; // [esp+44h] [ebp-8h]
  float newendtime; // [esp+48h] [ebp-4h]
  CChoreoEvent *finalGesture; // [esp+58h] [ebp+Ch]

  v4 = this;
  CChoreoView::DrawFocusRect(this);
  v5 = 0;
  v4->m_FocusRects.m_Size = 0;
  if ( v4->m_FocusRects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4->m_FocusRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_FocusRects.m_Memory.m_pMemory);
      v4->m_FocusRects.m_Memory.m_pMemory = nullptr;
    }
    v4->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  }
  v4->m_FocusRects.m_pElements = v4->m_FocusRects.m_Memory.m_pMemory;
  newend = v4->m_xStart;
  v4->m_bDragging = false;
  if ( CChoreoView::GetTimeDeltaForMouseDelta(this: v4, (int)mx, origmx: newend) != 0.0 )
  {
    m_bDirty = v4->m_bDirty;
    v4->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &v4->IFacePoserToolWindow, prefix: "* ");
    CChoreoView::PushUndo(this: v4, description: "Change Scene Duration");
    newendtime = (float)((float)((float)((int)mx - v4->m_nLabelWidth)
                               / (float)(v4->m_rcTimeLine.right - v4->m_nLabelWidth))
                       * (float)(v4->m_flEndTime - v4->m_flStartTime))
               + v4->m_flStartTime;
    i = 0;
    scene_dt = newendtime - CChoreoScene::FindStopTime(this: v4->m_pScene);
    if ( v4->m_SceneActors.m_Size > 0 )
    {
      do
      {
        v7 = v4->m_SceneActors.m_Memory.m_pMemory[v5];
        a = v7;
        if ( v7 != nullptr )
        {
          j = 0;
          if ( CChoreoWidgetDrawHelper::GetHeight(this: v7) > 0 )
          {
            do
            {
              Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v7, num: j);
              v9 = (CChoreoChannelWidget *)Channel;
              if ( Channel != nullptr )
              {
                finalGesture = nullptr;
                v10 = (char *)&CAudioMixerWave::GetChannel(this: Channel)[-1].pitch + 3;
                if ( (int)v10 >= 0 )
                {
                  do
                  {
                    v11 = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v9, num: (int)v10);
                    Header = CAudioSourceWave::GetHeader(this: v11);
                    if ( CChoreoEvent::GetType(this: (CChoreoEvent *)Header) == GESTURE
                      && (finalGesture == nullptr
                       || (double)(newduration = CChoreoEvent::GetStartTime(this: (CChoreoEvent *)Header)) > CChoreoEvent::GetStartTime(this: finalGesture)) )
                    {
                      finalGesture = (CChoreoEvent *)Header;
                    }
                    --v10;
                  }
                  while ( (int)v10 >= 0 );
                  v4 = this;
                }
                v13 = (char *)&CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v9)[-1].pitch + 3;
                if ( (int)v13 >= 0 )
                {
                  do
                  {
                    v14 = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v9, num: (int)v13);
                    v15 = (CChoreoEvent *)CAudioSourceWave::GetHeader(this: v14);
                    if ( CChoreoEvent::GetStartTime(this: v15) <= (double)newendtime )
                    {
                      if ( (double)newendtime <= CChoreoEvent::GetEndTime(this: v15) || v15 == finalGesture )
                      {
                        dt = scene_dt;
                        if ( CChoreoEvent::GetType(this: v15) == GESTURE
                          && (double)newendtime > CChoreoEvent::GetEndTime(this: v15) )
                        {
                          dt = newendtime - CChoreoEvent::GetEndTime(this: v15);
                        }
                        newdurationa = ((double (__thiscall *)(CChoreoEvent *))v15->GetDuration)(a1: v15) + dt;
                        RescaleRamp(event: v15, newduration: newdurationa);
                        Type = CChoreoEvent::GetType(this: v15);
                        if ( Type == GESTURE )
                        {
                          newstarta = CChoreoEvent::GetEndTime(this: v15) + dt;
                          StartTime = CChoreoEvent::GetStartTime(this: v15);
                          CChoreoEvent::RescaleGestureTimes(
                            this: v15,
                            newstart: StartTime,
                            newend: newstarta,
                            bMaintainAbsoluteTagPositions: true);
                        }
                        else if ( Type == FLEXANIMATION )
                        {
                          newenda = CChoreoEvent::GetEndTime(this: v15) + dt;
                          newstart = CChoreoEvent::GetStartTime(this: v15);
                          RescaleExpressionTimes(event: v15, newstart, newend: newenda);
                        }
                        CChoreoEvent::OffsetEndTime(this: v15, dt);
                        CChoreoEvent::SnapTimes(this: v15);
                        CCurveData::Resort(this: &v15->m_Ramp, data: v15);
                      }
                    }
                    else
                    {
                      v16 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v9);
                      CChoreoChannel::RemoveEvent(this: (CChoreoChannel *)v16, event: v15);
                      CChoreoScene::DeleteReferencedObjects(this: this->m_pScene, event: v15);
                    }
                    --v13;
                  }
                  while ( (int)v13 >= 0 );
                  v4 = this;
                }
                v7 = a;
              }
              ++j;
            }
            while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v7) );
            v5 = i;
          }
        }
        i = ++v5;
      }
      while ( v5 < v4->m_SceneActors.m_Size );
    }
    CChoreoView::DeleteSceneWidgets(this: v4);
    m_hPrevCursor = v4->m_hPrevCursor;
    v4->m_nDragType = 0;
    if ( m_hPrevCursor != nullptr )
    {
      SetCursor(hCursor: m_hPrevCursor);
      v4->m_hPrevCursor = nullptr;
    }
    CChoreoView::PushRedo(this: v4, description: "Change Scene Duration");
    CChoreoView::CreateSceneWidgets(this: v4);
    if ( !v4->m_bSuppressLayout )
    {
      if ( CChoreoView::ComputeHPixelsNeeded(this: v4) != v4->m_nLastHPixelsNeeded )
        CChoreoView::RepositionHSlider(this: v4);
      if ( CChoreoView::ComputeVPixelsNeeded(this: v4) != v4->m_nLastVPixelsNeeded )
        CChoreoView::RepositionVSlider(this: v4);
      m_pScene = v4->m_pScene;
      if ( m_pScene != nullptr )
      {
        CChoreoScene::ReconcileGestureTimes(this: m_pScene);
        CChoreoScene::ReconcileCloseCaption(this: v4->m_pScene);
      }
      redraw = v4->redraw;
      v4->m_bLayoutIsValid = false;
      redraw(this: v4);
    }
    ExpressionTool::LayoutItems(this: g_pExpressionTool, force: true);
    g_pExpressionTool->redraw(this: g_pExpressionTool);
    g_pGestureTool->redraw(this: g_pGestureTool);
    g_pRampTool->redraw(this: g_pRampTool);
    g_pSceneRampTool->redraw(this: g_pSceneRampTool);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432610
// Name: public: void CChoreoView::FinishDraggingEvent(class mxEvent __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::FinishDraggingEvent(CChoreoView *this, mxEvent *event, int mx, CChoreoChannelWidget *my)
{
  double TimeDeltaForMouseDelta; // st7
  CChoreoEventWidget *m_pClickedEvent; // ecx
  char *Header; // eax
  char *v8; // eax
  const char *v9; // eax
  CChoreoEventWidget *v10; // ecx
  char *v11; // esi
  const char *v12; // eax
  char *v13; // eax
  const char *Name; // eax
  bool m_bDirty; // zf
  const char *v16; // eax
  int v17; // esi
  CChoreoActorWidget *v18; // ecx
  CChoreoChannelWidget *Channel; // eax
  CAudioSourceWave *v20; // edi
  CChoreoEvent *v21; // esi
  double v22; // st7
  CChoreoEvent::EVENTTYPE Type; // eax
  double v24; // st7
  double StartTime; // st7
  double v26; // st7
  CChoreoEvent::EVENTTYPE v27; // eax
  double v28; // st7
  double EndTime; // st7
  int m_Size; // eax
  int v31; // edi
  int v32; // eax
  CChoreoEvent **v33; // eax
  int (__thiscall *GetOutputData)(struct CAudioSourceWave *, void **, int, int, bool); // edx
  int left; // edi
  double Percentage; // st7
  int v37; // eax
  int (__thiscall *v38)(struct CAudioSourceWave *, void **, int, int, bool); // eax
  __int64 *v39; // eax
  double v40; // st7
  __int32 v41; // eax
  __int32 v42; // eax
  IFacePoserSound_vtbl *v43; // edi
  const char *v44; // eax
  char *v45; // eax
  int v46; // edi
  double v47; // st7
  int v48; // esi
  int v49; // esi
  int v50; // esi
  CChoreoEvent *v51; // edi
  float v52; // xmm0_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  int v55; // edi
  CChoreoEvent *v56; // esi
  double v57; // st7
  CChoreoEvent_vtbl *v58; // edx
  float (__thiscall *GetDuration)(struct CChoreoEvent *); // eax
  float v60; // xmm0_4
  float v61; // xmm0_4
  CChoreoEvent::EVENTTYPE v62; // eax
  int m_nDragType; // eax
  bool v64; // al
  int i; // edi
  CChoreoGlobalEventWidget **m_pMemory; // ecx
  TimelineItem *v67; // esi
  CChoreoEvent *Actor; // eax
  CChoreoEvent *v69; // esi
  HICON__ *m_hPrevCursor; // eax
  CChoreoEventWidget *v71; // ecx
  unsigned int m_yStart; // edi
  int v73; // esi
  CChoreoActorWidget *ChannelUnderCursorPos; // eax
  CChoreoScene *m_pScene; // ecx
  int v76; // eax
  double StopTime; // st7
  const char *v78; // eax
  CChoreoScene *v79; // ecx
  int TimeZoom; // eax
  int v81; // esi
  int j; // edi
  CChoreoActorWidget *v83; // ecx
  CChoreoScene *v84; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  char *v87; // edi
  char *v88; // esi
  CChoreoEvent *v89; // edi
  CChoreoActor *v90; // eax
  CChoreoEvent *v91; // esi
  const char *v92; // eax
  const char *v93; // eax
  CChoreoScene *v94; // ecx
  int v95; // eax
  double v96; // st7
  const char *v97; // eax
  CChoreoScene *v98; // ecx
  int v99; // eax
  int v100; // esi
  int k; // edi
  CChoreoActorWidget *v102; // ecx
  CChoreoScene *v103; // ecx
  void (__thiscall *v104)(struct CChoreoView *); // eax
  CChoreoEvent *v105; // esi
  CChoreoEvent::EVENTTYPE v106; // eax
  float v107; // [esp+Ch] [ebp-27Ch]
  float v108; // [esp+Ch] [ebp-27Ch]
  float newstart; // [esp+10h] [ebp-278h]
  float newstarta; // [esp+10h] [ebp-278h]
  float newstartb; // [esp+10h] [ebp-278h]
  float newstartc; // [esp+10h] [ebp-278h]
  int newduration; // [esp+14h] [ebp-274h]
  float newdurationa; // [esp+14h] [ebp-274h]
  bool newdurationb; // [esp+14h] [ebp-274h]
  float newdurationc; // [esp+14h] [ebp-274h]
  bool newdurationd; // [esp+14h] [ebp-274h]
  float newduratione; // [esp+14h] [ebp-274h]
  char sndname[512]; // [esp+24h] [ebp-264h] BYREF
  tagRECT bounds; // [esp+224h] [ebp-64h]
  __int64 v121; // [esp+234h] [ebp-54h]
  __int64 v122; // [esp+23Ch] [ebp-4Ch]
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > rescaleHelper; // [esp+244h] [ebp-44h] BYREF
  float et; // [esp+258h] [ebp-30h]
  float flTimeFromStart; // [esp+25Ch] [ebp-2Ch]
  const char *desc; // [esp+260h] [ebp-28h]
  float flEnd; // [esp+264h] [ebp-24h]
  float flNewDuration; // [esp+268h] [ebp-20h]
  float flScale; // [esp+26Ch] [ebp-1Ch]
  float flStart; // [esp+270h] [ebp-18h]
  float flDuration; // [esp+274h] [ebp-14h]
  float st; // [esp+278h] [ebp-10h]
  int flNewEndTime; // [esp+27Ch] [ebp-Ch]
  float dt; // [esp+280h] [ebp-8h]
  float flNewStartTime; // [esp+284h] [ebp-4h]
  float mxa; // [esp+294h] [ebp+Ch]
  float mxb; // [esp+294h] [ebp+Ch]
  CChoreoChannelWidget *chNew; // [esp+298h] [ebp+10h]

  CChoreoView::DrawFocusRect(this);
  this->m_FocusRects.m_Size = 0;
  if ( this->m_FocusRects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
      this->m_FocusRects.m_Memory.m_pMemory = nullptr;
    }
    this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
  newduration = this->m_xStart;
  this->m_bDragging = false;
  TimeDeltaForMouseDelta = CChoreoView::GetTimeDeltaForMouseDelta(this, mx, origmx: newduration);
  dt = TimeDeltaForMouseDelta;
  if ( TimeDeltaForMouseDelta == 0.0 )
  {
    if ( this->m_pScene != nullptr )
    {
      m_pClickedEvent = this->m_pClickedEvent;
      if ( m_pClickedEvent != nullptr )
      {
        Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)m_pClickedEvent);
        if ( CChoreoEvent::GetType(this: (CChoreoEvent *)Header) == SPEAK )
        {
          v8 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedEvent);
          v9 = FacePoser_TranslateSoundName(event: (CChoreoEvent *)v8);
          V_strncpy(pDest: sndname, pSrc: v9, maxLen: 512);
          v10 = this->m_pClickedEvent;
          if ( sndname[0] != 0 )
          {
            v11 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v10);
            v12 = va(fmt: "sound/%s", sndname);
            PhonemeEditor::SetCurrentWaveFile(
              this: g_pPhonemeEditor,
              wavefile: v12,
              force: false,
              event: (CChoreoEvent *)v11);
          }
          else
          {
            v13 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v10);
            Name = CChoreoEvent::GetName(this: (CChoreoEvent *)v13);
            _Warning(a1: "Unable to resolve sound name for '%s', check actor associations\n", Name);
          }
        }
      }
    }
    return;
  }
  m_bDirty = this->m_bDirty;
  this->m_bDirty = true;
  if ( !m_bDirty )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  switch ( this->m_nDragType )
  {
    case 2:
    case 3:
      v16 = "Change Start Time";
      break;
    case 4:
    case 5:
      v16 = "Change End Time";
      break;
    case 6:
      v16 = "Move Event Tag";
      break;
    case 7:
      v16 = "Move Abs Event Tag";
      break;
    case 0xA:
    case 0xB:
      v16 = "Rescale Time";
      break;
    default:
      v16 = "Event Move";
      break;
  }
  desc = v16;
  CChoreoView::PushUndo(this, description: v16);
  v17 = 0;
  memset(&rescaleHelper, 0, sizeof(rescaleHelper));
  flNewStartTime = 0.0;
  if ( this->m_SceneActors.m_Size > 0 )
  {
    do
    {
      v18 = this->m_SceneActors.m_Memory.m_pMemory[v17];
      flEnd = *(float *)&v18;
      if ( v18 != nullptr )
      {
        flStart = 0.0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: v18) > 0 )
        {
          do
          {
            Channel = CChoreoActorWidget::GetChannel(this: (CChoreoActorWidget *)LODWORD(flEnd), num: SLODWORD(flStart));
            flScale = *(float *)&Channel;
            if ( Channel != nullptr )
            {
              flNewDuration = 0.0;
              if ( (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)Channel) > 0 )
              {
                do
                {
                  v20 = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(
                                              this: (CChoreoChannelWidget *)LODWORD(flScale),
                                              num: SLODWORD(flNewDuration));
                  if ( v20 != nullptr && v20->IsLooped(this: v20) )
                  {
                    v21 = (CChoreoEvent *)CAudioSourceWave::GetHeader(this: v20);
                    if ( v21 != nullptr )
                    {
                      switch ( this->m_nDragType )
                      {
                        case 2:
                        case 3:
                          v22 = ((double (__thiscall *)(CChoreoEvent *))v21->GetDuration)(a1: v21);
                          *(float *)&flNewEndTime = v22 - dt;
                          RescaleRamp(event: v21, newduration: *(float *)&flNewEndTime);
                          Type = CChoreoEvent::GetType(this: v21);
                          if ( Type == GESTURE )
                          {
                            newdurationb = this->m_nDragType == 2;
                            newstarta = CChoreoEvent::GetEndTime(this: v21);
                            StartTime = CChoreoEvent::GetStartTime(this: v21);
                            v107 = StartTime + dt;
                            CChoreoEvent::RescaleGestureTimes(
                              this: v21,
                              newstart: v107,
                              newend: newstarta,
                              bMaintainAbsoluteTagPositions: newdurationb);
                          }
                          else if ( Type == FLEXANIMATION )
                          {
                            newdurationa = CChoreoEvent::GetEndTime(this: v21);
                            v24 = CChoreoEvent::GetStartTime(this: v21);
                            newstart = v24 + dt;
                            RescaleExpressionTimes(event: v21, newstart, newend: newdurationa);
                          }
                          CChoreoEvent::OffsetStartTime(this: v21, dt);
                          goto LABEL_35;
                        case 4:
                        case 5:
                          v26 = ((double (__thiscall *)(CChoreoEvent *))v21->GetDuration)(a1: v21);
                          *(float *)&flNewEndTime = v26 + dt;
                          RescaleRamp(event: v21, newduration: *(float *)&flNewEndTime);
                          v27 = CChoreoEvent::GetType(this: v21);
                          if ( v27 == GESTURE )
                          {
                            newdurationd = this->m_nDragType == 4;
                            EndTime = CChoreoEvent::GetEndTime(this: v21);
                            newstartc = EndTime + dt;
                            v108 = CChoreoEvent::GetStartTime(this: v21);
                            CChoreoEvent::RescaleGestureTimes(
                              this: v21,
                              newstart: v108,
                              newend: newstartc,
                              bMaintainAbsoluteTagPositions: newdurationd);
                          }
                          else if ( v27 == FLEXANIMATION )
                          {
                            v28 = CChoreoEvent::GetEndTime(this: v21);
                            newdurationc = v28 + dt;
                            newstartb = CChoreoEvent::GetStartTime(this: v21);
                            RescaleExpressionTimes(event: v21, newstart: newstartb, newend: newdurationc);
                          }
                          CChoreoEvent::OffsetEndTime(this: v21, dt);
LABEL_35:
                          CChoreoEvent::SnapTimes(this: v21);
                          CCurveData::Resort(this: &v21->m_Ramp, data: v21);
                          goto LABEL_63;
                        case 6:
                          if ( this->m_nClickedTag == -1 )
                            goto LABEL_63;
                          flDuration = COERCE_FLOAT(CChoreoEvent::GetRelativeTag(this: v21, tagnum: this->m_nClickedTag));
                          if ( flDuration == 0.0 )
                            goto LABEL_63;
                          GetOutputData = v20->__vftable[1].GetOutputData;
                          et = (float)(mx - this->m_xStart);
                          bounds = *(tagRECT *)((int (__thiscall *)(CAudioSourceWave *))GetOutputData)(a1: v20);
                          left = bounds.left;
                          flNewEndTime = bounds.right - bounds.left;
                          if ( bounds.right - bounds.left <= 0 )
                            goto LABEL_63;
                          st = (float)flNewEndTime;
                          Percentage = CEventAbsoluteTag::GetPercentage(this: (CEventAbsoluteTag *)LODWORD(flDuration));
                          v37 = (int)(float)((float)(bounds.left + (int)(Percentage * st + 0.5)) + et);
                          if ( v37 >= bounds.left )
                          {
                            if ( v37 >= bounds.right )
                              v37 = bounds.right - 1;
                          }
                          else
                          {
                            v37 = bounds.left;
                          }
                          break;
                        case 7:
                          flDuration = *(float *)&this->m_pClickedAbsoluteTag;
                          if ( flDuration == 0.0 )
                            goto LABEL_63;
                          v38 = v20->__vftable[1].GetOutputData;
                          flTimeFromStart = (float)(mx - this->m_xStart);
                          v39 = (__int64 *)((int (__thiscall *)(CAudioSourceWave *))v38)(a1: v20);
                          v121 = *v39;
                          left = v121;
                          v122 = v39[1];
                          flNewEndTime = v122 - v121;
                          if ( (int)v122 - (int)v121 <= 0 )
                            goto LABEL_63;
                          st = (float)flNewEndTime;
                          v40 = CEventAbsoluteTag::GetPercentage(this: (CEventAbsoluteTag *)LODWORD(flDuration));
                          v37 = (int)(float)((float)(v121 + (int)(v40 * st + 0.5)) + flTimeFromStart);
                          if ( v37 >= (int)v121 )
                          {
                            if ( v37 >= (int)v122 )
                              v37 = v122 - 1;
                          }
                          else
                          {
                            v37 = v121;
                          }
                          break;
                        case 0xA:
                        case 0xB:
                          m_Size = rescaleHelper.m_Size;
                          v31 = rescaleHelper.m_Size;
                          if ( rescaleHelper.m_Size + 1 > rescaleHelper.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&rescaleHelper,
                              num: rescaleHelper.m_Size - rescaleHelper.m_Memory.m_nAllocationCount + 1);
                            m_Size = rescaleHelper.m_Size;
                          }
                          rescaleHelper.m_Size = m_Size + 1;
                          v32 = m_Size - v31;
                          rescaleHelper.m_pElements = rescaleHelper.m_Memory.m_pMemory;
                          if ( v32 > 0 )
                            _V_memmove(
                              dest: &rescaleHelper.m_Memory.m_pMemory[v31 + 1],
                              src: &rescaleHelper.m_Memory.m_pMemory[v31],
                              count: 4 * v32);
                          v33 = &rescaleHelper.m_Memory.m_pMemory[v31];
                          if ( v33 != nullptr )
                            *v33 = v21;
                          goto LABEL_63;
                        default:
                          CChoreoEvent::OffsetTime(this: v21, dt);
                          CChoreoEvent::SnapTimes(this: v21);
                          goto LABEL_63;
                      }
                      CEventAbsoluteTag::SetPercentage(
                        this: (CEventAbsoluteTag *)LODWORD(flDuration),
                        percentage: (float)(v37 - left) / st);
                    }
LABEL_63:
                    v41 = CChoreoEvent::GetType(this: v21) - 5;
                    if ( v41 != 0 )
                    {
                      v42 = v41 - 1;
                      if ( v42 != 0 )
                      {
                        if ( v42 == 1 )
                          CChoreoView::CheckSequenceLength(this, e: v21, bCheckOnly: false);
                      }
                      else
                      {
                        CChoreoView::CheckGestureLength(this, e: v21, bCheckOnly: false);
                      }
                    }
                    else
                    {
                      v43 = sound->__vftable;
                      v44 = FacePoser_TranslateSoundName(event: v21);
                      v45 = va(fmt: "sound/%s", v44);
                      v46 = (int)v43->LoadSound(this: sound, a2: v45);
                      if ( v46 != 0 )
                      {
                        *(float *)&flNewEndTime = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v46 + 36))(a1: v46);
                        v47 = CChoreoEvent::GetStartTime(this: v21);
                        newduratione = v47 + *(float *)&flNewEndTime;
                        CChoreoEvent::SetEndTime(this: v21, endtime: newduratione);
                        (**(void (__thiscall ***)(int, int))v46)(a1: v46, a2: 1);
                      }
                    }
                  }
                  v48 = ++LODWORD(flNewDuration);
                }
                while ( v48 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)LODWORD(flScale)) );
              }
            }
            v49 = ++LODWORD(flStart);
          }
          while ( v49 < CChoreoWidgetDrawHelper::GetHeight(this: (CChoreoActorWidget *)LODWORD(flEnd)) );
          v17 = LODWORD(flNewStartTime);
        }
      }
      ++v17;
      flNewStartTime = *(float *)&v17;
    }
    while ( v17 < this->m_SceneActors.m_Size );
    if ( rescaleHelper.m_Size > 0 )
    {
      flStart = 3.4028235e38;
      v50 = 0;
      flEnd = 1.1754944e-38;
      do
      {
        v51 = rescaleHelper.m_Memory.m_pMemory[v50];
        st = CChoreoEvent::GetStartTime(this: v51);
        flTimeFromStart = CChoreoEvent::GetEndTime(this: v51);
        if ( flStart > (double)st )
          flStart = st;
        v52 = flEnd;
        if ( flTimeFromStart > flEnd )
        {
          v52 = flTimeFromStart;
          flEnd = flTimeFromStart;
        }
        ++v50;
      }
      while ( v50 < rescaleHelper.m_Size );
      v53 = v52 - flStart;
      if ( v53 > 0.0 )
      {
        if ( this->m_nDragType == 10 )
          v54 = v53 - dt;
        else
          v54 = v53 + dt;
        if ( v54 < 0.1 )
          v54 = 0.1;
        v55 = 0;
        for ( flScale = v54 / v53; v55 < rescaleHelper.m_Size; ++v55 )
        {
          v56 = rescaleHelper.m_Memory.m_pMemory[v55];
          st = CChoreoEvent::GetStartTime(this: v56);
          if ( CChoreoEvent::CurveHasEndTime(this: v56) )
            v57 = CChoreoEvent::GetEndTime(this: v56);
          else
            v57 = CChoreoEvent::GetStartTime(this: v56);
          v58 = v56->__vftable;
          et = v57;
          GetDuration = v58->GetDuration;
          flTimeFromStart = st - flStart;
          flDuration = GetDuration(this: v56);
          if ( this->m_nDragType == 10 )
          {
            *(float *)&flNewEndTime = flEnd - (float)((float)(flEnd - et) * flScale);
            if ( CChoreoEvent::CurveHasEndTime(this: v56) && !CChoreoEvent::IsFixedLength(this: v56) )
            {
              v60 = flDuration * flScale;
              flNewStartTime = *(float *)&flNewEndTime - (float)(flDuration * flScale);
LABEL_99:
              flNewDuration = v60;
              RescaleRamp(event: v56, newduration: v60);
              v62 = CChoreoEvent::GetType(this: v56);
              if ( v62 == GESTURE )
              {
                m_nDragType = this->m_nDragType;
                v64 = m_nDragType == 2 || m_nDragType == 4;
                CChoreoEvent::RescaleGestureTimes(
                  this: v56,
                  newstart: flNewStartTime,
                  newend: flNewDuration + flNewStartTime,
                  bMaintainAbsoluteTagPositions: v64);
              }
              else if ( v62 == FLEXANIMATION )
              {
                RescaleExpressionTimes(event: v56, newstart: flNewStartTime, newend: flNewDuration + flNewStartTime);
              }
              CChoreoEvent::SetStartTime(this: v56, starttime: flNewStartTime);
              CChoreoEvent::SetEndTime(this: v56, endtime: flNewDuration + flNewStartTime);
              continue;
            }
            v61 = *(float *)&flNewEndTime - flDuration;
          }
          else
          {
            flNewStartTime = (float)(flTimeFromStart * flScale) + flStart;
            if ( CChoreoEvent::CurveHasEndTime(this: v56) && !CChoreoEvent::IsFixedLength(this: v56) )
            {
              v60 = flDuration * flScale;
              goto LABEL_99;
            }
            v61 = flNewStartTime;
          }
          CChoreoEvent::OffsetTime(this: v56, dt: v61 - st);
        }
      }
    }
  }
  for ( i = 0; i < this->m_SceneGlobalEvents.m_Size; ++i )
  {
    m_pMemory = this->m_SceneGlobalEvents.m_Memory.m_pMemory;
    v67 = (TimelineItem *)m_pMemory[i];
    if ( v67 != nullptr
      && ((unsigned __int8 (__thiscall *)(CChoreoGlobalEventWidget *))v67->__vftable[3].Draw)(a1: m_pMemory[i]) != 0 )
    {
      Actor = (CChoreoEvent *)CActorBitmapButton::GetActor(this: v67);
      v69 = Actor;
      if ( Actor != nullptr )
      {
        CChoreoEvent::OffsetTime(this: Actor, dt);
        CChoreoEvent::SnapTimes(this: v69);
      }
    }
  }
  m_hPrevCursor = this->m_hPrevCursor;
  this->m_nDragType = 0;
  if ( m_hPrevCursor != nullptr )
  {
    SetCursor(hCursor: m_hPrevCursor);
    this->m_hPrevCursor = nullptr;
  }
  v71 = this->m_pClickedEvent;
  if ( v71 != nullptr )
  {
    flNewStartTime = COERCE_FLOAT(CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v71));
    if ( flNewStartTime != 0.0 )
    {
      m_yStart = (unsigned int)my;
      v73 = (int)my - this->m_yStart;
      if ( (event->modifiers & 2) == 0 )
        v73 = 0;
      if ( (int)abs32(v73) < this->m_pClickedEvent->GetItemHeight(this: this->m_pClickedEvent) )
        m_yStart = this->m_yStart;
      ChannelUnderCursorPos = CChoreoView::GetChannelUnderCursorPos(this, mx, my: m_yStart);
      chNew = (CChoreoChannelWidget *)ChannelUnderCursorPos;
      if ( !this->m_bSuppressLayout )
      {
        m_pScene = this->m_pScene;
        if ( m_pScene != nullptr )
        {
          StopTime = CChoreoScene::FindStopTime(this: m_pScene);
          mxa = StopTime;
          if ( StopTime < 5.0 )
            mxa = 5.0;
          v78 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
          v79 = this->m_pScene;
          if ( v79 != nullptr )
            TimeZoom = CChoreoScene::GetTimeZoom(this: v79, tool: v78);
          else
            TimeZoom = 100;
          v76 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                           * (float)(mxa + 5.0));
        }
        else
        {
          v76 = 0;
        }
        if ( v76 != this->m_nLastHPixelsNeeded )
          CChoreoView::RepositionHSlider(this);
        v81 = 0;
        for ( j = 0; v81 < this->m_SceneActors.m_Size; ++v81 )
        {
          v83 = this->m_SceneActors.m_Memory.m_pMemory[v81];
          if ( v83 != nullptr )
            j += v83->GetItemHeight(this: v83) + 2;
        }
        if ( j + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
          CChoreoView::RepositionVSlider(this);
        v84 = this->m_pScene;
        if ( v84 != nullptr )
        {
          CChoreoScene::ReconcileGestureTimes(this: v84);
          CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
        }
        redraw = this->redraw;
        this->m_bLayoutIsValid = false;
        redraw(this);
        ChannelUnderCursorPos = (CChoreoActorWidget *)chNew;
      }
      m_pClickedChannel = this->m_pClickedChannel;
      if ( m_pClickedChannel != nullptr
        && ChannelUnderCursorPos != nullptr
        && m_pClickedChannel != (CChoreoChannelWidget *)ChannelUnderCursorPos )
      {
        v87 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)m_pClickedChannel);
        v88 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)chNew);
        CChoreoView::DeleteSceneWidgets(this);
        CChoreoChannel::RemoveEvent(this: (CChoreoChannel *)v87, event: (CChoreoEvent *)LODWORD(flNewStartTime));
        v89 = (CChoreoEvent *)LODWORD(flNewStartTime);
        CChoreoChannel::AddEvent(this: (CChoreoChannel *)v88, event: (CChoreoEvent *)LODWORD(flNewStartTime));
        CChoreoEvent::SetChannel(this: v89, channel: (CChoreoChannel *)v88);
        v90 = CChoreoChannel::GetActor(this: (CChoreoChannel *)v88);
        CChoreoEvent::SetActor(this: v89, actor: v90);
        CChoreoView::CreateSceneWidgets(this);
      }
      else if ( CChoreoEvent::GetType(this: (CChoreoEvent *)LODWORD(flNewStartTime)) == SPEAK )
      {
        v91 = (CChoreoEvent *)LODWORD(flNewStartTime);
        v92 = FacePoser_TranslateSoundName(event: (CChoreoEvent *)LODWORD(flNewStartTime));
        v93 = va(fmt: "sound/%s", v92);
        PhonemeEditor::SetCurrentWaveFile(this: g_pPhonemeEditor, wavefile: v93, force: false, event: v91);
      }
    }
  }
  else
  {
    flNewStartTime = 0.0;
  }
  CChoreoView::PushRedo(this, description: desc);
  if ( !this->m_bSuppressLayout )
  {
    v94 = this->m_pScene;
    if ( v94 != nullptr )
    {
      v96 = CChoreoScene::FindStopTime(this: v94);
      mxb = v96;
      if ( v96 < 5.0 )
        mxb = 5.0;
      v97 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v98 = this->m_pScene;
      if ( v98 != nullptr )
        v99 = CChoreoScene::GetTimeZoom(this: v98, tool: v97);
      else
        v99 = 100;
      v95 = (int)(float)((float)((float)((float)v99 * this->m_flPixelsPerSecond) * 0.0099999998) * (float)(mxb + 5.0));
    }
    else
    {
      v95 = 0;
    }
    if ( v95 != this->m_nLastHPixelsNeeded )
      CChoreoView::RepositionHSlider(this);
    v100 = 0;
    for ( k = 0; v100 < this->m_SceneActors.m_Size; ++v100 )
    {
      v102 = this->m_SceneActors.m_Memory.m_pMemory[v100];
      if ( v102 != nullptr )
        k += v102->GetItemHeight(this: v102) + 2;
    }
    if ( k + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
      CChoreoView::RepositionVSlider(this);
    v103 = this->m_pScene;
    if ( v103 != nullptr )
    {
      CChoreoScene::ReconcileGestureTimes(this: v103);
      CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
    }
    v104 = this->redraw;
    this->m_bLayoutIsValid = false;
    v104(this);
  }
  v105 = (CChoreoEvent *)LODWORD(flNewStartTime);
  if ( flNewStartTime != 0.0 )
  {
    v106 = CChoreoEvent::GetType(this: (CChoreoEvent *)LODWORD(flNewStartTime));
    if ( v106 == GESTURE )
    {
      GestureTool::SetEvent(this: g_pGestureTool, event: v105);
    }
    else if ( v106 == FLEXANIMATION )
    {
      ExpressionTool::SetEvent(this: g_pExpressionTool, event: v105);
      FlexPanel::SetEvent(this: g_pFlexPanel, event: v105);
    }
    if ( CChoreoEvent::CurveHasEndTime(this: v105) )
      RampTool::SetEvent(this: g_pRampTool, event: v105);
  }
  ExpressionTool::LayoutItems(this: g_pExpressionTool, force: true);
  g_pExpressionTool->redraw(this: g_pExpressionTool);
  g_pGestureTool->redraw(this: g_pGestureTool);
  g_pRampTool->redraw(this: g_pRampTool);
  g_pSceneRampTool->redraw(this: g_pSceneRampTool);
  if ( rescaleHelper.m_Memory.m_nGrowSize >= 0 && rescaleHelper.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rescaleHelper.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004333C0
// Name: public: void CChoreoView::MouseFinishDrag(class mxEvent __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MouseFinishDrag(
        CChoreoView *this,
        mxEvent *event,
        CChoreoEvent *mx,
        CChoreoChannelWidget *my)
{
  CChoreoEvent *v5; // edi
  int m_nMinX; // eax
  int m_nLabelWidth; // eax
  int v8; // ecx
  int v9; // edi
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  float v11; // xmm1_4

  if ( this->m_bDragging )
  {
    v5 = mx;
    if ( this->m_bUseBounds )
    {
      m_nMinX = this->m_nMinX;
      if ( (int)mx < m_nMinX || (m_nMinX = this->m_nMaxX, (int)mx > m_nMinX) )
        v5 = (CChoreoEvent *)m_nMinX;
    }
    switch ( this->m_nDragType )
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 0xA:
      case 0xB:
        CChoreoView::FinishDraggingEvent(this, event, mx: (int)v5, my);
        break;
      case 8:
        CChoreoView::DrawFocusRect(this);
        CUtlVector<CChoreoView::CFocusRect,CUtlMemory<CChoreoView::CFocusRect,int>>::Purge(this: &this->m_FocusRects);
        m_nLabelWidth = this->m_nLabelWidth;
        v8 = this->m_rcTimeLine.right - m_nLabelWidth;
        v9 = (int)v5 - m_nLabelWidth;
        redraw = this->redraw;
        v11 = this->m_flScrubberTimeOffset
            + (float)((float)((float)((float)v9 / (float)v8) * (float)(this->m_flEndTime - this->m_flStartTime))
                    + this->m_flStartTime);
        this->m_flScrubberTimeOffset = 0.0;
        this->m_flScrub = v11;
        this->m_flScrubTarget = v11;
        this->m_bPaused = false;
        this->m_bDragging = false;
        this->m_nDragType = 0;
        redraw(this);
        break;
      case 9:
        CChoreoView::FinishDraggingSceneEndTime(this, event, mx: v5, (int)my);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433520
// Name: public: void CChoreoView::New(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChoreoView::New(CChoreoView *this@<ecx>, int a2@<ebx>)
{
  CChoreoScene *v3; // eax
  CChoreoScene *v4; // eax
  bool m_bDirty; // bl
  const char *v6; // eax
  bool v7; // zf
  CChoreoActor *v8; // eax
  char scenefile[512]; // [esp+4h] [ebp-38Ch] BYREF
  CActorParams params; // [esp+204h] [ebp-18Ch] BYREF

  if ( this->m_pScene == nullptr || (CChoreoView::Close(this, a2), this->m_pScene == nullptr) )
  {
    if ( FacePoser_ShowSaveFileNameDialog(relative: scenefile, bufsize: 0x200u, subdir: "scenes", wildcard: "*.vcd") )
    {
      V_DefaultExtension(path: scenefile, extension: ".vcd", pathStringLength: 512);
      v3 = (CChoreoScene *)operator new(nSize: 0x218u);
      v4 = v3 != nullptr ? CChoreoScene::CChoreoScene(this: v3, callback: &this->IChoreoEventCallback) : nullptr;
      this->m_pScene = v4;
      MDLViewer::InitGridSettings(this: g_MDLViewer);
      CChoreoView::SetChoreoFile(this, filename: scenefile);
      CChoreoScene::SetPrintFunc(this: this->m_pScene, pfn: Con_Printf);
      mxWidget::setVisible(this: this->m_btnPlay, b: true);
      mxWidget::setVisible(this: this->m_btnPause, b: true);
      mxWidget::setVisible(this: this->m_btnStop, b: true);
      mxWidget::setVisible(this: this->m_pPlaybackRate, b: true);
      m_bDirty = this->m_bDirty;
      this->m_bDirty = false;
      CChoreoView::WipeUndo(this);
      this->redraw(this);
      if ( m_bDirty )
      {
        v6 = "* ";
        if ( !this->m_bDirty )
          v6 = defaultValue;
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: v6);
      }
    }
    if ( this->m_pScene != nullptr )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      strcpy(params.m_szDialogTitle, "Create Actor");
      params.m_szName[0] = 0;
      if ( ActorProperties(&params) != 0 && strlen(params.m_szName) != 0 )
      {
        v7 = this->m_bDirty;
        this->m_bDirty = true;
        if ( !v7 )
          IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
        CChoreoView::PushUndo(this, description: aCreateA);
        Con_Printf(fmt: "Creating scene %s with actor '%s'\n", this->m_szChoreoFile, params.m_szName);
        v8 = CChoreoScene::AllocActor(this: this->m_pScene);
        if ( v8 != nullptr )
          CChoreoActor::SetName(this: v8, name: params.m_szName);
        CChoreoView::PushRedo(this, description: aCreateA);
        CChoreoView::CreateSceneWidgets(this);
        CChoreoView::InvalidateLayout(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433760
// Name: public: void CChoreoView::Load(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChoreoView::Load(CChoreoView *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  char scenefile[512]; // [esp+4h] [ebp-200h] BYREF

  if ( FacePoser_ShowOpenFileNameDialog(relative: scenefile, bufsize: 0x200u, subdir: "scenes", wildcard: "*.vcd") )
  {
    V_DefaultExtension(path: scenefile, extension: ".vcd", pathStringLength: 512);
    CChoreoView::LoadSceneFromFile(this, a2, a3, filename: scenefile);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &this->m_nextFileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004337D0
// Name: public: void CChoreoView::LoadNext(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChoreoView::LoadNext(CChoreoView *this@<ecx>, int a2@<esi>)
{
  int v3; // edi
  int v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  const char *v8; // esi
  int v9; // esi
  const char *v10; // eax
  int v11; // eax
  char v12; // cl
  const char *v13; // ecx
  unsigned int v14; // eax
  const char *v15; // esi
  char *v16; // edi
  char v17; // cl
  const char *v18; // ecx
  char v19; // cl
  char *v20; // edi
  unsigned int v21; // ecx
  char relativeFile[512]; // [esp+8h] [ebp-814h] BYREF
  char fixedupFile[512]; // [esp+208h] [ebp-614h] BYREF
  char relativePath[512]; // [esp+408h] [ebp-414h] BYREF
  char fileName[512]; // [esp+608h] [ebp-214h] BYREF
  CUtlString s; // [esp+808h] [ebp-14h] BYREF
  int hFindFile; // [esp+818h] [ebp-4h] BYREF

  v3 = 0;
  if ( this != (CChoreoView *)-881 )
  {
    V_FixupPathName(pOut: fixedupFile, nOutLen: 0x200u, pPath: this->m_szChoreoFile);
    filesystem->FullPathToRelativePath(this: filesystem, a2: fixedupFile, a3: relativeFile, a4: 512);
    V_ExtractFilePath(path: relativeFile, dest: relativePath, destSize: 512);
    if ( this->m_nextFileList.m_Size == 0 )
    {
      v4 = 0;
      do
      {
        v5 = relativePath[v4];
        fileName[v4++] = v5;
      }
      while ( v5 != 0 );
      v6 = &relativePath[511];
      do
        v7 = *++v6;
      while ( v7 != 0 );
      strcpy(v6, "/*.vcd");
      v8 = filesystem->FindFirstEx(this: filesystem, a2: fileName, a3: "MOD", a4: &hFindFile);
      if ( v8 != nullptr )
      {
        do
        {
          if ( ((unsigned __int8 (__thiscall *)(IFileSystem *, int, int))filesystem->FindIsDirectory)(
                 a1: filesystem,
                 a2: hFindFile,
                 a3: a2) == 0 )
          {
            CUtlString::CUtlString(this: &s, pString: v8);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: &this->m_nextFileList,
              elem: this->m_nextFileList.m_Size,
              src: &s);
            s.m_Storage.m_nActualLength = 0;
            if ( s.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( s.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s.m_Storage.m_Memory.m_pMemory);
                s.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              s.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
          a2 = hFindFile;
          v8 = (const char *)((int (__thiscall *)(IFileSystem *))filesystem->FindNext)(a1: filesystem);
        }
        while ( v8 != nullptr );
        filesystem->FindClose(this: filesystem, a2: hFindFile);
      }
    }
    v9 = 0;
    hFindFile = (int)V_UnqualifiedFileName(in: fixedupFile);
    if ( this->m_nextFileList.m_Size > 0 )
    {
      while ( 1 )
      {
        v10 = CUtlString::operator char const *(this: &this->m_nextFileList.m_Memory.m_pMemory[v3]);
        if ( _V_stricmp(s1: (const char *)hFindFile, s2: v10) == 0 )
          break;
        ++v9;
        ++v3;
        if ( v9 >= this->m_nextFileList.m_Size )
          return;
      }
      v11 = 0;
      do
      {
        v12 = relativePath[v11];
        fileName[v11++] = v12;
      }
      while ( v12 != 0 );
      if ( v9 >= this->m_nextFileList.m_Size - 1 )
      {
        v18 = CUtlString::operator char const *(this: this->m_nextFileList.m_Memory.m_pMemory);
        v14 = strlen(v18) + 1;
        v15 = v18;
        v16 = &relativePath[511];
        do
          v19 = *++v16;
        while ( v19 != 0 );
      }
      else
      {
        v13 = CUtlString::operator char const *(this: &this->m_nextFileList.m_Memory.m_pMemory[v9 + 1]);
        v14 = strlen(v13) + 1;
        v15 = v13;
        v16 = &relativePath[511];
        do
          v17 = *++v16;
        while ( v17 != 0 );
      }
      qmemcpy(v16, v15, 4 * (v14 >> 2));
      v20 = &v16[4 * (v14 >> 2)];
      v21 = v14 & 3;
      qmemcpy(v20, &v15[4 * (v14 >> 2)], v21);
      CChoreoView::LoadSceneFromFile(this, a2: (int)this, a3: (int)&v20[v21], filename: fileName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433A50
// Name: public: void CChoreoView::DeleteChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DeleteChannel(CChoreoView *this, CChoreoChannel *channel)
{
  bool m_bDirty; // zf
  int v4; // ebx
  CChoreoActor *Actor; // edi
  const char *Name; // eax

  if ( channel != nullptr && this->m_pScene != nullptr )
  {
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    CChoreoView::PushUndo(this, description: "Delete Channel");
    CChoreoView::DeleteSceneWidgets(this);
    v4 = 0;
    if ( CChoreoScene::GetNumActors(this: this->m_pScene) > 0 )
    {
      while ( 1 )
      {
        Actor = CChoreoScene::GetActor(this: this->m_pScene, actor: v4);
        if ( Actor != nullptr && CChoreoActor::FindChannelIndex(this: Actor, channel) != -1 )
          break;
        if ( ++v4 >= CChoreoScene::GetNumActors(this: this->m_pScene) )
          goto LABEL_11;
      }
      Name = CChoreoChannel::GetName(this: channel);
      Con_Printf(fmt: "Deleting %s\n", Name);
      CChoreoActor::RemoveChannel(this: Actor, channel);
      CChoreoScene::DeleteReferencedObjects(this: this->m_pScene, channel);
    }
LABEL_11:
    CChoreoView::ReportSceneClearToTools(this);
    CChoreoView::CreateSceneWidgets(this);
    CChoreoView::PushRedo(this, description: "Delete Channel");
    CChoreoView::InvalidateLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433B50
// Name: public: void CChoreoView::NewChannel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::NewChannel(CChoreoView *this)
{
  CChoreoScene *m_pScene; // ecx
  CChoreoScene *v3; // ecx
  CChoreoActor *Actor; // ebx
  bool m_bDirty; // zf
  CChoreoChannel *v6; // eax
  CChoreoChannel *v7; // edi
  CChannelParams params; // [esp+4h] [ebp-294h] BYREF

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
  {
    if ( CChoreoScene::GetNumActors(this: m_pScene) != 0 )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      v3 = this->m_pScene;
      strcpy(params.m_szDialogTitle, "Create Channel");
      params.m_szName[0] = 0;
      *(_WORD *)&params.m_bShowActors = 1;
      params.m_pScene = v3;
      if ( ChannelProperties(&params) != 0 && strlen(params.m_szName) != 0 )
      {
        Actor = CChoreoScene::FindActor(this: this->m_pScene, name: params.m_szSelectedActor);
        if ( Actor != nullptr )
        {
          m_bDirty = this->m_bDirty;
          this->m_bDirty = true;
          if ( !m_bDirty )
            IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
          CChoreoView::PushUndo(this, description: "Add Channel");
          CChoreoView::DeleteSceneWidgets(this);
          v6 = CChoreoScene::AllocChannel(this: this->m_pScene);
          v7 = v6;
          if ( v6 != nullptr )
          {
            CChoreoChannel::SetName(this: v6, name: params.m_szName);
            CChoreoChannel::SetActor(this: v7, actor: Actor);
            CChoreoActor::AddChannel(this: Actor, channel: v7);
          }
          else
          {
            Con_Printf(fmt: "Unable to allocate channel %s!\n", params.m_szName);
          }
          CChoreoView::CreateSceneWidgets(this);
          CChoreoView::PushRedo(this, description: "Add Channel");
          CChoreoView::InvalidateLayout(this);
        }
        else
        {
          Con_Printf(fmt: "Can't add channel %s, actor %s doesn't exist\n", params.m_szName, params.m_szSelectedActor);
        }
      }
    }
    else
    {
      Con_Printf(fmt: "You must create an actor before you can add a channel\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433CF0
// Name: public: void CChoreoView::MoveChannelUp(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MoveChannelUp(CChoreoView *this, CChoreoChannel *channel)
{
  bool v3; // al
  int v4; // ebx
  CChoreoActor *Actor; // edi
  int ChannelIndex; // eax
  int v7; // ebx
  const char *Name; // eax
  CChoreoScene *m_pScene; // ecx
  int v10; // eax
  double StopTime; // st7
  const char *v12; // eax
  CChoreoScene *v13; // ecx
  int TimeZoom; // eax
  int v15; // ebx
  int j; // edi
  CChoreoActorWidget *v17; // ecx
  CChoreoScene *v18; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // edx
  int i; // [esp+Ch] [ebp-4h]
  float channela; // [esp+18h] [ebp+8h]

  v3 = !this->m_bDirty;
  this->m_bDirty = true;
  if ( v3 )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  CChoreoView::PushUndo(this, description: "Move Channel Up");
  CChoreoView::DeleteSceneWidgets(this);
  v4 = 0;
  for ( i = 0; v4 < CChoreoScene::GetNumActors(this: this->m_pScene); i = ++v4 )
  {
    Actor = CChoreoScene::GetActor(this: this->m_pScene, actor: v4);
    if ( Actor != nullptr )
    {
      ChannelIndex = CChoreoActor::FindChannelIndex(this: Actor, channel);
      v7 = ChannelIndex;
      if ( ChannelIndex != -1 )
      {
        if ( ChannelIndex != 0 )
        {
          Name = CChoreoChannel::GetName(this: channel);
          Con_Printf(fmt: "Moving %s up\n", Name);
          CChoreoActor::SwapChannels(this: Actor, c1: v7, c2: v7 - 1);
        }
        break;
      }
      v4 = i;
    }
  }
  CChoreoView::CreateSceneWidgets(this);
  CChoreoView::PushRedo(this, description: "Move Channel Up");
  if ( !this->m_bSuppressLayout )
  {
    m_pScene = this->m_pScene;
    if ( m_pScene != nullptr )
    {
      StopTime = CChoreoScene::FindStopTime(this: m_pScene);
      channela = StopTime;
      if ( StopTime < 5.0 )
        channela = 5.0;
      v12 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v13 = this->m_pScene;
      if ( v13 != nullptr )
        TimeZoom = CChoreoScene::GetTimeZoom(this: v13, tool: v12);
      else
        TimeZoom = 100;
      v10 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                       * (float)(channela + 5.0));
    }
    else
    {
      v10 = 0;
    }
    if ( v10 != this->m_nLastHPixelsNeeded )
      CChoreoView::RepositionHSlider(this);
    v15 = 0;
    for ( j = 0; j < this->m_SceneActors.m_Size; ++j )
    {
      v17 = this->m_SceneActors.m_Memory.m_pMemory[j];
      if ( v17 != nullptr )
        v15 += v17->GetItemHeight(this: v17) + 2;
    }
    if ( v15 + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
      CChoreoView::RepositionVSlider(this);
    v18 = this->m_pScene;
    if ( v18 != nullptr )
    {
      CChoreoScene::ReconcileGestureTimes(this: v18);
      CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
    }
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433EE0
// Name: public: void CChoreoView::MoveChannelDown(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MoveChannelDown(CChoreoView *this, CChoreoChannel *channel)
{
  bool v3; // al
  int v4; // ebx
  CChoreoActor *Actor; // edi
  int ChannelIndex; // ebx
  const char *Name; // eax
  CChoreoScene *m_pScene; // ecx
  int v9; // eax
  double StopTime; // st7
  const char *v11; // eax
  CChoreoScene *v12; // ecx
  int TimeZoom; // eax
  int v14; // ebx
  int j; // edi
  CChoreoActorWidget *v16; // ecx
  CChoreoScene *v17; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // edx
  int i; // [esp+Ch] [ebp-4h]
  float channela; // [esp+18h] [ebp+8h]

  v3 = !this->m_bDirty;
  this->m_bDirty = true;
  if ( v3 )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  CChoreoView::PushUndo(this, description: "Move Channel Down");
  CChoreoView::DeleteSceneWidgets(this);
  v4 = 0;
  for ( i = 0; v4 < CChoreoScene::GetNumActors(this: this->m_pScene); i = ++v4 )
  {
    Actor = CChoreoScene::GetActor(this: this->m_pScene, actor: v4);
    if ( Actor != nullptr )
    {
      ChannelIndex = CChoreoActor::FindChannelIndex(this: Actor, channel);
      if ( ChannelIndex != -1 )
      {
        if ( ChannelIndex < CChoreoActor::GetNumChannels(this: Actor) - 1 )
        {
          Name = CChoreoChannel::GetName(this: channel);
          Con_Printf(fmt: "Moving %s down\n", Name);
          CChoreoActor::SwapChannels(this: Actor, c1: ChannelIndex, c2: ChannelIndex + 1);
        }
        break;
      }
      v4 = i;
    }
  }
  CChoreoView::CreateSceneWidgets(this);
  CChoreoView::PushRedo(this, description: "Move Channel Down");
  if ( !this->m_bSuppressLayout )
  {
    m_pScene = this->m_pScene;
    if ( m_pScene != nullptr )
    {
      StopTime = CChoreoScene::FindStopTime(this: m_pScene);
      channela = StopTime;
      if ( StopTime < 5.0 )
        channela = 5.0;
      v11 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v12 = this->m_pScene;
      if ( v12 != nullptr )
        TimeZoom = CChoreoScene::GetTimeZoom(this: v12, tool: v11);
      else
        TimeZoom = 100;
      v9 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                      * (float)(channela + 5.0));
    }
    else
    {
      v9 = 0;
    }
    if ( v9 != this->m_nLastHPixelsNeeded )
      CChoreoView::RepositionHSlider(this);
    v14 = 0;
    for ( j = 0; j < this->m_SceneActors.m_Size; ++j )
    {
      v16 = this->m_SceneActors.m_Memory.m_pMemory[j];
      if ( v16 != nullptr )
        v14 += v16->GetItemHeight(this: v16) + 2;
    }
    if ( v14 + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
      CChoreoView::RepositionVSlider(this);
    v17 = this->m_pScene;
    if ( v17 != nullptr )
    {
      CChoreoScene::ReconcileGestureTimes(this: v17);
      CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
    }
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004340D0
// Name: public: void CChoreoView::EditChannel(class CChoreoChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::EditChannel(CChoreoView *this, CChoreoChannel *channel)
{
  char *Name; // eax
  char *v4; // edx
  char v5; // cl
  bool m_bDirty; // zf
  CChannelParams params; // [esp+8h] [ebp-294h] BYREF

  if ( channel != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Edit Channel");
    Name = (char *)CChoreoChannel::GetName(this: channel);
    v4 = (char *)(params.m_szName - Name);
    do
    {
      v5 = *Name;
      Name[(_DWORD)v4] = *Name;
      ++Name;
    }
    while ( v5 != 0 );
    if ( ChannelProperties(&params) != 0 && strlen(params.m_szName) != 0 )
    {
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: aEditCha);
      CChoreoChannel::SetName(this: channel, name: params.m_szName);
      CChoreoView::PushRedo(this, description: aEditCha);
      CChoreoView::InvalidateLayout(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004341D0
// Name: public: void CChoreoView::DeleteActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DeleteActor(CChoreoView *this, CChoreoActor *actor)
{
  bool m_bDirty; // zf
  CChoreoActor *Name; // eax

  if ( actor != nullptr && this->m_pScene != nullptr )
  {
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    CChoreoView::PushUndo(this, description: "Delete Actor");
    CChoreoView::DeleteSceneWidgets(this);
    Name = CChoreoActor::GetName(this: actor);
    Con_Printf(fmt: "Deleting %s\n", Name->m_szName);
    CChoreoScene::RemoveActor(this: this->m_pScene, actor);
    CChoreoScene::DeleteReferencedObjects(this: this->m_pScene, actor);
    CChoreoView::ReportSceneClearToTools(this);
    CChoreoView::CreateSceneWidgets(this);
    CChoreoView::PushRedo(this, description: "Delete Actor");
    CChoreoView::InvalidateLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434280
// Name: public: void CChoreoView::NewActor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::NewActor(CChoreoView *this)
{
  bool m_bDirty; // zf
  CChoreoActor *v3; // eax
  CActorParams params; // [esp+4h] [ebp-18Ch] BYREF

  if ( this->m_pScene != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Create Actor");
    params.m_szName[0] = 0;
    if ( ActorProperties(&params) != 0 && strlen(params.m_szName) != 0 )
    {
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Add Actor");
      CChoreoView::DeleteSceneWidgets(this);
      Con_Printf(fmt: "Adding new actor '%s'\n", params.m_szName);
      v3 = CChoreoScene::AllocActor(this: this->m_pScene);
      if ( v3 != nullptr )
        CChoreoActor::SetName(this: v3, name: params.m_szName);
      CChoreoView::CreateSceneWidgets(this);
      CChoreoView::PushRedo(this, description: "Add Actor");
      CChoreoView::InvalidateLayout(this);
    }
  }
  else
  {
    Con_ErrorPrintf(fmt: "You must load or create a scene file first\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004343B0
// Name: public: void CChoreoView::MoveActorUp(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MoveActorUp(CChoreoView *this, CChoreoActor *actor)
{
  int ActorIndex; // eax
  int v4; // edi
  CChoreoActor *Name; // eax
  bool m_bDirty; // zf

  CChoreoView::DeleteSceneWidgets(this);
  ActorIndex = CChoreoScene::FindActorIndex(this: this->m_pScene, actor);
  v4 = ActorIndex;
  if ( ActorIndex != -1 && ActorIndex != 0 )
  {
    Name = CChoreoActor::GetName(this: actor);
    Con_Printf(fmt: "Moving %s up\n", Name->m_szName);
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    CChoreoView::PushUndo(this, description: "Move Actor Up");
    CChoreoScene::SwapActors(this: this->m_pScene, a1: v4, a2: v4 - 1);
    CChoreoView::PushRedo(this, description: "Move Actor Up");
  }
  CChoreoView::CreateSceneWidgets(this);
  CChoreoView::InvalidateLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00434450
// Name: public: void CChoreoView::MoveActorDown(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MoveActorDown(CChoreoView *this, CChoreoActor *actor)
{
  int ActorIndex; // edi
  CChoreoActor *Name; // eax
  bool m_bDirty; // zf

  CChoreoView::DeleteSceneWidgets(this);
  ActorIndex = CChoreoScene::FindActorIndex(this: this->m_pScene, actor);
  if ( ActorIndex != -1 && ActorIndex < CChoreoScene::GetNumActors(this: this->m_pScene) - 1 )
  {
    Name = CChoreoActor::GetName(this: actor);
    Con_Printf(fmt: "Moving %s down\n", Name->m_szName);
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    CChoreoView::PushUndo(this, description: "Move Actor Down");
    CChoreoScene::SwapActors(this: this->m_pScene, a1: ActorIndex, a2: ActorIndex + 1);
    CChoreoView::PushRedo(this, description: "Move Actor Down");
  }
  CChoreoView::CreateSceneWidgets(this);
  CChoreoView::InvalidateLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00434500
// Name: public: void CChoreoView::EditActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::EditActor(CChoreoView *this, CChoreoActor *actor)
{
  CChoreoActor *Name; // eax
  char *v4; // edx
  char v5; // cl
  bool m_bDirty; // zf
  CActorParams params; // [esp+8h] [ebp-18Ch] BYREF

  if ( actor != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Edit Actor");
    Name = CChoreoActor::GetName(this: actor);
    v4 = (char *)(params.m_szName - (char *)Name);
    do
    {
      v5 = Name->m_szName[0];
      Name->m_szName[(_DWORD)v4] = Name->m_szName[0];
      Name = (CChoreoActor *)((char *)Name + 1);
    }
    while ( v5 != 0 );
    if ( ActorProperties(&params) != 0 && strlen(params.m_szName) != 0 )
    {
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: aEditAct);
      CChoreoActor::SetName(this: actor, name: params.m_szName);
      CChoreoView::PushRedo(this, description: aEditAct);
      CChoreoView::InvalidateLayout(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434600
// Name: public: void CChoreoView::AddEvent(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::AddEvent(
        CChoreoView *this,
        CChoreoEvent::EVENTTYPE type,
        int subtype,
        CChoreoChannel *defaultparameters)
{
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  int m_nClickedX; // edi
  CChoreoActorWidget *m_pClickedActor; // ebx
  CChoreoChannelWidget *v8; // eax
  float m_flStartTime; // xmm1_4
  CChoreoScene *m_pScene; // ecx
  float v11; // xmm0_4
  const char *v12; // eax
  bool m_bDirty; // zf
  CChoreoEvent *v14; // eax
  CChoreoEvent *v15; // edi
  CChoreoActor *Actor; // eax
  float m_flEndTime; // xmm0_4
  char *Parameters; // eax
  CChoreoScene *Scene; // eax
  CChoreoScene *v20; // ebx
  double StopTime; // st7
  IFacePoserSound_vtbl *v22; // ebx
  const char *v23; // eax
  char *v24; // eax
  int v25; // ebx
  double v26; // st7
  CChoreoScene *v27; // ecx
  int v28; // eax
  double v29; // st7
  const char *Name; // eax
  CChoreoScene *v31; // ecx
  int TimeZoom; // eax
  int v33; // ebx
  int i; // edi
  CChoreoActorWidget *v35; // ecx
  CChoreoScene *v36; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  float starttime; // [esp+4h] [ebp-6E4h]
  float starttimea; // [esp+4h] [ebp-6E4h]
  CEventParams params; // [esp+14h] [ebp-6D4h] BYREF
  __int64 v41; // [esp+6D4h] [ebp-14h]
  __int64 v42; // [esp+6DCh] [ebp-Ch]
  CChoreoChannelWidget *channel; // [esp+6E4h] [ebp-4h]
  CChoreoChannel *pchannel; // [esp+6F8h] [ebp+10h]
  float pchannela; // [esp+6F8h] [ebp+10h]

  m_pClickedChannel = this->m_pClickedChannel;
  m_nClickedX = this->m_nClickedX;
  channel = m_pClickedChannel;
  if ( m_pClickedChannel == nullptr
    || CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)m_pClickedChannel) == nullptr )
  {
    m_pClickedActor = this->m_pClickedActor;
    if ( m_pClickedActor == nullptr )
      return;
    if ( CChoreoWidgetDrawHelper::GetHeight(this: this->m_pClickedActor) <= 0 )
      return;
    v8 = CChoreoActorWidget::GetChannel(this: m_pClickedActor, num: 0);
    channel = v8;
    if ( v8 == nullptr || CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v8) == nullptr )
      return;
  }
  memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
  if ( defaultparameters != nullptr )
    V_strncpy(pDest: params.m_szParameters, pSrc: (const char *)defaultparameters, maxLen: 256);
  m_flStartTime = this->m_flStartTime;
  m_pScene = this->m_pScene;
  strcpy(params.m_szDialogTitle, "Create Event");
  v41 = *(_QWORD *)&this->m_rcTimeLine.left;
  v42 = *(_QWORD *)&this->m_rcTimeLine.right;
  v11 = (float)((float)((float)(m_nClickedX - this->m_nLabelWidth) / (float)(v42 - this->m_nLabelWidth))
              * (float)(this->m_flEndTime - m_flStartTime))
      + m_flStartTime;
  params.m_nType = type;
  params.m_pScene = m_pScene;
  *(_WORD *)&params.m_bFixedLength = 0;
  params.m_flStartTime = v11;
  params.m_bCloseCaptionNoAttenuate = false;
  *(_WORD *)&params.m_bForceShortMovement = 0;
  params.m_bDisabled = false;
  params.m_bPlayOverScript = false;
  switch ( type )
  {
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 10:
    case 11:
    case 13:
    case 15:
    case 16:
    case 17:
      params.m_bHasEndTime = true;
      params.m_flEndTime = v11 + 0.5;
      if ( type == GESTURE && subtype == 1 )
      {
        strcpy(params.m_szDialogTitle, "Create <NULL> Gesture");
        strcpy(params.m_szName, "NULL");
      }
      break;
    case 5:
      params.m_bFixedLength = true;
      goto LABEL_14;
    default:
LABEL_14:
      params.m_flEndTime = -1.0;
      params.m_bHasEndTime = false;
      break;
  }
  this->m_flScrubTarget = this->m_flScrub;
  params.m_bUsesTag = false;
  this->m_bPaused = false;
  CChoreoView::FinishSimulation(this);
  sound->Flush(this: sound);
  this->m_bForceProcess = true;
  if ( EventProperties(&params) == 0 )
  {
LABEL_23:
    this->m_bForceProcess = false;
    return;
  }
  while ( 1 )
  {
    this->m_bForceProcess = false;
    if ( _V_strlen(str: params.m_szName) > 0 )
      break;
    v12 = va(fmt: "Event must have a valid name");
LABEL_22:
    mxMessageBox(parent: this, msg: v12, title: "Edit Event", style: 8);
    this->m_flScrubTarget = this->m_flScrub;
    this->m_bPaused = false;
    CChoreoView::FinishSimulation(this);
    sound->Flush(this: sound);
    this->m_bForceProcess = true;
    if ( EventProperties(&params) == 0 )
      goto LABEL_23;
  }
  if ( _V_strlen(str: params.m_szParameters) <= 0 )
  {
    switch ( params.m_nType )
    {
      case 6:
        if ( subtype == 1 )
          goto $LN18_2;
        break;
      case 0xA:
      case 0xD:
      case 0xF:
        goto $LN18_2;
      default:
        break;
    }
    v12 = va(fmt: "No parameters specified for %s\n", params.m_szName);
    goto LABEL_22;
  }
$LN18_2:
  m_bDirty = this->m_bDirty;
  this->m_bDirty = true;
  if ( !m_bDirty )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  CChoreoView::PushUndo(this, description: "Add Event");
  v14 = CChoreoScene::AllocEvent(this: this->m_pScene);
  v15 = v14;
  if ( v14 != nullptr )
  {
    CChoreoEvent::SetType(this: v14, type);
    CChoreoEvent::SetName(this: v15, name: params.m_szName);
    CChoreoEvent::SetParameters(this: v15, param: params.m_szParameters);
    CChoreoEvent::SetParameters2(this: v15, param: params.m_szParameters2);
    CChoreoEvent::SetParameters3(this: v15, param: params.m_szParameters3);
    CChoreoEvent::SetStartTime(this: v15, starttime: params.m_flStartTime);
    CChoreoEvent::SetResumeCondition(this: v15, resumecondition: params.m_bResumeCondition);
    CChoreoEvent::SetLockBodyFacing(this: v15, lockbodyfacing: params.m_bLockBodyFacing);
    CChoreoEvent::SetDistanceToTarget(this: v15, distancetotarget: params.m_flDistanceToTarget);
    CChoreoEvent::SetForceShortMovement(this: v15, bForceShortMovement: params.m_bForceShortMovement);
    CChoreoEvent::SetSyncToFollowingGesture(this: v15, bSyncToFollowingGesture: params.m_bSyncToFollowingGesture);
    CChoreoEvent::SetActive(this: v15, state: !params.m_bDisabled);
    CChoreoEvent::SetPlayOverScript(this: v15, bPlayOverScript: params.m_bPlayOverScript);
    if ( params.m_bUsesTag )
      CChoreoEvent::SetUsingRelativeTag(
        this: v15,
        usetag: true,
        tagname: params.m_szTagName,
        wavname: params.m_szTagWav);
    else
      CChoreoEvent::SetUsingRelativeTag(this: v15, usetag: false, tagname: nullptr, wavname: nullptr);
    pchannel = (CChoreoChannel *)CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)channel);
    CChoreoEvent::SetChannel(this: v15, channel: pchannel);
    Actor = CChoreoChannel::GetActor(this: pchannel);
    CChoreoEvent::SetActor(this: v15, actor: Actor);
    if ( !params.m_bHasEndTime
      || (m_flEndTime = params.m_flEndTime, params.m_flEndTime == -1.0)
      || params.m_flEndTime <= params.m_flStartTime )
    {
      m_flEndTime = -1.0;
    }
    CChoreoEvent::SetEndTime(this: v15, endtime: m_flEndTime);
    switch ( CChoreoEvent::GetType(this: v15) )
    {
      case LOOKAT:
      case FACE:
        if ( params.usepitchyaw )
        {
          CChoreoEvent::SetPitch(this: v15, pitch: params.pitch);
          CChoreoEvent::SetYaw(this: v15, yaw: params.yaw);
        }
        else
        {
          CChoreoEvent::SetPitch(this: v15, pitch: 0);
          CChoreoEvent::SetYaw(this: v15, yaw: 0);
        }
        break;
      case SPEAK:
        v22 = sound->__vftable;
        v23 = FacePoser_TranslateSoundName(event: v15);
        v24 = va(fmt: "sound/%s", v23);
        v25 = (int)v22->LoadSound(this: sound, a2: v24);
        if ( v25 != 0 )
        {
          v26 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v25 + 36))(a1: v25);
          starttimea = v26 + params.m_flStartTime;
          CChoreoEvent::SetEndTime(this: v15, endtime: starttimea);
          (**(void (__thiscall ***)(int, int))v25)(a1: v25, a2: 1);
        }
        CChoreoEvent::SetSuppressingCaptionAttenuation(this: v15, suppress: params.m_bCloseCaptionNoAttenuate);
        break;
      case GESTURE:
        CChoreoView::DefaultGestureLength(this, e: v15, bCheckOnly: false);
        CChoreoView::AutoaddGestureKeys(this, e: v15, bCheckOnly: false);
        break;
      case SEQUENCE:
        CChoreoView::CheckSequenceLength(this, e: v15, bCheckOnly: false);
        break;
      case SUBSCENE:
        Parameters = (char *)CChoreoEvent::GetParameters(this: v15);
        Scene = CChoreoView::LoadScene(this, filename: Parameters);
        v20 = Scene;
        if ( Scene != nullptr )
        {
          StopTime = CChoreoScene::FindStopTime(this: Scene);
          starttime = StopTime + params.m_flStartTime;
          CChoreoEvent::SetEndTime(this: v15, endtime: starttime);
          CChoreoScene::~CChoreoScene(this: v20);
          free(pMem: v20);
        }
        break;
      default:
        break;
    }
    CChoreoEvent::SnapTimes(this: v15);
    CChoreoView::DeleteSceneWidgets(this);
    CChoreoChannel::AddEvent(this: pchannel, event: v15);
    CChoreoView::CreateSceneWidgets(this);
    if ( !this->m_bSuppressLayout )
    {
      v27 = this->m_pScene;
      if ( v27 != nullptr )
      {
        v29 = CChoreoScene::FindStopTime(this: v27);
        pchannela = v29;
        if ( v29 < 5.0 )
          pchannela = 5.0;
        Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
        v31 = this->m_pScene;
        if ( v31 != nullptr )
          TimeZoom = CChoreoScene::GetTimeZoom(this: v31, tool: Name);
        else
          TimeZoom = 100;
        v28 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                         * (float)(pchannela + 5.0));
      }
      else
      {
        v28 = 0;
      }
      if ( v28 != this->m_nLastHPixelsNeeded )
        CChoreoView::RepositionHSlider(this);
      v33 = 0;
      for ( i = 0; i < this->m_SceneActors.m_Size; ++i )
      {
        v35 = this->m_SceneActors.m_Memory.m_pMemory[i];
        if ( v35 != nullptr )
          v33 += v35->GetItemHeight(this: v35) + 2;
      }
      if ( v33 + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
        CChoreoView::RepositionVSlider(this);
      v36 = this->m_pScene;
      if ( v36 != nullptr )
      {
        CChoreoScene::ReconcileGestureTimes(this: v36);
        CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
      }
      redraw = this->redraw;
      this->m_bLayoutIsValid = false;
      redraw(this);
    }
  }
  CChoreoView::PushRedo(this, description: "Add Event");
}

//------------------------------------------------------------------------------
// Address: 0x00434D90
// Name: public: void CChoreoView::AddGlobalEvent(enum CChoreoEvent::EVENTTYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::AddGlobalEvent(CChoreoView *this, CChoreoEvent::EVENTTYPE type)
{
  int m_nClickedX; // edi
  __int64 v4; // xmm0_8
  int m_nLabelWidth; // eax
  float v6; // xmm1_4
  bool m_bDirty; // zf
  CChoreoEvent *v8; // eax
  CChoreoEvent *v9; // edi
  const char *v10; // eax
  char undotext[256]; // [esp+14h] [ebp-4B4h] BYREF
  CGlobalEventParams params; // [esp+114h] [ebp-3B4h] BYREF
  __int64 v13; // [esp+4B8h] [ebp-10h]
  __int64 v14; // [esp+4C0h] [ebp-8h]

  m_nClickedX = this->m_nClickedX;
  memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
  params.m_nType = type;
  switch ( type )
  {
    case SECTION:
      *(_QWORD *)params.m_szDialogTitle = *(_QWORD *)aAddPaus;
      v4 = 0x746E696F502065LL;
      break;
    case LOOP:
      strcpy(params.m_szDialogTitle, "Add Loop Point");
      goto LABEL_9;
    case STOPPOINT:
      *(_QWORD *)params.m_szDialogTitle = *(_QWORD *)aAddFire;
      v4 = 0x74656C706D6F4320LL;
      *(_DWORD *)&params.m_szDialogTitle[16] = (char *)&g_flexedverts[55040].z + 1;
      break;
    default:
      strcpy(params.m_szDialogTitle, "???");
      goto LABEL_9;
  }
  *(_QWORD *)&params.m_szDialogTitle[8] = v4;
LABEL_9:
  m_nLabelWidth = this->m_nLabelWidth;
  v13 = *(_QWORD *)&this->m_rcTimeLine.left;
  v14 = *(_QWORD *)&this->m_rcTimeLine.right;
  v6 = (float)((float)((float)(m_nClickedX - m_nLabelWidth) / (float)(v14 - m_nLabelWidth))
             * (float)(this->m_flEndTime - this->m_flStartTime))
     + this->m_flStartTime;
  params.m_szName[0] = 0;
  params.m_szAction[0] = 0;
  params.m_flStartTime = v6;
  if ( GlobalEventProperties(&params) != 0 )
  {
    if ( strlen(params.m_szName) != 0 )
    {
      if ( strlen(params.m_szAction) != 0 )
      {
        undotext[0] = 0;
        switch ( type )
        {
          case SECTION:
            _V_strcpy(dest: undotext, src: "Add Section Pause");
            break;
          case LOOP:
            _V_strcpy(dest: undotext, src: aAddLoop);
            break;
          case STOPPOINT:
            _V_strcpy(dest: undotext, src: aAddFire);
            break;
          default:
            break;
        }
        m_bDirty = this->m_bDirty;
        this->m_bDirty = true;
        if ( !m_bDirty )
          IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
        CChoreoView::PushUndo(this, description: undotext);
        v8 = CChoreoScene::AllocEvent(this: this->m_pScene);
        v9 = v8;
        if ( v8 != nullptr )
        {
          CChoreoEvent::SetType(this: v8, type);
          CChoreoEvent::SetName(this: v9, name: params.m_szName);
          CChoreoEvent::SetParameters(this: v9, param: params.m_szAction);
          CChoreoEvent::SetStartTime(this: v9, starttime: params.m_flStartTime);
          CChoreoEvent::SetEndTime(this: v9, endtime: -1.0);
          if ( type == LOOP )
          {
            CChoreoEvent::SetLoopCount(this: v9, numloops: params.m_nLoopCount);
            v10 = va(fmt: "%f", params.m_flLoopTime);
            CChoreoEvent::SetParameters(this: v9, param: v10);
          }
          CChoreoEvent::SnapTimes(this: v9);
          CChoreoView::DeleteSceneWidgets(this);
          CChoreoView::CreateSceneWidgets(this);
          CChoreoView::InvalidateLayout(this);
        }
        CChoreoView::PushRedo(this, description: undotext);
      }
      else
      {
        Con_Printf(fmt: "No action specified for section pause\n");
      }
    }
    else
    {
      Con_Printf(fmt: "Pause section event must have a valid name\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435080
// Name: public: void CChoreoView::EditGlobalEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::EditGlobalEvent(CChoreoView *this, CChoreoEvent *event)
{
  __int32 v3; // eax
  __int32 v4; // eax
  const char *Parameters; // eax
  char *v6; // eax
  char *v7; // edx
  char v8; // cl
  char *Name; // eax
  char *v10; // edx
  char v11; // cl
  const char *v12; // eax
  const char *v13; // eax
  bool m_bDirty; // zf
  __int32 v15; // eax
  __int32 v16; // eax
  const char *starttime; // [esp+4h] [ebp-4B0h]
  char undotext[256]; // [esp+10h] [ebp-4A4h] BYREF
  CGlobalEventParams params; // [esp+110h] [ebp-3A4h] BYREF

  if ( event != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    params.m_nType = CChoreoEvent::GetType(this: event);
    v3 = CChoreoEvent::GetType(this: event) - 1;
    if ( v3 != 0 )
    {
      v4 = v3 - 11;
      if ( v4 != 0 )
      {
        if ( v4 == 2 )
        {
          strcpy(params.m_szDialogTitle, "Edit Fire Completion");
          params.m_szAction[0] = 0;
        }
        else
        {
          strcpy(params.m_szDialogTitle, "???");
        }
      }
      else
      {
        strcpy(params.m_szDialogTitle, "Edit Loop Point");
        params.m_szAction[0] = 0;
        Parameters = CChoreoEvent::GetParameters(this: event);
        params.m_flLoopTime = atof(nptr: Parameters);
        params.m_nLoopCount = CChoreoEvent::GetLoopCount(this: event);
      }
    }
    else
    {
      strcpy(params.m_szDialogTitle, "Edit Pause Point");
      v6 = (char *)CChoreoEvent::GetParameters(this: event);
      v7 = (char *)(params.m_szAction - v6);
      do
      {
        v8 = *v6;
        v6[(_DWORD)v7] = *v6;
        ++v6;
      }
      while ( v8 != 0 );
    }
    Name = (char *)CChoreoEvent::GetName(this: event);
    v10 = (char *)(params.m_szName - Name);
    do
    {
      v11 = *Name;
      Name[(_DWORD)v10] = *Name;
      ++Name;
    }
    while ( v11 != 0 );
    params.m_flStartTime = CChoreoEvent::GetStartTime(this: event);
    if ( GlobalEventProperties(&params) != 0 )
    {
      if ( strlen(params.m_szName) != 0 )
      {
        if ( strlen(params.m_szAction) != 0 )
        {
          m_bDirty = this->m_bDirty;
          this->m_bDirty = true;
          if ( !m_bDirty )
            IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
          undotext[0] = 0;
          v15 = CChoreoEvent::GetType(this: event) - 1;
          if ( v15 != 0 )
          {
            v16 = v15 - 11;
            if ( v16 != 0 )
            {
              if ( v16 == 2 )
                _V_strcpy(dest: undotext, src: aEditFir);
            }
            else
            {
              _V_strcpy(dest: undotext, src: aEditLoo);
            }
          }
          else
          {
            _V_strcpy(dest: undotext, src: "Edit Section Pause");
          }
          CChoreoView::PushUndo(this, description: undotext);
          CChoreoEvent::SetName(this: event, name: params.m_szName);
          CChoreoEvent::SetStartTime(this: event, starttime: params.m_flStartTime);
          CChoreoEvent::SetEndTime(this: event, endtime: -1.0);
          if ( CChoreoEvent::GetType(this: event) == LOOP )
          {
            CChoreoEvent::SetLoopCount(this: event, numloops: params.m_nLoopCount);
            starttime = va(fmt: "%f", params.m_flLoopTime);
            CChoreoEvent::SetParameters(this: event, param: starttime);
          }
          else
          {
            CChoreoEvent::SetParameters(this: event, param: params.m_szAction);
          }
          CChoreoEvent::SnapTimes(this: event);
          CChoreoView::PushRedo(this, description: undotext);
          CChoreoView::InvalidateLayout(this);
        }
        else
        {
          v13 = CChoreoEvent::GetName(this: event);
          Con_Printf(fmt: "No action specified for %s\n", v13);
        }
      }
      else
      {
        v12 = CChoreoEvent::GetName(this: event);
        Con_Printf(fmt: "Event %s must have a valid name\n", v12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435370
// Name: public: void CChoreoView::DeleteGlobalEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DeleteGlobalEvent(CChoreoView *this, CChoreoEvent *event)
{
  bool m_bDirty; // zf
  __int32 v4; // eax
  __int32 v5; // eax
  const char *Name; // eax
  char undotext[256]; // [esp+8h] [ebp-100h] BYREF

  if ( event != nullptr && this->m_pScene != nullptr )
  {
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    undotext[0] = 0;
    v4 = CChoreoEvent::GetType(this: event) - 1;
    if ( v4 != 0 )
    {
      v5 = v4 - 11;
      if ( v5 != 0 )
      {
        if ( v5 == 2 )
          _V_strcpy(dest: undotext, src: "Delete Fire Completion");
      }
      else
      {
        _V_strcpy(dest: undotext, src: "Delete Loop Point");
      }
    }
    else
    {
      _V_strcpy(dest: undotext, src: "Delete Section Pause");
    }
    CChoreoView::PushUndo(this, description: undotext);
    CChoreoView::DeleteSceneWidgets(this);
    Name = CChoreoEvent::GetName(this: event);
    Con_Printf(fmt: "Deleting %s\n", Name);
    CChoreoScene::DeleteReferencedObjects(this: this->m_pScene, event);
    CChoreoView::CreateSceneWidgets(this);
    CChoreoView::PushRedo(this, description: undotext);
    CChoreoView::InvalidateLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435460
// Name: public: void CChoreoView::EditEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::EditEvent(CChoreoView *this, CChoreoEvent *event)
{
  char *Parameters3; // eax
  char *v5; // edx
  char v6; // cl
  char *Parameters2; // eax
  char *v8; // edx
  char v9; // cl
  char *Parameters; // eax
  char *v11; // edx
  char v12; // cl
  char *Name; // eax
  char *v14; // edx
  char v15; // cl
  char *v16; // eax
  char *v17; // edx
  char v18; // cl
  char *v19; // eax
  char *v20; // edx
  char v21; // cl
  char *RelativeTagName; // eax
  char *v23; // edx
  char v24; // cl
  char *RelativeWavName; // eax
  char *v26; // edx
  char v27; // cl
  const char *v28; // eax
  bool m_bDirty; // zf
  double EndTime; // st7
  CChoreoEvent::EVENTTYPE Type; // eax
  IFacePoserSound_vtbl *v32; // ebx
  const char *v33; // eax
  char *v34; // eax
  int v35; // ebx
  double v36; // st7
  char *v37; // eax
  CChoreoScene *Scene; // eax
  CChoreoScene *v39; // ebx
  double StopTime; // st7
  CChoreoScene *m_pScene; // ecx
  int v42; // eax
  double v43; // st7
  const char *v44; // eax
  CChoreoScene *v45; // ecx
  int TimeZoom; // eax
  int v47; // ebx
  int i; // esi
  CChoreoActorWidget *v49; // ecx
  CChoreoScene *v50; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  const char *v52; // eax
  const char *v53; // [esp+0h] [ebp-6D8h]
  float v54; // [esp+0h] [ebp-6D8h]
  float newstart; // [esp+4h] [ebp-6D4h]
  float newstarta; // [esp+4h] [ebp-6D4h]
  float newstartb; // [esp+4h] [ebp-6D4h]
  float newstartc; // [esp+4h] [ebp-6D4h]
  float starttime; // [esp+8h] [ebp-6D0h]
  CEventParams params; // [esp+14h] [ebp-6C4h] BYREF
  float newduration; // [esp+6D4h] [ebp-4h]
  float dt; // [esp+6E0h] [ebp+8h]
  float dta; // [esp+6E0h] [ebp+8h]

  if ( event == nullptr )
    return;
  memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
  strcpy(params.m_szDialogTitle, "Edit Event");
  params.m_nType = CChoreoEvent::GetType(this: event);
  params.m_bDisabled = !CChoreoEvent::GetActive(this: event);
  switch ( params.m_nType )
  {
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 0xD:
    case 0xF:
    case 0x10:
    case 0x11:
      Parameters3 = (char *)CChoreoEvent::GetParameters3(this: event);
      v5 = (char *)(params.m_szParameters3 - Parameters3);
      do
      {
        v6 = *Parameters3;
        Parameters3[(_DWORD)v5] = *Parameters3;
        ++Parameters3;
      }
      while ( v6 != 0 );
      Parameters2 = (char *)CChoreoEvent::GetParameters2(this: event);
      v8 = (char *)(params.m_szParameters2 - Parameters2);
      do
      {
        v9 = *Parameters2;
        Parameters2[(_DWORD)v8] = *Parameters2;
        ++Parameters2;
      }
      while ( v9 != 0 );
      Parameters = (char *)CChoreoEvent::GetParameters(this: event);
      v11 = (char *)(params.m_szParameters - Parameters);
      do
      {
        v12 = *Parameters;
        Parameters[(_DWORD)v11] = *Parameters;
        ++Parameters;
      }
      while ( v12 != 0 );
      Name = (char *)CChoreoEvent::GetName(this: event);
      v14 = (char *)(params.m_szName - Name);
      do
      {
        v15 = *Name;
        Name[(_DWORD)v14] = *Name;
        ++Name;
      }
      while ( v15 != 0 );
      goto LABEL_21;
    case 3:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
      v16 = (char *)CChoreoEvent::GetParameters(this: event);
      v17 = (char *)(params.m_szParameters - v16);
      do
      {
        v18 = *v16;
        v16[(_DWORD)v17] = *v16;
        ++v16;
      }
      while ( v18 != 0 );
      v19 = (char *)CChoreoEvent::GetName(this: event);
      v20 = (char *)(params.m_szName - v19);
      do
      {
        v21 = *v19;
        v19[(_DWORD)v20] = *v19;
        ++v19;
      }
      while ( v21 != 0 );
      if ( (params.m_nType == 3 || params.m_nType == 8)
        && (CChoreoEvent::GetPitch(this: event) != 0 || CChoreoEvent::GetYaw(this: event) != 0) )
      {
        params.usepitchyaw = true;
        params.pitch = CChoreoEvent::GetPitch(this: event);
        params.yaw = CChoreoEvent::GetYaw(this: event);
      }
LABEL_21:
      params.m_pScene = this->m_pScene;
      params.m_pEvent = event;
      params.m_flStartTime = CChoreoEvent::GetStartTime(this: event);
      params.m_flEndTime = CChoreoEvent::GetEndTime(this: event);
      params.m_bHasEndTime = CChoreoEvent::CurveHasEndTime(this: event);
      params.m_bFixedLength = CChoreoEvent::IsFixedLength(this: event);
      params.m_bResumeCondition = CChoreoEvent::IsResumeCondition(this: event);
      params.m_bLockBodyFacing = CChoreoEvent::IsLockBodyFacing(this: event);
      params.m_flDistanceToTarget = CChoreoEvent::GetDistanceToTarget(this: event);
      params.m_bForceShortMovement = CChoreoEvent::GetForceShortMovement(this: event);
      params.m_bSyncToFollowingGesture = CChoreoEvent::GetSyncToFollowingGesture(this: event);
      params.m_bPlayOverScript = CChoreoEvent::GetPlayOverScript(this: event);
      params.m_bUsesTag = CChoreoEvent::IsUsingRelativeTag(this: event);
      params.m_bCloseCaptionNoAttenuate = CChoreoEvent::IsSuppressingCaptionAttenuation(this: event);
      if ( params.m_bUsesTag )
      {
        RelativeTagName = (char *)CChoreoEvent::GetRelativeTagName(this: event);
        v23 = (char *)(params.m_szTagName - RelativeTagName);
        do
        {
          v24 = *RelativeTagName;
          v23[(_DWORD)RelativeTagName] = *RelativeTagName;
          ++RelativeTagName;
        }
        while ( v24 != 0 );
        RelativeWavName = (char *)CChoreoEvent::GetRelativeWavName(this: event);
        v26 = (char *)(params.m_szTagWav - RelativeWavName);
        do
        {
          v27 = *RelativeWavName;
          v26[(_DWORD)RelativeWavName] = *RelativeWavName;
          ++RelativeWavName;
        }
        while ( v27 != 0 );
      }
      this->m_flScrubTarget = this->m_flScrub;
      this->m_bPaused = false;
      CChoreoView::FinishSimulation(this);
      sound->Flush(this: sound);
      this->m_bForceProcess = true;
      if ( EventProperties(&params) == 0 )
        goto LABEL_34;
      break;
    default:
      v52 = CChoreoEvent::NameForType(type: (CChoreoEvent::EVENTTYPE)params.m_nType);
      Con_Printf(fmt: "Don't know how to edit event type %s\n", v52);
      return;
  }
  while ( 1 )
  {
    this->m_bForceProcess = false;
    if ( _V_strlen(str: params.m_szName) > 0 )
      break;
    v53 = CChoreoEvent::GetName(this: event);
    v28 = va(fmt: "Event %s must have a valid name", v53);
LABEL_33:
    mxMessageBox(parent: this, msg: v28, title: "Edit Event", style: 8);
    this->m_flScrubTarget = this->m_flScrub;
    this->m_bPaused = false;
    CChoreoView::FinishSimulation(this);
    sound->Flush(this: sound);
    this->m_bForceProcess = true;
    if ( EventProperties(&params) == 0 )
    {
LABEL_34:
      this->m_bForceProcess = false;
      return;
    }
  }
  if ( _V_strlen(str: params.m_szParameters) <= 0 )
  {
    switch ( params.m_nType )
    {
      case 6:
        if ( _V_stricmp(s1: params.m_szName, s2: "NULL") == 0 )
          goto $LN22;
        break;
      case 0xA:
      case 0xD:
      case 0xF:
        goto $LN22;
      default:
        break;
    }
    v28 = va(fmt: "No parameters specified for %s\n", params.m_szName);
    goto LABEL_33;
  }
$LN22:
  m_bDirty = this->m_bDirty;
  this->m_bDirty = true;
  if ( !m_bDirty )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  CChoreoView::PushUndo(this, description: "Edit Event");
  CChoreoEvent::SetName(this: event, name: params.m_szName);
  CChoreoEvent::SetParameters(this: event, param: params.m_szParameters);
  CChoreoEvent::SetParameters2(this: event, param: params.m_szParameters2);
  CChoreoEvent::SetParameters3(this: event, param: params.m_szParameters3);
  CChoreoEvent::SetStartTime(this: event, starttime: params.m_flStartTime);
  CChoreoEvent::SetResumeCondition(this: event, resumecondition: params.m_bResumeCondition);
  CChoreoEvent::SetLockBodyFacing(this: event, lockbodyfacing: params.m_bLockBodyFacing);
  CChoreoEvent::SetDistanceToTarget(this: event, distancetotarget: params.m_flDistanceToTarget);
  CChoreoEvent::SetForceShortMovement(this: event, bForceShortMovement: params.m_bForceShortMovement);
  CChoreoEvent::SetSyncToFollowingGesture(this: event, bSyncToFollowingGesture: params.m_bSyncToFollowingGesture);
  CChoreoEvent::SetActive(this: event, state: !params.m_bDisabled);
  CChoreoEvent::SetPlayOverScript(this: event, bPlayOverScript: params.m_bPlayOverScript);
  if ( params.m_bUsesTag )
    CChoreoEvent::SetUsingRelativeTag(
      this: event,
      usetag: true,
      tagname: params.m_szTagName,
      wavname: params.m_szTagWav);
  else
    CChoreoEvent::SetUsingRelativeTag(this: event, usetag: false, tagname: nullptr, wavname: nullptr);
  if ( !params.m_bHasEndTime || params.m_flEndTime == -1.0 || params.m_flEndTime <= params.m_flStartTime )
  {
    CChoreoEvent::SetEndTime(this: event, endtime: -1.0);
  }
  else
  {
    EndTime = CChoreoEvent::GetEndTime(this: event);
    dt = params.m_flEndTime - EndTime;
    newduration = ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event) + dt;
    RescaleRamp(event, newduration);
    Type = CChoreoEvent::GetType(this: event);
    if ( Type == GESTURE )
    {
      newstarta = CChoreoEvent::GetEndTime(this: event) + dt;
      v54 = CChoreoEvent::GetStartTime(this: event);
      CChoreoEvent::RescaleGestureTimes(
        this: event,
        newstart: v54,
        newend: newstarta,
        bMaintainAbsoluteTagPositions: true);
    }
    else if ( Type == FLEXANIMATION )
    {
      starttime = CChoreoEvent::GetEndTime(this: event) + dt;
      newstart = CChoreoEvent::GetStartTime(this: event);
      RescaleExpressionTimes(event, newstart, newend: starttime);
    }
    CChoreoEvent::SetEndTime(this: event, endtime: params.m_flEndTime);
    CChoreoEvent::SnapTimes(this: event);
    CCurveData::Resort(this: &event->m_Ramp, data: event);
  }
  switch ( CChoreoEvent::GetType(this: event) )
  {
    case LOOKAT:
    case FACE:
      if ( params.usepitchyaw )
      {
        CChoreoEvent::SetPitch(this: event, pitch: params.pitch);
        CChoreoEvent::SetYaw(this: event, yaw: params.yaw);
      }
      else
      {
        CChoreoEvent::SetPitch(this: event, pitch: 0);
        CChoreoEvent::SetYaw(this: event, yaw: 0);
      }
      break;
    case SPEAK:
      v32 = sound->__vftable;
      v33 = FacePoser_TranslateSoundName(event);
      v34 = va(fmt: "sound/%s", v33);
      v35 = (int)v32->LoadSound(this: sound, a2: v34);
      if ( v35 != 0 )
      {
        v36 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v35 + 36))(a1: v35);
        newstartb = v36 + params.m_flStartTime;
        CChoreoEvent::SetEndTime(this: event, endtime: newstartb);
        (**(void (__thiscall ***)(int, int))v35)(a1: v35, a2: 1);
      }
      CChoreoEvent::SetSuppressingCaptionAttenuation(this: event, suppress: params.m_bCloseCaptionNoAttenuate);
      break;
    case GESTURE:
      CChoreoView::CheckGestureLength(this, e: event, bCheckOnly: false);
      CChoreoView::AutoaddGestureKeys(this, e: event, bCheckOnly: false);
      g_pGestureTool->redraw(this: g_pGestureTool);
      break;
    case SEQUENCE:
      CChoreoView::CheckSequenceLength(this, e: event, bCheckOnly: false);
      break;
    case SUBSCENE:
      v37 = (char *)CChoreoEvent::GetParameters(this: event);
      Scene = CChoreoView::LoadScene(this, filename: v37);
      v39 = Scene;
      if ( Scene != nullptr )
      {
        StopTime = CChoreoScene::FindStopTime(this: Scene);
        newstartc = StopTime + params.m_flStartTime;
        CChoreoEvent::SetEndTime(this: event, endtime: newstartc);
        CChoreoScene::~CChoreoScene(this: v39);
        free(pMem: v39);
      }
      break;
    default:
      break;
  }
  CChoreoEvent::SnapTimes(this: event);
  CChoreoView::PushRedo(this, description: "Edit Event");
  if ( !this->m_bSuppressLayout )
  {
    m_pScene = this->m_pScene;
    if ( m_pScene != nullptr )
    {
      v43 = CChoreoScene::FindStopTime(this: m_pScene);
      dta = v43;
      if ( v43 < 5.0 )
        dta = 5.0;
      v44 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v45 = this->m_pScene;
      if ( v45 != nullptr )
        TimeZoom = CChoreoScene::GetTimeZoom(this: v45, tool: v44);
      else
        TimeZoom = 100;
      v42 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                       * (float)(dta + 5.0));
    }
    else
    {
      v42 = 0;
    }
    if ( v42 != this->m_nLastHPixelsNeeded )
      CChoreoView::RepositionHSlider(this);
    v47 = 0;
    for ( i = 0; i < this->m_SceneActors.m_Size; ++i )
    {
      v49 = this->m_SceneActors.m_Memory.m_pMemory[i];
      if ( v49 != nullptr )
        v47 += v49->GetItemHeight(this: v49) + 2;
    }
    if ( v47 + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
      CChoreoView::RepositionVSlider(this);
    v50 = this->m_pScene;
    if ( v50 != nullptr )
    {
      CChoreoScene::ReconcileGestureTimes(this: v50);
      CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
    }
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435CE0
// Name: public: void CChoreoView::EnableSelectedEvents(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::EnableSelectedEvents(CChoreoView *this, bool state)
{
  bool m_bDirty; // zf
  CChoreoEventWidget *m_pClickedEvent; // ecx
  int v5; // esi
  CChoreoActorWidget *v6; // edi
  CAudioMixerWave *v7; // eax
  CChoreoChannelWidget *v8; // esi
  char *v9; // edi
  CAudioSourceWave *Event; // esi
  char *Header; // eax
  int k; // edi
  CChoreoGlobalEventWidget **m_pMemory; // ecx
  TimelineItem *v14; // esi
  CChoreoEvent *Actor; // eax
  CChoreoScene *m_pScene; // ecx
  int v17; // eax
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v20; // ecx
  int TimeZoom; // eax
  int v22; // esi
  int m; // edi
  CChoreoActorWidget *v24; // ecx
  CChoreoScene *v25; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  CChoreoChannelWidget *channel; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  CChoreoActorWidget *a; // [esp+Ch] [ebp-Ch]
  const char *desc; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]
  float statea; // [esp+20h] [ebp+8h]

  if ( this->m_pScene != nullptr )
  {
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    if ( CChoreoView::CountSelectedEvents(this) == 0 )
    {
      m_pClickedEvent = this->m_pClickedEvent;
      if ( m_pClickedEvent != nullptr )
        m_pClickedEvent->SetSelected(this: m_pClickedEvent, a2: true);
    }
    desc = "Enable Events";
    if ( !state )
      desc = "Disable Events";
    CChoreoView::PushUndo(this, description: desc);
    v5 = 0;
    for ( i = 0; v5 < this->m_SceneActors.m_Size; i = v5 )
    {
      v6 = this->m_SceneActors.m_Memory.m_pMemory[v5];
      a = v6;
      if ( v6 != nullptr )
      {
        j = 0;
        if ( CChoreoWidgetDrawHelper::GetHeight(this: v6) > 0 )
        {
          do
          {
            v7 = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v6, num: j);
            v8 = (CChoreoChannelWidget *)v7;
            channel = (CChoreoChannelWidget *)v7;
            if ( v7 != nullptr )
            {
              v9 = (char *)&CAudioMixerWave::GetChannel(this: v7)[-1].pitch + 3;
              if ( (int)v9 >= 0 )
              {
                while ( 1 )
                {
                  Event = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v8, num: (int)v9);
                  if ( Event->IsLooped(this: Event) )
                  {
                    Header = CAudioSourceWave::GetHeader(this: Event);
                    CChoreoEvent::SetActive(this: (CChoreoEvent *)Header, state);
                  }
                  if ( (int)--v9 < 0 )
                    break;
                  v8 = channel;
                }
              }
              v6 = a;
            }
            ++j;
          }
          while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v6) );
          v5 = i;
        }
      }
      ++v5;
    }
    for ( k = 0; k < this->m_SceneGlobalEvents.m_Size; ++k )
    {
      m_pMemory = this->m_SceneGlobalEvents.m_Memory.m_pMemory;
      v14 = (TimelineItem *)m_pMemory[k];
      if ( v14 != nullptr
        && ((unsigned __int8 (__thiscall *)(CChoreoGlobalEventWidget *))v14->__vftable[3].Draw)(a1: m_pMemory[k]) != 0 )
      {
        Actor = (CChoreoEvent *)CActorBitmapButton::GetActor(this: v14);
        CChoreoEvent::SetActive(this: Actor, state);
      }
    }
    CChoreoView::PushRedo(this, description: desc);
    if ( !this->m_bSuppressLayout )
    {
      m_pScene = this->m_pScene;
      if ( m_pScene != nullptr )
      {
        StopTime = CChoreoScene::FindStopTime(this: m_pScene);
        statea = StopTime;
        if ( StopTime < 5.0 )
          statea = 5.0;
        Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
        v20 = this->m_pScene;
        if ( v20 != nullptr )
          TimeZoom = CChoreoScene::GetTimeZoom(this: v20, tool: Name);
        else
          TimeZoom = 100;
        v17 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                         * (float)(statea + 5.0));
      }
      else
      {
        v17 = 0;
      }
      if ( v17 != this->m_nLastHPixelsNeeded )
        CChoreoView::RepositionHSlider(this);
      v22 = 0;
      for ( m = 0; v22 < this->m_SceneActors.m_Size; ++v22 )
      {
        v24 = this->m_SceneActors.m_Memory.m_pMemory[v22];
        if ( v24 != nullptr )
          m += v24->GetItemHeight(this: v24) + 2;
      }
      if ( m + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
        CChoreoView::RepositionVSlider(this);
      v25 = this->m_pScene;
      if ( v25 != nullptr )
      {
        CChoreoScene::ReconcileGestureTimes(this: v25);
        CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
      }
      redraw = this->redraw;
      this->m_bLayoutIsValid = false;
      redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435F70
// Name: public: void CChoreoView::DeleteSelectedEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DeleteSelectedEvents(CChoreoView *this)
{
  int v2; // ebx
  bool m_bDirty; // zf
  CChoreoActorWidget *v4; // esi
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v6; // ebx
  char *v7; // eax
  CAudioSourceWave *Event; // esi
  char *Header; // eax
  char *v10; // eax
  int m; // ebx
  CChoreoGlobalEventWidget **m_pMemory; // ecx
  TimelineItem *v13; // esi
  CChoreoEvent *Actor; // eax
  CChoreoScene *m_pScene; // ecx
  CChoreoScene *v16; // ecx
  int v17; // eax
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v20; // ecx
  int TimeZoom; // eax
  int v22; // ebx
  int n; // esi
  CChoreoActorWidget *v24; // ecx
  CChoreoScene *v25; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // edx
  char *endtime; // [esp+4h] [ebp-28h]
  float oldstoptime; // [esp+14h] [ebp-18h]
  CChoreoActorWidget *a; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  float ia; // [esp+1Ch] [ebp-10h]
  int j; // [esp+20h] [ebp-Ch]
  int k; // [esp+24h] [ebp-8h]
  int deleteCount; // [esp+28h] [ebp-4h]

  v2 = 0;
  if ( this->m_pScene != nullptr )
  {
    m_bDirty = this->m_bDirty;
    this->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    CChoreoView::PushUndo(this, description: "Delete Events");
    deleteCount = 0;
    oldstoptime = CChoreoScene::FindStopTime(this: this->m_pScene);
    i = 0;
    if ( this->m_SceneActors.m_Size > 0 )
    {
      do
      {
        v4 = this->m_SceneActors.m_Memory.m_pMemory[v2];
        a = v4;
        if ( v4 != nullptr )
        {
          j = 0;
          if ( CChoreoWidgetDrawHelper::GetHeight(this: v4) > 0 )
          {
            do
            {
              Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v4, num: j);
              v6 = (CChoreoChannelWidget *)Channel;
              if ( Channel != nullptr )
              {
                v7 = (char *)&CAudioMixerWave::GetChannel(this: Channel)[-1].pitch + 3;
                k = (int)v7;
                if ( (int)v7 >= 0 )
                {
                  while ( 1 )
                  {
                    Event = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v6, num: (int)v7);
                    if ( Event->IsLooped(this: Event) )
                    {
                      endtime = CAudioSourceWave::GetHeader(this: Event);
                      Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v6);
                      CChoreoChannel::RemoveEvent(this: (CChoreoChannel *)Header, event: (CChoreoEvent *)endtime);
                      v10 = CAudioSourceWave::GetHeader(this: Event);
                      CChoreoScene::DeleteReferencedObjects(this: this->m_pScene, event: (CChoreoEvent *)v10);
                      ++deleteCount;
                    }
                    if ( --k < 0 )
                      break;
                    v7 = (char *)k;
                  }
                  v4 = a;
                }
              }
              ++j;
            }
            while ( j < CChoreoWidgetDrawHelper::GetHeight(this: v4) );
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < this->m_SceneActors.m_Size );
    }
    for ( m = 0; m < this->m_SceneGlobalEvents.m_Size; ++m )
    {
      m_pMemory = this->m_SceneGlobalEvents.m_Memory.m_pMemory;
      v13 = (TimelineItem *)m_pMemory[m];
      if ( v13 != nullptr
        && ((unsigned __int8 (__thiscall *)(CChoreoGlobalEventWidget *))v13->__vftable[3].Draw)(a1: m_pMemory[m]) != 0 )
      {
        Actor = (CChoreoEvent *)CActorBitmapButton::GetActor(this: v13);
        CChoreoScene::DeleteReferencedObjects(this: this->m_pScene, event: Actor);
        ++deleteCount;
      }
    }
    CChoreoView::DeleteSceneWidgets(this);
    m_pScene = this->m_pScene;
    if ( m_pScene != nullptr )
      CChoreoScene::ResetSimulation(this: m_pScene, forward: true, starttime: 0.0, endtime: 0.0);
    PhonemeEditor::ClearEvent(this: g_pPhonemeEditor);
    ExpressionTool::LayoutItems(this: g_pExpressionTool, force: true);
    g_pExpressionTool->redraw(this: g_pExpressionTool);
    g_pGestureTool->redraw(this: g_pGestureTool);
    g_pRampTool->redraw(this: g_pRampTool);
    g_pSceneRampTool->redraw(this: g_pSceneRampTool);
    CChoreoView::CreateSceneWidgets(this);
    CChoreoView::PushRedo(this, description: "Delete Events");
    Con_Printf(fmt: "Deleted <%i> events\n", deleteCount);
    if ( CChoreoScene::FindStopTime(this: this->m_pScene) != oldstoptime )
    {
      this->m_nLastHPixelsNeeded = -1;
      this->m_nLastVPixelsNeeded = -1;
    }
    if ( !this->m_bSuppressLayout )
    {
      v16 = this->m_pScene;
      if ( v16 != nullptr )
      {
        StopTime = CChoreoScene::FindStopTime(this: v16);
        ia = StopTime;
        if ( StopTime < 5.0 )
          ia = 5.0;
        Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
        v20 = this->m_pScene;
        if ( v20 != nullptr )
          TimeZoom = CChoreoScene::GetTimeZoom(this: v20, tool: Name);
        else
          TimeZoom = 100;
        v17 = (int)(float)((float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)
                         * (float)(ia + 5.0));
      }
      else
      {
        v17 = 0;
      }
      if ( v17 != this->m_nLastHPixelsNeeded )
        CChoreoView::RepositionHSlider(this);
      v22 = 0;
      for ( n = 0; n < this->m_SceneActors.m_Size; ++n )
      {
        v24 = this->m_SceneActors.m_Memory.m_pMemory[n];
        if ( v24 != nullptr )
          v22 += v24->GetItemHeight(this: v24) + 2;
      }
      if ( v22 + this->m_nStartRow + this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 30 != this->m_nLastVPixelsNeeded )
        CChoreoView::RepositionVSlider(this);
      v25 = this->m_pScene;
      if ( v25 != nullptr )
      {
        CChoreoScene::ReconcileGestureTimes(this: v25);
        CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
      }
      redraw = this->redraw;
      this->m_bLayoutIsValid = false;
      redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004362D0
// Name: public: bool CChoreoView::CreateAnimationEvent(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoView::CreateAnimationEvent(CChoreoView *this, int mx, int my, CChoreoChannel *animationname)
{
  HWND Handle; // eax
  int v6; // eax
  int v7; // eax
  CChoreoActorWidget *ChannelUnderCursorPos; // eax
  CChoreoActorWidget *ActorUnderCursorPos; // eax
  CChoreoActorWidget *v10; // edi
  int v12; // [esp-24h] [ebp-25Ch]
  int y; // [esp-20h] [ebp-258h]
  ChoiceText text; // [esp+Ch] [ebp-22Ch] BYREF
  CChoiceParams params; // [esp+8Ch] [ebp-1ACh] BYREF
  tagPOINT pt; // [esp+230h] [ebp-8h] BYREF

  if ( animationname == nullptr )
    return 0;
  if ( LOBYTE(animationname->m_pActor) == 0 )
    return 0;
  pt.y = my;
  pt.x = mx;
  Handle = (HWND)mxWidget::getHandle(this);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  if ( pt.x < 0 )
    return 0;
  if ( pt.y < 0 )
    return 0;
  v6 = mxWidget::w2(this);
  if ( pt.x > v6 )
    return 0;
  v7 = mxWidget::h2(this);
  if ( pt.y > v7 )
    return 0;
  y = pt.y;
  v12 = pt.x - this->m_nLabelWidth;
  pt.x = v12;
  this->m_nClickedX = v12;
  CChoreoView::GetObjectsUnderMouse(
    this,
    mx: v12,
    my: y,
    actor: &this->m_pClickedActor,
    channel: &this->m_pClickedChannel,
    event: &this->m_pClickedEvent,
    globalevent: &this->m_pClickedGlobalEvent,
    clickedTag: &this->m_nClickedTag,
    absolutetag: &this->m_pClickedAbsoluteTag,
    clickedCCArea: &this->m_nClickedChannelCloseCaptionButton);
  ChannelUnderCursorPos = CChoreoView::GetChannelUnderCursorPos(this, mx: pt.x, my: pt.y);
  if ( ChannelUnderCursorPos == nullptr )
  {
    ActorUnderCursorPos = CChoreoView::GetActorUnderCursorPos(this, mx: pt.x, my: pt.y);
    v10 = ActorUnderCursorPos;
    if ( ActorUnderCursorPos == nullptr )
      return 0;
    if ( CChoreoWidgetDrawHelper::GetHeight(this: ActorUnderCursorPos) == 0 )
      return 0;
    ChannelUnderCursorPos = (CChoreoActorWidget *)CChoreoActorWidget::GetChannel(this: v10, num: 0);
    if ( ChannelUnderCursorPos == nullptr )
      return 0;
  }
  if ( CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)ChannelUnderCursorPos) == nullptr )
    return 0;
  CChoiceParams::CChoiceParams(this: &params);
  strcpy(params.m_szDialogTitle, "Create Animation Event");
  strcpy(text.choice, "gesture");
  params.m_bPositionDialog = false;
  params.m_nLeft = 0;
  params.m_nTop = 0;
  strcpy(params.m_szPrompt, "Type of event:");
  params.m_Choices.m_Size = 0;
  params.m_nSelected = 0;
  CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int>>::InsertBefore(this: &params.m_Choices, elem: 0, src: &text);
  strcpy(text.choice, "sequence");
  CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int>>::InsertBefore(
    this: &params.m_Choices,
    elem: params.m_Choices.m_Size,
    src: &text);
  if ( ChoiceProperties(&params) == 0 || params.m_nSelected < 0 )
  {
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&params.m_Choices);
    return 0;
  }
  if ( params.m_nSelected == 1 )
    CChoreoView::AddEvent(this, type: SEQUENCE, subtype: 0, defaultparameters: animationname);
  else
    CChoreoView::AddEvent(this, type: GESTURE, subtype: 0, defaultparameters: animationname);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&params.m_Choices);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00436540
// Name: public: bool CChoreoView::CreateExpressionEvent(int,int,class CExpClass __near *,class CExpression __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoView::CreateExpressionEvent(CChoreoView *this, int mx, int my, CExpClass *cl, CExpression *exp)
{
  HWND Handle; // eax
  int v8; // eax
  int v9; // eax
  CChoreoActorWidget *ChannelUnderCursorPos; // eax
  CChoreoActorWidget *ActorUnderCursorPos; // eax
  CChoreoActorWidget *v12; // edi
  char *Header; // ebx
  CChoreoEvent *v14; // edi
  bool v15; // al
  const char *Name; // eax
  CChoreoActor *Actor; // eax
  tagPOINT pt; // [esp+20h] [ebp-8h] BYREF
  float starttime; // [esp+30h] [ebp+8h]

  if ( this->m_pScene == nullptr )
    return 0;
  if ( exp == nullptr )
    return 0;
  pt.y = my;
  pt.x = mx;
  Handle = (HWND)mxWidget::getHandle(this);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  if ( pt.x < 0 )
    return 0;
  if ( pt.y < 0 )
    return 0;
  v8 = mxWidget::w2(this);
  if ( pt.x > v8 )
    return 0;
  v9 = mxWidget::h2(this);
  if ( pt.y > v9 )
    return 0;
  ChannelUnderCursorPos = CChoreoView::GetChannelUnderCursorPos(this, mx: pt.x, my: pt.y);
  if ( ChannelUnderCursorPos == nullptr )
  {
    ActorUnderCursorPos = CChoreoView::GetActorUnderCursorPos(this, mx: pt.x, my: pt.y);
    v12 = ActorUnderCursorPos;
    if ( ActorUnderCursorPos == nullptr )
      return 0;
    if ( CChoreoWidgetDrawHelper::GetHeight(this: ActorUnderCursorPos) == 0 )
      return 0;
    ChannelUnderCursorPos = (CChoreoActorWidget *)CChoreoActorWidget::GetChannel(this: v12, num: 0);
    if ( ChannelUnderCursorPos == nullptr )
      return 0;
  }
  Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)ChannelUnderCursorPos);
  if ( Header == nullptr )
    return 0;
  v14 = CChoreoScene::AllocEvent(this: this->m_pScene);
  if ( v14 == nullptr )
    return 0;
  v15 = !this->m_bDirty;
  starttime = (float)((float)((float)(pt.x - this->m_nLabelWidth)
                            / (float)(this->m_rcTimeLine.right - this->m_nLabelWidth))
                    * (float)(this->m_flEndTime - this->m_flStartTime))
            + this->m_flStartTime;
  this->m_bDirty = true;
  if ( v15 )
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  CChoreoView::PushUndo(this, description: "Create Expression");
  CChoreoEvent::SetType(this: v14, type: (CChoreoEvent::EVENTTYPE)2);
  CChoreoEvent::SetName(this: v14, name: exp->name);
  Name = CExpClass::GetName(this: cl);
  CChoreoEvent::SetParameters(this: v14, param: Name);
  CChoreoEvent::SetParameters2(this: v14, param: exp->name);
  CChoreoEvent::SetStartTime(this: v14, starttime);
  CChoreoEvent::SetChannel(this: v14, channel: (CChoreoChannel *)Header);
  Actor = CChoreoChannel::GetActor(this: (CChoreoChannel *)Header);
  CChoreoEvent::SetActor(this: v14, actor: Actor);
  CChoreoEvent::SetEndTime(this: v14, endtime: starttime + 1.0);
  CChoreoEvent::SnapTimes(this: v14);
  CChoreoView::DeleteSceneWidgets(this);
  CChoreoChannel::AddEvent(this: (CChoreoChannel *)Header, event: v14);
  CChoreoView::CreateSceneWidgets(this);
  CChoreoView::PushRedo(this, description: "Create Expression");
  CChoreoView::InvalidateLayout(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00436750
// Name: public: void CChoreoView::DeleteEventRelativeTag(class CChoreoEvent __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::DeleteEventRelativeTag(CChoreoView *this, CChoreoEvent *event, int tagnum)
{
  CEventAbsoluteTag *RelativeTag; // edi
  bool m_bDirty; // zf
  const char *Name; // eax

  if ( event != nullptr )
  {
    RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: event, tagnum);
    if ( RelativeTag != nullptr )
    {
      m_bDirty = this->m_bDirty;
      this->m_bDirty = true;
      if ( !m_bDirty )
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      CChoreoView::PushUndo(this, description: "Delete Event Tag");
      Name = CEventAbsoluteTag::GetName(this: RelativeTag);
      CChoreoEvent::RemoveRelativeTag(this: event, tagname: Name);
      CChoreoScene::ReconcileTags(this: this->m_pScene);
      CChoreoView::PushRedo(this, description: "Delete Event Tag");
      g_pPhonemeEditor->redraw(this: g_pPhonemeEditor);
      CChoreoView::InvalidateLayout(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004367E0
// Name: public: void CChoreoView::AddEventRelativeTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::AddEventRelativeTag(CChoreoView *this)
{
  CChoreoEventWidget *m_pClickedEvent; // edi
  char *Header; // ebx
  bool m_bDirty; // zf
  CInputParams params; // [esp+10h] [ebp-5A0h] BYREF
  tagRECT bounds; // [esp+59Ch] [ebp-14h]
  float frac; // [esp+5ACh] [ebp-4h]

  m_pClickedEvent = this->m_pClickedEvent;
  if ( m_pClickedEvent != nullptr )
  {
    Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)m_pClickedEvent);
    if ( CChoreoEvent::GetEndTime(this: (CChoreoEvent *)Header) == 0.0 )
    {
      Con_ErrorPrintf(fmt: "Event Tag:  Can only tag events with an end time\n");
    }
    else
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      strcpy(params.m_szDialogTitle, "Event Tag Name");
      strcpy(params.m_szPrompt, "Name:");
      params.m_szInputText[0] = 0;
      if ( InputProperties(&params) != 0 )
      {
        if ( strlen(params.m_szInputText) != 0 )
        {
          bounds = *m_pClickedEvent->getBounds(this: m_pClickedEvent);
          frac = 0.0;
          if ( bounds.right - bounds.left > 0 )
          {
            frac = (float)(this->m_nClickedX - bounds.left) / (float)(bounds.right - bounds.left);
            if ( frac <= 1.0 )
            {
              if ( frac < 0.0 )
                frac = 0.0;
            }
            else
            {
              frac = 1.0;
            }
          }
          m_bDirty = this->m_bDirty;
          this->m_bDirty = true;
          if ( !m_bDirty )
            IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
          CChoreoView::PushUndo(this, description: "Add Event Tag");
          CChoreoEvent::AddRelativeTag(this: (CChoreoEvent *)Header, tagname: params.m_szInputText, percentage: frac);
          CChoreoView::PushRedo(this, description: "Add Event Tag");
          CChoreoView::InvalidateLayout(this);
          g_pPhonemeEditor->redraw(this: g_pPhonemeEditor);
          g_pExpressionTool->redraw(this: g_pExpressionTool);
          g_pGestureTool->redraw(this: g_pGestureTool);
          g_pRampTool->redraw(this: g_pRampTool);
          g_pSceneRampTool->redraw(this: g_pSceneRampTool);
        }
        else
        {
          Con_ErrorPrintf(fmt: "Event Tag Name:  No name entered!\n");
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004369F0
// Name: public: bool CChoreoView::ValidateCombinedSoundCheckSum(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoView::ValidateCombinedSoundCheckSum(CChoreoView *this, CChoreoEvent *e)
{
  const char *CloseCaptionToken; // eax
  CChoreoChannel *Channel; // eax
  const char *v7; // eax
  const char *v8; // eax
  bool v9; // bl
  const char *v10; // eax
  bool v11; // bl
  const char *v12; // [esp-8h] [ebp-230h]
  char outfilename[512]; // [esp+Ch] [ebp-21Ch] BYREF
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > eventList; // [esp+20Ch] [ebp-1Ch] BYREF
  bool genderwildcard; // [esp+230h] [ebp+8h]

  if ( e == nullptr || CChoreoEvent::GetType(this: e) != SPEAK )
    return false;
  genderwildcard = CChoreoEvent::IsCombinedUsingGenderToken(this: e);
  _V_memset(dest: outfilename, fill: 0, count: 512);
  if ( !CChoreoEvent::ComputeCombinedBaseFileName(
          this: e,
          dest: outfilename,
          destlen: 512,
          creategenderwildcard: genderwildcard) )
  {
    CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
    Con_ErrorPrintf(fmt: "Unable to regenerate wav file name for combined sound (%s)\n", CloseCaptionToken);
    return false;
  }
  eventList.m_LessFunc = ChoreEventStartTimeLessFunc;
  memset(&eventList.m_Elements, 0, sizeof(eventList.m_Elements));
  *(_DWORD *)&eventList.m_Root = 0xFFFF;
  *(_DWORD *)&eventList.m_FirstFree = -1;
  eventList.m_pElements = nullptr;
  v12 = CChoreoEvent::GetCloseCaptionToken(this: e);
  Channel = CChoreoEvent::GetChannel(this: e);
  if ( CChoreoChannel::GetSortedCombinedEventList(this: Channel, cctoken: v12, events: &eventList) )
  {
    v8 = CChoreoEvent::GetCloseCaptionToken(this: e);
    if ( genderwildcard )
    {
      v9 = CChoreoView::ValidateCombinedFileCheckSum(
             this,
             outfilename,
             cctoken: v8,
             gender: GENDER_MALE,
             sorted: &eventList);
      v10 = CChoreoEvent::GetCloseCaptionToken(this: e);
      v11 = CChoreoView::ValidateCombinedFileCheckSum(
              this,
              outfilename,
              cctoken: v10,
              gender: GENDER_FEMALE,
              sorted: &eventList)
         && v9;
    }
    else
    {
      v11 = CChoreoView::ValidateCombinedFileCheckSum(
              this,
              outfilename,
              cctoken: v8,
              gender: GENDER_NONE,
              sorted: &eventList);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eventList);
    return v11;
  }
  else
  {
    v7 = CChoreoEvent::GetCloseCaptionToken(this: e);
    Con_ErrorPrintf(fmt: "Unable to generated combined event list (%s)\n", v7);
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eventList);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436C40
// Name: public: CChoreoView::CChoreoView(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CChoreoView *__userpurge CChoreoView::CChoreoView@<eax>(
        CChoreoView *this@<ecx>,
        int a2@<edi>,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        int id)
{
  mxScrollbar *v9; // eax
  mxScrollbar *v10; // eax
  mxScrollbar *v11; // eax
  mxScrollbar *v12; // eax
  mxBitmapButton *v13; // eax
  mxBitmapButton *v14; // eax
  mxBitmapButton *v15; // eax
  mxBitmapButton *v16; // eax
  mxBitmapButton *v17; // eax
  mxBitmapButton *v18; // eax
  mxSlider *v19; // eax
  mxSlider *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  bool h_3; // [esp+33h] [ebp+1Bh]

  mxWindow::mxWindow(this, parent, x, y, w, h, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "CChoreoView",
    displaynameroot: "Choreography");
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&IChoreoEventCallback::`vftable';
  this->mxWindow::mxWidget::__vftable = (CChoreoView_vtbl *)&CChoreoView::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&CChoreoView::`vftable'{for `IFacePoserToolWindow'};
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&CChoreoView::`vftable'{for `IChoreoEventCallback'};
  this->m_SceneActors.m_Memory.m_pMemory = nullptr;
  this->m_SceneActors.m_Memory.m_nAllocationCount = 0;
  this->m_SceneActors.m_Memory.m_nGrowSize = 0;
  this->m_SceneActors.m_Size = 0;
  this->m_SceneActors.m_pElements = nullptr;
  this->m_SceneGlobalEvents.m_Memory.m_pMemory = nullptr;
  this->m_SceneGlobalEvents.m_Memory.m_nAllocationCount = 0;
  this->m_SceneGlobalEvents.m_Memory.m_nGrowSize = 0;
  this->m_SceneGlobalEvents.m_Size = 0;
  this->m_SceneGlobalEvents.m_pElements = nullptr;
  this->m_FocusRects.m_Memory.m_pMemory = nullptr;
  this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  this->m_FocusRects.m_Memory.m_nGrowSize = 0;
  this->m_FocusRects.m_Size = 0;
  this->m_FocusRects.m_pElements = nullptr;
  this->m_UndoStack.m_Memory.m_pMemory = nullptr;
  this->m_UndoStack.m_Memory.m_nAllocationCount = 0;
  this->m_UndoStack.m_Memory.m_nGrowSize = 0;
  this->m_UndoStack.m_Size = 0;
  this->m_UndoStack.m_pElements = nullptr;
  this->m_nextFileList.m_Memory.m_pMemory = nullptr;
  this->m_nextFileList.m_Memory.m_nAllocationCount = 0;
  this->m_nextFileList.m_Memory.m_nGrowSize = 0;
  this->m_nextFileList.m_Size = 0;
  this->m_nextFileList.m_pElements = nullptr;
  this->m_bForceProcess = false;
  *(_WORD *)&this->m_bSuppressLayout = 1;
  IFacePoserToolWindow::SetAutoProcess(this: &this->IFacePoserToolWindow, autoprocess: true);
  this->m_flLastMouseClickTime = -1.0;
  this->m_flPlaybackRate = 1.0;
  this->m_pScene = nullptr;
  this->m_flScrub = 0.0;
  this->m_flScrubTarget = 0.0;
  this->m_bCanDraw = false;
  *(_WORD *)&this->m_bRedoPending = 256;
  this->m_nUndoLevel = 0;
  CChoreoEventWidget::LoadImages();
  CChoreoWidget::m_pView = this;
  mxWidget::setId(this, id);
  this->m_flLastSpeedScale = 0.0;
  this->m_nTopOffset = 0;
  this->m_flLeftOffset = 0.0;
  this->m_nLastHPixelsNeeded = -1;
  this->m_nLastVPixelsNeeded = -1;
  this->m_nStartRow = 45;
  this->m_nLabelWidth = 140;
  this->m_nRowHeight = 35;
  *(_WORD *)&this->m_bSimulating = 0;
  this->m_bForward = true;
  this->m_flStartTime = 0.0;
  this->m_flEndTime = 0.0;
  this->m_flFrameTime = 0.0;
  *(_WORD *)&this->m_bResetSpeedScale = 0;
  this->m_nAutomatedAction = 0;
  this->m_flAutomationDelay = 0.0;
  this->m_flAutomationTime = 0.0;
  v9 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxScrollbar::mxScrollbar(this: v9, parent: this, x: 0, y: 0, w: 18, h: 100, id: 5003, style: 1);
  else
    v10 = nullptr;
  this->m_pVertScrollBar = v10;
  v11 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    v12 = mxScrollbar::mxScrollbar(this: v11, parent: this, x: 0, y: 0, w: 18, h: 100, id: 5004, style: 0);
  else
    v12 = nullptr;
  this->m_pHorzScrollBar = v12;
  this->m_bLayoutIsValid = false;
  this->m_flPixelsPerSecond = 150.0;
  v13 = (mxBitmapButton *)operator new(nSize: 0x1Cu);
  if ( v13 != nullptr )
    v14 = mxBitmapButton::mxBitmapButton(
            this: v13,
            parent: this,
            x: 2,
            y: 4,
            w: 16,
            h: 16,
            id: 5001,
            bitmap: "gfx/hlfaceposer/play.bmp");
  else
    v14 = nullptr;
  this->m_btnPlay = v14;
  v15 = (mxBitmapButton *)operator new(nSize: 0x1Cu);
  if ( v15 != nullptr )
    v16 = mxBitmapButton::mxBitmapButton(
            this: v15,
            parent: this,
            x: 18,
            y: 4,
            w: 16,
            h: 16,
            id: 5002,
            bitmap: "gfx/hlfaceposer/pause.bmp");
  else
    v16 = nullptr;
  this->m_btnPause = v16;
  v17 = (mxBitmapButton *)operator new(nSize: 0x1Cu);
  if ( v17 != nullptr )
    v18 = mxBitmapButton::mxBitmapButton(
            this: v17,
            parent: this,
            x: 34,
            y: 4,
            w: 16,
            h: 16,
            id: 5000,
            bitmap: "gfx/hlfaceposer/stop.bmp");
  else
    v18 = nullptr;
  this->m_btnStop = v18;
  v19 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v19 != nullptr )
    v20 = mxSlider::mxSlider(this: v19, parent: this, x: 0, y: 0, w: 16, h: 16, id: 5050, style: 0);
  else
    v20 = nullptr;
  this->m_pPlaybackRate = v20;
  mxSlider::setRange(this: v20, min: 0.0, max: 2.0, ticks: 40);
  mxSlider::setValue(this: this->m_pPlaybackRate, value: this->m_flPlaybackRate);
  mxWidget::setVisible(this: this->m_btnPlay, b: false);
  mxWidget::setVisible(this: this->m_btnPause, b: false);
  mxWidget::setVisible(this: this->m_btnStop, b: false);
  mxWidget::setVisible(this: this->m_pPlaybackRate, b: false);
  this->m_nFontSize = 12;
  *(_DWORD *)&this->m_ActorExpanded[0].expanded = 16843009;
  *(_DWORD *)&this->m_ActorExpanded[4].expanded = 16843009;
  *(_DWORD *)&this->m_ActorExpanded[8].expanded = 16843009;
  *(_DWORD *)&this->m_ActorExpanded[12].expanded = 16843009;
  *(_DWORD *)&this->m_ActorExpanded[16].expanded = 16843009;
  *(_DWORD *)&this->m_ActorExpanded[20].expanded = 16843009;
  *(_DWORD *)&this->m_ActorExpanded[24].expanded = 16843009;
  *(_DWORD *)&this->m_ActorExpanded[28].expanded = 16843009;
  CChoreoView::SetChoreoFile(this, filename: defaultValue);
  if ( workspacefiles->GetNumStoredFiles(this: workspacefiles, a2: 1) >= 1 )
  {
    v21 = workspacefiles->GetStoredFile(this: workspacefiles, a2: 1, a3: 0);
    CChoreoView::LoadSceneFromFile(this, a2: 0, a3: a2, filename: v21);
  }
  this->m_rgABPoints[0] = 0;
  this->m_rgABPoints[1] = 0;
  this->m_nCurrentABPoint = 0;
  this->m_pClickedActor = nullptr;
  this->m_pClickedChannel = nullptr;
  this->m_pClickedEvent = nullptr;
  this->m_pClickedGlobalEvent = nullptr;
  this->m_nClickedX = 0;
  this->m_nClickedY = 0;
  this->m_nSelectedEvents = 0;
  this->m_nClickedTag = -1;
  this->m_nClickedChannelCloseCaptionButton = 0;
  this->m_bDragging = false;
  this->m_xStart = 0;
  this->m_yStart = 0;
  this->m_nDragType = 0;
  this->m_hPrevCursor = nullptr;
  this->m_nMinX = 0;
  this->m_nMaxX = 0;
  this->m_bUseBounds = false;
  this->m_nScrollbarHeight = 12;
  this->m_nInfoHeight = 30;
  *(_QWORD *)&this->m_Flyover.a = 0;
  *(_QWORD *)&this->m_Flyover.e = 0;
  *(_QWORD *)&this->m_Flyover.tag = 0;
  this->m_Flyover.ccbutton = 0;
  h_3 = this->m_bDirty;
  this->m_bDirty = false;
  CChoreoView::WipeUndo(this);
  this->redraw(this);
  if ( h_3 )
  {
    v22 = "* ";
    if ( !this->m_bDirty )
      v22 = defaultValue;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: v22);
  }
  this->m_bSuppressLayout = false;
  this->m_bScrubSeconds = 0;
  this->m_bCanDraw = true;
  this->m_flScrubberTimeOffset = 0.0;
  this->m_bShowCloseCaptionData = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00437190
// Name: public: virtual CChoreoView::~CChoreoView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::~CChoreoView(CChoreoView *this)
{
  this->mxWindow::mxWidget::__vftable = (CChoreoView_vtbl *)&CChoreoView::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&CChoreoView::`vftable'{for `IFacePoserToolWindow'};
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&CChoreoView::`vftable'{for `IChoreoEventCallback'};
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &this->m_nextFileList);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_UndoStack);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FocusRects);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SceneGlobalEvents);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SceneActors);
  IFacePoserToolWindow::~IFacePoserToolWindow(this: &this->IFacePoserToolWindow);
  mxWindow::~mxWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437200
// Name: public: void CChoreoView::AssociateModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::AssociateModel(CChoreoView *this)
{
  CChoreoView *v1; // esi
  CChoreoActorWidget *m_pClickedActor; // ecx
  int v3; // edi
  const char *v4; // eax
  CChoreoActor *Name; // eax
  bool m_bDirty; // zf
  const char *v7; // [esp-8h] [ebp-240h]
  ChoiceText text; // [esp+8h] [ebp-230h] BYREF
  CChoiceParams params; // [esp+88h] [ebp-1B0h] BYREF
  int c; // [esp+22Ch] [ebp-Ch]
  CChoreoView *v11; // [esp+230h] [ebp-8h]
  CChoreoActor *a; // [esp+234h] [ebp-4h]

  v1 = this;
  v11 = this;
  if ( this->m_pScene != nullptr )
  {
    m_pClickedActor = this->m_pClickedActor;
    if ( m_pClickedActor != nullptr )
    {
      a = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)m_pClickedActor);
      if ( a != nullptr )
      {
        strcpy(params.m_szDialogTitle, "Associate Model");
        memset(&params.m_Choices, 0, sizeof(params.m_Choices));
        params.m_bPositionDialog = false;
        params.m_nLeft = 0;
        params.m_nTop = 0;
        strcpy(params.m_szPrompt, "Choose model:");
        params.m_nSelected = -1;
        v3 = 0;
        c = models->Count(this: models);
        if ( c > 0 )
        {
          do
          {
            v4 = models->GetModelName(this: models, a2: v3);
            strcpy(text.choice, v4);
            v7 = v4;
            Name = CChoreoActor::GetName(this: a);
            if ( _V_stricmp(s1: Name->m_szName, s2: v7) == 0 )
              params.m_nSelected = v3;
            CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int>>::InsertBefore(
              this: &params.m_Choices,
              elem: params.m_Choices.m_Size,
              src: &text);
            ++v3;
          }
          while ( v3 < c );
          v1 = v11;
        }
        qmemcpy(&text, "No Associated Mo", 16);
        *(_DWORD *)&text.choice[16] = &g_flexedverts[43904].y;
        CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int>>::InsertBefore(
          this: &params.m_Choices,
          elem: params.m_Choices.m_Size,
          src: &text);
        if ( ChoiceProperties(&params) != 0 && params.m_nSelected != -1 )
        {
          if ( params.m_nSelected >= 0 && params.m_nSelected < params.m_Choices.m_Size )
          {
            CChoreoView::AssociateModelToActor(this: v1, actor: a, modelindex: params.m_nSelected);
            CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&params.m_Choices);
            return;
          }
          m_bDirty = v1->m_bDirty;
          v1->m_bDirty = true;
          if ( !m_bDirty )
            IFacePoserToolWindow::SetPrefix(this: &v1->IFacePoserToolWindow, prefix: "* ");
          CChoreoView::PushUndo(this: v1, description: "Associate model");
          CChoreoActor::SetFacePoserModelName(this: a, name: defaultValue);
          CChoreoView::RecomputeWaves(this: v1);
          CChoreoView::PushRedo(this: v1, description: "Associate model");
        }
        CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&params.m_Choices);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437400
// Name: public: void CChoreoView::MouseStartDrag(class mxEvent __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::MouseStartDrag(CChoreoView *this, float event, int mx, int my)
{
  bool m_bDirty; // zf
  CChoreoWidget **p_m_pClickedGlobalEvent; // ebx
  CChoreoWidget **p_m_pClickedEvent; // edi
  CChoreoEvent *Header; // ebx
  int v9; // eax
  bool v10; // al
  CChoreoWidget_vtbl *v11; // ebx
  bool v12; // al
  char *v13; // eax
  __int32 v14; // eax
  __int32 v15; // eax
  CChoreoWidget *v16; // ecx
  CChoreoWidget_vtbl *v17; // edi
  bool v18; // al
  mxEvent *v19; // edi
  bool IsMouseOverScrubHandle; // al
  float m_flStartTime; // xmm1_4
  int m_nLabelWidth; // ecx
  __int64 v23; // xmm0_8
  int x_low; // eax
  float v25; // xmm1_4
  double v26; // st7
  CChoreoView_vtbl *v27; // eax
  void (__thiscall *redraw)(struct CChoreoView *); // edx
  HWND Handle; // eax
  int v30; // ecx
  HCURSOR CursorA; // eax
  int v32; // eax
  void (__thiscall *v33)(struct CChoreoView *); // edx
  int v34; // ebx
  int m_nClickedChannelCloseCaptionButton; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  float v39; // xmm0_4
  int m_Size; // [esp-10h] [ebp-58h]
  tagRECT rcScrub; // [esp+4h] [ebp-44h] BYREF
  tagRECT rcHandle; // [esp+14h] [ebp-34h] BYREF
  tagRECT rcFocus; // [esp+24h] [ebp-24h] BYREF
  tagPOINT pt; // [esp+34h] [ebp-14h] BYREF
  float v45; // [esp+3Ch] [ebp-Ch]
  CChoreoEvent *e; // [esp+40h] [ebp-8h] BYREF
  bool isrightbutton; // [esp+47h] [ebp-1h]

  m_bDirty = !this->m_bDragging;
  isrightbutton = (*(_DWORD *)(LODWORD(event) + 32) & 2) != 0;
  if ( m_bDirty )
  {
    p_m_pClickedGlobalEvent = &this->m_pClickedGlobalEvent;
    p_m_pClickedEvent = &this->m_pClickedEvent;
    CChoreoView::GetObjectsUnderMouse(
      this,
      mx,
      my,
      actor: &this->m_pClickedActor,
      channel: &this->m_pClickedChannel,
      event: &this->m_pClickedEvent,
      globalevent: &this->m_pClickedGlobalEvent,
      clickedTag: &this->m_nClickedTag,
      absolutetag: &this->m_pClickedAbsoluteTag,
      clickedCCArea: &this->m_nClickedChannelCloseCaptionButton);
    if ( this->m_pClickedEvent != nullptr )
    {
      Header = (CChoreoEvent *)CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)this->m_pClickedEvent);
      e = Header;
      v9 = CChoreoView::ComputeEventDragType(this, mx, my);
      v10 = v9 == 5 || v9 == 3;
      if ( (*(_BYTE *)(LODWORD(event) + 40) & 3) != 0 )
      {
        if ( !v10 )
        {
          v11 = (*p_m_pClickedEvent)->__vftable;
          v12 = v11->IsSelected(this: *p_m_pClickedEvent);
          v11->SetSelected(this: *p_m_pClickedEvent, a2: !v12);
          Header = e;
        }
      }
      else
      {
        if ( !(*p_m_pClickedEvent)->IsSelected(this: *p_m_pClickedEvent) )
        {
          CChoreoView::TraverseWidgets(this, pfn: CChoreoView::Deselect, param1: nullptr, param1a: nullptr);
          this->redraw(this);
        }
        CChoreoView::TraverseWidgets(this, pfn: CChoreoView::Select, param1: nullptr, param1a: *p_m_pClickedEvent);
      }
      v13 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)*p_m_pClickedEvent);
      v14 = CChoreoEvent::GetType(this: (CChoreoEvent *)v13) - 5;
      if ( v14 != 0 )
      {
        v15 = v14 - 1;
        if ( v15 != 0 )
        {
          if ( v15 == 4 )
          {
            ExpressionTool::SetEvent(this: g_pExpressionTool, event: Header);
            FlexPanel::SetEvent(this: g_pFlexPanel, event: Header);
          }
        }
        else
        {
          GestureTool::SetEvent(this: g_pGestureTool, event: Header);
        }
      }
      else
      {
        CWaveBrowser::SetEvent(
          this: (CWaveBrowser *)`CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements,
          event: Header);
      }
      if ( CChoreoEvent::CurveHasEndTime(this: Header) )
        RampTool::SetEvent(this: g_pRampTool, event: Header);
LABEL_27:
      this->redraw(this);
      CChoreoView::StartDraggingEvent(this, mx, my);
LABEL_57:
      CChoreoView::CalcBounds(this, movetype: this->m_nDragType);
      return;
    }
    v16 = *p_m_pClickedGlobalEvent;
    if ( *p_m_pClickedGlobalEvent != nullptr )
    {
      if ( (*(_BYTE *)(LODWORD(event) + 40) & 3) != 0 )
      {
        v17 = v16->__vftable;
        v18 = v16->IsSelected(this: v16);
        v17->SetSelected(this: *p_m_pClickedGlobalEvent, a2: !v18);
      }
      else
      {
        if ( !v16->IsSelected(this: v16) )
          CChoreoView::DeselectAll(this);
        CChoreoView::TraverseWidgets(this, pfn: CChoreoView::Select, param1: nullptr, param1a: *p_m_pClickedGlobalEvent);
      }
      goto LABEL_27;
    }
    v19 = (mxEvent *)LODWORD(event);
    if ( CChoreoView::IsMouseOverScrubArea(this, event: (mxEvent *)LODWORD(event)) )
    {
      IsMouseOverScrubHandle = CChoreoView::IsMouseOverScrubHandle(this, a2: (int)v19, event: v19);
      m_flStartTime = this->m_flStartTime;
      if ( IsMouseOverScrubHandle )
      {
        m_nLabelWidth = this->m_nLabelWidth;
        *(_QWORD *)&rcFocus.left = *(_QWORD *)&this->m_rcTimeLine.left;
        v23 = *(_QWORD *)&this->m_rcTimeLine.right;
        this->m_nDragType = 8;
        this->m_bDragging = true;
        x_low = SLOWORD(v19->x);
        *(_QWORD *)&rcFocus.right = v23;
        *(float *)&v23 = (float)((float)((float)(x_low - m_nLabelWidth) / (float)(v23 - m_nLabelWidth))
                               * (float)(this->m_flEndTime - m_flStartTime))
                       + m_flStartTime;
        v25 = this->m_flScrub - *(float *)&v23;
        v45 = *(float *)&v23;
        this->m_flScrubberTimeOffset = v25;
        v26 = 20.0 / CChoreoView::GetPixelsPerSecond(this);
        event = v26;
        *(float *)&e = -v26;
        event = clamp<float,float,float>(val: &this->m_flScrubberTimeOffset, minVal: (const float *)&e, maxVal: &event);
        v27 = this->mxWindow::mxWidget::__vftable;
        this->m_flScrubberTimeOffset = event;
        *(float *)&v23 = event + v45;
        redraw = v27->redraw;
        this->m_flScrub = event + v45;
        LODWORD(this->m_flScrubTarget) = v23;
        this->m_bPaused = false;
        redraw(this);
        CChoreoView::GetScrubHandleRect(this, a2: (int)&this->m_flScrubberTimeOffset, &rcHandle, clipped: true);
        CUtlVector<CChoreoView::CFocusRect,CUtlMemory<CChoreoView::CFocusRect,int>>::Purge(this: &this->m_FocusRects);
        rcFocus.top = CChoreoView::GetStartRow(this);
        rcFocus.bottom = mxWidget::h2(this) - this->m_nInfoHeight - this->m_nScrollbarHeight;
        rcFocus.left = (rcHandle.right + rcHandle.left) / 2;
        rcFocus.right = rcFocus.left;
        pt = 0;
        Handle = (HWND)mxWidget::getHandle(this);
        ClientToScreen(hWnd: Handle, lpPoint: &pt);
        OffsetRect(lprc: &rcFocus, dx: pt.x, dy: pt.y);
        m_Size = this->m_FocusRects.m_Size;
        rcHandle = rcFocus;
        rcScrub = rcFocus;
        CUtlVector<PhonemeEditor::CFocusRect,CUtlMemory<PhonemeEditor::CFocusRect,int>>::InsertBefore(
          this: &this->m_FocusRects,
          elem: m_Size,
          src: (const CChoreoView::CFocusRect *)&rcScrub);
        v30 = my;
        this->m_xStart = mx;
        this->m_yStart = v30;
        CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
        this->m_hPrevCursor = SetCursor(hCursor: CursorA);
        CChoreoView::DrawFocusRect(this);
      }
      else
      {
        v32 = this->m_nLabelWidth;
        rcHandle = this->m_rcTimeLine;
        v33 = this->redraw;
        this->m_flScrubTarget = (float)((float)((float)(mx - v32) / (float)(rcHandle.right - v32))
                                      * (float)(this->m_flEndTime - m_flStartTime))
                              + m_flStartTime;
        this->m_bPaused = false;
        v33(this);
      }
      goto LABEL_57;
    }
    v34 = mx;
    if ( CChoreoView::IsMouseOverSceneEndTime(this, mx) )
    {
      this->redraw(this);
      CChoreoView::StartDraggingSceneEndTime(this, mx: v34, my);
      goto LABEL_57;
    }
    if ( this->m_pClickedChannel != nullptr )
    {
      m_nClickedChannelCloseCaptionButton = this->m_nClickedChannelCloseCaptionButton;
      if ( m_nClickedChannelCloseCaptionButton != 0 && m_nClickedChannelCloseCaptionButton != 5 )
      {
        v36 = m_nClickedChannelCloseCaptionButton - 2;
        if ( v36 != 0 )
        {
          v37 = v36 - 1;
          if ( v37 != 0 )
          {
            if ( v37 != 1 )
            {
              CChoreoView::OnToggleCloseCaptionTags(this);
              goto LABEL_57;
            }
            m_bDirty = this->m_bDirty;
            this->m_bDirty = true;
            if ( !m_bDirty )
              IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
            CChoreoView::PushUndo(this, description: "Change selector");
            CChoreoChannelWidget::HandleSelectorClicked(this: this->m_pClickedChannel);
            CChoreoView::PushRedo(this, description: "Change selector");
LABEL_56:
            this->redraw(this);
            goto LABEL_57;
          }
          v38 = GetCloseCaptionLanguageId() + 1;
          if ( v38 >= 12 )
            v38 = 0;
        }
        else
        {
          v38 = GetCloseCaptionLanguageId() - 1;
          if ( v38 < 0 )
            v38 = 11;
        }
        SetCloseCaptionLanguageId(id: v38, force: false);
        goto LABEL_56;
      }
    }
    if ( (v19->modifiers & 3) != 0 )
      goto LABEL_57;
    CChoreoView::DeselectAll(this);
    if ( !isrightbutton )
    {
      if ( realtime - this->m_flLastMouseClickTime >= 0.300000011920929 )
      {
        v39 = realtime;
      }
      else
      {
        CChoreoView::OnDoubleClicked(this);
        v39 = -1.0;
      }
      this->m_flLastMouseClickTime = v39;
    }
    goto LABEL_56;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437970
// Name: public: void CChoreoView::ImportVCDFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ImportVCDFile(CChoreoView *this, char *filename)
{
  CChoreoView *v2; // esi
  CChoreoScene *Scene; // ebx
  int v4; // edi
  CChoreoActorWidget *v5; // ebx
  CAudioMixerWave *Channel; // eax
  CChoreoChannelWidget *v7; // edi
  int v8; // ebx
  CAudioSourceWave *Event; // eax
  int v10; // eax
  UtlRBTreeNode_t<CChoreoEvent *,int> *m_pMemory; // ecx
  int v12; // edx
  unsigned int v13; // esi
  int v14; // edx
  CChoreoEvent **p_m_Data; // eax
  int v16; // edi
  bool m_bDirty; // zf
  CChoreoActorWidget *v18; // ebx
  CAudioMixerWave *v19; // eax
  CChoreoChannelWidget *v20; // edi
  int v21; // ebx
  CAudioSourceWave *v22; // eax
  CAudioSourceWave *v23; // esi
  int v24; // edi
  CChoreoScene *m_pScene; // ecx
  int v26; // eax
  double StopTime; // st7
  const char *Name; // eax
  CChoreoScene *v29; // ecx
  int TimeZoom; // eax
  int v31; // ebx
  int k; // edi
  CChoreoActorWidget *v33; // ecx
  CChoreoScene *v34; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  CUtlRBTree<CChoreoEvent *,int,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,int>,int> > oldEvents; // [esp+Ch] [ebp-44h] BYREF
  CChoreoActorWidget *actor; // [esp+30h] [ebp-20h]
  CChoreoEvent *insert; // [esp+34h] [ebp-1Ch] BYREF
  int parent; // [esp+38h] [ebp-18h] BYREF
  CChoreoScene *merge; // [esp+3Ch] [ebp-14h]
  CChoreoView *v41; // [esp+40h] [ebp-10h]
  int j; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  bool leftchild; // [esp+4Fh] [ebp-1h] BYREF

  v2 = this;
  v41 = this;
  Scene = CChoreoView::LoadScene(this, filename);
  v4 = 0;
  merge = Scene;
  if ( Scene != nullptr )
  {
    CChoreoView::TraverseWidgets(this: v2, pfn: CChoreoView::Deselect, param1: nullptr, param1a: nullptr);
    v2->redraw(this: v2);
    oldEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))CDefOps<CChoreoEvent *>::LessFunc;
    memset(&oldEvents.m_Elements, 0, sizeof(oldEvents.m_Elements));
    oldEvents.m_Root = -1;
    oldEvents.m_NumElements = 0;
    oldEvents.m_FirstFree = -1;
    oldEvents.m_LastAlloc.index = -1;
    oldEvents.m_pElements = nullptr;
    i = 0;
    if ( v2->m_SceneActors.m_Size > 0 )
    {
      do
      {
        v5 = v2->m_SceneActors.m_Memory.m_pMemory[v4];
        actor = v5;
        if ( v5 != nullptr )
        {
          j = 0;
          if ( CChoreoWidgetDrawHelper::GetHeight(this: v5) > 0 )
          {
            do
            {
              Channel = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v5, num: j);
              v7 = (CChoreoChannelWidget *)Channel;
              if ( Channel != nullptr )
              {
                v8 = 0;
                if ( (int)CAudioMixerWave::GetChannel(this: Channel) > 0 )
                {
                  do
                  {
                    Event = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v7, num: v8);
                    if ( Event != nullptr )
                    {
                      insert = (CChoreoEvent *)CAudioSourceWave::GetHeader(this: Event);
                      parent = -1;
                      leftchild = false;
                      CUtlRBTree<CChoreoEvent *,int,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,int>,int>>::FindInsertionPosition(
                        this: &oldEvents,
                        &insert,
                        &parent,
                        &leftchild);
                      v10 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
                              this: (CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *)&oldEvents,
                              a2: (const char *)v7);
                      m_pMemory = oldEvents.m_Elements.m_pMemory;
                      v12 = parent;
                      v13 = v10;
                      oldEvents.m_Elements.m_pMemory[v13].m_Parent = parent;
                      m_pMemory[v13].m_Right = -1;
                      m_pMemory[v13].m_Left = -1;
                      m_pMemory[v13].m_Tag = 0;
                      if ( v12 == -1 )
                      {
                        oldEvents.m_Root = v10;
                      }
                      else
                      {
                        v14 = v12;
                        if ( leftchild )
                          m_pMemory[v14].m_Left = v10;
                        else
                          m_pMemory[v14].m_Right = v10;
                      }
                      CUtlRBTree<CChoreoEvent *,int,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,int>,int>>::InsertRebalance(
                        this: &oldEvents,
                        elem: v10);
                      ++oldEvents.m_NumElements;
                      p_m_Data = &oldEvents.m_Elements.m_pMemory[v13].m_Data;
                      v2 = v41;
                      if ( p_m_Data != nullptr )
                        *p_m_Data = insert;
                    }
                    ++v8;
                  }
                  while ( v8 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v7) );
                }
                v5 = actor;
              }
              v16 = ++j;
            }
            while ( v16 < CChoreoWidgetDrawHelper::GetHeight(this: v5) );
            v4 = i;
          }
        }
        i = ++v4;
      }
      while ( v4 < v2->m_SceneActors.m_Size );
      Scene = merge;
      v4 = 0;
    }
    m_bDirty = v2->m_bDirty;
    v2->m_bDirty = true;
    if ( !m_bDirty )
      IFacePoserToolWindow::SetPrefix(this: &v2->IFacePoserToolWindow, prefix: "* ");
    CChoreoView::PushUndo(this: v2, description: "Merge/Import VCD");
    CChoreoScene::Merge(this: v2->m_pScene, other: Scene);
    CChoreoView::PushRedo(this: v2, description: "Merge/Import VCD");
    CChoreoView::DeleteSceneWidgets(this: v2);
    CChoreoView::CreateSceneWidgets(this: v2);
    v2->m_nLastHPixelsNeeded = -1;
    v2->m_nLastVPixelsNeeded = -1;
    i = 0;
    if ( v2->m_SceneActors.m_Size > 0 )
    {
      do
      {
        v18 = v2->m_SceneActors.m_Memory.m_pMemory[v4];
        actor = v18;
        if ( v18 != nullptr )
        {
          j = 0;
          if ( CChoreoWidgetDrawHelper::GetHeight(this: v18) > 0 )
          {
            do
            {
              v19 = (CAudioMixerWave *)CChoreoActorWidget::GetChannel(this: v18, num: j);
              v20 = (CChoreoChannelWidget *)v19;
              if ( v19 != nullptr )
              {
                v21 = 0;
                if ( (int)CAudioMixerWave::GetChannel(this: v19) > 0 )
                {
                  do
                  {
                    v22 = (CAudioSourceWave *)CChoreoChannelWidget::GetEvent(this: v20, num: v21);
                    v23 = v22;
                    if ( v22 != nullptr )
                    {
                      insert = (CChoreoEvent *)CAudioSourceWave::GetHeader(this: v22);
                      if ( CUtlRBTree<CChoreoEvent *,int,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,int>,int>>::Find(
                             this: &oldEvents,
                             search: &insert) == -1 )
                        ((void (__thiscall *)(CAudioSourceWave *, int))v23->IsStreaming)(a1: v23, a2: 1);
                    }
                    ++v21;
                  }
                  while ( v21 < (int)CAudioMixerWave::GetChannel(this: (CAudioMixerWave *)v20) );
                  v2 = v41;
                }
                v18 = actor;
              }
              v24 = ++j;
            }
            while ( v24 < CChoreoWidgetDrawHelper::GetHeight(this: v18) );
            v4 = i;
          }
        }
        i = ++v4;
      }
      while ( v4 < v2->m_SceneActors.m_Size );
      Scene = merge;
    }
    if ( !v2->m_bSuppressLayout )
    {
      m_pScene = v2->m_pScene;
      if ( m_pScene != nullptr )
      {
        StopTime = CChoreoScene::FindStopTime(this: m_pScene);
        *(float *)&actor = StopTime;
        if ( StopTime < 5.0 )
          *(float *)&actor = 5.0;
        Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&v2->IFacePoserToolWindow);
        v29 = v2->m_pScene;
        if ( v29 != nullptr )
          TimeZoom = CChoreoScene::GetTimeZoom(this: v29, tool: Name);
        else
          TimeZoom = 100;
        v26 = (int)(float)((float)((float)((float)TimeZoom * v2->m_flPixelsPerSecond) * 0.0099999998)
                         * (float)(*(float *)&actor + 5.0));
      }
      else
      {
        v26 = 0;
      }
      if ( v26 != v2->m_nLastHPixelsNeeded )
        CChoreoView::RepositionHSlider(this: v2);
      v31 = 0;
      for ( k = 0; k < v2->m_SceneActors.m_Size; ++k )
      {
        v33 = v2->m_SceneActors.m_Memory.m_pMemory[k];
        if ( v33 != nullptr )
          v31 += v33->GetItemHeight(this: v33) + 2;
      }
      if ( v31 + v2->m_nStartRow + v2->GetCaptionHeight(this: &v2->IFacePoserToolWindow) + 30 != v2->m_nLastVPixelsNeeded )
        CChoreoView::RepositionVSlider(this: v2);
      v34 = v2->m_pScene;
      if ( v34 != nullptr )
      {
        CChoreoScene::ReconcileGestureTimes(this: v34);
        CChoreoScene::ReconcileCloseCaption(this: v2->m_pScene);
      }
      redraw = v2->redraw;
      v2->m_bLayoutIsValid = false;
      redraw(this: v2);
      Scene = merge;
    }
    Con_Printf(fmt: "Imported vcd '%s'\n", filename);
    CChoreoScene::~CChoreoScene(this: Scene);
    free(pMem: Scene);
    v2->redraw(this: v2);
    CUtlRBTree<CChoreoEvent *,int,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,int>,int>>::RemoveAll(this: &oldEvents);
    if ( oldEvents.m_Elements.m_nGrowSize >= 0 && oldEvents.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: oldEvents.m_Elements.m_pMemory);
  }
  else
  {
    Con_Printf(fmt: "Couldn't load from .vcd %s\n", filename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437E00
// Name: public: void CChoreoView::ImportVCD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::ImportVCD(CChoreoView *this)
{
  char scenefile[512]; // [esp+4h] [ebp-200h] BYREF

  if ( this->m_pScene != nullptr
    && this->m_pClickedActor != nullptr
    && this->m_pClickedChannel != nullptr
    && FacePoser_ShowOpenFileNameDialog(relative: scenefile, bufsize: 0x200u, subdir: "scenes", wildcard: "*.vcd") )
  {
    CChoreoView::ImportVCDFile(this, filename: scenefile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437E60
// Name: private: void CChoreoView::OnCombineSpeakEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChoreoView::OnCombineSpeakEvents(CChoreoView *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  int v4; // edi
  CChoreoEvent *v5; // esi
  CChoreoChannel *Channel; // eax
  bool m_bDirty; // zf
  int m_Size; // edi
  CChoreoScene *m_pScene; // ecx
  void (__thiscall *redraw)(struct CChoreoView *); // eax
  int v11; // ebx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // edi
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // dx
  unsigned __int16 v15; // cx
  int v16; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v18; // esi
  int v19; // edx
  ISoundEmitterSystemBase_vtbl *v20; // esi
  const char *Parameters; // eax
  CChoreoEvent *m_Data; // esi
  bool v23; // di
  ISoundEmitterSystemBase_vtbl *v24; // edi
  const char *v25; // eax
  int v26; // eax
  const char *v27; // eax
  const char *v28; // esi
  int v29; // eax
  HWND__ *Handle; // eax
  CChoreoView *v31; // esi
  const char *v32; // [esp-Ch] [ebp-2840h]
  char v34[4096]; // [esp+8h] [ebp-282Ch] BYREF
  char v35[2048]; // [esp+1008h] [ebp-182Ch] BYREF
  CInputParams dst; // [esp+1808h] [ebp-102Ch] BYREF
  char pSrc[512]; // [esp+1D94h] [ebp-AA0h] BYREF
  CAddSoundParams params; // [esp+1F94h] [ebp-8A0h] BYREF
  CCloseCaptionLookupParams pDest; // [esp+2324h] [ebp-510h] BYREF
  char dest[64]; // [esp+27B0h] [ebp-84h] BYREF
  CChoreoView *v41; // [esp+27F0h] [ebp-44h]
  unsigned __int16 parent[2]; // [esp+27F4h] [ebp-40h] BYREF
  CChoreoEvent *insert; // [esp+27F8h] [ebp-3Ch] BYREF
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sorted; // [esp+27FCh] [ebp-38h] BYREF
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > events; // [esp+2818h] [ebp-1Ch] BYREF
  bool using_gender[4]; // [esp+282Ch] [ebp-8h]
  bool leftchild; // [esp+2833h] [ebp-1h] BYREF

  v3 = 0;
  v41 = this;
  if ( this->m_pScene == nullptr )
    return;
  *(_DWORD *)using_gender = 0;
  memset(&events, 0, sizeof(events));
  CChoreoView::GetSelectedEvents(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&events);
  v4 = events.m_Size - 1;
  if ( events.m_Size - 1 < 0 )
  {
LABEL_9:
    if ( events.m_Size < 2 )
    {
      Con_ErrorPrintf(fmt: "Can't combine events, must have at least two events selected.\n");
      goto LABEL_11;
    }
    V_strncpy(pDest: pDest.m_szDialogTitle, pSrc: "Choose Close Caption Token", maxLen: 128);
    pDest.m_bPositionDialog = false;
    pDest.m_nLeft = 0;
    pDest.m_nTop = 0;
    if ( CChoreoEvent::GetPlaybackCloseCaptionToken(this: *events.m_Memory.m_pMemory, dest, destlen: 64) )
    {
      v32 = V_stristr(pStr: dest, pSearch: "_cc") != nullptr ? va(fmt: "%s", dest) : va(fmt: "%s_cc", dest);
      V_strncpy(pDest: pDest.m_szCCToken, pSrc: v32, maxLen: 1024);
      if ( CloseCaptionLookup(params: &pDest) != 0 || pDest.m_szCCToken[0] == 0 )
      {
        if ( g_pLocalize->FindIndex(this: g_pLocalize, a2: pDest.m_szCCToken) == -1 )
        {
          memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
          V_strncpy(pDest: dst.m_szDialogTitle, pSrc: "Add Close Caption", maxLen: 128);
          V_snprintf(pDest: dst.m_szPrompt, maxLen: 256, pFormat: "Token (%s):", pDest.m_szCCToken);
          SuggestCaption(dest: v35, destlen: 0x800u, &events);
          V_snprintf(pDest: dst.m_szInputText, maxLen: 1024, pFormat: "%s", v35);
          if ( InputProperties(params: &dst) == 0 )
          {
            Con_Printf(fmt: "Combining of sound events cancelled\n");
            CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
            return;
          }
          if ( _V_strlen(str: dst.m_szInputText) == 0 )
            V_snprintf(pDest: dst.m_szInputText, maxLen: 1024, pFormat: "!!!%s", pDest.m_szCCToken);
          if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, const char *, const char *, int))filesystem->IsFileWritable)(
                 a1: &filesystem->IBaseFileSystem,
                 a2: "resource/closecaption_english.txt",
                 a3: "GAME",
                 a4: a2) == 0 )
          {
            _Warning(a1: "Forcing %s to be writable!!!\n", "resource/closecaption_english.txt");
            MakeFileWriteable(filename: "resource/closecaption_english.txt");
          }
          ((void (__thiscall *)(ILocalize *, char *, char *))g_pLocalize->ConvertANSIToUnicode)(
            a1: g_pLocalize,
            a2: dst.m_szInputText,
            a3: v34);
          g_pLocalize->AddString(
            this: g_pLocalize,
            a2: pDest.m_szCCToken,
            a3: (wchar_t *)v34,
            a4: "resource/closecaption_english.txt");
          g_pLocalize->SaveToFile(this: g_pLocalize, a2: "resource/closecaption_english.txt");
        }
        m_bDirty = this->m_bDirty;
        this->m_bDirty = true;
        if ( !m_bDirty )
          IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
        CChoreoView::PushUndo(this, description: "Combine Sound Events");
        m_Size = events.m_Size;
        if ( events.m_Size > 0 )
        {
          do
            CChoreoEvent::SetCloseCaptionToken(this: events.m_Memory.m_pMemory[v3++], token: pDest.m_szCCToken);
          while ( v3 < m_Size );
        }
        CChoreoView::PushRedo(this, description: "Combine Sound Events");
        if ( !this->m_bSuppressLayout )
        {
          if ( CChoreoView::ComputeHPixelsNeeded(this) != this->m_nLastHPixelsNeeded )
            CChoreoView::RepositionHSlider(this);
          if ( CChoreoView::ComputeVPixelsNeeded(this) != this->m_nLastVPixelsNeeded )
            CChoreoView::RepositionVSlider(this);
          m_pScene = this->m_pScene;
          if ( m_pScene != nullptr )
          {
            CChoreoScene::ReconcileGestureTimes(this: m_pScene);
            CChoreoScene::ReconcileCloseCaption(this: this->m_pScene);
          }
          redraw = this->redraw;
          this->m_bLayoutIsValid = false;
          redraw(this);
        }
        Con_Printf(fmt: "Changed %i events to use close caption token '%s'\n", m_Size, pDest.m_szCCToken);
        v11 = 0;
        v12 = nullptr;
        sorted.m_LessFunc = ChoreEventStartTimeLessFunc;
        memset(&sorted.m_Elements, 0, sizeof(sorted.m_Elements));
        *(_DWORD *)&sorted.m_Root = 0xFFFF;
        *(_DWORD *)&sorted.m_FirstFree = -1;
        sorted.m_pElements = nullptr;
        using_gender[0] = false;
        if ( events.m_Size > 0 )
        {
          do
          {
            insert = events.m_Memory.m_pMemory[v11];
            *(_DWORD *)parent = 0xFFFF;
            leftchild = false;
            CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
              this: &sorted,
              &insert,
              parent,
              &leftchild);
            v13 = CUtlRBTree<CChoreoEventWidget *,unsigned short,bool (__cdecl *)(CChoreoEventWidget * const &,CChoreoEventWidget * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEventWidget *,unsigned short>,unsigned short>>::NewNode(
                    this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&sorted,
                    a2: (const char *)v12);
            v14 = parent[0];
            v15 = v13;
            v16 = 3 * v13;
            m_pMemory = sorted.m_Elements.m_pMemory;
            v18 = 4 * v16;
            *(unsigned __int16 *)((char *)&sorted.m_Elements.m_pMemory->m_Right + v18) = -1;
            *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v18) = -1;
            *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v18) = 0;
            *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v18) = v14;
            if ( v14 == 0xFFFF )
            {
              sorted.m_Root = v15;
            }
            else
            {
              v19 = v14;
              if ( leftchild )
                m_pMemory[v19].m_Left = v15;
              else
                m_pMemory[v19].m_Right = v15;
            }
            CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
              this: &sorted,
              elem: v15);
            v12 = sorted.m_Elements.m_pMemory;
            ++sorted.m_NumElements;
            if ( (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)((char *)sorted.m_Elements.m_pMemory + v18) != (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)-8 )
              *(CChoreoEvent **)((char *)&sorted.m_Elements.m_pMemory->m_Data + v18) = insert;
            if ( !using_gender[0] )
            {
              v20 = soundemitter->__vftable;
              Parameters = CChoreoEvent::GetParameters(this: insert);
              using_gender[0] = v20->IsUsingGenderToken(this: soundemitter, a2: Parameters);
            }
            ++v11;
          }
          while ( v11 < events.m_Size );
        }
        _V_memset(dest: pSrc, fill: 0, count: 512);
        m_Data = v12[(unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sorted)].m_Data;
        v23 = using_gender[0];
        CChoreoEvent::SetCombinedUsingGenderToken(this: m_Data, using_gender: using_gender[0]);
        if ( !CChoreoEvent::ComputeCombinedBaseFileName(
                this: m_Data,
                dest: pSrc,
                destlen: 512,
                creategenderwildcard: v23) )
        {
          Con_ErrorPrintf(fmt: "Unable to regenerate wav file name for combined sound\n");
          goto LABEL_62;
        }
        v24 = soundemitter->__vftable;
        v25 = CChoreoEvent::GetParameters(this: m_Data);
        v26 = v24->GetSoundIndex(this: soundemitter, a2: v25);
        v27 = soundemitter->GetSourceFileForSound(this: soundemitter, a2: v26);
        v28 = v27;
        if ( v27 == nullptr || *v27 == 0 )
        {
          Con_ErrorPrintf(fmt: "Unable to find existing script to use for new combined sound entry.\n");
LABEL_62:
          CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sorted);
          if ( sorted.m_Elements.m_nGrowSize >= 0 && sorted.m_Elements.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Elements.m_pMemory);
          if ( events.m_Memory.m_nGrowSize >= 0 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: events.m_Memory.m_pMemory);
          return;
        }
        params.m_szWaveFile[0] = 0;
        params.m_szSoundName[0] = 0;
        params.m_szScriptName[0] = 0;
        *(_WORD *)&params.m_bAllowExistingSound = 0;
        _V_memset(dest: &params, fill: 0, count: 912);
        V_strncpy(pDest: params.m_szDialogTitle, pSrc: "Add Combined Sound Entry", maxLen: 128);
        v29 = _V_strlen(str: "sound/");
        V_strncpy(pDest: params.m_szWaveFile, pSrc: &pSrc[v29], maxLen: 256);
        V_strncpy(pDest: params.m_szScriptName, pSrc: v28, maxLen: 256);
        V_strncpy(pDest: params.m_szSoundName, pSrc: pDest.m_szCCToken, maxLen: 256);
        *(_WORD *)&params.m_bAllowExistingSound = 257;
        Handle = (HWND__ *)mxWidget::getHandle(this: g_MDLViewer);
        if ( AddSound(&params, parent: Handle) != 0 )
        {
          if ( using_gender[0] )
          {
            v31 = v41;
            CChoreoView::GenerateCombinedFile(
              this: v41,
              outfilename: pSrc,
              cctoken: pDest.m_szCCToken,
              gender: GENDER_MALE,
              &sorted);
            CChoreoView::GenerateCombinedFile(
              this: v31,
              outfilename: pSrc,
              cctoken: pDest.m_szCCToken,
              gender: GENDER_FEMALE,
              &sorted);
          }
          else
          {
            CChoreoView::GenerateCombinedFile(
              this: v41,
              outfilename: pSrc,
              cctoken: pDest.m_szCCToken,
              gender: GENDER_NONE,
              &sorted);
          }
        }
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &sorted);
      }
    }
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
    return;
  }
  while ( 1 )
  {
    v5 = events.m_Memory.m_pMemory[v4];
    if ( CChoreoEvent::GetType(this: v5) != SPEAK )
    {
      Con_ErrorPrintf(fmt: "Can't combine events, all events must be SPEAK events.\n");
      goto LABEL_11;
    }
    Channel = CChoreoEvent::GetChannel(this: v5);
    if ( *(_DWORD *)using_gender != 0 )
      break;
    *(_DWORD *)using_gender = Channel;
LABEL_7:
    if ( --v4 < 0 )
    {
      v3 = 0;
      goto LABEL_9;
    }
  }
  if ( Channel == *(CChoreoChannel **)using_gender )
    goto LABEL_7;
  Con_ErrorPrintf(fmt: "Can't combine events, all events must reside in the same channel.\n");
LABEL_11:
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
}

//------------------------------------------------------------------------------
// Address: 0x00438550
// Name: public: void CChoreoView::OnPlaceNextSpeakEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::OnPlaceNextSpeakEvent(CChoreoView *this)
{
  CChoreoEvent *v2; // esi
  CAudioSourceWave *ChannelForEvent; // eax
  ISoundEmitterSystemBase_vtbl *v4; // edx
  int (__thiscall *GetSoundCount)(ISoundEmitterSystemBase *); // eax
  int v6; // esi
  const char *v7; // eax
  CChoreoEvent *v8; // esi
  int v9; // eax
  const char *Parameters; // eax
  int v11; // ebx
  const char *v12; // eax
  bool m_bDirty; // zf
  CChoreoEvent *v14; // eax
  CChoreoEvent *v15; // esi
  CChoreoChannel *v16; // ebx
  CChoreoActor *Actor; // eax
  IFacePoserSound_vtbl *v18; // ebx
  const char *v19; // eax
  char *v20; // eax
  int v21; // eax
  void (__thiscall ***v22)(_DWORD, int); // ebx
  double v23; // st7
  CAudioSourceWave *WidgetForEvent; // eax
  float starttime; // [esp+8h] [ebp-58h]
  float starttimea; // [esp+8h] [ebp-58h]
  CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > m_SortedNames; // [esp+18h] [ebp-48h] BYREF
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > list; // [esp+3Ch] [ebp-24h] BYREF
  int c; // [esp+50h] [ebp-10h] BYREF
  char *insert; // [esp+54h] [ebp-Ch] BYREF
  CChoreoChannel *channel; // [esp+58h] [ebp-8h]
  CChoreoEvent *ev; // [esp+5Ch] [ebp-4h]

  memset(&list, 0, sizeof(list));
  CChoreoView::GetSelectedEvents(this, events: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&list);
  if ( list.m_Size == 1 )
  {
    v2 = *list.m_Memory.m_pMemory;
    ev = *list.m_Memory.m_pMemory;
    if ( CChoreoEvent::GetType(this: ev) == SPEAK )
    {
      ChannelForEvent = (CAudioSourceWave *)CChoreoView::FindChannelForEvent(this, event: v2);
      if ( ChannelForEvent != nullptr )
      {
        channel = (CChoreoChannel *)CAudioSourceWave::GetHeader(this: ChannelForEvent);
        if ( channel != nullptr )
        {
          v4 = soundemitter->__vftable;
          m_SortedNames.m_Root = -1;
          m_SortedNames.m_FirstFree = -1;
          m_SortedNames.m_LastAlloc.index = -1;
          GetSoundCount = v4->GetSoundCount;
          m_SortedNames.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))NameLessFunc;
          memset(&m_SortedNames.m_Elements, 0, sizeof(m_SortedNames.m_Elements));
          m_SortedNames.m_NumElements = 0;
          m_SortedNames.m_pElements = nullptr;
          v6 = 0;
          for ( *(float *)&c = COERCE_FLOAT(GetSoundCount(this: soundemitter)); v6 < c; ++v6 )
          {
            v7 = soundemitter->GetSoundName(this: soundemitter, a2: v6);
            if ( v7 != nullptr && *v7 != 0 )
            {
              insert = MemAlloc_StrDup(pString: v7);
              CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Insert(
                this: &m_SortedNames,
                a2: (const char *)this,
                (const char *const *)&insert);
            }
          }
          v8 = ev;
          *(float *)&c = COERCE_FLOAT(CChoreoEvent::GetParameters(this: ev));
          v9 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Find(
                 this: &m_SortedNames,
                 search: (const char *const *)&c);
          if ( v9 == -1 )
          {
            Parameters = CChoreoEvent::GetParameters(this: v8);
            _Warning(a1: "Can't place sound event, can't find '%s' in sound list\n", Parameters);
            DeleteAllAndPurge<CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>>(tree: &m_SortedNames);
          }
          else
          {
            v11 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
                    this: &m_SortedNames,
                    i: v9);
            if ( v11 == -1 )
            {
              v12 = CChoreoEvent::GetParameters(this: v8);
              _Warning(a1: "Can't place sound event, can't next sound after '%s' in sound list\n", v12);
              DeleteAllAndPurge<CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>>(tree: &m_SortedNames);
            }
            else
            {
              CChoreoView::TraverseWidgets(this, pfn: CChoreoView::Deselect, param1: nullptr, param1a: nullptr);
              this->redraw(this);
              m_bDirty = this->m_bDirty;
              this->m_bDirty = true;
              if ( !m_bDirty )
                IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
              CChoreoView::PushUndo(this, description: "Place Next Speak Event");
              v14 = CChoreoScene::AllocEvent(this: this->m_pScene);
              v15 = v14;
              if ( v14 != nullptr )
              {
                CChoreoEvent::operator=(this: v14, src: ev);
                CChoreoEvent::SetParameters(this: v15, param: m_SortedNames.m_Elements.m_pMemory[v11].m_Data);
                starttime = CChoreoEvent::GetEndTime(this: v15);
                CChoreoEvent::SetStartTime(this: v15, starttime);
                CChoreoEvent::SetResumeCondition(this: v15, resumecondition: false);
                CChoreoEvent::ClearAllRelativeTags(this: v15);
                CChoreoEvent::ClearAllTimingTags(this: v15);
                CChoreoEvent::ClearAllAbsoluteTags(this: v15, type: PLAYBACK);
                CChoreoEvent::ClearAllAbsoluteTags(this: v15, type: ORIGINAL);
                v16 = channel;
                CChoreoEvent::SetChannel(this: v15, channel);
                Actor = CChoreoChannel::GetActor(this: v16);
                CChoreoEvent::SetActor(this: v15, actor: Actor);
                v18 = sound->__vftable;
                v19 = FacePoser_TranslateSoundName(event: v15);
                v20 = va(fmt: "sound/%s", v19);
                v21 = (int)v18->LoadSound(this: sound, a2: v20);
                v22 = (void (__thiscall ***)(_DWORD, int))v21;
                if ( v21 != 0 )
                {
                  *(float *)&c = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v21 + 36))(a1: v21);
                  v23 = CChoreoEvent::GetStartTime(this: v15);
                  starttimea = v23 + *(float *)&c;
                  CChoreoEvent::SetEndTime(this: v15, endtime: starttimea);
                  (**v22)(a1: v22, a2: 1);
                }
                CChoreoView::DeleteSceneWidgets(this);
                CChoreoChannel::AddEvent(this: channel, event: v15);
                CChoreoView::CreateSceneWidgets(this);
                WidgetForEvent = CChoreoView::FindWidgetForEvent(this, event: v15);
                if ( WidgetForEvent != nullptr )
                  ((void (__thiscall *)(CAudioSourceWave *, int))WidgetForEvent->IsStreaming)(a1: WidgetForEvent, a2: 1);
                CChoreoView::InvalidateLayout(this);
              }
              CChoreoView::PushRedo(this, description: "Place Next Speak Event");
              DeleteAllAndPurge<CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>>(tree: &m_SortedNames);
            }
          }
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::~CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>(this: &m_SortedNames);
          CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&list);
        }
        else
        {
          _Warning(a1: "Can't place sound event, can't find channel for new event\n");
          CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&list);
        }
      }
      else
      {
        _Warning(a1: "Can't place sound event, can't find channel widget for event\n");
        CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&list);
      }
    }
    else
    {
      _Warning(a1: "Can't place sound event, no previous sound event selected\n");
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&list);
    }
  }
  else
  {
    _Warning(a1: "Can't place sound event, nothing selected\n");
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&list);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004388C0
// Name: public: void CChoreoView::PasteEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::PasteEvents(CChoreoView *this)
{
  if ( this->m_pScene != nullptr
    && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: "scenes/copydatavcd.txt", a3: nullptr) )
  {
    CChoreoView::ImportVCDFile(this, filename: "scenes/copydatavcd.txt");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438900
// Name: public: virtual int CChoreoView::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CChoreoView::handleEvent@<eax>(CChoreoView *this@<ecx>, double a2@<st0>, mxEvent *event)
{
  void (*BeginLock)(void); // edx
  bool (__thiscall *HandleToolEvent)(IFacePoserToolWindow *, mxEvent *); // edx
  const char *Name; // eax
  CChoreoScene *v8; // ecx
  int TimeZoom; // eax
  int v10; // ecx
  int v11; // eax
  CChoreoChannel *v12; // edi
  const char *v13; // eax
  const char *v14; // eax
  CChoreoScene *v15; // ecx
  int v16; // eax
  int x_low; // eax
  int v18; // ecx
  float m_flStartTime; // xmm1_4
  float v20; // xmm0_4
  void (__thiscall *redraw)(struct CChoreoView *); // edx
  int v22; // eax
  char *RedoDescription; // eax
  char *UndoDescription; // eax
  CChoreoScene *v25; // ecx
  CChoreoScene *m_pScene; // edi
  float v27; // xmm0_4
  CChoreoScene *v28; // edi
  int v29; // eax
  int v30; // edi
  float v31; // xmm0_4
  int v32; // ebx
  int v33; // edi
  int v34; // eax
  int action; // ecx
  CChoreoChannelWidget *v36; // ecx
  CChoreoEvent *CaptionClickedEvent; // eax
  CChoreoEvent *v38; // edi
  CChoreoView_vtbl *v39; // edx
  int height; // edi
  int MinValue; // eax
  HWND Handle; // eax
  int MaxValue; // edi
  int v44; // edi
  CChoreoActorWidget *v45; // ecx
  CChoreoActor *v46; // eax
  CChoreoActorWidget *m_pClickedActor; // ecx
  CChoreoActor *Actor; // eax
  CChoreoActorWidget *v49; // ecx
  CChoreoActor *v50; // eax
  CChoreoActorWidget *v51; // ecx
  CChoreoActor *v52; // eax
  mxWidget *widget; // ecx
  CChoreoActorWidget *v54; // eax
  mxWidget *v55; // ecx
  CChoreoActorWidget *v56; // eax
  CChoreoEventWidget *m_pClickedEvent; // ecx
  char *Header; // eax
  CChoreoEventWidget *v59; // ecx
  char *v60; // eax
  CChoreoEventWidget *v61; // ecx
  char *v62; // eax
  CChoreoGlobalEventWidget *m_pClickedGlobalEvent; // ecx
  CChoreoEvent *v64; // eax
  CChoreoGlobalEventWidget *v65; // ecx
  CChoreoEvent *v66; // eax
  CChoreoChannelWidget *m_pClickedChannel; // ecx
  char *v68; // eax
  CChoreoChannelWidget *v69; // ecx
  char *v70; // eax
  CChoreoChannelWidget *v71; // ecx
  char *v72; // eax
  CChoreoChannelWidget *v73; // ecx
  char *v74; // eax
  int m_nLabelWidth; // ecx
  int m_nClickedX; // eax
  int v77; // [esp-8h] [ebp-44h]
  int m_nClickedTag; // [esp-4h] [ebp-40h]
  CUtlVector<CChoreoEvent *,CUtlMemory<CChoreoEvent *,int> > events; // [esp+Ch] [ebp-30h] BYREF
  tagRECT m_rcTimeLine; // [esp+20h] [ebp-1Ch] OVERLAPPED BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+30h] [ebp-Ch]
  CChoreoChannel *v82; // [esp+34h] [ebp-8h]
  int iret; // [esp+38h] [ebp-4h]
  float maxtimea; // [esp+44h] [ebp+8h]
  float maxtimeb; // [esp+44h] [ebp+8h]
  float maxtime; // [esp+44h] [ebp+8h]
  float maxtimec; // [esp+44h] [ebp+8h]

  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock();
  HandleToolEvent = this->HandleToolEvent;
  iret = 0;
  v82 = (CChoreoChannel *)&this->IFacePoserToolWindow;
  if ( ((unsigned __int8 (__stdcall *)(mxEvent *))HandleToolEvent)(a1: event) != 0 )
  {
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  switch ( event->event )
  {
    case 0:
      action = event->action;
      iret = 1;
      if ( action > 5000 )
      {
        switch ( action )
        {
          case 5001:
            Con_Printf(fmt: "Commencing playback\n");
            CChoreoView::PlayScene(this, forward: true);
            goto LABEL_211;
          case 5002:
            Con_Printf(fmt: "Pausing playback\n");
            CChoreoView::PauseScene(this);
            goto LABEL_211;
          case 5003:
            switch ( event->modifiers )
            {
              case 0:
                height = mxScrollbar::getValue(this: this->m_pVertScrollBar) - 10;
                goto LABEL_119;
              case 1:
                height = mxScrollbar::getValue(this: this->m_pVertScrollBar) + 10;
                goto LABEL_115;
              case 2:
                height = mxScrollbar::getValue(this: this->m_pVertScrollBar) - 20;
LABEL_119:
                if ( height > mxScrollbar::getMinValue(this: this->m_pVertScrollBar) )
                  goto LABEL_122;
                MinValue = mxScrollbar::getMinValue(this: this->m_pVertScrollBar);
                goto LABEL_121;
              case 3:
                height = mxScrollbar::getValue(this: this->m_pVertScrollBar) + 20;
LABEL_115:
                if ( height >= mxScrollbar::getMaxValue(this: this->m_pVertScrollBar) )
                {
                  MinValue = mxScrollbar::getMaxValue(this: this->m_pVertScrollBar);
LABEL_121:
                  height = MinValue;
                }
LABEL_122:
                mxScrollbar::setValue(this: this->m_pVertScrollBar, ivalue: height);
                Handle = (HWND)mxWidget::getHandle(this: this->m_pVertScrollBar);
                InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
                this->m_nTopOffset = height;
                CChoreoView::InvalidateLayout(this);
                break;
              case 5:
                height = event->height;
                goto LABEL_122;
              default:
                goto LABEL_211;
            }
            goto LABEL_211;
          case 5004:
            switch ( event->modifiers )
            {
              case 0:
                MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 10;
                goto LABEL_126;
              case 1:
                MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 10;
                goto LABEL_131;
              case 2:
                MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 20;
LABEL_126:
                if ( MaxValue > mxScrollbar::getMinValue(this: this->m_pHorzScrollBar) )
                  goto LABEL_133;
                v44 = mxScrollbar::getMinValue(this: this->m_pHorzScrollBar);
                CChoreoView::MoveTimeSliderToPos(this, x: v44);
                break;
              case 3:
                MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 20;
LABEL_131:
                if ( MaxValue >= mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar) )
                  MaxValue = mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar);
LABEL_133:
                CChoreoView::MoveTimeSliderToPos(this, x: MaxValue);
                break;
              case 5:
                CChoreoView::MoveTimeSliderToPos(this, x: event->height);
                break;
              default:
                goto LABEL_211;
            }
            goto LABEL_211;
          case 5005:
            CChoreoView::NewActor(this);
            goto LABEL_211;
          case 5006:
            m_pClickedActor = this->m_pClickedActor;
            if ( m_pClickedActor != nullptr )
            {
              Actor = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)m_pClickedActor);
              CChoreoView::DeleteActor(this, actor: Actor);
            }
            goto LABEL_211;
          case 5007:
            v49 = this->m_pClickedActor;
            if ( v49 != nullptr )
            {
              v50 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)v49);
              CChoreoView::MoveActorUp(this, actor: v50);
            }
            goto LABEL_211;
          case 5008:
            v51 = this->m_pClickedActor;
            if ( v51 != nullptr )
            {
              v52 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)v51);
              CChoreoView::MoveActorDown(this, actor: v52);
            }
            goto LABEL_211;
          case 5009:
            v45 = this->m_pClickedActor;
            if ( v45 != nullptr )
            {
              v46 = (CChoreoActor *)CActorBitmapButton::GetActor(this: (TimelineItem *)v45);
              CChoreoView::EditActor(this, actor: v46);
            }
            goto LABEL_211;
          case 5010:
            m_pClickedEvent = this->m_pClickedEvent;
            if ( m_pClickedEvent != nullptr )
            {
              Header = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)m_pClickedEvent);
              CChoreoView::EditEvent(this, event: (CChoreoEvent *)Header);
              this->redraw(this);
            }
            goto LABEL_211;
          case 5011:
            CChoreoView::DeleteSelectedEvents(this);
            goto LABEL_211;
          case 5012:
            CChoreoView::AddEvent(this, type: (CChoreoEvent::EVENTTYPE)2, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5013:
            CChoreoView::AddEvent(this, type: GESTURE, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5014:
            CChoreoView::AddEvent(this, type: LOOKAT, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5015:
            CChoreoView::AddEvent(this, type: MOVETO, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5016:
            CChoreoView::AddEvent(this, type: SPEAK, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5017:
            CChoreoView::AddEvent(this, type: FACE, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5018:
            CChoreoView::AddEvent(this, type: FIRETRIGGER, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5019:
            CChoreoView::AddEvent(this, type: SEQUENCE, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5020:
            CChoreoView::AddEvent(this, type: GENERIC, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5021:
            CChoreoView::OnChangeScale(this);
            goto LABEL_211;
          case 5022:
            m_pClickedGlobalEvent = this->m_pClickedGlobalEvent;
            if ( m_pClickedGlobalEvent != nullptr )
            {
              v64 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)m_pClickedGlobalEvent);
              CChoreoView::EditGlobalEvent(this, event: v64);
              this->redraw(this);
            }
            goto LABEL_211;
          case 5023:
            v65 = this->m_pClickedGlobalEvent;
            if ( v65 != nullptr )
            {
              v66 = (CChoreoEvent *)CActorBitmapButton::GetActor(this: (TimelineItem *)v65);
              CChoreoView::DeleteGlobalEvent(this, event: v66);
            }
            goto LABEL_211;
          case 5024:
            CChoreoView::AddGlobalEvent(this, type: SECTION);
            goto LABEL_211;
          case 5025:
            CChoreoView::NewChannel(this);
            goto LABEL_211;
          case 5026:
            m_pClickedChannel = this->m_pClickedChannel;
            if ( m_pClickedChannel != nullptr )
            {
              v68 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)m_pClickedChannel);
              CChoreoView::EditChannel(this, channel: (CChoreoChannel *)v68);
            }
            goto LABEL_211;
          case 5027:
            v69 = this->m_pClickedChannel;
            if ( v69 != nullptr )
            {
              v70 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v69);
              CChoreoView::DeleteChannel(this, channel: (CChoreoChannel *)v70);
            }
            goto LABEL_211;
          case 5028:
            v71 = this->m_pClickedChannel;
            if ( v71 != nullptr )
            {
              v72 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v71);
              CChoreoView::MoveChannelUp(this, channel: (CChoreoChannel *)v72);
            }
            goto LABEL_211;
          case 5029:
            v73 = this->m_pClickedChannel;
            if ( v73 != nullptr )
            {
              v74 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v73);
              CChoreoView::MoveChannelDown(this, channel: (CChoreoChannel *)v74);
            }
            goto LABEL_211;
          case 5030:
            widget = event->widget;
            if ( widget != nullptr )
            {
              v54 = (CChoreoActorWidget *)CActorBitmapButton::GetActor(this: (TimelineItem *)widget);
              if ( v54 != nullptr )
                CChoreoActorWidget::ShowChannels(this: v54, show: true);
            }
            goto LABEL_211;
          case 5031:
            v55 = event->widget;
            if ( v55 != nullptr )
            {
              v56 = (CChoreoActorWidget *)CActorBitmapButton::GetActor(this: (TimelineItem *)v55);
              if ( v56 != nullptr )
                CChoreoActorWidget::ShowChannels(this: v56, show: false);
            }
            goto LABEL_211;
          case 5033:
            v61 = this->m_pClickedEvent;
            if ( v61 != nullptr && this->m_nClickedTag >= 0 )
            {
              m_nClickedTag = this->m_nClickedTag;
              v62 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v61);
              CChoreoView::DeleteEventRelativeTag(this, event: (CChoreoEvent *)v62, tagnum: m_nClickedTag);
            }
            goto LABEL_211;
          case 5034:
            CChoreoView::AddEventRelativeTag(this);
            goto LABEL_211;
          case 5035:
            CChoreoView::SelectAll(this);
            goto LABEL_211;
          case 5036:
            CChoreoView::DeselectAll(this);
            goto LABEL_211;
          case 5037:
            v59 = this->m_pClickedEvent;
            if ( v59 != nullptr )
            {
              v60 = CAudioSourceWave::GetHeader(this: (CAudioSourceWave *)v59);
              CChoreoView::MoveEventToBack(this, event: (CChoreoEvent *)v60);
            }
            goto LABEL_211;
          case 5040:
            CChoreoView::OnExpressionTool(this);
            goto LABEL_211;
          case 5041:
            CChoreoView::AssociateBSP(this);
            goto LABEL_211;
          case 5042:
            CChoreoView::AddEvent(this, type: FLEXANIMATION, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5043:
            CChoreoView::CopyEvents(this);
            goto LABEL_211;
          case 5044:
            CChoreoView::PasteEvents(this);
            this->redraw(this);
            goto LABEL_211;
          case 5045:
            CChoreoView::ImportEvents(this);
            this->redraw(this);
            goto LABEL_211;
          case 5046:
            CChoreoView::ExportEvents(this);
            this->redraw(this);
            goto LABEL_211;
          case 5047:
            CChoreoView::AddEvent(this, type: SUBSCENE, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5049:
            CChoreoView::AssociateModel(this);
            goto LABEL_211;
          case 5050:
            this->m_flPlaybackRate = mxSlider::getValue(this: this->m_pPlaybackRate);
            this->redraw(this);
            goto LABEL_211;
          case 5051:
            CChoreoView::OnCheckSequenceLengths(this, a2: (int)event);
            goto LABEL_211;
          case 5052:
            this->m_bProcessSequences = !this->m_bProcessSequences;
            goto LABEL_211;
          case 5053:
            CChoreoView::OnGestureTool(this);
            goto LABEL_211;
          case 5054:
            CChoreoView::AddGlobalEvent(this, type: LOOP);
            goto LABEL_211;
          case 5055:
            v39 = this->mxWindow::mxWidget::__vftable;
            this->m_bRampOnly = !this->m_bRampOnly;
            v39->redraw(this);
            goto LABEL_211;
          case 5056:
            CChoreoView::AddEvent(this, type: INTERRUPT, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5067:
            CChoreoView::AddGlobalEvent(this, type: STOPPOINT);
            goto LABEL_211;
          case 5068:
            CChoreoView::AddEvent(this, type: GESTURE, subtype: 1, defaultparameters: nullptr);
            goto LABEL_211;
          case 5069:
            _V_memset(dest: &m_rcTimeLine.top, fill: 0, count: 12);
            LOBYTE(m_rcTimeLine.right) = 0;
            goto LABEL_196;
          case 5070:
            _V_memset(dest: &m_rcTimeLine.top, fill: 0, count: 12);
            LOBYTE(m_rcTimeLine.right) = 1;
LABEL_196:
            m_rcTimeLine.bottom = 2;
            break;
          case 5071:
            _V_memset(dest: &m_rcTimeLine.top, fill: 0, count: 12);
            LOBYTE(m_rcTimeLine.right) = 0;
            m_rcTimeLine.bottom = 1;
            break;
          case 5072:
            _V_memset(dest: &m_rcTimeLine.top, fill: 0, count: 12);
            LOBYTE(m_rcTimeLine.right) = 1;
            m_rcTimeLine.bottom = 1;
            break;
          case 5073:
            _V_memset(dest: &m_rcTimeLine.top, fill: 0, count: 12);
            LOBYTE(m_rcTimeLine.right) = 0;
            m_rcTimeLine.bottom = 0;
            break;
          case 5074:
            _V_memset(dest: &m_rcTimeLine.top, fill: 0, count: 12);
            LOBYTE(m_rcTimeLine.right) = 1;
            m_rcTimeLine.bottom = 0;
            break;
          case 5075:
            CChoreoView::OnInsertTime(this);
            goto LABEL_211;
          case 5076:
            CChoreoView::OnDeleteTime(this);
            goto LABEL_211;
          case 5077:
            CChoreoView::ExportVCD(this);
            this->redraw(this);
            goto LABEL_211;
          case 5078:
            CChoreoView::ImportVCD(this);
            this->redraw(this);
            goto LABEL_211;
          case 5079:
            CChoreoView::AddEvent(this, type: PERMIT_RESPONSES, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          case 5080:
            CChoreoView::OnToggleCloseCaptionTags(this);
            goto LABEL_211;
          case 5081:
            CChoreoView::OnCombineSpeakEvents(this, a2: (int)event);
            goto LABEL_211;
          case 5082:
            CChoreoView::OnRemoveSpeakEventFromGroup(this);
            goto LABEL_211;
          case 5083:
            v36 = this->m_pClickedChannel;
            if ( v36 != nullptr )
            {
              CaptionClickedEvent = CChoreoChannelWidget::GetCaptionClickedEvent(this: v36);
              v38 = CaptionClickedEvent;
              if ( CaptionClickedEvent != nullptr && CChoreoEvent::GetNumSlaves(this: CaptionClickedEvent) >= 1 )
                CChoreoView::OnChangeCloseCaptionToken(this, e: v38);
            }
            goto LABEL_211;
          case 5084:
            CChoreoView::OnToggleCloseCaptionsForEvent(this);
            goto LABEL_211;
          case 5085:
            CChoreoView::OnAlign(this, a2, left: true);
            goto LABEL_211;
          case 5086:
            CChoreoView::OnAlign(this, a2, left: false);
            goto LABEL_211;
          case 5087:
            CChoreoView::OnMakeSameSize(this, a2, smallest: true);
            goto LABEL_211;
          case 5088:
            CChoreoView::OnMakeSameSize(this, a2, smallest: false);
            goto LABEL_211;
          case 5089:
            if ( this->m_pClickedChannel != nullptr )
              CChoreoView::SelectAllEventsInChannel(this, channel: this->m_pClickedChannel);
            goto LABEL_211;
          case 5090:
            if ( this->m_pClickedActor != nullptr )
              CChoreoView::SelectAllEventsInActor(this, actor: this->m_pClickedActor);
            goto LABEL_211;
          case 5091:
            CChoreoView::EnableSelectedEvents(this, state: true);
            goto LABEL_211;
          case 5092:
            CChoreoView::EnableSelectedEvents(this, state: false);
            goto LABEL_211;
          case 5093:
            CChoreoView::AddEvent(this, type: CAMERA, subtype: 0, defaultparameters: nullptr);
            goto LABEL_211;
          default:
            goto LABEL_209;
        }
        m_nLabelWidth = this->m_nLabelWidth;
        m_nClickedX = this->m_nClickedX;
        *(_QWORD *)&events.m_Memory.m_nAllocationCount = *(_QWORD *)&this->m_rcTimeLine.left;
        *(_QWORD *)&events.m_Size = *(_QWORD *)&this->m_rcTimeLine.right;
        *(float *)&m_rcTimeLine.top = (float)((float)((float)(m_nClickedX - m_nLabelWidth)
                                                    / (float)(events.m_Size - m_nLabelWidth))
                                            * (float)(this->m_flEndTime - this->m_flStartTime))
                                    + this->m_flStartTime;
        CChoreoView::SelectEvents(this, params: (CChoreoView::SelectionParams_t *)&m_rcTimeLine.top);
      }
      else
      {
        switch ( action )
        {
          case 5000:
            Con_Printf(fmt: "Canceling playback\n");
            CChoreoView::StopScene(this);
            break;
          case 1025:
            CChoreoView::Undo(this);
            break;
          case 1026:
            CChoreoView::Redo(this);
            break;
          default:
LABEL_209:
            iret = 0;
            if ( (unsigned int)(action - 5300) > 0xB )
              goto LABEL_212;
            iret = 1;
            SetCloseCaptionLanguageId(id: action - 5300, force: false);
            break;
        }
      }
LABEL_211:
      IFacePoserToolWindow::SetActiveTool(tool: (IFacePoserToolWindow *)v82);
LABEL_212:
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return iret;
    case 1:
      this->m_nLastHPixelsNeeded = -1;
      this->m_nLastVPixelsNeeded = -1;
      CChoreoView::InvalidateLayout(this);
      CChoreoView::PositionControls(this);
      iret = 1;
      goto LABEL_212;
    case 6:
      CChoreoView::MouseFinishDrag(
        this,
        event,
        mx: (CChoreoEvent *)SLOWORD(event->x),
        my: (CChoreoChannelWidget *)SLOWORD(event->y));
      iret = 1;
      goto LABEL_212;
    case 7:
      if ( this->m_bDragging )
        goto LABEL_30;
      if ( (event->buttons & 2) != 0 )
      {
        if ( CChoreoView::IsMouseOverTimeline(this, mx: SLOWORD(event->x), my: SLOWORD(event->y)) )
        {
          CChoreoView::PlaceABPoint(this, mx: SLOWORD(event->x));
          ((void (*)(void))this->redraw)();
          iret = 1;
        }
        else
        {
          if ( CChoreoView::IsMouseOverScrubArea(this, event) )
          {
            x_low = SLOWORD(event->x);
            v18 = this->m_nLabelWidth;
            m_flStartTime = this->m_flStartTime;
            m_rcTimeLine = this->m_rcTimeLine;
            v20 = (float)((float)((float)(x_low - v18) / (float)(m_rcTimeLine.right - v18))
                        * (float)(this->m_flEndTime - m_flStartTime))
                + m_flStartTime;
            this->m_flScrub = v20;
            this->m_flScrubTarget = v20;
            this->m_bPaused = false;
            sound->Flush(this: sound);
            redraw = this->redraw;
            this->m_bPaused = false;
            redraw(this);
          }
          else
          {
            CChoreoView::ShowContextMenu(this, mx: SLOWORD(event->x), my: SLOWORD(event->y));
          }
          iret = 1;
        }
      }
      else if ( CChoreoView::IsMouseOverTimeline(this, mx: SLOWORD(event->x), my: SLOWORD(event->y)) )
      {
        CChoreoView::ClearABPoints(this);
        ((void (*)(void))this->redraw)();
        iret = 1;
      }
      else
      {
        CChoreoView::MouseStartDrag(this, event: *(float *)&event, mx: SLOWORD(event->x), my: SLOWORD(event->y));
LABEL_30:
        iret = 1;
      }
      goto LABEL_212;
    case 8:
      CChoreoView::MouseMove(this, mx: SLOWORD(event->x), my: SLOWORD(event->y));
      CChoreoView::UpdateStatusArea(this, mx: SLOWORD(event->x), my: SLOWORD(event->y));
      iret = 1;
      goto LABEL_212;
    case 9:
      CChoreoView::MouseContinueDrag(this, event, mx: SLOWORD(event->x), my: SLOWORD(event->y));
      iret = 1;
      goto LABEL_212;
    case 0xB:
      v22 = event->key - 13;
      iret = 1;
      switch ( v22 )
      {
        case 0:
          memset(&events, 0, sizeof(events));
          CChoreoView::GetSelectedEvents(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&events);
          if ( events.m_Size == 1 && GetAsyncKeyState(vKey: 18) != 0 )
          {
            CChoreoView::EditEvent(this, event: *events.m_Memory.m_pMemory);
            this->redraw(this);
            iret = 1;
          }
          CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
          break;
        case 14:
          CChoreoView::DeselectAll(this);
          break;
        case 19:
          if ( this->m_bSimulating )
            CChoreoView::StopScene(this);
          break;
        case 20:
          v30 = this->m_nLabelWidth;
          v31 = this->m_flLeftOffset - (float)(mxWidget::w2(this) - v30);
          if ( v31 <= 0.0 )
            v31 = 0.0;
          goto LABEL_71;
        case 21:
          v32 = this->m_nLabelWidth;
          v33 = mxWidget::w2(this) - v32;
          v34 = CChoreoView::ComputeHPixelsNeeded(this);
          v31 = (float)v33 + this->m_flLeftOffset;
          if ( (float)v34 <= v31 )
            v31 = (float)v34;
LABEL_71:
          this->m_flLeftOffset = v31;
          CChoreoView::MoveTimeSliderToPos(this, x: (int)v31);
          break;
        case 22:
          maxtimec = CChoreoScene::FindStopTime(this: this->m_pScene) - 1.0;
          v29 = (int)(CChoreoView::GetPixelsPerSecond(this) * maxtimec);
          CChoreoView::MoveTimeSliderToPos(this, x: v29 - 1);
          break;
        case 23:
          CChoreoView::MoveTimeSliderToPos(this, x: 0);
          break;
        case 24:
          m_pScene = this->m_pScene;
          if ( m_pScene != nullptr && CChoreoScene::GetSceneFPS(this: this->m_pScene) > 0 )
          {
            maxtimea = this->m_flScrub;
            v27 = maxtimea - (float)(1.0 / (float)CChoreoScene::GetSceneFPS(this: m_pScene));
            if ( v27 <= 0.0 )
              v27 = 0.0;
            this->m_flScrubTarget = v27;
            this->m_bPaused = false;
          }
          break;
        case 26:
          v28 = this->m_pScene;
          if ( v28 != nullptr && CChoreoScene::GetSceneFPS(this: this->m_pScene) > 0 )
          {
            maxtimeb = this->m_flScrub;
            maxtime = (float)(1.0 / (float)CChoreoScene::GetSceneFPS(this: v28)) + maxtimeb;
            if ( CChoreoScene::FindStopTime(this: v28) <= (double)maxtime )
              maxtime = CChoreoScene::FindStopTime(this: v28);
            this->m_flScrubTarget = maxtime;
            this->m_bPaused = false;
          }
          break;
        case 33:
          if ( IFacePoserToolWindow::IsActiveTool(this: (IFacePoserToolWindow *)v82) )
            CChoreoView::DeleteSelectedEvents(this);
          break;
        case 54:
          CChoreoView::CopyEvents(this);
          iret = 1;
          break;
        case 56:
          if ( GetAsyncKeyState(vKey: 17) != 0 )
            CChoreoView::OnPlaceNextSpeakEvent(this);
          break;
        case 73:
          CChoreoView::PasteEvents(this);
          this->redraw(this);
          break;
        case 77:
          if ( GetAsyncKeyState(vKey: 17) != 0 )
          {
            if ( GetAsyncKeyState(vKey: 16) != 0 )
            {
              if ( this->m_nUndoLevel != this->m_UndoStack.m_Size )
              {
                RedoDescription = CChoreoView::GetRedoDescription(this);
                Con_Printf(fmt: "Redo %s\n", RedoDescription);
                CChoreoView::Redo(this);
                iret = 1;
              }
            }
            else if ( this->m_nUndoLevel != 0 )
            {
              UndoDescription = CChoreoView::GetUndoDescription(this);
              Con_Printf(fmt: "Undo %s\n", UndoDescription);
              CChoreoView::Undo(this);
              iret = 1;
            }
          }
          break;
        case 175:
          this->m_flScrubTarget = 0.0;
          this->m_bPaused = false;
          break;
        case 177:
          v25 = this->m_pScene;
          if ( v25 != nullptr )
          {
            this->m_flScrubTarget = CChoreoScene::FindStopTime(this: v25);
            this->m_bPaused = false;
          }
          break;
        default:
          iret = 0;
          break;
      }
      goto LABEL_212;
    case 0xC:
      if ( this->m_pScene != nullptr )
      {
        Name = CChoreoChannel::GetName(this: v82);
        v8 = this->m_pScene;
        if ( v8 != nullptr )
          TimeZoom = CChoreoScene::GetTimeZoom(this: v8, tool: Name);
        else
          TimeZoom = 100;
        v10 = (4 * ((event->modifiers & 2) != 0)) | 1;
        if ( event->height <= 0 )
        {
          v11 = TimeZoom - 4 * v10;
          if ( v11 <= 4 )
            v11 = 4;
        }
        else
        {
          v11 = TimeZoom + 4 * v10;
          if ( v11 >= 1000 )
            v11 = 1000;
        }
        v12 = v82;
        v77 = v11;
        v13 = CChoreoChannel::GetName(this: v82);
        CChoreoView::SetTimeZoom(this, tool: v13, tz: v77, preserveFocus: true);
        memset(&events, 0, sizeof(events));
        CChoreoView::GetSelectedEvents(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&events);
        CChoreoView::DeleteSceneWidgets(this);
        CChoreoView::CreateSceneWidgets(this);
        CChoreoView::ReselectEvents(this, list: &events);
        CChoreoView::InvalidateLayout(this);
        v14 = CChoreoChannel::GetName(this: v12);
        v15 = this->m_pScene;
        if ( v15 != nullptr )
          v16 = CChoreoScene::GetTimeZoom(this: v15, tool: v14);
        else
          v16 = 100;
        Con_Printf(fmt: "Zoom factor %i %%\n", v16);
        CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&events);
      }
      iret = 1;
      goto LABEL_212;
    default:
      goto LABEL_212;
  }
}
