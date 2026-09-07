// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/studio_utils.cpp
// Functions: 53
// ============================================================

#include "utils\hlmv\studio_utils.h"

//------------------------------------------------------------------------------
// Address: 0x0041BC10
// Name: public: static void StudioModel::Init(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl StudioModel::Init()
{
  int v0; // eax

  v0 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender);
  StudioModel::m_AmbientLightColors = (Vector *)operator new(nSize: 12 * v0);
  StudioModel::UpdateStudioRenderConfig(
    bWireframe: g_viewerSettings.renderMode == 0,
    bZBufferWireframe: false,
    bNormals: g_viewerSettings.showNormals,
    bTangentFrame: g_viewerSettings.showTangentFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0041BC70
// Name: public: void StudioModel::SetCurrentModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetCurrentModel(StudioModel *this)
{
  g_pActiveModel = this;
}

//------------------------------------------------------------------------------
// Address: 0x0041BC80
// Name: public: static void __near * StudioModel::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl StudioModel::operator new(unsigned int stAllocateBlock)
{
  void *v1; // eax
  unsigned __int8 *v3; // esi

  v1 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: stAllocateBlock + 19);
  if ( v1 != nullptr )
  {
    v3 = (unsigned __int8 *)(((unsigned int)v1 + 19) & 0xFFFFFFF0);
    *((_DWORD *)v3 - 1) = v1;
    memset(dst: v3, value: 0, count: stAllocateBlock);
    return v3;
  }
  else
  {
    memset(dst: nullptr, value: 0, count: stAllocateBlock);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BCD0
// Name: public: static void StudioModel::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StudioModel::operator delete(unsigned int pMem)
{
  if ( pMem != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((pMem & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0041BD00
// Name: public: int StudioModel::GetSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetSequence(StudioModel *this)
{
  return this->m_sequence;
}

//------------------------------------------------------------------------------
// Address: 0x0041BD10
// Name: public: int StudioModel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetSequence(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  int NumSeq_Internal; // eax
  int m_sequence; // edx

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( iSequence < 0 )
    return 0;
  if ( m_pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
  else
    NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( iSequence > NumSeq_Internal )
    return this->m_sequence;
  m_sequence = this->m_sequence;
  this->m_sequence = iSequence;
  this->m_prevsequence = m_sequence;
  this->m_cycle = 0.0;
  this->m_sequencetime = 0.0;
  return iSequence;
}

//------------------------------------------------------------------------------
// Address: 0x0041BDC0
// Name: public: void StudioModel::ClearAnimationLayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::ClearAnimationLayers(StudioModel *this)
{
  this->m_iActiveLayers = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041BDD0
// Name: public: int StudioModel::GetNewAnimationLayer(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetNewAnimationLayer(StudioModel *this, int iPriority)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  int result; // eax
  int m_iActiveLayers; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  m_iActiveLayers = this->m_iActiveLayers;
  if ( m_iActiveLayers >= 8 )
    return 7;
  this->m_Layer[m_iActiveLayers].m_priority = iPriority;
  result = this->m_iActiveLayers;
  this->m_iActiveLayers = result + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BE50
// Name: public: int StudioModel::SetOverlaySequence(int,int,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetOverlaySequence(StudioModel *this, unsigned int iLayer, int iSequence, float flWeight)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  int NumSeq_Internal; // eax
  char *v9; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( iSequence < 0 )
    return 0;
  if ( iLayer > 7 )
    return 0;
  if ( m_pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
  else
    NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( iSequence > NumSeq_Internal )
    return this->m_Layer[iLayer].m_sequence;
  v9 = (char *)this + 20 * iLayer;
  this->m_Layer[iLayer].m_weight = flWeight;
  *((_DWORD *)v9 + 39) = iSequence;
  *((_DWORD *)v9 + 41) = 1065353216;
  return iSequence;
}

//------------------------------------------------------------------------------
// Address: 0x0041BF20
// Name: public: float StudioModel::SetOverlayRate(int,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::SetOverlayRate(
        StudioModel *this,
        unsigned int iLayer,
        float flCycle,
        float flPlaybackRate)
{
  double result; // st7
  float *v5; // eax

  result = flCycle;
  if ( iLayer <= 7 )
  {
    v5 = (float *)((char *)this + 20 * iLayer);
    v5[38] = flCycle;
    v5[41] = flPlaybackRate;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BF60
// Name: public: int StudioModel::GetOverlaySequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetOverlaySequence(StudioModel *this, unsigned int iLayer)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return -1;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( iLayer > 7 )
    return 0;
  return this->m_Layer[iLayer].m_sequence;
}

//------------------------------------------------------------------------------
// Address: 0x0041BFD0
// Name: public: float StudioModel::GetOverlaySequenceWeight(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetOverlaySequenceWeight(StudioModel *this, unsigned int iLayer)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1.0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return -1.0;
  }
  if ( m_pStudioHdr == nullptr )
    return -1.0;
  if ( iLayer > 7 )
    return 0.0;
  return this->m_Layer[iLayer].m_weight;
}

//------------------------------------------------------------------------------
// Address: 0x0041C040
// Name: public: int StudioModel::LookupSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupSequence(StudioModel *this, const char *szSequence)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int i; // esi
  int v8; // eax
  const studiohdr_t *v9; // ecx
  int v10; // eax
  mstudioseqdesc_t *v11; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return -1;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  for ( i = 0; ; ++i )
  {
    v8 = m_pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
       : m_pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( i >= v8 )
      break;
    if ( m_pStudioHdr->m_pVModel != nullptr )
    {
      v11 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i);
    }
    else
    {
      v9 = m_pStudioHdr->m_pStudioHdr;
      v10 = i;
      if ( i < 0 || i >= v9->numlocalseq )
        v10 = 0;
      v11 = (mstudioseqdesc_t *)((char *)v9 + 212 * v10 + v9->localseqindex);
    }
    if ( _V_stricmp(s1: szSequence, s2: (const char *)v11 + v11->szlabelindex) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C110
// Name: public: int StudioModel::LookupActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupActivity(StudioModel *this, const char *szActivity)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int i; // esi
  int v8; // eax
  const studiohdr_t *v9; // ecx
  int v10; // eax
  mstudioseqdesc_t *v11; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return -1;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  for ( i = 0; ; ++i )
  {
    v8 = m_pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
       : m_pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( i >= v8 )
      break;
    if ( m_pStudioHdr->m_pVModel != nullptr )
    {
      v11 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i);
    }
    else
    {
      v9 = m_pStudioHdr->m_pStudioHdr;
      v10 = i;
      if ( i < 0 || i >= v9->numlocalseq )
        v10 = 0;
      v11 = (mstudioseqdesc_t *)((char *)v9 + 212 * v10 + v9->localseqindex);
    }
    if ( _V_stricmp(s1: szActivity, s2: (const char *)v11 + v11->szactivitynameindex) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C1E0
// Name: public: enum LocalFlexController_t StudioModel::LookupFlexController(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupFlexController(StudioModel *this, char *szName)
{
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  const studiohdr_t *v7; // ecx
  int v8; // edi
  int i; // esi

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return 0;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v7 = m_pStudioHdr->m_pStudioHdr;
  v8 = 0;
  if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers <= 0 )
    return -1;
  for ( i = 0;
        _V_stricmp(
          s1: szName,
          s2: (const char *)v7 + i + v7->flexcontrollerindex + *(int *)((char *)&v7->version + i + v7->flexcontrollerindex)) != 0;
        i += 20 )
  {
    v7 = m_pStudioHdr->m_pStudioHdr;
    if ( ++v8 >= m_pStudioHdr->m_pStudioHdr->numflexcontrollers )
      return -1;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0041C290
// Name: public: float StudioModel::GetFlexController(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetFlexController(StudioModel *this, int iFlex)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  const studiohdr_t *v5; // edx
  float v6; // xmm2_4
  __int32 v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float flValue; // [esp+Ch] [ebp+8h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0.0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0.0;
  if ( iFlex < 0 )
    return 0.0;
  v5 = m_pStudioHdr->m_pStudioHdr;
  if ( iFlex >= m_pStudioHdr->m_pStudioHdr->numflexcontrollers )
    return 0.0;
  v6 = this->m_flexweight[iFlex];
  v7 = v5->flexcontrollerindex + 20 * iFlex;
  v8 = *(float *)&v5->name[v7 + 4];
  v9 = *(float *)&v5->name[v7];
  flValue = v6;
  if ( v9 != v8 )
    return (float)((float)((float)(v8 - v9) * v6) + v9);
  return flValue;
}

//------------------------------------------------------------------------------
// Address: 0x0041C340
// Name: public: void StudioModel::ExtractBbox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::ExtractBbox(StudioModel *this@<ecx>, int a2@<esi>, Vector *mins, Vector *maxs)
{
  int v5; // eax
  studiohdr_t *v6; // ecx
  int m_sequence; // eax
  mstudioseqdesc_t *v8; // eax
  int v10; // [esp-2Ch] [ebp-38h]
  int v11; // [esp-28h] [ebp-34h]
  int v12; // [esp-24h] [ebp-30h]
  int v13; // [esp-20h] [ebp-2Ch]
  int v14; // [esp-1Ch] [ebp-28h]
  int v15; // [esp-18h] [ebp-24h]
  int v16; // [esp-14h] [ebp-20h]
  int v17; // [esp-10h] [ebp-1Ch]
  int v18; // [esp-Ch] [ebp-18h]
  int v19; // [esp-8h] [ebp-14h]
  int v20; // [esp-4h] [ebp-10h]

  v5 = ((int (__stdcall *)(_DWORD, int, int, int, int, int, int, int, int, int, int, int, int))g_pMDLCache->GetStudioHdr)(
         a1: this->m_MDLHandle,
         a2,
         a3: v10,
         a4: v11,
         a5: v12,
         a6: v13,
         a7: v14,
         a8: v15,
         a9: v16,
         a10: v17,
         a11: v18,
         a12: v19,
         a13: v20);
  v6 = (studiohdr_t *)v5;
  if ( v5 != 0 )
  {
    if ( fsqrt(
           (float)((float)(*(float *)(v5 + 108) * *(float *)(v5 + 108))
                 + (float)(*(float *)(v5 + 104) * *(float *)(v5 + 104)))
         + (float)(*(float *)(v5 + 112) * *(float *)(v5 + 112))) == 0.0 )
    {
      if ( fsqrt(
             (float)((float)(*(float *)(v5 + 132) * *(float *)(v5 + 132))
                   + (float)(*(float *)(v5 + 136) * *(float *)(v5 + 136)))
           + (float)(*(float *)(v5 + 128) * *(float *)(v5 + 128))) == 0.0 )
      {
        m_sequence = this->m_sequence;
        if ( v6->numincludemodels != 0 )
        {
          v8 = studiohdr_t::pSeqdesc_Internal(this: v6, i: this->m_sequence);
        }
        else
        {
          if ( m_sequence < 0 || m_sequence >= v6->numlocalseq )
            m_sequence = 0;
          v8 = (mstudioseqdesc_t *)((char *)v6 + 212 * m_sequence + v6->localseqindex);
        }
        *mins = v8->bbmin;
        *maxs = v8->bbmax;
      }
      else
      {
        *mins = *(Vector *)(v5 + 128);
        *maxs = *(Vector *)(v5 + 140);
      }
    }
    else
    {
      *mins = *(Vector *)(v5 + 104);
      *maxs = *(Vector *)(v5 + 116);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C520
// Name: public: float StudioModel::GetFPS(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetFPS(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_FPS(pStudioHdr: m_pStudioHdr, iSequence, poseParameter: this->m_poseparameter);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C580
// Name: public: float StudioModel::GetDuration(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetDuration(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_Duration(pStudioHdr: m_pStudioHdr, iSequence, poseParameter: this->m_poseparameter);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C5E0
// Name: public: int StudioModel::GetNumFrames(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetNumFrames(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  int NumSeq_Internal; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr
    && iSequence >= 0
    && (m_pStudioHdr->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr))
      : (NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq),
        iSequence < NumSeq_Internal) )
  {
    return Studio_MaxFrame(pStudioHdr: m_pStudioHdr, iSequence, poseParameter: this->m_poseparameter);
  }
  else
  {
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C670
// Name: public: bool StudioModel::GetSequenceLoops(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall StudioModel::GetSequenceLoops(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return false;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return false;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return false;
  return GetSequenceFlags(pStudioHdr: m_pStudioHdr, nSequence: iSequence) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C6D0
// Name: public: float StudioModel::GetDuration(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetDuration(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  int m_sequence; // edi
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  m_sequence = this->m_sequence;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_Duration(pStudioHdr: m_pStudioHdr, iSequence: m_sequence, poseParameter: this->m_poseparameter);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C740
// Name: public: void StudioModel::GetMovement(float __near * const,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::GetMovement(StudioModel *this, float *prevcycle, Vector *vecPos, QAngle *vecAngles)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v7; // eax
  CStudioHdr *v8; // ecx
  float *v10; // edi
  float *p_m_weight; // esi
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  double v16; // st7
  float flCycleFrom; // [esp+0h] [ebp-38h]
  float flCycleTo; // [esp+4h] [ebp-34h]
  QAngle angTmp; // [esp+20h] [ebp-18h] BYREF
  Vector vecTmp; // [esp+2Ch] [ebp-Ch] BYREF
  const float *prevcyclea; // [esp+40h] [ebp+8h]
  const CStudioHdr *pStudioHdr; // [esp+44h] [ebp+Ch]
  int vecAnglesa; // [esp+48h] [ebp+10h]

  vecPos->x = 0.0;
  vecPos->y = 0.0;
  vecPos->z = 0.0;
  vecAngles->x = 0.0;
  vecAngles->y = 0.0;
  vecAngles->z = 0.0;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    pStudioHdr = this->m_pStudioHdr;
    v8 = (CStudioHdr *)pStudioHdr;
  }
  else
  {
    v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
    if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
      return;
    v8 = this->m_pStudioHdr;
    pStudioHdr = v8;
  }
  if ( v8 != nullptr )
  {
    if ( (float)(this->m_cycle - *prevcycle) < -0.5 )
      *prevcycle = *prevcycle - 1.0;
    prevcyclea = this->m_poseparameter;
    Studio_SeqMovement(
      pStudioHdr: v8,
      iSequence: this->m_sequence,
      flCycleFrom: *prevcycle,
      flCycleTo: this->m_cycle,
      poseParameter: this->m_poseparameter,
      deltaPos: vecPos,
      deltaAngles: vecAngles);
    *prevcycle = this->m_cycle;
    v10 = prevcycle + 1;
    p_m_weight = &this->m_Layer[0].m_weight;
    for ( vecAnglesa = 4; vecAnglesa != 0; --vecAnglesa )
    {
      if ( (float)(*(p_m_weight - 2) - *v10) < -0.5 )
        *v10 = *v10 - 1.0;
      if ( *p_m_weight > 0.0 )
      {
        v12 = *((_DWORD *)p_m_weight - 1);
        flCycleTo = *(p_m_weight - 2);
        flCycleFrom = *v10;
        memset(&vecTmp, 0, sizeof(vecTmp));
        memset(&angTmp, 0, sizeof(angTmp));
        if ( Studio_SeqMovement(
               pStudioHdr,
               iSequence: v12,
               flCycleFrom,
               flCycleTo,
               poseParameter: prevcyclea,
               deltaPos: &vecTmp,
               deltaAngles: &angTmp) )
        {
          v13 = 1.0 - *p_m_weight;
          v14 = (float)(vecPos->y * v13) + (float)(vecTmp.y * *p_m_weight);
          v15 = (float)(vecPos->z * v13) + (float)(vecTmp.z * *p_m_weight);
          vecPos->x = (float)(vecPos->x * v13) + (float)(vecTmp.x * *p_m_weight);
          vecPos->y = v14;
          vecPos->z = v15;
        }
      }
      v16 = *(p_m_weight - 2);
      p_m_weight += 5;
      *v10++ = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C950
// Name: public: void StudioModel::GetMovement(int,float,float,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::GetMovement(
        StudioModel *this,
        int iSequence,
        float prevCycle,
        float nextCycle,
        Vector *vecPos,
        QAngle *vecAngles)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v8; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v8 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v8, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    Studio_SeqMovement(
      pStudioHdr: m_pStudioHdr,
      iSequence,
      flCycleFrom: prevCycle,
      flCycleTo: nextCycle,
      poseParameter: this->m_poseparameter,
      deltaPos: vecPos,
      deltaAngles: vecAngles);
  }
  else
  {
    vecPos->x = 0.0;
    vecPos->y = 0.0;
    vecPos->z = 0.0;
    vecAngles->x = 0.0;
    vecAngles->y = 0.0;
    vecAngles->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CA00
// Name: public: float StudioModel::GetGroundSpeed(int)
// Source: json
//------------------------------------------------------------------------------
double __userpurge StudioModel::GetGroundSpeed@<st0>(StudioModel *this@<ecx>, float a2@<ebp>, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  float y; // xmm1_4
  __int128 v7; // xmm0
  __int128 v9; // [esp+20h] [ebp-3Ch] BYREF
  Vector v10; // [esp+3Ch] [ebp-20h] BYREF
  Vector vecMove; // [esp+48h] [ebp-14h]
  void *v12; // [esp+54h] [ebp-8h]
  void *retaddr; // [esp+5Ch] [ebp+0h]

  vecMove.z = a2;
  v12 = retaddr;
  StudioModel::GetMovement(
    this,
    iSequence,
    prevCycle: 0.0,
    nextCycle: 1.0,
    vecPos: &v10,
    vecAngles: (QAngle *)((char *)&v9 + 4));
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    vecMove.y = Studio_Duration(pStudioHdr: m_pStudioHdr, iSequence, poseParameter: this->m_poseparameter);
    y = vecMove.y;
  }
  else
  {
    y = 0.0;
  }
  vecMove.y = 0.0;
  if ( y > 0.0 )
  {
    vecMove.x = v10.x * v10.x;
    v7 = 0;
    *(float *)&v7 = fsqrt((float)((float)(v10.x * v10.x) + (float)(v10.z * v10.z)) + (float)(v10.y * v10.y));
    v9 = v7;
    vecMove.y = *(float *)&v7 / y;
  }
  return vecMove.y;
}

//------------------------------------------------------------------------------
// Address: 0x0041CB10
// Name: public: bool StudioModel::IsHidden(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall StudioModel::IsHidden(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v4; // eax
  int v5; // eax
  const studiohdr_t *v6; // ecx

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  if ( m_pStudioHdr->m_pVModel != nullptr )
    return (CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: iSequence)->flags & 0x400) != 0;
  v5 = iSequence;
  v6 = m_pStudioHdr->m_pStudioHdr;
  if ( iSequence < 0 || iSequence >= v6->numlocalseq )
    v5 = 0;
  return (*(_DWORD *)&v6->name[212 * v5 + v6->localseqindex] & 0x400) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041CBA0
// Name: public: float StudioModel::SetController(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::SetController(StudioModel *this, int iController, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_SetController(
             pStudioHdr: m_pStudioHdr,
             iController,
             flValue,
             ctlValue: &this->m_controller[iController]);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CC10
// Name: public: int StudioModel::LookupPoseParameter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupPoseParameter(StudioModel *this, const char *szName)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int v7; // esi
  const mstudioposeparamdesc_t *v8; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return 0;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v7 = 0;
  if ( CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr) <= 0 )
    return -1;
  while ( 1 )
  {
    v8 = CStudioHdr::pPoseParameter(this: m_pStudioHdr, i: v7);
    if ( _V_stricmp(s1: szName, s2: (const char *)v8 + v8->sznameindex) == 0 )
      break;
    if ( ++v7 >= CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr) )
      return -1;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0041CCB0
// Name: public: float StudioModel::SetPoseParameter(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::SetPoseParameter(StudioModel *this, int iParameter, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_SetPoseParameter(
             pStudioHdr: m_pStudioHdr,
             iParameter,
             flValue,
             ctlValue: &this->m_poseparameter[iParameter]);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CD20
// Name: public: float __near * StudioModel::GetPoseParameters(void)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall StudioModel::GetPoseParameters(StudioModel *this)
{
  return this->m_poseparameter;
}

//------------------------------------------------------------------------------
// Address: 0x0041CD30
// Name: public: bool StudioModel::GetPoseParameterRange(int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::GetPoseParameterRange(StudioModel *this, int iParameter, float *pflMin, float *pflMax)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  CStudioHdr *v7; // esi
  const mstudioposeparamdesc_t *v9; // eax

  *pflMin = 0.0;
  *pflMax = 0.0;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v7 = this->m_pStudioHdr;
  }
  else
  {
    v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
    v7 = this->m_pStudioHdr;
    if ( v7->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( v7 == nullptr )
    return 0;
  if ( iParameter < 0 || iParameter >= CStudioHdr::GetNumPoseParameters(this: v7) )
    return 0;
  v9 = CStudioHdr::pPoseParameter(this: v7, i: iParameter);
  *pflMin = v9->start;
  *pflMax = v9->end;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041CDD0
// Name: public: int StudioModel::LookupAttachment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupAttachment(StudioModel *this, const char *szName)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int v7; // esi
  const mstudioattachment_t *v8; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return -1;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  v7 = 0;
  if ( CStudioHdr::GetNumAttachments(this: m_pStudioHdr) <= 0 )
    return -1;
  while ( 1 )
  {
    v8 = CStudioHdr::pAttachment(this: m_pStudioHdr, i: v7);
    if ( _V_stricmp(s1: (const char *)v8 + v8->sznameindex, s2: szName) == 0 )
      break;
    if ( ++v7 >= CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
      return -1;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0041CE70
// Name: public: int StudioModel::SetBodygroup(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetBodygroup(StudioModel *this, int iGroup, int iValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  int result; // eax
  int v7; // ecx
  int v8; // edi

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( iGroup > m_pStudioHdr->m_pStudioHdr->numbodyparts )
    return -1;
  v7 = (int)m_pStudioHdr->m_pStudioHdr + 16 * iGroup + m_pStudioHdr->m_pStudioHdr->bodypartindex;
  v8 = *(_DWORD *)(v7 + 4);
  result = iValue;
  if ( iValue >= v8 )
    return this->m_bodynum / *(_DWORD *)(v7 + 8) % v8;
  this->m_bodynum += *(_DWORD *)(v7 + 8) * (iValue - this->m_bodynum / *(_DWORD *)(v7 + 8) % v8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041CF10
// Name: public: int StudioModel::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetSkin(StudioModel *this, int iValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  int result; // eax
  const studiohdr_t *v6; // ecx

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v6 = m_pStudioHdr->m_pStudioHdr;
  result = iValue;
  if ( iValue >= v6->numskinfamilies )
    return this->m_skinnum;
  this->m_skinnum = iValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041CF80
// Name: public: struct virtualmodel_t __near * studiohdr_t::GetVirtualModel(void)const
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall studiohdr_t::GetVirtualModel(studiohdr_t *this)
{
  return g_pMDLCache->GetVirtualModel(this: g_pMDLCache, a2: (unsigned __int16)this->virtualModel);
}

//------------------------------------------------------------------------------
// Address: 0x0041CFA0
// Name: public: unsigned char __near * studiohdr_t::GetAnimBlock(int,bool)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall studiohdr_t::GetAnimBlock(studiohdr_t *this, int i, BOOL preloadIfMissing)
{
  return g_pMDLCache->GetAnimBlock(
           this: g_pMDLCache,
           a2: (unsigned __int16)this->virtualModel,
           a3: i,
           a4: preloadIfMissing);
}

//------------------------------------------------------------------------------
// Address: 0x0041CFD0
// Name: public: bool studiohdr_t::hasAnimBlockBeenPreloaded(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall studiohdr_t::hasAnimBlockBeenPreloaded(studiohdr_t *this, int i)
{
  return g_pMDLCache->HasAnimBlockBeenPreloaded(this: g_pMDLCache, a2: (unsigned __int16)this->virtualModel, a3: i);
}

//------------------------------------------------------------------------------
// Address: 0x0041D000
// Name: public: int studiohdr_t::GetAutoplayList(unsigned short __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall studiohdr_t::GetAutoplayList(studiohdr_t *this, unsigned __int16 **pOut)
{
  return g_pMDLCache->GetAutoplayList(this: g_pMDLCache, a2: (unsigned __int16)this->virtualModel, a3: pOut);
}

//------------------------------------------------------------------------------
// Address: 0x0041D030
// Name: public: struct studiohdr_t const __near * virtualgroup_t::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall virtualgroup_t::GetStudioHdr(virtualgroup_t *this)
{
  return g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: (unsigned __int16)this->cache);
}

//------------------------------------------------------------------------------
// Address: 0x0041D0E0
// Name: public: virtual bool StudioModel::PostLoadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::PostLoadModel(StudioModel *this, const char *modelname)
{
  IMDLCache *v2; // edi
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v5; // eax
  int i; // edi
  CStudioHdr *v8; // eax
  const studiohdr_t *v9; // eax
  IMDLCache *cacheCriticalSection; // [esp+14h] [ebp-4h]

  v2 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    StudioModel::SetSequence(this, iSequence: 0);
    StudioModel::SetController(this, iController: 0, flValue: 0.0);
    StudioModel::SetController(this, iController: 1, flValue: 0.0);
    StudioModel::SetController(this, iController: 2, flValue: 0.0);
    StudioModel::SetController(this, iController: 3, flValue: 0.0);
    this->m_blendtime = 0.2;
    for ( i = 0; i < m_pStudioHdr->m_pStudioHdr->numbodyparts; ++i )
      StudioModel::SetBodygroup(this, iGroup: i, iValue: 0);
    v8 = this->m_pStudioHdr;
    if ( v8 != nullptr )
    {
      if ( v8->m_pStudioHdr != nullptr
        || (v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
            CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr),
            (v8 = this->m_pStudioHdr)->m_pStudioHdr != nullptr) )
      {
        if ( v8 != nullptr && v8->m_pStudioHdr->numskinfamilies > 0 )
          this->m_skinnum = 0;
      }
    }
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
    return 1;
  }
  else
  {
    v2->EndLock(this: v2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D240
// Name: public: void StudioModel::ClearOverlaysSequences(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::ClearOverlaysSequences(StudioModel *this)
{
  this->m_iActiveLayers = 0;
  memset(dst: (unsigned __int8 *)this->m_Layer, value: 0, count: sizeof(this->m_Layer));
}

//------------------------------------------------------------------------------
// Address: 0x0041D270
// Name: public: void StudioModel::SetFlexController(enum LocalFlexController_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetFlexController(StudioModel *this, LocalFlexController_t iFlex, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  const studiohdr_t *v6; // eax
  __int32 v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float *v10; // ecx
  bool v11; // zf
  float v12; // xmm0_4
  int v13; // xmm1_4

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr != nullptr
      || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
          CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
          (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr) )
    {
      if ( m_pStudioHdr != nullptr && iFlex >= DUMMY_NULL_FLEX_CONTROLLER )
      {
        v6 = m_pStudioHdr->m_pStudioHdr;
        if ( iFlex < v6->numflexcontrollers )
        {
          v7 = v6->flexcontrollerindex + 20 * iFlex;
          v8 = *(float *)&v6->name[v7];
          v9 = *(float *)&v6->name[v7 + 4];
          v10 = (float *)((char *)&v6->id + v7);
          v11 = v8 == v9;
          v12 = flValue;
          if ( !v11 )
            v12 = (float)(flValue - v10[3]) / (float)(v9 - v10[3]);
          v13 = 0;
          if ( v12 < 0.0 || (v13 = 1065353216, v12 > 1.0) )
            v12 = *(float *)&v13;
          this->m_flexweight[iFlex] = v12;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D330
// Name: public: float StudioModel::GetFlexController(char __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetFlexController(StudioModel *this, char *szName)
{
  int v3; // eax

  v3 = StudioModel::LookupFlexController(this, szName);
  return StudioModel::GetFlexController(this, iFlex: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0041D350
// Name: public: void StudioModel::GetSequenceInfo(int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::GetSequenceInfo(
        StudioModel *this,
        int iSequence,
        float *pflFrameRate,
        float *pflGroundSpeed)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v7; // eax
  double v8; // st7
  int savedregs; // [esp+8h] [ebp+0h] BYREF
  float t; // [esp+10h] [ebp+8h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr
    && (v8 = Studio_Duration(pStudioHdr: m_pStudioHdr, iSequence, poseParameter: this->m_poseparameter)) > 0.0 )
  {
    t = v8;
    *pflFrameRate = 1.0 / t;
    *pflGroundSpeed = StudioModel::GetGroundSpeed(this, a2: COERCE_FLOAT(&savedregs), iSequence);
  }
  else
  {
    *pflFrameRate = 1.0;
    *pflGroundSpeed = StudioModel::GetGroundSpeed(this, a2: COERCE_FLOAT(&savedregs), iSequence);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D410
// Name: public: float StudioModel::SetPoseParameter(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::SetPoseParameter(StudioModel *this, const char *szName, float flValue)
{
  int v4; // eax

  v4 = StudioModel::LookupPoseParameter(this, szName);
  return StudioModel::SetPoseParameter(this, iParameter: v4, flValue);
}

//------------------------------------------------------------------------------
// Address: 0x0041D800
// Name: public: void StudioModel::FreeModel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::FreeModel(StudioModel *this, bool bReleasing)
{
  CStudioHdr *m_pStudioHdr; // edi

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    CStudioHdr::Term(this: this->m_pStudioHdr);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&m_pStudioHdr->m_boneParent);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&m_pStudioHdr->m_boneFlags);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
    free(pMem: m_pStudioHdr);
    this->m_pStudioHdr = nullptr;
  }
  if ( this->m_MDLHandle != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_MDLHandle);
    this->m_MDLHandle = -1;
  }
  if ( !bReleasing && this->m_pModelName != nullptr )
  {
    free(pMem: this->m_pModelName);
    this->m_pModelName = nullptr;
  }
  this->m_SurfaceProps.m_Size = 0;
  if ( this->m_SurfaceProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SurfaceProps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SurfaceProps.m_Memory.m_pMemory);
      this->m_SurfaceProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_SurfaceProps.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SurfaceProps.m_pElements = this->m_SurfaceProps.m_Memory.m_pMemory;
  DestroyPhysics(pStudioPhysics: this->m_pPhysics);
  this->m_pPhysics = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041D9A0
// Name: public: static void StudioModel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl StudioModel::Shutdown()
{
  StudioModel::FreeModel(this: g_pStudioModel, bReleasing: false);
  free(pMem: StudioModel::m_AmbientLightColors);
}

//------------------------------------------------------------------------------
// Address: 0x0041D9C0
// Name: public: static void StudioModel::ReleaseStudioModel(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl StudioModel::ReleaseStudioModel()
{
  SaveViewerSettings(filename: g_pStudioModel->m_pModelName, pModel: g_pStudioModel);
  StudioModel::FreeModel(this: g_pStudioModel, bReleasing: true);
}

//------------------------------------------------------------------------------
// Address: 0x0041DB20
// Name: public: bool StudioModel::LoadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::LoadModel(StudioModel *this, const char *pModelName)
{
  IMDLCache *v2; // esi
  StudioModel *v3; // edi
  const char *v4; // ebx
  const char *m_pModelName; // eax
  int v7; // eax
  char *v8; // eax
  const char *v9; // ecx
  char *v10; // edx
  char v11; // al
  unsigned __int16 v12; // ax
  CStudioHdr *m_pStudioHdr; // ebx
  CStudioHdr *v14; // ebx
  const studiohdr_t *v15; // eax
  CStudioHdr *v16; // eax
  CStudioHdr *v17; // eax
  const studiohdr_t *v18; // eax
  CStudioHdr *v19; // ebx
  const studiohdr_t *v20; // eax
  int v21; // esi
  bool v22; // zf
  mstudiohitboxset_t *v23; // esi
  CUtlString *p_m_Name; // edi
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *v25; // ebx
  const char *v26; // edi
  int v27; // esi
  unsigned __int16 v28; // ax
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *m_pMemory; // eax
  int v30; // edx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v31; // ecx
  CUtlString *v32; // ecx
  int v33; // esi
  int v34; // eax
  int v35; // esi
  const char *v36; // eax
  const studiohdr_t *v37; // ecx
  CUtlMemory<short,int> *p_m_SurfaceProps; // esi
  __int16 *v39; // edi
  int m_nAllocationCount; // eax
  __int16 *v41; // ecx
  int v42; // eax
  __int16 *v43; // edi
  int v44; // eax
  bool v45; // cl
  studiohwdata_t *v46; // eax
  studiohwdata_t *v47; // ebx
  int m_RootLOD; // ecx
  int v49; // eax
  int v50; // esi
  int v51; // edi
  int v52; // ecx
  int v53; // ecx
  int v54; // ecx
  IMDLCache *v55; // [esp-4h] [ebp-30h]
  int m_MDLHandle; // [esp-4h] [ebp-30h]
  unsigned __int16 m_Tail; // [esp+Ch] [ebp-20h]
  int lodID; // [esp+10h] [ebp-1Ch]
  int lodIDa; // [esp+10h] [ebp-1Ch]
  mstudiohitboxset_t *pSrcSet; // [esp+14h] [ebp-18h]
  mstudiohitboxset_t *pSrcSeta; // [esp+14h] [ebp-18h]
  IMDLCache *cacheCriticalSection; // [esp+18h] [ebp-14h]
  int v63; // [esp+1Ch] [ebp-10h]
  int v64; // [esp+1Ch] [ebp-10h]
  CStudioHdr *pStudioHdr; // [esp+20h] [ebp-Ch]
  int i; // [esp+28h] [ebp-4h]
  int ia; // [esp+28h] [ebp-4h]

  v2 = g_pMDLCache;
  v3 = this;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  v4 = pModelName;
  if ( pModelName == nullptr )
    goto LABEL_2;
  m_pModelName = v3->m_pModelName;
  if ( m_pModelName != pModelName )
  {
    if ( m_pModelName != nullptr )
      free(pMem: v3->m_pModelName);
    v7 = _V_strlen(str: v4);
    v8 = (char *)operator new(nSize: v7 + 1);
    v3->m_pModelName = v8;
    v9 = v4;
    v10 = v8;
    do
    {
      v11 = *v9;
      *v10++ = *v9++;
    }
    while ( v11 != 0 );
  }
  v12 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: v4);
  m_pStudioHdr = v3->m_pStudioHdr;
  v3->m_MDLHandle = v12;
  if ( m_pStudioHdr != nullptr )
  {
    CStudioHdr::Term(this: m_pStudioHdr);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&m_pStudioHdr->m_boneParent);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&m_pStudioHdr->m_boneFlags);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
    free(pMem: m_pStudioHdr);
  }
  v14 = (CStudioHdr *)operator new(nSize: 0x64u);
  if ( v14 != nullptr )
  {
    v55 = g_pMDLCache;
    v15 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    v16 = CStudioHdr::CStudioHdr(this: v14, pStudioHdr: v15, mdlcache: v55);
  }
  else
  {
    v16 = nullptr;
  }
  m_MDLHandle = v3->m_MDLHandle;
  v3->m_pStudioHdr = v16;
  g_pActiveModel = v3;
  v3->m_pPhysics = LoadPhysics(a1: (int)v14, mdlHandle: m_MDLHandle);
  CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::RemoveAll(this: &v3->m_HitboxSets);
  v17 = v3->m_pStudioHdr;
  if ( v17 == nullptr || v17->m_pStudioHdr != nullptr )
  {
    pStudioHdr = v3->m_pStudioHdr;
    v19 = pStudioHdr;
  }
  else
  {
    v18 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v18, mdlcache: nullptr);
    v19 = v3->m_pStudioHdr->m_pStudioHdr != nullptr ? v3->m_pStudioHdr : nullptr;
    pStudioHdr = v19;
  }
  v20 = v19->m_pStudioHdr;
  lodID = 0;
  if ( v19->m_pStudioHdr->numhitboxsets > 0 )
  {
    v63 = 0;
    do
    {
      v21 = v63 + v20->hitboxsetindex;
      v22 = (const studiohdr_t *)((char *)v20 + v21) == nullptr;
      v23 = (mstudiohitboxset_t *)((char *)v20 + v21);
      pSrcSet = v23;
      if ( !v22 )
      {
        p_m_Name = &v3->m_HitboxSets.m_Memory.m_pMemory[CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::InsertBefore(
                                                          this: &v3->m_HitboxSets,
                                                          elem: v3->m_HitboxSets.m_Size)].m_Name;
        CUtlString::operator=(this: p_m_Name, src: (const char *)v23 + v23->sznameindex);
        i = 0;
        if ( v23->numhitboxes > 0 )
        {
          v25 = (CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *)&p_m_Name[1];
          pModelName = nullptr;
          while ( 1 )
          {
            v26 = &pModelName[(_DWORD)v23 + v23->hitboxindex];
            v27 = (unsigned __int16)CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal(
                                      this: v25,
                                      multilist: false);
            v28 = -1;
            if ( (_WORD)v27 != 0xFFFF )
            {
              CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::Unlink(
                this: v25,
                elem: v27);
              m_pMemory = v25->m_Memory.m_pMemory;
              v30 = v27;
              m_pMemory[v30].m_Next = -1;
              m_Tail = v25->m_Tail;
              m_pMemory[v30].m_Previous = m_Tail;
              v25->m_Tail = v27;
              if ( m_Tail == 0xFFFF )
                v25->m_Head = v27;
              else
                v25->m_Memory.m_pMemory[m_Tail].m_Next = v27;
              v31 = v25->m_Memory.m_pMemory;
              ++v25->m_ElementCount;
              v32 = &v31[v30].m_Element.m_Name;
              if ( v32 != nullptr )
                CUtlString::CUtlString(this: v32);
              v28 = v27;
            }
            v33 = v28;
            v34 = *((_DWORD *)v26 + 8);
            v35 = (int)&v25->m_Memory.m_pMemory[v33];
            v36 = v34 != 0 ? &v26[v34] : defaultValue;
            CUtlString::operator=(this: (CUtlString *)v35, src: v36);
            *(_DWORD *)(v35 + 16) = *(_DWORD *)v26;
            *(_DWORD *)(v35 + 20) = *((_DWORD *)v26 + 1);
            *(float *)(v35 + 24) = *((float *)v26 + 2);
            pModelName += 68;
            *(float *)(v35 + 28) = *((float *)v26 + 3);
            *(float *)(v35 + 32) = *((float *)v26 + 4);
            *(float *)(v35 + 36) = *((float *)v26 + 5);
            *(float *)(v35 + 40) = *((float *)v26 + 6);
            *(float *)(v35 + 44) = *((float *)v26 + 7);
            *(_DWORD *)(v35 + 48) = *((_DWORD *)v26 + 8);
            *(_DWORD *)(v35 + 52) = *((_DWORD *)v26 + 9);
            *(_DWORD *)(v35 + 56) = *((_DWORD *)v26 + 10);
            *(_DWORD *)(v35 + 60) = *((_DWORD *)v26 + 11);
            *(_DWORD *)(v35 + 64) = *((_DWORD *)v26 + 12);
            *(_DWORD *)(v35 + 68) = *((_DWORD *)v26 + 13);
            *(_DWORD *)(v35 + 72) = *((_DWORD *)v26 + 14);
            *(_DWORD *)(v35 + 76) = *((_DWORD *)v26 + 15);
            *(_DWORD *)(v35 + 80) = *((_DWORD *)v26 + 16);
            *(_DWORD *)(v35 + 48) = 0;
            if ( ++i >= pSrcSet->numhitboxes )
              break;
            v23 = pSrcSet;
          }
          v19 = pStudioHdr;
        }
        v3 = this;
      }
      v20 = v19->m_pStudioHdr;
      v63 += 12;
      ++lodID;
    }
    while ( lodID < v19->m_pStudioHdr->numhitboxsets );
    v2 = cacheCriticalSection;
  }
  v37 = v19->m_pStudioHdr;
  ia = 0;
  if ( v19->m_pStudioHdr->numbones > 0 )
  {
    p_m_SurfaceProps = (CUtlMemory<short,int> *)&v3->m_SurfaceProps;
    v64 = 0;
    do
    {
      CUtlSymbol::CUtlSymbol(
        this: (CUtlSymbol *)&pModelName,
        pStr: (const char *)v37 + v64 + v37->boneindex + *(int *)((char *)&v37->hitboxsetindex + v64 + v37->boneindex));
      v39 = p_m_SurfaceProps[1].m_pMemory;
      m_nAllocationCount = p_m_SurfaceProps->m_nAllocationCount;
      if ( (int)v39 + 1 > m_nAllocationCount )
        CUtlMemory<CUtlSymbol,int>::Grow(this: p_m_SurfaceProps, num: (int)v39 - m_nAllocationCount + 1);
      ++p_m_SurfaceProps[1].m_pMemory;
      v41 = p_m_SurfaceProps->m_pMemory;
      v42 = (char *)p_m_SurfaceProps[1].m_pMemory - (char *)v39 - 1;
      p_m_SurfaceProps[1].m_nAllocationCount = (int)p_m_SurfaceProps->m_pMemory;
      if ( v42 > 0 )
        _V_memmove(dest: &v41[(_DWORD)v39 + 1], src: &v41[(_DWORD)v39], count: 2 * v42);
      v43 = &p_m_SurfaceProps->m_pMemory[(_DWORD)v39];
      if ( v43 != nullptr )
        *v43 = (__int16)pModelName;
      v37 = v19->m_pStudioHdr;
      v64 += 216;
      ++ia;
    }
    while ( ia < v19->m_pStudioHdr->numbones );
    v3 = this;
    v2 = cacheCriticalSection;
  }
  v3->m_physPreviewBone = -1;
  v44 = v3->m_MDLHandle;
  v45 = (v19->m_pStudioHdr->flags & 4) != 0;
  *(_WORD *)&v3->m_bIsTransparent = 0;
  HIBYTE(pModelName) = v45;
  v46 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: v44);
  v47 = v46;
  if ( v46 != nullptr )
  {
    m_RootLOD = v46->m_RootLOD;
    lodIDa = v46->m_RootLOD;
    if ( v46->m_RootLOD < v46->m_NumLODs )
    {
      v49 = 32 * m_RootLOD;
      pSrcSeta = (mstudiohitboxset_t *)(32 * m_RootLOD);
      do
      {
        v50 = (int)v47->m_pLODs + v49;
        v51 = 0;
        if ( *(int *)(v50 + 8) > 0 )
        {
          do
          {
            v52 = *(_DWORD *)(*(_DWORD *)(v50 + 12) + 4 * v51);
            (*(void (__thiscall **)(int))(*(_DWORD *)v52 + 76))(a1: v52);
            if ( HIBYTE(pModelName) == 0 )
            {
              v53 = *(_DWORD *)(*(_DWORD *)(v50 + 12) + 4 * v51);
              if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v53 + 68))(a1: v53) != 0 )
                this->m_bIsTransparent = true;
            }
            v54 = *(_DWORD *)(*(_DWORD *)(v50 + 12) + 4 * v51);
            if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v54 + 84))(a1: v54) != 0 )
              this->m_bHasProxy = true;
            ++v51;
          }
          while ( v51 < *(_DWORD *)(v50 + 8) );
          v49 = (int)pSrcSeta;
          m_RootLOD = lodIDa;
        }
        ++m_RootLOD;
        v49 += 32;
        lodIDa = m_RootLOD;
        pSrcSeta = (mstudiohitboxset_t *)v49;
      }
      while ( m_RootLOD < v47->m_NumLODs );
      v2 = cacheCriticalSection;
    }
    v2->EndLock(this: v2);
    return 1;
  }
  else
  {
LABEL_2:
    v2->EndLock(this: v2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E030
// Name: public: StudioModel::StudioModel(void)
// Source: json
//------------------------------------------------------------------------------
StudioModel *__thiscall StudioModel::StudioModel(StudioModel *this)
{
  void *v2; // eax
  matrix3x4a_t *v4; // ecx

  this->__vftable = (StudioModel_vtbl *)&StudioModel::`vftable';
  this->m_mouth.m_VoiceSources[0].m_flElapsed = 0.0;
  this->m_mouth.m_VoiceSources[0].m_pAudioSource = nullptr;
  this->m_mouth.m_VoiceSources[0].m_bIgnorePhonemes = false;
  this->m_mouth.m_VoiceSources[1].m_flElapsed = 0.0;
  this->m_mouth.m_VoiceSources[1].m_pAudioSource = nullptr;
  this->m_mouth.m_VoiceSources[1].m_bIgnorePhonemes = false;
  this->m_mouth.m_VoiceSources[2].m_flElapsed = 0.0;
  this->m_mouth.m_VoiceSources[2].m_pAudioSource = nullptr;
  this->m_mouth.m_VoiceSources[2].m_bIgnorePhonemes = false;
  this->m_mouth.m_VoiceSources[3].m_flElapsed = 0.0;
  this->m_mouth.m_VoiceSources[3].m_pAudioSource = nullptr;
  this->m_mouth.m_VoiceSources[3].m_bIgnorePhonemes = false;
  *(_DWORD *)&this->m_mouth.m_nVoiceSources = 0;
  this->m_HitboxSets.m_Memory.m_pMemory = nullptr;
  this->m_HitboxSets.m_Memory.m_nAllocationCount = 0;
  this->m_HitboxSets.m_Memory.m_nGrowSize = 0;
  this->m_HitboxSets.m_Size = 0;
  this->m_HitboxSets.m_pElements = nullptr;
  this->m_SurfaceProps.m_Memory.m_pMemory = nullptr;
  this->m_SurfaceProps.m_Memory.m_nAllocationCount = 0;
  this->m_SurfaceProps.m_Memory.m_nGrowSize = 0;
  this->m_SurfaceProps.m_Size = 0;
  this->m_SurfaceProps.m_pElements = nullptr;
  this->m_vecHeadTargets.m_Memory.m_pMemory = nullptr;
  this->m_vecHeadTargets.m_Memory.m_nAllocationCount = 0;
  this->m_vecHeadTargets.m_Memory.m_nGrowSize = 0;
  this->m_vecHeadTargets.m_Size = 0;
  this->m_vecHeadTargets.m_pElements = nullptr;
  CIKContext::CIKContext(this: &this->m_ik);
  this->m_MDLHandle = -1;
  StudioModel::ClearLookTargets(this);
  v2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12307);
  if ( v2 != nullptr )
  {
    v4 = (matrix3x4a_t *)(((unsigned int)v2 + 19) & 0xFFFFFFF0);
    LODWORD(v4[-1].m_flMatVal[2][3]) = v2;
    this->m_pBoneToWorld = v4;
  }
  else
  {
    this->m_pBoneToWorld = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041E120
// Name: public: StudioModel::~StudioModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::~StudioModel(StudioModel *this)
{
  matrix3x4a_t *m_pBoneToWorld; // eax

  m_pBoneToWorld = this->m_pBoneToWorld;
  this->__vftable = (StudioModel_vtbl *)&StudioModel::`vftable';
  if ( m_pBoneToWorld != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pBoneToWorld & 0xFFFFFFFC) - 4));
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ik.m_ikLock);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_ik.m_ikChainRule);
  this->m_ik.m_target.m_Size = 0;
  this->m_ik.m_target.m_pElements = (CIKTarget *)&this->m_ik;
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_vecHeadTargets);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SurfaceProps);
  CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::~CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>(this: &this->m_HitboxSets);
  this->m_mouth.m_nVoiceSources = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E1A0
