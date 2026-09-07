// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/detailobjectsystem.cpp
// Functions: 74
// ============================================================

#include "game\client\detailobjectsystem.h"

//------------------------------------------------------------------------------
// Address: 0x100A3AD0
// Name: public: virtual int CDetailObjectSystem::GetDetailModelCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDetailObjectSystem::GetDetailModelCount(CChoreoScene *this)
{
  return this->m_Actors.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100C7660
// Name: DrawMeshCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawMeshCallback(void *pMesh)
{
  (*(void (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)pMesh + 48))(a1: pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C7680
// Name: public: virtual class QAngle const __near & CDetailModel::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CDetailModel::GetRenderAngles(CDetailModel *this)
{
  return (const QAngle *)&this->m_Origin.z;
}

//------------------------------------------------------------------------------
// Address: 0x100C7690
// Name: public: virtual bool CDetailModel::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDetailModel::GetAttachment(CDetailModel *this, int number, matrix3x4_t *matrix)
{
  const matrix3x4_t *v3; // eax

  v3 = (const matrix3x4_t *)this->IClientUnknown::IHandleEntity::__vftable[3].GetRefEHandle(this);
  MatrixCopy(in: v3, out: matrix);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C76B0
// Name: public: virtual bool CDetailModel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDetailModel::ShouldDraw(CDetailModel *this)
{
  IClientMode *ClientMode; // eax

  ClientMode = GetClientMode();
  return ClientMode->ShouldDrawDetailObjects(this: ClientMode);
}

//------------------------------------------------------------------------------
// Address: 0x100C76C0
// Name: public: virtual void CDetailModel::GetRenderBoundsWorldspace(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDetailModel::GetRenderBoundsWorldspace(
        C_BaseEntity *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        Vector *mins,
        Vector *maxs)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  DefaultRenderBoundsWorldspace(
    a1: COERCE_FLOAT(&savedregs),
    a2,
    a3,
    pRenderable: this != (C_BaseEntity *)4 ? (IClientRenderable *)this : nullptr,
    absMins: mins,
    absMaxs: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x100C76F0
// Name: public: virtual void CDetailModel::GetShadowRenderBounds(class Vector __near &,class Vector __near &,enum ShadowType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailModel::GetShadowRenderBounds(
        CDetailModel *this,
        Vector *mins,
        Vector *maxs,
        ShadowType_t shadowType)
{
  ((void (__thiscall *)(CDetailModel *, Vector *, Vector *))this->IClientUnknown::IHandleEntity::__vftable[1].GetBaseEntity)(
    a1: this,
    a2: mins,
    a3: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x100C7710
// Name: public: virtual int CDetailModel::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDetailModel::DrawModel(CDetailModel *this, int flags, const RenderableInstance_t *instance)
{
  if ( instance->m_nAlpha == 0 || *((_DWORD *)this + 9) == 0 )
    return 0;
  ((void (__stdcall *)(_DWORD))render->SetBlend)(a1: (float)instance->m_nAlpha * 0.0039215689);
  return modelrender->DrawModel(
           this: modelrender,
           a2: flags,
           a3: this != (CDetailModel *)4 ? (IClientRenderable *)this : nullptr,
           a4: 0xFFFF,
           a5: -1,
           a6: *((const struct model_t **)this + 9),
           a7: (const Vector *)&this->IClientRenderable,
           a8: (const QAngle *)&this->m_Origin.z,
           a9: 0,
           a10: 0,
           a11: 0,
           a12: nullptr,
           a13: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100C7790
// Name: private: void CDetailObjectSystem::FreeSortBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::FreeSortBuffers(CDetailObjectSystem *this)
{
  CDetailObjectSystem::SortInfo_t *m_pSortInfo; // eax
  CDetailObjectSystem::SortInfo_t *m_pFastSortInfo; // eax
  FastSpriteQuadBuildoutBufferX4_t *m_pBuildoutBuffer; // eax

  m_pSortInfo = this->m_pSortInfo;
  if ( m_pSortInfo != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pSortInfo & 0xFFFFFFFC) - 4));
    this->m_pSortInfo = nullptr;
  }
  m_pFastSortInfo = this->m_pFastSortInfo;
  if ( m_pFastSortInfo != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pFastSortInfo & 0xFFFFFFFC) - 4));
    this->m_pFastSortInfo = nullptr;
  }
  m_pBuildoutBuffer = this->m_pBuildoutBuffer;
  if ( m_pBuildoutBuffer != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pBuildoutBuffer & 0xFFFFFFFC) - 4));
    this->m_pBuildoutBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7820
