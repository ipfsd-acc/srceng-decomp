// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particles_new.cpp
// Functions: 43
// ============================================================

#include "game\client\particles_new.h"

//------------------------------------------------------------------------------
// Address: 0x10137290
// Name: private: void CNewParticleEffect::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::AddRef(CNewParticleEffect *this)
{
  ++this->m_RefCount;
}

//------------------------------------------------------------------------------
// Address: 0x101372A0
// Name: public: virtual void CNewParticleEffect::NotifyRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::NotifyRemove(CNewParticleEffect *this)
{
  if ( (*((_BYTE *)this + 944) & 0x40) != 0 )
    ((void (__thiscall *)(CNewParticleEffect *, int))this->dtr_IParticleEffect)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101372C0
// Name: public: virtual int CNewParticleEffect::GetRenderFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNewParticleEffect::GetRenderFlags(CNewParticleEffect *this)
{
  IClientRenderable *v1; // esi
  int v2; // edi

  v1 = &this->IClientRenderable;
  v2 = 0;
  if ( CParticleCollection::UsesPowerOfTwoFrameBufferTexture(
         this: (CParticleCollection *)&this->IClientRenderable,
         bThisFrame: true) != 0 )
    v2 = 5;
  if ( CParticleCollection::UsesFullFrameBufferTexture(this: (CParticleCollection *)v1, bThisFrame: true) != 0 )
    return v2 | 2;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101372F0
// Name: public: void CNewParticleEffect::SetDormant(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetDormant(CNewParticleEffect *this, bool bDormant)
{
  CParticleCollection::SetDormant(this: &this->CParticleCollection, bDormant);
}

//------------------------------------------------------------------------------
// Address: 0x10137300
// Name: public: virtual bool CNewParticleEffect::ShouldDrawForSplitScreenUser(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNewParticleEffect::ShouldDrawForSplitScreenUser(CNewParticleEffect *this, int nSlot)
{
  float y; // eax

  y = this->m_LastMax.y;
  return y == NAN || LODWORD(y) == nSlot;
}

//------------------------------------------------------------------------------
// Address: 0x10137320
// Name: DumpParticleStats_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpParticleStats_f()
{
  CParticleSystemMgr::DumpProfileInformation(this: g_pParticleSystemMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10137330
// Name: public: bool CParticleCollection::ReadsControlPoint(int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CParticleCollection::ReadsControlPoint(CParticleCollection *this, char nPoint)
{
  return (this->m_nControlPointReadMask & (1LL << nPoint)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10137370
// Name: public: void CParticleCollection::SetControlPoint(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleCollection::SetControlPoint(CParticleCollection *this, int nWhichPoint, const Vector *v)
{
  int m_nNumControlPointsAllocated; // eax
  int v4; // eax
  int m_nHighestCP; // eax
  CParticleCollection *i; // esi

  m_nNumControlPointsAllocated = this->m_nNumControlPointsAllocated;
  if ( nWhichPoint < m_nNumControlPointsAllocated )
  {
    v4 = m_nNumControlPointsAllocated - 1;
    if ( nWhichPoint < v4 )
      v4 = nWhichPoint;
    this->m_pCPInfo[v4].m_ControlPoint.m_Position = *v;
    m_nHighestCP = this->m_nHighestCP;
    if ( m_nHighestCP <= nWhichPoint )
      m_nHighestCP = nWhichPoint;
    this->m_nHighestCP = m_nHighestCP;
  }
  for ( i = this->m_Children.m_pHead; i != nullptr; i = i->m_pNext )
    CParticleCollection::SetControlPoint(this: i, nWhichPoint, v);
}

//------------------------------------------------------------------------------
// Address: 0x101373E0
// Name: public: void CParticleCollection::SetControlPointObject(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleCollection::SetControlPointObject(CParticleCollection *this, int nWhichPoint, void *pObject)
{
  int m_nNumControlPointsAllocated; // eax
  int v4; // eax
  int m_nHighestCP; // eax
  CParticleCollection *i; // esi

  m_nNumControlPointsAllocated = this->m_nNumControlPointsAllocated;
  if ( nWhichPoint < m_nNumControlPointsAllocated )
  {
    v4 = m_nNumControlPointsAllocated - 1;
    if ( nWhichPoint < v4 )
      v4 = nWhichPoint;
    this->m_pCPInfo[v4].m_ControlPoint.m_pObject = pObject;
    m_nHighestCP = this->m_nHighestCP;
    if ( m_nHighestCP <= nWhichPoint )
      m_nHighestCP = nWhichPoint;
    this->m_nHighestCP = m_nHighestCP;
  }
  for ( i = this->m_Children.m_pHead; i != nullptr; i = i->m_pNext )
    CParticleCollection::SetControlPointObject(this: i, nWhichPoint, pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10137440
// Name: public: void CParticleCollection::SetControlPointOrientation(int,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleCollection::SetControlPointOrientation(
        CParticleCollection *this,
        int nWhichPoint,
        const Vector *forward,
        const Vector *right,
        const Vector *up)
{
  int m_nNumControlPointsAllocated; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  const Vector *v9; // edx
  int m_nHighestCP; // eax
  CParticleCollection *m_pHead; // esi

  m_nNumControlPointsAllocated = this->m_nNumControlPointsAllocated;
  if ( nWhichPoint >= m_nNumControlPointsAllocated )
  {
    v9 = right;
  }
  else
  {
    v6 = m_nNumControlPointsAllocated - 1;
    if ( nWhichPoint < v6 )
      v6 = nWhichPoint;
    this->m_pCPInfo[v6].m_ControlPoint.m_ForwardVector = *forward;
    v7 = this->m_nNumControlPointsAllocated - 1;
    if ( nWhichPoint < v7 )
      v7 = nWhichPoint;
    this->m_pCPInfo[v7].m_ControlPoint.m_UpVector = *up;
    v8 = this->m_nNumControlPointsAllocated - 1;
    if ( nWhichPoint < v8 )
      v8 = nWhichPoint;
    v9 = right;
    this->m_pCPInfo[v8].m_ControlPoint.m_RightVector = *right;
    m_nHighestCP = this->m_nHighestCP;
    if ( m_nHighestCP <= nWhichPoint )
      m_nHighestCP = nWhichPoint;
    this->m_nHighestCP = m_nHighestCP;
  }
  m_pHead = this->m_Children.m_pHead;
  if ( m_pHead != nullptr )
  {
    while ( 1 )
    {
      CParticleCollection::SetControlPointOrientation(this: m_pHead, nWhichPoint, forward, right: v9, up);
      m_pHead = m_pHead->m_pNext;
      if ( m_pHead == nullptr )
        break;
      v9 = right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137520
// Name: public: void CParticleCollection::SetControlPointForwardVector(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleCollection::SetControlPointForwardVector(
        CParticleCollection *this,
        int nWhichPoint,
        const Vector *v)
{
  int m_nNumControlPointsAllocated; // eax
  int v4; // eax
  int m_nHighestCP; // eax
  CParticleCollection *i; // esi

  m_nNumControlPointsAllocated = this->m_nNumControlPointsAllocated;
  if ( nWhichPoint < m_nNumControlPointsAllocated )
  {
    v4 = m_nNumControlPointsAllocated - 1;
    if ( nWhichPoint < v4 )
      v4 = nWhichPoint;
    this->m_pCPInfo[v4].m_ControlPoint.m_ForwardVector = *v;
    m_nHighestCP = this->m_nHighestCP;
    if ( m_nHighestCP <= nWhichPoint )
      m_nHighestCP = nWhichPoint;
    this->m_nHighestCP = m_nHighestCP;
  }
  for ( i = this->m_Children.m_pHead; i != nullptr; i = i->m_pNext )
    CParticleCollection::SetControlPointForwardVector(this: i, nWhichPoint, v);
}

//------------------------------------------------------------------------------
// Address: 0x10137590
// Name: public: static void CNewParticleEffect::RemoveParticleEffect(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CNewParticleEffect::RemoveParticleEffect(int nPrecacheIndex)
{
  CParticleSystemDefinition *PrecachedParticleSystem; // eax
  CParticleCollection *i; // eax

  PrecachedParticleSystem = CParticleSystemMgr::FindPrecachedParticleSystem(this: g_pParticleSystemMgr, nPrecacheIndex);
  if ( PrecachedParticleSystem != nullptr )
  {
    for ( i = PrecachedParticleSystem->m_pFirstCollection; i != nullptr; i = i->m_pNextDef )
    {
      if ( i != (CParticleCollection *)16 )
        i[1].m_fl4CurTime.m128_i8[0] |= 2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101375D0
// Name: private: void CNewParticleEffect::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::Release(CNewParticleEffect *this)
{
  bool v2; // zf

  v2 = this->m_RefCount-- == 1;
  if ( v2
    && (*((_BYTE *)this + 944) & 0x40) != 0
    && CParticleCollection::IsFinished(this: &this->CParticleCollection) != 0 )
  {
    *((_BYTE *)this + 944) |= 2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137600
// Name: public: void CNewParticleEffect::StopEmission(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::StopEmission(
        CNewParticleEffect *this,
        BOOL bInfiniteOnly,
        bool bRemoveAllParticles,
        bool bWakeOnStop,
        bool bPlayEndCap)
{
  KeyValues *v6; // eax
  KeyValues *v7; // esi

  if ( (*((_BYTE *)this + 945) & 1) != 0
    && this->m_nToolParticleEffectId != -1
    && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "ParticleSystem_StopEmission");
    else
      v7 = nullptr;
    state_5.m_nParticleSystemId = this->m_nToolParticleEffectId;
    state_5.m_flTime = *(float *)(gpGlobals.m_Index + 12);
    state_5.m_bInfiniteOnly = bInfiniteOnly;
    KeyValues::SetPtr(this: v7, keyName: "state", value: &state_5);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v7);
  }
  CParticleCollection::StopEmission(
    this: &this->CParticleCollection,
    bInfiniteOnly,
    bRemoveAllParticles,
    bWakeOnStop,
    bPlayEndCap);
}

//------------------------------------------------------------------------------
// Address: 0x101376B0
// Name: public: bool CNewParticleEffect::RecalculateBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CNewParticleEffect::RecalculateBoundingBox@<al>(CNewParticleEffect *this@<ecx>, float a2@<ebp>)
{
  const Vector *v3; // eax
  double z; // st7

  CParticleCollection::BloatBoundsUsingControlPoint(this: &this->CParticleCollection, a2);
  if ( this->m_bBoundsValid )
    return 1;
  v3 = this->GetRenderOrigin(this: &this->IClientRenderable);
  this->m_MinBounds.x = v3->x;
  this->m_MinBounds.y = v3->y;
  z = v3->z;
  this->m_MinBounds.z = z;
  this->m_MaxBounds.x = this->m_MinBounds.x;
  this->m_MaxBounds.y = this->m_MinBounds.y;
  this->m_MaxBounds.z = this->m_MinBounds.z;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10137720
// Name: public: virtual void CNewParticleEffect::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::GetRenderBounds(CNewParticleEffect *this, Vector *mins, Vector *maxs)
{
  double x; // st7
  float *v5; // eax
  float *v6; // eax

  if ( LOBYTE(this->m_Center.z) != 0 )
  {
    v5 = (float *)((int (__thiscall *)(CNewParticleEffect *))this->Update)(a1: this);
    mins->x = *(float *)&this->m_pRenderable - *v5;
    mins->y = *(float *)&this->m_bBoundsValid - v5[1];
    mins->z = this->m_MinBounds.x - v5[2];
    v6 = (float *)((int (__thiscall *)(CNewParticleEffect *))this->Update)(a1: this);
    maxs->x = this->m_MinBounds.y - *v6;
    maxs->y = this->m_MinBounds.z - v6[1];
    maxs->z = this->m_MaxBounds.x - v6[2];
  }
  else
  {
    mins->x = vec3_origin.x;
    x = mins->x;
    mins->y = vec3_origin.y;
    mins->z = vec3_origin.z;
    maxs->x = x;
    maxs->y = mins->y;
    maxs->z = mins->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137800
// Name: public: void CNewParticleEffect::DetectChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::DetectChanges(CNewParticleEffect *this)
{
  int m_hRenderHandle; // eax

  m_hRenderHandle = this->m_hRenderHandle;
  if ( (_WORD)m_hRenderHandle != 0xFFFF )
  {
    g_pClientLeafSystem->EnableRendering(this: g_pClientLeafSystem, a2: m_hRenderHandle, a3: this->m_bBoundsValid);
    if ( this->m_bBoundsValid )
    {
      if ( this->m_LastMin.x != this->m_MinBounds.x
        || this->m_LastMin.y != this->m_MinBounds.y
        || this->m_LastMin.z != this->m_MinBounds.z
        || this->m_LastMax.x != this->m_MaxBounds.x
        || this->m_LastMax.y != this->m_MaxBounds.y
        || this->m_LastMax.z != this->m_MaxBounds.z )
      {
        ((void (__stdcall *)(_DWORD))g_pClientLeafSystem->RenderableChanged)(a1: this->m_hRenderHandle);
        this->m_LastMin.x = this->m_MinBounds.x;
        this->m_LastMin.y = this->m_MinBounds.y;
        this->m_LastMin.z = this->m_MinBounds.z;
        this->m_LastMax.x = this->m_MaxBounds.x;
        this->m_LastMax.y = this->m_MaxBounds.y;
        this->m_LastMax.z = this->m_MaxBounds.z;
      }
    }
    else
    {
      this->m_LastMin.x = -3.4028235e38;
      this->m_LastMin.y = -3.4028235e38;
      this->m_LastMin.z = -3.4028235e38;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137940
// Name: public: void CNewParticleEffect::SetDrawOnlyForSplitScreenUser(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetDrawOnlyForSplitScreenUser(CNewParticleEffect *this, int nSlot)
{
  if ( nSlot != this->m_nSplitScreenUser )
    this->m_nSplitScreenUser = nSlot;
}

//------------------------------------------------------------------------------
// Address: 0x10137960
// Name: public: virtual bool CNewParticleEffect::SetupBones(class matrix3x4a_t __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNewParticleEffect::SetupBones@<al>(
        CNewParticleEffect *this@<ecx>,
        unsigned int a2@<ebp>,
        matrix3x4a_t *pBoneToWorldOut,
        int nMaxBones,
        int boneMask,
        float currentTime)
{
  _DWORD v7[3]; // [esp-Ch] [ebp-3Ch] BYREF
  matrix3x4a_t mat; // [esp+0h] [ebp-30h]
  float retaddr; // [esp+30h] [ebp+0h]

  mat.m_flMatVal[2][2] = retaddr;
  mat.m_flMatVal[0][0] = vec3_origin.x;
  v7[0] = 0;
  v7[2] = 0;
  *(_QWORD *)&mat.m_flMatVal[0][1] = 3212836864LL;
  mat.m_flMatVal[0][3] = 0.0;
  *(_QWORD *)&mat.m_flMatVal[1][2] = 0x3F80000000000000LL;
  v7[1] = 1065353216;
  *(_QWORD *)&mat.m_flMatVal[1][0] = LODWORD(vec3_origin.y);
  *(_QWORD *)&mat.m_flMatVal[2][0] = __PAIR64__(a2, LODWORD(vec3_origin.z));
  ConcatTransforms(
    in1: (const matrix3x4_t *)(&this->m_RefCount + 2),
    in2: (const matrix3x4_t *)v7,
    out: pBoneToWorldOut);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10137A10
// Name: cl_particles_dumplist
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_particles_dumplist(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    CParticleSystemMgr::DumpParticleList(this: g_pParticleSystemMgr, pNameSubstring: args->m_ppArgv[1]);
  else
    CParticleSystemMgr::DumpParticleList(this: g_pParticleSystemMgr, pNameSubstring: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10137A40
// Name: public: virtual CNewParticleEffect::~CNewParticleEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::~CNewParticleEffect(CNewParticleEffect *this)
{
  bool v2; // zf
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // eax
  CUtlReference<CNewParticleEffect> *m_pHead; // eax
  CUtlReference<CNewParticleEffect> *m_pNext; // ecx

  v2 = (*((_BYTE *)this + 945) & 1) == 0;
  this->IParticleEffect::__vftable = (CNewParticleEffect_vtbl *)&CNewParticleEffect::`vftable';
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CDefaultClientRenderable_vtbl *)&CNewParticleEffect::`vftable'{for `IClientUnknown'};
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CNewParticleEffect::`vftable'{for `IClientRenderable'};
  if ( !v2 && this->m_nToolParticleEffectId != -1 && clienttools->IsInRecordingMode(this: clienttools) )
  {
    state_6.m_nParticleSystemId = this->m_nToolParticleEffectId;
    state_6.m_flTime = *(float *)(gpGlobals.m_Index + 12);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "ParticleSystem_Destroy");
    else
      v4 = nullptr;
    KeyValues::SetPtr(this: v4, keyName: "state", value: &state_6);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v4);
    this->m_nToolParticleEffectId = -1;
  }
  *((_BYTE *)this + 944) &= ~0x40u;
  m_Index = this->m_hOwner.m_Index;
  if ( m_Index != -1 )
  {
    v6 = (unsigned __int16)m_Index;
    v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v8 = HIWORD(m_Index);
    if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
    {
      v9 = v6;
      v2 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
      v10 = &g_pEntityList->m_EntPtrArray[v9];
      if ( v2 )
        m_pEntity = v10->m_pEntity;
      else
        m_pEntity = nullptr;
      CParticleProperty::OnParticleSystemDeleted(this: (CParticleProperty *)&m_pEntity[218], pEffect: this);
    }
  }
  m_pHead = this->m_References.m_pHead;
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_References.m_pHead = nullptr;
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CDefaultClientRenderable_vtbl *)&IHandleEntity::`vftable';
  CParticleCollection::~CParticleCollection(this: &this->CParticleCollection);
  this->IParticleEffect::__vftable = (CNewParticleEffect_vtbl *)&IParticleEffect::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10137B90
// Name: public: virtual bool CNewParticleEffect::ShouldSimulate(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNewParticleEffect::ShouldSimulate(CNewParticleEffect *this)
{
  return *((_BYTE *)this + 944) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x10137BA0
// Name: public: virtual void CNewParticleEffect::SetShouldSimulate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetShouldSimulate(CNewParticleEffect *this, bool bSim)
{
  *((_BYTE *)this + 944) = (bSim << 7) | *((_BYTE *)this + 944) & 0x7F;
}

//------------------------------------------------------------------------------
// Address: 0x10137BC0
// Name: public: virtual class Vector const __near & CNewParticleEffect::GetSortOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CNewParticleEffect::GetSortOrigin(CNewParticleEffect *this)
{
  return &this->m_vSortOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10137BD0
// Name: public: virtual struct matrix3x4_t const __near & CNewParticleEffect::RenderableToWorldTransform(void)
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall CNewParticleEffect::RenderableToWorldTransform(CNewParticleEffect *this)
{
  const Vector *v2; // eax

  if ( (`CNewParticleEffect::RenderableToWorldTransform'::`2'::`local static guard' & 1) == 0 )
    `CNewParticleEffect::RenderableToWorldTransform'::`2'::`local static guard' |= 1u;
  SetIdentityMatrix(matrix: &`CNewParticleEffect::RenderableToWorldTransform'::`2'::mat);
  v2 = (const Vector *)((int (__thiscall *)(CNewParticleEffect *))this->Update)(a1: this);
  MatrixSetColumn(in: v2, column: 3, out: &`CNewParticleEffect::RenderableToWorldTransform'::`2'::mat);
  return &`CNewParticleEffect::RenderableToWorldTransform'::`2'::mat;
}

//------------------------------------------------------------------------------
// Address: 0x10137C20
// Name: public: virtual class Vector const __near & CNewParticleEffect::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CNewParticleEffect::GetRenderOrigin(CNewParticleEffect *this)
{
  return (const Vector *)((char *)this + 944);
}

//------------------------------------------------------------------------------
// Address: 0x10137C30
// Name: public: virtual char const __near * CNewParticleEffect::GetEffectName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNewParticleEffect::GetEffectName(CNewParticleEffect *this)
{
  return CParticleCollection::GetName(this: &this->CParticleCollection);
}

//------------------------------------------------------------------------------
// Address: 0x10137C40
// Name: public: void CNewParticleEffect::SetControlPoint(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetControlPoint(CNewParticleEffect *this, int nWhichPoint, const Vector *v)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx

  if ( (*((_BYTE *)this + 945) & 1) != 0
    && this->m_nToolParticleEffectId != -1
    && clienttools->IsInRecordingMode(this: clienttools) )
  {
    if ( (_S6_34 & 1) == 0 )
      _S6_34 |= 1u;
    state_7.m_nParticleSystemId = this->m_nToolParticleEffectId;
    state_7.m_flTime = *(float *)(gpGlobals.m_Index + 12);
    state_7.m_nControlPoint = nWhichPoint;
    state_7.m_vecPosition = *v;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ParticleSystem_SetControlPointPosition");
    else
      v5 = nullptr;
    KeyValues::SetPtr(this: v5, keyName: "state", value: &state_7);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v5);
  }
  CParticleCollection::SetControlPoint(this: &this->CParticleCollection, nWhichPoint, v);
}

//------------------------------------------------------------------------------
// Address: 0x10137D30
// Name: private: void CNewParticleEffect::RecordCreation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::RecordCreation(CNewParticleEffect *this)
{
  CParticleMgr *v2; // eax
  int m_nToolParticleEffectId; // ecx
  unsigned int m_Index; // esi
  int v5; // eax
  CEntInfo *v6; // ecx
  unsigned int v7; // esi
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi

  if ( this->m_pDef.m_pObject != nullptr && clienttools->IsInRecordingMode(this: clienttools) )
  {
    *((_BYTE *)this + 945) |= 1u;
    v2 = ParticleMgr();
    m_nToolParticleEffectId = v2->m_nToolParticleEffectId;
    v2->m_nToolParticleEffectId = m_nToolParticleEffectId + 1;
    this->m_nToolParticleEffectId = m_nToolParticleEffectId;
    state_8.m_nParticleSystemId = m_nToolParticleEffectId;
    state_8.m_flTime = *(float *)(gpGlobals.m_Index + 12);
    state_8.m_pName = CParticleSystemDefinition::GetName(this: this->m_pDef.m_pObject);
    m_Index = this->m_hOwner.m_Index;
    if ( m_Index != -1
      && (v5 = (unsigned __int16)m_Index,
          v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v7 = HIWORD(m_Index),
          v6->m_SerialNumber == v7)
      && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        state_8.m_nOwner = ((int (__thiscall *)(IHandleEntity *))v10->m_pEntity[2].__vftable[3].SetRefEHandle)(a1: &v10->m_pEntity[2]);
      else
        state_8.m_nOwner = (*(int (__thiscall **)(int))(MEMORY[8] + 40))(a1: 8);
    }
    else
    {
      state_8.m_nOwner = -1;
    }
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "ParticleSystem_Create");
    else
      v12 = nullptr;
    KeyValues::SetPtr(this: v12, keyName: "state", value: &state_8);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137E50
// Name: private: void CNewParticleEffect::RecordControlPointOrientation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::RecordControlPointOrientation(CNewParticleEffect *this, int nWhichPoint)
{
  int v3; // ecx
  int v4; // edx
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  QAngle angles; // [esp+4h] [ebp-Ch] BYREF

  if ( (*((_BYTE *)this + 945) & 1) != 0
    && this->m_nToolParticleEffectId != -1
    && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v3 = this->m_nNumControlPointsAllocated - 1;
    v4 = nWhichPoint;
    if ( nWhichPoint < v3 )
      v3 = nWhichPoint;
    else
      v4 = this->m_nNumControlPointsAllocated - 1;
    VectorAngles(
      forward: &this->m_pCPInfo[v3].m_ControlPoint.m_ForwardVector,
      pseudoup: &this->m_pCPInfo[v4].m_ControlPoint.m_UpVector,
      &angles);
    if ( (_S7_11 & 1) == 0 )
      _S7_11 |= 1u;
    state_9.m_nParticleSystemId = this->m_nToolParticleEffectId;
    state_9.m_flTime = *(float *)(gpGlobals.m_Index + 12);
    state_9.m_nControlPoint = nWhichPoint;
    AngleQuaternion(&angles, outQuat: &state_9.m_qOrientation);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "ParticleSystem_SetControlPointOrientation");
    else
      v6 = nullptr;
    KeyValues::SetPtr(this: v6, keyName: "state", value: &state_9);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137F50
// Name: public: void CNewParticleEffect::SetControlPointOrientation(int,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetControlPointOrientation(
        CNewParticleEffect *this,
        int nWhichPoint,
        const Vector *forward,
        const Vector *right,
        const Vector *up)
{
  CParticleCollection::SetControlPointOrientation(this: &this->CParticleCollection, nWhichPoint, forward, right, up);
  CNewParticleEffect::RecordControlPointOrientation(this, nWhichPoint);
}

//------------------------------------------------------------------------------
// Address: 0x10137F80
// Name: public: virtual void CNewParticleEffect::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::Update(CNewParticleEffect *this, float flTimeDelta)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hOwner.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      CParticleProperty::OnParticleSystemUpdated(this: (CParticleProperty *)&m_pEntity[218], pEffect: this, flTimeDelta);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138020
// Name: private: void CNewParticleEffect::Construct(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNewParticleEffect::Construct(CNewParticleEffect *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  char v4; // al
  CParticleMgr *v5; // eax

  this->m_vSortOrigin.x = 0.0;
  this->m_vSortOrigin.y = 0.0;
  this->m_vSortOrigin.z = 0.0;
  v4 = *((_BYTE *)this + 945) & 0xF8 | 4;
  *((_BYTE *)this + 944) = -48;
  *((_BYTE *)this + 945) = v4;
  this->m_nToolParticleEffectId = -1;
  this->m_RefCount = 0;
  v5 = ParticleMgr();
  CParticleMgr::AddEffect(this: v5, a2, a3, pEffect: this);
  this->m_LastMax.x = -1000000.0;
  this->m_LastMax.y = -1000000.0;
  this->m_LastMax.z = -1000000.0;
  this->m_LastMin.x = 1000000.0;
  this->m_LastMin.y = 1000000.0;
  this->m_LastMin.z = 1000000.0;
  this->m_MinBounds.x = 1000000.0;
  this->m_MinBounds.y = 1000000.0;
  this->m_MinBounds.z = 1000000.0;
  this->m_MaxBounds.x = -1000000.0;
  this->m_MaxBounds.y = -1000000.0;
  this->m_MaxBounds.z = -1000000.0;
  this->m_pDebugName = nullptr;
  this->m_nSplitScreenUser = -1;
  CParticleCollection::SetRenderable(this: &this->CParticleCollection, pRenderable: this);
  CNewParticleEffect::RecordCreation(this);
}

//------------------------------------------------------------------------------
// Address: 0x10138110
// Name: public: void CNewParticleEffect::SetOwner(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetOwner(CNewParticleEffect *this, C_BaseEntity *pOwner)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax
  char IsRenderingInFastReflections; // bl
  IClientLeafSystem *v6; // esi
  IClientLeafSystem_vtbl *v7; // edi
  unsigned __int16 *v8; // eax
  CNewParticleEffect *v9; // [esp+8h] [ebp-4h]

  m_Index = this->m_hOwner.m_Index;
  v9 = this;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != pOwner )
  {
    if ( pOwner != nullptr )
    {
      this->m_hOwner.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
      IsRenderingInFastReflections = C_BaseEntity::IsRenderingInFastReflections(this: pOwner);
    }
    else
    {
      this->m_hOwner.m_Index = -1;
      IsRenderingInFastReflections = 0;
    }
    v6 = g_pClientLeafSystem;
    v7 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v8 = v9->RenderHandle(this: &v9->IClientRenderable);
    v7->RenderInFastReflections(this: v6, a2: *v8, a3: IsRenderingInFastReflections);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101381B0
// Name: public: void CNewParticleEffect::SetControlPointEntity(int,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetControlPointEntity(
        CNewParticleEffect *this,
        int nWhichPoint,
        C_BaseEntity *pEntity)
{
  KeyValues *v4; // eax
  KeyValues *v5; // edi

  if ( (*((_BYTE *)this + 945) & 1) != 0
    && this->m_nToolParticleEffectId != -1
    && clienttools->IsInRecordingMode(this: clienttools) )
  {
    state_10.m_nParticleSystemId = this->m_nToolParticleEffectId;
    state_10.m_flTime = *(float *)(gpGlobals.m_Index + 12);
    state_10.m_nControlPoint = nWhichPoint;
    if ( pEntity != nullptr )
      state_10.m_nObject = pEntity->entindex(this: &pEntity->IClientNetworkable);
    else
      state_10.m_nObject = -1;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ParticleSystem_SetControlPointObject");
    else
      v5 = nullptr;
    KeyValues::SetPtr(this: v5, keyName: "state", value: &state_10);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v5);
  }
  if ( pEntity != nullptr )
  {
    CParticleCollection::SetControlPointObject(
      this: &this->CParticleCollection,
      nWhichPoint,
      pObject: (void *)&this->m_hControlPointOwners[nWhichPoint]);
    this->m_hControlPointOwners[nWhichPoint].m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  }
  else
  {
    CParticleCollection::SetControlPointObject(this: &this->CParticleCollection, nWhichPoint, pObject: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101382B0
// Name: public: void CNewParticleEffect::SetToolRecording(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetToolRecording(CNewParticleEffect *this, bool bRecord)
{
  char v2; // dl
  char v3; // al

  v2 = *((_BYTE *)this + 945);
  if ( bRecord != (v2 & 1) )
  {
    v3 = v2 ^ (bRecord ^ v2) & 1;
    *((_BYTE *)this + 945) = v3;
    if ( (v3 & 1) != 0 )
      CNewParticleEffect::RecordCreation(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101382F0
// Name: public: virtual int CNewParticleEffect::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CNewParticleEffect::DrawModel@<eax>(
        CNewParticleEffect *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CMatRenderContextPtr flags,
        const RenderableInstance_t *instance)
{
  IClientMode *ClientMode; // eax
  CParticleMgr *v7; // eax
  int m_pObject; // ebx
  C_BaseCombatWeapon *v10; // eax
  CUtlReference<CParticleSystemDefinition> *m_pNext; // eax
  CUtlReference<CParticleSystemDefinition> *v12; // edi
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v14; // edi
  int v15; // eax
  CParticleCollection *m_Index; // edi
  C_BasePlayer *SplitScreenViewPlayer; // edi
  CUtlReference<CParticleSystemDefinition> *v18; // edi
  CUtlReference<CParticleSystemDefinition> *v19; // eax
  C_BaseCombatWeapon *OwnerEntity; // ebx
  CUtlReference<CParticleSystemDefinition> *m_pPrev; // eax
  C_BaseCombatWeapon *v22; // edi
  int v23; // eax
  int v24; // eax
  IMatRenderContext *v25; // edi
  bool v26; // al
  int v27; // eax
  bool v28; // zf
  void *m_pRenderable; // xmm1_4
  float v30; // xmm2_4
  float x; // xmm3_4
  float v32; // ecx
  float z; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  int v36; // ebx
  IVDebugOverlay_vtbl *v37; // edi
  int v38; // eax
  int i; // esi
  int v40; // ecx
  int v41; // eax
  CParticleCPInfo *m_pCPInfo; // edx
  int v43; // eax
  int v44; // eax
  float v45; // xmm1_4
  float y; // xmm2_4
  float v47; // xmm3_4
  int v48; // eax
  int v49; // eax
  float v50; // xmm0_4
  int p_m_RightVector; // eax
  int v52; // esi
  int v53; // [esp+64h] [ebp-64h]
  Vector4D vecDiffuseModulation; // [esp+70h] [ebp-58h] BYREF
  Vector target; // [esp+80h] [ebp-48h] BYREF
  Vector mins; // [esp+8Ch] [ebp-3Ch] BYREF
  Vector vecUp; // [esp+98h] [ebp-30h] BYREF
  Vector vecRight; // [esp+A4h] [ebp-24h] BYREF
  Vector vecPos; // [esp+B0h] [ebp-18h] BYREF
  unsigned int v61; // [esp+BCh] [ebp-Ch]
  CHandle<C_BaseCombatWeapon> v62; // [esp+C0h] [ebp-8h] BYREF
  int g; // [esp+C4h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNewParticleEffect::DrawModel",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  if ( r_DrawParticles.m_pParent == nullptr
    || r_DrawParticles.m_pParent->m_Value.m_nValue == 0
    || (ClientMode = GetClientMode(), !ClientMode->ShouldDrawParticles(this: ClientMode))
    || (v7 = ParticleMgr(), !CParticleMgr::ShouldRenderParticleSystems(this: v7))
    || (m_pObject = (int)flags.m_pObject, ((unsigned int)flags.m_pObject & 0x40000000) != 0) )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  v53 = a3;
  if ( CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_vSortOrigin.y) != nullptr )
  {
    v10 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_vSortOrigin.y);
    if ( v10->IsDormant(this: &v10->IClientNetworkable) )
      goto LABEL_45;
  }
  CMatRenderContextPtr::CMatRenderContextPtr(this: &flags, pFrom: materials);
  m_pNext = this->m_pDef.CParticleCollection::m_pNext;
  if ( BYTE1(m_pNext[20].m_pObject) == 0
    && LOBYTE(m_pNext[20].m_pObject) == 0
    && (((void (__thiscall *)(CMatRenderContextPtr, float *))flags.m_pObject->GetWorldSpaceCameraPosition)(
          a1: flags,
          a2: &vecDiffuseModulation.y),
        v12 = this->m_pDef.CParticleCollection::m_pNext,
        CalcSqrDistanceToAABB(
          mins: (const Vector *)&this->m_pRenderable,
          maxs: (const Vector *)&this->m_MinBounds.y,
          point: (const Vector *)&vecDiffuseModulation.y) > *(float *)&v12[23].m_pNext * *(float *)&v12[23].m_pNext)
    || LOBYTE(this->m_pDef.CParticleCollection::m_pNext[20].m_pObject) != 0
    && ((LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1), v14 = LocalPlayer, LocalPlayer == nullptr)
     || !LocalPlayer->IsAlive(this: LocalPlayer)
     || (v15 = (int)v14->GetRenderedWeaponModel(this: v14)) == 0
     || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v15 + 844))(a1: v15) == 0) )
  {
LABEL_44:
    CMatRenderContextPtr::~CMatRenderContextPtr(this: &flags);
LABEL_45:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  v61 = m_pObject & 0x80000000;
  if ( m_pObject < 0
    || (m_Index = (CParticleCollection *)&this->IClientRenderable,
        v62.m_Index = (unsigned int)&this->IClientRenderable,
        !CParticleCollection::IsBatchable(this: (CParticleCollection *)&this->IClientRenderable))
    || BYTE2(this->m_pDef.CParticleCollection::m_pNext[20].m_pObject) == 0 )
  {
    SplitScreenViewPlayer = GetSplitScreenViewPlayer(nSlot: 0);
    g = (int)SplitScreenViewPlayer;
    if ( C_BasePlayer::GetViewEntity(this: SplitScreenViewPlayer) != nullptr )
      g = (int)C_BasePlayer::GetViewEntity(this: SplitScreenViewPlayer);
    v18 = this->m_pDef.CParticleCollection::m_pNext;
    v19 = v18[24].m_pNext;
    if ( v19 == (CUtlReference<CParticleSystemDefinition> *)-1 )
      v62.m_Index = -1;
    else
      v62.m_Index = *((_DWORD *)&this->m_vSortOrigin.z + (_DWORD)v19);
    OwnerEntity = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: &v62);
    m_pPrev = v18[24].m_pPrev;
    if ( m_pPrev == (CUtlReference<CParticleSystemDefinition> *)-1 )
      v62.m_Index = -1;
    else
      v62.m_Index = *((_DWORD *)&this->m_vSortOrigin.z + (_DWORD)m_pPrev);
    v22 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: &v62);
    if ( OwnerEntity != nullptr )
    {
      if ( OwnerEntity->IsBaseCombatWeapon(this: OwnerEntity)
        || OwnerEntity->GetBaseAnimating(this: OwnerEntity) != nullptr
        && (v23 = (int)OwnerEntity->GetBaseAnimating(this: OwnerEntity),
            (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v23 + 844))(a1: v23) != 0) )
      {
        OwnerEntity = (C_BaseCombatWeapon *)C_BaseEntity::GetOwnerEntity(this: OwnerEntity);
      }
    }
    if ( v22 != nullptr )
    {
      if ( v22->IsBaseCombatWeapon(this: v22)
        || v22->GetBaseAnimating(this: v22) != nullptr
        && (v24 = (int)v22->GetBaseAnimating(this: v22),
            (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v24 + 844))(a1: v24) != 0) )
      {
        v22 = (C_BaseCombatWeapon *)C_BaseEntity::GetOwnerEntity(this: v22);
      }
    }
    if ( g == 0 || (C_BaseCombatWeapon *)g != OwnerEntity && (v22 == nullptr || (C_BaseCombatWeapon *)g == v22) )
    {
      v25 = flags.m_pObject;
      vecDiffuseModulation.x = 1.0;
      vecDiffuseModulation.y = 1.0;
      vecDiffuseModulation.z = 1.0;
      vecDiffuseModulation.w = 1.0;
      ((void (__thiscall *)(CMatRenderContextPtr, int, int))flags.m_pObject->MatrixMode)(a1: flags, a2: 10, a3: v53);
      v25->PushMatrix(this: v25);
      v25->LoadIdentity(this: v25);
      v26 = v61 != 0 && CParticleCollection::IsTwoPass(this: (CParticleCollection *)&this->IClientRenderable);
      v62.m_Index = (unsigned int)&this->IClientRenderable;
      CParticleCollection::Render(
        this: (CParticleCollection *)&this->IClientRenderable,
        a2: (int)this,
        nViewRecursionLevel: 0,
        pRenderContext: v25,
        &vecDiffuseModulation,
        bTranslucentOnly: v26,
        pCameraObject: (void *)g);
      v25->MatrixMode(this: v25, a2: MATERIAL_MODEL);
      v25->PopMatrix(this: v25);
      m_Index = (CParticleCollection *)v62.m_Index;
      goto LABEL_50;
    }
    goto LABEL_44;
  }
  CParticleSystemMgr::AddToRenderCache(
    this: g_pParticleSystemMgr,
    pParticles: this != (CNewParticleEffect *)8 ? m_Index : nullptr);
LABEL_50:
  if ( cl_particles_show_bbox.m_pParent != nullptr && cl_particles_show_bbox.m_pParent->m_Value.m_nValue != 0 )
  {
    v27 = ((int (__thiscall *)(CNewParticleEffect *, int, int))this->Update)(a1: this, a2: v53, a3: a2);
    v28 = ((int)this->m_pPrev & 0x20) == 0;
    m_pRenderable = this->m_pRenderable;
    v30 = *(float *)&this->m_bBoundsValid;
    x = this->m_MinBounds.x;
    *(_QWORD *)&vecPos.x = *(_QWORD *)v27;
    v32 = *(float *)(v27 + 8);
    z = this->m_MinBounds.z;
    mins.x = *(float *)&m_pRenderable - vecPos.x;
    vecPos.z = v32;
    mins.y = v30 - vecPos.y;
    mins.z = x - v32;
    v34 = this->m_MinBounds.y - vecPos.x;
    vecRight.y = z - vecPos.y;
    v35 = this->m_MaxBounds.x - v32;
    vecRight.x = v34;
    vecRight.z = v35;
    if ( v28 )
    {
      v36 = 0;
      g = 255;
    }
    else
    {
      v36 = 255;
      g = 0;
    }
    memset((void *)&vecUp, 0, sizeof(vecUp));
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, Vector *, int, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: debugoverlay,
      a2: &vecPos,
      a3: &mins,
      a4: &vecRight,
      a5: &vecUp,
      a6: v36,
      a7: g,
      a8: 0);
    v37 = debugoverlay->__vftable;
    v38 = (*(int (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 2) + 44))(
            a1: (char *)this - 8,
            a2: LODWORD(this->m_flPrevSimTime));
    ((void (__cdecl *)(IVDebugOverlay *, Vector *, _DWORD, _DWORD, int, int, _DWORD, int, const char *, int))v37->AddTextOverlayRGB)(
      a1: debugoverlay,
      a2: &vecPos,
      a3: 0,
      a4: 0,
      a5: v36,
      a6: g,
      a7: 0,
      a8: 64,
      a9: "%s:(%d)",
      a10: v38);
    m_Index = (CParticleCollection *)v62.m_Index;
  }
  if ( cl_particles_show_controlpoints.m_pParent != nullptr
    && cl_particles_show_controlpoints.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = 0; i < 64; ++i )
    {
      if ( CParticleCollection::ReadsControlPoint(this: m_Index, nPoint: i) )
      {
        v40 = m_Index->m_nNumControlPointsAllocated - 1;
        v41 = i;
        if ( i >= v40 )
          v41 = m_Index->m_nNumControlPointsAllocated - 1;
        m_pCPInfo = m_Index->m_pCPInfo;
        vecPos = m_pCPInfo[v41].m_ControlPoint.m_Position;
        v43 = i;
        if ( i >= v40 )
          v43 = v40;
        v44 = v43;
        v45 = m_pCPInfo[v44].m_ControlPoint.m_ForwardVector.x;
        y = m_pCPInfo[v44].m_ControlPoint.m_ForwardVector.y;
        v47 = m_pCPInfo[v44].m_ControlPoint.m_ForwardVector.z;
        v48 = i;
        if ( i >= v40 )
          v48 = v40;
        v49 = v48;
        v50 = m_pCPInfo[v49].m_ControlPoint.m_RightVector.x;
        p_m_RightVector = (int)&m_pCPInfo[v49].m_ControlPoint.m_RightVector;
        vecRight.x = v50;
        vecRight.y = *(float *)(p_m_RightVector + 4);
        vecRight.z = *(float *)(p_m_RightVector + 8);
        if ( i < v40 )
          v40 = i;
        vecUp = m_pCPInfo[v40].m_ControlPoint.m_UpVector;
        mins.x = vecPos.x + (float)(v45 * 4.0);
        mins.y = vecPos.y + (float)(y * 4.0);
        mins.z = vecPos.z + (float)(v47 * 4.0);
        NDebugOverlay::Line(
          origin: &vecPos,
          target: &mins,
          r: 255,
          g: 0,
          b: 0,
          noDepthTest: true,
          duration: 0.050000001);
        target.x = (float)(vecRight.x * 4.0) + vecPos.x;
        target.y = (float)(vecRight.y * 4.0) + vecPos.y;
        target.z = (float)(vecRight.z * 4.0) + vecPos.z;
        NDebugOverlay::Line(origin: &vecPos, &target, r: 0, g: 255, b: 0, noDepthTest: true, duration: 0.050000001);
        vecDiffuseModulation.y = (float)(vecUp.x * 4.0) + vecPos.x;
        vecDiffuseModulation.z = (float)(vecUp.y * 4.0) + vecPos.y;
        vecDiffuseModulation.w = (float)(vecUp.z * 4.0) + vecPos.z;
        NDebugOverlay::Line(
          origin: &vecPos,
          target: (const Vector *)&vecDiffuseModulation.y,
          r: 0,
          g: 0,
          b: 255,
          noDepthTest: true,
          duration: 0.050000001);
      }
    }
  }
  v52 = (int)flags.m_pObject;
  if ( flags.m_pObject != nullptr )
  {
    ((void (__thiscall *)(CMatRenderContextPtr))flags.m_pObject->EndRender)(a1: flags);
    (*(void (__thiscall **)(int))(*(_DWORD *)v52 + 4))(a1: v52);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10138A10
// Name: protected: CNewParticleEffect::CNewParticleEffect(class C_BaseEntity __near *,class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__userpurge CNewParticleEffect::CNewParticleEffect@<eax>(
        CNewParticleEffect *this@<ecx>,
        int a2@<ebx>,
        C_BaseEntity *pOwner,
        CParticleSystemDefinition *pEffect)
{
  unsigned __int8 (__thiscall **p_m_LastMin)(IResourceAccessControl *, int, const char *); // edi
  const char *Name; // eax

  this->IParticleEffect::__vftable = (CNewParticleEffect_vtbl *)&IParticleEffect::`vftable';
  CParticleCollection::CParticleCollection(this: &this->CParticleCollection);
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&IClientRenderable::`vftable';
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CDefaultClientRenderable_vtbl *)&CDefaultClientRenderable::`vftable'{for `IClientUnknown'};
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CDefaultClientRenderable::`vftable'{for `IClientRenderable'};
  this->m_hRenderHandle = -1;
  this->IParticleEffect::__vftable = (CNewParticleEffect_vtbl *)&CNewParticleEffect::`vftable';
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CDefaultClientRenderable_vtbl *)&CNewParticleEffect::`vftable'{for `IClientUnknown'};
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CNewParticleEffect::`vftable'{for `IClientRenderable'};
  this->m_References.m_pHead = nullptr;
  this->m_hOwner.m_Index = -1;
  memset((void *)this->m_hControlPointOwners, 0xFFu, sizeof(this->m_hControlPointOwners));
  p_m_LastMin = (unsigned __int8 (__thiscall **)(IResourceAccessControl *, int, const char *))&this->m_LastMin;
  if ( pOwner != nullptr )
    this->m_hOwner.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
  else
    this->m_hOwner.m_Index = -1;
  if ( g_pResourceAccessControl != nullptr )
  {
    p_m_LastMin = (unsigned __int8 (__thiscall **)(IResourceAccessControl *, int, const char *))g_pResourceAccessControl->__vftable;
    Name = CParticleSystemDefinition::GetName(this: pEffect);
    if ( p_m_LastMin[12](a1: g_pResourceAccessControl, a2: 3, a3: Name) == 0 )
      pEffect = CParticleSystemMgr::FindParticleSystem(this: g_pParticleSystemMgr, pName: "error");
  }
  CParticleCollection::Init(this: &this->CParticleCollection, pDef: pEffect);
  CNewParticleEffect::Construct(this, a2, a3: (int)p_m_LastMin);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10138AF0
// Name: protected: CNewParticleEffect::CNewParticleEffect(class C_BaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__userpurge CNewParticleEffect::CNewParticleEffect@<eax>(
        CNewParticleEffect *this@<ecx>,
        int a2@<ebx>,
        C_BaseEntity *pOwner,
        const char *pEffectName)
{
  const char *v5; // edi

  this->IParticleEffect::__vftable = (CNewParticleEffect_vtbl *)&IParticleEffect::`vftable';
  CParticleCollection::CParticleCollection(this: &this->CParticleCollection);
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&IClientRenderable::`vftable';
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CDefaultClientRenderable_vtbl *)&CDefaultClientRenderable::`vftable'{for `IClientUnknown'};
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CDefaultClientRenderable::`vftable'{for `IClientRenderable'};
  this->m_hRenderHandle = -1;
  this->IParticleEffect::__vftable = (CNewParticleEffect_vtbl *)&CNewParticleEffect::`vftable';
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CDefaultClientRenderable_vtbl *)&CNewParticleEffect::`vftable'{for `IClientUnknown'};
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CNewParticleEffect::`vftable'{for `IClientRenderable'};
  this->m_References.m_pHead = nullptr;
  this->m_hOwner.m_Index = -1;
  memset((void *)this->m_hControlPointOwners, 0xFFu, sizeof(this->m_hControlPointOwners));
  if ( pOwner != nullptr )
    this->m_hOwner.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
  else
    this->m_hOwner.m_Index = -1;
  v5 = pEffectName;
  if ( g_pResourceAccessControl != nullptr
    && !g_pResourceAccessControl->IsAccessAllowed(
          this: g_pResourceAccessControl,
          a2: RESOURCE_PARTICLE_SYSTEM,
          a3: pEffectName) )
  {
    v5 = "error";
  }
  CParticleCollection::Init(this: &this->CParticleCollection, pParticleSystemName: v5);
  CNewParticleEffect::Construct(this, a2, a3: (int)v5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10138BB0
// Name: public: static class CNewParticleEffect __near * CNewParticleEffect::CreateOrAggregate(class C_BaseEntity __near *,class CParticleSystemDefinition __near *,class Vector const __near &,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__cdecl CNewParticleEffect::CreateOrAggregate(
        C_BaseEntity *pOwner,
        CParticleSystemDefinition *pDef,
        const Vector *vecAggregatePosition,
        const char *pDebugName,
        int nSplitScreenSlot)
{
  CNewParticleEffect *v5; // edi
  CParticleSystemDefinition *FallbackReplacementDefinition; // eax
  CParticleCollection *m_pFirstCollection; // esi
  float i; // xmm3_4
  float *p_m_pPrevDef; // edx
  CNewParticleEffect *v10; // eax
  bool bCanAggregate; // [esp+Bh] [ebp-1h]

  v5 = nullptr;
  if ( pOwner == nullptr
    && pDef->m_flAggregateRadius > 0.0
    && cl_aggregate_particles.m_pParent != nullptr
    && cl_aggregate_particles.m_pParent->m_Value.m_nValue != 0 )
  {
    bCanAggregate = true;
    FallbackReplacementDefinition = pDef;
    do
    {
      m_pFirstCollection = FallbackReplacementDefinition->m_pFirstCollection;
      for ( i = (float)(FallbackReplacementDefinition->m_flAggregateRadius
                      * FallbackReplacementDefinition->m_flAggregateRadius)
              + 0.1; m_pFirstCollection != nullptr; m_pFirstCollection = m_pFirstCollection->m_pNextDef )
      {
        p_m_pPrevDef = (float *)&m_pFirstCollection[-1].m_pPrevDef;
        if ( (m_pFirstCollection[1].m_fl4CurTime.m128_i8[1] & 4) == 0
          && i > (float)((float)((float)((float)(vecAggregatePosition->y - p_m_pPrevDef[314])
                                       * (float)(vecAggregatePosition->y - p_m_pPrevDef[314]))
                               + (float)((float)(vecAggregatePosition->x - p_m_pPrevDef[313])
                                       * (float)(vecAggregatePosition->x - p_m_pPrevDef[313])))
                       + (float)((float)(vecAggregatePosition->z - p_m_pPrevDef[315])
                               * (float)(vecAggregatePosition->z - p_m_pPrevDef[315])))
          && m_pFirstCollection->m_nMaxAllowedParticles - m_pFirstCollection->m_nActiveParticles > FallbackReplacementDefinition->m_nAggregationMinAvailableParticles
          && *((_DWORD *)p_m_pPrevDef + 312) == nSplitScreenSlot )
        {
          i = (float)((float)((float)(vecAggregatePosition->y - p_m_pPrevDef[314])
                            * (float)(vecAggregatePosition->y - p_m_pPrevDef[314]))
                    + (float)((float)(vecAggregatePosition->x - p_m_pPrevDef[313])
                            * (float)(vecAggregatePosition->x - p_m_pPrevDef[313])))
            + (float)((float)(vecAggregatePosition->z - p_m_pPrevDef[315])
                    * (float)(vecAggregatePosition->z - p_m_pPrevDef[315]));
          v5 = (CNewParticleEffect *)&m_pFirstCollection[-1].m_pPrevDef;
        }
      }
      FallbackReplacementDefinition = CParticleSystemDefinition::GetFallbackReplacementDefinition(this: FallbackReplacementDefinition);
    }
    while ( FallbackReplacementDefinition != nullptr );
    if ( v5 != nullptr )
    {
      CParticleCollection::Restart(this: &v5->CParticleCollection, eMode: RESTART_RESET_AND_MAKE_SURE_EMITS_HAPPEN);
LABEL_22:
      v5->m_vecAggregationCenter = *vecAggregatePosition;
      goto LABEL_23;
    }
  }
  else
  {
    bCanAggregate = false;
  }
  v10 = (CNewParticleEffect *)CParticleOperatorInstance::operator new(nSize: 0x530u);
  if ( v10 != nullptr )
    v5 = CNewParticleEffect::CNewParticleEffect(this: v10, a2: (int)vecAggregatePosition, pOwner, pEffect: pDef);
  else
    v5 = nullptr;
  if ( nSplitScreenSlot != v5->m_nSplitScreenUser )
    v5->m_nSplitScreenUser = nSplitScreenSlot;
  *((_BYTE *)v5 + 944) |= 0x40u;
  if ( bCanAggregate )
    goto LABEL_22;
LABEL_23:
  *((_BYTE *)v5 + 945) &= ~4u;
  v5->m_pDebugName = pDebugName;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10138D40
// Name: public: static class CNewParticleEffect __near * CNewParticleEffect::CreateOrAggregatePrecached(class C_BaseEntity __near *,int,class Vector const __near &,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__cdecl CNewParticleEffect::CreateOrAggregatePrecached(
        C_BaseEntity *pOwner,
        int nPrecacheIndex,
        const Vector *vecAggregatePosition,
        const char *pDebugName,
        int nSplitScreenUser)
{
  CParticleSystemDefinition *PrecachedParticleSystem; // eax
  const char *ParticleSystemNameFromIndex; // eax

  PrecachedParticleSystem = CParticleSystemMgr::FindPrecachedParticleSystem(this: g_pParticleSystemMgr, nPrecacheIndex);
  if ( PrecachedParticleSystem == nullptr )
  {
    ParticleSystemNameFromIndex = GetParticleSystemNameFromIndex(nIndex: nPrecacheIndex);
    _Warning(a1: "Attempted to create unknown particle system type \"%s\"!\n", ParticleSystemNameFromIndex);
    PrecachedParticleSystem = CParticleSystemMgr::FindParticleSystem(this: g_pParticleSystemMgr, pName: "error");
  }
  return CNewParticleEffect::CreateOrAggregate(
           pOwner,
           pDef: PrecachedParticleSystem,
           vecAggregatePosition,
           pDebugName,
           nSplitScreenSlot: nSplitScreenUser);
}

//------------------------------------------------------------------------------
// Address: 0x10138DA0
// Name: public: static class CNewParticleEffect __near * CNewParticleEffect::Create(class C_BaseEntity __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__usercall CNewParticleEffect::Create@<eax>(
        int a1@<ebx>,
        C_BaseEntity *pOwner,
        const char *pParticleSystemName,
        const char *pDebugName)
{
  CNewParticleEffect *v4; // eax
  CNewParticleEffect *result; // eax

  v4 = (CNewParticleEffect *)CParticleOperatorInstance::operator new(nSize: 0x530u);
  if ( v4 != nullptr )
  {
    result = CNewParticleEffect::CNewParticleEffect(this: v4, a2: a1, pOwner, pEffectName: pParticleSystemName);
    *((_BYTE *)result + 944) |= 0x40u;
    result->m_pDebugName = pDebugName;
  }
  else
  {
    MEMORY[0x3B0] |= 0x40u;
    MEMORY[0x3AC] = pDebugName;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10138DF0
// Name: public: class CNewParticleEffect __near * CNewParticleEffect::ReplaceWith(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__userpurge CNewParticleEffect::ReplaceWith@<eax>(
        CNewParticleEffect *this@<ecx>,
        int a2@<ebx>,
        CNewParticleEffect *pParticleSystemName)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax
  CNewParticleEffect *result; // eax
  CNewParticleEffect *v7; // ebx
  int i; // esi
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  CParticleCPInfo *m_pCPInfo; // edx
  int v13; // ecx
  float x; // xmm0_4
  int p_m_ForwardVector; // ecx
  int v16; // ecx
  int v17; // ecx
  float v18; // xmm0_4
  int p_m_RightVector; // ecx
  int v20; // eax
  float v21; // xmm0_4
  int p_m_UpVector; // eax
  int v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  CEntInfo *v26; // edx
  unsigned int v27; // ecx
  CEntInfo *v28; // eax
  CUtlReference<CNewParticleEffect> *m_pHead; // eax
  CNewParticleEffect *m_pObject; // ecx
  CUtlReference<CNewParticleEffect> *m_pPrev; // edx
  CUtlReference<CNewParticleEffect> *m_pNext; // edx
  CUtlReference<CNewParticleEffect> *v33; // ecx
  Vector vecForward; // [esp+4h] [ebp-24h] BYREF
  Vector vecRight; // [esp+10h] [ebp-18h] BYREF
  Vector vecUp; // [esp+1Ch] [ebp-Ch] BYREF
  CNewParticleEffect *pNewEffect; // [esp+30h] [ebp+8h]

  CNewParticleEffect::StopEmission(
    this,
    bInfiniteOnly: false,
    bRemoveAllParticles: true,
    bWakeOnStop: true,
    bPlayEndCap: false);
  if ( pParticleSystemName == nullptr || LOBYTE(pParticleSystemName->IParticleEffect::__vftable) == 0 )
    return nullptr;
  m_Index = this->m_hOwner.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  result = CNewParticleEffect::Create(
             a1: a2,
             pOwner: m_pEntity,
             (const char *)pParticleSystemName,
             pDebugName: (const char *)pParticleSystemName);
  v7 = result;
  pNewEffect = result;
  if ( result != nullptr )
  {
    for ( i = 0; i < 64; ++i )
    {
      if ( (this->m_nControlPointReadMask & (1LL << i)) != 0 )
      {
        v9 = this->m_nNumControlPointsAllocated - 1;
        if ( i < v9 )
          v9 = i;
        CNewParticleEffect::SetControlPoint(this: v7, nWhichPoint: i, v: &this->m_pCPInfo[v9].m_ControlPoint.m_Position);
        v10 = this->m_nNumControlPointsAllocated - 1;
        v11 = i;
        if ( i >= v10 )
          v11 = this->m_nNumControlPointsAllocated - 1;
        m_pCPInfo = this->m_pCPInfo;
        v13 = v11;
        x = m_pCPInfo[v13].m_ControlPoint.m_ForwardVector.x;
        p_m_ForwardVector = (int)&m_pCPInfo[v13].m_ControlPoint.m_ForwardVector;
        vecForward.x = x;
        vecForward.y = *(float *)(p_m_ForwardVector + 4);
        vecForward.z = *(float *)(p_m_ForwardVector + 8);
        v16 = i;
        if ( i >= v10 )
          v16 = v10;
        v17 = v16;
        v18 = m_pCPInfo[v17].m_ControlPoint.m_RightVector.x;
        p_m_RightVector = (int)&m_pCPInfo[v17].m_ControlPoint.m_RightVector;
        vecRight.x = v18;
        vecRight.y = *(float *)(p_m_RightVector + 4);
        vecRight.z = *(float *)(p_m_RightVector + 8);
        if ( i < v10 )
          v10 = i;
        v20 = v10;
        v21 = m_pCPInfo[v20].m_ControlPoint.m_UpVector.x;
        p_m_UpVector = (int)&m_pCPInfo[v20].m_ControlPoint.m_UpVector;
        vecUp.x = v21;
        vecUp.y = *(float *)(p_m_UpVector + 4);
        vecUp.z = *(float *)(p_m_UpVector + 8);
        CParticleCollection::SetControlPointOrientation(
          this: &v7->CParticleCollection,
          nWhichPoint: i,
          forward: &vecForward,
          right: &vecRight,
          up: &vecUp);
        CNewParticleEffect::RecordControlPointOrientation(this: pNewEffect, nWhichPoint: i);
        v23 = this->m_nNumControlPointsAllocated - 1;
        if ( i < v23 )
          v23 = i;
        CParticleCollection::SetControlPointParent(
          this: &v7->CParticleCollection,
          nWhichPoint: i,
          n: this->m_pCPInfo[v23].m_ControlPoint.m_nParent);
        v7 = pNewEffect;
      }
    }
    v24 = this->m_hOwner.m_Index;
    if ( v24 != -1 )
    {
      v25 = (unsigned __int16)v24;
      v26 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v24];
      v27 = HIWORD(v24);
      if ( v26->m_SerialNumber == v27 && v26->m_pEntity != nullptr )
      {
        v28 = &g_pEntityList->m_EntPtrArray[v25];
        if ( v28->m_SerialNumber == v27 )
          CParticleProperty::ReplaceParticleEffect(
            this: (CParticleProperty *)&v28->m_pEntity[218],
            pOldEffect: this,
            pNewEffect: v7);
        else
          CParticleProperty::ReplaceParticleEffect(this: (CParticleProperty *)0x368, pOldEffect: this, pNewEffect: v7);
      }
    }
    while ( this->m_References.m_pHead != nullptr )
    {
      m_pHead = this->m_References.m_pHead;
      m_pObject = m_pHead->m_pObject;
      if ( m_pObject != v7 )
      {
        if ( m_pObject != nullptr )
        {
          m_pPrev = m_pHead->m_pPrev;
          if ( m_pPrev != nullptr )
          {
            m_pPrev->m_pNext = m_pHead->m_pNext;
            if ( m_pHead->m_pNext != nullptr )
              m_pHead->m_pNext->m_pPrev = m_pHead->m_pPrev;
          }
          else if ( m_pObject->m_References.m_pHead == m_pHead )
          {
            m_pNext = m_pHead->m_pNext;
            m_pObject->m_References.m_pHead = m_pHead->m_pNext;
            if ( m_pNext != nullptr )
              m_pNext->m_pPrev = nullptr;
          }
          m_pHead->m_pPrev = nullptr;
          m_pHead->m_pNext = nullptr;
          m_pHead->m_pObject = nullptr;
        }
        m_pHead->m_pObject = v7;
        m_pHead->m_pNext = v7->m_References.m_pHead;
        v33 = v7->m_References.m_pHead;
        if ( v33 != nullptr )
          v33->m_pPrev = m_pHead;
        m_pHead->m_pPrev = nullptr;
        v7->m_References.m_pHead = m_pHead;
      }
    }
    *((_BYTE *)this + 944) |= 2u;
    return v7;
  }
  return result;
}