// Name: public: static void StudioModel::RestoreStudioModel(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl StudioModel::RestoreStudioModel()
{
  if ( StudioModel::LoadModel(this: g_pStudioModel, pModelName: g_pStudioModel->m_pModelName) != 0 )
    g_pStudioModel->PostLoadModel(this: g_pStudioModel, a2: g_pStudioModel->m_pModelName);
}

//------------------------------------------------------------------------------
// Address: 0x004CDD20
// Name: GetSequenceFlags
// Source: json
//------------------------------------------------------------------------------
int __usercall GetSequenceFlags@<eax>(CStudioHdr *pStudioHdr@<eax>, int nSequence@<edi>)
{
  int v3; // eax
  const studiohdr_t *m_pStudioHdr; // esi
  int v5; // eax

  if ( pStudioHdr == nullptr || nSequence < 0 )
    return 0;
  v3 = pStudioHdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pStudioHdr)
     : pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( nSequence >= v3 )
    return 0;
  if ( pStudioHdr->m_pVModel != nullptr )
    return CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: nSequence)->flags;
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  v5 = nSequence;
  if ( nSequence >= m_pStudioHdr->numlocalseq )
    v5 = 0;
  return *(_DWORD *)&m_pStudioHdr->name[212 * v5 + m_pStudioHdr->localseqindex];
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0040B9A0
// Name: public: int CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040BA50
// Name: public: int CUtlVector<class CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>,class CUtlMemory<class CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,int>>::InsertBefore(
        CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *m_pMemory; // ecx
  int v6; // eax
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Memory.m_pMemory = nullptr;
    v7->m_Memory.m_nAllocationCount = 0;
    v7->m_Memory.m_nGrowSize = 0;
    v7->m_Size = 0;
    v7->m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040BEF0