// Name: public: virtual void CDetailObjectSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::LevelShutdownPostEntity(CDetailObjectSystem *this)
{
  CMaterialReference::Shutdown(this: &this->m_DetailWireframeMaterial, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C7830
// Name: public: virtual void CDetailObjectSystem::BeginTranslucentDetailRendering(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::BeginTranslucentDetailRendering(CDetailObjectSystem *this)
{
  this->m_nSortedLeaf = -1;
  this->m_bFirstLeaf = true;
  this->m_nFirstSprite = 0;
  this->m_nSpriteCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C7850
// Name: private: static bool CDetailObjectSystem::SortLessFunc(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDetailObjectSystem::SortLessFunc(
        const CDetailObjectSystem::SortInfo_t *left,
        const CDetailObjectSystem::SortInfo_t *right)
{
  return SLODWORD(left->m_flDistance) > SLODWORD(right->m_flDistance);
}

//------------------------------------------------------------------------------
// Address: 0x100C7870
// Name: public: virtual float CDetailObjectSystem::ComputeDetailFadeInfo(struct DistanceFadeInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDetailObjectSystem::ComputeDetailFadeInfo(CDetailObjectSystem *this, DistanceFadeInfo_t *pInfo)
{
  C_BasePlayer *LocalPlayer; // eax
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float flFactora; // [esp+4h] [ebp-4h]
  float flFactor; // [esp+4h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    flFactora = C_BasePlayer::GetFOVDistanceAdjustFactor(this: LocalPlayer);
    v4 = flFactora;
  }
  else
  {
    v4 = 1.0;
  }
  v5 = 1.0 / v4;
  flFactor = this->m_flDetailFadeEnd * (float)(1.0 / v4);
  v6 = flFactor * flFactor;
  pInfo->m_flMaxDistSqr = flFactor * flFactor;
  v7 = (float)(this->m_flDetailFadeStart * v5) * (float)(this->m_flDetailFadeStart * v5);
  pInfo->m_flMinDistSqr = v7;
  if ( (float)((float)(flFactor * flFactor) - 1.0) <= v7 )
    v7 = v6 - 1.0;
  pInfo->m_flMinDistSqr = v7;
  pInfo->m_flFalloffFactor = 1.0 / (float)(v6 - v7);
  return flFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100C7A30
// Name: public: static float float16::Convert16bitFloatTo32bits(unsigned short)
// Source: json
//------------------------------------------------------------------------------
double __cdecl float16::Convert16bitFloatTo32bits(unsigned int input)
{
  int v1; // ecx
  float v3; // xmm0_4

  v1 = (input >> 10) & 0x1F;
  if ( v1 == 31 )
  {
    if ( (input & 0x3FF) != 0 )
    {
      return 0.0;
    }
    else if ( (input & 0x8000) != 0 )
    {
      return -1.0 * 65504.0;
    }
    else
    {
      return 1.0 * 65504.0;
    }
  }
  else if ( (_WORD)v1 != 0 || (input & 0x3FF) == 0 )
  {
    return COERCE_FLOAT((input & 0x3FF
                       | (8
                        * (input & 0x8000
                         | ((((((unsigned __int16)input >> 10) & 0x1F) + 112)
                           * ((((unsigned __int16)input >> 10) & 0x1F) != 0)) << 7)))) << 13);
  }
  else
  {
    if ( (input & 0x8000) != 0 )
      v3 = -1.0;
    else
      v3 = 1.0;
    return (float)((float)(v3 * (float)((float)(input & 0x3FF) * 0.0009765625)) * 0.000061035156);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7B30
// Name: public: static unsigned short float16::ConvertFloatTo16bitsNonDefault<0>(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl float16::ConvertFloatTo16bitsNonDefault<0>(float input)
{
  float v1; // xmm0_4
  int v2; // xmm1_4
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  float16::float16bits output; // [esp+8h] [ebp+8h]

  v1 = input;
  v2 = 1199562752;
  if ( input > 65504.0 || (v2 = -947920896, input < -65504.0) )
    v1 = *(float *)&v2;
  v3 = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  v4 = (unsigned __int8)(LODWORD(v1) >> 23);
  output.rawWord = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  if ( (unsigned __int8)(LODWORD(v1) >> 23) != 0 )
  {
    if ( v4 == 255 )
    {
      if ( (LODWORD(v1) & 0x7FFFFF) != 0 )
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
      else
        LOWORD(v3) = LOWORD(v1) & 0x7BFF | (LODWORD(v1) >> 31 << 15) | 0x7BFF;
    }
    else
    {
      v5 = v4 - 127;
      if ( v5 < -24 )
      {
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
        output.rawWord = v3;
      }
      if ( v5 >= -14 )
      {
        if ( v5 <= 15 )
          return (((_WORD)v5 + 15) << 10) & 0x7C00 | (LODWORD(v1) >> 13) & 0x3FF | output.rawWord & 0x8000;
        else
          LOWORD(v3) = output.rawWord & 0x8000 | 0x7BFF;
      }
      else
      {
        LOWORD(v3) = v3 & 0x83FF;
        if ( (unsigned int)(-14 - v5 - 1) <= 9 )
          LOWORD(v3) = (v3 ^ ((1 << (10 - (-14 - v5))) + ((LODWORD(v1) & 0x7FFFFFu) >> (-14 - v5 + 13)))) & 0x3FF ^ v3;
      }
    }
  }
  else
  {
    LOWORD(v3) = LODWORD(v1) >> 31 << 15;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C7C50
// Name: public: virtual struct matrix3x4_t const __near & CDetailModel::RenderableToWorldTransform(void)
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall CDetailModel::RenderableToWorldTransform(CDetailModel *this)
{
  const QAngle *v2; // eax
  const Vector *v4; // [esp-8h] [ebp-Ch]

  if ( (_S5_92 & 1) == 0 )
    _S5_92 |= 1u;
  v4 = (const Vector *)((int (__thiscall *)(CDetailModel *))this->SetRefEHandle)(a1: this);
  v2 = (const QAngle *)this->GetRefEHandle(this);
  AngleMatrix(angles: v2, position: v4, matrix: &mat);
  return &mat;
}

//------------------------------------------------------------------------------
// Address: 0x100C7C90
// Name: public: virtual bool CDetailModel::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDetailModel::GetAttachment(CDetailModel *this, int number, Vector *origin, QAngle *angles)
{
  origin->x = *(float *)&this->IClientRenderable::__vftable;
  origin->y = this->m_Origin.x;
  origin->z = this->m_Origin.y;
  *angles = *(QAngle *)&this->m_Origin.z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C7CD0
// Name: public: void CDetailModel::InitShapeTri(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailModel::InitShapeTri(CDetailModel *this)
{
  int v2; // ebx
  int i; // esi
  matrix3x4_t matrix; // [esp+Ch] [ebp-60h] BYREF
  Vector rotUp; // [esp+3Ch] [ebp-30h] BYREF
  Vector rotRight; // [esp+48h] [ebp-24h] BYREF
  Vector rotForward; // [esp+54h] [ebp-18h] BYREF
  QAngle anglesRotated; // [esp+60h] [ebp-Ch] BYREF

  AngleMatrix(angles: &this->m_Angles, &matrix);
  v2 = 0;
  for ( i = 72; i < 108; i += 12 )
  {
    anglesRotated.x = (float)this->m_pAdvInfo->m_iShapeAngle;
    anglesRotated.y = (float)v2;
    anglesRotated.z = 0.0;
    AngleVectors(angles: &anglesRotated, forward: &rotForward, right: &rotRight, up: &rotUp);
    VectorRotate(in1: &rotForward.x, in2: &matrix, out: (float *)((char *)this->m_pAdvInfo + i - 72));
    VectorRotate(in1: &rotRight.x, in2: &matrix, out: (float *)((char *)this->m_pAdvInfo + i - 36));
    VectorRotate(in1: &rotUp.x, in2: &matrix, out: (float *)((char *)this->m_pAdvInfo + i));
    v2 += 120;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7D90
// Name: public: void CDetailObjectSystem::UpdateDetailFadeValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::UpdateDetailFadeValues(CDetailObjectSystem *this)
{
  int m_nValue; // eax
  float v3; // xmm0_4
  int v4; // eax
  float v5; // xmm0_4
  C_EnvDetailController *DetailController; // eax
  float m_flDetailFadeStart; // xmm0_4
  C_EnvDetailController *v8; // eax
  float m_flDetailFadeEnd; // xmm0_4

  if ( cl_detaildist.m_pParent != nullptr )
    m_nValue = cl_detaildist.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = (float)m_nValue;
  this->m_flDetailFadeEnd = (float)m_nValue;
  if ( cl_detailfade.m_pParent != nullptr )
    v4 = cl_detailfade.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  v5 = v3 - (float)v4;
  this->m_flDetailFadeStart = v5;
  if ( v5 < 0.0 )
    this->m_flDetailFadeStart = 0.0;
  if ( GetDetailController() != nullptr )
  {
    DetailController = GetDetailController();
    m_flDetailFadeStart = this->m_flDetailFadeStart;
    if ( DetailController->m_flFadeStartDist.m_Value <= m_flDetailFadeStart )
      m_flDetailFadeStart = GetDetailController()->m_flFadeStartDist.m_Value;
    this->m_flDetailFadeStart = m_flDetailFadeStart;
    v8 = GetDetailController();
    m_flDetailFadeEnd = this->m_flDetailFadeEnd;
    if ( v8->m_flFadeEndDist.m_Value <= m_flDetailFadeEnd )
      m_flDetailFadeEnd = GetDetailController()->m_flFadeEndDist.m_Value;
    this->m_flDetailFadeEnd = m_flDetailFadeEnd;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7E50
// Name: public: virtual void CDetailObjectSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::LevelInitPostEntity(CDetailObjectSystem *this)
{
  const char *v2; // esi
  C_World *ClientWorldEntity; // eax
  char *m_iszDetailSpriteMaterial; // eax

  v2 = "detail/detailsprites";
  ClientWorldEntity = GetClientWorldEntity();
  if ( ClientWorldEntity != nullptr )
  {
    m_iszDetailSpriteMaterial = ClientWorldEntity->m_iszDetailSpriteMaterial;
    if ( m_iszDetailSpriteMaterial != nullptr && *m_iszDetailSpriteMaterial != 0 )
      v2 = m_iszDetailSpriteMaterial;
  }
  CMaterialReference::Init(
    this: &this->m_DetailSpriteMaterial,
    pMaterialName: v2,
    pTextureGroupName: "Other textures",
    bComplain: true);
  CDetailObjectSystem::UpdateDetailFadeValues(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C7E90
// Name: private: int CDetailObjectSystem::CountSpritesInLeafList(int,unsigned short __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDetailObjectSystem::CountSpritesInLeafList(
        CDetailObjectSystem *this,
        int nLeafCount,
        unsigned __int16 *pLeafList)
{
  int v3; // edi
  int i; // esi
  int nFirstDetailObject; // [esp+Ch] [ebp-8h] BYREF
  int nDetailObjectCount; // [esp+10h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDetailObjectSystem::CountSpritesInLeafList",
    a3: 0,
    a4: "Detail_Prop_Rendering",
    a5: false,
    a6: 4);
  v3 = 0;
  for ( i = 0; i < nLeafCount; ++i )
  {
    ((void (__stdcall *)(_DWORD, int *, int *))g_pClientLeafSystem->GetDetailObjectsInLeaf)(
      a1: pLeafList[i],
      a2: &nFirstDetailObject,
      a3: &nDetailObjectCount);
    v3 += nDetailObjectCount;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C7F00
// Name: private: int CDetailObjectSystem::CountFastSpritesInLeafList(int,unsigned short const __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDetailObjectSystem::CountFastSpritesInLeafList(
        CDetailObjectSystem *this,
        int nLeafCount,
        const unsigned __int16 *pLeafList,
        int *nMaxFoundInLeaf)
{
  int v4; // ebx
  int v5; // edi
  int i; // esi
  int v7; // eax
  int v8; // ecx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDetailObjectSystem::CountSpritesInLeafList",
    a3: 0,
    a4: "Detail_Prop_Rendering",
    a5: false,
    a6: 4);
  v4 = 0;
  v5 = 0;
  for ( i = 0; i < nLeafCount; ++i )
  {
    v7 = ((int (__stdcall *)(_DWORD, _DWORD))g_pClientLeafSystem->GetSubSystemDataInLeaf)(a1: pLeafList[i], a2: 0);
    if ( v7 != 0 )
    {
      v8 = *(_DWORD *)(v7 + 4);
      v4 += v8;
      if ( v5 <= v8 )
        v5 = *(_DWORD *)(v7 + 4);
    }
  }
  *nMaxFoundInLeaf = (v5 + 3) & 0xFFFFFFFC;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100C7F80
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7FD0
// Name: public: CUtlEnvelope<unsigned short>::CUtlEnvelope<unsigned short>(unsigned short const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlEnvelope<unsigned short> *__thiscall CUtlEnvelope<unsigned short>::CUtlEnvelope<unsigned short>(
        CUtlEnvelope<unsigned short> *this,
        unsigned __int8 *pData,
        int nElems)
{
  int v3; // edi
  unsigned __int8 *v5; // eax

  v3 = 2 * nElems;
  if ( pData != nullptr )
  {
    this->m_nBytes = v3;
    if ( v3 <= 4 )
    {
      memcpy(dst: (unsigned __int8 *)this, src: pData, count: v3);
    }
    else
    {
      v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v3);
      this->m_pData = v5;
      memcpy(dst: v5, src: pData, count: v3);
    }
    return this;
  }
  else
  {
    this->m_pData = nullptr;
    this->m_nBytes = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C81C0
// Name: private: void CUtlDataEnvelope::Assign(class CUtlDataEnvelope const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDataEnvelope::Assign(CUtlDataEnvelope *this, CUtlDataEnvelope *from)
{
  CUtlDataEnvelope *m_pData; // ebx
  int m_nBytes; // esi
  unsigned __int8 *v5; // eax

  m_pData = from;
  m_nBytes = from->m_nBytes;
  if ( m_nBytes != 0 )
  {
    if ( m_nBytes > 4 )
      m_pData = (CUtlDataEnvelope *)from->m_pData;
  }
  else
  {
    m_pData = nullptr;
  }
  if ( m_pData != nullptr )
  {
    this->m_nBytes = m_nBytes;
    if ( m_nBytes <= 4 )
    {
      memcpy(dst: (unsigned __int8 *)this, src: (unsigned __int8 *)m_pData, count: m_nBytes);
    }
    else
    {
      v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: m_nBytes);
      this->m_pData = v5;
      memcpy(dst: v5, src: (unsigned __int8 *)m_pData, count: m_nBytes);
    }
  }
  else
  {
    this->m_pData = nullptr;
    this->m_nBytes = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8230
// Name: protected: bool CUtlBuffer::GetTypeText<int>(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<int>(CUtlBuffer *this, int *value, unsigned int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C8330
// Name: DetailFadeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl DetailFadeCallback()
{
  CDetailObjectSystem::UpdateDetailFadeValues(this: &s_DetailObjectSystem);
}

//------------------------------------------------------------------------------
// Address: 0x100C8340
// Name: public: virtual void CDetailModel::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailModel::GetRenderBounds(CDetailModel *this, Vector *mins, Vector *maxs)
{
  int v4; // eax
  IVModelInfoClient_vtbl *v5; // esi
  int v6; // eax
  DetailPropSpriteDict_t *v7; // esi
  double v8; // st7
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float ul_4; // [esp+Ch] [ebp-Ch]
  float flScale; // [esp+14h] [ebp-4h]
  float flScalea; // [esp+14h] [ebp-4h]

  if ( (this->m_Color.r & 0xC) != 0 )
  {
    v7 = &s_DetailObjectSystem.m_DetailSpriteDict.m_Memory.m_pMemory[*((unsigned __int16 *)this + 18)];
    v8 = float16::Convert16bitFloatTo32bits(input: *((_WORD *)this + 19));
    flScale = v8;
    v9 = fabs(v7->m_LR.x * flScale);
    v10 = fabs(v7->m_UL.x * flScale);
    if ( v9 <= v10 )
      v11 = v10;
    else
      v11 = v9;
    flScalea = v8 * v7->m_LR.y;
    v12 = fabs(flScalea);
    ul_4 = v7->m_UL.y * v8;
    v13 = fabs(ul_4);
    if ( v12 <= v13 )
      v12 = v13;
    v14 = fsqrt((float)(v12 * v12) + (float)(v11 * v11));
    LODWORD(mins->x) = LODWORD(v14) ^ _mask__NegFloat_;
    LODWORD(mins->y) = LODWORD(v14) ^ _mask__NegFloat_;
    LODWORD(mins->z) = LODWORD(v14) ^ _mask__NegFloat_;
    maxs->x = v14;
    maxs->y = v14;
    maxs->z = v14;
  }
  else
  {
    v4 = modelinfo->GetModelType(this: modelinfo, a2: *((const struct model_t **)this + 9));
    if ( v4 == 3 || v4 == 1 )
    {
      v5 = modelinfo->__vftable;
      v6 = ((int (__thiscall *)(CDetailModel *, Vector *, Vector *))this->GetClientThinkable)(
             a1: this,
             a2: mins,
             a3: maxs);
      ((void (__thiscall *)(IVModelInfoClient *, int))v5->GetModelRenderBounds)(a1: modelinfo, a2: v6);
    }
    else
    {
      mins->x = 0.0;
      mins->y = 0.0;
      mins->z = 0.0;
      maxs->x = 0.0;
      maxs->y = 0.0;
      maxs->z = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8480
// Name: public: virtual bool CDetailModel::SetupBones(class matrix3x4a_t __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CDetailModel::SetupBones@<al>(
        CDetailModel *this@<ecx>,
        int a2@<ebp>,
        matrix3x4a_t *pBoneToWorldOut,
        int nMaxBones,
        int boneMask,
        float currentTime)
{
  float *v8; // edi
  const struct model_t *v9; // eax
  studiohdr_t *v10; // edi
  int v11; // esi
  _BYTE v12[12]; // [esp-Ch] [ebp-4Ch] BYREF
  matrix3x4a_t parentTransform; // [esp+0h] [ebp-40h]
  matrix3x4_t *v14; // [esp+30h] [ebp-10h]
  int v15; // [esp+34h] [ebp-Ch]
  void *v16; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  v15 = a2;
  v16 = retaddr;
  if ( *((_DWORD *)this + 9) == 0 )
    return 0;
  v14 = (matrix3x4_t *)this->GetRefEHandle(this);
  v8 = (float *)((int (__thiscall *)(CDetailModel *))this->SetRefEHandle)(a1: this);
  AngleMatrix(angles: (const QAngle *)v14, matrix: (matrix3x4_t *)v12);
  v9 = *((const struct model_t **)this + 9);
  parentTransform.m_flMatVal[0][0] = *v8;
  parentTransform.m_flMatVal[1][0] = v8[1];
  parentTransform.m_flMatVal[2][0] = v8[2];
  v10 = modelinfo->GetStudiomodel(this: modelinfo, a2: v9);
  v11 = 0;
  if ( v10->numbones > 0 )
  {
    v14 = pBoneToWorldOut;
    do
    {
      MatrixCopy(in: (const matrix3x4_t *)v12, out: v14++);
      ++v11;
    }
    while ( v11 < v10->numbones );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C8570
// Name: public: void CDetailModel::InitShapedSprite(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailModel::InitShapedSprite(
        CDetailModel *this,
        unsigned __int8 shapeAngle,
        unsigned __int8 shapeSize,
        unsigned __int8 swayAmount)
{
  DetailModelAdvInfo_t *v5; // eax

  v5 = (DetailModelAdvInfo_t *)MemAlloc_Alloc(nSize: 0x88u);
  this->m_pAdvInfo = v5;
  if ( v5 != nullptr )
  {
    v5->m_iShapeAngle = shapeAngle;
    this->m_pAdvInfo->m_flSwayAmount = (float)swayAmount * 0.0039215689;
    this->m_pAdvInfo->m_flShapeSize = (float)shapeSize * 0.0039215689;
    this->m_pAdvInfo->m_vecCurrentAvoid = vec3_origin;
    this->m_pAdvInfo->m_flSwayYaw = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 0,
                                      a3: 1127481344);
  }
  if ( ((*((unsigned __int8 *)this + 36) >> 2) & 3) == 2 )
  {
    AngleVectors(
      angles: &this->m_Angles,
      forward: this->m_pAdvInfo->m_vecAnglesForward,
      right: this->m_pAdvInfo->m_vecAnglesRight,
      up: this->m_pAdvInfo->m_vecAnglesUp);
  }
  else if ( ((*((unsigned __int8 *)this + 36) >> 2) & 3) == 3 )
  {
    CDetailModel::InitShapeTri(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8670
// Name: public: void CDetailModel::DrawSwayingQuad(class CMeshBuilder __near &,class Vector,class Vector,class Vector2D,class Vector2D,unsigned char __near *,class Vector,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailModel::DrawSwayingQuad(
        CDetailModel *this,
        CMeshBuilder *meshBuilder,
        Vector vecOrigin,
        Vector vecSway,
        Vector2D texul,
        Vector2D texlr,
        unsigned __int8 *color,
        Vector width,
        Vector height)
{
  float *m_pCurrPosition; // eax
  float *v10; // eax
  float *v11; // eax
  float *v12; // eax

  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = vecSway.x + vecOrigin.x;
  m_pCurrPosition[1] = vecOrigin.y + vecSway.y;
  m_pCurrPosition[2] = vecSway.z + vecOrigin.z;
  *(Vector2D *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = texul;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = color[2]
                                                       | ((color[1] | ((*color | (color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  vecOrigin.y = height.y + vecOrigin.y;
  vecOrigin.x = height.x + vecOrigin.x;
  vecOrigin.z = height.z + vecOrigin.z;
  *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrPosition = vecOrigin;
  v10 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  *v10 = texul.x;
  v10[1] = texlr.y;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = color[2]
                                                       | ((color[1] | ((*color | (color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  vecOrigin.y = width.y + vecOrigin.y;
  vecOrigin.x = width.x + vecOrigin.x;
  vecOrigin.z = width.z + vecOrigin.z;
  *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrPosition = vecOrigin;
  *(Vector2D *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = texlr;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = color[2]
                                                       | ((color[1] | ((*color | (color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v11 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v11 = vecSway.x + (float)(vecOrigin.x - height.x);
  v11[1] = (float)(vecOrigin.y - height.y) + vecSway.y;
  v11[2] = vecSway.z + (float)(vecOrigin.z - height.z);
  v12 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  *v12 = texlr.x;
  v12[1] = texul.y;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = color[2]
                                                       | ((color[1] | ((*color | (color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x100C88D0
// Name: public: virtual class IClientRenderable __near * CDetailObjectSystem::GetDetailModel(int)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall CDetailObjectSystem::GetDetailModel(CDetailObjectSystem *this, int idx)
{
  CDetailModel *v2; // eax

  v2 = &this->m_DetailObjects.m_Memory.m_pMemory[idx];
  if ( (*((_BYTE *)v2 + 36) & 0xC) != 0 || v2 == nullptr )
    return nullptr;
  else
    return &v2->IClientRenderable;
}

//------------------------------------------------------------------------------
// Address: 0x100C8900
// Name: private: class Vector CDetailObjectSystem::GetSpriteMiddleBottomPosition(struct DetailObjectLump_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CDetailObjectSystem::GetSpriteMiddleBottomPosition(
        CDetailObjectSystem *this,
        Vector *result,
        const DetailObjectLump_t *lump)
{
  int m_DetailModel; // esi
  float x; // xmm1_4
  DetailPropSpriteDict_t *v5; // esi
  float m_flScale; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  QAngle Angles; // [esp+8h] [ebp-30h] BYREF
  Vector vecDir; // [esp+14h] [ebp-24h] BYREF
  Vector dy; // [esp+20h] [ebp-18h] BYREF
  Vector right; // [esp+2Ch] [ebp-Ch] BYREF

  m_DetailModel = lump->m_DetailModel;
  x = lump->m_Origin.x;
  vecDir.y = (float)(lump->m_Origin.y - 100.0) - lump->m_Origin.y;
  v5 = &s_DetailObjectSystem.m_DetailSpriteDict.m_Memory.m_pMemory[m_DetailModel];
  vecDir.x = x - x;
  vecDir.z = 0.0;
  VectorAngles(forward: &vecDir, angles: &Angles);
  AngleVectors(angles: &Angles, forward: nullptr, &right, up: &dy);
  m_flScale = lump->m_flScale;
  v7 = v5->m_UL.x * m_flScale;
  v8 = v5->m_UL.y * m_flScale;
  v9 = v5->m_LR.y * m_flScale;
  v10 = (float)(dy.x * v8) + (float)((float)(right.x * v7) + lump->m_Origin.x);
  v11 = (float)(v5->m_LR.x * m_flScale) - v7;
  v12 = (float)(dy.y * v8) + (float)((float)(right.y * v7) + lump->m_Origin.y);
  v13 = (float)(dy.z * v8) + (float)((float)(right.z * v7) + lump->m_Origin.z);
  v14 = v9 - v8;
  right.y = right.y * v11;
  dy.y = dy.y * v14;
  vecDir.x = (float)(right.x * v11) * 0.5;
  v16 = (float)(dy.y + v12) + (float)(right.y * 0.5);
  v17 = vecDir.x + (float)((float)(dy.x * v14) + v10);
  v18 = (float)((float)(v14 * dy.z) + v13) + (float)((float)(v11 * right.z) * 0.5);
  result->x = v17;
  result->y = v16;
  result->z = v18;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C8A80
// Name: private: void CDetailObjectSystem::UnserializeFastSprite(struct FastSpriteX4_t __near *,int,struct DetailObjectLump_t const __near &,bool,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::UnserializeFastSprite(
        CDetailObjectSystem *this,
        FastSpriteX4_t *pSpritex4,
        int nSubField,
        const DetailObjectLump_t *lump,
        bool bFlipped,
        const Vector *posOffset)
{
  Vector *SpriteMiddleBottomPosition; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  CDetailObjectSystem *v9; // ecx
  DetailPropSpriteDict_t *v10; // esi
  ColorRGBExp32 m_Lighting; // eax
  float v12; // xmm0_4
  int v13; // ecx
  int v14; // edx
  double v15; // xmm1_8
  float color[4]; // [esp+Ch] [ebp-20h] BYREF
  Vector result; // [esp+1Ch] [ebp-10h] BYREF
  CDetailObjectSystem *v18; // [esp+28h] [ebp-4h]

  v18 = this;
  SpriteMiddleBottomPosition = CDetailObjectSystem::GetSpriteMiddleBottomPosition(this, &result, lump);
  v7 = SpriteMiddleBottomPosition->y + posOffset->y;
  v8 = SpriteMiddleBottomPosition->z + posOffset->z;
  v9 = v18;
  pSpritex4->m_Pos.x.m128_f32[nSubField] = SpriteMiddleBottomPosition->x + posOffset->x;
  pSpritex4->m_Pos.y.m128_f32[nSubField] = v7;
  pSpritex4->m_Pos.z.m128_f32[nSubField] = v8;
  v10 = &v9->m_DetailSpriteDict.m_Memory.m_pMemory[lump->m_DetailModel];
  pSpritex4->m_HalfWidth.m128_f32[nSubField] = (float)(v10->m_LR.x - v10->m_UL.x) * (float)(lump->m_flScale * 0.5);
  pSpritex4->m_Height.m128_f32[nSubField] = (float)(v10->m_LR.y - v10->m_UL.y) * lump->m_flScale;
  if ( !bFlipped )
    v10 = &v9->m_DetailSpriteDictFlipped.m_Memory.m_pMemory[lump->m_DetailModel];
  m_Lighting = lump->m_Lighting;
  v12 = dword_105BA000[m_Lighting.exponent];
  color[0] = (float)m_Lighting.r * v12;
  color[1] = (float)m_Lighting.g * v12;
  color[2] = (float)m_Lighting.b * v12;
  color[3] = 255.0;
  engine->LinearToGamma(this: engine, a2: color, a3: color);
  v13 = (int)(color[0] * 255.0);
  v14 = (int)(color[1] * 255.0);
  v15 = color[2] * 255.0;
  pSpritex4->m_pSpriteDefs[nSubField] = v10;
  pSpritex4->m_RGBColor[nSubField][0] = v13;
  pSpritex4->m_RGBColor[nSubField][1] = v14;
  pSpritex4->m_RGBColor[nSubField][2] = (int)v15;
  pSpritex4->m_RGBColor[nSubField][3] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100C8C00
// Name: private: int CDetailObjectSystem::CountSpriteQuadsInLeafList(int,unsigned short __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDetailObjectSystem::CountSpriteQuadsInLeafList(
        CDetailObjectSystem *this,
        int nLeafCount,
        unsigned __int16 *pLeafList)
{
  int v4; // esi
  int i; // edi
  int v6; // ecx
  unsigned __int8 *v7; // eax
  int nFirstDetailObject; // [esp+Ch] [ebp-8h] BYREF
  int nDetailObjectCount; // [esp+10h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDetailObjectSystem::CountSpritesInLeafList",
    a3: 0,
    a4: "Detail_Prop_Rendering",
    a5: false,
    a6: 4);
  v4 = 0;
  for ( i = 0; i < nLeafCount; ++i )
  {
    ((void (__stdcall *)(_DWORD, int *, int *))g_pClientLeafSystem->GetDetailObjectsInLeaf)(
      a1: pLeafList[i],
      a2: &nFirstDetailObject,
      a3: &nDetailObjectCount);
    v6 = nDetailObjectCount;
    if ( nDetailObjectCount > 0 )
    {
      v7 = (unsigned __int8 *)&this->m_DetailObjects.m_Memory.m_pMemory[nFirstDetailObject] + 36;
      do
      {
        v4 += s_pQuadCount[(*v7 >> 2) & 3];
        v7 += 48;
        --v6;
      }
      while ( v6 != 0 );
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100C8F20
// Name: public: void CUtlMemoryFixedGrowable<struct DetailRenderableInfo_t,2048,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<DetailRenderableInfo_t,2048,int>::Grow(
        CUtlMemoryFixedGrowable<DetailRenderableInfo_t,2048,int> *this,
        int nCount)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = this->m_nMallocGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 16 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (DetailRenderableInfo_t *)v5;
      CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
        (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
        num: nCount);
      return;
    }
    this->m_pMemory = nullptr;
  }
  CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
    (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
    num: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x100C9360
// Name: public: CFunctor8<void (*)(class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short> const __near &),class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short>,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::CFunctor8<void (*)(class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short> const __near &),class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short>,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>(void (*)(class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short> const __near &),class CDetailObjectSystem __near * const __near &,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int const __near &,class CUtlEnvelope<unsigned short> const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor8<void (__cdecl*)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *__thiscall CFunctor8<void (__cdecl *)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::CFunctor8<void (__cdecl *)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>(
        CFunctor8<void (__cdecl*)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this,
        void (__cdecl *pfnProxied)(CDetailObjectSystem *, DistanceFadeInfo_t, Vector, Vector, Vector, Vector, int, const CUtlEnvelope<unsigned short> *),
        CDetailObjectSystem **arg1,
        const DistanceFadeInfo_t *arg2,
        const Vector *arg3,
        const Vector *arg4,
        const Vector *arg5,
        const Vector *arg6,
        int *arg7,
        const CUtlEnvelope<unsigned short> *arg8)
{
  this->m_iRefs = 1;
  this->m_pfnProxied = pfnProxied;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CFunctor8<void (__cdecl*)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > >_vtbl *)&CFunctor8<void (__cdecl *)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctor8<void (__cdecl *)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_arg1 = *arg1;
  this->m_arg2 = *arg2;
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  this->m_arg5 = *arg5;
  this->m_arg6 = *arg6;
  this->m_arg7 = *arg7;
  CUtlDataEnvelope::Assign(this: &this->m_arg8, from: &arg8->CUtlDataEnvelope);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C9400
// Name: public: virtual void CFunctor8<void (*)(class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short> const __near &),class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short>,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor8<void (__cdecl *)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor8<void (__cdecl*)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(CDetailObjectSystem *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, CUtlEnvelope<unsigned short> *))this->m_pfnProxied)(
    a1: this->m_arg1,
    a2: LODWORD(this->m_arg2.m_flMaxDistSqr),
    a3: LODWORD(this->m_arg2.m_flMinDistSqr),
    a4: LODWORD(this->m_arg2.m_flFalloffFactor),
    a5: LODWORD(this->m_arg3.x),
    a6: LODWORD(this->m_arg3.y),
    a7: LODWORD(this->m_arg3.z),
    a8: LODWORD(this->m_arg4.x),
    a9: LODWORD(this->m_arg4.y),
    a10: LODWORD(this->m_arg4.z),
    a11: LODWORD(this->m_arg5.x),
    a12: LODWORD(this->m_arg5.y),
    a13: LODWORD(this->m_arg5.z),
    a14: LODWORD(this->m_arg6.x),
    a15: LODWORD(this->m_arg6.y),
    a16: LODWORD(this->m_arg6.z),
    a17: this->m_arg7,
    a18: &this->m_arg8);
}

//------------------------------------------------------------------------------
// Address: 0x100C94D0
// Name: public: CMemberFunctor9<class CDetailObjectSystem __near *,void (CDetailObjectSystem::*)(class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class Vector const __near &,bool),class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class Vector,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::CMemberFunctor9<class CDetailObjectSystem __near *,void (CDetailObjectSystem::*)(class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class Vector const __near &,bool),class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class Vector,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(class CDetailObjectSystem __near *,void (CDetailObjectSystem::*)(class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class Vector const __near &,bool),class CFastDetailLeafSpriteList __near * const __near &,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int const __near &,class Vector const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this,
        CDetailObjectSystem *pObject,
        __int128 pfnProxied,
        CFastDetailLeafSpriteList **arg1,
        const DistanceFadeInfo_t *arg2,
        const Vector *arg3,
        const Vector *arg4,
        const Vector *arg5,
        const Vector *arg6,
        int *arg7,
        const Vector *arg8,
        bool *arg9)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_Proxy.m_pObject = pObject;
  this->m_Proxy.m_pfnProxied = pfnProxied;
  this->m_arg1 = *arg1;
  this->m_arg2 = *arg2;
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  this->m_arg5 = *arg5;
  this->m_arg6 = *arg6;
  this->m_arg7 = *arg7;
  this->m_arg8 = *arg8;
  this->m_arg9 = *arg9;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C9590
// Name: public: virtual void CMemberFunctor9<class CDetailObjectSystem __near *,void (CDetailObjectSystem::*)(class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class Vector const __near &,bool),class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class Vector,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, CFastDetailLeafSpriteList *, DistanceFadeInfo_t *, Vector *, Vector *, Vector *, Vector *, int, Vector *, bool))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: &this->m_arg2,
    a4: &this->m_arg3,
    a5: &this->m_arg4,
    a6: &this->m_arg5,
    a7: &this->m_arg6,
    a8: this->m_arg7,
    a9: &this->m_arg8,
    a10: this->m_arg9);
}

//------------------------------------------------------------------------------
// Address: 0x100CA720
// Name: public: virtual void CDetailObjectSystem::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::LevelShutdownPreEntity(CDetailObjectSystem *this)
{
  CUtlVector<CDetailModel,CUtlMemory<CDetailModel,int>>::Purge(this: &this->m_DetailObjects);
  this->m_DetailObjectDict.m_Size = 0;
  if ( this->m_DetailObjectDict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DetailObjectDict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DetailObjectDict.m_Memory.m_pMemory);
      this->m_DetailObjectDict.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailObjectDict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DetailObjectDict.m_pElements = this->m_DetailObjectDict.m_Memory.m_pMemory;
  this->m_DetailSpriteDict.m_Size = 0;
  if ( this->m_DetailSpriteDict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DetailSpriteDict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DetailSpriteDict.m_Memory.m_pMemory);
      this->m_DetailSpriteDict.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailSpriteDict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DetailSpriteDict.m_pElements = this->m_DetailSpriteDict.m_Memory.m_pMemory;
  this->m_DetailSpriteDictFlipped.m_Size = 0;
  if ( this->m_DetailSpriteDictFlipped.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory);
      this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailSpriteDictFlipped.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DetailSpriteDictFlipped.m_pElements = this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory;
  this->m_DetailLighting.m_Size = 0;
  if ( this->m_DetailLighting.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DetailLighting.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DetailLighting.m_Memory.m_pMemory);
      this->m_DetailLighting.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailLighting.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DetailLighting.m_pElements = this->m_DetailLighting.m_Memory.m_pMemory;
  CMaterialReference::Shutdown(this: &this->m_DetailSpriteMaterial, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x100CAB20
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 0xAu);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CABC0
// Name: public: virtual enum IterationRetval_t CPlayerEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CPlayerEnumerator::EnumElement(CPlayerEnumerator *this, IHandleEntity *pHandleEntity)
{
  CBaseHandle *v3; // eax
  C_BaseEntity *BaseEntityFromHandle; // eax
  C_BaseEntity *v5; // esi
  float *v6; // eax
  vgui::TreeNode *m_Index; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Objects; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v12; // eax
  vgui::TreeNode **v13; // eax

  v3 = pHandleEntity->GetRefEHandle(this: pHandleEntity);
  BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           hEnt: (CBaseHandle)v3->m_Index);
  v5 = BaseEntityFromHandle;
  if ( BaseEntityFromHandle != nullptr && BaseEntityFromHandle->IsPlayer(this: BaseEntityFromHandle) )
  {
    v6 = (float *)v5->GetAbsOrigin(this: v5);
    if ( (float)((float)((float)((float)(*v6 - this->m_vecOrigin.x) * (float)(*v6 - this->m_vecOrigin.x))
                       + (float)((float)(v6[1] - this->m_vecOrigin.y) * (float)(v6[1] - this->m_vecOrigin.y)))
               + (float)((float)(v6[2] - this->m_vecOrigin.z) * (float)(v6[2] - this->m_vecOrigin.z))) <= this->m_flRadiusSquared )
    {
      m_Index = (vgui::TreeNode *)v5->GetRefEHandle(this: v5)->m_Index;
      m_nAllocationCount = this->m_Objects.m_Memory.m_nAllocationCount;
      p_m_Objects = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Objects;
      m_Size = this->m_Objects.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Objects, num: m_Size - m_nAllocationCount + 1);
      ++p_m_Objects[1].m_pMemory;
      m_pMemory = p_m_Objects->m_pMemory;
      v12 = (int)p_m_Objects[1].m_pMemory - m_Size - 1;
      p_m_Objects[1].m_nAllocationCount = (int)p_m_Objects->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &p_m_Objects->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = m_Index;
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x100CACB0
// Name: public: virtual void CDetailModel::GetColorModulation(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDetailModel::GetColorModulation(CDetailModel *this@<ecx>, int a2@<edi>, float *color)
{
  double v4; // st7
  int z_high; // ecx
  unsigned __int16 v7; // ax
  int v8; // edx
  float *v9; // ecx
  int v10; // eax
  int v11; // ebx
  DetailPropLightstylesLump_t *v12; // esi
  double v13; // st7
  float v14; // xmm0_4
  Vector tmp; // [esp+4h] [ebp-20h] BYREF
  Vector normal; // [esp+10h] [ebp-14h] BYREF
  CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t search; // [esp+1Ch] [ebp-8h] BYREF
  float *colora; // [esp+2Ch] [ebp+8h]

  if ( mat_fullbright_0.m_pParent != nullptr && mat_fullbright_0.m_pParent->m_Value.m_nValue == 1 )
  {
    color[2] = 1.0;
    color[1] = 1.0;
    *color = 1.0;
  }
  else
  {
    normal.x = 1.0;
    normal.y = 0.0;
    normal.z = 0.0;
    ((void (__thiscall *)(IVEngineClient *, IClientRenderable *, Vector *, Vector *, int))engine->ComputeDynamicLighting)(
      a1: engine,
      a2: &this->IClientRenderable,
      a3: &normal,
      a4: &tmp,
      a5: a2);
    v4 = ((double (__thiscall *)(IVEngineClient *, _DWORD))engine->LightStyleValue)(a1: engine, a2: 0);
    z_high = SHIBYTE(this->m_Angles.z);
    search.elem = (CDetailModel::LightStyleInfo_t)LOBYTE(this->m_Angles.z);
    *color = (double)(int)search.elem * dword_105BA000[z_high] * v4 + tmp.x;
    color[1] = (double)BYTE1(this->m_Angles.z) * dword_105BA000[SHIBYTE(this->m_Angles.z)] * v4 + tmp.y;
    color[2] = v4 * ((double)BYTE2(this->m_Angles.z) * dword_105BA000[SHIBYTE(this->m_Angles.z)]) + tmp.z;
    if ( (this->m_Color.r & 0x10) != 0 )
    {
      search.key = (CDetailModel *)((char *)this - 4);
      v7 = CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &CDetailModel::gm_LightStylesMap.m_Tree,
             &search);
      if ( v7 != 0xFFFF )
      {
        v8 = v7;
        v9 = (float *)*((unsigned __int8 *)&CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem
                      + 3);
        v10 = *(_DWORD *)&CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem & 0xFFFFFF;
        if ( *((_BYTE *)&CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem + 3) != 0 )
        {
          v11 = v10;
          colora = v9;
          do
          {
            v12 = &s_DetailObjectSystem.m_DetailLighting.m_Memory.m_pMemory[v11];
            v13 = ((double (__stdcall *)(_DWORD))engine->LightStyleValue)(a1: s_DetailObjectSystem.m_DetailLighting.m_Memory.m_pMemory[v11].m_Style);
            *(float *)&search.elem = v13;
            if ( v13 != 0.0 )
            {
              v14 = *(float *)&search.elem;
              *color = (float)((float)((float)v12->m_Lighting.r * dword_105BA000[v12->m_Lighting.exponent])
                             * *(float *)&search.elem)
                     + *color;
              color[1] = (float)((float)((float)v12->m_Lighting.g * dword_105BA000[v12->m_Lighting.exponent]) * v14)
                       + color[1];
              color[2] = (float)((float)((float)v12->m_Lighting.b * dword_105BA000[v12->m_Lighting.exponent]) * v14)
                       + color[2];
            }
            ++v11;
            colora = (float *)((char *)colora - 1);
          }
          while ( colora != nullptr );
        }
      }
    }
    ((void (__thiscall *)(IVEngineClient *, float *))engine->LinearToGamma)(a1: engine, a2: color);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CAEB0
// Name: public: void CDetailModel::UpdatePlayerAvoid(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CDetailModel::UpdatePlayerAvoid(CDetailModel *this@<ecx>, float a2@<ebp>)
{
  int v2; // esi
  float m_fValue; // xmm0_4
  __int64 v4; // xmm1_8
  Vector *p_m_Origin; // edi
  float z; // ecx
  void (__thiscall *EnumerateElementsInSphere)(ISpatialPartition *, int, const Vector *, float, bool, IPartitionEnumerator *); // edx
  int v8; // eax
  C_BasePlayer *LocalPlayer; // eax
  unsigned int v10; // ecx
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  __int128 v14; // xmm0
  float v15; // xmm0_4
  float v16; // xmm0_4
  float y; // xmm4_4
  float v18; // ecx
  int v19; // eax
  __int128 v20; // xmm1
  float v21; // xmm0_4
  __int128 v22; // xmm0
  float x; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  int v26; // eax
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  int v30; // eax
  float v31; // xmm1_4
  float v32; // xmm1_4
  float v33[2]; // [esp+14h] [ebp-94h] BYREF
  _BYTE v34[48]; // [esp+1Ch] [ebp-8Ch] OVERLAPPED BYREF
  float v35[6]; // [esp+4Ch] [ebp-5Ch]
  Vector v36; // [esp+64h] [ebp-44h] BYREF
  Vector vecMaxAvoid; // [esp+70h] [ebp-38h] BYREF
  Vector vecAvoid; // [esp+7Ch] [ebp-2Ch]
  float flRecoverSpeed; // [esp+88h] [ebp-20h]
  int v40; // [esp+8Ch] [ebp-1Ch]
  float v41; // [esp+90h] [ebp-18h]
  float flRadius; // [esp+94h] [ebp-14h]
  int c; // [esp+98h] [ebp-10h]
  float flMaxForce; // [esp+9Ch] [ebp-Ch]
  float flForce; // [esp+A0h] [ebp-8h]
  float retaddr; // [esp+A8h] [ebp+0h]

  flMaxForce = a2;
  flForce = retaddr;
  flRadius = cl_detail_avoid_force.m_pParent->m_Value.m_fValue;
  LODWORD(vecAvoid.y) = this;
  if ( flRadius >= 0.1 )
  {
    v2 = 0;
    if ( this->m_pAdvInfo != nullptr )
    {
      m_fValue = cl_detail_avoid_radius.m_pParent->m_Value.m_fValue;
      vecAvoid.x = cl_detail_avoid_recover_speed.m_pParent->m_Value.m_fValue;
      v41 = 0.0;
      memset((void *)&v36, 0, sizeof(v36));
      v4 = *(_QWORD *)&this->m_Origin.x;
      p_m_Origin = &this->m_Origin;
      z = this->m_Origin.z;
      *(_QWORD *)&vecMaxAvoid.x = v4;
      v33[1] = m_fValue * m_fValue;
      vecMaxAvoid.z = z;
      *(_QWORD *)v34 = v4;
      LODWORD(v33[0]) = &CPlayerEnumerator::`vftable';
      memset(&v34[12], 0, 20);
      *(float *)&v34[8] = z;
      EnumerateElementsInSphere = partition->EnumerateElementsInSphere;
      flRecoverSpeed = m_fValue;
      ((void (__thiscall *)(ISpatialPartition *, int, Vector *, _DWORD, _DWORD, float *))EnumerateElementsInSphere)(
        a1: partition,
        a2: 4,
        a3: p_m_Origin,
        a4: LODWORD(m_fValue),
        a5: 0,
        a6: v33);
      v8 = *(_DWORD *)&v34[24];
      v40 = *(_DWORD *)&v34[24];
      LODWORD(vecAvoid.z) = *(_DWORD *)&v34[24] + 1;
      if ( *(_DWORD *)&v34[24] + 1 > 0 )
      {
        while ( 1 )
        {
          if ( v2 == v40 )
          {
            LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
            if ( LocalPlayer == nullptr )
              goto LABEL_26;
          }
          else if ( v2 < 0
                 || v2 >= v8
                 || (v10 = *(_DWORD *)(*(_DWORD *)&v34[12] + 4 * v2)) == -1
                 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          {
            LocalPlayer = nullptr;
          }
          else
          {
            LocalPlayer = (C_BasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
          }
          v11 = (float *)LocalPlayer->GetAbsOrigin(this: LocalPlayer);
          v12 = p_m_Origin->y - v11[1];
          v13 = 0.0;
          vecMaxAvoid.x = p_m_Origin->x - *v11;
          vecMaxAvoid.y = v12;
          v14 = 0;
          vecMaxAvoid.z = 0.0;
          *(float *)&v14 = fsqrt((float)(v12 * v12) + (float)(vecMaxAvoid.x * vecMaxAvoid.x));
          *(_OWORD *)v35 = v14;
          if ( *(float *)&v14 <= flRecoverSpeed )
          {
            if ( flRecoverSpeed == 0.0 )
            {
              if ( (float)(*(float *)&v14 - 0.0) < 0.0 )
                v15 = flRadius;
              else
                v15 = 0.0;
            }
            else
            {
              v16 = *(float *)&v14 / flRecoverSpeed;
              if ( v16 >= 0.0 )
              {
                v13 = 1.0;
                if ( v16 <= 1.0 )
                  v13 = v16;
              }
              v15 = (float)(COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_) * v13) + flRadius;
            }
            *(float *)&c = v15;
            if ( v15 > v41 )
            {
              v41 = v15;
              VectorNormalize(vec: &vecMaxAvoid);
              vecMaxAvoid.x = vecMaxAvoid.x * *(float *)&c;
              vecMaxAvoid.y = vecMaxAvoid.y * *(float *)&c;
              vecMaxAvoid.z = *(float *)&c * vecMaxAvoid.z;
              v36 = vecMaxAvoid;
            }
          }
LABEL_26:
          if ( ++v2 >= SLODWORD(vecAvoid.z) )
            break;
          v8 = *(_DWORD *)&v34[24];
        }
      }
      y = v36.y;
      v18 = vecAvoid.y;
      v19 = *(_DWORD *)(LODWORD(vecAvoid.y) + 44);
      v20 = 0;
      v21 = *(float *)(v19 + 112);
      *(float *)&v20 = fsqrt((float)(y * y) + (float)(v36.x * v36.x));
      *(_OWORD *)v35 = v20;
      *(float *)&v20 = (float)(*(float *)(v19 + 108) * *(float *)(v19 + 108)) + (float)(v21 * v21);
      v22 = 0;
      *(float *)&v22 = fsqrt(*(float *)&v20);
      *(_OWORD *)&v34[32] = v22;
      if ( v35[0] <= *(float *)&v22 )
        x = vecAvoid.x;
      else
        x = 10.0;
      v24 = *(float *)(v19 + 108);
      if ( (float)(v36.x - v24) <= x )
      {
        if ( (float)-x <= (float)(v36.x - v24) )
          v25 = v36.x;
        else
          v25 = v24 - x;
      }
      else
      {
        v25 = v24 + x;
      }
      *(float *)(v19 + 108) = v25;
      v26 = *(_DWORD *)(LODWORD(v18) + 44);
      v27 = *(float *)(v26 + 112);
      if ( (float)(y - v27) <= x )
      {
        if ( (float)-x <= (float)(y - v27) )
          v28 = y;
        else
          v28 = v27 - x;
      }
      else
      {
        v28 = v27 + x;
      }
      v29 = v36.z;
      *(float *)(v26 + 112) = v28;
      v30 = *(_DWORD *)(LODWORD(v18) + 44);
      v31 = *(float *)(v30 + 116);
      if ( (float)(v29 - v31) <= x )
      {
        if ( (float)-x <= (float)(v29 - v31) )
          v32 = v29;
        else
          v32 = v31 - x;
      }
      else
      {
        v32 = v31 + x;
      }
      *(float *)(v30 + 116) = v32;
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v34[12]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB260
// Name: public: CDetailObjectSystem::CDetailObjectSystem(void)
// Source: json
//------------------------------------------------------------------------------
CDetailObjectSystem *__thiscall CDetailObjectSystem::CDetailObjectSystem(CDetailObjectSystem *this)
{
  CDetailObjectSystem::DetailModelDict_t *v2; // eax
  DetailPropSpriteDict_t *v3; // eax
  DetailPropSpriteDict_t *v4; // eax

  this->__vftable = (CDetailObjectSystem_vtbl *)&CDetailObjectSystem::`vftable';
  this->m_DetailObjectDict.m_Memory.m_pMemory = nullptr;
  this->m_DetailObjectDict.m_Memory.m_nAllocationCount = 32;
  this->m_DetailObjectDict.m_Memory.m_nGrowSize = 0;
  v2 = (CDetailObjectSystem::DetailModelDict_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  this->m_DetailObjectDict.m_Memory.m_pMemory = v2;
  this->m_DetailObjectDict.m_pElements = v2;
  this->m_DetailObjectDict.m_Size = 0;
  this->m_DetailObjects.m_Memory.m_pMemory = nullptr;
  this->m_DetailObjects.m_Memory.m_nAllocationCount = 0;
  this->m_DetailObjects.m_Memory.m_nGrowSize = 0;
  this->m_DetailObjects.m_Size = 0;
  this->m_DetailObjects.m_pElements = nullptr;
  this->m_DetailSpriteDict.m_Memory.m_pMemory = nullptr;
  this->m_DetailSpriteDict.m_Memory.m_nAllocationCount = 32;
  this->m_DetailSpriteDict.m_Memory.m_nGrowSize = 0;
  v3 = (DetailPropSpriteDict_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1024);
  this->m_DetailSpriteDict.m_Memory.m_pMemory = v3;
  this->m_DetailSpriteDict.m_pElements = v3;
  this->m_DetailSpriteDict.m_Size = 0;
  this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory = nullptr;
  this->m_DetailSpriteDictFlipped.m_Memory.m_nAllocationCount = 32;
  this->m_DetailSpriteDictFlipped.m_Memory.m_nGrowSize = 0;
  v4 = (DetailPropSpriteDict_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1024);
  this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory = v4;
  this->m_DetailSpriteDictFlipped.m_Size = 0;
  this->m_DetailSpriteDictFlipped.m_pElements = v4;
  this->m_DetailLighting.m_Memory.m_pMemory = nullptr;
  this->m_DetailLighting.m_Memory.m_nAllocationCount = 0;
  this->m_DetailLighting.m_Memory.m_nGrowSize = 0;
  this->m_DetailLighting.m_Size = 0;
  this->m_DetailLighting.m_pElements = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_DetailSpriteMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_DetailWireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_pFastSpriteData = nullptr;
  this->m_pSortInfo = nullptr;
  this->m_pFastSortInfo = nullptr;
  this->m_pBuildoutBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CB340
// Name: public: virtual char const __near * CDetailObjectSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDetailObjectSystem::Name(CDetailObjectSystem *this)
{
  return "DetailObjectSystem";
}

//------------------------------------------------------------------------------
// Address: 0x100CB350
// Name: public: virtual bool CDetailObjectSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDetailObjectSystem::Init(CDetailObjectSystem *this)
{
  this->m_flDetailFadeStart = 0.0;
  this->m_flDetailFadeEnd = 0.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CB370
// Name: public: virtual CDetailObjectSystem::~CDetailObjectSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::~CDetailObjectSystem(CDetailObjectSystem *this)
{
  FastSpriteX4_t *m_pFastSpriteData; // eax

  m_pFastSpriteData = this->m_pFastSpriteData;
  this->__vftable = (CDetailObjectSystem_vtbl *)&CDetailObjectSystem::`vftable';
  if ( m_pFastSpriteData != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pFastSpriteData & 0xFFFFFFFC) - 4));
    this->m_pFastSpriteData = nullptr;
  }
  CDetailObjectSystem::FreeSortBuffers(this);
  CMaterialReference::~CMaterialReference(this: &this->m_DetailWireframeMaterial);
  CMaterialReference::~CMaterialReference(this: &this->m_DetailSpriteMaterial);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DetailLighting);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DetailSpriteDictFlipped);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DetailSpriteDict);
  CUtlVector<CDetailModel,CUtlMemory<CDetailModel,int>>::Purge(this: &this->m_DetailObjects);
  if ( this->m_DetailObjects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DetailObjects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DetailObjects.m_Memory.m_pMemory);
      this->m_DetailObjects.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailObjects.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DetailObjectDict);
  IGameSystem::~IGameSystem(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CB420
// Name: private: void CDetailObjectSystem::UnserializeModelDict(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::UnserializeModelDict(CDetailObjectSystem *this, CUtlBuffer *buf)
{
  signed int Int; // edi
  CDetailObjectSystem::DetailModelDict_t *m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  CDetailObjectSystem::DetailModelDict_t *v6; // eax
  const struct model_t *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDetailObjectSystem::DetailModelDict_t *v10; // ecx
  int v11; // eax
  CDetailObjectSystem::DetailModelDict_t *v12; // eax
  DetailObjectDictLump_t lump; // [esp+Ch] [ebp-84h] BYREF
  int count; // [esp+8Ch] [ebp-4h]

  Int = CUtlBuffer::GetInt(this: buf);
  if ( this->m_DetailObjectDict.m_Memory.m_nAllocationCount < Int && this->m_DetailObjectDict.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_DetailObjectDict.m_Memory.m_pMemory;
    this->m_DetailObjectDict.m_Memory.m_nAllocationCount = Int;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (CDetailObjectSystem::DetailModelDict_t *)((int (__stdcall *)(CDetailObjectSystem::DetailModelDict_t *, int))v5->Realloc_2)(
                                                       a1: m_pMemory,
                                                       a2: 4 * Int);
    else
      v6 = (CDetailObjectSystem::DetailModelDict_t *)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * Int);
    this->m_DetailObjectDict.m_Memory.m_pMemory = v6;
  }
  this->m_DetailObjectDict.m_pElements = this->m_DetailObjectDict.m_Memory.m_pMemory;
  for ( count = Int - 1; count >= 0; --count )
  {
    CUtlBuffer::Get(this: buf, pMem: (unsigned __int8 *)&lump, size: 128);
    v7 = engine->LoadModel(this: engine, a2: &lump, a3: 1);
    if ( modelinfo->IsModelVertexLit(this: modelinfo, a2: v7) )
    {
      _Warning(a1: "Detail prop model %s is using vertex-lit materials!\nIt must use unlit materials!\n", lump.m_Name);
      v7 = engine->LoadModel(this: engine, a2: "models/error.mdl", a3: 0);
    }
    m_Size = this->m_DetailObjectDict.m_Size;
    m_nAllocationCount = this->m_DetailObjectDict.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_DetailObjectDict,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_DetailObjectDict.m_Size;
    v10 = this->m_DetailObjectDict.m_Memory.m_pMemory;
    v11 = this->m_DetailObjectDict.m_Size - m_Size - 1;
    this->m_DetailObjectDict.m_pElements = v10;
    if ( v11 > 0 )
      _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 4 * v11);
    v12 = &this->m_DetailObjectDict.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      v12->m_pModel = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB560
// Name: private: void CDetailObjectSystem::UnserializeDetailSprites(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::UnserializeDetailSprites(CDetailObjectSystem *this, CUtlBuffer *buf)
{
  CDetailObjectSystem *v2; // esi
  signed int Int; // ebx
  CUtlMemory<vgui::RichText::TFormatStream,int> *p_m_DetailSpriteDict; // edi
  vgui::RichText::TFormatStream *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  int v7; // eax
  bool v8; // zf
  DetailPropSpriteDict_t *v9; // eax
  int v10; // ebx
  int m_nAllocationCount; // eax
  vgui::RichText::TFormatStream *v12; // ecx
  int v13; // eax
  int m_Size; // ebx
  int v15; // eax
  DetailPropSpriteDict_t *v16; // ecx
  int v17; // eax
  float *p_color; // ecx
  DetailPropSpriteDict_t *v19; // eax
  int v20; // ebx
  float *p_x; // eax
  bool v22; // sf
  int v23; // xmm0_4
  unsigned int v24; // [esp-4h] [ebp-18h]
  int v25; // [esp+Ch] [ebp-8h]
  int counta; // [esp+10h] [ebp-4h]

  v2 = this;
  Int = CUtlBuffer::GetInt(this: buf);
  p_m_DetailSpriteDict = (CUtlMemory<vgui::RichText::TFormatStream,int> *)&v2->m_DetailSpriteDict;
  if ( v2->m_DetailSpriteDict.m_Memory.m_nAllocationCount < Int && v2->m_DetailSpriteDict.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_DetailSpriteDict->m_pMemory;
    v2->m_DetailSpriteDict.m_Memory.m_nAllocationCount = Int;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
    {
      v7 = ((int (__stdcall *)(vgui::RichText::TFormatStream *, int))v6->Realloc_2)(a1: m_pMemory, a2: 32 * Int);
      v2 = this;
    }
    else
    {
      v7 = ((int (__stdcall *)(int))v6->Alloc_2)(a1: 32 * Int);
    }
    p_m_DetailSpriteDict->m_pMemory = (vgui::RichText::TFormatStream *)v7;
  }
  p_m_DetailSpriteDict[1].m_nAllocationCount = (int)p_m_DetailSpriteDict->m_pMemory;
  if ( v2->m_DetailSpriteDictFlipped.m_Memory.m_nAllocationCount < Int
    && v2->m_DetailSpriteDictFlipped.m_Memory.m_nGrowSize >= 0 )
  {
    v8 = v2->m_DetailSpriteDictFlipped.m_Memory.m_pMemory == nullptr;
    v2->m_DetailSpriteDictFlipped.m_Memory.m_nAllocationCount = Int;
    v24 = 32 * Int;
    if ( v8 )
      v9 = (DetailPropSpriteDict_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v24);
    else
      v9 = (DetailPropSpriteDict_t *)_g_pMemAlloc->Realloc_2(
                                       this: _g_pMemAlloc,
                                       a2: v2->m_DetailSpriteDictFlipped.m_Memory.m_pMemory,
                                       a3: v24);
    v2->m_DetailSpriteDictFlipped.m_Memory.m_pMemory = v9;
  }
  v2->m_DetailSpriteDictFlipped.m_pElements = v2->m_DetailSpriteDictFlipped.m_Memory.m_pMemory;
  counta = Int - 1;
  if ( Int - 1 >= 0 )
  {
    do
    {
      v10 = (int)p_m_DetailSpriteDict[1].m_pMemory;
      m_nAllocationCount = p_m_DetailSpriteDict->m_nAllocationCount;
      if ( v10 + 1 > m_nAllocationCount )
        CUtlMemory<DetailPropSpriteDict_t,int>::Grow(this: p_m_DetailSpriteDict, num: v10 - m_nAllocationCount + 1);
      ++p_m_DetailSpriteDict[1].m_pMemory;
      v12 = p_m_DetailSpriteDict->m_pMemory;
      v13 = (int)p_m_DetailSpriteDict[1].m_pMemory - v10 - 1;
      p_m_DetailSpriteDict[1].m_nAllocationCount = (int)p_m_DetailSpriteDict->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 32 * v13);
      v25 = v10;
      CUtlBuffer::Get(this: buf, pMem: (unsigned __int8 *)&p_m_DetailSpriteDict->m_pMemory[v10].color, size: 32);
      m_Size = v2->m_DetailSpriteDictFlipped.m_Size;
      v15 = v2->m_DetailSpriteDictFlipped.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > v15 )
        CUtlMemory<DetailPropSpriteDict_t,int>::Grow(
          this: (CUtlMemory<vgui::RichText::TFormatStream,int> *)&v2->m_DetailSpriteDictFlipped,
          num: m_Size - v15 + 1);
      ++v2->m_DetailSpriteDictFlipped.m_Size;
      v16 = v2->m_DetailSpriteDictFlipped.m_Memory.m_pMemory;
      v17 = v2->m_DetailSpriteDictFlipped.m_Size - m_Size - 1;
      v2->m_DetailSpriteDictFlipped.m_pElements = v16;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 32 * v17);
      p_color = (float *)&p_m_DetailSpriteDict->m_pMemory[v25].color;
      v19 = v2->m_DetailSpriteDictFlipped.m_Memory.m_pMemory;
      v20 = m_Size;
      v19[v20].m_UL.x = *p_color;
      p_x = &v19[v20].m_UL.x;
      v22 = --counta < 0;
      p_x[1] = p_color[1];
      p_x[2] = p_color[2];
      p_x[3] = p_color[3];
      p_x[4] = p_color[4];
      p_x[5] = p_color[5];
      p_x[6] = p_color[6];
      p_x[7] = p_color[7];
      v23 = *((_DWORD *)p_x + 4);
      p_x[4] = p_x[6];
      *((_DWORD *)p_x + 6) = v23;
    }
    while ( !v22 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB710
// Name: private: void CDetailObjectSystem::UnserializeModelLighting(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::UnserializeModelLighting(CDetailObjectSystem *this, CUtlBuffer *buf)
{
  signed int Int; // ebx
  DetailPropLightstylesLump_t *m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  DetailPropLightstylesLump_t *v6; // eax
  int v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DetailPropLightstylesLump_t *v10; // ecx
  int v11; // eax

  Int = CUtlBuffer::GetInt(this: buf);
  if ( this->m_DetailLighting.m_Memory.m_nAllocationCount < Int && this->m_DetailLighting.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_DetailLighting.m_Memory.m_pMemory;
    this->m_DetailLighting.m_Memory.m_nAllocationCount = Int;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (DetailPropLightstylesLump_t *)((int (__stdcall *)(DetailPropLightstylesLump_t *, int))v5->Realloc_2)(
                                            a1: m_pMemory,
                                            a2: 5 * Int);
    else
      v6 = (DetailPropLightstylesLump_t *)((int (__stdcall *)(int))v5->Alloc_2)(a1: 5 * Int);
    this->m_DetailLighting.m_Memory.m_pMemory = v6;
  }
  v7 = Int - 1;
  for ( this->m_DetailLighting.m_pElements = this->m_DetailLighting.m_Memory.m_pMemory; v7 >= 0; --v7 )
  {
    m_Size = this->m_DetailLighting.m_Size;
    m_nAllocationCount = this->m_DetailLighting.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<DetailPropLightstylesLump_t,int>::Grow(
        this: &this->m_DetailLighting.m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_DetailLighting.m_Size;
    v10 = this->m_DetailLighting.m_Memory.m_pMemory;
    v11 = this->m_DetailLighting.m_Size - m_Size - 1;
    this->m_DetailLighting.m_pElements = v10;
    if ( v11 > 0 )
      _V_memmove(
        dest: (char *)&v10[1].m_Lighting + 4 * m_Size + m_Size,
        src: (char *)&v10->m_Lighting + 4 * m_Size + m_Size,
        count: 5 * v11);
    CUtlBuffer::Get(
      this: buf,
      pMem: (unsigned __int8 *)&this->m_DetailLighting.m_Memory.m_pMemory[m_Size].m_Lighting,
      size: 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB7D0
// Name: private: void CDetailObjectSystem::ScanForCounts(class CUtlBuffer __near &,int __near *,int __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::ScanForCounts(
        CDetailObjectSystem *this,
        CUtlBuffer *buf,
        int *pNumOldStyleObjects,
        int *pNumFastSpritesToAllocate,
        int *nMaxNumOldSpritesInLeaf,
        int *nMaxNumFastSpritesInLeaf)
{
  int v6; // esi
  int v7; // edi
  int m_Leaf; // ebx
  int v9; // ecx
  int m_nValue; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // ecx
  int v14; // ecx
  DetailObjectLump_t lump; // [esp+Ch] [ebp-4Ch] BYREF
  int oldpos; // [esp+40h] [ebp-18h]
  int count; // [esp+44h] [ebp-14h]
  int nOld; // [esp+48h] [ebp-10h]
  int nMaxFast; // [esp+4Ch] [ebp-Ch]
  int nMaxOld; // [esp+50h] [ebp-8h]
  int nNumOldInLeaf; // [esp+54h] [ebp-4h]

  v6 = 0;
  oldpos = buf->m_Get;
  nOld = 0;
  v7 = 0;
  m_Leaf = -1;
  nNumOldInLeaf = 0;
  nMaxOld = 0;
  nMaxFast = 0;
  for ( count = CUtlBuffer::GetInt(this: buf) - 1; count >= 0; --count )
  {
    CUtlBuffer::Get(this: buf, pMem: (unsigned __int8 *)&lump, size: 52);
    if ( m_Leaf != lump.m_Leaf )
    {
      v7 += -v7 & 3;
      if ( nMaxFast <= v6 )
        nMaxFast = v6;
      if ( nMaxOld <= nNumOldInLeaf )
        nMaxOld = nNumOldInLeaf;
      v6 = 0;
      nNumOldInLeaf = 0;
      m_Leaf = lump.m_Leaf;
    }
    if ( cl_fastdetailsprites.m_pParent == nullptr
      || cl_fastdetailsprites.m_pParent->m_Value.m_nValue == 0
      || lump.m_Type != 1
      || lump.m_LightStyleCount != 0
      || lump.m_Orientation != 2
      || lump.m_ShapeAngle != 0
      || lump.m_ShapeSize != 0
      || lump.m_SwayAmount != 0 )
    {
      if ( cl_detail_multiplier.m_pParent != nullptr )
        m_nValue = cl_detail_multiplier.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      nOld += m_nValue;
      if ( cl_detail_multiplier.m_pParent != nullptr )
        v11 = cl_detail_multiplier.m_pParent->m_Value.m_nValue;
      else
        v11 = 0;
      nNumOldInLeaf += v11;
    }
    else
    {
      if ( cl_detail_multiplier.m_pParent != nullptr )
        v9 = cl_detail_multiplier.m_pParent->m_Value.m_nValue;
      else
        v9 = 0;
      v7 += v9;
      if ( cl_detail_multiplier.m_pParent != nullptr )
        v6 += cl_detail_multiplier.m_pParent->m_Value.m_nValue;
    }
  }
  v12 = (-v7 & 3) + v7;
  if ( nMaxFast <= v6 )
    nMaxFast = v6;
  if ( nMaxOld <= nNumOldInLeaf )
    nMaxOld = nNumOldInLeaf;
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: oldpos);
  v13 = nOld;
  *pNumFastSpritesToAllocate = v12;
  *pNumOldStyleObjects = v13;
  v14 = nMaxFast;
  *nMaxNumOldSpritesInLeaf = nMaxOld;
  *nMaxNumFastSpritesInLeaf = (v14 + 3) & 0xFFFFFFFC;
}

//------------------------------------------------------------------------------
// Address: 0x100CBA70
// Name: public: void CDetailModel::DrawTypeSprite(class CMeshBuilder __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailModel::DrawTypeSprite(CDetailModel *this, CMeshBuilder *meshBuilder, unsigned __int8 nAlpha)
{
  int m_nSpriteIndex; // edi
  int v5; // ebx
  DetailPropSpriteDict_t *v6; // edi
  double v7; // st7
  bool v8; // zf
  float z; // xmm5_4
  float y; // xmm6_4
  float x; // xmm7_4
  double v12; // st7
  DetailModelAdvInfo_t *m_pAdvInfo; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  __m128 v17; // xmm0
  double v18; // xmm0_8
  float v19; // xmm3_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  float v26; // xmm7_4
  float v27; // xmm0_4
  float *m_pCurrPosition; // eax
  float v29; // xmm4_4
  float v30; // xmm1_4
  int v31; // ecx
  int v32; // edx
  int v33; // edi
  float *v34; // eax
  float v35; // xmm0_4
  float *v36; // eax
  float v37; // xmm1_4
  float v38; // xmm2_4
  unsigned __int8 *m_pCurrColor; // ecx
  float *v40; // eax
  float *m_pCurrNormal; // eax
  float *v42; // eax
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  unsigned __int8 *v46; // edx
  float *v47; // eax
  float *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  float *v52; // eax
  Vector *v53; // esi
  Vector vecColor; // [esp+Ch] [ebp-64h] BYREF
  Vector dz; // [esp+18h] [ebp-58h] BYREF
  Vector vecSway; // [esp+24h] [ebp-4Ch]
  Vector dy; // [esp+30h] [ebp-40h] BYREF
  Vector right; // [esp+3Ch] [ebp-34h] BYREF
  Vector vecOrigin; // [esp+48h] [ebp-28h]
  Vector2D lr; // [esp+54h] [ebp-1Ch]
  Vector2D ul; // [esp+5Ch] [ebp-14h]
  float flSwayAmplitude; // [esp+64h] [ebp-Ch]
  float v63; // [esp+68h] [ebp-8h]
  unsigned __int8 color[4]; // [esp+6Ch] [ebp-4h]
  int savedregs; // [esp+70h] [ebp+0h] BYREF

  this->GetColorModulation(this: &this->IClientRenderable, a2: (float *)&vecColor);
  m_nSpriteIndex = this->m_SpriteInfo.m_nSpriteIndex;
  v5 = (int)(float)(vecColor.x * 255.0);
  color[1] = (int)(float)(vecColor.y * 255.0);
  color[2] = (int)(float)(vecColor.z * 255.0);
  v6 = &s_DetailObjectSystem.m_DetailSpriteDict.m_Memory.m_pMemory[m_nSpriteIndex];
  AngleVectors(angles: &this->m_Angles, forward: &dz, &right, up: &dy);
  v7 = float16::Convert16bitFloatTo32bits(input: this->m_SpriteInfo.m_flScale.m_storage.rawWord);
  ul.x = v6->m_UL.x * v7;
  ul.y = v6->m_UL.y * v7;
  lr.x = v6->m_LR.x * v7;
  lr.y = v7 * v6->m_LR.y;
  CDetailModel::UpdatePlayerAvoid(this, a2: COERCE_FLOAT(&savedregs));
  v8 = this->m_pAdvInfo == nullptr;
  z = right.z;
  y = right.y;
  x = right.x;
  vecSway = vec3_origin;
  if ( !v8 )
  {
    v12 = float16::Convert16bitFloatTo32bits(input: this->m_SpriteInfo.m_flScale.m_storage.rawWord);
    m_pAdvInfo = this->m_pAdvInfo;
    v63 = v12;
    v14 = m_pAdvInfo->m_vecCurrentAvoid.y;
    v15 = m_pAdvInfo->m_vecCurrentAvoid.z;
    vecOrigin.x = v63 * m_pAdvInfo->m_vecCurrentAvoid.x;
    vecSway.x = vecOrigin.x;
    v16 = m_pAdvInfo->m_flSwayAmount * cl_detail_max_sway.m_pParent->m_Value.m_fValue;
    vecOrigin.y = v14 * v63;
    vecOrigin.z = v15 * v63;
    vecSway.y = v14 * v63;
    vecSway.z = v15 * v63;
    v63 = v16;
    if ( v16 <= 0.0 )
    {
      z = right.z;
      y = right.y;
      x = right.x;
    }
    else
    {
      v17 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      v17.m128_f32[0] = v17.m128_f32[0] + this->m_Origin.x;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v17));
      x = right.x;
      y = right.y;
      z = right.z;
      v19 = v18;
      vecSway.x = (float)((float)(right.x * v19) * v63) + vecOrigin.x;
      vecSway.y = (float)((float)(right.y * v19) * v63) + vecOrigin.y;
      vecSway.z = (float)((float)(right.z * v19) * v63) + vecOrigin.z;
    }
  }
  v8 = (*((_BYTE *)this + 36) & 0x20) == 0;
  v20 = (float)(dy.x * ul.y) + (float)((float)(x * ul.x) + this->m_Origin.x);
  v21 = (float)(dy.y * ul.y) + (float)((float)(y * ul.x) + this->m_Origin.y);
  v22 = (float)(dy.z * ul.y) + (float)((float)(z * ul.x) + this->m_Origin.z);
  dy.x = dy.x * (float)(lr.y - ul.y);
  dy.y = dy.y * (float)(lr.y - ul.y);
  right.x = x * (float)(lr.x - ul.x);
  right.y = y * (float)(lr.x - ul.x);
  right.z = z * (float)(lr.x - ul.x);
  dy.z = dy.z * (float)(lr.y - ul.y);
  v23 = v6->m_TexUL.x;
  v24 = v6->m_TexUL.y;
  v25 = v6->m_TexLR.x;
  v26 = v6->m_TexLR.y;
  v27 = v23;
  vecOrigin.x = v20;
  vecOrigin.y = v21;
  vecOrigin.z = v22;
  flSwayAmplitude = v23;
  v63 = v24;
  ul.x = v25;
  ul.y = v26;
  if ( v8 )
  {
    v27 = v25;
    flSwayAmplitude = v25;
    ul.x = v23;
  }
  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v29 = v21 + vecSway.y;
  v30 = v22 + vecSway.z;
  v31 = color[1];
  v32 = color[2];
  *m_pCurrPosition = v20 + vecSway.x;
  m_pCurrPosition[1] = v29;
  m_pCurrPosition[2] = v30;
  v33 = v32 | ((v31 | (((unsigned __int8)v5 | (nAlpha << 8)) << 8)) << 8);
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = v33;
  v34 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  *v34 = v27;
  v34[1] = v24;
  *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrNormal = dz;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v35 = dy.x + vecOrigin.x;
  v36 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v37 = dy.y + vecOrigin.y;
  v38 = dy.z + vecOrigin.z;
  m_pCurrColor = meshBuilder->m_VertexBuilder.m_pCurrColor;
  *v36 = dy.x + vecOrigin.x;
  v36[1] = v37;
  v36[2] = v38;
  *(_DWORD *)m_pCurrColor = v33;
  v40 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  vecOrigin.x = v35;
  *v40 = flSwayAmplitude;
  v40[1] = ul.y;
  m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
  *m_pCurrNormal = dz.x;
  m_pCurrNormal[1] = dz.y;
  vecOrigin.y = v37;
  vecOrigin.z = v38;
  m_pCurrNormal[2] = dz.z;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v42 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v43 = vecOrigin.x + right.x;
  v44 = vecOrigin.y + right.y;
  v45 = vecOrigin.z + right.z;
  v46 = meshBuilder->m_VertexBuilder.m_pCurrColor;
  *v42 = vecOrigin.x + right.x;
  v42[1] = v44;
  v42[2] = v45;
  *(_DWORD *)v46 = v33;
  v47 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  vecOrigin.x = v43;
  *v47 = ul.x;
  vecOrigin.y = v44;
  vecOrigin.z = v45;
  v47[1] = ul.y;
  *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrNormal = dz;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v48 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v49 = (float)(vecOrigin.y - dy.y) + vecSway.y;
  v50 = (float)(vecOrigin.z - dy.z) + vecSway.z;
  *v48 = (float)(vecOrigin.x - dy.x) + vecSway.x;
  v51 = ul.x;
  v48[1] = v49;
  v48[2] = v50;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = v33;
  v52 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  v53 = (Vector *)meshBuilder->m_VertexBuilder.m_pCurrNormal;
  *v52 = v51;
  v52[1] = v63;
  *v53 = dz;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x100CBF70
// Name: public: void CDetailModel::DrawTypeShapeCross(class CMeshBuilder __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailModel::DrawTypeShapeCross(CDetailModel *this, CMeshBuilder *meshBuilder, unsigned __int8 nAlpha)
{
  DetailPropSpriteDict_t *v4; // edi
  bool v5; // zf
  float x; // xmm2_4
  float y; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  DetailModelAdvInfo_t *m_pAdvInfo; // eax
  float z; // xmm3_4
  float v15; // xmm2_4
  float m_flSwayAmount; // xmm1_4
  float v17; // xmm1_4
  __m128 v18; // xmm0
  DetailModelAdvInfo_t *v19; // eax
  double v20; // xmm0_8
  Vector *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  DetailModelAdvInfo_t *v24; // eax
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  const Vector *v35; // eax
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  Vector v40; // [esp-10h] [ebp-C0h]
  unsigned __int16 yaw; // [esp+4h] [ebp-ACh]
  Vector vecColor; // [esp+10h] [ebp-A0h] BYREF
  Vector forward; // [esp+1Ch] [ebp-94h]
  unsigned __int64 v44; // [esp+28h] [ebp-88h]
  float v45; // [esp+30h] [ebp-80h]
  __int64 v46; // [esp+34h] [ebp-7Ch]
  float v47; // [esp+3Ch] [ebp-74h]
  float flSwayAmplitude; // [esp+40h] [ebp-70h]
  float flSizeY; // [esp+44h] [ebp-6Ch]
  Vector right; // [esp+48h] [ebp-68h] BYREF
  Vector2D texumid; // [esp+54h] [ebp-5Ch]
  Vector up; // [esp+5Ch] [ebp-54h]
  Vector vecOrigin; // [esp+68h] [ebp-48h]
  unsigned __int64 v54; // [esp+74h] [ebp-3Ch]
  float v55; // [esp+7Ch] [ebp-34h]
  float v56; // [esp+80h] [ebp-30h]
  Vector2D ul; // [esp+84h] [ebp-2Ch]
  Vector2D texul; // [esp+8Ch] [ebp-24h]
  Vector2D texlr; // [esp+94h] [ebp-1Ch]
  int v60; // [esp+9Ch] [ebp-14h]
  Vector vecSway; // [esp+A0h] [ebp-10h]
  unsigned __int8 color[4]; // [esp+ACh] [ebp-4h] BYREF
  int savedregs; // [esp+B0h] [ebp+0h] BYREF
  float iBranchb; // [esp+BCh] [ebp+Ch]
  int iBranch; // [esp+BCh] [ebp+Ch]
  int iBrancha; // [esp+BCh] [ebp+Ch]
  Vector v67; // 0:^3C.12

  this->GetColorModulation(this: &this->IClientRenderable, a2: (float *)&vecColor);
  v4 = &s_DetailObjectSystem.m_DetailSpriteDict.m_Memory.m_pMemory[this->m_SpriteInfo.m_nSpriteIndex];
  v5 = this->m_pModel == nullptr;
  x = v4->m_TexUL.x;
  y = v4->m_TexLR.y;
  v8 = v4->m_TexUL.y;
  color[0] = (int)(float)(vecColor.x * 255.0);
  texul.y = v8;
  v9 = v4->m_TexLR.x;
  v10 = x;
  color[1] = (int)(float)(vecColor.y * 255.0);
  color[2] = (int)(float)(vecColor.z * 255.0);
  color[3] = nAlpha;
  texul.x = x;
  texlr.x = v9;
  texlr.y = y;
  if ( v5 )
  {
    v10 = v9;
    v9 = x;
    texul.x = v10;
    texlr.x = x;
  }
  yaw = this->m_SpriteInfo.m_flScale.m_storage.rawWord;
  texumid.x = (float)(v9 + v10) * 0.5;
  iBranchb = float16::Convert16bitFloatTo32bits(input: yaw);
  v11 = (float)((float)(v4->m_LR.x * iBranchb) - (float)(v4->m_UL.x * iBranchb)) * 0.5;
  v12 = (float)(v4->m_LR.y * iBranchb) - (float)(v4->m_UL.y * iBranchb);
  ul.y = v4->m_UL.y * iBranchb;
  *(float *)&iBranch = v11;
  flSizeY = v12;
  CDetailModel::UpdatePlayerAvoid(this, a2: COERCE_FLOAT(&savedregs));
  m_pAdvInfo = this->m_pAdvInfo;
  z = m_pAdvInfo->m_vecCurrentAvoid.z;
  v15 = (float)(m_pAdvInfo->m_vecCurrentAvoid.y * v11) * 2.0;
  vecSway.x = (float)(m_pAdvInfo->m_vecCurrentAvoid.x * v11) * 2.0;
  m_flSwayAmount = m_pAdvInfo->m_flSwayAmount;
  vecSway.y = v15;
  v17 = m_flSwayAmount * cl_detail_max_sway.m_pParent->m_Value.m_fValue;
  vecSway.z = (float)(z * v11) * 2.0;
  flSwayAmplitude = v17;
  if ( v17 > 0.0 )
  {
    v18 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
    v18.m128_f32[0] = v18.m128_f32[0] + this->m_Origin.x;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v18));
    v19 = this->m_pAdvInfo;
    *(float *)&v20 = v20;
    v60 = SLODWORD(v20);
    v21 = UTIL_YawToVector(result: &right, yaw: v19->m_flSwayYaw);
    v22 = (float)((float)(v21->y * *(float *)&v60) * flSwayAmplitude) + vecSway.y;
    v23 = (float)((float)(v21->z * *(float *)&v60) * flSwayAmplitude) + vecSway.z;
    vecSway.x = (float)((float)(v21->x * *(float *)&v60) * flSwayAmplitude) + vecSway.x;
    v11 = *(float *)&iBranch;
    vecSway.y = v22;
    vecSway.z = v23;
  }
  v24 = this->m_pAdvInfo;
  v25 = v24->m_vecAnglesForward[0].z;
  vecOrigin.x = (float)(v24->m_vecAnglesUp[0].x * ul.y) + this->m_Origin.x;
  vecOrigin.y = (float)(v24->m_vecAnglesUp[0].y * ul.y) + this->m_Origin.y;
  v26 = v24->m_vecAnglesForward[0].x;
  vecOrigin.z = (float)(v24->m_vecAnglesUp[0].z * ul.y) + this->m_Origin.z;
  v27 = v24->m_vecAnglesForward[0].y * v11;
  v56 = v26 * v11;
  ul.x = v27;
  forward.x = v26 * v11;
  v28 = v24->m_vecAnglesRight[0].x;
  forward.y = v27;
  v29 = v28 * v11;
  v30 = v24->m_vecAnglesRight[0].y * v11;
  ul.y = v25 * v11;
  forward.z = v25 * v11;
  v31 = v24->m_vecAnglesRight[0].z * v11;
  v32 = v24->m_vecAnglesUp[0].x;
  v54 = __PAIR64__(LODWORD(v30), LODWORD(v29));
  right.x = v29;
  v33 = v24->m_vecAnglesUp[0].y;
  right.y = v30;
  v34 = v24->m_vecAnglesUp[0].z;
  v55 = v31;
  right.z = v31;
  up.x = v32 * flSizeY;
  up.y = v33 * flSizeY;
  up.z = v34 * flSizeY;
  v35 = CurrentViewOrigin();
  v36 = v35->x - this->m_Origin.x;
  v37 = v35->y - this->m_Origin.y;
  v38 = v35->z - this->m_Origin.z;
  if ( (float)((float)((float)(v37 * ul.x) + (float)(v36 * v56)) + (float)(v38 * ul.y)) <= 0.0 )
    iBrancha = ((float)((float)((float)(v37 * *((float *)&v54 + 1)) + (float)(v36 * *(float *)&v54)) + (float)(v38 * v55)) <= 0.0)
             + 1;
  else
    iBrancha = (float)((float)((float)(v37 * *((float *)&v54 + 1)) + (float)(v36 * *(float *)&v54)) + (float)(v38 * v55)) > 0.0
             ? 0
             : 3;
  v60 = 4;
  do
  {
    switch ( iBrancha )
    {
      case 0:
        v67 = up;
        *(float *)&v46 = -v56;
        *((float *)&v46 + 1) = -ul.x;
        v47 = -ul.y;
        *(_QWORD *)&v40.x = v46;
        v40.z = -ul.y;
        goto LABEL_14;
      case 1:
        v67 = up;
        v44 = v54 ^ 0x8000000080000000uLL;
        v45 = -v55;
        *(_QWORD *)&v40.x = v54 ^ 0x8000000080000000uLL;
        v39 = texul.x;
        v40.z = -v55;
        goto LABEL_15;
      case 2:
        v67 = up;
        v40 = forward;
        v39 = texul.x;
        goto LABEL_15;
      case 3:
        v67 = up;
        v40 = right;
LABEL_14:
        v39 = texlr.x;
LABEL_15:
        CDetailModel::DrawSwayingQuad(
          this,
          meshBuilder,
          vecOrigin,
          vecSway,
          texul: (Vector2D)__PAIR64__(LODWORD(texul.y), LODWORD(texumid.x)),
          texlr: (Vector2D)__PAIR64__(LODWORD(texlr.y), LODWORD(v39)),
          color,
          width: v40,
          height: v67);
        break;
      default:
        break;
    }
    if ( ++iBrancha > 3 )
      iBrancha = 0;
    --v60;
  }
  while ( *(float *)&v60 != 0.0 );
}

//------------------------------------------------------------------------------
// Address: 0x100CC4E0
// Name: public: void CDetailModel::DrawTypeShapeTri(class CMeshBuilder __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailModel::DrawTypeShapeTri(CDetailModel *this, CMeshBuilder *meshBuilder, unsigned __int8 nAlpha)
{
  DetailPropSpriteDict_t *v4; // esi
  bool v5; // zf
  float y; // xmm2_4
  float x; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  double v10; // st7
  const Vector *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float z; // xmm2_4
  float *m_pAdvInfo; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  bool v19; // dl
  bool v20; // cl
  bool v21; // al
  int v22; // esi
  int i; // ebx
  DetailModelAdvInfo_t *v24; // edx
  int v25; // ecx
  float v26; // xmm4_4
  unsigned int v27; // xmm0_4
  float *v28; // eax
  int v29; // ecx
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float *v33; // ecx
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm4_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float *p_x; // eax
  float v41; // xmm2_4
  __m128 v42; // xmm0
  double v43; // xmm0_8
  float v44; // xmm3_4
  DetailModelAdvInfo_t *v45; // eax
  float v46; // xmm5_4
  Vector vecSwayYaw; // [esp+14h] [ebp-70h] BYREF
  Vector vecColor; // [esp+20h] [ebp-64h] BYREF
  Vector vecOrigin; // [esp+2Ch] [ebp-58h]
  Vector vecSway; // [esp+38h] [ebp-4Ch]
  Vector vecWidth; // [esp+44h] [ebp-40h]
  Vector vecHeight; // [esp+50h] [ebp-34h]
  Vector2D texul; // [esp+5Ch] [ebp-28h]
  Vector2D texlr; // [esp+64h] [ebp-20h]
  Vector2D ul; // [esp+6Ch] [ebp-18h]
  float v56; // [esp+74h] [ebp-10h]
  float flSwayAmplitude; // [esp+78h] [ebp-Ch]
  float flHeight; // [esp+7Ch] [ebp-8h]
  unsigned __int8 color[4]; // [esp+80h] [ebp-4h] BYREF
  int savedregs; // [esp+84h] [ebp+0h] BYREF
  float flWidth; // [esp+90h] [ebp+Ch]

  this->GetColorModulation(this: &this->IClientRenderable, a2: (float *)&vecColor);
  v4 = &s_DetailObjectSystem.m_DetailSpriteDict.m_Memory.m_pMemory[this->m_SpriteInfo.m_nSpriteIndex];
  v5 = this->m_pModel == nullptr;
  y = v4->m_TexLR.y;
  x = v4->m_TexUL.x;
  v8 = v4->m_TexUL.y;
  color[0] = (int)(float)(vecColor.x * 255.0);
  texul.y = v8;
  v9 = v4->m_TexLR.x;
  color[1] = (int)(float)(vecColor.y * 255.0);
  color[2] = (int)(float)(vecColor.z * 255.0);
  color[3] = nAlpha;
  texul.x = x;
  texlr.x = v9;
  texlr.y = y;
  if ( v5 )
  {
    texul.x = v9;
    texlr.x = x;
  }
  v10 = float16::Convert16bitFloatTo32bits(input: this->m_SpriteInfo.m_flScale.m_storage.rawWord);
  ul.x = v4->m_UL.x * v10;
  ul.y = v4->m_UL.y * v10;
  v56 = v4->m_LR.x * v10;
  flSwayAmplitude = v10 * v4->m_LR.y;
  v11 = CurrentViewOrigin();
  v12 = v11->x;
  v13 = v11->y;
  z = v11->z;
  m_pAdvInfo = (float *)this->m_pAdvInfo;
  v16 = v12 - this->m_Origin.x;
  v17 = v13 - this->m_Origin.y;
  v18 = z - this->m_Origin.z;
  v19 = (float)((float)((float)(m_pAdvInfo[1] * v17) + (float)(*m_pAdvInfo * v16)) + (float)(m_pAdvInfo[2] * v18)) > 0.0;
  v20 = (float)((float)((float)(m_pAdvInfo[4] * v17) + (float)(m_pAdvInfo[3] * v16)) + (float)(m_pAdvInfo[5] * v18)) > 0.0;
  v21 = (float)((float)((float)(m_pAdvInfo[7] * v17) + (float)(m_pAdvInfo[6] * v16)) + (float)(m_pAdvInfo[8] * v18)) > 0.0;
  v22 = 0;
  if ( v19 )
  {
    if ( !v20 )
    {
      v22 = 1;
      goto LABEL_9;
    }
  }
  else if ( !v20 )
  {
    goto LABEL_9;
  }
  if ( !v21 )
    v22 = 2;
LABEL_9:
  flHeight = flSwayAmplitude - ul.y;
  flWidth = v56 - ul.x;
  CDetailModel::UpdatePlayerAvoid(this, a2: COERCE_FLOAT(&savedregs));
  UTIL_YawToVector(result: &vecSwayYaw, yaw: this->m_pAdvInfo->m_flSwayYaw);
  flSwayAmplitude = this->m_pAdvInfo->m_flSwayAmount * cl_detail_max_sway.m_pParent->m_Value.m_fValue;
  for ( i = 3; i != 0; --i )
  {
    v24 = this->m_pAdvInfo;
    v25 = 3 * v22 + 18;
    v26 = *(&v24->m_vecAnglesForward[0].y + v25);
    *(float *)&v27 = *(&v24->m_vecAnglesForward[0].x + v25) * flHeight;
    v28 = (float *)((char *)v24 + 4 * v25);
    vecHeight.z = v28[2] * flHeight;
    *(_QWORD *)&vecHeight.x = __PAIR64__(v26 * flHeight, v27);
    v29 = 3 * v22 + 9;
    v30 = *(&v24->m_vecAnglesForward[0].y + v29);
    v31 = *(&v24->m_vecAnglesForward[0].x + v29);
    v32 = *(&v24->m_vecAnglesForward[0].z + v29) * flWidth;
    v33 = (float *)((char *)v24 + 4 * v29);
    vecWidth.z = v32;
    v34 = (float)(v33[2] * ul.x) + this->m_Origin.z;
    vecWidth.y = v30 * flWidth;
    v35 = v33[1];
    vecWidth.x = v31 * flWidth;
    v36 = (float)(v26 * ul.y) + (float)((float)(v35 * ul.x) + this->m_Origin.y);
    v37 = (float)(v28[2] * ul.y) + v34;
    v38 = (float)(*v28 * ul.y) + (float)((float)(*v33 * ul.x) + this->m_Origin.x);
    v39 = v24->m_flShapeSize * flWidth;
    p_x = &v24->m_vecAnglesForward[v22].x;
    vecOrigin.x = (float)(*p_x * v39) + v38;
    vecOrigin.y = (float)(p_x[1] * v39) + v36;
    v41 = p_x[2] * v39;
    v42 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
    v42.m128_f32[0] = (float)(v42.m128_f32[0] + this->m_Origin.x) + (float)v22;
    vecOrigin.z = v41 + v37;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v42));
    v44 = v43;
    v45 = this->m_pAdvInfo;
    v46 = v45->m_vecCurrentAvoid.z;
    *(_QWORD *)&vecSway.x = __PAIR64__(
                              (float)(v45->m_vecCurrentAvoid.y * flWidth)
                            + (float)((float)(vecSwayYaw.y * v44) * flSwayAmplitude),
                              (float)(v45->m_vecCurrentAvoid.x * flWidth)
                            + (float)((float)(vecSwayYaw.x * v44) * flSwayAmplitude));
    vecSway.z = (float)(v46 * flWidth) + (float)((float)(vecSwayYaw.z * v44) * flSwayAmplitude);
    CDetailModel::DrawSwayingQuad(
      this,
      meshBuilder,
      vecOrigin,
      vecSway,
      texul,
      texlr,
      color,
      width: vecWidth,
      height: vecHeight);
    if ( ++v22 > 2 )
      v22 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC960
// Name: private: int CDetailObjectSystem::SortSpritesBackToFront(int,class Vector const __near &,struct DistanceFadeInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDetailObjectSystem::SortSpritesBackToFront(
        CDetailObjectSystem *this,
        int nLeaf,
        const Vector *viewOrigin,
        const DistanceFadeInfo_t *fadeInfo,
        CDetailObjectSystem::SortInfo_t *pSortInfo)
{
  int v5; // edi
  int v6; // eax
  char *v7; // esi
  float *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  const Vector *v12; // eax
  const Vector *v13; // eax
  Vector forward; // [esp+4h] [ebp-2Ch] BYREF
  Vector v16; // [esp+10h] [ebp-20h] BYREF
  CDetailObjectSystem *v17; // [esp+1Ch] [ebp-14h]
  int nFirstDetailObject; // [esp+20h] [ebp-10h] BYREF
  int v19; // [esp+24h] [ebp-Ch]
  int nDetailObjectCount; // [esp+28h] [ebp-8h] BYREF
  int j; // [esp+2Ch] [ebp-4h]
  char nLeaf_3; // [esp+3Bh] [ebp+Bh]

  v17 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDetailObjectSystem::SortSpritesBackToFront",
    a3: 0,
    a4: "Detail_Prop_Rendering",
    a5: false,
    a6: 4);
  g_pClientLeafSystem->GetDetailObjectsInLeaf(
    this: g_pClientLeafSystem,
    a2: nLeaf,
    a3: &nFirstDetailObject,
    a4: &nDetailObjectCount);
  v5 = 0;
  nDetailObjectCount += nFirstDetailObject;
  j = nFirstDetailObject;
  if ( nFirstDetailObject < nDetailObjectCount )
  {
    v6 = 48 * nFirstDetailObject;
    v19 = 48 * nFirstDetailObject;
    do
    {
      v7 = (char *)v17->m_DetailObjects.m_Memory.m_pMemory + v6;
      if ( (v7[36] & 0xC) != 0 )
      {
        v8 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)v7 + 1) + 4))(a1: v7 + 4);
        v9 = viewOrigin->y - v8[1];
        v10 = viewOrigin->z - v8[2];
        v11 = (float)((float)(v9 * v9) + (float)((float)(viewOrigin->x - *v8) * (float)(viewOrigin->x - *v8)))
            + (float)(v10 * v10);
        if ( v11 < fadeInfo->m_flMaxDistSqr )
        {
          nLeaf_3 = -1;
          if ( v11 <= fadeInfo->m_flMinDistSqr
            || (nLeaf_3 = (int)(float)((float)(fadeInfo->m_flMaxDistSqr - v11)
                                     * (float)(fadeInfo->m_flFalloffFactor * 255.0))) != 0 )
          {
            if ( (v7[36] & 3) == 1 )
            {
              v13 = CurrentViewOrigin();
              forward.x = v13->x - *((float *)v7 + 2);
              forward.y = v13->y - *((float *)v7 + 3);
              forward.z = v13->z - *((float *)v7 + 4);
              VectorAngles(&forward, angles: (QAngle *)(v7 + 20));
            }
            else if ( (v7[36] & 3) == 2 )
            {
              v12 = CurrentViewOrigin();
              v16.x = v12->x - *((float *)v7 + 2);
              v16.y = v12->y - *((float *)v7 + 3);
              v16.z = 0.0;
              VectorAngles(forward: &v16, angles: (QAngle *)(v7 + 20));
            }
            *(_DWORD *)&pSortInfo[v5] ^= (j ^ *(_DWORD *)&pSortInfo[v5]) & 0xFFFFFF;
            *((_BYTE *)&pSortInfo[v5] + 3) = nLeaf_3;
            pSortInfo[v5++].m_flDistance = v11;
          }
        }
      }
      v6 = v19 + 48;
      ++j;
      v19 += 48;
    }
    while ( j < nDetailObjectCount );
    if ( v5 != 0 )
    {
      if ( 8 * v5 > 8 )
        std::_Make_heap<CDetailObjectSystem::SortInfo_t *,int,CDetailObjectSystem::SortInfo_t,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
          _First: pSortInfo,
          _Last: &pSortInfo[v5],
          _Pred: (bool (__cdecl *)(const CDetailObjectSystem::SortInfo_t *, const CDetailObjectSystem::SortInfo_t *))CDetailObjectSystem::SortLessFunc,
          __formal: nullptr,
          __formal: nullptr);
      std::_Sort_heap<CDetailObjectSystem::SortInfo_t *,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
        _First: pSortInfo,
        _Last: &pSortInfo[v5],
        _Pred: (bool (__cdecl *)(const CDetailObjectSystem::SortInfo_t *, const CDetailObjectSystem::SortInfo_t *))CDetailObjectSystem::SortLessFunc);
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100CCB60
// Name: private: int CDetailObjectSystem::BuildOutSortedSprites(class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDetailObjectSystem::BuildOutSortedSprites(
        CDetailObjectSystem *this,
        CFastDetailLeafSpriteList *pData,
        const DistanceFadeInfo_t *info,
        const Vector *viewOrigin,
        const Vector *viewForward,
        const Vector *viewRight,
        const Vector *viewUp)
{
  FastSpriteX4_t *m_pSprites; // edx
  CDetailObjectSystem::SortInfo_t *m_pFastSortInfo; // ecx
  FastSpriteQuadBuildoutBufferX4_t *m_pBuildoutBuffer; // eax
  float y; // xmm3_4
  float z; // xmm4_4
  __m128 v14; // xmm1
  float v15; // xmm0_4
  __m128 v16; // xmm5
  __m128 v17; // xmm7
  __m128 v18; // xmm0
  __m128 v19; // xmm0
  __m128 v20; // xmm0
  int v21; // esi
  __m128 *p_z; // edx
  __m128 *v23; // eax
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm4
  __m128 v33; // xmm6
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm4
  __m128 v40; // xmm6
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  __m128 v44; // xmm5
  __m128 v45; // xmm2
  __m128 v46; // xmm6
  __m128 v47; // xmm0
  __m128 v48; // xmm0
  __m128 v49; // xmm5
  __m128 v50; // xmm5
  int v51; // edi
  int v52; // edi
  int v53; // edi
  int v54; // esi
  __m128 vecDy_20; // [esp+14h] [ebp-16Ch]
  __m128 vecDx_20; // [esp+44h] [ebp-13Ch]
  __m128 vecDx_36; // [esp+54h] [ebp-12Ch]
  __m128 startFade_4; // [esp+64h] [ebp-11Ch]
  __m128 v60; // [esp+74h] [ebp-10Ch]
  __m128 vecUp_4; // [esp+84h] [ebp-FCh]
  __m128 vecUp_20; // [esp+94h] [ebp-ECh]
  __m128 vecUp_36; // [esp+A4h] [ebp-DCh]
  __m128 v64; // [esp+B4h] [ebp-CCh]
  __m128 vecFwd_4; // [esp+C4h] [ebp-BCh]
  __m128 vecFwd_20; // [esp+D4h] [ebp-ACh]
  __m128 vecFwd_36; // [esp+E4h] [ebp-9Ch]
  __m128 maxsqdist_4; // [esp+F4h] [ebp-8Ch]
  __m128 vecViewPos_4; // [esp+104h] [ebp-7Ch]
  __m128 vecViewPos_20; // [esp+114h] [ebp-6Ch]
  __m128 vecViewPos_36; // [esp+124h] [ebp-5Ch]
  __m128 v72; // [esp+134h] [ebp-4Ch]
  __m128 falloffFactor_4; // [esp+144h] [ebp-3Ch]
  unsigned __int64 distanceSquared_8; // [esp+158h] [ebp-28h]
  unsigned int v75; // [esp+160h] [ebp-20h]
  CDetailObjectSystem *vNormal_4; // [esp+168h] [ebp-18h]
  int vNormal_8; // [esp+16Ch] [ebp-14h]
  int vNormal_12; // [esp+170h] [ebp-10h]

  vNormal_12 = pData->m_nNumSIMDSprites;
  m_pSprites = pData->m_pSprites;
  m_pFastSortInfo = this->m_pFastSortInfo;
  *(_DWORD *)m_pFastSortInfo = *(_DWORD *)m_pFastSortInfo & 0xFF000000 | 1;
  vNormal_4 = this;
  m_pBuildoutBuffer = this->m_pBuildoutBuffer;
  m_pBuildoutBuffer->m_Coords[0].x = Four_Zeros;
  y = viewForward->y;
  z = viewForward->z;
  *(float *)&distanceSquared_8 = -viewForward->x;
  *((float *)&distanceSquared_8 + 1) = -y;
  maxsqdist_4 = _mm_shuffle_ps((__m128)LODWORD(viewOrigin->x), (__m128)LODWORD(viewOrigin->x), 0);
  vecViewPos_4 = _mm_shuffle_ps((__m128)LODWORD(viewOrigin->y), (__m128)LODWORD(viewOrigin->y), 0);
  vecViewPos_20 = _mm_shuffle_ps((__m128)LODWORD(viewOrigin->z), (__m128)LODWORD(viewOrigin->z), 0);
  *(float *)&v75 = -z;
  v14 = 0;
  v14.m128_f32[0] = info->m_flMaxDistSqr;
  vecFwd_36 = _mm_shuffle_ps(v14, v14, 0);
  v15 = 1.0 / (float)(v14.m128_f32[0] - info->m_flMinDistSqr);
  v16 = 0;
  v16.m128_f32[0] = v15;
  v72 = _mm_shuffle_ps(v16, v16, 0);
  vecDx_36 = _mm_shuffle_ps((__m128)LODWORD(info->m_flMinDistSqr), (__m128)LODWORD(info->m_flMinDistSqr), 0);
  v17 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  vecUp_4 = v17;
  vecUp_20 = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  v18 = 0;
  v18.m128_f32[0] = viewForward->x;
  v64 = _mm_shuffle_ps(v18, v18, 0);
  v19 = 0;
  v19.m128_f32[0] = y;
  vecFwd_4 = _mm_shuffle_ps(v19, v19, 0);
  v20 = 0;
  v20.m128_f32[0] = z;
  v60 = v17;
  vecFwd_20 = _mm_shuffle_ps(v20, v20, 0);
  v21 = 2;
  p_z = &m_pSprites->m_Pos.z;
  v23 = &m_pBuildoutBuffer->m_Coords[1].z;
  do
  {
    vecViewPos_36 = *p_z;
    v24 = _mm_sub_ps(*p_z, vecViewPos_20);
    startFade_4 = p_z[-2];
    v25 = _mm_sub_ps(startFade_4, maxsqdist_4);
    vecUp_36 = p_z[-1];
    v26 = _mm_sub_ps(vecUp_36, vecViewPos_4);
    v27 = _mm_mul_ps(v25, v25);
    v28 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, v26), v27), _mm_mul_ps(v24, v24));
    falloffFactor_4 = v28;
    vNormal_8 = _mm_movemask_ps(
                  _mm_or_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(vecFwd_4, v26), _mm_mul_ps(v64, v25)), _mm_mul_ps(v24, vecFwd_20)),
                    _mm_cmplt_ps(vecFwd_36, v28)));
    if ( vNormal_8 != 15 )
    {
      v29 = _mm_xor_ps(*(__m128 *)g_SIMD_signmask, v26);
      v30 = _mm_rsqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v29, v29), v27), _mm_mul_ps(Four_Zeros, Four_Zeros)));
      v31 = _mm_mul_ps(v30, Four_Zeros);
      v32 = _mm_mul_ps(v30, v29);
      v33 = _mm_mul_ps(v30, v25);
      v34 = _mm_mul_ps(p_z[1], v32);
      v35 = p_z[1];
      v36 = _mm_mul_ps(v35, v31);
      v37 = p_z[2];
      v23[8] = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     Four_Ones,
                     _mm_min_ps(_mm_max_ps(_mm_mul_ps(_mm_sub_ps(v28, vecDx_36), v72), Four_Zeros), Four_Ones)),
                   Four_255s),
                 Four_MagicNumbers);
      v38 = _mm_add_ps(startFade_4, v34);
      v23[-5] = v38;
      v39 = _mm_mul_ps(v35, v33);
      v40 = v37;
      vecDx_20 = v36;
      v41 = _mm_mul_ps(v37, vecUp_4);
      vecDy_20 = _mm_mul_ps(v37, vecUp_20);
      v42 = _mm_add_ps(vecViewPos_36, vecDx_20);
      v23[-3] = v42;
      v43 = _mm_sub_ps(v42, vecDy_20);
      v44 = _mm_add_ps(vecUp_36, v39);
      v23[-4] = v44;
      *v23 = v43;
      v45 = _mm_sub_ps(_mm_sub_ps(v43, vecDx_20), vecDx_20);
      v46 = _mm_mul_ps(v40, v17);
      v47 = _mm_sub_ps(v38, v46);
      v23[-2] = v47;
      v48 = _mm_sub_ps(_mm_sub_ps(v47, v34), v34);
      v49 = _mm_sub_ps(v44, v41);
      v23[-1] = v49;
      v23[1] = v48;
      v23[3] = v45;
      v50 = _mm_sub_ps(_mm_sub_ps(v49, v39), v39);
      v23[2] = v50;
      v23[6] = _mm_add_ps(v45, vecDy_20);
      v23[4] = _mm_add_ps(v48, v46);
      v23[5] = _mm_add_ps(v50, v41);
      v23[9] = p_z[4];
      v23[7] = p_z[3];
      v51 = *(_DWORD *)m_pFastSortInfo ^ (v21 - 2);
      LODWORD(m_pFastSortInfo->m_flDistance) = falloffFactor_4.m128_i32[0];
      *(_DWORD *)m_pFastSortInfo ^= v51 & 0xFFFFFF;
      *(_DWORD *)&m_pFastSortInfo[1] ^= (*(_DWORD *)&m_pFastSortInfo[1] ^ (v21 - 1)) & 0xFFFFFF;
      v17 = v60;
      v52 = v21 ^ *(_DWORD *)&m_pFastSortInfo[2];
      LODWORD(m_pFastSortInfo[1].m_flDistance) = falloffFactor_4.m128_i32[1];
      *(_DWORD *)&m_pFastSortInfo[2] ^= v52 & 0xFFFFFF;
      LODWORD(m_pFastSortInfo[2].m_flDistance) = falloffFactor_4.m128_i32[2];
      LODWORD(m_pFastSortInfo[3].m_flDistance) = falloffFactor_4.m128_i32[3];
      v53 = *(_DWORD *)&m_pFastSortInfo[3] ^ (v21 + 1);
      v21 += 4;
      *(_DWORD *)&m_pFastSortInfo[3] ^= v53 & 0xFFFFFF;
      v23[10].m128_u64[0] = distanceSquared_8;
      v23[10].m128_i32[2] = v75;
      v23[10].m128_i32[3] = 0;
      m_pFastSortInfo += 4;
      v23 += 16;
    }
    p_z += 7;
    --vNormal_12;
  }
  while ( vNormal_12 != 0 );
  v54 = m_pFastSortInfo - vNormal_4->m_pFastSortInfo;
  if ( vNormal_8 != 15 )
    v54 -= -pData->m_nNumSprites & 3;
  if ( v54 != 0 )
  {
    if ( 8 * v54 > 8 )
      std::_Make_heap<CDetailObjectSystem::SortInfo_t *,int,CDetailObjectSystem::SortInfo_t,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
        _First: vNormal_4->m_pFastSortInfo,
        _Last: &vNormal_4->m_pFastSortInfo[v54],
        _Pred: (bool (__cdecl *)(const CDetailObjectSystem::SortInfo_t *, const CDetailObjectSystem::SortInfo_t *))CDetailObjectSystem::SortLessFunc,
        __formal: nullptr,
        __formal: nullptr);
    std::_Sort_heap<CDetailObjectSystem::SortInfo_t *,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
      _First: vNormal_4->m_pFastSortInfo,
      _Last: &vNormal_4->m_pFastSortInfo[v54],
      _Pred: (bool (__cdecl *)(const CDetailObjectSystem::SortInfo_t *, const CDetailObjectSystem::SortInfo_t *))CDetailObjectSystem::SortLessFunc);
  }
  return v54;
}

//------------------------------------------------------------------------------
// Address: 0x100CCFC0
// Name: public: void CDetailObjectSystem::RenderFastSprites(struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,unsigned short const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDetailObjectSystem::RenderFastSprites(
        CDetailObjectSystem *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const DistanceFadeInfo_t *info,
        const Vector *viewOrigin,
        const Vector *viewForward,
        const Vector *viewRight,
        const Vector *viewUp,
        int nLeafCount,
        const unsigned __int16 *pLeafList)
{
  IMatRenderContext *v11; // edi
  IMaterial *m_pMaterial; // esi
  int m_nValue; // eax
  int v14; // eax
  IMesh *v15; // eax
  void (__thiscall *GetMaxToRender)(IMatRenderContext *, IMesh *, bool, int *, int *); // edx
  IMesh *v17; // ebx
  int v18; // edi
  int v19; // ecx
  int v20; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v22; // edi
  CFastDetailLeafSpriteList *v23; // eax
  CDetailObjectSystem *v24; // esi
  int v25; // eax
  const CDetailObjectSystem::SortInfo_t *m_pFastSortInfo; // edx
  const FastSpriteQuadBuildoutBufferNonSIMDView_t *m_pBuildoutBuffer; // ecx
  float *m_pCurrPosition; // edx
  int m_nVertexCount; // esi
  int v30; // ecx
  int v31; // eax
  int v32; // esi
  void (__thiscall *v33)(IMesh *, MaterialPrimitiveType_t); // eax
  int v34; // ecx
  const FastSpriteQuadBuildoutBufferNonSIMDView_t *v35; // eax
  DetailPropSpriteDict_t *v36; // edi
  double v37; // st7
  unsigned __int8 v38; // bl
  float v39; // xmm0_4
  float v40; // xmm1_4
  float *p_x; // esi
  char *v42; // eax
  int v43; // ecx
  float *v44; // edx
  float y; // xmm0_4
  float *m_pCurrNormal; // edx
  int v47; // edx
  float *v48; // edx
  int v49; // xmm0_4
  int v50; // xmm1_4
  float *v51; // edx
  float v52; // xmm0_4
  float *v53; // edx
  int v54; // edx
  float *v55; // edx
  int v56; // xmm0_4
  int v57; // xmm1_4
  float *v58; // edx
  float v59; // xmm0_4
  float *v60; // edx
  int v61; // edx
  float *v62; // edx
  int v63; // xmm0_4
  int v64; // xmm1_4
  float *v65; // eax
  float v66; // xmm0_4
  float *v67; // eax
  int v68; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-224h] BYREF
  const FastSpriteQuadBuildoutBufferNonSIMDView_t *pQuadBuffer; // [esp+1ECh] [ebp-3Ch]
  int nMaxVerts; // [esp+1F0h] [ebp-38h] BYREF
  int nMaxIndices; // [esp+1F4h] [ebp-34h] BYREF
  IMesh *pMesh; // [esp+1F8h] [ebp-30h]
  CDetailObjectSystem *v75; // [esp+1FCh] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+200h] [ebp-28h] BYREF
  const CDetailObjectSystem::SortInfo_t *pDraw; // [esp+204h] [ebp-24h]
  int nCount; // [esp+208h] [ebp-20h]
  int i; // [esp+20Ch] [ebp-1Ch]
  int nQuadCount; // [esp+210h] [ebp-18h]
  int nToDraw; // [esp+214h] [ebp-14h]
  int nQuadsToDraw; // [esp+218h] [ebp-10h]
  unsigned __int8 color[4]; // [esp+21Ch] [ebp-Ch]
  int nQuadsRemaining; // [esp+220h] [ebp-8h]
  DetailPropFlashlightMode_t flashlightMode; // [esp+224h] [ebp-4h]

  v75 = this;
  nQuadCount = CDetailObjectSystem::CountFastSpritesInLeafList(
                 this,
                 nLeafCount,
                 pLeafList,
                 nMaxFoundInLeaf: (int *)&pRenderContext);
  if ( nQuadCount != 0 && r_DrawDetailProps.m_pParent != nullptr && r_DrawDetailProps.m_pParent->m_Value.m_nValue != 0 )
  {
    v11 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                                 a1: materials,
                                 a2,
                                 a3);
    pRenderContext.m_pObject = v11;
    if ( v11 != nullptr )
      v11->BeginRender(this: v11);
    v11->MatrixMode(this: v11, a2: MATERIAL_MODEL);
    v11->PushMatrix(this: v11);
    v11->LoadIdentity(this: v11);
    m_pMaterial = this->m_DetailSpriteMaterial.m_pMaterial;
    if ( ShouldDrawInWireFrameMode()
      || r_DrawDetailProps.m_pParent != nullptr && r_DrawDetailProps.m_pParent->m_Value.m_nValue == 2 )
    {
      m_pMaterial = this->m_DetailWireframeMaterial.m_pMaterial;
    }
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    if ( r_FlashlightDetailProps.m_pParent != nullptr )
      m_nValue = r_FlashlightDetailProps.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v14 = m_nValue - 1;
    if ( v14 != 0 )
    {
      if ( v14 == 1 )
        flashlightMode = DPFM_MULTIPASS;
      else
        flashlightMode = DPFM_NONE;
    }
    else
    {
      flashlightMode = DPFM_SINGLEPASS;
    }
    v15 = v11->GetDynamicMesh(
            this: v11,
            a2: flashlightMode != DPFM_MULTIPASS,
            a3: nullptr,
            a4: nullptr,
            a5: m_pMaterial);
    GetMaxToRender = v11->GetMaxToRender;
    v17 = v15;
    pMesh = v15;
    GetMaxToRender(this: v11, a2: v15, a3: false, a4: &nMaxVerts, a5: &nMaxIndices);
    v18 = nQuadCount;
    v19 = nMaxIndices / 6;
    if ( nMaxIndices / 6 > nMaxVerts / 4 )
      v19 = nMaxVerts / 4;
    if ( nQuadCount >= v19 )
    {
      nQuadsToDraw = v19;
      v18 = v19;
    }
    else
    {
      nQuadsToDraw = nQuadCount;
    }
    nQuadsRemaining = v18;
    v20 = 4 * v18;
    meshBuilder.m_pMesh = v17;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    SetPrimitiveType = v17->SetPrimitiveType;
    v22 = 6 * v18;
    nQuadCount = v22;
    SetPrimitiveType(this: v17, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v20, a3: v22, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v17->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v22;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(
      this: &meshBuilder.m_VertexBuilder,
      pMesh: v17,
      nMaxVertexCount: v20,
      desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    i = 0;
    if ( nLeafCount <= 0 )
    {
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    else
    {
      do
      {
        v23 = (CFastDetailLeafSpriteList *)g_pClientLeafSystem->GetSubSystemDataInLeaf(
                                             this: g_pClientLeafSystem,
                                             a2: pLeafList[i],
                                             a3: 0);
        if ( v23 != nullptr
          && (v24 = v75,
              v25 = CDetailObjectSystem::BuildOutSortedSprites(
                      this: v75,
                      pData: v23,
                      info,
                      viewOrigin,
                      viewForward,
                      viewRight,
                      viewUp),
              m_pFastSortInfo = v24->m_pFastSortInfo,
              m_pBuildoutBuffer = (const FastSpriteQuadBuildoutBufferNonSIMDView_t *)v24->m_pBuildoutBuffer,
              nCount = v25,
              pDraw = m_pFastSortInfo,
              pQuadBuffer = m_pBuildoutBuffer,
              v25 != 0) )
        {
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          do
          {
            v30 = nQuadsRemaining;
            if ( nQuadsRemaining == 0 )
            {
              if ( meshBuilder.m_bGenerateIndices )
              {
                switch ( meshBuilder.m_Type )
                {
                  case MATERIAL_LINE_STRIP:
                    v31 = 2 * m_nVertexCount - 2;
                    break;
                  case MATERIAL_LINE_LOOP:
                    v31 = 2 * m_nVertexCount;
                    break;
                  case MATERIAL_POLYGON:
                    v31 = 3 * m_nVertexCount - 6;
                    break;
                  case MATERIAL_QUADS:
                    v31 = 6 * m_nVertexCount / 4;
                    break;
                  case MATERIAL_INSTANCED_QUADS:
                    v31 = 0;
                    break;
                  default:
                    v31 = m_nVertexCount;
                    break;
                }
                CIndexBuilder::GenerateIndices(
                  this: &meshBuilder.m_IndexBuilder,
                  primitiveType: meshBuilder.m_Type,
                  nIndexCount: v31);
                m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              }
              meshBuilder.m_pMesh->UnlockMesh(
                this: meshBuilder.m_pMesh,
                a2: m_nVertexCount,
                a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
                a4: &meshBuilder);
              meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
              meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
              meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
              meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
              meshBuilder.m_pMesh = nullptr;
              meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
              v17->Draw_2(this: v17, a2: -1, a3: 0);
              if ( flashlightMode == DPFM_MULTIPASS )
                shadowmgr->FlashlightDrawCallback(this: shadowmgr, a2: DrawMeshCallback, a3: v17);
              v32 = nQuadsToDraw;
              meshBuilder.m_pMesh = v17;
              meshBuilder.m_bGenerateIndices = true;
              meshBuilder.m_Type = MATERIAL_QUADS;
              v33 = v17->SetPrimitiveType;
              nQuadsRemaining = nQuadsToDraw;
              v33(this: v17, a2: MATERIAL_TRIANGLES);
              meshBuilder.m_pMesh->LockMesh(
                this: meshBuilder.m_pMesh,
                a2: 4 * v32,
                a3: v22,
                a4: &meshBuilder,
                a5: nullptr);
              meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v17->IIndexBuffer;
              meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
              meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v22;
              meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
              meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
              meshBuilder.m_IndexBuilder.m_bModify = false;
              meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
              meshBuilder.m_VertexBuilder.m_pVertexBuffer = v17;
              meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
              meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4 * nQuadsToDraw;
              meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
              meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
              meshBuilder.m_VertexBuilder.m_bModify = false;
              if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
              {
                meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
                meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
                meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
              }
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
              CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              v25 = nCount;
              v30 = nQuadsRemaining;
            }
            if ( v25 >= v30 )
              nToDraw = v30;
            else
              v30 = v25;
            nQuadsRemaining -= v30;
            v25 -= v30;
            nCount = v25;
            if ( v30 != 0 )
            {
              while ( 1 )
              {
                nToDraw = v30 - 1;
                v34 = *(_DWORD *)pDraw & 3;
                v35 = &pQuadBuffer[(int)(*(_DWORD *)pDraw << 8) >> 10];
                v36 = v35->m_pSpriteDefs[v34];
                v37 = v35->m_flX0[v34];
                v38 = v35->m_RGBColor[v34][0];
                v39 = v35->m_flY0[v34];
                v40 = v35->m_flZ0[v34];
                p_x = &v35->m_Normal.x;
                v42 = (char *)&v35->m_flX0[v34];
                color[1] = v42[193];
                color[2] = v42[194];
                LOBYTE(v34) = v42[208];
                *m_pCurrPosition = v37;
                color[3] = v34;
                m_pCurrPosition[1] = v39;
                m_pCurrPosition[2] = v40;
                v43 = color[2] | ((color[1] | ((v38 | (color[3] << 8)) << 8)) << 8);
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v43;
                v44 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                y = v36->m_TexLR.y;
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v36->m_TexLR.x;
                v44[1] = y;
                m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
                m_pCurrNormal[1] = p_x[1];
                m_pCurrNormal[2] = p_x[2];
                v47 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                meshBuilder.m_VertexBuilder.m_nCurrentVertex = v47;
                if ( v47 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                  meshBuilder.m_VertexBuilder.m_nVertexCount = v47;
                meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                    + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                v48 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                         + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                meshBuilder.m_VertexBuilder.m_pCurrPosition = v48;
                v49 = *((_DWORD *)v42 + 16);
                v50 = *((_DWORD *)v42 + 20);
                *v48 = *((float *)v42 + 12);
                *((_DWORD *)v48 + 1) = v49;
                *((_DWORD *)v48 + 2) = v50;
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v43;
                v51 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                v52 = v36->m_TexUL.y;
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v36->m_TexLR.x;
                v51[1] = v52;
                v53 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
                v53[1] = p_x[1];
                v53[2] = p_x[2];
                v54 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                meshBuilder.m_VertexBuilder.m_nCurrentVertex = v54;
                if ( v54 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                  meshBuilder.m_VertexBuilder.m_nVertexCount = v54;
                meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                    + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                v55 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                         + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                meshBuilder.m_VertexBuilder.m_pCurrPosition = v55;
                v56 = *((_DWORD *)v42 + 28);
                v57 = *((_DWORD *)v42 + 32);
                *v55 = *((float *)v42 + 24);
                *((_DWORD *)v55 + 1) = v56;
                *((_DWORD *)v55 + 2) = v57;
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v43;
                v58 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                v59 = v36->m_TexUL.y;
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v36->m_TexUL.x;
                v58[1] = v59;
                v60 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
                v60[1] = p_x[1];
                v60[2] = p_x[2];
                v61 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                meshBuilder.m_VertexBuilder.m_nCurrentVertex = v61;
                if ( v61 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                  meshBuilder.m_VertexBuilder.m_nVertexCount = v61;
                meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                    + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                v62 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                         + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                meshBuilder.m_VertexBuilder.m_pCurrPosition = v62;
                v63 = *((_DWORD *)v42 + 40);
                v64 = *((_DWORD *)v42 + 44);
                *v62 = *((float *)v42 + 36);
                *((_DWORD *)v62 + 1) = v63;
                *((_DWORD *)v62 + 2) = v64;
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v43;
                v65 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                v66 = v36->m_TexLR.y;
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v36->m_TexUL.x;
                v65[1] = v66;
                v67 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
                v67[1] = p_x[1];
                v67[2] = p_x[2];
                m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                v68 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                meshBuilder.m_VertexBuilder.m_nCurrentVertex = v68;
                if ( v68 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                {
                  m_nVertexCount = v68;
                  meshBuilder.m_VertexBuilder.m_nVertexCount = v68;
                }
                meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                    + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                         + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                ++pDraw;
                meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                if ( nToDraw == 0 )
                  break;
                v30 = nToDraw;
              }
              v17 = pMesh;
              v25 = nCount;
            }
            v22 = nQuadCount;
          }
          while ( v25 != 0 );
        }
        else
        {
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        }
        ++i;
      }
      while ( i < nLeafCount );
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh, a2: m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v17->Draw_2(this: v17, a2: -1, a3: 0);
    if ( flashlightMode == DPFM_MULTIPASS )
      shadowmgr->FlashlightDrawCallback(this: shadowmgr, a2: DrawMeshCallback, a3: v17);
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->PopMatrix(this: pRenderContext.m_pObject);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD830
// Name: public: void CDetailObjectSystem::RenderFastTranslucentDetailObjectsInLeaf(class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::RenderFastTranslucentDetailObjectsInLeaf(
        CDetailObjectSystem *this,
        CFastDetailLeafSpriteList *pData,
        int info,
        const Vector *viewOrigin,
        const Vector *viewForward,
        DetailPropFlashlightMode_t viewRight,
        const CDetailObjectSystem::SortInfo_t *viewUp,
        int nLeaf,
        float vecClosestPoint,
        const Vector *bFirstCallThisFrame)
{
  const Vector *v11; // edi
  const Vector *v12; // ecx
  const Vector *v13; // edx
  CFastDetailLeafSpriteList *v14; // esi
  const Vector *m_nNumPendingSprites; // ecx
  bool v16; // cc
  IMatRenderContext *v17; // eax
  IMatRenderContext *v18; // edi
  IMaterial *m_pMaterial; // esi
  int m_nValue; // eax
  int v21; // eax
  IMesh *v22; // eax
  void (__thiscall *GetMaxToRender)(IMatRenderContext *, IMesh *, bool, int *, int *); // edx
  IMesh *v24; // esi
  const Vector *v25; // ebx
  int v26; // ecx
  int v27; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v29; // ebx
  const FastSpriteQuadBuildoutBufferNonSIMDView_t *m_pBuildoutBuffer; // ecx
  int m_nVertexCount; // edi
  const Vector *v32; // eax
  float *m_pCurrPosition; // edx
  int v34; // eax
  int v35; // eax
  int v36; // edi
  void (__thiscall *v37)(IMesh *, MaterialPrimitiveType_t); // eax
  int v38; // ecx
  const FastSpriteQuadBuildoutBufferNonSIMDView_t *v39; // eax
  DetailPropSpriteDict_t *v40; // edi
  double v41; // st7
  unsigned __int8 v42; // bl
  float v43; // xmm0_4
  float v44; // xmm1_4
  float *p_x; // esi
  char *v46; // eax
  int v47; // ecx
  float *v48; // edx
  float y; // xmm0_4
  float *m_pCurrNormal; // edx
  int v51; // edx
  float *v52; // edx
  int v53; // xmm0_4
  int v54; // xmm1_4
  float *v55; // edx
  float v56; // xmm0_4
  float *v57; // edx
  int v58; // edx
  float *v59; // edx
  int v60; // xmm0_4
  int v61; // xmm1_4
  float *v62; // edx
  float v63; // xmm0_4
  float *v64; // edx
  int v65; // edx
  float *v66; // edx
  int v67; // xmm0_4
  int v68; // xmm1_4
  float v69; // xmm0_4
  float *v70; // eax
  float *v71; // eax
  int v72; // eax
  bool v73; // zf
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-204h] BYREF
  const FastSpriteQuadBuildoutBufferNonSIMDView_t *pQuadBuffer; // [esp+1F4h] [ebp-1Ch]
  CMatRenderContextPtr pRenderContext; // [esp+1F8h] [ebp-18h]
  int nMaxVerts; // [esp+1FCh] [ebp-14h] BYREF
  int v79; // [esp+200h] [ebp-10h]
  IMesh *pMesh; // [esp+204h] [ebp-Ch]
  int nToDraw; // [esp+208h] [ebp-8h]
  CDetailObjectSystem *v82; // [esp+20Ch] [ebp-4h]

  v11 = viewOrigin;
  v82 = this;
  if ( (_BYTE)bFirstCallThisFrame == 0 && this->m_nSortedFastLeaf == nLeaf )
  {
    v14 = pData;
  }
  else
  {
    v12 = (const Vector *)viewRight;
    v13 = viewForward;
    v14 = pData;
    this->m_nSortedFastLeaf = nLeaf;
    pData->m_nNumPendingSprites = CDetailObjectSystem::BuildOutSortedSprites(
                                    this,
                                    pData,
                                    (const DistanceFadeInfo_t *)info,
                                    viewOrigin: v11,
                                    viewForward: v13,
                                    viewRight: v12,
                                    (const Vector *)viewUp);
    pData->m_nStartSpriteIndex = 0;
  }
  m_nNumPendingSprites = (const Vector *)v14->m_nNumPendingSprites;
  if ( m_nNumPendingSprites != nullptr )
  {
    v16 = (float)((float)((float)((float)(*(float *)(LODWORD(vecClosestPoint) + 4) - v11->y)
                                * (float)(*(float *)(LODWORD(vecClosestPoint) + 4) - v11->y))
                        + (float)((float)(*(float *)LODWORD(vecClosestPoint) - v11->x)
                                * (float)(*(float *)LODWORD(vecClosestPoint) - v11->x)))
                + (float)((float)(*(float *)(LODWORD(vecClosestPoint) + 8) - v11->z)
                        * (float)(*(float *)(LODWORD(vecClosestPoint) + 8) - v11->z))) <= this->m_pFastSortInfo[v14->m_nStartSpriteIndex].m_flDistance;
    vecClosestPoint = (float)((float)((float)(*(float *)(LODWORD(vecClosestPoint) + 4) - v11->y)
                                    * (float)(*(float *)(LODWORD(vecClosestPoint) + 4) - v11->y))
                            + (float)((float)(*(float *)LODWORD(vecClosestPoint) - v11->x)
                                    * (float)(*(float *)LODWORD(vecClosestPoint) - v11->x)))
                    + (float)((float)(*(float *)(LODWORD(vecClosestPoint) + 8) - v11->z)
                            * (float)(*(float *)(LODWORD(vecClosestPoint) + 8) - v11->z));
    if ( v16 )
    {
      bFirstCallThisFrame = m_nNumPendingSprites;
      v17 = materials->GetRenderContext(this: materials);
      v18 = v17;
      pRenderContext.m_pObject = v17;
      if ( v17 != nullptr )
        v17->BeginRender(this: v17);
      v18->MatrixMode(this: v18, a2: MATERIAL_MODEL);
      v18->PushMatrix(this: v18);
      v18->LoadIdentity(this: v18);
      m_pMaterial = this->m_DetailSpriteMaterial.m_pMaterial;
      if ( ShouldDrawInWireFrameMode()
        || r_DrawDetailProps.m_pParent != nullptr && r_DrawDetailProps.m_pParent->m_Value.m_nValue == 2 )
      {
        m_pMaterial = this->m_DetailWireframeMaterial.m_pMaterial;
      }
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      if ( r_FlashlightDetailProps.m_pParent != nullptr )
        m_nValue = r_FlashlightDetailProps.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v21 = m_nValue - 1;
      if ( v21 != 0 )
      {
        if ( v21 == 1 )
          viewRight = DPFM_MULTIPASS;
        else
          viewRight = DPFM_NONE;
      }
      else
      {
        viewRight = DPFM_SINGLEPASS;
      }
      v22 = v18->GetDynamicMesh(this: v18, a2: false, a3: nullptr, a4: nullptr, a5: m_pMaterial);
      GetMaxToRender = v18->GetMaxToRender;
      v24 = v22;
      pMesh = v22;
      GetMaxToRender(this: v18, a2: v22, a3: false, a4: &nMaxVerts, a5: &info);
      v25 = bFirstCallThisFrame;
      v26 = info / 6;
      if ( info / 6 > nMaxVerts / 4 )
        v26 = nMaxVerts / 4;
      if ( (int)bFirstCallThisFrame >= v26 )
      {
        viewForward = (const Vector *)v26;
        v25 = (const Vector *)v26;
      }
      else
      {
        viewForward = bFirstCallThisFrame;
      }
      viewOrigin = v25;
      v27 = 4 * (_DWORD)v25;
      meshBuilder.m_pMesh = v24;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_QUADS;
      SetPrimitiveType = v24->SetPrimitiveType;
      v29 = 6 * (_DWORD)v25;
      v79 = v29;
      SetPrimitiveType(this: v24, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v27, a3: v29, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v24->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v29;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v24,
        nMaxVertexCount: v27,
        desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      m_pBuildoutBuffer = (const FastSpriteQuadBuildoutBufferNonSIMDView_t *)v82->m_pBuildoutBuffer;
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      v32 = (const Vector *)&v82->m_pFastSortInfo[pData->m_nStartSpriteIndex];
      viewUp = (const CDetailObjectSystem::SortInfo_t *)v32;
      pQuadBuffer = m_pBuildoutBuffer;
      if ( bFirstCallThisFrame != nullptr )
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        do
        {
          if ( v32->y < vecClosestPoint )
            break;
          v34 = (int)viewOrigin;
          if ( viewOrigin == nullptr )
          {
            if ( meshBuilder.m_bGenerateIndices )
            {
              switch ( meshBuilder.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  v35 = 2 * m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  v35 = 2 * m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  v35 = 3 * m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  v35 = 6 * m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  v35 = 0;
                  break;
                default:
                  v35 = m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(
                this: &meshBuilder.m_IndexBuilder,
                primitiveType: meshBuilder.m_Type,
                nIndexCount: v35);
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
            }
            meshBuilder.m_pMesh->UnlockMesh(
              this: meshBuilder.m_pMesh,
              a2: m_nVertexCount,
              a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
              a4: &meshBuilder);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_pMesh = nullptr;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v24->Draw_2(this: v24, a2: -1, a3: 0);
            if ( viewRight == DPFM_MULTIPASS )
              shadowmgr->FlashlightDrawCallback(this: shadowmgr, a2: DrawMeshCallback, a3: v24);
            v36 = (int)viewForward;
            meshBuilder.m_pMesh = v24;
            meshBuilder.m_bGenerateIndices = true;
            meshBuilder.m_Type = MATERIAL_QUADS;
            v37 = v24->SetPrimitiveType;
            viewOrigin = viewForward;
            v37(this: v24, a2: MATERIAL_TRIANGLES);
            v36 *= 4;
            meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v36, a3: v29, a4: &meshBuilder, a5: nullptr);
            meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
            meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v24->IIndexBuffer;
            meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v29;
            meshBuilder.m_IndexBuilder.m_bModify = false;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            CVertexBuilder::AttachBegin(
              this: &meshBuilder.m_VertexBuilder,
              pMesh: v24,
              nMaxVertexCount: v36,
              desc: &meshBuilder);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
            v34 = (int)viewOrigin;
          }
          if ( (int)bFirstCallThisFrame < v34 )
            v34 = (int)bFirstCallThisFrame;
          viewOrigin = (const Vector *)((char *)viewOrigin - v34);
          bFirstCallThisFrame = (const Vector *)((char *)bFirstCallThisFrame - v34);
          if ( v34 != 0 )
          {
            do
            {
              nToDraw = v34 - 1;
              v38 = *(_DWORD *)viewUp & 3;
              v39 = &pQuadBuffer[(int)(*(_DWORD *)viewUp << 8) >> 10];
              v40 = v39->m_pSpriteDefs[v38];
              v41 = v39->m_flX0[v38];
              v42 = v39->m_RGBColor[v38][0];
              v43 = v39->m_flY0[v38];
              v44 = v39->m_flZ0[v38];
              p_x = &v39->m_Normal.x;
              v46 = (char *)&v39->m_flX0[v38];
              BYTE1(nLeaf) = v46[193];
              BYTE2(nLeaf) = v46[194];
              LOBYTE(v38) = v46[208];
              *m_pCurrPosition = v41;
              HIBYTE(nLeaf) = v38;
              m_pCurrPosition[1] = v43;
              m_pCurrPosition[2] = v44;
              v47 = BYTE2(nLeaf) | ((BYTE1(nLeaf) | ((v42 | (HIBYTE(nLeaf) << 8)) << 8)) << 8);
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v47;
              v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              y = v40->m_TexLR.y;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v40->m_TexLR.x;
              v48[1] = y;
              m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
              m_pCurrNormal[1] = p_x[1];
              m_pCurrNormal[2] = p_x[2];
              v51 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
              meshBuilder.m_VertexBuilder.m_nCurrentVertex = v51;
              if ( v51 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                meshBuilder.m_VertexBuilder.m_nVertexCount = v51;
              meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
              v52 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
              meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                       + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
              meshBuilder.m_VertexBuilder.m_pCurrPosition = v52;
              v53 = *((_DWORD *)v46 + 16);
              v54 = *((_DWORD *)v46 + 20);
              *v52 = *((float *)v46 + 12);
              *((_DWORD *)v52 + 1) = v53;
              *((_DWORD *)v52 + 2) = v54;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v47;
              v55 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              v56 = v40->m_TexUL.y;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v40->m_TexLR.x;
              v55[1] = v56;
              v57 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
              v57[1] = p_x[1];
              v57[2] = p_x[2];
              v58 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
              meshBuilder.m_VertexBuilder.m_nCurrentVertex = v58;
              if ( v58 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                meshBuilder.m_VertexBuilder.m_nVertexCount = v58;
              meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
              v59 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
              meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                       + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
              meshBuilder.m_VertexBuilder.m_pCurrPosition = v59;
              v60 = *((_DWORD *)v46 + 28);
              v61 = *((_DWORD *)v46 + 32);
              *v59 = *((float *)v46 + 24);
              *((_DWORD *)v59 + 1) = v60;
              *((_DWORD *)v59 + 2) = v61;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v47;
              v62 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              v63 = v40->m_TexUL.y;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v40->m_TexUL.x;
              v62[1] = v63;
              v64 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
              v64[1] = p_x[1];
              v64[2] = p_x[2];
              v65 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
              meshBuilder.m_VertexBuilder.m_nCurrentVertex = v65;
              if ( v65 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                meshBuilder.m_VertexBuilder.m_nVertexCount = v65;
              meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
              meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
              v66 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                       + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
              meshBuilder.m_VertexBuilder.m_pCurrPosition = v66;
              v67 = *((_DWORD *)v46 + 40);
              v68 = *((_DWORD *)v46 + 44);
              *v66 = *((float *)v46 + 36);
              *((_DWORD *)v66 + 1) = v67;
              *((_DWORD *)v66 + 2) = v68;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v47;
              v69 = v40->m_TexLR.y;
              v70 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v40->m_TexUL.x;
              v70[1] = v69;
              v71 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
              v71[1] = p_x[1];
              v71[2] = p_x[2];
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              v72 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
              meshBuilder.m_VertexBuilder.m_nCurrentVertex = v72;
              if ( v72 > meshBuilder.m_VertexBuilder.m_nVertexCount )
              {
                m_nVertexCount = v72;
                meshBuilder.m_VertexBuilder.m_nVertexCount = v72;
              }
              meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
              meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
              m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
              v34 = nToDraw;
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                       + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
              ++viewUp;
              meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
            }
            while ( nToDraw != 0 );
            v24 = pMesh;
            v29 = v79;
          }
          v32 = (const Vector *)viewUp;
        }
        while ( bFirstCallThisFrame != nullptr );
      }
      pData->m_nNumPendingSprites = (int)bFirstCallThisFrame;
      v73 = !meshBuilder.m_bGenerateIndices;
      pData->m_nStartSpriteIndex = ((char *)v32 - (char *)v82->m_pFastSortInfo) >> 3;
      if ( !v73 )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            m_nVertexCount = 2 * m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            m_nVertexCount *= 2;
            break;
          case MATERIAL_POLYGON:
            m_nVertexCount = 3 * m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            m_nVertexCount = 6 * m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            m_nVertexCount = 0;
            break;
          default:
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: m_nVertexCount);
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      }
      meshBuilder.m_pMesh->UnlockMesh(
        this: meshBuilder.m_pMesh,
        a2: m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
        a4: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_pMesh = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      v24->Draw_2(this: v24, a2: -1, a3: 0);
      if ( viewRight == DPFM_MULTIPASS )
        shadowmgr->FlashlightDrawCallback(this: shadowmgr, a2: DrawMeshCallback, a3: v24);
      m_pObject = pRenderContext.m_pObject;
      pRenderContext.m_pObject->PopMatrix(this: pRenderContext.m_pObject);
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE030
// Name: public: virtual void CDetailObjectSystem::BuildRenderingData(class CUtlVectorFixedGrowable<struct DetailRenderableInfo_t,2048> __near &,struct SetupRenderInfo_t const __near &,float,struct DistanceFadeInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::BuildRenderingData(
        CDetailObjectSystem *this,
        CUtlVectorFixedGrowable<DetailRenderableInfo_t,2048> *list,
        const SetupRenderInfo_t *info,
        float flDetailDist,
        const DistanceFadeInfo_t *fadeInfo)
{
  IClientMode *ClientMode; // eax
  ISpatialQuery *v7; // esi
  WorldListLeafData_t *m_pLeafDataList; // edx
  void *v9; // esp
  int (__thiscall *ListLeavesInSphereWithFlagSet)(ISpatialQuery *, int *, const Vector *, float, int, const unsigned __int16 *, int, int); // edx
  Vector *p_m_vecRenderOrigin; // edi
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  void (__thiscall *GetDetailObjectsInLeaf)(IClientLeafSystem *, int, int *, int *); // edx
  int v17; // esi
  int v18; // esi
  float *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DetailRenderableInfo_t *m_pMemory; // ecx
  int v26; // eax
  DetailRenderableInfo_t *v27; // edi
  BOOL v28; // eax
  const Vector *v29; // eax
  const Vector *v30; // eax
  _BYTE v31[12]; // [esp+14h] [ebp-44h] BYREF
  Vector forward; // [esp+20h] [ebp-38h] BYREF
  Vector v33; // [esp+2Ch] [ebp-2Ch] BYREF
  int nListLeafIndex; // [esp+38h] [ebp-20h]
  int i; // [esp+3Ch] [ebp-1Ch]
  CDetailObjectSystem *v36; // [esp+40h] [ebp-18h]
  int nFirstDetailObject; // [esp+44h] [ebp-14h] BYREF
  int *pValidLeafIndex; // [esp+48h] [ebp-10h]
  int nDetailObjectCount; // [esp+4Ch] [ebp-Ch] BYREF
  Vector *v40; // [esp+50h] [ebp-8h]
  const WorldListLeafData_t *pLeafData; // [esp+54h] [ebp-4h]
  int j; // [esp+60h] [ebp+8h]
  int nLeafCount; // [esp+64h] [ebp+Ch]
  char nLeafCount_3; // [esp+67h] [ebp+Fh]
  int nValidLeafs; // [esp+68h] [ebp+10h]

  v36 = this;
  ClientMode = GetClientMode();
  if ( ClientMode->ShouldDrawDetailObjects(this: ClientMode)
    && r_DrawDetailProps.m_pParent != nullptr
    && r_DrawDetailProps.m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = engine->GetBSPTreeQuery(this: engine);
    m_pLeafDataList = info->m_pWorldListInfo->m_pLeafDataList;
    nLeafCount = info->m_pWorldListInfo->m_LeafCount;
    pLeafData = m_pLeafDataList;
    v9 = alloca(4 * nLeafCount);
    ListLeavesInSphereWithFlagSet = v7->ListLeavesInSphereWithFlagSet;
    p_m_vecRenderOrigin = &info->m_vecRenderOrigin;
    pValidLeafIndex = (int *)v31;
    v40 = &info->m_vecRenderOrigin;
    v12 = ((int (__thiscall *)(ISpatialQuery *, _BYTE *, Vector *, _DWORD, int, const WorldListLeafData_t *, int, int))ListLeavesInSphereWithFlagSet)(
            a1: v7,
            a2: v31,
            a3: &info->m_vecRenderOrigin,
            a4: LODWORD(flDetailDist),
            a5: nLeafCount,
            a6: pLeafData,
            a7: 8,
            a8: 8);
    nValidLeafs = v12;
    if ( v12 != 0 )
    {
      v13 = 0;
      if ( v12 > 0 )
      {
        do
          g_pClientLeafSystem->DrawDetailObjectsInLeaf(
            this: g_pClientLeafSystem,
            a2: pLeafData[pValidLeafIndex[v13++]].leafIndex,
            a3: info->m_nDetailBuildFrame,
            a4: &nFirstDetailObject,
            a5: &nDetailObjectCount);
        while ( v13 < nValidLeafs );
        v12 = nValidLeafs;
      }
      if ( v36->m_DetailObjects.m_Size != 0 )
      {
        v14 = 0;
        i = 0;
        if ( v12 > 0 )
        {
          do
          {
            GetDetailObjectsInLeaf = g_pClientLeafSystem->GetDetailObjectsInLeaf;
            nListLeafIndex = pValidLeafIndex[v14];
            ((void (__stdcall *)(_DWORD, int *, int *))GetDetailObjectsInLeaf)(
              a1: pLeafData[nListLeafIndex].leafIndex,
              a2: &nFirstDetailObject,
              a3: &nDetailObjectCount);
            v17 = 0;
            for ( j = 0; v17 < nDetailObjectCount; j = v17 )
            {
              v18 = (int)&v36->m_DetailObjects.m_Memory.m_pMemory[nFirstDetailObject + v17];
              if ( (*(_BYTE *)(v18 + 36) & 0xC) == 0 )
              {
                v19 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)(v18 + 4) + 4))(a1: v18 + 4);
                v20 = p_m_vecRenderOrigin->y - v19[1];
                v21 = p_m_vecRenderOrigin->z - v19[2];
                v22 = (float)((float)(v20 * v20)
                            + (float)((float)(p_m_vecRenderOrigin->x - *v19) * (float)(p_m_vecRenderOrigin->x - *v19)))
                    + (float)(v21 * v21);
                if ( v22 < fadeInfo->m_flMaxDistSqr )
                {
                  nLeafCount_3 = -1;
                  if ( v22 <= fadeInfo->m_flMinDistSqr
                    || (nLeafCount_3 = (int)(float)((float)(fadeInfo->m_flMaxDistSqr - v22)
                                                  * (float)(fadeInfo->m_flFalloffFactor * 255.0))) != 0 )
                  {
                    m_Size = list->m_Size;
                    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
                    if ( m_Size + 1 > m_nAllocationCount )
                      CUtlMemoryFixedGrowable<DetailRenderableInfo_t,2048,int>::Grow(
                        this: &list->m_Memory,
                        nCount: m_Size - m_nAllocationCount + 1);
                    ++list->m_Size;
                    m_pMemory = list->m_Memory.m_pMemory;
                    v26 = list->m_Size - m_Size - 1;
                    list->m_pElements = list->m_Memory.m_pMemory;
                    if ( v26 > 0 )
                      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v26);
                    v27 = &list->m_Memory.m_pMemory[m_Size];
                    v27->m_pRenderable = (IClientRenderable *)(v18 + 4);
                    v27->m_InstanceData.m_nAlpha = nLeafCount_3;
                    v28 = nLeafCount_3 != -1 || (*(_BYTE *)(v18 + 36) & 0x40) != 0;
                    v27->m_nRenderGroup = v28;
                    v27->m_nLeafIndex = nListLeafIndex;
                    if ( (*(_BYTE *)(v18 + 36) & 3) == 1 )
                    {
                      v30 = CurrentViewOrigin();
                      forward.x = v30->x - *(float *)(v18 + 8);
                      forward.y = v30->y - *(float *)(v18 + 12);
                      forward.z = v30->z - *(float *)(v18 + 16);
                      VectorAngles(&forward, angles: (QAngle *)(v18 + 20));
                    }
                    else if ( (*(_BYTE *)(v18 + 36) & 3) == 2 )
                    {
                      v29 = CurrentViewOrigin();
                      v33.x = v29->x - *(float *)(v18 + 8);
                      v33.y = v29->y - *(float *)(v18 + 12);
                      v33.z = 0.0;
                      VectorAngles(forward: &v33, angles: (QAngle *)(v18 + 20));
                    }
                    p_m_vecRenderOrigin = v40;
                  }
                }
              }
              v17 = j + 1;
            }
            v14 = i + 1;
            i = v14;
          }
          while ( v14 < nValidLeafs );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE330
// Name: s_RenderFastSpriteGuts
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_RenderFastSpriteGuts(
        CDetailObjectSystem *pThis,
        DistanceFadeInfo_t info,
        Vector viewOrigin,
        Vector viewForward,
        Vector viewRight,
        Vector viewUp,
        int nNumLeafs,
        const CUtlEnvelope<unsigned short> *leaflist)
{
  const CUtlEnvelope<unsigned short> *m_pData; // eax
  int m_nBytes; // ecx

  m_pData = leaflist;
  m_nBytes = leaflist->m_nBytes;
  if ( m_nBytes != 0 )
  {
    if ( m_nBytes > 4 )
      m_pData = (const CUtlEnvelope<unsigned short> *)leaflist->m_pData;
  }
  else
  {
    m_pData = nullptr;
  }
  CDetailObjectSystem::RenderFastSprites(
    this: pThis,
    &info,
    &viewOrigin,
    &viewForward,
    &viewRight,
    &viewUp,
    nLeafCount: nNumLeafs,
    pLeafList: (const unsigned __int16 *)m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x100CE370
// Name: public: virtual void CDetailObjectSystem::RenderTranslucentDetailObjects(struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDetailObjectSystem::RenderTranslucentDetailObjects(
        CDetailObjectSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const DistanceFadeInfo_t *info,
        const Vector *viewOrigin,
        const Vector *viewForward,
        const Vector *viewRight,
        const Vector *viewUp,
        int nLeafCount,
        unsigned __int16 *pLeafList)
{
  int m_nValue; // eax
  int v12; // eax
  IShadowMgr_vtbl *v13; // edx
  IMatRenderContext *v14; // eax
  IMatRenderContext *m_pObject; // esi
  ICallQueue *v16; // ebx
  const CUtlEnvelope<unsigned short> *v17; // eax
  int v18; // edi
  IMaterial *m_pMaterial; // ebx
  IMesh *v20; // ebx
  int v21; // ecx
  int v22; // edi
  int v23; // esi
  CDetailObjectSystem::SortInfo_t *m_pSortInfo; // edi
  int v25; // eax
  int v26; // esi
  CDetailModel *v27; // ecx
  int m_nVertexCount; // eax
  int v29; // esi
  int v30; // edi
  int v31; // esi
  int v32; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-228h] BYREF
  int nDetailObjectCount; // [esp+1ECh] [ebp-40h] BYREF
  CDetailObjectSystem::SortInfo_t *pSortInfo; // [esp+1F0h] [ebp-3Ch]
  CUtlEnvelope<unsigned short> v38; // [esp+1F4h] [ebp-38h] BYREF
  int nQuadsInModel; // [esp+1FCh] [ebp-30h]
  CDetailModel *model; // [esp+200h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+204h] [ebp-28h]
  int nMaxIndices; // [esp+208h] [ebp-24h] BYREF
  int nCount; // [esp+20Ch] [ebp-20h]
  int nMaxVerts; // [esp+210h] [ebp-1Ch] BYREF
  int nQuadCount; // [esp+214h] [ebp-18h]
  unsigned __int8 nAlpha[4]; // [esp+218h] [ebp-14h]
  int j; // [esp+21Ch] [ebp-10h] BYREF
  CDetailObjectSystem *v48; // [esp+220h] [ebp-Ch]
  int i; // [esp+224h] [ebp-8h]
  DetailPropFlashlightMode_t flashlightMode; // [esp+228h] [ebp-4h]
  int nMaxQuadsToDraw; // [esp+23Ch] [ebp+10h]
  int nQuadsDrawna; // [esp+240h] [ebp+14h]
  int nQuadsDrawn; // [esp+240h] [ebp+14h]
  int nQuadsToDraw; // [esp+244h] [ebp+18h]

  v48 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDetailObjectSystem::RenderTranslucentDetailObjects",
    a3: 0,
    a4: "Detail_Prop_Rendering",
    a5: false,
    a6: 4);
  if ( nLeafCount != 0 )
  {
    if ( r_FlashlightDetailProps.m_pParent != nullptr )
      m_nValue = r_FlashlightDetailProps.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v12 = m_nValue - 1;
    if ( v12 != 0 )
    {
      if ( --v12 != 0 )
        flashlightMode = DPFM_NONE;
      else
        flashlightMode = DPFM_MULTIPASS;
    }
    else
    {
      flashlightMode = DPFM_SINGLEPASS;
    }
    v13 = shadowmgr->__vftable;
    LOBYTE(v12) = flashlightMode == DPFM_SINGLEPASS;
    LOBYTE(i) = flashlightMode == DPFM_SINGLEPASS;
    v13->PushSinglePassFlashlightStateEnabled(this: shadowmgr, a2: v12);
    v14 = materials->GetRenderContext(this: materials);
    m_pObject = v14;
    pRenderContext.m_pObject = v14;
    if ( v14 != nullptr )
      v14->BeginRender(this: v14);
    v16 = m_pObject->GetCallQueue(this: m_pObject);
    if ( v16 != nullptr
      && r_ThreadedDetailProps.m_pParent != nullptr
      && r_ThreadedDetailProps.m_pParent->m_Value.m_nValue != 0 )
    {
      j = (int)this;
      v17 = CUtlEnvelope<unsigned short>::CUtlEnvelope<unsigned short>(this: &v38, pData: pLeafList, nElems: nLeafCount);
      ICallQueue::QueueCall<void,CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &,CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>>(
        this: v16,
        pfnProxied: s_RenderFastSpriteGuts,
        arg1: (CDetailObjectSystem *const *)&j,
        arg2: info,
        arg3: viewOrigin,
        arg4: viewForward,
        arg5: viewRight,
        arg6: viewUp,
        arg7: &nLeafCount,
        arg8: v17);
      if ( v38.m_nBytes > 4 )
        C_BaseEntity::operator delete(pMem: v38.m_pData);
    }
    else
    {
      CDetailObjectSystem::RenderFastSprites(
        this,
        a2: (int)this,
        a3: (int)m_pObject,
        info,
        viewOrigin,
        viewForward,
        viewRight,
        viewUp,
        nLeafCount,
        pLeafList);
    }
    shadowmgr->PopSinglePassFlashlightStateEnabled(this: shadowmgr);
    v18 = CDetailObjectSystem::CountSpriteQuadsInLeafList(this, nLeafCount, pLeafList);
    nQuadCount = v18;
    if ( v18 != 0 )
    {
      ((void (__thiscall *)(IShadowMgr *, int, int, int))shadowmgr->PushSinglePassFlashlightStateEnabled)(
        a1: shadowmgr,
        a2: i,
        a3: a2,
        a4: a3);
      m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
      m_pObject->PushMatrix(this: m_pObject);
      m_pObject->LoadIdentity(this: m_pObject);
      m_pMaterial = v48->m_DetailSpriteMaterial.m_pMaterial;
      if ( ShouldDrawInWireFrameMode()
        || r_DrawDetailProps.m_pParent != nullptr && r_DrawDetailProps.m_pParent->m_Value.m_nValue == 2 )
      {
        m_pMaterial = v48->m_DetailWireframeMaterial.m_pMaterial;
      }
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      v20 = m_pObject->GetDynamicMesh(
              this: m_pObject,
              a2: flashlightMode != DPFM_MULTIPASS,
              a3: nullptr,
              a4: nullptr,
              a5: m_pMaterial);
      m_pObject->GetMaxToRender(this: m_pObject, a2: v20, a3: false, a4: &nMaxVerts, a5: &nMaxIndices);
      v21 = nMaxIndices / 6;
      nMaxQuadsToDraw = nMaxIndices / 6;
      if ( nMaxIndices / 6 > nMaxVerts / 4 )
      {
        nMaxQuadsToDraw = nMaxVerts / 4;
        v21 = nMaxVerts / 4;
      }
      nQuadsToDraw = v18;
      if ( v18 > v21 )
      {
        nQuadsToDraw = v21;
        v18 = v21;
      }
      meshBuilder.m_pMesh = v20;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_QUADS;
      nQuadsDrawna = 4 * v18;
      v22 = 6 * v18;
      v20->SetPrimitiveType(this: v20, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: nQuadsDrawna, a3: v22, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v20->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v22;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v20,
        nMaxVertexCount: nQuadsDrawna,
        desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      nQuadsDrawn = 0;
      i = 0;
      if ( nLeafCount > 0 )
      {
        do
        {
          v23 = pLeafList[i];
          g_pClientLeafSystem->GetDetailObjectsInLeaf(
            this: g_pClientLeafSystem,
            a2: v23,
            a3: &v38.m_nBytes,
            a4: &nDetailObjectCount);
          m_pSortInfo = v48->m_pSortInfo;
          pSortInfo = m_pSortInfo;
          v25 = CDetailObjectSystem::SortSpritesBackToFront(
                  this: v48,
                  nLeaf: v23,
                  viewOrigin,
                  fadeInfo: info,
                  pSortInfo: m_pSortInfo);
          v26 = 0;
          nCount = v25;
          for ( j = 0; v26 < nCount; j = v26 )
          {
            v27 = &v48->m_DetailObjects.m_Memory.m_pMemory[(int)(*(_DWORD *)&m_pSortInfo[v26] << 8) >> 8];
            nQuadsInModel = s_pQuadCount[(*((unsigned __int8 *)v27 + 36) >> 2) & 3];
            model = v27;
            if ( nQuadsDrawn + nQuadsInModel > nQuadsToDraw )
            {
              if ( meshBuilder.m_bGenerateIndices )
              {
                switch ( meshBuilder.m_Type )
                {
                  case MATERIAL_LINE_STRIP:
                    m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                    break;
                  case MATERIAL_LINE_LOOP:
                    m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                    break;
                  case MATERIAL_POLYGON:
                    m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                    break;
                  case MATERIAL_QUADS:
                    m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                    break;
                  case MATERIAL_INSTANCED_QUADS:
                    m_nVertexCount = 0;
                    break;
                  default:
                    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                    break;
                }
                CIndexBuilder::GenerateIndices(
                  this: &meshBuilder.m_IndexBuilder,
                  primitiveType: meshBuilder.m_Type,
                  nIndexCount: m_nVertexCount);
              }
              meshBuilder.m_pMesh->UnlockMesh(
                this: meshBuilder.m_pMesh,
                a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
                a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
                a4: &meshBuilder);
              meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
              meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
              meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
              meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
              meshBuilder.m_pMesh = nullptr;
              meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
              v20->Draw_2(this: v20, a2: -1, a3: 0);
              if ( flashlightMode == DPFM_MULTIPASS )
                shadowmgr->FlashlightDrawCallback(this: shadowmgr, a2: DrawMeshCallback, a3: v20);
              v29 = nQuadCount - nQuadsDrawn;
              nQuadCount = v29;
              nQuadsToDraw = v29;
              if ( v29 > nMaxQuadsToDraw )
              {
                nQuadsToDraw = nMaxQuadsToDraw;
                v29 = nMaxQuadsToDraw;
              }
              meshBuilder.m_pMesh = v20;
              meshBuilder.m_bGenerateIndices = true;
              meshBuilder.m_Type = MATERIAL_QUADS;
              v30 = 4 * v29;
              v31 = 6 * v29;
              v20->SetPrimitiveType(this: v20, a2: MATERIAL_TRIANGLES);
              meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v30, a3: v31, a4: &meshBuilder, a5: nullptr);
              meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v20->IIndexBuffer;
              meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
              meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v31;
              meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
              meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
              meshBuilder.m_IndexBuilder.m_bModify = false;
              meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
              meshBuilder.m_VertexBuilder.m_pVertexBuffer = v20;
              meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
              meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4 * nQuadsToDraw;
              meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
              meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
              meshBuilder.m_VertexBuilder.m_bModify = false;
              if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
              {
                meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
                meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
                meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
              }
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
              CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
              m_pSortInfo = pSortInfo;
              v27 = model;
              nQuadsDrawn = 0;
              v26 = j;
            }
            nAlpha[0] = *((_BYTE *)&m_pSortInfo[v26] + 3);
            switch ( (*((unsigned __int8 *)v27 + 36) >> 2) & 3 )
            {
              case 1:
                CDetailModel::DrawTypeSprite(this: v27, &meshBuilder, nAlpha: nAlpha[0]);
                break;
              case 2:
                CDetailModel::DrawTypeShapeCross(this: v27, &meshBuilder, nAlpha: nAlpha[0]);
                break;
              case 3:
                CDetailModel::DrawTypeShapeTri(this: v27, &meshBuilder, nAlpha: nAlpha[0]);
                break;
              default:
                break;
            }
            nQuadsDrawn += nQuadsInModel;
            ++v26;
          }
          ++i;
        }
        while ( i < nLeafCount );
        m_pObject = pRenderContext.m_pObject;
      }
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            v32 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            v32 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            v32 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            v32 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            v32 = 0;
            break;
          default:
            v32 = meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: v32);
      }
      ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      v20->Draw_2(this: v20, a2: -1, a3: 0);
      if ( flashlightMode == DPFM_MULTIPASS )
        shadowmgr->FlashlightDrawCallback(this: shadowmgr, a2: DrawMeshCallback, a3: v20);
      shadowmgr->PopSinglePassFlashlightStateEnabled(this: shadowmgr);
      m_pObject->PopMatrix(this: m_pObject);
      if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
        && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
      {
        meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
      }
      if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
        && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
      {
        meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
      }
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
    else
    {
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CEB20
// Name: public: virtual void CDetailObjectSystem::RenderTranslucentDetailObjectsInLeaf(struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::RenderTranslucentDetailObjectsInLeaf(
        CDetailObjectSystem *this,
        const DistanceFadeInfo_t *info,
        const Vector *viewOrigin,
        const Vector *viewForward,
        CDetailModel *viewRight,
        const Vector *viewUp,
        int nLeaf,
        const Vector *pVecClosestPoint)
{
  int m_nValue; // eax
  int v10; // eax
  int v11; // edi
  IMatRenderContext *v12; // eax
  IMatRenderContext *v13; // edi
  ICallQueue *v14; // eax
  __int64 v15; // xmm0_8
  bool *p_m_bFirstLeaf; // ebx
  const Vector *v17; // ebx
  int m_nFirstSprite; // ecx
  float v19; // xmm0_4
  const Vector *v20; // ebx
  IMaterial *m_pMaterial; // edi
  IMesh *v22; // edi
  int v23; // ecx
  int v24; // ebx
  int v25; // edx
  int v26; // eax
  CDetailObjectSystem::SortInfo_t *m_pSortInfo; // ecx
  float m_flDistance; // xmm0_4
  CDetailObjectSystem::SortInfo_t *v29; // eax
  CDetailModel *v30; // ecx
  int m_nVertexCount; // eax
  int v32; // eax
  const Vector *v33; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-220h] BYREF
  DistanceFadeInfo_t arg2; // [esp+1F4h] [ebp-38h] BYREF
  __int64 v36; // [esp+200h] [ebp-2Ch]
  __int64 v37; // [esp+208h] [ebp-24h]
  int nMaxIndices; // [esp+210h] [ebp-1Ch] BYREF
  int nMaxVerts; // [esp+214h] [ebp-18h] BYREF
  Vector cpnt; // [esp+218h] [ebp-14h] BYREF
  CFastDetailLeafSpriteList *pData; // [esp+224h] [ebp-8h] BYREF
  DetailPropFlashlightMode_t flashlightMode; // [esp+228h] [ebp-4h]
  unsigned __int8 infoa; // [esp+234h] [ebp+8h]
  int nQuadsDrawn; // [esp+238h] [ebp+Ch]
  int nQuadsInModel; // [esp+23Ch] [ebp+10h]
  CDetailModel *model; // [esp+240h] [ebp+14h]
  float flMinDistance; // [esp+244h] [ebp+18h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDetailObjectSystem::RenderTranslucentDetailObjectsInLeaf",
    a3: 0,
    a4: "Detail_Prop_Rendering",
    a5: false,
    a6: 4);
  if ( r_DrawDetailProps.m_pParent != nullptr && r_DrawDetailProps.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( r_FlashlightDetailProps.m_pParent != nullptr )
      m_nValue = r_FlashlightDetailProps.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v10 = m_nValue - 1;
    if ( v10 != 0 )
    {
      if ( v10 == 1 )
        flashlightMode = DPFM_MULTIPASS;
      else
        flashlightMode = DPFM_NONE;
    }
    else
    {
      flashlightMode = DPFM_SINGLEPASS;
    }
    v11 = nLeaf;
    pData = (CFastDetailLeafSpriteList *)g_pClientLeafSystem->GetSubSystemDataInLeaf(
                                           this: g_pClientLeafSystem,
                                           a2: nLeaf,
                                           a3: 0);
    if ( pData != nullptr )
    {
      shadowmgr->PushSinglePassFlashlightStateEnabled(this: shadowmgr, a2: flashlightMode == DPFM_SINGLEPASS);
      v12 = materials->GetRenderContext(this: materials);
      v13 = v12;
      if ( v12 != nullptr )
        v12->BeginRender(this: v12);
      v14 = v13->GetCallQueue(this: v13);
      cpnt = *viewOrigin;
      if ( pVecClosestPoint != nullptr )
        cpnt = *pVecClosestPoint;
      if ( v14 != nullptr
        && r_ThreadedDetailProps.m_pParent != nullptr
        && r_ThreadedDetailProps.m_pParent->m_Value.m_nValue != 0 )
      {
        v15 = *(_QWORD *)&info->m_flMaxDistSqr;
        arg2.m_flFalloffFactor = info->m_flFalloffFactor;
        v37 = 0;
        p_m_bFirstLeaf = &this->m_bFirstLeaf;
        *(_QWORD *)&arg2.m_flMaxDistSqr = v15;
        v36 = (unsigned int)CDetailObjectSystem::RenderFastTranslucentDetailObjectsInLeaf;
        ICallQueue::QueueCall<CDetailObjectSystem *,CDetailObjectSystem,void,CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool,CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool>(
          this: v14,
          pObject: this,
          pfnProxied: (unsigned int)CDetailObjectSystem::RenderFastTranslucentDetailObjectsInLeaf,
          arg1: &pData,
          &arg2,
          arg3: viewOrigin,
          arg4: viewForward,
          arg5: (const Vector *)viewRight,
          arg6: viewUp,
          arg7: &nLeaf,
          arg8: &cpnt,
          arg9: &this->m_bFirstLeaf);
      }
      else
      {
        p_m_bFirstLeaf = &this->m_bFirstLeaf;
        CDetailObjectSystem::RenderFastTranslucentDetailObjectsInLeaf(
          this,
          pData,
          (int)info,
          viewOrigin,
          viewForward,
          (DetailPropFlashlightMode_t)viewRight,
          (const CDetailObjectSystem::SortInfo_t *)viewUp,
          nLeaf,
          vecClosestPoint: COERCE_FLOAT(&cpnt),
          bFirstCallThisFrame: (const Vector *)this->m_bFirstLeaf);
      }
      *p_m_bFirstLeaf = false;
      shadowmgr->PopSinglePassFlashlightStateEnabled(this: shadowmgr);
      v13->EndRender(this: v13);
      v13->Release(this: v13);
      v11 = nLeaf;
    }
    if ( this->m_nSortedLeaf == v11 )
    {
      v17 = viewOrigin;
    }
    else
    {
      nLeaf = (unsigned __int16)v11;
      this->m_nSortedLeaf = v11;
      this->m_nSpriteCount = 0;
      this->m_nFirstSprite = 0;
      if ( CDetailObjectSystem::CountSpritesInLeafList(this, nLeafCount: 1, pLeafList: (unsigned __int16 *)&nLeaf) == 0 )
        goto LABEL_76;
      v17 = viewOrigin;
      this->m_nSpriteCount = CDetailObjectSystem::SortSpritesBackToFront(
                               this,
                               nLeaf: v11,
                               viewOrigin,
                               fadeInfo: info,
                               pSortInfo: this->m_pSortInfo);
    }
    m_nFirstSprite = this->m_nFirstSprite;
    if ( this->m_nSpriteCount != m_nFirstSprite )
    {
      v19 = 0.0;
      flMinDistance = 0.0;
      if ( pVecClosestPoint != nullptr )
      {
        v19 = (float)((float)((float)(pVecClosestPoint->y - v17->y) * (float)(pVecClosestPoint->y - v17->y))
                    + (float)((float)(pVecClosestPoint->x - v17->x) * (float)(pVecClosestPoint->x - v17->x)))
            + (float)((float)(pVecClosestPoint->z - v17->z) * (float)(pVecClosestPoint->z - v17->z));
        flMinDistance = v19;
      }
      if ( v19 <= this->m_pSortInfo[m_nFirstSprite].m_flDistance )
      {
        v20 = (const Vector *)materials->GetRenderContext(this: materials);
        pVecClosestPoint = v20;
        if ( v20 != nullptr )
          (*(void (__thiscall **)(const Vector *))(LODWORD(v20->x) + 8))(a1: v20);
        (*(void (__thiscall **)(const Vector *, int))(LODWORD(v20->x) + 80))(a1: v20, a2: 10);
        (*(void (__thiscall **)(const Vector *))(LODWORD(v20->x) + 84))(a1: v20);
        (*(void (__thiscall **)(const Vector *))(LODWORD(v20->x) + 124))(a1: v20);
        m_pMaterial = this->m_DetailSpriteMaterial.m_pMaterial;
        if ( ShouldDrawInWireFrameMode()
          || r_DrawDetailProps.m_pParent != nullptr && r_DrawDetailProps.m_pParent->m_Value.m_nValue == 2 )
        {
          m_pMaterial = this->m_DetailWireframeMaterial.m_pMaterial;
        }
        CMeshBuilder::CMeshBuilder(this: &meshBuilder);
        v22 = (IMesh *)(*(int (__thiscall **)(const Vector *, bool, _DWORD, _DWORD, IMaterial *))(LODWORD(v20->x) + 228))(
                         a1: v20,
                         a2: flashlightMode != DPFM_MULTIPASS,
                         a3: 0,
                         a4: 0,
                         a5: m_pMaterial);
        shadowmgr->PushSinglePassFlashlightStateEnabled(this: shadowmgr, a2: flashlightMode == DPFM_SINGLEPASS);
        (*(void (__thiscall **)(const Vector *, IMesh *, _DWORD, int *, int *))(LODWORD(v20->x) + 492))(
          a1: v20,
          a2: v22,
          a3: 0,
          a4: &nMaxVerts,
          a5: &nMaxIndices);
        v23 = nMaxIndices / 6;
        v24 = 4 * (this->m_nSpriteCount - this->m_nFirstSprite);
        nLeaf = nMaxIndices / 6;
        if ( nMaxIndices / 6 > nMaxVerts / 4 )
        {
          nLeaf = nMaxVerts / 4;
          v23 = nMaxVerts / 4;
        }
        if ( v24 > v23 )
          v24 = v23;
        CMeshBuilder::Begin(this: &meshBuilder, pMesh: v22, type: 7, numPrimitives: v24);
        v25 = 0;
        for ( nQuadsDrawn = 0; this->m_nFirstSprite < this->m_nSpriteCount; nQuadsDrawn += nQuadsInModel )
        {
          v26 = this->m_nFirstSprite;
          m_pSortInfo = this->m_pSortInfo;
          m_flDistance = m_pSortInfo[v26].m_flDistance;
          v29 = &m_pSortInfo[v26];
          if ( m_flDistance < flMinDistance )
            break;
          v30 = &this->m_DetailObjects.m_Memory.m_pMemory[(int)(*(_DWORD *)v29 << 8) >> 8];
          nQuadsInModel = s_pQuadCount[(*((unsigned __int8 *)v30 + 36) >> 2) & 3];
          model = v30;
          if ( v25 + nQuadsInModel > v24 )
          {
            if ( meshBuilder.m_bGenerateIndices )
            {
              switch ( meshBuilder.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  m_nVertexCount = 0;
                  break;
                default:
                  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(
                this: &meshBuilder.m_IndexBuilder,
                primitiveType: meshBuilder.m_Type,
                nIndexCount: m_nVertexCount);
            }
            meshBuilder.m_pMesh->UnlockMesh(
              this: meshBuilder.m_pMesh,
              a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
              a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
              a4: &meshBuilder);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_pMesh = nullptr;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v22->Draw_2(this: v22, a2: -1, a3: 0);
            if ( flashlightMode == DPFM_MULTIPASS )
              shadowmgr->FlashlightDrawCallback(this: shadowmgr, a2: DrawMeshCallback, a3: v22);
            v24 = 4 * (this->m_nSpriteCount - this->m_nFirstSprite);
            if ( v24 > nLeaf )
              v24 = nLeaf;
            meshBuilder.m_pMesh = v22;
            meshBuilder.m_bGenerateIndices = true;
            meshBuilder.m_Type = MATERIAL_QUADS;
            v22->SetPrimitiveType(this: v22, a2: MATERIAL_TRIANGLES);
            meshBuilder.m_pMesh->LockMesh(
              this: meshBuilder.m_pMesh,
              a2: 4 * v24,
              a3: 6 * v24,
              a4: &meshBuilder,
              a5: nullptr);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v22->IIndexBuffer;
            meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_bModify = false;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6 * v24;
            meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
            meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
            meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
            CVertexBuilder::AttachBegin(
              this: &meshBuilder.m_VertexBuilder,
              pMesh: v22,
              nMaxVertexCount: 4 * v24,
              desc: &meshBuilder);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
            v30 = model;
            nQuadsDrawn = 0;
          }
          infoa = *((_BYTE *)&this->m_pSortInfo[this->m_nFirstSprite] + 3);
          switch ( (*((unsigned __int8 *)v30 + 36) >> 2) & 3 )
          {
            case 1:
              CDetailModel::DrawTypeSprite(this: v30, &meshBuilder, nAlpha: infoa);
              break;
            case 2:
              CDetailModel::DrawTypeShapeCross(this: v30, &meshBuilder, nAlpha: infoa);
              break;
            case 3:
              CDetailModel::DrawTypeShapeTri(this: v30, &meshBuilder, nAlpha: infoa);
              break;
            default:
              break;
          }
          ++this->m_nFirstSprite;
          v25 = nQuadsInModel + nQuadsDrawn;
        }
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              v32 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              v32 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              v32 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              v32 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              v32 = 0;
              break;
            default:
              v32 = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: v32);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        v22->Draw_2(this: v22, a2: -1, a3: 0);
        if ( flashlightMode == DPFM_MULTIPASS )
          shadowmgr->FlashlightDrawCallback(this: shadowmgr, a2: DrawMeshCallback, a3: v22);
        shadowmgr->PopSinglePassFlashlightStateEnabled(this: shadowmgr);
        v33 = pVecClosestPoint;
        (*(void (__thiscall **)(const Vector *))(LODWORD(pVecClosestPoint->x) + 88))(a1: pVecClosestPoint);
        CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
        (*(void (__thiscall **)(const Vector *))(LODWORD(v33->x) + 12))(a1: v33);
        (*(void (__thiscall **)(const Vector *))(LODWORD(v33->x) + 4))(a1: v33);
      }
    }
  }
LABEL_76:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100CF270
// Name: public: bool CUtlMap<class CDetailModel __near *,struct CDetailModel::LightStyleInfo_t,unsigned short>::Remove(class CDetailModel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Remove(
        CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short> *this,
        CDetailModel **key)
{
  int v3; // edi
  int v4; // eax
  CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t dummyNode; // [esp+8h] [ebp-8h] BYREF

  dummyNode.key = *key;
  v3 = CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  if ( (_WORD)v3 == 0xFFFF )
    return 0;
  CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Tree,
    elem: v3);
  v4 = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Left = v3;
  this->m_Tree.m_Elements.m_pMemory[v4].m_Right = this->m_Tree.m_FirstFree;
  this->m_Tree.m_FirstFree = v3;
  --this->m_Tree.m_NumElements;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF2E0
// Name: public: bool CDetailModel::Init(int,class Vector const __near &,class QAngle const __near &,struct model_t __near *,struct ColorRGBExp32,int,unsigned char,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDetailModel::Init@<al>(
        CDetailModel *this@<ecx>,
        const char *a2@<edi>,
        int index,
        const Vector *org,
        const QAngle *angles,
        struct model_t *pModel,
        ColorRGBExp32 lighting,
        int lightstyle,
        unsigned __int8 lightstylecount,
        char orientation)
{
  unsigned __int16 v11; // cx
  int v12; // edi
  UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short> *v13; // eax
  unsigned __int16 v14; // dx
  int v15; // edx
  UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t *p_m_Data; // edi
  int v18; // eax
  CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t insert; // [esp+4h] [ebp-14h] BYREF
  int v22; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  this->m_Color = lighting;
  if ( lightstylecount != 0 )
  {
    *((_BYTE *)this + 36) |= 0x10u;
    insert.key = this;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &CDetailModel::gm_LightStylesMap.m_Tree,
      &insert,
      parent,
      &leftchild);
    v11 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
            this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&CDetailModel::gm_LightStylesMap,
            a2);
    v22 = v11;
    v12 = v11;
    v13 = &CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v11];
    v14 = parent[0];
    v13->m_Right = -1;
    v13->m_Left = -1;
    v13->m_Parent = v14;
    v13->m_Tag = 0;
    if ( v14 == 0xFFFF )
    {
      CDetailModel::gm_LightStylesMap.m_Tree.m_Root = v11;
    }
    else
    {
      v15 = v14;
      if ( leftchild )
        CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v15].m_Left = v11;
      else
        CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v15].m_Right = v11;
    }
    CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &CDetailModel::gm_LightStylesMap.m_Tree,
      elem: v11);
    m_pMemory = CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory;
    ++CDetailModel::gm_LightStylesMap.m_Tree.m_NumElements;
    p_m_Data = &CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v12].m_Data;
    if ( p_m_Data != nullptr )
    {
      *p_m_Data = insert;
      m_pMemory = CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory;
    }
    if ( lightstyle >= 0x1000000 || lightstylecount >= 0x64u )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_10472868, a2);
      m_pMemory = CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory;
    }
    v18 = (unsigned __int16)v22;
    *(_DWORD *)&m_pMemory[v18].m_Data.elem ^= (lightstyle
                                             ^ *(_DWORD *)&m_pMemory[(unsigned __int16)v22].m_Data.elem)
                                            & 0xFFFFFF;
    *((_BYTE *)&CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v18].m_Data.elem + 3) = lightstylecount;
  }
  *((_BYTE *)this + 36) = orientation & 3 | *((_BYTE *)this + 36) & 0xF0;
  this->m_pModel = pModel;
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (modelinfo->IsTranslucent(this: modelinfo, a2: pModel) << 6)) & 0x40;
  this->m_Origin = *org;
  this->m_Angles = *angles;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF470
// Name: public: bool CDetailModel::InitSprite(int,bool,class Vector const __near &,class QAngle const __near &,unsigned short,struct ColorRGBExp32,int,unsigned char,int,float,unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDetailModel::InitSprite@<al>(
        CDetailModel *this@<ecx>,
        const char *a2@<edi>,
        int index,
        bool bFlipped,
        const Vector *org,
        const QAngle *angles,
        unsigned __int16 nSpriteIndex,
        ColorRGBExp32 lighting,
        int lightstyle,
        unsigned __int8 lightstylecount,
        char orientation,
        float flScale,
        unsigned __int8 type,
        unsigned __int8 shapeAngle,
        unsigned __int8 shapeSize,
        unsigned __int8 swayAmount)
{
  unsigned __int16 v17; // cx
  int v18; // edi
  UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short> *v19; // eax
  unsigned __int16 v20; // dx
  int v21; // edx
  UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t *p_m_Data; // edi
  int v24; // eax
  char v25; // dl
  float16::float16bits v26; // ax
  const char *v28; // [esp+4h] [ebp-20h]
  CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t insert; // [esp+10h] [ebp-14h] BYREF
  int v30; // [esp+18h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+1Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+23h] [ebp-1h] BYREF

  this->m_Color = lighting;
  if ( lightstylecount != 0 )
  {
    *((_BYTE *)this + 36) |= 0x10u;
    insert.key = this;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &CDetailModel::gm_LightStylesMap.m_Tree,
      &insert,
      parent,
      &leftchild);
    v17 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
            this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&CDetailModel::gm_LightStylesMap,
            a2);
    v30 = v17;
    v18 = v17;
    v19 = &CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v17];
    v20 = parent[0];
    v19->m_Right = -1;
    v19->m_Left = -1;
    v19->m_Parent = v20;
    v19->m_Tag = 0;
    if ( v20 == 0xFFFF )
    {
      CDetailModel::gm_LightStylesMap.m_Tree.m_Root = v17;
    }
    else
    {
      v21 = v20;
      if ( leftchild )
        CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v21].m_Left = v17;
      else
        CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v21].m_Right = v17;
    }
    CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &CDetailModel::gm_LightStylesMap.m_Tree,
      elem: v17);
    m_pMemory = CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory;
    ++CDetailModel::gm_LightStylesMap.m_Tree.m_NumElements;
    p_m_Data = &CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v18].m_Data;
    if ( p_m_Data != nullptr )
    {
      *p_m_Data = insert;
      m_pMemory = CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory;
    }
    if ( lightstyle >= 0x1000000 || lightstylecount >= 0x64u )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_10472868, a2: v28);
      m_pMemory = CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory;
    }
    v24 = (unsigned __int16)v30;
    *(_DWORD *)&m_pMemory[v24].m_Data.elem ^= (lightstyle
                                             ^ *(_DWORD *)&m_pMemory[(unsigned __int16)v30].m_Data.elem)
                                            & 0xFFFFFF;
    *((_BYTE *)&CDetailModel::gm_LightStylesMap.m_Tree.m_Elements.m_pMemory[v24].m_Data.elem + 3) = lightstylecount;
  }
  v25 = *((_BYTE *)this + 36);
  this->m_SpriteInfo.m_nSpriteIndex = nSpriteIndex;
  *((_BYTE *)this + 36) = orientation & 3 | v25 & 0xF0 | (4 * (type & 3));
  v26.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: flScale);
  *((_BYTE *)this + 36) |= 0x40u;
  this->m_SpriteInfo.m_flScale.m_storage = v26;
  this->m_pAdvInfo = nullptr;
  if ( type == 3 || type == 2 || swayAmount != 0 )
  {
    this->m_Angles = *angles;
    CDetailModel::InitShapedSprite(this, shapeAngle, shapeSize, swayAmount);
  }
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (32 * bFlipped)) & 0x20;
  this->m_Origin = *org;
  this->m_Angles = *angles;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF650
// Name: private: void CDetailObjectSystem::UnserializeModels(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CDetailObjectSystem::UnserializeModels(CDetailObjectSystem *this, CUtlBuffer *buf)
{
  CDetailObjectSystem *v2; // esi
  void *v3; // eax
  unsigned int v4; // ecx
  int v5; // edi
  void *v6; // eax
  unsigned int v7; // ecx
  void *v8; // eax
  unsigned int v9; // ecx
  void *v10; // eax
  unsigned int v11; // ecx
  int v12; // edi
  CDetailModel *m_pMemory; // eax
  IMemAlloc_vtbl *v14; // edx
  int v15; // eax
  unsigned int Int; // eax
  int m_pFastSpriteData; // edx
  int v18; // edi
  bool v19; // sf
  int v20; // ecx
  char v21; // al
  CClientLeafSubSystemData *v22; // eax
  CClientLeafSubSystemData *v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // esi
  int m_Size; // ecx
  ConVar *m_pParent; // ecx
  int v30; // eax
  IUniformRandomStream *v31; // ecx
  FastSpriteX4_t *v32; // esi
  int v33; // edi
  IUniformRandomStream *v34; // ecx
  IUniformRandomStream *v35; // ecx
  unsigned __int8 *v36; // eax
  int j; // edi
  int k; // edi
  int v39; // eax
  IUniformRandomStream *v40; // ecx
  IUniformRandomStream *v41; // ecx
  CDetailObjectSystem *v42; // esi
  int v43; // eax
  int v44; // eax
  int v45; // esi
  int v46; // edi
  CClientLeafSubSystemData *v47; // eax
  int v48; // ecx
  float v49; // [esp+48h] [ebp-8Ch]
  float v50; // [esp+4Ch] [ebp-88h]
  float v51; // [esp+54h] [ebp-80h]
  float v52; // [esp+58h] [ebp-7Ch]
  DetailObjectLump_t lump; // [esp+60h] [ebp-74h] BYREF
  Vector pos; // [esp+94h] [ebp-40h] BYREF
  Vector org; // [esp+A0h] [ebp-34h] BYREF
  int firstDetailObject; // [esp+ACh] [ebp-28h]
  int count; // [esp+B0h] [ebp-24h] BYREF
  int nCurFastObject; // [esp+B4h] [ebp-20h]
  int detailObjectLeaf; // [esp+B8h] [ebp-1Ch]
  int nNumFastSpritesToAllocate; // [esp+BCh] [ebp-18h] BYREF
  int i; // [esp+C0h] [ebp-14h] BYREF
  int nMaxFastInLeaf; // [esp+C4h] [ebp-10h] BYREF
  int nNumFastObjectsInCurLeaf; // [esp+C8h] [ebp-Ch]
  int detailObjectCount; // [esp+CCh] [ebp-8h]
  CDetailObjectSystem *v65; // [esp+D0h] [ebp-4h]

  v2 = this;
  firstDetailObject = 0;
  detailObjectCount = 0;
  v65 = this;
  detailObjectLeaf = -1;
  CDetailObjectSystem::ScanForCounts(
    this,
    buf,
    pNumOldStyleObjects: &i,
    pNumFastSpritesToAllocate: &nNumFastSpritesToAllocate,
    nMaxNumOldSpritesInLeaf: &count,
    nMaxNumFastSpritesInLeaf: &nMaxFastInLeaf);
  CDetailObjectSystem::FreeSortBuffers(this: v2);
  if ( count != 0 )
  {
    v3 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * count + 43);
    if ( v3 != nullptr )
    {
      v4 = ((unsigned int)v3 + 19) & 0xFFFFFFF0;
      *(_DWORD *)(v4 - 4) = v3;
    }
    else
    {
      v4 = 0;
    }
    v2->m_pSortInfo = (CDetailObjectSystem::SortInfo_t *)v4;
  }
  v5 = nMaxFastInLeaf;
  if ( nMaxFastInLeaf != 0 )
  {
    v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * nMaxFastInLeaf + 43);
    if ( v6 != nullptr )
    {
      v7 = ((unsigned int)v6 + 19) & 0xFFFFFFF0;
      *(_DWORD *)(v7 - 4) = v6;
    }
    else
    {
      v7 = 0;
    }
    v2->m_pFastSortInfo = (CDetailObjectSystem::SortInfo_t *)v7;
    v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: ((v5 / 4 + 1) << 8) + 19);
    if ( v8 != nullptr )
    {
      v9 = ((unsigned int)v8 + 19) & 0xFFFFFFF0;
      *(_DWORD *)(v9 - 4) = v8;
    }
    else
    {
      v9 = 0;
    }
    v2->m_pBuildoutBuffer = (FastSpriteQuadBuildoutBufferX4_t *)v9;
  }
  if ( nNumFastSpritesToAllocate != 0 )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 112 * (nNumFastSpritesToAllocate >> 2) + 19);
    if ( v10 != nullptr )
    {
      v11 = ((unsigned int)v10 + 19) & 0xFFFFFFF0;
      *(_DWORD *)(v11 - 4) = v10;
    }
    else
    {
      v11 = 0;
    }
    v2->m_pFastSpriteData = (FastSpriteX4_t *)v11;
  }
  v12 = i;
  if ( i >= 0x1000000 )
    _Warning(a1: "*** CDetailObjectSystem::UnserializeModels: Error! Too many detail objects!\n");
  if ( v2->m_DetailObjects.m_Memory.m_nAllocationCount < v12 && v2->m_DetailObjects.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = v2->m_DetailObjects.m_Memory.m_pMemory;
    v2->m_DetailObjects.m_Memory.m_nAllocationCount = v12;
    v14 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v15 = ((int (__cdecl *)(CDetailModel *, int))v14->Realloc_2)(a1: m_pMemory, a2: 48 * v12);
    else
      v15 = ((int (__cdecl *)(int))v14->Alloc_2)(a1: 48 * v12);
    v2->m_DetailObjects.m_Memory.m_pMemory = (CDetailModel *)v15;
  }
  v2->m_DetailObjects.m_pElements = v2->m_DetailObjects.m_Memory.m_pMemory;
  Int = CUtlBuffer::GetInt(this: buf);
  m_pFastSpriteData = (int)v2->m_pFastSpriteData;
  v18 = 0;
  v20 = Int - 1;
  v19 = (int)(Int - 1) < 0;
  nCurFastObject = 0;
  nNumFastObjectsInCurLeaf = 0;
  nMaxFastInLeaf = m_pFastSpriteData;
  v21 = 1;
  count = v20;
  if ( !v19 )
  {
    while ( 1 )
    {
      LOBYTE(nNumFastSpritesToAllocate) = v21 == 0;
      CUtlBuffer::Get(this: buf, pMem: (unsigned __int8 *)&lump, size: 52);
      if ( detailObjectLeaf != lump.m_Leaf )
      {
        if ( detailObjectLeaf != -1 )
        {
          if ( nNumFastObjectsInCurLeaf != 0 )
          {
            v22 = (CClientLeafSubSystemData *)MemAlloc_Alloc(nSize: 0x18u);
            if ( v22 != nullptr )
            {
              v22->__vftable = (CClientLeafSubSystemData_vtbl *)&CFastDetailLeafSpriteList::`vftable';
              v22[4].__vftable = nullptr;
              v22[5].__vftable = nullptr;
              v23 = v22;
            }
            else
            {
              v23 = nullptr;
            }
            v24 = nNumFastObjectsInCurLeaf;
            v25 = nMaxFastInLeaf;
            v23[1].__vftable = (CClientLeafSubSystemData_vtbl *)nNumFastObjectsInCurLeaf;
            v26 = (v24 + 3) >> 2;
            v23[2].__vftable = (CClientLeafSubSystemData_vtbl *)v26;
            v23[3].__vftable = (CClientLeafSubSystemData_vtbl *)v25;
            nMaxFastInLeaf = 112 * v26 + v25;
            v27 = detailObjectLeaf;
            g_pClientLeafSystem->SetSubSystemDataInLeaf(this: g_pClientLeafSystem, a2: detailObjectLeaf, a3: 0, a4: v23);
            engine->SetLeafFlag(this: engine, a2: v27, a3: 8);
            v2 = v65;
            v18 += -v18 & 3;
            nCurFastObject = v18;
            nNumFastObjectsInCurLeaf = 0;
          }
          g_pClientLeafSystem->SetDetailObjectsInLeaf(
            this: g_pClientLeafSystem,
            a2: detailObjectLeaf,
            a3: firstDetailObject,
            a4: detailObjectCount);
        }
        m_Size = v2->m_DetailObjects.m_Size;
        detailObjectLeaf = lump.m_Leaf;
        firstDetailObject = m_Size;
        detailObjectCount = 0;
      }
      m_pParent = cl_fastdetailsprites.m_pParent;
      if ( cl_fastdetailsprites.m_pParent == nullptr
        || cl_fastdetailsprites.m_pParent->m_Value.m_nValue == 0
        || lump.m_Type != 1 )
      {
        break;
      }
      if ( lump.m_LightStyleCount != 0 )
        goto LABEL_60;
      m_pParent = *(ConVar **)&lump.m_ShapeSize;
      if ( lump.m_Orientation != 2 || lump.m_ShapeAngle != 0 || lump.m_ShapeSize != 0 || lump.m_SwayAmount != 0 )
        goto LABEL_60;
      v30 = 0;
      i = 0;
      while ( 1 )
      {
        v31 = cl_detail_multiplier.m_pParent != nullptr
            ? (IUniformRandomStream *)cl_detail_multiplier.m_pParent->m_Value.m_nValue
            : nullptr;
        if ( v30 >= (int)v31 )
          break;
        v32 = &v65->m_pFastSpriteData[v18 >> 2];
        v33 = v18 & 3;
        memset((void *)&pos, 0, sizeof(pos));
        if ( v30 != 0 )
        {
          v49 = _RandomFloat(this: v31, a2: -50.0, a3: 50.0);
          v50 = _RandomFloat(this: v34, a2: -50.0, a3: 50.0);
          _RandomFloat(this: v35, a2: -50.0, a3: 50.0);
          pos.x = v49;
          pos.z = 0.0;
          pos.y = v50;
        }
        CDetailObjectSystem::UnserializeFastSprite(
          this: v65,
          pSpritex4: v32,
          nSubField: v33,
          &lump,
          bFlipped: nNumFastSpritesToAllocate,
          posOffset: &pos);
        if ( v33 == 0 )
        {
          v32->m_HalfWidth = _mm_shuffle_ps(
                               (__m128)v32->m_HalfWidth.m128_u32[0],
                               (__m128)v32->m_HalfWidth.m128_u32[0],
                               0);
          v32->m_Height = _mm_shuffle_ps((__m128)v32->m_Height.m128_u32[0], (__m128)v32->m_Height.m128_u32[0], 0);
          v36 = &v32->m_RGBColor[1][1];
          for ( j = 3; j != 0; --j )
          {
            *(v36 - 1) = v32->m_RGBColor[0][0];
            *v36 = v32->m_RGBColor[0][1];
            v36[1] = v32->m_RGBColor[0][2];
            v36[2] = v32->m_RGBColor[0][3];
            v36 += 4;
          }
          v32->m_Pos.x = _mm_shuffle_ps((__m128)v32->m_Pos.x.m128_u32[0], (__m128)v32->m_Pos.x.m128_u32[0], 0);
          v32->m_Pos.y = _mm_shuffle_ps((__m128)v32->m_Pos.y.m128_u32[0], (__m128)v32->m_Pos.y.m128_u32[0], 0);
          v32->m_Pos.z = _mm_shuffle_ps((__m128)v32->m_Pos.z.m128_u32[0], (__m128)v32->m_Pos.z.m128_u32[0], 0);
        }
        v2 = v65;
        ++nCurFastObject;
        ++nNumFastObjectsInCurLeaf;
        v30 = ++i;
        v18 = nCurFastObject;
      }
LABEL_72:
      if ( --count < 0 )
      {
        v45 = detailObjectLeaf;
        if ( detailObjectLeaf != -1 )
        {
          v46 = nNumFastObjectsInCurLeaf;
          if ( nNumFastObjectsInCurLeaf != 0 )
          {
            v47 = (CClientLeafSubSystemData *)MemAlloc_Alloc(nSize: 0x18u);
            if ( v47 != nullptr )
            {
              v47->__vftable = (CClientLeafSubSystemData_vtbl *)&CFastDetailLeafSpriteList::`vftable';
              v47[4].__vftable = nullptr;
              v47[5].__vftable = nullptr;
            }
            else
            {
              v47 = nullptr;
            }
            v48 = nMaxFastInLeaf;
            v47[1].__vftable = (CClientLeafSubSystemData_vtbl *)v46;
            v47[2].__vftable = (CClientLeafSubSystemData_vtbl *)((v46 + 3) >> 2);
            v47[3].__vftable = (CClientLeafSubSystemData_vtbl *)v48;
            g_pClientLeafSystem->SetSubSystemDataInLeaf(this: g_pClientLeafSystem, a2: v45, a3: 0, a4: v47);
            engine->SetLeafFlag(this: engine, a2: v45, a3: 8);
          }
          g_pClientLeafSystem->SetDetailObjectsInLeaf(
            this: g_pClientLeafSystem,
            a2: v45,
            a3: firstDetailObject,
            a4: detailObjectCount);
        }
        goto LABEL_80;
      }
      v21 = nNumFastSpritesToAllocate;
    }
    if ( lump.m_Type != 0 )
    {
LABEL_60:
      if ( (unsigned __int8)(lump.m_Type - 1) > 2u )
        goto LABEL_72;
      for ( k = 0; ; ++k )
      {
        v39 = cl_detail_multiplier.m_pParent != nullptr ? cl_detail_multiplier.m_pParent->m_Value.m_nValue : 0;
        if ( k >= v39 )
          break;
        org = lump.m_Origin;
        if ( k != 0 )
        {
          v51 = _RandomFloat(this: (IUniformRandomStream *)m_pParent, a2: -50.0, a3: 50.0);
          v52 = _RandomFloat(this: v40, a2: -50.0, a3: 50.0);
          _RandomFloat(this: v41, a2: -50.0, a3: 50.0);
          org.z = lump.m_Origin.z;
          org.x = v51 + org.x;
          org.y = org.y + v52;
        }
        v42 = v65;
        v43 = CUtlVector<CDetailModel,CUtlMemory<CDetailModel,int>>::InsertBefore(
                this: &v65->m_DetailObjects,
                elem: v65->m_DetailObjects.m_Size);
        CDetailModel::InitSprite(
          this: &v42->m_DetailObjects.m_Memory.m_pMemory[v43],
          index: v43,
          bFlipped: nNumFastSpritesToAllocate,
          &org,
          angles: &lump.m_Angles,
          nSpriteIndex: lump.m_DetailModel,
          lighting: lump.m_Lighting,
          lightstyle: lump.m_LightStyles,
          lightstylecount: lump.m_LightStyleCount,
          orientation: lump.m_Orientation,
          flScale: lump.m_flScale,
          type: lump.m_Type,
          shapeAngle: lump.m_ShapeAngle,
          shapeSize: lump.m_ShapeSize,
          swayAmount: lump.m_SwayAmount);
        ++detailObjectCount;
      }
      v18 = nCurFastObject;
    }
    else
    {
      v44 = CUtlVector<CDetailModel,CUtlMemory<CDetailModel,int>>::InsertBefore(
              this: &v2->m_DetailObjects,
              elem: v2->m_DetailObjects.m_Size);
      CDetailModel::Init(
        this: &v2->m_DetailObjects.m_Memory.m_pMemory[v44],
        index: v44,
        org: &lump.m_Origin,
        angles: &lump.m_Angles,
        pModel: v65->m_DetailObjectDict.m_Memory.m_pMemory[lump.m_DetailModel].m_pModel,
        lighting: lump.m_Lighting,
        lightstyle: lump.m_LightStyles,
        lightstylecount: lump.m_LightStyleCount,
        orientation: lump.m_Orientation);
      ++detailObjectCount;
    }
    v2 = v65;
    goto LABEL_72;
  }
LABEL_80:
  engine->RecalculateBSPLeafFlags(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x100CFD20
// Name: public: virtual void CDetailObjectSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDetailObjectSystem::LevelInitPreEntity(CDetailObjectSystem *this)
{
  FastSpriteX4_t *m_pFastSpriteData; // eax
  unsigned __int8 *m_pMemory; // ebx
  const char *v4; // edi
  C_World *ClientWorldEntity; // eax
  char *m_iszDetailSpriteMaterial; // eax
  int v7; // edi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  IMaterial *m_pMaterial; // edi
  int v10; // ebx
  float v11; // xmm0_4
  int v12; // edx
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  IMemAlloc_vtbl *v16; // edx
  unsigned __int8 *v17; // eax
  bool v18; // al
  unsigned __int8 *v19; // edi
  CUtlBuffer buf; // [esp+Ch] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> fileMemory; // [esp+3Ch] [ebp-Ch]

  m_pFastSpriteData = this->m_pFastSpriteData;
  m_pMemory = nullptr;
  if ( m_pFastSpriteData != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pFastSpriteData & 0xFFFFFFFC) - 4));
    this->m_pFastSpriteData = nullptr;
  }
  CDetailObjectSystem::FreeSortBuffers(this);
  v4 = "detail/detailsprites";
  ClientWorldEntity = GetClientWorldEntity();
  if ( ClientWorldEntity != nullptr )
  {
    m_iszDetailSpriteMaterial = ClientWorldEntity->m_iszDetailSpriteMaterial;
    if ( m_iszDetailSpriteMaterial != nullptr && *m_iszDetailSpriteMaterial != 0 )
      v4 = m_iszDetailSpriteMaterial;
  }
  CMaterialReference::Init(
    this: &this->m_DetailSpriteMaterial,
    pMaterialName: v4,
    pTextureGroupName: "Other textures",
    bComplain: true);
  CMaterialReference::Init(
    this: &this->m_DetailWireframeMaterial,
    pMaterialName: "debug/debugspritewireframe",
    pTextureGroupName: "Other textures",
    bComplain: true);
  if ( engine->GameLumpVersion(this: engine, a2: 1685090928) >= 4 )
  {
    v7 = engine->GameLumpSize(this: engine, a2: 1685090928);
    fileMemory.m_pMemory = nullptr;
    fileMemory.m_nAllocationCount = 0;
    if ( v7 > 0 )
    {
      Alloc_2 = _g_pMemAlloc->Alloc_2;
      fileMemory.m_nAllocationCount = v7;
      fileMemory.m_pMemory = (unsigned __int8 *)Alloc_2(this: _g_pMemAlloc, a2: v7);
      m_pMemory = fileMemory.m_pMemory;
    }
    if ( engine->LoadGameLump(this: engine, a2: 1685090928, a3: m_pMemory, a4: v7) )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: m_pMemory, nSize: v7, nFlags: 8u);
      CDetailObjectSystem::UnserializeModelDict(this, &buf);
      if ( engine->GameLumpVersion(this: engine, a2: 1685090928) == 4 )
      {
        CDetailObjectSystem::UnserializeDetailSprites(this, &buf);
        CDetailObjectSystem::UnserializeModels(this, &buf);
      }
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    if ( this->m_DetailObjects.m_Size != 0 || this->m_DetailSpriteDict.m_Size != 0 )
    {
      PrecacheMaterial(pMaterialName: "detail/detailsprites");
      m_pMaterial = this->m_DetailSpriteMaterial.m_pMaterial;
      v10 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v11 = (float)(m_pMaterial->GetMappingWidth(this: m_pMaterial) / v10);
      if ( v11 > 1.0 )
      {
        v12 = 0;
        if ( this->m_DetailSpriteDict.m_Size > 0 )
        {
          v13 = 0;
          do
          {
            this->m_DetailSpriteDict.m_Memory.m_pMemory[v13].m_TexUL.y = v11
                                                                       * this->m_DetailSpriteDict.m_Memory.m_pMemory[v13].m_TexUL.y;
            this->m_DetailSpriteDict.m_Memory.m_pMemory[v13].m_TexLR.y = v11
                                                                       * this->m_DetailSpriteDict.m_Memory.m_pMemory[v13].m_TexLR.y;
            this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory[v13].m_TexUL.y = this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory[v13].m_TexUL.y
                                                                              * v11;
            ++v12;
            this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory[v13].m_TexLR.y = this->m_DetailSpriteDictFlipped.m_Memory.m_pMemory[v13].m_TexLR.y
                                                                              * v11;
            ++v13;
          }
          while ( v12 < this->m_DetailSpriteDict.m_Size );
        }
      }
    }
    v14 = g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE
        ? 1685089384
        : 1685089396;
    v15 = engine->GameLumpSize(this: engine, a2: v14);
    if ( fileMemory.m_nAllocationCount < v15 )
    {
      v16 = _g_pMemAlloc->__vftable;
      if ( fileMemory.m_pMemory != nullptr )
        v17 = (unsigned __int8 *)((int (__stdcall *)(unsigned __int8 *, int))v16->Realloc_2)(
                                   a1: fileMemory.m_pMemory,
                                   a2: v15);
      else
        v17 = (unsigned __int8 *)((int (__stdcall *)(int))v16->Alloc_2)(a1: v15);
      fileMemory.m_pMemory = v17;
    }
    v18 = engine->LoadGameLump(this: engine, a2: v14, a3: fileMemory.m_pMemory, a4: v15);
    v19 = fileMemory.m_pMemory;
    if ( v18 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: fileMemory.m_pMemory, nSize: v15, nFlags: 8u);
      CDetailObjectSystem::UnserializeModelLighting(this, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    if ( v19 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
  }
  else
  {
    _Warning(a1: "Map uses old detail prop file format.. ignoring detail props\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x104153E0
// Name: _dynamic_initializer_for__CDetailModel::gm_LightStylesMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDetailModel::gm_LightStylesMap__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDetailModel::gm_LightStylesMap__);
}

//------------------------------------------------------------------------------
// Address: 0x104314F0
// Name: _dynamic_atexit_destructor_for__CDetailModel::gm_LightStylesMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDetailModel::gm_LightStylesMap__()
{
  CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CDetailModel *,CDetailModel::LightStyleInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &CDetailModel::gm_LightStylesMap.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x104153F0
// Name: _dynamic_initializer_for__cl_detail_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_detail_multiplier__()
{
  ConVar::ConVar(
    this: &cl_detail_multiplier,
    pName: "cl_detail_multiplier",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "extra details to create");
  return atexit(func: dynamic_atexit_destructor_for__cl_detail_multiplier__);
}

//------------------------------------------------------------------------------
// Address: 0x10415420
// Name: _dynamic_initializer_for__cl_fastdetailsprites__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_fastdetailsprites__()
{
  ConVar::ConVar(
    this: &cl_fastdetailsprites,
    pName: "cl_fastdetailsprites",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "whether to use new detail sprite system");
  return atexit(func: dynamic_atexit_destructor_for__cl_fastdetailsprites__);
}

//------------------------------------------------------------------------------
// Address: 0x10415450
// Name: _dynamic_initializer_for__g_CDummyFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDummyFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "Dummy",
           a3: CCDummyMaterialProxyFactory);
}
