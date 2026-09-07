// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_baseflex.cpp
// Functions: 76
// ============================================================

#include "game\client\c_baseflex.h"

//------------------------------------------------------------------------------
// Address: 0x10044DA0
// Name: bool StringHasPrefix(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl StringHasPrefix(const char *str, const char *prefix)
{
  return StringAfterPrefix(str, prefix) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10044DC0
// Name: public: virtual class ClientClass __near * C_BaseFlex::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseFlex::GetClientClass(C_BaseFlex *this)
{
  return &__g_C_BaseFlexClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10044ED0
// Name: public: virtual struct datamap_t __near * C_BaseFlex::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseFlex::GetPredDescMap(C_BaseFlex *this)
{
  return &C_BaseFlex::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10044EE0
// Name: public: virtual void C_BaseFlex::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::Spawn(C_BaseFlex *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  this->InitPhonemeMappings(this);
}

//------------------------------------------------------------------------------
// Address: 0x10044F00
// Name: public: void C_BaseFlex::SetupMappings(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::SetupMappings(C_BaseFlex *this, const char *pchFileRoot)
{
  C_BaseFlex::Emphasized_Phoneme *m_PhonemeClasses; // edi

  m_PhonemeClasses = this->m_PhonemeClasses;
  memset(dst: (int)this->m_PhonemeClasses, value: nullptr, count: sizeof(this->m_PhonemeClasses));
  V_snprintf(pDest: this->m_PhonemeClasses[1].classname, maxLen: 0x40u, pFormat: "%s", pchFileRoot);
  this->m_PhonemeClasses[1].required = true;
  V_snprintf(pDest: m_PhonemeClasses->classname, maxLen: 0x40u, pFormat: "%s_weak", pchFileRoot);
  V_snprintf(pDest: this->m_PhonemeClasses[2].classname, maxLen: 0x40u, pFormat: "%s_strong", pchFileRoot);
}

//------------------------------------------------------------------------------
// Address: 0x10044F70
// Name: public: virtual void C_BaseFlex::StandardBlendingRules(class CStudioHdr __near *,class Vector __near * const,class QuaternionAligned __near * const,float,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseFlex::StandardBlendingRules(
        C_BaseFlex *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CStudioHdr *hdr,
        Vector *pos,
        QuaternionAligned *q,
        float currentTime,
        int boneMask)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  C_BaseAnimating::StandardBlendingRules(
    this,
    a2: (CBoneSetup *)&savedregs,
    a3: a2,
    a4: a3,
    hdr,
    pos,
    q,
    currentTime,
    boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x10044FA0
// Name: private: void C_BaseFlex::ComputeBlendedSetting(struct C_BaseFlex::Emphasized_Phoneme __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::ComputeBlendedSetting(
        C_BaseFlex *this,
        C_BaseFlex::Emphasized_Phoneme *classes,
        float emphasis_intensity)
{
  float v3; // xmm0_4
  float v4; // xmm0_4

  if ( emphasis_intensity <= 0.60000002 )
  {
    if ( emphasis_intensity >= 0.40000001 )
    {
      classes[1].amount = emphasis_intensity * 2.0;
    }
    else if ( classes->valid )
    {
      v4 = (float)(0.40000001 - emphasis_intensity) * 2.5;
      classes->amount = v4;
      classes[1].amount = (float)((float)(1.0 - v4) * 2.0) * 0.40000001;
    }
    else
    {
      classes[1].amount = 0.80000001;
    }
  }
  else if ( classes[2].valid )
  {
    v3 = (float)(1.0 - emphasis_intensity) * 2.5000002;
    classes[2].amount = 1.0 - v3;
    classes[1].amount = (float)(v3 * 2.0) * 0.60000002;
  }
  else
  {
    classes[1].amount = 1.2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045090
// Name: public: static void C_BaseFlex::InvalidateFlexCaches(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseFlex::InvalidateFlexCaches()
{
  ++g_iFlexCounter;
}

//------------------------------------------------------------------------------
// Address: 0x100450A0
// Name: public: static char const __near * C_BaseFlex::GetGlobalFlexControllerName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl C_BaseFlex::GetGlobalFlexControllerName(int idx)
{
  if ( idx < 0 || idx >= C_BaseFlex::g_numflexcontrollers )
    return prType;
  else
    return C_BaseFlex::g_flexcontroller[idx];
}

//------------------------------------------------------------------------------
// Address: 0x100450D0
// Name: private: bool C_BaseFlex::RequestStartSequenceSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseFlex::RequestStartSequenceSceneEvent(
        C_BaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor,
        C_BaseEntity *pTarget)
{
  const char *Parameters; // eax
  int v8; // eax

  Parameters = CChoreoEvent::GetParameters(this: event);
  v8 = C_BaseAnimating::LookupSequence(this, label: Parameters);
  info->m_nSequence = v8;
  if ( v8 < 0 )
    return 0;
  info->m_pActor = actor;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045110
// Name: public: virtual bool C_BaseFlex::ProcessSequenceSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseFlex::ProcessSequenceSceneEvent(
        C_BaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  if ( info == nullptr || event == nullptr || scene == nullptr )
    return 0;
  C_BaseAnimating::SetSequence(this, nSequence: info->m_nSequence);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045140
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x10045170
// Name: public: virtual void C_BaseFlex::InitPhonemeMappings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::InitPhonemeMappings(C_BaseFlex *this)
{
  C_BaseFlex::SetupMappings(this, pchFileRoot: "phonemes");
}

//------------------------------------------------------------------------------
// Address: 0x10045180
// Name: public: virtual class IClientModelRenderable __near * C_BaseFlex::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__usercall C_BaseFlex::GetClientModelRenderable@<eax>(C_BaseFlex *this@<ecx>, int a2@<esi>)
{
  IClientThinkable *result; // eax
  int v4; // esi

  result = C_BaseAnimating::GetClientModelRenderable(this, a2);
  if ( result != nullptr )
  {
    if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: (C_BaseFlex *)((char *)this - 4));
    v4 = *(_DWORD *)&this->m_nOldMuzzleFlashParity;
    if ( v4 == 0 || *(_DWORD *)v4 == 0 || *(_DWORD *)(*(_DWORD *)v4 + 268) != 0 || this == (C_BaseFlex *)4 )
      return nullptr;
    else
      return &this->IClientThinkable;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100451E0
// Name: public: virtual bool C_BaseFlex::GetSoundSpatialization(struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseFlex::GetSoundSpatialization(C_BaseFlex *this, SpatializationInfo_t *info)
{
  SpatializationInfo_t *v2; // edi
  char SoundSpatialization; // bl
  Vector *pOrigin; // eax
  QAngle *pAngles; // eax
  QAngle angles; // [esp+Ch] [ebp-18h] BYREF
  Vector origin; // [esp+18h] [ebp-Ch] BYREF

  v2 = info;
  SoundSpatialization = C_BaseAnimating::GetSoundSpatialization(this, info);
  if ( SoundSpatialization != 0 && v2->info.nChannel == 2 && this->m_iMouthAttachment > 0 )
  {
    C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
      this: (C_BaseAnimating::AutoAllowBoneAccess *)&info + 3,
      bAllowForNormalModels: true,
      bAllowForViewModels: false);
    if ( this->GetAttachment_2(this: &this->IClientRenderable, a2: this->m_iMouthAttachment, a3: &origin, a4: &angles) )
    {
      pOrigin = v2->pOrigin;
      if ( pOrigin != nullptr )
        *pOrigin = origin;
      pAngles = v2->pAngles;
      if ( pAngles != nullptr )
        *pAngles = angles;
    }
    C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: (C_BaseAnimating::AutoAllowBoneAccess *)&info + 3);
  }
  return SoundSpatialization;
}

//------------------------------------------------------------------------------
// Address: 0x100452A0
// Name: private: class Vector C_BaseFlex::SetViewTarget(class CStudioHdr __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
Vector *__userpurge C_BaseFlex::SetViewTarget@<eax>(
        C_BaseFlex *this@<ecx>,
        float a2@<ebp>,
        Vector *result,
        CStudioHdr *pStudioHdr,
        const float *pGlobalFlexWeight)
{
  int m_iEyeAttachment; // eax
  float x; // xmm0_4
  float v9; // xmm2_4
  __int128 v10; // xmm0
  LocalFlexController_t m_iEyeUpdown; // eax
  LocalFlexController_t m_iEyeRightleft; // eax
  float v13; // xmm4_4
  int studiohdr2index; // ecx
  float v15; // xmm4_4
  float v16; // xmm3_4
  float y; // xmm2_4
  float z; // xmm1_4
  float v19; // xmm0_4
  CStudioHdr *m_pStudioHdr; // eax
  bool v21; // zf
  IVModelRender_vtbl *v22; // edi
  int v23; // eax
  _BYTE v24[12]; // [esp-Ch] [ebp-8Ch] BYREF
  __int128 attToWorld_36; // [esp+24h] [ebp-5Ch] OVERLAPPED
  Vector v26; // [esp+40h] [ebp-40h] BYREF
  Vector eyeDeflect; // [esp+4Ch] [ebp-34h] BYREF
  QAngle eyeAng; // [esp+58h] [ebp-28h] BYREF
  Vector tmp; // [esp+64h] [ebp-1Ch] BYREF
  Vector local; // [esp+70h] [ebp-10h]
  float retaddr; // [esp+80h] [ebp+0h]

  local.y = a2;
  local.z = retaddr;
  if ( pStudioHdr == nullptr )
    goto LABEL_2;
  eyeAng.z = this->m_viewtarget.z;
  m_iEyeAttachment = this->m_iEyeAttachment;
  *(_QWORD *)&eyeAng.x = *(_QWORD *)&this->m_viewtarget.x;
  if ( m_iEyeAttachment > 0 )
  {
    if ( !this->GetAttachment(this: &this->IClientRenderable, a2: m_iEyeAttachment, a3: (matrix3x4_t *)v24) )
    {
LABEL_2:
      result->x = 0.0;
      result->y = 0.0;
      result->z = 0.0;
      return result;
    }
    VectorITransform(in1: &eyeAng.x, in2: (const matrix3x4_t *)v24, out: &tmp.x);
    x = tmp.x;
    if ( tmp.x < 6.0 )
    {
      x = 6.0;
      tmp.x = 6.0;
    }
    local.x = tmp.z * tmp.z;
    v9 = (float)((float)(tmp.z * tmp.z) + (float)(tmp.y * tmp.y)) + (float)(x * x);
    v10 = 0;
    *(float *)&v10 = fsqrt(v9);
    attToWorld_36 = v10;
    VectorNormalize(vec: &tmp);
    m_iEyeUpdown = this->m_iEyeUpdown;
    memset((void *)&eyeDeflect, 0, sizeof(eyeDeflect));
    if ( m_iEyeUpdown != DUMMY_INVALID_FLEX_CONTROLLER )
      eyeDeflect.x = pGlobalFlexWeight[*(int *)((char *)&pStudioHdr->m_pStudioHdr->checksum
                                              + 20 * m_iEyeUpdown
                                              + pStudioHdr->m_pStudioHdr->flexcontrollerindex)];
    m_iEyeRightleft = this->m_iEyeRightleft;
    if ( m_iEyeRightleft != DUMMY_INVALID_FLEX_CONTROLLER )
      eyeDeflect.y = pGlobalFlexWeight[*(int *)((char *)&pStudioHdr->m_pStudioHdr->checksum
                                              + 20 * m_iEyeRightleft
                                              + pStudioHdr->m_pStudioHdr->flexcontrollerindex)];
    AngleVectors(angles: (const QAngle *)&eyeDeflect, forward: &v26);
    v13 = tmp.x;
    v26.x = (float)(v13 * v13) * 0.0;
    v26.y = v26.y * (float)(v13 * v13);
    v26.z = v26.z * (float)(v13 * v13);
    tmp.x = v26.x + tmp.x;
    tmp.y = v26.y + tmp.y;
    tmp.z = v26.z + tmp.z;
    VectorNormalize(vec: &tmp);
    studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
    if ( studiohdr2index == 0 || (v15 = *(float *)&pStudioHdr->m_pStudioHdr->name[studiohdr2index]) == 0.0 )
      v15 = 0.866;
    v16 = tmp.x;
    y = tmp.y;
    z = tmp.z;
    if ( v15 > tmp.x )
    {
      if ( (float)((float)(tmp.z * tmp.z) + (float)(tmp.y * tmp.y)) <= 0.0 )
      {
        v16 = 1.0;
      }
      else
      {
        v19 = fsqrt((float)(1.0 - (float)(v15 * v15)) / (float)((float)(tmp.z * tmp.z) + (float)(tmp.y * tmp.y)));
        v16 = v15;
        y = tmp.y * v19;
        z = tmp.z * v19;
      }
    }
    tmp.x = *(float *)&attToWorld_36 * v16;
    tmp.y = *(float *)&attToWorld_36 * y;
    tmp.z = *(float *)&attToWorld_36 * z;
    VectorTransform(in1: &tmp.x, in2: (const matrix3x4_t *)v24, out: &eyeAng.x);
  }
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr
    || (v21 = m_pStudioHdr->m_pStudioHdr == nullptr, LODWORD(local.x) = this->m_pStudioHdr, v21) )
  {
    local.x = 0.0;
  }
  v22 = modelrender->__vftable;
  v23 = ((int (__thiscall *)(IClientRenderable *, QAngle *))this->GetBody)(a1: &this->IClientRenderable, a2: &eyeAng);
  ((void (__thiscall *)(IVModelRender *, _DWORD, int))v22->SetViewTarget)(
    a1: modelrender,
    a2: LODWORD(local.x),
    a3: v23);
  *result = (Vector)eyeAng;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100455C0
// Name: public: virtual void C_BaseFlex::OnThreadedDrawSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::OnThreadedDrawSetup(C_BaseFlex *this)
{
  C_BaseAnimating *v1; // esi
  CStudioHdr *m_pStudioHdr; // eax

  if ( (int)this->m_pIk >= 0 )
  {
    v1 = (C_BaseFlex *)((char *)this - 4);
    if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: v1);
    m_pStudioHdr = v1->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
      v1->CalcAttachments(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045610
// Name: public: static int C_BaseFlex::AddGlobalFlexController(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl C_BaseFlex::AddGlobalFlexController(char *szName)
{
  int v1; // eax
  int v2; // ebx
  char *v3; // eax
  int v4; // ecx

  v1 = C_BaseFlex::g_numflexcontrollers;
  v2 = 0;
  if ( C_BaseFlex::g_numflexcontrollers <= 0 )
  {
LABEL_4:
    if ( v1 < 384 )
    {
      if ( szName != nullptr
        && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(szName) + 1)) != nullptr )
      {
        strcpy(v3, szName);
      }
      else
      {
        v3 = nullptr;
      }
      v4 = C_BaseFlex::g_numflexcontrollers;
      C_BaseFlex::g_flexcontroller[C_BaseFlex::g_numflexcontrollers] = v3;
      C_BaseFlex::g_numflexcontrollers = v4 + 1;
    }
  }
  else
  {
    while ( _V_stricmp(s1: C_BaseFlex::g_flexcontroller[v2], s2: szName) != 0 )
    {
      v1 = C_BaseFlex::g_numflexcontrollers;
      if ( ++v2 >= C_BaseFlex::g_numflexcontrollers )
        goto LABEL_4;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100456A0
// Name: public: virtual bool C_BaseFlex::StartSceneEvent(class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *,class CChoreoActor __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseFlex::StartSceneEvent(
        C_BaseFlex *this,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event,
        CChoreoActor *actor,
        C_BaseEntity *pTarget)
{
  char result; // al

  switch ( CChoreoEvent::GetType(this: event) )
  {
    case EXPRESSION:
      goto $LN5_7;
    case SPEAK:
      if ( !info->m_bClientSide )
        goto LABEL_7;
      goto $LN5_7;
    case SEQUENCE:
      if ( !info->m_bClientSide )
        goto LABEL_7;
      result = C_BaseFlex::RequestStartSequenceSceneEvent(this, info, scene, event, actor, pTarget);
      break;
    case FLEXANIMATION:
      info->m_flWeight = 1.0;
$LN5_7:
      result = 1;
      break;
    default:
LABEL_7:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045740
// Name: public: void C_BaseFlex::SetFlexWeight(enum LocalFlexController_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::SetFlexWeight(C_BaseFlex *this, LocalFlexController_t index, float value)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  float v6; // xmm0_4
  __int32 v7; // ecx
  float v8; // xmm1_4
  float *v9; // ecx
  int v10; // xmm1_4

  if ( index >= DUMMY_NULL_FLEX_CONTROLLER && index < C_BaseAnimating::GetNumFlexControllers(this) )
  {
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v5 = m_pStudioHdr->m_pStudioHdr;
      v6 = value;
      v7 = v5->flexcontrollerindex + 20 * index;
      v8 = *(float *)&v5->name[v7 + 4];
      v9 = (float *)((char *)&v5->id + v7);
      if ( v8 != v9[3] )
      {
        v6 = (float)(value - v9[3]) / (float)(v8 - v9[3]);
        v10 = 0;
        if ( v6 < 0.0 || (v10 = 1065353216, v6 > 1.0) )
          v6 = *(float *)&v10;
      }
      this->m_flexWeight[index] = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100457F0
// Name: public: float C_BaseFlex::GetFlexWeight(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseFlex::GetFlexWeight(C_BaseFlex *this, LocalFlexController_t index)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  __int32 v5; // ecx
  float v6; // xmm0_4
  float *v7; // ecx

  if ( index < DUMMY_NULL_FLEX_CONTROLLER || index >= C_BaseAnimating::GetNumFlexControllers(this) )
    return 0.0;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0.0;
  v4 = m_pStudioHdr->m_pStudioHdr;
  v5 = v4->flexcontrollerindex + 20 * index;
  v6 = *(float *)&v4->name[v5 + 4];
  v7 = (float *)((char *)&v4->id + v5);
  if ( v6 == v7[3] )
    return this->m_flexWeight[index];
  else
    return v7[3] + (v6 - v7[3]) * this->m_flexWeight[index];
}

//------------------------------------------------------------------------------
// Address: 0x10045890
// Name: public: enum LocalFlexController_t C_BaseFlex::FindFlexController(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseFlex::FindFlexController(C_BaseFlex *this, const char *szName)
{
  LocalFlexController_t v3; // esi
  const char *FlexControllerName; // eax

  v3 = DUMMY_NULL_FLEX_CONTROLLER;
  if ( C_BaseAnimating::GetNumFlexControllers(this) <= 0 )
    return -1;
  while ( 1 )
  {
    FlexControllerName = C_BaseAnimating::GetFlexControllerName(this, iFlexController: v3);
    if ( _V_stricmp(s1: FlexControllerName, s2: szName) == 0 )
      break;
    if ( ++v3 >= C_BaseAnimating::GetNumFlexControllers(this) )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100458E0
// Name: public: CSceneEventInfo::CSceneEventInfo(class CSceneEventInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
CSceneEventInfo *__thiscall CSceneEventInfo::CSceneEventInfo(CSceneEventInfo *this, const CSceneEventInfo *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100459E0
// Name: public: void CByteswap::SwapBufferToTargetEndian<int>(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045A70
// Name: public: virtual bool C_BaseFlex::UsesFlexDelayedWeights(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseFlex::UsesFlexDelayedWeights(C_BaseFlex *this)
{
  return this->m_iMouthAttachment != 0
      && g_CV_FlexSmooth.m_pParent != nullptr
      && g_CV_FlexSmooth.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10045AA0
// Name: public: virtual void C_BaseFlex::BuildTransformations(class CStudioHdr __near *,class Vector __near *,class Quaternion __near * const,struct matrix3x4_t const __near &,int,class CBoneBitList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::BuildTransformations(
        C_BaseFlex *this,
        CStudioHdr *pStudioHdr,
        Vector *pos,
        Quaternion *q,
        const matrix3x4_t *cameraTransform,
        int boneMask,
        CBoneBitList *boneComputed)
{
  CStudioHdr *v7; // edx
  int studiohdr2index; // ecx
  int v9; // eax
  int v10; // ecx
  const studiohdr_t *v11; // edi
  int v12; // ebx
  int v13; // ecx
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  char *v17; // ecx
  float v18; // xmm0_4
  int v19; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v21; // eax
  int v22; // ecx
  float v23; // xmm1_4
  float *v24; // ecx
  const Vector *position; // [esp+4h] [ebp-18h]
  int v26; // [esp+8h] [ebp-14h]
  int version; // [esp+Ch] [ebp-10h]
  int v28; // [esp+10h] [ebp-Ch]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v7 = pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0 )
    v9 = *(_DWORD *)&pStudioHdr->m_pStudioHdr->name[studiohdr2index + 12];
  else
    v9 = 0;
  if ( v9 > 0 )
  {
    v28 = 0;
    v26 = v9;
    while ( 1 )
    {
      v10 = v7->m_pStudioHdr->studiohdr2index;
      v11 = v10 != 0
          ? (const studiohdr_t *)((char *)v7->m_pStudioHdr + v10 + v28 + *(_DWORD *)&v7->m_pStudioHdr->name[v10 + 16])
          : nullptr;
      position = &pos[v11->id];
      if ( v11->version > 0 )
        break;
LABEL_33:
      v28 += 24;
      if ( --v26 == 0 )
        goto LABEL_34;
    }
    v12 = 0;
    version = v11->version;
    while ( 1 )
    {
      v13 = v12 + v11->checksum;
      v14 = *(float *)((char *)&v11->checksum + v13);
      v15 = *(float *)&v11->name[v13];
      v16 = *(&position->x + *(int *)((char *)&v11->id + v13));
      v17 = (char *)v11 + v13;
      if ( v14 == v15 )
        break;
      v18 = (float)(v16 - v14) / (float)(v15 - v14);
      if ( v18 < 0.0 )
      {
LABEL_15:
        v18 = 0.0;
        goto LABEL_18;
      }
      if ( v18 > 1.0 )
        goto LABEL_17;
LABEL_18:
      v19 = *((_DWORD *)v17 + 1);
      if ( v19 < 0 || v19 >= C_BaseAnimating::GetNumFlexControllers(this) )
        goto LABEL_31;
      if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
        C_BaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
        goto LABEL_31;
      v21 = m_pStudioHdr->m_pStudioHdr;
      v22 = v21->flexcontrollerindex + 20 * v19;
      v23 = *(float *)&v21->name[v22 + 4];
      v24 = (float *)((char *)&v21->id + v22);
      if ( v23 == v24[3] )
      {
LABEL_30:
        this->m_flexWeight[v19] = v18;
        goto LABEL_31;
      }
      v18 = (float)(v18 - v24[3]) / (float)(v23 - v24[3]);
      if ( v18 >= 0.0 )
      {
        if ( v18 <= 1.0 )
          goto LABEL_30;
        this->m_flexWeight[v19] = 1.0;
      }
      else
      {
        this->m_flexWeight[v19] = 0.0;
      }
LABEL_31:
      v12 += 16;
      if ( --version == 0 )
      {
        v7 = pStudioHdr;
        goto LABEL_33;
      }
    }
    if ( (float)(v16 - v15) < 0.0 )
      goto LABEL_15;
LABEL_17:
    v18 = 1.0;
    goto LABEL_18;
  }
LABEL_34:
  C_BaseAnimating::BuildTransformations(
    this,
    a2: (int)&savedregs,
    hdr: v7,
    pos,
    q,
    cameraTransform,
    boneMask,
    boneComputed);
}

//------------------------------------------------------------------------------
// Address: 0x10045CA0
// Name: public: void C_BaseFlex::AddFlexAnimation(class CSceneEventInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::AddFlexAnimation(C_BaseFlex *this, CSceneEventInfo *info)
{
  CSceneEventInfo *v2; // esi
  CChoreoEvent *m_pEvent; // edi
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v6; // esi
  const char *FlexControllerName; // eax
  LocalFlexController_t FlexController; // eax
  const char *v9; // eax
  LocalFlexController_t v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  LocalFlexController_t v13; // eax
  int v14; // esi
  double v15; // xmm0_8
  float v16; // xmm0_4
  CChoreoScene *v17; // ebx
  CFlexAnimationTrack *v18; // eax
  CFlexAnimationTrack *v19; // edi
  int j; // esi
  LocalFlexController_t RawFlexControllerIndex; // ebx
  double FlexWeight; // st7
  LocalFlexController_t v23; // esi
  C_BaseFlex *v24; // edi
  double v25; // st7
  char name[512]; // [esp+14h] [ebp-218h] BYREF
  CChoreoEvent *event; // [esp+214h] [ebp-18h]
  float scenetime; // [esp+218h] [ebp-14h]
  C_BaseFlex *v29; // [esp+21Ch] [ebp-10h]
  CChoreoScene *scene; // [esp+220h] [ebp-Ch]
  float value; // [esp+224h] [ebp-8h]
  int i; // [esp+228h] [ebp-4h]

  v2 = info;
  v29 = this;
  if ( info != nullptr )
  {
    m_pEvent = info->m_pEvent;
    event = m_pEvent;
    if ( m_pEvent != nullptr )
    {
      scene = info->m_pScene;
      if ( scene != nullptr )
      {
        if ( !CChoreoEvent::GetTrackLookupSet(this: m_pEvent) )
        {
          *(float *)&i = 0.0;
          if ( CViewRender::BuildWorldListsNumber(this: m_pEvent) > 0 )
          {
            do
            {
              FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: m_pEvent, index: i);
              v6 = FlexAnimationTrack;
              if ( FlexAnimationTrack != nullptr )
              {
                if ( CFlexAnimationTrack::IsComboType(this: FlexAnimationTrack) )
                {
                  V_strncpy(pDest: name, pSrc: "right_", maxLen: 512);
                  FlexControllerName = CFlexAnimationTrack::GetFlexControllerName(this: v6);
                  V_strncat(pDest: name, pSrc: FlexControllerName, destBufferSize: 0x200u, max_chars_to_copy: -1);
                  if ( C_BaseFlex::FindFlexController(this, szName: name) <= 0 )
                    FlexController = DUMMY_NULL_FLEX_CONTROLLER;
                  else
                    FlexController = C_BaseFlex::FindFlexController(this, szName: name);
                  CFlexAnimationTrack::SetFlexControllerIndex(this: v6, raw: FlexController, index: 0, side: 0);
                  V_strncpy(pDest: name, pSrc: "left_", maxLen: 512);
                  v9 = CFlexAnimationTrack::GetFlexControllerName(this: v6);
                  V_strncat(pDest: name, pSrc: v9, destBufferSize: 0x200u, max_chars_to_copy: -1);
                  if ( C_BaseFlex::FindFlexController(this, szName: name) <= 0 )
                  {
                    CFlexAnimationTrack::SetFlexControllerIndex(
                      this: v6,
                      raw: DUMMY_NULL_FLEX_CONTROLLER,
                      index: 0,
                      side: 1);
                  }
                  else
                  {
                    v10 = C_BaseFlex::FindFlexController(this, szName: name);
                    CFlexAnimationTrack::SetFlexControllerIndex(this: v6, raw: v10, index: 0, side: 1);
                  }
                }
                else
                {
                  v11 = CFlexAnimationTrack::GetFlexControllerName(this: v6);
                  if ( C_BaseFlex::FindFlexController(this, szName: v11) <= 0 )
                  {
                    v13 = DUMMY_NULL_FLEX_CONTROLLER;
                  }
                  else
                  {
                    v12 = CFlexAnimationTrack::GetFlexControllerName(this: v6);
                    v13 = C_BaseFlex::FindFlexController(this, szName: v12);
                  }
                  CFlexAnimationTrack::SetFlexControllerIndex(this: v6, raw: v13, index: 0, side: 0);
                }
              }
              v14 = ++i;
            }
            while ( v14 < CViewRender::BuildWorldListsNumber(this: m_pEvent) );
            v2 = info;
          }
          CChoreoEvent::SetTrackLookupSet(this: m_pEvent, set: true);
        }
        if ( scene_clientflex.m_pParent != nullptr && scene_clientflex.m_pParent->m_Value.m_nValue != 0 )
        {
          scenetime = CChoreoScene::GetTime(this: scene);
          *(float *)&i = CChoreoEvent::GetIntensity(this: m_pEvent, scenetime);
          v15 = v2->m_flWeight + 0.1;
          if ( v15 >= 1.0 )
            v15 = 1.0;
          v16 = v15;
          v2->m_flWeight = v16;
          v17 = nullptr;
          *(float *)&i = v16 * *(float *)&i;
          scene = nullptr;
          if ( CViewRender::BuildWorldListsNumber(this: m_pEvent) > 0 )
          {
            while ( 1 )
            {
              v18 = CChoreoEvent::GetFlexAnimationTrack(this: m_pEvent, index: (int)v17);
              v19 = v18;
              if ( v18 != nullptr && CFlexAnimationTrack::IsTrackActive(this: v18) )
              {
                if ( CFlexAnimationTrack::IsComboType(this: v19) )
                {
                  for ( j = 0; j < 2; ++j )
                  {
                    RawFlexControllerIndex = CFlexAnimationTrack::GetRawFlexControllerIndex(this: v19, side: j);
                    value = CFlexAnimationTrack::GetIntensity(this: v19, time: scenetime, side: j);
                    if ( RawFlexControllerIndex >= DUMMY_NULL_FLEX_CONTROLLER )
                    {
                      FlexWeight = C_BaseFlex::GetFlexWeight(this: v29, index: RawFlexControllerIndex);
                      value = *(float *)&i * value + (1.0 - *(float *)&i) * FlexWeight;
                      C_BaseFlex::SetFlexWeight(this: v29, index: RawFlexControllerIndex, value);
                    }
                  }
                  v17 = scene;
                }
                else
                {
                  v23 = CFlexAnimationTrack::GetRawFlexControllerIndex(this: v19, side: 0);
                  value = CFlexAnimationTrack::GetIntensity(this: v19, time: scenetime, side: 0);
                  if ( v23 >= DUMMY_NULL_FLEX_CONTROLLER )
                  {
                    v24 = v29;
                    v25 = C_BaseFlex::GetFlexWeight(this: v29, index: v23);
                    value = *(float *)&i * value + (1.0 - *(float *)&i) * v25;
                    C_BaseFlex::SetFlexWeight(this: v24, index: v23, value);
                  }
                }
              }
              v17 = (CChoreoScene *)((char *)v17 + 1);
              scene = v17;
              if ( (int)v17 >= CViewRender::BuildWorldListsNumber(this: event) )
                break;
              m_pEvent = event;
            }
            v2 = info;
          }
          v2->m_bStarted = true;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100464D0
// Name: public: void C_BaseFlex::ClearSceneEvents(class CChoreoScene __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::ClearSceneEvents(C_BaseFlex *this, CChoreoScene *scene, BOOL canceled)
{
  int v4; // ebx
  int v5; // eax
  CSceneEventInfo *v6; // esi
  int v7; // [esp+4h] [ebp-4h]

  if ( scene != nullptr )
  {
    v4 = this->m_SceneEvents.m_Size - 1;
    if ( v4 >= 0 )
    {
      v5 = 76 * v4;
      v7 = 76 * v4;
      do
      {
        v6 = (CSceneEventInfo *)((char *)this->m_SceneEvents.m_Memory.m_pMemory + v5);
        if ( v6->m_pScene == scene )
        {
          this->ClearSceneEvent(this, a2: v6, a3: false, a4: canceled);
          v6->m_pEvent = nullptr;
          v6->m_pScene = nullptr;
          v6->m_bStarted = false;
          if ( this->m_SceneEvents.m_Size - v4 - 1 > 0 )
            _V_memmove(
              dest: (char *)this->m_SceneEvents.m_Memory.m_pMemory + v7,
              src: (char *)&this->m_SceneEvents.m_Memory.m_pMemory[1] + v7,
              count: 76 * (this->m_SceneEvents.m_Size - v4 - 1));
          --this->m_SceneEvents.m_Size;
          v5 = v7;
        }
        v5 -= 76;
        --v4;
        v7 = v5;
      }
      while ( v4 >= 0 );
    }
  }
  else
  {
    this->m_SceneEvents.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046580
// Name: public: void C_BaseFlex::RemoveSceneEvent(class CChoreoScene __near *,class CChoreoEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::RemoveSceneEvent(C_BaseFlex *this, CChoreoScene *scene, CChoreoEvent *event, BOOL fastKill)
{
  int v5; // ebx
  CSceneEventInfo *v6; // esi
  int i; // [esp+8h] [ebp-4h]

  v5 = 0;
  if ( this->m_SceneEvents.m_Size > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v6 = &this->m_SceneEvents.m_Memory.m_pMemory[i];
      if ( v6->m_pScene == scene
        && v6->m_pEvent == event
        && this->ClearSceneEvent(this, a2: v6, a3: fastKill, a4: false) )
      {
        break;
      }
      if ( ++v5 >= this->m_SceneEvents.m_Size )
        return;
    }
    v6->m_pEvent = nullptr;
    v6->m_pScene = nullptr;
    v6->m_bStarted = false;
    if ( this->m_SceneEvents.m_Size - v5 - 1 > 0 )
      _V_memmove(
        dest: &this->m_SceneEvents.m_Memory.m_pMemory[v5],
        src: &this->m_SceneEvents.m_Memory.m_pMemory[v5 + 1],
        count: 76 * (this->m_SceneEvents.m_Size - v5 - 1));
    --this->m_SceneEvents.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046E40
// Name: private: void CFlexSceneFileManager::DeleteSceneFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexSceneFileManager::DeleteSceneFiles(CFlexSceneFileManager *this)
{
  CFlexSceneFile *v2; // edi

  while ( this->m_FileList.m_Size > 0 )
  {
    v2 = *this->m_FileList.m_Memory.m_pMemory;
    if ( this->m_FileList.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_FileList.m_Memory.m_pMemory,
        src: this->m_FileList.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_FileList.m_Size - 1));
    --this->m_FileList.m_Size;
    C_BaseEntity::operator delete(pMem: v2->buffer);
    C_BaseEntity::operator delete(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046EA0
// Name: public: virtual void CFlexSceneFileManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFlexSceneFileManager::Shutdown(CFlexSceneFileManager *this)
{
  CFlexSceneFileManager::DeleteSceneFiles(this);
}

//------------------------------------------------------------------------------
// Address: 0x10046EB0
// Name: public: void C_BaseFlex::RemoveChoreoScene(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::RemoveChoreoScene(C_BaseFlex *this, CChoreoScene *scene)
{
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ActiveChoreoScenes,
    src: (vgui::TreeNode **)&scene);
}

//------------------------------------------------------------------------------
// Address: 0x10046F90
// Name: public: virtual C_BaseFlex::~C_BaseFlex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::~C_BaseFlex(C_BaseFlex *this)
{
  float *m_flFlexDelayedWeight; // eax
  CInterpolatedVarEntryBase<Vector,0> *m_pElements; // eax

  m_flFlexDelayedWeight = this->m_flFlexDelayedWeight;
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseFlex_vtbl *)&C_BaseFlex::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseFlex::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseFlex::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseFlex::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseFlex::`vftable';
  if ( m_flFlexDelayedWeight != nullptr )
  {
    C_BaseEntity::operator delete(pMem: m_flFlexDelayedWeight);
    this->m_flFlexDelayedWeight = nullptr;
  }
  this->m_SceneEvents.m_Size = 0;
  CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LocalToGlobal);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_CachedDelayedFlexWeights);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_CachedFlexWeights);
  CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::~CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>(this: &this->m_LocalToGlobal);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ActiveChoreoScenes);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SceneEvents);
  this->m_iv_flexWeight.__vftable = (CInterpolatedVarArray<float,96>_vtbl *)&CInterpolatedVarArrayBase<float,1>::`vftable';
  CInterpolatedVarArrayBase<float,1>::ClearHistory(this: &this->m_iv_flexWeight);
  C_BaseEntity::operator delete(pMem: this->m_iv_flexWeight.m_bLooping);
  C_BaseEntity::operator delete(pMem: this->m_iv_flexWeight.m_LastNetworkedValue);
  CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>::~CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>(this: &this->m_iv_flexWeight.m_VarHistory);
  this->m_iv_flexWeight.__vftable = (CInterpolatedVarArray<float,96>_vtbl *)&IInterpolatedVar::`vftable';
  this->m_iv_viewtarget.__vftable = (CInterpolatedVar<Vector>_vtbl *)&CInterpolatedVarArrayBase<Vector,0>::`vftable';
  *(_DWORD *)&this->m_iv_viewtarget.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_viewtarget.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_viewtarget.m_LastNetworkedValue);
  m_pElements = this->m_iv_viewtarget.m_VarHistory.m_pElements;
  if ( m_pElements != nullptr )
    C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.z);
  this->m_iv_viewtarget.m_VarHistory.m_pElements = nullptr;
  this->m_iv_viewtarget.__vftable = (CInterpolatedVar<Vector>_vtbl *)&IInterpolatedVar::`vftable';
  C_BaseAnimatingOverlay::~C_BaseAnimatingOverlay(this);
}

//------------------------------------------------------------------------------
// Address: 0x100470F0
// Name: public: void C_BaseFlex::StartChoreoScene(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::StartChoreoScene(C_BaseFlex *this, CChoreoScene *scene)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_ActiveChoreoScenes; // esi
  int m_Size; // ecx
  int v4; // eax
  CChoreoScene **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_ActiveChoreoScenes = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ActiveChoreoScenes;
  m_Size = this->m_ActiveChoreoScenes.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CChoreoScene **)p_m_ActiveChoreoScenes->m_pMemory;
  while ( *m_pMemory != scene )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_ActiveChoreoScenes->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_ActiveChoreoScenes, num: m_Size - m_nAllocationCount + 1);
    ++p_m_ActiveChoreoScenes[1].m_pMemory;
    v8 = p_m_ActiveChoreoScenes->m_pMemory;
    v9 = (int)p_m_ActiveChoreoScenes[1].m_pMemory - v7 - 1;
    p_m_ActiveChoreoScenes[1].m_nAllocationCount = (int)p_m_ActiveChoreoScenes->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_ActiveChoreoScenes->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)scene;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047180
// Name: public: void C_BaseFlex::AddSceneEvent(class CChoreoScene __near *,class CChoreoEvent __near *,class C_BaseEntity __near *,bool,class C_SceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::AddSceneEvent(
        C_BaseFlex *this,
        CChoreoActor *scene,
        CChoreoEvent *event,
        C_BaseEntity *pTarget,
        bool bClientSide,
        C_SceneEntity *pSceneEntity)
{
  CSceneEventInfo info; // [esp+8h] [ebp-50h] BYREF
  C_BaseFlex *v8; // [esp+54h] [ebp-4h]
  CChoreoActor *actor; // [esp+60h] [ebp+8h]

  v8 = this;
  if ( scene != nullptr && event != nullptr )
  {
    actor = CChoreoEvent::GetActor(this: event);
    if ( actor != nullptr )
    {
      memset(dst: (int)&info, value: nullptr, count: sizeof(info));
      info.m_pEvent = event;
      info.m_pScene = (CChoreoScene *)scene;
      if ( pTarget != nullptr )
        info.m_hTarget.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
      else
        info.m_hTarget.m_Index = -1;
      info.m_bStarted = false;
      info.m_bClientSide = bClientSide;
      if ( pSceneEntity != nullptr )
        info.m_hSceneEntity.m_Index = pSceneEntity->GetRefEHandle(this: pSceneEntity)->m_Index;
      else
        info.m_hSceneEntity.m_Index = -1;
      if ( v8->StartSceneEvent(this: v8, a2: &info, a3: (CChoreoScene *)scene, a4: event, a5: actor, a6: pTarget) )
        CUtlVector<CSceneEventInfo,CUtlMemory<CSceneEventInfo,int>>::InsertBefore(
          this: &v8->m_SceneEvents,
          elem: v8->m_SceneEvents.m_Size,
          src: &info);
      else
        CChoreoScene::SceneMsg(this: (CChoreoScene *)scene, pFormat: "C_BaseFlex::AddSceneEvent:  event failed\n");
    }
    else
    {
      _Msg(a1: "C_BaseFlex::AddSceneEvent:  event->GetActor() was NULL!!!\n");
    }
  }
  else
  {
    _Msg(a1: "C_BaseFlex::AddSceneEvent:  scene or event was NULL!!!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047290
// Name: public: C_BaseFlex::C_BaseFlex(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseFlex *__thiscall C_BaseFlex::C_BaseFlex(C_BaseFlex *this)
{
  UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short> *m_pMemory; // ecx

  C_BaseAnimatingOverlay::C_BaseAnimatingOverlay(this);
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseFlex_vtbl *)&C_BaseFlex::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseFlex::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseFlex::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseFlex::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseFlex::`vftable';
  this->m_iv_viewtarget.__vftable = (CInterpolatedVar<Vector>_vtbl *)&CInterpolatedVarArrayBase<Vector,0>::`vftable';
  this->m_iv_viewtarget.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_viewtarget.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_viewtarget.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
    this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0> > *)&this->m_iv_viewtarget.m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<QAngle,0> *)4);
  this->m_iv_viewtarget.m_pDebugName = "C_BaseFlex::m_iv_viewtarget";
  this->m_iv_viewtarget.m_pValue = nullptr;
  this->m_iv_viewtarget.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_viewtarget.m_fType = 1;
  this->m_iv_viewtarget.m_LastNetworkedTime = 0.0;
  this->m_iv_viewtarget.m_LastNetworkedValue = nullptr;
  this->m_iv_viewtarget.m_bLooping = nullptr;
  this->m_iv_viewtarget.__vftable = (CInterpolatedVar<Vector>_vtbl *)&CInterpolatedVar<Vector>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(
    this: (CInterpolatedVarArrayBase<QAngle,0> *)&this->m_iv_viewtarget,
    flCurrentTime: 0.0,
    newmax: 1);
  this->m_iv_flexWeight.__vftable = (CInterpolatedVarArray<float,96>_vtbl *)&CInterpolatedVarArrayBase<float,1>::`vftable';
  this->m_iv_flexWeight.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_flexWeight.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_flexWeight.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
    this: &this->m_iv_flexWeight.m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<float,1> *)4);
  this->m_iv_flexWeight.m_pDebugName = "C_BaseFlex:m_iv_flexWeight";
  this->m_iv_flexWeight.m_pValue = nullptr;
  this->m_iv_flexWeight.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_flexWeight.m_fType = 1;
  this->m_iv_flexWeight.m_LastNetworkedTime = 0.0;
  this->m_iv_flexWeight.m_LastNetworkedValue = nullptr;
  this->m_iv_flexWeight.m_bLooping = nullptr;
  this->m_iv_flexWeight.__vftable = (CInterpolatedVarArray<float,96>_vtbl *)&CInterpolatedVarArray<float,96>::`vftable';
  CInterpolatedVarArrayBase<float,1>::SetMaxCount(this: &this->m_iv_flexWeight, flCurrentTime: 0.0, newmax: 96);
  this->m_SceneEvents.m_Memory.m_pMemory = nullptr;
  this->m_SceneEvents.m_Memory.m_nAllocationCount = 0;
  this->m_SceneEvents.m_Memory.m_nGrowSize = 0;
  this->m_SceneEvents.m_Size = 0;
  this->m_SceneEvents.m_pElements = nullptr;
  this->m_ActiveChoreoScenes.m_Memory.m_pMemory = nullptr;
  this->m_ActiveChoreoScenes.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveChoreoScenes.m_Memory.m_nGrowSize = 0;
  this->m_ActiveChoreoScenes.m_Size = 0;
  this->m_ActiveChoreoScenes.m_pElements = nullptr;
  this->m_LocalToGlobal.m_LessFunc = CDefOps<C_BaseEntity *>::LessFunc;
  this->m_LocalToGlobal.m_Elements.m_pMemory = nullptr;
  this->m_LocalToGlobal.m_Elements.m_nAllocationCount = 0;
  this->m_LocalToGlobal.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_LocalToGlobal.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_LocalToGlobal.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_LocalToGlobal.m_FirstFree = -1;
  this->m_LocalToGlobal.m_pElements = m_pMemory;
  this->m_CachedFlexWeights.m_Memory.m_pMemory = nullptr;
  this->m_CachedFlexWeights.m_Memory.m_nAllocationCount = 0;
  this->m_CachedFlexWeights.m_Memory.m_nGrowSize = 0;
  this->m_CachedFlexWeights.m_Size = 0;
  this->m_CachedFlexWeights.m_pElements = nullptr;
  this->m_CachedDelayedFlexWeights.m_Memory.m_pMemory = nullptr;
  this->m_CachedDelayedFlexWeights.m_Memory.m_nAllocationCount = 0;
  this->m_CachedDelayedFlexWeights.m_Memory.m_nGrowSize = 0;
  this->m_CachedDelayedFlexWeights.m_Size = 0;
  this->m_CachedDelayedFlexWeights.m_pElements = nullptr;
  C_BaseEntity::AddVar(
    this,
    data: (void *)&this->m_viewtarget,
    watcher: &this->m_iv_viewtarget,
    type: 17,
    bSetup: false);
  C_BaseEntity::AddVar(this, data: this->m_flexWeight, watcher: &this->m_iv_flexWeight, type: 1, bSetup: false);
  C_BaseFlex::SetupMappings(this, pchFileRoot: "phonemes");
  this->m_flFlexDelayedWeight = nullptr;
  this->m_iMostRecentFlexCounter = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100474B0
// Name: public: virtual class CStudioHdr __near * C_BaseFlex::OnNewModel(void)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall C_BaseFlex::OnNewModel(C_BaseFlex *this)
{
  CStudioHdr *v2; // edi
  float *m_flFlexDelayedWeight; // eax
  int numflexdesc; // edi
  float *v5; // eax
  unsigned int v6; // edi
  CStudioHdr *hdr; // [esp+14h] [ebp-4h]

  v2 = C_BaseAnimatingOverlay::OnNewModel(this);
  this->m_iBlink = -1;
  this->m_iEyeUpdown = DUMMY_INVALID_FLEX_CONTROLLER;
  this->m_iEyeRightleft = DUMMY_INVALID_FLEX_CONTROLLER;
  m_flFlexDelayedWeight = this->m_flFlexDelayedWeight;
  hdr = v2;
  this->m_iMouthAttachment = 0;
  if ( m_flFlexDelayedWeight != nullptr )
  {
    C_BaseEntity::operator delete(pMem: m_flFlexDelayedWeight);
    this->m_flFlexDelayedWeight = nullptr;
  }
  if ( v2 != nullptr )
  {
    numflexdesc = v2->m_pStudioHdr->numflexdesc;
    this->m_CachedFlexWeights.m_Size = 0;
    CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
      this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&this->m_CachedFlexWeights,
      elem: 0,
      num: numflexdesc);
    this->m_CachedDelayedFlexWeights.m_Size = 0;
    CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
      this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&this->m_CachedDelayedFlexWeights,
      elem: 0,
      num: numflexdesc);
    if ( numflexdesc != 0 )
    {
      v5 = (float *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)numflexdesc >> 30 != 0 ? -1 : 4 * numflexdesc);
      v6 = 4 * numflexdesc;
      this->m_flFlexDelayedWeight = v5;
      memset(dst: (int)v5, value: nullptr, count: v6);
      memset(dst: (int)this->m_CachedFlexWeights.m_Memory.m_pMemory, value: nullptr, count: v6);
      memset(dst: (int)this->m_CachedDelayedFlexWeights.m_Memory.m_pMemory, value: nullptr, count: v6);
    }
    v2 = hdr;
    CInterpolatedVarArrayBase<float,1>::SetMaxCount(
      this: &this->m_iv_flexWeight,
      flCurrentTime: *(float *)(gpGlobals.m_Index + 12),
      newmax: hdr->m_pStudioHdr->numflexcontrollers);
    this->m_iMouthAttachment = this->LookupAttachment(this: &this->IClientRenderable, a2: "mouth");
    this->m_iEyeUpdown = C_BaseFlex::FindFlexController(this, szName: "eyes_updown");
    this->m_iEyeRightleft = C_BaseFlex::FindFlexController(this, szName: "eyes_rightleft");
    this->m_iBlink = C_BaseFlex::AddGlobalFlexController(szName: "blink");
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100477D0
// Name: public: void C_BaseFlex::EnsureTranslations(struct flexsettinghdr_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::EnsureTranslations(C_BaseFlex *this, const flexsettinghdr_t *pSettinghdr)
{
  const flexsettinghdr_t *v2; // esi
  CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl*)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short> > *p_m_LocalToGlobal; // edi
  int v4; // ebx
  int v5; // eax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // esi
  UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short> *v10; // eax
  int v11; // edx
  UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short> *v13; // ecx
  const flexsettinghdr_t **p_m_Key; // esi
  const flexsettinghdr_t *v15; // eax
  const flexsettinghdr_t *v16; // [esp-4h] [ebp-20h]
  C_BaseFlex::FS_LocalToGlobal_t entry; // [esp+Ch] [ebp-10h] BYREF
  unsigned __int16 parent[2]; // [esp+18h] [ebp-4h] BYREF

  v2 = pSettinghdr;
  p_m_LocalToGlobal = &this->m_LocalToGlobal;
  v4 = 0;
  entry.m_Key = pSettinghdr;
  entry.m_nCount = 0;
  entry.m_Mapping = nullptr;
  if ( CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_LocalToGlobal,
         search: &entry) == 0xFFFF )
  {
    entry.m_nCount = v2->numkeys;
    entry.m_Mapping = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)entry.m_nCount >> 30 != 0 ? -1 : 4 * entry.m_nCount);
    _V_memset(dest: entry.m_Mapping, fill: 0, count: 4 * entry.m_nCount);
    if ( v2->numkeys > 0 )
    {
      do
      {
        v5 = C_BaseFlex::AddGlobalFlexController(szName: (char *)v2 + *(int *)((char *)&v2->id
                                                                             + 4 * v4
                                                                             + v2->keynameindex));
        entry.m_Mapping[v4++] = v5;
      }
      while ( v4 < v2->numkeys );
    }
    *(_DWORD *)parent = 0xFFFF;
    HIBYTE(pSettinghdr) = 0;
    CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: p_m_LocalToGlobal,
      insert: &entry,
      parent,
      leftchild: (bool *)&pSettinghdr + 3);
    v6 = CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::NewNode(
           this: p_m_LocalToGlobal,
           a2: (const char *)p_m_LocalToGlobal);
    v7 = parent[0];
    v8 = v6;
    v9 = v6;
    v10 = &p_m_LocalToGlobal->m_Elements.m_pMemory[v9];
    v10->m_Right = -1;
    v10->m_Left = -1;
    v10->m_Parent = v7;
    v10->m_Tag = 0;
    if ( v7 == 0xFFFF )
    {
      p_m_LocalToGlobal->m_Root = v8;
    }
    else
    {
      v11 = v7;
      m_pMemory = p_m_LocalToGlobal->m_Elements.m_pMemory;
      if ( HIBYTE(pSettinghdr) != 0 )
        m_pMemory[v11].m_Left = v8;
      else
        m_pMemory[v11].m_Right = v8;
    }
    CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: p_m_LocalToGlobal,
      elem: v8);
    v13 = p_m_LocalToGlobal->m_Elements.m_pMemory;
    ++p_m_LocalToGlobal->m_NumElements;
    p_m_Key = &v13[v9].m_Data.m_Key;
    if ( p_m_Key != nullptr )
    {
      v16 = p_m_Key[2];
      *p_m_Key = entry.m_Key;
      C_BaseEntity::operator delete(pMem: (void *)v16);
      v15 = (const flexsettinghdr_t *)MemAlloc_Alloc(
                                        nSize: (unsigned __int64)(unsigned int)entry.m_nCount >> 30 != 0
                                      ? -1
                                      : 4 * entry.m_nCount);
      p_m_Key[2] = v15;
      _V_memcpy(dest: (void *)v15, src: entry.m_Mapping, count: 4 * entry.m_nCount);
      p_m_Key[1] = (const flexsettinghdr_t *)entry.m_nCount;
    }
  }
  C_BaseEntity::operator delete(pMem: entry.m_Mapping);
}

//------------------------------------------------------------------------------
// Address: 0x10047970
// Name: public: int C_BaseFlex::FlexControllerLocalToGlobal(struct flexsettinghdr_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseFlex::FlexControllerLocalToGlobal(C_BaseFlex *this, const flexsettinghdr_t *pSettinghdr, int key)
{
  int v4; // edi
  char *Classname; // eax
  int v6; // eax
  int v7; // esi
  const char *v9; // [esp-4h] [ebp-1Ch]
  const char *v10; // [esp+0h] [ebp-18h]
  C_BaseFlex::FS_LocalToGlobal_t entry; // [esp+Ch] [ebp-Ch] BYREF

  entry.m_nCount = 0;
  entry.m_Mapping = nullptr;
  entry.m_Key = pSettinghdr;
  v4 = CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_LocalToGlobal,
         search: &entry);
  if ( v4 == 0xFFFF )
  {
    Classname = C_BaseEntity::GetClassname(this);
    v6 = ((int (__thiscall *)(IClientNetworkable *, char *))this->entindex)(
           a1: &this->IClientNetworkable,
           a2: Classname);
    _Warning(a1: "Unable to find mapping for flexcontroller %i, settings %p on %i/%s\n", key, pSettinghdr, v6, v9);
    C_BaseFlex::EnsureTranslations(this, pSettinghdr);
    v4 = CUtlRBTree<C_BaseFlex::FS_LocalToGlobal_t,unsigned short,bool (__cdecl *)(C_BaseFlex::FS_LocalToGlobal_t const &,C_BaseFlex::FS_LocalToGlobal_t const &),CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_LocalToGlobal,
           search: &entry);
    if ( v4 == 0xFFFF )
      _Error(this: (ISceneTokenProcessor *)&stru_10450110, a2: v10);
  }
  v7 = this->m_LocalToGlobal.m_Elements.m_pMemory[(unsigned __int16)v4].m_Data.m_Mapping[key];
  C_BaseEntity::operator delete(pMem: entry.m_Mapping);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10047A30
// Name: private: void C_BaseFlex::AddFlexSetting(float __near *,char const __near *,float,struct flexsettinghdr_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::AddFlexSetting(
        C_BaseFlex *this,
        float *pGlobalFlexWeight,
        const char *expr,
        float scale,
        const flexsettinghdr_t *pSettinghdr,
        bool newexpression)
{
  int v7; // esi
  const char *v8; // edi
  int v9; // esi
  bool v10; // zf
  float *v11; // esi
  int v12; // edi
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm2_4
  const flexsettinghdr_t *pSettinghdra; // [esp+24h] [ebp+14h]
  const flexsettinghdr_t *pSettinghdrb; // [esp+24h] [ebp+14h]

  v7 = 0;
  if ( pSettinghdr->numflexsettings > 0 )
  {
    pSettinghdra = nullptr;
    do
    {
      v8 = (char *)pSettinghdra + pSettinghdr->flexsettingindex + (_DWORD)pSettinghdr;
      if ( v8 != nullptr && _V_stricmp(s1: &v8[*(_DWORD *)v8], s2: expr) == 0 )
        break;
      pSettinghdra = (const flexsettinghdr_t *)((char *)pSettinghdra + 24);
      ++v7;
    }
    while ( v7 < pSettinghdr->numflexsettings );
    if ( v7 < pSettinghdr->numflexsettings )
    {
      v9 = *((_DWORD *)v8 + 5);
      v10 = &v8[v9] == nullptr;
      v11 = (float *)&v8[v9];
      v12 = *((_DWORD *)v8 + 2);
      if ( !v10 && v12 > 0 )
      {
        pSettinghdrb = (const flexsettinghdr_t *)v12;
        do
        {
          v13 = C_BaseFlex::FlexControllerLocalToGlobal(this, pSettinghdr, key: *(_DWORD *)v11);
          v14 = v11[2] * scale;
          if ( v14 >= 0.0 )
          {
            if ( v14 > 1.0 )
              v14 = 1.0;
          }
          else
          {
            v14 = 0.0;
          }
          v15 = v11[1] * v14;
          v11 += 3;
          v10 = pSettinghdrb == (const flexsettinghdr_t *)1;
          pSettinghdrb = (const flexsettinghdr_t *)((char *)pSettinghdrb - 1);
          pGlobalFlexWeight[v13] = (float)((float)(1.0 - v14) * pGlobalFlexWeight[v13]) + v15;
        }
        while ( !v10 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047B00
// Name: public: void const __near * CFlexSceneFileManager::FindSceneFile(class C_BaseFlex __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFlexSceneFileManager::FindSceneFile(
        CFlexSceneFileManager *this,
        C_BaseFlex *instance,
        char *filename,
        bool allowBlockingIO)
{
  int v5; // edi
  CFlexSceneFile *v6; // ebx
  IFileSystem_vtbl *v8; // edi
  char *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CFlexSceneFile **m_pMemory; // ecx
  int v13; // eax
  CFlexSceneFile **v14; // edi
  char szFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  _V_strcpy(dest: szFilename, src: filename);
  V_FixSlashes(pname: szFilename, separator: 92);
  v5 = 0;
  if ( this->m_FileList.m_Size <= 0 )
  {
LABEL_5:
    if ( !allowBlockingIO )
      return nullptr;
    filename = nullptr;
    v8 = filesystem->IAppSystem::__vftable;
    v9 = VarArgs(format: "expressions/%s.vfe", szFilename);
    if ( v8->ReadFileEx(
           this: filesystem,
           a2: v9,
           a3: "GAME",
           a4: (void **)&filename,
           a5: false,
           a6: false,
           a7: 0,
           a8: 0,
           a9: nullptr) == 0 )
      return nullptr;
    v6 = (CFlexSceneFile *)MemAlloc_Alloc(nSize: 0x84u);
    V_strncpy(pDest: v6->filename, pSrc: szFilename, maxLen: 128);
    v6->buffer = filename;
    m_Size = this->m_FileList.m_Size;
    m_nAllocationCount = this->m_FileList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FileList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_FileList.m_Size;
    m_pMemory = this->m_FileList.m_Memory.m_pMemory;
    v13 = this->m_FileList.m_Size - m_Size - 1;
    this->m_FileList.m_pElements = m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
    v14 = &this->m_FileList.m_Memory.m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = v6;
  }
  else
  {
    while ( 1 )
    {
      v6 = this->m_FileList.m_Memory.m_pMemory[v5];
      if ( v6 != nullptr && _V_stricmp(s1: v6->filename, s2: szFilename) == 0 )
        break;
      if ( ++v5 >= this->m_FileList.m_Size )
        goto LABEL_5;
    }
  }
  if ( instance != nullptr )
    C_BaseFlex::EnsureTranslations(this: instance, pSettinghdr: (const flexsettinghdr_t *)v6->buffer);
  return v6->buffer;
}

//------------------------------------------------------------------------------
// Address: 0x10047C60
// Name: public: void const __near * C_BaseFlex::FindSceneFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall C_BaseFlex::FindSceneFile(C_BaseFlex *this, const char *filename)
{
  C_BaseFlex *v2; // edi
  bool v3; // zf
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // edx
  int studiohdr2index; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  const char *name; // esi
  void *result; // eax
  char *v12; // eax
  char *v13; // edx
  char v14; // cl
  int v15; // edi
  CFlexSceneFile *v16; // esi
  char dest[260]; // [esp+8h] [ebp-108h] BYREF
  C_BaseFlex *v18; // [esp+10Ch] [ebp-4h]

  v2 = this;
  v3 = this->m_pStudioHdr == nullptr;
  v18 = this;
  if ( v3 && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: v2);
  m_pStudioHdr = v2->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return (void *)CFlexSceneFileManager::FindSceneFile(
                     this: &g_FlexSceneFileManager,
                     instance: v2,
                     filename,
                     allowBlockingIO: false);
  v5 = m_pStudioHdr->m_pStudioHdr;
  studiohdr2index = m_pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&v5->name[studiohdr2index + 8], v8 = (int)v5 + studiohdr2index, v7 != 0)
    && v8 + v7 != 0 )
  {
    v9 = *(_DWORD *)(v8 + 20);
    if ( v9 == 0 )
      return (void *)CFlexSceneFileManager::FindSceneFile(
                       this: &g_FlexSceneFileManager,
                       instance: v2,
                       filename,
                       allowBlockingIO: false);
    name = (const char *)(v9 + v8);
  }
  else
  {
    name = v5->name;
  }
  if ( name == nullptr )
    return (void *)CFlexSceneFileManager::FindSceneFile(
                     this: &g_FlexSceneFileManager,
                     instance: v2,
                     filename,
                     allowBlockingIO: false);
  if ( StringAfterPrefix(str: name, prefix: "models") != nullptr )
  {
    v12 = (char *)(StringAfterPrefix(str: name, prefix: "models") + 1);
    v13 = (char *)(szExtendedPath - v12);
    do
    {
      v14 = *v12;
      v12[(_DWORD)v13] = *v12;
      ++v12;
    }
    while ( v14 != 0 );
  }
  else
  {
    strcpy(szExtendedPath, name);
  }
  V_StripExtension(in: szExtendedPath, out: szExtendedPath, outSize: 260);
  V_FixupPathName(pOut: szExtendedPath, nOutLen: 260, pPath: szExtendedPath);
  if ( _V_strlen(str: szExtendedPath) <= 2 )
    return (void *)CFlexSceneFileManager::FindSceneFile(
                     this: &g_FlexSceneFileManager,
                     instance: v2,
                     filename,
                     allowBlockingIO: false);
  while ( 1 )
  {
    V_ComposeFileName(path: szExtendedPath, filename, dest: szExtendedName, destSize: 260);
    _V_strcpy(dest, src: szExtendedName);
    V_FixSlashes(pname: dest, separator: 92);
    v15 = 0;
    if ( g_FlexSceneFileManager.m_FileList.m_Size > 0 )
    {
      while ( 1 )
      {
        v16 = g_FlexSceneFileManager.m_FileList.m_Memory.m_pMemory[v15];
        if ( v16 != nullptr && _V_stricmp(s1: v16->filename, s2: dest) == 0 )
          break;
        if ( ++v15 >= g_FlexSceneFileManager.m_FileList.m_Size )
          goto LABEL_26;
      }
      C_BaseFlex::EnsureTranslations(this: v18, pSettinghdr: (const flexsettinghdr_t *)v16->buffer);
      result = v16->buffer;
      if ( result != nullptr )
        return result;
    }
LABEL_26:
    if ( V_StripLastDir(dirName: szExtendedPath, maxlen: 0x104u) == 0 || _V_strlen(str: szExtendedPath) <= 2 )
    {
      v2 = v18;
      return (void *)CFlexSceneFileManager::FindSceneFile(
                       this: &g_FlexSceneFileManager,
                       instance: v2,
                       filename,
                       allowBlockingIO: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047E40
// Name: private: bool C_BaseFlex::SetupEmphasisBlend(struct C_BaseFlex::Emphasized_Phoneme __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseFlex::SetupEmphasisBlend(C_BaseFlex *this, C_BaseFlex::Emphasized_Phoneme *classes, int phoneme)
{
  int v3; // edi
  const flexsettinghdr_t **i; // esi
  bool v5; // zf
  const flexsettinghdr_t *v6; // eax
  int v7; // ecx
  const flexsettinghdr_t *v8; // ecx

  v3 = 0;
  for ( i = &classes->base; ; i += 21 )
  {
    v5 = *((_BYTE *)i - 3) == 0;
    *((_BYTE *)i + 8) = 0;
    i[3] = nullptr;
    if ( v5 )
    {
      *((_BYTE *)i - 3) = 1;
      *i = (const flexsettinghdr_t *)C_BaseFlex::FindSceneFile(this, filename: (const char *)i - 68);
    }
    v6 = *i;
    i[1] = nullptr;
    if ( v6 != nullptr )
    {
      if ( phoneme < 0
        || phoneme >= v6->numindexes
        || (v7 = *(int *)((char *)&v6->id + 4 * phoneme + v6->indexindex)) == -1 )
      {
        v8 = nullptr;
      }
      else
      {
        v8 = (const flexsettinghdr_t *)((char *)v6 + 24 * v7 + v6->flexsettingindex);
      }
      i[1] = v8;
    }
    if ( *((_BYTE *)i - 4) != 0 && (v6 == nullptr || i[1] == nullptr) )
      break;
    if ( i[1] != nullptr )
      *((_BYTE *)i + 8) = 1;
    if ( ++v3 >= 3 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10047EF0
// Name: private: bool C_BaseFlex::ProcessFlexSettingSceneEvent(float __near *,class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseFlex::ProcessFlexSettingSceneEvent(
        C_BaseFlex *this,
        float *pGlobalFlexWeight,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  const char *Parameters; // ebx
  const char *Parameters2; // eax
  const flexsettinghdr_t *SceneFile; // eax
  const char *name; // [esp+18h] [ebp-8h]
  float scale; // [esp+34h] [ebp+14h]
  float scalea; // [esp+34h] [ebp+14h]

  if ( CChoreoEvent::CurveHasEndTime(this: event) )
  {
    Parameters = CChoreoEvent::GetParameters(this: event);
    Parameters2 = CChoreoEvent::GetParameters2(this: event);
    name = Parameters2;
    if ( Parameters != nullptr && Parameters2 != nullptr )
    {
      if ( info->m_pExpHdr != nullptr
        || (SceneFile = (const flexsettinghdr_t *)C_BaseFlex::FindSceneFile(this, filename: Parameters),
            info->m_pExpHdr = SceneFile,
            SceneFile != nullptr) )
      {
        scale = CChoreoScene::GetTime(this: scene);
        scalea = CChoreoEvent::GetIntensity(this: event, scenetime: scale);
        C_BaseFlex::AddFlexSetting(
          this,
          pGlobalFlexWeight,
          expr: name,
          scale: scalea,
          pSettinghdr: info->m_pExpHdr,
          newexpression: !info->m_bStarted);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10047FA0
// Name: private: bool C_BaseFlex::ProcessSceneEvent(float __near *,bool,class CSceneEventInfo __near *,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseFlex::ProcessSceneEvent(
        C_BaseFlex *this,
        float *pGlobalFlexWeight,
        bool bFlexEvents,
        CSceneEventInfo *info,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  char result; // al

  switch ( CChoreoEvent::GetType(this: event) )
  {
    case EXPRESSION:
      if ( bFlexEvents )
        goto LABEL_5;
      return C_BaseFlex::ProcessFlexSettingSceneEvent(this, pGlobalFlexWeight, info, scene, event);
    case SPEAK:
      if ( info->m_bClientSide )
        goto LABEL_5;
      goto LABEL_12;
    case SEQUENCE:
      if ( !info->m_bClientSide )
        goto LABEL_12;
      if ( bFlexEvents )
LABEL_5:
        result = 1;
      else
        result = this->ProcessSequenceSceneEvent(this, a2: info, a3: scene, a4: event);
      break;
    case FLEXANIMATION:
      if ( bFlexEvents && CChoreoEvent::CurveHasEndTime(this: event) )
        C_BaseFlex::AddFlexAnimation(this, info);
      goto LABEL_5;
    default:
LABEL_12:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048060
// Name: public: virtual bool CFlexSceneFileManager::InitRecursive(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFlexSceneFileManager::InitRecursive(CFlexSceneFileManager *this, const char *pFolder)
{
  const char *v2; // ebx
  const char *i; // esi
  const char *FileExtension; // eax
  int v6; // eax
  char fullFileName[260]; // [esp+Ch] [ebp-410h] BYREF
  char folderpath[260]; // [esp+110h] [ebp-30Ch] BYREF
  char directory[260]; // [esp+214h] [ebp-208h] BYREF
  char vfeName[260]; // [esp+318h] [ebp-104h] BYREF

  v2 = pFolder;
  if ( pFolder == nullptr )
    v2 = "expressions";
  V_snprintf(pDest: directory, maxLen: 0x104u, pFormat: "%s/*.*", v2);
  for ( i = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: directory, a3: &pFolder);
        i != nullptr;
        i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: pFolder) )
  {
    if ( _V_stricmp(s1: i, s2: ".") != 0 && _V_stricmp(s1: i, s2: "..") != 0 )
    {
      if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)pFolder) )
      {
        V_snprintf(pDest: folderpath, maxLen: 0x104u, pFormat: "%s/%s", v2, i);
        this->InitRecursive(this, a2: folderpath);
      }
      else
      {
        FileExtension = V_GetFileExtension(path: i);
        if ( FileExtension == nullptr || _V_stricmp(s1: FileExtension, s2: "vfe") == 0 )
        {
          V_snprintf(pDest: fullFileName, maxLen: 0x104u, pFormat: "%s/%s", v2, i);
          v6 = _V_strlen(str: "expressions/");
          V_StripExtension(in: &fullFileName[v6], out: vfeName, outSize: 260);
          V_FixSlashes(pname: vfeName, separator: 92);
          CFlexSceneFileManager::FindSceneFile(this, instance: nullptr, filename: vfeName, allowBlockingIO: true);
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100481E0
// Name: public: virtual bool CFlexSceneFileManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFlexSceneFileManager::Init(CFlexSceneFileManager *this)
{
  CFlexSceneFileManager::FindSceneFile(this, instance: nullptr, filename: "phonemes", allowBlockingIO: true);
  CFlexSceneFileManager::FindSceneFile(this, instance: nullptr, filename: "phonemes_weak", allowBlockingIO: true);
  CFlexSceneFileManager::FindSceneFile(this, instance: nullptr, filename: "phonemes_strong", allowBlockingIO: true);
  this->InitRecursive(this, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10048220
// Name: private: void C_BaseFlex::AddViseme(float __near *,struct C_BaseFlex::Emphasized_Phoneme __near *,float,int,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::AddViseme(
        C_BaseFlex *this,
        float *pGlobalFlexWeight,
        C_BaseFlex::Emphasized_Phoneme *classes,
        float emphasis_intensity,
        int phoneme,
        float scale,
        bool newexpression)
{
  int v7; // esi
  float *p_amount; // ebx
  const flexsettinghdr_t *v10; // edi
  int v11; // eax
  char *v12; // eax
  int v13; // esi
  bool v14; // zf
  char *v15; // esi
  int v16; // eax
  int v17; // eax
  float v18; // xmm0_4
  C_BaseFlex::Emphasized_Phoneme *classesa; // [esp+20h] [ebp+Ch]
  int emphasis_intensitya; // [esp+24h] [ebp+10h]

  v7 = phoneme;
  if ( C_BaseFlex::SetupEmphasisBlend(this, classes, phoneme) == 0 )
  {
    C_BaseFlex::ComputeBlendedSetting(this, classes, emphasis_intensity);
    p_amount = &classes->amount;
    for ( emphasis_intensitya = 3; emphasis_intensitya != 0; --emphasis_intensitya )
    {
      if ( *((_BYTE *)p_amount - 4) != 0 && *p_amount != 0.0 )
      {
        v10 = *((const flexsettinghdr_t **)p_amount - 3);
        if ( v7 >= 0 && v7 < v10->numindexes )
        {
          v11 = *(int *)((char *)&v10->id + 4 * v7 + v10->indexindex);
          if ( v11 != -1 )
          {
            v12 = (char *)v10 + 24 * v11 + v10->flexsettingindex;
            if ( v12 != nullptr )
            {
              v13 = *((_DWORD *)v12 + 5);
              v14 = &v12[v13] == nullptr;
              v15 = &v12[v13];
              v16 = *((_DWORD *)v12 + 2);
              if ( !v14 && v16 > 0 )
              {
                classesa = (C_BaseFlex::Emphasized_Phoneme *)v16;
                do
                {
                  v17 = C_BaseFlex::FlexControllerLocalToGlobal(this, pSettinghdr: v10, key: *(_DWORD *)v15);
                  v18 = (float)((float)(*p_amount * scale) * *((float *)v15 + 1)) + pGlobalFlexWeight[v17];
                  v15 += 12;
                  v14 = classesa == (C_BaseFlex::Emphasized_Phoneme *)1;
                  classesa = (C_BaseFlex::Emphasized_Phoneme *)((char *)classesa - 1);
                  pGlobalFlexWeight[v17] = v18;
                }
                while ( !v14 );
              }
              v7 = phoneme;
            }
          }
        }
      }
      p_amount += 21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048300
// Name: private: void C_BaseFlex::AddVisemesForSentence(float __near *,struct C_BaseFlex::Emphasized_Phoneme __near *,float,class CSentence __near *,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::AddVisemesForSentence(
        C_BaseFlex *this,
        float *pGlobalFlexWeight,
        C_BaseFlex::Emphasized_Phoneme *classes,
        float emphasis_intensity,
        CChoreoScene *sentence,
        float t,
        float dt,
        bool juststarted)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v10; // edi
  const CBasePhonemeTag *RuntimePhoneme; // eax
  float v12; // xmm4_4
  const CBasePhonemeTag *v13; // esi
  float m_flStartTime; // xmm0_4
  int m_iAccumulatedBoneMask; // eax
  int m_nValue; // eax
  bool v17; // zf
  bool v18; // sf
  bool v19; // of
  int v20; // eax
  int v21; // eax
  int v22; // eax
  const CBasePhonemeTag *v23; // eax
  float m_flEndTime; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  CStudioHdr *v30; // [esp+1Ch] [ebp-8h]
  int pcount; // [esp+20h] [ebp-4h]

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  v30 = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v10 = 0;
    pcount = CDetailObjectSystem::GetDetailModelCount(this: sentence);
    if ( pcount > 0 )
    {
      do
      {
        RuntimePhoneme = CSentence::GetRuntimePhoneme(this: (CSentence *)sentence, i: v10);
        v12 = t;
        v13 = RuntimePhoneme;
        m_flStartTime = RuntimePhoneme->m_flStartTime;
        if ( t <= RuntimePhoneme->m_flStartTime || RuntimePhoneme->m_flEndTime <= t )
          goto LABEL_41;
        if ( (v30->m_pStudioHdr->flags & 0x1000) != 0 )
          goto LABEL_28;
        m_iAccumulatedBoneMask = this->m_iAccumulatedBoneMask;
        if ( (m_iAccumulatedBoneMask & 0x400) != 0 )
        {
          if ( g_CV_PhonemeSnap.m_pParent != nullptr )
          {
            m_nValue = g_CV_PhonemeSnap.m_pParent->m_Value.m_nValue;
            v19 = false;
            v17 = m_nValue == 0;
            v18 = m_nValue < 0;
          }
          else
          {
            v19 = false;
            v17 = true;
            v18 = false;
          }
        }
        else if ( (m_iAccumulatedBoneMask & 0x800) != 0 )
        {
          if ( g_CV_PhonemeSnap.m_pParent != nullptr )
          {
            v20 = g_CV_PhonemeSnap.m_pParent->m_Value.m_nValue;
            v19 = __OFSUB__(v20, 1);
            v17 = v20 == 1;
            v18 = v20 - 1 < 0;
          }
          else
          {
            v19 = false;
            v17 = false;
            v18 = true;
          }
        }
        else if ( (m_iAccumulatedBoneMask & 0x1000) != 0 )
        {
          if ( g_CV_PhonemeSnap.m_pParent != nullptr )
          {
            v21 = g_CV_PhonemeSnap.m_pParent->m_Value.m_nValue;
            v19 = __OFSUB__(v21, 2);
            v17 = v21 == 2;
            v18 = v21 - 2 < 0;
          }
          else
          {
            v19 = false;
            v17 = false;
            v18 = true;
          }
        }
        else
        {
          if ( (m_iAccumulatedBoneMask & 0x2000) == 0 )
            goto LABEL_41;
          v22 = g_CV_PhonemeSnap.m_pParent != nullptr ? g_CV_PhonemeSnap.m_pParent->m_Value.m_nValue : 0;
          v19 = __OFSUB__(v22, 3);
          v17 = v22 == 3;
          v18 = v22 - 3 < 0;
        }
        if ( (v18 ^ v19 | v17) == 0 )
        {
LABEL_28:
          if ( v10 < pcount - 1 )
          {
            v23 = CSentence::GetRuntimePhoneme(this: (CSentence *)sentence, i: v10 + 1);
            m_flEndTime = v13->m_flEndTime;
            v12 = t;
            if ( v23 != nullptr )
            {
              if ( v23->m_flStartTime == m_flEndTime )
                v25 = v23->m_flEndTime - t;
              else
                v25 = v23->m_flStartTime - t;
              m_flStartTime = v13->m_flStartTime;
              v26 = m_flEndTime - v13->m_flStartTime;
              if ( v26 <= v25 )
                v27 = v26;
              else
                v27 = v25;
              if ( dt > v27 )
                goto LABEL_41;
              if ( v26 > v25 )
              {
                dt = v25;
                goto LABEL_41;
              }
            }
            else
            {
              m_flStartTime = v13->m_flStartTime;
              v26 = m_flEndTime - v13->m_flStartTime;
              if ( dt > v26 )
                goto LABEL_41;
            }
            dt = v26;
          }
        }
LABEL_41:
        v28 = (float)(m_flStartTime - v12) * (float)(1.0 / dt);
        v29 = (float)(v13->m_flEndTime - v12) * (float)(1.0 / dt);
        if ( v28 < 1.0 && v29 > 0.0 )
        {
          if ( v29 > 1.0 )
            v29 = 1.0;
          if ( v28 < 0.0 )
            v28 = 0.0;
          C_BaseFlex::AddViseme(
            this,
            pGlobalFlexWeight,
            classes,
            emphasis_intensity,
            phoneme: v13->m_nPhonemeCode,
            scale: v29 - v28,
            newexpression: juststarted);
        }
        ++v10;
      }
      while ( v10 < pcount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048540
// Name: private: void C_BaseFlex::ProcessVisemes(struct C_BaseFlex::Emphasized_Phoneme __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::ProcessVisemes(
        C_BaseFlex *this,
        C_BaseFlex::Emphasized_Phoneme *classes,
        float *pGlobalFlexWeight)
{
  int v4; // eax
  int v5; // esi
  char *v6; // esi
  CSentence *v7; // edi
  float t; // [esp+28h] [ebp-14h]
  float dt; // [esp+2Ch] [ebp-10h]
  float sentence_length; // [esp+30h] [ebp-Ch]
  float sentence_lengtha; // [esp+30h] [ebp-Ch]
  int v12; // [esp+34h] [ebp-8h]
  int source; // [esp+38h] [ebp-4h]

  if ( this->m_mouth.m_nVoiceSources > 0 )
  {
    v4 = 0;
    source = 0;
    v5 = 0;
    v12 = 0;
    do
    {
      if ( v4 >= 0 && v4 < this->m_mouth.m_nVoiceSources )
      {
        v6 = (char *)this->m_mouth.m_VoiceSources + v5;
        if ( v6 != nullptr && v6[8] == 0 )
        {
          v7 = engine->GetSentence(this: engine, a2: *((_DWORD *)v6 + 1));
          if ( v7 != nullptr )
          {
            sentence_length = engine->GetSentenceLength(this: engine, a2: *((struct CAudioSource **)v6 + 1));
            if ( *(float *)v6 < (float)(sentence_length + 2.0) )
            {
              t = *(float *)v6 - g_CV_PhonemeDelay.m_pParent->m_Value.m_fValue;
              dt = g_CV_PhonemeFilter.m_pParent->m_Value.m_fValue;
              sentence_lengtha = CSentence::GetIntensity(this: v7, time: t, endtime: sentence_length);
              C_BaseFlex::AddVisemesForSentence(
                this,
                pGlobalFlexWeight,
                classes,
                emphasis_intensity: sentence_lengtha,
                sentence: (CChoreoScene *)v7,
                t,
                dt,
                juststarted: false);
            }
          }
          v4 = source;
        }
      }
      ++v4;
      v5 = v12 + 12;
      source = v4;
      v12 += 12;
    }
    while ( v4 < this->m_mouth.m_nVoiceSources );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048680
// Name: private: void C_BaseFlex::ProcessSceneEvents(bool,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::ProcessSceneEvents(C_BaseFlex *this, bool bFlexEvents, float *pGlobalFlexWeight)
{
  int v4; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  LocalFlexController_t j; // esi
  CSceneEventInfo *m_pMemory; // esi
  CChoreoEvent *m_pEvent; // eax
  CChoreoScene *m_pScene; // ecx
  CSceneEventInfo *v10; // esi
  float value; // [esp+0h] [ebp-14h]
  int i; // [esp+10h] [ebp-4h]

  v4 = 0;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    if ( bFlexEvents )
    {
      for ( j = DUMMY_NULL_FLEX_CONTROLLER; j < C_BaseAnimating::GetNumFlexControllers(this); ++j )
      {
        value = C_BaseFlex::GetFlexWeight(this, index: j) * 0.95;
        C_BaseFlex::SetFlexWeight(this, index: j, value);
      }
    }
    for ( i = 0; i < this->m_SceneEvents.m_Size; ++i )
    {
      m_pMemory = this->m_SceneEvents.m_Memory.m_pMemory;
      m_pEvent = m_pMemory[v4].m_pEvent;
      m_pScene = m_pMemory[v4].m_pScene;
      v10 = &m_pMemory[v4];
      if ( C_BaseFlex::ProcessSceneEvent(
             this,
             pGlobalFlexWeight,
             bFlexEvents,
             info: v10,
             scene: m_pScene,
             event: m_pEvent) != 0 )
        v10->m_bStarted = true;
      ++v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048750
// Name: public: virtual void C_BaseFlex::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::GetToolRecordingState(C_BaseFlex *this, KeyValues *msg)
{
  int v3; // ebx
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v5; // ecx
  const studiohdr_t *v6; // ecx
  int v7; // edx
  int v8; // ebx
  int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  int v12; // eax
  float v13; // ecx
  int m_blinktoggle; // eax
  unsigned int m_Index; // ecx
  ConVar *m_pParent; // edx
  __m128 m_blinktime_low; // xmm0
  __m128d v18; // xmm0
  __m128i v19; // xmm0
  double v20; // xmm0_8
  float v21; // xmm0_4
  int m_iBlink; // eax
  float v23; // xmm1_4
  LocalFlexController_t m_iEyeUpdown; // ecx
  float z; // eax
  LocalFlexController_t m_iEyeRightleft; // edi
  int v27; // ecx
  int v28; // ebx
  float *v29; // ecx
  int v30; // edi
  int v31; // eax
  float B; // xmm1_4
  float val; // xmm2_4
  float A; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  const studiohdr_t *v37; // eax
  int v38; // edx
  int v39; // edi
  int v40; // ecx
  float v41; // xmm0_4
  char *v42; // ecx
  Vector viewtarget; // [esp+34h] [ebp-14h] BYREF
  float updown; // [esp+40h] [ebp-8h]
  float rightleft; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  if ( ToolsEnabled() )
  {
    v3 = 0;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "C_BaseFlex::GetToolRecordingState",
      a3: 0,
      a4: "Tools",
      a5: false,
      a6: 4);
    C_BaseAnimating::GetToolRecordingState(this, msg);
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr
      && m_pStudioHdr->m_pStudioHdr != nullptr
      && m_pStudioHdr->m_pStudioHdr->numflexcontrollers != 0 )
    {
      C_BaseFlex::ProcessSceneEvents(this, bFlexEvents: true, pGlobalFlexWeight: nullptr);
      v5 = m_pStudioHdr->m_pStudioHdr;
      if ( *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->checksum + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex) == -1 )
      {
        rightleft = 0.0;
        if ( v5->numflexcontrollers > 0 )
        {
          do
          {
            *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->checksum + v3
                                                                   + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex) = C_BaseFlex::AddGlobalFlexController(szName: (char *)v5 + v3 + v5->flexcontrollerindex + *(int *)((char *)&v5->version + v3 + v5->flexcontrollerindex));
            v5 = m_pStudioHdr->m_pStudioHdr;
            v3 += 20;
            ++LODWORD(rightleft);
          }
          while ( SLODWORD(rightleft) < v5->numflexcontrollers );
        }
      }
      memset(dst: (int)C_BaseFlex::s_pGlobalFlexWeight, value: nullptr, count: 4 * C_BaseFlex::g_numflexcontrollers);
      v6 = m_pStudioHdr->m_pStudioHdr;
      v7 = 0;
      if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
      {
        v8 = 0;
        LODWORD(rightleft) = this->m_flexWeight;
        do
        {
          v9 = v8 + v6->flexcontrollerindex;
          v10 = *(float *)&v6->name[v9];
          v11 = *(float *)&v6->name[v9 + 4];
          v12 = *(int *)((char *)&v6->checksum + v9);
          LODWORD(v13) = LODWORD(rightleft) + 4;
          C_BaseFlex::s_pGlobalFlexWeight[v12] = (float)((float)(v11 - v10) * *(float *)LODWORD(rightleft)) + v10;
          rightleft = v13;
          v6 = m_pStudioHdr->m_pStudioHdr;
          ++v7;
          v8 += 20;
        }
        while ( v7 < m_pStudioHdr->m_pStudioHdr->numflexcontrollers );
      }
      C_BaseFlex::ProcessSceneEvents(this, bFlexEvents: false, pGlobalFlexWeight: C_BaseFlex::s_pGlobalFlexWeight);
      m_blinktoggle = this->m_blinktoggle;
      if ( m_blinktoggle != this->m_prevblinktoggle )
      {
        this->m_prevblinktoggle = m_blinktoggle;
        this->m_blinktime = g_CV_BlinkDuration.m_pParent->m_Value.m_fValue + *(float *)(gpGlobals.m_Index + 12);
      }
      if ( this->m_iBlink == -1 )
        this->m_iBlink = C_BaseFlex::AddGlobalFlexController(szName: "blink");
      m_Index = gpGlobals.m_Index;
      m_pParent = g_CV_BlinkDuration.m_pParent;
      C_BaseFlex::s_pGlobalFlexWeight[this->m_iBlink] = 0.0;
      m_blinktime_low = (__m128)LODWORD(this->m_blinktime);
      m_blinktime_low.m128_f32[0] = m_blinktime_low.m128_f32[0] - *(float *)(m_Index + 12);
      v18 = _mm_cvtps_pd(m_blinktime_low);
      v18.m128d_f64[0] = v18.m128d_f64[0] * 3.141592653589793 * 0.5 * (1.0 / m_pParent->m_Value.m_fValue);
      v19 = (__m128i)_mm_cvtpd_ps(v18);
      if ( *(float *)v19.m128i_i32 > 0.0 )
      {
        *(double *)v19.m128i_i64 = *(float *)v19.m128i_i32;
        __libm_sse2_cos(X: v19);
        v21 = v20;
        if ( v21 > 0.0 )
        {
          C_BaseFlex::s_pGlobalFlexWeight[this->m_iBlink] = fsqrt(v21) * 2.0;
          m_iBlink = this->m_iBlink;
          v23 = C_BaseFlex::s_pGlobalFlexWeight[m_iBlink];
          if ( v23 > 1.0 )
            C_BaseFlex::s_pGlobalFlexWeight[m_iBlink] = 2.0 - v23;
        }
      }
      C_BaseFlex::ProcessVisemes(
        this,
        classes: this->m_PhonemeClasses,
        pGlobalFlexWeight: C_BaseFlex::s_pGlobalFlexWeight);
      C_BaseFlex::SetViewTarget(
        this,
        a2: COERCE_FLOAT(&savedregs),
        result: &viewtarget,
        pStudioHdr: m_pStudioHdr,
        pGlobalFlexWeight: C_BaseFlex::s_pGlobalFlexWeight);
      m_iEyeUpdown = this->m_iEyeUpdown;
      z = this->m_viewtarget.z;
      *(_QWORD *)&viewtarget.x = *(_QWORD *)&this->m_viewtarget.x;
      viewtarget.z = z;
      if ( m_iEyeUpdown != DUMMY_INVALID_FLEX_CONTROLLER )
      {
        m_iEyeRightleft = this->m_iEyeRightleft;
        if ( m_iEyeRightleft != DUMMY_INVALID_FLEX_CONTROLLER )
        {
          v27 = m_pStudioHdr->m_pStudioHdr->flexcontrollerindex + 20 * m_iEyeUpdown;
          v28 = *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->checksum + v27);
          v29 = (float *)((char *)&m_pStudioHdr->m_pStudioHdr->id + v27);
          v30 = (int)m_pStudioHdr->m_pStudioHdr + 20 * m_iEyeRightleft + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex;
          if ( v28 != -1 )
          {
            v31 = *(_DWORD *)(v30 + 8);
            if ( v31 != -1 )
            {
              B = v29[4];
              val = C_BaseFlex::s_pGlobalFlexWeight[v28];
              rightleft = C_BaseFlex::s_pGlobalFlexWeight[v31];
              A = v29[3];
              updown = val;
              if ( A != B )
                updown = RemapVal(val, A, B, C: 0.0, D: 1.0);
              v35 = *(float *)(v30 + 12);
              v36 = *(float *)(v30 + 16);
              if ( v35 != v36 )
                rightleft = RemapVal(val: rightleft, A: v35, B: v36, C: 0.0, D: 1.0);
              C_BaseFlex::s_pGlobalFlexWeight[v28] = updown;
              C_BaseFlex::s_pGlobalFlexWeight[*(_DWORD *)(v30 + 8)] = rightleft;
            }
          }
        }
      }
      v37 = m_pStudioHdr->m_pStudioHdr;
      v38 = 0;
      if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
      {
        v39 = 0;
        do
        {
          v40 = v39 + v37->flexcontrollerindex;
          v41 = *(float *)&v37->name[v40 + 4];
          v42 = (char *)v37 + v40;
          if ( v41 != *((float *)v42 + 3) )
            C_BaseFlex::s_pGlobalFlexWeight[*((_DWORD *)v42 + 2)] = (float)(C_BaseFlex::s_pGlobalFlexWeight[*((_DWORD *)v42 + 2)]
                                                                          - *((float *)v42 + 3))
                                                                  / (float)(v41 - *((float *)v42 + 3));
          v37 = m_pStudioHdr->m_pStudioHdr;
          ++v38;
          v39 += 20;
        }
        while ( v38 < m_pStudioHdr->m_pStudioHdr->numflexcontrollers );
      }
      if ( (_S6_8 & 1) == 0 )
        _S6_8 |= 1u;
      state_1.m_vecViewTarget = viewtarget;
      state_1.m_nFlexCount = C_BaseFlex::g_numflexcontrollers;
      state_1.m_pDestWeight = C_BaseFlex::s_pGlobalFlexWeight;
      KeyValues::SetPtr(this: msg, keyName: "baseflex", value: &state_1);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048BF0
// Name: public: virtual void C_BaseFlex::SetupWeights(struct matrix3x4_t const __near *,int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseFlex::SetupWeights(
        C_BaseFlex *this,
        const matrix3x4_t *pBoneToWorld,
        LocalFlexController_t nFlexWeightCount,
        float *pFlexWeights,
        float *pFlexDelayedWeights)
{
  CStudioHdr *v6; // edi
  float *m_flFlexDelayedWeight; // ecx
  int numflexdesc; // eax
  unsigned int v9; // edi
  IVModelRender_vtbl *v10; // edi
  CStudioHdr *ModelPtr; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v13; // ebx
  const studiohdr_t *v14; // ecx
  int v15; // edx
  const char **p_m_pDebugName; // ebx
  const char *m_pDebugName; // eax
  float m_fValue; // xmm1_4
  float v19; // xmm0_4
  __m128 m_pElements; // xmm1
  __m128d v21; // xmm1
  __m128 v22; // xmm0
  double v23; // xmm0_8
  float v24; // xmm0_4
  float v25; // xmm0_4
  int m_prevblinktoggle; // eax
  float v27; // xmm1_4
  float v28; // xmm0_4
  double v29; // xmm0_8
  __m128d v30; // xmm0
  double v31; // xmm0_8
  int v32; // edi
  LocalFlexController_t v33; // eax
  int v34; // ecx
  int v35; // ebx
  unsigned int v36; // edi
  float *v37; // eax
  float v38; // xmm1_4
  char *v39; // ecx
  int m_iMouthAttachment; // ecx
  float v41; // xmm1_4
  float v42; // xmm3_4
  float *v43; // ecx
  unsigned int v44; // edi
  float z; // [esp-Ch] [ebp-30h]
  int v46; // [esp-4h] [ebp-28h]
  Vector result; // [esp+Ch] [ebp-18h] BYREF
  int v48; // [esp+18h] [ebp-Ch]
  int v49; // [esp+1Ch] [ebp-8h]
  int nFlexDescCount; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  LocalFlexController_t i; // [esp+30h] [ebp+Ch]
  LocalFlexController_t ia; // [esp+30h] [ebp+Ch]
  float ib; // [esp+30h] [ebp+Ch]
  LocalFlexController_t ic; // [esp+30h] [ebp+Ch]

  if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: (C_BaseFlex *)((char *)this - 4));
  v6 = *(CStudioHdr **)&this->m_nOldMuzzleFlashParity;
  if ( v6 != nullptr && v6->m_pStudioHdr != nullptr )
  {
    if ( v6->m_pStudioHdr->numflexcontrollers != 0 )
    {
      m_flFlexDelayedWeight = this->m_flFlexDelayedWeight;
      numflexdesc = v6->m_pStudioHdr->numflexdesc;
      nFlexDescCount = numflexdesc;
      if ( m_flFlexDelayedWeight == (float *)g_iFlexCounter )
      {
        if ( nFlexWeightCount < numflexdesc )
          numflexdesc = nFlexWeightCount;
        v9 = 4 * numflexdesc;
        memcpy(
          dst: (unsigned __int8 *)pFlexWeights,
          src: (unsigned __int8 *)LODWORD(this->m_CachedViewTarget.z),
          count: 4 * numflexdesc);
        if ( pFlexDelayedWeights != nullptr )
          memcpy(
            dst: (unsigned __int8 *)pFlexDelayedWeights,
            src: (unsigned __int8 *)this->m_CachedFlexWeights.m_pElements,
            count: v9);
        v10 = modelrender->__vftable;
        v46 = ((int (__thiscall *)(C_BaseFlex *, int *))this->GetAbsOrigin)(
                a1: this,
                a2: &this->m_iMostRecentFlexCounter);
        ModelPtr = C_BaseAnimating::GetModelPtr(this: (C_BaseFlex *)((char *)this - 4));
        ((void (__thiscall *)(IVModelRender *, CStudioHdr *, int))v10->SetViewTarget)(
          a1: modelrender,
          a2: ModelPtr,
          a3: v46);
      }
      else
      {
        C_BaseFlex::ProcessSceneEvents(
          this: (C_BaseFlex *)((char *)this - 4),
          bFlexEvents: true,
          pGlobalFlexWeight: nullptr);
        m_pStudioHdr = v6->m_pStudioHdr;
        if ( *(int *)((char *)&v6->m_pStudioHdr->checksum + v6->m_pStudioHdr->flexcontrollerindex) == -1 )
        {
          v13 = 0;
          i = DUMMY_NULL_FLEX_CONTROLLER;
          if ( m_pStudioHdr->numflexcontrollers > 0 )
          {
            do
            {
              *(int *)((char *)&v6->m_pStudioHdr->checksum + v6->m_pStudioHdr->flexcontrollerindex + v13) = C_BaseFlex::AddGlobalFlexController(szName: (char *)m_pStudioHdr + m_pStudioHdr->flexcontrollerindex + v13 + *(int *)((char *)&m_pStudioHdr->version + m_pStudioHdr->flexcontrollerindex + v13));
              m_pStudioHdr = v6->m_pStudioHdr;
              v13 += 20;
              ++i;
            }
            while ( i < v6->m_pStudioHdr->numflexcontrollers );
          }
        }
        memset(dst: (int)C_BaseFlex::s_pGlobalFlexWeight, value: nullptr, count: 4 * C_BaseFlex::g_numflexcontrollers);
        v14 = v6->m_pStudioHdr;
        v15 = 0;
        if ( v6->m_pStudioHdr->numflexcontrollers > 0 )
        {
          ia = DUMMY_NULL_FLEX_CONTROLLER;
          p_m_pDebugName = &this->m_iv_viewtarget.m_pDebugName;
          do
          {
            C_BaseFlex::s_pGlobalFlexWeight[*(int *)((char *)&v14->checksum + v14->flexcontrollerindex + ia)] = (float)((float)(*(float *)&v14->name[v14->flexcontrollerindex + 4 + ia] - *(float *)&v14->name[v14->flexcontrollerindex + ia]) * *(float *)p_m_pDebugName) + *(float *)&v14->name[v14->flexcontrollerindex + ia];
            ia += 20;
            v14 = v6->m_pStudioHdr;
            ++v15;
            ++p_m_pDebugName;
          }
          while ( v15 < v6->m_pStudioHdr->numflexcontrollers );
        }
        C_BaseFlex::ProcessSceneEvents(
          this: (C_BaseFlex *)((char *)this - 4),
          bFlexEvents: false,
          pGlobalFlexWeight: C_BaseFlex::s_pGlobalFlexWeight);
        m_pDebugName = this->m_iv_flexWeight.m_pDebugName;
        if ( m_pDebugName != (const char *)LODWORD(this->m_blinktime) )
        {
          LODWORD(this->m_blinktime) = m_pDebugName;
          *(float *)&this->m_LocalToGlobal.m_pElements = g_CV_BlinkDuration.m_pParent->m_Value.m_fValue
                                                       + *(float *)(gpGlobals.m_Index + 12);
        }
        m_fValue = g_CV_BlinkDuration.m_pParent->m_Value.m_fValue;
        if ( m_fValue <= 0.0 )
          v19 = 0.0;
        else
          v19 = 1.0 / m_fValue;
        m_pElements = (__m128)(unsigned int)this->m_LocalToGlobal.m_pElements;
        m_pElements.m128_f32[0] = m_pElements.m128_f32[0] - *(float *)(gpGlobals.m_Index + 12);
        v21 = _mm_cvtps_pd(m_pElements);
        v21.m128d_f64[0] = v21.m128d_f64[0] * 3.141592653589793 * 0.5 * v19;
        v22 = _mm_cvtpd_ps(v21);
        if ( v22.m128_f32[0] > 0.0 )
        {
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v22));
          v24 = v23;
          if ( v24 > 0.0 && v24 < 1.0 )
          {
            v25 = fsqrt(v24) * 2.0;
            if ( v25 > 1.0 )
              v25 = 2.0 - v25;
            if ( v25 >= 0.0 )
            {
              if ( v25 > 1.0 )
                v25 = 1.0;
            }
            else
            {
              v25 = 0.0;
            }
            m_prevblinktoggle = this->m_prevblinktoggle;
            v27 = C_BaseFlex::s_pGlobalFlexWeight[m_prevblinktoggle] + v25;
            if ( v27 >= 0.0 )
            {
              if ( v27 > 1.0 )
                v27 = 1.0;
            }
            else
            {
              v27 = 0.0;
            }
            C_BaseFlex::s_pGlobalFlexWeight[m_prevblinktoggle] = v27;
          }
        }
        C_BaseFlex::ProcessVisemes(
          this: (C_BaseFlex *)((char *)this - 4),
          classes: (C_BaseFlex::Emphasized_Phoneme *)&this->m_CachedDelayedFlexWeights.m_pElements,
          pGlobalFlexWeight: C_BaseFlex::s_pGlobalFlexWeight);
        if ( g_CV_FlexRules.m_pParent != nullptr && g_CV_FlexRules.m_pParent->m_Value.m_nValue != 0 )
          CStudioHdr::RunFlexRules(this: v6, src: C_BaseFlex::s_pGlobalFlexWeight, dest: pFlexWeights);
        *(Vector *)&this->m_iMostRecentFlexCounter = *C_BaseFlex::SetViewTarget(
                                                        this: (C_BaseFlex *)((char *)this - 4),
                                                        a2: COERCE_FLOAT(&savedregs),
                                                        &result,
                                                        pStudioHdr: v6,
                                                        pGlobalFlexWeight: C_BaseFlex::s_pGlobalFlexWeight);
        v28 = 1.0;
        ib = *(float *)(gpGlobals.m_Index + 16);
        if ( ib != 0.0 )
        {
          __libm_sse2_log(a1: (__m128d)0x3FE99999A0000000uLL);
          *(float *)&v29 = v29;
          v30.m128d_f64[0] = (float)((float)(*(float *)&v29 * 30.30303) * ib);
          __libm_sse2_exp(a1: v30);
          v28 = v31;
        }
        v32 = nFlexDescCount;
        v33 = DUMMY_NULL_FLEX_CONTROLLER;
        if ( nFlexDescCount >= 4 )
        {
          v48 = 4 - (_DWORD)pFlexWeights;
          v34 = -8 - (_DWORD)pFlexWeights;
          v35 = 8;
          v36 = ((unsigned int)(nFlexDescCount - 4) >> 2) + 1;
          v37 = pFlexWeights + 2;
          v38 = 1.0 - v28;
          v49 = -8 - (_DWORD)pFlexWeights;
          ic = 4 * v36;
          while ( 1 )
          {
            v39 = (char *)v37 + v34;
            *(float *)&v39[this->m_iMouthAttachment] = (float)(*(v37 - 2) * v38)
                                                     + (float)(*(float *)&v39[this->m_iMouthAttachment] * v28);
            *(float *)&v39[this->m_iMouthAttachment + 4] = (float)(*(v37 - 1) * v38)
                                                         + (float)(*(float *)&v39[this->m_iMouthAttachment + 4] * v28);
            *(float *)(this->m_iMouthAttachment + v35) = (float)(*(float *)(this->m_iMouthAttachment + v35) * v28)
                                                       + (float)(v38 * *v37);
            *(float *)((char *)v37 + v48 + this->m_iMouthAttachment) = (float)(v37[1] * v38)
                                                                     + (float)(*(float *)((char *)v37
                                                                                        + v48
                                                                                        + this->m_iMouthAttachment)
                                                                             * v28);
            v35 += 16;
            v37 += 4;
            if ( --v36 == 0 )
              break;
            v34 = v49;
          }
          v33 = ic;
          v32 = nFlexDescCount;
        }
        for ( ; v33 < v32; *v43 = (float)(v41 * (float)(1.0 - v28)) + (float)(v42 * v28) )
        {
          m_iMouthAttachment = this->m_iMouthAttachment;
          v41 = pFlexWeights[v33];
          v42 = *(float *)(m_iMouthAttachment + 4 * v33);
          v43 = (float *)(m_iMouthAttachment + 4 * v33++);
        }
        if ( pFlexDelayedWeights != nullptr )
          memcpy(
            dst: (unsigned __int8 *)pFlexDelayedWeights,
            src: (unsigned __int8 *)this->m_iMouthAttachment,
            count: 4 * v32);
        v44 = 4 * v32;
        z = this->m_CachedViewTarget.z;
        this->m_flFlexDelayedWeight = (float *)g_iFlexCounter;
        memcpy(dst: (unsigned __int8 *)LODWORD(z), src: (unsigned __int8 *)pFlexWeights, count: v44);
        memcpy(
          dst: (unsigned __int8 *)this->m_CachedFlexWeights.m_pElements,
          src: (unsigned __int8 *)this->m_iMouthAttachment,
          count: v44);
      }
    }
    else
    {
      memset(dst: (int)pFlexWeights, value: nullptr, count: 4 * nFlexWeightCount);
      if ( pFlexDelayedWeights != nullptr )
        memset(dst: (int)pFlexDelayedWeights, value: nullptr, count: 4 * nFlexWeightCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DAAB0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411030
// Name: DT_BaseFlex::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseFlex::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseFlex::g_RecvTable);
  return atexit(func: DT_BaseFlex::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411050
// Name: DT_BaseFlex::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseFlex::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseFlex::ignored>();
  DT_BaseFlex::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411060
// Name: C_BaseFlex_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseFlex_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseFlex::m_PredMap.dataNumFields = 1;
  C_BaseFlex::m_PredMap.dataDesc = (typedescription_t *)&unk_105FF0F0;
}

//------------------------------------------------------------------------------
// Address: 0x104110F0
// Name: flexsettinghdr_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *flexsettinghdr_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<flexsettinghdr_t>();
  flexsettinghdr_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411100
// Name: flexsetting_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *flexsetting_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<flexsetting_t>();
  flexsetting_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411110
// Name: flexweight_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *flexweight_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<flexweight_t>();
  flexweight_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042FE90
// Name: DT_BaseFlex::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseFlex::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseFlex::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10411080
// Name: _dynamic_initializer_for__g_FlexSceneFileManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FlexSceneFileManager__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_FlexSceneFileManager, name: "CFlexSceneFileManager");
  g_FlexSceneFileManager.__vftable = (CFlexSceneFileManager_vtbl *)&CFlexSceneFileManager::`vftable';
  g_FlexSceneFileManager.m_FileList.m_Memory.m_pMemory = nullptr;
  g_FlexSceneFileManager.m_FileList.m_Memory.m_nAllocationCount = 0;
  g_FlexSceneFileManager.m_FileList.m_Memory.m_nGrowSize = 0;
  g_FlexSceneFileManager.m_FileList.m_Size = 0;
  g_FlexSceneFileManager.m_FileList.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_FlexSceneFileManager__);
}

//------------------------------------------------------------------------------
// Address: 0x104110C0
// Name: _dynamic_initializer_for__g_CV_PhonemeSnap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_PhonemeSnap__()
{
  ConVar::ConVar(
    this: &g_CV_PhonemeSnap,
    pName: "phonemesnap",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Lod at level at which visemes stops always considering two phonemes, regardless of duration.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_PhonemeSnap__);
}

//------------------------------------------------------------------------------
// Address: 0x10411120
// Name: _dynamic_initializer_for__g_CGameInstructorSymbolSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CGameInstructorSymbolSymbolTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_CGameInstructorSymbolSymbolTable,
    growSize: 0,
    initSize: 16,
    caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_CGameInstructorSymbolSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411140
// Name: _dynamic_initializer_for__g_pLessonVariableInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LessonVariableInfo *dynamic_initializer_for__g_pLessonVariableInfo__()
{
  LessonVariableInfo *result; // eax
  int i; // ecx

  result = g_pLessonVariableInfo;
  for ( i = 46; i >= 0; --i )
  {
    result->iOffset = 0;
    result->varType = FIELD_VOID;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411160
// Name: _dynamic_initializer_for__g_NameToTypeMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NameToTypeMap__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_NameToTypeMap__);
}

//------------------------------------------------------------------------------
// Address: 0x10411170
// Name: _dynamic_initializer_for__g_TypeToParamTypeMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TypeToParamTypeMap__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_TypeToParamTypeMap__);
}

//------------------------------------------------------------------------------
// Address: 0x1042FEA0
// Name: _dynamic_atexit_destructor_for__g_CV_PhonemeSnap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_PhonemeSnap__()
{
  ConVar::~ConVar(this: &g_CV_PhonemeSnap);
}

//------------------------------------------------------------------------------
// Address: 0x1042FEB0
// Name: _dynamic_atexit_destructor_for__g_FlexSceneFileManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FlexSceneFileManager__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_FlexSceneFileManager.m_FileList);
  IGameSystem::~IGameSystem(this: &g_FlexSceneFileManager);
}

//------------------------------------------------------------------------------
// Address: 0x1042FED0
// Name: _DataMapInit_flexsettinghdr_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_flexsettinghdr_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x1042FEE0
// Name: _DataMapInit_flexsetting_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_flexsetting_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_4);
}

//------------------------------------------------------------------------------
// Address: 0x1042FEF0
// Name: _DataMapInit_flexweight_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_flexweight_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_5);
}

//------------------------------------------------------------------------------
// Address: 0x1042FF00
// Name: _dynamic_atexit_destructor_for__g_CGameInstructorSymbolSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CGameInstructorSymbolSymbolTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_CGameInstructorSymbolSymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042FF10
// Name: _DataMapInit_CScriptedIconLesson__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CScriptedIconLesson__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_6);
}

//------------------------------------------------------------------------------
// Address: 0x1042FF20
// Name: _dynamic_atexit_destructor_for__g_NameToTypeMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NameToTypeMap__()
{
  CUtlDict<enum LessonVariable,int>::RemoveAll(this: &g_NameToTypeMap);
  CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>(this: &g_NameToTypeMap.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1042FF40
// Name: _dynamic_atexit_destructor_for__g_TypeToParamTypeMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TypeToParamTypeMap__()
{
  CUtlDict<enum _fieldtypes,int>::RemoveAll(this: &g_TypeToParamTypeMap);
  CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>(this: &g_TypeToParamTypeMap.m_Elements.m_Tree);
}