// Name: public: int CUtlVector<struct HitboxSet_t,class CUtlMemory<struct HitboxSet_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::InsertBefore(
        CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  HitboxSet_t *m_pMemory; // ecx
  int v6; // eax
  HitboxSet_t *v7; // esi
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>::Grow(
      (CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_Name);
    v7->m_Hitboxes.m_Memory.m_pMemory = nullptr;
    v7->m_Hitboxes.m_Memory.m_nAllocationCount = 0;
    v7->m_Hitboxes.m_Memory.m_nGrowSize = 0;
    v7->m_Hitboxes.m_LastAlloc.index = -1;
    *(_DWORD *)&v7->m_Hitboxes.m_FirstFree = 0xFFFF;
    v8 = v7->m_Hitboxes.m_Memory.m_pMemory;
    *(_DWORD *)&v7->m_Hitboxes.m_Head = -1;
    v7->m_Hitboxes.m_NumAlloced = 0;
    v7->m_Hitboxes.m_pElements = v8;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040BF80
// Name: public: void CUtlVector<struct HitboxSet_t,class CUtlMemory<struct HitboxSet_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::RemoveAll(
        CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int> > *this)
{
  int v1; // eax
  int v2; // eax
  char *v3; // esi
  CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int> > *v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    for ( j = v2; ; v2 = j )
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *)(v3 + 16));
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 4));
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      j -= 44;
      this = v4;
      if ( --i < 0 )
        break;
    }
    v4->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C020
