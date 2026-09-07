// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/faceposer_models.cpp
// Functions: 51
// ============================================================

#include "utils\hlfaceposer\faceposer_models.h"

//------------------------------------------------------------------------------
// Address: 0x004541C0
// Name: FindPoseCycle
// Source: json
//------------------------------------------------------------------------------
int __usercall FindPoseCycle@<xmm0>(StudioModel *model@<esi>, int sequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v3; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  char *m_pModelName; // edi
  const char *KeyValueText; // eax
  KeyValues *Key; // eax
  int Int; // edi
  int v11; // eax
  float cycle; // [esp+0h] [ebp-4h]

  m_pStudioHdr = model->m_pStudioHdr;
  cycle = 0.0;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->m_MDLHandle);
    CStudioHdr::Init(this: model->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = model->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: defaultValue);
  else
    v6 = nullptr;
  m_pModelName = model->m_pModelName;
  KeyValueText = StudioModel::GetKeyValueText(this: model, iSequence: sequence);
  if ( KeyValues::LoadFromBuffer(
         this: v6,
         resourceName: m_pModelName,
         pBuffer: KeyValueText,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    Key = KeyValues::FindKey(this: v6, keyName: "faceposer", bCreate: false);
    if ( Key != nullptr )
    {
      Int = KeyValues::GetInt(this: Key, keyName: "thumbnail_frame", defaultValue: 0);
      if ( Int != 0 )
      {
        v11 = StudioModel::GetNumFrames(this: model, iSequence: sequence) - 1;
        if ( v11 > 0 )
          cycle = (float)Int / (float)v11;
      }
    }
  }
  KeyValues::deleteThis(this: v6);
  return LODWORD(cycle);
}

//------------------------------------------------------------------------------
// Address: 0x004542B0
// Name: void EnableStickySnapshotMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableStickySnapshotMode()
{
  MatSysWindow::EnableStickySnapshotMode(this: g_pMatSysWindow);
}

//------------------------------------------------------------------------------
// Address: 0x004542C0
// Name: void DisableStickySnapshotMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisableStickySnapshotMode()
{
  MatSysWindow::DisableStickySnapshotMode(this: g_pMatSysWindow);
}

//------------------------------------------------------------------------------
// Address: 0x004542D0
// Name: public: void IFaceposerModels::CFacePoserModel::Restore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::Restore(IFaceposerModels::CFacePoserModel *this)
{
  StudioModel *v2; // edi
  int v3; // eax

  v2 = g_pStudioModel;
  g_pStudioModel = this->m_pModel;
  if ( StudioModel::LoadModel(this: this->m_pModel, pModelName: this->m_pModel->m_pModelName) != 0 )
  {
    this->m_pModel->PostLoadModel(this: this->m_pModel, a2: this->m_pModel->m_pModelName);
    v3 = StudioModel::LookupSequence(this: this->m_pModel, szSequence: "idle_subtle");
    StudioModel::SetSequence(this: this->m_pModel, iSequence: v3);
  }
  g_pStudioModel = v2;
  SetupModelFlexcontrollerLinks(model: this->m_pModel);
}