// Name: public: void CUtlVector<class CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>,class CUtlMemory<class CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,int> > *this)
{
  int v1; // edi
  int v2; // eax
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v3; // esi
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // eax
  CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    for ( i = 20 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)((char *)this->m_Memory.m_pMemory + v2);
      CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      i -= 20;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CEB0
// Name: public: CUtlVector<class CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>,class CUtlMemory<class CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>,int>>::~CUtlVector<class CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>,class CUtlMemory<class CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,int>>::~CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,int>>(
        CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DD50
// Name: public: CUtlVector<struct GetTriangles_MaterialBatch_t,class CUtlMemory<struct GetTriangles_MaterialBatch_t,int>>::~CUtlVector<struct GetTriangles_MaterialBatch_t,class CUtlMemory<struct GetTriangles_MaterialBatch_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(
        CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int> > *this)
{
  bool v2; // sf
  GetTriangles_MaterialBatch_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll((CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413510
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edx
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
    v7 = 100 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<JiggleData,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: m_pMemory,
                                                                            a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<JiggleData,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F390
// Name: public: int CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(
        CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->activityIdx = -1;
          v11->startingIdx = -1;
          v11->count = -1;
          v11->totalWeight = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00420CD0
// Name: public: void CUtlMemory<class CUtlVector<class CAttributeNode __near *,class CUtlMemory<class CAttributeNode __near *,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CDmElement *,int> *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CDmElement *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004259A0
// Name: public: int CUtlVector<struct StudioLookTarget,class CUtlMemory<struct StudioLookTarget,int>>::InsertBefore(int,struct StudioLookTarget const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<StudioLookTarget,CUtlMemory<StudioLookTarget,int>>::InsertBefore(
        CUtlVector<StudioLookTarget,CUtlMemory<StudioLookTarget,int> > *this,
        int elem,
        const StudioLookTarget *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  StudioLookTarget *m_pMemory; // ecx
  int v7; // eax
  StudioLookTarget *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004268B0
// Name: public: static void StudioModel::Init(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl StudioModel::Init()
{
  int v0; // eax

  v0 = g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender);
  StudioModel::m_AmbientLightColors = (Vector *)operator new(nSize: 12 * v0);
  StudioModel::UpdateStudioRenderConfig(
    bWireframe: g_viewerSettings.renderMode == 0,
    bZBufferWireframe: false,
    bNormals: g_viewerSettings.showNormals,
    bTangentFrame: g_viewerSettings.showTangentFrame);
}

//------------------------------------------------------------------------------
// Address: 0x00426910
// Name: public: void StudioModel::SetCurrentModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetCurrentModel(StudioModel *this)
{
  g_pActiveModel = this;
}

//------------------------------------------------------------------------------
// Address: 0x00426920
// Name: public: static void __near * StudioModel::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl StudioModel::operator new(unsigned int stAllocateBlock)
{
  void *v1; // eax
  unsigned __int8 *v3; // esi

  v1 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: stAllocateBlock + 19);
  if ( v1 != nullptr )
  {
    v3 = (unsigned __int8 *)(((unsigned int)v1 + 19) & 0xFFFFFFF0);
    *((_DWORD *)v3 - 1) = v1;
    memset(dst: v3, value: 0, count: stAllocateBlock);
    return v3;
  }
  else
  {
    memset(dst: nullptr, value: 0, count: stAllocateBlock);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426970
// Name: public: static void StudioModel::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StudioModel::operator delete(unsigned int pMem)
{
  if ( pMem != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((pMem & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x004269A0
// Name: public: bool StudioModel::HasModel(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::HasModel(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v3; // eax
  CStudioHdr *v4; // esi
  const studiohdr_t *v6; // edx
  int numbodyparts; // esi
  int v8; // ecx
  int i; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v4 = this->m_pStudioHdr;
  }
  else
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    v4 = this->m_pStudioHdr;
    if ( v4->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( v4 == nullptr )
    return 0;
  v6 = v4->m_pStudioHdr;
  numbodyparts = v4->m_pStudioHdr->numbodyparts;
  v8 = 0;
  if ( numbodyparts <= 0 )
    return 0;
  for ( i = 0; *(int *)((char *)&v6->version + i + v6->bodypartindex) == 0; i += 16 )
  {
    if ( ++v8 >= numbodyparts )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426A20
// Name: public: int StudioModel::GetSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetSequence(StudioModel *this)
{
  return this->m_sequence;
}

//------------------------------------------------------------------------------
// Address: 0x00426A30
// Name: public: int StudioModel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetSequence(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  int NumSeq_Internal; // eax
  int m_sequence; // edx

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( iSequence < 0 )
    return 0;
  if ( m_pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
  else
    NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( iSequence > NumSeq_Internal )
    return this->m_sequence;
  m_sequence = this->m_sequence;
  this->m_sequence = iSequence;
  this->m_prevsequence = m_sequence;
  this->m_cycle = 0.0;
  this->m_sequencetime = 0.0;
  return iSequence;
}

//------------------------------------------------------------------------------
// Address: 0x00426AE0
// Name: public: char const __near * StudioModel::GetSequenceName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall StudioModel::GetSequenceName(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int v7; // eax
  const studiohdr_t *v8; // esi
  int v9; // eax
  char *v10; // ecx
  mstudioseqdesc_t *v11; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v5 = this->m_pStudioHdr;
  }
  else
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return nullptr;
  }
  if ( v5 == nullptr )
    return nullptr;
  if ( iSequence < 0 )
    return nullptr;
  v7 = v5->m_pVModel != nullptr ? CStudioHdr::GetNumSeq_Internal(this: v5) : v5->m_pStudioHdr->numlocalseq;
  if ( iSequence > v7 )
    return nullptr;
  if ( v5->m_pVModel != nullptr )
  {
    v11 = CStudioHdr::pSeqdesc_Internal(this: v5, i: iSequence);
    return (char *)v11 + v11->szlabelindex;
  }
  else
  {
    v8 = v5->m_pStudioHdr;
    v9 = iSequence;
    if ( iSequence >= v8->numlocalseq )
      v9 = 0;
    v10 = (char *)v8 + 212 * v9 + v8->localseqindex;
    return &v10[*((_DWORD *)v10 + 1)];
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426BA0
// Name: public: int StudioModel::SetOverlaySequence(int,int,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetOverlaySequence(StudioModel *this, unsigned int iLayer, int iSequence, float flWeight)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  int NumSeq_Internal; // eax
  char *v9; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( iSequence < 0 )
    return 0;
  if ( iLayer > 7 )
    return 0;
  if ( m_pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
  else
    NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( iSequence > NumSeq_Internal )
    return this->m_Layer[iLayer].m_sequence;
  v9 = (char *)this + 20 * iLayer;
  this->m_Layer[iLayer].m_weight = flWeight;
  *((_DWORD *)v9 + 39) = iSequence;
  *((_DWORD *)v9 + 41) = 1065353216;
  return iSequence;
}

//------------------------------------------------------------------------------
// Address: 0x00426C70
// Name: public: int StudioModel::GetOverlaySequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetOverlaySequence(StudioModel *this, unsigned int iLayer)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return -1;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( iLayer > 7 )
    return 0;
  return this->m_Layer[iLayer].m_sequence;
}

//------------------------------------------------------------------------------
// Address: 0x00426CE0
// Name: public: float StudioModel::GetOverlaySequenceWeight(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetOverlaySequenceWeight(StudioModel *this, unsigned int iLayer)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1.0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return -1.0;
  }
  if ( m_pStudioHdr == nullptr )
    return -1.0;
  if ( iLayer > 7 )
    return 0.0;
  return this->m_Layer[iLayer].m_weight;
}

//------------------------------------------------------------------------------
// Address: 0x00426D50
// Name: public: int StudioModel::LookupSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupSequence(StudioModel *this, const char *szSequence)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int i; // esi
  int v8; // eax
  const studiohdr_t *v9; // ecx
  int v10; // eax
  mstudioseqdesc_t *v11; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return -1;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  for ( i = 0; ; ++i )
  {
    v8 = m_pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
       : m_pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( i >= v8 )
      break;
    if ( m_pStudioHdr->m_pVModel != nullptr )
    {
      v11 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i);
    }
    else
    {
      v9 = m_pStudioHdr->m_pStudioHdr;
      v10 = i;
      if ( i < 0 || i >= v9->numlocalseq )
        v10 = 0;
      v11 = (mstudioseqdesc_t *)((char *)v9 + 212 * v10 + v9->localseqindex);
    }
    if ( _V_stricmp(s1: szSequence, s2: (const char *)v11 + v11->szlabelindex) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00426E20
// Name: public: void StudioModel::StartBlending(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::StartBlending(StudioModel *this)
{
  StudioModel::SetSequence(this, iSequence: this->m_prevsequence);
}

//------------------------------------------------------------------------------
// Address: 0x00426E30
// Name: public: void StudioModel::SetBlendTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetBlendTime(StudioModel *this, float blendtime)
{
  if ( blendtime > 0.0 )
    this->m_blendtime = blendtime;
}

//------------------------------------------------------------------------------
// Address: 0x00426E50
// Name: public: float StudioModel::GetTransitionAmount(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetTransitionAmount(StudioModel *this)
{
  if ( !g_viewerSettings.blendSequenceChanges
    || this->m_blendtime <= this->m_sequencetime
    || this->m_prevsequence == this->m_sequence )
  {
    return 0.0;
  }
  else
  {
    return this->m_sequencetime / this->m_blendtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426EA0
// Name: public: enum LocalFlexController_t StudioModel::LookupFlexController(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupFlexController(StudioModel *this, char *szName)
{
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  const studiohdr_t *v7; // ecx
  int v8; // edi
  int i; // esi

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return 0;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v7 = m_pStudioHdr->m_pStudioHdr;
  v8 = 0;
  if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers <= 0 )
    return -1;
  for ( i = 0;
        _V_stricmp(
          s1: szName,
          s2: (const char *)v7 + i + v7->flexcontrollerindex + *(int *)((char *)&v7->version + i + v7->flexcontrollerindex)) != 0;
        i += 20 )
  {
    v7 = m_pStudioHdr->m_pStudioHdr;
    if ( ++v8 >= m_pStudioHdr->m_pStudioHdr->numflexcontrollers )
      return -1;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00426F50
// Name: public: float StudioModel::GetFlexController(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetFlexController(StudioModel *this, int iFlex)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  const studiohdr_t *v5; // edx
  float v6; // xmm2_4
  __int32 v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float flValue; // [esp+Ch] [ebp+8h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0.0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0.0;
  if ( iFlex < 0 )
    return 0.0;
  v5 = m_pStudioHdr->m_pStudioHdr;
  if ( iFlex >= m_pStudioHdr->m_pStudioHdr->numflexcontrollers )
    return 0.0;
  v6 = this->m_flexweight[iFlex];
  v7 = v5->flexcontrollerindex + 20 * iFlex;
  v8 = *(float *)&v5->name[v7 + 4];
  v9 = *(float *)&v5->name[v7];
  flValue = v6;
  if ( v9 != v8 )
    return (float)((float)((float)(v8 - v9) * v6) + v9);
  return flValue;
}

//------------------------------------------------------------------------------
// Address: 0x00427000
// Name: public: float StudioModel::GetFlexControllerRaw(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetFlexControllerRaw(StudioModel *this, LocalFlexController_t iFlex)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr
    && iFlex >= DUMMY_NULL_FLEX_CONTROLLER
    && iFlex < m_pStudioHdr->m_pStudioHdr->numflexcontrollers )
  {
    return this->m_flexweight[iFlex];
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427070
// Name: public: int StudioModel::GetNumLODs(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetNumLODs(StudioModel *this)
{
  const studiohwdata_t *v1; // eax

  v1 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: this->m_MDLHandle);
  return g_pStudioRender->GetNumLODs(this: g_pStudioRender, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004270A0
// Name: public: float StudioModel::GetLODSwitchValue(int)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall StudioModel::GetLODSwitchValue(StudioModel *this, int lod)
{
  const studiohwdata_t *v2; // eax

  v2 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: this->m_MDLHandle);
  return g_pStudioRender->GetLODSwitchValue(this: g_pStudioRender, a2: v2, a3: lod);
}

//------------------------------------------------------------------------------
// Address: 0x004270D0
// Name: public: void StudioModel::SetLODSwitchValue(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetLODSwitchValue(StudioModel *this, int lod, float switchValue)
{
  studiohwdata_t *v3; // eax

  v3 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: this->m_MDLHandle);
  ((void (__thiscall *)(IStudioRender *, studiohwdata_t *, int, _DWORD))g_pStudioRender->SetLODSwitchValue)(
    a1: g_pStudioRender,
    a2: v3,
    a3: lod,
    a4: LODWORD(switchValue));
}

//------------------------------------------------------------------------------
// Address: 0x00427110
// Name: public: void StudioModel::ExtractBbox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::ExtractBbox(StudioModel *this@<ecx>, int a2@<esi>, Vector *mins, Vector *maxs)
{
  int v5; // eax
  studiohdr_t *v6; // ecx
  int m_sequence; // eax
  mstudioseqdesc_t *v8; // eax
  int v10; // [esp-2Ch] [ebp-38h]
  int v11; // [esp-28h] [ebp-34h]
  int v12; // [esp-24h] [ebp-30h]
  int v13; // [esp-20h] [ebp-2Ch]
  int v14; // [esp-1Ch] [ebp-28h]
  int v15; // [esp-18h] [ebp-24h]
  int v16; // [esp-14h] [ebp-20h]
  int v17; // [esp-10h] [ebp-1Ch]
  int v18; // [esp-Ch] [ebp-18h]
  int v19; // [esp-8h] [ebp-14h]
  int v20; // [esp-4h] [ebp-10h]

  v5 = ((int (__stdcall *)(_DWORD, int, int, int, int, int, int, int, int, int, int, int, int))g_pMDLCache->GetStudioHdr)(
         a1: this->m_MDLHandle,
         a2,
         a3: v10,
         a4: v11,
         a5: v12,
         a6: v13,
         a7: v14,
         a8: v15,
         a9: v16,
         a10: v17,
         a11: v18,
         a12: v19,
         a13: v20);
  v6 = (studiohdr_t *)v5;
  if ( v5 != 0 )
  {
    if ( fsqrt(
           (float)((float)(*(float *)(v5 + 108) * *(float *)(v5 + 108))
                 + (float)(*(float *)(v5 + 104) * *(float *)(v5 + 104)))
         + (float)(*(float *)(v5 + 112) * *(float *)(v5 + 112))) == 0.0 )
    {
      if ( fsqrt(
             (float)((float)(*(float *)(v5 + 132) * *(float *)(v5 + 132))
                   + (float)(*(float *)(v5 + 136) * *(float *)(v5 + 136)))
           + (float)(*(float *)(v5 + 128) * *(float *)(v5 + 128))) == 0.0 )
      {
        m_sequence = this->m_sequence;
        if ( v6->numincludemodels != 0 )
        {
          v8 = studiohdr_t::pSeqdesc_Internal(this: v6, i: this->m_sequence);
        }
        else
        {
          if ( m_sequence < 0 || m_sequence >= v6->numlocalseq )
            m_sequence = 0;
          v8 = (mstudioseqdesc_t *)((char *)v6 + 212 * m_sequence + v6->localseqindex);
        }
        *mins = v8->bbmin;
        *maxs = v8->bbmax;
      }
      else
      {
        *mins = *(Vector *)(v5 + 128);
        *maxs = *(Vector *)(v5 + 140);
      }
    }
    else
    {
      *mins = *(Vector *)(v5 + 104);
      *maxs = *(Vector *)(v5 + 116);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004272F0
// Name: public: float StudioModel::GetFPS(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetFPS(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  int m_sequence; // edi
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  m_sequence = this->m_sequence;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_FPS(pStudioHdr: m_pStudioHdr, iSequence: m_sequence, poseParameter: this->m_poseparameter);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427360
// Name: public: float StudioModel::GetDuration(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetDuration(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_Duration(pStudioHdr: m_pStudioHdr, iSequence, poseParameter: this->m_poseparameter);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004273C0
// Name: public: float StudioModel::GetDuration(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetDuration(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  int m_sequence; // edi
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  m_sequence = this->m_sequence;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_Duration(pStudioHdr: m_pStudioHdr, iSequence: m_sequence, poseParameter: this->m_poseparameter);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427430
// Name: public: void StudioModel::GetMovement(float __near * const,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::GetMovement(StudioModel *this, float *prevcycle, Vector *vecPos, QAngle *vecAngles)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v7; // eax
  CStudioHdr *v8; // ecx
  float *v10; // edi
  float *p_m_weight; // esi
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  double v16; // st7
  float flCycleFrom; // [esp+0h] [ebp-38h]
  float flCycleTo; // [esp+4h] [ebp-34h]
  QAngle angTmp; // [esp+20h] [ebp-18h] BYREF
  Vector vecTmp; // [esp+2Ch] [ebp-Ch] BYREF
  const float *prevcyclea; // [esp+40h] [ebp+8h]
  const CStudioHdr *pStudioHdr; // [esp+44h] [ebp+Ch]
  int vecAnglesa; // [esp+48h] [ebp+10h]

  vecPos->x = 0.0;
  vecPos->y = 0.0;
  vecPos->z = 0.0;
  vecAngles->x = 0.0;
  vecAngles->y = 0.0;
  vecAngles->z = 0.0;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    pStudioHdr = this->m_pStudioHdr;
    v8 = (CStudioHdr *)pStudioHdr;
  }
  else
  {
    v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
    if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
      return;
    v8 = this->m_pStudioHdr;
    pStudioHdr = v8;
  }
  if ( v8 != nullptr )
  {
    if ( (float)(this->m_cycle - *prevcycle) < -0.5 )
      *prevcycle = *prevcycle - 1.0;
    prevcyclea = this->m_poseparameter;
    Studio_SeqMovement(
      pStudioHdr: v8,
      iSequence: this->m_sequence,
      flCycleFrom: *prevcycle,
      flCycleTo: this->m_cycle,
      poseParameter: this->m_poseparameter,
      deltaPos: vecPos,
      deltaAngles: vecAngles);
    *prevcycle = this->m_cycle;
    v10 = prevcycle + 1;
    p_m_weight = &this->m_Layer[0].m_weight;
    for ( vecAnglesa = 4; vecAnglesa != 0; --vecAnglesa )
    {
      if ( (float)(*(p_m_weight - 2) - *v10) < -0.5 )
        *v10 = *v10 - 1.0;
      if ( *p_m_weight > 0.0 )
      {
        v12 = *((_DWORD *)p_m_weight - 1);
        flCycleTo = *(p_m_weight - 2);
        flCycleFrom = *v10;
        memset(&vecTmp, 0, sizeof(vecTmp));
        memset(&angTmp, 0, sizeof(angTmp));
        if ( Studio_SeqMovement(
               pStudioHdr,
               iSequence: v12,
               flCycleFrom,
               flCycleTo,
               poseParameter: prevcyclea,
               deltaPos: &vecTmp,
               deltaAngles: &angTmp) )
        {
          v13 = 1.0 - *p_m_weight;
          v14 = (float)(vecPos->y * v13) + (float)(vecTmp.y * *p_m_weight);
          v15 = (float)(vecPos->z * v13) + (float)(vecTmp.z * *p_m_weight);
          vecPos->x = (float)(vecPos->x * v13) + (float)(vecTmp.x * *p_m_weight);
          vecPos->y = v14;
          vecPos->z = v15;
        }
      }
      v16 = *(p_m_weight - 2);
      p_m_weight += 5;
      *v10++ = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427640
// Name: public: float StudioModel::GetCurrentVelocity(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall StudioModel::GetCurrentVelocity@<st0>(StudioModel *this@<ecx>, int a2@<ebp>)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  Vector v6; // [esp+24h] [ebp-28h] BYREF
  float v7; // [esp+3Ch] [ebp-10h]
  int v8; // [esp+40h] [ebp-Ch]
  void *v9; // [esp+44h] [ebp-8h]
  void *retaddr; // [esp+4Ch] [ebp+0h]

  v8 = a2;
  v9 = retaddr;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0.0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0.0;
  }
  if ( m_pStudioHdr == nullptr
    || !Studio_SeqVelocity(
          pStudioHdr: m_pStudioHdr,
          iSequence: this->m_sequence,
          flCycle: this->m_cycle,
          poseParameter: this->m_poseparameter,
          vecVelocity: &v6) )
  {
    return 0.0;
  }
  v7 = v6.x * v6.x;
  return fsqrt((float)((float)(v6.x * v6.x) + (float)(v6.y * v6.y)) + (float)(v6.z * v6.z));
}

//------------------------------------------------------------------------------
// Address: 0x00427720
// Name: public: float StudioModel::SetController(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::SetController(StudioModel *this, int iController, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_SetController(
             pStudioHdr: m_pStudioHdr,
             iController,
             flValue,
             ctlValue: &this->m_controller[iController]);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427790
// Name: public: int StudioModel::LookupPoseParameter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupPoseParameter(StudioModel *this, const char *szName)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int v7; // esi
  const mstudioposeparamdesc_t *v8; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return 0;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v7 = 0;
  if ( CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr) <= 0 )
    return -1;
  while ( 1 )
  {
    v8 = CStudioHdr::pPoseParameter(this: m_pStudioHdr, i: v7);
    if ( _V_stricmp(s1: szName, s2: (const char *)v8 + v8->sznameindex) == 0 )
      break;
    if ( ++v7 >= CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr) )
      return -1;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00427830
// Name: public: float StudioModel::SetPoseParameter(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::SetPoseParameter(StudioModel *this, int iParameter, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_SetPoseParameter(
             pStudioHdr: m_pStudioHdr,
             iParameter,
             flValue,
             ctlValue: &this->m_poseparameter[iParameter]);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004278A0
// Name: public: float StudioModel::GetPoseParameter(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetPoseParameter(StudioModel *this, int iParameter)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    return Studio_GetPoseParameter(pStudioHdr: m_pStudioHdr, iParameter, ctlValue: this->m_poseparameter[iParameter]);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427910
// Name: public: bool StudioModel::GetPoseParameterRange(int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::GetPoseParameterRange(StudioModel *this, int iParameter, float *pflMin, float *pflMax)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  CStudioHdr *v7; // esi
  const mstudioposeparamdesc_t *v9; // eax

  *pflMin = 0.0;
  *pflMax = 0.0;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v7 = this->m_pStudioHdr;
  }
  else
  {
    v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
    v7 = this->m_pStudioHdr;
    if ( v7->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( v7 == nullptr )
    return 0;
  if ( iParameter < 0 || iParameter >= CStudioHdr::GetNumPoseParameters(this: v7) )
    return 0;
  v9 = CStudioHdr::pPoseParameter(this: v7, i: iParameter);
  *pflMin = v9->start;
  *pflMax = v9->end;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004279B0
// Name: public: int StudioModel::LookupAttachment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::LookupAttachment(StudioModel *this, const char *szName)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int v7; // esi
  const mstudioattachment_t *v8; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return -1;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  v7 = 0;
  if ( CStudioHdr::GetNumAttachments(this: m_pStudioHdr) <= 0 )
    return -1;
  while ( 1 )
  {
    v8 = CStudioHdr::pAttachment(this: m_pStudioHdr, i: v7);
    if ( _V_stricmp(s1: (const char *)v8 + v8->sznameindex, s2: szName) == 0 )
      break;
    if ( ++v7 >= CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
      return -1;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00427A50
// Name: public: int StudioModel::SetBodygroup(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetBodygroup(StudioModel *this, int iGroup, int iValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  int result; // eax
  int v7; // ecx
  int v8; // edi

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( iGroup > m_pStudioHdr->m_pStudioHdr->numbodyparts )
    return -1;
  v7 = (int)m_pStudioHdr->m_pStudioHdr + 16 * iGroup + m_pStudioHdr->m_pStudioHdr->bodypartindex;
  v8 = *(_DWORD *)(v7 + 4);
  result = iValue;
  if ( iValue >= v8 )
    return this->m_bodynum / *(_DWORD *)(v7 + 8) % v8;
  this->m_bodynum += *(_DWORD *)(v7 + 8) * (iValue - this->m_bodynum / *(_DWORD *)(v7 + 8) % v8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427AF0
// Name: public: int StudioModel::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetSkin(StudioModel *this, int iValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  int result; // eax
  const studiohdr_t *v6; // ecx

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v6 = m_pStudioHdr->m_pStudioHdr;
  result = iValue;
  if ( iValue >= v6->numskinfamilies )
    return this->m_skinnum;
  this->m_skinnum = iValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427B60
// Name: public: int StudioModel::Physics_GetBoneCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::Physics_GetBoneCount(StudioModel *this)
{
  return this->m_pPhysics->Count(this: this->m_pPhysics);
}

//------------------------------------------------------------------------------
// Address: 0x00427B70
// Name: public: char const __near * StudioModel::Physics_GetBoneName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall StudioModel::Physics_GetBoneName(StudioModel *this, int index)
{
  return (const char *)this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: index);
}

//------------------------------------------------------------------------------
// Address: 0x00427B90
// Name: public: void StudioModel::Physics_GetData(int,struct hlmvsolid_t __near *,struct constraint_ragdollparams_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::Physics_GetData(
        StudioModel *this,
        int boneIndex,
        hlmvsolid_t *psolid,
        constraint_ragdollparams_t *pConstraint)
{
  CPhysmesh *v4; // eax

  v4 = this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: boneIndex);
  if ( v4 != nullptr )
  {
    if ( psolid != nullptr )
      *psolid = v4->m_solid;
    if ( pConstraint != nullptr )
      *pConstraint = v4->m_constraint;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427BE0
// Name: public: void StudioModel::Physics_SetData(int,struct hlmvsolid_t const __near *,struct constraint_ragdollparams_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::Physics_SetData(
        StudioModel *this,
        int boneIndex,
        const hlmvsolid_t *psolid,
        const constraint_ragdollparams_t *pConstraint)
{
  CPhysmesh *v4; // eax

  v4 = this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: boneIndex);
  if ( v4 != nullptr )
  {
    if ( psolid != nullptr )
      qmemcpy(&v4->m_solid, psolid, sizeof(v4->m_solid));
    if ( pConstraint != nullptr )
      qmemcpy(&v4->m_constraint, pConstraint, sizeof(v4->m_constraint));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427C30
// Name: public: float StudioModel::Physics_GetMass(void)
// Source: json
//------------------------------------------------------------------------------
float __thiscall StudioModel::Physics_GetMass(StudioModel *this)
{
  return this->m_pPhysics->GetMass(this: this->m_pPhysics);
}

//------------------------------------------------------------------------------
// Address: 0x00427C40
// Name: public: void StudioModel::Physics_SetMass(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::Physics_SetMass(StudioModel *this, float mass)
{
  this->m_physMass = mass;
}

//------------------------------------------------------------------------------
// Address: 0x00427C60
// Name: public: char __near * StudioModel::Physics_DumpQC(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall StudioModel::Physics_DumpQC(StudioModel *this)
{
  return this->m_pPhysics->DumpQC(this: this->m_pPhysics);
}

//------------------------------------------------------------------------------
// Address: 0x00427C70
// Name: public: struct virtualmodel_t __near * studiohdr_t::GetVirtualModel(void)const
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall studiohdr_t::GetVirtualModel(studiohdr_t *this)
{
  return g_pMDLCache->GetVirtualModel(this: g_pMDLCache, a2: (unsigned __int16)this->virtualModel);
}

//------------------------------------------------------------------------------
// Address: 0x00427C90
// Name: public: unsigned char __near * studiohdr_t::GetAnimBlock(int,bool)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall studiohdr_t::GetAnimBlock(studiohdr_t *this, int i, BOOL preloadIfMissing)
{
  return g_pMDLCache->GetAnimBlock(
           this: g_pMDLCache,
           a2: (unsigned __int16)this->virtualModel,
           a3: i,
           a4: preloadIfMissing);
}

//------------------------------------------------------------------------------
// Address: 0x00427CC0
// Name: public: bool studiohdr_t::hasAnimBlockBeenPreloaded(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall studiohdr_t::hasAnimBlockBeenPreloaded(studiohdr_t *this, int i)
{
  return g_pMDLCache->HasAnimBlockBeenPreloaded(this: g_pMDLCache, a2: (unsigned __int16)this->virtualModel, a3: i);
}

//------------------------------------------------------------------------------
// Address: 0x00427CF0
// Name: public: int studiohdr_t::GetAutoplayList(unsigned short __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall studiohdr_t::GetAutoplayList(studiohdr_t *this, unsigned __int16 **pOut)
{
  return g_pMDLCache->GetAutoplayList(this: g_pMDLCache, a2: (unsigned __int16)this->virtualModel, a3: pOut);
}

//------------------------------------------------------------------------------
// Address: 0x00427D20
// Name: public: struct studiohdr_t const __near * virtualgroup_t::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall virtualgroup_t::GetStudioHdr(virtualgroup_t *this)
{
  return g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: (unsigned __int16)this->cache);
}

//------------------------------------------------------------------------------
// Address: 0x00427D40
// Name: public: virtual bool StudioModel::PostLoadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::PostLoadModel(StudioModel *this, const char *modelname)
{
  IMDLCache *v2; // edi
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v5; // eax
  int i; // edi
  CStudioHdr *v8; // eax
  const studiohdr_t *v9; // eax
  IMDLCache *cacheCriticalSection; // [esp+14h] [ebp-4h]

  v2 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && (m_pStudioHdr->m_pStudioHdr != nullptr
     || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
         CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
         (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr))
    && m_pStudioHdr != nullptr )
  {
    StudioModel::SetSequence(this, iSequence: 0);
    StudioModel::SetController(this, iController: 0, flValue: 0.0);
    StudioModel::SetController(this, iController: 1, flValue: 0.0);
    StudioModel::SetController(this, iController: 2, flValue: 0.0);
    StudioModel::SetController(this, iController: 3, flValue: 0.0);
    this->m_blendtime = 0.2;
    for ( i = 0; i < m_pStudioHdr->m_pStudioHdr->numbodyparts; ++i )
      StudioModel::SetBodygroup(this, iGroup: i, iValue: 0);
    v8 = this->m_pStudioHdr;
    if ( v8 != nullptr )
    {
      if ( v8->m_pStudioHdr != nullptr
        || (v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
            CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr),
            (v8 = this->m_pStudioHdr)->m_pStudioHdr != nullptr) )
      {
        if ( v8 != nullptr && v8->m_pStudioHdr->numskinfamilies > 0 )
          this->m_skinnum = 0;
      }
    }
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
    return 1;
  }
  else
  {
    v2->EndLock(this: v2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427EA0
// Name: public: void StudioModel::SetFlexController(enum LocalFlexController_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetFlexController(StudioModel *this, LocalFlexController_t iFlex, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  const studiohdr_t *v6; // eax
  __int32 v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float *v10; // ecx
  bool v11; // zf
  float v12; // xmm0_4
  int v13; // xmm1_4

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr != nullptr
      || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
          CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
          (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr) )
    {
      if ( m_pStudioHdr != nullptr && iFlex >= DUMMY_NULL_FLEX_CONTROLLER )
      {
        v6 = m_pStudioHdr->m_pStudioHdr;
        if ( iFlex < v6->numflexcontrollers )
        {
          v7 = v6->flexcontrollerindex + 20 * iFlex;
          v8 = *(float *)&v6->name[v7];
          v9 = *(float *)&v6->name[v7 + 4];
          v10 = (float *)((char *)&v6->id + v7);
          v11 = v8 == v9;
          v12 = flValue;
          if ( !v11 )
            v12 = (float)(flValue - v10[3]) / (float)(v9 - v10[3]);
          v13 = 0;
          if ( v12 < 0.0 || (v13 = 1065353216, v12 > 1.0) )
            v12 = *(float *)&v13;
          this->m_flexweight[iFlex] = v12;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427F60
// Name: public: void StudioModel::SetFlexControllerRaw(enum LocalFlexController_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetFlexControllerRaw(StudioModel *this, LocalFlexController_t iFlex, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  float v6; // xmm0_4

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr != nullptr
      || (v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle),
          CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr),
          (m_pStudioHdr = this->m_pStudioHdr)->m_pStudioHdr != nullptr) )
    {
      if ( m_pStudioHdr != nullptr
        && iFlex >= DUMMY_NULL_FLEX_CONTROLLER
        && iFlex < m_pStudioHdr->m_pStudioHdr->numflexcontrollers )
      {
        v6 = 0.0;
        if ( flValue >= 0.0 )
        {
          v6 = 1.0;
          if ( flValue <= 1.0 )
            v6 = flValue;
        }
        this->m_flexweight[iFlex] = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427FE0
// Name: public: float StudioModel::GetFlexController(char __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetFlexController(StudioModel *this, char *szName)
{
  int v3; // eax

  v3 = StudioModel::LookupFlexController(this, szName);
  return StudioModel::GetFlexController(this, iFlex: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00428000
// Name: public: float StudioModel::SetPoseParameter(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::SetPoseParameter(StudioModel *this, const char *szName, float flValue)
{
  int v4; // eax

  v4 = StudioModel::LookupPoseParameter(this, szName);
  return StudioModel::SetPoseParameter(this, iParameter: v4, flValue);
}

//------------------------------------------------------------------------------
// Address: 0x00428030
// Name: public: void StudioModel::FreeModel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::FreeModel(StudioModel *this, bool bReleasing)
{
  CStudioHdr *m_pStudioHdr; // edi

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    CStudioHdr::Term(this: this->m_pStudioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&m_pStudioHdr->m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&m_pStudioHdr->m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
    free(pMem: m_pStudioHdr);
    this->m_pStudioHdr = nullptr;
  }
  if ( this->m_MDLHandle != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_MDLHandle);
    this->m_MDLHandle = -1;
  }
  if ( !bReleasing && this->m_pModelName != nullptr )
  {
    free(pMem: this->m_pModelName);
    this->m_pModelName = nullptr;
  }
  this->m_SurfaceProps.m_Size = 0;
  if ( this->m_SurfaceProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SurfaceProps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SurfaceProps.m_Memory.m_pMemory);
      this->m_SurfaceProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_SurfaceProps.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SurfaceProps.m_pElements = this->m_SurfaceProps.m_Memory.m_pMemory;
  DestroyPhysics(pStudioPhysics: this->m_pPhysics);
  this->m_pPhysics = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00428120
// Name: public: static void StudioModel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl StudioModel::Shutdown()
{
  StudioModel::FreeModel(this: g_pStudioModel, bReleasing: false);
  free(pMem: StudioModel::m_AmbientLightColors);
}

//------------------------------------------------------------------------------
// Address: 0x00428140
// Name: public: static void StudioModel::ReleaseStudioModel(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl StudioModel::ReleaseStudioModel()
{
  SaveViewerSettings(filename: g_pStudioModel->m_pModelName, pModel: g_pStudioModel);
  StudioModel::FreeModel(this: g_pStudioModel, bReleasing: true);
}

//------------------------------------------------------------------------------
// Address: 0x00428170
// Name: public: bool StudioModel::LoadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::LoadModel(StudioModel *this, const char *pModelName)
{
  IMDLCache *v2; // esi
  StudioModel *v3; // edi
  const char *v4; // ebx
  const char *m_pModelName; // eax
  int v7; // eax
  char *v8; // eax
  const char *v9; // ecx
  char *v10; // edx
  char v11; // al
  unsigned __int16 v12; // ax
  CStudioHdr *m_pStudioHdr; // ebx
  CStudioHdr *v14; // ebx
  const studiohdr_t *v15; // eax
  CStudioHdr *v16; // eax
  CStudioHdr *v17; // eax
  const studiohdr_t *v18; // eax
  CStudioHdr *v19; // ebx
  const studiohdr_t *v20; // eax
  int v21; // esi
  bool v22; // zf
  mstudiohitboxset_t *v23; // esi
  CUtlString *p_m_Name; // edi
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *v25; // ebx
  const char *v26; // edi
  int v27; // esi
  unsigned __int16 v28; // ax
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *m_pMemory; // eax
  int v30; // edx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v31; // ecx
  CUtlString *v32; // ecx
  int v33; // esi
  int v34; // eax
  int v35; // esi
  const char *v36; // eax
  const studiohdr_t *v37; // ecx
  CUtlMemory<short,int> *p_m_SurfaceProps; // esi
  __int16 *v39; // edi
  int m_nAllocationCount; // eax
  __int16 *v41; // ecx
  int v42; // eax
  __int16 *v43; // edi
  int v44; // eax
  bool v45; // cl
  studiohwdata_t *v46; // eax
  studiohwdata_t *v47; // ebx
  int m_RootLOD; // ecx
  int v49; // eax
  int v50; // esi
  int v51; // edi
  int v52; // ecx
  int v53; // ecx
  int v54; // ecx
  IMDLCache *v55; // [esp-4h] [ebp-30h]
  unsigned __int16 m_MDLHandle; // [esp-4h] [ebp-30h]
  unsigned __int16 m_Tail; // [esp+Ch] [ebp-20h]
  int lodID; // [esp+10h] [ebp-1Ch]
  int lodIDa; // [esp+10h] [ebp-1Ch]
  mstudiohitboxset_t *pSrcSet; // [esp+14h] [ebp-18h]
  mstudiohitboxset_t *pSrcSeta; // [esp+14h] [ebp-18h]
  IMDLCache *cacheCriticalSection; // [esp+18h] [ebp-14h]
  int v63; // [esp+1Ch] [ebp-10h]
  int v64; // [esp+1Ch] [ebp-10h]
  CStudioHdr *pStudioHdr; // [esp+20h] [ebp-Ch]
  int i; // [esp+28h] [ebp-4h]
  int ia; // [esp+28h] [ebp-4h]

  v2 = g_pMDLCache;
  v3 = this;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  v4 = pModelName;
  if ( pModelName == nullptr )
    goto LABEL_2;
  m_pModelName = v3->m_pModelName;
  if ( m_pModelName != pModelName )
  {
    if ( m_pModelName != nullptr )
      free(pMem: v3->m_pModelName);
    v7 = _V_strlen(str: v4);
    v8 = (char *)operator new(nSize: v7 + 1);
    v3->m_pModelName = v8;
    v9 = v4;
    v10 = v8;
    do
    {
      v11 = *v9;
      *v10++ = *v9++;
    }
    while ( v11 != 0 );
  }
  v12 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: v4);
  m_pStudioHdr = v3->m_pStudioHdr;
  v3->m_MDLHandle = v12;
  if ( m_pStudioHdr != nullptr )
  {
    CStudioHdr::Term(this: m_pStudioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&m_pStudioHdr->m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&m_pStudioHdr->m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
    free(pMem: m_pStudioHdr);
  }
  v14 = (CStudioHdr *)operator new(nSize: 0x64u);
  if ( v14 != nullptr )
  {
    v55 = g_pMDLCache;
    v15 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    v16 = CStudioHdr::CStudioHdr(this: v14, pStudioHdr: v15, mdlcache: v55);
  }
  else
  {
    v16 = nullptr;
  }
  m_MDLHandle = v3->m_MDLHandle;
  v3->m_pStudioHdr = v16;
  g_pActiveModel = v3;
  v3->m_pPhysics = LoadPhysics(mdlHandle: m_MDLHandle);
  CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::RemoveAll(this: &v3->m_HitboxSets);
  v17 = v3->m_pStudioHdr;
  if ( v17 == nullptr || v17->m_pStudioHdr != nullptr )
  {
    pStudioHdr = v3->m_pStudioHdr;
    v19 = pStudioHdr;
  }
  else
  {
    v18 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v18, mdlcache: nullptr);
    v19 = v3->m_pStudioHdr->m_pStudioHdr != nullptr ? v3->m_pStudioHdr : nullptr;
    pStudioHdr = v19;
  }
  v20 = v19->m_pStudioHdr;
  lodID = 0;
  if ( v19->m_pStudioHdr->numhitboxsets > 0 )
  {
    v63 = 0;
    do
    {
      v21 = v63 + v20->hitboxsetindex;
      v22 = (const studiohdr_t *)((char *)v20 + v21) == nullptr;
      v23 = (mstudiohitboxset_t *)((char *)v20 + v21);
      pSrcSet = v23;
      if ( !v22 )
      {
        p_m_Name = &v3->m_HitboxSets.m_Memory.m_pMemory[CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::InsertBefore(
                                                          this: &v3->m_HitboxSets,
                                                          elem: v3->m_HitboxSets.m_Size)].m_Name;
        CUtlString::operator=(this: p_m_Name, src: (const char *)v23 + v23->sznameindex);
        i = 0;
        if ( v23->numhitboxes > 0 )
        {
          v25 = (CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *)&p_m_Name[1];
          pModelName = nullptr;
          while ( 1 )
          {
            v26 = &pModelName[(_DWORD)v23 + v23->hitboxindex];
            v27 = (unsigned __int16)CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal(
                                      this: v25,
                                      multilist: false);
            v28 = -1;
            if ( (_WORD)v27 != 0xFFFF )
            {
              CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::Unlink(
                this: v25,
                elem: v27);
              m_pMemory = v25->m_Memory.m_pMemory;
              v30 = v27;
              m_pMemory[v30].m_Next = -1;
              m_Tail = v25->m_Tail;
              m_pMemory[v30].m_Previous = m_Tail;
              v25->m_Tail = v27;
              if ( m_Tail == 0xFFFF )
                v25->m_Head = v27;
              else
                v25->m_Memory.m_pMemory[m_Tail].m_Next = v27;
              v31 = v25->m_Memory.m_pMemory;
              ++v25->m_ElementCount;
              v32 = &v31[v30].m_Element.m_Name;
              if ( v32 != nullptr )
                CUtlString::CUtlString(this: v32);
              v28 = v27;
            }
            v33 = v28;
            v34 = *((_DWORD *)v26 + 8);
            v35 = (int)&v25->m_Memory.m_pMemory[v33];
            v36 = v34 != 0 ? &v26[v34] : WindowName;
            CUtlString::operator=(this: (CUtlString *)v35, src: v36);
            *(_DWORD *)(v35 + 16) = *(_DWORD *)v26;
            *(_DWORD *)(v35 + 20) = *((_DWORD *)v26 + 1);
            *(float *)(v35 + 24) = *((float *)v26 + 2);
            pModelName += 68;
            *(float *)(v35 + 28) = *((float *)v26 + 3);
            *(float *)(v35 + 32) = *((float *)v26 + 4);
            *(float *)(v35 + 36) = *((float *)v26 + 5);
            *(float *)(v35 + 40) = *((float *)v26 + 6);
            *(float *)(v35 + 44) = *((float *)v26 + 7);
            *(_DWORD *)(v35 + 48) = *((_DWORD *)v26 + 8);
            *(_DWORD *)(v35 + 52) = *((_DWORD *)v26 + 9);
            *(_DWORD *)(v35 + 56) = *((_DWORD *)v26 + 10);
            *(_DWORD *)(v35 + 60) = *((_DWORD *)v26 + 11);
            *(_DWORD *)(v35 + 64) = *((_DWORD *)v26 + 12);
            *(_DWORD *)(v35 + 68) = *((_DWORD *)v26 + 13);
            *(_DWORD *)(v35 + 72) = *((_DWORD *)v26 + 14);
            *(_DWORD *)(v35 + 76) = *((_DWORD *)v26 + 15);
            *(_DWORD *)(v35 + 80) = *((_DWORD *)v26 + 16);
            *(_DWORD *)(v35 + 48) = 0;
            if ( ++i >= pSrcSet->numhitboxes )
              break;
            v23 = pSrcSet;
          }
          v19 = pStudioHdr;
        }
        v3 = this;
      }
      v20 = v19->m_pStudioHdr;
      v63 += 12;
      ++lodID;
    }
    while ( lodID < v19->m_pStudioHdr->numhitboxsets );
    v2 = cacheCriticalSection;
  }
  v37 = v19->m_pStudioHdr;
  ia = 0;
  if ( v19->m_pStudioHdr->numbones > 0 )
  {
    p_m_SurfaceProps = (CUtlMemory<short,int> *)&v3->m_SurfaceProps;
    v64 = 0;
    do
    {
      CUtlSymbol::CUtlSymbol(
        this: (CUtlSymbol *)&pModelName,
        pStr: (const char *)v37 + v64 + v37->boneindex + *(int *)((char *)&v37->hitboxsetindex + v64 + v37->boneindex));
      v39 = p_m_SurfaceProps[1].m_pMemory;
      m_nAllocationCount = p_m_SurfaceProps->m_nAllocationCount;
      if ( (int)v39 + 1 > m_nAllocationCount )
        CUtlMemory<CUtlSymbol,int>::Grow(this: p_m_SurfaceProps, num: (int)v39 - m_nAllocationCount + 1);
      ++p_m_SurfaceProps[1].m_pMemory;
      v41 = p_m_SurfaceProps->m_pMemory;
      v42 = (char *)p_m_SurfaceProps[1].m_pMemory - (char *)v39 - 1;
      p_m_SurfaceProps[1].m_nAllocationCount = (int)p_m_SurfaceProps->m_pMemory;
      if ( v42 > 0 )
        _V_memmove(dest: &v41[(_DWORD)v39 + 1], src: &v41[(_DWORD)v39], count: 2 * v42);
      v43 = &p_m_SurfaceProps->m_pMemory[(_DWORD)v39];
      if ( v43 != nullptr )
        *v43 = (__int16)pModelName;
      v37 = v19->m_pStudioHdr;
      v64 += 216;
      ++ia;
    }
    while ( ia < v19->m_pStudioHdr->numbones );
    v3 = this;
    v2 = cacheCriticalSection;
  }
  v3->m_physPreviewBone = -1;
  v44 = v3->m_MDLHandle;
  v45 = (v19->m_pStudioHdr->flags & 4) != 0;
  *(_WORD *)&v3->m_bIsTransparent = 0;
  HIBYTE(pModelName) = v45;
  v46 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: v44);
  v47 = v46;
  if ( v46 != nullptr )
  {
    m_RootLOD = v46->m_RootLOD;
    lodIDa = v46->m_RootLOD;
    if ( v46->m_RootLOD < v46->m_NumLODs )
    {
      v49 = 32 * m_RootLOD;
      pSrcSeta = (mstudiohitboxset_t *)(32 * m_RootLOD);
      do
      {
        v50 = (int)v47->m_pLODs + v49;
        v51 = 0;
        if ( *(int *)(v50 + 8) > 0 )
        {
          do
          {
            v52 = *(_DWORD *)(*(_DWORD *)(v50 + 12) + 4 * v51);
            (*(void (__thiscall **)(int))(*(_DWORD *)v52 + 76))(a1: v52);
            if ( HIBYTE(pModelName) == 0 )
            {
              v53 = *(_DWORD *)(*(_DWORD *)(v50 + 12) + 4 * v51);
              if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v53 + 68))(a1: v53) != 0 )
                this->m_bIsTransparent = true;
            }
            v54 = *(_DWORD *)(*(_DWORD *)(v50 + 12) + 4 * v51);
            if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v54 + 84))(a1: v54) != 0 )
              this->m_bHasProxy = true;
            ++v51;
          }
          while ( v51 < *(_DWORD *)(v50 + 8) );
          v49 = (int)pSrcSeta;
          m_RootLOD = lodIDa;
        }
        ++m_RootLOD;
        v49 += 32;
        lodIDa = m_RootLOD;
        pSrcSeta = (mstudiohitboxset_t *)v49;
      }
      while ( m_RootLOD < v47->m_NumLODs );
      v2 = cacheCriticalSection;
    }
    v2->EndLock(this: v2);
    return 1;
  }
  else
  {
LABEL_2:
    v2->EndLock(this: v2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428620
// Name: public: CUtlVector<struct HitboxSet_t,class CUtlMemory<struct HitboxSet_t,int>>::~CUtlVector<struct HitboxSet_t,class CUtlMemory<struct HitboxSet_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::~CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>(
        CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int> > *this)
{
  bool v2; // sf
  HitboxSet_t *m_pMemory; // eax

  CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428680
// Name: public: StudioModel::StudioModel(void)
// Source: json
//------------------------------------------------------------------------------
StudioModel *__thiscall StudioModel::StudioModel(StudioModel *this)
{
  void *v2; // eax
  matrix3x4a_t *v4; // ecx

  this->__vftable = (StudioModel_vtbl *)&StudioModel::`vftable';
  this->m_mouth.m_VoiceSources[0].m_flElapsed = 0.0;
  this->m_mouth.m_VoiceSources[0].m_pAudioSource = nullptr;
  this->m_mouth.m_VoiceSources[0].m_bIgnorePhonemes = false;
  this->m_mouth.m_VoiceSources[1].m_flElapsed = 0.0;
  this->m_mouth.m_VoiceSources[1].m_pAudioSource = nullptr;
  this->m_mouth.m_VoiceSources[1].m_bIgnorePhonemes = false;
  this->m_mouth.m_VoiceSources[2].m_flElapsed = 0.0;
  this->m_mouth.m_VoiceSources[2].m_pAudioSource = nullptr;
  this->m_mouth.m_VoiceSources[2].m_bIgnorePhonemes = false;
  this->m_mouth.m_VoiceSources[3].m_flElapsed = 0.0;
  this->m_mouth.m_VoiceSources[3].m_pAudioSource = nullptr;
  this->m_mouth.m_VoiceSources[3].m_bIgnorePhonemes = false;
  *(_DWORD *)&this->m_mouth.m_nVoiceSources = 0;
  this->m_HitboxSets.m_Memory.m_pMemory = nullptr;
  this->m_HitboxSets.m_Memory.m_nAllocationCount = 0;
  this->m_HitboxSets.m_Memory.m_nGrowSize = 0;
  this->m_HitboxSets.m_Size = 0;
  this->m_HitboxSets.m_pElements = nullptr;
  this->m_SurfaceProps.m_Memory.m_pMemory = nullptr;
  this->m_SurfaceProps.m_Memory.m_nAllocationCount = 0;
  this->m_SurfaceProps.m_Memory.m_nGrowSize = 0;
  this->m_SurfaceProps.m_Size = 0;
  this->m_SurfaceProps.m_pElements = nullptr;
  this->m_vecHeadTargets.m_Memory.m_pMemory = nullptr;
  this->m_vecHeadTargets.m_Memory.m_nAllocationCount = 0;
  this->m_vecHeadTargets.m_Memory.m_nGrowSize = 0;
  this->m_vecHeadTargets.m_Size = 0;
  this->m_vecHeadTargets.m_pElements = nullptr;
  CIKContext::CIKContext(this: &this->m_ik);
  this->m_MDLHandle = -1;
  StudioModel::ClearLookTargets(this);
  v2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12307);
  if ( v2 != nullptr )
  {
    v4 = (matrix3x4a_t *)(((unsigned int)v2 + 19) & 0xFFFFFFF0);
    LODWORD(v4[-1].m_flMatVal[2][3]) = v2;
    this->m_pBoneToWorld = v4;
  }
  else
  {
    this->m_pBoneToWorld = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428770
// Name: public: StudioModel::~StudioModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::~StudioModel(StudioModel *this)
{
  matrix3x4a_t *m_pBoneToWorld; // eax

  m_pBoneToWorld = this->m_pBoneToWorld;
  this->__vftable = (StudioModel_vtbl *)&StudioModel::`vftable';
  if ( m_pBoneToWorld != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pBoneToWorld & 0xFFFFFFFC) - 4));
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_ik.m_ikLock);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_ik.m_ikChainRule);
  this->m_ik.m_target.m_Size = 0;
  this->m_ik.m_target.m_pElements = (CIKTarget *)&this->m_ik;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_vecHeadTargets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_SurfaceProps);
  CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::~CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>(this: &this->m_HitboxSets);
  this->m_mouth.m_nVoiceSources = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004287F0
// Name: public: static void StudioModel::RestoreStudioModel(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl StudioModel::RestoreStudioModel()
{
  if ( StudioModel::LoadModel(this: g_pStudioModel, pModelName: g_pStudioModel->m_pModelName) != 0 )
    g_pStudioModel->PostLoadModel(this: g_pStudioModel, a2: g_pStudioModel->m_pModelName);
}

//------------------------------------------------------------------------------
// Address: 0x0042A660
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A7D0
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(
      (CUtlMemory<CDmeDag::TransformInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0042AE80
// Name: public: int CUtlVector<struct CDmElementDictionary::DeletionInfo_t,class CUtlMemory<struct CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::DeletionInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00432520
// Name: public: void CUtlMemory<struct ikcontextikrule_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ikcontextikrule_t,int>::Grow(CUtlMemory<ikcontextikrule_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ikcontextikrule_t *m_pMemory; // edx
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
    v7 = 132 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ikcontextikrule_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ikcontextikrule_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432DF0
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::InsertMultipleBefore(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ikcontextikrule_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 132 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00433A40
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::AddToTail(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  ikcontextikrule_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 132 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0043D630
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
        CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *this,
        int elem,
        DmElementHandle_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmElementHandle_t *m_pMemory; // ecx
  int v7; // eax
  DmElementHandle_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0043DE60
// Name: public: int CUtlVector<struct ElementPathItem_t,class CUtlMemory<struct ElementPathItem_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int>>::InsertBefore(
        CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ElementPathItem_t *m_pMemory; // ecx
  int v6; // eax
  ElementPathItem_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->hElement = DMELEMENT_HANDLE_INVALID;
    v7->hAttribute = DMATTRIBUTE_HANDLE_INVALID;
    v7->nIndex = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004418C0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::Find(enum DmElementHandle_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::Find(
        CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *this,
        const DmElementHandle_t *src)
{
  int m_Size; // edx
  int result; // eax
  DmElementHandle_t *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00441D00
// Name: public: void CUtlMemory<class VMatrix,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VMatrix,int>::Grow(CUtlMemory<VMatrix,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VMatrix *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441D90
// Name: public: void CUtlMemory<struct ActiveLayer_t<class QAngle>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
        CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ActiveLayer_t<CUtlSymbolLarge> *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ActiveLayer_t<CUtlSymbolLarge> *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (ActiveLayer_t<CUtlSymbolLarge> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004426B0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CDmaArrayBase<bool,CDmaDataInternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool *v4; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Storage.m_Memory.m_pMemory = v4;
    this->m_Storage.m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442710
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        CDmaArrayBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *this,
        int num)
{
  DmeTime_t *m_pMemory; // edx
  unsigned int v4; // eax
  DmeTime_t *v5; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Storage.m_Memory.m_pMemory = (DmeTime_t *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v4);
      goto LABEL_5;
    }
    v5 = (DmeTime_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Storage.m_Memory.m_pMemory = v5;
    this->m_Storage.m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442770
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *this,
        int num)
{
  QAngle *m_pMemory; // edx
  unsigned int v4; // eax
  QAngle *v5; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Storage.m_Memory.m_pMemory = (QAngle *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (QAngle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Storage.m_Memory.m_pMemory = v5;
    this->m_Storage.m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004427E0
// Name: public: CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *__thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>(
        CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *this,
        int growSize,
        int initSize)
{
  CDmElement **m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00442830
// Name: public: int CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolLarge *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlSymbolLarge *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->u.m_Id = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00442D60
// Name: public: void CUtlVector<class CDmeHandle<class CDmElement,2>,class CUtlMemory<class CDmeHandle<class CDmElement,2>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int>>::Purge(
        CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CDmeHandle<CDmElement,2> *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel.u.m_Id != 0 )
      CDmeElementRefHelper::Unref(
        this: &this->m_Memory.m_pMemory[i],
        hElement: this->m_Memory.m_pMemory[i].m_handle,
        handleType: HT_UNDO);
  }
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442DD0
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  CUtlBinaryBlock *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v7, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00443C10
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > *this,
        int num)
{
  Vector2D *m_pMemory; // edx
  unsigned int v4; // eax
  Vector2D *v5; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    v4 = 8 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Storage.m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Storage.m_Memory.m_pMemory = v5;
    this->m_Storage.m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443D10
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CDmaArrayBase<Quaternion,CDmaDataInternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *this,
        int num)
{
  Quaternion *m_pMemory; // edx
  unsigned int v4; // eax
  Quaternion *v5; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Storage.m_Memory.m_pMemory = (Quaternion *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v4);
      goto LABEL_5;
    }
    v5 = (Quaternion *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Storage.m_Memory.m_pMemory = v5;
    this->m_Storage.m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004492D0
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertBefore(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        float *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v7; // eax
  float *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00449340
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertBefore(int,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        bool *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v7; // eax
  bool *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004493A0
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertMultipleBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00449410
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  Color *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = 0;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004494A0
// Name: public: CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *__thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int growSize,
        int initSize)
{
  Vector2D *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004494F0
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  Vector2D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<CDmeMesh::FaceSet_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00449560
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<CDmeMesh::FaceSet_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004495D0
// Name: public: CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CUtlVector<class Vector,class CUtlMemory<class Vector,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<QAngle,CUtlMemory<QAngle,int> > *__thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CUtlVector<Vector,CUtlMemory<Vector,int>>(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int growSize,
        int initSize)
{
  QAngle *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (QAngle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449620
// Name: public: CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *__thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int growSize,
        int initSize)
{
  Quaternion *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (Quaternion *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449670
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  Vector4D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004496F0
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00449760
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        const QAngle *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v7; // eax
  QAngle *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004497E0
// Name: public: int CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00449860
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertBefore(int,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        const Quaternion *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v7; // eax
  Quaternion *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004498E0
// Name: public: CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *__thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int growSize,
        int initSize)
{
  VMatrix *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: initSize << 6);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449930
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertBefore(int,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        const VMatrix *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy((void *)&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004499A0
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: v9 << 6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00449A10
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00449A80
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlBinaryBlock *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 16 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlBinaryBlock::CUtlBinaryBlock(this: v12, growSize: 0, initSize: 0);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00449B20
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  DmeTime_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_tms = 0x80000000;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0045FC70
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::FastRemove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf
  int m_Size; // eax
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  __int64 v8; // xmm0_8
  CUtlBinaryBlock *v9; // eax

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v7 = m_Size;
      v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v7 - 1].m_Memory.m_pMemory;
      v9 = &this->m_Memory.m_pMemory[v7 - 1];
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_pMemory = v8;
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_nGrowSize = *(_QWORD *)&v9->m_Memory.m_nGrowSize;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FCF0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::Remove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 16 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0045FD60
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultiple(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int *v9; // esi
  bool v10; // sf
  bool v11; // zf
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]
  int elema; // [esp+18h] [ebp+8h]

  v5 = num;
  v6 = elem + num;
  v7 = elem + num - 1;
  v12 = elem + num;
  if ( v7 >= elem )
  {
    v8 = 16 * v7;
    elema = 16 * v7;
    v13 = num;
    do
    {
      v9 = (int *)((char *)this->m_Memory.m_pMemory + v8);
      v10 = v9[2] < 0;
      v9[3] = 0;
      if ( !v10 )
      {
        if ( *v9 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v9);
          v6 = v12;
          v8 = elema;
          *v9 = 0;
        }
        v9[1] = 0;
      }
      v8 -= 16;
      v11 = v13-- == 1;
      elema = v8;
    }
    while ( !v11 );
    v5 = num;
  }
  if ( this->m_Size - elem - v5 > 0 && v5 > 0 )
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[v6],
      count: 16 * (this->m_Size - elem - v5));
    v5 = num;
  }
  this->m_Size -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x0045FF30
// Name: public: void CUtlVector<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,class CUtlMemory<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465150
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::CopyArray(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::CopyArray(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        const float *pArray,
        int size)
{
  int v3; // ebx
  int v4; // edi
  const float *v6; // ecx
  const float *v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  char *v10; // edx
  int v11; // ebx
  double v12; // st7
  char *v13; // edx
  int v14; // [esp+14h] [ebp-4h]

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)this,
    elem: 0,
    num: size);
  v6 = pArray;
  if ( size >= 4 )
  {
    v7 = pArray + 2;
    v8 = -8 - (_DWORD)pArray;
    v9 = ((unsigned int)(size - 4) >> 2) + 1;
    v14 = 8;
    v4 = 4 * v9;
    while ( 1 )
    {
      v10 = (char *)v7 + v8;
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory] = *(v7 - 2);
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 4] = *(v7 - 1);
      v11 = v14;
      v14 += 16;
      *(float *)((char *)this->m_Memory.m_pMemory + v11) = *v7;
      v12 = v7[1];
      v13 = (char *)v7 + 4 - (_DWORD)pArray;
      v7 += 4;
      *(float *)&v13[(unsigned int)this->m_Memory.m_pMemory] = v12;
      if ( --v9 == 0 )
        break;
      v8 = -8 - (_DWORD)pArray;
    }
    v3 = size;
    v6 = pArray;
  }
  for ( ; v4 < v3; ++v4 )
    this->m_Memory.m_pMemory[v4] = v6[v4];
}

//------------------------------------------------------------------------------
// Address: 0x00465200
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::CopyArray(bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::CopyArray(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        const bool *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00465270
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CopyArray(class Vector2D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CopyArray(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        const Vector2D *pArray,
        int size)
{
  int v3; // edi
  signed int v6; // edx
  int v7; // edx
  unsigned int v8; // edi
  float *p_y; // eax
  Vector2D *m_pMemory; // ecx
  char *v11; // edx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  Vector2D *v16; // eax
  unsigned int v17; // ecx
  double x; // st7
  int i; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]
  const Vector2D *pArraya; // [esp+20h] [ebp+8h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v6 = 0;
  if ( size >= 4 )
  {
    v21 = -4 - (_DWORD)pArray;
    v7 = -20 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    v20 = 4 - (_DWORD)pArray;
    p_y = &pArray[2].y;
    pArraya = (const Vector2D *)(-20 - (_DWORD)pArray);
    i = 4 * v8;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v11 = (char *)p_y + v7;
      *(float *)&v11[(_DWORD)m_pMemory] = *(p_y - 5);
      *(float *)&v11[(_DWORD)m_pMemory + 4] = *(p_y - 4);
      v12 = (float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 8];
      *v12 = *(p_y - 3);
      v12[1] = *(p_y - 2);
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v21);
      *v13 = *(p_y - 1);
      v13[1] = *p_y;
      v14 = p_y[1];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v20);
      p_y += 8;
      --v8;
      *v15 = v14;
      v15[1] = *(p_y - 6);
      if ( v8 == 0 )
        break;
      v7 = (int)pArraya;
    }
    v3 = size;
    v6 = i;
  }
  for ( ; v6 < v3; v16[v17].y = pArray[v17].y )
  {
    v16 = this->m_Memory.m_pMemory;
    v17 = v6;
    x = pArray[v6++].x;
    v16[v17].x = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465360
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CopyArray(class Vector4D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CopyArray(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        const Vector4D *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector4D *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  float *v16; // ecx
  int v17; // edi
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
    (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this,
    elem: 0,
    num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -24 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 6);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 5);
      v11[2] = *(p_z - 4);
      v11[3] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 16];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v12[3] = p_z[1];
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 8 - (_DWORD)pArray);
      *v13 = p_z[2];
      v13[1] = p_z[3];
      v13[2] = p_z[4];
      v13[3] = p_z[5];
      v14 = p_z[6];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      p_z += 16;
      --v7;
      *v15 = v14;
      v15[1] = *(p_z - 9);
      v15[2] = *(p_z - 8);
      v15[3] = *(p_z - 7);
      if ( v7 == 0 )
        break;
      v6 = -24 - (_DWORD)pArray;
    }
    v3 = size;
    v5 = i;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = (float *)((char *)v16 + (unsigned int)this->m_Memory.m_pMemory - 8 - (_DWORD)pArray);
      *v18 = *(v16 - 2);
      v16 += 4;
      --v17;
      v18[1] = *(v16 - 5);
      v18[2] = *(v16 - 4);
      v18[3] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465490
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        const QAngle *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  QAngle *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  double v13; // st7
  float *v14; // ecx
  float *v15; // ecx
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      *(float *)&v10[(_DWORD)m_pMemory + 4] = *(p_z - 4);
      *(float *)&v10[(_DWORD)m_pMemory + 8] = *(p_z - 3);
      v11 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v11 = *(p_z - 2);
      v11[1] = *(p_z - 1);
      v11[2] = *p_z;
      v12 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v12 = p_z[1];
      v12[1] = p_z[2];
      v12[2] = p_z[3];
      v13 = p_z[4];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      p_z += 12;
      --v7;
      *v14 = v13;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = i;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v15 = &pArray[v5].z;
    v16 = v3 - v5;
    do
    {
      v17 = *(v15 - 2);
      v18 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v15 - 8 - (_DWORD)pArray);
      v15 += 3;
      --v16;
      *v18 = v17;
      v18[1] = *(v15 - 4);
      v18[2] = *(v15 - 3);
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004655A0
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  bool v2; // sf
  CUtlBinaryBlock *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll((CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466FB0
// Name: public: class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x13 )
    return (CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00467010
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00467030
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00468840
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0xF )
    return (CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004688B0
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmAttribute::GetValue<class CUtlVector<int,class CUtlMemory<int,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x10 )
    return (CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468910
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468970
// Name: public: class CUtlVector<bool,class CUtlMemory<bool,int>> const __near & CDmAttribute::GetValue<class CUtlVector<bool,class CUtlMemory<bool,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x12 )
    return (CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004689D0
// Name: public: class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Color,class CUtlMemory<class Color,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x16 )
    return (CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468A30
// Name: public: class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x17 )
    return (CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468A90
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x18 )
    return (CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468AF0
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x19 )
    return (CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468B50
// Name: public: class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1A )
    return (CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468BB0
// Name: public: class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1B )
    return (CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468C10
// Name: public: class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1C )
    return (CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468C70
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00468D80
// Name: public: class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal);
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x14 )
    return (CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0046B3B0
// Name: public: void CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::Sort(int (*)(class CUtlSymbolLarge const __near *,class CUtlSymbolLarge const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::Sort(
        CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  CUtlSymbolLarge::<unnamed_type_u> v6; // ecx
  CUtlSymbolLarge *v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6.m_Id = (int)this->m_Memory.m_pMemory[j - 1].u;
            v7 = &this->m_Memory.m_pMemory[j];
            v7[-1].u.m_Id = v7->u.m_Id;
            v7->u.m_Id = v6.m_Id;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B530
// Name: public: void CUtlMemory<class IDmFormatUpdater __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IDmFormatUpdater *,int>::Grow(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BE90
// Name: public: void CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::FastRemove(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  CDataModel::ElementIdHandlePair_t *m_pMemory; // edx
  int v4; // eax
  __int64 v5; // xmm0_8
  CDataModel::ElementIdHandlePair_t *v6; // eax
  CDataModel::ElementIdHandlePair_t *v7; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v4 = m_Size;
      v5 = *(_QWORD *)this->m_Memory.m_pMemory[v4 - 1].m_id.m_Value;
      v6 = &this->m_Memory.m_pMemory[v4 - 1];
      *(_QWORD *)m_pMemory[elem].m_id.m_Value = v5;
      v7 = &m_pMemory[elem];
      *(_QWORD *)&v7->m_id.m_Value[8] = *(_QWORD *)&v6->m_id.m_Value[8];
      v7->m_ref = v6->m_ref;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E750
// Name: public: int CUtlVector<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<CDmAttribute,21>::EntryType_t,CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,CUtlMemory<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<CDmeMesh::FaceSet_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0046E7C0
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(int,struct CDataModel::ElementIdHandlePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        const CDataModel::ElementIdHandlePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v7; // eax
  CDataModel::ElementIdHandlePair_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDataModel::ElementIdHandlePair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CDataModel::ElementIdHandlePair_t::ElementIdHandlePair_t(this: v8, that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00473320
// Name: public: class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> __near & CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *__thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(
        CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *this,
        const CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *other)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v2; // esi
  int m_Size; // edi
  int v4; // eax
  int v5; // edi
  _DWORD *v6; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v7; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  int i; // eax
  bool v12; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v2 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this;
  m_Size = other->m_Size;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll((CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: v2,
    elem: v2->m_Size,
    num: m_Size);
  if ( m_Size <= 0 )
    return (CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *)v2;
  v4 = 0;
  v16 = 0;
  v15 = m_Size;
  while ( 1 )
  {
    v5 = *(int *)((char *)&other->m_Memory.m_pMemory->m_Size + v4);
    v6 = (DmElementHandle_t **)((char *)&other->m_Memory.m_pMemory->m_Memory.m_pMemory + v4);
    v7 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)((char *)v2->m_Memory.m_pMemory + v4);
    v7[1].m_pMemory = nullptr;
    if ( v5 != 0 )
    {
      m_nAllocationCount = v7->m_nAllocationCount;
      if ( v5 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: v5 - m_nAllocationCount);
      v7[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)v7[1].m_pMemory + v5);
      m_pMemory = v7->m_pMemory;
      v10 = (int)v7[1].m_pMemory - v5;
      v7[1].m_nAllocationCount = (int)v7->m_pMemory;
      if ( v10 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: 4 * v10);
    }
    for ( i = 0; i < v5; ++i )
      v7->m_pMemory[i] = *(CUtlSymbolTable::StringPool_t **)(*v6 + 4 * i);
    v4 = v16 + 20;
    v12 = v15-- == 1;
    v16 += 20;
    if ( v12 )
      break;
    v2 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00473450
// Name: public: CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>::~CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004744E0
// Name: public: virtual class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near & CDmElementFramework::GetSortedOperators(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *__thiscall CDmElementFramework::GetSortedOperators(
        CDmElementFramework *this)
{
  return &this->m_dependencyGraph.m_operators;
}

//------------------------------------------------------------------------------
// Address: 0x00474A40
// Name: public: bool CUtlVector<class IDmNotify __near *,class CUtlMemory<class IDmNotify __near *,int>>::FindAndRemove(class IDmNotify __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
        CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *this,
        IDmNotify **src)
{
  int m_Size; // edx
  int v4; // eax
  IDmNotify **m_pMemory; // ebx
  IDmNotify **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00475B80
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolTableLargeBaseTreeEntry_t **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0047C200
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *this)
{
  bool v2; // sf
  CMDLAttachmentData *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F1B0
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(int,struct CDmElementDictionary::DmIdPair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(
        CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *this,
        int elem,
        const CDmElementDictionary::DmIdPair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::DmIdPair_t *m_pMemory; // ecx
  int v7; // eax
  CDmElementDictionary::DmIdPair_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0047FEE0
// Name: public: int CUtlVector<struct CDmElementDictionary::AttributeInfo_t,class CUtlMemory<struct CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::AttributeInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0048A600
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmElement::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(this: Attribute);
  else
    return &`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0048A700
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *,class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0048A770
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *,class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0048B170
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0048B1D0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00491550
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7E40
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004A8190
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AEC50
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmeVertexDataBase::GetPositionData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CDmeVertexDataBase::GetPositionData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[0];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x004AECA0
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmeVertexDataBase::GetNormalData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CDmeVertexDataBase::GetNormalData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[1];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x004AECF0
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmeVertexDataBase::GetTangentData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *__thiscall CDmeVertexDataBase::GetTangentData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector4D> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[2];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector4D;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector4D,CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x004AED40
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmeVertexDataBase::GetBalanceData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmeVertexDataBase::GetBalanceData(CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<float> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[7];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyFloat;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x004AED90
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmeVertexDataBase::GetVertexIndexData(enum CDmeVertexDataBase::StandardFields_t)const
// Source: json
//------------------------------------------------------------------------------
CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmeVertexDataBase::GetVertexIndexData(
        CDmeVertexDataBase *this,
        CDmeVertexDataBase::StandardFields_t fieldId)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[fieldId];
  if ( v2 < 0 || v2 >= this->m_FieldInfo.m_Size )
    return (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&s_EmptyInt;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x004AF0A0
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmeVertexDataBase::FindVertexIndicesFromDataIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<int,CUtlMemory<int,int> > *__thiscall CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nDataIndex)
{
  CDmeVertexDataBase::FieldInfo_t *v4; // esi
  bool v5; // zf
  const CDmAttribute *m_pIndexData; // edi
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_InverseMap; // ebx
  int v8; // edi
  int v9; // edx
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v11; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v14; // eax
  int *v15; // edi
  CDmrArrayConst<int> array; // [esp+0h] [ebp-14h] BYREF
  CDmeVertexDataBase::FieldInfo_t *info; // [esp+8h] [ebp-Ch]
  CDmrGenericArray vertexArray; // [esp+Ch] [ebp-8h] BYREF
  int nCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  if ( nFieldIndex < 0 )
    return &s_EmptyInt;
  v4 = &this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex];
  v5 = !v4->m_bInverseMapDirty;
  info = v4;
  if ( !v5 )
  {
    m_pIndexData = v4->m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: &array,
      pAttribute: m_pIndexData);
    CDmrGenericArray::CDmrGenericArray(this: &vertexArray, pAttribute: v4->m_pVertexData);
    p_m_InverseMap = &v4->m_InverseMap;
    v8 = CDmrGenericArrayConst::Count(this: &vertexArray);
    nCount = array.m_pStorage->m_Size;
    CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v4->m_InverseMap);
    CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v4->m_InverseMap);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v4->m_InverseMap,
      elem: v4->m_InverseMap.m_Size,
      num: v8);
    v9 = 0;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        m_Size = p_m_InverseMap->m_Memory.m_pMemory[array.m_pStorage->m_Memory.m_pMemory[v9]].m_Size;
        v11 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&p_m_InverseMap->m_Memory.m_pMemory[array.m_pStorage->m_Memory.m_pMemory[v9]];
        m_nAllocationCount = v11->m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v11, num: m_Size - m_nAllocationCount + 1);
          v9 = i;
        }
        ++v11[1].m_pMemory;
        m_pMemory = v11->m_pMemory;
        v14 = (int)v11[1].m_pMemory - m_Size - 1;
        v11[1].m_nAllocationCount = (int)v11->m_pMemory;
        if ( v14 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
          v9 = i;
        }
        v15 = (int *)&v11->m_pMemory[m_Size];
        if ( v15 != nullptr )
          *v15 = v9;
        i = ++v9;
      }
      while ( v9 < nCount );
      v4 = info;
    }
    v4->m_bInverseMapDirty = false;
  }
  return &v4->m_InverseMap.m_Memory.m_pMemory[nDataIndex];
}

//------------------------------------------------------------------------------
// Address: 0x004AF1C0
// Name: public: int CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  int v6; // eax
  CDmeVertexDataBase::FieldInfo_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<matrix3x4_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_Name);
    v7->m_InverseMap.m_Memory.m_pMemory = nullptr;
    v7->m_InverseMap.m_Memory.m_nAllocationCount = 0;
    v7->m_InverseMap.m_Memory.m_nGrowSize = 0;
    v7->m_InverseMap.m_Size = 0;
    v7->m_InverseMap.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004AF240
// Name: public: void CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this)
{
  int v1; // eax
  int v2; // eax
  char *v3; // edi
  void *v4; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *v5; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 48 * v1;
    for ( j = v2; ; v2 = j )
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)(v3 + 24));
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( *((_DWORD *)v3 + 6) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 6));
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      v4 = *((void **)v3 + 6);
      *((_DWORD *)v3 + 10) = v4;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      j -= 48;
      this = v5;
      if ( --i < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AF680
// Name: public: CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::~CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::~CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // eax

  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3380
// Name: public: int CUtlVector<struct CDmeMesh::FaceSet_t,class CUtlMemory<struct CDmeMesh::FaceSet_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeMesh::FaceSet_t,CUtlMemory<CDmeMesh::FaceSet_t,int>>::InsertMultipleBefore(
        CUtlVector<CDmeMesh::FaceSet_t,CUtlMemory<CDmeMesh::FaceSet_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeMesh::FaceSet_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CDmeMesh::FaceSet_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_bBuilt = false;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004B6A90
// Name: public: int CUtlVector<struct matrix3x4_t,class CUtlMemory<struct matrix3x4_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
        CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  matrix3x4_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<matrix3x4_t,int>::Grow(
      (CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 48 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004BAA90
// Name: public: void CUtlMemory<struct matrix3x4_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<matrix3x4_t,int>::Grow(CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeVertexDataBase::FieldInfo_t *)_g_pMemAlloc->Realloc_2(
                                                             this: _g_pMemAlloc,
                                                             a2: m_pMemory,
                                                             a3: v7);
    else
      this->m_pMemory = (CDmeVertexDataBase::FieldInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB4C0
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertMultipleBefore(int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num,
        const int *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int *v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *v13 = pToInsert[v11];
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x004BBAE0
// Name: public: void CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CDmeCombinationOperator::RawControlInfo_t *v3; // esi
  CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBB50
// Name: public: int CUtlVector<struct CDmeCombinationOperator::CombinationOperation_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationOperation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::InsertBefore(
        CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeCombinationOperator::CombinationOperation_t *m_pMemory; // ecx
  int v6; // eax
  CDmeCombinationOperator::CombinationOperation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_ControlIndices.m_Memory.m_pMemory = nullptr;
    v7->m_ControlIndices.m_Memory.m_nAllocationCount = 0;
    v7->m_ControlIndices.m_Memory.m_nGrowSize = 0;
    v7->m_ControlIndices.m_Size = 0;
    v7->m_ControlIndices.m_pElements = nullptr;
    v7->m_DominatorIndices.m_Memory.m_pMemory = nullptr;
    v7->m_DominatorIndices.m_Memory.m_nAllocationCount = 0;
    v7->m_DominatorIndices.m_Memory.m_nGrowSize = 0;
    v7->m_DominatorIndices.m_Size = 0;
    v7->m_DominatorIndices.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004BBBD0
// Name: public: void CUtlVector<struct CDmeCombinationOperator::CombinationOperation_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    v7 = 44 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 9) = 0;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( *((_DWORD *)v3 + 6) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 6));
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      v4 = *((void **)v3 + 6);
      *((_DWORD *)v3 + 10) = v4;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v5 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v5;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 44;
      v7 -= 44;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBCC0
// Name: public: CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::RawControlInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBD20
// Name: public: void CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 40 * v1;
    v7 = 40 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      v4 = *((void **)v3 + 5);
      *((_DWORD *)v3 + 9) = v4;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v5 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 40;
      v7 -= 40;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BC0E0
// Name: public: CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::DominatorInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BC400
// Name: public: int CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::InsertBefore(
        CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeCombinationOperator::CombinationInfo_t *m_pMemory; // ecx
  int v6; // eax
  CDmeCombinationOperator::CombinationInfo_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Outputs.m_Memory.m_pMemory = nullptr;
    v7->m_Outputs.m_Memory.m_nAllocationCount = 0;
    v7->m_Outputs.m_Memory.m_nGrowSize = 0;
    v7->m_Outputs.m_Size = 0;
    v7->m_Outputs.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004BCA90
// Name: public: void CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CDmeCombinationOperator::CombinationInfo_t *v3; // esi
  bool v4; // sf
  CDmeCombinationOperator::CombinationOperation_t *m_pMemory; // eax
  CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(this: &v3->m_Outputs);
      if ( v3->m_Outputs.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Outputs.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Outputs.m_Memory.m_pMemory);
          v3->m_Outputs.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Outputs.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Outputs.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Outputs.m_Memory.m_pMemory;
      v3->m_Outputs.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Outputs.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Outputs.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BCB30
// Name: public: CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::CombinationInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5400
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  __int16 *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (__int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (__int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5490
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class QAngle>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: m_pMemory,
                                                                                  a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5540
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class Vector2D>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: m_pMemory,
                                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C55F0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class CUtlSymbolLarge>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short> *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<CUtlSymbolLarge>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C56C0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class Vector4D>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector4D>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *m_pMemory; // edx
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
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: m_pMemory,
                                                                                      a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5770
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct ActiveLayer_t<float> __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<float> *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C5820
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class VMatrix>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *m_pMemory; // edx
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
    v7 = 88 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: m_pMemory,
                                                                                   a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EF250
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int,class DmeTime_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num,
        const DmeTime_t *pToInsert)
{
  int v4; // esi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  DmeTime_t *v13; // eax
  int v14; // eax
  int v15; // edx
  DmeTime_t *v16; // ecx

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v11);
  if ( pToInsert != nullptr )
  {
    v14 = 0;
    if ( num > 0 )
    {
      v15 = elem;
      do
      {
        v16 = &this->m_Memory.m_pMemory[v15];
        if ( v16 != nullptr )
        {
          v16->m_tms = (int)pToInsert[v14];
          v10 = elem;
        }
        ++v14;
        ++v15;
      }
      while ( v14 < num );
    }
  }
  else if ( num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        v13->m_tms = 0x80000000;
      ++v12;
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0057C340
// Name: public: void CUtlMemory<class CMDLAttachmentData,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMDLAttachmentData,int>::Grow(CUtlMemory<CMDLAttachmentData,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMDLAttachmentData *m_pMemory; // edx
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
    v7 = 52 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMDLAttachmentData *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CMDLAttachmentData *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057C5A0
// Name: public: int CUtlVector<class CMDLAttachmentData,class CUtlMemory<class CMDLAttachmentData,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int>>::InsertMultipleBefore(
        CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMDLAttachmentData *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMDLAttachmentData,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 52 * v9);
  return elem;
}

} // namespace hlmv