//------------------------------------------------------------------------------
// Address: 0x00454350
// Name: public: virtual void IFaceposerModels::UnForceActiveModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::UnForceActiveModelIndex(IFaceposerModels *this)
{
  this->m_nForceModelIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00454360
// Name: public: virtual int IFaceposerModels::GetActiveModelIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IFaceposerModels::GetActiveModelIndex(IFaceposerModels *this)
{
  int result; // eax

  if ( g_MDLViewer == nullptr )
    return 0;
  result = this->m_nForceModelIndex;
  if ( result == -1 )
    return MDLViewer::GetActiveModelTab(this: g_MDLViewer);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00454380
// Name: public: virtual char const __near * IFaceposerModels::GetActiveModelName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IFaceposerModels::GetActiveModelName(IFaceposerModels *this)
{
  IFaceposerModels_vtbl *v3; // edi
  int v4; // eax

  if ( g_MDLViewer == nullptr )
    return nullptr;
  v3 = this->__vftable;
  v4 = this->GetActiveModelIndex(this);
  return v3->GetModelName(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004543B0
// Name: public: virtual class StudioModel __near * IFaceposerModels::GetActiveStudioModel(void)
// Source: json
//------------------------------------------------------------------------------
StudioModel *__thiscall IFaceposerModels::GetActiveStudioModel(IFaceposerModels *this)
{
  IFaceposerModels_vtbl *v2; // edi
  int v3; // eax
  StudioModel *result; // eax

  v2 = this->__vftable;
  v3 = this->GetActiveModelIndex(this);
  result = v2->GetStudioModel(this, a2: v3);
  if ( result == nullptr )
    return g_pStudioModel;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004543D0
// Name: public: virtual void IFaceposerModels::CloseAllModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CloseAllModels(IFaceposerModels *this)
{
  int i; // esi

  for ( i = this->Count(this) - 1; i >= 0; --i )
    this->FreeModel(this, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x004543F0
// Name: public: virtual class CStudioHdr __near * IFaceposerModels::GetStudioHeader(int)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall IFaceposerModels::GetStudioHeader(IFaceposerModels *this, int index)
{
  StudioModel *v2; // eax
  StudioModel *v3; // esi
  CStudioHdr *result; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *m_pStudioHdr; // esi

  v2 = this->GetStudioModel(this, a2: index);
  v3 = v2;
  if ( v2 != nullptr )
  {
    result = v2->m_pStudioHdr;
    if ( result != nullptr )
    {
      if ( result->m_pStudioHdr != nullptr )
        goto LABEL_6;
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
      CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      m_pStudioHdr = v3->m_pStudioHdr;
      if ( m_pStudioHdr->m_pStudioHdr != nullptr )
      {
        result = m_pStudioHdr;
LABEL_6:
        if ( result != nullptr )
          return result;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00454450
// Name: public: virtual void IFaceposerModels::LoadModelList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::LoadModelList(IFaceposerModels *this)
{
  int v2; // ebx
  int i; // esi
  const char *v4; // eax

  v2 = workspacefiles->GetNumStoredFiles(this: workspacefiles, a2: 2);
  for ( i = 0; i < v2; ++i )
  {
    v4 = workspacefiles->GetStoredFile(this: workspacefiles, a2: 2, a3: i);
    this->LoadModel(this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004544A0
// Name: public: void IFaceposerModels::CFacePoserModel::CreateNewBitmap(char const __near *,int,int,bool,class CExpression __near *,struct mxbitmapdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::CreateNewBitmap(
        IFaceposerModels::CFacePoserModel *this,
        const char *pchBitmapFilename,
        int sequence,
        int nSnapShotSize,
        bool bZoomInOnFace,
        CExpression *pExpression,
        mxbitmapdata_t *bitmap)
{
  StudioModel *m_pModel; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v9; // eax
  int v10; // eax
  mstudioseqdesc_t *v11; // eax
  const char *v12; // edx
  unsigned int NewAnimationLayer; // ebx
  int flCycle; // xmm0_4
  int i; // ebx
  const studiohdr_t *v16; // eax
  LocalFlexController_t v17; // ebx
  float z; // ecx
  float v19; // edx
  const mstudioattachment_t *v20; // ebx
  const matrix3x4_t *v21; // eax
  float v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // ebx
  const char *KeyValueText; // eax
  KeyValues *Key; // eax
  double Float; // st7
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  MatSysWindow *v32; // ebx
  const char *GameDirectory; // eax
  bool v34; // cl
  LocalFlexController_t v35; // ebx
  const studiohdr_t *v36; // eax
  float flexValues[384]; // [esp+18h] [ebp-8B4h] BYREF
  char fullpath[512]; // [esp+618h] [ebp-2B4h] BYREF
  matrix3x4_t attachmentPoseToLocal; // [esp+818h] [ebp-B4h] BYREF
  matrix3x4_t boneToPose; // [esp+848h] [ebp-84h] BYREF
  int j; // [esp+878h] [ebp-54h]
  QAngle oldLight; // [esp+87Ch] [ebp-50h]
  float *weights; // [esp+888h] [ebp-44h]
  QAngle oldrot; // [esp+88Ch] [ebp-40h]
  MatSysWindow *pWnd; // [esp+898h] [ebp-34h]
  Vector oldtrans; // [esp+89Ch] [ebp-30h]
  Vector maxs; // [esp+8A8h] [ebp-24h] BYREF
  int iBone; // [esp+8B4h] [ebp-18h]
  Vector mins; // [esp+8B8h] [ebp-14h] BYREF
  bool bSaveGround; // [esp+8C7h] [ebp-5h]
  float eyeheight; // [esp+8C8h] [ebp-4h] BYREF
  int flEyeheight; // [esp+8E0h] [ebp+14h]
  const char *flEyeheightb; // [esp+8E0h] [ebp+14h]
  float flEyeheightc; // [esp+8E0h] [ebp+14h]
  int flEyeheighta; // [esp+8E0h] [ebp+14h]

  pWnd = g_pMatSysWindow;
  if ( g_pMatSysWindow != nullptr )
  {
    m_pModel = this->m_pModel;
    if ( m_pModel != nullptr )
    {
      m_pStudioHdr = m_pModel->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr )
      {
        if ( m_pStudioHdr->m_pStudioHdr != nullptr
          || (v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: m_pModel->m_MDLHandle),
              CStudioHdr::Init(this: m_pModel->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr),
              (m_pStudioHdr = m_pModel->m_pStudioHdr)->m_pStudioHdr != nullptr) )
        {
          if ( m_pStudioHdr != nullptr && sequence >= 0 )
          {
            v10 = m_pStudioHdr->m_pVModel != nullptr
                ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
                : m_pStudioHdr->m_pStudioHdr->numlocalseq;
            if ( sequence < v10 )
            {
              v11 = CStudioHdr::pSeqdesc(this: m_pStudioHdr, iSequence: sequence);
              v12 = (char *)v11 + v11->szlabelindex;
              eyeheight = 1.8389699e-38;
              Con_ColorPrintf(
                rgb: (const Color *)&eyeheight,
                fmt: "Creating bitmap %s for sequence '%s'\n",
                pchBitmapFilename,
                v12);
              StudioModel::ClearOverlaysSequences(this: m_pModel);
              NewAnimationLayer = StudioModel::GetNewAnimationLayer(this: m_pModel, iPriority: 0);
              StudioModel::SetOverlaySequence(
                this: m_pModel,
                iLayer: NewAnimationLayer,
                iSequence: sequence,
                flWeight: 1.0);
              flCycle = FindPoseCycle(model: m_pModel, sequence);
              StudioModel::SetOverlayRate(
                this: m_pModel,
                iLayer: NewAnimationLayer,
                flCycle: *(float *)&flCycle,
                flPlaybackRate: 0.0);
              for ( i = 0; i < CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr); ++i )
                StudioModel::SetPoseParameter(this: m_pModel, iParameter: i, flValue: 0.0);
              memset(flexValues, 0, sizeof(flexValues));
              if ( pExpression != nullptr )
              {
                iBone = (int)CExpression::GetSettings(this: pExpression);
                weights = CExpression::GetWeights(this: pExpression);
                v16 = m_pStudioHdr->m_pStudioHdr;
                v17 = DUMMY_NULL_FLEX_CONTROLLER;
                if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
                {
                  eyeheight = 0.0;
                  do
                  {
                    j = *(int *)((char *)&v16->checksum + LODWORD(eyeheight) + v16->flexcontrollerindex);
                    if ( j != -1 )
                    {
                      flexValues[v17] = StudioModel::GetFlexController(this: m_pModel, iFlex: v17);
                      StudioModel::SetFlexController(
                        this: m_pModel,
                        iFlex: v17,
                        flValue: weights[j] * *(float *)(iBone + 4 * j));
                    }
                    v16 = m_pStudioHdr->m_pStudioHdr;
                    LODWORD(eyeheight) += 20;
                    ++v17;
                  }
                  while ( v17 < v16->numflexcontrollers );
                }
              }
              StudioModel::ClearLookTargets(this: m_pModel);
              oldrot = m_pModel->m_angles;
              oldtrans = m_pModel->m_origin;
              oldLight = g_viewerSettings.lightrot;
              m_pModel->m_angles.x = 0.0;
              m_pModel->m_angles.y = 0.0;
              m_pModel->m_angles.z = 0.0;
              m_pModel->m_origin.x = 0.0;
              m_pModel->m_origin.y = 0.0;
              m_pModel->m_origin.z = 0.0;
              g_viewerSettings.lightrot.x = 0.0;
              g_viewerSettings.lightrot.z = 0.0;
              g_viewerSettings.lightrot.y = -180.0;
              bSaveGround = g_viewerSettings.showGround;
              g_viewerSettings.showGround = false;
              if ( bZoomInOnFace )
              {
                z = m_pStudioHdr->m_pStudioHdr->hull_min.z;
                v19 = m_pStudioHdr->m_pStudioHdr->hull_max.z;
                *(_QWORD *)&maxs.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->hull_min.x;
                *(_QWORD *)&mins.x = *(_QWORD *)&maxs.x;
                maxs.z = z;
                mins.z = z;
                eyeheight = (float)(v19 - z) * 0.9 + z;
                m_pModel->m_origin.x = (float)(v19 - z) * 0.60000002;
                if ( CStudioHdr::GetNumAttachments(this: m_pStudioHdr) > 0 )
                {
                  flEyeheight = 0;
                  if ( CStudioHdr::GetNumAttachments(this: m_pStudioHdr) > 0 )
                  {
                    while ( 1 )
                    {
                      v20 = CStudioHdr::pAttachment(this: m_pStudioHdr, i: flEyeheight);
                      iBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: flEyeheight);
                      if ( _V_stricmp(s1: (const char *)v20 + v20->sznameindex, s2: "eyes") == 0 )
                      {
                        v21 = (const matrix3x4_t *)((char *)m_pStudioHdr->m_pStudioHdr
                                                  + 216 * iBone
                                                  + m_pStudioHdr->m_pStudioHdr->boneindex);
                        if ( v21 != nullptr )
                          break;
                      }
                      if ( ++flEyeheight >= CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
                        goto LABEL_28;
                    }
                    MatrixInvert(in: v21 + 2, out: &boneToPose);
                    ConcatTransforms(in1: &boneToPose, in2: &v20->local, out: &attachmentPoseToLocal);
                    VectorITransform(in1: &vec3_origin.x, in2: &attachmentPoseToLocal, out: &maxs.x);
                    v22 = m_pStudioHdr->m_pStudioHdr->hull_min.z;
                    *(_QWORD *)&mins.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->hull_min.x;
                    mins.z = v22;
                    eyeheight = v22 - maxs.z;
                  }
                }
LABEL_28:
                v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                if ( v23 != nullptr )
                  v24 = KeyValues::KeyValues(this: v23, setName: defaultValue);
                else
                  v24 = nullptr;
                flEyeheightb = m_pModel->m_pModelName;
                KeyValueText = StudioModel::GetKeyValueText(this: m_pModel, iSequence: sequence);
                if ( KeyValues::LoadFromBuffer(
                       this: v24,
                       resourceName: flEyeheightb,
                       pBuffer: KeyValueText,
                       pFileSystem: nullptr,
                       pPathID: nullptr,
                       pfnEvaluateSymbolProc: nullptr)
                  && (Key = KeyValues::FindKey(this: v24, keyName: "faceposer", bCreate: false)) != nullptr
                  && (Float = KeyValues::GetFloat(this: Key, keyName: "eye_height", defaultValue: -9999.0)) != -9999.0 )
                {
                  flEyeheightc = Float;
                  v28 = flEyeheightc;
                }
                else
                {
                  v28 = eyeheight;
                }
                m_pModel->m_origin.z = m_pModel->m_origin.z + v28;
                if ( v24 != nullptr )
                  KeyValues::deleteThis(this: v24);
              }
              else
              {
                StudioModel::ExtractBbox(this: m_pModel, a2: (int)m_pModel, &mins, &maxs);
                v29 = maxs.x - mins.x;
                v30 = maxs.z - mins.z;
                if ( (float)(maxs.y - mins.y) > (float)(maxs.x - mins.x) )
                  v29 = maxs.y - mins.y;
                if ( v30 > v29 )
                  v29 = maxs.z - mins.z;
                v31 = (float)((float)(v30 * 0.5) + mins.z) + m_pModel->m_origin.z;
                m_pModel->m_origin.x = v29 * 3.0;
                m_pModel->m_origin.z = v31;
              }
              MatSysWindow::PushSnapshotMode(this: g_pMatSysWindow, nSnapShotSize);
              v32 = pWnd;
              MatSysWindow::SuppressBufferSwap(this: pWnd, bSuppress: true);
              v32->redraw(this: v32);
              MatSysWindow::SuppressBufferSwap(this: v32, bSuppress: false);
              GameDirectory = GetGameDirectory();
              V_snprintf(pDest: fullpath, maxLen: 512, pFormat: "%s%s", GameDirectory, pchBitmapFilename);
              MatSysWindow::TakeSnapshotRect(
                this: v32,
                pFilename: fullpath,
                x: 0,
                y: 0,
                w: nSnapShotSize,
                h: nSnapShotSize);
              MatSysWindow::PopSnapshotMode(this: g_pMatSysWindow);
              v34 = bSaveGround;
              m_pModel->m_angles = oldrot;
              m_pModel->m_origin = oldtrans;
              g_viewerSettings.lightrot = oldLight;
              v35 = DUMMY_NULL_FLEX_CONTROLLER;
              g_viewerSettings.showGround = v34;
              if ( pExpression != nullptr )
              {
                v36 = m_pStudioHdr->m_pStudioHdr;
                if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
                {
                  flEyeheighta = 0;
                  do
                  {
                    if ( *(int *)((char *)&v36->checksum + flEyeheighta + v36->flexcontrollerindex) != -1 )
                      StudioModel::SetFlexController(this: m_pModel, iFlex: v35, flValue: flexValues[v35]);
                    v36 = m_pStudioHdr->m_pStudioHdr;
                    flEyeheighta += 20;
                    ++v35;
                  }
                  while ( v35 < m_pStudioHdr->m_pStudioHdr->numflexcontrollers );
                }
              }
              StudioModel::ClearOverlaysSequences(this: m_pModel);
              if ( bitmap->valid )
              {
                DeleteObject(ho: bitmap->image);
                bitmap->image = nullptr;
                bitmap->valid = false;
              }
              LoadBitmapFromFile(relative: pchBitmapFilename, bitmap);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454B10
// Name: public: virtual void IFaceposerModels::CreateNewBitmap(int,char const __near *,int,int,bool,class CExpression __near *,struct mxbitmapdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CreateNewBitmap(
        IFaceposerModels *this,
        int modelindex,
        const char *pchBitmapFilename,
        int sequence,
        int nSnapShotSize,
        bool bZoomInOnFace,
        CExpression *pExpression,
        mxbitmapdata_t *bitmap)
{
  IFaceposerModels::CFacePoserModel *v8; // ecx

  v8 = this->m_Models.m_Memory.m_pMemory[modelindex];
  if ( v8 != nullptr )
    IFaceposerModels::CFacePoserModel::CreateNewBitmap(
      this: v8,
      pchBitmapFilename,
      sequence,
      nSnapShotSize,
      bZoomInOnFace,
      pExpression,
      bitmap);
}

//------------------------------------------------------------------------------
// Address: 0x00454B50
// Name: public: virtual char const __near * IFaceposerModels::GetModelName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall IFaceposerModels::GetModelName(IFaceposerModels *this, int index)
{
  IFaceposerModels::CFacePoserModel *v3; // eax

  if ( index >= 0 && index < this->Count(this) && (v3 = this->m_Models.m_Memory.m_pMemory[index]) != nullptr )
    return v3->m_szShortName;
  else
    return (char *)defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00454B90
// Name: public: virtual char const __near * IFaceposerModels::GetModelFileName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall IFaceposerModels::GetModelFileName(IFaceposerModels *this, int index)
{
  IFaceposerModels::CFacePoserModel *v3; // eax

  if ( index >= 0 && index < this->Count(this) && (v3 = this->m_Models.m_Memory.m_pMemory[index]) != nullptr )
    return v3->m_szModelFileName;
  else
    return (char *)defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00454BD0
// Name: public: virtual int IFaceposerModels::FindModelByFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IFaceposerModels::FindModelByFilename(IFaceposerModels *this, const char *filename)
{
  int v3; // ebx
  int v4; // esi
  IFaceposerModels::CFacePoserModel *v5; // eax

  v3 = this->Count(this);
  v4 = 0;
  if ( v3 <= 0 )
    return -1;
  while ( 1 )
  {
    if ( v4 >= 0 && v4 < this->Count(this) )
    {
      v5 = this->m_Models.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr && _V_stricmp(s1: v5->m_szModelFileName, s2: filename) == 0 )
        break;
    }
    if ( ++v4 >= v3 )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00454C30
// Name: public: virtual class StudioModel __near * IFaceposerModels::GetStudioModel(int)
// Source: json
//------------------------------------------------------------------------------
StudioModel *__thiscall IFaceposerModels::GetStudioModel(IFaceposerModels *this, int index)
{
  IFaceposerModels::CFacePoserModel *v3; // eax

  if ( index >= 0 && index < this->Count(this) && (v3 = this->m_Models.m_Memory.m_pMemory[index]) != nullptr )
    return v3->m_pModel;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00454C70
// Name: public: virtual int IFaceposerModels::GetModelIndexForActor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IFaceposerModels::GetModelIndexForActor(IFaceposerModels *this, const char *actorname)
{
  int v3; // ebx
  int v4; // esi
  IFaceposerModels::CFacePoserModel *v5; // eax

  v3 = this->Count(this);
  v4 = 0;
  if ( v3 <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v4 >= 0 && v4 < this->Count(this) )
    {
      v5 = this->m_Models.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr && _V_stricmp(s1: v5->m_szActorName, s2: actorname) == 0 )
        break;
    }
    if ( ++v4 >= v3 )
      return 0;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00454CD0
// Name: public: virtual class StudioModel __near * IFaceposerModels::GetModelForActor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
StudioModel *__thiscall IFaceposerModels::GetModelForActor(IFaceposerModels *this, const char *actorname)
{
  int v3; // edi
  int v4; // esi
  IFaceposerModels::CFacePoserModel *v5; // edi
  int c; // [esp+Ch] [ebp-4h]

  v3 = this->Count(this);
  v4 = 0;
  c = v3;
  if ( v3 <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v4 >= 0 && v4 < this->Count(this) )
    {
      v5 = this->m_Models.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr && _V_stricmp(s1: v5->m_szActorName, s2: actorname) == 0 )
        break;
      v3 = c;
    }
    if ( ++v4 >= v3 )
      return nullptr;
  }
  return v5->m_pModel;
}

//------------------------------------------------------------------------------
// Address: 0x00454D40
// Name: public: virtual char const __near * IFaceposerModels::GetActorNameForModel(int)
// Source: json
//------------------------------------------------------------------------------
IFaceposerModels::CFacePoserModel *__thiscall IFaceposerModels::GetActorNameForModel(
        IFaceposerModels *this,
        int modelindex)
{
  IFaceposerModels::CFacePoserModel *result; // eax

  if ( modelindex < 0 )
    return (IFaceposerModels::CFacePoserModel *)defaultValue;
  if ( modelindex >= this->Count(this) )
    return (IFaceposerModels::CFacePoserModel *)defaultValue;
  result = this->m_Models.m_Memory.m_pMemory[modelindex];
  if ( result == nullptr )
    return (IFaceposerModels::CFacePoserModel *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00454D70
// Name: public: virtual void IFaceposerModels::SetActorNameForModel(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::SetActorNameForModel(IFaceposerModels *this, int modelindex, const char *actorname)
{
  IFaceposerModels::CFacePoserModel *v4; // eax
  const char *v5; // edx
  char v6; // cl

  if ( modelindex >= 0 && modelindex < this->Count(this) )
  {
    v4 = this->m_Models.m_Memory.m_pMemory[modelindex];
    if ( v4 != nullptr )
    {
      v5 = (const char *)(actorname - (const char *)v4);
      do
      {
        v6 = v4->m_szActorName[(_DWORD)v5];
        v4->m_szActorName[0] = v6;
        v4 = (IFaceposerModels::CFacePoserModel *)((char *)v4 + 1);
      }
      while ( v6 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454DB0
// Name: public: virtual void IFaceposerModels::SaveModelList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::SaveModelList(IFaceposerModels *this)
{
  int v2; // ebx
  int i; // esi
  IFaceposerModels::CFacePoserModel *v4; // eax

  workspacefiles->StartStoringFiles(this: workspacefiles, a2: 2);
  v2 = this->Count(this);
  for ( i = 0; i < v2; ++i )
  {
    if ( i >= 0 && i < this->Count(this) )
    {
      v4 = this->m_Models.m_Memory.m_pMemory[i];
      if ( v4 != nullptr )
        workspacefiles->StoreFile(this: workspacefiles, a2: 2, a3: v4->m_szModelFileName);
    }
  }
  workspacefiles->FinishStoringFiles(this: workspacefiles, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00454E20
// Name: public: virtual void IFaceposerModels::ReleaseModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::ReleaseModels(IFaceposerModels *this)
{
  int v2; // ebx
  int i; // esi
  IFaceposerModels::CFacePoserModel *v4; // eax

  v2 = this->Count(this);
  for ( i = 0; i < v2; ++i )
  {
    if ( i >= 0 && i < this->Count(this) )
    {
      v4 = this->m_Models.m_Memory.m_pMemory[i];
      if ( v4 != nullptr )
        StudioModel::FreeModel(this: v4->m_pModel, bReleasing: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454E70
// Name: public: virtual void IFaceposerModels::RestoreModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::RestoreModels(IFaceposerModels *this)
{
  int v2; // ebx
  int i; // esi
  IFaceposerModels::CFacePoserModel *v4; // ecx

  v2 = this->Count(this);
  for ( i = 0; i < v2; ++i )
  {
    if ( i >= 0 && i < this->Count(this) )
    {
      v4 = this->m_Models.m_Memory.m_pMemory[i];
      if ( v4 != nullptr )
        IFaceposerModels::CFacePoserModel::Restore(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454EB0
// Name: public: virtual int IFaceposerModels::CountVisibleModels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IFaceposerModels::CountVisibleModels(IFaceposerModels *this)
{
  int v2; // esi
  int v3; // ebx
  IFaceposerModels::CFacePoserModel *v4; // eax
  int num; // [esp+Ch] [ebp-4h]

  v2 = 0;
  num = 0;
  v3 = this->Count(this);
  if ( v3 <= 0 )
    return 0;
  do
  {
    if ( v2 >= 0 && v2 < this->Count(this) )
    {
      v4 = this->m_Models.m_Memory.m_pMemory[v2];
      if ( v4 != nullptr && v4->m_bVisibileIn3DView )
        ++num;
    }
    ++v2;
  }
  while ( v2 < v3 );
  return num;
}

//------------------------------------------------------------------------------
// Address: 0x00454F10
// Name: public: virtual void IFaceposerModels::ShowModelIn3DView(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::ShowModelIn3DView(IFaceposerModels *this, int modelindex, bool show)
{
  IFaceposerModels::CFacePoserModel *v4; // eax

  if ( modelindex >= 0 && modelindex < this->Count(this) )
  {
    v4 = this->m_Models.m_Memory.m_pMemory[modelindex];
    if ( v4 != nullptr )
      v4->m_bVisibileIn3DView = show;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00454F50
// Name: public: virtual bool IFaceposerModels::IsModelShownIn3DView(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IFaceposerModels::IsModelShownIn3DView(IFaceposerModels *this, int modelindex)
{
  IFaceposerModels::CFacePoserModel *v3; // eax

  return modelindex >= 0
      && modelindex < this->Count(this)
      && (v3 = this->m_Models.m_Memory.m_pMemory[modelindex]) != nullptr
      && v3->m_bVisibileIn3DView;
}

//------------------------------------------------------------------------------
// Address: 0x00454F90
// Name: public: virtual int IFaceposerModels::GetIndexForStudioModel(class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IFaceposerModels::GetIndexForStudioModel(IFaceposerModels *this, StudioModel *model)
{
  int v3; // ebx
  int v4; // esi
  IFaceposerModels::CFacePoserModel *v5; // eax

  v3 = this->Count(this);
  v4 = 0;
  if ( v3 <= 0 )
    return -1;
  while ( 1 )
  {
    if ( v4 >= 0 && v4 < this->Count(this) )
    {
      v5 = this->m_Models.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr && v5->m_pModel == model )
        break;
    }
    if ( ++v4 >= v3 )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00454FF0
// Name: public: virtual void IFaceposerModels::CheckResetFlexes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CheckResetFlexes(IFaceposerModels *this)
{
  IFaceposerModels *v1; // esi
  int CurrentFrame; // eax
  int v3; // ebx
  IFaceposerModels::CFacePoserModel *v4; // eax
  StudioModel *m_pModel; // edi
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v7; // eax
  LocalFlexController_t j; // esi
  int c; // [esp+14h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  CurrentFrame = MDLViewer::GetCurrentFrame(this: g_MDLViewer);
  if ( CurrentFrame != v1->m_nLastRenderFrame )
  {
    v1->m_nLastRenderFrame = CurrentFrame;
    v3 = 0;
    c = v1->Count(this: v1);
    i = 0;
    if ( c > 0 )
    {
      do
      {
        if ( v3 >= 0 && v3 < v1->Count(this: v1) )
        {
          v4 = v1->m_Models.m_Memory.m_pMemory[v3];
          if ( v4 != nullptr )
          {
            m_pModel = v4->m_pModel;
            if ( m_pModel != nullptr )
            {
              m_pStudioHdr = m_pModel->m_pStudioHdr;
              if ( m_pStudioHdr != nullptr )
              {
                if ( m_pStudioHdr->m_pStudioHdr != nullptr
                  || (v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: m_pModel->m_MDLHandle),
                      CStudioHdr::Init(this: m_pModel->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr),
                      (m_pStudioHdr = m_pModel->m_pStudioHdr)->m_pStudioHdr != nullptr) )
                {
                  if ( m_pStudioHdr != nullptr )
                  {
                    for ( j = DUMMY_NULL_FLEX_CONTROLLER; j < m_pStudioHdr->m_pStudioHdr->numflexcontrollers; ++j )
                      StudioModel::SetFlexController(this: m_pModel, iFlex: j, flValue: 0.0);
                    v1 = this;
                  }
                }
              }
              v3 = i;
            }
          }
        }
        i = ++v3;
      }
      while ( v3 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004550E0
// Name: public: virtual void IFaceposerModels::ClearOverlaysSequences(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::ClearOverlaysSequences(IFaceposerModels *this)
{
  int v2; // ebx
  int i; // esi
  IFaceposerModels::CFacePoserModel *v4; // eax
  StudioModel *m_pModel; // eax

  v2 = this->Count(this);
  for ( i = 0; i < v2; ++i )
  {
    if ( i >= 0 && i < this->Count(this) )
    {
      v4 = this->m_Models.m_Memory.m_pMemory[i];
      if ( v4 != nullptr )
      {
        m_pModel = v4->m_pModel;
        if ( m_pModel != nullptr )
          StudioModel::ClearOverlaysSequences(this: m_pModel);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455130
// Name: public: virtual int IFaceposerModels::CountActiveSources(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IFaceposerModels::CountActiveSources(IFaceposerModels *this)
{
  int v2; // esi
  int v3; // ebx
  IFaceposerModels::CFacePoserModel *v4; // eax
  StudioModel *m_pModel; // eax
  int count; // [esp+Ch] [ebp-4h]

  v2 = 0;
  count = 0;
  v3 = this->Count(this);
  if ( v3 <= 0 )
    return 0;
  do
  {
    if ( v2 >= 0 && v2 < this->Count(this) )
    {
      v4 = this->m_Models.m_Memory.m_pMemory[v2];
      if ( v4 != nullptr )
      {
        m_pModel = v4->m_pModel;
        if ( m_pModel != nullptr )
          count += m_pModel->m_mouth.m_nVoiceSources;
      }
    }
    ++v2;
  }
  while ( v2 < v3 );
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x004551A0
// Name: public: virtual void IFaceposerModels::ClearModelTargets(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::ClearModelTargets(IFaceposerModels *this, bool force)
{
  int v3; // ebx
  int i; // esi
  IFaceposerModels::CFacePoserModel *v5; // eax
  StudioModel *m_pModel; // eax

  v3 = this->Count(this);
  for ( i = 0; i < v3; ++i )
  {
    if ( i >= 0 && i < this->Count(this) )
    {
      v5 = this->m_Models.m_Memory.m_pMemory[i];
      if ( v5 != nullptr )
      {
        m_pModel = v5->m_pModel;
        if ( m_pModel != nullptr )
          StudioModel::ClearLookTargets(this: m_pModel);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004551F0
// Name: public: virtual void IFaceposerModels::SetSolveHeadTurn(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::SetSolveHeadTurn(IFaceposerModels *this, int solve)
{
  int v3; // ebx
  int i; // esi
  IFaceposerModels::CFacePoserModel *v5; // eax
  StudioModel *m_pModel; // eax

  v3 = this->Count(this);
  for ( i = 0; i < v3; ++i )
  {
    if ( i >= 0 && i < this->Count(this) )
    {
      v5 = this->m_Models.m_Memory.m_pMemory[i];
      if ( v5 != nullptr )
      {
        m_pModel = v5->m_pModel;
        if ( m_pModel != nullptr )
          StudioModel::SetSolveHeadTurn(this: m_pModel, solve);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455250
// Name: public: void IFaceposerModels::CFacePoserModel::FreeBitmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::FreeBitmaps(IFaceposerModels::CFacePoserModel *this)
{
  IFaceposerModels::CFacePoserModel::AnimBitmap **m_pMemory; // eax
  IFaceposerModels::CFacePoserModel::AnimBitmap *v3; // edi

  for ( ; this->m_AnimationBitmaps.m_Size > 0; --this->m_AnimationBitmaps.m_Size )
  {
    m_pMemory = this->m_AnimationBitmaps.m_Memory.m_pMemory;
    v3 = *m_pMemory;
    free(pMem: (*m_pMemory)->bitmap);
    free(pMem: v3);
    if ( this->m_AnimationBitmaps.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_AnimationBitmaps.m_Memory.m_pMemory,
        src: this->m_AnimationBitmaps.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_AnimationBitmaps.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x004552C0
// Name: public: unsigned long IFaceposerModels::CFacePoserModel::GetBitmapCRC(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IFaceposerModels::CFacePoserModel::GetBitmapCRC(
        IFaceposerModels::CFacePoserModel *this,
        int sequence)
{
  StudioModel *m_pModel; // edi
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v4; // eax
  int v6; // eax
  const studiohdr_t *v7; // esi
  int v8; // eax
  mstudioseqdesc_t *v9; // esi
  const char *v10; // edi
  int v11; // eax
  const char *v12; // edi
  int v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  StudioModel *v16; // ecx
  const char *m_pModelName; // edi
  const char *KeyValueText; // eax
  CUtlBuffer buf; // [esp+8h] [ebp-38h] BYREF
  IFaceposerModels::CFacePoserModel *v20; // [esp+38h] [ebp-8h]
  unsigned int crc; // [esp+3Ch] [ebp-4h] BYREF

  m_pModel = this->m_pModel;
  v20 = this;
  if ( m_pModel != nullptr )
  {
    m_pStudioHdr = m_pModel->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr )
      return -1;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: m_pModel->m_MDLHandle);
      CStudioHdr::Init(this: m_pModel->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      m_pStudioHdr = m_pModel->m_pStudioHdr->m_pStudioHdr != nullptr ? m_pModel->m_pStudioHdr : nullptr;
    }
  }
  else
  {
    m_pStudioHdr = nullptr;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( sequence < 0 )
    return -1;
  v6 = m_pStudioHdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
     : m_pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( sequence >= v6 )
    return -1;
  if ( m_pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
  }
  else
  {
    v7 = m_pStudioHdr->m_pStudioHdr;
    v8 = sequence;
    if ( sequence >= v7->numlocalseq )
      v8 = 0;
    v9 = (mstudioseqdesc_t *)((char *)v7 + 212 * v8 + v7->localseqindex);
  }
  CRC32_Init(pulCRC: &crc);
  v10 = (char *)v9 + v9->szlabelindex;
  v11 = _V_strlen(str: v10);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: v10, nBuffer: v11);
  v12 = (char *)v9 + v9->szactivitynameindex;
  v13 = _V_strlen(str: v12);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: v12, nBuffer: v13);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &v9->flags, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &v9->numblends, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: v9->groupsize, nBuffer: 8);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: defaultValue);
  else
    v15 = nullptr;
  v16 = v20->m_pModel;
  m_pModelName = v16->m_pModelName;
  KeyValueText = StudioModel::GetKeyValueText(this: v16, iSequence: sequence);
  if ( KeyValues::LoadFromBuffer(
         this: v15,
         resourceName: m_pModelName,
         pBuffer: KeyValueText,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    KeyValues::RecursiveSaveToFile(this: v15, &buf, indentLevel: 0);
    CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: buf.m_Memory.m_pMemory, nBuffer: buf.m_Put);
    CUtlBuffer::~CUtlBuffer(this: &buf);
  }
  KeyValues::deleteThis(this: v15);
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x00455490
// Name: public: char const __near * IFaceposerModels::CFacePoserModel::GetBitmapFilename(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall IFaceposerModels::CFacePoserModel::GetBitmapFilename(
        IFaceposerModels::CFacePoserModel *this,
        unsigned int sequence)
{
  char *v3; // esi
  char *i; // edi
  char v5; // al
  int v7; // [esp-4h] [ebp-420h]
  char modelName[512]; // [esp+Ch] [ebp-410h] BYREF
  char modelNameTemp[512]; // [esp+20Ch] [ebp-210h] BYREF
  char out[16]; // [esp+40Ch] [ebp-10h] BYREF

  filename_0[0] = 0;
  V_strncpy(pDest: modelNameTemp, pSrc: this->m_szShortName, maxLen: 512);
  v3 = modelNameTemp;
  for ( i = modelName; *v3 != 0; ++v3 )
  {
    if ( isalnum(c: *v3) == 0 )
    {
      v5 = *v3;
      if ( *v3 != 95 && v5 != 92 && v5 != 47 && v5 != 46 && v5 != 58 )
        continue;
    }
    *i++ = *v3;
  }
  v7 = sequence;
  *i = 0;
  sequence = IFaceposerModels::CFacePoserModel::GetBitmapCRC(this, sequence: v7);
  V_binarytohex(in: (const unsigned __int8 *)&sequence, inputbytes: 4, out, outsize: 16);
  V_snprintf(pDest: byte_7160D0, maxLen: 512, pFormat: "%s", out);
  V_snprintf(pDest: filename_0, maxLen: 256, pFormat: "expressions/%s/animation/%s.bmp", modelName, byte_7160D0);
  V_FixSlashes(pname: filename_0, separator: 92);
  strlwr(string: filename_0);
  CreatePath(relative: filename_0);
  return filename_0;
}

//------------------------------------------------------------------------------
// Address: 0x004555A0
// Name: private: void IFaceposerModels::CFacePoserModel::LoadBitmapForSequence(struct mxbitmapdata_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::LoadBitmapForSequence(
        IFaceposerModels::CFacePoserModel *this,
        mxbitmapdata_t *bitmap,
        int sequence)
{
  char *BitmapFilename; // eax
  char filename[512]; // [esp+Ch] [ebp-200h] BYREF

  BitmapFilename = IFaceposerModels::CFacePoserModel::GetBitmapFilename(this, sequence);
  V_strncpy(pDest: filename, pSrc: BitmapFilename, maxLen: 512);
  if ( !LoadBitmapFromFile(relative: filename, bitmap) )
    IFaceposerModels::CFacePoserModel::CreateNewBitmap(
      this,
      pchBitmapFilename: filename,
      sequence,
      nSnapShotSize: 256,
      bZoomInOnFace: false,
      pExpression: nullptr,
      bitmap);
}

//------------------------------------------------------------------------------
// Address: 0x00455610
// Name: public: struct mxbitmapdata_t __near * IFaceposerModels::CFacePoserModel::GetBitmapForSequence(int)
// Source: json
//------------------------------------------------------------------------------
mxbitmapdata_t *__thiscall IFaceposerModels::CFacePoserModel::GetBitmapForSequence(
        IFaceposerModels::CFacePoserModel *this,
        int sequence)
{
  IFaceposerModels::CFacePoserModel::AnimBitmap *v3; // eax

  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    nullbitmap.valid = false;
    nullbitmap.image = nullptr;
    nullbitmap.width = 0;
    nullbitmap.height = 0;
  }
  if ( sequence < 0 || sequence >= this->m_AnimationBitmaps.m_Size )
    return &nullbitmap;
  v3 = this->m_AnimationBitmaps.m_Memory.m_pMemory[sequence];
  if ( v3->needsload )
  {
    v3->needsload = false;
    IFaceposerModels::CFacePoserModel::LoadBitmapForSequence(this, bitmap: v3->bitmap, sequence);
  }
  return this->m_AnimationBitmaps.m_Memory.m_pMemory[sequence]->bitmap;
}

//------------------------------------------------------------------------------
// Address: 0x00455690
// Name: public: virtual void IFaceposerModels::FreeModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::FreeModel(IFaceposerModels *this, int index)
{
  IFaceposerModels::CFacePoserModel *v3; // edi
  unsigned int m_pModel; // esi

  if ( index >= 0 && index < this->Count(this) )
  {
    v3 = this->m_Models.m_Memory.m_pMemory[index];
    if ( v3 != nullptr )
    {
      m_pModel = (unsigned int)v3->m_pModel;
      SaveViewerSettings(filename: *(HKEY__ **)(m_pModel + 128), pModel: (StudioModel *)m_pModel);
      StudioModel::FreeModel(this: (StudioModel *)m_pModel, bReleasing: false);
      StudioModel::~StudioModel(this: (StudioModel *)m_pModel);
      StudioModel::operator delete(pMem: m_pModel);
      IFaceposerModels::CFacePoserModel::FreeBitmaps(this: v3);
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v3->m_AnimationBitmaps);
      free(pMem: v3);
      if ( this->m_Models.m_Size - index - 1 > 0 )
        _V_memmove(
          dest: &this->m_Models.m_Memory.m_pMemory[index],
          src: &this->m_Models.m_Memory.m_pMemory[index + 1],
          count: 4 * (this->m_Models.m_Size - index - 1));
      --this->m_Models.m_Size;
      MDLViewer::InitModelTab(this: g_MDLViewer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455740
// Name: public: virtual struct mxbitmapdata_t __near * IFaceposerModels::GetBitmapForSequence(int,int)
// Source: json
//------------------------------------------------------------------------------
mxbitmapdata_t *__thiscall IFaceposerModels::GetBitmapForSequence(IFaceposerModels *this, int modelindex, int sequence)
{
  IFaceposerModels::CFacePoserModel *v4; // ecx

  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    nullbitmap_0.valid = false;
    nullbitmap_0.image = nullptr;
    nullbitmap_0.width = 0;
    nullbitmap_0.height = 0;
  }
  if ( modelindex >= 0
    && modelindex < this->Count(this)
    && (v4 = this->m_Models.m_Memory.m_pMemory[modelindex]) != nullptr )
  {
    return IFaceposerModels::CFacePoserModel::GetBitmapForSequence(this: v4, sequence);
  }
  else
  {
    return &nullbitmap_0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004557B0
// Name: public: void IFaceposerModels::CFacePoserModel::LoadBitmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::LoadBitmaps(IFaceposerModels::CFacePoserModel *this)
{
  IFaceposerModels::CFacePoserModel *v1; // edi
  StudioModel *m_pModel; // esi
  CUtlSymbolTable::StringPool_t *v3; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // ecx
  int v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  CUtlSymbolTable::StringPool_t *v10; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_AnimationBitmaps; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTable::StringPool_t **v16; // edi
  int i; // [esp+10h] [ebp-8h]
  CStudioHdr *v19; // [esp+14h] [ebp-4h]

  v1 = this;
  m_pModel = this->m_pModel;
  v3 = nullptr;
  if ( m_pModel != nullptr )
  {
    m_pStudioHdr = m_pModel->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v19 = m_pModel->m_pStudioHdr;
      v6 = v19;
    }
    else
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: m_pModel->m_MDLHandle);
      CStudioHdr::Init(this: m_pModel->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      v6 = m_pModel->m_pStudioHdr->m_pStudioHdr != nullptr ? m_pModel->m_pStudioHdr : nullptr;
      v19 = v6;
    }
  }
  else
  {
    v19 = nullptr;
    v6 = nullptr;
  }
  if ( v6 != nullptr )
  {
    i = 0;
    while ( 1 )
    {
      v7 = v6->m_pVModel != nullptr ? CStudioHdr::GetNumSeq_Internal(this: v6) : v6->m_pStudioHdr->numlocalseq;
      if ( i >= v7 )
        break;
      v8 = operator new(nSize: 0x10u);
      if ( v8 != nullptr )
      {
        *(_BYTE *)v8 = 0;
        v8[1] = 0;
        v8[2] = 0;
        v8[3] = 0;
        v9 = v8;
      }
      else
      {
        v9 = nullptr;
      }
      v10 = (CUtlSymbolTable::StringPool_t *)operator new(nSize: 8u);
      if ( v10 != nullptr )
      {
        v10->m_SpaceUsed = 0;
        LOBYTE(v10->m_TotalLen) = 0;
        v3 = v10;
      }
      v3->m_SpaceUsed = (int)v9;
      p_m_AnimationBitmaps = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_AnimationBitmaps;
      LOBYTE(v3->m_TotalLen) = 1;
      m_Size = v1->m_AnimationBitmaps.m_Size;
      m_nAllocationCount = p_m_AnimationBitmaps->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_m_AnimationBitmaps, num: m_Size - m_nAllocationCount + 1);
      ++p_m_AnimationBitmaps[1].m_pMemory;
      m_pMemory = p_m_AnimationBitmaps->m_pMemory;
      v15 = (int)p_m_AnimationBitmaps[1].m_pMemory - m_Size - 1;
      p_m_AnimationBitmaps[1].m_nAllocationCount = (int)p_m_AnimationBitmaps->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
      v16 = &p_m_AnimationBitmaps->m_pMemory[m_Size];
      if ( v16 != nullptr )
        *v16 = v3;
      ++i;
      v6 = v19;
      v1 = this;
      v3 = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004558F0
// Name: public: virtual IFaceposerModels::~IFaceposerModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::~IFaceposerModels(IFaceposerModels *this)
{
  IFaceposerModels::CFacePoserModel **m_pMemory; // eax
  IFaceposerModels::CFacePoserModel *v3; // esi
  IFaceposerModels::CFacePoserModel::AnimBitmap **v4; // eax
  int v5; // eax

  for ( this->__vftable = (IFaceposerModels_vtbl *)&IFaceposerModels::`vftable';
        this->m_Models.m_Size > 0;
        --this->m_Models.m_Size )
  {
    m_pMemory = this->m_Models.m_Memory.m_pMemory;
    v3 = *m_pMemory;
    if ( *m_pMemory != nullptr )
    {
      IFaceposerModels::CFacePoserModel::FreeBitmaps(this: *m_pMemory);
      v3->m_AnimationBitmaps.m_Size = 0;
      if ( v3->m_AnimationBitmaps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_AnimationBitmaps.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_AnimationBitmaps.m_Memory.m_pMemory);
          v3->m_AnimationBitmaps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_AnimationBitmaps.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_AnimationBitmaps.m_Memory.m_pMemory;
      v3->m_AnimationBitmaps.m_pElements = v4;
      if ( v3->m_AnimationBitmaps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v3->m_AnimationBitmaps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_AnimationBitmaps.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
    }
    v5 = this->m_Models.m_Size - 1;
    if ( v5 > 0 )
      _V_memmove(dest: this->m_Models.m_Memory.m_pMemory, src: this->m_Models.m_Memory.m_pMemory + 1, count: 4 * v5);
  }
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Models);
}

//------------------------------------------------------------------------------
// Address: 0x004559C0
// Name: public: IFaceposerModels::CFacePoserModel::CFacePoserModel(char const __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
IFaceposerModels::CFacePoserModel *__thiscall IFaceposerModels::CFacePoserModel::CFacePoserModel(
        IFaceposerModels::CFacePoserModel *this,
        const char *modelfile,
        StudioModel *model)
{
  const char *v3; // eax
  int v5; // edx
  char v6; // cl
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v8; // eax
  const studiohdr_t *v9; // edx
  int studiohdr2index; // eax
  int v11; // ecx
  char *v12; // eax
  int v13; // ecx
  const char *name; // eax

  v3 = modelfile;
  this->m_AnimationBitmaps.m_Memory.m_pMemory = nullptr;
  this->m_AnimationBitmaps.m_Memory.m_nAllocationCount = 0;
  this->m_AnimationBitmaps.m_Memory.m_nGrowSize = 0;
  this->m_AnimationBitmaps.m_Size = 0;
  this->m_AnimationBitmaps.m_pElements = nullptr;
  this->m_pModel = model;
  this->m_szActorName[0] = 0;
  this->m_szShortName[0] = 0;
  v5 = this->m_szModelFileName - modelfile;
  do
  {
    v6 = *v3;
    v3[v5] = *v3;
    ++v3;
  }
  while ( v6 != 0 );
  V_FixSlashes(pname: this->m_szModelFileName, separator: 92);
  m_pStudioHdr = model->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v8 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->m_MDLHandle);
      CStudioHdr::Init(this: model->m_pStudioHdr, pStudioHdr: v8, mdlcache: nullptr);
      if ( model->m_pStudioHdr->m_pStudioHdr == nullptr )
        goto LABEL_16;
      m_pStudioHdr = model->m_pStudioHdr;
    }
    if ( m_pStudioHdr != nullptr )
    {
      v9 = m_pStudioHdr->m_pStudioHdr;
      studiohdr2index = m_pStudioHdr->m_pStudioHdr->studiohdr2index;
      if ( studiohdr2index != 0
        && (v11 = *(_DWORD *)&v9->name[studiohdr2index + 8], v12 = (char *)v9 + studiohdr2index, v11 != 0)
        && &v12[v11] != nullptr )
      {
        v13 = *((_DWORD *)v12 + 5);
        if ( v13 != 0 )
          name = &v12[v13];
        else
          name = nullptr;
      }
      else
      {
        name = v9->name;
      }
      V_StripExtension(in: name, out: this->m_szShortName, outSize: 32);
    }
  }
LABEL_16:
  this->m_bVisibileIn3DView = false;
  this->m_bFirstBitmapLoad = true;
  IFaceposerModels::CFacePoserModel::LoadBitmaps(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00455AE0
// Name: public: virtual int IFaceposerModels::LoadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IFaceposerModels::LoadModel(IFaceposerModels *this, IFaceposerModels::CFacePoserModel *filename)
{
  IMDLCache *v2; // esi
  unsigned __int8 *v5; // eax
  StudioModel *v6; // esi
  int v8; // eax
  int Sequence; // eax
  IFaceposerModels::CFacePoserModel *v10; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IFaceposerModels::CFacePoserModel **m_pMemory; // ecx
  int v14; // eax
  IFaceposerModels::CFacePoserModel **v15; // eax
  int idx; // [esp+Ch] [ebp-8h]
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-4h]
  StudioModel *newEntry; // [esp+1Ch] [ebp+8h]
  IFaceposerModels::CFacePoserModel *newEntrya; // [esp+1Ch] [ebp+8h]

  v2 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  idx = this->FindModelByFilename(this, a2: (const char *)filename);
  if ( idx != -1 || this->Count(this) >= 16 )
  {
LABEL_22:
    v2->EndLock(this: v2);
    return idx;
  }
  v5 = StudioModel::operator new(stAllocateBlock: 0x1460u);
  if ( v5 != nullptr )
    v6 = StudioModel::StudioModel(this: (StudioModel *)v5);
  else
    v6 = nullptr;
  newEntry = g_pStudioModel;
  g_pStudioModel = v6;
  if ( StudioModel::LoadModel(this: v6, pModelName: filename->m_szActorName) != 0 )
  {
    g_pStudioModel = newEntry;
    v8 = StudioModel::LookupSequence(this: v6, szSequence: "idle_subtle");
    StudioModel::SetSequence(this: v6, iSequence: v8);
    Sequence = StudioModel::GetSequence(this: v6);
    StudioModel::SetSequence(this: v6, iSequence: Sequence);
    SetupModelFlexcontrollerLinks(model: v6);
    if ( LoadViewerSettings((HKEY__ *)filename, pModel: v6) == 0 )
      InitViewerSettings(subkey: "faceposer");
    StudioModel::ClearOverlaysSequences(this: v6);
    v10 = (IFaceposerModels::CFacePoserModel *)operator new(nSize: 0x100u);
    if ( v10 != nullptr )
      newEntrya = IFaceposerModels::CFacePoserModel::CFacePoserModel(
                    this: v10,
                    modelfile: filename->m_szActorName,
                    model: v6);
    else
      newEntrya = nullptr;
    m_Size = this->m_Models.m_Size;
    m_nAllocationCount = this->m_Models.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Models,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Models.m_Size;
    m_pMemory = this->m_Models.m_Memory.m_pMemory;
    v14 = this->m_Models.m_Size - m_Size - 1;
    this->m_Models.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
    v15 = &this->m_Models.m_Memory.m_pMemory[m_Size];
    if ( v15 != nullptr )
      *v15 = newEntrya;
    MDLViewer::InitModelTab(this: g_MDLViewer);
    MDLViewer::SetActiveModelTab(this: g_MDLViewer, modelindex: m_Size);
    v2 = cacheCriticalSection;
    goto LABEL_22;
  }
  if ( v6 != nullptr )
  {
    StudioModel::~StudioModel(this: v6);
    StudioModel::operator delete(pMem: (unsigned int)v6);
  }
  g_pStudioModel = newEntry;
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00455C90
// Name: private: void IFaceposerModels::CFacePoserModel::BuildValidChecksums(class CUtlRBTree<unsigned long,unsigned short,bool (*)(unsigned long const __near &,unsigned long const __near &),class CUtlMemory<struct UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::BuildValidChecksums(
        IFaceposerModels::CFacePoserModel *this,
        CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *tree)
{
  IFaceposerModels::CFacePoserModel *v2; // ebx
  StudioModel *m_pModel; // esi
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v5; // eax
  CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *v6; // esi
  const char *j; // edi
  int v8; // eax
  unsigned __int16 v9; // ax
  unsigned __int16 v10; // dx
  unsigned __int16 v11; // cx
  int v12; // edi
  UtlRBTreeNode_t<unsigned long,unsigned short> *v13; // eax
  int v14; // edx
  UtlRBTreeNode_t<unsigned long,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<unsigned long,unsigned short> *v16; // ecx
  unsigned int *p_m_Data; // edi
  CStudioHdr *hdr; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  unsigned int crc; // [esp+14h] [ebp-8h] BYREF
  unsigned __int16 parent[2]; // [esp+18h] [ebp-4h] BYREF

  v2 = this;
  m_pModel = this->m_pModel;
  if ( m_pModel != nullptr )
  {
    m_pStudioHdr = m_pModel->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr
      || m_pStudioHdr->m_pStudioHdr != nullptr
      || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: m_pModel->m_MDLHandle),
          CStudioHdr::Init(this: m_pModel->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
          (m_pStudioHdr = m_pModel->m_pStudioHdr)->m_pStudioHdr != nullptr) )
    {
      hdr = m_pStudioHdr;
      if ( m_pStudioHdr != nullptr )
      {
        v6 = tree;
        for ( j = nullptr; ; j = (const char *)(i + 1) )
        {
          i = (int)j;
          v8 = m_pStudioHdr->m_pVModel != nullptr
             ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
             : m_pStudioHdr->m_pStudioHdr->numlocalseq;
          if ( (int)j >= v8 )
            break;
          crc = IFaceposerModels::CFacePoserModel::GetBitmapCRC(this: v2, sequence: (int)j);
          *(_DWORD *)parent = 0xFFFF;
          HIBYTE(tree) = 0;
          CUtlRBTree<unsigned long,unsigned short,bool (__cdecl *)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: v6,
            insert: &crc,
            parent,
            leftchild: (bool *)&tree + 3);
          v9 = CUtlRBTree<CChoreoEventWidget *,unsigned short,bool (__cdecl *)(CChoreoEventWidget * const &,CChoreoEventWidget * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEventWidget *,unsigned short>,unsigned short>>::NewNode(
                 this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)v6,
                 a2: j);
          v10 = parent[0];
          v11 = v9;
          v12 = v9;
          v13 = &v6->m_Elements.m_pMemory[v12];
          v13->m_Right = -1;
          v13->m_Left = -1;
          v13->m_Parent = v10;
          v13->m_Tag = 0;
          if ( v10 == 0xFFFF )
          {
            v6->m_Root = v11;
          }
          else
          {
            v14 = v10;
            m_pMemory = v6->m_Elements.m_pMemory;
            if ( HIBYTE(tree) != 0 )
              m_pMemory[v14].m_Left = v11;
            else
              m_pMemory[v14].m_Right = v11;
          }
          CUtlRBTree<unsigned long,unsigned short,bool (__cdecl *)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>>::InsertRebalance(
            this: v6,
            elem: v11);
          v16 = v6->m_Elements.m_pMemory;
          ++v6->m_NumElements;
          p_m_Data = &v16[v12].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = crc;
          v2 = this;
          m_pStudioHdr = hdr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455DD0
// Name: private: void IFaceposerModels::CFacePoserModel::ReconcileAnimationBitmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::ReconcileAnimationBitmaps(IFaceposerModels::CFacePoserModel *this)
{
  char *m_szShortName; // edi
  const char *v2; // esi
  CFmtStrN<256> *v3; // eax
  CUtlString *m_pMemory; // ebx
  int m_Size; // edi
  int v6; // esi
  CUtlString *v7; // esi
  int v8; // ebx
  const char *v9; // eax
  int v10; // eax
  int v11; // [esp+20h] [ebp-568h]
  char path[512]; // [esp+38h] [ebp-550h] BYREF
  char fullpath[512]; // [esp+238h] [ebp-350h] BYREF
  CFmtStrN<256> v14; // [esp+438h] [ebp-150h] BYREF
  float v15; // [esp+544h] [ebp-44h]
  unsigned int check; // [esp+548h] [ebp-40h] BYREF
  char *v17; // [esp+54Ch] [ebp-3Ch]
  CUtlString s; // [esp+550h] [ebp-38h] BYREF
  int v19; // [esp+560h] [ebp-28h]
  int v20; // [esp+564h] [ebp-24h]
  int v21; // [esp+568h] [ebp-20h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > workList; // [esp+56Ch] [ebp-1Ch] BYREF
  int hFindFile; // [esp+580h] [ebp-8h] BYREF
  IFaceposerModels::CFacePoserModel *v24; // [esp+584h] [ebp-4h]

  m_szShortName = this->m_szShortName;
  v24 = this;
  v17 = this->m_szShortName;
  V_snprintf(pDest: path, maxLen: 512, pFormat: "expressions/%s/animation/*.bmp", this->m_szShortName);
  v2 = filesystem->FindFirstEx(this: filesystem, a2: path, a3: "MOD", a4: &hFindFile);
  v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "%s - Reconcile Animation Thumbnails", m_szShortName);
  g_pProgressDialog->Start(this: g_pProgressDialog, a2: v3->m_szBuf, a3: defaultValue, a4: true);
  m_pMemory = nullptr;
  m_Size = 0;
  memset(&workList, 0, sizeof(workList));
  if ( v2 != nullptr )
  {
    do
    {
      if ( ((unsigned __int8 (__thiscall *)(IFileSystem *, int, int))filesystem->FindIsDirectory)(
             a1: filesystem,
             a2: hFindFile,
             a3: v11) == 0 )
      {
        CUtlString::CUtlString(this: (CUtlString *)&s.m_Storage.m_nActualLength, pString: v2);
        v6 = m_Size;
        if ( m_Size + 1 > workList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<SceneImageEntry_t,int>::Grow(
            this: (CUtlMemory<SceneImageEntry_t,int> *)&workList,
            num: m_Size - workList.m_Memory.m_nAllocationCount + 1);
          m_Size = workList.m_Size;
          m_pMemory = workList.m_Memory.m_pMemory;
        }
        workList.m_Size = ++m_Size;
        workList.m_pElements = m_pMemory;
        if ( m_Size - v6 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 16 * (m_Size - v6 - 1));
        v7 = &m_pMemory[v6];
        if ( v7 != nullptr )
          CUtlString::CUtlString(this: v7, string: (const CUtlString *)&s.m_Storage.m_nActualLength);
        v21 = 0;
        if ( v20 >= 0 )
        {
          if ( s.m_Storage.m_nActualLength != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)s.m_Storage.m_nActualLength);
            s.m_Storage.m_nActualLength = 0;
          }
          v19 = 0;
        }
      }
      v11 = hFindFile;
      v2 = (const char *)((int (__thiscall *)(IFileSystem *))filesystem->FindNext)(a1: filesystem);
    }
    while ( v2 != nullptr );
    filesystem->FindClose(this: filesystem, a2: hFindFile);
  }
  s.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)CDefOps<CChoreoEvent *>::LessFunc;
  memset(&s.m_Storage.m_Memory.m_nAllocationCount, 0, 12);
  v19 = 0xFFFF;
  v20 = -1;
  v21 = 0;
  IFaceposerModels::CFacePoserModel::BuildValidChecksums(
    this: v24,
    tree: (CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *)&s);
  v8 = 0;
  if ( m_Size > 0 )
  {
    v15 = (float)m_Size;
    v24 = (IFaceposerModels::CFacePoserModel *)workList.m_Memory.m_pMemory;
    while ( 1 )
    {
      v9 = CUtlString::operator char const *(this: (CUtlString *)v24);
      V_StripExtension(in: v9, out: &v14.m_szBuf[7], outSize: 256);
      g_pProgressDialog->UpdateText(this: g_pProgressDialog, a2: "%s", &v14.m_szBuf[7]);
      ((void (__thiscall *)(IProgressDialog *, _DWORD))g_pProgressDialog->Update)(
        a1: g_pProgressDialog,
        a2: (float)v8 / v15);
      v10 = _V_strlen(str: &v14.m_szBuf[7]);
      V_hextobinary(in: &v14.m_szBuf[7], numchars: v10, out: (unsigned __int8 *)&check, maxoutputbytes: 4);
      if ( CUtlRBTree<unsigned long,unsigned short,bool (__cdecl *)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>>::Find(
             this: (CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *)&s,
             search: &check) == 0xFFFF )
      {
        V_snprintf(pDest: &v14.m_szBuf[7], maxLen: 256, pFormat: "expressions/%s/animation/%s", v17, v2);
        filesystem->RelativePathToFullPath(
          this: filesystem,
          a2: &v14.m_szBuf[7],
          a3: "MOD",
          a4: fullpath,
          a5: 512,
          a6: (PathTypeFilter_t)0,
          a7: nullptr);
        Con_ErrorPrintf(fmt: "Removing unused bitmap file %s\n", fullpath);
        _unlink(path: fullpath);
      }
      if ( g_pProgressDialog->IsCancelled(this: g_pProgressDialog) )
        break;
      v24 = (IFaceposerModels::CFacePoserModel *)((char *)v24 + 16);
      if ( ++v8 >= m_Size )
        goto LABEL_23;
    }
    _Msg(a1: "Cancelled\n");
  }
LABEL_23:
  g_pProgressDialog->Finish(this: g_pProgressDialog);
  CUtlRBTree<unsigned long,unsigned short,bool (__cdecl *)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *)&s);
  if ( s.m_Storage.m_nActualLength >= 0 && s.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)s.m_Storage.m_Memory.m_nAllocationCount);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &workList);
  if ( workList.m_Memory.m_nGrowSize >= 0 && workList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00456140
// Name: public: void IFaceposerModels::CFacePoserModel::RecreateAnimationBitmap(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::RecreateAnimationBitmap(
        IFaceposerModels::CFacePoserModel *this,
        int sequence,
        bool reconcile)
{
  IFaceposerModels::CFacePoserModel::AnimBitmap *v4; // esi
  mxbitmapdata_t *bitmap; // eax
  char *BitmapFilename; // eax
  char fullpath[512]; // [esp+8h] [ebp-400h] BYREF
  char filename[512]; // [esp+208h] [ebp-200h] BYREF

  if ( sequence >= 0 && sequence < this->m_AnimationBitmaps.m_Size )
  {
    v4 = this->m_AnimationBitmaps.m_Memory.m_pMemory[sequence];
    bitmap = v4->bitmap;
    v4->needsload = true;
    if ( bitmap->valid )
    {
      DeleteObject(ho: bitmap->image);
      v4->bitmap->image = nullptr;
      v4->bitmap->valid = false;
    }
    BitmapFilename = IFaceposerModels::CFacePoserModel::GetBitmapFilename(this, sequence);
    V_snprintf(pDest: filename, maxLen: 512, pFormat: "%s", BitmapFilename);
    if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: filename, a3: nullptr) )
    {
      filesystem->RelativePathToFullPath(
        this: filesystem,
        a2: filename,
        a3: "MOD",
        a4: fullpath,
        a5: 512,
        a6: (PathTypeFilter_t)0,
        a7: nullptr);
      _unlink(path: fullpath);
    }
    IFaceposerModels::CFacePoserModel::GetBitmapForSequence(this, sequence);
    if ( reconcile )
      IFaceposerModels::CFacePoserModel::ReconcileAnimationBitmaps(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456230
// Name: public: virtual void IFaceposerModels::RecreateAnimationBitmap(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::RecreateAnimationBitmap(IFaceposerModels *this, int modelindex, int sequence)
{
  IFaceposerModels::CFacePoserModel *v4; // ecx

  if ( modelindex >= 0 && modelindex < this->Count(this) )
  {
    v4 = this->m_Models.m_Memory.m_pMemory[modelindex];
    if ( v4 != nullptr )
      IFaceposerModels::CFacePoserModel::RecreateAnimationBitmap(this: v4, sequence, reconcile: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456270
// Name: public: void IFaceposerModels::CFacePoserModel::RecreateAllAnimationBitmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::CFacePoserModel::RecreateAllAnimationBitmaps(IFaceposerModels::CFacePoserModel *this)
{
  IFaceposerModels::CFacePoserModel *v1; // ebx
  StudioModel *m_pModel; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  CFmtStrN<256> *v6; // eax
  int i; // esi
  int v8; // eax
  int NumSeq_Internal; // eax
  CFmtStrN<256> v10; // [esp+20h] [ebp-110h] BYREF
  IFaceposerModels::CFacePoserModel *v11; // [esp+12Ch] [ebp-4h]

  v1 = this;
  m_pModel = this->m_pModel;
  v11 = this;
  if ( m_pModel != nullptr )
  {
    m_pStudioHdr = m_pModel->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr )
    {
      if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      {
        v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: m_pModel->m_MDLHandle);
        CStudioHdr::Init(this: m_pModel->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
        v5 = m_pModel->m_pStudioHdr;
        if ( v5->m_pStudioHdr == nullptr )
          return;
        m_pStudioHdr = v5;
      }
      if ( m_pStudioHdr != nullptr )
      {
        v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v10, pszFormat: "%s - Animation Thumbnails", v1->m_szShortName);
        g_pProgressDialog->Start(this: g_pProgressDialog, a2: v6->m_szBuf, a3: defaultValue, a4: true);
        for ( i = 0; ; ++i )
        {
          v8 = m_pStudioHdr->m_pVModel != nullptr
             ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
             : m_pStudioHdr->m_pStudioHdr->numlocalseq;
          if ( i >= v8 )
            break;
          if ( m_pStudioHdr->m_pVModel != nullptr )
            CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i);
          ((void (__stdcall *)(IProgressDialog *))g_pProgressDialog->UpdateText)(a1: g_pProgressDialog);
          if ( m_pStudioHdr->m_pVModel != nullptr )
            NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
          else
            NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
          ((void (__cdecl *)(_DWORD))g_pProgressDialog->Update)(a1: (float)i / (float)NumSeq_Internal);
          v1 = v11;
          IFaceposerModels::CFacePoserModel::RecreateAnimationBitmap(this: v11, sequence: i, reconcile: false);
          if ( g_pProgressDialog->IsCancelled(this: g_pProgressDialog) )
          {
            _Msg(a1: "Cancelling\n");
            break;
          }
        }
        g_pProgressDialog->Finish(this: g_pProgressDialog);
        IFaceposerModels::CFacePoserModel::ReconcileAnimationBitmaps(this: v1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456410
// Name: public: virtual void IFaceposerModels::RecreateAllAnimationBitmaps(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::RecreateAllAnimationBitmaps(IFaceposerModels *this, int modelindex)
{
  IFaceposerModels::CFacePoserModel *v3; // ecx

  if ( modelindex >= 0 && modelindex < this->Count(this) )
  {
    v3 = this->m_Models.m_Memory.m_pMemory[modelindex];
    if ( v3 != nullptr )
      IFaceposerModels::CFacePoserModel::RecreateAllAnimationBitmaps(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491980
// Name: public: virtual void IFaceposerModels::ForceActiveModelIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IFaceposerModels::ForceActiveModelIndex(IFaceposerModels *this, int index)
{
  this->m_nForceModelIndex = index;
}
